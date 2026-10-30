File92F0_Header:
  .2byte 683 @ palStart
  .2byte 33 @ metaspriteCount
  .2byte 11 @ animationCount
  .2byte 104 @ subspriteCount
  .2byte 42 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 692 @ offsetToAnims
  .4byte 780 @ offsetToSubsprites
  .4byte 1612 @ offsetToCmds
  .4byte 1780 @ offsetToTiles

File92F0_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x7E8C, File92F0_Obj_0,    2,            0,    0,  234,   80
  pose 0x7E8D, File92F0_Obj_2,    5,            0,    0,  235,  128
  pose 0x7E8E, File92F0_Obj_7,    7,            0,    0,  235,  128
  pose 0x7E8F, File92F0_Obj_14,   7,            0,    0,  235,  128
  pose 0xFDFA, File92F0_Obj_21,   2,            0,    0,  234,   80
  pose 0xFDFB, File92F0_Obj_23,   5,            0,    0,  235,  128
  pose 0xFDFC, File92F0_Obj_28,   7,            0,    0,  235,  128
  pose 0xFDFD, File92F0_Obj_35,   7,            0,    0,  235,  128
  pose 0x9D97, File92F0_Obj_42,   1,            0,    0,   72,   72
  pose 0x9D98, File92F0_Obj_43,   1,            0,    0,   72,   72
  pose 0x9D99, File92F0_Obj_44,   1,            0,    0,   72,   72
  pose 0x9D9A, File92F0_Obj_45,   1,            0,    0,   72,   72
  pose 0x9D9B, File92F0_Obj_46,   1,            0,    0,   72,   72
  pose 0x9D9C, File92F0_Obj_47,   1,            0,    0,   72,   72
  pose 0x9D9D, File92F0_Obj_48,   1,            0,    0,   72,   72
  pose 0x9D9E, File92F0_Obj_49,   1,            0,    0,   72,   72
  pose 0x9D9F, File92F0_Obj_50,   1,            0,    0,   72,   72
  pose 0x9DA0, File92F0_Obj_51,   1,            0,    0,   72,   72
  pose 0x9A6C, File92F0_Obj_52,   2,            0,    0,  120,   80
  pose 0x2E72, File92F0_Obj_54,   3,            0,    0,  120,   84
  pose 0x2E73, File92F0_Obj_57,   3,            0,    0,  120,   84
  pose 0x2E74, File92F0_Obj_60,   3,            0,    0,  120,   84
  pose 0x4672, File92F0_Obj_63,   3,            0,    0,  128,   84
  pose 0x4673, File92F0_Obj_66,   3,            0,    0,  128,   84
  pose 0x4674, File92F0_Obj_69,   3,            0,    0,  128,   84
  pose 0x5EC4, File92F0_Obj_72,   5,            0,    0,  136,  120
  pose 0x5EC5, File92F0_Obj_77,   5,            0,    0,  136,  120
  pose 0xC2CA, File92F0_Obj_82,   5,            0,    0,  136,  152
  pose 0xC2CB, File92F0_Obj_87,   5,            0,    0,  136,  152
  pose 0xA1DA, File92F0_Obj_92,   3,            0,    0,  136,  120
  pose 0xA1DB, File92F0_Obj_95,   3,            0,    0,  136,  120
  pose 0xA1DC, File92F0_Obj_98,   3,            0,    0,  136,  120
  pose 0xA1DD, File92F0_Obj_101,  3,            0,    0,  136,  120

File92F0_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0x846C, File92F0_Cmd_0,  6
  animation 0x846D, File92F0_Cmd_6,  2
  animation 0x846E, File92F0_Cmd_8,  5
  animation 0x846F, File92F0_Cmd_13, 1
  animation 0x03D7, File92F0_Cmd_14, 6
  animation 0x03D8, File92F0_Cmd_20, 2
  animation 0x03D9, File92F0_Cmd_22, 5
  animation 0x03DA, File92F0_Cmd_27, 1
  animation 0x108A, File92F0_Cmd_28, 4
  animation 0x1090, File92F0_Cmd_32, 4
  animation 0x550D, File92F0_Cmd_36, 6

1:
File92F0_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File92F0_Obj_0:
    subsprite OAM_SIZE_32x64,  194,   48,    0,    4
    subsprite OAM_SIZE_8x32,   226,   56,    8,    4
  File92F0_Obj_2:
    subsprite OAM_SIZE_8x32,   187,   56,    9,    4
    subsprite OAM_SIZE_8x32,   227,   56,    9,    4, xflip=1
    subsprite OAM_SIZE_32x16,  195,   96,  100,    4
    subsprite OAM_SIZE_32x32,  195,   48,    4,    4
    subsprite OAM_SIZE_32x16,  195,   80,   68,    4
  File92F0_Obj_7:
    subsprite OAM_SIZE_8x32,   187,   48,   72,    4
    subsprite OAM_SIZE_8x16,   187,   80,  136,    4
    subsprite OAM_SIZE_8x32,   227,   48,   72,    4, xflip=1
    subsprite OAM_SIZE_8x16,   227,   80,  136,    4, xflip=1
    subsprite OAM_SIZE_32x16,  195,   80,  192,    4
    subsprite OAM_SIZE_32x32,  195,   48,  128,    4
    subsprite OAM_SIZE_32x16,  195,   96,  100,    4
  File92F0_Obj_14:
    subsprite OAM_SIZE_8x32,   187,   48,   73,    4
    subsprite OAM_SIZE_8x16,   187,   80,  137,    4
    subsprite OAM_SIZE_8x32,   227,   48,   73,    4, xflip=1
    subsprite OAM_SIZE_8x16,   227,   80,  137,    4, xflip=1
    subsprite OAM_SIZE_32x16,  195,   96,  100,    4
    subsprite OAM_SIZE_32x16,  195,   80,  196,    4
    subsprite OAM_SIZE_32x32,  195,   48,  132,    4
  File92F0_Obj_21:
    subsprite OAM_SIZE_32x64,  194,   48,    0,    5
    subsprite OAM_SIZE_8x32,   226,   56,    8,    5
  File92F0_Obj_23:
    subsprite OAM_SIZE_8x32,   187,   56,    9,    5
    subsprite OAM_SIZE_8x32,   227,   56,    9,    5, xflip=1
    subsprite OAM_SIZE_32x32,  195,   48,    4,    5
    subsprite OAM_SIZE_32x16,  195,   80,   68,    5
    subsprite OAM_SIZE_32x16,  195,   96,  100,    5
  File92F0_Obj_28:
    subsprite OAM_SIZE_8x32,   187,   48,   72,    5
    subsprite OAM_SIZE_8x16,   187,   80,  136,    5
    subsprite OAM_SIZE_8x32,   227,   48,   72,    5, xflip=1
    subsprite OAM_SIZE_8x16,   227,   80,  136,    5, xflip=1
    subsprite OAM_SIZE_32x32,  195,   48,  128,    5
    subsprite OAM_SIZE_32x16,  195,   80,  192,    5
    subsprite OAM_SIZE_32x16,  195,   96,  100,    5
  File92F0_Obj_35:
    subsprite OAM_SIZE_8x32,   187,   48,   73,    5
    subsprite OAM_SIZE_8x16,   187,   80,  137,    5
    subsprite OAM_SIZE_8x32,   227,   48,   73,    5, xflip=1
    subsprite OAM_SIZE_8x16,   227,   80,  137,    5, xflip=1
    subsprite OAM_SIZE_32x32,  195,   48,  132,    5
    subsprite OAM_SIZE_32x16,  195,   80,  196,    5
    subsprite OAM_SIZE_32x16,  195,   96,  100,    5
  File92F0_Obj_42:
    subsprite OAM_SIZE_8x16,    64,   64,   10,    3
  File92F0_Obj_43:
    subsprite OAM_SIZE_8x16,    64,   64,   11,    3
  File92F0_Obj_44:
    subsprite OAM_SIZE_8x16,    64,   64,   12,    3
  File92F0_Obj_45:
    subsprite OAM_SIZE_8x16,    64,   64,   13,    3
  File92F0_Obj_46:
    subsprite OAM_SIZE_8x16,    64,   64,   14,    3
  File92F0_Obj_47:
    subsprite OAM_SIZE_8x16,    64,   64,   15,    3
  File92F0_Obj_48:
    subsprite OAM_SIZE_8x16,    64,   64,   42,    3
  File92F0_Obj_49:
    subsprite OAM_SIZE_8x16,    64,   64,   43,    3
  File92F0_Obj_50:
    subsprite OAM_SIZE_8x16,    64,   64,   44,    3
  File92F0_Obj_51:
    subsprite OAM_SIZE_8x16,    64,   64,   45,    3
  File92F0_Obj_52:
    subsprite OAM_SIZE_16x16,   88,   64,   46,    0
    subsprite OAM_SIZE_16x16,  104,   64,   46,    0, xflip=1
  File92F0_Obj_54:
    subsprite OAM_SIZE_16x16,   80,   64,   78,    0
    subsprite OAM_SIZE_8x8,     96,   68,   75,    0
    subsprite OAM_SIZE_16x8,   104,   68,   75,    0
  File92F0_Obj_57:
    subsprite OAM_SIZE_16x16,   80,   64,   78,    1
    subsprite OAM_SIZE_16x8,   104,   68,   75,    1
    subsprite OAM_SIZE_8x8,     96,   68,   75,    1
  File92F0_Obj_60:
    subsprite OAM_SIZE_16x16,   80,   64,   78,    2
    subsprite OAM_SIZE_16x8,   104,   68,   75,    2
    subsprite OAM_SIZE_8x8,     96,   68,   75,    2
  File92F0_Obj_63:
    subsprite OAM_SIZE_16x16,  112,   64,   78,    0, xflip=1
    subsprite OAM_SIZE_16x8,    88,   68,   75,    0, xflip=1
    subsprite OAM_SIZE_8x8,    104,   68,   75,    0
  File92F0_Obj_66:
    subsprite OAM_SIZE_16x16,  112,   64,   78,    1, xflip=1
    subsprite OAM_SIZE_16x8,    88,   68,   75,    1, xflip=1
    subsprite OAM_SIZE_8x8,    104,   68,   75,    1
  File92F0_Obj_69:
    subsprite OAM_SIZE_16x16,  112,   64,   78,    2, xflip=1
    subsprite OAM_SIZE_16x8,    88,   68,   75,    2, xflip=1
    subsprite OAM_SIZE_8x8,    104,   68,   75,    2
  File92F0_Obj_72:
    subsprite OAM_SIZE_16x16,   40,   88,  174,    0
    subsprite OAM_SIZE_16x16,   56,   88,  142,    0
    subsprite OAM_SIZE_32x16,   72,   88,  168,    0
    subsprite OAM_SIZE_16x16,  104,   88,  172,    0
    subsprite OAM_SIZE_16x16,  120,   88,  174,    0, xflip=1
  File92F0_Obj_77:
    subsprite OAM_SIZE_16x16,   56,   88,  142,    1
    subsprite OAM_SIZE_32x16,   72,   88,  168,    1
    subsprite OAM_SIZE_16x16,  104,   88,  172,    1
    subsprite OAM_SIZE_16x16,   40,   88,  174,    1
    subsprite OAM_SIZE_16x16,  120,   88,  174,    1, xflip=1
  File92F0_Obj_82:
    subsprite OAM_SIZE_32x16,   48,  120,  106,    0
    subsprite OAM_SIZE_32x16,   96,  120,  138,    0
    subsprite OAM_SIZE_16x16,   80,  120,  110,    0
    subsprite OAM_SIZE_8x16,    40,  120,  174,    0
    subsprite OAM_SIZE_8x16,   128,  120,  174,    0, xflip=1
  File92F0_Obj_87:
    subsprite OAM_SIZE_32x16,   48,  120,  106,    1
    subsprite OAM_SIZE_32x16,   96,  120,  138,    1
    subsprite OAM_SIZE_16x16,   80,  120,  110,    1
    subsprite OAM_SIZE_8x16,    40,  120,  174,    1
    subsprite OAM_SIZE_8x16,   128,  120,  174,    1, xflip=1
  File92F0_Obj_92:
    subsprite OAM_SIZE_32x16,   40,   88,  200,    0
    subsprite OAM_SIZE_32x16,  104,   88,  200,    0, xflip=1
    subsprite OAM_SIZE_32x16,   72,   88,  202,    0
  File92F0_Obj_95:
    subsprite OAM_SIZE_32x16,   40,   88,  200,    1
    subsprite OAM_SIZE_32x16,  104,   88,  200,    1, xflip=1
    subsprite OAM_SIZE_32x16,   72,   88,  202,    1
  File92F0_Obj_98:
    subsprite OAM_SIZE_32x16,   40,   88,  200,    2
    subsprite OAM_SIZE_32x16,  104,   88,  200,    2, xflip=1
    subsprite OAM_SIZE_32x16,   72,   88,  202,    2
  File92F0_Obj_101:
    subsprite OAM_SIZE_32x16,   40,   88,  200,    3
    subsprite OAM_SIZE_32x16,  104,   88,  200,    3, xflip=1
    subsprite OAM_SIZE_32x16,   72,   88,  202,    3

2:
File92F0_Cmds:
  File92F0_Cmd_0:
    animcmd   1,   31
    animcmd   2,   11
    animcmd   3,   32
    animcmd   2,   11
    animcmd   1,   20
    animcmd   0,  208
  File92F0_Cmd_6:
    animcmd   1,  144
    animcmd   0,  144
  File92F0_Cmd_8:
    animcmd   1,   31
    animcmd   2,   11
    animcmd   3,   53
    animcmd   2,   11
    animcmd   1,   72
  File92F0_Cmd_13:
    animcmd   0,  255
  File92F0_Cmd_14:
    animcmd   5,   31
    animcmd   6,   11
    animcmd   7,   32
    animcmd   6,   11
    animcmd   5,   20
    animcmd   4,  208
  File92F0_Cmd_20:
    animcmd   5,  144
    animcmd   4,  144
  File92F0_Cmd_22:
    animcmd   5,   31
    animcmd   6,   11
    animcmd   7,   53
    animcmd   6,   11
    animcmd   5,   72
  File92F0_Cmd_27:
    animcmd   4,  255
  File92F0_Cmd_28:
    animcmd  20,    6
    animcmd  19,    6
    animcmd  20,    6
    animcmd  21,    6
  File92F0_Cmd_32:
    animcmd  23,    6
    animcmd  22,    6
    animcmd  23,    6
    animcmd  24,    6
  File92F0_Cmd_36:
    animcmd  29,   16
    animcmd  30,    8
    animcmd  31,    8
    animcmd  32,    8
    animcmd  31,    8
    animcmd  30,    8

File92F0_Tiles:
  .incbin "data/sprite_main/92F0.4bpp"
