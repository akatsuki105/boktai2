.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.macro group id:req, size:req, base:req
  .2byte (\id)          @ ID
  .byte 0x00, (\size)   @ flags, size
  .2byte (\base), 0x00  @ tileID, plttID
.endm

.global gParticlesDirectory
gParticlesDirectory: @ 0x08A2011C
  .4byte 1, 0x10, 0x14, 0x1C
  .2byte 0x3002, 0
  .4byte 0x1C, 0
gParticleFile0: @ 0x08A20138
  .4byte 0x0   @ unk_00
  .2byte 317   @ tileCount
  .2byte 3     @ groupCount
  .4byte gPartileFile0_Tiles - gParticleFile0  @ offsetToTiles
  group 0x1C1A, OAM_SIZE_16x16,   0 @ 0x1C1A: HashName("eff_eff_00")
  group 0x1C1C, OAM_SIZE_8x8,   224 @ 0x1C1C: ??
  group 0x1C1E, OAM_SIZE_8x8,   298 @ 0x1C1E: ??
gPartileFile0_Tiles: @ 0x08A2015C
  .incbin "data/particle_group_0.4bpp" @ 0x08A2015c, Tile 0..223
  .incbin "data/particle_group_1.4bpp" @ 0x08A21D5C, Tile 224..297
  .incbin "data/particle_group_2.4bpp" @ 0x08A2269C, Tile 298..316
  .4byte 0
