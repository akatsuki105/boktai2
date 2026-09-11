#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from "@cliffy/command";
import * as path from "@std/path";
import * as gba from "./common/gba/gba.ts";

const main = () => {
  new Command()
    .name("bin.ts")
    .description("開始オフセット から 終端オフセット(end-1)まで、 バイナリファイルとして ダンプします。")
    .argument("<input:string>", "Path to the input binary file.")
    .argument("<start:number>", "Start offset.")
    .argument("<end:number>", "End offset (exclusive).")
    .argument("<output:string>", "Path to the output binary file.")
    .action((_, inputPath, startOffset, endOffset, outputPath) => {
      if (path.extname(inputPath) === ".gba") { // 拡張子が .gba の場合は ROMアドレスも受け入れる
        if (startOffset >= gba.BASE) startOffset -= gba.BASE;
        if (endOffset >= gba.BASE) endOffset -= gba.BASE;
      }
      const input = Deno.readFileSync(inputPath);
      const slice = input.subarray(startOffset, endOffset);
      Deno.writeFileSync(outputPath, slice);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
