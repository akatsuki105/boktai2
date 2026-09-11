#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { ARM_REGISTERS, Register } from "./arm_registers.ts";
import { ghidraGet, resolveAddress, symbolsByAddress } from "./common.ts";

type Varnode = { space: string; offset: string; size: number };
type PcodeOp = { mnemonic: string; seq: { address: string }; inputs: Varnode[]; output?: Varnode };
type BasicBlock = { start: { address: string }; stop: { address: string }; pcodes: PcodeOp[] };
type PcodeResponse = { name: string; address: string; basic_blocks: BasicBlock[]; high_pcodes?: PcodeOp[] };

// 分岐先(コードアドレス)を第0入力に取る命令。ram 空間の生アドレスではなくラベルとして出す。
const BRANCH_OPS = new Set(["BRANCH", "CBRANCH", "BRANCHIND", "CALL", "CALLIND"]);

class Formatter {
  // (レジスタ空間のオフセット, バイト数) -> レジスタ名
  private regs = new Map<string, string>();
  private syms = symbolsByAddress();
  private blockStarts = new Map<number, number>(); // アドレス -> ブロック番号

  constructor(registers: Register[], blocks: BasicBlock[]) {
    for (const r of registers) this.regs.set(`${r.offset}:${r.size}`, r.name);
    blocks.forEach((b, i) => this.blockStarts.set(parseInt(b.start.address, 16), i));
  }

  private register(off: number, size: number): string {
    const exact = this.regs.get(`${off}:${size}`);
    if (exact) return exact;
    // サイズ違い(サブレジスタなど)は同じオフセットの32bitレジスタ名にサイズを添えて出す
    const parent = this.regs.get(`${off}:4`);
    return parent ? `${parent}:${size}` : `reg[${gba.toHex32(off)}:${size}]`;
  }

  // コードアドレスはシンボル名 → 同一関数内のブロック番号 → 生アドレス の順で名前を付ける
  private codeAddress(off: number): string {
    const sym = this.syms.get(off);
    if (sym) return sym;
    const block = this.blockStarts.get(off);
    if (block !== undefined) return `block${block}`;
    return `0x${gba.toHex32(off)}`;
  }

  varnode(v: Varnode | undefined, asCodeAddress = false): string {
    if (!v) return "?";
    const off = parseInt(v.offset, 16);
    switch (v.space) {
      case "register": {
        return this.register(off, v.size);
      }
      case "const": {
        return `#0x${off.toString(16).toUpperCase()}`;
      }
      case "unique": {
        return `u${off.toString(16)}`;
      }
      case "ram": {
        if (asCodeAddress) return this.codeAddress(off);
        const sym = this.syms.get(off);
        return sym ? `${sym}:${v.size}` : `ram[0x${gba.toHex32(off)}:${v.size}]`;
      }
      default: {
        return `${v.space}[0x${off.toString(16)}:${v.size}]`;
      }
    }
  }

  op(op: PcodeOp): string {
    const isBranch = BRANCH_OPS.has(op.mnemonic);
    const ins = op.inputs.map((v, i) => this.varnode(v, isBranch && i === 0)).join(", ");
    const lhs = op.output ? `${this.varnode(op.output)} = ` : "";
    return `${op.seq.address}  ${lhs}${op.mnemonic}(${ins})`;
  }
}

const render = (d: PcodeResponse, registers: Register[], high: boolean): string => {
  const fmt = new Formatter(registers, d.basic_blocks);
  const lines: string[] = [`${d.name} @ ${d.address}  basic_blocks=${d.basic_blocks.length}`];

  d.basic_blocks.forEach((b, i) => {
    lines.push("", `--- block${i}: ${b.start.address} .. ${b.stop.address}`);
    for (const op of b.pcodes) lines.push(`  ${fmt.op(op)}`);
  });

  // granularity=high のときだけ付いてくる HighFunction 側の op 列
  if (high && d.high_pcodes) {
    lines.push("", `--- high_pcodes (${d.high_pcodes.length})`);
    for (const op of d.high_pcodes) lines.push(`  ${fmt.op(op)}`);
  }
  return lines.join("\n");
};

// e.g. tools/ghidra/pcode.ts LevelUpper_Destroy
// e.g. tools/ghidra/pcode.ts 0x080A869C --granularity high
const main = () => {
  new Command()
    .name("pcode.ts")
    .description("関数のP-codeを取得して読みやすく整形する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "Function name or ROM address")
    .option("--granularity <level:string>", "'basic'(基本ブロックのみ) または 'high'(HighFunction込み)。", { default: "basic" })
    .option("--json", "整形せず生のJSONを出力する。")
    .option("--timeout <sec:number>", "タイムアウト(秒)。", { default: 60 })
    .action(async (opts, target) => {
      const addr = resolveAddress(target);
      const raw = await ghidraGet("get_function_pcode", { function_address: `0x${gba.toHex32(addr)}`, granularity: opts.granularity }, opts.timeout);
      if (opts.json) {
        console.log(raw);
        return;
      }
      console.log(render(JSON.parse(raw) as PcodeResponse, ARM_REGISTERS, opts.granularity === "high"));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
