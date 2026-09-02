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
