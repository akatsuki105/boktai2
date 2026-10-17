FileDFDE_Header:
  .2byte 749 @ palStart
  .2byte 37 @ metaspriteCount
  .2byte 23 @ animationCount
  .2byte 224 @ subspriteCount
  .2byte 46 @ cmdCount
  .2byte 256 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 772 @ offsetToAnims
  .4byte 956 @ offsetToSubsprites
  .4byte 2748 @ offsetToCmds
  .4byte 2932 @ offsetToTiles

FileDFDE_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF541, FileDFDE_Obj_0,     6,          -24,  -48,   10,   10
  pose 0xF561, FileDFDE_Obj_6,     6,          -25,  -48,    8,   10
  pose 0xF581, FileDFDE_Obj_12,    5,          -25,  -48,    8,   10
  pose 0xF5A1, FileDFDE_Obj_17,    6,          -25,  -48,    9,   11
  pose 0xF5C1, FileDFDE_Obj_23,    6,          -24,  -48,   10,   11
  pose 0xF371, FileDFDE_Obj_29,    5,          -25,  -49,   18,    0
  pose 0xF372, FileDFDE_Obj_34,    6,          -24,  -48,   17,    0
  pose 0xF373, FileDFDE_Obj_40,    7,          -25,  -49,   16,    6
  pose 0xF374, FileDFDE_Obj_47,    6,          -25,  -48,   18,    0
  pose 0xF3B1, FileDFDE_Obj_53,    5,          -26,  -47,   11,    0
  pose 0xF3B2, FileDFDE_Obj_58,    5,          -25,  -46,   11,    9
  pose 0xF3B3, FileDFDE_Obj_63,    7,          -25,  -47,   13,    0
  pose 0xF3B4, FileDFDE_Obj_70,    5,          -26,  -46,   10,    0
  pose 0xF501, FileDFDE_Obj_75,    6,          -25,  -48,    8,   10
  pose 0xF502, FileDFDE_Obj_81,    6,          -25,  -49,    9,   10
  pose 0xF503, FileDFDE_Obj_87,    6,          -25,  -49,   10,   10
  pose 0xF504, FileDFDE_Obj_93,    6,          -25,  -49,   10,   10
  pose 0x9CCF, FileDFDE_Obj_99,    6,          -25,  -48,    9,   11
  pose 0xF542, FileDFDE_Obj_105,   7,          -25,  -50,    9,   11
  pose 0xF543, FileDFDE_Obj_112,   6,          -25,  -50,    9,   11
  pose 0xF544, FileDFDE_Obj_118,   6,          -25,  -50,    9,   11
  pose 0xF511, FileDFDE_Obj_124,   6,          -25,  -50,    9,   11
  pose 0xF961, FileDFDE_Obj_130,   6,          -25,  -48,    8,   10
  pose 0xF962, FileDFDE_Obj_136,   6,          -25,  -48,    8,   10
  pose 0xF963, FileDFDE_Obj_142,   6,          -25,  -49,    7,   10
  pose 0xF9A1, FileDFDE_Obj_148,   6,          -25,  -48,    9,   11
  pose 0xF9A2, FileDFDE_Obj_154,   6,          -25,  -50,    9,   11
  pose 0xF9A3, FileDFDE_Obj_160,   6,          -25,  -50,    9,   11
  pose 0xECB1, FileDFDE_Obj_166,   7,          -25,  -48,    9,   11
  pose 0xECB2, FileDFDE_Obj_173,   6,          -25,  -50,   10,   10
  pose 0xECB3, FileDFDE_Obj_179,   6,          -25,  -49,   10,   11
  pose 0xECB4, FileDFDE_Obj_185,   7,          -25,  -48,    9,   11
  pose 0xEC71, FileDFDE_Obj_192,   6,          -25,  -48,    8,   10
  pose 0xEC72, FileDFDE_Obj_198,   7,          -25,  -49,    9,    9
  pose 0xEC73, FileDFDE_Obj_205,   6,          -25,  -48,    9,   10
  pose 0xEC74, FileDFDE_Obj_211,   6,          -25,  -48,    8,   10
  pose 0xEC75, FileDFDE_Obj_217,   7,          -25,  -48,    8,   10

FileDFDE_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB142, FileDFDE_Cmd_0,     1
  animation 0xB162, FileDFDE_Cmd_1,     1
  animation 0xB182, FileDFDE_Cmd_2,     1
  animation 0xB1A2, FileDFDE_Cmd_3,     1
  animation 0xB1C2, FileDFDE_Cmd_4,     1
  animation 0x2F79, FileDFDE_Cmd_5,     4
  animation 0x2FB9, FileDFDE_Cmd_9,     4
  animation 0xB56C, FileDFDE_Cmd_13,    2
  animation 0xB58C, FileDFDE_Cmd_15,    1
  animation 0xB5AC, FileDFDE_Cmd_16,    2
  animation 0xB5CC, FileDFDE_Cmd_18,    1
  animation 0x30B9, FileDFDE_Cmd_19,    4
  animation 0x30D9, FileDFDE_Cmd_23,    1
  animation 0x30F9, FileDFDE_Cmd_24,    4
  animation 0x3119, FileDFDE_Cmd_28,    1
  animation 0xB116, FileDFDE_Cmd_29,    4
  animation 0xB136, FileDFDE_Cmd_33,    1
  animation 0x0781, FileDFDE_Cmd_34,    3
  animation 0x07A1, FileDFDE_Cmd_37,    1
  animation 0xF898, FileDFDE_Cmd_38,    2
  animation 0x07C1, FileDFDE_Cmd_40,    3
  animation 0x07E1, FileDFDE_Cmd_43,    1
  animation 0x0801, FileDFDE_Cmd_44,    2

1:
FileDFDE_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDFDE_Obj_0:
    subsprite OAM_SIZE_8x16,    -4,  -12,   64,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,   10,    0
    subsprite OAM_SIZE_16x8,    -8,   -6,   42,    0
    subsprite OAM_SIZE_8x16,     2,  -21,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,   36,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    0,    0
  FileDFDE_Obj_6:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x16,    -1,  -19,   33,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
  FileDFDE_Obj_12:
    subsprite OAM_SIZE_8x16,    -4,  -12,   67,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   14,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   46,    0
    subsprite OAM_SIZE_8x16,    -4,  -17,   34,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    4,    0
  FileDFDE_Obj_17:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_8x16,     1,  -23,   39,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   35,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    6,    0
  FileDFDE_Obj_23:
    subsprite OAM_SIZE_8x16,    -4,  -12,   69,    0
    subsprite OAM_SIZE_16x16,   -8,  -21,   60,    0
    subsprite OAM_SIZE_16x8,    -8,   -5,   92,    0
    subsprite OAM_SIZE_8x16,     2,  -21,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,   36,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    8,    0
  FileDFDE_Obj_29:
    subsprite OAM_SIZE_16x16,   -9,  -25,  206,    0
    subsprite OAM_SIZE_8x16,    -6,  -11,  133,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  168,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,  100,    0
    subsprite OAM_SIZE_16x8,     2,  -18,  142,    0
  FileDFDE_Obj_34:
    subsprite OAM_SIZE_16x16,   -8,  -24,  206,    0
    subsprite OAM_SIZE_8x16,    -4,  -14,  134,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  170,    0
    subsprite OAM_SIZE_16x16,   -6,  -32,  102,    0
    subsprite OAM_SIZE_16x8,     1,  -19,  220,    0
    subsprite OAM_SIZE_8x8,      1,  -11,  152,    0
  FileDFDE_Obj_40:
    subsprite OAM_SIZE_16x16,   -7,  -24,  206,    0
    subsprite OAM_SIZE_16x8,    -8,  -10,  135,    0
    subsprite OAM_SIZE_8x8,     -8,   -2,  151,    0
    subsprite OAM_SIZE_16x16,   -9,  -20,  172,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,  100,    0
    subsprite OAM_SIZE_8x16,     0,  -20,  105,    0
    subsprite OAM_SIZE_8x8,      8,  -15,  143,    0
  FileDFDE_Obj_47:
    subsprite OAM_SIZE_16x16,   -8,  -23,  206,    0
    subsprite OAM_SIZE_8x16,    -3,  -10,  137,    0
    subsprite OAM_SIZE_16x16,   -9,  -19,  174,    0
    subsprite OAM_SIZE_16x16,   -6,  -32,  102,    0
    subsprite OAM_SIZE_8x16,     2,  -19,   37,    0
    subsprite OAM_SIZE_8x8,     10,  -16,  143,    0
  FileDFDE_Obj_53:
    subsprite OAM_SIZE_8x16,     3,  -22,  104,    0
    subsprite OAM_SIZE_8x16,    -5,  -11,  128,    0
    subsprite OAM_SIZE_16x16,  -10,  -20,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -31,   96,    0
    subsprite OAM_SIZE_8x8,     -7,  -16,  129,    0
  FileDFDE_Obj_58:
    subsprite OAM_SIZE_8x8,      3,  -19,  155,    0
    subsprite OAM_SIZE_16x8,    -9,   -7,  145,    0
    subsprite OAM_SIZE_16x16,   -9,  -19,  162,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,   98,    0
    subsprite OAM_SIZE_8x8,     -6,  -15,  138,    0
  FileDFDE_Obj_63:
    subsprite OAM_SIZE_8x8,      5,  -24,  207,    0
    subsprite OAM_SIZE_8x8,      0,  -23,   41,    0
    subsprite OAM_SIZE_8x16,    -1,  -10,  131,    0
    subsprite OAM_SIZE_8x8,     -9,  -10,  130,    0
    subsprite OAM_SIZE_16x16,   -9,  -20,  164,    0
    subsprite OAM_SIZE_16x16,   -6,  -31,   96,    0
    subsprite OAM_SIZE_8x8,     -4,  -16,  154,    0
  FileDFDE_Obj_70:
    subsprite OAM_SIZE_8x16,    -4,  -12,  132,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  156,    0
    subsprite OAM_SIZE_16x16,  -10,  -19,  166,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,   98,    0
    subsprite OAM_SIZE_8x8,     -5,  -15,  139,    0
  FileDFDE_Obj_75:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x16,    -1,  -19,   33,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
  FileDFDE_Obj_81:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x8,      1,  -18,   71,    0
    subsprite OAM_SIZE_16x16,   -9,  -33,  192,    0
  FileDFDE_Obj_87:
    subsprite OAM_SIZE_8x8,     -7,  -23,   40,    0
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x8,      2,  -18,   72,    0
    subsprite OAM_SIZE_16x16,   -9,  -33,  192,    0
  FileDFDE_Obj_93:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x8,     -7,  -23,   40,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x8,      2,  -18,   72,    0
    subsprite OAM_SIZE_16x16,   -9,  -33,  192,    0
  FileDFDE_Obj_99:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_8x16,     1,  -23,   39,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   35,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    6,    0
  FileDFDE_Obj_105:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -7,  -21,   70,    0
    subsprite OAM_SIZE_8x16,     1,  -25,   41,    0
    subsprite OAM_SIZE_8x8,      1,  -13,   87,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  200,    0
  FileDFDE_Obj_112:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x8,      1,  -20,   56,    0
    subsprite OAM_SIZE_16x8,    -9,  -17,   88,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  200,    0
  FileDFDE_Obj_118:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x8,      1,  -20,   56,    0
    subsprite OAM_SIZE_16x8,    -9,  -17,   88,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  196,    0
  FileDFDE_Obj_124:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x8,      1,  -20,   56,    0
    subsprite OAM_SIZE_16x8,    -9,  -17,   88,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  198,    0
  FileDFDE_Obj_130:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x16,    -1,  -19,   33,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
  FileDFDE_Obj_136:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x16,    -1,  -19,   33,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
  FileDFDE_Obj_142:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_8x16,    -1,  -19,   33,    0
    subsprite OAM_SIZE_16x16,   -9,  -33,  192,    0
  FileDFDE_Obj_148:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_8x16,     1,  -23,   39,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   35,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    6,    0
  FileDFDE_Obj_154:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_8x16,     1,  -23,   39,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   35,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  194,    0
  FileDFDE_Obj_160:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_8x16,     1,  -23,   39,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,   35,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  196,    0
  FileDFDE_Obj_166:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,     1,  -25,   41,    0
    subsprite OAM_SIZE_8x16,    -8,  -21,  141,    0
    subsprite OAM_SIZE_8x8,      0,  -13,  158,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    6,    0
  FileDFDE_Obj_173:
    subsprite OAM_SIZE_8x16,    -4,  -11,   62,    0
    subsprite OAM_SIZE_8x8,      2,  -23,   73,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   90,    0
    subsprite OAM_SIZE_16x8,    -9,  -20,  204,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  202,    0
  FileDFDE_Obj_179:
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x8,      2,  -22,   73,    0
    subsprite OAM_SIZE_16x8,    -9,  -19,  204,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  202,    0
  FileDFDE_Obj_185:
    subsprite OAM_SIZE_8x16,     1,  -25,   41,    0
    subsprite OAM_SIZE_8x16,    -3,  -11,   68,    0
    subsprite OAM_SIZE_16x16,   -9,  -21,   58,    0
    subsprite OAM_SIZE_16x8,    -9,   -5,   90,    0
    subsprite OAM_SIZE_8x16,    -8,  -21,  141,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  158,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    6,    0
  FileDFDE_Obj_192:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -23,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
    subsprite OAM_SIZE_8x16,     0,  -18,   66,    0
  FileDFDE_Obj_198:
    subsprite OAM_SIZE_8x8,     -9,  -25,   94,    0
    subsprite OAM_SIZE_8x16,    -3,  -19,   63,    0
    subsprite OAM_SIZE_8x8,     -3,   -3,   95,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -7,   44,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,    2,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  159,    0
  FileDFDE_Obj_205:
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x8,     -9,  -24,   94,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  159,    0
  FileDFDE_Obj_211:
    subsprite OAM_SIZE_8x8,     -9,  -23,   94,    0
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
    subsprite OAM_SIZE_8x16,     0,  -18,   66,    0
  FileDFDE_Obj_217:
    subsprite OAM_SIZE_8x8,     -9,  -23,   94,    0
    subsprite OAM_SIZE_8x16,    -3,  -12,   65,    0
    subsprite OAM_SIZE_8x16,    -9,  -22,   38,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,   12,    0
    subsprite OAM_SIZE_16x8,    -9,   -6,   44,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,    2,    0
    subsprite OAM_SIZE_8x16,     0,  -18,   66,    0

2:
FileDFDE_Cmds:
  FileDFDE_Cmd_0:
    animcmd   0,   1
  FileDFDE_Cmd_1:
    animcmd   1,   1
  FileDFDE_Cmd_2:
    animcmd   2,   1
  FileDFDE_Cmd_3:
    animcmd   3,   1
  FileDFDE_Cmd_4:
    animcmd   4,   1
  FileDFDE_Cmd_5:
    animcmd   5,   9
    animcmd   6,  11
    animcmd   7,   9
    animcmd   8,  11
  FileDFDE_Cmd_9:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileDFDE_Cmd_13:
    animcmd  22,   9
    animcmd  24,   9
  FileDFDE_Cmd_15:
    animcmd  24,   1
  FileDFDE_Cmd_16:
    animcmd  25,   9
    animcmd  27,   9
  FileDFDE_Cmd_18:
    animcmd  27,   1
  FileDFDE_Cmd_19:
    animcmd  13,  14
    animcmd  14,   9
    animcmd  15,   9
    animcmd  16,  14
  FileDFDE_Cmd_23:
    animcmd  16,   1
  FileDFDE_Cmd_24:
    animcmd  17,  14
    animcmd  18,   9
    animcmd  19,   9
    animcmd  20,  14
  FileDFDE_Cmd_28:
    animcmd  20,   1
  FileDFDE_Cmd_29:
    animcmd  17,  14
    animcmd  18,   9
    animcmd  19,   9
    animcmd  21,  14
  FileDFDE_Cmd_33:
    animcmd  21,   1
  FileDFDE_Cmd_34:
    animcmd   1,   4
    animcmd  32,   4
    animcmd  33,   4
  FileDFDE_Cmd_37:
    animcmd  34,  24
  FileDFDE_Cmd_38:
    animcmd  32,   6
    animcmd   1,   6
  FileDFDE_Cmd_40:
    animcmd   3,   4
    animcmd  28,   4
    animcmd  29,   4
  FileDFDE_Cmd_43:
    animcmd  30,  24
  FileDFDE_Cmd_44:
    animcmd  31,   6
    animcmd   3,   6

FileDFDE_Tiles:
  .incbin "data/spriteset/rita.4bpp"
