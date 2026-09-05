#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from "@cliffy/command";
import { ByteStream, InstructionReader } from "./instruction_reader.ts";
import { parseAll } from "./parser.ts";
import { compile } from "./compiler.ts";
import * as gba from "../common/gba/gba.ts";

// bokcc/main.ts decompile baserom.gba 0x08D13428
const decompile = new Command()
  .description("バイトコードをデコンパイルして出力する。")
  .arguments("<rom:string> <addr:number>")
  .action((_, romPath, targetAddr) => {
    const offset = (targetAddr >= gba.BASE) ? targetAddr - gba.BASE : targetAddr; // 0x08000000 以降のアドレスが指定された場合はファイルオフセットに変換する
    const data = Deno.readFileSync(romPath);
    const reader = new InstructionReader(new ByteStream(data, offset));

    try {
      for (const instr of reader.decompile()) {
        console.log(instr.toString());
      }
    } catch (e) {
      console.error(e instanceof Error ? e.message : String(e));
      Deno.exit(1);
    }
  });

// bokcc/main.ts compile script.bokcc [--bin out.bin]
const compileCmd = new Command()
  .description("bokccのスクリプトコードをコンパイルしてバイト列を出力する。入力には複数のスクリプトを並べてよい。")
  .arguments("<input:string>")
  .option("--bin <output:string>", "16進テキストの代わりにバイナリファイルとして書き出す。")
  .action((opts, inputPath) => {
    const src = Deno.readTextFileSync(inputPath);

    try {
      // 複数のスクリプトはROM上と同じく隙間なく連結する
      const chunks = parseAll(src).map(compile);
      if (opts.bin) {
        const total = chunks.reduce((n, c) => n + c.length, 0);
        const out = new Uint8Array(total);
        let at = 0;
        for (const c of chunks) {
          out.set(c, at);
          at += c.length;
        }
        Deno.writeFileSync(opts.bin, out);
      } else {
        // スクリプトごとに1行(連結して1行にすると境目が分からなくなるため)
        for (const bytes of chunks) {
          console.log(Array.from(bytes, (b) => b.toString(16).toUpperCase().padStart(2, "0")).join(" "));
        }
      }
    } catch (e) {
      console.error(e instanceof Error ? e.message : String(e));
      Deno.exit(1);
    }
  });

const main = () => {
  new Command()
    .name("main.ts")
    .description("bokcc: boktai2バイトコードのデコンパイラ/コンパイラ。")
    .command("decompile", decompile)
    .command("compile", compileCmd)
    .parse(Deno.args);
};

if (import.meta.main) main();
