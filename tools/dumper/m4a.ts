#!/usr/bin/env -S deno run --allow-read --allow-run

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";
import { parseSymbolFile } from "../parser/common/symbol.ts";
import * as m4a from "../parser/m4a.ts";
import * as gas from "./gas.ts";

const indent = "  ";

// tools/dumper/m4a.ts songtable baserom.gba 0x0825E56C
const songtable = new Command()
  .description("gSongTable")
  .argument("<rom:string>", "Path to a GBA ROM file.")
  .argument("<addr:number>", "ROM address of gSongTable.")
  .argument("[length:number]", "Number of entries in gSongTable.")
  .action((_, romPath, targetAddr, entryCount = -1) => {
    const rom = new DataView((Deno.readFileSync(romPath)).buffer);
    const syms = parseSymbolFile();
    const dumpC = false;
    const name = "gSongTable";

    try {
      const songs = m4a.parseSongTable(rom, targetAddr, entryCount);

      if (dumpC) {
        console.log("const Song ${name}[] = {");
        for (let i = 0; i < songs.length; i++) {
          const song = songs[i];
          console.log(indent + `[${i}] = {(SongHeader*)0x${gba.toHex32(song.header)}, ${song.ms}, ${song.me}},`);
        }
        console.log("};");
      } else {
        console.log(`.global ${name}`);
        console.log(`${name}: @ 0x${gba.toHex32(targetAddr)}`);
        for (let i = 0; i < songs.length; i++) {
          const song = songs[i];
          const sym = syms.find((s) => s.offset === song.header);
          const header = (sym && sym.name) ? sym.name : `0x${gba.toHex32(song.header)}`;
          console.log(indent + `song ${header}, ${song.ms}, ${song.me}`);
        }
      }
    } catch (e) {
      console.error(e instanceof Error ? e.message : String(e));
      Deno.exit(1);
    }
  });

// tools/dumper/m4a.ts songheader baserom.gba 0x0852F3A4
const songheader = new Command()
  .argument("<rom:string>", "Path to a GBA ROM file.")
  .argument("<addr:number>", "ROM address of SongHeader.")
  .action((_, romPath, targetAddr) => {
    const rom = new DataView((Deno.readFileSync(romPath)).buffer);
    try {
      dumpSongHeader(rom, targetAddr);
    } catch (e) {
      console.error(e instanceof Error ? e.message : String(e));
      Deno.exit(1);
    }
  });

const dumpSongHeader = (rom: DataView, start: addr) => {
  const hdr = m4a.parseSongHeader(rom, start);
  const label = `song_${gba.toHex32(start)}`;

  const [mmlStart, mmlEnd] = [hdr.part[0], start];
  if ((mmlStart >= mmlEnd) || (mmlEnd - mmlStart > 0x2000)) {
    throw new Error(`Invalid MML range in SongHeader: start=0x${gba.toHex32(mmlStart)}, end=0x${gba.toHex32(mmlEnd)}`);
  }

  const mml = gba.copyBytes(rom, hdr.part[0], mmlEnd - mmlStart);
  console.log(`${label}_mml:`);
  console.log(gas.dumpU8array(mml, indent, 32));

  console.log(gas.Align4);
  console.log(gas.dumpGlobalSymbol(label) + ` @ 0x${gba.toHex32(start)}`);
  console.log(indent + `.byte ${hdr.trackCount}, ${hdr.blockCount}, ${hdr.priority}, ${hdr.reverb} @ trackCount, blockCount, priority, reverb`);
  console.log(indent + `.4byte 0x${gba.toHex32(hdr.tone)} @ tone`);
  console.log(indent + `@ parts`);
  for (let i = 0; i < hdr.part.length; i++) {
    if (i === 0) {
      console.log(indent + `.4byte ${label}_mml`);
    } else {
      const offset = hdr.part[i] - hdr.part[0];
      console.log(indent + `.4byte ${label}_mml+${offset}`);
    }
    if (i > 128) {
      throw new Error("Too many parts in SongHeader.");
    }
  }
};

const main = () => {
  new Command()
    .name("m4a.ts")
    .command("songtable", songtable)
    .command("songheader", songheader)
    .parse(Deno.args);
};

if (import.meta.main) main();
