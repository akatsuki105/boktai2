#!/usr/bin/env -S uv run python3
"""巨大な .s/.inc ファイルの中から1関数分のアセンブリを asm/func/FUNCNAME.inc
として切り出し、元の場所を `.include "asm/func/FUNCNAME.inc"` に置き換える。

Usage: tools/extract-func-asm.py <FUNCTION_NAME> [ASM_FILE]

ASM_FILE を省略すると、src/*.s と asm/*.inc（トップレベルのみ、
asm/func/ や asm/macros/ は対象外）から `thumb_func_start FUNCTION_NAME`
を含むファイルを自動検出する。

e.g. tools/extract-func-asm.py FUN_0824c0c4 asm/code_0824beb8.inc
e.g. tools/extract-func-asm.py FUN_0824c0c4

変換前 (ASM_FILE 内):
	thumb_func_start FUN_0824c0c4
FUN_0824c0c4: @ 0x0824C0C4
	push {r4, r5, r6, lr}
	...
	bx r1
	.align 2, 0

変換後 (ASM_FILE 内):
	thumb_func_start FUN_0824c0c4
FUN_0824c0c4: @ 0x0824C0C4
  .include "asm/func/FUN_0824c0c4.inc"

asm/func/FUN_0824c0c4.inc (新規作成):
	push {r4, r5, r6, lr}
	...
	bx r1
	.align 2, 0
"""

import re
import subprocess
import sys
from pathlib import Path

REPO = Path(
    subprocess.run(
        ["git", "rev-parse", "--show-toplevel"], capture_output=True, text=True
    ).stdout.strip()
)


def find_asm_file(fn: str) -> Path:
    """src/*.s と asm/*.inc（トップレベルのみ）から thumb_func_start FN を
    含むファイルを探す。"""
    pattern = re.compile(rf"\s*thumb_func_start\s+{re.escape(fn)}\b")
    candidates = sorted((REPO / "src").glob("*.s")) + sorted(
        (REPO / "asm").glob("*.inc")
    )
    hits = []
    for path in candidates:
        text = path.read_text(encoding="utf-8", errors="replace")
        if any(pattern.match(ln) for ln in text.split("\n")):
            hits.append(path)

    if not hits:
        sys.exit(
            f"エラー: thumb_func_start {fn} を src/*.s / asm/*.inc から見つけられませんでした"
        )
    if len(hits) > 1:
        listing = "\n".join(f"  - {p.relative_to(REPO)}" for p in hits)
        sys.exit(
            f"エラー: {fn} が複数のファイルで見つかりました。ASM_FILE を明示してください:\n{listing}"
        )
    return hits[0]


def main() -> None:
    if len(sys.argv) not in (2, 3):
        sys.exit(f"usage: {sys.argv[0]} <FUNCTION_NAME> [ASM_FILE]")

    fn = sys.argv[1]
    if len(sys.argv) == 3:
        asm_path = REPO / sys.argv[2]
        if not asm_path.is_file():
            sys.exit(f"エラー: {asm_path} が見つかりません")
    else:
        asm_path = find_asm_file(fn)
        print(f"(自動検出: {asm_path.relative_to(REPO)})")

    out_path = REPO / "asm" / "func" / f"{fn}.inc"

    text = asm_path.read_text(encoding="utf-8")
    lines = text.split("\n")

    start = None
    for i, ln in enumerate(lines):
        if re.match(rf"\s*thumb_func_start\s+{re.escape(fn)}\b", ln):
            start = i
            break
    if start is None:
        sys.exit(f"エラー: thumb_func_start {fn} が {asm_path} に見つかりません")

    label_idx = start + 1
    if label_idx >= len(lines) or not re.match(
        rf"^{re.escape(fn)}\s*:", lines[label_idx]
    ):
        sys.exit(f"エラー: {fn}: ラベル行が thumb_func_start の直後にありません")

    body_start = label_idx + 1
    if body_start < len(lines) and lines[body_start].strip().startswith(".include"):
        sys.exit(f"エラー: {fn} は既に切り出し済みのようです（.include 行を検出）")

    body_end = len(lines)
    is_last_func = True
    for j in range(body_start, len(lines)):
        if re.match(r"\s*thumb_func_start\s+\w", lines[j]):
            body_end = j
            is_last_func = False
            break

    body = lines[body_start:body_end]
    while body and body[-1].strip() == "":
        body.pop()

    if not body:
        sys.exit(f"エラー: {fn} の本体が空です")

    if out_path.exists():
        sys.exit(f"エラー: {out_path} は既に存在します（上書きを避けるため中断）")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text("\n".join(body) + "\n", encoding="utf-8")

    include_line = f'  .include "{out_path.relative_to(REPO)}"'
    # ファイル末尾の関数の場合、joinで実際の空行を作るには空文字列が2つ要る
    # （1つだけだと単なる末尾改行になり、目に見える空行にならない）。
    replacement = [include_line, "", ""] if is_last_func else [include_line, ""]
    new_lines = lines[: label_idx + 1] + replacement + lines[body_end:]
    asm_path.write_text("\n".join(new_lines), encoding="utf-8")

    print(f"{out_path.relative_to(REPO)} を作成しました（{len(body)} 行）")
    print(f"{asm_path.relative_to(REPO)} を書き換えました")


if __name__ == "__main__":
    main()
