#!/usr/bin/env -S deno run --allow-read --allow-net --allow-env

import { Command } from "@cliffy/command";
import { saveProgram } from "./api/program.ts";
import { getStructLayout, modifyStructField, StructField, StructLayout } from "./api/struct.ts";

// Ghidra 側の構造体のフィールドをリネームして保存する。GUIのGhidraが起動している必要がある。
// GhidraMCP の Strict Naming Enforcement (Edit > Tool Options > GhidraMCP HTTP Server) をオフにしておくこと。
// オンのままだとハンガリアン記法の接頭辞 (pNext など) が勝手に付けられる。
// フィールドは名前でもオフセット (0x で始まる16進数) でも指定できる。
// modify_struct_field が名前以外 (オフセット・型・サイズ) を変えていないことを前後のレイアウト比較で確かめてから保存する。
//
// e.g. tools/ghidra/rename_struct_field.ts Entity28CB q_shakeX shakeX
// e.g. tools/ghidra/rename_struct_field.ts Entity28CB 0x60 shakeX

const findField = (layout: StructLayout, target: string): StructField | undefined => {
  if (/^0x[0-9A-Fa-f]+$/.test(target)) {
    const off = parseInt(target, 16);
    return layout.fields.find((f) => f.offset === off);
  }
  return layout.fields.find((f) => f.name === target);
};

const main = () => {
  new Command()
    .name("rename_struct_field.ts")
    .description("Ghidra 側の構造体のフィールドをリネームして保存する。GUIのGhidraが起動している必要がある。")
    .argument("<structName:string>", "構造体名 (Ghidra 上の名前)")
    .argument("<field:string>", "リネームするフィールドの名前、またはオフセット (0x60 のように 0x 付きの16進数)")
    .argument("<newName:string>", "新しいフィールド名")
    .option("--no-save", "リネーム後に save_program を実行しない。")
    .action(async (opts, structName, field, newName) => {
      try {
        const before = await getStructLayout(structName);
        const target = findField(before, field);
        if (!target) {
          console.error(`エラー: ${structName} にフィールド '${field}' がありません`);
          Deno.exit(1);
        }
        if (before.fields.some((f) => f.name === newName)) {
          console.error(`エラー: ${structName} には既に '${newName}' というフィールドがあります`);
          Deno.exit(1);
        }

        // 名前のないフィールドは offset:N で指定する (GhidraMCP の仕様)
        const fieldSpec = target.name ? target.name : `offset:${target.offset}`;
        const res = await modifyStructField(structName, fieldSpec, { newName });

        // 名前以外が変わっていないか確かめる
        const after = await getStructLayout(structName);
        const renamed = after.fields.find((f) => f.offset === target.offset);
        const unchanged = after.size === before.size &&
          after.fields.length === before.fields.length &&
          after.fields.every((f, i) => {
            const b = before.fields[i];
            return f.offset === b.offset && f.size === b.size && f.type === b.type &&
              (f.offset === target.offset ? f.name === newName : f.name === b.name);
          });
        if (!renamed || !unchanged) {
          console.error(`エラー: リネーム結果が想定と違います。保存はしていません。Ghidra 上で確認してください。`);
          console.error(`  応答: ${res.trim()}`);
          console.error(`  0x${target.offset.toString(16).toUpperCase()}: ${renamed ? `${renamed.type} ${renamed.name}` : "(なし)"}, サイズ ${before.size} -> ${after.size}`);
          Deno.exit(1);
        }
        console.log(`${structName}+0x${target.offset.toString(16).toUpperCase()}: ${target.name || "(無名)"} -> ${newName}`);

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
