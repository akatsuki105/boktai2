#!/usr/bin/env -S uv run python3
"""Get Context for Claude to decompile a function.
Context includes:
- the original asm
- the current C implementation
    - if the function is NAKED, generate C from the asm using m2c
    - if the function is NON_MATCH, use the existing C implementation

Usage: scripts/context.py <FUNCTION_NAME> <SRC_FILE> <ASM_FILE>

e.g. scripts/context.py FUN_08242b88 src/weapon.c asm/func/FUN_08242b88.inc
"""

import os
import re
import subprocess
import shutil
import sys
import tempfile
from pathlib import Path

REPO = Path(
    subprocess.run(
        ["git", "rev-parse", "--show-toplevel"], capture_output=True, text=True
    ).stdout.strip()
)


# m2c: https://github.com/matt-kempster/m2c
# m2c.py --target gba -f <FUNCTION_NAME> <ASM_FILE>
# ASM_FILE:
#
# .syntax unified
# .text
# 	thumb_func_start <FUNCTION_NAME>
# <FUNCTION_NAME>:
#  {.inc asm file contents}
def find_m2c():
    if shutil.which("m2c"):
        return ["m2c"]
    return None


def hr():
    print("=" * 60)


def detect_level(src_file: Path, fn: str) -> str | None:
    """src ファイルを走査して関数が NAKED か NON_MATCH かを返す。"""
    for line in src_file.read_text(encoding="utf-8", errors="replace").splitlines():
        s = line.strip()
        if re.match(rf"NAKED\s+\S+\s+{re.escape(fn)}\s*\(", s):
            return "NAKED"
        if re.match(rf"NON_MATCH\s+\S+\s+{re.escape(fn)}\s*\(", s):
            return "NON_MATCH"
    return None


def extract_func_block(src_file: Path, fn: str) -> str:
    """NON_MATCH 関数のブロック全体（関数定義行から閉じ括弧まで）を返す。"""
    lines = src_file.read_text(encoding="utf-8", errors="replace").splitlines()
    start = None
    for i, line in enumerate(lines):
        if re.match(rf"NON_MATCH\s+\S+\s+{re.escape(fn)}\s*\(", line.strip()):
            start = i
            break
    if start is None:
        return f"(NON_MATCH 実装が見つかりませんでした: {fn})"

    # ブレース深度でブロック終端を探す
    depth = 0
    entered = False
    for i in range(start, len(lines)):
        for ch in lines[i]:
            if ch == "{":
                depth += 1
                entered = True
            elif ch == "}":
                depth -= 1
        if entered and depth == 0:
            return "\n".join(lines[start : i + 1])

    return "\n".join(lines[start:])


def main():
    if len(sys.argv) < 4:
        print(
            f"Usage: {sys.argv[0]} <FUNCTION_NAME> <SRC_FILE> <ASM_FILE>",
            file=sys.stderr,
        )
        sys.exit(1)

    fn = sys.argv[1]
    src_file = REPO / sys.argv[2]
    asm_file = REPO / sys.argv[3]

    # 1. TARGET ASSEMBLY
    hr()
    print(f"TARGET ASSEMBLY: {asm_file.relative_to(REPO)}")
    hr()
    asm_text = asm_file.read_text(encoding="utf-8", errors="replace")
    print(asm_text, end="")
    print()

    # 2. CURRENT C
    level = detect_level(src_file, fn)

    if level == "NAKED":
        # m2c で .inc から C コードを生成する
        m2c_cmd = find_m2c()
        if not m2c_cmd:
            print("(m2c が見つかりません)", file=sys.stderr)
            print("  uv tool install git+https://github.com/matt-kempster/m2c.git")
            sys.exit(1)

        tmp_content = (
            f".syntax unified\n.text\n\tthumb_func_start {fn}\n{fn}:\n" + asm_text
        )
        with tempfile.NamedTemporaryFile(suffix=".s", mode="w", delete=False) as tmp:
            tmp.write(tmp_content)
            tmp_path = tmp.name

        try:
            hr()
            print(f"CURRENT C (m2c): {src_file.relative_to(REPO)}")
            hr()
            result = subprocess.run(
                m2c_cmd + ["--target", "gba", "-f", fn, tmp_path],
                capture_output=True,
                text=True,
            )
            print(result.stdout, end="")
            if result.returncode != 0:
                print("(m2c 変換失敗)")
                if result.stderr:
                    print(result.stderr[:400])
        finally:
            os.unlink(tmp_path)

    elif level == "NON_MATCH":
        hr()
        print(f"CURRENT C: {src_file.relative_to(REPO)}")
        hr()
        print(extract_func_block(src_file, fn))

    else:
        print(f"(関数 {fn} が {sys.argv[2]} に見つかりませんでした)", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
