.include "asm/macros.inc"
.include "asm/commands.inc"

.balign 4, 0
.section .rodata

@ ScriptDirectory in include/vm.h
.global gScriptDirectory
gScriptDirectory: @ 0x08CBF248
  .4byte 0x40A8186C @ build_date

ScriptEntries: @ 0x08CBF24C
  @ スクリプトNのアドレスは Bytecode_start + ScriptEntries[N] で求められる
  .incbin "data/script_entries.bin" @ ./tmp/bin.sh ./baserom.gba 0x08CBF24C 0x08CCA69C ./data/script_entries.bin

sOffsets: @ 0x08CCA69C
  .4byte Bytecode - sOffsets
  .4byte StringIndex - sOffsets
  .4byte StringData - sOffsets
  .4byte Unknown - sOffsets

StringIndex: @ 0x08CCA6AC
  .incbin "data/string_index.bin" @ ./tmp/bin.sh ./baserom.gba 0x08CCA6AC 0x08CD1640 ./data/string_index.bin

StringData: @ 0x08CD1640
  .include "data/text/strings.inc"
  .include "data/text/chat_unknown.inc" @ ID: 4941..
  .include "data/text/chat_zaji.inc" @ ID: 5092..
  .include "data/text/staff_roll.inc" @ ID: 5310..
  .balign 4, 0
  .include "data/text/text_5368.inc"
  .include "data/text/start_menu.inc" @ ID: 5640..
  .balign 4, 0
  .include "data/text/text_6297.inc" @ ID: 6297..
  .balign 4, 0 @ ここで4バイトアラインメントされてるし、内容も通信対戦のテキストになるのでここでファイルが分かれている気がする
  .include "data/text/link_battle.inc" @ ID: 6996..

Unknown: @ 0x08D13420
  .byte 0xD8, 0x0E, 0x0A, 0x61 @ unknown

Bytecode: @ 0x08d13424
  .4byte Bytecode_end - Bytecode_start @ bytecode.bin bytesize
Bytecode_start:
  .include "data/scripts/script_08d13428.inc"
  .include "data/scripts/script_08d1ca88.inc"
  .include "data/scripts/script_08d23b5b.inc"
  .include "data/scripts/script_08d2c5f2.inc"
  .include "data/scripts/script_08d36092.inc"
  .include "data/scripts/script_08d3e449.inc"
  .include "data/scripts/script_08d46d1e.inc"
  .include "data/scripts/script_08d4e9c3.inc"
  .include "data/scripts/script_08d55b67.inc"
  .include "data/scripts/script_08d5dc5c.inc"
  .include "data/scripts/script_08d64455.inc"
  .include "data/scripts/script_08d6cb82.inc"
  .include "data/scripts/script_08d75915.inc"
  .include "data/scripts/script_08d7e702.inc"
  .include "data/scripts/script_08d89836.inc"
  .include "data/scripts/script_08d9013a.inc"
  .include "data/scripts/script_08d97e2a.inc"
  .include "data/scripts/script_08da7c93.inc"
Bytecode_end:

SpecialScript: @ 0x08da9e5c
  .4byte SpecialScript_end - (. + 4) @ special.bin bytesize
  .include "data/scripts/special.inc"
SpecialScript_end:

.balign 4, 0
