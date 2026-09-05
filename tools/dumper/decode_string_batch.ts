#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { CHARMAP_PATH, decode, findTerminatorSeq, formatByteDump, indexOfSeq, parseCharmap, READ_WINDOW } from "./decode_string.ts";
import * as mft from "../parser/mft.ts";
import { getScriptDirectory } from "../parser/script.ts";
import type { addr } from "../common/gba/gba.ts";

// decode_string.ts のバッチスクリプト (アドレスでなく 文字列ID で指定する)
//
// e.g. decode_string_batch.ts 32 48
//   -> ID 32 から 47 まで(END_ID は含まない)をダンプする
// e.g. decode_string_batch.ts 630
//   -> ID 630 だけをダンプする(END_ID を省略した場合)

const main = () => {
  new Command()
    .name("decode_string_batch.ts")
    .description("tmp/string_addr.txt 由来の文字列アドレスを使って、指定した ID 範囲を decode_string.ts と同じロジックでバッチデコードする。")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .argument("<start:number>", "開始ID。")
    .argument("[end:number]", "終了ID(含まない)。省略時は start + 1。")
    .action((_, romPath, startID, endID) => {
      const endIndex = endID ?? startID + 1;

      const rom = new DataView((Deno.readFileSync(romPath)).buffer);

      const stringAddrs = getScriptDirectory(rom, mft.getMftHeader(rom, 0xA41E).ptr).strings;

      if (!(0 <= startID && startID <= endIndex && endIndex <= stringAddrs.length)) {
        console.error(`error: ID範囲が不正です (0 <= start <= end <= ${stringAddrs.length} である必要があります)`);
        Deno.exit(1);
      }

      const charmap = parseCharmap(CHARMAP_PATH);
      const termSeq = findTerminatorSeq(charmap);

      for (let idx = startID; idx < endIndex; idx++) {
        const addr: addr = stringAddrs[idx];
        const window = new Uint8Array(gba.getSlice(rom, addr, READ_WINDOW));

        const body = decode(window, charmap);
        if (body !== null) {
          console.log(`String_${gba.toHex16(idx)}:: @ 0x${gba.toHex32(addr)}, ID: ${idx}`);
          console.log(`  .string "${body}"`);
          continue;
        }

        const termEnd = indexOfSeq(window, termSeq);
        if (termEnd === -1) {
          console.error(`@ Binary_${gba.toHex16(idx)} @ 0x${gba.toHex32(addr)}, ID: ${idx}: 終端が見つからないためスキップ`);
          continue;
        }

        console.log(`Binary_${gba.toHex16(idx)}:: @ 0x${gba.toHex32(addr)}, ID: ${idx}`);
        console.log(formatByteDump(window.subarray(0, termEnd + termSeq.length)));
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
