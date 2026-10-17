FileD3CA_Header:
  .2byte 547 @ palStart
  .2byte 49 @ metaspriteCount
  .2byte 20 @ animationCount
  .2byte 429 @ subspriteCount
  .2byte 64 @ cmdCount
  .2byte 1280 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 1012 @ offsetToAnims
  .4byte 1172 @ offsetToSubsprites
  .4byte 4604 @ offsetToCmds
  .4byte 4860 @ offsetToTiles

FileD3CA_Poses:
@ pose unk_0,  obj,               objcount,   bb
  pose 0x1935, FileD3CA_Obj_0,    12,         -93, -112,   44,   36
  pose 0x1936, FileD3CA_Obj_12,   10,         -85, -108,   44,   55
  pose 0x1937, FileD3CA_Obj_22,   11,         -90, -103,   38,   35
  pose 0x1938, FileD3CA_Obj_33,   12,        -103, -100,   35,   44
  pose 0xBE46, FileD3CA_Obj_45,   12,         -95, -111,   44,   38
  pose 0xBE47, FileD3CA_Obj_57,   11,         -87, -106,   44,   56
  pose 0xBE48, FileD3CA_Obj_68,   12,         -92, -101,   36,   36
  pose 0xBE49, FileD3CA_Obj_80,   11,        -100, -101,   36,   45
  pose 0xBE4A, FileD3CA_Obj_91,   10,         -94, -115,   45,   37
  pose 0xBE4B, FileD3CA_Obj_101,  9,          -86, -108,   45,   52
  pose 0xBE4C, FileD3CA_Obj_110,  10,         -91, -102,   37,   34
  pose 0xBE4D, FileD3CA_Obj_120,  11,        -102, -100,   34,   45
  pose 0xBE4E, FileD3CA_Obj_131,  10,         -96, -117,   47,   38
  pose 0xBE4F, FileD3CA_Obj_141,  9,          -88, -106,   47,   50
  pose 0xBE77, FileD3CA_Obj_150,  10,         -93, -100,   35,   34
  pose 0xBE78, FileD3CA_Obj_160,  11,        -104, -102,   35,   47
  pose 0xBE79, FileD3CA_Obj_171,  10,         -95, -116,   46,   37
  pose 0xBE7A, FileD3CA_Obj_181,  9,          -87, -107,   46,   51
  pose 0xBE7B, FileD3CA_Obj_190,  10,         -92, -101,   36,   34
  pose 0xBE7C, FileD3CA_Obj_200,  11,        -103, -101,   34,   46
  pose 0x3E47, FileD3CA_Obj_211,  11,         -73, -136,   55,   24
  pose 0x3E48, FileD3CA_Obj_222,  11,         -74, -134,   54,   26
  pose 0x3E49, FileD3CA_Obj_233,  3,          -91,  -96,   45,   64
  pose 0x3E4A, FileD3CA_Obj_236,  2,          -90, -122,   38,   38
  pose 0x3E4B, FileD3CA_Obj_238,  3,          -83, -127,   53,   25
  pose 0x08A2, FileD3CA_Obj_241,  8,          -86, -115,   45,   37
  pose 0x08A3, FileD3CA_Obj_249,  9,          -91, -102,   45,   52
  pose 0x08A4, FileD3CA_Obj_258,  12,        -102,  -99,   34,   45
  pose 0x08A5, FileD3CA_Obj_270,  11,        -102, -108,   42,   36
  pose 0x08A6, FileD3CA_Obj_281,  8,          -86, -115,   45,   37
  pose 0x08A7, FileD3CA_Obj_289,  9,          -91, -102,   45,   52
  pose 0x08A8, FileD3CA_Obj_298,  12,        -102,  -99,   34,   45
  pose 0x08A9, FileD3CA_Obj_310,  11,        -102, -108,   42,   36
  pose 0x08AA, FileD3CA_Obj_321,  10,         -94, -115,   45,   37
  pose 0x08AB, FileD3CA_Obj_331,  9,          -86, -108,   45,   52
  pose 0x08D3, FileD3CA_Obj_340,  10,         -91, -102,   37,   34
  pose 0x08D4, FileD3CA_Obj_350,  11,        -102, -100,   34,   45
  pose 0x2438, FileD3CA_Obj_361,  7,          -87, -101,   41,   59
  pose 0x2439, FileD3CA_Obj_368,  7,          -86, -102,   42,   58
  pose 0x576F, FileD3CA_Obj_375,  4,          -45,  -62,   35,    2
  pose 0x5770, FileD3CA_Obj_379,  5,          -48,  -94,   16,    0
  pose 0x5771, FileD3CA_Obj_384,  3,          -39,  -87,    9,    0
  pose 0x5772, FileD3CA_Obj_387,  7,          -37,  -92,   35,    0
  pose 0x5773, FileD3CA_Obj_394,  6,          -26,  -81,   46,    0
  pose 0xD352, FileD3CA_Obj_400,  6,          -24,  -58,   16,   14
  pose 0xD353, FileD3CA_Obj_406,  3,          -48,  -66,   16,   14
  pose 0xD354, FileD3CA_Obj_409,  5,          -48,  -66,   17,   14
  pose 0xD355, FileD3CA_Obj_414,  9,          -40,  -58,   24,   14
  pose 0xD356, FileD3CA_Obj_423,  6,          -46,  -48,   26,   32

FileD3CA_Anims:
@ animation unk_0,  cmd,             cmdCount
  animation 0xC144, FileD3CA_Cmd_0,  4
  animation 0xB292, FileD3CA_Cmd_4,  4
  animation 0xB293, FileD3CA_Cmd_8,  12
  animation 0xB294, FileD3CA_Cmd_20, 3
  animation 0xB692, FileD3CA_Cmd_23, 1
  animation 0xB693, FileD3CA_Cmd_24, 4
  animation 0xBA92, FileD3CA_Cmd_28, 8
  animation 0xBA93, FileD3CA_Cmd_36, 4
  animation 0x3559, FileD3CA_Cmd_40, 2
  animation 0x355A, FileD3CA_Cmd_42, 5
  animation 0x5D4F, FileD3CA_Cmd_47, 4
  animation 0x5D50, FileD3CA_Cmd_51, 3
  animation 0x5D51, FileD3CA_Cmd_54, 1
  animation 0x5D52, FileD3CA_Cmd_55, 1
  animation 0x5D53, FileD3CA_Cmd_56, 1
  animation 0x5D54, FileD3CA_Cmd_57, 1
  animation 0x5D55, FileD3CA_Cmd_58, 1
  animation 0xD352, FileD3CA_Cmd_59, 1
  animation 0xD353, FileD3CA_Cmd_60, 3
  animation 0xD354, FileD3CA_Cmd_63, 1

1:
FileD3CA_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD3CA_Obj_0:
    subsprite OAM_SIZE_32x32,  -18,   -4,  457,    0
    subsprite OAM_SIZE_16x16,   -1,    2,  640,    0
    subsprite OAM_SIZE_16x16,    4,   -9,  672,    0
    subsprite OAM_SIZE_32x32,   -1,  -24,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -29,  -44,   56,    0
    subsprite OAM_SIZE_16x16,   19,   20,  704,    0
    subsprite OAM_SIZE_8x8,     35,  -32,  496,    0
    subsprite OAM_SIZE_64x64,  -20,  -48,  132,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_32x16,  -32,   -5,  864,    0
    subsprite OAM_SIZE_16x32,  -16,   11,  804,    0
  FileD3CA_Obj_12:
    subsprite OAM_SIZE_32x32,  -19,   -5,  457,    0
    subsprite OAM_SIZE_16x16,   -2,    2,  640,    0
    subsprite OAM_SIZE_32x32,   -1,  -23,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -21,  -44,  896,    0
    subsprite OAM_SIZE_64x32,  -20,   -9,  449,    0
    subsprite OAM_SIZE_32x64,  -28,  -49,  368,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_32x16,  -32,   -6,  868,    0
    subsprite OAM_SIZE_16x32,  -16,   10,  806,    0
  FileD3CA_Obj_22:
    subsprite OAM_SIZE_32x32,  -20,   -6,  457,    0
    subsprite OAM_SIZE_16x16,   -3,    2,  640,    0
    subsprite OAM_SIZE_32x32,   -2,  -22,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -26,  -39,  512,    0
    subsprite OAM_SIZE_32x32,  -47,  -29,  706,    0
    subsprite OAM_SIZE_16x32,  -15,  -29,  710,    0
    subsprite OAM_SIZE_32x64,   -1,    3,  396,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_16x32,  -16,    9,  800,    0
    subsprite OAM_SIZE_32x16,  -32,   -7,  768,    0
  FileD3CA_Obj_33:
    subsprite OAM_SIZE_32x32,  -19,   -5,  457,    0
    subsprite OAM_SIZE_16x16,   -2,    2,  640,    0
    subsprite OAM_SIZE_16x16,    4,   -7,  672,    0
    subsprite OAM_SIZE_32x32,   -1,  -23,  256,    0
    subsprite OAM_SIZE_64x32,  -37,  -36,  263,    0
    subsprite OAM_SIZE_64x32,  -39,  -33,  643,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_32x64,    3,  -36,  268,    0
    subsprite OAM_SIZE_16x8,    11,   28,   42,    0
    subsprite OAM_SIZE_32x64,    0,   -1, 1056,    0
    subsprite OAM_SIZE_32x16,  -32,   -6,  772,    0
    subsprite OAM_SIZE_16x32,  -16,   10,  802,    0
  FileD3CA_Obj_45:
    subsprite OAM_SIZE_32x32,  -18,   -4,  457,    0
    subsprite OAM_SIZE_16x16,   -1,    2,  640,    0
    subsprite OAM_SIZE_16x16,    4,   -9,  672,    0
    subsprite OAM_SIZE_32x32,   -1,  -24,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -31,  -42,   56,    0
    subsprite OAM_SIZE_64x64,  -20,  -47,  132,    0
    subsprite OAM_SIZE_8x8,     33,  -30,  496,    0
    subsprite OAM_SIZE_16x16,   17,   22,  704,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_32x16,  -32,   -5,  864,    0
    subsprite OAM_SIZE_16x32,  -16,   11,  804,    0
  FileD3CA_Obj_57:
    subsprite OAM_SIZE_32x32,  -19,   -5,  457,    0
    subsprite OAM_SIZE_16x16,   -2,    2,  640,    0
    subsprite OAM_SIZE_16x16,    4,   -7,  672,    0
    subsprite OAM_SIZE_32x32,   -1,  -23,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -23,  -42,  896,    0
    subsprite OAM_SIZE_32x64,  -28,  -48,  368,    0
    subsprite OAM_SIZE_64x32,  -20,   -8,  449,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_16x32,  -16,   10,  802,    0
    subsprite OAM_SIZE_32x16,  -32,   -6,  772,    0
  FileD3CA_Obj_68:
    subsprite OAM_SIZE_32x32,  -20,   -6,  457,    0
    subsprite OAM_SIZE_16x16,   -3,    2,  640,    0
    subsprite OAM_SIZE_16x16,    2,   -6,  672,    0
    subsprite OAM_SIZE_32x32,   -2,  -22,  256,    0
    subsprite OAM_SIZE_32x32,  -22,  -13,  259,    0
    subsprite OAM_SIZE_64x64,  -28,  -37,  512,    0
    subsprite OAM_SIZE_32x32,  -47,  -28,  706,    0
    subsprite OAM_SIZE_16x32,  -15,  -28,  710,    0
    subsprite OAM_SIZE_32x64,   -1,    4,  396,    0
    subsprite OAM_SIZE_32x16,  -22,  -13,  259,    0
    subsprite OAM_SIZE_16x32,  -16,    9,  800,    0
    subsprite OAM_SIZE_32x16,  -32,   -7,  768,    0
  FileD3CA_Obj_80:
    subsprite OAM_SIZE_16x16,  -29,  -10,  954,    0
    subsprite OAM_SIZE_32x32,  -13,  -10,  924,    0
    subsprite OAM_SIZE_16x8,   -13,  -18,  908,    0
    subsprite OAM_SIZE_8x8,    -21,    6,  987,    0
    subsprite OAM_SIZE_16x8,   -13,   22,  988,    0
    subsprite OAM_SIZE_64x32,  -36,  -35,  263,    0
    subsprite OAM_SIZE_32x64,    4,  -35,  268,    0
    subsprite OAM_SIZE_16x8,    12,   29,   42,    0
    subsprite OAM_SIZE_64x32,  -36,  -37,  643,    0
    subsprite OAM_SIZE_32x64,    3,   -5, 1056,    0
    subsprite OAM_SIZE_16x16,  -13,  -18,  908,    0
  FileD3CA_Obj_91:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -30,  -44,   56,    2
    subsprite OAM_SIZE_16x16,   18,   20,  704,    2
    subsprite OAM_SIZE_8x8,     34,  -32,  496,    2
    subsprite OAM_SIZE_64x64,  -19,  -51,  132,    2
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  864,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  804,    0
  FileD3CA_Obj_101:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x64,  -22,  -44,  896,    2
    subsprite OAM_SIZE_64x32,  -19,  -12,  449,    2
    subsprite OAM_SIZE_32x64,  -27,  -52,  368,    2
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  802,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  772,    0
  FileD3CA_Obj_110:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_64x64,  -27,  -38,  512,    2
    subsprite OAM_SIZE_32x32,  -46,  -32,  706,    2
    subsprite OAM_SIZE_16x32,  -14,  -32,  710,    2
    subsprite OAM_SIZE_32x64,    0,    0,  396,    2
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  800,    0
    subsprite OAM_SIZE_32x16,  -27,  -14,  768,    0
  FileD3CA_Obj_120:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x32,  -38,  -35,  263,    2
    subsprite OAM_SIZE_32x64,    2,  -35,  268,    2
    subsprite OAM_SIZE_16x8,    10,   29,   42,    2
    subsprite OAM_SIZE_32x64,    1,   -4, 1056,    2
    subsprite OAM_SIZE_64x32,  -38,  -36,  643,    2
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  868,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  806,    0
  FileD3CA_Obj_131:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -32,  -42,   56,    4
    subsprite OAM_SIZE_16x16,   16,   22,  704,    4
    subsprite OAM_SIZE_8x8,     32,  -30,  496,    4
    subsprite OAM_SIZE_64x64,  -17,  -53,  132,    4
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_16x32,  -14,    5,  800,    0
    subsprite OAM_SIZE_32x16,  -30,  -11,  768,    0
  FileD3CA_Obj_141:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x64,  -24,  -42,  896,    4
    subsprite OAM_SIZE_64x32,  -17,  -14,  449,    4
    subsprite OAM_SIZE_32x64,  -25,  -54,  368,    4
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  868,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  806,    0
  FileD3CA_Obj_150:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_64x64,  -29,  -36,  512,    4
    subsprite OAM_SIZE_32x32,  -44,  -34,  706,    4
    subsprite OAM_SIZE_16x32,  -12,  -34,  710,    4
    subsprite OAM_SIZE_32x64,    2,   -2,  396,    4
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_32x16,  -27,  -14,  864,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  804,    0
  FileD3CA_Obj_160:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x32,  -40,  -33,  263,    4
    subsprite OAM_SIZE_32x64,    0,  -33,  268,    4
    subsprite OAM_SIZE_16x8,     8,   31,   42,    4
    subsprite OAM_SIZE_32x64,    3,   -6, 1056,    4
    subsprite OAM_SIZE_64x32,  -36,  -38,  643,    4
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  802,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  772,    0
  FileD3CA_Obj_171:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -31,  -43,   56,    3
    subsprite OAM_SIZE_16x16,   17,   21,  704,    3
    subsprite OAM_SIZE_8x8,     33,  -31,  496,    3
    subsprite OAM_SIZE_64x64,  -18,  -52,  132,    3
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_16x32,  -14,    5,  802,    0
    subsprite OAM_SIZE_32x16,  -30,  -11,  772,    0
  FileD3CA_Obj_181:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x64,  -23,  -43,  896,    3
    subsprite OAM_SIZE_64x32,  -18,  -13,  449,    3
    subsprite OAM_SIZE_32x64,  -26,  -53,  368,    3
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  800,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  768,    0
  FileD3CA_Obj_190:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_64x64,  -28,  -37,  512,    3
    subsprite OAM_SIZE_32x32,  -45,  -33,  706,    3
    subsprite OAM_SIZE_16x32,  -13,  -33,  710,    3
    subsprite OAM_SIZE_32x64,    1,   -1,  396,    3
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_32x16,  -27,  -14,  868,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  806,    0
  FileD3CA_Obj_200:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x32,  -39,  -34,  263,    3
    subsprite OAM_SIZE_32x64,    1,  -34,  268,    3
    subsprite OAM_SIZE_16x8,     9,   30,   42,    3
    subsprite OAM_SIZE_32x64,    2,   -5, 1056,    3
    subsprite OAM_SIZE_64x32,  -37,  -37,  643,    3
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  864,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  804,    0
  FileD3CA_Obj_211:
    subsprite OAM_SIZE_32x32,   -9,  -40,  776,    0
    subsprite OAM_SIZE_16x16,   23,  -40,  780,    0
    subsprite OAM_SIZE_16x8,    23,  -24,  812,    0
    subsprite OAM_SIZE_8x16,    39,  -40,  840,    0
    subsprite OAM_SIZE_32x8,    -9,   -8,   44,    0
    subsprite OAM_SIZE_16x16,   -1,    0,  236,    0
    subsprite OAM_SIZE_8x8,     15,    0,  238,    0
    subsprite OAM_SIZE_64x32,   -9,  -72, 1216,    0
    subsprite OAM_SIZE_16x32,   23, -104, 1156,    0
    subsprite OAM_SIZE_32x8,    -9,  -80, 1200,    0
    subsprite OAM_SIZE_8x8,     15,  -88, 1187,    0
  FileD3CA_Obj_222:
    subsprite OAM_SIZE_32x8,   -10,  -78, 1200,    0
    subsprite OAM_SIZE_64x32,  -10,  -70, 1216,    0
    subsprite OAM_SIZE_16x32,   22, -102, 1156,    0
    subsprite OAM_SIZE_8x8,     14,  -86, 1187,    0
    subsprite OAM_SIZE_32x32,  -10,  -38,  776,    0
    subsprite OAM_SIZE_16x16,   22,  -38,  780,    0
    subsprite OAM_SIZE_8x16,    38,  -38,  840,    0
    subsprite OAM_SIZE_16x8,    22,  -22,  812,    0
    subsprite OAM_SIZE_32x8,   -10,   -6,   44,    0
    subsprite OAM_SIZE_16x16,   -2,    2,  236,    0
    subsprite OAM_SIZE_8x8,     14,    2,  238,    0
  FileD3CA_Obj_233:
    subsprite OAM_SIZE_64x64,  -27,  -32, 1032,    0
    subsprite OAM_SIZE_32x16,   -3,   32,   12,    0
    subsprite OAM_SIZE_8x16,    37,  -24,  674,    0
  FileD3CA_Obj_236:
    subsprite OAM_SIZE_64x64,  -26,  -58,  324,    0
    subsprite OAM_SIZE_32x32,  -26,    6,  192,    0
  FileD3CA_Obj_238:
    subsprite OAM_SIZE_8x16,    45,  -23,  642,    0
    subsprite OAM_SIZE_64x64,  -19,  -63, 1160,    0
    subsprite OAM_SIZE_32x32,   -5,   -7,  304,    0
  FileD3CA_Obj_241:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -22,  -44,  896,    5
    subsprite OAM_SIZE_64x64,  -19,  -51,  132,    5
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  864,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  804,    0
  FileD3CA_Obj_249:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x64,  -27,  -38,  512,    5
    subsprite OAM_SIZE_64x32,  -19,  -12,  449,    5
    subsprite OAM_SIZE_32x64,  -27,  -52,  368,    5
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  802,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  772,    0
  FileD3CA_Obj_258:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_32x64,    2,  -35,  268,    5
    subsprite OAM_SIZE_64x32,  -38,  -35,  263,    5
    subsprite OAM_SIZE_16x8,    10,   29,   42,    5
    subsprite OAM_SIZE_32x32,  -46,  -32,  706,    5
    subsprite OAM_SIZE_16x32,  -14,  -32,  710,    5
    subsprite OAM_SIZE_32x64,    0,    0,  396,    5
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  800,    0
    subsprite OAM_SIZE_32x16,  -27,  -14,  768,    0
  FileD3CA_Obj_270:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_8x8,     34,  -32,  496,    5
    subsprite OAM_SIZE_64x64,  -30,  -44,   56,    5
    subsprite OAM_SIZE_16x16,   18,   20,  704,    5
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x64,    1,   -4, 1056,    5
    subsprite OAM_SIZE_64x32,  -38,  -36,  643,    5
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  868,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  806,    0
  FileD3CA_Obj_281:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -22,  -44,  896,    0
    subsprite OAM_SIZE_64x64,  -19,  -51,  132,    6
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  864,    6
    subsprite OAM_SIZE_16x32,  -13,    4,  804,    6
  FileD3CA_Obj_289:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_64x64,  -27,  -38,  512,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x32,  -19,  -12,  449,    0
    subsprite OAM_SIZE_32x64,  -27,  -52,  368,    0
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  802,    6
    subsprite OAM_SIZE_32x16,  -28,  -13,  772,    6
  FileD3CA_Obj_298:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_16x8,    10,   29,   42,    0
    subsprite OAM_SIZE_32x64,    2,  -35,  268,    0
    subsprite OAM_SIZE_64x32,  -38,  -35,  263,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_32x32,  -46,  -32,  706,    0
    subsprite OAM_SIZE_16x32,  -14,  -32,  710,    0
    subsprite OAM_SIZE_32x64,    0,    0,  396,    0
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  800,    6
    subsprite OAM_SIZE_32x16,  -27,  -14,  768,    6
  FileD3CA_Obj_310:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_8x8,     34,  -32,  496,    6
    subsprite OAM_SIZE_64x64,  -30,  -44,   56,    6
    subsprite OAM_SIZE_16x16,   18,   20,  704,    6
    subsprite OAM_SIZE_32x64,    1,   -4, 1056,    0
    subsprite OAM_SIZE_64x32,  -38,  -36,  643,    0
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  868,    6
    subsprite OAM_SIZE_16x32,  -13,    4,  806,    6
  FileD3CA_Obj_321:
    subsprite OAM_SIZE_32x32,   -7,  -11,  128,    0
    subsprite OAM_SIZE_32x16,  -19,    5, 1024,    0
    subsprite OAM_SIZE_32x64,  -19,  -15,  568,    0
    subsprite OAM_SIZE_64x64,  -30,  -44,   56,    0
    subsprite OAM_SIZE_16x16,   18,   20,  704,    0
    subsprite OAM_SIZE_8x8,     34,  -32,  496,    0
    subsprite OAM_SIZE_64x64,  -19,  -51,  132,    0
    subsprite OAM_SIZE_16x16,  -19,  -15,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  864,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  804,    0
  FileD3CA_Obj_331:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x64,  -22,  -44,  896,    0
    subsprite OAM_SIZE_64x32,  -19,  -12,  449,    0
    subsprite OAM_SIZE_32x64,  -27,  -52,  368,    0
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_16x32,  -12,    3,  802,    0
    subsprite OAM_SIZE_32x16,  -28,  -13,  772,    0
  FileD3CA_Obj_340:
    subsprite OAM_SIZE_32x32,   -9,   -9,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    2, 1024,    0
    subsprite OAM_SIZE_32x64,  -17,  -17,  568,    0
    subsprite OAM_SIZE_64x64,  -27,  -38,  512,    0
    subsprite OAM_SIZE_32x32,  -46,  -32,  706,    0
    subsprite OAM_SIZE_16x32,  -14,  -32,  710,    0
    subsprite OAM_SIZE_32x64,    0,    0,  396,    0
    subsprite OAM_SIZE_16x16,  -17,  -17,  568,    0
    subsprite OAM_SIZE_16x32,  -11,    2,  800,    0
    subsprite OAM_SIZE_32x16,  -27,  -14,  768,    0
  FileD3CA_Obj_350:
    subsprite OAM_SIZE_32x32,   -8,  -10,  128,    0
    subsprite OAM_SIZE_32x16,  -18,    3, 1024,    0
    subsprite OAM_SIZE_32x64,  -18,  -16,  568,    0
    subsprite OAM_SIZE_64x32,  -38,  -35,  263,    0
    subsprite OAM_SIZE_32x64,    2,  -35,  268,    0
    subsprite OAM_SIZE_16x8,    10,   29,   42,    0
    subsprite OAM_SIZE_32x64,    1,   -4, 1056,    0
    subsprite OAM_SIZE_64x32,  -38,  -36,  643,    0
    subsprite OAM_SIZE_16x16,  -18,  -16,  568,    0
    subsprite OAM_SIZE_32x16,  -29,  -12,  868,    0
    subsprite OAM_SIZE_16x32,  -13,    4,  806,    0
  FileD3CA_Obj_361:
    subsprite OAM_SIZE_64x64,  -23,  -37,    0,    0
    subsprite OAM_SIZE_32x16,  -55,  -24,  188,    0
    subsprite OAM_SIZE_16x8,   -55,   -8,  220,    0
    subsprite OAM_SIZE_8x16,   -31,   -8,  223,    0
    subsprite OAM_SIZE_16x8,     9,   43,   40,    0
    subsprite OAM_SIZE_16x16,    9,   27,    8,    0
    subsprite OAM_SIZE_8x16,    25,   27,   10,    0
  FileD3CA_Obj_368:
    subsprite OAM_SIZE_64x64,  -22,  -38,    0,    0
    subsprite OAM_SIZE_16x16,   10,   26,    8,    0
    subsprite OAM_SIZE_16x8,    10,   42,   40,    0
    subsprite OAM_SIZE_8x16,    26,   26,   10,    0
    subsprite OAM_SIZE_32x16,  -54,  -25,  188,    0
    subsprite OAM_SIZE_8x16,   -30,   -9,  223,    0
    subsprite OAM_SIZE_16x8,   -54,   -9,  220,    0
  FileD3CA_Obj_375:
    subsprite OAM_SIZE_32x32,  -13,  -30,  714,    0
    subsprite OAM_SIZE_8x32,    19,  -30,  718,    0
    subsprite OAM_SIZE_8x8,     19,  -38,  735,    0
    subsprite OAM_SIZE_8x8,     27,  -30,  719,    0
  FileD3CA_Obj_379:
    subsprite OAM_SIZE_32x32,  -16,  -62,  556,    0
    subsprite OAM_SIZE_16x16,    0,  -78,  526,    0
    subsprite OAM_SIZE_8x8,     -8,  -70,  541,    0
    subsprite OAM_SIZE_16x16,    0,  -30,  622,    0
    subsprite OAM_SIZE_8x8,     -8,  -30,  621,    0
  FileD3CA_Obj_384:
    subsprite OAM_SIZE_16x32,  -23,  -71, 1094,    0
    subsprite OAM_SIZE_16x16,  -23,  -39, 1124,    0
    subsprite OAM_SIZE_16x32,   -7,  -47, 1158,    0
  FileD3CA_Obj_387:
    subsprite OAM_SIZE_32x32,   -5,  -60,  652,    0
    subsprite OAM_SIZE_8x16,    11,  -76,   11,    0
    subsprite OAM_SIZE_16x8,    19,  -68,  636,    0
    subsprite OAM_SIZE_8x16,    27,  -60,  751,    0
    subsprite OAM_SIZE_8x8,     27,  -44,  699,    0
    subsprite OAM_SIZE_16x8,     3,  -28,  254,    0
    subsprite OAM_SIZE_8x8,     19,  -28,  222,    0
  FileD3CA_Obj_394:
    subsprite OAM_SIZE_16x32,    6,  -33,  782,    0
    subsprite OAM_SIZE_32x16,    6,  -49,  520,    0
    subsprite OAM_SIZE_16x16,   22,  -33,  841,    0
    subsprite OAM_SIZE_16x16,   30,  -65,  736,    0
    subsprite OAM_SIZE_8x8,     22,  -57,  620,    0
    subsprite OAM_SIZE_8x8,     38,  -49,  540,    0
  FileD3CA_Obj_400:
    subsprite OAM_SIZE_16x32,   -8,  -34,  712,   10
    subsprite OAM_SIZE_8x16,     8,  -26,  846,   10
    subsprite OAM_SIZE_8x16,   -16,  -18,  847,   10
    subsprite OAM_SIZE_8x8,    -16,  -25,  829,   10
    subsprite OAM_SIZE_16x8,    -8,   -2,  859,   10
    subsprite OAM_SIZE_16x8,    -8,  -42,  554,    0
  FileD3CA_Obj_406:
    subsprite OAM_SIZE_32x32,  -16,  -34,  872,   10
    subsprite OAM_SIZE_16x8,    -8,   -2,  843,   10
    subsprite OAM_SIZE_16x8,    -8,  -42,  552,   10
  FileD3CA_Obj_409:
    subsprite OAM_SIZE_32x32,  -16,  -34, 1028,   10
    subsprite OAM_SIZE_16x8,    -8,  -42,  552,   10
    subsprite OAM_SIZE_16x8,    -8,   -2,  843,   10
    subsprite OAM_SIZE_8x8,    -24,  -18,  829,   10
    subsprite OAM_SIZE_8x8,      9,  -18,  829,   10
  FileD3CA_Obj_414:
    subsprite OAM_SIZE_16x32,   -8,  -42,  936,   10
    subsprite OAM_SIZE_16x8,    -8,  -10,  524,   10
    subsprite OAM_SIZE_16x8,    -8,   -2,  843,   10
    subsprite OAM_SIZE_16x16,  -24,  -34, 1092,   10
    subsprite OAM_SIZE_16x8,   -24,  -18,  876,   10
    subsprite OAM_SIZE_16x16,    8,  -34, 1092,   10, xflip=1
    subsprite OAM_SIZE_16x8,     8,  -18,  876,   10, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -42, 1186,   10
    subsprite OAM_SIZE_8x8,      8,  -42, 1186,   10, xflip=1
  FileD3CA_Obj_423:
    subsprite OAM_SIZE_32x16,  -14,  -16, 1000,   10, xflip=1
    subsprite OAM_SIZE_32x16,  -14,    0, 1004,   10, xflip=1
    subsprite OAM_SIZE_16x8,   -14,  -24, 1184,   10, xflip=1
    subsprite OAM_SIZE_8x8,     18,    4,  878,   10, xflip=1
    subsprite OAM_SIZE_8x8,    -14,   16,  828,   10, xflip=1
    subsprite OAM_SIZE_8x16,   -22,    0,  845,   10, xflip=1

2:
FileD3CA_Cmds:
  FileD3CA_Cmd_0:
    animcmd   0,   9
    animcmd   1,   9
    animcmd   2,   9
    animcmd   3,   9
  FileD3CA_Cmd_4:
    animcmd   4,   4
    animcmd   5,   4
    animcmd   6,   4
    animcmd   7,   4
  FileD3CA_Cmd_8:
    animcmd  12,   3
    animcmd  16,   3
    animcmd   8,   3
    animcmd  13,   3
    animcmd  17,   3
    animcmd   9,   3
    animcmd  14,   3
    animcmd  18,   3
    animcmd  10,   3
    animcmd  15,   3
    animcmd  19,   3
    animcmd  11,   3
  FileD3CA_Cmd_20:
    animcmd   7,   8
    animcmd   6,   8
    animcmd   5,   8
  FileD3CA_Cmd_23:
    animcmd  20,   2
  FileD3CA_Cmd_24:
    animcmd  37,   5
    animcmd  22,   6
    animcmd  23,   7
    animcmd  24,   8
  FileD3CA_Cmd_28:
    animcmd  25,   2
    animcmd  29,   2
    animcmd  26,   2
    animcmd  30,   2
    animcmd  27,   2
    animcmd  31,   2
    animcmd  28,   2
    animcmd  32,   2
  FileD3CA_Cmd_36:
    animcmd  34,   9
    animcmd  35,   9
    animcmd  36,   9
    animcmd  33,   9
  FileD3CA_Cmd_40:
    animcmd  37,   2
    animcmd  38,   2
  FileD3CA_Cmd_42:
    animcmd  22,   6
    animcmd  23,   7
    animcmd  24,   8
    animcmd   6,   8
    animcmd   5,   8
  FileD3CA_Cmd_47:
    animcmd  37,   6
    animcmd  22,   6
    animcmd  23,   6
    animcmd  24,   6
  FileD3CA_Cmd_51:
    animcmd  37,   6
    animcmd  22,   6
    animcmd  23,   6
  FileD3CA_Cmd_54:
    animcmd  39,   1
  FileD3CA_Cmd_55:
    animcmd  40,   1
  FileD3CA_Cmd_56:
    animcmd  41,   1
  FileD3CA_Cmd_57:
    animcmd  42,   1
  FileD3CA_Cmd_58:
    animcmd  43,   1
  FileD3CA_Cmd_59:
    animcmd  44,   1
  FileD3CA_Cmd_60:
    animcmd  45,  16
    animcmd  46,   8
    animcmd  47,  54
  FileD3CA_Cmd_63:
    animcmd  48,   1

FileD3CA_Tiles:
  .incbin "data/spriteset/duneyrr.4bpp"
