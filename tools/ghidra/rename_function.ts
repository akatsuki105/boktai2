#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { BASE_URL, ghidraGet, resolveAddress } from "./common.ts";

// Ghidra 側の関数をリネームして保存する。GUIのGhidraが起動している必要がある。
// GhidraMCP の Strict Naming Enforcement (Edit > Tool Options > GhidraMCP HTTP Server) をオフにしておくこと。
// オンのままだと独自の命名ルールに合わない名前は拒否される。
//
// e.g. tools/ghidra/rename_function.ts FUN_08241298 EEPROM_Erase
// e.g. tools/ghidra/rename_function.ts 0x08241298 EEPROM_Erase

const post = async (endpoint: string, body: Record<string, unknown>): Promise<Record<string, unknown>> => {
  try {
    const res = await fetch(`${BASE_URL}/${endpoint}`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(body),
      signal: AbortSignal.timeout(60 * 1000),
    });
    return await res.json();
  } catch (e) {
    console.error(`エラー: ${BASE_URL}/${endpoint} の呼び出しに失敗しました(Ghidra は起動していますか?)`);
    console.error(`  ${e instanceof Error ? e.message : String(e)}`);
    Deno.exit(1);
  }
};

const main = () => {
  new Command()
    .name("rename_function.ts")
    .description("Ghidra 側の関数をリネームして保存する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "リネームする関数のシンボル名(boktai2.sym から引く)またはROMアドレス")
    .argument("<newName:string>", "新しい関数名")
    .option("--no-save", "リネーム後に save_program を実行しない。")
    .action(async (opts, target, newName) => {
      const addr = `0x${gba.toHex32(resolveAddress(target))}`;

      // rename_function_by_address はアドレスを「含む」関数をリネームするので、関数の途中を指していないか先に確かめる
      const info = await ghidraGet("get_function_by_address", { address: addr }, 60);
      const entry = info.match(/^Entry: ([0-9A-Fa-f]+)/m)?.[1];
      if (!entry) {
        console.error(`エラー: ${addr} に関数がありません: ${info.trim()}`);
        Deno.exit(1);
      }
      if (parseInt(entry, 16) !== parseInt(addr, 16)) {
        const name = info.match(/^Function: (\S+)/m)?.[1] ?? "?";
        console.error(`エラー: ${addr} は関数 ${name} (0x${entry.toUpperCase()}) の途中を指しています`);
        Deno.exit(1);
      }

      const renamed = await post("rename_function_by_address", { function_address: addr, new_name: newName });
      if (renamed.status !== "success") {
        console.error(`エラー: リネームに失敗しました: ${JSON.stringify(renamed)}`);
        Deno.exit(1);
      }
      console.log(renamed.message);

      if (opts.save) {
        const saved = await post("save_program", {});
        if (saved.success !== true) {
          console.error(`エラー: 保存に失敗しました: ${JSON.stringify(saved)}`);
          Deno.exit(1);
        }
        console.log("保存しました");
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
