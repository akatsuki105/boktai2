#!/usr/bin/env -S deno run --allow-read --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";

// e.g. .claude/skills/decomp-func/scripts/census.ts src/enemy_080ef84c.c
// e.g. .claude/skills/decomp-func/scripts/census.ts src/enemy_manager.c src/enemy_080ef84c.c
// e.g. .claude/skills/decomp-func/scripts/census.ts src/**/*.c
const main = () => {
  new Command()
    .name("census.ts")
    .description("未一致関数 (NAKED / NON_MATCH) の関数をサイズ昇順で列挙する。出力は TSV: size<TAB>level<TAB>name<TAB>inc_path")
    .argument("<files...:string>", "探索対象の .c のパス (glob で複数渡せる)")
    .action((_opts, ...targets: string[]) => {
      census(getRepoRoot(), targets);
    })
    .parse(Deno.args);
};

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const resolveCFile = (target: string): string => {
  const abs = path.isAbsolute(target) ? target : path.resolve(target);
  let stat: Deno.FileInfo;
  try {
    stat = Deno.statSync(abs);
  } catch {
    die(`見つかりません: ${target}`);
  }
  if (!stat!.isFile) die(`.c のパスを渡してください (ディレクトリは不可): ${target}`);
  if (path.extname(abs) !== ".c") die(`.c ではありません: ${target}`);
  return abs;
};

const incRe = /INCFUNC\("(asm\/func\/[^"]+\.inc)"\)/;
// 型は複数トークンになりうる (`NAKED EntityD854Node* Foo(`) ので、`(` の直前の識別子を関数名とする
const defRe = /^(NAKED|NON_MATCH)\s+[^()]*?(\w+)\s*\(/;

type Level = "NAKED" | "NON_MATCH";

// 関数名 -> レベルと inc の相対パス
const collectTargets = (files: string[]): Map<string, { level: Level; inc: string }> => {
  const targets = new Map<string, { level: Level; inc: string }>();

  for (const file of files) {
    let pending: string | null = null; // #else の INCFUNC を待っている NON_MATCH 関数
    let inElse = false;

    for (const line of Deno.readTextFileSync(file).split("\n")) {
      const s = line.trim();

      const def = s.match(defRe);
      if (def) {
        if (def[1] === "NAKED") {
          // NAKED は同じ行に INCFUNC がある
          const inc = s.match(incRe);
          if (inc) targets.set(def[2], { level: "NAKED", inc: inc[1] });
        } else {
          pending = def[2];
          inElse = false;
        }
        continue;
      }

      if (pending === null) continue;
      if (s === "#else") {
        inElse = true;
      } else if (s === "#endif") {
        pending = null;
        inElse = false;
      } else if (inElse) {
        const inc = s.match(incRe);
        if (inc) {
          targets.set(pending, { level: "NON_MATCH", inc: inc[1] });
          pending = null;
          inElse = false;
        }
      }
    }
  }

  return targets;
};

// inc ファイルの命令行からバイトサイズを推定する
const estimateSize = (incPath: string): number => {
  let est = 0;
  for (const line of Deno.readTextFileSync(incPath).split("\n")) {
    const s = line.trim();
    if (!s || s.endsWith(":")) continue;
    if (/^(@|\.align|\.include|\.syntax|\.text|\.thumb|thumb_func|arm_func)/.test(s)) continue;
    if (s.startsWith(".4byte")) est += 4;
    else if (s.startsWith(".short") || s.startsWith(".2byte")) est += 2;
    else if (s.startsWith(".byte")) est += 1;
    else if (!s.startsWith(".")) est += 2;
  }
  return est;
};

const census = (repo: string, targets: string[]) => {
  const files = [...new Set(targets.map(resolveCFile))].sort();

  const found = collectTargets(files);
  if (found.size === 0) die("対象関数が見つかりませんでした");

  const rows = [...found].map(([name, { level, inc }]) => {
    const incPath = path.join(repo, inc);
    let size = 0;
    try {
      size = estimateSize(incPath);
    } catch {
      size = 0; // inc が無い場合
    }
    return { size, level, name, inc };
  });

  rows.sort((a, b) => a.size - b.size || a.name.localeCompare(b.name));
  for (const r of rows) console.log(`${r.size}\t${r.level}\t${r.name}\t${r.inc}`);
  console.error(`# ${rows.length} functions remaining`);
};

const getRepoRoot = (): string => {
  const { stdout } = new Deno.Command("git", { args: ["rev-parse", "--show-toplevel"] }).outputSync();
  return new TextDecoder().decode(stdout).trim();
};

if (import.meta.main) main();
