import { ConstantOp, DataType, InsnType, Instruction, memSelectorOf, Opcode, OPERATOR_END, PARAM_EXTENDED } from "./instruction.ts";

// コンパイル専用。Instruction をバイト列に書き出す(後半。前半の解析は parser.ts)。
//
// コンテナの長さプレフィックスと制御命令のラベル距離は中身を書き終えるまで分からないので、いったん仮置きして後から埋め戻す。

class Writer {
  bytes: number[] = [];

  private u8(n: number): void {
    this.bytes.push(n & 0xFF);
  }

  private u16le(n: number): void {
    this.bytes.push(n & 0xFF, (n >> 8) & 0xFF);
  }

  // block/call のような「長さプレフィックス付きコンテナ」を書く共通ヘルパー。
  // 中身を書き終えるまでバイト数が分からないので、opcodeバイトを仮置きしておき、書き終わった後に実際のバイト数から長さニブル/拡張バイトを逆算して埋め戻す。
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

  private writeConstant(instr: Instruction): void {
    const cmd = instr.hasForcedOpcode ? instr.forcedOpcode! : instr.defaultConstantOpcode();
    this.u8(cmd);
    if (cmd >= Opcode.ConstantCompact) return; // コンパクト形式は値がopcodeに埋まっている
    // コンパクト形式を除けば cmd は型タグそのものなので、続くバイト数は型で決まる
    switch (cmd) {
      case DataType.Int16:
      case DataType.UInt16:
      case DataType.UInt24: {
        this.u16le(instr.value);
        break;
      }
      case DataType.UInt8:
      case DataType.UInt8_0x03:
      case DataType.Bool: {
        this.u8(instr.value);
        break;
      }
      case DataType.Int32:
      case DataType.Int32_0x0A:
      case DataType.Int32_0x0D: {
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
    const tag = instr.hasForcedOpcode ? instr.forcedOpcode! : instr.typeTag();
    const high = instr.insnType === InsnType.MemoryIndexed ? Opcode.MemoryIndexed : Opcode.Memory;
    this.u8(high | tag);
    const base = instr.memRegionBase!;
    // 領域バイト: 上位ニブルが領域、下位ニブルは Bool のビット番号
    const region = instr.hasForcedRegion ? instr.forcedRegion! : memSelectorOf(base);
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
        this.container(Opcode.Block, () => {
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(ConstantOp.End);
        });
        break;
      }
      case InsnType.Call: {
        this.container(Opcode.Call, () => {
          this.u16le(instr.value);
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(ConstantOp.End);
        });
        break;
      }
      case InsnType.Expression: {
        this.container(Opcode.Expression, () => {
          for (const child of instr.children) this.writeInstruction(child);
          this.u8(Opcode.Operator | OPERATOR_END); // 式の終端
        });
        break;
      }
      case InsnType.Label: {
        this.container(Opcode.Label, () => {
          this.u8(instr.value); // ラベルの1文字
          for (const child of instr.children) this.writeInstruction(child);
        });
        break;
      }
      case InsnType.Control: {
        this.container(Opcode.Control, () => {
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
        this.u8(ConstantOp.String);
        this.u8(instr.bytes!.length);
        for (const b of instr.bytes!) this.u8(b);
        break;
      }
      case InsnType.StringRef: {
        this.u8(ConstantOp.StringRef);
        this.u16le(instr.value);
        break;
      }
      case InsnType.Memory:
      case InsnType.MemoryIndexed: {
        this.writeMemory(instr);
        break;
      }
      case InsnType.Parameter: {
        if (instr.value >= PARAM_EXTENDED) {
          this.u8(Opcode.Parameter | PARAM_EXTENDED);
          this.u8(instr.value - PARAM_EXTENDED);
        } else {
          this.u8(Opcode.Parameter | instr.value);
        }
        break;
      }
      case InsnType.Variable: {
        this.u8(Opcode.Variable | instr.value);
        break;
      }
      case InsnType.Operator: {
        this.u8(Opcode.Operator | instr.value);
        break;
      }
      default: {
        throw new Error(`compile: InsnType ${InsnType[instr.insnType]} is not supported yet`);
      }
    }
  }

  // 制御命令は tag の後に「最初のラベル命令(無ければ終端)までのバイト数」が入る。
  // 中身を書かないと分からないので、いったん1バイトで仮置きし、後から埋める
  // (0x80以上になる場合は2バイト形式に差し替える)。
  private writeControlBody(instr: Instruction): void {
    const fieldPos = this.bytes.length;
    this.bytes.push(0);
    const bodyStart = this.bytes.length;
    let distance = -1;
    for (const child of instr.children) {
      if (distance < 0 && child.insnType === InsnType.Label) distance = this.bytes.length - bodyStart;
      this.writeInstruction(child);
    }
    // 距離は「最初のラベル、または終端命令の位置まで」(終端命令の手前まで)
    if (distance < 0) distance = this.bytes.length - bodyStart;
    this.u8(ConstantOp.End);
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
