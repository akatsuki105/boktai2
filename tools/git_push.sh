#!/bin/bash
# 作業ツリーをコミットして push する。ROM が一致しないときは何もせずに止まる。
#
# Usage:
#   tools/git_push.sh "Entity56DC のレイアウトを埋める"
#   tools/git_push.sh          # メッセージ省略時は差分が一番大きいファイル名
#
# 一致確認は変更内容によらず必ず行う。ビルドに影響しうるかを判断するコストのほうがビルドより高く、しかもその判断こそが外れるため (見ていないヘッダ、data/*.inc まで届いたリネーム、前から残っていた編集)。clean-code を挟むのは、古いオブジェクトがありもしない一致を報告するのを避けるため。

set -eu

cd "$(git rev-parse --show-toplevel)"

jobs=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

if [ -z "$(git status --porcelain)" ]; then
  echo "コミットするものがありません"
  exit 1
fi

git status --porcelain

# ROM 一致確認
echo "--- make clean-code && make compare -j$jobs"
make clean-code >/dev/null
if ! out=$(make compare -j"$jobs" 2>&1) || ! grep -qx 'boktai2\.gba: OK' <<<"$out"; then
  echo "$out" | tail -20
  echo "ROM が一致しないのでコミットしませんでした" >&2
  exit 1
fi
echo "boktai2.gba: OK"

# build/ tmp/ expected/ は .gitignore 済みなので -A で足りる
git add -A

if git diff --cached --quiet; then
  echo "ステージされた変更がありません" >&2
  exit 1
fi

# メッセージ省略時は追加+削除の行数が最大のファイル名
msg="${1:-}"
if [ -z "$msg" ]; then
  msg=$(git diff --cached --numstat |
    awk '{ a = ($1 == "-") ? 0 : $1; d = ($2 == "-") ? 0 : $2
           if (a + d >= max) { max = a + d; f = $NF } }
         END { print f }')
  msg=$(basename "$msg")
  echo "メッセージ未指定のため \"$msg\" を使います"
fi

# .claude/settings.json の PreToolUse フックはこのスクリプト経由だと発火しないので自分で呼ぶ
tools/clang_format_staged.sh >/dev/null 2>&1 || true

git commit -q -m "$msg"
git push
git log --oneline -1
