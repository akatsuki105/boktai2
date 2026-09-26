#include "entity.h"
#include "global.h"

// スクリプト命令 0xD53D が作る失敗画面, 全画面のタイルマップとパレットを読み込み、SE_NG を鳴らしてメッセージを出し、最後に scriptID のスクリプトを起動する
typedef struct EntityD53D {
  Entity e;       // 0x00, ENTITY_UNK_12
  u8 state;       // 0x18, EntityD53D_Update が PTR_ARRAY_085AB664 (ハンドラ4件) の添字にして呼び出す
  u8 enter;       // 0x19, state が変わるたび 1, 各ハンドラが最初のフレームで 0 に戻す
  u8 unk_1a[2];   // 0x1A, padding?
  u32 timer;      // 0x1C, 毎フレーム +1、state が変わると 0
  s32 windowID;   // 0x20, TextPanel_Create の戻り値, なければ -1, _Destroy が TextPanel_Destroy に渡して解放する
  void* tilemap;  // 0x24, GetFile(TILE_MAP, ...) の戻り値, Video_SetupBGLayout に渡す
  u8* msgPc;      // 0x28, _Init 時点の VM_GetPC(), TextPanel_SetScript(windowID, msgPc) に渡す
  s32 scriptID;   // 0x2C, '.r=0', state 3 が Script_ExecById に渡す
} EntityD53D;
static_assert(sizeof(EntityD53D) == 48);

extern EntityD53D* gEntityD53D;  // 0x030000E8

INCASM("asm/entity_d53d.inc");
