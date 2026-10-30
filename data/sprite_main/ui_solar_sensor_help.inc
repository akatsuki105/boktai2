FileDF11_Header:
  .2byte 674 @ palStart
  .2byte 24 @ metaspriteCount
  .2byte 5 @ animationCount
  .2byte 165 @ subspriteCount
  .2byte 13 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 512 @ offsetToAnims
  .4byte 552 @ offsetToSubsprites
  .4byte 1872 @ offsetToCmds
  .4byte 1924 @ offsetToTiles

FileDF11_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xBC59, FileDF11_Obj_0,     1,            0,    0,  200,  100
  pose 0x3C94, FileDF11_Obj_1,     1,            0,    0,  200,  100
  pose 0x0B99, FileDF11_Obj_2,     4,            0,    0,  216,  154
  pose 0x0B9A, FileDF11_Obj_6,     2,            0,    0,  216,  186
  pose 0x0B9B, FileDF11_Obj_8,     2,            0,    0,  216,  186
  pose 0x3C10, FileDF11_Obj_10,    4,            0,    0,  147,  154
  pose 0x3C11, FileDF11_Obj_14,    4,            0,    0,  147,  154
  pose 0x3C12, FileDF11_Obj_18,    4,            0,    0,  147,  154
  pose 0x3C13, FileDF11_Obj_22,    4,            0,    0,  147,  154
  pose 0x5C55, FileDF11_Obj_26,    5,            0,    0,  200,  164
  pose 0x5C56, FileDF11_Obj_31,    12,           0,    0,  216,  164
  pose 0xFFFD, FileDF11_Obj_43,    5,            0,    0,   88,  172
  pose 0xFFFE, FileDF11_Obj_48,    4,            0,    0,   88,  172
  pose 0xD27B, FileDF11_Obj_52,    7,            0,    0,   88,  172
  pose 0xD27C, FileDF11_Obj_59,    7,            0,    0,   88,  172
  pose 0x69DB, FileDF11_Obj_66,    10,           0,   -8,  200,   24
  pose 0x69DC, FileDF11_Obj_76,    11,           0,   -8,  208,   24
  pose 0x69DD, FileDF11_Obj_87,    14,          -8,   -8,  232,   24
  pose 0x69DF, FileDF11_Obj_101,   14,          -8,   -8,  232,   24
  pose 0x69E0, FileDF11_Obj_115,   11,           0,   -8,  208,   24
  pose 0x69E1, FileDF11_Obj_126,   11,           0,   -8,  208,   24
  pose 0x69E3, FileDF11_Obj_137,   11,           0,   -8,  208,   24
  pose 0x3B9F, FileDF11_Obj_148,   5,            0,   -8,  160,   24
  pose 0x3BA0, FileDF11_Obj_153,   12,           0,   -8,  216,   24

FileDF11_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x67FE, FileDF11_Cmd_0,     2
  animation 0x0AF0, FileDF11_Cmd_2,     2
  animation 0x405B, FileDF11_Cmd_4,     3
  animation 0xF9DE, FileDF11_Cmd_7,     4
  animation 0x22E1, FileDF11_Cmd_11,    2

1:
FileDF11_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDF11_Obj_0:
    subsprite OAM_SIZE_32x32,  168,   68,    6,    0
  FileDF11_Obj_1:
    subsprite OAM_SIZE_32x32,  168,   68,   70,    0
  FileDF11_Obj_2:
    subsprite OAM_SIZE_32x32,  152,   90,  136,    0
    subsprite OAM_SIZE_32x32,  184,   90,  136,    0, xflip=1
    subsprite OAM_SIZE_32x32,  152,  122,  136,    0, yflip=1
    subsprite OAM_SIZE_32x32,  184,  122,  136,    0, xflip=1, yflip=1
  FileDF11_Obj_6:
    subsprite OAM_SIZE_64x32,  152,   90,  128,    0
    subsprite OAM_SIZE_64x32,  152,  122,  128,    0, xflip=1, yflip=1
  FileDF11_Obj_8:
    subsprite OAM_SIZE_64x32,  152,  122,  128,    0, yflip=1
    subsprite OAM_SIZE_64x32,  152,   90,  128,    0, xflip=1
  FileDF11_Obj_10:
    subsprite OAM_SIZE_32x16,   99,  106,    0,    0
    subsprite OAM_SIZE_16x16,  131,  106,    4,    0
    subsprite OAM_SIZE_32x16,   99,  122,    0,    0, yflip=1
    subsprite OAM_SIZE_16x16,  131,  122,    4,    0, yflip=1
  FileDF11_Obj_14:
    subsprite OAM_SIZE_32x16,   99,  106,   32,    0
    subsprite OAM_SIZE_16x16,  131,  106,   36,    0
    subsprite OAM_SIZE_32x16,   99,  122,   32,    0, yflip=1
    subsprite OAM_SIZE_16x16,  131,  122,   36,    0, yflip=1
  FileDF11_Obj_18:
    subsprite OAM_SIZE_32x16,   99,  106,   64,    0
    subsprite OAM_SIZE_16x16,  131,  106,   68,    0
    subsprite OAM_SIZE_32x16,   99,  122,   64,    0, yflip=1
    subsprite OAM_SIZE_16x16,  131,  122,   68,    0, yflip=1
  FileDF11_Obj_22:
    subsprite OAM_SIZE_32x16,   99,  106,   96,    0
    subsprite OAM_SIZE_16x16,  131,  106,  100,    0
    subsprite OAM_SIZE_32x16,   99,  122,   96,    0, yflip=1
    subsprite OAM_SIZE_16x16,  131,  122,  100,    0, yflip=1
  FileDF11_Obj_26:
    subsprite OAM_SIZE_16x32,  168,  100,   12,    1
    subsprite OAM_SIZE_16x32,  184,  100,   12,    1, xflip=1
    subsprite OAM_SIZE_32x16,  168,  132,   76,    0
    subsprite OAM_SIZE_8x8,    176,  148,  109,    0
    subsprite OAM_SIZE_8x8,    184,  148,  109,    0, xflip=1
  FileDF11_Obj_31:
    subsprite OAM_SIZE_16x32,  168,  100,   14,    0
    subsprite OAM_SIZE_16x32,  184,  100,   14,    0, xflip=1
    subsprite OAM_SIZE_32x16,  168,  132,   76,    0
    subsprite OAM_SIZE_8x8,    176,  148,  109,    0
    subsprite OAM_SIZE_8x8,    184,  148,  109,    0, xflip=1
    subsprite OAM_SIZE_8x8,    160,   92,   59,    0
    subsprite OAM_SIZE_16x16,  152,  108,   74,    0
    subsprite OAM_SIZE_8x8,    160,  132,   59,    0, yflip=1
    subsprite OAM_SIZE_16x16,  176,   84,  106,    0
    subsprite OAM_SIZE_8x8,    200,   92,   59,    0, xflip=1
    subsprite OAM_SIZE_16x16,  200,  108,   74,    0, xflip=1
    subsprite OAM_SIZE_8x8,    200,  132,   59,    0, xflip=1, yflip=1
  FileDF11_Obj_43:
    subsprite OAM_SIZE_32x32,   32,  108,  124,    0
    subsprite OAM_SIZE_32x8,    32,  140,  188,    0
    subsprite OAM_SIZE_32x8,    56,  140,  188,    0, xflip=1
    subsprite OAM_SIZE_32x32,   56,  108,  124,    0, xflip=1
    subsprite OAM_SIZE_8x16,    50,  108,   42,    0
  FileDF11_Obj_48:
    subsprite OAM_SIZE_32x32,   32,  108,  124,    0
    subsprite OAM_SIZE_32x8,    32,  140,  188,    0
    subsprite OAM_SIZE_32x8,    56,  140,  188,    0, xflip=1
    subsprite OAM_SIZE_32x32,   56,  108,  124,    0, xflip=1
  FileDF11_Obj_52:
    subsprite OAM_SIZE_32x32,   32,  108,  124,    0
    subsprite OAM_SIZE_32x8,    32,  140,  188,    0
    subsprite OAM_SIZE_32x8,    56,  140,  188,    0, xflip=1
    subsprite OAM_SIZE_32x32,   56,  108,  124,    0, xflip=1
    subsprite OAM_SIZE_16x16,   48,   89,   10,    0
    subsprite OAM_SIZE_8x16,    50,  108,   42,    0
    subsprite OAM_SIZE_8x16,    64,   89,   11,    0
  FileDF11_Obj_59:
    subsprite OAM_SIZE_32x32,   32,  108,  124,    0
    subsprite OAM_SIZE_32x8,    32,  140,  188,    0
    subsprite OAM_SIZE_32x8,    56,  140,  188,    0, xflip=1
    subsprite OAM_SIZE_32x32,   56,  108,  124,    0, xflip=1
    subsprite OAM_SIZE_16x16,   48,   89,   10,    0, xflip=1
    subsprite OAM_SIZE_8x16,    50,  108,   42,    0
    subsprite OAM_SIZE_8x16,    64,   89,   11,    0, xflip=1
  FileDF11_Obj_66:
    subsprite OAM_SIZE_16x16,   40,    8,  360,    2
    subsprite OAM_SIZE_16x16,   56,    8,  256,    2
    subsprite OAM_SIZE_16x16,   72,    8,  258,    2
    subsprite OAM_SIZE_16x16,   88,    8,  260,    2
    subsprite OAM_SIZE_16x16,  104,    8,  262,    2
    subsprite OAM_SIZE_16x16,  120,    8,  264,    2
    subsprite OAM_SIZE_16x16,  136,    8,  266,    2
    subsprite OAM_SIZE_16x16,  152,    8,  268,    2
    subsprite OAM_SIZE_16x16,  168,    8,  270,    2
    subsprite OAM_SIZE_16x16,  184,    8,  362,    2
  FileDF11_Obj_76:
    subsprite OAM_SIZE_16x16,   32,    8,  360,    2
    subsprite OAM_SIZE_16x16,   48,    8,  256,    2
    subsprite OAM_SIZE_16x16,   64,    8,  258,    2
    subsprite OAM_SIZE_16x16,   80,    8,  260,    2
    subsprite OAM_SIZE_16x16,   96,    8,  262,    2
    subsprite OAM_SIZE_16x16,  112,    8,  264,    2
    subsprite OAM_SIZE_16x16,  128,    8,  266,    2
    subsprite OAM_SIZE_16x16,  144,    8,  288,    2
    subsprite OAM_SIZE_16x16,  160,    8,  290,    2
    subsprite OAM_SIZE_16x16,  176,    8,  292,    2
    subsprite OAM_SIZE_16x16,  192,    8,  362,    2
  FileDF11_Obj_87:
    subsprite OAM_SIZE_16x16,    8,    8,  360,    2
    subsprite OAM_SIZE_16x16,   24,    8,  256,    2
    subsprite OAM_SIZE_16x16,   40,    8,  258,    2
    subsprite OAM_SIZE_16x16,   56,    8,  260,    2
    subsprite OAM_SIZE_16x16,   72,    8,  262,    2
    subsprite OAM_SIZE_16x16,   88,    8,  264,    2
    subsprite OAM_SIZE_16x16,  104,    8,  266,    2
    subsprite OAM_SIZE_16x16,  168,    8,  288,    2
    subsprite OAM_SIZE_16x16,  120,    8,  294,    2
    subsprite OAM_SIZE_16x16,  136,    8,  296,    2
    subsprite OAM_SIZE_16x16,  152,    8,  298,    2
    subsprite OAM_SIZE_16x16,  184,    8,  332,    2
    subsprite OAM_SIZE_16x16,  200,    8,  334,    2
    subsprite OAM_SIZE_16x16,  216,    8,  362,    2
  FileDF11_Obj_101:
    subsprite OAM_SIZE_16x16,    8,    8,  360,    2
    subsprite OAM_SIZE_16x16,   24,    8,  256,    2
    subsprite OAM_SIZE_16x16,   40,    8,  258,    2
    subsprite OAM_SIZE_16x16,   56,    8,  260,    2
    subsprite OAM_SIZE_16x16,   72,    8,  262,    2
    subsprite OAM_SIZE_16x16,   88,    8,  264,    2
    subsprite OAM_SIZE_16x16,  104,    8,  266,    2
    subsprite OAM_SIZE_16x16,  120,    8,  288,    2
    subsprite OAM_SIZE_16x16,  136,    8,  328,    2
    subsprite OAM_SIZE_16x16,  152,    8,  330,    2
    subsprite OAM_SIZE_16x16,  168,    8,  364,    2
    subsprite OAM_SIZE_16x16,  184,    8,  356,    2
    subsprite OAM_SIZE_16x16,  200,    8,  330,    2
    subsprite OAM_SIZE_16x16,  216,    8,  362,    2
  FileDF11_Obj_115:
    subsprite OAM_SIZE_16x16,   32,    8,  360,    2
    subsprite OAM_SIZE_16x16,   48,    8,  256,    2
    subsprite OAM_SIZE_16x16,   64,    8,  258,    2
    subsprite OAM_SIZE_16x16,   80,    8,  260,    2
    subsprite OAM_SIZE_16x16,   96,    8,  262,    2
    subsprite OAM_SIZE_16x16,  112,    8,  264,    2
    subsprite OAM_SIZE_16x16,  128,    8,  266,    2
    subsprite OAM_SIZE_16x16,  144,    8,  268,    2
    subsprite OAM_SIZE_16x16,  160,    8,  352,    2
    subsprite OAM_SIZE_16x16,  176,    8,  354,    2
    subsprite OAM_SIZE_16x16,  192,    8,  362,    2
  FileDF11_Obj_126:
    subsprite OAM_SIZE_16x16,   32,    8,  360,    2
    subsprite OAM_SIZE_16x16,   48,    8,  256,    2
    subsprite OAM_SIZE_16x16,   64,    8,  258,    2
    subsprite OAM_SIZE_16x16,   80,    8,  260,    2
    subsprite OAM_SIZE_16x16,   96,    8,  262,    2
    subsprite OAM_SIZE_16x16,  112,    8,  264,    2
    subsprite OAM_SIZE_16x16,  128,    8,  266,    2
    subsprite OAM_SIZE_16x16,  144,    8,  268,    2
    subsprite OAM_SIZE_16x16,  160,    8,  320,    2
    subsprite OAM_SIZE_16x16,  176,    8,  322,    2
    subsprite OAM_SIZE_16x16,  192,    8,  362,    2
  FileDF11_Obj_137:
    subsprite OAM_SIZE_16x16,   32,    8,  360,    2
    subsprite OAM_SIZE_16x16,   48,    8,  256,    2
    subsprite OAM_SIZE_16x16,   64,    8,  258,    2
    subsprite OAM_SIZE_16x16,   80,    8,  260,    2
    subsprite OAM_SIZE_16x16,   96,    8,  262,    2
    subsprite OAM_SIZE_16x16,  112,    8,  264,    2
    subsprite OAM_SIZE_16x16,  128,    8,  266,    2
    subsprite OAM_SIZE_16x16,  144,    8,  268,    2
    subsprite OAM_SIZE_16x16,  160,    8,  324,    2
    subsprite OAM_SIZE_16x16,  176,    8,  326,    2
    subsprite OAM_SIZE_16x16,  192,    8,  362,    2
  FileDF11_Obj_148:
    subsprite OAM_SIZE_16x16,   80,    8,  360,    2
    subsprite OAM_SIZE_16x16,  144,    8,  362,    2
    subsprite OAM_SIZE_16x16,   96,    8,  302,    2
    subsprite OAM_SIZE_16x16,  112,    8,  324,    2
    subsprite OAM_SIZE_16x16,  128,    8,  300,    2
  FileDF11_Obj_153:
    subsprite OAM_SIZE_16x16,   24,    8,  360,    2
    subsprite OAM_SIZE_16x16,   40,    8,  256,    2
    subsprite OAM_SIZE_16x16,   56,    8,  258,    2
    subsprite OAM_SIZE_16x16,   72,    8,  260,    2
    subsprite OAM_SIZE_16x16,   88,    8,  262,    2
    subsprite OAM_SIZE_16x16,  104,    8,  264,    2
    subsprite OAM_SIZE_16x16,  120,    8,  266,    2
    subsprite OAM_SIZE_16x16,  136,    8,  268,    2
    subsprite OAM_SIZE_16x16,  200,    8,  362,    2
    subsprite OAM_SIZE_16x16,  152,    8,  358,    2
    subsprite OAM_SIZE_16x16,  168,    8,  358,    2
    subsprite OAM_SIZE_16x16,  184,    8,  358,    2

2:
FileDF11_Cmds:
  FileDF11_Cmd_0:
    animcmd  11,  16
    animcmd  12,  16
  FileDF11_Cmd_2:
    animcmd  13,  12
    animcmd  14,  12
  FileDF11_Cmd_4:
    animcmd   2,  26
    animcmd   3,  26
    animcmd   4,  26
  FileDF11_Cmd_7:
    animcmd   5,  10
    animcmd   6,  10
    animcmd   7,  10
    animcmd   8,  10
  FileDF11_Cmd_11:
    animcmd   9,  26
    animcmd  10,  26

FileDF11_Tiles:
  .incbin "data/sprite_main/ui_solar_sensor_help.4bpp"
