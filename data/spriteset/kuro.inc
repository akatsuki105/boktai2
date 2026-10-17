FileE00E_Header:
  .2byte 655 @ palStart
  .2byte 76 @ metaspriteCount
  .2byte 33 @ animationCount
  .2byte 179 @ subspriteCount
  .2byte 84 @ cmdCount
  .2byte 512 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 1552 @ offsetToAnims
  .4byte 1816 @ offsetToSubsprites
  .4byte 3248 @ offsetToCmds
  .4byte 3584 @ offsetToTiles

FileE00E_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF559, FileE00E_Obj_0,     2,          -24,  -34,    8,   14
  pose 0xF579, FileE00E_Obj_2,     3,          -25,  -35,   15,   13
  pose 0xF599, FileE00E_Obj_5,     4,          -24,  -29,   16,    3
  pose 0xF5B9, FileE00E_Obj_9,     3,          -24,  -29,   16,    3
  pose 0xF5D9, FileE00E_Obj_12,    1,          -24,  -29,    8,    3
  pose 0xFC49, FileE00E_Obj_13,    3,          -25,  -27,   15,    5
  pose 0xFC4A, FileE00E_Obj_16,    3,          -25,  -28,   15,    4
  pose 0xFC4B, FileE00E_Obj_19,    3,          -25,  -27,   15,    5
  pose 0xFC4C, FileE00E_Obj_22,    3,          -25,  -28,   15,    4
  pose 0xF389, FileE00E_Obj_25,    3,          -25,  -28,   15,    4
  pose 0xF38A, FileE00E_Obj_28,    3,          -28,  -29,   12,    3
  pose 0xF38B, FileE00E_Obj_31,    3,          -28,  -33,   12,    7
  pose 0xF38C, FileE00E_Obj_34,    2,          -26,  -32,   14,    0
  pose 0xFC89, FileE00E_Obj_36,    1,          -23,  -29,    9,    3
  pose 0xFC8A, FileE00E_Obj_37,    1,          -23,  -30,    9,    2
  pose 0xFC8B, FileE00E_Obj_38,    2,          -23,  -28,    9,    4
  pose 0xFC8C, FileE00E_Obj_40,    2,          -23,  -29,    9,    3
  pose 0xF3C9, FileE00E_Obj_42,    2,          -23,  -30,    9,   10
  pose 0xF3CA, FileE00E_Obj_44,    2,          -25,  -31,   14,    1
  pose 0xF3CB, FileE00E_Obj_46,    2,          -26,  -32,   14,    0
  pose 0xF3CC, FileE00E_Obj_48,    2,          -23,  -31,    9,    9
  pose 0x2A12, FileE00E_Obj_50,    2,          -24,  -34,    8,   14
  pose 0x2B32, FileE00E_Obj_52,    3,          -25,  -36,   15,   12
  pose 0x2B52, FileE00E_Obj_55,    4,          -24,  -30,   16,    2
  pose 0x2B72, FileE00E_Obj_59,    3,          -25,  -27,   14,    5
  pose 0x2B92, FileE00E_Obj_62,    1,          -24,  -29,    8,    3
  pose 0x3202, FileE00E_Obj_63,    3,          -25,  -27,   15,    5
  pose 0x3203, FileE00E_Obj_66,    3,          -25,  -28,   15,    4
  pose 0x3204, FileE00E_Obj_69,    3,          -25,  -27,   15,    5
  pose 0x3205, FileE00E_Obj_72,    3,          -25,  -28,   15,    4
  pose 0x2942, FileE00E_Obj_75,    3,          -24,  -28,   16,    4
  pose 0x2943, FileE00E_Obj_78,    3,          -26,  -32,   14,    4
  pose 0x2944, FileE00E_Obj_81,    3,          -22,  -33,   10,    7
  pose 0x2945, FileE00E_Obj_84,    3,          -26,  -32,   14,    0
  pose 0x3242, FileE00E_Obj_87,    1,          -23,  -29,    9,    3
  pose 0x3243, FileE00E_Obj_88,    1,          -23,  -30,    9,    2
  pose 0x3244, FileE00E_Obj_89,    2,          -23,  -28,    9,    4
  pose 0x3245, FileE00E_Obj_91,    2,          -23,  -29,    9,    3
  pose 0x2982, FileE00E_Obj_93,    2,          -23,  -30,    9,   10
  pose 0x2983, FileE00E_Obj_95,    2,          -24,  -31,   16,    1
  pose 0x2984, FileE00E_Obj_97,    2,          -25,  -32,   14,    0
  pose 0x2985, FileE00E_Obj_99,    3,          -24,  -31,   16,    9
  pose 0xED29, FileE00E_Obj_102,   2,          -23,  -27,    9,    5
  pose 0xED2A, FileE00E_Obj_104,   2,          -23,  -28,    9,    4
  pose 0xED2B, FileE00E_Obj_106,   2,          -23,  -29,    9,    3
  pose 0xED2C, FileE00E_Obj_108,   3,          -23,  -29,    9,    3
  pose 0x22E2, FileE00E_Obj_111,   2,          -23,  -27,    9,    5
  pose 0x22E3, FileE00E_Obj_113,   2,          -23,  -28,    9,    4
  pose 0x22E4, FileE00E_Obj_115,   2,          -23,  -29,    9,    3
  pose 0x22E5, FileE00E_Obj_117,   3,          -23,  -29,    9,    3
  pose 0xDB59, FileE00E_Obj_120,   3,          -23,  -29,    9,    3
  pose 0xDB5A, FileE00E_Obj_123,   4,          -25,  -29,   14,    5
  pose 0xDB5B, FileE00E_Obj_127,   2,          -24,  -29,    9,    3
  pose 0xDB5C, FileE00E_Obj_129,   4,          -25,  -29,   14,    5
  pose 0xDB5D, FileE00E_Obj_133,   3,          -23,  -29,    9,    3
  pose 0x1112, FileE00E_Obj_136,   3,          -23,  -29,    9,    3
  pose 0x1113, FileE00E_Obj_139,   3,          -25,  -27,   14,    5
  pose 0x1114, FileE00E_Obj_142,   2,          -24,  -29,    9,    3
  pose 0x1115, FileE00E_Obj_144,   3,          -25,  -27,   14,    5
  pose 0x1116, FileE00E_Obj_147,   3,          -23,  -29,    9,    3
  pose 0xF699, FileE00E_Obj_150,   2,          -23,  -29,    9,    3
  pose 0xF69A, FileE00E_Obj_152,   2,          -23,  -28,    9,    4
  pose 0xF69B, FileE00E_Obj_154,   2,          -24,  -26,    8,    6
  pose 0xF69C, FileE00E_Obj_156,   2,          -21,  -27,   11,    5
  pose 0xF69D, FileE00E_Obj_158,   1,          -23,  -29,    9,    3
  pose 0xF69E, FileE00E_Obj_159,   2,          -23,  -29,    9,    3
  pose 0x2C52, FileE00E_Obj_161,   2,          -23,  -29,    9,    3
  pose 0x2C53, FileE00E_Obj_163,   2,          -23,  -28,    9,    4
  pose 0x2C54, FileE00E_Obj_165,   2,          -24,  -26,    8,    6
  pose 0x2C55, FileE00E_Obj_167,   2,          -21,  -27,   11,    5
  pose 0x2C56, FileE00E_Obj_169,   1,          -23,  -29,    9,    3
  pose 0x2C57, FileE00E_Obj_170,   2,          -23,  -29,    9,    3
  pose 0x66BD, FileE00E_Obj_172,   2,          -24,  -23,    8,    9
  pose 0x2B33, FileE00E_Obj_174,   2,          -23,  -25,    9,    7
  pose 0x2B34, FileE00E_Obj_176,   2,          -23,  -24,   16,    8
  pose 0x2B35, FileE00E_Obj_178,   1,          -23,  -23,    9,    9

FileE00E_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xB15A, FileE00E_Cmd_0,     1
  animation 0xB17A, FileE00E_Cmd_1,     1
  animation 0xB19A, FileE00E_Cmd_2,     1
  animation 0xB1BA, FileE00E_Cmd_3,     1
  animation 0xB1DA, FileE00E_Cmd_4,     1
  animation 0x3850, FileE00E_Cmd_5,     4
  animation 0x3890, FileE00E_Cmd_9,     4
  animation 0x2F91, FileE00E_Cmd_13,    4
  animation 0x2FD1, FileE00E_Cmd_17,    4
  animation 0x975E, FileE00E_Cmd_21,    3
  animation 0x975F, FileE00E_Cmd_24,    2
  animation 0x9F4A, FileE00E_Cmd_26,    4
  animation 0xA92E, FileE00E_Cmd_30,    4
  animation 0xB29E, FileE00E_Cmd_34,    2
  animation 0xB29F, FileE00E_Cmd_36,    1
  animation 0xB2A0, FileE00E_Cmd_37,    3
  animation 0xE712, FileE00E_Cmd_40,    1
  animation 0xE732, FileE00E_Cmd_41,    1
  animation 0xE752, FileE00E_Cmd_42,    1
  animation 0xE772, FileE00E_Cmd_43,    1
  animation 0xE792, FileE00E_Cmd_44,    1
  animation 0x6E08, FileE00E_Cmd_45,    4
  animation 0x6E48, FileE00E_Cmd_49,    4
  animation 0x6549, FileE00E_Cmd_53,    4
  animation 0x6589, FileE00E_Cmd_57,    4
  animation 0xCD16, FileE00E_Cmd_61,    3
  animation 0xCD17, FileE00E_Cmd_64,    2
  animation 0x5651, FileE00E_Cmd_66,    4
  animation 0xDEE6, FileE00E_Cmd_70,    4
  animation 0xE856, FileE00E_Cmd_74,    2
  animation 0xE857, FileE00E_Cmd_76,    1
  animation 0xE858, FileE00E_Cmd_77,    3
  animation 0x6739, FileE00E_Cmd_80,    4

1:
FileE00E_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileE00E_Obj_0:
    subsprite OAM_SIZE_16x16,   -8,  -18,    0,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,   32,    0
  FileE00E_Obj_2:
    subsprite OAM_SIZE_16x16,   -9,  -19,    2,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  245,    0
    subsprite OAM_SIZE_16x8,    -9,   -3,   34,    0
  FileE00E_Obj_5:
    subsprite OAM_SIZE_16x16,   -8,  -13,    4,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
    subsprite OAM_SIZE_8x8,      8,  -13,    8,    0
    subsprite OAM_SIZE_8x8,    -16,  -13,  248,    0
  FileE00E_Obj_9:
    subsprite OAM_SIZE_16x16,   -8,  -13,   24,    0
    subsprite OAM_SIZE_8x8,      0,  -21,    9,    0
    subsprite OAM_SIZE_8x8,      8,  -13,    8,    0
  FileE00E_Obj_12:
    subsprite OAM_SIZE_16x16,   -8,  -13,    6,    0
  FileE00E_Obj_13:
    subsprite OAM_SIZE_16x16,   -9,  -11,  144,    0
    subsprite OAM_SIZE_8x8,      7,  -10,  245,    0
    subsprite OAM_SIZE_8x8,     -1,  -18,    3,    0
  FileE00E_Obj_16:
    subsprite OAM_SIZE_16x16,   -9,  -12,  146,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  245,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,    3,    0
  FileE00E_Obj_19:
    subsprite OAM_SIZE_16x16,   -9,  -11,  148,    0
    subsprite OAM_SIZE_8x8,      7,  -10,  245,    0
    subsprite OAM_SIZE_8x8,     -1,  -18,    3,    0
  FileE00E_Obj_22:
    subsprite OAM_SIZE_16x16,   -9,  -12,  150,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  245,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,    3,    0
  FileE00E_Obj_25:
    subsprite OAM_SIZE_16x16,   -9,  -12,   80,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,    3,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  245,    0
  FileE00E_Obj_28:
    subsprite OAM_SIZE_16x16,  -12,  -13,   82,    0
    subsprite OAM_SIZE_8x16,     4,  -13,   84,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,    3,    0
  FileE00E_Obj_31:
    subsprite OAM_SIZE_16x16,  -12,  -17,   85,    0
    subsprite OAM_SIZE_8x16,     4,  -17,   87,    0
    subsprite OAM_SIZE_8x8,     -4,   -1,  241,    0
  FileE00E_Obj_34:
    subsprite OAM_SIZE_16x16,  -10,  -16,   88,    0
    subsprite OAM_SIZE_8x16,     6,  -16,   90,    0
  FileE00E_Obj_36:
    subsprite OAM_SIZE_16x16,   -7,  -13,  152,    0
  FileE00E_Obj_37:
    subsprite OAM_SIZE_16x16,   -7,  -14,  154,    0
  FileE00E_Obj_38:
    subsprite OAM_SIZE_16x16,   -7,  -12,  156,    0
    subsprite OAM_SIZE_8x8,     -1,  -13,  247,    0
  FileE00E_Obj_40:
    subsprite OAM_SIZE_16x16,   -7,  -13,  158,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  247,    0
  FileE00E_Obj_42:
    subsprite OAM_SIZE_16x16,   -7,  -14,   50,    0
    subsprite OAM_SIZE_8x8,     -8,    2,  247,    0
  FileE00E_Obj_44:
    subsprite OAM_SIZE_16x16,   -9,  -15,   52,    0
    subsprite OAM_SIZE_8x16,     6,  -15,   56,    0
  FileE00E_Obj_46:
    subsprite OAM_SIZE_16x16,  -10,  -16,   54,    0
    subsprite OAM_SIZE_8x16,     6,  -16,   56,    0
  FileE00E_Obj_48:
    subsprite OAM_SIZE_16x16,   -7,  -15,   48,    0
    subsprite OAM_SIZE_8x8,     -7,    1,  247,    0
  FileE00E_Obj_50:
    subsprite OAM_SIZE_16x16,   -8,  -18,   59,    0
    subsprite OAM_SIZE_16x8,    -8,   -2,   32,    0
  FileE00E_Obj_52:
    subsprite OAM_SIZE_16x16,   -9,  -20,   78,    0
    subsprite OAM_SIZE_16x8,    -9,   -4,  110,    0
    subsprite OAM_SIZE_8x8,      7,  -12,  244,    0
  FileE00E_Obj_55:
    subsprite OAM_SIZE_16x16,   -8,  -14,   91,    0
    subsprite OAM_SIZE_8x8,    -16,  -13,  248,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
    subsprite OAM_SIZE_8x8,      8,  -13,    8,    0
  FileE00E_Obj_59:
    subsprite OAM_SIZE_16x16,   -9,  -11,  126,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,  240,    0
    subsprite OAM_SIZE_8x16,     6,  -14,   56,    0
  FileE00E_Obj_62:
    subsprite OAM_SIZE_16x16,   -8,  -13,   57,    0
  FileE00E_Obj_63:
    subsprite OAM_SIZE_16x16,   -9,  -11,  184,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,  250,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  249,    0
  FileE00E_Obj_66:
    subsprite OAM_SIZE_16x16,   -9,  -12,  186,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  250,    0
    subsprite OAM_SIZE_8x8,      7,  -12,  249,    0
  FileE00E_Obj_69:
    subsprite OAM_SIZE_16x16,   -9,  -11,  188,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,  250,    0
    subsprite OAM_SIZE_8x8,      7,  -11,  249,    0
  FileE00E_Obj_72:
    subsprite OAM_SIZE_16x16,   -9,  -12,  190,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  250,    0
    subsprite OAM_SIZE_8x8,      7,  -12,  249,    0
  FileE00E_Obj_75:
    subsprite OAM_SIZE_8x8,      8,  -12,  242,    0
    subsprite OAM_SIZE_16x16,   -8,  -12,  112,    0
    subsprite OAM_SIZE_8x8,      0,  -20,  250,    0
  FileE00E_Obj_78:
    subsprite OAM_SIZE_8x16,     6,  -12,  116,    0
    subsprite OAM_SIZE_16x16,  -10,  -12,  114,    0
    subsprite OAM_SIZE_16x8,    -6,  -16,  117,    0
  FileE00E_Obj_81:
    subsprite OAM_SIZE_16x16,   -6,  -17,  117,    0
    subsprite OAM_SIZE_8x8,    -14,   -9,  243,    0
    subsprite OAM_SIZE_8x8,     -3,   -1,  241,    0
  FileE00E_Obj_84:
    subsprite OAM_SIZE_16x16,  -10,  -16,  119,    0
    subsprite OAM_SIZE_8x16,     6,  -12,  116,    0
    subsprite OAM_SIZE_16x8,    -6,  -16,  117,    0
  FileE00E_Obj_87:
    subsprite OAM_SIZE_16x16,   -7,  -13,  176,    0
  FileE00E_Obj_88:
    subsprite OAM_SIZE_16x16,   -7,  -14,  178,    0
  FileE00E_Obj_89:
    subsprite OAM_SIZE_16x16,   -7,  -12,  180,    0
    subsprite OAM_SIZE_8x8,     -1,  -13,  247,    0
  FileE00E_Obj_91:
    subsprite OAM_SIZE_16x16,   -7,  -13,  182,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  247,    0
  FileE00E_Obj_93:
    subsprite OAM_SIZE_16x16,   -7,  -14,   10,    0
    subsprite OAM_SIZE_8x8,     -8,    2,  247,    0
  FileE00E_Obj_95:
    subsprite OAM_SIZE_16x16,   -8,  -15,   12,    0
    subsprite OAM_SIZE_8x8,      8,  -14,    8,    0
  FileE00E_Obj_97:
    subsprite OAM_SIZE_16x16,   -9,  -16,   14,    0
    subsprite OAM_SIZE_8x16,     6,  -16,   56,    0
  FileE00E_Obj_99:
    subsprite OAM_SIZE_16x16,   -8,  -15,   46,    0
    subsprite OAM_SIZE_8x8,      8,  -14,    8,    0
    subsprite OAM_SIZE_8x8,     -7,    1,  247,    0
  FileE00E_Obj_102:
    subsprite OAM_SIZE_16x16,   -7,  -11,  208,    0
    subsprite OAM_SIZE_8x8,    -15,   -6,  248,    0
  FileE00E_Obj_104:
    subsprite OAM_SIZE_16x16,   -7,  -12,  210,    0
    subsprite OAM_SIZE_8x8,    -15,   -7,  248,    0
  FileE00E_Obj_106:
    subsprite OAM_SIZE_16x16,   -7,  -13,  212,    0
    subsprite OAM_SIZE_8x8,    -15,   -5,  252,    0
  FileE00E_Obj_108:
    subsprite OAM_SIZE_16x16,   -7,  -13,  214,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  251,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  247,    0
  FileE00E_Obj_111:
    subsprite OAM_SIZE_16x16,   -7,  -11,  216,    0
    subsprite OAM_SIZE_8x8,    -15,   -6,  248,    0
  FileE00E_Obj_113:
    subsprite OAM_SIZE_16x16,   -7,  -12,  218,    0
    subsprite OAM_SIZE_8x8,    -15,   -7,  248,    0
  FileE00E_Obj_115:
    subsprite OAM_SIZE_16x16,   -7,  -13,  220,    0
    subsprite OAM_SIZE_8x8,    -15,   -5,  252,    0
  FileE00E_Obj_117:
    subsprite OAM_SIZE_8x8,    -15,  -13,  251,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  222,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  247,    0
  FileE00E_Obj_120:
    subsprite OAM_SIZE_16x16,   -7,  -13,  122,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  253,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
  FileE00E_Obj_123:
    subsprite OAM_SIZE_16x16,   -9,  -11,  124,    0
    subsprite OAM_SIZE_8x16,     0,  -21,    9,    0
    subsprite OAM_SIZE_8x8,     -7,  -12,  247,    0
    subsprite OAM_SIZE_8x16,     6,  -14,   56,    0
  FileE00E_Obj_127:
    subsprite OAM_SIZE_16x16,   -8,  -13,  266,    0
    subsprite OAM_SIZE_8x8,      1,  -13,  248,    0
  FileE00E_Obj_129:
    subsprite OAM_SIZE_16x16,   -9,  -11,  268,    0
    subsprite OAM_SIZE_8x16,     0,  -21,    9,    0
    subsprite OAM_SIZE_8x16,     6,  -14,   56,    0
    subsprite OAM_SIZE_8x8,     -7,  -12,  247,    0
  FileE00E_Obj_133:
    subsprite OAM_SIZE_16x16,   -7,  -13,  270,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
    subsprite OAM_SIZE_8x8,     -8,  -13,    8,    0
  FileE00E_Obj_136:
    subsprite OAM_SIZE_8x8,    -15,  -13,  253,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  256,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
  FileE00E_Obj_139:
    subsprite OAM_SIZE_16x16,   -9,  -11,  258,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,  240,    0
    subsprite OAM_SIZE_8x16,     6,  -14,   56,    0
  FileE00E_Obj_142:
    subsprite OAM_SIZE_16x16,   -8,  -13,  260,    0
    subsprite OAM_SIZE_8x8,      1,  -13,  248,    0
  FileE00E_Obj_144:
    subsprite OAM_SIZE_16x16,   -9,  -11,  262,    0
    subsprite OAM_SIZE_8x8,     -1,  -19,  240,    0
    subsprite OAM_SIZE_8x16,     6,  -14,   56,    0
  FileE00E_Obj_147:
    subsprite OAM_SIZE_16x16,   -7,  -13,  264,    0
    subsprite OAM_SIZE_8x8,      0,  -21,  246,    0
    subsprite OAM_SIZE_8x8,     -8,  -13,    8,    0
  FileE00E_Obj_150:
    subsprite OAM_SIZE_16x16,   -7,  -13,  302,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  254,    0
  FileE00E_Obj_152:
    subsprite OAM_SIZE_16x16,   -7,  -12,  288,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  251,    0
  FileE00E_Obj_154:
    subsprite OAM_SIZE_16x16,   -8,  -10,  290,    0
    subsprite OAM_SIZE_8x8,     -8,  -18,  255,    0
  FileE00E_Obj_156:
    subsprite OAM_SIZE_16x16,   -5,  -11,  292,    0
    subsprite OAM_SIZE_8x8,    -11,  -18,  254,    0
  FileE00E_Obj_158:
    subsprite OAM_SIZE_16x16,   -7,  -13,  294,    0
  FileE00E_Obj_159:
    subsprite OAM_SIZE_16x16,   -7,  -13,  296,    0
    subsprite OAM_SIZE_8x8,    -15,  -12,  248,    0
  FileE00E_Obj_161:
    subsprite OAM_SIZE_8x8,    -15,  -13,  254,    0
    subsprite OAM_SIZE_16x16,   -7,  -13,  298,    0
  FileE00E_Obj_163:
    subsprite OAM_SIZE_16x16,   -7,  -12,  300,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  251,    0
  FileE00E_Obj_165:
    subsprite OAM_SIZE_16x16,   -8,  -10,  334,    0
    subsprite OAM_SIZE_8x8,     -8,  -18,  255,    0
  FileE00E_Obj_167:
    subsprite OAM_SIZE_16x16,   -5,  -11,  320,    0
    subsprite OAM_SIZE_8x8,    -11,  -18,  254,    0
  FileE00E_Obj_169:
    subsprite OAM_SIZE_16x16,   -7,  -13,  322,    0
  FileE00E_Obj_170:
    subsprite OAM_SIZE_16x16,   -7,  -13,  324,    0
    subsprite OAM_SIZE_8x8,    -15,  -12,  248,    0
  FileE00E_Obj_172:
    subsprite OAM_SIZE_16x16,   -8,   -7,  326,    0
    subsprite OAM_SIZE_8x8,    -16,   -7,   37,    0
  FileE00E_Obj_174:
    subsprite OAM_SIZE_16x16,   -7,   -9,  328,    0
    subsprite OAM_SIZE_8x8,     -7,  -17,   36,    0
  FileE00E_Obj_176:
    subsprite OAM_SIZE_16x16,   -7,   -8,  330,    0
    subsprite OAM_SIZE_8x8,      8,   -4,   37,    0, xflip=1, yflip=1
  FileE00E_Obj_178:
    subsprite OAM_SIZE_16x16,   -7,   -7,  332,    0

2:
FileE00E_Cmds:
  FileE00E_Cmd_0:
    animcmd   0,   1
  FileE00E_Cmd_1:
    animcmd   1,   1
  FileE00E_Cmd_2:
    animcmd   2,   1
  FileE00E_Cmd_3:
    animcmd   3,   1
  FileE00E_Cmd_4:
    animcmd   4,   1
  FileE00E_Cmd_5:
    animcmd   5,  13
    animcmd   6,  11
    animcmd   7,  13
    animcmd   8,  11
  FileE00E_Cmd_9:
    animcmd  13,  13
    animcmd  14,  11
    animcmd  15,  13
    animcmd  16,  11
  FileE00E_Cmd_13:
    animcmd   9,   9
    animcmd  10,  11
    animcmd  11,   9
    animcmd  12,  11
  FileE00E_Cmd_17:
    animcmd  17,   9
    animcmd  18,  11
    animcmd  19,   9
    animcmd  20,  11
  FileE00E_Cmd_21:
    animcmd  50,  10
    animcmd  51,  10
    animcmd  52,  10
  FileE00E_Cmd_24:
    animcmd  53,  10
    animcmd  54,  10
  FileE00E_Cmd_26:
    animcmd  45,  11
    animcmd  44,  11
    animcmd  43,  11
    animcmd  42,  11
  FileE00E_Cmd_30:
    animcmd  42,   9
    animcmd  43,   9
    animcmd  44,   9
    animcmd  45,   9
  FileE00E_Cmd_34:
    animcmd  60,  10
    animcmd  61,  15
  FileE00E_Cmd_36:
    animcmd  62,   1
  FileE00E_Cmd_37:
    animcmd  63,   7
    animcmd  64,  10
    animcmd  65,  10
  FileE00E_Cmd_40:
    animcmd  21,   1
  FileE00E_Cmd_41:
    animcmd  22,   1
  FileE00E_Cmd_42:
    animcmd  23,   1
  FileE00E_Cmd_43:
    animcmd  24,   1
  FileE00E_Cmd_44:
    animcmd  25,   1
  FileE00E_Cmd_45:
    animcmd  26,  13
    animcmd  27,  11
    animcmd  28,  13
    animcmd  29,  11
  FileE00E_Cmd_49:
    animcmd  34,  13
    animcmd  35,  11
    animcmd  36,  13
    animcmd  37,  11
  FileE00E_Cmd_53:
    animcmd  30,   9
    animcmd  31,  11
    animcmd  32,   9
    animcmd  33,  11
  FileE00E_Cmd_57:
    animcmd  38,   9
    animcmd  39,  11
    animcmd  40,   9
    animcmd  41,  11
  FileE00E_Cmd_61:
    animcmd  55,  10
    animcmd  56,  10
    animcmd  57,  10
  FileE00E_Cmd_64:
    animcmd  58,  10
    animcmd  59,  10
  FileE00E_Cmd_66:
    animcmd  49,  11
    animcmd  48,  11
    animcmd  47,  11
    animcmd  46,  11
  FileE00E_Cmd_70:
    animcmd  46,   9
    animcmd  47,   9
    animcmd  48,   9
    animcmd  49,   9
  FileE00E_Cmd_74:
    animcmd  66,  10
    animcmd  67,  10
  FileE00E_Cmd_76:
    animcmd  68,   1
  FileE00E_Cmd_77:
    animcmd  69,  10
    animcmd  70,  10
    animcmd  71,  10
  FileE00E_Cmd_80:
    animcmd  72,   6
    animcmd  73,   6
    animcmd  74,   6
    animcmd  75,   6

FileE00E_Tiles:
  .incbin "data/spriteset/kuro.4bpp"
