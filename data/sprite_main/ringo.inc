FileD3DA_Header:
  .2byte 195 @ palStart
  .2byte 206 @ metaspriteCount
  .2byte 89 @ animationCount
  .2byte 1002 @ subspriteCount
  .2byte 261 @ cmdCount
  .2byte 3328 @ tileCount
  .4byte 32 @ offsetToPoses
  .4byte 4152 @ offsetToAnims
  .4byte 4864 @ offsetToSubsprites
  .4byte 12880 @ offsetToCmds
  .4byte 13924 @ offsetToTiles

FileD3DA_Poses:
@ pose unk_0,  obj,                objcount,   bb
  pose 0x1B43, FileD3DA_Obj_0,     5,          -48,  -78,   24,   24
  pose 0x1B44, FileD3DA_Obj_5,     4,          -48,  -79,   32,   24
  pose 0x1B45, FileD3DA_Obj_9,     3,          -48,  -78,   24,   24
  pose 0x1B46, FileD3DA_Obj_12,    4,          -48,  -79,   24,   24
  pose 0x1B47, FileD3DA_Obj_16,    5,          -48,  -79,   24,   24
  pose 0x9B43, FileD3DA_Obj_21,    5,          -48,  -72,   24,   24
  pose 0x9B44, FileD3DA_Obj_26,    4,          -48,  -72,   32,   24
  pose 0x9B45, FileD3DA_Obj_30,    4,          -40,  -72,   24,   24
  pose 0x9B46, FileD3DA_Obj_34,    4,          -48,  -72,   24,   24
  pose 0x9B47, FileD3DA_Obj_38,    5,          -48,  -72,   24,   24
  pose 0xD981, FileD3DA_Obj_43,    5,          -48,  -89,   24,   16
  pose 0xDD81, FileD3DA_Obj_48,    5,          -52,  -87,   24,   16
  pose 0xD97F, FileD3DA_Obj_53,    5,          -48,  -83,   24,   16
  pose 0xDD7F, FileD3DA_Obj_58,    5,          -54,  -83,   23,   16
  pose 0xDB81, FileD3DA_Obj_63,    4,          -48,  -80,   24,   16
  pose 0xDF81, FileD3DA_Obj_67,    4,          -48,  -80,   24,   16
  pose 0xDB7F, FileD3DA_Obj_71,    4,          -48,  -80,   24,   16
  pose 0xDF7F, FileD3DA_Obj_75,    4,          -49,  -80,   23,   16
  pose 0x5C35, FileD3DA_Obj_79,    8,          -56,  -64,   24,   32
  pose 0x5C36, FileD3DA_Obj_87,    8,          -48,  -64,   24,   32
  pose 0x5C37, FileD3DA_Obj_95,    7,          -48,  -64,   24,   32
  pose 0x5C38, FileD3DA_Obj_102,   7,          -53,  -64,   24,   32
  pose 0x5C39, FileD3DA_Obj_109,   10,         -96, -104,   32,   24
  pose 0x5C3A, FileD3DA_Obj_119,   10,         -96, -104,   32,   24
  pose 0xDC35, FileD3DA_Obj_129,   5,          -56,  -64,   24,   32
  pose 0xDC36, FileD3DA_Obj_134,   5,          -48,  -64,   24,   32
  pose 0xDC37, FileD3DA_Obj_139,   5,          -48,  -64,   24,   32
  pose 0xDC38, FileD3DA_Obj_144,   5,          -48,  -64,   24,   32
  pose 0xDC39, FileD3DA_Obj_149,   7,          -96, -104,   32,   24
  pose 0xDC3A, FileD3DA_Obj_156,   7,          -96, -104,   32,   24
  pose 0x24BC, FileD3DA_Obj_163,   5,          -56,  -79,   24,   24
  pose 0x24BD, FileD3DA_Obj_168,   5,          -48,  -77,   32,   24
  pose 0x24BE, FileD3DA_Obj_173,   5,          -48,  -83,   32,   32
  pose 0x24BF, FileD3DA_Obj_178,   4,          -48,  -73,   24,   24
  pose 0x24C0, FileD3DA_Obj_182,   5,          -56,  -72,   24,   24
  pose 0xA4BC, FileD3DA_Obj_187,   4,          -56,  -72,   24,   24
  pose 0xA4BD, FileD3DA_Obj_191,   5,          -48,  -72,   32,   24
  pose 0xA4BE, FileD3DA_Obj_196,   5,          -48,  -72,   32,   32
  pose 0xA4BF, FileD3DA_Obj_201,   3,          -48,  -72,   24,   24
  pose 0xA4C0, FileD3DA_Obj_204,   4,          -56,  -72,   24,   24
  pose 0x6AEE, FileD3DA_Obj_208,   6,          -56,  -81,   33,   32
  pose 0x6EEE, FileD3DA_Obj_214,   6,          -44,  -75,   35,   33
  pose 0x72EE, FileD3DA_Obj_220,   8,          -56,  -93,   32,   15
  pose 0x76EE, FileD3DA_Obj_228,   9,          -56,  -93,   40,   19
  pose 0x7AEE, FileD3DA_Obj_237,   9,          -56,  -93,   40,   19
  pose 0x7EEE, FileD3DA_Obj_246,   9,          -48,  -93,   40,   32
  pose 0x82EE, FileD3DA_Obj_255,   9,          -44,  -93,   40,   33
  pose 0x86EE, FileD3DA_Obj_264,   5,          -45,  -76,   27,   34
  pose 0x8AEE, FileD3DA_Obj_269,   5,          -45,  -78,  308,  284
  pose 0x6AEC, FileD3DA_Obj_274,   7,          -56,  -72,   25,   24
  pose 0x6EEC, FileD3DA_Obj_281,   5,          -58,  -76,   27,   16
  pose 0x72EC, FileD3DA_Obj_286,   10,         -51,  -77,   45,   12
  pose 0x76EC, FileD3DA_Obj_296,   10,         -49,  -79,   45,   20
  pose 0x7AEC, FileD3DA_Obj_306,   10,         -51,  -80,   45,   20
  pose 0x7EEC, FileD3DA_Obj_316,   7,          -46,  -81,   45,   20
  pose 0x82EC, FileD3DA_Obj_323,   6,          -46,  -82,   45,   20
  pose 0x86EC, FileD3DA_Obj_329,   4,          -47,  -83,   27,    0
  pose 0x8AEC, FileD3DA_Obj_333,   4,          -51,  -81,   19,   15
  pose 0x6CEE, FileD3DA_Obj_337,   5,          -56,  -80,   24,   32
  pose 0x70EE, FileD3DA_Obj_342,   6,          -44,  -73,   35,   33
  pose 0x74EE, FileD3DA_Obj_348,   7,          -56,  -93,   32,   15
  pose 0x78EE, FileD3DA_Obj_355,   8,          -56,  -93,   40,   19
  pose 0x7CEE, FileD3DA_Obj_363,   8,          -56,  -93,   40,   19
  pose 0x80EE, FileD3DA_Obj_371,   8,          -48,  -93,   40,   32
  pose 0x84EE, FileD3DA_Obj_379,   8,          -44,  -93,   40,   33
  pose 0x88EE, FileD3DA_Obj_387,   4,          -45,  -76,   27,   34
  pose 0x8CEE, FileD3DA_Obj_391,   3,          -45,  -78,   22,   31
  pose 0x6CEC, FileD3DA_Obj_394,   6,          -56,  -72,   24,   24
  pose 0x70EC, FileD3DA_Obj_400,   5,          -58,  -74,   14,   16
  pose 0x74EC, FileD3DA_Obj_405,   10,         -51,  -76,   45,   12
  pose 0x78EC, FileD3DA_Obj_415,   10,         -49,  -74,   45,   20
  pose 0x7CEC, FileD3DA_Obj_425,   10,         -51,  -75,   45,   20
  pose 0x80EC, FileD3DA_Obj_435,   7,          -46,  -76,   45,   20
  pose 0x84EC, FileD3DA_Obj_442,   6,          -46,  -77,   45,   20
  pose 0x88EC, FileD3DA_Obj_448,   4,          -47,  -77,   27,    0
  pose 0x8CEC, FileD3DA_Obj_452,   4,          -51,  -77,   19,   15
  pose 0x21E0, FileD3DA_Obj_456,   6,          -48,  -80,   24,   32
  pose 0x21E1, FileD3DA_Obj_462,   6,          -48,  -80,   24,   16
  pose 0x21E2, FileD3DA_Obj_468,   7,          -48,  -72,   24,   24
  pose 0x21E3, FileD3DA_Obj_475,   4,          -48,  -72,   24,   24
  pose 0x21E4, FileD3DA_Obj_479,   4,          -48,  -72,   24,   24
  pose 0x21E5, FileD3DA_Obj_483,   6,          -48,  -72,   24,   24
  pose 0x1A0B, FileD3DA_Obj_489,   4,          -48,  -72,   16,   16
  pose 0x1A0C, FileD3DA_Obj_493,   3,          -48,  -72,   16,   24
  pose 0x1A0D, FileD3DA_Obj_496,   4,          -48,  -70,   16,   16
  pose 0x1A0E, FileD3DA_Obj_500,   3,          -48,  -56,   16,   24
  pose 0x1A0F, FileD3DA_Obj_503,   1,          -24,  -40,    8,    0
  pose 0x1A10, FileD3DA_Obj_504,   1,          -24,  -24,    8,    8
  pose 0x1A11, FileD3DA_Obj_505,   1,          -24,  -24,    8,    8
  pose 0x1A12, FileD3DA_Obj_506,   3,          -48,  -48,   24,   16
  pose 0x42D7, FileD3DA_Obj_509,   1,          -48,  -40,   16,   24
  pose 0x1A13, FileD3DA_Obj_510,   2,          -48,  -56,   24,    8
  pose 0x42F7, FileD3DA_Obj_512,   3,          -52,  -56,   28,   40
  pose 0x1A14, FileD3DA_Obj_515,   4,          -55,  -78,   25,    2
  pose 0x47F7, FileD3DA_Obj_519,   3,          -56,  -72,   24,   16
  pose 0x1A3C, FileD3DA_Obj_522,   3,          -52,  -70,   28,   26
  pose 0x4817, FileD3DA_Obj_525,   3,          -53,  -57,   19,   39
  pose 0x1A3D, FileD3DA_Obj_528,   3,          -49,  -54,   23,   18
  pose 0x1A3E, FileD3DA_Obj_531,   3,          -48,  -56,   16,   40
  pose 0x1A3F, FileD3DA_Obj_534,   2,          -48,  -48,   16,   16
  pose 0x1A40, FileD3DA_Obj_536,   1,          -24,  -32,    8,    0
  pose 0x1A41, FileD3DA_Obj_537,   1,          -48,  -48,   16,   16
  pose 0x1A2B, FileD3DA_Obj_538,   3,          -48,  -64,   24,   32
  pose 0x1A2C, FileD3DA_Obj_541,   3,          -56,  -72,   24,   16
  pose 0x1A2D, FileD3DA_Obj_544,   4,          -96, -112,   32,   24
  pose 0x1A2E, FileD3DA_Obj_548,   4,          -96, -112,   32,   16
  pose 0x1A2F, FileD3DA_Obj_552,   5,          -64,  -80,   32,   16
  pose 0x1A30, FileD3DA_Obj_557,   4,          -64,  -80,   24,    0
  pose 0x1F22, FileD3DA_Obj_561,   5,          -49,  -78,   16,   32
  pose 0x2322, FileD3DA_Obj_566,   6,          -50,  -78,   16,   24
  pose 0x2722, FileD3DA_Obj_572,   6,          -52,  -80,   16,   16
  pose 0x2B22, FileD3DA_Obj_578,   6,          -51,  -79,   17,   17
  pose 0x2F22, FileD3DA_Obj_584,   6,          -50,  -78,   18,   18
  pose 0x1F20, FileD3DA_Obj_590,   5,          -48,  -79,   21,   24
  pose 0x2320, FileD3DA_Obj_595,   6,          -48,  -80,   24,   16
  pose 0x2720, FileD3DA_Obj_601,   7,          -56,  -77,   18,   24
  pose 0x2B20, FileD3DA_Obj_608,   7,          -55,  -78,   19,   23
  pose 0x2F20, FileD3DA_Obj_615,   7,          -54,  -79,   20,   22
  pose 0x9783, FileD3DA_Obj_622,   4,          -48,  -80,   24,   16
  pose 0x9B83, FileD3DA_Obj_626,   5,          -48,  -80,   32,   16
  pose 0x9F83, FileD3DA_Obj_631,   5,          -48,  -80,   24,   16
  pose 0x9781, FileD3DA_Obj_636,   4,          -48,  -80,   24,   16
  pose 0x9B81, FileD3DA_Obj_640,   7,          -48,  -80,   24,   32
  pose 0x9F81, FileD3DA_Obj_647,   6,          -48,  -80,   24,   16
  pose 0x2ED4, FileD3DA_Obj_653,   3,          -49,  -80,   24,    0
  pose 0x32D4, FileD3DA_Obj_656,   3,          -50,  -79,   23,    0
  pose 0x36D4, FileD3DA_Obj_659,   5,          -56,  -80,   16,   32
  pose 0x3AD4, FileD3DA_Obj_664,   5,          -57,  -79,   15,   33
  pose 0x42D4, FileD3DA_Obj_669,   8,          -56,  -73,   24,   24
  pose 0x46D4, FileD3DA_Obj_677,   8,          -56,  -80,   32,   24
  pose 0x4AD4, FileD3DA_Obj_685,   6,          -56,  -73,   32,   24
  pose 0x4ED4, FileD3DA_Obj_691,   5,          -56,  -73,   24,   24
  pose 0x52D4, FileD3DA_Obj_696,   6,          -56,  -73,   24,   24
  pose 0xF2D4, FileD3DA_Obj_702,   5,          -56,  -73,   24,   24
  pose 0xF6D4, FileD3DA_Obj_707,   4,          -40,  -73,   24,   24
  pose 0x2ED2, FileD3DA_Obj_711,   4,          -40,  -77,   26,   24
  pose 0x32D2, FileD3DA_Obj_715,   4,          -41,  -78,   25,   23
  pose 0x36D2, FileD3DA_Obj_719,   4,          -54,  -80,   16,   32
  pose 0x3AD2, FileD3DA_Obj_723,   4,          -55,  -81,   15,   31
  pose 0x42D2, FileD3DA_Obj_727,   7,          -56,  -72,   32,   24
  pose 0x46D2, FileD3DA_Obj_734,   7,          -56,  -72,   32,   24
  pose 0x4AD2, FileD3DA_Obj_741,   6,          -56,  -72,   32,   24
  pose 0x4ED2, FileD3DA_Obj_747,   7,          -56,  -72,   32,   24
  pose 0x52D2, FileD3DA_Obj_754,   9,          -48,  -72,   32,   24
  pose 0xF2D2, FileD3DA_Obj_763,   6,          -48,  -72,   32,   24
  pose 0xF6D2, FileD3DA_Obj_769,   6,          -40,  -72,   32,   16
  pose 0x30D4, FileD3DA_Obj_775,   2,          -40,  -80,   24,    0
  pose 0x34D4, FileD3DA_Obj_777,   2,          -41,  -79,   23,    0
  pose 0x38D4, FileD3DA_Obj_779,   4,          -48,  -80,   16,   32
  pose 0x3CD4, FileD3DA_Obj_783,   4,          -49,  -79,   15,   33
  pose 0x44D4, FileD3DA_Obj_787,   7,          -56,  -72,   24,   24
  pose 0x48D4, FileD3DA_Obj_794,   7,          -56,  -80,   32,   24
  pose 0x4CD4, FileD3DA_Obj_801,   5,          -56,  -72,   32,   24
  pose 0x50D4, FileD3DA_Obj_806,   4,          -56,  -72,   24,   24
  pose 0x54D4, FileD3DA_Obj_810,   5,          -56,  -72,   24,   24
  pose 0xF4D4, FileD3DA_Obj_815,   4,          -56,  -72,   24,   24
  pose 0xF8D4, FileD3DA_Obj_819,   3,          -40,  -72,   24,   24
  pose 0x30D2, FileD3DA_Obj_822,   3,          -40,  -72,   24,   24
  pose 0x34D2, FileD3DA_Obj_825,   3,          -41,  -73,   23,   23
  pose 0x38D2, FileD3DA_Obj_828,   3,          -48,  -80,   16,   32
  pose 0x3CD2, FileD3DA_Obj_831,   3,          -49,  -81,   15,   31
  pose 0x44D2, FileD3DA_Obj_834,   6,          -56,  -72,   24,   24
  pose 0x48D2, FileD3DA_Obj_840,   6,          -56,  -72,   24,   24
  pose 0x4CD2, FileD3DA_Obj_846,   5,          -56,  -72,   24,   24
  pose 0x50D2, FileD3DA_Obj_851,   6,          -56,  -72,   24,   24
  pose 0x54D2, FileD3DA_Obj_857,   9,          -48,  -72,   32,   24
  pose 0xF4D2, FileD3DA_Obj_866,   5,          -48,  -72,   24,   24
  pose 0xF8D2, FileD3DA_Obj_871,   5,          -40,  -72,   24,   16
  pose 0x8DC3, FileD3DA_Obj_876,   5,          -48,  -64,   24,   16
  pose 0x8DC4, FileD3DA_Obj_881,   4,          -52,  -68,   20,   28
  pose 0x8DC5, FileD3DA_Obj_885,   4,          -52,  -68,   20,   28
  pose 0x8DC6, FileD3DA_Obj_889,   4,          -52,  -68,   20,   28
  pose 0x0DC4, FileD3DA_Obj_893,   5,          -48,  -64,   24,   16
  pose 0x0DC5, FileD3DA_Obj_898,   4,          -52,  -68,   20,   28
  pose 0x0DC6, FileD3DA_Obj_902,   4,          -52,  -68,   20,   28
  pose 0x0DC7, FileD3DA_Obj_906,   4,          -52,  -68,   20,   28
  pose 0xE6EF, FileD3DA_Obj_910,   2,          -48,  -80,   16,    0
  pose 0xE6ED, FileD3DA_Obj_912,   2,          -48,  -80,   16,    0
  pose 0xEAEF, FileD3DA_Obj_914,   1,          -48,  -80,   16,    0
  pose 0xEAED, FileD3DA_Obj_915,   1,          -48,  -80,   16,    0
  pose 0x62C2, FileD3DA_Obj_916,   3,          -24,  -23,   16,    9
  pose 0x62C3, FileD3DA_Obj_919,   2,          -24,  -24,   16,    8
  pose 0x62C4, FileD3DA_Obj_921,   2,          -24,  -24,   16,    8
  pose 0x62C5, FileD3DA_Obj_923,   3,          -23,  -24,   17,    8
  pose 0x62C6, FileD3DA_Obj_926,   3,          -24,  -25,   16,    7
  pose 0x62C7, FileD3DA_Obj_929,   3,          -25,  -24,    8,    8
  pose 0x62C8, FileD3DA_Obj_932,   2,          -24,  -24,    8,    8
  pose 0x62C9, FileD3DA_Obj_934,   2,          -24,  -24,    8,    8
  pose 0x62CA, FileD3DA_Obj_936,   1,          -24,  -24,    8,    8
  pose 0x62CB, FileD3DA_Obj_937,   1,          -48,  -48,   16,   16
  pose 0x62F3, FileD3DA_Obj_938,   3,          -24,  -25,    9,    7
  pose 0x62F4, FileD3DA_Obj_941,   1,          -48,  -47,   16,   17
  pose 0x62F5, FileD3DA_Obj_942,   3,          -24,  -20,   16,   12
  pose 0x8DC7, FileD3DA_Obj_945,   5,          -52,  -68,   20,   28
  pose 0x0DC8, FileD3DA_Obj_950,   5,          -52,  -68,   20,   28
  pose 0xD53F, FileD3DA_Obj_955,   5,          -48,  -80,   28,   32
  pose 0xD540, FileD3DA_Obj_960,   6,          -48,  -80,   31,   32
  pose 0xD541, FileD3DA_Obj_966,   5,          -48,  -80,   18,   32
  pose 0xD542, FileD3DA_Obj_971,   4,          -48,  -80,   32,   32
  pose 0xD543, FileD3DA_Obj_975,   4,          -48,  -80,   32,   32
  pose 0x2691, FileD3DA_Obj_979,   4,          -48,  -80,   24,   32
  pose 0x2692, FileD3DA_Obj_983,   4,          -48,  -80,   24,   16
  pose 0x2693, FileD3DA_Obj_987,   5,          -48,  -72,   24,   24
  pose 0x2694, FileD3DA_Obj_992,   3,          -48,  -72,   24,   24
  pose 0x2695, FileD3DA_Obj_995,   3,          -48,  -72,   24,   24
  pose 0x2696, FileD3DA_Obj_998,   4,          -48,  -72,   24,   24

FileD3DA_Anims:
@ animation unk_0,  cmd,                cmdCount
  animation 0x1B43, FileD3DA_Cmd_0,     1
  animation 0x1B44, FileD3DA_Cmd_1,     1
  animation 0x1B45, FileD3DA_Cmd_2,     1
  animation 0x1B46, FileD3DA_Cmd_3,     1
  animation 0x1B47, FileD3DA_Cmd_4,     1
  animation 0x9B43, FileD3DA_Cmd_5,     1
  animation 0x9B44, FileD3DA_Cmd_6,     1
  animation 0x9B45, FileD3DA_Cmd_7,     1
  animation 0x9B46, FileD3DA_Cmd_8,     1
  animation 0x9B47, FileD3DA_Cmd_9,     1
  animation 0x6CBE, FileD3DA_Cmd_10,    2
  animation 0x70BE, FileD3DA_Cmd_12,    1
  animation 0x6CBC, FileD3DA_Cmd_13,    2
  animation 0x70BC, FileD3DA_Cmd_15,    1
  animation 0x6CCE, FileD3DA_Cmd_16,    2
  animation 0x70CE, FileD3DA_Cmd_18,    1
  animation 0x6CCC, FileD3DA_Cmd_19,    2
  animation 0x70CC, FileD3DA_Cmd_21,    1
  animation 0x2AE0, FileD3DA_Cmd_22,    2
  animation 0x2AE1, FileD3DA_Cmd_24,    1
  animation 0x2AE2, FileD3DA_Cmd_25,    1
  animation 0x2AE3, FileD3DA_Cmd_26,    2
  animation 0x2EE0, FileD3DA_Cmd_28,    2
  animation 0x2EE1, FileD3DA_Cmd_30,    1
  animation 0x2EE2, FileD3DA_Cmd_31,    1
  animation 0x2EE3, FileD3DA_Cmd_32,    2
  animation 0x6124, FileD3DA_Cmd_34,    1
  animation 0x6125, FileD3DA_Cmd_35,    1
  animation 0x6126, FileD3DA_Cmd_36,    1
  animation 0x6127, FileD3DA_Cmd_37,    1
  animation 0x6128, FileD3DA_Cmd_38,    1
  animation 0x6524, FileD3DA_Cmd_39,    1
  animation 0x6525, FileD3DA_Cmd_40,    1
  animation 0x6526, FileD3DA_Cmd_41,    1
  animation 0x6527, FileD3DA_Cmd_42,    1
  animation 0x6528, FileD3DA_Cmd_43,    1
  animation 0xD149, FileD3DA_Cmd_44,    1
  animation 0xD549, FileD3DA_Cmd_45,    8
  animation 0xD147, FileD3DA_Cmd_53,    1
  animation 0xD547, FileD3DA_Cmd_54,    8
  animation 0xD159, FileD3DA_Cmd_62,    1
  animation 0xD559, FileD3DA_Cmd_63,    8
  animation 0xD157, FileD3DA_Cmd_71,    1
  animation 0xD557, FileD3DA_Cmd_72,    8
  animation 0x810D, FileD3DA_Cmd_80,    10
  animation 0xD8CE, FileD3DA_Cmd_90,    7
  animation 0xD8D5, FileD3DA_Cmd_97,    1
  animation 0x1B4F, FileD3DA_Cmd_98,    1
  animation 0xD8D6, FileD3DA_Cmd_99,    1
  animation 0x1B6F, FileD3DA_Cmd_100,   1
  animation 0xD8D7, FileD3DA_Cmd_101,   1
  animation 0x206F, FileD3DA_Cmd_102,   1
  animation 0xD8FF, FileD3DA_Cmd_103,   1
  animation 0x208F, FileD3DA_Cmd_104,   1
  animation 0xD900, FileD3DA_Cmd_105,   1
  animation 0xD901, FileD3DA_Cmd_106,   1
  animation 0xD902, FileD3DA_Cmd_107,   2
  animation 0xD904, FileD3DA_Cmd_109,   7
  animation 0x6EEB, FileD3DA_Cmd_116,   2
  animation 0x72EB, FileD3DA_Cmd_118,   4
  animation 0x76EB, FileD3DA_Cmd_122,   2
  animation 0x6EE9, FileD3DA_Cmd_124,   2
  animation 0x72E9, FileD3DA_Cmd_126,   4
  animation 0x76E9, FileD3DA_Cmd_130,   2
  animation 0x7AAE, FileD3DA_Cmd_132,   3
  animation 0x7EAE, FileD3DA_Cmd_135,   2
  animation 0x7AAC, FileD3DA_Cmd_137,   3
  animation 0x7EAC, FileD3DA_Cmd_140,   2
  animation 0xB441, FileD3DA_Cmd_142,   13
  animation 0xB43F, FileD3DA_Cmd_155,   13
  animation 0xB841, FileD3DA_Cmd_168,   13
  animation 0xB83F, FileD3DA_Cmd_181,   13
  animation 0x1724, FileD3DA_Cmd_194,   12
  animation 0x1725, FileD3DA_Cmd_206,   12
  animation 0xE6EF, FileD3DA_Cmd_218,   1
  animation 0xE6ED, FileD3DA_Cmd_219,   1
  animation 0xEAEF, FileD3DA_Cmd_220,   1
  animation 0xEAED, FileD3DA_Cmd_221,   1
  animation 0x62C2, FileD3DA_Cmd_222,   9
  animation 0x62C3, FileD3DA_Cmd_231,   8
  animation 0x62C4, FileD3DA_Cmd_239,   1
  animation 0xD352, FileD3DA_Cmd_240,   2
  animation 0xD372, FileD3DA_Cmd_242,   2
  animation 0xD353, FileD3DA_Cmd_244,   1
  animation 0xD373, FileD3DA_Cmd_245,   1
  animation 0xB3C4, FileD3DA_Cmd_246,   5
  animation 0xB3C5, FileD3DA_Cmd_251,   4
  animation 0xEC42, FileD3DA_Cmd_255,   4
  animation 0xEC43, FileD3DA_Cmd_259,   2

1:
FileD3DA_Subsprites:
@   subsprite size,            x,    y,   tile,  pal
  FileD3DA_Obj_0:
    subsprite OAM_SIZE_32x32,  -16,  -40,   12,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,   76,    1
    subsprite OAM_SIZE_8x32,   -24,  -40,  128,    1
    subsprite OAM_SIZE_8x32,    16,  -40,  129,    1
    subsprite OAM_SIZE_32x16,  -11,  -46,  416,    1
  FileD3DA_Obj_5:
    subsprite OAM_SIZE_32x32,  -16,  -40,    8,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,   72,    1
    subsprite OAM_SIZE_16x16,   16,  -24,   98,    1
    subsprite OAM_SIZE_32x16,   -9,  -47,  448,    1
  FileD3DA_Obj_9:
    subsprite OAM_SIZE_32x32,   -8,  -40,    4,    1
    subsprite OAM_SIZE_32x16,   -8,   -8,   68,    1
    subsprite OAM_SIZE_32x16,  -16,  -46,  419,    1
  FileD3DA_Obj_12:
    subsprite OAM_SIZE_32x32,  -16,  -40,    0,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,   64,    1
    subsprite OAM_SIZE_8x16,    16,  -32,   96,    1
    subsprite OAM_SIZE_32x32,  -16,  -47,  267,    1
  FileD3DA_Obj_16:
    subsprite OAM_SIZE_32x32,  -16,  -40,  108,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,  172,    1
    subsprite OAM_SIZE_8x16,   -24,  -24,  100,    1
    subsprite OAM_SIZE_8x16,    16,  -24,  101,    1
    subsprite OAM_SIZE_32x32,  -11,  -47,  264,    1
  FileD3DA_Obj_21:
    subsprite OAM_SIZE_8x32,   -24,  -40,  128,    3
    subsprite OAM_SIZE_8x32,    16,  -40,  129,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,   12,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,   76,    3
    subsprite OAM_SIZE_16x8,    -8,  -48,  356,    3
  FileD3DA_Obj_26:
    subsprite OAM_SIZE_16x8,    -8,  -48,  380,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,   72,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,    8,    3
    subsprite OAM_SIZE_16x16,   16,  -24,   98,    3
  FileD3DA_Obj_30:
    subsprite OAM_SIZE_16x8,    -8,  -48,  378,    3
    subsprite OAM_SIZE_32x32,   -8,  -40,    4,    3
    subsprite OAM_SIZE_32x16,   -8,   -8,   68,    3
    subsprite OAM_SIZE_8x8,      8,  -48,   97,    3
  FileD3DA_Obj_34:
    subsprite OAM_SIZE_16x8,    -8,  -48,  376,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,   64,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,    0,    3
    subsprite OAM_SIZE_8x16,    16,  -32,   96,    3
  FileD3DA_Obj_38:
    subsprite OAM_SIZE_8x16,   -24,  -24,  100,    3
    subsprite OAM_SIZE_8x16,    16,  -24,  101,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,  108,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,  172,    3
    subsprite OAM_SIZE_16x8,    -8,  -48,  372,    3
  FileD3DA_Obj_43:
    subsprite OAM_SIZE_32x32,  -16,  -48,  256,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  320,    1
    subsprite OAM_SIZE_8x8,      0,    0,  611,    1
    subsprite OAM_SIZE_8x32,    16,  -32,  130,    1
    subsprite OAM_SIZE_32x32,  -13,  -57,  312,    1
  FileD3DA_Obj_48:
    subsprite OAM_SIZE_32x32,  -16,  -48,  260,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  324,    1
    subsprite OAM_SIZE_8x8,      0,    0,  627,    1
    subsprite OAM_SIZE_8x32,    16,  -40,  131,    1
    subsprite OAM_SIZE_32x32,  -20,  -55,  315,    1
  FileD3DA_Obj_53:
    subsprite OAM_SIZE_32x32,  -16,  -48,  136,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  228,    1
    subsprite OAM_SIZE_8x8,     -8,    0,  250,    1
    subsprite OAM_SIZE_8x8,     16,  -24,  113,    1
    subsprite OAM_SIZE_32x16,  -12,  -51,  384,    1
  FileD3DA_Obj_58:
    subsprite OAM_SIZE_32x32,  -17,  -48,  132,    1
    subsprite OAM_SIZE_32x16,  -17,  -16,  196,    1
    subsprite OAM_SIZE_16x8,   -17,    0,  234,    1
    subsprite OAM_SIZE_8x16,    15,  -32,  102,    1
    subsprite OAM_SIZE_32x16,  -22,  -51,  387,    1
  FileD3DA_Obj_63:
    subsprite OAM_SIZE_8x32,    16,  -32,  130,    3
    subsprite OAM_SIZE_32x32,  -16,  -48,  256,    3
    subsprite OAM_SIZE_32x16,  -16,  -16,  320,    3
    subsprite OAM_SIZE_8x8,      0,    0,  611,    3
  FileD3DA_Obj_67:
    subsprite OAM_SIZE_8x32,    16,  -40,  131,    3
    subsprite OAM_SIZE_32x32,  -16,  -48,  260,    3
    subsprite OAM_SIZE_32x16,  -16,  -16,  324,    3
    subsprite OAM_SIZE_8x8,      0,    0,  627,    3
  FileD3DA_Obj_71:
    subsprite OAM_SIZE_8x8,     16,  -24,  113,    3
    subsprite OAM_SIZE_32x32,  -16,  -48,  136,    3
    subsprite OAM_SIZE_32x16,  -16,  -16,  228,    3
    subsprite OAM_SIZE_8x8,     -8,    0,  250,    3
  FileD3DA_Obj_75:
    subsprite OAM_SIZE_8x16,    15,  -32,  102,    3
    subsprite OAM_SIZE_32x32,  -17,  -48,  132,    3
    subsprite OAM_SIZE_32x16,  -17,  -16,  196,    3
    subsprite OAM_SIZE_16x8,   -17,    0,  234,    3
  FileD3DA_Obj_79:
    subsprite OAM_SIZE_32x32,  -24,  -32,  459,    1
    subsprite OAM_SIZE_16x32,    8,  -32,  640,    1
    subsprite OAM_SIZE_32x8,   -24,    0,  620,    1
    subsprite OAM_SIZE_16x8,     8,    0,  121,    1
    subsprite OAM_SIZE_16x8,    -8,  -40,  105,    1
    subsprite OAM_SIZE_16x16,  -11,  -32,  192,    1
    subsprite OAM_SIZE_32x8,   -11,  -16,  224,    1
    subsprite OAM_SIZE_8x16,     5,  -32,  194,    1
  FileD3DA_Obj_87:
    subsprite OAM_SIZE_32x32,  -16,  -32,  520,    1
    subsprite OAM_SIZE_32x16,  -16,    0,  584,    1
    subsprite OAM_SIZE_16x8,    -8,  -40, 2530,    1
    subsprite OAM_SIZE_8x8,    -24,    0,  107,    1
    subsprite OAM_SIZE_8x32,    16,  -16,  399,    1
    subsprite OAM_SIZE_16x16,  -12,  -39, 1098,    1
    subsprite OAM_SIZE_32x8,   -12,  -23, 1116,    1
    subsprite OAM_SIZE_8x16,     4,  -39,  359,    1
  FileD3DA_Obj_95:
    subsprite OAM_SIZE_32x32,  -16,  -32,  524,    1
    subsprite OAM_SIZE_32x16,  -16,    0,  588,    1
    subsprite OAM_SIZE_8x16,   -24,   -8,  484,    1
    subsprite OAM_SIZE_8x8,     16,   -8,  123,    1
    subsprite OAM_SIZE_16x16,  -11,  -39,  391,    1
    subsprite OAM_SIZE_8x16,     5,  -39,  393,    1
    subsprite OAM_SIZE_32x8,   -11,  -23,  423,    1
  FileD3DA_Obj_102:
    subsprite OAM_SIZE_8x8,    -24,   -8,  123,    1, xflip=1
    subsprite OAM_SIZE_32x16,  -16,    0,  588,    1, xflip=1
    subsprite OAM_SIZE_8x16,    16,   -8,  484,    1, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -32,  524,    1, xflip=1
    subsprite OAM_SIZE_32x8,   -21,  -23,  423,    1, xflip=1
    subsprite OAM_SIZE_8x16,   -13,  -39,  393,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -5,  -39,  391,    1, xflip=1
  FileD3DA_Obj_109:
    subsprite OAM_SIZE_64x32,  -32,  -40,  512,    1
    subsprite OAM_SIZE_8x8,     -8,  -48,  917,    1
    subsprite OAM_SIZE_16x8,   -32,   -8,  624,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,  576,    1
    subsprite OAM_SIZE_8x8,    -16,    8,  626,    1
    subsprite OAM_SIZE_8x8,      8,    8,  610,    1
    subsprite OAM_SIZE_16x8,    16,   -8,  608,    1
    subsprite OAM_SIZE_16x16,  -10,  -41,  395,    1
    subsprite OAM_SIZE_32x8,   -10,  -25,  439,    1
    subsprite OAM_SIZE_8x16,     6,  -41,  394,    1
  FileD3DA_Obj_119:
    subsprite OAM_SIZE_64x32,  -32,  -40,  512,    1, xflip=1
    subsprite OAM_SIZE_8x8,      0,  -48,  917,    1, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -8,  576,    1, xflip=1
    subsprite OAM_SIZE_16x8,    16,   -8,  624,    1, xflip=1
    subsprite OAM_SIZE_8x8,      8,    8,  626,    1, xflip=1
    subsprite OAM_SIZE_8x8,    -16,    8,  610,    1, xflip=1
    subsprite OAM_SIZE_16x8,   -32,   -8,  608,    1, xflip=1
    subsprite OAM_SIZE_16x16,   -6,  -41,  395,    1, xflip=1
    subsprite OAM_SIZE_32x8,   -22,  -25,  439,    1, xflip=1
    subsprite OAM_SIZE_8x16,   -14,  -41,  394,    1, xflip=1
  FileD3DA_Obj_129:
    subsprite OAM_SIZE_32x32,  -24,  -32,  459,    3
    subsprite OAM_SIZE_16x32,    8,  -32,  640,    3
    subsprite OAM_SIZE_32x8,   -24,    0,  620,    3
    subsprite OAM_SIZE_16x8,     8,    0,  121,    3
    subsprite OAM_SIZE_16x8,    -8,  -40,  105,    3
  FileD3DA_Obj_134:
    subsprite OAM_SIZE_8x32,    16,  -16,  399,    3
    subsprite OAM_SIZE_8x8,    -24,    0,  107,    3
    subsprite OAM_SIZE_32x32,  -16,  -32,  520,    3
    subsprite OAM_SIZE_32x16,  -16,    0,  584,    3
    subsprite OAM_SIZE_16x8,    -8,  -40, 2530,    3
  FileD3DA_Obj_139:
    subsprite OAM_SIZE_16x16,   -8,  -48,  103,    3
    subsprite OAM_SIZE_8x8,     16,   -8,  123,    3
    subsprite OAM_SIZE_32x32,  -16,  -32,  524,    3
    subsprite OAM_SIZE_32x16,  -16,    0,  588,    3
    subsprite OAM_SIZE_8x16,   -24,   -8,  484,    3
  FileD3DA_Obj_144:
    subsprite OAM_SIZE_16x16,   -8,  -48,  103,    3, xflip=1
    subsprite OAM_SIZE_32x32,  -16,  -32,  524,    3, xflip=1
    subsprite OAM_SIZE_8x8,    -24,   -8,  123,    3, xflip=1
    subsprite OAM_SIZE_32x16,  -16,    0,  588,    3, xflip=1
    subsprite OAM_SIZE_8x16,    16,   -8,  484,    3, xflip=1
  FileD3DA_Obj_149:
    subsprite OAM_SIZE_64x32,  -32,  -40,  512,    3
    subsprite OAM_SIZE_8x8,     -8,  -48,  917,    3
    subsprite OAM_SIZE_16x8,   -32,   -8,  624,    3
    subsprite OAM_SIZE_16x8,    16,   -8,  608,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,  576,    3
    subsprite OAM_SIZE_8x8,    -16,    8,  626,    3
    subsprite OAM_SIZE_8x8,      8,    8,  610,    3
  FileD3DA_Obj_156:
    subsprite OAM_SIZE_64x32,  -32,  -40,  512,    3, xflip=1
    subsprite OAM_SIZE_16x8,   -32,   -8,  608,    3, xflip=1
    subsprite OAM_SIZE_32x16,  -16,   -8,  576,    3, xflip=1
    subsprite OAM_SIZE_8x8,      0,  -48,  917,    3, xflip=1
    subsprite OAM_SIZE_8x8,      8,    8,  626,    3, xflip=1
    subsprite OAM_SIZE_8x8,    -16,    8,  610,    3, xflip=1
    subsprite OAM_SIZE_16x8,    16,   -8,  624,    3, xflip=1
  FileD3DA_Obj_163:
    subsprite OAM_SIZE_32x32,  -24,  -40,  768,    1
    subsprite OAM_SIZE_16x32,    8,  -40,  772,    1
    subsprite OAM_SIZE_16x8,    -8,  -48,  900,    1
    subsprite OAM_SIZE_32x8,   -16,   -8,  944,    1
    subsprite OAM_SIZE_32x16,  -20,  -47,  451,    1
  FileD3DA_Obj_168:
    subsprite OAM_SIZE_32x32,  -16,  -40,  710,    1
    subsprite OAM_SIZE_16x32,   16,  -40,  714,    1
    subsprite OAM_SIZE_32x8,    -8,   -8,  732,    1
    subsprite OAM_SIZE_8x8,      8,  -48,  367,    1
    subsprite OAM_SIZE_32x16,   -5,  -45,  480,    1
  FileD3DA_Obj_173:
    subsprite OAM_SIZE_32x32,  -16,  -32,  704,    1
    subsprite OAM_SIZE_16x32,   16,  -32,  708,    1
    subsprite OAM_SIZE_32x8,    -8,  -40,  700,    1
    subsprite OAM_SIZE_32x8,    -8,    0,  716,    1
    subsprite OAM_SIZE_32x32,    0,  -51,  880,    1
  FileD3DA_Obj_178:
    subsprite OAM_SIZE_32x32,  -16,  -40,  648,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,  668,    1
    subsprite OAM_SIZE_8x16,    16,  -16,  335,    1
    subsprite OAM_SIZE_32x32,  -15,  -41,  835,    1
  FileD3DA_Obj_182:
    subsprite OAM_SIZE_32x32,  -24,  -40,  642,    1
    subsprite OAM_SIZE_16x32,    8,  -40,  646,    1
    subsprite OAM_SIZE_32x16,  -24,   -8,  636,    1
    subsprite OAM_SIZE_16x16,    8,   -8,  485,    1
    subsprite OAM_SIZE_32x32,  -12,  -39,  832,    1
  FileD3DA_Obj_187:
    subsprite OAM_SIZE_32x32,  -24,  -40,  768,    3
    subsprite OAM_SIZE_16x32,    8,  -40,  772,    3
    subsprite OAM_SIZE_16x8,    -8,  -48,  900,    3
    subsprite OAM_SIZE_32x8,   -16,   -8,  944,    3
  FileD3DA_Obj_191:
    subsprite OAM_SIZE_16x8,    -8,  -48,  382,    3
    subsprite OAM_SIZE_8x8,      8,  -48,  367,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,  710,    3
    subsprite OAM_SIZE_16x32,   16,  -40,  714,    3
    subsprite OAM_SIZE_32x8,    -8,   -8,  732,    3
  FileD3DA_Obj_196:
    subsprite OAM_SIZE_8x8,      8,  -40,  243,    3
    subsprite OAM_SIZE_32x8,    -8,    0,  716,    3
    subsprite OAM_SIZE_32x32,  -16,  -32,  704,    3
    subsprite OAM_SIZE_16x32,   16,  -32,  708,    3
    subsprite OAM_SIZE_32x8,    -8,  -40,  700,    3
  FileD3DA_Obj_201:
    subsprite OAM_SIZE_8x16,    16,  -16,  335,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,  648,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,  668,    3
  FileD3DA_Obj_204:
    subsprite OAM_SIZE_16x16,    8,   -8,  485,    3
    subsprite OAM_SIZE_32x32,  -24,  -40,  642,    3
    subsprite OAM_SIZE_16x32,    8,  -40,  646,    3
    subsprite OAM_SIZE_32x16,  -24,   -8,  636,    3
  FileD3DA_Obj_208:
    subsprite OAM_SIZE_32x32,  -24,  -32, 1062,    1
    subsprite OAM_SIZE_8x16,   -32,  -24, 1092,    1
    subsprite OAM_SIZE_32x8,   -24,    0, 2672,    1
    subsprite OAM_SIZE_32x16,   -8,  -48, 1030,    1
    subsprite OAM_SIZE_16x32,    8,  -32, 1034,    1
    subsprite OAM_SIZE_32x16,    1,  -49,  480,    1
  FileD3DA_Obj_214:
    subsprite OAM_SIZE_32x8,   -12,    1, 1472,    1
    subsprite OAM_SIZE_32x32,  -12,  -31, 1408,    1
    subsprite OAM_SIZE_8x8,     -5,  -25, 2132,    1
    subsprite OAM_SIZE_16x32,  -13,  -57, 1122,    1
    subsprite OAM_SIZE_32x16,    3,  -33, 2144,    1
    subsprite OAM_SIZE_32x16,   -4,  -43,  480,    1
  FileD3DA_Obj_220:
    subsprite OAM_SIZE_8x16,    22,  -25, 1376,    1
    subsprite OAM_SIZE_16x8,    -2,   -1, 1377,    1
    subsprite OAM_SIZE_32x32,  -10,  -33, 1420,    1
    subsprite OAM_SIZE_32x32,   -8,  -46, 1124,    1
    subsprite OAM_SIZE_32x16,   -6,  -43,  480,    1
    subsprite OAM_SIZE_32x32,  -24,  -61, 1356,    2
    subsprite OAM_SIZE_32x32,    0,  -29, 1480,    2
    subsprite OAM_SIZE_8x8,     -8,   -5, 1379,    2
  FileD3DA_Obj_228:
    subsprite OAM_SIZE_16x8,    -3,    0, 1377,    1
    subsprite OAM_SIZE_32x32,  -11,  -32, 1420,    1
    subsprite OAM_SIZE_8x16,    21,  -24, 1376,    1
    subsprite OAM_SIZE_32x32,   -9,  -45, 1124,    1
    subsprite OAM_SIZE_32x16,   -7,  -42,  480,    1
    subsprite OAM_SIZE_32x32,  -24,  -61, 1416,    2
    subsprite OAM_SIZE_8x16,     8,  -61, 1504,    2
    subsprite OAM_SIZE_32x32,    8,  -45, 1352,    2
    subsprite OAM_SIZE_32x16,    0,  -13, 1568,    2
  FileD3DA_Obj_237:
    subsprite OAM_SIZE_32x32,  -12,  -32, 1420,    1
    subsprite OAM_SIZE_8x16,    20,  -24, 1376,    1
    subsprite OAM_SIZE_32x32,  -10,  -44, 1124,    1
    subsprite OAM_SIZE_16x8,    -4,    0, 1377,    1
    subsprite OAM_SIZE_32x16,   -8,  -41,  480,    1
    subsprite OAM_SIZE_32x16,  -24,  -61, 1536,    2
    subsprite OAM_SIZE_16x16,    8,  -61, 1294,    2
    subsprite OAM_SIZE_32x32,    8,  -45, 1476,    2
    subsprite OAM_SIZE_32x16,    8,  -13, 1505,    2
  FileD3DA_Obj_246:
    subsprite OAM_SIZE_8x16,    21,  -24, 2127,    1
    subsprite OAM_SIZE_32x8,   -11,    0, 1488,    1
    subsprite OAM_SIZE_32x32,  -11,  -32, 1286,    1
    subsprite OAM_SIZE_32x32,  -12,  -43, 1128,    1
    subsprite OAM_SIZE_32x16,   -9,  -40,  480,    1
    subsprite OAM_SIZE_32x16,  -16,  -61, 1600,    2
    subsprite OAM_SIZE_32x32,    8,  -45, 1540,    2
    subsprite OAM_SIZE_16x16,   16,  -61, 1326,    2
    subsprite OAM_SIZE_16x8,    17,  -14, 1778,    2
  FileD3DA_Obj_255:
    subsprite OAM_SIZE_32x8,   -12,    1, 1488,    1
    subsprite OAM_SIZE_8x16,    20,  -23, 2127,    1
    subsprite OAM_SIZE_32x32,  -12,  -31, 1286,    1
    subsprite OAM_SIZE_32x32,  -12,  -44, 1128,    1
    subsprite OAM_SIZE_32x16,   -9,  -41,  480,    1
    subsprite OAM_SIZE_32x32,    8,  -45, 1548,    2
    subsprite OAM_SIZE_8x8,     24,  -13, 1431,    2
    subsprite OAM_SIZE_32x16,   -8,  -61, 1544,    2
    subsprite OAM_SIZE_8x8,     24,  -53,  916,    2
  FileD3DA_Obj_264:
    subsprite OAM_SIZE_32x8,   -13,    2, 1488,    1
    subsprite OAM_SIZE_32x32,  -13,  -30, 1286,    1
    subsprite OAM_SIZE_8x16,    19,  -22, 2127,    1
    subsprite OAM_SIZE_32x32,  -13,  -44, 1128,    1
    subsprite OAM_SIZE_32x16,  -10,  -41,  480,    1
  FileD3DA_Obj_269:
    subsprite OAM_SIZE_32x32,  -13,  -33, 1408,    1
    subsprite OAM_SIZE_32x8,   -13,   -1, 1472,    1
    subsprite OAM_SIZE_32x32,  -10,  -46, 1128,    1
    subsprite OAM_SIZE_32x16,   -7,  -43,  480,    1
    subsprite OAM_SIZE_8x8,    300,  276,  204,    1
  FileD3DA_Obj_274:
    subsprite OAM_SIZE_32x32,  -24,  -40, 1024,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 1088,    1
    subsprite OAM_SIZE_16x32,    8,  -24, 1028,    1
    subsprite OAM_SIZE_8x8,      8,  -32, 3016,    1
    subsprite OAM_SIZE_8x8,    -32,  -24, 1109,    1
    subsprite OAM_SIZE_8x8,     -8,  -48, 1093,    1
    subsprite OAM_SIZE_16x16,    9,  -16, 1132,    1
  FileD3DA_Obj_281:
    subsprite OAM_SIZE_32x32,  -20,  -32, 1411,    1
    subsprite OAM_SIZE_16x32,   -2,  -58, 1120,    1
    subsprite OAM_SIZE_32x16,  -26,  -34, 2112,    1
    subsprite OAM_SIZE_16x8,   -12,    0, 1393,    1
    subsprite OAM_SIZE_32x32,   -5,  -44, 1280,    1
  FileD3DA_Obj_286:
    subsprite OAM_SIZE_32x32,  -16,  -31, 1290,    1
    subsprite OAM_SIZE_8x16,    16,  -23, 2159,    1
    subsprite OAM_SIZE_8x8,     -8,    1, 1347,    1
    subsprite OAM_SIZE_8x16,    19,  -32, 2122,    1
    subsprite OAM_SIZE_32x32,  -13,  -40, 2118,    1
    subsprite OAM_SIZE_32x32,   -6,  -45, 1280,    1
    subsprite OAM_SIZE_32x32,   13,  -44, 1676,    2
    subsprite OAM_SIZE_8x8,     37,  -12, 1395,    2
    subsprite OAM_SIZE_32x32,  -19,  -20, 1612,    2
    subsprite OAM_SIZE_8x8,    -19,  -28, 1415,    2
  FileD3DA_Obj_296:
    subsprite OAM_SIZE_32x32,  -17,  -32, 1290,    1
    subsprite OAM_SIZE_8x16,    15,  -24, 2159,    1
    subsprite OAM_SIZE_8x8,     -9,    0, 1347,    1
    subsprite OAM_SIZE_8x16,    17,  -34, 2122,    1
    subsprite OAM_SIZE_32x32,  -15,  -42, 2118,    1
    subsprite OAM_SIZE_32x32,   -8,  -47, 1280,    1
    subsprite OAM_SIZE_16x32,   21,  -44, 1633,    2
    subsprite OAM_SIZE_16x32,   29,  -36, 1650,    2
    subsprite OAM_SIZE_32x32,  -11,  -12, 1740,    2
    subsprite OAM_SIZE_8x32,   -19,  -20, 1632,    2
  FileD3DA_Obj_306:
    subsprite OAM_SIZE_32x32,  -19,  -34, 1290,    1
    subsprite OAM_SIZE_8x16,    13,  -26, 2159,    1
    subsprite OAM_SIZE_8x8,    -11,   -2, 1347,    1
    subsprite OAM_SIZE_8x16,    16,  -35, 2122,    1
    subsprite OAM_SIZE_32x32,  -16,  -43, 2118,    1
    subsprite OAM_SIZE_32x32,   -9,  -48, 1280,    1
    subsprite OAM_SIZE_32x32,  -11,  -12, 1576,    2
    subsprite OAM_SIZE_16x16,   21,   -4, 1760,    2
    subsprite OAM_SIZE_16x32,   29,  -28, 1606,    2
    subsprite OAM_SIZE_8x16,    29,  -44, 1447,    2
  FileD3DA_Obj_316:
    subsprite OAM_SIZE_8x8,     18,  -19, 1363,    1
    subsprite OAM_SIZE_32x32,  -14,  -35, 1484,    1
    subsprite OAM_SIZE_32x32,  -14,  -44, 2123,    1
    subsprite OAM_SIZE_32x32,  -10,  -49, 1280,    1
    subsprite OAM_SIZE_32x32,   -3,  -12, 1640,    2
    subsprite OAM_SIZE_16x32,   29,  -20, 1696,    2
    subsprite OAM_SIZE_16x16,   29,  -36, 1604,    2
  FileD3DA_Obj_323:
    subsprite OAM_SIZE_32x32,  -13,  -34, 1484,    1
    subsprite OAM_SIZE_8x8,     19,  -18, 1363,    1
    subsprite OAM_SIZE_32x32,  -14,  -45, 2123,    1
    subsprite OAM_SIZE_32x32,  -10,  -50, 1280,    1
    subsprite OAM_SIZE_32x32,   -3,  -12, 1704,    2
    subsprite OAM_SIZE_16x32,   29,  -20, 1714,    2
  FileD3DA_Obj_329:
    subsprite OAM_SIZE_32x32,  -13,  -33, 1484,    1
    subsprite OAM_SIZE_8x8,     19,  -17, 1363,    1
    subsprite OAM_SIZE_32x32,  -15,  -46, 2123,    1
    subsprite OAM_SIZE_32x32,  -11,  -51, 1280,    1
  FileD3DA_Obj_333:
    subsprite OAM_SIZE_32x32,  -19,  -33, 1411,    1
    subsprite OAM_SIZE_16x8,   -11,   -1, 1393,    1
    subsprite OAM_SIZE_32x32,  -13,  -45, 2123,    1
    subsprite OAM_SIZE_32x32,  -17,  -49,  267,    0
  FileD3DA_Obj_337:
    subsprite OAM_SIZE_32x32,  -24,  -32, 1062,    3
    subsprite OAM_SIZE_8x16,   -32,  -24, 1092,    3
    subsprite OAM_SIZE_32x8,   -24,    0, 2672,    3
    subsprite OAM_SIZE_32x16,   -8,  -48, 1030,    3
    subsprite OAM_SIZE_16x32,    8,  -32, 1034,    3
  FileD3DA_Obj_342:
    subsprite OAM_SIZE_32x32,  -12,  -31, 1408,    3
    subsprite OAM_SIZE_16x32,  -13,  -57, 1122,    3
    subsprite OAM_SIZE_32x8,   -12,    1, 1472,    3
    subsprite OAM_SIZE_8x8,     -5,  -25, 2132,    3
    subsprite OAM_SIZE_32x16,    3,  -33, 2144,    3
    subsprite OAM_SIZE_16x8,     3,  -41, 2116,    3
  FileD3DA_Obj_348:
    subsprite OAM_SIZE_8x16,    22,  -25, 1376,    3
    subsprite OAM_SIZE_16x8,    -2,   -1, 1377,    3
    subsprite OAM_SIZE_32x32,  -10,  -33, 1420,    3
    subsprite OAM_SIZE_32x32,   -8,  -46, 1124,    3
    subsprite OAM_SIZE_32x32,  -24,  -61, 1356,    4
    subsprite OAM_SIZE_32x32,    0,  -29, 1480,    4
    subsprite OAM_SIZE_8x8,     -8,   -5, 1379,    4
  FileD3DA_Obj_355:
    subsprite OAM_SIZE_16x8,    -3,    0, 1377,    3
    subsprite OAM_SIZE_32x32,  -11,  -32, 1420,    3
    subsprite OAM_SIZE_8x16,    21,  -24, 1376,    3
    subsprite OAM_SIZE_32x32,   -9,  -45, 1124,    3
    subsprite OAM_SIZE_32x32,  -24,  -61, 1416,    4
    subsprite OAM_SIZE_8x16,     8,  -61, 1504,    4
    subsprite OAM_SIZE_32x32,    8,  -45, 1352,    4
    subsprite OAM_SIZE_32x16,    0,  -13, 1568,    4
  FileD3DA_Obj_363:
    subsprite OAM_SIZE_16x8,    -4,    0, 1377,    3
    subsprite OAM_SIZE_32x32,  -12,  -32, 1420,    3
    subsprite OAM_SIZE_8x16,    20,  -24, 1376,    3
    subsprite OAM_SIZE_32x32,  -10,  -44, 1124,    3
    subsprite OAM_SIZE_32x16,  -24,  -61, 1536,    4
    subsprite OAM_SIZE_16x16,    8,  -61, 1294,    4
    subsprite OAM_SIZE_32x32,    8,  -45, 1476,    4
    subsprite OAM_SIZE_32x16,    8,  -13, 1505,    4
  FileD3DA_Obj_371:
    subsprite OAM_SIZE_8x16,    21,  -24, 2127,    3
    subsprite OAM_SIZE_32x8,   -11,    0, 1488,    3
    subsprite OAM_SIZE_32x32,  -11,  -32, 1286,    3
    subsprite OAM_SIZE_32x32,  -12,  -43, 1128,    3
    subsprite OAM_SIZE_32x16,  -16,  -61, 1600,    4
    subsprite OAM_SIZE_32x32,    8,  -45, 1540,    4
    subsprite OAM_SIZE_16x16,   16,  -61, 1326,    4
    subsprite OAM_SIZE_16x8,    16,  -13, 1778,    4
  FileD3DA_Obj_379:
    subsprite OAM_SIZE_32x8,   -12,    1, 1488,    3
    subsprite OAM_SIZE_8x16,    20,  -23, 2127,    3
    subsprite OAM_SIZE_32x32,  -12,  -31, 1286,    3
    subsprite OAM_SIZE_32x32,  -12,  -44, 1128,    3
    subsprite OAM_SIZE_32x32,    8,  -45, 1548,    4
    subsprite OAM_SIZE_8x8,     24,  -13, 1431,    4
    subsprite OAM_SIZE_8x8,     24,  -53,  916,    4
    subsprite OAM_SIZE_32x16,   -8,  -61, 1544,    4
  FileD3DA_Obj_387:
    subsprite OAM_SIZE_32x8,   -13,    2, 1488,    3
    subsprite OAM_SIZE_32x32,  -13,  -30, 1286,    3
    subsprite OAM_SIZE_8x16,    19,  -22, 2127,    3
    subsprite OAM_SIZE_32x32,  -13,  -44, 1128,    3
  FileD3DA_Obj_391:
    subsprite OAM_SIZE_32x32,  -13,  -33, 1408,    3
    subsprite OAM_SIZE_32x8,   -13,   -1, 1472,    3
    subsprite OAM_SIZE_32x32,  -10,  -46, 1128,    3
  FileD3DA_Obj_394:
    subsprite OAM_SIZE_8x8,     -8,  -48, 1093,    3
    subsprite OAM_SIZE_32x32,  -24,  -40, 1024,    3
    subsprite OAM_SIZE_32x16,  -24,   -8, 1088,    3
    subsprite OAM_SIZE_16x32,    8,  -24, 1028,    3
    subsprite OAM_SIZE_8x8,      8,  -32, 3016,    3
    subsprite OAM_SIZE_8x8,    -32,  -24, 1109,    3
  FileD3DA_Obj_400:
    subsprite OAM_SIZE_32x32,  -20,  -32, 1411,    3
    subsprite OAM_SIZE_32x16,  -26,  -34, 2112,    3
    subsprite OAM_SIZE_16x32,   -2,  -58, 1120,    3
    subsprite OAM_SIZE_16x8,   -12,    0, 1393,    3
    subsprite OAM_SIZE_16x32,   -3,  -43, 1284,    3
  FileD3DA_Obj_405:
    subsprite OAM_SIZE_32x32,  -16,  -31, 1290,    3
    subsprite OAM_SIZE_8x16,    16,  -23, 2159,    3
    subsprite OAM_SIZE_8x8,     -8,    1, 1347,    3
    subsprite OAM_SIZE_8x16,    19,  -32, 2122,    3
    subsprite OAM_SIZE_32x32,  -13,  -40, 2118,    3
    subsprite OAM_SIZE_16x32,   -4,  -44, 1284,    3
    subsprite OAM_SIZE_32x32,   13,  -44, 1676,    4
    subsprite OAM_SIZE_8x8,     37,  -12, 1395,    4
    subsprite OAM_SIZE_32x32,  -19,  -20, 1612,    4
    subsprite OAM_SIZE_8x8,    -19,  -28, 1415,    4
  FileD3DA_Obj_415:
    subsprite OAM_SIZE_32x32,  -17,  -32, 1290,    3
    subsprite OAM_SIZE_8x16,    15,  -24, 2159,    3
    subsprite OAM_SIZE_8x8,     -9,    0, 1347,    3
    subsprite OAM_SIZE_8x16,    17,  -34, 2122,    3
    subsprite OAM_SIZE_32x32,  -15,  -42, 2118,    3
    subsprite OAM_SIZE_16x32,   -6,  -46, 1284,    3
    subsprite OAM_SIZE_16x32,   21,  -44, 1633,    4
    subsprite OAM_SIZE_16x32,   29,  -36, 1650,    4
    subsprite OAM_SIZE_32x32,  -11,  -12, 1740,    4
    subsprite OAM_SIZE_8x32,   -19,  -20, 1632,    4
  FileD3DA_Obj_425:
    subsprite OAM_SIZE_32x32,  -19,  -34, 1290,    3
    subsprite OAM_SIZE_8x16,    13,  -26, 2159,    3
    subsprite OAM_SIZE_8x8,    -11,   -2, 1347,    3
    subsprite OAM_SIZE_8x16,    16,  -35, 2122,    3
    subsprite OAM_SIZE_32x32,  -16,  -43, 2118,    3
    subsprite OAM_SIZE_16x32,   -7,  -47, 1284,    3
    subsprite OAM_SIZE_32x32,  -11,  -12, 1576,    4
    subsprite OAM_SIZE_16x16,   21,   -4, 1760,    4
    subsprite OAM_SIZE_16x32,   29,  -28, 1606,    4
    subsprite OAM_SIZE_8x16,    29,  -44, 1447,    4
  FileD3DA_Obj_435:
    subsprite OAM_SIZE_8x8,     18,  -19, 1363,    3
    subsprite OAM_SIZE_32x32,  -14,  -35, 1484,    3
    subsprite OAM_SIZE_32x32,  -14,  -44, 2123,    3
    subsprite OAM_SIZE_16x32,   -8,  -48, 1284,    3
    subsprite OAM_SIZE_32x32,   -3,  -12, 1640,    4
    subsprite OAM_SIZE_16x32,   29,  -20, 1696,    4
    subsprite OAM_SIZE_16x16,   29,  -36, 1604,    4
  FileD3DA_Obj_442:
    subsprite OAM_SIZE_32x32,  -13,  -34, 1484,    3
    subsprite OAM_SIZE_8x8,     19,  -18, 1363,    3
    subsprite OAM_SIZE_32x32,  -14,  -45, 2123,    3
    subsprite OAM_SIZE_16x32,   -8,  -49, 1284,    3
    subsprite OAM_SIZE_32x32,   -3,  -12, 1704,    4
    subsprite OAM_SIZE_16x32,   29,  -20, 1714,    4
  FileD3DA_Obj_448:
    subsprite OAM_SIZE_32x32,  -13,  -33, 1484,    3
    subsprite OAM_SIZE_8x8,     19,  -17, 1363,    3
    subsprite OAM_SIZE_32x32,  -15,  -45, 2123,    3
    subsprite OAM_SIZE_16x32,   -9,  -49, 1284,    3
  FileD3DA_Obj_452:
    subsprite OAM_SIZE_32x32,  -19,  -33, 1411,    3
    subsprite OAM_SIZE_16x8,   -11,   -1, 1393,    3
    subsprite OAM_SIZE_32x32,  -13,  -45, 2123,    3
    subsprite OAM_SIZE_16x32,   -7,  -51, 1348,    3
  FileD3DA_Obj_456:
    subsprite OAM_SIZE_8x16,    16,  -24,  463,    1
    subsprite OAM_SIZE_32x32,  -16,  -48,  780,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  844,    1
    subsprite OAM_SIZE_32x8,   -16,    0,  876,    1
    subsprite OAM_SIZE_16x16,   -8,  -52, 3234,    1
    subsprite OAM_SIZE_8x8,    -16,  -44, 3312,    1
  FileD3DA_Obj_462:
    subsprite OAM_SIZE_8x16,    16,  -24,  495,    1
    subsprite OAM_SIZE_8x8,     -8,    0, 2658,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  856,    1
    subsprite OAM_SIZE_32x32,  -16,  -48,  792,    1
    subsprite OAM_SIZE_16x16,   -7,  -52, 3234,    1
    subsprite OAM_SIZE_8x8,    -15,  -44, 3312,    1
  FileD3DA_Obj_468:
    subsprite OAM_SIZE_8x16,    16,  -32,  871,    1
    subsprite OAM_SIZE_8x16,   -24,  -16,  839,    1
    subsprite OAM_SIZE_32x32,  -16,  -40,  892,    1
    subsprite OAM_SIZE_32x16,  -16,   -8, 1000,    1
    subsprite OAM_SIZE_16x8,     0,  -48,  890,    1
    subsprite OAM_SIZE_16x16,   -2,  -44, 3180,    1
    subsprite OAM_SIZE_8x8,     14,  -38, 3201,    1
  FileD3DA_Obj_475:
    subsprite OAM_SIZE_32x32,  -16,  -40,  932,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,  996,    1
    subsprite OAM_SIZE_8x16,    16,  -24,  902,    1
    subsprite OAM_SIZE_16x16,   -2,  -36, 3206,    0
  FileD3DA_Obj_479:
    subsprite OAM_SIZE_32x32,  -16,  -40,  960,    1
    subsprite OAM_SIZE_32x16,  -16,   -8, 1164,    1
    subsprite OAM_SIZE_8x16,    16,  -24, 2154,    1
    subsprite OAM_SIZE_16x16,   -2,  -37, 3206,    0
  FileD3DA_Obj_483:
    subsprite OAM_SIZE_8x16,    16,  -32,  903,    1
    subsprite OAM_SIZE_32x32,  -16,  -40,  904,    1
    subsprite OAM_SIZE_16x8,     0,  -48,  888,    1
    subsprite OAM_SIZE_32x16,  -16,   -8,  968,    1
    subsprite OAM_SIZE_16x16,   -2,  -44, 3180,    1
    subsprite OAM_SIZE_8x8,     14,  -38, 3201,    1
  FileD3DA_Obj_489:
    subsprite OAM_SIZE_32x32,  -16,  -32, 1668,    3
    subsprite OAM_SIZE_16x8,    -8,    0, 1974,    3
    subsprite OAM_SIZE_32x8,   -16,  -40,    0,    3
    subsprite OAM_SIZE_16x8,    -8,  -48,  376,    3
  FileD3DA_Obj_493:
    subsprite OAM_SIZE_32x32,  -16,  -40, 1792,    3
    subsprite OAM_SIZE_16x8,    -8,  -48,  372,    3
    subsprite OAM_SIZE_32x16,  -16,   -8, 1856,    3
  FileD3DA_Obj_496:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1796,    3
    subsprite OAM_SIZE_32x16,  -16,  -38, 1792,    3
    subsprite OAM_SIZE_32x8,   -16,  -22, 1824,    3
    subsprite OAM_SIZE_16x8,    -8,  -46,  372,    3
  FileD3DA_Obj_500:
    subsprite OAM_SIZE_32x16,  -16,   -8, 1768,    3
    subsprite OAM_SIZE_32x16,  -16,  -24, 1792,    3
    subsprite OAM_SIZE_16x8,    -8,  -32,  372,    3
  FileD3DA_Obj_503:
    subsprite OAM_SIZE_16x32,   -8,  -24, 1350,    3
  FileD3DA_Obj_504:
    subsprite OAM_SIZE_16x16,   -8,   -8, 1636,    3
  FileD3DA_Obj_505:
    subsprite OAM_SIZE_16x16,   -8,   -8,  616,    3
  FileD3DA_Obj_506:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1932,    3
    subsprite OAM_SIZE_8x8,     -8,  -24,  618,    3
    subsprite OAM_SIZE_8x16,    16,   -8,  619,    3
  FileD3DA_Obj_509:
    subsprite OAM_SIZE_32x32,  -16,   -8, 2186,    3
  FileD3DA_Obj_510:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1988,    3
    subsprite OAM_SIZE_8x32,    16,  -24, 1861,    3
  FileD3DA_Obj_512:
    subsprite OAM_SIZE_32x32,  -20,  -24, 2244,    3
    subsprite OAM_SIZE_16x32,   12,  -24, 2190,    3
    subsprite OAM_SIZE_32x8,   -20,    8, 2368,    3
  FileD3DA_Obj_515:
    subsprite OAM_SIZE_32x32,  -23,  -46, 2176,    3
    subsprite OAM_SIZE_16x16,  -15,  -14, 1922,    3
    subsprite OAM_SIZE_16x32,    9,  -46, 1954,    3
    subsprite OAM_SIZE_8x8,      9,  -14,  634,    3
  FileD3DA_Obj_519:
    subsprite OAM_SIZE_32x32,  -24,  -40, 2252,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2309,    3
    subsprite OAM_SIZE_32x32,  -16,  -16, 2305,    3
  FileD3DA_Obj_522:
    subsprite OAM_SIZE_32x32,  -20,  -38, 2180,    3
    subsprite OAM_SIZE_16x32,   12,  -38, 2184,    3
    subsprite OAM_SIZE_32x8,   -12,   -6, 1852,    3
  FileD3DA_Obj_525:
    subsprite OAM_SIZE_32x32,  -21,  -25, 2248,    3
    subsprite OAM_SIZE_8x32,    11,  -25, 2304,    3
    subsprite OAM_SIZE_32x8,   -13,    7, 1956,    3
  FileD3DA_Obj_528:
    subsprite OAM_SIZE_8x8,     -1,   10, 1941,    3
    subsprite OAM_SIZE_32x32,  -17,  -22, 2240,    3
    subsprite OAM_SIZE_8x8,     15,   -6, 1925,    3
  FileD3DA_Obj_531:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1800,    3
    subsprite OAM_SIZE_8x32,   -24,  -24, 1860,    3
    subsprite OAM_SIZE_32x8,   -16,    8, 1804,    3
  FileD3DA_Obj_534:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1996,    3
    subsprite OAM_SIZE_8x8,      0,  -24, 1635,    3
  FileD3DA_Obj_536:
    subsprite OAM_SIZE_16x32,   -8,  -16, 1920,    3
  FileD3DA_Obj_537:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1868,    3
  FileD3DA_Obj_538:
    subsprite OAM_SIZE_32x32,  -16,  -32, 1992,    3
    subsprite OAM_SIZE_32x16,  -16,    0, 1820,    3
    subsprite OAM_SIZE_8x16,    16,  -24, 1924,    3
  FileD3DA_Obj_541:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1928,    3
    subsprite OAM_SIZE_32x32,  -24,  -40, 1864,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 1862,    3
  FileD3DA_Obj_544:
    subsprite OAM_SIZE_32x32,  -16,  -24, 1988,    3
    subsprite OAM_SIZE_8x32,    16,  -24, 1861,    3
    subsprite OAM_SIZE_32x32,  -16,   -8, 2186,    3
    subsprite OAM_SIZE_64x32,  -32,  -48, 2056,    3
  FileD3DA_Obj_548:
    subsprite OAM_SIZE_64x32,  -32,  -48, 2048,    3
    subsprite OAM_SIZE_32x32,  -16,  -16, 1932,    3
    subsprite OAM_SIZE_8x8,     -8,  -24,  618,    3
    subsprite OAM_SIZE_8x16,    16,   -8,  619,    3
  FileD3DA_Obj_552:
    subsprite OAM_SIZE_32x32,  -16,  -16, 1868,    3
    subsprite OAM_SIZE_32x16,  -32,  -48, 1036,    3
    subsprite OAM_SIZE_32x8,     0,  -48, 1084,    3
    subsprite OAM_SIZE_32x8,     0,  -32, 1100,    3
    subsprite OAM_SIZE_8x8,     24,  -24, 3032,    3
  FileD3DA_Obj_557:
    subsprite OAM_SIZE_32x8,   -32,  -48, 1068,    3
    subsprite OAM_SIZE_8x8,     -8,  -40, 3033,    3
    subsprite OAM_SIZE_8x8,      8,  -48, 3017,    3
    subsprite OAM_SIZE_16x8,     8,  -32, 2656,    3
  FileD3DA_Obj_561:
    subsprite OAM_SIZE_32x32,  -16,  -32, 2348,    1
    subsprite OAM_SIZE_16x16,   -8,  -48, 2316,    1
    subsprite OAM_SIZE_32x8,   -16,    0, 2412,    1
    subsprite OAM_SIZE_16x16,  -10,  -22,  748,    1
    subsprite OAM_SIZE_32x32,  -17,  -46,  267,    1
  FileD3DA_Obj_566:
    subsprite OAM_SIZE_32x32,  -16,  -40, 2328,    1
    subsprite OAM_SIZE_16x8,    -8,  -48, 2312,    1
    subsprite OAM_SIZE_32x8,   -16,   -8, 2392,    1
    subsprite OAM_SIZE_16x8,   -16,    0, 2318,    1
    subsprite OAM_SIZE_16x16,    0,  -18,  748,    1
    subsprite OAM_SIZE_32x32,  -18,  -46,  267,    1
  FileD3DA_Obj_572:
    subsprite OAM_SIZE_8x32,   -24,  -32, 2311,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2428,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 2532,    1
    subsprite OAM_SIZE_16x8,   -16,    0, 2546,    1
    subsprite OAM_SIZE_16x16,   -3,  -26,  750,    1
    subsprite OAM_SIZE_32x32,  -20,  -48,  267,    1
  FileD3DA_Obj_578:
    subsprite OAM_SIZE_32x32,  -15,  -47, 2428,    1
    subsprite OAM_SIZE_32x16,  -15,  -15, 2532,    1
    subsprite OAM_SIZE_8x32,   -23,  -31, 2311,    1
    subsprite OAM_SIZE_16x8,   -15,    1, 2546,    1
    subsprite OAM_SIZE_16x16,   -2,  -25,  750,    1
    subsprite OAM_SIZE_32x32,  -19,  -47,  267,    1
  FileD3DA_Obj_584:
    subsprite OAM_SIZE_8x32,   -22,  -30, 2311,    1
    subsprite OAM_SIZE_32x32,  -14,  -46, 2428,    1
    subsprite OAM_SIZE_32x16,  -14,  -14, 2532,    1
    subsprite OAM_SIZE_16x8,   -14,    2, 2546,    1
    subsprite OAM_SIZE_16x16,   -1,  -24,  750,    1
    subsprite OAM_SIZE_32x32,  -18,  -46,  267,    1
  FileD3DA_Obj_590:
    subsprite OAM_SIZE_32x32,  -16,  -40, 2408,    1
    subsprite OAM_SIZE_32x16,  -16,   -8, 2472,    1
    subsprite OAM_SIZE_16x8,    -8,  -48, 2334,    1
    subsprite OAM_SIZE_16x16,    3,  -28,  774,    1
    subsprite OAM_SIZE_32x16,  -11,  -47,  448,    1
  FileD3DA_Obj_595:
    subsprite OAM_SIZE_8x16,    16,  -40, 1926,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2436,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 2500,    1
    subsprite OAM_SIZE_16x8,    -8,    0, 2314,    1
    subsprite OAM_SIZE_16x16,    7,  -44,  806,    1
    subsprite OAM_SIZE_32x16,  -12,  -47,  448,    1
  FileD3DA_Obj_601:
    subsprite OAM_SIZE_32x32,  -24,  -40, 2372,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 2384,    1
    subsprite OAM_SIZE_16x8,   -16,  -48, 2018,    1
    subsprite OAM_SIZE_8x32,     8,  -40, 2565,    1
    subsprite OAM_SIZE_8x16,     8,   -8, 1927,    1
    subsprite OAM_SIZE_16x16,   -2,  -40, 1134,    1
    subsprite OAM_SIZE_32x16,  -14,  -45,  448,    1
  FileD3DA_Obj_608:
    subsprite OAM_SIZE_32x32,  -23,  -41, 2372,    1
    subsprite OAM_SIZE_32x16,  -23,   -9, 2384,    1
    subsprite OAM_SIZE_16x8,   -15,  -49, 2018,    1
    subsprite OAM_SIZE_8x32,     9,  -41, 2565,    1
    subsprite OAM_SIZE_8x16,     9,   -9, 1927,    1
    subsprite OAM_SIZE_16x16,   -1,  -41, 1134,    1
    subsprite OAM_SIZE_32x16,  -13,  -46,  448,    1
  FileD3DA_Obj_615:
    subsprite OAM_SIZE_8x16,    10,  -10, 1927,    1
    subsprite OAM_SIZE_32x32,  -22,  -42, 2372,    1
    subsprite OAM_SIZE_32x16,  -22,  -10, 2384,    1
    subsprite OAM_SIZE_16x8,   -14,  -50, 2018,    1
    subsprite OAM_SIZE_8x32,    10,  -42, 2565,    1
    subsprite OAM_SIZE_16x16,    0,  -42, 1134,    1
    subsprite OAM_SIZE_32x16,  -12,  -47,  448,    1
  FileD3DA_Obj_622:
    subsprite OAM_SIZE_8x32,    16,  -32, 2566,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2560,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 2624,    1
    subsprite OAM_SIZE_8x8,      0,    0, 1748,    1
  FileD3DA_Obj_626:
    subsprite OAM_SIZE_8x32,   -24,  -32,  200,    1
    subsprite OAM_SIZE_16x32,   16,  -24, 1984,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2948,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 3012,    1
    subsprite OAM_SIZE_16x8,     0,    0, 3070,    1
  FileD3DA_Obj_631:
    subsprite OAM_SIZE_32x32,  -16,  -48,  204,    1
    subsprite OAM_SIZE_32x16,  -16,  -16,  352,    1
    subsprite OAM_SIZE_16x8,     0,    0,  218,    1
    subsprite OAM_SIZE_8x32,    16,  -24, 2947,    1
    subsprite OAM_SIZE_8x32,   -24,  -32,  201,    1
  FileD3DA_Obj_636:
    subsprite OAM_SIZE_8x32,    16,  -40, 2564,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2432,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 2496,    1
    subsprite OAM_SIZE_16x8,   -16,    0, 2528,    1
  FileD3DA_Obj_640:
    subsprite OAM_SIZE_8x16,    16,  -32, 3049,    1
    subsprite OAM_SIZE_16x32,  -32,  -32, 3008,    1
    subsprite OAM_SIZE_16x8,   -32,    0,  202,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2956,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 3020,    1
    subsprite OAM_SIZE_32x8,   -16,    0, 3052,    1
    subsprite OAM_SIZE_16x8,   -16,    8, 3068,    1
  FileD3DA_Obj_647:
    subsprite OAM_SIZE_8x16,    16,  -32,  358,    1
    subsprite OAM_SIZE_16x32,  -32,  -24, 3010,    1
    subsprite OAM_SIZE_8x8,    -24,  -32,  251,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2952,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 3044,    1
    subsprite OAM_SIZE_16x8,   -16,    0, 2544,    1
  FileD3DA_Obj_653:
    subsprite OAM_SIZE_32x64,   -8,  -48, 2692,    1
    subsprite OAM_SIZE_8x16,   -16,  -16, 2661,    1
    subsprite OAM_SIZE_32x16,  -17,  -47, 2924,    1
  FileD3DA_Obj_656:
    subsprite OAM_SIZE_8x16,   -17,  -15, 2661,    1
    subsprite OAM_SIZE_32x64,   -9,  -47, 2692,    1
    subsprite OAM_SIZE_32x16,  -18,  -46, 2924,    1
  FileD3DA_Obj_659:
    subsprite OAM_SIZE_32x8,   -16,    0, 1020,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 1192,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 2764,    1
    subsprite OAM_SIZE_8x8,      8,  -56,  240,    1
    subsprite OAM_SIZE_32x16,  -24,  -47, 1251,    1
  FileD3DA_Obj_664:
    subsprite OAM_SIZE_32x8,   -17,    1, 1020,    1
    subsprite OAM_SIZE_32x16,  -17,  -15, 1192,    1
    subsprite OAM_SIZE_32x32,  -17,  -47, 2764,    1
    subsprite OAM_SIZE_8x8,      7,  -55,  240,    1
    subsprite OAM_SIZE_32x16,  -25,  -46, 1251,    1
  FileD3DA_Obj_669:
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    1
    subsprite OAM_SIZE_8x8,      8,  -56,  241,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
    subsprite OAM_SIZE_16x8,     8,  -48, 1972,    1
    subsprite OAM_SIZE_16x16,    0,  -48, 1190,    1
    subsprite OAM_SIZE_8x8,     -8,  -48, 1184,    1
  FileD3DA_Obj_677:
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    1
    subsprite OAM_SIZE_8x8,      8,  -56,  242,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
    subsprite OAM_SIZE_32x16,   -8,  -48, 1196,    1
    subsprite OAM_SIZE_16x32,    8,  -48,  958,    1
    subsprite OAM_SIZE_8x8,     24,  -32, 2419,    1
  FileD3DA_Obj_685:
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    1
    subsprite OAM_SIZE_16x16,    8,  -48, 1734,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
    subsprite OAM_SIZE_16x32,   16,  -40,  956,    1
  FileD3DA_Obj_691:
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    1
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
    subsprite OAM_SIZE_16x32,    8,  -32, 3018,    1
  FileD3DA_Obj_696:
    subsprite OAM_SIZE_32x32,  -24,  -40, 2504,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2492,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 1888,    1
    subsprite OAM_SIZE_8x8,    -16,   -8, 1733,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
    subsprite OAM_SIZE_16x16,    8,  -16,  427,    1
  FileD3DA_Obj_702:
    subsprite OAM_SIZE_32x32,  -24,  -40, 2504,    1
    subsprite OAM_SIZE_16x32,    8,  -40, 2492,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 1888,    1
    subsprite OAM_SIZE_8x8,    -16,   -8, 1733,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
  FileD3DA_Obj_707:
    subsprite OAM_SIZE_32x32,   -8,  -40,  580,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 1764,    1
    subsprite OAM_SIZE_8x16,   -16,  -32, 2662,    1
    subsprite OAM_SIZE_32x16,   -8,  -41, 2920,    1
  FileD3DA_Obj_711:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2572,    1
    subsprite OAM_SIZE_32x16,   -8,   -8, 2636,    1
    subsprite OAM_SIZE_16x8,    -8,  -48, 2770,    1
    subsprite OAM_SIZE_32x32,   -6,  -45, 1216,    1
  FileD3DA_Obj_715:
    subsprite OAM_SIZE_16x8,    -9,  -49, 2770,    1
    subsprite OAM_SIZE_32x32,   -9,  -41, 2572,    1
    subsprite OAM_SIZE_32x16,   -9,   -9, 2636,    1
    subsprite OAM_SIZE_32x32,   -7,  -46, 1216,    1
  FileD3DA_Obj_719:
    subsprite OAM_SIZE_32x32,  -16,  -48, 2668,    1
    subsprite OAM_SIZE_32x8,   -16,    0, 2800,    1
    subsprite OAM_SIZE_32x16,  -16,  -16, 2732,    1
    subsprite OAM_SIZE_32x16,  -22,  -48, 1219,    1
  FileD3DA_Obj_723:
    subsprite OAM_SIZE_32x8,   -17,   -1, 2800,    1
    subsprite OAM_SIZE_32x16,  -17,  -17, 2732,    1
    subsprite OAM_SIZE_32x32,  -17,  -49, 2668,    1
    subsprite OAM_SIZE_32x16,  -23,  -49, 1219,    1
  FileD3DA_Obj_727:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    1
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    1
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
    subsprite OAM_SIZE_16x16,    0,  -48, 1185,    1
    subsprite OAM_SIZE_8x8,     -8,  -40, 1200,    1
  FileD3DA_Obj_734:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    1
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    1
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
    subsprite OAM_SIZE_16x32,    0,  -48, 2494,    1
    subsprite OAM_SIZE_8x8,     16,  -40, 1749,    1
  FileD3DA_Obj_741:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    1
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    1
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
    subsprite OAM_SIZE_32x32,   -8,  -40, 1228,    1
  FileD3DA_Obj_747:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    1
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    1
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    1
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
    subsprite OAM_SIZE_16x32,   -8,  -32,  397,    1
    subsprite OAM_SIZE_8x16,    16,  -40, 2663,    1
  FileD3DA_Obj_754:
    subsprite OAM_SIZE_32x32,  -16,  -40, 2632,    1
    subsprite OAM_SIZE_32x16,  -16,   -8, 2696,    1
    subsprite OAM_SIZE_8x32,    16,  -40, 2567,    1
    subsprite OAM_SIZE_8x8,     16,   -8, 2035,    1
    subsprite OAM_SIZE_8x8,     -8,    8, 2034,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
    subsprite OAM_SIZE_8x8,     16,  -32, 1732,    1
    subsprite OAM_SIZE_16x16,   -8,  -16, 1188,    1
    subsprite OAM_SIZE_8x16,   -16,  -16, 1187,    1
  FileD3DA_Obj_763:
    subsprite OAM_SIZE_8x8,     -8,    8, 2034,    1
    subsprite OAM_SIZE_32x32,  -16,  -40, 2632,    1
    subsprite OAM_SIZE_32x16,  -16,   -8, 2696,    1
    subsprite OAM_SIZE_8x32,    16,  -40, 2567,    1
    subsprite OAM_SIZE_8x8,     16,   -8, 2035,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
  FileD3DA_Obj_769:
    subsprite OAM_SIZE_32x32,   -8,  -32, 2704,    1
    subsprite OAM_SIZE_32x8,    -8,  -40, 2688,    1
    subsprite OAM_SIZE_16x16,   -8,    0, 2768,    1
    subsprite OAM_SIZE_8x8,      8,    0, 2786,    1
    subsprite OAM_SIZE_8x32,   -16,  -32,  271,    1
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    1
  FileD3DA_Obj_775:
    subsprite OAM_SIZE_32x64,   -8,  -48, 2692,    3
    subsprite OAM_SIZE_8x16,   -16,  -16, 2661,    3
  FileD3DA_Obj_777:
    subsprite OAM_SIZE_32x64,   -9,  -47, 2692,    3
    subsprite OAM_SIZE_8x16,   -17,  -15, 2661,    3
  FileD3DA_Obj_779:
    subsprite OAM_SIZE_8x8,      8,  -56,  240,    3
    subsprite OAM_SIZE_32x32,  -16,  -48, 2764,    3
    subsprite OAM_SIZE_32x16,  -16,  -16, 1192,    3
    subsprite OAM_SIZE_32x8,   -16,    0, 1020,    3
  FileD3DA_Obj_783:
    subsprite OAM_SIZE_8x8,      7,  -55,  240,    3
    subsprite OAM_SIZE_32x8,   -17,    1, 1020,    3
    subsprite OAM_SIZE_32x16,  -17,  -15, 1192,    3
    subsprite OAM_SIZE_32x32,  -17,  -47, 2764,    3
  FileD3DA_Obj_787:
    subsprite OAM_SIZE_8x8,      8,  -56,  241,    3
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    3
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    3
    subsprite OAM_SIZE_8x8,     -8,  -48, 1184,    3
    subsprite OAM_SIZE_16x16,    0,  -48, 1190,    3
    subsprite OAM_SIZE_16x8,     8,  -48, 1972,    3
  FileD3DA_Obj_794:
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    3
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    3
    subsprite OAM_SIZE_16x32,    8,  -48,  958,    3
    subsprite OAM_SIZE_32x16,   -8,  -48, 1196,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    3
    subsprite OAM_SIZE_8x8,     24,  -32, 2419,    3
    subsprite OAM_SIZE_8x8,      8,  -56,  242,    3
  FileD3DA_Obj_801:
    subsprite OAM_SIZE_16x32,   16,  -40,  956,    3
    subsprite OAM_SIZE_16x16,    8,  -48, 1734,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    3
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    3
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    3
  FileD3DA_Obj_806:
    subsprite OAM_SIZE_32x16,   -8,   -8, 2792,    3
    subsprite OAM_SIZE_32x32,  -24,  -40,  455,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2730,    3
    subsprite OAM_SIZE_16x32,    8,  -32, 3018,    3
  FileD3DA_Obj_810:
    subsprite OAM_SIZE_32x16,   -8,   -8, 1888,    3
    subsprite OAM_SIZE_8x8,    -16,   -8, 1733,    3
    subsprite OAM_SIZE_32x32,  -24,  -40, 2504,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2492,    3
    subsprite OAM_SIZE_16x16,    8,  -16,  427,    3
  FileD3DA_Obj_815:
    subsprite OAM_SIZE_32x16,   -8,   -8, 1888,    3
    subsprite OAM_SIZE_32x32,  -24,  -40, 2504,    3
    subsprite OAM_SIZE_16x32,    8,  -40, 2492,    3
    subsprite OAM_SIZE_8x8,    -16,   -8, 1733,    3
  FileD3DA_Obj_819:
    subsprite OAM_SIZE_32x16,   -8,   -8, 1764,    3
    subsprite OAM_SIZE_32x32,   -8,  -40,  580,    3
    subsprite OAM_SIZE_8x16,   -16,  -32, 2662,    3
  FileD3DA_Obj_822:
    subsprite OAM_SIZE_16x8,    -8,  -48, 2770,    3
    subsprite OAM_SIZE_32x32,   -8,  -40, 2572,    3
    subsprite OAM_SIZE_32x16,   -8,   -8, 2636,    3
  FileD3DA_Obj_825:
    subsprite OAM_SIZE_32x16,   -9,   -9, 2636,    3
    subsprite OAM_SIZE_16x8,    -9,  -49, 2770,    3
    subsprite OAM_SIZE_32x32,   -9,  -41, 2572,    3
  FileD3DA_Obj_828:
    subsprite OAM_SIZE_32x32,  -16,  -48, 2668,    3
    subsprite OAM_SIZE_32x16,  -16,  -16, 2732,    3
    subsprite OAM_SIZE_32x8,   -16,    0, 2800,    3
  FileD3DA_Obj_831:
    subsprite OAM_SIZE_32x32,  -17,  -49, 2668,    3
    subsprite OAM_SIZE_32x16,  -17,  -17, 2732,    3
    subsprite OAM_SIZE_32x8,   -17,   -1, 2800,    3
  FileD3DA_Obj_834:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    3
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    3
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    3
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    3
    subsprite OAM_SIZE_16x16,    0,  -48, 1185,    3
    subsprite OAM_SIZE_8x8,     -8,  -40, 1200,    3
  FileD3DA_Obj_840:
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    3
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    3
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    3
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    3
    subsprite OAM_SIZE_16x32,    0,  -48, 2494,    3
    subsprite OAM_SIZE_8x8,     16,  -40, 1749,    3
  FileD3DA_Obj_846:
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    3
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    3
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    3
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    3
    subsprite OAM_SIZE_32x32,   -8,  -40, 1228,    3
  FileD3DA_Obj_851:
    subsprite OAM_SIZE_8x16,     8,   -8, 2660,    3
    subsprite OAM_SIZE_32x16,  -24,   -8, 2628,    3
    subsprite OAM_SIZE_32x32,   -8,  -40, 2568,    3
    subsprite OAM_SIZE_16x32,  -24,  -32, 2728,    3
    subsprite OAM_SIZE_8x16,    16,  -40, 2663,    3
    subsprite OAM_SIZE_16x32,   -8,  -32,  397,    3
  FileD3DA_Obj_857:
    subsprite OAM_SIZE_32x32,    0,  -37, 1223,    3
    subsprite OAM_SIZE_32x32,  -16,  -40, 2632,    3
    subsprite OAM_SIZE_8x32,    16,  -40, 2567,    3
    subsprite OAM_SIZE_32x16,  -16,   -8, 2696,    3
    subsprite OAM_SIZE_8x8,     16,   -8, 2035,    3
    subsprite OAM_SIZE_8x8,     -8,    8, 2034,    3
    subsprite OAM_SIZE_8x8,     16,  -32, 1732,    3
    subsprite OAM_SIZE_8x16,   -16,  -16, 1187,    3
    subsprite OAM_SIZE_16x16,   -8,  -16, 1188,    3
  FileD3DA_Obj_866:
    subsprite OAM_SIZE_8x8,     -8,    8, 2034,    3
    subsprite OAM_SIZE_32x16,  -16,   -8, 2696,    3
    subsprite OAM_SIZE_8x8,     16,   -8, 2035,    3
    subsprite OAM_SIZE_32x32,  -16,  -40, 2632,    3
    subsprite OAM_SIZE_8x32,    16,  -40, 2567,    3
  FileD3DA_Obj_871:
    subsprite OAM_SIZE_8x32,   -16,  -32,  271,    3
    subsprite OAM_SIZE_32x32,   -8,  -32, 2704,    3
    subsprite OAM_SIZE_32x8,    -8,  -40, 2688,    3
    subsprite OAM_SIZE_16x16,   -8,    0, 2768,    3
    subsprite OAM_SIZE_8x8,      8,    0, 2786,    3
  FileD3DA_Obj_876:
    subsprite OAM_SIZE_32x32,  -16,  -32, 2848,    1
    subsprite OAM_SIZE_16x16,   -8,  -48, 2816,    1
    subsprite OAM_SIZE_16x16,  -16,    0, 2818,    1
    subsprite OAM_SIZE_8x8,      0,    0, 2659,    1
    subsprite OAM_SIZE_8x32,    16,  -32, 2944,    1
  FileD3DA_Obj_881:
    subsprite OAM_SIZE_32x32,  -20,  -36, 2820,    1
    subsprite OAM_SIZE_32x16,  -20,   -4, 2884,    1
    subsprite OAM_SIZE_8x32,    12,  -20, 1227,    1
    subsprite OAM_SIZE_8x8,      4,  -36, 2416,    1
  FileD3DA_Obj_885:
    subsprite OAM_SIZE_32x32,  -20,  -36, 2824,    1
    subsprite OAM_SIZE_32x16,  -20,   -4, 2888,    1
    subsprite OAM_SIZE_8x16,    12,  -12,  195,    1
    subsprite OAM_SIZE_8x8,      4,  -36, 2417,    1
  FileD3DA_Obj_889:
    subsprite OAM_SIZE_32x32,  -20,  -36, 2828,    1
    subsprite OAM_SIZE_32x16,  -20,   -4, 2892,    1
    subsprite OAM_SIZE_8x16,    12,  -12, 3048,    1
    subsprite OAM_SIZE_8x8,      4,  -36, 2418,    1
  FileD3DA_Obj_893:
    subsprite OAM_SIZE_16x16,  -16,    0, 2818,    3
    subsprite OAM_SIZE_8x8,      0,    0, 2659,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 2848,    3
    subsprite OAM_SIZE_8x32,    16,  -32, 2944,    3
    subsprite OAM_SIZE_16x16,   -8,  -48, 2816,    3
  FileD3DA_Obj_898:
    subsprite OAM_SIZE_8x8,      4,  -36, 2416,    3
    subsprite OAM_SIZE_32x16,  -20,   -4, 2884,    3
    subsprite OAM_SIZE_8x32,    12,  -20, 1227,    3
    subsprite OAM_SIZE_32x32,  -20,  -36, 2820,    3
  FileD3DA_Obj_902:
    subsprite OAM_SIZE_8x8,      4,  -36, 2417,    3
    subsprite OAM_SIZE_32x16,  -20,   -4, 2888,    3
    subsprite OAM_SIZE_8x16,    12,  -12,  195,    3
    subsprite OAM_SIZE_32x32,  -20,  -36, 2824,    3
  FileD3DA_Obj_906:
    subsprite OAM_SIZE_8x8,      4,  -36, 2418,    3
    subsprite OAM_SIZE_32x16,  -20,   -4, 2892,    3
    subsprite OAM_SIZE_8x16,    12,  -12, 3048,    3
    subsprite OAM_SIZE_32x32,  -20,  -36, 2828,    3
  FileD3DA_Obj_910:
    subsprite OAM_SIZE_32x64,  -16,  -48, 3076,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 3084,    1
  FileD3DA_Obj_912:
    subsprite OAM_SIZE_32x64,  -16,  -48, 3072,    1
    subsprite OAM_SIZE_32x32,  -16,  -48, 3080,    1
  FileD3DA_Obj_914:
    subsprite OAM_SIZE_32x64,  -16,  -48, 3076,    3
  FileD3DA_Obj_915:
    subsprite OAM_SIZE_32x64,  -16,  -48, 3072,    3
  FileD3DA_Obj_916:
    subsprite OAM_SIZE_16x16,   -8,   -7, 3150,    1
    subsprite OAM_SIZE_8x8,      8,   -3, 3200,    1
    subsprite OAM_SIZE_8x8,     -9,   -3, 3200,    1
  FileD3DA_Obj_919:
    subsprite OAM_SIZE_16x16,   -8,   -8, 3180,    1
    subsprite OAM_SIZE_8x8,      8,   -2, 3201,    1
  FileD3DA_Obj_921:
    subsprite OAM_SIZE_16x16,   -8,   -8, 3182,    1
    subsprite OAM_SIZE_8x8,      8,   -2, 3216,    1
  FileD3DA_Obj_923:
    subsprite OAM_SIZE_16x16,   -7,   -8, 3202,    1
    subsprite OAM_SIZE_8x8,    -15,   -4, 3217,    1
    subsprite OAM_SIZE_8x8,      9,   -2, 3232,    1
  FileD3DA_Obj_926:
    subsprite OAM_SIZE_16x16,   -8,   -9, 3204,    1
    subsprite OAM_SIZE_8x8,      8,   -4, 3232,    1
    subsprite OAM_SIZE_8x8,     -9,   -4, 3232,    1
  FileD3DA_Obj_929:
    subsprite OAM_SIZE_16x16,   -9,   -8, 3202,    1, xflip=1
    subsprite OAM_SIZE_8x8,      0,   -4, 3217,    1
    subsprite OAM_SIZE_8x8,    -10,   -2, 3232,    1
  FileD3DA_Obj_932:
    subsprite OAM_SIZE_16x16,   -8,   -8, 3182,    1, xflip=1
    subsprite OAM_SIZE_8x8,    -16,   -2, 3216,    1, xflip=1
  FileD3DA_Obj_934:
    subsprite OAM_SIZE_16x16,   -8,   -8, 3180,    1, xflip=1
    subsprite OAM_SIZE_8x8,    -16,   -2, 3201,    1, xflip=1
  FileD3DA_Obj_936:
    subsprite OAM_SIZE_16x16,   -8,   -8, 3206,    0
  FileD3DA_Obj_937:
    subsprite OAM_SIZE_32x32,  -16,  -16, 3144,    1
  FileD3DA_Obj_938:
    subsprite OAM_SIZE_16x16,   -8,   -9, 3148,    1
    subsprite OAM_SIZE_8x8,    -16,   -5, 3217,    1
    subsprite OAM_SIZE_8x8,      1,   -5, 3217,    1
  FileD3DA_Obj_941:
    subsprite OAM_SIZE_32x32,  -16,  -15, 3212,    1, yflip=1
  FileD3DA_Obj_942:
    subsprite OAM_SIZE_16x16,   -8,   -4, 3204,    1, yflip=1
    subsprite OAM_SIZE_8x8,     -9,    0, 3232,    1
    subsprite OAM_SIZE_8x8,      8,    0, 3232,    1
  FileD3DA_Obj_945:
    subsprite OAM_SIZE_32x32,  -20,  -36, 3276,    1
    subsprite OAM_SIZE_32x16,  -20,   -4, 2888,    1
    subsprite OAM_SIZE_16x16,   -8,  -36, 2148,    1
    subsprite OAM_SIZE_8x16,    12,  -12,  195,    1
    subsprite OAM_SIZE_8x8,      0,  -20, 2133,    1
  FileD3DA_Obj_950:
    subsprite OAM_SIZE_32x32,  -20,  -36, 3276,    3
    subsprite OAM_SIZE_32x16,  -20,   -4, 2888,    3
    subsprite OAM_SIZE_8x16,    12,  -12,  195,    3
    subsprite OAM_SIZE_16x16,   -8,  -36, 2148,    3
    subsprite OAM_SIZE_8x8,      0,  -20, 2133,    3
  FileD3DA_Obj_955:
    subsprite OAM_SIZE_16x16,   12,  -29, 3248,   10
    subsprite OAM_SIZE_32x16,  -16,  -48, 3072,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 3208,    3
    subsprite OAM_SIZE_32x16,  -16,    0, 3168,    3
    subsprite OAM_SIZE_16x8,    12,  -13, 3280,   10
  FileD3DA_Obj_960:
    subsprite OAM_SIZE_16x16,   12,  -28, 3248,   10
    subsprite OAM_SIZE_32x16,  -16,  -48, 3072,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 3208,    3
    subsprite OAM_SIZE_32x16,  -16,    0, 3168,    3
    subsprite OAM_SIZE_8x8,     23,   -8, 3233,    3
    subsprite OAM_SIZE_16x8,    12,  -12, 3296,    3
  FileD3DA_Obj_966:
    subsprite OAM_SIZE_16x16,    2,  -29, 3248,   10
    subsprite OAM_SIZE_16x8,     2,  -13, 3280,   10
    subsprite OAM_SIZE_32x16,  -16,    0, 3168,    3
    subsprite OAM_SIZE_32x16,  -16,  -48, 3072,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 3272,    3
  FileD3DA_Obj_971:
    subsprite OAM_SIZE_32x16,  -16,    0, 3168,    3
    subsprite OAM_SIZE_32x16,  -16,  -48, 3072,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 3268,    3
    subsprite OAM_SIZE_16x16,   16,  -39, 3238,    3
  FileD3DA_Obj_975:
    subsprite OAM_SIZE_32x16,  -16,    0, 3168,    3
    subsprite OAM_SIZE_32x16,  -16,  -48, 3072,    3
    subsprite OAM_SIZE_32x32,  -16,  -32, 3268,    3
    subsprite OAM_SIZE_16x16,   16,  -40, 3238,    3
  FileD3DA_Obj_979:
    subsprite OAM_SIZE_8x16,    16,  -24,  463,    3
    subsprite OAM_SIZE_32x32,  -16,  -48,  780,    3
    subsprite OAM_SIZE_32x16,  -16,  -16,  844,    3
    subsprite OAM_SIZE_32x8,   -16,    0,  876,    3
  FileD3DA_Obj_983:
    subsprite OAM_SIZE_8x16,    16,  -24,  495,    3
    subsprite OAM_SIZE_8x8,     -8,    0, 2658,    3
    subsprite OAM_SIZE_32x16,  -16,  -16,  856,    3
    subsprite OAM_SIZE_32x32,  -16,  -48,  792,    3
  FileD3DA_Obj_987:
    subsprite OAM_SIZE_8x16,    16,  -32,  871,    3
    subsprite OAM_SIZE_8x16,   -24,  -16,  839,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,  892,    3
    subsprite OAM_SIZE_32x16,  -16,   -8, 1000,    3
    subsprite OAM_SIZE_16x8,     0,  -48,  890,    3
  FileD3DA_Obj_992:
    subsprite OAM_SIZE_32x32,  -16,  -40,  932,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,  996,    3
    subsprite OAM_SIZE_8x16,    16,  -24,  902,    3
  FileD3DA_Obj_995:
    subsprite OAM_SIZE_32x32,  -16,  -40,  960,    3
    subsprite OAM_SIZE_32x16,  -16,   -8, 1164,    3
    subsprite OAM_SIZE_8x16,    16,  -24, 2154,    3
  FileD3DA_Obj_998:
    subsprite OAM_SIZE_8x16,    16,  -32,  903,    3
    subsprite OAM_SIZE_32x32,  -16,  -40,  904,    3
    subsprite OAM_SIZE_16x8,     0,  -48,  888,    3
    subsprite OAM_SIZE_32x16,  -16,   -8,  968,    3

2:
FileD3DA_Cmds:
  FileD3DA_Cmd_0:
    animcmd    0,   1
  FileD3DA_Cmd_1:
    animcmd    1,   1
  FileD3DA_Cmd_2:
    animcmd    2,   1
  FileD3DA_Cmd_3:
    animcmd    3,   1
  FileD3DA_Cmd_4:
    animcmd    4,   1
  FileD3DA_Cmd_5:
    animcmd    5,   1
  FileD3DA_Cmd_6:
    animcmd    6,   1
  FileD3DA_Cmd_7:
    animcmd    7,   1
  FileD3DA_Cmd_8:
    animcmd    8,   1
  FileD3DA_Cmd_9:
    animcmd    9,   1
  FileD3DA_Cmd_10:
    animcmd   10,   8
    animcmd   11,   8
  FileD3DA_Cmd_12:
    animcmd   10,   8
  FileD3DA_Cmd_13:
    animcmd   12,   8
    animcmd   13,   8
  FileD3DA_Cmd_15:
    animcmd   12,   8
  FileD3DA_Cmd_16:
    animcmd   14,   8
    animcmd   15,   8
  FileD3DA_Cmd_18:
    animcmd   14,   1
  FileD3DA_Cmd_19:
    animcmd   16,   8
    animcmd   17,   8
  FileD3DA_Cmd_21:
    animcmd   16,   1
  FileD3DA_Cmd_22:
    animcmd   20,   5
    animcmd   21,   5
  FileD3DA_Cmd_24:
    animcmd   19,   1
  FileD3DA_Cmd_25:
    animcmd   18,   1
  FileD3DA_Cmd_26:
    animcmd   22,   5
    animcmd   23,   5
  FileD3DA_Cmd_28:
    animcmd   26,   5
    animcmd   27,   5
  FileD3DA_Cmd_30:
    animcmd   25,   1
  FileD3DA_Cmd_31:
    animcmd   24,   1
  FileD3DA_Cmd_32:
    animcmd   28,   5
    animcmd   29,   5
  FileD3DA_Cmd_34:
    animcmd   30,   1
  FileD3DA_Cmd_35:
    animcmd   31,   1
  FileD3DA_Cmd_36:
    animcmd   32,   1
  FileD3DA_Cmd_37:
    animcmd   33,   1
  FileD3DA_Cmd_38:
    animcmd   34,   1
  FileD3DA_Cmd_39:
    animcmd   35,   1
  FileD3DA_Cmd_40:
    animcmd   36,   1
  FileD3DA_Cmd_41:
    animcmd   37,   1
  FileD3DA_Cmd_42:
    animcmd   38,   1
  FileD3DA_Cmd_43:
    animcmd   39,   1
  FileD3DA_Cmd_44:
    animcmd   40,   1
  FileD3DA_Cmd_45:
    animcmd   41,   4
    animcmd   42,   2
    animcmd   43,   2
    animcmd   44,   2
    animcmd   45,   2
    animcmd   46,   2
    animcmd   47,  16
    animcmd   48,   8
  FileD3DA_Cmd_53:
    animcmd   49,   1
  FileD3DA_Cmd_54:
    animcmd   50,   2
    animcmd   51,   2
    animcmd   52,   2
    animcmd   53,   2
    animcmd   54,   2
    animcmd   55,   2
    animcmd   56,  16
    animcmd   57,   8
  FileD3DA_Cmd_62:
    animcmd   58,   1
  FileD3DA_Cmd_63:
    animcmd   59,   4
    animcmd   60,   2
    animcmd   61,   2
    animcmd   62,   2
    animcmd   63,   2
    animcmd   64,   2
    animcmd   65,  16
    animcmd   66,   8
  FileD3DA_Cmd_71:
    animcmd   67,   1
  FileD3DA_Cmd_72:
    animcmd   68,   4
    animcmd   69,   2
    animcmd   70,   2
    animcmd   71,   2
    animcmd   72,   2
    animcmd   73,   2
    animcmd   74,  16
    animcmd   75,   8
  FileD3DA_Cmd_80:
    animcmd   76,  20
    animcmd   77,   8
    animcmd   78,   5
    animcmd   79,   7
    animcmd   80,   7
    animcmd   79,   7
    animcmd   80,   7
    animcmd   79,   7
    animcmd   80,   7
    animcmd   81,   8
  FileD3DA_Cmd_90:
    animcmd   82,   7
    animcmd   83,  16
    animcmd   84,   8
    animcmd   85,   8
    animcmd   86,   7
    animcmd   87,   6
    animcmd   88,   6
  FileD3DA_Cmd_97:
    animcmd   89,   1
  FileD3DA_Cmd_98:
    animcmd   90,   1
  FileD3DA_Cmd_99:
    animcmd   91,   1
  FileD3DA_Cmd_100:
    animcmd   92,   1
  FileD3DA_Cmd_101:
    animcmd   93,   1
  FileD3DA_Cmd_102:
    animcmd   94,   1
  FileD3DA_Cmd_103:
    animcmd   95,   1
  FileD3DA_Cmd_104:
    animcmd   96,   1
  FileD3DA_Cmd_105:
    animcmd   97,   1
  FileD3DA_Cmd_106:
    animcmd   98,   1
  FileD3DA_Cmd_107:
    animcmd   99,   5
    animcmd  100,   5
  FileD3DA_Cmd_109:
    animcmd  101,   2
    animcmd  102,   2
    animcmd  103,   5
    animcmd  104,   5
    animcmd  105,   5
    animcmd  106,   5
    animcmd  107,   5
  FileD3DA_Cmd_116:
    animcmd  113,   8
    animcmd  114,  18
  FileD3DA_Cmd_118:
    animcmd  114,   6
    animcmd  115,   4
    animcmd  116,   4
    animcmd  117,   4
  FileD3DA_Cmd_122:
    animcmd  114,   4
    animcmd  113,   8
  FileD3DA_Cmd_124:
    animcmd  108,   8
    animcmd  109,  18
  FileD3DA_Cmd_126:
    animcmd  109,   6
    animcmd  110,   4
    animcmd  111,   4
    animcmd  112,   4
  FileD3DA_Cmd_130:
    animcmd  109,   4
    animcmd  108,   8
  FileD3DA_Cmd_132:
    animcmd   48,   6
    animcmd   31,   6
    animcmd  118,   8
  FileD3DA_Cmd_135:
    animcmd  119,   6
    animcmd  120,   6
  FileD3DA_Cmd_137:
    animcmd   57,   6
    animcmd   33,   6
    animcmd  121,   8
  FileD3DA_Cmd_140:
    animcmd  122,   6
    animcmd  123,   6
  FileD3DA_Cmd_142:
    animcmd  124,   8
    animcmd  125,   8
    animcmd  124,   8
    animcmd  126,   6
    animcmd  127,   6
    animcmd  126,   6
    animcmd  128,   2
    animcmd  129,   2
    animcmd  130,   1
    animcmd  131,   1
    animcmd  132,   1
    animcmd  133,   3
    animcmd  134,  31
  FileD3DA_Cmd_155:
    animcmd  135,   8
    animcmd  136,   8
    animcmd  135,   8
    animcmd  137,   6
    animcmd  138,   6
    animcmd  137,   6
    animcmd  139,   2
    animcmd  140,   2
    animcmd  141,   1
    animcmd  142,   1
    animcmd  143,   1
    animcmd  144,   3
    animcmd  145,  31
  FileD3DA_Cmd_168:
    animcmd  146,   8
    animcmd  147,   8
    animcmd  146,   8
    animcmd  148,   6
    animcmd  149,   6
    animcmd  148,   6
    animcmd  150,   2
    animcmd  151,   2
    animcmd  152,   1
    animcmd  153,   1
    animcmd  154,   1
    animcmd  155,   3
    animcmd  156,  31
  FileD3DA_Cmd_181:
    animcmd  157,   8
    animcmd  158,   8
    animcmd  157,   8
    animcmd  159,   6
    animcmd  160,   6
    animcmd  159,   6
    animcmd  161,   2
    animcmd  162,   2
    animcmd  163,   1
    animcmd  164,   1
    animcmd  165,   1
    animcmd  166,   3
    animcmd  167,  31
  FileD3DA_Cmd_194:
    animcmd  168,  64
    animcmd  169,   6
    animcmd  170,  24
    animcmd  171,  18
    animcmd  170,  24
    animcmd  171,  18
    animcmd  170,  24
    animcmd  171,  18
    animcmd  170,  24
    animcmd  171,  18
    animcmd  170,  24
    animcmd  171,  18
  FileD3DA_Cmd_206:
    animcmd  172,  12
    animcmd  173,   6
    animcmd  174,  24
    animcmd  175,  18
    animcmd  174,  24
    animcmd  175,  18
    animcmd  174,  24
    animcmd  175,  18
    animcmd  174,  24
    animcmd  175,  18
    animcmd  174,  24
    animcmd  175,  18
  FileD3DA_Cmd_218:
    animcmd  176,   1
  FileD3DA_Cmd_219:
    animcmd  177,   1
  FileD3DA_Cmd_220:
    animcmd  178,   1
  FileD3DA_Cmd_221:
    animcmd  179,   1
  FileD3DA_Cmd_222:
    animcmd  190,   6
    animcmd  191,   6
    animcmd  192,   6
    animcmd  189,   6
    animcmd  180,   3
    animcmd  190,   6
    animcmd  191,   6
    animcmd  192,   6
    animcmd  189,   6
  FileD3DA_Cmd_231:
    animcmd  180,   4
    animcmd  181,   4
    animcmd  182,   4
    animcmd  183,   4
    animcmd  184,   4
    animcmd  185,   4
    animcmd  186,   4
    animcmd  187,   4
  FileD3DA_Cmd_239:
    animcmd  188,   1
  FileD3DA_Cmd_240:
    animcmd  170,  16
    animcmd  171,  16
  FileD3DA_Cmd_242:
    animcmd  174,  16
    animcmd  175,  16
  FileD3DA_Cmd_244:
    animcmd  193,   1
  FileD3DA_Cmd_245:
    animcmd  194,   1
  FileD3DA_Cmd_246:
    animcmd  195,   6
    animcmd  196,   8
    animcmd  195,   4
    animcmd  196,   6
    animcmd  195,  32
  FileD3DA_Cmd_251:
    animcmd  195,   8
    animcmd  197,  16
    animcmd  198,   3
    animcmd  199,  13
  FileD3DA_Cmd_255:
    animcmd  200,  20
    animcmd  201,   8
    animcmd  202,   5
    animcmd  203,   8
  FileD3DA_Cmd_259:
    animcmd  204,   4
    animcmd  205,   8

FileD3DA_Tiles:
  .incbin "data/sprite_main/ringo.4bpp"
