#!/usr/bin/env -S deno run --allow-read --allow-run --allow-env

import { Command } from "@cliffy/command";
import * as path from "@std/path";

// e.g. .claude/skills/decomp-func/scripts/residual.ts
// e.g. .claude/skills/decomp-func/scripts/residual.ts src/door.c
const main = () => {
  new Command()
    .name("residual.ts")
    .description(
      "NON_MATCH の関数が原典からどれだけ離れているかを一括で測る。NONMATCHING_C を有効にして全体をビルドし、関数ごとに streamdiff を回して差分の塊 (hunk) の数と行数を出す。hunk が少ないものほど再挑戦が安い",
    )
    .argument("[files...:string]", "対象の .c (省略時は src/ 全体)")
    .action((_opts, ...targets: string[]) => {
      residual(getRepoRoot(), targets);
    })
    .parse(Deno.args);
};

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const run = (cmd: string, args: string[]): { code: number; out: string } => {
  const r = new Deno.Command(cmd, { args, stderr: "piped" }).outputSync();
  return {
    code: r.code,
    out: new TextDecoder().decode(r.stdout) + new TextDecoder().decode(r.stderr),
  };
};

const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};

const nproc = (): string => {
  for (const [cmd, args] of [["nproc", []], ["sysctl", ["-n", "hw.ncpu"]]] as const) {
    try {
      const r = new Deno.Command(cmd, { args: [...args] }).outputSync();
      if (r.code === 0) return new TextDecoder().decode(r.stdout).trim();
    } catch { /* そのコマンドが無い環境 */ }
  }
  return "4";
};

const listCFiles = (root: string, targets: string[]): string[] => {
  if (targets.length > 0) {
    return targets.map((t) => path.relative(root, path.resolve(t)));
  }
  const acc: string[] = [];
  const walk = (dir: string) => {
    for (const e of Deno.readDirSync(path.join(root, dir))) {
      const rel = path.join(dir, e.name);
      if (e.isDirectory) walk(rel);
      else if (e.name.endsWith(".c")) acc.push(rel);
    }
  };
  walk("src");
  return acc.sort();
};

type Row = {
  status: "OK" | "OBJ_MISSING" | "INC_MISSING" | "ERR";
  fn: string;
  file: string;
  hunks?: number;
  lines?: number;
  mine?: number;
  orig?: number;
  note?: string;
};

const measure = (root: string, file: string, fn: string): Row => {
  const obj = path.join("build/boktai2", file.replace(/\.c$/, ".o"));
  const inc = `asm/func/${fn}.inc`;
  if (!existsSync(path.join(root, obj))) return { status: "OBJ_MISSING", fn, file };
  if (!existsSync(path.join(root, inc))) return { status: "INC_MISSING", fn, file };

  const { out } = run(".claude/skills/decomp-func/scripts/streamdiff.py", [obj, fn, inc]);
  const head = out.split("\n")[0] ?? "";
  const m = head.match(/^(\d+) insns \(yours\) vs (\d+)/);
  if (!m) return { status: "ERR", fn, file, note: head.slice(0, 80) };

  return {
    status: "OK",
    fn,
    file,
    hunks: (out.match(/^--- /gm) ?? []).length,
    lines: (out.match(/^ {2}[MT] /gm) ?? []).length,
    mine: Number(m[1]),
    orig: Number(m[2]),
  };
};

const existsSync = (p: string): boolean => {
  try {
    Deno.statSync(p);
    return true;
  } catch {
    return false;
  }
};

const residual = (root: string, targets: string[]) => {
  Deno.chdir(root);

  // NONMATCHING_C ブロックの中身は古くなっていることがあり、コンパイルが通らない
  // ファイルが出る。-k で続行し、そのファイルの関数は OBJ_MISSING として報告する
  console.error("--- make -k EXTRA_CPPFLAGS=-DNONMATCHING_C");
  run("make", ["clean-code"]);
  run("make", ["-k", `-j${nproc()}`, "EXTRA_CPPFLAGS=-DNONMATCHING_C"]);

  const rows: Row[] = [];
  for (const file of listCFiles(root, targets)) {
    if (!existsSync(file)) die(`no such file: ${file}`);
    const txt = Deno.readTextFileSync(file);
    for (const m of txt.matchAll(/^NON_MATCH\b[^(\n]*?([A-Za-z_]\w*)\s*\(/gm)) {
      rows.push(measure(root, file, m[1]));
    }
  }

  const ok = rows.filter((r): r is Row & { hunks: number } => r.status === "OK");
  const bad = rows.filter((r) => r.status !== "OK");
  console.log(`NON_MATCH: ${rows.length}  measured: ${ok.length}  unmeasurable: ${bad.length}`);
  console.log();
  console.log("hunks\tlines\tinsns\tfunction\tfile");
  ok.sort((a, b) => a.hunks - b.hunks || a.lines! - b.lines!);
  for (const r of ok) {
    console.log(`${r.hunks}\t${r.lines}\t${r.mine}/${r.orig}\t${r.fn}\t${r.file}`);
  }
  if (bad.length > 0) {
    console.log();
    for (const r of bad) console.log(`${r.status}\t${r.fn}\t${r.file}\t${r.note ?? ""}`);
  }

  // フラグ付きのオブジェクトを build/ に残すと、次の make compare が嘘をつく
  run("make", ["clean-code"]);
  console.error("\n(build/ は掃除しました。次のビルドはやり直しになります)");
};

main();
