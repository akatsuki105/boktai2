import * as gba from "../common/gba/gba.ts";
import * as MFT from "../encoding/mft/mft.ts";
import * as VM from "../encoding/script/script.ts";
import { compile } from "../bokcc/compiler.ts";
import { parseAll } from "../bokcc/parser.ts";
import { buildPrintContext } from "../bokcc/print_context.ts";
import { InsnType, scriptIdOf } from "../bokcc/instruction.ts";
import type { Instruction, PrintContext } from "../bokcc/instruction.ts";
import { Memory, OVERLAY_BASE } from "./memory.ts";

// ROM のスクリプトディレクトリ (FileID 0xA41E) を読み, スクリプトID から実行に必要なものを引けるようにする。
// --overlay の .bokc は ROM の外に置き, 同じIDの ROM のスクリプトより優先する。

const SCRIPT_DIRECTORY_ID = 0xA41E;

// .bokc で include しているヘッダ, 名前の表示と名前でのスクリプト指定に使う
export const HEADERS = {
  strings: "data/scripts/strings.h",
  scripts: "data/scripts/script.h",
  commands: "data/scripts/commands.h",
  stat: "data/scripts/stat.h",
  world: "data/scripts/world.h",
  scratch: "data/scripts/scratch.h",
};

export type ScriptEntry = {
  addr: number; // ブロック命令 (0x80) の位置, VM_ExecByID と同じくここから長さを読む
  varcount: number; // ローカル変数の数 (script_entries の上位8bit)
};

export class Program {
  readonly memory: Memory;
  readonly ctx: PrintContext;
  private readonly scripts: ScriptEntry[]; // scripts[id - 1]
  private readonly strings: number[]; // 文字列IDごとの先頭アドレス
  private readonly overlays = new Map<number, ScriptEntry>();
  readonly overlaid = new Set<number>();

  constructor(rom: Uint8Array) {
    this.memory = new Memory(rom);
    const view = new DataView(rom.buffer, rom.byteOffset, rom.byteLength);
    const dir = VM.ParseScriptDirectory(view, MFT.getFSEntry(view, SCRIPT_DIRECTORY_ID).ptr);
    this.scripts = dir.scripts.map((s) => ({ addr: s.addr, varcount: s.varcount }));
    this.strings = dir.strings.map((s) => s.addr);
    this.ctx = buildPrintContext(HEADERS);
  }

  get scriptCount(): number {
    return this.scripts.length;
  }

  // VM_LookupByID と同じく id & 0x7FFFFFFF から1を引いた添字で引く
  lookup(id: number): ScriptEntry {
    const masked = (id & 0x7FFFFFFF) >>> 0;
    const overlay = this.overlays.get(masked);
    if (overlay !== undefined) return overlay;
    const e = this.scripts[masked - 1];
    if (e === undefined) throw new Error(`スクリプトID 0x${masked.toString(16).toUpperCase()} はありません (1..0x${this.scripts.length.toString(16).toUpperCase()})`);
    return e;
  }

  // GetStringByID, 範囲外は実機ならでたらめな位置を指すが, ここでは 0 を返す
  stringAddr(id: number): number {
    return this.strings[id] ?? 0;
  }

  // "Scr_st00_00" / "Scr_0x0307" / "0x0307" / "775" のどれでもスクリプトIDにする
  resolveScript(text: string): number {
    for (const [id, name] of this.ctx.scriptNames ?? []) {
      if (name === text) return id;
    }
    const raw = scriptIdOf(text);
    if (raw !== undefined) return raw;
    const n = Number(text);
    if (Number.isInteger(n) && n > 0) return n;
    throw new Error(`スクリプト ${text} が分かりません (script.h の名前か Scr_0xXXXX かID を指定してください)`);
  }

  // cpp を通した .bokc を読み, 定義ごとにコンパイルして ROM の外に並べる。
  // parser は定義の見出しの名前を捨てるので, 見出しの綴りは自分で拾って順番で対応させる。
  // 見出しは Scr_0xXXXX か, script.h の名前を cpp が展開した数値 (0x0177)
  addOverlay(preprocessed: string): number[] {
    const heads = [...preprocessed.matchAll(/^\s*([A-Za-z_][A-Za-z0-9_]*|0[xX][0-9A-Fa-f]+|[0-9]+)\s*\(\s*\)\s*\{/gm)].map((m) => m[1]);
    const scripts = parseAll(preprocessed);
    if (heads.length !== scripts.length) throw new Error(`overlay: 定義の見出し ${heads.length} 件と定義 ${scripts.length} 件が対応しません`);

    const chunks: Uint8Array[] = [];
    const ids: number[] = [];
    let at = OVERLAY_BASE + this.memory.overlay.length;
    for (let i = 0; i < scripts.length; i++) {
      const id = /^[0-9]/.test(heads[i]) ? Number(heads[i]) : scriptIdOf(heads[i]);
      if (id === undefined) throw new Error(`overlay: ${heads[i]} はスクリプトIDの綴り (Scr_0xXXXX か数値) ではありません`);
      const bytes = compile(scripts[i]);
      // ローカル変数の数は ROM 側の値と, 本文で使っている vN の最大の大きい方
      const varcount = Math.max(this.scripts[id - 1]?.varcount ?? 0, maxVariable(scripts[i]));
      this.overlays.set(id, { addr: at, varcount });
      this.overlaid.add(id);
      chunks.push(bytes);
      ids.push(id);
      at += bytes.length;
    }

    const merged = new Uint8Array(at - OVERLAY_BASE);
    merged.set(this.memory.overlay, 0);
    let p = this.memory.overlay.length;
    for (const c of chunks) {
      merged.set(c, p);
      p += c.length;
    }
    this.memory.overlay = merged;
    return ids;
  }
}

// 命令木に現れる vN の最大の N
const maxVariable = (instr: Instruction): number => {
  let max = instr.insnType === InsnType.Variable ? instr.value : 0;
  for (const c of instr.children) max = Math.max(max, maxVariable(c));
  return max;
};

export const loadProgram = (romPath: string): Program => {
  const rom = Deno.readFileSync(romPath);
  if (rom.length < 0xC0 || gba.getGameCode(new DataView(rom.buffer)) !== "U32J") throw new Error(`${romPath} は Zoku Bokura no Taiyou の ROM ではありません`);
  return new Program(rom);
};

// Makefile の .bokc のルールと同じ cpp で展開する
export const preprocessBokc = (path: string): string => {
  const out = new Deno.Command("arm-none-eabi-cpp", { args: ["-P", "-C", "-iquote", ".", path], stdout: "piped", stderr: "piped" }).outputSync();
  if (!out.success) throw new Error(`cpp に失敗しました: ${new TextDecoder().decode(out.stderr)}`);
  return new TextDecoder().decode(out.stdout);
};
