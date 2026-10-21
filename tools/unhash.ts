#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import { hashName } from "./hash.ts";
import * as gba from "./common/gba/gba.ts";
import { ParseFile } from "./encoding/constants_header.ts";

// BOKHASH のハッシュ値から元の文字列の候補を逆算する。
//
// 原典は FileID や VM のキーワードを文字列で書いていて、IDはその文字列のハッシュだった (src/system_0823071c.c の HashName)。
// 16bit なので衝突は避けられず、ハッシュが一致しても確定ではない。命名規則と、そのファイルやハンドラの実際の中身が合うかで判断すること。
//
// e.g. tools/unhash.ts 0x922E                                                  -> anm   (DIR_ANIMATION)
// e.g. tools/unhash.ts 0x1FB8 --suffix _anm                                    -> ect   (ANIM_1FB8 = "ect_anm")
// e.g. tools/unhash.ts --header file.h --name-prefix DIR_
// e.g. tools/unhash.ts --header constants/sprite_animation.h --suffix _anm
// e.g. tools/unhash.ts 0xAE6C --prefix h --suffix p --max-len 5          -> h?????p (magic が "HP" なので先頭 h, 末尾 p)

const MASK = 0xFFFF;

// ヘッダは #include に書く綴りで受け取り、ファイル自体は include/ 配下から読む (tools/bokcc/print_context.ts と同じ約束)。
const INCLUDE_DIR = "include";

// 既知の名前 (anm, map, ect_anm, bg_link_col_arr, mask_test_00) に出てくる文字だけを試す。
const ALPHABET = "abcdefghijklmnopqrstuvwxyz0123456789_";

// 表に入れる文字列の最大長。37^3 = 50,653 で、ハッシュの空間 65,536 より小さいので3文字の答えはほぼ一意になる。
const TABLE_LEN = 3;

// 前半と後半に割って突き合わせるので、扱える最大長は TABLE_LEN の2倍。
const MAX_LEN = TABLE_LEN * 2;

// 確定している名前から取れる語彙。候補の順位付けにだけ使う。
const VOCAB = new Set(["anm", "map", "bg", "link", "col", "arr", "mask", "test", "00"]);

// HashName の1文字分。
const stepForward = (h: number, byte: number): number => {
  const rot = ((h << 5) | (h >>> 11)) & MASK;
  return (rot + byte) & MASK;
};

// stepForward の逆。 rotl16(h, 5) = (h' - c) なので、それを rotr16 で戻す。
const stepBack = (h: number, byte: number): number => {
  const rot = (h - byte) & MASK;
  return ((rot >>> 5) | (rot << 11)) & MASK;
};

// 末尾が trailing だと分かっているとき、trailing を食べる前の状態を返す。
const stateBefore = (h: number, trailing: string): number => {
  const bytes = new TextEncoder().encode(trailing);
  let state = h;
  for (let i = bytes.length - 1; i >= 0; i--) state = stepBack(state, bytes[i]);
  return state;
};

// 長さ 1..TABLE_LEN の全文字列を「start から始めたときのハッシュ値 -> 文字列」の表にする。
// start は名前の先頭が分かっている場合にその分を進めた状態で、分からなければ 0。
const buildTable = (start: number): Map<number, string[]> => {
  const table = new Map<number, string[]>();

  const walk = (s: string, h: number) => {
    for (const c of ALPHABET) {
      const next = stepForward(h, c.charCodeAt(0));
      const word = s + c;

      const found = table.get(next);
      if (found === undefined) {
        table.set(next, [word]);
      } else {
        found.push(word);
      }

      if (word.length < TABLE_LEN) walk(word, next);
    }
  };

  walk("", start);
  return table;
};

// 長さ 1..TABLE_LEN の全文字列。結合するときの後半として使うので、開始状態には依存しない。
const allWords = (): string[] => {
  const words: string[] = [];

  const walk = (s: string) => {
    for (const c of ALPHABET) {
      const word = s + c;
      words.push(word);
      if (word.length < TABLE_LEN) walk(word);
    }
  };

  walk("");
  return words;
};

// 名前の形として有り得るものだけ残す。既知の名前はどれも英字で始まり、"__" を含まず、"_" で終わらない。
const isPlausible = (name: string): boolean => /^[a-z][a-z0-9_]*$/.test(name) && !name.includes("__") && !name.endsWith("_");

// "_" で区切った区画のうち語彙に載っているものの数。多いものを先に出す。
const vocabScore = (name: string): number => name.split("_").filter((part) => VOCAB.has(part)).length;

// id になる名前の候補を返す。prefix / suffix が分かっているときは、その間の未知の部分だけを探す。
// table は prefix を食べ終えた状態から作られていること。
const solve = (table: Map<number, string[]>, words: string[], id: number, prefix: string, suffix: string, maxLen: number): string[] => {
  const target = stateBefore(id, suffix);
  const heads = new Set<string>();

  for (const head of table.get(target) ?? []) {
    if (head.length <= maxLen) heads.add(head);
  }

  // TABLE_LEN より長い接頭辞は、前半 a と後半 b に割って16bitの状態で突き合わせる。
  if (maxLen > TABLE_LEN) {
    for (const b of words) {
      const mid = stateBefore(target, b);
      for (const a of table.get(mid) ?? []) {
        const head = a + b;
        if (head.length > TABLE_LEN && head.length <= maxLen) heads.add(head);
      }
    }
  }

  const names: string[] = [];
  for (const head of heads) {
    const name = prefix + head + suffix;
    if (!isPlausible(name)) continue;
    if (hashName(name) !== id) continue; // 逆算の自己検証, 順方向の実装 (preproc とROM一致で裏が取れている) と必ず一致させる
    names.push(name);
  }

  // 未知の部分が0文字、つまり prefix + suffix だけで当たる場合
  const joined = prefix + suffix;
  if (joined.length > 0 && isPlausible(joined) && hashName(joined) === id) names.push(joined);

  return names.sort((a, b) => vocabScore(b) - vocabScore(a) || a.length - b.length || a.localeCompare(b));
};

// --header で、まだ生の16進で定義されている #define だけを集める。BOKHASH("x") 済みのものは値が文字列になるので除かれる。
const readTargets = (include: string, namePrefix: string): { name: string; id: number }[] => {
  const targets: { name: string; id: number }[] = [];

  for (const [name, value] of Object.entries(ParseFile(`${INCLUDE_DIR}/${include}`))) {
    if (typeof value !== "number") continue;
    if (!name.startsWith(namePrefix)) continue;
    if (value < 0 || value > MASK) continue;
    targets.push({ name, id: value });
  }

  return targets;
};

const report = (name: string, id: number, names: string[], limit: number) => {
  const label = name.length > 0 ? `${name.padEnd(24)} ` : "";

  if (names.length === 0) {
    console.log(`${label}0x${gba.toHex16(id)}  候補なし`);
    return;
  }

  const shown = names.slice(0, limit).join(", ");
  const more = names.length > limit ? ` ... 他 ${names.length - limit}件` : "";
  console.log(`${label}0x${gba.toHex16(id)}  ${shown}${more}`);

  // 候補が1つなら、そのまま貼れる形も出す
  if (names.length === 1 && name.length > 0) console.log(`${" ".repeat(label.length)}#define ${name} BOKHASH("${names[0]}")`);
};

const main = () => {
  new Command()
    .name("unhash.ts")
    .description("BOKHASH のハッシュ値から元の文字列の候補を逆算する")
    .argument("[id:string]", "逆算するハッシュ値 (0x1FB8 のように 0x 付きの16進数), --header と併用不可")
    .option("--header <include:string>", `対象のIDをヘッダから読む, #include に書く綴りで指定する (${INCLUDE_DIR}/ 配下から読む), まだ生の16進で定義されている #define だけを対象にする`)
    .option("--name-prefix <prefix:string>", "--header のときに対象を絞るマクロ名の接頭辞, e.g. ANIM_", { default: "" })
    .option("--prefix <prefix:string>", "名前の先頭が分かっている場合に指定する, e.g. h", { default: "" })
    .option("--suffix <suffix:string>", "名前の末尾が分かっている場合に指定する, e.g. _anm", { default: "" })
    .option("--max-len <n:number>", `prefix と suffix の間の未知の部分として試す最大の長さ (1〜${MAX_LEN})`, { default: TABLE_LEN })
    .option("--limit <n:number>", "1件あたりに表示する候補の最大数", { default: 10 })
    .action((opts, id) => {
      if ((id === undefined) === (opts.header === undefined)) {
        console.error("ハッシュ値か --header のどちらか一方を指定してください");
        Deno.exit(1);
      }

      const maxLen = opts.maxLen;
      if (maxLen < 1 || maxLen > MAX_LEN) {
        console.error(`--max-len は 1〜${MAX_LEN} で指定してください (前半と後半に割って突き合わせるため ${TABLE_LEN} の2倍が上限)`);
        Deno.exit(1);
      }

      const targets = opts.header !== undefined ? readTargets(opts.header, opts.namePrefix) : [{ name: "", id: Number(id) }];
      if (targets.length === 0) {
        console.error("対象のIDがありません");
        Deno.exit(1);
      }
      for (const t of targets) {
        if (!Number.isInteger(t.id) || t.id < 0 || t.id > MASK) {
          console.error(`16bitのハッシュ値として読めません: ${t.name.length > 0 ? t.name : id}`);
          Deno.exit(1);
        }
      }

      const table = buildTable(hashName(opts.prefix));
      const words = maxLen > TABLE_LEN ? allWords() : [];

      for (const t of targets) report(t.name, t.id, solve(table, words, t.id, opts.prefix, opts.suffix, maxLen), opts.limit);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
