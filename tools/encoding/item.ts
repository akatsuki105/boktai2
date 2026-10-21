import { Parser } from "@binary-parser";

// see "include/item.h"
type ItemData = {
  unk_00: number; // u16
  effectType: number; // u16
  unk_04: number; // u16
  value: number; // u16
  unk_08: number; // u16
  unk_0a: number; // u16
  price: number; // u32
};

export const Parse = (data: Uint8Array): ItemData => {
  const parser = new Parser().endianness("little")
    .uint16("unk_00")
    .uint16("effectType")
    .uint16("unk_04")
    .uint16("value")
    .uint16("unk_08")
    .uint16("unk_0a")
    .uint32("price");
  return parser.parse(data);
};

export const Stringify = (data: ItemData, defines: Record<string, number>): string => {
  const effects = Object.entries(defines).filter(([name]) => name.startsWith("IET_")).map(([name, value]) => ({ name, value }));

  const fmtEffect = (effect: number): string => {
    for (const { name, value } of effects) {
      if (value === effect) return name;
    }
    return `${effect}`;
  };

  return `.unk_00 = ${data.unk_00}, .effectType = ${fmtEffect(data.effectType)}, .unk_04 = ${data.unk_04}, .value = ${data.value}, .unk_08 = ${data.unk_08}, .unk_0a = ${data.unk_0a}, .price = ${data.price}`;
};
