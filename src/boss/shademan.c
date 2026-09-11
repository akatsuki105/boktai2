#include "boss.h"
#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2396 - 0x18];
} BossShadeMan;
static_assert(sizeof(BossShadeMan) == 2396);

s32 FUN_0803c1bc(void* _) { return 7; }

INCASM("asm/shademan.inc");

NAKED s32 BossShadeMan_Update(BossShadeMan* p) { INCFUNC("asm/func/BossShadeMan_Update.inc"); }

NAKED s32 BossShadeMan_Destroy(BossShadeMan* p) { INCFUNC("asm/func/BossShadeMan_Destroy.inc"); }

NAKED s32 BossShadeMan_Init(BossShadeMan* p, u32 id) { INCFUNC("asm/func/BossShadeMan_Init.inc"); }

BossShadeMan* BossShadeMan_Create(u32 id) {
  BossShadeMan* p = FUN_08022a2c(BOSS_SHADEMAN);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(BossShadeMan));
  if (p != NULL) {
    SetEntityRoutine(p, BossShadeMan_Update, BossShadeMan_Destroy);
    if (BossShadeMan_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
