import { ParseFile } from "../encoding/constants_header.ts";
import { toHex } from "./instruction.ts";
import type { PrintContext } from "./instruction.ts";

// デコンパイル専用。出力で識別子に名前を出すための表(PrintContext)を、Cのヘッダから作る。
//
// .bokc 側では数値でしかない文字列IDなどを、include/ のヘッダで定義されたマクロ名で出力するために使う。
// コンパイル時のマクロ展開はCプリプロセッサの仕事なので、こちらはデコンパイル(ROMから.bokcをダンプする処理)専用。

// ヘッダは #include に書く綴りで受け取り、ファイル自体はこのディレクトリ配下から読む。
// Makefile 側の cpp も -iquote include で解決するので、2つの綴りが食い違わない。
export const INCLUDE_DIR = "include";

// ヘッダの #define を「値 -> 名前」に反転する。同じ値に2つの名前が付いていると、どちらを出しても検証できないのでエラーにする。
const loadNames = (include: string): ReadonlyMap<number, string> => {
  const names = new Map<number, string>();
  for (const [name, value] of Object.entries(ParseFile(`${INCLUDE_DIR}/${include}`))) {
    if (typeof value !== "number") continue; // 値が式やマクロ参照のものは名前として使えない
    const defined = names.get(value);
    if (defined !== undefined) {
      throw new Error(`${include}: 0x${toHex(value, 4)} に ${defined} と ${name} の2つの名前が定義されています`);
    }
    names.set(value, name);
  }
  return names;
};

// デコンパイル結果に名前を出すためのコンテキストを、namespace ごとのヘッダから作る。
export const buildPrintContext = (headers: { strings?: string }): PrintContext => ({
  stringNames: headers.strings ? loadNames(headers.strings) : undefined,
});
