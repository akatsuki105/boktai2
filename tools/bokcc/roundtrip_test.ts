// ROMからデコンパイルした bokcc コードを bokcc でコンパイルし、元のROMバイト列と一致するかを検証する。
//
// デコンパイル→コンパイルが自己循環するだけでは不十分で、必ず ROM の実バイト列と比較すること(デコンパイル結果とコンパイル結果を突き合わせるだけだと、両方が同じように間違っていても気づけないため)。
import { fail } from "@std/assert";

import { ByteStream, InstructionReader } from "./instruction_reader.ts";
import { InsnType } from "./instruction.ts";
import { parse } from "./parser.ts";
import { compile } from "./compiler.ts";
import * as gba from "../common/gba/gba.ts";
import { getScriptDirectory } from "../parser/script.ts";
import * as mft from "../parser/mft.ts";
import type { addr } from "../common/gba/gba.ts";

const romBytes = Deno.readFileSync(new URL("../../baserom.gba", import.meta.url));
const rom = new DataView(romBytes.buffer);
const dir = getScriptDirectory(rom, mft.getMftHeader(rom, 0xA41E).ptr);

const getScriptAddr = (scriptId: number): addr => {
  if (scriptId < 1 || scriptId > dir.scripts.length) {
    throw new Error(`Invalid script ID: ${scriptId}`);
  }
  return dir.scripts[scriptId - 1];
};

const alreadyTested = new Set<addr>();

const hex = (bytes: Uint8Array, from: number, count = 12): string => [...bytes.subarray(from, from + count)].map((b) => b.toString(16).toUpperCase().padStart(2, "0")).join(" ");

// 往復できなければ理由を返す(できたなら null)。
const roundtripFailure = (addr: addr): string | null => {
  const offset = addr - gba.BASE;

  const stream = new ByteStream(romBytes, offset);
  const instr = new InstructionReader(stream).readInstruction();
  if (instr.insnType !== InsnType.Block) {
    return `expected a top-level Block, got InsnType ${InsnType[instr.insnType]}`;
  }
  const end = stream.position;

  const decompiled = instr.toString();
  const recompiled = compile(parse(decompiled));

  const original = romBytes.subarray(offset, end);
  if (recompiled.length === original.length && recompiled.every((b, i) => b === original[i])) {
    if (!alreadyTested.has(addr)) {
      // console.log(`Script at offset ${offset} round-tripped successfully. .bytes[0]: ${gba.toHex8(recompiled[0])}`);
      alreadyTested.add(addr);
    }
    return null;
  }

  // 最初に食い違ったバイトの周辺を出す(全部並べても読めないため)
  let i = 0;
  while (i < Math.min(recompiled.length, original.length) && recompiled[i] === original[i]) i++;
  const from = Math.max(0, i - 4);
  return `bytes differ at offset ${i} (length ${original.length} -> ${recompiled.length})\n` +
    `      ROM: ${hex(original, from)}\n` +
    `      out: ${hex(recompiled, from)}`;
};

Deno.test("round-trip: 全スクリプト", () => {
  const failures: string[] = [];
  for (let id = 1; id <= dir.scripts.length; id++) {
    let reason: string | null;
    try {
      reason = roundtripFailure(getScriptAddr(id));
    } catch (e) {
      reason = e instanceof Error ? e.message : String(e);
    }
    if (reason !== null) {
      failures.push(`  Script_${String(id).padStart(4, "0")}: ${reason}`);
    }
  }
  if (failures.length > 0) {
    const shown = failures.slice(0, 10).join("\n");
    fail(
      `${failures.length} / ${dir.scripts.length} scripts failed to round-trip:\n${shown}` +
        (failures.length > 10 ? `\n  ... and ${failures.length - 10} more` : ""),
    );
  }
});
