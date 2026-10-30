FileD27A_Header:
  .2byte 752 @ palStart
  .2byte 30 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 32 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 632 @ offsetToAnims
  .4byte 632 @ offsetToSubsprites
  .4byte 888 @ offsetToCmds
  .4byte 888 @ offsetToTiles

FileD27A_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xAE63, FileD27A_Obj_0,     1,          -32,  -32,   32,   32
  pose 0xB513, FileD27A_Obj_1,     1,          -32,  -32,   32,   32
  pose 0xC55B, FileD27A_Obj_2,     1,          -32,  -32,   32,   32
  pose 0xDD92, FileD27A_Obj_3,     1,          -32,  -32,   32,   32
  pose 0x5998, FileD27A_Obj_4,     1,          -32,  -32,   32,   32
  pose 0x918B, FileD27A_Obj_5,     1,          -32,  -32,   32,   32
  pose 0xB20E, FileD27A_Obj_6,     1,          -32,  -32,   32,   32
  pose 0x5598, FileD27A_Obj_7,     1,          -32,  -32,   32,   32
  pose 0xC91A, FileD27A_Obj_8,     1,          -32,  -32,   32,   32
  pose 0x1D16, FileD27A_Obj_9,     1,          -32,  -32,   32,   32
  pose 0x4596, FileD27A_Obj_10,    1,          -32,  -32,   32,   32
  pose 0xF183, FileD27A_Obj_11,    1,          -32,  -32,   32,   32
  pose 0x2499, FileD27A_Obj_12,    1,          -32,  -32,   32,   32
  pose 0xB897, FileD27A_Obj_13,    1,          -32,  -32,   32,   32
  pose 0xF13D, FileD27A_Obj_14,    1,          -32,  -32,   32,   32
  pose 0xF53D, FileD27A_Obj_15,    1,          -32,  -32,   32,   32
  pose 0xF93D, FileD27A_Obj_16,    1,          -32,  -32,   32,   32
  pose 0x44A6, FileD27A_Obj_17,    1,          -32,  -32,   32,   32
  pose 0xBCA8, FileD27A_Obj_18,    1,          -32,  -32,   32,   32
  pose 0xBCAC, FileD27A_Obj_19,    1,          -32,  -32,   32,   32
  pose 0xD8AA, FileD27A_Obj_20,    1,          -32,  -32,   32,   32
  pose 0x6CEE, FileD27A_Obj_21,    1,          -32,  -32,   32,   32
  pose 0x70EE, FileD27A_Obj_22,    1,          -32,  -32,   32,   32
  pose 0x74EE, FileD27A_Obj_23,    1,          -32,  -32,   32,   32
  pose 0x4187, FileD27A_Obj_24,    1,          -32,  -32,   32,   32
  pose 0xC193, FileD27A_Obj_25,    1,          -32,  -32,   32,   32
  pose 0x786D, FileD27A_Obj_26,    1,          -32,  -32,   32,   32
  pose 0x249F, FileD27A_Obj_27,    2,          -32,  -32,   68,   32
  pose 0x9416, FileD27A_Obj_29,    2,          -32,  -32,   68,   32
  pose 0x991B, FileD27A_Obj_31,    1,          -32,  -32,   32,   32

FileD27A_Anims:

1:
FileD27A_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD27A_Obj_0:
    subsprite OAM_SIZE_32x32,    0,    0,    0,    0
  FileD27A_Obj_1:
    subsprite OAM_SIZE_32x32,    0,    0,    4,    2
  FileD27A_Obj_2:
    subsprite OAM_SIZE_32x32,    0,    0,    8,    0
  FileD27A_Obj_3:
    subsprite OAM_SIZE_32x32,    0,    0,   12,    2
  FileD27A_Obj_4:
    subsprite OAM_SIZE_32x32,    0,    0,   64,    0
  FileD27A_Obj_5:
    subsprite OAM_SIZE_32x32,    0,    0,   68,    0
  FileD27A_Obj_6:
    subsprite OAM_SIZE_32x32,    0,    0,   72,    0
  FileD27A_Obj_7:
    subsprite OAM_SIZE_32x32,    0,    0,   76,    0
  FileD27A_Obj_8:
    subsprite OAM_SIZE_32x32,    0,    0,  128,    0
  FileD27A_Obj_9:
    subsprite OAM_SIZE_32x32,    0,    0,  132,    0
  FileD27A_Obj_10:
    subsprite OAM_SIZE_32x32,    0,    0,  136,    0
  FileD27A_Obj_11:
    subsprite OAM_SIZE_32x32,    0,    0,  140,    2
  FileD27A_Obj_12:
    subsprite OAM_SIZE_32x32,    0,    0,  192,    0
  FileD27A_Obj_13:
    subsprite OAM_SIZE_32x32,    0,    0,  196,    0
  FileD27A_Obj_14:
    subsprite OAM_SIZE_32x32,    0,    0,  200,    0
  FileD27A_Obj_15:
    subsprite OAM_SIZE_32x32,    0,    0,  204,    0
  FileD27A_Obj_16:
    subsprite OAM_SIZE_32x32,    0,    0,  256,    0
  FileD27A_Obj_17:
    subsprite OAM_SIZE_32x32,    0,    0,  260,    0
  FileD27A_Obj_18:
    subsprite OAM_SIZE_32x32,    0,    0,  264,    0
  FileD27A_Obj_19:
    subsprite OAM_SIZE_32x32,    0,    0,  268,    2
  FileD27A_Obj_20:
    subsprite OAM_SIZE_32x32,    0,    0,  320,    0
  FileD27A_Obj_21:
    subsprite OAM_SIZE_32x32,    0,    0,  324,    0
  FileD27A_Obj_22:
    subsprite OAM_SIZE_32x32,    0,    0,  328,    0
  FileD27A_Obj_23:
    subsprite OAM_SIZE_32x32,    0,    0,  332,    2
  FileD27A_Obj_24:
    subsprite OAM_SIZE_32x32,    0,    0,  384,    1
  FileD27A_Obj_25:
    subsprite OAM_SIZE_32x32,    0,    0,  388,    2
  FileD27A_Obj_26:
    subsprite OAM_SIZE_32x32,    0,    0,  392,    0
  FileD27A_Obj_27:
    subsprite OAM_SIZE_32x32,    0,    0,    0,    0
    subsprite OAM_SIZE_32x32,   36,    0,  384,    1, xflip=1
  FileD27A_Obj_29:
    subsprite OAM_SIZE_32x32,   36,    0,  384,    1, xflip=1
    subsprite OAM_SIZE_32x32,    0,    0,    4,    2
  FileD27A_Obj_31:
    subsprite OAM_SIZE_32x32,    0,    0,  396,    0

FileD27A_Cmds:

FileD27A_Tiles:
  .incbin "data/sprite_main/portraits.4bpp"
