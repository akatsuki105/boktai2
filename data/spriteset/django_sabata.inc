FileDE23_Header:
  .2byte 29 @ palStart
  .2byte 982 @ metaspriteCount
  .2byte 539 @ animationCount
  .2byte 8131 @ subspriteCount
  .2byte 1129 @ cmdCount
  .2byte 3072 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 19672 @ offsetToAnims
  .4byte 23984 @ offsetToSubsprites
  .4byte 89032 @ offsetToCmds
  .4byte 93548 @ offsetToTiles

FileDE23_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0xF48E, FileDE23_Obj_0,     6,          -25,  -51,   15,   10
  pose 0xF4AE, FileDE23_Obj_6,     6,          -25,  -51,   10,   10
  pose 0xF4CE, FileDE23_Obj_12,    7,          -25,  -51,   11,   10
  pose 0xF4EE, FileDE23_Obj_19,    6,          -25,  -51,   16,   10
  pose 0xF50E, FileDE23_Obj_25,    6,          -26,  -51,   14,   10
  pose 0xD4EE, FileDE23_Obj_31,    6,          -24,  -51,    9,   10
  pose 0xD4AE, FileDE23_Obj_37,    6,          -26,  -51,    9,   10
  pose 0xB75E, FileDE23_Obj_43,    6,          -24,  -52,   16,    9
  pose 0xB75F, FileDE23_Obj_49,    5,          -25,  -51,   15,    2
  pose 0xB760, FileDE23_Obj_54,    5,          -26,  -51,   14,    2
  pose 0xB761, FileDE23_Obj_59,    6,          -26,  -52,   14,    3
  pose 0xB762, FileDE23_Obj_65,    6,          -24,  -52,    8,    9
  pose 0xB763, FileDE23_Obj_71,    5,          -24,  -51,    9,    2
  pose 0xB764, FileDE23_Obj_76,    5,          -24,  -51,   10,    2
  pose 0xB765, FileDE23_Obj_81,    6,          -24,  -52,   10,    3
  pose 0xB77E, FileDE23_Obj_87,    5,          -30,  -52,   11,    9
  pose 0xB77F, FileDE23_Obj_92,    6,          -30,  -51,   11,   10
  pose 0xB780, FileDE23_Obj_98,    7,          -30,  -51,   18,    9
  pose 0xB781, FileDE23_Obj_105,   6,          -30,  -52,   17,    9
  pose 0xB782, FileDE23_Obj_111,   6,          -30,  -52,   18,    9
  pose 0xB783, FileDE23_Obj_117,   6,          -30,  -51,   11,   10
  pose 0xB784, FileDE23_Obj_123,   5,          -30,  -51,   11,    4
  pose 0xB785, FileDE23_Obj_128,   5,          -30,  -52,   11,    9
  pose 0xB79E, FileDE23_Obj_133,   7,          -35,  -51,   11,    9
  pose 0xB79F, FileDE23_Obj_140,   6,          -35,  -50,   11,   10
  pose 0xB7A0, FileDE23_Obj_146,   6,          -35,  -50,   11,   10
  pose 0xB7A1, FileDE23_Obj_152,   6,          -35,  -51,   11,    6
  pose 0xB7A2, FileDE23_Obj_158,   6,          -35,  -51,   11,    4
  pose 0xB7A3, FileDE23_Obj_164,   5,          -35,  -50,   11,    2
  pose 0xB7A4, FileDE23_Obj_169,   5,          -35,  -50,   11,    2
  pose 0xB7A5, FileDE23_Obj_174,   6,          -35,  -51,   11,    2
  pose 0xB7BE, FileDE23_Obj_180,   7,          -30,  -50,   17,    9
  pose 0xB7BF, FileDE23_Obj_187,   5,          -30,  -49,    9,   10
  pose 0xB7C0, FileDE23_Obj_192,   5,          -31,  -49,    9,    2
  pose 0xB7C1, FileDE23_Obj_197,   5,          -31,  -50,    9,    1
  pose 0xB7C2, FileDE23_Obj_202,   6,          -30,  -50,   11,    9
  pose 0xB7C3, FileDE23_Obj_208,   4,          -30,  -49,    9,    2
  pose 0xB7C4, FileDE23_Obj_212,   5,          -31,  -49,    9,    2
  pose 0xB7C5, FileDE23_Obj_217,   7,          -31,  -50,   16,    9
  pose 0xB7DE, FileDE23_Obj_224,   6,          -25,  -50,   15,    9
  pose 0xB7DF, FileDE23_Obj_230,   5,          -25,  -49,   15,    2
  pose 0xB7E0, FileDE23_Obj_235,   5,          -24,  -49,   16,    2
  pose 0xB7E1, FileDE23_Obj_240,   5,          -24,  -50,   16,    1
  pose 0xB7E2, FileDE23_Obj_245,   6,          -24,  -50,    9,    9
  pose 0xB7E3, FileDE23_Obj_251,   5,          -24,  -49,    9,    2
  pose 0xB7E4, FileDE23_Obj_256,   5,          -24,  -49,    8,    2
  pose 0xB7E5, FileDE23_Obj_261,   5,          -24,  -50,    8,    1
  pose 0xEAE2, FileDE23_Obj_266,   6,          -24,  -51,    9,    4
  pose 0xEB02, FileDE23_Obj_272,   7,          -24,  -51,   10,   10
  pose 0xEB22, FileDE23_Obj_279,   10,         -24,  -50,   16,   10
  pose 0xEB42, FileDE23_Obj_289,   7,          -26,  -50,   13,    9
  pose 0xEB62, FileDE23_Obj_296,   7,          -24,  -50,    8,    9
  pose 0xEADA, FileDE23_Obj_303,   6,          -24,  -51,    9,   10
  pose 0xEADB, FileDE23_Obj_309,   5,          -24,  -52,    9,    1
  pose 0xEADC, FileDE23_Obj_314,   5,          -24,  -52,    9,    1
  pose 0xEADD, FileDE23_Obj_319,   6,          -24,  -51,    9,    4
  pose 0xEADE, FileDE23_Obj_325,   6,          -24,  -51,    9,   10
  pose 0xEADF, FileDE23_Obj_331,   5,          -24,  -52,    9,    1
  pose 0xEAE0, FileDE23_Obj_336,   5,          -24,  -52,    9,    1
  pose 0xEAE1, FileDE23_Obj_341,   6,          -24,  -51,    9,    4
  pose 0xEAFA, FileDE23_Obj_347,   6,          -23,  -51,   11,    2
  pose 0xEAFB, FileDE23_Obj_353,   8,          -23,  -52,   11,    9
  pose 0xEAFC, FileDE23_Obj_361,   7,          -23,  -52,   11,    9
  pose 0xEAFD, FileDE23_Obj_368,   7,          -23,  -51,   11,    9
  pose 0xEAFE, FileDE23_Obj_375,   7,          -23,  -51,   11,    9
  pose 0xEAFF, FileDE23_Obj_382,   8,          -23,  -52,   11,    8
  pose 0xEB00, FileDE23_Obj_390,   8,          -23,  -52,   11,    9
  pose 0xEB01, FileDE23_Obj_398,   7,          -23,  -51,   11,   10
  pose 0xEB1A, FileDE23_Obj_405,   9,          -23,  -50,   17,   10
  pose 0xEB1B, FileDE23_Obj_414,   8,          -23,  -51,   16,    9
  pose 0xEB1C, FileDE23_Obj_422,   9,          -23,  -51,   17,    9
  pose 0xEB1D, FileDE23_Obj_431,   8,          -23,  -50,   17,    6
  pose 0xEB1E, FileDE23_Obj_439,   8,          -23,  -50,   17,    4
  pose 0xEB1F, FileDE23_Obj_447,   8,          -23,  -51,   16,    9
  pose 0xEB20, FileDE23_Obj_455,   9,          -23,  -51,   17,    9
  pose 0xEB21, FileDE23_Obj_464,   8,          -23,  -50,   17,    2
  pose 0xEB3A, FileDE23_Obj_472,   8,          -25,  -49,   14,    9
  pose 0xEB3B, FileDE23_Obj_480,   8,          -25,  -50,   13,    8
  pose 0xEB3C, FileDE23_Obj_488,   7,          -25,  -50,   14,    1
  pose 0xEB3D, FileDE23_Obj_495,   7,          -25,  -49,   14,    2
  pose 0xEB3E, FileDE23_Obj_502,   8,          -25,  -49,   14,   10
  pose 0xEB3F, FileDE23_Obj_510,   7,          -25,  -50,   13,    1
  pose 0xEB40, FileDE23_Obj_517,   7,          -25,  -50,   14,    1
  pose 0xEB41, FileDE23_Obj_524,   8,          -25,  -49,   14,    9
  pose 0xEB5A, FileDE23_Obj_532,   7,          -24,  -49,    8,   10
  pose 0xEB5B, FileDE23_Obj_539,   6,          -24,  -50,    8,    1
  pose 0xEB5C, FileDE23_Obj_545,   6,          -24,  -50,    8,    1
  pose 0xEB5D, FileDE23_Obj_551,   6,          -24,  -49,    8,    2
  pose 0xEB5E, FileDE23_Obj_557,   7,          -24,  -49,    9,   10
  pose 0xEB5F, FileDE23_Obj_564,   6,          -24,  -50,    8,    1
  pose 0xEB60, FileDE23_Obj_570,   6,          -24,  -50,    8,    1
  pose 0xEB61, FileDE23_Obj_576,   6,          -24,  -49,    8,    2
  pose 0xF52E, FileDE23_Obj_582,   5,          -22,  -52,   11,    9
  pose 0xF52F, FileDE23_Obj_587,   5,          -22,  -53,   11,    8
  pose 0xF530, FileDE23_Obj_592,   5,          -22,  -53,   11,    8
  pose 0xF531, FileDE23_Obj_597,   6,          -22,  -52,   15,    9
  pose 0xF532, FileDE23_Obj_603,   6,          -22,  -52,   11,    9
  pose 0xF533, FileDE23_Obj_609,   5,          -22,  -53,   11,    8
  pose 0xF534, FileDE23_Obj_614,   5,          -22,  -52,   11,    9
  pose 0xF535, FileDE23_Obj_619,   5,          -22,  -53,   11,    8
  pose 0xF536, FileDE23_Obj_624,   5,          -22,  -52,   11,    9
  pose 0xF537, FileDE23_Obj_629,   5,          -22,  -53,   11,    8
  pose 0xF56E, FileDE23_Obj_634,   6,          -23,  -50,   11,   10
  pose 0xF56F, FileDE23_Obj_640,   6,          -23,  -51,   11,    9
  pose 0xF570, FileDE23_Obj_646,   6,          -23,  -51,   11,   10
  pose 0xF571, FileDE23_Obj_652,   6,          -23,  -50,   11,   10
  pose 0xF572, FileDE23_Obj_658,   7,          -23,  -50,   11,   10
  pose 0xF573, FileDE23_Obj_665,   6,          -23,  -51,   11,   10
  pose 0xF574, FileDE23_Obj_671,   5,          -23,  -50,   11,    6
  pose 0xF575, FileDE23_Obj_676,   5,          -23,  -51,   11,    5
  pose 0xF576, FileDE23_Obj_681,   6,          -23,  -50,   11,   11
  pose 0xF577, FileDE23_Obj_687,   6,          -23,  -51,   11,   10
  pose 0x0F6B, FileDE23_Obj_693,   5,          -25,  -52,   18,    0
  pose 0x0F6C, FileDE23_Obj_698,   5,          -25,  -50,    9,    9
  pose 0x2C0B, FileDE23_Obj_703,   5,          -30,  -49,   10,   11
  pose 0x2C0C, FileDE23_Obj_708,   7,          -21,  -41,   20,   11
  pose 0x2C0D, FileDE23_Obj_715,   8,          -24,  -41,   20,    9
  pose 0x2C0E, FileDE23_Obj_723,   9,          -21,  -40,   20,   11
  pose 0x0FAB, FileDE23_Obj_732,   10,         -24,  -50,   21,    8
  pose 0x0FAC, FileDE23_Obj_742,   7,          -27,  -50,   13,    9
  pose 0x2C4B, FileDE23_Obj_749,   6,          -31,  -48,   17,    3
  pose 0x2C4C, FileDE23_Obj_755,   8,          -21,  -35,   20,   16
  pose 0x2C4D, FileDE23_Obj_763,   9,          -21,  -25,   20,   15
  pose 0x2C4E, FileDE23_Obj_772,   9,          -28,  -27,   20,   16
  pose 0xA58A, FileDE23_Obj_781,   11,         -38,  -25,   11,   17
  pose 0xA58B, FileDE23_Obj_792,   11,         -38,  -24,   13,   24
  pose 0xA58C, FileDE23_Obj_803,   6,          -29,  -38,    7,   13
  pose 0xA58D, FileDE23_Obj_809,   5,          -24,  -46,   10,    5
  pose 0xA5CA, FileDE23_Obj_814,   8,          -37,  -39,   11,   15
  pose 0xA5CB, FileDE23_Obj_822,   9,          -37,  -38,   13,   15
  pose 0xA5CC, FileDE23_Obj_831,   6,          -32,  -46,    7,   13
  pose 0xA5CD, FileDE23_Obj_837,   5,          -24,  -44,   17,    5
  pose 0x8F5B, FileDE23_Obj_842,   6,          -25,  -50,    9,    1
  pose 0x8F5C, FileDE23_Obj_848,   7,          -25,  -50,    9,    8
  pose 0x8F9B, FileDE23_Obj_855,   10,         -25,  -53,   16,    9
  pose 0x8F9C, FileDE23_Obj_865,   10,         -25,  -54,   16,    8
  pose 0x6333, FileDE23_Obj_875,   11,         -34,  -46,   13,    5
  pose 0x6334, FileDE23_Obj_886,   11,         -32,  -46,   16,    5
  pose 0x6335, FileDE23_Obj_897,   10,         -30,  -47,   16,    5
  pose 0x6336, FileDE23_Obj_907,   11,         -35,  -37,   16,   11
  pose 0xDC8A, FileDE23_Obj_918,   7,          -25,  -50,   15,   11
  pose 0xDC8B, FileDE23_Obj_925,   7,          -28,  -48,    9,   13
  pose 0xDC8C, FileDE23_Obj_932,   6,          -28,  -48,   13,   13
  pose 0xDC8D, FileDE23_Obj_938,   7,          -28,  -48,   15,   13
  pose 0xDC8E, FileDE23_Obj_945,   7,          -28,  -48,    7,   13
  pose 0xDD0A, FileDE23_Obj_952,   6,          -24,  -50,   10,   11
  pose 0xDD0B, FileDE23_Obj_958,   8,          -26,  -48,    8,   13
  pose 0xDD0C, FileDE23_Obj_966,   7,          -34,  -48,    8,   13
  pose 0xDD0D, FileDE23_Obj_973,   7,          -34,  -48,    8,   13
  pose 0xDD0E, FileDE23_Obj_980,   7,          -26,  -48,    8,   13
  pose 0xDCAA, FileDE23_Obj_987,   6,          -24,  -52,   16,    9
  pose 0xDCAB, FileDE23_Obj_993,   7,          -24,  -53,   16,    8
  pose 0xDCAC, FileDE23_Obj_1000,  7,          -24,  -53,   16,    8
  pose 0xDCAD, FileDE23_Obj_1007,  7,          -24,  -53,   16,    8
  pose 0xDCAE, FileDE23_Obj_1014,  7,          -24,  -53,   16,    8
  pose 0x375E, FileDE23_Obj_1021,  6,          -24,  -50,   11,    3
  pose 0x375F, FileDE23_Obj_1027,  5,          -24,  -50,    8,    6
  pose 0x3760, FileDE23_Obj_1032,  7,          -25,  -50,   11,    3
  pose 0x377E, FileDE23_Obj_1039,  5,          -26,  -50,   14,    3
  pose 0x377F, FileDE23_Obj_1044,  5,          -25,  -50,   10,    3
  pose 0x3780, FileDE23_Obj_1049,  6,          -27,  -50,   14,    3
  pose 0x379E, FileDE23_Obj_1055,  6,          -25,  -50,    8,    3
  pose 0x379F, FileDE23_Obj_1061,  7,          -25,  -50,   10,    6
  pose 0x37A0, FileDE23_Obj_1068,  8,          -25,  -50,   16,    3
  pose 0x37BE, FileDE23_Obj_1076,  5,          -25,  -50,    8,    5
  pose 0x37BF, FileDE23_Obj_1081,  6,          -25,  -50,    8,    6
  pose 0x37C0, FileDE23_Obj_1087,  7,          -25,  -50,   13,    3
  pose 0x37DE, FileDE23_Obj_1094,  6,          -25,  -50,   15,   11
  pose 0x37DF, FileDE23_Obj_1100,  6,          -24,  -50,    9,   11
  pose 0x37E0, FileDE23_Obj_1106,  8,          -24,  -50,    9,   11
  pose 0xF75B, FileDE23_Obj_1114,  7,          -24,  -50,   11,    3
  pose 0xF75C, FileDE23_Obj_1121,  7,          -25,  -50,    8,    6
  pose 0xF75D, FileDE23_Obj_1128,  7,          -25,  -50,   11,    3
  pose 0xF77B, FileDE23_Obj_1135,  6,          -26,  -50,   18,    3
  pose 0xF77C, FileDE23_Obj_1141,  6,          -27,  -54,   17,    3
  pose 0xF77D, FileDE23_Obj_1147,  6,          -27,  -53,   16,    3
  pose 0xF79B, FileDE23_Obj_1153,  7,          -25,  -50,   16,    3
  pose 0xF79C, FileDE23_Obj_1160,  8,          -25,  -50,   21,    6
  pose 0xF79D, FileDE23_Obj_1168,  8,          -25,  -50,   20,    3
  pose 0x5819, FileDE23_Obj_1176,  6,          -25,  -50,    9,    5
  pose 0x581A, FileDE23_Obj_1182,  8,          -25,  -50,   17,    6
  pose 0x581B, FileDE23_Obj_1190,  7,          -25,  -50,   16,    3
  pose 0xF7DB, FileDE23_Obj_1197,  7,          -25,  -50,   15,   11
  pose 0xF7DC, FileDE23_Obj_1204,  7,          -24,  -50,    9,   11
  pose 0xF7DD, FileDE23_Obj_1211,  8,          -24,  -50,    9,   11
  pose 0xAAAE, FileDE23_Obj_1219,  8,          -24,  -50,   11,    3
  pose 0xAAAF, FileDE23_Obj_1227,  7,          -25,  -50,    8,    6
  pose 0xAAB0, FileDE23_Obj_1234,  7,          -25,  -50,   11,    3
  pose 0xAACE, FileDE23_Obj_1241,  7,          -26,  -50,   17,    3
  pose 0xAACF, FileDE23_Obj_1248,  7,          -27,  -50,   17,    3
  pose 0xAAD0, FileDE23_Obj_1255,  7,          -27,  -50,   16,    3
  pose 0xAAEE, FileDE23_Obj_1262,  7,          -25,  -50,   16,    3
  pose 0xAAEF, FileDE23_Obj_1269,  8,          -25,  -50,   21,    6
  pose 0xAAF0, FileDE23_Obj_1277,  8,          -25,  -50,   20,    3
  pose 0xEDB3, FileDE23_Obj_1285,  6,          -25,  -50,    8,    5
  pose 0xEDB4, FileDE23_Obj_1291,  8,          -25,  -50,   15,    6
  pose 0xEDB5, FileDE23_Obj_1299,  7,          -25,  -50,   14,    3
  pose 0xAB2E, FileDE23_Obj_1306,  7,          -25,  -50,   15,   11
  pose 0xAB2F, FileDE23_Obj_1313,  7,          -24,  -50,    9,   11
  pose 0xAB30, FileDE23_Obj_1320,  8,          -24,  -50,    9,   11
  pose 0xFB6E, FileDE23_Obj_1328,  9,          -31,  -51,   10,   10
  pose 0xFB6F, FileDE23_Obj_1337,  10,         -30,  -51,   10,   10
  pose 0xFB70, FileDE23_Obj_1347,  6,          -44,  -50,    8,    3
  pose 0xFB71, FileDE23_Obj_1353,  9,          -56,  -81,   24,    3
  pose 0xFB72, FileDE23_Obj_1362,  10,         -27,  -50,   29,   11
  pose 0xFB73, FileDE23_Obj_1372,  10,         -27,  -50,   28,   11
  pose 0xFB8E, FileDE23_Obj_1382,  9,          -41,  -51,    8,   10
  pose 0xFB8F, FileDE23_Obj_1391,  9,          -40,  -51,    8,   10
  pose 0xFB90, FileDE23_Obj_1400,  9,          -32,  -58,   10,    3
  pose 0xFB91, FileDE23_Obj_1409,  8,          -32,  -83,   33,   13
  pose 0xFB92, FileDE23_Obj_1417,  9,          -25,  -50,   12,   11
  pose 0xFB93, FileDE23_Obj_1426,  10,         -25,  -50,   12,   11
  pose 0xFBAE, FileDE23_Obj_1436,  9,          -24,  -54,   11,   10
  pose 0xFBAF, FileDE23_Obj_1445,  10,         -24,  -53,   11,   10
  pose 0xFBB0, FileDE23_Obj_1455,  8,          -24,  -53,   11,    3
  pose 0xFBB1, FileDE23_Obj_1463,  11,         -33,  -57,   32,   23
  pose 0xFBB2, FileDE23_Obj_1474,  10,         -24,  -49,   11,    3
  pose 0xFBB3, FileDE23_Obj_1484,  9,          -24,  -49,   11,    3
  pose 0xFBCE, FileDE23_Obj_1493,  9,          -24,  -55,   15,   10
  pose 0xFBCF, FileDE23_Obj_1502,  8,          -24,  -54,   15,   10
  pose 0xFBD0, FileDE23_Obj_1510,  9,          -24,  -49,   24,    3
  pose 0xFBD1, FileDE23_Obj_1519,  9,          -30,  -49,   34,   15
  pose 0xFBD2, FileDE23_Obj_1528,  7,          -44,  -49,   19,    3
  pose 0xFBD3, FileDE23_Obj_1535,  7,          -43,  -49,   19,    3
  pose 0xFBEE, FileDE23_Obj_1542,  7,          -24,  -50,   27,   10
  pose 0xFBEF, FileDE23_Obj_1549,  7,          -24,  -50,   26,   10
  pose 0xFBF0, FileDE23_Obj_1556,  8,          -24,  -49,   28,   11
  pose 0xFBF1, FileDE23_Obj_1564,  10,         -40,  -49,   24,   31
  pose 0xFBF2, FileDE23_Obj_1574,  10,         -45,  -49,   15,   11
  pose 0xFBF3, FileDE23_Obj_1584,  9,          -44,  -49,   15,   11
  pose 0xECCE, FileDE23_Obj_1593,  10,         -25,  -51,   11,   10
  pose 0xECCF, FileDE23_Obj_1603,  10,         -25,  -52,   11,   10
  pose 0xECD0, FileDE23_Obj_1613,  11,         -25,  -73,   10,    3
  pose 0xECD1, FileDE23_Obj_1624,  9,          -25,  -64,   10,    3
  pose 0xECD2, FileDE23_Obj_1633,  11,         -25,  -85,    8,    3
  pose 0xECD3, FileDE23_Obj_1644,  9,          -25,  -76,    8,    6
  pose 0xECD4, FileDE23_Obj_1653,  9,          -25,  -64,   10,    3
  pose 0xECEE, FileDE23_Obj_1662,  11,         -26,  -51,   24,   10
  pose 0xECEF, FileDE23_Obj_1673,  11,         -25,  -51,   25,   10
  pose 0xECF0, FileDE23_Obj_1684,  12,         -25,  -65,   38,    5
  pose 0xECF1, FileDE23_Obj_1696,  9,          -25,  -58,   31,    3
  pose 0xECF2, FileDE23_Obj_1705,  11,         -25,  -76,   45,    3
  pose 0xECF3, FileDE23_Obj_1716,  10,         -25,  -69,   38,    6
  pose 0xECF4, FileDE23_Obj_1726,  9,          -25,  -58,   31,    3
  pose 0xED0E, FileDE23_Obj_1735,  11,         -52,  -51,   28,   18
  pose 0xED0F, FileDE23_Obj_1746,  10,         -51,  -51,   29,   18
  pose 0xED10, FileDE23_Obj_1756,  11,         -38,  -50,   50,   16
  pose 0xED11, FileDE23_Obj_1767,  10,         -39,  -50,   41,   16
  pose 0xED12, FileDE23_Obj_1777,  12,         -26,  -50,   62,   14
  pose 0xED13, FileDE23_Obj_1789,  9,          -27,  -50,   53,   14
  pose 0xED14, FileDE23_Obj_1798,  9,          -39,  -50,   41,   16
  pose 0xED2E, FileDE23_Obj_1807,  11,         -34,  -51,   16,   10
  pose 0xED2F, FileDE23_Obj_1818,  11,         -33,  -51,   17,   10
  pose 0xED30, FileDE23_Obj_1829,  11,         -24,  -50,   34,   23
  pose 0xED31, FileDE23_Obj_1840,  10,         -24,  -50,   27,   16
  pose 0xED32, FileDE23_Obj_1850,  12,         -24,  -49,   45,   30
  pose 0xED33, FileDE23_Obj_1862,  11,         -24,  -49,   38,   23
  pose 0xED34, FileDE23_Obj_1873,  10,         -24,  -50,   27,   16
  pose 0xED4E, FileDE23_Obj_1883,  10,         -24,  -51,   16,   10
  pose 0xED4F, FileDE23_Obj_1893,  9,          -24,  -51,   10,   10
  pose 0xED50, FileDE23_Obj_1902,  12,         -24,  -49,    9,   29
  pose 0xED51, FileDE23_Obj_1914,  11,         -24,  -49,   16,   18
  pose 0xED52, FileDE23_Obj_1925,  12,         -24,  -48,   16,   41
  pose 0xED53, FileDE23_Obj_1937,  9,          -24,  -48,    9,   30
  pose 0xED54, FileDE23_Obj_1946,  10,         -24,  -49,    9,   18
  pose 0x0F4C, FileDE23_Obj_1956,  9,          -24,  -63,   11,   10
  pose 0x0F4D, FileDE23_Obj_1965,  8,          -24,  -63,   11,    3
  pose 0x0F4E, FileDE23_Obj_1973,  8,          -24,  -64,   11,    3
  pose 0x0F4F, FileDE23_Obj_1981,  7,          -24,  -54,   11,    3
  pose 0x0F50, FileDE23_Obj_1988,  7,          -24,  -55,   11,    3
  pose 0x0F51, FileDE23_Obj_1995,  8,          -24,  -64,   11,    3
  pose 0x0F52, FileDE23_Obj_2003,  9,          -24,  -63,   11,   10
  pose 0x0F53, FileDE23_Obj_2012,  9,          -24,  -52,   12,   10
  pose 0x0F54, FileDE23_Obj_2021,  9,          -24,  -53,   12,   10
  pose 0x0F55, FileDE23_Obj_2030,  9,          -24,  -52,   12,   10
  pose 0x0F7D, FileDE23_Obj_2039,  8,          -24,  -64,   11,    3
  pose 0xEDF9, FileDE23_Obj_2047,  10,         -25,  -60,   20,   10
  pose 0x0F6D, FileDE23_Obj_2057,  10,         -25,  -61,   11,    3
  pose 0x0F6E, FileDE23_Obj_2067,  10,         -25,  -62,   12,    6
  pose 0x0F6F, FileDE23_Obj_2077,  12,         -28,  -55,   12,    3
  pose 0x0F70, FileDE23_Obj_2089,  12,         -27,  -56,   13,    3
  pose 0x0F71, FileDE23_Obj_2101,  10,         -31,  -62,   13,    5
  pose 0x0F72, FileDE23_Obj_2111,  10,         -30,  -60,   20,   10
  pose 0x0F73, FileDE23_Obj_2121,  10,         -30,  -50,   22,   10
  pose 0x0F74, FileDE23_Obj_2131,  11,         -24,  -50,   22,   10
  pose 0x0F75, FileDE23_Obj_2142,  11,         -24,  -50,   22,   10
  pose 0x0F9D, FileDE23_Obj_2153,  10,         -24,  -60,   20,   10
  pose 0x0F9E, FileDE23_Obj_2163,  10,         -25,  -62,   13,    3
  pose 0x0F8C, FileDE23_Obj_2173,  13,         -24,  -51,   30,   10
  pose 0x0F8D, FileDE23_Obj_2186,  10,         -24,  -58,   13,    3
  pose 0x0F8E, FileDE23_Obj_2196,  11,         -24,  -58,   14,    6
  pose 0x0F8F, FileDE23_Obj_2207,  12,         -34,  -57,   14,    5
  pose 0x0F90, FileDE23_Obj_2219,  11,         -33,  -58,   15,    3
  pose 0x0F91, FileDE23_Obj_2230,  10,         -36,  -58,   15,    3
  pose 0x0F92, FileDE23_Obj_2240,  11,         -35,  -50,   30,   10
  pose 0x0F93, FileDE23_Obj_2251,  12,         -34,  -49,   31,   10
  pose 0x0F94, FileDE23_Obj_2263,  12,         -24,  -49,   31,   10
  pose 0x0F95, FileDE23_Obj_2275,  13,         -24,  -49,   31,   10
  pose 0x0FBD, FileDE23_Obj_2288,  12,         -24,  -50,   30,   10
  pose 0x0FBE, FileDE23_Obj_2300,  11,         -24,  -58,   15,    5
  pose 0xF5F9, FileDE23_Obj_2311,  11,         -25,  -51,   20,   10
  pose 0x0FAD, FileDE23_Obj_2322,  9,          -25,  -55,   11,    3
  pose 0x0FAE, FileDE23_Obj_2331,  8,          -25,  -54,   12,    3
  pose 0x0FAF, FileDE23_Obj_2339,  9,          -28,  -58,    8,    3
  pose 0x0FB0, FileDE23_Obj_2348,  10,         -27,  -59,    8,    3
  pose 0x0FB1, FileDE23_Obj_2358,  9,          -32,  -54,   13,    3
  pose 0x0FB2, FileDE23_Obj_2367,  10,         -30,  -49,   20,   10
  pose 0x0FB3, FileDE23_Obj_2377,  10,         -30,  -48,   25,   20
  pose 0x0FB4, FileDE23_Obj_2387,  11,         -24,  -48,   25,   19
  pose 0x0FB5, FileDE23_Obj_2398,  10,         -24,  -48,   25,   20
  pose 0x0FDD, FileDE23_Obj_2408,  10,         -24,  -49,   20,   10
  pose 0x0FDE, FileDE23_Obj_2418,  8,          -25,  -54,   13,    3
  pose 0x0FCC, FileDE23_Obj_2426,  8,          -24,  -51,   11,   10
  pose 0x0FCD, FileDE23_Obj_2434,  9,          -24,  -53,   11,   11
  pose 0x0FCE, FileDE23_Obj_2443,  9,          -24,  -52,   11,   11
  pose 0x0FCF, FileDE23_Obj_2452,  9,          -24,  -58,   11,   11
  pose 0x0FD0, FileDE23_Obj_2461,  9,          -24,  -59,   11,   11
  pose 0x0FD1, FileDE23_Obj_2470,  9,          -24,  -52,   11,   11
  pose 0x0FD2, FileDE23_Obj_2479,  8,          -24,  -49,   11,   10
  pose 0x0FD3, FileDE23_Obj_2487,  11,         -24,  -48,   11,   28
  pose 0x0FD4, FileDE23_Obj_2498,  11,         -24,  -48,   11,   27
  pose 0x0FD5, FileDE23_Obj_2509,  11,         -24,  -48,   11,   28
  pose 0x0FFD, FileDE23_Obj_2520,  8,          -24,  -49,   11,   10
  pose 0x0FFE, FileDE23_Obj_2528,  9,          -24,  -52,   11,   11
  pose 0x4EB5, FileDE23_Obj_2537,  5,          -24,  -50,    8,    6
  pose 0x4EB6, FileDE23_Obj_2542,  6,          -25,  -50,   15,    3
  pose 0x4EB7, FileDE23_Obj_2548,  6,          -25,  -50,   15,    3
  pose 0x4EB8, FileDE23_Obj_2554,  7,          -25,  -50,    8,    6
  pose 0x4ED5, FileDE23_Obj_2561,  4,          -25,  -50,    7,    3
  pose 0x4ED6, FileDE23_Obj_2565,  6,          -27,  -50,   13,    3
  pose 0x4ED7, FileDE23_Obj_2571,  6,          -27,  -50,   13,    3
  pose 0x4ED8, FileDE23_Obj_2577,  6,          -27,  -50,   13,    3
  pose 0x4EF5, FileDE23_Obj_2583,  6,          -25,  -50,    8,    6
  pose 0x4EF6, FileDE23_Obj_2589,  7,          -32,  -50,   16,    3
  pose 0x4EF7, FileDE23_Obj_2596,  7,          -32,  -50,   16,    3
  pose 0x4EF8, FileDE23_Obj_2603,  8,          -25,  -50,   16,    6
  pose 0x4F15, FileDE23_Obj_2611,  5,          -25,  -50,    8,    6
  pose 0x4F16, FileDE23_Obj_2616,  7,          -36,  -50,   13,    3
  pose 0x4F17, FileDE23_Obj_2623,  7,          -36,  -50,   13,    3
  pose 0x4F18, FileDE23_Obj_2630,  8,          -25,  -50,   13,    6
  pose 0x4F35, FileDE23_Obj_2638,  5,          -24,  -50,    9,   11
  pose 0x4F36, FileDE23_Obj_2643,  7,          -34,  -50,    9,   11
  pose 0x4F37, FileDE23_Obj_2650,  7,          -33,  -50,    9,   11
  pose 0x4F38, FileDE23_Obj_2657,  7,          -24,  -50,    9,   11
  pose 0xEDDE, FileDE23_Obj_2664,  6,          -25,  -51,   15,   10
  pose 0xEDDF, FileDE23_Obj_2670,  6,          -24,  -45,   10,   15
  pose 0xEDE0, FileDE23_Obj_2676,  6,          -24,  -45,   10,   15
  pose 0xEDFE, FileDE23_Obj_2682,  6,          -25,  -51,   10,   10
  pose 0xEDFF, FileDE23_Obj_2688,  5,          -24,  -45,    9,   13
  pose 0xEE00, FileDE23_Obj_2693,  5,          -24,  -45,    9,   13
  pose 0xEE1E, FileDE23_Obj_2698,  7,          -24,  -49,   11,   10
  pose 0xEE1F, FileDE23_Obj_2705,  7,          -23,  -42,   11,   13
  pose 0xEE20, FileDE23_Obj_2712,  6,          -23,  -44,    9,   13
  pose 0xEE3E, FileDE23_Obj_2718,  6,          -24,  -50,   16,   10
  pose 0xEE3F, FileDE23_Obj_2724,  6,          -24,  -42,   12,   13
  pose 0xEE40, FileDE23_Obj_2730,  6,          -24,  -43,   12,   13
  pose 0xEE5E, FileDE23_Obj_2736,  6,          -26,  -51,   14,   10
  pose 0xEE5F, FileDE23_Obj_2742,  5,          -26,  -43,   10,    7
  pose 0xEE60, FileDE23_Obj_2747,  5,          -26,  -43,   10,    7
  pose 0x9240, FileDE23_Obj_2752,  6,          -25,  -51,   15,   10
  pose 0x9640, FileDE23_Obj_2758,  7,          -24,  -52,   10,   10
  pose 0x9A40, FileDE23_Obj_2765,  10,         -24,  -51,   11,   10
  pose 0x9E40, FileDE23_Obj_2775,  8,          -25,  -51,   16,   10
  pose 0xA240, FileDE23_Obj_2783,  7,          -26,  -51,   14,   10
  pose 0x9E3C, FileDE23_Obj_2790,  8,          -24,  -51,   15,   10
  pose 0x963C, FileDE23_Obj_2798,  8,          -26,  -52,   16,   10
  pose 0xEC38, FileDE23_Obj_2806,  7,          -24,  -52,   16,    9
  pose 0xEC58, FileDE23_Obj_2813,  6,          -25,  -51,   15,    2
  pose 0xEC78, FileDE23_Obj_2819,  6,          -26,  -51,   14,    2
  pose 0xEC98, FileDE23_Obj_2825,  7,          -26,  -52,   14,    3
  pose 0xECB8, FileDE23_Obj_2832,  7,          -24,  -52,   11,    9
  pose 0xECD8, FileDE23_Obj_2839,  6,          -24,  -51,   11,    2
  pose 0xECF8, FileDE23_Obj_2845,  6,          -24,  -51,   10,    2
  pose 0xED18, FileDE23_Obj_2851,  7,          -24,  -52,   10,    3
  pose 0xF038, FileDE23_Obj_2858,  9,          -23,  -53,   11,    9
  pose 0xF058, FileDE23_Obj_2867,  9,          -23,  -51,   11,   10
  pose 0xF078, FileDE23_Obj_2876,  10,         -23,  -52,   18,    9
  pose 0xF098, FileDE23_Obj_2886,  10,         -23,  -52,   17,    9
  pose 0xF0B8, FileDE23_Obj_2896,  10,         -23,  -53,   18,    9
  pose 0xF0D8, FileDE23_Obj_2906,  9,          -23,  -51,   11,   10
  pose 0xF0F8, FileDE23_Obj_2915,  8,          -23,  -52,   11,    2
  pose 0xF118, FileDE23_Obj_2923,  9,          -23,  -52,   11,    9
  pose 0xF438, FileDE23_Obj_2932,  8,          -35,  -54,   11,    9
  pose 0xF458, FileDE23_Obj_2940,  7,          -35,  -55,   11,   10
  pose 0xF478, FileDE23_Obj_2947,  7,          -34,  -55,   11,   10
  pose 0xF498, FileDE23_Obj_2954,  7,          -34,  -54,   11,    6
  pose 0xF4B8, FileDE23_Obj_2961,  7,          -35,  -54,   11,    4
  pose 0xF4D8, FileDE23_Obj_2968,  6,          -35,  -55,   11,    2
  pose 0xF4F8, FileDE23_Obj_2974,  6,          -34,  -55,   11,    2
  pose 0xF518, FileDE23_Obj_2980,  7,          -34,  -54,   11,    2
  pose 0xF838, FileDE23_Obj_2987,  9,          -25,  -50,   17,    9
  pose 0xF858, FileDE23_Obj_2996,  8,          -25,  -57,   10,   10
  pose 0xF878, FileDE23_Obj_3004,  7,          -25,  -49,    9,    2
  pose 0xF898, FileDE23_Obj_3011,  8,          -25,  -50,   10,    1
  pose 0xF8B8, FileDE23_Obj_3019,  8,          -25,  -50,   11,    9
  pose 0xF8D8, FileDE23_Obj_3027,  7,          -25,  -57,   10,    2
  pose 0xF8F8, FileDE23_Obj_3034,  7,          -25,  -49,    9,    2
  pose 0xF918, FileDE23_Obj_3041,  10,         -25,  -50,   16,    9
  pose 0xFC38, FileDE23_Obj_3051,  9,          -25,  -50,   15,    9
  pose 0xFC58, FileDE23_Obj_3060,  8,          -25,  -49,   15,    2
  pose 0xFC78, FileDE23_Obj_3068,  8,          -25,  -49,   16,    2
  pose 0xFC98, FileDE23_Obj_3076,  8,          -24,  -50,   16,    1
  pose 0xFCB8, FileDE23_Obj_3084,  9,          -25,  -50,   11,    9
  pose 0xFCD8, FileDE23_Obj_3093,  8,          -24,  -49,   11,    2
  pose 0xFCF8, FileDE23_Obj_3101,  8,          -25,  -49,   10,    2
  pose 0xFD18, FileDE23_Obj_3109,  8,          -24,  -50,   10,    1
  pose 0x5CBF, FileDE23_Obj_3117,  6,          -24,  -51,    9,    4
  pose 0x60BF, FileDE23_Obj_3123,  8,          -24,  -52,   10,   10
  pose 0x64BF, FileDE23_Obj_3131,  12,         -24,  -50,   16,   10
  pose 0x68BF, FileDE23_Obj_3143,  9,          -26,  -50,   13,    9
  pose 0x6CBF, FileDE23_Obj_3152,  8,          -25,  -52,    8,    9
  pose 0x5BBF, FileDE23_Obj_3160,  6,          -24,  -51,    9,   10
  pose 0x5BDF, FileDE23_Obj_3166,  5,          -24,  -52,    9,    1
  pose 0x5BFF, FileDE23_Obj_3171,  5,          -24,  -52,    9,    1
  pose 0x5C1F, FileDE23_Obj_3176,  6,          -24,  -51,    9,    4
  pose 0x5C3F, FileDE23_Obj_3182,  6,          -24,  -51,    9,   10
  pose 0x5C5F, FileDE23_Obj_3188,  5,          -24,  -52,    9,    1
  pose 0x5C7F, FileDE23_Obj_3193,  5,          -24,  -52,    9,    1
  pose 0x5C9F, FileDE23_Obj_3198,  6,          -24,  -51,    9,    4
  pose 0x5FBF, FileDE23_Obj_3204,  7,          -23,  -52,   11,    2
  pose 0x5FDF, FileDE23_Obj_3211,  9,          -23,  -52,   11,    9
  pose 0x5FFF, FileDE23_Obj_3220,  8,          -23,  -53,   11,    9
  pose 0x601F, FileDE23_Obj_3228,  8,          -23,  -51,   11,    9
  pose 0x603F, FileDE23_Obj_3236,  8,          -23,  -52,   11,    9
  pose 0x605F, FileDE23_Obj_3244,  9,          -23,  -52,   11,    8
  pose 0x607F, FileDE23_Obj_3253,  9,          -23,  -53,   11,    9
  pose 0x609F, FileDE23_Obj_3262,  8,          -23,  -51,   11,   10
  pose 0x63BF, FileDE23_Obj_3270,  12,         -23,  -50,   17,   10
  pose 0x63DF, FileDE23_Obj_3282,  11,         -23,  -51,   16,    9
  pose 0x63FF, FileDE23_Obj_3293,  11,         -23,  -51,   17,    9
  pose 0x641F, FileDE23_Obj_3304,  11,         -23,  -50,   17,    6
  pose 0x643F, FileDE23_Obj_3315,  11,         -23,  -50,   17,    4
  pose 0x645F, FileDE23_Obj_3326,  11,         -23,  -51,   16,    9
  pose 0x647F, FileDE23_Obj_3337,  11,         -23,  -51,   17,    9
  pose 0x649F, FileDE23_Obj_3348,  11,         -23,  -50,   17,    2
  pose 0x67BF, FileDE23_Obj_3359,  9,          -25,  -49,   14,    9
  pose 0x67DF, FileDE23_Obj_3368,  9,          -25,  -50,   13,    8
  pose 0x67FF, FileDE23_Obj_3377,  9,          -25,  -50,   14,    1
  pose 0x681F, FileDE23_Obj_3386,  9,          -25,  -57,   14,    2
  pose 0x683F, FileDE23_Obj_3395,  9,          -25,  -49,   14,   10
  pose 0x685F, FileDE23_Obj_3404,  8,          -25,  -50,   13,    1
  pose 0x687F, FileDE23_Obj_3412,  9,          -25,  -50,   14,    1
  pose 0x689F, FileDE23_Obj_3421,  10,         -25,  -57,   14,    9
  pose 0x6BBF, FileDE23_Obj_3431,  8,          -25,  -53,    8,   10
  pose 0x6BDF, FileDE23_Obj_3439,  7,          -24,  -54,    8,    1
  pose 0x6BFF, FileDE23_Obj_3446,  7,          -25,  -54,    8,    1
  pose 0x6C1F, FileDE23_Obj_3453,  7,          -24,  -53,    8,    2
  pose 0x6C3F, FileDE23_Obj_3460,  8,          -25,  -53,    9,   10
  pose 0x6C5F, FileDE23_Obj_3468,  7,          -24,  -54,    8,    1
  pose 0x6C7F, FileDE23_Obj_3475,  7,          -25,  -54,    8,    1
  pose 0x6C9F, FileDE23_Obj_3482,  7,          -24,  -53,    8,    2
  pose 0xA640, FileDE23_Obj_3489,  6,          -22,  -52,   15,    9
  pose 0xA660, FileDE23_Obj_3495,  6,          -22,  -53,   15,    8
  pose 0xA680, FileDE23_Obj_3501,  6,          -22,  -53,   15,    8
  pose 0xA6A0, FileDE23_Obj_3507,  7,          -22,  -52,   15,    9
  pose 0xA6C0, FileDE23_Obj_3514,  7,          -22,  -52,   15,    9
  pose 0xA6E0, FileDE23_Obj_3521,  6,          -22,  -53,   15,    8
  pose 0xA700, FileDE23_Obj_3527,  6,          -22,  -52,   15,    9
  pose 0xA720, FileDE23_Obj_3533,  6,          -22,  -53,   15,    8
  pose 0xA740, FileDE23_Obj_3539,  6,          -22,  -52,   15,    9
  pose 0xA760, FileDE23_Obj_3545,  6,          -22,  -53,   15,    8
  pose 0xAE40, FileDE23_Obj_3551,  7,          -23,  -51,   18,   10
  pose 0xAE60, FileDE23_Obj_3558,  7,          -23,  -52,   18,    9
  pose 0xAE80, FileDE23_Obj_3565,  7,          -23,  -52,   18,   10
  pose 0xAEA0, FileDE23_Obj_3572,  7,          -23,  -51,   18,   10
  pose 0xAEC0, FileDE23_Obj_3579,  8,          -23,  -51,   18,   10
  pose 0xAEE0, FileDE23_Obj_3587,  7,          -23,  -52,   18,   10
  pose 0xAF00, FileDE23_Obj_3594,  6,          -23,  -51,   18,    3
  pose 0xAF20, FileDE23_Obj_3600,  6,          -23,  -52,   18,    2
  pose 0xAF40, FileDE23_Obj_3606,  7,          -23,  -51,   18,   11
  pose 0xAF60, FileDE23_Obj_3613,  7,          -23,  -52,   18,   10
  pose 0xEDC3, FileDE23_Obj_3620,  8,          -42,  -53,   13,    2
  pose 0xEDE3, FileDE23_Obj_3628,  10,         -64,  -60,    9,    9
  pose 0x81C7, FileDE23_Obj_3638,  10,         -62,  -61,   11,   11
  pose 0x81E7, FileDE23_Obj_3648,  13,         -22,  -51,   27,   11
  pose 0x8207, FileDE23_Obj_3661,  11,         -27,  -47,   25,    9
  pose 0x8227, FileDE23_Obj_3672,  11,         -56,  -45,   22,   19
  pose 0xF5C3, FileDE23_Obj_3683,  12,         -35,  -58,   23,    8
  pose 0xF5E3, FileDE23_Obj_3695,  10,         -36,  -63,   13,    9
  pose 0x89C7, FileDE23_Obj_3705,  9,          -33,  -60,   17,    3
  pose 0x89E7, FileDE23_Obj_3714,  13,         -27,  -38,   24,   18
  pose 0x8A07, FileDE23_Obj_3727,  11,         -22,  -31,   24,   17
  pose 0x8A27, FileDE23_Obj_3738,  12,         -53,  -33,   24,   31
  pose 0xB1B6, FileDE23_Obj_3750,  14,         -46,  -32,   18,   32
  pose 0xB1D6, FileDE23_Obj_3764,  13,         -46,  -31,   18,   33
  pose 0xB1F6, FileDE23_Obj_3777,  7,          -28,  -38,    7,   13
  pose 0xB216, FileDE23_Obj_3784,  6,          -24,  -48,   11,    5
  pose 0xB9B6, FileDE23_Obj_3790,  9,          -40,  -46,   24,   18
  pose 0xB9D6, FileDE23_Obj_3799,  10,         -40,  -45,   24,   19
  pose 0xB9F6, FileDE23_Obj_3809,  8,          -28,  -46,    7,   13
  pose 0xBA16, FileDE23_Obj_3817,  7,          -24,  -51,   17,    5
  pose 0xEBD3, FileDE23_Obj_3824,  8,          -42,  -51,   13,    4
  pose 0xEBF3, FileDE23_Obj_3832,  9,          -42,  -50,   13,    8
  pose 0xF3D3, FileDE23_Obj_3841,  12,         -35,  -51,   23,    9
  pose 0xF3F3, FileDE23_Obj_3853,  12,         -35,  -58,   23,    8
  pose 0x66CE, FileDE23_Obj_3865,  12,         -35,  -46,   13,    5
  pose 0x66EE, FileDE23_Obj_3877,  12,         -35,  -46,   16,    5
  pose 0x670E, FileDE23_Obj_3889,  12,         -35,  -55,   16,    5
  pose 0x672E, FileDE23_Obj_3901,  13,         -43,  -44,   21,   20
  pose 0x91BD, FileDE23_Obj_3914,  7,          -25,  -50,   15,   11
  pose 0x91DD, FileDE23_Obj_3921,  7,          -28,  -48,   11,   13
  pose 0x91FD, FileDE23_Obj_3928,  7,          -28,  -48,   11,   13
  pose 0x921D, FileDE23_Obj_3935,  7,          -28,  -48,   12,   13
  pose 0x923D, FileDE23_Obj_3942,  7,          -28,  -48,   11,   13
  pose 0xA1BD, FileDE23_Obj_3949,  7,          -24,  -50,   10,   11
  pose 0xA1DD, FileDE23_Obj_3956,  8,          -26,  -48,    8,   13
  pose 0xA1FD, FileDE23_Obj_3964,  8,          -26,  -48,    8,   13
  pose 0xA21D, FileDE23_Obj_3972,  7,          -26,  -48,    8,   13
  pose 0xA23D, FileDE23_Obj_3979,  8,          -26,  -48,    8,   13
  pose 0x95BD, FileDE23_Obj_3987,  8,          -24,  -53,   16,    9
  pose 0x95DD, FileDE23_Obj_3995,  8,          -24,  -54,   16,    8
  pose 0x95FD, FileDE23_Obj_4003,  8,          -24,  -54,   16,    8
  pose 0x961D, FileDE23_Obj_4011,  8,          -24,  -53,   16,    8
  pose 0x963D, FileDE23_Obj_4019,  8,          -24,  -54,   16,    8
  pose 0xEC28, FileDE23_Obj_4027,  6,          -24,  -50,   11,    3
  pose 0xEC48, FileDE23_Obj_4033,  5,          -24,  -50,   12,    3
  pose 0xEC68, FileDE23_Obj_4038,  7,          -25,  -50,   12,    3
  pose 0xF028, FileDE23_Obj_4045,  7,          -26,  -50,   14,    3
  pose 0xF048, FileDE23_Obj_4052,  7,          -25,  -51,   10,    3
  pose 0xF068, FileDE23_Obj_4059,  8,          -27,  -51,   14,    3
  pose 0xF428, FileDE23_Obj_4067,  6,          -25,  -50,    8,    3
  pose 0xF448, FileDE23_Obj_4073,  7,          -24,  -50,   10,    3
  pose 0xF468, FileDE23_Obj_4080,  8,          -25,  -50,   16,    3
  pose 0xF828, FileDE23_Obj_4088,  8,          -25,  -58,    8,    3
  pose 0xF848, FileDE23_Obj_4096,  9,          -25,  -50,    8,    3
  pose 0xF868, FileDE23_Obj_4105,  11,         -25,  -50,   13,    3
  pose 0xFC28, FileDE23_Obj_4116,  8,          -25,  -50,   15,   11
  pose 0xFC48, FileDE23_Obj_4124,  8,          -25,  -50,    9,   11
  pose 0xFC68, FileDE23_Obj_4132,  9,          -25,  -50,    9,   11
  pose 0xEBE0, FileDE23_Obj_4141,  7,          -24,  -50,   11,    3
  pose 0xEC00, FileDE23_Obj_4148,  7,          -25,  -50,   12,    3
  pose 0xEC20, FileDE23_Obj_4155,  7,          -25,  -50,   12,    3
  pose 0xEFE0, FileDE23_Obj_4162,  8,          -26,  -50,   18,    3
  pose 0xF000, FileDE23_Obj_4170,  8,          -27,  -54,   17,    3
  pose 0xF020, FileDE23_Obj_4178,  8,          -27,  -53,   16,    3
  pose 0xF3E0, FileDE23_Obj_4186,  7,          -25,  -50,   16,    3
  pose 0xF400, FileDE23_Obj_4193,  8,          -25,  -50,   21,    3
  pose 0xF420, FileDE23_Obj_4201,  8,          -25,  -50,   20,    3
  pose 0x038D, FileDE23_Obj_4209,  9,          -25,  -58,    9,    3
  pose 0x03AD, FileDE23_Obj_4218,  11,         -25,  -50,   17,    3
  pose 0x03CD, FileDE23_Obj_4229,  11,         -25,  -50,   16,    3
  pose 0xFBE0, FileDE23_Obj_4240,  9,          -25,  -50,   15,   11
  pose 0xFC00, FileDE23_Obj_4249,  9,          -25,  -50,    9,   11
  pose 0xFC20, FileDE23_Obj_4258,  9,          -25,  -50,    9,   11
  pose 0x5637, FileDE23_Obj_4267,  8,          -24,  -50,   11,    3
  pose 0x5657, FileDE23_Obj_4275,  7,          -25,  -50,   12,    3
  pose 0x5677, FileDE23_Obj_4282,  7,          -25,  -50,   12,    3
  pose 0x5A37, FileDE23_Obj_4289,  9,          -26,  -50,   17,    3
  pose 0x5A57, FileDE23_Obj_4298,  9,          -27,  -51,   17,    3
  pose 0x5A77, FileDE23_Obj_4307,  9,          -27,  -51,   16,    3
  pose 0x5E37, FileDE23_Obj_4316,  7,          -25,  -50,   16,    3
  pose 0x5E57, FileDE23_Obj_4323,  8,          -25,  -50,   21,    3
  pose 0x5E77, FileDE23_Obj_4331,  8,          -25,  -50,   20,    3
  pose 0xB6DF, FileDE23_Obj_4339,  9,          -25,  -58,    8,    3
  pose 0xB6FF, FileDE23_Obj_4348,  11,         -25,  -50,   15,    3
  pose 0xB71F, FileDE23_Obj_4359,  11,         -25,  -50,   14,    3
  pose 0x6637, FileDE23_Obj_4370,  9,          -25,  -50,   15,   11
  pose 0x6657, FileDE23_Obj_4379,  9,          -25,  -50,    9,   11
  pose 0x6677, FileDE23_Obj_4388,  9,          -25,  -50,    9,   11
  pose 0x6E41, FileDE23_Obj_4397,  10,         -31,  -51,   10,   10
  pose 0x6E61, FileDE23_Obj_4407,  11,         -30,  -51,   10,   10
  pose 0x6E81, FileDE23_Obj_4418,  7,          -44,  -50,    9,    3
  pose 0x6EA1, FileDE23_Obj_4425,  10,         -56,  -81,   24,    3
  pose 0x6EC1, FileDE23_Obj_4435,  10,         -27,  -50,   29,   11
  pose 0x6EE1, FileDE23_Obj_4445,  10,         -27,  -50,   28,   11
  pose 0x7241, FileDE23_Obj_4455,  10,         -41,  -51,    9,   10
  pose 0x7261, FileDE23_Obj_4465,  10,         -40,  -52,    9,   10
  pose 0x7281, FileDE23_Obj_4475,  10,         -32,  -58,   10,    3
  pose 0x72A1, FileDE23_Obj_4485,  9,          -32,  -83,   33,   13
  pose 0x72C1, FileDE23_Obj_4494,  13,         -25,  -51,   12,   11
  pose 0x72E1, FileDE23_Obj_4507,  13,         -25,  -51,   12,   11
  pose 0x7641, FileDE23_Obj_4520,  12,         -24,  -54,   11,   10
  pose 0x7661, FileDE23_Obj_4532,  12,         -24,  -53,   11,   10
  pose 0x7681, FileDE23_Obj_4544,  11,         -24,  -53,   11,    3
  pose 0x76A1, FileDE23_Obj_4555,  14,         -33,  -57,   32,   23
  pose 0x76C1, FileDE23_Obj_4569,  11,         -24,  -49,   11,    3
  pose 0x76E1, FileDE23_Obj_4580,  10,         -24,  -49,   11,    3
  pose 0x7A41, FileDE23_Obj_4590,  10,         -24,  -58,   15,   10
  pose 0x7A61, FileDE23_Obj_4600,  10,         -24,  -54,   15,   10
  pose 0x7A81, FileDE23_Obj_4610,  11,         -24,  -57,   24,    3
  pose 0x7AA1, FileDE23_Obj_4621,  11,         -30,  -49,   34,   15
  pose 0x7AC1, FileDE23_Obj_4632,  9,          -44,  -49,   19,    3
  pose 0x7AE1, FileDE23_Obj_4641,  9,          -43,  -49,   19,    3
  pose 0x7E41, FileDE23_Obj_4650,  9,          -24,  -50,   27,   10
  pose 0x7E61, FileDE23_Obj_4659,  9,          -25,  -50,   26,   10
  pose 0x7E81, FileDE23_Obj_4668,  10,         -24,  -49,   28,   11
  pose 0x7EA1, FileDE23_Obj_4678,  12,         -40,  -49,   24,   31
  pose 0x7EC1, FileDE23_Obj_4690,  11,         -45,  -49,   15,   11
  pose 0x7EE1, FileDE23_Obj_4701,  11,         -44,  -49,   15,   11
  pose 0x9A3F, FileDE23_Obj_4712,  10,         -25,  -51,   11,   10
  pose 0x9A5F, FileDE23_Obj_4722,  10,         -25,  -52,   11,   10
  pose 0x9A7F, FileDE23_Obj_4732,  11,         -25,  -73,   10,    3
  pose 0x9A9F, FileDE23_Obj_4743,  9,          -25,  -64,   10,    3
  pose 0x9ABF, FileDE23_Obj_4752,  11,         -25,  -85,    8,    3
  pose 0x9ADF, FileDE23_Obj_4763,  9,          -25,  -76,    8,    3
  pose 0x9AFF, FileDE23_Obj_4772,  9,          -25,  -64,   10,    3
  pose 0x9E3F, FileDE23_Obj_4781,  15,         -26,  -51,   24,   10
  pose 0x9E5F, FileDE23_Obj_4796,  15,         -25,  -52,   25,   10
  pose 0x9E7F, FileDE23_Obj_4811,  15,         -25,  -65,   38,    3
  pose 0x9E9F, FileDE23_Obj_4826,  13,         -25,  -58,   31,    3
  pose 0x9EBF, FileDE23_Obj_4839,  15,         -25,  -76,   45,    3
  pose 0x9EDF, FileDE23_Obj_4854,  13,         -25,  -69,   38,    3
  pose 0x9EFF, FileDE23_Obj_4867,  13,         -25,  -58,   31,    3
  pose 0xA23F, FileDE23_Obj_4880,  12,         -52,  -51,   28,   18
  pose 0xA25F, FileDE23_Obj_4892,  11,         -51,  -51,   29,   18
  pose 0xA27F, FileDE23_Obj_4903,  12,         -38,  -50,   50,   16
  pose 0xA29F, FileDE23_Obj_4915,  10,         -39,  -50,   41,   16
  pose 0xA2BF, FileDE23_Obj_4925,  12,         -26,  -50,   62,   14
  pose 0xA2DF, FileDE23_Obj_4937,  10,         -27,  -50,   53,   14
  pose 0xA2FF, FileDE23_Obj_4947,  10,         -39,  -50,   41,   16
  pose 0xA63F, FileDE23_Obj_4957,  13,         -34,  -59,   16,   10
  pose 0xA65F, FileDE23_Obj_4970,  13,         -33,  -51,   17,   10
  pose 0xA67F, FileDE23_Obj_4983,  12,         -24,  -58,   34,   23
  pose 0xA69F, FileDE23_Obj_4995,  11,         -24,  -50,   27,   16
  pose 0xA6BF, FileDE23_Obj_5006,  14,         -24,  -57,   45,   30
  pose 0xA6DF, FileDE23_Obj_5020,  12,         -24,  -49,   38,   23
  pose 0xA6FF, FileDE23_Obj_5032,  11,         -24,  -50,   27,   16
  pose 0xAA3F, FileDE23_Obj_5043,  11,         -24,  -51,   15,   10
  pose 0xAA5F, FileDE23_Obj_5054,  11,         -24,  -51,   15,   10
  pose 0xAA7F, FileDE23_Obj_5065,  14,         -24,  -49,   14,   29
  pose 0xAA9F, FileDE23_Obj_5079,  12,         -25,  -49,   14,   18
  pose 0xAABF, FileDE23_Obj_5091,  13,         -24,  -48,   13,   41
  pose 0xAADF, FileDE23_Obj_5104,  11,         -25,  -48,   13,   30
  pose 0xAAFF, FileDE23_Obj_5115,  12,         -25,  -49,   13,   18
  pose 0xE9E3, FileDE23_Obj_5127,  9,          -24,  -63,   11,   10
  pose 0xEA03, FileDE23_Obj_5136,  8,          -24,  -63,   11,    3
  pose 0xEA23, FileDE23_Obj_5144,  8,          -24,  -64,   11,    3
  pose 0xEA43, FileDE23_Obj_5152,  7,          -24,  -54,   11,    3
  pose 0xEA63, FileDE23_Obj_5159,  7,          -24,  -55,   11,    3
  pose 0xEA83, FileDE23_Obj_5166,  8,          -24,  -64,   11,    3
  pose 0xEAA3, FileDE23_Obj_5174,  9,          -24,  -63,   11,   10
  pose 0xEAC3, FileDE23_Obj_5183,  9,          -24,  -52,   12,   10
  pose 0xEAE3, FileDE23_Obj_5192,  9,          -24,  -53,   12,   10
  pose 0xEB03, FileDE23_Obj_5201,  9,          -24,  -52,   12,   10
  pose 0xF003, FileDE23_Obj_5210,  8,          -24,  -64,   11,    3
  pose 0xBF9F, FileDE23_Obj_5218,  11,         -24,  -60,   20,   10
  pose 0xEE03, FileDE23_Obj_5229,  11,         -25,  -61,   11,    3
  pose 0xEE23, FileDE23_Obj_5240,  11,         -25,  -62,   12,    3
  pose 0xEE43, FileDE23_Obj_5251,  13,         -28,  -55,   12,    3
  pose 0xEE63, FileDE23_Obj_5264,  13,         -27,  -56,   13,    3
  pose 0xEE83, FileDE23_Obj_5277,  11,         -25,  -62,   13,    3
  pose 0xEEA3, FileDE23_Obj_5288,  11,         -24,  -60,   20,   10
  pose 0xEEC3, FileDE23_Obj_5299,  12,         -24,  -50,   22,   10
  pose 0xEEE3, FileDE23_Obj_5311,  12,         -24,  -51,   22,   10
  pose 0xEF03, FileDE23_Obj_5323,  12,         -24,  -51,   22,   10
  pose 0xF403, FileDE23_Obj_5335,  11,         -24,  -60,   20,   10
  pose 0xF423, FileDE23_Obj_5346,  11,         -25,  -62,   13,    3
  pose 0xF1E3, FileDE23_Obj_5357,  15,         -24,  -51,   30,   10
  pose 0xF203, FileDE23_Obj_5372,  13,         -24,  -58,   13,    3
  pose 0xF223, FileDE23_Obj_5385,  13,         -24,  -58,   14,    3
  pose 0xF243, FileDE23_Obj_5398,  14,         -34,  -57,   14,    3
  pose 0xF263, FileDE23_Obj_5412,  14,         -33,  -58,   15,    3
  pose 0xF283, FileDE23_Obj_5426,  13,         -24,  -58,   15,    3
  pose 0xF2A3, FileDE23_Obj_5439,  14,         -24,  -50,   30,   10
  pose 0xF2C3, FileDE23_Obj_5453,  15,         -24,  -49,   31,   10
  pose 0xF2E3, FileDE23_Obj_5468,  15,         -24,  -49,   31,   10
  pose 0xF303, FileDE23_Obj_5483,  15,         -24,  -49,   31,   10
  pose 0xF803, FileDE23_Obj_5498,  14,         -24,  -50,   30,   10
  pose 0xF823, FileDE23_Obj_5512,  13,         -24,  -58,   15,    3
  pose 0xBFA0, FileDE23_Obj_5525,  13,         -25,  -51,   20,   10
  pose 0xF603, FileDE23_Obj_5538,  10,         -24,  -58,   11,    3
  pose 0xF623, FileDE23_Obj_5548,  10,         -25,  -54,   12,    3
  pose 0xF643, FileDE23_Obj_5558,  11,         -28,  -58,    8,    3
  pose 0xF663, FileDE23_Obj_5569,  11,         -27,  -59,    8,    3
  pose 0xF683, FileDE23_Obj_5580,  10,         -25,  -54,   13,    3
  pose 0xF6A3, FileDE23_Obj_5590,  12,         -24,  -49,   20,   10
  pose 0xF6C3, FileDE23_Obj_5602,  12,         -24,  -56,   25,   20
  pose 0xF6E3, FileDE23_Obj_5614,  12,         -24,  -48,   25,   19
  pose 0xF703, FileDE23_Obj_5626,  12,         -24,  -48,   25,   20
  pose 0xFC03, FileDE23_Obj_5638,  12,         -24,  -49,   20,   10
  pose 0xFC23, FileDE23_Obj_5650,  10,         -25,  -54,   13,    3
  pose 0xF9E3, FileDE23_Obj_5660,  9,          -25,  -51,   11,   10
  pose 0xFA03, FileDE23_Obj_5669,  10,         -24,  -53,   11,   11
  pose 0xFA23, FileDE23_Obj_5679,  10,         -25,  -52,   11,   11
  pose 0xFA43, FileDE23_Obj_5689,  10,         -25,  -58,   11,   11
  pose 0xFA63, FileDE23_Obj_5699,  10,         -25,  -59,   11,   11
  pose 0xFA83, FileDE23_Obj_5709,  11,         -25,  -52,   11,   11
  pose 0xFAA3, FileDE23_Obj_5720,  10,         -24,  -51,   11,   10
  pose 0xFAC3, FileDE23_Obj_5730,  13,         -24,  -52,   11,   28
  pose 0xFAE3, FileDE23_Obj_5743,  12,         -25,  -52,   11,   27
  pose 0xFB03, FileDE23_Obj_5755,  12,         -25,  -52,   11,   28
  pose 0x0003, FileDE23_Obj_5767,  9,          -25,  -53,   11,   10
  pose 0x0023, FileDE23_Obj_5776,  10,         -25,  -52,   11,   11
  pose 0xD70B, FileDE23_Obj_5786,  5,          -24,  -50,   11,    3
  pose 0xD72B, FileDE23_Obj_5791,  7,          -25,  -50,   12,    3
  pose 0xD74B, FileDE23_Obj_5798,  7,          -25,  -50,   12,    3
  pose 0xD76B, FileDE23_Obj_5805,  7,          -25,  -50,   12,    3
  pose 0xDB0B, FileDE23_Obj_5812,  6,          -25,  -51,    8,    3
  pose 0xDB2B, FileDE23_Obj_5818,  8,          -27,  -51,   13,    3
  pose 0xDB4B, FileDE23_Obj_5826,  8,          -27,  -50,   13,    3
  pose 0xDB6B, FileDE23_Obj_5834,  8,          -27,  -51,   13,    3
  pose 0xDF0B, FileDE23_Obj_5842,  6,          -24,  -50,    8,    3
  pose 0xDF2B, FileDE23_Obj_5848,  8,          -25,  -50,   16,    3
  pose 0xDF4B, FileDE23_Obj_5856,  8,          -25,  -50,   16,    3
  pose 0xDF6B, FileDE23_Obj_5864,  8,          -25,  -50,   16,    3
  pose 0xE30B, FileDE23_Obj_5872,  8,          -25,  -50,    8,    3
  pose 0xE32B, FileDE23_Obj_5880,  11,         -25,  -50,   13,    3
  pose 0xE34B, FileDE23_Obj_5891,  11,         -25,  -58,   13,    3
  pose 0xE36B, FileDE23_Obj_5902,  11,         -25,  -50,   13,    3
  pose 0xE70B, FileDE23_Obj_5913,  7,          -25,  -50,    9,   11
  pose 0xE72B, FileDE23_Obj_5920,  9,          -25,  -50,    9,   11
  pose 0xE74B, FileDE23_Obj_5929,  9,          -24,  -50,    9,   11
  pose 0xE76B, FileDE23_Obj_5938,  9,          -25,  -50,    9,   11
  pose 0xBC3F, FileDE23_Obj_5947,  6,          -25,  -51,   15,   10
  pose 0xBC5F, FileDE23_Obj_5953,  6,          -24,  -45,   10,   13
  pose 0xBC7F, FileDE23_Obj_5959,  6,          -24,  -45,   10,   13
  pose 0xC03F, FileDE23_Obj_5965,  7,          -24,  -52,   10,   10
  pose 0xC05F, FileDE23_Obj_5972,  6,          -24,  -46,   11,   13
  pose 0xC07F, FileDE23_Obj_5978,  6,          -24,  -46,   10,   13
  pose 0xC43F, FileDE23_Obj_5984,  10,         -24,  -51,   11,   10
  pose 0xC45F, FileDE23_Obj_5994,  6,          -35,  -50,   10,   13
  pose 0xC47F, FileDE23_Obj_6000,  6,          -35,  -50,   10,   13
  pose 0xC83F, FileDE23_Obj_6006,  8,          -24,  -58,   16,   10
  pose 0xC85F, FileDE23_Obj_6014,  8,          -24,  -50,   12,   13
  pose 0xC87F, FileDE23_Obj_6022,  8,          -24,  -43,   12,   13
  pose 0xCC3F, FileDE23_Obj_6030,  7,          -26,  -51,   14,   10
  pose 0xCC5F, FileDE23_Obj_6037,  7,          -26,  -45,   10,    7
  pose 0xCC7F, FileDE23_Obj_6044,  7,          -26,  -45,   10,    7
  pose 0x9E83, FileDE23_Obj_6051,  17,         -53,  -46,   37,    5
  pose 0x9E84, FileDE23_Obj_6068,  17,         -54,  -47,   38,    5
  pose 0x9EA3, FileDE23_Obj_6085,  10,         -35,  -48,   21,    9
  pose 0x9EE3, FileDE23_Obj_6095,  11,         -39,  -41,   24,   20
  pose 0x48A9, FileDE23_Obj_6106,  14,         -24,  -45,   14,   10
  pose 0xC8A9, FileDE23_Obj_6120,  9,          -24,  -45,   19,   10
  pose 0x48AA, FileDE23_Obj_6129,  10,         -28,  -48,   15,   10
  pose 0xC8AA, FileDE23_Obj_6139,  11,         -24,  -45,   13,   10
  pose 0x48AB, FileDE23_Obj_6150,  10,         -24,  -35,   14,   10
  pose 0x07B5, FileDE23_Obj_6160,  11,         -39,  -47,   20,    9
  pose 0x0BB5, FileDE23_Obj_6171,  11,         -32,  -46,   20,   10
  pose 0xF719, FileDE23_Obj_6182,  11,         -24,  -47,   19,    9
  pose 0x13B5, FileDE23_Obj_6193,  11,         -39,  -48,   19,    9
  pose 0x17B5, FileDE23_Obj_6204,  11,         -32,  -47,   20,    9
  pose 0x1BB5, FileDE23_Obj_6215,  11,         -25,  -46,   20,   10
  pose 0x1FB5, FileDE23_Obj_6226,  10,         -40,  -47,   19,    2
  pose 0x23B5, FileDE23_Obj_6236,  11,         -30,  -48,   19,    9
  pose 0x07B6, FileDE23_Obj_6247,  9,          -35,  -49,   20,    9
  pose 0x0BB6, FileDE23_Obj_6256,  9,          -35,  -45,   19,   10
  pose 0x0FB6, FileDE23_Obj_6265,  8,          -33,  -44,   18,    2
  pose 0x13B6, FileDE23_Obj_6273,  8,          -34,  -48,   17,    1
  pose 0x17B6, FileDE23_Obj_6281,  9,          -35,  -46,   16,    9
  pose 0x1BB6, FileDE23_Obj_6290,  8,          -34,  -45,   17,    2
  pose 0x1FB6, FileDE23_Obj_6298,  8,          -35,  -48,   18,    2
  pose 0x23B6, FileDE23_Obj_6306,  9,          -35,  -47,   19,    9
  pose 0x1681, FileDE23_Obj_6315,  9,          -24,  -45,   19,   10
  pose 0x1A81, FileDE23_Obj_6324,  9,          -24,  -46,   19,   10
  pose 0x1E81, FileDE23_Obj_6333,  9,          -24,  -47,   19,   10
  pose 0x2281, FileDE23_Obj_6342,  9,          -24,  -48,   19,   10
  pose 0x2681, FileDE23_Obj_6351,  9,          -24,  -47,   21,   10
  pose 0x2A81, FileDE23_Obj_6360,  8,          -24,  -46,   19,   10
  pose 0x2E81, FileDE23_Obj_6368,  9,          -24,  -45,   20,   10
  pose 0x1682, FileDE23_Obj_6377,  11,         -24,  -45,   17,   10
  pose 0x1A82, FileDE23_Obj_6388,  11,         -24,  -46,   17,   10
  pose 0x1E82, FileDE23_Obj_6399,  12,         -24,  -45,   21,   10
  pose 0x2282, FileDE23_Obj_6411,  12,         -24,  -44,   22,   10
  pose 0x2682, FileDE23_Obj_6423,  11,         -24,  -42,   17,   10
  pose 0x2A82, FileDE23_Obj_6434,  11,         -24,  -41,   17,   10
  pose 0x2E82, FileDE23_Obj_6445,  11,         -24,  -43,   17,   10
  pose 0x9251, FileDE23_Obj_6456,  6,          -25,  -51,   15,   10
  pose 0x9651, FileDE23_Obj_6462,  6,          -25,  -50,   10,   10
  pose 0x9A51, FileDE23_Obj_6468,  7,          -25,  -50,   11,   10
  pose 0x9E51, FileDE23_Obj_6475,  6,          -25,  -49,   16,   10
  pose 0xA251, FileDE23_Obj_6481,  7,          -26,  -49,   14,   10
  pose 0x9E4D, FileDE23_Obj_6488,  6,          -24,  -49,    9,   10
  pose 0x964D, FileDE23_Obj_6494,  6,          -26,  -50,    9,   10
  pose 0xEC49, FileDE23_Obj_6500,  6,          -24,  -52,   16,    9
  pose 0xEC69, FileDE23_Obj_6506,  5,          -25,  -51,   15,    2
  pose 0xEC89, FileDE23_Obj_6511,  5,          -26,  -51,   14,    2
  pose 0xECA9, FileDE23_Obj_6516,  6,          -26,  -52,   14,    3
  pose 0xECC9, FileDE23_Obj_6522,  6,          -24,  -52,    8,    9
  pose 0xECE9, FileDE23_Obj_6528,  5,          -24,  -51,    9,    2
  pose 0xED09, FileDE23_Obj_6533,  5,          -24,  -51,   10,    2
  pose 0xED29, FileDE23_Obj_6538,  6,          -24,  -52,   10,    3
  pose 0xF049, FileDE23_Obj_6544,  5,          -30,  -51,   11,    9
  pose 0xF069, FileDE23_Obj_6549,  6,          -30,  -50,   11,   10
  pose 0xF089, FileDE23_Obj_6555,  7,          -30,  -50,   18,    9
  pose 0xF0A9, FileDE23_Obj_6562,  6,          -30,  -51,   17,    9
  pose 0xF0C9, FileDE23_Obj_6568,  6,          -30,  -51,   18,    9
  pose 0xF0E9, FileDE23_Obj_6574,  6,          -30,  -50,   11,   10
  pose 0xF109, FileDE23_Obj_6580,  5,          -30,  -50,   11,    4
  pose 0xF129, FileDE23_Obj_6585,  5,          -30,  -51,   11,    9
  pose 0xF449, FileDE23_Obj_6590,  7,          -35,  -50,   11,    9
  pose 0xF469, FileDE23_Obj_6597,  6,          -35,  -49,   11,   10
  pose 0xF489, FileDE23_Obj_6603,  6,          -35,  -49,   11,   10
  pose 0xF4A9, FileDE23_Obj_6609,  6,          -35,  -49,   11,    6
  pose 0xF4C9, FileDE23_Obj_6615,  6,          -35,  -50,   11,    4
  pose 0xF4E9, FileDE23_Obj_6621,  5,          -35,  -49,   11,    2
  pose 0xF509, FileDE23_Obj_6626,  5,          -35,  -49,   11,    2
  pose 0xF529, FileDE23_Obj_6631,  6,          -35,  -49,   11,    2
  pose 0xF849, FileDE23_Obj_6637,  7,          -30,  -48,   17,    9
  pose 0xF869, FileDE23_Obj_6644,  5,          -30,  -47,    9,   10
  pose 0xF889, FileDE23_Obj_6649,  5,          -31,  -47,    9,    2
  pose 0xF8A9, FileDE23_Obj_6654,  5,          -31,  -47,    9,    1
  pose 0xF8C9, FileDE23_Obj_6659,  6,          -30,  -48,   11,    9
  pose 0xF8E9, FileDE23_Obj_6665,  4,          -30,  -47,    9,    2
  pose 0xF909, FileDE23_Obj_6669,  5,          -31,  -47,    9,    2
  pose 0xF929, FileDE23_Obj_6674,  7,          -31,  -47,   16,    9
  pose 0xFC49, FileDE23_Obj_6681,  7,          -25,  -48,   15,    9
  pose 0xFC69, FileDE23_Obj_6688,  6,          -25,  -47,   15,    2
  pose 0xFC89, FileDE23_Obj_6694,  6,          -25,  -47,   16,    2
  pose 0xFCA9, FileDE23_Obj_6700,  6,          -25,  -47,   16,    1
  pose 0xFCC9, FileDE23_Obj_6706,  7,          -25,  -48,    9,    9
  pose 0xFCE9, FileDE23_Obj_6713,  6,          -25,  -47,    9,    2
  pose 0xFD09, FileDE23_Obj_6719,  6,          -25,  -47,    8,    2
  pose 0xFD29, FileDE23_Obj_6725,  6,          -25,  -47,    8,    1
  pose 0x5CD0, FileDE23_Obj_6731,  6,          -24,  -51,    9,    4
  pose 0x60D0, FileDE23_Obj_6737,  7,          -24,  -50,   10,   10
  pose 0x64D0, FileDE23_Obj_6744,  10,         -24,  -49,   16,   10
  pose 0x68D0, FileDE23_Obj_6754,  7,          -26,  -48,   13,    9
  pose 0x6CD0, FileDE23_Obj_6761,  8,          -25,  -48,    8,    9
  pose 0x5BD0, FileDE23_Obj_6769,  6,          -24,  -51,    9,   10
  pose 0x5BF0, FileDE23_Obj_6775,  5,          -24,  -52,    9,    1
  pose 0x5C10, FileDE23_Obj_6780,  5,          -24,  -52,    9,    1
  pose 0x5C30, FileDE23_Obj_6785,  6,          -24,  -51,    9,    4
  pose 0x5C50, FileDE23_Obj_6791,  6,          -24,  -51,    9,   10
  pose 0x5C70, FileDE23_Obj_6797,  5,          -24,  -52,    9,    1
  pose 0x5C90, FileDE23_Obj_6802,  5,          -24,  -52,    9,    1
  pose 0x5CB0, FileDE23_Obj_6807,  6,          -24,  -51,    9,    4
  pose 0x5FD0, FileDE23_Obj_6813,  6,          -23,  -50,   11,    2
  pose 0x5FF0, FileDE23_Obj_6819,  8,          -23,  -51,   11,    9
  pose 0x6010, FileDE23_Obj_6827,  7,          -23,  -51,   11,    9
  pose 0x6030, FileDE23_Obj_6834,  7,          -23,  -50,   11,    9
  pose 0x6050, FileDE23_Obj_6841,  7,          -23,  -50,   11,    9
  pose 0x6070, FileDE23_Obj_6848,  8,          -23,  -51,   11,    8
  pose 0x6090, FileDE23_Obj_6856,  8,          -23,  -51,   11,    9
  pose 0x60B0, FileDE23_Obj_6864,  7,          -23,  -50,   11,   10
  pose 0x63D0, FileDE23_Obj_6871,  9,          -23,  -49,   17,   10
  pose 0x63F0, FileDE23_Obj_6880,  8,          -23,  -49,   16,    9
  pose 0x6410, FileDE23_Obj_6888,  9,          -23,  -50,   17,    9
  pose 0x6430, FileDE23_Obj_6897,  8,          -23,  -49,   17,    6
  pose 0x6450, FileDE23_Obj_6905,  8,          -23,  -49,   17,    4
  pose 0x6470, FileDE23_Obj_6913,  8,          -23,  -49,   16,    9
  pose 0x6490, FileDE23_Obj_6921,  9,          -23,  -50,   17,    9
  pose 0x64B0, FileDE23_Obj_6930,  8,          -23,  -49,   17,    2
  pose 0x67D0, FileDE23_Obj_6938,  8,          -25,  -47,   14,    9
  pose 0x67F0, FileDE23_Obj_6946,  8,          -25,  -47,   13,    8
  pose 0x6810, FileDE23_Obj_6954,  7,          -25,  -48,   14,    1
  pose 0x6830, FileDE23_Obj_6961,  7,          -25,  -47,   14,    2
  pose 0x6850, FileDE23_Obj_6968,  8,          -25,  -47,   14,   10
  pose 0x6870, FileDE23_Obj_6976,  7,          -25,  -47,   13,    1
  pose 0x6890, FileDE23_Obj_6983,  7,          -25,  -48,   14,    1
  pose 0x68B0, FileDE23_Obj_6990,  8,          -25,  -47,   14,    9
  pose 0x6BD0, FileDE23_Obj_6998,  8,          -25,  -47,    8,   10
  pose 0x6BF0, FileDE23_Obj_7006,  7,          -25,  -47,    8,    1
  pose 0x6C10, FileDE23_Obj_7013,  7,          -25,  -48,    8,    1
  pose 0x6C30, FileDE23_Obj_7020,  7,          -25,  -47,    8,    2
  pose 0x6C50, FileDE23_Obj_7027,  8,          -25,  -47,    9,   10
  pose 0x6C70, FileDE23_Obj_7035,  7,          -25,  -47,    8,    1
  pose 0x6C90, FileDE23_Obj_7042,  7,          -25,  -48,    8,    1
  pose 0x6CB0, FileDE23_Obj_7049,  7,          -25,  -47,    8,    2
  pose 0xA651, FileDE23_Obj_7056,  5,          -22,  -50,   11,    9
  pose 0xA671, FileDE23_Obj_7061,  5,          -22,  -51,   11,    8
  pose 0xA691, FileDE23_Obj_7066,  5,          -22,  -51,   11,    8
  pose 0xA6B1, FileDE23_Obj_7071,  6,          -22,  -50,   15,    9
  pose 0xA6D1, FileDE23_Obj_7077,  6,          -22,  -50,   11,    9
  pose 0xA6F1, FileDE23_Obj_7083,  5,          -22,  -51,   11,    8
  pose 0xA711, FileDE23_Obj_7088,  5,          -22,  -50,   11,    9
  pose 0xA731, FileDE23_Obj_7093,  5,          -22,  -51,   11,    8
  pose 0xA751, FileDE23_Obj_7098,  5,          -22,  -50,   11,    9
  pose 0xA771, FileDE23_Obj_7103,  5,          -22,  -51,   11,    8
  pose 0xAE51, FileDE23_Obj_7108,  6,          -23,  -49,   11,   10
  pose 0xAE71, FileDE23_Obj_7114,  6,          -23,  -50,   11,    9
  pose 0xAE91, FileDE23_Obj_7120,  6,          -23,  -50,   11,   10
  pose 0xAEB1, FileDE23_Obj_7126,  6,          -23,  -49,   11,   10
  pose 0xAED1, FileDE23_Obj_7132,  7,          -23,  -49,   11,   10
  pose 0xAEF1, FileDE23_Obj_7139,  6,          -23,  -50,   11,   10
  pose 0xAF11, FileDE23_Obj_7145,  5,          -23,  -49,   11,    6
  pose 0xAF31, FileDE23_Obj_7150,  5,          -23,  -50,   11,    5
  pose 0xAF51, FileDE23_Obj_7155,  6,          -23,  -49,   11,   11
  pose 0xAF71, FileDE23_Obj_7161,  6,          -23,  -50,   11,   10
  pose 0xEDD4, FileDE23_Obj_7167,  6,          -25,  -52,   18,    0
  pose 0xEDF4, FileDE23_Obj_7173,  5,          -25,  -49,    9,    9
  pose 0x81D8, FileDE23_Obj_7178,  5,          -30,  -48,   10,   11
  pose 0x81F8, FileDE23_Obj_7183,  8,          -21,  -41,   20,   11
  pose 0x8218, FileDE23_Obj_7191,  9,          -24,  -41,   20,    9
  pose 0x8238, FileDE23_Obj_7200,  10,         -21,  -40,   20,   11
  pose 0xF5D4, FileDE23_Obj_7210,  10,         -24,  -50,   21,    8
  pose 0xF5F4, FileDE23_Obj_7220,  7,          -27,  -49,   13,    9
  pose 0x89D8, FileDE23_Obj_7227,  7,          -31,  -48,   17,    3
  pose 0x89F8, FileDE23_Obj_7234,  9,          -21,  -35,   20,   16
  pose 0x8A18, FileDE23_Obj_7243,  10,         -21,  -25,   20,   15
  pose 0x8A38, FileDE23_Obj_7253,  10,         -28,  -27,   20,   16
  pose 0xB1C7, FileDE23_Obj_7263,  11,         -37,  -25,   11,   17
  pose 0xB1E7, FileDE23_Obj_7274,  11,         -37,  -24,   13,   24
  pose 0xB207, FileDE23_Obj_7285,  6,          -29,  -37,    7,   13
  pose 0xB227, FileDE23_Obj_7291,  5,          -24,  -45,   10,    5
  pose 0xB9C7, FileDE23_Obj_7296,  8,          -36,  -39,   11,   15
  pose 0xB9E7, FileDE23_Obj_7304,  9,          -36,  -38,   13,   15
  pose 0xBA07, FileDE23_Obj_7313,  6,          -32,  -44,    7,   13
  pose 0xBA27, FileDE23_Obj_7319,  7,          -24,  -44,   17,    5
  pose 0xEBE4, FileDE23_Obj_7326,  6,          -25,  -51,    9,    1
  pose 0xEC04, FileDE23_Obj_7332,  7,          -25,  -51,    9,    8
  pose 0xF3E4, FileDE23_Obj_7339,  10,         -25,  -53,   16,    9
  pose 0xF404, FileDE23_Obj_7349,  10,         -24,  -54,   16,    8
  pose 0x66DF, FileDE23_Obj_7359,  10,         -34,  -45,   13,    5
  pose 0x66FF, FileDE23_Obj_7369,  10,         -32,  -45,   16,    5
  pose 0x671F, FileDE23_Obj_7379,  10,         -30,  -46,   16,    5
  pose 0x673F, FileDE23_Obj_7389,  10,         -34,  -37,   16,   11
  pose 0x91CE, FileDE23_Obj_7399,  7,          -25,  -50,   15,   11
  pose 0x91EE, FileDE23_Obj_7406,  7,          -28,  -48,    9,   13
  pose 0x920E, FileDE23_Obj_7413,  6,          -28,  -48,   13,   13
  pose 0x922E, FileDE23_Obj_7419,  7,          -28,  -48,   15,   13
  pose 0x924E, FileDE23_Obj_7426,  7,          -28,  -48,    7,   13
  pose 0xA1CE, FileDE23_Obj_7433,  6,          -24,  -49,   10,   11
  pose 0xA1EE, FileDE23_Obj_7439,  8,          -26,  -47,    8,   13
  pose 0xA20E, FileDE23_Obj_7447,  7,          -34,  -47,    8,   13
  pose 0xA22E, FileDE23_Obj_7454,  7,          -34,  -47,    8,   13
  pose 0xA24E, FileDE23_Obj_7461,  7,          -26,  -47,    8,   13
  pose 0x95CE, FileDE23_Obj_7468,  6,          -24,  -51,   16,    9
  pose 0x95EE, FileDE23_Obj_7474,  7,          -24,  -52,   16,    8
  pose 0x960E, FileDE23_Obj_7481,  7,          -24,  -52,   16,    8
  pose 0x962E, FileDE23_Obj_7488,  7,          -24,  -52,   16,    8
  pose 0x964E, FileDE23_Obj_7495,  7,          -24,  -52,   16,    8
  pose 0xEBF1, FileDE23_Obj_7502,  8,          -24,  -50,   11,    3
  pose 0xEC11, FileDE23_Obj_7510,  7,          -24,  -50,   11,    3
  pose 0xEC31, FileDE23_Obj_7517,  7,          -24,  -50,   11,    3
  pose 0xEFF1, FileDE23_Obj_7524,  10,         -25,  -49,   18,    3
  pose 0xF011, FileDE23_Obj_7534,  9,          -25,  -54,   17,    5
  pose 0xF031, FileDE23_Obj_7543,  9,          -25,  -53,   16,    3
  pose 0xF3F1, FileDE23_Obj_7552,  8,          -25,  -49,   16,    5
  pose 0xF411, FileDE23_Obj_7560,  9,          -25,  -49,   21,    6
  pose 0xF431, FileDE23_Obj_7569,  8,          -25,  -49,   20,    3
  pose 0x039E, FileDE23_Obj_7577,  10,         -25,  -48,   14,    3
  pose 0x03BE, FileDE23_Obj_7587,  10,         -25,  -48,   17,    3
  pose 0x03DE, FileDE23_Obj_7597,  11,         -25,  -48,   16,    3
  pose 0x7EB7, FileDE23_Obj_7608,  9,          -25,  -48,   15,   11
  pose 0xFC11, FileDE23_Obj_7617,  9,          -25,  -48,    9,   11
  pose 0xFC31, FileDE23_Obj_7626,  9,          -25,  -48,    9,   11
  pose 0xBC50, FileDE23_Obj_7635,  6,          -25,  -51,   15,   10
  pose 0xBC70, FileDE23_Obj_7641,  6,          -24,  -45,   10,   15
  pose 0xBC90, FileDE23_Obj_7647,  6,          -24,  -45,   10,   15
  pose 0xC050, FileDE23_Obj_7653,  6,          -24,  -49,   10,   10
  pose 0xC070, FileDE23_Obj_7659,  5,          -24,  -43,   10,   13
  pose 0xC090, FileDE23_Obj_7664,  5,          -24,  -44,    9,   13
  pose 0xC450, FileDE23_Obj_7669,  7,          -24,  -48,   11,   10
  pose 0xC470, FileDE23_Obj_7676,  7,          -23,  -41,   11,   13
  pose 0xC490, FileDE23_Obj_7683,  6,          -23,  -43,    9,   13
  pose 0xC850, FileDE23_Obj_7689,  8,          -24,  -51,   16,   10
  pose 0xC870, FileDE23_Obj_7697,  8,          -24,  -43,   12,   13
  pose 0xC890, FileDE23_Obj_7705,  6,          -24,  -41,   12,   13
  pose 0xCC50, FileDE23_Obj_7711,  8,          -26,  -50,   14,   10
  pose 0xCC70, FileDE23_Obj_7719,  7,          -26,  -42,   10,    7
  pose 0xCC90, FileDE23_Obj_7726,  6,          -26,  -41,   10,    7
  pose 0x8483, FileDE23_Obj_7732,  12,         -25,  -51,   21,   10
  pose 0x8484, FileDE23_Obj_7744,  11,         -25,  -50,   28,    3
  pose 0x8485, FileDE23_Obj_7755,  12,         -25,  -54,   32,    3
  pose 0x8486, FileDE23_Obj_7767,  12,         -25,  -55,   32,    3
  pose 0x8482, FileDE23_Obj_7779,  12,         -25,  -51,   20,   10
  pose 0x84A2, FileDE23_Obj_7791,  11,         -44,  -51,   22,   19
  pose 0x84C2, FileDE23_Obj_7802,  11,         -31,  -51,   12,   10
  pose 0x84E2, FileDE23_Obj_7813,  10,         -24,  -51,   10,   10
  pose 0x84C3, FileDE23_Obj_7823,  12,         -30,  -51,   12,   10
  pose 0x84C4, FileDE23_Obj_7835,  13,         -24,  -50,   19,   12
  pose 0x84C5, FileDE23_Obj_7848,  11,         -22,  -44,   28,   21
  pose 0x84C6, FileDE23_Obj_7859,  11,         -22,  -44,   28,   20
  pose 0x90D2, FileDE23_Obj_7870,  16,         -24,  -52,   21,   10
  pose 0x90F2, FileDE23_Obj_7886,  15,         -25,  -51,   28,    3
  pose 0x9112, FileDE23_Obj_7901,  16,         -25,  -54,   32,    3
  pose 0x9132, FileDE23_Obj_7917,  16,         -25,  -55,   32,    3
  pose 0x90B2, FileDE23_Obj_7933,  16,         -24,  -52,   20,   10
  pose 0x94B2, FileDE23_Obj_7949,  11,         -44,  -51,   22,   19
  pose 0x98B2, FileDE23_Obj_7960,  13,         -31,  -51,   12,   10
  pose 0x9CB2, FileDE23_Obj_7973,  14,         -24,  -51,   15,   10
  pose 0x98D2, FileDE23_Obj_7987,  14,         -30,  -51,   12,   10
  pose 0x98F2, FileDE23_Obj_8001,  16,         -24,  -50,   19,   12
  pose 0x9912, FileDE23_Obj_8017,  13,         -22,  -44,   28,   21
  pose 0x9932, FileDE23_Obj_8030,  13,         -22,  -44,   28,   20
  pose 0xA65D, FileDE23_Obj_8043,  6,          -31,  -49,   12,   10
  pose 0xA67D, FileDE23_Obj_8049,  6,          -36,  -49,   12,   10
  pose 0xA69D, FileDE23_Obj_8055,  7,          -36,  -49,   12,   10
  pose 0xA6BD, FileDE23_Obj_8062,  7,          -36,  -49,   12,   10
  pose 0xA6DD, FileDE23_Obj_8069,  6,          -36,  -49,   12,   10
  pose 0x9EC1, FileDE23_Obj_8075,  7,          -25,  -49,   12,   10
  pose 0x9EE1, FileDE23_Obj_8082,  7,          -25,  -49,   12,   10
  pose 0xE3C5, FileDE23_Obj_8089,  2,          -36,  -40,    0,    0
  pose 0x96C1, FileDE23_Obj_8091,  8,          -25,  -50,   17,   10
  pose 0x96E1, FileDE23_Obj_8099,  8,          -25,  -50,   17,   10
  pose 0x971A, FileDE23_Obj_8107,  1,          -36,  -39,    0,    0
  pose 0xE3B4, FileDE23_Obj_8108,  1,          -36,  -40,    0,    0
  pose 0xDB1C, FileDE23_Obj_8109,  4,          -25,  -49,    7,    3
  pose 0xDB3C, FileDE23_Obj_8113,  6,          -27,  -49,   13,    3
  pose 0xDB5C, FileDE23_Obj_8119,  6,          -27,  -49,   13,    3
  pose 0xDB7C, FileDE23_Obj_8125,  6,          -27,  -49,   13,    3

FileDE23_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x4EF9, FileDE23_Cmd_0,     1
  animation 0x4F19, FileDE23_Cmd_1,     1
  animation 0x4F39, FileDE23_Cmd_2,     1
  animation 0x4F59, FileDE23_Cmd_3,     1
  animation 0x4F79, FileDE23_Cmd_4,     1
  animation 0x6DB9, FileDE23_Cmd_5,     8
  animation 0x6DD9, FileDE23_Cmd_13,    8
  animation 0x6DF9, FileDE23_Cmd_21,    8
  animation 0x6E19, FileDE23_Cmd_29,    8
  animation 0x6E39, FileDE23_Cmd_37,    8
  animation 0x3B8B, FileDE23_Cmd_45,    1
  animation 0x3BAB, FileDE23_Cmd_46,    1
  animation 0x3BCB, FileDE23_Cmd_47,    1
  animation 0x3BEB, FileDE23_Cmd_48,    1
  animation 0x3C0B, FileDE23_Cmd_49,    1
  animation 0x3B8C, FileDE23_Cmd_50,    8
  animation 0x3BAC, FileDE23_Cmd_58,    8
  animation 0x3BCC, FileDE23_Cmd_66,    8
  animation 0x3BEC, FileDE23_Cmd_74,    8
  animation 0x3C0C, FileDE23_Cmd_82,    8
  animation 0xDE6C, FileDE23_Cmd_90,    2
  animation 0xDEAC, FileDE23_Cmd_92,    2
  animation 0xDE6D, FileDE23_Cmd_94,    1
  animation 0xDEAD, FileDE23_Cmd_95,    1
  animation 0xDE6E, FileDE23_Cmd_96,    4
  animation 0xDEAE, FileDE23_Cmd_100,   4
  animation 0xDE6F, FileDE23_Cmd_104,   2
  animation 0xDEAF, FileDE23_Cmd_106,   2
  animation 0xDE70, FileDE23_Cmd_108,   4
  animation 0xDEB0, FileDE23_Cmd_112,   4
  animation 0xDE71, FileDE23_Cmd_116,   1
  animation 0xDEB1, FileDE23_Cmd_117,   1
  animation 0x25CE, FileDE23_Cmd_118,   1
  animation 0x260E, FileDE23_Cmd_119,   1
  animation 0x25CF, FileDE23_Cmd_120,   1
  animation 0x260F, FileDE23_Cmd_121,   1
  animation 0x6812, FileDE23_Cmd_122,   5
  animation 0x6852, FileDE23_Cmd_127,   5
  animation 0x6196, FileDE23_Cmd_132,   1
  animation 0x61D6, FileDE23_Cmd_133,   1
  animation 0x6197, FileDE23_Cmd_134,   3
  animation 0x61D7, FileDE23_Cmd_137,   3
  animation 0x6198, FileDE23_Cmd_140,   2
  animation 0x61D8, FileDE23_Cmd_142,   2
  animation 0xCB61, FileDE23_Cmd_144,   2
  animation 0xCBA1, FileDE23_Cmd_146,   2
  animation 0xCB62, FileDE23_Cmd_148,   2
  animation 0xCBA2, FileDE23_Cmd_150,   2
  animation 0xAF82, FileDE23_Cmd_152,   1
  animation 0xAF83, FileDE23_Cmd_153,   1
  animation 0xAF84, FileDE23_Cmd_154,   1
  animation 0xAF85, FileDE23_Cmd_155,   1
  animation 0xCEB7, FileDE23_Cmd_156,   2
  animation 0xCF37, FileDE23_Cmd_158,   2
  animation 0xCEB8, FileDE23_Cmd_160,   2
  animation 0xCF38, FileDE23_Cmd_162,   2
  animation 0xCEB9, FileDE23_Cmd_164,   1
  animation 0xCF39, FileDE23_Cmd_165,   1
  animation 0xCEBA, FileDE23_Cmd_166,   1
  animation 0xCF3A, FileDE23_Cmd_167,   1
  animation 0xCED7, FileDE23_Cmd_168,   2
  animation 0xCED8, FileDE23_Cmd_170,   2
  animation 0xCED9, FileDE23_Cmd_172,   1
  animation 0xCEDA, FileDE23_Cmd_173,   1
  animation 0xA833, FileDE23_Cmd_174,   1
  animation 0xA853, FileDE23_Cmd_175,   1
  animation 0xA873, FileDE23_Cmd_176,   1
  animation 0xA893, FileDE23_Cmd_177,   1
  animation 0xA8B3, FileDE23_Cmd_178,   1
  animation 0xA834, FileDE23_Cmd_179,   1
  animation 0xA854, FileDE23_Cmd_180,   1
  animation 0xA874, FileDE23_Cmd_181,   1
  animation 0xA894, FileDE23_Cmd_182,   1
  animation 0xA8B4, FileDE23_Cmd_183,   1
  animation 0xA835, FileDE23_Cmd_184,   1
  animation 0xA855, FileDE23_Cmd_185,   1
  animation 0xA875, FileDE23_Cmd_186,   1
  animation 0xA895, FileDE23_Cmd_187,   1
  animation 0xA8B5, FileDE23_Cmd_188,   1
  animation 0x57B9, FileDE23_Cmd_189,   1
  animation 0x57D9, FileDE23_Cmd_190,   1
  animation 0x57F9, FileDE23_Cmd_191,   1
  animation 0x5819, FileDE23_Cmd_192,   1
  animation 0x5839, FileDE23_Cmd_193,   1
  animation 0x57BA, FileDE23_Cmd_194,   1
  animation 0x57DA, FileDE23_Cmd_195,   1
  animation 0x57FA, FileDE23_Cmd_196,   1
  animation 0x581A, FileDE23_Cmd_197,   1
  animation 0x583A, FileDE23_Cmd_198,   1
  animation 0x57BB, FileDE23_Cmd_199,   1
  animation 0x57DB, FileDE23_Cmd_200,   1
  animation 0x57FB, FileDE23_Cmd_201,   1
  animation 0x581B, FileDE23_Cmd_202,   1
  animation 0x583B, FileDE23_Cmd_203,   1
  animation 0x66B4, FileDE23_Cmd_204,   1
  animation 0x66D4, FileDE23_Cmd_205,   1
  animation 0x66F4, FileDE23_Cmd_206,   1
  animation 0x6714, FileDE23_Cmd_207,   1
  animation 0x6734, FileDE23_Cmd_208,   1
  animation 0x66B5, FileDE23_Cmd_209,   1
  animation 0x66D5, FileDE23_Cmd_210,   1
  animation 0x66F5, FileDE23_Cmd_211,   1
  animation 0x6715, FileDE23_Cmd_212,   1
  animation 0x6735, FileDE23_Cmd_213,   1
  animation 0x66B6, FileDE23_Cmd_214,   1
  animation 0x66D6, FileDE23_Cmd_215,   1
  animation 0x66F6, FileDE23_Cmd_216,   1
  animation 0x6716, FileDE23_Cmd_217,   1
  animation 0x6736, FileDE23_Cmd_218,   1
  animation 0x2B3A, FileDE23_Cmd_219,   2
  animation 0x2B5A, FileDE23_Cmd_221,   2
  animation 0x2B7A, FileDE23_Cmd_223,   2
  animation 0x2B9A, FileDE23_Cmd_225,   2
  animation 0x2BBA, FileDE23_Cmd_227,   2
  animation 0x2B3B, FileDE23_Cmd_229,   4
  animation 0x2B5B, FileDE23_Cmd_233,   4
  animation 0x2B7B, FileDE23_Cmd_237,   4
  animation 0x2B9B, FileDE23_Cmd_241,   4
  animation 0x2BBB, FileDE23_Cmd_245,   4
  animation 0x2B3C, FileDE23_Cmd_249,   1
  animation 0x2B5C, FileDE23_Cmd_250,   1
  animation 0x2B7C, FileDE23_Cmd_251,   1
  animation 0x2B9C, FileDE23_Cmd_252,   1
  animation 0x2BBC, FileDE23_Cmd_253,   1
  animation 0x562F, FileDE23_Cmd_254,   1
  animation 0x564F, FileDE23_Cmd_255,   1
  animation 0x566F, FileDE23_Cmd_256,   1
  animation 0x568F, FileDE23_Cmd_257,   1
  animation 0x56AF, FileDE23_Cmd_258,   1
  animation 0x5630, FileDE23_Cmd_259,   1
  animation 0x5650, FileDE23_Cmd_260,   1
  animation 0x5670, FileDE23_Cmd_261,   1
  animation 0x5690, FileDE23_Cmd_262,   1
  animation 0x56B0, FileDE23_Cmd_263,   1
  animation 0x5631, FileDE23_Cmd_264,   1
  animation 0x5651, FileDE23_Cmd_265,   1
  animation 0x5671, FileDE23_Cmd_266,   1
  animation 0x5691, FileDE23_Cmd_267,   1
  animation 0x56B1, FileDE23_Cmd_268,   1
  animation 0x5632, FileDE23_Cmd_269,   2
  animation 0x5652, FileDE23_Cmd_271,   2
  animation 0x5672, FileDE23_Cmd_273,   2
  animation 0x5692, FileDE23_Cmd_275,   2
  animation 0x56B2, FileDE23_Cmd_277,   2
  animation 0x5633, FileDE23_Cmd_279,   4
  animation 0x5653, FileDE23_Cmd_283,   4
  animation 0x5673, FileDE23_Cmd_287,   4
  animation 0x5693, FileDE23_Cmd_291,   4
  animation 0x56B3, FileDE23_Cmd_295,   4
  animation 0x268D, FileDE23_Cmd_299,   2
  animation 0x26AD, FileDE23_Cmd_301,   2
  animation 0x26CD, FileDE23_Cmd_303,   2
  animation 0x26ED, FileDE23_Cmd_305,   2
  animation 0x270D, FileDE23_Cmd_307,   2
  animation 0x268E, FileDE23_Cmd_309,   1
  animation 0x26AE, FileDE23_Cmd_310,   1
  animation 0x26CE, FileDE23_Cmd_311,   1
  animation 0x26EE, FileDE23_Cmd_312,   1
  animation 0x270E, FileDE23_Cmd_313,   1
  animation 0x268F, FileDE23_Cmd_314,   9
  animation 0x26AF, FileDE23_Cmd_323,   9
  animation 0x26CF, FileDE23_Cmd_332,   9
  animation 0x26EF, FileDE23_Cmd_341,   9
  animation 0x270F, FileDE23_Cmd_350,   9
  animation 0x4EB4, FileDE23_Cmd_359,   1
  animation 0x4ED4, FileDE23_Cmd_360,   1
  animation 0x4EF4, FileDE23_Cmd_361,   1
  animation 0x4F14, FileDE23_Cmd_362,   1
  animation 0x4F34, FileDE23_Cmd_363,   1
  animation 0x4EB5, FileDE23_Cmd_364,   1
  animation 0x4ED5, FileDE23_Cmd_365,   1
  animation 0x4EF5, FileDE23_Cmd_366,   1
  animation 0x4F15, FileDE23_Cmd_367,   1
  animation 0x4F35, FileDE23_Cmd_368,   1
  animation 0x4EB6, FileDE23_Cmd_369,   2
  animation 0x4ED6, FileDE23_Cmd_371,   2
  animation 0x4EF6, FileDE23_Cmd_373,   2
  animation 0x4F16, FileDE23_Cmd_375,   2
  animation 0x4F36, FileDE23_Cmd_377,   2
  animation 0x89C1, FileDE23_Cmd_379,   1
  animation 0x89E1, FileDE23_Cmd_380,   1
  animation 0x8A01, FileDE23_Cmd_381,   1
  animation 0x8A21, FileDE23_Cmd_382,   1
  animation 0x8A41, FileDE23_Cmd_383,   1
  animation 0xCF94, FileDE23_Cmd_384,   2
  animation 0xCFB4, FileDE23_Cmd_386,   2
  animation 0xCFD4, FileDE23_Cmd_388,   2
  animation 0xCFF4, FileDE23_Cmd_390,   2
  animation 0xD014, FileDE23_Cmd_392,   2
  animation 0xCF95, FileDE23_Cmd_394,   1
  animation 0xCFB5, FileDE23_Cmd_395,   1
  animation 0xCFD5, FileDE23_Cmd_396,   1
  animation 0xCFF5, FileDE23_Cmd_397,   1
  animation 0xD015, FileDE23_Cmd_398,   1
  animation 0x5D5A, FileDE23_Cmd_399,   1
  animation 0x5D7A, FileDE23_Cmd_400,   1
  animation 0x5D9A, FileDE23_Cmd_401,   1
  animation 0x5DBA, FileDE23_Cmd_402,   1
  animation 0x5DDA, FileDE23_Cmd_403,   1
  animation 0xDF8B, FileDE23_Cmd_404,   1
  animation 0xE38B, FileDE23_Cmd_405,   1
  animation 0xE78B, FileDE23_Cmd_406,   1
  animation 0xEB8B, FileDE23_Cmd_407,   1
  animation 0xEF8B, FileDE23_Cmd_408,   1
  animation 0xB78F, FileDE23_Cmd_409,   8
  animation 0xBB8F, FileDE23_Cmd_417,   8
  animation 0xBF8F, FileDE23_Cmd_425,   8
  animation 0xC38F, FileDE23_Cmd_433,   8
  animation 0xC78F, FileDE23_Cmd_441,   8
  animation 0x71C9, FileDE23_Cmd_449,   1
  animation 0x75C9, FileDE23_Cmd_450,   1
  animation 0x79C9, FileDE23_Cmd_451,   1
  animation 0x7DC9, FileDE23_Cmd_452,   1
  animation 0x81C9, FileDE23_Cmd_453,   1
  animation 0x71E9, FileDE23_Cmd_454,   8
  animation 0x75E9, FileDE23_Cmd_462,   8
  animation 0x79E9, FileDE23_Cmd_470,   8
  animation 0x7DE9, FileDE23_Cmd_478,   8
  animation 0x81E9, FileDE23_Cmd_486,   8
  animation 0xCDFD, FileDE23_Cmd_494,   2
  animation 0xD5FD, FileDE23_Cmd_496,   2
  animation 0xCE1D, FileDE23_Cmd_498,   1
  animation 0xD61D, FileDE23_Cmd_499,   1
  animation 0xCE3D, FileDE23_Cmd_500,   4
  animation 0xD63D, FileDE23_Cmd_504,   4
  animation 0xCE5D, FileDE23_Cmd_508,   2
  animation 0xD65D, FileDE23_Cmd_510,   2
  animation 0xCE7D, FileDE23_Cmd_512,   4
  animation 0xD67D, FileDE23_Cmd_516,   4
  animation 0xCE9D, FileDE23_Cmd_520,   1
  animation 0xD69D, FileDE23_Cmd_521,   1
  animation 0xBA26, FileDE23_Cmd_522,   1
  animation 0xC226, FileDE23_Cmd_523,   1
  animation 0xBA46, FileDE23_Cmd_524,   1
  animation 0xC246, FileDE23_Cmd_525,   1
  animation 0x02AF, FileDE23_Cmd_526,   5
  animation 0x0AAF, FileDE23_Cmd_531,   5
  animation 0x332E, FileDE23_Cmd_536,   1
  animation 0x3B2E, FileDE23_Cmd_537,   1
  animation 0x334E, FileDE23_Cmd_538,   3
  animation 0x3B4E, FileDE23_Cmd_541,   3
  animation 0x336E, FileDE23_Cmd_544,   2
  animation 0x3B6E, FileDE23_Cmd_546,   2
  animation 0x6C9B, FileDE23_Cmd_548,   2
  animation 0x749B, FileDE23_Cmd_550,   2
  animation 0x6CBB, FileDE23_Cmd_552,   2
  animation 0x74BB, FileDE23_Cmd_554,   2
  animation 0xF0B7, FileDE23_Cmd_556,   1
  animation 0xF0D7, FileDE23_Cmd_557,   1
  animation 0xF0F7, FileDE23_Cmd_558,   1
  animation 0xF117, FileDE23_Cmd_559,   1
  animation 0xD75B, FileDE23_Cmd_560,   2
  animation 0xE75B, FileDE23_Cmd_562,   2
  animation 0xD77B, FileDE23_Cmd_564,   2
  animation 0xE77B, FileDE23_Cmd_566,   2
  animation 0xD79B, FileDE23_Cmd_568,   1
  animation 0xE79B, FileDE23_Cmd_569,   1
  animation 0xD7BB, FileDE23_Cmd_570,   1
  animation 0xE7BB, FileDE23_Cmd_571,   1
  animation 0xDB5B, FileDE23_Cmd_572,   2
  animation 0xDB7B, FileDE23_Cmd_574,   2
  animation 0xDB9B, FileDE23_Cmd_576,   1
  animation 0xDBBB, FileDE23_Cmd_577,   1
  animation 0x06D7, FileDE23_Cmd_578,   1
  animation 0x0AD7, FileDE23_Cmd_579,   1
  animation 0x0ED7, FileDE23_Cmd_580,   1
  animation 0x12D7, FileDE23_Cmd_581,   1
  animation 0x16D7, FileDE23_Cmd_582,   1
  animation 0x06F7, FileDE23_Cmd_583,   1
  animation 0x0AF7, FileDE23_Cmd_584,   1
  animation 0x0EF7, FileDE23_Cmd_585,   1
  animation 0x12F7, FileDE23_Cmd_586,   1
  animation 0x16F7, FileDE23_Cmd_587,   1
  animation 0x0717, FileDE23_Cmd_588,   1
  animation 0x0B17, FileDE23_Cmd_589,   1
  animation 0x0F17, FileDE23_Cmd_590,   1
  animation 0x1317, FileDE23_Cmd_591,   1
  animation 0x1717, FileDE23_Cmd_592,   1
  animation 0xF78C, FileDE23_Cmd_593,   1
  animation 0xFB8C, FileDE23_Cmd_594,   1
  animation 0xFF8C, FileDE23_Cmd_595,   1
  animation 0x038D, FileDE23_Cmd_596,   1
  animation 0x078D, FileDE23_Cmd_597,   1
  animation 0xF7AC, FileDE23_Cmd_598,   1
  animation 0xFBAC, FileDE23_Cmd_599,   1
  animation 0xFFAC, FileDE23_Cmd_600,   1
  animation 0x03AD, FileDE23_Cmd_601,   1
  animation 0x07AD, FileDE23_Cmd_602,   1
  animation 0xF7CC, FileDE23_Cmd_603,   1
  animation 0xFBCC, FileDE23_Cmd_604,   1
  animation 0xFFCC, FileDE23_Cmd_605,   1
  animation 0x03CD, FileDE23_Cmd_606,   1
  animation 0x07CD, FileDE23_Cmd_607,   1
  animation 0xD6EE, FileDE23_Cmd_608,   1
  animation 0xDAEE, FileDE23_Cmd_609,   1
  animation 0xDEEE, FileDE23_Cmd_610,   1
  animation 0xE2EE, FileDE23_Cmd_611,   1
  animation 0xE6EE, FileDE23_Cmd_612,   1
  animation 0xD70E, FileDE23_Cmd_613,   1
  animation 0xDB0E, FileDE23_Cmd_614,   1
  animation 0xDF0E, FileDE23_Cmd_615,   1
  animation 0xE30E, FileDE23_Cmd_616,   1
  animation 0xE70E, FileDE23_Cmd_617,   1
  animation 0xD72E, FileDE23_Cmd_618,   1
  animation 0xDB2E, FileDE23_Cmd_619,   1
  animation 0xDF2E, FileDE23_Cmd_620,   1
  animation 0xE32E, FileDE23_Cmd_621,   1
  animation 0xE72E, FileDE23_Cmd_622,   1
  animation 0x67A7, FileDE23_Cmd_623,   2
  animation 0x6BA7, FileDE23_Cmd_625,   2
  animation 0x6FA7, FileDE23_Cmd_627,   2
  animation 0x73A7, FileDE23_Cmd_629,   2
  animation 0x77A7, FileDE23_Cmd_631,   2
  animation 0x67C7, FileDE23_Cmd_633,   4
  animation 0x6BC7, FileDE23_Cmd_637,   4
  animation 0x6FC7, FileDE23_Cmd_641,   4
  animation 0x73C7, FileDE23_Cmd_645,   4
  animation 0x77C7, FileDE23_Cmd_649,   4
  animation 0x67E7, FileDE23_Cmd_653,   1
  animation 0x6BE7, FileDE23_Cmd_654,   1
  animation 0x6FE7, FileDE23_Cmd_655,   1
  animation 0x73E7, FileDE23_Cmd_656,   1
  animation 0x77E7, FileDE23_Cmd_657,   1
  animation 0xC64C, FileDE23_Cmd_658,   1
  animation 0xCA4C, FileDE23_Cmd_659,   1
  animation 0xCE4C, FileDE23_Cmd_660,   1
  animation 0xD24C, FileDE23_Cmd_661,   1
  animation 0xD64C, FileDE23_Cmd_662,   1
  animation 0xC66C, FileDE23_Cmd_663,   1
  animation 0xCA6C, FileDE23_Cmd_664,   1
  animation 0xCE6C, FileDE23_Cmd_665,   1
  animation 0xD26C, FileDE23_Cmd_666,   1
  animation 0xD66C, FileDE23_Cmd_667,   1
  animation 0xC68C, FileDE23_Cmd_668,   1
  animation 0xCA8C, FileDE23_Cmd_669,   1
  animation 0xCE8C, FileDE23_Cmd_670,   1
  animation 0xD28C, FileDE23_Cmd_671,   1
  animation 0xD68C, FileDE23_Cmd_672,   1
  animation 0xC6AC, FileDE23_Cmd_673,   2
  animation 0xCAAC, FileDE23_Cmd_675,   2
  animation 0xCEAC, FileDE23_Cmd_677,   2
  animation 0xD2AC, FileDE23_Cmd_679,   2
  animation 0xD6AC, FileDE23_Cmd_681,   2
  animation 0xC6CC, FileDE23_Cmd_683,   4
  animation 0xCACC, FileDE23_Cmd_687,   4
  animation 0xCECC, FileDE23_Cmd_691,   4
  animation 0xD2CC, FileDE23_Cmd_695,   4
  animation 0xD6CC, FileDE23_Cmd_699,   4
  animation 0xD206, FileDE23_Cmd_703,   2
  animation 0xD606, FileDE23_Cmd_705,   2
  animation 0xDA06, FileDE23_Cmd_707,   2
  animation 0xDE06, FileDE23_Cmd_709,   2
  animation 0xE206, FileDE23_Cmd_711,   2
  animation 0xD226, FileDE23_Cmd_713,   1
  animation 0xD626, FileDE23_Cmd_714,   1
  animation 0xDA26, FileDE23_Cmd_715,   1
  animation 0xDE26, FileDE23_Cmd_716,   1
  animation 0xE226, FileDE23_Cmd_717,   1
  animation 0xD246, FileDE23_Cmd_718,   9
  animation 0xD646, FileDE23_Cmd_727,   9
  animation 0xDA46, FileDE23_Cmd_736,   9
  animation 0xDE46, FileDE23_Cmd_745,   9
  animation 0xE246, FileDE23_Cmd_754,   9
  animation 0x4EE5, FileDE23_Cmd_763,   1
  animation 0x52E5, FileDE23_Cmd_764,   1
  animation 0x56E5, FileDE23_Cmd_765,   1
  animation 0x5AE5, FileDE23_Cmd_766,   1
  animation 0x5EE5, FileDE23_Cmd_767,   1
  animation 0x4F05, FileDE23_Cmd_768,   1
  animation 0x5305, FileDE23_Cmd_769,   1
  animation 0x5705, FileDE23_Cmd_770,   1
  animation 0x5B05, FileDE23_Cmd_771,   1
  animation 0x5F05, FileDE23_Cmd_772,   1
  animation 0x4F25, FileDE23_Cmd_773,   2
  animation 0x5325, FileDE23_Cmd_775,   2
  animation 0x5725, FileDE23_Cmd_777,   2
  animation 0x5B25, FileDE23_Cmd_779,   2
  animation 0x5F25, FileDE23_Cmd_781,   2
  animation 0x89F2, FileDE23_Cmd_783,   1
  animation 0x8DF2, FileDE23_Cmd_784,   1
  animation 0x91F2, FileDE23_Cmd_785,   1
  animation 0x95F2, FileDE23_Cmd_786,   1
  animation 0x99F2, FileDE23_Cmd_787,   1
  animation 0xCFC5, FileDE23_Cmd_788,   2
  animation 0xD3C5, FileDE23_Cmd_790,   2
  animation 0xD7C5, FileDE23_Cmd_792,   2
  animation 0xDBC5, FileDE23_Cmd_794,   2
  animation 0xDFC5, FileDE23_Cmd_796,   2
  animation 0xCFE5, FileDE23_Cmd_798,   1
  animation 0xD3E5, FileDE23_Cmd_799,   1
  animation 0xD7E5, FileDE23_Cmd_800,   1
  animation 0xDBE5, FileDE23_Cmd_801,   1
  animation 0xDFE5, FileDE23_Cmd_802,   1
  animation 0x5D8B, FileDE23_Cmd_803,   1
  animation 0x618B, FileDE23_Cmd_804,   1
  animation 0x658B, FileDE23_Cmd_805,   1
  animation 0x698B, FileDE23_Cmd_806,   1
  animation 0x6D8B, FileDE23_Cmd_807,   1
  animation 0x94F2, FileDE23_Cmd_808,   2
  animation 0x9512, FileDE23_Cmd_810,   1
  animation 0x9552, FileDE23_Cmd_811,   7
  animation 0x9513, FileDE23_Cmd_818,   5
  animation 0x9553, FileDE23_Cmd_823,   5
  animation 0x9895, FileDE23_Cmd_828,   1
  animation 0x1896, FileDE23_Cmd_829,   1
  animation 0x9896, FileDE23_Cmd_830,   1
  animation 0x1897, FileDE23_Cmd_831,   1
  animation 0x9897, FileDE23_Cmd_832,   1
  animation 0x1C96, FileDE23_Cmd_833,   8
  animation 0x1C97, FileDE23_Cmd_841,   8
  animation 0x2096, FileDE23_Cmd_849,   6
  animation 0x2097, FileDE23_Cmd_855,   6
  animation 0x2496, FileDE23_Cmd_861,   1
  animation 0x2497, FileDE23_Cmd_862,   1
  animation 0xDF9C, FileDE23_Cmd_863,   1
  animation 0xE39C, FileDE23_Cmd_864,   1
  animation 0xE79C, FileDE23_Cmd_865,   1
  animation 0xEB9C, FileDE23_Cmd_866,   1
  animation 0xEF9C, FileDE23_Cmd_867,   1
  animation 0xB7A0, FileDE23_Cmd_868,   8
  animation 0xBBA0, FileDE23_Cmd_876,   8
  animation 0xBFA0, FileDE23_Cmd_884,   8
  animation 0xC3A0, FileDE23_Cmd_892,   8
  animation 0xC7A0, FileDE23_Cmd_900,   8
  animation 0x71DA, FileDE23_Cmd_908,   1
  animation 0x75DA, FileDE23_Cmd_909,   1
  animation 0x79DA, FileDE23_Cmd_910,   1
  animation 0x7DDA, FileDE23_Cmd_911,   1
  animation 0x81DA, FileDE23_Cmd_912,   1
  animation 0x71FA, FileDE23_Cmd_913,   8
  animation 0x75FA, FileDE23_Cmd_921,   8
  animation 0x79FA, FileDE23_Cmd_929,   8
  animation 0x7DFA, FileDE23_Cmd_937,   8
  animation 0x81FA, FileDE23_Cmd_945,   8
  animation 0xCE0E, FileDE23_Cmd_953,   2
  animation 0xD60E, FileDE23_Cmd_955,   2
  animation 0xCE2E, FileDE23_Cmd_957,   1
  animation 0xD62E, FileDE23_Cmd_958,   1
  animation 0xCE4E, FileDE23_Cmd_959,   4
  animation 0xD64E, FileDE23_Cmd_963,   4
  animation 0xCE6E, FileDE23_Cmd_967,   2
  animation 0xD66E, FileDE23_Cmd_969,   2
  animation 0xCE8E, FileDE23_Cmd_971,   4
  animation 0xD68E, FileDE23_Cmd_975,   4
  animation 0xCEAE, FileDE23_Cmd_979,   1
  animation 0xD6AE, FileDE23_Cmd_980,   1
  animation 0xBA37, FileDE23_Cmd_981,   1
  animation 0xC237, FileDE23_Cmd_982,   1
  animation 0xBA57, FileDE23_Cmd_983,   1
  animation 0xC257, FileDE23_Cmd_984,   1
  animation 0x02C0, FileDE23_Cmd_985,   5
  animation 0x0AC0, FileDE23_Cmd_990,   5
  animation 0x333F, FileDE23_Cmd_995,   1
  animation 0x3B3F, FileDE23_Cmd_996,   1
  animation 0x335F, FileDE23_Cmd_997,   3
  animation 0x3B5F, FileDE23_Cmd_1000,  3
  animation 0x337F, FileDE23_Cmd_1003,  2
  animation 0x3B7F, FileDE23_Cmd_1005,  2
  animation 0x6CAC, FileDE23_Cmd_1007,  2
  animation 0x74AC, FileDE23_Cmd_1009,  2
  animation 0x6CCC, FileDE23_Cmd_1011,  2
  animation 0x74CC, FileDE23_Cmd_1013,  2
  animation 0xF0C8, FileDE23_Cmd_1015,  1
  animation 0xF0E8, FileDE23_Cmd_1016,  1
  animation 0xF108, FileDE23_Cmd_1017,  1
  animation 0xF128, FileDE23_Cmd_1018,  1
  animation 0xD76C, FileDE23_Cmd_1019,  2
  animation 0xE76C, FileDE23_Cmd_1021,  2
  animation 0xD78C, FileDE23_Cmd_1023,  2
  animation 0xE78C, FileDE23_Cmd_1025,  2
  animation 0xD7AC, FileDE23_Cmd_1027,  1
  animation 0xE7AC, FileDE23_Cmd_1028,  1
  animation 0xD7CC, FileDE23_Cmd_1029,  1
  animation 0xE7CC, FileDE23_Cmd_1030,  1
  animation 0xDB6C, FileDE23_Cmd_1031,  2
  animation 0xDB8C, FileDE23_Cmd_1033,  2
  animation 0xDBAC, FileDE23_Cmd_1035,  1
  animation 0xDBCC, FileDE23_Cmd_1036,  1
  animation 0xF79D, FileDE23_Cmd_1037,  1
  animation 0xFB9D, FileDE23_Cmd_1038,  1
  animation 0xFF9D, FileDE23_Cmd_1039,  1
  animation 0x039E, FileDE23_Cmd_1040,  1
  animation 0x079E, FileDE23_Cmd_1041,  1
  animation 0xF7BD, FileDE23_Cmd_1042,  1
  animation 0xFBBD, FileDE23_Cmd_1043,  1
  animation 0xFFBD, FileDE23_Cmd_1044,  1
  animation 0x03BE, FileDE23_Cmd_1045,  1
  animation 0x07BE, FileDE23_Cmd_1046,  1
  animation 0xF7DD, FileDE23_Cmd_1047,  1
  animation 0xFBDD, FileDE23_Cmd_1048,  1
  animation 0xFFDD, FileDE23_Cmd_1049,  1
  animation 0x03DE, FileDE23_Cmd_1050,  1
  animation 0x07DE, FileDE23_Cmd_1051,  1
  animation 0x38A4, FileDE23_Cmd_1052,  1
  animation 0x3CA4, FileDE23_Cmd_1053,  1
  animation 0x40A4, FileDE23_Cmd_1054,  1
  animation 0x44A4, FileDE23_Cmd_1055,  1
  animation 0x48A4, FileDE23_Cmd_1056,  1
  animation 0xF30C, FileDE23_Cmd_1057,  2
  animation 0xF70C, FileDE23_Cmd_1059,  2
  animation 0xFB0C, FileDE23_Cmd_1061,  2
  animation 0xFF0C, FileDE23_Cmd_1063,  2
  animation 0x030D, FileDE23_Cmd_1065,  2
  animation 0xF32C, FileDE23_Cmd_1067,  1
  animation 0xF72C, FileDE23_Cmd_1068,  1
  animation 0xFB2C, FileDE23_Cmd_1069,  1
  animation 0xFF2C, FileDE23_Cmd_1070,  1
  animation 0x032D, FileDE23_Cmd_1071,  1
  animation 0xABBE, FileDE23_Cmd_1072,  1
  animation 0xAFBE, FileDE23_Cmd_1073,  1
  animation 0xB3BE, FileDE23_Cmd_1074,  1
  animation 0xB7BE, FileDE23_Cmd_1075,  1
  animation 0xBBBE, FileDE23_Cmd_1076,  1
  animation 0x8C21, FileDE23_Cmd_1077,  4
  animation 0x8C22, FileDE23_Cmd_1081,  2
  animation 0x8C41, FileDE23_Cmd_1083,  1
  animation 0x8C61, FileDE23_Cmd_1084,  1
  animation 0x8C81, FileDE23_Cmd_1085,  1
  animation 0x8CA1, FileDE23_Cmd_1086,  1
  animation 0x8C82, FileDE23_Cmd_1087,  4
  animation 0x8C83, FileDE23_Cmd_1091,  2
  animation 0x8493, FileDE23_Cmd_1093,  4
  animation 0x84B3, FileDE23_Cmd_1097,  2
  animation 0x8893, FileDE23_Cmd_1099,  1
  animation 0x8C93, FileDE23_Cmd_1100,  1
  animation 0x9093, FileDE23_Cmd_1101,  1
  animation 0x9493, FileDE23_Cmd_1102,  1
  animation 0x90B3, FileDE23_Cmd_1103,  4
  animation 0x90D3, FileDE23_Cmd_1107,  2
  animation 0x6111, FileDE23_Cmd_1109,  1
  animation 0x6131, FileDE23_Cmd_1110,  4
  animation 0x78D4, FileDE23_Cmd_1114,  4
  animation 0x80D4, FileDE23_Cmd_1118,  4
  animation 0xA2FC, FileDE23_Cmd_1122,  1
  animation 0x4D14, FileDE23_Cmd_1123,  1
  animation 0xA2EB, FileDE23_Cmd_1124,  1
  animation 0x52F6, FileDE23_Cmd_1125,  1
  animation 0x5316, FileDE23_Cmd_1126,  1
  animation 0x5336, FileDE23_Cmd_1127,  2

1:
FileDE23_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileDE23_Obj_0:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
  FileDE23_Obj_6:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   32,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
  FileDE23_Obj_12:
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
  FileDE23_Obj_19:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   96,    0
  FileDE23_Obj_25:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,  128,    0
  FileDE23_Obj_31:
    subsprite OAM_SIZE_8x16,    -1,  -19, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,    2, 1293,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -14,  281,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -35,   96,    0, xflip=1
  FileDE23_Obj_37:
    subsprite OAM_SIZE_8x8,     -7,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -23,  259,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -19, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -3, 2053,    0, xflip=1
  FileDE23_Obj_43:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  269,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2080,    0
  FileDE23_Obj_49:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0
    subsprite OAM_SIZE_16x16,   -9,  -27,  290,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  285,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2082,    0
  FileDE23_Obj_54:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0
    subsprite OAM_SIZE_16x16,  -10,  -27,  292,    0
    subsprite OAM_SIZE_8x8,      6,  -21,  270,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2084,    0
  FileDE23_Obj_59:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0
    subsprite OAM_SIZE_8x8,      0,   -5, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,  -10,  -28,  294,    0
    subsprite OAM_SIZE_8x8,      6,  -24,  286,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2086,    0
  FileDE23_Obj_65:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  269,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -36,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2080,    0
  FileDE23_Obj_71:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -27,  290,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  285,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2082,    0
  FileDE23_Obj_76:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -27,  292,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -21,  270,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2084,    0
  FileDE23_Obj_81:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -5, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -6,  -28,  294,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -24,  286,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -36,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2086,    0
  FileDE23_Obj_87:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1344,    0
    subsprite OAM_SIZE_8x8,     -6,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  320,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   32,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2112,    0
  FileDE23_Obj_92:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1346,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  322,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   34,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2114,    0
    subsprite OAM_SIZE_8x8,     -7,   -5, 2054,    0
  FileDE23_Obj_98:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1348,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  324,    0
    subsprite OAM_SIZE_8x8,     10,  -19,  271,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   32,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2116,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 2055,    0
  FileDE23_Obj_105:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1350,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  326,    0
    subsprite OAM_SIZE_8x8,      9,  -23,  287,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   36,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2118,    0
  FileDE23_Obj_111:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1352,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -6,  -25,  328,    0
    subsprite OAM_SIZE_8x8,     10,  -20,  296,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   32,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2112,    0
  FileDE23_Obj_117:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1354,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1310,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  330,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   34,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2114,    0
    subsprite OAM_SIZE_8x8,     -7,   -5, 2054,    0
  FileDE23_Obj_123:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1356,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  332,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   32,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2116,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 2055,    0
  FileDE23_Obj_128:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1358,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1311,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  334,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   36,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2118,    0
  FileDE23_Obj_133:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1376,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  352,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -26, 2144,    0
  FileDE23_Obj_140:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1378,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  354,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -23, 2146,    0
  FileDE23_Obj_146:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1380,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  356,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -22, 2148,    0
  FileDE23_Obj_152:
    subsprite OAM_SIZE_16x16,   -7,  -18, 1382,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  358,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   68,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -24, 2150,    0
  FileDE23_Obj_158:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1384,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  360,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -26, 2144,    0
  FileDE23_Obj_164:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1386,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  362,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -23, 2146,    0
  FileDE23_Obj_169:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1388,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  364,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -22, 2148,    0
  FileDE23_Obj_174:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1390,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  366,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   68,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -24, 2150,    0
  FileDE23_Obj_180:
    subsprite OAM_SIZE_16x16,  -14,  -28, 2176,    0
    subsprite OAM_SIZE_8x8,    -15,  -21, 2055,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1408,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  384,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  281,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   96,    0
  FileDE23_Obj_187:
    subsprite OAM_SIZE_16x8,   -14,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1410,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  386,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   98,    0
  FileDE23_Obj_192:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2180,    0
    subsprite OAM_SIZE_8x8,    -14,  -16, 2071,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1412,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  388,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   96,    0
  FileDE23_Obj_197:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2182,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1414,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  390,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  100,    0
  FileDE23_Obj_202:
    subsprite OAM_SIZE_16x16,  -14,  -28, 2176,    0
    subsprite OAM_SIZE_8x8,    -15,  -21, 2055,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1416,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1326,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  392,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   96,    0
  FileDE23_Obj_208:
    subsprite OAM_SIZE_16x8,   -14,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1418,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  394,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   98,    0
  FileDE23_Obj_212:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2180,    0
    subsprite OAM_SIZE_8x8,    -14,  -16, 2071,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1420,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  396,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   96,    0
  FileDE23_Obj_217:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2182,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1422,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  398,    0
    subsprite OAM_SIZE_8x8,      8,  -21,  312,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  100,    0
  FileDE23_Obj_224:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0
    subsprite OAM_SIZE_8x8,     -9,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -24,  416,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  297,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
  FileDE23_Obj_230:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  418,    0
    subsprite OAM_SIZE_8x8,      7,  -18,  313,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
  FileDE23_Obj_235:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  298,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_240:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  314,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  132,    0
  FileDE23_Obj_245:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    1, 1294,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  416,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  297,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
  FileDE23_Obj_251:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -23,  418,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -18,  313,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
  FileDE23_Obj_256:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -18,  298,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_261:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  314,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  132,    0
  FileDE23_Obj_266:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1576,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_272:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1578,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   32,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
    subsprite OAM_SIZE_8x8,     -2,  -22,  301,    0
  FileDE23_Obj_279:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1580,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -15,  -28,  194,    0
    subsprite OAM_SIZE_16x8,    -4,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  317,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
  FileDE23_Obj_289:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,  -10,  -15, 1582,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   96,    0
    subsprite OAM_SIZE_16x8,    -6,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  430,    0
  FileDE23_Obj_296:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1600,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1337,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_303:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2056,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_309:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2058,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_314:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2060,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_319:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0
    subsprite OAM_SIZE_8x8,      0,   -4, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2062,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_325:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2056,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_331:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2058,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_336:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2060,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_341:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2062,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_347:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1472,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2088,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2089,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_353:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1474,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1291,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   36,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2091,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_361:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1476,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2093,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_368:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1478,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   34,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2094,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2095,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_375:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1480,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2088,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2089,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_382:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1482,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   36,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2091,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_390:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1484,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -36,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2093,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_398:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1486,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,   34,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2094,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2095,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_405:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1504,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_8x16,   -11,  -20, 2120,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
  FileDE23_Obj_414:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1506,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   68,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2121,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_422:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1508,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -6,  -21, 2122,    0
    subsprite OAM_SIZE_8x8,     -5,   -5, 2055,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
  FileDE23_Obj_431:
    subsprite OAM_SIZE_16x16,   -7,  -18, 1510,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 2123,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_439:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1512,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_8x16,   -11,  -20, 2120,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
  FileDE23_Obj_447:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1514,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   68,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2121,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_455:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1516,    0
    subsprite OAM_SIZE_8x8,     -3,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -6,  -21, 2122,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
    subsprite OAM_SIZE_8x8,     -5,   -5, 2055,    0
  FileDE23_Obj_464:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1518,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_16x16,   -6,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -14,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 2123,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_472:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2124,    0
    subsprite OAM_SIZE_8x8,    -14,  -14, 2194,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1536,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   96,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_480:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -14,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1538,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  100,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_488:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2126,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1540,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   96,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_495:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2127,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1542,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   98,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_502:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2124,    0
    subsprite OAM_SIZE_8x8,    -14,  -14, 2194,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1544,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   96,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_510:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -14,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1546,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  100,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_517:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2126,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1548,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   96,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_524:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2127,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1550,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   98,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_532:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2152,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0
    subsprite OAM_SIZE_8x8,     -9,    2, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_539:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  132,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_545:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_551:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2158,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_557:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2152,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_564:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  132,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_570:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_576:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2158,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_582:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -36,   96,    0, xflip=1
  FileDE23_Obj_587:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1604,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  514,    0
    subsprite OAM_SIZE_16x16,   -5,  -37,   96,    0, xflip=1
  FileDE23_Obj_592:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  516,    0
    subsprite OAM_SIZE_16x16,   -5,  -37,   96,    0, xflip=1
  FileDE23_Obj_597:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  518,    0
    subsprite OAM_SIZE_8x8,      7,   -8,  548,    0
    subsprite OAM_SIZE_16x16,   -5,  -36,   96,    0, xflip=1
  FileDE23_Obj_603:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  520,    0
    subsprite OAM_SIZE_8x8,      3,   -8,  548,    0
    subsprite OAM_SIZE_16x16,   -5,  -36,   96,    0, xflip=1
  FileDE23_Obj_609:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1608,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37,   96,    0, xflip=1
  FileDE23_Obj_614:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1610,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -36,   96,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -7,    1, 1325,    0, xflip=1
  FileDE23_Obj_619:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1612,    0
    subsprite OAM_SIZE_8x8,     -1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37,   96,    0, xflip=1
  FileDE23_Obj_624:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1614,    0
    subsprite OAM_SIZE_8x8,    -11,    1, 1326,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -36,   96,    0, xflip=1
  FileDE23_Obj_629:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37,   96,    0, xflip=1
  FileDE23_Obj_634:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
  FileDE23_Obj_640:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1634,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  524,    0
    subsprite OAM_SIZE_16x16,   -5,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
  FileDE23_Obj_646:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  526,    0
    subsprite OAM_SIZE_16x16,   -5,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
  FileDE23_Obj_652:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  544,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
  FileDE23_Obj_658:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  546,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -11,  564,    0
  FileDE23_Obj_665:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1638,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
  FileDE23_Obj_671:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1640,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
  FileDE23_Obj_676:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1642,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
  FileDE23_Obj_681:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1644,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -34,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,    3, 1291,    0, xflip=1
  FileDE23_Obj_687:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_16x16,   -5,  -35,   32,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
  FileDE23_Obj_693:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1646,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  549,    0
    subsprite OAM_SIZE_16x16,   -9,  -36,    6,    0
    subsprite OAM_SIZE_8x16,    -8,  -22, 2216,    0
    subsprite OAM_SIZE_16x8,     2,  -17, 2198,    0
  FileDE23_Obj_698:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1664,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  551,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,    8,    0
    subsprite OAM_SIZE_16x16,   -9,  -19, 2186,    0
  FileDE23_Obj_703:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1666,    0
    subsprite OAM_SIZE_8x8,     -2,    3, 1291,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  553,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   10,    0
    subsprite OAM_SIZE_16x16,  -14,  -19, 2188,    0
  FileDE23_Obj_708:
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_16x16,    4,  -24,   12,    0
    subsprite OAM_SIZE_16x16,   -5,  -25, 2190,    0
  FileDE23_Obj_715:
    subsprite OAM_SIZE_16x16,   -4,  -13,  557,    0
    subsprite OAM_SIZE_8x8,      3,  -21,  577,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  593,    0
    subsprite OAM_SIZE_8x8,     12,  -11,  578,    0
    subsprite OAM_SIZE_8x8,    -12,    1,  594,    0
    subsprite OAM_SIZE_16x16,    4,  -25,   14,    0
    subsprite OAM_SIZE_16x8,    -8,  -20, 2217,    0
    subsprite OAM_SIZE_8x8,      3,  -12, 2219,    0
  FileDE23_Obj_723:
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_16x16,    4,  -24,   12,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_16x8,    -5,  -15, 2221,    0
    subsprite OAM_SIZE_8x8,    -13,  -15, 2220,    0
    subsprite OAM_SIZE_8x16,     3,   -7, 2223,    0
  FileDE23_Obj_732:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1668,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1338,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  579,    0
    subsprite OAM_SIZE_8x8,      8,  -24,  585,    0
    subsprite OAM_SIZE_8x8,    -16,  -19,  601,    0
    subsprite OAM_SIZE_8x8,     -8,  -35,  297,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   70,    0
    subsprite OAM_SIZE_16x8,     5,  -18, 2225,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2054,    0
    subsprite OAM_SIZE_8x16,    -9,  -16, 2224,    0
  FileDE23_Obj_742:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1670,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -24,  581,    0
    subsprite OAM_SIZE_8x8,      5,  -23,  586,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   72,    0
    subsprite OAM_SIZE_8x8,      4,  -17, 2228,    0
    subsprite OAM_SIZE_8x16,    -9,  -16, 2227,    0
  FileDE23_Obj_749:
    subsprite OAM_SIZE_16x8,   -15,  -23, 2241,    0
    subsprite OAM_SIZE_8x8,    -12,  -15, 2244,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1672,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  583,    0
    subsprite OAM_SIZE_8x8,      9,  -14,  602,    0
    subsprite OAM_SIZE_16x16,   -6,  -32,   74,    0
  FileDE23_Obj_755:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_16x16,    4,   -1,   76,    0
    subsprite OAM_SIZE_8x8,      3,   -3, 2231,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2229,    0
  FileDE23_Obj_763:
    subsprite OAM_SIZE_16x16,   -5,   -9,  589,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  609,    0
    subsprite OAM_SIZE_8x8,      1,    7,  625,    0
    subsprite OAM_SIZE_8x8,    -10,  -17,  610,    0
    subsprite OAM_SIZE_8x8,     11,   -1,  626,    0
    subsprite OAM_SIZE_16x16,    4,   -2,   78,    0
    subsprite OAM_SIZE_8x16,     3,  -16, 2234,    0
    subsprite OAM_SIZE_8x8,     -1,   -4, 2249,    0
    subsprite OAM_SIZE_8x8,     -9,   -8, 2233,    0
  FileDE23_Obj_772:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_16x16,    4,   -1,   76,    0
    subsprite OAM_SIZE_8x16,     4,  -11, 2235,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 2053,    0, yflip=1
    subsprite OAM_SIZE_16x8,   -12,   -3, 2247,    0
  FileDE23_Obj_781:
    subsprite OAM_SIZE_8x8,    -14,   -1, 2236,    0
    subsprite OAM_SIZE_8x16,    -6,   -7, 2237,    0
    subsprite OAM_SIZE_8x16,     2,   -9, 2238,    0
    subsprite OAM_SIZE_8x8,    -10,  -10,  265,    0
    subsprite OAM_SIZE_8x8,      1,    2,  510,    0
    subsprite OAM_SIZE_16x16,  -12,   -9,  611,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  615,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  616,    0
    subsprite OAM_SIZE_8x8,    -20,   -4,  631,    0
    subsprite OAM_SIZE_8x8,     -7,    7,  632,    0
    subsprite OAM_SIZE_16x16,  -22,    1,   38,    0
  FileDE23_Obj_792:
    subsprite OAM_SIZE_8x8,    -15,    0, 2252,    0
    subsprite OAM_SIZE_8x16,    -7,   -7, 2256,    0
    subsprite OAM_SIZE_8x16,     1,   -9, 2238,    0
    subsprite OAM_SIZE_8x8,      2,    4,  510,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  615,    0
    subsprite OAM_SIZE_16x16,  -11,   -8,  613,    0
    subsprite OAM_SIZE_8x8,    -19,   -3,  617,    0
    subsprite OAM_SIZE_16x8,    -7,    8,  633,    0
    subsprite OAM_SIZE_8x8,      5,  -10,  616,    0
    subsprite OAM_SIZE_8x8,    -10,   15,  297,    0
    subsprite OAM_SIZE_16x16,  -22,    2,   40,    0
  FileDE23_Obj_803:
    subsprite OAM_SIZE_16x16,   -9,  -10, 1674,    0
    subsprite OAM_SIZE_16x16,  -11,  -11,  619,    0
    subsprite OAM_SIZE_8x8,     -1,    5,  618,    0
    subsprite OAM_SIZE_16x16,  -13,  -22,   32,    0
    subsprite OAM_SIZE_8x16,   -11,   -7, 2257,    0
    subsprite OAM_SIZE_8x8,    -19,   -7, 2255,    0
  FileDE23_Obj_809:
    subsprite OAM_SIZE_16x16,   -8,  -11, 1676,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  621,    0
    subsprite OAM_SIZE_16x16,   -7,  -30,   42,    0
    subsprite OAM_SIZE_8x16,   -10,  -16, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -14, 2093,    0
  FileDE23_Obj_814:
    subsprite OAM_SIZE_8x8,    -11,  -17, 2258,    0
    subsprite OAM_SIZE_16x8,   -11,   -9, 2274,    0
    subsprite OAM_SIZE_16x8,    -9,   -1, 2260,    0
    subsprite OAM_SIZE_16x16,  -21,  -23,  102,    0
    subsprite OAM_SIZE_16x16,  -11,  -17,  640,    0
    subsprite OAM_SIZE_8x8,      3,   -9,  644,    0
    subsprite OAM_SIZE_8x8,     -1,   -3,  660,    0
    subsprite OAM_SIZE_8x8,    -19,  -11,  623,    0
  FileDE23_Obj_822:
    subsprite OAM_SIZE_8x8,     -7,  -17, 2259,    0
    subsprite OAM_SIZE_16x8,   -11,   -9, 2276,    0
    subsprite OAM_SIZE_16x8,    -8,   -1, 2260,    0
    subsprite OAM_SIZE_16x16,  -21,  -22,  104,    0
    subsprite OAM_SIZE_16x16,  -11,  -14,  642,    0
    subsprite OAM_SIZE_8x8,      5,   -4,  644,    0
    subsprite OAM_SIZE_8x8,      1,    2,  660,    0
    subsprite OAM_SIZE_8x16,   -19,  -10,  645,    0
    subsprite OAM_SIZE_8x8,     -8,  -22,  639,    0
  FileDE23_Obj_831:
    subsprite OAM_SIZE_16x16,  -16,  -16, 2262,    0
    subsprite OAM_SIZE_16x16,   -9,  -11, 1678,    0
    subsprite OAM_SIZE_8x8,     -4,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -19,  646,    0
    subsprite OAM_SIZE_8x8,    -18,   -3,  618,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -13,  -30,   96,    0
  FileDE23_Obj_837:
    subsprite OAM_SIZE_8x16,    -7,  -16, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -11, 1696,    0
    subsprite OAM_SIZE_16x16,   -7,  -18,  648,    0
    subsprite OAM_SIZE_8x8,      9,   -9,  281,    0
    subsprite OAM_SIZE_16x16,   -6,  -28,  106,    0
  FileDE23_Obj_842:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1698,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  650,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   44,    0
    subsprite OAM_SIZE_8x8,    -12,  -40, 2288,    0
    subsprite OAM_SIZE_8x8,     -9,  -32, 2289,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2290,    0
  FileDE23_Obj_848:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1700,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  652,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   46,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 2291,    0
    subsprite OAM_SIZE_16x8,    -9,  -33, 2292,    0
    subsprite OAM_SIZE_8x8,     -8,  -25, 2294,    0
  FileDE23_Obj_855:
    subsprite OAM_SIZE_8x16,    -6,  -37, 2265,    0
    subsprite OAM_SIZE_8x8,     -8,  -45, 2296,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1702,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  654,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,  108,    0
    subsprite OAM_SIZE_8x16,   -11,  -35, 2264,    0
    subsprite OAM_SIZE_8x8,    -12,  -43, 2295,    0
  FileDE23_Obj_865:
    subsprite OAM_SIZE_8x8,     -3,  -46, 2298,    0
    subsprite OAM_SIZE_8x16,    -5,  -38, 2267,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1704,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  672,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,  110,    0
    subsprite OAM_SIZE_8x16,    -9,  -36, 2266,    0
    subsprite OAM_SIZE_8x8,     -7,  -44, 2297,    0
  FileDE23_Obj_875:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2284,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2299,    0
    subsprite OAM_SIZE_8x8,     -7,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -19,  675,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x8,      0,   -3,  697,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  698,    0
    subsprite OAM_SIZE_8x8,    -24,  -25,  194,    0, yflip=1
    subsprite OAM_SIZE_16x16,  -18,  -30,  134,    0
    subsprite OAM_SIZE_8x8,    -10,  -13,  297,    0
  FileDE23_Obj_886:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2270,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2299,    0
    subsprite OAM_SIZE_8x8,     -6,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19,  677,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  683,    0
    subsprite OAM_SIZE_8x8,      2,   -3,  684,    0
    subsprite OAM_SIZE_8x8,      8,   -7,  685,    0
    subsprite OAM_SIZE_8x8,    -22,  -24,  194,    0
    subsprite OAM_SIZE_16x16,  -16,  -30,  136,    0
  FileDE23_Obj_897:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2286,    0
    subsprite OAM_SIZE_8x8,     -2,   -3, 2299,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  679,    0
    subsprite OAM_SIZE_16x8,    -5,  -27,  700,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  682,    0
    subsprite OAM_SIZE_8x8,      8,   -9,  686,    0
    subsprite OAM_SIZE_8x8,      4,   -3,  702,    0
    subsprite OAM_SIZE_16x16,  -14,  -31,   72,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  495,    0
  FileDE23_Obj_907:
    subsprite OAM_SIZE_8x8,    -12,  -13, 2252,    0
    subsprite OAM_SIZE_8x16,    -4,  -20, 2256,    0
    subsprite OAM_SIZE_8x16,     4,  -22, 2238,    0
    subsprite OAM_SIZE_8x8,      5,   -9,  510,    0
    subsprite OAM_SIZE_8x8,      2,  -27,  615,    0
    subsprite OAM_SIZE_16x16,   -8,  -21,  613,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  617,    0
    subsprite OAM_SIZE_16x8,    -4,   -5,  633,    0
    subsprite OAM_SIZE_8x8,      8,  -23,  616,    0
    subsprite OAM_SIZE_8x8,     -7,    2,  297,    0
    subsprite OAM_SIZE_16x16,  -19,  -11,  138,    0
  FileDE23_Obj_918:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1706,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  704,    0
    subsprite OAM_SIZE_8x8,      7,  -24,  687,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  140,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
  FileDE23_Obj_925:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32,  140,    0
    subsprite OAM_SIZE_8x16,     1,  -16, 2090,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -3,  -15, 2091,    0, xflip=1
  FileDE23_Obj_932:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32,  140,    0
    subsprite OAM_SIZE_16x16,   -3,  -17, 2112,    0, xflip=1
  FileDE23_Obj_938:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1710,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  708,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  711,    0
    subsprite OAM_SIZE_16x16,  -10,  -32,  142,    0
    subsprite OAM_SIZE_16x16,   -2,  -17, 2116,    0, xflip=1
    subsprite OAM_SIZE_8x8,      7,   -1, 2055,    0
  FileDE23_Obj_945:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32,  140,    0
    subsprite OAM_SIZE_8x16,    -3,  -16, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -7,    0, 2053,    0, xflip=1
  FileDE23_Obj_952:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1728,    0
    subsprite OAM_SIZE_8x8,      2,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  712,    0
    subsprite OAM_SIZE_8x8,    -15,  -20,  703,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  172,    0
  FileDE23_Obj_958:
    subsprite OAM_SIZE_8x16,    -9,  -17, 2125,    0
    subsprite OAM_SIZE_8x8,    -17,   -9, 2195,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32,  172,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_966:
    subsprite OAM_SIZE_16x16,  -18,  -25, 2176,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32,  172,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_973:
    subsprite OAM_SIZE_16x8,   -18,  -22, 2180,    0
    subsprite OAM_SIZE_8x8,    -17,  -14, 2071,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1732,    0
    subsprite OAM_SIZE_8x8,     -8,    5, 1339,    0
    subsprite OAM_SIZE_16x16,  -10,  -32,  174,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  716,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  734,    0
  FileDE23_Obj_980:
    subsprite OAM_SIZE_8x16,    -9,  -16, 2051,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32,  172,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_987:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1734,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  736,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  719,    0
    subsprite OAM_SIZE_16x16,   -8,  -36,   32,    0
    subsprite OAM_SIZE_8x16,    -3,  -19, 2048,    0
  FileDE23_Obj_993:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   32,    0
    subsprite OAM_SIZE_16x16,   -6,  -20, 2058,    0
  FileDE23_Obj_1000:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   32,    0
    subsprite OAM_SIZE_16x16,   -6,  -20, 2080,    0
  FileDE23_Obj_1007:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1738,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  740,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  743,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   34,    0
    subsprite OAM_SIZE_16x16,   -7,  -20, 2084,    0
  FileDE23_Obj_1014:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -7,  -37,   32,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2048,    0
  FileDE23_Obj_1021:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2092,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -16, 2093,    0, xflip=1
  FileDE23_Obj_1027:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
  FileDE23_Obj_1032:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2090,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -17, 2091,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -2,  -35, 3040,    0
  FileDE23_Obj_1039:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   34,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2060,    0
  FileDE23_Obj_1044:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  871,    0
    subsprite OAM_SIZE_8x8,      2,  -26, 3056,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
  FileDE23_Obj_1049:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2058,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      6,  -29, 3041,    0
  FileDE23_Obj_1055:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2093,    0
  FileDE23_Obj_1061:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  878,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
    subsprite OAM_SIZE_8x8,      2,  -21, 3056,    0
  FileDE23_Obj_1068:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -17, 2091,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,      8,  -21, 3042,    0
  FileDE23_Obj_1076:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   98,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
  FileDE23_Obj_1081:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  902,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2055,    0
    subsprite OAM_SIZE_8x8,     -2,  -19, 3057,    0, xflip=1
  FileDE23_Obj_1087:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -9,  -18, 2121,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_8x8,      5,  -14, 3043,    0
  FileDE23_Obj_1094:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
  FileDE23_Obj_1100:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  908,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 3057,    0, xflip=1
  FileDE23_Obj_1106:
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -10, 3044,    0
  FileDE23_Obj_1114:
    subsprite OAM_SIZE_8x16,     2,  -36, 1740,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2092,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -16, 2093,    0, xflip=1
  FileDE23_Obj_1121:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -4,  -41, 1740,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
  FileDE23_Obj_1128:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -4,  -40, 1740,    0
    subsprite OAM_SIZE_8x16,    -3,  -33,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2090,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -17, 2091,    0, xflip=1
  FileDE23_Obj_1135:
    subsprite OAM_SIZE_16x16,    2,  -30, 1742,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   34,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2060,    0
  FileDE23_Obj_1141:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    1,  -38, 1742,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
  FileDE23_Obj_1147:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    0,  -37, 1742,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2058,    0
    subsprite OAM_SIZE_8x16,     0,  -30,  875,    0
  FileDE23_Obj_1153:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,    0,  -23, 1760,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2093,    0
  FileDE23_Obj_1160:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_16x16,    5,  -29, 1760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
  FileDE23_Obj_1168:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -17, 2091,    0
    subsprite OAM_SIZE_16x16,    4,  -29, 1760,    0
    subsprite OAM_SIZE_16x8,    -1,  -19,  898,    0
  FileDE23_Obj_1176:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   98,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 1762,    0
  FileDE23_Obj_1182:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2055,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,    1,  -19, 1762,    0
  FileDE23_Obj_1190:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -9,  -18, 2121,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  914,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  915,    0
    subsprite OAM_SIZE_16x16,    0,  -20, 1762,    0
  FileDE23_Obj_1197:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 1741,    0
  FileDE23_Obj_1204:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x16,    -4,  -16, 1741,    0
  FileDE23_Obj_1211:
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -19,  929,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 1741,    0
  FileDE23_Obj_1219:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,     2,  -32,  744,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,      3,  -27,  764,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2092,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -16, 2093,    0, xflip=1
  FileDE23_Obj_1227:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -37,  744,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
  FileDE23_Obj_1234:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -36,  744,    0
    subsprite OAM_SIZE_8x16,    -3,  -33,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,     3,  -18, 2090,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -17, 2091,    0, xflip=1
  FileDE23_Obj_1241:
    subsprite OAM_SIZE_16x16,    1,  -25,  746,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   34,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2060,    0
    subsprite OAM_SIZE_8x8,      4,  -20,  765,    0
  FileDE23_Obj_1248:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    1,  -32,  746,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
    subsprite OAM_SIZE_8x8,      4,  -27,  765,    0
  FileDE23_Obj_1255:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    0,  -31,  746,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2058,    0
    subsprite OAM_SIZE_8x16,     0,  -30,  875,    0
    subsprite OAM_SIZE_8x8,      3,  -26,  765,    0
  FileDE23_Obj_1262:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2093,    0
    subsprite OAM_SIZE_16x8,     0,  -15,  748,    0
  FileDE23_Obj_1269:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
    subsprite OAM_SIZE_16x8,     5,  -21,  748,    0
  FileDE23_Obj_1277:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -17, 2091,    0
    subsprite OAM_SIZE_16x8,    -1,  -19,  898,    0
    subsprite OAM_SIZE_16x8,     4,  -21,  748,    0
  FileDE23_Obj_1285:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   98,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  750,    0
  FileDE23_Obj_1291:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2055,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,   -1,  -16,  750,    0
  FileDE23_Obj_1299:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -9,  -18, 2121,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  914,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  915,    0
    subsprite OAM_SIZE_16x16,   -2,  -17,  750,    0
  FileDE23_Obj_1306:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
    subsprite OAM_SIZE_8x16,   -10,  -17,  745,    0
  FileDE23_Obj_1313:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x16,    -5,  -13,  745,    0
  FileDE23_Obj_1320:
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -19,  929,    0
    subsprite OAM_SIZE_8x16,    -5,  -14,  745,    0
  FileDE23_Obj_1328:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1792,    0
    subsprite OAM_SIZE_8x8,      2,    2, 1838,    0
    subsprite OAM_SIZE_16x16,  -11,  -27,  768,    0
    subsprite OAM_SIZE_8x8,     -2,  -35,  840,    0
    subsprite OAM_SIZE_16x8,   -15,  -27, 2576,    0
    subsprite OAM_SIZE_8x8,    -23,  -21, 2560,    0
    subsprite OAM_SIZE_8x8,    -15,  -19, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2058,    0
  FileDE23_Obj_1337:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1792,    0
    subsprite OAM_SIZE_8x8,      2,    2, 1838,    0
    subsprite OAM_SIZE_16x16,  -11,  -27,  768,    0
    subsprite OAM_SIZE_8x8,     -2,  -35,  840,    0
    subsprite OAM_SIZE_16x8,   -14,  -28, 2576,    0
    subsprite OAM_SIZE_8x8,    -22,  -22, 2560,    0
    subsprite OAM_SIZE_8x8,    -14,  -20, 1293,    0
    subsprite OAM_SIZE_8x8,     -2,  -24,  856,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
  FileDE23_Obj_1347:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  770,    0
    subsprite OAM_SIZE_16x8,   -28,  -27, 2562,    0
    subsprite OAM_SIZE_16x8,   -12,  -29, 2578,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2060,    0
  FileDE23_Obj_1353:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  772,    0
    subsprite OAM_SIZE_8x8,    -15,  -19,  841,    0
    subsprite OAM_SIZE_32x16,  -24,  -49, 2570,    0
    subsprite OAM_SIZE_16x32,    8,  -48, 2574,    0
    subsprite OAM_SIZE_8x8,    -10,  -33, 2604,    0
    subsprite OAM_SIZE_8x8,      0,  -33, 2605,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2060,    0
  FileDE23_Obj_1362:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  774,    0
    subsprite OAM_SIZE_8x8,    -19,  -19,  857,    0
    subsprite OAM_SIZE_8x8,      2,  -19, 2564,    0
    subsprite OAM_SIZE_8x8,      5,  -11, 2580,    0
    subsprite OAM_SIZE_16x8,    13,   -9, 2706,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2091,    0
  FileDE23_Obj_1372:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  774,    0
    subsprite OAM_SIZE_8x8,    -19,  -19,  857,    0
    subsprite OAM_SIZE_8x8,      1,  -20, 2564,    0
    subsprite OAM_SIZE_8x8,      4,  -12, 2580,    0
    subsprite OAM_SIZE_16x8,    12,  -10, 2706,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -2, 2053,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
  FileDE23_Obj_1382:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1798,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  776,    0
    subsprite OAM_SIZE_16x8,   -25,  -33, 2565,    0
    subsprite OAM_SIZE_16x8,    -9,  -31, 2581,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 2561,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   34,    0
    subsprite OAM_SIZE_8x16,   -11,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2091,    0
  FileDE23_Obj_1391:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1798,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  776,    0
    subsprite OAM_SIZE_16x8,   -24,  -33, 2565,    0
    subsprite OAM_SIZE_16x8,    -8,  -31, 2581,    0
    subsprite OAM_SIZE_8x8,      0,  -23, 2561,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   32,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
  FileDE23_Obj_1400:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  778,    0
    subsprite OAM_SIZE_8x8,     -2,  -34,  842,    0
    subsprite OAM_SIZE_16x8,   -16,  -42, 2567,    0
    subsprite OAM_SIZE_16x8,    -9,  -34, 2583,    0
    subsprite OAM_SIZE_8x16,     2,  -26, 2569,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   34,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2093,    0
  FileDE23_Obj_1409:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  780,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_32x8,     1,  -19, 2656,    0
    subsprite OAM_SIZE_32x32,    0,  -51, 2592,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2093,    0
  FileDE23_Obj_1417:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_8x8,     -1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  782,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2121,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 2596,    0
    subsprite OAM_SIZE_8x16,     4,   -2, 2597,    0
    subsprite OAM_SIZE_8x8,     -4,   -1, 2621,    0
  FileDE23_Obj_1426:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_8x8,     -1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  782,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -7,   -2, 2055,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2596,    0
    subsprite OAM_SIZE_8x16,     4,   -3, 2597,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2621,    0
  FileDE23_Obj_1436:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1804,    0
    subsprite OAM_SIZE_8x8,     -3,    2, 1854,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  800,    0
    subsprite OAM_SIZE_8x8,     -6,  -46, 2628,    0
    subsprite OAM_SIZE_8x8,     -4,  -39, 2644,    0
    subsprite OAM_SIZE_8x16,    -1,  -31, 2629,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -16,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2121,    0
  FileDE23_Obj_1445:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1804,    0
    subsprite OAM_SIZE_8x8,     -3,    2, 1854,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  800,    0
    subsprite OAM_SIZE_8x8,     -5,  -45, 2628,    0
    subsprite OAM_SIZE_8x8,     -3,  -38, 2644,    0
    subsprite OAM_SIZE_8x16,     0,  -30, 2629,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
  FileDE23_Obj_1455:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  802,    0
    subsprite OAM_SIZE_8x16,     3,  -29, 2630,    0
    subsprite OAM_SIZE_8x16,     2,  -45, 2598,    0
    subsprite OAM_SIZE_8x8,     -5,  -17, 2599,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   66,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2122,    0
  FileDE23_Obj_1463:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  804,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x8,     -1,  -17, 2615,    0
    subsprite OAM_SIZE_32x16,   -1,   -9, 2662,    0
    subsprite OAM_SIZE_16x32,   16,  -41, 2600,    0
    subsprite OAM_SIZE_8x8,      8,  -27, 2631,    0
    subsprite OAM_SIZE_8x8,      8,  -17, 2647,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -27,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2122,    0
  FileDE23_Obj_1474:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2124,    0
    subsprite OAM_SIZE_8x8,    -15,  -13, 2194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  806,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x16,   -13,  -21, 2602,    0
    subsprite OAM_SIZE_8x8,     -5,  -17, 2603,    0
    subsprite OAM_SIZE_8x16,   -15,   -5, 2674,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -27,  194,    0
  FileDE23_Obj_1484:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  806,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x16,   -12,  -22, 2602,    0
    subsprite OAM_SIZE_8x8,     -4,  -18, 2603,    0
    subsprite OAM_SIZE_8x16,   -14,   -6, 2674,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -27,  194,    0
  FileDE23_Obj_1493:
    subsprite OAM_SIZE_8x16,    -7,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -15,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1826,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  808,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2619,    0
    subsprite OAM_SIZE_8x16,     3,  -31, 2671,    0
    subsprite OAM_SIZE_8x16,     7,  -47, 2639,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   98,    0
  FileDE23_Obj_1502:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1826,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  808,    0
    subsprite OAM_SIZE_8x8,     -5,  -19, 2619,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2671,    0
    subsprite OAM_SIZE_8x16,     7,  -46, 2639,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   96,    0
  FileDE23_Obj_1510:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 2196,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  810,    0
    subsprite OAM_SIZE_8x8,     11,  -17,  859,    0
    subsprite OAM_SIZE_16x8,    -4,  -18, 2619,    0
    subsprite OAM_SIZE_8x16,     8,  -27, 2660,    0
    subsprite OAM_SIZE_8x16,    16,  -34, 2661,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   98,    0
  FileDE23_Obj_1519:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 2196,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  812,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 2716,    0
    subsprite OAM_SIZE_8x32,    -6,  -16, 2634,    0
    subsprite OAM_SIZE_32x32,    2,  -17, 2635,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   96,    0
  FileDE23_Obj_1528:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  814,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   96,    0
    subsprite OAM_SIZE_16x8,   -20,  -21, 2699,    0
    subsprite OAM_SIZE_16x8,   -28,  -13, 2803,    0
  FileDE23_Obj_1535:
    subsprite OAM_SIZE_8x16,    -4,  -20, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  814,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   96,    0
    subsprite OAM_SIZE_16x8,   -19,  -21, 2699,    0
    subsprite OAM_SIZE_16x8,   -27,  -13, 2803,    0
  FileDE23_Obj_1542:
    subsprite OAM_SIZE_16x16,   -8,  -21, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1832,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  832,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
    subsprite OAM_SIZE_16x8,    -5,  -22, 2691,    0
    subsprite OAM_SIZE_16x8,    11,  -27, 2693,    0
  FileDE23_Obj_1549:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1832,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  832,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x8,    -6,  -21, 2691,    0
    subsprite OAM_SIZE_16x8,    10,  -26, 2693,    0
  FileDE23_Obj_1556:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -22,  834,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 2675,    0
    subsprite OAM_SIZE_16x8,    -4,  -15, 2695,    0
    subsprite OAM_SIZE_16x8,    12,  -17, 2562,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
  FileDE23_Obj_1564:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  836,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_16x32,  -24,  -18, 2672,    0
    subsprite OAM_SIZE_32x16,   -8,   -1, 2570,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -8,   -9, 2605,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,      2,   -9, 2604,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_1574:
    subsprite OAM_SIZE_8x16,    -1,  -19, 2125,    0, xflip=1
    subsprite OAM_SIZE_8x8,      7,  -11, 2195,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 2698,    0
    subsprite OAM_SIZE_8x8,    -13,  -31, 2697,    0
    subsprite OAM_SIZE_16x8,   -29,  -33, 2706,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -22,  838,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_1584:
    subsprite OAM_SIZE_8x16,    -1,  -18, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_8x8,     -7,  -22, 2698,    0
    subsprite OAM_SIZE_8x8,    -12,  -30, 2697,    0
    subsprite OAM_SIZE_16x8,   -28,  -32, 2706,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -22,  838,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_1593:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  930,    0
    subsprite OAM_SIZE_8x32,     1,  -27, 2736,    0
    subsprite OAM_SIZE_8x16,     1,  -43, 2708,    0
    subsprite OAM_SIZE_8x8,      3,  -15,  944,    0
    subsprite OAM_SIZE_8x16,    -1,  -17,  932,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,    2,    0
    subsprite OAM_SIZE_8x16,   -12,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2091,    0
  FileDE23_Obj_1603:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  930,    0
    subsprite OAM_SIZE_8x32,     1,  -28, 2736,    0
    subsprite OAM_SIZE_8x16,     1,  -44, 2708,    0
    subsprite OAM_SIZE_8x8,      3,  -16,  944,    0
    subsprite OAM_SIZE_8x16,    -1,  -18,  932,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,    0,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0
  FileDE23_Obj_1613:
    subsprite OAM_SIZE_8x32,    -1,  -41, 2736,    0
    subsprite OAM_SIZE_8x8,      1,  -49, 2723,    0
    subsprite OAM_SIZE_8x16,    -1,  -65, 2709,    0
    subsprite OAM_SIZE_8x8,     -9,  -54, 2722,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  949,    0
    subsprite OAM_SIZE_8x8,     -1,  -30,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2093,    0
  FileDE23_Obj_1624:
    subsprite OAM_SIZE_8x32,    -1,  -40, 2736,    0
    subsprite OAM_SIZE_8x16,    -1,  -56, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,      2,  -19,  949,    0
    subsprite OAM_SIZE_8x8,     -1,  -29,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -17, 2091,    0
  FileDE23_Obj_1633:
    subsprite OAM_SIZE_8x32,    -3,  -53, 2736,    0
    subsprite OAM_SIZE_8x8,     -1,  -61, 2723,    0
    subsprite OAM_SIZE_8x16,    -3,  -77, 2709,    0
    subsprite OAM_SIZE_8x8,    -11,  -66, 2722,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -5,  -32,  934,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x16,     0,  -24,  935,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -8,  -17, 2091,    0
  FileDE23_Obj_1644:
    subsprite OAM_SIZE_8x32,    -3,  -52, 2736,    0
    subsprite OAM_SIZE_8x16,    -3,  -68, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -5,  -31,  934,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x16,     0,  -23,  935,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
  FileDE23_Obj_1653:
    subsprite OAM_SIZE_8x32,    -1,  -40, 2736,    0
    subsprite OAM_SIZE_8x16,    -1,  -56, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,      2,  -19,  949,    0
    subsprite OAM_SIZE_8x8,     -1,  -29,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,   -12,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2093,    0
  FileDE23_Obj_1662:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -2,  -23,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2121,    0
    subsprite OAM_SIZE_16x16,  -10,  -13, 2710,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 2711,    0
    subsprite OAM_SIZE_16x16,    8,  -31, 2712,    0
    subsprite OAM_SIZE_8x8,     -2,  -15,  957,    0
    subsprite OAM_SIZE_8x16,    -7,  -17,  940,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   34,    0
  FileDE23_Obj_1673:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 2710,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 2711,    0
    subsprite OAM_SIZE_16x16,    9,  -32, 2712,    0
    subsprite OAM_SIZE_8x8,     -1,  -16,  957,    0
    subsprite OAM_SIZE_8x16,    -6,  -18,  940,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   32,    0
  FileDE23_Obj_1684:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -6,   -3, 2055,    0
    subsprite OAM_SIZE_16x16,   -2,  -25, 2710,    0
    subsprite OAM_SIZE_8x8,     12,  -31, 2711,    0
    subsprite OAM_SIZE_8x8,     16,  -35, 2711,    0
    subsprite OAM_SIZE_8x8,     29,  -36,  297,    0
    subsprite OAM_SIZE_16x16,   22,  -49, 2714,    0
    subsprite OAM_SIZE_8x8,      5,  -20,  942,    0
    subsprite OAM_SIZE_8x8,     -1,  -18,  958,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   34,    0
  FileDE23_Obj_1696:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2121,    0
    subsprite OAM_SIZE_16x16,   -3,  -24, 2710,    0
    subsprite OAM_SIZE_8x8,     10,  -29, 2711,    0
    subsprite OAM_SIZE_16x16,   15,  -42, 2712,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  942,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
  FileDE23_Obj_1705:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    5,  -36, 2710,    0
    subsprite OAM_SIZE_8x8,     19,  -42, 2711,    0
    subsprite OAM_SIZE_8x8,     23,  -46, 2711,    0
    subsprite OAM_SIZE_8x8,     36,  -47,  297,    0
    subsprite OAM_SIZE_16x16,   29,  -60, 2714,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  938,    0
    subsprite OAM_SIZE_8x8,      8,  -29,  943,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  959,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2121,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   34,    0
  FileDE23_Obj_1716:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    4,  -35, 2710,    0
    subsprite OAM_SIZE_8x8,     17,  -40, 2711,    0
    subsprite OAM_SIZE_16x16,   22,  -53, 2712,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  938,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -6,   -2, 2055,    0
    subsprite OAM_SIZE_8x8,      7,  -28,  943,    0
    subsprite OAM_SIZE_8x8,      1,  -19,  959,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   32,    0
  FileDE23_Obj_1726:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2122,    0
    subsprite OAM_SIZE_16x16,   -3,  -24, 2710,    0
    subsprite OAM_SIZE_8x8,     10,  -29, 2711,    0
    subsprite OAM_SIZE_16x16,   15,  -42, 2712,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  942,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
  FileDE23_Obj_1735:
    subsprite OAM_SIZE_8x16,    -7,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -15,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -20,  -14, 2741,    0
    subsprite OAM_SIZE_16x8,    12,  -14, 2745,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,  964,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  981,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  965,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   66,    0
    subsprite OAM_SIZE_8x8,    -17,  -30,  194,    0
  FileDE23_Obj_1746:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -19,  -14, 2741,    0
    subsprite OAM_SIZE_16x8,    13,  -14, 2745,    0
    subsprite OAM_SIZE_8x16,   -10,  -21,  964,    0
    subsprite OAM_SIZE_8x8,     -2,  -13,  981,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  965,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
  FileDE23_Obj_1756:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -6,  -16, 2741,    0
    subsprite OAM_SIZE_8x8,     26,  -16, 2747,    0
    subsprite OAM_SIZE_8x16,    34,  -18, 2732,    0
    subsprite OAM_SIZE_8x8,     42,  -16, 2800,    0
    subsprite OAM_SIZE_8x8,     -6,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     1,  -21,  967,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -16,  -29,  194,    0
  FileDE23_Obj_1767:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -7,  -16, 2741,    0
    subsprite OAM_SIZE_16x8,    25,  -16, 2745,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  967,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
  FileDE23_Obj_1777:
    subsprite OAM_SIZE_8x8,    -14,  -11, 2195,    0
    subsprite OAM_SIZE_8x16,    -6,  -19, 2125,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  962,    0
    subsprite OAM_SIZE_32x8,     6,  -18, 2741,    0
    subsprite OAM_SIZE_8x8,     38,  -18, 2747,    0
    subsprite OAM_SIZE_8x16,    46,  -20, 2732,    0
    subsprite OAM_SIZE_8x8,     54,  -18, 2800,    0
    subsprite OAM_SIZE_16x8,     6,  -21,  984,    0
    subsprite OAM_SIZE_16x8,    -3,  -18,  968,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -15,  -29,  194,    0
  FileDE23_Obj_1789:
    subsprite OAM_SIZE_8x16,    -6,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  962,    0
    subsprite OAM_SIZE_32x8,     5,  -18, 2741,    0
    subsprite OAM_SIZE_16x8,    37,  -18, 2745,    0
    subsprite OAM_SIZE_16x8,     5,  -21,  984,    0
    subsprite OAM_SIZE_16x8,    -4,  -18,  968,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -15,  -28,  194,    0
  FileDE23_Obj_1798:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -7,  -16, 2741,    0
    subsprite OAM_SIZE_16x8,    25,  -16, 2745,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  967,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
  FileDE23_Obj_1807:
    subsprite OAM_SIZE_16x16,   -8,  -21, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_16x16,  -18,  -25, 2737,    0
    subsprite OAM_SIZE_8x8,     -5,  -12, 2754,    0
    subsprite OAM_SIZE_16x16,    0,   -7, 2769,    0
    subsprite OAM_SIZE_8x8,    -12,  -25,  982,    0
    subsprite OAM_SIZE_8x8,    -10,  -15,  974,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  975,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   98,    0
  FileDE23_Obj_1818:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_16x16,  -17,  -24, 2737,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 2754,    0
    subsprite OAM_SIZE_16x16,    1,   -6, 2769,    0
    subsprite OAM_SIZE_8x8,    -11,  -24,  982,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  974,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  975,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   96,    0
  FileDE23_Obj_1829:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -6,  -17, 2737,    0
    subsprite OAM_SIZE_8x8,      8,   -3, 2754,    0
    subsprite OAM_SIZE_8x8,     12,    1, 2754,    0
    subsprite OAM_SIZE_8x8,     25,    6,  297,    0
    subsprite OAM_SIZE_16x16,   18,    7, 2739,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  990,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   98,    0
    subsprite OAM_SIZE_8x16,     3,  -21,  992,    0
  FileDE23_Obj_1840:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 2737,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2754,    0
    subsprite OAM_SIZE_16x16,   11,    0, 2769,    0
    subsprite OAM_SIZE_8x8,      2,  -14, 1008,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  990,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   96,    0
  FileDE23_Obj_1850:
    subsprite OAM_SIZE_16x16,   -7,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  972,    0
    subsprite OAM_SIZE_16x16,    5,  -10, 2737,    0
    subsprite OAM_SIZE_8x8,     19,    4, 2754,    0
    subsprite OAM_SIZE_8x8,     23,    8, 2754,    0
    subsprite OAM_SIZE_8x8,     36,   13,  297,    0
    subsprite OAM_SIZE_16x16,   29,   14, 2739,    0
    subsprite OAM_SIZE_8x8,     -5,  -18,  993,    0
    subsprite OAM_SIZE_8x8,      3,  -12, 1009,    0
    subsprite OAM_SIZE_8x16,     5,  -18,  994,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   98,    0
  FileDE23_Obj_1862:
    subsprite OAM_SIZE_8x16,    -3,  -20, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  994,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  972,    0
    subsprite OAM_SIZE_16x16,    4,  -11, 2737,    0
    subsprite OAM_SIZE_8x8,     17,    2, 2754,    0
    subsprite OAM_SIZE_16x16,   22,    7, 2769,    0
    subsprite OAM_SIZE_8x8,     -6,  -19,  993,    0
    subsprite OAM_SIZE_8x8,      2,  -13, 1009,    0
    subsprite OAM_SIZE_8x8,      4,  -11, 1010,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,   96,    0
  FileDE23_Obj_1873:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 2737,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2754,    0
    subsprite OAM_SIZE_16x16,   11,    0, 2769,    0
    subsprite OAM_SIZE_8x8,      2,  -14, 1008,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  990,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   96,    0
  FileDE23_Obj_1883:
    subsprite OAM_SIZE_8x16,     0,  -20, 2125,    0, xflip=1
    subsprite OAM_SIZE_8x8,      8,  -12, 2195,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -8,   -3, 2772,    0
    subsprite OAM_SIZE_8x8,     -6,  -28,  991,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -20,  999,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,  130,    0
  FileDE23_Obj_1893:
    subsprite OAM_SIZE_8x16,     0,  -19, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_8x32,    -8,  -34, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -8,   -2, 2772,    0
    subsprite OAM_SIZE_8x8,     -6,  -27,  991,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -19,  999,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,  128,    0
  FileDE23_Obj_1902:
    subsprite OAM_SIZE_8x16,     1,  -19, 2126,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -21, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -4,   11, 2801,    0
    subsprite OAM_SIZE_8x8,    -14,   21, 2802,    0
    subsprite OAM_SIZE_8x16,    -6,   19, 2771,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -16, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -8, 1017,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  130,    0
  FileDE23_Obj_1914:
    subsprite OAM_SIZE_8x16,     0,  -19, 2125,    0, xflip=1
    subsprite OAM_SIZE_8x8,      8,  -11, 2195,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -22, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -9, 1017,    0
    subsprite OAM_SIZE_8x16,    -6,   10, 2772,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_1925:
    subsprite OAM_SIZE_8x8,      8,  -10, 2195,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -18, 2125,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  997,    0
    subsprite OAM_SIZE_8x32,    -4,   -9, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -2,   23, 2801,    0
    subsprite OAM_SIZE_8x8,    -12,   33, 2802,    0
    subsprite OAM_SIZE_8x16,    -4,   31, 2771,    0
    subsprite OAM_SIZE_8x16,    -7,  -20, 1002,    0
    subsprite OAM_SIZE_8x16,    -1,  -14, 1003,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  130,    0
  FileDE23_Obj_1937:
    subsprite OAM_SIZE_8x16,     0,  -17, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  997,    0
    subsprite OAM_SIZE_8x32,    -4,  -10, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -4,   22, 2772,    0
    subsprite OAM_SIZE_8x16,    -7,  -21, 1002,    0
    subsprite OAM_SIZE_8x16,    -1,  -15, 1003,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  128,    0
  FileDE23_Obj_1946:
    subsprite OAM_SIZE_8x16,     1,  -19, 2126,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -22, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -9, 1017,    0
    subsprite OAM_SIZE_8x16,    -6,   10, 2772,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
  FileDE23_Obj_1956:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2826,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1040,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -30, 1024,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2060,    0
  FileDE23_Obj_1965:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -26, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2058,    0
  FileDE23_Obj_1973:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 2048,    0
  FileDE23_Obj_1981:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -8,  -31, 1027,    0
    subsprite OAM_SIZE_8x16,     0,  -31, 1027,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -5,  -38, 2854,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2060,    0
  FileDE23_Obj_1988:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -8,  -32, 1027,    0
    subsprite OAM_SIZE_8x16,     0,  -32, 1027,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -5,  -39, 2854,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2056,    0
  FileDE23_Obj_1995:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2084,    0
  FileDE23_Obj_2003:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2826,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1040,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -30, 1024,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,    4,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2082,    0
  FileDE23_Obj_2012:
    subsprite OAM_SIZE_16x16,   -5,  -36, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -20, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -21, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -21, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2702,    0
  FileDE23_Obj_2021:
    subsprite OAM_SIZE_16x16,   -5,  -37, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -21, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -22, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -22, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2058,    0
  FileDE23_Obj_2030:
    subsprite OAM_SIZE_16x16,   -5,  -36, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -20, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -21, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -21, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 2048,    0
  FileDE23_Obj_2039:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2060,    0
  FileDE23_Obj_2047:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x8,    -5,  -24, 1034,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1028,    0
    subsprite OAM_SIZE_8x16,     1,  -25, 1036,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -19, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2093,    0
  FileDE23_Obj_2057:
    subsprite OAM_SIZE_16x16,   -5,  -45, 2819,    0
    subsprite OAM_SIZE_8x16,     1,  -29, 2821,    0
    subsprite OAM_SIZE_16x8,    -7,  -22, 1050,    0
    subsprite OAM_SIZE_8x8,     -1,  -26, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   34,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2091,    0
    subsprite OAM_SIZE_8x8,     -1,  -18, 1053,    0
  FileDE23_Obj_2067:
    subsprite OAM_SIZE_16x16,   -4,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     2,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -23, 1050,    0
    subsprite OAM_SIZE_8x8,      0,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 1053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -2, 2053,    0
  FileDE23_Obj_2077:
    subsprite OAM_SIZE_8x8,     -7,  -24, 1038,    0
    subsprite OAM_SIZE_8x8,      1,  -28, 1054,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_16x16,  -12,  -39, 2852,    0, xflip=1
    subsprite OAM_SIZE_8x8,      4,  -29, 2831,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1292,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2093,    0
    subsprite OAM_SIZE_8x16,    -1,  -28, 1039,    0
    subsprite OAM_SIZE_8x8,      2,  -29,  548,    0
  FileDE23_Obj_2089:
    subsprite OAM_SIZE_8x8,     -6,  -25, 1038,    0
    subsprite OAM_SIZE_8x8,      2,  -29, 1054,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2088,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2089,    0
    subsprite OAM_SIZE_16x16,  -11,  -40, 2852,    0, xflip=1
    subsprite OAM_SIZE_8x8,      5,  -30, 2831,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -7,  -24, 1292,    0
    subsprite OAM_SIZE_8x16,     0,  -29, 1039,    0
    subsprite OAM_SIZE_8x8,      3,  -30,  548,    0
  FileDE23_Obj_2101:
    subsprite OAM_SIZE_16x16,   -3,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -5,  -23, 1050,    0
    subsprite OAM_SIZE_8x8,      1,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 1053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_16x16,  -15,  -19, 2116,    0
    subsprite OAM_SIZE_8x8,     -9,   -3, 2055,    0
  FileDE23_Obj_2111:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x8,    -4,  -24, 1056,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1030,    0
    subsprite OAM_SIZE_8x16,     2,  -25, 1058,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   36,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2114,    0
    subsprite OAM_SIZE_8x8,     -7,   -5, 2054,    0
  FileDE23_Obj_2121:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -23, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -18, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 2858,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -18, 1073,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   34,    0
    subsprite OAM_SIZE_16x16,  -14,  -19, 2734,    0
  FileDE23_Obj_2131:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -29, 2858,    0
    subsprite OAM_SIZE_8x8,     -2,  -18, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -19, 1073,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -18, 2090,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2091,    0
  FileDE23_Obj_2142:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -23, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -18, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 2858,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -18, 1073,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -2,   -2, 2053,    0
  FileDE23_Obj_2153:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x8,    -4,  -24, 1056,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1030,    0
    subsprite OAM_SIZE_8x16,     2,  -25, 1058,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   32,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2093,    0
  FileDE23_Obj_2163:
    subsprite OAM_SIZE_16x16,   -3,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -5,  -23, 1050,    0
    subsprite OAM_SIZE_8x8,      1,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 1053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,   -11,  -18, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2093,    0
  FileDE23_Obj_2173:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -3,  -25, 1063,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1079,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -29,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -20, 2122,    0
    subsprite OAM_SIZE_8x8,     -6,   -4, 2055,    0
    subsprite OAM_SIZE_16x8,    -3,  -19, 1064,    0
  FileDE23_Obj_2186:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -5,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      3,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -16,  -29,  194,    0
    subsprite OAM_SIZE_16x16,   -3,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     3,  -26, 2821,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2121,    0
    subsprite OAM_SIZE_16x8,    -5,  -21, 1066,    0
  FileDE23_Obj_2196:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,   -2,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     4,  -26, 2821,    0
    subsprite OAM_SIZE_16x8,    -4,  -21, 1066,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -7,   -2, 2055,    0
  FileDE23_Obj_2207:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x8,    -5,  -24, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -18,  -41, 2850,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -2,  -29, 2848,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -32, 2716,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -6,   -3, 2055,    0
    subsprite OAM_SIZE_8x8,      5,  -24, 1051,    0
    subsprite OAM_SIZE_8x16,    -5,  -25, 1068,    0
  FileDE23_Obj_2219:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x8,    -4,  -25, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -17,  -42, 2850,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -1,  -30, 2848,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -13,  -33, 2716,    0
    subsprite OAM_SIZE_8x16,   -12,  -19, 2120,    0
    subsprite OAM_SIZE_8x8,      6,  -25, 1051,    0
    subsprite OAM_SIZE_8x16,    -4,  -26, 1068,    0
  FileDE23_Obj_2230:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -3,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,   -1,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     5,  -26, 2821,    0
    subsprite OAM_SIZE_16x16,  -20,  -21, 2148,    0
    subsprite OAM_SIZE_16x8,    -3,  -21, 1066,    0
  FileDE23_Obj_2240:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x16,    -2,  -24, 1069,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1059,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   68,    0
    subsprite OAM_SIZE_8x8,    -15,  -27,  194,    0
    subsprite OAM_SIZE_16x16,  -19,  -22, 2146,    0
    subsprite OAM_SIZE_16x8,    -2,  -18, 1070,    0
  FileDE23_Obj_2251:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -23, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   66,    0
    subsprite OAM_SIZE_8x8,    -14,  -28,  194,    0
    subsprite OAM_SIZE_16x16,  -18,  -19, 2862,    0
    subsprite OAM_SIZE_16x8,    -1,  -12, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -12, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 1104,    0
  FileDE23_Obj_2263:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -24, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -27,  194,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2121,    0
    subsprite OAM_SIZE_16x8,    -1,  -13, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -13, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -18, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -12, 1104,    0
  FileDE23_Obj_2275:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -23, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x16,   -6,  -33,   64,    0
    subsprite OAM_SIZE_8x8,    -14,  -27,  194,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -6,   -2, 2055,    0
    subsprite OAM_SIZE_16x8,    -1,  -12, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -12, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 1104,    0
  FileDE23_Obj_2288:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x16,    -2,  -24, 1069,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1059,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -15,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -6,  -20, 2122,    0
    subsprite OAM_SIZE_8x8,     -5,   -4, 2055,    0
    subsprite OAM_SIZE_16x8,    -2,  -18, 1070,    0
  FileDE23_Obj_2300:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -3,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -16,  -28,  194,    0
    subsprite OAM_SIZE_16x16,   -1,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     5,  -26, 2821,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2122,    0
    subsprite OAM_SIZE_8x8,     -6,   -3, 2055,    0
    subsprite OAM_SIZE_16x8,    -3,  -21, 1066,    0
  FileDE23_Obj_2311:
    subsprite OAM_SIZE_8x16,    -8,  -20, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     1,  -24, 1094,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   96,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_8x8,     -6,  -21, 1093,    0
    subsprite OAM_SIZE_8x8,     -1,  -13, 1109,    0
  FileDE23_Obj_2322:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,    -1,  -24, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   98,    0
    subsprite OAM_SIZE_16x16,   -5,  -39, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -23, 2821,    0
    subsprite OAM_SIZE_16x8,    -8,  -20, 1095,    0
  FileDE23_Obj_2331:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     0,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_16x16,   -4,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     2,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -7,  -19, 1095,    0
  FileDE23_Obj_2339:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 1111,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_16x16,  -12,  -42, 2829,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -26, 2827,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -9,  -21, 1112,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 1114,    0
  FileDE23_Obj_2348:
    subsprite OAM_SIZE_8x8,    -15,  -13, 2194,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2124,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,      0,  -24, 1111,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_16x16,  -11,  -43, 2829,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -27, 2827,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -22, 1112,    0
    subsprite OAM_SIZE_8x8,      0,  -24, 1114,    0
  FileDE23_Obj_2358:
    subsprite OAM_SIZE_16x8,   -16,  -24, 2180,    0
    subsprite OAM_SIZE_8x8,    -15,  -16, 2071,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     1,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_16x16,   -3,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -19, 1095,    0
  FileDE23_Obj_2367:
    subsprite OAM_SIZE_16x8,   -14,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     2,  -22, 1100,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1089,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,  100,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_16x8,    -5,  -18, 1098,    0
  FileDE23_Obj_2377:
    subsprite OAM_SIZE_16x16,  -14,  -19, 2887,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -21, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x16,   -7,  -32,   98,    0
    subsprite OAM_SIZE_16x16,    2,  -12, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    4, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -17, 1115,    0
    subsprite OAM_SIZE_8x8,      2,   -9, 1101,    0
  FileDE23_Obj_2387:
    subsprite OAM_SIZE_8x16,    -6,  -19, 2125,    0
    subsprite OAM_SIZE_8x8,    -14,  -11, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -22, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x16,   -7,  -32,   96,    0
    subsprite OAM_SIZE_16x16,    2,  -13, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    3, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -18, 1115,    0
    subsprite OAM_SIZE_8x8,      2,  -10, 1101,    0
  FileDE23_Obj_2398:
    subsprite OAM_SIZE_8x16,    -6,  -17, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -21, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x16,   -7,  -32,   96,    0
    subsprite OAM_SIZE_16x16,    2,  -12, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    4, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -17, 1115,    0
    subsprite OAM_SIZE_8x8,      2,   -9, 1101,    0
  FileDE23_Obj_2408:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     2,  -22, 1100,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1089,    0
    subsprite OAM_SIZE_16x16,   -8,  -33,   96,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_16x8,    -5,  -18, 1098,    0
  FileDE23_Obj_2418:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     1,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_16x16,   -3,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -19, 1095,    0
  FileDE23_Obj_2426:
    subsprite OAM_SIZE_16x16,   -8,  -21, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x16,    -8,  -22, 1103,    0
    subsprite OAM_SIZE_8x16,     0,  -22, 1103,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
  FileDE23_Obj_2434:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -21, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -22, 1124,    0
  FileDE23_Obj_2443:
    subsprite OAM_SIZE_8x16,    -4,  -20, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
  FileDE23_Obj_2452:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -42, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -26, 2826,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1125,    0
    subsprite OAM_SIZE_8x8,      0,  -20, 1141,    0
  FileDE23_Obj_2461:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2152,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -43, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -27, 2826,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1125,    0
    subsprite OAM_SIZE_8x8,      0,  -21, 1141,    0
  FileDE23_Obj_2470:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
  FileDE23_Obj_2479:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1120,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 1126,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1126,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  132,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
  FileDE23_Obj_2487:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2300,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  130,    0
    subsprite OAM_SIZE_8x8,     -2,   -9, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -4, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   12, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 1127,    0
    subsprite OAM_SIZE_8x16,     0,  -19, 1128,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  948,    0
  FileDE23_Obj_2498:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  128,    0
    subsprite OAM_SIZE_8x8,     -2,  -10, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -5, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   11, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -20, 1127,    0
    subsprite OAM_SIZE_8x8,     -7,   -7,  948,    0
    subsprite OAM_SIZE_8x16,     0,  -20, 1128,    0
  FileDE23_Obj_2509:
    subsprite OAM_SIZE_8x16,    -4,  -19, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_16x16,   -8,  -32,  128,    0
    subsprite OAM_SIZE_8x8,     -2,   -9, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -4, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   12, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 1127,    0
    subsprite OAM_SIZE_8x16,     0,  -19, 1128,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  948,    0
  FileDE23_Obj_2520:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1120,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 1126,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1126,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
  FileDE23_Obj_2528:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
  FileDE23_Obj_2537:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
  FileDE23_Obj_2542:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1781,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_16x16,   -1,  -19, 2734,    0, xflip=1
  FileDE23_Obj_2548:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1783,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -1,  -18, 2118,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,    2,    0
  FileDE23_Obj_2554:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1781,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,    0,    0
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
  FileDE23_Obj_2561:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  871,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
  FileDE23_Obj_2565:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -18, 2080,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
  FileDE23_Obj_2571:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2084,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1766,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   34,    0
  FileDE23_Obj_2577:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   32,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
  FileDE23_Obj_2583:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  878,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
  FileDE23_Obj_2589:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_16x16,  -16,  -19, 2734,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1765,    0
  FileDE23_Obj_2596:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_16x16,  -16,  -18, 2118,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1767,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   66,    0
    subsprite OAM_SIZE_8x8,    -17,  -29,  194,    0
  FileDE23_Obj_2603:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   64,    0
    subsprite OAM_SIZE_8x8,    -17,  -28,  194,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1765,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2049,    0
  FileDE23_Obj_2611:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  902,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2055,    0
  FileDE23_Obj_2616:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,  -20,  -21, 2146,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1780,    0
  FileDE23_Obj_2623:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,  -20,  -25, 2150,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1782,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   98,    0
  FileDE23_Obj_2630:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_16x16,   -9,  -34,   96,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1780,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2055,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2050,    0
  FileDE23_Obj_2638:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  908,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
  FileDE23_Obj_2643:
    subsprite OAM_SIZE_16x16,  -18,  -22, 2887,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1781,    0
  FileDE23_Obj_2650:
    subsprite OAM_SIZE_16x8,   -17,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1783,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  130,    0
  FileDE23_Obj_2657:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,  128,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1781,    0
  FileDE23_Obj_2664:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,  162,    0
  FileDE23_Obj_2670:
    subsprite OAM_SIZE_16x16,   -8,  -29,  162,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -17,  210,    0
    subsprite OAM_SIZE_16x8,    -6,   -1,  242,    0
  FileDE23_Obj_2676:
    subsprite OAM_SIZE_16x8,    -6,   -1,  242,    0
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -17,  210,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,    0,    0
  FileDE23_Obj_2682:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,  164,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
  FileDE23_Obj_2688:
    subsprite OAM_SIZE_16x16,   -7,  -29,  164,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  214,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  246,    0
  FileDE23_Obj_2693:
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  246,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  214,    0
    subsprite OAM_SIZE_16x16,   -7,  -29,   32,    0
  FileDE23_Obj_2698:
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_16x16,   -7,  -33,  166,    0
    subsprite OAM_SIZE_8x8,    -15,  -33,  195,    0
  FileDE23_Obj_2705:
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  218,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  250,    0
    subsprite OAM_SIZE_8x8,    -13,  -26,  195,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  166,    0
    subsprite OAM_SIZE_8x8,      3,  -14,  192,    0
  FileDE23_Obj_2712:
    subsprite OAM_SIZE_8x8,     -8,   -3,  250,    0
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  218,    0
    subsprite OAM_SIZE_16x16,   -7,  -28,   64,    0
    subsprite OAM_SIZE_8x8,    -15,  -22,  194,    0
  FileDE23_Obj_2718:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_16x16,   -7,  -34,  168,    0
  FileDE23_Obj_2724:
    subsprite OAM_SIZE_8x16,    -8,  -19,  221,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  253,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  168,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
  FileDE23_Obj_2730:
    subsprite OAM_SIZE_8x8,     -8,   -3,  253,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  221,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_16x16,   -7,  -27,   96,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
  FileDE23_Obj_2736:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_16x16,   -8,  -35,  170,    0
  FileDE23_Obj_2742:
    subsprite OAM_SIZE_8x8,    -10,   -9,  254,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  170,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
  FileDE23_Obj_2747:
    subsprite OAM_SIZE_8x8,    -10,   -9,  254,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  128,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
  FileDE23_Obj_2752:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -27, 2757,    0
  FileDE23_Obj_2758:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_8x32,   -12,  -30, 2759,    0
    subsprite OAM_SIZE_8x8,    -16,  -28, 1890,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_2765:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 1893,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_2775:
    subsprite OAM_SIZE_8x32,   -15,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -43, 1928,    0
  FileDE23_Obj_2783:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -43, 1261,    0
  FileDE23_Obj_2790:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,    2, 1293,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -14,  281,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,  -43, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -35, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x32,     7,  -33, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -25, 2890,    0, xflip=1
  FileDE23_Obj_2798:
    subsprite OAM_SIZE_8x8,     -7,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -23,  259,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -1,  -27, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x8,      8,  -28, 1890,    0, xflip=1
  FileDE23_Obj_2806:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  269,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1920,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 1992,    0
    subsprite OAM_SIZE_8x32,     3,  -32, 1993,    0
  FileDE23_Obj_2813:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0
    subsprite OAM_SIZE_16x16,   -9,  -27,  290,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  285,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1856,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 1992,    0
    subsprite OAM_SIZE_8x32,     3,  -33, 1993,    0
  FileDE23_Obj_2819:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0
    subsprite OAM_SIZE_16x16,  -10,  -27,  292,    0
    subsprite OAM_SIZE_8x8,      6,  -21,  270,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_8x32,   -10,  -33, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -33, 1993,    0
  FileDE23_Obj_2825:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0
    subsprite OAM_SIZE_8x8,      0,   -5, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,  -10,  -28,  294,    0
    subsprite OAM_SIZE_8x8,      6,  -24,  286,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1888,    0
    subsprite OAM_SIZE_8x32,   -10,  -32, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -32, 1993,    0
  FileDE23_Obj_2832:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  269,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -36, 1920,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 1992,    0
    subsprite OAM_SIZE_8x32,     3,  -32, 1993,    0
  FileDE23_Obj_2839:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -27,  290,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  285,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35, 1856,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 1992,    0
    subsprite OAM_SIZE_8x32,     3,  -33, 1993,    0
  FileDE23_Obj_2845:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -27,  292,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -21,  270,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_8x32,   -10,  -33, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -33, 1993,    0
  FileDE23_Obj_2851:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -5, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -6,  -28,  294,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -24,  286,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -36, 1888,    0
    subsprite OAM_SIZE_8x32,   -10,  -32, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -32, 1993,    0
  FileDE23_Obj_2858:
    subsprite OAM_SIZE_8x32,   -12,  -36, 1994,    0
    subsprite OAM_SIZE_8x8,     -4,  -28, 2906,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1344,    0
    subsprite OAM_SIZE_8x8,     -6,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  320,    0
    subsprite OAM_SIZE_16x16,   -6,  -37, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1890,    0
    subsprite OAM_SIZE_8x32,    -6,  -33, 1995,    0
    subsprite OAM_SIZE_8x8,      2,  -25, 2906,    0
  FileDE23_Obj_2867:
    subsprite OAM_SIZE_8x8,     -4,  -29, 2906,    0
    subsprite OAM_SIZE_8x32,   -12,  -37, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1346,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  322,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1858,    0
    subsprite OAM_SIZE_8x8,      2,  -26, 2906,    0
    subsprite OAM_SIZE_8x32,    -6,  -34, 1995,    0
  FileDE23_Obj_2876:
    subsprite OAM_SIZE_8x8,     -3,  -29, 2906,    0
    subsprite OAM_SIZE_8x32,   -11,  -37, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1348,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  324,    0
    subsprite OAM_SIZE_8x8,     10,  -19,  271,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1890,    0
    subsprite OAM_SIZE_8x8,      1,  -26, 2906,    0
    subsprite OAM_SIZE_8x32,    -7,  -34, 1995,    0
  FileDE23_Obj_2886:
    subsprite OAM_SIZE_8x8,     -3,  -28, 2906,    0
    subsprite OAM_SIZE_8x32,   -11,  -36, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1350,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  326,    0
    subsprite OAM_SIZE_8x8,      9,  -23,  287,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1891,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1874,    0
    subsprite OAM_SIZE_8x8,      1,  -25, 2906,    0
    subsprite OAM_SIZE_8x32,    -7,  -33, 1995,    0
  FileDE23_Obj_2896:
    subsprite OAM_SIZE_8x8,     -4,  -28, 2906,    0
    subsprite OAM_SIZE_8x32,   -12,  -36, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1352,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -6,  -25,  328,    0
    subsprite OAM_SIZE_8x8,     10,  -20,  296,    0
    subsprite OAM_SIZE_16x16,   -6,  -37, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1890,    0
    subsprite OAM_SIZE_8x8,      2,  -25, 2906,    0
    subsprite OAM_SIZE_8x32,    -6,  -33, 1995,    0
  FileDE23_Obj_2906:
    subsprite OAM_SIZE_8x8,     -4,  -29, 2906,    0
    subsprite OAM_SIZE_8x32,   -12,  -37, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1354,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1310,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  330,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1858,    0
    subsprite OAM_SIZE_8x8,      2,  -26, 2906,    0
    subsprite OAM_SIZE_8x32,    -6,  -34, 1995,    0
  FileDE23_Obj_2915:
    subsprite OAM_SIZE_8x8,     -3,  -29, 2906,    0
    subsprite OAM_SIZE_8x32,   -11,  -37, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1356,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  332,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1890,    0
    subsprite OAM_SIZE_8x8,      1,  -26, 2906,    0
    subsprite OAM_SIZE_8x32,    -7,  -34, 1995,    0
  FileDE23_Obj_2923:
    subsprite OAM_SIZE_8x8,     -3,  -28, 2906,    0
    subsprite OAM_SIZE_8x32,   -11,  -36, 1994,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1358,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1311,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  334,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1891,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1874,    0
    subsprite OAM_SIZE_8x8,      1,  -25, 2906,    0
    subsprite OAM_SIZE_8x32,    -7,  -33, 1995,    0
  FileDE23_Obj_2932:
    subsprite OAM_SIZE_16x32,  -18,  -38, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1376,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  352,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1924,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1893,    0
    subsprite OAM_SIZE_16x32,  -19,  -34, 1998,    0
  FileDE23_Obj_2940:
    subsprite OAM_SIZE_16x32,  -18,  -39, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1378,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  354,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1862,    0
    subsprite OAM_SIZE_8x8,    -13,  -36, 1861,    0
    subsprite OAM_SIZE_16x32,  -19,  -35, 1998,    0
  FileDE23_Obj_2947:
    subsprite OAM_SIZE_16x32,  -17,  -39, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1380,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  356,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -13,  -34, 1893,    0
    subsprite OAM_SIZE_16x32,  -18,  -35, 1998,    0
  FileDE23_Obj_2954:
    subsprite OAM_SIZE_16x32,  -17,  -38, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 1382,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  358,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1877,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1894,    0
    subsprite OAM_SIZE_16x32,  -18,  -34, 1998,    0
  FileDE23_Obj_2961:
    subsprite OAM_SIZE_16x32,  -18,  -38, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1384,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  360,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1924,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1893,    0
    subsprite OAM_SIZE_16x32,  -19,  -34, 1998,    0
  FileDE23_Obj_2968:
    subsprite OAM_SIZE_16x32,  -18,  -39, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1386,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  362,    0
    subsprite OAM_SIZE_8x8,    -13,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1862,    0
    subsprite OAM_SIZE_16x32,  -19,  -35, 1998,    0
  FileDE23_Obj_2974:
    subsprite OAM_SIZE_16x32,  -17,  -39, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1388,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  364,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -13,  -34, 1893,    0
    subsprite OAM_SIZE_16x32,  -18,  -35, 1998,    0
  FileDE23_Obj_2980:
    subsprite OAM_SIZE_16x32,  -17,  -38, 1996,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1390,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  366,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1894,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1877,    0
    subsprite OAM_SIZE_16x32,  -18,  -34, 1998,    0
  FileDE23_Obj_2987:
    subsprite OAM_SIZE_8x8,     -5,  -32, 1016,    0
    subsprite OAM_SIZE_8x32,   -16,  -37, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -29, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1408,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  384,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  281,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -42, 1928,    0
  FileDE23_Obj_2996:
    subsprite OAM_SIZE_8x8,     -5,  -33, 1016,    0
    subsprite OAM_SIZE_8x32,   -16,  -38, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -30, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1410,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  386,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1880,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1864,    0
  FileDE23_Obj_3004:
    subsprite OAM_SIZE_8x8,     -6,  -33, 1016,    0
    subsprite OAM_SIZE_8x32,   -15,  -38, 2701,    0
    subsprite OAM_SIZE_8x16,    -7,  -30, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1412,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  388,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -41, 1928,    0
  FileDE23_Obj_3011:
    subsprite OAM_SIZE_8x8,     -6,  -32, 1016,    0
    subsprite OAM_SIZE_8x32,   -15,  -37, 2701,    0
    subsprite OAM_SIZE_8x16,    -7,  -29, 2891,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1414,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  390,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1913,    0
    subsprite OAM_SIZE_8x8,    -10,  -37, 1912,    0
  FileDE23_Obj_3019:
    subsprite OAM_SIZE_8x8,     -5,  -32, 1016,    0
    subsprite OAM_SIZE_8x32,   -16,  -37, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -29, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1416,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1326,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  392,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -42, 1928,    0
  FileDE23_Obj_3027:
    subsprite OAM_SIZE_8x8,     -5,  -33, 1016,    0
    subsprite OAM_SIZE_8x32,   -16,  -38, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -30, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1418,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  394,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1880,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1864,    0
  FileDE23_Obj_3034:
    subsprite OAM_SIZE_8x8,     -6,  -33, 1016,    0
    subsprite OAM_SIZE_8x32,   -15,  -38, 2701,    0
    subsprite OAM_SIZE_8x16,    -7,  -30, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1420,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  396,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -41, 1928,    0
  FileDE23_Obj_3041:
    subsprite OAM_SIZE_8x8,     -6,  -32, 1016,    0
    subsprite OAM_SIZE_8x32,   -15,  -37, 2701,    0
    subsprite OAM_SIZE_8x16,    -7,  -29, 2891,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1422,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  398,    0
    subsprite OAM_SIZE_8x8,      8,  -21,  312,    0
    subsprite OAM_SIZE_8x8,    -10,  -37, 1912,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1913,    0
  FileDE23_Obj_3051:
    subsprite OAM_SIZE_8x32,   -11,  -40, 2766,    0
    subsprite OAM_SIZE_8x32,     3,  -40, 2767,    0
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0
    subsprite OAM_SIZE_8x8,     -9,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -24,  416,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  297,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
  FileDE23_Obj_3060:
    subsprite OAM_SIZE_8x32,     3,  -41, 2767,    0
    subsprite OAM_SIZE_8x32,   -11,  -41, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  418,    0
    subsprite OAM_SIZE_8x8,      7,  -18,  313,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
  FileDE23_Obj_3068:
    subsprite OAM_SIZE_8x32,     2,  -41, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -41, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  298,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_3076:
    subsprite OAM_SIZE_8x32,     2,  -40, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -40, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  314,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1868,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1839,    0
  FileDE23_Obj_3084:
    subsprite OAM_SIZE_8x32,     3,  -40, 2767,    0
    subsprite OAM_SIZE_8x32,   -11,  -40, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    1, 1294,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  416,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  297,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_3093:
    subsprite OAM_SIZE_8x32,     3,  -41, 2767,    0
    subsprite OAM_SIZE_8x32,   -11,  -41, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -23,  418,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -18,  313,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
  FileDE23_Obj_3101:
    subsprite OAM_SIZE_8x32,     2,  -41, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -41, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -18,  298,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_3109:
    subsprite OAM_SIZE_8x32,     2,  -40, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -40, 2766,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  314,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1868,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1839,    0
  FileDE23_Obj_3117:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1576,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -28, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_3123:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1578,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -28, 2760,    0
    subsprite OAM_SIZE_8x8,     -2,  -22,  301,    0
  FileDE23_Obj_3131:
    subsprite OAM_SIZE_8x8,     -6,  -27, 2889,    0
    subsprite OAM_SIZE_8x32,   -14,  -35, 2761,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1580,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 1893,    0
    subsprite OAM_SIZE_16x8,    -4,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  317,    0
    subsprite OAM_SIZE_8x32,   -15,  -30, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -22, 2905,    0
  FileDE23_Obj_3143:
    subsprite OAM_SIZE_8x8,     -6,  -26, 2890,    0
    subsprite OAM_SIZE_8x32,   -14,  -34, 2763,    0
    subsprite OAM_SIZE_16x16,  -10,  -15, 1582,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -8,  -42, 1928,    0
    subsprite OAM_SIZE_16x8,    -6,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  430,    0
  FileDE23_Obj_3152:
    subsprite OAM_SIZE_16x32,   -8,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1600,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1337,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_3160:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_3166:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1888,    0
    subsprite OAM_SIZE_16x32,   -8,  -30, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_3171:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -30, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_3176:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0
    subsprite OAM_SIZE_8x8,      0,   -4, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1856,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_3182:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_3188:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1888,    0
    subsprite OAM_SIZE_16x32,   -8,  -30, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_3193:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -30, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_3198:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1856,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_3204:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1472,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -29, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_3211:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1474,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1291,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1891,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1874,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -30, 2760,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_3220:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1476,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -6,  -37, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1890,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -30, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_3228:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1478,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1858,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -29, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_3236:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1480,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -29, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_3244:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1482,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -6,  -36, 1891,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1874,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -30, 2760,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_3253:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1484,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -6,  -37, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1890,    0
    subsprite OAM_SIZE_8x32,   -11,  -33, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -30, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_3262:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1486,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1858,    0
    subsprite OAM_SIZE_8x32,   -11,  -32, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -29, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_3270:
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1504,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_8x8,    -13,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1924,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
    subsprite OAM_SIZE_8x8,     -6,  -22, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -30, 2762,    0
  FileDE23_Obj_3282:
    subsprite OAM_SIZE_8x8,     -5,  -28, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -36, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1506,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1894,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1877,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -31, 2762,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_3293:
    subsprite OAM_SIZE_8x8,     -5,  -28, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -36, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1508,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1924,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -31, 2762,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
  FileDE23_Obj_3304:
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 1510,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1862,    0
    subsprite OAM_SIZE_8x8,    -13,  -36, 1861,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,     -6,  -22, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -30, 2762,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_3315:
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1512,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_8x8,    -13,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1924,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,     -6,  -22, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -30, 2762,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
  FileDE23_Obj_3326:
    subsprite OAM_SIZE_8x8,     -5,  -28, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -36, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1514,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1877,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1894,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -31, 2762,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_3337:
    subsprite OAM_SIZE_8x8,     -5,  -28, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -36, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -15, 1516,    0
    subsprite OAM_SIZE_8x8,     -3,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1924,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -31, 2762,    0
  FileDE23_Obj_3348:
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_16x16,   -7,  -14, 1518,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_8x8,    -13,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 1862,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,     -6,  -22, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -30, 2762,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_3359:
    subsprite OAM_SIZE_8x32,   -13,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2890,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1536,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -41, 1928,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_3368:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2890,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1538,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_8x8,    -10,  -37, 1912,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1913,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_3377:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2890,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1540,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_8x8,     -7,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1926,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_3386:
    subsprite OAM_SIZE_8x32,   -13,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2890,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1542,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1880,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1864,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_3395:
    subsprite OAM_SIZE_8x32,   -13,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2890,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1544,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_8x8,     -7,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1926,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_3404:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2890,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1546,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_8x8,    -10,  -37, 1912,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1913,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_3412:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2890,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1548,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_8x8,     -7,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1926,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_3421:
    subsprite OAM_SIZE_8x32,   -13,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2890,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1550,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1864,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1880,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_3431:
    subsprite OAM_SIZE_16x32,   -8,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0
    subsprite OAM_SIZE_8x8,     -9,    2, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_3439:
    subsprite OAM_SIZE_16x32,   -8,  -38, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1868,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1839,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_3446:
    subsprite OAM_SIZE_16x32,   -8,  -38, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_3453:
    subsprite OAM_SIZE_16x32,   -8,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_3460:
    subsprite OAM_SIZE_16x32,   -8,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_3468:
    subsprite OAM_SIZE_16x32,   -8,  -38, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1839,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1868,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_3475:
    subsprite OAM_SIZE_16x32,   -8,  -38, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_3482:
    subsprite OAM_SIZE_16x32,   -8,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_3489:
    subsprite OAM_SIZE_8x32,     7,  -31, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -44, 1928,    0, xflip=1
  FileDE23_Obj_3495:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -16, 1604,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  514,    0
    subsprite OAM_SIZE_8x8,      3,  -45, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -37, 1926,    0, xflip=1
  FileDE23_Obj_3501:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  516,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -45, 1928,    0, xflip=1
  FileDE23_Obj_3507:
    subsprite OAM_SIZE_8x32,     7,  -31, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  518,    0
    subsprite OAM_SIZE_8x8,      7,   -8,  548,    0
    subsprite OAM_SIZE_8x8,      3,  -44, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -36, 1926,    0, xflip=1
  FileDE23_Obj_3514:
    subsprite OAM_SIZE_8x32,     7,  -31, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  520,    0
    subsprite OAM_SIZE_8x8,      3,   -8,  548,    0
    subsprite OAM_SIZE_8x8,      3,  -44, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -36, 1926,    0, xflip=1
  FileDE23_Obj_3521:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -16, 1608,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -45, 1928,    0, xflip=1
  FileDE23_Obj_3527:
    subsprite OAM_SIZE_8x32,     7,  -31, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -15, 1610,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1325,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -44, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -36, 1926,    0, xflip=1
  FileDE23_Obj_3533:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -16, 1612,    0
    subsprite OAM_SIZE_8x8,     -1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -45, 1928,    0, xflip=1
  FileDE23_Obj_3539:
    subsprite OAM_SIZE_8x32,     7,  -31, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -15, 1614,    0
    subsprite OAM_SIZE_8x8,    -11,    1, 1326,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_8x8,      3,  -44, 1928,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -36, 1926,    0, xflip=1
  FileDE23_Obj_3545:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 1926,    0, xflip=1
    subsprite OAM_SIZE_8x8,      3,  -45, 1928,    0, xflip=1
  FileDE23_Obj_3551:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x32,     5,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -27, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -25, 2760,    0, xflip=1
  FileDE23_Obj_3558:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1634,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  524,    0
    subsprite OAM_SIZE_8x32,     5,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -28, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_3565:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  526,    0
    subsprite OAM_SIZE_8x32,     5,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -28, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_3572:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  544,    0
    subsprite OAM_SIZE_8x32,     5,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -27, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -25, 2760,    0, xflip=1
  FileDE23_Obj_3579:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  546,    0
    subsprite OAM_SIZE_8x8,    -14,  -11,  564,    0
    subsprite OAM_SIZE_8x32,     5,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -27, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -25, 2760,    0, xflip=1
  FileDE23_Obj_3587:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1638,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x32,     5,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -28, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_3594:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1640,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x32,     5,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -27, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -25, 2760,    0, xflip=1
  FileDE23_Obj_3600:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1642,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x32,     5,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -28, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_3606:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1644,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x8,     -5,    3, 1291,    0, xflip=1
    subsprite OAM_SIZE_8x32,     5,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -27, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -25, 2760,    0, xflip=1
  FileDE23_Obj_3613:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x32,     5,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -36, 1922,    0, xflip=1
    subsprite OAM_SIZE_8x8,     10,  -28, 1890,    0, xflip=1
    subsprite OAM_SIZE_8x32,     1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_3620:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1646,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  549,    0
    subsprite OAM_SIZE_16x16,  -26,  -34, 1252,    0
    subsprite OAM_SIZE_8x16,   -10,  -34, 1254,    0
    subsprite OAM_SIZE_16x16,   -7,  -37, 1984,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 1944,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 1220,    0
    subsprite OAM_SIZE_8x16,     5,   -6, 1222,    0
  FileDE23_Obj_3628:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1664,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  551,    0
    subsprite OAM_SIZE_32x8,   -32,  -28, 1255,    0
    subsprite OAM_SIZE_16x8,   -24,  -20, 1272,    0
    subsprite OAM_SIZE_8x8,     -8,  -20, 1274,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_16x16,  -13,  -15, 1188,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 1174,    0
  FileDE23_Obj_3638:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1666,    0
    subsprite OAM_SIZE_8x8,     -2,    3, 1291,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  553,    0
    subsprite OAM_SIZE_32x8,   -30,  -29, 1255,    0
    subsprite OAM_SIZE_16x8,   -22,  -21, 1272,    0
    subsprite OAM_SIZE_8x8,     -6,  -21, 1274,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 1954,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1906,    0
    subsprite OAM_SIZE_8x8,     -3,  -25, 1174,    0
    subsprite OAM_SIZE_16x16,  -11,  -17, 1188,    0
  FileDE23_Obj_3648:
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_16x16,    6,  -18, 2018,    0
    subsprite OAM_SIZE_16x8,     6,  -26, 2032,    0
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1191,    0
    subsprite OAM_SIZE_8x8,    -14,  -35, 1271,    0
    subsprite OAM_SIZE_8x8,      2,  -19, 1193,    0
    subsprite OAM_SIZE_8x8,     10,  -27, 1209,    0
    subsprite OAM_SIZE_16x16,   11,  -18, 1196,    0
    subsprite OAM_SIZE_8x8,     19,   -2, 1277,    0
  FileDE23_Obj_3661:
    subsprite OAM_SIZE_16x16,   -4,  -13,  557,    0
    subsprite OAM_SIZE_8x8,      3,  -21,  577,    0
    subsprite OAM_SIZE_16x16,    6,  -19, 2018,    0
    subsprite OAM_SIZE_16x8,     6,  -27, 2016,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  593,    0
    subsprite OAM_SIZE_8x8,     12,  -11,  578,    0
    subsprite OAM_SIZE_8x8,    -12,    1,  594,    0
    subsprite OAM_SIZE_16x16,  -11,  -31, 1223,    0
    subsprite OAM_SIZE_8x8,      5,  -23, 1206,    0
    subsprite OAM_SIZE_8x8,    -11,  -39, 1190,    0
    subsprite OAM_SIZE_16x16,    9,  -15, 1198,    0
  FileDE23_Obj_3672:
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_16x16,    6,  -18, 2018,    0
    subsprite OAM_SIZE_16x8,     6,  -26, 2032,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_32x8,   -24,  -13, 1179,    0
    subsprite OAM_SIZE_16x8,    -8,  -21, 1275,    0
    subsprite OAM_SIZE_16x16,    4,  -12, 1194,    0
    subsprite OAM_SIZE_8x16,     4,    4, 1225,    0
  FileDE23_Obj_3683:
    subsprite OAM_SIZE_16x16,   -1,  -37, 1129,    0
    subsprite OAM_SIZE_8x16,    15,  -37, 1131,    0
    subsprite OAM_SIZE_16x16,  -19,  -31, 1153,    0
    subsprite OAM_SIZE_8x16,   -27,  -23, 1152,    0
    subsprite OAM_SIZE_8x8,    -19,  -15, 1185,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1668,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1338,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  579,    0
    subsprite OAM_SIZE_8x8,      8,  -24,  585,    0
    subsprite OAM_SIZE_8x8,    -16,  -19,  601,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1988,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 2006,    0
  FileDE23_Obj_3695:
    subsprite OAM_SIZE_16x8,   -13,  -47, 1232,    0
    subsprite OAM_SIZE_8x16,    -5,  -39, 1251,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1670,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -24,  581,    0
    subsprite OAM_SIZE_8x8,      5,  -23,  586,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_16x16,  -20,  -36, 1156,    0
    subsprite OAM_SIZE_8x8,    -28,  -36, 1155,    0
  FileDE23_Obj_3705:
    subsprite OAM_SIZE_16x8,    -9,  -44, 1232,    0
    subsprite OAM_SIZE_8x16,    -1,  -36, 1251,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1672,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  583,    0
    subsprite OAM_SIZE_8x8,      9,  -14,  602,    0
    subsprite OAM_SIZE_16x16,   -5,  -29, 1986,    0
    subsprite OAM_SIZE_16x8,    -5,  -37, 1990,    0
    subsprite OAM_SIZE_8x8,    -25,  -33, 1155,    0
    subsprite OAM_SIZE_16x16,  -17,  -33, 1156,    0
  FileDE23_Obj_3714:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_16x16,    0,    2, 2020,    0
    subsprite OAM_SIZE_8x16,    16,    2, 2022,    0
    subsprite OAM_SIZE_16x16,  -11,   -6, 1248,    0
    subsprite OAM_SIZE_8x16,   -11,  -22, 1135,    0
    subsprite OAM_SIZE_8x16,     5,   -6, 1250,    0
    subsprite OAM_SIZE_16x16,    8,  -14, 1202,    0
    subsprite OAM_SIZE_16x8,     8,  -22, 1186,    0
    subsprite OAM_SIZE_8x8,     16,  -30, 1171,    0
  FileDE23_Obj_3727:
    subsprite OAM_SIZE_16x16,   -5,   -9,  589,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  609,    0
    subsprite OAM_SIZE_8x8,      1,    7,  625,    0
    subsprite OAM_SIZE_8x8,    -10,  -17,  610,    0
    subsprite OAM_SIZE_8x8,     11,   -1,  626,    0
    subsprite OAM_SIZE_16x16,    0,    1, 2020,    0
    subsprite OAM_SIZE_8x16,    16,    1, 2023,    0
    subsprite OAM_SIZE_8x16,   -14,  -13, 1132,    0
    subsprite OAM_SIZE_16x16,   -6,   -5, 1133,    0
    subsprite OAM_SIZE_16x16,    4,  -15, 1200,    0
    subsprite OAM_SIZE_8x8,     12,  -23, 1184,    0
  FileDE23_Obj_3738:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_8x16,    16,    2, 2022,    0
    subsprite OAM_SIZE_16x16,    0,    2, 2020,    0
    subsprite OAM_SIZE_32x8,   -21,   -1, 1158,    0
    subsprite OAM_SIZE_16x8,    -5,    7, 1176,    0
    subsprite OAM_SIZE_8x8,    -13,    7, 1175,    0
    subsprite OAM_SIZE_8x16,     2,  -22, 1162,    0
    subsprite OAM_SIZE_16x8,     2,   -6, 1234,    0
  FileDE23_Obj_3750:
    subsprite OAM_SIZE_32x8,   -14,    0, 1158,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -14,    8, 1176,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,    8, 1175,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -13,  -21, 1162,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -21,   -5, 1234,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -10,  -10,  265,    0
    subsprite OAM_SIZE_8x8,      1,    2,  510,    0
    subsprite OAM_SIZE_16x16,  -12,   -9,  611,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  615,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  616,    0
    subsprite OAM_SIZE_8x8,    -20,   -4,  631,    0
    subsprite OAM_SIZE_8x8,     -7,    7,  632,    0
    subsprite OAM_SIZE_16x16,  -23,   -1, 1226,    0
    subsprite OAM_SIZE_8x8,    -15,   15, 1259,    0
  FileDE23_Obj_3764:
    subsprite OAM_SIZE_32x8,   -14,    1, 1158,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -14,    9, 1176,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,    9, 1175,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -13,  -20, 1162,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -21,   -4, 1234,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,    4,  510,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  615,    0
    subsprite OAM_SIZE_16x16,  -11,   -8,  613,    0
    subsprite OAM_SIZE_8x8,    -19,   -3,  617,    0
    subsprite OAM_SIZE_16x8,    -7,    8,  633,    0
    subsprite OAM_SIZE_8x8,      5,  -10,  616,    0
    subsprite OAM_SIZE_16x16,  -23,    0, 1228,    0
    subsprite OAM_SIZE_8x8,    -15,   16, 1260,    0
  FileDE23_Obj_3777:
    subsprite OAM_SIZE_8x32,   -17,  -24, 1994,    0
    subsprite OAM_SIZE_16x16,   -9,  -10, 1674,    0
    subsprite OAM_SIZE_16x16,  -11,  -11,  619,    0
    subsprite OAM_SIZE_8x8,     -1,    5,  618,    0
    subsprite OAM_SIZE_16x16,  -12,  -22, 1891,    0
    subsprite OAM_SIZE_8x8,    -20,  -14, 1874,    0
    subsprite OAM_SIZE_8x32,   -11,  -20, 1995,    0
  FileDE23_Obj_3784:
    subsprite OAM_SIZE_8x32,   -11,  -34, 1994,    0
    subsprite OAM_SIZE_16x16,   -8,  -11, 1676,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  621,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 1954,    0
    subsprite OAM_SIZE_8x8,    -13,  -32, 1906,    0
    subsprite OAM_SIZE_8x32,    -6,  -29, 1995,    0
  FileDE23_Obj_3790:
    subsprite OAM_SIZE_8x16,   -12,    3, 1225,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -20,  -13, 1194,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -8,  -22, 1275,    0, xflip=1
    subsprite OAM_SIZE_32x8,    -8,  -14, 1179,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -21,  -23, 1230,    0
    subsprite OAM_SIZE_16x16,  -11,  -17,  640,    0
    subsprite OAM_SIZE_8x8,      3,   -9,  644,    0
    subsprite OAM_SIZE_8x8,     -1,   -3,  660,    0
    subsprite OAM_SIZE_8x8,    -19,  -11,  623,    0
  FileDE23_Obj_3799:
    subsprite OAM_SIZE_8x16,   -12,    4, 1225,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -20,  -12, 1194,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -8,  -21, 1275,    0, xflip=1
    subsprite OAM_SIZE_32x8,    -8,  -13, 1179,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -21,  -22, 1262,    0
    subsprite OAM_SIZE_16x16,  -11,  -14,  642,    0
    subsprite OAM_SIZE_8x8,      5,   -4,  644,    0
    subsprite OAM_SIZE_8x8,      1,    2,  660,    0
    subsprite OAM_SIZE_8x16,   -19,  -10,  645,    0
    subsprite OAM_SIZE_8x8,     -8,  -22,  639,    0
  FileDE23_Obj_3809:
    subsprite OAM_SIZE_8x32,   -20,  -33, 2701,    0
    subsprite OAM_SIZE_8x16,   -12,  -25, 2891,    0
    subsprite OAM_SIZE_16x16,   -9,  -11, 1678,    0
    subsprite OAM_SIZE_8x8,     -4,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -19,  646,    0
    subsprite OAM_SIZE_8x8,    -18,   -3,  618,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -30, 1913,    0
    subsprite OAM_SIZE_8x8,    -16,  -33, 1912,    0
  FileDE23_Obj_3817:
    subsprite OAM_SIZE_8x32,   -16,  -34, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -26, 2891,    0
    subsprite OAM_SIZE_16x16,   -8,  -11, 1696,    0
    subsprite OAM_SIZE_16x16,   -7,  -18,  648,    0
    subsprite OAM_SIZE_8x8,      9,   -9,  281,    0
    subsprite OAM_SIZE_16x16,   -7,  -27, 1986,    0
    subsprite OAM_SIZE_16x8,    -7,  -35, 1990,    0
  FileDE23_Obj_3824:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1698,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  650,    0
    subsprite OAM_SIZE_16x16,  -26,  -32, 1252,    0
    subsprite OAM_SIZE_8x16,   -10,  -32, 1254,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,   -3,  -20, 1220,    0
    subsprite OAM_SIZE_8x16,     5,   -4, 1222,    0
  FileDE23_Obj_3832:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1700,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  652,    0
    subsprite OAM_SIZE_16x16,  -26,  -33, 1252,    0
    subsprite OAM_SIZE_8x16,   -10,  -33, 1254,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_16x16,   -3,  -21, 1220,    0
    subsprite OAM_SIZE_8x16,     5,   -5, 1222,    0
  FileDE23_Obj_3841:
    subsprite OAM_SIZE_8x16,   -27,  -21, 1152,    0
    subsprite OAM_SIZE_16x16,  -19,  -29, 1153,    0
    subsprite OAM_SIZE_8x8,    -19,  -13, 1185,    0
    subsprite OAM_SIZE_8x16,    15,  -35, 1131,    0
    subsprite OAM_SIZE_16x16,   -1,  -35, 1129,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1702,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  654,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
  FileDE23_Obj_3853:
    subsprite OAM_SIZE_8x16,   -27,  -22, 1152,    0
    subsprite OAM_SIZE_16x16,  -19,  -30, 1153,    0
    subsprite OAM_SIZE_8x8,    -19,  -14, 1185,    0
    subsprite OAM_SIZE_8x16,    15,  -36, 1131,    0
    subsprite OAM_SIZE_16x16,   -1,  -36, 1129,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1704,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  672,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
  FileDE23_Obj_3865:
    subsprite OAM_SIZE_8x8,     -1,   -8, 1164,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1163,    0
    subsprite OAM_SIZE_16x8,   -19,  -18, 1165,    0
    subsprite OAM_SIZE_8x16,    -7,  -11, 1167,    0
    subsprite OAM_SIZE_8x8,     -7,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -19,  675,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x8,      0,   -3,  697,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  698,    0
    subsprite OAM_SIZE_8x8,    -10,  -13,  297,    0
    subsprite OAM_SIZE_16x16,  -16,  -30, 1900,    0
    subsprite OAM_SIZE_8x8,    -24,  -22, 1898,    0
  FileDE23_Obj_3877:
    subsprite OAM_SIZE_8x8,     -1,   -8, 1164,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1163,    0
    subsprite OAM_SIZE_16x8,   -19,  -18, 1165,    0
    subsprite OAM_SIZE_8x16,    -7,  -11, 1167,    0
    subsprite OAM_SIZE_8x8,     -6,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19,  677,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  683,    0
    subsprite OAM_SIZE_8x8,      2,   -3,  684,    0
    subsprite OAM_SIZE_8x8,      8,   -7,  685,    0
    subsprite OAM_SIZE_16x16,  -16,  -30, 1932,    0
    subsprite OAM_SIZE_8x8,    -24,  -27, 1899,    0
  FileDE23_Obj_3889:
    subsprite OAM_SIZE_8x8,     -1,   -8, 1164,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1163,    0
    subsprite OAM_SIZE_16x8,   -19,  -18, 1165,    0
    subsprite OAM_SIZE_8x16,    -7,  -11, 1167,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  679,    0
    subsprite OAM_SIZE_16x8,    -5,  -27,  700,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  682,    0
    subsprite OAM_SIZE_8x8,      8,   -9,  686,    0
    subsprite OAM_SIZE_8x8,      4,   -3,  702,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  495,    0
    subsprite OAM_SIZE_16x16,  -13,  -31, 1880,    0
    subsprite OAM_SIZE_16x8,   -13,  -39, 1864,    0
  FileDE23_Obj_3901:
    subsprite OAM_SIZE_16x8,   -18,  -17, 1234,    0, xflip=1
    subsprite OAM_SIZE_32x8,   -11,  -12, 1158,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -11,   -4, 1176,    0, xflip=1
    subsprite OAM_SIZE_8x8,      5,   -4, 1175,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -10,  -33, 1162,    0, xflip=1
    subsprite OAM_SIZE_8x8,      5,   -9,  510,    0
    subsprite OAM_SIZE_8x8,      2,  -27,  615,    0
    subsprite OAM_SIZE_16x16,   -8,  -21,  613,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  617,    0
    subsprite OAM_SIZE_16x8,    -4,   -5,  633,    0
    subsprite OAM_SIZE_8x8,      8,  -23,  616,    0
    subsprite OAM_SIZE_16x16,  -20,  -13, 1226,    0
    subsprite OAM_SIZE_8x8,    -12,    3, 1259,    0
  FileDE23_Obj_3914:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1706,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  704,    0
    subsprite OAM_SIZE_8x8,      7,  -24,  687,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1958,    0
    subsprite OAM_SIZE_8x32,    -1,  -26, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x32,     4,  -29, 2759,    0, xflip=1
  FileDE23_Obj_3921:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 1958,    0
    subsprite OAM_SIZE_8x32,    -2,  -24, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x32,     3,  -27, 2759,    0, xflip=1
  FileDE23_Obj_3928:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 1958,    0
    subsprite OAM_SIZE_8x32,    -2,  -23, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x32,     3,  -26, 2759,    0, xflip=1
  FileDE23_Obj_3935:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1710,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  708,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  711,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 1960,    0
    subsprite OAM_SIZE_8x32,    -1,  -23, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x32,     4,  -26, 2759,    0, xflip=1
  FileDE23_Obj_3942:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 1958,    0
    subsprite OAM_SIZE_8x32,    -2,  -24, 2760,    0, xflip=1
    subsprite OAM_SIZE_8x32,     3,  -27, 2759,    0, xflip=1
  FileDE23_Obj_3949:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1728,    0
    subsprite OAM_SIZE_8x8,      2,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  712,    0
    subsprite OAM_SIZE_8x8,    -15,  -20,  703,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1934,    0
  FileDE23_Obj_3956:
    subsprite OAM_SIZE_8x32,   -16,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 1934,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_3964:
    subsprite OAM_SIZE_8x32,   -16,  -29, 2763,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 1934,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_3972:
    subsprite OAM_SIZE_8x32,   -15,  -29, 2763,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1732,    0
    subsprite OAM_SIZE_8x8,     -8,    5, 1339,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 1966,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  716,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  734,    0
  FileDE23_Obj_3979:
    subsprite OAM_SIZE_8x32,   -16,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 1934,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_3987:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1734,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  736,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  719,    0
    subsprite OAM_SIZE_16x16,   -7,  -37, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -29, 1890,    0
    subsprite OAM_SIZE_8x32,   -10,  -31, 2759,    0
    subsprite OAM_SIZE_8x32,    -4,  -28, 2760,    0
  FileDE23_Obj_3995:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -38, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1890,    0
    subsprite OAM_SIZE_16x32,   -6,  -30, 2757,    0
  FileDE23_Obj_4003:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -38, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1890,    0
    subsprite OAM_SIZE_16x32,   -6,  -29, 2757,    0
  FileDE23_Obj_4011:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1738,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  740,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  743,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -37, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -32, 1858,    0
    subsprite OAM_SIZE_16x32,   -7,  -29, 2757,    0
  FileDE23_Obj_4019:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -38, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -30, 1890,    0
    subsprite OAM_SIZE_16x32,   -6,  -29, 2757,    0
  FileDE23_Obj_4027:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,     3,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -2,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4033:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -1,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4038:
    subsprite OAM_SIZE_8x8,     -2,  -35, 3040,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4045:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 2757,    0
    subsprite OAM_SIZE_8x32,    -3,  -27, 2758,    0
  FileDE23_Obj_4052:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  871,    0
    subsprite OAM_SIZE_8x8,      2,  -26, 3056,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -2,  -27, 2758,    0
    subsprite OAM_SIZE_8x32,   -10,  -27, 2757,    0
  FileDE23_Obj_4059:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
    subsprite OAM_SIZE_8x8,      6,  -29, 3041,    0
  FileDE23_Obj_4067:
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1862,    0
    subsprite OAM_SIZE_8x8,    -16,  -36, 1861,    0
    subsprite OAM_SIZE_8x32,    -8,  -27, 2760,    0
  FileDE23_Obj_4073:
    subsprite OAM_SIZE_8x32,   -12,  -30, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  878,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_8x8,      2,  -21, 3056,    0
  FileDE23_Obj_4080:
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x32,    -6,  -27, 2760,    0
    subsprite OAM_SIZE_8x8,      8,  -21, 3042,    0
  FileDE23_Obj_4088:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4096:
    subsprite OAM_SIZE_8x32,   -14,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  902,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_8x32,   -15,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2905,    0
    subsprite OAM_SIZE_8x8,     -2,  -19, 3057,    0, xflip=1
  FileDE23_Obj_4105:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x8,      5,  -14, 3043,    0
  FileDE23_Obj_4116:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
  FileDE23_Obj_4124:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  908,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 3057,    0, xflip=1
  FileDE23_Obj_4132:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x8,     -4,  -10, 3044,    0
  FileDE23_Obj_4141:
    subsprite OAM_SIZE_8x16,     2,  -36, 1740,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,     3,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -2,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4148:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -4,  -41, 1740,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4155:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -4,  -40, 1740,    0
    subsprite OAM_SIZE_8x16,    -3,  -33,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4162:
    subsprite OAM_SIZE_16x16,    2,  -30, 1742,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,    -3,  -27, 2758,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 2757,    0
  FileDE23_Obj_4170:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    1,  -38, 1742,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
  FileDE23_Obj_4178:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    0,  -37, 1742,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     0,  -30,  875,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
  FileDE23_Obj_4186:
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_8x8,    -16,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1862,    0
    subsprite OAM_SIZE_8x32,    -8,  -27, 2760,    0
    subsprite OAM_SIZE_16x16,    0,  -23, 1760,    0
  FileDE23_Obj_4193:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,    5,  -29, 1760,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
  FileDE23_Obj_4201:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,    4,  -29, 1760,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_16x8,    -1,  -19,  898,    0
  FileDE23_Obj_4209:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 1762,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
  FileDE23_Obj_4218:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,    1,  -19, 1762,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
  FileDE23_Obj_4229:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  915,    0
    subsprite OAM_SIZE_16x16,    0,  -20, 1762,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  914,    0
  FileDE23_Obj_4240:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 1741,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
  FileDE23_Obj_4249:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x16,    -4,  -16, 1741,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_4258:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -19,  929,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 1741,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_4267:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,     2,  -32,  744,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  845,    0
    subsprite OAM_SIZE_8x8,      3,  -27,  764,    0
    subsprite OAM_SIZE_8x8,    -15,  -13,  847,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,     3,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -2,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4275:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -37,  744,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4282:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -36,  744,    0
    subsprite OAM_SIZE_8x16,    -3,  -33,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_4289:
    subsprite OAM_SIZE_16x16,    1,  -25,  746,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -10,  -26,  869,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_8x8,      4,  -20,  765,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 2757,    0
    subsprite OAM_SIZE_8x32,    -3,  -27, 2758,    0
  FileDE23_Obj_4298:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    1,  -32,  746,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x8,      4,  -27,  765,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
  FileDE23_Obj_4307:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    0,  -31,  746,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     0,  -30,  875,    0
    subsprite OAM_SIZE_8x8,      3,  -26,  765,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
  FileDE23_Obj_4316:
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  876,    0
    subsprite OAM_SIZE_16x8,     0,  -15,  748,    0
    subsprite OAM_SIZE_8x8,    -16,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1862,    0
    subsprite OAM_SIZE_8x32,    -8,  -27, 2760,    0
  FileDE23_Obj_4323:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_16x8,     5,  -21,  748,    0
  FileDE23_Obj_4331:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_16x8,    -1,  -19,  898,    0
    subsprite OAM_SIZE_16x8,     4,  -21,  748,    0
  FileDE23_Obj_4339:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  900,    0
    subsprite OAM_SIZE_16x16,   -8,  -16,  750,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4348:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,   -1,  -16,  750,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
  FileDE23_Obj_4359:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  915,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  914,    0
    subsprite OAM_SIZE_16x16,   -2,  -17,  750,    0
  FileDE23_Obj_4370:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  906,    0
    subsprite OAM_SIZE_8x8,      7,  -17,  928,    0
    subsprite OAM_SIZE_8x16,   -10,  -17,  745,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
  FileDE23_Obj_4379:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x16,    -5,  -13,  745,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_4388:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -19,  929,    0
    subsprite OAM_SIZE_8x16,    -5,  -14,  745,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_4397:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1792,    0
    subsprite OAM_SIZE_8x8,      2,    2, 1838,    0
    subsprite OAM_SIZE_16x16,  -11,  -27,  768,    0
    subsprite OAM_SIZE_8x8,     -2,  -35,  840,    0
    subsprite OAM_SIZE_16x8,   -15,  -27, 2576,    0
    subsprite OAM_SIZE_8x8,    -23,  -21, 2560,    0
    subsprite OAM_SIZE_8x8,    -15,  -19, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1856,    0
    subsprite OAM_SIZE_8x32,     1,  -28, 2758,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2757,    0
  FileDE23_Obj_4407:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1792,    0
    subsprite OAM_SIZE_8x8,      2,    2, 1838,    0
    subsprite OAM_SIZE_16x16,  -11,  -27,  768,    0
    subsprite OAM_SIZE_8x8,     -2,  -35,  840,    0
    subsprite OAM_SIZE_16x8,   -14,  -28, 2576,    0
    subsprite OAM_SIZE_8x8,    -22,  -22, 2560,    0
    subsprite OAM_SIZE_8x8,    -14,  -20, 1293,    0
    subsprite OAM_SIZE_8x8,     -2,  -24,  856,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_8x32,     1,  -28, 2758,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2757,    0
  FileDE23_Obj_4418:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  770,    0
    subsprite OAM_SIZE_16x8,   -28,  -27, 2562,    0
    subsprite OAM_SIZE_16x8,   -12,  -29, 2578,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,     1,  -27, 2758,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2757,    0
  FileDE23_Obj_4425:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  772,    0
    subsprite OAM_SIZE_8x8,    -15,  -19,  841,    0
    subsprite OAM_SIZE_32x16,  -24,  -49, 2570,    0
    subsprite OAM_SIZE_16x32,    8,  -48, 2574,    0
    subsprite OAM_SIZE_8x8,    -10,  -33, 2604,    0
    subsprite OAM_SIZE_8x8,      0,  -33, 2605,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,    -9,  -28, 2757,    0
    subsprite OAM_SIZE_8x32,    -2,  -26, 2758,    0
  FileDE23_Obj_4435:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  774,    0
    subsprite OAM_SIZE_8x8,    -19,  -19,  857,    0
    subsprite OAM_SIZE_8x8,      2,  -19, 2564,    0
    subsprite OAM_SIZE_8x8,      5,  -11, 2580,    0
    subsprite OAM_SIZE_16x8,    13,   -9, 2706,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
    subsprite OAM_SIZE_8x32,    -6,  -26, 2760,    0
  FileDE23_Obj_4445:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  774,    0
    subsprite OAM_SIZE_8x8,    -19,  -19,  857,    0
    subsprite OAM_SIZE_8x8,      1,  -20, 2564,    0
    subsprite OAM_SIZE_8x8,      4,  -12, 2580,    0
    subsprite OAM_SIZE_16x8,    12,  -10, 2706,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
  FileDE23_Obj_4455:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1798,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  776,    0
    subsprite OAM_SIZE_16x8,   -25,  -33, 2565,    0
    subsprite OAM_SIZE_16x8,    -9,  -31, 2581,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 2561,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -15,  -30, 1858,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_4465:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1798,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  776,    0
    subsprite OAM_SIZE_16x8,   -24,  -33, 2565,    0
    subsprite OAM_SIZE_16x8,    -8,  -31, 2581,    0
    subsprite OAM_SIZE_8x8,      0,  -23, 2561,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_4475:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  778,    0
    subsprite OAM_SIZE_8x8,     -2,  -34,  842,    0
    subsprite OAM_SIZE_16x8,   -16,  -42, 2567,    0
    subsprite OAM_SIZE_16x8,    -9,  -34, 2583,    0
    subsprite OAM_SIZE_8x16,     2,  -26, 2569,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -15,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,   -12,  -28, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
  FileDE23_Obj_4485:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  780,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_32x8,     1,  -19, 2656,    0
    subsprite OAM_SIZE_32x32,    0,  -51, 2592,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x32,    -8,  -26, 2760,    0
  FileDE23_Obj_4494:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_8x8,     -1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  782,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 2596,    0
    subsprite OAM_SIZE_8x16,     4,   -2, 2597,    0
    subsprite OAM_SIZE_8x8,     -4,   -1, 2621,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
  FileDE23_Obj_4507:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_8x8,     -1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  782,    0
    subsprite OAM_SIZE_8x8,     -9,  -34,  858,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2596,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -34, 2761,    0
    subsprite OAM_SIZE_8x16,     4,   -3, 2597,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2621,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x32,   -13,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -5,  -21, 2905,    0
  FileDE23_Obj_4520:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1804,    0
    subsprite OAM_SIZE_8x8,     -3,    2, 1854,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  800,    0
    subsprite OAM_SIZE_8x8,     -6,  -46, 2628,    0
    subsprite OAM_SIZE_8x8,     -4,  -39, 2644,    0
    subsprite OAM_SIZE_8x16,    -1,  -31, 2629,    0
    subsprite OAM_SIZE_8x8,    -15,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1862,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4532:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1804,    0
    subsprite OAM_SIZE_8x8,     -3,    2, 1854,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  800,    0
    subsprite OAM_SIZE_8x8,     -5,  -45, 2628,    0
    subsprite OAM_SIZE_8x8,     -3,  -38, 2644,    0
    subsprite OAM_SIZE_8x16,     0,  -30, 2629,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4544:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  802,    0
    subsprite OAM_SIZE_8x16,     3,  -29, 2630,    0
    subsprite OAM_SIZE_8x16,     2,  -45, 2598,    0
    subsprite OAM_SIZE_8x8,     -5,  -17, 2599,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1862,    0
    subsprite OAM_SIZE_8x8,    -15,  -35, 1861,    0
    subsprite OAM_SIZE_8x32,   -15,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2905,    0
  FileDE23_Obj_4555:
    subsprite OAM_SIZE_8x8,     -5,  -26, 2889,    0
    subsprite OAM_SIZE_8x32,   -13,  -34, 2761,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  804,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x8,     -1,  -17, 2615,    0
    subsprite OAM_SIZE_32x16,   -1,   -9, 2662,    0
    subsprite OAM_SIZE_16x32,   16,  -41, 2600,    0
    subsprite OAM_SIZE_8x8,      8,  -27, 2631,    0
    subsprite OAM_SIZE_8x8,      8,  -17, 2647,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1924,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4569:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_8x8,    -15,  -13, 2194,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  806,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x8,     -5,  -17, 2603,    0
    subsprite OAM_SIZE_8x16,   -15,   -5, 2674,    0
    subsprite OAM_SIZE_8x16,   -13,  -21, 2602,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1924,    0
  FileDE23_Obj_4580:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  806,    0
    subsprite OAM_SIZE_8x8,     -1,  -34,  843,    0
    subsprite OAM_SIZE_8x16,   -12,  -22, 2602,    0
    subsprite OAM_SIZE_8x8,     -4,  -18, 2603,    0
    subsprite OAM_SIZE_8x16,   -14,   -6, 2674,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1924,    0
  FileDE23_Obj_4590:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1826,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  808,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2619,    0
    subsprite OAM_SIZE_8x16,     3,  -31, 2671,    0
    subsprite OAM_SIZE_8x16,     7,  -47, 2639,    0
    subsprite OAM_SIZE_16x8,    -7,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1880,    0
  FileDE23_Obj_4600:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1826,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -27,  808,    0
    subsprite OAM_SIZE_8x8,     -5,  -19, 2619,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2671,    0
    subsprite OAM_SIZE_8x16,     7,  -46, 2639,    0
    subsprite OAM_SIZE_8x8,     -8,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1926,    0
  FileDE23_Obj_4610:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2890,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 2196,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  810,    0
    subsprite OAM_SIZE_8x8,     11,  -17,  859,    0
    subsprite OAM_SIZE_16x8,    -4,  -18, 2619,    0
    subsprite OAM_SIZE_8x16,     8,  -27, 2660,    0
    subsprite OAM_SIZE_8x16,    16,  -34, 2661,    0
    subsprite OAM_SIZE_16x8,    -7,  -41, 1864,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1880,    0
  FileDE23_Obj_4621:
    subsprite OAM_SIZE_8x32,   -13,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -25, 2890,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 2196,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  812,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 2716,    0
    subsprite OAM_SIZE_8x32,    -6,  -16, 2634,    0
    subsprite OAM_SIZE_32x32,    2,  -17, 2635,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1926,    0
  FileDE23_Obj_4632:
    subsprite OAM_SIZE_8x32,   -10,  -34, 2764,    0
    subsprite OAM_SIZE_8x32,    -3,  -36, 2765,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  814,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_16x8,   -20,  -21, 2699,    0
    subsprite OAM_SIZE_16x8,   -28,  -13, 2803,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1926,    0
  FileDE23_Obj_4641:
    subsprite OAM_SIZE_8x32,   -10,  -35, 2764,    0
    subsprite OAM_SIZE_8x32,    -2,  -36, 2765,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -5,  -26,  814,    0
    subsprite OAM_SIZE_8x8,     11,  -25,  844,    0
    subsprite OAM_SIZE_16x8,   -19,  -21, 2699,    0
    subsprite OAM_SIZE_16x8,   -27,  -13, 2803,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1926,    0
  FileDE23_Obj_4650:
    subsprite OAM_SIZE_8x32,    -1,  -38, 2765,    0
    subsprite OAM_SIZE_8x32,    -9,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1832,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  832,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
    subsprite OAM_SIZE_16x8,    -5,  -22, 2691,    0
    subsprite OAM_SIZE_16x8,    11,  -27, 2693,    0
  FileDE23_Obj_4659:
    subsprite OAM_SIZE_8x32,    -1,  -38, 2765,    0
    subsprite OAM_SIZE_8x32,    -9,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1832,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  832,    0
    subsprite OAM_SIZE_16x8,    -6,  -21, 2691,    0
    subsprite OAM_SIZE_16x8,    10,  -26, 2693,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_4668:
    subsprite OAM_SIZE_8x32,    -1,  -37, 2765,    0
    subsprite OAM_SIZE_8x32,    -9,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -22,  834,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 2675,    0
    subsprite OAM_SIZE_16x8,    -4,  -15, 2695,    0
    subsprite OAM_SIZE_16x8,    12,  -17, 2562,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
  FileDE23_Obj_4678:
    subsprite OAM_SIZE_8x32,     1,  -35, 2765,    0
    subsprite OAM_SIZE_8x32,    -6,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  836,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_16x32,  -24,  -18, 2672,    0
    subsprite OAM_SIZE_32x16,   -8,   -1, 2570,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -8,   -9, 2605,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,      2,   -9, 2604,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_4690:
    subsprite OAM_SIZE_8x32,     6,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -2,  -24, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 2698,    0
    subsprite OAM_SIZE_8x8,    -13,  -31, 2697,    0
    subsprite OAM_SIZE_16x8,   -29,  -33, 2706,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -22,  838,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_4701:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -24, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_8x8,     -7,  -22, 2698,    0
    subsprite OAM_SIZE_8x8,    -12,  -30, 2697,    0
    subsprite OAM_SIZE_16x8,   -28,  -32, 2706,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -22,  838,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  860,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_4712:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  930,    0
    subsprite OAM_SIZE_8x32,     1,  -27, 2736,    0
    subsprite OAM_SIZE_8x16,     1,  -43, 2708,    0
    subsprite OAM_SIZE_8x8,      3,  -15,  944,    0
    subsprite OAM_SIZE_8x16,    -1,  -17,  932,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1856,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
  FileDE23_Obj_4722:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  930,    0
    subsprite OAM_SIZE_8x32,     1,  -28, 2736,    0
    subsprite OAM_SIZE_8x16,     1,  -44, 2708,    0
    subsprite OAM_SIZE_8x8,      3,  -16,  944,    0
    subsprite OAM_SIZE_8x16,    -1,  -18,  932,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1920,    0
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_4732:
    subsprite OAM_SIZE_8x32,    -1,  -41, 2736,    0
    subsprite OAM_SIZE_8x8,      1,  -49, 2723,    0
    subsprite OAM_SIZE_8x16,    -1,  -65, 2709,    0
    subsprite OAM_SIZE_8x8,     -9,  -54, 2722,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,     -1,  -30,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
    subsprite OAM_SIZE_8x32,    -5,  -27, 2760,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  949,    0
  FileDE23_Obj_4743:
    subsprite OAM_SIZE_8x32,    -1,  -40, 2736,    0
    subsprite OAM_SIZE_8x16,    -1,  -56, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,     -1,  -29,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,    -5,  -27, 2760,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
    subsprite OAM_SIZE_8x8,      2,  -19,  949,    0
  FileDE23_Obj_4752:
    subsprite OAM_SIZE_8x32,    -3,  -53, 2736,    0
    subsprite OAM_SIZE_8x8,     -1,  -61, 2723,    0
    subsprite OAM_SIZE_8x16,    -3,  -77, 2709,    0
    subsprite OAM_SIZE_8x8,    -11,  -66, 2722,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -5,  -32,  934,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x16,     0,  -24,  935,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,    -4,  -27, 2760,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
  FileDE23_Obj_4763:
    subsprite OAM_SIZE_8x32,    -3,  -52, 2736,    0
    subsprite OAM_SIZE_8x16,    -3,  -68, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -5,  -31,  934,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x16,     0,  -23,  935,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,    -5,  -27, 2760,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
  FileDE23_Obj_4772:
    subsprite OAM_SIZE_8x32,    -1,  -40, 2736,    0
    subsprite OAM_SIZE_8x16,    -1,  -56, 2708,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1796,    0
    subsprite OAM_SIZE_16x16,   -9,  -22,  930,    0
    subsprite OAM_SIZE_8x8,      2,  -19,  949,    0
    subsprite OAM_SIZE_8x8,     -1,  -29,  933,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,    -6,  -27, 2760,    0
    subsprite OAM_SIZE_8x32,   -11,  -31, 2759,    0
  FileDE23_Obj_4781:
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -2,  -23,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_16x16,  -10,  -13, 2710,    0
    subsprite OAM_SIZE_8x8,      3,  -18, 2711,    0
    subsprite OAM_SIZE_16x16,    8,  -31, 2712,    0
    subsprite OAM_SIZE_8x8,     -2,  -15,  957,    0
    subsprite OAM_SIZE_8x16,    -7,  -17,  940,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -30, 1858,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4796:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 2710,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 2711,    0
    subsprite OAM_SIZE_16x16,    9,  -32, 2712,    0
    subsprite OAM_SIZE_8x8,     -1,  -16,  957,    0
    subsprite OAM_SIZE_8x16,    -6,  -18,  940,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_4811:
    subsprite OAM_SIZE_8x32,   -14,  -31, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -2,  -25, 2710,    0
    subsprite OAM_SIZE_8x8,     12,  -31, 2711,    0
    subsprite OAM_SIZE_8x8,     16,  -35, 2711,    0
    subsprite OAM_SIZE_8x8,     29,  -36,  297,    0
    subsprite OAM_SIZE_16x16,   22,  -49, 2714,    0
    subsprite OAM_SIZE_8x8,      5,  -20,  942,    0
    subsprite OAM_SIZE_8x8,     -1,  -18,  958,    0
    subsprite OAM_SIZE_8x8,    -15,  -29, 1858,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1859,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
  FileDE23_Obj_4826:
    subsprite OAM_SIZE_8x32,   -14,  -31, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -3,  -24, 2710,    0
    subsprite OAM_SIZE_8x8,     10,  -29, 2711,    0
    subsprite OAM_SIZE_16x16,   15,  -42, 2712,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  942,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
  FileDE23_Obj_4839:
    subsprite OAM_SIZE_8x32,   -13,  -31, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    5,  -36, 2710,    0
    subsprite OAM_SIZE_8x8,     19,  -42, 2711,    0
    subsprite OAM_SIZE_8x8,     23,  -46, 2711,    0
    subsprite OAM_SIZE_8x8,     36,  -47,  297,    0
    subsprite OAM_SIZE_16x16,   29,  -60, 2714,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  938,    0
    subsprite OAM_SIZE_8x8,      8,  -29,  943,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  959,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1858,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,     -3,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -11,  -28, 2762,    0
  FileDE23_Obj_4854:
    subsprite OAM_SIZE_8x32,   -13,  -31, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    4,  -35, 2710,    0
    subsprite OAM_SIZE_8x8,     17,  -40, 2711,    0
    subsprite OAM_SIZE_16x16,   22,  -53, 2712,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  938,    0
    subsprite OAM_SIZE_8x8,      7,  -28,  943,    0
    subsprite OAM_SIZE_8x8,      1,  -19,  959,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -4,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -12,  -28, 2762,    0
  FileDE23_Obj_4867:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -3,  -24, 2710,    0
    subsprite OAM_SIZE_8x8,     10,  -29, 2711,    0
    subsprite OAM_SIZE_16x16,   15,  -42, 2712,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  942,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
  FileDE23_Obj_4880:
    subsprite OAM_SIZE_8x32,   -15,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -26, 2890,    0
    subsprite OAM_SIZE_8x8,    -15,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -20,  -14, 2741,    0
    subsprite OAM_SIZE_16x8,    12,  -14, 2745,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  981,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  965,    0
    subsprite OAM_SIZE_8x8,    -16,  -37, 1861,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1862,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,  964,    0
  FileDE23_Obj_4892:
    subsprite OAM_SIZE_8x32,   -15,  -34, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -26, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -19,  -14, 2741,    0
    subsprite OAM_SIZE_16x8,    13,  -14, 2745,    0
    subsprite OAM_SIZE_8x16,   -10,  -21,  964,    0
    subsprite OAM_SIZE_8x8,     -2,  -13,  981,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  965,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 1893,    0
  FileDE23_Obj_4903:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -6,  -16, 2741,    0
    subsprite OAM_SIZE_8x8,     26,  -16, 2747,    0
    subsprite OAM_SIZE_8x16,    34,  -18, 2732,    0
    subsprite OAM_SIZE_8x8,     42,  -16, 2800,    0
    subsprite OAM_SIZE_8x8,     -6,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     1,  -21,  967,    0
    subsprite OAM_SIZE_8x8,    -15,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1862,    0
  FileDE23_Obj_4915:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -7,  -16, 2741,    0
    subsprite OAM_SIZE_16x8,    25,  -16, 2745,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  967,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
  FileDE23_Obj_4925:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  962,    0
    subsprite OAM_SIZE_32x8,     6,  -18, 2741,    0
    subsprite OAM_SIZE_8x8,     38,  -18, 2747,    0
    subsprite OAM_SIZE_8x16,    46,  -20, 2732,    0
    subsprite OAM_SIZE_8x8,     54,  -18, 2800,    0
    subsprite OAM_SIZE_16x8,     6,  -21,  984,    0
    subsprite OAM_SIZE_16x8,    -3,  -18,  968,    0
    subsprite OAM_SIZE_8x8,    -14,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1862,    0
  FileDE23_Obj_4937:
    subsprite OAM_SIZE_8x32,   -13,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  962,    0
    subsprite OAM_SIZE_32x8,     5,  -18, 2741,    0
    subsprite OAM_SIZE_16x8,    37,  -18, 2745,    0
    subsprite OAM_SIZE_16x8,     5,  -21,  984,    0
    subsprite OAM_SIZE_16x8,    -4,  -18,  968,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 1893,    0
  FileDE23_Obj_4947:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1824,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_32x8,    -7,  -16, 2741,    0
    subsprite OAM_SIZE_16x8,    25,  -16, 2745,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  966,    0
    subsprite OAM_SIZE_8x16,     0,  -21,  967,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
  FileDE23_Obj_4957:
    subsprite OAM_SIZE_8x32,     0,  -33, 2765,    0
    subsprite OAM_SIZE_8x32,    -7,  -34, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_16x16,  -18,  -25, 2737,    0
    subsprite OAM_SIZE_8x8,     -5,  -12, 2754,    0
    subsprite OAM_SIZE_16x16,    0,   -7, 2769,    0
    subsprite OAM_SIZE_8x8,    -12,  -25,  982,    0
    subsprite OAM_SIZE_8x8,    -10,  -15,  974,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  975,    0
    subsprite OAM_SIZE_16x8,    -8,  -43, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1880,    0
  FileDE23_Obj_4970:
    subsprite OAM_SIZE_8x32,     0,  -33, 2765,    0
    subsprite OAM_SIZE_8x32,    -7,  -34, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_16x16,  -17,  -24, 2737,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 2754,    0
    subsprite OAM_SIZE_16x16,    1,   -6, 2769,    0
    subsprite OAM_SIZE_8x8,    -11,  -24,  982,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  974,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  975,    0
    subsprite OAM_SIZE_8x8,     -9,  -43, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1926,    0
  FileDE23_Obj_4983:
    subsprite OAM_SIZE_8x32,    -8,  -32, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -6,  -17, 2737,    0
    subsprite OAM_SIZE_8x8,      8,   -3, 2754,    0
    subsprite OAM_SIZE_8x8,     12,    1, 2754,    0
    subsprite OAM_SIZE_8x8,     25,    6,  297,    0
    subsprite OAM_SIZE_16x16,   18,    7, 2739,    0
    subsprite OAM_SIZE_8x8,     -7,  -19,  990,    0
    subsprite OAM_SIZE_8x16,     3,  -21,  992,    0
    subsprite OAM_SIZE_16x8,    -7,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1880,    0
  FileDE23_Obj_4995:
    subsprite OAM_SIZE_8x32,    -8,  -32, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 2737,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2754,    0
    subsprite OAM_SIZE_16x16,   11,    0, 2769,    0
    subsprite OAM_SIZE_8x8,      2,  -14, 1008,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  990,    0
    subsprite OAM_SIZE_8x8,     -8,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1926,    0
  FileDE23_Obj_5006:
    subsprite OAM_SIZE_8x32,    -1,  -34, 2765,    0
    subsprite OAM_SIZE_8x32,    -8,  -30, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  972,    0
    subsprite OAM_SIZE_16x16,    5,  -10, 2737,    0
    subsprite OAM_SIZE_8x8,     19,    4, 2754,    0
    subsprite OAM_SIZE_8x8,     23,    8, 2754,    0
    subsprite OAM_SIZE_8x8,     36,   13,  297,    0
    subsprite OAM_SIZE_16x16,   29,   14, 2739,    0
    subsprite OAM_SIZE_8x8,     -5,  -18,  993,    0
    subsprite OAM_SIZE_8x8,      3,  -12, 1009,    0
    subsprite OAM_SIZE_8x16,     5,  -18,  994,    0
    subsprite OAM_SIZE_16x8,    -6,  -41, 1864,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 1880,    0
  FileDE23_Obj_5020:
    subsprite OAM_SIZE_8x32,    -8,  -31, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,      4,  -19,  994,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  972,    0
    subsprite OAM_SIZE_16x16,    4,  -11, 2737,    0
    subsprite OAM_SIZE_8x8,     17,    2, 2754,    0
    subsprite OAM_SIZE_16x16,   22,    7, 2769,    0
    subsprite OAM_SIZE_8x8,     -6,  -19,  993,    0
    subsprite OAM_SIZE_8x8,      2,  -13, 1009,    0
    subsprite OAM_SIZE_8x8,      4,  -11, 1010,    0
    subsprite OAM_SIZE_8x8,     -7,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1926,    0
  FileDE23_Obj_5032:
    subsprite OAM_SIZE_8x32,    -8,  -32, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 2737,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2754,    0
    subsprite OAM_SIZE_16x16,   11,    0, 2769,    0
    subsprite OAM_SIZE_8x8,      2,  -14, 1008,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  990,    0
    subsprite OAM_SIZE_8x8,     -8,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1926,    0
  FileDE23_Obj_5043:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -24, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_8x32,    -8,  -35, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -8,   -3, 2772,    0
    subsprite OAM_SIZE_8x8,     -6,  -28,  991,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -20,  999,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1866,    0
    subsprite OAM_SIZE_8x8,     -3,  -43, 1855,    0
  FileDE23_Obj_5054:
    subsprite OAM_SIZE_8x32,     7,  -32, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -24, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_8x32,    -8,  -34, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -8,   -2, 2772,    0
    subsprite OAM_SIZE_8x8,     -6,  -27,  991,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -19,  999,    0
    subsprite OAM_SIZE_8x8,      0,  -43, 1261,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1870,    0
  FileDE23_Obj_5065:
    subsprite OAM_SIZE_8x32,     6,  -33, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -2,  -25, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -21, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -4,   11, 2801,    0
    subsprite OAM_SIZE_8x8,    -14,   21, 2802,    0
    subsprite OAM_SIZE_8x16,    -6,   19, 2771,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -16, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -8, 1017,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -41, 1855,    0
  FileDE23_Obj_5079:
    subsprite OAM_SIZE_8x32,     6,  -33, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -2,  -25, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -22, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -9, 1017,    0
    subsprite OAM_SIZE_8x16,    -6,   10, 2772,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_5091:
    subsprite OAM_SIZE_8x32,     5,  -33, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -3,  -25, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  997,    0
    subsprite OAM_SIZE_8x32,    -4,   -9, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -2,   23, 2801,    0
    subsprite OAM_SIZE_8x8,    -12,   33, 2802,    0
    subsprite OAM_SIZE_8x16,    -4,   31, 2771,    0
    subsprite OAM_SIZE_8x16,    -7,  -20, 1002,    0
    subsprite OAM_SIZE_8x16,    -1,  -14, 1003,    0
    subsprite OAM_SIZE_16x16,   -8,  -32, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -40, 1855,    0
  FileDE23_Obj_5104:
    subsprite OAM_SIZE_8x32,     5,  -34, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -3,  -26, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -21,  997,    0
    subsprite OAM_SIZE_8x32,    -4,  -10, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -4,   22, 2772,    0
    subsprite OAM_SIZE_8x16,    -7,  -21, 1002,    0
    subsprite OAM_SIZE_8x16,    -1,  -15, 1003,    0
    subsprite OAM_SIZE_8x8,     -1,  -40, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 1870,    0
  FileDE23_Obj_5115:
    subsprite OAM_SIZE_8x32,     5,  -35, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -3,  -27, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1836,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  995,    0
    subsprite OAM_SIZE_8x32,    -6,  -22, 2736,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1015,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1001,    0
    subsprite OAM_SIZE_8x8,     -3,   -9, 1017,    0
    subsprite OAM_SIZE_8x16,    -6,   10, 2772,    0
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
  FileDE23_Obj_5127:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2826,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1040,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -30, 1024,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -27, 2757,    0
  FileDE23_Obj_5136:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -26, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_16x32,   -8,  -26, 2757,    0
  FileDE23_Obj_5144:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -26, 2757,    0
  FileDE23_Obj_5152:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -8,  -31, 1027,    0
    subsprite OAM_SIZE_8x16,     0,  -31, 1027,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -26, 2757,    0
    subsprite OAM_SIZE_16x16,   -5,  -38, 2854,    0
  FileDE23_Obj_5159:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -8,  -32, 1027,    0
    subsprite OAM_SIZE_8x16,     0,  -32, 1027,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -26, 2757,    0
    subsprite OAM_SIZE_16x16,   -5,  -39, 2854,    0
  FileDE23_Obj_5166:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -27, 2757,    0
  FileDE23_Obj_5174:
    subsprite OAM_SIZE_16x16,   -5,  -47, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -31, 2826,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1040,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -30, 1024,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1888,    0
    subsprite OAM_SIZE_16x32,   -8,  -28, 2757,    0
  FileDE23_Obj_5183:
    subsprite OAM_SIZE_16x16,   -5,  -36, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -20, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -21, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -21, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
  FileDE23_Obj_5192:
    subsprite OAM_SIZE_16x16,   -5,  -37, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -21, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -22, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -22, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
  FileDE23_Obj_5201:
    subsprite OAM_SIZE_16x16,   -5,  -36, 2856,    0
    subsprite OAM_SIZE_8x8,     -2,  -20, 2842,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1006,    0
    subsprite OAM_SIZE_8x8,    -12,  -21, 1041,    0
    subsprite OAM_SIZE_8x8,      4,  -21, 1041,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -29, 2757,    0
  FileDE23_Obj_5210:
    subsprite OAM_SIZE_16x16,   -5,  -48, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -32, 2818,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1025,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 1026,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_16x32,   -8,  -28, 2757,    0
  FileDE23_Obj_5218:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_8x32,   -12,  -30, 2759,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x8,    -5,  -24, 1034,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1028,    0
    subsprite OAM_SIZE_8x16,     1,  -25, 1036,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_5229:
    subsprite OAM_SIZE_16x16,   -5,  -45, 2819,    0
    subsprite OAM_SIZE_8x16,     1,  -29, 2821,    0
    subsprite OAM_SIZE_16x8,    -7,  -22, 1050,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,     -1,  -26, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
    subsprite OAM_SIZE_8x8,     -1,  -18, 1053,    0
  FileDE23_Obj_5240:
    subsprite OAM_SIZE_16x16,   -4,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     2,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -23, 1050,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,      0,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
    subsprite OAM_SIZE_8x8,      0,  -19, 1053,    0
  FileDE23_Obj_5251:
    subsprite OAM_SIZE_8x8,     -7,  -24, 1038,    0
    subsprite OAM_SIZE_8x8,      1,  -28, 1054,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_16x16,  -12,  -39, 2852,    0, xflip=1
    subsprite OAM_SIZE_8x8,      4,  -29, 2831,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -23, 1292,    0
    subsprite OAM_SIZE_8x8,      2,  -29,  548,    0
    subsprite OAM_SIZE_8x32,    -8,  -25, 2760,    0
    subsprite OAM_SIZE_8x16,    -1,  -28, 1039,    0
  FileDE23_Obj_5264:
    subsprite OAM_SIZE_8x8,     -6,  -25, 1038,    0
    subsprite OAM_SIZE_8x8,      2,  -29, 1054,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x32,   -13,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,  -11,  -40, 2852,    0, xflip=1
    subsprite OAM_SIZE_8x8,      5,  -30, 2831,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -7,  -24, 1292,    0
    subsprite OAM_SIZE_8x16,     0,  -29, 1039,    0
    subsprite OAM_SIZE_8x8,      3,  -30,  548,    0
    subsprite OAM_SIZE_8x32,    -8,  -26, 2760,    0
  FileDE23_Obj_5277:
    subsprite OAM_SIZE_16x16,   -3,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -5,  -23, 1050,    0
    subsprite OAM_SIZE_8x8,      1,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 1053,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
  FileDE23_Obj_5288:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
    subsprite OAM_SIZE_16x8,    -4,  -24, 1056,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1030,    0
    subsprite OAM_SIZE_8x16,     2,  -25, 1058,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1891,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1874,    0
    subsprite OAM_SIZE_8x32,    -6,  -27, 2760,    0
  FileDE23_Obj_5299:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -23, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -18, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 2858,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -18, 1073,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -14,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,    -6,  -26, 2760,    0
  FileDE23_Obj_5311:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -29, 2858,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,     -2,  -18, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -19, 1073,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -6,  -26, 2760,    0
  FileDE23_Obj_5323:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -4,  -23, 1072,    0
    subsprite OAM_SIZE_8x8,      4,  -18, 1051,    0
    subsprite OAM_SIZE_16x16,    6,  -28, 2858,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 2847,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1032,    0
    subsprite OAM_SIZE_8x8,      2,  -18, 1073,    0
    subsprite OAM_SIZE_16x16,   -6,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -6,  -26, 2760,    0
  FileDE23_Obj_5335:
    subsprite OAM_SIZE_16x16,    2,  -28, 2827,    0
    subsprite OAM_SIZE_16x16,    4,  -44, 2829,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x8,    -4,  -24, 1056,    0
    subsprite OAM_SIZE_8x32,   -11,  -30, 2759,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1030,    0
    subsprite OAM_SIZE_8x16,     2,  -25, 1058,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,    -6,  -27, 2760,    0
  FileDE23_Obj_5346:
    subsprite OAM_SIZE_16x16,   -3,  -46, 2819,    0
    subsprite OAM_SIZE_8x16,     3,  -30, 2821,    0
    subsprite OAM_SIZE_16x8,    -5,  -23, 1050,    0
    subsprite OAM_SIZE_8x8,      1,  -27, 1037,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_8x32,   -11,  -29, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1028,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 1053,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -6,  -26, 2760,    0
  FileDE23_Obj_5357:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -3,  -25, 1063,    0
    subsprite OAM_SIZE_8x8,      3,  -17, 1079,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x8,    -3,  -19, 1064,    0
    subsprite OAM_SIZE_8x8,    -15,  -35, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1924,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_5372:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -5,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      3,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1862,    0
    subsprite OAM_SIZE_16x16,   -3,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     3,  -26, 2821,    0
    subsprite OAM_SIZE_8x32,   -15,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2905,    0
    subsprite OAM_SIZE_16x8,    -5,  -21, 1066,    0
  FileDE23_Obj_5385:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -4,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_16x16,   -2,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     4,  -26, 2821,    0
    subsprite OAM_SIZE_16x8,    -4,  -21, 1066,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -15,  -28, 2762,    0
  FileDE23_Obj_5398:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x8,    -5,  -24, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_16x16,  -18,  -41, 2850,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -2,  -29, 2848,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -32, 2716,    0
    subsprite OAM_SIZE_8x8,      5,  -24, 1051,    0
    subsprite OAM_SIZE_8x8,     -7,  -19, 2905,    0
    subsprite OAM_SIZE_8x16,    -5,  -25, 1068,    0
    subsprite OAM_SIZE_8x32,   -15,  -27, 2762,    0
  FileDE23_Obj_5412:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x8,    -4,  -25, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_16x16,  -17,  -42, 2850,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -1,  -30, 2848,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -13,  -33, 2716,    0
    subsprite OAM_SIZE_8x8,      6,  -25, 1051,    0
    subsprite OAM_SIZE_8x16,    -4,  -26, 1068,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -15,  -28, 2762,    0
  FileDE23_Obj_5426:
    subsprite OAM_SIZE_8x32,   -13,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -3,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_16x16,   -1,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     5,  -26, 2821,    0
    subsprite OAM_SIZE_16x8,    -3,  -21, 1066,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
  FileDE23_Obj_5439:
    subsprite OAM_SIZE_8x32,   -12,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -4,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x16,    -2,  -24, 1069,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1059,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x8,    -2,  -18, 1070,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1894,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 1877,    0
    subsprite OAM_SIZE_8x8,     -5,  -21, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -29, 2762,    0
  FileDE23_Obj_5453:
    subsprite OAM_SIZE_8x32,   -12,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -4,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -23, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x8,    -1,  -12, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -12, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 1104,    0
    subsprite OAM_SIZE_8x8,    -13,  -35, 1861,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1862,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
  FileDE23_Obj_5468:
    subsprite OAM_SIZE_8x32,   -12,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -4,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -24, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -16, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x8,    -1,  -13, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -13, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -18, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -12, 1104,    0
    subsprite OAM_SIZE_8x8,    -13,  -33, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1924,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
  FileDE23_Obj_5483:
    subsprite OAM_SIZE_8x32,   -12,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -4,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x8,     -2,  -23, 1086,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1087,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1061,    0
    subsprite OAM_SIZE_16x8,    -1,  -12, 2302,    0
    subsprite OAM_SIZE_16x16,   15,  -12, 2860,    0
    subsprite OAM_SIZE_8x8,     -2,  -17, 1088,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 1104,    0
    subsprite OAM_SIZE_8x8,    -13,  -33, 1893,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 1924,    0
    subsprite OAM_SIZE_8x8,     -5,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
  FileDE23_Obj_5498:
    subsprite OAM_SIZE_8x32,   -13,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_8x16,    -2,  -24, 1069,    0
    subsprite OAM_SIZE_16x16,   -7,  -23, 1059,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2848,    0
    subsprite OAM_SIZE_16x16,   13,  -34, 2850,    0
    subsprite OAM_SIZE_8x8,     22,  -25, 2716,    0
    subsprite OAM_SIZE_16x8,    -2,  -18, 1070,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 1924,    0
    subsprite OAM_SIZE_8x32,   -14,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -21, 2905,    0
  FileDE23_Obj_5512:
    subsprite OAM_SIZE_8x32,   -13,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_8x8,     -3,  -24, 1080,    0
    subsprite OAM_SIZE_8x8,      5,  -19, 1081,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,    -15,  -34, 1893,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 1924,    0
    subsprite OAM_SIZE_16x16,   -1,  -42, 2822,    0
    subsprite OAM_SIZE_8x16,     5,  -26, 2821,    0
    subsprite OAM_SIZE_16x8,    -3,  -21, 1066,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
  FileDE23_Obj_5525:
    subsprite OAM_SIZE_8x32,   -15,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     1,  -24, 1094,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_8x8,     -6,  -21, 1093,    0
    subsprite OAM_SIZE_8x8,     -1,  -13, 1109,    0
    subsprite OAM_SIZE_8x8,     -9,  -43, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1926,    0
  FileDE23_Obj_5538:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,    -1,  -24, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_16x16,   -5,  -39, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     1,  -23, 2821,    0
    subsprite OAM_SIZE_16x8,    -8,  -20, 1095,    0
  FileDE23_Obj_5548:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     0,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_16x16,   -4,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     2,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -7,  -19, 1095,    0
  FileDE23_Obj_5558:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 1111,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_16x16,  -12,  -42, 2829,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -26, 2827,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -9,  -21, 1112,    0
    subsprite OAM_SIZE_8x8,     -1,  -23, 1114,    0
  FileDE23_Obj_5569:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x8,      0,  -24, 1111,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_16x16,  -11,  -43, 2829,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -27, 2827,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -22, 1112,    0
    subsprite OAM_SIZE_8x8,      0,  -24, 1114,    0
  FileDE23_Obj_5580:
    subsprite OAM_SIZE_8x32,   -14,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     1,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_16x16,   -3,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -19, 1095,    0
  FileDE23_Obj_5590:
    subsprite OAM_SIZE_8x32,   -13,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     2,  -22, 1100,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1089,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_16x8,    -5,  -18, 1098,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 1913,    0
    subsprite OAM_SIZE_8x8,    -11,  -36, 1912,    0
  FileDE23_Obj_5602:
    subsprite OAM_SIZE_8x32,   -13,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -21, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x8,    -6,  -40, 1864,    0
    subsprite OAM_SIZE_16x16,   -6,  -32, 1880,    0
    subsprite OAM_SIZE_16x16,    2,  -12, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    4, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -17, 1115,    0
    subsprite OAM_SIZE_8x8,      2,   -9, 1101,    0
  FileDE23_Obj_5614:
    subsprite OAM_SIZE_8x32,   -13,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -22, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x16,    2,  -13, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    3, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -18, 1115,    0
    subsprite OAM_SIZE_8x8,      2,  -10, 1101,    0
    subsprite OAM_SIZE_8x8,     -7,  -40, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 1926,    0
  FileDE23_Obj_5626:
    subsprite OAM_SIZE_8x32,   -13,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -5,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     3,  -21, 1102,    0
    subsprite OAM_SIZE_16x16,   -7,  -21, 1091,    0
    subsprite OAM_SIZE_16x16,    2,  -12, 2880,    0
    subsprite OAM_SIZE_16x16,    9,    4, 2882,    0
    subsprite OAM_SIZE_8x8,     -4,  -17, 1115,    0
    subsprite OAM_SIZE_8x8,      2,   -9, 1101,    0
    subsprite OAM_SIZE_8x8,     -7,  -40, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 1926,    0
  FileDE23_Obj_5638:
    subsprite OAM_SIZE_8x32,   -14,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x16,     2,  -22, 1100,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 1089,    0
    subsprite OAM_SIZE_8x8,     -4,  -13, 2831,    0
    subsprite OAM_SIZE_16x16,    4,  -23, 2852,    0
    subsprite OAM_SIZE_8x8,     12,   -7, 1292,    0
    subsprite OAM_SIZE_16x8,    -5,  -18, 1098,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1926,    0
  FileDE23_Obj_5650:
    subsprite OAM_SIZE_8x32,   -14,  -30, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -22, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_8x16,     1,  -23, 1097,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_16x16,   -3,  -38, 2819,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -22, 2821,    0
    subsprite OAM_SIZE_16x8,    -6,  -19, 1095,    0
  FileDE23_Obj_5660:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x16,    -8,  -22, 1103,    0
    subsprite OAM_SIZE_8x16,     0,  -22, 1103,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -43, 1261,    0
  FileDE23_Obj_5669:
    subsprite OAM_SIZE_16x32,   -8,  -34, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
    subsprite OAM_SIZE_16x16,   -5,  -37, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -21, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -22, 1124,    0
  FileDE23_Obj_5679:
    subsprite OAM_SIZE_16x32,   -8,  -34, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
  FileDE23_Obj_5689:
    subsprite OAM_SIZE_16x32,   -8,  -33, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_16x16,   -5,  -42, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -26, 2826,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1125,    0
    subsprite OAM_SIZE_8x8,      0,  -20, 1141,    0
  FileDE23_Obj_5699:
    subsprite OAM_SIZE_16x32,   -8,  -33, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_16x16,   -5,  -43, 2824,    0
    subsprite OAM_SIZE_8x16,    -2,  -27, 2826,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 1125,    0
    subsprite OAM_SIZE_8x8,      0,  -21, 1141,    0
  FileDE23_Obj_5709:
    subsprite OAM_SIZE_16x32,   -8,  -34, 2764,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
  FileDE23_Obj_5720:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_16x8,    -8,  -27, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1120,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 1126,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1126,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,  -41, 1839,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 1868,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
  FileDE23_Obj_5730:
    subsprite OAM_SIZE_16x32,   -8,  -36, 2764,    0
    subsprite OAM_SIZE_16x8,    -8,  -19, 2300,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_8x8,     -2,   -9, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -4, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   12, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 1127,    0
    subsprite OAM_SIZE_8x16,     0,  -19, 1128,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  948,    0
    subsprite OAM_SIZE_16x16,   -8,  -32, 1866,    0
    subsprite OAM_SIZE_8x8,     -4,  -40, 1855,    0
  FileDE23_Obj_5743:
    subsprite OAM_SIZE_16x32,   -8,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_8x8,     -2,  -10, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -5, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   11, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -20, 1127,    0
    subsprite OAM_SIZE_8x8,     -7,   -7,  948,    0
    subsprite OAM_SIZE_8x16,     0,  -20, 1128,    0
    subsprite OAM_SIZE_8x8,     -1,  -40, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 1870,    0
  FileDE23_Obj_5755:
    subsprite OAM_SIZE_16x32,   -8,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -21, 1122,    0
    subsprite OAM_SIZE_8x8,     -2,   -9, 2842,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -2,   -4, 2884,    0
    subsprite OAM_SIZE_16x16,   -5,   12, 2885,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 1127,    0
    subsprite OAM_SIZE_8x16,     0,  -19, 1128,    0
    subsprite OAM_SIZE_8x8,     -7,   -6,  948,    0
    subsprite OAM_SIZE_8x8,     -1,  -40, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 1870,    0
  FileDE23_Obj_5767:
    subsprite OAM_SIZE_16x32,   -8,  -37, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1120,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 1126,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1126,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -41, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 1870,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2854,    0
  FileDE23_Obj_5776:
    subsprite OAM_SIZE_16x32,   -8,  -36, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
    subsprite OAM_SIZE_16x16,   -5,  -36, 2816,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2818,    0
    subsprite OAM_SIZE_8x8,     -8,  -21, 1117,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 1124,    0
  FileDE23_Obj_5786:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     3,  -29, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,    -2,  -26, 2760,    0, xflip=1
  FileDE23_Obj_5791:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1781,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_5798:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1783,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1856,    0
    subsprite OAM_SIZE_8x32,     4,  -31, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -27, 2760,    0, xflip=1
  FileDE23_Obj_5805:
    subsprite OAM_SIZE_8x8,     -2,  -35, 1781,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x16,    -3,  -34,  868,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  866,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1920,    0
    subsprite OAM_SIZE_8x32,     4,  -30, 2759,    0, xflip=1
    subsprite OAM_SIZE_8x32,     0,  -26, 2760,    0, xflip=1
  FileDE23_Obj_5812:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  871,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -3,  -27, 2758,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 2757,    0
  FileDE23_Obj_5818:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
  FileDE23_Obj_5826:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1766,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1859,    0
    subsprite OAM_SIZE_8x8,    -16,  -29, 1858,    0
    subsprite OAM_SIZE_8x32,    -9,  -28, 2757,    0
    subsprite OAM_SIZE_8x32,    -1,  -29, 2758,    0
  FileDE23_Obj_5834:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -27, 1890,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2757,    0
    subsprite OAM_SIZE_8x32,    -1,  -28, 2758,    0
  FileDE23_Obj_5842:
    subsprite OAM_SIZE_8x32,   -12,  -31, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  878,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -8,  -27, 2760,    0
  FileDE23_Obj_5848:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -28, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1765,    0
  FileDE23_Obj_5856:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -29, 2759,    0
    subsprite OAM_SIZE_8x8,    -16,  -36, 1861,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1862,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1767,    0
  FileDE23_Obj_5864:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  896,    0
    subsprite OAM_SIZE_8x32,   -12,  -28, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -34, 1893,    0
    subsprite OAM_SIZE_8x32,    -7,  -26, 2760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,      8,  -22, 1765,    0
  FileDE23_Obj_5872:
    subsprite OAM_SIZE_8x32,   -13,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -5,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  902,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
  FileDE23_Obj_5880:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1780,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
  FileDE23_Obj_5891:
    subsprite OAM_SIZE_8x32,   -14,  -35, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -27, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1782,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1864,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1880,    0
    subsprite OAM_SIZE_8x8,     -6,  -21, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -29, 2762,    0
  FileDE23_Obj_5902:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  904,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_8x8,      3,  -15, 1780,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -42, 1928,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -14,  -28, 2762,    0
  FileDE23_Obj_5913:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -6,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -26,  908,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_5920:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1781,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_5929:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -24, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1783,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1855,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1866,    0
  FileDE23_Obj_5938:
    subsprite OAM_SIZE_8x32,   -15,  -31, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  910,    0
    subsprite OAM_SIZE_8x16,    -5,  -18,  929,    0
    subsprite OAM_SIZE_8x8,     -4,  -11, 1781,    0
    subsprite OAM_SIZE_8x8,     -1,  -42, 1261,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 1870,    0
  FileDE23_Obj_5947:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1952,    0
    subsprite OAM_SIZE_16x32,   -8,  -27, 2757,    0
  FileDE23_Obj_5953:
    subsprite OAM_SIZE_16x16,   -8,  -29, 1952,    0
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -28, 1993,    0
  FileDE23_Obj_5959:
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_16x16,   -8,  -29, 1920,    0
    subsprite OAM_SIZE_8x32,   -10,  -28, 1992,    0
    subsprite OAM_SIZE_8x32,     2,  -28, 1993,    0
  FileDE23_Obj_5965:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_8x32,   -12,  -30, 2759,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1954,    0
    subsprite OAM_SIZE_8x8,    -16,  -36, 1906,    0
    subsprite OAM_SIZE_8x32,    -7,  -27, 2760,    0
  FileDE23_Obj_5972:
    subsprite OAM_SIZE_8x32,   -11,  -31, 1994,    0
    subsprite OAM_SIZE_16x16,   -5,  -30, 1954,    0
    subsprite OAM_SIZE_8x8,    -13,  -30, 1906,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_8x32,    -7,  -28, 1995,    0
  FileDE23_Obj_5978:
    subsprite OAM_SIZE_8x32,   -11,  -31, 1994,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_16x16,   -6,  -30, 1922,    0
    subsprite OAM_SIZE_8x8,    -14,  -22, 1890,    0
    subsprite OAM_SIZE_8x32,    -7,  -28, 1995,    0
  FileDE23_Obj_5984:
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1956,    0
    subsprite OAM_SIZE_8x8,     -8,  -43, 1909,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_5994:
    subsprite OAM_SIZE_16x32,  -18,  -34, 1996,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_8x8,     -6,  -36, 1909,    0
    subsprite OAM_SIZE_16x16,   -6,  -28, 1956,    0
    subsprite OAM_SIZE_16x32,  -19,  -30, 1998,    0
  FileDE23_Obj_6000:
    subsprite OAM_SIZE_16x32,  -18,  -34, 1996,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_16x16,   -6,  -28, 1924,    0
    subsprite OAM_SIZE_8x8,    -14,  -28, 1893,    0
    subsprite OAM_SIZE_16x32,  -19,  -30, 1998,    0
  FileDE23_Obj_6006:
    subsprite OAM_SIZE_8x32,   -15,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1986,    0
    subsprite OAM_SIZE_16x8,    -8,  -42, 1990,    0
  FileDE23_Obj_6014:
    subsprite OAM_SIZE_8x8,     -4,  -29, 1016,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
    subsprite OAM_SIZE_16x8,    -6,  -34, 1990,    0
    subsprite OAM_SIZE_16x16,   -6,  -26, 1986,    0
    subsprite OAM_SIZE_8x32,   -16,  -33, 2701,    0
    subsprite OAM_SIZE_8x16,    -8,  -25, 2891,    0
  FileDE23_Obj_6022:
    subsprite OAM_SIZE_8x8,     -4,  -29, 1016,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
    subsprite OAM_SIZE_8x8,     -7,  -35, 1928,    0
    subsprite OAM_SIZE_16x16,   -7,  -27, 1926,    0
    subsprite OAM_SIZE_8x16,    -8,  -25, 2891,    0
    subsprite OAM_SIZE_8x32,   -16,  -33, 2701,    0
  FileDE23_Obj_6030:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1902,    0
    subsprite OAM_SIZE_8x8,     -4,  -42, 1945,    0
  FileDE23_Obj_6037:
    subsprite OAM_SIZE_8x32,     2,  -37, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -37, 2766,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
    subsprite OAM_SIZE_8x8,     -4,  -34, 1945,    0
    subsprite OAM_SIZE_16x16,   -8,  -26, 1902,    0
  FileDE23_Obj_6044:
    subsprite OAM_SIZE_8x32,     2,  -37, 2767,    0
    subsprite OAM_SIZE_8x32,   -10,  -37, 2766,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
    subsprite OAM_SIZE_16x16,   -9,  -27, 1870,    0
    subsprite OAM_SIZE_8x8,     -1,  -35, 1261,    0
  FileDE23_Obj_6051:
    subsprite OAM_SIZE_16x16,  -21,  -30, 1964,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -37,  -30,  202,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,  -36,  203,    0, xflip=1
    subsprite OAM_SIZE_16x16,    5,  -30, 1964,    0
    subsprite OAM_SIZE_16x8,    21,  -30,  202,    0
    subsprite OAM_SIZE_8x8,      4,  -36,  203,    0
    subsprite OAM_SIZE_8x16,    -8,  -14, 1775,    0
    subsprite OAM_SIZE_8x8,    -16,   -3,  201,    0
    subsprite OAM_SIZE_8x8,      8,   -3,  201,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -14, 1775,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19, 1120,    0
    subsprite OAM_SIZE_16x16,   -8,  -30, 1902,    0
    subsprite OAM_SIZE_8x8,     -4,  -38, 1945,    0
    subsprite OAM_SIZE_16x8,     2,  -20,  196,    0
    subsprite OAM_SIZE_8x8,     10,  -12,  198,    0
    subsprite OAM_SIZE_8x8,    -18,  -12,  198,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -18,  -20,  196,    0, xflip=1
  FileDE23_Obj_6068:
    subsprite OAM_SIZE_8x16,    -8,  -14, 1775,    0
    subsprite OAM_SIZE_8x8,    -16,   -3,  201,    0
    subsprite OAM_SIZE_8x8,      8,   -3,  201,    0, xflip=1
    subsprite OAM_SIZE_8x16,     0,  -14, 1775,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -20, 1120,    0
    subsprite OAM_SIZE_16x8,     1,  -19,  196,    0
    subsprite OAM_SIZE_8x8,      9,  -11,  198,    0
    subsprite OAM_SIZE_8x8,    -17,  -11,  198,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -17,  -19,  196,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -22,  -31, 1964,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -38,  -31,  202,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -13,  -37,  203,    0, xflip=1
    subsprite OAM_SIZE_16x16,    6,  -31, 1964,    0
    subsprite OAM_SIZE_16x8,    22,  -31,  202,    0
    subsprite OAM_SIZE_16x16,   -8,  -29, 1902,    0
    subsprite OAM_SIZE_8x8,     -4,  -37, 1945,    0
    subsprite OAM_SIZE_8x8,      5,  -37,  203,    0
  FileDE23_Obj_6085:
    subsprite OAM_SIZE_16x16,  -14,  -23, 1768,    0
    subsprite OAM_SIZE_16x8,   -14,   -7, 1340,    0
    subsprite OAM_SIZE_8x8,     -6,    1,  200,    0
    subsprite OAM_SIZE_8x8,     13,  -12,  199,    0
    subsprite OAM_SIZE_16x16,    5,  -24, 1220,    0, yflip=1
    subsprite OAM_SIZE_8x16,    13,  -40, 1222,    0, yflip=1
    subsprite OAM_SIZE_16x16,  -19,  -11, 1252,    0, yflip=1
    subsprite OAM_SIZE_8x16,    -3,  -11, 1254,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -1,  -14, 1770,    0
    subsprite OAM_SIZE_16x8,    -1,  -22, 1342,    0
  FileDE23_Obj_6095:
    subsprite OAM_SIZE_16x16,   -3,  -25, 1946,    0
    subsprite OAM_SIZE_8x16,   -11,  -25, 1915,    0
    subsprite OAM_SIZE_16x16,   -8,  -12, 1773,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  511,    0
    subsprite OAM_SIZE_8x16,   -16,  -12, 1772,    0
    subsprite OAM_SIZE_16x8,   -16,    4,  204,    0
    subsprite OAM_SIZE_16x8,     8,  -12,  206,    0
    subsprite OAM_SIZE_16x16,  -23,  -25, 1252,    0
    subsprite OAM_SIZE_8x16,    -7,  -25, 1254,    0
    subsprite OAM_SIZE_16x16,    1,  -12, 1220,    0
    subsprite OAM_SIZE_8x16,     9,    4, 1222,    0
  FileDE23_Obj_6106:
    subsprite OAM_SIZE_8x8,      0,  -24, 2338,    0
    subsprite OAM_SIZE_8x8,     -8,  -24, 2338,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_16x8,    -8,  -19, 2304,    0
    subsprite OAM_SIZE_16x16,   -8,  -29, 2306,    0
    subsprite OAM_SIZE_8x16,    -4,  -16, 2320,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 2352,    0
    subsprite OAM_SIZE_8x16,     6,  -21, 2321,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2353,    0
    subsprite OAM_SIZE_8x16,   -14,  -21, 2321,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,   -5, 2353,    0, xflip=1
    subsprite OAM_SIZE_8x8,      4,  -19, 2354,    0
    subsprite OAM_SIZE_8x8,    -12,  -19, 2354,    0, xflip=1
  FileDE23_Obj_6120:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_16x16,   -5,  -29, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -26, 2312,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 2383,    0
    subsprite OAM_SIZE_8x16,     2,  -18, 2341,    0
    subsprite OAM_SIZE_8x8,      5,   -7, 2342,    0
  FileDE23_Obj_6129:
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2313,    0
    subsprite OAM_SIZE_8x16,    -5,  -18, 2339,    0
    subsprite OAM_SIZE_8x8,     -5,   -2, 2328,    0
    subsprite OAM_SIZE_16x16,   -1,  -32, 2315,    0
    subsprite OAM_SIZE_16x8,    -1,  -16, 2347,    0
    subsprite OAM_SIZE_8x8,     -9,  -24, 2334,    0
    subsprite OAM_SIZE_16x8,   -12,  -18, 2317,    0
    subsprite OAM_SIZE_8x16,   -12,  -10, 2333,    0
  FileDE23_Obj_6139:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x8,    -10,  -20, 2398,    0
    subsprite OAM_SIZE_8x16,   -13,  -15, 2397,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2319,    0
    subsprite OAM_SIZE_8x8,     -8,   -3, 2351,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x8,    -5,  -29, 2343,    0
    subsprite OAM_SIZE_16x16,   -4,  -21, 2359,    0
    subsprite OAM_SIZE_8x8,      5,  -14, 2350,    0
  FileDE23_Obj_6150:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_8x16,     6,  -21, 2346,    0
    subsprite OAM_SIZE_8x8,      6,   -5, 2378,    0
    subsprite OAM_SIZE_8x16,     0,  -27, 2345,    0
    subsprite OAM_SIZE_8x8,      0,  -11, 2377,    0
    subsprite OAM_SIZE_8x8,    -14,   -5, 2378,    0, xflip=1
    subsprite OAM_SIZE_8x16,   -14,  -21, 2346,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -8,  -27, 2345,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,  -11, 2377,    0, xflip=1
  FileDE23_Obj_6160:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1344,    0
    subsprite OAM_SIZE_8x8,     -6,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -7,  -25, 2308,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2367,    0
    subsprite OAM_SIZE_8x8,     -4,  -29, 1979,    0
    subsprite OAM_SIZE_16x16,   -4,  -31, 2310,    0
    subsprite OAM_SIZE_8x8,     12,  -28, 2312,    0
    subsprite OAM_SIZE_16x8,    -1,  -21, 2371,    0
    subsprite OAM_SIZE_8x8,      4,  -13, 2358,    0
    subsprite OAM_SIZE_16x8,   -23,  -16, 2394,    0
    subsprite OAM_SIZE_8x8,     -7,  -20, 2396,    0
  FileDE23_Obj_6171:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1346,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -24, 2308,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2367,    0
    subsprite OAM_SIZE_8x8,     -5,  -28, 1979,    0
    subsprite OAM_SIZE_16x16,   -4,  -30, 2310,    0
    subsprite OAM_SIZE_8x8,     12,  -27, 2312,    0
    subsprite OAM_SIZE_16x8,     0,  -19, 2371,    0
    subsprite OAM_SIZE_8x8,      5,  -11, 2358,    0
    subsprite OAM_SIZE_8x8,    -24,  -12, 2410,    0
    subsprite OAM_SIZE_16x8,   -16,  -18, 2411,    0
  FileDE23_Obj_6182:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1348,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -7,  -24, 2308,    0
    subsprite OAM_SIZE_8x8,     -9,  -22, 2367,    0
    subsprite OAM_SIZE_8x8,     -6,  -28, 1979,    0
    subsprite OAM_SIZE_16x16,   -5,  -31, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -28, 2312,    0
    subsprite OAM_SIZE_16x8,     1,  -19, 2371,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 2358,    0
    subsprite OAM_SIZE_8x8,    -16,  -11, 2414,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2399,    0
  FileDE23_Obj_6193:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1350,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -7,  -25, 2308,    0
    subsprite OAM_SIZE_8x8,    -10,  -22, 2367,    0
    subsprite OAM_SIZE_8x8,     -7,  -28, 1979,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -29, 2312,    0
    subsprite OAM_SIZE_16x8,     2,  -20, 2371,    0
    subsprite OAM_SIZE_8x8,      7,  -12, 2358,    0
    subsprite OAM_SIZE_16x8,   -23,  -15, 2394,    0
    subsprite OAM_SIZE_8x8,     -7,  -19, 2396,    0
  FileDE23_Obj_6204:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1352,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -7,  -25, 2308,    0
    subsprite OAM_SIZE_8x8,    -11,  -21, 2367,    0
    subsprite OAM_SIZE_8x8,     -8,  -27, 1979,    0
    subsprite OAM_SIZE_16x16,   -4,  -31, 2310,    0
    subsprite OAM_SIZE_8x8,     12,  -28, 2312,    0
    subsprite OAM_SIZE_16x8,     3,  -21, 2371,    0
    subsprite OAM_SIZE_8x8,      8,  -13, 2358,    0
    subsprite OAM_SIZE_8x8,    -24,  -13, 2410,    0
    subsprite OAM_SIZE_16x8,   -16,  -19, 2411,    0
  FileDE23_Obj_6215:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1354,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1310,    0
    subsprite OAM_SIZE_16x16,   -7,  -24, 2308,    0
    subsprite OAM_SIZE_8x8,    -10,  -21, 2367,    0
    subsprite OAM_SIZE_8x8,     -7,  -27, 1979,    0
    subsprite OAM_SIZE_16x16,   -4,  -30, 2310,    0
    subsprite OAM_SIZE_8x8,     12,  -27, 2312,    0
    subsprite OAM_SIZE_16x8,     2,  -19, 2371,    0
    subsprite OAM_SIZE_8x8,      7,  -11, 2358,    0
    subsprite OAM_SIZE_8x8,    -17,  -11, 2414,    0
    subsprite OAM_SIZE_8x16,    -9,  -19, 2399,    0
  FileDE23_Obj_6226:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1356,    0
    subsprite OAM_SIZE_16x16,   -7,  -24, 2308,    0
    subsprite OAM_SIZE_8x8,     -9,  -22, 2367,    0
    subsprite OAM_SIZE_8x8,     -6,  -28, 1979,    0
    subsprite OAM_SIZE_16x16,   -5,  -31, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -28, 2312,    0
    subsprite OAM_SIZE_16x8,     1,  -19, 2371,    0
    subsprite OAM_SIZE_8x8,      6,  -11, 2358,    0
    subsprite OAM_SIZE_16x8,   -24,  -15, 2394,    0
    subsprite OAM_SIZE_8x8,     -8,  -19, 2396,    0
  FileDE23_Obj_6236:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1358,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1311,    0
    subsprite OAM_SIZE_16x16,   -7,  -25, 2308,    0
    subsprite OAM_SIZE_8x8,     -8,  -23, 2367,    0
    subsprite OAM_SIZE_8x8,     -5,  -29, 1979,    0
    subsprite OAM_SIZE_16x16,   -5,  -32, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -29, 2312,    0
    subsprite OAM_SIZE_16x8,     0,  -20, 2371,    0
    subsprite OAM_SIZE_8x8,      5,  -12, 2358,    0
    subsprite OAM_SIZE_8x8,    -22,  -14, 2410,    0
    subsprite OAM_SIZE_16x8,   -14,  -20, 2411,    0
  FileDE23_Obj_6247:
    subsprite OAM_SIZE_16x16,   -9,  -15, 1408,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x8,   -19,  -33, 2373,    0
    subsprite OAM_SIZE_8x8,    -10,  -25, 2388,    0
    subsprite OAM_SIZE_8x8,     12,  -19, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -22, 2363,    0
    subsprite OAM_SIZE_16x16,  -12,  -18, 2365,    0
    subsprite OAM_SIZE_16x8,    -2,  -26, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -18, 2359,    0
  FileDE23_Obj_6256:
    subsprite OAM_SIZE_16x16,   -9,  -14, 1410,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1293,    0
    subsprite OAM_SIZE_8x8,     11,  -18, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -21, 2363,    0
    subsprite OAM_SIZE_16x16,  -11,  -17, 2365,    0
    subsprite OAM_SIZE_16x8,    -2,  -25, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -17, 2359,    0
    subsprite OAM_SIZE_16x8,   -19,  -29, 2390,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2389,    0
  FileDE23_Obj_6265:
    subsprite OAM_SIZE_16x16,   -9,  -14, 1412,    0
    subsprite OAM_SIZE_8x8,     10,  -17, 1978,    0
    subsprite OAM_SIZE_16x8,   -17,  -28, 2392,    0
    subsprite OAM_SIZE_16x8,   -17,  -20, 2408,    0
    subsprite OAM_SIZE_16x16,   -6,  -21, 2363,    0
    subsprite OAM_SIZE_16x16,  -10,  -16, 2365,    0
    subsprite OAM_SIZE_16x8,    -3,  -26, 2343,    0
    subsprite OAM_SIZE_16x16,   -2,  -18, 2359,    0
  FileDE23_Obj_6273:
    subsprite OAM_SIZE_16x16,   -9,  -15, 1414,    0
    subsprite OAM_SIZE_16x8,   -18,  -32, 2373,    0
    subsprite OAM_SIZE_8x8,     -9,  -24, 2388,    0
    subsprite OAM_SIZE_8x8,      9,  -18, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -22, 2363,    0
    subsprite OAM_SIZE_16x8,    -3,  -27, 2343,    0
    subsprite OAM_SIZE_16x16,   -2,  -19, 2359,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2365,    0
  FileDE23_Obj_6281:
    subsprite OAM_SIZE_16x16,   -9,  -15, 1416,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1326,    0
    subsprite OAM_SIZE_8x8,      8,  -19, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -22, 2363,    0
    subsprite OAM_SIZE_16x8,    -2,  -26, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -18, 2359,    0
    subsprite OAM_SIZE_16x8,   -19,  -30, 2390,    0
    subsprite OAM_SIZE_8x8,     -7,  -22, 2389,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2365,    0
  FileDE23_Obj_6290:
    subsprite OAM_SIZE_16x16,   -9,  -14, 1418,    0
    subsprite OAM_SIZE_8x8,      9,  -18, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -21, 2363,    0
    subsprite OAM_SIZE_16x8,    -2,  -25, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -17, 2359,    0
    subsprite OAM_SIZE_16x8,   -18,  -29, 2392,    0
    subsprite OAM_SIZE_16x8,   -18,  -21, 2408,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2365,    0
  FileDE23_Obj_6298:
    subsprite OAM_SIZE_16x16,   -9,  -14, 1420,    0
    subsprite OAM_SIZE_16x8,   -19,  -32, 2373,    0
    subsprite OAM_SIZE_8x8,    -10,  -24, 2388,    0
    subsprite OAM_SIZE_8x8,     10,  -18, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2363,    0
    subsprite OAM_SIZE_16x16,  -10,  -17, 2365,    0
    subsprite OAM_SIZE_16x8,    -3,  -26, 2343,    0
    subsprite OAM_SIZE_16x16,   -2,  -18, 2359,    0
  FileDE23_Obj_6306:
    subsprite OAM_SIZE_16x16,   -9,  -15, 1422,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_8x8,     11,  -19, 1978,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2363,    0
    subsprite OAM_SIZE_16x16,  -11,  -18, 2365,    0
    subsprite OAM_SIZE_16x8,   -19,  -31, 2390,    0
    subsprite OAM_SIZE_8x8,     -7,  -23, 2389,    0
    subsprite OAM_SIZE_16x8,    -3,  -27, 2343,    0
    subsprite OAM_SIZE_16x16,   -2,  -19, 2359,    0
  FileDE23_Obj_6315:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_16x16,   -5,  -29, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -26, 2312,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 2383,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
  FileDE23_Obj_6324:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_16x16,   -5,  -30, 2310,    0
    subsprite OAM_SIZE_8x8,     11,  -27, 2312,    0
    subsprite OAM_SIZE_8x16,    -8,  -16, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,    0, 2383,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
  FileDE23_Obj_6333:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,   -1, 2383,    0
    subsprite OAM_SIZE_16x16,   -3,  -31, 2402,    0
    subsprite OAM_SIZE_8x8,      5,  -15, 2425,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
  FileDE23_Obj_6342:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2383,    0
    subsprite OAM_SIZE_16x16,   -2,  -32, 2402,    0
    subsprite OAM_SIZE_8x8,      6,  -16, 2425,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
  FileDE23_Obj_6351:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_16x16,   -3,  -31, 2310,    0
    subsprite OAM_SIZE_8x8,     13,  -28, 2312,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
    subsprite OAM_SIZE_8x16,    -6,  -19, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,   -3, 2383,    0
  FileDE23_Obj_6360:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_16x16,   -2,  -30, 2400,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2340,    0
    subsprite OAM_SIZE_8x8,     -8,   -2, 2383,    0
  FileDE23_Obj_6368:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23, 2308,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2340,    0
    subsprite OAM_SIZE_8x8,     -7,   -1, 2383,    0
    subsprite OAM_SIZE_8x8,     12,  -26, 2312,    0
    subsprite OAM_SIZE_16x16,   -4,  -29, 2310,    0
    subsprite OAM_SIZE_16x8,     2,  -18, 2386,    0
    subsprite OAM_SIZE_8x8,     11,  -22, 2370,    0
  FileDE23_Obj_6377:
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_8x8,     -9,  -20, 2398,    0
    subsprite OAM_SIZE_8x16,   -12,  -15, 2397,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x8,    -4,  -29, 2343,    0
    subsprite OAM_SIZE_16x16,   -3,  -21, 2359,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6388:
    subsprite OAM_SIZE_8x8,     -9,  -20, 2398,    0
    subsprite OAM_SIZE_8x16,   -12,  -15, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x8,    -4,  -30, 2343,    0
    subsprite OAM_SIZE_16x16,   -3,  -22, 2359,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6399:
    subsprite OAM_SIZE_8x8,     -8,  -21, 2398,    0
    subsprite OAM_SIZE_8x16,   -11,  -16, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x16,   -3,  -29, 2406,    0
    subsprite OAM_SIZE_16x8,    -3,  -13, 2426,    0
    subsprite OAM_SIZE_8x8,     13,  -21, 2424,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6411:
    subsprite OAM_SIZE_8x8,     -7,  -21, 2398,    0
    subsprite OAM_SIZE_8x16,   -11,  -17, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x16,   -2,  -28, 2406,    0
    subsprite OAM_SIZE_16x8,    -2,  -12, 2426,    0
    subsprite OAM_SIZE_8x8,     14,  -20, 2424,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6423:
    subsprite OAM_SIZE_8x8,     -6,  -22, 2398,    0
    subsprite OAM_SIZE_8x16,   -10,  -17, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_16x8,    -2,  -26, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -18, 2359,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6434:
    subsprite OAM_SIZE_8x8,     -7,  -21, 2398,    0
    subsprite OAM_SIZE_8x16,   -10,  -16, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x8,    -2,  -25, 2343,    0
    subsprite OAM_SIZE_16x16,   -1,  -17, 2404,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6445:
    subsprite OAM_SIZE_8x8,     -8,  -20, 2398,    0
    subsprite OAM_SIZE_8x16,   -11,  -15, 2397,    0
    subsprite OAM_SIZE_8x8,      9,  -15, 2369,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -22, 2363,    0
    subsprite OAM_SIZE_8x8,     -4,  -22, 2338,    0
    subsprite OAM_SIZE_16x8,    -3,  -27, 2343,    0
    subsprite OAM_SIZE_16x16,   -2,  -19, 2359,    0
    subsprite OAM_SIZE_8x16,    -5,  -19, 2368,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2385,    0
  FileDE23_Obj_6456:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
  FileDE23_Obj_6462:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 2464,    0
  FileDE23_Obj_6468:
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 2496,    0
    subsprite OAM_SIZE_8x8,    -17,  -34, 2492,    0
  FileDE23_Obj_6475:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
  FileDE23_Obj_6481:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2470,    0
    subsprite OAM_SIZE_8x8,     -1,  -40, 2493,    0
  FileDE23_Obj_6488:
    subsprite OAM_SIZE_8x16,    -1,  -19, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,    2, 1293,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -14,  281,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -33, 2438,    0, xflip=1
  FileDE23_Obj_6494:
    subsprite OAM_SIZE_8x8,     -7,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -23,  259,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -1,  -19, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -34, 2464,    0, xflip=1
  FileDE23_Obj_6500:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  269,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2080,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2432,    0
  FileDE23_Obj_6506:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0
    subsprite OAM_SIZE_16x16,   -9,  -27,  290,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  285,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2082,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2434,    0
  FileDE23_Obj_6511:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0
    subsprite OAM_SIZE_16x16,  -10,  -27,  292,    0
    subsprite OAM_SIZE_8x8,      6,  -21,  270,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2084,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
  FileDE23_Obj_6516:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0
    subsprite OAM_SIZE_8x8,      0,   -5, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,  -10,  -28,  294,    0
    subsprite OAM_SIZE_8x8,      6,  -24,  286,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2086,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2436,    0
  FileDE23_Obj_6522:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1312,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    1, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  288,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  269,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19, 2080,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2432,    0
  FileDE23_Obj_6528:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1314,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -27,  290,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  285,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19, 2082,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2434,    0
  FileDE23_Obj_6533:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1316,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -27,  292,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -21,  270,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -18, 2084,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
  FileDE23_Obj_6538:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1318,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -5, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -6,  -28,  294,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -24,  286,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -18, 2086,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2436,    0
  FileDE23_Obj_6544:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1344,    0
    subsprite OAM_SIZE_8x8,     -6,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  320,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2112,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2464,    0
  FileDE23_Obj_6549:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1346,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  322,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2114,    0
    subsprite OAM_SIZE_8x8,     -7,   -5, 2054,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2466,    0
  FileDE23_Obj_6555:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1348,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  324,    0
    subsprite OAM_SIZE_8x8,     10,  -19,  271,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2116,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 2055,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2464,    0
  FileDE23_Obj_6562:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1350,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  326,    0
    subsprite OAM_SIZE_8x8,      9,  -23,  287,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2118,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2468,    0
  FileDE23_Obj_6568:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1352,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -6,  -25,  328,    0
    subsprite OAM_SIZE_8x8,     10,  -20,  296,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2112,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2464,    0
  FileDE23_Obj_6574:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1354,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1310,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  330,    0
    subsprite OAM_SIZE_16x16,  -14,  -21, 2114,    0
    subsprite OAM_SIZE_8x8,     -7,   -5, 2054,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2466,    0
  FileDE23_Obj_6580:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1356,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  332,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2116,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 2055,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2464,    0
  FileDE23_Obj_6585:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1358,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1311,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  334,    0
    subsprite OAM_SIZE_16x16,  -14,  -20, 2118,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2468,    0
  FileDE23_Obj_6590:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1376,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  352,    0
    subsprite OAM_SIZE_16x16,  -19,  -26, 2144,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
  FileDE23_Obj_6597:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1378,    0
    subsprite OAM_SIZE_8x8,      0,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  354,    0
    subsprite OAM_SIZE_16x16,  -19,  -23, 2146,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2498,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
  FileDE23_Obj_6603:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1380,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  356,    0
    subsprite OAM_SIZE_16x16,  -19,  -22, 2148,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
  FileDE23_Obj_6609:
    subsprite OAM_SIZE_16x16,   -7,  -18, 1382,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  358,    0
    subsprite OAM_SIZE_16x16,  -19,  -24, 2150,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2500,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
  FileDE23_Obj_6615:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1384,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  360,    0
    subsprite OAM_SIZE_16x16,  -19,  -26, 2144,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
  FileDE23_Obj_6621:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1386,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  362,    0
    subsprite OAM_SIZE_16x16,  -19,  -23, 2146,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2498,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
  FileDE23_Obj_6626:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1388,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  364,    0
    subsprite OAM_SIZE_16x16,  -19,  -22, 2148,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
  FileDE23_Obj_6631:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1390,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  366,    0
    subsprite OAM_SIZE_16x16,  -19,  -24, 2150,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2500,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
  FileDE23_Obj_6637:
    subsprite OAM_SIZE_16x16,  -14,  -28, 2176,    0
    subsprite OAM_SIZE_8x8,    -15,  -21, 2055,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1408,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  384,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  281,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 2438,    0
  FileDE23_Obj_6644:
    subsprite OAM_SIZE_16x8,   -14,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1410,    0
    subsprite OAM_SIZE_8x8,     -2,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  386,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2440,    0
  FileDE23_Obj_6649:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2180,    0
    subsprite OAM_SIZE_8x8,    -14,  -16, 2071,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1412,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  388,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2438,    0
  FileDE23_Obj_6654:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2182,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1414,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  390,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2442,    0
  FileDE23_Obj_6659:
    subsprite OAM_SIZE_16x16,  -14,  -28, 2176,    0
    subsprite OAM_SIZE_8x8,    -15,  -21, 2055,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1416,    0
    subsprite OAM_SIZE_8x8,      3,    1, 1326,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  392,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 2438,    0
  FileDE23_Obj_6665:
    subsprite OAM_SIZE_16x8,   -14,  -25, 2178,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1418,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  394,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2440,    0
  FileDE23_Obj_6669:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2180,    0
    subsprite OAM_SIZE_8x8,    -14,  -16, 2071,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1420,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  396,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2438,    0
  FileDE23_Obj_6674:
    subsprite OAM_SIZE_16x8,   -15,  -24, 2182,    0
    subsprite OAM_SIZE_8x8,     -7,  -32, 2070,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1422,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  398,    0
    subsprite OAM_SIZE_8x8,      8,  -21,  312,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2442,    0
  FileDE23_Obj_6681:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0
    subsprite OAM_SIZE_8x8,     -9,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -24,  416,    0
    subsprite OAM_SIZE_8x8,      7,  -19,  297,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2470,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
  FileDE23_Obj_6688:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  418,    0
    subsprite OAM_SIZE_8x8,      7,  -18,  313,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2472,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
  FileDE23_Obj_6694:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  298,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2470,    0
  FileDE23_Obj_6700:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  314,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2474,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
  FileDE23_Obj_6706:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2208,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1440,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    1, 1294,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  416,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -19,  297,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2470,    0
  FileDE23_Obj_6713:
    subsprite OAM_SIZE_16x8,    -8,  -28, 2210,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1442,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -7,  -23,  418,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -15,  -18,  313,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2472,    0
  FileDE23_Obj_6719:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2212,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1444,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  420,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -18,  298,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2470,    0
  FileDE23_Obj_6725:
    subsprite OAM_SIZE_16x8,    -8,  -27, 2214,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1446,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  422,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -16,  -20,  314,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2474,    0
  FileDE23_Obj_6731:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1576,    0
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
  FileDE23_Obj_6737:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1578,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -24,  454,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
    subsprite OAM_SIZE_8x8,     -2,  -22,  301,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 2464,    0
  FileDE23_Obj_6744:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1580,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  460,    0
    subsprite OAM_SIZE_16x8,    -4,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  317,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
    subsprite OAM_SIZE_16x16,   -7,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -15,  -33, 2492,    0
  FileDE23_Obj_6754:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,  -10,  -15, 1582,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  482,    0
    subsprite OAM_SIZE_16x8,    -6,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  430,    0
    subsprite OAM_SIZE_16x16,   -8,  -32, 2438,    0
  FileDE23_Obj_6761:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1600,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1337,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -9,  -32, 2470,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
  FileDE23_Obj_6769:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2056,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_6775:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2436,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2058,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_6780:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2432,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2060,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_6785:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0
    subsprite OAM_SIZE_8x8,      0,   -4, 1331,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2434,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2062,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_6791:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1448,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,    2, 1295,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2432,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2056,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_6797:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1450,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  450,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2436,    0
    subsprite OAM_SIZE_16x16,   -8,  -18, 2058,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  300,    0
  FileDE23_Obj_6802:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1452,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -28,  448,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 2432,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2060,    0
    subsprite OAM_SIZE_8x8,      1,  -22,  299,    0
  FileDE23_Obj_6807:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1454,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -8,   -4, 1331,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -27,  452,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2434,    0
    subsprite OAM_SIZE_16x16,   -8,  -19, 2062,    0
    subsprite OAM_SIZE_8x8,      1,  -21,  299,    0
  FileDE23_Obj_6813:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1472,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2464,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2088,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2089,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_6819:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1474,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1291,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2468,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2091,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_6827:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1476,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1307,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2464,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2093,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_6834:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1478,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1308,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2466,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2094,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2095,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_6841:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1480,    0
    subsprite OAM_SIZE_8x8,     -4,    1, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2464,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2088,    0
    subsprite OAM_SIZE_8x16,    -6,  -17, 2089,    0
    subsprite OAM_SIZE_8x8,     -1,  -22,  301,    0
  FileDE23_Obj_6848:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1482,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1309,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  456,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2468,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2091,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  302,    0
    subsprite OAM_SIZE_8x8,      0,  -16, 1293,    0
  FileDE23_Obj_6856:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1484,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  454,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2464,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2093,    0
    subsprite OAM_SIZE_8x8,     -1,  -23,  301,    0
  FileDE23_Obj_6864:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1486,    0
    subsprite OAM_SIZE_8x8,     -7,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  458,    0
    subsprite OAM_SIZE_16x16,   -7,  -34, 2466,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 2094,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2095,    0
    subsprite OAM_SIZE_8x8,     -1,  -21,  303,    0
  FileDE23_Obj_6871:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1504,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1292,    0
    subsprite OAM_SIZE_8x8,    -15,   -7, 1320,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
    subsprite OAM_SIZE_8x16,   -11,  -20, 2120,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
  FileDE23_Obj_6880:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1506,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2500,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2121,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_6888:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1508,    0
    subsprite OAM_SIZE_8x8,     -5,    1, 1321,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
    subsprite OAM_SIZE_8x16,    -6,  -21, 2122,    0
    subsprite OAM_SIZE_8x8,     -5,   -5, 2055,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
  FileDE23_Obj_6897:
    subsprite OAM_SIZE_16x16,   -7,  -18, 1510,    0
    subsprite OAM_SIZE_8x8,     -9,   -2, 1322,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2498,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 2123,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_6905:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1512,    0
    subsprite OAM_SIZE_8x8,    -15,   -4, 1323,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
    subsprite OAM_SIZE_8x16,   -11,  -20, 2120,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -17,  317,    0
  FileDE23_Obj_6913:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1514,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  462,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2500,    0
    subsprite OAM_SIZE_8x8,    -14,  -33, 2492,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2121,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  318,    0
    subsprite OAM_SIZE_8x8,      8,  -18,  424,    0
  FileDE23_Obj_6921:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1516,    0
    subsprite OAM_SIZE_8x8,     -3,    1, 1336,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  460,    0
    subsprite OAM_SIZE_16x16,   -6,  -34, 2496,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
    subsprite OAM_SIZE_8x16,    -6,  -21, 2122,    0
    subsprite OAM_SIZE_16x8,    -3,  -21,  315,    0
    subsprite OAM_SIZE_8x8,      9,  -18,  317,    0
    subsprite OAM_SIZE_8x8,     -5,   -5, 2055,    0
  FileDE23_Obj_6930:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1518,    0
    subsprite OAM_SIZE_8x8,    -15,   -6, 1324,    0
    subsprite OAM_SIZE_16x16,   -5,  -23,  480,    0
    subsprite OAM_SIZE_8x8,    -14,  -34, 2492,    0
    subsprite OAM_SIZE_16x16,   -6,  -33, 2498,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 2123,    0
    subsprite OAM_SIZE_16x8,    -3,  -20,  425,    0
    subsprite OAM_SIZE_8x8,      9,  -16,  427,    0
  FileDE23_Obj_6938:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2124,    0
    subsprite OAM_SIZE_8x8,    -14,  -14, 2194,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1536,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1325,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2438,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_6946:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -14,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1538,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2442,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_6954:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2126,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1540,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 2438,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_6961:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2127,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1542,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2440,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_6968:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2124,    0
    subsprite OAM_SIZE_8x8,    -14,  -14, 2194,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1544,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2438,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -13,  430,    0
  FileDE23_Obj_6976:
    subsprite OAM_SIZE_8x16,    -6,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -14,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1546,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  484,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2442,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  440,    0
    subsprite OAM_SIZE_8x8,      5,  -14,  431,    0
  FileDE23_Obj_6983:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2126,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2196,    0
    subsprite OAM_SIZE_16x16,   -9,  -15, 1548,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  482,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 2438,    0
    subsprite OAM_SIZE_16x8,    -5,  -21,  428,    0
    subsprite OAM_SIZE_8x8,      6,  -14,  430,    0
  FileDE23_Obj_6990:
    subsprite OAM_SIZE_8x16,    -7,  -21, 2127,    0
    subsprite OAM_SIZE_8x8,      1,  -21, 2197,    0
    subsprite OAM_SIZE_16x16,   -9,  -14, 1550,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1327,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  486,    0
    subsprite OAM_SIZE_16x16,   -7,  -31, 2440,    0
    subsprite OAM_SIZE_16x8,    -5,  -20,  442,    0
    subsprite OAM_SIZE_8x8,      6,  -12,  444,    0
  FileDE23_Obj_6998:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2152,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0
    subsprite OAM_SIZE_8x8,     -9,    2, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2470,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_7006:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2474,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_7013:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2470,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_7020:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2158,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2472,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_7027:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2152,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1568,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  488,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2470,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -11,  299,    0, xflip=1
  FileDE23_Obj_7035:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1570,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  490,    0
    subsprite OAM_SIZE_8x8,     -1,  -38, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2474,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  446,    0
    subsprite OAM_SIZE_8x8,     -3,  -13,  299,    0
  FileDE23_Obj_7042:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2156,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1572,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  488,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2470,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  445,    0
    subsprite OAM_SIZE_8x8,     -6,  -12,  299,    0, xflip=1
  FileDE23_Obj_7049:
    subsprite OAM_SIZE_16x16,   -8,  -19, 2158,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1574,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -23,  492,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_16x16,   -9,  -31, 2472,    0
    subsprite OAM_SIZE_8x8,     -5,  -20,  447,    0
    subsprite OAM_SIZE_8x8,     -2,  -10,  494,    0
  FileDE23_Obj_7056:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 2438,    0, xflip=1
  FileDE23_Obj_7061:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1604,    0
    subsprite OAM_SIZE_8x8,     -2,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  514,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 2438,    0, xflip=1
  FileDE23_Obj_7066:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  516,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 2438,    0, xflip=1
  FileDE23_Obj_7071:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  518,    0
    subsprite OAM_SIZE_8x8,      7,   -8,  548,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 2438,    0, xflip=1
  FileDE23_Obj_7077:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1602,    0
    subsprite OAM_SIZE_8x8,     -1,    1, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  520,    0
    subsprite OAM_SIZE_8x8,      3,   -8,  548,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 2438,    0, xflip=1
  FileDE23_Obj_7083:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1608,    0
    subsprite OAM_SIZE_8x8,     -4,    0, 1327,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 2438,    0, xflip=1
  FileDE23_Obj_7088:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1610,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1325,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2438,    0, xflip=1
  FileDE23_Obj_7093:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1612,    0
    subsprite OAM_SIZE_8x8,     -1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 2438,    0, xflip=1
  FileDE23_Obj_7098:
    subsprite OAM_SIZE_8x16,     1,  -20, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -15, 1614,    0
    subsprite OAM_SIZE_8x8,    -11,    1, 1326,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -24,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -34, 2438,    0, xflip=1
  FileDE23_Obj_7103:
    subsprite OAM_SIZE_8x16,     1,  -21, 2184,    0
    subsprite OAM_SIZE_16x16,   -6,  -16, 1606,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1294,    0
    subsprite OAM_SIZE_16x16,   -5,  -25,  512,    0
    subsprite OAM_SIZE_16x16,   -5,  -35, 2438,    0, xflip=1
  FileDE23_Obj_7108:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -33, 2464,    0, xflip=1
  FileDE23_Obj_7114:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1634,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  524,    0
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2464,    0, xflip=1
  FileDE23_Obj_7120:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  526,    0
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2464,    0, xflip=1
  FileDE23_Obj_7126:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  544,    0
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -33, 2464,    0, xflip=1
  FileDE23_Obj_7132:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1632,    0
    subsprite OAM_SIZE_8x8,     -8,    2, 1307,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -22,  546,    0
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -14,  -11,  564,    0
    subsprite OAM_SIZE_16x16,   -5,  -33, 2464,    0, xflip=1
  FileDE23_Obj_7139:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1638,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2464,    0, xflip=1
  FileDE23_Obj_7145:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1640,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -33, 2464,    0, xflip=1
  FileDE23_Obj_7150:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1642,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2464,    0, xflip=1
  FileDE23_Obj_7155:
    subsprite OAM_SIZE_16x16,   -7,  -13, 1644,    0
    subsprite OAM_SIZE_16x16,   -6,  -22,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -18, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,    3, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -33, 2464,    0, xflip=1
  FileDE23_Obj_7161:
    subsprite OAM_SIZE_16x16,   -7,  -14, 1636,    0
    subsprite OAM_SIZE_8x8,     -6,    2, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -23,  522,    0
    subsprite OAM_SIZE_8x16,     1,  -19, 2185,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -34, 2464,    0, xflip=1
  FileDE23_Obj_7167:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1646,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  549,    0
    subsprite OAM_SIZE_8x16,    -8,  -22, 2216,    0
    subsprite OAM_SIZE_16x8,     2,  -17, 2198,    0
    subsprite OAM_SIZE_16x16,   -9,  -36, 2502,    0
    subsprite OAM_SIZE_8x16,     7,  -36, 2504,    0
  FileDE23_Obj_7173:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1664,    0
    subsprite OAM_SIZE_8x8,      0,    1, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -25,  551,    0
    subsprite OAM_SIZE_16x16,   -9,  -19, 2186,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2466,    0
  FileDE23_Obj_7178:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1666,    0
    subsprite OAM_SIZE_8x8,     -2,    3, 1291,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  553,    0
    subsprite OAM_SIZE_16x16,  -14,  -19, 2188,    0
    subsprite OAM_SIZE_16x16,   -6,  -32, 2505,    0
  FileDE23_Obj_7183:
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_16x16,    4,  -24, 2507,    0
    subsprite OAM_SIZE_8x8,     12,   -8, 2495,    0
    subsprite OAM_SIZE_16x16,   -5,  -25, 2190,    0
  FileDE23_Obj_7191:
    subsprite OAM_SIZE_16x16,   -4,  -13,  557,    0
    subsprite OAM_SIZE_8x8,      3,  -21,  577,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  593,    0
    subsprite OAM_SIZE_8x8,     12,  -11,  578,    0
    subsprite OAM_SIZE_8x8,    -12,    1,  594,    0
    subsprite OAM_SIZE_16x16,    4,  -25, 2509,    0
    subsprite OAM_SIZE_8x8,     12,   -9, 2495,    0
    subsprite OAM_SIZE_16x8,    -8,  -20, 2217,    0
    subsprite OAM_SIZE_8x8,      3,  -12, 2219,    0
  FileDE23_Obj_7200:
    subsprite OAM_SIZE_16x16,   -4,  -12,  555,    0
    subsprite OAM_SIZE_8x8,      3,  -20,  559,    0
    subsprite OAM_SIZE_8x8,    -12,   -4,  575,    0
    subsprite OAM_SIZE_8x8,     12,  -10,  576,    0
    subsprite OAM_SIZE_16x16,    4,  -24, 2507,    0
    subsprite OAM_SIZE_8x8,     12,   -8, 2495,    0
    subsprite OAM_SIZE_8x8,    -11,    3,  592,    0
    subsprite OAM_SIZE_16x8,    -5,  -15, 2221,    0
    subsprite OAM_SIZE_8x8,    -13,  -15, 2220,    0
    subsprite OAM_SIZE_8x16,     3,   -7, 2223,    0
  FileDE23_Obj_7210:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1668,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1338,    0
    subsprite OAM_SIZE_16x16,   -8,  -25,  579,    0
    subsprite OAM_SIZE_8x8,      8,  -24,  585,    0
    subsprite OAM_SIZE_8x8,    -16,  -19,  601,    0
    subsprite OAM_SIZE_16x8,     5,  -18, 2225,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 2054,    0
    subsprite OAM_SIZE_8x16,    -9,  -16, 2224,    0
    subsprite OAM_SIZE_8x8,      8,  -31, 2431,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 2429,    0
  FileDE23_Obj_7220:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1670,    0
    subsprite OAM_SIZE_8x8,     -2,    1, 1293,    0
    subsprite OAM_SIZE_16x16,  -11,  -24,  581,    0
    subsprite OAM_SIZE_8x8,      5,  -23,  586,    0
    subsprite OAM_SIZE_8x8,      4,  -17, 2228,    0
    subsprite OAM_SIZE_8x16,    -9,  -16, 2227,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2460,    0
  FileDE23_Obj_7227:
    subsprite OAM_SIZE_16x8,   -15,  -23, 2241,    0
    subsprite OAM_SIZE_8x8,    -12,  -15, 2244,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1672,    0
    subsprite OAM_SIZE_16x16,   -7,  -22,  583,    0
    subsprite OAM_SIZE_8x8,      9,  -14,  602,    0
    subsprite OAM_SIZE_8x8,      8,  -29, 2447,    0
    subsprite OAM_SIZE_16x16,   -8,  -32, 2462,    0
  FileDE23_Obj_7234:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,      3,   -3, 2231,    0
    subsprite OAM_SIZE_16x16,   -5,  -19, 2229,    0
    subsprite OAM_SIZE_16x16,    4,   -1, 2530,    0
    subsprite OAM_SIZE_8x8,     -4,    7, 2494,    0
  FileDE23_Obj_7243:
    subsprite OAM_SIZE_16x16,   -5,   -9,  589,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  609,    0
    subsprite OAM_SIZE_8x8,      1,    7,  625,    0
    subsprite OAM_SIZE_8x8,    -10,  -17,  610,    0
    subsprite OAM_SIZE_8x8,     11,   -1,  626,    0
    subsprite OAM_SIZE_8x16,     3,  -16, 2234,    0
    subsprite OAM_SIZE_8x8,     -1,   -4, 2249,    0
    subsprite OAM_SIZE_8x8,     -9,   -8, 2233,    0
    subsprite OAM_SIZE_16x16,    4,   -2, 2528,    0
    subsprite OAM_SIZE_8x8,     -4,    6, 2494,    0
  FileDE23_Obj_7253:
    subsprite OAM_SIZE_16x16,   -5,   -8,  587,    0
    subsprite OAM_SIZE_8x8,    -13,  -10,  591,    0
    subsprite OAM_SIZE_8x8,      1,    8,  607,    0
    subsprite OAM_SIZE_8x8,     -6,  -16,  608,    0
    subsprite OAM_SIZE_8x8,     11,    0,  624,    0
    subsprite OAM_SIZE_8x16,     4,  -11, 2235,    0
    subsprite OAM_SIZE_8x8,      4,  -19, 2053,    0, yflip=1
    subsprite OAM_SIZE_16x8,   -12,   -3, 2247,    0
    subsprite OAM_SIZE_16x16,    4,   -1, 2530,    0
    subsprite OAM_SIZE_8x8,     -4,    7, 2494,    0
  FileDE23_Obj_7263:
    subsprite OAM_SIZE_8x8,    -14,   -1, 2236,    0
    subsprite OAM_SIZE_8x16,    -6,   -7, 2237,    0
    subsprite OAM_SIZE_8x16,     2,   -9, 2238,    0
    subsprite OAM_SIZE_8x8,    -10,  -10,  265,    0
    subsprite OAM_SIZE_8x8,      1,    2,  510,    0
    subsprite OAM_SIZE_16x16,  -12,   -9,  611,    0
    subsprite OAM_SIZE_8x8,     -3,  -17,  615,    0
    subsprite OAM_SIZE_8x8,      3,  -13,  616,    0
    subsprite OAM_SIZE_8x8,    -20,   -4,  631,    0
    subsprite OAM_SIZE_8x8,     -7,    7,  632,    0
    subsprite OAM_SIZE_16x16,  -21,    1, 2532,    0
  FileDE23_Obj_7274:
    subsprite OAM_SIZE_8x8,    -15,    0, 2252,    0
    subsprite OAM_SIZE_8x16,    -7,   -7, 2256,    0
    subsprite OAM_SIZE_8x16,     1,   -9, 2238,    0
    subsprite OAM_SIZE_8x8,      2,    4,  510,    0
    subsprite OAM_SIZE_8x8,     -1,  -14,  615,    0
    subsprite OAM_SIZE_16x16,  -11,   -8,  613,    0
    subsprite OAM_SIZE_8x8,    -19,   -3,  617,    0
    subsprite OAM_SIZE_16x8,    -7,    8,  633,    0
    subsprite OAM_SIZE_8x8,      5,  -10,  616,    0
    subsprite OAM_SIZE_8x8,    -10,   15,  297,    0
    subsprite OAM_SIZE_16x16,  -21,    2, 2534,    0
  FileDE23_Obj_7285:
    subsprite OAM_SIZE_16x16,   -9,  -10, 1674,    0
    subsprite OAM_SIZE_16x16,  -11,  -11,  619,    0
    subsprite OAM_SIZE_8x8,     -1,    5,  618,    0
    subsprite OAM_SIZE_8x16,   -11,   -7, 2257,    0
    subsprite OAM_SIZE_8x8,    -19,   -7, 2255,    0
    subsprite OAM_SIZE_16x16,  -13,  -21, 2464,    0
  FileDE23_Obj_7291:
    subsprite OAM_SIZE_16x16,   -8,  -11, 1676,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  621,    0
    subsprite OAM_SIZE_8x16,   -10,  -16, 2092,    0
    subsprite OAM_SIZE_8x16,    -6,  -14, 2093,    0
    subsprite OAM_SIZE_16x16,   -6,  -29, 2505,    0
  FileDE23_Obj_7296:
    subsprite OAM_SIZE_8x8,    -11,  -17, 2258,    0
    subsprite OAM_SIZE_16x8,   -11,   -9, 2274,    0
    subsprite OAM_SIZE_16x8,    -9,   -1, 2260,    0
    subsprite OAM_SIZE_16x16,  -20,  -23, 2536,    0
    subsprite OAM_SIZE_16x16,  -11,  -17,  640,    0
    subsprite OAM_SIZE_8x8,      3,   -9,  644,    0
    subsprite OAM_SIZE_8x8,     -1,   -3,  660,    0
    subsprite OAM_SIZE_8x8,    -19,  -11,  623,    0
  FileDE23_Obj_7304:
    subsprite OAM_SIZE_8x8,     -7,  -17, 2259,    0
    subsprite OAM_SIZE_16x8,   -11,   -9, 2276,    0
    subsprite OAM_SIZE_16x8,    -8,   -1, 2260,    0
    subsprite OAM_SIZE_16x16,  -20,  -22, 2538,    0
    subsprite OAM_SIZE_16x16,  -11,  -14,  642,    0
    subsprite OAM_SIZE_8x8,      5,   -4,  644,    0
    subsprite OAM_SIZE_8x8,      1,    2,  660,    0
    subsprite OAM_SIZE_8x16,   -19,  -10,  645,    0
    subsprite OAM_SIZE_8x8,     -8,  -22,  639,    0
  FileDE23_Obj_7313:
    subsprite OAM_SIZE_16x16,  -16,  -16, 2262,    0
    subsprite OAM_SIZE_16x16,   -9,  -11, 1678,    0
    subsprite OAM_SIZE_8x8,     -4,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -19,  646,    0
    subsprite OAM_SIZE_8x8,    -18,   -3,  618,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -13,  -28, 2438,    0
  FileDE23_Obj_7319:
    subsprite OAM_SIZE_8x16,    -7,  -16, 2126,    0
    subsprite OAM_SIZE_16x16,   -8,  -11, 1696,    0
    subsprite OAM_SIZE_16x16,   -7,  -18,  648,    0
    subsprite OAM_SIZE_8x8,      9,   -9,  281,    0
    subsprite OAM_SIZE_16x16,   -6,  -28, 2540,    0
    subsprite OAM_SIZE_8x8,     -4,  -12, 2495,    0
    subsprite OAM_SIZE_8x8,      3,  -13, 2495,    0
  FileDE23_Obj_7326:
    subsprite OAM_SIZE_16x16,   -8,  -15, 1698,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  650,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 2916,    0
    subsprite OAM_SIZE_8x8,    -12,  -40, 2288,    0
    subsprite OAM_SIZE_8x8,     -9,  -32, 2289,    0
    subsprite OAM_SIZE_8x8,     -6,  -24, 2290,    0
  FileDE23_Obj_7332:
    subsprite OAM_SIZE_16x16,   -8,  -16, 1700,    0
    subsprite OAM_SIZE_8x8,      1,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -24,  652,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2918,    0
    subsprite OAM_SIZE_8x8,     -8,  -41, 2291,    0
    subsprite OAM_SIZE_16x8,    -9,  -33, 2292,    0
    subsprite OAM_SIZE_8x8,     -8,  -25, 2294,    0
  FileDE23_Obj_7339:
    subsprite OAM_SIZE_8x16,    -6,  -37, 2265,    0
    subsprite OAM_SIZE_8x8,     -8,  -45, 2296,    0
    subsprite OAM_SIZE_16x16,   -8,  -15, 1702,    0
    subsprite OAM_SIZE_8x8,     -7,    1, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -24,  654,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 2912,    0
    subsprite OAM_SIZE_8x16,   -11,  -35, 2264,    0
    subsprite OAM_SIZE_8x8,    -12,  -43, 2295,    0
  FileDE23_Obj_7349:
    subsprite OAM_SIZE_8x8,     -3,  -46, 2298,    0
    subsprite OAM_SIZE_8x16,    -5,  -38, 2267,    0
    subsprite OAM_SIZE_16x16,   -8,  -16, 1704,    0
    subsprite OAM_SIZE_8x8,     -3,    0, 1327,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  672,    0
    subsprite OAM_SIZE_8x8,      8,  -22,  674,    0
    subsprite OAM_SIZE_8x8,    -16,  -18,  690,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 2914,    0
    subsprite OAM_SIZE_8x16,    -9,  -36, 2266,    0
    subsprite OAM_SIZE_8x8,     -7,  -44, 2297,    0
  FileDE23_Obj_7359:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2284,    0
    subsprite OAM_SIZE_8x8,     -4,   -3, 2299,    0
    subsprite OAM_SIZE_8x8,     -7,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -19,  675,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x8,      0,   -3,  697,    0
    subsprite OAM_SIZE_8x8,      5,   -3,  698,    0
    subsprite OAM_SIZE_8x8,    -10,  -13,  297,    0
    subsprite OAM_SIZE_16x16,  -18,  -29, 2922,    0
  FileDE23_Obj_7369:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2270,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2299,    0
    subsprite OAM_SIZE_8x8,     -6,  -10,  271,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -19,  677,    0
    subsprite OAM_SIZE_8x8,     -5,  -27,  681,    0
    subsprite OAM_SIZE_8x16,   -16,  -16,  683,    0
    subsprite OAM_SIZE_8x8,      2,   -3,  684,    0
    subsprite OAM_SIZE_8x8,      8,   -7,  685,    0
    subsprite OAM_SIZE_16x16,  -16,  -29, 2924,    0
  FileDE23_Obj_7379:
    subsprite OAM_SIZE_16x8,    -8,  -19, 2268,    0
    subsprite OAM_SIZE_16x8,    -7,  -11, 2286,    0
    subsprite OAM_SIZE_8x8,     -2,   -3, 2299,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  679,    0
    subsprite OAM_SIZE_16x8,    -5,  -27,  700,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  682,    0
    subsprite OAM_SIZE_8x8,      8,   -9,  686,    0
    subsprite OAM_SIZE_8x8,      4,   -3,  702,    0
    subsprite OAM_SIZE_8x8,      8,  -17,  495,    0
    subsprite OAM_SIZE_16x16,  -14,  -30, 2460,    0
  FileDE23_Obj_7389:
    subsprite OAM_SIZE_8x8,    -12,  -13, 2252,    0
    subsprite OAM_SIZE_8x16,    -4,  -20, 2256,    0
    subsprite OAM_SIZE_8x16,     4,  -22, 2238,    0
    subsprite OAM_SIZE_8x8,      5,   -9,  510,    0
    subsprite OAM_SIZE_8x8,      2,  -27,  615,    0
    subsprite OAM_SIZE_16x16,   -8,  -21,  613,    0
    subsprite OAM_SIZE_8x8,    -16,  -16,  617,    0
    subsprite OAM_SIZE_16x8,    -4,   -5,  633,    0
    subsprite OAM_SIZE_8x8,      8,  -23,  616,    0
    subsprite OAM_SIZE_16x16,  -18,  -11, 2532,    0
  FileDE23_Obj_7399:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1706,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -25,  704,    0
    subsprite OAM_SIZE_8x8,      7,  -24,  687,    0
    subsprite OAM_SIZE_8x16,    -1,  -18, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -5,   -2, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 2944,    0
  FileDE23_Obj_7406:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_8x16,     1,  -16, 2090,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -3,  -15, 2091,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 2944,    0
  FileDE23_Obj_7413:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_16x16,   -3,  -17, 2112,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 2944,    0
  FileDE23_Obj_7419:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1710,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  708,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  711,    0
    subsprite OAM_SIZE_16x16,   -2,  -17, 2116,    0, xflip=1
    subsprite OAM_SIZE_8x8,      7,   -1, 2055,    0
    subsprite OAM_SIZE_16x16,  -10,  -32, 2946,    0
  FileDE23_Obj_7426:
    subsprite OAM_SIZE_16x16,  -10,  -11, 1708,    0
    subsprite OAM_SIZE_8x8,    -12,    5, 1291,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -12,  -21,  706,    0
    subsprite OAM_SIZE_8x16,    -1,  -33,  710,    0
    subsprite OAM_SIZE_8x16,    -3,  -16, 2049,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -7,    0, 2053,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -32, 2944,    0
  FileDE23_Obj_7433:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1728,    0
    subsprite OAM_SIZE_8x8,      2,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -7,  -26,  712,    0
    subsprite OAM_SIZE_8x8,    -15,  -20,  703,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 2948,    0
  FileDE23_Obj_7439:
    subsprite OAM_SIZE_8x16,    -9,  -17, 2125,    0
    subsprite OAM_SIZE_8x8,    -17,   -9, 2195,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -31, 2948,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_7447:
    subsprite OAM_SIZE_16x16,  -18,  -25, 2176,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -31, 2948,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_7454:
    subsprite OAM_SIZE_16x8,   -18,  -22, 2180,    0
    subsprite OAM_SIZE_8x8,    -17,  -14, 2071,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1732,    0
    subsprite OAM_SIZE_8x8,     -8,    5, 1339,    0
    subsprite OAM_SIZE_16x16,  -10,  -31, 2950,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  716,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  734,    0
  FileDE23_Obj_7461:
    subsprite OAM_SIZE_8x16,    -9,  -16, 2051,    0
    subsprite OAM_SIZE_16x16,  -10,  -11, 1730,    0
    subsprite OAM_SIZE_8x8,    -13,    5, 1294,    0, xflip=1
    subsprite OAM_SIZE_16x16,  -10,  -31, 2948,    0
    subsprite OAM_SIZE_16x16,   -8,  -24,  714,    0
    subsprite OAM_SIZE_8x8,    -11,  -32,  718,    0
    subsprite OAM_SIZE_8x8,     -9,  -18,  297,    0
  FileDE23_Obj_7468:
    subsprite OAM_SIZE_16x16,   -7,  -15, 1734,    0
    subsprite OAM_SIZE_8x8,      1,    1, 1306,    0
    subsprite OAM_SIZE_16x16,   -8,  -28,  736,    0
    subsprite OAM_SIZE_8x8,      8,  -20,  719,    0
    subsprite OAM_SIZE_8x16,    -3,  -19, 2048,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2464,    0
  FileDE23_Obj_7474:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -20, 2058,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 2464,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
  FileDE23_Obj_7481:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -6,  -20, 2080,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 2464,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
  FileDE23_Obj_7488:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1738,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  740,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_16x16,   -7,  -20, 2084,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 2466,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  743,    0
  FileDE23_Obj_7495:
    subsprite OAM_SIZE_16x16,   -6,  -16, 1736,    0
    subsprite OAM_SIZE_8x8,      4,    0, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -29,  738,    0
    subsprite OAM_SIZE_8x8,    -16,  -15,  735,    0
    subsprite OAM_SIZE_8x16,    -2,  -20, 2048,    0
    subsprite OAM_SIZE_16x16,   -7,  -36, 2464,    0
    subsprite OAM_SIZE_8x16,     8,  -32,  742,    0
  FileDE23_Obj_7502:
    subsprite OAM_SIZE_8x8,    -15,  -25, 1079,    0, xflip=1, yflip=1
    subsprite OAM_SIZE_8x16,     3,  -29, 1037,    0
    subsprite OAM_SIZE_8x16,     2,  -36, 1740,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_8x8,    -11,  -21, 1080,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 2434,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2060,    0
  FileDE23_Obj_7510:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -4,  -41, 1740,    0
    subsprite OAM_SIZE_8x16,     3,  -31,  992,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -9,  -25, 1100,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 2432,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 2048,    0
  FileDE23_Obj_7517:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1794,    0
    subsprite OAM_SIZE_16x16,   -8,  -22, 1004,    0
    subsprite OAM_SIZE_8x16,    -4,  -40, 1740,    0
    subsprite OAM_SIZE_8x16,     3,  -30,  992,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -9,  -24, 1100,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34, 2432,    0
    subsprite OAM_SIZE_16x16,   -8,  -17, 2058,    0
  FileDE23_Obj_7524:
    subsprite OAM_SIZE_8x8,     -7,  -22, 1063,    0
    subsprite OAM_SIZE_16x16,    2,  -30, 1742,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_8x8,      6,  -18,  863,    0
    subsprite OAM_SIZE_8x8,     -6,  -14,  195,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2466,    0
    subsprite OAM_SIZE_8x8,      2,  -20,  949,    0
    subsprite OAM_SIZE_8x16,   -11,  -19, 2092,    0
    subsprite OAM_SIZE_8x16,    -7,  -16, 2093,    0
  FileDE23_Obj_7534:
    subsprite OAM_SIZE_8x8,     -7,  -26, 1063,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    1,  -38, 1742,    0
    subsprite OAM_SIZE_8x8,     -6,  -14,  195,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2464,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
  FileDE23_Obj_7543:
    subsprite OAM_SIZE_8x8,     -8,  -25, 1063,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,    0,  -37, 1742,    0
    subsprite OAM_SIZE_8x8,     -6,  -14,  195,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  960,    0
    subsprite OAM_SIZE_8x16,     0,  -30,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2464,    0
    subsprite OAM_SIZE_8x16,   -10,  -19, 2090,    0
    subsprite OAM_SIZE_8x16,    -7,  -17, 2091,    0
  FileDE23_Obj_7552:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,    0,  -23, 1760,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2498,    0
    subsprite OAM_SIZE_8x8,    -17,  -34, 2492,    0
    subsprite OAM_SIZE_8x8,     -1,  -18,  247,    0
    subsprite OAM_SIZE_8x8,     -7,   -3, 2055,    0
    subsprite OAM_SIZE_8x16,    -8,  -19, 2122,    0
  FileDE23_Obj_7560:
    subsprite OAM_SIZE_16x8,     0,  -22, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -17,  -33, 2492,    0
    subsprite OAM_SIZE_16x16,    5,  -29, 1760,    0
    subsprite OAM_SIZE_16x8,     0,  -19,  898,    0
    subsprite OAM_SIZE_8x8,     -7,   -2, 2055,    0
    subsprite OAM_SIZE_8x16,    -7,  -18, 2050,    0
  FileDE23_Obj_7569:
    subsprite OAM_SIZE_16x8,    -1,  -22, 1082,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1806,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2496,    0
    subsprite OAM_SIZE_8x8,    -17,  -33, 2492,    0
    subsprite OAM_SIZE_16x16,    4,  -29, 1760,    0
    subsprite OAM_SIZE_16x8,    -1,  -19,  898,    0
    subsprite OAM_SIZE_8x16,    -9,  -18, 2121,    0
  FileDE23_Obj_7577:
    subsprite OAM_SIZE_8x16,    -8,  -19, 2126,    0
    subsprite OAM_SIZE_8x8,      0,  -23, 1063,    0
    subsprite OAM_SIZE_8x8,      6,  -17, 1051,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 1103,    0
    subsprite OAM_SIZE_16x16,   -7,  -18, 1762,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2440,    0
    subsprite OAM_SIZE_8x8,      1,  -10, 2926,    1
    subsprite OAM_SIZE_8x8,     -7,  -18, 2527,    1
  FileDE23_Obj_7587:
    subsprite OAM_SIZE_8x16,    -7,  -18, 2051,    0
    subsprite OAM_SIZE_8x8,      1,  -22, 1063,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,     -4,  -18,  914,    0
    subsprite OAM_SIZE_8x8,      5,  -12,  915,    0
    subsprite OAM_SIZE_16x16,    1,  -19, 1762,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2438,    0
    subsprite OAM_SIZE_8x8,      1,  -19, 2527,    1
    subsprite OAM_SIZE_8x8,      9,  -11, 2926,    1
  FileDE23_Obj_7597:
    subsprite OAM_SIZE_8x8,    -15,  -11, 2195,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2125,    0
    subsprite OAM_SIZE_8x8,      0,  -23, 1063,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1828,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,      4,  -13,  915,    0
    subsprite OAM_SIZE_16x16,    0,  -20, 1762,    0
    subsprite OAM_SIZE_8x8,     -5,  -19,  914,    0
    subsprite OAM_SIZE_8x8,      8,  -12, 2926,    1
    subsprite OAM_SIZE_8x8,      0,  -20, 2527,    1
    subsprite OAM_SIZE_16x16,   -9,  -32, 2438,    0
  FileDE23_Obj_7608:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_8x8,      3,  -20, 1088,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2472,    0
    subsprite OAM_SIZE_8x8,     -1,  -40, 2493,    0
    subsprite OAM_SIZE_8x16,   -10,  -20, 1741,    0
    subsprite OAM_SIZE_8x8,      7,  -15,  284,    0
    subsprite OAM_SIZE_8x8,    -10,  -20, 2511,    1
  FileDE23_Obj_7617:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_8x16,    -8,  -21, 2428,    0
    subsprite OAM_SIZE_8x16,     0,  -21, 2428,    0, xflip=1
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2472,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_8x16,    -4,  -16, 1741,    0
    subsprite OAM_SIZE_8x8,     -4,  -16, 2511,    1
  FileDE23_Obj_7626:
    subsprite OAM_SIZE_16x16,   -8,  -13, 1834,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_8x8,      1,    3, 1293,    0
    subsprite OAM_SIZE_8x16,     0,  -22, 2428,    0, xflip=1
    subsprite OAM_SIZE_8x16,    -8,  -22, 2428,    0
    subsprite OAM_SIZE_16x16,   -9,  -32, 2472,    0
    subsprite OAM_SIZE_8x8,     -1,  -39, 2493,    0
    subsprite OAM_SIZE_8x16,    -4,  -17, 1741,    0
    subsprite OAM_SIZE_8x8,     -4,  -17, 2511,    1
  FileDE23_Obj_7635:
    subsprite OAM_SIZE_8x8,      1,    2, 1290,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1280,    0
    subsprite OAM_SIZE_8x16,     7,  -18,  258,    0
    subsprite OAM_SIZE_16x16,   -9,  -23,  256,    0
    subsprite OAM_SIZE_8x16,    -4,  -18, 2048,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 2920,    0
  FileDE23_Obj_7641:
    subsprite OAM_SIZE_16x16,   -8,  -29, 2920,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -17,  210,    0
    subsprite OAM_SIZE_16x8,    -6,   -1,  242,    0
  FileDE23_Obj_7647:
    subsprite OAM_SIZE_16x8,    -6,   -1,  242,    0
    subsprite OAM_SIZE_16x8,    -6,   -3,  240,    0
    subsprite OAM_SIZE_16x16,   -6,  -19,  208,    0
    subsprite OAM_SIZE_8x16,   -11,  -18,  160,    0
    subsprite OAM_SIZE_16x16,   -6,  -17,  210,    0
    subsprite OAM_SIZE_16x16,   -8,  -29, 2432,    0
  FileDE23_Obj_7653:
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -6,  -23,  259,    0
    subsprite OAM_SIZE_16x16,   -8,  -33, 2505,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
  FileDE23_Obj_7659:
    subsprite OAM_SIZE_16x16,   -6,  -27, 2505,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  214,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  246,    0
  FileDE23_Obj_7664:
    subsprite OAM_SIZE_16x8,    -8,   -3,  244,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  246,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  212,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  214,    0
    subsprite OAM_SIZE_16x16,   -7,  -28, 2464,    0
  FileDE23_Obj_7669:
    subsprite OAM_SIZE_8x8,     -2,    2, 1292,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -5,  -24,  261,    0
    subsprite OAM_SIZE_8x8,     -3,   -8,  274,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_8x8,    -15,  -33,  195,    0
    subsprite OAM_SIZE_16x16,   -7,  -32, 2542,    0
  FileDE23_Obj_7676:
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  218,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  250,    0
    subsprite OAM_SIZE_8x8,    -13,  -26,  195,    0
    subsprite OAM_SIZE_8x8,      3,  -14,  192,    0
    subsprite OAM_SIZE_16x16,   -5,  -25, 2542,    0
  FileDE23_Obj_7683:
    subsprite OAM_SIZE_8x8,     -8,   -3,  250,    0
    subsprite OAM_SIZE_16x16,   -7,  -19,  216,    0
    subsprite OAM_SIZE_16x8,    -7,   -3,  248,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  218,    0
    subsprite OAM_SIZE_16x16,   -7,  -27, 2496,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 2492,    0
  FileDE23_Obj_7689:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  263,    0
    subsprite OAM_SIZE_8x8,      8,  -14,  281,    0
    subsprite OAM_SIZE_8x8,      2,  -20, 2495,    0
    subsprite OAM_SIZE_8x8,     -5,  -19, 2495,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 2892,    0
  FileDE23_Obj_7697:
    subsprite OAM_SIZE_8x16,    -8,  -19,  221,    0
    subsprite OAM_SIZE_8x8,     -8,   -3,  253,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
    subsprite OAM_SIZE_8x8,     -3,  -11, 2495,    0
    subsprite OAM_SIZE_8x8,      4,  -12, 2495,    0
    subsprite OAM_SIZE_16x16,   -5,  -27, 2892,    0
  FileDE23_Obj_7705:
    subsprite OAM_SIZE_8x8,     -8,   -3,  253,    0
    subsprite OAM_SIZE_16x8,    -8,   -3,  251,    0
    subsprite OAM_SIZE_8x16,    -8,  -19,  221,    0
    subsprite OAM_SIZE_16x16,   -8,  -19,  219,    0
    subsprite OAM_SIZE_8x8,      4,  -11,  193,    0
    subsprite OAM_SIZE_16x16,   -7,  -25, 2438,    0
  FileDE23_Obj_7711:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,  -10,  -23,  266,    0
    subsprite OAM_SIZE_8x16,     6,  -20,  268,    0
    subsprite OAM_SIZE_8x8,     -9,  -18, 2495,    0
    subsprite OAM_SIZE_8x8,      0,  -18, 2495,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 2894,    0
  FileDE23_Obj_7719:
    subsprite OAM_SIZE_8x8,    -10,   -9,  254,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
    subsprite OAM_SIZE_16x16,   -8,  -26, 2894,    0
    subsprite OAM_SIZE_8x8,      0,  -10, 2495,    0
    subsprite OAM_SIZE_8x8,     -9,  -10, 2495,    0
  FileDE23_Obj_7726:
    subsprite OAM_SIZE_8x8,    -10,   -9,  254,    0
    subsprite OAM_SIZE_16x16,  -10,  -17,  222,    0
    subsprite OAM_SIZE_8x8,     -2,   -1,  255,    0
    subsprite OAM_SIZE_8x16,     2,  -15,  161,    0
    subsprite OAM_SIZE_16x16,   -9,  -25, 2470,    0
    subsprite OAM_SIZE_8x8,     -1,  -32, 2493,    0
  FileDE23_Obj_7732:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_8x8,      0,  -14,  957,    0
    subsprite OAM_SIZE_16x8,     5,  -26, 2956,    0
    subsprite OAM_SIZE_16x8,    -5,  -16, 2974,    0
    subsprite OAM_SIZE_16x8,    -3,  -18, 2974,    0
    subsprite OAM_SIZE_8x8,     -5,   -8, 2973,    0
    subsprite OAM_SIZE_8x16,    -6,  -18,  940,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   32,    0
  FileDE23_Obj_7744:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -8,  -18, 2121,    0
    subsprite OAM_SIZE_8x8,      7,  -16,  942,    0
    subsprite OAM_SIZE_8x8,      2,  -16, 2973,    0
    subsprite OAM_SIZE_16x8,     2,  -24, 2974,    0
    subsprite OAM_SIZE_16x8,     4,  -26, 2974,    0
    subsprite OAM_SIZE_16x8,    12,  -34, 2956,    0
    subsprite OAM_SIZE_8x8,      2,  -13, 1071,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
  FileDE23_Obj_7755:
    subsprite OAM_SIZE_8x8,      4,  -25,  593,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     11,  -20,  942,    0
    subsprite OAM_SIZE_16x8,    16,  -38, 2956,    0
    subsprite OAM_SIZE_16x8,     6,  -28, 2974,    0
    subsprite OAM_SIZE_16x8,     8,  -30, 2974,    0
    subsprite OAM_SIZE_8x8,      6,  -20, 2973,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
    subsprite OAM_SIZE_8x8,      2,  -21, 1119,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -1,  -20, 1066,    0
  FileDE23_Obj_7767:
    subsprite OAM_SIZE_8x8,      4,  -26,  593,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x16,    -6,  -18, 2050,    0
    subsprite OAM_SIZE_8x8,     11,  -21,  942,    0
    subsprite OAM_SIZE_16x8,    16,  -39, 2956,    0
    subsprite OAM_SIZE_16x8,     6,  -29, 2974,    0
    subsprite OAM_SIZE_16x8,     8,  -31, 2974,    0
    subsprite OAM_SIZE_8x8,      6,  -21, 2973,    0
    subsprite OAM_SIZE_8x8,      2,  -22, 1119,    0, yflip=1
    subsprite OAM_SIZE_8x8,      0,  -20, 1066,    0
    subsprite OAM_SIZE_16x16,   -8,  -34,   32,    0
  FileDE23_Obj_7779:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -2,  -23,  941,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2050,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x8,     -1,  -13,  957,    0
    subsprite OAM_SIZE_16x8,     4,  -25, 2956,    0
    subsprite OAM_SIZE_16x8,    -6,  -15, 2974,    0
    subsprite OAM_SIZE_16x8,    -4,  -17, 2974,    0
    subsprite OAM_SIZE_8x8,     -6,   -7, 2973,    0
    subsprite OAM_SIZE_8x16,    -7,  -17,  940,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   32,    0
  FileDE23_Obj_7791:
    subsprite OAM_SIZE_8x16,    -7,  -20, 2125,    0
    subsprite OAM_SIZE_8x8,    -15,  -12, 2195,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -12,  -13, 2952,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,  964,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  965,    0
    subsprite OAM_SIZE_8x8,    -17,  -30,  194,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   64,    0
    subsprite OAM_SIZE_8x8,     -4,   -9,  284,    0
    subsprite OAM_SIZE_16x8,     6,  -13, 2954,    0
  FileDE23_Obj_7802:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x8,      3,   -2, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -7,  -12, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -15,  -20, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,  -25,  982,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  975,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  284,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   96,    0
    subsprite OAM_SIZE_16x8,    -5,  -10, 2958,    0, xflip=1
  FileDE23_Obj_7813:
    subsprite OAM_SIZE_8x16,     0,  -20, 2051,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -20,  999,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  981,    0
    subsprite OAM_SIZE_8x32,    -9,  -27, 2991,    0
    subsprite OAM_SIZE_8x8,     -6,  -28,  991,    0
    subsprite OAM_SIZE_16x16,   -7,  -35,  128,    0
    subsprite OAM_SIZE_8x16,    -9,   -9, 3023,    0
  FileDE23_Obj_7823:
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x8,      4,   -1, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -6,  -11, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -14,  -19, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -11,  -24,  982,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  975,    0
    subsprite OAM_SIZE_16x16,   -9,  -35,   96,    0
    subsprite OAM_SIZE_8x8,     -8,  -13,  284,    0
    subsprite OAM_SIZE_16x8,    -4,   -9, 2958,    0, xflip=1
  FileDE23_Obj_7835:
    subsprite OAM_SIZE_16x16,   -8,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_8x8,      1,  -14, 1008,    0
    subsprite OAM_SIZE_16x8,    -7,  -14, 2942,    0, xflip=1
    subsprite OAM_SIZE_16x8,     1,   -6, 2958,    0, xflip=1
    subsprite OAM_SIZE_8x8,     11,    4, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -34,   96,    0
    subsprite OAM_SIZE_8x8,     -6,  -14, 1104,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1103,    0
    subsprite OAM_SIZE_8x8,     -2,   -9,  284,    0
    subsprite OAM_SIZE_16x8,     3,   -4, 2958,    0, xflip=1
  FileDE23_Obj_7848:
    subsprite OAM_SIZE_16x16,   -5,  -18, 2156,    0
    subsprite OAM_SIZE_16x16,   -6,  -11, 1414,    0
    subsprite OAM_SIZE_16x16,   -5,  -18, 1032,    0
    subsprite OAM_SIZE_16x8,     2,   -5, 2942,    0, xflip=1
    subsprite OAM_SIZE_16x8,    10,    3, 2958,    0, xflip=1
    subsprite OAM_SIZE_8x8,     20,   13, 2927,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -17, 1003,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -4,  -28,   96,    0
    subsprite OAM_SIZE_8x8,     -4,  -13,  940,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,   -6, 1009,    0
    subsprite OAM_SIZE_16x8,    12,    5, 2958,    0, xflip=1
  FileDE23_Obj_7859:
    subsprite OAM_SIZE_16x16,   -5,  -18, 2156,    0
    subsprite OAM_SIZE_16x16,   -6,  -11, 1414,    0
    subsprite OAM_SIZE_16x16,   -5,  -18, 1032,    0
    subsprite OAM_SIZE_8x8,     20,   12, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    10,    2, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,     2,   -6, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -18, 1003,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -4,  -28,   96,    0
    subsprite OAM_SIZE_8x8,     -4,  -14,  940,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,   -7, 1009,    0
    subsprite OAM_SIZE_16x8,    12,    4, 2958,    0, xflip=1
  FileDE23_Obj_7870:
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -1,  -24,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x8,      0,  -14,  957,    0
    subsprite OAM_SIZE_16x8,     5,  -26, 2956,    0
    subsprite OAM_SIZE_16x8,    -5,  -16, 2974,    0
    subsprite OAM_SIZE_16x8,    -3,  -18, 2974,    0
    subsprite OAM_SIZE_8x8,     -5,   -8, 2973,    0
    subsprite OAM_SIZE_8x16,    -6,  -18,  940,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_7886:
    subsprite OAM_SIZE_8x32,   -14,  -33, 2761,    0
    subsprite OAM_SIZE_8x8,     -7,  -25, 2889,    0
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,      7,  -16,  942,    0
    subsprite OAM_SIZE_8x8,      2,  -16, 2973,    0
    subsprite OAM_SIZE_16x8,     2,  -24, 2974,    0
    subsprite OAM_SIZE_16x8,     4,  -26, 2974,    0
    subsprite OAM_SIZE_16x8,    12,  -34, 2956,    0
    subsprite OAM_SIZE_8x8,      2,  -13, 1071,    0
    subsprite OAM_SIZE_8x8,     -2,  -17,  958,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -6,  -20, 2905,    0
    subsprite OAM_SIZE_8x32,   -13,  -28, 2762,    0
  FileDE23_Obj_7901:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2761,    0
    subsprite OAM_SIZE_8x8,     -8,  -24, 2889,    0
    subsprite OAM_SIZE_8x8,      4,  -25,  593,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,     11,  -20,  942,    0
    subsprite OAM_SIZE_16x8,    16,  -38, 2956,    0
    subsprite OAM_SIZE_16x8,     6,  -28, 2974,    0
    subsprite OAM_SIZE_16x8,     8,  -30, 2974,    0
    subsprite OAM_SIZE_8x8,      6,  -20, 2973,    0
    subsprite OAM_SIZE_8x8,      2,  -21, 1119,    0, yflip=1
    subsprite OAM_SIZE_8x8,     -1,  -20, 1066,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -5,  -19, 2905,    0
    subsprite OAM_SIZE_8x32,   -12,  -27, 2762,    0
  FileDE23_Obj_7917:
    subsprite OAM_SIZE_8x32,   -15,  -32, 2761,    0
    subsprite OAM_SIZE_8x8,     -8,  -24, 2889,    0
    subsprite OAM_SIZE_8x8,      4,  -26,  593,    0, yflip=1
    subsprite OAM_SIZE_16x16,   -9,  -13, 1802,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  936,    0
    subsprite OAM_SIZE_8x8,     11,  -21,  942,    0
    subsprite OAM_SIZE_16x8,    16,  -39, 2956,    0
    subsprite OAM_SIZE_16x8,     6,  -29, 2974,    0
    subsprite OAM_SIZE_16x8,     8,  -31, 2974,    0
    subsprite OAM_SIZE_8x8,      6,  -21, 2973,    0
    subsprite OAM_SIZE_8x8,      2,  -22, 1119,    0, yflip=1
    subsprite OAM_SIZE_8x8,      0,  -20, 1066,    0
    subsprite OAM_SIZE_16x16,   -7,  -35, 1922,    0
    subsprite OAM_SIZE_8x8,    -15,  -27, 1890,    0
    subsprite OAM_SIZE_8x8,     -5,  -19, 2905,    0
    subsprite OAM_SIZE_8x32,   -12,  -27, 2762,    0
  FileDE23_Obj_7933:
    subsprite OAM_SIZE_8x8,     -6,  -26, 2889,    0
    subsprite OAM_SIZE_8x32,   -14,  -34, 2761,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_8x8,     -2,  -23,  941,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  936,    0
    subsprite OAM_SIZE_8x8,     -1,  -13,  957,    0
    subsprite OAM_SIZE_16x8,     4,  -25, 2956,    0
    subsprite OAM_SIZE_16x8,    -6,  -15, 2974,    0
    subsprite OAM_SIZE_16x8,    -4,  -17, 2974,    0
    subsprite OAM_SIZE_8x8,     -6,   -7, 2973,    0
    subsprite OAM_SIZE_8x16,    -7,  -17,  940,    0
    subsprite OAM_SIZE_16x16,   -8,  -36, 1922,    0
    subsprite OAM_SIZE_8x8,    -16,  -28, 1890,    0
    subsprite OAM_SIZE_8x32,   -15,  -29, 2762,    0
    subsprite OAM_SIZE_8x8,     -7,  -21, 2905,    0
  FileDE23_Obj_7949:
    subsprite OAM_SIZE_8x32,   -15,  -33, 2763,    0
    subsprite OAM_SIZE_8x8,     -7,  -25, 2890,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1284,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_32x8,   -12,  -13, 2952,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  965,    0
    subsprite OAM_SIZE_8x8,     -4,   -9,  284,    0
    subsprite OAM_SIZE_16x16,   -8,  -35, 1924,    0
    subsprite OAM_SIZE_8x8,    -16,  -35, 1893,    0
    subsprite OAM_SIZE_8x16,   -11,  -21,  964,    0
    subsprite OAM_SIZE_16x8,     6,  -13, 2954,    0
  FileDE23_Obj_7960:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x8,      3,   -2, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -7,  -12, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -15,  -20, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -12,  -25,  982,    0
    subsprite OAM_SIZE_8x8,     -2,  -21,  975,    0
    subsprite OAM_SIZE_8x8,     -9,  -14,  284,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1926,    0
    subsprite OAM_SIZE_8x8,     -9,  -43, 1928,    0
    subsprite OAM_SIZE_16x8,    -5,  -10, 2958,    0, xflip=1
  FileDE23_Obj_7973:
    subsprite OAM_SIZE_8x32,     7,  -34, 2763,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -1,  -26, 2890,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -14, 1288,    0
    subsprite OAM_SIZE_8x8,      1,    2, 1294,    0
    subsprite OAM_SIZE_16x16,   -7,  -23,  995,    0
    subsprite OAM_SIZE_16x8,    -6,  -20,  999,    0
    subsprite OAM_SIZE_8x8,     -8,  -20,  981,    0
    subsprite OAM_SIZE_8x32,    -9,  -24, 2991,    0
    subsprite OAM_SIZE_8x8,     -6,  -28,  991,    0
    subsprite OAM_SIZE_8x8,      0,  -43, 1261,    0
    subsprite OAM_SIZE_8x8,    -12,  -28, 1035,    0, xflip=1
    subsprite OAM_SIZE_16x16,   -8,  -35, 1870,    0
    subsprite OAM_SIZE_8x8,    -13,  -19,  847,    0
    subsprite OAM_SIZE_8x16,    -9,   -6, 3023,    0
  FileDE23_Obj_7987:
    subsprite OAM_SIZE_16x32,   -8,  -35, 2764,    0
    subsprite OAM_SIZE_8x16,    -4,  -21, 2052,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  970,    0
    subsprite OAM_SIZE_8x8,      4,   -1, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    -6,  -11, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,   -14,  -19, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x8,    -11,  -24,  982,    0
    subsprite OAM_SIZE_8x8,     -1,  -20,  975,    0
    subsprite OAM_SIZE_8x8,     -8,  -13,  284,    0
    subsprite OAM_SIZE_8x8,     -9,  -43, 1928,    0
    subsprite OAM_SIZE_16x16,   -9,  -35, 1926,    0
    subsprite OAM_SIZE_16x8,    -4,   -9, 2958,    0, xflip=1
  FileDE23_Obj_8001:
    subsprite OAM_SIZE_8x32,   -10,  -34, 2764,    9
    subsprite OAM_SIZE_8x32,    -1,  -35, 2765,    9
    subsprite OAM_SIZE_16x16,   -8,  -20, 2154,    0
    subsprite OAM_SIZE_16x16,   -8,  -13, 1830,    0
    subsprite OAM_SIZE_8x8,      2,  -22,  992,    0
    subsprite OAM_SIZE_16x16,   -8,  -22,  970,    0
    subsprite OAM_SIZE_8x8,      1,  -14, 1008,    0
    subsprite OAM_SIZE_16x8,    -7,  -14, 2942,    0, xflip=1
    subsprite OAM_SIZE_16x8,     1,   -6, 2958,    0, xflip=1
    subsprite OAM_SIZE_8x8,     11,    4, 2927,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -6,  -14, 1104,    0
    subsprite OAM_SIZE_8x8,     -8,  -22, 1103,    0
    subsprite OAM_SIZE_8x8,     -2,   -9,  284,    0
    subsprite OAM_SIZE_8x8,     -8,  -42, 1928,    0
    subsprite OAM_SIZE_16x16,   -8,  -34, 1926,    0
    subsprite OAM_SIZE_16x8,     3,   -4, 2958,    0, xflip=1
  FileDE23_Obj_8017:
    subsprite OAM_SIZE_8x32,   -11,  -29, 2763,    0
    subsprite OAM_SIZE_8x8,     -3,  -21, 2890,    0
    subsprite OAM_SIZE_16x16,   -6,  -11, 1414,    0
    subsprite OAM_SIZE_16x16,   -5,  -18, 1032,    0
    subsprite OAM_SIZE_16x8,     2,   -5, 2942,    0, xflip=1
    subsprite OAM_SIZE_16x8,    10,    3, 2958,    0, xflip=1
    subsprite OAM_SIZE_8x8,     20,   13, 2927,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -17, 1003,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,  -13,  940,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,   -6, 1009,    0
    subsprite OAM_SIZE_16x16,   -4,  -28, 1926,    0
    subsprite OAM_SIZE_8x8,     -4,  -36, 1928,    0
    subsprite OAM_SIZE_16x8,    12,    5, 2958,    0, xflip=1
  FileDE23_Obj_8030:
    subsprite OAM_SIZE_8x32,   -11,  -29, 2763,    0
    subsprite OAM_SIZE_8x8,     -3,  -21, 2890,    0
    subsprite OAM_SIZE_16x16,   -6,  -11, 1414,    0
    subsprite OAM_SIZE_16x16,   -5,  -18, 1032,    0
    subsprite OAM_SIZE_8x8,     20,   12, 2927,    0, xflip=1
    subsprite OAM_SIZE_16x8,    10,    2, 2958,    0, xflip=1
    subsprite OAM_SIZE_16x8,     2,   -6, 2942,    0, xflip=1
    subsprite OAM_SIZE_8x16,     3,  -18, 1003,    0, xflip=1
    subsprite OAM_SIZE_8x8,     -4,  -14,  940,    0, xflip=1
    subsprite OAM_SIZE_8x8,      2,   -7, 1009,    0
    subsprite OAM_SIZE_8x8,     -4,  -36, 1928,    0
    subsprite OAM_SIZE_16x16,   -4,  -28, 1926,    0
    subsprite OAM_SIZE_16x8,    12,    4, 2958,    0, xflip=1
  FileDE23_Obj_8043:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
    subsprite OAM_SIZE_8x16,     1,  -23, 2978,    0
    subsprite OAM_SIZE_16x16,  -15,  -23, 2976,    0
  FileDE23_Obj_8049:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
    subsprite OAM_SIZE_16x8,   -20,  -24, 2968,    0
    subsprite OAM_SIZE_16x16,   -6,  -27, 3008,    0
  FileDE23_Obj_8055:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
    subsprite OAM_SIZE_16x16,   -6,  -27, 3008,    0
    subsprite OAM_SIZE_16x8,   -20,  -24, 2970,    0
    subsprite OAM_SIZE_8x8,    -20,  -16, 2972,    0
  FileDE23_Obj_8062:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
    subsprite OAM_SIZE_16x16,   -6,  -27, 3008,    0
    subsprite OAM_SIZE_16x8,   -20,  -24, 2995,    0
    subsprite OAM_SIZE_8x8,    -20,  -16, 2982,    0
  FileDE23_Obj_8069:
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2438,    0
    subsprite OAM_SIZE_16x16,   -6,  -27, 3008,    0
    subsprite OAM_SIZE_16x8,   -20,  -24, 2979,    0
  FileDE23_Obj_8075:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_8x8,      4,  -24, 2997,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 3010,    0
    subsprite OAM_SIZE_8x8,     -8,  -19, 2981,    0
  FileDE23_Obj_8082:
    subsprite OAM_SIZE_8x16,    -7,  -19, 2051,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1286,    0
    subsprite OAM_SIZE_8x8,      4,    2, 1293,    0
    subsprite OAM_SIZE_16x16,   -8,  -23,  960,    0
    subsprite OAM_SIZE_8x8,      4,  -25, 2997,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 3010,    0
    subsprite OAM_SIZE_8x8,     -8,  -20, 2981,    0
  FileDE23_Obj_8089:
    subsprite OAM_SIZE_16x16,  -20,  -24, 3014,    0
    subsprite OAM_SIZE_8x8,    -12,  -32, 2999,    0
  FileDE23_Obj_8091:
    subsprite OAM_SIZE_8x8,     -6,  -24, 1050,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1028,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 2464,    0
    subsprite OAM_SIZE_16x8,     1,  -18, 2983,    0
  FileDE23_Obj_8099:
    subsprite OAM_SIZE_8x8,     -6,  -25, 1050,    0
    subsprite OAM_SIZE_8x8,     -1,    2, 1291,    0
    subsprite OAM_SIZE_16x16,   -8,  -14, 1282,    0
    subsprite OAM_SIZE_16x16,   -8,  -23, 1028,    0
    subsprite OAM_SIZE_8x16,    -7,  -19, 2049,    0
    subsprite OAM_SIZE_8x8,     -3,   -3, 2053,    0
    subsprite OAM_SIZE_16x16,   -9,  -34, 2464,    0
    subsprite OAM_SIZE_16x8,     1,  -19, 2983,    0
  FileDE23_Obj_8107:
    subsprite OAM_SIZE_16x16,  -20,  -23, 3012,    0
  FileDE23_Obj_8108:
    subsprite OAM_SIZE_16x16,  -20,  -24, 3016,    0
  FileDE23_Obj_8109:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,   -9,  -26,  871,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2464,    0
  FileDE23_Obj_8113:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -18, 2080,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2464,    0
  FileDE23_Obj_8119:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_16x16,   -9,  -17, 2084,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1766,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2466,    0
  FileDE23_Obj_8125:
    subsprite OAM_SIZE_16x16,   -9,  -13, 1800,    0
    subsprite OAM_SIZE_16x16,  -11,  -26,  873,    0
    subsprite OAM_SIZE_8x16,     1,  -31,  875,    0
    subsprite OAM_SIZE_8x8,      5,  -30, 1764,    0
    subsprite OAM_SIZE_8x16,    -5,  -17, 2048,    0
    subsprite OAM_SIZE_16x16,   -9,  -33, 2464,    0

2:
FileDE23_Cmds:
  FileDE23_Cmd_0:
    animcmd    0,   1
  FileDE23_Cmd_1:
    animcmd    1,   1
  FileDE23_Cmd_2:
    animcmd    2,   1
  FileDE23_Cmd_3:
    animcmd    3,   1
  FileDE23_Cmd_4:
    animcmd    4,   1
  FileDE23_Cmd_5:
    animcmd    7,   5
    animcmd    8,   5
    animcmd    9,   5
    animcmd   10,   5
    animcmd   11,   5
    animcmd   12,   5
    animcmd   13,   5
    animcmd   14,   5
  FileDE23_Cmd_13:
    animcmd   15,   5
    animcmd   16,   5
    animcmd   17,   5
    animcmd   18,   5
    animcmd   19,   5
    animcmd   20,   5
    animcmd   21,   5
    animcmd   22,   5
  FileDE23_Cmd_21:
    animcmd   23,   5
    animcmd   24,   5
    animcmd   25,   5
    animcmd   26,   5
    animcmd   27,   5
    animcmd   28,   5
    animcmd   29,   5
    animcmd   30,   5
  FileDE23_Cmd_29:
    animcmd   31,   5
    animcmd   32,   5
    animcmd   33,   5
    animcmd   34,   5
    animcmd   35,   5
    animcmd   36,   5
    animcmd   37,   5
    animcmd   38,   5
  FileDE23_Cmd_37:
    animcmd   39,   5
    animcmd   40,   5
    animcmd   41,   5
    animcmd   42,   5
    animcmd   43,   5
    animcmd   44,   5
    animcmd   45,   5
    animcmd   46,   5
  FileDE23_Cmd_45:
    animcmd   47,   1
  FileDE23_Cmd_46:
    animcmd   48,   1
  FileDE23_Cmd_47:
    animcmd   49,   1
  FileDE23_Cmd_48:
    animcmd   50,   1
  FileDE23_Cmd_49:
    animcmd   51,   1
  FileDE23_Cmd_50:
    animcmd   52,  10
    animcmd   53,   8
    animcmd   54,   8
    animcmd   55,   8
    animcmd   56,  10
    animcmd   57,   8
    animcmd   58,   8
    animcmd   59,   8
  FileDE23_Cmd_58:
    animcmd   60,  10
    animcmd   61,   8
    animcmd   62,   8
    animcmd   63,   8
    animcmd   64,  10
    animcmd   65,   8
    animcmd   66,   8
    animcmd   67,   8
  FileDE23_Cmd_66:
    animcmd   68,  10
    animcmd   69,   8
    animcmd   70,   8
    animcmd   71,   8
    animcmd   72,  10
    animcmd   73,   8
    animcmd   74,   8
    animcmd   75,   8
  FileDE23_Cmd_74:
    animcmd   76,  10
    animcmd   77,   8
    animcmd   78,   8
    animcmd   79,   8
    animcmd   80,  10
    animcmd   81,   8
    animcmd   82,   8
    animcmd   83,   8
  FileDE23_Cmd_82:
    animcmd   84,  10
    animcmd   85,   8
    animcmd   86,   8
    animcmd   87,   8
    animcmd   88,  10
    animcmd   89,   8
    animcmd   90,   8
    animcmd   91,   8
  FileDE23_Cmd_90:
    animcmd    3,   6
    animcmd    5,   6
  FileDE23_Cmd_92:
    animcmd    5,   6
    animcmd    6,   6
  FileDE23_Cmd_94:
    animcmd   92,   1
  FileDE23_Cmd_95:
    animcmd  102,   1
  FileDE23_Cmd_96:
    animcmd   93,   8
    animcmd   94,  15
    animcmd   93,   8
    animcmd   92,  15
  FileDE23_Cmd_100:
    animcmd  103,   8
    animcmd  104,  15
    animcmd  103,   8
    animcmd  102,  15
  FileDE23_Cmd_104:
    animcmd   95,   4
    animcmd   96,   4
  FileDE23_Cmd_106:
    animcmd  105,   4
    animcmd  106,   4
  FileDE23_Cmd_108:
    animcmd   97,  15
    animcmd   98,  15
    animcmd   99,  15
    animcmd  100,  15
  FileDE23_Cmd_112:
    animcmd  107,  15
    animcmd  108,  15
    animcmd  109,  15
    animcmd  110,  15
  FileDE23_Cmd_116:
    animcmd  101,   8
  FileDE23_Cmd_117:
    animcmd  111,   1
  FileDE23_Cmd_118:
    animcmd  112,   1
  FileDE23_Cmd_119:
    animcmd  118,   1
  FileDE23_Cmd_120:
    animcmd  113,   6
  FileDE23_Cmd_121:
    animcmd  119,   6
  FileDE23_Cmd_122:
    animcmd  113,   8
    animcmd  114,   8
    animcmd  115,   6
    animcmd  116,   6
    animcmd  117,   8
  FileDE23_Cmd_127:
    animcmd  119,   8
    animcmd  120,   8
    animcmd  121,   6
    animcmd  122,   6
    animcmd  123,   8
  FileDE23_Cmd_132:
    animcmd  124,   1
  FileDE23_Cmd_133:
    animcmd  128,   1
  FileDE23_Cmd_134:
    animcmd  125,   4
    animcmd  124,   4
    animcmd  125,   4
  FileDE23_Cmd_137:
    animcmd  129,   4
    animcmd  128,   4
    animcmd  129,   4
  FileDE23_Cmd_140:
    animcmd  126,   8
    animcmd  127,   6
  FileDE23_Cmd_142:
    animcmd  130,   8
    animcmd  131,   6
  FileDE23_Cmd_144:
    animcmd  132,   3
    animcmd  133,   3
  FileDE23_Cmd_146:
    animcmd  134,   3
    animcmd  135,   3
  FileDE23_Cmd_148:
    animcmd  114,   3
    animcmd  127,   6
  FileDE23_Cmd_150:
    animcmd  120,   3
    animcmd  131,   6
  FileDE23_Cmd_152:
    animcmd  136,   1
  FileDE23_Cmd_153:
    animcmd  137,   1
  FileDE23_Cmd_154:
    animcmd  138,   1
  FileDE23_Cmd_155:
    animcmd  139,   1
  FileDE23_Cmd_156:
    animcmd  140,   6
    animcmd  141,   6
  FileDE23_Cmd_158:
    animcmd  145,   6
    animcmd  146,   6
  FileDE23_Cmd_160:
    animcmd  142,   3
    animcmd  143,   3
  FileDE23_Cmd_162:
    animcmd  147,   3
    animcmd  148,   3
  FileDE23_Cmd_164:
    animcmd  144,   1
  FileDE23_Cmd_165:
    animcmd  149,   1
  FileDE23_Cmd_166:
    animcmd  140,   6
  FileDE23_Cmd_167:
    animcmd  145,   6
  FileDE23_Cmd_168:
    animcmd  150,   5
    animcmd  151,   5
  FileDE23_Cmd_170:
    animcmd  152,   3
    animcmd  153,   3
  FileDE23_Cmd_172:
    animcmd  154,   1
  FileDE23_Cmd_173:
    animcmd  150,   6
  FileDE23_Cmd_174:
    animcmd  155,   5
  FileDE23_Cmd_175:
    animcmd  158,   5
  FileDE23_Cmd_176:
    animcmd  161,   5
  FileDE23_Cmd_177:
    animcmd  164,   5
  FileDE23_Cmd_178:
    animcmd  167,   5
  FileDE23_Cmd_179:
    animcmd  156,   5
  FileDE23_Cmd_180:
    animcmd  159,   5
  FileDE23_Cmd_181:
    animcmd  162,   5
  FileDE23_Cmd_182:
    animcmd  165,   5
  FileDE23_Cmd_183:
    animcmd  168,   5
  FileDE23_Cmd_184:
    animcmd  157,   5
  FileDE23_Cmd_185:
    animcmd  160,   5
  FileDE23_Cmd_186:
    animcmd  163,   5
  FileDE23_Cmd_187:
    animcmd  166,   5
  FileDE23_Cmd_188:
    animcmd  169,   5
  FileDE23_Cmd_189:
    animcmd  170,   5
  FileDE23_Cmd_190:
    animcmd  173,   5
  FileDE23_Cmd_191:
    animcmd  176,   5
  FileDE23_Cmd_192:
    animcmd  179,   5
  FileDE23_Cmd_193:
    animcmd  182,   5
  FileDE23_Cmd_194:
    animcmd  171,   5
  FileDE23_Cmd_195:
    animcmd  174,   5
  FileDE23_Cmd_196:
    animcmd  177,   5
  FileDE23_Cmd_197:
    animcmd  180,   5
  FileDE23_Cmd_198:
    animcmd  183,   5
  FileDE23_Cmd_199:
    animcmd  172,   5
  FileDE23_Cmd_200:
    animcmd  175,   5
  FileDE23_Cmd_201:
    animcmd  178,   5
  FileDE23_Cmd_202:
    animcmd  181,   5
  FileDE23_Cmd_203:
    animcmd  184,   5
  FileDE23_Cmd_204:
    animcmd  185,   5
  FileDE23_Cmd_205:
    animcmd  188,   5
  FileDE23_Cmd_206:
    animcmd  191,   5
  FileDE23_Cmd_207:
    animcmd  194,   5
  FileDE23_Cmd_208:
    animcmd  197,   5
  FileDE23_Cmd_209:
    animcmd  186,   5
  FileDE23_Cmd_210:
    animcmd  189,   5
  FileDE23_Cmd_211:
    animcmd  192,   5
  FileDE23_Cmd_212:
    animcmd  195,   5
  FileDE23_Cmd_213:
    animcmd  198,   5
  FileDE23_Cmd_214:
    animcmd  187,   5
  FileDE23_Cmd_215:
    animcmd  190,   5
  FileDE23_Cmd_216:
    animcmd  193,   5
  FileDE23_Cmd_217:
    animcmd  196,   5
  FileDE23_Cmd_218:
    animcmd  199,   5
  FileDE23_Cmd_219:
    animcmd  200,   3
    animcmd  201,   5
  FileDE23_Cmd_221:
    animcmd  206,   3
    animcmd  207,   5
  FileDE23_Cmd_223:
    animcmd  212,   3
    animcmd  213,   5
  FileDE23_Cmd_225:
    animcmd  218,   3
    animcmd  219,   5
  FileDE23_Cmd_227:
    animcmd  224,   3
    animcmd  225,   5
  FileDE23_Cmd_229:
    animcmd  202,   3
    animcmd  203,   3
    animcmd  204,   3
    animcmd  205,   3
  FileDE23_Cmd_233:
    animcmd  208,   3
    animcmd  209,   3
    animcmd  210,   3
    animcmd  211,   3
  FileDE23_Cmd_237:
    animcmd  214,   3
    animcmd  215,   3
    animcmd  216,   3
    animcmd  217,   3
  FileDE23_Cmd_241:
    animcmd  220,   3
    animcmd  221,   3
    animcmd  222,   3
    animcmd  223,   3
  FileDE23_Cmd_245:
    animcmd  226,   3
    animcmd  227,   3
    animcmd  228,   3
    animcmd  229,   3
  FileDE23_Cmd_249:
    animcmd  201,   1
  FileDE23_Cmd_250:
    animcmd  207,   1
  FileDE23_Cmd_251:
    animcmd  213,   1
  FileDE23_Cmd_252:
    animcmd  219,   1
  FileDE23_Cmd_253:
    animcmd  225,   1
  FileDE23_Cmd_254:
    animcmd  230,   5
  FileDE23_Cmd_255:
    animcmd  237,   5
  FileDE23_Cmd_256:
    animcmd  244,   5
  FileDE23_Cmd_257:
    animcmd  251,   5
  FileDE23_Cmd_258:
    animcmd  258,   5
  FileDE23_Cmd_259:
    animcmd  231,   7
  FileDE23_Cmd_260:
    animcmd  238,   7
  FileDE23_Cmd_261:
    animcmd  245,   7
  FileDE23_Cmd_262:
    animcmd  252,   7
  FileDE23_Cmd_263:
    animcmd  259,   7
  FileDE23_Cmd_264:
    animcmd  230,   3
  FileDE23_Cmd_265:
    animcmd  237,   3
  FileDE23_Cmd_266:
    animcmd  244,   3
  FileDE23_Cmd_267:
    animcmd  251,   3
  FileDE23_Cmd_268:
    animcmd  258,   3
  FileDE23_Cmd_269:
    animcmd  232,   3
    animcmd  233,   7
  FileDE23_Cmd_271:
    animcmd  239,   3
    animcmd  240,   7
  FileDE23_Cmd_273:
    animcmd  246,   3
    animcmd  247,   7
  FileDE23_Cmd_275:
    animcmd  253,   3
    animcmd  254,   7
  FileDE23_Cmd_277:
    animcmd  260,   3
    animcmd  261,   7
  FileDE23_Cmd_279:
    animcmd  236,   1
    animcmd  234,   3
    animcmd  235,   7
    animcmd  236,   5
  FileDE23_Cmd_283:
    animcmd  243,   1
    animcmd  241,   3
    animcmd  242,   7
    animcmd  243,   5
  FileDE23_Cmd_287:
    animcmd  250,   1
    animcmd  248,   3
    animcmd  249,   7
    animcmd  250,   5
  FileDE23_Cmd_291:
    animcmd  257,   1
    animcmd  255,   3
    animcmd  256,   7
    animcmd  257,   5
  FileDE23_Cmd_295:
    animcmd  264,   1
    animcmd  262,   3
    animcmd  263,   7
    animcmd  264,   5
  FileDE23_Cmd_299:
    animcmd  265,   3
    animcmd  266,   4
  FileDE23_Cmd_301:
    animcmd  276,   3
    animcmd  277,   4
  FileDE23_Cmd_303:
    animcmd  288,   3
    animcmd  289,   4
  FileDE23_Cmd_305:
    animcmd  300,   3
    animcmd  301,   4
  FileDE23_Cmd_307:
    animcmd  312,   3
    animcmd  313,   4
  FileDE23_Cmd_309:
    animcmd  267,   1
  FileDE23_Cmd_310:
    animcmd  278,   1
  FileDE23_Cmd_311:
    animcmd  290,   1
  FileDE23_Cmd_312:
    animcmd  302,   1
  FileDE23_Cmd_313:
    animcmd  314,   1
  FileDE23_Cmd_314:
    animcmd  268,   5
    animcmd  269,   6
    animcmd  270,   3
    animcmd  271,   3
    animcmd  272,   3
    animcmd  273,   3
    animcmd  274,  12
    animcmd  265,   5
    animcmd  275,   4
  FileDE23_Cmd_323:
    animcmd  279,   5
    animcmd  280,   6
    animcmd  281,   3
    animcmd  282,   3
    animcmd  283,   3
    animcmd  284,   3
    animcmd  285,  12
    animcmd  286,   5
    animcmd  287,   4
  FileDE23_Cmd_332:
    animcmd  291,   5
    animcmd  292,   6
    animcmd  293,   3
    animcmd  294,   3
    animcmd  295,   3
    animcmd  296,   3
    animcmd  297,  12
    animcmd  298,   5
    animcmd  299,   4
  FileDE23_Cmd_341:
    animcmd  303,   5
    animcmd  304,   6
    animcmd  305,   3
    animcmd  306,   3
    animcmd  307,   3
    animcmd  308,   3
    animcmd  309,  12
    animcmd  310,   5
    animcmd  311,   4
  FileDE23_Cmd_350:
    animcmd  315,   5
    animcmd  316,   6
    animcmd  317,   3
    animcmd  318,   3
    animcmd  319,   3
    animcmd  320,   3
    animcmd  321,  12
    animcmd  322,   5
    animcmd  323,   4
  FileDE23_Cmd_359:
    animcmd  324,   5
  FileDE23_Cmd_360:
    animcmd  328,   5
  FileDE23_Cmd_361:
    animcmd  332,   5
  FileDE23_Cmd_362:
    animcmd  336,   5
  FileDE23_Cmd_363:
    animcmd  340,   5
  FileDE23_Cmd_364:
    animcmd  327,   1
  FileDE23_Cmd_365:
    animcmd  331,   1
  FileDE23_Cmd_366:
    animcmd  335,   1
  FileDE23_Cmd_367:
    animcmd  339,   1
  FileDE23_Cmd_368:
    animcmd  343,   1
  FileDE23_Cmd_369:
    animcmd  325,   3
    animcmd  326,   3
  FileDE23_Cmd_371:
    animcmd  329,   3
    animcmd  330,   3
  FileDE23_Cmd_373:
    animcmd  333,   3
    animcmd  334,   3
  FileDE23_Cmd_375:
    animcmd  337,   3
    animcmd  338,   3
  FileDE23_Cmd_377:
    animcmd  341,   3
    animcmd  342,   3
  FileDE23_Cmd_379:
    animcmd  344,   1
  FileDE23_Cmd_380:
    animcmd  347,   1
  FileDE23_Cmd_381:
    animcmd  350,   1
  FileDE23_Cmd_382:
    animcmd  353,   1
  FileDE23_Cmd_383:
    animcmd  356,   1
  FileDE23_Cmd_384:
    animcmd  344,   5
    animcmd  345,  16
  FileDE23_Cmd_386:
    animcmd  347,   5
    animcmd  348,  16
  FileDE23_Cmd_388:
    animcmd  350,   5
    animcmd  351,  16
  FileDE23_Cmd_390:
    animcmd  353,   5
    animcmd  354,  16
  FileDE23_Cmd_392:
    animcmd  356,   5
    animcmd  357,  16
  FileDE23_Cmd_394:
    animcmd  346,   5
  FileDE23_Cmd_395:
    animcmd  349,   5
  FileDE23_Cmd_396:
    animcmd  352,   5
  FileDE23_Cmd_397:
    animcmd  355,   5
  FileDE23_Cmd_398:
    animcmd  358,   5
  FileDE23_Cmd_399:
    animcmd  345,   1
  FileDE23_Cmd_400:
    animcmd  348,   1
  FileDE23_Cmd_401:
    animcmd  351,   1
  FileDE23_Cmd_402:
    animcmd  354,   1
  FileDE23_Cmd_403:
    animcmd  357,   1
  FileDE23_Cmd_404:
    animcmd  359,   1
  FileDE23_Cmd_405:
    animcmd  360,   1
  FileDE23_Cmd_406:
    animcmd  361,   1
  FileDE23_Cmd_407:
    animcmd  362,   1
  FileDE23_Cmd_408:
    animcmd  363,   1
  FileDE23_Cmd_409:
    animcmd  366,   5
    animcmd  367,   5
    animcmd  368,   5
    animcmd  369,   5
    animcmd  370,   5
    animcmd  371,   5
    animcmd  372,   5
    animcmd  373,   5
  FileDE23_Cmd_417:
    animcmd  374,   5
    animcmd  375,   5
    animcmd  376,   5
    animcmd  377,   5
    animcmd  378,   5
    animcmd  379,   5
    animcmd  380,   5
    animcmd  381,   5
  FileDE23_Cmd_425:
    animcmd  382,   5
    animcmd  383,   5
    animcmd  384,   5
    animcmd  385,   5
    animcmd  386,   5
    animcmd  387,   5
    animcmd  388,   5
    animcmd  389,   5
  FileDE23_Cmd_433:
    animcmd  390,   5
    animcmd  391,   5
    animcmd  392,   5
    animcmd  393,   5
    animcmd  394,   5
    animcmd  395,   5
    animcmd  396,   5
    animcmd  397,   5
  FileDE23_Cmd_441:
    animcmd  398,   5
    animcmd  399,   5
    animcmd  400,   5
    animcmd  401,   5
    animcmd  402,   5
    animcmd  403,   5
    animcmd  404,   5
    animcmd  405,   5
  FileDE23_Cmd_449:
    animcmd  406,   1
  FileDE23_Cmd_450:
    animcmd  407,   1
  FileDE23_Cmd_451:
    animcmd  408,   1
  FileDE23_Cmd_452:
    animcmd  409,   1
  FileDE23_Cmd_453:
    animcmd  410,   1
  FileDE23_Cmd_454:
    animcmd  411,  10
    animcmd  412,   8
    animcmd  413,   8
    animcmd  414,   8
    animcmd  415,  10
    animcmd  416,   8
    animcmd  417,   8
    animcmd  418,   8
  FileDE23_Cmd_462:
    animcmd  419,  10
    animcmd  420,   8
    animcmd  421,   8
    animcmd  422,   8
    animcmd  423,  10
    animcmd  424,   8
    animcmd  425,   8
    animcmd  426,   8
  FileDE23_Cmd_470:
    animcmd  427,  10
    animcmd  428,   8
    animcmd  429,   8
    animcmd  430,   8
    animcmd  431,  10
    animcmd  432,   8
    animcmd  433,   8
    animcmd  434,   8
  FileDE23_Cmd_478:
    animcmd  435,  10
    animcmd  436,   8
    animcmd  437,   8
    animcmd  438,   8
    animcmd  439,  10
    animcmd  440,   8
    animcmd  441,   8
    animcmd  442,   8
  FileDE23_Cmd_486:
    animcmd  443,  10
    animcmd  444,   8
    animcmd  445,   8
    animcmd  446,   8
    animcmd  447,  10
    animcmd  448,   8
    animcmd  449,   8
    animcmd  450,   8
  FileDE23_Cmd_494:
    animcmd  362,   6
    animcmd  364,   6
  FileDE23_Cmd_496:
    animcmd  364,   6
    animcmd  365,   6
  FileDE23_Cmd_498:
    animcmd  451,   1
  FileDE23_Cmd_499:
    animcmd  461,   1
  FileDE23_Cmd_500:
    animcmd  452,   8
    animcmd  453,  15
    animcmd  452,   8
    animcmd  451,  15
  FileDE23_Cmd_504:
    animcmd  462,   8
    animcmd  463,  15
    animcmd  462,   8
    animcmd  461,  15
  FileDE23_Cmd_508:
    animcmd  454,   4
    animcmd  455,   4
  FileDE23_Cmd_510:
    animcmd  464,   4
    animcmd  465,   4
  FileDE23_Cmd_512:
    animcmd  456,  15
    animcmd  457,  15
    animcmd  458,  15
    animcmd  459,  15
  FileDE23_Cmd_516:
    animcmd  466,  15
    animcmd  467,  15
    animcmd  468,  15
    animcmd  469,  15
  FileDE23_Cmd_520:
    animcmd  460,   8
  FileDE23_Cmd_521:
    animcmd  470,   1
  FileDE23_Cmd_522:
    animcmd  471,   1
  FileDE23_Cmd_523:
    animcmd  477,   1
  FileDE23_Cmd_524:
    animcmd  472,   6
  FileDE23_Cmd_525:
    animcmd  478,   6
  FileDE23_Cmd_526:
    animcmd  472,   8
    animcmd  473,   8
    animcmd  474,   6
    animcmd  475,   6
    animcmd  476,   8
  FileDE23_Cmd_531:
    animcmd  478,   8
    animcmd  479,   8
    animcmd  480,   6
    animcmd  481,   6
    animcmd  482,   8
  FileDE23_Cmd_536:
    animcmd  483,   1
  FileDE23_Cmd_537:
    animcmd  487,   1
  FileDE23_Cmd_538:
    animcmd  484,   4
    animcmd  483,   4
    animcmd  484,   4
  FileDE23_Cmd_541:
    animcmd  488,   4
    animcmd  487,   4
    animcmd  488,   4
  FileDE23_Cmd_544:
    animcmd  485,   8
    animcmd  486,   6
  FileDE23_Cmd_546:
    animcmd  489,   8
    animcmd  490,   6
  FileDE23_Cmd_548:
    animcmd  491,   3
    animcmd  492,   3
  FileDE23_Cmd_550:
    animcmd  493,   3
    animcmd  494,   3
  FileDE23_Cmd_552:
    animcmd  473,   3
    animcmd  486,   6
  FileDE23_Cmd_554:
    animcmd  479,   3
    animcmd  490,   6
  FileDE23_Cmd_556:
    animcmd  495,   1
  FileDE23_Cmd_557:
    animcmd  496,   1
  FileDE23_Cmd_558:
    animcmd  497,   1
  FileDE23_Cmd_559:
    animcmd  498,   1
  FileDE23_Cmd_560:
    animcmd  499,   6
    animcmd  500,   6
  FileDE23_Cmd_562:
    animcmd  504,   6
    animcmd  505,   6
  FileDE23_Cmd_564:
    animcmd  501,   3
    animcmd  502,   3
  FileDE23_Cmd_566:
    animcmd  506,   3
    animcmd  507,   3
  FileDE23_Cmd_568:
    animcmd  503,   1
  FileDE23_Cmd_569:
    animcmd  508,   1
  FileDE23_Cmd_570:
    animcmd  499,   6
  FileDE23_Cmd_571:
    animcmd  504,   6
  FileDE23_Cmd_572:
    animcmd  509,   5
    animcmd  510,   5
  FileDE23_Cmd_574:
    animcmd  511,   3
    animcmd  512,   3
  FileDE23_Cmd_576:
    animcmd  513,   1
  FileDE23_Cmd_577:
    animcmd  509,   6
  FileDE23_Cmd_578:
    animcmd  514,   5
  FileDE23_Cmd_579:
    animcmd  517,   5
  FileDE23_Cmd_580:
    animcmd  520,   5
  FileDE23_Cmd_581:
    animcmd  523,   5
  FileDE23_Cmd_582:
    animcmd  526,   5
  FileDE23_Cmd_583:
    animcmd  515,   5
  FileDE23_Cmd_584:
    animcmd  518,   5
  FileDE23_Cmd_585:
    animcmd  521,   5
  FileDE23_Cmd_586:
    animcmd  524,   5
  FileDE23_Cmd_587:
    animcmd  527,   5
  FileDE23_Cmd_588:
    animcmd  516,   5
  FileDE23_Cmd_589:
    animcmd  519,   5
  FileDE23_Cmd_590:
    animcmd  522,   5
  FileDE23_Cmd_591:
    animcmd  525,   5
  FileDE23_Cmd_592:
    animcmd  528,   5
  FileDE23_Cmd_593:
    animcmd  529,   5
  FileDE23_Cmd_594:
    animcmd  532,   5
  FileDE23_Cmd_595:
    animcmd  535,   5
  FileDE23_Cmd_596:
    animcmd  538,   5
  FileDE23_Cmd_597:
    animcmd  541,   5
  FileDE23_Cmd_598:
    animcmd  530,   5
  FileDE23_Cmd_599:
    animcmd  533,   5
  FileDE23_Cmd_600:
    animcmd  536,   5
  FileDE23_Cmd_601:
    animcmd  539,   5
  FileDE23_Cmd_602:
    animcmd  542,   5
  FileDE23_Cmd_603:
    animcmd  531,   5
  FileDE23_Cmd_604:
    animcmd  534,   5
  FileDE23_Cmd_605:
    animcmd  537,   5
  FileDE23_Cmd_606:
    animcmd  540,   5
  FileDE23_Cmd_607:
    animcmd  543,   5
  FileDE23_Cmd_608:
    animcmd  544,   5
  FileDE23_Cmd_609:
    animcmd  547,   5
  FileDE23_Cmd_610:
    animcmd  550,   5
  FileDE23_Cmd_611:
    animcmd  553,   5
  FileDE23_Cmd_612:
    animcmd  556,   5
  FileDE23_Cmd_613:
    animcmd  545,   5
  FileDE23_Cmd_614:
    animcmd  548,   5
  FileDE23_Cmd_615:
    animcmd  551,   5
  FileDE23_Cmd_616:
    animcmd  554,   5
  FileDE23_Cmd_617:
    animcmd  557,   5
  FileDE23_Cmd_618:
    animcmd  546,   5
  FileDE23_Cmd_619:
    animcmd  549,   5
  FileDE23_Cmd_620:
    animcmd  552,   5
  FileDE23_Cmd_621:
    animcmd  555,   5
  FileDE23_Cmd_622:
    animcmd  558,   5
  FileDE23_Cmd_623:
    animcmd  559,   3
    animcmd  560,   5
  FileDE23_Cmd_625:
    animcmd  565,   3
    animcmd  566,   5
  FileDE23_Cmd_627:
    animcmd  571,   3
    animcmd  572,   5
  FileDE23_Cmd_629:
    animcmd  577,   3
    animcmd  578,   5
  FileDE23_Cmd_631:
    animcmd  583,   3
    animcmd  584,   5
  FileDE23_Cmd_633:
    animcmd  561,   3
    animcmd  562,   3
    animcmd  563,   3
    animcmd  564,   3
  FileDE23_Cmd_637:
    animcmd  567,   3
    animcmd  568,   3
    animcmd  569,   3
    animcmd  570,   3
  FileDE23_Cmd_641:
    animcmd  573,   3
    animcmd  574,   3
    animcmd  575,   3
    animcmd  576,   3
  FileDE23_Cmd_645:
    animcmd  579,   3
    animcmd  580,   3
    animcmd  581,   3
    animcmd  582,   3
  FileDE23_Cmd_649:
    animcmd  585,   3
    animcmd  586,   3
    animcmd  587,   3
    animcmd  588,   3
  FileDE23_Cmd_653:
    animcmd  560,   1
  FileDE23_Cmd_654:
    animcmd  566,   1
  FileDE23_Cmd_655:
    animcmd  572,   1
  FileDE23_Cmd_656:
    animcmd  578,   1
  FileDE23_Cmd_657:
    animcmd  584,   1
  FileDE23_Cmd_658:
    animcmd  589,   5
  FileDE23_Cmd_659:
    animcmd  596,   5
  FileDE23_Cmd_660:
    animcmd  603,   5
  FileDE23_Cmd_661:
    animcmd  610,   5
  FileDE23_Cmd_662:
    animcmd  617,   5
  FileDE23_Cmd_663:
    animcmd  590,   7
  FileDE23_Cmd_664:
    animcmd  597,   7
  FileDE23_Cmd_665:
    animcmd  604,   7
  FileDE23_Cmd_666:
    animcmd  611,   7
  FileDE23_Cmd_667:
    animcmd  618,   7
  FileDE23_Cmd_668:
    animcmd  589,   3
  FileDE23_Cmd_669:
    animcmd  596,   3
  FileDE23_Cmd_670:
    animcmd  603,   3
  FileDE23_Cmd_671:
    animcmd  610,   3
  FileDE23_Cmd_672:
    animcmd  617,   3
  FileDE23_Cmd_673:
    animcmd  591,   3
    animcmd  592,   7
  FileDE23_Cmd_675:
    animcmd  598,   3
    animcmd  599,   7
  FileDE23_Cmd_677:
    animcmd  605,   3
    animcmd  606,   7
  FileDE23_Cmd_679:
    animcmd  612,   3
    animcmd  613,   7
  FileDE23_Cmd_681:
    animcmd  619,   3
    animcmd  620,   7
  FileDE23_Cmd_683:
    animcmd  595,   1
    animcmd  593,   3
    animcmd  594,   7
    animcmd  595,   5
  FileDE23_Cmd_687:
    animcmd  602,   1
    animcmd  600,   3
    animcmd  601,   7
    animcmd  602,   5
  FileDE23_Cmd_691:
    animcmd  609,   1
    animcmd  607,   3
    animcmd  608,   7
    animcmd  609,   5
  FileDE23_Cmd_695:
    animcmd  616,   1
    animcmd  614,   3
    animcmd  615,   7
    animcmd  616,   5
  FileDE23_Cmd_699:
    animcmd  623,   1
    animcmd  621,   3
    animcmd  622,   7
    animcmd  623,   5
  FileDE23_Cmd_703:
    animcmd  624,   3
    animcmd  625,   4
  FileDE23_Cmd_705:
    animcmd  635,   3
    animcmd  636,   4
  FileDE23_Cmd_707:
    animcmd  647,   3
    animcmd  648,   4
  FileDE23_Cmd_709:
    animcmd  659,   3
    animcmd  660,   4
  FileDE23_Cmd_711:
    animcmd  671,   3
    animcmd  672,   4
  FileDE23_Cmd_713:
    animcmd  626,   1
  FileDE23_Cmd_714:
    animcmd  637,   1
  FileDE23_Cmd_715:
    animcmd  649,   1
  FileDE23_Cmd_716:
    animcmd  661,   1
  FileDE23_Cmd_717:
    animcmd  673,   1
  FileDE23_Cmd_718:
    animcmd  627,   5
    animcmd  628,   6
    animcmd  629,   3
    animcmd  630,   3
    animcmd  631,   3
    animcmd  632,   3
    animcmd  633,  12
    animcmd  624,   5
    animcmd  634,   4
  FileDE23_Cmd_727:
    animcmd  638,   5
    animcmd  639,   6
    animcmd  640,   3
    animcmd  641,   3
    animcmd  642,   3
    animcmd  643,   3
    animcmd  644,  12
    animcmd  645,   5
    animcmd  646,   4
  FileDE23_Cmd_736:
    animcmd  650,   5
    animcmd  651,   6
    animcmd  652,   3
    animcmd  653,   3
    animcmd  654,   3
    animcmd  655,   3
    animcmd  656,  12
    animcmd  657,   5
    animcmd  658,   4
  FileDE23_Cmd_745:
    animcmd  662,   5
    animcmd  663,   6
    animcmd  664,   3
    animcmd  665,   3
    animcmd  666,   3
    animcmd  667,   3
    animcmd  668,  12
    animcmd  669,   5
    animcmd  670,   4
  FileDE23_Cmd_754:
    animcmd  674,   5
    animcmd  675,   6
    animcmd  676,   3
    animcmd  677,   3
    animcmd  678,   3
    animcmd  679,   3
    animcmd  680,  12
    animcmd  681,   5
    animcmd  682,   4
  FileDE23_Cmd_763:
    animcmd  683,   5
  FileDE23_Cmd_764:
    animcmd  687,   5
  FileDE23_Cmd_765:
    animcmd  691,   5
  FileDE23_Cmd_766:
    animcmd  695,   5
  FileDE23_Cmd_767:
    animcmd  699,   5
  FileDE23_Cmd_768:
    animcmd  686,   1
  FileDE23_Cmd_769:
    animcmd  690,   1
  FileDE23_Cmd_770:
    animcmd  694,   1
  FileDE23_Cmd_771:
    animcmd  698,   1
  FileDE23_Cmd_772:
    animcmd  702,   1
  FileDE23_Cmd_773:
    animcmd  684,   3
    animcmd  685,   3
  FileDE23_Cmd_775:
    animcmd  688,   3
    animcmd  689,   3
  FileDE23_Cmd_777:
    animcmd  692,   3
    animcmd  693,   3
  FileDE23_Cmd_779:
    animcmd  696,   3
    animcmd  697,   3
  FileDE23_Cmd_781:
    animcmd  700,   3
    animcmd  701,   3
  FileDE23_Cmd_783:
    animcmd  703,   1
  FileDE23_Cmd_784:
    animcmd  706,   1
  FileDE23_Cmd_785:
    animcmd  709,   1
  FileDE23_Cmd_786:
    animcmd  712,   1
  FileDE23_Cmd_787:
    animcmd  715,   1
  FileDE23_Cmd_788:
    animcmd  703,   5
    animcmd  704,  16
  FileDE23_Cmd_790:
    animcmd  706,   5
    animcmd  707,  16
  FileDE23_Cmd_792:
    animcmd  709,   5
    animcmd  710,  16
  FileDE23_Cmd_794:
    animcmd  712,   5
    animcmd  713,  16
  FileDE23_Cmd_796:
    animcmd  715,   5
    animcmd  716,  16
  FileDE23_Cmd_798:
    animcmd  705,   5
  FileDE23_Cmd_799:
    animcmd  708,   5
  FileDE23_Cmd_800:
    animcmd  711,   5
  FileDE23_Cmd_801:
    animcmd  714,   5
  FileDE23_Cmd_802:
    animcmd  717,   5
  FileDE23_Cmd_803:
    animcmd  704,   1
  FileDE23_Cmd_804:
    animcmd  707,   1
  FileDE23_Cmd_805:
    animcmd  710,   1
  FileDE23_Cmd_806:
    animcmd  713,   1
  FileDE23_Cmd_807:
    animcmd  716,   1
  FileDE23_Cmd_808:
    animcmd  718,   3
    animcmd  719,   3
  FileDE23_Cmd_810:
    animcmd  721,   1
  FileDE23_Cmd_811:
    animcmd  720,  42
    animcmd  493,   4
    animcmd  478,   4
    animcmd  479,   4
    animcmd  713,   4
    animcmd  714,   4
    animcmd  362,  29
  FileDE23_Cmd_818:
    animcmd  491,   4
    animcmd  472,   4
    animcmd  473,   4
    animcmd  707,   4
    animcmd  708,   4
  FileDE23_Cmd_823:
    animcmd  493,   4
    animcmd  478,   4
    animcmd  479,   4
    animcmd  713,   4
    animcmd  714,   4
  FileDE23_Cmd_828:
    animcmd  722,   1
  FileDE23_Cmd_829:
    animcmd  723,   1
  FileDE23_Cmd_830:
    animcmd  724,   1
  FileDE23_Cmd_831:
    animcmd  725,   1
  FileDE23_Cmd_832:
    animcmd  726,   1
  FileDE23_Cmd_833:
    animcmd  727,   3
    animcmd  728,   3
    animcmd  729,   3
    animcmd  730,   3
    animcmd  731,   3
    animcmd  732,   3
    animcmd  733,   3
    animcmd  734,   3
  FileDE23_Cmd_841:
    animcmd  735,   3
    animcmd  736,   3
    animcmd  737,   3
    animcmd  738,   3
    animcmd  739,   3
    animcmd  740,   3
    animcmd  741,   3
    animcmd  742,   3
  FileDE23_Cmd_849:
    animcmd  743,   3
    animcmd  744,   4
    animcmd  745,   4
    animcmd  746,   4
    animcmd  747,   2
    animcmd  748,  16
  FileDE23_Cmd_855:
    animcmd  750,   3
    animcmd  751,   4
    animcmd  752,   4
    animcmd  753,   4
    animcmd  754,   2
    animcmd  755,  16
  FileDE23_Cmd_861:
    animcmd  749,   1
  FileDE23_Cmd_862:
    animcmd  756,   1
  FileDE23_Cmd_863:
    animcmd  757,   1
  FileDE23_Cmd_864:
    animcmd  758,   1
  FileDE23_Cmd_865:
    animcmd  759,   1
  FileDE23_Cmd_866:
    animcmd  760,   1
  FileDE23_Cmd_867:
    animcmd  761,   1
  FileDE23_Cmd_868:
    animcmd  764,   5
    animcmd  765,   5
    animcmd  766,   5
    animcmd  767,   5
    animcmd  768,   5
    animcmd  769,   5
    animcmd  770,   5
    animcmd  771,   5
  FileDE23_Cmd_876:
    animcmd  772,   5
    animcmd  773,   5
    animcmd  774,   5
    animcmd  775,   5
    animcmd  776,   5
    animcmd  777,   5
    animcmd  778,   5
    animcmd  779,   5
  FileDE23_Cmd_884:
    animcmd  780,   5
    animcmd  781,   5
    animcmd  782,   5
    animcmd  783,   5
    animcmd  784,   5
    animcmd  785,   5
    animcmd  786,   5
    animcmd  787,   5
  FileDE23_Cmd_892:
    animcmd  788,   5
    animcmd  789,   5
    animcmd  790,   5
    animcmd  791,   5
    animcmd  792,   5
    animcmd  793,   5
    animcmd  794,   5
    animcmd  795,   5
  FileDE23_Cmd_900:
    animcmd  796,   5
    animcmd  797,   5
    animcmd  798,   5
    animcmd  799,   5
    animcmd  800,   5
    animcmd  801,   5
    animcmd  802,   5
    animcmd  803,   5
  FileDE23_Cmd_908:
    animcmd  804,   1
  FileDE23_Cmd_909:
    animcmd  805,   1
  FileDE23_Cmd_910:
    animcmd  806,   1
  FileDE23_Cmd_911:
    animcmd  807,   1
  FileDE23_Cmd_912:
    animcmd  808,   1
  FileDE23_Cmd_913:
    animcmd  809,  10
    animcmd  810,   8
    animcmd  811,   8
    animcmd  812,   8
    animcmd  813,  10
    animcmd  814,   8
    animcmd  815,   8
    animcmd  816,   8
  FileDE23_Cmd_921:
    animcmd  817,  10
    animcmd  818,   8
    animcmd  819,   8
    animcmd  820,   8
    animcmd  821,  10
    animcmd  822,   8
    animcmd  823,   8
    animcmd  824,   8
  FileDE23_Cmd_929:
    animcmd  825,  10
    animcmd  826,   8
    animcmd  827,   8
    animcmd  828,   8
    animcmd  829,  10
    animcmd  830,   8
    animcmd  831,   8
    animcmd  832,   8
  FileDE23_Cmd_937:
    animcmd  833,  10
    animcmd  834,   8
    animcmd  835,   8
    animcmd  836,   8
    animcmd  837,  10
    animcmd  838,   8
    animcmd  839,   8
    animcmd  840,   8
  FileDE23_Cmd_945:
    animcmd  841,  10
    animcmd  842,   8
    animcmd  843,   8
    animcmd  844,   8
    animcmd  845,  10
    animcmd  846,   8
    animcmd  847,   8
    animcmd  848,   8
  FileDE23_Cmd_953:
    animcmd  760,   6
    animcmd  762,   6
  FileDE23_Cmd_955:
    animcmd  762,   6
    animcmd  763,   6
  FileDE23_Cmd_957:
    animcmd  849,   1
  FileDE23_Cmd_958:
    animcmd  859,   1
  FileDE23_Cmd_959:
    animcmd  850,   8
    animcmd  851,  15
    animcmd  850,   8
    animcmd  849,  15
  FileDE23_Cmd_963:
    animcmd  860,   8
    animcmd  861,  15
    animcmd  860,   8
    animcmd  859,  15
  FileDE23_Cmd_967:
    animcmd  852,   4
    animcmd  853,   4
  FileDE23_Cmd_969:
    animcmd  862,   4
    animcmd  863,   4
  FileDE23_Cmd_971:
    animcmd  854,  15
    animcmd  855,  15
    animcmd  856,  15
    animcmd  857,  15
  FileDE23_Cmd_975:
    animcmd  864,  15
    animcmd  865,  15
    animcmd  866,  15
    animcmd  867,  15
  FileDE23_Cmd_979:
    animcmd  858,   8
  FileDE23_Cmd_980:
    animcmd  868,   1
  FileDE23_Cmd_981:
    animcmd  869,   1
  FileDE23_Cmd_982:
    animcmd  875,   1
  FileDE23_Cmd_983:
    animcmd  870,   6
  FileDE23_Cmd_984:
    animcmd  876,   6
  FileDE23_Cmd_985:
    animcmd  870,   8
    animcmd  871,   8
    animcmd  872,   6
    animcmd  873,   6
    animcmd  874,   8
  FileDE23_Cmd_990:
    animcmd  876,   8
    animcmd  877,   8
    animcmd  878,   6
    animcmd  879,   6
    animcmd  880,   8
  FileDE23_Cmd_995:
    animcmd  881,   1
  FileDE23_Cmd_996:
    animcmd  885,   1
  FileDE23_Cmd_997:
    animcmd  882,   4
    animcmd  881,   4
    animcmd  882,   4
  FileDE23_Cmd_1000:
    animcmd  886,   4
    animcmd  885,   4
    animcmd  886,   4
  FileDE23_Cmd_1003:
    animcmd  883,   8
    animcmd  884,   6
  FileDE23_Cmd_1005:
    animcmd  887,   8
    animcmd  888,   6
  FileDE23_Cmd_1007:
    animcmd  889,   3
    animcmd  890,   3
  FileDE23_Cmd_1009:
    animcmd  891,   3
    animcmd  892,   3
  FileDE23_Cmd_1011:
    animcmd  871,   3
    animcmd  884,   6
  FileDE23_Cmd_1013:
    animcmd  877,   3
    animcmd  888,   6
  FileDE23_Cmd_1015:
    animcmd  893,   1
  FileDE23_Cmd_1016:
    animcmd  894,   1
  FileDE23_Cmd_1017:
    animcmd  895,   1
  FileDE23_Cmd_1018:
    animcmd  896,   1
  FileDE23_Cmd_1019:
    animcmd  897,   6
    animcmd  898,   6
  FileDE23_Cmd_1021:
    animcmd  902,   6
    animcmd  903,   6
  FileDE23_Cmd_1023:
    animcmd  899,   3
    animcmd  900,   3
  FileDE23_Cmd_1025:
    animcmd  904,   3
    animcmd  905,   3
  FileDE23_Cmd_1027:
    animcmd  901,   1
  FileDE23_Cmd_1028:
    animcmd  906,   1
  FileDE23_Cmd_1029:
    animcmd  897,   6
  FileDE23_Cmd_1030:
    animcmd  902,   6
  FileDE23_Cmd_1031:
    animcmd  907,   5
    animcmd  908,   5
  FileDE23_Cmd_1033:
    animcmd  909,   3
    animcmd  910,   3
  FileDE23_Cmd_1035:
    animcmd  911,   1
  FileDE23_Cmd_1036:
    animcmd  907,   6
  FileDE23_Cmd_1037:
    animcmd  912,   5
  FileDE23_Cmd_1038:
    animcmd  915,   5
  FileDE23_Cmd_1039:
    animcmd  918,   5
  FileDE23_Cmd_1040:
    animcmd  921,   5
  FileDE23_Cmd_1041:
    animcmd  924,   5
  FileDE23_Cmd_1042:
    animcmd  913,   5
  FileDE23_Cmd_1043:
    animcmd  916,   5
  FileDE23_Cmd_1044:
    animcmd  919,   5
  FileDE23_Cmd_1045:
    animcmd  922,   5
  FileDE23_Cmd_1046:
    animcmd  925,   5
  FileDE23_Cmd_1047:
    animcmd  914,   5
  FileDE23_Cmd_1048:
    animcmd  917,   1
  FileDE23_Cmd_1049:
    animcmd  920,   5
  FileDE23_Cmd_1050:
    animcmd  923,   5
  FileDE23_Cmd_1051:
    animcmd  926,   5
  FileDE23_Cmd_1052:
    animcmd  927,   1
  FileDE23_Cmd_1053:
    animcmd  930,   1
  FileDE23_Cmd_1054:
    animcmd  933,   1
  FileDE23_Cmd_1055:
    animcmd  936,   1
  FileDE23_Cmd_1056:
    animcmd  939,   1
  FileDE23_Cmd_1057:
    animcmd  927,   5
    animcmd  928,  16
  FileDE23_Cmd_1059:
    animcmd  930,   5
    animcmd  931,  16
  FileDE23_Cmd_1061:
    animcmd  933,   5
    animcmd  934,  16
  FileDE23_Cmd_1063:
    animcmd  936,   5
    animcmd  937,  16
  FileDE23_Cmd_1065:
    animcmd  939,   5
    animcmd  940,  16
  FileDE23_Cmd_1067:
    animcmd  929,   5
  FileDE23_Cmd_1068:
    animcmd  932,   5
  FileDE23_Cmd_1069:
    animcmd  935,   5
  FileDE23_Cmd_1070:
    animcmd  938,   5
  FileDE23_Cmd_1071:
    animcmd  941,   5
  FileDE23_Cmd_1072:
    animcmd  928,   1
  FileDE23_Cmd_1073:
    animcmd  931,   1
  FileDE23_Cmd_1074:
    animcmd  934,   1
  FileDE23_Cmd_1075:
    animcmd  937,   1
  FileDE23_Cmd_1076:
    animcmd  940,   1
  FileDE23_Cmd_1077:
    animcmd  946,   8
    animcmd  942,   8
    animcmd  943,   8
    animcmd  944,   8
  FileDE23_Cmd_1081:
    animcmd  944,  10
    animcmd  945,  10
  FileDE23_Cmd_1083:
    animcmd  946,   1
  FileDE23_Cmd_1084:
    animcmd  947,   1
  FileDE23_Cmd_1085:
    animcmd  948,   1
  FileDE23_Cmd_1086:
    animcmd  949,   1
  FileDE23_Cmd_1087:
    animcmd  948,   8
    animcmd  950,   8
    animcmd  951,   8
    animcmd  952,   8
  FileDE23_Cmd_1091:
    animcmd  953,   3
    animcmd  952,   3
  FileDE23_Cmd_1093:
    animcmd  958,   8
    animcmd  954,   8
    animcmd  955,   8
    animcmd  956,   8
  FileDE23_Cmd_1097:
    animcmd  956,  10
    animcmd  957,  10
  FileDE23_Cmd_1099:
    animcmd  958,   1
  FileDE23_Cmd_1100:
    animcmd  959,   1
  FileDE23_Cmd_1101:
    animcmd  960,   1
  FileDE23_Cmd_1102:
    animcmd  961,   1
  FileDE23_Cmd_1103:
    animcmd  960,   8
    animcmd  962,   8
    animcmd  963,   8
    animcmd  964,   8
  FileDE23_Cmd_1107:
    animcmd  965,   3
    animcmd  964,   3
  FileDE23_Cmd_1109:
    animcmd  966,   8
  FileDE23_Cmd_1110:
    animcmd  967,   6
    animcmd  968,   6
    animcmd  969,   6
    animcmd  970,   6
  FileDE23_Cmd_1114:
    animcmd  758,   6
    animcmd  974,  17
    animcmd  975,  17
    animcmd  974,   6
  FileDE23_Cmd_1118:
    animcmd  760,   6
    animcmd  971,  17
    animcmd  972,  17
    animcmd  971,   6
  FileDE23_Cmd_1122:
    animcmd  973,   1
  FileDE23_Cmd_1123:
    animcmd  976,   1
  FileDE23_Cmd_1124:
    animcmd  977,   1
  FileDE23_Cmd_1125:
    animcmd  978,   5
  FileDE23_Cmd_1126:
    animcmd  981,   1
  FileDE23_Cmd_1127:
    animcmd  979,   3
    animcmd  980,   3

FileDE23_Tiles:
  .incbin "data/spriteset/django_sabata.4bpp"
