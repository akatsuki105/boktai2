#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import type { addr } from "../common/gba/gba.ts";
import { getWeaponTemplate } from "../parser/weapon.ts";
import { parseHeaderDefines } from "../parser/constants_header.ts";
import * as gba from "../common/gba/gba.ts";

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

      let result = "const WeaponData gWeaponDB[WEAPON_NUM] = {\n";
      for (let i = 0; i < gWeaponDB.length; i++) {
        const addr: addr = gWeaponDB.addr + i * gWeaponDB.bytesize;
        const data = getWeaponTemplate(rom, addr);
        result += `\t{ id: ${getName(data.id)}, kind: ${getKindName(data.kind)}, unk_02: 0x${gba.toHex8(data.unk_02)}, lv: ${data.lv}, unk_04: 0x${gba.toHex16(data.unk_04)}, price: ${data.price}, effects: {${data.effects.join(", ")}} },\n`;
      }
      result += "};\n";

      console.log(result);
    })
    .parse(Deno.args);
};

main();
