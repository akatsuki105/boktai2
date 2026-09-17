import * as gba from "../../common/gba/gba.ts";
import type { addr } from "../../common/gba/gba.ts";

// gFSのエントリ
export type FSEntry = {
  ids: [number, number]; // e.g. [0x2117, 0x9B05] in U32J_rev1's AuxSprite
  ptr: addr; // start addr, e.g. 0x08A22900 in U32J_rev1's AuxSprite
  end?: addr; // end addr, e.g. 0x08B79944 in U32J_rev1's AuxSprite
};

export const ParseFS = (rom: DataView, fs: addr, length: number): FSEntry[] => {
  const entries: FSEntry[] = [];
  for (let i = 0; i < length; i++) {
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
