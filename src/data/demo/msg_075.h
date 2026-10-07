// clang-format off
/* ================ demo 75  (101 steps) ================ */
/* -- step 0 -- */
static const DemoMsg0  sMsg_d75_s0_0      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg4  sMsg_d75_s0_1      = { 0x51E2, CLS_ACTOR,  WAIT,   0, 3,               3, { 2384, 768, 1792, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d75_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2304, 768, 2688, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d75_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d75_s2_1      = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d75_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d75_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d75_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d75_s5_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 4,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d75_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d75_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 61, 0 } };
static const DemoMsg2  sMsg_d75_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 5, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d75_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d75_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d75_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d75_s9_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d75_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d75_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d75_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d75_s12_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 30,              1, { 1, 0 } };
static const DemoMsg0  sMsg_d75_s12_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 21,              0 };
static const DemoMsg2  sMsg_d75_s12_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 219, 0 } };
static const DemoMsg2  sMsg_d75_s12_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 818, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d75_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d75_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d75_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d75_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d75_s16_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 31,              0 };
static const DemoMsg2  sMsg_d75_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 855, 0 } };
static const DemoMsg2  sMsg_d75_s16_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 819, 0 } };
static const DemoMsg2  sMsg_d75_s16_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d75_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d75_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 0, 0, 64, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d75_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 64, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d75_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d75_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg4  sMsg_d75_s21_0     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 1,               3, { 2304, 768, 2560, 0 } };
static const DemoMsg4  sMsg_d75_s21_1     = { 0x51E2, CLS_ACTOR,  WAIT,   0, 3,               3, { 2048, 768, 2560, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d75_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 200, 0 } };
static const DemoMsg2  sMsg_d75_s22_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 828, 0 } };
static const DemoMsg2  sMsg_d75_s22_2     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d75_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 24 -- */
static const DemoMsg0  sMsg_d75_s24_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d75_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg2  sMsg_d75_s25_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 4,               1, { 1, 0 } };
static const DemoMsg0  sMsg_d75_s25_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 0,               0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d75_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d75_s26_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 0, 0, 64, 0 } };
/* -- step 27 -- */
static const DemoMsg4  sMsg_d75_s27_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 2816, 0 } };
static const DemoMsg4  sMsg_d75_s27_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2304, 768, 2816, 30 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d75_s28_0     = { 0x51E2, CLS_ACTOR,  WAIT,   0, 2,               1, { 4, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d75_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 30 -- */
static const DemoMsg0  sMsg_d75_s30_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d75_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d75_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d75_s32_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d75_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d75_s33_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d75_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg4  sMsg_d75_s34_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 160, 160, 0 } };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d75_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s35_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 66, 0 } };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d75_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 37 -- */
static const DemoMsg0  sMsg_d75_s37_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d75_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s38_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const DemoMsg2  sMsg_d75_s38_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
static const DemoMsg2  sMsg_d75_s38_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 39 -- */
static const DemoMsg2  sMsg_d75_s39_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 200, 0 } };
static const DemoMsg2  sMsg_d75_s39_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d75_s39_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d75_s40_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d75_s40_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const DemoMsg2  sMsg_d75_s40_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d75_s41_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 42 -- */
static const DemoMsg0  sMsg_d75_s42_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 43 -- */
static const DemoMsg2  sMsg_d75_s43_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d75_s43_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d75_s44_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d75_s44_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d75_s44_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 45 -- */
static const DemoMsg2  sMsg_d75_s45_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 46 -- */
static const DemoMsg0  sMsg_d75_s46_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 47 -- */
static const DemoMsg2  sMsg_d75_s47_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s47_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d75_s47_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 48 -- */
static const DemoMsg2  sMsg_d75_s48_0     = { 0x2B06, CLS_PLAYER, WAIT,   0, 21,              1, { 1, 0 } };
/* -- step 49 -- */
static const DemoMsg2  sMsg_d75_s49_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s49_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d75_s49_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d75_s49_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d75_s49_4     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d75_s49_5     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 57, 0 } };
/* -- step 50 -- */
static const DemoMsg2  sMsg_d75_s50_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 51 -- */
static const DemoMsg0  sMsg_d75_s51_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 52 -- */
static const DemoMsg2  sMsg_d75_s52_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s52_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 53 -- */
static const DemoMsg2  sMsg_d75_s53_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s53_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const DemoMsg2  sMsg_d75_s53_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
/* -- step 54 -- */
static const DemoMsg2  sMsg_d75_s54_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 160, 0 } };
/* -- step 55 -- */
static const DemoMsg2  sMsg_d75_s55_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d75_s55_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const DemoMsg2  sMsg_d75_s55_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
static const DemoMsg2  sMsg_d75_s55_3     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 56 -- */
static const DemoMsg2  sMsg_d75_s56_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 57 -- */
static const DemoMsg0  sMsg_d75_s57_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 58 -- */
static const DemoMsg2  sMsg_d75_s58_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d75_s58_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 59 -- */
static const DemoMsg2  sMsg_d75_s59_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 60 -- */
static const DemoMsg0  sMsg_d75_s60_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 61 -- */
static const DemoMsg2  sMsg_d75_s61_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s61_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 62 -- */
static const DemoMsg2  sMsg_d75_s62_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s62_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 36,              1, { 0, 0 } };
/* -- step 63 -- */
static const DemoMsg2  sMsg_d75_s63_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s63_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 42,              1, { 6, 0 } };
static const DemoMsg0  sMsg_d75_s63_2     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 28,              0 };
/* -- step 64 -- */
static const DemoMsg2  sMsg_d75_s64_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d75_s64_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d75_s64_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 65 -- */
static const DemoMsg2  sMsg_d75_s65_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d75_s65_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 66 -- */
static const DemoMsg2  sMsg_d75_s66_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d75_s66_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 37,              0 };
/* -- step 67 -- */
static const DemoMsg2  sMsg_d75_s67_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d75_s67_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 10,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d75_s67_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
/* -- step 68 -- */
static const DemoMsg2  sMsg_d75_s68_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s68_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 5, 0 } };
static const DemoMsg8  sMsg_d75_s68_2     = { 0x730A, CLS_FADE,   NOWAIT, 5, 0,               7, { 2048, 768, 2560, 128, 120, 20, 2, 0 } };
static const DemoMsg2  sMsg_d75_s68_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 69 -- */
static const DemoMsg2  sMsg_d75_s69_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d75_s69_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 21,              0 };
static const DemoMsg2  sMsg_d75_s69_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 70 -- */
static const DemoMsg2  sMsg_d75_s70_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 2,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d75_s70_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 71 -- */
static const DemoMsg2  sMsg_d75_s71_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 72 -- */
static const DemoMsg0  sMsg_d75_s72_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 73 -- */
static const DemoMsg2  sMsg_d75_s73_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s73_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 12,              1, { 1, 0 } };
/* -- step 74 -- */
static const DemoMsg2  sMsg_d75_s74_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d75_s74_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 742, 0 } };
/* -- step 75 -- */
static const DemoMsg2  sMsg_d75_s75_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 76 -- */
static const DemoMsg0  sMsg_d75_s76_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 77 -- */
static const DemoMsg2  sMsg_d75_s77_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d75_s77_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
/* -- step 78 -- */
static const DemoMsg2  sMsg_d75_s78_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 79 -- */
static const DemoMsg0  sMsg_d75_s79_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 80 -- */
static const DemoMsg2  sMsg_d75_s80_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d75_s80_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 81 -- */
static const DemoMsg2  sMsg_d75_s81_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 82 -- */
static const DemoMsg0  sMsg_d75_s82_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 83 -- */
static const DemoMsg2  sMsg_d75_s83_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s83_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d75_s83_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d75_s83_3     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 84 -- */
static const DemoMsg2  sMsg_d75_s84_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d75_s84_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg10 sMsg_d75_s84_2     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 85 -- */
static const DemoMsg4  sMsg_d75_s85_0     = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 2048, 0 } };
static const DemoMsg0  sMsg_d75_s85_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg0  sMsg_d75_s85_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
static const DemoMsg0  sMsg_d75_s85_3     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg4  sMsg_d75_s85_4     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 1,               3, { 2404, 918, 2460, 0 } };
/* -- step 86 -- */
static const DemoMsg2  sMsg_d75_s86_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg10 sMsg_d75_s86_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d75_s86_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d75_s86_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 87 -- */
static const DemoMsg2  sMsg_d75_s87_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d75_s87_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 60, 0 } };
/* -- step 88 -- */
static const DemoMsg2  sMsg_d75_s88_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 89 -- */
static const DemoMsg0  sMsg_d75_s89_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 90 -- */
static const DemoMsg2  sMsg_d75_s90_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
static const DemoMsg2  sMsg_d75_s90_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 91 -- */
static const DemoMsg2  sMsg_d75_s91_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
/* -- step 92 -- */
static const DemoMsg2  sMsg_d75_s92_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d75_s92_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const DemoMsg2  sMsg_d75_s92_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
/* -- step 93 -- */
static const DemoMsg2  sMsg_d75_s93_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d75_s93_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 94 -- */
static const DemoMsg2  sMsg_d75_s94_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
/* -- step 95 -- */
static const DemoMsg2  sMsg_d75_s95_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d75_s95_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const DemoMsg2  sMsg_d75_s95_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
/* -- step 96 -- */
static const DemoMsg2  sMsg_d75_s96_0     = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
/* -- step 97 -- */
static const DemoMsg2  sMsg_d75_s97_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 98 -- */
static const DemoMsg0  sMsg_d75_s98_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 99 -- */
static const DemoMsg4  sMsg_d75_s99_0     = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 1024, 0 } };
/* -- step 100 -- */
static const DemoMsg2  sMsg_d75_s100_0    = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const DemoMsg0  sMsg_d75_s100_1    = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d75_s100_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 85, 0 } };
/* ================ demo 76  (22 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d76_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d76_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 495, 0 } };
static const DemoMsg2  sMsg_d76_s0_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d76_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d76_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d76_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d76_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d76_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d76_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d76_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d76_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d76_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d76_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d76_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d76_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d76_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d76_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d76_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d76_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d76_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d76_s15_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d76_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d76_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d76_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d76_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d76_s19_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d76_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 21 -- */
static const DemoMsg0  sMsg_d76_s21_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 77  (36 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d77_s0_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1472, 256, 3520, 20 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d77_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d77_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d77_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d77_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg10 sMsg_d77_s4_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 2, 31, 0, 31, 1, 0, 0, 0, 0 } };
static const DemoMsg2  sMsg_d77_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 867, 0 } };
static const DemoMsg2  sMsg_d77_s4_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d77_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg10 sMsg_d77_s5_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 3, 31, 0, 31, 1, 0, 0, 0, 0 } };
static const DemoMsg4  sMsg_d77_s5_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 1, 1, 0 } };
static const DemoMsg2  sMsg_d77_s5_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 772, 0 } };
static const DemoMsg2  sMsg_d77_s5_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 230, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d77_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d77_s6_1      = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 0,               1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d77_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d77_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 0, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d77_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d77_s8_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d77_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d77_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d77_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d77_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d77_s12_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 42,              1, { 7, 0 } };
static const DemoMsg2  sMsg_d77_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 508, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d77_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d77_s13_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d77_s13_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d77_s13_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 12,              1, { 0, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d77_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d77_s14_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 42,              1, { 7, 0 } };
static const DemoMsg2  sMsg_d77_s14_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 508, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d77_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d77_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d77_s15_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 0, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d77_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d77_s16_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 7, 0 } };
static const DemoMsg2  sMsg_d77_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 488, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d77_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d77_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d77_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d77_s19_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 0, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d77_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d77_s20_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 24,              2, { 0, 10 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d77_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d77_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d77_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d77_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 17, 0 } };
static const DemoMsg0  sMsg_d77_s24_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 25,              0 };
static const DemoMsg2  sMsg_d77_s24_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 489, 0 } };
static const DemoMsg0  sMsg_d77_s24_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d77_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg10 sMsg_d77_s25_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 2, 31, 31, 31, 1, 0, 0, 0, 0 } };
static const DemoMsg2  sMsg_d77_s25_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 868, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d77_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg10 sMsg_d77_s26_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 3, 31, 31, 31, 1, 0, 0, 0, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d77_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 28 -- */
static const DemoMsg0  sMsg_d77_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d77_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d77_s29_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d77_s29_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 4,               1, { 9, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d77_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d77_s30_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 752, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d77_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d77_s31_1     = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 0,               1, { 10, 0 } };
static const DemoMsg2  sMsg_d77_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 2,               1, { 8, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d77_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 33 -- */
static const DemoMsg0  sMsg_d77_s33_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d77_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d77_s34_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 9,               0 };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d77_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d77_s35_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d77_s35_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 4,               1, { 5, 0 } };
/* ================ demo 78  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d78_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d78_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27778, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d78_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d78_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg4  sMsg_d78_s3_1      = { 0xB548, CLS_ACTOR,  NOWAIT, 0, 40,              3, { 2304, 768, 2304, 0 } };
static const DemoMsg2  sMsg_d78_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d78_s4_0      = { 0xF378, CLS_ETC,    WAIT,   0, 6,               0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d78_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ demo 79  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d79_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 512, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d79_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d79_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d79_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d79_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d79_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16593, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d79_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d79_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d79_s5_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d79_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d79_s6_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d79_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16593, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d79_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 80  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d80_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 512, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d80_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d80_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d80_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d80_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d80_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30089, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d80_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d80_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d80_s5_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d80_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d80_s6_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d80_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30089, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d80_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 81  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d81_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 2816, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d81_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 768, 2304, 0 } };
static const DemoMsg4  sMsg_d81_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1558, 918, 2294, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d81_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d81_s2_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d81_s2_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d81_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d81_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg4  sMsg_d81_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const DemoMsg2  sMsg_d81_s5_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d81_s5_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d81_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d81_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d81_s8_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1558, 918, 2294, 120 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d81_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d81_s9_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d81_s9_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d81_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d81_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d81_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d81_s12_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d81_s12_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d81_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d81_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d81_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d81_s15_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d81_s15_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d81_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d81_s16_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d81_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d81_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d81_s19_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 82  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d82_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 1280, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d82_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 1792, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d82_s2_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 2432, 0 } };
static const DemoMsg4  sMsg_d82_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1318, 918, 2602, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d82_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d82_s3_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d82_s3_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d82_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d82_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d82_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const DemoMsg2  sMsg_d82_s6_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d82_s6_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d82_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d82_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d82_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1318, 918, 2602, 120 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d82_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d82_s10_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d82_s10_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d82_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d82_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d82_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d82_s13_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
static const DemoMsg2  sMsg_d82_s13_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d82_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d82_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d82_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d82_s16_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d82_s16_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d82_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d82_s17_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d82_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d82_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d82_s20_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 83  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d83_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 2816, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d83_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 768, 2304, 0 } };
static const DemoMsg4  sMsg_d83_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1558, 918, 2294, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d83_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d83_s2_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d83_s2_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d83_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d83_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg4  sMsg_d83_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const DemoMsg2  sMsg_d83_s5_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d83_s5_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d83_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d83_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d83_s8_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1558, 918, 2294, 120 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d83_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d83_s9_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d83_s9_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d83_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d83_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d83_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d83_s12_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d83_s12_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d83_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d83_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d83_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d83_s15_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d83_s15_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d83_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d83_s16_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d83_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d83_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d83_s19_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 84  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d84_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 1280, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d84_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 1792, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d84_s2_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 2432, 0 } };
static const DemoMsg4  sMsg_d84_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1318, 918, 2602, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d84_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d84_s3_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d84_s3_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d84_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d84_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d84_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const DemoMsg2  sMsg_d84_s6_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d84_s6_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d84_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d84_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d84_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1318, 918, 2602, 120 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d84_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d84_s10_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d84_s10_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d84_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d84_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d84_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d84_s13_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d84_s13_2     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d84_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d84_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d84_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d84_s16_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d84_s16_2     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d84_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d84_s17_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d84_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d84_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d84_s20_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 85  (17 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d85_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 640, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d85_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d85_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d85_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d85_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d85_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12996, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d85_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d85_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d85_s5_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 24,              0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d85_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d85_s6_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d85_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d85_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d85_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d85_s8_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d85_s8_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 0, 0 } };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d85_s9_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 384, 256, 497, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d85_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d85_s10_1     = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 26,              3, { 384, 256, 640, 0 } };
static const DemoMsg2  sMsg_d85_s10_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d85_s10_3     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 6, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d85_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d85_s11_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 12 -- */
static const DemoMsg4  sMsg_d85_s12_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 640, 256, 1024, 0 } };
static const DemoMsg2  sMsg_d85_s12_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d85_s12_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 13 -- */
static const DemoMsg4  sMsg_d85_s13_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 640, 256, 1408, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d85_s14_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d85_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12996, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d85_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 86  (13 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d86_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 6016, 256, 2688, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d86_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d86_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d86_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d86_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d86_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3803, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d86_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d86_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d86_s5_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d86_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d86_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
static const DemoMsg2  sMsg_d86_s6_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d86_s6_3      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d86_s7_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2432, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d86_s8_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5120, 256, 2432, 0 } };
static const DemoMsg2  sMsg_d86_s8_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d86_s9_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 4352, 768, 1792, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d86_s10_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d86_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3803, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d86_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 87  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d87_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d87_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d87_s1_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d87_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d87_s2_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2432, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d87_s3_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5120, 768, 2432, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d87_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 4352, 768, 1792, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d87_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* ================ demo 88  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d88_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 4864, 768, 1792, 0 } };
static const DemoMsg2  sMsg_d88_s0_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d88_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d88_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d88_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d88_s2_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d88_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d88_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d88_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 3500, 768, 1792, 0 } };
/* -- step 5 -- */
static const DemoMsg4  sMsg_d88_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 1536, 768, 1792, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d88_s6_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* ================ demo 89  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d89_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 2048, 768, 1792, 0 } };
static const DemoMsg2  sMsg_d89_s0_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d89_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d89_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d89_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d89_s2_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d89_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d89_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d89_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 500, 768, 1792, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d89_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* ================ demo 90  (46 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d90_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 7040, 256, 6784, 0 } };
static const DemoMsg4  sMsg_d90_s0_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 7296, 256, 6656, 0 } };
static const DemoMsg2  sMsg_d90_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d90_s0_3      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7230, 406, 6734, 60 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d90_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d90_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d90_s1_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d90_s2_0      = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 24,              0 };
static const DemoMsg2  sMsg_d90_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 600, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d90_s3_0      = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 3,               3, { 7062, 256, 6334, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d90_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d90_s4_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d90_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d90_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d90_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d90_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d90_s7_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d90_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d90_s8_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 7424, 256, 6784, 0 } };
static const DemoMsg6  sMsg_d90_s8_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 30, 20, 5, 0 } };
static const DemoMsg2  sMsg_d90_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
static const DemoMsg2  sMsg_d90_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 920, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d90_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg2  sMsg_d90_s9_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 38,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d90_s9_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const DemoMsg6  sMsg_d90_s9_3      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 150, 20, 5, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d90_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d90_s10_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 11 -- */
static const DemoMsg4  sMsg_d90_s11_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 3,               3, { 7008, 256, 6334, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d90_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d90_s12_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 23,              0 };
static const DemoMsg2  sMsg_d90_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d90_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg4  sMsg_d90_s13_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 150, 150, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d90_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d90_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d90_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d90_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 1,               3, { 7424, 256, 6656, 0 } };
static const DemoMsg4  sMsg_d90_s15_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7168, 256, 6656, 0 } };
static const DemoMsg4  sMsg_d90_s15_3     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7552, 256, 6528, 0 } };
static const DemoMsg0  sMsg_d90_s15_4     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 39,              0 };
static const DemoMsg2  sMsg_d90_s15_5     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 304, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d90_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg4  sMsg_d90_s16_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7470, 406, 6794, 40 } };
static const DemoMsg2  sMsg_d90_s16_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d90_s16_3     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d90_s16_4     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d90_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d90_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d90_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d90_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d90_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d90_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d90_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d90_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d90_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 25 -- */
static const DemoMsg0  sMsg_d90_s25_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d90_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d90_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 28 -- */
static const DemoMsg0  sMsg_d90_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d90_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d90_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d90_s30_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d90_s30_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d90_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg6  sMsg_d90_s31_1     = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const DemoMsg2  sMsg_d90_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d90_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d90_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d90_s33_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const DemoMsg0  sMsg_d90_s33_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d90_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d90_s34_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d90_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 36 -- */
static const DemoMsg0  sMsg_d90_s36_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d90_s37_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d90_s37_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d90_s37_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d90_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 39 -- */
static const DemoMsg0  sMsg_d90_s39_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d90_s40_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d90_s40_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const DemoMsg0  sMsg_d90_s40_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d90_s40_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d90_s41_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d90_s41_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d90_s41_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 42 -- */
static const DemoMsg2  sMsg_d90_s42_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 43 -- */
static const DemoMsg0  sMsg_d90_s43_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d90_s44_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d90_s44_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d90_s44_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 45 -- */
static const DemoMsg2  sMsg_d90_s45_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ demo 91  (46 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d91_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 7040, 256, 6784, 0 } };
static const DemoMsg2  sMsg_d91_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d91_s0_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7230, 406, 6734, 60 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d91_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d91_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d91_s2_0      = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 24,              0 };
static const DemoMsg2  sMsg_d91_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 600, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d91_s3_0      = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 3,               3, { 7062, 256, 6334, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d91_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d91_s4_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d91_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d91_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d91_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d91_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d91_s7_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d91_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d91_s8_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 7424, 256, 6784, 0 } };
static const DemoMsg6  sMsg_d91_s8_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 30, 20, 5, 0 } };
static const DemoMsg2  sMsg_d91_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
static const DemoMsg2  sMsg_d91_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 920, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d91_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg2  sMsg_d91_s9_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 38,              1, { 3, 0 } };
static const DemoMsg6  sMsg_d91_s9_2      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 150, 20, 5, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d91_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d91_s10_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 11 -- */
static const DemoMsg4  sMsg_d91_s11_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   0, 3,               3, { 7008, 256, 6334, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d91_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d91_s12_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 23,              0 };
static const DemoMsg2  sMsg_d91_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d91_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg4  sMsg_d91_s13_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 150, 150, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d91_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d91_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d91_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d91_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 1,               3, { 7424, 256, 6656, 0 } };
static const DemoMsg4  sMsg_d91_s15_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7168, 256, 6656, 0 } };
static const DemoMsg0  sMsg_d91_s15_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 39,              0 };
static const DemoMsg2  sMsg_d91_s15_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 304, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d91_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg4  sMsg_d91_s16_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7470, 406, 6794, 40 } };
static const DemoMsg2  sMsg_d91_s16_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d91_s16_3     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d91_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d91_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d91_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d91_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d91_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d91_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d91_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d91_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d91_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 25 -- */
static const DemoMsg0  sMsg_d91_s25_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d91_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d91_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 28 -- */
static const DemoMsg0  sMsg_d91_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d91_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d91_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d91_s30_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d91_s30_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d91_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg6  sMsg_d91_s31_1     = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const DemoMsg2  sMsg_d91_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d91_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d91_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d91_s33_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const DemoMsg0  sMsg_d91_s33_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d91_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d91_s34_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d91_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 36 -- */
static const DemoMsg0  sMsg_d91_s36_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d91_s37_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d91_s37_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d91_s37_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d91_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 39 -- */
static const DemoMsg0  sMsg_d91_s39_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d91_s40_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d91_s40_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const DemoMsg0  sMsg_d91_s40_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d91_s40_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d91_s41_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d91_s41_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d91_s41_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 42 -- */
static const DemoMsg2  sMsg_d91_s42_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 43 -- */
static const DemoMsg0  sMsg_d91_s43_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d91_s44_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg10 sMsg_d91_s44_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d91_s44_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 45 -- */
static const DemoMsg2  sMsg_d91_s45_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ demo 92  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d92_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 7552, 256, 6784, 0 } };
static const DemoMsg4  sMsg_d92_s0_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7570, 406, 6694, 40 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d92_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d92_s1_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d92_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d92_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d92_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d92_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d92_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d92_s5_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d92_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d92_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg6  sMsg_d92_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const DemoMsg2  sMsg_d92_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d92_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d92_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d92_s8_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const DemoMsg0  sMsg_d92_s8_2      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d92_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d92_s9_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d92_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d92_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d92_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d92_s12_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d92_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d92_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d92_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d92_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d92_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const DemoMsg0  sMsg_d92_s15_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d92_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d92_s16_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 7, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d92_s16_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d92_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d92_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d92_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg10 sMsg_d92_s19_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d92_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ demo 93  (14 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d93_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d93_s0_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d93_s0_2      = { 0x6773, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d93_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 512, 256, 512, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d93_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d93_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d93_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d93_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d93_s6_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 640, 256, 896, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d93_s7_0      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d93_s7_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d93_s7_2      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d93_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d93_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d93_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d93_s10_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d93_s10_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d93_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d93_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d93_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d93_s13_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 19,              0 };
/* ================ demo 94  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d94_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 4992, 768, 2944, 0 } };
static const DemoMsg4  sMsg_d94_s0_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 4992, 768, 2816, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d94_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d94_s1_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d94_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d94_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d94_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d94_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12752, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d94_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d94_s5_0      = { 0xF68F, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d94_s6_0      = { 0xF68F, CLS_ACTOR,  WAIT,   3, 3,               3, { 4480, 768, 2944, 0 } };
static const DemoMsg2  sMsg_d94_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d94_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d94_s7_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 95  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d95_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 4992, 768, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d95_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d95_s1_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d95_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d95_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d95_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12948, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d95_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d95_s5_0      = { 0xF68F, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d95_s6_0      = { 0xF68F, CLS_ACTOR,  WAIT,   3, 3,               3, { 4480, 768, 2944, 0 } };
static const DemoMsg2  sMsg_d95_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d95_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d95_s7_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 96  (14 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d96_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 6784, 256, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d96_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d96_s1_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d96_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d96_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d96_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d96_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d96_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d96_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d96_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d96_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d96_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d96_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d96_s11_0     = { 0x8E9F, CLS_ACTOR,  WAIT,   3, 2,               1, { 1, 0 } };
/* -- step 12 -- */
static const DemoMsg4  sMsg_d96_s12_0     = { 0x8E9F, CLS_ACTOR,  WAIT,   3, 3,               3, { 6784, 256, 2432, 0 } };
static const DemoMsg2  sMsg_d96_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d96_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d96_s13_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 97  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d97_s0_0      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2304, 768, 2304, 120 } };
static const DemoMsg4  sMsg_d97_s0_1      = { 0x9CFE, CLS_ACTOR,  WAIT,   3, 3,               3, { 2304, 768, 2304, 0 } };
static const DemoMsg4  sMsg_d97_s0_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 6,               3, { 2304, 768, 2560, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d97_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d97_s1_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d97_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d97_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 27732, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d97_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d97_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d97_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d97_s5_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 349, 0 } };
static const DemoMsg2  sMsg_d97_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg0  sMsg_d97_s5_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 9,               0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d97_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg10 sMsg_d97_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d97_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 608, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d97_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d97_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 9, 0 } };
/* ================ demo 98  (3 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d98_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d98_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 512, 4480, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d98_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3248, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d98_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 99  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d99_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d99_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d99_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d99_s1_1      = { 0x3436, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d99_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d99_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d99_s3_0      = { 0x3436, CLS_ACTOR,  WAIT,   0, 3,               3, { 3456, 1024, 2304, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d99_s4_0      = { 0x3436, CLS_ACTOR,  WAIT,   0, 0,               0 };
// clang-format on
