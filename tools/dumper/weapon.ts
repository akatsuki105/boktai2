#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import type { addr } from "../common/gba/gba.ts";
import { getWeaponTemplate } from "../parser/weapon.ts";
import { parseHeaderDefines } from "../parser/common/constants_header.ts";

const gWeaponDB = {
  addr: 0x08DA9E68,
  length: 66,
  bytesize: 36,
} as const;

const main = () => {
  new Command()
    .name("weapon.ts")
    .description("Dump gWeaponDB")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .action((_, romPath) => {
      const rom = new DataView((Deno.readFileSync(romPath)).buffer);

      const defines = parseHeaderDefines("./include/constants/weapon.h") as Record<string, number>;
      const names = Object.entries(defines).filter(([name]) => name.startsWith("WEAPON_")).map(([name, value]) => ({ name, value }));
      const kinds = Object.entries(defines).filter(([name]) => name.startsWith("WK_")).map(([name, value]) => ({ name, value }));
      const effects = Object.entries(defines).filter(([name]) => name.startsWith("WET_")).map(([name, value]) => ({ name, value }));

      const getName = (id: number): string => {
        for (const { name, value } of names) {
          if (value === id) return name;
        }
        return `${id}`;
      };

      const getKindName = (kind: number): string => {
        for (const { name, value } of kinds) {
          if (value === kind) return name;
        }
        return `${kind}`;
      };

      const getEffectName = (wetid: number): string => {
        for (const { name, value } of effects) {
          if (value === wetid) return name;
        }
        return `${wetid}`;
      };

      const dumpWeaponEffects = (effects: [number, number, number]): string => {
        let result = "";
        for (let i = 0; i < effects.length; i++) {
          const effect = effects[i];
          if (effect === 0) break;
          if (result.length > 0) result += ", ";

          const name = getEffectName(effect & 0xFF); // bit0-7
          const value = (effect >> 8) & 0xFFFFFF; // bit8-31: 効果量
          if (value !== 0) {
            result += `(${name} | (${value} << 8))`;
          } else {
            result += `${name}`;
          }
        }
        return result;
      };

      let result = "const WeaponData gWeaponDB[WEAPON_NUM] = {\n";
      for (let i = 0; i < gWeaponDB.length; i++) {
        const addr: addr = gWeaponDB.addr + i * gWeaponDB.bytesize;
        const data = getWeaponTemplate(rom, addr);
        result += `\t{ id: ${getName(data.id)}, kind: ${getKindName(data.kind)}, rank: ${data.rank}, lv: ${data.lv}, durability: ${data.durability}, price: ${data.price}, effects: {${dumpWeaponEffects(data.effects)}} },\n`;
      }
      result += "};\n";

      console.log(result);
    })
    .parse(Deno.args);
};

main();
