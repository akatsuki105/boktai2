#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import * as path from "@std/path";

const main = () => {
  new Command()
    .name("array_s16.ts")
    .description("Dump s16[length]")
    .argument("<input:string>", "Path to the input binary file.")
    .argument("<start:number>", "Start offset.")
    .argument("<length:number>", "Number of s16 elements to read.")
    .action((_, inputPath, startOffset, length) => {
      if (path.extname(inputPath) === ".gba") { // 拡張子が .gba の場合は ROMアドレスも受け入れる
        if (startOffset >= gba.BASE) startOffset -= gba.BASE;
      }
      const input = new DataView(Deno.readFileSync(inputPath).buffer);
      const result: number[] = [];
      for (let i = 0; i < length; i++) {
        const offset = startOffset + i * 2;
        const value = input.getInt16(offset, true);
        result.push(value);
      }
      console.log(result);
    })
    .parse(Deno.args);
};

main();
