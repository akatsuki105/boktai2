#!/usr/bin/env -S deno run --allow-read --allow-net --allow-env

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { applyDataType, auditGlobal, renameData } from "./api/data.ts";
import { saveProgram } from "./api/program.ts";
import { resolveTarget } from "./common.ts";

// Ghidra 側のグローバル変数 (IWRAM/EWRAM など) の型を変えて保存する。GUIのGhidraが起動している必要がある。
//
// apply_data_type はポインタ型や配列型を当てるとシンボル名を自動で付け替えることがある
// (references/http-api.md 参照)。ここでは元の名前を控えておき、変わっていたら戻す。
// apply_data_type は dry_run を読まない (GhidraMCP-6.0.0 で確認) ので、
// 実行してから audit_global で前後を比べる。
//
// 型が広がる場合は後続バイトが未定義でないと失敗する。その場合は先に隣のデータを消すこと。
//
// e.g. tools/ghidra/set_global_type.ts 0x03003530 u32
// e.g. tools/ghidra/set_global_type.ts gAuxSpriteLists "AuxSprite *[2]"

// "u32 *[2]" と "u32*[2]" のような表記ゆれを吸収して比べる
const normalizeType = (s: string): string => s.replace(/\s+/g, "");

const main = () => {
  new Command()
    .name("set_global_type.ts")
    .description("Ghidra 側のグローバル変数の型を変えて保存する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "型を変えるグローバルのシンボル名またはアドレス (0x03003530 など)")
    .argument("<typeName:string>", "適用する型名 (Ghidra 上の名前。'Vec3' や 'AuxSprite *[2]' など)")
    .option("--no-save", "変更後に save_program を実行しない。")
    .action(async (opts, target, typeName) => {
      try {
        const addr = await resolveTarget(target);
        if (addr === undefined) {
          console.error(`エラー: '${target}' をアドレスに解決できません`);
          Deno.exit(1);
        }

        const before = await auditGlobal(addr);
        if (normalizeType(before.type) === normalizeType(typeName)) {
          console.log(`${gba.toHex32(addr)} (${before.name}) は既に ${before.type} です (変更なし)`);
          return;
        }

        const res = await applyDataType(addr, typeName);
        for (const w of res.warnings) console.warn(`警告: ${w}`);

        let after = await auditGlobal(addr);

        // apply_data_type が名前を勝手に変えることがあるので、元の名前に戻す
        if (before.name !== "" && after.name !== before.name) {
          console.warn(`警告: 型の適用で名前が '${before.name}' から '${after.name}' に変わったため戻します`);
          const back = await renameData(addr, before.name);
          for (const w of back.warnings) console.warn(`警告: ${w}`);
          after = await auditGlobal(addr);
          if (after.name !== before.name) {
            console.error(`エラー: 名前を '${before.name}' に戻せませんでした (現在 '${after.name}')。保存はしていません。`);
            Deno.exit(1);
          }
        }

        if (normalizeType(after.type) !== normalizeType(typeName)) {
          console.error(`エラー: 型が ${after.type} のままです (指定は ${typeName})。保存はしていません。`);
          console.error("型名が Ghidra 上に存在するか、後続バイトが未定義かを確認してください。");
          Deno.exit(1);
        }

        console.log(`${gba.toHex32(addr)} (${after.name}): ${before.type} (${before.length} bytes) -> ${after.type} (${after.length} bytes)`);
        if (after.length !== before.length) {
          console.log(`  サイズが ${before.length} から ${after.length} バイトに変わりました。後続のデータ定義を確認してください。`);
        }

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
