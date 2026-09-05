export enum InsnType {
  Invalid,
  Constant,
  Memory,
  MemoryIndexed,
  Expression,
  Parameter,
  Keyword,
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
  NativeCall_9906 = 0x9906,
  NativeCall_B745 = 0xB745,
}

// キーワードは1文字の名前付き引数で、意味は呼び出し先のエンジン関数ごとに異なる。
// ここに挙げるのは if/switch の内側でだけ現れる、意味が確定しているものだけ。
export enum KeywordType {
  Case = 0x63,
  Default = 0x64,
  Else = 0x65,
  ElseIf = 0x69,
}

// 型は命令の下位ニブルそのもの。メモリ参照と定数リテラルで同じニブル空間を使い、
// 各文脈が表現できる範囲で実装されている(例: メモリ参照は s16 と u16 を区別しない、
// 定数リテラルは u24 を2バイトで持つ)。
// 0x03 / 0x0A / 0x0D はVMのswitchには存在するがスクリプト中に一度も現れない。
// 本当に別名なのか別の型なのか判定材料が無いので、区別だけ付けて保留する。
export enum DataType {
  Void,
  Bool, // 0x04
  UInt8, // 0x02
  UInt8_0x03, // 0x03  未使用
  Int16, // 0x01
  UInt16, // 0x06
  UInt24, // 0x08
  Int32, // 0x09
  Int32_0x0A, // 0x0A  未使用
  Int32_0x0D, // 0x0D  未使用
}

export const toHex = (n: number, minDigits = 0): string => n.toString(16).toUpperCase().padStart(minDigits, "0");

// Memory の3つのアドレス領域ベース(bokasm 側の world/scratch/stat と同じ命名)。
export const MEM_STAT = 0x0203D800;
export const MEM_WORLD = 0x0203E800;
export const MEM_SCRATCH = 0x0203F000;

const MEM_REGION_NAMES: Record<number, string> = {
  [MEM_STAT]: "stat",
  [MEM_WORLD]: "world",
  [MEM_SCRATCH]: "scratch",
};

export class Instruction {
  static readonly Invalid: Instruction = new Instruction();

  private static readonly DataTypeStrings: string[] = [
    "void",
    "bool",
    "u8",
    "u8_0x03",
    "s16",
    "u16",
    "u24",
    "s32",
    "s32_0x0A",
    "s32_0x0D",
  ];
  private static readonly OperatorStrings: string[] = [
    ";",
    "-",
    "!",
    "~",
    "+",
    "-",
    "*",
    "/",
    "%",
    "<<",
    ">>",
    "==",
    "!=",
    "<",
    "<=",
    ">",
    ">=",
    "|",
    "&",
    "^",
    "||",
    "&&",
    "=",
    "",
  ];
  private static readonly OperatorPrecedence: number[] = [
    0,
    2,
    2,
    2,
    4,
    4,
    3,
    3,
    3,
    5,
    5,
    7,
    7,
    6,
    6,
    6,
    6,
    10,
    8,
    9,
    12,
    11,
    14,
    16,
  ];

  address: number;
  insnType: InsnType;
  dataType: DataType;
  children: Instruction[];
  value: number;
  indent: number;

  // コマンドエイリアス保持用: Constant/Memory を読んだ際の生の opcode ニブルが
  // 「デフォルト」形式と異なっていた場合にのみセットされる(instruction_reader.ts 側で設定)。
  hasForcedOpcode?: boolean;
  forcedOpcode?: number;
  // Memory/MemoryIndexed のアドレス領域セレクタバイト(& 0xF0 適用前)が
  // デフォルトと異なっていた場合にのみセットされる。
  hasForcedRegion?: boolean;
  forcedRegion?: number;
  // String(opcode 7)の生バイト列。charmap による可読化は可逆性を検証してから行う。
  bytes?: Uint8Array;
  // Bool のビット番号(0-7)。領域バイトの下位ニブルに入っている。
  bitIndex?: number;
  // Memory/MemoryIndexed の value(絶対アドレス)の計算に使った領域ベースアドレス
  // (MEM_STAT/MEM_WORLD/MEM_SCRATCH のいずれか)。world/scratch/stat 表記での
  // 出力に使う(instruction_reader.ts の readMemory がセットする)。
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
    return this.insnType === InsnType.Operator && this.value === 0;
  }

  // hasForcedOpcode/hasForcedRegion が立っている場合に、それを示す注釈を返す
  // (コマンドエイリアスの情報を出力から消さないため)。
  private aliasSuffix(): string {
    let s = "";
    if (this.hasForcedRegion) s += " /*reg:0x" + toHex(this.forcedRegion!) + "*/";
    if (this.hasForcedOpcode) s += " /*op:0x" + toHex(this.forcedOpcode!) + "*/";
    return s;
  }

  // Memory/MemoryIndexed のベースアドレス部分を、既知の領域(world/scratch/stat)
  // であれば "region + 0xOFFSET" の形で、そうでなければ従来通り生アドレスで返す。
  // Bool(BIT)の場合は addrValue・領域ベースの両方をビットアドレスとして扱うため
  // divisor=8 を渡す(この場合 addrValue は 8 で割る前の値を渡すこと)。
  private formatBase(addrValue: number, opts: { divisor?: number; fallbackPad?: number } = {}): string {
    const divisor = opts.divisor ?? 1;
    const byteAddr = Math.trunc(addrValue / divisor);
    if (this.memRegionBase !== undefined) {
      const regionBase = Math.trunc(this.memRegionBase / divisor);
      const name = MEM_REGION_NAMES[this.memRegionBase] ?? ("0x" + toHex(this.memRegionBase));
      const offset = byteAddr - regionBase;
      return name + " + 0x" + toHex(offset);
    }
    return "0x" + toHex(byteAddr, opts.fallbackPad ?? 0);
  }

  toString(): string {
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
      // 定数の型(=ニブル)はテキストから復元できないとコンパイルできないので、
      // 最頻の s32(コンパクト形式)以外はキャストで型を明示する。
      case InsnType.Constant: {
        s = this.typeCast() + this.value.toString() + this.aliasSuffix();
        break;
      }
      case InsnType.Memory: {
        if (this.dataType === DataType.Bool) {
          s = "BIT(";
          s += this.formatBase(this.value);
          s += ", ";
          s += this.bitIndex;
          s += ")";
        } else {
          s = "*(";
          s += "(" + Instruction.DataTypeStrings[this.dataType] + " *)";
          s += "(" + this.formatBase(this.value) + ")";
          s += ")";
        }
        s += this.aliasSuffix();
        break;
      }
      case InsnType.MemoryIndexed: {
        if (this.dataType === DataType.Bool) {
          s = "BIT(";
          s += this.formatBase(this.value);
          s += ", ";
          s += this.bitIndex;
          s += ", ";
          s += this.children[0].toString() + ", " + this.children[1].toString();
          s += ")";
        } else {
          s = "(";
          s += "(" + Instruction.DataTypeStrings[this.dataType] + " *)";
          s += "(" + this.formatBase(this.value) + ")";
          s += ")[";
          s += this.children[0].toString() + ", " + this.children[1].toString();
          s += "]";
        }
        s += this.aliasSuffix();
        break;
      }
      case InsnType.Expression: {
        s = "(" + this.expressionToString() + ")";
        break;
      }
      case InsnType.Parameter: {
        // index 0 は gVM.result(直前の文の値)。スクリプト呼び出しや式でも上書きされる。
        if (this.value === 0) {
          s = "result";
        } else {
          s = "p" + (this.value - 1);
        }
        break;
      }
      case InsnType.String: {
        s = '"';
        for (const b of this.bytes!) s += "\\x" + toHex(b, 2);
        s += '"';
        break;
      }
      case InsnType.StringRef: {
        s = "StringRef(0x" + toHex(this.value, 4) + ")";
        break;
      }
      case InsnType.Keyword: {
        s = this.keywordToString();
        break;
      }
      case InsnType.Control: {
        s = this.controlToString();
        break;
      }
      case InsnType.Call: {
        s = this.callToString();
        break;
      }
      case InsnType.Block: {
        if (this.children.length === 0) {
          s = "{}";
          break;
        }
        s = "{" + "\n" + "\t".repeat(this.indent + 1);
        s += this.childrenToString(0);
        s += "\n" + "\t".repeat(this.indent) + "}";
        break;
      }
      case InsnType.Variable: {
        s = "v" + this.value;
        break;
      }
      case InsnType.Operator: {
        s = Instruction.OperatorStrings[this.value];
        break;
      }
      default: {
        throw new Error("Unexpected instruction type");
      }
    }

    return s;
  }

  // 文・if/switch の条件のように、ほぼ必ず式コンテナが来る位置での表記。
  // 式コンテナなら括弧を付けずに中身を書き、例外的に裸のオペランドが来た場合だけ
  // "[...]" で括って区別する(引数の位置とは逆の約束であることに注意)。
  private conditionString(): string {
    return this.insnType === InsnType.Expression ? this.expressionToString() : "[" + this.toString() + "]";
  }

  // 文の位置。Control/Call か式コンテナしか来ないので印は要らない。
  private statementString(): string {
    return this.insnType === InsnType.Expression ? this.expressionToString() : this.toString();
  }

  private expressionToString(): string {
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
        const rPrec = Instruction.OperatorPrecedence[child.value];
        const op = child.toString();

        if (aPrec > rPrec) aStr = "(" + aStr + ")";
        if (bPrec >= rPrec) bStr = "(" + bStr + ")";

        switch (child.value) {
          case 1:
          case 2:
          case 3:
          case 23: {
            // 単項演算子。負の定数リテラルと区別するためオペランドを必ず括弧で囲む
            dataStack.push(op + "(" + bStr + ")");
            break;
          }
          case 22: {
            // Assign
            dataStack.push(aStr + " " + op + " " + bStr);
            break;
          }
          default: {
            // Binary operator
            dataStack.push(aStr + " " + op + " " + bStr);
            break;
          }
        }
        precStack.push(rPrec);
      } else {
        // 式の中の Block は「実行して結果を値として使う」もの。剥がすと復元できないので括弧を残す。
        if (child.insnType === InsnType.Block) {
          dataStack.push("{ " + child.children.map((c) => c.toString()).join("; ") + "; }");
        } else {
          dataStack.push(child.toString());
        }
        precStack.push(0);
      }
    }
    return dataStack.pop()!;
  }

  // 名前付き引数としてのキーワード。1文字はそのまま残す(意味は呼び出し先ごとに違うため)。
  // if/switch の内側に現れるものは controlToString 側で else / case として描画する。
  private keywordToString(): string {
    const name = "." + String.fromCharCode(this.value);
    if (this.children.length === 0) return name;
    for (const c of this.children) c.indent = this.indent;
    if (this.children.length === 1) return name + " = " + this.children[0].toString();
    return name + " = [" + this.paramsToString(0) + "]";
  }

  private controlToString(): string {
    let s: string;
    const operands = this.children.filter((c) => c.insnType !== InsnType.Keyword);
    const keywords = this.children.filter((c) => c.insnType === InsnType.Keyword);
    for (const c of this.children) c.indent = this.indent;

    switch (this.value) {
      case ControlType.If: {
        s = "if (" + operands[0].conditionString() + ") " + operands[1].toString();
        for (const k of keywords) {
          k.children[k.children.length - 1].indent = this.indent;
          if (k.value === KeywordType.ElseIf) {
            s += " else if (" + k.children[0].conditionString() + ") " + k.children[1].toString();
          } else if (k.value === KeywordType.Else) {
            s += " else " + k.children[0].toString();
          }
        }
        break;
      }
      case ControlType.Switch: {
        const pad = "\t".repeat(this.indent + 1);
        s = "switch (" + operands[0].conditionString() + ") {";
        for (const k of keywords) {
          const body = k.children[k.children.length - 1];
          body.indent = this.indent + 1;
          if (k.value === KeywordType.Case) {
            s += "\n" + pad + "case " + k.children[0].toString() + ": " + body.toString();
          } else if (k.value === KeywordType.Default) {
            s += "\n" + pad + "default: " + body.toString();
          }
        }
        s += "\n" + "\t".repeat(this.indent) + "}";
        break;
      }
      case ControlType.Return: {
        s = operands.length > 0 ? "return " + operands[0].toString() : "return";
        break;
      }
      // 呼び先が式のスクリプト呼び出し。呼び先が定数の 0x70 と同じ綴りで書ける
      // (0x70 の呼び先は常にリテラル、0x121F の呼び先は常に式なので区別できる)。
      case ControlType.CallIndirect: {
        s = "ScriptCall(" + this.paramsToString(0) + ")";
        break;
      }
      case ControlType.LoadMap: {
        s = "LoadMap(" + operands[0].idToString() + this.paramsToString(1, ", ") + ")";
        break;
      }
      case ControlType.NativeCall_9906:
      case ControlType.NativeCall_B745: {
        s = "NativeCall_" + toHex(this.value) + "(" + operands[0].idToString() + this.paramsToString(1, ", ") + ")";
        break;
      }
      // 挙動が未解明の制御命令は opcode をそのまま名前にして保留する。
      default: {
        s = "Ctrl_" + toHex(this.value, 4) + "(" + this.paramsToString(0) + ")";
        break;
      }
    }
    return s;
  }

  private callToString(): string {
    const id = "0x" + toHex(this.value, 4);
    const args = this.paramsToString(0);
    return "ScriptCall(" + id + (args.length > 0 ? ", " + args : "") + ")";
  }

  // s32 以外の定数はキャストで型を明示する("(u16)" のような接頭辞を返す)。
  private typeCast(): string {
    return this.dataType === DataType.Int32 ? "" : "(" + Instruction.DataTypeStrings[this.dataType] + ")";
  }

  // subroutine ID / script ID のような識別子は16進で描画する(型とエイリアス注釈は残す)。
  private idToString(): string {
    if (this.insnType !== InsnType.Constant) return this.toString();
    return this.typeCast() + "0x" + toHex(this.value, 4) + this.aliasSuffix();
  }

  private paramsToString(skip: number, prefix = ""): string {
    let s = "";
    let first = true;
    for (const subInstr of this.children.slice(skip)) {
      if (!first) s += ", ";
      first = false;

      s += subInstr.toString();
    }
    return s.length > 0 ? prefix + s : s;
  }

  // if/switch は "}" で終わるので ";" を付けない。それ以外の文には付ける。
  private static needsSemicolon(instr: Instruction): boolean {
    if (instr.insnType !== InsnType.Control) return true;
    return instr.value !== ControlType.If && instr.value !== ControlType.Switch;
  }

  private childrenToString(skip: number): string {
    let s = "";
    let doNewLine = false;
    for (const subInstr of this.children.slice(skip)) {
      if (this.insnType === InsnType.Control || this.insnType === InsnType.Keyword) {
        subInstr.indent = this.indent;
      } else {
        subInstr.indent = this.indent + 1;
      }
      if (doNewLine) s += "\n" + "\t".repeat(this.indent + 1);
      doNewLine = true;

      s += subInstr.statementString();
      if (Instruction.needsSemicolon(subInstr)) s += ";";
    }
    return s;
  }
}
