File0C23_Header:
  .2byte 734 @ palStart
  .2byte 3 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 3 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 92 @ offsetToAnims
  .4byte 92 @ offsetToSubsprites
  .4byte 116 @ offsetToCmds
  .4byte 116 @ offsetToTiles

File0C23_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0xB2E8, File0C23_Obj_0,    1,          -96,  -96,   32,   32
  pose 0xB2E9, File0C23_Obj_1,    1,          -96,  -96,   32,   32
  pose 0xB2EA, File0C23_Obj_2,    1,          -96,  -64,   32,   64

File0C23_Anims:

1:
File0C23_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File0C23_Obj_0:
    subsprite OAM_SIZE_64x64,  -32,  -32,    0,    0
  File0C23_Obj_1:
    subsprite OAM_SIZE_64x64,  -32,  -32,    8,    0
  File0C23_Obj_2:
    subsprite OAM_SIZE_64x32,  -32,    0,  136,    0

File0C23_Cmds:

File0C23_Tiles:
  .incbin "data/spriteset/event_sun_ray.4bpp"
