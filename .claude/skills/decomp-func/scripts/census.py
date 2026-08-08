#!/usr/bin/env -S uv run python3
"""レベル2・3の未一致関数をサイズ昇順で列挙する。

リポジトリのルートから実行すること。出力形式は TSV: size<TAB>name<TAB>inc_path
- レベル2: NAKED + INCFUNC (C シグネチャはあるが実装なし)
- レベル3: NON_MATCH + INCFUNC (C 実装はあるが一致しない)
"""

import re
import subprocess
import sys
from pathlib import Path

REPO = Path(
    subprocess.run(["git", "rev-parse", "--show-toplevel"], capture_output=True, text=True).stdout.strip()
)


def collect_targets():
    """src/ の各 .c ファイルを行ごとに走査して NAKED / NON_MATCH 関数を収集する。

    NAKED の場合:    同じ行に INCFUNC がある
    NON_MATCH の場合: #else ブロック内に INCFUNC がある
    """
    targets = {}  # name -> inc の相対パス

    for src_file in sorted((REPO / "src").glob("*.c")):
        state = None        # "NON_MATCH" | None
        current_name = None
        in_else = False     # #else に入ったかどうか

        for line in src_file.read_text(encoding="utf-8", errors="replace").splitlines():
            s = line.strip()

            # 先頭が NAKED または NON_MATCH の関数定義行を検出する
            m = re.match(r"(NAKED|NON_MATCH)\s+\S+\s+(\w+)\s*\(", s)
            if m:
                level = m.group(1)
                name = m.group(2)
                if level == "NAKED":
                    # NAKED は同じ行に INCFUNC がある
                    inc_m = re.search(r'INCFUNC\("(asm/func/[^"]+\.inc)"\)', s)
                    if inc_m:
                        targets[name] = inc_m.group(1)
                else:
                    # NON_MATCH: #else ブロック内の INCFUNC を待つ
                    state = "NON_MATCH"
                    current_name = name
                    in_else = False
                continue

            if state == "NON_MATCH" and current_name:
                if s == "#else":
                    in_else = True
                elif s == "#endif":
                    # ブロック終端
                    state = None
                    current_name = None
                    in_else = False
                elif in_else:
                    inc_m = re.search(r'INCFUNC\("(asm/func/[^"]+\.inc)"\)', s)
                    if inc_m:
                        targets[current_name] = inc_m.group(1)
                        state = None
                        current_name = None
                        in_else = False

    return targets


def estimate_size(inc_path):
    """inc ファイルの命令行からバイトサイズを推定する。"""
    est = 0
    for line in inc_path.read_text(encoding="utf-8", errors="replace").splitlines():
        s = line.strip()
        if (
            not s
            or s.startswith(("@", ".align", ".include", ".syntax", ".text", ".thumb",
                              "thumb_func", "arm_func"))
            or s.endswith(":")
        ):
            continue
        if s.startswith(".4byte"):
            est += 4
        elif s.startswith((".short", ".2byte")):
            est += 2
        elif s.startswith(".byte"):
            est += 1
        elif not s.startswith("."):
            est += 2
    return est


def main():
    targets = collect_targets()
    if not targets:
        print("対象関数が見つかりませんでした", file=sys.stderr)
        return 1

    rows = []
    for name, inc_rel in targets.items():
        inc_path = REPO / inc_rel
        size = estimate_size(inc_path) if inc_path.exists() else 0
        rows.append((size, name, inc_rel))

    rows.sort()
    for size, name, inc in rows:
        print(f"{size}\t{name}\t{inc}")
    print(f"# {len(rows)} functions remaining", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
