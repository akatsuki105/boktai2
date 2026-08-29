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

.global gActorSpritesDirectory
gActorSpritesDirectory: @ 0x08A22900
  .4byte 1, 0x10, 0x14, 0x1C
  .2byte 0xFF54, 0
  .4byte 0x1C, 0
.global gActorSpritesFile0
gActorSpritesFile0: @ 0x08A2291C
  .include "data/actor_sprites.inc" @ 0xFF54

.global gSpriteSetsDirectory
gSpriteSetsDirectory: @ 0x08B79944
  .4byte 40
  .4byte SpriteSetsDirectory_FileIDs - gSpriteSetsDirectory
  .4byte SpriteSetsDirectory_FileOffsets - gSpriteSetsDirectory
  .4byte SpriteSetFile0 - gSpriteSetsDirectory
  SpriteSetsDirectory_FileIDs: @ 0x08B79954, see "include/constants/sprite.h"
    .2byte 0x0312, 0x0C23, 0x1774, 0x1BC7, 0x414C, 0x42E2, 0x5D04, 0x5D36, 0x5EBF, 0x6893, 0x82F1, 0x92F0, 0x9524, 0xAE52, 0xAF82, 0xB343
    .2byte 0xB991, 0xD27A, 0xD353, 0xD3CA, 0xD3DA, 0xD3EA, 0xD3FA, 0xD40A, 0xDCC1, 0xDE23, 0xDF11, 0xDFCE, 0xDFDE, 0xDFEE, 0xDFFE, 0xE00E
    .2byte 0xE01E, 0xE02E, 0xE03E, 0xE04E, 0xE2DE, 0xE349, 0xE89F, 0xF099
  SpriteSetsDirectory_FileOffsets: @ 0x08b799A4
    .4byte SpriteSetFile0 - gSpriteSetsDirectory
    .4byte SpriteSetFile1 - gSpriteSetsDirectory
    .4byte SpriteSetFile2 - gSpriteSetsDirectory
    .4byte 0x8580, 0xD170, 0xF880, 0x14924, 0x1E11C, 0x2DE94, 0x30704, 0x33CA4, 0x38184, 0x3A878, 0x526B0, 0x74630, 0x76690
    .4byte 0x7E7F8, 0x828E8, 0x86C60, 0x8905C, 0x94358, 0xB19BC, 0xC4440, 0xCFA00, 0xDA050, 0xE0EC8, 0x10FC34, 0x1143B8, 0x119A40, 0x11C5B4, 0x1210C8, 0x123734
    .4byte 0x128534, 0x12AD44, 0x12D43C, 0x131DFC, 0x136B6C, 0x138C24, 0x13AD60, 0x13D50C
  SpriteSetFiles: @ 0x08B79A44
    .include "data/spriteset/ui_map.inc"                      @ 0x0312
    .include "data/spriteset/event_sun_ray.inc"               @ 0x0C23
    .include "data/spriteset/django_large.inc"                @ 0x1774
    .include "data/spriteset/flamethrower.inc"                @ 0x1BC7
    .include "data/spriteset/ui_misc.inc"                     @ 0x414C
    .include "data/spriteset/42E2.inc"                        @ 0x42E2
    .include "data/spriteset/inventory_icons.inc"             @ 0x5D04
    .include "data/spriteset/shademan.inc"                    @ 0x5D36
    .include "data/spriteset/ui_gallery.inc"                  @ 0x5EBF
    .include "data/spriteset/6893.inc"                        @ 0x6893
    .include "data/spriteset/markers.inc"                     @ 0x82F1
    .include "data/spriteset/92F0.inc"                        @ 0x92F0
    .include "data/spriteset/jormungandr.inc"                 @ 0x9524
    .include "data/spriteset/skeletons.inc"                   @ 0xAE52
    .include "data/spriteset/megaman.inc"                     @ 0xAF82
    .include "data/spriteset/ui_start_menu.inc"               @ 0xB343
    .include "data/spriteset/candle_box.inc"                  @ 0xB991
    .include "data/spriteset/portraits.inc"                   @ 0xD27A
    .include "data/spriteset/D353.inc"                        @ 0xD353
    .include "data/spriteset/duneyrr.inc"                     @ 0xD3CA
    .include "data/spriteset/ringo.inc"                       @ 0xD3DA
    .include "data/spriteset/shaian.inc"                      @ 0xD3EA
    .include "data/spriteset/durathror.inc"                   @ 0xD3FA
    .include "data/spriteset/dvalinn.inc"                     @ 0xD40A
    .include "data/spriteset/ui_link.inc"                     @ 0xDCC1
    .include "data/spriteset/django_sabata.inc"               @ 0xDE23
    .include "data/spriteset/ui_solar_sensor_help.inc"        @ 0xDF11
    .include "data/spriteset/smith_marcello.inc"              @ 0xDFCE
    .include "data/spriteset/rita.inc"                        @ 0xDFDE
    .include "data/spriteset/zaji.inc"                        @ 0xDFEE
    .include "data/spriteset/sumire.inc"                      @ 0xDFFE
    .include "data/spriteset/kuro.inc"                        @ 0xE00E
    .include "data/spriteset/kid.inc"                         @ 0xE01E
    .include "data/spriteset/lady.inc"                        @ 0xE02E
    .include "data/spriteset/coffinseller_unknown.inc"        @ 0xE03E
    .include "data/spriteset/ennio_luis.inc"                  @ 0xE04E
    .include "data/spriteset/carmilla.inc"                    @ 0xE2DE
    .include "data/spriteset/dainn.inc"                       @ 0xE349
    .include "data/spriteset/E89F.inc"                        @ 0xE89F
    .include "data/spriteset/chandelier.inc"                  @ 0xF099

.global gSpriteSetPlttsDirectory
gSpriteSetPlttsDirectory: @ 0x08CB9228
  .4byte 1, 0x10, 0x14, gObjPlttFile0-gSpriteSetPlttsDirectory
  .2byte 0xC5E9, 0
  .4byte gObjPlttFile0-gSpriteSetPlttsDirectory, 0
gObjPlttFile0: @ 0x08CB9244
  .2byte 768  @ palette length (16色パレットが 768個ある)
  .2byte 171  @ unk
  @ ./tmp/bin.sh ./baserom.gba 0x08cb9248 0x08cbf248 ./data/gObjPlttFile0.bin
  .incbin "data/gObjPlttFile0.bin"

