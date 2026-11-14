import * as gba from "../common/gba/gba.ts";

// bokvm のメモリ。VM が触るのは次の2種類だけなので、それぞれを GBA のアドレスで引けるようにする。
//
// - バイトコードと文字列: ROM (0x08000000-) と, --overlay で差し込んだスクリプトを置く仮想の領域 (OVERLAY_BASE-)
// - ゲーム状態: gStat / gWorld / gScratch とそのバックアップ, 実機では gGameStateBuffer (12288 バイト) の中に並ぶ
//
// ゲーム状態は実機と同じ並びで1枚のバッファに置くので, 領域の外にはみ出した読み書きも実機と同じ隣の領域に当たる。
// 実機では RandomizeGameStateAddr が起点をずらすが, 相対位置は変わらないので起点は 0 に固定している。

export const OVERLAY_BASE = 0x0A000000; // ROM の外, --overlay のスクリプトを置く

export const STATE_SIZE = 12288; // gGameStateBuffer
export const STAT = 0x0000; // gStat (GameInfo, 2392 バイト)
export const STAT_BACKUP = 0x0B00;
export const WORLD = 0x1600; // gWorld (World, 1024 バイト)
export const WORLD_BACKUP = 0x1A00;
export const SCRATCH = 0x1E00; // gScratch (Scratch, 1024 バイト)

export type RegionName = "stat" | "world" | "scratch";
export const REGIONS: readonly { name: RegionName; base: number; size: number }[] = [
  { name: "stat", base: STAT, size: 2392 },
  { name: "world", base: WORLD, size: 1024 },
  { name: "scratch", base: SCRATCH, size: 1024 },
];

// VM_ReadMemory 系の領域選択, 記述子の2バイト目の上位ニブルが 0x8 なら gStat, 0x1 なら gScratch, それ以外は gWorld
export const regionBaseOf = (selectorByte: number): number => {
  const nibble = selectorByte & 0xF0;
  if (nibble === 0x80) return STAT;
  if (nibble === 0x10) return SCRATCH;
  return WORLD;
};

// ゲーム状態のオフセットを "world + 0x18" の形にする (.bokc のメモリ参照と同じ綴り)
export const describeState = (offset: number): string => {
  for (const r of REGIONS) {
    if (offset >= r.base && offset < r.base + r.size) return `${r.name} + 0x${(offset - r.base).toString(16).toUpperCase()}`;
  }
  return `state + 0x${offset.toString(16).toUpperCase()}`;
};

export class Memory {
  readonly rom: Uint8Array;
  overlay: Uint8Array = new Uint8Array(0);
  readonly state = new Uint8Array(STATE_SIZE);
  warn: (msg: string) => void = () => {};

  constructor(rom: Uint8Array) {
    this.rom = rom;
  }

  // アドレスが指すバイト列と、その中の位置。InstructionReader に渡すのに使う
  segmentOf(addr: number): { bytes: Uint8Array; offset: number } {
    if (addr >= OVERLAY_BASE && addr < OVERLAY_BASE + this.overlay.length) return { bytes: this.overlay, offset: addr - OVERLAY_BASE };
    if (addr >= gba.BASE && addr < gba.BASE + this.rom.length) return { bytes: this.rom, offset: addr - gba.BASE };
    throw new Error(`0x${addr.toString(16).toUpperCase()} はバイトコードを読めるアドレスではありません`);
  }

  // バイトコード側の1バイト
  u8(addr: number): number {
    const { bytes, offset } = this.segmentOf(addr);
    return bytes[offset];
  }

  // 0 終端の文字列のバイト列 (DebugPrint や StringRef の表示用)
  cstring(addr: number): Uint8Array {
    const { bytes, offset } = this.segmentOf(addr);
    let end = offset;
    while (end < bytes.length && bytes[end] !== 0) end++;
    return bytes.subarray(offset, end);
  }

  // ゲーム状態の1バイト, バッファの外は実機なら別の変数に当たるが, ここでは警告して 0 を返す
  stateU8(offset: number): number {
    if (offset < 0 || offset >= STATE_SIZE) {
      this.warn(`gGameStateBuffer の外を読みました (${offset})`);
      return 0;
    }
    return this.state[offset];
  }

  setStateU8(offset: number, val: number): void {
    if (offset < 0 || offset >= STATE_SIZE) {
      this.warn(`gGameStateBuffer の外に書こうとしました (${offset})`);
      return;
    }
    this.state[offset] = val & 0xFF;
  }

  stateU16(offset: number): number {
    return this.stateU8(offset) | (this.stateU8(offset + 1) << 8);
  }

  stateU32(offset: number): number {
    return (this.stateU16(offset) | (this.stateU16(offset + 2) << 16)) >>> 0;
  }

  setStateU32(offset: number, val: number): void {
    for (let i = 0; i < 4; i++) this.setStateU8(offset + i, val >>> (i * 8));
  }
}
