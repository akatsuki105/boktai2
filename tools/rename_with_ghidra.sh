#!/bin/sh
# 関数をリポジトリと Ghidra の両方でリネームする。GUI の Ghidra が起動している必要がある。
#
# e.g. tools/rename_with_ghidra.sh FUN_082412f8 Save_ReadCurrentSlot
#
# Ghidra 側は boktai2.sym から旧名のアドレスを引くので、リポジトリより先にリネームする。
# (リポジトリを先にリネームしても boktai2.sym は再ビルドするまで旧名のままだが、失敗時にリポジトリだけ変わった状態を避けるため)
set -eu

if [ $# -ne 2 ]; then
  echo "usage: $0 <old_name> <new_name>" >&2
  exit 1
fi
old=$1
new=$2

cd "$(git rev-parse --show-toplevel)"

tools/ghidra/rename_function.ts "$old" "$new"
deno run -A tools/rename.ts "$old" "$new"

echo "完了: $old -> $new (make で undefined reference が出たら make clean-code してください)"
