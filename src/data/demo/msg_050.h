// clang-format off
/* ================ demo 50  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d50_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d50_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25119, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d50_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d50_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d50_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d50_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 350, 0 } };
/* ================ demo 51  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d51_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d51_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25120, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d51_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d51_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d51_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d51_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 350, 0 } };
/* ================ demo 52  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d52_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d52_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25121, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d52_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d52_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d52_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d52_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 350, 0 } };
/* ================ demo 53  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d53_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d53_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25122, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d53_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d53_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg0  sMsg_d53_s3_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
static const DemoMsg2  sMsg_d53_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 728, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d53_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d53_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d53_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg0  sMsg_d53_s5_1      = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 1,               0 };
static const DemoMsg2  sMsg_d53_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 805, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d53_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d53_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d53_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d53_s6_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* ================ demo 54  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d54_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d54_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 110, 0 } };
/* -- step 1 -- */
static const DemoMsg0  sMsg_d54_s1_0      = { 0xD37F, CLS_BOSS,   WAIT,   0, 44,              0 };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d54_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 32408, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d54_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 55  (56 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d55_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d55_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 926, 768, 1408, 0 } };
static const DemoMsg4  sMsg_d55_s0_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 1182, 768, 1408, 0 } };
static const DemoMsg2  sMsg_d55_s0_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d55_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d55_s1_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d55_s2_0      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
static const DemoMsg4  sMsg_d55_s2_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1152, 768, 1664, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d55_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d55_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 74, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d55_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d55_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d55_s6_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   3, 18,              1, { 1, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d55_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d55_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d55_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d55_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d55_s11_0     = { 0x3DB5, CLS_ACTOR,  WAIT,   3, 11,              1, { 1, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d55_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d55_s13_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d55_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d55_s15_0     = { 0x3DB5, CLS_ACTOR,  WAIT,   3, 1,               1, { 1, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d55_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d55_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d55_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s18_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d55_s18_2     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 3, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d55_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d55_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d55_s21_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s21_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d55_s21_2     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 5, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d55_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 23 -- */
static const DemoMsg0  sMsg_d55_s23_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d55_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s24_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 18,              1, { 1, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d55_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d55_s26_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d55_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s27_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 19,              1, { 1, 0 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d55_s28_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 29 -- */
static const DemoMsg0  sMsg_d55_s29_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d55_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d55_s30_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 13,              0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d55_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 32 -- */
static const DemoMsg0  sMsg_d55_s32_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d55_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d55_s33_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 1,               1, { 1, 0 } };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d55_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d55_s35_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 36 -- */
static const DemoMsg4  sMsg_d55_s36_0     = { 0x3DB5, CLS_ACTOR,  WAIT,   3, 3,               3, { 1024, 768, 3128, 0 } };
static const DemoMsg2  sMsg_d55_s36_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 37 -- */
static const DemoMsg0  sMsg_d55_s37_0     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
static const DemoMsg2  sMsg_d55_s37_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 156, 0 } };
static const DemoMsg4  sMsg_d55_s37_2     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1024, 768, 1536, 60 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d55_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 39 -- */
static const DemoMsg0  sMsg_d55_s39_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d55_s40_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d55_s41_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 42 -- */
static const DemoMsg0  sMsg_d55_s42_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 43 -- */
static const DemoMsg2  sMsg_d55_s43_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d55_s44_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 45 -- */
static const DemoMsg0  sMsg_d55_s45_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 46 -- */
static const DemoMsg2  sMsg_d55_s46_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d55_s46_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 47 -- */
static const DemoMsg2  sMsg_d55_s47_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 48 -- */
static const DemoMsg0  sMsg_d55_s48_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 49 -- */
static const DemoMsg2  sMsg_d55_s49_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 50 -- */
static const DemoMsg0  sMsg_d55_s50_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 51 -- */
static const DemoMsg2  sMsg_d55_s51_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 52 -- */
static const DemoMsg2  sMsg_d55_s52_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d55_s52_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 130, 130, 0 } };
static const DemoMsg4  sMsg_d55_s52_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 10,              3, { 4, 130, 130, 0 } };
/* -- step 53 -- */
static const DemoMsg2  sMsg_d55_s53_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d55_s53_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 54 -- */
static const DemoMsg2  sMsg_d55_s54_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29216, 0 } };
/* -- step 55 -- */
static const DemoMsg0  sMsg_d55_s55_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 56  (63 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d56_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4736, 768, 1664, 0 } };
static const DemoMsg4  sMsg_d56_s0_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4864, 768, 1600, 45 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d56_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d56_s1_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s1_2      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d56_s1_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d56_s1_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d56_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d56_s2_1      = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 4736, 768, 1280, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d56_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d56_s3_1      = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d56_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d56_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d56_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2688, 1024, 1408, 60 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d56_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d56_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d56_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4864, 768, 1600, 60 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d56_s10_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 7,               1, { 0, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d56_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d56_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d56_s13_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 9,               0 };
/* -- step 14 -- */
static const DemoMsg4  sMsg_d56_s14_0     = { 0x9CFE, CLS_ACTOR,  WAIT,   3, 3,               3, { 4928, 768, 1664, 0 } };
static const DemoMsg2  sMsg_d56_s14_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d56_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg2  sMsg_d56_s15_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d56_s15_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d56_s15_3     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 0, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d56_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d56_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d56_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d56_s18_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d56_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d56_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d56_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d56_s21_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 56, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d56_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 23 -- */
static const DemoMsg0  sMsg_d56_s23_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d56_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d56_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d56_s26_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d56_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s27_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d56_s28_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 29 -- */
static const DemoMsg0  sMsg_d56_s29_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d56_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d56_s30_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d56_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d56_s31_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 10,              3, { 4, 140, 140, 0 } };
static const DemoMsg2  sMsg_d56_s31_2     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d56_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg2  sMsg_d56_s32_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s32_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d56_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s33_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 66, 0 } };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d56_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d56_s35_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d56_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg2  sMsg_d56_s36_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d56_s36_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d56_s37_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 38 -- */
static const DemoMsg0  sMsg_d56_s38_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 39 -- */
static const DemoMsg2  sMsg_d56_s39_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d56_s39_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d56_s39_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d56_s40_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 41 -- */
static const DemoMsg0  sMsg_d56_s41_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 42 -- */
static const DemoMsg2  sMsg_d56_s42_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d56_s42_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d56_s42_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 43 -- */
static const DemoMsg2  sMsg_d56_s43_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 44 -- */
static const DemoMsg0  sMsg_d56_s44_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 45 -- */
static const DemoMsg4  sMsg_d56_s45_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 4928, 768, 1408, 0 } };
static const DemoMsg2  sMsg_d56_s45_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 46 -- */
static const DemoMsg2  sMsg_d56_s46_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d56_s46_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d56_s46_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 2, 0 } };
static const DemoMsg2  sMsg_d56_s46_3     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d56_s46_4     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 47 -- */
static const DemoMsg2  sMsg_d56_s47_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 48 -- */
static const DemoMsg0  sMsg_d56_s48_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 49 -- */
static const DemoMsg2  sMsg_d56_s49_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d56_s49_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d56_s49_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 50 -- */
static const DemoMsg2  sMsg_d56_s50_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 51 -- */
static const DemoMsg0  sMsg_d56_s51_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 52 -- */
static const DemoMsg2  sMsg_d56_s52_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d56_s52_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d56_s52_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 53 -- */
static const DemoMsg2  sMsg_d56_s53_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 54 -- */
static const DemoMsg0  sMsg_d56_s54_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 55 -- */
static const DemoMsg2  sMsg_d56_s55_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d56_s55_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 43,              1, { 2, 0 } };
/* -- step 56 -- */
static const DemoMsg2  sMsg_d56_s56_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 57 -- */
static const DemoMsg0  sMsg_d56_s57_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 58 -- */
static const DemoMsg0  sMsg_d56_s58_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 9,               0 };
/* -- step 59 -- */
static const DemoMsg2  sMsg_d56_s59_0     = { 0xF5EB, CLS_PLAYER, WAIT,   3, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d56_s59_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d56_s59_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg0  sMsg_d56_s59_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 44,              0 };
/* -- step 60 -- */
static const DemoMsg2  sMsg_d56_s60_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31478, 0 } };
/* -- step 61 -- */
static const DemoMsg0  sMsg_d56_s61_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 62 -- */
static const DemoMsg2  sMsg_d56_s62_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const DemoMsg2  sMsg_d56_s62_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 156, 0 } };
/* ================ demo 57  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d57_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 1120, 768, 2368, 0 } };
static const DemoMsg4  sMsg_d57_s0_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 928, 768, 2368, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d57_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d57_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d57_s1_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d57_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -15774, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d57_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 58  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d58_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 6016, 256, 2688, 0 } };
static const DemoMsg4  sMsg_d58_s0_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 6144, 256, 2688, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d58_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d58_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d58_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d58_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d58_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d58_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19269, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d58_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d58_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d58_s5_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d58_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d58_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 655, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d58_s7_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d58_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -19269, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d58_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg4  sMsg_d58_s10_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2048, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d58_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d58_s11_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 59  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d59_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 6016, 256, 2688, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d59_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d59_s1_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d59_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d59_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d59_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4748, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d59_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d59_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d59_s5_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d59_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d59_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 655, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d59_s7_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d59_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4748, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d59_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg4  sMsg_d59_s10_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2048, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d59_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d59_s11_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 60  (3 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d60_s0_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2432, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d60_s1_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2048, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d60_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d60_s2_1      = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 61  (3 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d61_s0_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2432, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d61_s1_0      = { 0x29A0, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2048, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d61_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d61_s2_1      = { 0x29A0, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* ================ demo 62  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d62_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d62_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 110, 0 } };
static const DemoMsg2  sMsg_d62_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 794, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d62_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d62_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d62_s2_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d62_s2_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d62_s2_4      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d62_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d62_s3_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d62_s3_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d62_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg4  sMsg_d62_s4_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
static const DemoMsg4  sMsg_d62_s4_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d62_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg4  sMsg_d62_s5_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 2304, 768, 3840, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d62_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg4  sMsg_d62_s6_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 2304, 768, 3840, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d62_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d62_s7_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 4, 4, 4, 1, 1, 1, 0, 0 } };
/* ================ demo 63  (48 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d63_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d63_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 6016, 256, 2944, 0 } };
static const DemoMsg4  sMsg_d63_s0_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 6016, 256, 2816, 0 } };
static const DemoMsg4  sMsg_d63_s0_3      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 5952, 256, 3008, 30 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d63_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d63_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d63_s1_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d63_s2_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2848, 0 } };
static const DemoMsg2  sMsg_d63_s2_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d63_s3_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d63_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d63_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d63_s6_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 5760, 256, 2816, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d63_s7_0      = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d63_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d63_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d63_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d63_s10_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 37,              0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d63_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d63_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d63_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s13_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 1,               1, { 3, 0 } };
/* -- step 14 -- */
static const DemoMsg4  sMsg_d63_s14_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 5632, 256, 2848, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d63_s15_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s15_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d63_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d63_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d63_s18_0     = { 0x6740, CLS_ACTOR,  WAIT,   3, 3,               3, { 5504, 256, 2944, 0 } };
static const DemoMsg4  sMsg_d63_s18_1     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 5760, 256, 2432, 0 } };
/* -- step 19 -- */
static const DemoMsg4  sMsg_d63_s19_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 5760, 256, 2432, 0 } };
static const DemoMsg2  sMsg_d63_s19_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
static const DemoMsg0  sMsg_d63_s19_2     = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* -- step 20 -- */
static const DemoMsg4  sMsg_d63_s20_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2432, 0 } };
static const DemoMsg2  sMsg_d63_s20_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d63_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d63_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d63_s23_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 5, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d63_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg2  sMsg_d63_s24_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d63_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d63_s25_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 4,               0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d63_s26_0     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s26_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d63_s26_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg4  sMsg_d63_s26_3     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 6144, 256, 3072, 20 } };
static const DemoMsg2  sMsg_d63_s26_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d63_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 28 -- */
static const DemoMsg0  sMsg_d63_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d63_s29_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 2,               1, { 1, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d63_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 31 -- */
static const DemoMsg0  sMsg_d63_s31_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 32 -- */
static const DemoMsg4  sMsg_d63_s32_0     = { 0x6773, CLS_ACTOR,  WAIT,   3, 3,               3, { 6016, 256, 2176, 0 } };
static const DemoMsg2  sMsg_d63_s32_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 603, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d63_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg2  sMsg_d63_s33_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg0  sMsg_d63_s33_2     = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d63_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d63_s35_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d63_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d63_s36_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 4,               0 };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d63_s37_0     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d63_s37_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d63_s37_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg4  sMsg_d63_s37_3     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 6144, 256, 3072, 20 } };
static const DemoMsg2  sMsg_d63_s37_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 59, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d63_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 39 -- */
static const DemoMsg0  sMsg_d63_s39_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const DemoMsg4  sMsg_d63_s40_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 9088, 768, 1792, 60 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d63_s41_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 42 -- */
static const DemoMsg0  sMsg_d63_s42_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 43 -- */
static const DemoMsg4  sMsg_d63_s43_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 6144, 256, 3072, 60 } };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d63_s44_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27631, 0 } };
/* -- step 45 -- */
static const DemoMsg0  sMsg_d63_s45_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 46 -- */
static const DemoMsg4  sMsg_d63_s46_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   3, 3,               3, { 7040, 256, 2688, 0 } };
static const DemoMsg2  sMsg_d63_s46_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d63_s46_2     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 5,               1, { 60, 0 } };
/* -- step 47 -- */
static const DemoMsg0  sMsg_d63_s47_0     = { 0x6DAD, CLS_ACTOR,  WAIT,   3, 0,               0 };
static const DemoMsg2  sMsg_d63_s47_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 156, 0 } };
/* ================ demo 64  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d64_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d64_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 14,              1, { 7, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d64_s1_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   3, 3,               3, { 8576, 768, 1664, 0 } };
static const DemoMsg4  sMsg_d64_s1_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 8576, 768, 1920, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d64_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3279, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d64_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d64_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d64_s4_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 4, 4, 4, 1, 1, 1, 0, 0 } };
/* ================ demo 65  (17 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d65_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d65_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 3072, 768, 2688, 60 } };
static const DemoMsg2  sMsg_d65_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 65, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d65_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -26995, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d65_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d65_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d65_s4_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d65_s4_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d65_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -26995, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d65_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d65_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d65_s7_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d65_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -26995, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d65_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d65_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d65_s10_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 15,              1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d65_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -26995, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d65_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d65_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d65_s13_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 1,               1, { 5, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d65_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d65_s14_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d65_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d65_s15_1     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 13,              1, { 7, 0 } };
static const DemoMsg2  sMsg_d65_s15_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d65_s16_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
static const DemoMsg2  sMsg_d65_s16_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
/* ================ demo 66  (13 steps) ================ */
/* -- step 0 -- */
static const DemoMsg0  sMsg_d66_s0_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 27,              0 };
static const DemoMsg4  sMsg_d66_s0_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2432, 768, 2432, 45 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d66_s1_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   0, 3,               3, { 2560, 768, 2304, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d66_s2_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   0, 2,               1, { 7, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d66_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -12317, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d66_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d66_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d66_s5_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 18,              2, { 3, 0 } };
static const DemoMsg2  sMsg_d66_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 746, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d66_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d66_s6_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d66_s6_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d66_s6_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d66_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d66_s7_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 10,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d66_s7_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d66_s7_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d66_s7_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 76, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d66_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -12317, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d66_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d66_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 330, 0 } };
static const DemoMsg10 sMsg_d66_s10_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 2,               9, { 1, 8, 0, 0, 0, 1, 1, 0, 64, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d66_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -12317, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d66_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 67  (13 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d67_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d67_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d67_s1_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d67_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d67_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 8128, 256, 6720, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d67_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d67_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg4  sMsg_d67_s3_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 41,              3, { 8320, 256, 5406, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d67_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3103, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d67_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d67_s6_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   0, 3,               3, { 8320, 256, 6528, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d67_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d67_s7_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d67_s7_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d67_s7_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 2, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d67_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3103, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d67_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d67_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d67_s10_1     = { 0x6DAD, CLS_ACTOR,  NOWAIT, 3, 11,              0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d67_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -3103, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d67_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 68  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d68_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d68_s0_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 4,               0 };
static const DemoMsg4  sMsg_d68_s0_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 3968, 768, 3200, 50 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d68_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27383, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d68_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d68_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d68_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27383, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d68_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d68_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d68_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27383, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d68_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d68_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d68_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27383, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d68_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 69  (22 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d69_s0_0      = { 0x74E2, CLS_SOUND,  WAIT,   0, 2,               1, { 80, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d69_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d69_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d69_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d69_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d69_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d69_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d69_s6_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 1, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d69_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d69_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 10,              1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d69_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d69_s8_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 33,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d69_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d69_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d69_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d69_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d69_s11_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 34,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d69_s11_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d69_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d69_s12_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 12,              1, { 1, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d69_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d69_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d69_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d69_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d69_s15_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d69_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d69_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d69_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d69_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17777, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d69_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d69_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
/* ================ demo 70  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d70_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d70_s0_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 4, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d70_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg10 sMsg_d70_s1_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 7, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg4  sMsg_d70_s1_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1792, 256, 3840, 60 } };
static const DemoMsg0  sMsg_d70_s1_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 40,              0 };
static const DemoMsg2  sMsg_d70_s1_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 957, 0 } };
static const DemoMsg2  sMsg_d70_s1_5      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d70_s1_6      = { 0xCBB0, CLS_CBB0,   NOWAIT, 0, 0,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d70_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d70_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d70_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 18,              2, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d70_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d70_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 76, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d70_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 26682, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d70_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d70_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d70_s7_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 4, 4, 4, 1, 1, 1, 0, 0 } };
static const DemoMsg0  sMsg_d70_s7_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 41,              0 };
static const DemoMsg2  sMsg_d70_s7_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 42,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d70_s7_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 4, 0 } };
/* ================ demo 71  (16 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d71_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg2  sMsg_d71_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 82, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d71_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 30673, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d71_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d71_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d71_s3_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 37,              0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d71_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 30673, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d71_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d71_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d71_s6_1      = { 0x6773, CLS_ACTOR,  NOWAIT, 3, 1,               1, { 3, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d71_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 30673, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d71_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d71_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d71_s9_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 3, 13,              0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d71_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 30673, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d71_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d71_s12_0     = { 0x2B06, CLS_PLAYER, WAIT,   0, 35,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d71_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 742, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d71_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 30673, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d71_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d71_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d71_s15_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 10, 0 } };
/* ================ demo 72  (26 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d72_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d72_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d72_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d72_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d72_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d72_s3_2      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d72_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d72_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d72_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d72_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 7, 0,               7, { 768, 704, 1792, 128, 120, 20, 7, 0 } };
static const DemoMsg2  sMsg_d72_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d72_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d72_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d72_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg8  sMsg_d72_s9_1      = { 0x730A, CLS_FADE,   NOWAIT, 5, 0,               7, { 1024, 704, 1792, 128, 120, 20, 7, 0 } };
static const DemoMsg2  sMsg_d72_s9_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 668, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d72_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d72_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d72_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d72_s12_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d72_s12_2     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
static const DemoMsg2  sMsg_d72_s12_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d72_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d72_s13_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 291, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d72_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d72_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d72_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d72_s16_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 5, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d72_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d72_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d72_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d72_s19_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 9,               0 };
static const DemoMsg0  sMsg_d72_s19_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d72_s19_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 159, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d72_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d72_s20_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d72_s20_2     = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d72_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27368, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d72_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d72_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg2  sMsg_d72_s23_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 4,               1, { 7, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d72_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg2  sMsg_d72_s24_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d72_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d72_s25_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* ================ demo 73  (17 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d73_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d73_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16312, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d73_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d73_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d73_s3_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 11,              0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d73_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16312, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d73_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d73_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d73_s6_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 12,              0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d73_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16312, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d73_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d73_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d73_s9_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d73_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16312, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d73_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d73_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d73_s12_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 19,              0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d73_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d73_s13_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 0, 64, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d73_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -16312, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d73_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d73_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* ================ demo 74  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d74_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg0  sMsg_d74_s0_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 4,               0 };
static const DemoMsg4  sMsg_d74_s0_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2540, 918, 2720, 60 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d74_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d74_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d74_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d74_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 66, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d74_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31339, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d74_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d74_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d74_s5_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
// clang-format on
