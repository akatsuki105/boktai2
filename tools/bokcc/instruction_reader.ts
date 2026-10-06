import { ConstantOp, DataType, dataTypeOfTag, InsnType, Instruction, memRegionOf, memSelectorOf, Opcode, PARAM_EXTENDED } from "./instruction.ts";

// デコンパイル専用。バイト列から Instruction を読む(前半。後半の描画は instruction.ts の toString)。
//
// ByteStream はROM上の連続したバイト列、InstructionReader はそこから命令を1つずつ組み立てる。
// 「デフォルト」形式とは違う opcode や領域セレクタで書かれていた場合は、元のバイト列に戻せるようにコマンドエイリアスとして Instruction に記録する。

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

export class InstructionReader {
  private stream: ByteStream;
  private alreadyReadInstructions: Instruction[];
  // 直近に readScriptOffset で読んだコンテナ長と、その本体が始まる位置。
  // ラベル/制御命令の本体の終端はこの長さだけが決めるので、「どのラベルが子を何個取るか」を知らなくても読める。
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

    // Operator とコンパクト形式の定数は上位ニブルを複数使うので、ニブルで分ける前に判定する。
    if (cmd >= Opcode.ConstantCompact) {
      instr = this.readConstant(cmd);
    } else if ((cmd & 0xE0) === Opcode.Operator) {
      instr = new Instruction(InsnType.Operator, cmd & 0x1F);
    } else {
      switch (cmd & 0xF0) {
        case Opcode.Constant: {
          instr = this.readConstant(cmd);
          break;
        }
        case Opcode.Memory:
        case Opcode.MemoryIndexed: {
          instr = this.readMemory(cmd);
          break;
        }
        case Opcode.Expression: {
          this.readScriptOffset(cmd);
          instr = new Instruction(InsnType.Expression);
          while (!(subInstr = this.readInstruction()).isExpressionEnd()) {
            instr.children.push(subInstr);
          }
          break;
        }
        case Opcode.Parameter: {
          if ((cmd & 0xF) === PARAM_EXTENDED) {
            instr = new Instruction(InsnType.Parameter, PARAM_EXTENDED + this.stream.readByte());
          } else {
            instr = new Instruction(InsnType.Parameter, cmd & 0xF);
          }
          break;
        }
        case Opcode.Label: {
          this.readScriptOffset(cmd);
          instr = this.readLabel();
          break;
        }
        case Opcode.Control: {
          this.readScriptOffset(cmd);
          instr = this.readControl();
          break;
        }
        case Opcode.Call: {
          this.readScriptOffset(cmd);
          instr = this.readCall();
          break;
        }
        case Opcode.Block: {
          this.readScriptOffset(cmd);
          instr = new Instruction(InsnType.Block);
          while ((subInstr = this.readInstruction()).insnType !== InsnType.End) {
            instr.children.push(subInstr);
          }
          break;
        }
        case Opcode.Variable: {
          instr = new Instruction(InsnType.Variable, cmd & 0xF);
          break;
        }
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
    if ((cmd & 0xF0) === Opcode.Constant) {
      switch (cmd) {
        case ConstantOp.End: {
          return new Instruction(InsnType.End);
        }
        case DataType.Int16:
        case DataType.UInt24: { // s16 と u24 は VM_DecodeValue の同じ経路(2バイト・符号拡張)、u16 だけがゼロ拡張。
          type = cmd as DataType;
          val = toInt16(this.stream.readByte() | (this.stream.readByte() << 8));
          break;
        }
        case DataType.UInt8:
        case DataType.UInt8_0x03:
        case DataType.Bool: {
          type = cmd as DataType;
          val = this.stream.readByte();
          break;
        }
        case DataType.UInt16: {
          type = cmd as DataType;
          val = this.stream.readByte() | (this.stream.readByte() << 8);
          break;
        }
        case DataType.Int32:
        case DataType.Int32_0x0A:
        case DataType.Int32_0x0D: {
          type = cmd as DataType;
          val = this.stream.readByte() | (this.stream.readByte() << 8) | (this.stream.readByte() << 16) | (this.stream.readByte() << 24);
          break;
        }
        case ConstantOp.String: { // String: 長さ1バイト + その長さ分のバイト列(VM_DecodeValue は pc + pc[0] + 1 進める)
          const len = this.stream.readByte();
          const bytes = new Uint8Array(len);
          for (let i = 0; i < len; i++) bytes[i] = this.stream.readByte();
          const str = new Instruction(InsnType.String);
          str.bytes = bytes;
          return str;
        }
        case ConstantOp.StringRef: { // StringRef: 2バイトの文字列ID(Textbox_LookupString に渡される)
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
    if (cmd !== instr.defaultConstantOpcode()) {
      instr.hasForcedOpcode = true;
      instr.forcedOpcode = cmd;
    }
    return instr;
  }

  protected readMemory(cmd: number): Instruction {
    const regByte = this.stream.readByte();
    const base = memRegionOf(regByte & 0xF0);

    // 領域バイトの下位ニブルは Bool のときだけ意味を持ち、ビット番号(0-7)を表す。他の型では常に 0。
    // アドレスはビッグエンディアンのバイトオフセット。
    const bitIndex = regByte & 0xF;
    const addr = base + ((this.stream.readByte() << 8) | this.stream.readByte());

    // メモリ参照では 1 と 6 の動作は同じ(どちらも16bit・ストライド2)だが、タグとしては別物なので型も分けて保持する。
    const dataType = dataTypeOfTag(cmd & 0xF) ?? DataType.Void;

    const instr = new Instruction();
    instr.dataType = dataType;
    instr.value = addr;
    instr.memRegionBase = base;
    instr.bitIndex = bitIndex;

    if ((cmd & 0xF0) === Opcode.MemoryIndexed) {
      instr.insnType = InsnType.MemoryIndexed;
      instr.children.push(this.readInstruction());
      instr.children.push(this.readInstruction());
    } else {
      instr.insnType = InsnType.Memory;
    }

    if ((regByte & 0xF0) !== memSelectorOf(base)) {
      instr.hasForcedRegion = true;
      instr.forcedRegion = regByte & 0xF0;
    }

    if (dataType !== DataType.Void) {
      if ((cmd & 0xF) !== instr.typeTag()) {
        instr.hasForcedOpcode = true;
        instr.forcedOpcode = cmd & 0xF;
      }
    }

    return instr;
  }

  // ラベルは「1文字 + 本体」。本体に何が何個入るかは呼び出し先のエンジン関数次第なので、個数は決め打ちせずコンテナ長が尽きるまで読む。
  protected readLabel(): Instruction {
    const end = this.containerStart + this.containerLen;
    const instr = new Instruction(InsnType.Label, this.stream.readByte());
    while (this.stream.position < end) {
      instr.children.push(this.readInstruction());
    }
    return instr;
  }

  // 制御命令もラベルと同じで、続く値がいくつ並ぶかは呼び出し先が決める(0xB745 は呼ばれたエンジン関数が自分で VM_GetValue() する)。コンテナ長で読む。
  protected readControl(): Instruction {
    const end = this.containerStart + this.containerLen;
    const tag = this.stream.readByte() | (this.stream.readByte() << 8);
    // 最初のラベルまでのバイト数。構造から導けるので値は使わない。
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
