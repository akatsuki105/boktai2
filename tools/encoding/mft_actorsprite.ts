import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";

export type ActorSpriteFile = {
  header: {
    unk0: number;
    actorCount: number;
    unk8: number;
    offsetToTiles: number;
    offsetToMetasprites: number;
    offsetToSubsprites: number;
  };
  actors: {
    id: number;
    unk_02: number; // always 0
    size: [number, number]; // width, height in pixels
    offset: [number, number]; // x, y pixel offset
    metaspriteIndex: number; // index into .metasprite[]
  }[];
  metasprites: {
    subspriteCount: number;
    unk_01: number;
    plttID: number;
    tileID: number; // index into .tiles[]
    subspriteIdx: number; // index into .subsprite[]
  }[];
  subsprites: {
    sizeIdx: number;
    unk_01: number; // always 0
    offset: [number, number]; // x, y pixel offset
  }[];
};

export const parseActorSpriteFile = (rom: DataView, start: addr, end: addr): ActorSpriteFile => {
  const header: ActorSpriteFile["header"] = {
    unk0: gba.getU32(rom, start),
    actorCount: gba.getU32(rom, start + 4),
    unk8: gba.getU32(rom, start + 8),
    offsetToTiles: gba.getU32(rom, start + 12),
    offsetToMetasprites: gba.getU32(rom, start + 16),
    offsetToSubsprites: gba.getU32(rom, start + 20),
  };

  // Actors
  const actors: ActorSpriteFile["actors"] = [];
  for (let i = 0; i < header.actorCount; i++) {
    const p: addr = (start + 0x18) + (i * 12);
    const [id, unk_02] = [gba.getU16(rom, p), gba.getU16(rom, p + 2)];
    if (unk_02 !== 0) {
      throw new Error(`ActorSprite${i}(ID:0x${gba.toHex16(id)}) has unk_02 = ${unk_02}, expected 0.`);
    }
    const size: [number, number] = [gba.getU8(rom, p + 4), gba.getU8(rom, p + 5)];
    const offset: [number, number] = [gba.getS8(rom, p + 6), gba.getS8(rom, p + 7)];
    const metaspriteIdx = gba.getU32(rom, p + 8) / 12;
    actors.push({ id, unk_02, size, offset, metaspriteIndex: metaspriteIdx });
  }

  // Metasprites
  const metasprites: ActorSpriteFile["metasprites"] = [];
  {
    const bytelength = (start + header.offsetToSubsprites) - (start + header.offsetToMetasprites);
    const length = bytelength / 12;
    if (length !== 2164) throw new Error(`Warning: ActorSpriteFile has ${length} sprites, expected 2164 in Boktai2.`);
    for (let i = 0; i < length; i++) {
      const p: addr = (start + header.offsetToMetasprites) + (i * 12);
      const [subspriteCount, unk_01] = [gba.getU8(rom, p), gba.getU8(rom, p + 1)];
      const plttID = gba.getU16(rom, p + 2);
      const tileID = gba.getU32(rom, p + 4) >> 5;
      const subspriteIdx = gba.getU32(rom, p + 8) >> 2;
      metasprites.push({ subspriteCount, unk_01, plttID, tileID, subspriteIdx });
    }
  }

  // Subsprites
  const subsprites: ActorSpriteFile["subsprites"] = [];
  {
    const bytelength = end - (start + header.offsetToSubsprites);
    const length = bytelength >> 2;
    if (length !== 4641) console.error(`Warning: ActorSpriteFile has ${length} objects, expected 4641 in Boktai2.`);
    for (let i = 0; i < length; i++) {
      const p: addr = (start + header.offsetToSubsprites) + (i * 4);
      const [shape, unk_01] = [gba.getU8(rom, p), gba.getU8(rom, p + 1)];
      const [x, y] = [gba.getS8(rom, p + 2), gba.getS8(rom, p + 3)];
      subsprites.push({ sizeIdx: shape, unk_01, offset: [x, y] });
    }
  }

  return { header, actors, metasprites, subsprites };
};
