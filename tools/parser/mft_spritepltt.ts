import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as boktai from "../common/boktai.ts";

type SpritePlttFile = {
  length: number; // 16色のパレットが何個あるか
  unk_02: number;
  body: Uint8Array;
};

// u16[length * 16]
const PlttDataBase = {
  "U32J_rev1": 0x08CB9248,
} as Record<boktai.gameid, addr>;

export const parseSpritePlttFile = (rom: DataView, start: addr): SpritePlttFile => {
  const length = gba.getU16(rom, start);
  if (length !== 768) {
    throw new Error(`Unexpected SpritePlttFile length: ${length}, expected 768. in Boktai2`);
  }

  const unk_02 = gba.getU16(rom, start + 2);
  const bytelength = length * 32;
  const body = new Uint8Array(gba.getSlice(rom, start + 4, bytelength)).slice(0, bytelength);

  return { length, unk_02, body };
};

export const getPlttData = (rom: DataView, plttID: number): Uint8Array => {
  const meta = boktai.getGameMeta(rom);
  const plttBase = PlttDataBase[meta.id];
  const plttStart = plttBase + (plttID * 32);
  return new Uint8Array(gba.getSlice(rom, plttStart, 32)).slice(0, 32);
};
