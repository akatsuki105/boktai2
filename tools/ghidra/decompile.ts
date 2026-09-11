#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { ghidraGet, resolveAddress } from "./common.ts";

// e.g. tools/ghidra/decompile.ts LevelUpper_Destroy
// e.g. tools/ghidra/decompile.ts 0x080A869C
const main = () => {
  new Command()
    .name("decompile.ts")
    .description("GhidraでデコンパイルされたCコードを取得する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "Function name or ROM address")
    .option("--timeout <sec:number>", "デコンパイルのタイムアウト(秒)。", { default: 45 })
    .action(async (opts, target) => {
      const addr = resolveAddress(target);
      console.log(await ghidraGet("decompile_function", { address: gba.toHex32(addr) }, opts.timeout));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
