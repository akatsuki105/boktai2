FileE02E_Header:
  .2byte 667 @ palStart
  .2byte 21 @ metaspriteCount
  .2byte 9 @ animationCount
  .2byte 147 @ subspriteCount
  .2byte 21 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 452 @ offsetToAnims
  .4byte 524 @ offsetToSubsprites
  .4byte 1700 @ offsetToCmds
  .4byte 1784 @ offsetToTiles

FileE02E_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x256A, FileE02E_Obj_0,     6,          -24,  -55,    9,   15
  pose 0x258A, FileE02E_Obj_6,     8,          -24,  -55,    8,   15
  pose 0x25AA, FileE02E_Obj_14,    4,          -25,  -55,    8,   15
  pose 0x25CA, FileE02E_Obj_18,    6,          -24,  -55,    8,   15
  pose 0x25EA, FileE02E_Obj_24,    7,          -24,  -55,    9,   16
  pose 0x2C5A, FileE02E_Obj_31,    8,          -26,  -54,    8,    8
  pose 0x2C5B, FileE02E_Obj_39,    7,          -24,  -55,    8,    7
  pose 0x2C5C, FileE02E_Obj_46,    7,          -24,  -54,    8,   16
  pose 0x2C5D, FileE02E_Obj_53,    7,          -25,  -55,    8,    7
  pose 0x239A, FileE02E_Obj_60,    7,          -24,  -55,   17,   13
  pose 0x239B, FileE02E_Obj_67,    8,          -23,  -55,   17,    7
  pose 0x239C, FileE02E_Obj_75,    9,          -24,  -55,   17,   11
  pose 0x239D, FileE02E_Obj_84,    7,          -25,  -55,   17,    6
  pose 0x2C9A, FileE02E_Obj_91,    7,          -24,  -54,    8,   16
  pose 0x2C9B, FileE02E_Obj_98,    7,          -24,  -55,    8,   15
  pose 0x2C9C, FileE02E_Obj_105,   7,          -26,  -54,    9,    8
  pose 0x2C9D, FileE02E_Obj_112,   7,          -24,  -55,    9,    7
  pose 0x23DA, FileE02E_Obj_119,   6,          -25,  -55,   10,    7
  pose 0x23DB, FileE02E_Obj_125,   7,          -23,  -54,   10,    8
  pose 0x23DC, FileE02E_Obj_132,   8,          -23,  -55,   11,    7
  pose 0x23DD, FileE02E_Obj_140,   7,          -24,  -54,   10,    8

FileE02E_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xE16A, FileE02E_Cmd_0,     1
  animation 0xE18A, FileE02E_Cmd_1,     1
  animation 0xE1AA, FileE02E_Cmd_2,     1
  animation 0xE1CA, FileE02E_Cmd_3,     1
  animation 0xE1EA, FileE02E_Cmd_4,     1
  animation 0x6860, FileE02E_Cmd_5,     4
  animation 0x68A0, FileE02E_Cmd_9,     4
  animation 0x5FA1, FileE02E_Cmd_13,    4
  animation 0x5FE1, FileE02E_Cmd_17,    4

1:
FileE02E_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE02E_Obj_0:
    subsprite OAM_SIZE_16x8,    -8,   -1,   70,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,   38,    0
    subsprite OAM_SIZE_16x8,    -8,  -25,   36,    0
    subsprite OAM_SIZE_16x16,   -8,  -31,   50,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,    0,    0
    subsprite OAM_SIZE_8x8,    -15,  -31,   32,    0
  FileE02E_Obj_6:
    subsprite OAM_SIZE_16x8,    -8,   -1,   72,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,   40,    0
    subsprite OAM_SIZE_16x8,    -8,  -25,   26,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,    2,    0
    subsprite OAM_SIZE_8x16,     0,  -28,   53,    0
    subsprite OAM_SIZE_8x8,     -8,  -28,   52,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   33,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   33,    0
  FileE02E_Obj_14:
    subsprite OAM_SIZE_16x8,    -8,   -1,   74,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,   42,    0
    subsprite OAM_SIZE_16x8,    -8,  -24,   10,    0
    subsprite OAM_SIZE_16x16,   -9,  -39,    4,    0
  FileE02E_Obj_18:
    subsprite OAM_SIZE_16x16,   -8,  -17,   44,    0
    subsprite OAM_SIZE_16x8,    -8,  -25,   34,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,   81,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,    6,    0
    subsprite OAM_SIZE_16x8,    -8,   -1,   76,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   33,    0
  FileE02E_Obj_24:
    subsprite OAM_SIZE_8x8,     -4,  -29,  216,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   46,    0
    subsprite OAM_SIZE_16x8,    -8,    0,   78,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,   48,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,    8,    0
    subsprite OAM_SIZE_8x8,    -15,  -31,   30,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,   83,    0
  FileE02E_Obj_31:
    subsprite OAM_SIZE_8x16,    -8,  -24,  239,    0
    subsprite OAM_SIZE_16x16,  -10,  -16,  184,    0
    subsprite OAM_SIZE_8x8,     -2,    0,  217,    0
    subsprite OAM_SIZE_16x8,    -8,  -24,  222,    0
    subsprite OAM_SIZE_8x16,     0,  -24,   12,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,  237,    0
    subsprite OAM_SIZE_8x8,    -16,  -30,   14,    0
  FileE02E_Obj_39:
    subsprite OAM_SIZE_8x16,    -8,  -25,  152,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,  186,    0
    subsprite OAM_SIZE_8x8,     -8,   -1,  218,    0
    subsprite OAM_SIZE_16x8,    -8,  -25,  222,    0
    subsprite OAM_SIZE_8x16,     0,  -24,   13,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,  237,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   14,    0
  FileE02E_Obj_46:
    subsprite OAM_SIZE_8x16,    -8,  -24,   93,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  220,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  188,    0
    subsprite OAM_SIZE_16x8,    -8,  -24,  222,    0
    subsprite OAM_SIZE_8x16,    -1,  -24,   15,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,  237,    0
    subsprite OAM_SIZE_8x8,    -16,  -30,   14,    0
  FileE02E_Obj_53:
    subsprite OAM_SIZE_8x16,    -8,  -25,  152,    0
    subsprite OAM_SIZE_16x16,   -9,  -17,  190,    0
    subsprite OAM_SIZE_8x8,     -1,   -1,  219,    0
    subsprite OAM_SIZE_16x8,    -8,  -25,  222,    0
    subsprite OAM_SIZE_8x16,     0,  -24,   13,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,  237,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   14,    0
  FileE02E_Obj_60:
    subsprite OAM_SIZE_8x16,    -9,  -31,  231,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  176,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  208,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,  229,    0
    subsprite OAM_SIZE_8x16,     2,  -31,  234,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  226,    0
    subsprite OAM_SIZE_8x8,      9,  -39,  228,    0
  FileE02E_Obj_67:
    subsprite OAM_SIZE_8x16,    -6,  -32,  232,    0
    subsprite OAM_SIZE_16x16,   -7,  -17,  194,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  229,    0
    subsprite OAM_SIZE_16x8,    -7,  -25,  178,    0
    subsprite OAM_SIZE_8x16,     2,  -29,  235,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  224,    0
    subsprite OAM_SIZE_8x8,      9,  -31,  244,    0
    subsprite OAM_SIZE_8x8,     -1,   -1,  220,    0
  FileE02E_Obj_75:
    subsprite OAM_SIZE_8x16,    -5,  -32,  233,    0
    subsprite OAM_SIZE_8x8,      3,  -24,  216,    0
    subsprite OAM_SIZE_8x8,      8,   -5,  214,    0
    subsprite OAM_SIZE_16x8,    -8,   -5,  212,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,  229,    0
    subsprite OAM_SIZE_16x16,   -8,  -21,  180,    0
    subsprite OAM_SIZE_8x16,    -2,  -28,  236,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  226,    0
    subsprite OAM_SIZE_8x8,      9,  -39,  228,    0
  FileE02E_Obj_84:
    subsprite OAM_SIZE_8x16,    -6,  -32,  232,    0
    subsprite OAM_SIZE_16x16,   -9,  -18,  182,    0
    subsprite OAM_SIZE_8x8,     -1,   -2,  215,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  229,    0
    subsprite OAM_SIZE_8x16,     2,  -29,  235,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  224,    0
    subsprite OAM_SIZE_8x8,      9,  -31,  244,    0
  FileE02E_Obj_91:
    subsprite OAM_SIZE_8x16,     0,  -24,   88,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  112,    0
    subsprite OAM_SIZE_16x8,    -8,    0,   91,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,   94,    0
    subsprite OAM_SIZE_8x16,    -7,  -24,   85,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    6,    0
    subsprite OAM_SIZE_8x8,    -16,  -30,   33,    0
  FileE02E_Obj_98:
    subsprite OAM_SIZE_8x16,    -1,  -27,   89,    0
    subsprite OAM_SIZE_16x8,    -8,   -1,  107,    0
    subsprite OAM_SIZE_16x16,   -8,  -17,  114,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   94,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,   86,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,    6,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   33,    0
  FileE02E_Obj_105:
    subsprite OAM_SIZE_8x16,     1,  -27,   90,    0
    subsprite OAM_SIZE_8x8,     -2,    0,  122,    0
    subsprite OAM_SIZE_16x16,  -10,  -16,  116,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,   94,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,   87,    0
    subsprite OAM_SIZE_16x16,   -8,  -38,    6,    0
    subsprite OAM_SIZE_8x8,    -16,  -30,   33,    0
  FileE02E_Obj_112:
    subsprite OAM_SIZE_8x16,    -1,  -27,   89,    0
    subsprite OAM_SIZE_8x8,     -7,   -1,  123,    0
    subsprite OAM_SIZE_16x16,   -7,  -17,  118,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   94,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,   86,    0
    subsprite OAM_SIZE_16x16,   -8,  -39,    6,    0
    subsprite OAM_SIZE_8x8,    -16,  -31,   33,    0
  FileE02E_Obj_119:
    subsprite OAM_SIZE_16x16,   -9,  -17,  124,    0
    subsprite OAM_SIZE_8x8,     -1,   -1,  120,    0
    subsprite OAM_SIZE_16x8,    -7,  -25,  138,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  150,    0
    subsprite OAM_SIZE_8x16,    -5,  -24,  153,    0
    subsprite OAM_SIZE_8x8,      2,  -32,   33,    0
  FileE02E_Obj_125:
    subsprite OAM_SIZE_8x16,     0,  -26,  157,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,  126,    0
    subsprite OAM_SIZE_8x8,     -9,    0,  136,    0
    subsprite OAM_SIZE_16x8,    -7,  -23,  138,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,  148,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,  154,    0
    subsprite OAM_SIZE_8x8,      2,  -30,   33,    0
  FileE02E_Obj_132:
    subsprite OAM_SIZE_16x16,   -5,  -29,  158,    0
    subsprite OAM_SIZE_16x16,   -5,  -17,  144,    0
    subsprite OAM_SIZE_8x8,     -5,   -1,  121,    0
    subsprite OAM_SIZE_16x8,    -7,  -25,  138,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,  155,    0
    subsprite OAM_SIZE_16x16,   -7,  -39,  150,    0
    subsprite OAM_SIZE_8x8,      2,  -32,   33,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,   33,    0
  FileE02E_Obj_140:
    subsprite OAM_SIZE_8x16,     0,  -26,  157,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  146,    0
    subsprite OAM_SIZE_8x8,     -8,    0,  137,    0
    subsprite OAM_SIZE_16x8,    -7,  -23,  138,    0
    subsprite OAM_SIZE_16x16,   -7,  -38,  148,    0
    subsprite OAM_SIZE_8x16,    -8,  -24,  154,    0
    subsprite OAM_SIZE_8x8,      2,  -30,   33,    0

2:
FileE02E_Cmds:
  FileE02E_Cmd_0:
    animcmd   0,   1
  FileE02E_Cmd_1:
    animcmd   1,   1
  FileE02E_Cmd_2:
    animcmd   2,   1
  FileE02E_Cmd_3:
    animcmd   3,   1
  FileE02E_Cmd_4:
    animcmd   4,   1
  FileE02E_Cmd_5:
    animcmd   5,  13
    animcmd   6,  11
    animcmd   7,  13
    animcmd   8,  11
  FileE02E_Cmd_9:
    animcmd  13,  13
    animcmd  14,  11
    animcmd  15,  13
    animcmd  16,  11
  FileE02E_Cmd_13:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileE02E_Cmd_17:
    animcmd  17,   9
    animcmd  18,  11
    animcmd  19,   9
    animcmd  20,  11

FileE02E_Tiles:
  .incbin "data/spriteset/lady.4bpp"
