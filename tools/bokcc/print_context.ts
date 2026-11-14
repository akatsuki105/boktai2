import { ParseFile } from "../encoding/constants_header.ts";
import { toHex } from "./instruction.ts";
import type { PrintContext } from "./instruction.ts";

// デコンパイル専用。出力で識別子に名前を出すための表(PrintContext)を、Cのヘッダから作る。
//
// .bokc 側では数値でしかない文字列IDなどを、ヘッダで定義されたマクロ名で出力するために使う。
// コンパイル時のマクロ展開はCプリプロセッサの仕事なので、こちらはデコンパイル(ROMから.bokcをダンプする処理)専用。

// ヘッダの #define を「値 -> 名前」に反転する。同じ値に2つの名前が付いていると、どちらを出しても検証できないのでエラーにする。
const loadNames = (path: string): ReadonlyMap<number, string> => {
  const names = new Map<number, string>();
  for (const [name, value] of Object.entries(ParseFile(path))) {
    if (typeof value !== "number") continue; // 値が式やマクロ参照のものは名前として使えない
    const defined = names.get(value);
    if (defined !== undefined) {
      throw new Error(`${path}: 0x${toHex(value, 4)} に ${defined} と ${name} の2つの名前が定義されています`);
    }
    names.set(value, name);
  }
  return names;
};

// script.h の行末コメントを「ID -> コメント」にする, ダンパーが定義の直前のアドレスコメントにそのまま付け足す
// e.g. #define Scr_AddFriendship 0x0236  // p0=who, p1=amount 好感度を増減する
// コメントなので cpp も parser も読まない
const loadComments = (path: string): ReadonlyMap<number, string> => {
  const comments = new Map<number, string>();
  for (const line of Deno.readTextFileSync(path).split("\n")) {
    const m = /^#define\s+\w+\s+(0x[0-9A-Fa-f]+|[0-9]+)\s*\/\/\s*(.*?)\s*$/.exec(line);
    if (m === null || m[2] === "") continue;
    comments.set(Number(m[1]), m[2]);
  }
  return comments;
};

// stat.h / world.h / scratch.h のメモリ参照のマクロを「綴り -> 名前」にする, e.g. #define PLAYER_X *((s16 *)(stat + 0x30))
// .bokc では括弧が式の命令になるので, マクロの中身は外側を括弧で囲まない
const loadMemoryNames = (paths: readonly string[]): ReadonlyMap<string, string> => {
  const names = new Map<string, string>();
  for (const path of paths) for (const line of Deno.readTextFileSync(path).split("\n")) {
    const m = /^#define\s+(\w+)\s+((?:\*|BIT\().*?)\s*(?:\/\/.*)?$/.exec(line);
    if (m === null) continue;
    const defined = names.get(m[2]);
    if (defined !== undefined) throw new Error(`${path}: ${m[2]} に ${defined} と ${m[1]} の2つの名前が定義されています`);
    names.set(m[2], m[1]);
  }
  return names;
};

// stat.h / world.h / scratch.h の添字付きメモリ参照のマクロを「添字の位置を \0 にした綴り -> 名前」にする
// e.g. #define FRIENDSHIP(i) ((s16 *)(stat + 0x2FE))[5, i], #define W_CHEST_OPENED(i) BIT(world + 0x1A8, 0, (u8)100, i)
const loadMemoryIndexedNames = (paths: readonly string[]): ReadonlyMap<string, string> => {
  const names = new Map<string, string>();
  for (const path of paths) for (const line of Deno.readTextFileSync(path).split("\n")) {
    const m = /^#define\s+(\w+)\((\w+)\)\s+(.*?)\s*(?:\/\/.*)?$/.exec(line);
    if (m === null) continue;
    const parts = m[3].split(new RegExp(`\\b${m[2]}\\b`));
    if (parts.length !== 2) throw new Error(`${path}: ${m[1]} の中身に引数 ${m[2]} がちょうど1回出てくる必要があります`);
    names.set(parts.join("\0"), m[1]);
  }
  return names;
};

// デコンパイル結果に名前を出すためのコンテキストを、namespace ごとのヘッダから作る。
export const buildPrintContext = (headers: { strings?: string; scripts?: string; commands?: string; stat?: string; world?: string; scratch?: string }): PrintContext => {
  const memory = [headers.stat, headers.world, headers.scratch].filter((p): p is string => p !== undefined);
  return {
    stringNames: headers.strings ? loadNames(headers.strings) : undefined,
    scriptNames: headers.scripts ? loadNames(headers.scripts) : undefined,
    commandNames: headers.commands ? loadNames(headers.commands) : undefined,
    scriptComments: headers.scripts ? loadComments(headers.scripts) : undefined,
    memoryNames: memory.length > 0 ? loadMemoryNames(memory) : undefined,
    memoryIndexedNames: memory.length > 0 ? loadMemoryIndexedNames(memory) : undefined,
  };
};
