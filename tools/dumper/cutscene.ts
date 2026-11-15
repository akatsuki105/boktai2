#!/usr/bin/env -S deno run --allow-read --allow-write

import { Command } from "@cliffy/command";
import { join } from "@std/path";
import * as gba from "../common/gba/gba.ts";
import { loadProgram } from "../bokvm/loader.ts";
import { SCRATCH, WORLD } from "../bokvm/memory.ts";
import { Tracer } from "../bokvm/trace.ts";
import { BokVM } from "../bokvm/vm.ts";

// カットシーンスクリプトの3段テーブルを, カットシーン1本につき1ファイル (src/data/cutscene/cNNN.h) として書き出す。
//
// ROM 上は 0x08DAADB8-0x08DBD758 に、メッセージ本体 → ステップ → カットシーン → カットシーン表 の順で
// 隙間なく並んでいる。ソースではカットシーンごとにまとめて書き, 段ごとに別の section
// (.rodata.cutscene_msg / _step / _list) に入れて, ld_script.ld で段の順に並べ直す。
// 同じ section の中は宣言順に積まれるので, cNNN.h を番号順に include すれば ROM と同じ並びになる。
//
// 宛先の名前 (TGT_*) は src/cutscene.c の #define から, 起動元のスクリプトは data/scripts/scripts.bokc から拾う。
// ステップ見出しの台詞は, 起動元スクリプトを bokvm (tools/bokvm) で実際に走らせて拾う (traceDialogueVM)。
// bokvm で追えないもの (起動元の switch が読めないもの) だけ, スクリプトの本文を順に読む推定 (traceDialogue) に戻す。
// 出力は clang-format の整形に任せる (1行に収まらない CUTSCENE の並びは clang-format が折り返す)。
//
// e.g. ./tools/dumper/cutscene.ts ./baserom.gba

const ROM_BASE = 0x08000000;
const REGION_START = 0x08daadb8; // メッセージ本体の先頭 = 領域全体の先頭
const ROOT = 0x08dbd564; // カットシーン表
const REGION_END = 0x08dbd758;

// targetClass ごとの本体マクロ (src/cutscene.c で定義)
const CLASS_MACROS: Record<number, string> = {
  1: "TO_BUS", // 決まった形に当てはまらないもの
  2: "TO_PLAYER",
  3: "TO_ENEMY",
  4: "TO_BOSS",
  5: "TO_ACTOR",
  6: "TO_CAMERA",
  7: "TO_EFFECT",
  8: "TO_SOUND",
  9: "TO_CBB0",
  10: "TO_ETC",
};

const CLS_BUS = 1;
const TGT_BUS = 0x4e69;

type Msg = { addr: number; size: number; argc: number; args: number[] };
type Step = { addr: number; msgs: Msg[] };
type Cutscene = { addr: number; steps: Step[] };

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

  const cutscenes: Cutscene[] = [];
  for (let i = 0; i < (REGION_END - ROOT) / 4; i++) {
    const cutsceneAddr = u32(ROOT + i * 4);
    const steps: Step[] = [];
    for (const stepAddr of ptrList(cutsceneAddr)) {
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
    cutscenes.push({ addr: cutsceneAddr, steps });
  }

  // 3段が隙間なく並んでいることを確認する。ずれていたら黙って壊れた C を吐かないよう中断する。
  const all = cutscenes.flatMap((d) => d.steps.flatMap((s) => s.msgs));
  const sorted = [...all].sort((a, b) => a.addr - b.addr);
  if (sorted[0].addr !== REGION_START) throw new Error("先頭のメッセージが 0x08DAADB8 ではありません");
  for (let i = 0; i + 1 < sorted.length; i++) {
    if (sorted[i].addr + sorted[i].size !== sorted[i + 1].addr) {
      throw new Error(`メッセージが連続していません: 0x${gba.toHex32(sorted[i].addr)}`);
    }
  }
  if (new Set(all.map((m) => m.addr)).size !== all.length) throw new Error("メッセージが共有されています");

  return { cutscenes, u16, u8 };
};


// src/cutscene.c の名前のついた命令の #define を読む
// #define NAME(target, a, b) TO_ACTOR(target, 3, a, b) は宛先を引数に取る形, #define NAME(a) TO_BOSS(TGT_X, 3, a) は宛先を固定した形
type NamedCmd = { name: string; cls: number; cmd: number; argc: number; target?: string };
const readNamedCmds = (path: string): NamedCmd[] => {
  const classOf = new Map(Object.entries(CLASS_MACROS).map(([k, v]) => [v, Number(k)]));
  const cmds: NamedCmd[] = [];
  for (const m of Deno.readTextFileSync(path).matchAll(/^#define (\w+)\(([\w, ]*)\) (TO_\w+)\((\w+), (\d+)[^)]*\)/gm)) {
    const cls = classOf.get(m[3]);
    if (cls === undefined) continue;
    const params = m[2].split(",").map((x) => x.trim()).filter((x) => x !== "");
    const byArg = params[0] === "target" && m[4] === "target";
    cmds.push({ name: m[1], cls, cmd: Number(m[5]), argc: byArg ? params.length - 1 : params.length, target: byArg ? undefined : m[4] });
  }
  return cmds;
};

// src/cutscene.c の #define TGT_XXX 0xNNNN を読む
const readTargetNames = (path: string): Map<number, string> => {
  const names = new Map<number, string>();
  for (const m of Deno.readTextFileSync(path).matchAll(/^#define (TGT_\w+) (0x[0-9A-Fa-f]+)/gm)) {
    names.set(parseInt(m[2], 16), m[1]);
  }
  return names;
};

type Starter = { script: string; p: string; e: string; c: string };

// scripts.bokc の Cmd_StartCutscene を拾い, カットシーンID -> 起動元の一覧にする
const readStarters = (path: string): Map<number, Starter[]> => {
  const starters = new Map<number, Starter[]>();
  let script = "";
  for (const line of Deno.readTextFileSync(path).split("\n")) {
    const def = line.match(/^(\w+)\(\) \{/);
    if (def) script = def[1];
    if (!line.includes("Cmd_StartCutscene")) continue;
    const d = line.match(/\.d = (?:\(u8\))?(\d+)/);
    if (!d) continue;
    const c = line.match(/\.c = (?:\(u8\))?(\d+)/)?.[1] ?? "";
    const p = line.match(/\.p = \[([^\]]*)\]/)?.[1] ?? "";
    const e = line.match(/\.e = (?:\(u24\))?(\w+)/)?.[1] ?? "";
    const pairs = [...p.matchAll(/\(u16\)(\d+), \(u24\)(\w+)/g)].map((m) => `${m[1]} -> ${m[2]}`).join(", ");
    const list = starters.get(Number(d[1])) ?? [];
    list.push({ script, p: pairs, e, c });
    starters.set(Number(d[1]), list);
  }
  return starters;
};

// include/constants/songs.h の #define NAME 123 を読む
const readSongNames = (path: string): Map<number, string> => {
  const names = new Map<number, string>();
  for (const m of Deno.readTextFileSync(path).matchAll(/^#define (\w+) (\d+)\b/gm)) {
    if (!names.has(Number(m[2]))) names.set(Number(m[2]), m[1]);
  }
  return names;
};

// data/scripts/strings.h の #define Str_XXXX 0xNNNN  // 本文 を読み, 本文を1行の台詞にする
const readStrings = (path: string): Map<string, string> => {
  const texts = new Map<string, string>();
  for (const m of Deno.readTextFileSync(path).matchAll(/^#define (Str_\w+) \S+\s*\/\/ (.*)$/gm)) {
    // <LABEL=X>名前</LABEL> は名前だけ残す, 名前が空ならラベルを捨てる, 主人公の名前 <NAME> は残してほかのタグは消す
    const text = m[2].replace(/<LABEL=[^>]*>([^<]*)<\/LABEL>/g, "$1").replace(/<(?!NAME>)[^>]*>/g, "").replace(/<\/?[A-Z]*…$/, "…").trim();
    texts.set(m[1], text);
  }
  return texts;
};

// SOUND の cmd のうち args[0] がサウンドID のもの (src/cutscene_sound.c のハンドラが呼ぶ関数で判断)
const SOUND_ID_CMDS = new Set([0, 1, 2, 6]);

// スクリプト1本の switch の case ごとの本文
type ScriptCases = Map<number, string[]>;

// scripts.bokc から "NAME() {" で始まるスクリプトの, 先頭の switch (..._STEP) の case を拾う
const readScriptCases = (lines: string[]): Map<string, ScriptCases> => {
  const scripts = new Map<string, ScriptCases>();
  let name = "";
  let cases: ScriptCases | undefined;
  let depth = 0;
  let switchDepth = -1;
  let current: string[] | undefined;
  for (const line of lines) {
    const def = line.match(/^(\w+)\(\) \{/);
    if (def) {
      name = def[1];
      cases = undefined;
      depth = 0;
      switchDepth = -1;
      current = undefined;
    }
    if (switchDepth < 0 && /^\tswitch \(\w*STEP\) \{/.test(line) && cases === undefined) {
      cases = new Map();
      scripts.set(name, cases);
      switchDepth = depth + 1;
    }
    const c = line.match(/^\t\tcase (\d+): \{/);
    if (cases !== undefined && switchDepth >= 0 && depth === switchDepth && c) {
      current = [];
      cases.set(Number(c[1]), current);
    } else if (current !== undefined && depth > switchDepth) {
      current.push(line.trim());
    }
    for (const ch of line) {
      if (ch === "{") depth++;
      if (ch === "}") depth--;
    }
    if (switchDepth >= 0 && depth < switchDepth) {
      switchDepth = -1;
      current = undefined;
    }
    if (depth <= switchDepth) current = undefined;
  }
  return scripts;
};

// case の本文を1行の要約にする, 台詞があれば台詞, なければ呼んでいるコマンドとスクリプト
const NOISE = /^(Cmd_SetHUDMode|Cmd_ResumeCutscene|Cmd_OpenMessageWindow|Scr_OpenMsgWindow|Scr_CloseMsgWindow)$/;
const summarizeCase = (body: string[], texts: Map<string, string>): string => {
  const said: string[] = [];
  for (const line of body) {
    for (const m of line.matchAll(/StringRef\((Str_\w+)\)/g)) said.push(texts.get(m[1]) ?? m[1]);
  }
  if (said.length > 0) return said.join(" / ");
  const calls: string[] = [];
  for (const line of body) {
    const m = line.match(/^(?:Command|Chara)\((\w+)/) ?? line.match(/^(Scr_\w+)\(/);
    if (m && !NOISE.test(m[1]) && !calls.includes(m[1])) calls.push(m[1]);
  }
  return calls.join(", ");
};

// traceDialogueVM で追えないときの代わり, スクリプトを走らせずに本文から推定する
// 各 BUS_EXEC_SCRIPT がスクリプトのどの case を走らせるかを追い, ステップごとの要約を返す
// case は呼ばれるたびに1つ進む。BUS_EXEC_SCRIPT で走った case がメッセージ窓などにコールバックを
// 渡していれば, 窓を閉じたときに次の case が走るので, Cmd_ResumeCutscene でカットシーンが
// 再開するまでの case をまとめて同じステップの出来事とみなす
const traceDialogue = (
  cutscene: Cutscene,
  ci: number,
  u16: (a: number) => number,
  u8: (a: number) => number,
  starter: Starter | undefined,
  scripts: Map<string, ScriptCases>,
  texts: Map<string, string>,
): Map<number, string> => {
  const notes = new Map<number, string>();
  if (starter === undefined) return notes;
  const keyToScript = new Map<number, string>();
  for (const m of starter.p.matchAll(/(\d+) -> (\w+)/g)) keyToScript.set(Number(m[1]), m[2]);
  const pointers = new Map<string, number>();
  cutscene.steps.forEach((step, si) => {
    for (const m of step.msgs) {
      if (u8(m.addr + 2) !== CLS_BUS || u16(m.addr) !== TGT_BUS || u8(m.addr + 6) !== 0 || m.argc !== 1) continue;
      const script = keyToScript.get(m.args[0] & 0xffff);
      const cases = script !== undefined ? scripts.get(script) : undefined;
      if (script === undefined || cases === undefined) continue;
      // 最初の呼び出しは Cmd_StartCutscene を含む case の次から
      if (!pointers.has(script)) {
        let start = -1;
        for (const [k, body] of cases) {
          if (body.some((l) => l.includes("Cmd_StartCutscene") && new RegExp(`\\.d = (?:\\(u8\\))?${ci}\\b`).test(l))) {
            start = k;
            break;
          }
        }
        if (start < 0) continue;
        pointers.set(script, start + 1);
      }
      let k = pointers.get(script)!;
      if (k < 0) continue;
      const parts: string[] = [];
      for (;;) {
        const body = cases.get(k);
        if (body === undefined) break;
        const summary = summarizeCase(body, texts);
        if (summary !== "") parts.push(summary);
        // 選択肢は選んだ結果で行き先が変わるので, ここから先は追わない
        if (body.some((l) => l.includes("Choice"))) {
          parts.push("(選択肢, 以降は追跡しない)");
          k = -1;
          break;
        }
        // S_..._STEP = N; は次の case を飛ばす
        const jump = body.map((l) => l.match(/^\w+_STEP = (\d+);$/)).find((m) => m !== null);
        k = jump ? Number(jump[1]) : k + 1;
        const resumes = body.some((l) => l.includes("Cmd_ResumeCutscene"));
        // メッセージ窓や Cmd_Delay の終わりに呼ぶスクリプトを渡していれば, それがまたこのスクリプトを呼んで次の case が走る
        const callsBack = body.some((l) => (l.includes("(u24)Scr_") && !l.includes("Cmd_StartCutscene") && !l.includes("Scr_Nop")) || l.startsWith(`${script}(`));
        if (resumes || !callsBack) break;
      }
      pointers.set(script, k);
      if (parts.length > 0) notes.set(si, parts.join(" / "));
    }
  });
  return notes;
};


// ---- bokvm で起動元スクリプトを実際に走らせて台詞を拾う ----
//
// 起動元スクリプトを Cmd_StartCutscene が走るまで呼び, そのあとはカットシーンの BUS_EXEC_SCRIPT ごとに
// キーに対応するスクリプトを呼ぶ。1回の呼び出しで渡されたコールバック (メッセージ窓を閉じたときに呼ぶスクリプトなど) が
// あればそれを続けて呼び, Cmd_ResumeCutscene でカットシーンが再開したところで区切る。
// 次のステップが BUS_WAIT_EXT ならカットシーンは再開を待っているので, コールバックが見えなくても
// (Cmd_Delay の .e の中など) 同じスクリプトをもう一度呼ぶ。選択肢は最初の項目を選んだものとして結果 0 を渡す。

// 起動に条件があるカットシーンの, 起動させるための状態 (gGameStateBuffer のオフセット, OR する値)
const START_STATE: Record<number, [number, number][]> = {
  13: [[WORLD + 0x000, 32]], // W_STORY_PROGRESS が 32..62
  34: [[WORLD + 0x179, 0x80]], // BIT(world + 0x179, 7)
  60: [[WORLD + 0x000, 23]], // Scr_GetKuroState() == 1
  61: [[WORLD + 0x000, 48]], // Scr_GetKuroState() == 2
  111: [[SCRATCH + 0x154, 1]], // S_UNK_154
  112: [[SCRATCH + 0x154, 2]],
  114: [[SCRATCH + 0x154, 1]],
  115: [[SCRATCH + 0x154, 2]],
};

type VMRun = { said: string[]; calls: string[]; callbacks: string[]; resumed: boolean; choice: boolean; ended: "" | "end" | "stop"; started: number[] };

// deno-lint-ignore no-explicit-any
const runScript = (vm: BokVM, program: any, lines: string[], name: string, owner: string, texts: Map<string, string>, argv: number[]): VMRun => {
  lines.length = 0;
  try {
    vm.execByID(program.resolveScript(name), { argc: argv.length, argv });
  } catch {
    // 止まったところまでの記録を使う
  }
  const r: VMRun = { said: [], calls: [], callbacks: [], resumed: false, choice: false, ended: "", started: [] };
  let depth = 0;
  for (const l of lines) {
    const t = l.trim();
    if (t.startsWith(">> ")) {
      depth++;
      continue;
    }
    if (t.startsWith("<< ")) {
      depth--;
      continue;
    }
    if (t.startsWith("//")) continue;
    for (const m of t.matchAll(/StringRef\((Str_\w+)\)/g)) r.said.push(texts.get(m[1]) ?? m[1]);
    if (t.includes("Cmd_ResumeCutscene")) r.resumed = true;
    // 自分を呼び直した先 (S_CUTSCENE_STEP を書き換えて自分を呼ぶ形) で終わることもあるので深さは見ない
    if (t.startsWith("Scr_EndCutscene(")) r.ended = "end";
    else if (t.startsWith("Command(Cmd_StopCutscene") && r.ended === "") r.ended = "stop";
    if (depth !== 1) continue; // ここから下は呼んだスクリプト自身の文だけ見る
    if (t.includes("Choice")) r.choice = true;
    const sc = t.match(/Cmd_StartCutscene, \.d = (?:\(u8\))?(\d+)/);
    if (sc) {
      r.started.push(Number(sc[1]));
      continue;
    }
    for (const m of t.matchAll(/\(u24\)(Scr_\w+)/g)) if (m[1] !== "Scr_Nop") r.callbacks.push(m[1]);
    const call = t.match(/^(?:Command|Chara)\((\w+)/) ?? t.match(/^(Scr_\w+)\(/);
    if (call && call[1] !== name && call[1] !== owner && !NOISE.test(call[1]) && !r.calls.includes(call[1])) r.calls.push(call[1]);
  }
  return r;
};

// 起動元を走らせて, ステップ番号 -> 要約 を返す, 起動元の switch が読めなければ undefined
const traceDialogueVM = (
  cutscene: Cutscene,
  ci: number,
  u16: (a: number) => number,
  u8: (a: number) => number,
  starter: Starter | undefined,
  romPath: string,
  scriptsText: string,
  scratchHeader: string,
  texts: Map<string, string>,
): Map<number, string> | undefined => {
  if (starter === undefined) return undefined;
  const keyToScript = new Map<number, string>();
  for (const m of starter.p.matchAll(/(\d+) -> (\w+)/g)) keyToScript.set(Number(m[1]), m[2]);

  const program = loadProgram(romPath);
  const trace = new Tracer(program);
  const lines: string[] = [];
  trace.out = (l) => lines.push(l);
  const vm = new BokVM(program, trace);
  vm.maxSteps = 200_000;
  const mem = program.memory.state;
  for (const [a, v] of START_STATE[ci] ?? []) mem[a] |= v;

  // 起動元の switch の変数と, この番号の Cmd_StartCutscene がある case
  const at = scriptsText.indexOf(`\n${starter.script}() {`);
  const body = at < 0 ? "" : scriptsText.slice(at, scriptsText.indexOf("\n}\n", at));
  const counter = body.match(/switch \((\w+)\)/)?.[1];
  const counterOff = counter === undefined ? undefined : scratchHeader.match(new RegExp(`#define ${counter} \\*\\(\\(u8 \\*\\)\\(scratch \\+ (0x[0-9A-Fa-f]+)\\)`))?.[1];
  let startCase = -1;
  let cur = -1;
  for (const l of body.split("\n")) {
    const c = l.match(/^\t\tcase (\d+): \{/);
    if (c) cur = Number(c[1]);
    if (startCase < 0 && new RegExp(`Cmd_StartCutscene, \\.d = (?:\\(u8\\))?${ci},`).test(l)) startCase = cur;
  }

  // 起動まで走らせる, 起動できなければ (Cmd_Delay の .e の中で起動するものなど) case を直接進める
  let started = false;
  let next: string | undefined = starter.script;
  for (let i = 0; i < 30 && next !== undefined; i++) {
    const r = runScript(vm, program, lines, next, starter.script, texts, []);
    if (r.started.includes(ci)) {
      started = true;
      break;
    }
    if (r.started.length > 0) break;
    next = r.callbacks[0] ?? starter.script;
  }
  if (!started) {
    if (counterOff === undefined || startCase < 0) return undefined;
    mem[SCRATCH + parseInt(counterOff, 16)] = startCase + 1;
  }

  const isBus = (m: Msg, cmd: number) => u8(m.addr + 2) === CLS_BUS && u16(m.addr) === TGT_BUS && u8(m.addr + 6) === cmd;
  const notes = new Map<number, string>();
  let ended = false; // 選んだ選択肢でカットシーンが終わったら, 再び起動するまで追わない
  cutscene.steps.forEach((step, si) => {
    const exec = step.msgs.find((m) => isBus(m, 0) && m.argc === 1);
    if (exec === undefined || ended) return;
    const owner = keyToScript.get(exec.args[0] & 0xffff);
    if (owner === undefined) return;
    const waits = cutscene.steps[si + 1]?.msgs.some((m) => isBus(m, 2)) ?? false;
    const parts: string[] = [];
    let name: string | undefined = owner;
    let argv: number[] = [];
    for (let i = 0; i < 10 && name !== undefined; i++) {
      const r = runScript(vm, program, lines, name, owner, texts, argv);
      argv = [];
      const summary = r.said.length > 0 ? r.said.join(" / ") : r.calls.join(", ");
      if (summary !== "") parts.push(summary);
      if (r.started.includes(ci)) break; // 途中の段から起動し直した
      if (r.ended && !r.choice) { // 選択肢の前の Cmd_StopCutscene は, 選んだ先で途中から起動し直すためのもの
        ended = true;
        // Cmd_StopCutscene は止めるだけで, 別のイベントが '.c' で途中の段から起動し直すことがある
        parts.push(r.ended === "end" ? "(ここでカットシーンが終わる)" : "(ここでカットシーンが止まる)");
        break;
      }
      if (r.choice && r.callbacks.length > 0) {
        parts.push("(選択肢は最初の項目を選んだ場合)");
        name = r.callbacks[0];
        argv = [0];
        continue;
      }
      if (r.resumed) break;
      if (r.callbacks.length > 0) name = r.callbacks[0];
      else if (waits) name = owner;
      else break;
    }
    if (parts.length > 0) notes.set(si, parts.join(" / "));
  });
  return notes;
};

const dumpCutscene = (
  cutscene: Cutscene,
  ci: number,
  u16: (a: number) => number,
  u8: (a: number) => number,
  targets: Map<number, string>,
  starters: Starter[],
  songs: Map<number, string>,
  notes: Map<number, string>,
  namedCmds: NamedCmd[],
): string => {
  const out: string[] = [];
  out.push("// Generated by tools/dumper/cutscene.ts");
  out.push(`// cutscene ${ci} (${cutscene.steps.length} steps)`);
  if (starters.length === 0) out.push("// 起動元: scripts.bokc に Cmd_StartCutscene が見つからない");
  // 同じ内容の起動元はまとめる
  const seen = new Set<string>();
  for (const st of starters) {
    const text = `// 起動元: ${st.script}${st.c !== "0" ? ` (.c = ${st.c})` : ""}, .p = [${st.p}], .e = ${st.e}`;
    if (seen.has(text)) continue;
    seen.add(text);
    out.push(text);
  }

  cutscene.steps.forEach((step, si) => {
    out.push("");
    const note = notes.get(si);
    out.push(note !== undefined ? `// step ${si}: ${note}` : `// step ${si}`);
    const refs: string[] = [];
    step.msgs.forEach((m, mi) => {
      const name = `c${ci}_s${si}_${mi}`;
      refs.push(`M(${name})`);
      const target = u16(m.addr);
      const cls = u8(m.addr + 2);
      const wait = u8(m.addr + 3) ? "WAIT" : "NOWAIT";
      const f = u8(m.addr + 4) | (u8(m.addr + 5) << 8);
      const cmd = u8(m.addr + 6);
      const args = m.args.slice(0, m.argc);

      let body: string;
      if (cls === CLS_BUS && target === TGT_BUS && cmd === 0 && m.argc === 1) {
        body = `BUS_EXEC_SCRIPT(${args[0] & 0xffff})`;
      } else if (cls === CLS_BUS && target === TGT_BUS && cmd === 1 && m.argc === 1) {
        body = `BUS_WAIT(${args[0]})`;
      } else if (cls === CLS_BUS && target === TGT_BUS && cmd === 2 && m.argc === 0) {
        body = "BUS_WAIT_EXT()";
      } else {
        const macro = CLASS_MACROS[cls];
        if (macro === undefined) throw new Error(`未知の targetClass ${cls}: 0x${gba.toHex32(m.addr)}`);
        const tgt = targets.get(target) ?? `0x${gba.toHex16(target)}`;
        const shown = args.map(String);
        if (cls === 8 && SOUND_ID_CMDS.has(cmd) && args.length > 0) shown[0] = songs.get(args[0]) ?? shown[0];
        // 名前のついた命令があればそれで書く, 宛先を固定した形を先に探す
        const fits = (c: NamedCmd) => c.cls === cls && c.cmd === cmd && c.argc === m.argc;
        const named = namedCmds.find((c) => fits(c) && c.target === tgt) ?? namedCmds.find((c) => fits(c) && c.target === undefined);
        if (named?.target !== undefined) body = `${named.name}(${shown.join(", ")})`;
        else if (named !== undefined) body = `${named.name}(${[tgt, ...shown].join(", ")})`;
        else body = `${macro}(${[tgt, String(cmd), ...shown].join(", ")})`;
      }
      const head = f !== 0 ? `MSG_F(${name}, ${f}, ` : `MSG(${name}, `;
      out.push(`${head}${wait}, ${body});`);
    });
    out.push(`STEP(c${ci}_s${si}) = {${refs.join(", ")}, NULL};`);
  });

  out.push("");
  const steps = cutscene.steps.map((_, si) => `sStep_c${ci}_s${si}`).join(", ");
  out.push(`CUTSCENE(${ci}) = {${steps}, NULL};`);
  return out.join("\n") + "\n";
};

const main = () => {
  new Command()
    .name("cutscene.ts")
    .description("カットシーンスクリプトをカットシーン1本につき1ファイルとして書き出す")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .option("--out <dir:string>", "書き出し先のディレクトリ", { default: "src/data/cutscene" })
    .option("--names <path:string>", "TGT_* と名前のついた命令の #define を読むファイル", { default: "src/cutscene.c" })
    .option("--scripts <path:string>", "起動元と台詞を拾うスクリプト", { default: "data/scripts/scripts.bokc" })
    .option("--strings <path:string>", "台詞の本文を拾うヘッダ", { default: "data/scripts/strings.h" })
    .option("--songs <path:string>", "サウンドIDの名前を拾うヘッダ", { default: "include/constants/songs.h" })
    .option("--scratch <path:string>", "起動元の switch の変数の番地を拾うヘッダ", { default: "data/scripts/scratch.h" })
    .action((opts, romPath) => {
      const rom = new DataView(Deno.readFileSync(romPath).buffer);
      const { cutscenes, u16, u8 } = read(rom);
      const targets = readTargetNames(opts.names);
      const namedCmds = readNamedCmds(opts.names);
      const starters = readStarters(opts.scripts);
      const scriptsText = Deno.readTextFileSync(opts.scripts);
      const scripts = readScriptCases(scriptsText.split("\n"));
      const scratchHeader = Deno.readTextFileSync(opts.scratch);
      const texts = readStrings(opts.strings);
      const songs = readSongNames(opts.songs);
      const includes: string[] = ["// Generated by tools/dumper/cutscene.ts"];
      cutscenes.forEach((cutscene, ci) => {
        const file = `c${String(ci).padStart(3, "0")}.h`;
        const st = starters.get(ci) ?? [];
        const starter = st.find((x) => x.c === "0") ?? st[0];
        const notes = traceDialogueVM(cutscene, ci, u16, u8, starter, romPath, scriptsText, scratchHeader, texts) ??
          traceDialogue(cutscene, ci, u16, u8, starter, scripts, texts);
        Deno.writeTextFileSync(join(opts.out, file), dumpCutscene(cutscene, ci, u16, u8, targets, st, songs, notes, namedCmds));
        includes.push(`#include "${file}"`);
      });
      Deno.writeTextFileSync(join(opts.out, "cutscenes.h"), includes.join("\n") + "\n");
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
