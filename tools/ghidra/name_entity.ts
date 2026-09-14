#!/usr/bin/env -S deno run --allow-read --allow-run --allow-net --allow-env

import { Command } from "@cliffy/command";
import { dirname, fromFileUrl, join } from "@std/path";
import * as gba from "../common/gba/gba.ts";
import { disassembleFunction, type Instruction } from "./api/function.ts";
import { resolveAddress, symbolsByAddress } from "./common.ts";

// CreateEntity を呼ぶ関数 (EntityXXXX_Create) のアドレスを受け取り、そこから Init / Update / Destroy を見つけて
// 4つまとめて EntityXXXX_Create / _Init / _Update / _Destroy にリネームする (リポジトリと Ghidra の両方)。
// Entity の名前は --sub があれば Entity${SubroutineID} (4桁大文字)、なければ Entity${Create のアドレス} (8桁小文字)。
//
// Create は次の形をしている前提で、形が違えば何もせず終了する:
//   bl CreateEntity / ... / ldr r1, =Update / ldr r2, =Destroy / bl SetEntityRoutine / ... / bl Init
//
// e.g. tools/ghidra/name_entity.ts 0x08013B68
// e.g. tools/ghidra/name_entity.ts FUN_08089a2c --sub 28CB --dry-run

const REPO_ROOT = join(dirname(fromFileUrl(import.meta.url)), "../..");
const ROM_BASE = 0x08000000;

// ROM のワードを baserom.gba から読む (ldr rN, [pc] のプールの値)
const readRomWord = (rom: Uint8Array, addr: number): number => {
  const off = addr - ROM_BASE;
  if (off < 0 || off + 4 > rom.length) throw new Error(`0x${gba.toHex32(addr)} は ROM の範囲外です`);
  return new DataView(rom.buffer, rom.byteOffset + off, 4).getUint32(0, true);
};

// "bl 0x08230bf8" の呼び先
const blTarget = (insn: Instruction): number | undefined => {
  if (insn.mnemonic !== "bl") return undefined;
  const m = insn.operands.match(/^0x([0-9A-Fa-f]+)$/);
  return m ? parseInt(m[1], 16) : undefined;
};

// "r1,[0x08013b98]" のプールのアドレス
const ldrPool = (insn: Instruction, reg: string): number | undefined => {
  if (insn.mnemonic !== "ldr") return undefined;
  const m = insn.operands.match(/^(r\d+),\[0x([0-9A-Fa-f]+)\]$/);
  return m && m[1] === reg ? parseInt(m[2], 16) : undefined;
};

// Create の命令列から Init / Update / Destroy のアドレスを探す
const findMethods = (insns: Instruction[], rom: Uint8Array): { init: number; update: number; destroy: number } => {
  const createEntity = resolveAddress("CreateEntity");
  const setEntityRoutine = resolveAddress("SetEntityRoutine");

  const ci = insns.findIndex((i) => blTarget(i) === createEntity);
  if (ci < 0) throw new Error("CreateEntity を呼んでいません");
  const si = insns.findIndex((i, idx) => idx > ci && blTarget(i) === setEntityRoutine);
  if (si < 0) throw new Error("CreateEntity の後に SetEntityRoutine を呼んでいません");

  // SetEntityRoutine の直前で r1 (Update), r2 (Destroy) にプールから読み込んでいるはず
  let update: number | undefined;
  let destroy: number | undefined;
  for (let i = si - 1; i > ci && (update === undefined || destroy === undefined); i--) {
    update ??= ldrPool(insns[i], "r1");
    destroy ??= ldrPool(insns[i], "r2");
  }
  if (update === undefined || destroy === undefined) throw new Error("SetEntityRoutine に渡す r1 / r2 をプールから読んでいません");

  const init = insns.slice(si + 1).map(blTarget).find((t) => t !== undefined);
  if (init === undefined) throw new Error("SetEntityRoutine の後に Init を呼んでいません");

  // プールの値は Thumb の関数ポインタなので最下位ビットを落とす
  return { init, update: readRomWord(rom, update) & ~1, destroy: readRomWord(rom, destroy) & ~1 };
};

const main = () => {
  new Command()
    .name("name_entity.ts")
    .description("EntityXXXX_Create から Init / Update / Destroy を見つけ、4つを EntityXXXX_* にリネームする。")
    .argument("<create:string>", "CreateEntity を呼ぶ関数のROMアドレスまたはシンボル名")
    .option("--sub <id:string>", "VM の Subroutine ID (16進数)。指定すると Entity${ID} (4桁大文字) という名前にする。")
    .option("--dry-run", "リネーム案を表示するだけで、リネームはしない。")
    .action(async (opts, target) => {
      const create = resolveAddress(target);

      let entity: string;
      if (opts.sub !== undefined) {
        if (!/^(0x)?[0-9A-Fa-f]{1,4}$/.test(opts.sub)) {
          console.error(`エラー: --sub には4桁以内の16進数を指定してください: ${opts.sub}`);
          Deno.exit(1);
        }
        entity = `Entity${opts.sub.replace(/^0x/i, "").toUpperCase().padStart(4, "0")}`;
      } else {
        entity = `Entity${create.toString(16).padStart(8, "0")}`;
      }

      let methods: { init: number; update: number; destroy: number };
      try {
        const rom = Deno.readFileSync(join(REPO_ROOT, "baserom.gba"));
        methods = findMethods(await disassembleFunction(create), rom);
      } catch (e) {
        console.error(`エラー: 0x${gba.toHex32(create)} を Create として解析できません: ${e instanceof Error ? e.message : String(e)}`);
        Deno.exit(1);
      }

      const plan: [number, string][] = [
        [create, `${entity}_Create`],
        [methods.init, `${entity}_Init`],
        [methods.update, `${entity}_Update`],
        [methods.destroy, `${entity}_Destroy`],
      ];

      // リネームは boktai2.sym の名前 (リポジトリ側の名前) を旧名として行う
      const syms = symbolsByAddress();
      const taken = new Set(syms.values());
      const renames: [string, string][] = [];
      let ng = false;
      for (const [addr, newName] of plan) {
        const oldName = syms.get(addr);
        if (oldName === newName) {
          console.log(`${oldName} (リネーム済み)`);
          continue;
        }
        if (!oldName) {
          console.error(`エラー: 0x${gba.toHex32(addr)} が boktai2.sym にありません`);
          ng = true;
        } else if (!oldName.startsWith("FUN_")) {
          console.error(`エラー: ${oldName} はすでに名前が付いています (${newName} にはしません)`);
          ng = true;
        } else if (taken.has(newName)) {
          console.error(`エラー: ${newName} はすでに別の関数の名前です`);
          ng = true;
        } else {
          console.log(`${oldName} -> ${newName}`);
          renames.push([oldName, newName]);
        }
      }
      if (ng) Deno.exit(1);
      if (opts.dryRun || renames.length === 0) return;

      for (const [oldName, newName] of renames) {
        // make clean-code の案内は最後に1度だけ出すので、--quiet で個々のリネームでは出さない
        const { success } = new Deno.Command(join(REPO_ROOT, "tools/rename_with_ghidra.sh"), {
          args: ["--quiet", oldName, newName],
          cwd: REPO_ROOT,
          stdout: "inherit",
          stderr: "inherit",
        }).outputSync();
        if (!success) {
          console.error(`エラー: ${oldName} -> ${newName} のリネームに失敗したので中断します`);
          Deno.exit(1);
        }
      }
      console.log("make で undefined reference が出たら make clean-code してください");
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
