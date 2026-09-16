#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as weapon from "../encoding/weapon.ts";

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

      let result = "const WeaponData gWeaponDB[WEAPON_NUM] = {\n";
      for (let i = 0; i < gWeaponDB.length; i++) {
        const addr: addr = gWeaponDB.addr + i * gWeaponDB.bytesize;
        const data = weapon.Parse(new Uint8Array(rom.buffer, addr - gba.BASE));
        result += `\t{ ${weapon.Stringify(data)} },\n`;
      }
      result += "};\n";

      console.log(result);
    })
    .parse(Deno.args);
};

main();
