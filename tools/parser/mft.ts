import * as gba from "../common/gba/gba.ts";
import * as boktai from "../common/boktai.ts";
import type { addr } from "../common/gba/gba.ts";

const MFT_ENTRY_COUNT = 11;

const gFS = {
  "U32J": 0x085B0CE4,
  "U32J_rev1": 0x085B0D90,
};

// gFSのエントリ
type MftHeader = {
  ids: [number, number]; // e.g. [0x2117, 0x9B05] in U32J_rev1's ActorSprite
  ptr: addr; // start addr, e.g. 0x08A22900 in U32J_rev1's ActorSprite
  end?: addr; // end addr, e.g. 0x08B79944 in U32J_rev1's ActorSprite
};

const getMftFSEntries = (rom: DataView, fs: addr): MftHeader[] => {
  const entries: MftHeader[] = [];
  for (let i = 0; i < MFT_ENTRY_COUNT; i++) {
    const p = fs + i * 8;
    const [id1, id2] = [gba.getU16(rom, p), gba.getU16(rom, p + 2)];
    const ptr = gba.getU32(rom, p + 4);
    entries.push({ ids: [id1, id2], ptr });
  }

  let last: addr | null = null;
  for (const entry of [...entries].sort((a, b) => b.ptr - a.ptr)) {
    if (last !== null) {
      entry.end = last;
    }
    last = entry.ptr;
  }

  return entries;
};

export const getMftHeader = (rom: DataView, id: number): MftHeader => {
  const meta = boktai.getGameMeta(rom);
  const fs = gFS[meta.id];

  const dirs = getMftFSEntries(rom, fs);
  for (const dir of dirs) {
    if (dir.ids[0] === id) {
      return dir;
    }
  }
  throw new Error(`MFT entry with id1 ${id} not found.`);
};

type MftDirectory = {
  addr: addr; // ディレクトリの先頭アドレス
  entryNum: number; // ファイル数
  offsetToIDs: number; // ファイルIDの配列へのオフセット
  offsetToFileOffsets: number;
  offsetTo1stFile: number;
  ids: number[]; // ファイルIDの配列
  fileOffsets: number[]; // ファイルのオフセットの配列
};

export const parseMftDirectory = (rom: DataView, dirAddr: addr): MftDirectory => {
  const start = dirAddr;
  const entryNum: number = gba.getU32(rom, start);
  const offsetToIDs: number = gba.getU32(rom, start + 4);
  const offsetToFileOffsets: number = gba.getU32(rom, start + 8);
  const offsetTo1stFile: number = gba.getU32(rom, start + 12);

  const ids: number[] = Array(entryNum).fill(0);
  const fileOffsets: number[] = Array(entryNum).fill(0);
  for (let i = 0; i < entryNum; i++) {
    ids[i] = gba.getU16(rom, (start + offsetToIDs) + i * 2);
    fileOffsets[i] = gba.getU32(rom, (start + offsetToFileOffsets) + i * 4);
  }
  return { addr: start, entryNum, offsetToIDs, offsetToFileOffsets, offsetTo1stFile, ids, fileOffsets };
};
