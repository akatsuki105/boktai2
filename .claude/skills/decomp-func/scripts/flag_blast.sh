#!/bin/bash
# コンパイラフラグの影響範囲 (blast radius) を測る。
# フラグを立ててフルビルドし、expected/ のオブジェクトと1つずつ突き合わせて
# 「そのフラグが何個のオブジェクトを変えるか」を数える。
#
# Usage:
#   .claude/skills/decomp-func/scripts/flag_blast.sh -fno-gcse
#   .claude/skills/decomp-func/scripts/flag_blast.sh -fsigned-narrow-modes -ffix-shift-compare   # 組み合わせ
#   .claude/skills/decomp-func/scripts/flag_blast.sh --baseline            # フラグなし、0 になるかの健全性確認
#   .claude/skills/decomp-func/scripts/flag_blast.sh --with-lib -fno-gcse  # src/lib も数に入れる
#
# 既定では src/lib/ を除外する。あそこはゲーム本体のコードではなくライブラリで、
# 元の開発元も別のビルド条件で作っている可能性が高く、判断材料にならない。
#
# 出す数字は「候補の絞り込み」であって「判定」ではない。src/*.c は今の CFLAGS で
# 一致するように書かれているので、原典がそのフラグを使っていた場合でも差は出る。
# 0 は「フラグが無効」と「原典も同じ」を区別できない。詳細は
# docs/for-ai-agent/agbcc-levers.md の Tier D を読むこと。

set -eu

cd "$(git rev-parse --show-toplevel)"

with_lib=0
baseline=0
flags=()

for a in "$@"; do
  case "$a" in
    --with-lib) with_lib=1 ;;
    --baseline) baseline=1 ;;
    -h | --help)
      awk 'NR > 1 { if ($0 !~ /^#/) exit; sub(/^# ?/, ""); print }' "$0"
      exit 0
      ;;
    *) flags+=("$a") ;;
  esac
done

if [ "$baseline" -eq 0 ] && [ "${#flags[@]}" -eq 0 ]; then
  echo "フラグが指定されていません (--baseline なら意図的に空)" >&2
  exit 1
fi

if [ ! -d expected/build/boktai2 ]; then
  echo "expected/build/boktai2 がありません。tools/refresh-expected.sh を先に走らせてください" >&2
  exit 1
fi

jobs=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
extra="${flags[*]-}"

# 通常ビルドとは別の置き場所を使う。EXTRA_CFLAGS は make の依存関係に入らないので、
# build/boktai2 に吐くと通常ビルドのオブジェクトと混ざって次の make compare が嘘をつく。
# 実行のたびにフラグが変わるので、この専用ディレクトリは毎回頭で消す。
BDIR=build/flagblast
rm -rf "$BDIR"

echo "--- EXTRA_CFLAGS=\"$extra\""
# objs はリンクまで行かないので、ROM が一致しないことも compare も気にしなくていい
make -j"$jobs" objs BUILD_DIR="$BDIR" EXTRA_CFLAGS="$extra" >/dev/null 2>&1 || true

total=0
diff=0
nobase=0
changed=()
while IFS= read -r o; do
  [ "$with_lib" -eq 1 ] || case "$o" in "$BDIR"/src/lib/*) continue ;; esac
  e="expected/build/boktai2/${o#"$BDIR"/}"
  if [ ! -f "$e" ]; then
    nobase=$((nobase + 1))
    continue
  fi
  total=$((total + 1))
  cmp -s "$o" "$e" || {
    diff=$((diff + 1))
    changed+=("$o")
  }
done < <(find "$BDIR" -name '*.o' | sort)

if [ "$total" -eq 0 ]; then
  echo "オブジェクトが1つも作られていません。ビルドが落ちています:" >&2
  make objs BUILD_DIR="$BDIR" EXTRA_CFLAGS="$extra" 2>&1 | tail -20 >&2
  exit 1
fi

echo
echo "影響範囲: $diff / $total"
for c in "${changed[@]-}"; do [ -n "$c" ] && echo "  $c"; done
if [ "$nobase" -gt 0 ]; then
  echo
  echo "注意: expected/ に対応がないオブジェクトが $nobase 個あり、数に入れていません。"
  echo "      tools/refresh-expected.sh を走らせると母数が揃います。"
fi

echo
echo "(オブジェクトは $BDIR/ に残してあります。通常ビルドの build/boktai2 には触っていません)"
