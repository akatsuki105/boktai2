#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as path from "@std/path";
import * as gba from "../common/gba/gba.ts";
import { ParseFile } from "../parser/common/charmap.ts";

// 指定アドレスから終端文字('$')までを charmap.txt の内容に基づいて .string "..." として出力
// デコード中に charmap.txt に存在しない未定義バイトに遭遇した場合は、文字列の先頭からその時点で判明している終端文字まで生バイト列として .byte 0xXX, ... にフォールバックする。
//
// e.g. decode_string.ts baserom.gba 0x08CD167C
//   -> .string "<PROC=0>\n<END>$"

export const CHARMAP_PATH = new URL("../../charmap.txt", import.meta.url);
export const READ_WINDOW = 0x2000;
const BYTES_PER_LINE = 16;

export type CharMap = Map<string, string>;

const seqKey = (bytes: Uint8Array): string => Array.from(bytes, (b) => b.toString(16).padStart(2, "0")).join("");
const keyToBytes = (key: string): Uint8Array => Uint8Array.from(key.match(/../g) ?? [], (h) => parseInt(h, 16));

// tools/parser/common/charmap.ts の ParseFile で charmap.txt をパースし、 バイト列(hex文字列) -> 表示文字 の Map に変換する。
export const parseCharmap = (charmapPath: string | URL): CharMap => {
  const entries = ParseFile(charmapPath instanceof URL ? path.fromFileUrl(charmapPath) : charmapPath);
  const charmap: CharMap = new Map();
  for (const entry of entries) {
    // entry.code を直接 hex 化する(Uint8Array.from を経由すると NaN が 0 に クランプされ、"00"(NUL)キーの正しいエントリを上書きしてしまうため)。
    const key = entry.code.map((b) => b.toString(16).padStart(2, "0")).join("");
    charmap.set(key, entry.char);
  }
  return charmap;
};

export const findTerminatorSeq = (charmap: CharMap): Uint8Array => {
  for (const [key, ch] of charmap) {
    if (ch === "$") return keyToBytes(key);
  }
  throw new Error("error: charmap.txt に '$' (終端文字) の定義がありません");
};

export const formatByteDump = (data: Uint8Array): string => {
  const lines: string[] = [];
  for (let i = 0; i < data.length; i += BYTES_PER_LINE) {
    const chunk = data.subarray(i, i + BYTES_PER_LINE);
    lines.push("  .byte " + Array.from(chunk, (b) => `0x${b.toString(16).toUpperCase().padStart(2, "0")}`).join(", "));
  }
  return lines.join("\n");
};

export const indexOfSeq = (data: Uint8Array, seq: Uint8Array): number => {
  outer: for (let i = 0; i <= data.length - seq.length; i++) {
    for (let j = 0; j < seq.length; j++) {
      if (data[i + j] !== seq[j]) continue outer;
    }
    return i;
  }
  return -1;
};

// 終端文字まで正常にデコードできれば .string 用の中身を返す。未定義バイトに
// 遭遇したら null を返す(呼び出し側で生バイトダンプにフォールバックする)。
export const decode = (data: Uint8Array, charmap: CharMap): string | null => {
  const lengths = Array.from(new Set(Array.from(charmap.keys(), (k) => k.length / 2))).sort((a, b) => b - a);

  const out: string[] = [];
  let pos = 0;
  while (true) {
    let matched: [string, string] | null = null;
    for (const length of lengths) {
      const key = seqKey(data.subarray(pos, pos + length));
      if (charmap.has(key)) {
        matched = [key, charmap.get(key)!];
        break;
      }
    }

    if (matched === null) return null;

    const [key, value] = matched;
    pos += key.length / 2;

    if (value === "$") {
      out.push("$");
      break;
    }

    if (value === "\\" || value === '"') {
      out.push("\\" + value);
    } else {
      out.push(value);
    }
  }

  return out.join("");
};

const main = () => {
  new Command()
    .name("decode_string.ts")
    .description("ROM上の文字列を charmap.txt でデコードして .string 形式で標準出力する。")
    .argument("<rom:string>", "Path to a GBA ROM file.")
    .argument("<addr:number>", "ROM address (or file offset) of the string. e.g. 0x08CD167C")
    .action((_, romPath, romAddr) => {
      if (romAddr < gba.BASE) romAddr += gba.BASE;

      const charmap = parseCharmap(CHARMAP_PATH);
      const termSeq = findTerminatorSeq(charmap);

      const rom = new DataView(Deno.readFileSync(romPath).buffer);
      const window = new Uint8Array(gba.getSlice(rom, romAddr, READ_WINDOW));

      const stringBody = decode(window, charmap);
      if (stringBody !== null) {
        console.log(`.string "${stringBody}"`);
        return;
      }

      const end = indexOfSeq(window, termSeq);
      if (end === -1) {
        console.error(`error: 0x${READ_WINDOW.toString(16).toUpperCase()} バイト以内に終端文字が見つかりませんでした (addr=0x${romAddr.toString(16).toUpperCase()})`);
        Deno.exit(1);
      }

      console.log(formatByteDump(window.subarray(0, end + termSeq.length)));
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
