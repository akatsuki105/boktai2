#!/usr/bin/env -S uv run python3
"""巨大な src/code_*.s を分割する前に、関数境界ごとの手がかりを要約する。

ファイル全体を読むのはこのスクリプト自身(Claude ではない)。出力はコンパクトな
一覧なので、巨大ファイルでも安全に確認できる。

各関数について:
  - 開始行・行数(概算サイズ)
  - 呼び出し先(bl のターゲット)
  - 参照している定数プール値(.4byte)
  - 直前の関数と呼び出し先/定数を共有していれば明示 (-> そこでは切らない方がよい)

Usage: split-summary.py <path/to/code_XXXXXXXX.s>
"""
import re
import sys
from pathlib import Path


def parse_functions(lines: list[str]) -> list[tuple[str, int, int]]:
    """(name, start_line_idx, end_line_idx) のリストを返す。境界は thumb_func_start。"""
    funcs = []
    start = None
    name = None
    for i, line in enumerate(lines):
        m = re.match(r"\s*thumb_func_start\s+(\S+)", line)
        if m:
            if start is not None:
                funcs.append((name, start, i))
            start = i
            name = m.group(1)
    if start is not None:
        funcs.append((name, start, len(lines)))
    return funcs


def extract_signals(lines: list[str], start: int, end: int) -> tuple[set[str], set[str]]:
    callees: set[str] = set()
    consts: set[str] = set()
    for line in lines[start:end]:
        m = re.search(r"\bbl\s+(\S+)", line)
        if m:
            callees.add(m.group(1))
        m = re.search(r"\.4byte\s+(\S+)", line)
        if m:
            consts.add(m.group(1))
    return callees, consts


def fmt_set(s: set[str], limit: int = 6) -> str:
    items = sorted(s)
    shown = ", ".join(items[:limit])
    more = f", …+{len(items) - limit}" if len(items) > limit else ""
    return f"[{shown}{more}]"


def main() -> None:
    if len(sys.argv) != 2:
        sys.exit("usage: split-summary.py <path/to/code_XXXXXXXX.s>")
    path = Path(sys.argv[1])
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    funcs = parse_functions(lines)

    print(f"# {path}  —  {len(funcs)} functions, {len(lines)} lines\n")

    prev_callees: set[str] | None = None
    prev_consts: set[str] | None = None
    for name, start, end in funcs:
        callees, consts = extract_signals(lines, start, end)
        size = end - start

        note = ""
        if prev_callees is not None:
            shared_c = callees & prev_callees
            shared_k = consts & prev_consts
            bits = []
            if shared_c:
                bits.append(f"callees={fmt_set(shared_c, 4)}")
            if shared_k:
                bits.append(f"consts={fmt_set(shared_k, 4)}")
            if bits:
                note = "  <-- shares with prev, consider NOT cutting here: " + "; ".join(bits)

        print(
            f"L{start + 1:<7} {name:<28} {size:>5}L  "
            f"calls={fmt_set(callees)}  consts={fmt_set(consts)}{note}"
        )
        prev_callees, prev_consts = callees, consts


if __name__ == "__main__":
    main()
