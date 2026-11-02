#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as MFT from "../encoding/mft/mft.ts";
import * as VM from "../encoding/script/script.ts";

const ID = 0xA41E;

const main = () => {
  new Command()
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .action((_, romPath) => {
      const rom = new DataView((Deno.readFileSync(romPath)).buffer);
      const dir = VM.ParseScriptDirectory(rom, MFT.getFSEntry(rom, ID).ptr);
      console.log("// deno-fmt-ignore-file\n");
      console.log("export const ScriptAddrs = [");
      console.log(`  0x08DA9E60, // 0, SpecialScript`);

      for (let i = 0; i < dir.scripts.length; i++) {
        const script = dir.scripts[i];
        console.log(`  0x${gba.toHex32(script.addr)}, // ID: ${i + 1}(0x${(i + 1).toString(16).toUpperCase()}), Script_0x${gba.toHex16(i + 1)}`);
      }

      console.log("];");
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
