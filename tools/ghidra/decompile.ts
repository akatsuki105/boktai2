#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net --allow-env

import { Command } from "@cliffy/command";
import { decompileFunction } from "./api/function.ts";
import { resolveAddress } from "./common.ts";

// e.g. tools/ghidra/decompile.ts LevelUpper_Destroy
// e.g. tools/ghidra/decompile.ts 0x080A869C
const main = () => {
  new Command()
    .name("decompile.ts")
    .description("GhidraでデコンパイルされたCコードを取得する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "Function name or ROM address")
    .option("--timeout <sec:number>", "デコンパイルのタイムアウト(秒)。省略時は decompileFunction のデフォルト値。")
    .action(async (opts, target) => {
      const addr = resolveAddress(target);
      try {
        console.log(await decompileFunction(addr, opts.timeout));
      } catch (e) {
        console.error(`エラー: ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
