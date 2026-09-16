import * as gba from "../../common/gba/gba.ts";
import type { addr } from "../../common/gba/gba.ts";
import * as GAS from "../gas/gas.ts";

export type Directory = {
  addr: addr; // ディレクトリの先頭アドレス
  entryNum: number; // ファイル数
  offsetToIDs: number; // ファイルIDの配列へのオフセット
  offsetToFileOffsets: number;
  offsetTo1stFile: number;
  ids: number[]; // ファイルIDの配列
  fileOffsets: number[]; // ファイルのオフセットの配列
};

export const ParseDirectory = (rom: DataView, dirAddr: addr): Directory => {
  const start = dirAddr;
  const entryNum: number = gba.getU32(rom, start);
  const offsetToIDs: number = gba.getU32(rom, start + 4);
  const offsetToFileOffsets: number = gba.getU32(rom, start + 8);
  const offsetTo1stFile: number = gba.getU32(rom, start + 12);

  const ids: number[] = Array(entryNum).fill(0);
  const fileOffsets: number[] = Array(entryNum).fill(0);
  for (let i = 0; i < entryNum; i++) {
    ids[i] = gba.getU16(rom, (start + offsetToIDs) + i * 2);
    fileOffsets[i] = gba.getU32(rom, (start + offsetToFileOffsets) + i * 4);
  }
  return { addr: start, entryNum, offsetToIDs, offsetToFileOffsets, offsetTo1stFile, ids, fileOffsets };
};

export const StringifyDirectory = (data: Directory, indent: string = "  "): string => {
  const lines: string[] = [];
  lines.push(indent + `.4byte ${data.entryNum} @ entry count`);
  lines.push(indent + `.4byte 0x${data.offsetToIDs.toString(16).toUpperCase()}, 0x${data.offsetToFileOffsets.toString(16).toUpperCase()}, 0x${data.offsetTo1stFile.toString(16).toUpperCase()}`);
  lines.push("\n@ FileIDs");
  const ids = data.ids;
  if (ids.length % 2 !== 0) ids.push(0); // パディングとして0を追加
  lines.push(GAS.dumpU16array(ids, indent, 16));
  lines.push("@ FileOffsets");
  const offsets = data.fileOffsets;
  if (offsets.length % 2 !== 0) offsets.push(0); // パディングとして0を追加, 8バイトアラインメントかと思ったが、そうでもない
  lines.push(GAS.dumpU32array(offsets, indent, 8));
  return lines.join("\n");
};
