#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";

// デモ(イベント)スクリプトの3段テーブルを src/demo.c として書き出す。
//
// ROM 上は 0x08DAADB8-0x08DBD758 に、メッセージ本体 → ステップ → デモ → デモ表 の順で
// 隙間なく並んでいる。C でも同じ順に並べるので、宣言順がそのまま ROM の並びになる。
//
// e.g. ./tools/dumper/demo_script.ts ./baserom.gba > src/demo.c

const ROM_BASE = 0x08000000;
const REGION_START = 0x08daadb8; // メッセージ本体の先頭 = 領域全体の先頭
const ROOT = 0x08dbd564; // デモ表
const REGION_END = 0x08dbd758;

// FUN_080223f4 の第3引数を全登録元から拾ったもの
const CLASS_NAMES: Record<number, string> = {
  1: "CLS_BUS", // EntityMsgBus 自身 (デモ進行)
  2: "CLS_PLAYER", // CreatePlayer / LinkPlayer_Create
  3: "CLS_ENEMY", // Enemy*_Init 25種
  4: "CLS_BOSS", // Boss_Init_08022a70
  5: "CLS_ACTOR", // FUN_08044310 / FUN_080450c4 / FUN_08206434 ほか
  6: "CLS_CAMERA", // Camera_Init
  7: "CLS_FADE", // Entity730A_Init
  8: "CLS_SOUND", // EntityD3A9_Init
  9: "CLS_CBB0", // FUN_080b2410
  10: "CLS_ETC", // Entity28CB_Init / EntityE534_Init ほか
};

// cmd の意味は targetClass ごとに別。ハンドラを読んで確定しているものだけ名前を付ける。
const CMD_NAMES: Record<number, Record<number, string>> = {
  1: { 0: "BUS_EXEC_SCRIPT", 1: "BUS_WAIT", 2: "BUS_WAIT_EXT" },
};

type Msg = { addr: number; size: number; argc: number; args: number[] };
type Step = { addr: number; msgs: Msg[] };
type Demo = { addr: number; steps: Step[] };

const read = (rom: DataView) => {
  const u32 = (a: number) => rom.getUint32(a - ROM_BASE, true);
  const u16 = (a: number) => rom.getUint16(a - ROM_BASE, true);
  const u8 = (a: number) => rom.getUint8(a - ROM_BASE);
  const s16 = (a: number) => rom.getInt16(a - ROM_BASE, true);

  // NULL 終端のポインタ配列を読む
  const ptrList = (a: number): number[] => {
    const out: number[] = [];
    for (let p = a;; p += 4) {
      const v = u32(p);
      if (v === 0) break;
      out.push(v);
    }
    return out;
  };

  const demos: Demo[] = [];
  for (let i = 0; i < (REGION_END - ROOT) / 4; i++) {
    const demoAddr = u32(ROOT + i * 4);
    const steps: Step[] = [];
    for (const stepAddr of ptrList(demoAddr)) {
      const msgs: Msg[] = [];
      for (const msgAddr of ptrList(stepAddr)) {
        const argc = u8(msgAddr + 7);
        const args: number[] = [];
        // 実体サイズは 8 + ceil(argc/2)*4。argc が奇数のときの余り2バイトは常に 0
        const slots = Math.ceil(argc / 2) * 2;
        for (let j = 0; j < slots; j++) args.push(s16(msgAddr + 8 + j * 2));
        msgs.push({ addr: msgAddr, size: 8 + slots * 2, argc, args });
      }
      steps.push({ addr: stepAddr, msgs });
    }
    demos.push({ addr: demoAddr, steps });
  }

  // 3段が隙間なく並んでいることを確認する。ずれていたら黙って壊れた C を吐かないよう中断する。
  const all = demos.flatMap((d) => d.steps.flatMap((s) => s.msgs));
  const sorted = [...all].sort((a, b) => a.addr - b.addr);
  if (sorted[0].addr !== REGION_START) throw new Error("先頭のメッセージが 0x08DAADB8 ではありません");
  for (let i = 0; i + 1 < sorted.length; i++) {
    if (sorted[i].addr + sorted[i].size !== sorted[i + 1].addr) {
      throw new Error(`メッセージが連続していません: 0x${gba.toHex32(sorted[i].addr)}`);
    }
  }
  if (new Set(all.map((m) => m.addr)).size !== all.length) throw new Error("メッセージが共有されています");

  return { demos, u16, u8 };
};

const preamble = `#include "global.h"
#include "msgbus.h"

// デモ(イベント/カットシーン)スクリプト。EntityMsgBus がこれを読んで各エンティティにメッセージを配る。
// 構造は デモ表[demoID] -> デモ[step] -> ステップ[i] -> メッセージ の4段で、DemoTable_GetMsg が引く。
//
// ROM の並びが 段ごとのまとまり (メッセージ本体 -> ステップ -> デモ -> デモ表) なので、
// 1つのデモのデータはこのファイルの4箇所に分かれている。タイムラインとして読めるのは
// 最初の「メッセージ本体」の領域で、そこはデモ順・ステップ順に並んでいる。
//
// tools/dumper/demo_script.ts が baserom.gba から生成したもの。以降は手で名前を育ててよい。

// clang-format off

// ---- メッセージの実体 ----
// 可変長で、実体サイズは 8 + ceil(argc/2)*4。argc を偶数に丸めた6種を使い分ける。
// 実行時に見るときは EntityMsg* にキャストする。余りスロットは常に 0。

typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; }                DemoMsg0;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[2]; }   DemoMsg2;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[4]; }   DemoMsg4;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[6]; }   DemoMsg6;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[8]; }   DemoMsg8;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[10]; }  DemoMsg10;

// waitFlag: WAIT なら受け手が処理し終えるまで次のステップに進まない
#define NOWAIT 0
#define WAIT 1

// targetClass: 宛先の種別。EntityMsgBus_Register の第3引数と照合される
#define CLS_BUS 1
#define CLS_PLAYER 2
#define CLS_ENEMY 3
#define CLS_BOSS 4
#define CLS_ACTOR 5
#define CLS_CAMERA 6
#define CLS_FADE 7
#define CLS_SOUND 8
#define CLS_CBB0 9
#define CLS_ETC 10

// cmd の意味は targetClass ごとに別物。ハンドラを読んで確定したものだけ名前を付けてある
#define BUS_EXEC_SCRIPT 0  // Demo_CmdExecScript
#define BUS_WAIT 1         // Demo_CmdWait
#define BUS_WAIT_EXT 2     // Demo_CmdWaitExternal

#define M(x) (const EntityMsg*)&x
`;

const dump = (rom: DataView): string => {
  const { demos, u16, u8 } = read(rom);
  const out: string[] = [preamble];

  const msgName = (d: number, s: number, i: number) => `sMsg_d${d}_s${s}_${i}`;
  const stepName = (d: number, s: number) => `sStep_d${d}_s${s}`;
  const demoName = (d: number) => `sDemo_${d}`;

  // ---- 領域1: メッセージ本体 ----
  out.push(`\n/* ======== メッセージ本体 (0x${gba.toHex32(REGION_START)}-) ======== */\n`);
  demos.forEach((demo, di) => {
    out.push(`/* ================ demo ${di}  (${demo.steps.length} steps) ================ */`);
    demo.steps.forEach((step, si) => {
      out.push(`/* -- step ${si} -- */`);
      step.msgs.forEach((m, mi) => {
        const cls = CLASS_NAMES[u8(m.addr + 2)] ?? String(u8(m.addr + 2));
        const cmd = CMD_NAMES[u8(m.addr + 2)]?.[u8(m.addr + 6)] ?? String(u8(m.addr + 6));
        const wait = u8(m.addr + 3) ? "WAIT" : "NOWAIT";
        const args = m.args.length > 0 ? `, { ${m.args.join(", ")} }` : "";
        const ty = `DemoMsg${m.args.length}`;
        out.push(
          `static const ${ty.padEnd(9)} ${msgName(di, si, mi).padEnd(18)} = ` +
            `{ 0x${gba.toHex16(u16(m.addr))}, ${(cls + ",").padEnd(11)} ${(wait + ",").padEnd(7)} ` +
            `${u8(m.addr + 4)}, ${(cmd + ",").padEnd(16)} ${m.argc}${args} };`,
        );
      });
    });
  });

  // ---- 領域2: ステップ ----
  out.push(`\n/* ======== ステップ (0x${gba.toHex32(demos[0].steps[0].addr)}-) ======== */\n`);
  demos.forEach((demo, di) => {
    demo.steps.forEach((step, si) => {
      const items = step.msgs.map((_, mi) => `M(${msgName(di, si, mi)})`).join(", ");
      out.push(`static const EntityMsg* const ${stepName(di, si)}[] = { ${items}, NULL };`);
    });
  });

  // ---- 領域3: デモ ----
  out.push(`\n/* ======== デモ (0x${gba.toHex32(demos[0].addr)}-) ======== */\n`);
  demos.forEach((demo, di) => {
    const items = demo.steps.map((_, si) => stepName(di, si)).join(", ");
    out.push(`static const EntityMsg* const* const ${demoName(di)}[] = { ${items}, NULL };`);
  });

  // ---- 領域4: デモ表 ----
  out.push(`\n/* ======== デモ表 (0x${gba.toHex32(ROOT)}-) ======== */\n`);
  out.push(`const EntityMsg* const* const* const gDemoTable[${demos.length}] = {`);
  for (let i = 0; i < demos.length; i += 5) {
    out.push("    " + demos.slice(i, i + 5).map((_, j) => `${demoName(i + j)},`).join(" "));
  }
  out.push("};");
  out.push("\n// clang-format on");

  return out.join("\n") + "\n";
};

const main = () => {
  new Command()
    .name("demo_script.ts")
    .description("デモスクリプトの3段テーブルを src/demo.c として書き出す")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .action((_, romPath) => {
      const rom = new DataView(Deno.readFileSync(romPath).buffer);
      console.log(dump(rom));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
