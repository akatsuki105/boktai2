#!/usr/bin/env python3
"""ひとつの .inc ファイルを複数の空スタブ関数の位置で分割する。

Usage: split_inc_multi.py <inc_path> <fn1> [<fn2> ...]

指定した関数名の thumb_func_start 行を境界として <base>_p1.inc, <base>_p2.inc ...
を生成し、元の .inc ファイルを削除する。生成したファイル名を標準出力に列挙する。

例:
  tools/split_inc_multi.py asm/code_082422f0.inc FUN_082423a8 removeSpecifiedItem
  → asm/code_082422f0_p1.inc  (FUN_082423a8 の前の部分)
  → asm/code_082422f0_p2.inc  (FUN_082423a8, FUN_082423a8 ～ removeSpecifiedItem の間)
  → asm/code_082422f0_p3.inc  (removeSpecifiedItem 以降)
"""
import re
import sys
from pathlib import Path

PRELUDE = [
    '\t.include "asm/macros.inc"',
    "",
    "\t.syntax unified",
    "",
    "\t.text",
    "",
]


def main() -> None:
    if len(sys.argv) < 3:
        sys.exit("usage: split_inc_multi.py <inc_path> <fn1> [<fn2> ...]")

    inc = Path(sys.argv[1])
    fns = sys.argv[2:]
    text = inc.read_text()
    lines = text.split("\n")

    cuts: list[tuple[int, int]] = []
    for fn in fns:
        start = None
        for i, ln in enumerate(lines):
            if re.match(rf"\s*thumb_func_start\s+{re.escape(fn)}\b", ln):
                start = i
                break
        if start is None:
            sys.exit(f"エラー: thumb_func_start {fn} が見つかりません")
        end = len(lines)
        for j in range(start + 1, len(lines)):
            if re.match(r"\s*thumb_func_start\s+\w", lines[j]):
                end = j
                break
        cuts.append((start, end))

    cuts.sort()

    parts: list[list[str]] = []
    prev = 0
    for start, end in cuts:
        parts.append(lines[prev:start])
        prev = end
    parts.append(lines[prev:])

    for p in parts:
        while p and p[-1].strip() == "":
            p.pop()

    base = inc.with_suffix("")
    for i, p in enumerate(parts):
        path = Path(str(base) + f"_p{i + 1}.inc")
        if i == 0:
            path.write_text("\n".join(p) + "\n")
        else:
            content = PRELUDE.copy()
            while p and p[0].strip() == "":
                p.pop(0)
            content.extend(p)
            path.write_text("\n".join(content) + "\n")
        print(path)

    inc.unlink()


if __name__ == "__main__":
    main()
