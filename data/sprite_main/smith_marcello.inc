FileDFCE_Header:
  .2byte 743 @ palStart
  .2byte 54 @ metaspriteCount
  .2byte 25 @ animationCount
  .2byte 529 @ subspriteCount
  .2byte 56 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 1112 @ offsetToAnims
  .4byte 1312 @ offsetToSubsprites
  .4byte 5544 @ offsetToCmds
  .4byte 5768 @ offsetToTiles

FileDFCE_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF539, FileDFCE_Obj_0,     10,         -24,  -54,   16,    3
  pose 0xF559, FileDFCE_Obj_10,    11,         -28,  -54,   12,    9
  pose 0xF579, FileDFCE_Obj_21,    8,          -24,  -54,    8,   10
  pose 0xF599, FileDFCE_Obj_29,    9,          -28,  -54,    9,    9
  pose 0xF5B9, FileDFCE_Obj_38,    9,          -24,  -54,   16,    2
  pose 0xFC29, FileDFCE_Obj_47,    10,         -30,  -54,   19,    9
  pose 0xFC2A, FileDFCE_Obj_57,    11,         -27,  -55,   13,    8
  pose 0xFC2B, FileDFCE_Obj_68,    11,         -26,  -54,   17,    9
  pose 0xFC2C, FileDFCE_Obj_79,    11,         -27,  -55,   13,    8
  pose 0xF369, FileDFCE_Obj_90,    8,          -30,  -55,   19,    8
  pose 0xF36A, FileDFCE_Obj_98,    8,          -28,  -54,   18,    9
  pose 0xF36B, FileDFCE_Obj_106,   10,         -26,  -55,   17,    8
  pose 0xF36C, FileDFCE_Obj_116,   8,          -28,  -54,   18,    9
  pose 0xFC69, FileDFCE_Obj_124,   10,         -27,  -53,   16,    9
  pose 0xFC6A, FileDFCE_Obj_134,   9,          -27,  -54,   10,    8
  pose 0xFC6B, FileDFCE_Obj_143,   10,         -30,  -53,   18,    9
  pose 0xFC6C, FileDFCE_Obj_153,   9,          -27,  -54,   10,    8
  pose 0xF3A9, FileDFCE_Obj_162,   10,         -27,  -53,   16,    8
  pose 0xF3AA, FileDFCE_Obj_172,   8,          -28,  -52,   18,    9
  pose 0xF3AB, FileDFCE_Obj_180,   9,          -31,  -53,   18,    8
  pose 0xF3AC, FileDFCE_Obj_189,   8,          -28,  -52,   18,    9
  pose 0xDE69, FileDFCE_Obj_197,   10,         -26,  -54,   20,    9
  pose 0xDE6A, FileDFCE_Obj_207,   10,         -28,  -59,   12,   10
  pose 0xDE6B, FileDFCE_Obj_217,   10,         -27,  -58,   13,   10
  pose 0xDE6C, FileDFCE_Obj_227,   12,         -28,  -62,   16,   10
  pose 0xDE6D, FileDFCE_Obj_239,   12,         -27,  -63,   17,   10
  pose 0xDE6E, FileDFCE_Obj_251,   10,         -26,  -58,   14,   10
  pose 0xDE6F, FileDFCE_Obj_261,   10,         -25,  -51,   20,    9
  pose 0xDE70, FileDFCE_Obj_271,   12,         -24,  -50,   25,   14
  pose 0xDE71, FileDFCE_Obj_283,   12,         -24,  -50,   25,   13
  pose 0xDE72, FileDFCE_Obj_295,   12,         -24,  -50,   25,   14
  pose 0xF541, FileDFCE_Obj_307,   10,         -24,  -54,   16,    3
  pose 0xF561, FileDFCE_Obj_317,   11,         -28,  -54,   12,    9
  pose 0xF581, FileDFCE_Obj_328,   7,          -25,  -54,    8,   10
  pose 0xF5A1, FileDFCE_Obj_335,   11,         -28,  -54,   12,    9
  pose 0xF5C1, FileDFCE_Obj_346,   10,         -24,  -54,   16,    2
  pose 0xFC31, FileDFCE_Obj_356,   10,         -30,  -54,   19,    9
  pose 0xFC32, FileDFCE_Obj_366,   11,         -27,  -55,   13,    8
  pose 0xFC33, FileDFCE_Obj_377,   11,         -26,  -54,   17,    9
  pose 0xFC34, FileDFCE_Obj_388,   11,         -27,  -55,   13,    8
  pose 0xF371, FileDFCE_Obj_399,   8,          -30,  -55,   19,    8
  pose 0xF372, FileDFCE_Obj_407,   8,          -28,  -54,   18,    9
  pose 0xF373, FileDFCE_Obj_415,   10,         -26,  -55,   17,    8
  pose 0xF374, FileDFCE_Obj_425,   8,          -28,  -54,   18,    9
  pose 0xFC71, FileDFCE_Obj_433,   11,         -27,  -53,   16,    9
  pose 0xFC72, FileDFCE_Obj_444,   11,         -27,  -54,   13,    8
  pose 0xFC73, FileDFCE_Obj_455,   10,         -30,  -53,   18,    9
  pose 0xFC74, FileDFCE_Obj_465,   12,         -27,  -54,   13,    8
  pose 0xF3B1, FileDFCE_Obj_477,   10,         -27,  -53,   16,    8
  pose 0xF3B2, FileDFCE_Obj_487,   10,         -28,  -52,   18,    9
  pose 0xF3B3, FileDFCE_Obj_497,   9,          -31,  -53,   18,    8
  pose 0xF3B4, FileDFCE_Obj_506,   9,          -28,  -52,   18,    9
  pose 0xCEA0, FileDFCE_Obj_515,   3,          -51,  -49,   21,   23
  pose 0xCEA1, FileDFCE_Obj_518,   11,         -33,  -49,   15,   11

FileDFCE_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB13A, FileDFCE_Cmd_0,     1
  animation 0xB15A, FileDFCE_Cmd_1,     1
  animation 0xB17A, FileDFCE_Cmd_2,     1
  animation 0xB19A, FileDFCE_Cmd_3,     1
  animation 0xB1BA, FileDFCE_Cmd_4,     1
  animation 0x3830, FileDFCE_Cmd_5,     4
  animation 0x3870, FileDFCE_Cmd_9,     4
  animation 0x2F71, FileDFCE_Cmd_13,    4
  animation 0x2FB1, FileDFCE_Cmd_17,    4
  animation 0x9A70, FileDFCE_Cmd_21,    2
  animation 0x9A71, FileDFCE_Cmd_23,    1
  animation 0x9A72, FileDFCE_Cmd_24,    1
  animation 0x9A73, FileDFCE_Cmd_25,    1
  animation 0x9A74, FileDFCE_Cmd_26,    7
  animation 0x8AA3, FileDFCE_Cmd_33,    1
  animation 0x8AA4, FileDFCE_Cmd_34,    1
  animation 0xB142, FileDFCE_Cmd_35,    1
  animation 0xB162, FileDFCE_Cmd_36,    1
  animation 0xB182, FileDFCE_Cmd_37,    1
  animation 0xB1A2, FileDFCE_Cmd_38,    1
  animation 0xB1C2, FileDFCE_Cmd_39,    1
  animation 0x3838, FileDFCE_Cmd_40,    4
  animation 0x3878, FileDFCE_Cmd_44,    4
  animation 0x2F79, FileDFCE_Cmd_48,    4
  animation 0x2FB9, FileDFCE_Cmd_52,    4

1:
FileDFCE_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDFCE_Obj_0:
    subsprite OAM_SIZE_16x8,    -8,  -15,   64,    0
    subsprite OAM_SIZE_8x16,     0,   -7,   66,    0
    subsprite OAM_SIZE_8x16,    -8,   -7,   66,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -29,   14,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,  494,    0
    subsprite OAM_SIZE_8x16,     7,  -26,  256,    0
    subsprite OAM_SIZE_8x8,      8,  -10,  257,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  256,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -10,  257,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -38,    0,    0
  FileDFCE_Obj_10:
    subsprite OAM_SIZE_8x16,   -12,  -29,  262,    0
    subsprite OAM_SIZE_8x8,    -10,  -13,  257,    0
    subsprite OAM_SIZE_8x8,    -20,  -23,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,   80,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   67,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  422,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,  450,    0
    subsprite OAM_SIZE_8x16,     1,  -23,  258,    0
    subsprite OAM_SIZE_8x8,      4,   -7,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    2,    0
  FileDFCE_Obj_21:
    subsprite OAM_SIZE_16x8,    -8,  -14,   69,    0
    subsprite OAM_SIZE_16x16,   -8,   -6,   71,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  426,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,  428,    0
    subsprite OAM_SIZE_8x16,    -5,  -22,  259,    0
    subsprite OAM_SIZE_8x8,     -2,   -6,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    4,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  464,    0
  FileDFCE_Obj_29:
    subsprite OAM_SIZE_8x16,     1,  -29,  264,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_8x16,   -16,  -26,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  430,    0
    subsprite OAM_SIZE_16x16,   -8,  -14,   46,    0
    subsprite OAM_SIZE_8x16,   -12,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -10,   -7,  257,    0
    subsprite OAM_SIZE_8x8,    -20,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    6,    0
  FileDFCE_Obj_38:
    subsprite OAM_SIZE_8x16,    -8,   -7,   77,    0
    subsprite OAM_SIZE_8x16,     0,   -7,   77,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -30,  480,    0
    subsprite OAM_SIZE_16x16,   -8,  -14,  482,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  261,    0
    subsprite OAM_SIZE_8x8,    -16,  -10,  257,    0, xflip=1
    subsprite OAM_SIZE_8x16,     7,  -26,  261,    0, xflip=1
    subsprite OAM_SIZE_8x8,      8,  -10,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    8,    0
  FileDFCE_Obj_47:
    subsprite OAM_SIZE_16x16,  -14,  -29,  270,    0
    subsprite OAM_SIZE_8x8,    -12,  -13,  283,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,   91,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   78,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  450,    0
    subsprite OAM_SIZE_16x16,    3,  -23,  265,    0
    subsprite OAM_SIZE_8x8,     10,   -7,  267,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,    2,    0
  FileDFCE_Obj_57:
    subsprite OAM_SIZE_8x16,   -11,  -30,  262,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  257,    0
    subsprite OAM_SIZE_8x8,    -19,  -24,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,   96,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,   98,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -27,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,    2,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  450,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  258,    0
    subsprite OAM_SIZE_8x8,      5,   -8,  257,    0
  FileDFCE_Obj_68:
    subsprite OAM_SIZE_16x16,  -10,  -29,  288,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  112,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  101,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  490,    0
    subsprite OAM_SIZE_16x16,    1,  -23,  268,    0
    subsprite OAM_SIZE_8x8,      2,   -7,  257,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,    2,    0
    subsprite OAM_SIZE_8x8,      8,   -4,   90,    0
    subsprite OAM_SIZE_8x8,     -9,   -7,  367,    0
  FileDFCE_Obj_79:
    subsprite OAM_SIZE_8x16,   -11,  -30,  262,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  257,    0
    subsprite OAM_SIZE_8x8,    -19,  -24,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  103,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  105,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -27,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  450,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  258,    0
    subsprite OAM_SIZE_8x8,      5,   -8,  257,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,    2,    0
  FileDFCE_Obj_90:
    subsprite OAM_SIZE_16x16,  -14,  -30,  296,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,   91,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  107,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -27,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  486,    0
    subsprite OAM_SIZE_16x16,    3,  -24,  290,    0
    subsprite OAM_SIZE_16x16,   -6,  -39,    2,    0
  FileDFCE_Obj_98:
    subsprite OAM_SIZE_16x16,  -12,  -29,  298,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,   96,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  109,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  450,    0
    subsprite OAM_SIZE_16x16,    2,  -23,  292,    0
    subsprite OAM_SIZE_16x16,   -6,  -38,    2,    0
  FileDFCE_Obj_106:
    subsprite OAM_SIZE_16x16,  -10,  -30,  300,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  112,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  128,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -27,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  490,    0
    subsprite OAM_SIZE_16x16,    1,  -24,  294,    0
    subsprite OAM_SIZE_16x16,   -6,  -39,    2,    0
    subsprite OAM_SIZE_8x8,      8,   -4,   90,    0
    subsprite OAM_SIZE_8x8,     -9,   -8,  367,    0
  FileDFCE_Obj_116:
    subsprite OAM_SIZE_16x16,  -12,  -29,  298,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  103,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  130,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  484,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  449,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  450,    0
    subsprite OAM_SIZE_16x16,    2,  -23,  292,    0
    subsprite OAM_SIZE_16x16,   -6,  -38,    2,    0
  FileDFCE_Obj_124:
    subsprite OAM_SIZE_16x16,    0,  -28,  322,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  132,    0
    subsprite OAM_SIZE_8x8,    -16,   -6,  464,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -25,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  454,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,  302,    0
    subsprite OAM_SIZE_8x8,     -4,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,    6,    0
    subsprite OAM_SIZE_8x8,      8,   -3,   90,    0
  FileDFCE_Obj_134:
    subsprite OAM_SIZE_8x16,     2,  -29,  354,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  136,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  456,    0
    subsprite OAM_SIZE_8x8,     -9,   -7,  257,    0
    subsprite OAM_SIZE_8x16,   -11,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -19,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,    6,    0
  FileDFCE_Obj_143:
    subsprite OAM_SIZE_16x16,    2,  -28,  324,    0
    subsprite OAM_SIZE_8x8,      9,  -12,  267,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  150,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  138,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -25,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  458,    0
    subsprite OAM_SIZE_16x16,  -14,  -22,  320,    0
    subsprite OAM_SIZE_8x8,    -12,   -6,  283,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,    6,    0
  FileDFCE_Obj_153:
    subsprite OAM_SIZE_8x16,     2,  -29,  354,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  142,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  460,    0
    subsprite OAM_SIZE_8x8,     -9,   -7,  257,    0
    subsprite OAM_SIZE_8x16,   -11,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -19,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,    6,    0
  FileDFCE_Obj_162:
    subsprite OAM_SIZE_16x16,   -1,  -29,  332,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  119,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  160,    0
    subsprite OAM_SIZE_8x8,    -16,   -7,  464,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  454,    0
    subsprite OAM_SIZE_16x16,  -11,  -23,  326,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,    6,    0
    subsprite OAM_SIZE_8x8,      8,   -3,   90,    0
  FileDFCE_Obj_172:
    subsprite OAM_SIZE_16x16,    2,  -28,  334,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  162,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -25,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  456,    0
    subsprite OAM_SIZE_16x16,  -12,  -22,  328,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,    6,    0
  FileDFCE_Obj_180:
    subsprite OAM_SIZE_16x16,    2,  -29,  352,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  150,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  164,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -14,  458,    0
    subsprite OAM_SIZE_16x16,  -15,  -23,  330,    0
    subsprite OAM_SIZE_8x8,    -10,   -7,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,    6,    0
  FileDFCE_Obj_189:
    subsprite OAM_SIZE_16x16,    2,  -28,  334,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  166,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,  452,    0
    subsprite OAM_SIZE_8x16,   -15,  -25,  419,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  460,    0
    subsprite OAM_SIZE_16x16,  -12,  -22,  328,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,    6,    0
  FileDFCE_Obj_197:
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -8,  -14,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -26,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  430,    0
    subsprite OAM_SIZE_8x16,     3,  -32,  384,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    6,    0
    subsprite OAM_SIZE_16x16,    4,  -27,  391,    0
    subsprite OAM_SIZE_8x8,     12,  -11,  404,    0
    subsprite OAM_SIZE_16x16,  -10,  -25,  355,    0
    subsprite OAM_SIZE_8x8,      6,  -17,  357,    0
  FileDFCE_Obj_207:
    subsprite OAM_SIZE_16x16,   -8,   -6,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -25,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  430,    0
    subsprite OAM_SIZE_8x16,     1,  -30,  385,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_16x16,   -5,  -43,  393,    0
    subsprite OAM_SIZE_8x16,     1,  -27,  395,    0
    subsprite OAM_SIZE_16x16,  -12,  -24,  358,    0
    subsprite OAM_SIZE_8x8,      4,  -22,  373,    0
  FileDFCE_Obj_217:
    subsprite OAM_SIZE_16x16,   -8,   -6,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -25,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  430,    0
    subsprite OAM_SIZE_8x16,     2,  -29,  385,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_16x16,   -4,  -42,  393,    0
    subsprite OAM_SIZE_8x16,     2,  -26,  395,    0
    subsprite OAM_SIZE_16x16,  -11,  -23,  358,    0
    subsprite OAM_SIZE_8x8,      5,  -21,  373,    0
  FileDFCE_Obj_227:
    subsprite OAM_SIZE_16x16,   -8,   -6,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -25,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  430,    0
    subsprite OAM_SIZE_8x8,      2,  -35,  386,    0
    subsprite OAM_SIZE_16x8,     0,  -27,  387,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_8x8,    -10,  -31,  273,    0
    subsprite OAM_SIZE_16x16,  -12,  -46,  396,    0
    subsprite OAM_SIZE_8x16,    -2,  -30,  416,    0
    subsprite OAM_SIZE_16x16,  -12,  -28,  360,    0
    subsprite OAM_SIZE_8x8,      4,  -25,  362,    0
  FileDFCE_Obj_239:
    subsprite OAM_SIZE_16x16,   -8,   -6,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -25,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  430,    0
    subsprite OAM_SIZE_8x8,      3,  -36,  386,    0
    subsprite OAM_SIZE_16x8,     1,  -28,  387,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_8x8,     -9,  -32,  273,    0
    subsprite OAM_SIZE_16x16,  -11,  -47,  396,    0
    subsprite OAM_SIZE_8x16,    -1,  -31,  416,    0
    subsprite OAM_SIZE_16x16,  -11,  -29,  360,    0
    subsprite OAM_SIZE_8x8,      5,  -26,  362,    0
  FileDFCE_Obj_251:
    subsprite OAM_SIZE_16x16,   -8,   -6,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13,   46,    0
    subsprite OAM_SIZE_8x16,   -16,  -25,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  430,    0
    subsprite OAM_SIZE_8x16,     3,  -29,  385,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    6,    0
    subsprite OAM_SIZE_16x16,   -3,  -42,  393,    0
    subsprite OAM_SIZE_8x16,     3,  -26,  395,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  358,    0
    subsprite OAM_SIZE_8x8,      6,  -21,  373,    0
  FileDFCE_Obj_261:
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  230,    0
    subsprite OAM_SIZE_8x16,     8,  -23,  367,    0
    subsprite OAM_SIZE_16x16,   -8,  -12,  365,    0
    subsprite OAM_SIZE_8x16,     4,  -29,  389,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,    6,    0
    subsprite OAM_SIZE_16x16,    4,  -27,  391,    0
    subsprite OAM_SIZE_8x8,     12,  -11,  404,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  363,    0
    subsprite OAM_SIZE_8x8,      7,  -16,  378,    0
  FileDFCE_Obj_271:
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  462,    0
    subsprite OAM_SIZE_8x16,     8,  -24,  418,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  492,    0
    subsprite OAM_SIZE_16x16,    9,   -2,  420,    0
    subsprite OAM_SIZE_8x8,     10,  -10,  402,    0
    subsprite OAM_SIZE_8x16,     2,  -18,  417,    0
    subsprite OAM_SIZE_8x16,     5,  -27,  390,    0
    subsprite OAM_SIZE_8x8,     -3,  -15,  273,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   12,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  398,    0
    subsprite OAM_SIZE_8x8,      6,   -8,  403,    0
  FileDFCE_Obj_283:
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  462,    0
    subsprite OAM_SIZE_8x16,     8,  -24,  418,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  492,    0
    subsprite OAM_SIZE_16x16,    9,   -3,  420,    0
    subsprite OAM_SIZE_8x8,     10,  -11,  402,    0
    subsprite OAM_SIZE_8x16,     2,  -19,  417,    0
    subsprite OAM_SIZE_8x16,     5,  -28,  390,    0
    subsprite OAM_SIZE_8x8,     -3,  -16,  273,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,    6,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  398,    0
    subsprite OAM_SIZE_8x8,      6,   -9,  403,    0
  FileDFCE_Obj_295:
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  462,    0
    subsprite OAM_SIZE_8x16,     8,  -24,  418,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  492,    0
    subsprite OAM_SIZE_8x8,     10,  -10,  402,    0
    subsprite OAM_SIZE_8x16,     2,  -18,  417,    0
    subsprite OAM_SIZE_16x16,    9,   -2,  420,    0
    subsprite OAM_SIZE_8x16,     5,  -27,  390,    0
    subsprite OAM_SIZE_8x8,     -3,  -15,  273,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,    6,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  398,    0
    subsprite OAM_SIZE_8x8,      6,   -8,  403,    0
  FileDFCE_Obj_307:
    subsprite OAM_SIZE_16x8,    -8,  -15,   64,    0
    subsprite OAM_SIZE_8x16,     0,   -7,   66,    0
    subsprite OAM_SIZE_8x16,    -8,   -7,   66,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -29,  196,    0
    subsprite OAM_SIZE_16x8,    -8,  -13,  510,    0
    subsprite OAM_SIZE_8x16,     7,  -26,  256,    0
    subsprite OAM_SIZE_8x8,      8,  -10,  257,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  256,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -10,  257,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -38,   32,    0
  FileDFCE_Obj_317:
    subsprite OAM_SIZE_8x16,   -12,  -29,  262,    0
    subsprite OAM_SIZE_8x8,    -10,  -13,  257,    0
    subsprite OAM_SIZE_8x8,    -20,  -23,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  156,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   67,    0
    subsprite OAM_SIZE_16x16,   -9,  -29,  198,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_8x8,    -17,  -25,  465,    0
    subsprite OAM_SIZE_8x16,     1,  -23,  258,    0
    subsprite OAM_SIZE_8x8,      4,   -7,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,   34,    0
  FileDFCE_Obj_328:
    subsprite OAM_SIZE_16x8,    -8,  -14,  168,    0
    subsprite OAM_SIZE_16x16,   -8,   -6,   71,    0
    subsprite OAM_SIZE_16x16,   -9,  -29,  200,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_8x16,    -5,  -22,  259,    0
    subsprite OAM_SIZE_8x8,     -2,   -6,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,   36,    0
  FileDFCE_Obj_335:
    subsprite OAM_SIZE_8x16,     1,  -29,  264,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  257,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  184,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   73,    0
    subsprite OAM_SIZE_16x16,   -9,  -30,  202,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,  140,    0
    subsprite OAM_SIZE_8x8,    -17,  -24,  465,    0
    subsprite OAM_SIZE_8x16,   -12,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -10,   -7,  257,    0
    subsprite OAM_SIZE_8x8,    -20,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,   38,    0
  FileDFCE_Obj_346:
    subsprite OAM_SIZE_16x8,    -8,  -15,  170,    0
    subsprite OAM_SIZE_8x16,    -8,   -7,   77,    0
    subsprite OAM_SIZE_8x16,     0,   -7,   77,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -30,  232,    0
    subsprite OAM_SIZE_16x8,    -8,  -14,  134,    0
    subsprite OAM_SIZE_8x16,   -15,  -26,  261,    0
    subsprite OAM_SIZE_8x8,    -16,  -10,  257,    0, xflip=1
    subsprite OAM_SIZE_8x16,     7,  -26,  261,    0, xflip=1
    subsprite OAM_SIZE_8x8,      8,  -10,  257,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,   40,    0
  FileDFCE_Obj_356:
    subsprite OAM_SIZE_16x16,  -14,  -29,  270,    0
    subsprite OAM_SIZE_8x8,    -12,  -13,  283,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  186,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,   78,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -25,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,    3,  -23,  265,    0
    subsprite OAM_SIZE_8x8,     10,   -7,  267,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,   34,    0
  FileDFCE_Obj_366:
    subsprite OAM_SIZE_8x16,   -11,  -30,  262,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  257,    0
    subsprite OAM_SIZE_8x8,    -19,  -24,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  172,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,   98,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  258,    0
    subsprite OAM_SIZE_8x8,      5,   -8,  257,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,   34,    0
  FileDFCE_Obj_377:
    subsprite OAM_SIZE_16x16,  -10,  -29,  288,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  188,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  101,    0
    subsprite OAM_SIZE_8x8,    -16,   -7,  100,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -25,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,    1,  -23,  268,    0
    subsprite OAM_SIZE_8x8,      2,   -7,  257,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,   34,    0
    subsprite OAM_SIZE_8x8,      8,   -4,   90,    0
  FileDFCE_Obj_388:
    subsprite OAM_SIZE_8x16,   -11,  -30,  262,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  257,    0
    subsprite OAM_SIZE_8x8,    -19,  -24,  273,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  174,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  105,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_8x16,     2,  -24,  258,    0
    subsprite OAM_SIZE_8x8,      5,   -8,  257,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,   34,    0
  FileDFCE_Obj_399:
    subsprite OAM_SIZE_16x16,  -14,  -30,  296,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  186,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  107,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_16x16,    3,  -24,  290,    0
    subsprite OAM_SIZE_16x16,   -6,  -39,   34,    0
  FileDFCE_Obj_407:
    subsprite OAM_SIZE_16x16,  -12,  -29,  298,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  172,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  109,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -25,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,    2,  -23,  292,    0
    subsprite OAM_SIZE_16x16,   -6,  -38,   42,    0
  FileDFCE_Obj_415:
    subsprite OAM_SIZE_16x16,  -10,  -30,  300,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  188,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  128,    0
    subsprite OAM_SIZE_8x8,    -16,   -8,  100,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -26,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_16x16,    1,  -24,  294,    0
    subsprite OAM_SIZE_16x16,   -6,  -39,   34,    0
    subsprite OAM_SIZE_8x8,      8,   -4,   90,    0
  FileDFCE_Obj_425:
    subsprite OAM_SIZE_16x16,  -12,  -29,  298,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  174,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  130,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  234,    0
    subsprite OAM_SIZE_8x8,    -16,  -25,  116,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,    2,  -23,  292,    0
    subsprite OAM_SIZE_16x16,   -6,  -38,   42,    0
  FileDFCE_Obj_433:
    subsprite OAM_SIZE_16x16,    0,  -28,  322,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  190,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  132,    0
    subsprite OAM_SIZE_8x8,    -16,   -6,  464,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  228,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_8x8,    -16,  -23,  464,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,  302,    0
    subsprite OAM_SIZE_8x8,     -4,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   38,    0
    subsprite OAM_SIZE_8x8,      8,   -3,   90,    0
  FileDFCE_Obj_444:
    subsprite OAM_SIZE_8x16,     2,  -29,  354,    0
    subsprite OAM_SIZE_8x8,      5,  -13,  257,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  192,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  136,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_8x8,     -9,   -7,  257,    0
    subsprite OAM_SIZE_8x16,   -11,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -19,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,   38,    0
  FileDFCE_Obj_455:
    subsprite OAM_SIZE_16x16,    2,  -28,  324,    0
    subsprite OAM_SIZE_8x8,      9,  -12,  267,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  208,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  138,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -23,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,  -14,  -22,  320,    0
    subsprite OAM_SIZE_8x8,    -12,   -6,  283,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   38,    0
  FileDFCE_Obj_465:
    subsprite OAM_SIZE_8x8,      5,  -13,  257,    0
    subsprite OAM_SIZE_8x16,     2,  -29,  354,    0
    subsprite OAM_SIZE_8x8,      5,  -13,  257,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,   75,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  142,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_8x8,     -9,   -7,  257,    0
    subsprite OAM_SIZE_8x16,   -11,  -23,  260,    0
    subsprite OAM_SIZE_8x8,    -19,  -17,  273,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,   38,    0
  FileDFCE_Obj_477:
    subsprite OAM_SIZE_16x16,   -1,  -29,  332,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  190,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  160,    0
    subsprite OAM_SIZE_8x8,    -16,   -7,  464,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_16x16,  -11,  -23,  326,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,   38,    0
    subsprite OAM_SIZE_8x8,      8,   -3,   90,    0
  FileDFCE_Obj_487:
    subsprite OAM_SIZE_16x16,    2,  -28,  334,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  267,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,  192,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  162,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -23,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,  -12,  -22,  328,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,   44,    0
  FileDFCE_Obj_497:
    subsprite OAM_SIZE_16x16,    2,  -29,  352,    0
    subsprite OAM_SIZE_16x8,    -8,  -16,  208,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  164,    0
    subsprite OAM_SIZE_16x16,   -8,  -30,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -14,   85,    0
    subsprite OAM_SIZE_16x16,  -15,  -23,  330,    0
    subsprite OAM_SIZE_8x8,    -10,   -7,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,   38,    0
  FileDFCE_Obj_506:
    subsprite OAM_SIZE_16x16,    2,  -28,  334,    0
    subsprite OAM_SIZE_16x8,    -8,  -15,   75,    0
    subsprite OAM_SIZE_16x16,   -8,   -7,  166,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  228,    0
    subsprite OAM_SIZE_8x8,    -16,  -23,  464,    0
    subsprite OAM_SIZE_16x8,    -9,  -13,   85,    0
    subsprite OAM_SIZE_16x16,  -12,  -22,  328,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  267,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,   44,    0
  FileDFCE_Obj_515:
    subsprite OAM_SIZE_32x32,  -19,  -17,  204,    0
    subsprite OAM_SIZE_8x8,      5,   15,  242,    0
    subsprite OAM_SIZE_8x16,    13,   -1,  111,    0
  FileDFCE_Obj_518:
    subsprite OAM_SIZE_16x16,   -2,  -29,  324,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  404,    0
    subsprite OAM_SIZE_16x8,   -11,  -14,  119,    0
    subsprite OAM_SIZE_16x16,  -10,  -28,  452,    0
    subsprite OAM_SIZE_8x16,   -18,  -24,  419,    0
    subsprite OAM_SIZE_16x16,  -10,  -12,  454,    0
    subsprite OAM_SIZE_16x16,  -17,  -21,  320,    0
    subsprite OAM_SIZE_8x8,    -15,   -5,  283,    0
    subsprite OAM_SIZE_16x16,   -1,  -12,  224,    0
    subsprite OAM_SIZE_16x8,   -14,   -5,  226,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   10,    0

2:
FileDFCE_Cmds:
  FileDFCE_Cmd_0:
    animcmd   0,   1
  FileDFCE_Cmd_1:
    animcmd   1,   1
  FileDFCE_Cmd_2:
    animcmd   2,   1
  FileDFCE_Cmd_3:
    animcmd   3,   1
  FileDFCE_Cmd_4:
    animcmd   4,   1
  FileDFCE_Cmd_5:
    animcmd   5,  13
    animcmd   6,  11
    animcmd   7,  13
    animcmd   8,  11
  FileDFCE_Cmd_9:
    animcmd  13,  13
    animcmd  14,  11
    animcmd  15,  13
    animcmd  16,  11
  FileDFCE_Cmd_13:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileDFCE_Cmd_17:
    animcmd  17,   9
    animcmd  18,  11
    animcmd  19,   9
    animcmd  20,  11
  FileDFCE_Cmd_21:
    animcmd  21,   3
    animcmd  22,   4
  FileDFCE_Cmd_23:
    animcmd  23,   1
  FileDFCE_Cmd_24:
    animcmd  24,   5
  FileDFCE_Cmd_25:
    animcmd  25,   1
  FileDFCE_Cmd_26:
    animcmd  26,   2
    animcmd  27,   2
    animcmd  28,   2
    animcmd  29,   2
    animcmd  30,  12
    animcmd  27,   5
    animcmd  26,   4
  FileDFCE_Cmd_33:
    animcmd  52,   1
  FileDFCE_Cmd_34:
    animcmd  53,   1
  FileDFCE_Cmd_35:
    animcmd  31,   1
  FileDFCE_Cmd_36:
    animcmd  32,   1
  FileDFCE_Cmd_37:
    animcmd  33,   1
  FileDFCE_Cmd_38:
    animcmd  34,   1
  FileDFCE_Cmd_39:
    animcmd  35,   1
  FileDFCE_Cmd_40:
    animcmd  36,  13
    animcmd  37,  11
    animcmd  38,  13
    animcmd  39,  11
  FileDFCE_Cmd_44:
    animcmd  44,  13
    animcmd  45,  11
    animcmd  46,  13
    animcmd  47,  11
  FileDFCE_Cmd_48:
    animcmd  40,   9
    animcmd  41,  11
    animcmd  42,   9
    animcmd  43,  11
  FileDFCE_Cmd_52:
    animcmd  48,   9
    animcmd  49,  11
    animcmd  50,   9
    animcmd  51,  11

FileDFCE_Tiles:
  .incbin "data/sprite_main/smith_marcello.4bpp"
