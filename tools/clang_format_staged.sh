#!/bin/sh
# ステージ済みの .c / .h に clang-format をかけて、ステージし直す。
# git commit の直前に .claude/settings.json の PreToolUse フックから呼ばれる。
#
# clang-format の実体は VSCode の C/C++ 拡張に同梱されているものを優先する。
# 保存時整形で使われているのと同じバイナリでないと整形結果が食い違い、
# 手作業とAIの作業で整形が行ったり来たりするため (Homebrew の llvm は別バージョン)。
#
# フックを止めたくないので、何が起きても終了コードは 0 にする。

cf=""
for d in $(ls -d "$HOME"/.vscode/extensions/ms-vscode.cpptools-*/LLVM/bin 2>/dev/null | sort -r); do
  if [ -x "$d/clang-format" ]; then
    cf="$d/clang-format"
    break
  fi
done
[ -z "$cf" ] && cf=$(command -v clang-format 2>/dev/null)

root=$(git rev-parse --show-toplevel 2>/dev/null) || exit 0
[ -z "$root" ] && exit 0
cd "$root" || exit 0

files=$(git diff --cached --name-only --diff-filter=ACM -- '*.c' '*.h' 2>/dev/null)
[ -z "$files" ] && exit 0

if [ -z "$cf" ]; then
  echo '{"systemMessage":"clang-format が見つからないので整形をスキップしました"}'
  exit 0
fi

echo "$files" | tr '\n' '\0' | xargs -0 "$cf" -i 2>/dev/null || {
  echo '{"systemMessage":"clang-format が失敗したので整形をスキップしました"}'
  exit 0
}
# 整形で変わったぶんを同じコミットに入れ直す
echo "$files" | tr '\n' '\0' | xargs -0 git add -- 2>/dev/null

echo "{\"systemMessage\":\"clang-format: $(echo "$files" | tr '\n' ' ')\"}"
exit 0
