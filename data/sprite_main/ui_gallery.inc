File5EBF_Header:
  .2byte 723 @ palStart
  .2byte 36 @ metaspriteCount
  .2byte 0 @ animationCount
  .2byte 176 @ subspriteCount
  .2byte 0 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 752 @ offsetToAnims
  .4byte 752 @ offsetToSubsprites
  .4byte 2160 @ offsetToCmds
  .4byte 2160 @ offsetToTiles

File5EBF_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x4E3C, File5EBF_Obj_0,     1,           -8,   -8,    8,    8
  pose 0x4E3D, File5EBF_Obj_1,     1,           -8,   -8,    8,    8
  pose 0x4E3E, File5EBF_Obj_2,     1,           -8,   -8,    8,    8
  pose 0x4E3F, File5EBF_Obj_3,     1,           -8,   -8,    8,    8
  pose 0x4E40, File5EBF_Obj_4,     1,           -8,   -8,    8,    8
  pose 0x4E41, File5EBF_Obj_5,     1,           -8,   -8,    8,    8
  pose 0x4E42, File5EBF_Obj_6,     1,           -8,   -8,    8,    8
  pose 0x4E43, File5EBF_Obj_7,     1,           -8,   -8,    8,    8
  pose 0x4E44, File5EBF_Obj_8,     1,           -8,   -8,    8,    8
  pose 0x4E45, File5EBF_Obj_9,     1,           -8,   -8,    8,    8
  pose 0x0E48, File5EBF_Obj_10,    1,           -8,    0,    8,   16
  pose 0x89E2, File5EBF_Obj_11,    1,           -8,   -8,    8,    8
  pose 0xCFB8, File5EBF_Obj_12,    2,            0,    0,   40,   40
  pose 0xCF42, File5EBF_Obj_14,    1,            0,  -16,   48,   16
  pose 0xCF43, File5EBF_Obj_15,    1,            0,    0,   40,   35
  pose 0x19A0, File5EBF_Obj_16,    6,           -8,  -32,  216,   32
  pose 0x19A1, File5EBF_Obj_22,    8,          -16,  -32,  240,   32
  pose 0x1AE4, File5EBF_Obj_30,    7,          -16,    0,  240,   43
  pose 0xA508, File5EBF_Obj_37,    7,          -16,  -13,  240,   51
  pose 0xBB48, File5EBF_Obj_44,    6,          -16,    0,  240,   35
  pose 0x4F3B, File5EBF_Obj_50,    7,          -16,  -13,  240,   51
  pose 0x6510, File5EBF_Obj_57,    7,          -16,  -13,  240,   51
  pose 0x3B53, File5EBF_Obj_64,    7,          -16,    0,  224,   64
  pose 0x3B54, File5EBF_Obj_71,    3,            0,    0,  224,   84
  pose 0x2A79, File5EBF_Obj_74,    8,            0,    0,  208,  116
  pose 0xED9F, File5EBF_Obj_82,    13,         -16,  -32,  240,   32
  pose 0xEDA0, File5EBF_Obj_95,    12,         -16,  -32,  240,   32
  pose 0xEDA1, File5EBF_Obj_107,   14,         -16,  -32,  240,   32
  pose 0xEDA2, File5EBF_Obj_121,   12,         -16,  -32,  240,   32
  pose 0x887A, File5EBF_Obj_133,   1,            0,  -16,  136,   48
  pose 0xE99F, File5EBF_Obj_134,   12,         -16,  -32,  240,   32
  pose 0xE9A0, File5EBF_Obj_146,   12,         -16,  -32,  240,   32
  pose 0xE9A1, File5EBF_Obj_158,   12,         -16,  -32,  240,   32
  pose 0x36B0, File5EBF_Obj_170,   4,          -12,  -12,   60,   84
  pose 0x2DD8, File5EBF_Obj_174,   1,          -16,  -16,   16,   16
  pose 0x2DDE, File5EBF_Obj_175,   1,            0,  -16,  240,   16

File5EBF_Anims:

1:
File5EBF_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File5EBF_Obj_0:
    subsprite OAM_SIZE_8x16,     0,    0,  128,    1
  File5EBF_Obj_1:
    subsprite OAM_SIZE_8x16,     0,    0,  129,    1
  File5EBF_Obj_2:
    subsprite OAM_SIZE_8x16,     0,    0,  130,    1
  File5EBF_Obj_3:
    subsprite OAM_SIZE_8x16,     0,    0,  131,    1
  File5EBF_Obj_4:
    subsprite OAM_SIZE_8x16,     0,    0,  132,    1
  File5EBF_Obj_5:
    subsprite OAM_SIZE_8x16,     0,    0,  133,    1
  File5EBF_Obj_6:
    subsprite OAM_SIZE_8x16,     0,    0,  134,    1
  File5EBF_Obj_7:
    subsprite OAM_SIZE_8x16,     0,    0,  135,    1
  File5EBF_Obj_8:
    subsprite OAM_SIZE_8x16,     0,    0,  136,    1
  File5EBF_Obj_9:
    subsprite OAM_SIZE_8x16,     0,    0,  137,    1
  File5EBF_Obj_10:
    subsprite OAM_SIZE_8x8,      0,    8,  117,    1
  File5EBF_Obj_11:
    subsprite OAM_SIZE_8x16,     0,    0,   69,    1
  File5EBF_Obj_12:
    subsprite OAM_SIZE_16x16,   16,   24,  138,    1
    subsprite OAM_SIZE_8x8,     32,   32,  117,    1
  File5EBF_Obj_14:
    subsprite OAM_SIZE_16x16,   32,    0,  206,    0
  File5EBF_Obj_15:
    subsprite OAM_SIZE_16x16,   24,   19,  206,    1
  File5EBF_Obj_16:
    subsprite OAM_SIZE_32x16,   88,    0,  224,    0
    subsprite OAM_SIZE_32x16,  120,    0,  228,    0
    subsprite OAM_SIZE_32x16,   24,    0,   96,    0
    subsprite OAM_SIZE_32x16,  184,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_32x16,  152,    0,   97,    0
    subsprite OAM_SIZE_32x16,   56,    0,   97,    0
  File5EBF_Obj_22:
    subsprite OAM_SIZE_32x16,   24,    0,   96,    0
    subsprite OAM_SIZE_32x16,   56,    0,   97,    0
    subsprite OAM_SIZE_32x16,   88,    0,  224,    0
    subsprite OAM_SIZE_32x16,  120,    0,  228,    0
    subsprite OAM_SIZE_32x16,  152,    0,   97,    0
    subsprite OAM_SIZE_32x16,  184,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_30:
    subsprite OAM_SIZE_16x16,   48,   19,  102,    1
    subsprite OAM_SIZE_16x16,   80,   19,  164,    1
    subsprite OAM_SIZE_16x16,   96,   19,  104,    1
    subsprite OAM_SIZE_8x16,   168,   19,   69,    1
    subsprite OAM_SIZE_16x16,    0,   19,  236,    0
    subsprite OAM_SIZE_16x16,  224,   19,  238,    0
    subsprite OAM_SIZE_16x8,    64,   27,  218,    1
  File5EBF_Obj_37:
    subsprite OAM_SIZE_8x16,   168,   19,   69,    1
    subsprite OAM_SIZE_16x16,    0,   19,  236,    0
    subsprite OAM_SIZE_16x16,  224,   19,  238,    0
    subsprite OAM_SIZE_16x16,   48,   19,    0,    1
    subsprite OAM_SIZE_32x16,   80,   19,  106,    1
    subsprite OAM_SIZE_16x16,   64,   19,  204,    1
    subsprite OAM_SIZE_16x16,  112,   19,  170,    1
  File5EBF_Obj_44:
    subsprite OAM_SIZE_8x16,   168,   19,   69,    1
    subsprite OAM_SIZE_16x16,    0,   19,  236,    0
    subsprite OAM_SIZE_16x16,  224,   19,  238,    0
    subsprite OAM_SIZE_16x16,   48,   19,  110,    1
    subsprite OAM_SIZE_16x16,   64,   19,  204,    1
    subsprite OAM_SIZE_16x16,   80,   19,   74,    1
  File5EBF_Obj_50:
    subsprite OAM_SIZE_8x16,   168,   19,   69,    1
    subsprite OAM_SIZE_16x16,    0,   19,  236,    0
    subsprite OAM_SIZE_16x16,  224,   19,  238,    0
    subsprite OAM_SIZE_32x16,   48,   19,   70,    1
    subsprite OAM_SIZE_16x16,   80,   19,  204,    1
    subsprite OAM_SIZE_16x16,   96,   19,  104,    1
    subsprite OAM_SIZE_16x16,  112,   19,  198,    1
  File5EBF_Obj_57:
    subsprite OAM_SIZE_8x16,   168,   19,   69,    1
    subsprite OAM_SIZE_16x16,    0,   19,  236,    0
    subsprite OAM_SIZE_16x16,  224,   19,  238,    0
    subsprite OAM_SIZE_32x16,   48,   19,  140,    1
    subsprite OAM_SIZE_16x16,   96,   19,   32,    1
    subsprite OAM_SIZE_16x16,  112,   19,  194,    1
    subsprite OAM_SIZE_16x8,    80,   27,  218,    1
  File5EBF_Obj_64:
    subsprite OAM_SIZE_32x16,   16,   32,   64,    0
    subsprite OAM_SIZE_32x16,  192,   32,   64,    0, xflip=1
    subsprite OAM_SIZE_32x16,   48,   32,   65,    0
    subsprite OAM_SIZE_32x16,   80,   32,   65,    0
    subsprite OAM_SIZE_32x16,  128,   32,   65,    0
    subsprite OAM_SIZE_32x16,  160,   32,   65,    0
    subsprite OAM_SIZE_16x16,  112,   32,   65,    0
  File5EBF_Obj_71:
    subsprite OAM_SIZE_32x16,  128,   52,   64,    0
    subsprite OAM_SIZE_32x16,  192,   52,   64,    0, xflip=1
    subsprite OAM_SIZE_32x16,  160,   52,   65,    0
  File5EBF_Obj_74:
    subsprite OAM_SIZE_32x16,  144,   52,   32,    1
    subsprite OAM_SIZE_16x16,  176,   52,   40,    1
    subsprite OAM_SIZE_16x16,  144,  100,    0,    1
    subsprite OAM_SIZE_16x16,  160,  100,   34,    1
    subsprite OAM_SIZE_32x16,  144,   68,    4,    1
    subsprite OAM_SIZE_32x16,  144,   84,   36,    1
    subsprite OAM_SIZE_16x16,  192,  100,  198,    1
    subsprite OAM_SIZE_16x16,  176,  100,    2,    1
  File5EBF_Obj_82:
    subsprite OAM_SIZE_32x16,   48,    0,  232,    0
    subsprite OAM_SIZE_32x16,   80,    0,  228,    0
    subsprite OAM_SIZE_16x16,  144,    0,  168,    0
    subsprite OAM_SIZE_16x16,  176,    0,  170,    0
    subsprite OAM_SIZE_16x16,   24,    0,   96,    0
    subsprite OAM_SIZE_8x16,    40,    0,  100,    0
    subsprite OAM_SIZE_8x16,   192,    0,  100,    0
    subsprite OAM_SIZE_16x16,  200,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_32x16,  112,    0,   97,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
    subsprite OAM_SIZE_16x8,   160,    8,  218,    0
    subsprite OAM_SIZE_16x8,   160,    0,   99,    0
  File5EBF_Obj_95:
    subsprite OAM_SIZE_32x16,   48,    0,  232,    0
    subsprite OAM_SIZE_32x16,   80,    0,  228,    0
    subsprite OAM_SIZE_16x16,   24,    0,   96,    0
    subsprite OAM_SIZE_8x16,    40,    0,  100,    0
    subsprite OAM_SIZE_32x16,  112,    0,   97,    0
    subsprite OAM_SIZE_8x16,   192,    0,  100,    0
    subsprite OAM_SIZE_16x16,  200,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_16x16,  144,    0,  164,    0
    subsprite OAM_SIZE_16x16,  160,    0,  160,    0
    subsprite OAM_SIZE_16x16,  176,    0,  192,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_107:
    subsprite OAM_SIZE_32x16,   48,    0,  232,    0
    subsprite OAM_SIZE_32x16,   80,    0,  228,    0
    subsprite OAM_SIZE_16x16,   24,    0,   96,    0
    subsprite OAM_SIZE_8x16,    40,    0,  100,    0
    subsprite OAM_SIZE_8x16,   192,    0,  100,    0
    subsprite OAM_SIZE_16x16,  200,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_16x16,  128,    0,  172,    0
    subsprite OAM_SIZE_16x16,  144,    0,  204,    0
    subsprite OAM_SIZE_16x16,  160,    0,  166,    0
    subsprite OAM_SIZE_16x16,  112,    0,   99,    0
    subsprite OAM_SIZE_16x8,   176,    8,  218,    0
    subsprite OAM_SIZE_16x8,   176,    0,   99,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_121:
    subsprite OAM_SIZE_32x16,   48,    0,  232,    0
    subsprite OAM_SIZE_32x16,   80,    0,  228,    0
    subsprite OAM_SIZE_16x16,   24,    0,   96,    0
    subsprite OAM_SIZE_8x16,    40,    0,  100,    0
    subsprite OAM_SIZE_8x16,   192,    0,  100,    0
    subsprite OAM_SIZE_16x16,  200,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_16x16,  112,    0,   99,    0
    subsprite OAM_SIZE_16x16,  160,    0,  162,    0
    subsprite OAM_SIZE_16x16,  176,    0,  204,    0
    subsprite OAM_SIZE_32x16,  128,    0,   97,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_133:
    subsprite OAM_SIZE_32x32,  104,   16,   44,    0
  File5EBF_Obj_134:
    subsprite OAM_SIZE_32x16,   56,    0,  192,    0
    subsprite OAM_SIZE_32x16,   88,    0,  196,    0
    subsprite OAM_SIZE_16x16,  160,    0,  174,    0
    subsprite OAM_SIZE_8x16,   176,    0,  129,    0
    subsprite OAM_SIZE_8x16,   120,    0,  100,    0
    subsprite OAM_SIZE_32x16,   24,    0,   96,    0
    subsprite OAM_SIZE_32x16,  184,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_16x16,  128,    0,  200,    0
    subsprite OAM_SIZE_16x8,   144,    8,  218,    0
    subsprite OAM_SIZE_16x8,   144,    0,   99,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_146:
    subsprite OAM_SIZE_32x16,   56,    0,  192,    0
    subsprite OAM_SIZE_32x16,   88,    0,  196,    0
    subsprite OAM_SIZE_16x16,  160,    0,  174,    0
    subsprite OAM_SIZE_8x16,   120,    0,  100,    0
    subsprite OAM_SIZE_32x16,   24,    0,   96,    0
    subsprite OAM_SIZE_32x16,  184,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_8x16,   176,    0,  130,    0
    subsprite OAM_SIZE_16x16,  128,    0,  200,    0
    subsprite OAM_SIZE_16x8,   144,    0,   99,    0
    subsprite OAM_SIZE_16x8,   144,    8,  218,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_158:
    subsprite OAM_SIZE_32x16,   56,    0,  192,    0
    subsprite OAM_SIZE_32x16,   88,    0,  196,    0
    subsprite OAM_SIZE_16x16,  160,    0,  174,    0
    subsprite OAM_SIZE_8x16,   120,    0,  100,    0
    subsprite OAM_SIZE_32x16,   24,    0,   96,    0
    subsprite OAM_SIZE_32x16,  184,    0,   96,    0, xflip=1
    subsprite OAM_SIZE_8x16,   176,    0,  131,    0
    subsprite OAM_SIZE_16x16,  128,    0,  200,    0
    subsprite OAM_SIZE_16x8,   144,    0,   99,    0
    subsprite OAM_SIZE_16x8,   144,    8,  218,    0
    subsprite OAM_SIZE_16x16,  224,    0,  238,    0
    subsprite OAM_SIZE_16x16,    0,    0,  236,    0
  File5EBF_Obj_170:
    subsprite OAM_SIZE_32x8,    20,   20,   12,    0
    subsprite OAM_SIZE_8x32,    52,   20,   11,    0
    subsprite OAM_SIZE_8x32,    20,   28,   10,    0
    subsprite OAM_SIZE_32x8,    28,   52,   28,    0
  File5EBF_Obj_174:
    subsprite OAM_SIZE_16x16,    0,    0,  236,    1
  File5EBF_Obj_175:
    subsprite OAM_SIZE_16x16,  224,    0,  238,    1

File5EBF_Cmds:

File5EBF_Tiles:
  .incbin "data/sprite_main/ui_gallery.4bpp"
