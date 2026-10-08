#include "entity.h"
#include "global.h"

// '.f' で指定した間隔で FUN_080e173c を呼ぶだけ
typedef struct {
  Entity e;       // 0x00, ENTITY_UNK_8
  u16 unk_18;     // 0x18, '.p[0]'
  u16 unk_1a;     // 0x1A, '.p[1]'
  u32 unk_1c[2];  // 0x1C, '.A[0]', '.A[1]'
  u16 interval;   // 0x24, '.f', 0 なら毎フレーム, それ以外は timer がこの倍数のときだけ FUN_080e173c を呼ぶ
  u16 timer;      // 0x26, _Update が毎フレーム +1
  u16 unk_28;     // 0x28, _Init が 0 を入れる
  u8 unk_2a;      // 0x2A, '.u[0]=1'
  u8 unk_2b;      // 0x2B, '.u[0]=8'
} Entity080e18e0;
static_assert(sizeof(Entity080e18e0) == 44);

NAKED void FUN_080e173c(Entity080e18e0* p) { INCFUNC("asm/func/FUN_080e173c.inc"); }

s32 Entity080e18e0_Update(Entity080e18e0* p) {
  if (p->interval == 0) {
    FUN_080e173c(p);
  } else if (Mod(p->timer, p->interval) == 0) {
    FUN_080e173c(p);
  }

  p->timer++;
  return 0;
}

s32 Entity080e18e0_Destroy(Entity080e18e0* p) { return 0; }

NAKED s32 Entity080e18e0_Init(Entity080e18e0* p) { INCFUNC("asm/func/Entity080e18e0_Init.inc"); }

Entity080e18e0* Entity080e18e0_Create(void) {
  Entity080e18e0* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080e18e0));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080e18e0_Update, Entity080e18e0_Destroy);
    if (Entity080e18e0_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
