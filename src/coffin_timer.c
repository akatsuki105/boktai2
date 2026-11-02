#include "entity.h"
#include "global.h"
#include "player.h"
#include "vm.h"

// サバタで黒ジャンゴを運搬するときの黒ジャンゴの残りHPを徐々に減らしていく (つまり棺桶運搬のタイムリミット)
// interval フレームごとに gStat->bossHP を1つ減らし、0 になったらサバタを PACT_SPECIALDEATH にする
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_8
  u16 timer;     // 0x18, _Update が毎フレーム +1 し interval に達したら 0 に戻す
  u16 interval;  // 0x1A, '.s' があればその値, なければ 30
} CoffinTimer;
static_assert(sizeof(CoffinTimer) == 28);

void FUN_0809c3c0(s32 param_1, s32 param_2, s32 param_3);

// ゲージを一定間隔で減らし, 0 になったら PACT_SPECIALDEATH にして、 この Entity を消す
s32 CoffinTimer_Update(CoffinTimer* p) {
  if (gPlayerPtr[0] != NULL && gPlayerPtr[0]->mode == 1) {
    bool8 empty = FALSE;
    s32* gauge = &gStat->bossHP;

    if (*gauge > 0) {
      if (++p->timer >= p->interval) {
        p->timer = 0;
        (*gauge)--;
        FUN_0809c3c0(gStat->bossHP, gStat->bossHPMax, 1);
        if (gStat->bossHP <= 0) {
          empty = TRUE;
        }
      }
    } else {
      empty = TRUE;
    }

    if (empty && gPlayerPtr[0]->action != PACT_GRABBED) {
      Player_EnterDeadState(gPlayerPtr[0]);
      gPlayerPtr[0]->action = PACT_SPECIALDEATH;
      gPlayerPtr[0]->state = 0;
      gPlayerPtr[0]->stateTimer = 0;
      KillEntity(&p->e);
    }
  }
  return 0;
}

s32 CoffinTimer_Destroy(CoffinTimer* p) { return 0; }

s32 CoffinTimer_Init(CoffinTimer* p, u32 id, u32 _) {
  if (gStat->bossHP <= 0) {
    gStat->bossHP = 1;
  }

  if (VM_SeekToNamedArg('s')) {
    p->interval = VM_GetValue();
  } else {
    p->interval = 30;
  }

  p->timer = 0;
  FUN_0809c3c0(gStat->bossHP, gStat->bossHPMax, 0);
  return 0;
}

// 0x162E
CoffinTimer* CoffinTimer_Create(u32 id, u32 _) {
  CoffinTimer* p = CreateEntity(ENTITY_UNK_8, sizeof(CoffinTimer));

  if (p != NULL) {
    SetEntityRoutine(p, CoffinTimer_Update, CoffinTimer_Destroy);
    if (CoffinTimer_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
