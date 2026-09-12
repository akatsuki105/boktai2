#!/usr/bin/env -S deno run --allow-read --allow-write --allow-net --allow-env

import { Command } from "@cliffy/command";
import { basename, join } from "@std/path";
import { BASE_URL } from "./common.ts";

// Python(PyGhidra) の GhidraScript を、起動中の GUI の Ghidra 上で実行する (GhidraMCP の /run_ghidra_script)。
// /run_ghidra_script は ~/ghidra_scripts にあるファイルを名前で実行するので、
// スクリプトをそこに一時ファイルとしてコピーしてから実行し、終わったら消す。
// スクリプトの出力部分だけを表示し、実行時例外のときは応答全体を表示して終了コード 1 を返す。
//
// e.g. tools/ghidra/run_pyghidra_script.ts tools/ghidra/ghidra_scripts/custom_string.py
// e.g. tools/ghidra/run_pyghidra_script.ts foo.py 0x08241298 16

// 一時ファイルの .pyc も PyGhidra が __pycache__ に作るので、自分が作ったものだけ消す。
// それで __pycache__ が空になったらディレクトリも消す(空でなければ Deno.remove が失敗するので他のファイルは消えない)。
const removePycache = (dir: string, stem: string) => {
  const cacheDir = join(dir, "__pycache__");
  try {
    for (const e of Deno.readDirSync(cacheDir)) {
      if (e.isFile && e.name.startsWith(`${stem}.`)) Deno.removeSync(join(cacheDir, e.name));
    }
    Deno.removeSync(cacheDir);
  } catch {
    // __pycache__ が無い、または他のファイルが残っていて消せなければ何もしない
  }
};

const main = () => {
  new Command()
    .name("run_pyghidra_script.ts")
    .description("Python(PyGhidra) の GhidraScript を GUI の Ghidra 上で実行し、出力を表示する。")
    .argument("<script:string>", "実行する .py ファイル。")
    .argument("[args...:string]", "スクリプトに渡す引数。getScriptArgs() で受け取る。")
    .option("--timeout <sec:number>", "タイムアウト(秒)。関数を全走査するスクリプトは時間がかかる。", { default: 600 })
    .option("--raw", "サーバーの応答をそのまま表示する。")
    .action(async (opts, script, ...args) => {
      const scriptDir = join(Deno.env.get("HOME") ?? "", "ghidra_scripts");
      Deno.mkdirSync(scriptDir, { recursive: true });

      // 同時に複数実行しても衝突しないよう、時刻を付けた名前にする
      const stem = `tmp_${basename(script, ".py").replace(/\W/g, "_")}_${Date.now()}`;
      const tmpPath = join(scriptDir, `${stem}.py`);
      Deno.copyFileSync(script, tmpPath);

      let text = "";
      let ok = false;
      try {
        const res = await fetch(`${BASE_URL}/run_ghidra_script`, {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ script_name: `${stem}.py`, args: args.join(" "), timeout_seconds: opts.timeout }),
          signal: AbortSignal.timeout((opts.timeout + 10) * 1000),
        });
        text = await res.text();
        ok = res.ok;
      } catch (e) {
        console.error(`エラー: ${BASE_URL} に接続できません(Ghidra は起動していますか?)`);
        console.error(`  ${e instanceof Error ? e.message : String(e)}`);
      } finally {
        try {
          Deno.removeSync(tmpPath);
        } catch {
          // 既に無ければ何もしない
        }
        removePycache(scriptDir, stem);
      }
      if (!text) Deno.exit(1);

      if (opts.raw) {
        console.log(text);
        return;
      }

      let success = false;
      let output = text;
      try {
        const json = JSON.parse(text);
        success = json.success === true;
        output = json.console_output ?? json.error ?? text;
      } catch {
        // JSON でなければ応答全体をそのまま扱う
      }
      // Python の例外はサーバー側で拾われて "SCRIPT COMPLETED SUCCESSFULLY" になるので Traceback でも判定する
      const failed = !ok || !success || output.includes("SCRIPT EXECUTION ERROR") || output.includes("Traceback (most recent call last)") ||
        !output.includes("SCRIPT COMPLETED SUCCESSFULLY");
      const body = failed ? output : (output.split("--- SCRIPT OUTPUT ---")[1] ?? output).replace(/=== SCRIPT COMPLETED SUCCESSFULLY ===\s*$/, "");
      console.log(body.trim());
      if (failed) Deno.exit(1);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
