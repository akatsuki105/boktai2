.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.global gSpritePlttsDirectory
gSpritePlttsDirectory: @ 0x08CB9228
  .4byte 1, 0x10, 0x14, gObjPlttFile0-gSpritePlttsDirectory
  .2byte 0xC5E9, 0
  .4byte gObjPlttFile0-gSpritePlttsDirectory, 0
gObjPlttFile0: @ 0x08CB9244
  .2byte 768  @ palette length (16色パレットが 768個ある)
  .2byte 171  @ unk
  @ サイズが大きすぎて gbagfx では一括で JASC-PAL/gbapal の変換ができない
  .incbin "data/gObjPlttFile0.bin" @ ./tools/bin.ts ./baserom.gba 0x08cb9248 0x08cbf248 ./data/gObjPlttFile0.bin

