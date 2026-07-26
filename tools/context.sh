#!/bin/bash
# Claude へのデコンパイルコンテキストを生成する
# Usage: tools/context.sh <FUNCTION_NAME> [SRC_FILE]
# 例: tools/context.sh FUN_08242b88
#     tools/context.sh FUN_08242b88 src/weapon.c

FN="${1?Usage: $0 <FUNCTION_NAME> [SRC_FILE]}"
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
AS="${DEVKITARM}/bin/arm-none-eabi-as"

hr() { printf '=%.0s' $(seq 1 60); echo; }

# ──────────────────────────────────────────────────────────
# 1. ターゲットアセンブリ (.inc) を探す
# ──────────────────────────────────────────────────────────
INC=$(find "$REPO/asm" -name "${FN}.inc" 2>/dev/null | head -1)
if [ -z "$INC" ]; then
  INC=$(find "$REPO/asm" -iname "*${FN}*.inc" 2>/dev/null | head -1)
fi

if [ -n "$INC" ]; then
  hr
  echo "TARGET ASSEMBLY: ${INC#$REPO/}"
  hr
  cat "$INC"
  echo ""

  # m2c で機械的に C へ変換
  # m2c コマンドを解決（pipx 版 or tools/m2c clone 版の両方に対応）
  if command -v m2c >/dev/null 2>&1; then
    M2C_CMD="m2c"
  elif [ -f "$REPO/tools/m2c/m2c.py" ]; then
    M2C_CMD="python3 $REPO/tools/m2c/m2c.py"
  else
    M2C_CMD=""
  fi

  if [ -n "$M2C_CMD" ]; then
    tmp_s=$(mktemp /tmp/ctx_XXXX.s)
    tmp_o=$(mktemp /tmp/ctx_XXXX.o)
    trap "rm -f $tmp_s $tmp_o" EXIT

    {
      echo ".syntax unified"
      echo ".thumb"
      echo ".text"
      printf '.include "%s"\n' "$INC"
    } > "$tmp_s"

    hr
    echo "m2c TRANSLATION"
    hr
    if "$AS" -mcpu=arm7tdmi -march=armv4t -mthumb -mthumb-interwork -g "$tmp_s" -o "$tmp_o" 2>/dev/null; then
      $M2C_CMD --arch arm32 --stop-on-error "$tmp_o" 2>/dev/null \
        || echo "(m2c 変換失敗)"
    else
      echo "(アセンブル失敗)"
    fi
    echo ""
  else
    echo "(m2c が見つかりません)"
    echo "  pipx install git+https://github.com/matt-kempster/m2c.git"
    echo "  または: git clone https://github.com/matt-kempster/m2c.git tools/m2c"
    echo ""
  fi
else
  echo "(注意: .inc ファイルが見つかりませんでした: $FN)"
  echo ""
fi

# ──────────────────────────────────────────────────────────
# 2. 現在のCコード実装を探す
# ──────────────────────────────────────────────────────────
SRC_FILE="${2:-$(grep -rl "$FN" "$REPO/src" 2>/dev/null | head -1)}"
if [ -n "$SRC_FILE" ]; then
  # src/ 相対パスに正規化
  [ "${SRC_FILE#/}" = "$SRC_FILE" ] && SRC_FILE="$REPO/$SRC_FILE"
  hr
  echo "CURRENT C: ${SRC_FILE#$REPO/}"
  hr
  # 関数定義から最大50行を表示
  grep -n "$FN" "$SRC_FILE" -A 50 | head -60
  echo ""
fi

# ──────────────────────────────────────────────────────────
# 3. 現在の差分
# ──────────────────────────────────────────────────────────
if [ -n "$SRC_FILE" ]; then
  REL_SRC="${SRC_FILE#$REPO/}"
  hr
  echo "CURRENT DIFF: $REL_SRC / $FN"
  hr
  "$HERE/diff.sh" "$REL_SRC" "$FN" 2>&1 \
    || echo "(diff 不可: ./tools/refresh-expected.sh を先に実行してください)"
fi
