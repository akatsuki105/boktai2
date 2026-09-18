#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";
import { getRepoRoot } from "../../../../tools/common/common.ts";

// TODO レベルの関数を NAKED レベルに上げるための asm 側の下準備をする。
//
// 1. まだ切り出されていなければ tools/extract_func.ts を呼んで asm/func/FUNCNAME.inc に切り出す
// 2. bulk asm ファイルに残るスタブ3行 (thumb_func_start / ラベル / .include) と直後の空行を消す
// 3. それで bulk asm がヘッダだけになったら、そのファイルと .c の INCASM 行を消す
//
// --sig を渡すと、その ASM_FILE を INCASM している .c に NAKED 宣言をアドレス順で挿入するところまでやる。
// スタブを消したままだとそのシンボルが ROM から消えるので、この2つは対で行う必要がある。
// --sig を省いた場合は .c を書き換えず、消す前のラベル行のアドレスを表示するだけなので、
// 自分で NAKED 宣言を書くときの挿入位置の判断に使う。
//
// e.g. .claude/skills/todo-to-naked/scripts/prepare_asm.ts FUN_080a939c
// e.g. .claude/skills/todo-to-naked/scripts/prepare_asm.ts FUN_080a939c --sig "void FUN_080a939c(HealingEffect* p)"
// e.g. .claude/skills/todo-to-naked/scripts/prepare_asm.ts FUN_080a939c asm/healing_effect.inc

const escapeRegExp = (s: string): string => s.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const funcStartRe = (fn: string): RegExp => new RegExp(`^\\s*thumb_func_start\\s+${escapeRegExp(fn)}\\b`);

const listFiles = (dir: string, ext: string): string[] => {
  const results: string[] = [];
  for (const entry of Deno.readDirSync(dir)) {
    if (entry.isFile && path.extname(entry.name) === ext) results.push(path.join(dir, entry.name));
  }
  return results.sort();
};

// extract_func.ts と同じ探し方: src/*.s と asm/*.inc(トップレベルのみ)から thumb_func_start FN を探す
const findAsmFile = (repo: string, fn: string): string => {
  const pattern = funcStartRe(fn);
  const candidates = [...listFiles(path.join(repo, "src"), ".s"), ...listFiles(path.join(repo, "asm"), ".inc")];
  const hits = candidates.filter((p) => Deno.readTextFileSync(p).split("\n").some((ln) => pattern.test(ln)));

  if (hits.length === 0) return die(`エラー: thumb_func_start ${fn} を src/*.s / asm/*.inc から見つけられませんでした`);
  if (hits.length > 1) {
    const listing = hits.map((p) => `  - ${path.relative(repo, p)}`).join("\n");
    return die(`エラー: ${fn} が複数のファイルで見つかりました。ASM_FILE を明示してください:\n${listing}`);
  }
  return hits[0];
};

const stubIndex = (lines: string[], fn: string): number => lines.findIndex((ln) => funcStartRe(fn).test(ln));

const isExtracted = (lines: string[], fn: string): boolean => {
  const i = stubIndex(lines, fn);
  return i >= 0 && (lines[i + 2] ?? "").trim().startsWith(".include");
};

const runExtract = (repo: string, fn: string, asmRelPath: string): void => {
  const cmd = new Deno.Command("deno", {
    args: ["run", "-A", path.join(repo, "tools/extract_func.ts"), fn, asmRelPath],
    cwd: repo,
  });
  const { code, stdout, stderr } = cmd.outputSync();
  const out = new TextDecoder().decode(stdout).trim();
  if (out !== "") console.log(out);
  if (code !== 0) {
    const err = new TextDecoder().decode(stderr).trim();
    die(`エラー: extract_func.ts が失敗しました\n${err}`);
  }
};

// boktai2.sym から シンボル名 -> ROMアドレス の表を作る。行は "080a939c T FUN_080a939c" の形。
const readSymbols = (repo: string): Map<string, number> => {
  const table = new Map<string, number>();
  const symPath = path.join(repo, "boktai2.sym");
  if (!isFile(symPath)) return table;
  for (const line of Deno.readTextFileSync(symPath).split("\n")) {
    const m = line.match(/^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)/);
    if (m) table.set(m[2], parseInt(m[1], 16));
  }
  return table;
};

const isFile = (p: string): boolean => {
  try {
    return Deno.statSync(p).isFile;
  } catch (e) {
    if (e instanceof Deno.errors.NotFound) return false;
    throw e;
  }
};

// ASM_FILE を INCASM している .c を探す
const findCFile = (repo: string, asmRelPath: string): string => {
  const pattern = new RegExp(`INCASM\\("${escapeRegExp(asmRelPath)}"\\)`);
  const hits = listFiles(path.join(repo, "src"), ".c").filter((p) => pattern.test(Deno.readTextFileSync(p)));
  if (hits.length === 0) return die(`エラー: INCASM("${asmRelPath}") を含む .c が src/ に見つかりません`);
  if (hits.length > 1) {
    const listing = hits.map((p) => `  - ${path.relative(repo, p)}`).join("\n");
    return die(`エラー: INCASM("${asmRelPath}") が複数の .c にあります:\n${listing}`);
  }
  return hits[0];
};

const defRe = /^(?:NAKED\s+|NON_MATCH\s+)?[A-Za-z_][A-Za-z0-9_ *]*?([A-Za-z_][A-Za-z0-9_]*)\s*\(/;

// その行が関数の「定義」か。引数リストを閉じた直後が ';' なら宣言、'{' なら定義。
// 前方宣言はファイルの先頭にまとめて置かれていて .text の並びとは無関係なので、
// 目印に使うと挿入位置が壊れる (ApplySolBug の宣言に引っぱられて実際に壊れた)。
const isDefinition = (lines: string[], i: number): boolean => {
  const open = lines[i].indexOf("(");
  if (open < 0) return false;
  let depth = 0;
  for (let j = i; j < lines.length && j <= i + 20; j++) {
    for (let k = j === i ? open : 0; k < lines[j].length; k++) {
      const c = lines[j][k];
      if (c === "(") depth++;
      else if (c === ")" && --depth === 0) {
        const rest = lines[j].slice(k + 1);
        if (/^\s*;/.test(rest)) return false;
        if (rest.includes("{")) return true;
        // 引数リストの後で改行しているケース
        const next = lines.slice(j + 1).find((ln) => ln.trim() !== "");
        return (next ?? "").trim().startsWith("{");
      }
    }
  }
  return false;
};

// .c に並んでいる関数定義を [行番号, 名前, アドレス] で返す。これが .text の並び順そのもの。
const definedFunctions = (lines: string[], syms: Map<string, number>): { at: number; name: string; addr: number }[] => {
  const out: { at: number; name: string; addr: number }[] = [];
  for (let i = 0; i < lines.length; i++) {
    const name = lines[i].match(defRe)?.[1];
    if (name === undefined) continue;
    const addr = syms.get(name);
    if (addr === undefined || !isDefinition(lines, i)) continue;
    out.push({ at: i, name, addr });
  }
  return out;
};

// .c に NAKED 宣言をアドレス順で挿入する。関数はアドレスの昇順に並んでいる必要がある。
const insertNaked = (repo: string, fn: string, asmRelPath: string, sig: string, fnAddr: number): void => {
  const cPath = findCFile(repo, asmRelPath);
  const lines = Deno.readTextFileSync(cPath).split("\n");
  const decl = `NAKED ${sig.replace(/^NAKED\s+/, "").trim()} { INCFUNC("asm/func/${fn}.inc"); }`;

  const syms = readSymbols(repo);
  // 既存の関数定義のうち boktai2.sym で引けるものを、アドレス順の目印にする
  const defs = definedFunctions(lines, syms);
  let at = defs.find((d) => d.addr > fnAddr)?.at ?? lines.length;

  // 後続関数に付いているコメント行より上へ移動し、前後がちょうど1行ずつ空くようにする
  while (at > 0 && lines[at - 1].trim().startsWith("//")) at--;
  while (at > 0 && lines[at - 1].trim() === "") at--;
  while (at > 0 && lines[at - 1].trim() === "") at--;
  const block = at > 0 ? ["", decl] : [decl];
  if (at < lines.length && lines[at].trim() !== "") block.push("");
  const newLines = [...lines.slice(0, at), ...block, ...lines.slice(at)];
  Deno.writeTextFileSync(cPath, newLines.join("\n").replace(/\n+$/, "\n"));

  console.log(`${path.relative(repo, cPath)} に追加しました: ${decl}`);

  // 並びが崩れていたら ROM が一致しなくなる。asm 側はもう書き換え済みなので中断はせず警告だけ出す。
  const after = definedFunctions(newLines, syms);
  for (let i = 0; i + 1 < after.length; i++) {
    if (after[i].addr > after[i + 1].addr) {
      console.error(
        `警告: ${path.relative(repo, cPath)} の関数がアドレス順に並んでいません ` +
          `(${after[i].name} の後ろに ${after[i + 1].name})。手で並べ替えてください`,
      );
      break;
    }
  }
};

// bulk asm がヘッダだけになったか (関数もデータも残っていないか)
const isBlobEmpty = (lines: string[]): boolean =>
  lines.every((ln) => {
    const t = ln.trim();
    return t === "" || t === ".syntax unified" || t === ".text" || t === '.include "asm/macros.inc"' || t.startsWith("@");
  });

// 空になった bulk asm を消し、.c から INCASM 行も消す
const dropEmptyBlob = (repo: string, asmPath: string, asmRelPath: string): void => {
  const cPath = findCFile(repo, asmRelPath);
  const lines = Deno.readTextFileSync(cPath).split("\n");
  const at = lines.findIndex((ln) => ln.includes(`INCASM("${asmRelPath}")`));
  if (at < 0) die(`エラー: INCASM("${asmRelPath}") の行が ${path.relative(repo, cPath)} に見つかりません`);
  let end = at + 1;
  if ((lines[end] ?? "").trim() === "") end++;
  Deno.writeTextFileSync(cPath, [...lines.slice(0, at), ...lines.slice(end)].join("\n").replace(/\n+$/, "\n"));
  Deno.removeSync(asmPath);
  console.log(`${asmRelPath} が空になったので削除し、${path.relative(repo, cPath)} の INCASM 行も消しました`);
};

// bulk asm に残る関数のうち、対象より後ろのアドレスのものを返す。
// C 側の関数は INCASM より後ろに置くしかないので、これが残っていると ROM の並び順が崩れる。
const laterFunctionsInAsm = (lines: string[], fn: string, fnAddr: number): string[] => {
  const later: string[] = [];
  for (let i = 0; i < lines.length; i++) {
    const m = lines[i].match(/^([A-Za-z_][A-Za-z0-9_]*)\s*:\s*@\s*(0x[0-9A-Fa-f]+)/);
    if (m && m[1] !== fn && parseInt(m[2], 16) > fnAddr) later.push(`${m[1]} (${m[2]})`);
  }
  return later;
};

const prepare = (repo: string, fn: string, asmFile?: string, sig?: string): void => {
  const asmPath = asmFile === undefined ? findAsmFile(repo, fn) : path.resolve(repo, asmFile);
  const asmRelPath = path.relative(repo, asmPath);
  if (asmFile === undefined) console.log(`(自動検出: ${asmRelPath})`);

  {
    const lines = Deno.readTextFileSync(asmPath).split("\n");
    const i = stubIndex(lines, fn);
    const addr = i < 0 ? undefined : lines[i + 1]?.match(/@\s*(0x[0-9A-Fa-f]+)/)?.[1];
    if (addr !== undefined) {
      const later = laterFunctionsInAsm(lines, fn, parseInt(addr, 16));
      if (later.length > 0) {
        die(
          `エラー: ${fn} (${addr}) より後ろのアドレスの関数が ${asmRelPath} に残っています。\n` +
            `C 側の関数は INCASM より後ろに置くしかないので、先にそれらを NAKED に上げてください:\n` +
            later.map((s) => `  - ${s}`).join("\n"),
        );
      }
    }
  }

  if (!isExtracted(Deno.readTextFileSync(asmPath).split("\n"), fn)) {
    runExtract(repo, fn, asmRelPath);
  } else {
    console.log(`(${fn} は切り出し済みです)`);
  }

  const lines = Deno.readTextFileSync(asmPath).split("\n");
  const start = stubIndex(lines, fn);
  if (start < 0) die(`エラー: thumb_func_start ${fn} が ${asmRelPath} に見つかりません`);
  if (!new RegExp(`^${escapeRegExp(fn)}\\s*:`).test(lines[start + 1] ?? "")) {
    die(`エラー: ${fn}: ラベル行が thumb_func_start の直後にありません`);
  }
  if (!(lines[start + 2] ?? "").trim().startsWith(".include")) {
    die(`エラー: ${fn} が .include 形式になっていません（切り出しに失敗しています）`);
  }

  const addr = lines[start + 1].match(/@\s*(0x[0-9A-Fa-f]+)/)?.[1];

  // スタブ3行と、続く空行1行を消す
  let end = start + 3;
  if ((lines[end] ?? "").trim() === "") end++;
  const newLines = [...lines.slice(0, start), ...lines.slice(end)];
  Deno.writeTextFileSync(asmPath, newLines.join("\n").replace(/\n+$/, "\n"));

  console.log(`${asmRelPath} からスタブを削除しました`);
  if (sig === undefined) {
    console.log(`次: src/*.c に NAKED 宣言を追加してください (${fn} のアドレスは ${addr ?? "不明"})`);
    if (isBlobEmpty(newLines)) dropEmptyBlob(repo, asmPath, asmRelPath);
    return;
  }
  if (!new RegExp(`\\b${escapeRegExp(fn)}\\s*\\(`).test(sig)) {
    die(`エラー: --sig に関数名 ${fn} が含まれていません: ${sig}`);
  }
  const fnAddr = addr === undefined ? readSymbols(repo).get(fn) : parseInt(addr, 16);
  if (fnAddr === undefined) {
    die(`エラー: ${fn} のアドレスが分かりません (ラベル行にも boktai2.sym にもありません)`);
    return;
  }
  insertNaked(repo, fn, asmRelPath, sig, fnAddr);

  if (isBlobEmpty(Deno.readTextFileSync(asmPath).split("\n"))) dropEmptyBlob(repo, asmPath, asmRelPath);
};

const main = () => {
  new Command()
    .name("prepare_asm.ts")
    .description("TODO レベルの関数を切り出し、bulk asm ファイルからスタブを削除する (--sig があれば .c に NAKED 宣言も追加する)。")
    .argument("<functionName:string>", "対象の関数名")
    .argument("[asmFile:string]", "関数が入っている .s/.inc (省略時は自動検出)")
    .option("--sig <signature:string>", "渡すと .c に NAKED 宣言をアドレス順で挿入する。例: \"void FUN_080a939c(HealingEffect* p)\"")
    .action((opts, functionName, asmFile) => {
      prepare(getRepoRoot(), functionName, asmFile, opts.sig);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
