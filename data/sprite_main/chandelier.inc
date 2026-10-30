FileF099_Header:
  .2byte 64 @ palStart
  .2byte 25 @ metaspriteCount
  .2byte 7 @ animationCount
  .2byte 37 @ subspriteCount
  .2byte 25 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 532 @ offsetToAnims
  .4byte 588 @ offsetToSubsprites
  .4byte 884 @ offsetToCmds
  .4byte 984 @ offsetToTiles

FileF099_Poses:
@ pose unk_0,  obj,              objcount,   bb
  pose 0x2AD3, FileF099_Obj_0,   1,          -47,  -66,   17,    0
  pose 0x2AD4, FileF099_Obj_1,   4,          -47,  -66,   20,    0
  pose 0x2AD5, FileF099_Obj_5,   4,          -47,  -66,   20,    0
  pose 0x2AD6, FileF099_Obj_9,   4,          -47,  -66,   20,    0
  pose 0x2AD7, FileF099_Obj_13,  4,          -47,  -66,   20,    0
  pose 0xDA7C, FileF099_Obj_17,  1,          -13,  -61,   19,    0
  pose 0xDA7D, FileF099_Obj_18,  1,          -13,  -60,   19,    0
  pose 0xDA7E, FileF099_Obj_19,  1,          -13,  -60,   19,    0
  pose 0xDA7F, FileF099_Obj_20,  1,          -13,  -60,   19,    0
  pose 0x3E35, FileF099_Obj_21,  1,          -13,  -44,   19,    0
  pose 0x3E36, FileF099_Obj_22,  1,          -13,  -43,   19,    0
  pose 0x3E37, FileF099_Obj_23,  1,          -13,  -43,   19,    0
  pose 0x3E38, FileF099_Obj_24,  1,          -13,  -43,   19,    0
  pose 0x4375, FileF099_Obj_25,  1,          -35,  -61,    0,    0
  pose 0x4376, FileF099_Obj_26,  1,          -35,  -60,    0,    0
  pose 0x4377, FileF099_Obj_27,  1,          -35,  -60,    0,    0
  pose 0x4378, FileF099_Obj_28,  1,          -35,  -60,    0,    0
  pose 0xBF02, FileF099_Obj_29,  1,          -35,  -44,    0,    0
  pose 0xBF03, FileF099_Obj_30,  1,          -35,  -43,    0,    0
  pose 0xBF04, FileF099_Obj_31,  1,          -35,  -43,    0,    0
  pose 0xBF05, FileF099_Obj_32,  1,          -35,  -43,    0,    0
  pose 0x6E71, FileF099_Obj_33,  1,          -24,  -66,    8,    0
  pose 0x6E72, FileF099_Obj_34,  1,          -25,  -66,    7,    0
  pose 0x6E73, FileF099_Obj_35,  1,          -24,  -66,    8,    0
  pose 0x6E74, FileF099_Obj_36,  1,          -24,  -66,    8,    0

FileF099_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xEDE9, FileF099_Cmd_0,  1
  animation 0x3F6C, FileF099_Cmd_1,  4
  animation 0xB096, FileF099_Cmd_5,  4
  animation 0x7807, FileF099_Cmd_9,  4
  animation 0x8287, FileF099_Cmd_13, 4
  animation 0x79A2, FileF099_Cmd_17, 4
  animation 0xD87F, FileF099_Cmd_21, 4

1:
FileF099_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileF099_Obj_0:
    subsprite OAM_SIZE_32x64,  -15,  -34,    0,    0
  FileF099_Obj_1:
    subsprite OAM_SIZE_32x64,  -15,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -47,    4,    0
    subsprite OAM_SIZE_16x16,  -18,  -30,    4,    0
    subsprite OAM_SIZE_16x16,    4,  -29,   36,    0
  FileF099_Obj_5:
    subsprite OAM_SIZE_32x64,  -15,  -34,    0,    0
    subsprite OAM_SIZE_16x16,  -18,  -30,   36,    0
    subsprite OAM_SIZE_16x16,   -7,  -47,   36,    0
    subsprite OAM_SIZE_16x16,    4,  -29,   68,    0
  FileF099_Obj_9:
    subsprite OAM_SIZE_32x64,  -15,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -47,   68,    0
    subsprite OAM_SIZE_16x16,  -18,  -30,   68,    0
    subsprite OAM_SIZE_16x16,    4,  -29,  100,    0
  FileF099_Obj_13:
    subsprite OAM_SIZE_32x64,  -15,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -47,  100,    0
    subsprite OAM_SIZE_16x16,  -18,  -30,  100,    0
    subsprite OAM_SIZE_16x16,    4,  -29,    4,    0
  FileF099_Obj_17:
    subsprite OAM_SIZE_16x16,    3,  -45,    4,    0
  FileF099_Obj_18:
    subsprite OAM_SIZE_16x16,    3,  -44,   36,    0
  FileF099_Obj_19:
    subsprite OAM_SIZE_16x16,    3,  -44,   68,    0
  FileF099_Obj_20:
    subsprite OAM_SIZE_16x16,    3,  -44,  100,    0
  FileF099_Obj_21:
    subsprite OAM_SIZE_16x16,    3,  -28,    4,    0
  FileF099_Obj_22:
    subsprite OAM_SIZE_16x16,    3,  -27,   36,    0
  FileF099_Obj_23:
    subsprite OAM_SIZE_16x16,    3,  -27,   68,    0
  FileF099_Obj_24:
    subsprite OAM_SIZE_16x16,    3,  -27,  100,    0
  FileF099_Obj_25:
    subsprite OAM_SIZE_16x16,  -19,  -45,    4,    0
  FileF099_Obj_26:
    subsprite OAM_SIZE_16x16,  -19,  -44,   36,    0
  FileF099_Obj_27:
    subsprite OAM_SIZE_16x16,  -19,  -44,   68,    0
  FileF099_Obj_28:
    subsprite OAM_SIZE_16x16,  -19,  -44,  100,    0
  FileF099_Obj_29:
    subsprite OAM_SIZE_16x16,  -19,  -28,    4,    0
  FileF099_Obj_30:
    subsprite OAM_SIZE_16x16,  -19,  -27,   36,    0
  FileF099_Obj_31:
    subsprite OAM_SIZE_16x16,  -19,  -27,   68,    0
  FileF099_Obj_32:
    subsprite OAM_SIZE_16x16,  -19,  -27,  100,    0
  FileF099_Obj_33:
    subsprite OAM_SIZE_16x32,   -8,  -50,    8,    0
  FileF099_Obj_34:
    subsprite OAM_SIZE_16x32,   -9,  -50,   10,    0
  FileF099_Obj_35:
    subsprite OAM_SIZE_16x32,   -8,  -50,   12,    0
  FileF099_Obj_36:
    subsprite OAM_SIZE_16x32,   -8,  -50,   14,    0

2:
FileF099_Cmds:
  FileF099_Cmd_0:
    animcmd   0,  1
  FileF099_Cmd_1:
    animcmd   1,  8
    animcmd   2,  8
    animcmd   3,  8
    animcmd   4,  8
  FileF099_Cmd_5:
    animcmd   5,  8
    animcmd   6,  8
    animcmd   7,  8
    animcmd   8,  8
  FileF099_Cmd_9:
    animcmd   9,  8
    animcmd  10,  8
    animcmd  11,  8
    animcmd  12,  8
  FileF099_Cmd_13:
    animcmd  13,  8
    animcmd  14,  8
    animcmd  15,  8
    animcmd  16,  8
  FileF099_Cmd_17:
    animcmd  17,  8
    animcmd  18,  8
    animcmd  19,  8
    animcmd  20,  8
  FileF099_Cmd_21:
    animcmd  21,  3
    animcmd  22,  3
    animcmd  23,  3
    animcmd  24,  3

FileF099_Tiles:
  .incbin "data/sprite_main/chandelier.4bpp"
