#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import { parseActorSpriteFile } from "../encoding/mft_actorsprite.ts";
import * as MFT from "../encoding/mft/mft.ts";
import { gbagfx } from "../common/gbagfx.ts";
import * as boktai from "../common/boktai.ts";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as ConstHeader from "../encoding/constants_header.ts";

// e.g. actorsprite_id.ts ./baserom.gba
const main = () => {
  new Command()
    .name("actorsprite_id.ts")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .action((_, romPath) => {
      const rom = new DataView((Deno.readFileSync(romPath)).buffer);
      const hdr = MFT.getFSEntry(rom, 0x2117);
      if (hdr.end == null) throw new Error(`MFT entry with id1 0x2117 has no end address.`);
      const dirStart: addr = hdr.ptr;
      const dirEnd: addr = hdr.end;
      const dir = MFT.ParseDirectory(rom, dirStart);

      const start: addr = dir.addr + dir.offsetTo1stFile;
      const end = dirEnd;
      const f = parseActorSpriteFile(rom, start, end);

      const defines = ConstHeader.ParseFile("./include/constants/sprite.h") as Record<string, number>;
      // value to key
      const valueToKey = Object.fromEntries(
        Object.entries(defines).map(([key, value]) => [value, key]),
      );

      for (let i = 0; i < f.header.actorCount; i++) {
        const auxsprite = f.actors[i];
        const id = auxsprite.id;
        const idHex = gba.toHex16(auxsprite.id);
        if (valueToKey[id] == null) {
          console.log(`#define SPRITE_${idHex} 0x${idHex}`);
        } else {
          // console.log(`#define ${valueToKey[id]} 0x${idHex}`);
        }
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
