// clang-format off
/* ================ demo 0  (13 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d0_s0_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15787, 0 } };
static const DemoMsg2  sMsg_d0_s0_1       = { 0x1E18, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d0_s0_2       = { 0x1E19, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 192, 0 } };
static const DemoMsg2  sMsg_d0_s0_3       = { 0x1E1A, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d0_s1_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d0_s1_1       = { 0x3EE7, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d0_s2_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d0_s2_1       = { 0x3EE7, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1400, 1024, 7000, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d0_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d0_s3_1       = { 0x1E18, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 64, 0 } };
static const DemoMsg2  sMsg_d0_s3_2       = { 0x1E19, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 64, 0 } };
static const DemoMsg2  sMsg_d0_s3_3       = { 0x1E1A, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 64, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d0_s4_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d0_s4_1       = { 0x3EE7, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 128, 0 } };
static const DemoMsg4  sMsg_d0_s4_2       = { 0x1E18, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 896, 1024, 7500, 0 } };
static const DemoMsg4  sMsg_d0_s4_3       = { 0x1E19, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1024, 1024, 7600, 0 } };
static const DemoMsg4  sMsg_d0_s4_4       = { 0x1E1A, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1152, 1024, 7500, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d0_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d0_s5_1       = { 0x3EE7, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 64, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d0_s6_0       = { 0x3EE7, CLS_ACTOR,  WAIT,   0, 3,               3, { 1024, 1024, 7000, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d0_s7_0       = { 0x3EE7, CLS_ACTOR,  WAIT,   0, 2,               1, { 192, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d0_s8_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg4  sMsg_d0_s8_1       = { 0x3EE7, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1024, 1024, 3000, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d0_s9_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d0_s9_1       = { 0x1E18, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 128, 0 } };
static const DemoMsg2  sMsg_d0_s9_2       = { 0x1E19, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 192, 0 } };
static const DemoMsg2  sMsg_d0_s9_3       = { 0x1E1A, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 0, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d0_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 240, 0 } };
static const DemoMsg4  sMsg_d0_s10_1      = { 0x1E18, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 896, 1024, 5000, 0 } };
static const DemoMsg4  sMsg_d0_s10_2      = { 0x1E19, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1024, 1024, 4900, 0 } };
static const DemoMsg4  sMsg_d0_s10_3      = { 0x1E1A, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1152, 1024, 5000, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d0_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 600, 0 } };
static const DemoMsg2  sMsg_d0_s11_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d0_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d0_s12_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 8, 0 } };
static const DemoMsg2  sMsg_d0_s12_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 88, 0 } };
/* ================ demo 1  (65 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d1_s0_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d1_s0_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 4224, 512, 1664, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d1_s1_0       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1664, 0 } };
static const DemoMsg2  sMsg_d1_s1_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d1_s2_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1408, 60 } };
static const DemoMsg2  sMsg_d1_s2_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d1_s2_2       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 1, 6,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d1_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d1_s3_1       = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 9,               1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d1_s4_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d1_s4_1       = { 0xBA4B, CLS_BOSS,   WAIT,   0, 5,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d1_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d1_s6_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d1_s7_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d1_s7_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d1_s8_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d1_s9_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d1_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d1_s10_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 62, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d1_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s11_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 9,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d1_s11_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d1_s11_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d1_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d1_s12_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 11,              0 };
static const DemoMsg2  sMsg_d1_s12_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d1_s12_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d1_s12_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 835, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d1_s13_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s13_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d1_s13_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d1_s14_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s14_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d1_s14_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d1_s15_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d1_s15_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d1_s15_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d1_s16_0      = { 0x74E2, CLS_SOUND,  WAIT,   3, 0,               1, { 857, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d1_s17_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d1_s18_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d1_s19_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d1_s19_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 22,              1, { 1, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d1_s20_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 21 -- */
static const DemoMsg0  sMsg_d1_s21_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 22 -- */
static const DemoMsg4  sMsg_d1_s22_0      = { 0xBA4B, CLS_BOSS,   WAIT,   0, 13,              3, { 4224, 512, 1408, 0 } };
static const DemoMsg2  sMsg_d1_s22_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d1_s22_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 860, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d1_s23_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d1_s23_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 14,              1, { 0, 0 } };
/* -- step 24 -- */
static const DemoMsg4  sMsg_d1_s24_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 48, 1, 0 } };
static const DemoMsg4  sMsg_d1_s24_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1792, 30 } };
static const DemoMsg2  sMsg_d1_s24_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d1_s24_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d1_s25_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d1_s25_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 16,              1, { 5, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d1_s26_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d1_s26_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 503, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d1_s27_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 28 -- */
static const DemoMsg0  sMsg_d1_s28_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 29 -- */
static const DemoMsg0  sMsg_d1_s29_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 17,              0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d1_s30_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d1_s30_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 17,              1, { 13, 0 } };
static const DemoMsg2  sMsg_d1_s30_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 31 -- */
static const DemoMsg4  sMsg_d1_s31_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 48, 1, 0 } };
static const DemoMsg2  sMsg_d1_s31_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 230, 0 } };
static const DemoMsg2  sMsg_d1_s31_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 772, 0 } };
static const DemoMsg4  sMsg_d1_s31_3      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 2048, 30 } };
static const DemoMsg2  sMsg_d1_s31_4      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d1_s32_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 33 -- */
static const DemoMsg0  sMsg_d1_s33_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d1_s34_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d1_s34_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 2, 0 } };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d1_s35_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 36 -- */
static const DemoMsg0  sMsg_d1_s36_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d1_s37_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d1_s37_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1792, 60 } };
static const DemoMsg2  sMsg_d1_s37_2      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 18,              1, { 0, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d1_s38_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d1_s38_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 3, 0 } };
/* -- step 39 -- */
static const DemoMsg2  sMsg_d1_s39_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d1_s39_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 13,              3, { 4224, 512, 800, 0 } };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d1_s40_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s40_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d1_s41_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d1_s41_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg0  sMsg_d1_s41_2      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 0,               0 };
/* -- step 42 -- */
static const DemoMsg4  sMsg_d1_s42_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 2048, 60 } };
static const DemoMsg0  sMsg_d1_s42_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 17,              0 };
/* -- step 43 -- */
static const DemoMsg2  sMsg_d1_s43_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 44 -- */
static const DemoMsg0  sMsg_d1_s44_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 45 -- */
static const DemoMsg2  sMsg_d1_s45_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 10,              1, { 1, 0 } };
/* -- step 46 -- */
static const DemoMsg2  sMsg_d1_s46_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d1_s46_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 130, 130, 0 } };
static const DemoMsg2  sMsg_d1_s46_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
/* -- step 47 -- */
static const DemoMsg2  sMsg_d1_s47_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d1_s47_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 57, 0 } };
/* -- step 48 -- */
static const DemoMsg2  sMsg_d1_s48_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 49 -- */
static const DemoMsg0  sMsg_d1_s49_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 50 -- */
static const DemoMsg2  sMsg_d1_s50_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d1_s50_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 12,              1, { 1, 0 } };
/* -- step 51 -- */
static const DemoMsg2  sMsg_d1_s51_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s51_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 1, 0 } };
/* -- step 52 -- */
static const DemoMsg2  sMsg_d1_s52_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d1_s52_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 53 -- */
static const DemoMsg2  sMsg_d1_s53_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 54 -- */
static const DemoMsg0  sMsg_d1_s54_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 55 -- */
static const DemoMsg2  sMsg_d1_s55_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d1_s55_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* -- step 56 -- */
static const DemoMsg2  sMsg_d1_s56_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d1_s56_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 780, 0 } };
static const DemoMsg4  sMsg_d1_s56_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 4096, 512, 780, 0 } };
/* -- step 57 -- */
static const DemoMsg2  sMsg_d1_s57_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d1_s57_1      = { 0x730A, CLS_FADE,   NOWAIT, 9, 3,               8, { 1, 6, 0, 0, 0, 1, 1, 0 } };
static const DemoMsg0  sMsg_d1_s57_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg0  sMsg_d1_s57_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
/* -- step 58 -- */
static const DemoMsg4  sMsg_d1_s58_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4354, 512, 1664, 80 } };
static const DemoMsg2  sMsg_d1_s58_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 62, 0 } };
static const DemoMsg2  sMsg_d1_s58_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* -- step 59 -- */
static const DemoMsg2  sMsg_d1_s59_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 60 -- */
static const DemoMsg2  sMsg_d1_s60_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d1_s60_1      = { 0x7901, CLS_ACTOR,  NOWAIT, 0, 4,               0 };
/* -- step 61 -- */
static const DemoMsg2  sMsg_d1_s61_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d1_s61_1      = { 0x9386, CLS_BOSS,   WAIT,   0, 7,               0 };
/* -- step 62 -- */
static const DemoMsg2  sMsg_d1_s62_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 63 -- */
static const DemoMsg0  sMsg_d1_s63_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 64 -- */
static const DemoMsg2  sMsg_d1_s64_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg2  sMsg_d1_s64_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
static const DemoMsg6  sMsg_d1_s64_2      = { 0x730A, CLS_FADE,   NOWAIT, 9, 4,               6, { 1, 7, 0, 0, 0, 1 } };
/* ================ demo 2  (45 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d2_s0_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d2_s0_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1664, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d2_s1_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d2_s1_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d2_s2_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1408, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d2_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d2_s3_1       = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 9,               1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d2_s4_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d2_s4_1       = { 0xBA4B, CLS_BOSS,   WAIT,   0, 5,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d2_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d2_s6_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d2_s7_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d2_s7_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d2_s8_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d2_s9_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d2_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d2_s10_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 9,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d2_s10_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d2_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d2_s11_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 11,              0 };
static const DemoMsg2  sMsg_d2_s11_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d2_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d2_s12_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d2_s13_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d2_s13_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d2_s14_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d2_s14_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d2_s15_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d2_s16_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d2_s17_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d2_s17_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d2_s18_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d2_s19_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg4  sMsg_d2_s20_0      = { 0xBA4B, CLS_BOSS,   WAIT,   0, 12,              3, { 4224, 512, 1408, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d2_s21_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d2_s21_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 14,              1, { 0, 0 } };
/* -- step 22 -- */
static const DemoMsg4  sMsg_d2_s22_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 48, 1, 0 } };
static const DemoMsg4  sMsg_d2_s22_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1792, 30 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d2_s23_0      = { 0xBA4B, CLS_BOSS,   WAIT,   0, 16,              1, { 5, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d2_s24_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 25 -- */
static const DemoMsg0  sMsg_d2_s25_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d2_s26_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 17,              0 };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d2_s27_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d2_s27_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 17,              1, { 0, 0 } };
/* -- step 28 -- */
static const DemoMsg4  sMsg_d2_s28_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 1, 48, 1, 0 } };
static const DemoMsg4  sMsg_d2_s28_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 2048, 30 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d2_s29_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 30 -- */
static const DemoMsg0  sMsg_d2_s30_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d2_s31_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d2_s31_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1792, 60 } };
static const DemoMsg2  sMsg_d2_s31_2      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 18,              1, { 0, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d2_s32_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d2_s32_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 12,              3, { 4224, 512, 0, 0 } };
/* -- step 33 -- */
static const DemoMsg4  sMsg_d2_s33_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 2048, 60 } };
static const DemoMsg0  sMsg_d2_s33_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 17,              0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d2_s34_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d2_s35_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d2_s36_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 10,              1, { 1, 0 } };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d2_s37_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d2_s37_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 0, 120, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d2_s38_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 39 -- */
static const DemoMsg0  sMsg_d2_s39_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d2_s40_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d2_s40_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 12,              1, { 1, 0 } };
/* -- step 41 -- */
static const DemoMsg2  sMsg_d2_s41_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d2_s41_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 1, 0 } };
/* -- step 42 -- */
static const DemoMsg2  sMsg_d2_s42_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 3374, 0 } };
/* -- step 43 -- */
static const DemoMsg0  sMsg_d2_s43_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 44 -- */
static const DemoMsg2  sMsg_d2_s44_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d2_s44_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 896, 0 } };
/* ================ demo 3  (25 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d3_s0_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d3_s0_1       = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 4,               0 };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d3_s1_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d3_s1_1       = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d3_s1_2       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d3_s2_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d3_s2_1       = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 8, 0 } };
static const DemoMsg2  sMsg_d3_s2_2       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 8, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d3_s3_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d3_s3_1       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1094, 1024, 2490, 30 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d3_s4_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d3_s4_1       = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d3_s4_2       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d3_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d3_s6_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d3_s7_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
static const DemoMsg0  sMsg_d3_s7_1       = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d3_s8_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d3_s9_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
static const DemoMsg0  sMsg_d3_s9_1       = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d3_s10_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d3_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 110, 0 } };
static const DemoMsg4  sMsg_d3_s11_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               3, { 4, 120, 120, 0 } };
static const DemoMsg4  sMsg_d3_s11_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
static const DemoMsg4  sMsg_d3_s11_3      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 120, 120, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d3_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d3_s12_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 8, 0 } };
static const DemoMsg2  sMsg_d3_s12_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 8, 0 } };
static const DemoMsg2  sMsg_d3_s12_3      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 8, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d3_s13_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d3_s14_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d3_s15_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
static const DemoMsg0  sMsg_d3_s15_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d3_s16_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d3_s17_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19358, 0 } };
static const DemoMsg0  sMsg_d3_s17_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 17,              0 };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d3_s18_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d3_s19_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 48, 0 } };
static const DemoMsg0  sMsg_d3_s19_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 16,              0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d3_s20_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d3_s20_1      = { 0x6DAD, CLS_ACTOR,  NOWAIT, 0, 5,               0 };
static const DemoMsg2  sMsg_d3_s20_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 2, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d3_s21_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 110, 0 } };
static const DemoMsg4  sMsg_d3_s21_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               3, { 4, 120, 120, 0 } };
static const DemoMsg4  sMsg_d3_s21_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d3_s22_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d3_s22_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 8, 0 } };
static const DemoMsg2  sMsg_d3_s22_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 8, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d3_s23_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d3_s23_1      = { 0x6A20, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d3_s23_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d3_s24_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d3_s24_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 1, 0 } };
/* ================ demo 4  (16 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d4_s0_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d4_s0_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 512, 4736, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d4_s1_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d4_s1_1       = { 0x9CFE, CLS_ACTOR,  WAIT,   1, 6,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d4_s2_0       = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d4_s2_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d4_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d4_s4_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2944, 768, 1408, 120 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d4_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d4_s5_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 68, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d4_s6_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d4_s6_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d4_s7_0       = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 2944, 768, 1152, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d4_s8_0       = { 0x51E2, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d4_s9_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d4_s10_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 120, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d4_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d4_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 9879, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d4_s13_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d4_s14_0      = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 7,               0 };
static const DemoMsg2  sMsg_d4_s14_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d4_s15_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d4_s15_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 20, 0 } };
/* ================ demo 5  (16 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d5_s0_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d5_s0_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2432, 512, 6272, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d5_s1_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d5_s1_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d5_s2_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d5_s2_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d5_s2_2       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d5_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d5_s4_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1920, 512, 4992, 50 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d5_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d5_s5_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 68, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d5_s6_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d5_s6_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d5_s7_0       = { 0x51E2, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d5_s8_0       = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 1920, 512, 5120, 0 } };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d5_s9_0       = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 1920, 256, 5376, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d5_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg0  sMsg_d5_s10_1      = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d5_s11_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 19833, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d5_s12_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d5_s13_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg4  sMsg_d5_s13_1      = { 0x45E5, CLS_ENEMY,  NOWAIT, 0, 3,               3, { 4, 130, 130, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d5_s14_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d5_s14_1      = { 0x45E5, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d5_s14_2      = { 0x45E5, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d5_s15_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* ================ demo 6  (17 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d6_s0_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d6_s0_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1664, 256, 2688, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d6_s1_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d6_s2_0       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d6_s2_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d6_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d6_s4_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1664, 256, 896, 80 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d6_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d6_s5_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 68, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d6_s6_0       = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 1664, 256, 384, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d6_s7_0       = { 0x51E2, CLS_ACTOR,  WAIT,   0, 0,               0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d6_s8_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1408, 256, 2176, 60 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d6_s9_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg4  sMsg_d6_s9_1       = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1152, 256, 2432, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d6_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -1763, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d6_s11_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d6_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d6_s12_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d6_s12_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 2, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d6_s13_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d6_s13_1      = { 0x2B18, CLS_BOSS,   WAIT,   0, 7,               0 };
static const DemoMsg2  sMsg_d6_s13_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 69, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d6_s14_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -1763, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d6_s15_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d6_s16_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d6_s16_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* ================ demo 7  (46 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d7_s0_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d7_s0_1       = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 640, 256, 1152, 0 } };
static const DemoMsg4  sMsg_d7_s0_2       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 896, 256, 1152, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d7_s1_0       = { 0x9CFE, CLS_ACTOR,  WAIT,   1, 2,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d7_s2_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d7_s2_1       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d7_s2_2       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d7_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s3_1       = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 70, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d7_s4_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d7_s5_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d7_s6_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d7_s6_1       = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 24,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s6_2       = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s6_3       = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 602, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d7_s7_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg2  sMsg_d7_s7_1       = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d7_s8_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d7_s9_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d7_s10_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d7_s11_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 5,               1, { 1, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d7_s12_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d7_s13_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d7_s14_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d7_s15_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d7_s15_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 4,               1, { 1, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d7_s16_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d7_s17_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d7_s18_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d7_s19_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d7_s19_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d7_s19_2      = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 1, 0 } };
static const DemoMsg4  sMsg_d7_s19_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 640, 256, 1024, 0 } };
static const DemoMsg4  sMsg_d7_s19_4      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 896, 256, 1024, 0 } };
static const DemoMsg4  sMsg_d7_s19_5      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 896, 512, 384, 80 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d7_s20_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d7_s21_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d7_s22_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d7_s23_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d7_s24_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d7_s24_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d7_s25_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d7_s26_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d7_s27_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d7_s27_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d7_s27_2      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s27_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 0, 0 } };
/* -- step 28 -- */
static const DemoMsg4  sMsg_d7_s28_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 896, 512, 1024, 80 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d7_s29_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 30 -- */
static const DemoMsg0  sMsg_d7_s30_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d7_s31_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d7_s32_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d7_s32_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 800, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d7_s33_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s33_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d7_s33_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 1, 0 } };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d7_s34_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d7_s35_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d7_s36_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d7_s36_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1152, 256, 1024, 0 } };
/* -- step 37 -- */
static const DemoMsg2  sMsg_d7_s37_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d7_s37_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d7_s38_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg4  sMsg_d7_s38_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 896, 256, 1792, 0 } };
/* -- step 39 -- */
static const DemoMsg4  sMsg_d7_s39_0      = { 0x51E2, CLS_ACTOR,  WAIT,   0, 3,               3, { 896, 256, 1664, 0 } };
static const DemoMsg2  sMsg_d7_s39_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* -- step 40 -- */
static const DemoMsg0  sMsg_d7_s40_0      = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg4  sMsg_d7_s40_1      = { 0x51E2, CLS_ACTOR,  WAIT,   0, 3,               3, { 896, 256, 1792, 0 } };
/* -- step 41 -- */
static const DemoMsg0  sMsg_d7_s41_0      = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d7_s41_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d7_s41_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d7_s41_3      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 42 -- */
static const DemoMsg2  sMsg_d7_s42_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 43 -- */
static const DemoMsg2  sMsg_d7_s43_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 12375, 0 } };
/* -- step 44 -- */
static const DemoMsg0  sMsg_d7_s44_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 45 -- */
static const DemoMsg0  sMsg_d7_s45_0      = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 7,               0 };
/* ================ demo 8  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d8_s0_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d8_s1_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d8_s1_1       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d8_s2_0       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1920, 256, 5248, 45 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d8_s3_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d8_s3_1       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 130, 130, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d8_s4_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4162, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d8_s5_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d8_s6_0       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d8_s6_1       = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* ================ demo 9  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d9_s0_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d9_s1_0       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 4, 0 } };
static const DemoMsg4  sMsg_d9_s1_1       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1664, 256, 1408, 45 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d9_s2_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -1323, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d9_s3_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d9_s4_0       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d9_s4_1       = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg4  sMsg_d9_s4_2       = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1536, 256, 640, 45 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d9_s5_0       = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -1323, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d9_s6_0       = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d9_s7_0       = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d9_s7_1       = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* ================ demo 10  (37 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d10_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d10_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d10_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
static const DemoMsg2  sMsg_d10_s1_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d10_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d10_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
static const DemoMsg2  sMsg_d10_s3_1      = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d10_s4_0      = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg4  sMsg_d10_s4_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 5504, 256, 4992, 0 } };
static const DemoMsg4  sMsg_d10_s4_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 5418, 256, 5082, 60 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d10_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d10_s5_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 178, 0 } };
static const DemoMsg2  sMsg_d10_s5_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d10_s5_3      = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d10_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d10_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d10_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d10_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d10_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d10_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d10_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d10_s13_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d10_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d10_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d10_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d10_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d10_s17_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 7,               1, { 0, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d10_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d10_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d10_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d10_s20_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d10_s20_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 3, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d10_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d10_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d10_s23_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d10_s23_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 9,               0 };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d10_s24_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d10_s24_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 178, 0 } };
static const DemoMsg2  sMsg_d10_s24_2     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg0  sMsg_d10_s24_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d10_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d10_s26_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 27 -- */
static const DemoMsg4  sMsg_d10_s27_0     = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 5632, 256, 4992, 0 } };
static const DemoMsg4  sMsg_d10_s27_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 5452, 256, 4992, 30 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d10_s28_0     = { 0xF5EB, CLS_PLAYER, WAIT,   3, 3,               1, { 7, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d10_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d10_s29_1     = { 0xF68F, CLS_ACTOR,  NOWAIT, 3, 3,               3, { 5504, 256, 4992, 0 } };
static const DemoMsg2  sMsg_d10_s29_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 30 -- */
static const DemoMsg4  sMsg_d10_s30_0     = { 0xF68F, CLS_ACTOR,  WAIT,   3, 3,               3, { 5504, 256, 5888, 0 } };
static const DemoMsg2  sMsg_d10_s30_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
static const DemoMsg2  sMsg_d10_s30_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d10_s30_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 202, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d10_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d10_s31_1     = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d10_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d10_s32_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d10_s32_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 26, 0 } };
static const DemoMsg2  sMsg_d10_s32_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d10_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11335, 0 } };
/* -- step 34 -- */
static const DemoMsg0  sMsg_d10_s34_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d10_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d10_s35_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 130, 130, 0 } };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d10_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d10_s36_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 7,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d10_s36_2     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 5,               1, { 30, 0 } };
/* ================ demo 11  (41 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d11_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d11_s0_1      = { 0x2B06, CLS_PLAYER, WAIT,   1, 11,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d11_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d11_s1_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d11_s1_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1920, 256, 1408, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d11_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d11_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 1, 6,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d11_s2_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d11_s3_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 2048, 256, 1280, 30 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d11_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d11_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 71, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d11_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d11_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d11_s7_0      = { 0x2B06, CLS_PLAYER, WAIT,   1, 12,              1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d11_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d11_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d11_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d11_s10_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 4,               1, { 1, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d11_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d11_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d11_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d11_s13_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d11_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d11_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d11_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d11_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d11_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d11_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg4  sMsg_d11_s19_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 110, 120, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d11_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8502, 0 } };
/* -- step 21 -- */
static const DemoMsg0  sMsg_d11_s21_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d11_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d11_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 24 -- */
static const DemoMsg0  sMsg_d11_s24_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d11_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d11_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 27 -- */
static const DemoMsg0  sMsg_d11_s27_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d11_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d11_s28_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 7,               1, { 0, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d11_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 30 -- */
static const DemoMsg0  sMsg_d11_s30_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d11_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d11_s31_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 4, 0 } };
static const DemoMsg2  sMsg_d11_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 3, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d11_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 33 -- */
static const DemoMsg0  sMsg_d11_s33_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d11_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d11_s34_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 9,               0 };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d11_s35_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d11_s35_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 71, 0 } };
static const DemoMsg2  sMsg_d11_s35_2     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
static const DemoMsg0  sMsg_d11_s35_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d11_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23147, 0 } };
/* -- step 37 -- */
static const DemoMsg0  sMsg_d11_s37_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d11_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d11_s38_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 7,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d11_s38_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 39 -- */
static const DemoMsg2  sMsg_d11_s39_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 40 -- */
static const DemoMsg2  sMsg_d11_s40_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
static const DemoMsg2  sMsg_d11_s40_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 26, 0 } };
/* ================ demo 12  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d12_s0_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1958, 406, 1494, 30 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d12_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d12_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d12_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d12_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 2, 0 } };
static const DemoMsg2  sMsg_d12_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d12_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d12_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d12_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d12_s6_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
static const DemoMsg4  sMsg_d12_s6_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 120, 120, 0 } };
static const DemoMsg0  sMsg_d12_s6_3      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d12_s6_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 26, 0 } };
static const DemoMsg2  sMsg_d12_s6_5      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d12_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d12_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d12_s9_0      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 3, 7,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d12_s9_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 13  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d13_s0_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1958, 406, 1494, 30 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d13_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d13_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d13_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d13_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 2, 0 } };
static const DemoMsg2  sMsg_d13_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d13_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d13_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d13_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d13_s6_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
static const DemoMsg0  sMsg_d13_s6_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d13_s6_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 26, 0 } };
static const DemoMsg2  sMsg_d13_s6_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d13_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31425, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d13_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d13_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 14  (35 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d14_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d14_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 1920, 256, 2176, 0 } };
static const DemoMsg4  sMsg_d14_s0_2      = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 1920, 256, 2432, 0 } };
static const DemoMsg2  sMsg_d14_s0_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d14_s1_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d14_s1_1      = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 1664, 256, 2176, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d14_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d14_s2_1      = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 2,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d14_s3_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1920, 256, 1844, 30 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d14_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d14_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d14_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d14_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d14_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 62, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d14_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d14_s8_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d14_s8_2      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d14_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d14_s9_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 11,              0 };
static const DemoMsg2  sMsg_d14_s9_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 835, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d14_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d14_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d14_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg4  sMsg_d14_s12_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1728, 256, 1880, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d14_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d14_s13_1     = { 0x7901, CLS_ACTOR,  NOWAIT, 0, 4,               0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d14_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d14_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d14_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d14_s16_1     = { 0x7901, CLS_ACTOR,  NOWAIT, 0, 32,              0 };
static const DemoMsg2  sMsg_d14_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 542, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d14_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d14_s17_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d14_s17_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d14_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d14_s18_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 7,               3, { 1728, 256, 1880, 0 } };
static const DemoMsg0  sMsg_d14_s18_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d14_s18_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d14_s18_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 850, 0 } };
static const DemoMsg2  sMsg_d14_s18_5     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 478, 0 } };
static const DemoMsg2  sMsg_d14_s18_6     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 1, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d14_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d14_s19_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 18,              1, { 0, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d14_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 21 -- */
static const DemoMsg0  sMsg_d14_s21_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d14_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d14_s22_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 5,               1, { 45, 0 } };
static const DemoMsg2  sMsg_d14_s22_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 28, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d14_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 24 -- */
static const DemoMsg0  sMsg_d14_s24_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d14_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg4  sMsg_d14_s25_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 13,              3, { 1920, 256, 2048, 0 } };
static const DemoMsg2  sMsg_d14_s25_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 860, 0 } };
static const DemoMsg2  sMsg_d14_s25_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d14_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 7, 0 } };
static const DemoMsg4  sMsg_d14_s26_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 29,              3, { 1984, 256, 2176, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d14_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d14_s27_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 30,              1, { 7, 0 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d14_s28_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 29 -- */
static const DemoMsg0  sMsg_d14_s29_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d14_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d14_s30_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 16,              3, { 7, 60, 0, 0 } };
static const DemoMsg4  sMsg_d14_s30_2     = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 29,              3, { 1536, 256, 2176, 0 } };
static const DemoMsg2  sMsg_d14_s30_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 664, 0 } };
static const DemoMsg2  sMsg_d14_s30_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 741, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d14_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
static const DemoMsg2  sMsg_d14_s31_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 14,              1, { 0, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d14_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d14_s32_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 31,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d14_s32_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 5,               1, { 7, 0 } };
/* -- step 33 -- */
static const DemoMsg2  sMsg_d14_s33_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14069, 0 } };
/* -- step 34 -- */
static const DemoMsg0  sMsg_d14_s34_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 15  (41 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d15_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d15_s0_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 21,              0 };
static const DemoMsg2  sMsg_d15_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d15_s1_0      = { 0x74E2, CLS_SOUND,  WAIT,   0, 2,               1, { 60, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d15_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d15_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d15_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d15_s4_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1920, 256, 1920, 0 } };
static const DemoMsg2  sMsg_d15_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d15_s5_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d15_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d15_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 62, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d15_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d15_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d15_s7_2      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 28,              1, { 0, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d15_s8_0      = { 0xBA4B, CLS_BOSS,   WAIT,   0, 13,              3, { 1920, 256, 1920, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d15_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d15_s9_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 23,              0 };
static const DemoMsg0  sMsg_d15_s9_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d15_s9_3      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d15_s9_4      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d15_s9_5      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 759, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d15_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d15_s10_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 22,              1, { 3, 0 } };
static const DemoMsg2  sMsg_d15_s10_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 880, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d15_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d15_s11_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 24,              0 };
static const DemoMsg4  sMsg_d15_s11_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 16,              3, { 1, 48, 1, 0 } };
static const DemoMsg2  sMsg_d15_s11_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 42,              1, { 1, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d15_s12_0     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 23,              1, { 30, 0 } };
static const DemoMsg4  sMsg_d15_s12_1     = { 0xBA4B, CLS_BOSS,   WAIT,   0, 15,              3, { 1920, 256, 1664, 0 } };
static const DemoMsg2  sMsg_d15_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 671, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d15_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d15_s13_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d15_s13_2     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 22,              1, { 2, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d15_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d15_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d15_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d15_s16_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 18,              0 };
static const DemoMsg2  sMsg_d15_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d15_s17_0     = { 0xBA4B, CLS_BOSS,   WAIT,   0, 26,              0 };
static const DemoMsg2  sMsg_d15_s17_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 76, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d15_s18_0     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 838, 0 } };
static const DemoMsg2  sMsg_d15_s18_1     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg8  sMsg_d15_s18_2     = { 0xE534, CLS_ETC,    NOWAIT, 0, 0,               8, { 1920, 256, 1664, 10, 128, 4000, 0, 255 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d15_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d15_s19_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 1, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d15_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d15_s20_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 3, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d15_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d15_s21_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 5, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d15_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d15_s22_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 3, 0 } };
/* -- step 23 -- */
static const DemoMsg4  sMsg_d15_s23_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 6,               3, { 1792, 256, 2176, 0 } };
static const DemoMsg4  sMsg_d15_s23_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1856, 256, 2240, 40 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d15_s24_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 10,              1, { 3, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d15_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 26 -- */
static const DemoMsg0  sMsg_d15_s26_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d15_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d15_s27_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 35, 0 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d15_s28_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 29 -- */
static const DemoMsg0  sMsg_d15_s29_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d15_s30_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 13,              1, { 3, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d15_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d15_s31_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 7,               1, { 0, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d15_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 33 -- */
static const DemoMsg0  sMsg_d15_s33_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d15_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d15_s34_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 9,               0 };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d15_s35_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 3,               1, { 3, 0 } };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d15_s36_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 37 -- */
static const DemoMsg0  sMsg_d15_s37_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 38 -- */
static const DemoMsg2  sMsg_d15_s38_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg10 sMsg_d15_s38_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 4, 4, 4, 1, 1, 0, 64, 0 } };
/* -- step 39 -- */
static const DemoMsg2  sMsg_d15_s39_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 10309, 0 } };
/* -- step 40 -- */
static const DemoMsg0  sMsg_d15_s40_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 16  (8 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d16_s0_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d16_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 768, 0 } };
static const DemoMsg2  sMsg_d16_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 65, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d16_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 896, 512, 384, 80 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d16_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14652, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d16_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d16_s4_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d16_s5_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 35,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d16_s5_1      = { 0x74E2, CLS_SOUND,  WAIT,   0, 0,               1, { 742, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d16_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14652, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d16_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 17  (13 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d17_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 640, 256, 2176, 0 } };
static const DemoMsg2  sMsg_d17_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d17_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d17_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d17_s2_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 896, 256, 640, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d17_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d17_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 68, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d17_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d17_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d17_s5_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 2,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d17_s6_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 896, 256, 256, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d17_s7_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d17_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -22135, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d17_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d17_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d17_s11_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d17_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d17_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 29, 0 } };
static const DemoMsg2  sMsg_d17_s12_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* ================ demo 18  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d18_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d18_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d18_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d18_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d18_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d18_s2_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1664, 768, 1152, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d18_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d18_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 68, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d18_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d18_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d18_s5_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 2,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d18_s6_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 3,               3, { 1408, 768, 1152, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d18_s7_0      = { 0x51E2, CLS_ACTOR,  WAIT,   3, 0,               0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d18_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d18_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d18_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d18_s10_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 29, 0 } };
static const DemoMsg2  sMsg_d18_s10_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* ================ demo 19  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d19_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 4224, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d19_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d19_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d19_s2_0      = { 0x0A5A, CLS_ACTOR,  WAIT,   0, 3,               3, { 4736, 512, 4224, 0 } };
static const DemoMsg4  sMsg_d19_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4480, 256, 4096, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d19_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d19_s3_1      = { 0x0A5A, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d19_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -28814, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d19_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d19_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d19_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -28814, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d19_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d19_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d19_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -28814, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d19_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d19_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d19_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -28814, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d19_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d19_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d19_s15_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 28,              3, { 4, 130, 130, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d19_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -28814, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d19_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d19_s18_0     = { 0x0A5A, CLS_ACTOR,  WAIT,   0, 3,               3, { 4736, 512, 3584, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d19_s19_0     = { 0x0A5A, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d19_s19_1     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 45, 0 } };
/* ================ demo 20  (19 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d20_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d20_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d20_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d20_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg4  sMsg_d20_s3_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 1536, 4992, 0 } };
static const DemoMsg4  sMsg_d20_s3_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1472, 1536, 4800, 40 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d20_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d20_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d20_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d20_s6_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 77, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d20_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d20_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d20_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d20_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d20_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d20_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d20_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d20_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d20_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d20_s15_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d20_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -27878, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d20_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d20_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d20_s18_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* ================ demo 21  (32 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d21_s0_0      = { 0x8E9F, CLS_ACTOR,  WAIT,   0, 1,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d21_s0_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 1,               3, { 1472, 1536, 4800, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d21_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d21_s1_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 34,              0 };
static const DemoMsg2  sMsg_d21_s1_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 77, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d21_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d21_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d21_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d21_s4_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 35,              0 };
static const DemoMsg2  sMsg_d21_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 602, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d21_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d21_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d21_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d21_s7_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d21_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d21_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg4  sMsg_d21_s8_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1664, 3584, 1152, 600 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d21_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d21_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d21_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d21_s11_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 66, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d21_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d21_s13_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg4  sMsg_d21_s14_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1472, 1536, 4800, 80 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d21_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d21_s15_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d21_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d21_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d21_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d21_s18_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d21_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d21_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d21_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d21_s21_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d21_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 23 -- */
static const DemoMsg0  sMsg_d21_s23_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d21_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d21_s24_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 9,               0 };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d21_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d21_s25_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d21_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31740, 0 } };
/* -- step 27 -- */
static const DemoMsg0  sMsg_d21_s27_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d21_s28_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d21_s28_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1152, 2048, 4992, 0 } };
static const DemoMsg2  sMsg_d21_s28_2     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 5,               1, { 30, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d21_s29_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 3, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d21_s30_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d21_s30_1     = { 0x8E9F, CLS_ACTOR,  WAIT,   0, 3,               3, { 1408, 1536, 5760, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d21_s31_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d21_s31_1     = { 0x8E9F, CLS_ACTOR,  WAIT,   0, 0,               0 };
/* ================ demo 22  (25 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d22_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 4992, 0 } };
/* -- step 1 -- */
static const DemoMsg0  sMsg_d22_s1_0      = { 0x7901, CLS_ACTOR,  WAIT,   0, 4,               0 };
static const DemoMsg2  sMsg_d22_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg4  sMsg_d22_s1_2      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1066, 256, 4802, 50 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d22_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d22_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -25042, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d22_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d22_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d22_s5_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d22_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -25042, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d22_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d22_s8_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d22_s8_1      = { 0x7901, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d22_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg8  sMsg_d22_s9_1      = { 0xE534, CLS_ETC,    NOWAIT, 8, 1,               8, { 1152, 256, 4480, 20, 1800, 256, 0, 255 } };
static const DemoMsg2  sMsg_d22_s9_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 813, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d22_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -25042, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d22_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d22_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d22_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 60, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d22_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -25042, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d22_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg8  sMsg_d22_s15_0     = { 0xE534, CLS_ETC,    WAIT,   8, 1,               8, { 1152, 256, 4480, 20, 130, 30, 0, 255 } };
static const DemoMsg2  sMsg_d22_s15_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 234, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d22_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d22_s16_1     = { 0x7901, CLS_ACTOR,  NOWAIT, 0, 30,              0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d22_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d22_s17_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 781, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d22_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -25042, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d22_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d22_s20_0     = { 0xE534, CLS_ETC,    WAIT,   2, 2,               2, { 30977, 5 } };
/* -- step 21 -- */
static const DemoMsg4  sMsg_d22_s21_0     = { 0x7901, CLS_ACTOR,  WAIT,   0, 31,              3, { 896, 256, 4480, 0 } };
static const DemoMsg2  sMsg_d22_s21_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 814, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d22_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d22_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d22_s23_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 24 -- */
static const DemoMsg4  sMsg_d22_s24_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1280, 256, 4096, 0 } };
static const DemoMsg2  sMsg_d22_s24_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* ================ demo 23  (16 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d23_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg4  sMsg_d23_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 1152, 256, 1152, 0 } };
static const DemoMsg2  sMsg_d23_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d23_s0_3      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1216, 256, 1024, 60 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d23_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d23_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 69, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d23_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15357, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d23_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d23_s4_0      = { 0x9386, CLS_BOSS,   WAIT,   0, 5,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d23_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15357, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d23_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d23_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d23_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d23_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d23_s8_1      = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 3 } };
static const DemoMsg2  sMsg_d23_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 106, 0 } };
static const DemoMsg2  sMsg_d23_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 7,               1, { 4, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d23_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d23_s9_1      = { 0x730A, CLS_FADE,   NOWAIT, 9, 2,               9, { 1, 5, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d23_s10_0     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
static const DemoMsg4  sMsg_d23_s10_1     = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 5568, 256, 1280, 60 } };
static const DemoMsg4  sMsg_d23_s10_2     = { 0x9386, CLS_BOSS,   NOWAIT, 0, 1,               3, { 5504, 256, 896, 0 } };
static const DemoMsg4  sMsg_d23_s10_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 1,               3, { 5504, 256, 1408, 0 } };
static const DemoMsg2  sMsg_d23_s10_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg10 sMsg_d23_s11_0     = { 0x730A, CLS_FADE,   WAIT,   9, 2,               9, { 0, 5, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d23_s11_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 69, 0 } };
static const DemoMsg2  sMsg_d23_s11_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 4, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d23_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15357, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d23_s13_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d23_s14_0     = { 0x9386, CLS_BOSS,   WAIT,   0, 22,              0 };
static const DemoMsg2  sMsg_d23_s14_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d23_s14_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 383, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d23_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d23_s15_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* ================ demo 24  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d24_s0_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4988, 406, 5116, 100 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d24_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d24_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 4, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d24_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d24_s2_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d24_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d24_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d24_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d24_s4_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d24_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d24_s5_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 130, 130, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d24_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
// clang-format on
