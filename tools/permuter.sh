#!/bin/bash
# decomp-permuter を venv 経由で実行するラッパー
# Usage: tools/permuter.sh <PERM_DIR> [OPTIONS]
# 例: tools/permuter.sh /tmp/perm_FUN_08242b88 -j4

HERE="$(cd "$(dirname "$0")" && pwd)"
VENV="$HERE/decomp-permuter/.venv/bin/activate"

if [ ! -f "$VENV" ]; then
  echo "error: venv が見つかりません。セットアップ手順を確認してください。" >&2
  exit 1
fi

source "$VENV"
python3 "$HERE/decomp-permuter/permuter.py" "$@"
