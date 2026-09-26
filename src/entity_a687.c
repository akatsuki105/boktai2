#include "entity.h"
#include "global.h"
#include "vm.h"

// 画面を暗くして一定時間保ち、元の明るさへ戻して自滅する演出, brightness は FUN_0822d630 が読む明るさ係数
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_9
  s32 timer;          // 0x18, state 1 で数え上げ holdFrames と比べる, 状態が変わるたびに 0 に戻る
  s32 minBrightness;  // 0x1C, '.r=32', state 0 が brightness をここまで 2 ずつ下げる
  s32 holdFrames;     // 0x20, '.e=120', state 1 が保つ長さ
  s32 brightness;     // 0x24, 毎フレーム s32_03004460 と s32_0300445c へ書く, FRACUNIT_6 (64) が等倍
  s32 state;          // 0x28, 0 で暗転、1 で保持、2 で 64 まで戻して KillEntity する
} BgPlttDimmer;
static_assert(sizeof(BgPlttDimmer) == 44);

NAKED s32 BgPlttDimmer_Update(BgPlttDimmer* p) { INCFUNC("asm/func/BgPlttDimmer_Update.inc"); }

NAKED s32 BgPlttDimmer_Destroy(BgPlttDimmer* p) { INCFUNC("asm/func/BgPlttDimmer_Destroy.inc"); }

s32 BgPlttDimmer_Init(BgPlttDimmer* p) {
  p->minBrightness = VM_GetKeywordValue('r', 32);
  p->holdFrames = VM_GetKeywordValue('e', 120);
  return 0;
}

NAKED BgPlttDimmer* BgPlttDimmer_Create(void) { INCFUNC("asm/func/BgPlttDimmer_Create.inc"); }
