import { ControlType, DataType, InsnType, Instruction, KeywordType, MEM_SCRATCH, MEM_STAT, MEM_WORLD } from "./instruction.ts";

// ---------------------------------------------------------------------------
// 字句解析
// ---------------------------------------------------------------------------

type TokenType = "IDENT" | "NUMBER" | "STRING" | "PUNCT" | "ALIAS" | "EOF";
type Token = { type: TokenType; text: string; value?: number; pos: number };

// 長いものから先に試す(">>=" は無いので3文字は不要)
const PUNCTS = ["==", "!=", "<=", ">=", "<<", ">>", "||", "&&", "{", "}", "(", ")", "[", "]", ",", ";", ":", ".", "=", "+", "-", "*", "/", "%", "<", ">", "!", "~", "|", "&", "^"];

const ALIAS_RE = /^(?:reg|op):0x[0-9A-Fa-f]+$/;

const lex = (input: string): Token[] => {
  const tokens: Token[] = [];
  let i = 0;
  while (i < input.length) {
    const ch = input[i];
    if (/\s/.test(ch)) {
      i++;
      continue;
    }
    if (input.startsWith("//", i)) {
      const end = input.indexOf("\n", i + 2);
      i = end < 0 ? input.length : end + 1;
      continue;
    }
    if (input.startsWith("/*", i)) {
      const end = input.indexOf("*/", i + 2);
      if (end < 0) throw new Error(`Unterminated comment at ${i}`);
      const body = input.slice(i + 2, end).trim();
      // コマンドエイリアス注釈 /*op:0x8*/ /*reg:0x1*/ は復元に必要な情報なので字句として拾う。それ以外のブロックコメントは読み飛ばす
      if (ALIAS_RE.test(body)) tokens.push({ type: "ALIAS", text: body, pos: i });
      i = end + 2;
      continue;
    }
    if (ch === '"') {
      let j = i + 1;
      const bytes: number[] = [];
      while (j < input.length && input[j] !== '"') {
        if (input[j] === "\\" && input[j + 1] === "x") {
          bytes.push(parseInt(input.slice(j + 2, j + 4), 16));
          j += 4;
        } else {
          bytes.push(input.charCodeAt(j));
          j += 1;
        }
      }
      if (j >= input.length) throw new Error(`Unterminated string at ${i}`);
      tokens.push({ type: "STRING", text: String.fromCharCode(...bytes), pos: i });
      (tokens[tokens.length - 1] as Token & { bytes?: number[] }).bytes = bytes;
      i = j + 1;
      continue;
    }
    if (/[0-9]/.test(ch)) {
      const m = /^0[xX][0-9A-Fa-f]+|^[0-9]+/.exec(input.slice(i))!;
      tokens.push({ type: "NUMBER", text: m[0], value: Number(m[0]), pos: i });
      i += m[0].length;
      continue;
    }
    if (/[A-Za-z_]/.test(ch)) {
      let j = i;
      while (j < input.length && /[A-Za-z0-9_]/.test(input[j])) j++;
      tokens.push({ type: "IDENT", text: input.slice(i, j), pos: i });
      i = j;
      continue;
    }
    const punct = PUNCTS.find((p) => input.startsWith(p, i));
    if (!punct) throw new Error(`Unexpected character '${ch}' at position ${i}`);
    tokens.push({ type: "PUNCT", text: punct, pos: i });
    i += punct.length;
  }
  tokens.push({ type: "EOF", text: "", pos: input.length });
  return tokens;
};

// ---------------------------------------------------------------------------
// 演算子表(instruction.ts の OperatorStrings / OperatorPrecedence と対応)
// ---------------------------------------------------------------------------

const UNARY_OPS: Record<string, number> = { "-": 1, "!": 2, "~": 3 };
// 優先度の低い(結合が弱い)ものから並べる。同じ配列内は同一優先度。
const BINARY_LEVELS: Record<string, number>[] = [
  { "=": 22 },
  { "||": 20 },
  { "&&": 21 },
  { "|": 17 },
  { "^": 19 },
  { "&": 18 },
  { "==": 11, "!=": 12 },
  { "<": 13, "<=": 14, ">": 15, ">=": 16 },
  { "<<": 9, ">>": 10 },
  { "+": 4, "-": 5 },
  { "*": 6, "/": 7, "%": 8 },
];

const TYPE_BY_NAME: Record<string, DataType> = {
  bool: DataType.Bool,
  u8: DataType.UInt8,
  u8_0x03: DataType.UInt8_0x03,
  s16: DataType.Int16,
  u16: DataType.UInt16,
  u24: DataType.UInt24,
  s32: DataType.Int32,
  s32_0x0A: DataType.Int32_0x0A,
  s32_0x0D: DataType.Int32_0x0D,
};
const REGION_BY_NAME: Record<string, number> = { stat: MEM_STAT, world: MEM_WORLD, scratch: MEM_SCRATCH };

// ---------------------------------------------------------------------------
// 構文解析
// ---------------------------------------------------------------------------

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

  // 直後に続くエイリアス注釈を命令に貼り付ける
  private attachAlias(instr: Instruction): Instruction {
    while (this.peek().type === "ALIAS") {
      const t = this.next();
      const m = /^(reg|op):0x([0-9A-Fa-f]+)$/.exec(t.text);
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
    while (this.peek().type !== "EOF") scripts.push(this.parseBlock());
    return scripts;
  }

  private parseBlock(): Instruction {
    this.expect("{");
    const instr = new Instruction(InsnType.Block);
    while (!this.at("}")) instr.children.push(this.parseStatement());
    this.expect("}");
    return instr;
  }

  private parseStatement(): Instruction {
    if (this.at("if")) return this.parseIf();
    if (this.at("switch")) return this.parseSwitch();
    const instr = this.at("return") ? this.parseReturn() : this.parseSimpleStatement();
    this.expect(";");
    return instr;
  }

  private parseIf(): Instruction {
    this.expect("if");
    this.expect("(");
    const instr = new Instruction(InsnType.Control, ControlType.If);
    instr.children.push(this.parseBareExpression());
    this.expect(")");
    instr.children.push(this.parseBlock());
    while (this.at("else")) {
      this.expect("else");
      if (this.at("if")) {
        this.expect("if");
        this.expect("(");
        const kw = new Instruction(InsnType.Keyword, KeywordType.ElseIf);
        kw.children.push(this.parseBareExpression());
        this.expect(")");
        kw.children.push(this.parseBlock());
        instr.children.push(kw);
      } else {
        const kw = new Instruction(InsnType.Keyword, KeywordType.Else);
        kw.children.push(this.parseBlock());
        instr.children.push(kw);
        break;
      }
    }
    return instr;
  }

  private parseSwitch(): Instruction {
    this.expect("switch");
    this.expect("(");
    const instr = new Instruction(InsnType.Control, ControlType.Switch);
    instr.children.push(this.parseBareExpression());
    this.expect(")");
    this.expect("{");
    while (!this.at("}")) {
      if (this.accept("case")) {
        const kw = new Instruction(InsnType.Keyword, KeywordType.Case);
        kw.children.push(this.parseExpressionNode());
        this.expect(":");
        kw.children.push(this.parseBlock());
        instr.children.push(kw);
      } else {
        this.expect("default");
        this.expect(":");
        const kw = new Instruction(InsnType.Keyword, KeywordType.Default);
        kw.children.push(this.parseBlock());
        instr.children.push(kw);
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

  private tryParseCallLike(): Instruction | null {
    const t = this.peek();
    if (t.type !== "IDENT" || this.peek(1).text !== "(") return null;
    if (t.text === "ScriptCall") return this.parseScriptCall();
    let tag: number;
    if (t.text === "NativeCall_9906") tag = ControlType.NativeCall_9906;
    else if (t.text === "NativeCall_B745") tag = ControlType.NativeCall_B745;
    else if (t.text === "LoadMap") tag = ControlType.LoadMap;
    else {
      const m = /^Ctrl_([0-9A-Fa-f]{1,4})$/.exec(t.text);
      if (!m) return null;
      tag = parseInt(m[1], 16);
    }
    this.next();
    const instr = new Instruction(InsnType.Control, tag);
    this.parseArgs(instr);
    return instr;
  }

  // ScriptCall(0xNNNN, ...) は 0x70(呼び先が定数)、ScriptCall(式, ...) は 0x121F
  private parseScriptCall(): Instruction {
    this.expect("ScriptCall");
    this.expect("(");
    const head = this.peek();
    const isDirect = head.type === "NUMBER" && /^0[xX]/.test(head.text);
    if (isDirect) {
      const instr = new Instruction(InsnType.Call, this.expectNumber());
      while (this.accept(",")) instr.children.push(this.parseArg());
      this.expect(")");
      return instr;
    }
    const instr = new Instruction(InsnType.Control, ControlType.CallIndirect);
    if (!this.at(")")) {
      instr.children.push(this.parseArg());
      while (this.accept(",")) instr.children.push(this.parseArg());
    }
    this.expect(")");
    return instr;
  }

  private parseArgs(instr: Instruction): void {
    this.expect("(");
    if (!this.at(")")) {
      instr.children.push(this.parseArg());
      while (this.accept(",")) instr.children.push(this.parseArg());
    }
    this.expect(")");
  }

  // 引数は通常の値か、キーワード引数 .x = 値 / .x = (値, 値, ...)
  private parseArg(): Instruction {
    if (!this.at(".")) return this.parseExpressionNode();
    this.expect(".");
    const name = this.next();
    if (name.type !== "IDENT" || name.text.length !== 1) {
      throw new Error(`Expected a one-letter keyword but got '${name.text}' at position ${name.pos}`);
    }
    const kw = new Instruction(InsnType.Keyword, name.text.charCodeAt(0));
    if (!this.accept("=")) return kw; // 値を持たないキーワード
    if (this.accept("[")) {
      kw.children.push(this.parseExpressionNode());
      while (this.accept(",")) kw.children.push(this.parseExpressionNode());
      this.expect("]");
    } else {
      kw.children.push(this.parseExpressionNode());
    }
    return kw;
  }

  // -------------------------------------------------------------------------
  // 式: 中置で読み、RPN(バイトコードの並び)に変換する
  // -------------------------------------------------------------------------

  // 文や if/switch の条件のように、構文上そこが式であることが確定している位置。
  // オペランド1つでも必ず Expression コンテナになる。
  private parseBareExpression(): Instruction {
    // "[...]" は例外的に裸のオペランドが置かれていることを示す印
    if (this.accept("[")) {
      const operand = this.parseExpressionNode();
      this.expect("]");
      return operand;
    }
    const rpn: Instruction[] = [];
    const single = this.parseBinary(0, rpn);
    if (single) rpn.push(single);
    const expr = new Instruction(InsnType.Expression);
    expr.children = rpn;
    return expr;
  }

  // 引数の位置。"(" で始まっていれば式コンテナ、そうでなければ裸のオペランド。
  private parseExpressionNode(): Instruction {
    if (this.at("(") && !this.startsCast() && !this.startsIndexedMemory()) {
      this.expect("(");
      const expr = this.parseBareExpression();
      this.expect(")");
      return expr;
    }
    const rpn: Instruction[] = [];
    const single = this.parseBinary(0, rpn);
    if (single) return single;
    const expr = new Instruction(InsnType.Expression);
    expr.children = rpn;
    return expr;
  }

  private startsCast(): boolean {
    return this.peek(1).type === "IDENT" && TYPE_BY_NAME[this.peek(1).text] !== undefined && this.peek(2).text === ")";
  }

  private startsIndexedMemory(): boolean {
    return this.peek(1).text === "(" && TYPE_BY_NAME[this.peek(2).text] !== undefined && this.peek(3).text === "*";
  }

  // level 以上の優先度の二項演算を読む。演算子が1つも無ければその単項式を返す。
  private parseBinary(level: number, rpn: Instruction[]): Instruction | null {
    if (level >= BINARY_LEVELS.length) return this.parseUnary(rpn);
    let single = this.parseBinary(level + 1, rpn);
    for (;;) {
      const t = this.peek();
      const op = t.type === "PUNCT" ? BINARY_LEVELS[level][t.text] : undefined;
      if (op === undefined) return single;
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

  private parsePrimary(rpn: Instruction[]): Instruction | null {
    const t = this.peek();

    if (t.type === "NUMBER" || (t.text === "-" && this.peek(1).type === "NUMBER")) {
      const sign = this.accept("-") ? -1 : 1;
      return this.attachAlias(new Instruction(InsnType.Constant, DataType.Int32, sign * this.expectNumber()));
    }
    if (t.type === "STRING") {
      this.next();
      const instr = new Instruction(InsnType.String);
      instr.bytes = new Uint8Array((t as Token & { bytes: number[] }).bytes);
      return instr;
    }
    if (this.at("{")) return this.parseBlock();
    if (this.at("*")) return this.parseMemory(false);
    if (this.at("BIT")) return this.parseBit();

    if (t.type === "IDENT") {
      if (t.text === "result") {
        this.next();
        return new Instruction(InsnType.Parameter, 0);
      }
      let m = /^p([0-9]+)$/.exec(t.text);
      if (m) {
        this.next();
        return new Instruction(InsnType.Parameter, Number(m[1]) + 1);
      }
      m = /^v([0-9]+)$/.exec(t.text);
      if (m) {
        this.next();
        return new Instruction(InsnType.Variable, Number(m[1]));
      }
      if (t.text === "StringRef") {
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
        const type = TYPE_BY_NAME[this.next().text];
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
    const base = REGION_BY_NAME[name.text];
    if (base === undefined) throw new Error(`Unknown memory region '${name.text}' at position ${name.pos}`);
    this.expect("+");
    return { base, addr: base + this.expectNumber() };
  }

  // indexed=false: *((s16 *)(world + 0x2))
  // indexed=true : ((s16 *)(world + 0x2))[要素サイズ, 添字]
  private parseMemory(indexed: boolean): Instruction {
    if (!indexed) this.expect("*");
    this.expect("(");
    this.expect("(");
    const typeName = this.next();
    const dataType = TYPE_BY_NAME[typeName.text];
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
    instr.bitIndex = 0;
    if (indexed) {
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
