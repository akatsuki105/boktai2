FileD353_Header:
  .2byte 732 @ palStart
  .2byte 15 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 86 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 332 @ offsetToAnims
  .4byte 332 @ offsetToSubsprites
  .4byte 1020 @ offsetToCmds
  .4byte 1020 @ offsetToTiles

FileD353_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x1C23, FileD353_Obj_0,    11,         -32,    0,  240,  182
  pose 0xDBC1, FileD353_Obj_11,   10,           0,    0,  192,  112
  pose 0x43BA, FileD353_Obj_21,   4,            0,    0,  240,  146
  pose 0x43BB, FileD353_Obj_25,   4,            0,    0,  240,  146
  pose 0x43BC, FileD353_Obj_29,   4,            0,    0,  240,  146
  pose 0x43BD, FileD353_Obj_33,   4,            0,    0,  240,  146
  pose 0x431A, FileD353_Obj_37,   4,          -16,    0,   48,  146
  pose 0x431B, FileD353_Obj_41,   4,          -16,    0,   48,  146
  pose 0x431C, FileD353_Obj_45,   4,          -16,    0,   48,  146
  pose 0x431D, FileD353_Obj_49,   4,          -16,    0,   48,  146
  pose 0x14AD, FileD353_Obj_53,   9,            0,    0,  191,  146
  pose 0x8E78, FileD353_Obj_62,   9,            0,    0,  193,  146
  pose 0x80CD, FileD353_Obj_71,   6,            0,    0,  165,  146
  pose 0xE40D, FileD353_Obj_77,   4,            0,    0,  150,  146
  pose 0x7CF4, FileD353_Obj_81,   5,            0,    0,  159,  146

FileD353_Anims:

1:
FileD353_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD353_Obj_0:
    subsprite OAM_SIZE_32x8,     0,  150,   96,    0
    subsprite OAM_SIZE_32x8,    32,  150,  100,    0
    subsprite OAM_SIZE_32x8,    64,  150,  104,    0
    subsprite OAM_SIZE_32x8,    96,  150,  108,    0
    subsprite OAM_SIZE_32x8,   128,  150,  112,    0
    subsprite OAM_SIZE_32x8,   160,  150,  116,    0
    subsprite OAM_SIZE_32x8,   192,  150,  120,    0
    subsprite OAM_SIZE_16x8,   224,  150,  124,    0
    subsprite OAM_SIZE_8x8,    222,  158,  126,    0
    subsprite OAM_SIZE_8x8,    112,  158,  126,    0
    subsprite OAM_SIZE_16x8,   220,   73,  192,    0
  FileD353_Obj_11:
    subsprite OAM_SIZE_32x16,   48,   80,  224,    1
    subsprite OAM_SIZE_32x16,   80,   80,  228,    1
    subsprite OAM_SIZE_32x16,  112,   80,  232,    1
    subsprite OAM_SIZE_32x16,  144,   80,  236,    1
    subsprite OAM_SIZE_32x8,    56,   72,  209,    1
    subsprite OAM_SIZE_32x8,    88,   72,  213,    1
    subsprite OAM_SIZE_32x8,   120,   72,  217,    1
    subsprite OAM_SIZE_8x8,    152,   72,  221,    1
    subsprite OAM_SIZE_16x16,  176,   80,  190,    1
    subsprite OAM_SIZE_16x8,   176,   72,  174,    1
  FileD353_Obj_21:
    subsprite OAM_SIZE_16x16,  224,  130,  188,    0
    subsprite OAM_SIZE_16x16,  192,  130,  188,    0
    subsprite OAM_SIZE_16x16,  208,  130,  188,    0
    subsprite OAM_SIZE_8x16,   193,  130,   68,    0, xflip=1
  FileD353_Obj_25:
    subsprite OAM_SIZE_16x16,  224,  130,  188,    0
    subsprite OAM_SIZE_16x16,  192,  130,  188,    0
    subsprite OAM_SIZE_16x16,  208,  130,  188,    0
    subsprite OAM_SIZE_8x16,   194,  130,   68,    0, xflip=1
  FileD353_Obj_29:
    subsprite OAM_SIZE_16x16,  224,  130,  188,    0
    subsprite OAM_SIZE_16x16,  192,  130,  188,    0
    subsprite OAM_SIZE_16x16,  208,  130,  188,    0
    subsprite OAM_SIZE_8x16,   195,  130,   68,    0, xflip=1
  FileD353_Obj_33:
    subsprite OAM_SIZE_16x16,  224,  130,  188,    0
    subsprite OAM_SIZE_16x16,  192,  130,  188,    0
    subsprite OAM_SIZE_16x16,  208,  130,  188,    0
    subsprite OAM_SIZE_8x16,   200,  130,   68,    0, xflip=1
  FileD353_Obj_37:
    subsprite OAM_SIZE_16x16,    0,  130,  188,    0
    subsprite OAM_SIZE_16x16,   16,  130,  188,    0
    subsprite OAM_SIZE_16x16,   32,  130,  188,    0
    subsprite OAM_SIZE_8x16,    39,  130,   68,    0
  FileD353_Obj_41:
    subsprite OAM_SIZE_16x16,    0,  130,  188,    0
    subsprite OAM_SIZE_16x16,   16,  130,  188,    0
    subsprite OAM_SIZE_16x16,   32,  130,  188,    0
    subsprite OAM_SIZE_8x16,    38,  130,   68,    0
  FileD353_Obj_45:
    subsprite OAM_SIZE_16x16,    0,  130,  188,    0
    subsprite OAM_SIZE_16x16,   16,  130,  188,    0
    subsprite OAM_SIZE_16x16,   32,  130,  188,    0
    subsprite OAM_SIZE_8x16,    37,  130,   68,    0
  FileD353_Obj_49:
    subsprite OAM_SIZE_16x16,    0,  130,  188,    0
    subsprite OAM_SIZE_16x16,   16,  130,  188,    0
    subsprite OAM_SIZE_16x16,   32,  130,  188,    0
    subsprite OAM_SIZE_8x16,    32,  130,   68,    0
  FileD353_Obj_53:
    subsprite OAM_SIZE_16x16,   49,  130,   38,    0
    subsprite OAM_SIZE_16x16,   65,  130,   64,    0
    subsprite OAM_SIZE_16x16,   80,  130,   42,    0
    subsprite OAM_SIZE_16x16,   94,  130,    8,    0
    subsprite OAM_SIZE_16x16,  118,  130,   42,    0
    subsprite OAM_SIZE_16x16,  132,  130,   44,    0
    subsprite OAM_SIZE_16x16,  146,  130,    0,    0
    subsprite OAM_SIZE_16x16,  162,  130,   40,    0
    subsprite OAM_SIZE_16x16,  175,  130,   44,    0
  FileD353_Obj_62:
    subsprite OAM_SIZE_16x16,   48,  130,    6,    0
    subsprite OAM_SIZE_16x16,   64,  130,    0,    0
    subsprite OAM_SIZE_16x16,   80,  130,   32,    0
    subsprite OAM_SIZE_16x16,   96,  130,    4,    0
    subsprite OAM_SIZE_16x16,  120,  130,   42,    0
    subsprite OAM_SIZE_16x16,  134,  130,   44,    0
    subsprite OAM_SIZE_16x16,  148,  130,    0,    0
    subsprite OAM_SIZE_16x16,  164,  130,   40,    0
    subsprite OAM_SIZE_16x16,  177,  130,   44,    0
  FileD353_Obj_71:
    subsprite OAM_SIZE_16x16,   77,  130,   36,    0
    subsprite OAM_SIZE_16x16,   92,  130,   38,    0
    subsprite OAM_SIZE_16x16,  107,  130,   44,    0
    subsprite OAM_SIZE_16x16,  121,  130,   10,    0
    subsprite OAM_SIZE_16x16,  134,  130,   36,    0
    subsprite OAM_SIZE_16x16,  149,  130,   34,    0
  FileD353_Obj_77:
    subsprite OAM_SIZE_16x16,   91,  130,   14,    0
    subsprite OAM_SIZE_16x16,  105,  130,   10,    0
    subsprite OAM_SIZE_16x16,  118,  130,   34,    0
    subsprite OAM_SIZE_16x16,  134,  130,   12,    0
  FileD353_Obj_81:
    subsprite OAM_SIZE_16x16,   81,  130,   42,    0
    subsprite OAM_SIZE_16x16,   97,  130,   36,    0
    subsprite OAM_SIZE_16x16,  113,  130,   64,    0
    subsprite OAM_SIZE_16x16,  128,  130,   34,    0
    subsprite OAM_SIZE_16x16,  143,  130,   66,    0

FileD353_Cmds:

FileD353_Tiles:
  .incbin "data/sprite_main/D353.4bpp"
