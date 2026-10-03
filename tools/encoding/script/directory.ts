import * as gba from "../../common/gba/gba.ts";
import type { addr } from "../../common/gba/gba.ts";

export type ScriptDirectory = {
  // スクリプトの先頭アドレスの配列(注意: スクリプトIDがnのスクリプトアドレスは scripts[n-1] で取得する)
  // スクリプトIDと配置順が一致するとは限らない & 同じスクリプトが複数のIDで参照されることもあるので注意
  scripts: addr[];

  // 文字列の先頭アドレスの配列(こちらは文字列IDがそのままインデックス)
  strings: {
    attr: number; // bit0..30: オフセット, bit31 が 1 なら 文字列, 0 ならバイナリデータ
    size: number; // バイト単位のサイズ, 注意: 次のエントリのオフセットとの差分なのでアラインメントされているものは実際のサイズより大きく計算される
    addr: addr;
  }[];
};

export const ParseScriptDirectory = (rom: DataView, start: addr): ScriptDirectory => {
  let p: addr = start;
  p += 4;

  const scriptEntry: number[] = [];
  while (true) {
    const offset = gba.getU32(rom, p);
    p += 4;
    if (offset === 0xFFFFFFFF) break;
    scriptEntry.push(offset);
  }

  const scriptData: addr = p + gba.getU32(rom, p);

  const stringEntry: addr = p + gba.getU32(rom, p + 4);
  const stringData: addr = p + gba.getU32(rom, p + 8);
  const stringDataEnd: addr = p + gba.getU32(rom, p + 12);
  p += 16;

  const scripts: addr[] = [];
  for (const offset of scriptEntry) {
    scripts.push(scriptData + 4 + (offset & 0x00FFFFFF)); // 先頭4バイトはスクリプト全体のサイズなので飛ばす
  }

  const strings: { attr: number; size: number; addr: addr }[] = [];
  const stringCount = (stringData - stringEntry) >> 2;
  if (stringCount !== 7141) throw new Error(`Unexpected string count: ${stringCount} (expected 7141)`);
  for (let i = 0; i < stringCount; i++) {
    const attr = gba.getU32(rom, stringEntry + (i * 4));
    const offset = attr & 0x7FFFFFFF;
    const addr: addr = stringData + offset;
    const nextAddr: addr = (i === stringCount - 1) ? stringDataEnd : (stringData + (gba.getU32(rom, stringEntry + ((i + 1) * 4)) & 0x7FFFFFFF));
    const size = nextAddr - addr;
    strings.push({ attr, size, addr });
  }

  return { scripts, strings };
};
