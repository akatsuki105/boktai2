#!/usr/bin/env -S deno run

import { Command } from "@cliffy/command";
import { encodeChar } from "./bokcc/eucjp.ts";
import * as gba from "./common/gba/gba.ts";

// 原典は FileID や VM のキーワードを文字列で書いていて、IDはその文字列のハッシュだった。
// 計算は src/system_0823071c.c の HashName と tools/preproc の BOKHASH と同じで、16bit を5ビット左ローテートしながら1バイトずつ足す。
//
// 日本語の識別子もあるので、文字列は EUC-JP のバイト列にしてからハッシュする (ASCII だけなら UTF-8 と同じ結果になる)。
// 根拠: サブルーチンID 0x0074 (Dvalinn_Create) が "ドヴァリン" の EUC-JP のハッシュと一致する
//
// e.g. tools/hash.ts bg_link_col_arr  -> 0x26BB (BGP_26BB)
// e.g. tools/hash.ts if               -> 0x0D86 (VM_Ctrl_If)
// e.g. tools/hash.ts ドヴァリン        -> 0x0074 (Dvalinn_Create)

// バイト列のハッシュ, ROM 内の文字列をそのまま食わせるときに使う
export const hashBytes = (bytes: Uint8Array | readonly number[]): number => {
  let hash = 0;
  for (const byte of bytes) {
    hash = ((hash << 5) | (hash >>> 11)) & 0xFFFF;
    hash = (hash + byte) & 0xFFFF;
  }
  return hash;
};

// 文字列を EUC-JP にしてからハッシュする, EUC-JP で表せない文字があれば投げる
export const hashName = (s: string): number => {
  const bytes: number[] = [];

  for (const ch of s) {
    const encoded = encodeChar(ch);
    if (!encoded) throw new Error(`EUC-JP で表せない文字 ${JSON.stringify(ch)} が入っています`);
    for (const byte of encoded) bytes.push(byte);
  }

  return hashBytes(bytes);
};

const main = () => {
  new Command()
    .name("hash.ts")
    .description("BOKHASH, HashName() と同様のハッシュ計算をする, 文字列は EUC-JP として扱う")
    .argument("<input:string>", "Input string to hash.")
    .action((_, input) => {
      try {
        console.log(`0x${gba.toHex16(hashName(input))}`);
      } catch (e) {
        console.error(e instanceof Error ? e.message : String(e));
        Deno.exit(1);
      }
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
