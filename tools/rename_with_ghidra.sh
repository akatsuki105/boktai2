#!/bin/sh
# 関数をリポジトリと Ghidra の両方でリネームする。GUI の Ghidra が起動している必要がある。
#
# e.g. tools/rename_with_ghidra.sh FUN_082412f8 Save_ReadCurrentSlot
# e.g. tools/rename_with_ghidra.sh --quiet FUN_082412f8 Save_ReadCurrentSlot  (最後の make clean-code の案内を出さない)
#
# Ghidra 側は boktai2.sym から旧名のアドレスを引くので、リポジトリより先にリネームする。
# (リポジトリを先にリネームしても boktai2.sym は再ビルドするまで旧名のままだが、失敗時にリポジトリだけ変わった状態を避けるため)
set -eu

quiet=0
if [ "${1:-}" = "--quiet" ]; then
  quiet=1
  shift
fi
if [ $# -ne 2 ]; then
  echo "usage: $0 [--quiet] <old_name> <new_name>" >&2
  exit 1
fi
old=$1
new=$2

cd "$(git rev-parse --show-toplevel)"

tools/ghidra/rename_function.ts "$old" "$new"
deno run -A tools/rename.ts "$old" "$new"

if [ "$quiet" -eq 0 ]; then
  echo "完了: $old -> $new (make で undefined reference が出たら make clean-code してください)"
fi
