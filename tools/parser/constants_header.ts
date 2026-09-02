export type HeaderDefines = Record<string, number | string>;

// C ヘッダファイルの `#define XXX value` の行だけをパースする、非常に単純なパーサ。
// それ以外の行(#ifndef/#endif や値のない #define など)は無視し、value の評価 (式展開やマクロ参照の解決など)も行わない。
export const parseHeaderDefines = (path: string): HeaderDefines => {
  const text = Deno.readTextFileSync(path);
  const result: HeaderDefines = {};

  for (const line of text.split("\n")) {
    const m = line.match(/^\s*#\s*define\s+(\w+)\s+(.+)$/);
    if (!m) continue;

    const name = m[1];
    const value = m[2].split("//")[0].trim();
    if (!value) continue;

    const num = Number(value);
    result[name] = Number.isNaN(num) ? value : num;
  }

  return result;
};
