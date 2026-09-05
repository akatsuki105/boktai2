import * as gba from "../common/gba/gba.ts";
import * as boktai from "../common/boktai.ts";
import type { addr } from "../common/gba/gba.ts";

export const gSubroutineTable = {
  "U32J_rev1": [0x085A9208, 643],
} as Record<boktai.gameid, [addr, length: number]>;

type SubroutineEntry = {
  id: number; // サブルーチンのID
  func: addr; // サブルーチンの先頭アドレス
};

export const getSubroutineTable = (rom: DataView): SubroutineEntry[] => {
  const meta = boktai.getGameMeta(rom);
  const [start, length] = gSubroutineTable[meta.id];

  const entries: SubroutineEntry[] = [];
  for (let i = 0; i < length; i++) {
    const p: addr = start + (i * 8);
    const id = gba.getU32(rom, p);
    const func = gba.getU32(rom, p + 4);
    entries.push({ id, func });
  }

  return entries;
};

type ScriptDirectory = {
  // スクリプトの先頭アドレスの配列(注意: スクリプトIDがnのスクリプトアドレスは scripts[n-1] で取得する)
  // スクリプトIDと配置順が一致するとは限らない & 同じスクリプトが複数のIDで参照されることもあるので注意
  scripts: addr[];

  // 文字列の先頭アドレスの配列(こちらは文字列IDがそのままインデックス)
  strings: addr[];
};

export const getScriptDirectory = (rom: DataView, start: addr): ScriptDirectory => {
  let p: addr = start;
  p += 4;

  const scriptOffsets: number[] = [];
  while (true) {
    const offset = gba.getU32(rom, p);
    p += 4;
    if (offset === 0xFFFFFFFF) break;
    scriptOffsets.push(offset);
  }

  const scriptEntry: addr = p + gba.getU32(rom, p);
  const stringOffsetEntry: addr = p + gba.getU32(rom, p + 4);
  const stringEntry: addr = p + gba.getU32(rom, p + 8);
  p += 16;

  const scripts: addr[] = [];
  for (const offset of scriptOffsets) {
    scripts.push(scriptEntry + 4 + (offset & 0x00FFFFFF)); // 先頭4バイトはスクリプト全体のサイズなので飛ばす
  }

  const strings: addr[] = [];
  const stringCount = (stringEntry - stringOffsetEntry) >> 2;
  if (stringCount !== 7141) throw new Error(`Unexpected string count: ${stringCount} (expected 7141)`);
  for (let i = 0; i < stringCount; i++) {
    const offset = gba.getU32(rom, stringOffsetEntry + (i * 4)) & 0x7FFFFFFF;
    strings.push(stringEntry + offset);
  }

  return { scripts, strings };
};
