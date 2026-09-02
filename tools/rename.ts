#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";

// boktai2 内の関数名を一括リネームする。
// src/**/*.c, src/**/*.s, include/**/*.h, asm/**/*.inc から OLD_NAME を
// 単語境界つきで検索し、NEW_NAME に置換する(INCFUNC("asm/func/OLD_NAME.inc")
// のような文字列中の参照も、単語境界に囲まれているためあわせて置換される)。
// さらに asm/func/OLD_NAME.inc が存在すれば asm/func/NEW_NAME.inc にリネームする。
//
// e.g. tools/rename.ts FUN_08242c08 Weapon_Unregister
//
// リポジトリのどこから実行しても動くよう、リポジトリルートは git から取得する。

const TARGET_DIRS = ["src", "include", "asm", "data"];
const TARGET_EXTS = [".c", ".h", ".s", ".inc"];

const escapeRegExp = (s: string): string => s.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");

const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};

const collectFiles = (dir: string): string[] => {
  const results: string[] = [];
  for (const entry of Deno.readDirSync(dir)) {
    const p = path.join(dir, entry.name);
    if (entry.isDirectory) {
      results.push(...collectFiles(p));
    } else if (entry.isFile && TARGET_EXTS.includes(path.extname(entry.name))) {
      results.push(p);
    }
  }
  return results;
};

const renameFunction = (repo: string, oldName: string, newName: string): void => {
  const pattern = new RegExp(`\\b${escapeRegExp(oldName)}\\b`, "g");
  const files = TARGET_DIRS.flatMap((dir) => collectFiles(path.join(repo, dir)));

  let changedFiles = 0;
  let totalReplacements = 0;
  for (const file of files) {
    const text = Deno.readTextFileSync(file);
    const matches = text.match(pattern);
    if (!matches) continue;

    Deno.writeTextFileSync(file, text.replace(pattern, newName));
    changedFiles++;
    totalReplacements += matches.length;
    console.log(`  ${path.relative(repo, file)}: ${matches.length}件`);
  }

  const oldIncPath = path.join(repo, "asm", "func", `${oldName}.inc`);
  try {
    Deno.statSync(oldIncPath);
    const newIncPath = path.join(repo, "asm", "func", `${newName}.inc`);
    Deno.renameSync(oldIncPath, newIncPath);
    console.log(`ファイルをリネームしました: asm/func/${oldName}.inc -> asm/func/${newName}.inc`);
  } catch (e) {
    if (!(e instanceof Deno.errors.NotFound)) throw e;
  }

  console.log(`完了: ${changedFiles}ファイル, ${totalReplacements}箇所を ${oldName} -> ${newName} にリネームしました`);
};

const main = () => {
  new Command()
    .name("rename.ts")
    .description("boktai2 内の関数名(および対応する asm/func/*.inc ファイル)を一括リネームする。")
    .arguments("<oldName:string> <newName:string>")
    .action((_, oldName, newName) => {
      renameFunction(getRepoRoot(), oldName, newName);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
