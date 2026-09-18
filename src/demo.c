#include "global.h"
#include "msgbus.h"

// デモ(イベント/カットシーン)スクリプト。EntityMsgBus がこれを読んで各エンティティにメッセージを配る。
// 構造は デモ表[demoID] -> デモ[step] -> ステップ[i] -> メッセージ の4段で、DemoTable_GetMsg が引く。
//
// ROM の並びが 段ごとのまとまり (メッセージ本体 -> ステップ -> デモ -> デモ表) なので、
// 1つのデモのデータはこのファイルの4箇所に分かれている。タイムラインとして読めるのは
// 最初の「メッセージ本体」の領域で、そこはデモ順・ステップ順に並んでいる。
//
// tools/dumper/demo_script.ts が baserom.gba から生成したもの。以降は手で名前を育ててよい。

// ---- メッセージの実体 ----
// 可変長で、実体サイズは 8 + ceil(argc/2)*4。argc を偶数に丸めた6種を使い分ける。
// 実行時に見るときは EntityMsg* にキャストする。余りスロットは常に 0。

// clang-format off
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; }                DemoMsg0;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[2]; }   DemoMsg2;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[4]; }   DemoMsg4;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[6]; }   DemoMsg6;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[8]; }   DemoMsg8;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[10]; }  DemoMsg10;
// clang-format on

// waitFlag: WAIT なら受け手が処理し終えるまで次のステップに進まない
#define NOWAIT 0
#define WAIT 1

// targetClass: 宛先の種別。EntityMsgBus_Register の第3引数と照合される
#define CLS_BUS 1
#define CLS_PLAYER 2
#define CLS_ENEMY 3
#define CLS_BOSS 4
#define CLS_ACTOR 5
#define CLS_CAMERA 6
#define CLS_FADE 7
#define CLS_SOUND 8
#define CLS_CBB0 9
#define CLS_ETC 10

// cmd の意味は targetClass ごとに別物。ハンドラを読んで確定したものだけ名前を付けてある
#define BUS_EXEC_SCRIPT 0  // Demo_CmdExecScript
#define BUS_WAIT 1         // Demo_CmdWait
#define BUS_WAIT_EXT 2     // Demo_CmdWaitExternal

#define M(x) (const EntityMsg*)&x

// clang-format off

/* ======== メッセージ本体 (0x08DAADB8-) ======== */

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
/* ================ demo 25  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d25_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d25_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31314, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d25_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d25_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d25_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d25_s4_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 1, 0 } };
/* ================ demo 26  (22 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d26_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d26_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d26_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 5247, 512, 640, 0 } };
static const DemoMsg4  sMsg_d26_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 5181, 662, 770, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d26_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d26_s2_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d26_s2_2      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 5,               1, { 3, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d26_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20300, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d26_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d26_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d26_s5_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 5,               1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d26_s6_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 4280, 662, 770, 60 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d26_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20300, 0 } };
/* -- step 8 -- */
static const DemoMsg0  sMsg_d26_s8_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 9 -- */
static const DemoMsg4  sMsg_d26_s9_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 5181, 662, 770, 60 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d26_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d26_s10_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 5,               1, { 3, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d26_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 130, 0 } };
static const DemoMsg4  sMsg_d26_s11_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 140, 140, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d26_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20300, 0 } };
/* -- step 13 -- */
static const DemoMsg0  sMsg_d26_s13_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d26_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d26_s14_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 7,               1, { 0, 0 } };
static const DemoMsg2  sMsg_d26_s14_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d26_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20300, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d26_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d26_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d26_s17_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 43,              1, { 5, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d26_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -20300, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d26_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d26_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d26_s20_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 9,               0 };
static const DemoMsg0  sMsg_d26_s20_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 44,              0 };
static const DemoMsg2  sMsg_d26_s20_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 34, 0 } };
static const DemoMsg2  sMsg_d26_s20_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 3,               1, { 6, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d26_s21_0     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
static const DemoMsg2  sMsg_d26_s21_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* ================ demo 27  (31 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d27_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d27_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d27_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d27_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d27_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d27_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d27_s3_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d27_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg4  sMsg_d27_s4_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 29,              3, { 5248, 512, 640, 0 } };
static const DemoMsg4  sMsg_d27_s4_2      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 5248, 512, 640, 20 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d27_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d27_s5_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 4224, 512, 640, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d27_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d27_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d27_s8_0      = { 0xBA4B, CLS_BOSS,   WAIT,   3, 13,              3, { 4352, 512, 640, 0 } };
static const DemoMsg4  sMsg_d27_s8_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 4, 2,               4, { 4352, 512, 640, 20 } };
static const DemoMsg2  sMsg_d27_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 834, 0 } };
static const DemoMsg2  sMsg_d27_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 76, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d27_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d27_s9_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 14,              1, { 0, 0 } };
/* -- step 10 -- */
static const DemoMsg4  sMsg_d27_s10_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 16,              3, { 5, 80, 1, 0 } };
static const DemoMsg2  sMsg_d27_s10_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 230, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d27_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
/* -- step 12 -- */
static const DemoMsg4  sMsg_d27_s12_0     = { 0xBA4B, CLS_BOSS,   WAIT,   0, 4,               3, { 3968, 512, 640, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d27_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d27_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 3, 0 } };
static const DemoMsg2  sMsg_d27_s14_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 541, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d27_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d27_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d27_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d27_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d27_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 20 -- */
static const DemoMsg0  sMsg_d27_s20_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 21 -- */
static const DemoMsg4  sMsg_d27_s21_0     = { 0x2B06, CLS_PLAYER, WAIT,   1, 29,              3, { 4608, 512, 640, 0 } };
static const DemoMsg2  sMsg_d27_s21_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 35, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d27_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d27_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 13, 0 } };
static const DemoMsg2  sMsg_d27_s23_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 23,              1, { 30, 0 } };
static const DemoMsg4  sMsg_d27_s23_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 13,              3, { 2800, 512, 640, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d27_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 13, 0 } };
static const DemoMsg2  sMsg_d27_s24_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 23,              1, { 30, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d27_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 13, 0 } };
static const DemoMsg2  sMsg_d27_s25_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 23,              1, { 30, 0 } };
static const DemoMsg0  sMsg_d27_s25_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 3, 0,               0 };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d27_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -4107, 0 } };
/* -- step 27 -- */
static const DemoMsg0  sMsg_d27_s27_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 28 -- */
static const DemoMsg4  sMsg_d27_s28_0     = { 0x2B06, CLS_PLAYER, WAIT,   3, 6,               3, { 3712, 512, 640, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d27_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg0  sMsg_d27_s29_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 3, 0,               0 };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d27_s30_0     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 5, 0 } };
static const DemoMsg2  sMsg_d27_s30_1     = { 0xD23E, CLS_CAMERA, WAIT,   0, 5,               1, { 15, 0 } };
/* ================ demo 28  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d28_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1152, 512, 4736, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d28_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d28_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d28_s1_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d28_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
static const DemoMsg4  sMsg_d28_s2_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 640, 1280, 3500, 60 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d28_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg10 sMsg_d28_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d28_s4_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 1,               3, { 1280, 1792, 1408, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d28_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg4  sMsg_d28_s5_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1176, 2048, 1152, 60 } };
static const DemoMsg4  sMsg_d28_s5_2      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 6,               3, { 1664, 2048, 640, 0 } };
static const DemoMsg10 sMsg_d28_s5_3      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d28_s6_0      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 6,               3, { 1664, 2048, 640, 0 } };
static const DemoMsg4  sMsg_d28_s6_1      = { 0xBA4B, CLS_BOSS,   WAIT,   1, 13,              3, { 384, 2048, 1152, 0 } };
/* -- step 7 -- */
static const DemoMsg4  sMsg_d28_s7_0      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1176, 2048, 1152, 60 } };
static const DemoMsg4  sMsg_d28_s7_1      = { 0x2B06, CLS_PLAYER, WAIT,   1, 6,               3, { 1664, 2048, 640, 0 } };
static const DemoMsg0  sMsg_d28_s7_2      = { 0xBA4B, CLS_BOSS,   NOWAIT, 1, 0,               0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d28_s8_0      = { 0x2B06, CLS_PLAYER, WAIT,   1, 6,               3, { 640, 2048, 1152, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d28_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg4  sMsg_d28_s9_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 6,               3, { 384, 2048, 1152, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d28_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg10 sMsg_d28_s10_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 29  (36 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d29_s0_0      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 11,              1, { 7, 0 } };
static const DemoMsg4  sMsg_d29_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3968, 512, 2688, 0 } };
static const DemoMsg0  sMsg_d29_s0_2      = { 0x0074, CLS_BOSS,   NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d29_s0_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d29_s1_0      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 3700, 512, 2688, 35 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d29_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg2  sMsg_d29_s2_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 64, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d29_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29146, 0 } };
/* -- step 4 -- */
static const DemoMsg0  sMsg_d29_s4_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d29_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d29_s5_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 12,              1, { 7, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d29_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29146, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d29_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d29_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d29_s8_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 18,              0 };
static const DemoMsg2  sMsg_d29_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 835, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d29_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d29_s9_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d29_s9_2      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 28,              1, { 0, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d29_s10_0     = { 0xBA4B, CLS_BOSS,   WAIT,   0, 27,              0 };
static const DemoMsg2  sMsg_d29_s10_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 812, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d29_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d29_s12_0     = { 0xBA4B, CLS_BOSS,   WAIT,   0, 5,               1, { 3, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d29_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29146, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d29_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d29_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d29_s15_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 28,              0 };
static const DemoMsg2  sMsg_d29_s15_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 801, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d29_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29146, 0 } };
/* -- step 17 -- */
static const DemoMsg0  sMsg_d29_s17_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d29_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d29_s18_1     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 29,              0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d29_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg8  sMsg_d29_s19_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 27,              7, { 3200, 640, 2688, 3968, 640, 2944, 60, 0 } };
static const DemoMsg2  sMsg_d29_s19_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 802, 0 } };
/* -- step 20 -- */
static const DemoMsg4  sMsg_d29_s20_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3968, 512, 2944, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d29_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d29_s21_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 22 -- */
static const DemoMsg2  sMsg_d29_s22_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d29_s22_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
static const DemoMsg2  sMsg_d29_s22_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 803, 0 } };
static const DemoMsg2  sMsg_d29_s22_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 811, 0 } };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d29_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d29_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d29_s24_1     = { 0x0074, CLS_BOSS,   NOWAIT, 0, 45,              0 };
static const DemoMsg2  sMsg_d29_s24_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 446, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d29_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
static const DemoMsg2  sMsg_d29_s25_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d29_s25_2     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 28,              1, { 0, 0 } };
/* -- step 26 -- */
static const DemoMsg2  sMsg_d29_s26_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d29_s26_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 802, 0 } };
static const DemoMsg8  sMsg_d29_s26_2     = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 27,              7, { 3968, 640, 2944, 4096, 640, 2368, 60, 0 } };
static const DemoMsg4  sMsg_d29_s26_3     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 29,              3, { 4096, 512, 2368, 0 } };
static const DemoMsg2  sMsg_d29_s26_4     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 27 -- */
static const DemoMsg2  sMsg_d29_s27_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg0  sMsg_d29_s27_1     = { 0x0074, CLS_BOSS,   NOWAIT, 0, 46,              0 };
static const DemoMsg2  sMsg_d29_s27_2     = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 3,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d29_s27_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 361, 0 } };
/* -- step 28 -- */
static const DemoMsg2  sMsg_d29_s28_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d29_s28_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d29_s28_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 773, 0 } };
static const DemoMsg2  sMsg_d29_s28_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 448, 0 } };
/* -- step 29 -- */
static const DemoMsg2  sMsg_d29_s29_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 30 -- */
static const DemoMsg2  sMsg_d29_s30_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg0  sMsg_d29_s30_1     = { 0x51E2, CLS_ACTOR,  NOWAIT, 3, 0,               0 };
static const DemoMsg2  sMsg_d29_s30_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 1,               1, { 76, 0 } };
/* -- step 31 -- */
static const DemoMsg2  sMsg_d29_s31_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d29_s31_1     = { 0x0074, CLS_BOSS,   NOWAIT, 0, 47,              0 };
static const DemoMsg2  sMsg_d29_s31_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 447, 0 } };
static const DemoMsg2  sMsg_d29_s31_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 772, 0 } };
/* -- step 32 -- */
static const DemoMsg2  sMsg_d29_s32_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 29146, 0 } };
/* -- step 33 -- */
static const DemoMsg0  sMsg_d29_s33_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 34 -- */
static const DemoMsg2  sMsg_d29_s34_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d29_s34_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg4  sMsg_d29_s34_2     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 13,              3, { 2944, 512, 1152, 0 } };
/* -- step 35 -- */
static const DemoMsg2  sMsg_d29_s35_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg10 sMsg_d29_s35_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d29_s35_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 8, 0 } };
static const DemoMsg0  sMsg_d29_s35_3     = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 0,               0 };
/* ================ demo 30  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d30_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d30_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 113, 0 } };
static const DemoMsg2  sMsg_d30_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 69, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d30_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg0  sMsg_d30_s1_1      = { 0x0074, CLS_BOSS,   NOWAIT, 0, 51,              0 };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d30_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 14758, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d30_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d30_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg10 sMsg_d30_s4_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg0  sMsg_d30_s4_2      = { 0x0074, CLS_BOSS,   NOWAIT, 0, 48,              0 };
static const DemoMsg2  sMsg_d30_s4_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 445, 0 } };
static const DemoMsg2  sMsg_d30_s4_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 0,               1, { 732, 0 } };
static const DemoMsg2  sMsg_d30_s4_5      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 8, 0 } };
/* ================ demo 31  (10 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d31_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d31_s0_1      = { 0x0074, CLS_BOSS,   NOWAIT, 0, 50,              0 };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d31_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 606, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d31_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d31_s3_0      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 7, 0 } };
static const DemoMsg4  sMsg_d31_s3_1      = { 0xD23E, CLS_CAMERA, WAIT,   0, 2,               4, { 1750, 406, 2090, 60 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d31_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 606, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d31_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d31_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg0  sMsg_d31_s6_1      = { 0x0074, CLS_BOSS,   NOWAIT, 0, 49,              0 };
static const DemoMsg2  sMsg_d31_s6_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d31_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
static const DemoMsg2  sMsg_d31_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d31_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg2  sMsg_d31_s8_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
static const DemoMsg10 sMsg_d31_s8_2      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d31_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d31_s9_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 36, 0 } };
/* ================ demo 32  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d32_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2176, 256, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d32_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
/* -- step 2 -- */
static const DemoMsg4  sMsg_d32_s2_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 3200, 256, 2688, 80 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d32_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d32_s4_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2688, 256, 2176, 60 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d32_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d32_s6_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 50, 0 } };
/* ================ demo 33  (11 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d33_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d33_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d33_s1_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d33_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -12531, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d33_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d33_s4_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2176, 256, 2688, 80 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d33_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 6 -- */
static const DemoMsg4  sMsg_d33_s6_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2688, 256, 2176, 60 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d33_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d33_s8_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 50, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d33_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -12531, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d33_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* ================ demo 34  (20 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d34_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d34_s1_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2688, 256, 2944, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d34_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d34_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d34_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d34_s3_2      = { 0xBF31, CLS_PLAYER, NOWAIT, 0, 5,               1, { 3, 0 } };
/* -- step 4 -- */
static const DemoMsg4  sMsg_d34_s4_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2688, 0 } };
static const DemoMsg4  sMsg_d34_s4_1      = { 0xBF31, CLS_PLAYER, NOWAIT, 0, 6,               3, { 2176, 256, 2688, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d34_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d34_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d34_s7_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d34_s8_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d34_s8_1      = { 0xBF31, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d34_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d34_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg4  sMsg_d34_s11_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2176, 256, 2688, 60 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d34_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 110, 0 } };
static const DemoMsg4  sMsg_d34_s12_1     = { 0xBF31, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d34_s13_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d34_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d34_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg4  sMsg_d34_s16_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2944, 0 } };
/* -- step 17 -- */
static const DemoMsg4  sMsg_d34_s17_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 2944, 0 } };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d34_s18_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 1920, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d34_s19_0     = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 5, 0 } };
/* ================ demo 35  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d35_s0_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2176, 256, 2944, 0 } };
/* -- step 1 -- */
static const DemoMsg4  sMsg_d35_s1_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 2688, 256, 2944, 60 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d35_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d35_s3_0      = { 0x2B06, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d35_s3_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d35_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d35_s4_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 5,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d35_s4_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 5,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg4  sMsg_d35_s5_0      = { 0x2B06, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2688, 0 } };
static const DemoMsg4  sMsg_d35_s5_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 2176, 256, 2688, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d35_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d35_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d35_s8_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 3200, 256, 2688, 60 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d35_s9_0      = { 0x2B06, CLS_PLAYER, WAIT,   0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d35_s9_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d35_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 11 -- */
static const DemoMsg0  sMsg_d35_s11_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d35_s12_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d35_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 110, 0 } };
static const DemoMsg4  sMsg_d35_s13_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 120, 120, 0 } };
/* -- step 14 -- */
static const DemoMsg4  sMsg_d35_s14_0     = { 0x56CB, CLS_CAMERA, WAIT,   0, 2,               4, { 3200, 256, 2688, 60 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d35_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 31008, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d35_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg4  sMsg_d35_s17_0     = { 0x2B06, CLS_PLAYER, WAIT,   0, 6,               3, { 3200, 256, 2944, 0 } };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d35_s18_0     = { 0x2B06, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 2944, 0 } };
/* -- step 19 -- */
static const DemoMsg4  sMsg_d35_s19_0     = { 0x2B06, CLS_PLAYER, WAIT,   0, 6,               3, { 2688, 256, 1920, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d35_s20_0     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
static const DemoMsg2  sMsg_d35_s20_1     = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 60, 0 } };
/* ================ demo 36  (24 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d36_s0_0      = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 6,               3, { 2560, 1280, 2176, 0 } };
static const DemoMsg4  sMsg_d36_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 2816, 1280, 2176, 0 } };
static const DemoMsg2  sMsg_d36_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg2  sMsg_d36_s0_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 8,               1, { 6, 0 } };
static const DemoMsg4  sMsg_d36_s0_4      = { 0x56CB, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2896, 1430, 2086, 60 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d36_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d36_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 64, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d36_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d36_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d36_s4_0      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 543, 0 } };
static const DemoMsg2  sMsg_d36_s4_1      = { 0x730A, CLS_FADE,   WAIT,   9, 5,               2, { 30, 15 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d36_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d36_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d36_s7_0      = { 0xBA4B, CLS_BOSS,   WAIT,   0, 5,               1, { 5, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d36_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d36_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d36_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d36_s10_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 28,              3, { 4, 140, 140, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d36_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d36_s12_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d36_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d36_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 15 -- */
static const DemoMsg0  sMsg_d36_s15_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d36_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg2  sMsg_d36_s16_1     = { 0x2B06, CLS_PLAYER, NOWAIT, 0, 35,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d36_s16_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 742, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d36_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d36_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d36_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d36_s19_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 1, 0 } };
/* -- step 20 -- */
static const DemoMsg10 sMsg_d36_s20_0     = { 0x730A, CLS_FADE,   WAIT,   0, 2,               9, { 1, 5, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d36_s20_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d36_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8751, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d36_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg10 sMsg_d36_s23_0     = { 0x730A, CLS_FADE,   WAIT,   0, 2,               9, { 1, 0, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 37  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d37_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d37_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d37_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d37_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8986, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d37_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d37_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -8986, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d37_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 36, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d37_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d37_s6_1      = { 0xBA4B, CLS_BOSS,   NOWAIT, 0, 0,               0 };
/* ================ demo 38  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d38_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d38_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 71, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d38_s1_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 3,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d38_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d38_s3_0      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 544, 0 } };
static const DemoMsg2  sMsg_d38_s3_1      = { 0x730A, CLS_FADE,   WAIT,   9, 5,               2, { 30, 15 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d38_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d38_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -10795, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d38_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d38_s7_0      = { 0x2B06, CLS_PLAYER, WAIT,   0, 20,              1, { 1, 0 } };
static const DemoMsg2  sMsg_d38_s7_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d38_s8_0      = { 0x56CB, CLS_CAMERA, WAIT,   0, 5,               1, { 30, 0 } };
/* ================ demo 39  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d39_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d39_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d39_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d39_s1_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 5, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d39_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d39_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d39_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d39_s3_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d39_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d39_s4_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d39_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d39_s5_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 5, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d39_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30336, 0 } };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d39_s7_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d39_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d39_s8_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d39_s8_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d39_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -30336, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d39_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d39_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d39_s11_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 7,               0 };
/* ================ demo 40  (6 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d40_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg0  sMsg_d40_s0_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 33,              0 };
static const DemoMsg2  sMsg_d40_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d40_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d40_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 734, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d40_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        2, { 122, 260 } };
static const DemoMsg0  sMsg_d40_s2_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 33,              0 };
static const DemoMsg2  sMsg_d40_s2_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 158, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d40_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 138, 0 } };
static const DemoMsg2  sMsg_d40_s3_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 735, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d40_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d40_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg10 sMsg_d40_s4_2      = { 0x730A, CLS_FADE,   NOWAIT, 9, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 0, 0, 0 } };
static const DemoMsg2  sMsg_d40_s4_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 736, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d40_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg2  sMsg_d40_s5_1      = { 0x6740, CLS_ACTOR,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* ================ demo 41  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d41_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d41_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d41_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d41_s1_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 158, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d41_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8111, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d41_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d41_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 10, 0 } };
static const DemoMsg2  sMsg_d41_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 738, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d41_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d41_s5_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 0, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d41_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 809, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d41_s6_0      = { 0x45E5, CLS_ENEMY,  WAIT,   0, 4,               0 };
static const DemoMsg0  sMsg_d41_s6_1      = { 0x45E6, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg0  sMsg_d41_s6_2      = { 0x45E7, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg0  sMsg_d41_s6_3      = { 0x45E8, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* -- step 7 -- */
static const DemoMsg0  sMsg_d41_s7_0      = { 0x3DB5, CLS_ACTOR,  WAIT,   0, 18,              0 };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d41_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8111, 0 } };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d41_s9_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 10 -- */
static const DemoMsg2  sMsg_d41_s10_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d41_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 180, 0 } };
static const DemoMsg0  sMsg_d41_s11_1     = { 0x45E5, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const DemoMsg0  sMsg_d41_s11_2     = { 0x45E6, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const DemoMsg0  sMsg_d41_s11_3     = { 0x45E7, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
static const DemoMsg0  sMsg_d41_s11_4     = { 0x45E8, CLS_ENEMY,  NOWAIT, 0, 5,               0 };
/* -- step 12 -- */
static const DemoMsg0  sMsg_d41_s12_0     = { 0x3DB5, CLS_ACTOR,  WAIT,   0, 19,              0 };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d41_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8111, 0 } };
/* -- step 14 -- */
static const DemoMsg0  sMsg_d41_s14_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d41_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d41_s15_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 0, 0, 64, 0 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d41_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d41_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 105, 0 } };
static const DemoMsg2  sMsg_d41_s17_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 792, 0 } };
/* -- step 18 -- */
static const DemoMsg2  sMsg_d41_s18_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8111, 0 } };
/* -- step 19 -- */
static const DemoMsg0  sMsg_d41_s19_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d41_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d41_s20_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
/* ================ demo 42  (21 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d42_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d42_s0_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d42_s0_2      = { 0xF153, CLS_ENEMY,  NOWAIT, 0, 6,               2, { -2417, 256 } };
static const DemoMsg2  sMsg_d42_s0_3      = { 0xF154, CLS_ENEMY,  NOWAIT, 0, 6,               2, { -2417, 256 } };
static const DemoMsg2  sMsg_d42_s0_4      = { 0xF155, CLS_ENEMY,  NOWAIT, 0, 6,               2, { -2417, 256 } };
static const DemoMsg2  sMsg_d42_s0_5      = { 0xF156, CLS_ENEMY,  NOWAIT, 0, 6,               2, { -2417, 256 } };
static const DemoMsg2  sMsg_d42_s0_6      = { 0xF157, CLS_ENEMY,  NOWAIT, 0, 6,               2, { -2417, 256 } };
static const DemoMsg2  sMsg_d42_s0_7      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 4, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d42_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg0  sMsg_d42_s1_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 36,              0 };
static const DemoMsg0  sMsg_d42_s1_2      = { 0xE6ED, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg0  sMsg_d42_s1_3      = { 0xDDEE, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
static const DemoMsg2  sMsg_d42_s1_4      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 158, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d42_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d42_s2_1      = { 0xDDEE, CLS_ENEMY,  NOWAIT, 0, 4,               0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d42_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 90, 0 } };
static const DemoMsg2  sMsg_d42_s3_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d42_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8112, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d42_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d42_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d42_s6_1      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d42_s6_2      = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d42_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg4  sMsg_d42_s7_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1152, 256, 1152, 30 } };
static const DemoMsg2  sMsg_d42_s7_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 967, 0 } };
/* -- step 8 -- */
static const DemoMsg4  sMsg_d42_s8_0      = { 0xF68F, CLS_ACTOR,  WAIT,   0, 3,               3, { 1280, 256, 1164, 0 } };
static const DemoMsg2  sMsg_d42_s8_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d42_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 10 -- */
static const DemoMsg4  sMsg_d42_s10_0     = { 0xF68F, CLS_ACTOR,  WAIT,   0, 3,               3, { 1024, 256, 1164, 0 } };
static const DemoMsg2  sMsg_d42_s10_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 968, 0 } };
static const DemoMsg2  sMsg_d42_s10_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d42_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 12 -- */
static const DemoMsg4  sMsg_d42_s12_0     = { 0xF68F, CLS_ACTOR,  WAIT,   0, 3,               3, { 1152, 256, 1164, 0 } };
static const DemoMsg2  sMsg_d42_s12_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d42_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d42_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg4  sMsg_d42_s14_1     = { 0xF68F, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1024, 256, 1164, 0 } };
static const DemoMsg2  sMsg_d42_s14_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 201, 0 } };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d42_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d42_s15_1     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 2432, 256, 1408, 30 } };
/* -- step 16 -- */
static const DemoMsg2  sMsg_d42_s16_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 140, 0 } };
static const DemoMsg4  sMsg_d42_s16_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 10,              3, { 4, 130, 130, 0 } };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d42_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8112, 0 } };
/* -- step 18 -- */
static const DemoMsg0  sMsg_d42_s18_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d42_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg4  sMsg_d42_s19_1     = { 0x8E9F, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1152, 256, 1152, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d42_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d42_s20_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 6, 0 } };
static const DemoMsg10 sMsg_d42_s20_2     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 43  (9 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d43_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 15, 0 } };
static const DemoMsg2  sMsg_d43_s0_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d43_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d43_s1_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 6,               1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d43_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8443, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d43_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d43_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d43_s4_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d43_s4_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d43_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 8443, 0 } };
/* -- step 6 -- */
static const DemoMsg0  sMsg_d43_s6_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d43_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d43_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 1664, 1024, 128, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d43_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg4  sMsg_d43_s8_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1664, 1024, 384, 0 } };
static const DemoMsg10 sMsg_d43_s8_2      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 44  (26 steps) ================ */
/* -- step 0 -- */
static const DemoMsg4  sMsg_d44_s0_0      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 3,               3, { 1152, 256, 1664, 0 } };
static const DemoMsg4  sMsg_d44_s0_1      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 6,               3, { 1408, 256, 1664, 0 } };
static const DemoMsg2  sMsg_d44_s0_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d44_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg4  sMsg_d44_s1_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1408, 256, 1664, 120 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d44_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d44_s2_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d44_s2_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d44_s2_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 110, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d44_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d44_s3_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d44_s3_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d44_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d44_s4_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d44_s4_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 3, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d44_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d44_s5_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d44_s5_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d44_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 25, 0 } };
static const DemoMsg2  sMsg_d44_s6_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d44_s6_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d44_s6_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 560, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d44_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d44_s7_1      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d44_s7_2      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               1, { 1, 0 } };
static const DemoMsg2  sMsg_d44_s7_3      = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
static const DemoMsg2  sMsg_d44_s7_4      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d44_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg4  sMsg_d44_s8_1      = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1186, 256, 1094, 60 } };
static const DemoMsg0  sMsg_d44_s8_2      = { 0xD37F, CLS_BOSS,   NOWAIT, 0, 38,              0 };
/* -- step 9 -- */
static const DemoMsg0  sMsg_d44_s9_0      = { 0xD37F, CLS_BOSS,   WAIT,   0, 39,              0 };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d44_s10_0     = { 0xD37F, CLS_BOSS,   WAIT,   0, 40,              0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d44_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d44_s11_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 5, 0 } };
/* -- step 12 -- */
static const DemoMsg2  sMsg_d44_s12_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 120, 0 } };
static const DemoMsg0  sMsg_d44_s12_1     = { 0xD37F, CLS_BOSS,   NOWAIT, 0, 18,              0 };
static const DemoMsg2  sMsg_d44_s12_2     = { 0x730A, CLS_FADE,   NOWAIT, 9, 5,               2, { -1, 6 } };
/* -- step 13 -- */
static const DemoMsg2  sMsg_d44_s13_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 20, 0 } };
static const DemoMsg2  sMsg_d44_s13_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 48, 0 } };
/* -- step 14 -- */
static const DemoMsg2  sMsg_d44_s14_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
static const DemoMsg0  sMsg_d44_s14_1     = { 0x730A, CLS_FADE,   NOWAIT, 9, 6,               0 };
/* -- step 15 -- */
static const DemoMsg2  sMsg_d44_s15_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31921, 0 } };
/* -- step 16 -- */
static const DemoMsg0  sMsg_d44_s16_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 17 -- */
static const DemoMsg2  sMsg_d44_s17_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg0  sMsg_d44_s17_1     = { 0xD37F, CLS_BOSS,   NOWAIT, 0, 41,              0 };
static const DemoMsg4  sMsg_d44_s17_2     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1216, 256, 1344, 60 } };
/* -- step 18 -- */
static const DemoMsg4  sMsg_d44_s18_0     = { 0x9CFE, CLS_ACTOR,  WAIT,   0, 3,               3, { 896, 256, 1664, 0 } };
static const DemoMsg4  sMsg_d44_s18_1     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 6,               3, { 1664, 256, 1664, 0 } };
/* -- step 19 -- */
static const DemoMsg2  sMsg_d44_s19_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 50, 0 } };
static const DemoMsg4  sMsg_d44_s19_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 2,               3, { 1, 256, 1664, 0 } };
static const DemoMsg4  sMsg_d44_s19_2     = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 3,               3, { 1, 256, 1664, 0 } };
/* -- step 20 -- */
static const DemoMsg2  sMsg_d44_s20_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg2  sMsg_d44_s20_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 560, 0 } };
/* -- step 21 -- */
static const DemoMsg2  sMsg_d44_s21_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { -31921, 0 } };
/* -- step 22 -- */
static const DemoMsg0  sMsg_d44_s22_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 23 -- */
static const DemoMsg2  sMsg_d44_s23_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg0  sMsg_d44_s23_1     = { 0x9CFE, CLS_ACTOR,  NOWAIT, 0, 8,               0 };
static const DemoMsg4  sMsg_d44_s23_2     = { 0xD23E, CLS_CAMERA, NOWAIT, 0, 2,               4, { 1152, 256, 1664, 30 } };
static const DemoMsg2  sMsg_d44_s23_3     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 349, 0 } };
/* -- step 24 -- */
static const DemoMsg2  sMsg_d44_s24_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 150, 0 } };
static const DemoMsg2  sMsg_d44_s24_1     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 487, 0 } };
/* -- step 25 -- */
static const DemoMsg2  sMsg_d44_s25_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg10 sMsg_d44_s25_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 5, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d44_s25_2     = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 641, 0 } };
/* ================ demo 45  (12 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d45_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d45_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 5,               1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d45_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25114, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d45_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d45_s3_0      = { 0xF5EB, CLS_PLAYER, WAIT,   0, 10,              1, { 1, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d45_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 200, 0 } };
static const DemoMsg2  sMsg_d45_s4_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 6,               1, { 110, 0 } };
/* -- step 5 -- */
static const DemoMsg2  sMsg_d45_s5_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg0  sMsg_d45_s5_1      = { 0xD37F, CLS_BOSS,   NOWAIT, 0, 43,              0 };
static const DemoMsg2  sMsg_d45_s5_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 560, 0 } };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d45_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg2  sMsg_d45_s6_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 28,              1, { 0, 0 } };
/* -- step 7 -- */
static const DemoMsg2  sMsg_d45_s7_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 40, 0 } };
static const DemoMsg2  sMsg_d45_s7_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 13,              1, { 1, 0 } };
/* -- step 8 -- */
static const DemoMsg2  sMsg_d45_s8_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 100, 0 } };
static const DemoMsg0  sMsg_d45_s8_1      = { 0xF5EB, CLS_PLAYER, NOWAIT, 0, 0,               0 };
static const DemoMsg2  sMsg_d45_s8_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 9,               1, { 3, 0 } };
static const DemoMsg2  sMsg_d45_s8_3      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 48, 0 } };
/* -- step 9 -- */
static const DemoMsg2  sMsg_d45_s9_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25114, 0 } };
/* -- step 10 -- */
static const DemoMsg0  sMsg_d45_s10_0     = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 11 -- */
static const DemoMsg2  sMsg_d45_s11_0     = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg10 sMsg_d45_s11_1     = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 46  (7 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d46_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d46_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d46_s1_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 10,              1, { 0, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d46_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d46_s2_1      = { 0x3DB5, CLS_ACTOR,  NOWAIT, 0, 1,               1, { 1, 0 } };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d46_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 80, 0 } };
static const DemoMsg2  sMsg_d46_s3_1      = { 0x51E2, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
static const DemoMsg2  sMsg_d46_s3_2      = { 0x6773, CLS_ACTOR,  NOWAIT, 0, 2,               1, { 7, 0 } };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d46_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25115, 0 } };
/* -- step 5 -- */
static const DemoMsg0  sMsg_d46_s5_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 6 -- */
static const DemoMsg2  sMsg_d46_s6_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d46_s6_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 0, 0, 0, 1, 1, 1, 0, 0 } };
/* ================ demo 47  (5 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d47_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d47_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 60, 0 } };
static const DemoMsg2  sMsg_d47_s1_1      = { 0x2B06, CLS_PLAYER, NOWAIT, 1, 12,              1, { 1, 0 } };
/* -- step 2 -- */
static const DemoMsg2  sMsg_d47_s2_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25116, 0 } };
/* -- step 3 -- */
static const DemoMsg0  sMsg_d47_s3_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 4 -- */
static const DemoMsg2  sMsg_d47_s4_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 240, 0 } };
static const DemoMsg10 sMsg_d47_s4_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 8, 0, 0, 0, 1, 1, 1, 64, 0 } };
static const DemoMsg2  sMsg_d47_s4_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 4,               1, { 12, 0 } };
/* ================ demo 48  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d48_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 5, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d48_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25117, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d48_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d48_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
/* ================ demo 49  (4 steps) ================ */
/* -- step 0 -- */
static const DemoMsg2  sMsg_d49_s0_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 30, 0 } };
static const DemoMsg2  sMsg_d49_s0_1      = { 0x74E2, CLS_SOUND,  NOWAIT, 0, 2,               1, { 158, 0 } };
/* -- step 1 -- */
static const DemoMsg2  sMsg_d49_s1_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_EXEC_SCRIPT, 1, { 25118, 0 } };
/* -- step 2 -- */
static const DemoMsg0  sMsg_d49_s2_0      = { 0x4E69, CLS_BUS,    NOWAIT, 0, BUS_WAIT_EXT,    0 };
/* -- step 3 -- */
static const DemoMsg2  sMsg_d49_s3_0      = { 0x4E69, CLS_BUS,    WAIT,   0, BUS_WAIT,        1, { 70, 0 } };
static const DemoMsg10 sMsg_d49_s3_1      = { 0x730A, CLS_FADE,   NOWAIT, 0, 2,               9, { 1, 6, 31, 31, 31, 1, 1, 1, 0, 0 } };
static const DemoMsg2  sMsg_d49_s3_2      = { 0x74E2, CLS_SOUND,  NOWAIT, 3, 0,               1, { 350, 0 } };
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

/* ======== ステップ (0x08DB57B4-) ======== */

static const EntityMsg* const sStep_d0_s0[] = { M(sMsg_d0_s0_0), M(sMsg_d0_s0_1), M(sMsg_d0_s0_2), M(sMsg_d0_s0_3), NULL };
static const EntityMsg* const sStep_d0_s1[] = { M(sMsg_d0_s1_0), M(sMsg_d0_s1_1), NULL };
static const EntityMsg* const sStep_d0_s2[] = { M(sMsg_d0_s2_0), M(sMsg_d0_s2_1), NULL };
static const EntityMsg* const sStep_d0_s3[] = { M(sMsg_d0_s3_0), M(sMsg_d0_s3_1), M(sMsg_d0_s3_2), M(sMsg_d0_s3_3), NULL };
static const EntityMsg* const sStep_d0_s4[] = { M(sMsg_d0_s4_0), M(sMsg_d0_s4_1), M(sMsg_d0_s4_2), M(sMsg_d0_s4_3), M(sMsg_d0_s4_4), NULL };
static const EntityMsg* const sStep_d0_s5[] = { M(sMsg_d0_s5_0), M(sMsg_d0_s5_1), NULL };
static const EntityMsg* const sStep_d0_s6[] = { M(sMsg_d0_s6_0), NULL };
static const EntityMsg* const sStep_d0_s7[] = { M(sMsg_d0_s7_0), NULL };
static const EntityMsg* const sStep_d0_s8[] = { M(sMsg_d0_s8_0), M(sMsg_d0_s8_1), NULL };
static const EntityMsg* const sStep_d0_s9[] = { M(sMsg_d0_s9_0), M(sMsg_d0_s9_1), M(sMsg_d0_s9_2), M(sMsg_d0_s9_3), NULL };
static const EntityMsg* const sStep_d0_s10[] = { M(sMsg_d0_s10_0), M(sMsg_d0_s10_1), M(sMsg_d0_s10_2), M(sMsg_d0_s10_3), NULL };
static const EntityMsg* const sStep_d0_s11[] = { M(sMsg_d0_s11_0), M(sMsg_d0_s11_1), NULL };
static const EntityMsg* const sStep_d0_s12[] = { M(sMsg_d0_s12_0), M(sMsg_d0_s12_1), M(sMsg_d0_s12_2), NULL };
static const EntityMsg* const sStep_d1_s0[] = { M(sMsg_d1_s0_0), M(sMsg_d1_s0_1), NULL };
static const EntityMsg* const sStep_d1_s1[] = { M(sMsg_d1_s1_0), M(sMsg_d1_s1_1), NULL };
static const EntityMsg* const sStep_d1_s2[] = { M(sMsg_d1_s2_0), M(sMsg_d1_s2_1), M(sMsg_d1_s2_2), NULL };
static const EntityMsg* const sStep_d1_s3[] = { M(sMsg_d1_s3_0), M(sMsg_d1_s3_1), NULL };
static const EntityMsg* const sStep_d1_s4[] = { M(sMsg_d1_s4_0), M(sMsg_d1_s4_1), NULL };
static const EntityMsg* const sStep_d1_s5[] = { M(sMsg_d1_s5_0), NULL };
static const EntityMsg* const sStep_d1_s6[] = { M(sMsg_d1_s6_0), NULL };
static const EntityMsg* const sStep_d1_s7[] = { M(sMsg_d1_s7_0), M(sMsg_d1_s7_1), NULL };
static const EntityMsg* const sStep_d1_s8[] = { M(sMsg_d1_s8_0), NULL };
static const EntityMsg* const sStep_d1_s9[] = { M(sMsg_d1_s9_0), NULL };
static const EntityMsg* const sStep_d1_s10[] = { M(sMsg_d1_s10_0), M(sMsg_d1_s10_1), NULL };
static const EntityMsg* const sStep_d1_s11[] = { M(sMsg_d1_s11_0), M(sMsg_d1_s11_1), M(sMsg_d1_s11_2), M(sMsg_d1_s11_3), NULL };
static const EntityMsg* const sStep_d1_s12[] = { M(sMsg_d1_s12_0), M(sMsg_d1_s12_1), M(sMsg_d1_s12_2), M(sMsg_d1_s12_3), M(sMsg_d1_s12_4), NULL };
static const EntityMsg* const sStep_d1_s13[] = { M(sMsg_d1_s13_0), M(sMsg_d1_s13_1), M(sMsg_d1_s13_2), NULL };
static const EntityMsg* const sStep_d1_s14[] = { M(sMsg_d1_s14_0), M(sMsg_d1_s14_1), M(sMsg_d1_s14_2), NULL };
static const EntityMsg* const sStep_d1_s15[] = { M(sMsg_d1_s15_0), M(sMsg_d1_s15_1), M(sMsg_d1_s15_2), NULL };
static const EntityMsg* const sStep_d1_s16[] = { M(sMsg_d1_s16_0), NULL };
static const EntityMsg* const sStep_d1_s17[] = { M(sMsg_d1_s17_0), NULL };
static const EntityMsg* const sStep_d1_s18[] = { M(sMsg_d1_s18_0), NULL };
static const EntityMsg* const sStep_d1_s19[] = { M(sMsg_d1_s19_0), M(sMsg_d1_s19_1), NULL };
static const EntityMsg* const sStep_d1_s20[] = { M(sMsg_d1_s20_0), NULL };
static const EntityMsg* const sStep_d1_s21[] = { M(sMsg_d1_s21_0), NULL };
static const EntityMsg* const sStep_d1_s22[] = { M(sMsg_d1_s22_0), M(sMsg_d1_s22_1), M(sMsg_d1_s22_2), NULL };
static const EntityMsg* const sStep_d1_s23[] = { M(sMsg_d1_s23_0), M(sMsg_d1_s23_1), NULL };
static const EntityMsg* const sStep_d1_s24[] = { M(sMsg_d1_s24_0), M(sMsg_d1_s24_1), M(sMsg_d1_s24_2), M(sMsg_d1_s24_3), NULL };
static const EntityMsg* const sStep_d1_s25[] = { M(sMsg_d1_s25_0), M(sMsg_d1_s25_1), NULL };
static const EntityMsg* const sStep_d1_s26[] = { M(sMsg_d1_s26_0), M(sMsg_d1_s26_1), NULL };
static const EntityMsg* const sStep_d1_s27[] = { M(sMsg_d1_s27_0), NULL };
static const EntityMsg* const sStep_d1_s28[] = { M(sMsg_d1_s28_0), NULL };
static const EntityMsg* const sStep_d1_s29[] = { M(sMsg_d1_s29_0), NULL };
static const EntityMsg* const sStep_d1_s30[] = { M(sMsg_d1_s30_0), M(sMsg_d1_s30_1), M(sMsg_d1_s30_2), NULL };
static const EntityMsg* const sStep_d1_s31[] = { M(sMsg_d1_s31_0), M(sMsg_d1_s31_1), M(sMsg_d1_s31_2), M(sMsg_d1_s31_3), M(sMsg_d1_s31_4), NULL };
static const EntityMsg* const sStep_d1_s32[] = { M(sMsg_d1_s32_0), NULL };
static const EntityMsg* const sStep_d1_s33[] = { M(sMsg_d1_s33_0), NULL };
static const EntityMsg* const sStep_d1_s34[] = { M(sMsg_d1_s34_0), M(sMsg_d1_s34_1), NULL };
static const EntityMsg* const sStep_d1_s35[] = { M(sMsg_d1_s35_0), NULL };
static const EntityMsg* const sStep_d1_s36[] = { M(sMsg_d1_s36_0), NULL };
static const EntityMsg* const sStep_d1_s37[] = { M(sMsg_d1_s37_0), M(sMsg_d1_s37_1), M(sMsg_d1_s37_2), NULL };
static const EntityMsg* const sStep_d1_s38[] = { M(sMsg_d1_s38_0), M(sMsg_d1_s38_1), NULL };
static const EntityMsg* const sStep_d1_s39[] = { M(sMsg_d1_s39_0), M(sMsg_d1_s39_1), NULL };
static const EntityMsg* const sStep_d1_s40[] = { M(sMsg_d1_s40_0), M(sMsg_d1_s40_1), NULL };
static const EntityMsg* const sStep_d1_s41[] = { M(sMsg_d1_s41_0), M(sMsg_d1_s41_1), M(sMsg_d1_s41_2), NULL };
static const EntityMsg* const sStep_d1_s42[] = { M(sMsg_d1_s42_0), M(sMsg_d1_s42_1), NULL };
static const EntityMsg* const sStep_d1_s43[] = { M(sMsg_d1_s43_0), NULL };
static const EntityMsg* const sStep_d1_s44[] = { M(sMsg_d1_s44_0), NULL };
static const EntityMsg* const sStep_d1_s45[] = { M(sMsg_d1_s45_0), NULL };
static const EntityMsg* const sStep_d1_s46[] = { M(sMsg_d1_s46_0), M(sMsg_d1_s46_1), M(sMsg_d1_s46_2), NULL };
static const EntityMsg* const sStep_d1_s47[] = { M(sMsg_d1_s47_0), M(sMsg_d1_s47_1), NULL };
static const EntityMsg* const sStep_d1_s48[] = { M(sMsg_d1_s48_0), NULL };
static const EntityMsg* const sStep_d1_s49[] = { M(sMsg_d1_s49_0), NULL };
static const EntityMsg* const sStep_d1_s50[] = { M(sMsg_d1_s50_0), M(sMsg_d1_s50_1), NULL };
static const EntityMsg* const sStep_d1_s51[] = { M(sMsg_d1_s51_0), M(sMsg_d1_s51_1), NULL };
static const EntityMsg* const sStep_d1_s52[] = { M(sMsg_d1_s52_0), M(sMsg_d1_s52_1), NULL };
static const EntityMsg* const sStep_d1_s53[] = { M(sMsg_d1_s53_0), NULL };
static const EntityMsg* const sStep_d1_s54[] = { M(sMsg_d1_s54_0), NULL };
static const EntityMsg* const sStep_d1_s55[] = { M(sMsg_d1_s55_0), M(sMsg_d1_s55_1), NULL };
static const EntityMsg* const sStep_d1_s56[] = { M(sMsg_d1_s56_0), M(sMsg_d1_s56_1), M(sMsg_d1_s56_2), NULL };
static const EntityMsg* const sStep_d1_s57[] = { M(sMsg_d1_s57_0), M(sMsg_d1_s57_1), M(sMsg_d1_s57_2), M(sMsg_d1_s57_3), NULL };
static const EntityMsg* const sStep_d1_s58[] = { M(sMsg_d1_s58_0), M(sMsg_d1_s58_1), M(sMsg_d1_s58_2), NULL };
static const EntityMsg* const sStep_d1_s59[] = { M(sMsg_d1_s59_0), NULL };
static const EntityMsg* const sStep_d1_s60[] = { M(sMsg_d1_s60_0), M(sMsg_d1_s60_1), NULL };
static const EntityMsg* const sStep_d1_s61[] = { M(sMsg_d1_s61_0), M(sMsg_d1_s61_1), NULL };
static const EntityMsg* const sStep_d1_s62[] = { M(sMsg_d1_s62_0), NULL };
static const EntityMsg* const sStep_d1_s63[] = { M(sMsg_d1_s63_0), NULL };
static const EntityMsg* const sStep_d1_s64[] = { M(sMsg_d1_s64_0), M(sMsg_d1_s64_1), M(sMsg_d1_s64_2), NULL };
static const EntityMsg* const sStep_d2_s0[] = { M(sMsg_d2_s0_0), M(sMsg_d2_s0_1), NULL };
static const EntityMsg* const sStep_d2_s1[] = { M(sMsg_d2_s1_0), M(sMsg_d2_s1_1), NULL };
static const EntityMsg* const sStep_d2_s2[] = { M(sMsg_d2_s2_0), NULL };
static const EntityMsg* const sStep_d2_s3[] = { M(sMsg_d2_s3_0), M(sMsg_d2_s3_1), NULL };
static const EntityMsg* const sStep_d2_s4[] = { M(sMsg_d2_s4_0), M(sMsg_d2_s4_1), NULL };
static const EntityMsg* const sStep_d2_s5[] = { M(sMsg_d2_s5_0), NULL };
static const EntityMsg* const sStep_d2_s6[] = { M(sMsg_d2_s6_0), NULL };
static const EntityMsg* const sStep_d2_s7[] = { M(sMsg_d2_s7_0), M(sMsg_d2_s7_1), NULL };
static const EntityMsg* const sStep_d2_s8[] = { M(sMsg_d2_s8_0), NULL };
static const EntityMsg* const sStep_d2_s9[] = { M(sMsg_d2_s9_0), NULL };
static const EntityMsg* const sStep_d2_s10[] = { M(sMsg_d2_s10_0), M(sMsg_d2_s10_1), M(sMsg_d2_s10_2), NULL };
static const EntityMsg* const sStep_d2_s11[] = { M(sMsg_d2_s11_0), M(sMsg_d2_s11_1), M(sMsg_d2_s11_2), NULL };
static const EntityMsg* const sStep_d2_s12[] = { M(sMsg_d2_s12_0), M(sMsg_d2_s12_1), NULL };
static const EntityMsg* const sStep_d2_s13[] = { M(sMsg_d2_s13_0), M(sMsg_d2_s13_1), NULL };
static const EntityMsg* const sStep_d2_s14[] = { M(sMsg_d2_s14_0), M(sMsg_d2_s14_1), NULL };
static const EntityMsg* const sStep_d2_s15[] = { M(sMsg_d2_s15_0), NULL };
static const EntityMsg* const sStep_d2_s16[] = { M(sMsg_d2_s16_0), NULL };
static const EntityMsg* const sStep_d2_s17[] = { M(sMsg_d2_s17_0), M(sMsg_d2_s17_1), NULL };
static const EntityMsg* const sStep_d2_s18[] = { M(sMsg_d2_s18_0), NULL };
static const EntityMsg* const sStep_d2_s19[] = { M(sMsg_d2_s19_0), NULL };
static const EntityMsg* const sStep_d2_s20[] = { M(sMsg_d2_s20_0), NULL };
static const EntityMsg* const sStep_d2_s21[] = { M(sMsg_d2_s21_0), M(sMsg_d2_s21_1), NULL };
static const EntityMsg* const sStep_d2_s22[] = { M(sMsg_d2_s22_0), M(sMsg_d2_s22_1), NULL };
static const EntityMsg* const sStep_d2_s23[] = { M(sMsg_d2_s23_0), NULL };
static const EntityMsg* const sStep_d2_s24[] = { M(sMsg_d2_s24_0), NULL };
static const EntityMsg* const sStep_d2_s25[] = { M(sMsg_d2_s25_0), NULL };
static const EntityMsg* const sStep_d2_s26[] = { M(sMsg_d2_s26_0), NULL };
static const EntityMsg* const sStep_d2_s27[] = { M(sMsg_d2_s27_0), M(sMsg_d2_s27_1), NULL };
static const EntityMsg* const sStep_d2_s28[] = { M(sMsg_d2_s28_0), M(sMsg_d2_s28_1), NULL };
static const EntityMsg* const sStep_d2_s29[] = { M(sMsg_d2_s29_0), NULL };
static const EntityMsg* const sStep_d2_s30[] = { M(sMsg_d2_s30_0), NULL };
static const EntityMsg* const sStep_d2_s31[] = { M(sMsg_d2_s31_0), M(sMsg_d2_s31_1), M(sMsg_d2_s31_2), NULL };
static const EntityMsg* const sStep_d2_s32[] = { M(sMsg_d2_s32_0), M(sMsg_d2_s32_1), NULL };
static const EntityMsg* const sStep_d2_s33[] = { M(sMsg_d2_s33_0), M(sMsg_d2_s33_1), NULL };
static const EntityMsg* const sStep_d2_s34[] = { M(sMsg_d2_s34_0), NULL };
static const EntityMsg* const sStep_d2_s35[] = { M(sMsg_d2_s35_0), NULL };
static const EntityMsg* const sStep_d2_s36[] = { M(sMsg_d2_s36_0), NULL };
static const EntityMsg* const sStep_d2_s37[] = { M(sMsg_d2_s37_0), M(sMsg_d2_s37_1), NULL };
static const EntityMsg* const sStep_d2_s38[] = { M(sMsg_d2_s38_0), NULL };
static const EntityMsg* const sStep_d2_s39[] = { M(sMsg_d2_s39_0), NULL };
static const EntityMsg* const sStep_d2_s40[] = { M(sMsg_d2_s40_0), M(sMsg_d2_s40_1), NULL };
static const EntityMsg* const sStep_d2_s41[] = { M(sMsg_d2_s41_0), M(sMsg_d2_s41_1), NULL };
static const EntityMsg* const sStep_d2_s42[] = { M(sMsg_d2_s42_0), NULL };
static const EntityMsg* const sStep_d2_s43[] = { M(sMsg_d2_s43_0), NULL };
static const EntityMsg* const sStep_d2_s44[] = { M(sMsg_d2_s44_0), M(sMsg_d2_s44_1), NULL };
static const EntityMsg* const sStep_d3_s0[] = { M(sMsg_d3_s0_0), M(sMsg_d3_s0_1), NULL };
static const EntityMsg* const sStep_d3_s1[] = { M(sMsg_d3_s1_0), M(sMsg_d3_s1_1), M(sMsg_d3_s1_2), NULL };
static const EntityMsg* const sStep_d3_s2[] = { M(sMsg_d3_s2_0), M(sMsg_d3_s2_1), M(sMsg_d3_s2_2), NULL };
static const EntityMsg* const sStep_d3_s3[] = { M(sMsg_d3_s3_0), M(sMsg_d3_s3_1), NULL };
static const EntityMsg* const sStep_d3_s4[] = { M(sMsg_d3_s4_0), M(sMsg_d3_s4_1), M(sMsg_d3_s4_2), NULL };
static const EntityMsg* const sStep_d3_s5[] = { M(sMsg_d3_s5_0), NULL };
static const EntityMsg* const sStep_d3_s6[] = { M(sMsg_d3_s6_0), NULL };
static const EntityMsg* const sStep_d3_s7[] = { M(sMsg_d3_s7_0), M(sMsg_d3_s7_1), NULL };
static const EntityMsg* const sStep_d3_s8[] = { M(sMsg_d3_s8_0), NULL };
static const EntityMsg* const sStep_d3_s9[] = { M(sMsg_d3_s9_0), M(sMsg_d3_s9_1), NULL };
static const EntityMsg* const sStep_d3_s10[] = { M(sMsg_d3_s10_0), NULL };
static const EntityMsg* const sStep_d3_s11[] = { M(sMsg_d3_s11_0), M(sMsg_d3_s11_1), M(sMsg_d3_s11_2), M(sMsg_d3_s11_3), NULL };
static const EntityMsg* const sStep_d3_s12[] = { M(sMsg_d3_s12_0), M(sMsg_d3_s12_1), M(sMsg_d3_s12_2), M(sMsg_d3_s12_3), NULL };
static const EntityMsg* const sStep_d3_s13[] = { M(sMsg_d3_s13_0), NULL };
static const EntityMsg* const sStep_d3_s14[] = { M(sMsg_d3_s14_0), NULL };
static const EntityMsg* const sStep_d3_s15[] = { M(sMsg_d3_s15_0), M(sMsg_d3_s15_1), NULL };
static const EntityMsg* const sStep_d3_s16[] = { M(sMsg_d3_s16_0), NULL };
static const EntityMsg* const sStep_d3_s17[] = { M(sMsg_d3_s17_0), M(sMsg_d3_s17_1), NULL };
static const EntityMsg* const sStep_d3_s18[] = { M(sMsg_d3_s18_0), NULL };
static const EntityMsg* const sStep_d3_s19[] = { M(sMsg_d3_s19_0), M(sMsg_d3_s19_1), NULL };
static const EntityMsg* const sStep_d3_s20[] = { M(sMsg_d3_s20_0), M(sMsg_d3_s20_1), M(sMsg_d3_s20_2), NULL };
static const EntityMsg* const sStep_d3_s21[] = { M(sMsg_d3_s21_0), M(sMsg_d3_s21_1), M(sMsg_d3_s21_2), NULL };
static const EntityMsg* const sStep_d3_s22[] = { M(sMsg_d3_s22_0), M(sMsg_d3_s22_1), M(sMsg_d3_s22_2), NULL };
static const EntityMsg* const sStep_d3_s23[] = { M(sMsg_d3_s23_0), M(sMsg_d3_s23_1), M(sMsg_d3_s23_2), NULL };
static const EntityMsg* const sStep_d3_s24[] = { M(sMsg_d3_s24_0), M(sMsg_d3_s24_1), NULL };
static const EntityMsg* const sStep_d4_s0[] = { M(sMsg_d4_s0_0), M(sMsg_d4_s0_1), NULL };
static const EntityMsg* const sStep_d4_s1[] = { M(sMsg_d4_s1_0), M(sMsg_d4_s1_1), NULL };
static const EntityMsg* const sStep_d4_s2[] = { M(sMsg_d4_s2_0), M(sMsg_d4_s2_1), NULL };
static const EntityMsg* const sStep_d4_s3[] = { M(sMsg_d4_s3_0), NULL };
static const EntityMsg* const sStep_d4_s4[] = { M(sMsg_d4_s4_0), NULL };
static const EntityMsg* const sStep_d4_s5[] = { M(sMsg_d4_s5_0), M(sMsg_d4_s5_1), NULL };
static const EntityMsg* const sStep_d4_s6[] = { M(sMsg_d4_s6_0), M(sMsg_d4_s6_1), NULL };
static const EntityMsg* const sStep_d4_s7[] = { M(sMsg_d4_s7_0), NULL };
static const EntityMsg* const sStep_d4_s8[] = { M(sMsg_d4_s8_0), NULL };
static const EntityMsg* const sStep_d4_s9[] = { M(sMsg_d4_s9_0), NULL };
static const EntityMsg* const sStep_d4_s10[] = { M(sMsg_d4_s10_0), NULL };
static const EntityMsg* const sStep_d4_s11[] = { M(sMsg_d4_s11_0), NULL };
static const EntityMsg* const sStep_d4_s12[] = { M(sMsg_d4_s12_0), NULL };
static const EntityMsg* const sStep_d4_s13[] = { M(sMsg_d4_s13_0), NULL };
static const EntityMsg* const sStep_d4_s14[] = { M(sMsg_d4_s14_0), M(sMsg_d4_s14_1), NULL };
static const EntityMsg* const sStep_d4_s15[] = { M(sMsg_d4_s15_0), M(sMsg_d4_s15_1), NULL };
static const EntityMsg* const sStep_d5_s0[] = { M(sMsg_d5_s0_0), M(sMsg_d5_s0_1), NULL };
static const EntityMsg* const sStep_d5_s1[] = { M(sMsg_d5_s1_0), M(sMsg_d5_s1_1), NULL };
static const EntityMsg* const sStep_d5_s2[] = { M(sMsg_d5_s2_0), M(sMsg_d5_s2_1), M(sMsg_d5_s2_2), NULL };
static const EntityMsg* const sStep_d5_s3[] = { M(sMsg_d5_s3_0), NULL };
static const EntityMsg* const sStep_d5_s4[] = { M(sMsg_d5_s4_0), NULL };
static const EntityMsg* const sStep_d5_s5[] = { M(sMsg_d5_s5_0), M(sMsg_d5_s5_1), NULL };
static const EntityMsg* const sStep_d5_s6[] = { M(sMsg_d5_s6_0), M(sMsg_d5_s6_1), NULL };
static const EntityMsg* const sStep_d5_s7[] = { M(sMsg_d5_s7_0), NULL };
static const EntityMsg* const sStep_d5_s8[] = { M(sMsg_d5_s8_0), NULL };
static const EntityMsg* const sStep_d5_s9[] = { M(sMsg_d5_s9_0), NULL };
static const EntityMsg* const sStep_d5_s10[] = { M(sMsg_d5_s10_0), M(sMsg_d5_s10_1), NULL };
static const EntityMsg* const sStep_d5_s11[] = { M(sMsg_d5_s11_0), NULL };
static const EntityMsg* const sStep_d5_s12[] = { M(sMsg_d5_s12_0), NULL };
static const EntityMsg* const sStep_d5_s13[] = { M(sMsg_d5_s13_0), M(sMsg_d5_s13_1), NULL };
static const EntityMsg* const sStep_d5_s14[] = { M(sMsg_d5_s14_0), M(sMsg_d5_s14_1), M(sMsg_d5_s14_2), NULL };
static const EntityMsg* const sStep_d5_s15[] = { M(sMsg_d5_s15_0), NULL };
static const EntityMsg* const sStep_d6_s0[] = { M(sMsg_d6_s0_0), M(sMsg_d6_s0_1), NULL };
static const EntityMsg* const sStep_d6_s1[] = { M(sMsg_d6_s1_0), NULL };
static const EntityMsg* const sStep_d6_s2[] = { M(sMsg_d6_s2_0), M(sMsg_d6_s2_1), NULL };
static const EntityMsg* const sStep_d6_s3[] = { M(sMsg_d6_s3_0), NULL };
static const EntityMsg* const sStep_d6_s4[] = { M(sMsg_d6_s4_0), NULL };
static const EntityMsg* const sStep_d6_s5[] = { M(sMsg_d6_s5_0), M(sMsg_d6_s5_1), NULL };
static const EntityMsg* const sStep_d6_s6[] = { M(sMsg_d6_s6_0), NULL };
static const EntityMsg* const sStep_d6_s7[] = { M(sMsg_d6_s7_0), NULL };
static const EntityMsg* const sStep_d6_s8[] = { M(sMsg_d6_s8_0), NULL };
static const EntityMsg* const sStep_d6_s9[] = { M(sMsg_d6_s9_0), M(sMsg_d6_s9_1), NULL };
static const EntityMsg* const sStep_d6_s10[] = { M(sMsg_d6_s10_0), NULL };
static const EntityMsg* const sStep_d6_s11[] = { M(sMsg_d6_s11_0), NULL };
static const EntityMsg* const sStep_d6_s12[] = { M(sMsg_d6_s12_0), M(sMsg_d6_s12_1), M(sMsg_d6_s12_2), NULL };
static const EntityMsg* const sStep_d6_s13[] = { M(sMsg_d6_s13_0), M(sMsg_d6_s13_1), M(sMsg_d6_s13_2), NULL };
static const EntityMsg* const sStep_d6_s14[] = { M(sMsg_d6_s14_0), NULL };
static const EntityMsg* const sStep_d6_s15[] = { M(sMsg_d6_s15_0), NULL };
static const EntityMsg* const sStep_d6_s16[] = { M(sMsg_d6_s16_0), M(sMsg_d6_s16_1), NULL };
static const EntityMsg* const sStep_d7_s0[] = { M(sMsg_d7_s0_0), M(sMsg_d7_s0_1), M(sMsg_d7_s0_2), NULL };
static const EntityMsg* const sStep_d7_s1[] = { M(sMsg_d7_s1_0), NULL };
static const EntityMsg* const sStep_d7_s2[] = { M(sMsg_d7_s2_0), M(sMsg_d7_s2_1), M(sMsg_d7_s2_2), NULL };
static const EntityMsg* const sStep_d7_s3[] = { M(sMsg_d7_s3_0), M(sMsg_d7_s3_1), NULL };
static const EntityMsg* const sStep_d7_s4[] = { M(sMsg_d7_s4_0), NULL };
static const EntityMsg* const sStep_d7_s5[] = { M(sMsg_d7_s5_0), NULL };
static const EntityMsg* const sStep_d7_s6[] = { M(sMsg_d7_s6_0), M(sMsg_d7_s6_1), M(sMsg_d7_s6_2), M(sMsg_d7_s6_3), NULL };
static const EntityMsg* const sStep_d7_s7[] = { M(sMsg_d7_s7_0), M(sMsg_d7_s7_1), NULL };
static const EntityMsg* const sStep_d7_s8[] = { M(sMsg_d7_s8_0), NULL };
static const EntityMsg* const sStep_d7_s9[] = { M(sMsg_d7_s9_0), NULL };
static const EntityMsg* const sStep_d7_s10[] = { M(sMsg_d7_s10_0), NULL };
static const EntityMsg* const sStep_d7_s11[] = { M(sMsg_d7_s11_0), NULL };
static const EntityMsg* const sStep_d7_s12[] = { M(sMsg_d7_s12_0), NULL };
static const EntityMsg* const sStep_d7_s13[] = { M(sMsg_d7_s13_0), NULL };
static const EntityMsg* const sStep_d7_s14[] = { M(sMsg_d7_s14_0), NULL };
static const EntityMsg* const sStep_d7_s15[] = { M(sMsg_d7_s15_0), M(sMsg_d7_s15_1), NULL };
static const EntityMsg* const sStep_d7_s16[] = { M(sMsg_d7_s16_0), NULL };
static const EntityMsg* const sStep_d7_s17[] = { M(sMsg_d7_s17_0), NULL };
static const EntityMsg* const sStep_d7_s18[] = { M(sMsg_d7_s18_0), NULL };
static const EntityMsg* const sStep_d7_s19[] = { M(sMsg_d7_s19_0), M(sMsg_d7_s19_1), M(sMsg_d7_s19_2), M(sMsg_d7_s19_3), M(sMsg_d7_s19_4), M(sMsg_d7_s19_5), NULL };
static const EntityMsg* const sStep_d7_s20[] = { M(sMsg_d7_s20_0), NULL };
static const EntityMsg* const sStep_d7_s21[] = { M(sMsg_d7_s21_0), NULL };
static const EntityMsg* const sStep_d7_s22[] = { M(sMsg_d7_s22_0), NULL };
static const EntityMsg* const sStep_d7_s23[] = { M(sMsg_d7_s23_0), NULL };
static const EntityMsg* const sStep_d7_s24[] = { M(sMsg_d7_s24_0), M(sMsg_d7_s24_1), NULL };
static const EntityMsg* const sStep_d7_s25[] = { M(sMsg_d7_s25_0), NULL };
static const EntityMsg* const sStep_d7_s26[] = { M(sMsg_d7_s26_0), NULL };
static const EntityMsg* const sStep_d7_s27[] = { M(sMsg_d7_s27_0), M(sMsg_d7_s27_1), M(sMsg_d7_s27_2), M(sMsg_d7_s27_3), NULL };
static const EntityMsg* const sStep_d7_s28[] = { M(sMsg_d7_s28_0), NULL };
static const EntityMsg* const sStep_d7_s29[] = { M(sMsg_d7_s29_0), NULL };
static const EntityMsg* const sStep_d7_s30[] = { M(sMsg_d7_s30_0), NULL };
static const EntityMsg* const sStep_d7_s31[] = { M(sMsg_d7_s31_0), NULL };
static const EntityMsg* const sStep_d7_s32[] = { M(sMsg_d7_s32_0), M(sMsg_d7_s32_1), NULL };
static const EntityMsg* const sStep_d7_s33[] = { M(sMsg_d7_s33_0), M(sMsg_d7_s33_1), M(sMsg_d7_s33_2), NULL };
static const EntityMsg* const sStep_d7_s34[] = { M(sMsg_d7_s34_0), NULL };
static const EntityMsg* const sStep_d7_s35[] = { M(sMsg_d7_s35_0), NULL };
static const EntityMsg* const sStep_d7_s36[] = { M(sMsg_d7_s36_0), M(sMsg_d7_s36_1), NULL };
static const EntityMsg* const sStep_d7_s37[] = { M(sMsg_d7_s37_0), M(sMsg_d7_s37_1), NULL };
static const EntityMsg* const sStep_d7_s38[] = { M(sMsg_d7_s38_0), M(sMsg_d7_s38_1), NULL };
static const EntityMsg* const sStep_d7_s39[] = { M(sMsg_d7_s39_0), M(sMsg_d7_s39_1), NULL };
static const EntityMsg* const sStep_d7_s40[] = { M(sMsg_d7_s40_0), M(sMsg_d7_s40_1), NULL };
static const EntityMsg* const sStep_d7_s41[] = { M(sMsg_d7_s41_0), M(sMsg_d7_s41_1), M(sMsg_d7_s41_2), M(sMsg_d7_s41_3), NULL };
static const EntityMsg* const sStep_d7_s42[] = { M(sMsg_d7_s42_0), NULL };
static const EntityMsg* const sStep_d7_s43[] = { M(sMsg_d7_s43_0), NULL };
static const EntityMsg* const sStep_d7_s44[] = { M(sMsg_d7_s44_0), NULL };
static const EntityMsg* const sStep_d7_s45[] = { M(sMsg_d7_s45_0), NULL };
static const EntityMsg* const sStep_d8_s0[] = { M(sMsg_d8_s0_0), NULL };
static const EntityMsg* const sStep_d8_s1[] = { M(sMsg_d8_s1_0), M(sMsg_d8_s1_1), NULL };
static const EntityMsg* const sStep_d8_s2[] = { M(sMsg_d8_s2_0), NULL };
static const EntityMsg* const sStep_d8_s3[] = { M(sMsg_d8_s3_0), M(sMsg_d8_s3_1), NULL };
static const EntityMsg* const sStep_d8_s4[] = { M(sMsg_d8_s4_0), NULL };
static const EntityMsg* const sStep_d8_s5[] = { M(sMsg_d8_s5_0), NULL };
static const EntityMsg* const sStep_d8_s6[] = { M(sMsg_d8_s6_0), M(sMsg_d8_s6_1), NULL };
static const EntityMsg* const sStep_d9_s0[] = { M(sMsg_d9_s0_0), NULL };
static const EntityMsg* const sStep_d9_s1[] = { M(sMsg_d9_s1_0), M(sMsg_d9_s1_1), NULL };
static const EntityMsg* const sStep_d9_s2[] = { M(sMsg_d9_s2_0), NULL };
static const EntityMsg* const sStep_d9_s3[] = { M(sMsg_d9_s3_0), NULL };
static const EntityMsg* const sStep_d9_s4[] = { M(sMsg_d9_s4_0), M(sMsg_d9_s4_1), M(sMsg_d9_s4_2), NULL };
static const EntityMsg* const sStep_d9_s5[] = { M(sMsg_d9_s5_0), NULL };
static const EntityMsg* const sStep_d9_s6[] = { M(sMsg_d9_s6_0), NULL };
static const EntityMsg* const sStep_d9_s7[] = { M(sMsg_d9_s7_0), M(sMsg_d9_s7_1), NULL };
static const EntityMsg* const sStep_d10_s0[] = { M(sMsg_d10_s0_0), M(sMsg_d10_s0_1), NULL };
static const EntityMsg* const sStep_d10_s1[] = { M(sMsg_d10_s1_0), M(sMsg_d10_s1_1), NULL };
static const EntityMsg* const sStep_d10_s2[] = { M(sMsg_d10_s2_0), NULL };
static const EntityMsg* const sStep_d10_s3[] = { M(sMsg_d10_s3_0), M(sMsg_d10_s3_1), NULL };
static const EntityMsg* const sStep_d10_s4[] = { M(sMsg_d10_s4_0), M(sMsg_d10_s4_1), M(sMsg_d10_s4_2), NULL };
static const EntityMsg* const sStep_d10_s5[] = { M(sMsg_d10_s5_0), M(sMsg_d10_s5_1), M(sMsg_d10_s5_2), M(sMsg_d10_s5_3), NULL };
static const EntityMsg* const sStep_d10_s6[] = { M(sMsg_d10_s6_0), NULL };
static const EntityMsg* const sStep_d10_s7[] = { M(sMsg_d10_s7_0), NULL };
static const EntityMsg* const sStep_d10_s8[] = { M(sMsg_d10_s8_0), NULL };
static const EntityMsg* const sStep_d10_s9[] = { M(sMsg_d10_s9_0), NULL };
static const EntityMsg* const sStep_d10_s10[] = { M(sMsg_d10_s10_0), NULL };
static const EntityMsg* const sStep_d10_s11[] = { M(sMsg_d10_s11_0), NULL };
static const EntityMsg* const sStep_d10_s12[] = { M(sMsg_d10_s12_0), NULL };
static const EntityMsg* const sStep_d10_s13[] = { M(sMsg_d10_s13_0), NULL };
static const EntityMsg* const sStep_d10_s14[] = { M(sMsg_d10_s14_0), NULL };
static const EntityMsg* const sStep_d10_s15[] = { M(sMsg_d10_s15_0), NULL };
static const EntityMsg* const sStep_d10_s16[] = { M(sMsg_d10_s16_0), NULL };
static const EntityMsg* const sStep_d10_s17[] = { M(sMsg_d10_s17_0), M(sMsg_d10_s17_1), NULL };
static const EntityMsg* const sStep_d10_s18[] = { M(sMsg_d10_s18_0), NULL };
static const EntityMsg* const sStep_d10_s19[] = { M(sMsg_d10_s19_0), NULL };
static const EntityMsg* const sStep_d10_s20[] = { M(sMsg_d10_s20_0), M(sMsg_d10_s20_1), M(sMsg_d10_s20_2), NULL };
static const EntityMsg* const sStep_d10_s21[] = { M(sMsg_d10_s21_0), NULL };
static const EntityMsg* const sStep_d10_s22[] = { M(sMsg_d10_s22_0), NULL };
static const EntityMsg* const sStep_d10_s23[] = { M(sMsg_d10_s23_0), M(sMsg_d10_s23_1), NULL };
static const EntityMsg* const sStep_d10_s24[] = { M(sMsg_d10_s24_0), M(sMsg_d10_s24_1), M(sMsg_d10_s24_2), M(sMsg_d10_s24_3), NULL };
static const EntityMsg* const sStep_d10_s25[] = { M(sMsg_d10_s25_0), NULL };
static const EntityMsg* const sStep_d10_s26[] = { M(sMsg_d10_s26_0), NULL };
static const EntityMsg* const sStep_d10_s27[] = { M(sMsg_d10_s27_0), M(sMsg_d10_s27_1), NULL };
static const EntityMsg* const sStep_d10_s28[] = { M(sMsg_d10_s28_0), NULL };
static const EntityMsg* const sStep_d10_s29[] = { M(sMsg_d10_s29_0), M(sMsg_d10_s29_1), M(sMsg_d10_s29_2), NULL };
static const EntityMsg* const sStep_d10_s30[] = { M(sMsg_d10_s30_0), M(sMsg_d10_s30_1), M(sMsg_d10_s30_2), M(sMsg_d10_s30_3), NULL };
static const EntityMsg* const sStep_d10_s31[] = { M(sMsg_d10_s31_0), M(sMsg_d10_s31_1), NULL };
static const EntityMsg* const sStep_d10_s32[] = { M(sMsg_d10_s32_0), M(sMsg_d10_s32_1), M(sMsg_d10_s32_2), M(sMsg_d10_s32_3), NULL };
static const EntityMsg* const sStep_d10_s33[] = { M(sMsg_d10_s33_0), NULL };
static const EntityMsg* const sStep_d10_s34[] = { M(sMsg_d10_s34_0), NULL };
static const EntityMsg* const sStep_d10_s35[] = { M(sMsg_d10_s35_0), M(sMsg_d10_s35_1), NULL };
static const EntityMsg* const sStep_d10_s36[] = { M(sMsg_d10_s36_0), M(sMsg_d10_s36_1), M(sMsg_d10_s36_2), NULL };
static const EntityMsg* const sStep_d11_s0[] = { M(sMsg_d11_s0_0), M(sMsg_d11_s0_1), M(sMsg_d11_s0_2), NULL };
static const EntityMsg* const sStep_d11_s1[] = { M(sMsg_d11_s1_0), M(sMsg_d11_s1_1), NULL };
static const EntityMsg* const sStep_d11_s2[] = { M(sMsg_d11_s2_0), M(sMsg_d11_s2_1), M(sMsg_d11_s2_2), NULL };
static const EntityMsg* const sStep_d11_s3[] = { M(sMsg_d11_s3_0), NULL };
static const EntityMsg* const sStep_d11_s4[] = { M(sMsg_d11_s4_0), M(sMsg_d11_s4_1), NULL };
static const EntityMsg* const sStep_d11_s5[] = { M(sMsg_d11_s5_0), NULL };
static const EntityMsg* const sStep_d11_s6[] = { M(sMsg_d11_s6_0), NULL };
static const EntityMsg* const sStep_d11_s7[] = { M(sMsg_d11_s7_0), NULL };
static const EntityMsg* const sStep_d11_s8[] = { M(sMsg_d11_s8_0), NULL };
static const EntityMsg* const sStep_d11_s9[] = { M(sMsg_d11_s9_0), NULL };
static const EntityMsg* const sStep_d11_s10[] = { M(sMsg_d11_s10_0), M(sMsg_d11_s10_1), NULL };
static const EntityMsg* const sStep_d11_s11[] = { M(sMsg_d11_s11_0), NULL };
static const EntityMsg* const sStep_d11_s12[] = { M(sMsg_d11_s12_0), NULL };
static const EntityMsg* const sStep_d11_s13[] = { M(sMsg_d11_s13_0), M(sMsg_d11_s13_1), NULL };
static const EntityMsg* const sStep_d11_s14[] = { M(sMsg_d11_s14_0), NULL };
static const EntityMsg* const sStep_d11_s15[] = { M(sMsg_d11_s15_0), NULL };
static const EntityMsg* const sStep_d11_s16[] = { M(sMsg_d11_s16_0), NULL };
static const EntityMsg* const sStep_d11_s17[] = { M(sMsg_d11_s17_0), NULL };
static const EntityMsg* const sStep_d11_s18[] = { M(sMsg_d11_s18_0), NULL };
static const EntityMsg* const sStep_d11_s19[] = { M(sMsg_d11_s19_0), M(sMsg_d11_s19_1), NULL };
static const EntityMsg* const sStep_d11_s20[] = { M(sMsg_d11_s20_0), NULL };
static const EntityMsg* const sStep_d11_s21[] = { M(sMsg_d11_s21_0), NULL };
static const EntityMsg* const sStep_d11_s22[] = { M(sMsg_d11_s22_0), NULL };
static const EntityMsg* const sStep_d11_s23[] = { M(sMsg_d11_s23_0), NULL };
static const EntityMsg* const sStep_d11_s24[] = { M(sMsg_d11_s24_0), NULL };
static const EntityMsg* const sStep_d11_s25[] = { M(sMsg_d11_s25_0), NULL };
static const EntityMsg* const sStep_d11_s26[] = { M(sMsg_d11_s26_0), NULL };
static const EntityMsg* const sStep_d11_s27[] = { M(sMsg_d11_s27_0), NULL };
static const EntityMsg* const sStep_d11_s28[] = { M(sMsg_d11_s28_0), M(sMsg_d11_s28_1), NULL };
static const EntityMsg* const sStep_d11_s29[] = { M(sMsg_d11_s29_0), NULL };
static const EntityMsg* const sStep_d11_s30[] = { M(sMsg_d11_s30_0), NULL };
static const EntityMsg* const sStep_d11_s31[] = { M(sMsg_d11_s31_0), M(sMsg_d11_s31_1), M(sMsg_d11_s31_2), NULL };
static const EntityMsg* const sStep_d11_s32[] = { M(sMsg_d11_s32_0), NULL };
static const EntityMsg* const sStep_d11_s33[] = { M(sMsg_d11_s33_0), NULL };
static const EntityMsg* const sStep_d11_s34[] = { M(sMsg_d11_s34_0), M(sMsg_d11_s34_1), NULL };
static const EntityMsg* const sStep_d11_s35[] = { M(sMsg_d11_s35_0), M(sMsg_d11_s35_1), M(sMsg_d11_s35_2), M(sMsg_d11_s35_3), NULL };
static const EntityMsg* const sStep_d11_s36[] = { M(sMsg_d11_s36_0), NULL };
static const EntityMsg* const sStep_d11_s37[] = { M(sMsg_d11_s37_0), NULL };
static const EntityMsg* const sStep_d11_s38[] = { M(sMsg_d11_s38_0), M(sMsg_d11_s38_1), M(sMsg_d11_s38_2), NULL };
static const EntityMsg* const sStep_d11_s39[] = { M(sMsg_d11_s39_0), NULL };
static const EntityMsg* const sStep_d11_s40[] = { M(sMsg_d11_s40_0), M(sMsg_d11_s40_1), NULL };
static const EntityMsg* const sStep_d12_s0[] = { M(sMsg_d12_s0_0), NULL };
static const EntityMsg* const sStep_d12_s1[] = { M(sMsg_d12_s1_0), NULL };
static const EntityMsg* const sStep_d12_s2[] = { M(sMsg_d12_s2_0), NULL };
static const EntityMsg* const sStep_d12_s3[] = { M(sMsg_d12_s3_0), M(sMsg_d12_s3_1), M(sMsg_d12_s3_2), NULL };
static const EntityMsg* const sStep_d12_s4[] = { M(sMsg_d12_s4_0), NULL };
static const EntityMsg* const sStep_d12_s5[] = { M(sMsg_d12_s5_0), NULL };
static const EntityMsg* const sStep_d12_s6[] = { M(sMsg_d12_s6_0), M(sMsg_d12_s6_1), M(sMsg_d12_s6_2), M(sMsg_d12_s6_3), M(sMsg_d12_s6_4), M(sMsg_d12_s6_5), NULL };
static const EntityMsg* const sStep_d12_s7[] = { M(sMsg_d12_s7_0), NULL };
static const EntityMsg* const sStep_d12_s8[] = { M(sMsg_d12_s8_0), NULL };
static const EntityMsg* const sStep_d12_s9[] = { M(sMsg_d12_s9_0), M(sMsg_d12_s9_1), NULL };
static const EntityMsg* const sStep_d13_s0[] = { M(sMsg_d13_s0_0), NULL };
static const EntityMsg* const sStep_d13_s1[] = { M(sMsg_d13_s1_0), NULL };
static const EntityMsg* const sStep_d13_s2[] = { M(sMsg_d13_s2_0), NULL };
static const EntityMsg* const sStep_d13_s3[] = { M(sMsg_d13_s3_0), M(sMsg_d13_s3_1), M(sMsg_d13_s3_2), NULL };
static const EntityMsg* const sStep_d13_s4[] = { M(sMsg_d13_s4_0), NULL };
static const EntityMsg* const sStep_d13_s5[] = { M(sMsg_d13_s5_0), NULL };
static const EntityMsg* const sStep_d13_s6[] = { M(sMsg_d13_s6_0), M(sMsg_d13_s6_1), M(sMsg_d13_s6_2), M(sMsg_d13_s6_3), M(sMsg_d13_s6_4), NULL };
static const EntityMsg* const sStep_d13_s7[] = { M(sMsg_d13_s7_0), NULL };
static const EntityMsg* const sStep_d13_s8[] = { M(sMsg_d13_s8_0), NULL };
static const EntityMsg* const sStep_d13_s9[] = { M(sMsg_d13_s9_0), NULL };
static const EntityMsg* const sStep_d14_s0[] = { M(sMsg_d14_s0_0), M(sMsg_d14_s0_1), M(sMsg_d14_s0_2), M(sMsg_d14_s0_3), NULL };
static const EntityMsg* const sStep_d14_s1[] = { M(sMsg_d14_s1_0), M(sMsg_d14_s1_1), NULL };
static const EntityMsg* const sStep_d14_s2[] = { M(sMsg_d14_s2_0), M(sMsg_d14_s2_1), NULL };
static const EntityMsg* const sStep_d14_s3[] = { M(sMsg_d14_s3_0), NULL };
static const EntityMsg* const sStep_d14_s4[] = { M(sMsg_d14_s4_0), NULL };
static const EntityMsg* const sStep_d14_s5[] = { M(sMsg_d14_s5_0), NULL };
static const EntityMsg* const sStep_d14_s6[] = { M(sMsg_d14_s6_0), NULL };
static const EntityMsg* const sStep_d14_s7[] = { M(sMsg_d14_s7_0), M(sMsg_d14_s7_1), NULL };
static const EntityMsg* const sStep_d14_s8[] = { M(sMsg_d14_s8_0), M(sMsg_d14_s8_1), M(sMsg_d14_s8_2), NULL };
static const EntityMsg* const sStep_d14_s9[] = { M(sMsg_d14_s9_0), M(sMsg_d14_s9_1), M(sMsg_d14_s9_2), NULL };
static const EntityMsg* const sStep_d14_s10[] = { M(sMsg_d14_s10_0), NULL };
static const EntityMsg* const sStep_d14_s11[] = { M(sMsg_d14_s11_0), NULL };
static const EntityMsg* const sStep_d14_s12[] = { M(sMsg_d14_s12_0), M(sMsg_d14_s12_1), NULL };
static const EntityMsg* const sStep_d14_s13[] = { M(sMsg_d14_s13_0), M(sMsg_d14_s13_1), NULL };
static const EntityMsg* const sStep_d14_s14[] = { M(sMsg_d14_s14_0), NULL };
static const EntityMsg* const sStep_d14_s15[] = { M(sMsg_d14_s15_0), NULL };
static const EntityMsg* const sStep_d14_s16[] = { M(sMsg_d14_s16_0), M(sMsg_d14_s16_1), M(sMsg_d14_s16_2), NULL };
static const EntityMsg* const sStep_d14_s17[] = { M(sMsg_d14_s17_0), M(sMsg_d14_s17_1), M(sMsg_d14_s17_2), NULL };
static const EntityMsg* const sStep_d14_s18[] = { M(sMsg_d14_s18_0), M(sMsg_d14_s18_1), M(sMsg_d14_s18_2), M(sMsg_d14_s18_3), M(sMsg_d14_s18_4), M(sMsg_d14_s18_5), M(sMsg_d14_s18_6), NULL };
static const EntityMsg* const sStep_d14_s19[] = { M(sMsg_d14_s19_0), M(sMsg_d14_s19_1), NULL };
static const EntityMsg* const sStep_d14_s20[] = { M(sMsg_d14_s20_0), NULL };
static const EntityMsg* const sStep_d14_s21[] = { M(sMsg_d14_s21_0), NULL };
static const EntityMsg* const sStep_d14_s22[] = { M(sMsg_d14_s22_0), M(sMsg_d14_s22_1), M(sMsg_d14_s22_2), NULL };
static const EntityMsg* const sStep_d14_s23[] = { M(sMsg_d14_s23_0), NULL };
static const EntityMsg* const sStep_d14_s24[] = { M(sMsg_d14_s24_0), NULL };
static const EntityMsg* const sStep_d14_s25[] = { M(sMsg_d14_s25_0), M(sMsg_d14_s25_1), M(sMsg_d14_s25_2), M(sMsg_d14_s25_3), NULL };
static const EntityMsg* const sStep_d14_s26[] = { M(sMsg_d14_s26_0), M(sMsg_d14_s26_1), NULL };
static const EntityMsg* const sStep_d14_s27[] = { M(sMsg_d14_s27_0), M(sMsg_d14_s27_1), NULL };
static const EntityMsg* const sStep_d14_s28[] = { M(sMsg_d14_s28_0), NULL };
static const EntityMsg* const sStep_d14_s29[] = { M(sMsg_d14_s29_0), NULL };
static const EntityMsg* const sStep_d14_s30[] = { M(sMsg_d14_s30_0), M(sMsg_d14_s30_1), M(sMsg_d14_s30_2), M(sMsg_d14_s30_3), M(sMsg_d14_s30_4), NULL };
static const EntityMsg* const sStep_d14_s31[] = { M(sMsg_d14_s31_0), M(sMsg_d14_s31_1), NULL };
static const EntityMsg* const sStep_d14_s32[] = { M(sMsg_d14_s32_0), M(sMsg_d14_s32_1), M(sMsg_d14_s32_2), NULL };
static const EntityMsg* const sStep_d14_s33[] = { M(sMsg_d14_s33_0), NULL };
static const EntityMsg* const sStep_d14_s34[] = { M(sMsg_d14_s34_0), NULL };
static const EntityMsg* const sStep_d15_s0[] = { M(sMsg_d15_s0_0), M(sMsg_d15_s0_1), M(sMsg_d15_s0_2), NULL };
static const EntityMsg* const sStep_d15_s1[] = { M(sMsg_d15_s1_0), NULL };
static const EntityMsg* const sStep_d15_s2[] = { M(sMsg_d15_s2_0), NULL };
static const EntityMsg* const sStep_d15_s3[] = { M(sMsg_d15_s3_0), NULL };
static const EntityMsg* const sStep_d15_s4[] = { M(sMsg_d15_s4_0), M(sMsg_d15_s4_1), M(sMsg_d15_s4_2), NULL };
static const EntityMsg* const sStep_d15_s5[] = { M(sMsg_d15_s5_0), NULL };
static const EntityMsg* const sStep_d15_s6[] = { M(sMsg_d15_s6_0), M(sMsg_d15_s6_1), NULL };
static const EntityMsg* const sStep_d15_s7[] = { M(sMsg_d15_s7_0), M(sMsg_d15_s7_1), M(sMsg_d15_s7_2), NULL };
static const EntityMsg* const sStep_d15_s8[] = { M(sMsg_d15_s8_0), NULL };
static const EntityMsg* const sStep_d15_s9[] = { M(sMsg_d15_s9_0), M(sMsg_d15_s9_1), M(sMsg_d15_s9_2), M(sMsg_d15_s9_3), M(sMsg_d15_s9_4), M(sMsg_d15_s9_5), NULL };
static const EntityMsg* const sStep_d15_s10[] = { M(sMsg_d15_s10_0), M(sMsg_d15_s10_1), M(sMsg_d15_s10_2), NULL };
static const EntityMsg* const sStep_d15_s11[] = { M(sMsg_d15_s11_0), M(sMsg_d15_s11_1), M(sMsg_d15_s11_2), M(sMsg_d15_s11_3), NULL };
static const EntityMsg* const sStep_d15_s12[] = { M(sMsg_d15_s12_0), M(sMsg_d15_s12_1), M(sMsg_d15_s12_2), NULL };
static const EntityMsg* const sStep_d15_s13[] = { M(sMsg_d15_s13_0), M(sMsg_d15_s13_1), M(sMsg_d15_s13_2), NULL };
static const EntityMsg* const sStep_d15_s14[] = { M(sMsg_d15_s14_0), NULL };
static const EntityMsg* const sStep_d15_s15[] = { M(sMsg_d15_s15_0), NULL };
static const EntityMsg* const sStep_d15_s16[] = { M(sMsg_d15_s16_0), M(sMsg_d15_s16_1), M(sMsg_d15_s16_2), NULL };
static const EntityMsg* const sStep_d15_s17[] = { M(sMsg_d15_s17_0), M(sMsg_d15_s17_1), NULL };
static const EntityMsg* const sStep_d15_s18[] = { M(sMsg_d15_s18_0), M(sMsg_d15_s18_1), M(sMsg_d15_s18_2), NULL };
static const EntityMsg* const sStep_d15_s19[] = { M(sMsg_d15_s19_0), M(sMsg_d15_s19_1), NULL };
static const EntityMsg* const sStep_d15_s20[] = { M(sMsg_d15_s20_0), M(sMsg_d15_s20_1), NULL };
static const EntityMsg* const sStep_d15_s21[] = { M(sMsg_d15_s21_0), M(sMsg_d15_s21_1), NULL };
static const EntityMsg* const sStep_d15_s22[] = { M(sMsg_d15_s22_0), M(sMsg_d15_s22_1), NULL };
static const EntityMsg* const sStep_d15_s23[] = { M(sMsg_d15_s23_0), M(sMsg_d15_s23_1), NULL };
static const EntityMsg* const sStep_d15_s24[] = { M(sMsg_d15_s24_0), NULL };
static const EntityMsg* const sStep_d15_s25[] = { M(sMsg_d15_s25_0), NULL };
static const EntityMsg* const sStep_d15_s26[] = { M(sMsg_d15_s26_0), NULL };
static const EntityMsg* const sStep_d15_s27[] = { M(sMsg_d15_s27_0), M(sMsg_d15_s27_1), NULL };
static const EntityMsg* const sStep_d15_s28[] = { M(sMsg_d15_s28_0), NULL };
static const EntityMsg* const sStep_d15_s29[] = { M(sMsg_d15_s29_0), NULL };
static const EntityMsg* const sStep_d15_s30[] = { M(sMsg_d15_s30_0), NULL };
static const EntityMsg* const sStep_d15_s31[] = { M(sMsg_d15_s31_0), M(sMsg_d15_s31_1), NULL };
static const EntityMsg* const sStep_d15_s32[] = { M(sMsg_d15_s32_0), NULL };
static const EntityMsg* const sStep_d15_s33[] = { M(sMsg_d15_s33_0), NULL };
static const EntityMsg* const sStep_d15_s34[] = { M(sMsg_d15_s34_0), M(sMsg_d15_s34_1), NULL };
static const EntityMsg* const sStep_d15_s35[] = { M(sMsg_d15_s35_0), NULL };
static const EntityMsg* const sStep_d15_s36[] = { M(sMsg_d15_s36_0), NULL };
static const EntityMsg* const sStep_d15_s37[] = { M(sMsg_d15_s37_0), NULL };
static const EntityMsg* const sStep_d15_s38[] = { M(sMsg_d15_s38_0), M(sMsg_d15_s38_1), NULL };
static const EntityMsg* const sStep_d15_s39[] = { M(sMsg_d15_s39_0), NULL };
static const EntityMsg* const sStep_d15_s40[] = { M(sMsg_d15_s40_0), NULL };
static const EntityMsg* const sStep_d16_s0[] = { M(sMsg_d16_s0_0), M(sMsg_d16_s0_1), M(sMsg_d16_s0_2), NULL };
static const EntityMsg* const sStep_d16_s1[] = { M(sMsg_d16_s1_0), NULL };
static const EntityMsg* const sStep_d16_s2[] = { M(sMsg_d16_s2_0), NULL };
static const EntityMsg* const sStep_d16_s3[] = { M(sMsg_d16_s3_0), NULL };
static const EntityMsg* const sStep_d16_s4[] = { M(sMsg_d16_s4_0), NULL };
static const EntityMsg* const sStep_d16_s5[] = { M(sMsg_d16_s5_0), M(sMsg_d16_s5_1), NULL };
static const EntityMsg* const sStep_d16_s6[] = { M(sMsg_d16_s6_0), NULL };
static const EntityMsg* const sStep_d16_s7[] = { M(sMsg_d16_s7_0), NULL };
static const EntityMsg* const sStep_d17_s0[] = { M(sMsg_d17_s0_0), M(sMsg_d17_s0_1), NULL };
static const EntityMsg* const sStep_d17_s1[] = { M(sMsg_d17_s1_0), M(sMsg_d17_s1_1), NULL };
static const EntityMsg* const sStep_d17_s2[] = { M(sMsg_d17_s2_0), NULL };
static const EntityMsg* const sStep_d17_s3[] = { M(sMsg_d17_s3_0), M(sMsg_d17_s3_1), NULL };
static const EntityMsg* const sStep_d17_s4[] = { M(sMsg_d17_s4_0), M(sMsg_d17_s4_1), NULL };
static const EntityMsg* const sStep_d17_s5[] = { M(sMsg_d17_s5_0), NULL };
static const EntityMsg* const sStep_d17_s6[] = { M(sMsg_d17_s6_0), NULL };
static const EntityMsg* const sStep_d17_s7[] = { M(sMsg_d17_s7_0), NULL };
static const EntityMsg* const sStep_d17_s8[] = { M(sMsg_d17_s8_0), NULL };
static const EntityMsg* const sStep_d17_s9[] = { M(sMsg_d17_s9_0), NULL };
static const EntityMsg* const sStep_d17_s10[] = { M(sMsg_d17_s10_0), NULL };
static const EntityMsg* const sStep_d17_s11[] = { M(sMsg_d17_s11_0), NULL };
static const EntityMsg* const sStep_d17_s12[] = { M(sMsg_d17_s12_0), M(sMsg_d17_s12_1), M(sMsg_d17_s12_2), NULL };
static const EntityMsg* const sStep_d18_s0[] = { M(sMsg_d18_s0_0), M(sMsg_d18_s0_1), M(sMsg_d18_s0_2), NULL };
static const EntityMsg* const sStep_d18_s1[] = { M(sMsg_d18_s1_0), M(sMsg_d18_s1_1), NULL };
static const EntityMsg* const sStep_d18_s2[] = { M(sMsg_d18_s2_0), NULL };
static const EntityMsg* const sStep_d18_s3[] = { M(sMsg_d18_s3_0), M(sMsg_d18_s3_1), NULL };
static const EntityMsg* const sStep_d18_s4[] = { M(sMsg_d18_s4_0), M(sMsg_d18_s4_1), NULL };
static const EntityMsg* const sStep_d18_s5[] = { M(sMsg_d18_s5_0), NULL };
static const EntityMsg* const sStep_d18_s6[] = { M(sMsg_d18_s6_0), NULL };
static const EntityMsg* const sStep_d18_s7[] = { M(sMsg_d18_s7_0), NULL };
static const EntityMsg* const sStep_d18_s8[] = { M(sMsg_d18_s8_0), NULL };
static const EntityMsg* const sStep_d18_s9[] = { M(sMsg_d18_s9_0), NULL };
static const EntityMsg* const sStep_d18_s10[] = { M(sMsg_d18_s10_0), M(sMsg_d18_s10_1), M(sMsg_d18_s10_2), NULL };
static const EntityMsg* const sStep_d19_s0[] = { M(sMsg_d19_s0_0), NULL };
static const EntityMsg* const sStep_d19_s1[] = { M(sMsg_d19_s1_0), M(sMsg_d19_s1_1), NULL };
static const EntityMsg* const sStep_d19_s2[] = { M(sMsg_d19_s2_0), M(sMsg_d19_s2_1), NULL };
static const EntityMsg* const sStep_d19_s3[] = { M(sMsg_d19_s3_0), M(sMsg_d19_s3_1), NULL };
static const EntityMsg* const sStep_d19_s4[] = { M(sMsg_d19_s4_0), NULL };
static const EntityMsg* const sStep_d19_s5[] = { M(sMsg_d19_s5_0), NULL };
static const EntityMsg* const sStep_d19_s6[] = { M(sMsg_d19_s6_0), NULL };
static const EntityMsg* const sStep_d19_s7[] = { M(sMsg_d19_s7_0), NULL };
static const EntityMsg* const sStep_d19_s8[] = { M(sMsg_d19_s8_0), NULL };
static const EntityMsg* const sStep_d19_s9[] = { M(sMsg_d19_s9_0), NULL };
static const EntityMsg* const sStep_d19_s10[] = { M(sMsg_d19_s10_0), NULL };
static const EntityMsg* const sStep_d19_s11[] = { M(sMsg_d19_s11_0), NULL };
static const EntityMsg* const sStep_d19_s12[] = { M(sMsg_d19_s12_0), NULL };
static const EntityMsg* const sStep_d19_s13[] = { M(sMsg_d19_s13_0), NULL };
static const EntityMsg* const sStep_d19_s14[] = { M(sMsg_d19_s14_0), NULL };
static const EntityMsg* const sStep_d19_s15[] = { M(sMsg_d19_s15_0), M(sMsg_d19_s15_1), NULL };
static const EntityMsg* const sStep_d19_s16[] = { M(sMsg_d19_s16_0), NULL };
static const EntityMsg* const sStep_d19_s17[] = { M(sMsg_d19_s17_0), NULL };
static const EntityMsg* const sStep_d19_s18[] = { M(sMsg_d19_s18_0), NULL };
static const EntityMsg* const sStep_d19_s19[] = { M(sMsg_d19_s19_0), M(sMsg_d19_s19_1), NULL };
static const EntityMsg* const sStep_d20_s0[] = { M(sMsg_d20_s0_0), M(sMsg_d20_s0_1), NULL };
static const EntityMsg* const sStep_d20_s1[] = { M(sMsg_d20_s1_0), NULL };
static const EntityMsg* const sStep_d20_s2[] = { M(sMsg_d20_s2_0), NULL };
static const EntityMsg* const sStep_d20_s3[] = { M(sMsg_d20_s3_0), M(sMsg_d20_s3_1), NULL };
static const EntityMsg* const sStep_d20_s4[] = { M(sMsg_d20_s4_0), NULL };
static const EntityMsg* const sStep_d20_s5[] = { M(sMsg_d20_s5_0), NULL };
static const EntityMsg* const sStep_d20_s6[] = { M(sMsg_d20_s6_0), M(sMsg_d20_s6_1), NULL };
static const EntityMsg* const sStep_d20_s7[] = { M(sMsg_d20_s7_0), NULL };
static const EntityMsg* const sStep_d20_s8[] = { M(sMsg_d20_s8_0), NULL };
static const EntityMsg* const sStep_d20_s9[] = { M(sMsg_d20_s9_0), NULL };
static const EntityMsg* const sStep_d20_s10[] = { M(sMsg_d20_s10_0), NULL };
static const EntityMsg* const sStep_d20_s11[] = { M(sMsg_d20_s11_0), NULL };
static const EntityMsg* const sStep_d20_s12[] = { M(sMsg_d20_s12_0), NULL };
static const EntityMsg* const sStep_d20_s13[] = { M(sMsg_d20_s13_0), NULL };
static const EntityMsg* const sStep_d20_s14[] = { M(sMsg_d20_s14_0), NULL };
static const EntityMsg* const sStep_d20_s15[] = { M(sMsg_d20_s15_0), M(sMsg_d20_s15_1), NULL };
static const EntityMsg* const sStep_d20_s16[] = { M(sMsg_d20_s16_0), NULL };
static const EntityMsg* const sStep_d20_s17[] = { M(sMsg_d20_s17_0), NULL };
static const EntityMsg* const sStep_d20_s18[] = { M(sMsg_d20_s18_0), M(sMsg_d20_s18_1), NULL };
static const EntityMsg* const sStep_d21_s0[] = { M(sMsg_d21_s0_0), M(sMsg_d21_s0_1), NULL };
static const EntityMsg* const sStep_d21_s1[] = { M(sMsg_d21_s1_0), M(sMsg_d21_s1_1), M(sMsg_d21_s1_2), NULL };
static const EntityMsg* const sStep_d21_s2[] = { M(sMsg_d21_s2_0), NULL };
static const EntityMsg* const sStep_d21_s3[] = { M(sMsg_d21_s3_0), NULL };
static const EntityMsg* const sStep_d21_s4[] = { M(sMsg_d21_s4_0), M(sMsg_d21_s4_1), M(sMsg_d21_s4_2), NULL };
static const EntityMsg* const sStep_d21_s5[] = { M(sMsg_d21_s5_0), NULL };
static const EntityMsg* const sStep_d21_s6[] = { M(sMsg_d21_s6_0), NULL };
static const EntityMsg* const sStep_d21_s7[] = { M(sMsg_d21_s7_0), M(sMsg_d21_s7_1), M(sMsg_d21_s7_2), NULL };
static const EntityMsg* const sStep_d21_s8[] = { M(sMsg_d21_s8_0), M(sMsg_d21_s8_1), NULL };
static const EntityMsg* const sStep_d21_s9[] = { M(sMsg_d21_s9_0), NULL };
static const EntityMsg* const sStep_d21_s10[] = { M(sMsg_d21_s10_0), NULL };
static const EntityMsg* const sStep_d21_s11[] = { M(sMsg_d21_s11_0), M(sMsg_d21_s11_1), NULL };
static const EntityMsg* const sStep_d21_s12[] = { M(sMsg_d21_s12_0), NULL };
static const EntityMsg* const sStep_d21_s13[] = { M(sMsg_d21_s13_0), NULL };
static const EntityMsg* const sStep_d21_s14[] = { M(sMsg_d21_s14_0), NULL };
static const EntityMsg* const sStep_d21_s15[] = { M(sMsg_d21_s15_0), M(sMsg_d21_s15_1), NULL };
static const EntityMsg* const sStep_d21_s16[] = { M(sMsg_d21_s16_0), NULL };
static const EntityMsg* const sStep_d21_s17[] = { M(sMsg_d21_s17_0), NULL };
static const EntityMsg* const sStep_d21_s18[] = { M(sMsg_d21_s18_0), M(sMsg_d21_s18_1), NULL };
static const EntityMsg* const sStep_d21_s19[] = { M(sMsg_d21_s19_0), NULL };
static const EntityMsg* const sStep_d21_s20[] = { M(sMsg_d21_s20_0), NULL };
static const EntityMsg* const sStep_d21_s21[] = { M(sMsg_d21_s21_0), M(sMsg_d21_s21_1), NULL };
static const EntityMsg* const sStep_d21_s22[] = { M(sMsg_d21_s22_0), NULL };
static const EntityMsg* const sStep_d21_s23[] = { M(sMsg_d21_s23_0), NULL };
static const EntityMsg* const sStep_d21_s24[] = { M(sMsg_d21_s24_0), M(sMsg_d21_s24_1), NULL };
static const EntityMsg* const sStep_d21_s25[] = { M(sMsg_d21_s25_0), M(sMsg_d21_s25_1), NULL };
static const EntityMsg* const sStep_d21_s26[] = { M(sMsg_d21_s26_0), NULL };
static const EntityMsg* const sStep_d21_s27[] = { M(sMsg_d21_s27_0), NULL };
static const EntityMsg* const sStep_d21_s28[] = { M(sMsg_d21_s28_0), M(sMsg_d21_s28_1), M(sMsg_d21_s28_2), NULL };
static const EntityMsg* const sStep_d21_s29[] = { M(sMsg_d21_s29_0), NULL };
static const EntityMsg* const sStep_d21_s30[] = { M(sMsg_d21_s30_0), M(sMsg_d21_s30_1), NULL };
static const EntityMsg* const sStep_d21_s31[] = { M(sMsg_d21_s31_0), M(sMsg_d21_s31_1), NULL };
static const EntityMsg* const sStep_d22_s0[] = { M(sMsg_d22_s0_0), NULL };
static const EntityMsg* const sStep_d22_s1[] = { M(sMsg_d22_s1_0), M(sMsg_d22_s1_1), M(sMsg_d22_s1_2), NULL };
static const EntityMsg* const sStep_d22_s2[] = { M(sMsg_d22_s2_0), NULL };
static const EntityMsg* const sStep_d22_s3[] = { M(sMsg_d22_s3_0), NULL };
static const EntityMsg* const sStep_d22_s4[] = { M(sMsg_d22_s4_0), NULL };
static const EntityMsg* const sStep_d22_s5[] = { M(sMsg_d22_s5_0), M(sMsg_d22_s5_1), NULL };
static const EntityMsg* const sStep_d22_s6[] = { M(sMsg_d22_s6_0), NULL };
static const EntityMsg* const sStep_d22_s7[] = { M(sMsg_d22_s7_0), NULL };
static const EntityMsg* const sStep_d22_s8[] = { M(sMsg_d22_s8_0), M(sMsg_d22_s8_1), NULL };
static const EntityMsg* const sStep_d22_s9[] = { M(sMsg_d22_s9_0), M(sMsg_d22_s9_1), M(sMsg_d22_s9_2), NULL };
static const EntityMsg* const sStep_d22_s10[] = { M(sMsg_d22_s10_0), NULL };
static const EntityMsg* const sStep_d22_s11[] = { M(sMsg_d22_s11_0), NULL };
static const EntityMsg* const sStep_d22_s12[] = { M(sMsg_d22_s12_0), M(sMsg_d22_s12_1), NULL };
static const EntityMsg* const sStep_d22_s13[] = { M(sMsg_d22_s13_0), NULL };
static const EntityMsg* const sStep_d22_s14[] = { M(sMsg_d22_s14_0), NULL };
static const EntityMsg* const sStep_d22_s15[] = { M(sMsg_d22_s15_0), M(sMsg_d22_s15_1), NULL };
static const EntityMsg* const sStep_d22_s16[] = { M(sMsg_d22_s16_0), M(sMsg_d22_s16_1), NULL };
static const EntityMsg* const sStep_d22_s17[] = { M(sMsg_d22_s17_0), M(sMsg_d22_s17_1), NULL };
static const EntityMsg* const sStep_d22_s18[] = { M(sMsg_d22_s18_0), NULL };
static const EntityMsg* const sStep_d22_s19[] = { M(sMsg_d22_s19_0), NULL };
static const EntityMsg* const sStep_d22_s20[] = { M(sMsg_d22_s20_0), NULL };
static const EntityMsg* const sStep_d22_s21[] = { M(sMsg_d22_s21_0), M(sMsg_d22_s21_1), NULL };
static const EntityMsg* const sStep_d22_s22[] = { M(sMsg_d22_s22_0), NULL };
static const EntityMsg* const sStep_d22_s23[] = { M(sMsg_d22_s23_0), M(sMsg_d22_s23_1), NULL };
static const EntityMsg* const sStep_d22_s24[] = { M(sMsg_d22_s24_0), M(sMsg_d22_s24_1), NULL };
static const EntityMsg* const sStep_d23_s0[] = { M(sMsg_d23_s0_0), M(sMsg_d23_s0_1), M(sMsg_d23_s0_2), M(sMsg_d23_s0_3), NULL };
static const EntityMsg* const sStep_d23_s1[] = { M(sMsg_d23_s1_0), M(sMsg_d23_s1_1), NULL };
static const EntityMsg* const sStep_d23_s2[] = { M(sMsg_d23_s2_0), NULL };
static const EntityMsg* const sStep_d23_s3[] = { M(sMsg_d23_s3_0), NULL };
static const EntityMsg* const sStep_d23_s4[] = { M(sMsg_d23_s4_0), NULL };
static const EntityMsg* const sStep_d23_s5[] = { M(sMsg_d23_s5_0), NULL };
static const EntityMsg* const sStep_d23_s6[] = { M(sMsg_d23_s6_0), NULL };
static const EntityMsg* const sStep_d23_s7[] = { M(sMsg_d23_s7_0), M(sMsg_d23_s7_1), NULL };
static const EntityMsg* const sStep_d23_s8[] = { M(sMsg_d23_s8_0), M(sMsg_d23_s8_1), M(sMsg_d23_s8_2), M(sMsg_d23_s8_3), NULL };
static const EntityMsg* const sStep_d23_s9[] = { M(sMsg_d23_s9_0), M(sMsg_d23_s9_1), NULL };
static const EntityMsg* const sStep_d23_s10[] = { M(sMsg_d23_s10_0), M(sMsg_d23_s10_1), M(sMsg_d23_s10_2), M(sMsg_d23_s10_3), M(sMsg_d23_s10_4), NULL };
static const EntityMsg* const sStep_d23_s11[] = { M(sMsg_d23_s11_0), M(sMsg_d23_s11_1), M(sMsg_d23_s11_2), NULL };
static const EntityMsg* const sStep_d23_s12[] = { M(sMsg_d23_s12_0), NULL };
static const EntityMsg* const sStep_d23_s13[] = { M(sMsg_d23_s13_0), NULL };
static const EntityMsg* const sStep_d23_s14[] = { M(sMsg_d23_s14_0), M(sMsg_d23_s14_1), M(sMsg_d23_s14_2), NULL };
static const EntityMsg* const sStep_d23_s15[] = { M(sMsg_d23_s15_0), M(sMsg_d23_s15_1), NULL };
static const EntityMsg* const sStep_d24_s0[] = { M(sMsg_d24_s0_0), NULL };
static const EntityMsg* const sStep_d24_s1[] = { M(sMsg_d24_s1_0), M(sMsg_d24_s1_1), NULL };
static const EntityMsg* const sStep_d24_s2[] = { M(sMsg_d24_s2_0), M(sMsg_d24_s2_1), NULL };
static const EntityMsg* const sStep_d24_s3[] = { M(sMsg_d24_s3_0), M(sMsg_d24_s3_1), NULL };
static const EntityMsg* const sStep_d24_s4[] = { M(sMsg_d24_s4_0), M(sMsg_d24_s4_1), NULL };
static const EntityMsg* const sStep_d24_s5[] = { M(sMsg_d24_s5_0), M(sMsg_d24_s5_1), NULL };
static const EntityMsg* const sStep_d24_s6[] = { M(sMsg_d24_s6_0), NULL };
static const EntityMsg* const sStep_d25_s0[] = { M(sMsg_d25_s0_0), NULL };
static const EntityMsg* const sStep_d25_s1[] = { M(sMsg_d25_s1_0), NULL };
static const EntityMsg* const sStep_d25_s2[] = { M(sMsg_d25_s2_0), NULL };
static const EntityMsg* const sStep_d25_s3[] = { M(sMsg_d25_s3_0), NULL };
static const EntityMsg* const sStep_d25_s4[] = { M(sMsg_d25_s4_0), M(sMsg_d25_s4_1), NULL };
static const EntityMsg* const sStep_d26_s0[] = { M(sMsg_d26_s0_0), M(sMsg_d26_s0_1), NULL };
static const EntityMsg* const sStep_d26_s1[] = { M(sMsg_d26_s1_0), M(sMsg_d26_s1_1), NULL };
static const EntityMsg* const sStep_d26_s2[] = { M(sMsg_d26_s2_0), M(sMsg_d26_s2_1), M(sMsg_d26_s2_2), NULL };
static const EntityMsg* const sStep_d26_s3[] = { M(sMsg_d26_s3_0), NULL };
static const EntityMsg* const sStep_d26_s4[] = { M(sMsg_d26_s4_0), NULL };
static const EntityMsg* const sStep_d26_s5[] = { M(sMsg_d26_s5_0), M(sMsg_d26_s5_1), NULL };
static const EntityMsg* const sStep_d26_s6[] = { M(sMsg_d26_s6_0), NULL };
static const EntityMsg* const sStep_d26_s7[] = { M(sMsg_d26_s7_0), NULL };
static const EntityMsg* const sStep_d26_s8[] = { M(sMsg_d26_s8_0), NULL };
static const EntityMsg* const sStep_d26_s9[] = { M(sMsg_d26_s9_0), NULL };
static const EntityMsg* const sStep_d26_s10[] = { M(sMsg_d26_s10_0), M(sMsg_d26_s10_1), NULL };
static const EntityMsg* const sStep_d26_s11[] = { M(sMsg_d26_s11_0), M(sMsg_d26_s11_1), NULL };
static const EntityMsg* const sStep_d26_s12[] = { M(sMsg_d26_s12_0), NULL };
static const EntityMsg* const sStep_d26_s13[] = { M(sMsg_d26_s13_0), NULL };
static const EntityMsg* const sStep_d26_s14[] = { M(sMsg_d26_s14_0), M(sMsg_d26_s14_1), M(sMsg_d26_s14_2), NULL };
static const EntityMsg* const sStep_d26_s15[] = { M(sMsg_d26_s15_0), NULL };
static const EntityMsg* const sStep_d26_s16[] = { M(sMsg_d26_s16_0), NULL };
static const EntityMsg* const sStep_d26_s17[] = { M(sMsg_d26_s17_0), M(sMsg_d26_s17_1), NULL };
static const EntityMsg* const sStep_d26_s18[] = { M(sMsg_d26_s18_0), NULL };
static const EntityMsg* const sStep_d26_s19[] = { M(sMsg_d26_s19_0), NULL };
static const EntityMsg* const sStep_d26_s20[] = { M(sMsg_d26_s20_0), M(sMsg_d26_s20_1), M(sMsg_d26_s20_2), M(sMsg_d26_s20_3), M(sMsg_d26_s20_4), NULL };
static const EntityMsg* const sStep_d26_s21[] = { M(sMsg_d26_s21_0), M(sMsg_d26_s21_1), NULL };
static const EntityMsg* const sStep_d27_s0[] = { M(sMsg_d27_s0_0), M(sMsg_d27_s0_1), NULL };
static const EntityMsg* const sStep_d27_s1[] = { M(sMsg_d27_s1_0), NULL };
static const EntityMsg* const sStep_d27_s2[] = { M(sMsg_d27_s2_0), NULL };
static const EntityMsg* const sStep_d27_s3[] = { M(sMsg_d27_s3_0), M(sMsg_d27_s3_1), M(sMsg_d27_s3_2), NULL };
static const EntityMsg* const sStep_d27_s4[] = { M(sMsg_d27_s4_0), M(sMsg_d27_s4_1), M(sMsg_d27_s4_2), NULL };
static const EntityMsg* const sStep_d27_s5[] = { M(sMsg_d27_s5_0), M(sMsg_d27_s5_1), NULL };
static const EntityMsg* const sStep_d27_s6[] = { M(sMsg_d27_s6_0), NULL };
static const EntityMsg* const sStep_d27_s7[] = { M(sMsg_d27_s7_0), NULL };
static const EntityMsg* const sStep_d27_s8[] = { M(sMsg_d27_s8_0), M(sMsg_d27_s8_1), M(sMsg_d27_s8_2), M(sMsg_d27_s8_3), NULL };
static const EntityMsg* const sStep_d27_s9[] = { M(sMsg_d27_s9_0), M(sMsg_d27_s9_1), NULL };
static const EntityMsg* const sStep_d27_s10[] = { M(sMsg_d27_s10_0), M(sMsg_d27_s10_1), NULL };
static const EntityMsg* const sStep_d27_s11[] = { M(sMsg_d27_s11_0), NULL };
static const EntityMsg* const sStep_d27_s12[] = { M(sMsg_d27_s12_0), NULL };
static const EntityMsg* const sStep_d27_s13[] = { M(sMsg_d27_s13_0), NULL };
static const EntityMsg* const sStep_d27_s14[] = { M(sMsg_d27_s14_0), M(sMsg_d27_s14_1), NULL };
static const EntityMsg* const sStep_d27_s15[] = { M(sMsg_d27_s15_0), NULL };
static const EntityMsg* const sStep_d27_s16[] = { M(sMsg_d27_s16_0), NULL };
static const EntityMsg* const sStep_d27_s17[] = { M(sMsg_d27_s17_0), NULL };
static const EntityMsg* const sStep_d27_s18[] = { M(sMsg_d27_s18_0), NULL };
static const EntityMsg* const sStep_d27_s19[] = { M(sMsg_d27_s19_0), NULL };
static const EntityMsg* const sStep_d27_s20[] = { M(sMsg_d27_s20_0), NULL };
static const EntityMsg* const sStep_d27_s21[] = { M(sMsg_d27_s21_0), M(sMsg_d27_s21_1), NULL };
static const EntityMsg* const sStep_d27_s22[] = { M(sMsg_d27_s22_0), NULL };
static const EntityMsg* const sStep_d27_s23[] = { M(sMsg_d27_s23_0), M(sMsg_d27_s23_1), M(sMsg_d27_s23_2), NULL };
static const EntityMsg* const sStep_d27_s24[] = { M(sMsg_d27_s24_0), M(sMsg_d27_s24_1), NULL };
static const EntityMsg* const sStep_d27_s25[] = { M(sMsg_d27_s25_0), M(sMsg_d27_s25_1), M(sMsg_d27_s25_2), NULL };
static const EntityMsg* const sStep_d27_s26[] = { M(sMsg_d27_s26_0), NULL };
static const EntityMsg* const sStep_d27_s27[] = { M(sMsg_d27_s27_0), NULL };
static const EntityMsg* const sStep_d27_s28[] = { M(sMsg_d27_s28_0), NULL };
static const EntityMsg* const sStep_d27_s29[] = { M(sMsg_d27_s29_0), M(sMsg_d27_s29_1), NULL };
static const EntityMsg* const sStep_d27_s30[] = { M(sMsg_d27_s30_0), M(sMsg_d27_s30_1), NULL };
static const EntityMsg* const sStep_d28_s0[] = { M(sMsg_d28_s0_0), NULL };
static const EntityMsg* const sStep_d28_s1[] = { M(sMsg_d28_s1_0), M(sMsg_d28_s1_1), M(sMsg_d28_s1_2), NULL };
static const EntityMsg* const sStep_d28_s2[] = { M(sMsg_d28_s2_0), M(sMsg_d28_s2_1), NULL };
static const EntityMsg* const sStep_d28_s3[] = { M(sMsg_d28_s3_0), M(sMsg_d28_s3_1), NULL };
static const EntityMsg* const sStep_d28_s4[] = { M(sMsg_d28_s4_0), NULL };
static const EntityMsg* const sStep_d28_s5[] = { M(sMsg_d28_s5_0), M(sMsg_d28_s5_1), M(sMsg_d28_s5_2), M(sMsg_d28_s5_3), NULL };
static const EntityMsg* const sStep_d28_s6[] = { M(sMsg_d28_s6_0), M(sMsg_d28_s6_1), NULL };
static const EntityMsg* const sStep_d28_s7[] = { M(sMsg_d28_s7_0), M(sMsg_d28_s7_1), M(sMsg_d28_s7_2), NULL };
static const EntityMsg* const sStep_d28_s8[] = { M(sMsg_d28_s8_0), NULL };
static const EntityMsg* const sStep_d28_s9[] = { M(sMsg_d28_s9_0), M(sMsg_d28_s9_1), NULL };
static const EntityMsg* const sStep_d28_s10[] = { M(sMsg_d28_s10_0), M(sMsg_d28_s10_1), NULL };
static const EntityMsg* const sStep_d29_s0[] = { M(sMsg_d29_s0_0), M(sMsg_d29_s0_1), M(sMsg_d29_s0_2), M(sMsg_d29_s0_3), NULL };
static const EntityMsg* const sStep_d29_s1[] = { M(sMsg_d29_s1_0), NULL };
static const EntityMsg* const sStep_d29_s2[] = { M(sMsg_d29_s2_0), M(sMsg_d29_s2_1), NULL };
static const EntityMsg* const sStep_d29_s3[] = { M(sMsg_d29_s3_0), NULL };
static const EntityMsg* const sStep_d29_s4[] = { M(sMsg_d29_s4_0), NULL };
static const EntityMsg* const sStep_d29_s5[] = { M(sMsg_d29_s5_0), M(sMsg_d29_s5_1), NULL };
static const EntityMsg* const sStep_d29_s6[] = { M(sMsg_d29_s6_0), NULL };
static const EntityMsg* const sStep_d29_s7[] = { M(sMsg_d29_s7_0), NULL };
static const EntityMsg* const sStep_d29_s8[] = { M(sMsg_d29_s8_0), M(sMsg_d29_s8_1), M(sMsg_d29_s8_2), NULL };
static const EntityMsg* const sStep_d29_s9[] = { M(sMsg_d29_s9_0), M(sMsg_d29_s9_1), M(sMsg_d29_s9_2), NULL };
static const EntityMsg* const sStep_d29_s10[] = { M(sMsg_d29_s10_0), M(sMsg_d29_s10_1), NULL };
static const EntityMsg* const sStep_d29_s11[] = { M(sMsg_d29_s11_0), NULL };
static const EntityMsg* const sStep_d29_s12[] = { M(sMsg_d29_s12_0), NULL };
static const EntityMsg* const sStep_d29_s13[] = { M(sMsg_d29_s13_0), NULL };
static const EntityMsg* const sStep_d29_s14[] = { M(sMsg_d29_s14_0), NULL };
static const EntityMsg* const sStep_d29_s15[] = { M(sMsg_d29_s15_0), M(sMsg_d29_s15_1), M(sMsg_d29_s15_2), NULL };
static const EntityMsg* const sStep_d29_s16[] = { M(sMsg_d29_s16_0), NULL };
static const EntityMsg* const sStep_d29_s17[] = { M(sMsg_d29_s17_0), NULL };
static const EntityMsg* const sStep_d29_s18[] = { M(sMsg_d29_s18_0), M(sMsg_d29_s18_1), NULL };
static const EntityMsg* const sStep_d29_s19[] = { M(sMsg_d29_s19_0), M(sMsg_d29_s19_1), M(sMsg_d29_s19_2), NULL };
static const EntityMsg* const sStep_d29_s20[] = { M(sMsg_d29_s20_0), NULL };
static const EntityMsg* const sStep_d29_s21[] = { M(sMsg_d29_s21_0), M(sMsg_d29_s21_1), NULL };
static const EntityMsg* const sStep_d29_s22[] = { M(sMsg_d29_s22_0), M(sMsg_d29_s22_1), M(sMsg_d29_s22_2), M(sMsg_d29_s22_3), NULL };
static const EntityMsg* const sStep_d29_s23[] = { M(sMsg_d29_s23_0), NULL };
static const EntityMsg* const sStep_d29_s24[] = { M(sMsg_d29_s24_0), M(sMsg_d29_s24_1), M(sMsg_d29_s24_2), NULL };
static const EntityMsg* const sStep_d29_s25[] = { M(sMsg_d29_s25_0), M(sMsg_d29_s25_1), M(sMsg_d29_s25_2), NULL };
static const EntityMsg* const sStep_d29_s26[] = { M(sMsg_d29_s26_0), M(sMsg_d29_s26_1), M(sMsg_d29_s26_2), M(sMsg_d29_s26_3), M(sMsg_d29_s26_4), NULL };
static const EntityMsg* const sStep_d29_s27[] = { M(sMsg_d29_s27_0), M(sMsg_d29_s27_1), M(sMsg_d29_s27_2), M(sMsg_d29_s27_3), NULL };
static const EntityMsg* const sStep_d29_s28[] = { M(sMsg_d29_s28_0), M(sMsg_d29_s28_1), M(sMsg_d29_s28_2), M(sMsg_d29_s28_3), NULL };
static const EntityMsg* const sStep_d29_s29[] = { M(sMsg_d29_s29_0), NULL };
static const EntityMsg* const sStep_d29_s30[] = { M(sMsg_d29_s30_0), M(sMsg_d29_s30_1), M(sMsg_d29_s30_2), NULL };
static const EntityMsg* const sStep_d29_s31[] = { M(sMsg_d29_s31_0), M(sMsg_d29_s31_1), M(sMsg_d29_s31_2), M(sMsg_d29_s31_3), NULL };
static const EntityMsg* const sStep_d29_s32[] = { M(sMsg_d29_s32_0), NULL };
static const EntityMsg* const sStep_d29_s33[] = { M(sMsg_d29_s33_0), NULL };
static const EntityMsg* const sStep_d29_s34[] = { M(sMsg_d29_s34_0), M(sMsg_d29_s34_1), M(sMsg_d29_s34_2), NULL };
static const EntityMsg* const sStep_d29_s35[] = { M(sMsg_d29_s35_0), M(sMsg_d29_s35_1), M(sMsg_d29_s35_2), M(sMsg_d29_s35_3), NULL };
static const EntityMsg* const sStep_d30_s0[] = { M(sMsg_d30_s0_0), M(sMsg_d30_s0_1), M(sMsg_d30_s0_2), NULL };
static const EntityMsg* const sStep_d30_s1[] = { M(sMsg_d30_s1_0), M(sMsg_d30_s1_1), NULL };
static const EntityMsg* const sStep_d30_s2[] = { M(sMsg_d30_s2_0), NULL };
static const EntityMsg* const sStep_d30_s3[] = { M(sMsg_d30_s3_0), NULL };
static const EntityMsg* const sStep_d30_s4[] = { M(sMsg_d30_s4_0), M(sMsg_d30_s4_1), M(sMsg_d30_s4_2), M(sMsg_d30_s4_3), M(sMsg_d30_s4_4), M(sMsg_d30_s4_5), NULL };
static const EntityMsg* const sStep_d31_s0[] = { M(sMsg_d31_s0_0), M(sMsg_d31_s0_1), NULL };
static const EntityMsg* const sStep_d31_s1[] = { M(sMsg_d31_s1_0), NULL };
static const EntityMsg* const sStep_d31_s2[] = { M(sMsg_d31_s2_0), NULL };
static const EntityMsg* const sStep_d31_s3[] = { M(sMsg_d31_s3_0), M(sMsg_d31_s3_1), NULL };
static const EntityMsg* const sStep_d31_s4[] = { M(sMsg_d31_s4_0), NULL };
static const EntityMsg* const sStep_d31_s5[] = { M(sMsg_d31_s5_0), NULL };
static const EntityMsg* const sStep_d31_s6[] = { M(sMsg_d31_s6_0), M(sMsg_d31_s6_1), M(sMsg_d31_s6_2), NULL };
static const EntityMsg* const sStep_d31_s7[] = { M(sMsg_d31_s7_0), M(sMsg_d31_s7_1), NULL };
static const EntityMsg* const sStep_d31_s8[] = { M(sMsg_d31_s8_0), M(sMsg_d31_s8_1), M(sMsg_d31_s8_2), NULL };
static const EntityMsg* const sStep_d31_s9[] = { M(sMsg_d31_s9_0), M(sMsg_d31_s9_1), NULL };
static const EntityMsg* const sStep_d32_s0[] = { M(sMsg_d32_s0_0), NULL };
static const EntityMsg* const sStep_d32_s1[] = { M(sMsg_d32_s1_0), NULL };
static const EntityMsg* const sStep_d32_s2[] = { M(sMsg_d32_s2_0), NULL };
static const EntityMsg* const sStep_d32_s3[] = { M(sMsg_d32_s3_0), NULL };
static const EntityMsg* const sStep_d32_s4[] = { M(sMsg_d32_s4_0), NULL };
static const EntityMsg* const sStep_d32_s5[] = { M(sMsg_d32_s5_0), NULL };
static const EntityMsg* const sStep_d32_s6[] = { M(sMsg_d32_s6_0), NULL };
static const EntityMsg* const sStep_d33_s0[] = { M(sMsg_d33_s0_0), NULL };
static const EntityMsg* const sStep_d33_s1[] = { M(sMsg_d33_s1_0), M(sMsg_d33_s1_1), NULL };
static const EntityMsg* const sStep_d33_s2[] = { M(sMsg_d33_s2_0), NULL };
static const EntityMsg* const sStep_d33_s3[] = { M(sMsg_d33_s3_0), NULL };
static const EntityMsg* const sStep_d33_s4[] = { M(sMsg_d33_s4_0), NULL };
static const EntityMsg* const sStep_d33_s5[] = { M(sMsg_d33_s5_0), NULL };
static const EntityMsg* const sStep_d33_s6[] = { M(sMsg_d33_s6_0), NULL };
static const EntityMsg* const sStep_d33_s7[] = { M(sMsg_d33_s7_0), NULL };
static const EntityMsg* const sStep_d33_s8[] = { M(sMsg_d33_s8_0), NULL };
static const EntityMsg* const sStep_d33_s9[] = { M(sMsg_d33_s9_0), NULL };
static const EntityMsg* const sStep_d33_s10[] = { M(sMsg_d33_s10_0), NULL };
static const EntityMsg* const sStep_d34_s0[] = { M(sMsg_d34_s0_0), NULL };
static const EntityMsg* const sStep_d34_s1[] = { M(sMsg_d34_s1_0), NULL };
static const EntityMsg* const sStep_d34_s2[] = { M(sMsg_d34_s2_0), NULL };
static const EntityMsg* const sStep_d34_s3[] = { M(sMsg_d34_s3_0), M(sMsg_d34_s3_1), M(sMsg_d34_s3_2), NULL };
static const EntityMsg* const sStep_d34_s4[] = { M(sMsg_d34_s4_0), M(sMsg_d34_s4_1), NULL };
static const EntityMsg* const sStep_d34_s5[] = { M(sMsg_d34_s5_0), NULL };
static const EntityMsg* const sStep_d34_s6[] = { M(sMsg_d34_s6_0), NULL };
static const EntityMsg* const sStep_d34_s7[] = { M(sMsg_d34_s7_0), NULL };
static const EntityMsg* const sStep_d34_s8[] = { M(sMsg_d34_s8_0), M(sMsg_d34_s8_1), NULL };
static const EntityMsg* const sStep_d34_s9[] = { M(sMsg_d34_s9_0), NULL };
static const EntityMsg* const sStep_d34_s10[] = { M(sMsg_d34_s10_0), NULL };
static const EntityMsg* const sStep_d34_s11[] = { M(sMsg_d34_s11_0), NULL };
static const EntityMsg* const sStep_d34_s12[] = { M(sMsg_d34_s12_0), M(sMsg_d34_s12_1), NULL };
static const EntityMsg* const sStep_d34_s13[] = { M(sMsg_d34_s13_0), NULL };
static const EntityMsg* const sStep_d34_s14[] = { M(sMsg_d34_s14_0), NULL };
static const EntityMsg* const sStep_d34_s15[] = { M(sMsg_d34_s15_0), NULL };
static const EntityMsg* const sStep_d34_s16[] = { M(sMsg_d34_s16_0), NULL };
static const EntityMsg* const sStep_d34_s17[] = { M(sMsg_d34_s17_0), NULL };
static const EntityMsg* const sStep_d34_s18[] = { M(sMsg_d34_s18_0), NULL };
static const EntityMsg* const sStep_d34_s19[] = { M(sMsg_d34_s19_0), NULL };
static const EntityMsg* const sStep_d35_s0[] = { M(sMsg_d35_s0_0), NULL };
static const EntityMsg* const sStep_d35_s1[] = { M(sMsg_d35_s1_0), NULL };
static const EntityMsg* const sStep_d35_s2[] = { M(sMsg_d35_s2_0), NULL };
static const EntityMsg* const sStep_d35_s3[] = { M(sMsg_d35_s3_0), M(sMsg_d35_s3_1), NULL };
static const EntityMsg* const sStep_d35_s4[] = { M(sMsg_d35_s4_0), M(sMsg_d35_s4_1), M(sMsg_d35_s4_2), NULL };
static const EntityMsg* const sStep_d35_s5[] = { M(sMsg_d35_s5_0), M(sMsg_d35_s5_1), NULL };
static const EntityMsg* const sStep_d35_s6[] = { M(sMsg_d35_s6_0), NULL };
static const EntityMsg* const sStep_d35_s7[] = { M(sMsg_d35_s7_0), NULL };
static const EntityMsg* const sStep_d35_s8[] = { M(sMsg_d35_s8_0), NULL };
static const EntityMsg* const sStep_d35_s9[] = { M(sMsg_d35_s9_0), M(sMsg_d35_s9_1), NULL };
static const EntityMsg* const sStep_d35_s10[] = { M(sMsg_d35_s10_0), NULL };
static const EntityMsg* const sStep_d35_s11[] = { M(sMsg_d35_s11_0), NULL };
static const EntityMsg* const sStep_d35_s12[] = { M(sMsg_d35_s12_0), NULL };
static const EntityMsg* const sStep_d35_s13[] = { M(sMsg_d35_s13_0), M(sMsg_d35_s13_1), NULL };
static const EntityMsg* const sStep_d35_s14[] = { M(sMsg_d35_s14_0), NULL };
static const EntityMsg* const sStep_d35_s15[] = { M(sMsg_d35_s15_0), NULL };
static const EntityMsg* const sStep_d35_s16[] = { M(sMsg_d35_s16_0), NULL };
static const EntityMsg* const sStep_d35_s17[] = { M(sMsg_d35_s17_0), NULL };
static const EntityMsg* const sStep_d35_s18[] = { M(sMsg_d35_s18_0), NULL };
static const EntityMsg* const sStep_d35_s19[] = { M(sMsg_d35_s19_0), NULL };
static const EntityMsg* const sStep_d35_s20[] = { M(sMsg_d35_s20_0), M(sMsg_d35_s20_1), NULL };
static const EntityMsg* const sStep_d36_s0[] = { M(sMsg_d36_s0_0), M(sMsg_d36_s0_1), M(sMsg_d36_s0_2), M(sMsg_d36_s0_3), M(sMsg_d36_s0_4), NULL };
static const EntityMsg* const sStep_d36_s1[] = { M(sMsg_d36_s1_0), M(sMsg_d36_s1_1), NULL };
static const EntityMsg* const sStep_d36_s2[] = { M(sMsg_d36_s2_0), NULL };
static const EntityMsg* const sStep_d36_s3[] = { M(sMsg_d36_s3_0), NULL };
static const EntityMsg* const sStep_d36_s4[] = { M(sMsg_d36_s4_0), M(sMsg_d36_s4_1), NULL };
static const EntityMsg* const sStep_d36_s5[] = { M(sMsg_d36_s5_0), NULL };
static const EntityMsg* const sStep_d36_s6[] = { M(sMsg_d36_s6_0), NULL };
static const EntityMsg* const sStep_d36_s7[] = { M(sMsg_d36_s7_0), NULL };
static const EntityMsg* const sStep_d36_s8[] = { M(sMsg_d36_s8_0), NULL };
static const EntityMsg* const sStep_d36_s9[] = { M(sMsg_d36_s9_0), NULL };
static const EntityMsg* const sStep_d36_s10[] = { M(sMsg_d36_s10_0), M(sMsg_d36_s10_1), NULL };
static const EntityMsg* const sStep_d36_s11[] = { M(sMsg_d36_s11_0), NULL };
static const EntityMsg* const sStep_d36_s12[] = { M(sMsg_d36_s12_0), NULL };
static const EntityMsg* const sStep_d36_s13[] = { M(sMsg_d36_s13_0), NULL };
static const EntityMsg* const sStep_d36_s14[] = { M(sMsg_d36_s14_0), NULL };
static const EntityMsg* const sStep_d36_s15[] = { M(sMsg_d36_s15_0), NULL };
static const EntityMsg* const sStep_d36_s16[] = { M(sMsg_d36_s16_0), M(sMsg_d36_s16_1), M(sMsg_d36_s16_2), NULL };
static const EntityMsg* const sStep_d36_s17[] = { M(sMsg_d36_s17_0), NULL };
static const EntityMsg* const sStep_d36_s18[] = { M(sMsg_d36_s18_0), NULL };
static const EntityMsg* const sStep_d36_s19[] = { M(sMsg_d36_s19_0), M(sMsg_d36_s19_1), NULL };
static const EntityMsg* const sStep_d36_s20[] = { M(sMsg_d36_s20_0), M(sMsg_d36_s20_1), NULL };
static const EntityMsg* const sStep_d36_s21[] = { M(sMsg_d36_s21_0), NULL };
static const EntityMsg* const sStep_d36_s22[] = { M(sMsg_d36_s22_0), NULL };
static const EntityMsg* const sStep_d36_s23[] = { M(sMsg_d36_s23_0), NULL };
static const EntityMsg* const sStep_d37_s0[] = { M(sMsg_d37_s0_0), M(sMsg_d37_s0_1), NULL };
static const EntityMsg* const sStep_d37_s1[] = { M(sMsg_d37_s1_0), NULL };
static const EntityMsg* const sStep_d37_s2[] = { M(sMsg_d37_s2_0), NULL };
static const EntityMsg* const sStep_d37_s3[] = { M(sMsg_d37_s3_0), NULL };
static const EntityMsg* const sStep_d37_s4[] = { M(sMsg_d37_s4_0), NULL };
static const EntityMsg* const sStep_d37_s5[] = { M(sMsg_d37_s5_0), NULL };
static const EntityMsg* const sStep_d37_s6[] = { M(sMsg_d37_s6_0), M(sMsg_d37_s6_1), NULL };
static const EntityMsg* const sStep_d38_s0[] = { M(sMsg_d38_s0_0), M(sMsg_d38_s0_1), NULL };
static const EntityMsg* const sStep_d38_s1[] = { M(sMsg_d38_s1_0), NULL };
static const EntityMsg* const sStep_d38_s2[] = { M(sMsg_d38_s2_0), NULL };
static const EntityMsg* const sStep_d38_s3[] = { M(sMsg_d38_s3_0), M(sMsg_d38_s3_1), NULL };
static const EntityMsg* const sStep_d38_s4[] = { M(sMsg_d38_s4_0), NULL };
static const EntityMsg* const sStep_d38_s5[] = { M(sMsg_d38_s5_0), NULL };
static const EntityMsg* const sStep_d38_s6[] = { M(sMsg_d38_s6_0), NULL };
static const EntityMsg* const sStep_d38_s7[] = { M(sMsg_d38_s7_0), M(sMsg_d38_s7_1), NULL };
static const EntityMsg* const sStep_d38_s8[] = { M(sMsg_d38_s8_0), NULL };
static const EntityMsg* const sStep_d39_s0[] = { M(sMsg_d39_s0_0), M(sMsg_d39_s0_1), NULL };
static const EntityMsg* const sStep_d39_s1[] = { M(sMsg_d39_s1_0), M(sMsg_d39_s1_1), NULL };
static const EntityMsg* const sStep_d39_s2[] = { M(sMsg_d39_s2_0), M(sMsg_d39_s2_1), NULL };
static const EntityMsg* const sStep_d39_s3[] = { M(sMsg_d39_s3_0), M(sMsg_d39_s3_1), NULL };
static const EntityMsg* const sStep_d39_s4[] = { M(sMsg_d39_s4_0), M(sMsg_d39_s4_1), NULL };
static const EntityMsg* const sStep_d39_s5[] = { M(sMsg_d39_s5_0), M(sMsg_d39_s5_1), NULL };
static const EntityMsg* const sStep_d39_s6[] = { M(sMsg_d39_s6_0), NULL };
static const EntityMsg* const sStep_d39_s7[] = { M(sMsg_d39_s7_0), NULL };
static const EntityMsg* const sStep_d39_s8[] = { M(sMsg_d39_s8_0), M(sMsg_d39_s8_1), M(sMsg_d39_s8_2), NULL };
static const EntityMsg* const sStep_d39_s9[] = { M(sMsg_d39_s9_0), NULL };
static const EntityMsg* const sStep_d39_s10[] = { M(sMsg_d39_s10_0), NULL };
static const EntityMsg* const sStep_d39_s11[] = { M(sMsg_d39_s11_0), M(sMsg_d39_s11_1), NULL };
static const EntityMsg* const sStep_d40_s0[] = { M(sMsg_d40_s0_0), M(sMsg_d40_s0_1), M(sMsg_d40_s0_2), NULL };
static const EntityMsg* const sStep_d40_s1[] = { M(sMsg_d40_s1_0), M(sMsg_d40_s1_1), NULL };
static const EntityMsg* const sStep_d40_s2[] = { M(sMsg_d40_s2_0), M(sMsg_d40_s2_1), M(sMsg_d40_s2_2), NULL };
static const EntityMsg* const sStep_d40_s3[] = { M(sMsg_d40_s3_0), M(sMsg_d40_s3_1), NULL };
static const EntityMsg* const sStep_d40_s4[] = { M(sMsg_d40_s4_0), M(sMsg_d40_s4_1), M(sMsg_d40_s4_2), M(sMsg_d40_s4_3), NULL };
static const EntityMsg* const sStep_d40_s5[] = { M(sMsg_d40_s5_0), M(sMsg_d40_s5_1), NULL };
static const EntityMsg* const sStep_d41_s0[] = { M(sMsg_d41_s0_0), M(sMsg_d41_s0_1), NULL };
static const EntityMsg* const sStep_d41_s1[] = { M(sMsg_d41_s1_0), M(sMsg_d41_s1_1), NULL };
static const EntityMsg* const sStep_d41_s2[] = { M(sMsg_d41_s2_0), NULL };
static const EntityMsg* const sStep_d41_s3[] = { M(sMsg_d41_s3_0), NULL };
static const EntityMsg* const sStep_d41_s4[] = { M(sMsg_d41_s4_0), M(sMsg_d41_s4_1), NULL };
static const EntityMsg* const sStep_d41_s5[] = { M(sMsg_d41_s5_0), M(sMsg_d41_s5_1), M(sMsg_d41_s5_2), NULL };
static const EntityMsg* const sStep_d41_s6[] = { M(sMsg_d41_s6_0), M(sMsg_d41_s6_1), M(sMsg_d41_s6_2), M(sMsg_d41_s6_3), NULL };
static const EntityMsg* const sStep_d41_s7[] = { M(sMsg_d41_s7_0), NULL };
static const EntityMsg* const sStep_d41_s8[] = { M(sMsg_d41_s8_0), NULL };
static const EntityMsg* const sStep_d41_s9[] = { M(sMsg_d41_s9_0), NULL };
static const EntityMsg* const sStep_d41_s10[] = { M(sMsg_d41_s10_0), NULL };
static const EntityMsg* const sStep_d41_s11[] = { M(sMsg_d41_s11_0), M(sMsg_d41_s11_1), M(sMsg_d41_s11_2), M(sMsg_d41_s11_3), M(sMsg_d41_s11_4), NULL };
static const EntityMsg* const sStep_d41_s12[] = { M(sMsg_d41_s12_0), NULL };
static const EntityMsg* const sStep_d41_s13[] = { M(sMsg_d41_s13_0), NULL };
static const EntityMsg* const sStep_d41_s14[] = { M(sMsg_d41_s14_0), NULL };
static const EntityMsg* const sStep_d41_s15[] = { M(sMsg_d41_s15_0), M(sMsg_d41_s15_1), NULL };
static const EntityMsg* const sStep_d41_s16[] = { M(sMsg_d41_s16_0), NULL };
static const EntityMsg* const sStep_d41_s17[] = { M(sMsg_d41_s17_0), M(sMsg_d41_s17_1), NULL };
static const EntityMsg* const sStep_d41_s18[] = { M(sMsg_d41_s18_0), NULL };
static const EntityMsg* const sStep_d41_s19[] = { M(sMsg_d41_s19_0), NULL };
static const EntityMsg* const sStep_d41_s20[] = { M(sMsg_d41_s20_0), M(sMsg_d41_s20_1), NULL };
static const EntityMsg* const sStep_d42_s0[] = { M(sMsg_d42_s0_0), M(sMsg_d42_s0_1), M(sMsg_d42_s0_2), M(sMsg_d42_s0_3), M(sMsg_d42_s0_4), M(sMsg_d42_s0_5), M(sMsg_d42_s0_6), M(sMsg_d42_s0_7), NULL };
static const EntityMsg* const sStep_d42_s1[] = { M(sMsg_d42_s1_0), M(sMsg_d42_s1_1), M(sMsg_d42_s1_2), M(sMsg_d42_s1_3), M(sMsg_d42_s1_4), NULL };
static const EntityMsg* const sStep_d42_s2[] = { M(sMsg_d42_s2_0), M(sMsg_d42_s2_1), NULL };
static const EntityMsg* const sStep_d42_s3[] = { M(sMsg_d42_s3_0), M(sMsg_d42_s3_1), NULL };
static const EntityMsg* const sStep_d42_s4[] = { M(sMsg_d42_s4_0), NULL };
static const EntityMsg* const sStep_d42_s5[] = { M(sMsg_d42_s5_0), NULL };
static const EntityMsg* const sStep_d42_s6[] = { M(sMsg_d42_s6_0), M(sMsg_d42_s6_1), M(sMsg_d42_s6_2), NULL };
static const EntityMsg* const sStep_d42_s7[] = { M(sMsg_d42_s7_0), M(sMsg_d42_s7_1), M(sMsg_d42_s7_2), NULL };
static const EntityMsg* const sStep_d42_s8[] = { M(sMsg_d42_s8_0), M(sMsg_d42_s8_1), NULL };
static const EntityMsg* const sStep_d42_s9[] = { M(sMsg_d42_s9_0), NULL };
static const EntityMsg* const sStep_d42_s10[] = { M(sMsg_d42_s10_0), M(sMsg_d42_s10_1), M(sMsg_d42_s10_2), NULL };
static const EntityMsg* const sStep_d42_s11[] = { M(sMsg_d42_s11_0), NULL };
static const EntityMsg* const sStep_d42_s12[] = { M(sMsg_d42_s12_0), M(sMsg_d42_s12_1), NULL };
static const EntityMsg* const sStep_d42_s13[] = { M(sMsg_d42_s13_0), NULL };
static const EntityMsg* const sStep_d42_s14[] = { M(sMsg_d42_s14_0), M(sMsg_d42_s14_1), M(sMsg_d42_s14_2), NULL };
static const EntityMsg* const sStep_d42_s15[] = { M(sMsg_d42_s15_0), M(sMsg_d42_s15_1), NULL };
static const EntityMsg* const sStep_d42_s16[] = { M(sMsg_d42_s16_0), M(sMsg_d42_s16_1), NULL };
static const EntityMsg* const sStep_d42_s17[] = { M(sMsg_d42_s17_0), NULL };
static const EntityMsg* const sStep_d42_s18[] = { M(sMsg_d42_s18_0), NULL };
static const EntityMsg* const sStep_d42_s19[] = { M(sMsg_d42_s19_0), M(sMsg_d42_s19_1), NULL };
static const EntityMsg* const sStep_d42_s20[] = { M(sMsg_d42_s20_0), M(sMsg_d42_s20_1), M(sMsg_d42_s20_2), NULL };
static const EntityMsg* const sStep_d43_s0[] = { M(sMsg_d43_s0_0), M(sMsg_d43_s0_1), NULL };
static const EntityMsg* const sStep_d43_s1[] = { M(sMsg_d43_s1_0), M(sMsg_d43_s1_1), NULL };
static const EntityMsg* const sStep_d43_s2[] = { M(sMsg_d43_s2_0), NULL };
static const EntityMsg* const sStep_d43_s3[] = { M(sMsg_d43_s3_0), NULL };
static const EntityMsg* const sStep_d43_s4[] = { M(sMsg_d43_s4_0), M(sMsg_d43_s4_1), M(sMsg_d43_s4_2), NULL };
static const EntityMsg* const sStep_d43_s5[] = { M(sMsg_d43_s5_0), NULL };
static const EntityMsg* const sStep_d43_s6[] = { M(sMsg_d43_s6_0), NULL };
static const EntityMsg* const sStep_d43_s7[] = { M(sMsg_d43_s7_0), M(sMsg_d43_s7_1), NULL };
static const EntityMsg* const sStep_d43_s8[] = { M(sMsg_d43_s8_0), M(sMsg_d43_s8_1), M(sMsg_d43_s8_2), NULL };
static const EntityMsg* const sStep_d44_s0[] = { M(sMsg_d44_s0_0), M(sMsg_d44_s0_1), M(sMsg_d44_s0_2), NULL };
static const EntityMsg* const sStep_d44_s1[] = { M(sMsg_d44_s1_0), M(sMsg_d44_s1_1), NULL };
static const EntityMsg* const sStep_d44_s2[] = { M(sMsg_d44_s2_0), M(sMsg_d44_s2_1), M(sMsg_d44_s2_2), M(sMsg_d44_s2_3), NULL };
static const EntityMsg* const sStep_d44_s3[] = { M(sMsg_d44_s3_0), M(sMsg_d44_s3_1), M(sMsg_d44_s3_2), NULL };
static const EntityMsg* const sStep_d44_s4[] = { M(sMsg_d44_s4_0), M(sMsg_d44_s4_1), M(sMsg_d44_s4_2), NULL };
static const EntityMsg* const sStep_d44_s5[] = { M(sMsg_d44_s5_0), M(sMsg_d44_s5_1), M(sMsg_d44_s5_2), NULL };
static const EntityMsg* const sStep_d44_s6[] = { M(sMsg_d44_s6_0), M(sMsg_d44_s6_1), M(sMsg_d44_s6_2), M(sMsg_d44_s6_3), NULL };
static const EntityMsg* const sStep_d44_s7[] = { M(sMsg_d44_s7_0), M(sMsg_d44_s7_1), M(sMsg_d44_s7_2), M(sMsg_d44_s7_3), M(sMsg_d44_s7_4), NULL };
static const EntityMsg* const sStep_d44_s8[] = { M(sMsg_d44_s8_0), M(sMsg_d44_s8_1), M(sMsg_d44_s8_2), NULL };
static const EntityMsg* const sStep_d44_s9[] = { M(sMsg_d44_s9_0), NULL };
static const EntityMsg* const sStep_d44_s10[] = { M(sMsg_d44_s10_0), NULL };
static const EntityMsg* const sStep_d44_s11[] = { M(sMsg_d44_s11_0), M(sMsg_d44_s11_1), NULL };
static const EntityMsg* const sStep_d44_s12[] = { M(sMsg_d44_s12_0), M(sMsg_d44_s12_1), M(sMsg_d44_s12_2), NULL };
static const EntityMsg* const sStep_d44_s13[] = { M(sMsg_d44_s13_0), M(sMsg_d44_s13_1), NULL };
static const EntityMsg* const sStep_d44_s14[] = { M(sMsg_d44_s14_0), M(sMsg_d44_s14_1), NULL };
static const EntityMsg* const sStep_d44_s15[] = { M(sMsg_d44_s15_0), NULL };
static const EntityMsg* const sStep_d44_s16[] = { M(sMsg_d44_s16_0), NULL };
static const EntityMsg* const sStep_d44_s17[] = { M(sMsg_d44_s17_0), M(sMsg_d44_s17_1), M(sMsg_d44_s17_2), NULL };
static const EntityMsg* const sStep_d44_s18[] = { M(sMsg_d44_s18_0), M(sMsg_d44_s18_1), NULL };
static const EntityMsg* const sStep_d44_s19[] = { M(sMsg_d44_s19_0), M(sMsg_d44_s19_1), M(sMsg_d44_s19_2), NULL };
static const EntityMsg* const sStep_d44_s20[] = { M(sMsg_d44_s20_0), M(sMsg_d44_s20_1), NULL };
static const EntityMsg* const sStep_d44_s21[] = { M(sMsg_d44_s21_0), NULL };
static const EntityMsg* const sStep_d44_s22[] = { M(sMsg_d44_s22_0), NULL };
static const EntityMsg* const sStep_d44_s23[] = { M(sMsg_d44_s23_0), M(sMsg_d44_s23_1), M(sMsg_d44_s23_2), M(sMsg_d44_s23_3), NULL };
static const EntityMsg* const sStep_d44_s24[] = { M(sMsg_d44_s24_0), M(sMsg_d44_s24_1), NULL };
static const EntityMsg* const sStep_d44_s25[] = { M(sMsg_d44_s25_0), M(sMsg_d44_s25_1), M(sMsg_d44_s25_2), NULL };
static const EntityMsg* const sStep_d45_s0[] = { M(sMsg_d45_s0_0), M(sMsg_d45_s0_1), NULL };
static const EntityMsg* const sStep_d45_s1[] = { M(sMsg_d45_s1_0), NULL };
static const EntityMsg* const sStep_d45_s2[] = { M(sMsg_d45_s2_0), NULL };
static const EntityMsg* const sStep_d45_s3[] = { M(sMsg_d45_s3_0), NULL };
static const EntityMsg* const sStep_d45_s4[] = { M(sMsg_d45_s4_0), M(sMsg_d45_s4_1), NULL };
static const EntityMsg* const sStep_d45_s5[] = { M(sMsg_d45_s5_0), M(sMsg_d45_s5_1), M(sMsg_d45_s5_2), NULL };
static const EntityMsg* const sStep_d45_s6[] = { M(sMsg_d45_s6_0), M(sMsg_d45_s6_1), NULL };
static const EntityMsg* const sStep_d45_s7[] = { M(sMsg_d45_s7_0), M(sMsg_d45_s7_1), NULL };
static const EntityMsg* const sStep_d45_s8[] = { M(sMsg_d45_s8_0), M(sMsg_d45_s8_1), M(sMsg_d45_s8_2), M(sMsg_d45_s8_3), NULL };
static const EntityMsg* const sStep_d45_s9[] = { M(sMsg_d45_s9_0), NULL };
static const EntityMsg* const sStep_d45_s10[] = { M(sMsg_d45_s10_0), NULL };
static const EntityMsg* const sStep_d45_s11[] = { M(sMsg_d45_s11_0), M(sMsg_d45_s11_1), NULL };
static const EntityMsg* const sStep_d46_s0[] = { M(sMsg_d46_s0_0), NULL };
static const EntityMsg* const sStep_d46_s1[] = { M(sMsg_d46_s1_0), M(sMsg_d46_s1_1), NULL };
static const EntityMsg* const sStep_d46_s2[] = { M(sMsg_d46_s2_0), M(sMsg_d46_s2_1), NULL };
static const EntityMsg* const sStep_d46_s3[] = { M(sMsg_d46_s3_0), M(sMsg_d46_s3_1), M(sMsg_d46_s3_2), NULL };
static const EntityMsg* const sStep_d46_s4[] = { M(sMsg_d46_s4_0), NULL };
static const EntityMsg* const sStep_d46_s5[] = { M(sMsg_d46_s5_0), NULL };
static const EntityMsg* const sStep_d46_s6[] = { M(sMsg_d46_s6_0), M(sMsg_d46_s6_1), NULL };
static const EntityMsg* const sStep_d47_s0[] = { M(sMsg_d47_s0_0), NULL };
static const EntityMsg* const sStep_d47_s1[] = { M(sMsg_d47_s1_0), M(sMsg_d47_s1_1), NULL };
static const EntityMsg* const sStep_d47_s2[] = { M(sMsg_d47_s2_0), NULL };
static const EntityMsg* const sStep_d47_s3[] = { M(sMsg_d47_s3_0), NULL };
static const EntityMsg* const sStep_d47_s4[] = { M(sMsg_d47_s4_0), M(sMsg_d47_s4_1), M(sMsg_d47_s4_2), NULL };
static const EntityMsg* const sStep_d48_s0[] = { M(sMsg_d48_s0_0), NULL };
static const EntityMsg* const sStep_d48_s1[] = { M(sMsg_d48_s1_0), NULL };
static const EntityMsg* const sStep_d48_s2[] = { M(sMsg_d48_s2_0), NULL };
static const EntityMsg* const sStep_d48_s3[] = { M(sMsg_d48_s3_0), NULL };
static const EntityMsg* const sStep_d49_s0[] = { M(sMsg_d49_s0_0), M(sMsg_d49_s0_1), NULL };
static const EntityMsg* const sStep_d49_s1[] = { M(sMsg_d49_s1_0), NULL };
static const EntityMsg* const sStep_d49_s2[] = { M(sMsg_d49_s2_0), NULL };
static const EntityMsg* const sStep_d49_s3[] = { M(sMsg_d49_s3_0), M(sMsg_d49_s3_1), M(sMsg_d49_s3_2), NULL };
static const EntityMsg* const sStep_d50_s0[] = { M(sMsg_d50_s0_0), NULL };
static const EntityMsg* const sStep_d50_s1[] = { M(sMsg_d50_s1_0), NULL };
static const EntityMsg* const sStep_d50_s2[] = { M(sMsg_d50_s2_0), NULL };
static const EntityMsg* const sStep_d50_s3[] = { M(sMsg_d50_s3_0), M(sMsg_d50_s3_1), M(sMsg_d50_s3_2), NULL };
static const EntityMsg* const sStep_d51_s0[] = { M(sMsg_d51_s0_0), NULL };
static const EntityMsg* const sStep_d51_s1[] = { M(sMsg_d51_s1_0), NULL };
static const EntityMsg* const sStep_d51_s2[] = { M(sMsg_d51_s2_0), NULL };
static const EntityMsg* const sStep_d51_s3[] = { M(sMsg_d51_s3_0), M(sMsg_d51_s3_1), M(sMsg_d51_s3_2), NULL };
static const EntityMsg* const sStep_d52_s0[] = { M(sMsg_d52_s0_0), NULL };
static const EntityMsg* const sStep_d52_s1[] = { M(sMsg_d52_s1_0), NULL };
static const EntityMsg* const sStep_d52_s2[] = { M(sMsg_d52_s2_0), NULL };
static const EntityMsg* const sStep_d52_s3[] = { M(sMsg_d52_s3_0), M(sMsg_d52_s3_1), M(sMsg_d52_s3_2), NULL };
static const EntityMsg* const sStep_d53_s0[] = { M(sMsg_d53_s0_0), NULL };
static const EntityMsg* const sStep_d53_s1[] = { M(sMsg_d53_s1_0), NULL };
static const EntityMsg* const sStep_d53_s2[] = { M(sMsg_d53_s2_0), NULL };
static const EntityMsg* const sStep_d53_s3[] = { M(sMsg_d53_s3_0), M(sMsg_d53_s3_1), M(sMsg_d53_s3_2), NULL };
static const EntityMsg* const sStep_d53_s4[] = { M(sMsg_d53_s4_0), M(sMsg_d53_s4_1), NULL };
static const EntityMsg* const sStep_d53_s5[] = { M(sMsg_d53_s5_0), M(sMsg_d53_s5_1), M(sMsg_d53_s5_2), NULL };
static const EntityMsg* const sStep_d53_s6[] = { M(sMsg_d53_s6_0), M(sMsg_d53_s6_1), M(sMsg_d53_s6_2), M(sMsg_d53_s6_3), NULL };
static const EntityMsg* const sStep_d54_s0[] = { M(sMsg_d54_s0_0), M(sMsg_d54_s0_1), NULL };
static const EntityMsg* const sStep_d54_s1[] = { M(sMsg_d54_s1_0), NULL };
static const EntityMsg* const sStep_d54_s2[] = { M(sMsg_d54_s2_0), NULL };
static const EntityMsg* const sStep_d54_s3[] = { M(sMsg_d54_s3_0), NULL };
static const EntityMsg* const sStep_d55_s0[] = { M(sMsg_d55_s0_0), M(sMsg_d55_s0_1), M(sMsg_d55_s0_2), M(sMsg_d55_s0_3), NULL };
static const EntityMsg* const sStep_d55_s1[] = { M(sMsg_d55_s1_0), M(sMsg_d55_s1_1), M(sMsg_d55_s1_2), NULL };
static const EntityMsg* const sStep_d55_s2[] = { M(sMsg_d55_s2_0), M(sMsg_d55_s2_1), NULL };
static const EntityMsg* const sStep_d55_s3[] = { M(sMsg_d55_s3_0), M(sMsg_d55_s3_1), NULL };
static const EntityMsg* const sStep_d55_s4[] = { M(sMsg_d55_s4_0), NULL };
static const EntityMsg* const sStep_d55_s5[] = { M(sMsg_d55_s5_0), NULL };
static const EntityMsg* const sStep_d55_s6[] = { M(sMsg_d55_s6_0), NULL };
static const EntityMsg* const sStep_d55_s7[] = { M(sMsg_d55_s7_0), NULL };
static const EntityMsg* const sStep_d55_s8[] = { M(sMsg_d55_s8_0), NULL };
static const EntityMsg* const sStep_d55_s9[] = { M(sMsg_d55_s9_0), NULL };
static const EntityMsg* const sStep_d55_s10[] = { M(sMsg_d55_s10_0), NULL };
static const EntityMsg* const sStep_d55_s11[] = { M(sMsg_d55_s11_0), NULL };
static const EntityMsg* const sStep_d55_s12[] = { M(sMsg_d55_s12_0), NULL };
static const EntityMsg* const sStep_d55_s13[] = { M(sMsg_d55_s13_0), NULL };
static const EntityMsg* const sStep_d55_s14[] = { M(sMsg_d55_s14_0), NULL };
static const EntityMsg* const sStep_d55_s15[] = { M(sMsg_d55_s15_0), NULL };
static const EntityMsg* const sStep_d55_s16[] = { M(sMsg_d55_s16_0), NULL };
static const EntityMsg* const sStep_d55_s17[] = { M(sMsg_d55_s17_0), NULL };
static const EntityMsg* const sStep_d55_s18[] = { M(sMsg_d55_s18_0), M(sMsg_d55_s18_1), M(sMsg_d55_s18_2), NULL };
static const EntityMsg* const sStep_d55_s19[] = { M(sMsg_d55_s19_0), NULL };
static const EntityMsg* const sStep_d55_s20[] = { M(sMsg_d55_s20_0), NULL };
static const EntityMsg* const sStep_d55_s21[] = { M(sMsg_d55_s21_0), M(sMsg_d55_s21_1), M(sMsg_d55_s21_2), NULL };
static const EntityMsg* const sStep_d55_s22[] = { M(sMsg_d55_s22_0), NULL };
static const EntityMsg* const sStep_d55_s23[] = { M(sMsg_d55_s23_0), NULL };
static const EntityMsg* const sStep_d55_s24[] = { M(sMsg_d55_s24_0), M(sMsg_d55_s24_1), NULL };
static const EntityMsg* const sStep_d55_s25[] = { M(sMsg_d55_s25_0), NULL };
static const EntityMsg* const sStep_d55_s26[] = { M(sMsg_d55_s26_0), NULL };
static const EntityMsg* const sStep_d55_s27[] = { M(sMsg_d55_s27_0), M(sMsg_d55_s27_1), NULL };
static const EntityMsg* const sStep_d55_s28[] = { M(sMsg_d55_s28_0), NULL };
static const EntityMsg* const sStep_d55_s29[] = { M(sMsg_d55_s29_0), NULL };
static const EntityMsg* const sStep_d55_s30[] = { M(sMsg_d55_s30_0), M(sMsg_d55_s30_1), NULL };
static const EntityMsg* const sStep_d55_s31[] = { M(sMsg_d55_s31_0), NULL };
static const EntityMsg* const sStep_d55_s32[] = { M(sMsg_d55_s32_0), NULL };
static const EntityMsg* const sStep_d55_s33[] = { M(sMsg_d55_s33_0), M(sMsg_d55_s33_1), NULL };
static const EntityMsg* const sStep_d55_s34[] = { M(sMsg_d55_s34_0), NULL };
static const EntityMsg* const sStep_d55_s35[] = { M(sMsg_d55_s35_0), NULL };
static const EntityMsg* const sStep_d55_s36[] = { M(sMsg_d55_s36_0), M(sMsg_d55_s36_1), NULL };
static const EntityMsg* const sStep_d55_s37[] = { M(sMsg_d55_s37_0), M(sMsg_d55_s37_1), M(sMsg_d55_s37_2), NULL };
static const EntityMsg* const sStep_d55_s38[] = { M(sMsg_d55_s38_0), NULL };
static const EntityMsg* const sStep_d55_s39[] = { M(sMsg_d55_s39_0), NULL };
static const EntityMsg* const sStep_d55_s40[] = { M(sMsg_d55_s40_0), NULL };
static const EntityMsg* const sStep_d55_s41[] = { M(sMsg_d55_s41_0), NULL };
static const EntityMsg* const sStep_d55_s42[] = { M(sMsg_d55_s42_0), NULL };
static const EntityMsg* const sStep_d55_s43[] = { M(sMsg_d55_s43_0), NULL };
static const EntityMsg* const sStep_d55_s44[] = { M(sMsg_d55_s44_0), NULL };
static const EntityMsg* const sStep_d55_s45[] = { M(sMsg_d55_s45_0), NULL };
static const EntityMsg* const sStep_d55_s46[] = { M(sMsg_d55_s46_0), M(sMsg_d55_s46_1), NULL };
static const EntityMsg* const sStep_d55_s47[] = { M(sMsg_d55_s47_0), NULL };
static const EntityMsg* const sStep_d55_s48[] = { M(sMsg_d55_s48_0), NULL };
static const EntityMsg* const sStep_d55_s49[] = { M(sMsg_d55_s49_0), NULL };
static const EntityMsg* const sStep_d55_s50[] = { M(sMsg_d55_s50_0), NULL };
static const EntityMsg* const sStep_d55_s51[] = { M(sMsg_d55_s51_0), NULL };
static const EntityMsg* const sStep_d55_s52[] = { M(sMsg_d55_s52_0), M(sMsg_d55_s52_1), M(sMsg_d55_s52_2), NULL };
static const EntityMsg* const sStep_d55_s53[] = { M(sMsg_d55_s53_0), M(sMsg_d55_s53_1), NULL };
static const EntityMsg* const sStep_d55_s54[] = { M(sMsg_d55_s54_0), NULL };
static const EntityMsg* const sStep_d55_s55[] = { M(sMsg_d55_s55_0), NULL };
static const EntityMsg* const sStep_d56_s0[] = { M(sMsg_d56_s0_0), M(sMsg_d56_s0_1), NULL };
static const EntityMsg* const sStep_d56_s1[] = { M(sMsg_d56_s1_0), M(sMsg_d56_s1_1), M(sMsg_d56_s1_2), M(sMsg_d56_s1_3), M(sMsg_d56_s1_4), NULL };
static const EntityMsg* const sStep_d56_s2[] = { M(sMsg_d56_s2_0), M(sMsg_d56_s2_1), NULL };
static const EntityMsg* const sStep_d56_s3[] = { M(sMsg_d56_s3_0), M(sMsg_d56_s3_1), M(sMsg_d56_s3_2), NULL };
static const EntityMsg* const sStep_d56_s4[] = { M(sMsg_d56_s4_0), NULL };
static const EntityMsg* const sStep_d56_s5[] = { M(sMsg_d56_s5_0), NULL };
static const EntityMsg* const sStep_d56_s6[] = { M(sMsg_d56_s6_0), NULL };
static const EntityMsg* const sStep_d56_s7[] = { M(sMsg_d56_s7_0), NULL };
static const EntityMsg* const sStep_d56_s8[] = { M(sMsg_d56_s8_0), NULL };
static const EntityMsg* const sStep_d56_s9[] = { M(sMsg_d56_s9_0), NULL };
static const EntityMsg* const sStep_d56_s10[] = { M(sMsg_d56_s10_0), NULL };
static const EntityMsg* const sStep_d56_s11[] = { M(sMsg_d56_s11_0), NULL };
static const EntityMsg* const sStep_d56_s12[] = { M(sMsg_d56_s12_0), NULL };
static const EntityMsg* const sStep_d56_s13[] = { M(sMsg_d56_s13_0), NULL };
static const EntityMsg* const sStep_d56_s14[] = { M(sMsg_d56_s14_0), M(sMsg_d56_s14_1), NULL };
static const EntityMsg* const sStep_d56_s15[] = { M(sMsg_d56_s15_0), M(sMsg_d56_s15_1), M(sMsg_d56_s15_2), M(sMsg_d56_s15_3), NULL };
static const EntityMsg* const sStep_d56_s16[] = { M(sMsg_d56_s16_0), NULL };
static const EntityMsg* const sStep_d56_s17[] = { M(sMsg_d56_s17_0), NULL };
static const EntityMsg* const sStep_d56_s18[] = { M(sMsg_d56_s18_0), M(sMsg_d56_s18_1), NULL };
static const EntityMsg* const sStep_d56_s19[] = { M(sMsg_d56_s19_0), NULL };
static const EntityMsg* const sStep_d56_s20[] = { M(sMsg_d56_s20_0), NULL };
static const EntityMsg* const sStep_d56_s21[] = { M(sMsg_d56_s21_0), M(sMsg_d56_s21_1), NULL };
static const EntityMsg* const sStep_d56_s22[] = { M(sMsg_d56_s22_0), NULL };
static const EntityMsg* const sStep_d56_s23[] = { M(sMsg_d56_s23_0), NULL };
static const EntityMsg* const sStep_d56_s24[] = { M(sMsg_d56_s24_0), NULL };
static const EntityMsg* const sStep_d56_s25[] = { M(sMsg_d56_s25_0), NULL };
static const EntityMsg* const sStep_d56_s26[] = { M(sMsg_d56_s26_0), NULL };
static const EntityMsg* const sStep_d56_s27[] = { M(sMsg_d56_s27_0), M(sMsg_d56_s27_1), NULL };
static const EntityMsg* const sStep_d56_s28[] = { M(sMsg_d56_s28_0), NULL };
static const EntityMsg* const sStep_d56_s29[] = { M(sMsg_d56_s29_0), NULL };
static const EntityMsg* const sStep_d56_s30[] = { M(sMsg_d56_s30_0), M(sMsg_d56_s30_1), NULL };
static const EntityMsg* const sStep_d56_s31[] = { M(sMsg_d56_s31_0), M(sMsg_d56_s31_1), M(sMsg_d56_s31_2), NULL };
static const EntityMsg* const sStep_d56_s32[] = { M(sMsg_d56_s32_0), M(sMsg_d56_s32_1), M(sMsg_d56_s32_2), NULL };
static const EntityMsg* const sStep_d56_s33[] = { M(sMsg_d56_s33_0), M(sMsg_d56_s33_1), NULL };
static const EntityMsg* const sStep_d56_s34[] = { M(sMsg_d56_s34_0), NULL };
static const EntityMsg* const sStep_d56_s35[] = { M(sMsg_d56_s35_0), NULL };
static const EntityMsg* const sStep_d56_s36[] = { M(sMsg_d56_s36_0), M(sMsg_d56_s36_1), M(sMsg_d56_s36_2), NULL };
static const EntityMsg* const sStep_d56_s37[] = { M(sMsg_d56_s37_0), NULL };
static const EntityMsg* const sStep_d56_s38[] = { M(sMsg_d56_s38_0), NULL };
static const EntityMsg* const sStep_d56_s39[] = { M(sMsg_d56_s39_0), M(sMsg_d56_s39_1), M(sMsg_d56_s39_2), NULL };
static const EntityMsg* const sStep_d56_s40[] = { M(sMsg_d56_s40_0), NULL };
static const EntityMsg* const sStep_d56_s41[] = { M(sMsg_d56_s41_0), NULL };
static const EntityMsg* const sStep_d56_s42[] = { M(sMsg_d56_s42_0), M(sMsg_d56_s42_1), M(sMsg_d56_s42_2), NULL };
static const EntityMsg* const sStep_d56_s43[] = { M(sMsg_d56_s43_0), NULL };
static const EntityMsg* const sStep_d56_s44[] = { M(sMsg_d56_s44_0), NULL };
static const EntityMsg* const sStep_d56_s45[] = { M(sMsg_d56_s45_0), M(sMsg_d56_s45_1), NULL };
static const EntityMsg* const sStep_d56_s46[] = { M(sMsg_d56_s46_0), M(sMsg_d56_s46_1), M(sMsg_d56_s46_2), M(sMsg_d56_s46_3), M(sMsg_d56_s46_4), NULL };
static const EntityMsg* const sStep_d56_s47[] = { M(sMsg_d56_s47_0), NULL };
static const EntityMsg* const sStep_d56_s48[] = { M(sMsg_d56_s48_0), NULL };
static const EntityMsg* const sStep_d56_s49[] = { M(sMsg_d56_s49_0), M(sMsg_d56_s49_1), M(sMsg_d56_s49_2), NULL };
static const EntityMsg* const sStep_d56_s50[] = { M(sMsg_d56_s50_0), NULL };
static const EntityMsg* const sStep_d56_s51[] = { M(sMsg_d56_s51_0), NULL };
static const EntityMsg* const sStep_d56_s52[] = { M(sMsg_d56_s52_0), M(sMsg_d56_s52_1), M(sMsg_d56_s52_2), NULL };
static const EntityMsg* const sStep_d56_s53[] = { M(sMsg_d56_s53_0), NULL };
static const EntityMsg* const sStep_d56_s54[] = { M(sMsg_d56_s54_0), NULL };
static const EntityMsg* const sStep_d56_s55[] = { M(sMsg_d56_s55_0), M(sMsg_d56_s55_1), NULL };
static const EntityMsg* const sStep_d56_s56[] = { M(sMsg_d56_s56_0), NULL };
static const EntityMsg* const sStep_d56_s57[] = { M(sMsg_d56_s57_0), NULL };
static const EntityMsg* const sStep_d56_s58[] = { M(sMsg_d56_s58_0), NULL };
static const EntityMsg* const sStep_d56_s59[] = { M(sMsg_d56_s59_0), M(sMsg_d56_s59_1), M(sMsg_d56_s59_2), M(sMsg_d56_s59_3), NULL };
static const EntityMsg* const sStep_d56_s60[] = { M(sMsg_d56_s60_0), NULL };
static const EntityMsg* const sStep_d56_s61[] = { M(sMsg_d56_s61_0), NULL };
static const EntityMsg* const sStep_d56_s62[] = { M(sMsg_d56_s62_0), M(sMsg_d56_s62_1), NULL };
static const EntityMsg* const sStep_d57_s0[] = { M(sMsg_d57_s0_0), M(sMsg_d57_s0_1), NULL };
static const EntityMsg* const sStep_d57_s1[] = { M(sMsg_d57_s1_0), M(sMsg_d57_s1_1), M(sMsg_d57_s1_2), NULL };
static const EntityMsg* const sStep_d57_s2[] = { M(sMsg_d57_s2_0), NULL };
static const EntityMsg* const sStep_d57_s3[] = { M(sMsg_d57_s3_0), NULL };
static const EntityMsg* const sStep_d58_s0[] = { M(sMsg_d58_s0_0), M(sMsg_d58_s0_1), NULL };
static const EntityMsg* const sStep_d58_s1[] = { M(sMsg_d58_s1_0), M(sMsg_d58_s1_1), M(sMsg_d58_s1_2), NULL };
static const EntityMsg* const sStep_d58_s2[] = { M(sMsg_d58_s2_0), M(sMsg_d58_s2_1), NULL };
static const EntityMsg* const sStep_d58_s3[] = { M(sMsg_d58_s3_0), NULL };
static const EntityMsg* const sStep_d58_s4[] = { M(sMsg_d58_s4_0), NULL };
static const EntityMsg* const sStep_d58_s5[] = { M(sMsg_d58_s5_0), M(sMsg_d58_s5_1), NULL };
static const EntityMsg* const sStep_d58_s6[] = { M(sMsg_d58_s6_0), M(sMsg_d58_s6_1), NULL };
static const EntityMsg* const sStep_d58_s7[] = { M(sMsg_d58_s7_0), NULL };
static const EntityMsg* const sStep_d58_s8[] = { M(sMsg_d58_s8_0), NULL };
static const EntityMsg* const sStep_d58_s9[] = { M(sMsg_d58_s9_0), NULL };
static const EntityMsg* const sStep_d58_s10[] = { M(sMsg_d58_s10_0), NULL };
static const EntityMsg* const sStep_d58_s11[] = { M(sMsg_d58_s11_0), M(sMsg_d58_s11_1), NULL };
static const EntityMsg* const sStep_d59_s0[] = { M(sMsg_d59_s0_0), NULL };
static const EntityMsg* const sStep_d59_s1[] = { M(sMsg_d59_s1_0), M(sMsg_d59_s1_1), M(sMsg_d59_s1_2), NULL };
static const EntityMsg* const sStep_d59_s2[] = { M(sMsg_d59_s2_0), NULL };
static const EntityMsg* const sStep_d59_s3[] = { M(sMsg_d59_s3_0), NULL };
static const EntityMsg* const sStep_d59_s4[] = { M(sMsg_d59_s4_0), NULL };
static const EntityMsg* const sStep_d59_s5[] = { M(sMsg_d59_s5_0), M(sMsg_d59_s5_1), NULL };
static const EntityMsg* const sStep_d59_s6[] = { M(sMsg_d59_s6_0), M(sMsg_d59_s6_1), NULL };
static const EntityMsg* const sStep_d59_s7[] = { M(sMsg_d59_s7_0), NULL };
static const EntityMsg* const sStep_d59_s8[] = { M(sMsg_d59_s8_0), NULL };
static const EntityMsg* const sStep_d59_s9[] = { M(sMsg_d59_s9_0), NULL };
static const EntityMsg* const sStep_d59_s10[] = { M(sMsg_d59_s10_0), NULL };
static const EntityMsg* const sStep_d59_s11[] = { M(sMsg_d59_s11_0), M(sMsg_d59_s11_1), NULL };
static const EntityMsg* const sStep_d60_s0[] = { M(sMsg_d60_s0_0), NULL };
static const EntityMsg* const sStep_d60_s1[] = { M(sMsg_d60_s1_0), NULL };
static const EntityMsg* const sStep_d60_s2[] = { M(sMsg_d60_s2_0), M(sMsg_d60_s2_1), NULL };
static const EntityMsg* const sStep_d61_s0[] = { M(sMsg_d61_s0_0), NULL };
static const EntityMsg* const sStep_d61_s1[] = { M(sMsg_d61_s1_0), NULL };
static const EntityMsg* const sStep_d61_s2[] = { M(sMsg_d61_s2_0), M(sMsg_d61_s2_1), NULL };
static const EntityMsg* const sStep_d62_s0[] = { M(sMsg_d62_s0_0), NULL };
static const EntityMsg* const sStep_d62_s1[] = { M(sMsg_d62_s1_0), M(sMsg_d62_s1_1), NULL };
static const EntityMsg* const sStep_d62_s2[] = { M(sMsg_d62_s2_0), M(sMsg_d62_s2_1), M(sMsg_d62_s2_2), M(sMsg_d62_s2_3), M(sMsg_d62_s2_4), NULL };
static const EntityMsg* const sStep_d62_s3[] = { M(sMsg_d62_s3_0), M(sMsg_d62_s3_1), M(sMsg_d62_s3_2), NULL };
static const EntityMsg* const sStep_d62_s4[] = { M(sMsg_d62_s4_0), M(sMsg_d62_s4_1), M(sMsg_d62_s4_2), NULL };
static const EntityMsg* const sStep_d62_s5[] = { M(sMsg_d62_s5_0), M(sMsg_d62_s5_1), NULL };
static const EntityMsg* const sStep_d62_s6[] = { M(sMsg_d62_s6_0), M(sMsg_d62_s6_1), NULL };
static const EntityMsg* const sStep_d62_s7[] = { M(sMsg_d62_s7_0), M(sMsg_d62_s7_1), NULL };
static const EntityMsg* const sStep_d63_s0[] = { M(sMsg_d63_s0_0), M(sMsg_d63_s0_1), M(sMsg_d63_s0_2), M(sMsg_d63_s0_3), NULL };
static const EntityMsg* const sStep_d63_s1[] = { M(sMsg_d63_s1_0), M(sMsg_d63_s1_1), M(sMsg_d63_s1_2), NULL };
static const EntityMsg* const sStep_d63_s2[] = { M(sMsg_d63_s2_0), M(sMsg_d63_s2_1), NULL };
static const EntityMsg* const sStep_d63_s3[] = { M(sMsg_d63_s3_0), M(sMsg_d63_s3_1), NULL };
static const EntityMsg* const sStep_d63_s4[] = { M(sMsg_d63_s4_0), NULL };
static const EntityMsg* const sStep_d63_s5[] = { M(sMsg_d63_s5_0), NULL };
static const EntityMsg* const sStep_d63_s6[] = { M(sMsg_d63_s6_0), NULL };
static const EntityMsg* const sStep_d63_s7[] = { M(sMsg_d63_s7_0), M(sMsg_d63_s7_1), NULL };
static const EntityMsg* const sStep_d63_s8[] = { M(sMsg_d63_s8_0), NULL };
static const EntityMsg* const sStep_d63_s9[] = { M(sMsg_d63_s9_0), NULL };
static const EntityMsg* const sStep_d63_s10[] = { M(sMsg_d63_s10_0), M(sMsg_d63_s10_1), NULL };
static const EntityMsg* const sStep_d63_s11[] = { M(sMsg_d63_s11_0), NULL };
static const EntityMsg* const sStep_d63_s12[] = { M(sMsg_d63_s12_0), NULL };
static const EntityMsg* const sStep_d63_s13[] = { M(sMsg_d63_s13_0), M(sMsg_d63_s13_1), NULL };
static const EntityMsg* const sStep_d63_s14[] = { M(sMsg_d63_s14_0), NULL };
static const EntityMsg* const sStep_d63_s15[] = { M(sMsg_d63_s15_0), M(sMsg_d63_s15_1), NULL };
static const EntityMsg* const sStep_d63_s16[] = { M(sMsg_d63_s16_0), NULL };
static const EntityMsg* const sStep_d63_s17[] = { M(sMsg_d63_s17_0), NULL };
static const EntityMsg* const sStep_d63_s18[] = { M(sMsg_d63_s18_0), M(sMsg_d63_s18_1), NULL };
static const EntityMsg* const sStep_d63_s19[] = { M(sMsg_d63_s19_0), M(sMsg_d63_s19_1), M(sMsg_d63_s19_2), NULL };
static const EntityMsg* const sStep_d63_s20[] = { M(sMsg_d63_s20_0), M(sMsg_d63_s20_1), NULL };
static const EntityMsg* const sStep_d63_s21[] = { M(sMsg_d63_s21_0), NULL };
static const EntityMsg* const sStep_d63_s22[] = { M(sMsg_d63_s22_0), NULL };
static const EntityMsg* const sStep_d63_s23[] = { M(sMsg_d63_s23_0), NULL };
static const EntityMsg* const sStep_d63_s24[] = { M(sMsg_d63_s24_0), M(sMsg_d63_s24_1), NULL };
static const EntityMsg* const sStep_d63_s25[] = { M(sMsg_d63_s25_0), M(sMsg_d63_s25_1), NULL };
static const EntityMsg* const sStep_d63_s26[] = { M(sMsg_d63_s26_0), M(sMsg_d63_s26_1), M(sMsg_d63_s26_2), M(sMsg_d63_s26_3), M(sMsg_d63_s26_4), NULL };
static const EntityMsg* const sStep_d63_s27[] = { M(sMsg_d63_s27_0), NULL };
static const EntityMsg* const sStep_d63_s28[] = { M(sMsg_d63_s28_0), NULL };
static const EntityMsg* const sStep_d63_s29[] = { M(sMsg_d63_s29_0), NULL };
static const EntityMsg* const sStep_d63_s30[] = { M(sMsg_d63_s30_0), NULL };
static const EntityMsg* const sStep_d63_s31[] = { M(sMsg_d63_s31_0), NULL };
static const EntityMsg* const sStep_d63_s32[] = { M(sMsg_d63_s32_0), M(sMsg_d63_s32_1), NULL };
static const EntityMsg* const sStep_d63_s33[] = { M(sMsg_d63_s33_0), M(sMsg_d63_s33_1), M(sMsg_d63_s33_2), NULL };
static const EntityMsg* const sStep_d63_s34[] = { M(sMsg_d63_s34_0), NULL };
static const EntityMsg* const sStep_d63_s35[] = { M(sMsg_d63_s35_0), NULL };
static const EntityMsg* const sStep_d63_s36[] = { M(sMsg_d63_s36_0), M(sMsg_d63_s36_1), NULL };
static const EntityMsg* const sStep_d63_s37[] = { M(sMsg_d63_s37_0), M(sMsg_d63_s37_1), M(sMsg_d63_s37_2), M(sMsg_d63_s37_3), M(sMsg_d63_s37_4), NULL };
static const EntityMsg* const sStep_d63_s38[] = { M(sMsg_d63_s38_0), NULL };
static const EntityMsg* const sStep_d63_s39[] = { M(sMsg_d63_s39_0), NULL };
static const EntityMsg* const sStep_d63_s40[] = { M(sMsg_d63_s40_0), NULL };
static const EntityMsg* const sStep_d63_s41[] = { M(sMsg_d63_s41_0), NULL };
static const EntityMsg* const sStep_d63_s42[] = { M(sMsg_d63_s42_0), NULL };
static const EntityMsg* const sStep_d63_s43[] = { M(sMsg_d63_s43_0), NULL };
static const EntityMsg* const sStep_d63_s44[] = { M(sMsg_d63_s44_0), NULL };
static const EntityMsg* const sStep_d63_s45[] = { M(sMsg_d63_s45_0), NULL };
static const EntityMsg* const sStep_d63_s46[] = { M(sMsg_d63_s46_0), M(sMsg_d63_s46_1), M(sMsg_d63_s46_2), NULL };
static const EntityMsg* const sStep_d63_s47[] = { M(sMsg_d63_s47_0), M(sMsg_d63_s47_1), NULL };
static const EntityMsg* const sStep_d64_s0[] = { M(sMsg_d64_s0_0), M(sMsg_d64_s0_1), NULL };
static const EntityMsg* const sStep_d64_s1[] = { M(sMsg_d64_s1_0), M(sMsg_d64_s1_1), NULL };
static const EntityMsg* const sStep_d64_s2[] = { M(sMsg_d64_s2_0), NULL };
static const EntityMsg* const sStep_d64_s3[] = { M(sMsg_d64_s3_0), NULL };
static const EntityMsg* const sStep_d64_s4[] = { M(sMsg_d64_s4_0), M(sMsg_d64_s4_1), NULL };
static const EntityMsg* const sStep_d65_s0[] = { M(sMsg_d65_s0_0), NULL };
static const EntityMsg* const sStep_d65_s1[] = { M(sMsg_d65_s1_0), M(sMsg_d65_s1_1), NULL };
static const EntityMsg* const sStep_d65_s2[] = { M(sMsg_d65_s2_0), NULL };
static const EntityMsg* const sStep_d65_s3[] = { M(sMsg_d65_s3_0), NULL };
static const EntityMsg* const sStep_d65_s4[] = { M(sMsg_d65_s4_0), M(sMsg_d65_s4_1), M(sMsg_d65_s4_2), NULL };
static const EntityMsg* const sStep_d65_s5[] = { M(sMsg_d65_s5_0), NULL };
static const EntityMsg* const sStep_d65_s6[] = { M(sMsg_d65_s6_0), NULL };
static const EntityMsg* const sStep_d65_s7[] = { M(sMsg_d65_s7_0), M(sMsg_d65_s7_1), NULL };
static const EntityMsg* const sStep_d65_s8[] = { M(sMsg_d65_s8_0), NULL };
static const EntityMsg* const sStep_d65_s9[] = { M(sMsg_d65_s9_0), NULL };
static const EntityMsg* const sStep_d65_s10[] = { M(sMsg_d65_s10_0), M(sMsg_d65_s10_1), NULL };
static const EntityMsg* const sStep_d65_s11[] = { M(sMsg_d65_s11_0), NULL };
static const EntityMsg* const sStep_d65_s12[] = { M(sMsg_d65_s12_0), NULL };
static const EntityMsg* const sStep_d65_s13[] = { M(sMsg_d65_s13_0), M(sMsg_d65_s13_1), NULL };
static const EntityMsg* const sStep_d65_s14[] = { M(sMsg_d65_s14_0), M(sMsg_d65_s14_1), NULL };
static const EntityMsg* const sStep_d65_s15[] = { M(sMsg_d65_s15_0), M(sMsg_d65_s15_1), M(sMsg_d65_s15_2), NULL };
static const EntityMsg* const sStep_d65_s16[] = { M(sMsg_d65_s16_0), M(sMsg_d65_s16_1), NULL };
static const EntityMsg* const sStep_d66_s0[] = { M(sMsg_d66_s0_0), M(sMsg_d66_s0_1), NULL };
static const EntityMsg* const sStep_d66_s1[] = { M(sMsg_d66_s1_0), NULL };
static const EntityMsg* const sStep_d66_s2[] = { M(sMsg_d66_s2_0), NULL };
static const EntityMsg* const sStep_d66_s3[] = { M(sMsg_d66_s3_0), NULL };
static const EntityMsg* const sStep_d66_s4[] = { M(sMsg_d66_s4_0), NULL };
static const EntityMsg* const sStep_d66_s5[] = { M(sMsg_d66_s5_0), M(sMsg_d66_s5_1), M(sMsg_d66_s5_2), NULL };
static const EntityMsg* const sStep_d66_s6[] = { M(sMsg_d66_s6_0), M(sMsg_d66_s6_1), M(sMsg_d66_s6_2), M(sMsg_d66_s6_3), NULL };
static const EntityMsg* const sStep_d66_s7[] = { M(sMsg_d66_s7_0), M(sMsg_d66_s7_1), M(sMsg_d66_s7_2), M(sMsg_d66_s7_3), M(sMsg_d66_s7_4), NULL };
static const EntityMsg* const sStep_d66_s8[] = { M(sMsg_d66_s8_0), NULL };
static const EntityMsg* const sStep_d66_s9[] = { M(sMsg_d66_s9_0), NULL };
static const EntityMsg* const sStep_d66_s10[] = { M(sMsg_d66_s10_0), M(sMsg_d66_s10_1), NULL };
static const EntityMsg* const sStep_d66_s11[] = { M(sMsg_d66_s11_0), NULL };
static const EntityMsg* const sStep_d66_s12[] = { M(sMsg_d66_s12_0), NULL };
static const EntityMsg* const sStep_d67_s0[] = { M(sMsg_d67_s0_0), NULL };
static const EntityMsg* const sStep_d67_s1[] = { M(sMsg_d67_s1_0), M(sMsg_d67_s1_1), NULL };
static const EntityMsg* const sStep_d67_s2[] = { M(sMsg_d67_s2_0), M(sMsg_d67_s2_1), NULL };
static const EntityMsg* const sStep_d67_s3[] = { M(sMsg_d67_s3_0), M(sMsg_d67_s3_1), M(sMsg_d67_s3_2), NULL };
static const EntityMsg* const sStep_d67_s4[] = { M(sMsg_d67_s4_0), NULL };
static const EntityMsg* const sStep_d67_s5[] = { M(sMsg_d67_s5_0), NULL };
static const EntityMsg* const sStep_d67_s6[] = { M(sMsg_d67_s6_0), NULL };
static const EntityMsg* const sStep_d67_s7[] = { M(sMsg_d67_s7_0), M(sMsg_d67_s7_1), M(sMsg_d67_s7_2), M(sMsg_d67_s7_3), NULL };
static const EntityMsg* const sStep_d67_s8[] = { M(sMsg_d67_s8_0), NULL };
static const EntityMsg* const sStep_d67_s9[] = { M(sMsg_d67_s9_0), NULL };
static const EntityMsg* const sStep_d67_s10[] = { M(sMsg_d67_s10_0), M(sMsg_d67_s10_1), NULL };
static const EntityMsg* const sStep_d67_s11[] = { M(sMsg_d67_s11_0), NULL };
static const EntityMsg* const sStep_d67_s12[] = { M(sMsg_d67_s12_0), NULL };
static const EntityMsg* const sStep_d68_s0[] = { M(sMsg_d68_s0_0), M(sMsg_d68_s0_1), M(sMsg_d68_s0_2), NULL };
static const EntityMsg* const sStep_d68_s1[] = { M(sMsg_d68_s1_0), NULL };
static const EntityMsg* const sStep_d68_s2[] = { M(sMsg_d68_s2_0), NULL };
static const EntityMsg* const sStep_d68_s3[] = { M(sMsg_d68_s3_0), NULL };
static const EntityMsg* const sStep_d68_s4[] = { M(sMsg_d68_s4_0), NULL };
static const EntityMsg* const sStep_d68_s5[] = { M(sMsg_d68_s5_0), NULL };
static const EntityMsg* const sStep_d68_s6[] = { M(sMsg_d68_s6_0), NULL };
static const EntityMsg* const sStep_d68_s7[] = { M(sMsg_d68_s7_0), NULL };
static const EntityMsg* const sStep_d68_s8[] = { M(sMsg_d68_s8_0), NULL };
static const EntityMsg* const sStep_d68_s9[] = { M(sMsg_d68_s9_0), NULL };
static const EntityMsg* const sStep_d68_s10[] = { M(sMsg_d68_s10_0), NULL };
static const EntityMsg* const sStep_d68_s11[] = { M(sMsg_d68_s11_0), NULL };
static const EntityMsg* const sStep_d69_s0[] = { M(sMsg_d69_s0_0), NULL };
static const EntityMsg* const sStep_d69_s1[] = { M(sMsg_d69_s1_0), NULL };
static const EntityMsg* const sStep_d69_s2[] = { M(sMsg_d69_s2_0), NULL };
static const EntityMsg* const sStep_d69_s3[] = { M(sMsg_d69_s3_0), NULL };
static const EntityMsg* const sStep_d69_s4[] = { M(sMsg_d69_s4_0), NULL };
static const EntityMsg* const sStep_d69_s5[] = { M(sMsg_d69_s5_0), NULL };
static const EntityMsg* const sStep_d69_s6[] = { M(sMsg_d69_s6_0), M(sMsg_d69_s6_1), NULL };
static const EntityMsg* const sStep_d69_s7[] = { M(sMsg_d69_s7_0), M(sMsg_d69_s7_1), NULL };
static const EntityMsg* const sStep_d69_s8[] = { M(sMsg_d69_s8_0), M(sMsg_d69_s8_1), M(sMsg_d69_s8_2), NULL };
static const EntityMsg* const sStep_d69_s9[] = { M(sMsg_d69_s9_0), NULL };
static const EntityMsg* const sStep_d69_s10[] = { M(sMsg_d69_s10_0), NULL };
static const EntityMsg* const sStep_d69_s11[] = { M(sMsg_d69_s11_0), M(sMsg_d69_s11_1), M(sMsg_d69_s11_2), NULL };
static const EntityMsg* const sStep_d69_s12[] = { M(sMsg_d69_s12_0), M(sMsg_d69_s12_1), NULL };
static const EntityMsg* const sStep_d69_s13[] = { M(sMsg_d69_s13_0), NULL };
static const EntityMsg* const sStep_d69_s14[] = { M(sMsg_d69_s14_0), NULL };
static const EntityMsg* const sStep_d69_s15[] = { M(sMsg_d69_s15_0), M(sMsg_d69_s15_1), M(sMsg_d69_s15_2), NULL };
static const EntityMsg* const sStep_d69_s16[] = { M(sMsg_d69_s16_0), NULL };
static const EntityMsg* const sStep_d69_s17[] = { M(sMsg_d69_s17_0), NULL };
static const EntityMsg* const sStep_d69_s18[] = { M(sMsg_d69_s18_0), NULL };
static const EntityMsg* const sStep_d69_s19[] = { M(sMsg_d69_s19_0), NULL };
static const EntityMsg* const sStep_d69_s20[] = { M(sMsg_d69_s20_0), NULL };
static const EntityMsg* const sStep_d69_s21[] = { M(sMsg_d69_s21_0), NULL };
static const EntityMsg* const sStep_d70_s0[] = { M(sMsg_d70_s0_0), M(sMsg_d70_s0_1), NULL };
static const EntityMsg* const sStep_d70_s1[] = { M(sMsg_d70_s1_0), M(sMsg_d70_s1_1), M(sMsg_d70_s1_2), M(sMsg_d70_s1_3), M(sMsg_d70_s1_4), M(sMsg_d70_s1_5), M(sMsg_d70_s1_6), NULL };
static const EntityMsg* const sStep_d70_s2[] = { M(sMsg_d70_s2_0), NULL };
static const EntityMsg* const sStep_d70_s3[] = { M(sMsg_d70_s3_0), M(sMsg_d70_s3_1), NULL };
static const EntityMsg* const sStep_d70_s4[] = { M(sMsg_d70_s4_0), M(sMsg_d70_s4_1), NULL };
static const EntityMsg* const sStep_d70_s5[] = { M(sMsg_d70_s5_0), NULL };
static const EntityMsg* const sStep_d70_s6[] = { M(sMsg_d70_s6_0), NULL };
static const EntityMsg* const sStep_d70_s7[] = { M(sMsg_d70_s7_0), M(sMsg_d70_s7_1), M(sMsg_d70_s7_2), M(sMsg_d70_s7_3), M(sMsg_d70_s7_4), NULL };
static const EntityMsg* const sStep_d71_s0[] = { M(sMsg_d71_s0_0), M(sMsg_d71_s0_1), NULL };
static const EntityMsg* const sStep_d71_s1[] = { M(sMsg_d71_s1_0), NULL };
static const EntityMsg* const sStep_d71_s2[] = { M(sMsg_d71_s2_0), NULL };
static const EntityMsg* const sStep_d71_s3[] = { M(sMsg_d71_s3_0), M(sMsg_d71_s3_1), NULL };
static const EntityMsg* const sStep_d71_s4[] = { M(sMsg_d71_s4_0), NULL };
static const EntityMsg* const sStep_d71_s5[] = { M(sMsg_d71_s5_0), NULL };
static const EntityMsg* const sStep_d71_s6[] = { M(sMsg_d71_s6_0), M(sMsg_d71_s6_1), NULL };
static const EntityMsg* const sStep_d71_s7[] = { M(sMsg_d71_s7_0), NULL };
static const EntityMsg* const sStep_d71_s8[] = { M(sMsg_d71_s8_0), NULL };
static const EntityMsg* const sStep_d71_s9[] = { M(sMsg_d71_s9_0), M(sMsg_d71_s9_1), NULL };
static const EntityMsg* const sStep_d71_s10[] = { M(sMsg_d71_s10_0), NULL };
static const EntityMsg* const sStep_d71_s11[] = { M(sMsg_d71_s11_0), NULL };
static const EntityMsg* const sStep_d71_s12[] = { M(sMsg_d71_s12_0), M(sMsg_d71_s12_1), NULL };
static const EntityMsg* const sStep_d71_s13[] = { M(sMsg_d71_s13_0), NULL };
static const EntityMsg* const sStep_d71_s14[] = { M(sMsg_d71_s14_0), NULL };
static const EntityMsg* const sStep_d71_s15[] = { M(sMsg_d71_s15_0), M(sMsg_d71_s15_1), NULL };
static const EntityMsg* const sStep_d72_s0[] = { M(sMsg_d72_s0_0), NULL };
static const EntityMsg* const sStep_d72_s1[] = { M(sMsg_d72_s1_0), NULL };
static const EntityMsg* const sStep_d72_s2[] = { M(sMsg_d72_s2_0), NULL };
static const EntityMsg* const sStep_d72_s3[] = { M(sMsg_d72_s3_0), M(sMsg_d72_s3_1), M(sMsg_d72_s3_2), NULL };
static const EntityMsg* const sStep_d72_s4[] = { M(sMsg_d72_s4_0), NULL };
static const EntityMsg* const sStep_d72_s5[] = { M(sMsg_d72_s5_0), NULL };
static const EntityMsg* const sStep_d72_s6[] = { M(sMsg_d72_s6_0), M(sMsg_d72_s6_1), M(sMsg_d72_s6_2), NULL };
static const EntityMsg* const sStep_d72_s7[] = { M(sMsg_d72_s7_0), NULL };
static const EntityMsg* const sStep_d72_s8[] = { M(sMsg_d72_s8_0), NULL };
static const EntityMsg* const sStep_d72_s9[] = { M(sMsg_d72_s9_0), M(sMsg_d72_s9_1), M(sMsg_d72_s9_2), NULL };
static const EntityMsg* const sStep_d72_s10[] = { M(sMsg_d72_s10_0), NULL };
static const EntityMsg* const sStep_d72_s11[] = { M(sMsg_d72_s11_0), NULL };
static const EntityMsg* const sStep_d72_s12[] = { M(sMsg_d72_s12_0), M(sMsg_d72_s12_1), M(sMsg_d72_s12_2), M(sMsg_d72_s12_3), NULL };
static const EntityMsg* const sStep_d72_s13[] = { M(sMsg_d72_s13_0), M(sMsg_d72_s13_1), NULL };
static const EntityMsg* const sStep_d72_s14[] = { M(sMsg_d72_s14_0), NULL };
static const EntityMsg* const sStep_d72_s15[] = { M(sMsg_d72_s15_0), NULL };
static const EntityMsg* const sStep_d72_s16[] = { M(sMsg_d72_s16_0), M(sMsg_d72_s16_1), NULL };
static const EntityMsg* const sStep_d72_s17[] = { M(sMsg_d72_s17_0), NULL };
static const EntityMsg* const sStep_d72_s18[] = { M(sMsg_d72_s18_0), NULL };
static const EntityMsg* const sStep_d72_s19[] = { M(sMsg_d72_s19_0), M(sMsg_d72_s19_1), M(sMsg_d72_s19_2), M(sMsg_d72_s19_3), NULL };
static const EntityMsg* const sStep_d72_s20[] = { M(sMsg_d72_s20_0), M(sMsg_d72_s20_1), M(sMsg_d72_s20_2), NULL };
static const EntityMsg* const sStep_d72_s21[] = { M(sMsg_d72_s21_0), NULL };
static const EntityMsg* const sStep_d72_s22[] = { M(sMsg_d72_s22_0), NULL };
static const EntityMsg* const sStep_d72_s23[] = { M(sMsg_d72_s23_0), M(sMsg_d72_s23_1), NULL };
static const EntityMsg* const sStep_d72_s24[] = { M(sMsg_d72_s24_0), M(sMsg_d72_s24_1), NULL };
static const EntityMsg* const sStep_d72_s25[] = { M(sMsg_d72_s25_0), M(sMsg_d72_s25_1), NULL };
static const EntityMsg* const sStep_d73_s0[] = { M(sMsg_d73_s0_0), NULL };
static const EntityMsg* const sStep_d73_s1[] = { M(sMsg_d73_s1_0), NULL };
static const EntityMsg* const sStep_d73_s2[] = { M(sMsg_d73_s2_0), NULL };
static const EntityMsg* const sStep_d73_s3[] = { M(sMsg_d73_s3_0), M(sMsg_d73_s3_1), NULL };
static const EntityMsg* const sStep_d73_s4[] = { M(sMsg_d73_s4_0), NULL };
static const EntityMsg* const sStep_d73_s5[] = { M(sMsg_d73_s5_0), NULL };
static const EntityMsg* const sStep_d73_s6[] = { M(sMsg_d73_s6_0), M(sMsg_d73_s6_1), NULL };
static const EntityMsg* const sStep_d73_s7[] = { M(sMsg_d73_s7_0), NULL };
static const EntityMsg* const sStep_d73_s8[] = { M(sMsg_d73_s8_0), NULL };
static const EntityMsg* const sStep_d73_s9[] = { M(sMsg_d73_s9_0), M(sMsg_d73_s9_1), NULL };
static const EntityMsg* const sStep_d73_s10[] = { M(sMsg_d73_s10_0), NULL };
static const EntityMsg* const sStep_d73_s11[] = { M(sMsg_d73_s11_0), NULL };
static const EntityMsg* const sStep_d73_s12[] = { M(sMsg_d73_s12_0), M(sMsg_d73_s12_1), NULL };
static const EntityMsg* const sStep_d73_s13[] = { M(sMsg_d73_s13_0), M(sMsg_d73_s13_1), NULL };
static const EntityMsg* const sStep_d73_s14[] = { M(sMsg_d73_s14_0), NULL };
static const EntityMsg* const sStep_d73_s15[] = { M(sMsg_d73_s15_0), NULL };
static const EntityMsg* const sStep_d73_s16[] = { M(sMsg_d73_s16_0), NULL };
static const EntityMsg* const sStep_d74_s0[] = { M(sMsg_d74_s0_0), M(sMsg_d74_s0_1), M(sMsg_d74_s0_2), NULL };
static const EntityMsg* const sStep_d74_s1[] = { M(sMsg_d74_s1_0), M(sMsg_d74_s1_1), NULL };
static const EntityMsg* const sStep_d74_s2[] = { M(sMsg_d74_s2_0), M(sMsg_d74_s2_1), NULL };
static const EntityMsg* const sStep_d74_s3[] = { M(sMsg_d74_s3_0), NULL };
static const EntityMsg* const sStep_d74_s4[] = { M(sMsg_d74_s4_0), NULL };
static const EntityMsg* const sStep_d74_s5[] = { M(sMsg_d74_s5_0), M(sMsg_d74_s5_1), NULL };
static const EntityMsg* const sStep_d75_s0[] = { M(sMsg_d75_s0_0), M(sMsg_d75_s0_1), NULL };
static const EntityMsg* const sStep_d75_s1[] = { M(sMsg_d75_s1_0), NULL };
static const EntityMsg* const sStep_d75_s2[] = { M(sMsg_d75_s2_0), M(sMsg_d75_s2_1), NULL };
static const EntityMsg* const sStep_d75_s3[] = { M(sMsg_d75_s3_0), NULL };
static const EntityMsg* const sStep_d75_s4[] = { M(sMsg_d75_s4_0), NULL };
static const EntityMsg* const sStep_d75_s5[] = { M(sMsg_d75_s5_0), M(sMsg_d75_s5_1), NULL };
static const EntityMsg* const sStep_d75_s6[] = { M(sMsg_d75_s6_0), M(sMsg_d75_s6_1), M(sMsg_d75_s6_2), NULL };
static const EntityMsg* const sStep_d75_s7[] = { M(sMsg_d75_s7_0), NULL };
static const EntityMsg* const sStep_d75_s8[] = { M(sMsg_d75_s8_0), NULL };
static const EntityMsg* const sStep_d75_s9[] = { M(sMsg_d75_s9_0), M(sMsg_d75_s9_1), NULL };
static const EntityMsg* const sStep_d75_s10[] = { M(sMsg_d75_s10_0), NULL };
static const EntityMsg* const sStep_d75_s11[] = { M(sMsg_d75_s11_0), NULL };
static const EntityMsg* const sStep_d75_s12[] = { M(sMsg_d75_s12_0), M(sMsg_d75_s12_1), M(sMsg_d75_s12_2), M(sMsg_d75_s12_3), M(sMsg_d75_s12_4), NULL };
static const EntityMsg* const sStep_d75_s13[] = { M(sMsg_d75_s13_0), NULL };
static const EntityMsg* const sStep_d75_s14[] = { M(sMsg_d75_s14_0), NULL };
static const EntityMsg* const sStep_d75_s15[] = { M(sMsg_d75_s15_0), NULL };
static const EntityMsg* const sStep_d75_s16[] = { M(sMsg_d75_s16_0), M(sMsg_d75_s16_1), M(sMsg_d75_s16_2), M(sMsg_d75_s16_3), M(sMsg_d75_s16_4), NULL };
static const EntityMsg* const sStep_d75_s17[] = { M(sMsg_d75_s17_0), M(sMsg_d75_s17_1), NULL };
static const EntityMsg* const sStep_d75_s18[] = { M(sMsg_d75_s18_0), NULL };
static const EntityMsg* const sStep_d75_s19[] = { M(sMsg_d75_s19_0), NULL };
static const EntityMsg* const sStep_d75_s20[] = { M(sMsg_d75_s20_0), NULL };
static const EntityMsg* const sStep_d75_s21[] = { M(sMsg_d75_s21_0), M(sMsg_d75_s21_1), NULL };
static const EntityMsg* const sStep_d75_s22[] = { M(sMsg_d75_s22_0), M(sMsg_d75_s22_1), M(sMsg_d75_s22_2), NULL };
static const EntityMsg* const sStep_d75_s23[] = { M(sMsg_d75_s23_0), NULL };
static const EntityMsg* const sStep_d75_s24[] = { M(sMsg_d75_s24_0), NULL };
static const EntityMsg* const sStep_d75_s25[] = { M(sMsg_d75_s25_0), M(sMsg_d75_s25_1), M(sMsg_d75_s25_2), NULL };
static const EntityMsg* const sStep_d75_s26[] = { M(sMsg_d75_s26_0), M(sMsg_d75_s26_1), NULL };
static const EntityMsg* const sStep_d75_s27[] = { M(sMsg_d75_s27_0), M(sMsg_d75_s27_1), NULL };
static const EntityMsg* const sStep_d75_s28[] = { M(sMsg_d75_s28_0), NULL };
static const EntityMsg* const sStep_d75_s29[] = { M(sMsg_d75_s29_0), NULL };
static const EntityMsg* const sStep_d75_s30[] = { M(sMsg_d75_s30_0), NULL };
static const EntityMsg* const sStep_d75_s31[] = { M(sMsg_d75_s31_0), NULL };
static const EntityMsg* const sStep_d75_s32[] = { M(sMsg_d75_s32_0), M(sMsg_d75_s32_1), NULL };
static const EntityMsg* const sStep_d75_s33[] = { M(sMsg_d75_s33_0), M(sMsg_d75_s33_1), NULL };
static const EntityMsg* const sStep_d75_s34[] = { M(sMsg_d75_s34_0), M(sMsg_d75_s34_1), NULL };
static const EntityMsg* const sStep_d75_s35[] = { M(sMsg_d75_s35_0), M(sMsg_d75_s35_1), NULL };
static const EntityMsg* const sStep_d75_s36[] = { M(sMsg_d75_s36_0), NULL };
static const EntityMsg* const sStep_d75_s37[] = { M(sMsg_d75_s37_0), NULL };
static const EntityMsg* const sStep_d75_s38[] = { M(sMsg_d75_s38_0), M(sMsg_d75_s38_1), M(sMsg_d75_s38_2), M(sMsg_d75_s38_3), NULL };
static const EntityMsg* const sStep_d75_s39[] = { M(sMsg_d75_s39_0), M(sMsg_d75_s39_1), M(sMsg_d75_s39_2), NULL };
static const EntityMsg* const sStep_d75_s40[] = { M(sMsg_d75_s40_0), M(sMsg_d75_s40_1), M(sMsg_d75_s40_2), NULL };
static const EntityMsg* const sStep_d75_s41[] = { M(sMsg_d75_s41_0), NULL };
static const EntityMsg* const sStep_d75_s42[] = { M(sMsg_d75_s42_0), NULL };
static const EntityMsg* const sStep_d75_s43[] = { M(sMsg_d75_s43_0), M(sMsg_d75_s43_1), NULL };
static const EntityMsg* const sStep_d75_s44[] = { M(sMsg_d75_s44_0), M(sMsg_d75_s44_1), M(sMsg_d75_s44_2), NULL };
static const EntityMsg* const sStep_d75_s45[] = { M(sMsg_d75_s45_0), NULL };
static const EntityMsg* const sStep_d75_s46[] = { M(sMsg_d75_s46_0), NULL };
static const EntityMsg* const sStep_d75_s47[] = { M(sMsg_d75_s47_0), M(sMsg_d75_s47_1), M(sMsg_d75_s47_2), NULL };
static const EntityMsg* const sStep_d75_s48[] = { M(sMsg_d75_s48_0), NULL };
static const EntityMsg* const sStep_d75_s49[] = { M(sMsg_d75_s49_0), M(sMsg_d75_s49_1), M(sMsg_d75_s49_2), M(sMsg_d75_s49_3), M(sMsg_d75_s49_4), M(sMsg_d75_s49_5), NULL };
static const EntityMsg* const sStep_d75_s50[] = { M(sMsg_d75_s50_0), NULL };
static const EntityMsg* const sStep_d75_s51[] = { M(sMsg_d75_s51_0), NULL };
static const EntityMsg* const sStep_d75_s52[] = { M(sMsg_d75_s52_0), M(sMsg_d75_s52_1), NULL };
static const EntityMsg* const sStep_d75_s53[] = { M(sMsg_d75_s53_0), M(sMsg_d75_s53_1), M(sMsg_d75_s53_2), NULL };
static const EntityMsg* const sStep_d75_s54[] = { M(sMsg_d75_s54_0), NULL };
static const EntityMsg* const sStep_d75_s55[] = { M(sMsg_d75_s55_0), M(sMsg_d75_s55_1), M(sMsg_d75_s55_2), M(sMsg_d75_s55_3), NULL };
static const EntityMsg* const sStep_d75_s56[] = { M(sMsg_d75_s56_0), NULL };
static const EntityMsg* const sStep_d75_s57[] = { M(sMsg_d75_s57_0), NULL };
static const EntityMsg* const sStep_d75_s58[] = { M(sMsg_d75_s58_0), M(sMsg_d75_s58_1), NULL };
static const EntityMsg* const sStep_d75_s59[] = { M(sMsg_d75_s59_0), NULL };
static const EntityMsg* const sStep_d75_s60[] = { M(sMsg_d75_s60_0), NULL };
static const EntityMsg* const sStep_d75_s61[] = { M(sMsg_d75_s61_0), M(sMsg_d75_s61_1), NULL };
static const EntityMsg* const sStep_d75_s62[] = { M(sMsg_d75_s62_0), M(sMsg_d75_s62_1), NULL };
static const EntityMsg* const sStep_d75_s63[] = { M(sMsg_d75_s63_0), M(sMsg_d75_s63_1), M(sMsg_d75_s63_2), NULL };
static const EntityMsg* const sStep_d75_s64[] = { M(sMsg_d75_s64_0), M(sMsg_d75_s64_1), M(sMsg_d75_s64_2), NULL };
static const EntityMsg* const sStep_d75_s65[] = { M(sMsg_d75_s65_0), M(sMsg_d75_s65_1), NULL };
static const EntityMsg* const sStep_d75_s66[] = { M(sMsg_d75_s66_0), M(sMsg_d75_s66_1), NULL };
static const EntityMsg* const sStep_d75_s67[] = { M(sMsg_d75_s67_0), M(sMsg_d75_s67_1), M(sMsg_d75_s67_2), NULL };
static const EntityMsg* const sStep_d75_s68[] = { M(sMsg_d75_s68_0), M(sMsg_d75_s68_1), M(sMsg_d75_s68_2), M(sMsg_d75_s68_3), NULL };
static const EntityMsg* const sStep_d75_s69[] = { M(sMsg_d75_s69_0), M(sMsg_d75_s69_1), M(sMsg_d75_s69_2), NULL };
static const EntityMsg* const sStep_d75_s70[] = { M(sMsg_d75_s70_0), M(sMsg_d75_s70_1), NULL };
static const EntityMsg* const sStep_d75_s71[] = { M(sMsg_d75_s71_0), NULL };
static const EntityMsg* const sStep_d75_s72[] = { M(sMsg_d75_s72_0), NULL };
static const EntityMsg* const sStep_d75_s73[] = { M(sMsg_d75_s73_0), M(sMsg_d75_s73_1), NULL };
static const EntityMsg* const sStep_d75_s74[] = { M(sMsg_d75_s74_0), M(sMsg_d75_s74_1), NULL };
static const EntityMsg* const sStep_d75_s75[] = { M(sMsg_d75_s75_0), NULL };
static const EntityMsg* const sStep_d75_s76[] = { M(sMsg_d75_s76_0), NULL };
static const EntityMsg* const sStep_d75_s77[] = { M(sMsg_d75_s77_0), M(sMsg_d75_s77_1), NULL };
static const EntityMsg* const sStep_d75_s78[] = { M(sMsg_d75_s78_0), NULL };
static const EntityMsg* const sStep_d75_s79[] = { M(sMsg_d75_s79_0), NULL };
static const EntityMsg* const sStep_d75_s80[] = { M(sMsg_d75_s80_0), M(sMsg_d75_s80_1), NULL };
static const EntityMsg* const sStep_d75_s81[] = { M(sMsg_d75_s81_0), NULL };
static const EntityMsg* const sStep_d75_s82[] = { M(sMsg_d75_s82_0), NULL };
static const EntityMsg* const sStep_d75_s83[] = { M(sMsg_d75_s83_0), M(sMsg_d75_s83_1), M(sMsg_d75_s83_2), M(sMsg_d75_s83_3), NULL };
static const EntityMsg* const sStep_d75_s84[] = { M(sMsg_d75_s84_0), M(sMsg_d75_s84_1), M(sMsg_d75_s84_2), NULL };
static const EntityMsg* const sStep_d75_s85[] = { M(sMsg_d75_s85_0), M(sMsg_d75_s85_1), M(sMsg_d75_s85_2), M(sMsg_d75_s85_3), M(sMsg_d75_s85_4), NULL };
static const EntityMsg* const sStep_d75_s86[] = { M(sMsg_d75_s86_0), M(sMsg_d75_s86_1), M(sMsg_d75_s86_2), M(sMsg_d75_s86_3), NULL };
static const EntityMsg* const sStep_d75_s87[] = { M(sMsg_d75_s87_0), M(sMsg_d75_s87_1), NULL };
static const EntityMsg* const sStep_d75_s88[] = { M(sMsg_d75_s88_0), NULL };
static const EntityMsg* const sStep_d75_s89[] = { M(sMsg_d75_s89_0), NULL };
static const EntityMsg* const sStep_d75_s90[] = { M(sMsg_d75_s90_0), M(sMsg_d75_s90_1), NULL };
static const EntityMsg* const sStep_d75_s91[] = { M(sMsg_d75_s91_0), NULL };
static const EntityMsg* const sStep_d75_s92[] = { M(sMsg_d75_s92_0), M(sMsg_d75_s92_1), M(sMsg_d75_s92_2), NULL };
static const EntityMsg* const sStep_d75_s93[] = { M(sMsg_d75_s93_0), M(sMsg_d75_s93_1), NULL };
static const EntityMsg* const sStep_d75_s94[] = { M(sMsg_d75_s94_0), NULL };
static const EntityMsg* const sStep_d75_s95[] = { M(sMsg_d75_s95_0), M(sMsg_d75_s95_1), M(sMsg_d75_s95_2), NULL };
static const EntityMsg* const sStep_d75_s96[] = { M(sMsg_d75_s96_0), NULL };
static const EntityMsg* const sStep_d75_s97[] = { M(sMsg_d75_s97_0), NULL };
static const EntityMsg* const sStep_d75_s98[] = { M(sMsg_d75_s98_0), NULL };
static const EntityMsg* const sStep_d75_s99[] = { M(sMsg_d75_s99_0), NULL };
static const EntityMsg* const sStep_d75_s100[] = { M(sMsg_d75_s100_0), M(sMsg_d75_s100_1), M(sMsg_d75_s100_2), NULL };
static const EntityMsg* const sStep_d76_s0[] = { M(sMsg_d76_s0_0), M(sMsg_d76_s0_1), M(sMsg_d76_s0_2), NULL };
static const EntityMsg* const sStep_d76_s1[] = { M(sMsg_d76_s1_0), M(sMsg_d76_s1_1), NULL };
static const EntityMsg* const sStep_d76_s2[] = { M(sMsg_d76_s2_0), NULL };
static const EntityMsg* const sStep_d76_s3[] = { M(sMsg_d76_s3_0), NULL };
static const EntityMsg* const sStep_d76_s4[] = { M(sMsg_d76_s4_0), NULL };
static const EntityMsg* const sStep_d76_s5[] = { M(sMsg_d76_s5_0), NULL };
static const EntityMsg* const sStep_d76_s6[] = { M(sMsg_d76_s6_0), NULL };
static const EntityMsg* const sStep_d76_s7[] = { M(sMsg_d76_s7_0), NULL };
static const EntityMsg* const sStep_d76_s8[] = { M(sMsg_d76_s8_0), NULL };
static const EntityMsg* const sStep_d76_s9[] = { M(sMsg_d76_s9_0), NULL };
static const EntityMsg* const sStep_d76_s10[] = { M(sMsg_d76_s10_0), NULL };
static const EntityMsg* const sStep_d76_s11[] = { M(sMsg_d76_s11_0), NULL };
static const EntityMsg* const sStep_d76_s12[] = { M(sMsg_d76_s12_0), NULL };
static const EntityMsg* const sStep_d76_s13[] = { M(sMsg_d76_s13_0), NULL };
static const EntityMsg* const sStep_d76_s14[] = { M(sMsg_d76_s14_0), M(sMsg_d76_s14_1), NULL };
static const EntityMsg* const sStep_d76_s15[] = { M(sMsg_d76_s15_0), M(sMsg_d76_s15_1), NULL };
static const EntityMsg* const sStep_d76_s16[] = { M(sMsg_d76_s16_0), NULL };
static const EntityMsg* const sStep_d76_s17[] = { M(sMsg_d76_s17_0), NULL };
static const EntityMsg* const sStep_d76_s18[] = { M(sMsg_d76_s18_0), NULL };
static const EntityMsg* const sStep_d76_s19[] = { M(sMsg_d76_s19_0), M(sMsg_d76_s19_1), NULL };
static const EntityMsg* const sStep_d76_s20[] = { M(sMsg_d76_s20_0), NULL };
static const EntityMsg* const sStep_d76_s21[] = { M(sMsg_d76_s21_0), NULL };
static const EntityMsg* const sStep_d77_s0[] = { M(sMsg_d77_s0_0), NULL };
static const EntityMsg* const sStep_d77_s1[] = { M(sMsg_d77_s1_0), NULL };
static const EntityMsg* const sStep_d77_s2[] = { M(sMsg_d77_s2_0), NULL };
static const EntityMsg* const sStep_d77_s3[] = { M(sMsg_d77_s3_0), NULL };
static const EntityMsg* const sStep_d77_s4[] = { M(sMsg_d77_s4_0), M(sMsg_d77_s4_1), M(sMsg_d77_s4_2), M(sMsg_d77_s4_3), NULL };
static const EntityMsg* const sStep_d77_s5[] = { M(sMsg_d77_s5_0), M(sMsg_d77_s5_1), M(sMsg_d77_s5_2), M(sMsg_d77_s5_3), M(sMsg_d77_s5_4), NULL };
static const EntityMsg* const sStep_d77_s6[] = { M(sMsg_d77_s6_0), M(sMsg_d77_s6_1), NULL };
static const EntityMsg* const sStep_d77_s7[] = { M(sMsg_d77_s7_0), M(sMsg_d77_s7_1), NULL };
static const EntityMsg* const sStep_d77_s8[] = { M(sMsg_d77_s8_0), M(sMsg_d77_s8_1), NULL };
static const EntityMsg* const sStep_d77_s9[] = { M(sMsg_d77_s9_0), NULL };
static const EntityMsg* const sStep_d77_s10[] = { M(sMsg_d77_s10_0), NULL };
static const EntityMsg* const sStep_d77_s11[] = { M(sMsg_d77_s11_0), NULL };
static const EntityMsg* const sStep_d77_s12[] = { M(sMsg_d77_s12_0), M(sMsg_d77_s12_1), M(sMsg_d77_s12_2), NULL };
static const EntityMsg* const sStep_d77_s13[] = { M(sMsg_d77_s13_0), M(sMsg_d77_s13_1), M(sMsg_d77_s13_2), M(sMsg_d77_s13_3), NULL };
static const EntityMsg* const sStep_d77_s14[] = { M(sMsg_d77_s14_0), M(sMsg_d77_s14_1), M(sMsg_d77_s14_2), NULL };
static const EntityMsg* const sStep_d77_s15[] = { M(sMsg_d77_s15_0), M(sMsg_d77_s15_1), M(sMsg_d77_s15_2), NULL };
static const EntityMsg* const sStep_d77_s16[] = { M(sMsg_d77_s16_0), M(sMsg_d77_s16_1), M(sMsg_d77_s16_2), NULL };
static const EntityMsg* const sStep_d77_s17[] = { M(sMsg_d77_s17_0), NULL };
static const EntityMsg* const sStep_d77_s18[] = { M(sMsg_d77_s18_0), NULL };
static const EntityMsg* const sStep_d77_s19[] = { M(sMsg_d77_s19_0), M(sMsg_d77_s19_1), NULL };
static const EntityMsg* const sStep_d77_s20[] = { M(sMsg_d77_s20_0), M(sMsg_d77_s20_1), NULL };
static const EntityMsg* const sStep_d77_s21[] = { M(sMsg_d77_s21_0), NULL };
static const EntityMsg* const sStep_d77_s22[] = { M(sMsg_d77_s22_0), NULL };
static const EntityMsg* const sStep_d77_s23[] = { M(sMsg_d77_s23_0), NULL };
static const EntityMsg* const sStep_d77_s24[] = { M(sMsg_d77_s24_0), M(sMsg_d77_s24_1), M(sMsg_d77_s24_2), M(sMsg_d77_s24_3), NULL };
static const EntityMsg* const sStep_d77_s25[] = { M(sMsg_d77_s25_0), M(sMsg_d77_s25_1), M(sMsg_d77_s25_2), NULL };
static const EntityMsg* const sStep_d77_s26[] = { M(sMsg_d77_s26_0), M(sMsg_d77_s26_1), NULL };
static const EntityMsg* const sStep_d77_s27[] = { M(sMsg_d77_s27_0), NULL };
static const EntityMsg* const sStep_d77_s28[] = { M(sMsg_d77_s28_0), NULL };
static const EntityMsg* const sStep_d77_s29[] = { M(sMsg_d77_s29_0), M(sMsg_d77_s29_1), M(sMsg_d77_s29_2), NULL };
static const EntityMsg* const sStep_d77_s30[] = { M(sMsg_d77_s30_0), M(sMsg_d77_s30_1), NULL };
static const EntityMsg* const sStep_d77_s31[] = { M(sMsg_d77_s31_0), M(sMsg_d77_s31_1), M(sMsg_d77_s31_2), NULL };
static const EntityMsg* const sStep_d77_s32[] = { M(sMsg_d77_s32_0), NULL };
static const EntityMsg* const sStep_d77_s33[] = { M(sMsg_d77_s33_0), NULL };
static const EntityMsg* const sStep_d77_s34[] = { M(sMsg_d77_s34_0), M(sMsg_d77_s34_1), NULL };
static const EntityMsg* const sStep_d77_s35[] = { M(sMsg_d77_s35_0), M(sMsg_d77_s35_1), M(sMsg_d77_s35_2), NULL };
static const EntityMsg* const sStep_d78_s0[] = { M(sMsg_d78_s0_0), NULL };
static const EntityMsg* const sStep_d78_s1[] = { M(sMsg_d78_s1_0), NULL };
static const EntityMsg* const sStep_d78_s2[] = { M(sMsg_d78_s2_0), NULL };
static const EntityMsg* const sStep_d78_s3[] = { M(sMsg_d78_s3_0), M(sMsg_d78_s3_1), M(sMsg_d78_s3_2), NULL };
static const EntityMsg* const sStep_d78_s4[] = { M(sMsg_d78_s4_0), NULL };
static const EntityMsg* const sStep_d78_s5[] = { M(sMsg_d78_s5_0), NULL };
static const EntityMsg* const sStep_d79_s0[] = { M(sMsg_d79_s0_0), NULL };
static const EntityMsg* const sStep_d79_s1[] = { M(sMsg_d79_s1_0), M(sMsg_d79_s1_1), M(sMsg_d79_s1_2), NULL };
static const EntityMsg* const sStep_d79_s2[] = { M(sMsg_d79_s2_0), NULL };
static const EntityMsg* const sStep_d79_s3[] = { M(sMsg_d79_s3_0), NULL };
static const EntityMsg* const sStep_d79_s4[] = { M(sMsg_d79_s4_0), NULL };
static const EntityMsg* const sStep_d79_s5[] = { M(sMsg_d79_s5_0), M(sMsg_d79_s5_1), NULL };
static const EntityMsg* const sStep_d79_s6[] = { M(sMsg_d79_s6_0), M(sMsg_d79_s6_1), NULL };
static const EntityMsg* const sStep_d79_s7[] = { M(sMsg_d79_s7_0), NULL };
static const EntityMsg* const sStep_d79_s8[] = { M(sMsg_d79_s8_0), NULL };
static const EntityMsg* const sStep_d80_s0[] = { M(sMsg_d80_s0_0), NULL };
static const EntityMsg* const sStep_d80_s1[] = { M(sMsg_d80_s1_0), M(sMsg_d80_s1_1), M(sMsg_d80_s1_2), NULL };
static const EntityMsg* const sStep_d80_s2[] = { M(sMsg_d80_s2_0), NULL };
static const EntityMsg* const sStep_d80_s3[] = { M(sMsg_d80_s3_0), NULL };
static const EntityMsg* const sStep_d80_s4[] = { M(sMsg_d80_s4_0), NULL };
static const EntityMsg* const sStep_d80_s5[] = { M(sMsg_d80_s5_0), M(sMsg_d80_s5_1), NULL };
static const EntityMsg* const sStep_d80_s6[] = { M(sMsg_d80_s6_0), M(sMsg_d80_s6_1), NULL };
static const EntityMsg* const sStep_d80_s7[] = { M(sMsg_d80_s7_0), NULL };
static const EntityMsg* const sStep_d80_s8[] = { M(sMsg_d80_s8_0), NULL };
static const EntityMsg* const sStep_d81_s0[] = { M(sMsg_d81_s0_0), NULL };
static const EntityMsg* const sStep_d81_s1[] = { M(sMsg_d81_s1_0), M(sMsg_d81_s1_1), NULL };
static const EntityMsg* const sStep_d81_s2[] = { M(sMsg_d81_s2_0), M(sMsg_d81_s2_1), M(sMsg_d81_s2_2), NULL };
static const EntityMsg* const sStep_d81_s3[] = { M(sMsg_d81_s3_0), NULL };
static const EntityMsg* const sStep_d81_s4[] = { M(sMsg_d81_s4_0), NULL };
static const EntityMsg* const sStep_d81_s5[] = { M(sMsg_d81_s5_0), M(sMsg_d81_s5_1), M(sMsg_d81_s5_2), NULL };
static const EntityMsg* const sStep_d81_s6[] = { M(sMsg_d81_s6_0), NULL };
static const EntityMsg* const sStep_d81_s7[] = { M(sMsg_d81_s7_0), NULL };
static const EntityMsg* const sStep_d81_s8[] = { M(sMsg_d81_s8_0), NULL };
static const EntityMsg* const sStep_d81_s9[] = { M(sMsg_d81_s9_0), M(sMsg_d81_s9_1), M(sMsg_d81_s9_2), NULL };
static const EntityMsg* const sStep_d81_s10[] = { M(sMsg_d81_s10_0), NULL };
static const EntityMsg* const sStep_d81_s11[] = { M(sMsg_d81_s11_0), NULL };
static const EntityMsg* const sStep_d81_s12[] = { M(sMsg_d81_s12_0), M(sMsg_d81_s12_1), M(sMsg_d81_s12_2), NULL };
static const EntityMsg* const sStep_d81_s13[] = { M(sMsg_d81_s13_0), NULL };
static const EntityMsg* const sStep_d81_s14[] = { M(sMsg_d81_s14_0), NULL };
static const EntityMsg* const sStep_d81_s15[] = { M(sMsg_d81_s15_0), M(sMsg_d81_s15_1), M(sMsg_d81_s15_2), NULL };
static const EntityMsg* const sStep_d81_s16[] = { M(sMsg_d81_s16_0), M(sMsg_d81_s16_1), NULL };
static const EntityMsg* const sStep_d81_s17[] = { M(sMsg_d81_s17_0), NULL };
static const EntityMsg* const sStep_d81_s18[] = { M(sMsg_d81_s18_0), NULL };
static const EntityMsg* const sStep_d81_s19[] = { M(sMsg_d81_s19_0), NULL };
static const EntityMsg* const sStep_d82_s0[] = { M(sMsg_d82_s0_0), NULL };
static const EntityMsg* const sStep_d82_s1[] = { M(sMsg_d82_s1_0), NULL };
static const EntityMsg* const sStep_d82_s2[] = { M(sMsg_d82_s2_0), M(sMsg_d82_s2_1), NULL };
static const EntityMsg* const sStep_d82_s3[] = { M(sMsg_d82_s3_0), M(sMsg_d82_s3_1), M(sMsg_d82_s3_2), NULL };
static const EntityMsg* const sStep_d82_s4[] = { M(sMsg_d82_s4_0), NULL };
static const EntityMsg* const sStep_d82_s5[] = { M(sMsg_d82_s5_0), NULL };
static const EntityMsg* const sStep_d82_s6[] = { M(sMsg_d82_s6_0), M(sMsg_d82_s6_1), M(sMsg_d82_s6_2), NULL };
static const EntityMsg* const sStep_d82_s7[] = { M(sMsg_d82_s7_0), NULL };
static const EntityMsg* const sStep_d82_s8[] = { M(sMsg_d82_s8_0), NULL };
static const EntityMsg* const sStep_d82_s9[] = { M(sMsg_d82_s9_0), NULL };
static const EntityMsg* const sStep_d82_s10[] = { M(sMsg_d82_s10_0), M(sMsg_d82_s10_1), M(sMsg_d82_s10_2), NULL };
static const EntityMsg* const sStep_d82_s11[] = { M(sMsg_d82_s11_0), NULL };
static const EntityMsg* const sStep_d82_s12[] = { M(sMsg_d82_s12_0), NULL };
static const EntityMsg* const sStep_d82_s13[] = { M(sMsg_d82_s13_0), M(sMsg_d82_s13_1), M(sMsg_d82_s13_2), NULL };
static const EntityMsg* const sStep_d82_s14[] = { M(sMsg_d82_s14_0), NULL };
static const EntityMsg* const sStep_d82_s15[] = { M(sMsg_d82_s15_0), NULL };
static const EntityMsg* const sStep_d82_s16[] = { M(sMsg_d82_s16_0), M(sMsg_d82_s16_1), M(sMsg_d82_s16_2), NULL };
static const EntityMsg* const sStep_d82_s17[] = { M(sMsg_d82_s17_0), M(sMsg_d82_s17_1), NULL };
static const EntityMsg* const sStep_d82_s18[] = { M(sMsg_d82_s18_0), NULL };
static const EntityMsg* const sStep_d82_s19[] = { M(sMsg_d82_s19_0), NULL };
static const EntityMsg* const sStep_d82_s20[] = { M(sMsg_d82_s20_0), NULL };
static const EntityMsg* const sStep_d83_s0[] = { M(sMsg_d83_s0_0), NULL };
static const EntityMsg* const sStep_d83_s1[] = { M(sMsg_d83_s1_0), M(sMsg_d83_s1_1), NULL };
static const EntityMsg* const sStep_d83_s2[] = { M(sMsg_d83_s2_0), M(sMsg_d83_s2_1), M(sMsg_d83_s2_2), NULL };
static const EntityMsg* const sStep_d83_s3[] = { M(sMsg_d83_s3_0), NULL };
static const EntityMsg* const sStep_d83_s4[] = { M(sMsg_d83_s4_0), NULL };
static const EntityMsg* const sStep_d83_s5[] = { M(sMsg_d83_s5_0), M(sMsg_d83_s5_1), M(sMsg_d83_s5_2), NULL };
static const EntityMsg* const sStep_d83_s6[] = { M(sMsg_d83_s6_0), NULL };
static const EntityMsg* const sStep_d83_s7[] = { M(sMsg_d83_s7_0), NULL };
static const EntityMsg* const sStep_d83_s8[] = { M(sMsg_d83_s8_0), NULL };
static const EntityMsg* const sStep_d83_s9[] = { M(sMsg_d83_s9_0), M(sMsg_d83_s9_1), M(sMsg_d83_s9_2), NULL };
static const EntityMsg* const sStep_d83_s10[] = { M(sMsg_d83_s10_0), NULL };
static const EntityMsg* const sStep_d83_s11[] = { M(sMsg_d83_s11_0), NULL };
static const EntityMsg* const sStep_d83_s12[] = { M(sMsg_d83_s12_0), M(sMsg_d83_s12_1), M(sMsg_d83_s12_2), NULL };
static const EntityMsg* const sStep_d83_s13[] = { M(sMsg_d83_s13_0), NULL };
static const EntityMsg* const sStep_d83_s14[] = { M(sMsg_d83_s14_0), NULL };
static const EntityMsg* const sStep_d83_s15[] = { M(sMsg_d83_s15_0), M(sMsg_d83_s15_1), M(sMsg_d83_s15_2), NULL };
static const EntityMsg* const sStep_d83_s16[] = { M(sMsg_d83_s16_0), M(sMsg_d83_s16_1), NULL };
static const EntityMsg* const sStep_d83_s17[] = { M(sMsg_d83_s17_0), NULL };
static const EntityMsg* const sStep_d83_s18[] = { M(sMsg_d83_s18_0), NULL };
static const EntityMsg* const sStep_d83_s19[] = { M(sMsg_d83_s19_0), NULL };
static const EntityMsg* const sStep_d84_s0[] = { M(sMsg_d84_s0_0), NULL };
static const EntityMsg* const sStep_d84_s1[] = { M(sMsg_d84_s1_0), NULL };
static const EntityMsg* const sStep_d84_s2[] = { M(sMsg_d84_s2_0), M(sMsg_d84_s2_1), NULL };
static const EntityMsg* const sStep_d84_s3[] = { M(sMsg_d84_s3_0), M(sMsg_d84_s3_1), M(sMsg_d84_s3_2), NULL };
static const EntityMsg* const sStep_d84_s4[] = { M(sMsg_d84_s4_0), NULL };
static const EntityMsg* const sStep_d84_s5[] = { M(sMsg_d84_s5_0), NULL };
static const EntityMsg* const sStep_d84_s6[] = { M(sMsg_d84_s6_0), M(sMsg_d84_s6_1), M(sMsg_d84_s6_2), NULL };
static const EntityMsg* const sStep_d84_s7[] = { M(sMsg_d84_s7_0), NULL };
static const EntityMsg* const sStep_d84_s8[] = { M(sMsg_d84_s8_0), NULL };
static const EntityMsg* const sStep_d84_s9[] = { M(sMsg_d84_s9_0), NULL };
static const EntityMsg* const sStep_d84_s10[] = { M(sMsg_d84_s10_0), M(sMsg_d84_s10_1), M(sMsg_d84_s10_2), NULL };
static const EntityMsg* const sStep_d84_s11[] = { M(sMsg_d84_s11_0), NULL };
static const EntityMsg* const sStep_d84_s12[] = { M(sMsg_d84_s12_0), NULL };
static const EntityMsg* const sStep_d84_s13[] = { M(sMsg_d84_s13_0), M(sMsg_d84_s13_1), M(sMsg_d84_s13_2), NULL };
static const EntityMsg* const sStep_d84_s14[] = { M(sMsg_d84_s14_0), NULL };
static const EntityMsg* const sStep_d84_s15[] = { M(sMsg_d84_s15_0), NULL };
static const EntityMsg* const sStep_d84_s16[] = { M(sMsg_d84_s16_0), M(sMsg_d84_s16_1), M(sMsg_d84_s16_2), NULL };
static const EntityMsg* const sStep_d84_s17[] = { M(sMsg_d84_s17_0), M(sMsg_d84_s17_1), NULL };
static const EntityMsg* const sStep_d84_s18[] = { M(sMsg_d84_s18_0), NULL };
static const EntityMsg* const sStep_d84_s19[] = { M(sMsg_d84_s19_0), NULL };
static const EntityMsg* const sStep_d84_s20[] = { M(sMsg_d84_s20_0), NULL };
static const EntityMsg* const sStep_d85_s0[] = { M(sMsg_d85_s0_0), NULL };
static const EntityMsg* const sStep_d85_s1[] = { M(sMsg_d85_s1_0), M(sMsg_d85_s1_1), M(sMsg_d85_s1_2), NULL };
static const EntityMsg* const sStep_d85_s2[] = { M(sMsg_d85_s2_0), NULL };
static const EntityMsg* const sStep_d85_s3[] = { M(sMsg_d85_s3_0), NULL };
static const EntityMsg* const sStep_d85_s4[] = { M(sMsg_d85_s4_0), NULL };
static const EntityMsg* const sStep_d85_s5[] = { M(sMsg_d85_s5_0), M(sMsg_d85_s5_1), NULL };
static const EntityMsg* const sStep_d85_s6[] = { M(sMsg_d85_s6_0), M(sMsg_d85_s6_1), NULL };
static const EntityMsg* const sStep_d85_s7[] = { M(sMsg_d85_s7_0), M(sMsg_d85_s7_1), NULL };
static const EntityMsg* const sStep_d85_s8[] = { M(sMsg_d85_s8_0), M(sMsg_d85_s8_1), M(sMsg_d85_s8_2), NULL };
static const EntityMsg* const sStep_d85_s9[] = { M(sMsg_d85_s9_0), NULL };
static const EntityMsg* const sStep_d85_s10[] = { M(sMsg_d85_s10_0), M(sMsg_d85_s10_1), M(sMsg_d85_s10_2), M(sMsg_d85_s10_3), NULL };
static const EntityMsg* const sStep_d85_s11[] = { M(sMsg_d85_s11_0), M(sMsg_d85_s11_1), NULL };
static const EntityMsg* const sStep_d85_s12[] = { M(sMsg_d85_s12_0), M(sMsg_d85_s12_1), M(sMsg_d85_s12_2), NULL };
static const EntityMsg* const sStep_d85_s13[] = { M(sMsg_d85_s13_0), NULL };
static const EntityMsg* const sStep_d85_s14[] = { M(sMsg_d85_s14_0), NULL };
static const EntityMsg* const sStep_d85_s15[] = { M(sMsg_d85_s15_0), NULL };
static const EntityMsg* const sStep_d85_s16[] = { M(sMsg_d85_s16_0), NULL };
static const EntityMsg* const sStep_d86_s0[] = { M(sMsg_d86_s0_0), NULL };
static const EntityMsg* const sStep_d86_s1[] = { M(sMsg_d86_s1_0), M(sMsg_d86_s1_1), M(sMsg_d86_s1_2), NULL };
static const EntityMsg* const sStep_d86_s2[] = { M(sMsg_d86_s2_0), NULL };
static const EntityMsg* const sStep_d86_s3[] = { M(sMsg_d86_s3_0), NULL };
static const EntityMsg* const sStep_d86_s4[] = { M(sMsg_d86_s4_0), NULL };
static const EntityMsg* const sStep_d86_s5[] = { M(sMsg_d86_s5_0), M(sMsg_d86_s5_1), NULL };
static const EntityMsg* const sStep_d86_s6[] = { M(sMsg_d86_s6_0), M(sMsg_d86_s6_1), M(sMsg_d86_s6_2), M(sMsg_d86_s6_3), NULL };
static const EntityMsg* const sStep_d86_s7[] = { M(sMsg_d86_s7_0), NULL };
static const EntityMsg* const sStep_d86_s8[] = { M(sMsg_d86_s8_0), M(sMsg_d86_s8_1), NULL };
static const EntityMsg* const sStep_d86_s9[] = { M(sMsg_d86_s9_0), NULL };
static const EntityMsg* const sStep_d86_s10[] = { M(sMsg_d86_s10_0), NULL };
static const EntityMsg* const sStep_d86_s11[] = { M(sMsg_d86_s11_0), NULL };
static const EntityMsg* const sStep_d86_s12[] = { M(sMsg_d86_s12_0), NULL };
static const EntityMsg* const sStep_d87_s0[] = { M(sMsg_d87_s0_0), NULL };
static const EntityMsg* const sStep_d87_s1[] = { M(sMsg_d87_s1_0), M(sMsg_d87_s1_1), M(sMsg_d87_s1_2), NULL };
static const EntityMsg* const sStep_d87_s2[] = { M(sMsg_d87_s2_0), NULL };
static const EntityMsg* const sStep_d87_s3[] = { M(sMsg_d87_s3_0), NULL };
static const EntityMsg* const sStep_d87_s4[] = { M(sMsg_d87_s4_0), NULL };
static const EntityMsg* const sStep_d87_s5[] = { M(sMsg_d87_s5_0), NULL };
static const EntityMsg* const sStep_d88_s0[] = { M(sMsg_d88_s0_0), M(sMsg_d88_s0_1), NULL };
static const EntityMsg* const sStep_d88_s1[] = { M(sMsg_d88_s1_0), M(sMsg_d88_s1_1), NULL };
static const EntityMsg* const sStep_d88_s2[] = { M(sMsg_d88_s2_0), M(sMsg_d88_s2_1), NULL };
static const EntityMsg* const sStep_d88_s3[] = { M(sMsg_d88_s3_0), M(sMsg_d88_s3_1), NULL };
static const EntityMsg* const sStep_d88_s4[] = { M(sMsg_d88_s4_0), NULL };
static const EntityMsg* const sStep_d88_s5[] = { M(sMsg_d88_s5_0), NULL };
static const EntityMsg* const sStep_d88_s6[] = { M(sMsg_d88_s6_0), NULL };
static const EntityMsg* const sStep_d89_s0[] = { M(sMsg_d89_s0_0), M(sMsg_d89_s0_1), NULL };
static const EntityMsg* const sStep_d89_s1[] = { M(sMsg_d89_s1_0), M(sMsg_d89_s1_1), NULL };
static const EntityMsg* const sStep_d89_s2[] = { M(sMsg_d89_s2_0), M(sMsg_d89_s2_1), NULL };
static const EntityMsg* const sStep_d89_s3[] = { M(sMsg_d89_s3_0), M(sMsg_d89_s3_1), NULL };
static const EntityMsg* const sStep_d89_s4[] = { M(sMsg_d89_s4_0), NULL };
static const EntityMsg* const sStep_d89_s5[] = { M(sMsg_d89_s5_0), NULL };
static const EntityMsg* const sStep_d90_s0[] = { M(sMsg_d90_s0_0), M(sMsg_d90_s0_1), M(sMsg_d90_s0_2), M(sMsg_d90_s0_3), NULL };
static const EntityMsg* const sStep_d90_s1[] = { M(sMsg_d90_s1_0), M(sMsg_d90_s1_1), M(sMsg_d90_s1_2), NULL };
static const EntityMsg* const sStep_d90_s2[] = { M(sMsg_d90_s2_0), M(sMsg_d90_s2_1), NULL };
static const EntityMsg* const sStep_d90_s3[] = { M(sMsg_d90_s3_0), NULL };
static const EntityMsg* const sStep_d90_s4[] = { M(sMsg_d90_s4_0), M(sMsg_d90_s4_1), M(sMsg_d90_s4_2), NULL };
static const EntityMsg* const sStep_d90_s5[] = { M(sMsg_d90_s5_0), NULL };
static const EntityMsg* const sStep_d90_s6[] = { M(sMsg_d90_s6_0), NULL };
static const EntityMsg* const sStep_d90_s7[] = { M(sMsg_d90_s7_0), M(sMsg_d90_s7_1), M(sMsg_d90_s7_2), NULL };
static const EntityMsg* const sStep_d90_s8[] = { M(sMsg_d90_s8_0), M(sMsg_d90_s8_1), M(sMsg_d90_s8_2), M(sMsg_d90_s8_3), NULL };
static const EntityMsg* const sStep_d90_s9[] = { M(sMsg_d90_s9_0), M(sMsg_d90_s9_1), M(sMsg_d90_s9_2), M(sMsg_d90_s9_3), NULL };
static const EntityMsg* const sStep_d90_s10[] = { M(sMsg_d90_s10_0), M(sMsg_d90_s10_1), NULL };
static const EntityMsg* const sStep_d90_s11[] = { M(sMsg_d90_s11_0), NULL };
static const EntityMsg* const sStep_d90_s12[] = { M(sMsg_d90_s12_0), M(sMsg_d90_s12_1), M(sMsg_d90_s12_2), NULL };
static const EntityMsg* const sStep_d90_s13[] = { M(sMsg_d90_s13_0), M(sMsg_d90_s13_1), NULL };
static const EntityMsg* const sStep_d90_s14[] = { M(sMsg_d90_s14_0), M(sMsg_d90_s14_1), NULL };
static const EntityMsg* const sStep_d90_s15[] = { M(sMsg_d90_s15_0), M(sMsg_d90_s15_1), M(sMsg_d90_s15_2), M(sMsg_d90_s15_3), M(sMsg_d90_s15_4), M(sMsg_d90_s15_5), NULL };
static const EntityMsg* const sStep_d90_s16[] = { M(sMsg_d90_s16_0), M(sMsg_d90_s16_1), M(sMsg_d90_s16_2), M(sMsg_d90_s16_3), M(sMsg_d90_s16_4), NULL };
static const EntityMsg* const sStep_d90_s17[] = { M(sMsg_d90_s17_0), M(sMsg_d90_s17_1), NULL };
static const EntityMsg* const sStep_d90_s18[] = { M(sMsg_d90_s18_0), NULL };
static const EntityMsg* const sStep_d90_s19[] = { M(sMsg_d90_s19_0), NULL };
static const EntityMsg* const sStep_d90_s20[] = { M(sMsg_d90_s20_0), NULL };
static const EntityMsg* const sStep_d90_s21[] = { M(sMsg_d90_s21_0), NULL };
static const EntityMsg* const sStep_d90_s22[] = { M(sMsg_d90_s22_0), NULL };
static const EntityMsg* const sStep_d90_s23[] = { M(sMsg_d90_s23_0), NULL };
static const EntityMsg* const sStep_d90_s24[] = { M(sMsg_d90_s24_0), NULL };
static const EntityMsg* const sStep_d90_s25[] = { M(sMsg_d90_s25_0), NULL };
static const EntityMsg* const sStep_d90_s26[] = { M(sMsg_d90_s26_0), NULL };
static const EntityMsg* const sStep_d90_s27[] = { M(sMsg_d90_s27_0), NULL };
static const EntityMsg* const sStep_d90_s28[] = { M(sMsg_d90_s28_0), NULL };
static const EntityMsg* const sStep_d90_s29[] = { M(sMsg_d90_s29_0), NULL };
static const EntityMsg* const sStep_d90_s30[] = { M(sMsg_d90_s30_0), M(sMsg_d90_s30_1), M(sMsg_d90_s30_2), NULL };
static const EntityMsg* const sStep_d90_s31[] = { M(sMsg_d90_s31_0), M(sMsg_d90_s31_1), M(sMsg_d90_s31_2), NULL };
static const EntityMsg* const sStep_d90_s32[] = { M(sMsg_d90_s32_0), NULL };
static const EntityMsg* const sStep_d90_s33[] = { M(sMsg_d90_s33_0), M(sMsg_d90_s33_1), M(sMsg_d90_s33_2), NULL };
static const EntityMsg* const sStep_d90_s34[] = { M(sMsg_d90_s34_0), M(sMsg_d90_s34_1), NULL };
static const EntityMsg* const sStep_d90_s35[] = { M(sMsg_d90_s35_0), NULL };
static const EntityMsg* const sStep_d90_s36[] = { M(sMsg_d90_s36_0), NULL };
static const EntityMsg* const sStep_d90_s37[] = { M(sMsg_d90_s37_0), M(sMsg_d90_s37_1), M(sMsg_d90_s37_2), NULL };
static const EntityMsg* const sStep_d90_s38[] = { M(sMsg_d90_s38_0), NULL };
static const EntityMsg* const sStep_d90_s39[] = { M(sMsg_d90_s39_0), NULL };
static const EntityMsg* const sStep_d90_s40[] = { M(sMsg_d90_s40_0), M(sMsg_d90_s40_1), M(sMsg_d90_s40_2), M(sMsg_d90_s40_3), NULL };
static const EntityMsg* const sStep_d90_s41[] = { M(sMsg_d90_s41_0), M(sMsg_d90_s41_1), M(sMsg_d90_s41_2), NULL };
static const EntityMsg* const sStep_d90_s42[] = { M(sMsg_d90_s42_0), NULL };
static const EntityMsg* const sStep_d90_s43[] = { M(sMsg_d90_s43_0), NULL };
static const EntityMsg* const sStep_d90_s44[] = { M(sMsg_d90_s44_0), M(sMsg_d90_s44_1), M(sMsg_d90_s44_2), NULL };
static const EntityMsg* const sStep_d90_s45[] = { M(sMsg_d90_s45_0), NULL };
static const EntityMsg* const sStep_d91_s0[] = { M(sMsg_d91_s0_0), M(sMsg_d91_s0_1), M(sMsg_d91_s0_2), NULL };
static const EntityMsg* const sStep_d91_s1[] = { M(sMsg_d91_s1_0), M(sMsg_d91_s1_1), NULL };
static const EntityMsg* const sStep_d91_s2[] = { M(sMsg_d91_s2_0), M(sMsg_d91_s2_1), NULL };
static const EntityMsg* const sStep_d91_s3[] = { M(sMsg_d91_s3_0), NULL };
static const EntityMsg* const sStep_d91_s4[] = { M(sMsg_d91_s4_0), M(sMsg_d91_s4_1), M(sMsg_d91_s4_2), NULL };
static const EntityMsg* const sStep_d91_s5[] = { M(sMsg_d91_s5_0), NULL };
static const EntityMsg* const sStep_d91_s6[] = { M(sMsg_d91_s6_0), NULL };
static const EntityMsg* const sStep_d91_s7[] = { M(sMsg_d91_s7_0), M(sMsg_d91_s7_1), M(sMsg_d91_s7_2), NULL };
static const EntityMsg* const sStep_d91_s8[] = { M(sMsg_d91_s8_0), M(sMsg_d91_s8_1), M(sMsg_d91_s8_2), M(sMsg_d91_s8_3), NULL };
static const EntityMsg* const sStep_d91_s9[] = { M(sMsg_d91_s9_0), M(sMsg_d91_s9_1), M(sMsg_d91_s9_2), NULL };
static const EntityMsg* const sStep_d91_s10[] = { M(sMsg_d91_s10_0), M(sMsg_d91_s10_1), NULL };
static const EntityMsg* const sStep_d91_s11[] = { M(sMsg_d91_s11_0), NULL };
static const EntityMsg* const sStep_d91_s12[] = { M(sMsg_d91_s12_0), M(sMsg_d91_s12_1), M(sMsg_d91_s12_2), NULL };
static const EntityMsg* const sStep_d91_s13[] = { M(sMsg_d91_s13_0), M(sMsg_d91_s13_1), NULL };
static const EntityMsg* const sStep_d91_s14[] = { M(sMsg_d91_s14_0), M(sMsg_d91_s14_1), NULL };
static const EntityMsg* const sStep_d91_s15[] = { M(sMsg_d91_s15_0), M(sMsg_d91_s15_1), M(sMsg_d91_s15_2), M(sMsg_d91_s15_3), M(sMsg_d91_s15_4), NULL };
static const EntityMsg* const sStep_d91_s16[] = { M(sMsg_d91_s16_0), M(sMsg_d91_s16_1), M(sMsg_d91_s16_2), M(sMsg_d91_s16_3), NULL };
static const EntityMsg* const sStep_d91_s17[] = { M(sMsg_d91_s17_0), M(sMsg_d91_s17_1), NULL };
static const EntityMsg* const sStep_d91_s18[] = { M(sMsg_d91_s18_0), NULL };
static const EntityMsg* const sStep_d91_s19[] = { M(sMsg_d91_s19_0), NULL };
static const EntityMsg* const sStep_d91_s20[] = { M(sMsg_d91_s20_0), NULL };
static const EntityMsg* const sStep_d91_s21[] = { M(sMsg_d91_s21_0), NULL };
static const EntityMsg* const sStep_d91_s22[] = { M(sMsg_d91_s22_0), NULL };
static const EntityMsg* const sStep_d91_s23[] = { M(sMsg_d91_s23_0), NULL };
static const EntityMsg* const sStep_d91_s24[] = { M(sMsg_d91_s24_0), NULL };
static const EntityMsg* const sStep_d91_s25[] = { M(sMsg_d91_s25_0), NULL };
static const EntityMsg* const sStep_d91_s26[] = { M(sMsg_d91_s26_0), NULL };
static const EntityMsg* const sStep_d91_s27[] = { M(sMsg_d91_s27_0), NULL };
static const EntityMsg* const sStep_d91_s28[] = { M(sMsg_d91_s28_0), NULL };
static const EntityMsg* const sStep_d91_s29[] = { M(sMsg_d91_s29_0), NULL };
static const EntityMsg* const sStep_d91_s30[] = { M(sMsg_d91_s30_0), M(sMsg_d91_s30_1), M(sMsg_d91_s30_2), NULL };
static const EntityMsg* const sStep_d91_s31[] = { M(sMsg_d91_s31_0), M(sMsg_d91_s31_1), M(sMsg_d91_s31_2), NULL };
static const EntityMsg* const sStep_d91_s32[] = { M(sMsg_d91_s32_0), NULL };
static const EntityMsg* const sStep_d91_s33[] = { M(sMsg_d91_s33_0), M(sMsg_d91_s33_1), M(sMsg_d91_s33_2), NULL };
static const EntityMsg* const sStep_d91_s34[] = { M(sMsg_d91_s34_0), M(sMsg_d91_s34_1), NULL };
static const EntityMsg* const sStep_d91_s35[] = { M(sMsg_d91_s35_0), NULL };
static const EntityMsg* const sStep_d91_s36[] = { M(sMsg_d91_s36_0), NULL };
static const EntityMsg* const sStep_d91_s37[] = { M(sMsg_d91_s37_0), M(sMsg_d91_s37_1), M(sMsg_d91_s37_2), NULL };
static const EntityMsg* const sStep_d91_s38[] = { M(sMsg_d91_s38_0), NULL };
static const EntityMsg* const sStep_d91_s39[] = { M(sMsg_d91_s39_0), NULL };
static const EntityMsg* const sStep_d91_s40[] = { M(sMsg_d91_s40_0), M(sMsg_d91_s40_1), M(sMsg_d91_s40_2), M(sMsg_d91_s40_3), NULL };
static const EntityMsg* const sStep_d91_s41[] = { M(sMsg_d91_s41_0), M(sMsg_d91_s41_1), M(sMsg_d91_s41_2), NULL };
static const EntityMsg* const sStep_d91_s42[] = { M(sMsg_d91_s42_0), NULL };
static const EntityMsg* const sStep_d91_s43[] = { M(sMsg_d91_s43_0), NULL };
static const EntityMsg* const sStep_d91_s44[] = { M(sMsg_d91_s44_0), M(sMsg_d91_s44_1), M(sMsg_d91_s44_2), NULL };
static const EntityMsg* const sStep_d91_s45[] = { M(sMsg_d91_s45_0), NULL };
static const EntityMsg* const sStep_d92_s0[] = { M(sMsg_d92_s0_0), M(sMsg_d92_s0_1), NULL };
static const EntityMsg* const sStep_d92_s1[] = { M(sMsg_d92_s1_0), M(sMsg_d92_s1_1), M(sMsg_d92_s1_2), NULL };
static const EntityMsg* const sStep_d92_s2[] = { M(sMsg_d92_s2_0), NULL };
static const EntityMsg* const sStep_d92_s3[] = { M(sMsg_d92_s3_0), NULL };
static const EntityMsg* const sStep_d92_s4[] = { M(sMsg_d92_s4_0), NULL };
static const EntityMsg* const sStep_d92_s5[] = { M(sMsg_d92_s5_0), M(sMsg_d92_s5_1), M(sMsg_d92_s5_2), NULL };
static const EntityMsg* const sStep_d92_s6[] = { M(sMsg_d92_s6_0), M(sMsg_d92_s6_1), M(sMsg_d92_s6_2), NULL };
static const EntityMsg* const sStep_d92_s7[] = { M(sMsg_d92_s7_0), NULL };
static const EntityMsg* const sStep_d92_s8[] = { M(sMsg_d92_s8_0), M(sMsg_d92_s8_1), M(sMsg_d92_s8_2), NULL };
static const EntityMsg* const sStep_d92_s9[] = { M(sMsg_d92_s9_0), M(sMsg_d92_s9_1), NULL };
static const EntityMsg* const sStep_d92_s10[] = { M(sMsg_d92_s10_0), NULL };
static const EntityMsg* const sStep_d92_s11[] = { M(sMsg_d92_s11_0), NULL };
static const EntityMsg* const sStep_d92_s12[] = { M(sMsg_d92_s12_0), M(sMsg_d92_s12_1), M(sMsg_d92_s12_2), NULL };
static const EntityMsg* const sStep_d92_s13[] = { M(sMsg_d92_s13_0), NULL };
static const EntityMsg* const sStep_d92_s14[] = { M(sMsg_d92_s14_0), NULL };
static const EntityMsg* const sStep_d92_s15[] = { M(sMsg_d92_s15_0), M(sMsg_d92_s15_1), M(sMsg_d92_s15_2), NULL };
static const EntityMsg* const sStep_d92_s16[] = { M(sMsg_d92_s16_0), M(sMsg_d92_s16_1), M(sMsg_d92_s16_2), NULL };
static const EntityMsg* const sStep_d92_s17[] = { M(sMsg_d92_s17_0), NULL };
static const EntityMsg* const sStep_d92_s18[] = { M(sMsg_d92_s18_0), NULL };
static const EntityMsg* const sStep_d92_s19[] = { M(sMsg_d92_s19_0), M(sMsg_d92_s19_1), NULL };
static const EntityMsg* const sStep_d92_s20[] = { M(sMsg_d92_s20_0), NULL };
static const EntityMsg* const sStep_d93_s0[] = { M(sMsg_d93_s0_0), M(sMsg_d93_s0_1), M(sMsg_d93_s0_2), NULL };
static const EntityMsg* const sStep_d93_s1[] = { M(sMsg_d93_s1_0), NULL };
static const EntityMsg* const sStep_d93_s2[] = { M(sMsg_d93_s2_0), NULL };
static const EntityMsg* const sStep_d93_s3[] = { M(sMsg_d93_s3_0), NULL };
static const EntityMsg* const sStep_d93_s4[] = { M(sMsg_d93_s4_0), NULL };
static const EntityMsg* const sStep_d93_s5[] = { M(sMsg_d93_s5_0), NULL };
static const EntityMsg* const sStep_d93_s6[] = { M(sMsg_d93_s6_0), NULL };
static const EntityMsg* const sStep_d93_s7[] = { M(sMsg_d93_s7_0), M(sMsg_d93_s7_1), M(sMsg_d93_s7_2), NULL };
static const EntityMsg* const sStep_d93_s8[] = { M(sMsg_d93_s8_0), NULL };
static const EntityMsg* const sStep_d93_s9[] = { M(sMsg_d93_s9_0), NULL };
static const EntityMsg* const sStep_d93_s10[] = { M(sMsg_d93_s10_0), M(sMsg_d93_s10_1), M(sMsg_d93_s10_2), NULL };
static const EntityMsg* const sStep_d93_s11[] = { M(sMsg_d93_s11_0), NULL };
static const EntityMsg* const sStep_d93_s12[] = { M(sMsg_d93_s12_0), NULL };
static const EntityMsg* const sStep_d93_s13[] = { M(sMsg_d93_s13_0), M(sMsg_d93_s13_1), NULL };
static const EntityMsg* const sStep_d94_s0[] = { M(sMsg_d94_s0_0), M(sMsg_d94_s0_1), NULL };
static const EntityMsg* const sStep_d94_s1[] = { M(sMsg_d94_s1_0), M(sMsg_d94_s1_1), M(sMsg_d94_s1_2), NULL };
static const EntityMsg* const sStep_d94_s2[] = { M(sMsg_d94_s2_0), M(sMsg_d94_s2_1), NULL };
static const EntityMsg* const sStep_d94_s3[] = { M(sMsg_d94_s3_0), NULL };
static const EntityMsg* const sStep_d94_s4[] = { M(sMsg_d94_s4_0), NULL };
static const EntityMsg* const sStep_d94_s5[] = { M(sMsg_d94_s5_0), NULL };
static const EntityMsg* const sStep_d94_s6[] = { M(sMsg_d94_s6_0), M(sMsg_d94_s6_1), NULL };
static const EntityMsg* const sStep_d94_s7[] = { M(sMsg_d94_s7_0), M(sMsg_d94_s7_1), NULL };
static const EntityMsg* const sStep_d95_s0[] = { M(sMsg_d95_s0_0), NULL };
static const EntityMsg* const sStep_d95_s1[] = { M(sMsg_d95_s1_0), M(sMsg_d95_s1_1), M(sMsg_d95_s1_2), NULL };
static const EntityMsg* const sStep_d95_s2[] = { M(sMsg_d95_s2_0), NULL };
static const EntityMsg* const sStep_d95_s3[] = { M(sMsg_d95_s3_0), NULL };
static const EntityMsg* const sStep_d95_s4[] = { M(sMsg_d95_s4_0), NULL };
static const EntityMsg* const sStep_d95_s5[] = { M(sMsg_d95_s5_0), NULL };
static const EntityMsg* const sStep_d95_s6[] = { M(sMsg_d95_s6_0), M(sMsg_d95_s6_1), NULL };
static const EntityMsg* const sStep_d95_s7[] = { M(sMsg_d95_s7_0), M(sMsg_d95_s7_1), NULL };
static const EntityMsg* const sStep_d96_s0[] = { M(sMsg_d96_s0_0), NULL };
static const EntityMsg* const sStep_d96_s1[] = { M(sMsg_d96_s1_0), M(sMsg_d96_s1_1), M(sMsg_d96_s1_2), NULL };
static const EntityMsg* const sStep_d96_s2[] = { M(sMsg_d96_s2_0), NULL };
static const EntityMsg* const sStep_d96_s3[] = { M(sMsg_d96_s3_0), NULL };
static const EntityMsg* const sStep_d96_s4[] = { M(sMsg_d96_s4_0), NULL };
static const EntityMsg* const sStep_d96_s5[] = { M(sMsg_d96_s5_0), NULL };
static const EntityMsg* const sStep_d96_s6[] = { M(sMsg_d96_s6_0), NULL };
static const EntityMsg* const sStep_d96_s7[] = { M(sMsg_d96_s7_0), NULL };
static const EntityMsg* const sStep_d96_s8[] = { M(sMsg_d96_s8_0), NULL };
static const EntityMsg* const sStep_d96_s9[] = { M(sMsg_d96_s9_0), NULL };
static const EntityMsg* const sStep_d96_s10[] = { M(sMsg_d96_s10_0), NULL };
static const EntityMsg* const sStep_d96_s11[] = { M(sMsg_d96_s11_0), NULL };
static const EntityMsg* const sStep_d96_s12[] = { M(sMsg_d96_s12_0), M(sMsg_d96_s12_1), NULL };
static const EntityMsg* const sStep_d96_s13[] = { M(sMsg_d96_s13_0), M(sMsg_d96_s13_1), NULL };
static const EntityMsg* const sStep_d97_s0[] = { M(sMsg_d97_s0_0), M(sMsg_d97_s0_1), M(sMsg_d97_s0_2), NULL };
static const EntityMsg* const sStep_d97_s1[] = { M(sMsg_d97_s1_0), M(sMsg_d97_s1_1), M(sMsg_d97_s1_2), NULL };
static const EntityMsg* const sStep_d97_s2[] = { M(sMsg_d97_s2_0), NULL };
static const EntityMsg* const sStep_d97_s3[] = { M(sMsg_d97_s3_0), NULL };
static const EntityMsg* const sStep_d97_s4[] = { M(sMsg_d97_s4_0), NULL };
static const EntityMsg* const sStep_d97_s5[] = { M(sMsg_d97_s5_0), M(sMsg_d97_s5_1), M(sMsg_d97_s5_2), M(sMsg_d97_s5_3), NULL };
static const EntityMsg* const sStep_d97_s6[] = { M(sMsg_d97_s6_0), M(sMsg_d97_s6_1), M(sMsg_d97_s6_2), NULL };
static const EntityMsg* const sStep_d97_s7[] = { M(sMsg_d97_s7_0), M(sMsg_d97_s7_1), NULL };
static const EntityMsg* const sStep_d98_s0[] = { M(sMsg_d98_s0_0), M(sMsg_d98_s0_1), NULL };
static const EntityMsg* const sStep_d98_s1[] = { M(sMsg_d98_s1_0), NULL };
static const EntityMsg* const sStep_d98_s2[] = { M(sMsg_d98_s2_0), NULL };
static const EntityMsg* const sStep_d99_s0[] = { M(sMsg_d99_s0_0), M(sMsg_d99_s0_1), NULL };
static const EntityMsg* const sStep_d99_s1[] = { M(sMsg_d99_s1_0), M(sMsg_d99_s1_1), NULL };
static const EntityMsg* const sStep_d99_s2[] = { M(sMsg_d99_s2_0), M(sMsg_d99_s2_1), NULL };
static const EntityMsg* const sStep_d99_s3[] = { M(sMsg_d99_s3_0), NULL };
static const EntityMsg* const sStep_d99_s4[] = { M(sMsg_d99_s4_0), NULL };
static const EntityMsg* const sStep_d100_s0[] = { M(sMsg_d100_s0_0), NULL };
static const EntityMsg* const sStep_d100_s1[] = { M(sMsg_d100_s1_0), M(sMsg_d100_s1_1), NULL };
static const EntityMsg* const sStep_d100_s2[] = { M(sMsg_d100_s2_0), M(sMsg_d100_s2_1), NULL };
static const EntityMsg* const sStep_d100_s3[] = { M(sMsg_d100_s3_0), M(sMsg_d100_s3_1), NULL };
static const EntityMsg* const sStep_d100_s4[] = { M(sMsg_d100_s4_0), NULL };
static const EntityMsg* const sStep_d100_s5[] = { M(sMsg_d100_s5_0), NULL };
static const EntityMsg* const sStep_d100_s6[] = { M(sMsg_d100_s6_0), M(sMsg_d100_s6_1), NULL };
static const EntityMsg* const sStep_d101_s0[] = { M(sMsg_d101_s0_0), NULL };
static const EntityMsg* const sStep_d101_s1[] = { M(sMsg_d101_s1_0), NULL };
static const EntityMsg* const sStep_d101_s2[] = { M(sMsg_d101_s2_0), NULL };
static const EntityMsg* const sStep_d102_s0[] = { M(sMsg_d102_s0_0), M(sMsg_d102_s0_1), M(sMsg_d102_s0_2), M(sMsg_d102_s0_3), M(sMsg_d102_s0_4), NULL };
static const EntityMsg* const sStep_d102_s1[] = { M(sMsg_d102_s1_0), NULL };
static const EntityMsg* const sStep_d102_s2[] = { M(sMsg_d102_s2_0), NULL };
static const EntityMsg* const sStep_d102_s3[] = { M(sMsg_d102_s3_0), M(sMsg_d102_s3_1), NULL };
static const EntityMsg* const sStep_d102_s4[] = { M(sMsg_d102_s4_0), M(sMsg_d102_s4_1), NULL };
static const EntityMsg* const sStep_d102_s5[] = { M(sMsg_d102_s5_0), M(sMsg_d102_s5_1), NULL };
static const EntityMsg* const sStep_d102_s6[] = { M(sMsg_d102_s6_0), NULL };
static const EntityMsg* const sStep_d102_s7[] = { M(sMsg_d102_s7_0), NULL };
static const EntityMsg* const sStep_d102_s8[] = { M(sMsg_d102_s8_0), M(sMsg_d102_s8_1), NULL };
static const EntityMsg* const sStep_d102_s9[] = { M(sMsg_d102_s9_0), NULL };
static const EntityMsg* const sStep_d102_s10[] = { M(sMsg_d102_s10_0), NULL };
static const EntityMsg* const sStep_d102_s11[] = { M(sMsg_d102_s11_0), M(sMsg_d102_s11_1), NULL };
static const EntityMsg* const sStep_d102_s12[] = { M(sMsg_d102_s12_0), M(sMsg_d102_s12_1), M(sMsg_d102_s12_2), M(sMsg_d102_s12_3), NULL };
static const EntityMsg* const sStep_d102_s13[] = { M(sMsg_d102_s13_0), NULL };
static const EntityMsg* const sStep_d102_s14[] = { M(sMsg_d102_s14_0), NULL };
static const EntityMsg* const sStep_d102_s15[] = { M(sMsg_d102_s15_0), M(sMsg_d102_s15_1), M(sMsg_d102_s15_2), NULL };
static const EntityMsg* const sStep_d102_s16[] = { M(sMsg_d102_s16_0), M(sMsg_d102_s16_1), M(sMsg_d102_s16_2), NULL };
static const EntityMsg* const sStep_d102_s17[] = { M(sMsg_d102_s17_0), M(sMsg_d102_s17_1), NULL };
static const EntityMsg* const sStep_d102_s18[] = { M(sMsg_d102_s18_0), NULL };
static const EntityMsg* const sStep_d102_s19[] = { M(sMsg_d102_s19_0), NULL };
static const EntityMsg* const sStep_d102_s20[] = { M(sMsg_d102_s20_0), M(sMsg_d102_s20_1), M(sMsg_d102_s20_2), NULL };
static const EntityMsg* const sStep_d102_s21[] = { M(sMsg_d102_s21_0), NULL };
static const EntityMsg* const sStep_d102_s22[] = { M(sMsg_d102_s22_0), NULL };
static const EntityMsg* const sStep_d102_s23[] = { M(sMsg_d102_s23_0), M(sMsg_d102_s23_1), NULL };
static const EntityMsg* const sStep_d102_s24[] = { M(sMsg_d102_s24_0), NULL };
static const EntityMsg* const sStep_d102_s25[] = { M(sMsg_d102_s25_0), NULL };
static const EntityMsg* const sStep_d102_s26[] = { M(sMsg_d102_s26_0), M(sMsg_d102_s26_1), NULL };
static const EntityMsg* const sStep_d102_s27[] = { M(sMsg_d102_s27_0), NULL };
static const EntityMsg* const sStep_d102_s28[] = { M(sMsg_d102_s28_0), NULL };
static const EntityMsg* const sStep_d102_s29[] = { M(sMsg_d102_s29_0), NULL };
static const EntityMsg* const sStep_d102_s30[] = { M(sMsg_d102_s30_0), M(sMsg_d102_s30_1), NULL };
static const EntityMsg* const sStep_d102_s31[] = { M(sMsg_d102_s31_0), NULL };
static const EntityMsg* const sStep_d102_s32[] = { M(sMsg_d102_s32_0), NULL };
static const EntityMsg* const sStep_d102_s33[] = { M(sMsg_d102_s33_0), NULL };
static const EntityMsg* const sStep_d102_s34[] = { M(sMsg_d102_s34_0), NULL };
static const EntityMsg* const sStep_d102_s35[] = { M(sMsg_d102_s35_0), M(sMsg_d102_s35_1), NULL };
static const EntityMsg* const sStep_d102_s36[] = { M(sMsg_d102_s36_0), M(sMsg_d102_s36_1), NULL };
static const EntityMsg* const sStep_d103_s0[] = { M(sMsg_d103_s0_0), M(sMsg_d103_s0_1), NULL };
static const EntityMsg* const sStep_d103_s1[] = { M(sMsg_d103_s1_0), M(sMsg_d103_s1_1), M(sMsg_d103_s1_2), NULL };
static const EntityMsg* const sStep_d103_s2[] = { M(sMsg_d103_s2_0), NULL };
static const EntityMsg* const sStep_d103_s3[] = { M(sMsg_d103_s3_0), M(sMsg_d103_s3_1), M(sMsg_d103_s3_2), NULL };
static const EntityMsg* const sStep_d103_s4[] = { M(sMsg_d103_s4_0), M(sMsg_d103_s4_1), M(sMsg_d103_s4_2), NULL };
static const EntityMsg* const sStep_d103_s5[] = { M(sMsg_d103_s5_0), M(sMsg_d103_s5_1), M(sMsg_d103_s5_2), NULL };
static const EntityMsg* const sStep_d103_s6[] = { M(sMsg_d103_s6_0), M(sMsg_d103_s6_1), NULL };
static const EntityMsg* const sStep_d103_s7[] = { M(sMsg_d103_s7_0), NULL };
static const EntityMsg* const sStep_d103_s8[] = { M(sMsg_d103_s8_0), NULL };
static const EntityMsg* const sStep_d103_s9[] = { M(sMsg_d103_s9_0), M(sMsg_d103_s9_1), M(sMsg_d103_s9_2), NULL };
static const EntityMsg* const sStep_d103_s10[] = { M(sMsg_d103_s10_0), NULL };
static const EntityMsg* const sStep_d103_s11[] = { M(sMsg_d103_s11_0), NULL };
static const EntityMsg* const sStep_d103_s12[] = { M(sMsg_d103_s12_0), M(sMsg_d103_s12_1), NULL };
static const EntityMsg* const sStep_d103_s13[] = { M(sMsg_d103_s13_0), NULL };
static const EntityMsg* const sStep_d103_s14[] = { M(sMsg_d103_s14_0), NULL };
static const EntityMsg* const sStep_d103_s15[] = { M(sMsg_d103_s15_0), NULL };
static const EntityMsg* const sStep_d103_s16[] = { M(sMsg_d103_s16_0), M(sMsg_d103_s16_1), NULL };
static const EntityMsg* const sStep_d103_s17[] = { M(sMsg_d103_s17_0), NULL };
static const EntityMsg* const sStep_d103_s18[] = { M(sMsg_d103_s18_0), NULL };
static const EntityMsg* const sStep_d103_s19[] = { M(sMsg_d103_s19_0), M(sMsg_d103_s19_1), NULL };
static const EntityMsg* const sStep_d103_s20[] = { M(sMsg_d103_s20_0), M(sMsg_d103_s20_1), NULL };
static const EntityMsg* const sStep_d104_s0[] = { M(sMsg_d104_s0_0), M(sMsg_d104_s0_1), M(sMsg_d104_s0_2), M(sMsg_d104_s0_3), NULL };
static const EntityMsg* const sStep_d104_s1[] = { M(sMsg_d104_s1_0), M(sMsg_d104_s1_1), NULL };
static const EntityMsg* const sStep_d104_s2[] = { M(sMsg_d104_s2_0), M(sMsg_d104_s2_1), M(sMsg_d104_s2_2), NULL };
static const EntityMsg* const sStep_d104_s3[] = { M(sMsg_d104_s3_0), M(sMsg_d104_s3_1), NULL };
static const EntityMsg* const sStep_d104_s4[] = { M(sMsg_d104_s4_0), NULL };
static const EntityMsg* const sStep_d104_s5[] = { M(sMsg_d104_s5_0), NULL };
static const EntityMsg* const sStep_d104_s6[] = { M(sMsg_d104_s6_0), M(sMsg_d104_s6_1), NULL };
static const EntityMsg* const sStep_d104_s7[] = { M(sMsg_d104_s7_0), M(sMsg_d104_s7_1), M(sMsg_d104_s7_2), NULL };
static const EntityMsg* const sStep_d104_s8[] = { M(sMsg_d104_s8_0), M(sMsg_d104_s8_1), NULL };
static const EntityMsg* const sStep_d104_s9[] = { M(sMsg_d104_s9_0), NULL };
static const EntityMsg* const sStep_d104_s10[] = { M(sMsg_d104_s10_0), NULL };
static const EntityMsg* const sStep_d104_s11[] = { M(sMsg_d104_s11_0), NULL };
static const EntityMsg* const sStep_d105_s0[] = { M(sMsg_d105_s0_0), M(sMsg_d105_s0_1), M(sMsg_d105_s0_2), M(sMsg_d105_s0_3), NULL };
static const EntityMsg* const sStep_d105_s1[] = { M(sMsg_d105_s1_0), M(sMsg_d105_s1_1), NULL };
static const EntityMsg* const sStep_d105_s2[] = { M(sMsg_d105_s2_0), M(sMsg_d105_s2_1), M(sMsg_d105_s2_2), NULL };
static const EntityMsg* const sStep_d105_s3[] = { M(sMsg_d105_s3_0), M(sMsg_d105_s3_1), NULL };
static const EntityMsg* const sStep_d105_s4[] = { M(sMsg_d105_s4_0), NULL };
static const EntityMsg* const sStep_d105_s5[] = { M(sMsg_d105_s5_0), NULL };
static const EntityMsg* const sStep_d105_s6[] = { M(sMsg_d105_s6_0), M(sMsg_d105_s6_1), NULL };
static const EntityMsg* const sStep_d105_s7[] = { M(sMsg_d105_s7_0), M(sMsg_d105_s7_1), M(sMsg_d105_s7_2), NULL };
static const EntityMsg* const sStep_d105_s8[] = { M(sMsg_d105_s8_0), M(sMsg_d105_s8_1), NULL };
static const EntityMsg* const sStep_d105_s9[] = { M(sMsg_d105_s9_0), NULL };
static const EntityMsg* const sStep_d105_s10[] = { M(sMsg_d105_s10_0), NULL };
static const EntityMsg* const sStep_d105_s11[] = { M(sMsg_d105_s11_0), NULL };
static const EntityMsg* const sStep_d106_s0[] = { M(sMsg_d106_s0_0), M(sMsg_d106_s0_1), M(sMsg_d106_s0_2), M(sMsg_d106_s0_3), NULL };
static const EntityMsg* const sStep_d106_s1[] = { M(sMsg_d106_s1_0), M(sMsg_d106_s1_1), NULL };
static const EntityMsg* const sStep_d106_s2[] = { M(sMsg_d106_s2_0), NULL };
static const EntityMsg* const sStep_d106_s3[] = { M(sMsg_d106_s3_0), NULL };
static const EntityMsg* const sStep_d106_s4[] = { M(sMsg_d106_s4_0), M(sMsg_d106_s4_1), NULL };
static const EntityMsg* const sStep_d106_s5[] = { M(sMsg_d106_s5_0), NULL };
static const EntityMsg* const sStep_d106_s6[] = { M(sMsg_d106_s6_0), NULL };
static const EntityMsg* const sStep_d106_s7[] = { M(sMsg_d106_s7_0), M(sMsg_d106_s7_1), NULL };
static const EntityMsg* const sStep_d106_s8[] = { M(sMsg_d106_s8_0), M(sMsg_d106_s8_1), M(sMsg_d106_s8_2), NULL };
static const EntityMsg* const sStep_d106_s9[] = { M(sMsg_d106_s9_0), M(sMsg_d106_s9_1), NULL };
static const EntityMsg* const sStep_d106_s10[] = { M(sMsg_d106_s10_0), NULL };
static const EntityMsg* const sStep_d106_s11[] = { M(sMsg_d106_s11_0), NULL };
static const EntityMsg* const sStep_d106_s12[] = { M(sMsg_d106_s12_0), M(sMsg_d106_s12_1), M(sMsg_d106_s12_2), NULL };
static const EntityMsg* const sStep_d106_s13[] = { M(sMsg_d106_s13_0), M(sMsg_d106_s13_1), NULL };
static const EntityMsg* const sStep_d106_s14[] = { M(sMsg_d106_s14_0), M(sMsg_d106_s14_1), NULL };
static const EntityMsg* const sStep_d107_s0[] = { M(sMsg_d107_s0_0), M(sMsg_d107_s0_1), M(sMsg_d107_s0_2), M(sMsg_d107_s0_3), NULL };
static const EntityMsg* const sStep_d107_s1[] = { M(sMsg_d107_s1_0), M(sMsg_d107_s1_1), M(sMsg_d107_s1_2), NULL };
static const EntityMsg* const sStep_d107_s2[] = { M(sMsg_d107_s2_0), NULL };
static const EntityMsg* const sStep_d107_s3[] = { M(sMsg_d107_s3_0), NULL };
static const EntityMsg* const sStep_d107_s4[] = { M(sMsg_d107_s4_0), M(sMsg_d107_s4_1), NULL };
static const EntityMsg* const sStep_d107_s5[] = { M(sMsg_d107_s5_0), NULL };
static const EntityMsg* const sStep_d107_s6[] = { M(sMsg_d107_s6_0), NULL };
static const EntityMsg* const sStep_d107_s7[] = { M(sMsg_d107_s7_0), NULL };
static const EntityMsg* const sStep_d107_s8[] = { M(sMsg_d107_s8_0), NULL };
static const EntityMsg* const sStep_d107_s9[] = { M(sMsg_d107_s9_0), NULL };
static const EntityMsg* const sStep_d107_s10[] = { M(sMsg_d107_s10_0), M(sMsg_d107_s10_1), NULL };
static const EntityMsg* const sStep_d107_s11[] = { M(sMsg_d107_s11_0), M(sMsg_d107_s11_1), NULL };
static const EntityMsg* const sStep_d107_s12[] = { M(sMsg_d107_s12_0), M(sMsg_d107_s12_1), NULL };
static const EntityMsg* const sStep_d107_s13[] = { M(sMsg_d107_s13_0), M(sMsg_d107_s13_1), NULL };
static const EntityMsg* const sStep_d107_s14[] = { M(sMsg_d107_s14_0), M(sMsg_d107_s14_1), NULL };
static const EntityMsg* const sStep_d108_s0[] = { M(sMsg_d108_s0_0), M(sMsg_d108_s0_1), M(sMsg_d108_s0_2), M(sMsg_d108_s0_3), NULL };
static const EntityMsg* const sStep_d108_s1[] = { M(sMsg_d108_s1_0), M(sMsg_d108_s1_1), M(sMsg_d108_s1_2), NULL };
static const EntityMsg* const sStep_d108_s2[] = { M(sMsg_d108_s2_0), NULL };
static const EntityMsg* const sStep_d108_s3[] = { M(sMsg_d108_s3_0), NULL };
static const EntityMsg* const sStep_d108_s4[] = { M(sMsg_d108_s4_0), M(sMsg_d108_s4_1), NULL };
static const EntityMsg* const sStep_d108_s5[] = { M(sMsg_d108_s5_0), NULL };
static const EntityMsg* const sStep_d108_s6[] = { M(sMsg_d108_s6_0), NULL };
static const EntityMsg* const sStep_d108_s7[] = { M(sMsg_d108_s7_0), NULL };
static const EntityMsg* const sStep_d108_s8[] = { M(sMsg_d108_s8_0), NULL };
static const EntityMsg* const sStep_d108_s9[] = { M(sMsg_d108_s9_0), NULL };
static const EntityMsg* const sStep_d108_s10[] = { M(sMsg_d108_s10_0), M(sMsg_d108_s10_1), NULL };
static const EntityMsg* const sStep_d108_s11[] = { M(sMsg_d108_s11_0), M(sMsg_d108_s11_1), NULL };
static const EntityMsg* const sStep_d108_s12[] = { M(sMsg_d108_s12_0), M(sMsg_d108_s12_1), NULL };
static const EntityMsg* const sStep_d108_s13[] = { M(sMsg_d108_s13_0), M(sMsg_d108_s13_1), NULL };
static const EntityMsg* const sStep_d108_s14[] = { M(sMsg_d108_s14_0), M(sMsg_d108_s14_1), NULL };
static const EntityMsg* const sStep_d109_s0[] = { M(sMsg_d109_s0_0), M(sMsg_d109_s0_1), M(sMsg_d109_s0_2), NULL };
static const EntityMsg* const sStep_d109_s1[] = { M(sMsg_d109_s1_0), M(sMsg_d109_s1_1), M(sMsg_d109_s1_2), M(sMsg_d109_s1_3), M(sMsg_d109_s1_4), NULL };
static const EntityMsg* const sStep_d109_s2[] = { M(sMsg_d109_s2_0), NULL };
static const EntityMsg* const sStep_d109_s3[] = { M(sMsg_d109_s3_0), NULL };
static const EntityMsg* const sStep_d109_s4[] = { M(sMsg_d109_s4_0), M(sMsg_d109_s4_1), NULL };
static const EntityMsg* const sStep_d109_s5[] = { M(sMsg_d109_s5_0), NULL };
static const EntityMsg* const sStep_d109_s6[] = { M(sMsg_d109_s6_0), NULL };
static const EntityMsg* const sStep_d109_s7[] = { M(sMsg_d109_s7_0), M(sMsg_d109_s7_1), NULL };
static const EntityMsg* const sStep_d109_s8[] = { M(sMsg_d109_s8_0), NULL };
static const EntityMsg* const sStep_d109_s9[] = { M(sMsg_d109_s9_0), NULL };
static const EntityMsg* const sStep_d109_s10[] = { M(sMsg_d109_s10_0), NULL };
static const EntityMsg* const sStep_d109_s11[] = { M(sMsg_d109_s11_0), NULL };
static const EntityMsg* const sStep_d109_s12[] = { M(sMsg_d109_s12_0), M(sMsg_d109_s12_1), M(sMsg_d109_s12_2), M(sMsg_d109_s12_3), NULL };
static const EntityMsg* const sStep_d109_s13[] = { M(sMsg_d109_s13_0), M(sMsg_d109_s13_1), NULL };
static const EntityMsg* const sStep_d110_s0[] = { M(sMsg_d110_s0_0), NULL };
static const EntityMsg* const sStep_d110_s1[] = { M(sMsg_d110_s1_0), NULL };
static const EntityMsg* const sStep_d110_s2[] = { M(sMsg_d110_s2_0), NULL };
static const EntityMsg* const sStep_d110_s3[] = { M(sMsg_d110_s3_0), M(sMsg_d110_s3_1), NULL };
static const EntityMsg* const sStep_d110_s4[] = { M(sMsg_d110_s4_0), M(sMsg_d110_s4_1), NULL };
static const EntityMsg* const sStep_d110_s5[] = { M(sMsg_d110_s5_0), M(sMsg_d110_s5_1), M(sMsg_d110_s5_2), NULL };
static const EntityMsg* const sStep_d110_s6[] = { M(sMsg_d110_s6_0), NULL };
static const EntityMsg* const sStep_d110_s7[] = { M(sMsg_d110_s7_0), NULL };
static const EntityMsg* const sStep_d110_s8[] = { M(sMsg_d110_s8_0), NULL };
static const EntityMsg* const sStep_d110_s9[] = { M(sMsg_d110_s9_0), NULL };
static const EntityMsg* const sStep_d110_s10[] = { M(sMsg_d110_s10_0), NULL };
static const EntityMsg* const sStep_d110_s11[] = { M(sMsg_d110_s11_0), NULL };
static const EntityMsg* const sStep_d110_s12[] = { M(sMsg_d110_s12_0), NULL };
static const EntityMsg* const sStep_d110_s13[] = { M(sMsg_d110_s13_0), NULL };
static const EntityMsg* const sStep_d110_s14[] = { M(sMsg_d110_s14_0), NULL };
static const EntityMsg* const sStep_d110_s15[] = { M(sMsg_d110_s15_0), NULL };
static const EntityMsg* const sStep_d110_s16[] = { M(sMsg_d110_s16_0), NULL };
static const EntityMsg* const sStep_d110_s17[] = { M(sMsg_d110_s17_0), NULL };
static const EntityMsg* const sStep_d110_s18[] = { M(sMsg_d110_s18_0), NULL };
static const EntityMsg* const sStep_d111_s0[] = { M(sMsg_d111_s0_0), NULL };
static const EntityMsg* const sStep_d111_s1[] = { M(sMsg_d111_s1_0), NULL };
static const EntityMsg* const sStep_d111_s2[] = { M(sMsg_d111_s2_0), NULL };
static const EntityMsg* const sStep_d111_s3[] = { M(sMsg_d111_s3_0), M(sMsg_d111_s3_1), NULL };
static const EntityMsg* const sStep_d111_s4[] = { M(sMsg_d111_s4_0), M(sMsg_d111_s4_1), NULL };
static const EntityMsg* const sStep_d111_s5[] = { M(sMsg_d111_s5_0), M(sMsg_d111_s5_1), M(sMsg_d111_s5_2), NULL };
static const EntityMsg* const sStep_d111_s6[] = { M(sMsg_d111_s6_0), NULL };
static const EntityMsg* const sStep_d111_s7[] = { M(sMsg_d111_s7_0), NULL };
static const EntityMsg* const sStep_d111_s8[] = { M(sMsg_d111_s8_0), NULL };
static const EntityMsg* const sStep_d111_s9[] = { M(sMsg_d111_s9_0), NULL };
static const EntityMsg* const sStep_d111_s10[] = { M(sMsg_d111_s10_0), NULL };
static const EntityMsg* const sStep_d111_s11[] = { M(sMsg_d111_s11_0), NULL };
static const EntityMsg* const sStep_d111_s12[] = { M(sMsg_d111_s12_0), NULL };
static const EntityMsg* const sStep_d111_s13[] = { M(sMsg_d111_s13_0), NULL };
static const EntityMsg* const sStep_d111_s14[] = { M(sMsg_d111_s14_0), NULL };
static const EntityMsg* const sStep_d111_s15[] = { M(sMsg_d111_s15_0), NULL };
static const EntityMsg* const sStep_d111_s16[] = { M(sMsg_d111_s16_0), NULL };
static const EntityMsg* const sStep_d111_s17[] = { M(sMsg_d111_s17_0), NULL };
static const EntityMsg* const sStep_d111_s18[] = { M(sMsg_d111_s18_0), NULL };
static const EntityMsg* const sStep_d112_s0[] = { M(sMsg_d112_s0_0), NULL };
static const EntityMsg* const sStep_d112_s1[] = { M(sMsg_d112_s1_0), NULL };
static const EntityMsg* const sStep_d112_s2[] = { M(sMsg_d112_s2_0), NULL };
static const EntityMsg* const sStep_d112_s3[] = { M(sMsg_d112_s3_0), M(sMsg_d112_s3_1), NULL };
static const EntityMsg* const sStep_d112_s4[] = { M(sMsg_d112_s4_0), NULL };
static const EntityMsg* const sStep_d112_s5[] = { M(sMsg_d112_s5_0), M(sMsg_d112_s5_1), NULL };
static const EntityMsg* const sStep_d112_s6[] = { M(sMsg_d112_s6_0), M(sMsg_d112_s6_1), M(sMsg_d112_s6_2), NULL };
static const EntityMsg* const sStep_d112_s7[] = { M(sMsg_d112_s7_0), NULL };
static const EntityMsg* const sStep_d112_s8[] = { M(sMsg_d112_s8_0), M(sMsg_d112_s8_1), NULL };
static const EntityMsg* const sStep_d112_s9[] = { M(sMsg_d112_s9_0), NULL };
static const EntityMsg* const sStep_d112_s10[] = { M(sMsg_d112_s10_0), NULL };
static const EntityMsg* const sStep_d112_s11[] = { M(sMsg_d112_s11_0), NULL };
static const EntityMsg* const sStep_d112_s12[] = { M(sMsg_d112_s12_0), NULL };
static const EntityMsg* const sStep_d112_s13[] = { M(sMsg_d112_s13_0), NULL };
static const EntityMsg* const sStep_d112_s14[] = { M(sMsg_d112_s14_0), NULL };
static const EntityMsg* const sStep_d112_s15[] = { M(sMsg_d112_s15_0), NULL };
static const EntityMsg* const sStep_d112_s16[] = { M(sMsg_d112_s16_0), NULL };
static const EntityMsg* const sStep_d112_s17[] = { M(sMsg_d112_s17_0), NULL };
static const EntityMsg* const sStep_d112_s18[] = { M(sMsg_d112_s18_0), NULL };
static const EntityMsg* const sStep_d112_s19[] = { M(sMsg_d112_s19_0), NULL };
static const EntityMsg* const sStep_d113_s0[] = { M(sMsg_d113_s0_0), NULL };
static const EntityMsg* const sStep_d113_s1[] = { M(sMsg_d113_s1_0), NULL };
static const EntityMsg* const sStep_d113_s2[] = { M(sMsg_d113_s2_0), NULL };
static const EntityMsg* const sStep_d113_s3[] = { M(sMsg_d113_s3_0), M(sMsg_d113_s3_1), NULL };
static const EntityMsg* const sStep_d113_s4[] = { M(sMsg_d113_s4_0), M(sMsg_d113_s4_1), NULL };
static const EntityMsg* const sStep_d113_s5[] = { M(sMsg_d113_s5_0), M(sMsg_d113_s5_1), M(sMsg_d113_s5_2), NULL };
static const EntityMsg* const sStep_d113_s6[] = { M(sMsg_d113_s6_0), NULL };
static const EntityMsg* const sStep_d113_s7[] = { M(sMsg_d113_s7_0), NULL };
static const EntityMsg* const sStep_d113_s8[] = { M(sMsg_d113_s8_0), NULL };
static const EntityMsg* const sStep_d113_s9[] = { M(sMsg_d113_s9_0), NULL };
static const EntityMsg* const sStep_d113_s10[] = { M(sMsg_d113_s10_0), NULL };
static const EntityMsg* const sStep_d113_s11[] = { M(sMsg_d113_s11_0), NULL };
static const EntityMsg* const sStep_d113_s12[] = { M(sMsg_d113_s12_0), NULL };
static const EntityMsg* const sStep_d113_s13[] = { M(sMsg_d113_s13_0), NULL };
static const EntityMsg* const sStep_d113_s14[] = { M(sMsg_d113_s14_0), NULL };
static const EntityMsg* const sStep_d113_s15[] = { M(sMsg_d113_s15_0), NULL };
static const EntityMsg* const sStep_d113_s16[] = { M(sMsg_d113_s16_0), NULL };
static const EntityMsg* const sStep_d113_s17[] = { M(sMsg_d113_s17_0), NULL };
static const EntityMsg* const sStep_d113_s18[] = { M(sMsg_d113_s18_0), NULL };
static const EntityMsg* const sStep_d114_s0[] = { M(sMsg_d114_s0_0), NULL };
static const EntityMsg* const sStep_d114_s1[] = { M(sMsg_d114_s1_0), NULL };
static const EntityMsg* const sStep_d114_s2[] = { M(sMsg_d114_s2_0), NULL };
static const EntityMsg* const sStep_d114_s3[] = { M(sMsg_d114_s3_0), M(sMsg_d114_s3_1), NULL };
static const EntityMsg* const sStep_d114_s4[] = { M(sMsg_d114_s4_0), M(sMsg_d114_s4_1), NULL };
static const EntityMsg* const sStep_d114_s5[] = { M(sMsg_d114_s5_0), M(sMsg_d114_s5_1), M(sMsg_d114_s5_2), NULL };
static const EntityMsg* const sStep_d114_s6[] = { M(sMsg_d114_s6_0), NULL };
static const EntityMsg* const sStep_d114_s7[] = { M(sMsg_d114_s7_0), NULL };
static const EntityMsg* const sStep_d114_s8[] = { M(sMsg_d114_s8_0), NULL };
static const EntityMsg* const sStep_d114_s9[] = { M(sMsg_d114_s9_0), NULL };
static const EntityMsg* const sStep_d114_s10[] = { M(sMsg_d114_s10_0), NULL };
static const EntityMsg* const sStep_d114_s11[] = { M(sMsg_d114_s11_0), NULL };
static const EntityMsg* const sStep_d114_s12[] = { M(sMsg_d114_s12_0), NULL };
static const EntityMsg* const sStep_d114_s13[] = { M(sMsg_d114_s13_0), NULL };
static const EntityMsg* const sStep_d114_s14[] = { M(sMsg_d114_s14_0), NULL };
static const EntityMsg* const sStep_d114_s15[] = { M(sMsg_d114_s15_0), NULL };
static const EntityMsg* const sStep_d114_s16[] = { M(sMsg_d114_s16_0), NULL };
static const EntityMsg* const sStep_d114_s17[] = { M(sMsg_d114_s17_0), NULL };
static const EntityMsg* const sStep_d114_s18[] = { M(sMsg_d114_s18_0), NULL };
static const EntityMsg* const sStep_d115_s0[] = { M(sMsg_d115_s0_0), NULL };
static const EntityMsg* const sStep_d115_s1[] = { M(sMsg_d115_s1_0), NULL };
static const EntityMsg* const sStep_d115_s2[] = { M(sMsg_d115_s2_0), NULL };
static const EntityMsg* const sStep_d115_s3[] = { M(sMsg_d115_s3_0), M(sMsg_d115_s3_1), NULL };
static const EntityMsg* const sStep_d115_s4[] = { M(sMsg_d115_s4_0), NULL };
static const EntityMsg* const sStep_d115_s5[] = { M(sMsg_d115_s5_0), M(sMsg_d115_s5_1), NULL };
static const EntityMsg* const sStep_d115_s6[] = { M(sMsg_d115_s6_0), M(sMsg_d115_s6_1), M(sMsg_d115_s6_2), NULL };
static const EntityMsg* const sStep_d115_s7[] = { M(sMsg_d115_s7_0), NULL };
static const EntityMsg* const sStep_d115_s8[] = { M(sMsg_d115_s8_0), M(sMsg_d115_s8_1), NULL };
static const EntityMsg* const sStep_d115_s9[] = { M(sMsg_d115_s9_0), NULL };
static const EntityMsg* const sStep_d115_s10[] = { M(sMsg_d115_s10_0), NULL };
static const EntityMsg* const sStep_d115_s11[] = { M(sMsg_d115_s11_0), NULL };
static const EntityMsg* const sStep_d115_s12[] = { M(sMsg_d115_s12_0), NULL };
static const EntityMsg* const sStep_d115_s13[] = { M(sMsg_d115_s13_0), NULL };
static const EntityMsg* const sStep_d115_s14[] = { M(sMsg_d115_s14_0), NULL };
static const EntityMsg* const sStep_d115_s15[] = { M(sMsg_d115_s15_0), NULL };
static const EntityMsg* const sStep_d115_s16[] = { M(sMsg_d115_s16_0), NULL };
static const EntityMsg* const sStep_d115_s17[] = { M(sMsg_d115_s17_0), NULL };
static const EntityMsg* const sStep_d115_s18[] = { M(sMsg_d115_s18_0), NULL };
static const EntityMsg* const sStep_d115_s19[] = { M(sMsg_d115_s19_0), NULL };
static const EntityMsg* const sStep_d116_s0[] = { M(sMsg_d116_s0_0), M(sMsg_d116_s0_1), NULL };
static const EntityMsg* const sStep_d116_s1[] = { M(sMsg_d116_s1_0), M(sMsg_d116_s1_1), NULL };
static const EntityMsg* const sStep_d116_s2[] = { M(sMsg_d116_s2_0), M(sMsg_d116_s2_1), NULL };
static const EntityMsg* const sStep_d116_s3[] = { M(sMsg_d116_s3_0), M(sMsg_d116_s3_1), NULL };
static const EntityMsg* const sStep_d116_s4[] = { M(sMsg_d116_s4_0), M(sMsg_d116_s4_1), NULL };
static const EntityMsg* const sStep_d116_s5[] = { M(sMsg_d116_s5_0), M(sMsg_d116_s5_1), M(sMsg_d116_s5_2), M(sMsg_d116_s5_3), NULL };
static const EntityMsg* const sStep_d117_s0[] = { M(sMsg_d117_s0_0), M(sMsg_d117_s0_1), M(sMsg_d117_s0_2), NULL };
static const EntityMsg* const sStep_d117_s1[] = { M(sMsg_d117_s1_0), M(sMsg_d117_s1_1), NULL };
static const EntityMsg* const sStep_d117_s2[] = { M(sMsg_d117_s2_0), M(sMsg_d117_s2_1), NULL };
static const EntityMsg* const sStep_d117_s3[] = { M(sMsg_d117_s3_0), NULL };
static const EntityMsg* const sStep_d117_s4[] = { M(sMsg_d117_s4_0), NULL };
static const EntityMsg* const sStep_d117_s5[] = { M(sMsg_d117_s5_0), M(sMsg_d117_s5_1), NULL };
static const EntityMsg* const sStep_d117_s6[] = { M(sMsg_d117_s6_0), NULL };
static const EntityMsg* const sStep_d117_s7[] = { M(sMsg_d117_s7_0), NULL };
static const EntityMsg* const sStep_d117_s8[] = { M(sMsg_d117_s8_0), M(sMsg_d117_s8_1), NULL };
static const EntityMsg* const sStep_d118_s0[] = { M(sMsg_d118_s0_0), NULL };
static const EntityMsg* const sStep_d118_s1[] = { M(sMsg_d118_s1_0), M(sMsg_d118_s1_1), NULL };
static const EntityMsg* const sStep_d118_s2[] = { M(sMsg_d118_s2_0), NULL };
static const EntityMsg* const sStep_d118_s3[] = { M(sMsg_d118_s3_0), M(sMsg_d118_s3_1), NULL };
static const EntityMsg* const sStep_d118_s4[] = { M(sMsg_d118_s4_0), NULL };
static const EntityMsg* const sStep_d118_s5[] = { M(sMsg_d118_s5_0), NULL };
static const EntityMsg* const sStep_d119_s0[] = { M(sMsg_d119_s0_0), NULL };
static const EntityMsg* const sStep_d119_s1[] = { M(sMsg_d119_s1_0), M(sMsg_d119_s1_1), M(sMsg_d119_s1_2), NULL };
static const EntityMsg* const sStep_d119_s2[] = { M(sMsg_d119_s2_0), NULL };
static const EntityMsg* const sStep_d119_s3[] = { M(sMsg_d119_s3_0), NULL };
static const EntityMsg* const sStep_d119_s4[] = { M(sMsg_d119_s4_0), M(sMsg_d119_s4_1), NULL };
static const EntityMsg* const sStep_d119_s5[] = { M(sMsg_d119_s5_0), NULL };
static const EntityMsg* const sStep_d119_s6[] = { M(sMsg_d119_s6_0), NULL };
static const EntityMsg* const sStep_d119_s7[] = { M(sMsg_d119_s7_0), M(sMsg_d119_s7_1), NULL };
static const EntityMsg* const sStep_d119_s8[] = { M(sMsg_d119_s8_0), NULL };
static const EntityMsg* const sStep_d119_s9[] = { M(sMsg_d119_s9_0), NULL };
static const EntityMsg* const sStep_d119_s10[] = { M(sMsg_d119_s10_0), NULL };
static const EntityMsg* const sStep_d119_s11[] = { M(sMsg_d119_s11_0), M(sMsg_d119_s11_1), M(sMsg_d119_s11_2), NULL };
static const EntityMsg* const sStep_d119_s12[] = { M(sMsg_d119_s12_0), NULL };
static const EntityMsg* const sStep_d119_s13[] = { M(sMsg_d119_s13_0), NULL };
static const EntityMsg* const sStep_d119_s14[] = { M(sMsg_d119_s14_0), M(sMsg_d119_s14_1), M(sMsg_d119_s14_2), NULL };
static const EntityMsg* const sStep_d120_s0[] = { M(sMsg_d120_s0_0), NULL };
static const EntityMsg* const sStep_d120_s1[] = { M(sMsg_d120_s1_0), M(sMsg_d120_s1_1), M(sMsg_d120_s1_2), NULL };
static const EntityMsg* const sStep_d120_s2[] = { M(sMsg_d120_s2_0), NULL };
static const EntityMsg* const sStep_d120_s3[] = { M(sMsg_d120_s3_0), NULL };
static const EntityMsg* const sStep_d120_s4[] = { M(sMsg_d120_s4_0), M(sMsg_d120_s4_1), NULL };
static const EntityMsg* const sStep_d120_s5[] = { M(sMsg_d120_s5_0), NULL };
static const EntityMsg* const sStep_d120_s6[] = { M(sMsg_d120_s6_0), NULL };
static const EntityMsg* const sStep_d120_s7[] = { M(sMsg_d120_s7_0), M(sMsg_d120_s7_1), NULL };
static const EntityMsg* const sStep_d120_s8[] = { M(sMsg_d120_s8_0), NULL };
static const EntityMsg* const sStep_d120_s9[] = { M(sMsg_d120_s9_0), NULL };
static const EntityMsg* const sStep_d120_s10[] = { M(sMsg_d120_s10_0), NULL };
static const EntityMsg* const sStep_d120_s11[] = { M(sMsg_d120_s11_0), M(sMsg_d120_s11_1), M(sMsg_d120_s11_2), NULL };
static const EntityMsg* const sStep_d120_s12[] = { M(sMsg_d120_s12_0), NULL };
static const EntityMsg* const sStep_d120_s13[] = { M(sMsg_d120_s13_0), NULL };
static const EntityMsg* const sStep_d120_s14[] = { M(sMsg_d120_s14_0), M(sMsg_d120_s14_1), M(sMsg_d120_s14_2), NULL };
static const EntityMsg* const sStep_d121_s0[] = { M(sMsg_d121_s0_0), M(sMsg_d121_s0_1), NULL };
static const EntityMsg* const sStep_d121_s1[] = { M(sMsg_d121_s1_0), M(sMsg_d121_s1_1), NULL };
static const EntityMsg* const sStep_d121_s2[] = { M(sMsg_d121_s2_0), NULL };
static const EntityMsg* const sStep_d121_s3[] = { M(sMsg_d121_s3_0), NULL };
static const EntityMsg* const sStep_d122_s0[] = { M(sMsg_d122_s0_0), NULL };
static const EntityMsg* const sStep_d122_s1[] = { M(sMsg_d122_s1_0), NULL };
static const EntityMsg* const sStep_d122_s2[] = { M(sMsg_d122_s2_0), NULL };
static const EntityMsg* const sStep_d122_s3[] = { M(sMsg_d122_s3_0), NULL };
static const EntityMsg* const sStep_d122_s4[] = { M(sMsg_d122_s4_0), NULL };
static const EntityMsg* const sStep_d122_s5[] = { M(sMsg_d122_s5_0), NULL };
static const EntityMsg* const sStep_d122_s6[] = { M(sMsg_d122_s6_0), M(sMsg_d122_s6_1), NULL };
static const EntityMsg* const sStep_d122_s7[] = { M(sMsg_d122_s7_0), NULL };
static const EntityMsg* const sStep_d122_s8[] = { M(sMsg_d122_s8_0), NULL };
static const EntityMsg* const sStep_d122_s9[] = { M(sMsg_d122_s9_0), NULL };
static const EntityMsg* const sStep_d123_s0[] = { M(sMsg_d123_s0_0), NULL };
static const EntityMsg* const sStep_d123_s1[] = { M(sMsg_d123_s1_0), NULL };
static const EntityMsg* const sStep_d123_s2[] = { M(sMsg_d123_s2_0), NULL };
static const EntityMsg* const sStep_d123_s3[] = { M(sMsg_d123_s3_0), NULL };
static const EntityMsg* const sStep_d123_s4[] = { M(sMsg_d123_s4_0), NULL };
static const EntityMsg* const sStep_d123_s5[] = { M(sMsg_d123_s5_0), NULL };
static const EntityMsg* const sStep_d123_s6[] = { M(sMsg_d123_s6_0), M(sMsg_d123_s6_1), NULL };
static const EntityMsg* const sStep_d123_s7[] = { M(sMsg_d123_s7_0), NULL };
static const EntityMsg* const sStep_d123_s8[] = { M(sMsg_d123_s8_0), NULL };
static const EntityMsg* const sStep_d123_s9[] = { M(sMsg_d123_s9_0), NULL };
static const EntityMsg* const sStep_d124_s0[] = { M(sMsg_d124_s0_0), NULL };
static const EntityMsg* const sStep_d124_s1[] = { M(sMsg_d124_s1_0), NULL };
static const EntityMsg* const sStep_d124_s2[] = { M(sMsg_d124_s2_0), NULL };
static const EntityMsg* const sStep_d124_s3[] = { M(sMsg_d124_s3_0), M(sMsg_d124_s3_1), NULL };
static const EntityMsg* const sStep_d124_s4[] = { M(sMsg_d124_s4_0), M(sMsg_d124_s4_1), NULL };
static const EntityMsg* const sStep_d124_s5[] = { M(sMsg_d124_s5_0), NULL };
static const EntityMsg* const sStep_d124_s6[] = { M(sMsg_d124_s6_0), NULL };
static const EntityMsg* const sStep_d124_s7[] = { M(sMsg_d124_s7_0), M(sMsg_d124_s7_1), M(sMsg_d124_s7_2), NULL };
static const EntityMsg* const sStep_d124_s8[] = { M(sMsg_d124_s8_0), NULL };
static const EntityMsg* const sStep_d124_s9[] = { M(sMsg_d124_s9_0), NULL };
static const EntityMsg* const sStep_d124_s10[] = { M(sMsg_d124_s10_0), NULL };

/* ======== デモ (0x08DBB1C0-) ======== */

static const EntityMsg* const* const sDemo_0[] = { sStep_d0_s0, sStep_d0_s1, sStep_d0_s2, sStep_d0_s3, sStep_d0_s4, sStep_d0_s5, sStep_d0_s6, sStep_d0_s7, sStep_d0_s8, sStep_d0_s9, sStep_d0_s10, sStep_d0_s11, sStep_d0_s12, NULL };
static const EntityMsg* const* const sDemo_1[] = { sStep_d1_s0, sStep_d1_s1, sStep_d1_s2, sStep_d1_s3, sStep_d1_s4, sStep_d1_s5, sStep_d1_s6, sStep_d1_s7, sStep_d1_s8, sStep_d1_s9, sStep_d1_s10, sStep_d1_s11, sStep_d1_s12, sStep_d1_s13, sStep_d1_s14, sStep_d1_s15, sStep_d1_s16, sStep_d1_s17, sStep_d1_s18, sStep_d1_s19, sStep_d1_s20, sStep_d1_s21, sStep_d1_s22, sStep_d1_s23, sStep_d1_s24, sStep_d1_s25, sStep_d1_s26, sStep_d1_s27, sStep_d1_s28, sStep_d1_s29, sStep_d1_s30, sStep_d1_s31, sStep_d1_s32, sStep_d1_s33, sStep_d1_s34, sStep_d1_s35, sStep_d1_s36, sStep_d1_s37, sStep_d1_s38, sStep_d1_s39, sStep_d1_s40, sStep_d1_s41, sStep_d1_s42, sStep_d1_s43, sStep_d1_s44, sStep_d1_s45, sStep_d1_s46, sStep_d1_s47, sStep_d1_s48, sStep_d1_s49, sStep_d1_s50, sStep_d1_s51, sStep_d1_s52, sStep_d1_s53, sStep_d1_s54, sStep_d1_s55, sStep_d1_s56, sStep_d1_s57, sStep_d1_s58, sStep_d1_s59, sStep_d1_s60, sStep_d1_s61, sStep_d1_s62, sStep_d1_s63, sStep_d1_s64, NULL };
static const EntityMsg* const* const sDemo_2[] = { sStep_d2_s0, sStep_d2_s1, sStep_d2_s2, sStep_d2_s3, sStep_d2_s4, sStep_d2_s5, sStep_d2_s6, sStep_d2_s7, sStep_d2_s8, sStep_d2_s9, sStep_d2_s10, sStep_d2_s11, sStep_d2_s12, sStep_d2_s13, sStep_d2_s14, sStep_d2_s15, sStep_d2_s16, sStep_d2_s17, sStep_d2_s18, sStep_d2_s19, sStep_d2_s20, sStep_d2_s21, sStep_d2_s22, sStep_d2_s23, sStep_d2_s24, sStep_d2_s25, sStep_d2_s26, sStep_d2_s27, sStep_d2_s28, sStep_d2_s29, sStep_d2_s30, sStep_d2_s31, sStep_d2_s32, sStep_d2_s33, sStep_d2_s34, sStep_d2_s35, sStep_d2_s36, sStep_d2_s37, sStep_d2_s38, sStep_d2_s39, sStep_d2_s40, sStep_d2_s41, sStep_d2_s42, sStep_d2_s43, sStep_d2_s44, NULL };
static const EntityMsg* const* const sDemo_3[] = { sStep_d3_s0, sStep_d3_s1, sStep_d3_s2, sStep_d3_s3, sStep_d3_s4, sStep_d3_s5, sStep_d3_s6, sStep_d3_s7, sStep_d3_s8, sStep_d3_s9, sStep_d3_s10, sStep_d3_s11, sStep_d3_s12, sStep_d3_s13, sStep_d3_s14, sStep_d3_s15, sStep_d3_s16, sStep_d3_s17, sStep_d3_s18, sStep_d3_s19, sStep_d3_s20, sStep_d3_s21, sStep_d3_s22, sStep_d3_s23, sStep_d3_s24, NULL };
static const EntityMsg* const* const sDemo_4[] = { sStep_d4_s0, sStep_d4_s1, sStep_d4_s2, sStep_d4_s3, sStep_d4_s4, sStep_d4_s5, sStep_d4_s6, sStep_d4_s7, sStep_d4_s8, sStep_d4_s9, sStep_d4_s10, sStep_d4_s11, sStep_d4_s12, sStep_d4_s13, sStep_d4_s14, sStep_d4_s15, NULL };
static const EntityMsg* const* const sDemo_5[] = { sStep_d5_s0, sStep_d5_s1, sStep_d5_s2, sStep_d5_s3, sStep_d5_s4, sStep_d5_s5, sStep_d5_s6, sStep_d5_s7, sStep_d5_s8, sStep_d5_s9, sStep_d5_s10, sStep_d5_s11, sStep_d5_s12, sStep_d5_s13, sStep_d5_s14, sStep_d5_s15, NULL };
static const EntityMsg* const* const sDemo_6[] = { sStep_d6_s0, sStep_d6_s1, sStep_d6_s2, sStep_d6_s3, sStep_d6_s4, sStep_d6_s5, sStep_d6_s6, sStep_d6_s7, sStep_d6_s8, sStep_d6_s9, sStep_d6_s10, sStep_d6_s11, sStep_d6_s12, sStep_d6_s13, sStep_d6_s14, sStep_d6_s15, sStep_d6_s16, NULL };
static const EntityMsg* const* const sDemo_7[] = { sStep_d7_s0, sStep_d7_s1, sStep_d7_s2, sStep_d7_s3, sStep_d7_s4, sStep_d7_s5, sStep_d7_s6, sStep_d7_s7, sStep_d7_s8, sStep_d7_s9, sStep_d7_s10, sStep_d7_s11, sStep_d7_s12, sStep_d7_s13, sStep_d7_s14, sStep_d7_s15, sStep_d7_s16, sStep_d7_s17, sStep_d7_s18, sStep_d7_s19, sStep_d7_s20, sStep_d7_s21, sStep_d7_s22, sStep_d7_s23, sStep_d7_s24, sStep_d7_s25, sStep_d7_s26, sStep_d7_s27, sStep_d7_s28, sStep_d7_s29, sStep_d7_s30, sStep_d7_s31, sStep_d7_s32, sStep_d7_s33, sStep_d7_s34, sStep_d7_s35, sStep_d7_s36, sStep_d7_s37, sStep_d7_s38, sStep_d7_s39, sStep_d7_s40, sStep_d7_s41, sStep_d7_s42, sStep_d7_s43, sStep_d7_s44, sStep_d7_s45, NULL };
static const EntityMsg* const* const sDemo_8[] = { sStep_d8_s0, sStep_d8_s1, sStep_d8_s2, sStep_d8_s3, sStep_d8_s4, sStep_d8_s5, sStep_d8_s6, NULL };
static const EntityMsg* const* const sDemo_9[] = { sStep_d9_s0, sStep_d9_s1, sStep_d9_s2, sStep_d9_s3, sStep_d9_s4, sStep_d9_s5, sStep_d9_s6, sStep_d9_s7, NULL };
static const EntityMsg* const* const sDemo_10[] = { sStep_d10_s0, sStep_d10_s1, sStep_d10_s2, sStep_d10_s3, sStep_d10_s4, sStep_d10_s5, sStep_d10_s6, sStep_d10_s7, sStep_d10_s8, sStep_d10_s9, sStep_d10_s10, sStep_d10_s11, sStep_d10_s12, sStep_d10_s13, sStep_d10_s14, sStep_d10_s15, sStep_d10_s16, sStep_d10_s17, sStep_d10_s18, sStep_d10_s19, sStep_d10_s20, sStep_d10_s21, sStep_d10_s22, sStep_d10_s23, sStep_d10_s24, sStep_d10_s25, sStep_d10_s26, sStep_d10_s27, sStep_d10_s28, sStep_d10_s29, sStep_d10_s30, sStep_d10_s31, sStep_d10_s32, sStep_d10_s33, sStep_d10_s34, sStep_d10_s35, sStep_d10_s36, NULL };
static const EntityMsg* const* const sDemo_11[] = { sStep_d11_s0, sStep_d11_s1, sStep_d11_s2, sStep_d11_s3, sStep_d11_s4, sStep_d11_s5, sStep_d11_s6, sStep_d11_s7, sStep_d11_s8, sStep_d11_s9, sStep_d11_s10, sStep_d11_s11, sStep_d11_s12, sStep_d11_s13, sStep_d11_s14, sStep_d11_s15, sStep_d11_s16, sStep_d11_s17, sStep_d11_s18, sStep_d11_s19, sStep_d11_s20, sStep_d11_s21, sStep_d11_s22, sStep_d11_s23, sStep_d11_s24, sStep_d11_s25, sStep_d11_s26, sStep_d11_s27, sStep_d11_s28, sStep_d11_s29, sStep_d11_s30, sStep_d11_s31, sStep_d11_s32, sStep_d11_s33, sStep_d11_s34, sStep_d11_s35, sStep_d11_s36, sStep_d11_s37, sStep_d11_s38, sStep_d11_s39, sStep_d11_s40, NULL };
static const EntityMsg* const* const sDemo_12[] = { sStep_d12_s0, sStep_d12_s1, sStep_d12_s2, sStep_d12_s3, sStep_d12_s4, sStep_d12_s5, sStep_d12_s6, sStep_d12_s7, sStep_d12_s8, sStep_d12_s9, NULL };
static const EntityMsg* const* const sDemo_13[] = { sStep_d13_s0, sStep_d13_s1, sStep_d13_s2, sStep_d13_s3, sStep_d13_s4, sStep_d13_s5, sStep_d13_s6, sStep_d13_s7, sStep_d13_s8, sStep_d13_s9, NULL };
static const EntityMsg* const* const sDemo_14[] = { sStep_d14_s0, sStep_d14_s1, sStep_d14_s2, sStep_d14_s3, sStep_d14_s4, sStep_d14_s5, sStep_d14_s6, sStep_d14_s7, sStep_d14_s8, sStep_d14_s9, sStep_d14_s10, sStep_d14_s11, sStep_d14_s12, sStep_d14_s13, sStep_d14_s14, sStep_d14_s15, sStep_d14_s16, sStep_d14_s17, sStep_d14_s18, sStep_d14_s19, sStep_d14_s20, sStep_d14_s21, sStep_d14_s22, sStep_d14_s23, sStep_d14_s24, sStep_d14_s25, sStep_d14_s26, sStep_d14_s27, sStep_d14_s28, sStep_d14_s29, sStep_d14_s30, sStep_d14_s31, sStep_d14_s32, sStep_d14_s33, sStep_d14_s34, NULL };
static const EntityMsg* const* const sDemo_15[] = { sStep_d15_s0, sStep_d15_s1, sStep_d15_s2, sStep_d15_s3, sStep_d15_s4, sStep_d15_s5, sStep_d15_s6, sStep_d15_s7, sStep_d15_s8, sStep_d15_s9, sStep_d15_s10, sStep_d15_s11, sStep_d15_s12, sStep_d15_s13, sStep_d15_s14, sStep_d15_s15, sStep_d15_s16, sStep_d15_s17, sStep_d15_s18, sStep_d15_s19, sStep_d15_s20, sStep_d15_s21, sStep_d15_s22, sStep_d15_s23, sStep_d15_s24, sStep_d15_s25, sStep_d15_s26, sStep_d15_s27, sStep_d15_s28, sStep_d15_s29, sStep_d15_s30, sStep_d15_s31, sStep_d15_s32, sStep_d15_s33, sStep_d15_s34, sStep_d15_s35, sStep_d15_s36, sStep_d15_s37, sStep_d15_s38, sStep_d15_s39, sStep_d15_s40, NULL };
static const EntityMsg* const* const sDemo_16[] = { sStep_d16_s0, sStep_d16_s1, sStep_d16_s2, sStep_d16_s3, sStep_d16_s4, sStep_d16_s5, sStep_d16_s6, sStep_d16_s7, NULL };
static const EntityMsg* const* const sDemo_17[] = { sStep_d17_s0, sStep_d17_s1, sStep_d17_s2, sStep_d17_s3, sStep_d17_s4, sStep_d17_s5, sStep_d17_s6, sStep_d17_s7, sStep_d17_s8, sStep_d17_s9, sStep_d17_s10, sStep_d17_s11, sStep_d17_s12, NULL };
static const EntityMsg* const* const sDemo_18[] = { sStep_d18_s0, sStep_d18_s1, sStep_d18_s2, sStep_d18_s3, sStep_d18_s4, sStep_d18_s5, sStep_d18_s6, sStep_d18_s7, sStep_d18_s8, sStep_d18_s9, sStep_d18_s10, NULL };
static const EntityMsg* const* const sDemo_19[] = { sStep_d19_s0, sStep_d19_s1, sStep_d19_s2, sStep_d19_s3, sStep_d19_s4, sStep_d19_s5, sStep_d19_s6, sStep_d19_s7, sStep_d19_s8, sStep_d19_s9, sStep_d19_s10, sStep_d19_s11, sStep_d19_s12, sStep_d19_s13, sStep_d19_s14, sStep_d19_s15, sStep_d19_s16, sStep_d19_s17, sStep_d19_s18, sStep_d19_s19, NULL };
static const EntityMsg* const* const sDemo_20[] = { sStep_d20_s0, sStep_d20_s1, sStep_d20_s2, sStep_d20_s3, sStep_d20_s4, sStep_d20_s5, sStep_d20_s6, sStep_d20_s7, sStep_d20_s8, sStep_d20_s9, sStep_d20_s10, sStep_d20_s11, sStep_d20_s12, sStep_d20_s13, sStep_d20_s14, sStep_d20_s15, sStep_d20_s16, sStep_d20_s17, sStep_d20_s18, NULL };
static const EntityMsg* const* const sDemo_21[] = { sStep_d21_s0, sStep_d21_s1, sStep_d21_s2, sStep_d21_s3, sStep_d21_s4, sStep_d21_s5, sStep_d21_s6, sStep_d21_s7, sStep_d21_s8, sStep_d21_s9, sStep_d21_s10, sStep_d21_s11, sStep_d21_s12, sStep_d21_s13, sStep_d21_s14, sStep_d21_s15, sStep_d21_s16, sStep_d21_s17, sStep_d21_s18, sStep_d21_s19, sStep_d21_s20, sStep_d21_s21, sStep_d21_s22, sStep_d21_s23, sStep_d21_s24, sStep_d21_s25, sStep_d21_s26, sStep_d21_s27, sStep_d21_s28, sStep_d21_s29, sStep_d21_s30, sStep_d21_s31, NULL };
static const EntityMsg* const* const sDemo_22[] = { sStep_d22_s0, sStep_d22_s1, sStep_d22_s2, sStep_d22_s3, sStep_d22_s4, sStep_d22_s5, sStep_d22_s6, sStep_d22_s7, sStep_d22_s8, sStep_d22_s9, sStep_d22_s10, sStep_d22_s11, sStep_d22_s12, sStep_d22_s13, sStep_d22_s14, sStep_d22_s15, sStep_d22_s16, sStep_d22_s17, sStep_d22_s18, sStep_d22_s19, sStep_d22_s20, sStep_d22_s21, sStep_d22_s22, sStep_d22_s23, sStep_d22_s24, NULL };
static const EntityMsg* const* const sDemo_23[] = { sStep_d23_s0, sStep_d23_s1, sStep_d23_s2, sStep_d23_s3, sStep_d23_s4, sStep_d23_s5, sStep_d23_s6, sStep_d23_s7, sStep_d23_s8, sStep_d23_s9, sStep_d23_s10, sStep_d23_s11, sStep_d23_s12, sStep_d23_s13, sStep_d23_s14, sStep_d23_s15, NULL };
static const EntityMsg* const* const sDemo_24[] = { sStep_d24_s0, sStep_d24_s1, sStep_d24_s2, sStep_d24_s3, sStep_d24_s4, sStep_d24_s5, sStep_d24_s6, NULL };
static const EntityMsg* const* const sDemo_25[] = { sStep_d25_s0, sStep_d25_s1, sStep_d25_s2, sStep_d25_s3, sStep_d25_s4, NULL };
static const EntityMsg* const* const sDemo_26[] = { sStep_d26_s0, sStep_d26_s1, sStep_d26_s2, sStep_d26_s3, sStep_d26_s4, sStep_d26_s5, sStep_d26_s6, sStep_d26_s7, sStep_d26_s8, sStep_d26_s9, sStep_d26_s10, sStep_d26_s11, sStep_d26_s12, sStep_d26_s13, sStep_d26_s14, sStep_d26_s15, sStep_d26_s16, sStep_d26_s17, sStep_d26_s18, sStep_d26_s19, sStep_d26_s20, sStep_d26_s21, NULL };
static const EntityMsg* const* const sDemo_27[] = { sStep_d27_s0, sStep_d27_s1, sStep_d27_s2, sStep_d27_s3, sStep_d27_s4, sStep_d27_s5, sStep_d27_s6, sStep_d27_s7, sStep_d27_s8, sStep_d27_s9, sStep_d27_s10, sStep_d27_s11, sStep_d27_s12, sStep_d27_s13, sStep_d27_s14, sStep_d27_s15, sStep_d27_s16, sStep_d27_s17, sStep_d27_s18, sStep_d27_s19, sStep_d27_s20, sStep_d27_s21, sStep_d27_s22, sStep_d27_s23, sStep_d27_s24, sStep_d27_s25, sStep_d27_s26, sStep_d27_s27, sStep_d27_s28, sStep_d27_s29, sStep_d27_s30, NULL };
static const EntityMsg* const* const sDemo_28[] = { sStep_d28_s0, sStep_d28_s1, sStep_d28_s2, sStep_d28_s3, sStep_d28_s4, sStep_d28_s5, sStep_d28_s6, sStep_d28_s7, sStep_d28_s8, sStep_d28_s9, sStep_d28_s10, NULL };
static const EntityMsg* const* const sDemo_29[] = { sStep_d29_s0, sStep_d29_s1, sStep_d29_s2, sStep_d29_s3, sStep_d29_s4, sStep_d29_s5, sStep_d29_s6, sStep_d29_s7, sStep_d29_s8, sStep_d29_s9, sStep_d29_s10, sStep_d29_s11, sStep_d29_s12, sStep_d29_s13, sStep_d29_s14, sStep_d29_s15, sStep_d29_s16, sStep_d29_s17, sStep_d29_s18, sStep_d29_s19, sStep_d29_s20, sStep_d29_s21, sStep_d29_s22, sStep_d29_s23, sStep_d29_s24, sStep_d29_s25, sStep_d29_s26, sStep_d29_s27, sStep_d29_s28, sStep_d29_s29, sStep_d29_s30, sStep_d29_s31, sStep_d29_s32, sStep_d29_s33, sStep_d29_s34, sStep_d29_s35, NULL };
static const EntityMsg* const* const sDemo_30[] = { sStep_d30_s0, sStep_d30_s1, sStep_d30_s2, sStep_d30_s3, sStep_d30_s4, NULL };
static const EntityMsg* const* const sDemo_31[] = { sStep_d31_s0, sStep_d31_s1, sStep_d31_s2, sStep_d31_s3, sStep_d31_s4, sStep_d31_s5, sStep_d31_s6, sStep_d31_s7, sStep_d31_s8, sStep_d31_s9, NULL };
static const EntityMsg* const* const sDemo_32[] = { sStep_d32_s0, sStep_d32_s1, sStep_d32_s2, sStep_d32_s3, sStep_d32_s4, sStep_d32_s5, sStep_d32_s6, NULL };
static const EntityMsg* const* const sDemo_33[] = { sStep_d33_s0, sStep_d33_s1, sStep_d33_s2, sStep_d33_s3, sStep_d33_s4, sStep_d33_s5, sStep_d33_s6, sStep_d33_s7, sStep_d33_s8, sStep_d33_s9, sStep_d33_s10, NULL };
static const EntityMsg* const* const sDemo_34[] = { sStep_d34_s0, sStep_d34_s1, sStep_d34_s2, sStep_d34_s3, sStep_d34_s4, sStep_d34_s5, sStep_d34_s6, sStep_d34_s7, sStep_d34_s8, sStep_d34_s9, sStep_d34_s10, sStep_d34_s11, sStep_d34_s12, sStep_d34_s13, sStep_d34_s14, sStep_d34_s15, sStep_d34_s16, sStep_d34_s17, sStep_d34_s18, sStep_d34_s19, NULL };
static const EntityMsg* const* const sDemo_35[] = { sStep_d35_s0, sStep_d35_s1, sStep_d35_s2, sStep_d35_s3, sStep_d35_s4, sStep_d35_s5, sStep_d35_s6, sStep_d35_s7, sStep_d35_s8, sStep_d35_s9, sStep_d35_s10, sStep_d35_s11, sStep_d35_s12, sStep_d35_s13, sStep_d35_s14, sStep_d35_s15, sStep_d35_s16, sStep_d35_s17, sStep_d35_s18, sStep_d35_s19, sStep_d35_s20, NULL };
static const EntityMsg* const* const sDemo_36[] = { sStep_d36_s0, sStep_d36_s1, sStep_d36_s2, sStep_d36_s3, sStep_d36_s4, sStep_d36_s5, sStep_d36_s6, sStep_d36_s7, sStep_d36_s8, sStep_d36_s9, sStep_d36_s10, sStep_d36_s11, sStep_d36_s12, sStep_d36_s13, sStep_d36_s14, sStep_d36_s15, sStep_d36_s16, sStep_d36_s17, sStep_d36_s18, sStep_d36_s19, sStep_d36_s20, sStep_d36_s21, sStep_d36_s22, sStep_d36_s23, NULL };
static const EntityMsg* const* const sDemo_37[] = { sStep_d37_s0, sStep_d37_s1, sStep_d37_s2, sStep_d37_s3, sStep_d37_s4, sStep_d37_s5, sStep_d37_s6, NULL };
static const EntityMsg* const* const sDemo_38[] = { sStep_d38_s0, sStep_d38_s1, sStep_d38_s2, sStep_d38_s3, sStep_d38_s4, sStep_d38_s5, sStep_d38_s6, sStep_d38_s7, sStep_d38_s8, NULL };
static const EntityMsg* const* const sDemo_39[] = { sStep_d39_s0, sStep_d39_s1, sStep_d39_s2, sStep_d39_s3, sStep_d39_s4, sStep_d39_s5, sStep_d39_s6, sStep_d39_s7, sStep_d39_s8, sStep_d39_s9, sStep_d39_s10, sStep_d39_s11, NULL };
static const EntityMsg* const* const sDemo_40[] = { sStep_d40_s0, sStep_d40_s1, sStep_d40_s2, sStep_d40_s3, sStep_d40_s4, sStep_d40_s5, NULL };
static const EntityMsg* const* const sDemo_41[] = { sStep_d41_s0, sStep_d41_s1, sStep_d41_s2, sStep_d41_s3, sStep_d41_s4, sStep_d41_s5, sStep_d41_s6, sStep_d41_s7, sStep_d41_s8, sStep_d41_s9, sStep_d41_s10, sStep_d41_s11, sStep_d41_s12, sStep_d41_s13, sStep_d41_s14, sStep_d41_s15, sStep_d41_s16, sStep_d41_s17, sStep_d41_s18, sStep_d41_s19, sStep_d41_s20, NULL };
static const EntityMsg* const* const sDemo_42[] = { sStep_d42_s0, sStep_d42_s1, sStep_d42_s2, sStep_d42_s3, sStep_d42_s4, sStep_d42_s5, sStep_d42_s6, sStep_d42_s7, sStep_d42_s8, sStep_d42_s9, sStep_d42_s10, sStep_d42_s11, sStep_d42_s12, sStep_d42_s13, sStep_d42_s14, sStep_d42_s15, sStep_d42_s16, sStep_d42_s17, sStep_d42_s18, sStep_d42_s19, sStep_d42_s20, NULL };
static const EntityMsg* const* const sDemo_43[] = { sStep_d43_s0, sStep_d43_s1, sStep_d43_s2, sStep_d43_s3, sStep_d43_s4, sStep_d43_s5, sStep_d43_s6, sStep_d43_s7, sStep_d43_s8, NULL };
static const EntityMsg* const* const sDemo_44[] = { sStep_d44_s0, sStep_d44_s1, sStep_d44_s2, sStep_d44_s3, sStep_d44_s4, sStep_d44_s5, sStep_d44_s6, sStep_d44_s7, sStep_d44_s8, sStep_d44_s9, sStep_d44_s10, sStep_d44_s11, sStep_d44_s12, sStep_d44_s13, sStep_d44_s14, sStep_d44_s15, sStep_d44_s16, sStep_d44_s17, sStep_d44_s18, sStep_d44_s19, sStep_d44_s20, sStep_d44_s21, sStep_d44_s22, sStep_d44_s23, sStep_d44_s24, sStep_d44_s25, NULL };
static const EntityMsg* const* const sDemo_45[] = { sStep_d45_s0, sStep_d45_s1, sStep_d45_s2, sStep_d45_s3, sStep_d45_s4, sStep_d45_s5, sStep_d45_s6, sStep_d45_s7, sStep_d45_s8, sStep_d45_s9, sStep_d45_s10, sStep_d45_s11, NULL };
static const EntityMsg* const* const sDemo_46[] = { sStep_d46_s0, sStep_d46_s1, sStep_d46_s2, sStep_d46_s3, sStep_d46_s4, sStep_d46_s5, sStep_d46_s6, NULL };
static const EntityMsg* const* const sDemo_47[] = { sStep_d47_s0, sStep_d47_s1, sStep_d47_s2, sStep_d47_s3, sStep_d47_s4, NULL };
static const EntityMsg* const* const sDemo_48[] = { sStep_d48_s0, sStep_d48_s1, sStep_d48_s2, sStep_d48_s3, NULL };
static const EntityMsg* const* const sDemo_49[] = { sStep_d49_s0, sStep_d49_s1, sStep_d49_s2, sStep_d49_s3, NULL };
static const EntityMsg* const* const sDemo_50[] = { sStep_d50_s0, sStep_d50_s1, sStep_d50_s2, sStep_d50_s3, NULL };
static const EntityMsg* const* const sDemo_51[] = { sStep_d51_s0, sStep_d51_s1, sStep_d51_s2, sStep_d51_s3, NULL };
static const EntityMsg* const* const sDemo_52[] = { sStep_d52_s0, sStep_d52_s1, sStep_d52_s2, sStep_d52_s3, NULL };
static const EntityMsg* const* const sDemo_53[] = { sStep_d53_s0, sStep_d53_s1, sStep_d53_s2, sStep_d53_s3, sStep_d53_s4, sStep_d53_s5, sStep_d53_s6, NULL };
static const EntityMsg* const* const sDemo_54[] = { sStep_d54_s0, sStep_d54_s1, sStep_d54_s2, sStep_d54_s3, NULL };
static const EntityMsg* const* const sDemo_55[] = { sStep_d55_s0, sStep_d55_s1, sStep_d55_s2, sStep_d55_s3, sStep_d55_s4, sStep_d55_s5, sStep_d55_s6, sStep_d55_s7, sStep_d55_s8, sStep_d55_s9, sStep_d55_s10, sStep_d55_s11, sStep_d55_s12, sStep_d55_s13, sStep_d55_s14, sStep_d55_s15, sStep_d55_s16, sStep_d55_s17, sStep_d55_s18, sStep_d55_s19, sStep_d55_s20, sStep_d55_s21, sStep_d55_s22, sStep_d55_s23, sStep_d55_s24, sStep_d55_s25, sStep_d55_s26, sStep_d55_s27, sStep_d55_s28, sStep_d55_s29, sStep_d55_s30, sStep_d55_s31, sStep_d55_s32, sStep_d55_s33, sStep_d55_s34, sStep_d55_s35, sStep_d55_s36, sStep_d55_s37, sStep_d55_s38, sStep_d55_s39, sStep_d55_s40, sStep_d55_s41, sStep_d55_s42, sStep_d55_s43, sStep_d55_s44, sStep_d55_s45, sStep_d55_s46, sStep_d55_s47, sStep_d55_s48, sStep_d55_s49, sStep_d55_s50, sStep_d55_s51, sStep_d55_s52, sStep_d55_s53, sStep_d55_s54, sStep_d55_s55, NULL };
static const EntityMsg* const* const sDemo_56[] = { sStep_d56_s0, sStep_d56_s1, sStep_d56_s2, sStep_d56_s3, sStep_d56_s4, sStep_d56_s5, sStep_d56_s6, sStep_d56_s7, sStep_d56_s8, sStep_d56_s9, sStep_d56_s10, sStep_d56_s11, sStep_d56_s12, sStep_d56_s13, sStep_d56_s14, sStep_d56_s15, sStep_d56_s16, sStep_d56_s17, sStep_d56_s18, sStep_d56_s19, sStep_d56_s20, sStep_d56_s21, sStep_d56_s22, sStep_d56_s23, sStep_d56_s24, sStep_d56_s25, sStep_d56_s26, sStep_d56_s27, sStep_d56_s28, sStep_d56_s29, sStep_d56_s30, sStep_d56_s31, sStep_d56_s32, sStep_d56_s33, sStep_d56_s34, sStep_d56_s35, sStep_d56_s36, sStep_d56_s37, sStep_d56_s38, sStep_d56_s39, sStep_d56_s40, sStep_d56_s41, sStep_d56_s42, sStep_d56_s43, sStep_d56_s44, sStep_d56_s45, sStep_d56_s46, sStep_d56_s47, sStep_d56_s48, sStep_d56_s49, sStep_d56_s50, sStep_d56_s51, sStep_d56_s52, sStep_d56_s53, sStep_d56_s54, sStep_d56_s55, sStep_d56_s56, sStep_d56_s57, sStep_d56_s58, sStep_d56_s59, sStep_d56_s60, sStep_d56_s61, sStep_d56_s62, NULL };
static const EntityMsg* const* const sDemo_57[] = { sStep_d57_s0, sStep_d57_s1, sStep_d57_s2, sStep_d57_s3, NULL };
static const EntityMsg* const* const sDemo_58[] = { sStep_d58_s0, sStep_d58_s1, sStep_d58_s2, sStep_d58_s3, sStep_d58_s4, sStep_d58_s5, sStep_d58_s6, sStep_d58_s7, sStep_d58_s8, sStep_d58_s9, sStep_d58_s10, sStep_d58_s11, NULL };
static const EntityMsg* const* const sDemo_59[] = { sStep_d59_s0, sStep_d59_s1, sStep_d59_s2, sStep_d59_s3, sStep_d59_s4, sStep_d59_s5, sStep_d59_s6, sStep_d59_s7, sStep_d59_s8, sStep_d59_s9, sStep_d59_s10, sStep_d59_s11, NULL };
static const EntityMsg* const* const sDemo_60[] = { sStep_d60_s0, sStep_d60_s1, sStep_d60_s2, NULL };
static const EntityMsg* const* const sDemo_61[] = { sStep_d61_s0, sStep_d61_s1, sStep_d61_s2, NULL };
static const EntityMsg* const* const sDemo_62[] = { sStep_d62_s0, sStep_d62_s1, sStep_d62_s2, sStep_d62_s3, sStep_d62_s4, sStep_d62_s5, sStep_d62_s6, sStep_d62_s7, NULL };
static const EntityMsg* const* const sDemo_63[] = { sStep_d63_s0, sStep_d63_s1, sStep_d63_s2, sStep_d63_s3, sStep_d63_s4, sStep_d63_s5, sStep_d63_s6, sStep_d63_s7, sStep_d63_s8, sStep_d63_s9, sStep_d63_s10, sStep_d63_s11, sStep_d63_s12, sStep_d63_s13, sStep_d63_s14, sStep_d63_s15, sStep_d63_s16, sStep_d63_s17, sStep_d63_s18, sStep_d63_s19, sStep_d63_s20, sStep_d63_s21, sStep_d63_s22, sStep_d63_s23, sStep_d63_s24, sStep_d63_s25, sStep_d63_s26, sStep_d63_s27, sStep_d63_s28, sStep_d63_s29, sStep_d63_s30, sStep_d63_s31, sStep_d63_s32, sStep_d63_s33, sStep_d63_s34, sStep_d63_s35, sStep_d63_s36, sStep_d63_s37, sStep_d63_s38, sStep_d63_s39, sStep_d63_s40, sStep_d63_s41, sStep_d63_s42, sStep_d63_s43, sStep_d63_s44, sStep_d63_s45, sStep_d63_s46, sStep_d63_s47, NULL };
static const EntityMsg* const* const sDemo_64[] = { sStep_d64_s0, sStep_d64_s1, sStep_d64_s2, sStep_d64_s3, sStep_d64_s4, NULL };
static const EntityMsg* const* const sDemo_65[] = { sStep_d65_s0, sStep_d65_s1, sStep_d65_s2, sStep_d65_s3, sStep_d65_s4, sStep_d65_s5, sStep_d65_s6, sStep_d65_s7, sStep_d65_s8, sStep_d65_s9, sStep_d65_s10, sStep_d65_s11, sStep_d65_s12, sStep_d65_s13, sStep_d65_s14, sStep_d65_s15, sStep_d65_s16, NULL };
static const EntityMsg* const* const sDemo_66[] = { sStep_d66_s0, sStep_d66_s1, sStep_d66_s2, sStep_d66_s3, sStep_d66_s4, sStep_d66_s5, sStep_d66_s6, sStep_d66_s7, sStep_d66_s8, sStep_d66_s9, sStep_d66_s10, sStep_d66_s11, sStep_d66_s12, NULL };
static const EntityMsg* const* const sDemo_67[] = { sStep_d67_s0, sStep_d67_s1, sStep_d67_s2, sStep_d67_s3, sStep_d67_s4, sStep_d67_s5, sStep_d67_s6, sStep_d67_s7, sStep_d67_s8, sStep_d67_s9, sStep_d67_s10, sStep_d67_s11, sStep_d67_s12, NULL };
static const EntityMsg* const* const sDemo_68[] = { sStep_d68_s0, sStep_d68_s1, sStep_d68_s2, sStep_d68_s3, sStep_d68_s4, sStep_d68_s5, sStep_d68_s6, sStep_d68_s7, sStep_d68_s8, sStep_d68_s9, sStep_d68_s10, sStep_d68_s11, NULL };
static const EntityMsg* const* const sDemo_69[] = { sStep_d69_s0, sStep_d69_s1, sStep_d69_s2, sStep_d69_s3, sStep_d69_s4, sStep_d69_s5, sStep_d69_s6, sStep_d69_s7, sStep_d69_s8, sStep_d69_s9, sStep_d69_s10, sStep_d69_s11, sStep_d69_s12, sStep_d69_s13, sStep_d69_s14, sStep_d69_s15, sStep_d69_s16, sStep_d69_s17, sStep_d69_s18, sStep_d69_s19, sStep_d69_s20, sStep_d69_s21, NULL };
static const EntityMsg* const* const sDemo_70[] = { sStep_d70_s0, sStep_d70_s1, sStep_d70_s2, sStep_d70_s3, sStep_d70_s4, sStep_d70_s5, sStep_d70_s6, sStep_d70_s7, NULL };
static const EntityMsg* const* const sDemo_71[] = { sStep_d71_s0, sStep_d71_s1, sStep_d71_s2, sStep_d71_s3, sStep_d71_s4, sStep_d71_s5, sStep_d71_s6, sStep_d71_s7, sStep_d71_s8, sStep_d71_s9, sStep_d71_s10, sStep_d71_s11, sStep_d71_s12, sStep_d71_s13, sStep_d71_s14, sStep_d71_s15, NULL };
static const EntityMsg* const* const sDemo_72[] = { sStep_d72_s0, sStep_d72_s1, sStep_d72_s2, sStep_d72_s3, sStep_d72_s4, sStep_d72_s5, sStep_d72_s6, sStep_d72_s7, sStep_d72_s8, sStep_d72_s9, sStep_d72_s10, sStep_d72_s11, sStep_d72_s12, sStep_d72_s13, sStep_d72_s14, sStep_d72_s15, sStep_d72_s16, sStep_d72_s17, sStep_d72_s18, sStep_d72_s19, sStep_d72_s20, sStep_d72_s21, sStep_d72_s22, sStep_d72_s23, sStep_d72_s24, sStep_d72_s25, NULL };
static const EntityMsg* const* const sDemo_73[] = { sStep_d73_s0, sStep_d73_s1, sStep_d73_s2, sStep_d73_s3, sStep_d73_s4, sStep_d73_s5, sStep_d73_s6, sStep_d73_s7, sStep_d73_s8, sStep_d73_s9, sStep_d73_s10, sStep_d73_s11, sStep_d73_s12, sStep_d73_s13, sStep_d73_s14, sStep_d73_s15, sStep_d73_s16, NULL };
static const EntityMsg* const* const sDemo_74[] = { sStep_d74_s0, sStep_d74_s1, sStep_d74_s2, sStep_d74_s3, sStep_d74_s4, sStep_d74_s5, NULL };
static const EntityMsg* const* const sDemo_75[] = { sStep_d75_s0, sStep_d75_s1, sStep_d75_s2, sStep_d75_s3, sStep_d75_s4, sStep_d75_s5, sStep_d75_s6, sStep_d75_s7, sStep_d75_s8, sStep_d75_s9, sStep_d75_s10, sStep_d75_s11, sStep_d75_s12, sStep_d75_s13, sStep_d75_s14, sStep_d75_s15, sStep_d75_s16, sStep_d75_s17, sStep_d75_s18, sStep_d75_s19, sStep_d75_s20, sStep_d75_s21, sStep_d75_s22, sStep_d75_s23, sStep_d75_s24, sStep_d75_s25, sStep_d75_s26, sStep_d75_s27, sStep_d75_s28, sStep_d75_s29, sStep_d75_s30, sStep_d75_s31, sStep_d75_s32, sStep_d75_s33, sStep_d75_s34, sStep_d75_s35, sStep_d75_s36, sStep_d75_s37, sStep_d75_s38, sStep_d75_s39, sStep_d75_s40, sStep_d75_s41, sStep_d75_s42, sStep_d75_s43, sStep_d75_s44, sStep_d75_s45, sStep_d75_s46, sStep_d75_s47, sStep_d75_s48, sStep_d75_s49, sStep_d75_s50, sStep_d75_s51, sStep_d75_s52, sStep_d75_s53, sStep_d75_s54, sStep_d75_s55, sStep_d75_s56, sStep_d75_s57, sStep_d75_s58, sStep_d75_s59, sStep_d75_s60, sStep_d75_s61, sStep_d75_s62, sStep_d75_s63, sStep_d75_s64, sStep_d75_s65, sStep_d75_s66, sStep_d75_s67, sStep_d75_s68, sStep_d75_s69, sStep_d75_s70, sStep_d75_s71, sStep_d75_s72, sStep_d75_s73, sStep_d75_s74, sStep_d75_s75, sStep_d75_s76, sStep_d75_s77, sStep_d75_s78, sStep_d75_s79, sStep_d75_s80, sStep_d75_s81, sStep_d75_s82, sStep_d75_s83, sStep_d75_s84, sStep_d75_s85, sStep_d75_s86, sStep_d75_s87, sStep_d75_s88, sStep_d75_s89, sStep_d75_s90, sStep_d75_s91, sStep_d75_s92, sStep_d75_s93, sStep_d75_s94, sStep_d75_s95, sStep_d75_s96, sStep_d75_s97, sStep_d75_s98, sStep_d75_s99, sStep_d75_s100, NULL };
static const EntityMsg* const* const sDemo_76[] = { sStep_d76_s0, sStep_d76_s1, sStep_d76_s2, sStep_d76_s3, sStep_d76_s4, sStep_d76_s5, sStep_d76_s6, sStep_d76_s7, sStep_d76_s8, sStep_d76_s9, sStep_d76_s10, sStep_d76_s11, sStep_d76_s12, sStep_d76_s13, sStep_d76_s14, sStep_d76_s15, sStep_d76_s16, sStep_d76_s17, sStep_d76_s18, sStep_d76_s19, sStep_d76_s20, sStep_d76_s21, NULL };
static const EntityMsg* const* const sDemo_77[] = { sStep_d77_s0, sStep_d77_s1, sStep_d77_s2, sStep_d77_s3, sStep_d77_s4, sStep_d77_s5, sStep_d77_s6, sStep_d77_s7, sStep_d77_s8, sStep_d77_s9, sStep_d77_s10, sStep_d77_s11, sStep_d77_s12, sStep_d77_s13, sStep_d77_s14, sStep_d77_s15, sStep_d77_s16, sStep_d77_s17, sStep_d77_s18, sStep_d77_s19, sStep_d77_s20, sStep_d77_s21, sStep_d77_s22, sStep_d77_s23, sStep_d77_s24, sStep_d77_s25, sStep_d77_s26, sStep_d77_s27, sStep_d77_s28, sStep_d77_s29, sStep_d77_s30, sStep_d77_s31, sStep_d77_s32, sStep_d77_s33, sStep_d77_s34, sStep_d77_s35, NULL };
static const EntityMsg* const* const sDemo_78[] = { sStep_d78_s0, sStep_d78_s1, sStep_d78_s2, sStep_d78_s3, sStep_d78_s4, sStep_d78_s5, NULL };
static const EntityMsg* const* const sDemo_79[] = { sStep_d79_s0, sStep_d79_s1, sStep_d79_s2, sStep_d79_s3, sStep_d79_s4, sStep_d79_s5, sStep_d79_s6, sStep_d79_s7, sStep_d79_s8, NULL };
static const EntityMsg* const* const sDemo_80[] = { sStep_d80_s0, sStep_d80_s1, sStep_d80_s2, sStep_d80_s3, sStep_d80_s4, sStep_d80_s5, sStep_d80_s6, sStep_d80_s7, sStep_d80_s8, NULL };
static const EntityMsg* const* const sDemo_81[] = { sStep_d81_s0, sStep_d81_s1, sStep_d81_s2, sStep_d81_s3, sStep_d81_s4, sStep_d81_s5, sStep_d81_s6, sStep_d81_s7, sStep_d81_s8, sStep_d81_s9, sStep_d81_s10, sStep_d81_s11, sStep_d81_s12, sStep_d81_s13, sStep_d81_s14, sStep_d81_s15, sStep_d81_s16, sStep_d81_s17, sStep_d81_s18, sStep_d81_s19, NULL };
static const EntityMsg* const* const sDemo_82[] = { sStep_d82_s0, sStep_d82_s1, sStep_d82_s2, sStep_d82_s3, sStep_d82_s4, sStep_d82_s5, sStep_d82_s6, sStep_d82_s7, sStep_d82_s8, sStep_d82_s9, sStep_d82_s10, sStep_d82_s11, sStep_d82_s12, sStep_d82_s13, sStep_d82_s14, sStep_d82_s15, sStep_d82_s16, sStep_d82_s17, sStep_d82_s18, sStep_d82_s19, sStep_d82_s20, NULL };
static const EntityMsg* const* const sDemo_83[] = { sStep_d83_s0, sStep_d83_s1, sStep_d83_s2, sStep_d83_s3, sStep_d83_s4, sStep_d83_s5, sStep_d83_s6, sStep_d83_s7, sStep_d83_s8, sStep_d83_s9, sStep_d83_s10, sStep_d83_s11, sStep_d83_s12, sStep_d83_s13, sStep_d83_s14, sStep_d83_s15, sStep_d83_s16, sStep_d83_s17, sStep_d83_s18, sStep_d83_s19, NULL };
static const EntityMsg* const* const sDemo_84[] = { sStep_d84_s0, sStep_d84_s1, sStep_d84_s2, sStep_d84_s3, sStep_d84_s4, sStep_d84_s5, sStep_d84_s6, sStep_d84_s7, sStep_d84_s8, sStep_d84_s9, sStep_d84_s10, sStep_d84_s11, sStep_d84_s12, sStep_d84_s13, sStep_d84_s14, sStep_d84_s15, sStep_d84_s16, sStep_d84_s17, sStep_d84_s18, sStep_d84_s19, sStep_d84_s20, NULL };
static const EntityMsg* const* const sDemo_85[] = { sStep_d85_s0, sStep_d85_s1, sStep_d85_s2, sStep_d85_s3, sStep_d85_s4, sStep_d85_s5, sStep_d85_s6, sStep_d85_s7, sStep_d85_s8, sStep_d85_s9, sStep_d85_s10, sStep_d85_s11, sStep_d85_s12, sStep_d85_s13, sStep_d85_s14, sStep_d85_s15, sStep_d85_s16, NULL };
static const EntityMsg* const* const sDemo_86[] = { sStep_d86_s0, sStep_d86_s1, sStep_d86_s2, sStep_d86_s3, sStep_d86_s4, sStep_d86_s5, sStep_d86_s6, sStep_d86_s7, sStep_d86_s8, sStep_d86_s9, sStep_d86_s10, sStep_d86_s11, sStep_d86_s12, NULL };
static const EntityMsg* const* const sDemo_87[] = { sStep_d87_s0, sStep_d87_s1, sStep_d87_s2, sStep_d87_s3, sStep_d87_s4, sStep_d87_s5, NULL };
static const EntityMsg* const* const sDemo_88[] = { sStep_d88_s0, sStep_d88_s1, sStep_d88_s2, sStep_d88_s3, sStep_d88_s4, sStep_d88_s5, sStep_d88_s6, NULL };
static const EntityMsg* const* const sDemo_89[] = { sStep_d89_s0, sStep_d89_s1, sStep_d89_s2, sStep_d89_s3, sStep_d89_s4, sStep_d89_s5, NULL };
static const EntityMsg* const* const sDemo_90[] = { sStep_d90_s0, sStep_d90_s1, sStep_d90_s2, sStep_d90_s3, sStep_d90_s4, sStep_d90_s5, sStep_d90_s6, sStep_d90_s7, sStep_d90_s8, sStep_d90_s9, sStep_d90_s10, sStep_d90_s11, sStep_d90_s12, sStep_d90_s13, sStep_d90_s14, sStep_d90_s15, sStep_d90_s16, sStep_d90_s17, sStep_d90_s18, sStep_d90_s19, sStep_d90_s20, sStep_d90_s21, sStep_d90_s22, sStep_d90_s23, sStep_d90_s24, sStep_d90_s25, sStep_d90_s26, sStep_d90_s27, sStep_d90_s28, sStep_d90_s29, sStep_d90_s30, sStep_d90_s31, sStep_d90_s32, sStep_d90_s33, sStep_d90_s34, sStep_d90_s35, sStep_d90_s36, sStep_d90_s37, sStep_d90_s38, sStep_d90_s39, sStep_d90_s40, sStep_d90_s41, sStep_d90_s42, sStep_d90_s43, sStep_d90_s44, sStep_d90_s45, NULL };
static const EntityMsg* const* const sDemo_91[] = { sStep_d91_s0, sStep_d91_s1, sStep_d91_s2, sStep_d91_s3, sStep_d91_s4, sStep_d91_s5, sStep_d91_s6, sStep_d91_s7, sStep_d91_s8, sStep_d91_s9, sStep_d91_s10, sStep_d91_s11, sStep_d91_s12, sStep_d91_s13, sStep_d91_s14, sStep_d91_s15, sStep_d91_s16, sStep_d91_s17, sStep_d91_s18, sStep_d91_s19, sStep_d91_s20, sStep_d91_s21, sStep_d91_s22, sStep_d91_s23, sStep_d91_s24, sStep_d91_s25, sStep_d91_s26, sStep_d91_s27, sStep_d91_s28, sStep_d91_s29, sStep_d91_s30, sStep_d91_s31, sStep_d91_s32, sStep_d91_s33, sStep_d91_s34, sStep_d91_s35, sStep_d91_s36, sStep_d91_s37, sStep_d91_s38, sStep_d91_s39, sStep_d91_s40, sStep_d91_s41, sStep_d91_s42, sStep_d91_s43, sStep_d91_s44, sStep_d91_s45, NULL };
static const EntityMsg* const* const sDemo_92[] = { sStep_d92_s0, sStep_d92_s1, sStep_d92_s2, sStep_d92_s3, sStep_d92_s4, sStep_d92_s5, sStep_d92_s6, sStep_d92_s7, sStep_d92_s8, sStep_d92_s9, sStep_d92_s10, sStep_d92_s11, sStep_d92_s12, sStep_d92_s13, sStep_d92_s14, sStep_d92_s15, sStep_d92_s16, sStep_d92_s17, sStep_d92_s18, sStep_d92_s19, sStep_d92_s20, NULL };
static const EntityMsg* const* const sDemo_93[] = { sStep_d93_s0, sStep_d93_s1, sStep_d93_s2, sStep_d93_s3, sStep_d93_s4, sStep_d93_s5, sStep_d93_s6, sStep_d93_s7, sStep_d93_s8, sStep_d93_s9, sStep_d93_s10, sStep_d93_s11, sStep_d93_s12, sStep_d93_s13, NULL };
static const EntityMsg* const* const sDemo_94[] = { sStep_d94_s0, sStep_d94_s1, sStep_d94_s2, sStep_d94_s3, sStep_d94_s4, sStep_d94_s5, sStep_d94_s6, sStep_d94_s7, NULL };
static const EntityMsg* const* const sDemo_95[] = { sStep_d95_s0, sStep_d95_s1, sStep_d95_s2, sStep_d95_s3, sStep_d95_s4, sStep_d95_s5, sStep_d95_s6, sStep_d95_s7, NULL };
static const EntityMsg* const* const sDemo_96[] = { sStep_d96_s0, sStep_d96_s1, sStep_d96_s2, sStep_d96_s3, sStep_d96_s4, sStep_d96_s5, sStep_d96_s6, sStep_d96_s7, sStep_d96_s8, sStep_d96_s9, sStep_d96_s10, sStep_d96_s11, sStep_d96_s12, sStep_d96_s13, NULL };
static const EntityMsg* const* const sDemo_97[] = { sStep_d97_s0, sStep_d97_s1, sStep_d97_s2, sStep_d97_s3, sStep_d97_s4, sStep_d97_s5, sStep_d97_s6, sStep_d97_s7, NULL };
static const EntityMsg* const* const sDemo_98[] = { sStep_d98_s0, sStep_d98_s1, sStep_d98_s2, NULL };
static const EntityMsg* const* const sDemo_99[] = { sStep_d99_s0, sStep_d99_s1, sStep_d99_s2, sStep_d99_s3, sStep_d99_s4, NULL };
static const EntityMsg* const* const sDemo_100[] = { sStep_d100_s0, sStep_d100_s1, sStep_d100_s2, sStep_d100_s3, sStep_d100_s4, sStep_d100_s5, sStep_d100_s6, NULL };
static const EntityMsg* const* const sDemo_101[] = { sStep_d101_s0, sStep_d101_s1, sStep_d101_s2, NULL };
static const EntityMsg* const* const sDemo_102[] = { sStep_d102_s0, sStep_d102_s1, sStep_d102_s2, sStep_d102_s3, sStep_d102_s4, sStep_d102_s5, sStep_d102_s6, sStep_d102_s7, sStep_d102_s8, sStep_d102_s9, sStep_d102_s10, sStep_d102_s11, sStep_d102_s12, sStep_d102_s13, sStep_d102_s14, sStep_d102_s15, sStep_d102_s16, sStep_d102_s17, sStep_d102_s18, sStep_d102_s19, sStep_d102_s20, sStep_d102_s21, sStep_d102_s22, sStep_d102_s23, sStep_d102_s24, sStep_d102_s25, sStep_d102_s26, sStep_d102_s27, sStep_d102_s28, sStep_d102_s29, sStep_d102_s30, sStep_d102_s31, sStep_d102_s32, sStep_d102_s33, sStep_d102_s34, sStep_d102_s35, sStep_d102_s36, NULL };
static const EntityMsg* const* const sDemo_103[] = { sStep_d103_s0, sStep_d103_s1, sStep_d103_s2, sStep_d103_s3, sStep_d103_s4, sStep_d103_s5, sStep_d103_s6, sStep_d103_s7, sStep_d103_s8, sStep_d103_s9, sStep_d103_s10, sStep_d103_s11, sStep_d103_s12, sStep_d103_s13, sStep_d103_s14, sStep_d103_s15, sStep_d103_s16, sStep_d103_s17, sStep_d103_s18, sStep_d103_s19, sStep_d103_s20, NULL };
static const EntityMsg* const* const sDemo_104[] = { sStep_d104_s0, sStep_d104_s1, sStep_d104_s2, sStep_d104_s3, sStep_d104_s4, sStep_d104_s5, sStep_d104_s6, sStep_d104_s7, sStep_d104_s8, sStep_d104_s9, sStep_d104_s10, sStep_d104_s11, NULL };
static const EntityMsg* const* const sDemo_105[] = { sStep_d105_s0, sStep_d105_s1, sStep_d105_s2, sStep_d105_s3, sStep_d105_s4, sStep_d105_s5, sStep_d105_s6, sStep_d105_s7, sStep_d105_s8, sStep_d105_s9, sStep_d105_s10, sStep_d105_s11, NULL };
static const EntityMsg* const* const sDemo_106[] = { sStep_d106_s0, sStep_d106_s1, sStep_d106_s2, sStep_d106_s3, sStep_d106_s4, sStep_d106_s5, sStep_d106_s6, sStep_d106_s7, sStep_d106_s8, sStep_d106_s9, sStep_d106_s10, sStep_d106_s11, sStep_d106_s12, sStep_d106_s13, sStep_d106_s14, NULL };
static const EntityMsg* const* const sDemo_107[] = { sStep_d107_s0, sStep_d107_s1, sStep_d107_s2, sStep_d107_s3, sStep_d107_s4, sStep_d107_s5, sStep_d107_s6, sStep_d107_s7, sStep_d107_s8, sStep_d107_s9, sStep_d107_s10, sStep_d107_s11, sStep_d107_s12, sStep_d107_s13, sStep_d107_s14, NULL };
static const EntityMsg* const* const sDemo_108[] = { sStep_d108_s0, sStep_d108_s1, sStep_d108_s2, sStep_d108_s3, sStep_d108_s4, sStep_d108_s5, sStep_d108_s6, sStep_d108_s7, sStep_d108_s8, sStep_d108_s9, sStep_d108_s10, sStep_d108_s11, sStep_d108_s12, sStep_d108_s13, sStep_d108_s14, NULL };
static const EntityMsg* const* const sDemo_109[] = { sStep_d109_s0, sStep_d109_s1, sStep_d109_s2, sStep_d109_s3, sStep_d109_s4, sStep_d109_s5, sStep_d109_s6, sStep_d109_s7, sStep_d109_s8, sStep_d109_s9, sStep_d109_s10, sStep_d109_s11, sStep_d109_s12, sStep_d109_s13, NULL };
static const EntityMsg* const* const sDemo_110[] = { sStep_d110_s0, sStep_d110_s1, sStep_d110_s2, sStep_d110_s3, sStep_d110_s4, sStep_d110_s5, sStep_d110_s6, sStep_d110_s7, sStep_d110_s8, sStep_d110_s9, sStep_d110_s10, sStep_d110_s11, sStep_d110_s12, sStep_d110_s13, sStep_d110_s14, sStep_d110_s15, sStep_d110_s16, sStep_d110_s17, sStep_d110_s18, NULL };
static const EntityMsg* const* const sDemo_111[] = { sStep_d111_s0, sStep_d111_s1, sStep_d111_s2, sStep_d111_s3, sStep_d111_s4, sStep_d111_s5, sStep_d111_s6, sStep_d111_s7, sStep_d111_s8, sStep_d111_s9, sStep_d111_s10, sStep_d111_s11, sStep_d111_s12, sStep_d111_s13, sStep_d111_s14, sStep_d111_s15, sStep_d111_s16, sStep_d111_s17, sStep_d111_s18, NULL };
static const EntityMsg* const* const sDemo_112[] = { sStep_d112_s0, sStep_d112_s1, sStep_d112_s2, sStep_d112_s3, sStep_d112_s4, sStep_d112_s5, sStep_d112_s6, sStep_d112_s7, sStep_d112_s8, sStep_d112_s9, sStep_d112_s10, sStep_d112_s11, sStep_d112_s12, sStep_d112_s13, sStep_d112_s14, sStep_d112_s15, sStep_d112_s16, sStep_d112_s17, sStep_d112_s18, sStep_d112_s19, NULL };
static const EntityMsg* const* const sDemo_113[] = { sStep_d113_s0, sStep_d113_s1, sStep_d113_s2, sStep_d113_s3, sStep_d113_s4, sStep_d113_s5, sStep_d113_s6, sStep_d113_s7, sStep_d113_s8, sStep_d113_s9, sStep_d113_s10, sStep_d113_s11, sStep_d113_s12, sStep_d113_s13, sStep_d113_s14, sStep_d113_s15, sStep_d113_s16, sStep_d113_s17, sStep_d113_s18, NULL };
static const EntityMsg* const* const sDemo_114[] = { sStep_d114_s0, sStep_d114_s1, sStep_d114_s2, sStep_d114_s3, sStep_d114_s4, sStep_d114_s5, sStep_d114_s6, sStep_d114_s7, sStep_d114_s8, sStep_d114_s9, sStep_d114_s10, sStep_d114_s11, sStep_d114_s12, sStep_d114_s13, sStep_d114_s14, sStep_d114_s15, sStep_d114_s16, sStep_d114_s17, sStep_d114_s18, NULL };
static const EntityMsg* const* const sDemo_115[] = { sStep_d115_s0, sStep_d115_s1, sStep_d115_s2, sStep_d115_s3, sStep_d115_s4, sStep_d115_s5, sStep_d115_s6, sStep_d115_s7, sStep_d115_s8, sStep_d115_s9, sStep_d115_s10, sStep_d115_s11, sStep_d115_s12, sStep_d115_s13, sStep_d115_s14, sStep_d115_s15, sStep_d115_s16, sStep_d115_s17, sStep_d115_s18, sStep_d115_s19, NULL };
static const EntityMsg* const* const sDemo_116[] = { sStep_d116_s0, sStep_d116_s1, sStep_d116_s2, sStep_d116_s3, sStep_d116_s4, sStep_d116_s5, NULL };
static const EntityMsg* const* const sDemo_117[] = { sStep_d117_s0, sStep_d117_s1, sStep_d117_s2, sStep_d117_s3, sStep_d117_s4, sStep_d117_s5, sStep_d117_s6, sStep_d117_s7, sStep_d117_s8, NULL };
static const EntityMsg* const* const sDemo_118[] = { sStep_d118_s0, sStep_d118_s1, sStep_d118_s2, sStep_d118_s3, sStep_d118_s4, sStep_d118_s5, NULL };
static const EntityMsg* const* const sDemo_119[] = { sStep_d119_s0, sStep_d119_s1, sStep_d119_s2, sStep_d119_s3, sStep_d119_s4, sStep_d119_s5, sStep_d119_s6, sStep_d119_s7, sStep_d119_s8, sStep_d119_s9, sStep_d119_s10, sStep_d119_s11, sStep_d119_s12, sStep_d119_s13, sStep_d119_s14, NULL };
static const EntityMsg* const* const sDemo_120[] = { sStep_d120_s0, sStep_d120_s1, sStep_d120_s2, sStep_d120_s3, sStep_d120_s4, sStep_d120_s5, sStep_d120_s6, sStep_d120_s7, sStep_d120_s8, sStep_d120_s9, sStep_d120_s10, sStep_d120_s11, sStep_d120_s12, sStep_d120_s13, sStep_d120_s14, NULL };
static const EntityMsg* const* const sDemo_121[] = { sStep_d121_s0, sStep_d121_s1, sStep_d121_s2, sStep_d121_s3, NULL };
static const EntityMsg* const* const sDemo_122[] = { sStep_d122_s0, sStep_d122_s1, sStep_d122_s2, sStep_d122_s3, sStep_d122_s4, sStep_d122_s5, sStep_d122_s6, sStep_d122_s7, sStep_d122_s8, sStep_d122_s9, NULL };
static const EntityMsg* const* const sDemo_123[] = { sStep_d123_s0, sStep_d123_s1, sStep_d123_s2, sStep_d123_s3, sStep_d123_s4, sStep_d123_s5, sStep_d123_s6, sStep_d123_s7, sStep_d123_s8, sStep_d123_s9, NULL };
static const EntityMsg* const* const sDemo_124[] = { sStep_d124_s0, sStep_d124_s1, sStep_d124_s2, sStep_d124_s3, sStep_d124_s4, sStep_d124_s5, sStep_d124_s6, sStep_d124_s7, sStep_d124_s8, sStep_d124_s9, sStep_d124_s10, NULL };

/* ======== デモ表 (0x08DBD564-) ======== */

const EntityMsg* const* const* const gDemoTable[125] = {
    sDemo_0, sDemo_1, sDemo_2, sDemo_3, sDemo_4,
    sDemo_5, sDemo_6, sDemo_7, sDemo_8, sDemo_9,
    sDemo_10, sDemo_11, sDemo_12, sDemo_13, sDemo_14,
    sDemo_15, sDemo_16, sDemo_17, sDemo_18, sDemo_19,
    sDemo_20, sDemo_21, sDemo_22, sDemo_23, sDemo_24,
    sDemo_25, sDemo_26, sDemo_27, sDemo_28, sDemo_29,
    sDemo_30, sDemo_31, sDemo_32, sDemo_33, sDemo_34,
    sDemo_35, sDemo_36, sDemo_37, sDemo_38, sDemo_39,
    sDemo_40, sDemo_41, sDemo_42, sDemo_43, sDemo_44,
    sDemo_45, sDemo_46, sDemo_47, sDemo_48, sDemo_49,
    sDemo_50, sDemo_51, sDemo_52, sDemo_53, sDemo_54,
    sDemo_55, sDemo_56, sDemo_57, sDemo_58, sDemo_59,
    sDemo_60, sDemo_61, sDemo_62, sDemo_63, sDemo_64,
    sDemo_65, sDemo_66, sDemo_67, sDemo_68, sDemo_69,
    sDemo_70, sDemo_71, sDemo_72, sDemo_73, sDemo_74,
    sDemo_75, sDemo_76, sDemo_77, sDemo_78, sDemo_79,
    sDemo_80, sDemo_81, sDemo_82, sDemo_83, sDemo_84,
    sDemo_85, sDemo_86, sDemo_87, sDemo_88, sDemo_89,
    sDemo_90, sDemo_91, sDemo_92, sDemo_93, sDemo_94,
    sDemo_95, sDemo_96, sDemo_97, sDemo_98, sDemo_99,
    sDemo_100, sDemo_101, sDemo_102, sDemo_103, sDemo_104,
    sDemo_105, sDemo_106, sDemo_107, sDemo_108, sDemo_109,
    sDemo_110, sDemo_111, sDemo_112, sDemo_113, sDemo_114,
    sDemo_115, sDemo_116, sDemo_117, sDemo_118, sDemo_119,
    sDemo_120, sDemo_121, sDemo_122, sDemo_123, sDemo_124,
};

// clang-format on
