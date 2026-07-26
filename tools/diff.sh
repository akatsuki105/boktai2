#!/bin/bash
# ビルド後に expected vs build の逆アセンブル差分を表示する
# Usage: tools/diff.sh <src.c|src.o> [FUNCTION_NAME]
# 例: tools/diff.sh src/weapon.c FUN_08242b88

set -e

ROMNAME="boktai2"
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
OBJDUMP="${DEVKITARM}/bin/arm-none-eabi-objdump"

arg="${1?Usage: $0 <src.c|src.o> [FUNCTION_NAME]}"
case "$arg" in
  *.c) rel="${arg%.c}.o" ;;
  *.o) rel="$arg" ;;
  *)   echo "error: .c か .o で終わる引数が必要です" >&2; exit 1 ;;
esac
rel="${rel#./}"

TARGET="$REPO/expected/build/$ROMNAME/$rel"
BASE="$REPO/build/$ROMNAME/$rel"
FN="${2:-}"

if [ ! -f "$TARGET" ]; then
  echo "error: $TARGET が見つかりません。" >&2
  echo "./tools/refresh-expected.sh を実行してください。" >&2
  exit 1
fi

# 対象オブジェクトだけリビルド
(cd "$REPO" && make "$BASE" 2>&1)

# objdump してブランチラベルを正規化（ラベル名の差異を無視）
disasm() {
  "$OBJDUMP" -d --no-show-raw-insn "$1" | python3 -c "
import sys, re
for line in sys.stdin:
    # <SYMBOL+0xOFFSET> → <+0xOFFSET>  (シンボル名を除去、オフセットを保持)
    line = re.sub(r'<[^>+<]+\+(0x[0-9a-f]+)>', r'<+\1>', line)
    # <_08XXXXXX> 形式のアドレスラベル → <ADDR>
    line = re.sub(r' <_[0-9a-fA-F]+>', ' <ADDR>', line)
    sys.stdout.write(line)
"
}

# 指定関数のみ抽出
extract_fn() {
  local file="$1" fn="$2"
  disasm "$file" | awk -v fn="$fn" '
    $0 ~ ("<" fn ">:") { found=1; next }
    found && /^[0-9a-f]+ </ { exit }
    found { print }
  '
}

tmp_t=$(mktemp)
tmp_b=$(mktemp)
trap "rm -f $tmp_t $tmp_b" EXIT

if [ -n "$FN" ]; then
  extract_fn "$TARGET" "$FN" > "$tmp_t"
  extract_fn "$BASE"   "$FN" > "$tmp_b"
  label="$FN"
  if [ ! -s "$tmp_t" ]; then
    echo "警告: '$FN' が $TARGET に見つかりません" >&2
  fi
else
  disasm "$TARGET" > "$tmp_t"
  disasm "$BASE"   > "$tmp_b"
  label="$rel"
fi

if cmp -s "$tmp_t" "$tmp_b"; then
  echo "OK: $label 一致"
else
  diff --color=always -u \
    --label "expected ($label)" \
    --label "build    ($label)" \
    "$tmp_t" "$tmp_b" || true
fi
