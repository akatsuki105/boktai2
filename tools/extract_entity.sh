#!/bin/sh

# Entityの基本4メソッドに extract_func.ts を実行する
# e.g.
#  extract_entity.sh EntityB8B9
#    -> ./tools/extract_func.ts EntityB8B9_Create
#    -> ./tools/extract_func.ts EntityB8B9_Init
#    -> ./tools/extract_func.ts EntityB8B9_Destroy
#    -> ./tools/extract_func.ts EntityB8B9_Update

set -e

if [ -z "$1" ]; then
  echo "引数が空です。"
  exit 1
fi

#  e.g. EntityB8B9
PREFIX="$1"

methods="Update Destroy Init Create"

for method in $methods; do
  name="${PREFIX}_${method}"
  ./tools/extract_func.ts "$name"
done

for method in $methods; do
  name="${PREFIX}_${method}"
  if [ "$method" = "Create" ]; then
    echo "NAKED ${PREFIX}* ${name}(void) { INCFUNC(\"asm/func/${name}.inc\"); }"
  else
    echo "NAKED s32 ${name}(${PREFIX}* p) { INCFUNC(\"asm/func/${name}.inc\"); }"
  fi
done
