import { FSEntry, ParseFS } from "./fs.ts";
import * as boktai from "../../common/boktai.ts";

const MFT_ENTRY_COUNT = 11;

const gFS = {
  "U32J": 0x085B0CE4,
  "U32J_rev1": 0x085B0D90,
  "U33J": 0x08614D6C,
};

export const getFSEntry = (rom: DataView, id: number): FSEntry => {
  const meta = boktai.getGameMeta(rom);
  const fs = gFS[meta.id];

  const dirs = ParseFS(rom, fs, MFT_ENTRY_COUNT);
  for (const dir of dirs) {
    if (dir.ids[0] === id) {
      return dir;
    }
  }
  throw new Error(`MFT entry with id1 ${id} not found.`);
};
