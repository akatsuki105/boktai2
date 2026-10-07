// clang-format off
/* ================ demo 100  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d100_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   3, 6,               3, { 3456, 1024, 1920, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d100_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d100_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d100_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d100_s2_1     = { 0x3437, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d100_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d100_s3_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d100_s4_0     = { 0x3437, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 1280, 1920, 0 } };
/* -- step 5 -- */
static const DemoMsg4  sMsg_d100_s5_0     = { 0x3437, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 1280, 1152, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d100_s6_0     = { 0x3437, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d100_s6_1     = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 45, 0 } };
/* ================ demo 101  (3 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d101_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d101_s1_0     = { 0x3438, CLS_ACTOR,  WAIT,   0, 3,               3, { 256, 1280, 640, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d101_s2_0     = { 0x3438, CLS_ACTOR,  WAIT,   0, 0,               0 };
/* ================ demo 102  (37 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d102_s0_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 2, 0 } };
static const DemoMsg2  sMsg_d102_s0_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d102_s0_2     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3968, 0 } };
static const DemoMsg2  sMsg_d102_s0_3     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const DemoMsg4  sMsg_d102_s0_4     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2818, 408, 3898, 80 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d102_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d102_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d102_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d102_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d102_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d102_s4_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d102_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d102_s5_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 2,               1, { 5, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d102_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d102_s7_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d102_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const DemoMsg2  sMsg_d102_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d102_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d102_s10_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d102_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d102_s11_1    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 1, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d102_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d102_s12_1    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 42,              1, { 6, 0 } };
static const DemoMsg2  sMsg_d102_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 72, 0 } };
static const DemoMsg2  sMsg_d102_s12_3    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 510, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d102_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d102_s14_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d102_s15_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d102_s15_1    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d102_s15_2    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 43,              1, { 6, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d102_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d102_s16_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d102_s16_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d102_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d102_s17_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d102_s18_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d102_s19_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d102_s20_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d102_s20_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
static const DemoMsg2  sMsg_d102_s20_2    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 11,              1, { 5, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d102_s21_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d102_s22_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d102_s23_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d102_s23_1    = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 12,              1, { 5, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d102_s24_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 25 -- */
static const DemoMsg0  sMsg_d102_s25_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d102_s26_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d102_s26_1    = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 27 -- */
static const DemoMsg4  sMsg_d102_s27_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 256, 3712, 0 } };
/* -- step 28 -- */
static const DemoMsg4  sMsg_d102_s28_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3378, 0 } };
/* -- step 29 -- */
static const DemoMsg4  sMsg_d102_s29_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3328, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d102_s30_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d102_s30_1    = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d102_s31_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 32 -- */
static const DemoMsg0  sMsg_d102_s32_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 33 -- */
static const DemoMsg4  sMsg_d102_s33_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3378, 0 } };
/* -- step 34 -- */
static const DemoMsg4  sMsg_d102_s34_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3328, 0 } };
/* -- step 35 -- */
static const DemoMsg0  sMsg_d102_s35_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const DemoMsg2  sMsg_d102_s35_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 36 -- */
static const DemoMsg2  sMsg_d102_s36_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d102_s36_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 103  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d103_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3968, 0 } };
static const DemoMsg4  sMsg_d103_s0_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 2432, 256, 3712, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d103_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d103_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d103_s1_2     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d103_s2_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d103_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d103_s3_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 42,              1, { 6, 0 } };
static const DemoMsg2  sMsg_d103_s3_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 510, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d103_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d103_s4_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d103_s4_2     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 43,              1, { 6, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d103_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d103_s5_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d103_s5_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d103_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d103_s6_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d103_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23657, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d103_s8_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d103_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d103_s9_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 10,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d103_s9_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d103_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23657, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d103_s11_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d103_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d103_s12_1    = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 13 -- */
static const DemoMsg4  sMsg_d103_s13_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 256, 3712, 0 } };
/* -- step 14 -- */
static const DemoMsg4  sMsg_d103_s14_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3378, 0 } };
/* -- step 15 -- */
static const DemoMsg4  sMsg_d103_s15_0    = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3328, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d103_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d103_s16_1    = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
/* -- step 17 -- */
static const DemoMsg4  sMsg_d103_s17_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3378, 0 } };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d103_s18_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3328, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d103_s19_0    = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const DemoMsg2  sMsg_d103_s19_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d103_s20_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg10 sMsg_d103_s20_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 104  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d104_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 3200, 0 } };
static const DemoMsg0  sMsg_d104_s0_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 0,               0 };
static const DemoMsg2  sMsg_d104_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d104_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 948, 256, 3252, 45 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d104_s1_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d104_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d104_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d104_s2_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 1, 5, 0, 0, 0, 1, 0, 0 } };
static const DemoMsg2  sMsg_d104_s2_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d104_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d104_s3_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 33,              0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d104_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -24401, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d104_s5_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d104_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d104_s6_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 34,              0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d104_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d104_s7_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 0, 5, 0, 0, 0, 1, 0, 0 } };
static const DemoMsg2  sMsg_d104_s7_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d104_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d104_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 19, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d104_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -24401, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d104_s10_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d104_s11_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ demo 105  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d105_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4352, 256, 3200, 0 } };
static const DemoMsg0  sMsg_d105_s0_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 0,               0 };
static const DemoMsg2  sMsg_d105_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d105_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4412, 256, 3132, 45 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d105_s1_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d105_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d105_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d105_s2_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 1, 5, 0, 0, 0, 1, 0, 0 } };
static const DemoMsg2  sMsg_d105_s2_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d105_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d105_s3_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 33,              0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d105_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11372, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d105_s5_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d105_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d105_s6_1     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 34,              0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d105_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg8  sMsg_d105_s7_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 0, 5, 0, 0, 0, 1, 0, 0 } };
static const DemoMsg2  sMsg_d105_s7_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d105_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d105_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 19, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d105_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11372, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d105_s10_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d105_s11_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ demo 106  (15 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d106_s0_0     = { 0x0623, CLS_BOSS,   NOWAIT, 1, 2,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d106_s0_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 1280, 2176, 0 } };
static const DemoMsg2  sMsg_d106_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const DemoMsg4  sMsg_d106_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2818, 1430, 2046, 80 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d106_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d106_s1_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d106_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d106_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d106_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d106_s4_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d106_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d106_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d106_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d106_s7_1     = { 0x0623, CLS_BOSS,   NOWAIT, 0, 35,              0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d106_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg0  sMsg_d106_s8_1     = { 0x0623, CLS_BOSS,   NOWAIT, 0, 36,              0 };
static const DemoMsg2  sMsg_d106_s8_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d106_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d106_s9_1     = { 0x0623, CLS_BOSS,   NOWAIT, 0, 37,              0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d106_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d106_s11_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d106_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg10 sMsg_d106_s12_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d106_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d106_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d106_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d106_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d106_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 173, 0 } };
/* ================ demo 107  (15 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d107_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d107_s0_1     = { 0xCB6B, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d107_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg4  sMsg_d107_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 912, 406, 4846, 30 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d107_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d107_s1_1     = { 0xCB6B, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d107_s1_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 181, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d107_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d107_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d107_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d107_s4_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d107_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d107_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d107_s7_0     = { 0xCB6B, CLS_ACTOR,  WAIT,   0, 3,               3, { 384, 256, 4736, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d107_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d107_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d107_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d107_s10_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 7,               0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d107_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg0  sMsg_d107_s11_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 8,               0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d107_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d107_s12_1    = { 0xCB6B, CLS_ACTOR,  NOWAIT, 0, 5,               0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d107_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d107_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d107_s14_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const DemoMsg2  sMsg_d107_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 15, 0 } };
/* ================ demo 108  (15 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d108_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d108_s0_1     = { 0x7E5F, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg4  sMsg_d108_s0_2     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 256, 640, 30 } };
static const DemoMsg2  sMsg_d108_s0_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d108_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d108_s1_1     = { 0x7E5F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d108_s1_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 181, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d108_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d108_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d108_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d108_s4_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d108_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d108_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d108_s7_0     = { 0x7E5F, CLS_ACTOR,  WAIT,   0, 3,               3, { 4480, 256, 640, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d108_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d108_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d108_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d108_s10_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 7,               0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d108_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const DemoMsg0  sMsg_d108_s11_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 8,               0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d108_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d108_s12_1    = { 0x7E5F, CLS_ACTOR,  NOWAIT, 0, 5,               0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d108_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d108_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d108_s14_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const DemoMsg2  sMsg_d108_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 15, 0 } };
/* ================ demo 109  (14 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d109_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 384, 512, 4992, 0 } };
static const DemoMsg2  sMsg_d109_s0_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg4  sMsg_d109_s0_2     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 454, 662, 5042, 45 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d109_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d109_s1_1     = { 0x04B1, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d109_s1_2     = { 0x04B1, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d109_s1_3     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d109_s1_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 178, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d109_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d109_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d109_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d109_s4_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d109_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d109_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d109_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d109_s7_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d109_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d109_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg4  sMsg_d109_s10_0    = { 0x04B1, CLS_ACTOR,  WAIT,   0, 3,               3, { 640, 512, 4736, 0 } };
/* -- step 11 -- */
static const DemoMsg4  sMsg_d109_s11_0    = { 0x04B1, CLS_ACTOR,  WAIT,   0, 3,               3, { 640, 512, 4992, 0 } };
/* -- step 12 -- */
static const DemoMsg4  sMsg_d109_s12_0    = { 0x04B1, CLS_ACTOR,  WAIT,   0, 3,               3, { 1408, 512, 4992, 0 } };
static const DemoMsg2  sMsg_d109_s12_1    = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d109_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const DemoMsg2  sMsg_d109_s12_3    = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 30, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d109_s13_0    = { 0x04B1, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const DemoMsg2  sMsg_d109_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 16, 0 } };
/* ================ demo 110  (19 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d110_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d110_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d110_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d110_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d110_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d110_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d110_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d110_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d110_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d110_s5_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d110_s6_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d110_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d110_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d110_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d110_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d110_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d110_s12_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d110_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d110_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d110_s15_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d110_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d110_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d110_s18_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 111  (19 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d111_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d111_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d111_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d111_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d111_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d111_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d111_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d111_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d111_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d111_s5_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d111_s6_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d111_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d111_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d111_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d111_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d111_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d111_s12_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d111_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d111_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d111_s15_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d111_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d111_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d111_s18_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 112  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d112_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d112_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d112_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d112_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d112_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d112_s4_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4480, 406, 5504, 45 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d112_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d112_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d112_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d112_s6_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d112_s6_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d112_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d112_s8_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d112_s8_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d112_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d112_s10_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d112_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d112_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d112_s13_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d112_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d112_s15_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d112_s16_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d112_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d112_s18_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d112_s19_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 113  (19 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d113_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d113_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d113_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d113_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d113_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d113_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d113_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d113_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d113_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d113_s5_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d113_s6_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d113_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d113_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d113_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d113_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d113_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d113_s12_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d113_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d113_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d113_s15_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d113_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d113_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d113_s18_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 114  (19 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d114_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d114_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d114_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d114_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d114_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d114_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d114_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d114_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d114_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d114_s5_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d114_s6_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d114_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d114_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d114_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d114_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d114_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d114_s12_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d114_s13_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d114_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d114_s15_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d114_s16_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d114_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d114_s18_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 115  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d115_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d115_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d115_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d115_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d115_s3_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d115_s4_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4480, 406, 5504, 45 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d115_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d115_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d115_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d115_s6_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const DemoMsg2  sMsg_d115_s6_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d115_s7_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d115_s8_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d115_s8_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d115_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d115_s10_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d115_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d115_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d115_s13_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d115_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d115_s15_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d115_s16_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d115_s17_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d115_s18_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d115_s19_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 116  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d116_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1152, 0 } };
static const DemoMsg2  sMsg_d116_s0_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d116_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d116_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d116_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d116_s2_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1664, 45 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d116_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d116_s3_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d116_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d116_s4_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d116_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d116_s5_1     = { 0x81CF, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const DemoMsg0  sMsg_d116_s5_2     = { 0x81D0, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const DemoMsg0  sMsg_d116_s5_3     = { 0x81D1, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
/* ================ demo 117  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d117_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d117_s0_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1408, 45 } };
static const DemoMsg2  sMsg_d117_s0_2     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d117_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d117_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d117_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d117_s2_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d117_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17950, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d117_s4_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d117_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d117_s5_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d117_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17950, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d117_s7_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d117_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d117_s8_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 118  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d118_s0_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1152, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d118_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d118_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d118_s2_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1664, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d118_s3_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d118_s3_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d118_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 21757, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d118_s5_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 119  (15 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d119_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d119_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d119_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d119_s1_2     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d119_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d119_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d119_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d119_s4_1     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d119_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d119_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d119_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d119_s7_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d119_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d119_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d119_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d119_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d119_s11_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d119_s11_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d119_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d119_s13_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d119_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d119_s14_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg0  sMsg_d119_s14_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* ================ demo 120  (15 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d120_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d120_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d120_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d120_s1_2     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d120_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d120_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d120_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d120_s4_1     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 5, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d120_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d120_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d120_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d120_s7_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d120_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d120_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d120_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d120_s11_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d120_s11_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d120_s11_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d120_s12_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d120_s13_0    = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d120_s14_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d120_s14_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg0  sMsg_d120_s14_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* ================ demo 121  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d121_s0_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d121_s0_1     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 3200, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d121_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d121_s1_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d121_s2_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4048, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d121_s3_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 122  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d122_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d122_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d122_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d122_s3_0     = { 0x41AA, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d122_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d122_s5_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d122_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d122_s6_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d122_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d122_s8_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d122_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* ================ demo 123  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d123_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d123_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d123_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d123_s3_0     = { 0x41AA, CLS_PLAYER, WAIT,   0, 3,               1, { 5, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d123_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d123_s5_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d123_s6_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d123_s6_1     = { 0x41AA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d123_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d123_s8_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d123_s9_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* ================ demo 124  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d124_s0_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d124_s1_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d124_s2_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d124_s3_0     = { 0x41AA, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d124_s3_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d124_s4_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d124_s4_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d124_s5_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d124_s6_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d124_s7_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d124_s7_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d124_s7_2     = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d124_s8_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d124_s9_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d124_s10_0    = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
// clang-format on
