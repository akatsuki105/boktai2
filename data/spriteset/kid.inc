FileE01E_Header:
  .2byte 658 @ palStart
  .2byte 21 @ metaspriteCount
  .2byte 9 @ animationCount
  .2byte 182 @ subspriteCount
  .2byte 21 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 452 @ offsetToAnims
  .4byte 524 @ offsetToSubsprites
  .4byte 1980 @ offsetToCmds
  .4byte 2064 @ offsetToTiles

FileE01E_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF561, FileE01E_Obj_0,     8,          -28,  -51,   12,   10
  pose 0xF581, FileE01E_Obj_8,     8,          -27,  -51,   14,    4
  pose 0xF5A1, FileE01E_Obj_16,    9,          -26,  -51,   14,    4
  pose 0xF5C1, FileE01E_Obj_25,    9,          -30,  -50,   13,    5
  pose 0xF5E1, FileE01E_Obj_34,    8,          -27,  -51,   13,   10
  pose 0xFC51, FileE01E_Obj_42,    8,          -27,  -52,   16,    5
  pose 0xFC52, FileE01E_Obj_50,    9,          -27,  -53,   16,    7
  pose 0xFC53, FileE01E_Obj_59,    8,          -27,  -52,   16,    5
  pose 0xFC54, FileE01E_Obj_67,    8,          -27,  -53,   16,    4
  pose 0xF391, FileE01E_Obj_75,    9,          -25,  -53,   18,    4
  pose 0xF392, FileE01E_Obj_84,    8,          -25,  -52,   18,    1
  pose 0xF393, FileE01E_Obj_92,    8,          -25,  -53,   18,    4
  pose 0xF394, FileE01E_Obj_100,   8,          -25,  -52,   18,    1
  pose 0xFC91, FileE01E_Obj_108,   8,          -29,  -50,   15,    6
  pose 0xFC92, FileE01E_Obj_116,   9,          -29,  -51,   15,    5
  pose 0xFC93, FileE01E_Obj_125,   9,          -29,  -50,   15,    6
  pose 0xFC94, FileE01E_Obj_134,   9,          -29,  -51,   15,    5
  pose 0xF3D1, FileE01E_Obj_143,   10,         -28,  -50,   17,    5
  pose 0xF3D2, FileE01E_Obj_153,   10,         -28,  -49,   17,    6
  pose 0xF3D3, FileE01E_Obj_163,   9,          -28,  -50,   17,    7
  pose 0xF3D4, FileE01E_Obj_172,   10,         -28,  -49,   17,    6

FileE01E_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB162, FileE01E_Cmd_0,     1
  animation 0xB182, FileE01E_Cmd_1,     1
  animation 0xB1A2, FileE01E_Cmd_2,     1
  animation 0xB1C2, FileE01E_Cmd_3,     1
  animation 0xB1E2, FileE01E_Cmd_4,     1
  animation 0x3858, FileE01E_Cmd_5,     4
  animation 0x3898, FileE01E_Cmd_9,     4
  animation 0x2F99, FileE01E_Cmd_13,    4
  animation 0x2FD9, FileE01E_Cmd_17,    4

1:
FileE01E_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE01E_Obj_0:
    subsprite OAM_SIZE_16x16,   -7,  -13,   94,    0
    subsprite OAM_SIZE_8x16,   -12,  -24,  176,    0
    subsprite OAM_SIZE_8x16,     2,  -21,  180,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   68,    0
    subsprite OAM_SIZE_16x8,    -8,   -6,  100,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,   32,    0
    subsprite OAM_SIZE_16x16,  -12,  -35,    0,    0
    subsprite OAM_SIZE_8x16,     4,  -35,    2,    0
  FileE01E_Obj_8:
    subsprite OAM_SIZE_8x16,    -9,  -24,  177,    0
    subsprite OAM_SIZE_16x16,   -8,  -12,   62,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,   70,    0
    subsprite OAM_SIZE_8x8,     -6,   -6,  102,    0
    subsprite OAM_SIZE_8x16,     0,  -19,  181,    0
    subsprite OAM_SIZE_16x16,  -10,  -35,    3,    0
    subsprite OAM_SIZE_8x16,     6,  -35,    5,    0
    subsprite OAM_SIZE_16x16,  -11,  -20,   34,    0
  FileE01E_Obj_16:
    subsprite OAM_SIZE_16x16,   -5,  -22,   72,    0
    subsprite OAM_SIZE_8x8,     -5,   -6,  103,    0
    subsprite OAM_SIZE_8x16,    -4,  -12,  125,    0
    subsprite OAM_SIZE_8x16,    -5,  -20,   15,    0
    subsprite OAM_SIZE_8x8,     -5,   -4,   47,    0
    subsprite OAM_SIZE_8x16,   -12,  -21,   36,    0
    subsprite OAM_SIZE_16x16,  -10,  -35,    6,    0
    subsprite OAM_SIZE_8x16,     6,  -35,    8,    0
    subsprite OAM_SIZE_8x8,     -2,  -19,  247,    0
  FileE01E_Obj_25:
    subsprite OAM_SIZE_16x16,  -14,  -22,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  123,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,   74,    0
    subsprite OAM_SIZE_8x8,     -6,   -6,  104,    0
    subsprite OAM_SIZE_8x16,     1,  -24,  178,    0
    subsprite OAM_SIZE_8x16,    -9,  -19,  182,    0
    subsprite OAM_SIZE_8x8,     -3,  -42,  106,    0
    subsprite OAM_SIZE_8x16,     5,  -34,   11,    0
    subsprite OAM_SIZE_16x16,  -11,  -34,    9,    0
  FileE01E_Obj_34:
    subsprite OAM_SIZE_8x8,     -3,  -19,   46,    0
    subsprite OAM_SIZE_16x16,   -8,  -12,  126,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   76,    0
    subsprite OAM_SIZE_16x8,    -8,   -6,  108,    0
    subsprite OAM_SIZE_8x16,     4,  -21,  179,    0
    subsprite OAM_SIZE_8x16,   -12,  -20,  159,    0
    subsprite OAM_SIZE_16x16,  -11,  -35,   12,    0
    subsprite OAM_SIZE_8x16,     5,  -35,   14,    0
  FileE01E_Obj_42:
    subsprite OAM_SIZE_8x16,    -2,  -11,  112,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   64,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,   96,    0
    subsprite OAM_SIZE_8x16,    -8,  -28,  150,    0
    subsprite OAM_SIZE_8x16,     1,  -19,   41,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    3,    0
    subsprite OAM_SIZE_8x16,     8,  -36,    5,    0
    subsprite OAM_SIZE_16x16,  -11,  -21,   34,    0
  FileE01E_Obj_50:
    subsprite OAM_SIZE_16x16,   -7,  -17,  215,    0
    subsprite OAM_SIZE_8x8,      1,   -1,  246,    0
    subsprite OAM_SIZE_8x16,    -9,  -28,  151,    0
    subsprite OAM_SIZE_16x16,   -7,  -28,   64,    0
    subsprite OAM_SIZE_16x8,    -7,  -12,   96,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   34,    0
    subsprite OAM_SIZE_8x16,     0,  -20,   42,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    3,    0
    subsprite OAM_SIZE_8x16,     8,  -37,    5,    0
  FileE01E_Obj_59:
    subsprite OAM_SIZE_16x16,   -6,  -14,  115,    0
    subsprite OAM_SIZE_8x16,    -8,  -28,  152,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   64,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,   96,    0
    subsprite OAM_SIZE_16x16,  -11,  -21,   34,    0
    subsprite OAM_SIZE_8x16,     0,  -20,   43,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    3,    0
    subsprite OAM_SIZE_8x16,     8,  -36,    5,    0
  FileE01E_Obj_67:
    subsprite OAM_SIZE_16x16,   -7,  -14,  117,    0
    subsprite OAM_SIZE_8x16,   -10,  -27,  151,    0
    subsprite OAM_SIZE_16x16,   -7,  -28,   64,    0
    subsprite OAM_SIZE_16x8,    -7,  -12,   96,    0
    subsprite OAM_SIZE_8x16,     0,  -20,   42,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   34,    0
    subsprite OAM_SIZE_16x16,   -8,  -37,    3,    0
    subsprite OAM_SIZE_8x16,     8,  -37,    5,    0
  FileE01E_Obj_75:
    subsprite OAM_SIZE_8x16,    -1,  -12,  119,    0
    subsprite OAM_SIZE_8x8,     -9,   -4,  248,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  221,    0
    subsprite OAM_SIZE_8x8,     -5,   -8,  245,    0
    subsprite OAM_SIZE_8x16,    -7,  -29,  153,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   34,    0
    subsprite OAM_SIZE_16x16,    0,  -20,   44,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,    3,    0
    subsprite OAM_SIZE_8x16,    10,  -37,    5,    0
  FileE01E_Obj_84:
    subsprite OAM_SIZE_16x16,   -6,  -17,  120,    0
    subsprite OAM_SIZE_8x16,    -7,  -29,  154,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  221,    0
    subsprite OAM_SIZE_8x8,     -5,   -7,  245,    0
    subsprite OAM_SIZE_16x16,    0,  -20,  144,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   34,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,    3,    0
    subsprite OAM_SIZE_8x16,    10,  -36,    5,    0
  FileE01E_Obj_92:
    subsprite OAM_SIZE_8x16,    -5,  -31,  154,    0
    subsprite OAM_SIZE_16x16,   -7,  -12,  113,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  221,    0
    subsprite OAM_SIZE_8x8,     -5,   -8,  245,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   34,    0
    subsprite OAM_SIZE_8x16,     1,  -20,  146,    0
    subsprite OAM_SIZE_16x16,   -6,  -37,    3,    0
    subsprite OAM_SIZE_8x16,    10,  -37,    5,    0
  FileE01E_Obj_100:
    subsprite OAM_SIZE_8x16,    -2,  -12,  122,    0
    subsprite OAM_SIZE_8x16,    -7,  -29,  155,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  221,    0
    subsprite OAM_SIZE_8x8,     -5,   -7,  245,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   34,    0
    subsprite OAM_SIZE_16x16,   -6,  -36,    3,    0
    subsprite OAM_SIZE_8x16,    10,  -36,    5,    0
    subsprite OAM_SIZE_16x16,    0,  -20,  144,    0
  FileE01E_Obj_108:
    subsprite OAM_SIZE_16x16,  -13,  -22,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  208,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,   66,    0
    subsprite OAM_SIZE_16x8,    -7,  -10,   98,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,    9,    0
    subsprite OAM_SIZE_8x16,     7,  -34,   11,    0
    subsprite OAM_SIZE_8x8,     -1,  -42,  106,    0
    subsprite OAM_SIZE_8x16,    -6,  -19,  183,    0
  FileE01E_Obj_116:
    subsprite OAM_SIZE_16x16,  -13,  -23,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  210,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   66,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,   98,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,    9,    0
    subsprite OAM_SIZE_8x16,     7,  -35,   11,    0
    subsprite OAM_SIZE_8x8,     -1,  -43,  106,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  184,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  240,    0
  FileE01E_Obj_125:
    subsprite OAM_SIZE_16x16,  -13,  -22,   37,    0
    subsprite OAM_SIZE_8x16,    -3,   -9,  212,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,   66,    0
    subsprite OAM_SIZE_16x8,    -7,  -10,   98,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,    9,    0
    subsprite OAM_SIZE_8x16,     7,  -34,   11,    0
    subsprite OAM_SIZE_8x8,     -1,  -42,  106,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  185,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  241,    0
  FileE01E_Obj_134:
    subsprite OAM_SIZE_16x16,  -13,  -23,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  213,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   66,    0
    subsprite OAM_SIZE_16x8,    -7,  -11,   98,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,    9,    0
    subsprite OAM_SIZE_8x16,     7,  -35,   11,    0
    subsprite OAM_SIZE_8x8,     -1,  -43,  106,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  186,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  242,    0
  FileE01E_Obj_143:
    subsprite OAM_SIZE_16x16,  -12,  -23,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  217,    0
    subsprite OAM_SIZE_16x8,    -7,  -19,  249,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  219,    0
    subsprite OAM_SIZE_16x8,    -8,  -11,  243,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,    9,    0
    subsprite OAM_SIZE_8x16,     9,  -34,   11,    0
    subsprite OAM_SIZE_8x8,      1,  -42,  106,    0
    subsprite OAM_SIZE_8x16,    -4,  -22,  148,    0
    subsprite OAM_SIZE_8x8,      4,  -14,  107,    0
  FileE01E_Obj_153:
    subsprite OAM_SIZE_16x16,  -12,  -22,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  187,    0
    subsprite OAM_SIZE_8x16,     1,  -26,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  219,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,  243,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,    9,    0
    subsprite OAM_SIZE_8x16,     9,  -33,   11,    0
    subsprite OAM_SIZE_8x8,      1,  -41,  106,    0
    subsprite OAM_SIZE_8x8,      3,  -12,  105,    0
    subsprite OAM_SIZE_8x16,    -5,  -20,  149,    0
  FileE01E_Obj_163:
    subsprite OAM_SIZE_16x16,  -12,  -23,   37,    0
    subsprite OAM_SIZE_16x16,   -8,   -9,  189,    0
    subsprite OAM_SIZE_16x16,    1,  -24,  157,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  219,    0
    subsprite OAM_SIZE_16x8,    -8,  -11,  243,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,    9,    0
    subsprite OAM_SIZE_8x16,     9,  -34,   11,    0
    subsprite OAM_SIZE_8x8,      1,  -42,  106,    0
    subsprite OAM_SIZE_8x16,    -7,  -21,  147,    0
  FileE01E_Obj_172:
    subsprite OAM_SIZE_16x16,  -12,  -22,   37,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,   39,    0
    subsprite OAM_SIZE_8x16,     1,  -26,  156,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  219,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,  243,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,    9,    0
    subsprite OAM_SIZE_8x16,     9,  -33,   11,    0
    subsprite OAM_SIZE_8x8,      1,  -41,  106,    0
    subsprite OAM_SIZE_8x16,    -5,  -19,  149,    0
    subsprite OAM_SIZE_8x8,      3,  -11,  105,    0

2:
FileE01E_Cmds:
  FileE01E_Cmd_0:
    animcmd   0,   1
  FileE01E_Cmd_1:
    animcmd   1,   1
  FileE01E_Cmd_2:
    animcmd   2,   1
  FileE01E_Cmd_3:
    animcmd   3,   1
  FileE01E_Cmd_4:
    animcmd   4,   1
  FileE01E_Cmd_5:
    animcmd   5,  13
    animcmd   6,  11
    animcmd   7,  13
    animcmd   8,  11
  FileE01E_Cmd_9:
    animcmd  13,  13
    animcmd  14,  11
    animcmd  15,  13
    animcmd  16,  11
  FileE01E_Cmd_13:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileE01E_Cmd_17:
    animcmd  17,   9
    animcmd  18,  11
    animcmd  19,   9
    animcmd  20,  11

FileE01E_Tiles:
  .incbin "data/spriteset/kid.4bpp"
