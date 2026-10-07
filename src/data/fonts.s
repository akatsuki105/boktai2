.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.global gFontDirectory
gFontDirectory: @ 0x089ee074
  .4byte 1, 0x10, 0x14, 0x1C
  .2byte 0x3F51, 0
  .4byte 0x1C, 0

.global gFontFile0
gFontFile0: @ 0x089ee090
  .2byte 128
  .2byte 1537
  .4byte gHankakuFonts - gFontFile0
  .4byte gZenkakuFonts - gFontFile0

gHankakuFonts: @ 0x089EE09C
  .incbin "data/hankaku.4bpp"

gZenkakuFonts: @ 0x089F009C
  .incbin "data/zenkaku.4bpp"
