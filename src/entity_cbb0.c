#include "entity_cbb0.h"

#include "entity.h"
#include "global.h"

INCASM("asm/entity_cbb0.inc");

s32 FUN_080b2428(void) {
  gEntityCBB0 = NULL;
  return 0;
}

NAKED void FUN_080b2434(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2434.inc"); }

NAKED u32 FUN_080b2474(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2474.inc"); }

NAKED void FUN_080b24a4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b24a4.inc"); }

NAKED void FUN_080b252c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b252c.inc"); }

NAKED s32 EntityCBB0_Update(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Update.inc"); }

NAKED s32 EntityCBB0_Destroy(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Destroy.inc"); }

NAKED s32 EntityCBB0_Init(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Init.inc"); }

NAKED EntityCBB0* EntityCBB0_Create(u32 subroutineID) { INCFUNC("asm/func/EntityCBB0_Create.inc"); }
