// clang-format off
/* ================ demo 25  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d25_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d25_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31314, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d25_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d25_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d25_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d25_s4_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 5, 1, {1, 0}
};
/* ================ demo 26  (22 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d26_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d26_s0_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
/* -- step 1 -- */
static const DemoMsg4 sMsg_d26_s1_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {5247, 512, 640, 0}
};
static const DemoMsg4 sMsg_d26_s1_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {5181, 662, 770, 60}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d26_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d26_s2_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d26_s2_2 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 5, 1, {3, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d26_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-20300, 0}
};
/* -- step 4 -- */
static const DemoMsg0 sMsg_d26_s4_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d26_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d26_s5_1 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 5, 1, {7, 0}
};
/* -- step 6 -- */
static const DemoMsg4 sMsg_d26_s6_0 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 2, 4, {4280, 662, 770, 60}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d26_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-20300, 0}
};
/* -- step 8 -- */
static const DemoMsg0 sMsg_d26_s8_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 9 -- */
static const DemoMsg4 sMsg_d26_s9_0 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 2, 4, {5181, 662, 770, 60}
};
/* -- step 10 -- */
static const DemoMsg2 sMsg_d26_s10_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d26_s10_1 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 5, 1, {3, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d26_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {130, 0}
};
static const DemoMsg4 sMsg_d26_s11_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 3, {4, 140, 140, 0}
};
/* -- step 12 -- */
static const DemoMsg2 sMsg_d26_s12_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-20300, 0}
};
/* -- step 13 -- */
static const DemoMsg0 sMsg_d26_s13_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d26_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d26_s14_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 7, 1, {0, 0}
};
static const DemoMsg2 sMsg_d26_s14_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d26_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-20300, 0}
};
/* -- step 16 -- */
static const DemoMsg0 sMsg_d26_s16_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d26_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d26_s17_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 43, 1, {5, 0}
};
/* -- step 18 -- */
static const DemoMsg2 sMsg_d26_s18_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-20300, 0}
};
/* -- step 19 -- */
static const DemoMsg0 sMsg_d26_s19_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 20 -- */
static const DemoMsg2 sMsg_d26_s20_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg0 sMsg_d26_s20_1 = {0xF5EB, CLS_PLAYER, NOWAIT, 0, 9, 0};
static const DemoMsg0 sMsg_d26_s20_2 = {0xF5EB, CLS_PLAYER, NOWAIT, 0, 44, 0};
static const DemoMsg2 sMsg_d26_s20_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {34, 0}
};
static const DemoMsg2 sMsg_d26_s20_4 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 3, 1, {6, 0}
};
/* -- step 21 -- */
static const DemoMsg2 sMsg_d26_s21_0 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 5, 1, {30, 0}
};
static const DemoMsg2 sMsg_d26_s21_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
/* ================ demo 27  (31 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d27_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d27_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {8, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d27_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d27_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d27_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d27_s3_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {3, 0}
};
static const DemoMsg2 sMsg_d27_s3_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d27_s4_0 = {
    0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT, 1, {10, 0}
};
static const DemoMsg4 sMsg_d27_s4_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 3, 29, 3, {5248, 512, 640, 0}
};
static const DemoMsg4 sMsg_d27_s4_2 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 2, 4, {5248, 512, 640, 20}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d27_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg4 sMsg_d27_s5_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 6, 3, {4224, 512, 640, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d27_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 7 -- */
static const DemoMsg0 sMsg_d27_s7_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 8 -- */
static const DemoMsg4 sMsg_d27_s8_0 = {
    0xBA4B, CLS_BOSS, WAIT, 3, 13, 3, {4352, 512, 640, 0}
};
static const DemoMsg4 sMsg_d27_s8_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 4, 2, 4, {4352, 512, 640, 20}
};
static const DemoMsg2 sMsg_d27_s8_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {834, 0}
};
static const DemoMsg2 sMsg_d27_s8_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 1, 1, {76, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d27_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d27_s9_1 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 14, 1, {0, 0}
};
/* -- step 10 -- */
static const DemoMsg4 sMsg_d27_s10_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 16, 3, {5, 80, 1, 0}
};
static const DemoMsg2 sMsg_d27_s10_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {230, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d27_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
/* -- step 12 -- */
static const DemoMsg4 sMsg_d27_s12_0 = {
    0xBA4B, CLS_BOSS, WAIT, 0, 4, 3, {3968, 512, 640, 0}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d27_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d27_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {3, 0}
};
static const DemoMsg2 sMsg_d27_s14_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {541, 0}
};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d27_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 16 -- */
static const DemoMsg0 sMsg_d27_s16_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d27_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 18 -- */
static const DemoMsg0 sMsg_d27_s18_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d27_s19_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 20 -- */
static const DemoMsg0 sMsg_d27_s20_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 21 -- */
static const DemoMsg4 sMsg_d27_s21_0 = {
    0x2B06, CLS_PLAYER, WAIT, 1, 29, 3, {4608, 512, 640, 0}
};
static const DemoMsg2 sMsg_d27_s21_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {35, 0}
};
/* -- step 22 -- */
static const DemoMsg2 sMsg_d27_s22_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {10, 0}
};
/* -- step 23 -- */
static const DemoMsg2 sMsg_d27_s23_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {13, 0}
};
static const DemoMsg2 sMsg_d27_s23_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 23, 1, {30, 0}
};
static const DemoMsg4 sMsg_d27_s23_2 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 13, 3, {2800, 512, 640, 0}
};
/* -- step 24 -- */
static const DemoMsg2 sMsg_d27_s24_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {13, 0}
};
static const DemoMsg2 sMsg_d27_s24_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 23, 1, {30, 0}
};
/* -- step 25 -- */
static const DemoMsg2 sMsg_d27_s25_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {13, 0}
};
static const DemoMsg2 sMsg_d27_s25_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 23, 1, {30, 0}
};
static const DemoMsg0 sMsg_d27_s25_2 = {0xBA4B, CLS_BOSS, NOWAIT, 3, 0, 0};
/* -- step 26 -- */
static const DemoMsg2 sMsg_d27_s26_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-4107, 0}
};
/* -- step 27 -- */
static const DemoMsg0 sMsg_d27_s27_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 28 -- */
static const DemoMsg4 sMsg_d27_s28_0 = {
    0x2B06, CLS_PLAYER, WAIT, 3, 6, 3, {3712, 512, 640, 0}
};
/* -- step 29 -- */
static const DemoMsg2 sMsg_d27_s29_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg0 sMsg_d27_s29_1 = {0x2B06, CLS_PLAYER, NOWAIT, 3, 0, 0};
/* -- step 30 -- */
static const DemoMsg2 sMsg_d27_s30_0 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 13, 1, {5, 0}
};
static const DemoMsg2 sMsg_d27_s30_1 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 5, 1, {15, 0}
};
/* ================ demo 28  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d28_s0_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {1152, 512, 4736, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d28_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d28_s1_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
static const DemoMsg2 sMsg_d28_s1_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {0, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d28_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {25, 0}
};
static const DemoMsg4 sMsg_d28_s2_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {640, 1280, 3500, 60}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d28_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg10 sMsg_d28_s3_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* -- step 4 -- */
static const DemoMsg4 sMsg_d28_s4_0 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 1, 3, {1280, 1792, 1408, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d28_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg4 sMsg_d28_s5_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1176, 2048, 1152, 60}
};
static const DemoMsg4 sMsg_d28_s5_2 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 6, 3, {1664, 2048, 640, 0}
};
static const DemoMsg10 sMsg_d28_s5_3 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {0, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* -- step 6 -- */
static const DemoMsg4 sMsg_d28_s6_0 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 6, 3, {1664, 2048, 640, 0}
};
static const DemoMsg4 sMsg_d28_s6_1 = {
    0xBA4B, CLS_BOSS, WAIT, 1, 13, 3, {384, 2048, 1152, 0}
};
/* -- step 7 -- */
static const DemoMsg4 sMsg_d28_s7_0 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1176, 2048, 1152, 60}
};
static const DemoMsg4 sMsg_d28_s7_1 = {
    0x2B06, CLS_PLAYER, WAIT, 1, 6, 3, {1664, 2048, 640, 0}
};
static const DemoMsg0 sMsg_d28_s7_2 = {0xBA4B, CLS_BOSS, NOWAIT, 1, 0, 0};
/* -- step 8 -- */
static const DemoMsg4 sMsg_d28_s8_0 = {
    0x2B06, CLS_PLAYER, WAIT, 1, 6, 3, {640, 2048, 1152, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d28_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
static const DemoMsg4 sMsg_d28_s9_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 6, 3, {384, 2048, 1152, 0}
};
/* -- step 10 -- */
static const DemoMsg2 sMsg_d28_s10_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg10 sMsg_d28_s10_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 29  (36 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d29_s0_0 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 11, 1, {7, 0}
};
static const DemoMsg4 sMsg_d29_s0_1 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3968, 512, 2688, 0}
};
static const DemoMsg0 sMsg_d29_s0_2 = {0x0074, CLS_BOSS, NOWAIT, 0, 0, 0};
static const DemoMsg2 sMsg_d29_s0_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
/* -- step 1 -- */
static const DemoMsg4 sMsg_d29_s1_0 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 2, 4, {3700, 512, 2688, 35}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d29_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
static const DemoMsg2 sMsg_d29_s2_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {64, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d29_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {29146, 0}
};
/* -- step 4 -- */
static const DemoMsg0 sMsg_d29_s4_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d29_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d29_s5_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 12, 1, {7, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d29_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {29146, 0}
};
/* -- step 7 -- */
static const DemoMsg0 sMsg_d29_s7_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d29_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg0 sMsg_d29_s8_1 = {0xBA4B, CLS_BOSS, NOWAIT, 0, 18, 0};
static const DemoMsg2 sMsg_d29_s8_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {835, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d29_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d29_s9_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
static const DemoMsg2 sMsg_d29_s9_2 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 28, 1, {0, 0}
};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d29_s10_0 = {0xBA4B, CLS_BOSS, WAIT, 0, 27, 0};
static const DemoMsg2 sMsg_d29_s10_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {812, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d29_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
/* -- step 12 -- */
static const DemoMsg2 sMsg_d29_s12_0 = {
    0xBA4B, CLS_BOSS, WAIT, 0, 5, 1, {3, 0}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d29_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {29146, 0}
};
/* -- step 14 -- */
static const DemoMsg0 sMsg_d29_s14_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d29_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg0 sMsg_d29_s15_1 = {0xBA4B, CLS_BOSS, NOWAIT, 0, 28, 0};
static const DemoMsg2 sMsg_d29_s15_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {801, 0}
};
/* -- step 16 -- */
static const DemoMsg2 sMsg_d29_s16_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {29146, 0}
};
/* -- step 17 -- */
static const DemoMsg0 sMsg_d29_s17_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 18 -- */
static const DemoMsg2 sMsg_d29_s18_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg0 sMsg_d29_s18_1 = {0xBA4B, CLS_BOSS, NOWAIT, 0, 29, 0};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d29_s19_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg8 sMsg_d29_s19_1 = {
    0x51E2, CLS_ACTOR, NOWAIT, 3, 27, 7, {3200, 640, 2688, 3968, 640, 2944, 60, 0}
};
static const DemoMsg2 sMsg_d29_s19_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {802, 0}
};
/* -- step 20 -- */
static const DemoMsg4 sMsg_d29_s20_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3968, 512, 2944, 0}
};
/* -- step 21 -- */
static const DemoMsg2 sMsg_d29_s21_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {10, 0}
};
static const DemoMsg2 sMsg_d29_s21_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
/* -- step 22 -- */
static const DemoMsg2 sMsg_d29_s22_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg0 sMsg_d29_s22_1 = {0x51E2, CLS_ACTOR, NOWAIT, 3, 0, 0};
static const DemoMsg2 sMsg_d29_s22_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {803, 0}
};
static const DemoMsg2 sMsg_d29_s22_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {811, 0}
};
/* -- step 23 -- */
static const DemoMsg2 sMsg_d29_s23_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
/* -- step 24 -- */
static const DemoMsg2 sMsg_d29_s24_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg0 sMsg_d29_s24_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 45, 0};
static const DemoMsg2 sMsg_d29_s24_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {446, 0}
};
/* -- step 25 -- */
static const DemoMsg2 sMsg_d29_s25_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {90, 0}
};
static const DemoMsg2 sMsg_d29_s25_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
static const DemoMsg2 sMsg_d29_s25_2 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 28, 1, {0, 0}
};
/* -- step 26 -- */
static const DemoMsg2 sMsg_d29_s26_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d29_s26_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {802, 0}
};
static const DemoMsg8 sMsg_d29_s26_2 = {
    0x51E2, CLS_ACTOR, NOWAIT, 3, 27, 7, {3968, 640, 2944, 4096, 640, 2368, 60, 0}
};
static const DemoMsg4 sMsg_d29_s26_3 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 29, 3, {4096, 512, 2368, 0}
};
static const DemoMsg2 sMsg_d29_s26_4 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 27 -- */
static const DemoMsg2 sMsg_d29_s27_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {10, 0}
};
static const DemoMsg0 sMsg_d29_s27_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 46, 0};
static const DemoMsg2 sMsg_d29_s27_2 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 3, 1, {6, 0}
};
static const DemoMsg2 sMsg_d29_s27_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {361, 0}
};
/* -- step 28 -- */
static const DemoMsg2 sMsg_d29_s28_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg0 sMsg_d29_s28_1 = {0xF5EB, CLS_PLAYER, NOWAIT, 0, 0, 0};
static const DemoMsg2 sMsg_d29_s28_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {773, 0}
};
static const DemoMsg2 sMsg_d29_s28_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {448, 0}
};
/* -- step 29 -- */
static const DemoMsg2 sMsg_d29_s29_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 30 -- */
static const DemoMsg2 sMsg_d29_s30_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {100, 0}
};
static const DemoMsg0 sMsg_d29_s30_1 = {0x51E2, CLS_ACTOR, NOWAIT, 3, 0, 0};
static const DemoMsg2 sMsg_d29_s30_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 1, 1, {76, 0}
};
/* -- step 31 -- */
static const DemoMsg2 sMsg_d29_s31_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg0 sMsg_d29_s31_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 47, 0};
static const DemoMsg2 sMsg_d29_s31_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {447, 0}
};
static const DemoMsg2 sMsg_d29_s31_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {772, 0}
};
/* -- step 32 -- */
static const DemoMsg2 sMsg_d29_s32_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {29146, 0}
};
/* -- step 33 -- */
static const DemoMsg0 sMsg_d29_s33_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 34 -- */
static const DemoMsg2 sMsg_d29_s34_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d29_s34_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg4 sMsg_d29_s34_2 = {
    0xBA4B, CLS_BOSS, NOWAIT, 0, 13, 3, {2944, 512, 1152, 0}
};
/* -- step 35 -- */
static const DemoMsg2 sMsg_d29_s35_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg10 sMsg_d29_s35_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 0, 0, 0, 1, 1, 1, 0, 0}
};
static const DemoMsg2 sMsg_d29_s35_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {8, 0}
};
static const DemoMsg0 sMsg_d29_s35_3 = {0xBA4B, CLS_BOSS, NOWAIT, 0, 0, 0};
/* ================ demo 30  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d30_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d30_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 6, 1, {113, 0}
};
static const DemoMsg2 sMsg_d30_s0_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {69, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d30_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg0 sMsg_d30_s1_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 51, 0};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d30_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {14758, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d30_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d30_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {100, 0}
};
static const DemoMsg10 sMsg_d30_s4_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 31, 31, 31, 1, 1, 1, 0, 0}
};
static const DemoMsg0 sMsg_d30_s4_2 = {0x0074, CLS_BOSS, NOWAIT, 0, 48, 0};
static const DemoMsg2 sMsg_d30_s4_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 0, 1, {445, 0}
};
static const DemoMsg2 sMsg_d30_s4_4 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 0, 1, {732, 0}
};
static const DemoMsg2 sMsg_d30_s4_5 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 9, 1, {8, 0}
};
/* ================ demo 31  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d31_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg0 sMsg_d31_s0_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 50, 0};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d31_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {606, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d31_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d31_s3_0 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 13, 1, {7, 0}
};
static const DemoMsg4 sMsg_d31_s3_1 = {
    0xD23E, CLS_CAMERA, WAIT, 0, 2, 4, {1750, 406, 2090, 60}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d31_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {606, 0}
};
/* -- step 5 -- */
static const DemoMsg0 sMsg_d31_s5_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d31_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {40, 0}
};
static const DemoMsg0 sMsg_d31_s6_1 = {0x0074, CLS_BOSS, NOWAIT, 0, 49, 0};
static const DemoMsg2 sMsg_d31_s6_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d31_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {90, 0}
};
static const DemoMsg2 sMsg_d31_s7_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d31_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {120, 0}
};
static const DemoMsg2 sMsg_d31_s8_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {641, 0}
};
static const DemoMsg10 sMsg_d31_s8_2 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 31, 31, 31, 1, 1, 1, 0, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d31_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d31_s9_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {36, 0}
};
/* ================ demo 32  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d32_s0_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {2176, 256, 2944, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d32_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
/* -- step 2 -- */
static const DemoMsg4 sMsg_d32_s2_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {3200, 256, 2688, 80}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d32_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
/* -- step 4 -- */
static const DemoMsg4 sMsg_d32_s4_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2688, 256, 2176, 60}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d32_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d32_s6_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {50, 0}
};
/* ================ demo 33  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d33_s0_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2944, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d33_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d33_s1_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d33_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-12531, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d33_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg4 sMsg_d33_s4_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2176, 256, 2688, 80}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d33_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
/* -- step 6 -- */
static const DemoMsg4 sMsg_d33_s6_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2688, 256, 2176, 60}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d33_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d33_s8_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {50, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d33_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-12531, 0}
};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d33_s10_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* ================ demo 34  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d34_s0_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2944, 0}
};
/* -- step 1 -- */
static const DemoMsg4 sMsg_d34_s1_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2688, 256, 2944, 60}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d34_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d34_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d34_s3_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 5, 1, {7, 0}
};
static const DemoMsg2 sMsg_d34_s3_2 = {
    0xBF31, CLS_PLAYER, NOWAIT, 0, 5, 1, {3, 0}
};
/* -- step 4 -- */
static const DemoMsg4 sMsg_d34_s4_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2688, 0}
};
static const DemoMsg4 sMsg_d34_s4_1 = {
    0xBF31, CLS_PLAYER, NOWAIT, 0, 6, 3, {2176, 256, 2688, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d34_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 6 -- */
static const DemoMsg0 sMsg_d34_s6_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d34_s7_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {60, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d34_s8_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d34_s8_1 = {
    0xBF31, CLS_PLAYER, NOWAIT, 0, 3, 1, {3, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d34_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d34_s10_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 11 -- */
static const DemoMsg4 sMsg_d34_s11_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2176, 256, 2688, 60}
};
/* -- step 12 -- */
static const DemoMsg2 sMsg_d34_s12_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {110, 0}
};
static const DemoMsg4 sMsg_d34_s12_1 = {
    0xBF31, CLS_PLAYER, NOWAIT, 0, 28, 3, {4, 120, 120, 0}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d34_s13_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {60, 0}
};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d34_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 15 -- */
static const DemoMsg0 sMsg_d34_s15_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 16 -- */
static const DemoMsg4 sMsg_d34_s16_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2944, 0}
};
/* -- step 17 -- */
static const DemoMsg4 sMsg_d34_s17_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {2688, 256, 2944, 0}
};
/* -- step 18 -- */
static const DemoMsg4 sMsg_d34_s18_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {2688, 256, 1920, 0}
};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d34_s19_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 3, 1, {5, 0}
};
/* ================ demo 35  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d35_s0_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {2176, 256, 2944, 0}
};
/* -- step 1 -- */
static const DemoMsg4 sMsg_d35_s1_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {2688, 256, 2944, 60}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d35_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d35_s3_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d35_s3_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {3, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d35_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d35_s4_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 5, 1, {7, 0}
};
static const DemoMsg2 sMsg_d35_s4_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 5, 1, {3, 0}
};
/* -- step 5 -- */
static const DemoMsg4 sMsg_d35_s5_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2688, 0}
};
static const DemoMsg4 sMsg_d35_s5_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 6, 3, {2176, 256, 2688, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d35_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 7 -- */
static const DemoMsg0 sMsg_d35_s7_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 8 -- */
static const DemoMsg4 sMsg_d35_s8_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {3200, 256, 2688, 60}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d35_s9_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d35_s9_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {3, 0}
};
/* -- step 10 -- */
static const DemoMsg2 sMsg_d35_s10_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 11 -- */
static const DemoMsg0 sMsg_d35_s11_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 12 -- */
static const DemoMsg2 sMsg_d35_s12_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {60, 0}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d35_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {110, 0}
};
static const DemoMsg4 sMsg_d35_s13_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 3, {4, 120, 120, 0}
};
/* -- step 14 -- */
static const DemoMsg4 sMsg_d35_s14_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 2, 4, {3200, 256, 2688, 60}
};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d35_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {31008, 0}
};
/* -- step 16 -- */
static const DemoMsg0 sMsg_d35_s16_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 17 -- */
static const DemoMsg4 sMsg_d35_s17_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 6, 3, {3200, 256, 2944, 0}
};
/* -- step 18 -- */
static const DemoMsg4 sMsg_d35_s18_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 6, 3, {2688, 256, 2944, 0}
};
/* -- step 19 -- */
static const DemoMsg4 sMsg_d35_s19_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 6, 3, {2688, 256, 1920, 0}
};
/* -- step 20 -- */
static const DemoMsg2 sMsg_d35_s20_0 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 3, 1, {5, 0}
};
static const DemoMsg2 sMsg_d35_s20_1 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {60, 0}
};
/* ================ demo 36  (24 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d36_s0_0 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 6, 3, {2560, 1280, 2176, 0}
};
static const DemoMsg4 sMsg_d36_s0_1 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {2816, 1280, 2176, 0}
};
static const DemoMsg2 sMsg_d36_s0_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
static const DemoMsg2 sMsg_d36_s0_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 8, 1, {6, 0}
};
static const DemoMsg4 sMsg_d36_s0_4 = {
    0x56CB, CLS_CAMERA, NOWAIT, 0, 2, 4, {2896, 1430, 2086, 60}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d36_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d36_s1_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {64, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d36_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d36_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d36_s4_0 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {543, 0}
};
static const DemoMsg2 sMsg_d36_s4_1 = {
    0x730A, CLS_FADE, WAIT, 9, 5, 2, {30, 15}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d36_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 6 -- */
static const DemoMsg0 sMsg_d36_s6_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d36_s7_0 = {
    0xBA4B, CLS_BOSS, WAIT, 0, 5, 1, {5, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d36_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 9 -- */
static const DemoMsg0 sMsg_d36_s9_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 10 -- */
static const DemoMsg2 sMsg_d36_s10_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {140, 0}
};
static const DemoMsg4 sMsg_d36_s10_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 28, 3, {4, 140, 140, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d36_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 12 -- */
static const DemoMsg0 sMsg_d36_s12_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d36_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d36_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 15 -- */
static const DemoMsg0 sMsg_d36_s15_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 16 -- */
static const DemoMsg2 sMsg_d36_s16_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {100, 0}
};
static const DemoMsg2 sMsg_d36_s16_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 0, 35, 1, {1, 0}
};
static const DemoMsg2 sMsg_d36_s16_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {742, 0}
};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d36_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 18 -- */
static const DemoMsg0 sMsg_d36_s18_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d36_s19_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d36_s19_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {1, 0}
};
/* -- step 20 -- */
static const DemoMsg10 sMsg_d36_s20_0 = {
    0x730A, CLS_FADE, WAIT, 0, 2, 9, {1, 5, 31, 31, 31, 1, 1, 1, 0, 0}
};
static const DemoMsg2 sMsg_d36_s20_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {641, 0}
};
/* -- step 21 -- */
static const DemoMsg2 sMsg_d36_s21_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8751, 0}
};
/* -- step 22 -- */
static const DemoMsg0 sMsg_d36_s22_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 23 -- */
static const DemoMsg10 sMsg_d36_s23_0 = {
    0x730A, CLS_FADE, WAIT, 0, 2, 9, {1, 0, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 37  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d37_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d37_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d37_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {10, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d37_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8986, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d37_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d37_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-8986, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d37_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {36, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d37_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
static const DemoMsg0 sMsg_d37_s6_1 = {0xBA4B, CLS_BOSS, NOWAIT, 0, 0, 0};
/* ================ demo 38  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d38_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d38_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {71, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d38_s1_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 3, 1, {1, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d38_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {120, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d38_s3_0 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {544, 0}
};
static const DemoMsg2 sMsg_d38_s3_1 = {
    0x730A, CLS_FADE, WAIT, 9, 5, 2, {30, 15}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d38_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d38_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-10795, 0}
};
/* -- step 6 -- */
static const DemoMsg0 sMsg_d38_s6_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d38_s7_0 = {
    0x2B06, CLS_PLAYER, WAIT, 0, 20, 1, {1, 0}
};
static const DemoMsg2 sMsg_d38_s7_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d38_s8_0 = {
    0x56CB, CLS_CAMERA, WAIT, 0, 5, 1, {30, 0}
};
/* ================ demo 39  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d39_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d39_s0_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {5, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d39_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d39_s1_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 6, 1, {5, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d39_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d39_s2_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {7, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d39_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d39_s3_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {5, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d39_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d39_s4_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {3, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d39_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d39_s5_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {5, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d39_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-30336, 0}
};
/* -- step 7 -- */
static const DemoMsg0 sMsg_d39_s7_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d39_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d39_s8_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {3, 0}
};
static const DemoMsg2 sMsg_d39_s8_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d39_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-30336, 0}
};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d39_s10_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d39_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg0 sMsg_d39_s11_1 = {0x9CFE, CLS_ACTOR, NOWAIT, 0, 7, 0};
/* ================ demo 40  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d40_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg0 sMsg_d40_s0_1 = {0x6740, CLS_ACTOR, NOWAIT, 0, 33, 0};
static const DemoMsg2 sMsg_d40_s0_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d40_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d40_s1_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {734, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d40_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 2, {122, 260}
};
static const DemoMsg0 sMsg_d40_s2_1 = {0x6740, CLS_ACTOR, NOWAIT, 0, 33, 0};
static const DemoMsg2 sMsg_d40_s2_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {158, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d40_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {138, 0}
};
static const DemoMsg2 sMsg_d40_s3_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {735, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d40_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg2 sMsg_d40_s4_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
static const DemoMsg10 sMsg_d40_s4_2 = {
    0x730A, CLS_FADE, NOWAIT, 9, 2, 9, {1, 5, 0, 0, 0, 1, 1, 0, 0, 0}
};
static const DemoMsg2 sMsg_d40_s4_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {736, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d40_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg2 sMsg_d40_s5_1 = {
    0x6740, CLS_ACTOR, NOWAIT, 0, 1, 1, {1, 0}
};
/* ================ demo 41  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d41_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d41_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d41_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d41_s1_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {158, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d41_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8111, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d41_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d41_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {10, 0}
};
static const DemoMsg2 sMsg_d41_s4_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {738, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d41_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg10 sMsg_d41_s5_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {0, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
static const DemoMsg2 sMsg_d41_s5_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {809, 0}
};
/* -- step 6 -- */
static const DemoMsg0 sMsg_d41_s6_0 = {0x45E5, CLS_ENEMY, WAIT, 0, 4, 0};
static const DemoMsg0 sMsg_d41_s6_1 = {0x45E6, CLS_ENEMY, NOWAIT, 0, 4, 0};
static const DemoMsg0 sMsg_d41_s6_2 = {0x45E7, CLS_ENEMY, NOWAIT, 0, 4, 0};
static const DemoMsg0 sMsg_d41_s6_3 = {0x45E8, CLS_ENEMY, NOWAIT, 0, 4, 0};
/* -- step 7 -- */
static const DemoMsg0 sMsg_d41_s7_0 = {0x3DB5, CLS_ACTOR, WAIT, 0, 18, 0};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d41_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8111, 0}
};
/* -- step 9 -- */
static const DemoMsg0 sMsg_d41_s9_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 10 -- */
static const DemoMsg2 sMsg_d41_s10_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d41_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {180, 0}
};
static const DemoMsg0 sMsg_d41_s11_1 = {0x45E5, CLS_ENEMY, NOWAIT, 0, 5, 0};
static const DemoMsg0 sMsg_d41_s11_2 = {0x45E6, CLS_ENEMY, NOWAIT, 0, 5, 0};
static const DemoMsg0 sMsg_d41_s11_3 = {0x45E7, CLS_ENEMY, NOWAIT, 0, 5, 0};
static const DemoMsg0 sMsg_d41_s11_4 = {0x45E8, CLS_ENEMY, NOWAIT, 0, 5, 0};
/* -- step 12 -- */
static const DemoMsg0 sMsg_d41_s12_0 = {0x3DB5, CLS_ACTOR, WAIT, 0, 19, 0};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d41_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8111, 0}
};
/* -- step 14 -- */
static const DemoMsg0 sMsg_d41_s14_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d41_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg10 sMsg_d41_s15_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 0, 0, 0, 1, 0, 0, 64, 0}
};
/* -- step 16 -- */
static const DemoMsg2 sMsg_d41_s16_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d41_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {105, 0}
};
static const DemoMsg2 sMsg_d41_s17_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {792, 0}
};
/* -- step 18 -- */
static const DemoMsg2 sMsg_d41_s18_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8111, 0}
};
/* -- step 19 -- */
static const DemoMsg0 sMsg_d41_s19_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 20 -- */
static const DemoMsg2 sMsg_d41_s20_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg2 sMsg_d41_s20_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
/* ================ demo 42  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d42_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d42_s0_1 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 2, 1, {1, 0}
};
static const DemoMsg2 sMsg_d42_s0_2 = {
    0xF153, CLS_ENEMY, NOWAIT, 0, 6, 2, {-2417, 256}
};
static const DemoMsg2 sMsg_d42_s0_3 = {
    0xF154, CLS_ENEMY, NOWAIT, 0, 6, 2, {-2417, 256}
};
static const DemoMsg2 sMsg_d42_s0_4 = {
    0xF155, CLS_ENEMY, NOWAIT, 0, 6, 2, {-2417, 256}
};
static const DemoMsg2 sMsg_d42_s0_5 = {
    0xF156, CLS_ENEMY, NOWAIT, 0, 6, 2, {-2417, 256}
};
static const DemoMsg2 sMsg_d42_s0_6 = {
    0xF157, CLS_ENEMY, NOWAIT, 0, 6, 2, {-2417, 256}
};
static const DemoMsg2 sMsg_d42_s0_7 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {4, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d42_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg0 sMsg_d42_s1_1 = {0x8E9F, CLS_ACTOR, NOWAIT, 0, 36, 0};
static const DemoMsg0 sMsg_d42_s1_2 = {0xE6ED, CLS_ENEMY, NOWAIT, 0, 4, 0};
static const DemoMsg0 sMsg_d42_s1_3 = {0xDDEE, CLS_ENEMY, NOWAIT, 0, 4, 0};
static const DemoMsg2 sMsg_d42_s1_4 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {158, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d42_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg0 sMsg_d42_s2_1 = {0xDDEE, CLS_ENEMY, NOWAIT, 0, 4, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d42_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {90, 0}
};
static const DemoMsg2 sMsg_d42_s3_1 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 2, 1, {1, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d42_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8112, 0}
};
/* -- step 5 -- */
static const DemoMsg0 sMsg_d42_s5_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d42_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d42_s6_1 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 10, 1, {0, 0}
};
static const DemoMsg2 sMsg_d42_s6_2 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 2, 1, {7, 0}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d42_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg4 sMsg_d42_s7_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1152, 256, 1152, 30}
};
static const DemoMsg2 sMsg_d42_s7_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {967, 0}
};
/* -- step 8 -- */
static const DemoMsg4 sMsg_d42_s8_0 = {
    0xF68F, CLS_ACTOR, WAIT, 0, 3, 3, {1280, 256, 1164, 0}
};
static const DemoMsg2 sMsg_d42_s8_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {201, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d42_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 10 -- */
static const DemoMsg4 sMsg_d42_s10_0 = {
    0xF68F, CLS_ACTOR, WAIT, 0, 3, 3, {1024, 256, 1164, 0}
};
static const DemoMsg2 sMsg_d42_s10_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {968, 0}
};
static const DemoMsg2 sMsg_d42_s10_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {201, 0}
};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d42_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 12 -- */
static const DemoMsg4 sMsg_d42_s12_0 = {
    0xF68F, CLS_ACTOR, WAIT, 0, 3, 3, {1152, 256, 1164, 0}
};
static const DemoMsg2 sMsg_d42_s12_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {201, 0}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d42_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d42_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
static const DemoMsg4 sMsg_d42_s14_1 = {
    0xF68F, CLS_ACTOR, NOWAIT, 0, 3, 3, {1024, 256, 1164, 0}
};
static const DemoMsg2 sMsg_d42_s14_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {201, 0}
};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d42_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg4 sMsg_d42_s15_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {2432, 256, 1408, 30}
};
/* -- step 16 -- */
static const DemoMsg2 sMsg_d42_s16_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {140, 0}
};
static const DemoMsg4 sMsg_d42_s16_1 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 10, 3, {4, 130, 130, 0}
};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d42_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8112, 0}
};
/* -- step 18 -- */
static const DemoMsg0 sMsg_d42_s18_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d42_s19_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg4 sMsg_d42_s19_1 = {
    0x8E9F, CLS_ACTOR, NOWAIT, 0, 3, 3, {1152, 256, 1152, 0}
};
/* -- step 20 -- */
static const DemoMsg2 sMsg_d42_s20_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg2 sMsg_d42_s20_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {6, 0}
};
static const DemoMsg10 sMsg_d42_s20_2 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 43  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d43_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {15, 0}
};
static const DemoMsg2 sMsg_d43_s0_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {1, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d43_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d43_s1_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 6, 1, {1, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d43_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8443, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d43_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d43_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d43_s4_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {3, 0}
};
static const DemoMsg2 sMsg_d43_s4_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d43_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {8443, 0}
};
/* -- step 6 -- */
static const DemoMsg0 sMsg_d43_s6_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d43_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg4 sMsg_d43_s7_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 6, 3, {1664, 1024, 128, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d43_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg4 sMsg_d43_s8_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 3, 3, {1664, 1024, 384, 0}
};
static const DemoMsg10 sMsg_d43_s8_2 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 44  (26 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4 sMsg_d44_s0_0 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 3, 3, {1152, 256, 1664, 0}
};
static const DemoMsg4 sMsg_d44_s0_1 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 6, 3, {1408, 256, 1664, 0}
};
static const DemoMsg2 sMsg_d44_s0_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {5, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d44_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg4 sMsg_d44_s1_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1408, 256, 1664, 120}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d44_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d44_s2_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {3, 0}
};
static const DemoMsg2 sMsg_d44_s2_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d44_s2_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 6, 1, {110, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d44_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d44_s3_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {1, 0}
};
static const DemoMsg2 sMsg_d44_s3_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {1, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d44_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d44_s4_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {7, 0}
};
static const DemoMsg2 sMsg_d44_s4_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {3, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d44_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d44_s5_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {1, 0}
};
static const DemoMsg2 sMsg_d44_s5_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {1, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d44_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {25, 0}
};
static const DemoMsg2 sMsg_d44_s6_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {3, 0}
};
static const DemoMsg2 sMsg_d44_s6_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {7, 0}
};
static const DemoMsg2 sMsg_d44_s6_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {560, 0}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d44_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d44_s7_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 1, {1, 0}
};
static const DemoMsg2 sMsg_d44_s7_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 1, {1, 0}
};
static const DemoMsg2 sMsg_d44_s7_3 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 10, 1, {0, 0}
};
static const DemoMsg2 sMsg_d44_s7_4 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d44_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
static const DemoMsg4 sMsg_d44_s8_1 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1186, 256, 1094, 60}
};
static const DemoMsg0 sMsg_d44_s8_2 = {0xD37F, CLS_BOSS, NOWAIT, 0, 38, 0};
/* -- step 9 -- */
static const DemoMsg0 sMsg_d44_s9_0 = {0xD37F, CLS_BOSS, WAIT, 0, 39, 0};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d44_s10_0 = {0xD37F, CLS_BOSS, WAIT, 0, 40, 0};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d44_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg2 sMsg_d44_s11_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 9, 1, {5, 0}
};
/* -- step 12 -- */
static const DemoMsg2 sMsg_d44_s12_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {120, 0}
};
static const DemoMsg0 sMsg_d44_s12_1 = {0xD37F, CLS_BOSS, NOWAIT, 0, 18, 0};
static const DemoMsg2 sMsg_d44_s12_2 = {
    0x730A, CLS_FADE, NOWAIT, 9, 5, 2, {-1, 6}
};
/* -- step 13 -- */
static const DemoMsg2 sMsg_d44_s13_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {20, 0}
};
static const DemoMsg2 sMsg_d44_s13_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {48, 0}
};
/* -- step 14 -- */
static const DemoMsg2 sMsg_d44_s14_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
static const DemoMsg0 sMsg_d44_s14_1 = {0x730A, CLS_FADE, NOWAIT, 9, 6, 0};
/* -- step 15 -- */
static const DemoMsg2 sMsg_d44_s15_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-31921, 0}
};
/* -- step 16 -- */
static const DemoMsg0 sMsg_d44_s16_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 17 -- */
static const DemoMsg2 sMsg_d44_s17_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg0 sMsg_d44_s17_1 = {0xD37F, CLS_BOSS, NOWAIT, 0, 41, 0};
static const DemoMsg4 sMsg_d44_s17_2 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1216, 256, 1344, 60}
};
/* -- step 18 -- */
static const DemoMsg4 sMsg_d44_s18_0 = {
    0x9CFE, CLS_ACTOR, WAIT, 0, 3, 3, {896, 256, 1664, 0}
};
static const DemoMsg4 sMsg_d44_s18_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 6, 3, {1664, 256, 1664, 0}
};
/* -- step 19 -- */
static const DemoMsg2 sMsg_d44_s19_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {50, 0}
};
static const DemoMsg4 sMsg_d44_s19_1 = {
    0x9CFE, CLS_ACTOR, NOWAIT, 0, 2, 3, {1, 256, 1664, 0}
};
static const DemoMsg4 sMsg_d44_s19_2 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 3, 3, {1, 256, 1664, 0}
};
/* -- step 20 -- */
static const DemoMsg2 sMsg_d44_s20_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
static const DemoMsg2 sMsg_d44_s20_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {560, 0}
};
/* -- step 21 -- */
static const DemoMsg2 sMsg_d44_s21_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {-31921, 0}
};
/* -- step 22 -- */
static const DemoMsg0 sMsg_d44_s22_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 23 -- */
static const DemoMsg2 sMsg_d44_s23_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg0 sMsg_d44_s23_1 = {0x9CFE, CLS_ACTOR, NOWAIT, 0, 8, 0};
static const DemoMsg4 sMsg_d44_s23_2 = {
    0xD23E, CLS_CAMERA, NOWAIT, 0, 2, 4, {1152, 256, 1664, 30}
};
static const DemoMsg2 sMsg_d44_s23_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {349, 0}
};
/* -- step 24 -- */
static const DemoMsg2 sMsg_d44_s24_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {150, 0}
};
static const DemoMsg2 sMsg_d44_s24_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {487, 0}
};
/* -- step 25 -- */
static const DemoMsg2 sMsg_d44_s25_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg10 sMsg_d44_s25_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 5, 31, 31, 31, 1, 1, 1, 0, 0}
};
static const DemoMsg2 sMsg_d44_s25_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {641, 0}
};
/* ================ demo 45  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d45_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d45_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 5, 1, {5, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d45_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25114, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d45_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d45_s3_0 = {
    0xF5EB, CLS_PLAYER, WAIT, 0, 10, 1, {1, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d45_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {200, 0}
};
static const DemoMsg2 sMsg_d45_s4_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 6, 1, {110, 0}
};
/* -- step 5 -- */
static const DemoMsg2 sMsg_d45_s5_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {40, 0}
};
static const DemoMsg0 sMsg_d45_s5_1 = {0xD37F, CLS_BOSS, NOWAIT, 0, 43, 0};
static const DemoMsg2 sMsg_d45_s5_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {560, 0}
};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d45_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
static const DemoMsg2 sMsg_d45_s6_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 28, 1, {0, 0}
};
/* -- step 7 -- */
static const DemoMsg2 sMsg_d45_s7_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {40, 0}
};
static const DemoMsg2 sMsg_d45_s7_1 = {
    0xF5EB, CLS_PLAYER, NOWAIT, 0, 13, 1, {1, 0}
};
/* -- step 8 -- */
static const DemoMsg2 sMsg_d45_s8_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {100, 0}
};
static const DemoMsg0 sMsg_d45_s8_1 = {0xF5EB, CLS_PLAYER, NOWAIT, 0, 0, 0};
static const DemoMsg2 sMsg_d45_s8_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 9, 1, {3, 0}
};
static const DemoMsg2 sMsg_d45_s8_3 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {48, 0}
};
/* -- step 9 -- */
static const DemoMsg2 sMsg_d45_s9_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25114, 0}
};
/* -- step 10 -- */
static const DemoMsg0 sMsg_d45_s10_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 11 -- */
static const DemoMsg2 sMsg_d45_s11_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg10 sMsg_d45_s11_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 46  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d46_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d46_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d46_s1_1 = {
    0x3DB5, CLS_ACTOR, NOWAIT, 0, 10, 1, {0, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d46_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d46_s2_1 = {
    0x3DB5, CLS_ACTOR, NOWAIT, 0, 1, 1, {1, 0}
};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d46_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {80, 0}
};
static const DemoMsg2 sMsg_d46_s3_1 = {
    0x51E2, CLS_ACTOR, NOWAIT, 0, 2, 1, {7, 0}
};
static const DemoMsg2 sMsg_d46_s3_2 = {
    0x6773, CLS_ACTOR, NOWAIT, 0, 2, 1, {7, 0}
};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d46_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25115, 0}
};
/* -- step 5 -- */
static const DemoMsg0 sMsg_d46_s5_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 6 -- */
static const DemoMsg2 sMsg_d46_s6_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
static const DemoMsg10 sMsg_d46_s6_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 0, 0, 0, 1, 1, 1, 0, 0}
};
/* ================ demo 47  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d47_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d47_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {60, 0}
};
static const DemoMsg2 sMsg_d47_s1_1 = {
    0x2B06, CLS_PLAYER, NOWAIT, 1, 12, 1, {1, 0}
};
/* -- step 2 -- */
static const DemoMsg2 sMsg_d47_s2_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25116, 0}
};
/* -- step 3 -- */
static const DemoMsg0 sMsg_d47_s3_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 4 -- */
static const DemoMsg2 sMsg_d47_s4_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {240, 0}
};
static const DemoMsg10 sMsg_d47_s4_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 8, 0, 0, 0, 1, 1, 1, 64, 0}
};
static const DemoMsg2 sMsg_d47_s4_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 4, 1, {12, 0}
};
/* ================ demo 48  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d48_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {5, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d48_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25117, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d48_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d48_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
/* ================ demo 49  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2 sMsg_d49_s0_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {30, 0}
};
static const DemoMsg2 sMsg_d49_s0_1 = {
    0x74E2, CLS_SOUND, NOWAIT, 0, 2, 1, {158, 0}
};
/* -- step 1 -- */
static const DemoMsg2 sMsg_d49_s1_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_EXEC_SCRIPT, 1, {25118, 0}
};
/* -- step 2 -- */
static const DemoMsg0 sMsg_d49_s2_0 = {0x4E69, CLS_BUS, NOWAIT, 0, BUS_WAIT_EXT, 0};
/* -- step 3 -- */
static const DemoMsg2 sMsg_d49_s3_0 = {
    0x4E69, CLS_BUS, WAIT, 0, BUS_WAIT, 1, {70, 0}
};
static const DemoMsg10 sMsg_d49_s3_1 = {
    0x730A, CLS_FADE, NOWAIT, 0, 2, 9, {1, 6, 31, 31, 31, 1, 1, 1, 0, 0}
};
static const DemoMsg2 sMsg_d49_s3_2 = {
    0x74E2, CLS_SOUND, NOWAIT, 3, 0, 1, {350, 0}
};
// clang-format on
