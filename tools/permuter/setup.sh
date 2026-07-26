#!/bin/bash
# 関数1つ分の decomp-permuter 用ディレクトリをセットアップする
#
# Usage: tools/permuter/setup.sh <FUNCTION_NAME> [SRC_FILE] [OUTPUT_DIR]
# 例:
#   tools/permuter/setup.sh FUN_08242b88 src/weapon.c
#   tools/permuter/setup.sh FUN_08242b88 src/weapon.c /tmp/perm_FUN_08242b88
#
# 出力ディレクトリに以下を生成:
#   target.o     ... .inc から作った一致目標オブジェクト
#   base.c       ... permuter が変種を試す C ソース
#   compile.sh   ... agbcc コンパイルスクリプト
#   settings.toml

set -e

FN="${1?Usage: $0 <FUNCTION_NAME> [SRC_FILE] [OUTPUT_DIR]}"
SRC="${2:-}"
OUT="${3:-/tmp/perm_$FN}"

REPO="$(cd "$(dirname "$0")/../.." && pwd)"
PERMUTER="$REPO/tools/decomp-permuter"
AS="${DEVKITARM}/bin/arm-none-eabi-as"
ASFLAGS="-mcpu=arm7tdmi -march=armv4t -mthumb -mthumb-interwork -g"

# m2c コマンドを解決
if command -v m2c >/dev/null 2>&1; then
  M2C="m2c"
elif [ -f "$REPO/tools/m2c/m2c.py" ]; then
  M2C="python3 $REPO/tools/m2c/m2c.py"
else
  M2C=""
fi

mkdir -p "$OUT"

# ─────────────────────────────────────────────────────────
# 1. target.o を .inc ファイルから作成
# ─────────────────────────────────────────────────────────
INC=$(find "$REPO/asm" -name "${FN}.inc" 2>/dev/null | head -1)
if [ -z "$INC" ]; then
  echo "error: ${FN}.inc が見つかりません" >&2
  exit 1
fi

tmp_s=$(mktemp /tmp/perm_target_XXXX.s)
trap "rm -f $tmp_s" EXIT

cat > "$tmp_s" <<EOF
.syntax unified
.thumb
.text
.global $FN
.type $FN, %function
$FN:
.include "$INC"
.size $FN, . - $FN
EOF

$AS $ASFLAGS "$tmp_s" -o "$OUT/target.o"
echo "✓ target.o を作成しました"

# ─────────────────────────────────────────────────────────
# 2. base.c を生成
#   優先順位:
#     A. SRC_FILE が指定されていて MODERN=1 でプリプロセス可能
#     B. m2c による自動変換（フォールバック）
# ─────────────────────────────────────────────────────────
BASE_C_OK=0

if [ -n "$SRC" ] && [ -f "$REPO/$SRC" ]; then
  # __attribute__ と __asm__ を除去して pycparser が読めるようにする
  cc -E -P \
    -D'__attribute__(x)=' \
    -D'__asm__(x)=' \
    -I "$REPO/tools/agbcc" \
    -I "$REPO/tools/agbcc/include" \
    -iquote "$REPO/include" \
    -nostdinc -undef -DMODERN=1 \
    "$REPO/$SRC" > "$OUT/base.c" 2>/dev/null \
  && python3 "$PERMUTER/strip_other_fns.py" "$OUT/base.c" "$FN" 2>/dev/null \
  && grep -q "$FN" "$OUT/base.c" \
  && BASE_C_OK=1 \
  || true
fi

if [ "$BASE_C_OK" -eq 0 ]; then
  if [ -n "$M2C" ]; then
    echo "(MODERN=1 プリプロセス不可。m2c でフォールバック)"
    # m2c 用オブジェクトを一時的に作成
    tmp_o=$(mktemp /tmp/perm_m2c_XXXX.o)
    $AS $ASFLAGS "$tmp_s" -o "$tmp_o"
    {
      echo '#include "global.h"'
      echo ""
      $M2C --arch arm32 --stop-on-error "$tmp_o" 2>/dev/null || true
    } > "$OUT/base.c"
    rm -f "$tmp_o"
    echo "✓ base.c を m2c で生成しました（要確認）"
  else
    echo "error: m2c も SRC_FILE もありません。base.c を手動で作成してください" >&2
    exit 1
  fi
else
  echo "✓ base.c を生成しました (MODERN=1 プリプロセス)"
fi

# ─────────────────────────────────────────────────────────
# 3. compile.sh を生成（REPO パスをハードコード）
# ─────────────────────────────────────────────────────────
sed "s|REPO=\"\$(cd.*)\"|REPO=\"$REPO\"|" "$REPO/tools/permuter/compile.sh" > "$OUT/compile.sh"
chmod +x "$OUT/compile.sh"

# assertion[] 行を除去（agbcc では static_assert が利用不可のため）
sed -i '' '/^extern char assertion\[/d' "$OUT/base.c"

# ─────────────────────────────────────────────────────────
# 4. settings.toml
# ─────────────────────────────────────────────────────────
cat > "$OUT/settings.toml" <<EOF
func_name = "$FN"
compiler_type = "gcc"
EOF

echo ""
echo "セットアップ完了: $OUT"
echo ""
echo "実行例:"
echo "  tools/permuter.sh $OUT        # 1スレッド"
echo "  tools/permuter.sh $OUT -j4    # 4スレッド（推奨）"
