#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1524 - 0x18];
} Entity7F5E;
static_assert(sizeof(Entity7F5E) == 1524);

NAKED void SolarBank_CalcInterestRate(void) { INCFUNC("asm/func/SolarBank_CalcInterestRate.inc"); }

INCASM("asm/solar_bank.inc");

NAKED s32 Entity7F5E_Update(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Update.inc"); }

NAKED s32 Entity7F5E_Destroy(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Destroy.inc"); }

NAKED void FUN_080b4414(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4414.inc"); }

NAKED void FUN_080b4454(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4454.inc"); }

NAKED void FUN_080b4490(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4490.inc"); }

NAKED void FUN_080b4740(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4740.inc"); }

NAKED s32 Entity7F5E_Init(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Init.inc"); }

NAKED Entity7F5E* Entity7F5E_Create(u32 unused1, u32 unused2) { INCFUNC("asm/func/Entity7F5E_Create.inc"); }
