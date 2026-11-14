// clang-format off
/* ================ cutscene 75  (101 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg0  sMsg_c75_s0_0      = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const CutsceneMsg4  sMsg_c75_s0_1      = { TGT_KURO, CLS_ACTOR,  WAIT,   0, 3,               3, { 2384, 768, 1792, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c75_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2304, 768, 2688, 60 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c75_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c75_s2_1      = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c75_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c75_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c75_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c75_s5_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 4,               1, { 1, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c75_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c75_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 61, 0 } };
static const CutsceneMsg2  sMsg_c75_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 5, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c75_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c75_s8_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c75_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c75_s9_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c75_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c75_s11_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c75_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c75_s12_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 30,              1, { 1, 0 } };
static const CutsceneMsg0  sMsg_c75_s12_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 21,              0 };
static const CutsceneMsg2  sMsg_c75_s12_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 219, 0 } };
static const CutsceneMsg2  sMsg_c75_s12_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 818, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c75_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c75_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c75_s15_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c75_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c75_s16_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 31,              0 };
static const CutsceneMsg2  sMsg_c75_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 855, 0 } };
static const CutsceneMsg2  sMsg_c75_s16_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 819, 0 } };
static const CutsceneMsg2  sMsg_c75_s16_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c75_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg10 sMsg_c75_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 0, 0, 64, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c75_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 64, 0 } };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c75_s19_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 20 -- */
static const CutsceneMsg0  sMsg_c75_s20_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const CutsceneMsg4  sMsg_c75_s21_0     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 1,               3, { 2304, 768, 2560, 0 } };
static const CutsceneMsg4  sMsg_c75_s21_1     = { TGT_KURO, CLS_ACTOR,  WAIT,   0, 3,               3, { 2048, 768, 2560, 0 } };
/* -- step 22 -- */
static const CutsceneMsg2  sMsg_c75_s22_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 200, 0 } };
static const CutsceneMsg2  sMsg_c75_s22_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 828, 0 } };
static const CutsceneMsg2  sMsg_c75_s22_2     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 23 -- */
static const CutsceneMsg2  sMsg_c75_s23_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 24 -- */
static const CutsceneMsg0  sMsg_c75_s24_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 25 -- */
static const CutsceneMsg2  sMsg_c75_s25_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const CutsceneMsg2  sMsg_c75_s25_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 4,               1, { 1, 0 } };
static const CutsceneMsg0  sMsg_c75_s25_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 0,               0 };
/* -- step 26 -- */
static const CutsceneMsg2  sMsg_c75_s26_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c75_s26_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 0, 0, 64, 0 } };
/* -- step 27 -- */
static const CutsceneMsg4  sMsg_c75_s27_0     = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 2816, 0 } };
static const CutsceneMsg4  sMsg_c75_s27_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2304, 768, 2816, 30 } };
/* -- step 28 -- */
static const CutsceneMsg2  sMsg_c75_s28_0     = { TGT_KURO, CLS_ACTOR,  WAIT,   0, 2,               1, { 4, 0 } };
/* -- step 29 -- */
static const CutsceneMsg2  sMsg_c75_s29_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 30 -- */
static const CutsceneMsg0  sMsg_c75_s30_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 31 -- */
static const CutsceneMsg2  sMsg_c75_s31_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 32 -- */
static const CutsceneMsg2  sMsg_c75_s32_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c75_s32_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 33 -- */
static const CutsceneMsg2  sMsg_c75_s33_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c75_s33_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 34 -- */
static const CutsceneMsg2  sMsg_c75_s34_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const CutsceneMsg4  sMsg_c75_s34_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 160, 160, 0 } };
/* -- step 35 -- */
static const CutsceneMsg2  sMsg_c75_s35_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s35_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 66, 0 } };
/* -- step 36 -- */
static const CutsceneMsg2  sMsg_c75_s36_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 37 -- */
static const CutsceneMsg0  sMsg_c75_s37_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 38 -- */
static const CutsceneMsg2  sMsg_c75_s38_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s38_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const CutsceneMsg2  sMsg_c75_s38_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
static const CutsceneMsg2  sMsg_c75_s38_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 39 -- */
static const CutsceneMsg2  sMsg_c75_s39_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 200, 0 } };
static const CutsceneMsg2  sMsg_c75_s39_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s39_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 40 -- */
static const CutsceneMsg2  sMsg_c75_s40_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const CutsceneMsg0  sMsg_c75_s40_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const CutsceneMsg2  sMsg_c75_s40_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
/* -- step 41 -- */
static const CutsceneMsg2  sMsg_c75_s41_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 42 -- */
static const CutsceneMsg0  sMsg_c75_s42_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 43 -- */
static const CutsceneMsg2  sMsg_c75_s43_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c75_s43_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 44 -- */
static const CutsceneMsg2  sMsg_c75_s44_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c75_s44_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s44_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 45 -- */
static const CutsceneMsg2  sMsg_c75_s45_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 46 -- */
static const CutsceneMsg0  sMsg_c75_s46_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 47 -- */
static const CutsceneMsg2  sMsg_c75_s47_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s47_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s47_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 48 -- */
static const CutsceneMsg2  sMsg_c75_s48_0     = { TGT_SABATA, CLS_PLAYER, WAIT,   0, 21,              1, { 1, 0 } };
/* -- step 49 -- */
static const CutsceneMsg2  sMsg_c75_s49_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s49_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c75_s49_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c75_s49_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
static const CutsceneMsg2  sMsg_c75_s49_4     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c75_s49_5     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 57, 0 } };
/* -- step 50 -- */
static const CutsceneMsg2  sMsg_c75_s50_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 51 -- */
static const CutsceneMsg0  sMsg_c75_s51_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 52 -- */
static const CutsceneMsg2  sMsg_c75_s52_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s52_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 53 -- */
static const CutsceneMsg2  sMsg_c75_s53_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s53_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const CutsceneMsg2  sMsg_c75_s53_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
/* -- step 54 -- */
static const CutsceneMsg2  sMsg_c75_s54_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 160, 0 } };
/* -- step 55 -- */
static const CutsceneMsg2  sMsg_c75_s55_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c75_s55_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const CutsceneMsg2  sMsg_c75_s55_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
static const CutsceneMsg2  sMsg_c75_s55_3     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 56 -- */
static const CutsceneMsg2  sMsg_c75_s56_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 57 -- */
static const CutsceneMsg0  sMsg_c75_s57_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 58 -- */
static const CutsceneMsg2  sMsg_c75_s58_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c75_s58_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 59 -- */
static const CutsceneMsg2  sMsg_c75_s59_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 60 -- */
static const CutsceneMsg0  sMsg_c75_s60_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 61 -- */
static const CutsceneMsg2  sMsg_c75_s61_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s61_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 62 -- */
static const CutsceneMsg2  sMsg_c75_s62_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s62_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 36,              1, { 0, 0 } };
/* -- step 63 -- */
static const CutsceneMsg2  sMsg_c75_s63_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s63_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 42,              1, { 6, 0 } };
static const CutsceneMsg0  sMsg_c75_s63_2     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 28,              0 };
/* -- step 64 -- */
static const CutsceneMsg2  sMsg_c75_s64_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg10 sMsg_c75_s64_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s64_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 65 -- */
static const CutsceneMsg2  sMsg_c75_s65_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c75_s65_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 66 -- */
static const CutsceneMsg2  sMsg_c75_s66_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg0  sMsg_c75_s66_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 37,              0 };
/* -- step 67 -- */
static const CutsceneMsg2  sMsg_c75_s67_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c75_s67_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 10,              1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c75_s67_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
/* -- step 68 -- */
static const CutsceneMsg2  sMsg_c75_s68_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s68_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 5, 0 } };
static const CutsceneMsg8  sMsg_c75_s68_2     = { 0x730A, CLS_FADE,   NOWAIT, 5, 0,               7, { 2048, 768, 2560, 128, 120, 20, 2, 0 } };
static const CutsceneMsg2  sMsg_c75_s68_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 69 -- */
static const CutsceneMsg2  sMsg_c75_s69_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c75_s69_1     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 21,              0 };
static const CutsceneMsg2  sMsg_c75_s69_2     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 70 -- */
static const CutsceneMsg2  sMsg_c75_s70_0     = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 2,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s70_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 71 -- */
static const CutsceneMsg2  sMsg_c75_s71_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 72 -- */
static const CutsceneMsg0  sMsg_c75_s72_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 73 -- */
static const CutsceneMsg2  sMsg_c75_s73_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s73_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 12,              1, { 1, 0 } };
/* -- step 74 -- */
static const CutsceneMsg2  sMsg_c75_s74_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c75_s74_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 742, 0 } };
/* -- step 75 -- */
static const CutsceneMsg2  sMsg_c75_s75_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 76 -- */
static const CutsceneMsg0  sMsg_c75_s76_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 77 -- */
static const CutsceneMsg2  sMsg_c75_s77_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c75_s77_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
/* -- step 78 -- */
static const CutsceneMsg2  sMsg_c75_s78_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 79 -- */
static const CutsceneMsg0  sMsg_c75_s79_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 80 -- */
static const CutsceneMsg2  sMsg_c75_s80_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c75_s80_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 81 -- */
static const CutsceneMsg2  sMsg_c75_s81_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 82 -- */
static const CutsceneMsg0  sMsg_c75_s82_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 83 -- */
static const CutsceneMsg2  sMsg_c75_s83_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s83_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c75_s83_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c75_s83_3     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 84 -- */
static const CutsceneMsg2  sMsg_c75_s84_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c75_s84_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const CutsceneMsg10 sMsg_c75_s84_2     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 85 -- */
static const CutsceneMsg4  sMsg_c75_s85_0     = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 2048, 0 } };
static const CutsceneMsg0  sMsg_c75_s85_1     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const CutsceneMsg0  sMsg_c75_s85_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
static const CutsceneMsg0  sMsg_c75_s85_3     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const CutsceneMsg4  sMsg_c75_s85_4     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 1,               3, { 2404, 918, 2460, 0 } };
/* -- step 86 -- */
static const CutsceneMsg2  sMsg_c75_s86_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg10 sMsg_c75_s86_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c75_s86_2     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c75_s86_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 87 -- */
static const CutsceneMsg2  sMsg_c75_s87_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg2  sMsg_c75_s87_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 60, 0 } };
/* -- step 88 -- */
static const CutsceneMsg2  sMsg_c75_s88_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 89 -- */
static const CutsceneMsg0  sMsg_c75_s89_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 90 -- */
static const CutsceneMsg2  sMsg_c75_s90_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
static const CutsceneMsg2  sMsg_c75_s90_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 91 -- */
static const CutsceneMsg2  sMsg_c75_s91_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
/* -- step 92 -- */
static const CutsceneMsg2  sMsg_c75_s92_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c75_s92_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 10 } };
static const CutsceneMsg2  sMsg_c75_s92_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 121, 0 } };
/* -- step 93 -- */
static const CutsceneMsg2  sMsg_c75_s93_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c75_s93_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 94 -- */
static const CutsceneMsg2  sMsg_c75_s94_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
/* -- step 95 -- */
static const CutsceneMsg2  sMsg_c75_s95_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c75_s95_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const CutsceneMsg2  sMsg_c75_s95_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 9, 0 } };
/* -- step 96 -- */
static const CutsceneMsg2  sMsg_c75_s96_0     = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
/* -- step 97 -- */
static const CutsceneMsg2  sMsg_c75_s97_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -72, 0 } };
/* -- step 98 -- */
static const CutsceneMsg0  sMsg_c75_s98_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 99 -- */
static const CutsceneMsg4  sMsg_c75_s99_0     = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2304, 768, 1024, 0 } };
/* -- step 100 -- */
static const CutsceneMsg2  sMsg_c75_s100_0    = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const CutsceneMsg0  sMsg_c75_s100_1    = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const CutsceneMsg2  sMsg_c75_s100_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 85, 0 } };
/* ================ cutscene 76  (22 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c76_s0_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c76_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 495, 0 } };
static const CutsceneMsg2  sMsg_c76_s0_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c76_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c76_s1_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c76_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c76_s3_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c76_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c76_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c76_s6_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c76_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c76_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c76_s9_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c76_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c76_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c76_s12_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c76_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c76_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c76_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c76_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c76_s15_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c76_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 17 -- */
static const CutsceneMsg0  sMsg_c76_s17_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c76_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c76_s19_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c76_s19_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c76_s20_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 24945, 0 } };
/* -- step 21 -- */
static const CutsceneMsg0  sMsg_c76_s21_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 77  (36 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c77_s0_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1472, 256, 3520, 20 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c77_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c77_s2_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c77_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c77_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg10 sMsg_c77_s4_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 2, 31, 0, 31, 1, 0, 0, 0, 0 } };
static const CutsceneMsg2  sMsg_c77_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 867, 0 } };
static const CutsceneMsg2  sMsg_c77_s4_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c77_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg10 sMsg_c77_s5_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 3, 31, 0, 31, 1, 0, 0, 0, 0 } };
static const CutsceneMsg4  sMsg_c77_s5_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 1, 1, 0 } };
static const CutsceneMsg2  sMsg_c77_s5_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 772, 0 } };
static const CutsceneMsg2  sMsg_c77_s5_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 230, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c77_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c77_s6_1      = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 0,               1, { 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c77_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c77_s7_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 13,              1, { 0, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c77_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c77_s8_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c77_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c77_s10_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c77_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c77_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c77_s12_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 42,              1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c77_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 508, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c77_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c77_s13_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const CutsceneMsg2  sMsg_c77_s13_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c77_s13_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 12,              1, { 0, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c77_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c77_s14_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 42,              1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c77_s14_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 508, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c77_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c77_s15_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const CutsceneMsg2  sMsg_c77_s15_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 13,              1, { 0, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c77_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c77_s16_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 43,              1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c77_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 488, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c77_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c77_s18_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c77_s19_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c77_s19_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 5,               1, { 0, 0 } };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c77_s20_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c77_s20_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 24,              2, { 0, 10 } };
/* -- step 21 -- */
static const CutsceneMsg2  sMsg_c77_s21_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 22 -- */
static const CutsceneMsg0  sMsg_c77_s22_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const CutsceneMsg2  sMsg_c77_s23_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 24 -- */
static const CutsceneMsg2  sMsg_c77_s24_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 17, 0 } };
static const CutsceneMsg0  sMsg_c77_s24_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 25,              0 };
static const CutsceneMsg2  sMsg_c77_s24_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 489, 0 } };
static const CutsceneMsg0  sMsg_c77_s24_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 25 -- */
static const CutsceneMsg2  sMsg_c77_s25_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg10 sMsg_c77_s25_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 2, 31, 31, 31, 1, 0, 0, 0, 0 } };
static const CutsceneMsg2  sMsg_c77_s25_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 868, 0 } };
/* -- step 26 -- */
static const CutsceneMsg2  sMsg_c77_s26_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg10 sMsg_c77_s26_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 3, 31, 31, 31, 1, 0, 0, 0, 0 } };
/* -- step 27 -- */
static const CutsceneMsg2  sMsg_c77_s27_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 28 -- */
static const CutsceneMsg0  sMsg_c77_s28_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const CutsceneMsg2  sMsg_c77_s29_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c77_s29_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c77_s29_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 4,               1, { 9, 0 } };
/* -- step 30 -- */
static const CutsceneMsg2  sMsg_c77_s30_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c77_s30_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 752, 0 } };
/* -- step 31 -- */
static const CutsceneMsg2  sMsg_c77_s31_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c77_s31_1     = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 0,               1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c77_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 2,               1, { 8, 0 } };
/* -- step 32 -- */
static const CutsceneMsg2  sMsg_c77_s32_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19480, 0 } };
/* -- step 33 -- */
static const CutsceneMsg0  sMsg_c77_s33_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const CutsceneMsg2  sMsg_c77_s34_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg0  sMsg_c77_s34_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 9,               0 };
/* -- step 35 -- */
static const CutsceneMsg2  sMsg_c77_s35_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c77_s35_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c77_s35_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 4,               1, { 5, 0 } };
/* ================ cutscene 78  (6 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c78_s0_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c78_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27778, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c78_s2_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c78_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg4  sMsg_c78_s3_1      = { TGT_MEGAMAN, CLS_ACTOR,  NOWAIT, 0, 40,              3, { 2304, 768, 2304, 0 } };
static const CutsceneMsg2  sMsg_c78_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c78_s4_0      = { 0xF378, CLS_ETC,    WAIT,   0, 6,               0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c78_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ cutscene 79  (9 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c79_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 512, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c79_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c79_s1_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c79_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c79_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c79_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16593, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c79_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c79_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg2  sMsg_c79_s5_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c79_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c79_s6_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c79_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16593, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c79_s8_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 80  (9 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c80_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 512, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c80_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c80_s1_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c80_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c80_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c80_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30089, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c80_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c80_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg2  sMsg_c80_s5_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c80_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c80_s6_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c80_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30089, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c80_s8_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 81  (20 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c81_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 2816, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c81_s1_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 768, 2304, 0 } };
static const CutsceneMsg4  sMsg_c81_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1558, 918, 2294, 60 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c81_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c81_s2_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c81_s2_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c81_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c81_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg4  sMsg_c81_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const CutsceneMsg2  sMsg_c81_s5_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c81_s5_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c81_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 7 -- */
static const CutsceneMsg0  sMsg_c81_s7_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const CutsceneMsg4  sMsg_c81_s8_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1558, 918, 2294, 120 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c81_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c81_s9_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c81_s9_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c81_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c81_s11_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c81_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c81_s12_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 6, 0 } };
static const CutsceneMsg2  sMsg_c81_s12_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c81_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 14 -- */
static const CutsceneMsg0  sMsg_c81_s14_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c81_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c81_s15_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c81_s15_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c81_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c81_s16_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c81_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26866, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c81_s18_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c81_s19_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ cutscene 82  (21 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c82_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 1280, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c82_s1_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 1792, 0 } };
/* -- step 2 -- */
static const CutsceneMsg4  sMsg_c82_s2_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 2432, 0 } };
static const CutsceneMsg4  sMsg_c82_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1318, 918, 2602, 60 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c82_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c82_s3_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c82_s3_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c82_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c82_s5_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c82_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const CutsceneMsg2  sMsg_c82_s6_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c82_s6_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c82_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c82_s8_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg4  sMsg_c82_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1318, 918, 2602, 120 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c82_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c82_s10_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c82_s10_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c82_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c82_s12_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c82_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c82_s13_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
static const CutsceneMsg2  sMsg_c82_s13_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c82_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c82_s15_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c82_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c82_s16_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c82_s16_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c82_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c82_s17_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c82_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -6414, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c82_s19_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c82_s20_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ cutscene 83  (20 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c83_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 2816, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c83_s1_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 768, 2304, 0 } };
static const CutsceneMsg4  sMsg_c83_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1558, 918, 2294, 60 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c83_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c83_s2_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c83_s2_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c83_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c83_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg4  sMsg_c83_s5_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const CutsceneMsg2  sMsg_c83_s5_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c83_s5_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c83_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 7 -- */
static const CutsceneMsg0  sMsg_c83_s7_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const CutsceneMsg4  sMsg_c83_s8_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1558, 918, 2294, 120 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c83_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c83_s9_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c83_s9_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c83_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c83_s11_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c83_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c83_s12_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 6, 0 } };
static const CutsceneMsg2  sMsg_c83_s12_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c83_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 14 -- */
static const CutsceneMsg0  sMsg_c83_s14_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c83_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c83_s15_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c83_s15_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c83_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c83_s16_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c83_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 17838, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c83_s18_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c83_s19_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ cutscene 84  (21 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c84_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1024, 768, 1280, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c84_s1_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 1792, 0 } };
/* -- step 2 -- */
static const CutsceneMsg4  sMsg_c84_s2_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 768, 2432, 0 } };
static const CutsceneMsg4  sMsg_c84_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1318, 918, 2602, 60 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c84_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c84_s3_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c84_s3_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c84_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c84_s5_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c84_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 612, 768, 1636, 120 } };
static const CutsceneMsg2  sMsg_c84_s6_1      = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c84_s6_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c84_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c84_s8_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg4  sMsg_c84_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1318, 918, 2602, 120 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c84_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c84_s10_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c84_s10_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c84_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c84_s12_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c84_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c84_s13_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c84_s13_2     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c84_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c84_s15_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c84_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c84_s16_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c84_s16_2     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c84_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c84_s17_1     = { TGT_RITA, CLS_ACTOR,  NOWAIT, 0, 13,              0 };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c84_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15442, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c84_s19_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c84_s20_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ cutscene 85  (17 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c85_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 640, 256, 640, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c85_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c85_s1_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c85_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c85_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c85_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12996, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c85_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c85_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg0  sMsg_c85_s5_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 24,              0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c85_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c85_s6_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c85_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c85_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c85_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c85_s8_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c85_s8_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 0, 0 } };
/* -- step 9 -- */
static const CutsceneMsg4  sMsg_c85_s9_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 384, 256, 497, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c85_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg4  sMsg_c85_s10_1     = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 26,              3, { 384, 256, 640, 0 } };
static const CutsceneMsg2  sMsg_c85_s10_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c85_s10_3     = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 6, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c85_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c85_s11_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 12 -- */
static const CutsceneMsg4  sMsg_c85_s12_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 640, 256, 1024, 0 } };
static const CutsceneMsg2  sMsg_c85_s12_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c85_s12_2     = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 13 -- */
static const CutsceneMsg4  sMsg_c85_s13_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 640, 256, 1408, 0 } };
/* -- step 14 -- */
static const CutsceneMsg0  sMsg_c85_s14_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c85_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12996, 0 } };
/* -- step 16 -- */
static const CutsceneMsg0  sMsg_c85_s16_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 86  (13 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c86_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 6016, 256, 2688, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c86_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c86_s1_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c86_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c86_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c86_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3803, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c86_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c86_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c86_s5_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c86_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c86_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
static const CutsceneMsg2  sMsg_c86_s6_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c86_s6_3      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 7 -- */
static const CutsceneMsg4  sMsg_c86_s7_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2432, 0 } };
/* -- step 8 -- */
static const CutsceneMsg4  sMsg_c86_s8_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5120, 256, 2432, 0 } };
static const CutsceneMsg2  sMsg_c86_s8_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 9 -- */
static const CutsceneMsg4  sMsg_c86_s9_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 4352, 768, 1792, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c86_s10_0     = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c86_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3803, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c86_s12_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 87  (6 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c87_s0_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c87_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c87_s1_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c87_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg4  sMsg_c87_s2_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2432, 0 } };
/* -- step 3 -- */
static const CutsceneMsg4  sMsg_c87_s3_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 5120, 768, 2432, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c87_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 4352, 768, 1792, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c87_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* ================ cutscene 88  (7 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c88_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 4864, 768, 1792, 0 } };
static const CutsceneMsg2  sMsg_c88_s0_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c88_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c88_s1_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c88_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c88_s2_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c88_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c88_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c88_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 3500, 768, 1792, 0 } };
/* -- step 5 -- */
static const CutsceneMsg4  sMsg_c88_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 41,              3, { 1536, 768, 1792, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c88_s6_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* ================ cutscene 89  (6 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c89_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 2048, 768, 1792, 0 } };
static const CutsceneMsg2  sMsg_c89_s0_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c89_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c89_s1_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c89_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c89_s2_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c89_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c89_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c89_s4_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 500, 768, 1792, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c89_s5_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* ================ cutscene 90  (46 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c90_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 7040, 256, 6784, 0 } };
static const CutsceneMsg4  sMsg_c90_s0_1      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 7296, 256, 6656, 0 } };
static const CutsceneMsg2  sMsg_c90_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c90_s0_3      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7230, 406, 6734, 60 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c90_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c90_s1_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c90_s1_2      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c90_s2_0      = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 24,              0 };
static const CutsceneMsg2  sMsg_c90_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 600, 0 } };
/* -- step 3 -- */
static const CutsceneMsg4  sMsg_c90_s3_0      = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 3,               3, { 7062, 256, 6334, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c90_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c90_s4_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c90_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c90_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c90_s6_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c90_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c90_s7_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const CutsceneMsg2  sMsg_c90_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 8 -- */
static const CutsceneMsg4  sMsg_c90_s8_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 7424, 256, 6784, 0 } };
static const CutsceneMsg6  sMsg_c90_s8_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 30, 20, 5, 0 } };
static const CutsceneMsg2  sMsg_c90_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
static const CutsceneMsg2  sMsg_c90_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 920, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c90_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const CutsceneMsg2  sMsg_c90_s9_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 38,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c90_s9_2      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const CutsceneMsg6  sMsg_c90_s9_3      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 150, 20, 5, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c90_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg0  sMsg_c90_s10_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 11 -- */
static const CutsceneMsg4  sMsg_c90_s11_0     = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 3,               3, { 7008, 256, 6334, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c90_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c90_s12_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 23,              0 };
static const CutsceneMsg2  sMsg_c90_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c90_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const CutsceneMsg4  sMsg_c90_s13_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 150, 150, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c90_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg10 sMsg_c90_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c90_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg4  sMsg_c90_s15_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 1,               3, { 7424, 256, 6656, 0 } };
static const CutsceneMsg4  sMsg_c90_s15_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7168, 256, 6656, 0 } };
static const CutsceneMsg4  sMsg_c90_s15_3     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7552, 256, 6528, 0 } };
static const CutsceneMsg0  sMsg_c90_s15_4     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 39,              0 };
static const CutsceneMsg2  sMsg_c90_s15_5     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 304, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c90_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg4  sMsg_c90_s16_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7470, 406, 6794, 40 } };
static const CutsceneMsg2  sMsg_c90_s16_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c90_s16_3     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c90_s16_4     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c90_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c90_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c90_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c90_s19_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c90_s20_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 21 -- */
static const CutsceneMsg2  sMsg_c90_s21_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 22 -- */
static const CutsceneMsg0  sMsg_c90_s22_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const CutsceneMsg2  sMsg_c90_s23_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 24 -- */
static const CutsceneMsg2  sMsg_c90_s24_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 25 -- */
static const CutsceneMsg0  sMsg_c90_s25_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const CutsceneMsg2  sMsg_c90_s26_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 27 -- */
static const CutsceneMsg2  sMsg_c90_s27_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 28 -- */
static const CutsceneMsg0  sMsg_c90_s28_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const CutsceneMsg2  sMsg_c90_s29_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 30 -- */
static const CutsceneMsg2  sMsg_c90_s30_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c90_s30_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const CutsceneMsg2  sMsg_c90_s30_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 31 -- */
static const CutsceneMsg2  sMsg_c90_s31_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg6  sMsg_c90_s31_1     = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const CutsceneMsg2  sMsg_c90_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 32 -- */
static const CutsceneMsg2  sMsg_c90_s32_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 33 -- */
static const CutsceneMsg2  sMsg_c90_s33_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c90_s33_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const CutsceneMsg0  sMsg_c90_s33_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 34 -- */
static const CutsceneMsg2  sMsg_c90_s34_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const CutsceneMsg2  sMsg_c90_s34_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 35 -- */
static const CutsceneMsg2  sMsg_c90_s35_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 36 -- */
static const CutsceneMsg0  sMsg_c90_s36_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 37 -- */
static const CutsceneMsg2  sMsg_c90_s37_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c90_s37_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c90_s37_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 38 -- */
static const CutsceneMsg2  sMsg_c90_s38_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 39 -- */
static const CutsceneMsg0  sMsg_c90_s39_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const CutsceneMsg2  sMsg_c90_s40_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg0  sMsg_c90_s40_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const CutsceneMsg0  sMsg_c90_s40_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const CutsceneMsg2  sMsg_c90_s40_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 41 -- */
static const CutsceneMsg2  sMsg_c90_s41_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c90_s41_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c90_s41_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 42 -- */
static const CutsceneMsg2  sMsg_c90_s42_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13266, 0 } };
/* -- step 43 -- */
static const CutsceneMsg0  sMsg_c90_s43_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 44 -- */
static const CutsceneMsg2  sMsg_c90_s44_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg10 sMsg_c90_s44_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c90_s44_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 45 -- */
static const CutsceneMsg2  sMsg_c90_s45_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ cutscene 91  (46 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c91_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 7040, 256, 6784, 0 } };
static const CutsceneMsg2  sMsg_c91_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c91_s0_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7230, 406, 6734, 60 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c91_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c91_s1_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c91_s2_0      = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 24,              0 };
static const CutsceneMsg2  sMsg_c91_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 600, 0 } };
/* -- step 3 -- */
static const CutsceneMsg4  sMsg_c91_s3_0      = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 3,               3, { 7062, 256, 6334, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c91_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c91_s4_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c91_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c91_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c91_s6_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c91_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c91_s7_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const CutsceneMsg2  sMsg_c91_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 8 -- */
static const CutsceneMsg4  sMsg_c91_s8_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 7424, 256, 6784, 0 } };
static const CutsceneMsg6  sMsg_c91_s8_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 30, 20, 5, 0 } };
static const CutsceneMsg2  sMsg_c91_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
static const CutsceneMsg2  sMsg_c91_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 920, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c91_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const CutsceneMsg2  sMsg_c91_s9_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 38,              1, { 3, 0 } };
static const CutsceneMsg6  sMsg_c91_s9_2      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 150, 20, 5, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c91_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg0  sMsg_c91_s10_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 11 -- */
static const CutsceneMsg4  sMsg_c91_s11_0     = { TGT_ZAJI, CLS_ACTOR,  WAIT,   0, 3,               3, { 7008, 256, 6334, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c91_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c91_s12_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 23,              0 };
static const CutsceneMsg2  sMsg_c91_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 208, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c91_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const CutsceneMsg4  sMsg_c91_s13_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 150, 150, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c91_s14_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg10 sMsg_c91_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c91_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg4  sMsg_c91_s15_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 1,               3, { 7424, 256, 6656, 0 } };
static const CutsceneMsg4  sMsg_c91_s15_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 7168, 256, 6656, 0 } };
static const CutsceneMsg0  sMsg_c91_s15_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 39,              0 };
static const CutsceneMsg2  sMsg_c91_s15_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 304, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c91_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg4  sMsg_c91_s16_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7470, 406, 6794, 40 } };
static const CutsceneMsg2  sMsg_c91_s16_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c91_s16_3     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c91_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c91_s17_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c91_s18_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c91_s19_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c91_s20_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 21 -- */
static const CutsceneMsg2  sMsg_c91_s21_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 22 -- */
static const CutsceneMsg0  sMsg_c91_s22_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const CutsceneMsg2  sMsg_c91_s23_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 24 -- */
static const CutsceneMsg2  sMsg_c91_s24_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 25 -- */
static const CutsceneMsg0  sMsg_c91_s25_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const CutsceneMsg2  sMsg_c91_s26_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 27 -- */
static const CutsceneMsg2  sMsg_c91_s27_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 28 -- */
static const CutsceneMsg0  sMsg_c91_s28_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const CutsceneMsg2  sMsg_c91_s29_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 30 -- */
static const CutsceneMsg2  sMsg_c91_s30_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c91_s30_1     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const CutsceneMsg2  sMsg_c91_s30_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 31 -- */
static const CutsceneMsg2  sMsg_c91_s31_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg6  sMsg_c91_s31_1     = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const CutsceneMsg2  sMsg_c91_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 32 -- */
static const CutsceneMsg2  sMsg_c91_s32_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 33 -- */
static const CutsceneMsg2  sMsg_c91_s33_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c91_s33_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const CutsceneMsg0  sMsg_c91_s33_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 34 -- */
static const CutsceneMsg2  sMsg_c91_s34_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const CutsceneMsg2  sMsg_c91_s34_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 35 -- */
static const CutsceneMsg2  sMsg_c91_s35_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 36 -- */
static const CutsceneMsg0  sMsg_c91_s36_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 37 -- */
static const CutsceneMsg2  sMsg_c91_s37_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c91_s37_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c91_s37_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 38 -- */
static const CutsceneMsg2  sMsg_c91_s38_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 39 -- */
static const CutsceneMsg0  sMsg_c91_s39_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const CutsceneMsg2  sMsg_c91_s40_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg0  sMsg_c91_s40_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const CutsceneMsg0  sMsg_c91_s40_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const CutsceneMsg2  sMsg_c91_s40_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 41 -- */
static const CutsceneMsg2  sMsg_c91_s41_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c91_s41_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c91_s41_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 42 -- */
static const CutsceneMsg2  sMsg_c91_s42_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -13766, 0 } };
/* -- step 43 -- */
static const CutsceneMsg0  sMsg_c91_s43_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 44 -- */
static const CutsceneMsg2  sMsg_c91_s44_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg10 sMsg_c91_s44_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c91_s44_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 45 -- */
static const CutsceneMsg2  sMsg_c91_s45_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ cutscene 92  (21 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c92_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 7552, 256, 6784, 0 } };
static const CutsceneMsg4  sMsg_c92_s0_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 7570, 406, 6694, 40 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c92_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c92_s1_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c92_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c92_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c92_s3_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c92_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c92_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg0  sMsg_c92_s5_1      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const CutsceneMsg2  sMsg_c92_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c92_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg6  sMsg_c92_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 1,               5, { -2581, 128, 120, 20, 5, 0 } };
static const CutsceneMsg2  sMsg_c92_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c92_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c92_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c92_s8_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 7,               1, { 0, 0 } };
static const CutsceneMsg0  sMsg_c92_s8_2      = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c92_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const CutsceneMsg2  sMsg_c92_s9_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c92_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c92_s11_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c92_s12_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c92_s12_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c92_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c92_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 14 -- */
static const CutsceneMsg0  sMsg_c92_s14_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c92_s15_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg0  sMsg_c92_s15_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 9,               0 };
static const CutsceneMsg0  sMsg_c92_s15_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c92_s16_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c92_s16_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 7, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c92_s16_2     = { TGT_ZAJI, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c92_s17_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -14027, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c92_s18_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const CutsceneMsg2  sMsg_c92_s19_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg10 sMsg_c92_s19_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c92_s20_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* ================ cutscene 93  (14 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c93_s0_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c93_s0_1      = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c93_s0_2      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c93_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 512, 256, 512, 60 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c93_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c93_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c93_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c93_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c93_s6_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 640, 256, 896, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c93_s7_0      = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c93_s7_1      = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const CutsceneMsg2  sMsg_c93_s7_2      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c93_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c93_s9_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c93_s10_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c93_s10_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c93_s10_2     = { TGT_SUMIRE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c93_s11_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8953, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c93_s12_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c93_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c93_s13_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 0, 19,              0 };
/* ================ cutscene 94  (8 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c94_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 4992, 768, 2944, 0 } };
static const CutsceneMsg4  sMsg_c94_s0_1      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 4992, 768, 2816, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c94_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c94_s1_1      = { TGT_KID, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c94_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c94_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c94_s2_1      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c94_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12752, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c94_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c94_s5_0      = { TGT_KID, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c94_s6_0      = { TGT_KID, CLS_ACTOR,  WAIT,   3, 3,               3, { 4480, 768, 2944, 0 } };
static const CutsceneMsg2  sMsg_c94_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c94_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c94_s7_1      = { TGT_KID, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ cutscene 95  (8 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c95_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 4992, 768, 2944, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c95_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c95_s1_1      = { TGT_KID, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c95_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c95_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c95_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12948, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c95_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c95_s5_0      = { TGT_KID, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c95_s6_0      = { TGT_KID, CLS_ACTOR,  WAIT,   3, 3,               3, { 4480, 768, 2944, 0 } };
static const CutsceneMsg2  sMsg_c95_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c95_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c95_s7_1      = { TGT_KID, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ cutscene 96  (14 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c96_s0_0      = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 6784, 256, 2944, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c96_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c96_s1_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c96_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c96_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c96_s3_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c96_s4_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c96_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c96_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 7 -- */
static const CutsceneMsg0  sMsg_c96_s7_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c96_s8_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c96_s9_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 209, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c96_s10_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c96_s11_0     = { 0x8E9F, CLS_ACTOR,  WAIT,   3, 2,               1, { 1, 0 } };
/* -- step 12 -- */
static const CutsceneMsg4  sMsg_c96_s12_0     = { 0x8E9F, CLS_ACTOR,  WAIT,   3, 3,               3, { 6784, 256, 2432, 0 } };
static const CutsceneMsg2  sMsg_c96_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c96_s13_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c96_s13_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ cutscene 97  (8 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c97_s0_0      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2304, 768, 2304, 120 } };
static const CutsceneMsg4  sMsg_c97_s0_1      = { TGT_OTNK, CLS_ACTOR,  WAIT,   3, 3,               3, { 2304, 768, 2304, 0 } };
static const CutsceneMsg4  sMsg_c97_s0_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 6,               3, { 2304, 768, 2560, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c97_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c97_s1_1      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const CutsceneMsg2  sMsg_c97_s1_2      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c97_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 27732, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c97_s3_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c97_s4_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c97_s5_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c97_s5_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 349, 0 } };
static const CutsceneMsg2  sMsg_c97_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const CutsceneMsg0  sMsg_c97_s5_3      = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 3, 9,               0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c97_s6_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const CutsceneMsg10 sMsg_c97_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c97_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 608, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c97_s7_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const CutsceneMsg2  sMsg_c97_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 9, 0 } };
/* ================ cutscene 98  (3 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c98_s0_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg4  sMsg_c98_s0_1      = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 512, 4480, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c98_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3248, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c98_s2_0      = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 99  (5 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c99_s0_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c99_s0_1      = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c99_s1_0      = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c99_s1_1      = { 0x3436, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c99_s2_0      = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c99_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 3 -- */
static const CutsceneMsg4  sMsg_c99_s3_0      = { 0x3436, CLS_ACTOR,  WAIT,   0, 3,               3, { 3456, 1024, 2304, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c99_s4_0      = { 0x3436, CLS_ACTOR,  WAIT,   0, 0,               0 };
// clang-format on
