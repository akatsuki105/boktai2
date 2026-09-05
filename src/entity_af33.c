#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[444 - 0x18];
} EntityAF33;
static_assert(sizeof(EntityAF33) == 444);

INCASM("asm/entity_af33.inc");

NAKED void FUN_080502a8(EntityAF33* p) { INCFUNC("asm/func/FUN_080502a8.inc"); }

NAKED void FUN_0805043c(EntityAF33* p) { INCFUNC("asm/func/FUN_0805043c.inc"); }

NAKED void FUN_080504e0(EntityAF33* p) { INCFUNC("asm/func/FUN_080504e0.inc"); }

NAKED void FUN_08050558(EntityAF33* p) { INCFUNC("asm/func/FUN_08050558.inc"); }

NAKED void FUN_08050598(EntityAF33* p) { INCFUNC("asm/func/FUN_08050598.inc"); }

NAKED void FUN_08050674(EntityAF33* p) { INCFUNC("asm/func/FUN_08050674.inc"); }

NAKED void FUN_08050754(EntityAF33* p) { INCFUNC("asm/func/FUN_08050754.inc"); }

NAKED s32 EntityAF33_Update(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Update.inc"); }

NAKED s32 EntityAF33_Destroy(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Destroy.inc"); }

NAKED s32 EntityAF33_Init(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Init.inc"); }

EntityAF33* EntityAF33_Create(void) {
  EntityAF33* p = CreateEntity(ENTITY_UNK_2, sizeof(EntityAF33));
  if (p != NULL) {
    SetEntityRoutine(p, EntityAF33_Update, EntityAF33_Destroy);
    if (EntityAF33_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
