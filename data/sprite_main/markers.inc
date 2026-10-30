File82F1_Header:
  .2byte 762 @ palStart
  .2byte 15 @ metaspriteCount
  .2byte 1 @ animationCount
  .2byte 112 @ subspriteCount
  .2byte 3 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 332 @ offsetToAnims
  .4byte 340 @ offsetToSubsprites
  .4byte 1236 @ offsetToCmds
  .4byte 1248 @ offsetToTiles

File82F1_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xE414, File82F1_Obj_0,     7,          -65,  -47,   39,   35
  pose 0xE41A, File82F1_Obj_7,     7,          -65,  -47,   39,   35
  pose 0xE1F4, File82F1_Obj_14,    7,          -65,  -45,   39,   35
  pose 0xE1FA, File82F1_Obj_21,    7,          -65,  -45,   39,   35
  pose 0x7C20, File82F1_Obj_28,    5,          -62,  -48,   34,   35
  pose 0x7C26, File82F1_Obj_33,    5,          -62,  -48,   34,   35
  pose 0x7A00, File82F1_Obj_38,    5,          -62,  -45,   34,   35
  pose 0x7A06, File82F1_Obj_43,    5,          -62,  -45,   34,   35
  pose 0xB71A, File82F1_Obj_48,    1,          -16,  -16,   16,   16
  pose 0xB71B, File82F1_Obj_49,    1,          -16,  -16,   16,   16
  pose 0xB71C, File82F1_Obj_50,    1,          -16,  -16,   16,   16
  pose 0xD4CB, File82F1_Obj_51,    6,            0,    0,  165,  112
  pose 0x4BD5, File82F1_Obj_57,    19,           0,    0,  219,  120
  pose 0x3D8B, File82F1_Obj_76,    22,          -2,    0,  222,  120
  pose 0x0F4B, File82F1_Obj_98,    14,          -8,    0,  224,  104

File82F1_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x4DE8, File82F1_Cmd_0,     3

1:
File82F1_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File82F1_Obj_0:
    subsprite OAM_SIZE_16x16,  -25,  -31,   60,    0
    subsprite OAM_SIZE_32x16,  -33,  -13,    8,    5
    subsprite OAM_SIZE_32x8,   -33,    3,   40,    5
    subsprite OAM_SIZE_32x16,   -1,  -13,   12,    5
    subsprite OAM_SIZE_32x8,    -1,    3,   44,    5
    subsprite OAM_SIZE_8x8,     31,    3,   90,    5
    subsprite OAM_SIZE_8x16,    31,  -13,   58,    5
  File82F1_Obj_7:
    subsprite OAM_SIZE_16x16,   16,  -31,   60,    0, xflip=1
    subsprite OAM_SIZE_32x8,   -33,    3,   40,    5
    subsprite OAM_SIZE_32x8,    -1,    3,   44,    5
    subsprite OAM_SIZE_8x8,     31,    3,   90,    5
    subsprite OAM_SIZE_32x16,  -33,  -13,    8,    5
    subsprite OAM_SIZE_32x16,   -1,  -13,   12,    5
    subsprite OAM_SIZE_8x16,    31,  -13,   58,    5
  File82F1_Obj_14:
    subsprite OAM_SIZE_16x16,  -25,   12,   60,    0, yflip=1
    subsprite OAM_SIZE_32x8,   -33,    3,   40,    5
    subsprite OAM_SIZE_32x8,    -1,    3,   44,    5
    subsprite OAM_SIZE_8x8,     31,    3,   90,    5
    subsprite OAM_SIZE_32x16,  -33,  -13,    8,    5
    subsprite OAM_SIZE_32x16,   -1,  -13,   12,    5
    subsprite OAM_SIZE_8x16,    31,  -13,   58,    5
  File82F1_Obj_21:
    subsprite OAM_SIZE_16x16,   15,   12,   60,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x8,   -33,    3,   40,    5
    subsprite OAM_SIZE_32x8,    -1,    3,   44,    5
    subsprite OAM_SIZE_8x8,     31,    3,   90,    5
    subsprite OAM_SIZE_32x16,  -33,  -13,    8,    5
    subsprite OAM_SIZE_32x16,   -1,  -13,   12,    5
    subsprite OAM_SIZE_8x16,    31,  -13,   58,    5
  File82F1_Obj_28:
    subsprite OAM_SIZE_16x16,  -22,  -32,   60,    0
    subsprite OAM_SIZE_32x16,  -30,  -13,    0,    5
    subsprite OAM_SIZE_32x16,    2,  -13,    4,    5
    subsprite OAM_SIZE_32x8,   -30,    3,   32,    5
    subsprite OAM_SIZE_32x8,     2,    3,   36,    5
  File82F1_Obj_33:
    subsprite OAM_SIZE_16x16,   10,  -32,   60,    0, xflip=1
    subsprite OAM_SIZE_32x8,   -30,    3,   32,    5
    subsprite OAM_SIZE_32x8,     2,    3,   36,    5
    subsprite OAM_SIZE_32x16,  -30,  -13,    0,    5
    subsprite OAM_SIZE_32x16,    2,  -13,    4,    5
  File82F1_Obj_38:
    subsprite OAM_SIZE_16x16,  -24,   13,   60,    0, yflip=1
    subsprite OAM_SIZE_32x8,   -30,    3,   32,    5
    subsprite OAM_SIZE_32x8,     2,    3,   36,    5
    subsprite OAM_SIZE_32x16,  -30,  -13,    0,    5
    subsprite OAM_SIZE_32x16,    2,  -13,    4,    5
  File82F1_Obj_43:
    subsprite OAM_SIZE_16x16,    8,   13,   60,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x8,   -30,    3,   32,    5
    subsprite OAM_SIZE_32x8,     2,    3,   36,    5
    subsprite OAM_SIZE_32x16,  -30,  -13,    0,    5
    subsprite OAM_SIZE_32x16,    2,  -13,    4,    5
  File82F1_Obj_48:
    subsprite OAM_SIZE_16x16,    0,    0,   62,    0
  File82F1_Obj_49:
    subsprite OAM_SIZE_16x16,    0,    0,   94,    0
  File82F1_Obj_50:
    subsprite OAM_SIZE_16x16,    0,    0,  126,    0
  File82F1_Obj_51:
    subsprite OAM_SIZE_32x16,   85,   64,   48,    1
    subsprite OAM_SIZE_32x16,  117,   64,   52,    1
    subsprite OAM_SIZE_16x16,  149,   64,   56,    1
    subsprite OAM_SIZE_32x8,    85,   80,   80,    1
    subsprite OAM_SIZE_32x8,   117,   80,   84,    1
    subsprite OAM_SIZE_16x8,   149,   80,   88,    1
  File82F1_Obj_57:
    subsprite OAM_SIZE_32x16,   51,   72,  192,    2
    subsprite OAM_SIZE_32x16,   83,   72,  196,    2
    subsprite OAM_SIZE_32x8,    51,   88,  224,    2
    subsprite OAM_SIZE_32x8,    83,   88,  228,    2
    subsprite OAM_SIZE_32x16,  115,   72,  200,    2
    subsprite OAM_SIZE_32x8,   115,   88,  232,    2
    subsprite OAM_SIZE_32x16,  147,   72,  204,    2
    subsprite OAM_SIZE_32x8,   147,   88,  236,    2
    subsprite OAM_SIZE_32x16,  179,   72,   96,    2
    subsprite OAM_SIZE_32x8,   179,   88,  128,    2
    subsprite OAM_SIZE_8x16,   211,   72,  100,    2
    subsprite OAM_SIZE_32x16,   35,   48,  145,    2
    subsprite OAM_SIZE_32x8,    35,   64,  177,    2
    subsprite OAM_SIZE_32x16,   67,   48,  149,    2
    subsprite OAM_SIZE_32x8,    67,   64,  181,    2
    subsprite OAM_SIZE_32x16,   99,   48,  153,    2
    subsprite OAM_SIZE_32x8,    99,   64,  185,    2
    subsprite OAM_SIZE_8x16,   131,   48,  157,    2
    subsprite OAM_SIZE_8x8,    131,   64,  189,    2
  File82F1_Obj_76:
    subsprite OAM_SIZE_32x16,   30,   48,  102,    2
    subsprite OAM_SIZE_32x16,   62,   48,  106,    2
    subsprite OAM_SIZE_32x8,    62,   64,  138,    2
    subsprite OAM_SIZE_32x8,    30,   64,  134,    2
    subsprite OAM_SIZE_32x16,  166,   48,  265,    2
    subsprite OAM_SIZE_32x16,  134,   48,  261,    2
    subsprite OAM_SIZE_32x16,  102,   48,  257,    2
    subsprite OAM_SIZE_8x16,    94,   48,  256,    2
    subsprite OAM_SIZE_32x8,   102,   64,  289,    2
    subsprite OAM_SIZE_32x8,   134,   64,  293,    2
    subsprite OAM_SIZE_32x8,   166,   64,  297,    2
    subsprite OAM_SIZE_32x8,    54,   88,  224,    2
    subsprite OAM_SIZE_32x8,    86,   88,  228,    2
    subsprite OAM_SIZE_32x8,   118,   88,  232,    2
    subsprite OAM_SIZE_32x8,   150,   88,  236,    2
    subsprite OAM_SIZE_32x8,   182,   88,  128,    2
    subsprite OAM_SIZE_32x16,   54,   72,  192,    2
    subsprite OAM_SIZE_32x16,   86,   72,  196,    2
    subsprite OAM_SIZE_32x16,  118,   72,  200,    2
    subsprite OAM_SIZE_32x16,  150,   72,  204,    2
    subsprite OAM_SIZE_32x16,  182,   72,   96,    2
    subsprite OAM_SIZE_8x16,   214,   72,  100,    2
  File82F1_Obj_98:
    subsprite OAM_SIZE_32x16,   24,   56,  304,    4
    subsprite OAM_SIZE_32x16,   56,   56,  308,    4
    subsprite OAM_SIZE_32x16,   88,   56,  312,    4
    subsprite OAM_SIZE_32x8,    24,   72,  336,    4
    subsprite OAM_SIZE_32x8,    56,   72,  340,    4
    subsprite OAM_SIZE_32x8,    88,   72,  344,    4
    subsprite OAM_SIZE_32x16,  192,   56,  360,    4
    subsprite OAM_SIZE_32x8,   192,   72,  392,    4
    subsprite OAM_SIZE_32x16,  160,   56,  356,    4
    subsprite OAM_SIZE_32x8,   160,   72,  388,    4
    subsprite OAM_SIZE_32x16,  128,   56,  352,    4
    subsprite OAM_SIZE_32x8,   128,   72,  384,    4
    subsprite OAM_SIZE_8x16,   120,   56,  316,    4
    subsprite OAM_SIZE_8x8,    120,   72,  348,    4

2:
File82F1_Cmds:
  File82F1_Cmd_0:
    animcmd   8,  11
    animcmd   9,  11
    animcmd  10,  11

File82F1_Tiles:
  .incbin "data/sprite_main/markers.4bpp"
