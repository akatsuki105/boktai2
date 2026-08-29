#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import { parseActorSpriteFile } from "../parser/mft_actorsprite.ts";
import * as mft from "../parser/mft.ts";
import { gbagfx } from "./gbagfx.ts";
import * as boktai from "../common/boktai.ts";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as path from "@std/path";
import { getPlttData } from "../parser/mft_spritepltt.ts";

// e.g. actorsprite_tile.ts ./baserom.gba tmp/actorsprite 0xA895
const main = () => {
  new Command()
    .name("actorsprite_tile.ts")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .argument("<output:string>", "Path to output directory.")
    .argument("<id:number>", "Target actor ID (0 = all actors)")
    .option("--pltt <id:number>", "force plttID", { default: -1 })
    .option("-w, --width <number:number>", "gbagfx width (0: auto).", { default: 0 })
    .option("--mwidth <number:number>", "gbagfx mwidth(metatile width) (0: auto).", { default: 0 })
    .option("--mheight <number:number>", "gbagfx mheight(metatile height) (0: auto).", { default: 0 })
    .action((options, romPath, outDir, targetID) => {
      Deno.mkdirSync(`${outDir}`, { recursive: true });

      const rom = new DataView((Deno.readFileSync(romPath)).buffer);
      const hdr = mft.getMftHeader(rom, 0x2117);
      if (hdr.end == null) throw new Error(`MFT entry with id1 0x2117 has no end address.`);
      const dirStart: addr = hdr.ptr;
      const dirEnd: addr = hdr.end;
      const dir = mft.parseMftDirectory(rom, dirStart);

      const start: addr = dir.addr + dir.offsetTo1stFile;
      const end = dirEnd;
      const f = parseActorSpriteFile(rom, start, end);

      const makerules: string[] = [];
      const incbins: string[] = [];

      const actorCount = f.header.actorCount;
      const tilebase: addr = start + f.header.offsetToTiles; // .tiles
      for (let i = 0; i < f.header.actorCount; i++) {
        const actorID = f.actors[i].id;
        if (targetID !== 0 && actorID !== targetID) continue;

        const metaspriteStart = f.actors[i].metaspriteIndex;
        const metaspriteEnd = (i === actorCount - 1) ? f.metasprites.length : f.actors[i + 1].metaspriteIndex;

        // 各メタスプライトの使うTile数を数える
        let tileCount = 0;
        for (let j = metaspriteStart; j < metaspriteEnd; j++) {
          const ms = f.metasprites[j];
          for (let k = 0; k < ms.subspriteCount; k++) {
            const ss = f.subsprites[ms.subspriteIdx + k];
            const [w, h] = boktai.SpriteSize[ss.sizeIdx];
            const count = (w >> 3) * (h >> 3); // タイル数 = (幅 / 8) * (高さ / 8)
            tileCount += count;
          }
        }

        // アクターのタイルデータを ${ID}.4bpp を取得
        const tileID = f.metasprites[metaspriteStart].tileID; // アクターの最初のメタスプライトのtileID
        const from: addr = tilebase + (tileID * 32);
        const legnth = tileCount * 32;
        const bpp = new Uint8Array(gba.getSlice(rom, from, legnth)).slice(0, legnth);
        const bppPath = path.join(outDir, `${gba.toHex16(actorID)}.4bpp`);
        Deno.writeFileSync(bppPath, bpp);

        // アクターのパレットを ${ID}.gbapal を取得
        const plttID = (options.pltt >= 0) ? options.pltt : f.metasprites[metaspriteStart].plttID;
        const gbapal = getPlttData(rom, plttID);
        const palPath = path.join(outDir, `${gba.toHex16(actorID)}.gbapal`);
        Deno.writeFileSync(palPath, gbapal);

        // gbagfxでpngに変換
        const pngPath = path.join(outDir, `${gba.toHex16(actorID)}.png`);
        const width = (options.width > 0) ? options.width : ((tileCount >= 4) ? 4 : tileCount); // タイル数が4以上なら幅4、未満なら幅 = タイル数
        const gbagfxOpts = ["-object", "-palette", palPath, "-width", `${width}`];
        if (options.mwidth > 0) gbagfxOpts.push("-mwidth", `${options.mwidth}`);
        if (options.mheight > 0) gbagfxOpts.push("-mheight", `${options.mheight}`);
        const { code, stdout, stderr } = gbagfx(bppPath, pngPath, ...gbagfxOpts);
        if (code !== 0) {
          console.error(`Error: gbagfx failed with exit code ${code}`);
          const stdoutStr = new TextDecoder().decode(stdout);
          if (stdoutStr) console.log(`  gbagfx: ${stdoutStr}`);
          const stderrStr = new TextDecoder().decode(stderr);
          if (stderrStr) console.log(`  gbagfx: ${stderrStr}`);
          Deno.exit(1);
        }

        if (tileCount % width !== 0) {
          const rule = `data/actor_sprites/${gba.toHex16(actorID)}.4bpp: GFX_OPTS := -num_tiles ${tileCount}`;
          makerules.push(rule);
        }

        const incbin = `.incbin "data/actor_sprites/${gba.toHex16(actorID)}.4bpp" @ 0x${gba.toHex32(from)}, ActorID: 0x${gba.toHex16(actorID)}, PlttID: ${plttID}`;
        incbins.push(incbin);
      }

      makerules.forEach((rule) => console.log(rule));
      console.log();
      incbins.forEach((incbin) => console.log(incbin));
    })
    .parse(Deno.args);
};

main();
