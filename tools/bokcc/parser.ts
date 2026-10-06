import { ClauseType, ControlType, DATA_TYPE_BY_NAME, DataType, DEBUG_PRINT_NAME, ENTITY_CREATE_NAME, IMPLICIT_ARG_TYPES, InsnType, Instruction, LOAD_MAP_NAME, MEM_REGION_BY_NAME, OPERATORS, SCRIPT_CALL_NAME, SET_ZONE_CALLBACK_NAME, STRING_REF_NAME, SUBROUTINE_CALL_NAME } from "./instruction.ts";
import { encodeChar } from "./eucjp.ts";

// コンパイル専用。.bokc のテキストから Instruction を読む(コンパイル前半。 コンパイル後半の書き出しは compiler.ts)。
//
// 字句解析と構文解析をまとめて持つ。中置で書かれた式は、バイトコードの並びである RPN に直してから Instruction の列にする。

type TokenType = "IDENT" | "NUMBER" | "STRING" | "PUNCT" | "ALIAS" | "EOF";
// STRING だけは EUC-JP に直したバイト列を bytes として後付けで持つ(text は人が読む用で、コンパイルに使うのはバイト列の方)。
type Token = { type: TokenType; text: string; value?: number; pos: number };

// 長いものから先に試す(">>=" は無いので3文字は不要)
const PUNCTS = ["==", "!=", "<=", ">=", "<<", ">>", "||", "&&", "{", "}", "(", ")", "[", "]", ",", ";", ":", ".", "=", "+", "-", "*", "/", "%", "<", ">", "!", "~", "|", "&", "^"];

// コマンドエイリアス注釈 /*op:0x8*/ /*reg:0x1*/ の綴り。字句解析と attachAlias で共用する。
const ALIAS_RE = /^(reg|op):0x([0-9A-Fa-f]+)$/;

// テキストをトークン列にする
const lex = (input: string): Token[] => {
  const tokens: Token[] = [];
  let i = 0;
  while (i < input.length) {
    const ch = input[i];
    // 空白 (インデントのタブや改行)
    if (/\s/.test(ch)) {
      i++;
      continue;
    }

    // インラインコメント
    if (input.startsWith("//", i)) {
      const end = input.indexOf("\n", i + 2);
      i = end < 0 ? input.length : end + 1;
      continue;
    }

    // ブロックコメント
    // コマンドエイリアス注釈 (/*op:0x8*/ と /*reg:0x1*/ ) だけは 読み飛ばさずに ALIAS として残す(bokcc の動作確認で使用するだけで実際のコンパイルには影響しない)
    if (input.startsWith("/*", i)) {
      const end = input.indexOf("*/", i + 2);
      if (end < 0) throw new Error(`Unterminated comment at ${i}`);
      const body = input.slice(i + 2, end).trim();
      if (ALIAS_RE.test(body)) tokens.push({ type: "ALIAS", text: body, pos: i });
      i = end + 2;
      continue;
    }

    // 文字列リテラル  "ABC" / "\x81\x40" のように生の文字と \xNN を混ぜて書ける
    if (ch === '"') {
      let j = i + 1;
      const bytes: number[] = [];
      while (j < input.length && input[j] !== '"') {
        if (input[j] === "\\" && input[j + 1] === "x") {
          bytes.push(parseInt(input.slice(j + 2, j + 4), 16));
          j += 4;
        } else {
          // 生の文字は EUC-JP にして入れる(ソースは UTF-8 で読まれている)
          const c = String.fromCodePoint(input.codePointAt(j)!);
          const enc = encodeChar(c);
          if (!enc) throw new Error(`EUC-JP で表せない文字 ${JSON.stringify(c)} at ${j}`);
          for (const b of enc) bytes.push(b);
          j += c.length;
        }
      }
      if (j >= input.length) throw new Error(`Unterminated string at ${i}`);
      tokens.push({ type: "STRING", text: String.fromCharCode(...bytes), pos: i });
      (tokens[tokens.length - 1] as Token & { bytes?: number[] }).bytes = bytes;
      i = j + 1;
      continue;
    }

    // 数値リテラル  123 / 0x14F9
    if (/[0-9]/.test(ch)) {
      const m = /^0[xX][0-9A-Fa-f]+|^[0-9]+/.exec(input.slice(i))!;
      tokens.push({ type: "NUMBER", text: m[0], value: Number(m[0]), pos: i });
      i += m[0].length;
      continue;
    }

    // 識別子  if, return, result, p0, v3, BIT, StringRef, EntityCreate
    // キーワードも区別せず IDENT にして、構文解析側が text で見分ける
    if (/[A-Za-z_]/.test(ch)) {
      let j = i;
      while (j < input.length && /[A-Za-z0-9_]/.test(input[j])) j++;
      tokens.push({ type: "IDENT", text: input.slice(i, j), pos: i });
      i = j;
      continue;
    }

    // 記号  + - * ( ) [ ] == << など
    const punct = PUNCTS.find((p) => input.startsWith(p, i));
    if (!punct) throw new Error(`Unexpected character '${ch}' at position ${i}`);

    tokens.push({ type: "PUNCT", text: punct, pos: i });
    i += punct.length;
  }

  tokens.push({ type: "EOF", text: "", pos: input.length });
  return tokens;
};

// 演算子表は instruction.ts の OPERATORS から導出する。綴りの無い演算子(value 23)は .bokc に書けないので除く。
const UNARY_OPS: Record<string, number> = Object.fromEntries(
  OPERATORS.filter((op) => op.arity === "unary" && op.text !== "").map((op) => [op.text, op.value]),
);

// 優先度の低い(結合が弱い)ものから並べる。同じ要素内は同一優先度。
const BINARY_OPS = OPERATORS.filter((op) => op.arity === "binary");

const BINARY_LEVELS: Record<string, number>[] = [...new Set(BINARY_OPS.map((op) => op.precedence))]
  .sort((a, b) => b - a)
  .map((prec) => Object.fromEntries(BINARY_OPS.filter((op) => op.precedence === prec).map((op) => [op.text, op.value])));

class Parser {
  private pos = 0;
  constructor(private tokens: Token[]) {}

  private peek(k = 0): Token {
    return this.tokens[Math.min(this.pos + k, this.tokens.length - 1)];
  }

  private next(): Token {
    return this.tokens[this.pos++];
  }

  private at(text: string): boolean {
    const t = this.peek();
    return (t.type === "PUNCT" || t.type === "IDENT") && t.text === text;
  }

  private accept(text: string): boolean {
    if (!this.at(text)) return false;
    this.pos++;
    return true;
  }

  private expect(text: string): Token {
    if (!this.at(text)) {
      const t = this.peek();
      throw new Error(`Expected '${text}' but got '${t.text}' at position ${t.pos}`);
    }

    return this.next();
  }

  private expectNumber(): number {
    const t = this.next();
    if (t.type !== "NUMBER") throw new Error(`Expected a number but got '${t.text}' at position ${t.pos}`);
    return t.value!;
  }

  // bokccのデバッグ用, 直後に続くエイリアス注釈を命令に貼り付ける(1つの命令に op と reg の両方が付くことがあるのでループ)
  private attachAlias(instr: Instruction): Instruction {
    while (this.peek().type === "ALIAS") {
      const t = this.next();
      const m = ALIAS_RE.exec(t.text);
      if (!m) throw new Error(`Unrecognized annotation '${t.text}' at position ${t.pos}`);
      if (m[1] === "reg") {
        instr.hasForcedRegion = true;
        instr.forcedRegion = parseInt(m[2], 16);
      } else {
        instr.hasForcedOpcode = true;
        instr.forcedOpcode = parseInt(m[2], 16);
      }
    }
    return instr;
  }

  // 1つの入力に複数のスクリプトが並んでいてよい(スクリプトの外にはコメントしか置けない)
  parseProgram(): Instruction[] {
    const scripts: Instruction[] = [];
    while (this.peek().type !== "EOF") scripts.push(this.parseScript());
    return scripts;
  }

  // Script_00F1() { ... } のように名前が付いていてもよい。名前はバイト列に現れないので読み捨てる
  private parseScript(): Instruction {
    if (this.peek().type === "IDENT" && this.peek(1).text === "(" && this.peek(2).text === ")" && this.peek(3).text === "{") {
      this.next();
      this.expect("(");
      this.expect(")");
    }

    return this.parseBlock();
  }

  private parseBlock(): Instruction {
    this.expect("{");
    const instr = new Instruction(InsnType.Block);
    while (!this.at("}")) instr.children.push(this.parseStatement());
    this.expect("}");
    return instr;
  }

  // if と switch だけは "}" で終わるので ";" を取らない(instruction.ts の needsSemicolon と対)。
  private parseStatement(): Instruction {
    if (this.at("if")) return this.parseIf();
    if (this.at("switch")) return this.parseSwitch();
    const instr = this.at("return") ? this.parseReturn() : this.parseSimpleStatement();
    this.expect(";");
    return instr;
  }

  // else if / else は入れ子の if ではなく、if 命令の子に並ぶラベル(ClauseType)になる。バイトコードがその形。
  // e.g. if (p0 == 1) { ... } else if (p0 == 2) { ... } else { ... }
  private parseIf(): Instruction {
    // if (cond)
    this.expect("if");
    this.expect("(");
    const instr = new Instruction(InsnType.Control, ControlType.If);
    instr.children.push(this.parseBareExpression());
    this.expect(")");

    // if 本体
    instr.children.push(this.parseBlock());

    while (this.at("else")) {
      this.expect("else");

      // else if (cond) { ... }
      if (this.at("if")) {
        this.expect("if");
        this.expect("(");
        const label = new Instruction(InsnType.Label, ClauseType.ElseIf);
        label.children.push(this.parseBareExpression());
        this.expect(")");
        label.children.push(this.parseBlock());
        instr.children.push(label);
      } else {
        // else { ... } が来たら連鎖はそこで終わり
        const label = new Instruction(InsnType.Label, ClauseType.Else);
        label.children.push(this.parseBlock());
        instr.children.push(label);
        break;
      }
    }

    return instr;
  }

  // case / default も if の else と同じく、switch 命令の子に並ぶラベル(ClauseType)になる。
  // e.g. switch (p0) { case 1: { ... } case 2: { ... } default: { ... } }
  private parseSwitch(): Instruction {
    // switch (cond)
    this.expect("switch");
    this.expect("(");
    const instr = new Instruction(InsnType.Control, ControlType.Switch);
    instr.children.push(this.parseBareExpression());
    this.expect(")");

    this.expect("{");
    while (!this.at("}")) {
      // case 値: { ... }
      if (this.accept("case")) {
        const label = new Instruction(InsnType.Label, ClauseType.Case);
        label.children.push(this.parseExpressionNode());
        this.expect(":");
        label.children.push(this.parseBlock());
        instr.children.push(label);
      } else {
        // default: { ... }
        this.expect("default");
        this.expect(":");
        const label = new Instruction(InsnType.Label, ClauseType.Default);
        label.children.push(this.parseBlock());
        instr.children.push(label);
      }
    }

    this.expect("}");
    return instr;
  }

  private parseReturn(): Instruction {
    this.expect("return");
    const instr = new Instruction(InsnType.Control, ControlType.Return);
    if (!this.at(";")) instr.children.push(this.parseExpressionNode());
    return instr;
  }

  // 文の位置に来た呼び出し系はそのまま Call/Control になり、それ以外は式(0x30)で包む
  private parseSimpleStatement(): Instruction {
    const call = this.tryParseCallLike();
    if (call) return call;
    return this.parseBareExpression();
  }

  // 関数呼び出しの形 `XXX(...)` で XXX が特定の名前であれば対応する制御命令に変換し、それ以外は式として扱う(ここではnullを返すだけで式として読み直すのは呼び出し側の責任)
  private tryParseCallLike(): Instruction | null {
    const t = this.peek();
    if (t.type !== "IDENT" || this.peek(1).text !== "(") return null;

    if (t.text === SCRIPT_CALL_NAME) return this.parseScriptCall(); // ScriptCall(...) は別で処理

    // 残りは制御命令, e.g. EntityCreate(0x1B77, (u16)7031), SubroutineCall(0x0C63), Ctrl_XXXX(...)
    let tag: number;
    // 制御命令 のうち、用途がわかっているものは専用の名前をつけているので、名前から opcode を決める
    if (t.text === ENTITY_CREATE_NAME) tag = ControlType.EntityCreate;
    else if (t.text === SUBROUTINE_CALL_NAME) tag = ControlType.SubroutineCall;
    else if (t.text === LOAD_MAP_NAME) tag = ControlType.LoadMap;
    else if (t.text === DEBUG_PRINT_NAME) tag = ControlType.DebugPrint;
    else if (t.text === SET_ZONE_CALLBACK_NAME) tag = ControlType.SetZoneCallback;
    else {
      // Ctrl_XXXX は opcode を直に書いた形。それ以外の識別子は呼び出しではない
      const m = /^Ctrl_([0-9A-Fa-f]{1,4})$/.exec(t.text);
      if (!m) return null;
      tag = parseInt(m[1], 16);
    }

    this.next();
    this.expect("(");
    const instr = new Instruction(InsnType.Control, tag);
    this.parseArgList(instr);

    // 本来はキャストなしの数値は s32 として扱うが、IMPLICIT_ARG_TYPES の命令の第1引数はその型で扱う (ゲーム内の使用箇所全てで型が1つだったので、(u16)0xXXXX を毎回書くのは冗長だと思った)
    const implicitType = IMPLICIT_ARG_TYPES[tag];
    if (implicitType !== undefined) {
      const arg = instr.children[0];
      if (arg.insnType === InsnType.Constant && arg.dataType === DataType.Int32) arg.dataType = implicitType;
    }

    return instr;
  }

  // ScriptCall(0xNNNN, ...)
  // 先頭が16進リテラルかどうかで 直接呼び出し(0x70) か 間接呼び出し(0x121F) かを判定する
  private parseScriptCall(): Instruction {
    this.expect(SCRIPT_CALL_NAME);
    this.expect("(");

    // 2つの見分けは先頭が16進リテラルかどうか。呼び先IDは printer が必ず16進で出し、式の中の定数は必ず10進で出るので衝突しない。
    const head = this.peek();
    const isDirect = head.type === "NUMBER" && /^0[xX]/.test(head.text);

    if (isDirect) {
      // 直接呼び出し(0x70), e.g. ScriptCall(0x00F8, 3, (u24)85, 0);
      const instr = new Instruction(InsnType.Call, this.expectNumber());
      while (this.accept(",")) instr.children.push(this.parseArg());
      this.expect(")");
      return instr;
    } else {
      // 間接呼び出し(0x121F), e.g. ScriptCall(p1, 0);
      const instr = new Instruction(InsnType.Control, ControlType.CallIndirect);
      this.parseArgList(instr);
      return instr;
    }
  }

  // "(" を読んだ後の引数リストを ")" まで読む
  private parseArgList(instr: Instruction): void {
    if (!this.at(")")) {
      instr.children.push(this.parseArg());
      while (this.accept(",")) instr.children.push(this.parseArg());
    }

    this.expect(")");
  }

  // 引数, 名前付き引数
  private parseArg(): Instruction {
    if (!this.at(".")) return this.parseExpressionNode(); // 通常の値の場合

    // 名前付き引数 '.x'
    this.expect(".");
    const name = this.next();
    // ラベルはバイトコード上で1バイトの文字なので、名前は必ず1文字。
    if (name.type !== "IDENT" || name.text.length !== 1) {
      throw new Error(`Expected a one-letter name but got '${name.text}' at position ${name.pos}`);
    }

    const label = new Instruction(InsnType.Label, name.text.charCodeAt(0));
    if (!this.accept("=")) return label; // 値を持たない名前付き引数 e.g. Ctrl_E43C(.r);

    // '.x=val'
    if (this.accept("[")) {
      label.children.push(this.parseExpressionNode());
      while (this.accept(",")) label.children.push(this.parseExpressionNode());
      this.expect("]");
    } else {
      label.children.push(this.parseExpressionNode());
    }

    return label;
  }

  // if (p0 == 1) の "p0 == 1", 文の "v0 = 1" のように、必ず式が来るところ
  // オペランド1つでも Expression コンテナになり、裸のオペランドのときだけ if ([p0]) のように "[...]" で囲まれて現れる(instruction.ts の conditionString と対)
  private parseBareExpression(): Instruction {
    // "[...]" は例外的に裸のオペランドが置かれていることを示す印
    if (this.accept("[")) {
      const operand = this.parseExpressionNode();
      this.expect("]");
      return operand;
    }

    // オペランド1つだけでもコンテナに入れる
    const rpn: Instruction[] = [];
    const single = this.parseBinary(0, rpn);
    if (single) rpn.push(single);

    const expr = new Instruction(InsnType.Expression);
    expr.children = rpn;
    return expr;
  }

  // Ctrl_22FF(0x10, (p0 + 1)) の "0x10" と "(p0 + 1)", case 1: の "1", return p0; の "p0", BIT(world + 0xC, 1, 2, p0) の "2" と "p0"
  // "(" で囲まれていれば Expression コンテナ、囲みが無ければ裸のオペランドになる
  private parseExpressionNode(): Instruction {
    if (this.at("(") && !this.startsCast() && !this.startsIndexedMemory()) {
      // 式全体が "(" ... ")" で囲まれている場合  e.g. (p0 + 1) / (p0 == 1) / (p0)
      this.expect("(");
      const expr = this.parseBareExpression();
      this.expect(")");
      return expr;
    }

    // 囲みの無い値  e.g. 0x10 / p0 / (u16)123 / p0 + 1
    const rpn: Instruction[] = [];
    const single = this.parseBinary(0, rpn);
    if (single) return single;

    const expr = new Instruction(InsnType.Expression);
    expr.children = rpn;
    return expr;
  }

  // この "(" が型キャスト "(u16)123" の始まりか
  private startsCast(): boolean {
    return this.peek(1).type === "IDENT" && DATA_TYPE_BY_NAME[this.peek(1).text] !== undefined && this.peek(2).text === ")";
  }

  // この "(" が添字付きメモリ "((s16 *)(world + 0x2))[..]" の始まりか
  private startsIndexedMemory(): boolean {
    return this.peek(1).text === "(" && DATA_TYPE_BY_NAME[this.peek(2).text] !== undefined && this.peek(3).text === "*";
  }

  // 優先度の段を下りながら二項演算を読む(level が大きいほど強く結合する)。
  // 演算子を1つでも読んだら RPN を rpn に積んで null を返し、オペランド1つだけで終わったらそれを返す。呼び出し側はこの戻り値を見て Expression コンテナで包むかどうかを決める。
  // e.g. p0 + 1 * 2 なら rpn に p0, 1, 2, *, + の順で積む
  private parseBinary(level: number, rpn: Instruction[]): Instruction | null {
    if (level >= BINARY_LEVELS.length) return this.parseUnary(rpn);

    let single = this.parseBinary(level + 1, rpn);
    for (;;) {
      const t = this.peek();
      const op = t.type === "PUNCT" ? BINARY_LEVELS[level][t.text] : undefined;
      if (op === undefined) return single;

      // 溜めていた左辺をここで RPN に出す
      if (single) {
        rpn.push(single);
        single = null;
      }

      this.next();
      const rhs = this.parseBinary(level + 1, rpn);
      if (rhs) rpn.push(rhs);
      rpn.push(new Instruction(InsnType.Operator, op));
    }
  }

  private parseUnary(rpn: Instruction[]): Instruction | null {
    // 単項演算子は必ず "op(...)" の形で出力されるので(負の定数リテラルと区別するため)、"(" が続かないものは演算子ではない。
    const t = this.peek();
    if (t.type === "PUNCT" && UNARY_OPS[t.text] !== undefined && this.peek(1).text === "(" && !this.startsMemoryDeref()) {
      this.next();
      // 単項演算も評価スタックから2つ取るため、捨てられる側の 0 を補う
      rpn.push(new Instruction(InsnType.Constant, DataType.Int32, 0));
      const operand = this.parseUnary(rpn);
      if (operand) rpn.push(operand);
      rpn.push(new Instruction(InsnType.Operator, UNARY_OPS[t.text]));
      return null;
    }

    return this.parsePrimary(rpn);
  }

  // "*((s16 *)(world + 0x2))" のような単項の "*" はメモリ参照であって乗算ではない
  private startsMemoryDeref(): boolean {
    return this.peek().text === "*" && this.peek(1).text === "(" && this.peek(2).text === "(";
  }

  // オペランド1つを読む。括弧式の中身が演算子を含んでいた場合は rpn に積まれるので null が返る。
  private parsePrimary(rpn: Instruction[]): Instruction | null {
    const t = this.peek();

    // 数値リテラル  123 / -1
    if (t.type === "NUMBER" || (t.text === "-" && this.peek(1).type === "NUMBER")) {
      const sign = this.accept("-") ? -1 : 1;
      return this.attachAlias(new Instruction(InsnType.Constant, DataType.Int32, sign * this.expectNumber()));
    }

    // 文字列リテラル  "ABC"
    if (t.type === "STRING") {
      this.next();
      const instr = new Instruction(InsnType.String);
      // 0x00 終端はリテラルに書かない約束なのでここで付ける(instruction.ts の stringLiteral と対)。終端を明示した古い表記を黙って二重終端にしないよう、\x00 を含むリテラルは弾く
      const raw = (t as Token & { bytes: number[] }).bytes;
      if (raw.includes(0x00)) throw new Error(`文字列リテラルに \\x00 は書かない(終端は自動で付く) at ${t.pos}`);
      instr.bytes = new Uint8Array([...raw, 0x00]);
      return instr;
    }

    // 値として使うブロック { ... } / メモリ参照 *((s16 *)(world + 0x2)) / BIT(world + 0xC, 1)
    if (this.at("{")) return this.parseBlock();
    if (this.at("*")) return this.parseMemory(false);
    if (this.at("BIT")) return this.parseBit();

    // 識別子  result / p0 / v3 / StringRef(STR_XXXX) / 呼び出し
    if (t.type === "IDENT") {
      // result (スクリプトの戻り値)
      if (t.text === "result") {
        this.next();
        return new Instruction(InsnType.Parameter, 0);
      }

      // pN (スクリプトの引数), e.g. p2
      let m = /^p([0-9]+)$/.exec(t.text);
      if (m) {
        this.next();
        return new Instruction(InsnType.Parameter, Number(m[1]) + 1);
      }

      // vN (スクリプトのローカル変数), e.g. v3
      m = /^v([0-9]+)$/.exec(t.text);
      if (m) {
        this.next();
        return new Instruction(InsnType.Variable, Number(m[1]));
      }

      // StringRef(STR_XXXX)
      if (t.text === STRING_REF_NAME) {
        this.next();
        this.expect("(");
        const instr = new Instruction(InsnType.StringRef, this.expectNumber());
        this.expect(")");
        return instr;
      }

      const call = this.tryParseCallLike();
      if (call) return call;

      throw new Error(`Unexpected identifier '${t.text}' at position ${t.pos}`);
    }

    if (this.at("(")) {
      // 型キャスト "(u16)123" か、添字付きメモリ "((s16 *)(world + 0x2))[..]" か、括弧式
      if (this.startsCast()) {
        this.next();
        const type = DATA_TYPE_BY_NAME[this.next().text];
        this.expect(")");
        const sign = this.accept("-") ? -1 : 1;
        return this.attachAlias(new Instruction(InsnType.Constant, type, sign * this.expectNumber()));
      }
      if (this.startsIndexedMemory()) return this.parseMemory(true);
      this.expect("(");
      const inner = this.parseBinary(0, rpn);
      this.expect(")");
      return inner;
    }
    throw new Error(`Unexpected token '${t.text}' at position ${t.pos}`);
  }

  // "region + 0xNN" の形のアドレス
  private parseBase(): { base: number; addr: number } {
    const name = this.next();
    const base = MEM_REGION_BY_NAME[name.text];
    if (base === undefined) throw new Error(`Unknown memory region '${name.text}' at position ${name.pos}`);
    this.expect("+");
    return { base, addr: base + this.expectNumber() };
  }

  // indexed=false: *((s16 *)(world + 0x2))
  // indexed=true : ((s16 *)(world + 0x2))[要素サイズ, 添字]
  private parseMemory(indexed: boolean): Instruction {
    if (!indexed) this.expect("*"); // *((s16 *)(world + 0x2))

    this.expect("(");
    this.expect("(");
    const typeName = this.next();
    const dataType = DATA_TYPE_BY_NAME[typeName.text];
    if (dataType === undefined) throw new Error(`Unknown type '${typeName.text}' at position ${typeName.pos}`);
    this.expect("*");
    this.expect(")");
    this.expect("(");
    const { base, addr } = this.parseBase();
    this.expect(")");
    this.expect(")");

    const instr = new Instruction(indexed ? InsnType.MemoryIndexed : InsnType.Memory);
    instr.dataType = dataType;
    instr.value = addr;
    instr.memRegionBase = base;
    instr.bitIndex = 0; // Bool 以外は領域バイトの下位ニブルが常に 0
    if (indexed) { // [要素サイズ, 添字]
      this.expect("[");
      instr.children.push(this.parseExpressionNode());
      this.expect(",");
      instr.children.push(this.parseExpressionNode());
      this.expect("]");
    }

    return this.attachAlias(instr);
  }

  // BIT(world + 0xC, 1) / BIT(world + 0xC, 1, 要素サイズ, 添字)
  private parseBit(): Instruction {
    this.expect("BIT");
    this.expect("(");
    const { base, addr } = this.parseBase();
    this.expect(",");
    const bit = this.expectNumber();

    const instr = new Instruction(InsnType.Memory);
    instr.dataType = DataType.Bool;
    instr.value = addr;
    instr.memRegionBase = base;
    instr.bitIndex = bit;
    if (this.accept(",")) {
      instr.insnType = InsnType.MemoryIndexed;
      instr.children.push(this.parseExpressionNode());
      this.expect(",");
      instr.children.push(this.parseExpressionNode());
    }
    this.expect(")");
    return this.attachAlias(instr);
  }
}

// 入力中の全スクリプトを順に返す。
export const parseAll = (input: string): Instruction[] => new Parser(lex(input)).parseProgram();

// スクリプトがちょうど1つだけ入っていることを前提にそれを返す。
export const parse = (input: string): Instruction => {
  const scripts = parseAll(input);
  if (scripts.length !== 1) throw new Error(`Expected exactly one script but got ${scripts.length}`);
  return scripts[0];
};
