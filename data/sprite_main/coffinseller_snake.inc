FileE03E_Header:
  .2byte 668 @ palStart
  .2byte 26 @ metaspriteCount
  .2byte 14 @ animationCount
  .2byte 216 @ subspriteCount
  .2byte 26 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 552 @ offsetToAnims
  .4byte 664 @ offsetToSubsprites
  .4byte 2392 @ offsetToCmds
  .4byte 2496 @ offsetToTiles

FileE03E_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0xF571, FileE03E_Obj_0,    8,          -24,  -53,   12,   13
  pose 0xF591, FileE03E_Obj_8,    7,          -24,  -53,    9,   15
  pose 0xF5B1, FileE03E_Obj_15,   6,          -25,  -52,    8,   15
  pose 0xF5D1, FileE03E_Obj_21,   8,          -25,  -53,   10,   15
  pose 0xF5F1, FileE03E_Obj_29,   9,          -24,  -52,   12,   14
  pose 0x2DCA, FileE03E_Obj_38,   10,         -24,  -53,   12,   13
  pose 0x2DEA, FileE03E_Obj_48,   8,          -24,  -52,    8,   15
  pose 0x2E0A, FileE03E_Obj_56,   7,          -25,  -53,    9,   15
  pose 0x2E2A, FileE03E_Obj_63,   9,          -25,  -52,   10,   15
  pose 0x2E4A, FileE03E_Obj_72,   12,         -24,  -53,   18,   14
  pose 0x34BA, FileE03E_Obj_84,   8,          -25,  -52,   13,   15
  pose 0x34BB, FileE03E_Obj_92,   8,          -24,  -53,    9,   12
  pose 0x34BC, FileE03E_Obj_100,  9,          -24,  -52,   16,    8
  pose 0x34BD, FileE03E_Obj_109,  8,          -23,  -53,    9,   13
  pose 0x34FA, FileE03E_Obj_117,  9,          -24,  -51,    9,   16
  pose 0x34FB, FileE03E_Obj_126,  11,         -24,  -52,   10,   15
  pose 0x34FC, FileE03E_Obj_137,  11,         -24,  -51,   11,   18
  pose 0x34FD, FileE03E_Obj_148,  11,         -25,  -52,   10,   15
  pose 0x2BFA, FileE03E_Obj_159,  5,          -31,  -53,   18,    0
  pose 0x2BFB, FileE03E_Obj_164,  7,          -29,  -52,   17,    0
  pose 0x2BFC, FileE03E_Obj_171,  5,          -24,  -53,   10,    7
  pose 0x2BFD, FileE03E_Obj_176,  8,          -29,  -52,   17,    0
  pose 0x2C3A, FileE03E_Obj_184,  8,          -24,  -50,   16,    0
  pose 0x2C3B, FileE03E_Obj_192,  8,          -24,  -50,   16,    6
  pose 0x2C3C, FileE03E_Obj_200,  7,          -31,  -50,   17,    0
  pose 0x2C3D, FileE03E_Obj_207,  9,          -24,  -50,   16,    1

FileE03E_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xB172, FileE03E_Cmd_0,  1
  animation 0xB192, FileE03E_Cmd_1,  1
  animation 0xB1B2, FileE03E_Cmd_2,  1
  animation 0xB1D2, FileE03E_Cmd_3,  1
  animation 0xB1F2, FileE03E_Cmd_4,  1
  animation 0xE9CA, FileE03E_Cmd_5,  1
  animation 0xE9EA, FileE03E_Cmd_6,  1
  animation 0xEA0A, FileE03E_Cmd_7,  1
  animation 0xEA2A, FileE03E_Cmd_8,  1
  animation 0xEA4A, FileE03E_Cmd_9,  1
  animation 0x70C0, FileE03E_Cmd_10, 4
  animation 0x7100, FileE03E_Cmd_14, 4
  animation 0x6801, FileE03E_Cmd_18, 4
  animation 0x6841, FileE03E_Cmd_22, 4

1:
FileE03E_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE03E_Obj_0:
    subsprite OAM_SIZE_16x16,   -8,  -19,   40,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,   88,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    8,    0
    subsprite OAM_SIZE_8x16,   -12,  -30,   14,    0
    subsprite OAM_SIZE_8x8,    -12,  -14,   46,    0
    subsprite OAM_SIZE_8x16,     4,  -26,   15,    0
    subsprite OAM_SIZE_8x8,      4,  -10,   47,    0
  FileE03E_Obj_8:
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,   38,    0
    subsprite OAM_SIZE_16x8,    -8,   -1,   70,    0
    subsprite OAM_SIZE_8x16,   -12,  -28,   59,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   86,    0
    subsprite OAM_SIZE_8x16,     0,  -24,   11,    0
    subsprite OAM_SIZE_8x8,      0,   -8,   43,    0
  FileE03E_Obj_15:
    subsprite OAM_SIZE_16x16,   -8,  -17,   36,    0
    subsprite OAM_SIZE_16x8,    -8,   -1,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,   84,    0
    subsprite OAM_SIZE_8x16,    -7,  -22,  207,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  239,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    4,    0
  FileE03E_Obj_21:
    subsprite OAM_SIZE_16x16,   -6,  -17,   34,    0
    subsprite OAM_SIZE_16x8,    -6,   -1,   66,    0
    subsprite OAM_SIZE_8x16,     1,  -27,   58,    0
    subsprite OAM_SIZE_16x16,   -9,  -28,   82,    0
    subsprite OAM_SIZE_16x8,    -9,  -12,  114,    0
    subsprite OAM_SIZE_8x16,   -10,  -24,   10,    0
    subsprite OAM_SIZE_8x8,    -10,   -8,   42,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    2,    0
  FileE03E_Obj_29:
    subsprite OAM_SIZE_16x16,   -8,  -18,   32,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,   64,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,   80,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  112,    0
    subsprite OAM_SIZE_8x16,     4,  -30,   12,    0
    subsprite OAM_SIZE_8x8,      4,  -14,   44,    0
    subsprite OAM_SIZE_8x16,   -12,  -29,   13,    0
    subsprite OAM_SIZE_8x8,    -12,  -13,   45,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    0,    0
  FileE03E_Obj_38:
    subsprite OAM_SIZE_16x16,   -8,  -19,   40,    1
    subsprite OAM_SIZE_16x8,    -8,   -3,   72,    1
    subsprite OAM_SIZE_16x16,   -8,  -28,  164,    1
    subsprite OAM_SIZE_16x8,    -8,  -12,  196,    1
    subsprite OAM_SIZE_8x16,     4,  -26,  235,    1
    subsprite OAM_SIZE_8x8,      4,  -10,  254,    1
    subsprite OAM_SIZE_8x16,   -12,  -27,  234,    1
    subsprite OAM_SIZE_8x8,    -12,  -11,  253,    1
    subsprite OAM_SIZE_16x16,   -8,  -37,  192,    1
    subsprite OAM_SIZE_16x8,    -8,  -21,  194,    1
  FileE03E_Obj_48:
    subsprite OAM_SIZE_16x16,   -8,  -17,   38,    1
    subsprite OAM_SIZE_16x8,    -8,   -1,   70,    1
    subsprite OAM_SIZE_8x16,   -12,  -29,  225,    1
    subsprite OAM_SIZE_16x16,   -8,  -30,  138,    1
    subsprite OAM_SIZE_16x8,    -8,  -14,  170,    1
    subsprite OAM_SIZE_16x16,   -8,  -36,  162,    1
    subsprite OAM_SIZE_8x16,     0,  -28,  187,    1
    subsprite OAM_SIZE_8x8,      0,  -12,  219,    1
  FileE03E_Obj_56:
    subsprite OAM_SIZE_16x16,   -9,  -17,   36,    1
    subsprite OAM_SIZE_16x8,    -9,   -1,   68,    1
    subsprite OAM_SIZE_16x16,   -7,  -25,  120,    1
    subsprite OAM_SIZE_16x8,    -7,   -9,  152,    1
    subsprite OAM_SIZE_8x16,    -7,  -26,  186,    1
    subsprite OAM_SIZE_8x8,     -7,  -10,  218,    1
    subsprite OAM_SIZE_16x16,   -8,  -37,  160,    1
  FileE03E_Obj_63:
    subsprite OAM_SIZE_16x16,   -6,  -17,   34,    1
    subsprite OAM_SIZE_16x8,    -6,   -1,   66,    1
    subsprite OAM_SIZE_8x16,     0,  -29,  224,    1
    subsprite OAM_SIZE_16x16,   -9,  -28,   82,    1
    subsprite OAM_SIZE_16x16,   -8,  -30,  118,    1
    subsprite OAM_SIZE_16x8,    -8,  -14,  150,    1
    subsprite OAM_SIZE_16x16,   -8,  -36,  130,    1
    subsprite OAM_SIZE_8x16,   -10,  -28,  169,    1
    subsprite OAM_SIZE_8x8,    -10,  -12,  201,    1
  FileE03E_Obj_72:
    subsprite OAM_SIZE_16x16,   -8,  -18,   32,    1
    subsprite OAM_SIZE_16x8,    -8,   -2,   64,    1
    subsprite OAM_SIZE_16x16,   -8,  -32,   80,    1
    subsprite OAM_SIZE_16x8,    -8,  -16,  112,    1
    subsprite OAM_SIZE_16x16,   -8,  -26,  116,    1
    subsprite OAM_SIZE_16x8,    -8,  -10,  148,    1
    subsprite OAM_SIZE_8x16,   -12,  -27,  168,    1
    subsprite OAM_SIZE_8x8,    -12,  -11,  200,    1
    subsprite OAM_SIZE_8x16,     2,  -28,  210,    1
    subsprite OAM_SIZE_8x8,     10,  -20,  244,    1
    subsprite OAM_SIZE_8x8,      2,  -12,  242,    1
    subsprite OAM_SIZE_16x16,   -8,  -37,  128,    1
  FileE03E_Obj_84:
    subsprite OAM_SIZE_8x16,   -10,  -28,  256,    1
    subsprite OAM_SIZE_16x16,   -9,  -17,   62,    1
    subsprite OAM_SIZE_16x8,    -9,   -1,   94,    1
    subsprite OAM_SIZE_16x16,   -7,  -30,  138,    1
    subsprite OAM_SIZE_16x8,    -7,  -14,  170,    1
    subsprite OAM_SIZE_16x16,   -3,  -25,  211,    1
    subsprite OAM_SIZE_8x8,      5,   -9,  243,    1
    subsprite OAM_SIZE_16x16,   -7,  -36,  162,    1
  FileE03E_Obj_92:
    subsprite OAM_SIZE_8x16,   -10,  -30,  257,    1
    subsprite OAM_SIZE_16x16,   -8,  -20,   60,    1
    subsprite OAM_SIZE_16x8,    -8,   -4,   92,    1
    subsprite OAM_SIZE_16x16,   -7,  -31,  138,    1
    subsprite OAM_SIZE_16x8,    -7,  -15,  170,    1
    subsprite OAM_SIZE_8x16,     0,  -26,  213,    1
    subsprite OAM_SIZE_8x8,      0,  -10,  245,    1
    subsprite OAM_SIZE_16x16,   -7,  -37,  162,    1
  FileE03E_Obj_100:
    subsprite OAM_SIZE_8x16,    -9,  -32,  258,    1
    subsprite OAM_SIZE_16x16,   -8,  -16,  205,    1
    subsprite OAM_SIZE_8x8,     -8,    0,  238,    1
    subsprite OAM_SIZE_8x8,      8,   -8,  237,    1
    subsprite OAM_SIZE_16x16,   -7,  -30,  138,    1
    subsprite OAM_SIZE_16x8,    -7,  -14,  170,    1
    subsprite OAM_SIZE_8x16,    -1,  -25,  214,    1
    subsprite OAM_SIZE_8x8,     -1,   -9,  246,    1
    subsprite OAM_SIZE_16x16,   -7,  -36,  162,    1
  FileE03E_Obj_109:
    subsprite OAM_SIZE_16x16,   -7,  -19,  156,    1
    subsprite OAM_SIZE_8x16,    -9,  -29,  259,    1
    subsprite OAM_SIZE_16x8,    -7,   -3,  188,    1
    subsprite OAM_SIZE_16x16,   -7,  -31,  138,    1
    subsprite OAM_SIZE_16x8,    -7,  -15,  170,    1
    subsprite OAM_SIZE_8x16,     0,  -26,  215,    1
    subsprite OAM_SIZE_8x8,      0,  -10,  247,    1
    subsprite OAM_SIZE_16x16,   -7,  -37,  162,    1
  FileE03E_Obj_117:
    subsprite OAM_SIZE_8x16,     0,  -27,  260,    1
    subsprite OAM_SIZE_16x16,   -8,  -16,  158,    1
    subsprite OAM_SIZE_16x8,    -8,    0,  190,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,   82,    1
    subsprite OAM_SIZE_16x16,   -8,  -26,  166,    1
    subsprite OAM_SIZE_16x8,    -8,  -10,  198,    1
    subsprite OAM_SIZE_16x16,   -7,  -35,  130,    1
    subsprite OAM_SIZE_8x16,    -8,  -25,  216,    1
    subsprite OAM_SIZE_8x8,     -8,   -9,  248,    1
  FileE03E_Obj_126:
    subsprite OAM_SIZE_8x16,     2,  -26,  262,    1
    subsprite OAM_SIZE_8x8,      2,  -34,  255,    1
    subsprite OAM_SIZE_16x16,   -6,  -17,  108,    1
    subsprite OAM_SIZE_16x8,    -6,   -1,  140,    1
    subsprite OAM_SIZE_16x16,   -8,  -28,   82,    1
    subsprite OAM_SIZE_16x8,    -8,  -12,  114,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,  166,    1
    subsprite OAM_SIZE_16x8,    -8,  -11,  198,    1
    subsprite OAM_SIZE_16x16,   -7,  -36,  130,    1
    subsprite OAM_SIZE_8x16,    -9,  -19,  236,    1
    subsprite OAM_SIZE_8x8,     -9,  -27,  220,    1
  FileE03E_Obj_137:
    subsprite OAM_SIZE_8x16,     3,  -26,  261,    1
    subsprite OAM_SIZE_16x16,   -6,  -14,  110,    1
    subsprite OAM_SIZE_16x8,    -6,    2,  142,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,   82,    1
    subsprite OAM_SIZE_16x8,    -8,  -11,  114,    1
    subsprite OAM_SIZE_16x16,   -8,  -26,  166,    1
    subsprite OAM_SIZE_16x8,    -8,  -10,  198,    1
    subsprite OAM_SIZE_8x16,   -11,  -23,  217,    1
    subsprite OAM_SIZE_8x8,    -11,   -7,  249,    1
    subsprite OAM_SIZE_8x8,     -3,  -23,  204,    1
    subsprite OAM_SIZE_16x16,   -7,  -35,  130,    1
  FileE03E_Obj_148:
    subsprite OAM_SIZE_8x16,     2,  -26,  262,    1
    subsprite OAM_SIZE_8x8,      2,  -34,  255,    1
    subsprite OAM_SIZE_16x16,   -9,  -17,   90,    1
    subsprite OAM_SIZE_16x8,    -9,   -1,  122,    1
    subsprite OAM_SIZE_16x16,   -8,  -28,   82,    1
    subsprite OAM_SIZE_16x8,    -8,  -12,  114,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,  166,    1
    subsprite OAM_SIZE_16x8,    -8,  -11,  198,    1
    subsprite OAM_SIZE_8x16,    -9,  -27,  220,    1
    subsprite OAM_SIZE_8x8,     -9,  -11,  252,    1
    subsprite OAM_SIZE_16x16,   -7,  -36,  130,    1
  FileE03E_Obj_159:
    subsprite OAM_SIZE_16x16,  -15,  -30,  288,    1
    subsprite OAM_SIZE_16x32,   -8,  -26,  328,    1
    subsprite OAM_SIZE_16x32,   -8,  -34,  322,    1
    subsprite OAM_SIZE_16x16,    2,  -26,  294,    1
    subsprite OAM_SIZE_16x16,   -6,  -37,  263,    1
  FileE03E_Obj_164:
    subsprite OAM_SIZE_16x16,  -13,  -27,  290,    1
    subsprite OAM_SIZE_8x8,     -8,  -11,  320,    1
    subsprite OAM_SIZE_16x32,   -8,  -26,  330,    1
    subsprite OAM_SIZE_16x32,   -8,  -34,  324,    1
    subsprite OAM_SIZE_16x16,    1,  -24,  296,    1
    subsprite OAM_SIZE_8x8,      1,   -8,  321,    1
    subsprite OAM_SIZE_16x16,   -6,  -36,  265,    1
  FileE03E_Obj_171:
    subsprite OAM_SIZE_16x32,   -8,  -26,  300,    1
    subsprite OAM_SIZE_16x32,   -8,  -34,  326,    1
    subsprite OAM_SIZE_16x16,   -8,  -25,  298,    1
    subsprite OAM_SIZE_16x8,    -8,   -9,  336,    1
    subsprite OAM_SIZE_16x16,   -6,  -37,  263,    1
  FileE03E_Obj_176:
    subsprite OAM_SIZE_16x16,  -13,  -27,  290,    1
    subsprite OAM_SIZE_8x8,     -8,  -11,  320,    1
    subsprite OAM_SIZE_16x32,   -8,  -18,  302,    1
    subsprite OAM_SIZE_16x32,   -8,  -34,  324,    1
    subsprite OAM_SIZE_8x8,      1,   -8,  321,    1
    subsprite OAM_SIZE_16x16,    1,  -24,  296,    1
    subsprite OAM_SIZE_16x16,   -6,  -36,  265,    1
    subsprite OAM_SIZE_8x8,     -7,  -28,  394,    1
  FileE03E_Obj_184:
    subsprite OAM_SIZE_16x32,   -8,  -20,  416,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,  352,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,  364,    1
    subsprite OAM_SIZE_8x8,     -8,  -11,  271,    1
    subsprite OAM_SIZE_16x16,   -6,  -34,  267,    1
    subsprite OAM_SIZE_8x16,    -6,  -24,  387,    1
    subsprite OAM_SIZE_8x8,      2,  -16,  404,    1
    subsprite OAM_SIZE_8x8,      8,  -25,  410,    0
  FileE03E_Obj_192:
    subsprite OAM_SIZE_8x16,     1,  -26,  384,    1
    subsprite OAM_SIZE_16x32,   -8,  -20,  418,    1
    subsprite OAM_SIZE_16x16,   -8,  -26,  366,    1
    subsprite OAM_SIZE_16x8,    -8,  -10,  424,    1
    subsprite OAM_SIZE_8x16,    -9,  -23,  389,    1
    subsprite OAM_SIZE_8x8,     -9,   -7,  388,    1
    subsprite OAM_SIZE_16x16,   -6,  -34,  269,    1
    subsprite OAM_SIZE_8x8,      8,  -24,  410,    0
  FileE03E_Obj_200:
    subsprite OAM_SIZE_16x16,    1,  -28,  385,    1
    subsprite OAM_SIZE_16x32,   -8,  -21,  420,    1
    subsprite OAM_SIZE_8x8,     -8,  -11,  271,    1
    subsprite OAM_SIZE_16x16,   -8,  -27,  364,    1
    subsprite OAM_SIZE_16x16,  -15,  -26,  390,    1
    subsprite OAM_SIZE_16x16,   -6,  -34,  267,    1
    subsprite OAM_SIZE_8x8,      8,  -25,  410,    0
  FileE03E_Obj_207:
    subsprite OAM_SIZE_8x16,     1,  -26,  384,    1
    subsprite OAM_SIZE_16x32,   -8,  -20,  422,    1
    subsprite OAM_SIZE_8x8,     -9,   -7,  388,    1
    subsprite OAM_SIZE_16x16,   -8,  -26,  392,    1
    subsprite OAM_SIZE_8x8,     -7,  -10,  287,    1
    subsprite OAM_SIZE_8x8,      8,  -18,  394,    1
    subsprite OAM_SIZE_8x16,    -9,  -23,  389,    1
    subsprite OAM_SIZE_16x16,   -6,  -34,  269,    1
    subsprite OAM_SIZE_8x8,      8,  -24,  410,    0

2:
FileE03E_Cmds:
  FileE03E_Cmd_0:
    animcmd   0,   1
  FileE03E_Cmd_1:
    animcmd   1,   1
  FileE03E_Cmd_2:
    animcmd   2,   1
  FileE03E_Cmd_3:
    animcmd   3,   1
  FileE03E_Cmd_4:
    animcmd   4,   1
  FileE03E_Cmd_5:
    animcmd   5,   1
  FileE03E_Cmd_6:
    animcmd   6,   1
  FileE03E_Cmd_7:
    animcmd   7,   1
  FileE03E_Cmd_8:
    animcmd   8,   1
  FileE03E_Cmd_9:
    animcmd   9,   1
  FileE03E_Cmd_10:
    animcmd  10,  13
    animcmd  11,  11
    animcmd  12,  13
    animcmd  13,  11
  FileE03E_Cmd_14:
    animcmd  14,  13
    animcmd  15,  11
    animcmd  16,  13
    animcmd  17,  11
  FileE03E_Cmd_18:
    animcmd  18,   9
    animcmd  19,  11
    animcmd  20,   9
    animcmd  21,  11
  FileE03E_Cmd_22:
    animcmd  22,   9
    animcmd  23,  11
    animcmd  24,   9
    animcmd  25,  11

FileE03E_Tiles:
  .incbin "data/sprite_main/coffinseller_snake.4bpp"
