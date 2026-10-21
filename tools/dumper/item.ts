#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as Item from "../encoding/item.ts";
import * as ConstHeader from "../encoding/constants_header.ts";

const gItemDB = {
  addr: 0x08DAA8D8,
  length: 78,
  bytesize: 16,
} as const;

const main = () => {
  new Command()
    .description("Dump gItemDB")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .action((_, romPath) => {
      const rom = new DataView((Deno.readFileSync(romPath)).buffer);

      const defines = ConstHeader.ParseFile("./include/constants/item.h") as Record<string, number>;
      const names = Object.entries(defines).filter(([name]) => name.startsWith("ITEM_")).map(([name, value]) => ({ name, value }));
      const fmtName = (id: number): string => {
        for (const { name, value } of names) {
          if (value === id) return name;
        }
        return `${id}`;
      };

      let result = "const ItemData gItemDB[ITEM_NUM] = {\n";
      for (let i = 0; i < gItemDB.length; i++) {
        const addr: addr = gItemDB.addr + i * gItemDB.bytesize;
        const data = Item.Parse(new Uint8Array(rom.buffer, addr - gba.BASE));
        result += `\t[${fmtName(i)}] = { ${Item.Stringify(data, defines)} },\n`;
      }
      result += "};\n";

      console.log(result);
    })
    .parse(Deno.args);
};

main();
