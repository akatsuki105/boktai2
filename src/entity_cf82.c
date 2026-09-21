#include "entity.h"
#include "global.h"
#include "video.h"

// BG パレット 2 の色 8-11 を 1 色ずつ消したり点けたりして光が寄せては返すように見せる
typedef struct {
  Entity e;  // 0x00, ENTITY_UNK_12
  u8 step;   // 0x18, 0..7。点灯している色数を決める。0-3 が消していく側、4-7 が点けていく側
  u8 timer;  // 0x19, 毎フレーム +1。sEntityCF82StepDurations[step] に達したら step を進めて 0 に戻す
} EntityCF82;
static_assert(sizeof(EntityCF82) == 28);

u32 FUN_0800271c(void);

// アニメーションさせる BG パレット 2 と、点灯色をしまってある BG パレット 7
#define BG_PLTT2 (gBgPlttBuffer + 0x20)
#define BG_PLTT7 (gBgPlttBuffer + 0x70)
#define OFF_COLOR (*(gBgPlttBuffer + 0x2F))

static const u8 sEntityCF82StepDurations[8] = {
    10, 10, 10, 16, 10, 10, 10, 16,
};  // 0x085AA95C

// 点灯色と消灯色を 1 色ずつ塗り替えて、尺が来たら次の step へ進める
NON_MATCH s32 EntityCF82_Update(EntityCF82* p) {
#ifdef NONMATCHING_C
  if (FUN_0800271c()) {
    s32 i;

    if (p->step < 4) {
      for (i = 0; i < p->step; i++) {
        BG_PLTT2[11 - i] = OFF_COLOR;
      }
      for (; i < 4; i++) {
        BG_PLTT2[11 - i] = BG_PLTT7[4 - i];
      }
    } else {
      for (i = 0; i < p->step - 4; i++) {
        BG_PLTT2[8 + i] = BG_PLTT7[1 + i];
      }
      for (; i < 4; i++) {
        BG_PLTT2[8 + i] = OFF_COLOR;
      }
    }
  }

  p->timer++;
  if (p->timer >= sEntityCF82StepDurations[p->step]) {
    if (p->step < 4) {
      BG_PLTT2[11 - p->step] = OFF_COLOR;
    } else {
      BG_PLTT2[8 + p->step - 4] = BG_PLTT7[1 + p->step - 4];
    }
    p->step++;
    if (p->step > 7) {
      p->step = 0;
    }
    p->timer = 0;
  }
  return 0;
#else
  INCFUNC("asm/func/EntityCF82_Update.inc");
#endif
}

s32 EntityCF82_Destroy(EntityCF82* p) { return 0; }

// アニメーションを頭出しして、パレット 2 の色 0 を消灯色で塗っておく
s32 EntityCF82_Init(EntityCF82* p) {
  p->step = 0;
  p->timer = 0;
  {
    rgb555* off = gBgPlttBuffer + 0x2F;
    rgb555* pltt = gBgPlttBuffer + 0x20;

    *pltt = *off;
  }
  return 0;
}

EntityCF82* EntityCF82_Create(void) {
  EntityCF82* p = CreateEntity(ENTITY_UNK_12, sizeof(EntityCF82));

  if (p != NULL) {
    SetEntityRoutine(p, EntityCF82_Update, EntityCF82_Destroy);
    if (EntityCF82_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
