#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --allow-net --allow-env

import { Command } from "@cliffy/command";
import * as path from "@std/path";

// e.g. .claude/skills/decomp-func/scripts/context.ts FUN_080f8e3c
// e.g. .claude/skills/decomp-func/scripts/context.ts FUN_08242b88 src/weapon.c asm/func/FUN_08242b88.inc
const main = async () => {
  await new Command()
    .name("context.ts")
    .description("関数を一致させるための材料をまとめて出す (アセンブリ / シグネチャ / 型のレイアウト / 呼び先 / 兄弟関数 / 現在の C)。")
    .argument("<functionName:string>", "対象の関数名")
    .argument("[srcFile:string]", "関数の宣言がある .c (省略時は src/ から自動検出)")
    .argument("[asmFile:string]", "対象のアセンブリ (省略時は asm/func/<関数名>.inc)")
    .option("--no-ghidra", "Ghidra に問い合わせない")
    .option("--brief", "OFFSETS と SIBLINGS を省く (同じファイルを続けてやるときなど、既に頭に入っている情報の再掲を避ける)")
    .action(async (opts, fn, srcArg, asmArg) => {
      await context(getRepoRoot(), fn, srcArg, asmArg, opts.ghidra, opts.brief ?? false);
    })
    .parse(Deno.args);
};

const GHIDRA = Deno.env.get("GHIDRA_MCP_URL") ?? "http://127.0.0.1:8089";
const PRIMITIVES = new Set([
  "void",
  "u8",
  "u16",
  "u32",
  "u64",
  "s8",
  "s16",
  "s32",
  "s64",
  "bool8",
  "bool32",
  "unknown",
  "int",
  "char",
  "short",
  "long",
  "float",
  "double",
  "unsigned",
  "signed",
  "const",
  "struct",
  "static",
  "NAKED",
  "NON_MATCH",
  "UNUSED",
  "undefined",
  "undefined1",
  "undefined2",
  "undefined4",
  "code",
  "uint",
  "byte",
]);

// 宣言文から型名らしき識別子を拾う
const typeNames = (texts: string[]): string[] => {
  const names = new Set<string>();
  for (const t of texts) {
    for (const m of t.matchAll(/\b([A-Z]\w{2,})\b/g)) {
      if (!PRIMITIVES.has(m[1])) names.add(m[1]);
    }
  }
  return [...names];
};

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};

const hr = (title?: string) => {
  console.log("=".repeat(60));
  if (title !== undefined) {
    console.log(title);
    console.log("=".repeat(60));
  }
};

const listFiles = (dir: string, ext: string): string[] => {
  const out: string[] = [];
  const walk = (d: string) => {
    for (const e of Deno.readDirSync(d)) {
      const child = path.join(d, e.name);
      if (e.isDirectory) walk(child);
      else if (e.isFile && path.extname(e.name) === ext) out.push(child);
    }
  };
  walk(dir);
  return out.sort();
};

// `(` の直前の識別子を関数名とみなす (`NAKED static s32 Foo(` のような修飾子付きも拾う)
const defRe = (fn: string): RegExp => new RegExp(`^(NAKED|NON_MATCH)?\\s*[\\w* ]*?\\b${fn}\\s*\\(`);

const findSrcFile = (repo: string, fn: string): string => {
  for (const f of listFiles(path.join(repo, "src"), ".c")) {
    const re = defRe(fn);
    for (const line of Deno.readTextFileSync(f).split("\n")) {
      if (re.test(line)) return f;
    }
  }
  return die(`関数 ${fn} の宣言が src/ に見つかりませんでした`);
};

// 関数の宣言行を (行番号, 行) で返す
const findSignature = (srcFile: string, fn: string): { line: number; text: string; level: string } | null => {
  const re = defRe(fn);
  const lines = Deno.readTextFileSync(srcFile).split("\n");
  for (let i = 0; i < lines.length; i++) {
    if (!re.test(lines[i])) continue;
    const level = lines[i].startsWith("NAKED") ? "NAKED" : lines[i].startsWith("NON_MATCH") ? "NON_MATCH" : "MATCHING";
    return { line: i + 1, text: lines[i], level };
  }
  return null;
};

// 定義行から関数ブロック全体 (波括弧の深さで終端を判定) を返す
const extractBlock = (srcFile: string, fn: string): string => {
  const lines = Deno.readTextFileSync(srcFile).split("\n");
  const re = defRe(fn);
  const start = lines.findIndex((l) => re.test(l));
  if (start < 0) return `(${fn} の実装が見つかりませんでした)`;

  let depth = 0;
  let entered = false;
  for (let i = start; i < lines.length; i++) {
    for (const ch of lines[i]) {
      if (ch === "{") {
        depth++;
        entered = true;
      } else if (ch === "}") depth--;
    }
    if (entered && depth === 0) return lines.slice(start, i + 1).join("\n");
  }
  return lines.slice(start).join("\n");
};

// --------------------------------------------------------------------------
// アセンブリ側の読み取り
// --------------------------------------------------------------------------

type Asm = { code: string[]; pool: string[]; callees: string[]; offsets: number[] };

const readAsm = (asmFile: string): Asm => {
  const lines = Deno.readTextFileSync(asmFile).split("\n");
  const code: string[] = [];
  const pool: string[] = [];
  const callees: string[] = [];
  const offsets = new Set<number>();

  for (let i = 0; i < lines.length; i++) {
    const s = lines[i].trim();
    if (!s) continue;
    if (/^_?\w+:\s*\.(4byte|word|short|2byte|byte)/.test(s) || /^\.(4byte|word)/.test(s)) {
      pool.push(s);
      continue;
    }
    if (s === ".align 2, 0") continue;
    code.push(lines[i].replace(/\s+$/, ""));

    const bl = s.match(/^bl\s+(\w+)/);
    if (bl && !bl[1].startsWith("_call_via")) callees.push(bl[1]);

    // 構造体オフセットになりうる即値を集める
    for (const m of s.matchAll(/\[\w+,\s*#(0x[0-9a-fA-F]+|\d+)\]/g)) offsets.add(Number(m[1]));
    for (const m of s.matchAll(/@\s*=0x0000([0-9a-fA-F]{1,4})\b/g)) offsets.add(Number(`0x${m[1]}`));
    const adds = s.match(/^adds\s+r\d+,\s*#(0x[0-9a-fA-F]+|\d+)$/);
    if (adds) offsets.add(Number(adds[1]));

    // `movs rN, #imm` + `lsls rN, rN, #k` の組で作る大きめのオフセット
    const movs = s.match(/^movs\s+(r\d+),\s*#(0x[0-9a-fA-F]+|\d+)$/);
    if (movs) {
      const next = (lines[i + 1] ?? "").trim();
      const lsls = next.match(new RegExp(`^lsls\\s+${movs[1]},\\s*${movs[1]},\\s*#(0x[0-9a-fA-F]+|\\d+)$`));
      if (lsls) offsets.add(Number(movs[2]) << Number(lsls[1]));
    }
  }

  return { code, pool, callees: [...new Set(callees)], offsets: [...offsets].sort((a, b) => a - b) };
};

// --------------------------------------------------------------------------
// リポジトリ側の引き当て
// --------------------------------------------------------------------------

// 0x03xxxxxx / 0x02xxxxxx のプール定数を iwram/ewram の宣言コメントから引く
const resolveGlobals = (repo: string, pool: string[], code: string[]): string[] => {
  const addrs = new Set<string>();
  for (const s of [...pool, ...code]) {
    for (const m of s.matchAll(/0x0([23])([0-9A-Fa-f]{6})\b/g)) addrs.add(`0x0${m[1]}${m[2].toUpperCase()}`);
  }
  if (addrs.size === 0) return [];

  const out: string[] = [];
  for (const f of listFiles(path.join(repo, "src"), ".c")) {
    const lines = Deno.readTextFileSync(f).split("\n");
    for (let i = 0; i < lines.length; i++) {
      for (const a of addrs) {
        if (!lines[i].toUpperCase().includes(a)) continue;
        if (!/\b(IWRAM_DATA|EWRAM_DATA|extern)\b/.test(lines[i])) continue;
        out.push(`${a}  ${path.relative(repo, f)}:${i + 1}  ${lines[i].trim()}`);
      }
    }
  }
  return [...new Set(out)].sort();
};

// 宣言/定義の行。呼び出し文 (`  Foo(x);`) と区別するため、行頭から始まり、名前の前に
// 少なくとも1トークン (戻り値の型) があることを求める
const declRe = (fn: string): RegExp => new RegExp(`^[A-Za-z_][\\w *]*[\\s*]${fn}\\s*\\(`);

// .c が (再帰的に) include しているヘッダを集める
const includedHeaders = (repo: string, srcFile: string): Set<string> => {
  const seen = new Set<string>();
  const visit = (file: string) => {
    let text: string;
    try {
      text = Deno.readTextFileSync(file);
    } catch {
      return;
    }
    for (const m of text.matchAll(/^#include\s+"([^"]+)"/gm)) {
      const h = path.join(repo, "include", m[1]);
      if (seen.has(h)) continue;
      seen.add(h);
      visit(h);
    }
  };
  visit(srcFile);
  return seen;
};

type Decl = { file: string; line: number; text: string };

const findDecl = (files: string[], fn: string): Decl | null => {
  const re = declRe(fn);
  for (const f of files) {
    const lines = Deno.readTextFileSync(f).split("\n");
    for (let i = 0; i < lines.length; i++) {
      if (re.test(lines[i])) return { file: f, line: i + 1, text: lines[i].trim().slice(0, 160) };
    }
  }
  return null;
};

// 呼び先の宣言を引き、対象関数の位置から見えているかを確かめる
const resolveCallees = (repo: string, srcFile: string, targetLine: number, callees: string[]): string[] => {
  const headers = listFiles(path.join(repo, "include"), ".h");
  const sources = listFiles(path.join(repo, "src"), ".c");
  const visible = includedHeaders(repo, srcFile);
  const out: string[] = [];

  for (const fn of callees) {
    const inHeader = findDecl(headers, fn);
    const inSelf = findDecl([srcFile], fn);
    const inOther = inHeader || inSelf ? null : findDecl(sources, fn);
    const decl = inHeader ?? inSelf ?? inOther;

    out.push(decl === null ? `${fn}  (宣言が見つかりません)` : `${fn}  ${path.relative(repo, decl.file)}:${decl.line}  ${decl.text}`);

    // 見えているか: 同じ .c で対象より前にあるか、include 済みのヘッダにあるか
    if (inSelf !== null && inSelf.line < targetLine) continue;
    if (inHeader !== null && visible.has(inHeader.file)) continue;

    if (inHeader !== null) {
      out.push(`  → #include "${path.relative(path.join(repo, "include"), inHeader.file)}" が要ります`);
    } else if (inSelf !== null) {
      out.push(`  → 同じ .c の ${inSelf.line} 行目で、対象 (${targetLine} 行目) より後ろです。前方宣言が要ります`);
    } else {
      out.push(`  → 前方宣言が要ります`);
    }
  }
  return out;
};

// 同じ .c にある一致済み関数のうち、同じ呼び先を使っているものを挙げる
const findSiblings = (repo: string, srcFile: string, fn: string, callees: string[]): string[] => {
  if (callees.length === 0) return [];
  const lines = Deno.readTextFileSync(srcFile).split("\n");
  const out: string[] = [];
  let start = -1;
  let name = "";
  let depth = 0;
  let entered = false;

  for (let i = 0; i < lines.length; i++) {
    if (!entered) {
      const m = lines[i].match(/^([A-Za-z_][\w* ]*?)\b(\w+)\s*\(/);
      if (m && !/^(NAKED|NON_MATCH|static_assert|typedef|if|for|while|switch|return)\b/.test(lines[i])) {
        start = i;
        name = m[2];
      }
    }
    for (const ch of lines[i]) {
      if (ch === "{") {
        depth++;
        entered = true;
      } else if (ch === "}") depth--;
    }
    if (entered && depth === 0) {
      if (start >= 0 && name !== fn && !callees.includes(name)) {
        const body = lines.slice(start, i + 1).join("\n");
        const hits = callees.filter((c) => body.includes(c));
        if (hits.length > 0) out.push(`${path.relative(repo, srcFile)}:${start + 1}  ${name}  (${hits.join(", ")} を呼ぶ)`);
      }
      entered = false;
      start = -1;
      name = "";
    }
  }
  return out.slice(0, 8);
};

// リポジトリの構造体宣言からオフセット表を作る。
// この repo はフィールドごとに `/* 0x1D8 */` / `// 0x04` と実オフセットを書いてあるので、それを拾う。
const repoTypeFields = (repo: string, typeName: string): { offset: number; text: string }[] => {
  const files = [...listFiles(path.join(repo, "include"), ".h"), ...listFiles(path.join(repo, "src"), ".c")];
  const endRe = new RegExp(`^\\}\\s*${typeName}\\s*;`);
  const openRe = new RegExp(`^(typedef\\s+)?struct\\b.*\\{`);

  for (const f of files) {
    const lines = Deno.readTextFileSync(f).split("\n");
    const end = lines.findIndex((l) => endRe.test(l.trim()));
    if (end < 0) continue;
    let start = end;
    while (start > 0 && !openRe.test(lines[start].trim())) start--;

    let body = lines.slice(start, end + 1);
    // ENEMY_HDR のようなマクロで本体が別にある場合はその定義も取り込む
    const hdr = body.join("\n").match(/\b(\w+_HDR)\b/);
    if (hdr) {
      for (const g of files) {
        const gl = Deno.readTextFileSync(g).split("\n");
        const di = gl.findIndex((l) => l.startsWith(`#define ${hdr[1]}`));
        if (di < 0) continue;
        let j = di;
        const macro: string[] = [];
        while (j < gl.length) {
          macro.push(gl[j]);
          if (!gl[j].trimEnd().endsWith("\\")) break;
          j++;
        }
        body = [...macro, ...body];
        break;
      }
    }

    const fields: { offset: number; text: string }[] = [];
    for (const line of body) {
      const comment = line.match(/(?:\/\*|\/\/)\s*(0x[0-9A-Fa-f]+)/);
      if (!comment) continue;
      fields.push({ offset: Number(comment[1]), text: line.trim().replace(/\s+\\$/, "") });
    }
    if (fields.length > 0) return fields.sort((a, b) => a.offset - b.offset);
  }
  return [];
};

// asm に出てきたオフセットを構造体のフィールドに割り当てる
const resolveOffsets = (repo: string, typeNames: string[], offsets: number[]): string[] => {
  const tables = typeNames.map((n) => ({ name: n, fields: repoTypeFields(repo, n) })).filter((t) => t.fields.length > 0);
  if (tables.length === 0) return [];

  const out: string[] = [];
  for (const off of offsets) {
    const hex = `0x${off.toString(16).toUpperCase()}`;

    // ぴったり合うフィールドがある型だけを出す。無いときだけ手前のフィールドからの差分を出す
    const exact = tables.flatMap((t) => {
      const f = t.fields.find((f) => f.offset === off);
      return f ? [`${t.name}  ${f.text}`] : [];
    });
    const hits = exact.length > 0 ? exact : tables.flatMap((t) => {
      const below = [...t.fields].reverse().find((f) => f.offset < off);
      // 何十バイトも手前のフィールドを持ち出しても意味がないので近いものだけ
      return below && off - below.offset <= 64 ? [`${t.name}  ${below.text}   (+${off - below.offset})`] : [];
    }).slice(0, 2);

    if (hits.length > 0) out.push(`${hex.padEnd(7)} ${hits.join("\n        ")}`);
    else out.push(`${hex.padEnd(7)} (該当なし — 未定義の領域)`);
  }
  return out;
};

// --------------------------------------------------------------------------
// Ghidra
// --------------------------------------------------------------------------

const ghidraGet = async (endpoint: string): Promise<string | null> => {
  try {
    const res = await fetch(`${GHIDRA}/${endpoint}`, { signal: AbortSignal.timeout(15000) });
    if (!res.ok) return null;
    const text = (await res.text()).trim();
    return text.length > 0 && !text.startsWith("Error") ? text : null;
  } catch {
    return null;
  }
};

const ghidraAddress = async (fn: string): Promise<string | null> => {
  const text = await ghidraGet(`search_functions?name_pattern=${fn}&limit=10`);
  if (text === null) return null;
  for (const line of text.split("\n")) {
    const m = line.match(/^(\S+)\s+@\s+([0-9a-fA-F]+)/);
    if (m && m[1] === fn) return `0x${m[2]}`;
  }
  return null;
};

// シグネチャと decompile に出てくる型名を集め、Ghidra のレイアウトを引く
const ghidraTypes = async (texts: string[]): Promise<string[]> => {
  const names = new Set<string>();
  for (const t of texts) {
    for (const m of t.matchAll(/\b([A-Z]\w{2,})\b/g)) {
      if (!PRIMITIVES.has(m[1])) names.add(m[1]);
    }
  }
  const out: string[] = [];
  for (const n of [...names].slice(0, 8)) {
    const layout = await ghidraGet(`get_struct_layout?struct_name=${n}`);
    if (layout !== null && layout.includes("Offset")) out.push(layout);
  }
  return out;
};

// --------------------------------------------------------------------------

const m2cDecompile = (fn: string, asmText: string): string | null => {
  const which = new Deno.Command("sh", { args: ["-c", "command -v m2c"] }).outputSync();
  if (!which.success) return null;
  const tmp = Deno.makeTempFileSync({ suffix: ".s" });
  try {
    Deno.writeTextFileSync(tmp, `.syntax unified\n.text\n\tthumb_func_start ${fn}\n${fn}:\n${asmText}`);
    const r = new Deno.Command("m2c", { args: ["--target", "gba", "-f", fn, tmp] }).outputSync();
    return new TextDecoder().decode(r.stdout);
  } finally {
    Deno.removeSync(tmp);
  }
};

const context = async (repo: string, fn: string, srcArg?: string, asmArg?: string, useGhidra = true, brief = false) => {
  const srcFile = srcArg ? path.resolve(srcArg) : findSrcFile(repo, fn);
  const asmFile = asmArg ? path.resolve(asmArg) : path.join(repo, "asm", "func", `${fn}.inc`);
  try {
    if (!Deno.statSync(asmFile).isFile) die(`アセンブリが見つかりません: ${asmFile}`);
  } catch {
    die(`アセンブリが見つかりません: ${path.relative(repo, asmFile)} (もう MATCHING になっていませんか)`);
  }

  const asm = readAsm(asmFile);
  const sig = findSignature(srcFile, fn);

  hr(`TARGET ASSEMBLY: ${path.relative(repo, asmFile)}`);
  console.log(asm.code.join("\n"));

  if (asm.pool.length > 0) {
    console.log(`\n--- プール定数 ---`);
    console.log(asm.pool.join("\n"));
  }

  const globals = resolveGlobals(repo, asm.pool, asm.code);
  if (globals.length > 0) {
    console.log(`\n--- プール定数の引き当て ---`);
    console.log(globals.join("\n"));
  }
  console.log();

  hr("SIGNATURE");
  if (sig) console.log(`${path.relative(repo, srcFile)}:${sig.line}  [${sig.level}]  ${sig.text.trim()}`);
  else console.log(`(${fn} の宣言が ${path.relative(repo, srcFile)} に見つかりませんでした)`);
  console.log();

  // Ghidra があれば型付きの decompile と構造体レイアウトを出す
  let ghidraDecomp: string | null = null;
  if (useGhidra) {
    const addr = await ghidraAddress(fn);
    if (addr !== null) {
      ghidraDecomp = await ghidraGet(`decompile_function?address=${addr}`);
      const proto = await ghidraGet(`get_function_by_address?address=${addr}`);
      if (ghidraDecomp !== null) {
        hr(`GHIDRA DECOMPILE: ${addr}`);
        if (proto !== null) console.log(`${proto}\n`);
        console.log(ghidraDecomp);
        console.log();
      }
    }
  }

  // asm のオフセットをリポジトリの構造体宣言に割り当てる。repo のほうが Ghidra より新しいことが多いので repo を優先する
  const names = typeNames([sig?.text ?? "", ghidraDecomp ?? ""]);
  const resolved = !brief && asm.offsets.length > 0 ? resolveOffsets(repo, names, asm.offsets) : [];
  if (resolved.length > 0) {
    hr("OFFSETS IN THE ASM");
    console.log(resolved.join("\n"));
    console.log();
  } else if (!brief && asm.offsets.length > 0) {
    // 型が引けなかったときだけ Ghidra のレイアウトをそのまま出す
    const layouts = useGhidra ? await ghidraTypes([sig?.text ?? "", ghidraDecomp ?? ""]) : [];
    hr("OFFSETS IN THE ASM");
    console.log(asm.offsets.map((o) => `0x${o.toString(16).toUpperCase()}`).join("  "));
    if (layouts.length > 0) console.log(`\n${layouts.join("\n\n")}`);
    console.log();
  }

  if (asm.callees.length > 0) {
    hr("CALLEES");
    console.log(resolveCallees(repo, srcFile, sig?.line ?? 0, asm.callees).join("\n"));
    console.log();

    const siblings = brief ? [] : findSiblings(repo, srcFile, fn, asm.callees);
    if (siblings.length > 0) {
      hr("SIBLINGS (同じ .c で同じ関数を呼んでいる一致済みの関数)");
      console.log(siblings.join("\n"));
      console.log();
    }
  }

  if (sig?.level === "NON_MATCH") {
    hr(`CURRENT C: ${path.relative(repo, srcFile)}`);
    console.log(extractBlock(srcFile, fn));
  } else if (ghidraDecomp === null) {
    // Ghidra が使えないときだけ m2c にフォールバックする
    const m2c = m2cDecompile(fn, Deno.readTextFileSync(asmFile));
    hr("CURRENT C (m2c)");
    if (m2c === null) {
      console.log("(m2c も Ghidra も使えません。 uv tool install git+https://github.com/matt-kempster/m2c.git)");
    } else {
      console.log(m2c);
    }
  }
};

if (import.meta.main) main();
