import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import { Parser } from "@binary-parser";

// see "include/weapon.h"
const parser = new Parser().endianness("little")
  .uint8("id") // 武器ID
  .uint8("kind") // 武器種
  .uint8("unk_02")
  .uint8("lv")
  .uint16("unk_04") // 武器レベル
  .uint16("durability") // 耐久値
  .uint16("quality") // 品質(+X や SP)
  .uint16("price")
  .array("ps", { type: "uint8", length: 12 })
  .array("effects", { type: "uint32le", length: 3 });

export const getWeaponTemplate = (rom: DataView, addr: addr): {
  id: number;
  kind: number;
  unk_02: number;
  lv: number;
  unk_04: number;
  durability: number;
  quality: number;
  price: number;
  ps: number[];
  effects: number[];
} => {
  return parser.parse(new Uint8Array(rom.buffer, addr - gba.BASE));
};
