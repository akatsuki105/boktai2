FileAF82_Header:
  .2byte 695 @ palStart
  .2byte 1 @ metaspriteCount
  .2byte 1 @ animationCount
  .2byte 4 @ subspriteCount
  .2byte 1 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 52 @ offsetToAnims
  .4byte 60 @ offsetToSubsprites
  .4byte 92 @ offsetToCmds
  .4byte 96 @ offsetToTiles

FileAF82_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x698B, FileAF82_Obj_0,     4,          -24,  -25,   16,   39

FileAF82_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB34E, FileAF82_Cmd_0,     1

1:
FileAF82_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileAF82_Obj_0:
    subsprite OAM_SIZE_16x32,   -8,   -9,    0,    0
    subsprite OAM_SIZE_16x8,    -8,   23,   64,    0
    subsprite OAM_SIZE_8x16,   -16,    7,    2,    0
    subsprite OAM_SIZE_8x16,     8,    7,   34,    0

2:
FileAF82_Cmds:
  FileAF82_Cmd_0:
    animcmd  0,  1

FileAF82_Tiles:
  .incbin "data/sprite_main/megaman.4bpp"
