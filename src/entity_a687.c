#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// ソル・デ・バイス を受け取るときにジャンゴの1枚絵 (SPR_DJANGO_LARGE) を表示するが、その間に背景をある程度暗くする演出用のエンティティ (それ以外では使用されない)
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_9
  u32 timer;          // 0x18, state 1 で数え上げ holdFrames と比べる, 状態が変わるたびに 0 に戻る
  u32 minBrightness;  // 0x1C, '.r=32', state 0 が brightness をここまで 2 ずつ下げる
  u32 holdFrames;     // 0x20, '.e=120', state 1 が保つ長さ
  u32 brightness;     // 0x24, 毎フレーム gBgBrightness2 と gObjBrightness へ書く, Q6(1) が等倍
  u32 state;          // 0x28, 0 で暗転、1 で保持、2 で 64 まで戻して KillEntity する
} BgPlttDimmer;
static_assert(sizeof(BgPlttDimmer) == 44);

s32 BgPlttDimmer_Update(BgPlttDimmer* p) {
  switch (p->state) {
    case 0: {
      if (p->brightness > p->minBrightness) {
        p->brightness -= 2;
      } else {
        p->brightness = p->minBrightness;
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 1: {
      if (++p->timer >= p->holdFrames) {
        p->state = 2;
        p->timer = 0;
      }
      break;
    }
    case 2: {
      if (p->brightness < Q6(1)) {
        p->brightness += 2;
      } else {
        p->brightness = Q6(1);
        p->state = 3;
        p->timer = 0;
        KillEntity(&p->e);
      }
      break;
    }
  }
  gBgBrightness2 = p->brightness;
  gBgPlttFadeRowMask = 0x1FFF;
  gBgPlttBlendColor = RGB(4, 4, 4);
  gObjBrightness = p->brightness;
  gObjPlttFadeSkipMask = 0x20;
  gObjPlttBlendColor = RGB(4, 4, 4);
  return 0;
}

s32 BgPlttDimmer_Destroy(BgPlttDimmer* p) {
  gBgBrightness2 = Q6(1);
  gBgPlttFadeRowMask = 0x1FFF;
  gBgPlttBlendColor = RGB(4, 4, 4);
  gObjBrightness = Q6(1);
  gObjPlttFadeSkipMask = 0;
  gObjPlttBlendColor = RGB(4, 4, 4);
  return 0;
}

s32 BgPlttDimmer_Init(BgPlttDimmer* p) {
  p->minBrightness = VM_GetNamedArgValue('r', 32);
  p->holdFrames = VM_GetNamedArgValue('e', 120);
  return 0;
}

BgPlttDimmer* BgPlttDimmer_Create(void) {
  BgPlttDimmer* p = CreateEntity(ENTITY_UNK_9, sizeof(BgPlttDimmer));

  if (p != NULL) {
    SetEntityRoutine(p, BgPlttDimmer_Update, BgPlttDimmer_Destroy);
    if (BgPlttDimmer_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
