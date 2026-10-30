FileB991_Header:
  .2byte 739 @ palStart
  .2byte 5 @ metaspriteCount
  .2byte 2 @ animationCount
  .2byte 9 @ subspriteCount
  .2byte 5 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 132 @ offsetToAnims
  .4byte 148 @ offsetToSubsprites
  .4byte 220 @ offsetToCmds
  .4byte 240 @ offsetToTiles

FileB991_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x7740, FileB991_Obj_0,    1,          -88,  -96,   40,   32
  pose 0x780A, FileB991_Obj_1,    2,          -88,  -96,   40,   32
  pose 0x780B, FileB991_Obj_3,    2,          -88,  -96,   40,   32
  pose 0x780C, FileB991_Obj_5,    2,          -88,  -96,   40,   32
  pose 0x780D, FileB991_Obj_7,    2,          -88,  -96,   40,   32

FileB991_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xC927, FileB991_Cmd_0,  1
  animation 0x0E4E, FileB991_Cmd_1,  4

1:
FileB991_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileB991_Obj_0:
    subsprite OAM_SIZE_64x64,  -24,  -32,    0,    0
  FileB991_Obj_1:
    subsprite OAM_SIZE_64x64,  -24,  -32,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,    8,    0
  FileB991_Obj_3:
    subsprite OAM_SIZE_64x64,  -24,  -32,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   10,    0
  FileB991_Obj_5:
    subsprite OAM_SIZE_64x64,  -24,  -32,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   12,    0
  FileB991_Obj_7:
    subsprite OAM_SIZE_64x64,  -24,  -32,    0,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   14,    0

2:
FileB991_Cmds:
  FileB991_Cmd_0:
    animcmd  0,  1
  FileB991_Cmd_1:
    animcmd  1,  4
    animcmd  2,  4
    animcmd  3,  4
    animcmd  4,  4

FileB991_Tiles:
  .incbin "data/sprite_main/candle_box.4bpp"
