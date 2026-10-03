#include "entity.h"
#include "global.h"
#include "tilemap.h"

// スクリプト命令 0xD53D が作る失敗画面, 全画面のタイルマップとパレットを読み込み、SE_NG を鳴らしてメッセージを出し、最後に scriptID のスクリプトを起動する
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_12
  u8 state;           // 0x18, sEntityD53DUpdates[state]
  u8 enter;           // 0x19, state が変わるたび 1, 各ハンドラが最初のフレームで 0 に戻す
  u8 unk_1a[2];       // 0x1A, padding?
  u32 timer;          // 0x1C, 毎フレーム +1、state が変わると 0
  s32 windowID;       // 0x20, TextPanel_Create の戻り値, なければ -1, _Destroy が TextPanel_Destroy に渡して解放する
  Tilemaps* tilemap;  // 0x24
  u8* msgPc;          // 0x28, _Init 時点の VM_GetPC(), TextPanel_SetScript(windowID, msgPc) に渡す
  s32 scriptID;       // 0x2C, '.r=0', state 3 が VM_ExecByID に渡す
} EntityD53D;
static_assert(sizeof(EntityD53D) == 48);

IWRAM_DATA EntityD53D* gEntityD53D = NULL;  // 0x030000E8

NAKED void FUN_0804e9f4(s16 param_1, s16 param_2) { INCFUNC("asm/func/FUN_0804e9f4.inc"); }

EntityD53D* FUN_0804ea10(void) { return gEntityD53D; }

NAKED void FUN_0804ea1c(void) { INCFUNC("asm/func/FUN_0804ea1c.inc"); }

NAKED void FUN_0804ea68(EntityD53D* p, s32 param_2) { INCFUNC("asm/func/FUN_0804ea68.inc"); }

NAKED void FUN_0804ead0(EntityD53D* p, s32 param_2) { INCFUNC("asm/func/FUN_0804ead0.inc"); }

NAKED void FUN_0804eb38(EntityD53D* p) { INCFUNC("asm/func/FUN_0804eb38.inc"); }

NAKED void FUN_0804eb50(EntityD53D* p) { INCFUNC("asm/func/FUN_0804eb50.inc"); }

NAKED void FUN_0804ebc4(EntityD53D* p) { INCFUNC("asm/func/FUN_0804ebc4.inc"); }

NAKED void FUN_0804ec58(EntityD53D* p) { INCFUNC("asm/func/FUN_0804ec58.inc"); }

void (*const sEntityD53DUpdates[4])(EntityD53D*) = {
    FUN_0804eb38,
    FUN_0804eb50,
    FUN_0804ebc4,
    FUN_0804ec58,
};  // 0x085AB664

NAKED s32 EntityD53D_Update(EntityD53D* p) { INCFUNC("asm/func/EntityD53D_Update.inc"); }

NAKED s32 EntityD53D_Destroy(EntityD53D* p) { INCFUNC("asm/func/EntityD53D_Destroy.inc"); }

NAKED s32 EntityD53D_Init(EntityD53D* p) { INCFUNC("asm/func/EntityD53D_Init.inc"); }

NAKED EntityD53D* EntityD53D_Create(void) { INCFUNC("asm/func/EntityD53D_Create.inc"); }
