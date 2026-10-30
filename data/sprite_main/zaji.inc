FileDFEE_Header:
  .2byte 751 @ palStart
  .2byte 34 @ metaspriteCount
  .2byte 18 @ animationCount
  .2byte 229 @ subspriteCount
  .2byte 37 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 712 @ offsetToAnims
  .4byte 856 @ offsetToSubsprites
  .4byte 2688 @ offsetToCmds
  .4byte 2836 @ offsetToTiles

FileDFEE_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF549, FileDFEE_Obj_0,     6,          -24,  -49,   10,    3
  pose 0xF569, FileDFEE_Obj_6,     6,          -24,  -50,    8,    3
  pose 0xF589, FileDFEE_Obj_12,    5,          -24,  -50,    8,    3
  pose 0xF5A9, FileDFEE_Obj_17,    6,          -25,  -50,    8,    0
  pose 0xF5C9, FileDFEE_Obj_23,    6,          -24,  -50,   10,    3
  pose 0xF379, FileDFEE_Obj_29,    8,          -24,  -50,   16,    6
  pose 0xF37A, FileDFEE_Obj_37,    8,          -24,  -47,   16,    6
  pose 0xF37B, FileDFEE_Obj_45,    6,          -24,  -50,   11,    6
  pose 0xF37C, FileDFEE_Obj_51,    8,          -24,  -47,   16,    6
  pose 0xF3B9, FileDFEE_Obj_59,    8,          -24,  -49,   11,    6
  pose 0xF3BA, FileDFEE_Obj_67,    7,          -24,  -46,   10,    6
  pose 0xF3BB, FileDFEE_Obj_74,    8,          -24,  -49,   10,    6
  pose 0xF3BC, FileDFEE_Obj_82,    7,          -24,  -46,   10,    6
  pose 0xD509, FileDFEE_Obj_89,    6,          -24,  -50,   10,    3
  pose 0xD50A, FileDFEE_Obj_95,    8,          -34,  -49,   11,    5
  pose 0xD50B, FileDFEE_Obj_103,   8,          -33,  -47,    9,    6
  pose 0xD50C, FileDFEE_Obj_111,   8,          -34,  -47,   11,    6
  pose 0xD50D, FileDFEE_Obj_119,   8,          -31,  -47,   11,    5
  pose 0xD50E, FileDFEE_Obj_127,   9,          -25,  -60,   19,    4
  pose 0xD50F, FileDFEE_Obj_136,   9,          -24,  -61,   19,    4
  pose 0xD510, FileDFEE_Obj_145,   10,         -31,  -47,   11,    5
  pose 0xD511, FileDFEE_Obj_155,   8,          -34,  -49,   11,    5
  pose 0xAB27, FileDFEE_Obj_163,   6,          -25,  -50,    8,    0
  pose 0xAB28, FileDFEE_Obj_169,   6,          -25,  -50,    8,    0
  pose 0xAB29, FileDFEE_Obj_175,   6,          -25,  -50,    8,    0
  pose 0xAAE7, FileDFEE_Obj_181,   6,          -24,  -50,    8,    3
  pose 0xAAE8, FileDFEE_Obj_187,   6,          -24,  -50,    8,    3
  pose 0xAAE9, FileDFEE_Obj_193,   6,          -24,  -50,    8,    3
  pose 0x1867, FileDFEE_Obj_199,   6,          -25,  -50,    8,    0
  pose 0x1868, FileDFEE_Obj_205,   6,          -25,  -50,    8,    0
  pose 0xEA79, FileDFEE_Obj_211,   4,          -27,  -46,   13,    0
  pose 0xEA7A, FileDFEE_Obj_215,   4,          -27,  -47,   13,    0
  pose 0xEA7B, FileDFEE_Obj_219,   4,          -25,  -47,   13,    0
  pose 0xEA7C, FileDFEE_Obj_223,   6,          -24,  -50,    8,    3

FileDFEE_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB14A, FileDFEE_Cmd_0,     1
  animation 0xB16A, FileDFEE_Cmd_1,     1
  animation 0xB18A, FileDFEE_Cmd_2,     1
  animation 0xB1AA, FileDFEE_Cmd_3,     1
  animation 0xB1CA, FileDFEE_Cmd_4,     1
  animation 0x2F81, FileDFEE_Cmd_5,     4
  animation 0x2FC1, FileDFEE_Cmd_9,     4
  animation 0x910D, FileDFEE_Cmd_13,    5
  animation 0x912D, FileDFEE_Cmd_18,    2
  animation 0x914D, FileDFEE_Cmd_20,    3
  animation 0xB574, FileDFEE_Cmd_23,    2
  animation 0xB594, FileDFEE_Cmd_25,    1
  animation 0xB5B4, FileDFEE_Cmd_26,    2
  animation 0xB5D4, FileDFEE_Cmd_28,    1
  animation 0xB11E, FileDFEE_Cmd_29,    2
  animation 0xB13E, FileDFEE_Cmd_31,    1
  animation 0x4771, FileDFEE_Cmd_32,    4
  animation 0x4772, FileDFEE_Cmd_36,    1

1:
FileDFEE_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDFEE_Obj_0:
    subsprite OAM_SIZE_8x16,    -4,  -10,   78,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,     2,  -20,  166,    0
    subsprite OAM_SIZE_8x16,   -11,  -20,  141,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  109,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   42,    0
  FileDFEE_Obj_6:
    subsprite OAM_SIZE_8x16,    -3,  -10,   77,    0
    subsprite OAM_SIZE_8x16,    -8,  -23,  100,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   70,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   10,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  143,    0
  FileDFEE_Obj_12:
    subsprite OAM_SIZE_8x16,    -3,  -10,   76,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   62,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   68,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   12,    0
    subsprite OAM_SIZE_8x16,    -4,  -18,  111,    0
  FileDFEE_Obj_17:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   40,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
  FileDFEE_Obj_23:
    subsprite OAM_SIZE_8x16,    -4,  -10,   74,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   88,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,   64,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    8,    0
    subsprite OAM_SIZE_8x16,   -10,  -20,  167,    0
    subsprite OAM_SIZE_8x16,     2,  -20,  168,    0
  FileDFEE_Obj_29:
    subsprite OAM_SIZE_8x8,      3,  -15,  257,    0
    subsprite OAM_SIZE_8x16,    -7,  -24,  233,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  131,    0
    subsprite OAM_SIZE_16x8,    -6,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,   96,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   10,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  272,    0
    subsprite OAM_SIZE_16x8,     0,  -17,  285,    0
  FileDFEE_Obj_37:
    subsprite OAM_SIZE_8x8,      3,  -14,  257,    0
    subsprite OAM_SIZE_8x8,     -5,  -22,  263,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  133,    0
    subsprite OAM_SIZE_16x8,    -6,  -12,   72,    0
    subsprite OAM_SIZE_8x8,     -5,  -16,  115,    0
    subsprite OAM_SIZE_16x16,   -6,  -31,  107,    0
    subsprite OAM_SIZE_16x16,   -5,  -22,  103,    0
    subsprite OAM_SIZE_16x8,     0,  -16,  301,    0
  FileDFEE_Obj_45:
    subsprite OAM_SIZE_16x16,   -8,  -10,  135,    0
    subsprite OAM_SIZE_16x8,    -6,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,   96,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   10,    0
    subsprite OAM_SIZE_8x16,     2,  -21,  130,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  272,    0
  FileDFEE_Obj_51:
    subsprite OAM_SIZE_8x8,      3,  -14,  257,    0
    subsprite OAM_SIZE_8x8,     -5,  -22,  263,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  137,    0
    subsprite OAM_SIZE_16x8,    -6,  -12,   72,    0
    subsprite OAM_SIZE_16x16,   -6,  -31,  107,    0
    subsprite OAM_SIZE_16x16,   -5,  -22,  103,    0
    subsprite OAM_SIZE_16x8,     0,  -16,  301,    0
    subsprite OAM_SIZE_8x8,     -7,  -16,  273,    0
  FileDFEE_Obj_59:
    subsprite OAM_SIZE_16x16,   -8,  -10,  139,    0
    subsprite OAM_SIZE_16x16,   -7,  -17,   14,    0
    subsprite OAM_SIZE_8x8,      2,  -20,   99,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   66,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   40,    0
    subsprite OAM_SIZE_8x8,      1,  -15,  256,    0
    subsprite OAM_SIZE_8x16,    -9,  -18,   32,    0
    subsprite OAM_SIZE_8x8,      3,  -12,  280,    0
  FileDFEE_Obj_67:
    subsprite OAM_SIZE_8x8,      2,  -18,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  160,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,   14,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  101,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  105,    0
    subsprite OAM_SIZE_8x16,    -7,  -19,   34,    0
    subsprite OAM_SIZE_8x8,      1,  -14,  257,    0
  FileDFEE_Obj_74:
    subsprite OAM_SIZE_8x16,    -1,  -22,    1,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  162,    0
    subsprite OAM_SIZE_16x16,   -7,  -17,   14,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   66,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   40,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   33,    0
    subsprite OAM_SIZE_8x8,      0,  -11,   18,    0
    subsprite OAM_SIZE_8x8,      1,  -17,  257,    0
  FileDFEE_Obj_82:
    subsprite OAM_SIZE_8x16,     2,  -21,    0,    0
    subsprite OAM_SIZE_8x8,      2,  -21,  256,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,  164,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,   14,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  101,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  105,    0
    subsprite OAM_SIZE_8x16,    -7,  -18,   35,    0
  FileDFEE_Obj_89:
    subsprite OAM_SIZE_8x16,    -4,  -10,   74,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   46,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,   64,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    8,    0
    subsprite OAM_SIZE_8x16,   -10,  -20,  167,    0
    subsprite OAM_SIZE_8x16,     2,  -20,  168,    0
  FileDFEE_Obj_95:
    subsprite OAM_SIZE_8x16,    -4,  -11,    6,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,  288,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  234,    0
    subsprite OAM_SIZE_8x8,     -9,  -20,  279,    0
    subsprite OAM_SIZE_8x16,     3,  -20,  258,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,    8,    0
    subsprite OAM_SIZE_16x8,   -18,  -17,    3,    0
    subsprite OAM_SIZE_8x8,    -18,   -9,   19,    0
  FileDFEE_Obj_103:
    subsprite OAM_SIZE_8x16,    -4,  -11,    6,    0
    subsprite OAM_SIZE_16x8,    -7,  -10,  288,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  234,    0
    subsprite OAM_SIZE_8x8,     -8,  -21,  279,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,    8,    0
    subsprite OAM_SIZE_16x8,   -17,  -18,    3,    0
    subsprite OAM_SIZE_8x8,    -17,  -10,   19,    0
    subsprite OAM_SIZE_8x16,     1,  -19,  259,    0
  FileDFEE_Obj_111:
    subsprite OAM_SIZE_8x16,    -4,  -11,    6,    0
    subsprite OAM_SIZE_16x8,    -7,  -10,  288,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  234,    0
    subsprite OAM_SIZE_8x8,     -9,  -20,  279,    0
    subsprite OAM_SIZE_8x16,     3,  -20,  258,    0
    subsprite OAM_SIZE_16x8,   -18,  -17,    3,    0
    subsprite OAM_SIZE_8x8,    -18,   -9,   19,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,  169,    0
  FileDFEE_Obj_119:
    subsprite OAM_SIZE_8x16,    -3,  -12,    7,    0
    subsprite OAM_SIZE_16x8,    -8,  -11,  290,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  304,    0
    subsprite OAM_SIZE_8x16,     3,  -21,  260,    0
    subsprite OAM_SIZE_8x8,    -11,  -19,  264,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,  169,    0
    subsprite OAM_SIZE_16x16,  -15,  -25,   20,    0
    subsprite OAM_SIZE_8x8,     -7,  -33,    5,    0
  FileDFEE_Obj_127:
    subsprite OAM_SIZE_8x16,    -4,   -9,   38,    0
    subsprite OAM_SIZE_16x8,    -8,  -12,  292,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  306,    0
    subsprite OAM_SIZE_8x16,     2,  -23,  261,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,  236,    0
    subsprite OAM_SIZE_8x16,    -9,  -27,  265,    0
    subsprite OAM_SIZE_8x16,   -13,  -28,  172,    0
    subsprite OAM_SIZE_8x16,    -5,  -36,  173,    0
    subsprite OAM_SIZE_16x16,    3,  -44,  174,    0
  FileDFEE_Obj_136:
    subsprite OAM_SIZE_8x16,    -4,   -9,   38,    0
    subsprite OAM_SIZE_16x8,    -6,  -12,  294,    0
    subsprite OAM_SIZE_8x16,     2,  -23,  262,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  308,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,  201,    0
    subsprite OAM_SIZE_8x16,    -8,  -27,  266,    0
    subsprite OAM_SIZE_8x16,   -13,  -29,  204,    0
    subsprite OAM_SIZE_8x16,    -5,  -37,  205,    0
    subsprite OAM_SIZE_16x16,    3,  -45,  206,    0
  FileDFEE_Obj_145:
    subsprite OAM_SIZE_8x16,    -4,  -10,   39,    0
    subsprite OAM_SIZE_16x8,    -8,  -11,  290,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  304,    0
    subsprite OAM_SIZE_8x16,     3,  -21,  260,    0
    subsprite OAM_SIZE_8x8,    -11,  -19,  264,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,  169,    0
    subsprite OAM_SIZE_16x16,  -15,  -25,   20,    0
    subsprite OAM_SIZE_8x8,     -7,  -33,    5,    0
    subsprite OAM_SIZE_16x8,    -8,  -26,  269,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,   52,    0
  FileDFEE_Obj_155:
    subsprite OAM_SIZE_8x16,    -4,  -12,   98,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,  288,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  234,    0
    subsprite OAM_SIZE_8x8,     -9,  -20,  279,    0
    subsprite OAM_SIZE_8x16,     3,  -20,  258,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,    8,    0
    subsprite OAM_SIZE_16x8,   -18,  -17,    3,    0
    subsprite OAM_SIZE_8x8,    -18,   -9,   19,    0
  FileDFEE_Obj_163:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  198,    0
  FileDFEE_Obj_169:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  198,    0
  FileDFEE_Obj_175:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  224,    0
  FileDFEE_Obj_181:
    subsprite OAM_SIZE_8x16,    -3,  -10,   77,    0
    subsprite OAM_SIZE_8x16,    -8,  -23,  100,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   70,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   10,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  143,    0
  FileDFEE_Obj_187:
    subsprite OAM_SIZE_8x16,    -3,  -10,   77,    0
    subsprite OAM_SIZE_8x16,    -8,  -23,  100,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   70,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   10,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  143,    0
  FileDFEE_Obj_193:
    subsprite OAM_SIZE_8x16,    -3,  -10,   77,    0
    subsprite OAM_SIZE_8x16,    -8,  -23,  100,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   70,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  143,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  226,    0
  FileDFEE_Obj_199:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  228,    0
  FileDFEE_Obj_205:
    subsprite OAM_SIZE_8x16,    -3,  -10,   75,    0
    subsprite OAM_SIZE_16x16,   -8,  -18,   14,    0
    subsprite OAM_SIZE_8x16,     0,  -23,   79,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   66,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  230,    0
  FileDFEE_Obj_211:
    subsprite OAM_SIZE_8x16,    -1,  -10,  171,    0
    subsprite OAM_SIZE_16x16,  -11,  -20,  128,    0
    subsprite OAM_SIZE_16x8,    -3,  -18,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -30,  192,    0
  FileDFEE_Obj_215:
    subsprite OAM_SIZE_8x16,    -2,  -12,  338,    0
    subsprite OAM_SIZE_16x16,  -11,  -21,   44,    0
    subsprite OAM_SIZE_16x8,    -3,  -18,  283,    0
    subsprite OAM_SIZE_16x16,   -6,  -31,  194,    0
  FileDFEE_Obj_219:
    subsprite OAM_SIZE_8x16,    -3,  -11,  337,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,  238,    0
    subsprite OAM_SIZE_16x8,    -3,  -18,  299,    0
    subsprite OAM_SIZE_16x16,   -7,  -31,  196,    0
  FileDFEE_Obj_223:
    subsprite OAM_SIZE_8x16,    -3,  -11,  336,    0
    subsprite OAM_SIZE_8x16,    -8,  -23,  100,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   70,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   10,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  143,    0

2:
FileDFEE_Cmds:
  FileDFEE_Cmd_0:
    animcmd   0,   1
  FileDFEE_Cmd_1:
    animcmd   1,   1
  FileDFEE_Cmd_2:
    animcmd   2,   1
  FileDFEE_Cmd_3:
    animcmd   3,   1
  FileDFEE_Cmd_4:
    animcmd   4,   1
  FileDFEE_Cmd_5:
    animcmd   5,   9
    animcmd   6,  11
    animcmd   7,   9
    animcmd   8,  11
  FileDFEE_Cmd_9:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileDFEE_Cmd_13:
    animcmd   4,   9
    animcmd  14,   9
    animcmd  15,  19
    animcmd  17,   5
    animcmd  18,   7
  FileDFEE_Cmd_18:
    animcmd  19,   5
    animcmd  18,   5
  FileDFEE_Cmd_20:
    animcmd  20,   6
    animcmd  21,   6
    animcmd   4,  81
  FileDFEE_Cmd_23:
    animcmd   1,   9
    animcmd  27,   9
  FileDFEE_Cmd_25:
    animcmd  27,   9
  FileDFEE_Cmd_26:
    animcmd   3,   9
    animcmd  24,   9
  FileDFEE_Cmd_28:
    animcmd  24,   1
  FileDFEE_Cmd_29:
    animcmd  28,   9
    animcmd  29,   9
  FileDFEE_Cmd_31:
    animcmd  29,   1
  FileDFEE_Cmd_32:
    animcmd  30,   9
    animcmd  31,   9
    animcmd  32,   9
    animcmd  33,   9
  FileDFEE_Cmd_36:
    animcmd  30,   1

FileDFEE_Tiles:
  .incbin "data/sprite_main/zaji.4bpp"
