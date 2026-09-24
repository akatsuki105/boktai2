#include "entity.h"
#include "global.h"

typedef struct Entity7F5E {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[0x5F0 - 0x18];
  void (*fn)(struct Entity7F5E*);  // 0x5F0, Entity7F5E_Update が p->fn(p) として呼ぶ状態関数
} Entity7F5E;
static_assert(sizeof(Entity7F5E) == 1524);

NAKED void SolarBank_CalcInterestRate(void) { INCFUNC("asm/func/SolarBank_CalcInterestRate.inc"); }

INCASM("asm/solar_bank.inc");

s32 Entity7F5E_Update(Entity7F5E* p) {
  p->fn(p);
  return 0;
}

NAKED s32 Entity7F5E_Destroy(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Destroy.inc"); }

NAKED void FUN_080b4414(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4414.inc"); }

NAKED void FUN_080b4454(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4454.inc"); }

NAKED void FUN_080b4490(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4490.inc"); }

NAKED void FUN_080b4740(Entity7F5E* p) { INCFUNC("asm/func/FUN_080b4740.inc"); }

NAKED s32 Entity7F5E_Init(Entity7F5E* p) { INCFUNC("asm/func/Entity7F5E_Init.inc"); }

NAKED Entity7F5E* Entity7F5E_Create(u32 unused1, u32 unused2) { INCFUNC("asm/func/Entity7F5E_Create.inc"); }
