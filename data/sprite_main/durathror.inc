FileD3FA_Header:
  .2byte 756 @ palStart
  .2byte 93 @ metaspriteCount
  .2byte 50 @ animationCount
  .2byte 330 @ subspriteCount
  .2byte 159 @ cmdCount
  .2byte 1280 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 1892 @ offsetToAnims
  .4byte 2292 @ offsetToSubsprites
  .4byte 4932 @ offsetToCmds
  .4byte 5568 @ offsetToTiles

FileD3FA_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x3EF6, FileD3FA_Obj_0,    2,          -48,  -56,   16,    8
  pose 0x3EF7, FileD3FA_Obj_2,    2,          -48,  -56,   16,    8
  pose 0x3EF8, FileD3FA_Obj_4,    2,          -48,  -56,   16,    8
  pose 0x3EF9, FileD3FA_Obj_6,    2,          -48,  -56,   16,    8
  pose 0x8DB3, FileD3FA_Obj_8,    2,          -48,  -56,   16,    8
  pose 0x8DB4, FileD3FA_Obj_10,   4,          -48,  -72,   24,   24
  pose 0x8DB5, FileD3FA_Obj_14,   5,          -56,  -64,   24,   32
  pose 0x8DB6, FileD3FA_Obj_19,   5,          -56,  -72,   24,   32
  pose 0x8DB7, FileD3FA_Obj_24,   5,          -56,  -72,   24,   32
  pose 0x8DB8, FileD3FA_Obj_29,   1,          -97, -108,   31,   20
  pose 0x8DB9, FileD3FA_Obj_30,   3,          -96, -108,   32,   20
  pose 0x8DBA, FileD3FA_Obj_33,   3,          -96, -108,   32,   20
  pose 0x8DBB, FileD3FA_Obj_36,   3,          -96, -108,   32,   20
  pose 0x8DE3, FileD3FA_Obj_39,   3,          -96, -108,   32,   20
  pose 0x8DE4, FileD3FA_Obj_42,   3,          -96, -108,   32,   20
  pose 0x8DE5, FileD3FA_Obj_45,   3,          -96, -108,   32,   20
  pose 0x6E68, FileD3FA_Obj_48,   5,          -96, -108,   32,   20
  pose 0x7268, FileD3FA_Obj_53,   5,          -96, -108,   32,   20
  pose 0x7668, FileD3FA_Obj_58,   5,          -96, -108,   32,   20
  pose 0x7A68, FileD3FA_Obj_63,   5,          -96, -108,   32,   20
  pose 0x6E90, FileD3FA_Obj_68,   5,          -96, -108,   32,   20
  pose 0x7290, FileD3FA_Obj_73,   5,          -96, -108,   32,   20
  pose 0x7690, FileD3FA_Obj_78,   5,          -96, -108,   32,   20
  pose 0x7A90, FileD3FA_Obj_83,   5,          -96, -108,   32,   20
  pose 0x6E91, FileD3FA_Obj_88,   4,          -96, -108,   32,   20
  pose 0x7291, FileD3FA_Obj_92,   4,          -96, -108,   32,   20
  pose 0x7691, FileD3FA_Obj_96,   4,          -96, -108,   32,   20
  pose 0x7A91, FileD3FA_Obj_100,  4,          -96, -108,   32,   20
  pose 0x6E92, FileD3FA_Obj_104,  4,          -96, -108,   32,   20
  pose 0x7292, FileD3FA_Obj_108,  4,          -96, -108,   32,   20
  pose 0x7692, FileD3FA_Obj_112,  4,          -96, -108,   32,   20
  pose 0x7A92, FileD3FA_Obj_116,  4,          -96, -108,   32,   20
  pose 0x9C1D, FileD3FA_Obj_120,  2,          -48,  -76,   16,    4
  pose 0x9C1B, FileD3FA_Obj_122,  3,          -32,  -60,    8,    4
  pose 0x4732, FileD3FA_Obj_125,  4,          -24,  -52,   16,    0
  pose 0x4730, FileD3FA_Obj_129,  4,          -24,  -52,   16,    0
  pose 0xB4F3, FileD3FA_Obj_133,  3,          -24,  -52,   16,    0
  pose 0xB513, FileD3FA_Obj_136,  3,          -24,  -52,   16,    0
  pose 0xB533, FileD3FA_Obj_139,  3,          -24,  -52,   16,    0
  pose 0xB4F1, FileD3FA_Obj_142,  4,          -48,  -60,   16,   28
  pose 0xB511, FileD3FA_Obj_146,  4,          -48,  -60,   16,   28
  pose 0xB531, FileD3FA_Obj_150,  4,          -48,  -60,   16,   28
  pose 0x60F5, FileD3FA_Obj_154,  3,          -48,  -82,   16,    0
  pose 0x60F6, FileD3FA_Obj_157,  3,          -24,  -66,    8,   14
  pose 0x60F7, FileD3FA_Obj_160,  4,          -24,  -66,    8,   14
  pose 0x60F8, FileD3FA_Obj_164,  3,          -24,  -66,    8,   14
  pose 0x60F9, FileD3FA_Obj_167,  3,          -48,  -82,   16,    0
  pose 0x60FA, FileD3FA_Obj_170,  5,          -25,  -66,    7,   14
  pose 0x60FB, FileD3FA_Obj_175,  4,          -25,  -66,   15,   14
  pose 0x60FC, FileD3FA_Obj_179,  3,          -25,  -66,    7,   14
  pose 0xCBE8, FileD3FA_Obj_182,  5,          -48,  -68,   24,    4
  pose 0xCC08, FileD3FA_Obj_187,  6,          -48,  -68,   24,    4
  pose 0xCC28, FileD3FA_Obj_193,  2,          -51,  -59,   13,    5
  pose 0xCC48, FileD3FA_Obj_195,  2,          -51,  -59,   13,   21
  pose 0xCC68, FileD3FA_Obj_197,  3,          -50,  -60,   22,    4
  pose 0xCC88, FileD3FA_Obj_200,  2,          -51,  -59,   13,    5
  pose 0xCCA8, FileD3FA_Obj_202,  2,          -51,  -59,   13,   21
  pose 0xCBE6, FileD3FA_Obj_204,  4,          -56,  -68,   16,   12
  pose 0xCC06, FileD3FA_Obj_208,  5,          -56,  -68,   16,   12
  pose 0xCC26, FileD3FA_Obj_213,  2,          -48,  -60,   16,    4
  pose 0xCC46, FileD3FA_Obj_215,  2,          -48,  -60,   16,   20
  pose 0xCC66, FileD3FA_Obj_217,  1,          -48,  -60,   16,    4
  pose 0xCC86, FileD3FA_Obj_218,  2,          -48,  -60,   16,    4
  pose 0xCCA6, FileD3FA_Obj_220,  2,          -48,  -60,   16,   20
  pose 0x52D2, FileD3FA_Obj_222,  5,          -56,  -60,   16,   20
  pose 0x52F2, FileD3FA_Obj_227,  4,          -40,  -44,    8,   12
  pose 0x5312, FileD3FA_Obj_231,  4,          -40,  -44,    8,   12
  pose 0x5332, FileD3FA_Obj_235,  1,          -56,  -60,    8,    4
  pose 0x52D0, FileD3FA_Obj_236,  5,          -24,  -52,   24,   12
  pose 0x52F0, FileD3FA_Obj_241,  4,          -24,  -36,   16,    0
  pose 0x5310, FileD3FA_Obj_245,  4,          -24,  -36,   16,    0
  pose 0x5330, FileD3FA_Obj_249,  2,          -49,  -50,   15,   14
  pose 0x0F36, FileD3FA_Obj_251,  1,          -24,  -24,    8,    8
  pose 0x0F37, FileD3FA_Obj_252,  4,          -24,  -56,   16,    0
  pose 0x0F38, FileD3FA_Obj_256,  8,          -48,  -88,   24,   32
  pose 0x0F39, FileD3FA_Obj_264,  10,         -56,  -99,   24,   28
  pose 0x0F3A, FileD3FA_Obj_274,  10,         -56, -100,   24,   28
  pose 0x0F3B, FileD3FA_Obj_284,  10,         -56, -101,   24,   27
  pose 0xF44E, FileD3FA_Obj_294,  2,          -48,  -56,   16,    8
  pose 0xF44F, FileD3FA_Obj_296,  2,          -48,  -56,   16,    8
  pose 0xF450, FileD3FA_Obj_298,  2,          -48,  -56,   16,    8
  pose 0xF451, FileD3FA_Obj_300,  2,          -48,  -56,   16,    8
  pose 0xB797, FileD3FA_Obj_302,  2,          -96, -108,   32,   20
  pose 0xB7B7, FileD3FA_Obj_304,  2,          -96, -108,   32,   20
  pose 0xF35E, FileD3FA_Obj_306,  2,          -96, -108,   32,   20
  pose 0xF75E, FileD3FA_Obj_308,  2,          -96, -108,   32,   20
  pose 0xBCA2, FileD3FA_Obj_310,  3,          -96, -108,   32,   20
  pose 0xBCA3, FileD3FA_Obj_313,  3,          -96, -108,   32,   20
  pose 0xBCC2, FileD3FA_Obj_316,  3,          -96, -108,   32,   20
  pose 0xBCC3, FileD3FA_Obj_319,  3,          -96, -108,   32,   20
  pose 0xBCE2, FileD3FA_Obj_322,  3,          -96, -108,   32,   20
  pose 0xBCE3, FileD3FA_Obj_325,  3,          -96, -108,   32,   20
  pose 0x16DD, FileD3FA_Obj_328,  2,          -48,  -68,   16,   12

FileD3FA_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xB98C, FileD3FA_Cmd_0,  4
  animation 0x8DB2, FileD3FA_Cmd_4,  1
  animation 0x8DB3, FileD3FA_Cmd_5,  1
  animation 0x8DB4, FileD3FA_Cmd_6,  1
  animation 0x8DB5, FileD3FA_Cmd_7,  1
  animation 0x8DB6, FileD3FA_Cmd_8,  1
  animation 0x8DB7, FileD3FA_Cmd_9,  1
  animation 0x8DB8, FileD3FA_Cmd_10, 4
  animation 0xB782, FileD3FA_Cmd_14, 4
  animation 0xB7A2, FileD3FA_Cmd_18, 4
  animation 0xBCA2, FileD3FA_Cmd_22, 4
  animation 0x8DB9, FileD3FA_Cmd_26, 1
  animation 0x8DBA, FileD3FA_Cmd_27, 1
  animation 0x8DBB, FileD3FA_Cmd_28, 1
  animation 0x8DE3, FileD3FA_Cmd_29, 1
  animation 0x8DE4, FileD3FA_Cmd_30, 6
  animation 0xB783, FileD3FA_Cmd_36, 6
  animation 0xB7A3, FileD3FA_Cmd_42, 6
  animation 0xBCA3, FileD3FA_Cmd_48, 6
  animation 0x93DF, FileD3FA_Cmd_54, 4
  animation 0x93E0, FileD3FA_Cmd_58, 4
  animation 0x93E1, FileD3FA_Cmd_62, 4
  animation 0x9409, FileD3FA_Cmd_66, 4
  animation 0x9C1D, FileD3FA_Cmd_70, 1
  animation 0x9C1B, FileD3FA_Cmd_71, 1
  animation 0x4732, FileD3FA_Cmd_72, 1
  animation 0x4730, FileD3FA_Cmd_73, 1
  animation 0xF5E8, FileD3FA_Cmd_74, 4
  animation 0xF5E6, FileD3FA_Cmd_78, 4
  animation 0x3955, FileD3FA_Cmd_82, 8
  animation 0xCBE8, FileD3FA_Cmd_90, 1
  animation 0xCC08, FileD3FA_Cmd_91, 1
  animation 0xCC28, FileD3FA_Cmd_92, 1
  animation 0xCC48, FileD3FA_Cmd_93, 2
  animation 0xCC68, FileD3FA_Cmd_95, 3
  animation 0xCBE6, FileD3FA_Cmd_98, 1
  animation 0xCC06, FileD3FA_Cmd_99, 1
  animation 0xCC26, FileD3FA_Cmd_100, 1
  animation 0xCC46, FileD3FA_Cmd_101, 2
  animation 0xCC66, FileD3FA_Cmd_103, 3
  animation 0xEAD7, FileD3FA_Cmd_106, 10
  animation 0xEAD5, FileD3FA_Cmd_116, 10
  animation 0x0F36, FileD3FA_Cmd_126, 8
  animation 0x0F37, FileD3FA_Cmd_134, 1
  animation 0x0FBA, FileD3FA_Cmd_135, 8
  animation 0xB777, FileD3FA_Cmd_143, 4
  animation 0xB797, FileD3FA_Cmd_147, 1
  animation 0xBCF7, FileD3FA_Cmd_148, 6
  animation 0x7C58, FileD3FA_Cmd_154, 4
  animation 0x16DD, FileD3FA_Cmd_158, 1

1:
FileD3FA_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD3FA_Obj_0:
    subsprite OAM_SIZE_32x32,  -16,  -24,    0,    2
    subsprite OAM_SIZE_16x16,   -8,  -40,   76,    2
  FileD3FA_Obj_2:
    subsprite OAM_SIZE_32x32,  -16,  -24,    4,    2
    subsprite OAM_SIZE_16x16,   -8,  -40,   78,    2
  FileD3FA_Obj_4:
    subsprite OAM_SIZE_32x32,  -16,  -24,    8,    2
    subsprite OAM_SIZE_16x16,   -8,  -40,  108,    2
  FileD3FA_Obj_6:
    subsprite OAM_SIZE_32x32,  -16,  -24,   12,    2
    subsprite OAM_SIZE_16x16,   -8,  -40,  110,    2
  FileD3FA_Obj_8:
    subsprite OAM_SIZE_32x32,  -16,  -24,   64,    2
    subsprite OAM_SIZE_16x16,   -8,  -40,  132,    2
  FileD3FA_Obj_10:
    subsprite OAM_SIZE_32x32,  -16,  -24,   68,    2
    subsprite OAM_SIZE_32x16,  -16,  -40,  128,    2
    subsprite OAM_SIZE_8x16,    16,  -16,  134,    2
    subsprite OAM_SIZE_16x8,    -8,    8,  152,    2
  FileD3FA_Obj_14:
    subsprite OAM_SIZE_32x32,  -24,  -32,   72,    2
    subsprite OAM_SIZE_16x32,    8,  -32,  160,    2
    subsprite OAM_SIZE_32x16,  -16,    0,  140,    2
    subsprite OAM_SIZE_8x8,     16,    0,  135,    2
    subsprite OAM_SIZE_16x8,    -8,  -40,  136,    2
  FileD3FA_Obj_19:
    subsprite OAM_SIZE_32x32,  -24,  -32,  168,    2
    subsprite OAM_SIZE_16x32,    8,  -32,  162,    2
    subsprite OAM_SIZE_32x8,   -16,  -40,  232,    2
    subsprite OAM_SIZE_32x16,  -24,    0,  224,    2
    subsprite OAM_SIZE_16x16,    8,    0,  166,    2
  FileD3FA_Obj_24:
    subsprite OAM_SIZE_32x32,  -24,  -32,  172,    2
    subsprite OAM_SIZE_16x32,    8,  -32,  164,    2
    subsprite OAM_SIZE_32x16,  -24,    0,  228,    2
    subsprite OAM_SIZE_16x16,    8,    0,  198,    2
    subsprite OAM_SIZE_32x8,   -16,  -40,  248,    2
  FileD3FA_Obj_29:
    subsprite OAM_SIZE_64x64,  -33,  -44,  512,    2
  FileD3FA_Obj_30:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -32,  138,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_33:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -33,  138,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_36:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -35,  138,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_39:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -35,  138,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_42:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -35, 1096,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_45:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -35, 1096,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_48:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x32,  -15,  -52,  393,    1
    subsprite OAM_SIZE_8x32,     1,  -52,  395,    1
    subsprite OAM_SIZE_16x16,   -7,  -20,  448,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_53:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x32,  -15,  -53,  393,    1
    subsprite OAM_SIZE_8x32,     1,  -53,  395,    1
    subsprite OAM_SIZE_16x16,   -7,  -21,  448,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_58:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2, xflip=1
    subsprite OAM_SIZE_16x32,  -15,  -52,  393,    1
    subsprite OAM_SIZE_8x32,     1,  -52,  395,    1
    subsprite OAM_SIZE_16x16,   -7,  -20,  448,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2, xflip=1
  FileD3FA_Obj_63:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2, xflip=1
    subsprite OAM_SIZE_16x32,  -15,  -53,  393,    1
    subsprite OAM_SIZE_8x32,     1,  -53,  395,    1
    subsprite OAM_SIZE_16x16,   -7,  -21,  448,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2, xflip=1
  FileD3FA_Obj_68:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x32,   -3,  -52,  393,    1, xflip=1
    subsprite OAM_SIZE_8x32,   -11,  -52,  395,    1, xflip=1
    subsprite OAM_SIZE_16x16,  -11,  -20,  448,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_73:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x32,   -3,  -53,  393,    1, xflip=1
    subsprite OAM_SIZE_8x32,   -11,  -53,  395,    1, xflip=1
    subsprite OAM_SIZE_16x16,  -11,  -21,  448,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_78:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2, xflip=1
    subsprite OAM_SIZE_16x32,   -3,  -52,  393,    1, xflip=1
    subsprite OAM_SIZE_8x32,   -11,  -52,  395,    1, xflip=1
    subsprite OAM_SIZE_16x16,  -11,  -20,  448,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2, xflip=1
  FileD3FA_Obj_83:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2, xflip=1
    subsprite OAM_SIZE_16x32,   -3,  -53,  393,    1, xflip=1
    subsprite OAM_SIZE_8x32,   -11,  -53,  395,    1, xflip=1
    subsprite OAM_SIZE_16x16,  -11,  -21,  448,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2, xflip=1
  FileD3FA_Obj_88:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_32x32,  -16,  -52,  396,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -20,  480,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_92:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -21,  480,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -53,  396,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_96:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -20,  480,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -52,  396,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2, xflip=1
  FileD3FA_Obj_100:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -21,  480,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -53,  396,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2, xflip=1
  FileD3FA_Obj_104:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_32x32,  -17,  -52,  396,    1
    subsprite OAM_SIZE_16x16,   -9,  -20,  480,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_108:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -9,  -21,  480,    1
    subsprite OAM_SIZE_32x32,  -17,  -53,  396,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_112:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2, xflip=1
    subsprite OAM_SIZE_32x32,  -17,  -52,  396,    1
    subsprite OAM_SIZE_16x16,   -9,  -20,  480,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2, xflip=1
  FileD3FA_Obj_116:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -21,  480,    1
    subsprite OAM_SIZE_32x32,  -17,  -53,  396,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2, xflip=1
  FileD3FA_Obj_120:
    subsprite OAM_SIZE_32x32,  -16,  -44,  396,    1
    subsprite OAM_SIZE_16x16,   -8,  -12,  480,    1
  FileD3FA_Obj_122:
    subsprite OAM_SIZE_16x32,  -16,  -44,  393,    1
    subsprite OAM_SIZE_8x32,     0,  -44,  395,    1
    subsprite OAM_SIZE_16x16,   -8,  -12,  448,    1
  FileD3FA_Obj_125:
    subsprite OAM_SIZE_16x8,    -8,  -36,  266,    1
    subsprite OAM_SIZE_16x32,   -8,  -28,  260,    1
    subsprite OAM_SIZE_8x16,     8,  -20,  291,    1
    subsprite OAM_SIZE_8x16,   -16,  -20,  259,    1
  FileD3FA_Obj_129:
    subsprite OAM_SIZE_16x8,    -8,  -36,  264,    1
    subsprite OAM_SIZE_16x32,   -8,  -28,  256,    1
    subsprite OAM_SIZE_8x16,     8,  -20,  258,    1
    subsprite OAM_SIZE_8x16,   -16,  -20,  290,    1
  FileD3FA_Obj_133:
    subsprite OAM_SIZE_16x32,   -8,  -28,  384,    1
    subsprite OAM_SIZE_8x32,     8,  -36,  390,    1
    subsprite OAM_SIZE_16x8,    -8,  -36,  466,    1
  FileD3FA_Obj_136:
    subsprite OAM_SIZE_16x32,   -8,  -28,  386,    1
    subsprite OAM_SIZE_8x32,     8,  -36,  391,    1
    subsprite OAM_SIZE_16x8,    -8,  -36,  466,    1
  FileD3FA_Obj_139:
    subsprite OAM_SIZE_16x32,   -8,  -28,  388,    1
    subsprite OAM_SIZE_8x32,     8,  -36,  392,    1
    subsprite OAM_SIZE_16x8,    -8,  -36,  466,    1
  FileD3FA_Obj_142:
    subsprite OAM_SIZE_16x8,    -8,  -36,  450,    1
    subsprite OAM_SIZE_32x16,  -16,  -28,  324,    1
    subsprite OAM_SIZE_32x8,   -16,  -12,  356,    1
    subsprite OAM_SIZE_32x8,   -16,   -4,  372,    1
  FileD3FA_Obj_146:
    subsprite OAM_SIZE_16x8,    -8,  -36,  450,    1
    subsprite OAM_SIZE_32x16,  -16,  -28,  328,    1
    subsprite OAM_SIZE_32x8,   -16,  -12,  360,    1
    subsprite OAM_SIZE_32x8,   -16,   -4,  376,    1
  FileD3FA_Obj_150:
    subsprite OAM_SIZE_16x8,    -8,  -36,  450,    1
    subsprite OAM_SIZE_32x16,  -16,  -28,  332,    1
    subsprite OAM_SIZE_32x8,   -16,  -12,  364,    1
    subsprite OAM_SIZE_32x8,   -16,   -4,  376,    1
  FileD3FA_Obj_154:
    subsprite OAM_SIZE_32x16,  -16,  -50,  588,    1
    subsprite OAM_SIZE_32x8,   -16,  -34,  500,    1
    subsprite OAM_SIZE_16x32,   -8,  -26,  768,    1
  FileD3FA_Obj_157:
    subsprite OAM_SIZE_16x32,   -8,  -50,  584,    1
    subsprite OAM_SIZE_16x16,   -8,  -18,  586,    1
    subsprite OAM_SIZE_16x8,    -8,   -2,  618,    1
  FileD3FA_Obj_160:
    subsprite OAM_SIZE_16x32,   -8,  -50,  462,    1
    subsprite OAM_SIZE_16x16,   -8,  -18,  492,    1
    subsprite OAM_SIZE_8x16,   -16,  -34,  483,    1
    subsprite OAM_SIZE_16x8,    -8,   -2,  618,    1
  FileD3FA_Obj_164:
    subsprite OAM_SIZE_16x32,   -8,  -50,  458,    1
    subsprite OAM_SIZE_16x16,   -8,  -18,  460,    1
    subsprite OAM_SIZE_16x8,    -8,   -2,  618,    1
  FileD3FA_Obj_167:
    subsprite OAM_SIZE_32x16,  -16,  -50,  452,    1
    subsprite OAM_SIZE_32x8,   -16,  -34,  484,    1
    subsprite OAM_SIZE_16x32,   -8,  -26,  456,    1
  FileD3FA_Obj_170:
    subsprite OAM_SIZE_16x16,   -9,  -18,  460,    1, xflip=1
    subsprite OAM_SIZE_16x8,    -9,   -2,  618,    1, xflip=1
    subsprite OAM_SIZE_16x8,    -9,  -50,  458,    1, xflip=1
    subsprite OAM_SIZE_16x8,    -9,  -26,  506,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -42, 1002,    1
  FileD3FA_Obj_175:
    subsprite OAM_SIZE_16x32,   -9,  -50,  462,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -18,  492,    1, xflip=1
    subsprite OAM_SIZE_8x16,     7,  -34,  483,    1, xflip=1
    subsprite OAM_SIZE_16x8,    -9,   -2,  618,    1, xflip=1
  FileD3FA_Obj_179:
    subsprite OAM_SIZE_16x32,   -9,  -50,  584,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -18,  586,    1, xflip=1
    subsprite OAM_SIZE_16x8,    -9,   -2,  618,    1, xflip=1
  FileD3FA_Obj_182:
    subsprite OAM_SIZE_32x16,  -16,  -36,  802,    1
    subsprite OAM_SIZE_16x16,   -8,  -20,  778,    1
    subsprite OAM_SIZE_8x8,      0,   -4,  870,    1
    subsprite OAM_SIZE_16x8,     8,  -20,  826,    1
    subsprite OAM_SIZE_8x8,     16,  -28,  871,    1
  FileD3FA_Obj_187:
    subsprite OAM_SIZE_32x16,  -16,  -36,  836,    1
    subsprite OAM_SIZE_16x16,   -8,  -20,  868,    1
    subsprite OAM_SIZE_8x8,     16,  -28,  897,    1
    subsprite OAM_SIZE_8x8,      8,  -20,  912,    1
    subsprite OAM_SIZE_8x8,      0,   -4,  913,    1
    subsprite OAM_SIZE_8x8,     -8,  -44,  896,    1
  FileD3FA_Obj_193:
    subsprite OAM_SIZE_32x32,  -19,  -27,  840,    1
    subsprite OAM_SIZE_16x8,   -11,  -35,  930,    1
  FileD3FA_Obj_195:
    subsprite OAM_SIZE_32x32,  -19,  -27,  844,    1
    subsprite OAM_SIZE_16x8,    -3,    5,  944,    1
  FileD3FA_Obj_197:
    subsprite OAM_SIZE_32x32,  -18,  -28, 1028,    1
    subsprite OAM_SIZE_8x8,     -2,  -36, 1099,    1
    subsprite OAM_SIZE_8x16,    14,  -12,  971,    1
  FileD3FA_Obj_200:
    subsprite OAM_SIZE_32x32,  -19,  -27, 1036,    1
    subsprite OAM_SIZE_8x8,    -11,  -35, 1114,    1
  FileD3FA_Obj_202:
    subsprite OAM_SIZE_32x32,  -19,  -27, 1092,    1
    subsprite OAM_SIZE_16x8,    -3,    5, 1144,    1
  FileD3FA_Obj_204:
    subsprite OAM_SIZE_32x16,  -16,  -36,  620,    1
    subsprite OAM_SIZE_32x8,   -24,  -20,  780,    1
    subsprite OAM_SIZE_16x16,   -8,  -12,  798,    1
    subsprite OAM_SIZE_8x8,     -8,  -44,  498,    1
  FileD3FA_Obj_208:
    subsprite OAM_SIZE_32x16,  -16,  -36,  770,    1
    subsprite OAM_SIZE_32x8,   -24,  -20,  828,    1
    subsprite OAM_SIZE_16x16,   -8,  -12,  796,    1
    subsprite OAM_SIZE_8x8,    -24,  -28,  634,    1
    subsprite OAM_SIZE_8x8,     -8,  -44,  635,    1
  FileD3FA_Obj_213:
    subsprite OAM_SIZE_32x32,  -16,  -28,  774,    1
    subsprite OAM_SIZE_16x8,    -8,  -36,  810,    1
  FileD3FA_Obj_215:
    subsprite OAM_SIZE_32x32,  -16,  -28,  832,    1
    subsprite OAM_SIZE_16x8,   -16,    4,  886,    1
  FileD3FA_Obj_217:
    subsprite OAM_SIZE_32x32,  -16,  -28, 1024,    1
  FileD3FA_Obj_218:
    subsprite OAM_SIZE_32x32,  -16,  -28, 1032,    1
    subsprite OAM_SIZE_8x8,      0,  -36, 1098,    1
  FileD3FA_Obj_220:
    subsprite OAM_SIZE_32x32,  -16,  -28, 1088,    1
    subsprite OAM_SIZE_16x8,   -16,    4, 1128,    1
  FileD3FA_Obj_222:
    subsprite OAM_SIZE_32x16,  -16,  -28,  900,    1
    subsprite OAM_SIZE_32x16,  -24,  -12,  932,    1
    subsprite OAM_SIZE_8x8,      8,  -12,  929,    1
    subsprite OAM_SIZE_16x16,  -16,  -44,  898,    1
    subsprite OAM_SIZE_8x8,      0,  -36,  928,    1
  FileD3FA_Obj_227:
    subsprite OAM_SIZE_16x32,   -8,  -28,  904,    1
    subsprite OAM_SIZE_16x16,  -24,  -12,  938,    1
    subsprite OAM_SIZE_8x16,   -16,  -28,  263,    1
    subsprite OAM_SIZE_8x8,     -8,    4,  946,    1
  FileD3FA_Obj_231:
    subsprite OAM_SIZE_16x32,   -8,  -28,  908,    1
    subsprite OAM_SIZE_16x16,  -24,  -12,  906,    1
    subsprite OAM_SIZE_8x16,   -16,  -28,  262,    1
    subsprite OAM_SIZE_8x8,     -8,    4,  946,    1
  FileD3FA_Obj_235:
    subsprite OAM_SIZE_32x32,  -24,  -28,  960,    1
  FileD3FA_Obj_236:
    subsprite OAM_SIZE_16x32,   -8,  -36,  910,    1
    subsprite OAM_SIZE_8x8,    -16,  -20,  947,    1
    subsprite OAM_SIZE_8x32,     8,  -28,  964,    1
    subsprite OAM_SIZE_16x8,    -8,   -4,  382,    1
    subsprite OAM_SIZE_8x8,     16,  -12,  380,    1
  FileD3FA_Obj_241:
    subsprite OAM_SIZE_16x32,   -8,  -20,  965,    1
    subsprite OAM_SIZE_8x16,   -16,  -12,  295,    1
    subsprite OAM_SIZE_8x8,     -8,  -28,  381,    1
    subsprite OAM_SIZE_8x16,     8,  -12,  970,    1
  FileD3FA_Obj_245:
    subsprite OAM_SIZE_16x32,   -8,  -20,  968,    1
    subsprite OAM_SIZE_8x32,   -16,  -20,  967,    1
    subsprite OAM_SIZE_8x8,     -8,  -28,  294,    1
    subsprite OAM_SIZE_8x16,     8,  -12,  970,    1
  FileD3FA_Obj_249:
    subsprite OAM_SIZE_32x32,  -17,  -18,  972,    1
    subsprite OAM_SIZE_8x8,    -25,   -2,  310,    1
  FileD3FA_Obj_251:
    subsprite OAM_SIZE_16x8,    -8,   -8,  270,    4
  FileD3FA_Obj_252:
    subsprite OAM_SIZE_16x32,   -8,  -32,  268,    4
    subsprite OAM_SIZE_8x8,    -16,   -8,  151,    4
    subsprite OAM_SIZE_8x16,     8,  -16,  303,    4
    subsprite OAM_SIZE_16x8,    -8,  -40,  270,    4
  FileD3FA_Obj_256:
    subsprite OAM_SIZE_16x32,   -8,  -64,  268,    4
    subsprite OAM_SIZE_8x8,    -16,  -40,  151,    4
    subsprite OAM_SIZE_8x16,     8,  -48,  303,    4
    subsprite OAM_SIZE_32x32,  -16,  -32,  320,    4
    subsprite OAM_SIZE_8x16,   -24,  -16,  302,    4
    subsprite OAM_SIZE_8x8,     16,   -8,  482,    4
    subsprite OAM_SIZE_16x8,    -8,  -72,  270,    4
    subsprite OAM_SIZE_32x8,   -16,    0,  312,    4
  FileD3FA_Obj_264:
    subsprite OAM_SIZE_8x16,     8,  -59,  303,    4
    subsprite OAM_SIZE_16x32,   -8,  -75,  268,    4
    subsprite OAM_SIZE_8x8,    -16,  -51,  151,    4
    subsprite OAM_SIZE_32x32,  -16,  -43,  320,    4
    subsprite OAM_SIZE_8x16,   -24,  -27,  302,    4
    subsprite OAM_SIZE_8x8,     16,  -19,  482,    4
    subsprite OAM_SIZE_32x8,   -24,  -11,  280,    4
    subsprite OAM_SIZE_16x8,     8,  -11,  286,    4
    subsprite OAM_SIZE_32x16,  -16,   -4,  236,    4
    subsprite OAM_SIZE_16x8,    -8,  -83,  270,    4
  FileD3FA_Obj_274:
    subsprite OAM_SIZE_8x16,     8,  -60,  303,    4
    subsprite OAM_SIZE_16x32,   -8,  -76,  268,    4
    subsprite OAM_SIZE_32x32,  -16,  -44,  320,    4
    subsprite OAM_SIZE_8x8,    -16,  -52,  151,    4
    subsprite OAM_SIZE_8x8,     16,  -20,  482,    4
    subsprite OAM_SIZE_32x8,   -24,  -12,  280,    4
    subsprite OAM_SIZE_16x8,     8,  -12,  286,    4
    subsprite OAM_SIZE_8x16,   -24,  -28,  302,    4
    subsprite OAM_SIZE_32x16,  -16,   -4,  296,    4
    subsprite OAM_SIZE_16x8,    -8,  -84,  270,    4
  FileD3FA_Obj_284:
    subsprite OAM_SIZE_8x16,     8,  -61,  303,    4
    subsprite OAM_SIZE_16x32,   -8,  -77,  268,    4
    subsprite OAM_SIZE_32x32,  -16,  -45,  320,    4
    subsprite OAM_SIZE_8x8,    -16,  -53,  151,    4
    subsprite OAM_SIZE_8x8,     16,  -21,  482,    4
    subsprite OAM_SIZE_32x8,   -24,  -13,  280,    4
    subsprite OAM_SIZE_16x8,     8,  -13,  286,    4
    subsprite OAM_SIZE_8x16,   -24,  -29,  302,    4
    subsprite OAM_SIZE_32x16,  -16,   -5,  296,    4
    subsprite OAM_SIZE_16x8,    -8,  -85,  270,    4
  FileD3FA_Obj_294:
    subsprite OAM_SIZE_32x32,  -16,  -24,   64,    5
    subsprite OAM_SIZE_16x16,   -8,  -40, 1134,    5
  FileD3FA_Obj_296:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1152,    5
    subsprite OAM_SIZE_16x16,   -8,  -40, 1100,    5
  FileD3FA_Obj_298:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1156,    5
    subsprite OAM_SIZE_16x16,   -8,  -40, 1102,    5
  FileD3FA_Obj_300:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1160,    5
    subsprite OAM_SIZE_16x16,   -8,  -40, 1132,    5
  FileD3FA_Obj_302:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -33, 1196,    2
  FileD3FA_Obj_304:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -32, 1164,    2
  FileD3FA_Obj_306:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33, 1196,    2, xflip=1
  FileD3FA_Obj_308:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -32, 1164,    2, xflip=1
  FileD3FA_Obj_310:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -32,  138,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_313:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -33,  138,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_316:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -32, 1096,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_319:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -33, 1096,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_322:
    subsprite OAM_SIZE_64x64,  -32,  -44,  648,    2
    subsprite OAM_SIZE_16x16,   -8,  -32, 1096,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  524,    2
  FileD3FA_Obj_325:
    subsprite OAM_SIZE_64x64,  -32,  -44,  640,    2
    subsprite OAM_SIZE_16x16,   -8,  -33, 1096,    1
    subsprite OAM_SIZE_32x32,  -16,  -28,  520,    2
  FileD3FA_Obj_328:
    subsprite OAM_SIZE_32x32,  -16,  -36, 1216,    1
    subsprite OAM_SIZE_16x8,    -8,   -4, 1146,    1

2:
FileD3FA_Cmds:
  FileD3FA_Cmd_0:
    animcmd   0,    4
    animcmd   1,    4
    animcmd   2,    4
    animcmd   3,    4
  FileD3FA_Cmd_4:
    animcmd   0,    1
  FileD3FA_Cmd_5:
    animcmd   4,    1
  FileD3FA_Cmd_6:
    animcmd   5,    1
  FileD3FA_Cmd_7:
    animcmd   6,    1
  FileD3FA_Cmd_8:
    animcmd   7,    1
  FileD3FA_Cmd_9:
    animcmd   8,    1
  FileD3FA_Cmd_10:
    animcmd   9,    6
    animcmd  10,    5
    animcmd  11,    2
    animcmd  12,   40
  FileD3FA_Cmd_14:
    animcmd   9,    6
    animcmd  86,    5
    animcmd  87,    2
    animcmd  13,   40
  FileD3FA_Cmd_18:
    animcmd   9,    6
    animcmd  88,    5
    animcmd  89,    2
    animcmd  14,   40
  FileD3FA_Cmd_22:
    animcmd   9,    6
    animcmd  90,    5
    animcmd  91,    2
    animcmd  15,   40
  FileD3FA_Cmd_26:
    animcmd  12,    1
  FileD3FA_Cmd_27:
    animcmd  13,    1
  FileD3FA_Cmd_28:
    animcmd  14,    1
  FileD3FA_Cmd_29:
    animcmd  15,    1
  FileD3FA_Cmd_30:
    animcmd  11,    6
    animcmd   9,    8
    animcmd   7,    7
    animcmd   5,    6
    animcmd   4,    4
    animcmd   0,   19
  FileD3FA_Cmd_36:
    animcmd  87,    6
    animcmd   9,    8
    animcmd   7,    7
    animcmd   5,    6
    animcmd   4,    4
    animcmd   0,   19
  FileD3FA_Cmd_42:
    animcmd  89,    6
    animcmd   9,    8
    animcmd   7,    7
    animcmd   5,    6
    animcmd   4,    4
    animcmd   0,   19
  FileD3FA_Cmd_48:
    animcmd  91,    6
    animcmd   9,    8
    animcmd   7,    7
    animcmd   5,    6
    animcmd   4,    4
    animcmd   0,   19
  FileD3FA_Cmd_54:
    animcmd  18,    5
    animcmd  19,    5
    animcmd  16,    5
    animcmd  17,    5
  FileD3FA_Cmd_58:
    animcmd  22,    5
    animcmd  23,    5
    animcmd  20,    5
    animcmd  21,    5
  FileD3FA_Cmd_62:
    animcmd  26,    5
    animcmd  27,    5
    animcmd  24,    5
    animcmd  25,    5
  FileD3FA_Cmd_66:
    animcmd  30,    5
    animcmd  31,    5
    animcmd  28,    5
    animcmd  29,    5
  FileD3FA_Cmd_70:
    animcmd  32,    1
  FileD3FA_Cmd_71:
    animcmd  33,    1
  FileD3FA_Cmd_72:
    animcmd  34,    1
  FileD3FA_Cmd_73:
    animcmd  35,    1
  FileD3FA_Cmd_74:
    animcmd  36,   10
    animcmd  37,    6
    animcmd  38,   10
    animcmd  37,   13
  FileD3FA_Cmd_78:
    animcmd  39,   10
    animcmd  40,    6
    animcmd  41,   10
    animcmd  40,   13
  FileD3FA_Cmd_82:
    animcmd  49,    4
    animcmd  48,    4
    animcmd  47,    4
    animcmd  46,    4
    animcmd  45,    4
    animcmd  44,    4
    animcmd  43,    4
    animcmd  42,    4
  FileD3FA_Cmd_90:
    animcmd  50,    1
  FileD3FA_Cmd_91:
    animcmd  51,    1
  FileD3FA_Cmd_92:
    animcmd  52,    6
  FileD3FA_Cmd_93:
    animcmd  53,    5
    animcmd  56,    5
  FileD3FA_Cmd_95:
    animcmd  53,    5
    animcmd  55,    8
    animcmd  54,    8
  FileD3FA_Cmd_98:
    animcmd  57,    1
  FileD3FA_Cmd_99:
    animcmd  58,    1
  FileD3FA_Cmd_100:
    animcmd  59,    6
  FileD3FA_Cmd_101:
    animcmd  60,    5
    animcmd  63,    5
  FileD3FA_Cmd_103:
    animcmd  60,    5
    animcmd  62,    8
    animcmd  61,    8
  FileD3FA_Cmd_106:
    animcmd  68,   10
    animcmd  69,   20
    animcmd  70,   20
    animcmd  69,   20
    animcmd  70,   20
    animcmd  69,   20
    animcmd  70,   20
    animcmd  69,   20
    animcmd  70,    6
    animcmd  71,  130
  FileD3FA_Cmd_116:
    animcmd  64,   10
    animcmd  65,   20
    animcmd  66,   20
    animcmd  65,   20
    animcmd  66,   20
    animcmd  65,   20
    animcmd  66,   20
    animcmd  65,   20
    animcmd  66,    6
    animcmd  67,  130
  FileD3FA_Cmd_126:
    animcmd  72,    4
    animcmd  73,    4
    animcmd  74,    4
    animcmd  75,    4
    animcmd  76,    4
    animcmd  77,    6
    animcmd  76,    8
    animcmd  75,    8
  FileD3FA_Cmd_134:
    animcmd  75,    1
  FileD3FA_Cmd_135:
    animcmd   0,    4
    animcmd  78,    4
    animcmd   1,    4
    animcmd  79,    4
    animcmd   2,    4
    animcmd  80,    4
    animcmd   3,    4
    animcmd  81,    4
  FileD3FA_Cmd_143:
    animcmd   9,    6
    animcmd  82,    5
    animcmd  83,    2
    animcmd  83,   40
  FileD3FA_Cmd_147:
    animcmd  83,    1
  FileD3FA_Cmd_148:
    animcmd  83,    6
    animcmd   9,    8
    animcmd   7,    7
    animcmd   5,    6
    animcmd   4,    4
    animcmd   0,   19
  FileD3FA_Cmd_154:
    animcmd  85,    5
    animcmd  84,    5
    animcmd  83,    5
    animcmd  82,    5
  FileD3FA_Cmd_158:
    animcmd  92,    1

FileD3FA_Tiles:
  .incbin "data/sprite_main/durathror.4bpp"
