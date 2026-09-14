#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run --allow-net --allow-env

import { Command } from "@cliffy/command";
import { dirname, fromFileUrl, join } from "@std/path";
import * as gba from "../common/gba/gba.ts";
import { decompileFunction } from "./api/function.ts";
import { saveProgram } from "./api/program.ts";
import { resolveAddress, symbolsByAddress } from "./common.ts";

// EntityXXXX_Create の CreateEntity(kind, size) から、Ghidra に構造体 EntityXXXX を作る。
// 中身は先頭の Entity e だけで、残りは未定義のまま。同名の型がすでにあれば何もしない。
// 作ったら、リポジトリに貼るための C の定義を標準出力に出す (リポジトリ自体は変更しない)。
// Create は先に tools/ghidra/name_entity.ts で EntityXXXX_Create という名前にしておくこと。
//
// e.g. tools/ghidra/create_entity_struct.ts Entity08013b68_Create
// e.g. tools/ghidra/create_entity_struct.ts 0x08013B68

const REPO_ROOT = join(dirname(fromFileUrl(import.meta.url)), "../..");
const ENTITY_SIZE = 0x18;

// include/entity.h の EntityKind のマクロ定数 (#define ENTITY_XXX N) を 名前 -> 値 で読む
// ENTITY_DISABLE_* は値が (1 << n) なのでここでは拾わない。種類の数の ENTITY_KINDS は除く。
const readEntityKinds = (): Map<string, number> => {
  const text = Deno.readTextFileSync(join(REPO_ROOT, "include/entity.h"));
  const kinds = new Map<string, number>();
  for (const m of text.matchAll(/^#define\s+(ENTITY_\w+)\s+(0x[0-9A-Fa-f]+|\d+)\b/gm)) {
    if (m[1] !== "ENTITY_KINDS") kinds.set(m[1], parseInt(m[2]));
  }
  return kinds;
};

// デコンパイル結果の CreateEntity の第1引数 (Ghidra の enum 名 UNK_9 か数値) を ENTITY_XXX に直す
const toKindName = (token: string, kinds: Map<string, number>): string | undefined => {
  if (/^(0x[0-9A-Fa-f]+|\d+)$/.test(token)) {
    const value = parseInt(token);
    return [...kinds].find(([, v]) => v === value)?.[0];
  }
  if (kinds.has(`ENTITY_${token}`)) return `ENTITY_${token}`;
  if (kinds.has(token)) return token;
  return undefined;
};

const toCDefinition = (name: string, kind: string, size: number): string => {
  const lines = ["typedef struct {", `  Entity e;  // ${kind}`];
  if (size > ENTITY_SIZE) lines.push(`  u8 unk_18[${size} - 0x18];`);
  lines.push(`} ${name};`, `static_assert(sizeof(${name}) == ${size});`);
  return lines.join("\n");
};

const main = () => {
  new Command()
    .name("create_entity_struct.ts")
    .description("EntityXXXX_Create の CreateEntity(kind, size) から Ghidra に構造体 EntityXXXX を作り、C の定義を出力する。")
    .argument("<create:string>", "EntityXXXX_Create のROMアドレスまたはシンボル名")
    .action(async (_opts, target) => {
      // 状況の報告は標準エラー出力に出し、標準出力は C の定義だけにする (そのままコピペできるように)
      const create = resolveAddress(target);
      const funcName = symbolsByAddress().get(create);
      const entity = funcName?.match(/^(Entity[0-9A-Za-z]+)_Create$/)?.[1];
      if (!entity) {
        console.error(`エラー: 0x${gba.toHex32(create)} (${funcName ?? "名前なし"}) は EntityXXXX_Create という名前ではありません`);
        Deno.exit(1);
      }

      let kind: string | undefined;
      let size: number;
      try {
        const code = await decompileFunction(create);
        const m = code.match(/CreateEntity\(\s*(\w+)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\)/);
        if (!m) throw new Error("CreateEntity(kind, size) が見つかりません");
        kind = toKindName(m[1], readEntityKinds());
        if (!kind) throw new Error(`CreateEntity の種類 ${m[1]} が include/entity.h の EntityKind にありません`);
        size = parseInt(m[2]);
      } catch (e) {
        console.error(`エラー: ${funcName} を解析できません: ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }

      const res = new Deno.Command(join(REPO_ROOT, "tools/ghidra/run_pyghidra_script.ts"), {
        args: [join(REPO_ROOT, "tools/ghidra/ghidra_scripts/create_entity_struct.py"), entity, String(size)],
        cwd: REPO_ROOT,
        stdout: "piped",
        stderr: "piped",
      }).outputSync();
      const out = new TextDecoder().decode(res.stdout);
      if (!res.success) {
        console.error(`エラー: Ghidra で構造体を作れませんでした:\n${out}${new TextDecoder().decode(res.stderr)}`);
        Deno.exit(1);
      }

      const exists = out.match(/^EXISTS (.+)$/m);
      if (exists) {
        console.error(`${entity} は Ghidra にすでにあるので何もしません (${exists[1]})`);
        return;
      }
      const created = out.match(/^CREATED (\S+) (\d+)$/m);
      if (!created || Number(created[2]) !== size) {
        console.error(`エラー: Ghidra の応答が想定と違います:\n${out}`);
        Deno.exit(1);
      }

      try {
        await saveProgram();
      } catch (e) {
        console.error(`エラー: 構造体は作りましたが保存に失敗しました: ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }
      console.error(`Ghidra に ${created[1]} (${size} バイト) を作って保存しました`);
      console.log(toCDefinition(entity, kind, size));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
