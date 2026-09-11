#include "boss.h"
#include "entity.h"
#include "global.h"

// ボス戦前の人型のイベント時もこれ使う
typedef struct Dvalinn {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2120 - 0x18];
} Dvalinn;
static_assert(sizeof(Dvalinn) == 2120);

extern Dvalinn* gDvalinn;  // 0x03002C80

INCASM("asm/dvalinn.inc");

NAKED s32 Dvalinn_Update(Dvalinn* p) { INCFUNC("asm/func/Dvalinn_Update.inc"); }

NAKED s32 Dvalinn_Destroy(Dvalinn* p) { INCFUNC("asm/func/Dvalinn_Destroy.inc"); }

NAKED s32 Dvalinn_Init(Dvalinn* p, u32 id) { INCFUNC("asm/func/Dvalinn_Init.inc"); }

Dvalinn* Dvalinn_Create(u32 id) {
  Dvalinn* p = FUN_08022a2c(BOSS_DVALINN);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Dvalinn));
  if (p != NULL) {
    SetEntityRoutine(p, Dvalinn_Update, Dvalinn_Destroy);
    if (Dvalinn_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  gDvalinn = p;
  return p;
}

NAKED void FUN_08200a6c(void) { INCFUNC("asm/func/FUN_08200a6c.inc"); }
