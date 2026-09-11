#!/usr/bin/env -S deno run --allow-read --allow-net --allow-env

import { Command } from "@cliffy/command";

// Java の GhidraScript を、起動中の GUI の Ghidra 上で実行する (GhidraMCP の /run_script_inline)。
// スクリプトの出力部分だけを表示し、ビルド失敗・実行時例外のときは応答全体を表示して終了コード 1 を返す。
//
// e.g. .claude/skills/ghidra-struct/scripts/run_ghidra_script.ts .claude/skills/ghidra-struct/scripts/TypeUsers.java FreezeEffect
// e.g. .claude/skills/ghidra-struct/scripts/run_ghidra_script.ts .claude/skills/ghidra-struct/scripts/StructCandidates.java 44 Particle

const BASE_URL = Deno.env.get("GHIDRA_MCP_URL") ?? "http://127.0.0.1:8089";

// 以前にビルドに失敗した別のスクリプトのエラーが、ファイルを消した後も毎回出力に混ざる。
// 実行したスクリプト自身に関係しないものは取り除く。
const stripStaleBuildNote = (text: string, className: string): string => {
  const lines = text.split("\n");
  const out: string[] = [];
  for (let i = 0; i < lines.length; i++) {
    if (lines[i].includes("hasn't changed, with") && lines[i].includes("failing in previous build")) {
      let j = i + 1;
      while (j < lines.length && lines[j].trim() !== "") j++;
      if (lines.slice(i, j).some((l) => l.includes(`${className}.java`))) out.push(...lines.slice(i, j));
      i = j;
      continue;
    }
    out.push(lines[i]);
  }
  return out.join("\n");
};

const main = () => {
  new Command()
    .name("run_ghidra_script.ts")
    .description("Java の GhidraScript を GUI の Ghidra 上で実行し、出力を表示する。")
    .argument("<script:string>", "実行する .java ファイル。クラス名がそのまま ~/ghidra_scripts 内のファイル名になる。")
    .argument("[args...:string]", "スクリプトに渡す引数。getScriptArgs() で受け取る。")
    .option("--timeout <sec:number>", "タイムアウト(秒)。関数を全走査するスクリプトは時間がかかる。", { default: 600 })
    .option("--raw", "サーバーの応答をそのまま表示する。")
    .action(async (opts, script, ...args) => {
      const code = await Deno.readTextFile(script);
      const className = code.match(/public\s+class\s+(\w+)/)?.[1] ?? "";
      let res: Response;
      try {
        res = await fetch(`${BASE_URL}/run_script_inline`, {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ code, args: args.join(" ") }),
          signal: AbortSignal.timeout(opts.timeout * 1000),
        });
      } catch (e) {
        console.error(`エラー: ${BASE_URL} に接続できません(Ghidra は起動していますか?)`);
        console.error(`  ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }
      const text = await res.text();
      if (opts.raw) {
        console.log(text);
        return;
      }
      const failed = !res.ok || text.includes("SCRIPT EXECUTION ERROR") || !text.includes("SCRIPT COMPLETED SUCCESSFULLY") ||
        new RegExp(`${className}\\.java:\\d+: error`).test(text);
      const body = failed ? text : (text.split("--- SCRIPT OUTPUT ---")[1] ?? text).replace(/=== SCRIPT COMPLETED SUCCESSFULLY ===\s*$/, "");
      console.log(stripStaleBuildNote(body, className).trim());
      if (failed) Deno.exit(1);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
