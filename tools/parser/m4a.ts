import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";

type Song = {
  header: addr;
  ms: number;
  me: number;
};

export const parseSongTable = (rom: DataView, start: addr, songCount: number = -1): Song[] => {
  const parseSong = (buffer: DataView): Song => {
    const header = buffer.getUint32(0, true) as addr;
    const ms = buffer.getUint16(4, true);
    const me = buffer.getUint16(6, true);
    return { header, ms, me };
  };

  const offset = (start >= gba.BASE) ? start - gba.BASE : start;
  if (songCount === -1) {
    const song0 = parseSong(new DataView(rom.buffer, offset));
    songCount = (song0.header - start) >> 3;
  }

  const songs: Song[] = [];
  for (let i = 0; i < songCount; i++) {
    const song = parseSong(new DataView(rom.buffer, offset + i * 8));
    songs.push(song);
  }
  return songs;
};

type SongHeader = {
  trackCount: number;
  blockCount: number;
  priority: number;
  reverb: number;
  tone: addr;
  part: addr[];
};

export const parseSongHeader = (rom: DataView, start: addr): SongHeader => {
  const trackCount = gba.getU8(rom, start);
  const blockCount = gba.getU8(rom, start + 1);
  const priority = gba.getU8(rom, start + 2);
  const reverb = gba.getU8(rom, start + 3);
  const tone: addr = gba.getU32(rom, start + 4);
  const part0: addr = gba.getU32(rom, start + 8);
  const part: addr[] = [part0];
  for (let i = 1;; i++) {
    if (i > 128) throw new Error("Too many parts in SongHeader.");
    const partN: addr = gba.getU32(rom, start + 8 + (i * 4));
    if (partN >= part0 && partN < start) {
      part.push(partN);
    } else {
      break;
    }
  }
  return { trackCount, blockCount, priority, reverb, tone, part };
};
