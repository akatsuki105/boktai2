FileD3EA_Header:
  .2byte 626 @ palStart
  .2byte 135 @ metaspriteCount
  .2byte 42 @ animationCount
  .2byte 887 @ subspriteCount
  .2byte 180 @ cmdCount
  .2byte 2048 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 2732 @ offsetToAnims
  .4byte 3068 @ offsetToSubsprites
  .4byte 10164 @ offsetToCmds
  .4byte 10884 @ offsetToTiles

FileD3EA_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x373A, FileD3EA_Obj_0,     9,          -79,  -88,   47,    0
  pose 0x373B, FileD3EA_Obj_9,     7,          -72,  -99,   39,   11
  pose 0x373C, FileD3EA_Obj_16,    7,          -49, -109,   16,   21
  pose 0x373D, FileD3EA_Obj_23,    7,          -71, -100,   39,   12
  pose 0x373E, FileD3EA_Obj_30,    9,          -79,  -80,   47,    0
  pose 0x373F, FileD3EA_Obj_39,    7,          -72,  -99,   39,   11
  pose 0x3740, FileD3EA_Obj_46,    7,          -48, -109,   17,   21
  pose 0x3741, FileD3EA_Obj_53,    7,          -71, -100,   39,   11
  pose 0x7A92, FileD3EA_Obj_60,    9,          -63,  -88,   32,    0
  pose 0x7A93, FileD3EA_Obj_69,    5,          -48,  -88,   24,    8
  pose 0x7A94, FileD3EA_Obj_74,    7,          -48,  -80,   16,    8
  pose 0x7A95, FileD3EA_Obj_81,    6,          -56,  -80,   24,    8
  pose 0x7A96, FileD3EA_Obj_87,    7,          -64,  -80,   33,    0
  pose 0x7A97, FileD3EA_Obj_94,    6,          -56,  -80,   24,    8
  pose 0x7A98, FileD3EA_Obj_100,   7,          -48,  -80,   16,    8
  pose 0x7A99, FileD3EA_Obj_107,   5,          -48,  -88,   24,    8
  pose 0xCB99, FileD3EA_Obj_112,   6,          -48,  -79,   34,    0
  pose 0xCB9A, FileD3EA_Obj_118,   7,          -48,  -92,   39,   16
  pose 0xCB9B, FileD3EA_Obj_125,   7,          -44,  -84,   26,   16
  pose 0xCB9C, FileD3EA_Obj_132,   8,          -44,  -79,   25,    8
  pose 0xCB9D, FileD3EA_Obj_140,   8,          -44,  -79,   25,    8
  pose 0xCB9E, FileD3EA_Obj_148,   6,          -44,  -85,   28,    8
  pose 0xCB9F, FileD3EA_Obj_154,   7,          -48,  -92,   39,   16
  pose 0xCBA0, FileD3EA_Obj_161,   6,          -48,  -79,   35,   16
  pose 0xC399, FileD3EA_Obj_167,   9,          -50,  -77,   25,    8
  pose 0xC39A, FileD3EA_Obj_176,   8,          -45,  -79,   37,    8
  pose 0xC39B, FileD3EA_Obj_184,   6,          -48,  -85,   34,    8
  pose 0xC39C, FileD3EA_Obj_190,   8,          -48,  -77,   31,    8
  pose 0xC39D, FileD3EA_Obj_198,   7,          -48,  -77,   31,    8
  pose 0xC39E, FileD3EA_Obj_205,   7,          -45,  -77,   33,    0
  pose 0xC39F, FileD3EA_Obj_212,   7,          -45,  -85,   37,   24
  pose 0xC3A0, FileD3EA_Obj_219,   10,         -50,  -77,   25,    8
  pose 0x0EF2, FileD3EA_Obj_229,   4,          -48,  -79,   20,    0
  pose 0x0EF3, FileD3EA_Obj_233,   5,          -48,  -79,   24,   16
  pose 0x0EF4, FileD3EA_Obj_238,   5,          -44,  -79,   24,   16
  pose 0x0EF5, FileD3EA_Obj_243,   6,          -44,  -79,   24,    8
  pose 0x0EF6, FileD3EA_Obj_249,   6,          -44,  -79,   24,    8
  pose 0x0EF7, FileD3EA_Obj_255,   4,          -44,  -79,   24,    8
  pose 0x0EF8, FileD3EA_Obj_259,   5,          -48,  -79,   24,   16
  pose 0x0EF9, FileD3EA_Obj_264,   4,          -48,  -79,   20,   16
  pose 0x06F2, FileD3EA_Obj_268,   6,          -48,  -77,   24,    8
  pose 0x06F3, FileD3EA_Obj_274,   5,          -45,  -77,   24,    8
  pose 0x06F4, FileD3EA_Obj_279,   3,          -48,  -85,   19,    8
  pose 0x06F5, FileD3EA_Obj_282,   5,          -48,  -77,   19,    8
  pose 0x06F6, FileD3EA_Obj_287,   4,          -48,  -77,   19,    8
  pose 0x06F7, FileD3EA_Obj_291,   4,          -45,  -77,   24,    0
  pose 0x06F8, FileD3EA_Obj_295,   4,          -45,  -85,   24,   24
  pose 0x06F9, FileD3EA_Obj_299,   7,          -48,  -77,   24,    8
  pose 0x9E5C, FileD3EA_Obj_306,   6,          -48,  -64,   22,    8
  pose 0x9E5D, FileD3EA_Obj_312,   6,          -48,  -80,   25,   16
  pose 0x9E5E, FileD3EA_Obj_318,   6,          -24,  -64,   20,   16
  pose 0x9E5F, FileD3EA_Obj_324,   6,          -40,  -64,   24,   32
  pose 0x9E60, FileD3EA_Obj_330,   6,          -48,  -64,   21,    8
  pose 0xE1B4, FileD3EA_Obj_336,   4,          -48,  -64,   16,    8
  pose 0xE1B5, FileD3EA_Obj_340,   4,          -48,  -80,   16,   16
  pose 0xE1B6, FileD3EA_Obj_344,   4,          -24,  -64,   16,   16
  pose 0xE1B7, FileD3EA_Obj_348,   4,          -40,  -64,   24,   32
  pose 0xE1B8, FileD3EA_Obj_352,   4,          -48,  -64,   16,    8
  pose 0x5A89, FileD3EA_Obj_356,   8,          -40,  -72,   24,    8
  pose 0x5A8A, FileD3EA_Obj_364,   10,         -63,  -90,   16,    8
  pose 0x5A8B, FileD3EA_Obj_374,   11,         -73,  -88,   16,   16
  pose 0x5A8C, FileD3EA_Obj_385,   10,         -66,  -79,   24,   16
  pose 0x5A8D, FileD3EA_Obj_395,   7,          -48,  -71,   32,    8
  pose 0x5A8E, FileD3EA_Obj_402,   5,          -47,  -72,   24,   16
  pose 0x51FB, FileD3EA_Obj_407,   5,          -47,  -67,   24,   16
  pose 0x51FC, FileD3EA_Obj_412,   5,          -45,  -64,   24,   16
  pose 0x51FD, FileD3EA_Obj_417,   5,          -44,  -67,   24,   16
  pose 0x51FE, FileD3EA_Obj_422,   4,          -40,  -64,   24,   16
  pose 0x5A8F, FileD3EA_Obj_426,   6,          -40,  -72,   24,    8
  pose 0x4914, FileD3EA_Obj_432,   8,          -40,  -72,   24,    8
  pose 0x4915, FileD3EA_Obj_440,   10,         -63,  -90,   16,    8
  pose 0x4917, FileD3EA_Obj_450,   10,         -61,  -91,   24,   16
  pose 0x4918, FileD3EA_Obj_460,   12,         -83, -118,   49,   26
  pose 0x4919, FileD3EA_Obj_472,   9,          -44,  -64,   50,   20
  pose 0x491A, FileD3EA_Obj_481,   8,          -40,  -64,   50,   20
  pose 0x491B, FileD3EA_Obj_489,   8,          -40,  -64,   50,   20
  pose 0x628F, FileD3EA_Obj_497,   6,          -40,  -72,   24,   24
  pose 0x6290, FileD3EA_Obj_503,   9,          -55,  -84,   24,   16
  pose 0x6291, FileD3EA_Obj_512,   10,         -72,  -88,   16,    8
  pose 0x6292, FileD3EA_Obj_522,   9,          -52,  -99,   45,   16
  pose 0x6293, FileD3EA_Obj_531,   6,          -40,  -80,   32,   16
  pose 0x6294, FileD3EA_Obj_537,   7,          -45,  -75,   24,    8
  pose 0x52BC, FileD3EA_Obj_544,   7,          -40,  -72,   24,    8
  pose 0x52BD, FileD3EA_Obj_551,   7,          -40,  -72,   24,    8
  pose 0x52BE, FileD3EA_Obj_558,   7,          -40,  -72,   24,    8
  pose 0x52BF, FileD3EA_Obj_565,   7,          -40,  -72,   24,    8
  pose 0x6295, FileD3EA_Obj_572,   4,          -40,  -72,   24,   24
  pose 0x5114, FileD3EA_Obj_576,   6,          -40,  -72,   24,   24
  pose 0x5115, FileD3EA_Obj_582,   9,          -55,  -84,   24,   16
  pose 0x5117, FileD3EA_Obj_591,   9,          -40,  -81,   32,   16
  pose 0x5118, FileD3EA_Obj_600,   11,         -40, -102,   50,   16
  pose 0x5119, FileD3EA_Obj_611,   9,          -42, -103,   51,   16
  pose 0x511A, FileD3EA_Obj_620,   9,          -41, -103,   51,   16
  pose 0x511B, FileD3EA_Obj_629,   9,          -40, -103,   51,   16
  pose 0x2996, FileD3EA_Obj_638,   4,          -48,  -80,   16,    8
  pose 0x2997, FileD3EA_Obj_642,   4,          -48,  -80,   37,   24
  pose 0x2196, FileD3EA_Obj_646,   3,          -48,  -80,   16,   16
  pose 0x2197, FileD3EA_Obj_649,   4,          -48,  -80,   27,   16
  pose 0x1985, FileD3EA_Obj_653,   6,          -48,  -64,   16,   29
  pose 0x1986, FileD3EA_Obj_659,   6,          -48,  -64,   16,   29
  pose 0x1987, FileD3EA_Obj_665,   7,          -48,  -66,   16,   29
  pose 0x1988, FileD3EA_Obj_672,   7,          -48,  -66,   16,   29
  pose 0xF230, FileD3EA_Obj_679,   6,          -50,  -76,   22,    4
  pose 0xF22E, FileD3EA_Obj_685,   5,          -48,  -80,   32,   16
  pose 0x5D39, FileD3EA_Obj_690,   6,          -50,  -76,   22,    4
  pose 0x5D37, FileD3EA_Obj_696,   3,          -48,  -80,   24,   16
  pose 0x705B, FileD3EA_Obj_699,   2,          -48,  -72,   16,   24
  pose 0x705C, FileD3EA_Obj_701,   4,          -40,  -80,   24,    8
  pose 0x705D, FileD3EA_Obj_705,   5,          -40,  -80,   24,   16
  pose 0x705E, FileD3EA_Obj_710,   6,          -40,  -80,   24,   16
  pose 0x705F, FileD3EA_Obj_716,   3,          -48,  -88,   16,   24
  pose 0xB06D, FileD3EA_Obj_719,   6,          -50,  -76,   22,    4
  pose 0xB06E, FileD3EA_Obj_725,   3,          -45,  -77,   19,    0
  pose 0xB06F, FileD3EA_Obj_728,   5,          -21,  -57,   20,    0
  pose 0xB070, FileD3EA_Obj_733,   5,          -21,  -56,   20,    0
  pose 0xA86D, FileD3EA_Obj_738,   3,          -48,  -80,   24,   16
  pose 0xA86E, FileD3EA_Obj_741,   3,          -43,  -75,   22,   29
  pose 0xA86F, FileD3EA_Obj_744,   3,          -44,  -64,   22,   29
  pose 0xA870, FileD3EA_Obj_747,   4,          -43,  -66,   22,   29
  pose 0xA871, FileD3EA_Obj_751,   9,          -43,  -63,   22,   29
  pose 0xA872, FileD3EA_Obj_760,   7,          -39,  -68,   25,   12
  pose 0x59E2, FileD3EA_Obj_767,   9,          -49,  -98,   35,    6
  pose 0x5DE2, FileD3EA_Obj_776,   8,          -49,  -97,   36,    6
  pose 0x61E2, FileD3EA_Obj_784,   8,          -49,  -96,   37,    6
  pose 0x59E0, FileD3EA_Obj_792,   8,          -47,  -77,   22,    5
  pose 0x5DE0, FileD3EA_Obj_800,   7,          -47,  -77,   24,    5
  pose 0x61E0, FileD3EA_Obj_807,   7,          -47,  -77,   26,    5
  pose 0x129D, FileD3EA_Obj_814,   9,          -49,  -68,   24,    6
  pose 0x169D, FileD3EA_Obj_823,   8,          -49,  -68,   24,    6
  pose 0x1A9D, FileD3EA_Obj_831,   9,          -49,  -68,   24,    6
  pose 0x1E9D, FileD3EA_Obj_840,   8,          -49,  -68,   24,    6
  pose 0x129B, FileD3EA_Obj_848,   9,          -47,  -67,   25,    5
  pose 0x169B, FileD3EA_Obj_857,   10,         -47,  -67,   25,    5
  pose 0x1A9B, FileD3EA_Obj_867,   10,         -47,  -67,   25,    5
  pose 0x1E9B, FileD3EA_Obj_877,   10,         -47,  -67,   25,    5

FileD3EA_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0xCA8A, FileD3EA_Cmd_0,     8
  animation 0xA09B, FileD3EA_Cmd_8,     8
  animation 0x9E5C, FileD3EA_Cmd_16,    1
  animation 0x9E5D, FileD3EA_Cmd_17,    1
  animation 0x9E5E, FileD3EA_Cmd_18,    1
  animation 0x9E5F, FileD3EA_Cmd_19,    1
  animation 0x9E60, FileD3EA_Cmd_20,    1
  animation 0xE1B4, FileD3EA_Cmd_21,    1
  animation 0xE1B5, FileD3EA_Cmd_22,    1
  animation 0xE1B6, FileD3EA_Cmd_23,    1
  animation 0xE1B7, FileD3EA_Cmd_24,    1
  animation 0xE1B8, FileD3EA_Cmd_25,    1
  animation 0xE26F, FileD3EA_Cmd_26,    8
  animation 0xE26D, FileD3EA_Cmd_34,    8
  animation 0xB880, FileD3EA_Cmd_42,    8
  animation 0xB87E, FileD3EA_Cmd_50,    8
  animation 0x9FD5, FileD3EA_Cmd_58,    12
  animation 0x9FD3, FileD3EA_Cmd_70,    12
  animation 0x4111, FileD3EA_Cmd_82,    8
  animation 0x410F, FileD3EA_Cmd_90,    8
  animation 0x6187, FileD3EA_Cmd_98,    3
  animation 0x6185, FileD3EA_Cmd_101,   3
  animation 0x1985, FileD3EA_Cmd_104,   2
  animation 0x1986, FileD3EA_Cmd_106,   2
  animation 0x1987, FileD3EA_Cmd_108,   1
  animation 0xF230, FileD3EA_Cmd_109,   1
  animation 0xF22E, FileD3EA_Cmd_110,   1
  animation 0x5D39, FileD3EA_Cmd_111,   1
  animation 0x5D37, FileD3EA_Cmd_112,   1
  animation 0x705B, FileD3EA_Cmd_113,   1
  animation 0x705C, FileD3EA_Cmd_114,   1
  animation 0x705D, FileD3EA_Cmd_115,   1
  animation 0x705E, FileD3EA_Cmd_116,   1
  animation 0x705F, FileD3EA_Cmd_117,   1
  animation 0x1769, FileD3EA_Cmd_118,   20
  animation 0x1767, FileD3EA_Cmd_138,   20
  animation 0x6398, FileD3EA_Cmd_158,   4
  animation 0x6396, FileD3EA_Cmd_162,   4
  animation 0x9246, FileD3EA_Cmd_166,   6
  animation 0x9244, FileD3EA_Cmd_172,   6
  animation 0x1699, FileD3EA_Cmd_178,   1
  animation 0x169A, FileD3EA_Cmd_179,   1

1:
FileD3EA_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD3EA_Obj_0:
    subsprite OAM_SIZE_32x16,  -47,  -36,  996,    0, xflip=1
    subsprite OAM_SIZE_32x16,   15,  -37,  996,    0, yflip=1
    subsprite OAM_SIZE_32x8,   -31,  -32,   20,    0, xflip=1
    subsprite OAM_SIZE_32x8,     0,  -32,   20,    0
    subsprite OAM_SIZE_16x8,     0,  -40,   82,    0
    subsprite OAM_SIZE_32x32,  -16,  -56,  452,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   72,    0
    subsprite OAM_SIZE_8x8,    -16,   -8,  971,    0
    subsprite OAM_SIZE_8x16,     8,  -16,  260,    0
  FileD3EA_Obj_9:
    subsprite OAM_SIZE_32x32,  -40,  -21,  264,    0
    subsprite OAM_SIZE_32x32,    7,  -67,  264,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -16,  -24,   68,    0
    subsprite OAM_SIZE_8x8,    -24,  -16, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,  -40,   36,    0
    subsprite OAM_SIZE_16x8,     8,  -48,   98,    0
    subsprite OAM_SIZE_32x32,  -16,  -56, 1536,    0
  FileD3EA_Obj_16:
    subsprite OAM_SIZE_32x32,  -17,  -11,  323,    0
    subsprite OAM_SIZE_32x32,  -16,  -77,  323,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x32,   -8,  -56,  192,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,  194,    0
    subsprite OAM_SIZE_8x16,     8,  -24,  903,    0
    subsprite OAM_SIZE_32x16,  -16,  -40,   12,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,   44,    0
  FileD3EA_Obj_23:
    subsprite OAM_SIZE_32x32,  -39,  -68, 1184,    0
    subsprite OAM_SIZE_32x32,    7,  -20, 1184,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,   -8,  -24,  196,    0
    subsprite OAM_SIZE_32x16,  -24,  -40,  164,    0
    subsprite OAM_SIZE_16x8,   -24,  -48, 1748,    0
    subsprite OAM_SIZE_8x8,      8,  -32,  235,    0
    subsprite OAM_SIZE_32x32,  -16,  -48,   76,    0
  FileD3EA_Obj_30:
    subsprite OAM_SIZE_8x16,     8,  -16,  292,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   74,    0
    subsprite OAM_SIZE_8x8,    -16,   -8,  987,    0
    subsprite OAM_SIZE_32x16,  -47,  -36,  996,    0, xflip=1
    subsprite OAM_SIZE_32x16,   15,  -37,  996,    0, yflip=1
    subsprite OAM_SIZE_32x8,   -32,  -32,    4,    0
    subsprite OAM_SIZE_8x8,     -8,  -40,  152,    0
    subsprite OAM_SIZE_32x8,     1,  -32,    4,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -48,  140,    0
  FileD3EA_Obj_39:
    subsprite OAM_SIZE_32x32,  -40,  -21,  264,    0
    subsprite OAM_SIZE_32x32,    7,  -67,  264,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -24,  -24,  196,    0, xflip=1
    subsprite OAM_SIZE_32x16,   -8,  -40,  164,    0, xflip=1
    subsprite OAM_SIZE_16x8,     8,  -48, 1748,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -32,  235,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -48,  204,    0
  FileD3EA_Obj_46:
    subsprite OAM_SIZE_32x32,  -16,  -11,  323,    0
    subsprite OAM_SIZE_32x32,  -15,  -77,  323,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x32,   -8,  -56,  192,    0, xflip=1
    subsprite OAM_SIZE_16x32,   -8,  -24,  194,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -16,  -24,  903,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,  -40,  160,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,  688,    0
  FileD3EA_Obj_53:
    subsprite OAM_SIZE_32x32,  -39,  -68, 1184,    0
    subsprite OAM_SIZE_32x32,    7,  -21, 1184,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -16,  -24,   68,    0, xflip=1
    subsprite OAM_SIZE_8x8,     16,  -16, 1548,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,  -40,   36,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -24,  -48,   98,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -56,  256,    0
  FileD3EA_Obj_60:
    subsprite OAM_SIZE_32x8,   -31,  -32,   20,    0, xflip=1
    subsprite OAM_SIZE_32x8,     0,  -32,   20,    0
    subsprite OAM_SIZE_16x8,     0,  -40,   82,    0
    subsprite OAM_SIZE_32x32,  -16,  -56,  452,    0
    subsprite OAM_SIZE_8x8,    -32,  -28,  124,    0
    subsprite OAM_SIZE_8x8,     18,  -28,  124,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     8,  -16,  260,    0
    subsprite OAM_SIZE_8x8,    -16,   -8,  971,    0
  FileD3EA_Obj_69:
    subsprite OAM_SIZE_32x32,  -16,  -24,   68,    0
    subsprite OAM_SIZE_8x8,    -24,  -16, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,  -40,   36,    0
    subsprite OAM_SIZE_16x8,     8,  -48,   98,    0
    subsprite OAM_SIZE_32x32,  -16,  -56, 1536,    0
  FileD3EA_Obj_74:
    subsprite OAM_SIZE_16x32,   -8,  -56,  192,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,  194,    0
    subsprite OAM_SIZE_8x16,     8,  -24,  903,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,   34,    0
    subsprite OAM_SIZE_16x8,    -8,  -56,   80,    0
    subsprite OAM_SIZE_32x16,  -16,  -40,   12,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,   44,    0
  FileD3EA_Obj_81:
    subsprite OAM_SIZE_32x32,   -8,  -24,  196,    0
    subsprite OAM_SIZE_32x16,  -24,  -40,  164,    0
    subsprite OAM_SIZE_16x8,   -24,  -48, 1748,    0
    subsprite OAM_SIZE_8x8,      8,  -32,  235,    0
    subsprite OAM_SIZE_32x32,  -16,  -48,   76,    0
    subsprite OAM_SIZE_16x8,     8,  -16,  134,    0
  FileD3EA_Obj_87:
    subsprite OAM_SIZE_8x16,     8,  -16,  292,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   74,    0
    subsprite OAM_SIZE_8x8,    -16,   -8,  987,    0
    subsprite OAM_SIZE_32x8,     1,  -32,    4,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -40,  152,    0
    subsprite OAM_SIZE_32x8,   -32,  -32,    4,    0
    subsprite OAM_SIZE_32x32,  -16,  -48,  140,    0
  FileD3EA_Obj_94:
    subsprite OAM_SIZE_32x32,  -24,  -24,  196,    0, xflip=1
    subsprite OAM_SIZE_32x16,   -8,  -40,  164,    0, xflip=1
    subsprite OAM_SIZE_16x8,     8,  -48, 1748,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -32,  235,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -48,  204,    0
    subsprite OAM_SIZE_16x8,   -24,  -16,  134,    0, xflip=1
  FileD3EA_Obj_100:
    subsprite OAM_SIZE_16x32,   -8,  -56,  192,    0, xflip=1
    subsprite OAM_SIZE_16x32,   -8,  -24,  194,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -16,  -24,  903,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,   -8,   34,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -8,  -56,   80,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,  -40,  160,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,  688,    0
  FileD3EA_Obj_107:
    subsprite OAM_SIZE_32x32,  -16,  -24,   68,    0, xflip=1
    subsprite OAM_SIZE_8x8,     16,  -16, 1548,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,  -40,   36,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -24,  -48,   98,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -56,  256,    0
  FileD3EA_Obj_112:
    subsprite OAM_SIZE_16x32,    0,  -63,  832,    0
    subsprite OAM_SIZE_32x32,    2,  -33, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -32,  512,    0
    subsprite OAM_SIZE_8x8,      8,  -40,  576,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  268,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  315,    0
  FileD3EA_Obj_118:
    subsprite OAM_SIZE_32x32,   -8,  -60, 1604,    0
    subsprite OAM_SIZE_32x32,    7,  -46, 1484,    0
    subsprite OAM_SIZE_32x32,  -16,  -32,  516,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  592,    0
    subsprite OAM_SIZE_8x16,    16,  -24,  580,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  168,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  299,    0
  FileD3EA_Obj_125:
    subsprite OAM_SIZE_32x32,   -9,  -52, 1184,    0, xflip=1
    subsprite OAM_SIZE_16x32,   10,  -53,  782,    0
    subsprite OAM_SIZE_16x32,   -8,  -32,  520,    0
    subsprite OAM_SIZE_16x16,    8,  -32,  522,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  578,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  137,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  128,    0
  FileD3EA_Obj_132:
    subsprite OAM_SIZE_32x16,  -11,  -31,  996,    0
    subsprite OAM_SIZE_16x32,    9,  -56,  832,    0
    subsprite OAM_SIZE_32x32,   -8,  -40,  524,    0
    subsprite OAM_SIZE_8x8,    -16,  -32,  577,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  800,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  784,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  581,    0
    subsprite OAM_SIZE_8x8,    -16,   -8, 1091,    0
  FileD3EA_Obj_140:
    subsprite OAM_SIZE_32x16,  -12,  -32,  996,    0
    subsprite OAM_SIZE_16x32,    9,  -57,  832,    0
    subsprite OAM_SIZE_32x32,   -8,  -32,  608,    0
    subsprite OAM_SIZE_8x8,     -8,    0,  595,    0
    subsprite OAM_SIZE_8x8,    -16,  -32,  594,    0
    subsprite OAM_SIZE_16x8,     8,  -40,  585,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  268,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  315,    0
  FileD3EA_Obj_148:
    subsprite OAM_SIZE_32x32,   -9,  -53, 1184,    0, xflip=1
    subsprite OAM_SIZE_16x32,   12,  -52,  776,    0
    subsprite OAM_SIZE_32x32,   -8,  -32,  612,    0
    subsprite OAM_SIZE_8x8,     -8,    0,  674,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  168,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  299,    0
  FileD3EA_Obj_154:
    subsprite OAM_SIZE_32x32,   -8,  -60, 1604,    0
    subsprite OAM_SIZE_32x32,    7,  -46, 1484,    0
    subsprite OAM_SIZE_32x32,   -8,  -40,  616,    0
    subsprite OAM_SIZE_32x16,  -16,  -16,  588,    0
    subsprite OAM_SIZE_16x8,   -16,    0,  601,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  137,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  128,    0
  FileD3EA_Obj_161:
    subsprite OAM_SIZE_16x32,    0,  -62,  832,    0
    subsprite OAM_SIZE_32x32,    3,  -32, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -32,  620,    0
    subsprite OAM_SIZE_16x8,   -16,    0,  672,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  800,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  784,    0
  FileD3EA_Obj_167:
    subsprite OAM_SIZE_16x32,    9,  -57,  834,    0
    subsprite OAM_SIZE_32x32,  -16,  -40,  704,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  682,    0
    subsprite OAM_SIZE_8x16,    16,  -40,  587,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  420,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  404,    0
    subsprite OAM_SIZE_32x32,  -18,  -29,  320,    0
    subsprite OAM_SIZE_8x8,    -13,  -24, 1600,    0
    subsprite OAM_SIZE_8x8,     -8,  -29,  959,    0
  FileD3EA_Obj_176:
    subsprite OAM_SIZE_32x32,    5,  -47, 1184,    0, xflip=1
    subsprite OAM_SIZE_32x32,   -8,  -40,  708,    0
    subsprite OAM_SIZE_16x8,    -8,   -8, 1124,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  684,    0
    subsprite OAM_SIZE_32x16,  -11,  -24,  996,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 1616,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  424,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  388,    0
  FileD3EA_Obj_184:
    subsprite OAM_SIZE_32x16,    2,  -33,  996,    0
    subsprite OAM_SIZE_32x32,  -16,  -40,  712,    0
    subsprite OAM_SIZE_16x8,   -16,   -8,  692,    0
    subsprite OAM_SIZE_32x32,  -13,  -53,  396,    0
    subsprite OAM_SIZE_32x32,   -7,  -41,  826,    0
    subsprite OAM_SIZE_8x8,     -2,  -22, 1550,    0
  FileD3EA_Obj_190:
    subsprite OAM_SIZE_32x32,   -1,  -35, 1028,    0
    subsprite OAM_SIZE_32x32,  -16,  -40,  716,    0
    subsprite OAM_SIZE_16x8,     0,   -8, 1126,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  392,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,   59,    0
    subsprite OAM_SIZE_16x32,   -1,  -50,  834,    0
    subsprite OAM_SIZE_8x8,      4,  -27, 1549,    0
    subsprite OAM_SIZE_8x8,     -8,  -28,  943,    0
  FileD3EA_Obj_198:
    subsprite OAM_SIZE_32x32,   -1,  -36, 1028,    0
    subsprite OAM_SIZE_32x32,  -16,  -40,  904,    0
    subsprite OAM_SIZE_16x8,     0,   -8,  676,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  420,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  404,    0
    subsprite OAM_SIZE_16x32,    0,  -51,  834,    0
    subsprite OAM_SIZE_8x8,      5,  -27, 1549,    0
  FileD3EA_Obj_205:
    subsprite OAM_SIZE_32x16,    1,  -32,  996,    0
    subsprite OAM_SIZE_32x32,   -8,  -40,  327,    0
    subsprite OAM_SIZE_8x8,      0,   -8,  680,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  424,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  388,    0
    subsprite OAM_SIZE_32x32,   -7,  -40,  826,    0
    subsprite OAM_SIZE_8x8,     -2,  -21, 1550,    0
  FileD3EA_Obj_212:
    subsprite OAM_SIZE_32x32,    5,  -48, 1184,    0, xflip=1
    subsprite OAM_SIZE_32x32,   -8,  -40,  972,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  696,    0
    subsprite OAM_SIZE_32x8,    -8,   -8,  145,    0
    subsprite OAM_SIZE_32x32,  -13,  -53,  396,    0
    subsprite OAM_SIZE_32x16,  -11,  -25,  996,    0
    subsprite OAM_SIZE_8x8,     -5,  -21, 1616,    0
  FileD3EA_Obj_219:
    subsprite OAM_SIZE_16x32,    9,  -56,  834,    0
    subsprite OAM_SIZE_16x16,    0,   -8,  686,    0
    subsprite OAM_SIZE_8x8,     -8,   -8,  685,    0
    subsprite OAM_SIZE_32x32,  -16,  -40,  384,    0
    subsprite OAM_SIZE_8x16,    16,  -40,  681,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  392,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,   59,    0
    subsprite OAM_SIZE_32x32,  -18,  -28,  320,    0
    subsprite OAM_SIZE_8x8,    -13,  -23, 1600,    0
    subsprite OAM_SIZE_8x8,     -9,  -30,  927,    0
  FileD3EA_Obj_229:
    subsprite OAM_SIZE_32x32,  -16,  -32,  512,    0
    subsprite OAM_SIZE_8x8,      8,  -40,  576,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  268,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  315,    0
  FileD3EA_Obj_233:
    subsprite OAM_SIZE_32x32,  -16,  -32,  516,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  592,    0
    subsprite OAM_SIZE_8x16,    16,  -24,  580,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  168,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  299,    0
  FileD3EA_Obj_238:
    subsprite OAM_SIZE_16x32,   -8,  -32,  520,    0
    subsprite OAM_SIZE_16x16,    8,  -32,  522,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  578,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  137,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  128,    0
  FileD3EA_Obj_243:
    subsprite OAM_SIZE_32x32,   -8,  -40,  524,    0
    subsprite OAM_SIZE_8x8,    -16,  -32,  577,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  800,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  784,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  581,    0
    subsprite OAM_SIZE_8x8,    -16,   -8, 1091,    0
  FileD3EA_Obj_249:
    subsprite OAM_SIZE_32x32,   -8,  -32,  608,    0
    subsprite OAM_SIZE_8x8,     -8,    0,  595,    0
    subsprite OAM_SIZE_8x8,    -16,  -32,  594,    0
    subsprite OAM_SIZE_16x8,     8,  -40,  585,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  268,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  315,    0
  FileD3EA_Obj_255:
    subsprite OAM_SIZE_32x32,   -8,  -32,  612,    0
    subsprite OAM_SIZE_8x8,     -8,    0,  674,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  168,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  299,    0
  FileD3EA_Obj_259:
    subsprite OAM_SIZE_32x32,   -8,  -40,  616,    0
    subsprite OAM_SIZE_32x16,  -16,  -16,  588,    0
    subsprite OAM_SIZE_16x8,   -16,    0,  601,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  137,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  128,    0
  FileD3EA_Obj_264:
    subsprite OAM_SIZE_32x32,  -16,  -32,  620,    0
    subsprite OAM_SIZE_16x8,   -16,    0,  672,    0
    subsprite OAM_SIZE_32x16,  -12,  -39,  800,    0
    subsprite OAM_SIZE_32x8,   -12,  -47,  784,    0
  FileD3EA_Obj_268:
    subsprite OAM_SIZE_32x32,  -16,  -40,  704,    0
    subsprite OAM_SIZE_16x16,   -8,   -8,  682,    0
    subsprite OAM_SIZE_8x16,    16,  -40,  587,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  420,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  404,    0
    subsprite OAM_SIZE_8x8,     -8,  -29,  959,    0
  FileD3EA_Obj_274:
    subsprite OAM_SIZE_32x32,   -8,  -40,  708,    0
    subsprite OAM_SIZE_16x8,    -8,   -8, 1124,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  684,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  424,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  388,    0
  FileD3EA_Obj_279:
    subsprite OAM_SIZE_32x32,  -16,  -40,  712,    0
    subsprite OAM_SIZE_16x8,   -16,   -8,  692,    0
    subsprite OAM_SIZE_32x32,  -13,  -53,  396,    0
  FileD3EA_Obj_282:
    subsprite OAM_SIZE_32x32,  -16,  -40,  716,    0
    subsprite OAM_SIZE_16x8,     0,   -8, 1126,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  392,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,   59,    0
    subsprite OAM_SIZE_8x8,     -8,  -28,  943,    0
  FileD3EA_Obj_287:
    subsprite OAM_SIZE_32x32,  -16,  -40,  904,    0
    subsprite OAM_SIZE_16x8,     0,   -8,  676,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  420,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  404,    0
  FileD3EA_Obj_291:
    subsprite OAM_SIZE_32x32,   -8,  -40,  327,    0
    subsprite OAM_SIZE_8x8,      0,   -8,  680,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  424,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,  388,    0
  FileD3EA_Obj_295:
    subsprite OAM_SIZE_32x32,   -8,  -40,  972,    0
    subsprite OAM_SIZE_8x8,    -16,  -24,  696,    0
    subsprite OAM_SIZE_32x8,    -8,   -8,  145,    0
    subsprite OAM_SIZE_32x32,  -13,  -53,  396,    0
  FileD3EA_Obj_299:
    subsprite OAM_SIZE_32x32,  -16,  -40,  384,    0
    subsprite OAM_SIZE_8x16,    16,  -40,  681,    0
    subsprite OAM_SIZE_32x16,  -13,  -37,  392,    0
    subsprite OAM_SIZE_32x8,   -13,  -45,   59,    0
    subsprite OAM_SIZE_8x8,     -9,  -30,  927,    0
    subsprite OAM_SIZE_16x16,    0,   -8,  686,    0
    subsprite OAM_SIZE_8x8,     -8,   -8,  685,    0
  FileD3EA_Obj_306:
    subsprite OAM_SIZE_32x32,  -16,  -32,  772,    0
    subsprite OAM_SIZE_16x16,   -8,  -48,  868,    0
    subsprite OAM_SIZE_16x32,  -21,  -40,  908,    0
    subsprite OAM_SIZE_16x32,    6,  -40,  908,    0, xflip=1
    subsprite OAM_SIZE_8x8,      4,    0,   63,    0
    subsprite OAM_SIZE_8x8,     -9,    0,   63,    0
  FileD3EA_Obj_312:
    subsprite OAM_SIZE_32x32,  -16,  -32,  899,    0
    subsprite OAM_SIZE_32x16,  -16,  -48,  967,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  836,    0
    subsprite OAM_SIZE_16x16,    9,  -36, 1002,    0
    subsprite OAM_SIZE_16x16,   -2,  -28, 1002,    0
    subsprite OAM_SIZE_8x8,    -16,  -21,  684,    0
  FileD3EA_Obj_318:
    subsprite OAM_SIZE_16x16,    4,  -38,  838,    0
    subsprite OAM_SIZE_8x16,     8,  -48, 1634,    0
    subsprite OAM_SIZE_16x32,   -8,  -48,  840,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  870,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  852,    0
    subsprite OAM_SIZE_16x16,    3,  -28,  838,    0
  FileD3EA_Obj_324:
    subsprite OAM_SIZE_16x32,   -2,  -42,  778,    0
    subsprite OAM_SIZE_8x32,     8,  -48,  910,    0
    subsprite OAM_SIZE_16x32,   -8,  -48,  846,    0
    subsprite OAM_SIZE_32x16,   -8,  -16,  964,    0
    subsprite OAM_SIZE_32x8,    -8,    0,  890,    0
    subsprite OAM_SIZE_16x32,    8,  -32,  778,    0
  FileD3EA_Obj_330:
    subsprite OAM_SIZE_32x32,  -16,  -32,  960,    0
    subsprite OAM_SIZE_16x16,   -8,  -48, 1000,    0
    subsprite OAM_SIZE_16x32,  -20,  -33,  780,    0
    subsprite OAM_SIZE_16x32,    5,  -33,  780,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,    0,   63,    0
    subsprite OAM_SIZE_8x8,     -8,    0,   63,    0
  FileD3EA_Obj_336:
    subsprite OAM_SIZE_16x16,   -8,  -48,  868,    0
    subsprite OAM_SIZE_32x32,  -16,  -32,  772,    0
    subsprite OAM_SIZE_8x8,     -9,    0,   63,    0
    subsprite OAM_SIZE_8x8,      4,    0,   63,    0
  FileD3EA_Obj_340:
    subsprite OAM_SIZE_32x32,  -16,  -32,  899,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  836,    0
    subsprite OAM_SIZE_32x16,  -16,  -48,  967,    0
    subsprite OAM_SIZE_8x8,    -16,  -21,  684,    0
  FileD3EA_Obj_344:
    subsprite OAM_SIZE_16x32,   -8,  -48,  840,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  870,    0
    subsprite OAM_SIZE_8x16,     8,  -48, 1634,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  852,    0
  FileD3EA_Obj_348:
    subsprite OAM_SIZE_16x32,   -8,  -48,  846,    0
    subsprite OAM_SIZE_8x32,     8,  -48,  910,    0
    subsprite OAM_SIZE_32x16,   -8,  -16,  964,    0
    subsprite OAM_SIZE_32x8,    -8,    0,  890,    0
  FileD3EA_Obj_352:
    subsprite OAM_SIZE_32x32,  -16,  -32,  960,    0
    subsprite OAM_SIZE_16x16,   -8,  -48, 1000,    0
    subsprite OAM_SIZE_8x8,     -8,    0,   63,    0
    subsprite OAM_SIZE_8x8,      3,    0,   63,    0
  FileD3EA_Obj_356:
    subsprite OAM_SIZE_32x32,   -8,  -40,  896,    0
    subsprite OAM_SIZE_16x32,   -6,  -49, 1351,    0
    subsprite OAM_SIZE_16x32,    6,  -51,  834,    0
    subsprite OAM_SIZE_16x32,   -8,  -43,  834,    0
    subsprite OAM_SIZE_8x8,     -3,  -20, 1164,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1088,    0
    subsprite OAM_SIZE_8x8,      8,   -8, 1090,    0
    subsprite OAM_SIZE_8x8,     16,  -27,  276,    0
  FileD3EA_Obj_364:
    subsprite OAM_SIZE_16x32,  -12,  -40, 1140,    0
    subsprite OAM_SIZE_32x32,  -31,  -45, 1188,    0, yflip=1
    subsprite OAM_SIZE_32x32,  -16,  -40, 1031,    0
    subsprite OAM_SIZE_16x8,     0,  -48, 1092,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1094,    0
    subsprite OAM_SIZE_8x8,      2,  -35, 1035,    0
    subsprite OAM_SIZE_32x32,  -19,  -58, 1188,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -45, 1960,    0
    subsprite OAM_SIZE_8x8,     -9,  -35, 1165,    0
    subsprite OAM_SIZE_8x8,     -3,  -32, 1035,    0
  FileD3EA_Obj_374:
    subsprite OAM_SIZE_32x32,  -41,  -43, 1184,    0, yflip=1
    subsprite OAM_SIZE_32x32,  -25,  -56, 1184,    0, yflip=1
    subsprite OAM_SIZE_16x32,  -16,  -39, 1140,    0
    subsprite OAM_SIZE_32x32,  -16,  -48, 1196,    0
    subsprite OAM_SIZE_8x16,   -24,  -40, 1100,    0
    subsprite OAM_SIZE_16x8,    -8,  -56, 1108,    0
    subsprite OAM_SIZE_32x16,  -16,  -16, 1096,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1260,    0
    subsprite OAM_SIZE_8x8,      2,  -39, 1134,    0
    subsprite OAM_SIZE_16x16,  -10,  -47, 1262,    0
    subsprite OAM_SIZE_8x8,     -6,  -34, 1035,    0
  FileD3EA_Obj_385:
    subsprite OAM_SIZE_32x16,  -19,  -39, 1128,    0
    subsprite OAM_SIZE_16x32,    4,  -63, 1194,    0
    subsprite OAM_SIZE_32x16,  -34,  -27, 1160,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1036,    0
    subsprite OAM_SIZE_8x16,   -16,  -24, 1101,    0
    subsprite OAM_SIZE_16x16,    8,  -48, 1102,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1276,    0
    subsprite OAM_SIZE_8x8,      8,  -27, 1035,    0
    subsprite OAM_SIZE_16x32,   -1,  -39, 1142,    0
    subsprite OAM_SIZE_8x8,      0,  -26, 1051,    0
  FileD3EA_Obj_395:
    subsprite OAM_SIZE_32x16,  -16,  -37, 1128,    0, yflip=1
    subsprite OAM_SIZE_16x32,   -4,  -55, 1140,    0, yflip=1
    subsprite OAM_SIZE_32x32,   -8,  -32, 1480,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 1135,    0
    subsprite OAM_SIZE_8x16,    24,  -24, 1067,    0
    subsprite OAM_SIZE_16x32,    1,  -36, 1142,    0
    subsprite OAM_SIZE_8x8,      3,  -22, 1035,    0
  FileD3EA_Obj_402:
    subsprite OAM_SIZE_16x32,   -4,  -41, 1140,    0
    subsprite OAM_SIZE_32x16,  -15,  -40, 1128,    0
    subsprite OAM_SIZE_32x32,   -8,  -32,  448,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1150,    0
    subsprite OAM_SIZE_16x32,    0,  -42, 1351,    0
  FileD3EA_Obj_407:
    subsprite OAM_SIZE_16x32,   -4,  -40, 1140,    0
    subsprite OAM_SIZE_32x16,  -15,  -35, 1128,    0, yflip=1
    subsprite OAM_SIZE_32x32,   -8,  -32,  448,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1150,    0
    subsprite OAM_SIZE_16x32,    0,  -42, 1351,    0
  FileD3EA_Obj_412:
    subsprite OAM_SIZE_16x32,   -4,  -39, 1140,    0
    subsprite OAM_SIZE_32x16,  -13,  -32, 1128,    0, yflip=1
    subsprite OAM_SIZE_32x32,   -8,  -32,  448,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1150,    0
    subsprite OAM_SIZE_16x32,    0,  -42, 1351,    0
  FileD3EA_Obj_417:
    subsprite OAM_SIZE_16x32,   -4,  -38, 1140,    0
    subsprite OAM_SIZE_32x16,  -12,  -35, 1128,    0
    subsprite OAM_SIZE_32x32,   -8,  -32,  448,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1150,    0
    subsprite OAM_SIZE_16x32,    0,  -42, 1351,    0
  FileD3EA_Obj_422:
    subsprite OAM_SIZE_16x32,   -4,  -38, 1140,    0
    subsprite OAM_SIZE_32x32,   -8,  -32,  448,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1150,    0
    subsprite OAM_SIZE_16x32,    0,  -42, 1351,    0
  FileD3EA_Obj_426:
    subsprite OAM_SIZE_32x32,   -8,  -40,  896,    0
    subsprite OAM_SIZE_16x32,   -6,  -49, 1351,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1088,    0
    subsprite OAM_SIZE_8x8,      8,   -8, 1090,    0
    subsprite OAM_SIZE_8x8,    -12,  -31,  124,    0
    subsprite OAM_SIZE_8x8,     16,  -27,  276,    0
  FileD3EA_Obj_432:
    subsprite OAM_SIZE_32x32,   -8,  -40,  896,    0
    subsprite OAM_SIZE_16x32,   -6,  -49, 1351,    0
    subsprite OAM_SIZE_16x32,    6,  -51,  834,    0
    subsprite OAM_SIZE_16x32,   -8,  -43,  834,    0
    subsprite OAM_SIZE_8x8,     -3,  -20, 1164,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1088,    0
    subsprite OAM_SIZE_8x8,      8,   -8, 1090,    0
    subsprite OAM_SIZE_8x8,     16,  -27,  276,    0
  FileD3EA_Obj_440:
    subsprite OAM_SIZE_16x32,  -12,  -40, 1140,    0
    subsprite OAM_SIZE_32x32,  -31,  -45, 1188,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,   -8, 1094,    0
    subsprite OAM_SIZE_16x8,     0,  -48, 1092,    0
    subsprite OAM_SIZE_32x32,  -16,  -40, 1031,    0
    subsprite OAM_SIZE_32x32,  -19,  -58, 1188,    0, yflip=1
    subsprite OAM_SIZE_8x8,      2,  -35, 1035,    0
    subsprite OAM_SIZE_16x16,   -8,  -45, 1960,    0
    subsprite OAM_SIZE_8x8,     -9,  -35, 1165,    0
    subsprite OAM_SIZE_8x8,     -3,  -32, 1035,    0
  FileD3EA_Obj_450:
    subsprite OAM_SIZE_32x16,  -19,  -39, 1128,    0
    subsprite OAM_SIZE_32x32,  -11,  -59,  330,    0
    subsprite OAM_SIZE_32x32,  -29,  -42,  330,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1036,    0
    subsprite OAM_SIZE_8x16,   -16,  -24, 1101,    0
    subsprite OAM_SIZE_16x16,    8,  -48, 1102,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1276,    0
    subsprite OAM_SIZE_8x8,      8,  -27, 1035,    0
    subsprite OAM_SIZE_16x32,   -1,  -39, 1142,    0
    subsprite OAM_SIZE_8x8,      0,  -26, 1051,    0
  FileD3EA_Obj_460:
    subsprite OAM_SIZE_32x16,  -13,  -32, 1128,    0
    subsprite OAM_SIZE_32x32,   17,  -20, 1028,    0
    subsprite OAM_SIZE_32x32,   10,  -13,  320,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1480,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 1135,    0
    subsprite OAM_SIZE_8x16,    24,  -24, 1067,    0
    subsprite OAM_SIZE_16x32,    1,  -36, 1142,    0
    subsprite OAM_SIZE_8x8,      5,  -24, 1134,    0
    subsprite OAM_SIZE_64x32,  -19,  -54, 1920,    3
    subsprite OAM_SIZE_32x32,   13,  -22, 1984,    3
    subsprite OAM_SIZE_8x8,      5,  -22, 1732,    3
    subsprite OAM_SIZE_16x8,    21,   10, 1990,    3
  FileD3EA_Obj_472:
    subsprite OAM_SIZE_16x32,   -5,  -35, 1140,    0
    subsprite OAM_SIZE_32x16,  -12,  -31, 1128,    0
    subsprite OAM_SIZE_32x32,   18,  -19, 1028,    0
    subsprite OAM_SIZE_32x32,   11,  -12,  320,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 1135,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1480,    0
    subsprite OAM_SIZE_8x16,    24,  -24, 1067,    0
    subsprite OAM_SIZE_16x32,    1,  -36, 1142,    0
    subsprite OAM_SIZE_8x8,      3,  -23, 1035,    0
  FileD3EA_Obj_481:
    subsprite OAM_SIZE_16x32,   -4,  -36, 1140,    0
    subsprite OAM_SIZE_32x32,   18,  -19, 1028,    0
    subsprite OAM_SIZE_32x32,   11,  -12,  320,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 1135,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1480,    0
    subsprite OAM_SIZE_8x16,    24,  -24, 1067,    0
    subsprite OAM_SIZE_16x32,    1,  -36, 1142,    0
    subsprite OAM_SIZE_8x8,      4,  -22, 1051,    0, yflip=1
  FileD3EA_Obj_489:
    subsprite OAM_SIZE_32x32,   18,  -19, 1028,    0
    subsprite OAM_SIZE_32x32,   11,  -12,  320,    0
    subsprite OAM_SIZE_16x32,   -4,  -35, 1140,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 1135,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1480,    0
    subsprite OAM_SIZE_8x16,    24,  -24, 1067,    0
    subsprite OAM_SIZE_16x32,    1,  -36, 1142,    0
    subsprite OAM_SIZE_8x8,      4,  -22, 1051,    0, yflip=1
  FileD3EA_Obj_497:
    subsprite OAM_SIZE_16x32,   -5,  -56,  832,    0
    subsprite OAM_SIZE_16x32,    7,  -48,  832,    0
    subsprite OAM_SIZE_32x32,   -8,  -40, 1280,    0
    subsprite OAM_SIZE_32x16,   -8,   -8, 1376,    0
    subsprite OAM_SIZE_16x16,   -8,  -39, 1254,    0
    subsprite OAM_SIZE_16x16,   -6,  -46, 1250,    0
  FileD3EA_Obj_503:
    subsprite OAM_SIZE_32x32,   -8,  -48, 1284,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1422,    0
    subsprite OAM_SIZE_32x16,  -23,  -52,  996,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -39, 1254,    0
    subsprite OAM_SIZE_16x16,   -7,  -46, 1252,    0
    subsprite OAM_SIZE_32x16,  -13,  -43,  996,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,    5,  -39, 1256,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1385,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 1359,    0
  FileD3EA_Obj_512:
    subsprite OAM_SIZE_32x32,  -40,  -52,  826,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -16,  -40, 1288,    0
    subsprite OAM_SIZE_32x16,  -24,  -56, 1344,    0
    subsprite OAM_SIZE_8x8,    -24,  -40,  303,    0
    subsprite OAM_SIZE_16x32,  -15,  -41, 1140,    0
    subsprite OAM_SIZE_16x16,  -11,  -47, 1252,    0
    subsprite OAM_SIZE_32x32,  -29,  -36,  826,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -35, 1258,    0
    subsprite OAM_SIZE_16x16,    0,   -8, 1354,    0
    subsprite OAM_SIZE_8x8,     -8,   -8, 1353,    0
  FileD3EA_Obj_522:
    subsprite OAM_SIZE_32x32,  -20,  -67,  264,    0, yflip=1
    subsprite OAM_SIZE_32x32,   -8,  -48, 1292,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1420,    0
    subsprite OAM_SIZE_8x16,    24,  -40, 1391,    0
    subsprite OAM_SIZE_32x8,    13,  -35, 1180,    0
    subsprite OAM_SIZE_32x16,   -7,  -39,  168,    0
    subsprite OAM_SIZE_32x8,    -7,  -47,  299,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1356,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 1358,    0
  FileD3EA_Obj_531:
    subsprite OAM_SIZE_32x32,   -8,  -32, 1408,    0
    subsprite OAM_SIZE_32x16,    0,  -48, 1448,    0
    subsprite OAM_SIZE_8x8,     24,  -32,  319,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1166,    0
    subsprite OAM_SIZE_32x16,   -6,  -37,  137,    0
    subsprite OAM_SIZE_32x8,    -6,  -45,  128,    0
  FileD3EA_Obj_537:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1412,    0
    subsprite OAM_SIZE_32x16,  -13,  -43, 1128,    0
    subsprite OAM_SIZE_16x16,   -4,  -41, 1632,    0
    subsprite OAM_SIZE_16x16,    2,  -46, 1248,    0
    subsprite OAM_SIZE_8x8,      6,  -33,  124,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1389,    0
    subsprite OAM_SIZE_8x16,     8,   -8, 1635,    0
  FileD3EA_Obj_544:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1412,    0
    subsprite OAM_SIZE_16x16,   -5,  -41, 1632,    0
    subsprite OAM_SIZE_16x32,   -3,  -44, 1140,    0
    subsprite OAM_SIZE_16x16,    2,  -46, 1248,    0
    subsprite OAM_SIZE_8x8,      6,  -33,  124,    0
    subsprite OAM_SIZE_8x16,     8,   -8, 1635,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1389,    0
  FileD3EA_Obj_551:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1412,    0
    subsprite OAM_SIZE_16x16,   -5,  -39, 1632,    0
    subsprite OAM_SIZE_16x32,   -2,  -43, 1140,    0
    subsprite OAM_SIZE_16x16,    2,  -46, 1248,    0
    subsprite OAM_SIZE_8x8,      6,  -33,  124,    0
    subsprite OAM_SIZE_8x16,     8,   -8, 1635,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1389,    0
  FileD3EA_Obj_558:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1412,    0
    subsprite OAM_SIZE_16x32,   -1,  -44, 1140,    0
    subsprite OAM_SIZE_16x16,   -3,  -39, 1632,    0
    subsprite OAM_SIZE_16x16,    2,  -46, 1248,    0
    subsprite OAM_SIZE_8x8,      6,  -33,  124,    0
    subsprite OAM_SIZE_8x16,     8,   -8, 1635,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1389,    0
  FileD3EA_Obj_565:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1412,    0
    subsprite OAM_SIZE_16x16,   -3,  -37, 1254,    0, xflip=1
    subsprite OAM_SIZE_16x32,   -1,  -45, 1140,    0
    subsprite OAM_SIZE_16x16,    2,  -46, 1248,    0
    subsprite OAM_SIZE_8x8,      6,  -33,  124,    0
    subsprite OAM_SIZE_8x16,     8,   -8, 1635,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1389,    0
  FileD3EA_Obj_572:
    subsprite OAM_SIZE_32x16,   -8,   -8, 1376,    0
    subsprite OAM_SIZE_32x32,   -8,  -40, 1280,    0
    subsprite OAM_SIZE_16x16,   -8,  -39, 1254,    0
    subsprite OAM_SIZE_16x16,   -6,  -46, 1250,    0
  FileD3EA_Obj_576:
    subsprite OAM_SIZE_16x32,    7,  -48,  832,    0
    subsprite OAM_SIZE_16x32,   -5,  -56,  832,    0
    subsprite OAM_SIZE_32x16,   -8,   -8, 1376,    0
    subsprite OAM_SIZE_32x32,   -8,  -40, 1280,    0
    subsprite OAM_SIZE_16x16,   -8,  -39, 1254,    0
    subsprite OAM_SIZE_16x16,   -6,  -46, 1250,    0
  FileD3EA_Obj_582:
    subsprite OAM_SIZE_32x32,   -8,  -48, 1284,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1422,    0
    subsprite OAM_SIZE_32x16,  -23,  -52,  996,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -39, 1254,    0
    subsprite OAM_SIZE_16x16,   -7,  -46, 1252,    0
    subsprite OAM_SIZE_32x16,  -13,  -43,  996,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,    5,  -39, 1256,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 1359,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1385,    0
  FileD3EA_Obj_591:
    subsprite OAM_SIZE_32x32,   -8,  -48, 1292,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1420,    0
    subsprite OAM_SIZE_8x16,    24,  -40, 1391,    0
    subsprite OAM_SIZE_16x32,   -9,  -65, 1136,    0
    subsprite OAM_SIZE_32x16,   -7,  -39,  168,    0
    subsprite OAM_SIZE_32x8,    -7,  -47,  299,    0
    subsprite OAM_SIZE_16x32,    8,  -55, 1136,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 1358,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1356,    0
  FileD3EA_Obj_600:
    subsprite OAM_SIZE_32x32,   10,  -70, 1604,    0
    subsprite OAM_SIZE_32x32,   18,  -64, 1484,    0
    subsprite OAM_SIZE_32x16,    0,  -48, 1448,    0
    subsprite OAM_SIZE_8x8,     24,  -32,  319,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1408,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1166,    0
    subsprite OAM_SIZE_32x16,   -6,  -37,  137,    0
    subsprite OAM_SIZE_32x8,    -6,  -45,  128,    0
    subsprite OAM_SIZE_32x16,   -5,  -69, 1860,    3
    subsprite OAM_SIZE_16x32,   27,  -69, 1988,    3
    subsprite OAM_SIZE_16x8,    11,  -53, 2006,    3
  FileD3EA_Obj_611:
    subsprite OAM_SIZE_32x32,   11,  -71, 1604,    0
    subsprite OAM_SIZE_32x32,   19,  -65, 1484,    0
    subsprite OAM_SIZE_32x16,    0,  -48, 1448,    0
    subsprite OAM_SIZE_8x8,     24,  -32,  319,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1408,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1166,    0
    subsprite OAM_SIZE_32x16,  -10,  -40, 1128,    0
    subsprite OAM_SIZE_16x16,    0,  -38, 1632,    0
    subsprite OAM_SIZE_16x16,    4,  -45, 1250,    0
  FileD3EA_Obj_620:
    subsprite OAM_SIZE_32x32,   11,  -71, 1604,    0
    subsprite OAM_SIZE_32x32,   19,  -65, 1484,    0
    subsprite OAM_SIZE_32x16,    0,  -48, 1448,    0
    subsprite OAM_SIZE_8x8,     24,  -32,  319,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1408,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1166,    0
    subsprite OAM_SIZE_32x16,   -9,  -39, 1128,    0
    subsprite OAM_SIZE_16x16,    1,  -39, 1632,    0
    subsprite OAM_SIZE_16x16,    4,  -45, 1250,    0
  FileD3EA_Obj_629:
    subsprite OAM_SIZE_32x32,   19,  -65, 1484,    0
    subsprite OAM_SIZE_32x32,   11,  -71, 1604,    0
    subsprite OAM_SIZE_32x16,    0,  -48, 1448,    0
    subsprite OAM_SIZE_8x8,     24,  -32,  319,    0
    subsprite OAM_SIZE_32x32,   -8,  -32, 1408,    0
    subsprite OAM_SIZE_16x8,     0,    0, 1166,    0
    subsprite OAM_SIZE_16x32,   -3,  -38, 1140,    0
    subsprite OAM_SIZE_16x16,    1,  -37, 1254,    0
    subsprite OAM_SIZE_16x16,    4,  -45, 1250,    0
  FileD3EA_Obj_638:
    subsprite OAM_SIZE_32x32,  -16,  -40, 1024,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,  231,    0
    subsprite OAM_SIZE_16x16,    0,   -8,  202,    0
    subsprite OAM_SIZE_8x16,    -8,   -8,  201,    0
  FileD3EA_Obj_642:
    subsprite OAM_SIZE_32x16,    5,  -16, 1601,    0
    subsprite OAM_SIZE_32x32,  -16,  -40, 1544,    0
    subsprite OAM_SIZE_32x8,   -16,  -48,  247,    0
    subsprite OAM_SIZE_32x16,   -8,   -8, 1376,    0
  FileD3EA_Obj_646:
    subsprite OAM_SIZE_32x32,  -16,  -32, 1472,    0
    subsprite OAM_SIZE_32x16,  -16,  -48, 1347,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  836,    0
  FileD3EA_Obj_649:
    subsprite OAM_SIZE_32x32,   -5,  -35,  264,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -32, 1476,    0
    subsprite OAM_SIZE_32x16,  -16,  -48, 1379,    0
    subsprite OAM_SIZE_16x8,    -8,    0, 1540,    0
  FileD3EA_Obj_653:
    subsprite OAM_SIZE_16x32,    0,  -35, 1610,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 1609,    0
    subsprite OAM_SIZE_8x8,    -16,  -11, 1551,    0
    subsprite OAM_SIZE_32x8,   -16,   -3,   64,    0
    subsprite OAM_SIZE_16x16,  -13,  -32, 1580,    0
    subsprite OAM_SIZE_16x32,   -8,  -48, 1556,    0
  FileD3EA_Obj_659:
    subsprite OAM_SIZE_16x32,    0,  -35, 1610,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 1609,    0
    subsprite OAM_SIZE_8x8,    -16,  -11, 1551,    0
    subsprite OAM_SIZE_32x8,   -16,   -3,   64,    0
    subsprite OAM_SIZE_16x16,  -13,  -32, 1582,    0
    subsprite OAM_SIZE_16x32,   -8,  -48, 1556,    0
  FileD3EA_Obj_665:
    subsprite OAM_SIZE_16x32,    0,  -35, 1610,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 1609,    0
    subsprite OAM_SIZE_8x8,    -16,  -11, 1551,    0
    subsprite OAM_SIZE_32x8,   -16,   -3,   64,    0
    subsprite OAM_SIZE_16x32,  -15,  -50, 1612,    0
    subsprite OAM_SIZE_16x32,   -8,  -49, 1436,    0
    subsprite OAM_SIZE_16x16,  -15,  -50, 1612,    0
  FileD3EA_Obj_672:
    subsprite OAM_SIZE_16x32,    0,  -35, 1610,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 1609,    0
    subsprite OAM_SIZE_8x8,    -16,  -11, 1551,    0
    subsprite OAM_SIZE_32x8,   -16,   -3,   64,    0
    subsprite OAM_SIZE_16x32,  -15,  -50, 1614,    0
    subsprite OAM_SIZE_16x32,   -7,  -49, 1438,    0
    subsprite OAM_SIZE_16x16,  -15,  -50, 1614,    0
  FileD3EA_Obj_679:
    subsprite OAM_SIZE_16x8,   -10,  -52, 1542,    0
    subsprite OAM_SIZE_16x16,   -2,  -48, 1674,    0
    subsprite OAM_SIZE_16x32,    6,  -44, 1672,    0
    subsprite OAM_SIZE_32x32,  -18,  -44, 1668,    0
    subsprite OAM_SIZE_16x16,   -2,  -12, 1734,    0
    subsprite OAM_SIZE_8x8,    -10,  -12, 1733,    0
  FileD3EA_Obj_685:
    subsprite OAM_SIZE_16x32,   16,  -42, 1029,    0
    subsprite OAM_SIZE_32x32,  -16,  -48, 1664,    0
    subsprite OAM_SIZE_32x16,  -16,  -16, 1728,    0
    subsprite OAM_SIZE_16x16,    8,  -40, 1764,    0
    subsprite OAM_SIZE_32x16,   -8,  -32, 1760,    0
  FileD3EA_Obj_690:
    subsprite OAM_SIZE_16x8,   -10,  -52, 1542,    0
    subsprite OAM_SIZE_32x32,  -18,  -44, 1668,    0
    subsprite OAM_SIZE_16x16,   -2,  -52, 1706,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 1676,    0
    subsprite OAM_SIZE_16x16,   -2,  -12, 1734,    0
    subsprite OAM_SIZE_8x8,    -10,  -12, 1733,    0
  FileD3EA_Obj_696:
    subsprite OAM_SIZE_32x32,  -16,  -48, 1664,    0
    subsprite OAM_SIZE_32x16,  -16,  -16, 1728,    0
    subsprite OAM_SIZE_16x16,    8,  -40, 1766,    0
  FileD3EA_Obj_699:
    subsprite OAM_SIZE_32x32,  -16,  -40, 1736,    0
    subsprite OAM_SIZE_32x16,  -16,   -8, 1708,    0
  FileD3EA_Obj_701:
    subsprite OAM_SIZE_32x32,   -8,  -40, 1740,    0
    subsprite OAM_SIZE_32x8,    -8,  -48,  148,    0
    subsprite OAM_SIZE_16x16,   -8,   -8, 1387,    0
    subsprite OAM_SIZE_8x8,      8,   -8,  251,    0
  FileD3EA_Obj_705:
    subsprite OAM_SIZE_32x32,   -8,  -48,  456,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1678,    0
    subsprite OAM_SIZE_16x8,    -8,    0,  114,    0
    subsprite OAM_SIZE_16x8,     8,  -56, 1120,    0
    subsprite OAM_SIZE_8x8,      1,  -18,  684,    0
  FileD3EA_Obj_710:
    subsprite OAM_SIZE_32x32,   -8,  -48,  460,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  583,    0
    subsprite OAM_SIZE_8x16,     8,  -16,  200,    0
    subsprite OAM_SIZE_16x8,     0,    0,  700,    0
    subsprite OAM_SIZE_16x8,     0,  -56,  132,    0
    subsprite OAM_SIZE_8x8,     10,  -49,  124,    0
  FileD3EA_Obj_716:
    subsprite OAM_SIZE_32x32,  -16,  -56, 1792,    0
    subsprite OAM_SIZE_32x16,  -16,  -24,    0,    0
    subsprite OAM_SIZE_32x8,   -16,   -8,  768,    0
  FileD3EA_Obj_719:
    subsprite OAM_SIZE_16x8,   -10,  -52, 1542,    0
    subsprite OAM_SIZE_32x32,  -18,  -44, 1668,    0
    subsprite OAM_SIZE_16x16,   -2,  -52, 1706,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 1676,    0
    subsprite OAM_SIZE_16x16,   -2,  -12, 1734,    0
    subsprite OAM_SIZE_8x8,    -10,  -12, 1733,    0
  FileD3EA_Obj_725:
    subsprite OAM_SIZE_16x32,   -5,  -28, 1192,    0
    subsprite OAM_SIZE_8x32,    11,  -28, 1608,    0
    subsprite OAM_SIZE_32x32,  -13,  -45, 1856,    0
  FileD3EA_Obj_728:
    subsprite OAM_SIZE_16x32,   -5,  -28, 1192,    0
    subsprite OAM_SIZE_8x32,    11,  -28, 1608,    0
    subsprite OAM_SIZE_16x32,   -4,  -41, 1930,    0
    subsprite OAM_SIZE_8x32,    12,  -41, 1932,    0
    subsprite OAM_SIZE_8x8,     12,   -9,  675,    0
  FileD3EA_Obj_733:
    subsprite OAM_SIZE_16x32,   -5,  -28, 1192,    0
    subsprite OAM_SIZE_8x32,    11,  -28, 1608,    0
    subsprite OAM_SIZE_16x32,   -4,  -40, 1933,    0
    subsprite OAM_SIZE_8x32,    12,  -40, 1935,    0
    subsprite OAM_SIZE_8x8,     12,   -8,  144,    0
  FileD3EA_Obj_738:
    subsprite OAM_SIZE_32x32,  -16,  -48, 1664,    0
    subsprite OAM_SIZE_32x16,  -16,  -16, 1728,    0
    subsprite OAM_SIZE_16x16,    8,  -40, 1766,    0
  FileD3EA_Obj_741:
    subsprite OAM_SIZE_32x16,  -10,  -19, 1416,    0
    subsprite OAM_SIZE_32x8,   -10,   -3, 1564,    0
    subsprite OAM_SIZE_32x32,  -11,  -43, 1796,    0
  FileD3EA_Obj_744:
    subsprite OAM_SIZE_32x8,   -10,   -3, 1564,    0
    subsprite OAM_SIZE_32x16,  -10,  -19, 1416,    0
    subsprite OAM_SIZE_32x32,  -12,  -32, 1800,    0
  FileD3EA_Obj_747:
    subsprite OAM_SIZE_32x8,   -10,   -3, 1564,    0
    subsprite OAM_SIZE_32x16,  -10,  -19, 1416,    0
    subsprite OAM_SIZE_32x32,  -11,  -34, 1804,    0
    subsprite OAM_SIZE_8x8,     -3,   -2, 1369,    0
  FileD3EA_Obj_751:
    subsprite OAM_SIZE_16x32,   -7,  -37, 1140,    0
    subsprite OAM_SIZE_32x8,   -10,   -3, 1564,    0
    subsprite OAM_SIZE_32x16,  -10,  -19, 1416,    0
    subsprite OAM_SIZE_32x32,  -11,  -31,    8,    0
    subsprite OAM_SIZE_8x16,     4,  -30,  935,    0
    subsprite OAM_SIZE_16x16,   -4,  -36, 1960,    0
    subsprite OAM_SIZE_8x8,      0,  -22, 1035,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,  -26, 1144,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -4,  -28, 1144,    0, xflip=1, yflip=1
  FileD3EA_Obj_760:
    subsprite OAM_SIZE_32x32,   -7,  -36, 1993,    0
    subsprite OAM_SIZE_16x8,    -7,   -4,  554,    0
    subsprite OAM_SIZE_8x8,      2,  -32, 1144,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -4,  -34, 1144,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -4,  -42, 1960,    0
    subsprite OAM_SIZE_8x8,      0,  -28, 1035,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -10,  -30,  350,    0
  FileD3EA_Obj_767:
    subsprite OAM_SIZE_32x32,  -16,  -66,  330,    0
    subsprite OAM_SIZE_32x32,    3,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_8x16,     4,  -47, 1864,    0
    subsprite OAM_SIZE_32x32,  -12,  -36, 1894,    0
    subsprite OAM_SIZE_16x16,   -7,  -45, 1892,    0
    subsprite OAM_SIZE_8x8,      3,  -35,  136,    0
    subsprite OAM_SIZE_16x8,    -8,  -30,  334,    0
    subsprite OAM_SIZE_16x8,    -8,  -31,  334,    0
  FileD3EA_Obj_776:
    subsprite OAM_SIZE_32x32,  -14,  -65,  330,    0
    subsprite OAM_SIZE_32x32,    4,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_8x16,     6,  -46, 1864,    0
    subsprite OAM_SIZE_32x32,  -11,  -36, 1894,    0
    subsprite OAM_SIZE_16x16,   -5,  -45, 1892,    0
    subsprite OAM_SIZE_16x8,    -7,  -31,  334,    0
    subsprite OAM_SIZE_8x8,      4,  -35,  136,    0
  FileD3EA_Obj_784:
    subsprite OAM_SIZE_32x32,  -12,  -64,  330,    0
    subsprite OAM_SIZE_32x32,    5,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_8x16,     8,  -45, 1864,    0
    subsprite OAM_SIZE_32x32,  -10,  -36, 1894,    0
    subsprite OAM_SIZE_16x16,   -3,  -45, 1892,    0
    subsprite OAM_SIZE_16x8,    -6,  -32,  334,    0
    subsprite OAM_SIZE_8x8,      5,  -34,  136,    0
  FileD3EA_Obj_792:
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_32x32,  -10,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -11,  -35,  261,    0
    subsprite OAM_SIZE_16x32,  -13,  -31,  350,    0
    subsprite OAM_SIZE_32x32,  -10,  -45, 1865,    0
    subsprite OAM_SIZE_8x8,    -13,  -30,  189,    0
    subsprite OAM_SIZE_16x32,    1,  -61, 1194,    0, xflip=1
    subsprite OAM_SIZE_16x16,    4,  -41, 2022,    0
  FileD3EA_Obj_800:
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_32x32,   -9,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -10,  -35,  261,    0
    subsprite OAM_SIZE_16x32,  -12,  -31,  350,    0
    subsprite OAM_SIZE_32x32,   -8,  -45, 1865,    0
    subsprite OAM_SIZE_16x32,    3,  -60, 1194,    0, xflip=1
    subsprite OAM_SIZE_16x16,    6,  -40, 2022,    0
  FileD3EA_Obj_807:
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_32x32,   -8,  -30, 1188,    0, xflip=1
    subsprite OAM_SIZE_32x16,   -9,  -35,  261,    0
    subsprite OAM_SIZE_16x32,  -11,  -31,  350,    0
    subsprite OAM_SIZE_32x32,   -6,  -45, 1865,    0
    subsprite OAM_SIZE_16x32,    5,  -59, 1194,    0, xflip=1
    subsprite OAM_SIZE_16x16,    8,  -39, 2022,    0
  FileD3EA_Obj_814:
    subsprite OAM_SIZE_16x32,   -2,  -42,  778,    0
    subsprite OAM_SIZE_8x32,    -8,  -36, 1992,    0
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_32x16,  -11,  -36,  293,    0
    subsprite OAM_SIZE_16x16,   -7,  -38, 1254,    0
    subsprite OAM_SIZE_16x32,    1,  -34, 1558,    0
    subsprite OAM_SIZE_16x16,   -5,  -46, 1132,    0
    subsprite OAM_SIZE_16x32,    8,  -34,  778,    0
    subsprite OAM_SIZE_8x8,    -11,  -37,  189,    0
  FileD3EA_Obj_823:
    subsprite OAM_SIZE_16x32,   -2,  -42,  778,    0
    subsprite OAM_SIZE_8x32,    -8,  -36, 1992,    0
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_32x16,  -11,  -36,  293,    0
    subsprite OAM_SIZE_16x16,   -8,  -39, 1254,    0
    subsprite OAM_SIZE_16x32,    1,  -32, 1558,    0
    subsprite OAM_SIZE_16x16,   -6,  -46, 1250,    0
    subsprite OAM_SIZE_16x32,    8,  -32,  778,    0
  FileD3EA_Obj_831:
    subsprite OAM_SIZE_16x32,   -2,  -44,  778,    0
    subsprite OAM_SIZE_8x32,    -8,  -38, 1992,    0
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_32x16,  -11,  -36,  293,    0
    subsprite OAM_SIZE_16x16,   -9,  -39, 1254,    0
    subsprite OAM_SIZE_16x32,    1,  -32, 1558,    0
    subsprite OAM_SIZE_16x16,   -8,  -46,   32,    0
    subsprite OAM_SIZE_16x32,    8,  -32,  778,    0
    subsprite OAM_SIZE_8x8,      2,  -35,  136,    0
  FileD3EA_Obj_840:
    subsprite OAM_SIZE_16x32,   -2,  -44,  778,    0
    subsprite OAM_SIZE_8x32,    -8,  -38, 1992,    0
    subsprite OAM_SIZE_32x32,  -17,  -26, 1996,    0
    subsprite OAM_SIZE_32x16,  -11,  -36,  293,    0
    subsprite OAM_SIZE_16x16,   -8,  -40, 1254,    0
    subsprite OAM_SIZE_16x32,    1,  -34, 1558,    0
    subsprite OAM_SIZE_16x16,   -5,  -46, 1250,    0
    subsprite OAM_SIZE_16x32,    8,  -34,  778,    0
  FileD3EA_Obj_848:
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_16x32,    0,  -38, 1138,    0
    subsprite OAM_SIZE_32x16,  -10,  -35,  261,    0
    subsprite OAM_SIZE_8x16,     2,  -41,  935,    0
    subsprite OAM_SIZE_16x32,  -12,  -33,  350,    0
    subsprite OAM_SIZE_16x16,   -6,  -45,   96,    0
    subsprite OAM_SIZE_8x16,    -2,  -35,  935,    0
    subsprite OAM_SIZE_16x16,    9,  -36, 1002,    0
    subsprite OAM_SIZE_16x16,   -2,  -30, 1002,    0
  FileD3EA_Obj_857:
    subsprite OAM_SIZE_16x16,   -7,  -35, 1254,    0
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_16x32,    0,  -38, 1138,    0
    subsprite OAM_SIZE_32x16,  -10,  -35,  261,    0
    subsprite OAM_SIZE_8x16,     3,  -40,  935,    0
    subsprite OAM_SIZE_16x32,  -12,  -31,  350,    0
    subsprite OAM_SIZE_16x16,   -6,  -45,  678,    0
    subsprite OAM_SIZE_8x16,    -2,  -36,  935,    0
    subsprite OAM_SIZE_16x16,    9,  -36, 1002,    0
    subsprite OAM_SIZE_16x16,   -2,  -28, 1002,    0
  FileD3EA_Obj_867:
    subsprite OAM_SIZE_16x16,   -8,  -39, 1140,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_16x32,    0,  -40, 1138,    0
    subsprite OAM_SIZE_32x16,  -10,  -35,  261,    0
    subsprite OAM_SIZE_8x16,     3,  -39,  935,    0
    subsprite OAM_SIZE_16x32,  -12,  -31,  350,    0
    subsprite OAM_SIZE_16x16,   -4,  -45, 1106,    0
    subsprite OAM_SIZE_8x16,    -2,  -37,  935,    0
    subsprite OAM_SIZE_16x16,    9,  -38, 1002,    0
    subsprite OAM_SIZE_16x16,   -2,  -28, 1002,    0
  FileD3EA_Obj_877:
    subsprite OAM_SIZE_16x16,   -7,  -35, 1254,    0
    subsprite OAM_SIZE_32x32,  -15,  -27, 1868,    0
    subsprite OAM_SIZE_16x32,    0,  -40, 1138,    0
    subsprite OAM_SIZE_32x16,  -10,  -35,  261,    0
    subsprite OAM_SIZE_8x16,     3,  -40,  935,    0
    subsprite OAM_SIZE_16x32,  -12,  -33,  350,    0
    subsprite OAM_SIZE_16x16,   -5,  -45,  678,    0
    subsprite OAM_SIZE_8x16,    -1,  -36,  935,    0
    subsprite OAM_SIZE_16x16,    9,  -38, 1002,    0
    subsprite OAM_SIZE_16x16,   -2,  -30, 1002,    0

2:
FileD3EA_Cmds:
  FileD3EA_Cmd_0:
    animcmd    0,   4
    animcmd    1,   4
    animcmd    2,   4
    animcmd    3,   4
    animcmd    4,   4
    animcmd    5,   4
    animcmd    6,   4
    animcmd    7,   4
  FileD3EA_Cmd_8:
    animcmd    8,   4
    animcmd    9,   4
    animcmd   10,   4
    animcmd   11,   4
    animcmd   12,   4
    animcmd   13,   4
    animcmd   14,   4
    animcmd   15,   4
  FileD3EA_Cmd_16:
    animcmd   52,   1
  FileD3EA_Cmd_17:
    animcmd   51,   1
  FileD3EA_Cmd_18:
    animcmd   50,   1
  FileD3EA_Cmd_19:
    animcmd   49,   1
  FileD3EA_Cmd_20:
    animcmd   48,   1
  FileD3EA_Cmd_21:
    animcmd   57,   1
  FileD3EA_Cmd_22:
    animcmd   56,   1
  FileD3EA_Cmd_23:
    animcmd   55,   1
  FileD3EA_Cmd_24:
    animcmd   54,   1
  FileD3EA_Cmd_25:
    animcmd   53,   1
  FileD3EA_Cmd_26:
    animcmd   16,   6
    animcmd   17,   6
    animcmd   18,   6
    animcmd   19,   6
    animcmd   20,   6
    animcmd   21,   6
    animcmd   22,   6
    animcmd   23,   6
  FileD3EA_Cmd_34:
    animcmd   24,   6
    animcmd   25,   6
    animcmd   26,   6
    animcmd   27,   6
    animcmd   28,   6
    animcmd   29,   6
    animcmd   30,   6
    animcmd   31,   6
  FileD3EA_Cmd_42:
    animcmd   32,   6
    animcmd   33,   6
    animcmd   34,   6
    animcmd   35,   6
    animcmd   36,   6
    animcmd   37,   6
    animcmd   38,   6
    animcmd   39,   6
  FileD3EA_Cmd_50:
    animcmd   40,   6
    animcmd   41,   6
    animcmd   42,   6
    animcmd   43,   6
    animcmd   44,   6
    animcmd   45,   6
    animcmd   46,   6
    animcmd   47,   6
  FileD3EA_Cmd_58:
    animcmd   76,   5
    animcmd   77,   5
    animcmd   78,  16
    animcmd   79,   5
    animcmd   80,   5
    animcmd   81,   4
    animcmd   82,   2
    animcmd   83,   1
    animcmd   84,   1
    animcmd   85,  10
    animcmd   86,   5
    animcmd   56,  37
  FileD3EA_Cmd_70:
    animcmd   58,   5
    animcmd   59,   5
    animcmd   60,  16
    animcmd   61,   5
    animcmd   62,   5
    animcmd   63,   4
    animcmd   64,   2
    animcmd   65,   1
    animcmd   66,   1
    animcmd   67,  10
    animcmd   68,   5
    animcmd   54,  37
  FileD3EA_Cmd_82:
    animcmd   87,   5
    animcmd   88,   6
    animcmd   89,   5
    animcmd   90,   2
    animcmd   91,   2
    animcmd   92,   2
    animcmd   93,   6
    animcmd   87,   8
  FileD3EA_Cmd_90:
    animcmd   69,   5
    animcmd   70,   6
    animcmd   71,   5
    animcmd   72,   2
    animcmd   73,   2
    animcmd   74,   2
    animcmd   75,   6
    animcmd   69,   8
  FileD3EA_Cmd_98:
    animcmd   94,  15
    animcmd   95,   7
    animcmd   76,   7
  FileD3EA_Cmd_101:
    animcmd   96,  15
    animcmd   97,   7
    animcmd   58,   7
  FileD3EA_Cmd_104:
    animcmd   98,   8
    animcmd   99,   8
  FileD3EA_Cmd_106:
    animcmd  100,   4
    animcmd  101,  16
  FileD3EA_Cmd_108:
    animcmd  101,   1
  FileD3EA_Cmd_109:
    animcmd  102,   1
  FileD3EA_Cmd_110:
    animcmd  103,   1
  FileD3EA_Cmd_111:
    animcmd  104,   1
  FileD3EA_Cmd_112:
    animcmd  105,   1
  FileD3EA_Cmd_113:
    animcmd  110,   1
  FileD3EA_Cmd_114:
    animcmd  109,   1
  FileD3EA_Cmd_115:
    animcmd  108,   1
  FileD3EA_Cmd_116:
    animcmd  107,   1
  FileD3EA_Cmd_117:
    animcmd  106,   1
  FileD3EA_Cmd_118:
    animcmd  111,   8
    animcmd  112,  12
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
    animcmd  114,  37
    animcmd  113,  26
  FileD3EA_Cmd_138:
    animcmd  115,   8
    animcmd  116,  12
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
    animcmd  117,  37
    animcmd  118,  26
  FileD3EA_Cmd_158:
    animcmd  122,   9
    animcmd  123,  25
    animcmd  122,   9
    animcmd  121,  25
  FileD3EA_Cmd_162:
    animcmd  125,   9
    animcmd  126,  25
    animcmd  125,   9
    animcmd  124,  25
  FileD3EA_Cmd_166:
    animcmd  128,  13
    animcmd  129,  14
    animcmd  128,  13
    animcmd  127,  14
    animcmd  128,  13
    animcmd  130,  20
  FileD3EA_Cmd_172:
    animcmd  132,  13
    animcmd  133,  14
    animcmd  132,  13
    animcmd  131,  14
    animcmd  132,  13
    animcmd  134,  20
  FileD3EA_Cmd_178:
    animcmd  119,   1
  FileD3EA_Cmd_179:
    animcmd  120,   1

FileD3EA_Tiles:
  .incbin "data/sprite_main/shaian.4bpp"
