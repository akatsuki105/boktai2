FileE2DE_Header:
  .2byte 750 @ palStart
  .2byte 3 @ metaspriteCount
  .2byte 1 @ animationCount
  .2byte 9 @ subspriteCount
  .2byte 3 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 92 @ offsetToAnims
  .4byte 100 @ offsetToSubsprites
  .4byte 172 @ offsetToCmds
  .4byte 184 @ offsetToTiles

FileE2DE_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x3229, FileE2DE_Obj_0,    3,          -24,  -57,    8,    7
  pose 0x322A, FileE2DE_Obj_3,    3,          -24,  -57,    8,    7
  pose 0x322B, FileE2DE_Obj_6,    3,          -24,  -57,    8,    7

FileE2DE_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0x3229, FileE2DE_Cmd_0,  3

1:
FileE2DE_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE2DE_Obj_0:
    subsprite OAM_SIZE_16x16,   -8,  -41,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   32,    0
    subsprite OAM_SIZE_16x8,    -8,   -9,   64,    0
  FileE2DE_Obj_3:
    subsprite OAM_SIZE_16x16,   -8,  -41,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   34,    0
    subsprite OAM_SIZE_16x8,    -8,   -9,   64,    0
  FileE2DE_Obj_6:
    subsprite OAM_SIZE_16x16,   -8,  -41,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   36,    0
    subsprite OAM_SIZE_16x8,    -8,   -9,   64,    0

2:
FileE2DE_Cmds:
  FileE2DE_Cmd_0:
    animcmd  0,  8
    animcmd  1,  8
    animcmd  2,  8

FileE2DE_Tiles:
  .incbin "data/sprite_main/carmilla.4bpp"
