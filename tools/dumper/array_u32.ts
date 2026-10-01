#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import * as path from "@std/path";

const main = () => {
  new Command()
    .name("array_u32.ts")
    .description("Dump u32[length]")
    .argument("<input:string>", "Path to the input binary file.")
    .argument("<start:number>", "Start offset.")
    .argument("<length:number>", "Number of u32 elements to read.")
    .option("--hex", "Output the result in hexadecimal format.")
    .action((opts, inputPath, startOffset, length) => {
      if (path.extname(inputPath) === ".gba") { // 拡張子が .gba の場合は ROMアドレスも受け入れる
        if (startOffset >= gba.BASE) startOffset -= gba.BASE;
      }
      const input = new DataView(Deno.readFileSync(inputPath).buffer);
      const result: number[] = [];
      for (let i = 0; i < length; i++) {
        const offset = startOffset + i * 4;
        const value = input.getUint32(offset, true);
        result.push(value);
      }
      for (let i = 0; i < result.length; i++) {
        const comma = (i < result.length - 1) ? "," : "";
        if (opts.hex) {
          console.log("0x" + result[i].toString(16).toUpperCase() + comma);
        } else {
          console.log(result[i] + comma);
        }
      }
    })
    .parse(Deno.args);
};

main();
