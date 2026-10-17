File414C_Header:
  .2byte 671 @ palStart
  .2byte 43 @ metaspriteCount
  .2byte 3 @ animationCount
  .2byte 107 @ subspriteCount
  .2byte 9 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 892 @ offsetToAnims
  .4byte 916 @ offsetToSubsprites
  .4byte 1772 @ offsetToCmds
  .4byte 1808 @ offsetToTiles

File414C_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x8659, File414C_Obj_0,     1,            0,    0,   39,  112
  pose 0x865A, File414C_Obj_1,     1,            0,    0,   36,  105
  pose 0x865B, File414C_Obj_2,     1,            0,    0,   37,  105
  pose 0x865C, File414C_Obj_3,     1,            0,    0,   40,  117
  pose 0x865D, File414C_Obj_4,     1,            0,    0,   40,  117
  pose 0x0922, File414C_Obj_5,     3,            0,    0,   48,  121
  pose 0x0962, File414C_Obj_8,     3,          -16,    0,   56,  137
  pose 0x09A2, File414C_Obj_11,    3,          -16,    0,   64,  137
  pose 0x09E2, File414C_Obj_14,    3,          -24,    0,   72,  137
  pose 0xEE75, File414C_Obj_17,    6,            0,    0,  208,  141
  pose 0xEE76, File414C_Obj_23,    6,            0,    0,  208,  141
  pose 0x1146, File414C_Obj_29,    2,           -5,    0,  229,  120
  pose 0x1147, File414C_Obj_31,    2,           -5,    0,  229,  120
  pose 0x1148, File414C_Obj_33,    2,           -5,    0,  229,  120
  pose 0x1086, File414C_Obj_35,    2,           -5,    0,  229,  120
  pose 0x1087, File414C_Obj_37,    2,           -5,    0,  229,  120
  pose 0x1088, File414C_Obj_39,    2,           -5,    0,  229,  120
  pose 0x1066, File414C_Obj_41,    2,           -5,    0,  229,  120
  pose 0x1067, File414C_Obj_43,    2,           -5,    0,  229,  120
  pose 0x1068, File414C_Obj_45,    2,           -5,    0,  229,  120
  pose 0x2270, File414C_Obj_47,    2,          -32,  -32,   40,   32
  pose 0x226A, File414C_Obj_49,    1,          -32,  -32,   32,   32
  pose 0x1B45, File414C_Obj_50,    2,          -16,  -16,   24,   16
  pose 0x7D34, File414C_Obj_52,    1,          -39,  -48,   25,   16
  pose 0x84F8, File414C_Obj_53,    1,          -40,  -48,   24,   16
  pose 0x949E, File414C_Obj_54,    1,          -12,  -21,    4,    0
  pose 0x949F, File414C_Obj_55,    1,          -12,  -21,    4,    0
  pose 0x94A0, File414C_Obj_56,    1,          -12,  -21,    4,    0
  pose 0x94A1, File414C_Obj_57,    1,          -12,  -21,    4,    0
  pose 0x94A2, File414C_Obj_58,    1,          -12,  -21,    4,    0
  pose 0x94A3, File414C_Obj_59,    1,          -12,  -21,    4,    0
  pose 0x94A4, File414C_Obj_60,    1,          -12,  -21,    4,    0
  pose 0x94A5, File414C_Obj_61,    1,          -12,  -21,    4,    0
  pose 0x94A6, File414C_Obj_62,    1,          -12,  -21,    4,    0
  pose 0x94A7, File414C_Obj_63,    1,          -12,  -21,    4,    0
  pose 0x4B2E, File414C_Obj_64,    1,          -16,  -16,   16,   16
  pose 0x4B34, File414C_Obj_65,    1,            0,  -16,  128,   16
  pose 0xF09B, File414C_Obj_66,    9,          -16,  -16,  128,   16
  pose 0x8679, File414C_Obj_75,    7,          -12,  -16,  100,   16
  pose 0x075D, File414C_Obj_82,    9,          -16,  -16,  128,   16
  pose 0x6F6B, File414C_Obj_91,    7,          -16,  -16,  128,   16
  pose 0x37C7, File414C_Obj_98,    7,          -12,  -16,  100,   16
  pose 0xA4A4, File414C_Obj_105,   2,            0,    0,  133,   96

File414C_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB088, File414C_Cmd_0,     3
  animation 0xB082, File414C_Cmd_3,     3
  animation 0xB081, File414C_Cmd_6,     3

1:
File414C_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File414C_Obj_0:
    subsprite OAM_SIZE_8x16,    31,  104,    4,    0
  File414C_Obj_1:
    subsprite OAM_SIZE_8x32,    28,   97,   40,    0
  File414C_Obj_2:
    subsprite OAM_SIZE_8x32,    29,   97,   40,    0, xflip=1
  File414C_Obj_3:
    subsprite OAM_SIZE_8x8,     32,  109,    5,    0
  File414C_Obj_4:
    subsprite OAM_SIZE_8x8,     32,  109,   21,    0
  File414C_Obj_5:
    subsprite OAM_SIZE_16x16,   24,  105,   10,    0
    subsprite OAM_SIZE_8x16,    16,  105,    6,    0
    subsprite OAM_SIZE_8x16,    40,  105,    6,    0, xflip=1
  File414C_Obj_8:
    subsprite OAM_SIZE_32x16,   16,  105,    9,    0
    subsprite OAM_SIZE_8x16,     8,  105,    6,    0
    subsprite OAM_SIZE_8x16,    48,  105,    6,    0, xflip=1
  File414C_Obj_11:
    subsprite OAM_SIZE_32x16,   16,  105,    9,    0
    subsprite OAM_SIZE_16x16,    0,  105,    7,    0
    subsprite OAM_SIZE_16x16,   48,  105,    7,    0, xflip=1
  File414C_Obj_14:
    subsprite OAM_SIZE_32x16,    8,  105,    8,    0
    subsprite OAM_SIZE_32x16,   40,  105,   12,    0
    subsprite OAM_SIZE_16x16,   -8,  105,    8,    0
  File414C_Obj_17:
    subsprite OAM_SIZE_32x8,    32,  109,    0,    0
    subsprite OAM_SIZE_32x8,    64,  109,    0,    0
    subsprite OAM_SIZE_32x8,    96,  109,    0,    0
    subsprite OAM_SIZE_32x8,   128,  109,    0,    0
    subsprite OAM_SIZE_32x8,   160,  109,    0,    0
    subsprite OAM_SIZE_16x8,   192,  109,   94,    0
  File414C_Obj_23:
    subsprite OAM_SIZE_32x8,    32,  109,   16,    0
    subsprite OAM_SIZE_32x8,    64,  109,   16,    0
    subsprite OAM_SIZE_32x8,    96,  109,   16,    0
    subsprite OAM_SIZE_32x8,   128,  109,   16,    0
    subsprite OAM_SIZE_32x8,   160,  109,   16,    0
    subsprite OAM_SIZE_16x8,   192,  109,   16,    0
  File414C_Obj_29:
    subsprite OAM_SIZE_16x16,   11,  104,   32,    1
    subsprite OAM_SIZE_16x16,  213,  104,   32,    1
  File414C_Obj_31:
    subsprite OAM_SIZE_16x16,   11,  104,   34,    1
    subsprite OAM_SIZE_16x16,  213,  104,   34,    1
  File414C_Obj_33:
    subsprite OAM_SIZE_16x16,  213,  104,   36,    1
    subsprite OAM_SIZE_16x16,   11,  104,   36,    1
  File414C_Obj_35:
    subsprite OAM_SIZE_16x16,   11,  104,   64,    1
    subsprite OAM_SIZE_16x16,  213,  104,   64,    1
  File414C_Obj_37:
    subsprite OAM_SIZE_16x16,  213,  104,   66,    1
    subsprite OAM_SIZE_16x16,   11,  104,   66,    1
  File414C_Obj_39:
    subsprite OAM_SIZE_16x16,   11,  104,   68,    1
    subsprite OAM_SIZE_16x16,  213,  104,   68,    1
  File414C_Obj_41:
    subsprite OAM_SIZE_16x16,  213,  104,   96,    1
    subsprite OAM_SIZE_16x16,   11,  104,   96,    1
  File414C_Obj_43:
    subsprite OAM_SIZE_16x16,   11,  104,   98,    1
    subsprite OAM_SIZE_16x16,  213,  104,   98,    1
  File414C_Obj_45:
    subsprite OAM_SIZE_16x16,  213,  104,  100,    1
    subsprite OAM_SIZE_16x16,   11,  104,  100,    1
  File414C_Obj_47:
    subsprite OAM_SIZE_32x8,     0,    0,  128,    1
    subsprite OAM_SIZE_8x8,     32,    0,  132,    1
  File414C_Obj_49:
    subsprite OAM_SIZE_32x8,     0,    0,  144,    1
  File414C_Obj_50:
    subsprite OAM_SIZE_16x8,     0,    0,  160,    1
    subsprite OAM_SIZE_8x8,     16,    0,  162,    1
  File414C_Obj_52:
    subsprite OAM_SIZE_32x16,   -7,  -16,   73,    0
  File414C_Obj_53:
    subsprite OAM_SIZE_32x16,   -8,  -16,   41,    0
  File414C_Obj_54:
    subsprite OAM_SIZE_8x8,     -4,  -13,   45,    0
  File414C_Obj_55:
    subsprite OAM_SIZE_8x8,     -4,  -13,   46,    0
  File414C_Obj_56:
    subsprite OAM_SIZE_8x8,     -4,  -13,   47,    0
  File414C_Obj_57:
    subsprite OAM_SIZE_8x8,     -4,  -13,   61,    0
  File414C_Obj_58:
    subsprite OAM_SIZE_8x8,     -4,  -13,   62,    0
  File414C_Obj_59:
    subsprite OAM_SIZE_8x8,     -4,  -13,   63,    0
  File414C_Obj_60:
    subsprite OAM_SIZE_8x8,     -4,  -13,   77,    0
  File414C_Obj_61:
    subsprite OAM_SIZE_8x8,     -4,  -13,   78,    0
  File414C_Obj_62:
    subsprite OAM_SIZE_8x8,     -4,  -13,   79,    0
  File414C_Obj_63:
    subsprite OAM_SIZE_8x8,     -4,  -13,   93,    0
  File414C_Obj_64:
    subsprite OAM_SIZE_16x16,    0,    0,  104,    2
  File414C_Obj_65:
    subsprite OAM_SIZE_16x16,  112,    0,  106,    2
  File414C_Obj_66:
    subsprite OAM_SIZE_8x16,    96,    0,  203,    2, xflip=1
    subsprite OAM_SIZE_8x16,    24,    0,  203,    2
    subsprite OAM_SIZE_8x16,    48,    0,  204,    2
    subsprite OAM_SIZE_8x16,    72,    0,  204,    2
    subsprite OAM_SIZE_16x16,   80,    0,  206,    2
    subsprite OAM_SIZE_16x16,   32,    0,  108,    2
    subsprite OAM_SIZE_16x16,   56,    0,  110,    2
    subsprite OAM_SIZE_16x16,    0,    0,  236,    2
    subsprite OAM_SIZE_16x16,  112,    0,  238,    2
  File414C_Obj_75:
    subsprite OAM_SIZE_8x16,    36,    0,  204,    2
    subsprite OAM_SIZE_8x16,    60,    0,  204,    2
    subsprite OAM_SIZE_16x16,   68,    0,  206,    2
    subsprite OAM_SIZE_16x16,   20,    0,  136,    2
    subsprite OAM_SIZE_16x16,   44,    0,  138,    2
    subsprite OAM_SIZE_16x16,    4,    0,  203,    2
    subsprite OAM_SIZE_16x16,   84,    0,  203,    2, xflip=1
  File414C_Obj_82:
    subsprite OAM_SIZE_8x16,    24,    0,  203,    2
    subsprite OAM_SIZE_8x16,    48,    0,  204,    2
    subsprite OAM_SIZE_8x16,    72,    0,  204,    2
    subsprite OAM_SIZE_16x16,   80,    0,  206,    2
    subsprite OAM_SIZE_8x16,    96,    0,  203,    2, xflip=1
    subsprite OAM_SIZE_16x16,   32,    0,  140,    2
    subsprite OAM_SIZE_16x16,   56,    0,  142,    2
    subsprite OAM_SIZE_16x16,  112,    0,  238,    2
    subsprite OAM_SIZE_16x16,    0,    0,  236,    2
  File414C_Obj_91:
    subsprite OAM_SIZE_16x16,   40,    0,  172,    2
    subsprite OAM_SIZE_16x16,   72,    0,  174,    2
    subsprite OAM_SIZE_16x16,   56,    0,  204,    2
    subsprite OAM_SIZE_16x16,   24,    0,  203,    2
    subsprite OAM_SIZE_16x16,   88,    0,  203,    2, xflip=1
    subsprite OAM_SIZE_16x16,  112,    0,  238,    2
    subsprite OAM_SIZE_16x16,    0,    0,  236,    2
  File414C_Obj_98:
    subsprite OAM_SIZE_8x16,    36,    0,  204,    2
    subsprite OAM_SIZE_8x16,    60,    0,  204,    2
    subsprite OAM_SIZE_16x16,   68,    0,  206,    2
    subsprite OAM_SIZE_16x16,   20,    0,  168,    2
    subsprite OAM_SIZE_16x16,   44,    0,  170,    2
    subsprite OAM_SIZE_16x16,    4,    0,  203,    2
    subsprite OAM_SIZE_16x16,   84,    0,  203,    2, xflip=1
  File414C_Obj_105:
    subsprite OAM_SIZE_16x8,   109,   80,  200,    2
    subsprite OAM_SIZE_8x8,    125,   80,  202,    2

2:
File414C_Cmds:
  File414C_Cmd_0:
    animcmd  11,  7
    animcmd  12,  7
    animcmd  13,  7
  File414C_Cmd_3:
    animcmd  14,  6
    animcmd  15,  6
    animcmd  16,  6
  File414C_Cmd_6:
    animcmd  17,  5
    animcmd  18,  5
    animcmd  19,  5

File414C_Tiles:
  .incbin "data/spriteset/ui_misc.4bpp"
