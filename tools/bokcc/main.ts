#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from "@cliffy/command";
import { ByteStream, InstructionReader } from "./instruction_reader.ts";
import { parseAll } from "./parser.ts";
import { compile as compileScript } from "./compiler.ts";
import { buildPrintContext, INCLUDE_DIR } from "./print_context.ts";
import * as gba from "../common/gba/gba.ts";

// コンパイル・デコンパイル両方のエントリポイント。bokcc の CLI。

// bokcc/main.ts decompile baserom.gba 0x08D13428
// ROM上のスクリプト1つを対象にする。 ROMの全スクリプトを .bokc に書き出すのは tools/dumper/bokcc.ts 側 の役割。
const decompile = new Command()
  .description("バイトコードをデコンパイルして出力する")
  .argument("<rom:string>", "Path to a GBA ROM file.")
  .argument("<addr:number>", "Script address in the ROM.")
  .option("--strings <include:string>", `文字列IDの名前を定義したヘッダ, #include に書く綴りで指定する (${INCLUDE_DIR}/ 配下から読む)`)
  .action((opts, romPath, targetAddr) => {
    const offset = (targetAddr >= gba.BASE) ? targetAddr - gba.BASE : targetAddr; // 0x08000000 以降のアドレスが指定された場合はファイルオフセットに変換する
    const data = Deno.readFileSync(romPath);
    const reader = new InstructionReader(new ByteStream(data, offset));

    try {
      const ctx = buildPrintContext({ strings: opts.strings });
      for (const instr of reader.decompile()) {
        console.log(instr.toString(ctx));
      }
    } catch (e) {
      console.error(e instanceof Error ? e.message : String(e));
      Deno.exit(1);
    }
  });

// bokcc/main.ts compile script.bokc -o out.bin
const compile = new Command()
  .description("bokccのスクリプトコードをコンパイルしてバイト列を出力する")
  .argument("[input:string]", "入力ファイルのパス, 複数のスクリプトが連結されていてもよい")
  .option("--stdin", "read from stdin")
  .option("-o, --output [output:string]", "出力ファイルのパス, -S と併用不可")
  .option("-S, --stdout", "バイナリファイルの代わりに16進テキストとして書き出す, デバッグ用, -o と併用不可")
  .action(async (opts, inputPath) => {
    if (opts.stdout && opts.output) {
      console.error("-S と -o は併用できません");
      Deno.exit(1);
    }
    if (!opts.stdout && !opts.output) {
      console.error("出力先が指定されていません");
      Deno.exit(1);
    }

    let src: string;
    if (opts.stdin || inputPath === "-") {
      src = await new Response(Deno.stdin.readable).text();
    } else {
      if (!inputPath) {
        console.error("入力ファイルが指定されていません");
        Deno.exit(1);
      }
      src = Deno.readTextFileSync(inputPath);
    }

    try {
      // 複数のスクリプトはROM上と同じく隙間なく連結する
      const chunks = parseAll(src).map(compileScript);

      if (opts.stdout) {
        // スクリプトごとに1行(連結して1行にすると境目が分からなくなるため)
        for (const bytes of chunks) {
          console.log(Array.from(bytes, (b) => b.toString(16).toUpperCase().padStart(2, "0")).join(" "));
        }
      } else {
        const total = chunks.reduce((n, c) => n + c.length, 0);
        const out = new Uint8Array(total);
        let at = 0;
        for (const c of chunks) {
          out.set(c, at);
          at += c.length;
        }
        Deno.writeFileSync(opts.output as string, out);
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
    .command("compile", compile)
    .parse(Deno.args);
};

if (import.meta.main) main();
