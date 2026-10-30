File5D36_Header:
  .2byte 7 @ palStart
  .2byte 75 @ metaspriteCount
  .2byte 25 @ animationCount
  .2byte 685 @ subspriteCount
  .2byte 83 @ cmdCount
  .2byte 1792 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 1532 @ offsetToAnims
  .4byte 1732 @ offsetToSubsprites
  .4byte 7212 @ offsetToCmds
  .4byte 7544 @ offsetToTiles

File5D36_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x4EF9, File5D36_Obj_0,     6,          -49,  -81,   23,   15
  pose 0x4EFA, File5D36_Obj_6,     8,          -25,  -65,   23,   15
  pose 0x4EFB, File5D36_Obj_14,    5,          -49,  -81,   15,   15
  pose 0x4EFC, File5D36_Obj_19,    5,          -49,  -81,   23,   31
  pose 0x4EFD, File5D36_Obj_24,    7,          -49,  -81,   23,   15
  pose 0x3100, File5D36_Obj_31,    10,         -45,  -78,   26,   16
  pose 0x3500, File5D36_Obj_41,    10,         -45,  -78,   26,   16
  pose 0x3900, File5D36_Obj_51,    11,         -49,  -79,   22,   16
  pose 0x3D00, File5D36_Obj_62,    11,         -49,  -79,   22,   16
  pose 0x4100, File5D36_Obj_73,    8,          -46,  -81,   28,   16
  pose 0x4500, File5D36_Obj_81,    8,          -47,  -83,   28,   16
  pose 0x4900, File5D36_Obj_89,    8,          -49,  -97,   28,   17
  pose 0x4D00, File5D36_Obj_97,    8,          -50,  -98,   27,   17
  pose 0x5100, File5D36_Obj_105,   11,         -53,  -80,   22,   17
  pose 0x5500, File5D36_Obj_116,   8,          -48,  -80,   25,   17
  pose 0x30FE, File5D36_Obj_124,   5,          -55,  -72,   28,   14
  pose 0x34FE, File5D36_Obj_129,   5,          -55,  -73,   27,   14
  pose 0x38FE, File5D36_Obj_134,   8,          -55,  -75,   21,   14
  pose 0x3CFE, File5D36_Obj_142,   8,          -55,  -75,   21,   14
  pose 0x40FE, File5D36_Obj_150,   8,          -56,  -75,   24,   14
  pose 0x44FE, File5D36_Obj_158,   8,          -58,  -75,   22,   14
  pose 0x48FE, File5D36_Obj_166,   10,         -89,  -99,   14,   19
  pose 0x4CFE, File5D36_Obj_176,   10,         -91, -101,   13,   19
  pose 0x50FE, File5D36_Obj_186,   10,         -71,  -85,   26,   18
  pose 0x54FE, File5D36_Obj_196,   10,         -47,  -85,   29,   18
  pose 0x372E, File5D36_Obj_206,   3,          -49,  -82,   23,   14
  pose 0x372F, File5D36_Obj_209,   7,          -49,  -72,   31,   24
  pose 0x3730, File5D36_Obj_216,   4,          -48,  -71,   24,    9
  pose 0x3731, File5D36_Obj_220,   4,          -48,  -71,   24,    9
  pose 0xEF96, File5D36_Obj_224,   10,         -42,  -61,   17,    3
  pose 0xF396, File5D36_Obj_234,   10,         -43,  -60,   16,    2
  pose 0xF796, File5D36_Obj_244,   12,         -51,  -66,   24,   15
  pose 0xFB96, File5D36_Obj_256,   12,         -52,  -65,   22,   16
  pose 0xEF94, File5D36_Obj_268,   9,          -50,  -77,   28,    8
  pose 0xF394, File5D36_Obj_277,   8,          -51,  -78,   27,    6
  pose 0xF794, File5D36_Obj_285,   9,          -46,  -63,   15,    0
  pose 0xFB94, File5D36_Obj_294,   9,          -47,  -63,   13,    0
  pose 0xDEF4, File5D36_Obj_303,   5,          -49,  -81,   19,    8
  pose 0xDEF5, File5D36_Obj_308,   7,          -48,  -72,   23,    8
  pose 0xDEF6, File5D36_Obj_315,   7,          -48,  -73,   24,    8
  pose 0xDEF7, File5D36_Obj_322,   8,          -52,  -75,   20,    8
  pose 0xDEF8, File5D36_Obj_330,   9,          -88,  -71,   17,   17
  pose 0xDEF9, File5D36_Obj_339,   8,          -65,  -69,   17,   17
  pose 0xDEFA, File5D36_Obj_347,   8,          -63,  -69,   17,   17
  pose 0xDEFB, File5D36_Obj_355,   5,          -48,  -73,   16,    6
  pose 0xDEFC, File5D36_Obj_360,   1,          -55,  -76,    9,    0
  pose 0xDEFD, File5D36_Obj_361,   2,          -40,  -44,    0,    0
  pose 0x5422, File5D36_Obj_363,   14,         -74,  -82,   30,   23
  pose 0x5822, File5D36_Obj_377,   13,         -71,  -77,   25,    6
  pose 0x5C22, File5D36_Obj_390,   13,         -73,  -77,   23,    6
  pose 0x6022, File5D36_Obj_403,   12,         -56,  -91,   31,    7
  pose 0x6422, File5D36_Obj_415,   15,         -56,  -93,   33,   18
  pose 0x6822, File5D36_Obj_430,   13,         -52,  -93,   34,    8
  pose 0x6C22, File5D36_Obj_443,   15,         -53,  -91,  248,  112
  pose 0x7022, File5D36_Obj_458,   13,         -54,  -92,   33,   10
  pose 0x7422, File5D36_Obj_471,   11,         -55,  -54,   10,   11
  pose 0x7822, File5D36_Obj_482,   10,         -30,  -63,   13,    0
  pose 0x1823, File5D36_Obj_492,   10,         -31,  -64,   12,    0
  pose 0x1C23, File5D36_Obj_502,   14,         -72,  -82,   30,   22
  pose 0x2023, File5D36_Obj_516,   10,         -43,  -66,   33,    6
  pose 0x2423, File5D36_Obj_526,   8,          -49,  -76,   28,    3
  pose 0x5420, File5D36_Obj_534,   14,         -86,  -86,   19,    0
  pose 0x5820, File5D36_Obj_548,   8,          -71,  -80,   17,   24
  pose 0x5C20, File5D36_Obj_556,   8,          -73,  -82,   16,   24
  pose 0x6020, File5D36_Obj_564,   17,         -63,  -78,   45,   12
  pose 0x6420, File5D36_Obj_581,   11,         -49,  -68,   45,   20
  pose 0x6820, File5D36_Obj_592,   12,         -52,  -69,   45,   28
  pose 0x6C20, File5D36_Obj_604,   9,          -53,  -70,   45,   28
  pose 0x7020, File5D36_Obj_613,   10,         -55,  -72,   45,   28
  pose 0x7420, File5D36_Obj_623,   5,          -56,  -73,   13,    0
  pose 0x7820, File5D36_Obj_628,   11,         -31,  -61,   10,    0
  pose 0x1821, File5D36_Obj_639,   10,         -32,  -62,    8,    0
  pose 0x1C21, File5D36_Obj_649,   14,         -84,  -83,   17,    0
  pose 0x2021, File5D36_Obj_663,   8,          -46,  -74,   30,    8
  pose 0x2421, File5D36_Obj_671,   14,         -32,  -60,   19,    1

File5D36_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x4A76, File5D36_Cmd_0,     1
  animation 0x4A77, File5D36_Cmd_1,     1
  animation 0x4A78, File5D36_Cmd_2,     1
  animation 0x4A79, File5D36_Cmd_3,     1
  animation 0x4A7A, File5D36_Cmd_4,     1
  animation 0x156F, File5D36_Cmd_5,     4
  animation 0x156D, File5D36_Cmd_9,     4
  animation 0x196F, File5D36_Cmd_13,    1
  animation 0x196D, File5D36_Cmd_14,    1
  animation 0x7093, File5D36_Cmd_15,    1
  animation 0x7091, File5D36_Cmd_16,    1
  animation 0x7493, File5D36_Cmd_17,    8
  animation 0x7491, File5D36_Cmd_25,    8
  animation 0xF1B7, File5D36_Cmd_33,    8
  animation 0xC999, File5D36_Cmd_41,    8
  animation 0xC997, File5D36_Cmd_49,    8
  animation 0x78B6, File5D36_Cmd_57,    10
  animation 0x7C43, File5D36_Cmd_67,    1
  animation 0x7C41, File5D36_Cmd_68,    1
  animation 0x8043, File5D36_Cmd_69,    2
  animation 0x8041, File5D36_Cmd_71,    2
  animation 0x8443, File5D36_Cmd_73,    3
  animation 0x8441, File5D36_Cmd_76,    3
  animation 0x336A, File5D36_Cmd_79,    2
  animation 0x332A, File5D36_Cmd_81,    2

1:
File5D36_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  File5D36_Obj_0:
    subsprite OAM_SIZE_32x32,  -17,  -49,    0,    0
    subsprite OAM_SIZE_32x16,  -17,  -17,   64,    0
    subsprite OAM_SIZE_16x8,   -17,   -1,   96,    0
    subsprite OAM_SIZE_16x8,    -1,   -1,   98,    0
    subsprite OAM_SIZE_8x16,   -25,  -34,  112,    0
    subsprite OAM_SIZE_8x16,    15,  -34,  113,    0
  File5D36_Obj_6:
    subsprite OAM_SIZE_16x8,     7,  -17,  102,    0
    subsprite OAM_SIZE_16x16,   -9,  -17,   38,    0
    subsprite OAM_SIZE_8x16,   -17,  -41,  114,    0
    subsprite OAM_SIZE_8x16,   -17,  -17,  115,    0
    subsprite OAM_SIZE_8x16,     7,   -9,    6,    0
    subsprite OAM_SIZE_16x8,    -9,   -1,  100,    0
    subsprite OAM_SIZE_16x32,   -9,  -49,    4,    0
    subsprite OAM_SIZE_16x16,    7,  -33,  398,    0
  File5D36_Obj_14:
    subsprite OAM_SIZE_32x32,  -17,  -49,    8,    0
    subsprite OAM_SIZE_32x16,  -17,  -17,   72,    0
    subsprite OAM_SIZE_16x8,   -17,   -1,  104,    0
    subsprite OAM_SIZE_8x8,     -1,   -1,  106,    0
    subsprite OAM_SIZE_8x8,     -1,    7,    7,    0
  File5D36_Obj_19:
    subsprite OAM_SIZE_32x32,  -17,  -49,   12,    0
    subsprite OAM_SIZE_32x16,  -17,  -17,   76,    0
    subsprite OAM_SIZE_32x8,   -17,   -1,  108,    0
    subsprite OAM_SIZE_8x8,     15,  -26,  107,    0
    subsprite OAM_SIZE_8x8,     -9,    7,  180,    0
  File5D36_Obj_24:
    subsprite OAM_SIZE_32x32,  -17,  -49,  144,    0
    subsprite OAM_SIZE_32x16,  -17,  -17,  208,    0
    subsprite OAM_SIZE_16x8,   -17,   -1,  240,    0
    subsprite OAM_SIZE_16x8,    -1,   -1,  242,    0
    subsprite OAM_SIZE_8x16,   -25,  -24,  116,    0
    subsprite OAM_SIZE_8x16,    15,  -24,  148,    0
    subsprite OAM_SIZE_8x8,     15,  -32,   23,    0
  File5D36_Obj_31:
    subsprite OAM_SIZE_16x16,  -23,  -37,  970,    0
    subsprite OAM_SIZE_8x16,    -7,  -37, 1003,    0
    subsprite OAM_SIZE_16x32,    2,  -32,  932,    0
    subsprite OAM_SIZE_8x16,    18,  -16, 1002,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  834,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -13,  -46,  768,    0
    subsprite OAM_SIZE_8x8,      6,  -32,  914,    0
  File5D36_Obj_41:
    subsprite OAM_SIZE_16x16,  -23,  -39,  970,    0
    subsprite OAM_SIZE_8x16,    -7,  -39, 1003,    0
    subsprite OAM_SIZE_16x32,    2,  -34,  932,    0
    subsprite OAM_SIZE_8x16,    18,  -18, 1002,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  834,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -13,  -46,  768,    0
    subsprite OAM_SIZE_8x8,      6,  -32,  914,    0
  File5D36_Obj_51:
    subsprite OAM_SIZE_8x8,      5,   -8,  915,    0
    subsprite OAM_SIZE_32x32,  -17,  -40,  776,    0
    subsprite OAM_SIZE_16x16,    6,  -22,  960,    0
    subsprite OAM_SIZE_16x16,    6,  -38,  928,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  832,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -13,  -47,  768,    0
    subsprite OAM_SIZE_16x16,    2,  -37,  992,    0
    subsprite OAM_SIZE_8x8,     -4,  -34,  898,    0
  File5D36_Obj_62:
    subsprite OAM_SIZE_8x8,      5,   -8,  915,    0
    subsprite OAM_SIZE_32x32,  -17,  -42,  776,    0
    subsprite OAM_SIZE_16x16,    6,  -24,  960,    0
    subsprite OAM_SIZE_16x16,    6,  -40,  928,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  832,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -13,  -47,  768,    0
    subsprite OAM_SIZE_16x16,    2,  -37,  992,    0
    subsprite OAM_SIZE_8x8,     -4,  -34,  898,    0
  File5D36_Obj_73:
    subsprite OAM_SIZE_16x16,  -20,  -49,  930,    0
    subsprite OAM_SIZE_32x32,   -4,  -49,  844,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  834,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -14,  -47,  768,    0
    subsprite OAM_SIZE_16x16,    4,  -41,  962,    0
  File5D36_Obj_81:
    subsprite OAM_SIZE_32x32,   -4,  -51,  844,    0
    subsprite OAM_SIZE_16x16,  -20,  -51,  930,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  834,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  896,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  868,    0
    subsprite OAM_SIZE_8x16,     8,   -8,  836,    0
    subsprite OAM_SIZE_32x32,  -15,  -47,  768,    0
    subsprite OAM_SIZE_16x16,    4,  -43,  962,    0
  File5D36_Obj_89:
    subsprite OAM_SIZE_16x32,  -29,  -49,  842,    0
    subsprite OAM_SIZE_16x32,  -29,  -81,  840,    0
    subsprite OAM_SIZE_16x32,   -8,  -31,  837,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  912,    0
    subsprite OAM_SIZE_8x16,     8,   -7,  871,    0
    subsprite OAM_SIZE_32x32,  -17,  -49,  772,    0
    subsprite OAM_SIZE_8x16,   -16,  -15,  839,    0
    subsprite OAM_SIZE_32x32,   -4,  -33,  780,    0
  File5D36_Obj_97:
    subsprite OAM_SIZE_16x32,  -30,  -50,  842,    0
    subsprite OAM_SIZE_16x32,  -30,  -82,  840,    0
    subsprite OAM_SIZE_16x32,   -8,  -31,  837,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  912,    0
    subsprite OAM_SIZE_8x16,     8,   -7,  871,    0
    subsprite OAM_SIZE_32x32,  -18,  -49,  772,    0
    subsprite OAM_SIZE_8x16,   -16,  -15,  839,    0
    subsprite OAM_SIZE_32x32,   -5,  -34,  780,    0
  File5D36_Obj_105:
    subsprite OAM_SIZE_16x8,   -29,  -33, 1669,    0
    subsprite OAM_SIZE_16x16,  -37,  -49, 1636,    0
    subsprite OAM_SIZE_8x16,   -21,  -49, 1638,    0
    subsprite OAM_SIZE_16x32,   -8,  -31,  837,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  912,    0
    subsprite OAM_SIZE_8x16,     8,   -7,  871,    0
    subsprite OAM_SIZE_32x32,  -17,  -48,  772,    0
    subsprite OAM_SIZE_8x16,   -16,  -15,  839,    0
    subsprite OAM_SIZE_16x32,   -2,  -33, 1684,    0
    subsprite OAM_SIZE_8x16,    14,  -17, 1718,    0
    subsprite OAM_SIZE_8x8,     14,  -25, 1702,    0
  File5D36_Obj_116:
    subsprite OAM_SIZE_16x16,  -24,  -44, 1538,    0
    subsprite OAM_SIZE_16x32,   -8,  -31,  837,    0
    subsprite OAM_SIZE_16x8,    -8,    1,  912,    0
    subsprite OAM_SIZE_8x16,     8,   -7,  871,    0
    subsprite OAM_SIZE_32x32,  -16,  -48,  772,    0
    subsprite OAM_SIZE_8x16,   -16,  -15,  839,    0
    subsprite OAM_SIZE_16x16,    1,  -28, 1540,    0
    subsprite OAM_SIZE_8x16,    17,  -28, 1542,    0
  File5D36_Obj_124:
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_32x32,  -12,  -40,  576,    0
    subsprite OAM_SIZE_8x16,    20,  -24,  612,    0
    subsprite OAM_SIZE_16x16,  -19,   -8,  580,    0
    subsprite OAM_SIZE_8x16,   -27,   -8,  613,    0
  File5D36_Obj_129:
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_32x32,  -13,  -41,  576,    0
    subsprite OAM_SIZE_8x16,    19,  -25,  612,    0
    subsprite OAM_SIZE_16x16,  -20,   -9,  580,    0
    subsprite OAM_SIZE_8x16,   -28,   -9,  613,    0
  File5D36_Obj_134:
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_8x8,     -6,  -26,  710,    0
    subsprite OAM_SIZE_32x16,  -19,  -43,  516,    0
    subsprite OAM_SIZE_16x8,   -19,  -27,  548,    0
    subsprite OAM_SIZE_16x8,    -3,  -27,  550,    0
    subsprite OAM_SIZE_32x32,  -19,  -30,  582,    0
    subsprite OAM_SIZE_8x8,    -11,    2,  587,    0
    subsprite OAM_SIZE_8x16,    13,  -30,  586,    0
  File5D36_Obj_142:
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_8x8,     -6,  -26,  710,    0
    subsprite OAM_SIZE_32x16,  -19,  -43,  516,    0
    subsprite OAM_SIZE_16x8,   -19,  -27,  548,    0
    subsprite OAM_SIZE_16x8,    -3,  -27,  550,    0
    subsprite OAM_SIZE_32x32,  -19,  -33,  582,    0
    subsprite OAM_SIZE_8x8,    -11,   -1,  587,    0
    subsprite OAM_SIZE_8x16,    13,  -33,  586,    0
  File5D36_Obj_150:
    subsprite OAM_SIZE_8x8,     -6,  -26,  710,    0
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_32x16,  -20,  -43,  516,    0
    subsprite OAM_SIZE_16x8,   -20,  -28,  548,    0
    subsprite OAM_SIZE_16x8,    -4,  -28,  550,    0
    subsprite OAM_SIZE_32x32,  -24,  -38,  908,    0
    subsprite OAM_SIZE_16x32,    8,  -46,  972,    0
    subsprite OAM_SIZE_8x8,      0,  -46,  603,    0
  File5D36_Obj_158:
    subsprite OAM_SIZE_32x16,  -22,  -43,  516,    0
    subsprite OAM_SIZE_16x8,   -22,  -27,  548,    0
    subsprite OAM_SIZE_16x8,    -6,  -27,  550,    0
    subsprite OAM_SIZE_32x32,  -23,  -18,  512,    0
    subsprite OAM_SIZE_16x8,    -6,  -28,  550,    0
    subsprite OAM_SIZE_16x32,    6,  -49,  972,    0
    subsprite OAM_SIZE_8x8,     -2,  -49,  603,    0
    subsprite OAM_SIZE_32x32,  -26,  -41,  908,    0
  File5D36_Obj_166:
    subsprite OAM_SIZE_16x32,   -6,  -83,  526,    0
    subsprite OAM_SIZE_16x32,   -6,  -51,  590,    0
    subsprite OAM_SIZE_16x32,  -11,  -29,  524,    0
    subsprite OAM_SIZE_8x16,   -19,  -13,  588,    0
    subsprite OAM_SIZE_16x8,   -19,    3,  644,    0
    subsprite OAM_SIZE_8x16,     5,  -13,  589,    0
    subsprite OAM_SIZE_32x32,  -18,  -51,  520,    0
    subsprite OAM_SIZE_32x16,  -57,  -36, 1378,    0
    subsprite OAM_SIZE_32x16,  -41,  -20, 1408,    0
    subsprite OAM_SIZE_16x16,  -25,  -36, 1382,    0
  File5D36_Obj_176:
    subsprite OAM_SIZE_16x32,   -8,  -85,  526,    0
    subsprite OAM_SIZE_16x32,   -8,  -53,  590,    0
    subsprite OAM_SIZE_16x32,  -11,  -29,  524,    0
    subsprite OAM_SIZE_8x16,   -19,  -13,  588,    0
    subsprite OAM_SIZE_16x8,   -19,    3,  644,    0
    subsprite OAM_SIZE_8x16,     5,  -13,  589,    0
    subsprite OAM_SIZE_32x32,  -19,  -52,  520,    0
    subsprite OAM_SIZE_32x16,  -59,  -37, 1378,    0
    subsprite OAM_SIZE_32x16,  -43,  -21, 1408,    0
    subsprite OAM_SIZE_16x16,  -27,  -37, 1382,    0
  File5D36_Obj_186:
    subsprite OAM_SIZE_8x16,     2,  -45, 1770,    0
    subsprite OAM_SIZE_16x32,   -8,  -30,  524,    0
    subsprite OAM_SIZE_8x16,   -16,  -14,  588,    0
    subsprite OAM_SIZE_16x8,   -16,    2,  644,    0
    subsprite OAM_SIZE_8x16,     8,  -14,  589,    0
    subsprite OAM_SIZE_32x32,  -16,  -53,  520,    0
    subsprite OAM_SIZE_32x16,  -39,  -27, 1766,    0
    subsprite OAM_SIZE_8x8,    -31,  -11, 1750,    0
    subsprite OAM_SIZE_16x16,   10,  -53, 1771,    0
    subsprite OAM_SIZE_16x8,    10,  -37, 1752,    0
  File5D36_Obj_196:
    subsprite OAM_SIZE_16x16,    5,  -38, 1576,    0
    subsprite OAM_SIZE_8x8,     21,  -30, 1594,    0
    subsprite OAM_SIZE_16x32,   -8,  -30,  524,    0
    subsprite OAM_SIZE_8x16,   -16,  -14,  588,    0
    subsprite OAM_SIZE_16x8,   -16,    2,  644,    0
    subsprite OAM_SIZE_8x16,     8,  -14,  589,    0
    subsprite OAM_SIZE_32x32,  -15,  -53,  520,    0
    subsprite OAM_SIZE_16x16,  -19,  -19, 1579,    0
    subsprite OAM_SIZE_16x8,   -19,  -27, 1563,    0
    subsprite OAM_SIZE_8x8,    -11,  -22,  180,    0
  File5D36_Obj_206:
    subsprite OAM_SIZE_32x32,  -17,  -50,  117,    0
    subsprite OAM_SIZE_32x32,  -17,  -18,  181,    0
    subsprite OAM_SIZE_8x16,    15,  -42,  127,    0
  File5D36_Obj_209:
    subsprite OAM_SIZE_32x32,  -17,  -40,  121,    0
    subsprite OAM_SIZE_8x16,    15,  -40,  125,    0
    subsprite OAM_SIZE_8x16,    15,  -24,  157,    0
    subsprite OAM_SIZE_32x16,  -17,   -8,  185,    0
    subsprite OAM_SIZE_16x8,   -17,    8,  217,    0
    subsprite OAM_SIZE_8x16,    23,  -40,  189,    0
    subsprite OAM_SIZE_8x8,      6,  -48,   23,    0
  File5D36_Obj_216:
    subsprite OAM_SIZE_32x32,  -16,  -39,  416,    0
    subsprite OAM_SIZE_8x16,    16,  -39,  126,    0
    subsprite OAM_SIZE_16x16,  -16,   -7,  480,    0
    subsprite OAM_SIZE_8x8,      0,   -7,  482,    0
  File5D36_Obj_220:
    subsprite OAM_SIZE_32x32,  -16,  -39,  420,    0
    subsprite OAM_SIZE_16x16,  -16,   -7,  158,    0
    subsprite OAM_SIZE_8x8,      0,   -7,  222,    0
    subsprite OAM_SIZE_8x16,    16,  -39,  190,    0
  File5D36_Obj_224:
    subsprite OAM_SIZE_16x16,  -26,  -45,  716,    0
    subsprite OAM_SIZE_16x32,   -2,  -21,  666,    0
    subsprite OAM_SIZE_8x16,   -10,  -21,  649,    0
    subsprite OAM_SIZE_8x8,    -10,   -5,  734,    0
    subsprite OAM_SIZE_16x16,   -9,  -43,  730,    0
    subsprite OAM_SIZE_8x16,   -17,  -43,  729,    0
    subsprite OAM_SIZE_8x8,    -17,  -27,  761,    0
    subsprite OAM_SIZE_16x8,    -9,  -27,  762,    0
    subsprite OAM_SIZE_16x16,    1,  -27,  684,    0
    subsprite OAM_SIZE_8x8,      9,  -11,  637,    0
  File5D36_Obj_234:
    subsprite OAM_SIZE_16x16,  -27,  -44,  716,    0
    subsprite OAM_SIZE_16x32,   -2,  -22,  666,    0
    subsprite OAM_SIZE_8x16,   -10,  -22,  649,    0
    subsprite OAM_SIZE_8x8,    -10,   -6,  734,    0
    subsprite OAM_SIZE_16x16,  -10,  -42,  730,    0
    subsprite OAM_SIZE_8x16,   -18,  -42,  729,    0
    subsprite OAM_SIZE_8x8,    -18,  -26,  761,    0
    subsprite OAM_SIZE_16x8,   -10,  -26,  762,    0
    subsprite OAM_SIZE_16x16,    0,  -26,  684,    0
    subsprite OAM_SIZE_8x8,      8,  -10,  637,    0
  File5D36_Obj_244:
    subsprite OAM_SIZE_16x16,  -24,  -42,  750,    0
    subsprite OAM_SIZE_8x8,    -24,  -50,  618,    0
    subsprite OAM_SIZE_16x8,    -8,   -1,  912,    0
    subsprite OAM_SIZE_8x16,     8,   -9,  871,    0
    subsprite OAM_SIZE_8x8,     -1,  -28,  671,    0
    subsprite OAM_SIZE_8x16,   -16,  -17,  839,    0
    subsprite OAM_SIZE_16x32,   -8,  -33,  837,    0
    subsprite OAM_SIZE_32x16,  -19,  -34,  472,    0
    subsprite OAM_SIZE_16x8,   -19,  -42,  456,    0
    subsprite OAM_SIZE_8x8,     -3,  -42,  458,    0
    subsprite OAM_SIZE_16x16,    0,  -28,  748,    0
    subsprite OAM_SIZE_8x8,     16,  -24,  619,    0
  File5D36_Obj_256:
    subsprite OAM_SIZE_16x16,  -23,  -42,  750,    0
    subsprite OAM_SIZE_8x8,    -23,  -50,  618,    0
    subsprite OAM_SIZE_16x8,    -9,    0,  912,    0
    subsprite OAM_SIZE_8x8,     -2,  -28,  671,    0
    subsprite OAM_SIZE_8x16,     7,   -8,  871,    0
    subsprite OAM_SIZE_8x16,   -17,  -16,  839,    0
    subsprite OAM_SIZE_16x32,   -9,  -32,  837,    0
    subsprite OAM_SIZE_32x16,  -20,  -33,  472,    0
    subsprite OAM_SIZE_16x8,   -20,  -41,  456,    0
    subsprite OAM_SIZE_8x8,     -4,  -41,  458,    0
    subsprite OAM_SIZE_16x16,   -2,  -28,  748,    0
    subsprite OAM_SIZE_8x8,     14,  -24,  619,    0
  File5D36_Obj_268:
    subsprite OAM_SIZE_16x16,    4,  -40,  634,    0
    subsprite OAM_SIZE_8x16,    20,  -40,  620,    0
    subsprite OAM_SIZE_32x32,  -18,  -24,  656,    0
    subsprite OAM_SIZE_16x8,   -10,  -32,  640,    0
    subsprite OAM_SIZE_32x16,  -18,  -45,  720,    0
    subsprite OAM_SIZE_16x8,   -18,  -29,  752,    0
    subsprite OAM_SIZE_8x8,     -2,  -29,  754,    0
    subsprite OAM_SIZE_16x16,  -28,  -24,  680,    0
    subsprite OAM_SIZE_8x8,    -20,  -32,  735,    0
  File5D36_Obj_277:
    subsprite OAM_SIZE_16x16,    3,  -41,  634,    0
    subsprite OAM_SIZE_32x32,  -19,  -26,  656,    0
    subsprite OAM_SIZE_32x16,  -19,  -46,  720,    0
    subsprite OAM_SIZE_16x8,   -19,  -30,  752,    0
    subsprite OAM_SIZE_8x8,     -3,  -30,  754,    0
    subsprite OAM_SIZE_16x16,  -29,  -25,  680,    0
    subsprite OAM_SIZE_8x8,    -21,  -33,  735,    0
    subsprite OAM_SIZE_8x16,    19,  -41,  620,    0
  File5D36_Obj_285:
    subsprite OAM_SIZE_16x16,   -1,  -47,  678,    0
    subsprite OAM_SIZE_16x16,  -21,  -43,  724,    0
    subsprite OAM_SIZE_8x16,    -5,  -43,  726,    0
    subsprite OAM_SIZE_16x8,   -21,  -27,  756,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  758,    0
    subsprite OAM_SIZE_16x16,  -30,  -29,  647,    0
    subsprite OAM_SIZE_16x32,  -17,  -29,  660,    0
    subsprite OAM_SIZE_8x16,    -1,  -28,  646,    0
    subsprite OAM_SIZE_8x8,     -1,  -12,  621,    0
  File5D36_Obj_294:
    subsprite OAM_SIZE_16x16,   -3,  -47,  678,    0
    subsprite OAM_SIZE_16x16,  -22,  -42,  724,    0
    subsprite OAM_SIZE_8x16,    -6,  -42,  726,    0
    subsprite OAM_SIZE_16x8,   -22,  -26,  756,    0
    subsprite OAM_SIZE_8x8,     -6,  -26,  758,    0
    subsprite OAM_SIZE_16x16,  -31,  -29,  647,    0
    subsprite OAM_SIZE_16x32,  -18,  -28,  660,    0
    subsprite OAM_SIZE_8x16,    -2,  -27,  646,    0
    subsprite OAM_SIZE_8x8,     -2,  -11,  621,    0
  File5D36_Obj_303:
    subsprite OAM_SIZE_16x16,    3,  -34, 1480,    0
    subsprite OAM_SIZE_32x32,  -16,  -24, 1356,    0
    subsprite OAM_SIZE_32x32,  -17,  -49, 1292,    0
    subsprite OAM_SIZE_16x16,  -10,  -36, 1512,    0
    subsprite OAM_SIZE_8x16,     6,  -36, 1519,    0
  File5D36_Obj_308:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1356,    0
    subsprite OAM_SIZE_16x16,   -9,  -39, 1482,    0
    subsprite OAM_SIZE_16x8,    -9,  -47, 1318,    0
    subsprite OAM_SIZE_8x16,   -17,  -39, 1350,    0
    subsprite OAM_SIZE_8x8,     15,  -18, 1334,    0
    subsprite OAM_SIZE_32x32,  -11,  -40, 1288,    0
    subsprite OAM_SIZE_8x8,     13,   -8, 1335,    0
  File5D36_Obj_315:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1356,    0
    subsprite OAM_SIZE_16x8,   -16,  -31, 1282,    0
    subsprite OAM_SIZE_8x8,    -16,  -39, 1299,    0
    subsprite OAM_SIZE_16x16,   -8,  -47, 1284,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1314,    0
    subsprite OAM_SIZE_8x8,     16,  -41, 1287,    0
    subsprite OAM_SIZE_8x8,     16,  -25, 1303,    0
  File5D36_Obj_322:
    subsprite OAM_SIZE_16x16,    2,  -34, 1480,    0
    subsprite OAM_SIZE_32x32,  -16,  -24, 1356,    0
    subsprite OAM_SIZE_16x8,   -16,  -31, 1282,    0
    subsprite OAM_SIZE_8x8,    -16,  -39, 1299,    0
    subsprite OAM_SIZE_16x16,   -8,  -47, 1284,    0
    subsprite OAM_SIZE_32x32,  -20,  -43, 1314,    0
    subsprite OAM_SIZE_8x8,     12,  -43, 1287,    0
    subsprite OAM_SIZE_8x8,     12,  -27, 1303,    0
  File5D36_Obj_330:
    subsprite OAM_SIZE_16x8,   -18,    1, 1522,    0
    subsprite OAM_SIZE_16x16,    1,  -32, 1480,    0
    subsprite OAM_SIZE_16x32,  -15,  -53, 1280,    0
    subsprite OAM_SIZE_32x32,  -18,  -31, 1416,    0
    subsprite OAM_SIZE_8x16,     1,  -37, 1286,    0
    subsprite OAM_SIZE_8x8,      1,  -45, 1298,    0
    subsprite OAM_SIZE_32x16,  -56,  -39, 1378,    0
    subsprite OAM_SIZE_16x16,  -24,  -39, 1382,    0
    subsprite OAM_SIZE_32x16,  -40,  -23, 1408,    0
  File5D36_Obj_339:
    subsprite OAM_SIZE_16x16,    1,  -32, 1480,    0
    subsprite OAM_SIZE_32x32,  -18,  -31, 1416,    0
    subsprite OAM_SIZE_16x8,   -18,    1, 1522,    0
    subsprite OAM_SIZE_16x16,  -14,  -53, 1280,    0
    subsprite OAM_SIZE_8x16,     2,  -37, 1286,    0
    subsprite OAM_SIZE_8x8,      2,  -45, 1298,    0
    subsprite OAM_SIZE_16x16,  -14,  -37, 1312,    0
    subsprite OAM_SIZE_32x32,  -33,  -31, 1412,    0
  File5D36_Obj_347:
    subsprite OAM_SIZE_16x16,    1,  -32, 1480,    0
    subsprite OAM_SIZE_32x32,  -18,  -31, 1416,    0
    subsprite OAM_SIZE_16x8,   -18,    1, 1522,    0
    subsprite OAM_SIZE_16x16,  -14,  -53, 1280,    0
    subsprite OAM_SIZE_8x16,     2,  -37, 1286,    0
    subsprite OAM_SIZE_8x8,      2,  -45, 1298,    0
    subsprite OAM_SIZE_16x16,  -14,  -37, 1312,    0
    subsprite OAM_SIZE_32x32,  -31,  -29, 1412,    0
  File5D36_Obj_355:
    subsprite OAM_SIZE_16x32,  -11,  -54, 1344,    0
    subsprite OAM_SIZE_8x16,   -19,  -38, 1351,    0
    subsprite OAM_SIZE_16x8,   -16,  -10, 1504,    0
    subsprite OAM_SIZE_16x8,     0,  -10, 1506,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1440,    0
  File5D36_Obj_360:
    subsprite OAM_SIZE_32x32,  -23,  -44, 1476,    0
  File5D36_Obj_361:
    subsprite OAM_SIZE_8x16,   -24,  -36, 1518,    0
    subsprite OAM_SIZE_16x8,   -24,  -20, 1520,    0
  File5D36_Obj_363:
    subsprite OAM_SIZE_32x16,  -42,  -50, 1168,    0
    subsprite OAM_SIZE_16x8,   -34,  -34, 1200,    0
    subsprite OAM_SIZE_16x8,   -18,  -34, 1202,    0
    subsprite OAM_SIZE_8x8,    -10,  -42, 1155,    0
    subsprite OAM_SIZE_16x16,    1,  -45, 1091,    0
    subsprite OAM_SIZE_32x32,  -18,  -26, 1024,    0
    subsprite OAM_SIZE_16x8,   -26,    6, 1088,    0
    subsprite OAM_SIZE_8x16,   -26,  -10, 1227,    0
    subsprite OAM_SIZE_32x16,   -9,  -42, 1120,    0
    subsprite OAM_SIZE_16x8,    -1,  -26, 1153,    0
    subsprite OAM_SIZE_8x8,     -9,  -26, 1152,    0
    subsprite OAM_SIZE_32x32,   -2,  -25, 1028,    0
    subsprite OAM_SIZE_16x16,    6,    7, 1093,    0
    subsprite OAM_SIZE_8x16,    22,    7, 1095,    0
  File5D36_Obj_377:
    subsprite OAM_SIZE_32x16,  -39,  -45, 1080,    0
    subsprite OAM_SIZE_16x8,   -39,  -29, 1112,    0
    subsprite OAM_SIZE_16x16,  -11,  -36, 1032,    0
    subsprite OAM_SIZE_8x16,     5,  -36, 1034,    0
    subsprite OAM_SIZE_16x8,    -3,  -20, 1065,    0
    subsprite OAM_SIZE_16x8,   -23,  -29, 1114,    0
    subsprite OAM_SIZE_16x16,  -10,  -44, 1091,    0
    subsprite OAM_SIZE_16x32,    1,  -20, 1070,    0
    subsprite OAM_SIZE_8x16,    -7,  -20, 1069,    0
    subsprite OAM_SIZE_8x8,     -6,   -4, 1101,    0
    subsprite OAM_SIZE_32x16,   -7,  -26, 1035,    0
    subsprite OAM_SIZE_16x8,    -7,  -10, 1067,    0
    subsprite OAM_SIZE_8x8,     -1,  -35, 1039,    0
  File5D36_Obj_390:
    subsprite OAM_SIZE_32x16,  -41,  -45, 1080,    0
    subsprite OAM_SIZE_16x8,   -41,  -29, 1112,    0
    subsprite OAM_SIZE_16x8,   -25,  -29, 1114,    0
    subsprite OAM_SIZE_16x16,  -12,  -36, 1032,    0
    subsprite OAM_SIZE_8x16,     4,  -36, 1034,    0
    subsprite OAM_SIZE_16x8,    -4,  -20, 1065,    0
    subsprite OAM_SIZE_16x16,  -11,  -44, 1091,    0
    subsprite OAM_SIZE_8x8,     -2,  -35, 1039,    0
    subsprite OAM_SIZE_16x32,    1,  -20, 1070,    0
    subsprite OAM_SIZE_8x16,    -9,  -21, 1069,    0
    subsprite OAM_SIZE_8x8,     -9,   -5, 1101,    0
    subsprite OAM_SIZE_32x16,   -9,  -26, 1035,    0
    subsprite OAM_SIZE_16x8,    -9,  -10, 1067,    0
  File5D36_Obj_403:
    subsprite OAM_SIZE_16x16,  -27,  -50, 1164,    0
    subsprite OAM_SIZE_8x16,   -11,  -42, 1222,    0
    subsprite OAM_SIZE_8x8,    -27,  -58, 1090,    0
    subsprite OAM_SIZE_32x32,   -9,  -25, 1128,    0
    subsprite OAM_SIZE_32x32,  -17,  -41, 1124,    0
    subsprite OAM_SIZE_16x16,   -9,  -44, 1091,    0
    subsprite OAM_SIZE_16x8,    -9,  -33, 1150,    0
    subsprite OAM_SIZE_16x8,     0,  -24, 1116,    0
    subsprite OAM_SIZE_16x16,    7,  -17, 1132,    0
    subsprite OAM_SIZE_32x16,  -24,  -59, 1190,    1
    subsprite OAM_SIZE_8x8,    -24,  -43,  191,    1
    subsprite OAM_SIZE_32x32,   -1,  -29, 1196,    1
  File5D36_Obj_415:
    subsprite OAM_SIZE_32x32,  -19,  -25, 1216,    0
    subsprite OAM_SIZE_16x16,  -16,  -36, 1188,    0
    subsprite OAM_SIZE_16x8,   -16,  -20, 1104,    0
    subsprite OAM_SIZE_8x8,      0,  -20, 1106,    0
    subsprite OAM_SIZE_8x16,     0,  -36, 1259,    0
    subsprite OAM_SIZE_16x32,    0,  -50, 1220,    0
    subsprite OAM_SIZE_8x16,    16,  -34, 1254,    0
    subsprite OAM_SIZE_16x16,  -12,  -40, 1166,    0
    subsprite OAM_SIZE_16x8,   -13,  -30, 1134,    0
    subsprite OAM_SIZE_32x16,    1,  -14,  966,    1
    subsprite OAM_SIZE_16x8,    17,  -22,  566,    1
    subsprite OAM_SIZE_16x16,   17,  -38, 1194,    1
    subsprite OAM_SIZE_8x16,     8,  -61,  207,    1
    subsprite OAM_SIZE_8x8,    -24,  -45,  459,    1
    subsprite OAM_SIZE_32x16,  -24,  -61, 1484,    1
  File5D36_Obj_430:
    subsprite OAM_SIZE_32x32,  -20,  -24, 1216,    0
    subsprite OAM_SIZE_16x16,  -17,  -35, 1188,    0
    subsprite OAM_SIZE_16x8,   -17,  -19, 1104,    0
    subsprite OAM_SIZE_8x8,     -1,  -19, 1106,    0
    subsprite OAM_SIZE_8x16,    -1,  -35, 1259,    0
    subsprite OAM_SIZE_16x32,   -3,  -43, 1223,    0
    subsprite OAM_SIZE_16x16,  -13,  -39, 1166,    0
    subsprite OAM_SIZE_16x8,   -14,  -29, 1134,    0
    subsprite OAM_SIZE_8x8,     26,  -13,  713,    1
    subsprite OAM_SIZE_16x16,   10,  -13,  900,    1
    subsprite OAM_SIZE_16x32,   18,  -45, 1422,    1
    subsprite OAM_SIZE_8x16,    14,  -61,  239,    1
    subsprite OAM_SIZE_32x16,  -18,  -61,  998,    1
  File5D36_Obj_443:
    subsprite OAM_SIZE_32x32,  -21,  -23, 1216,    0
    subsprite OAM_SIZE_16x16,  -18,  -34, 1188,    0
    subsprite OAM_SIZE_16x8,   -18,  -18, 1104,    0
    subsprite OAM_SIZE_8x8,     -2,  -18, 1106,    0
    subsprite OAM_SIZE_8x16,    -2,  -34, 1259,    0
    subsprite OAM_SIZE_16x32,  -10,  -42, 1225,    0
    subsprite OAM_SIZE_16x16,  -14,  -38, 1166,    0
    subsprite OAM_SIZE_16x8,   -15,  -28, 1134,    0
    subsprite OAM_SIZE_8x8,      6,  -18, 1100,    0
    subsprite OAM_SIZE_32x16,    1,  -59,  994,    1
    subsprite OAM_SIZE_16x8,   -15,  -59,  654,    1
    subsprite OAM_SIZE_16x32,   17,  -43, 1354,    1
    subsprite OAM_SIZE_8x8,    240,   88,  755,    1
    subsprite OAM_SIZE_16x32,  232,   96, 1420,    1
    subsprite OAM_SIZE_32x16,  208,   80, 1514,    1
  File5D36_Obj_458:
    subsprite OAM_SIZE_32x32,  -22,  -22, 1216,    0
    subsprite OAM_SIZE_16x16,  -20,  -32, 1188,    0
    subsprite OAM_SIZE_16x8,   -20,  -16, 1104,    0
    subsprite OAM_SIZE_8x8,     -4,  -16, 1106,    0
    subsprite OAM_SIZE_8x16,    -4,  -32, 1259,    0
    subsprite OAM_SIZE_16x32,  -12,  -40, 1225,    0
    subsprite OAM_SIZE_16x16,  -16,  -36, 1166,    0
    subsprite OAM_SIZE_16x8,   -17,  -26, 1134,    0
    subsprite OAM_SIZE_8x8,      4,  -17, 1100,    0
    subsprite OAM_SIZE_8x8,     25,  -52,  755,    1
    subsprite OAM_SIZE_16x32,   17,  -44, 1420,    1
    subsprite OAM_SIZE_32x16,   -7,  -60, 1514,    1
    subsprite OAM_SIZE_8x8,    -19,  -14, 1064,    0
  File5D36_Obj_471:
    subsprite OAM_SIZE_32x32,  -23,  -21, 1216,    0
    subsprite OAM_SIZE_16x16,  -22,  -30, 1188,    0
    subsprite OAM_SIZE_16x8,   -22,  -14, 1104,    0
    subsprite OAM_SIZE_8x8,     -6,  -14, 1106,    0
    subsprite OAM_SIZE_8x16,    -6,  -30, 1259,    0
    subsprite OAM_SIZE_16x32,  -14,  -38, 1225,    0
    subsprite OAM_SIZE_16x16,  -18,  -34, 1166,    0
    subsprite OAM_SIZE_16x8,   -19,  -24, 1134,    0
    subsprite OAM_SIZE_8x8,      2,  -14, 1100,    0
    subsprite OAM_SIZE_8x8,    -21,  -12, 1064,    0
    subsprite OAM_SIZE_8x8,    -19,  -11, 1084,    0
  File5D36_Obj_482:
    subsprite OAM_SIZE_16x16,  -11,  -47, 1671,    0
    subsprite OAM_SIZE_8x16,     5,  -47, 1673,    0
    subsprite OAM_SIZE_8x8,      5,  -31, 1705,    0
    subsprite OAM_SIZE_16x32,   -6,  -26, 1550,    0
    subsprite OAM_SIZE_8x16,   -14,  -18, 1565,    0
    subsprite OAM_SIZE_16x16,  -14,  -37, 1641,    0
    subsprite OAM_SIZE_8x16,     2,  -37, 1643,    0
    subsprite OAM_SIZE_16x8,    -6,  -21, 1667,    0
    subsprite OAM_SIZE_16x16,  -12,  -45, 1604,    0
    subsprite OAM_SIZE_8x8,      2,  -30, 1778,    0
  File5D36_Obj_492:
    subsprite OAM_SIZE_16x16,  -12,  -48, 1671,    0
    subsprite OAM_SIZE_8x16,     4,  -48, 1673,    0
    subsprite OAM_SIZE_8x8,      4,  -32, 1705,    0
    subsprite OAM_SIZE_16x32,   -6,  -25, 1550,    0
    subsprite OAM_SIZE_8x16,   -14,  -17, 1565,    0
    subsprite OAM_SIZE_16x16,  -15,  -36, 1641,    0
    subsprite OAM_SIZE_8x16,     1,  -36, 1643,    0
    subsprite OAM_SIZE_16x8,    -7,  -20, 1667,    0
    subsprite OAM_SIZE_16x16,  -13,  -44, 1604,    0
    subsprite OAM_SIZE_8x8,      1,  -31, 1778,    0
  File5D36_Obj_502:
    subsprite OAM_SIZE_8x8,     -8,  -42, 1155,    0
    subsprite OAM_SIZE_16x32,   -1,  -27, 1550,    0
    subsprite OAM_SIZE_8x16,    -9,  -19, 1565,    0
    subsprite OAM_SIZE_32x16,  -40,  -50, 1168,    0
    subsprite OAM_SIZE_16x8,   -17,  -34, 1202,    0
    subsprite OAM_SIZE_16x8,   -32,  -34, 1200,    0
    subsprite OAM_SIZE_16x16,    0,  -39, 1720,    0
    subsprite OAM_SIZE_8x16,    -8,  -39, 1719,    0
    subsprite OAM_SIZE_16x8,     0,  -23, 1655,    0
    subsprite OAM_SIZE_8x16,    22,    6, 1095,    0
    subsprite OAM_SIZE_32x32,   -2,  -26, 1028,    0
    subsprite OAM_SIZE_16x16,    6,    6, 1093,    0
    subsprite OAM_SIZE_16x16,   -5,  -47, 1604,    0
    subsprite OAM_SIZE_16x8,    -5,  -35, 1570,    0
  File5D36_Obj_516:
    subsprite OAM_SIZE_16x16,  -23,  -50, 1536,    0
    subsprite OAM_SIZE_16x8,   -23,  -34, 1568,    0
    subsprite OAM_SIZE_32x32,  -11,  -31, 1216,    0
    subsprite OAM_SIZE_16x16,   -6,  -39, 1720,    0
    subsprite OAM_SIZE_16x8,    -6,  -23, 1655,    0
    subsprite OAM_SIZE_16x16,   -8,  -45, 1606,    0
    subsprite OAM_SIZE_32x16,    1,  -26, 1616,    0
    subsprite OAM_SIZE_8x8,     17,  -10, 1651,    0
    subsprite OAM_SIZE_8x16,   -14,  -39, 1719,    0
    subsprite OAM_SIZE_16x8,   -11,  -35, 1570,    0
  File5D36_Obj_526:
    subsprite OAM_SIZE_32x32,   -9,  -29, 1128,    0
    subsprite OAM_SIZE_16x16,  -17,  -44, 1714,    0
    subsprite OAM_SIZE_8x8,     -9,  -52, 1762,    0
    subsprite OAM_SIZE_32x32,  -17,  -44, 1124,    0
    subsprite OAM_SIZE_16x16,   -7,  -46, 1608,    0
    subsprite OAM_SIZE_16x16,    4,  -34, 1744,    0
    subsprite OAM_SIZE_8x8,     -4,  -34, 1573,    0
    subsprite OAM_SIZE_8x8,     20,  -34, 1746,    0
  File5D36_Obj_534:
    subsprite OAM_SIZE_16x16,  -20,  -34,  256,    0
    subsprite OAM_SIZE_8x16,    -4,  -34,  258,    0
    subsprite OAM_SIZE_16x8,   -20,  -18,  288,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  290,    0
    subsprite OAM_SIZE_16x32,    3,  -70,  292,    0
    subsprite OAM_SIZE_8x8,     11,  -78,  291,    0
    subsprite OAM_SIZE_8x16,    -5,  -54,  323,    0
    subsprite OAM_SIZE_16x16,  -11,  -41,  304,    0
    subsprite OAM_SIZE_16x8,   -11,  -25,  336,    0
    subsprite OAM_SIZE_8x8,      5,  -25,  338,    0
    subsprite OAM_SIZE_8x16,     5,  -41,  306,    0
    subsprite OAM_SIZE_16x16,  -22,  -34,  263,    0
    subsprite OAM_SIZE_8x8,    -30,  -18,  294,    0
    subsprite OAM_SIZE_32x16,  -54,  -34,  259,    0
  File5D36_Obj_548:
    subsprite OAM_SIZE_16x32,   -2,  -64,  334,    0
    subsprite OAM_SIZE_16x8,   -10,    8,  296,    0
    subsprite OAM_SIZE_8x16,   -10,   -8,  265,    0
    subsprite OAM_SIZE_16x32,   -2,  -24,  266,    0
    subsprite OAM_SIZE_32x32,  -15,  -44,  268,    0
    subsprite OAM_SIZE_32x16,  -39,  -35,  330,    0
    subsprite OAM_SIZE_16x8,   -47,  -43,  312,    0
    subsprite OAM_SIZE_8x8,    -47,  -35,  295,    0
  File5D36_Obj_556:
    subsprite OAM_SIZE_16x32,   -4,  -66,  334,    0
    subsprite OAM_SIZE_16x8,   -10,    8,  296,    0
    subsprite OAM_SIZE_8x16,   -10,   -8,  265,    0
    subsprite OAM_SIZE_16x32,   -2,  -24,  266,    0
    subsprite OAM_SIZE_32x32,  -16,  -45,  268,    0
    subsprite OAM_SIZE_32x16,  -41,  -37,  330,    0
    subsprite OAM_SIZE_16x8,   -49,  -45,  312,    0
    subsprite OAM_SIZE_8x8,    -49,  -37,  295,    0
  File5D36_Obj_564:
    subsprite OAM_SIZE_16x32,  -11,  -20,  352,    0
    subsprite OAM_SIZE_8x16,     5,  -20,  354,    0
    subsprite OAM_SIZE_8x8,      5,   -4,  386,    0
    subsprite OAM_SIZE_32x32,  -31,  -38,  355,    0
    subsprite OAM_SIZE_8x16,     1,  -46,  359,    0
    subsprite OAM_SIZE_8x16,     1,  -30,  391,    0
    subsprite OAM_SIZE_16x16,    9,  -54,  426,    0
    subsprite OAM_SIZE_8x8,      9,  -38,  402,    0
    subsprite OAM_SIZE_16x8,     1,  -62,  424,    0
    subsprite OAM_SIZE_8x16,   -19,  -28,  196,    1
    subsprite OAM_SIZE_8x16,   -19,  -12,  228,    1
    subsprite OAM_SIZE_8x8,      5,    4,  245,    1
    subsprite OAM_SIZE_16x32,  -11,  -12,  902,    1
    subsprite OAM_SIZE_16x16,   29,  -20,  711,    1
    subsprite OAM_SIZE_16x8,    29,  -28,  564,    1
    subsprite OAM_SIZE_32x16,   13,  -44,  233,    1
    subsprite OAM_SIZE_8x8,     -7,  -46,  440,    0
  File5D36_Obj_581:
    subsprite OAM_SIZE_32x32,  -17,  -28,  460,    0
    subsprite OAM_SIZE_32x16,  -17,  -36,  428,    0
    subsprite OAM_SIZE_16x8,    -9,  -44,  412,    0
    subsprite OAM_SIZE_16x16,    5,   -4,  743,    1
    subsprite OAM_SIZE_16x32,  -19,  -20,  904,    1
    subsprite OAM_SIZE_8x8,      5,   12,  221,    1
    subsprite OAM_SIZE_8x16,    -3,   -4,  487,    1
    subsprite OAM_SIZE_16x32,   29,  -36,  906,    1
    subsprite OAM_SIZE_16x8,    21,  -44,  246,    1
    subsprite OAM_SIZE_32x16,  -16,  -25,  326,    0
    subsprite OAM_SIZE_16x8,    -8,   -9,  310,    0
  File5D36_Obj_592:
    subsprite OAM_SIZE_32x32,  -18,  -29,  460,    0
    subsprite OAM_SIZE_16x8,   -10,  -45,  412,    0
    subsprite OAM_SIZE_32x16,  -18,  -37,  428,    0
    subsprite OAM_SIZE_32x16,  -20,  -26,  392,    0
    subsprite OAM_SIZE_16x8,     4,  -34,  364,    0
    subsprite OAM_SIZE_8x8,     12,  -26,  381,    0
    subsprite OAM_SIZE_32x16,  -11,   -4, 1260,    1
    subsprite OAM_SIZE_16x8,     5,   12,  219,    1
    subsprite OAM_SIZE_16x16,   21,   -4,  237,    1
    subsprite OAM_SIZE_8x8,    -11,  -12,  248,    1
    subsprite OAM_SIZE_16x32,   29,  -37, 1352,    1
    subsprite OAM_SIZE_16x8,    29,   -5,  504,    1
  File5D36_Obj_604:
    subsprite OAM_SIZE_32x32,  -19,  -30,  460,    0
    subsprite OAM_SIZE_16x8,   -11,  -46,  412,    0
    subsprite OAM_SIZE_32x16,  -19,  -38,  428,    0
    subsprite OAM_SIZE_32x16,  -21,  -33,  360,    0
    subsprite OAM_SIZE_8x8,      3,  -41,  380,    0
    subsprite OAM_SIZE_32x16,   -3,   -4,  483,    1
    subsprite OAM_SIZE_16x8,     5,   12,  506,    1
    subsprite OAM_SIZE_16x32,   29,  -33,  974,    1
    subsprite OAM_SIZE_8x8,     29,   -1,  441,    1
  File5D36_Obj_613:
    subsprite OAM_SIZE_32x32,  -19,  -32,  460,    0
    subsprite OAM_SIZE_16x8,   -13,  -48,  412,    0
    subsprite OAM_SIZE_32x16,  -21,  -40,  428,    0
    subsprite OAM_SIZE_32x16,  -23,  -35,  360,    0
    subsprite OAM_SIZE_8x8,      1,  -43,  380,    0
    subsprite OAM_SIZE_32x16,    5,   -4,   68,    1
    subsprite OAM_SIZE_8x8,     -3,   -4,  498,    1
    subsprite OAM_SIZE_16x8,     5,   12,  642,    1
    subsprite OAM_SIZE_16x16,   29,  -20,  652,    1
    subsprite OAM_SIZE_8x8,     37,   -4,  307,    1
  File5D36_Obj_623:
    subsprite OAM_SIZE_32x32,  -19,  -33,  460,    0
    subsprite OAM_SIZE_32x16,  -22,  -41,  428,    0
    subsprite OAM_SIZE_16x8,   -14,  -49,  412,    0
    subsprite OAM_SIZE_32x16,  -24,  -36,  360,    0
    subsprite OAM_SIZE_8x8,      0,  -44,  380,    0
  File5D36_Obj_628:
    subsprite OAM_SIZE_16x16,  -14,  -45, 1612,    0
    subsprite OAM_SIZE_8x8,     -1,  -28, 1597,    0
    subsprite OAM_SIZE_16x32,   -8,  -32, 1678,    0
    subsprite OAM_SIZE_8x16,   -16,  -16, 1677,    0
    subsprite OAM_SIZE_8x8,     -7,  -22, 1686,    0
    subsprite OAM_SIZE_16x16,  -15,  -38, 1722,    0
    subsprite OAM_SIZE_8x16,     1,  -38, 1724,    0
    subsprite OAM_SIZE_16x16,  -14,  -45, 1674,    0
    subsprite OAM_SIZE_8x16,     2,  -45, 1676,    0
    subsprite OAM_SIZE_16x8,   -14,  -29, 1706,    0
    subsprite OAM_SIZE_8x8,     -7,  -21,  180,    0
  File5D36_Obj_639:
    subsprite OAM_SIZE_16x16,  -15,  -44, 1612,    0
    subsprite OAM_SIZE_16x32,   -8,  -31, 1678,    0
    subsprite OAM_SIZE_8x16,   -16,  -15, 1677,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1686,    0
    subsprite OAM_SIZE_16x16,  -16,  -37, 1722,    0
    subsprite OAM_SIZE_8x16,     0,  -37, 1724,    0
    subsprite OAM_SIZE_16x16,  -16,  -46, 1674,    0
    subsprite OAM_SIZE_8x16,     0,  -46, 1676,    0
    subsprite OAM_SIZE_16x8,   -16,  -30, 1706,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  180,    0
  File5D36_Obj_649:
    subsprite OAM_SIZE_8x8,      3,  -24, 1597,    0
    subsprite OAM_SIZE_16x32,   -4,  -28, 1678,    0
    subsprite OAM_SIZE_8x16,   -12,  -12, 1677,    0
    subsprite OAM_SIZE_16x32,   -1,  -67,  292,    0
    subsprite OAM_SIZE_8x8,      7,  -75,  291,    0
    subsprite OAM_SIZE_8x16,    -9,  -51,  323,    0
    subsprite OAM_SIZE_32x16,  -15,  -36, 1644,    0
    subsprite OAM_SIZE_16x8,    -7,  -20, 1639,    0
    subsprite OAM_SIZE_32x16,  -52,  -32,  259,    0
    subsprite OAM_SIZE_16x16,   -2,  -41, 1612,    0
    subsprite OAM_SIZE_8x8,    -28,  -16,  294,    0
    subsprite OAM_SIZE_16x16,  -20,  -32,  263,    0
    subsprite OAM_SIZE_8x8,     -5,  -33, 1572,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  180,    0
  File5D36_Obj_663:
    subsprite OAM_SIZE_32x16,   -2,  -42, 1584,    0
    subsprite OAM_SIZE_32x32,  -10,  -24,  460,    0
    subsprite OAM_SIZE_32x16,  -14,  -32, 1543,    0
    subsprite OAM_SIZE_16x8,    -7,  -40, 1547,    0
    subsprite OAM_SIZE_16x16,   -4,  -42, 1612,    0
    subsprite OAM_SIZE_16x32,  -25,  -28, 1648,    0
    subsprite OAM_SIZE_8x8,     -9,  -28, 1650,    0
    subsprite OAM_SIZE_16x8,    -6,  -32, 1588,    0
  File5D36_Obj_671:
    subsprite OAM_SIZE_16x32,  -12,  -23,  352,    0
    subsprite OAM_SIZE_8x16,     4,  -23,  354,    0
    subsprite OAM_SIZE_8x8,      4,   -7,  386,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 1597,    0
    subsprite OAM_SIZE_16x16,    3,  -33, 1712,    0
    subsprite OAM_SIZE_16x16,   -7,  -44, 1748,    0
    subsprite OAM_SIZE_16x8,    -7,  -28, 1780,    0
    subsprite OAM_SIZE_8x16,   -15,  -36, 1763,    0
    subsprite OAM_SIZE_16x16,   -6,  -43, 1614,    0
    subsprite OAM_SIZE_16x16,  -16,  -22, 1682,    0
    subsprite OAM_SIZE_8x8,    -16,  -30, 1666,    0
    subsprite OAM_SIZE_8x8,      0,  -20,  180,    0
    subsprite OAM_SIZE_8x8,     -7,  -20,  180,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 1574,    0

2:
File5D36_Cmds:
  File5D36_Cmd_0:
    animcmd   0,   1
  File5D36_Cmd_1:
    animcmd   1,   1
  File5D36_Cmd_2:
    animcmd   2,   1
  File5D36_Cmd_3:
    animcmd   3,   1
  File5D36_Cmd_4:
    animcmd   4,   1
  File5D36_Cmd_5:
    animcmd  29,   8
    animcmd  30,   8
    animcmd  31,   8
    animcmd  32,  13
  File5D36_Cmd_9:
    animcmd  33,   8
    animcmd  34,   8
    animcmd  35,   8
    animcmd  36,  13
  File5D36_Cmd_13:
    animcmd  30,   8
  File5D36_Cmd_14:
    animcmd  34,   8
  File5D36_Cmd_15:
    animcmd  47,   1
  File5D36_Cmd_16:
    animcmd  61,   1
  File5D36_Cmd_17:
    animcmd  48,   4
    animcmd  49,   4
    animcmd  50,   2
    animcmd  51,   2
    animcmd  52,   2
    animcmd  53,   4
    animcmd  54,   5
    animcmd  55,  16
  File5D36_Cmd_25:
    animcmd  62,   4
    animcmd  63,   4
    animcmd  64,   2
    animcmd  65,   2
    animcmd  66,   2
    animcmd  67,   4
    animcmd  68,   5
    animcmd  69,  16
  File5D36_Cmd_33:
    animcmd  25,  20
    animcmd  26,   5
    animcmd  27,   7
    animcmd  28,   7
    animcmd  27,   7
    animcmd  28,   7
    animcmd  27,   7
    animcmd  28,   7
  File5D36_Cmd_41:
    animcmd   5,   5
    animcmd   6,   5
    animcmd   7,   5
    animcmd   8,   5
    animcmd   9,   4
    animcmd  10,   4
    animcmd  11,   2
    animcmd  12,  13
  File5D36_Cmd_49:
    animcmd  15,   5
    animcmd  16,   5
    animcmd  17,   5
    animcmd  18,   5
    animcmd  19,   4
    animcmd  20,   4
    animcmd  21,   2
    animcmd  22,  13
  File5D36_Cmd_57:
    animcmd  37,   4
    animcmd  38,   5
    animcmd  39,   4
    animcmd  40,   5
    animcmd  41,  12
    animcmd  42,   5
    animcmd  43,   5
    animcmd  44,   8
    animcmd  45,   8
    animcmd  46,   8
  File5D36_Cmd_67:
    animcmd  56,   1
  File5D36_Cmd_68:
    animcmd  70,   1
  File5D36_Cmd_69:
    animcmd  56,   5
    animcmd  57,   5
  File5D36_Cmd_71:
    animcmd  70,   5
    animcmd  71,   5
  File5D36_Cmd_73:
    animcmd  58,   6
    animcmd  59,   9
    animcmd  60,   9
  File5D36_Cmd_76:
    animcmd  72,   6
    animcmd  73,   9
    animcmd  74,   9
  File5D36_Cmd_79:
    animcmd  13,   5
    animcmd  14,   5
  File5D36_Cmd_81:
    animcmd  23,   5
    animcmd  24,   5

File5D36_Tiles:
  .incbin "data/sprite_main/shademan.4bpp"
