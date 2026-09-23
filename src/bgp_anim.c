#include "entity.h"
#include "global.h"

// BG パレットを丸ごと控えておき、控えたバンク 0..6 を 4 フレームごとに順にバンク 0 へ書き戻す (7 フレームのパレットアニメ)
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_12
  s32 timer;              // 0x18, 毎フレーム +1、3 を超えたら 0 に戻す
  s32 frame;              // 0x1C, timer が一周するたび +1、6 を超えたら 0 に戻す
  rgb555 savedPltt[256];  // 0x20, BgPlttAnimator_SavePltt が gBgPlttBuffer 全体 (128 ワード) をコピーする
} BgPlttAnimator;
static_assert(sizeof(BgPlttAnimator) == 544);

NAKED void BgPlttAnimator_SavePltt(BgPlttAnimator* p) { INCFUNC("asm/func/BgPlttAnimator_SavePltt.inc"); }

NAKED s32 BgPlttAnimator_Update(BgPlttAnimator* p) { INCFUNC("asm/func/BgPlttAnimator_Update.inc"); }

s32 BgPlttAnimator_Destroy(BgPlttAnimator* p) { return 0; }

s32 BgPlttAnimator_Init(BgPlttAnimator* p) {
  BgPlttAnimator_SavePltt(p);
  return 0;
}

NAKED BgPlttAnimator* BgPlttAnimator_Create(void) { INCFUNC("asm/func/BgPlttAnimator_Create.inc"); }
