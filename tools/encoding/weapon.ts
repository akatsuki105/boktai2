import { Parser } from "@binary-parser";
import * as ConstHeader from "../encoding/constants_header.ts";

type WeaponData = {
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
};

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

export const Parse = (data: Uint8Array): WeaponData => parser.parse(data);

export const Stringify = (data: WeaponData): string => {
  const defines = ConstHeader.ParseFile("./include/constants/weapon.h") as Record<string, number>;
  const names = Object.entries(defines).filter(([name]) => name.startsWith("WEAPON_")).map(([name, value]) => ({ name, value }));
  const kinds = Object.entries(defines).filter(([name]) => name.startsWith("WK_")).map(([name, value]) => ({ name, value }));
  const effects = Object.entries(defines).filter(([name]) => name.startsWith("WET_")).map(([name, value]) => ({ name, value }));

  const fmtName = (id: number): string => {
    for (const { name, value } of names) {
      if (value === id) return name;
    }
    return `${id}`;
  };

  const fmtKind = (kind: number): string => {
    for (const { name, value } of kinds) {
      if (value === kind) return name;
    }
    return `${kind}`;
  };

  const fmtEffect = (effect: number): string => {
    if (effect === 0) return "";

    const fmtEffectName = (wetid: number): string => {
      for (const { name, value } of effects) {
        if (value === wetid) return name;
      }
      return `${wetid}`;
    };

    const name = fmtEffectName(effect & 0xFF); // bit0-7
    const value = (effect >> 8) & 0xFFFFFF; // bit8-31: 効果量
    if (value !== 0) {
      return `(${name} | (${value} << 8))`;
    } else {
      return `${name}`;
    }
  };

  const fmtEffects = (effects: [number, number, number]): string => {
    let result = "";
    for (let i = 0; i < effects.length; i++) {
      const effect = effects[i];
      if (effect === 0) break;
      if (result.length > 0) result += ", ";
      result += fmtEffect(effect);
    }
    return result;
  };

  return `id: ${fmtName(data.id)}, kind: ${fmtKind(data.kind)}, rank: ${data.rank}, lv: ${data.lv}, durability: ${data.durability}, price: ${data.price}, effects: {${fmtEffects(data.effects)}}`;
};
