#include "entity.h"
#include "global.h"

// スクリプト命令 0xB0BC が作るセーブ処理。メッセージを出して 60 フレーム目に Save_WriteToNextSlot を実行し、
// 結果のメッセージに差し替えたあと、結果を引数にしてスクリプトを起動して自滅する
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_11
  s32 windowID;  // 0x18, TextPanel_Create(1, 0xD, 0x1C, 6) の戻り値。失敗時は -1。_Destroy が TextPanel_Destroy に渡す
  s32 scriptID;  // 0x1C, VM_GetKeywordValue('e', 0)。result を唯一の引数にして Script_ExecById へ渡したあと 0 に戻す
  s32 timer;     // 0x20, 毎フレーム +1。60 でセーブ実行、120 以降は A で進める、300 で打ち切る
  s32 result;    // 0x24, セーブ実行までは -1。Save_WriteToNextSlot の戻り値で、1 ならメッセージ 0xE、それ以外は 0xF
  u8* msgPc;     // 0x28, _Init 時点の VM_GetPC()。TextPanel_SetScript(windowID, msgPc) に渡す
} SaveSequence;
static_assert(sizeof(SaveSequence) == 44);

INCASM("asm/entity_b0bc.inc");
