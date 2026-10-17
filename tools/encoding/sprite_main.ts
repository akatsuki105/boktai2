import { Parser } from "@binary-parser";

// MainSpriteGfxFile in include/sprite_main.h
export type FileHeader = {
  palStart: number; // u16
  spriteCount: number; // u16
  animationCount: number; // u16
  subspriteCount: number; // u16
  cmdCount: number; // u16
  tileCount: number; // u16
  offsetToSprites: number; // u32
  offsetToAnims: number; // u32
  offsetToSubsprites: number; // u32
  offsetToCmds: number; // u32
  offsetToTiles: number; // u32
};

const FileHeaderParser = new Parser()
  .uint16le("palStart")
  .uint16le("spriteCount")
  .uint16le("animationCount")
  .uint16le("subspriteCount")
  .uint16le("cmdCount")
  .uint16le("tileCount")
  .uint32le("offsetToSprites")
  .uint32le("offsetToAnims")
  .uint32le("offsetToSubsprites")
  .uint32le("offsetToCmds")
  .uint32le("offsetToTiles");

// MainSpritePose in include/sprite_main.h
type Pose = {
  unk_0: number; // u16
  subspriteCount: number; // u16
  offset: [number, number]; // u16[2]
  box: [number, number, number, number]; // u16[4]
  subspriteOffset: number; // u32
};

const PoseParser = new Parser()
  .uint16le("unk_0")
  .uint16le("subspriteCount")
  .array("offset", { type: "uint16le", length: 2 })
  .array("box", { type: "int16le", length: 4 })
  .uint32le("subspriteOffset");

// MainAnim in include/sprite_main.h
type Anim = {
  unk_0: number; // u16
  cmdCount: number; // u16
  cmdOffset: number; // u32
};

const AnimParser = new Parser()
  .uint16le("unk_0")
  .uint16le("cmdCount")
  .uint32le("cmdOffset");

// MainSubsprite in include/sprite_main.h
type Subsprite = {
  flip: number; // u8
  shape: number; // u8
  x: number; // s16
  y: number; // s16
  tileNumPaletteNum: number; // u16:12, u16:4
};

const SubspriteParser = new Parser().endianess("little")
  .uint8("flip")
  .uint8("shape")
  .int16le("x")
  .int16le("y")
  .uint16le("tileNumPaletteNum");

type AnimCmd = {
  poseIdx: number; // u16
  duration: number; // u16
};

const AnimCmdParser = new Parser()
  .uint16le("poseIdx")
  .uint16le("duration");

export type File = {
  header: FileHeader;
  sprites: Pose[]; // Pose[header.spriteCount]
  anims: Anim[]; // Anim[header.animationCount]
  subsprites: Subsprite[]; // Subsprite[header.subspriteCount]
  cmds: AnimCmd[]; // AnimCmd[header.cmdCount]
};

export const ParseFile = (data: Uint8Array): File => {
  const parser = new Parser()
    .nest("header", { type: FileHeaderParser })
    .array("sprites", { type: PoseParser, length: "header.spriteCount" })
    .array("anims", { type: AnimParser, length: "header.animationCount" })
    .array("subsprites", { type: SubspriteParser, length: "header.subspriteCount" })
    .array("cmds", { type: AnimCmdParser, length: "header.cmdCount" });
  const f = parser.parse(data);

  for (let i = 0; i < f.sprites.length; i++) {
    const s = f.sprites[i];
    if (s.offset[0] !== 0 || s.offset[1] !== 0) {
      throw new Error(`Invalid offset value at sprite index ${i}: ${s.offset[0]}, ${s.offset[1]}`);
    }
  }

  for (let i = 0; i < f.subsprites.length; i++) {
    const flip = f.subsprites[i].flip;
    // bit2 と bit3 以外が立っていたらエラー
    if ((flip & 0xF3) !== 0) {
      throw new Error(`Invalid flip value at subsprite index ${i}: 0x${flip.toString(16).toUpperCase().padStart(2, "0")}`);
    }
  }

  return f;
};
