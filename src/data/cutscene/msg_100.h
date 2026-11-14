// clang-format off
/* ================ cutscene 100  (7 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c100_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   3, 6,               3, { 3456, 1024, 1920, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c100_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c100_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 3, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c100_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   3, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c100_s2_1     = { 0x3437, CLS_ACTOR,  NOWAIT, 3, 2,               1, { 3, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c100_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c100_s3_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 799, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c100_s4_0     = { 0x3437, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 1280, 1920, 0 } };
/* -- step 5 -- */
static const CutsceneMsg4  sMsg_c100_s5_0     = { 0x3437, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 1280, 1152, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c100_s6_0     = { 0x3437, CLS_ACTOR,  NOWAIT, 0, 0,               0 };
static const CutsceneMsg2  sMsg_c100_s6_1     = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 45, 0 } };
/* ================ cutscene 101  (3 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c101_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg4  sMsg_c101_s1_0     = { 0x3438, CLS_ACTOR,  WAIT,   0, 3,               3, { 256, 1280, 640, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c101_s2_0     = { 0x3438, CLS_ACTOR,  WAIT,   0, 0,               0 };
/* ================ cutscene 102  (37 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c102_s0_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 2, 0 } };
static const CutsceneMsg2  sMsg_c102_s0_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c102_s0_2     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3968, 0 } };
static const CutsceneMsg2  sMsg_c102_s0_3     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 4, 0 } };
static const CutsceneMsg4  sMsg_c102_s0_4     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2818, 408, 3898, 80 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c102_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c102_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c102_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c102_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c102_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c102_s4_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c102_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c102_s5_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 2,               1, { 5, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c102_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 7 -- */
static const CutsceneMsg0  sMsg_c102_s7_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c102_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c102_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c102_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c102_s10_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c102_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c102_s11_1    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 3,               1, { 1, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c102_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c102_s12_1    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 42,              1, { 6, 0 } };
static const CutsceneMsg2  sMsg_c102_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 72, 0 } };
static const CutsceneMsg2  sMsg_c102_s12_3    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 510, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c102_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 14 -- */
static const CutsceneMsg0  sMsg_c102_s14_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c102_s15_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c102_s15_1    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 7,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c102_s15_2    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 43,              1, { 6, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c102_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg10 sMsg_c102_s16_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c102_s16_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c102_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c102_s17_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c102_s18_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c102_s19_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c102_s20_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c102_s20_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
static const CutsceneMsg2  sMsg_c102_s20_2    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 11,              1, { 5, 0 } };
/* -- step 21 -- */
static const CutsceneMsg2  sMsg_c102_s21_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 22 -- */
static const CutsceneMsg0  sMsg_c102_s22_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const CutsceneMsg2  sMsg_c102_s23_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c102_s23_1    = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 12,              1, { 5, 0 } };
/* -- step 24 -- */
static const CutsceneMsg2  sMsg_c102_s24_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 25 -- */
static const CutsceneMsg0  sMsg_c102_s25_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 26 -- */
static const CutsceneMsg2  sMsg_c102_s26_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c102_s26_1    = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 27 -- */
static const CutsceneMsg4  sMsg_c102_s27_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 256, 3712, 0 } };
/* -- step 28 -- */
static const CutsceneMsg4  sMsg_c102_s28_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3378, 0 } };
/* -- step 29 -- */
static const CutsceneMsg4  sMsg_c102_s29_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3328, 0 } };
/* -- step 30 -- */
static const CutsceneMsg2  sMsg_c102_s30_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c102_s30_1    = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 0,               0 };
/* -- step 31 -- */
static const CutsceneMsg2  sMsg_c102_s31_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -7334, 0 } };
/* -- step 32 -- */
static const CutsceneMsg0  sMsg_c102_s32_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 33 -- */
static const CutsceneMsg4  sMsg_c102_s33_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3378, 0 } };
/* -- step 34 -- */
static const CutsceneMsg4  sMsg_c102_s34_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3328, 0 } };
/* -- step 35 -- */
static const CutsceneMsg0  sMsg_c102_s35_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const CutsceneMsg2  sMsg_c102_s35_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 36 -- */
static const CutsceneMsg2  sMsg_c102_s36_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg10 sMsg_c102_s36_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ cutscene 103  (21 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c103_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3968, 0 } };
static const CutsceneMsg4  sMsg_c103_s0_1     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 2432, 256, 3712, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c103_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c103_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c103_s1_2     = { TGT_OTNK, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c103_s2_0     = { TGT_SABATA, CLS_PLAYER, WAIT,   1, 3,               1, { 1, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c103_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c103_s3_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 42,              1, { 6, 0 } };
static const CutsceneMsg2  sMsg_c103_s3_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 510, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c103_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c103_s4_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 7,               1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c103_s4_2     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 43,              1, { 6, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c103_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg10 sMsg_c103_s5_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c103_s5_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 509, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c103_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg10 sMsg_c103_s6_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c103_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23657, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c103_s8_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c103_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c103_s9_1     = { TGT_SABATA, CLS_PLAYER, NOWAIT, 1, 10,              1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c103_s9_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 746, 0 } };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c103_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -23657, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c103_s11_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c103_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c103_s12_1    = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* -- step 13 -- */
static const CutsceneMsg4  sMsg_c103_s13_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2944, 256, 3712, 0 } };
/* -- step 14 -- */
static const CutsceneMsg4  sMsg_c103_s14_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3378, 0 } };
/* -- step 15 -- */
static const CutsceneMsg4  sMsg_c103_s15_0    = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 3328, 0 } };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c103_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c103_s16_1    = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 0,               0 };
/* -- step 17 -- */
static const CutsceneMsg4  sMsg_c103_s17_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3378, 0 } };
/* -- step 18 -- */
static const CutsceneMsg4  sMsg_c103_s18_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 3,               3, { 2688, 256, 3328, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c103_s19_0    = { TGT_OTNK, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const CutsceneMsg2  sMsg_c103_s19_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 20 -- */
static const CutsceneMsg2  sMsg_c103_s20_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg10 sMsg_c103_s20_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ cutscene 104  (12 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c104_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 3200, 0 } };
static const CutsceneMsg0  sMsg_c104_s0_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 0,               0 };
static const CutsceneMsg2  sMsg_c104_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c104_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 948, 256, 3252, 45 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c104_s1_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c104_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c104_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg8  sMsg_c104_s2_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 1, 5, 0, 0, 0, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c104_s2_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c104_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c104_s3_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 33,              0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c104_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -24401, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c104_s5_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c104_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c104_s6_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 34,              0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c104_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg8  sMsg_c104_s7_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 0, 5, 0, 0, 0, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c104_s7_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c104_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c104_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 19, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c104_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -24401, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c104_s10_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c104_s11_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ cutscene 105  (12 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c105_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4352, 256, 3200, 0 } };
static const CutsceneMsg0  sMsg_c105_s0_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 0,               0 };
static const CutsceneMsg2  sMsg_c105_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c105_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4412, 256, 3132, 45 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c105_s1_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c105_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c105_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg8  sMsg_c105_s2_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 1, 5, 0, 0, 0, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c105_s2_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c105_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c105_s3_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 33,              0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c105_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11372, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c105_s5_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c105_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c105_s6_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 34,              0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c105_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg8  sMsg_c105_s7_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 3,               8, { 0, 5, 0, 0, 0, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c105_s7_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c105_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c105_s8_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 19, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c105_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -11372, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c105_s10_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c105_s11_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 40, 0 } };
/* ================ cutscene 106  (15 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c106_s0_0     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 1, 2,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c106_s0_1     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 1280, 2176, 0 } };
static const CutsceneMsg2  sMsg_c106_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
static const CutsceneMsg4  sMsg_c106_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2818, 1430, 2046, 80 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c106_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c106_s1_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 180, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c106_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c106_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c106_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c106_s4_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c106_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c106_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c106_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg0  sMsg_c106_s7_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 0, 35,              0 };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c106_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const CutsceneMsg0  sMsg_c106_s8_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 0, 36,              0 };
static const CutsceneMsg2  sMsg_c106_s8_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 542, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c106_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg0  sMsg_c106_s9_1     = { TGT_SHADEMAN, CLS_BOSS,   NOWAIT, 0, 37,              0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c106_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29767, 0 } };
/* -- step 11 -- */
static const CutsceneMsg0  sMsg_c106_s11_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c106_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg10 sMsg_c106_s12_1    = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const CutsceneMsg2  sMsg_c106_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c106_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const CutsceneMsg2  sMsg_c106_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c106_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c106_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 173, 0 } };
/* ================ cutscene 107  (15 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c107_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c107_s0_1     = { TGT_MARCELLO, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c107_s0_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const CutsceneMsg4  sMsg_c107_s0_3     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 912, 406, 4846, 30 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c107_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c107_s1_1     = { TGT_MARCELLO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c107_s1_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 181, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c107_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c107_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c107_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const CutsceneMsg4  sMsg_c107_s4_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c107_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c107_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg4  sMsg_c107_s7_0     = { TGT_MARCELLO, CLS_ACTOR,  WAIT,   0, 3,               3, { 384, 256, 4736, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c107_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20575, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c107_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c107_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg0  sMsg_c107_s10_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 7,               0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c107_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const CutsceneMsg0  sMsg_c107_s11_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 8,               0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c107_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c107_s12_1    = { TGT_MARCELLO, CLS_ACTOR,  NOWAIT, 0, 5,               0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c107_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c107_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c107_s14_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c107_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 15, 0 } };
/* ================ cutscene 108  (15 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c108_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c108_s0_1     = { TGT_LUIS, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const CutsceneMsg4  sMsg_c108_s0_2     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 256, 640, 30 } };
static const CutsceneMsg2  sMsg_c108_s0_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c108_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c108_s1_1     = { TGT_LUIS, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c108_s1_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 181, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c108_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c108_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c108_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const CutsceneMsg4  sMsg_c108_s4_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c108_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c108_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg4  sMsg_c108_s7_0     = { TGT_LUIS, CLS_ACTOR,  WAIT,   0, 3,               3, { 4480, 256, 640, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c108_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 15817, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c108_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c108_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const CutsceneMsg0  sMsg_c108_s10_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 7,               0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c108_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 45, 0 } };
static const CutsceneMsg0  sMsg_c108_s11_1    = { 0xB142, CLS_ETC,    NOWAIT, 0, 8,               0 };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c108_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c108_s12_1    = { TGT_LUIS, CLS_ACTOR,  NOWAIT, 0, 5,               0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c108_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c108_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c108_s14_0    = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c108_s14_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 15, 0 } };
/* ================ cutscene 109  (14 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c109_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 384, 512, 4992, 0 } };
static const CutsceneMsg2  sMsg_c109_s0_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const CutsceneMsg4  sMsg_c109_s0_2     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 454, 662, 5042, 45 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c109_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c109_s1_1     = { TGT_HATENA, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const CutsceneMsg2  sMsg_c109_s1_2     = { TGT_HATENA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c109_s1_3     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c109_s1_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 178, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c109_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c109_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c109_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const CutsceneMsg4  sMsg_c109_s4_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c109_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c109_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c109_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const CutsceneMsg4  sMsg_c109_s7_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c109_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29872, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c109_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg4  sMsg_c109_s10_0    = { TGT_HATENA, CLS_ACTOR,  WAIT,   0, 3,               3, { 640, 512, 4736, 0 } };
/* -- step 11 -- */
static const CutsceneMsg4  sMsg_c109_s11_0    = { TGT_HATENA, CLS_ACTOR,  WAIT,   0, 3,               3, { 640, 512, 4992, 0 } };
/* -- step 12 -- */
static const CutsceneMsg4  sMsg_c109_s12_0    = { TGT_HATENA, CLS_ACTOR,  WAIT,   0, 3,               3, { 1408, 512, 4992, 0 } };
static const CutsceneMsg2  sMsg_c109_s12_1    = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c109_s12_2    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
static const CutsceneMsg2  sMsg_c109_s12_3    = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 30, 0 } };
/* -- step 13 -- */
static const CutsceneMsg0  sMsg_c109_s13_0    = { TGT_HATENA, CLS_ACTOR,  WAIT,   0, 0,               0 };
static const CutsceneMsg2  sMsg_c109_s13_1    = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 16, 0 } };
/* ================ cutscene 110  (19 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c110_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c110_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c110_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c110_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c110_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c110_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c110_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c110_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c110_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c110_s5_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c110_s6_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c110_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c110_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c110_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c110_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c110_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c110_s12_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c110_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c110_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c110_s15_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c110_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c110_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c110_s18_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 111  (19 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c111_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c111_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c111_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c111_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c111_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c111_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c111_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c111_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c111_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c111_s5_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c111_s6_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c111_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c111_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c111_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c111_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c111_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c111_s12_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c111_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c111_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c111_s15_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c111_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c111_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c111_s18_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 112  (20 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c112_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c112_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c112_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c112_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c112_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c112_s4_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4480, 406, 5504, 45 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c112_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c112_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c112_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c112_s6_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c112_s6_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg4  sMsg_c112_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c112_s8_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c112_s8_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c112_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c112_s10_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c112_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c112_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 13 -- */
static const CutsceneMsg0  sMsg_c112_s13_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c112_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c112_s15_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 16 -- */
static const CutsceneMsg0  sMsg_c112_s16_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c112_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c112_s18_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 4307, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c112_s19_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 113  (19 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c113_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c113_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c113_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c113_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c113_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c113_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c113_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c113_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c113_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c113_s5_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 6, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c113_s6_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c113_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c113_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c113_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c113_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c113_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c113_s12_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c113_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c113_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c113_s15_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c113_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c113_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c113_s18_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 114  (19 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c114_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c114_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c114_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c114_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c114_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c114_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c114_s4_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c114_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c114_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c114_s5_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 6 -- */
static const CutsceneMsg4  sMsg_c114_s6_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c114_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c114_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c114_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c114_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c114_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 12 -- */
static const CutsceneMsg0  sMsg_c114_s12_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const CutsceneMsg2  sMsg_c114_s13_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c114_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 15 -- */
static const CutsceneMsg0  sMsg_c114_s15_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const CutsceneMsg2  sMsg_c114_s16_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c114_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 18 -- */
static const CutsceneMsg0  sMsg_c114_s18_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 115  (20 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c115_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c115_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c115_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c115_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const CutsceneMsg2  sMsg_c115_s3_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const CutsceneMsg4  sMsg_c115_s4_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4480, 406, 5504, 45 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c115_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c115_s5_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c115_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c115_s6_1     = { 0x0CFF, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
static const CutsceneMsg2  sMsg_c115_s6_2     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 7 -- */
static const CutsceneMsg4  sMsg_c115_s7_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4480, 256, 5504, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c115_s8_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const CutsceneMsg2  sMsg_c115_s8_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c115_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 10 -- */
static const CutsceneMsg0  sMsg_c115_s10_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c115_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c115_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 13 -- */
static const CutsceneMsg0  sMsg_c115_s13_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c115_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 15 -- */
static const CutsceneMsg2  sMsg_c115_s15_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 16 -- */
static const CutsceneMsg0  sMsg_c115_s16_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const CutsceneMsg2  sMsg_c115_s17_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 18 -- */
static const CutsceneMsg2  sMsg_c115_s18_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -29849, 0 } };
/* -- step 19 -- */
static const CutsceneMsg0  sMsg_c115_s19_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 116  (6 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c116_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1152, 0 } };
static const CutsceneMsg2  sMsg_c116_s0_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c116_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c116_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c116_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg4  sMsg_c116_s2_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1664, 45 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c116_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c116_s3_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c116_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c116_s4_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c116_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c116_s5_1     = { 0x81CF, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const CutsceneMsg0  sMsg_c116_s5_2     = { 0x81D0, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const CutsceneMsg0  sMsg_c116_s5_3     = { 0x81D1, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
/* ================ cutscene 117  (9 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c117_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg4  sMsg_c117_s0_1     = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 4224, 512, 1408, 45 } };
static const CutsceneMsg2  sMsg_c117_s0_2     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c117_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg0  sMsg_c117_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 7,               0 };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c117_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const CutsceneMsg2  sMsg_c117_s2_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c117_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17950, 0 } };
/* -- step 4 -- */
static const CutsceneMsg0  sMsg_c117_s4_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c117_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const CutsceneMsg4  sMsg_c117_s5_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c117_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -17950, 0 } };
/* -- step 7 -- */
static const CutsceneMsg0  sMsg_c117_s7_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c117_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const CutsceneMsg10 sMsg_c117_s8_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ cutscene 118  (6 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg4  sMsg_c118_s0_0     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 4224, 512, 1152, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c118_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c118_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg4  sMsg_c118_s2_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 4224, 512, 1664, 60 } };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c118_s3_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const CutsceneMsg2  sMsg_c118_s3_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c118_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 21757, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c118_s5_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 119  (15 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c119_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c119_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c119_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c119_s1_2     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c119_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c119_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c119_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c119_s4_1     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 5, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c119_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c119_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c119_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c119_s7_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c119_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c119_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c119_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c119_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c119_s11_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c119_s11_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c119_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 275, 0 } };
/* -- step 13 -- */
static const CutsceneMsg0  sMsg_c119_s13_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c119_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c119_s14_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const CutsceneMsg0  sMsg_c119_s14_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* ================ cutscene 120  (15 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c120_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c120_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c120_s1_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c120_s1_2     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c120_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c120_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c120_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c120_s4_1     = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 5, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c120_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c120_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c120_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c120_s7_1     = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c120_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c120_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c120_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
/* -- step 11 -- */
static const CutsceneMsg2  sMsg_c120_s11_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c120_s11_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
static const CutsceneMsg2  sMsg_c120_s11_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 1,               1, { 3, 0 } };
/* -- step 12 -- */
static const CutsceneMsg2  sMsg_c120_s12_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30857, 0 } };
/* -- step 13 -- */
static const CutsceneMsg0  sMsg_c120_s13_0    = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const CutsceneMsg2  sMsg_c120_s14_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg0  sMsg_c120_s14_1    = { 0x1637, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const CutsceneMsg0  sMsg_c120_s14_2    = { 0x8C86, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* ================ cutscene 121  (4 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c121_s0_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg4  sMsg_c121_s0_1     = { TGT_PLAYER, CLS_PLAYER, WAIT,   0, 6,               3, { 896, 256, 3200, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c121_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const CutsceneMsg2  sMsg_c121_s1_1     = { TGT_PLAYER, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 2 -- */
static const CutsceneMsg2  sMsg_c121_s2_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4048, 0 } };
/* -- step 3 -- */
static const CutsceneMsg0  sMsg_c121_s3_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ cutscene 122  (10 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c122_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c122_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c122_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c122_s3_0     = { 0x41AA, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c122_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c122_s5_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c122_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c122_s6_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c122_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c122_s8_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c122_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* ================ cutscene 123  (10 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c123_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c123_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c123_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c123_s3_0     = { 0x41AA, CLS_PLAYER, WAIT,   0, 3,               1, { 5, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c123_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 5 -- */
static const CutsceneMsg0  sMsg_c123_s5_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const CutsceneMsg2  sMsg_c123_s6_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c123_s6_1     = { 0x41AA, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c123_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 8 -- */
static const CutsceneMsg0  sMsg_c123_s8_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const CutsceneMsg2  sMsg_c123_s9_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* ================ cutscene 124  (11 steps) ================ */
/* -- step 0 -- */
static const CutsceneMsg2  sMsg_c124_s0_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const CutsceneMsg2  sMsg_c124_s1_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 2 -- */
static const CutsceneMsg0  sMsg_c124_s2_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const CutsceneMsg2  sMsg_c124_s3_0     = { 0x41AA, CLS_ACTOR,  WAIT,   0, 2,               1, { 5, 0 } };
static const CutsceneMsg2  sMsg_c124_s3_1     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 4 -- */
static const CutsceneMsg2  sMsg_c124_s4_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const CutsceneMsg2  sMsg_c124_s4_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 3, 0 } };
/* -- step 5 -- */
static const CutsceneMsg2  sMsg_c124_s5_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 6 -- */
static const CutsceneMsg0  sMsg_c124_s6_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const CutsceneMsg2  sMsg_c124_s7_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const CutsceneMsg2  sMsg_c124_s7_1     = { 0x41AA, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const CutsceneMsg2  sMsg_c124_s7_2     = { TGT_KURO, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 8 -- */
static const CutsceneMsg2  sMsg_c124_s8_0     = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20032, 0 } };
/* -- step 9 -- */
static const CutsceneMsg0  sMsg_c124_s9_0     = { TGT_BUS, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const CutsceneMsg2  sMsg_c124_s10_0    = { TGT_BUS, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
// clang-format on
