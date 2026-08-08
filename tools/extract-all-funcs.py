#!/usr/bin/env -S uv run python3
"""1つの .s/.inc ファイルに含まれるすべての関数に対して extract-func-asm.py
を順番に実行し、それぞれを asm/func/FUNCNAME.inc に切り出す。

Usage: tools/extract-all-funcs.py <ASM_FILE>

e.g. tools/extract-all-funcs.py src/code_08245c4c.s

各関数は extract-func-asm.py <FUNCTION_NAME> <ASM_FILE> をそのまま呼び出す
ので、切り出しルール（末尾判定・空行の付け方など）は extract-func-asm.py
側の実装に一本化されている。既に切り出し済みの関数はスキップする。
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

EXTRACT_ONE = Path(__file__).resolve().parent / "extract-func-asm.py"


def list_func_names(asm_path: Path) -> list[str]:
    """ファイル中の thumb_func_start 行から関数名を出現順に集める。"""
    names = []
    for ln in asm_path.read_text(encoding="utf-8", errors="replace").split("\n"):
        m = re.match(r"\s*thumb_func_start\s+(\w+)", ln)
        if m:
            names.append(m.group(1))
    return names


def main() -> None:
    if len(sys.argv) != 2:
        sys.exit(f"usage: {sys.argv[0]} <ASM_FILE>")

    asm_path = REPO / sys.argv[1]
    if not asm_path.is_file():
        sys.exit(f"エラー: {asm_path} が見つかりません")

    names = list_func_names(asm_path)
    if not names:
        sys.exit(f"エラー: {asm_path} に thumb_func_start が見つかりません")

    print(f"{asm_path.relative_to(REPO)}: {len(names)} 関数を処理します")

    done, skipped, failed = [], [], []
    for fn in names:
        result = subprocess.run(
            [sys.executable, str(EXTRACT_ONE), fn, str(asm_path)],
            capture_output=True,
            text=True,
        )
        if result.returncode == 0:
            done.append(fn)
            print(f"  OK   {fn}")
        elif "既に切り出し済み" in result.stdout + result.stderr:
            skipped.append(fn)
            print(f"  SKIP {fn}（切り出し済み）")
        else:
            failed.append(fn)
            print(f"  FAIL {fn}")
            msg = (result.stdout + result.stderr).strip()
            if msg:
                print(f"       {msg}")

    print(
        f"\n完了: {len(done)} 件成功 / {len(skipped)} 件スキップ / {len(failed)} 件失敗"
    )
    if failed:
        print("失敗した関数: " + ", ".join(failed))
        sys.exit(1)


if __name__ == "__main__":
    main()
