#include "entity.h"
#include "global.h"
#include "video.h"

// BG パレットを丸ごと控えておき、控えたバンク 0..6 を 4 フレームごとに順にバンク 0 へ書き戻す (7 フレームのパレットアニメ)
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_12
  s32 timer;              // 0x18, 毎フレーム +1、3 を超えたら 0 に戻す
  s32 frame;              // 0x1C, timer が一周するたび +1、6 を超えたら 0 に戻す
  rgb555 savedPltt[256];  // 0x20, BgPlttAnimator_SavePltt が gBgPlttBuffer 全体 (128 ワード) をコピーする
} BgPlttAnimator;
static_assert(sizeof(BgPlttAnimator) == 544);

bool32 FUN_0800271c(void);

void BgPlttAnimator_SavePltt(BgPlttAnimator* p) { CpuCopy32(gBgPlttBuffer, p->savedPltt, sizeof(p->savedPltt)); }

// 4 フレームごとに控えたバンクを1つ進めてバンク 0 へ書き戻す
s32 BgPlttAnimator_Update(BgPlttAnimator* p) {
  s32 i;

  if (FUN_0800271c()) {
    BgPlttAnimator_SavePltt(p);
  }

  p->timer++;
  if (p->timer > 3) {
    p->timer = 0;
    p->frame++;
    if (p->frame > 6) {
      p->frame = 0;
    }
    for (i = 0; i < 16; i++) {
      gBgPlttBuffer[i] = p->savedPltt[p->frame * 16 + i];
    }
  }
  return 0;
}

s32 BgPlttAnimator_Destroy(BgPlttAnimator* p) { return 0; }

s32 BgPlttAnimator_Init(BgPlttAnimator* p) {
  BgPlttAnimator_SavePltt(p);
  return 0;
}

BgPlttAnimator* BgPlttAnimator_Create(void) {
  BgPlttAnimator* p = CreateEntity(ENTITY_UNK_12, sizeof(BgPlttAnimator));

  if (p != NULL) {
    SetEntityRoutine(p, BgPlttAnimator_Update, BgPlttAnimator_Destroy);
    if (BgPlttAnimator_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
