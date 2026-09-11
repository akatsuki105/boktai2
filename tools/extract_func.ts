#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";
import { getRepoRoot } from "./common/common.ts";

// .s/.inc ファイルの中から1関数分のアセンブリを asm/func/FUNCNAME.inc として切り出し、 元の場所を `.include "asm/func/FUNCNAME.inc"` に置き換える。
//
// ASM_FILE を省略すると、src/*.s と asm/*.inc(トップレベルのみ、asm/func/ や asm/macros/ は対象外)から
// `thumb_func_start FUNCTION_NAME` を含むファイルを自動検出する。
//
// e.g. tools/extract-func-asm.ts FUN_0824c0c4 asm/code_0824beb8.inc
// e.g. tools/extract-func-asm.ts FUN_0824c0c4
//
// 変換前 (ASM_FILE 内):
//         thumb_func_start FUN_0824c0c4
// FUN_0824c0c4: @ 0x0824C0C4
//         push {r4, r5, r6, lr}
//         ...
//         bx r1
//         .align 2, 0
//
// 変換後 (ASM_FILE 内):
//         thumb_func_start FUN_0824c0c4
// FUN_0824c0c4: @ 0x0824C0C4
//   .include "asm/func/FUN_0824c0c4.inc"
//
// asm/func/FUN_0824c0c4.inc (新規作成):
//         push {r4, r5, r6, lr}
//         ...
//         bx r1
//         .align 2, 0

const escapeRegExp = (s: string): string => s.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

// 行頭の thumb_func_start FN にマッチする正規表現
const funcStartRe = (fn: string): RegExp => new RegExp(`^\\s*thumb_func_start\\s+${escapeRegExp(fn)}\\b`);

const listFiles = (dir: string, ext: string): string[] => {
  const results: string[] = [];
  for (const entry of Deno.readDirSync(dir)) {
    if (entry.isFile && path.extname(entry.name) === ext) results.push(path.join(dir, entry.name));
  }
  return results.sort();
};

// src/*.s と asm/*.inc(トップレベルのみ)から thumb_func_start FN を含むファイルを探す。
const findAsmFile = (repo: string, fn: string): string => {
  const pattern = funcStartRe(fn);
  const candidates = [...listFiles(path.join(repo, "src"), ".s"), ...listFiles(path.join(repo, "asm"), ".inc")];
  const hits = candidates.filter((p) => Deno.readTextFileSync(p).split("\n").some((ln) => pattern.test(ln)));

  if (hits.length === 0) {
    return die(`エラー: thumb_func_start ${fn} を src/*.s / asm/*.inc から見つけられませんでした`);
  }
  if (hits.length > 1) {
    const listing = hits.map((p) => `  - ${path.relative(repo, p)}`).join("\n");
    return die(`エラー: ${fn} が複数のファイルで見つかりました。ASM_FILE を明示してください:\n${listing}`);
  }
  return hits[0];
};

const isFile = (p: string): boolean => {
  try {
    return Deno.statSync(p).isFile;
  } catch (e) {
    if (e instanceof Deno.errors.NotFound) return false;
    throw e;
  }
};

const extractFunction = (repo: string, fn: string, asmFile?: string): void => {
  let asmPath: string;
  if (asmFile !== undefined) {
    asmPath = path.resolve(repo, asmFile);
    if (!isFile(asmPath)) die(`エラー: ${asmPath} が見つかりません`);
  } else {
    asmPath = findAsmFile(repo, fn);
    console.log(`(自動検出: ${path.relative(repo, asmPath)})`);
  }

  const incRelPath = `asm/func/${fn}.inc`;
  const outPath = path.join(repo, incRelPath);

  const lines = Deno.readTextFileSync(asmPath).split("\n");

  const start = lines.findIndex((ln) => funcStartRe(fn).test(ln));
  if (start < 0) die(`エラー: thumb_func_start ${fn} が ${asmPath} に見つかりません`);

  const labelIdx = start + 1;
  if (labelIdx >= lines.length || !new RegExp(`^${escapeRegExp(fn)}\\s*:`).test(lines[labelIdx])) {
    die(`エラー: ${fn}: ラベル行が thumb_func_start の直後にありません`);
  }

  const bodyStart = labelIdx + 1;
  if (bodyStart < lines.length && lines[bodyStart].trim().startsWith(".include")) {
    die(`エラー: ${fn} は既に切り出し済みのようです（.include 行を検出）`);
  }

  let bodyEnd = lines.length;
  let isLastFunc = true;
  for (let j = bodyStart; j < lines.length; j++) {
    if (/^\s*thumb_func_start\s+\w/.test(lines[j])) {
      bodyEnd = j;
      isLastFunc = false;
      break;
    }
  }

  const body = lines.slice(bodyStart, bodyEnd);
  while (body.length > 0 && body[body.length - 1].trim() === "") body.pop();

  if (body.length === 0) die(`エラー: ${fn} の本体が空です`);
  if (isFile(outPath)) die(`エラー: ${outPath} は既に存在します（上書きを避けるため中断）`);

  Deno.mkdirSync(path.dirname(outPath), { recursive: true });
  Deno.writeTextFileSync(outPath, body.join("\n") + "\n");

  const includeLine = `  .include "${incRelPath}"`;
  // ファイル末尾の関数の場合、joinで実際の空行を作るには空文字列が2つ要る
  // (1つだけだと単なる末尾改行になり、目に見える空行にならない)。
  const replacement = isLastFunc ? [includeLine, "", ""] : [includeLine, ""];
  const newLines = [...lines.slice(0, labelIdx + 1), ...replacement, ...lines.slice(bodyEnd)];
  Deno.writeTextFileSync(asmPath, newLines.join("\n"));

  console.log(`${incRelPath} を作成しました（${body.length} 行）`);
  console.log(`${path.relative(repo, asmPath)} を書き換えました`);
};

const main = () => {
  new Command()
    .name("extract_func.ts")
    .description("巨大な .s/.inc ファイルから1関数分のアセンブリを asm/func/FUNCNAME.inc として切り出す。")
    .arguments("<functionName:string> [asmFile:string]")
    .action((_, functionName, asmFile) => {
      extractFunction(getRepoRoot(), functionName, asmFile);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
