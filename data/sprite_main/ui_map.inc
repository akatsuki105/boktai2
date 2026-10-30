File0312_Header:
  .2byte 711 @ palStart
  .2byte 24 @ metaspriteCount
  .2byte 5 @ animationCount
  .2byte 28 @ subspriteCount
  .2byte 12 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 512 @ offsetToAnims
  .4byte 552 @ offsetToSubsprites
  .4byte 776 @ offsetToCmds
  .4byte 824 @ offsetToTiles

File0312_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x9A20, File0312_Obj_0,     1,          -24,  -24,    8,    8
  pose 0x98A5, File0312_Obj_1,     1,          -24,  -24,    8,    8
  pose 0x1D79, File0312_Obj_2,     1,          -24,  -24,    8,    8
  pose 0x1950, File0312_Obj_3,     1,          -24,  -24,    8,    8
  pose 0x3AD7, File0312_Obj_4,     1,          -16,  -16,   16,   16
  pose 0x3AD8, File0312_Obj_5,     1,          -15,  -16,   17,   16
  pose 0x3AD9, File0312_Obj_6,     1,          -15,  -15,   17,   17
  pose 0x3ADA, File0312_Obj_7,     1,          -16,  -15,   16,   17
  pose 0x4948, File0312_Obj_8,     5,            0,    0,  176,   96
  pose 0x5940, File0312_Obj_13,    1,           -7,    0,    9,   80
  pose 0x5D40, File0312_Obj_14,    1,           -8,    0,    8,   80
  pose 0x5946, File0312_Obj_15,    1,            0,    0,  239,   80
  pose 0x5D46, File0312_Obj_16,    1,            0,    0,  240,   80
  pose 0x5949, File0312_Obj_17,    1,            0,   -7,  144,    9
  pose 0x5D49, File0312_Obj_18,    1,            0,   -8,  144,    8
  pose 0x5938, File0312_Obj_19,    1,            0,    0,  128,  140
  pose 0x5D38, File0312_Obj_20,    1,            0,    0,  128,  141
  pose 0x4817, File0312_Obj_21,    1,          -44,  -44,   20,   20
  pose 0x0589, File0312_Obj_22,    1,            0,    0,  266,  132
  pose 0x058A, File0312_Obj_23,    1,            0,    0,  348,  396
  pose 0x058B, File0312_Obj_24,    1,            0,    0,  416,  272
  pose 0x058C, File0312_Obj_25,    1,            0,    0,  146,  195
  pose 0x058D, File0312_Obj_26,    1,            0,    0,  422,  112
  pose 0x058E, File0312_Obj_27,    1,            0,    0,  406,  120

File0312_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x31D5, File0312_Cmd_0,     4
  animation 0xA893, File0312_Cmd_4,     2
  animation 0xA899, File0312_Cmd_6,     2
  animation 0xA89C, File0312_Cmd_8,     2
  animation 0xA88B, File0312_Cmd_10,    2

1:
File0312_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File0312_Obj_0:
    subsprite OAM_SIZE_16x16,   -8,   -8,   34,    0
  File0312_Obj_1:
    subsprite OAM_SIZE_16x16,   -8,   -8,   36,    1
  File0312_Obj_2:
    subsprite OAM_SIZE_16x16,   -8,   -8,   38,    2
  File0312_Obj_3:
    subsprite OAM_SIZE_16x16,   -8,   -8,   32,    0
  File0312_Obj_4:
    subsprite OAM_SIZE_16x16,    0,    0,    6,    1
  File0312_Obj_5:
    subsprite OAM_SIZE_16x16,    1,    0,    6,    1
  File0312_Obj_6:
    subsprite OAM_SIZE_16x16,    1,    1,    6,    1
  File0312_Obj_7:
    subsprite OAM_SIZE_16x16,    0,    1,    6,    1
  File0312_Obj_8:
    subsprite OAM_SIZE_16x16,   80,   64,    0,    0
    subsprite OAM_SIZE_16x16,   64,   64,    0,    0
    subsprite OAM_SIZE_16x16,  144,   64,    0,    0
    subsprite OAM_SIZE_16x16,  160,   64,    0,    0
    subsprite OAM_SIZE_32x16,  104,   64,    2,    0
  File0312_Obj_13:
    subsprite OAM_SIZE_8x8,      1,   72,   70,    0, xflip=1
  File0312_Obj_14:
    subsprite OAM_SIZE_8x8,      0,   72,   70,    0, xflip=1
  File0312_Obj_15:
    subsprite OAM_SIZE_8x8,    231,   72,   70,    0
  File0312_Obj_16:
    subsprite OAM_SIZE_8x8,    232,   72,   70,    0
  File0312_Obj_17:
    subsprite OAM_SIZE_8x8,    136,    1,   71,    0
  File0312_Obj_18:
    subsprite OAM_SIZE_8x8,    136,    0,   71,    0
  File0312_Obj_19:
    subsprite OAM_SIZE_8x8,    120,  132,   71,    0, yflip=1
  File0312_Obj_20:
    subsprite OAM_SIZE_8x8,    120,  133,   71,    0, yflip=1
  File0312_Obj_21:
    subsprite OAM_SIZE_32x32,  -12,  -12,   64,    2
  File0312_Obj_22:
    subsprite OAM_SIZE_32x32,  234,  100,    8,    3
  File0312_Obj_23:
    subsprite OAM_SIZE_32x32,  316,  364,   72,    4
  File0312_Obj_24:
    subsprite OAM_SIZE_32x32,  384,  240,  136,    5
  File0312_Obj_25:
    subsprite OAM_SIZE_32x32,  114,  163,   12,    6
  File0312_Obj_26:
    subsprite OAM_SIZE_32x32,  390,   80,   76,    7
  File0312_Obj_27:
    subsprite OAM_SIZE_16x32,  390,  104,  140,    7

2:
File0312_Cmds:
  File0312_Cmd_0:
    animcmd   4,  11
    animcmd   5,  11
    animcmd   6,  11
    animcmd   7,  11
  File0312_Cmd_4:
    animcmd   9,  19
    animcmd  10,  19
  File0312_Cmd_6:
    animcmd  11,  19
    animcmd  12,  19
  File0312_Cmd_8:
    animcmd  13,  19
    animcmd  14,  19
  File0312_Cmd_10:
    animcmd  15,  19
    animcmd  16,  19

File0312_Tiles:
  .incbin "data/sprite_main/ui_map.4bpp"
