#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net --allow-env

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import { getFunctionByAddress, renameFunctionByAddress } from "./api/function.ts";
import { saveProgram } from "./api/program.ts";
import { resolveAddress } from "./common.ts";

// Ghidra 側の関数をリネームして保存する。GUIのGhidraが起動している必要がある。
// GhidraMCP の Strict Naming Enforcement (Edit > Tool Options > GhidraMCP HTTP Server) をオフにしておくこと。
// オンのままだと独自の命名ルールに合わない名前は拒否される。
//
// e.g. tools/ghidra/rename_function.ts FUN_08241298 EEPROM_Erase
// e.g. tools/ghidra/rename_function.ts 0x08241298 EEPROM_Erase

const main = () => {
  new Command()
    .name("rename_function.ts")
    .description("Ghidra 側の関数をリネームして保存する。GUIのGhidraが起動している必要がある。")
    .argument("<target:string>", "リネームする関数のシンボル名(boktai2.sym から引く)またはROMアドレス")
    .argument("<newName:string>", "新しい関数名")
    .option("--no-save", "リネーム後に save_program を実行しない。")
    .action(async (opts, target, newName) => {
      const addr = resolveAddress(target);
      try {
        // rename_function_by_address はアドレスを「含む」関数をリネームするので、関数の途中を指していないか先に確かめる
        const func = await getFunctionByAddress(addr);
        if (func.entry !== addr) {
          console.error(`エラー: 0x${gba.toHex32(addr)} は関数 ${func.name} (0x${gba.toHex32(func.entry)}) の途中を指しています`);
          Deno.exit(1);
        }

        console.log(await renameFunctionByAddress(addr, newName));

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
