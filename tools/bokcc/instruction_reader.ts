import { DataType, InsnType, Instruction, MEM_SCRATCH, MEM_STAT, MEM_WORLD } from "./instruction.ts";

export class ByteStream {
  private data: DataView;
  position: number;

  constructor(data: Uint8Array | DataView, position = 0) {
    this.data = data instanceof DataView ? data : new DataView(data.buffer, data.byteOffset, data.byteLength);
    this.position = position;
  }

  readByte(): number {
    if (this.position >= this.data.byteLength) return -1; // EOF
    return this.data.getUint8(this.position++);
  }
}

// (short) キャストの移植: 16bit 値を符号付きに変換する。
const toInt16 = (n: number): number => (n << 16) >> 16;

// 型は命令の下位ニブルそのもので、メモリ参照と定数リテラルで共通。
const TYPE_BY_TAG: Record<number, DataType> = {
  0x1: DataType.Int16,
  0x2: DataType.UInt8,
  0x3: DataType.UInt8_0x03,
  0x4: DataType.Bool,
  0x6: DataType.UInt16,
  0x8: DataType.UInt24,
  0x9: DataType.Int32,
  0xA: DataType.Int32_0x0A,
  0xD: DataType.Int32_0x0D,
};
const TAG_BY_TYPE = new Map<DataType, number>(
  Object.entries(TYPE_BY_TAG).map(([tag, type]) => [type, Number(tag)]),
);

const tagOf = (dataType: DataType, where: string): number => {
  const tag = TAG_BY_TYPE.get(dataType);
  if (tag === undefined) throw new Error(where + ": unexpected data type " + dataType);
  return tag;
};

// Constant の (dataType, value) に対して「デフォルト」となる cmd バイトを返す。
// 実際に読んだ cmd がこれと異なる場合、コマンドエイリアスとして Instruction に記録する。
// Int32 は値が -1〜62 に収まるならコンパクト形式(0xC0-0xFF)が正準形、収まらないなら 9。
const defaultConstantCmd = (dataType: DataType, val: number): number => {
  if (dataType === DataType.Int32 && val >= -1 && val <= 62) {
    return 0xC0 | ((val + 1) & 0x3F);
  }
  return tagOf(dataType, "defaultConstantCmd");
};

// Memory の型タグ(cmd & 0xF)のデフォルト値。
const defaultMemoryTag = (dataType: DataType): number => tagOf(dataType, "defaultMemoryTag");

// Memory のアドレス領域セレクタバイト(& 0xF0 適用前)のデフォルト値。
// 0x203D800 と 0x203F000 の2領域はセレクタが1つしかないためエイリアスなし。
// それ以外(0x203E800 領域)は複数のバイト値が同じ領域を指し得るため、
// 0x00 を正準形と仮定している(実データでの検証はまだできていない)。
const defaultRegionByte = (base: number): number => {
  switch (base) {
    case MEM_STAT: {
      return 0x80;
    }
    case MEM_SCRATCH: {
      return 0x10;
    }
    default: {
      return 0x00; // world
    }
  }
};

export class InstructionReader {
  private stream: ByteStream;
  private alreadyReadInstructions: Instruction[];
  // 直近に readScriptOffset で読んだコンテナ長と、その本体が始まる位置。
  // キーワード/制御命令の本体の終端はこの長さだけが決めるので、
  // 「どのキーワードが子を何個取るか」を知らなくても読める。
  private containerLen = 0;
  private containerStart = 0;

  constructor(stream: ByteStream) {
    this.stream = stream;
    this.alreadyReadInstructions = [];
  }

  readInstructionBlock(): Instruction {
    const instr = new Instruction(InsnType.Block);
    let subInstr: Instruction;
    while ((subInstr = this.readInstruction()).insnType !== InsnType.End) {
      instr.children.push(subInstr);
    }
    return instr;
  }

  // 現在位置から順に命令を読み、End で打ち切る。Block を読んだ直後にも打ち切る(main.ts の decompile コマンドの挙動)。
  decompile(): Instruction[] {
    const instrs: Instruction[] = [];
    let instr: Instruction;
    while ((instr = this.readInstruction()).insnType !== InsnType.End) {
      instrs.push(instr);
      if (instr.insnType === InsnType.Block) break;
    }
    return instrs;
  }

  readInstruction(): Instruction {
    if (this.alreadyReadInstructions.length > 0) {
      return this.alreadyReadInstructions.shift()!;
    }

    const pos = this.stream.position;
    const cmd = this.stream.readByte();
    if (cmd < 0) {
      return Instruction.Invalid;
    }

    let instr: Instruction = Instruction.Invalid;
    let subInstr: Instruction;

    switch (cmd & 0xF0) {
      case 0x00: {
        instr = this.readConstant(cmd);
        break;
      }
      case 0x10:
      case 0x20: {
        instr = this.readMemory(cmd);
        break;
      }
      case 0x30: {
        this.readScriptOffset(cmd);
        instr = new Instruction(InsnType.Expression);
        while (!(subInstr = this.readInstruction()).isExpressionEnd()) {
          instr.children.push(subInstr);
        }
        break;
      }
      case 0x40: {
        if ((cmd & 0xF) === 0xF) {
          instr = new Instruction(InsnType.Parameter, 0xF + this.stream.readByte());
        } else {
          instr = new Instruction(InsnType.Parameter, cmd & 0xF);
        }
        break;
      }
      case 0x50: {
        this.readScriptOffset(cmd);
        instr = this.readKeyword();
        break;
      }
      case 0x60: {
        this.readScriptOffset(cmd);
        instr = this.readControl();
        break;
      }
      case 0x70: {
        this.readScriptOffset(cmd);
        instr = this.readCall();
        break;
      }
      case 0x80: {
        this.readScriptOffset(cmd);
        instr = new Instruction(InsnType.Block);
        while ((subInstr = this.readInstruction()).insnType !== InsnType.End) {
          instr.children.push(subInstr);
        }
        break;
      }
      case 0x90: {
        instr = new Instruction(InsnType.Variable, cmd & 0xF);
        break;
      }
      case 0xA0:
      case 0xB0: {
        instr = new Instruction(InsnType.Operator, cmd & 0x1F);
        break;
      }
      case 0xC0:
      case 0xD0:
      case 0xE0:
      case 0xF0: {
        instr = this.readConstant(cmd);
        break;
      }
    }

    instr.address = pos;
    return instr;
  }

  protected readScriptOffset(cmd: number): number {
    let len: number;
    switch (cmd & 0xF) {
      case 0xD: {
        len = this.stream.readByte();
        break;
      }
      case 0xE: {
        len = this.stream.readByte() | (this.stream.readByte() << 8);
        break;
      }
      case 0xF: {
        len = this.stream.readByte() | (this.stream.readByte() << 8) | (this.stream.readByte() << 16);
        break;
      }
      default: {
        len = cmd & 0xF;
        break;
      }
    }
    this.containerLen = len;
    this.containerStart = this.stream.position;
    return len;
  }

  protected readConstant(cmd: number): Instruction {
    let val = 0;
    let type: DataType;
    if ((cmd & 0xF0) === 0) {
      switch (cmd) {
        case 0: {
          return new Instruction(InsnType.End);
        }
        // 1 と 8 は VM_DecodeValue の同じ経路(2バイト・符号拡張)、6 だけがゼロ拡張。
        case 1:
        case 8: {
          type = TYPE_BY_TAG[cmd];
          val = toInt16(this.stream.readByte() | (this.stream.readByte() << 8));
          break;
        }
        case 2:
        case 3:
        case 4: {
          type = TYPE_BY_TAG[cmd];
          val = this.stream.readByte();
          break;
        }
        case 6: {
          type = DataType.UInt16;
          val = this.stream.readByte() | (this.stream.readByte() << 8);
          break;
        }
        case 9:
        case 10:
        case 13: {
          type = TYPE_BY_TAG[cmd];
          val = this.stream.readByte() | (this.stream.readByte() << 8) | (this.stream.readByte() << 16) | (this.stream.readByte() << 24);
          break;
        }
        // opcode 7: 長さ1バイト + その長さ分のバイト列(VM_DecodeValue は pc + pc[0] + 1 進める)
        case 7: {
          const len = this.stream.readByte();
          const bytes = new Uint8Array(len);
          for (let i = 0; i < len; i++) bytes[i] = this.stream.readByte();
          const str = new Instruction(InsnType.String);
          str.bytes = bytes;
          return str;
        }
        // opcode 14: 2バイトの文字列ID(Textbox_LookupString に渡される)
        case 14: {
          const id = this.stream.readByte() | (this.stream.readByte() << 8);
          return new Instruction(InsnType.StringRef, id);
        }
        default: {
          throw new Error("Unknown data type " + cmd);
        }
      }
    } else {
      type = DataType.Int32;
      val = (cmd & 0x3F) - 1;
    }

    const instr = new Instruction(InsnType.Constant, type, val);
    const defaultCmd = defaultConstantCmd(type, val);
    if (cmd !== defaultCmd) {
      instr.hasForcedOpcode = true;
      instr.forcedOpcode = cmd;
    }
    return instr;
  }

  protected readMemory(cmd: number): Instruction {
    const regByte = this.stream.readByte();
    let base: number;
    switch (regByte & 0xF0) {
      case 0x80: {
        base = MEM_STAT;
        break;
      }
      case 0x10: {
        base = MEM_SCRATCH;
        break;
      }
      default: {
        base = MEM_WORLD;
        break;
      }
    }

    // 領域バイトの下位ニブルは Bool のときだけ意味を持ち、ビット番号(0-7)を表す。
    // 他の型では常に 0。アドレスはビッグエンディアンのバイトオフセット。
    const bitIndex = regByte & 0xF;
    const addr = base + ((this.stream.readByte() << 8) | this.stream.readByte());

    // メモリ参照では 1 と 6 の動作は同じ(どちらも16bit・ストライド2)だが、
    // タグとしては別物なので型も分けて保持する。
    const dataType = TYPE_BY_TAG[cmd & 0xF] ?? DataType.Void;

    const instr = new Instruction();
    instr.dataType = dataType;
    instr.value = addr;
    instr.memRegionBase = base;
    instr.bitIndex = bitIndex;

    if ((cmd & 0xF0) === 0x20) {
      instr.insnType = InsnType.MemoryIndexed;
      instr.children.push(this.readInstruction());
      instr.children.push(this.readInstruction());
    } else {
      instr.insnType = InsnType.Memory;
    }

    const defaultReg = defaultRegionByte(base);
    if ((regByte & 0xF0) !== defaultReg) {
      instr.hasForcedRegion = true;
      instr.forcedRegion = regByte & 0xF0;
    }

    if (dataType !== DataType.Void) {
      const defaultTag = defaultMemoryTag(dataType);
      if ((cmd & 0xF) !== defaultTag) {
        instr.hasForcedOpcode = true;
        instr.forcedOpcode = cmd & 0xF;
      }
    }

    return instr;
  }

  // キーワードは「1文字 + 本体」。本体に何が何個入るかは呼び出し先のエンジン関数次第なので、
  // 個数は決め打ちせずコンテナ長が尽きるまで読む。
  protected readKeyword(): Instruction {
    const end = this.containerStart + this.containerLen;
    const instr = new Instruction(InsnType.Keyword, this.stream.readByte());
    while (this.stream.position < end) {
      instr.children.push(this.readInstruction());
    }
    return instr;
  }

  // 制御命令もキーワードと同じで、続く値がいくつ並ぶかは呼び出し先が決める
  // (0xB745 は呼ばれたエンジン関数が自分で Script_GetValue() する)。コンテナ長で読む。
  protected readControl(): Instruction {
    const end = this.containerStart + this.containerLen;
    const tag = this.stream.readByte() | (this.stream.readByte() << 8);
    // 次のキーワードまでのバイト数。構造から導けるので値は使わない。
    if ((this.stream.readByte() & 0x80) !== 0) {
      this.stream.readByte();
    }

    const instr = new Instruction(InsnType.Control, tag);
    while (this.stream.position < end) {
      const subInstr = this.readInstruction();
      if (subInstr.insnType !== InsnType.End) {
        instr.children.push(subInstr);
      }
    }

    return instr;
  }

  protected readCall(): Instruction {
    const tag = this.stream.readByte() | (this.stream.readByte() << 8);

    const instr = new Instruction(InsnType.Call, tag);
    let subInstr: Instruction;
    while ((subInstr = this.readInstruction()).insnType !== InsnType.End) {
      instr.children.push(subInstr);
    }

    return instr;
  }
}
