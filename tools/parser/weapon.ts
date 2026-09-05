import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import { Parser } from "@binary-parser";

// see "include/weapon.h"
const parser = new Parser().endianness("little")
  .uint8("id") // 武器ID
  .uint8("kind") // 武器種
  .uint8("rank")
  .uint8("lv") // 武器レベル
  .uint16("durability") // 耐久値
  .uint16("wear")
  .uint16("quality") // 品質(+X や SP)
  .uint16("price")
  .array("ps", { type: "uint8", length: 12 })
  .array("effects", { type: "uint32le", length: 3 });

export const getWeaponTemplate = (rom: DataView, addr: addr): {
  id: number;
  kind: number;
  rank: number;
  lv: number;
  durability: number;
  wear: number;
  quality: number;
  price: number;
  ps: number[];
  effects: [number, number, number];
} => {
  return parser.parse(new Uint8Array(rom.buffer, addr - gba.BASE));
};
