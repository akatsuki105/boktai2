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
  .4byte String_0000 - sOffsets
  .4byte unk08D13420 - sOffsets

StringIndex: @ 0x08CCA6AC
  .incbin "data/string_index.bin" @ ./tmp/bin.sh ./baserom.gba 0x08CCA6AC 0x08CD1640 ./data/string_index.bin
