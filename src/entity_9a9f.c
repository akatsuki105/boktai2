#include "entity_9a9f.h"

#include "entity.h"
#include "global.h"

Entity9A9F* FUN_081dd9a0(void) { return gEntity9A9F; }

void FUN_081dd9ac(void) { gEntity9A9F = NULL; }

INCASM("asm/entity_9a9f.inc");

NAKED s32 FUN_081dfa98(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dfa98.inc"); }

NAKED s32 Entity9A9F_Destroy(Entity9A9F* p) { INCFUNC("asm/func/Entity9A9F_Destroy.inc"); }

NAKED Entity9A9F* Entity9A9F_Create(void) { INCFUNC("asm/func/Entity9A9F_Create.inc"); }

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
