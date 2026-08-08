#!/bin/bash
# decomp-permuter を実行するラッパー
# Usage: tools/permuter.sh <PERM_DIR> [OPTIONS]
# 例: tools/permuter.sh /tmp/perm_FUN_08242b88 -j4
#
# `uv run python3` は経由しない: decomp-permuter は pyproject.toml に依存関係を
# 宣言していない素の pip 管理プロジェクトなので、uv の分離環境には toml 等が
# 入っていない。permuter.py 自身の shebang (#!/usr/bin/env python3) 経由で
# 直接実行し、toml がインストール済みの通常の python3 を使わせる。

: "${DECOMP_PERMUTER:?DECOMP_PERMUTER is not set}"

"$DECOMP_PERMUTER/permuter.py" "$@"
