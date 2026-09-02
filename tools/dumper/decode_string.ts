#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import * as gba from "../common/gba/gba.ts";
import type { addr } from "../common/gba/gba.ts";

// 指定アドレスから終端文字('$' = charmap.txt上で 0x00 にマップされた文字)まで
// 読み進め、charmap.txt でデコードできた文字列を .string "..." として出力する。
// charmap.txt の裸の識別子(シングルクオートで囲まれていない、例: CTRL85FF = 85 FF)
// に一致したバイト列は {CTRL85FF} のようにブレース付きの名前として出力する。
// デコード中に charmap.txt に存在しない未定義バイトに遭遇した場合は、文字列の
// 先頭からその時点で判明している終端文字まで生バイト列として
// .byte 0xXX, ... (16バイト/行) にフォールバックする。
//
// e.g. decode_string.ts baserom.gba 0x08CD167C
//   -> .string "<PROC=0>\n<END>$"

export const CHARMAP_PATH = new URL("../../charmap.txt", import.meta.url);
export const READ_WINDOW = 0x2000;
const BYTES_PER_LINE = 16;

export type CharMap = Map<string, string>;

const seqKey = (bytes: Uint8Array): string => Array.from(bytes, (b) => b.toString(16).padStart(2, "0")).join("");
const keyToBytes = (key: string): Uint8Array => Uint8Array.from(key.match(/../g) ?? [], (h) => parseInt(h, 16));

// charmap.txt を (charMap, escapeMap, constantMap) に変換する。
//
// charMap: バイト列 -> 表示文字 (例: 80 01 -> 'あ')
// escapeMap: バイト列 -> エスケープ名 (例: 0A -> 'n', 出力時は \n になる)
// constantMap: バイト列 -> 定数名 (シングルクオートなしの裸の識別子。
//   例: 85 FF -> 'CTRL85FF', 出力時は {CTRL85FF} になる)
export const parseCharmap = (text: string): { charMap: CharMap; escapeMap: CharMap; constantMap: CharMap } => {
  const charMap: CharMap = new Map();
  const escapeMap: CharMap = new Map();
  const constantMap: CharMap = new Map();

  for (let line of text.split("\n")) {
    line = line.split(" @")[0].trim();
    if (!line || line.startsWith("@") || !line.includes("=")) continue;

    if (!line.startsWith("'")) {
      // シングルクオートで囲まれていない裸の識別子(定数)。
      const eqIdx = line.indexOf("=");
      const name = line.slice(0, eqIdx).trim();
      const rhs = line.slice(eqIdx + 1).trim();
      const seq = Uint8Array.from(rhs.split(/\s+/).filter(Boolean).map((b) => parseInt(b, 16)));
      constantMap.set(seqKey(seq), name);
      continue;
    }

    // LHS が 'X' や '\X' の場合、X 自体が '=' のこともあるため、
    // 単純に最初の '=' で区切らずクォートの終端を見て区切る。
    const closingIdx = line[1] === "\\" ? 3 : 2;
    if (closingIdx >= line.length || line[closingIdx] !== "'") continue;

    const lhs = line.slice(0, closingIdx + 1);
    const rhs = line.slice(closingIdx + 1).split("=")[1].trim();

    const inner = lhs.slice(1, -1);
    const seq = Uint8Array.from(rhs.split(/\s+/).filter(Boolean).map((b) => parseInt(b, 16)));

    if (inner.startsWith("\\") && inner !== "\\'") {
      escapeMap.set(seqKey(seq), inner.slice(1));
    } else {
      const ch = inner === "\\'" ? "'" : inner;
      charMap.set(seqKey(seq), ch);
    }
  }

  return { charMap, escapeMap, constantMap };
};

export const findTerminatorSeq = (charMap: CharMap): Uint8Array => {
  for (const [key, ch] of charMap) {
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
export const decode = (data: Uint8Array, charMap: CharMap, escapeMap: CharMap, constantMap: CharMap): string | null => {
  const lengths = Array.from(
    new Set([
      ...Array.from(charMap.keys(), (k) => k.length / 2),
      ...Array.from(escapeMap.keys(), (k) => k.length / 2),
      ...Array.from(constantMap.keys(), (k) => k.length / 2),
    ]),
  ).sort((a, b) => b - a);

  const out: string[] = [];
  let pos = 0;
  while (true) {
    let matched: [string, string, "char" | "escape" | "constant"] | null = null;
    for (const length of lengths) {
      const key = seqKey(data.subarray(pos, pos + length));
      if (charMap.has(key)) {
        matched = [key, charMap.get(key)!, "char"];
        break;
      }
      if (escapeMap.has(key)) {
        matched = [key, escapeMap.get(key)!, "escape"];
        break;
      }
      if (constantMap.has(key)) {
        matched = [key, constantMap.get(key)!, "constant"];
        break;
      }
    }

    if (matched === null) return null;

    const [key, value, kind] = matched;
    pos += key.length / 2;

    if (kind === "escape") {
      out.push("\\" + value);
      continue;
    }

    if (kind === "constant") {
      out.push("{" + value + "}");
      continue;
    }

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
    .argument("<addr:string>", "ROM address (or file offset) of the string. e.g. 0x08CD167C")
    .action((_, romPath, addrStr) => {
      let romAddr: addr = Number(addrStr);
      if (romAddr < gba.BASE) romAddr += gba.BASE;

      const { charMap, escapeMap, constantMap } = parseCharmap(Deno.readTextFileSync(CHARMAP_PATH));
      const termSeq = findTerminatorSeq(charMap);

      const rom = new DataView(Deno.readFileSync(romPath).buffer);
      const window = new Uint8Array(gba.getSlice(rom, romAddr, READ_WINDOW));

      const stringBody = decode(window, charMap, escapeMap, constantMap);
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
