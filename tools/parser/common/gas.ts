export type GasFunction = {
  name: string;
  kind: "arm" | "thumb" | "non_word_aligned_thumb";
  extracted: boolean; // 本体が asm/func/NAME.inc への .include に切り出し済みか
  // addr: number | null; // ラベル行の `@ 0x08xxxxxx` から。コメントが無ければ null
};

// .s / .inc の中身から、そこに定義されている関数の一覧を返す(ファイル中の出現順)。
export const listFunctions = (text: string): GasFunction[] => {
  const funcStartRe = /^\s*(arm|thumb|non_word_aligned_thumb)_func_start\s+(\S+)/;
  // const labelRe = /^(\S+):\s*(?:@\s*0x([0-9A-Fa-f]+))?/;

  const lines = text.split("\n");
  const funcs: GasFunction[] = [];

  for (let i = 0; i < lines.length; i++) {
    const m = funcStartRe.exec(lines[i]);
    if (m === null) continue;
    const [, kind, name] = m;

    // 直後のラベル行からアドレスを拾う。マクロの引数と食い違う行(= ラベルが無い)は無視する
    // const label = labelRe.exec(lines[i + 1] ?? "");
    // const addr = label !== null && label[1] === name && label[2] !== undefined ? parseInt(label[2], 16) : null;

    funcs.push({
      name,
      kind: kind as GasFunction["kind"],
      extracted: (lines[i + 2] ?? "").trim().startsWith(".include"),
      // addr,
    });
  }

  return funcs;
};
