#!/usr/bin/env -S deno run --allow-net --allow-env

import { Command } from "@cliffy/command";

// 関数を Ghidra でデコンパイルし、構造体のフィールドに解決されずに残っている生のオフセットアクセスを数える。
// 型を当てた後の検証に使う。残りが 0 行なら、その関数から見える範囲のアクセスはすべて型で説明できている。
//
// e.g. .claude/skills/ghidra-struct/scripts/check_decomp.ts FreezeEffect_Init 0x080a7b80
// e.g. .claude/skills/ghidra-struct/scripts/check_decomp.ts --quiet 0x080a7b80 0x080a7c64

const BASE_URL = Deno.env.get("GHIDRA_MCP_URL") ?? "http://127.0.0.1:8089";

// 生のオフセットアクセスとみなす書き方
const RAW_PATTERNS: RegExp[] = [
  /\bfield\d*_0x[0-9a-f]+/, // 型の未定義部分へのアクセス (field_0x10, field12_0x18)
  /\(int\)[A-Za-z_]\w* \+ (0x[0-9a-f]+|\d+)\)/, // *(T *)((int)p + 0x10)
  /\bparam_\d+ \+ (0x[0-9a-f]+|\d+)\b/, // 型の付いていない引数からのオフセット
  /(?<![>.\w])[A-Za-z_]\w*\[0x[0-9a-f]+\]\.\w+/, // 大きい構造体を小さい型の配列として読んでいる (p[0x46].onDelete)
];

const main = () => {
  new Command()
    .name("check_decomp.ts")
    .description("関数をデコンパイルし、フィールドに解決されていない生のオフセットアクセスを数える。")
    .argument("<functions...:string>", "関数名、または 0x で始まるアドレス。")
    .option("--quiet", "デコンパイル結果を表示せず、残っている行と件数だけを表示する。")
    .option("--timeout <sec:number>", "1 関数あたりのデコンパイルのタイムアウト(秒)。", { default: 120 })
    .action(async (opts, ...funcs) => {
      let total = 0;
      for (const f of funcs) {
        const url = `${BASE_URL}/decompile_function?${new URLSearchParams({ address: f, timeout: String(opts.timeout) })}`;
        let text: string;
        try {
          const res = await fetch(url, { signal: AbortSignal.timeout((opts.timeout + 30) * 1000) });
          text = await res.text();
        } catch (e) {
          console.error(`エラー: ${BASE_URL} に接続できません(Ghidra は起動していますか?)`);
          console.error(`  ${e instanceof Error ? e.message : String(e)}`);
          Deno.exit(1);
        }
        if (text.trimStart().startsWith("{\"error\"")) {
          console.log(`--- ${f}: デコンパイル失敗 ${text.trim()}`);
          continue;
        }
        const hits = text.split("\n").map((line, i) => ({ line, no: i + 1 })).filter(({ line }) => RAW_PATTERNS.some((r) => r.test(line)));
        total += hits.length;
        if (!opts.quiet) console.log(`===== ${f} =====\n${text.trim()}\n`);
        console.log(`--- ${f}: 生オフセット ${hits.length} 行`);
        for (const { line, no } of hits) console.log(`  ${no}: ${line.trim()}`);
      }
      console.log(`\n合計 ${total} 行`);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
