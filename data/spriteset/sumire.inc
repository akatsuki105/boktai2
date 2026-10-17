FileDFFE_Header:
  .2byte 741 @ palStart
  .2byte 18 @ metaspriteCount
  .2byte 11 @ animationCount
  .2byte 136 @ subspriteCount
  .2byte 19 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 392 @ offsetToAnims
  .4byte 480 @ offsetToSubsprites
  .4byte 1568 @ offsetToCmds
  .4byte 1644 @ offsetToTiles

FileDFFE_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF551, FileDFFE_Obj_0,     6,          -28,  -42,   12,    6
  pose 0xF571, FileDFFE_Obj_6,     7,          -24,  -42,    8,    6
  pose 0xF591, FileDFFE_Obj_13,    7,          -27,  -42,    8,    0
  pose 0xF5B1, FileDFFE_Obj_20,    8,          -24,  -43,    9,    6
  pose 0xF5D1, FileDFFE_Obj_28,    9,          -32,  -43,   16,    0
  pose 0xF381, FileDFFE_Obj_37,    9,          -25,  -44,   17,   12
  pose 0xF382, FileDFFE_Obj_46,    8,          -25,  -42,   15,   13
  pose 0xF383, FileDFFE_Obj_54,    9,          -25,  -44,   15,   12
  pose 0xF384, FileDFFE_Obj_63,    7,          -25,  -42,   15,    6
  pose 0xF3C1, FileDFFE_Obj_70,    8,          -25,  -43,   15,    0
  pose 0xF3C2, FileDFFE_Obj_78,    8,          -26,  -42,   16,    5
  pose 0xF3C3, FileDFFE_Obj_86,    8,          -25,  -43,   15,    5
  pose 0xF3C4, FileDFFE_Obj_94,    9,          -24,  -42,   16,    4
  pose 0xDF61, FileDFFE_Obj_103,   8,          -24,  -43,    9,    6
  pose 0xDF81, FileDFFE_Obj_111,   7,          -26,  -42,   10,    6
  pose 0xDFA1, FileDFFE_Obj_118,   8,          -24,  -42,   10,    6
  pose 0xD5B5, FileDFFE_Obj_126,   2,          -24,  -34,    8,   14
  pose 0xD502, FileDFFE_Obj_128,   8,          -24,  -43,    9,    6

FileDFFE_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB152, FileDFFE_Cmd_0,     1
  animation 0xB172, FileDFFE_Cmd_1,     1
  animation 0xB192, FileDFFE_Cmd_2,     1
  animation 0xB1B2, FileDFFE_Cmd_3,     1
  animation 0xB1D2, FileDFFE_Cmd_4,     1
  animation 0x2F89, FileDFFE_Cmd_5,     4
  animation 0x2FC9, FileDFFE_Cmd_9,     4
  animation 0x8756, FileDFFE_Cmd_13,    3
  animation 0x8736, FileDFFE_Cmd_16,    1
  animation 0x2709, FileDFFE_Cmd_17,    1
  animation 0x8F03, FileDFFE_Cmd_18,    1

1:
FileDFFE_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDFFE_Obj_0:
    subsprite OAM_SIZE_8x16,    -4,  -12,   48,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   58,    0
    subsprite OAM_SIZE_16x16,  -12,  -26,    0,    0
    subsprite OAM_SIZE_8x16,     4,  -26,    2,    0
    subsprite OAM_SIZE_16x8,   -12,  -10,   32,    0
    subsprite OAM_SIZE_8x8,      4,  -10,   34,    0
  FileDFFE_Obj_6:
    subsprite OAM_SIZE_8x16,    -4,  -12,   52,    0
    subsprite OAM_SIZE_8x8,     -8,  -17,   15,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   60,    0
    subsprite OAM_SIZE_8x16,     0,  -17,   85,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,    4,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,   36,    0
    subsprite OAM_SIZE_8x16,   -16,  -18,   19,    0
  FileDFFE_Obj_13:
    subsprite OAM_SIZE_8x16,    -4,  -12,   51,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   62,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,    6,    0
    subsprite OAM_SIZE_8x8,     -3,  -10,   39,    0
    subsprite OAM_SIZE_8x8,    -11,  -10,   38,    0
    subsprite OAM_SIZE_8x16,    -1,  -25,   53,    0
    subsprite OAM_SIZE_8x16,    -4,  -16,   84,    0
  FileDFFE_Obj_20:
    subsprite OAM_SIZE_8x16,    -4,  -12,   50,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,   15,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,    9,    0
    subsprite OAM_SIZE_8x16,   -16,  -18,   24,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,   41,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   80,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   56,    0
    subsprite OAM_SIZE_8x16,    -8,  -18,   31,    0
  FileDFFE_Obj_28:
    subsprite OAM_SIZE_16x16,    0,  -26,   12,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -16,  -26,   12,    0
    subsprite OAM_SIZE_8x8,      0,  -10,   45,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -10,   45,    0
    subsprite OAM_SIZE_8x16,    -4,  -12,   49,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   82,    0
    subsprite OAM_SIZE_8x16,   -10,  -17,   87,    0
    subsprite OAM_SIZE_8x16,     1,  -17,   86,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,   54,    0
  FileDFFE_Obj_37:
    subsprite OAM_SIZE_8x8,     -9,  -16,  112,    0
    subsprite OAM_SIZE_16x16,   -8,  -10,   88,    0
    subsprite OAM_SIZE_16x16,   -7,  -20,  196,    0
    subsprite OAM_SIZE_16x8,     1,  -15,  153,    0
    subsprite OAM_SIZE_16x8,    -7,   -4,  170,    0
    subsprite OAM_SIZE_16x16,   -9,  -28,  116,    0
    subsprite OAM_SIZE_8x16,     7,  -28,  118,    0
    subsprite OAM_SIZE_16x8,    -9,  -12,  148,    0
    subsprite OAM_SIZE_8x8,      7,  -12,  150,    0
  FileDFFE_Obj_46:
    subsprite OAM_SIZE_16x16,   -8,  -10,   90,    0
    subsprite OAM_SIZE_8x8,     -7,  -16,  113,    0
    subsprite OAM_SIZE_16x16,   -7,  -19,  198,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  172,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  155,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  119,    0
    subsprite OAM_SIZE_8x16,     7,  -26,  121,    0
    subsprite OAM_SIZE_16x8,    -9,  -10,  151,    0
  FileDFFE_Obj_54:
    subsprite OAM_SIZE_16x16,   -8,  -10,   92,    0
    subsprite OAM_SIZE_8x8,     -5,  -18,  114,    0
    subsprite OAM_SIZE_16x16,   -6,  -20,  200,    0
    subsprite OAM_SIZE_16x8,    -6,   -4,  174,    0
    subsprite OAM_SIZE_8x8,      0,  -11,  156,    0
    subsprite OAM_SIZE_16x16,   -9,  -28,  116,    0
    subsprite OAM_SIZE_8x16,     7,  -28,  118,    0
    subsprite OAM_SIZE_16x8,    -9,  -12,  148,    0
    subsprite OAM_SIZE_8x8,      7,  -12,  150,    0
  FileDFFE_Obj_63:
    subsprite OAM_SIZE_16x16,   -8,  -10,   94,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  115,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,  232,    0
    subsprite OAM_SIZE_8x8,      2,  -13,  131,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  119,    0
    subsprite OAM_SIZE_8x16,     7,  -26,  121,    0
    subsprite OAM_SIZE_16x8,    -9,  -10,  151,    0
  FileDFFE_Obj_70:
    subsprite OAM_SIZE_8x16,    -3,   -9,  122,    0
    subsprite OAM_SIZE_8x8,      3,  -15,  144,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  167,    0
    subsprite OAM_SIZE_8x8,     -9,  -10,  182,    0
    subsprite OAM_SIZE_8x16,     7,  -26,  169,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  224,    0
    subsprite OAM_SIZE_8x8,     -6,  -13,  234,    0
    subsprite OAM_SIZE_16x16,   -4,  -27,   56,    0
  FileDFFE_Obj_78:
    subsprite OAM_SIZE_16x16,   -8,  -26,  164,    0
    subsprite OAM_SIZE_16x16,  -10,  -11,  123,    0
    subsprite OAM_SIZE_8x8,      2,  -15,  145,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,  226,    0
    subsprite OAM_SIZE_8x16,     0,  -24,  194,    0
    subsprite OAM_SIZE_8x8,      8,  -24,  195,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  235,    0
    subsprite OAM_SIZE_8x8,     -4,   -4,  206,    0
  FileDFFE_Obj_86:
    subsprite OAM_SIZE_16x16,   -9,  -26,  167,    0
    subsprite OAM_SIZE_8x8,     -9,  -10,  182,    0
    subsprite OAM_SIZE_8x8,      7,  -26,  169,    0
    subsprite OAM_SIZE_16x16,   -8,  -11,  125,    0
    subsprite OAM_SIZE_8x8,      0,  -16,  146,    0
    subsprite OAM_SIZE_16x16,   -6,  -17,  228,    0
    subsprite OAM_SIZE_16x16,   -4,  -27,   56,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  250,    0
  FileDFFE_Obj_94:
    subsprite OAM_SIZE_16x16,   -8,  -26,  164,    0
    subsprite OAM_SIZE_8x8,      8,  -26,  166,    0
    subsprite OAM_SIZE_8x16,    -3,  -11,  127,    0
    subsprite OAM_SIZE_8x8,      2,  -15,  147,    0
    subsprite OAM_SIZE_16x16,   -7,  -16,  230,    0
    subsprite OAM_SIZE_8x16,     0,  -24,  194,    0
    subsprite OAM_SIZE_8x8,      8,  -24,  195,    0
    subsprite OAM_SIZE_8x8,     -5,  -12,  251,    0
    subsprite OAM_SIZE_8x8,     -4,   -4,  206,    0
  FileDFFE_Obj_103:
    subsprite OAM_SIZE_8x16,    -4,  -12,   50,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,    9,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,   15,    0
    subsprite OAM_SIZE_8x16,   -16,  -18,   24,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,   41,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   80,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   56,    0
    subsprite OAM_SIZE_8x16,    -8,  -16,   84,    0
  FileDFFE_Obj_111:
    subsprite OAM_SIZE_8x8,     -1,  -14,   11,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  220,    0
    subsprite OAM_SIZE_16x8,   -10,  -10,  252,    0
    subsprite OAM_SIZE_8x16,    -4,  -12,   50,    0
    subsprite OAM_SIZE_16x16,   -8,  -15,   80,    0
    subsprite OAM_SIZE_16x16,   -6,  -25,  222,    0
    subsprite OAM_SIZE_8x16,    -8,  -15,   30,    0
  FileDFFE_Obj_118:
    subsprite OAM_SIZE_8x16,    -4,  -12,   50,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,    9,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,   41,    0
    subsprite OAM_SIZE_8x16,   -16,  -18,   24,    0
    subsprite OAM_SIZE_8x8,      0,  -17,    8,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   80,    0
    subsprite OAM_SIZE_8x8,     -8,  -15,    3,    0
    subsprite OAM_SIZE_16x16,   -6,  -26,  192,    0
  FileDFFE_Obj_126:
    subsprite OAM_SIZE_16x8,    -8,   -2,  218,    1
    subsprite OAM_SIZE_16x16,   -8,  -18,  186,    1
  FileDFFE_Obj_128:
    subsprite OAM_SIZE_8x16,    -4,  -12,   50,    0
    subsprite OAM_SIZE_8x8,      0,  -16,  190,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,    9,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,   41,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,   80,    0
    subsprite OAM_SIZE_8x16,    -8,  -16,  191,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,  188,    0
    subsprite OAM_SIZE_8x16,   -16,  -18,   24,    0

2:
FileDFFE_Cmds:
  FileDFFE_Cmd_0:
    animcmd   0,   1
  FileDFFE_Cmd_1:
    animcmd   1,   1
  FileDFFE_Cmd_2:
    animcmd   2,   1
  FileDFFE_Cmd_3:
    animcmd   3,   1
  FileDFFE_Cmd_4:
    animcmd   4,   1
  FileDFFE_Cmd_5:
    animcmd   5,   9
    animcmd   6,  11
    animcmd   7,   9
    animcmd   8,  11
  FileDFFE_Cmd_9:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileDFFE_Cmd_13:
    animcmd   3,  11
    animcmd  14,   9
    animcmd  15,   1
  FileDFFE_Cmd_16:
    animcmd  15,   1
  FileDFFE_Cmd_17:
    animcmd  16,   1
  FileDFFE_Cmd_18:
    animcmd  17,   1

FileDFFE_Tiles:
  .incbin "data/spriteset/sumire.4bpp"
