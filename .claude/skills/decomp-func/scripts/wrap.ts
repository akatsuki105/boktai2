#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";

// NON_MATCH の殻を外す / 着せる。行単位でしか編集しないので #ifdef / #else / #endif が行頭から動かない
//
// e.g. .claude/skills/decomp-func/scripts/wrap.ts open FUN_08066d2c
// e.g. .claude/skills/decomp-func/scripts/wrap.ts close FUN_08066d2c --note "残差1命令, 原典は ..." --note "Tier A は試済 (...)"
const main = () => {
  new Command()
    .name("wrap.ts")
    .description("NAKED / NON_MATCH の INCFUNC の殻を外して C を書ける形にする (open) / 書いた C を NON_MATCH に戻す (close)")
    .command("open", "NAKED の1行スタブ、または NON_MATCH の #ifdef ブロックを、素の C 関数にする")
    .argument("<name:string>", "関数名")
    .action((_opts, name: string) => open(name))
    .command("close", "素の C 関数を NON_MATCH (#ifdef NONMATCHING_C / #else INCFUNC / #endif) に戻す")
    .argument("<name:string>", "関数名")
    .option("-n, --note <text:string>", "シグネチャの直上に入れる残差メモ (// は不要, 複数回指定できる)", { collect: true })
    .action((opts: { note?: string[] }, name: string) => close(name, opts.note ?? []))
    .parse(Deno.args);
};

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};

// 関数名から定義のある .c を探す。NAKED / NON_MATCH / 素の C のどれでも拾う
const findDef = (repo: string, name: string): { file: string; lines: string[]; sig: number } => {
  // 型は複数トークンになりうる (`NAKED EntityD854Node* Foo(`) ので、`(` の直前の識別子で照合する
  const sigRe = new RegExp(`^\\s*(?:NAKED|NON_MATCH|UNUSED)?[\\w\\s*]*?\\b${name}\\s*\\(`);
  const srcDir = path.join(repo, "src");

  for (const file of walkC(srcDir)) {
    const lines = Deno.readTextFileSync(file).split("\n");
    for (let i = 0; i < lines.length; i++) {
      // 前方宣言 (`;` で終わる) は定義ではない
      if (!sigRe.test(lines[i]) || /;\s*$/.test(lines[i])) continue;
      if (!lines[i].includes("{")) continue;
      return { file, lines, sig: i };
    }
  }
  return die(`${name} の定義が src/ に見つかりません`);
};

const walkC = (dir: string): string[] => {
  const out: string[] = [];
  for (const e of Deno.readDirSync(dir)) {
    const p = path.join(dir, e.name);
    if (e.isDirectory) out.push(...walkC(p));
    else if (e.name.endsWith(".c")) out.push(p);
  }
  return out.sort();
};

// シグネチャ行から、本体を閉じる `}` の行番号を返す
const findBodyEnd = (lines: string[], sig: number): number => {
  let depth = 0;
  for (let i = sig; i < lines.length; i++) {
    for (const ch of lines[i]) {
      if (ch === "{") depth++;
      else if (ch === "}") depth--;
    }
    if (depth === 0) return i;
  }
  return die("本体を閉じる } が見つかりません");
};

const incOf = (name: string) => `asm/func/${name}.inc`;

// シグネチャ直上の残差メモだけを剥がす (関数の説明コメントは残す)。削った行数を返す
// メモは「残差 / Tier / 未: で始まる行」から始まってシグネチャまで続く (折り返した続きの行はマーカーを持たない)
const dropNotes = (lines: string[], sig: number): number => {
  let top = sig;
  while (top > 0 && /^\s*\/\//.test(lines[top - 1])) top--; // 直上のコメント塊の先頭
  const start = lines.slice(top, sig).findIndex((l) => /^\s*\/\/\s*(残差|Tier|未:)/.test(l));
  if (start < 0) return 0;
  const n = sig - (top + start);
  lines.splice(top + start, n);
  return n;
};

const write = (file: string, lines: string[]) => {
  Deno.writeTextFileSync(file, lines.join("\n"));
  const after = Deno.readTextFileSync(file);
  // 自前のスライスで #else を行頭から落とすのが過去2回の事故原因なので、書いた後に必ず検算する
  for (const d of ["#ifdef", "#else", "#endif"]) {
    if (new RegExp(`\\S${d}\\b`).test(after)) die(`${d} が行頭にありません。書き込みを戻してください: ${file}`);
  }
  const n = (re: RegExp) => (after.match(re) ?? []).length;
  if (n(/^#if(def|ndef)?\b/gm) !== n(/^#endif\b/gm)) die(`#if と #endif の数が合いません: ${file}`);
};

const open = (name: string) => {
  const repo = getRepoRoot();
  const { file, lines, sig } = findDef(repo, name);
  const end = findBodyEnd(lines, sig);

  if (lines[sig].includes("NAKED")) {
    if (sig !== end) die(`${name} は NAKED ですが1行になっていません`);
    const m = lines[sig].match(/^(\s*)NAKED\s+(.*?)\s*\{.*\}\s*$/);
    if (!m) die(`${name} の NAKED スタブを解釈できません: ${lines[sig]}`);
    lines.splice(sig, 1, `${m![1]}${m![2]} {`, `${m![1]}}`);
    write(file, lines);
    console.log(`${path.relative(repo, file)}:${sig + 1} ${name} を素の C にしました (本体は空です)`);
    return;
  }

  if (!lines[sig].includes("NON_MATCH")) die(`${name} は NAKED でも NON_MATCH でもありません`);

  const ifdef = lines.findIndex((l, i) => i > sig && i < end && l.trim() === "#ifdef NONMATCHING_C");
  const els = lines.findIndex((l, i) => i > sig && i < end && l.trim() === "#else");
  const endif = lines.findIndex((l, i) => i > sig && i < end && l.trim() === "#endif");
  if (ifdef < 0 || els < 0 || endif < 0) die(`${name} の #ifdef / #else / #endif が揃っていません`);

  lines.splice(els, endif - els + 1); // #else から #endif まで
  lines.splice(ifdef, 1); // #ifdef NONMATCHING_C
  lines[sig] = lines[sig].replace(/\bNON_MATCH\s+/, "");
  const dropped = dropNotes(lines, sig);
  write(file, lines);
  console.log(`${path.relative(repo, file)}:${sig + 1 - dropped} ${name} の NON_MATCH の殻を外しました (残差メモ ${dropped} 行を削除)`);
};

const close = (name: string, notes: string[]) => {
  const repo = getRepoRoot();
  const { file, lines, sig } = findDef(repo, name);
  if (/\b(NAKED|NON_MATCH)\b/.test(lines[sig])) die(`${name} はすでに ${lines[sig].includes("NAKED") ? "NAKED" : "NON_MATCH"} です`);

  const end = findBodyEnd(lines, sig);
  const inc = incOf(name);
  restoreInc(repo, inc);

  const indent = lines[sig].match(/^\s*/)![0];
  lines.splice(end, 0, "#else", `${indent}  INCFUNC("${inc}");`, "#endif");
  lines.splice(sig + 1, 0, "#ifdef NONMATCHING_C");
  lines[sig] = `${indent}NON_MATCH ${lines[sig].trimStart()}`;
  lines.splice(sig, 0, ...notes.map((n) => `${indent}// ${n}`));
  write(file, lines);
  console.log(`${path.relative(repo, file)}:${sig + 1} ${name} を NON_MATCH に戻しました (メモ ${notes.length} 行)`);
};

// MATCHING にして消した .inc を戻す (open -> close で往復したときのため)
const restoreInc = (repo: string, inc: string) => {
  const abs = path.join(repo, inc);
  try {
    Deno.statSync(abs);
    return;
  } catch {
    // 無いので git から戻す
  }
  const { success, stdout } = new Deno.Command("git", { args: ["show", `HEAD:${inc}`], cwd: repo }).outputSync();
  if (!success) die(`${inc} がありません。git からも取れないので手で戻してください`);
  Deno.writeFileSync(abs, stdout);
  console.log(`${inc} を HEAD から復元しました`);
};

if (import.meta.main) main();
