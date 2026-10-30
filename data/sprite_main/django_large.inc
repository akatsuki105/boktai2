File1774_Header:
  .2byte 719 @ palStart
  .2byte 1 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 20 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 52 @ offsetToAnims
  .4byte 52 @ offsetToSubsprites
  .4byte 212 @ offsetToCmds
  .4byte 212 @ offsetToTiles

File1774_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x0001, File1774_Obj_0,    20,          -8,  -56,  224,  160

File1774_Anims:

1:
File1774_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File1774_Obj_0:
    subsprite OAM_SIZE_64x64,   64,    8,    0,    1
    subsprite OAM_SIZE_8x8,     72,   72,  129,    0
    subsprite OAM_SIZE_32x8,    80,   72,  130,    1
    subsprite OAM_SIZE_32x64,  128,   16,   24,    0
    subsprite OAM_SIZE_64x32,   80,   80,  146,    0
    subsprite OAM_SIZE_16x8,   112,   72,  134,    0
    subsprite OAM_SIZE_16x8,    64,   88,  160,    0
    subsprite OAM_SIZE_32x32,  144,   80,  154,    0
    subsprite OAM_SIZE_16x32,  176,   56,  110,    0
    subsprite OAM_SIZE_32x16,   80,  112,  210,    0
    subsprite OAM_SIZE_32x16,  112,  112,  214,    0
    subsprite OAM_SIZE_8x16,   144,  112,  218,    0
    subsprite OAM_SIZE_32x16,   88,  128,  257,    0
    subsprite OAM_SIZE_8x8,     80,  128,  256,    0
    subsprite OAM_SIZE_32x16,  120,  128,  261,    0
    subsprite OAM_SIZE_32x32,  192,   48,  293,    0
    subsprite OAM_SIZE_32x32,   32,   64,  321,    0
    subsprite OAM_SIZE_32x16,   24,   48,  288,    0
    subsprite OAM_SIZE_16x8,   152,  112,  219,    0
    subsprite OAM_SIZE_16x32,  160,   48,   92,    0

File1774_Cmds:

File1774_Tiles:
  .incbin "data/sprite_main/django_large.4bpp"
