#!/bin/bash

# scripts.bokc の再生成スクリプト
# strings.h や script.h の内容を変更した場合に実行する

set -eu

DUMPER="./tools/dumper/bokcc.ts"
TARGET="./data/scripts/scripts.bokc"

"$DUMPER" baserom.gba --strings constants/strings.h --scripts constants/script.h > "$TARGET"
