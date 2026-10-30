FileE04E_Header:
  .2byte 670 @ palStart
  .2byte 34 @ metaspriteCount
  .2byte 16 @ animationCount
  .2byte 308 @ subspriteCount
  .2byte 34 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 712 @ offsetToAnims
  .4byte 840 @ offsetToSubsprites
  .4byte 3304 @ offsetToCmds
  .4byte 3440 @ offsetToTiles

FileE04E_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0xF579, FileE04E_Obj_0,    8,          -24,  -50,   12,   17
  pose 0xF599, FileE04E_Obj_8,    7,          -24,  -50,    9,   16
  pose 0xF5B9, FileE04E_Obj_15,   6,          -28,  -49,   10,   18
  pose 0xF5D9, FileE04E_Obj_21,   5,          -24,  -48,   10,   16
  pose 0xF5F9, FileE04E_Obj_26,   6,          -24,  -47,   10,   16
  pose 0xF3A9, FileE04E_Obj_32,   7,          -24,  -51,   14,    5
  pose 0xF3AA, FileE04E_Obj_39,   5,          -24,  -50,   10,    2
  pose 0xF3AB, FileE04E_Obj_44,   6,          -24,  -51,   10,    9
  pose 0xF3AC, FileE04E_Obj_50,   6,          -24,  -50,   11,    2
  pose 0xF3E9, FileE04E_Obj_56,   5,          -23,  -47,   11,   15
  pose 0xF3EA, FileE04E_Obj_61,   5,          -24,  -46,   11,    2
  pose 0xF3EB, FileE04E_Obj_66,   6,          -23,  -47,   11,   16
  pose 0xF3EC, FileE04E_Obj_72,   6,          -23,  -46,   11,   14
  pose 0x2ED2, FileE04E_Obj_78,   10,         -24,  -54,   10,   17
  pose 0x2EF2, FileE04E_Obj_88,   9,          -24,  -54,   11,   16
  pose 0x2F12, FileE04E_Obj_97,   9,          -24,  -54,   12,   18
  pose 0x2F32, FileE04E_Obj_106,  11,         -24,  -54,   11,   16
  pose 0x2F52, FileE04E_Obj_117,  11,         -25,  -51,   10,   16
  pose 0x35C2, FileE04E_Obj_128,  10,         -23,  -54,   12,    8
  pose 0x35C3, FileE04E_Obj_138,  9,          -23,  -55,   12,    7
  pose 0x35C4, FileE04E_Obj_147,  8,          -23,  -54,   12,    8
  pose 0x35C5, FileE04E_Obj_155,  10,         -23,  -55,   12,   15
  pose 0x2D02, FileE04E_Obj_165,  10,         -23,  -54,   12,    8
  pose 0x2D03, FileE04E_Obj_175,  10,         -23,  -53,   13,    9
  pose 0x2D04, FileE04E_Obj_185,  8,          -23,  -54,   12,    8
  pose 0x2D05, FileE04E_Obj_193,  11,         -23,  -53,   13,   15
  pose 0x3602, FileE04E_Obj_204,  12,         -24,  -53,   12,   14
  pose 0x3603, FileE04E_Obj_216,  13,         -24,  -54,   12,   14
  pose 0x3604, FileE04E_Obj_229,  14,         -24,  -53,   18,   17
  pose 0x3605, FileE04E_Obj_243,  13,         -24,  -54,   12,   14
  pose 0x2D42, FileE04E_Obj_256,  12,         -24,  -52,   12,   14
  pose 0x2D43, FileE04E_Obj_268,  13,         -24,  -51,   13,   14
  pose 0x2D44, FileE04E_Obj_281,  14,         -24,  -52,   18,   17
  pose 0x2D45, FileE04E_Obj_295,  13,         -24,  -51,   13,   14

FileE04E_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xB17A, FileE04E_Cmd_0,  1
  animation 0xB19A, FileE04E_Cmd_1,  1
  animation 0xB1BA, FileE04E_Cmd_2,  1
  animation 0xB1DA, FileE04E_Cmd_3,  1
  animation 0xB1FA, FileE04E_Cmd_4,  1
  animation 0x2FB1, FileE04E_Cmd_5,  4
  animation 0x2FF1, FileE04E_Cmd_9,  4
  animation 0xEAD2, FileE04E_Cmd_13, 1
  animation 0xEAF2, FileE04E_Cmd_14, 1
  animation 0xEB12, FileE04E_Cmd_15, 1
  animation 0xEB32, FileE04E_Cmd_16, 1
  animation 0xEB52, FileE04E_Cmd_17, 1
  animation 0x71C8, FileE04E_Cmd_18, 4
  animation 0x7208, FileE04E_Cmd_22, 4
  animation 0x6909, FileE04E_Cmd_26, 4
  animation 0x6949, FileE04E_Cmd_30, 4

1:
FileE04E_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE04E_Obj_0:
    subsprite OAM_SIZE_16x16,   -8,  -15,   64,    0
    subsprite OAM_SIZE_16x8,    -8,    1,   96,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   32,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,   -10,  -22,   26,    0
    subsprite OAM_SIZE_8x8,     -2,  -14,   43,    0
    subsprite OAM_SIZE_8x16,     4,  -22,   59,    0
    subsprite OAM_SIZE_8x8,     -4,  -14,   74,    0
  FileE04E_Obj_8:
    subsprite OAM_SIZE_16x16,   -8,  -16,   66,    0
    subsprite OAM_SIZE_16x8,    -8,    0,   98,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   34,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   12,    0
    subsprite OAM_SIZE_8x16,    -1,  -22,   13,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,   58,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,    2,    0
  FileE04E_Obj_15:
    subsprite OAM_SIZE_16x16,   -7,  -14,   68,    0
    subsprite OAM_SIZE_16x8,    -7,    2,  100,    0
    subsprite OAM_SIZE_8x16,    -9,  -24,   45,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   46,    0
    subsprite OAM_SIZE_16x8,   -12,  -20,   10,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,    4,    0
  FileE04E_Obj_21:
    subsprite OAM_SIZE_16x16,   -6,  -16,   70,    0
    subsprite OAM_SIZE_16x8,    -6,    0,  102,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   38,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   14,    0
    subsprite OAM_SIZE_16x16,   -6,  -32,    6,    0
  FileE04E_Obj_26:
    subsprite OAM_SIZE_16x16,   -8,  -16,   72,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  104,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   40,    0
    subsprite OAM_SIZE_8x16,    -9,  -24,   44,    0
    subsprite OAM_SIZE_8x16,     2,  -24,   15,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,    8,    0
  FileE04E_Obj_32:
    subsprite OAM_SIZE_16x16,   -7,  -19,  164,    0
    subsprite OAM_SIZE_8x8,     -7,   -3,  108,    0
    subsprite OAM_SIZE_8x16,    -9,  -25,   78,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   76,    0
    subsprite OAM_SIZE_8x16,    -2,  -26,  120,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  155,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,    2,    0
  FileE04E_Obj_39:
    subsprite OAM_SIZE_16x16,   -8,  -14,  166,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,   79,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   76,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,    2,    0
    subsprite OAM_SIZE_8x16,     1,  -22,  121,    0
  FileE04E_Obj_44:
    subsprite OAM_SIZE_16x16,   -8,  -15,  168,    0
    subsprite OAM_SIZE_8x8,     -8,    1,  109,    0
    subsprite OAM_SIZE_8x16,    -6,  -26,  123,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   76,    0
    subsprite OAM_SIZE_8x16,    -1,  -22,  122,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,    2,    0
  FileE04E_Obj_50:
    subsprite OAM_SIZE_16x16,   -7,  -14,  170,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,   79,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   76,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  152,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  154,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,    2,    0
  FileE04E_Obj_56:
    subsprite OAM_SIZE_16x16,   -7,  -17,  116,    0
    subsprite OAM_SIZE_16x8,    -7,   -1,  148,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,   90,    0
    subsprite OAM_SIZE_16x16,   -5,  -31,    6,    0
    subsprite OAM_SIZE_8x16,    -5,  -21,  160,    0
  FileE04E_Obj_61:
    subsprite OAM_SIZE_16x16,   -8,  -14,  112,    0
    subsprite OAM_SIZE_8x8,      2,  -16,  144,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,   90,    0
    subsprite OAM_SIZE_8x16,    -7,  -18,  161,    0
    subsprite OAM_SIZE_16x16,   -5,  -30,    6,    0
  FileE04E_Obj_66:
    subsprite OAM_SIZE_16x16,   -7,  -16,  114,    0
    subsprite OAM_SIZE_16x8,    -7,    0,  146,    0
    subsprite OAM_SIZE_8x8,      2,  -17,  145,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -22,  162,    0
    subsprite OAM_SIZE_16x16,   -5,  -31,    6,    0
  FileE04E_Obj_72:
    subsprite OAM_SIZE_16x16,   -7,  -18,  118,    0
    subsprite OAM_SIZE_16x8,    -7,   -2,  150,    0
    subsprite OAM_SIZE_8x8,      1,  -16,   27,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,   90,    0
    subsprite OAM_SIZE_8x16,    -6,  -20,  163,    0
    subsprite OAM_SIZE_16x16,   -5,  -30,    6,    0
  FileE04E_Obj_78:
    subsprite OAM_SIZE_16x16,   -8,  -36,  192,    0
    subsprite OAM_SIZE_16x16,   -8,  -15,   64,    0
    subsprite OAM_SIZE_16x8,    -8,    1,   96,    0
    subsprite OAM_SIZE_8x16,   -11,  -24,  203,    0
    subsprite OAM_SIZE_8x8,    -11,   -8,  235,    0
    subsprite OAM_SIZE_8x16,     2,  -25,  157,    0
    subsprite OAM_SIZE_8x8,      2,   -9,  110,    0
    subsprite OAM_SIZE_16x8,    -8,   -8,  221,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  189,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,  224,    0
  FileE04E_Obj_88:
    subsprite OAM_SIZE_16x16,   -8,  -16,   66,    0
    subsprite OAM_SIZE_16x8,    -8,    0,   98,    0
    subsprite OAM_SIZE_8x16,    -8,  -26,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  126,    0
    subsprite OAM_SIZE_16x8,    -8,   -8,  158,    0
    subsprite OAM_SIZE_16x16,   -5,  -33,  194,    0
    subsprite OAM_SIZE_8x8,      3,  -17,  202,    0
    subsprite OAM_SIZE_16x16,   -5,  -38,  226,    0
    subsprite OAM_SIZE_8x16,    -1,  -20,  124,    0
  FileE04E_Obj_97:
    subsprite OAM_SIZE_8x16,     2,  -16,  207,    0
    subsprite OAM_SIZE_16x8,    -7,    2,  100,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,   68,    0
    subsprite OAM_SIZE_16x16,   -4,  -33,  196,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  256,    0
    subsprite OAM_SIZE_16x8,    -8,   -9,  288,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  125,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  228,    0
    subsprite OAM_SIZE_8x8,      4,  -18,  234,    0
  FileE04E_Obj_106:
    subsprite OAM_SIZE_8x16,     3,  -20,  239,    0
    subsprite OAM_SIZE_8x8,      3,   -4,  111,    0
    subsprite OAM_SIZE_16x16,   -6,  -16,   70,    0
    subsprite OAM_SIZE_16x8,    -6,    0,  102,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   38,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  274,    0
    subsprite OAM_SIZE_16x8,    -8,  -24,  258,    0
    subsprite OAM_SIZE_8x16,    -8,  -20,  237,    0
    subsprite OAM_SIZE_16x16,   -5,  -32,  198,    0
    subsprite OAM_SIZE_8x8,      3,  -16,  218,    0
    subsprite OAM_SIZE_16x16,   -5,  -38,  230,    0
  FileE04E_Obj_117:
    subsprite OAM_SIZE_16x16,   -8,  -16,   72,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  104,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,   40,    0
    subsprite OAM_SIZE_16x8,    -8,   -6,  292,    0
    subsprite OAM_SIZE_8x32,     2,  -21,  204,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,  260,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,  292,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  250,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  200,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,  238,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,  232,    0
  FileE04E_Obj_128:
    subsprite OAM_SIZE_8x8,     -7,  -23,  404,    0
    subsprite OAM_SIZE_8x16,    -3,  -16,  336,    0
    subsprite OAM_SIZE_8x8,     -3,    0,  368,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  126,    0
    subsprite OAM_SIZE_16x16,   -4,  -33,  194,    0
    subsprite OAM_SIZE_8x8,      4,  -17,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  226,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  158,    0
    subsprite OAM_SIZE_8x16,     1,  -21,  384,    0
    subsprite OAM_SIZE_8x8,     -7,  -30,  191,    0
  FileE04E_Obj_138:
    subsprite OAM_SIZE_8x8,     -7,  -23,  405,    0
    subsprite OAM_SIZE_8x8,      4,  -18,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -34,  194,    0
    subsprite OAM_SIZE_16x16,   -4,  -39,  226,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  337,    0
    subsprite OAM_SIZE_8x8,     -7,  -31,  389,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -9,  158,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  385,    0
  FileE04E_Obj_147:
    subsprite OAM_SIZE_16x16,   -5,  -12,  339,    0
    subsprite OAM_SIZE_8x8,     -6,  -23,  404,    0
    subsprite OAM_SIZE_8x8,      4,  -17,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -33,  194,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  226,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  158,    0
    subsprite OAM_SIZE_8x16,    -1,  -21,  386,    0
  FileE04E_Obj_155:
    subsprite OAM_SIZE_16x16,   -7,  -17,  341,    0
    subsprite OAM_SIZE_16x8,    -7,   -1,  373,    0
    subsprite OAM_SIZE_8x8,     -7,  -23,  405,    0
    subsprite OAM_SIZE_8x8,     -7,  -31,  389,    0
    subsprite OAM_SIZE_8x8,      4,  -18,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -34,  194,    0
    subsprite OAM_SIZE_16x16,   -4,  -39,  226,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -9,  158,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  385,    0
  FileE04E_Obj_165:
    subsprite OAM_SIZE_8x8,     -7,  -23,  404,    0
    subsprite OAM_SIZE_8x16,    -3,  -16,  336,    0
    subsprite OAM_SIZE_8x8,     -3,    0,  368,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  126,    0
    subsprite OAM_SIZE_16x16,   -4,  -33,  194,    0
    subsprite OAM_SIZE_8x8,      4,  -17,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  226,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  158,    0
    subsprite OAM_SIZE_8x16,     1,  -21,  384,    0
    subsprite OAM_SIZE_8x8,     -7,  -30,  191,    0
  FileE04E_Obj_175:
    subsprite OAM_SIZE_16x16,   -7,  -14,  337,    0
    subsprite OAM_SIZE_8x8,     -7,  -21,  405,    0
    subsprite OAM_SIZE_8x8,      4,  -16,  202,    0
    subsprite OAM_SIZE_16x16,   -3,  -32,  194,    0
    subsprite OAM_SIZE_16x16,   -3,  -37,  226,    0
    subsprite OAM_SIZE_8x8,     -7,  -29,  389,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  158,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  385,    0
    subsprite OAM_SIZE_8x8,     -6,  -29,  191,    0
  FileE04E_Obj_185:
    subsprite OAM_SIZE_16x16,   -5,  -12,  339,    0
    subsprite OAM_SIZE_8x8,     -6,  -23,  404,    0
    subsprite OAM_SIZE_8x8,      4,  -17,  202,    0
    subsprite OAM_SIZE_16x16,   -4,  -33,  194,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  226,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  158,    0
    subsprite OAM_SIZE_8x16,    -1,  -21,  386,    0
  FileE04E_Obj_193:
    subsprite OAM_SIZE_16x16,   -7,  -17,  341,    0
    subsprite OAM_SIZE_16x8,    -7,   -1,  373,    0
    subsprite OAM_SIZE_8x8,     -7,  -21,  405,    0
    subsprite OAM_SIZE_8x8,     -7,  -29,  389,    0
    subsprite OAM_SIZE_8x8,      4,  -16,  202,    0
    subsprite OAM_SIZE_16x16,   -3,  -32,  194,    0
    subsprite OAM_SIZE_16x16,   -3,  -37,  226,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  126,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  158,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  385,    0
    subsprite OAM_SIZE_8x8,     -6,  -29,  191,    0
  FileE04E_Obj_204:
    subsprite OAM_SIZE_8x16,     2,  -25,  307,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  262,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,  294,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,   38,    0
    subsprite OAM_SIZE_8x16,     3,  -18,  312,    0
    subsprite OAM_SIZE_8x8,      3,   -2,  344,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  290,    0
    subsprite OAM_SIZE_16x16,   -4,  -31,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -15,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -37,  230,    0
    subsprite OAM_SIZE_8x16,    -7,  -20,  304,    0
  FileE04E_Obj_216:
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  264,    0
    subsprite OAM_SIZE_8x16,     3,  -26,  308,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,  296,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,   38,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  290,    0
    subsprite OAM_SIZE_8x16,    -8,  -20,  305,    0
    subsprite OAM_SIZE_8x16,     4,  -19,  312,    0
    subsprite OAM_SIZE_8x8,      4,   -3,  344,    0
    subsprite OAM_SIZE_16x16,   -4,  -32,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -16,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  230,    0
  FileE04E_Obj_229:
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15,  266,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  309,    0
    subsprite OAM_SIZE_8x8,     10,  -16,  326,    0
    subsprite OAM_SIZE_8x16,     5,  -16,  312,    0
    subsprite OAM_SIZE_8x8,      5,    0,  344,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  298,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,   38,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  290,    0
    subsprite OAM_SIZE_16x16,   -4,  -31,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -15,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -37,  230,    0
    subsprite OAM_SIZE_8x16,    -8,  -20,  306,    0
  FileE04E_Obj_243:
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  268,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,  300,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,   38,    0
    subsprite OAM_SIZE_8x16,     3,  -25,  311,    0
    subsprite OAM_SIZE_8x16,     4,  -17,  312,    0
    subsprite OAM_SIZE_8x8,      4,   -1,  344,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -8,  290,    0
    subsprite OAM_SIZE_8x16,    -8,  -20,  305,    0
    subsprite OAM_SIZE_16x16,   -4,  -32,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -16,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -38,  230,    0
  FileE04E_Obj_256:
    subsprite OAM_SIZE_8x16,     2,  -25,  307,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  262,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,  294,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,   38,    0
    subsprite OAM_SIZE_8x16,     3,  -18,  312,    0
    subsprite OAM_SIZE_8x8,      3,   -2,  344,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  290,    0
    subsprite OAM_SIZE_16x16,   -4,  -30,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -14,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -36,  230,    0
    subsprite OAM_SIZE_8x16,    -7,  -20,  304,    0
  FileE04E_Obj_268:
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  264,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,  296,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  308,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,   38,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -6,  290,    0
    subsprite OAM_SIZE_8x16,    -8,  -18,  305,    0
    subsprite OAM_SIZE_8x16,     4,  -19,  312,    0
    subsprite OAM_SIZE_8x8,      4,   -3,  344,    0
    subsprite OAM_SIZE_16x16,   -3,  -29,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -14,  218,    0
    subsprite OAM_SIZE_16x16,   -3,  -35,  230,    0
  FileE04E_Obj_281:
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15,  266,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  309,    0
    subsprite OAM_SIZE_8x8,     10,  -16,  326,    0
    subsprite OAM_SIZE_8x16,     5,  -16,  312,    0
    subsprite OAM_SIZE_8x8,      5,    0,  344,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  298,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,   38,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  258,    0
    subsprite OAM_SIZE_16x8,    -7,   -7,  290,    0
    subsprite OAM_SIZE_16x16,   -4,  -30,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -14,  218,    0
    subsprite OAM_SIZE_16x16,   -4,  -36,  230,    0
    subsprite OAM_SIZE_8x16,    -8,  -20,  306,    0
  FileE04E_Obj_295:
    subsprite OAM_SIZE_16x8,    -8,   -2,  300,    0
    subsprite OAM_SIZE_8x16,    -1,  -13,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,  268,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,   38,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  311,    0
    subsprite OAM_SIZE_16x8,    -7,   -6,  290,    0
    subsprite OAM_SIZE_8x16,     4,  -17,  312,    0
    subsprite OAM_SIZE_8x8,      4,   -1,  344,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  258,    0
    subsprite OAM_SIZE_8x16,    -8,  -18,  305,    0
    subsprite OAM_SIZE_16x16,   -3,  -29,  198,    0
    subsprite OAM_SIZE_8x8,      4,  -14,  218,    0
    subsprite OAM_SIZE_16x16,   -3,  -35,  230,    0

2:
FileE04E_Cmds:
  FileE04E_Cmd_0:
    animcmd   0,   1
  FileE04E_Cmd_1:
    animcmd   1,   1
  FileE04E_Cmd_2:
    animcmd   2,   1
  FileE04E_Cmd_3:
    animcmd   3,   1
  FileE04E_Cmd_4:
    animcmd   4,   1
  FileE04E_Cmd_5:
    animcmd   5,   9
    animcmd   6,  11
    animcmd   7,   9
    animcmd   8,  11
  FileE04E_Cmd_9:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileE04E_Cmd_13:
    animcmd  13,   1
  FileE04E_Cmd_14:
    animcmd  14,   1
  FileE04E_Cmd_15:
    animcmd  15,   1
  FileE04E_Cmd_16:
    animcmd  16,   1
  FileE04E_Cmd_17:
    animcmd  17,   1
  FileE04E_Cmd_18:
    animcmd  18,  13
    animcmd  19,  11
    animcmd  20,  13
    animcmd  21,  11
  FileE04E_Cmd_22:
    animcmd  26,  13
    animcmd  27,  11
    animcmd  28,  13
    animcmd  29,  11
  FileE04E_Cmd_26:
    animcmd  22,   9
    animcmd  23,   9
    animcmd  24,   9
    animcmd  25,   9
  FileE04E_Cmd_30:
    animcmd  30,   9
    animcmd  31,   9
    animcmd  32,   9
    animcmd  33,   9

FileE04E_Tiles:
  .incbin "data/sprite_main/ennio_luis.4bpp"
