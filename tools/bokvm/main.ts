#!/usr/bin/env -S deno run --allow-read --allow-run=arm-none-eabi-cpp

import { Command } from "@cliffy/command";
import { loadProgram, preprocessBokc } from "./loader.ts";
import { describeState, REGIONS } from "./memory.ts";
import { Tracer } from "./trace.ts";
import { BokVM } from "./vm.ts";

// bokvm: ROM のスクリプトを手元で実行する。src/vm.c の VM を TS に移したもの。
//
// e.g. tools/bokvm/main.ts Scr_st00_00
//      tools/bokvm/main.ts 0x010D --args 65
//      tools/bokvm/main.ts Scr_UseKey --args 65 --ret Cmd_HasItem=1 --overlay my.bokc --quiet
//
// ゲーム本体は動かないので, 移植していないコマンドは何もせず 0 を返す (--ret で変えられる)。

const parseNumber = (text: string): number => {
  const n = Number(text.trim());
  if (!Number.isFinite(n)) throw new Error(`数値ではありません: ${text}`);
  return n | 0;
};

// 実行の前後で変わったバイトを, 連続する範囲ごとにまとめて出す
const printStateDiff = (before: Uint8Array, after: Uint8Array): void => {
  const lines: string[] = [];
  for (const r of REGIONS) {
    let i = r.base;
    while (i < r.base + r.size) {
      if (before[i] === after[i]) {
        i++;
        continue;
      }
      const start = i;
      while (i < r.base + r.size && before[i] !== after[i]) i++;
      const hex = (buf: Uint8Array) => [...buf.subarray(start, i)].map((b) => b.toString(16).toUpperCase().padStart(2, "0")).join(" ");
      lines.push(`${describeState(start)}: ${hex(before)} -> ${hex(after)}`);
    }
  }
  console.log(lines.length === 0 ? "メモリの変化なし" : "メモリの変化:\n" + lines.map((l) => "  " + l).join("\n"));
};

const main = () => {
  new Command()
    .name("bokvm")
    .description("ROM のスクリプトを手元で実行して, 実行した文・コマンド・メモリの書き込みを出す。")
    .argument("<script:string>", "実行するスクリプト, script.h の名前 (Scr_st00_00) か Scr_0xXXXX かID")
    .option("--rom <path:string>", "ROM のパス", { default: "baserom.gba" })
    .option("--args <list:string>", "スクリプトに渡す引数 (p0, p1, ...), カンマ区切り, e.g. 65,0x10")
    .option("--ret <spec:string>", "未実装のコマンドが返す値, e.g. Cmd_HasItem=1 (何度でも指定できる)", { collect: true })
    .option("--overlay <path:string>", "差し替える .bokc, 中で定義したスクリプトだけ ROM のものより優先する (何度でも指定できる)", { collect: true })
    .option("--mem <spec:string>", "ゲーム状態の初期値, e.g. world=world.bin (stat / world / scratch, 何度でも指定できる)", { collect: true })
    .option("-q, --quiet", "文を出さず, スクリプトの出入り・コマンド・書き込み・イベントだけを出す")
    .option("--max-steps <n:number>", "この数の文を実行したら止める (無限ループ対策)", { default: 1_000_000 })
    .action((opts, scriptArg) => {
      try {
        const program = loadProgram(opts.rom);
        for (const path of opts.overlay ?? []) {
          const ids = program.addOverlay(preprocessBokc(path));
          console.log(`overlay ${path}: ${ids.map((id) => "0x" + id.toString(16).toUpperCase().padStart(4, "0")).join(", ")}`);
        }

        const trace = new Tracer(program);
        trace.statements = !opts.quiet;
        const vm = new BokVM(program, trace);
        vm.maxSteps = opts.maxSteps;

        for (const spec of opts.ret ?? []) {
          const [name, value] = spec.split("=");
          if (value === undefined) throw new Error(`--ret は 名前=値 の形で指定してください: ${spec}`);
          vm.commandResults.set(name.trim(), parseNumber(value));
        }

        for (const spec of opts.mem ?? []) {
          const [name, path] = spec.split("=");
          const region = REGIONS.find((r) => r.name === name);
          if (region === undefined || path === undefined) throw new Error(`--mem は stat=... / world=... / scratch=... の形で指定してください: ${spec}`);
          const data = Deno.readFileSync(path);
          program.memory.state.set(data.subarray(0, region.size), region.base);
        }

        const id = program.resolveScript(scriptArg);
        const argv = opts.args ? opts.args.split(",").map(parseNumber) : [];
        const before = program.memory.state.slice();

        let failed = false;
        try {
          vm.execByID(id, { argc: argv.length, argv });
        } catch (e) {
          failed = true;
          console.log(`!! 実行を中断しました: ${e instanceof Error ? e.message : String(e)}`);
        }

        console.log("");
        console.log(`result = ${vm.result}, ${vm.steps} 文`);
        printStateDiff(before, program.memory.state);
        if (trace.warnings.length > 0) console.log(`警告 ${trace.warnings.length} 件`);
        if (failed) Deno.exit(1);
      } catch (e) {
        console.error(e instanceof Error ? e.message : String(e));
        Deno.exit(1);
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
