.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.macro pose unk_0:req, obj:req, objcount:req, boxright:req, boxbottom:req, boxleft:req, boxtop:req
  .2byte (\unk_0) @ unk_0
  .2byte (\objcount) @ subsprite count
  .2byte 0, 0 @ x, y (always 0 in ROM)
  .2byte (\boxright), (\boxbottom), (\boxleft), (\boxtop) @ box right, box bottom, box left, box top
  .4byte (\obj) - 1f @ subsprite offset
.endm

.macro animation unk_0:req, cmd:req, cmdCount:req
  .2byte (\unk_0) @ unk_0
  .2byte (\cmdCount) @ cmd count
  .4byte (\cmd) - 2f @ cmd offset
.endm

.macro subsprite size:req, x:req, y:req, tileIdx:req, palID:req, xflip=0, yflip=0
  .byte ((\yflip << 3) | (\xflip << 2)), (\size) @ attr, shape
  .2byte (\x), (\y) @ x, y
  .2byte (\tileIdx | (\palID << 12)) @ tileIdx | (palID << 12)
.endm

.macro animcmd pose:req, duration:req
  .2byte (\pose) @ pose idx
  .2byte (\duration) @ frame duration
.endm

.global gMainSpritesDirectory
gMainSpritesDirectory: @ 0x08B79944
  .4byte 40
  .4byte MainSpritesDirectory_FileIDs - gMainSpritesDirectory
  .4byte MainSpritesDirectory_FileOffsets - gMainSpritesDirectory
  .4byte MainSpriteFiles - gMainSpritesDirectory
  MainSpritesDirectory_FileIDs: @ 0x08B79954, see "include/constants/sprite.h"
    .2byte 0x0312, 0x0C23, 0x1774, 0x1BC7, 0x414C, 0x42E2, 0x5D04, 0x5D36, 0x5EBF, 0x6893, 0x82F1, 0x92F0, 0x9524, 0xAE52, 0xAF82, 0xB343
    .2byte 0xB991, 0xD27A, 0xD353, 0xD3CA, 0xD3DA, 0xD3EA, 0xD3FA, 0xD40A, 0xDCC1, 0xDE23, 0xDF11, 0xDFCE, 0xDFDE, 0xDFEE, 0xDFFE, 0xE00E
    .2byte 0xE01E, 0xE02E, 0xE03E, 0xE04E, 0xE2DE, 0xE349, 0xE89F, 0xF099
  MainSpritesDirectory_FileOffsets: @ 0x08b799A4
    .4byte 0x100, 0x2438, 0x44AC, 0x8580, 0xD170, 0xF880, 0x14924, 0x1E11C, 0x2DE94, 0x30704, 0x33CA4, 0x38184, 0x3A878, 0x526B0, 0x74630, 0x76690
    .4byte 0x7E7F8, 0x828E8, 0x86C60, 0x8905C, 0x94358, 0xB19BC, 0xC4440, 0xCFA00, 0xDA050, 0xE0EC8, 0x10FC34, 0x1143B8, 0x119A40, 0x11C5B4, 0x1210C8, 0x123734
    .4byte 0x128534, 0x12AD44, 0x12D43C, 0x131DFC, 0x136B6C, 0x138C24, 0x13AD60, 0x13D50C
  MainSpriteFiles: @ 0x08B79A44
    .include "data/sprite_main/ui_map.inc"                      @ 0x0312
    .include "data/sprite_main/event_sun_ray.inc"               @ 0x0C23
    .include "data/sprite_main/django_large.inc"                @ 0x1774
    .include "data/sprite_main/flamethrower.inc"                @ 0x1BC7
    .include "data/sprite_main/ui_misc.inc"                     @ 0x414C
    .include "data/sprite_main/42E2.inc"                        @ 0x42E2
    .include "data/sprite_main/inventory_icons.inc"             @ 0x5D04
    .include "data/sprite_main/shademan.inc"                    @ 0x5D36
    .include "data/sprite_main/ui_gallery.inc"                  @ 0x5EBF
    .include "data/sprite_main/6893.inc"                        @ 0x6893
    .include "data/sprite_main/markers.inc"                     @ 0x82F1
    .include "data/sprite_main/92F0.inc"                        @ 0x92F0
    .include "data/sprite_main/jormungandr.inc"                 @ 0x9524
    .include "data/sprite_main/skeletons.inc"                   @ 0xAE52
    .include "data/sprite_main/megaman.inc"                     @ 0xAF82
    .include "data/sprite_main/ui_start_menu.inc"               @ 0xB343
    .include "data/sprite_main/candle_box.inc"                  @ 0xB991
    .include "data/sprite_main/portraits.inc"                   @ 0xD27A
    .include "data/sprite_main/D353.inc"                        @ 0xD353
    .include "data/sprite_main/duneyrr.inc"                     @ 0xD3CA
    .include "data/sprite_main/ringo.inc"                       @ 0xD3DA
    .include "data/sprite_main/shaian.inc"                      @ 0xD3EA
    .include "data/sprite_main/durathror.inc"                   @ 0xD3FA
    .include "data/sprite_main/dvalinn.inc"                     @ 0xD40A
    .include "data/sprite_main/ui_link.inc"                     @ 0xDCC1
    .include "data/sprite_main/django_sabata.inc"               @ 0xDE23
    .include "data/sprite_main/ui_solar_sensor_help.inc"        @ 0xDF11
    .include "data/sprite_main/smith_marcello.inc"              @ 0xDFCE
    .include "data/sprite_main/rita.inc"                        @ 0xDFDE
    .include "data/sprite_main/zaji.inc"                        @ 0xDFEE
    .include "data/sprite_main/sumire.inc"                      @ 0xDFFE
    .include "data/sprite_main/kuro.inc"                        @ 0xE00E
    .include "data/sprite_main/kid.inc"                         @ 0xE01E
    .include "data/sprite_main/lady.inc"                        @ 0xE02E
    .include "data/sprite_main/coffinseller_snake.inc"          @ 0xE03E
    .include "data/sprite_main/ennio_luis.inc"                  @ 0xE04E
    .include "data/sprite_main/carmilla.inc"                    @ 0xE2DE
    .include "data/sprite_main/dainn.inc"                       @ 0xE349
    .include "data/sprite_main/E89F.inc"                        @ 0xE89F
    .include "data/sprite_main/chandelier.inc"                  @ 0xF099
