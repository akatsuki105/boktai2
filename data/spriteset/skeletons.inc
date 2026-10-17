FileAE52_Header:
  .2byte 247 @ palStart
  .2byte 424 @ metaspriteCount
  .2byte 144 @ animationCount
  .2byte 2627 @ subspriteCount
  .2byte 490 @ cmdCount
  .2byte 3328 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 8512 @ offsetToAnims
  .4byte 9664 @ offsetToSubsprites
  .4byte 30680 @ offsetToCmds
  .4byte 32640 @ offsetToTiles

FileAE52_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xBD16, FileAE52_Obj_0,     6,          -26,  -55,   17,   11
  pose 0x3D17, FileAE52_Obj_6,     6,          -48,  -65,   16,   15
  pose 0xBD46, FileAE52_Obj_12,    7,          -32,  -56,   15,    0
  pose 0xBD47, FileAE52_Obj_19,    7,          -31,  -54,   16,    0
  pose 0xBD48, FileAE52_Obj_26,    6,          -32,  -54,   15,    0
  pose 0xBD49, FileAE52_Obj_32,    6,          -44,  -56,   20,    8
  pose 0xBD4A, FileAE52_Obj_38,    6,          -44,  -56,   20,    8
  pose 0xBD4B, FileAE52_Obj_44,    6,          -44,  -56,   20,    8
  pose 0xBD4C, FileAE52_Obj_50,    7,          -44,  -56,   20,    8
  pose 0xBD4D, FileAE52_Obj_57,    6,          -44,  -56,   20,    8
  pose 0x3D47, FileAE52_Obj_63,    8,          -44,  -58,   20,    8
  pose 0x3D48, FileAE52_Obj_71,    9,          -30,  -56,   12,    0
  pose 0x3D49, FileAE52_Obj_80,    9,          -31,  -56,   19,    0
  pose 0x3D4A, FileAE52_Obj_89,    9,          -31,  -57,   12,    0
  pose 0x3D4B, FileAE52_Obj_98,    8,          -32,  -58,   11,    0
  pose 0x3D4C, FileAE52_Obj_106,   8,          -30,  -56,   12,    0
  pose 0x3D4D, FileAE52_Obj_114,   8,          -31,  -56,   19,    0
  pose 0x3D4E, FileAE52_Obj_122,   8,          -31,  -57,   11,    0
  pose 0xBBE6, FileAE52_Obj_130,   3,          -50,  -72,   14,    0
  pose 0xBBE7, FileAE52_Obj_133,   4,          -44,  -71,   20,    1
  pose 0xBBE8, FileAE52_Obj_137,   4,          -40,  -74,   24,    0
  pose 0xBBE9, FileAE52_Obj_141,   4,          -48,  -79,   32,    0
  pose 0xBBEA, FileAE52_Obj_145,   4,          -49,  -77,   15,    0
  pose 0xBBEB, FileAE52_Obj_149,   2,          -29,  -38,   11,    0
  pose 0x3BE7, FileAE52_Obj_151,   4,          -54,  -72,   18,    0
  pose 0x3BE8, FileAE52_Obj_155,   4,          -53,  -69,   19,    0
  pose 0x3BE9, FileAE52_Obj_159,   4,          -41,  -69,   23,    0
  pose 0x3BEA, FileAE52_Obj_163,   4,          -40,  -70,   24,   10
  pose 0x3BEB, FileAE52_Obj_167,   5,          -37,  -74,   35,    0
  pose 0x3BEC, FileAE52_Obj_172,   2,          -28,  -40,   12,    0
  pose 0xBC36, FileAE52_Obj_174,   2,          -46,  -71,   18,   25
  pose 0xBC37, FileAE52_Obj_176,   4,          -48,  -73,   16,   23
  pose 0xBC38, FileAE52_Obj_180,   2,          -50,  -71,   14,   25
  pose 0x3C37, FileAE52_Obj_182,   3,          -40,  -71,   24,    9
  pose 0x3C38, FileAE52_Obj_185,   3,          -42,  -71,   22,    9
  pose 0x3C39, FileAE52_Obj_188,   3,          -42,  -71,   22,    9
  pose 0x8727, FileAE52_Obj_191,   3,          -48,  -71,   16,   25
  pose 0x8747, FileAE52_Obj_194,   2,          -48,  -71,   16,   25
  pose 0x8767, FileAE52_Obj_196,   3,          -48,  -71,   16,   25
  pose 0xBC86, FileAE52_Obj_199,   7,          -32,  -57,   19,    0
  pose 0xBC87, FileAE52_Obj_206,   7,          -31,  -54,   21,    0
  pose 0xBC88, FileAE52_Obj_213,   6,          -31,  -56,   21,    0
  pose 0xBC89, FileAE52_Obj_219,   6,          -44,  -57,   20,    8
  pose 0xBC8A, FileAE52_Obj_225,   6,          -44,  -57,   20,    8
  pose 0xBC8B, FileAE52_Obj_231,   6,          -44,  -56,   21,    8
  pose 0xBC8C, FileAE52_Obj_237,   6,          -44,  -56,   21,    8
  pose 0xBC8D, FileAE52_Obj_243,   6,          -44,  -57,   20,    8
  pose 0x3C87, FileAE52_Obj_249,   8,          -44,  -59,   20,    8
  pose 0x3C88, FileAE52_Obj_257,   8,          -30,  -55,   18,    0
  pose 0x3C89, FileAE52_Obj_265,   9,          -30,  -57,   18,    0
  pose 0x3C8A, FileAE52_Obj_274,   9,          -31,  -59,   18,    0
  pose 0x3C8B, FileAE52_Obj_283,   8,          -31,  -59,   18,    0
  pose 0x3C8C, FileAE52_Obj_291,   7,          -30,  -55,   18,    0
  pose 0x3C8D, FileAE52_Obj_298,   8,          -30,  -57,   18,    0
  pose 0x3C8E, FileAE52_Obj_306,   8,          -31,  -59,   18,    0
  pose 0xBC76, FileAE52_Obj_314,   3,          -43,  -67,   21,   29
  pose 0xBC77, FileAE52_Obj_317,   3,          -43,  -62,   29,   18
  pose 0x3C77, FileAE52_Obj_320,   2,          -47,  -67,   17,   13
  pose 0x3C78, FileAE52_Obj_322,   2,          -46,  -62,   18,   18
  pose 0xBC06, FileAE52_Obj_324,   7,          -30,  -58,   20,    0
  pose 0xBC07, FileAE52_Obj_331,   7,          -30,  -57,   20,    0
  pose 0xBC08, FileAE52_Obj_338,   7,          -30,  -55,   20,    0
  pose 0x3C07, FileAE52_Obj_345,   9,          -30,  -55,   19,    0
  pose 0x3C08, FileAE52_Obj_354,   7,          -30,  -57,   19,    0
  pose 0x3C09, FileAE52_Obj_361,   8,          -30,  -55,   19,    0
  pose 0xBD06, FileAE52_Obj_369,   5,          -47,  -50,   23,   14
  pose 0xBD07, FileAE52_Obj_374,   2,          -41,  -60,   23,   36
  pose 0xBD08, FileAE52_Obj_376,   5,          -47,  -50,   17,   14
  pose 0x3D07, FileAE52_Obj_381,   8,          -31,  -48,   17,    4
  pose 0x3D08, FileAE52_Obj_389,   3,          -43,  -58,   21,   22
  pose 0x3D09, FileAE52_Obj_392,   8,          -31,  -51,   16,    0
  pose 0xBC16, FileAE52_Obj_400,   4,          -43,  -67,   21,   21
  pose 0x3C17, FileAE52_Obj_404,   3,          -50,  -69,   14,   11
  pose 0xB966, FileAE52_Obj_407,   2,          -22,  -23,   10,    9
  pose 0xBD67, FileAE52_Obj_409,   2,          -22,  -23,   10,    9
  pose 0xBD68, FileAE52_Obj_411,   2,          -25,  -23,   15,    9
  pose 0xBD69, FileAE52_Obj_413,   2,          -24,  -25,   16,    7
  pose 0xBD6A, FileAE52_Obj_415,   3,          -23,  -41,   17,    0
  pose 0xBD6B, FileAE52_Obj_418,   4,          -28,  -52,   20,    4
  pose 0xBD6C, FileAE52_Obj_422,   6,          -30,  -53,   18,    3
  pose 0xBD6D, FileAE52_Obj_428,   3,          -46,  -71,   18,    9
  pose 0xBD6E, FileAE52_Obj_431,   2,          -45,  -68,   19,   20
  pose 0xBD6F, FileAE52_Obj_433,   3,          -45,  -69,   19,   27
  pose 0x3D67, FileAE52_Obj_436,   2,          -25,  -28,    7,   20
  pose 0x3D68, FileAE52_Obj_438,   2,          -23,  -28,    9,   20
  pose 0x3D69, FileAE52_Obj_440,   3,          -25,  -31,    7,   17
  pose 0x3D6A, FileAE52_Obj_443,   3,          -24,  -32,    8,   16
  pose 0x3D6B, FileAE52_Obj_446,   2,          -22,  -43,   18,    0
  pose 0x3D6C, FileAE52_Obj_448,   3,          -27,  -50,   13,    6
  pose 0x3D6D, FileAE52_Obj_451,   4,          -28,  -49,   20,    7
  pose 0x3D6E, FileAE52_Obj_455,   2,          -46,  -67,   18,    5
  pose 0x3D6F, FileAE52_Obj_457,   1,          -49,  -64,   15,    0
  pose 0x3D70, FileAE52_Obj_458,   2,          -45,  -65,   19,    7
  pose 0xBCC6, FileAE52_Obj_460,   2,          -44,  -67,   20,   13
  pose 0xBCC7, FileAE52_Obj_462,   2,          -44,  -67,   20,   13
  pose 0xBCC8, FileAE52_Obj_464,   3,          -44,  -66,   20,   21
  pose 0xBCC9, FileAE52_Obj_467,   6,          -44,  -51,   20,   29
  pose 0xBCCA, FileAE52_Obj_473,   4,          -44,  -41,   20,   29
  pose 0x3CC7, FileAE52_Obj_477,   2,          -50,  -69,   14,   27
  pose 0x3CC8, FileAE52_Obj_479,   7,          -50,  -54,   14,   27
  pose 0x3CC9, FileAE52_Obj_486,   5,          -50,  -53,   14,   27
  pose 0x3CCA, FileAE52_Obj_491,   5,          -26,  -53,   14,   11
  pose 0x3CCB, FileAE52_Obj_496,   3,          -50,  -37,   14,   27
  pose 0xFD16, FileAE52_Obj_499,   8,          -30,  -55,   17,   25
  pose 0x7D17, FileAE52_Obj_507,   8,          -56,  -55,   12,   13
  pose 0xFD46, FileAE52_Obj_515,   8,          -32,  -56,   15,   24
  pose 0xFD47, FileAE52_Obj_523,   8,          -31,  -54,   16,   24
  pose 0xFD48, FileAE52_Obj_531,   8,          -32,  -54,   15,   24
  pose 0xFD49, FileAE52_Obj_539,   7,          -44,  -56,   20,   24
  pose 0xFD4A, FileAE52_Obj_546,   7,          -44,  -56,   20,   24
  pose 0xFD4B, FileAE52_Obj_553,   7,          -44,  -56,   20,   24
  pose 0xFD4C, FileAE52_Obj_560,   8,          -44,  -56,   20,   24
  pose 0xFD4D, FileAE52_Obj_568,   7,          -44,  -56,   20,   24
  pose 0x7D47, FileAE52_Obj_575,   8,          -57,  -58,   20,   11
  pose 0x7D48, FileAE52_Obj_583,   9,          -57,  -56,   12,   11
  pose 0x7D49, FileAE52_Obj_592,   9,          -59,  -56,   19,   10
  pose 0x7D4A, FileAE52_Obj_601,   9,          -60,  -57,   12,   10
  pose 0x7D4B, FileAE52_Obj_610,   8,          -60,  -58,   11,   10
  pose 0x7D4C, FileAE52_Obj_618,   8,          -57,  -56,   12,   13
  pose 0x7D4D, FileAE52_Obj_626,   8,          -55,  -56,   19,   12
  pose 0x7D4E, FileAE52_Obj_634,   8,          -55,  -57,   11,   11
  pose 0xFBE6, FileAE52_Obj_642,   4,          -50,  -72,   14,    0
  pose 0xFBE7, FileAE52_Obj_646,   5,          -51,  -71,   20,   19
  pose 0xFBE8, FileAE52_Obj_651,   4,          -40,  -74,   30,    0
  pose 0xFBE9, FileAE52_Obj_655,   7,          -48,  -82,   47,    6
  pose 0xFBEA, FileAE52_Obj_662,   9,          -49,  -77,   47,    0
  pose 0xFBEB, FileAE52_Obj_671,   5,          -49,  -77,   15,    0
  pose 0x7BE7, FileAE52_Obj_676,   5,          -54,  -72,   18,    0
  pose 0x7BE8, FileAE52_Obj_681,   5,          -53,  -69,   19,    0
  pose 0x7BE9, FileAE52_Obj_686,   4,          -65,  -69,   23,   10
  pose 0x7BEA, FileAE52_Obj_690,   11,         -44,  -70,   44,   32
  pose 0x7BEB, FileAE52_Obj_701,   8,          -37,  -75,   55,   27
  pose 0x7BEC, FileAE52_Obj_709,   5,          -37,  -74,   30,    0
  pose 0xFC36, FileAE52_Obj_714,   3,          -48,  -71,   16,   25
  pose 0xFC37, FileAE52_Obj_717,   3,          -48,  -73,   18,   23
  pose 0xFC38, FileAE52_Obj_720,   3,          -48,  -71,   16,   25
  pose 0x7C37, FileAE52_Obj_723,   4,          -44,  -71,   24,   22
  pose 0x7C38, FileAE52_Obj_727,   4,          -48,  -71,   22,   15
  pose 0x7C39, FileAE52_Obj_731,   4,          -57,  -71,   22,   22
  pose 0x8777, FileAE52_Obj_735,   7,          -50,  -60,   16,   16
  pose 0x8797, FileAE52_Obj_742,   6,          -49,  -62,   25,   19
  pose 0x87B7, FileAE52_Obj_748,   4,          -48,  -71,   24,   25
  pose 0x87B9, FileAE52_Obj_752,   3,          -48,  -71,   22,   25
  pose 0x87D9, FileAE52_Obj_755,   4,          -48,  -73,   19,   23
  pose 0x87F9, FileAE52_Obj_759,   3,          -48,  -71,   16,   25
  pose 0x7C3A, FileAE52_Obj_762,   3,          -40,  -71,   30,    9
  pose 0x7C3B, FileAE52_Obj_765,   4,          -42,  -71,   33,    9
  pose 0x7C3C, FileAE52_Obj_769,   5,          -42,  -71,   23,    9
  pose 0xFC3A, FileAE52_Obj_774,   7,          -47,  -62,   17,   16
  pose 0xFC3B, FileAE52_Obj_781,   5,          -49,  -65,   18,   19
  pose 0xFC3C, FileAE52_Obj_786,   8,          -47,  -65,   17,   16
  pose 0xFC86, FileAE52_Obj_794,   7,          -32,  -75,   35,    0
  pose 0xFC87, FileAE52_Obj_801,   7,          -31,  -74,   37,    0
  pose 0xFC88, FileAE52_Obj_808,   6,          -31,  -74,   37,    0
  pose 0xFC89, FileAE52_Obj_814,   6,          -44,  -75,   35,    8
  pose 0xFC8A, FileAE52_Obj_820,   6,          -44,  -75,   35,    8
  pose 0xFC8B, FileAE52_Obj_826,   6,          -44,  -74,   37,    8
  pose 0xFC8C, FileAE52_Obj_832,   6,          -44,  -74,   37,    8
  pose 0xFC8D, FileAE52_Obj_838,   6,          -44,  -75,   35,    8
  pose 0x7C87, FileAE52_Obj_844,   8,          -48,  -65,   20,    8
  pose 0x7C88, FileAE52_Obj_852,   8,          -47,  -62,   18,    2
  pose 0x7C89, FileAE52_Obj_860,   9,          -47,  -62,   18,    2
  pose 0x7C8A, FileAE52_Obj_869,   9,          -48,  -65,   18,    0
  pose 0x7C8B, FileAE52_Obj_878,   8,          -48,  -65,   18,    0
  pose 0x7C8C, FileAE52_Obj_886,   7,          -47,  -62,   18,    2
  pose 0x7C8D, FileAE52_Obj_893,   8,          -47,  -62,   18,    2
  pose 0x7C8E, FileAE52_Obj_901,   8,          -48,  -65,   18,    0
  pose 0xFC76, FileAE52_Obj_909,   4,          -43,  -67,   28,   29
  pose 0xFC77, FileAE52_Obj_913,   4,          -43,  -62,   44,   18
  pose 0xFC78, FileAE52_Obj_917,   5,          -46,  -66,   39,   13
  pose 0x7C77, FileAE52_Obj_922,   3,          -48,  -67,   17,   14
  pose 0x7C78, FileAE52_Obj_925,   3,          -49,  -62,   18,   28
  pose 0x7C79, FileAE52_Obj_928,   8,          -48,  -58,   17,    6
  pose 0xFC06, FileAE52_Obj_936,   8,          -31,  -57,   16,   24
  pose 0xFC07, FileAE52_Obj_944,   8,          -32,  -58,   15,    0
  pose 0xFC08, FileAE52_Obj_952,   8,          -29,  -58,   23,    0
  pose 0xFC09, FileAE52_Obj_960,   7,          -34,  -59,   30,    7
  pose 0xFC0A, FileAE52_Obj_967,   8,          -33,  -73,   31,    0
  pose 0xFC0B, FileAE52_Obj_975,   7,          -30,  -74,   35,    0
  pose 0xFC0C, FileAE52_Obj_982,   7,          -30,  -73,   36,    0
  pose 0x7C07, FileAE52_Obj_989,   8,          -55,  -56,   12,   13
  pose 0x7C08, FileAE52_Obj_997,   8,          -54,  -58,   12,    6
  pose 0x7C09, FileAE52_Obj_1005,  7,          -50,  -62,   15,    3
  pose 0x7C0A, FileAE52_Obj_1012,  7,          -50,  -65,   16,    1
  pose 0x7C0B, FileAE52_Obj_1019,  8,          -51,  -68,   17,    0
  pose 0x7C0C, FileAE52_Obj_1027,  8,          -49,  -65,   16,    0
  pose 0x7C0D, FileAE52_Obj_1035,  8,          -47,  -63,   19,    1
  pose 0xFD06, FileAE52_Obj_1043,  5,          -47,  -66,   39,   14
  pose 0xFD07, FileAE52_Obj_1048,  3,          -41,  -60,   23,   36
  pose 0xFD08, FileAE52_Obj_1051,  6,          -47,  -50,   17,   31
  pose 0x7D07, FileAE52_Obj_1057,  8,          -48,  -55,   17,    9
  pose 0x7D08, FileAE52_Obj_1065,  4,          -50,  -58,   21,   37
  pose 0x7D09, FileAE52_Obj_1069,  7,          -55,  -51,   16,   17
  pose 0xFC16, FileAE52_Obj_1076,  5,          -43,  -67,   22,   21
  pose 0x7C17, FileAE52_Obj_1081,  4,          -62,  -69,   14,   11
  pose 0xFCD6, FileAE52_Obj_1085,  6,          -31,  -72,   35,    0
  pose 0xFCD7, FileAE52_Obj_1091,  5,          -32,  -62,   20,    0
  pose 0xFCD8, FileAE52_Obj_1096,  5,          -33,  -63,   19,    0
  pose 0xFCD9, FileAE52_Obj_1101,  6,          -34,  -73,   34,    0
  pose 0xFCDA, FileAE52_Obj_1107,  7,          -53,  -82,   40,   13
  pose 0xFCDB, FileAE52_Obj_1114,  7,          -53,  -84,   43,   13
  pose 0xFCDC, FileAE52_Obj_1121,  7,          -46,  -69,   33,   14
  pose 0xFCDD, FileAE52_Obj_1128,  7,          -44,  -70,   35,   13
  pose 0x7CD7, FileAE52_Obj_1135,  9,          -51,  -64,   15,    0
  pose 0x7CD8, FileAE52_Obj_1144,  8,          -45,  -65,   19,    7
  pose 0x7CD9, FileAE52_Obj_1152,  8,          -49,  -67,   15,    6
  pose 0x7CDA, FileAE52_Obj_1160,  8,          -51,  -65,   15,    0
  pose 0x7CDB, FileAE52_Obj_1168,  10,         -30,  -66,   29,   23
  pose 0x7CDC, FileAE52_Obj_1178,  8,          -28,  -64,   32,   26
  pose 0x7CDD, FileAE52_Obj_1186,  7,          -51,  -66,   15,    0
  pose 0x7CDE, FileAE52_Obj_1193,  9,          -49,  -61,   17,    3
  pose 0xFD6E, FileAE52_Obj_1202,  3,          -45,  -68,   19,   20
  pose 0xFD6F, FileAE52_Obj_1205,  4,          -45,  -69,   19,   27
  pose 0x7D6F, FileAE52_Obj_1209,  2,          -49,  -64,   15,    6
  pose 0x7D70, FileAE52_Obj_1211,  3,          -57,  -65,   19,   24
  pose 0xA35F, FileAE52_Obj_1214,  8,          -26,  -58,   17,   11
  pose 0xA36F, FileAE52_Obj_1222,  7,          -48,  -65,   16,   15
  pose 0xA95F, FileAE52_Obj_1229,  9,          -32,  -59,   15,    0
  pose 0xA97F, FileAE52_Obj_1238,  9,          -31,  -57,   16,    0
  pose 0xA99F, FileAE52_Obj_1247,  9,          -32,  -58,   15,    0
  pose 0xA9BF, FileAE52_Obj_1256,  8,          -44,  -59,   20,    8
  pose 0xA9DF, FileAE52_Obj_1264,  8,          -44,  -59,   20,    8
  pose 0xA9FF, FileAE52_Obj_1272,  8,          -44,  -57,   20,    8
  pose 0xAA1F, FileAE52_Obj_1280,  9,          -44,  -58,   20,    8
  pose 0xAA3F, FileAE52_Obj_1289,  8,          -44,  -59,   20,    8
  pose 0xA96F, FileAE52_Obj_1297,  9,          -44,  -58,   20,    8
  pose 0xA98F, FileAE52_Obj_1306,  10,         -32,  -56,   12,    0
  pose 0xA9AF, FileAE52_Obj_1316,  10,         -33,  -57,   19,    0
  pose 0xA9CF, FileAE52_Obj_1326,  10,         -33,  -58,   12,    0
  pose 0xA9EF, FileAE52_Obj_1336,  9,          -33,  -58,   11,    0
  pose 0xAA0F, FileAE52_Obj_1345,  9,          -32,  -56,   12,    0
  pose 0xAA2F, FileAE52_Obj_1354,  9,          -33,  -57,   19,    0
  pose 0xAA4F, FileAE52_Obj_1363,  9,          -33,  -58,   11,    0
  pose 0x7D5F, FileAE52_Obj_1372,  4,          -50,  -72,   14,    0
  pose 0x7D7F, FileAE52_Obj_1376,  4,          -58,  -71,   20,   15
  pose 0x7D9F, FileAE52_Obj_1380,  5,          -40,  -74,   28,   20
  pose 0x7DBF, FileAE52_Obj_1385,  6,          -48,  -86,   52,   10
  pose 0x7DCF, FileAE52_Obj_1391,  6,          -49,  -77,   55,    0
  pose 0x7E1F, FileAE52_Obj_1397,  2,          -46,  -76,   20,   12
  pose 0x7E3F, FileAE52_Obj_1399,  3,          -40,  -79,   24,    1
  pose 0x7E5F, FileAE52_Obj_1402,  3,          -47,  -74,   19,    0
  pose 0x7E7F, FileAE52_Obj_1405,  3,          -47,  -74,   18,    0
  pose 0xAE67, FileAE52_Obj_1408,  5,          -54,  -72,   18,    0
  pose 0xB267, FileAE52_Obj_1413,  5,          -53,  -69,   19,    0
  pose 0xB667, FileAE52_Obj_1418,  5,          -72,  -69,   23,    0
  pose 0xBA67, FileAE52_Obj_1423,  6,          -40,  -70,   42,   28
  pose 0xBC67, FileAE52_Obj_1429,  6,          -37,  -74,   50,   33
  pose 0xC667, FileAE52_Obj_1435,  4,          -43,  -62,   21,    2
  pose 0xCA67, FileAE52_Obj_1439,  4,          -44,  -65,   20,    0
  pose 0xCE67, FileAE52_Obj_1443,  5,          -46,  -70,   20,    0
  pose 0xD267, FileAE52_Obj_1448,  5,          -46,  -70,   19,    0
  pose 0xEC6A, FileAE52_Obj_1453,  4,          -43,  -67,   21,   29
  pose 0xF06A, FileAE52_Obj_1457,  4,          -43,  -70,   30,   18
  pose 0xF46A, FileAE52_Obj_1461,  5,          -46,  -60,   28,   13
  pose 0xEE6A, FileAE52_Obj_1466,  3,          -47,  -67,   31,   13
  pose 0xF26A, FileAE52_Obj_1469,  3,          -46,  -62,   35,   18
  pose 0xF66A, FileAE52_Obj_1472,  7,          -42,  -55,   22,    9
  pose 0x2C6B, FileAE52_Obj_1479,  8,          -40,  -69,   24,    0
  pose 0x306B, FileAE52_Obj_1487,  8,          -39,  -68,   25,    0
  pose 0x346B, FileAE52_Obj_1495,  8,          -39,  -68,   25,    0
  pose 0x386B, FileAE52_Obj_1503,  8,          -44,  -69,   24,    8
  pose 0x3C6B, FileAE52_Obj_1511,  8,          -44,  -69,   24,    8
  pose 0x406B, FileAE52_Obj_1519,  8,          -44,  -68,   25,    8
  pose 0x446B, FileAE52_Obj_1527,  8,          -44,  -68,   25,    8
  pose 0x486B, FileAE52_Obj_1535,  8,          -44,  -69,   24,    8
  pose 0x916E, FileAE52_Obj_1543,  7,          -44,  -61,   23,    8
  pose 0x918E, FileAE52_Obj_1550,  8,          -40,  -59,   24,    5
  pose 0x91AE, FileAE52_Obj_1558,  8,          -40,  -59,   24,    5
  pose 0x91CE, FileAE52_Obj_1566,  8,          -41,  -61,   23,    3
  pose 0x91EE, FileAE52_Obj_1574,  7,          -41,  -61,   23,    3
  pose 0x920E, FileAE52_Obj_1581,  7,          -40,  -59,   24,    5
  pose 0x922E, FileAE52_Obj_1588,  7,          -40,  -59,   24,    5
  pose 0x924E, FileAE52_Obj_1595,  7,          -41,  -61,   23,    3
  pose 0x815E, FileAE52_Obj_1602,  6,          -50,  -74,   16,    0
  pose 0x817E, FileAE52_Obj_1608,  4,          -43,  -79,   21,   17
  pose 0x819E, FileAE52_Obj_1612,  7,          -33,  -60,   19,    0
  pose 0x81BE, FileAE52_Obj_1619,  9,          -40,  -68,   24,    0
  pose 0x816E, FileAE52_Obj_1628,  10,         -34,  -60,   12,    0
  pose 0x818E, FileAE52_Obj_1638,  9,          -38,  -70,   26,    0
  pose 0x81AE, FileAE52_Obj_1647,  10,         -32,  -57,   33,    0
  pose 0x81CE, FileAE52_Obj_1657,  8,          -42,  -60,   22,    4
  pose 0xA15E, FileAE52_Obj_1665,  6,          -47,  -56,   23,   14
  pose 0xA17E, FileAE52_Obj_1671,  3,          -41,  -60,   31,   36
  pose 0xA199, FileAE52_Obj_1674,  6,          -47,  -70,   19,   14
  pose 0xA169, FileAE52_Obj_1680,  9,          -31,  -48,   20,    4
  pose 0xA189, FileAE52_Obj_1689,  4,          -43,  -58,   28,   25
  pose 0xA1A9, FileAE52_Obj_1693,  8,          -37,  -64,   27,    0
  pose 0x8359, FileAE52_Obj_1701,  5,          -43,  -67,   21,   21
  pose 0x8369, FileAE52_Obj_1706,  4,          -52,  -69,   14,   11
  pose 0xAE19, FileAE52_Obj_1710,  7,          -31,  -53,   18,    5
  pose 0xAE39, FileAE52_Obj_1717,  4,          -46,  -71,   18,    9
  pose 0xAE59, FileAE52_Obj_1721,  3,          -45,  -68,   19,   20
  pose 0xAE79, FileAE52_Obj_1724,  4,          -47,  -72,   19,   27
  pose 0xAE24, FileAE52_Obj_1728,  5,          -28,  -49,   20,    7
  pose 0xAE44, FileAE52_Obj_1733,  3,          -46,  -67,   18,    5
  pose 0xAE64, FileAE52_Obj_1736,  2,          -49,  -64,   15,    0
  pose 0xAE84, FileAE52_Obj_1738,  3,          -45,  -65,   19,    7
  pose 0x8754, FileAE52_Obj_1741,  4,          -46,  -71,   18,   25
  pose 0x8774, FileAE52_Obj_1745,  5,          -50,  -74,   16,   23
  pose 0x8794, FileAE52_Obj_1750,  4,          -50,  -71,   14,   25
  pose 0x8764, FileAE52_Obj_1754,  5,          -40,  -71,   24,    9
  pose 0x8784, FileAE52_Obj_1759,  4,          -42,  -71,   22,    9
  pose 0x87A4, FileAE52_Obj_1763,  4,          -42,  -71,   22,    9
  pose 0xEF08, FileAE52_Obj_1767,  4,          -48,  -71,   16,   25
  pose 0xF308, FileAE52_Obj_1771,  3,          -48,  -73,   18,   25
  pose 0x87B1, FileAE52_Obj_1774,  4,          -48,  -71,   17,   25
  pose 0xF6A8, FileAE52_Obj_1778,  3,          -48,  -71,   18,   25
  pose 0x87D1, FileAE52_Obj_1781,  4,          -48,  -73,   19,   23
  pose 0x87F1, FileAE52_Obj_1785,  3,          -48,  -71,   16,   25
  pose 0x87C1, FileAE52_Obj_1788,  4,          -40,  -71,   28,    9
  pose 0x87E1, FileAE52_Obj_1792,  5,          -43,  -66,   32,   14
  pose 0x8801, FileAE52_Obj_1797,  6,          -43,  -59,   25,    8
  pose 0x5597, FileAE52_Obj_1803,  7,          -44,  -61,   20,   16
  pose 0xD598, FileAE52_Obj_1810,  6,          -49,  -62,   16,   19
  pose 0x8811, FileAE52_Obj_1816,  7,          -51,  -61,   16,   16
  pose 0x7D59, FileAE52_Obj_1823,  7,          -30,  -75,   34,    0
  pose 0x7D79, FileAE52_Obj_1830,  8,          -38,  -65,   37,    2
  pose 0x7D99, FileAE52_Obj_1838,  7,          -30,  -66,   34,    0
  pose 0x7DB9, FileAE52_Obj_1845,  7,          -32,  -66,   32,    0
  pose 0x7DD9, FileAE52_Obj_1852,  7,          -32,  -66,   32,    0
  pose 0x7DF9, FileAE52_Obj_1859,  6,          -30,  -68,   23,    0
  pose 0x7E19, FileAE52_Obj_1865,  6,          -30,  -71,   24,    0
  pose 0x7E39, FileAE52_Obj_1871,  7,          -30,  -75,   21,    0
  pose 0x7E60, FileAE52_Obj_1878,  8,          -31,  -76,   27,    0
  pose 0x7E80, FileAE52_Obj_1886,  7,          -29,  -65,   33,    0
  pose 0x8380, FileAE52_Obj_1893,  6,          -29,  -74,   37,    0
  pose 0x83A0, FileAE52_Obj_1899,  6,          -29,  -74,   37,    0
  pose 0x83C0, FileAE52_Obj_1905,  7,          -29,  -74,   39,    0
  pose 0x83E0, FileAE52_Obj_1912,  7,          -29,  -74,   39,    0
  pose 0x8400, FileAE52_Obj_1919,  7,          -29,  -84,   47,    0
  pose 0x8420, FileAE52_Obj_1926,  7,          -29,  -84,   47,    0
  pose 0x8160, FileAE52_Obj_1933,  12,         -29,  -84,   50,    0
  pose 0x8180, FileAE52_Obj_1945,  12,         -29,  -84,   50,    0
  pose 0x81A0, FileAE52_Obj_1957,  13,         -29,  -84,   47,    0
  pose 0x81C0, FileAE52_Obj_1970,  13,         -29,  -84,   47,    0
  pose 0x81E0, FileAE52_Obj_1983,  12,         -29,  -84,   46,    0
  pose 0x8209, FileAE52_Obj_1995,  12,         -29,  -84,   48,    0
  pose 0x8229, FileAE52_Obj_2007,  7,          -29,  -84,   47,    0
  pose 0x8249, FileAE52_Obj_2014,  7,          -29,  -84,   47,    0
  pose 0xAFA7, FileAE52_Obj_2021,  7,          -43,  -63,   21,    1
  pose 0xB3A7, FileAE52_Obj_2028,  9,          -29,  -58,   22,    2
  pose 0xB7A7, FileAE52_Obj_2037,  7,          -34,  -64,   30,    0
  pose 0xBBA7, FileAE52_Obj_2044,  7,          -36,  -65,   29,    0
  pose 0xBFA7, FileAE52_Obj_2051,  7,          -36,  -66,   28,    0
  pose 0xC3A7, FileAE52_Obj_2058,  6,          -44,  -81,   20,    0
  pose 0xC7A7, FileAE52_Obj_2064,  6,          -44,  -83,   20,    0
  pose 0x7E59, FileAE52_Obj_2070,  7,          -43,  -88,   21,    0
  pose 0x7E79, FileAE52_Obj_2077,  7,          -44,  -90,   20,    0
  pose 0x7E8F, FileAE52_Obj_2084,  6,          -41,  -67,   23,    0
  pose 0x838F, FileAE52_Obj_2090,  6,          -38,  -64,   26,    0
  pose 0x83AF, FileAE52_Obj_2096,  6,          -38,  -64,   26,    0
  pose 0x83CF, FileAE52_Obj_2102,  10,         -38,  -64,   28,    0
  pose 0x83EF, FileAE52_Obj_2112,  7,          -38,  -64,   28,    0
  pose 0x840F, FileAE52_Obj_2119,  7,          -38,  -72,   36,    0
  pose 0x842F, FileAE52_Obj_2126,  7,          -37,  -72,   36,    0
  pose 0x816F, FileAE52_Obj_2133,  13,         -38,  -72,   40,    0
  pose 0x818F, FileAE52_Obj_2146,  12,         -37,  -72,   40,    0
  pose 0x81AF, FileAE52_Obj_2158,  14,         -38,  -72,   37,    0
  pose 0x81CF, FileAE52_Obj_2172,  13,         -38,  -72,   37,    0
  pose 0x81EF, FileAE52_Obj_2185,  13,         -38,  -72,   36,    0
  pose 0x820F, FileAE52_Obj_2198,  13,         -38,  -72,   38,    0
  pose 0x822F, FileAE52_Obj_2211,  7,          -38,  -72,   36,    0
  pose 0x824F, FileAE52_Obj_2218,  8,          -38,  -72,   36,    0
  pose 0x87BF, FileAE52_Obj_2226,  4,          -48,  -71,   20,   25
  pose 0x87DF, FileAE52_Obj_2230,  5,          -48,  -73,   19,   23
  pose 0x87FF, FileAE52_Obj_2235,  4,          -48,  -71,   16,   25
  pose 0x87C6, FileAE52_Obj_2239,  5,          -40,  -71,   33,    9
  pose 0x87E6, FileAE52_Obj_2244,  5,          -43,  -66,   28,   14
  pose 0x8806, FileAE52_Obj_2249,  6,          -43,  -71,   22,    9
  pose 0x87D6, FileAE52_Obj_2255,  9,          -47,  -64,   17,   16
  pose 0x87F6, FileAE52_Obj_2264,  6,          -49,  -65,   16,   19
  pose 0x8816, FileAE52_Obj_2270,  9,          -50,  -64,   16,   16
  pose 0x9156, FileAE52_Obj_2279,  7,          -32,  -64,   22,    0
  pose 0x9176, FileAE52_Obj_2286,  7,          -34,  -63,   30,    1
  pose 0x9196, FileAE52_Obj_2293,  6,          -34,  -63,   30,    2
  pose 0x91B6, FileAE52_Obj_2299,  6,          -44,  -64,   20,    8
  pose 0x91D6, FileAE52_Obj_2305,  5,          -44,  -64,   20,    8
  pose 0x91F6, FileAE52_Obj_2310,  5,          -44,  -62,   20,    8
  pose 0x9216, FileAE52_Obj_2315,  5,          -44,  -63,   21,    8
  pose 0x9236, FileAE52_Obj_2320,  5,          -44,  -64,   21,    8
  pose 0x9166, FileAE52_Obj_2325,  6,          -44,  -60,   20,    8
  pose 0x9186, FileAE52_Obj_2331,  7,          -44,  -57,   20,   11
  pose 0x91A6, FileAE52_Obj_2338,  7,          -45,  -58,   19,   11
  pose 0x91C6, FileAE52_Obj_2345,  7,          -31,  -61,   18,    0
  pose 0x91E6, FileAE52_Obj_2352,  6,          -31,  -60,   19,    0
  pose 0x9206, FileAE52_Obj_2358,  6,          -30,  -57,   19,    0
  pose 0x9226, FileAE52_Obj_2364,  6,          -30,  -58,   18,    0
  pose 0x9246, FileAE52_Obj_2370,  6,          -31,  -61,   16,    0
  pose 0x8216, FileAE52_Obj_2376,  7,          -36,  -66,   28,    0
  pose 0x8242, FileAE52_Obj_2383,  8,          -35,  -65,   29,    0
  pose 0x8262, FileAE52_Obj_2391,  7,          -30,  -74,   34,    0
  pose 0x8232, FileAE52_Obj_2398,  8,          -43,  -62,   21,    2
  pose 0x8252, FileAE52_Obj_2406,  7,          -43,  -62,   21,    2
  pose 0x8272, FileAE52_Obj_2413,  7,          -43,  -62,   21,    2
  pose 0xA162, FileAE52_Obj_2420,  8,          -41,  -56,   26,   22
  pose 0xA182, FileAE52_Obj_2428,  8,          -40,  -56,   26,   22
  pose 0xA1A2, FileAE52_Obj_2436,  8,          -39,  -57,   25,   21
  pose 0xA1C2, FileAE52_Obj_2444,  8,          -41,  -57,   25,   22
  pose 0xA1E2, FileAE52_Obj_2452,  8,          -42,  -57,   26,   22
  pose 0xA202, FileAE52_Obj_2460,  6,          -30,  -62,   23,    0
  pose 0xA172, FileAE52_Obj_2466,  9,          -28,  -55,   26,    5
  pose 0xA192, FileAE52_Obj_2475,  9,          -28,  -55,   26,    6
  pose 0xA1B2, FileAE52_Obj_2484,  9,          -29,  -55,   25,    6
  pose 0xA1D2, FileAE52_Obj_2493,  9,          -28,  -55,   25,    6
  pose 0xA1F2, FileAE52_Obj_2502,  9,          -29,  -55,   26,    5
  pose 0xA212, FileAE52_Obj_2511,  7,          -30,  -57,   19,    0
  pose 0x8362, FileAE52_Obj_2518,  6,          -43,  -67,   22,   21
  pose 0x8378, FileAE52_Obj_2524,  7,          -43,  -67,   22,   21
  pose 0x8368, FileAE52_Obj_2531,  5,          -53,  -69,   14,   11
  pose 0x8388, FileAE52_Obj_2536,  6,          -53,  -69,   14,   11
  pose 0xBE67, FileAE52_Obj_2542,  7,          -55,  -77,   55,    0
  pose 0x0D70, FileAE52_Obj_2549,  7,          -37,  -78,   50,   33
  pose 0x7DEF, FileAE52_Obj_2556,  5,          -55,  -77,   15,    0
  pose 0x7DFF, FileAE52_Obj_2561,  6,          -37,  -78,   43,    0
  pose 0x3D62, FileAE52_Obj_2567,  5,          -50,  -72,   16,    0
  pose 0x3D63, FileAE52_Obj_2572,  6,          -44,  -71,   22,    1
  pose 0x3D64, FileAE52_Obj_2578,  6,          -40,  -74,   24,    0
  pose 0x3D65, FileAE52_Obj_2584,  6,          -48,  -79,   32,    0
  pose 0x3D66, FileAE52_Obj_2590,  6,          -49,  -77,   15,    0
  pose 0x6861, FileAE52_Obj_2596,  6,          -54,  -72,   18,    0
  pose 0x6862, FileAE52_Obj_2602,  6,          -53,  -69,   29,   16
  pose 0x6863, FileAE52_Obj_2608,  6,          -41,  -69,   25,    0
  pose 0x6864, FileAE52_Obj_2614,  6,          -40,  -70,   24,   10
  pose 0x6865, FileAE52_Obj_2620,  7,          -37,  -74,   35,    0

FileAE52_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x75CA, FileAE52_Cmd_0,     1
  animation 0x75CB, FileAE52_Cmd_1,     1
  animation 0xF5CA, FileAE52_Cmd_2,     1
  animation 0xF5CB, FileAE52_Cmd_3,     1
  animation 0xB9E6, FileAE52_Cmd_4,     1
  animation 0x75CC, FileAE52_Cmd_5,     1
  animation 0x762A, FileAE52_Cmd_6,     8
  animation 0x762B, FileAE52_Cmd_14,    8
  animation 0xF62A, FileAE52_Cmd_22,    8
  animation 0xF62B, FileAE52_Cmd_30,    8
  animation 0xC5E6, FileAE52_Cmd_38,    8
  animation 0x762C, FileAE52_Cmd_46,    8
  animation 0x736A, FileAE52_Cmd_54,    5
  animation 0x736B, FileAE52_Cmd_59,    5
  animation 0xF36A, FileAE52_Cmd_64,    6
  animation 0xF36B, FileAE52_Cmd_70,    6
  animation 0xB9DD, FileAE52_Cmd_76,    4
  animation 0xBDDD, FileAE52_Cmd_80,    4
  animation 0xB9E0, FileAE52_Cmd_84,    2
  animation 0xBDE0, FileAE52_Cmd_86,    2
  animation 0xB9E1, FileAE52_Cmd_88,    2
  animation 0xBDE1, FileAE52_Cmd_90,    2
  animation 0xB9E2, FileAE52_Cmd_92,    2
  animation 0xBDE2, FileAE52_Cmd_94,    2
  animation 0xBBDD, FileAE52_Cmd_96,    15
  animation 0xBFDD, FileAE52_Cmd_111,   15
  animation 0xBBDE, FileAE52_Cmd_126,   6
  animation 0xBFDE, FileAE52_Cmd_132,   6
  animation 0xBBDF, FileAE52_Cmd_138,   1
  animation 0xBFDF, FileAE52_Cmd_139,   1
  animation 0x740A, FileAE52_Cmd_140,   3
  animation 0x740B, FileAE52_Cmd_143,   3
  animation 0x740C, FileAE52_Cmd_146,   3
  animation 0xF40A, FileAE52_Cmd_149,   3
  animation 0xF40B, FileAE52_Cmd_152,   3
  animation 0xF40C, FileAE52_Cmd_155,   3
  animation 0xF40D, FileAE52_Cmd_158,   3
  animation 0xF40E, FileAE52_Cmd_161,   3
  animation 0xF40F, FileAE52_Cmd_164,   3
  animation 0x81E6, FileAE52_Cmd_167,   3
  animation 0x8206, FileAE52_Cmd_170,   3
  animation 0x740D, FileAE52_Cmd_173,   3
  animation 0x740E, FileAE52_Cmd_176,   3
  animation 0x740F, FileAE52_Cmd_179,   3
  animation 0x7410, FileAE52_Cmd_182,   3
  animation 0x8257, FileAE52_Cmd_185,   3
  animation 0x8277, FileAE52_Cmd_188,   3
  animation 0xF410, FileAE52_Cmd_191,   3
  animation 0x74AA, FileAE52_Cmd_194,   8
  animation 0x74AB, FileAE52_Cmd_202,   8
  animation 0xF4AA, FileAE52_Cmd_210,   8
  animation 0xF4AB, FileAE52_Cmd_218,   8
  animation 0xBD4A, FileAE52_Cmd_226,   8
  animation 0x74AC, FileAE52_Cmd_234,   8
  animation 0xBF4A, FileAE52_Cmd_242,   8
  animation 0xF4AC, FileAE52_Cmd_250,   8
  animation 0xBC76, FileAE52_Cmd_258,   1
  animation 0x3C77, FileAE52_Cmd_259,   1
  animation 0xBC77, FileAE52_Cmd_260,   1
  animation 0x3C78, FileAE52_Cmd_261,   1
  animation 0xBC78, FileAE52_Cmd_262,   1
  animation 0x3C79, FileAE52_Cmd_263,   1
  animation 0xFC76, FileAE52_Cmd_264,   1
  animation 0x7C77, FileAE52_Cmd_265,   1
  animation 0xFC77, FileAE52_Cmd_266,   1
  animation 0x7C78, FileAE52_Cmd_267,   1
  animation 0xFC78, FileAE52_Cmd_268,   1
  animation 0x7C79, FileAE52_Cmd_269,   1
  animation 0x8F61, FileAE52_Cmd_270,   1
  animation 0xEEAB, FileAE52_Cmd_271,   1
  animation 0x8F81, FileAE52_Cmd_272,   1
  animation 0xF2AB, FileAE52_Cmd_273,   1
  animation 0x8FA1, FileAE52_Cmd_274,   1
  animation 0xF6AB, FileAE52_Cmd_275,   1
  animation 0x2A89, FileAE52_Cmd_276,   4
  animation 0x3C07, FileAE52_Cmd_280,   4
  animation 0xFC06, FileAE52_Cmd_284,   6
  animation 0x7C07, FileAE52_Cmd_290,   6
  animation 0x2C47, FileAE52_Cmd_296,   4
  animation 0xBC07, FileAE52_Cmd_300,   4
  animation 0xBD06, FileAE52_Cmd_304,   2
  animation 0x3D07, FileAE52_Cmd_306,   2
  animation 0xBD07, FileAE52_Cmd_308,   1
  animation 0x3D08, FileAE52_Cmd_309,   1
  animation 0xFD06, FileAE52_Cmd_310,   2
  animation 0x7D07, FileAE52_Cmd_312,   2
  animation 0xFD07, FileAE52_Cmd_314,   1
  animation 0x7D08, FileAE52_Cmd_315,   1
  animation 0x2C8D, FileAE52_Cmd_316,   2
  animation 0x2C5C, FileAE52_Cmd_318,   2
  animation 0x308D, FileAE52_Cmd_320,   1
  animation 0xBD08, FileAE52_Cmd_321,   1
  animation 0x2B5C, FileAE52_Cmd_322,   5
  animation 0x2D5C, FileAE52_Cmd_327,   5
  animation 0x2F5C, FileAE52_Cmd_332,   1
  animation 0xFD08, FileAE52_Cmd_333,   1
  animation 0xBC16, FileAE52_Cmd_334,   1
  animation 0x3C17, FileAE52_Cmd_335,   1
  animation 0xFC16, FileAE52_Cmd_336,   1
  animation 0x7C17, FileAE52_Cmd_337,   1
  animation 0x6ABB, FileAE52_Cmd_338,   1
  animation 0xBC17, FileAE52_Cmd_339,   1
  animation 0x6BBB, FileAE52_Cmd_340,   1
  animation 0xFC17, FileAE52_Cmd_341,   1
  animation 0xBD66, FileAE52_Cmd_342,   1
  animation 0x3D67, FileAE52_Cmd_343,   1
  animation 0xBD67, FileAE52_Cmd_344,   4
  animation 0x3D68, FileAE52_Cmd_348,   4
  animation 0xBD68, FileAE52_Cmd_352,   8
  animation 0x3D69, FileAE52_Cmd_360,   8
  animation 0xFD68, FileAE52_Cmd_368,   8
  animation 0x7D69, FileAE52_Cmd_376,   8
  animation 0xB2C0, FileAE52_Cmd_384,   8
  animation 0xBD69, FileAE52_Cmd_392,   8
  animation 0xBCC6, FileAE52_Cmd_400,   5
  animation 0x3CC7, FileAE52_Cmd_405,   5
  animation 0x7CC7, FileAE52_Cmd_410,   2
  animation 0xFCC7, FileAE52_Cmd_412,   2
  animation 0x74EA, FileAE52_Cmd_414,   1
  animation 0x74EB, FileAE52_Cmd_415,   1
  animation 0xF4EA, FileAE52_Cmd_416,   1
  animation 0xF4EB, FileAE52_Cmd_417,   1
  animation 0xBB1A, FileAE52_Cmd_418,   1
  animation 0x74EC, FileAE52_Cmd_419,   1
  animation 0xBCF9, FileAE52_Cmd_420,   4
  animation 0xF4EC, FileAE52_Cmd_424,   4
  animation 0xFCD6, FileAE52_Cmd_428,   3
  animation 0x7CD7, FileAE52_Cmd_431,   3
  animation 0xFCD7, FileAE52_Cmd_434,   1
  animation 0x7CD8, FileAE52_Cmd_435,   1
  animation 0xFCD8, FileAE52_Cmd_436,   2
  animation 0x7CD9, FileAE52_Cmd_438,   2
  animation 0xFCD9, FileAE52_Cmd_440,   3
  animation 0x7CDA, FileAE52_Cmd_443,   3
  animation 0xFCDA, FileAE52_Cmd_446,   12
  animation 0x7CDB, FileAE52_Cmd_458,   12
  animation 0xCD48, FileAE52_Cmd_470,   5
  animation 0xD148, FileAE52_Cmd_475,   5
  animation 0xCD49, FileAE52_Cmd_480,   1
  animation 0xD149, FileAE52_Cmd_481,   1
  animation 0xB9DE, FileAE52_Cmd_482,   2
  animation 0xBDDE, FileAE52_Cmd_484,   2
  animation 0xB9DF, FileAE52_Cmd_486,   2
  animation 0xBDDF, FileAE52_Cmd_488,   2

1:
FileAE52_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileAE52_Obj_0:
    subsprite OAM_SIZE_16x16,    1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -23,  550,    0
    subsprite OAM_SIZE_16x32,  -10,  -37,  652,    0
    subsprite OAM_SIZE_8x32,     6,  -37,  654,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  556,    0
    subsprite OAM_SIZE_8x16,     6,   -5,  558,    0
  FileAE52_Obj_6:
    subsprite OAM_SIZE_32x32,  -16,  -33,  908,    0
    subsprite OAM_SIZE_16x8,   -16,   -1,  428,    0
    subsprite OAM_SIZE_8x8,      0,   -1, 1911,    0
    subsprite OAM_SIZE_16x16,   -4,  -31, 1179,    0
    subsprite OAM_SIZE_8x8,      4,  -15, 1211,    0
    subsprite OAM_SIZE_16x8,    -4,  -39, 1163,    0
  FileAE52_Obj_12:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  192,    0
  FileAE52_Obj_19:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -1,  -26,  194,    0
  FileAE52_Obj_26:
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -27,  196,    0
  FileAE52_Obj_32:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  194,    0
  FileAE52_Obj_38:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  192,    0
  FileAE52_Obj_44:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -1,  -26,  194,    0
  FileAE52_Obj_50:
    subsprite OAM_SIZE_16x32,  -11,  -35,  202,    0
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -27,  196,    0
  FileAE52_Obj_57:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  194,    0
  FileAE52_Obj_63:
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,  -16,  -25,  135,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
  FileAE52_Obj_71:
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_8x32,    -6,  -22,  132,    0
  FileAE52_Obj_80:
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -7,  -23,  128,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
  FileAE52_Obj_89:
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_8x32,    -8,  -25,  132,    0
  FileAE52_Obj_98:
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,  -16,  -25,  135,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
  FileAE52_Obj_106:
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_8x32,    -6,  -22,  132,    0
  FileAE52_Obj_114:
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -7,  -23,  128,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
  FileAE52_Obj_122:
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_8x32,    -8,  -25,  132,    0
  FileAE52_Obj_130:
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_32x32,  -18,  -40,  264,    0
  FileAE52_Obj_133:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -12,  -39,  268,    0
    subsprite OAM_SIZE_16x16,  -12,  -15,  200,    0
  FileAE52_Obj_137:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,   -8,  -42,  320,    0
    subsprite OAM_SIZE_16x16,    8,  -18,  230,    0
  FileAE52_Obj_141:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -16,  -47,  324,    0
    subsprite OAM_SIZE_16x16,   16,  -39,  232,    0
  FileAE52_Obj_145:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
  FileAE52_Obj_149:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
  FileAE52_Obj_151:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -22,  -40,  448,    0
    subsprite OAM_SIZE_16x16,    2,  -16,  672,    0
  FileAE52_Obj_155:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -21,  -37,  452,    0
    subsprite OAM_SIZE_16x16,    3,  -21,  460,    0
  FileAE52_Obj_159:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -9,  -37,  456,    0
    subsprite OAM_SIZE_16x16,  -25,  -21,  462,    0
  FileAE52_Obj_163:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -8,  -38,  256,    0
    subsprite OAM_SIZE_16x16,    8,   -6,  492,    0
  FileAE52_Obj_167:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x16,   19,  -26,  198,    0
  FileAE52_Obj_172:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
  FileAE52_Obj_174:
    subsprite OAM_SIZE_32x32,  -14,  -39, 1608,    0
    subsprite OAM_SIZE_32x16,  -14,   -7, 1612,    0
  FileAE52_Obj_176:
    subsprite OAM_SIZE_8x32,   -16,  -35, 2436,    0
    subsprite OAM_SIZE_8x32,     8,  -35, 2437,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
  FileAE52_Obj_180:
    subsprite OAM_SIZE_32x32,  -18,  -39, 1608,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -18,   -7, 1612,    0, xflip=1
  FileAE52_Obj_182:
    subsprite OAM_SIZE_32x32,   -8,  -39, 1432,    0
    subsprite OAM_SIZE_16x8,    -8,   -7, 1325,    0
    subsprite OAM_SIZE_8x8,      8,   -7, 1327,    0
  FileAE52_Obj_185:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1372,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1436,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1295,    0
  FileAE52_Obj_188:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1536,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1376,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1347,    0
  FileAE52_Obj_191:
    subsprite OAM_SIZE_32x32,  -16,  -39, 1540,    0
    subsprite OAM_SIZE_32x8,   -16,   -7, 1212,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1632,    0
  FileAE52_Obj_194:
    subsprite OAM_SIZE_32x32,  -16,  -39, 1544,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 1604,    0
  FileAE52_Obj_196:
    subsprite OAM_SIZE_32x32,  -16,  -39, 1540,    0, xflip=1
    subsprite OAM_SIZE_32x8,   -16,   -7, 1212,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,    1, 1632,    0, xflip=1
  FileAE52_Obj_199:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    3,  -27, 2474,    0
  FileAE52_Obj_206:
    subsprite OAM_SIZE_16x16,    1,  -38,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -22,  396,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    5,  -26, 2472,    0
  FileAE52_Obj_213:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    5,  -26, 2472,    0
  FileAE52_Obj_219:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    3,  -27, 2474,    0
  FileAE52_Obj_225:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    3,  -27, 2474,    0
  FileAE52_Obj_231:
    subsprite OAM_SIZE_16x16,    1,  -38,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -22,  396,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    5,  -26, 2472,    0
  FileAE52_Obj_237:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    5,  -26, 2472,    0
  FileAE52_Obj_243:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    3,  -27, 2474,    0
  FileAE52_Obj_249:
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   74,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
  FileAE52_Obj_257:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -19,  173,    0
    subsprite OAM_SIZE_16x16,   -2,  -35,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -19,  952,    0
  FileAE52_Obj_265:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -19,  173,    0
    subsprite OAM_SIZE_16x8,    -3,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -17, 1211,    0
    subsprite OAM_SIZE_16x16,   -3,  -33, 1179,    0
  FileAE52_Obj_274:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   74,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
  FileAE52_Obj_283:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   74,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
  FileAE52_Obj_291:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -19,  173,    0
    subsprite OAM_SIZE_16x16,   -2,  -35,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -19,  952,    0
  FileAE52_Obj_298:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -19,  173,    0
    subsprite OAM_SIZE_16x8,    -3,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -17, 1211,    0
    subsprite OAM_SIZE_16x16,   -3,  -33, 1179,    0
  FileAE52_Obj_306:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,  -11,  -22,   74,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
  FileAE52_Obj_314:
    subsprite OAM_SIZE_32x32,  -11,  -35,  896,    0
    subsprite OAM_SIZE_32x8,   -11,   -3,  960,    0
    subsprite OAM_SIZE_8x8,      5,    5,  978,    0
  FileAE52_Obj_317:
    subsprite OAM_SIZE_32x32,  -11,  -30,  900,    0
    subsprite OAM_SIZE_16x8,    -3,    2,  964,    0
    subsprite OAM_SIZE_8x16,    21,   -6,  175,    0
  FileAE52_Obj_320:
    subsprite OAM_SIZE_32x32,  -15,  -35,  840,    0
    subsprite OAM_SIZE_16x16,   -7,   -3,  526,    0
  FileAE52_Obj_322:
    subsprite OAM_SIZE_32x32,  -14,  -30,  844,    0
    subsprite OAM_SIZE_16x8,   -14,    2,  430,    0
  FileAE52_Obj_324:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    1,  -42,  206,    0
    subsprite OAM_SIZE_16x8,     1,  -26,  238,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    4,  -25, 2474,    0
  FileAE52_Obj_331:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    2,  -41,  206,    0
    subsprite OAM_SIZE_16x8,     2,  -25,  238,    0
    subsprite OAM_SIZE_8x32,     2,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    4,  -26, 2474,    0
  FileAE52_Obj_338:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    4,  -25, 2474,    0
    subsprite OAM_SIZE_16x16,    1,  -39,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -23,  396,    0
  FileAE52_Obj_345:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    3,  -26,  139,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -20,   74,    0
    subsprite OAM_SIZE_16x16,    1,  -38,  524,    0
    subsprite OAM_SIZE_8x16,    -7,  -38,  523,    0
    subsprite OAM_SIZE_16x8,     1,  -22,  254,    0
  FileAE52_Obj_354:
    subsprite OAM_SIZE_16x32,    3,  -27,  139,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -21,   74,    0
    subsprite OAM_SIZE_16x32,   -1,  -41,  972,    0
  FileAE52_Obj_361:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    3,  -26,  139,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -20,   74,    0
    subsprite OAM_SIZE_16x16,   -2,  -37,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -21,  952,    0
  FileAE52_Obj_369:
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 2374,    0
    subsprite OAM_SIZE_8x32,     4,  -30,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -30,  579,    0
    subsprite OAM_SIZE_16x16,    7,  -18, 2472,    0
  FileAE52_Obj_374:
    subsprite OAM_SIZE_32x32,   -9,  -28,  388,    0
    subsprite OAM_SIZE_32x8,    -9,    4, 1984,    0
  FileAE52_Obj_376:
    subsprite OAM_SIZE_16x32,    0,  -34, 2432,    0
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_8x32,     2,  -31,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -31,  579,    0
    subsprite OAM_SIZE_16x32,    0,  -20,  196,    0
  FileAE52_Obj_381:
    subsprite OAM_SIZE_16x32,    1,  -21,  204,    0
    subsprite OAM_SIZE_16x32,   -7,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      9,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -32,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -32,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -30,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -14,  952,    0
    subsprite OAM_SIZE_16x16,  -12,  -12,  173,    0
  FileAE52_Obj_389:
    subsprite OAM_SIZE_32x32,  -11,  -26,  384,    0
    subsprite OAM_SIZE_16x8,   -11,    6,  412,    0
    subsprite OAM_SIZE_8x8,      5,    6, 1910,    0
  FileAE52_Obj_392:
    subsprite OAM_SIZE_16x32,    0,  -29,  130,    0
    subsprite OAM_SIZE_16x32,  -10,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      6,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -35,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -35,  576,    0
    subsprite OAM_SIZE_16x16,   -1,  -21, 2450,    0
    subsprite OAM_SIZE_16x8,    -1,  -29, 2434,    0
    subsprite OAM_SIZE_8x32,    -8,  -19,  132,    0
  FileAE52_Obj_400:
    subsprite OAM_SIZE_32x32,  -11,  -35,  332,    0
    subsprite OAM_SIZE_16x8,   -11,   -3,  976,    0
    subsprite OAM_SIZE_16x8,    -3,    5, 1010,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  979,    0
  FileAE52_Obj_404:
    subsprite OAM_SIZE_32x32,  -18,  -37,  392,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  992,    0
    subsprite OAM_SIZE_8x8,      6,   -5,  994,    0
  FileAE52_Obj_407:
    subsprite OAM_SIZE_16x16,   -6,   -7, 1193,    0
    subsprite OAM_SIZE_8x16,   -14,   -7, 1192,    0
  FileAE52_Obj_409:
    subsprite OAM_SIZE_8x16,   -14,   -7, 1160,    0
    subsprite OAM_SIZE_16x16,   -6,   -7, 1161,    0
  FileAE52_Obj_411:
    subsprite OAM_SIZE_16x16,   -9,   -7, 1033,    0
    subsprite OAM_SIZE_8x8,      7,   -7, 1065,    0
  FileAE52_Obj_413:
    subsprite OAM_SIZE_8x8,      8,   -9, 1065,    0
    subsprite OAM_SIZE_16x16,   -8,   -9, 1033,    0
  FileAE52_Obj_415:
    subsprite OAM_SIZE_16x32,   -7,  -25, 1024,    0
    subsprite OAM_SIZE_8x16,     9,  -25, 1026,    0
    subsprite OAM_SIZE_8x8,      9,   -9, 1071,    0
  FileAE52_Obj_418:
    subsprite OAM_SIZE_16x16,  -12,  -12,  738,    0
    subsprite OAM_SIZE_8x16,   -12,  -20, 1027,    0
    subsprite OAM_SIZE_8x32,    -4,  -36, 1029,    0
    subsprite OAM_SIZE_16x16,    4,  -36, 1059,    0
  FileAE52_Obj_422:
    subsprite OAM_SIZE_16x16,  -14,  -13,  996,    0
    subsprite OAM_SIZE_8x8,      2,   -5,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -37, 1030,    0
    subsprite OAM_SIZE_16x16,    2,  -37,  814,    0
    subsprite OAM_SIZE_8x8,     10,  -21, 1066,    0
    subsprite OAM_SIZE_8x16,   -14,  -21, 1028,    0
  FileAE52_Obj_428:
    subsprite OAM_SIZE_32x32,  -14,  -39, 1088,    0
    subsprite OAM_SIZE_16x16,  -14,   -7,  782,    0
    subsprite OAM_SIZE_8x16,     2,   -7,  559,    0
  FileAE52_Obj_431:
    subsprite OAM_SIZE_32x32,  -13,  -36, 1092,    0
    subsprite OAM_SIZE_32x16,  -13,  -12, 1168,    0
  FileAE52_Obj_433:
    subsprite OAM_SIZE_32x32,  -13,  -37, 1096,    0
    subsprite OAM_SIZE_32x8,   -13,   -5, 1152,    0
    subsprite OAM_SIZE_16x8,    -5,    3,  566,    0
  FileAE52_Obj_436:
    subsprite OAM_SIZE_16x16,   -9,  -12,  398,    0
    subsprite OAM_SIZE_16x8,    -9,    4,  157,    0
  FileAE52_Obj_438:
    subsprite OAM_SIZE_16x16,   -7,  -12,  904,    0
    subsprite OAM_SIZE_16x8,    -7,    4,  936,    0
  FileAE52_Obj_440:
    subsprite OAM_SIZE_16x16,   -9,   -7, 1179,    0
    subsprite OAM_SIZE_16x8,    -9,  -15, 1163,    0
    subsprite OAM_SIZE_8x8,     -1,    9, 1211,    0
  FileAE52_Obj_443:
    subsprite OAM_SIZE_16x16,   -8,   -8, 1179,    0
    subsprite OAM_SIZE_16x8,    -8,  -16, 1163,    0
    subsprite OAM_SIZE_8x8,      0,    8, 1211,    0
  FileAE52_Obj_446:
    subsprite OAM_SIZE_16x32,   -6,  -27,  644,    0
    subsprite OAM_SIZE_8x8,     10,  -19,  143,    0
  FileAE52_Obj_448:
    subsprite OAM_SIZE_16x16,  -11,  -10,  674,    0
    subsprite OAM_SIZE_16x32,  -11,  -34,  646,    0
    subsprite OAM_SIZE_8x32,     5,  -34,  648,    0
  FileAE52_Obj_451:
    subsprite OAM_SIZE_16x16,  -12,   -9,  704,    0
    subsprite OAM_SIZE_16x32,   -4,  -33,  650,    0
    subsprite OAM_SIZE_8x32,   -12,  -33,  649,    0
    subsprite OAM_SIZE_8x8,     12,  -25,  159,    0
  FileAE52_Obj_455:
    subsprite OAM_SIZE_32x32,  -14,  -35,  708,    0
    subsprite OAM_SIZE_16x16,  -14,  -11,  706,    0
  FileAE52_Obj_457:
    subsprite OAM_SIZE_32x32,  -17,  -32,  712,    0
  FileAE52_Obj_458:
    subsprite OAM_SIZE_32x32,  -13,  -33,  716,    0
    subsprite OAM_SIZE_16x16,  -13,   -9,  736,    0
  FileAE52_Obj_460:
    subsprite OAM_SIZE_32x32,  -12,  -19, 1364,    0
    subsprite OAM_SIZE_32x16,  -12,  -35, 1332,    0
  FileAE52_Obj_462:
    subsprite OAM_SIZE_32x32,  -12,  -19, 1368,    0
    subsprite OAM_SIZE_32x16,  -12,  -35, 1336,    0
  FileAE52_Obj_464:
    subsprite OAM_SIZE_32x16,  -12,  -34, 1336,    0
    subsprite OAM_SIZE_32x16,  -12,  -11, 1340,    0
    subsprite OAM_SIZE_16x8,    -4,    5, 1330,    0
  FileAE52_Obj_467:
    subsprite OAM_SIZE_16x16,   -4,  -27, 1182,    0
    subsprite OAM_SIZE_8x16,   -12,  -27, 1181,    0
    subsprite OAM_SIZE_16x8,    -4,  -35, 1166,    0
    subsprite OAM_SIZE_32x8,   -12,   -3, 1312,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1165,    0
    subsprite OAM_SIZE_8x8,      4,    5, 1324,    0
  FileAE52_Obj_473:
    subsprite OAM_SIZE_16x16,   -5,  -17, 1182,    0
    subsprite OAM_SIZE_8x16,   -13,  -17, 1181,    0
    subsprite OAM_SIZE_16x8,    -5,  -25, 1166,    0
    subsprite OAM_SIZE_32x8,   -12,   -3, 1316,    0
  FileAE52_Obj_477:
    subsprite OAM_SIZE_32x32,  -18,  -37,  968,    0
    subsprite OAM_SIZE_32x16,  -18,   -5, 1280,    0
  FileAE52_Obj_479:
    subsprite OAM_SIZE_8x8,    -10,  -22, 1068,    0
    subsprite OAM_SIZE_32x16,  -18,   -5, 1284,    0
    subsprite OAM_SIZE_16x16,  -10,  -21,  998,    0
    subsprite OAM_SIZE_8x8,    -18,  -21,  980,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  981,    0
    subsprite OAM_SIZE_16x16,  -10,  -38, 1036,    0
    subsprite OAM_SIZE_16x8,    -2,  -22, 1069,    0
  FileAE52_Obj_486:
    subsprite OAM_SIZE_16x32,  -10,  -37, 1036,    0
    subsprite OAM_SIZE_8x16,   -18,  -21, 1067,    0
    subsprite OAM_SIZE_8x8,      6,  -21, 1070,    0
    subsprite OAM_SIZE_32x8,   -18,   -5, 1288,    0
    subsprite OAM_SIZE_16x8,   -18,    3, 1304,    0
  FileAE52_Obj_491:
    subsprite OAM_SIZE_16x32,  -10,  -37, 1031,    0
    subsprite OAM_SIZE_8x8,    -18,  -13, 1081,    0
    subsprite OAM_SIZE_8x8,      6,  -29, 1082,    0
    subsprite OAM_SIZE_16x8,   -10,   -5, 1293,    0
    subsprite OAM_SIZE_8x8,    -18,   -5, 1292,    0
  FileAE52_Obj_496:
    subsprite OAM_SIZE_16x16,  -10,  -21, 1328,    0
    subsprite OAM_SIZE_8x8,      6,  -13, 1346,    0
    subsprite OAM_SIZE_32x8,   -18,   -5, 1360,    0
  FileAE52_Obj_499:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -23,  550,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -3,  -23, 1792,    0
    subsprite OAM_SIZE_16x8,    -3,    9,  141,    0
  FileAE52_Obj_507:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,  -24,  -19, 1664,    0
    subsprite OAM_SIZE_16x16,   -4,  -31, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -39, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -15, 1211,    0
  FileAE52_Obj_515:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -5,  -24, 1792,    0
    subsprite OAM_SIZE_16x8,    -5,    8,  141,    0
  FileAE52_Obj_523:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -5,  -24, 1794,    0
    subsprite OAM_SIZE_16x8,    -5,    8, 1320,    0
  FileAE52_Obj_531:
    subsprite OAM_SIZE_16x32,  -11,  -35,  202,    0
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -6,  -24, 1796,    0
    subsprite OAM_SIZE_16x8,    -6,    8, 1322,    0
  FileAE52_Obj_539:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -6,  -24, 1798,    0
    subsprite OAM_SIZE_16x8,    -6,    8, 1378,    0
  FileAE52_Obj_546:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x8,    -6,    8, 1378,    0
    subsprite OAM_SIZE_16x32,   -6,  -24, 1798,    0
  FileAE52_Obj_553:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -3,  -24,  328,    0
    subsprite OAM_SIZE_16x8,    -3,    8, 1306,    0
  FileAE52_Obj_560:
    subsprite OAM_SIZE_16x32,  -11,  -35,  202,    0
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -3,  -24,  520,    0
    subsprite OAM_SIZE_16x8,    -3,    8, 1308,    0
  FileAE52_Obj_568:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -24,  516,    0
    subsprite OAM_SIZE_16x8,    -2,    8, 1310,    0
  FileAE52_Obj_575:
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -25,  -21, 1664,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
  FileAE52_Obj_583:
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,  -25,  -21, 1668,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
  FileAE52_Obj_592:
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_32x32,  -27,  -22, 1672,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
  FileAE52_Obj_601:
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -28,  -22, 1676,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
  FileAE52_Obj_610:
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -28,  -22, 1676,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
  FileAE52_Obj_618:
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,  -25,  -19, 1728,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
  FileAE52_Obj_626:
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_32x32,  -23,  -20, 1732,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
  FileAE52_Obj_634:
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -23,  -21, 1736,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
  FileAE52_Obj_642:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -18,  -40,  264,    0
    subsprite OAM_SIZE_16x32,  -17,  -26, 1740,    0
  FileAE52_Obj_646:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -12,  -39,  268,    0
    subsprite OAM_SIZE_16x16,  -12,  -15,  200,    0
    subsprite OAM_SIZE_32x16,  -19,  -13, 1836,    0
  FileAE52_Obj_651:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,   -8,  -42,  320,    0
    subsprite OAM_SIZE_16x32,   14,  -21, 1742,    0
  FileAE52_Obj_655:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -16,  -47,  324,    0
    subsprite OAM_SIZE_32x32,   15,  -50, 1856,    0
    subsprite OAM_SIZE_16x8,    31,  -18, 1862,    0
    subsprite OAM_SIZE_16x16,   23,  -10, 1878,    0
    subsprite OAM_SIZE_8x8,     23,  -18, 1822,    0
  FileAE52_Obj_662:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
    subsprite OAM_SIZE_8x16,    -1,  -58, 1807,    0
    subsprite OAM_SIZE_16x8,     7,  -58, 1820,    0
    subsprite OAM_SIZE_16x8,    23,  -58, 1804,    0
    subsprite OAM_SIZE_8x8,     39,  -58, 1806,    0
    subsprite OAM_SIZE_8x16,    -9,  -50, 1492,    0
  FileAE52_Obj_671:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
    subsprite OAM_SIZE_16x16,  -14,  -47, 1438,    0
  FileAE52_Obj_676:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -22,  -40,  448,    0
    subsprite OAM_SIZE_16x16,    2,  -16,  672,    0
    subsprite OAM_SIZE_16x32,  -22,  -41, 1864,    0
  FileAE52_Obj_681:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -21,  -37,  452,    0
    subsprite OAM_SIZE_16x16,    3,  -21,  460,    0
    subsprite OAM_SIZE_16x32,  -22,  -39, 1866,    0
  FileAE52_Obj_686:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -9,  -37,  456,    0
    subsprite OAM_SIZE_32x16,  -33,  -22, 1868,    0
  FileAE52_Obj_690:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -8,  -38,  256,    0
    subsprite OAM_SIZE_32x32,    4,    0, 1988,    0
    subsprite OAM_SIZE_16x16,  -28,   -8, 1966,    0
    subsprite OAM_SIZE_16x8,     4,   -8, 2032,    0
    subsprite OAM_SIZE_16x16,  -12,    0, 2002,    0
    subsprite OAM_SIZE_16x8,   -12,   16, 2034,    0
    subsprite OAM_SIZE_8x8,    -20,    8, 1948,    0
    subsprite OAM_SIZE_16x16,   -4,  -24, 2000,    0
    subsprite OAM_SIZE_8x16,    36,   24, 2024,    0
  FileAE52_Obj_701:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_32x32,   16,  -43, 1928,    0
    subsprite OAM_SIZE_8x32,    47,  -21, 1933,    0
    subsprite OAM_SIZE_8x8,     39,  -21, 1932,    0
    subsprite OAM_SIZE_16x16,   39,   11, 1934,    0
  FileAE52_Obj_709:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x32,   14,  -43, 1994,    0
  FileAE52_Obj_714:
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0
    subsprite OAM_SIZE_8x16,     6,  -15,  555,    0
  FileAE52_Obj_717:
    subsprite OAM_SIZE_32x32,  -14,  -33, 2116,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
  FileAE52_Obj_720:
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -14,  -15,  555,    0, xflip=1
  FileAE52_Obj_723:
    subsprite OAM_SIZE_32x32,   -8,  -39, 1432,    0
    subsprite OAM_SIZE_16x8,    -8,   -7, 1325,    0
    subsprite OAM_SIZE_8x8,      8,   -7, 1327,    0
    subsprite OAM_SIZE_32x8,   -12,  -10, 1532,    0
  FileAE52_Obj_727:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1372,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1436,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1295,    0
    subsprite OAM_SIZE_32x32,  -16,  -17, 2496,    0, xflip=1
  FileAE52_Obj_731:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1536,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1376,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1347,    0
    subsprite OAM_SIZE_32x8,   -25,  -10, 2440,    0
  FileAE52_Obj_735:
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 2509,    0
    subsprite OAM_SIZE_16x8,     0,    0, 2540,    0
    subsprite OAM_SIZE_8x32,     0,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -18,  -28, 2116,    0
    subsprite OAM_SIZE_16x32,   -6,  -39, 2510,    0
  FileAE52_Obj_742:
    subsprite OAM_SIZE_16x32,    1,  -30, 2560,    0, xflip=1
    subsprite OAM_SIZE_8x8,     17,  -14, 2888,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -14,  -23,  173,    0
    subsprite OAM_SIZE_32x16,  -17,  -30, 2336,    0
    subsprite OAM_SIZE_16x32,   -8,  -40, 2438,    0
    subsprite OAM_SIZE_32x16,  -16,  -13, 2476,    0
  FileAE52_Obj_748:
    subsprite OAM_SIZE_32x8,   -16,   -7, 1212,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,    1, 1632,    0, xflip=1
    subsprite OAM_SIZE_16x16,    8,  -19, 2600,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 1540,    0, xflip=1
  FileAE52_Obj_752:
    subsprite OAM_SIZE_16x32,    6,  -43, 2504,    0
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0
  FileAE52_Obj_755:
    subsprite OAM_SIZE_16x16,  -14,  -40, 2054,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -13,  -36, 2120,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
  FileAE52_Obj_759:
    subsprite OAM_SIZE_16x32,  -23,  -43, 2504,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0, xflip=1
  FileAE52_Obj_762:
    subsprite OAM_SIZE_32x32,   -8,  -39,   76,    0
    subsprite OAM_SIZE_16x8,    -5,   -7, 1524,    0
    subsprite OAM_SIZE_32x32,   -2,  -35, 2048,    0
  FileAE52_Obj_765:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1372,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1436,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1295,    0
    subsprite OAM_SIZE_32x32,    1,  -33, 2496,    0, yflip=1
  FileAE52_Obj_769:
    subsprite OAM_SIZE_16x32,    2,  -31,  204,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1376,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1347,    0
    subsprite OAM_SIZE_32x32,  -10,  -39, 1536,    0
    subsprite OAM_SIZE_32x32,   -9,  -29, 2496,    0, yflip=1
  FileAE52_Obj_774:
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 2509,    0
    subsprite OAM_SIZE_16x8,     0,    0, 2540,    0
    subsprite OAM_SIZE_8x32,     0,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -41,  576,    0
    subsprite OAM_SIZE_32x32,  -15,  -30, 2120,    0
    subsprite OAM_SIZE_16x32,   -6,  -39, 2510,    0
  FileAE52_Obj_781:
    subsprite OAM_SIZE_32x16,  -16,  -13, 2476,    0
    subsprite OAM_SIZE_16x16,  -13,  -24,   74,    0
    subsprite OAM_SIZE_32x16,  -17,  -30, 2336,    0
    subsprite OAM_SIZE_16x32,   -8,  -40, 2438,    0
    subsprite OAM_SIZE_32x32,  -14,  -33, 2048,    0, xflip=1
  FileAE52_Obj_786:
    subsprite OAM_SIZE_16x32,  -16,  -27,  139,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -16,  -16, 2509,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -16,    0, 2540,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -8,  -41,  655,    0, xflip=1
    subsprite OAM_SIZE_16x32,    0,  -41,  576,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -10,  -39, 2510,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -15,  -33, 2052,    0, xflip=1
  FileAE52_Obj_794:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    3,  -43, 2060,    0
  FileAE52_Obj_801:
    subsprite OAM_SIZE_16x16,    1,  -38,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -22,  396,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 2056,    0
  FileAE52_Obj_808:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 2056,    0
  FileAE52_Obj_814:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    3,  -43, 2060,    0
  FileAE52_Obj_820:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    3,  -43, 2060,    0
  FileAE52_Obj_826:
    subsprite OAM_SIZE_16x16,    1,  -38,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -22,  396,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 2056,    0
  FileAE52_Obj_832:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 2056,    0
  FileAE52_Obj_838:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    3,  -43, 2060,    0
  FileAE52_Obj_844:
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_32x32,  -16,  -33, 2052,    0
  FileAE52_Obj_852:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -35,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -19,  952,    0
    subsprite OAM_SIZE_32x32,  -15,  -30, 2048,    0
  FileAE52_Obj_860:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -3,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -3,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -17, 1211,    0
    subsprite OAM_SIZE_32x32,  -15,  -30, 2048,    0
  FileAE52_Obj_869:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_32x32,  -16,  -33, 2052,    0
  FileAE52_Obj_878:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_32x32,  -16,  -33, 2052,    0
  FileAE52_Obj_886:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -35,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -19,  952,    0
    subsprite OAM_SIZE_32x32,  -15,  -30, 2048,    0
  FileAE52_Obj_893:
    subsprite OAM_SIZE_16x32,    2,  -27,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -3,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -3,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -17, 1211,    0
    subsprite OAM_SIZE_32x32,  -15,  -30, 2048,    0
  FileAE52_Obj_901:
    subsprite OAM_SIZE_16x32,    2,  -29,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1211,    0
    subsprite OAM_SIZE_32x32,  -16,  -33, 2052,    0
  FileAE52_Obj_909:
    subsprite OAM_SIZE_32x32,  -11,  -35,  896,    0
    subsprite OAM_SIZE_16x32,   12,  -36, 2504,    0
    subsprite OAM_SIZE_32x8,   -11,   -3,  960,    0
    subsprite OAM_SIZE_8x8,      5,    5,  978,    0
  FileAE52_Obj_913:
    subsprite OAM_SIZE_32x32,  -11,  -30,  900,    0
    subsprite OAM_SIZE_32x32,   12,  -23, 2500,    0
    subsprite OAM_SIZE_16x8,    -3,    2,  964,    0
    subsprite OAM_SIZE_8x16,    21,   -6,  175,    0
  FileAE52_Obj_917:
    subsprite OAM_SIZE_32x32,  -14,  -19, 2376,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 2374,    0
    subsprite OAM_SIZE_8x32,     4,  -30,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -30,  579,    0
    subsprite OAM_SIZE_32x32,    7,  -34, 2056,    0
  FileAE52_Obj_922:
    subsprite OAM_SIZE_32x32,  -15,  -35,  840,    0
    subsprite OAM_SIZE_16x16,   -7,   -3,  526,    0
    subsprite OAM_SIZE_32x16,  -16,  -18, 2444,    0
  FileAE52_Obj_925:
    subsprite OAM_SIZE_32x32,  -14,  -30,  844,    0
    subsprite OAM_SIZE_16x8,   -14,    2,  430,    0
    subsprite OAM_SIZE_32x32,  -17,   -4, 2496,    0
  FileAE52_Obj_928:
    subsprite OAM_SIZE_16x32,    1,  -24,  204,    0
    subsprite OAM_SIZE_16x32,   -7,  -21, 2380,    0
    subsprite OAM_SIZE_8x8,      9,  -13, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -35,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -35,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -29,  966,    0
    subsprite OAM_SIZE_16x8,    -4,  -13,  952,    0
    subsprite OAM_SIZE_32x32,  -16,  -26, 2048,    0
  FileAE52_Obj_936:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_8x32,     1,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -38,  579,    0
    subsprite OAM_SIZE_16x32,    0,  -24,  516,    0
    subsprite OAM_SIZE_16x8,     0,    8, 1310,    0
  FileAE52_Obj_944:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x16,     4,  -26, 2131,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -1,  -42,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -26,  550,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -22, 2178,    0
  FileAE52_Obj_952:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,  -11,  -36, 2176,    0
    subsprite OAM_SIZE_8x32,     5,  -36,  578,    0
    subsprite OAM_SIZE_16x16,   -2,  -42,  518,    0
    subsprite OAM_SIZE_16x8,    -2,  -26,  550,    0
    subsprite OAM_SIZE_16x32,   -1,  -23, 2180,    0
    subsprite OAM_SIZE_8x8,     15,  -15, 2557,    0
  FileAE52_Obj_960:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,  -12,  -36, 2176,    0
    subsprite OAM_SIZE_8x32,     4,  -36,  578,    0
    subsprite OAM_SIZE_16x16,   -3,  -43,  518,    0
    subsprite OAM_SIZE_16x8,    -3,  -27,  550,    0
    subsprite OAM_SIZE_32x16,   -2,  -25, 1900,    0
  FileAE52_Obj_967:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x16,     3,  -25, 2131,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -11,  -36, 2176,    0
    subsprite OAM_SIZE_8x32,     5,  -36,  578,    0
    subsprite OAM_SIZE_16x16,   -1,  -42,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -26,  550,    0
    subsprite OAM_SIZE_32x32,   -1,  -41, 2056,    0
  FileAE52_Obj_975:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -38,  579,    0
    subsprite OAM_SIZE_16x16,    0,  -40,  640,    0
    subsprite OAM_SIZE_16x8,     0,  -24,  396,    0
    subsprite OAM_SIZE_32x32,    3,  -42, 2060,    0
  FileAE52_Obj_982:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    1,  -39,  640,    0
    subsprite OAM_SIZE_16x8,     1,  -23,  396,    0
    subsprite OAM_SIZE_32x32,    4,  -41, 2060,    0
  FileAE52_Obj_989:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     1,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -39,  576,    0
    subsprite OAM_SIZE_32x32,  -23,  -19, 1736,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
  FileAE52_Obj_997:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_32x32,  -22,  -26, 2112,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      2,  -17, 1211,    0
  FileAE52_Obj_1005:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x16,  -17,  -30, 2336,    0
    subsprite OAM_SIZE_32x32,  -18,  -29, 2116,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1179,    0
    subsprite OAM_SIZE_16x8,    -6,  -44, 1163,    0
    subsprite OAM_SIZE_8x8,      2,  -20, 1211,    0
  FileAE52_Obj_1012:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x16,  -18,  -31, 2336,    0
    subsprite OAM_SIZE_32x32,  -16,  -33, 2120,    0
    subsprite OAM_SIZE_16x16,   -7,  -38, 1179,    0
    subsprite OAM_SIZE_16x8,    -7,  -46, 1163,    0
    subsprite OAM_SIZE_8x8,      1,  -22, 1211,    0
  FileAE52_Obj_1019:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    1,  -29,  204,    0
    subsprite OAM_SIZE_32x16,  -18,  -32, 2336,    0
    subsprite OAM_SIZE_16x16,   -7,  -39, 1179,    0
    subsprite OAM_SIZE_16x8,    -7,  -47, 1163,    0
    subsprite OAM_SIZE_8x8,      1,  -23, 1211,    0
    subsprite OAM_SIZE_32x32,  -19,  -36, 2048,    0
  FileAE52_Obj_1027:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    0,  -28,  139,    0
    subsprite OAM_SIZE_8x32,     0,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -40,  576,    0
    subsprite OAM_SIZE_16x16,   -5,  -40,  966,    0
    subsprite OAM_SIZE_16x8,    -5,  -24,  952,    0
    subsprite OAM_SIZE_32x32,  -17,  -33, 2048,    0
  FileAE52_Obj_1035:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    3,  -26,  139,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -37,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -21,  952,    0
    subsprite OAM_SIZE_32x32,  -15,  -31, 2052,    0
  FileAE52_Obj_1043:
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 2374,    0
    subsprite OAM_SIZE_8x32,     4,  -30,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -30,  579,    0
    subsprite OAM_SIZE_32x32,    7,  -34, 2056,    0
  FileAE52_Obj_1048:
    subsprite OAM_SIZE_32x32,   -9,  -28,  388,    0
    subsprite OAM_SIZE_32x8,    -9,    4, 1984,    0
    subsprite OAM_SIZE_16x16,    5,   -1, 2600,    0
  FileAE52_Obj_1051:
    subsprite OAM_SIZE_16x32,    0,  -34, 2432,    0
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_8x32,     2,  -31,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -31,  579,    0
    subsprite OAM_SIZE_16x32,   -1,  -17,  520,    0
    subsprite OAM_SIZE_16x8,     0,   15, 1310,    0
  FileAE52_Obj_1057:
    subsprite OAM_SIZE_16x32,    1,  -21,  204,    0
    subsprite OAM_SIZE_16x32,  -10,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      6,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -32,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -32,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -30,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -14,  952,    0
    subsprite OAM_SIZE_32x32,  -16,  -23, 2048,    0
  FileAE52_Obj_1065:
    subsprite OAM_SIZE_32x32,  -11,  -26,  384,    0
    subsprite OAM_SIZE_16x8,   -11,    6,  412,    0
    subsprite OAM_SIZE_8x8,      5,    6, 1910,    0
    subsprite OAM_SIZE_32x8,   -18,    5, 1532,    0
  FileAE52_Obj_1069:
    subsprite OAM_SIZE_16x32,    0,  -29,  130,    0
    subsprite OAM_SIZE_16x32,  -10,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      6,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -35,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -35,  576,    0
    subsprite OAM_SIZE_16x32,   -1,  -29, 2434,    0
    subsprite OAM_SIZE_32x32,  -23,  -15, 1736,    0
  FileAE52_Obj_1076:
    subsprite OAM_SIZE_32x32,  -11,  -35,  332,    0
    subsprite OAM_SIZE_32x8,   -10,  -25, 2456,    0
    subsprite OAM_SIZE_16x8,   -11,   -3,  976,    0
    subsprite OAM_SIZE_16x8,    -3,    5, 1010,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  979,    0
  FileAE52_Obj_1081:
    subsprite OAM_SIZE_32x32,  -18,  -37,  392,    0
    subsprite OAM_SIZE_32x8,   -30,  -23, 2440,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  992,    0
    subsprite OAM_SIZE_8x8,      6,   -5,  994,    0
  FileAE52_Obj_1085:
    subsprite OAM_SIZE_16x32,   -7,  -22,  768,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x16,    0,  -38,  640,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  396,    0
    subsprite OAM_SIZE_32x32,    3,  -40, 2060,    0
  FileAE52_Obj_1091:
    subsprite OAM_SIZE_16x8,   -16,  -30, 1394,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -5,  -41, 2374,    0
    subsprite OAM_SIZE_16x32,   -8,  -21, 2372,    0
    subsprite OAM_SIZE_16x16,   -8,  -31, 2406,    0
    subsprite OAM_SIZE_16x32,    4,  -46, 2318,    0
  FileAE52_Obj_1096:
    subsprite OAM_SIZE_16x8,   -17,  -34, 1394,    0
    subsprite OAM_SIZE_16x16,   -7,  -43, 2374,    0
    subsprite OAM_SIZE_16x32,   -8,  -21, 2312,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2406,    0
    subsprite OAM_SIZE_16x32,    3,  -47, 2318,    0
  FileAE52_Obj_1101:
    subsprite OAM_SIZE_16x16,  -17,  -40, 2306,    0
    subsprite OAM_SIZE_16x32,   -7,  -22,  768,    0
    subsprite OAM_SIZE_16x16,   -7,  -39, 2374,    0
    subsprite OAM_SIZE_8x32,    -2,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -18,  -36,  579,    0
    subsprite OAM_SIZE_32x32,    2,  -41, 2056,    0
  FileAE52_Obj_1107:
    subsprite OAM_SIZE_16x16,  -22,  -38, 2306,    0
    subsprite OAM_SIZE_16x16,   -3,  -39,  206,    0
    subsprite OAM_SIZE_16x8,    -3,  -23,  238,    0
    subsprite OAM_SIZE_32x32,  -21,  -19, 2314,    0
    subsprite OAM_SIZE_32x32,  -19,  -37, 2124,    0
    subsprite OAM_SIZE_32x32,    8,  -50, 2308,    0
    subsprite OAM_SIZE_8x16,     0,  -34, 1964,    0
  FileAE52_Obj_1114:
    subsprite OAM_SIZE_16x16,  -20,  -40, 2304,    0
    subsprite OAM_SIZE_32x32,  -21,  -19, 2368,    0
    subsprite OAM_SIZE_16x16,   -1,  -40,  206,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  238,    0
    subsprite OAM_SIZE_32x32,  -17,  -38, 2124,    0
    subsprite OAM_SIZE_32x32,   11,  -52, 2308,    0
    subsprite OAM_SIZE_8x16,     3,  -36, 1964,    0
  FileAE52_Obj_1121:
    subsprite OAM_SIZE_16x16,  -10,  -35, 2240,    0
    subsprite OAM_SIZE_32x32,  -14,  -18,  836,    0
    subsprite OAM_SIZE_8x32,    -1,  -33,  581,    0
    subsprite OAM_SIZE_16x32,  -17,  -33,  579,    0
    subsprite OAM_SIZE_16x16,   -2,  -35,  640,    0
    subsprite OAM_SIZE_16x8,    -2,  -19,  396,    0
    subsprite OAM_SIZE_32x32,    1,  -37, 2060,    0
  FileAE52_Obj_1128:
    subsprite OAM_SIZE_16x16,  -10,  -33, 2240,    0
    subsprite OAM_SIZE_32x32,  -12,  -19,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -34,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -34,  579,    0
    subsprite OAM_SIZE_16x16,   -1,  -36,  640,    0
    subsprite OAM_SIZE_16x8,    -1,  -20,  396,    0
    subsprite OAM_SIZE_32x32,    3,  -38, 2056,    0
  FileAE52_Obj_1135:
    subsprite OAM_SIZE_16x32,   -1,  -34,  204,    0
    subsprite OAM_SIZE_8x32,     5,  -23,    6,    0
    subsprite OAM_SIZE_16x32,  -11,  -23,    4,    0
    subsprite OAM_SIZE_8x32,    -2,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -18,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -9,  -38, 1179,    0
    subsprite OAM_SIZE_16x8,    -9,  -46, 1163,    0
    subsprite OAM_SIZE_8x8,     -1,  -22, 1211,    0
    subsprite OAM_SIZE_32x32,  -19,  -32, 2048,    0
  FileAE52_Obj_1144:
    subsprite OAM_SIZE_16x16,   -1,  -36, 2274,    0
    subsprite OAM_SIZE_32x32,  -13,  -25,    0,    0
    subsprite OAM_SIZE_8x32,    -3,  -43,  655,    0
    subsprite OAM_SIZE_16x32,  -19,  -43,  576,    0
    subsprite OAM_SIZE_16x16,  -11,  -41, 1179,    0
    subsprite OAM_SIZE_16x8,   -11,  -49, 1163,    0
    subsprite OAM_SIZE_8x8,     -3,  -25, 1211,    0
    subsprite OAM_SIZE_16x32,  -11,  -46, 2186,    0
  FileAE52_Obj_1152:
    subsprite OAM_SIZE_16x16,   -1,  -38, 2274,    0
    subsprite OAM_SIZE_32x32,  -17,  -26, 2252,    0
    subsprite OAM_SIZE_8x32,    -4,  -44,  655,    0
    subsprite OAM_SIZE_16x32,  -20,  -44,  576,    0
    subsprite OAM_SIZE_16x16,  -13,  -43, 1179,    0
    subsprite OAM_SIZE_16x8,   -13,  -51, 1163,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 1211,    0
    subsprite OAM_SIZE_16x32,  -12,  -47, 2186,    0
  FileAE52_Obj_1160:
    subsprite OAM_SIZE_8x32,     5,  -23,    6,    0
    subsprite OAM_SIZE_16x32,  -11,  -23,    4,    0
    subsprite OAM_SIZE_16x16,   -1,  -44, 2240,    0
    subsprite OAM_SIZE_8x32,    -2,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -18,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -8,  -42,  966,    0
    subsprite OAM_SIZE_16x8,    -8,  -26,  952,    0
    subsprite OAM_SIZE_32x32,  -19,  -33, 2052,    0
  FileAE52_Obj_1168:
    subsprite OAM_SIZE_16x16,   -6,  -50, 2240,    0
    subsprite OAM_SIZE_16x32,  -13,  -26,   68,    0
    subsprite OAM_SIZE_16x32,  -14,  -39, 2176,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  578,    0
    subsprite OAM_SIZE_16x16,   -3,  -25, 2244,    0
    subsprite OAM_SIZE_16x16,    5,   -9, 2276,    0
    subsprite OAM_SIZE_16x16,   13,    7, 2272,    0
    subsprite OAM_SIZE_16x16,   -1,  -42,  524,    0
    subsprite OAM_SIZE_16x8,    -1,  -26,  254,    0
    subsprite OAM_SIZE_8x16,    -9,  -42,  523,    0
  FileAE52_Obj_1178:
    subsprite OAM_SIZE_16x32,  -11,  -26,   70,    0
    subsprite OAM_SIZE_16x16,   -4,  -48, 2242,    0
    subsprite OAM_SIZE_16x32,  -12,  -37, 2176,    0
    subsprite OAM_SIZE_8x32,     4,  -37,  578,    0
    subsprite OAM_SIZE_16x32,   -1,  -43,  972,    0
    subsprite OAM_SIZE_16x16,    0,  -22, 2244,    0
    subsprite OAM_SIZE_16x16,    8,   -6, 2276,    0
    subsprite OAM_SIZE_16x16,   16,   10, 2272,    0
  FileAE52_Obj_1186:
    subsprite OAM_SIZE_16x32,  -13,  -26,   66,    0
    subsprite OAM_SIZE_16x16,   -1,  -45, 2240,    0
    subsprite OAM_SIZE_16x32,  -18,  -42,  576,    0
    subsprite OAM_SIZE_8x32,    -2,  -42,  655,    0
    subsprite OAM_SIZE_16x16,   -8,  -43,  966,    0
    subsprite OAM_SIZE_16x8,    -8,  -27,  952,    0
    subsprite OAM_SIZE_32x32,  -19,  -34, 2052,    0
  FileAE52_Obj_1193:
    subsprite OAM_SIZE_16x32,    1,  -31,  204,    0
    subsprite OAM_SIZE_16x32,  -14,  -22,   10,    0
    subsprite OAM_SIZE_8x32,     2,  -22,   12,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  576,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -7,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 1211,    0
    subsprite OAM_SIZE_32x32,  -17,  -29, 2048,    0
  FileAE52_Obj_1202:
    subsprite OAM_SIZE_32x32,  -13,  -36, 1092,    0
    subsprite OAM_SIZE_32x16,  -13,  -12, 1168,    0
    subsprite OAM_SIZE_16x8,    -3,   -2, 1648,    0
  FileAE52_Obj_1205:
    subsprite OAM_SIZE_32x32,  -13,  -37, 1096,    0
    subsprite OAM_SIZE_32x8,   -13,   -5, 1152,    0
    subsprite OAM_SIZE_16x8,    -5,    3,  566,    0
    subsprite OAM_SIZE_16x16,   -2,   -8, 2602,    0
  FileAE52_Obj_1209:
    subsprite OAM_SIZE_32x32,  -17,  -32,  712,    0
    subsprite OAM_SIZE_16x8,   -17,  -10, 1992,    0
  FileAE52_Obj_1211:
    subsprite OAM_SIZE_32x32,  -13,  -33,  716,    0
    subsprite OAM_SIZE_16x16,  -13,   -9,  736,    0
    subsprite OAM_SIZE_32x8,   -25,   -8,  444,    0
  FileAE52_Obj_1214:
    subsprite OAM_SIZE_16x16,    1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -23,  550,    0
    subsprite OAM_SIZE_16x32,  -10,  -37,  652,    0
    subsprite OAM_SIZE_8x32,     6,  -37,  654,    0
    subsprite OAM_SIZE_16x32,   -6,  -42, 2562,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2889,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  556,    0
    subsprite OAM_SIZE_8x16,     6,   -5,  558,    0
  FileAE52_Obj_1222:
    subsprite OAM_SIZE_16x32,  -16,  -40, 2628,    0
    subsprite OAM_SIZE_32x32,  -16,  -33,  908,    0
    subsprite OAM_SIZE_16x16,   -4,  -31, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -39, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -15, 1211,    0
    subsprite OAM_SIZE_16x8,   -16,   -1,  428,    0
    subsprite OAM_SIZE_8x8,      0,   -1, 1911,    0
  FileAE52_Obj_1229:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  192,    0
    subsprite OAM_SIZE_16x32,   -8,  -43, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 2889,    0
  FileAE52_Obj_1238:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -1,  -26,  194,    0
    subsprite OAM_SIZE_16x32,   -7,  -41, 2562,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 2889,    0
  FileAE52_Obj_1247:
    subsprite OAM_SIZE_16x32,  -11,  -35,  202,    0
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -27,  196,    0
    subsprite OAM_SIZE_16x32,   -8,  -42, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 2889,    0
  FileAE52_Obj_1256:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  194,    0
    subsprite OAM_SIZE_16x32,   -8,  -43, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 2889,    0
  FileAE52_Obj_1264:
    subsprite OAM_SIZE_16x16,   -1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  192,    0
    subsprite OAM_SIZE_16x32,   -8,  -43, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 2889,    0
  FileAE52_Obj_1272:
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -36,  579,    0
    subsprite OAM_SIZE_16x32,   -1,  -26,  194,    0
    subsprite OAM_SIZE_16x32,   -7,  -41, 2562,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 2889,    0
  FileAE52_Obj_1280:
    subsprite OAM_SIZE_16x32,  -11,  -35,  202,    0
    subsprite OAM_SIZE_16x16,   -1,  -38,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -27,  196,    0
    subsprite OAM_SIZE_16x32,   -8,  -42, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 2889,    0
  FileAE52_Obj_1289:
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   -2,  -28,  194,    0
    subsprite OAM_SIZE_16x32,   -8,  -43, 2562,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 2889,    0
  FileAE52_Obj_1297:
    subsprite OAM_SIZE_16x32,  -17,  -42, 2628,    0
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,  -16,  -25,  135,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
  FileAE52_Obj_1306:
    subsprite OAM_SIZE_16x32,  -16,  -40, 2628,    0
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
    subsprite OAM_SIZE_8x32,    -6,  -22,  132,    0
  FileAE52_Obj_1316:
    subsprite OAM_SIZE_16x32,  -17,  -41, 2628,    0
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -7,  -23,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
  FileAE52_Obj_1326:
    subsprite OAM_SIZE_16x32,  -17,  -42, 2628,    0
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
    subsprite OAM_SIZE_8x32,    -8,  -25,  132,    0
  FileAE52_Obj_1336:
    subsprite OAM_SIZE_16x32,  -17,  -42, 2628,    0
    subsprite OAM_SIZE_16x32,   -5,  -35,  137,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,  -16,  -25,  135,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 1211,    0
  FileAE52_Obj_1345:
    subsprite OAM_SIZE_16x32,  -16,  -40, 2628,    0
    subsprite OAM_SIZE_16x32,   -4,  -31,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -4,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -16, 1211,    0
    subsprite OAM_SIZE_8x32,    -6,  -22,  132,    0
  FileAE52_Obj_1354:
    subsprite OAM_SIZE_16x32,  -17,  -41, 2628,    0
    subsprite OAM_SIZE_16x32,    3,  -32,  130,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -7,  -23,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -40, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1211,    0
  FileAE52_Obj_1363:
    subsprite OAM_SIZE_16x32,  -17,  -42, 2628,    0
    subsprite OAM_SIZE_16x32,   -6,  -34,  133,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
    subsprite OAM_SIZE_8x32,    -8,  -25,  132,    0
  FileAE52_Obj_1372:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -18,  -40,  264,    0
    subsprite OAM_SIZE_16x32,  -21,  -40, 3014,    0
  FileAE52_Obj_1376:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -12,  -39,  268,    0
    subsprite OAM_SIZE_32x16,  -26,  -17, 2892,    0
  FileAE52_Obj_1380:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,   -8,  -42,  320,    0
    subsprite OAM_SIZE_16x16,    8,  -18,  230,    0
    subsprite OAM_SIZE_32x16,   -4,  -12, 2924,    0
  FileAE52_Obj_1385:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -16,  -47,  324,    0
    subsprite OAM_SIZE_16x16,   16,  -39,  232,    0
    subsprite OAM_SIZE_32x32,   20,  -54, 2956,    0
    subsprite OAM_SIZE_32x16,   20,  -22, 3020,    0
  FileAE52_Obj_1391:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
    subsprite OAM_SIZE_16x16,   31,  -57, 2905,    0
    subsprite OAM_SIZE_16x16,   39,  -49, 2922,    0
  FileAE52_Obj_1397:
    subsprite OAM_SIZE_32x32,  -12,  -20,  770,    0
    subsprite OAM_SIZE_32x32,  -14,  -44, 2880,    0
  FileAE52_Obj_1399:
    subsprite OAM_SIZE_16x32,   -7,  -23,  768,    0
    subsprite OAM_SIZE_32x32,   -8,  -47, 2884,    0
    subsprite OAM_SIZE_16x8,    -8,  -15, 2936,    0
  FileAE52_Obj_1402:
    subsprite OAM_SIZE_16x32,   -7,  -23,  768,    0
    subsprite OAM_SIZE_32x32,  -15,  -42, 2828,    0
    subsprite OAM_SIZE_8x32,    11,  -50, 2954,    0
  FileAE52_Obj_1405:
    subsprite OAM_SIZE_16x32,   -7,  -23,  768,    0
    subsprite OAM_SIZE_8x32,    10,  -49, 2954,    0
    subsprite OAM_SIZE_32x32,  -15,  -42, 2828,    0
  FileAE52_Obj_1408:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -15,  -49, 2948,    0
    subsprite OAM_SIZE_32x32,  -22,  -40,  448,    0
    subsprite OAM_SIZE_16x16,    2,  -16,  672,    0
  FileAE52_Obj_1413:
    subsprite OAM_SIZE_8x32,   -14,  -51,  522,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -21,  -37,  452,    0
    subsprite OAM_SIZE_16x16,    3,  -21,  460,    0
  FileAE52_Obj_1418:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -9,  -37,  456,    0
    subsprite OAM_SIZE_16x16,  -25,  -21,  462,    0
    subsprite OAM_SIZE_32x32,  -40,  -37, 2944,    0
  FileAE52_Obj_1423:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -8,  -38,  256,    0
    subsprite OAM_SIZE_16x16,    8,   -6,  492,    0
    subsprite OAM_SIZE_32x32,   -6,   -4, 3008,    0
    subsprite OAM_SIZE_16x32,   26,   -4, 3012,    0
  FileAE52_Obj_1429:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x16,   19,  -26,  198,    0
    subsprite OAM_SIZE_32x32,   18,    1, 2950,    0
  FileAE52_Obj_1435:
    subsprite OAM_SIZE_16x32,  -13,  -23,   10,    0
    subsprite OAM_SIZE_8x32,     3,  -23,   12,    0
    subsprite OAM_SIZE_32x32,  -11,  -30, 2816,    0
    subsprite OAM_SIZE_16x16,   -7,  -43, 1163,    0
  FileAE52_Obj_1439:
    subsprite OAM_SIZE_16x32,  -10,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     6,  -24,    9,    0
    subsprite OAM_SIZE_32x32,  -12,  -33, 2820,    0
    subsprite OAM_SIZE_16x16,   -6,  -45, 1163,    0
  FileAE52_Obj_1443:
    subsprite OAM_SIZE_16x16,   -5,  -45, 1163,    0
    subsprite OAM_SIZE_16x32,  -10,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     6,  -24,    9,    0
    subsprite OAM_SIZE_32x32,  -14,  -38, 2824,    0
    subsprite OAM_SIZE_8x32,    12,  -31, 2955,    0
  FileAE52_Obj_1448:
    subsprite OAM_SIZE_16x16,   -5,  -45, 1163,    0
    subsprite OAM_SIZE_16x32,  -10,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     6,  -24,    9,    0
    subsprite OAM_SIZE_32x32,  -14,  -38, 2824,    0
    subsprite OAM_SIZE_8x32,    11,  -31, 2955,    0
  FileAE52_Obj_1453:
    subsprite OAM_SIZE_16x32,   -4,  -43, 2574,    0
    subsprite OAM_SIZE_32x32,  -11,  -35,  896,    0
    subsprite OAM_SIZE_32x8,   -11,   -3,  960,    0
    subsprite OAM_SIZE_8x8,      5,    5,  978,    0
  FileAE52_Obj_1457:
    subsprite OAM_SIZE_32x32,   -2,  -38, 3136,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -11,  -30,  900,    0
    subsprite OAM_SIZE_16x8,    -3,    2,  964,    0
    subsprite OAM_SIZE_8x16,    21,   -6,  175,    0
  FileAE52_Obj_1461:
    subsprite OAM_SIZE_32x32,   -4,  -28, 2696,    0
    subsprite OAM_SIZE_32x32,  -14,  -19, 2376,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 2374,    0
    subsprite OAM_SIZE_8x32,     4,  -30,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -30,  579,    0
  FileAE52_Obj_1466:
    subsprite OAM_SIZE_32x16,   -1,  -29, 3052,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -15,  -35,  840,    0
    subsprite OAM_SIZE_16x16,   -7,   -3,  526,    0
  FileAE52_Obj_1469:
    subsprite OAM_SIZE_32x32,    3,  -24, 3136,    0
    subsprite OAM_SIZE_32x32,  -14,  -30,  844,    0
    subsprite OAM_SIZE_16x8,   -14,    2,  430,    0
  FileAE52_Obj_1472:
    subsprite OAM_SIZE_16x32,   -7,  -21, 2380,    0
    subsprite OAM_SIZE_8x8,      9,  -13, 2556,    0
    subsprite OAM_SIZE_16x32,  -15,  -35,  576,    0
    subsprite OAM_SIZE_8x32,     1,  -35,  655,    0
    subsprite OAM_SIZE_16x16,   -4,  -29,  966,    0
    subsprite OAM_SIZE_16x8,    -4,  -13,  952,    0
    subsprite OAM_SIZE_32x32,  -10,  -23, 2636,    0
  FileAE52_Obj_1479:
    subsprite OAM_SIZE_16x16,   -1,  -42,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -26,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,   -8,  -37, 2696,    0
    subsprite OAM_SIZE_8x16,     6,  -36, 2025,    0
  FileAE52_Obj_1487:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -7,  -36, 2700,    0
    subsprite OAM_SIZE_8x16,     8,  -34, 2025,    0
  FileAE52_Obj_1495:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_32x32,   -7,  -36, 2696,    0
    subsprite OAM_SIZE_8x16,     8,  -34, 2025,    0
  FileAE52_Obj_1503:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,   -8,  -37, 2696,    0
    subsprite OAM_SIZE_8x16,     7,  -35, 2025,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  788,    0
  FileAE52_Obj_1511:
    subsprite OAM_SIZE_16x16,   -1,  -42,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -26,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,   -8,  -37, 2696,    0
    subsprite OAM_SIZE_8x16,     6,  -36, 2025,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  792,    0
  FileAE52_Obj_1519:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -7,  -36, 2700,    0
    subsprite OAM_SIZE_8x16,     8,  -34, 2025,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  796,    0
  FileAE52_Obj_1527:
    subsprite OAM_SIZE_16x16,    1,  -40,  518,    0
    subsprite OAM_SIZE_16x8,     1,  -24,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -7,  -36, 2696,    0
    subsprite OAM_SIZE_8x16,     8,  -34, 2025,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  850,    0
  FileAE52_Obj_1535:
    subsprite OAM_SIZE_16x16,    0,  -41,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -25,  550,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_32x32,   -8,  -37, 2696,    0
    subsprite OAM_SIZE_8x16,     7,  -35, 2025,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  854,    0
  FileAE52_Obj_1543:
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,   -9,  -29, 2632,    0
    subsprite OAM_SIZE_16x16,   -4,  -36, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -44, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -20, 1211,    0
  FileAE52_Obj_1550:
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -8,  -27, 2636,    0
    subsprite OAM_SIZE_16x16,   -2,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -2,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      6,  -17, 1211,    0
  FileAE52_Obj_1558:
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -8,  -27, 2632,    0
    subsprite OAM_SIZE_16x16,   -2,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -2,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      6,  -17, 1211,    0
  FileAE52_Obj_1566:
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,   -9,  -29, 2632,    0
    subsprite OAM_SIZE_16x16,   -3,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -3,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1211,    0
  FileAE52_Obj_1574:
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,   -9,  -29, 2632,    0
    subsprite OAM_SIZE_16x16,   -4,  -36, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -44, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -20, 1211,    0
  FileAE52_Obj_1581:
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -8,  -27, 2636,    0
    subsprite OAM_SIZE_16x16,   -2,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -2,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      6,  -17, 1211,    0
  FileAE52_Obj_1588:
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -8,  -27, 2632,    0
    subsprite OAM_SIZE_16x16,   -2,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -2,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      6,  -17, 1211,    0
  FileAE52_Obj_1595:
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_32x32,   -9,  -29, 2632,    0
    subsprite OAM_SIZE_16x16,   -3,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -3,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1211,    0
  FileAE52_Obj_1602:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    0,  -38,  518,    0
    subsprite OAM_SIZE_16x8,     0,  -22,  550,    0
    subsprite OAM_SIZE_32x32,  -18,  -42, 2756,    0
    subsprite OAM_SIZE_16x32,    0,  -26,  196,    0
  FileAE52_Obj_1608:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -11,  -47, 2760,    0
    subsprite OAM_SIZE_32x8,   -11,  -15, 1528,    0
  FileAE52_Obj_1612:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    3,  -44, 2764,    0
    subsprite OAM_SIZE_16x16,   -1,  -39,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -23,  550,    0
    subsprite OAM_SIZE_8x32,    -1,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -17,  -36,  579,    0
  FileAE52_Obj_1619:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,   -1,  -41,  518,    0
    subsprite OAM_SIZE_16x8,    -1,  -25,  550,    0
    subsprite OAM_SIZE_8x32,     0,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -8,  -36, 2696,    0
    subsprite OAM_SIZE_8x16,     6,  -35, 2025,    0
    subsprite OAM_SIZE_8x16,     3,  -14,  603,    0
  FileAE52_Obj_1628:
    subsprite OAM_SIZE_16x32,  -15,  -44, 2624,    0
    subsprite OAM_SIZE_8x16,     1,  -44,  107,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,    -2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -18,  -39,  576,    0
    subsprite OAM_SIZE_16x32,  -11,  -23,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -31, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -39, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1211,    0
  FileAE52_Obj_1638:
    subsprite OAM_SIZE_32x16,   -6,  -38, 2692,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,    -1,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -17,  -39,  576,    0
    subsprite OAM_SIZE_16x16,  -10,  -19, 2724,    0
    subsprite OAM_SIZE_16x16,   -6,  -31, 1179,    0
    subsprite OAM_SIZE_16x8,    -6,  -39, 1163,    0
    subsprite OAM_SIZE_8x8,      2,  -15, 1211,    0
  FileAE52_Obj_1647:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    9,  -35, 2626,    0
    subsprite OAM_SIZE_8x8,     25,  -19, 2890,    0
    subsprite OAM_SIZE_8x32,     0,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -39,  576,    0
    subsprite OAM_SIZE_16x16,   -9,  -23, 2472,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1179,    0
    subsprite OAM_SIZE_16x8,    -5,  -41, 1163,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1211,    0
  FileAE52_Obj_1657:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     0,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -40,  576,    0
    subsprite OAM_SIZE_32x32,  -10,  -28, 2632,    0
    subsprite OAM_SIZE_16x16,   -4,  -34, 1179,    0
    subsprite OAM_SIZE_16x8,    -4,  -42, 1163,    0
    subsprite OAM_SIZE_8x8,      4,  -18, 1211,    0
  FileAE52_Obj_1665:
    subsprite OAM_SIZE_16x32,   -4,  -40, 2574,    0
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 2374,    0
    subsprite OAM_SIZE_8x32,     4,  -30,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -30,  579,    0
    subsprite OAM_SIZE_16x16,    7,  -18, 2472,    0
  FileAE52_Obj_1671:
    subsprite OAM_SIZE_32x16,   -1,  -14, 3052,    0, xflip=1
    subsprite OAM_SIZE_32x32,   -9,  -28,  388,    0
    subsprite OAM_SIZE_32x8,    -9,    4, 1984,    0
  FileAE52_Obj_1674:
    subsprite OAM_SIZE_32x32,  -13,  -38, 2944,    0, xflip=1
    subsprite OAM_SIZE_16x32,    0,  -34, 2432,    0
    subsprite OAM_SIZE_32x32,  -15,  -18, 2376,    0
    subsprite OAM_SIZE_8x32,     2,  -31,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -31,  579,    0
    subsprite OAM_SIZE_16x32,    0,  -20,  196,    0
  FileAE52_Obj_1680:
    subsprite OAM_SIZE_16x32,    1,  -21,  204,    0
    subsprite OAM_SIZE_16x32,    4,  -29, 2574,    0
    subsprite OAM_SIZE_16x32,  -10,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      6,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -32,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -32,  576,    0
    subsprite OAM_SIZE_16x16,   -2,  -30,  966,    0
    subsprite OAM_SIZE_16x8,    -2,  -14,  952,    0
    subsprite OAM_SIZE_16x16,  -12,  -12,  173,    0
  FileAE52_Obj_1689:
    subsprite OAM_SIZE_32x16,   -4,   -7, 3052,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_32x32,  -11,  -26,  384,    0
    subsprite OAM_SIZE_16x8,   -11,    6,  412,    0
    subsprite OAM_SIZE_8x8,      5,    6, 1910,    0
  FileAE52_Obj_1693:
    subsprite OAM_SIZE_32x32,   -5,  -32, 2944,    0, xflip=1
    subsprite OAM_SIZE_16x32,    0,  -29,  130,    0
    subsprite OAM_SIZE_16x32,  -10,  -22, 2380,    0
    subsprite OAM_SIZE_8x8,      6,  -14, 2556,    0
    subsprite OAM_SIZE_8x32,     1,  -35,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -35,  576,    0
    subsprite OAM_SIZE_16x32,   -1,  -29, 2434,    0
    subsprite OAM_SIZE_8x32,    -8,  -19,  132,    0
  FileAE52_Obj_1701:
    subsprite OAM_SIZE_32x32,  -11,  -35,  332,    0
    subsprite OAM_SIZE_16x32,  -19,  -38, 3016,    0
    subsprite OAM_SIZE_16x8,   -11,   -3,  976,    0
    subsprite OAM_SIZE_16x8,    -3,    5, 1010,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  979,    0
  FileAE52_Obj_1706:
    subsprite OAM_SIZE_32x16,  -20,  -35, 3052,    0
    subsprite OAM_SIZE_32x32,  -18,  -37,  392,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  992,    0
    subsprite OAM_SIZE_8x8,      6,   -5,  994,    0
  FileAE52_Obj_1710:
    subsprite OAM_SIZE_8x32,    -6,  -37, 1030,    0
    subsprite OAM_SIZE_8x16,   -14,  -21, 1028,    0
    subsprite OAM_SIZE_16x16,    2,  -37,  814,    0
    subsprite OAM_SIZE_8x8,     10,  -21, 1066,    0
    subsprite OAM_SIZE_16x16,  -14,  -13,  996,    0
    subsprite OAM_SIZE_8x8,      2,   -5,  995,    0
    subsprite OAM_SIZE_16x16,  -15,  -11, 3084,    0
  FileAE52_Obj_1717:
    subsprite OAM_SIZE_32x32,  -14,  -39, 1088,    0
    subsprite OAM_SIZE_16x16,  -14,   -7,  782,    0
    subsprite OAM_SIZE_8x16,     2,   -7,  559,    0
    subsprite OAM_SIZE_16x32,  -13,  -16, 3018,    0
  FileAE52_Obj_1721:
    subsprite OAM_SIZE_32x32,  -13,  -36, 1092,    0
    subsprite OAM_SIZE_32x16,  -13,  -12, 1168,    0
    subsprite OAM_SIZE_16x32,  -10,  -27, 3072,    0
  FileAE52_Obj_1724:
    subsprite OAM_SIZE_32x32,  -13,  -37, 1096,    0
    subsprite OAM_SIZE_32x32,  -15,  -40, 3074,    0
    subsprite OAM_SIZE_32x8,   -13,   -5, 1152,    0
    subsprite OAM_SIZE_16x8,    -5,    3,  566,    0
  FileAE52_Obj_1728:
    subsprite OAM_SIZE_16x32,   -4,  -33,  650,    0
    subsprite OAM_SIZE_8x32,   -12,  -33,  649,    0
    subsprite OAM_SIZE_8x8,     12,  -25,  159,    0
    subsprite OAM_SIZE_16x16,  -12,   -9,  704,    0
    subsprite OAM_SIZE_8x16,   -14,  -14,  584,    0
  FileAE52_Obj_1733:
    subsprite OAM_SIZE_32x32,  -14,  -35,  708,    0
    subsprite OAM_SIZE_16x16,  -14,  -11,  706,    0
    subsprite OAM_SIZE_8x32,   -14,  -25, 3087,    0
  FileAE52_Obj_1736:
    subsprite OAM_SIZE_32x32,  -17,  -32,  712,    0
    subsprite OAM_SIZE_16x32,  -17,  -35, 3078,    0
  FileAE52_Obj_1738:
    subsprite OAM_SIZE_32x32,  -13,  -33,  716,    0
    subsprite OAM_SIZE_16x16,  -13,   -9,  736,    0
    subsprite OAM_SIZE_16x32,  -16,  -40, 3080,    0
  FileAE52_Obj_1741:
    subsprite OAM_SIZE_32x32,  -14,  -39, 1608,    0
    subsprite OAM_SIZE_32x16,  -14,   -7, 1612,    0
    subsprite OAM_SIZE_16x32,   -5,  -43, 2562,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 2889,    0
  FileAE52_Obj_1745:
    subsprite OAM_SIZE_8x32,   -16,  -35, 2436,    0
    subsprite OAM_SIZE_8x32,     8,  -35, 2437,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
    subsprite OAM_SIZE_32x32,  -18,  -42, 3140,    0
  FileAE52_Obj_1750:
    subsprite OAM_SIZE_32x32,  -18,  -39, 1608,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -18,   -7, 1612,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -11,  -43, 2562,    0, xflip=1
    subsprite OAM_SIZE_8x8,      5,  -35, 2889,    0, xflip=1
  FileAE52_Obj_1754:
    subsprite OAM_SIZE_32x32,   -8,  -39, 1432,    0
    subsprite OAM_SIZE_16x32,  -10,  -43, 3144,    0
    subsprite OAM_SIZE_8x8,      6,  -43, 1633,    0
    subsprite OAM_SIZE_16x8,    -8,   -7, 1325,    0
    subsprite OAM_SIZE_8x8,      8,   -7, 1327,    0
  FileAE52_Obj_1759:
    subsprite OAM_SIZE_32x32,  -10,  -39, 1372,    0
    subsprite OAM_SIZE_16x32,  -13,  -42, 3150,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1436,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1295,    0
  FileAE52_Obj_1763:
    subsprite OAM_SIZE_16x32,  -13,  -44, 3148,    0
    subsprite OAM_SIZE_32x32,  -10,  -39, 1536,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1376,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1347,    0
  FileAE52_Obj_1767:
    subsprite OAM_SIZE_16x32,  -17,  -42, 2628,    0
    subsprite OAM_SIZE_32x32,  -16,  -39, 1540,    0
    subsprite OAM_SIZE_32x8,   -16,   -7, 1212,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1632,    0
  FileAE52_Obj_1771:
    subsprite OAM_SIZE_32x32,  -14,  -41, 3140,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 1544,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 1604,    0
  FileAE52_Obj_1774:
    subsprite OAM_SIZE_16x32,    1,  -42, 2628,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 1540,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,    1, 1632,    0, xflip=1
    subsprite OAM_SIZE_32x8,   -16,   -7, 1212,    0, xflip=1
  FileAE52_Obj_1778:
    subsprite OAM_SIZE_16x32,    2,  -41, 3082,    0
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0
  FileAE52_Obj_1781:
    subsprite OAM_SIZE_8x32,    -4,  -44, 3086,    0
    subsprite OAM_SIZE_32x32,  -13,  -36, 2120,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
  FileAE52_Obj_1785:
    subsprite OAM_SIZE_16x32,  -18,  -41, 3082,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0, xflip=1
  FileAE52_Obj_1788:
    subsprite OAM_SIZE_16x16,    0,  -31, 1493,    0
    subsprite OAM_SIZE_32x32,   -8,  -39,   76,    0
    subsprite OAM_SIZE_16x8,    -5,   -7, 1524,    0
    subsprite OAM_SIZE_32x32,   -4,  -36, 2700,    0
  FileAE52_Obj_1792:
    subsprite OAM_SIZE_16x16,    2,  -26,  494,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -11,   -2, 2008,    0
    subsprite OAM_SIZE_32x32,    0,  -30, 3204,    0
    subsprite OAM_SIZE_32x32,  -11,  -34, 3200,    0
    subsprite OAM_SIZE_16x16,   -2,  -23, 2474,    0
  FileAE52_Obj_1797:
    subsprite OAM_SIZE_32x32,  -11,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_16x8,    -2,  -23, 1569,    0
    subsprite OAM_SIZE_32x32,   -7,  -27, 2636,    0
    subsprite OAM_SIZE_16x16,   -2,  -39, 1537,    0
  FileAE52_Obj_1803:
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 2509,    0
    subsprite OAM_SIZE_16x8,     0,    0, 2540,    0
    subsprite OAM_SIZE_8x32,     0,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -6,  -43, 2510,    0
    subsprite OAM_SIZE_32x32,  -12,  -29, 2636,    0
  FileAE52_Obj_1810:
    subsprite OAM_SIZE_32x16,  -16,  -13, 2476,    0
    subsprite OAM_SIZE_32x16,  -17,  -30, 2336,    0
    subsprite OAM_SIZE_16x32,   -8,  -40, 2438,    0
    subsprite OAM_SIZE_16x16,  -13,  -24,   74,    0
    subsprite OAM_SIZE_8x32,    -2,  -27, 3086,    0
    subsprite OAM_SIZE_8x16,     2,  -25, 2539,    0
  FileAE52_Obj_1816:
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -16,  -16, 2509,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -16,    0, 2540,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -8,  -41,  655,    0, xflip=1
    subsprite OAM_SIZE_16x32,    0,  -41,  576,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -19,  -29, 2636,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -10,  -43, 2510,    0, xflip=1
  FileAE52_Obj_1823:
    subsprite OAM_SIZE_16x16,    4,  -33, 1493,    0
    subsprite OAM_SIZE_16x32,    2,  -49, 3266,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    2,  -43, 1924,    0
  FileAE52_Obj_1830:
    subsprite OAM_SIZE_32x8,    -6,  -30, 1200,    0
    subsprite OAM_SIZE_16x32,    3,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     3,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -13,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   21,  -48, 1410,    0
    subsprite OAM_SIZE_16x16,    5,  -32, 1468,    0
  FileAE52_Obj_1838:
    subsprite OAM_SIZE_8x16,    -4,  -42, 1058,    0
    subsprite OAM_SIZE_16x32,    1,  -50, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    2,  -34, 1428,    0
  FileAE52_Obj_1845:
    subsprite OAM_SIZE_16x32,   -1,  -50, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     1,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -38,  579,    0
    subsprite OAM_SIZE_8x16,    -6,  -43, 1058,    0
    subsprite OAM_SIZE_32x32,    0,  -33, 1428,    0
  FileAE52_Obj_1852:
    subsprite OAM_SIZE_16x32,   -1,  -50, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     1,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -38,  579,    0
    subsprite OAM_SIZE_8x16,    -6,  -44, 1058,    0
    subsprite OAM_SIZE_32x32,    0,  -34, 1428,    0
  FileAE52_Obj_1859:
    subsprite OAM_SIZE_16x32,    0,  -50, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  579,    0
    subsprite OAM_SIZE_16x32,    7,  -52, 1408,    0
  FileAE52_Obj_1865:
    subsprite OAM_SIZE_16x32,    0,  -52, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  579,    0
    subsprite OAM_SIZE_16x32,    8,  -55, 1408,    0
  FileAE52_Obj_1871:
    subsprite OAM_SIZE_16x32,   -1,  -52, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  579,    0
    subsprite OAM_SIZE_16x32,    5,  -59, 1860,    0
    subsprite OAM_SIZE_16x8,     5,  -27, 1086,    0
  FileAE52_Obj_1878:
    subsprite OAM_SIZE_16x32,   -2,  -52, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  579,    0
    subsprite OAM_SIZE_16x32,    3,  -60, 1860,    0
    subsprite OAM_SIZE_8x16,    19,  -52,  106,    0
    subsprite OAM_SIZE_16x8,     3,  -28, 1086,    0
  FileAE52_Obj_1886:
    subsprite OAM_SIZE_16x32,    3,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_16x32,   17,  -46, 1470,    0
    subsprite OAM_SIZE_16x16,    1,  -30, 1500,    0
  FileAE52_Obj_1893:
    subsprite OAM_SIZE_16x32,    3,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
  FileAE52_Obj_1899:
    subsprite OAM_SIZE_16x32,    3,  -48, 2188,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
  FileAE52_Obj_1905:
    subsprite OAM_SIZE_16x32,    3,  -48,  974,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_16x16,   23,  -44, 1230,    0
  FileAE52_Obj_1912:
    subsprite OAM_SIZE_16x32,    3,  -49, 2188,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_16x16,   23,  -44, 1262,    0
  FileAE52_Obj_1919:
    subsprite OAM_SIZE_16x32,    4,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   15,  -52, 1156,    0
  FileAE52_Obj_1926:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    6,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   15,  -52, 1222,    0
  FileAE52_Obj_1933:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 1216,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1226,    0
    subsprite OAM_SIZE_8x8,     32,  -47, 1035,    0
    subsprite OAM_SIZE_8x8,     41,  -33, 1051,    0
    subsprite OAM_SIZE_8x8,     17,  -48, 1035,    0
    subsprite OAM_SIZE_8x8,     42,  -48, 1051,    0
    subsprite OAM_SIZE_8x8,     28,  -26, 1035,    0
  FileAE52_Obj_1945:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    6,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1100,    0
    subsprite OAM_SIZE_8x8,     34,  -49, 1035,    0
    subsprite OAM_SIZE_8x8,     42,  -33, 1051,    0
    subsprite OAM_SIZE_8x8,     27,  -50, 1051,    0
    subsprite OAM_SIZE_8x8,     16,  -49, 1051,    0
    subsprite OAM_SIZE_8x8,     28,  -25, 1051,    0
  FileAE52_Obj_1957:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 1216,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1218,    0
    subsprite OAM_SIZE_8x8,     35,  -50, 1051,    0
    subsprite OAM_SIZE_8x8,     27,  -52, 1051,    0
    subsprite OAM_SIZE_8x8,     15,  -50, 1051,    0
    subsprite OAM_SIZE_8x8,     34,  -44, 1035,    0
    subsprite OAM_SIZE_8x8,     39,  -38, 1035,    0
    subsprite OAM_SIZE_8x8,     16,  -30, 1035,    0
  FileAE52_Obj_1970:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1226,    0
    subsprite OAM_SIZE_8x8,     36,  -51, 1051,    0
    subsprite OAM_SIZE_8x8,     35,  -36, 1035,    0
    subsprite OAM_SIZE_8x8,     27,  -53, 1051,    0
    subsprite OAM_SIZE_8x8,     36,  -45, 1035,    0
    subsprite OAM_SIZE_8x8,     39,  -38, 1051,    0
    subsprite OAM_SIZE_8x8,     15,  -29, 1051,    0
  FileAE52_Obj_1983:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 1216,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1100,    0
    subsprite OAM_SIZE_8x8,     37,  -35, 1035,    0
    subsprite OAM_SIZE_8x8,     27,  -54, 1051,    0
    subsprite OAM_SIZE_8x8,     20,  -45, 1035,    0
    subsprite OAM_SIZE_8x8,     38,  -46, 1035,    0
    subsprite OAM_SIZE_8x8,     25,  -52, 1035,    0
  FileAE52_Obj_1995:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 1216,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   14,  -52, 1218,    0
    subsprite OAM_SIZE_8x8,     39,  -34, 1051,    0
    subsprite OAM_SIZE_8x8,     27,  -55, 1051,    0
    subsprite OAM_SIZE_8x8,     18,  -47, 1035,    0
    subsprite OAM_SIZE_8x8,     40,  -47, 1051,    0
    subsprite OAM_SIZE_8x8,     24,  -52, 1051,    0
  FileAE52_Obj_2007:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 2190,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   15,  -52, 1226,    0, yflip=1
  FileAE52_Obj_2014:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    4,  -49, 1216,    0
    subsprite OAM_SIZE_8x32,     4,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -38,  579,    0
    subsprite OAM_SIZE_32x32,    5,  -42, 1472,    0
    subsprite OAM_SIZE_32x32,   15,  -52, 1100,    0, yflip=1
  FileAE52_Obj_2021:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    1,  -27,  139,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -45, 3264,    0
    subsprite OAM_SIZE_32x32,  -11,  -31, 2752,    0
  FileAE52_Obj_2028:
    subsprite OAM_SIZE_16x32,    6,  -29,  204,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -1,  -42, 3146,    0
    subsprite OAM_SIZE_16x32,    2,  -25, 2382,    0
    subsprite OAM_SIZE_16x16,   -5,  -14,  492,    0
    subsprite OAM_SIZE_16x16,  -11,  -25, 2000,    0
  FileAE52_Obj_2037:
    subsprite OAM_SIZE_32x8,    -2,  -32, 1200,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_16x32,  -18,  -29,  906,    0
    subsprite OAM_SIZE_16x32,   -2,  -44, 3146,    0
  FileAE52_Obj_2044:
    subsprite OAM_SIZE_32x8,    -3,  -33, 1200,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,  -20,  -30,  906,    0
    subsprite OAM_SIZE_16x32,   -4,  -45, 3146,    0
  FileAE52_Obj_2051:
    subsprite OAM_SIZE_32x8,    -4,  -34, 1200,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     1,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -40,  576,    0
    subsprite OAM_SIZE_16x32,  -19,  -31,  906,    0
    subsprite OAM_SIZE_16x32,   -4,  -45, 3146,    0
  FileAE52_Obj_2058:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_16x32,   -3,  -45, 3146,    0
    subsprite OAM_SIZE_32x32,  -12,  -49,  588,    0
  FileAE52_Obj_2064:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -4,  -47, 3146,    0
    subsprite OAM_SIZE_32x32,  -12,  -51,  588,    0
  FileAE52_Obj_2070:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -5,  -47, 3146,    0
    subsprite OAM_SIZE_32x32,  -11,  -56, 2182,    0
    subsprite OAM_SIZE_16x8,   -11,  -24, 1526,    0
  FileAE52_Obj_2077:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     1,  -42,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -42,  576,    0
    subsprite OAM_SIZE_16x32,   -6,  -48, 3146,    0
    subsprite OAM_SIZE_32x32,  -12,  -58, 2182,    0
    subsprite OAM_SIZE_16x8,   -12,  -26, 1526,    0
  FileAE52_Obj_2084:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -44, 3146,    0
    subsprite OAM_SIZE_32x32,   -9,  -35, 1920,    0
  FileAE52_Obj_2090:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,   -2,  -44, 3146,    0
  FileAE52_Obj_2096:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,   -2,  -43, 2630,    0
  FileAE52_Obj_2102:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x16,   -3,  -35, 1179,    0
    subsprite OAM_SIZE_16x8,    -3,  -43, 1163,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1211,    0
    subsprite OAM_SIZE_8x16,     3,  -43, 2506,    0
    subsprite OAM_SIZE_16x16,   12,  -32, 1230,    0
  FileAE52_Obj_2112:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -44, 2630,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x16,   12,  -32, 1262,    0
  FileAE52_Obj_2119:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,   -1,  -44, 3146,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1156,    0
  FileAE52_Obj_2126:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -5,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1222,    0
  FileAE52_Obj_2133:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2572,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1226,    0
    subsprite OAM_SIZE_8x8,     22,  -35, 1035,    0
    subsprite OAM_SIZE_8x8,     31,  -21, 1051,    0
    subsprite OAM_SIZE_8x8,      7,  -36, 1035,    0
    subsprite OAM_SIZE_8x8,     32,  -36, 1051,    0
    subsprite OAM_SIZE_8x8,     18,  -14, 1035,    0
  FileAE52_Obj_2146:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -5,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1100,    0
    subsprite OAM_SIZE_8x8,     24,  -37, 1035,    0
    subsprite OAM_SIZE_8x8,     32,  -21, 1051,    0
    subsprite OAM_SIZE_8x8,     17,  -38, 1051,    0
    subsprite OAM_SIZE_8x8,      6,  -37, 1051,    0
    subsprite OAM_SIZE_8x8,     18,  -13, 1051,    0
  FileAE52_Obj_2158:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2572,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1218,    0
    subsprite OAM_SIZE_8x8,     25,  -38, 1051,    0
    subsprite OAM_SIZE_8x8,     17,  -40, 1051,    0
    subsprite OAM_SIZE_8x8,      5,  -38, 1051,    0
    subsprite OAM_SIZE_8x8,     24,  -32, 1035,    0
    subsprite OAM_SIZE_8x8,     29,  -26, 1035,    0
    subsprite OAM_SIZE_8x8,      6,  -18, 1035,    0
  FileAE52_Obj_2172:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1226,    0
    subsprite OAM_SIZE_8x8,     26,  -39, 1051,    0
    subsprite OAM_SIZE_8x8,     25,  -24, 1035,    0
    subsprite OAM_SIZE_8x8,     17,  -41, 1051,    0
    subsprite OAM_SIZE_8x8,     26,  -33, 1035,    0
    subsprite OAM_SIZE_8x8,     29,  -26, 1051,    0
    subsprite OAM_SIZE_8x8,      5,  -17, 1051,    0
  FileAE52_Obj_2185:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2572,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1100,    0
    subsprite OAM_SIZE_8x8,     27,  -23, 1035,    0
    subsprite OAM_SIZE_8x8,     17,  -42, 1051,    0
    subsprite OAM_SIZE_8x8,     10,  -33, 1035,    0
    subsprite OAM_SIZE_8x8,     28,  -34, 1035,    0
    subsprite OAM_SIZE_8x8,     15,  -40, 1035,    0
  FileAE52_Obj_2198:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2572,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1218,    0
    subsprite OAM_SIZE_8x8,     29,  -22, 1051,    0
    subsprite OAM_SIZE_8x8,     17,  -43, 1051,    0
    subsprite OAM_SIZE_8x8,      8,  -35, 1035,    0
    subsprite OAM_SIZE_8x8,     30,  -35, 1051,    0
    subsprite OAM_SIZE_8x8,     14,  -40, 1051,    0
  FileAE52_Obj_2211:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1226,    0, yflip=1
  FileAE52_Obj_2218:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_32x32,   -6,  -32, 2246,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2766,    0
    subsprite OAM_SIZE_16x32,    0,  -44, 2572,    0
    subsprite OAM_SIZE_32x32,    4,  -40, 1222,    0
  FileAE52_Obj_2226:
    subsprite OAM_SIZE_16x32,    4,  -40, 2382,    0
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0
    subsprite OAM_SIZE_8x16,     5,  -47, 2538,    0
  FileAE52_Obj_2230:
    subsprite OAM_SIZE_16x16,  -19,  -44, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -3,  -47, 2538,    0
    subsprite OAM_SIZE_32x32,  -13,  -36, 2120,    0
    subsprite OAM_SIZE_32x32,  -16,  -41, 1548,    0
    subsprite OAM_SIZE_32x16,  -16,   -9, 1636,    0
  FileAE52_Obj_2235:
    subsprite OAM_SIZE_16x32,  -20,  -40, 2382,    0, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -39, 2564,    0, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -7, 2568,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -13,  -47, 2538,    0, xflip=1
  FileAE52_Obj_2239:
    subsprite OAM_SIZE_32x16,   -4,  -28, 1496,    0
    subsprite OAM_SIZE_32x32,   -8,  -39,   76,    0
    subsprite OAM_SIZE_16x8,    -5,   -7, 1524,    0
    subsprite OAM_SIZE_8x16,     9,  -45, 2538,    0
    subsprite OAM_SIZE_32x32,    1,  -35, 2688,    0
  FileAE52_Obj_2244:
    subsprite OAM_SIZE_16x16,   -1,  -27, 1493,    0
    subsprite OAM_SIZE_16x8,   -11,   -2, 2008,    0
    subsprite OAM_SIZE_32x32,  -11,  -34, 3200,    0
    subsprite OAM_SIZE_8x16,     8,  -41, 2506,    0
    subsprite OAM_SIZE_32x32,   -4,  -29, 2752,    0
  FileAE52_Obj_2249:
    subsprite OAM_SIZE_16x32,    1,  -28,  204,    0
    subsprite OAM_SIZE_16x16,  -10,   -7, 1376,    0
    subsprite OAM_SIZE_8x8,      6,   -7, 1347,    0
    subsprite OAM_SIZE_32x32,  -10,  -39, 1536,    0
    subsprite OAM_SIZE_8x16,     5,  -41, 2506,    0
    subsprite OAM_SIZE_32x32,  -11,  -31, 1996,    0
  FileAE52_Obj_2255:
    subsprite OAM_SIZE_16x32,   -1,  -28,  204,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0
    subsprite OAM_SIZE_8x16,     8,  -16, 2509,    0
    subsprite OAM_SIZE_16x8,     0,    0, 2540,    0
    subsprite OAM_SIZE_8x32,     0,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -16,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -6,  -39, 2510,    0
    subsprite OAM_SIZE_8x16,     0,  -39, 2506,    0
    subsprite OAM_SIZE_32x32,  -15,  -32, 1996,    0
  FileAE52_Obj_2264:
    subsprite OAM_SIZE_32x16,  -16,  -13, 2476,    0
    subsprite OAM_SIZE_16x16,  -13,  -24,   74,    0
    subsprite OAM_SIZE_32x16,  -17,  -30, 2336,    0
    subsprite OAM_SIZE_16x32,   -8,  -40, 2438,    0
    subsprite OAM_SIZE_8x16,    -4,  -38, 2506,    0
    subsprite OAM_SIZE_32x32,  -17,  -33, 2752,    0, xflip=1
  FileAE52_Obj_2270:
    subsprite OAM_SIZE_16x32,  -16,  -27,  139,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -16, 2507,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -16,  -16, 2509,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -16,    0, 2540,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -8,  -41,  655,    0, xflip=1
    subsprite OAM_SIZE_16x32,    0,  -41,  576,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -10,  -39, 2510,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -7,  -39, 2506,    0
    subsprite OAM_SIZE_32x32,  -18,  -32, 2688,    0, xflip=1
  FileAE52_Obj_2279:
    subsprite OAM_SIZE_16x16,  -14,  -33, 3268,    0
    subsprite OAM_SIZE_16x32,    1,  -48, 3266,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   72,    0
    subsprite OAM_SIZE_8x16,     4,   -8, 2891,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,    6,  -32, 3274,    0
  FileAE52_Obj_2286:
    subsprite OAM_SIZE_16x16,  -15,  -33, 3268,    0
    subsprite OAM_SIZE_16x32,    2,  -46, 3266,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   13,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   15,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -2,  -31, 3276,    0
  FileAE52_Obj_2293:
    subsprite OAM_SIZE_16x16,  -15,  -32, 3268,    0
    subsprite OAM_SIZE_16x32,    2,  -47, 3266,    0
    subsprite OAM_SIZE_16x32,   -9,  -24,  768,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_32x32,   -2,  -30, 3276,    0
  FileAE52_Obj_2299:
    subsprite OAM_SIZE_16x16,  -14,  -33, 3268,    0
    subsprite OAM_SIZE_16x32,    0,  -48, 3266,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  770,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,    4,  -31, 3274,    0
  FileAE52_Obj_2305:
    subsprite OAM_SIZE_16x32,    1,  -48, 3266,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  774,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,    4,  -31, 3272,    0
  FileAE52_Obj_2310:
    subsprite OAM_SIZE_16x32,    2,  -46, 3266,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  778,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x32,    4,  -30, 3272,    0
  FileAE52_Obj_2315:
    subsprite OAM_SIZE_16x32,    2,  -47, 3266,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  832,    0
    subsprite OAM_SIZE_8x32,     1,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -15,  -37,  579,    0
    subsprite OAM_SIZE_16x32,    5,  -30, 3272,    0
  FileAE52_Obj_2320:
    subsprite OAM_SIZE_16x32,    0,  -48, 3266,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,  836,    0
    subsprite OAM_SIZE_8x32,     0,  -38,  581,    0
    subsprite OAM_SIZE_16x32,  -16,  -38,  579,    0
    subsprite OAM_SIZE_16x32,    5,  -31, 3274,    0
  FileAE52_Obj_2325:
    subsprite OAM_SIZE_16x32,   -1,  -27,  139,    0
    subsprite OAM_SIZE_32x32,  -12,  -24,    0,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -3,  -44, 3264,    0
    subsprite OAM_SIZE_16x32,   -7,  -23, 3210,    0
  FileAE52_Obj_2331:
    subsprite OAM_SIZE_16x32,   -4,  -28,  204,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    6,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    4,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -41, 3264,    0
    subsprite OAM_SIZE_32x32,  -12,  -21, 3212,    0
  FileAE52_Obj_2338:
    subsprite OAM_SIZE_16x32,   -2,  -26,  204,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,    7,    0
    subsprite OAM_SIZE_8x32,     4,  -24,    9,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -42, 3264,    0
    subsprite OAM_SIZE_32x32,  -13,  -21, 3212,    0
  FileAE52_Obj_2345:
    subsprite OAM_SIZE_16x32,    2,  -26,  139,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,   10,    0
    subsprite OAM_SIZE_8x32,     4,  -24,   12,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -4,  -45, 3264,    0
    subsprite OAM_SIZE_16x32,   -9,  -24, 3210,    0
  FileAE52_Obj_2352:
    subsprite OAM_SIZE_16x32,    3,  -25,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -24,   64,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -3,  -44, 3264,    0
    subsprite OAM_SIZE_16x32,  -10,  -24, 3208,    0
  FileAE52_Obj_2358:
    subsprite OAM_SIZE_16x32,    3,  -23,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   66,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -41, 3264,    0
    subsprite OAM_SIZE_16x32,  -10,  -23, 3208,    0
  FileAE52_Obj_2364:
    subsprite OAM_SIZE_16x32,    2,  -23,  204,    0
    subsprite OAM_SIZE_16x32,   -8,  -21,   68,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -2,  -42, 3264,    0
    subsprite OAM_SIZE_16x32,   -9,  -22, 3208,    0
  FileAE52_Obj_2370:
    subsprite OAM_SIZE_16x32,    0,  -26,  139,    0
    subsprite OAM_SIZE_16x32,   -8,  -23,   70,    0
    subsprite OAM_SIZE_8x32,     1,  -41,  655,    0
    subsprite OAM_SIZE_16x32,  -15,  -41,  576,    0
    subsprite OAM_SIZE_16x32,   -4,  -45, 3264,    0
    subsprite OAM_SIZE_16x32,   -8,  -23, 3210,    0
  FileAE52_Obj_2376:
    subsprite OAM_SIZE_32x16,   -4,  -34, 1496,    0
    subsprite OAM_SIZE_16x32,    0,  -48, 3266,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x32,    7,  -42, 3270,    0
  FileAE52_Obj_2383:
    subsprite OAM_SIZE_32x16,   -3,  -33, 1496,    0
    subsprite OAM_SIZE_16x32,    1,  -48, 3266,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x32,   12,  -42,  330,    0
    subsprite OAM_SIZE_8x16,     4,  -26, 2904,    0
  FileAE52_Obj_2391:
    subsprite OAM_SIZE_16x16,    4,  -32, 1493,    0
    subsprite OAM_SIZE_16x32,    2,  -48, 3266,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_32x32,    2,  -42, 1924,    0
  FileAE52_Obj_2398:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    0,  -24,  139,    0
    subsprite OAM_SIZE_16x32,   -1,  -44, 3264,    0
    subsprite OAM_SIZE_32x32,  -11,  -30, 2688,    0
  FileAE52_Obj_2406:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    1,  -26,  139,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,   -2,  -44, 3264,    0
    subsprite OAM_SIZE_32x32,  -11,  -30, 2752,    0
  FileAE52_Obj_2413:
    subsprite OAM_SIZE_16x32,   -1,  -28,  204,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_8x32,     2,  -39,  655,    0
    subsprite OAM_SIZE_16x32,  -14,  -39,  576,    0
    subsprite OAM_SIZE_16x32,   -3,  -44, 3264,    0
    subsprite OAM_SIZE_32x32,  -11,  -30, 1996,    0
  FileAE52_Obj_2420:
    subsprite OAM_SIZE_16x32,    2,  -40, 2432,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -37,  579,    0
    subsprite OAM_SIZE_16x16,   10,  -32, 1634,    0
    subsprite OAM_SIZE_16x32,    2,  -27,  192,    0
    subsprite OAM_SIZE_32x16,   -9,  -10, 1600,    0
  FileAE52_Obj_2428:
    subsprite OAM_SIZE_16x32,    2,  -40, 2432,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     3,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -13,  -37,  579,    0
    subsprite OAM_SIZE_16x16,   10,  -32, 1634,    0
    subsprite OAM_SIZE_16x32,    1,  -27,  194,    0
    subsprite OAM_SIZE_32x16,   -8,  -10, 1600,    0
  FileAE52_Obj_2436:
    subsprite OAM_SIZE_16x32,    1,  -41, 2432,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     2,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -37,  579,    0
    subsprite OAM_SIZE_16x16,    9,  -33, 1634,    0
    subsprite OAM_SIZE_16x32,    0,  -27,  196,    0
    subsprite OAM_SIZE_32x16,   -7,  -11, 1600,    0
  FileAE52_Obj_2444:
    subsprite OAM_SIZE_16x32,    1,  -41, 2432,    0
    subsprite OAM_SIZE_8x32,     3,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -13,  -37,  579,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x16,    9,  -33, 1634,    0
    subsprite OAM_SIZE_16x32,    0,  -27,  194,    0
    subsprite OAM_SIZE_32x16,   -9,  -10, 1600,    0
  FileAE52_Obj_2452:
    subsprite OAM_SIZE_16x32,    2,  -41, 2432,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_8x32,     4,  -37,  581,    0
    subsprite OAM_SIZE_16x32,  -12,  -37,  579,    0
    subsprite OAM_SIZE_16x16,   10,  -33, 1634,    0
    subsprite OAM_SIZE_16x32,    1,  -27,  192,    0
    subsprite OAM_SIZE_32x16,  -10,  -10, 1600,    0
  FileAE52_Obj_2460:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    7,  -30, 3274,    0
    subsprite OAM_SIZE_16x32,    2,  -46, 3266,    0
    subsprite OAM_SIZE_8x32,     2,  -36,  581,    0
    subsprite OAM_SIZE_16x32,  -14,  -36,  579,    0
  FileAE52_Obj_2466:
    subsprite OAM_SIZE_16x32,   -1,  -33,  137,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -11,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     5,  -39,  655,    0
    subsprite OAM_SIZE_16x32,    2,  -34, 2434,    0
    subsprite OAM_SIZE_16x32,  -11,  -22,  135,    0
    subsprite OAM_SIZE_16x16,   10,  -29, 1038,    0
    subsprite OAM_SIZE_16x16,  -12,  -11, 3300,    0
  FileAE52_Obj_2475:
    subsprite OAM_SIZE_16x32,   -2,  -33,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -12,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     4,  -39,  655,    0
    subsprite OAM_SIZE_16x32,    2,  -34, 2434,    0
    subsprite OAM_SIZE_8x32,    -4,  -22,  132,    0
    subsprite OAM_SIZE_16x16,   10,  -29, 1038,    0
    subsprite OAM_SIZE_16x16,  -10,  -10, 3300,    0
  FileAE52_Obj_2484:
    subsprite OAM_SIZE_16x32,    5,  -33,  130,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -13,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     3,  -39,  655,    0
    subsprite OAM_SIZE_16x32,    1,  -35, 2434,    0
    subsprite OAM_SIZE_16x32,   -5,  -22,  128,    0
    subsprite OAM_SIZE_16x16,    9,  -30, 1038,    0
    subsprite OAM_SIZE_16x16,   -9,  -10, 3300,    0
  FileAE52_Obj_2493:
    subsprite OAM_SIZE_16x32,   -3,  -33,  133,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -12,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     4,  -39,  655,    0
    subsprite OAM_SIZE_16x32,    1,  -35, 2434,    0
    subsprite OAM_SIZE_8x32,    -5,  -22,  132,    0
    subsprite OAM_SIZE_16x16,    9,  -30, 1038,    0
    subsprite OAM_SIZE_16x16,  -11,  -10, 3300,    0
  FileAE52_Obj_2502:
    subsprite OAM_SIZE_16x32,   -2,  -33,  137,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,  -11,  -39,  576,    0
    subsprite OAM_SIZE_8x32,     5,  -39,  655,    0
    subsprite OAM_SIZE_16x32,    2,  -35, 2434,    0
    subsprite OAM_SIZE_16x32,  -12,  -22,  135,    0
    subsprite OAM_SIZE_16x16,   10,  -30, 1038,    0
    subsprite OAM_SIZE_16x16,  -13,  -11, 3300,    0
  FileAE52_Obj_2511:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_16x32,    3,  -25,  139,    0
    subsprite OAM_SIZE_16x32,  -14,  -40,  576,    0
    subsprite OAM_SIZE_8x32,     2,  -40,  655,    0
    subsprite OAM_SIZE_16x32,   -3,  -41, 3264,    0
    subsprite OAM_SIZE_16x32,   -8,  -23, 3210,    0
  FileAE52_Obj_2518:
    subsprite OAM_SIZE_32x32,  -11,  -35,  332,    0
    subsprite OAM_SIZE_16x16,  -12,  -37, 3116,    0
    subsprite OAM_SIZE_16x32,    6,  -36, 2250,    0
    subsprite OAM_SIZE_16x8,   -11,   -3,  976,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  979,    0
    subsprite OAM_SIZE_16x8,    -3,    5, 1010,    0
  FileAE52_Obj_2524:
    subsprite OAM_SIZE_32x32,  -11,  -35,  332,    0
    subsprite OAM_SIZE_16x16,  -12,  -37, 3116,    0
    subsprite OAM_SIZE_16x16,   -2,  -37, 1646,    0
    subsprite OAM_SIZE_16x32,    6,  -36, 2250,    0
    subsprite OAM_SIZE_16x8,    -3,    5, 1010,    0
    subsprite OAM_SIZE_16x8,   -11,   -3,  976,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  979,    0
  FileAE52_Obj_2531:
    subsprite OAM_SIZE_32x32,  -18,  -37,  392,    0
    subsprite OAM_SIZE_16x16,  -10,   -5,  992,    0
    subsprite OAM_SIZE_8x8,      6,   -5,  994,    0
    subsprite OAM_SIZE_16x16,  -14,  -41, 2726,    0
    subsprite OAM_SIZE_32x32,  -21,  -32, 1800,    0
  FileAE52_Obj_2536:
    subsprite OAM_SIZE_16x16,  -10,   -5,  992,    0
    subsprite OAM_SIZE_8x8,      6,   -5,  994,    0
    subsprite OAM_SIZE_32x32,  -18,  -37,  392,    0
    subsprite OAM_SIZE_16x16,  -14,  -41, 2726,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1644,    0
    subsprite OAM_SIZE_32x32,  -21,  -32, 1800,    0
  FileAE52_Obj_2542:
    subsprite OAM_SIZE_32x16,  -23,  -41, 3052,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
    subsprite OAM_SIZE_16x16,   31,  -57, 2905,    0
    subsprite OAM_SIZE_16x16,   39,  -49, 2922,    0
  FileAE52_Obj_2549:
    subsprite OAM_SIZE_32x32,   11,  -46, 3136,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x16,   19,  -26,  198,    0
    subsprite OAM_SIZE_32x32,   18,    1, 2950,    0
  FileAE52_Obj_2556:
    subsprite OAM_SIZE_32x16,  -23,  -41, 3052,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
  FileAE52_Obj_2561:
    subsprite OAM_SIZE_32x32,   11,  -46, 3136,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x16,   19,  -26,  198,    0
  FileAE52_Obj_2567:
    subsprite OAM_SIZE_16x32,    0,  -34, 2382,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -18,  -40,  264,    0
    subsprite OAM_SIZE_8x16,     3,  -47, 2538,    0
  FileAE52_Obj_2572:
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_16x32,    6,  -36, 2382,    0
    subsprite OAM_SIZE_32x32,  -12,  -39,  268,    0
    subsprite OAM_SIZE_16x16,  -12,  -15,  200,    0
    subsprite OAM_SIZE_8x16,     7,  -46, 2538,    0
  FileAE52_Obj_2578:
    subsprite OAM_SIZE_16x32,    3,  -41, 2382,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,   -8,  -42,  320,    0
    subsprite OAM_SIZE_16x16,    8,  -18,  230,    0
    subsprite OAM_SIZE_8x16,     9,  -49, 2538,    0
  FileAE52_Obj_2584:
    subsprite OAM_SIZE_16x32,  -19,  -41, 2382,    0
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -16,  -47,  324,    0
    subsprite OAM_SIZE_16x16,   16,  -39,  232,    0
    subsprite OAM_SIZE_8x16,     5,  -52, 2538,    0
  FileAE52_Obj_2590:
    subsprite OAM_SIZE_16x32,  -29,  -34, 2382,    0, xflip=1
    subsprite OAM_SIZE_8x32,     3,  -22,  587,    0
    subsprite OAM_SIZE_16x32,  -13,  -22,  585,    0
    subsprite OAM_SIZE_32x32,  -17,  -45,  512,    0
    subsprite OAM_SIZE_16x16,  -25,  -29,  642,    0
    subsprite OAM_SIZE_8x16,     2,  -53, 2538,    0
  FileAE52_Obj_2596:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -22,  -40,  448,    0
    subsprite OAM_SIZE_16x32,    1,  -23, 2382,    0, xflip=1
    subsprite OAM_SIZE_16x16,    2,  -16,  672,    0
    subsprite OAM_SIZE_8x16,    -6,  -45, 2506,    0
  FileAE52_Obj_2602:
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,  -21,  -37,  452,    0
    subsprite OAM_SIZE_16x16,    3,  -21,  460,    0
    subsprite OAM_SIZE_8x16,    -3,  -43, 2506,    0
    subsprite OAM_SIZE_32x16,   -3,  -16, 1600,    0, xflip=1
  FileAE52_Obj_2608:
    subsprite OAM_SIZE_16x32,    9,  -31, 2382,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -9,  -37,  456,    0
    subsprite OAM_SIZE_16x16,  -25,  -21,  462,    0
    subsprite OAM_SIZE_8x16,     5,  -42, 2506,    0
  FileAE52_Obj_2614:
    subsprite OAM_SIZE_16x32,    6,  -52, 2382,    0
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -8,  -38,  256,    0
    subsprite OAM_SIZE_16x16,    8,   -6,  492,    0
    subsprite OAM_SIZE_8x16,     9,  -41, 2506,    0
  FileAE52_Obj_2620:
    subsprite OAM_SIZE_16x32,  -20,  -48, 2382,    0, xflip=1
    subsprite OAM_SIZE_16x32,  -12,  -24,  582,    0
    subsprite OAM_SIZE_8x16,     4,  -16,  616,    0
    subsprite OAM_SIZE_32x32,   -5,  -42,  260,    0
    subsprite OAM_SIZE_16x16,  -21,  -42,  494,    0
    subsprite OAM_SIZE_16x16,   19,  -26,  198,    0
    subsprite OAM_SIZE_8x16,    11,  -44, 2506,    0

2:
FileAE52_Cmds:
  FileAE52_Cmd_0:
    animcmd    0,   4
  FileAE52_Cmd_1:
    animcmd    1,   4
  FileAE52_Cmd_2:
    animcmd  103,   1
  FileAE52_Cmd_3:
    animcmd  104,   1
  FileAE52_Cmd_4:
    animcmd  215,   1
  FileAE52_Cmd_5:
    animcmd  216,   1
  FileAE52_Cmd_6:
    animcmd    2,  10
    animcmd    3,  20
    animcmd    4,  13
    animcmd    5,  10
    animcmd    6,  10
    animcmd    7,  20
    animcmd    8,  13
    animcmd    9,  10
  FileAE52_Cmd_14:
    animcmd   10,  10
    animcmd   11,  20
    animcmd   12,  13
    animcmd   13,  10
    animcmd   14,  10
    animcmd   15,  20
    animcmd   16,  13
    animcmd   17,  10
  FileAE52_Cmd_22:
    animcmd  105,  10
    animcmd  106,  20
    animcmd  107,  13
    animcmd  108,  10
    animcmd  109,  10
    animcmd  110,  20
    animcmd  111,  13
    animcmd  112,  10
  FileAE52_Cmd_30:
    animcmd  113,  10
    animcmd  114,  20
    animcmd  115,  13
    animcmd  116,  10
    animcmd  117,  10
    animcmd  118,  20
    animcmd  119,  13
    animcmd  120,  10
  FileAE52_Cmd_38:
    animcmd  217,  10
    animcmd  218,  20
    animcmd  219,  13
    animcmd  220,  10
    animcmd  221,  10
    animcmd  222,  20
    animcmd  223,  13
    animcmd  224,  10
  FileAE52_Cmd_46:
    animcmd  225,  10
    animcmd  226,  20
    animcmd  227,  13
    animcmd  228,  10
    animcmd  229,  10
    animcmd  230,  20
    animcmd  231,  13
    animcmd  232,  10
  FileAE52_Cmd_54:
    animcmd   18,  27
    animcmd   19,   6
    animcmd   20,   3
    animcmd   21,   4
    animcmd   22,  18
  FileAE52_Cmd_59:
    animcmd   24,  27
    animcmd   25,   6
    animcmd   26,   3
    animcmd   27,   4
    animcmd   28,  18
  FileAE52_Cmd_64:
    animcmd  121,  27
    animcmd  122,   7
    animcmd  123,   4
    animcmd  124,   3
    animcmd  125,   3
    animcmd  126,  18
  FileAE52_Cmd_70:
    animcmd  127,  27
    animcmd  128,   7
    animcmd  129,   4
    animcmd  130,   3
    animcmd  131,   3
    animcmd  132,  18
  FileAE52_Cmd_76:
    animcmd  233,  27
    animcmd  234,   5
    animcmd  235,   5
    animcmd  236,   5
  FileAE52_Cmd_80:
    animcmd  242,  27
    animcmd  243,   5
    animcmd  244,   5
    animcmd  245,   5
  FileAE52_Cmd_84:
    animcmd  238,   8
    animcmd  239,  32
  FileAE52_Cmd_86:
    animcmd  247,   8
    animcmd  248,  32
  FileAE52_Cmd_88:
    animcmd  240,   2
    animcmd  241,   2
  FileAE52_Cmd_90:
    animcmd  249,   2
    animcmd  250,   2
  FileAE52_Cmd_92:
    animcmd  238,   8
    animcmd  276,   8
  FileAE52_Cmd_94:
    animcmd  247,   8
    animcmd  280,   8
  FileAE52_Cmd_96:
    animcmd  315,   4
    animcmd  316,   4
    animcmd  317,   6
    animcmd  318,  16
    animcmd  319,   2
    animcmd  320,   4
    animcmd  321,   8
    animcmd  322,   8
    animcmd  323,  16
    animcmd  324,   4
    animcmd  325,   4
    animcmd  326,   8
    animcmd  327,   4
    animcmd  328,   4
    animcmd  330,   4
  FileAE52_Cmd_111:
    animcmd  339,   4
    animcmd  340,   4
    animcmd  341,   6
    animcmd  342,  16
    animcmd  343,   2
    animcmd  344,   4
    animcmd  345,   8
    animcmd  346,   8
    animcmd  347,  16
    animcmd  348,   4
    animcmd  349,   4
    animcmd  350,   8
    animcmd  351,   4
    animcmd  352,   4
    animcmd  354,   4
  FileAE52_Cmd_126:
    animcmd  331,   5
    animcmd  332,   5
    animcmd  333,   5
    animcmd  334,   5
    animcmd  335,   5
    animcmd  336,   5
  FileAE52_Cmd_132:
    animcmd  355,   5
    animcmd  356,   5
    animcmd  357,   5
    animcmd  358,   5
    animcmd  359,   5
    animcmd  360,   5
  FileAE52_Cmd_138:
    animcmd  324,   8
  FileAE52_Cmd_139:
    animcmd  348,   8
  FileAE52_Cmd_140:
    animcmd   32,  10
    animcmd   31,  10
    animcmd   30,  10
  FileAE52_Cmd_143:
    animcmd   33,  10
    animcmd   34,  10
    animcmd   35,  10
  FileAE52_Cmd_146:
    animcmd   36,  10
    animcmd   37,  10
    animcmd   38,  10
  FileAE52_Cmd_149:
    animcmd  135,  10
    animcmd  134,  10
    animcmd  133,  10
  FileAE52_Cmd_152:
    animcmd  136,  10
    animcmd  137,  10
    animcmd  138,  10
  FileAE52_Cmd_155:
    animcmd  139,  10
    animcmd  140,  10
    animcmd  141,  10
  FileAE52_Cmd_158:
    animcmd  144,  10
    animcmd  143,  10
    animcmd  142,  10
  FileAE52_Cmd_161:
    animcmd  145,  10
    animcmd  146,  10
    animcmd  147,  10
  FileAE52_Cmd_164:
    animcmd  148,  10
    animcmd  149,  10
    animcmd  150,  10
  FileAE52_Cmd_167:
    animcmd  299,  10
    animcmd  298,  10
    animcmd  297,  10
  FileAE52_Cmd_170:
    animcmd  300,  10
    animcmd  301,  10
    animcmd  302,  10
  FileAE52_Cmd_173:
    animcmd  303,  10
    animcmd  304,  10
    animcmd  305,  10
  FileAE52_Cmd_176:
    animcmd  308,  10
    animcmd  307,  10
    animcmd  306,  10
  FileAE52_Cmd_179:
    animcmd  309,  10
    animcmd  310,  10
    animcmd  311,  10
  FileAE52_Cmd_182:
    animcmd  312,  10
    animcmd  313,  10
    animcmd  314,  10
  FileAE52_Cmd_185:
    animcmd  365,  10
    animcmd  364,  10
    animcmd  363,  10
  FileAE52_Cmd_188:
    animcmd  366,  10
    animcmd  367,  10
    animcmd  368,  10
  FileAE52_Cmd_191:
    animcmd  369,  10
    animcmd  370,  10
    animcmd  371,  10
  FileAE52_Cmd_194:
    animcmd   39,   6
    animcmd   40,   6
    animcmd   41,   6
    animcmd   42,   6
    animcmd   43,   6
    animcmd   44,   6
    animcmd   45,   6
    animcmd   46,   6
  FileAE52_Cmd_202:
    animcmd   47,   6
    animcmd   48,   6
    animcmd   49,   6
    animcmd   50,   6
    animcmd   51,   6
    animcmd   52,   6
    animcmd   53,   6
    animcmd   54,   6
  FileAE52_Cmd_210:
    animcmd  151,   6
    animcmd  152,   6
    animcmd  153,   6
    animcmd  154,   6
    animcmd  155,   6
    animcmd  156,   6
    animcmd  157,   6
    animcmd  158,   6
  FileAE52_Cmd_218:
    animcmd  159,   6
    animcmd  160,   6
    animcmd  161,   6
    animcmd  162,   6
    animcmd  163,   6
    animcmd  164,   6
    animcmd  165,   6
    animcmd  166,   6
  FileAE52_Cmd_226:
    animcmd  257,   6
    animcmd  258,   6
    animcmd  259,   6
    animcmd  260,   6
    animcmd  261,   6
    animcmd  262,   6
    animcmd  263,   6
    animcmd  264,   6
  FileAE52_Cmd_234:
    animcmd  265,   6
    animcmd  266,   6
    animcmd  267,   6
    animcmd  268,   6
    animcmd  269,   6
    animcmd  270,   6
    animcmd  271,   6
    animcmd  272,   6
  FileAE52_Cmd_242:
    animcmd  372,   6
    animcmd  373,   6
    animcmd  374,   6
    animcmd  375,   6
    animcmd  376,   6
    animcmd  377,   6
    animcmd  378,   6
    animcmd  379,   6
  FileAE52_Cmd_250:
    animcmd  380,   6
    animcmd  381,   6
    animcmd  382,   6
    animcmd  383,   6
    animcmd  384,   6
    animcmd  385,   6
    animcmd  386,   6
    animcmd  387,   6
  FileAE52_Cmd_258:
    animcmd   55,  23
  FileAE52_Cmd_259:
    animcmd   57,  21
  FileAE52_Cmd_260:
    animcmd   56,  24
  FileAE52_Cmd_261:
    animcmd   58,  21
  FileAE52_Cmd_262:
    animcmd   65,   1
  FileAE52_Cmd_263:
    animcmd   68,   1
  FileAE52_Cmd_264:
    animcmd  167,  23
  FileAE52_Cmd_265:
    animcmd  170,  21
  FileAE52_Cmd_266:
    animcmd  168,  24
  FileAE52_Cmd_267:
    animcmd  171,  21
  FileAE52_Cmd_268:
    animcmd  169,   1
  FileAE52_Cmd_269:
    animcmd  172,   1
  FileAE52_Cmd_270:
    animcmd  251,  23
  FileAE52_Cmd_271:
    animcmd  254,  21
  FileAE52_Cmd_272:
    animcmd  252,  24
  FileAE52_Cmd_273:
    animcmd  255,  21
  FileAE52_Cmd_274:
    animcmd  253,   1
  FileAE52_Cmd_275:
    animcmd  256,   1
  FileAE52_Cmd_276:
    animcmd   61,   4
    animcmd   60,   4
    animcmd   59,   3
    animcmd   60,  16
  FileAE52_Cmd_280:
    animcmd   64,   4
    animcmd   63,   4
    animcmd   62,   3
    animcmd   63,  16
  FileAE52_Cmd_284:
    animcmd  173,   4
    animcmd  174,   4
    animcmd  175,   4
    animcmd  176,   4
    animcmd  177,   4
    animcmd  178,   4
  FileAE52_Cmd_290:
    animcmd  180,   4
    animcmd  181,   4
    animcmd  182,   4
    animcmd  183,   4
    animcmd  184,   4
    animcmd  185,   4
  FileAE52_Cmd_296:
    animcmd  273,   8
    animcmd  274,   6
    animcmd  275,   6
    animcmd  276,   8
  FileAE52_Cmd_300:
    animcmd  277,   8
    animcmd  278,   6
    animcmd  279,   6
    animcmd  280,   8
  FileAE52_Cmd_304:
    animcmd   65,   8
    animcmd   66,  32
  FileAE52_Cmd_306:
    animcmd   68,   8
    animcmd   69,  32
  FileAE52_Cmd_308:
    animcmd   67,  12
  FileAE52_Cmd_309:
    animcmd   70,  12
  FileAE52_Cmd_310:
    animcmd  187,   8
    animcmd  188,  32
  FileAE52_Cmd_312:
    animcmd  190,   8
    animcmd  191,  32
  FileAE52_Cmd_314:
    animcmd  189,  12
  FileAE52_Cmd_315:
    animcmd  192,  12
  FileAE52_Cmd_316:
    animcmd  281,   8
    animcmd  282,  32
  FileAE52_Cmd_318:
    animcmd  284,   8
    animcmd  285,  32
  FileAE52_Cmd_320:
    animcmd  283,  12
  FileAE52_Cmd_321:
    animcmd  286,  12
  FileAE52_Cmd_322:
    animcmd  394,  20
    animcmd  395,  12
    animcmd  396,  16
    animcmd  397,  12
    animcmd  398,  22
  FileAE52_Cmd_327:
    animcmd  400,  20
    animcmd  401,  12
    animcmd  402,  17
    animcmd  403,  12
    animcmd  404,  22
  FileAE52_Cmd_332:
    animcmd  399,   1
  FileAE52_Cmd_333:
    animcmd  405,   1
  FileAE52_Cmd_334:
    animcmd   71,   1
  FileAE52_Cmd_335:
    animcmd   72,   1
  FileAE52_Cmd_336:
    animcmd  193,   1
  FileAE52_Cmd_337:
    animcmd  194,   1
  FileAE52_Cmd_338:
    animcmd  287,   1
  FileAE52_Cmd_339:
    animcmd  288,   1
  FileAE52_Cmd_340:
    animcmd  406,   1
  FileAE52_Cmd_341:
    animcmd  408,   1
  FileAE52_Cmd_342:
    animcmd   75,   6
  FileAE52_Cmd_343:
    animcmd   85,   6
  FileAE52_Cmd_344:
    animcmd   75,   5
    animcmd   74,   5
    animcmd   75,   5
    animcmd   73,   5
  FileAE52_Cmd_348:
    animcmd   85,   5
    animcmd   84,   5
    animcmd   85,   5
    animcmd   83,   5
  FileAE52_Cmd_352:
    animcmd   75,   6
    animcmd   76,   4
    animcmd   77,   6
    animcmd   78,   7
    animcmd   79,   8
    animcmd   80,   9
    animcmd   81,  10
    animcmd   82,   7
  FileAE52_Cmd_360:
    animcmd   85,   6
    animcmd   86,   4
    animcmd   87,   6
    animcmd   88,   7
    animcmd   89,   8
    animcmd   90,   9
    animcmd   91,  10
    animcmd   92,   7
  FileAE52_Cmd_368:
    animcmd   75,   6
    animcmd   76,   4
    animcmd   77,   6
    animcmd   78,   7
    animcmd   79,   8
    animcmd   80,   9
    animcmd  211,  10
    animcmd  212,   7
  FileAE52_Cmd_376:
    animcmd   85,   6
    animcmd   86,   4
    animcmd   87,   6
    animcmd   88,   7
    animcmd   89,   8
    animcmd   90,   9
    animcmd  213,  10
    animcmd  214,   7
  FileAE52_Cmd_384:
    animcmd   75,   6
    animcmd   76,   4
    animcmd   77,   6
    animcmd   78,   7
    animcmd  289,   8
    animcmd  290,   9
    animcmd  291,  10
    animcmd  292,   7
  FileAE52_Cmd_392:
    animcmd   85,   6
    animcmd   86,   4
    animcmd   87,   6
    animcmd   88,   7
    animcmd  293,   8
    animcmd  294,   9
    animcmd  295,  10
    animcmd  296,   7
  FileAE52_Cmd_400:
    animcmd   93,   9
    animcmd   94,   9
    animcmd   95,   9
    animcmd   96,   7
    animcmd   97,   6
  FileAE52_Cmd_405:
    animcmd   98,   9
    animcmd   99,   9
    animcmd  100,   9
    animcmd  101,   7
    animcmd  102,   6
  FileAE52_Cmd_410:
    animcmd  406,   4
    animcmd  407,   4
  FileAE52_Cmd_412:
    animcmd  408,   4
    animcmd  409,   4
  FileAE52_Cmd_414:
    animcmd   61,   4
  FileAE52_Cmd_415:
    animcmd   64,   4
  FileAE52_Cmd_416:
    animcmd  179,   1
  FileAE52_Cmd_417:
    animcmd  186,   1
  FileAE52_Cmd_418:
    animcmd  276,   1
  FileAE52_Cmd_419:
    animcmd  280,   1
  FileAE52_Cmd_420:
    animcmd  388,  16
    animcmd  389,  16
    animcmd  390,  16
    animcmd  389,  16
  FileAE52_Cmd_424:
    animcmd  391,  16
    animcmd  392,  16
    animcmd  393,  16
    animcmd  392,  16
  FileAE52_Cmd_428:
    animcmd  195,   6
    animcmd  196,   6
    animcmd  197,  32
  FileAE52_Cmd_431:
    animcmd  203,   6
    animcmd  204,   6
    animcmd  205,  32
  FileAE52_Cmd_434:
    animcmd  198,   4
  FileAE52_Cmd_435:
    animcmd  206,   4
  FileAE52_Cmd_436:
    animcmd  199,   4
    animcmd  200,  32
  FileAE52_Cmd_438:
    animcmd  207,   4
    animcmd  208,  32
  FileAE52_Cmd_440:
    animcmd  199,   6
    animcmd  201,   6
    animcmd  202,   6
  FileAE52_Cmd_443:
    animcmd  207,   6
    animcmd  209,   6
    animcmd  210,   6
  FileAE52_Cmd_446:
    animcmd  202,   8
    animcmd  201,  12
    animcmd  198,  22
    animcmd  199,   4
    animcmd  200,   8
    animcmd  199,   4
    animcmd  201,   4
    animcmd  199,   4
    animcmd  200,   8
    animcmd  199,   4
    animcmd  201,   4
    animcmd  202,   4
  FileAE52_Cmd_458:
    animcmd  210,   8
    animcmd  209,  12
    animcmd  206,  22
    animcmd  207,   4
    animcmd  208,   8
    animcmd  207,   4
    animcmd  209,   4
    animcmd  207,   4
    animcmd  208,   8
    animcmd  207,   4
    animcmd  209,   4
    animcmd  210,   4
  FileAE52_Cmd_470:
    animcmd  414,   7
    animcmd  415,   6
    animcmd  416,   3
    animcmd  417,   4
    animcmd  418,  18
  FileAE52_Cmd_475:
    animcmd  419,   7
    animcmd  420,   6
    animcmd  421,   3
    animcmd  422,   4
    animcmd  423,  18
  FileAE52_Cmd_480:
    animcmd    0,   1
  FileAE52_Cmd_481:
    animcmd    0,   1
  FileAE52_Cmd_482:
    animcmd  237,   4
    animcmd   22,  32
  FileAE52_Cmd_484:
    animcmd  246,   4
    animcmd   28,  32
  FileAE52_Cmd_486:
    animcmd  410,   4
    animcmd  412,  32
  FileAE52_Cmd_488:
    animcmd  411,   4
    animcmd  413,  32

FileAE52_Tiles:
  .incbin "data/spriteset/skeletons.4bpp"
