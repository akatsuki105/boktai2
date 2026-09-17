.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.global gParticlesDirectory
gParticlesDirectory: @ 0x08A2011C
  .4byte 1, 0x10, 0x14, 0x1C
  .2byte 0x3002, 0
  .4byte 0x1C, 0
gParticleFile0: @ 0x08A20138
  .4byte 0x0   @ unk_00
  .2byte 317   @ tileCount
  .2byte 3     @ groupCount
  .4byte gPartileFile0_Tiles-gParticleFile0  @ offsetToTiles
  gPartileFile0_Group0: @ 0x08A20144
    .2byte 0x1C1A @ ID
    .byte 0x00
    .byte (1 << 2) | 0 @ shape, 16x16px
    .2byte 0, 0x00
  gPartileFile0_Group1: @ 0x08A2014C
    .2byte 0x1C1C @ ID
    .byte 0x00, 0x00
    .2byte 224, 0x00
  gPartileFile0_Group2: @ 0x08A20154
    .2byte 0x1C1E @ ID
    .byte 0x00, 0x00
    .2byte 298, 0x00
  gPartileFile0_Tiles: @ 0x08A2015C
  .incbin "data/particle_group_0.4bpp" @ 0x08A2015c, Tile 0..223
  .incbin "data/particle_group_1.4bpp" @ 0x08A21D5C, Tile 224..297
  .incbin "data/particle_group_2.4bpp" @ 0x08A2269C, Tile 298..316
  .4byte 0
