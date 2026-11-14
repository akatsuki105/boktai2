#!/bin/bash

# scripts.bokc の再生成スクリプト
# strings.h, script.h, stat.h, world.h, scratch.h の内容を変更した場合や, src/vm_commands.s の関数名を変えた場合に実行する

set -eu

DUMPER="./tools/dumper/bokcc.ts"
TARGET="./data/scripts/scripts.bokc"

# commands.h は src/vm_commands.s から作るので先に作り直す
./tools/dumper/commands.ts src/vm_commands.s > ./data/scripts/commands.h

"$DUMPER" baserom.gba --strings data/scripts/strings.h --scripts data/scripts/script.h --commands data/scripts/commands.h --stat data/scripts/stat.h --world data/scripts/world.h --scratch data/scripts/scratch.h > "$TARGET"
