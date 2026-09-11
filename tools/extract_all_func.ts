#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as path from "@std/path";
import { getRepoRoot } from "./common/common.ts";
import { listFunctions } from "./parser/common/gas.ts";

// extract_func.ts は thumb_func_start しか扱えないので、それ以外の種類の関数は対象外にする。
// (実際 asm/func/*.inc に arm の関数は1つも無い)
const EXTRACTABLE_KIND = "thumb";

const die = (msg: string): never => {
  console.error(msg);
  Deno.exit(1);
};

const isFile = (p: string): boolean => {
  try {
    return Deno.statSync(p).isFile;
  } catch (e) {
    if (e instanceof Deno.errors.NotFound) return false;
    throw e;
  }
};

// extract_func.ts を1関数ぶん実行する。成功なら null、失敗ならその出力を返す。
const runExtractFunc = (repo: string, fnName: string, asmRelPath: string): string | null => {
  const script = path.join(repo, "tools", "extract_func.ts");
  const { success, stdout, stderr } = new Deno.Command(Deno.execPath(), {
    args: ["run", "--allow-read", "--allow-write", "--allow-run", script, fnName, asmRelPath],
    cwd: repo,
  }).outputSync();

  if (success) return null;
  const decoder = new TextDecoder();
  return (decoder.decode(stdout) + decoder.decode(stderr)).trim();
};

const extractAllFunctions = (repo: string, asmFile: string): void => {
  const asmPath = path.resolve(repo, asmFile);
  if (!isFile(asmPath)) die(`エラー: ${asmPath} が見つかりません`);
  const asmRelPath = path.relative(repo, asmPath);

  const funcs = listFunctions(Deno.readTextFileSync(asmPath));
  if (funcs.length === 0) die(`エラー: ${asmRelPath} に関数が1つも見つかりませんでした`);

  const skipped = funcs.filter((fn) => fn.extracted);
  const unsupported = funcs.filter((fn) => !fn.extracted && fn.kind !== EXTRACTABLE_KIND);
  const targets = funcs.filter((fn) => !fn.extracted && fn.kind === EXTRACTABLE_KIND);

  console.log(`${asmRelPath}: 関数 ${funcs.length}件 (切り出し対象 ${targets.length}件, 切り出し済み ${skipped.length}件)`);
  for (const fn of unsupported) {
    console.log(`  スキップ: ${fn.name} (${fn.kind} は extract_func.ts が未対応)`);
  }

  // 1件ごとに extract_func.ts を実行する。extract_func.ts は毎回 .s/.inc を読み直すので、
  // 途中で失敗しても既に切り出した分はそのまま残り、あとで再実行すればスキップされる。
  const failures: string[] = [];
  for (const [i, fn] of targets.entries()) {
    const output = runExtractFunc(repo, fn.name, asmRelPath);
    const status = output === null ? "OK" : "失敗";
    console.log(`  [${i + 1}/${targets.length}] ${fn.name}: ${status}`);
    if (output !== null) failures.push(`  ${fn.name}:\n${output.split("\n").map((ln) => `    ${ln}`).join("\n")}`);
  }

  console.log(`完了: 切り出し ${targets.length - failures.length}件, スキップ ${skipped.length + unsupported.length}件, 失敗 ${failures.length}件`);
  if (failures.length > 0) {
    console.error(`\n失敗した関数:\n${failures.join("\n")}`);
    Deno.exit(1);
  }
};

const main = () => {
  new Command()
    .name("extract_all_func.ts")
    .description("引数で渡した .s/.inc ファイルの全部の関数に extract_func.ts を適用する (すでに適用されていたらスキップ)")
    .arguments("<asmFile:string>")
    .action((_, asmFile) => {
      extractAllFunctions(getRepoRoot(), asmFile);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
