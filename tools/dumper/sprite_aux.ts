#!/usr/bin/env -S deno run --allow-read --allow-write --allow-run

import { Command } from "@cliffy/command";
import * as SpriteAux from "../encoding/sprite_aux.ts";
import * as MFT from "../encoding/mft/mft.ts";
import { gbagfx } from "../common/gbagfx.ts";
import * as boktai from "../common/boktai.ts";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import * as path from "@std/path";
import { getPlttData } from "../encoding/mft_spritepltt.ts";

const ID = 0x2117;

// e.g. sprite_aux.ts tile ./baserom.gba tmp/actorsprite 0xA895
const tileCmd = new Command()
  .name("sprite_aux.ts")
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
    const hdr = MFT.getFSEntry(rom, ID);
    if (hdr.end == null) throw new Error(`MFT entry with id1 0x2117 has no end address.`);
    const [dirStart, dirEnd]: [addr, addr] = [hdr.ptr, hdr.end];
    const dir = MFT.ParseDirectory(rom, dirStart);

    const start: addr = dir.addr + dir.offsetTo1stFile;
    const f = SpriteAux.ParseFile(rom, start, dirEnd);

    const makerules: string[] = [];
    const incbins: string[] = [];

    const entryCount = f.header.entryCount;
    const tilebase: addr = start + f.header.offsetToTiles; // .tiles
    for (let i = 0; i < f.header.entryCount; i++) {
      const actorID = f.entries[i].id;
      if (targetID !== 0 && actorID !== targetID) continue;

      const metaspriteStart = f.entries[i].metaspriteIndex;
      const metaspriteEnd = (i === entryCount - 1) ? f.metasprites.length : f.entries[i + 1].metaspriteIndex;

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
      const bpp = gba.copyBytes(rom, from, legnth).slice(0, legnth);
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
  });

// ./tools/dumper/sprite_aux.ts asm ./baserom.gba > tmp/sprite_aux.inc
const asmCmd = new Command()
  .description("Dump actor sprite data as assembly.")
  .argument("<rom:string>", "Path to a GBA ROM file.")
  .action((opts, romPath) => {
    const macros = `
.macro subsprite size:req, x:req, y:req
  .byte (\\size), 0 @ shape, unk_01(always 0)
  .byte (\\x), (\\y) @ x, y (pixel offset)
.endm
    `;
    const rom = new DataView((Deno.readFileSync(romPath)).buffer);
    const hdr = MFT.getFSEntry(rom, ID);
    if (hdr.end == null) throw new Error(`MFT entry with id1 0x2117 has no end address.`);
    const [dirStart, dirEnd]: [addr, addr] = [hdr.ptr, hdr.end];
    const dir = MFT.ParseDirectory(rom, dirStart);

    const start: addr = dir.addr + dir.offsetTo1stFile;
    const f = SpriteAux.ParseFile(rom, start, dirEnd);

    // console.log(macros);

    // entry
    for (let i = 0; i < f.entries.length; i++) {
      const entry = f.entries[i];
      console.log(`  entry 0x${gba.toHex16(entry.id)}, Metaprite_${entry.metaspriteIndex}, ${entry.size[0]}, ${entry.size[1]}, ${entry.offset[0]}, ${entry.offset[1]} @ ${i}`);
    }

    // metasprite
    console.log(`Metaprites:`);
    const metaspriteStarts: number[] = f.entries.map((ms) => ms.metaspriteIndex);
    for (let i = 0; i < f.metasprites.length; i++) {
      const ms = f.metasprites[i];
      if (metaspriteStarts.includes(i)) {
        console.log(`  Metaprite_${i}:`);
      }
      console.log(`    metasprite Subsprite_${ms.subspriteIdx}, ${ms.subspriteCount}, ${ms.tileCount}, ${ms.plttID}, ${ms.tileID} @ ${i}`);
    }

    // subsprite
    console.log(`Subsprites:`);
    const subspriteStarts: number[] = f.metasprites.flatMap((ms) => ms.subspriteIdx);
    for (let i = 0; i < f.subsprites.length; i++) {
      const subsprite = f.subsprites[i];
      const [w, h] = boktai.SpriteSize[subsprite.sizeIdx];
      if (subspriteStarts.includes(i)) {
        console.log(`  Subsprite_${i}:`);
      }
      console.log(`    subsprite OAM_SIZE_${w}x${h}, ${subsprite.offset[0]}, ${subsprite.offset[1]}`);
    }
  });

const main = () => {
  new Command()
    .name("sprite_aux.ts")
    .command("tile", tileCmd)
    .command("asm", asmCmd)
    .parse(Deno.args);
};

if (import.meta.main) main();
