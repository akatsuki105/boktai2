import { readChar } from "./eucjp.ts";

// コンパイル・デコンパイル共用。命令の中間表現(Instruction)と、その綴りの定義。
//
// バイト列側の綴り(opcode・型タグ・メモリ領域のセレクタ・演算子の番号) と、テキスト側の綴り(.bokc 上の表記と演算子の優先度)の定義元はすべてこのファイルで、reader/parser/compiler はここから引く。
// Instruction から .bokc のテキストへの描画(toString)もここが持つ。

export enum InsnType {
  Invalid,
  Constant,
  Memory,
  MemoryIndexed,
  Expression,
  Parameter,
  Label,
  Control,
  Call,
  Block,
  Variable,
  Operator,
  End,
  String,
  StringRef,
}

export enum ControlType {
  If = 0x0D86,
  Switch = 0x4A6F,
  CallIndirect = 0x121F,
  Return = 0xCD3A,
  LoadMap = 0xC8BB,
  EntityCreate = 0x9906,
  SubroutineCall = 0xB745,
  DebugPrint = 0xB96E,
  SetZoneCallback = 0xD4CB,
}

// .bokc 上の綴り。printer (controlToString) と parser (tryParseCallLike) が同じものを使う
export const ENTITY_CREATE_NAME = "EntityCreate";
export const SUBROUTINE_CALL_NAME = "SubroutineCall";
export const LOAD_MAP_NAME = "LoadMap";
export const DEBUG_PRINT_NAME = "DebugPrint";
export const SET_ZONE_CALLBACK_NAME = "SetZoneCallback";
export const SCRIPT_CALL_NAME = "ScriptCall";
export const STRING_REF_NAME = "StringRef";

// デコンパイル時に識別子へ名前を付けるための表, namespace ごとに別のヘッダから作る, 名前が無いIDは従来通り16進で出力する。
export type PrintContext = {
  stringNames?: ReadonlyMap<number, string>; // STRING_REF_NAME の 文字列ID
};

// ラベル(0x50)のうち if/switch の節として現れるもの。これ以外のラベルは名前付き引数で、1文字の意味は呼び出し先のエンジン関数ごとに異なる。
export enum ClauseType {
  Case = 0x63,
  Default = 0x64,
  Else = 0x65,
  ElseIf = 0x69,
}

// 命令の opcode。上位ニブルが命令の種類で、下位ニブルの意味は種類ごとに違う
// (コンテナなら本体の長さ、Constant なら型タグ、Parameter/Variable/Operator なら番号)。
// Operator は番号が5ビット、コンパクト形式の定数は値が6ビットなので、上位ニブルを複数使う。
export enum Opcode {
  Constant = 0x00,
  Memory = 0x10,
  MemoryIndexed = 0x20,
  Expression = 0x30,
  Parameter = 0x40,
  Label = 0x50,
  Control = 0x60,
  Call = 0x70,
  Block = 0x80,
  Variable = 0x90,
  Operator = 0xA0, // 0xA0-0xBF
  ConstantCompact = 0xC0, // 0xC0-0xFF
}

// Constant ニブル(0x00)の下位ニブルのうち、型タグではないもの。
export enum ConstantOp {
  End = 0x0,
  String = 0x7,
  StringRef = 0xE,
}

// Parameter の番号は下位ニブルに入るが、0xF のときだけ続く1バイトとの和になる。
export const PARAM_EXTENDED = 0xF;

// 式の終端は番号 0 の Operator。
export const OPERATOR_END = 0;

// 型は命令の下位ニブルそのもの(=型タグ)なので、enum の値をそのタグにしてある。
// メモリ参照と定数リテラルで同じニブル空間を使い、各文脈が表現できる範囲で実装されている
// (例: メモリ参照は s16 と u16 を区別しない、定数リテラルは u24 を2バイトで持つ)。
// 0x3 / 0xA / 0xD はVMのswitchには存在するがスクリプト中に一度も現れない。
// 本当に別名なのか別の型なのか判定材料が無いので、区別だけ付けて保留する。
export enum DataType {
  Void = 0x0,
  Int16 = 0x1,
  UInt8 = 0x2,
  UInt8_0x03 = 0x3, // 未使用
  Bool = 0x4,
  UInt16 = 0x6,
  UInt24 = 0x8,
  Int32 = 0x9,
  Int32_0x0A = 0xA, // 未使用
  Int32_0x0D = 0xD, // 未使用
}

// .bokc 上のキャスト表記。void は型タグとしては現れず、型を持たない命令を表すためだけに使う。
export const DATA_TYPE_NAMES: Readonly<Record<DataType, string>> = {
  [DataType.Void]: "void",
  [DataType.Int16]: "s16",
  [DataType.UInt8]: "u8",
  [DataType.UInt8_0x03]: "u8_0x03",
  [DataType.Bool]: "bool",
  [DataType.UInt16]: "u16",
  [DataType.UInt24]: "u24",
  [DataType.Int32]: "s32",
  [DataType.Int32_0x0A]: "s32_0x0A",
  [DataType.Int32_0x0D]: "s32_0x0D",
};

// キャスト表記から型を引く(DATA_TYPE_NAMES の逆引き)。void は .bokc に書けないので持たない。
export const DATA_TYPE_BY_NAME: Readonly<Record<string, DataType>> = Object.fromEntries(
  Object.entries(DATA_TYPE_NAMES).filter(([tag]) => Number(tag) !== DataType.Void).map(([tag, name]) => [name, Number(tag)]),
);

// 型タグから型を引く。タグは enum の値そのものなので、型を持たないニブルかどうかの判定だけを行う。
// 第1引数のキャストを書かない制御命令と、書かなかったときの型。その位置の値は型が1つに決まっているのでキャストが省ける。printer と parser が同じ表を見る
export const IMPLICIT_ARG_TYPES: Readonly<Record<number, DataType>> = {
  [ControlType.SubroutineCall]: DataType.UInt16,
  [ControlType.EntityCreate]: DataType.UInt16,
  [ControlType.LoadMap]: DataType.UInt24,
};

export const dataTypeOfTag = (tag: number): DataType | undefined => (tag !== DataType.Void && tag in DATA_TYPE_NAMES) ? tag as DataType : undefined;

export const toHex = (n: number, minDigits = 0): string => n.toString(16).toUpperCase().padStart(minDigits, "0");

// String(opcode 7)のバイト列を文字列リテラルに描画する。EUC-JP として読めて元のバイト列に戻せる文字だけをそのまま出し、それ以外は \xNN のまま残す(コンパイルし直したときにバイト列が変わらないことを優先する)。
// 引用符とバックスラッシュも、字句解析を単純に保つためにエスケープせず \xNN で出す。
const stringLiteral = (bytes: Uint8Array): string => {
  // opcode 7 の文字列は必ず 0x00 終端(ROM内の130件すべてがそうで、途中に 0x00 を含むものは無い)。
  // 終端は自明なのでリテラルには出さず、コンパイル時に parser が付け直す。
  if (bytes.length === 0 || bytes[bytes.length - 1] !== 0x00) {
    throw new Error("String(opcode 7) が 0x00 終端ではない: " + [...bytes].map((b) => toHex(b, 2)).join(" "));
  }
  const body = bytes.subarray(0, bytes.length - 1);

  let s = "";
  for (let i = 0; i < body.length;) {
    const b = body[i];
    if (b >= 0x20 && b <= 0x7E && b !== 0x22 && b !== 0x5C) {
      s += String.fromCharCode(b);
      i += 1;
      continue;
    }
    const ch = readChar(body, i);
    if (ch) {
      s += ch.ch;
      i += ch.len;
      continue;
    }
    s += "\\x" + toHex(b, 2);
    i += 1;
  }
  return s;
};

// Memory の3つのアドレス領域ベース(bokasm 側の world/scratch/stat と同じ命名)。
export const MEM_STAT = 0x0203D800;
export const MEM_WORLD = 0x0203E800;
export const MEM_SCRATCH = 0x0203F000;

// 領域の定義。selector は領域バイトの上位ニブルで、stat と scratch はセレクタが1つしかないためエイリアスなし。
// world は複数のバイト値が同じ領域を指し得るため 0x00 をデフォルトとしている(実データは全て 0x00)。
const MEM_REGIONS = [
  { base: MEM_STAT, name: "stat", selector: 0x80 },
  { base: MEM_WORLD, name: "world", selector: 0x00 },
  { base: MEM_SCRATCH, name: "scratch", selector: 0x10 },
];

const MEM_REGION_NAMES = new Map<number, string>(MEM_REGIONS.map((r) => [r.base, r.name]));
const REGION_BY_SELECTOR = new Map<number, number>(MEM_REGIONS.map((r) => [r.selector, r.base]));
const SELECTOR_BY_REGION = new Map<number, number>(MEM_REGIONS.map((r) => [r.base, r.selector]));
const WORLD_SELECTOR = SELECTOR_BY_REGION.get(MEM_WORLD)!;

// 表記から領域ベースを引く(.bokc の "world + 0x2" の world の部分)。
export const MEM_REGION_BY_NAME: Readonly<Record<string, number>> = Object.fromEntries(MEM_REGIONS.map((r) => [r.name, r.base]));

// 領域バイトの上位ニブルから領域ベースを引く。表に無いセレクタは world 扱い。
export const memRegionOf = (selector: number): number => REGION_BY_SELECTOR.get(selector) ?? MEM_WORLD;

// 領域ベースに対するデフォルトのセレクタ。
export const memSelectorOf = (base: number): number => SELECTOR_BY_REGION.get(base) ?? WORLD_SELECTOR;

// 式の演算子。value は opcode の下位5ビットで、どの演算子も評価スタックから2つ取って1つ返す
// (そのため単項演算子は捨てられる側のダミーのオペランドを伴う)。
// precedence は数値が大きいほど結合が弱く、印字時の括弧付けとパーサの結合順の両方の基になる。
// value 0 は式の終端、value 23 は綴りも用途も不明でスクリプト中に現れない。
export const OPERATORS: readonly { value: number; text: string; precedence: number; arity: "end" | "unary" | "binary" }[] = [
  { value: 0, text: ";", precedence: 0, arity: "end" },
  { value: 1, text: "-", precedence: 2, arity: "unary" },
  { value: 2, text: "!", precedence: 2, arity: "unary" },
  { value: 3, text: "~", precedence: 2, arity: "unary" },
  { value: 4, text: "+", precedence: 4, arity: "binary" },
  { value: 5, text: "-", precedence: 4, arity: "binary" },
  { value: 6, text: "*", precedence: 3, arity: "binary" },
  { value: 7, text: "/", precedence: 3, arity: "binary" },
  { value: 8, text: "%", precedence: 3, arity: "binary" },
  { value: 9, text: "<<", precedence: 5, arity: "binary" },
  { value: 10, text: ">>", precedence: 5, arity: "binary" },
  { value: 11, text: "==", precedence: 7, arity: "binary" },
  { value: 12, text: "!=", precedence: 7, arity: "binary" },
  { value: 13, text: "<", precedence: 6, arity: "binary" },
  { value: 14, text: "<=", precedence: 6, arity: "binary" },
  { value: 15, text: ">", precedence: 6, arity: "binary" },
  { value: 16, text: ">=", precedence: 6, arity: "binary" },
  { value: 17, text: "|", precedence: 10, arity: "binary" },
  { value: 18, text: "&", precedence: 8, arity: "binary" },
  { value: 19, text: "^", precedence: 9, arity: "binary" },
  { value: 20, text: "||", precedence: 12, arity: "binary" },
  { value: 21, text: "&&", precedence: 11, arity: "binary" },
  { value: 22, text: "=", precedence: 14, arity: "binary" },
  { value: 23, text: "", precedence: 16, arity: "unary" },
];

const OPERATOR_TEXT: string[] = [];
const OPERATOR_PRECEDENCE: number[] = [];
for (const op of OPERATORS) {
  OPERATOR_TEXT[op.value] = op.text;
  OPERATOR_PRECEDENCE[op.value] = op.precedence;
}
const UNARY_OPERATORS = new Set<number>(OPERATORS.filter((op) => op.arity === "unary").map((op) => op.value));

export class Instruction {
  static readonly Invalid: Instruction = new Instruction();

  address: number;
  insnType: InsnType;
  dataType: DataType;
  children: Instruction[];
  value: number;
  indent: number;

  // コマンドエイリアス保持用: Constant/Memory を読んだ際の生の opcode ニブルが「デフォルト」形式(defaultConstantOpcode / typeTag)と異なっていた場合にのみセットされる(instruction_reader.ts 側で設定)。
  // 今の .bokc には1件も現れないが、往復の動作保証のために念のため残してある。
  hasForcedOpcode?: boolean;
  forcedOpcode?: number;
  // Memory/MemoryIndexed のアドレス領域セレクタバイト(& 0xF0 適用前)がデフォルトと異なっていた場合にのみセットされる。
  hasForcedRegion?: boolean;
  forcedRegion?: number;
  // String(opcode 7)の生バイト列。charmap による可読化は可逆性を検証してから行う。
  bytes?: Uint8Array;
  // Bool のビット番号(0-7)。領域バイトの下位ニブルに入っている。
  bitIndex?: number;
  // Memory/MemoryIndexed の value(絶対アドレス)の計算に使った領域ベースアドレス
  // (MEM_STAT/MEM_WORLD/MEM_SCRATCH のいずれか)。world/scratch/stat 表記での出力に使う(instruction_reader.ts の readMemory がセットする)。
  memRegionBase?: number;

  constructor(insnType?: InsnType);
  constructor(insnType: InsnType, value: number);
  constructor(insnType: InsnType, dataType: DataType, value: number);
  constructor(insnType: InsnType = InsnType.Invalid, dataTypeOrValue?: DataType | number, value?: number) {
    let dataType: DataType;
    let val: number;
    if (value !== undefined) {
      dataType = dataTypeOrValue as DataType;
      val = value;
    } else if (dataTypeOrValue !== undefined) {
      dataType = DataType.Void;
      val = dataTypeOrValue;
    } else {
      dataType = DataType.Void;
      val = 0;
    }

    this.address = 0;
    this.insnType = insnType;
    this.dataType = dataType;
    this.value = val;
    this.children = [];
    this.indent = 0;
  }

  isExpressionEnd(): boolean {
    return this.insnType === InsnType.Operator && this.value === OPERATOR_END;
  }

  // 型タグ(opcode の下位ニブル)。タグは DataType の値そのもの。
  typeTag(): number {
    if (dataTypeOfTag(this.dataType) === undefined) throw new Error("unexpected data type " + this.dataType);
    return this.dataType;
  }

  // Constant を書き出すときの「デフォルト」形式の opcode。Int32 は値が -1〜62 に収まるならコンパクト形式(0xC0-0xFF)、収まらないなら型タグそのもの。
  // デコンパイル時はこれと違う opcode で書かれていたらコマンドエイリアスとして記録し、コンパイル時はエイリアスが無ければこれを書くので、読み書きが同じ規則を見ることになる。
  defaultConstantOpcode(): number {
    if (this.dataType === DataType.Int32 && this.value >= -1 && this.value <= 62) {
      return Opcode.ConstantCompact | ((this.value + 1) & 0x3F);
    }
    return this.typeTag();
  }

  // hasForcedOpcode/hasForcedRegion が立っている場合に、それを示す注釈を返す(コマンドエイリアスの情報を出力から消さないため)。
  private aliasSuffix(): string {
    let s = "";
    if (this.hasForcedRegion) s += " /*reg:0x" + toHex(this.forcedRegion!) + "*/";
    if (this.hasForcedOpcode) s += " /*op:0x" + toHex(this.forcedOpcode!) + "*/";
    return s;
  }

  // Memory/MemoryIndexed のベースアドレス部分を、既知の領域(world/scratch/stat)
  // であれば "region + 0xOFFSET" の形で、そうでなければ従来通り生アドレスで返す。
  // Bool(BIT)の場合は addrValue・領域ベースの両方をビットアドレスとして扱うため divisor=8 を渡す(この場合 addrValue は 8 で割る前の値を渡すこと)。
  private formatBase(addrValue: number, opts: { divisor?: number; fallbackPad?: number } = {}): string {
    const divisor = opts.divisor ?? 1;
    const byteAddr = Math.trunc(addrValue / divisor);
    if (this.memRegionBase !== undefined) {
      const regionBase = Math.trunc(this.memRegionBase / divisor);
      const name = MEM_REGION_NAMES.get(this.memRegionBase) ?? ("0x" + toHex(this.memRegionBase));
      const offset = byteAddr - regionBase;
      return name + " + 0x" + toHex(offset);
    }
    return "0x" + toHex(byteAddr, opts.fallbackPad ?? 0);
  }

  toString(ctx?: PrintContext): string {
    let s: string;

    switch (this.insnType) {
      case InsnType.Invalid: {
        s = "?";
        break;
      }
      case InsnType.End: {
        s = "}";
        break;
      }
      case InsnType.Constant: {
        // 定数の型(=ニブル)はテキストから復元できないとコンパイルできないので、最頻の s32(コンパクト形式)以外はキャストで型を明示する。
        s = this.typeCast() + this.value.toString() + this.aliasSuffix();
        break;
      }
      case InsnType.Memory: {
        if (this.dataType === DataType.Bool) {
          s = "BIT(" + this.formatBase(this.value) + ", " + this.bitIndex + ")"; // BIT(world + 0xC, 1)
        } else {
          s = "*((" + DATA_TYPE_NAMES[this.dataType] + " *)(" + this.formatBase(this.value) + "))"; // *((s16 *)(world + 0x2))
        }
        s += this.aliasSuffix();
        break;
      }
      case InsnType.MemoryIndexed: {
        const index = this.children[0].toString(ctx) + ", " + this.children[1].toString(ctx);
        if (this.dataType === DataType.Bool) {
          s = "BIT(" + this.formatBase(this.value) + ", " + this.bitIndex + ", " + index + ")"; // BIT(world + 0xC, 1, 要素サイズ, 添字)
        } else {
          s = "((" + DATA_TYPE_NAMES[this.dataType] + " *)(" + this.formatBase(this.value) + "))[" + index + "]"; // ((s16 *)(world + 0x2))[要素サイズ, 添字]
        }
        s += this.aliasSuffix();
        break;
      }
      case InsnType.Expression: {
        s = "(" + this.expressionToString(ctx) + ")";
        break;
      }
      case InsnType.Parameter: {
        if (this.value === 0) {
          s = "result"; // index 0 は gVM.result(直前の文の値)。スクリプト呼び出しや式でも上書きされる。
        } else {
          s = "p" + (this.value - 1); // pN
        }
        break;
      }
      case InsnType.String: {
        s = '"' + stringLiteral(this.bytes!) + '"';
        break;
      }
      case InsnType.StringRef: {
        const name = ctx?.stringNames?.get(this.value);
        s = STRING_REF_NAME + "(" + (name ?? "0x" + toHex(this.value, 4)) + ")";
        break;
      }
      case InsnType.Label: {
        s = this.labelToString(ctx);
        break;
      }
      case InsnType.Control: {
        s = this.controlToString(ctx);
        break;
      }
      case InsnType.Call: {
        s = this.callToString(ctx);
        break;
      }
      case InsnType.Block: {
        if (this.children.length === 0) {
          s = "{}";
          break;
        }
        s = "{" + "\n" + "\t".repeat(this.indent + 1);
        s += this.childrenToString(ctx, 0);
        s += "\n" + "\t".repeat(this.indent) + "}";
        break;
      }
      case InsnType.Variable: {
        s = "v" + this.value;
        break;
      }
      case InsnType.Operator: {
        s = OPERATOR_TEXT[this.value];
        break;
      }
      default: {
        throw new Error("Unexpected instruction type");
      }
    }

    return s;
  }

  // 文・if/switch の条件のように、ほぼ必ず式コンテナが来る位置での表記。
  // 式コンテナなら括弧を付けずに中身を書き、例外的に裸のオペランドが来た場合だけ "[...]" で括って区別する(引数の位置とは逆の約束であることに注意)。
  private conditionString(ctx?: PrintContext): string {
    return this.insnType === InsnType.Expression ? this.expressionToString(ctx) : "[" + this.toString(ctx) + "]";
  }

  // 文の位置。Control/Call か式コンテナしか来ないので印は要らない。
  private statementString(ctx?: PrintContext): string {
    return this.insnType === InsnType.Expression ? this.expressionToString(ctx) : this.toString(ctx);
  }

  private expressionToString(ctx?: PrintContext): string {
    const dataStack: string[] = [];
    const precStack: number[] = [];
    for (const child of this.children) {
      if (child.insnType === InsnType.Operator) {
        if (child.value === 0) {
          break;
        }
        let bStr = dataStack.pop()!;
        let aStr = dataStack.pop()!;
        const bPrec = precStack.pop()!;
        const aPrec = precStack.pop()!;
        const rPrec = OPERATOR_PRECEDENCE[child.value];
        const op = child.toString();

        if (aPrec > rPrec) aStr = "(" + aStr + ")";
        if (bPrec >= rPrec) bStr = "(" + bStr + ")";

        if (UNARY_OPERATORS.has(child.value)) {
          // 単項演算子。負の定数リテラルと区別するためオペランドを必ず括弧で囲む
          dataStack.push(op + "(" + bStr + ")");
        } else {
          dataStack.push(aStr + " " + op + " " + bStr);
        }
        precStack.push(rPrec);
      } else {
        // 式の中の Block は「実行して結果を値として使う」もの。剥がすと復元できないので括弧を残す。
        if (child.insnType === InsnType.Block) {
          dataStack.push("{ " + child.children.map((c) => c.toString(ctx)).join("; ") + "; }");
        } else {
          dataStack.push(child.toString(ctx));
        }
        precStack.push(0);
      }
    }
    return dataStack.pop()!;
  }

  // 名前付き引数としてのラベル。1文字はそのまま残す(意味は呼び出し先ごとに違うため)。
  // if/switch の内側に現れるものは controlToString 側で else / case として描画する。
  private labelToString(ctx?: PrintContext): string {
    const name = "." + String.fromCharCode(this.value);
    if (this.children.length === 0) return name;
    for (const c of this.children) c.indent = this.indent;
    if (this.children.length === 1) return name + " = " + this.children[0].toString(ctx);
    return name + " = [" + this.paramsToString(ctx, 0) + "]";
  }

  private controlToString(ctx?: PrintContext): string {
    let s: string;
    const operands = this.children.filter((c) => c.insnType !== InsnType.Label);
    const clauses = this.children.filter((c) => c.insnType === InsnType.Label);
    for (const c of this.children) c.indent = this.indent;

    switch (this.value) {
      case ControlType.If: {
        s = "if (" + operands[0].conditionString(ctx) + ") " + operands[1].toString(ctx);
        for (const k of clauses) {
          k.children[k.children.length - 1].indent = this.indent;
          if (k.value === ClauseType.ElseIf) {
            s += " else if (" + k.children[0].conditionString(ctx) + ") " + k.children[1].toString(ctx);
          } else if (k.value === ClauseType.Else) {
            s += " else " + k.children[0].toString(ctx);
          }
        }
        break;
      }
      case ControlType.Switch: {
        const pad = "\t".repeat(this.indent + 1);
        s = "switch (" + operands[0].conditionString(ctx) + ") {";
        for (const k of clauses) {
          const body = k.children[k.children.length - 1];
          body.indent = this.indent + 1;
          if (k.value === ClauseType.Case) {
            s += "\n" + pad + "case " + k.children[0].toString(ctx) + ": " + body.toString(ctx);
          } else if (k.value === ClauseType.Default) {
            s += "\n" + pad + "default: " + body.toString(ctx);
          }
        }
        s += "\n" + "\t".repeat(this.indent) + "}";
        break;
      }
      case ControlType.Return: {
        s = operands.length > 0 ? "return " + operands[0].toString(ctx) : "return";
        break;
      }
      // 呼び先が式のスクリプト呼び出し。呼び先が定数の 0x70 と同じ綴りで書けるが、 0x70 の呼び先は常にリテラル、0x121F の呼び先は常に式なので区別できる
      case ControlType.CallIndirect: {
        s = SCRIPT_CALL_NAME + "(" + this.paramsToString(ctx, 0) + ")";
        break;
      }
      case ControlType.LoadMap: {
        s = LOAD_MAP_NAME + "(" + operands[0].idToString(ctx, IMPLICIT_ARG_TYPES[this.value]) + this.paramsToString(ctx, 1, ", ") + ")";
        break;
      }
      // Entity を生成するサブルーチンを呼ぶ。値1つを C の実引数として渡し、戻り値は捨てる。
      // ハンドラは src/vm_ctrl2.c の VM_Ctrl_CreateEntity
      case ControlType.EntityCreate: {
        s = ENTITY_CREATE_NAME + "(" + operands[0].idToString(ctx, IMPLICIT_ARG_TYPES[this.value]) + this.paramsToString(ctx, 1, ", ") + ")";
        break;
      }
      // 汎用のサブルーチン呼び出し。引数は呼ばれた側が自分で読み、戻り値は result に入る。
      // ハンドラは src/vm_ctrl2.c の VM_Ctrl_CallSubroutine
      case ControlType.SubroutineCall: {
        s = SUBROUTINE_CALL_NAME + "(" + operands[0].idToString(ctx, IMPLICIT_ARG_TYPES[this.value]) + this.paramsToString(ctx, 1, ", ") + ")";
        break;
      }
      // EUC-JP の文字列をデバッグ出力する。ハンドラは src/vm.c の VM_Ctrl_DebugPrint
      case ControlType.DebugPrint: {
        s = DEBUG_PRINT_NAME + "(" + this.paramsToString(ctx, 0) + ")";
        break;
      }
      case ControlType.SetZoneCallback: {
        s = SET_ZONE_CALLBACK_NAME + "(" + this.paramsToString(ctx, 0) + ")";
        break;
      }
      // 挙動が未解明の制御命令は opcode をそのまま名前にして保留する。
      default: {
        s = "Ctrl_" + toHex(this.value, 4) + "(" + this.paramsToString(ctx, 0) + ")";
        break;
      }
    }
    return s;
  }

  private callToString(ctx?: PrintContext): string {
    const id = "0x" + toHex(this.value, 4);
    const args = this.paramsToString(ctx, 0);
    return SCRIPT_CALL_NAME + "(" + id + (args.length > 0 ? ", " + args : "") + ")";
  }

  // s32 以外の定数はキャストで型を明示する("(u16)" のような接頭辞を返す)。 型情報を残さないとコンパイル時に正しい型が復元できない。
  private typeCast(): string {
    return this.dataType === DataType.Int32 ? "" : "(" + DATA_TYPE_NAMES[this.dataType] + ")";
  }

  // subroutine ID / script ID のような識別子は16進で描画する(型とエイリアス注釈は残す)。
  // implicitType を渡すとその型のときだけキャストを省く(IMPLICIT_ARG_TYPES の命令は型が1つに決まっているので parser 側が決め打ちできる)
  private idToString(ctx?: PrintContext, implicitType?: DataType): string {
    if (this.insnType !== InsnType.Constant) return this.toString(ctx); // e.g. LoadMap(p0);
    const cast = this.dataType === implicitType ? "" : this.typeCast();
    return cast + "0x" + toHex(this.value, 4) + this.aliasSuffix();
  }

  private paramsToString(ctx: PrintContext | undefined, skip: number, prefix = ""): string {
    let s = "";
    let first = true;
    for (const subInstr of this.children.slice(skip)) {
      if (!first) s += ", ";
      first = false;

      s += subInstr.toString(ctx);
    }
    return s.length > 0 ? prefix + s : s;
  }

  // if/switch は "}" で終わるので ";" を付けない。それ以外の文には付ける。
  private static needsSemicolon(instr: Instruction): boolean {
    if (instr.insnType !== InsnType.Control) return true;
    return instr.value !== ControlType.If && instr.value !== ControlType.Switch;
  }

  private childrenToString(ctx: PrintContext | undefined, skip: number): string {
    let s = "";
    let doNewLine = false;
    for (const subInstr of this.children.slice(skip)) {
      if (this.insnType === InsnType.Control || this.insnType === InsnType.Label) {
        subInstr.indent = this.indent;
      } else {
        subInstr.indent = this.indent + 1;
      }
      if (doNewLine) s += "\n" + "\t".repeat(this.indent + 1);
      doNewLine = true;

      s += subInstr.statementString(ctx);
      if (Instruction.needsSemicolon(subInstr)) s += ";";
    }
    return s;
  }
}
