#!/usr/bin/env -S deno run --allow-read

import { Command } from "@cliffy/command";
import { hashName } from "./hash.ts";
import * as gba from "./common/gba/gba.ts";

// BOKHASH のハッシュ値から元の文字列の候補を逆算する。
//
// 原典は FileID や VM のキーワードを文字列で書いていて、IDはその文字列のハッシュだった (src/system_0823071c.c の HashName)。
// 16bit なので衝突は避けられず、ハッシュが一致しても確定ではない。命名規則と、そのファイルやハンドラの実際の中身が合うかで判断すること。
//
// e.g. tools/unhash.ts 0x922E                                                  -> anm   (DIR_ANIMATION)
// e.g. tools/unhash.ts 0x1FB8 --suffix _anm                                    -> ect   (ANIM_1FB8 = "ect_anm")
// e.g. tools/unhash.ts 0xAE6C --prefix h --suffix p --max-len 5          -> h?????p (magic が "HP" なので先頭 h, 末尾 p)
// e.g. tools/unhash.ts 0x26BB --contains link --suffix _col_arr             -> bg_link_col_arr (BGP_LINK, "link" の前後を探す)
// e.g. tools/unhash.ts 0x26BB --contains link,col --suffix _arr --max-len 4    -> bg_link_col_arr ("link" と "col" を両方含む)

const MASK = 0xFFFF;

// 未知の部分に試す文字の既定値。既知の名前 (anm, map, ect_anm, bg_link_col_arr, mask_test_00) に出てくる文字だけを試す。
const DEFAULT_CHARSET = "abcdefghijklmnopqrstuvwxyz0123456789_";

// 表に入れる文字列の最大長。既定の文字セットなら 37^3 = 50,653 で、ハッシュの空間 65,536 より小さいので3文字の答えはほぼ一意になる。
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
const buildTable = (charset: string, start: number): Map<number, string[]> => {
  const table = new Map<number, string[]>();

  const walk = (s: string, h: number) => {
    for (const c of charset) {
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
const allWords = (charset: string): string[] => {
  const words: string[] = [];

  const walk = (s: string) => {
    for (const c of charset) {
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

// 重複を除いた全ての並び順。
const permutations = (items: string[]): string[][] => {
  if (items.length <= 1) return [items];

  const result = new Map<string, string[]>();
  items.forEach((item, i) => {
    for (const rest of permutations([...items.slice(0, i), ...items.slice(i + 1)])) {
      const order = [item, ...rest];
      result.set(JSON.stringify(order), order);
    }
  });
  return [...result.values()];
};

// 名前が contains を全て含むと分かっているときの候補を返す。contains の並び順は分からないので全ての順列を試す。
// 名前は prefix + head + c0 + gap0 + c1 + gap1 + ... + cN + tail + suffix の形で、head 以外の未知の部分 (間と tail) は合計 TABLE_LEN 文字までを後ろから総当たりし、残った状態になる head を表で引く。
// table は prefix を食べ終えた状態から作られていること。
const solveContains = (table: Map<number, string[]>, words: string[], id: number, prefix: string, contains: string[], suffix: string, maxLen: number, headLen: number, tailLen: number): string[] => {
  const start = hashName(prefix);
  const target = stateBefore(id, suffix);
  const names = new Set<string>();

  // 長さごとに分けておく, 0文字は空文字列だけ
  const byLen: string[][] = [[""]];
  for (const word of words) (byLen[word.length] ??= []).push(word);

  const budget = Math.min(TABLE_LEN, maxLen);

  for (const order of permutations(contains)) {
    const gaps: string[] = new Array(order.length);

    // order[i] の直後の未知の部分を末尾から順に決め、state をその手前まで巻き戻していく
    const walk = (i: number, state: number, used: number) => {
      if (i < 0) {
        const heads = state === start ? ["", ...(table.get(state) ?? [])] : (table.get(state) ?? []);
        for (const head of heads) {
          if (head.length > headLen || head.length + used > maxLen) continue;
          const name = prefix + head + order.map((c, j) => c + gaps[j]).join("") + suffix;
          if (!isPlausible(name)) continue;
          if (hashName(name) !== id) continue; // 逆算の自己検証
          names.add(name);
        }
        return;
      }

      const limit = i === order.length - 1 ? Math.min(budget - used, tailLen) : budget - used;
      for (let len = 0; len <= limit; len++) {
        for (const gap of byLen[len] ?? []) {
          gaps[i] = gap;
          walk(i - 1, stateBefore(stateBefore(state, gap), order[i]), used + len);
        }
      }
    };

    walk(order.length - 1, target, 0);
  }

  return [...names].sort((a, b) => vocabScore(b) - vocabScore(a) || a.length - b.length || a.localeCompare(b));
};

const report = (id: number, names: string[], limit: number) => {
  if (names.length === 0) {
    console.log(`0x${gba.toHex16(id)}  候補なし`);
    return;
  }

  const shown = names.slice(0, limit).join(", ");
  const more = names.length > limit ? ` ... 他 ${names.length - limit}件` : "";
  console.log(`0x${gba.toHex16(id)}  ${shown}${more}`);
};

const main = () => {
  new Command()
    .name("unhash.ts")
    .description("BOKHASH のハッシュ値から元の文字列の候補を逆算する")
    .argument("<id:string>", "逆算するハッシュ値 (0x1FB8 のように 0x 付きの16進数)")
    .option("-p, --prefix <prefix:string>", "名前の先頭が分かっている場合に指定する, e.g. h", { default: "" })
    .option("-s, --suffix <suffix:string>", "名前の末尾が分かっている場合に指定する, e.g. _anm", { default: "" })
    .option("--charset <chars:string>", "未知の部分に試す文字を並べて指定する (a-z0-9_ の中から), e.g. abcdefghijklmnopqrstuvwxyz", { default: DEFAULT_CHARSET })
    .option("-c, --contains <strs:string[]>", "名前のどこかに含まれると分かっている文字列, \",\" で区切って複数指定すると全てを含むものを探す (順番は問わない), e.g. link,col")
    .option("--head-len <n:number>", `先頭の --contains の前に来る未知の部分の最大の長さ (0〜${TABLE_LEN})`, { default: TABLE_LEN })
    .option("--tail-len <n:number>", `末尾の --contains の後に来る未知の部分の最大の長さ (0〜${TABLE_LEN})`, { default: TABLE_LEN })
    .option("-m,--max-len <n:number>", `prefix と suffix の間の未知の部分として試す最大の長さ (1〜${MAX_LEN}), --contains のときは未知の部分全体の合計で、head 以外は合計 ${TABLE_LEN} まで`, { default: TABLE_LEN })
    .option("-l, --limit <n:number>", "1件あたりに表示する候補の最大数", { default: 100 })
    .action((opts, idArg) => {
      const maxLen = opts.maxLen;
      if (maxLen < 1 || maxLen > MAX_LEN) {
        console.error(`--max-len は 1〜${MAX_LEN} で指定してください (前半と後半に割って突き合わせるため ${TABLE_LEN} の2倍が上限)`);
        Deno.exit(1);
      }

      for (const [flag, n] of [["--head-len", opts.headLen], ["--tail-len", opts.tailLen]] as const) {
        if (n < 0 || n > TABLE_LEN) {
          console.error(`${flag} は 0〜${TABLE_LEN} で指定してください`);
          Deno.exit(1);
        }
      }

      const id = Number(idArg);
      if (!Number.isInteger(id) || id < 0 || id > MASK) {
        console.error(`16bitのハッシュ値として読めません: ${idArg}`);
        Deno.exit(1);
      }

      // isPlausible が a-z0-9_ 以外を含む名前を捨てるので、それ以外の文字は試しても候補にならない
      const charset = [...new Set(opts.charset)].join("");
      if (!/^[a-z0-9_]+$/.test(charset)) {
        console.error(`--charset は a-z0-9_ の文字だけで指定してください: ${opts.charset}`);
        Deno.exit(1);
      }

      const table = buildTable(charset, hashName(opts.prefix));
      // 他の指定に含まれる文字列は、そちらを含めば必ず含むので外す
      const contains = [...new Set(opts.contains ?? [])].filter((c, _, all) => !all.some((other) => other !== c && other.includes(c)));

      if (contains.length > 0) {
        report(id, solveContains(table, allWords(charset), id, opts.prefix, contains, opts.suffix, maxLen, opts.headLen, opts.tailLen), opts.limit);
        return;
      }

      const words = maxLen > TABLE_LEN ? allWords(charset) : [];
      report(id, solve(table, words, id, opts.prefix, opts.suffix, maxLen), opts.limit);
    })
    .parse(Deno.args);
};

if (import.meta.main) main();
