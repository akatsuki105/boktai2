#!/usr/bin/env -S deno run --allow-read --allow-net --allow-env

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { auditGlobal, renameData } from "./api/data.ts";
import { saveProgram } from "./api/program.ts";
import { resolveTarget } from "./common.ts";

// Ghidra 側のグローバル変数 (IWRAM/EWRAM など) をリネームして保存する。GUIのGhidraが起動している必要がある。
// GhidraMCP の Strict Naming Enforcement (Edit > Tool Options > GhidraMCP HTTP Server) をオフにしておくこと。
// オンのままだと g_ 接頭辞のない名前が拒否される。
//
// rename_data は dry_run を読まない (GhidraMCP-6.0.0 で確認) ので、
// 実行してから audit_global で前後を比べ、名前以外が変わっていないことを確かめてから保存する。
//
// e.g. tools/ghidra/rename_global.ts 0x03003530 gSpriteListIdx
// e.g. tools/ghidra/rename_global.ts u32_03003530 gSpriteListIdx

const main = () => {
  new Command()
    .name("rename_global.ts")
    .description("Ghidra 側のグローバル変数をリネームして保存する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "リネームするグローバルのシンボル名またはアドレス (0x03003530 など)")
    .argument("<newName:string>", "新しいシンボル名")
    .option("--no-save", "リネーム後に save_program を実行しない。")
    .action(async (opts, target, newName) => {
      try {
        const addr = await resolveTarget(target);
        if (addr === undefined) {
          console.error(`エラー: '${target}' をアドレスに解決できません`);
          Deno.exit(1);
        }

        const before = await auditGlobal(addr);
        if (before.name === newName) {
          console.log(`${gba.toHex32(addr)} は既に '${newName}' です (変更なし)`);
          return;
        }

        const res = await renameData(addr, newName);
        for (const w of res.warnings) console.warn(`警告: ${w}`);

        // 名前以外が変わっていないか確かめる
        const after = await auditGlobal(addr);
        if (after.name !== newName) {
          console.error(`エラー: 名前が '${after.name}' になりました (指定は '${newName}')。`);
          console.error("Strict Naming Enforcement が有効に戻っている可能性があります。保存はしていません。");
          Deno.exit(1);
        }
        if (after.address !== before.address || after.type !== before.type || after.length !== before.length) {
          console.error("エラー: 名前以外も変わりました。保存はしていません。Ghidra 上で確認してください。");
          console.error(`  前: ${before.name} @ ${gba.toHex32(before.address)} ${before.type} (${before.length} bytes)`);
          console.error(`  後: ${after.name} @ ${gba.toHex32(after.address)} ${after.type} (${after.length} bytes)`);
          Deno.exit(1);
        }

        console.log(`${gba.toHex32(addr)}: ${before.name} -> ${after.name} (${after.type}, ${after.length} bytes, xref ${after.xrefCount}件)`);

        if (opts.save) {
          await saveProgram();
          console.log("保存しました");
        }
      } catch (e) {
        console.error(`エラー: ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
