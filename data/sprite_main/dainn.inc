FileE349_Header:
  .2byte 744 @ palStart
  .2byte 7 @ metaspriteCount
  .2byte 4 @ animationCount
  .2byte 10 @ subspriteCount
  .2byte 8 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 172 @ offsetToAnims
  .4byte 204 @ offsetToSubsprites
  .4byte 284 @ offsetToCmds
  .4byte 316 @ offsetToTiles

FileE349_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0xCBC3, FileE349_Obj_0,    2,          -48,  -67,   16,   13
  pose 0xCEB2, FileE349_Obj_2,    2,          -48,  -67,   16,   13
  pose 0xCEB3, FileE349_Obj_4,    2,          -48,  -67,   16,   13
  pose 0xCEB4, FileE349_Obj_6,    1,          -48,  -59,   16,    5
  pose 0xCEB5, FileE349_Obj_7,    1,          -48,  -51,   16,   13
  pose 0xCEB6, FileE349_Obj_8,    1,          -24,  -26,    8,    6
  pose 0x71F8, FileE349_Obj_9,    1,          -47,  -58,   17,    6

FileE349_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0x4E74, FileE349_Cmd_0,  1
  animation 0x4E94, FileE349_Cmd_1,  1
  animation 0x98C2, FileE349_Cmd_2,  5
  animation 0xDF8D, FileE349_Cmd_7,  1

1:
FileE349_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE349_Obj_0:
    subsprite OAM_SIZE_32x32,  -16,  -35,  112,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  177,    0
  FileE349_Obj_2:
    subsprite OAM_SIZE_32x32,  -16,  -35,    0,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,   65,    0
  FileE349_Obj_4:
    subsprite OAM_SIZE_32x32,  -16,  -35,    4,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,   69,    0
  FileE349_Obj_6:
    subsprite OAM_SIZE_32x32,  -16,  -27,    8,    0
  FileE349_Obj_7:
    subsprite OAM_SIZE_32x32,  -16,  -19,   12,    0
  FileE349_Obj_8:
    subsprite OAM_SIZE_16x16,   -8,  -10,   80,    0
  FileE349_Obj_9:
    subsprite OAM_SIZE_32x32,  -15,  -26,   76,    0

2:
FileE349_Cmds:
  FileE349_Cmd_0:
    animcmd  0,  1
  FileE349_Cmd_1:
    animcmd  1,  1
  FileE349_Cmd_2:
    animcmd  1,  6
    animcmd  2,  6
    animcmd  3,  6
    animcmd  4,  6
    animcmd  5,  6
  FileE349_Cmd_7:
    animcmd  6,  1

FileE349_Tiles:
  .incbin "data/sprite_main/dainn.4bpp"
