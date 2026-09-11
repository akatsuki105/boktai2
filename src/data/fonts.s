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
  .2byte 128                         @ narrowCharCount (8x16px)
  .2byte 1537                        @ wideCharCount (16x16px)
  .4byte gHankakuFonts - gFontFile0  @ offsetToNarrowChars
  .4byte gZenkakuFonts - gFontFile0  @ offsetToWideChars

gHankakuFonts: @ 0x089EE09C
  .incbin "data/font_narrow.4bpp"

gZenkakuFonts: @ 0x089F009C
  .incbin "data/font_wide.4bpp"
