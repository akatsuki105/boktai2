import { ByteStream, InstructionReader } from "../bokcc/instruction_reader.ts";
import { InsnType, Instruction } from "../bokcc/instruction.ts";
import type { Program } from "./loader.ts";

// 実行ログ。ブロックの入れ子の深さでインデントして標準出力に書く。
// statements を切ると文そのものは出さず, スクリプトの出入り・コマンド・書き込み・イベントだけを出す。

export class Tracer {
  depth = 0;
  statements = true;
  private readonly program: Program;
  readonly warnings: string[] = [];
  out: (line: string) => void = (line) => console.log(line);

  constructor(program: Program) {
    this.program = program;
  }

  private line(text: string): void {
    this.out("  ".repeat(this.depth) + text);
  }

  // pc にある文を .bokc の綴りで1行にする (if / switch は見出しの行だけ)
  statementText(pc: number): string {
    try {
      const { bytes, offset } = this.program.memory.segmentOf(pc);
      const instr = new InstructionReader(new ByteStream(bytes, offset)).readInstruction();
      const block = new Instruction(InsnType.Block);
      block.children.push(instr);
      const lines = block.toString(this.program.ctx).split("\n");
      return (lines[1] ?? "").trim();
    } catch (e) {
      return `<デコードできません: ${e instanceof Error ? e.message : String(e)}>`;
    }
  }

  statement(pc: number): void {
    if (this.statements) this.line(this.statementText(pc));
  }

  // 文とは別に結果を書くもの (if の分岐先, switch の一致した節, コマンドの戻り値など)
  note(text: string): void {
    this.line("// " + text);
  }

  // 文を出していないときでも出すもの
  event(text: string): void {
    this.line(text);
  }

  warn(text: string): void {
    this.warnings.push(text);
    this.line("!! " + text);
  }
}
