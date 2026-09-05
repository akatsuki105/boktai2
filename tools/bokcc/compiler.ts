import { DataType, InsnType, Instruction, MEM_SCRATCH, MEM_STAT } from "./instruction.ts";

// 型タグ(命令の下位ニブル)。instruction_reader.ts の TYPE_BY_TAG の逆。
const TAG_BY_TYPE: Record<number, number> = {
  [DataType.Int16]: 0x1,
  [DataType.UInt8]: 0x2,
  [DataType.UInt8_0x03]: 0x3,
  [DataType.Bool]: 0x4,
  [DataType.UInt16]: 0x6,
  [DataType.UInt24]: 0x8,
  [DataType.Int32]: 0x9,
  [DataType.Int32_0x0A]: 0xA,
  [DataType.Int32_0x0D]: 0xD,
};

const regionByteOf = (base: number): number => base === MEM_STAT ? 0x80 : base === MEM_SCRATCH ? 0x10 : 0x00;

class Writer {
  bytes: number[] = [];

  private u8(n: number): void {
    this.bytes.push(n & 0xFF);
  }

  private u16le(n: number): void {
    this.bytes.push(n & 0xFF, (n >> 8) & 0xFF);
  }

  // block/call のような「長さプレフィックス付きコンテナ」を書く共通ヘルパー。
  // 中身を書き終えるまでバイト数が分からないので、opcodeバイトを仮置きしておき、
  // 書き終わった後に実際のバイト数から長さニブル/拡張バイトを逆算して埋め戻す。
  private container(opcodeHighNibble: number, writeBody: () => void): void {
    const opcodePos = this.bytes.length;
    this.bytes.push(0);
    writeBody();
    const size = this.bytes.length - opcodePos - 1;

    if (size <= 0xC) {
      this.bytes[opcodePos] = opcodeHighNibble | size;
    } else if (size <= 0xFF) {
      this.bytes[opcodePos] = opcodeHighNibble | 0xD;
      this.bytes.splice(opcodePos + 1, 0, size);
    } else if (size <= 0xFFFF) {
      this.bytes[opcodePos] = opcodeHighNibble | 0xE;
      this.bytes.splice(opcodePos + 1, 0, size & 0xFF, (size >> 8) & 0xFF);
    } else {
      this.bytes[opcodePos] = opcodeHighNibble | 0xF;
      this.bytes.splice(opcodePos + 1, 0, size & 0xFF, (size >> 8) & 0xFF, (size >> 16) & 0xFF);
    }
  }

  // 定数の opcode バイト(エイリアスがあればそれを優先)
  private constantCmd(instr: Instruction): number {
    if (instr.hasForcedOpcode) return instr.forcedOpcode!;
    if (instr.dataType === DataType.Int32 && instr.value >= -1 && instr.value <= 62) {
      return 0xC0 | ((instr.value + 1) & 0x3F);
    }
    return TAG_BY_TYPE[instr.dataType];
  }

  private writeConstant(instr: Instruction): void {
    const cmd = this.constantCmd(instr);
    this.u8(cmd);
    if ((cmd & 0xC0) === 0xC0) return; // コンパクト形式は値がopcodeに埋まっている
    switch (cmd) {
      case 0x1:
      case 0x6:
      case 0x8: {
        this.u16le(instr.value);
        break;
      }
      case 0x2:
      case 0x3:
      case 0x4: {
        this.u8(instr.value);
        break;
      }
      case 0x9:
      case 0xA:
      case 0xD: {
        this.u16le(instr.value);
        this.u16le(instr.value >> 16);
        break;
      }
      default: {
        throw new Error("compile: unexpected constant opcode 0x" + cmd.toString(16));
      }
    }
  }

  private writeMemory(instr: Instruction): void {
    const tag = instr.hasForcedOpcode ? instr.forcedOpcode! : TAG_BY_TYPE[instr.dataType];
    const high = instr.insnType === InsnType.MemoryIndexed ? 0x20 : 0x10;
    this.u8(high | tag);
    const base = instr.memRegionBase!;
    // 領域バイト: 上位ニブルが領域、下位ニブルは Bool のビット番号
    const region = instr.hasForcedRegion ? instr.forcedRegion! : regionByteOf(base);
    this.u8(region | (instr.bitIndex ?? 0));
    const off = instr.value - base;
    this.u8((off >> 8) & 0xFF); // アドレスはビッグエンディアン
    this.u8(off & 0xFF);
    if (instr.insnType === InsnType.MemoryIndexed) {
      for (const child of instr.children) this.writeInstruction(child);
    }
  }

  writeInstruction(instr: Instruction): void {
    switch (instr.insnType) {
      case InsnType.Block: {
        this.container(0x80, () => {
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(0x00); // End
        });
        break;
      }
      case InsnType.Call: {
        this.container(0x70, () => {
          this.u16le(instr.value);
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(0x00); // End
        });
        break;
      }
      case InsnType.Expression: {
        this.container(0x30, () => {
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(0xA0); // 式の終端 (Operator 0)
        });
        break;
      }
      case InsnType.Keyword: {
        this.container(0x50, () => {
          this.u8(instr.value); // キーワードの1文字
          for (const child of instr.children) this.writeInstruction(child);
        });
        break;
      }
      case InsnType.Control: {
        this.container(0x60, () => {
          this.u16le(instr.value);
          this.writeControlBody(instr);
        });
        break;
      }
      case InsnType.Constant: {
        this.writeConstant(instr);
        break;
      }
      case InsnType.String: {
        this.u8(0x07);
        this.u8(instr.bytes!.length);
        for (const b of instr.bytes!) this.u8(b);
        break;
      }
      case InsnType.StringRef: {
        this.u8(0x0E);
        this.u16le(instr.value);
        break;
      }
      case InsnType.Memory:
      case InsnType.MemoryIndexed: {
        this.writeMemory(instr);
        break;
      }
      case InsnType.Parameter: {
        if (instr.value >= 0xF) {
          this.u8(0x4F);
          this.u8(instr.value - 0xF);
        } else {
          this.u8(0x40 | instr.value);
        }
        break;
      }
      case InsnType.Variable: {
        this.u8(0x90 | instr.value);
        break;
      }
      case InsnType.Operator: {
        this.u8(0xA0 | instr.value);
        break;
      }
      default: {
        throw new Error(`compile: InsnType ${InsnType[instr.insnType]} is not supported yet`);
      }
    }
  }

  // 制御命令は tag の後に「次のキーワード命令(無ければ終端)までのバイト数」が入る。
  // 中身を書かないと分からないので、いったん1バイトで仮置きし、後から埋める
  // (0x80以上になる場合は2バイト形式に差し替える)。
  private writeControlBody(instr: Instruction): void {
    const fieldPos = this.bytes.length;
    this.bytes.push(0);
    const bodyStart = this.bytes.length;
    let distance = -1;
    for (const child of instr.children) {
      if (distance < 0 && child.insnType === InsnType.Keyword) distance = this.bytes.length - bodyStart;
      this.writeInstruction(child);
    }
    // 距離は「次のキーワード、または終端命令の位置まで」(終端命令の手前まで)
    if (distance < 0) distance = this.bytes.length - bodyStart;
    this.u8(0x00); // End
    // 0x80未満なら1バイト、そうでなければ2バイト(ビッグエンディアン、上位バイトに 0x80 を立てる)
    if (distance < 0x80) {
      this.bytes[fieldPos] = distance;
    } else {
      this.bytes[fieldPos] = 0x80 | ((distance >> 8) & 0x7F);
      this.bytes.splice(fieldPos + 1, 0, distance & 0xFF);
    }
  }

  getBytes(): Uint8Array {
    return new Uint8Array(this.bytes);
  }
}

export const compile = (instr: Instruction): Uint8Array => {
  const w = new Writer();
  w.writeInstruction(instr);
  return w.getBytes();
};
