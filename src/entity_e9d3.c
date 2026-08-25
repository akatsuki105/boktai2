#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[2128 - sizeof(Entity)];
} EntityE9D3;
static_assert(sizeof(EntityE9D3) == 2128);

INCASM("asm/entity_e9d3.inc");

NAKED void EntityE9D3_Init_Helper_080b5650(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5650.inc"); }

NAKED void EntityE9D3_Init_Helper_080b593c(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b593c.inc"); }

NAKED s32 EntityE9D3_Init_Helper_080b5984(void) { INCFUNC("asm/func/EntityE9D3_Init_Helper_080b5984.inc"); }

NAKED s32 EntityE9D3_Init(EntityE9D3* p) { INCFUNC("asm/func/EntityE9D3_Init.inc"); }

NAKED EntityE9D3* EntityE9D3_Create(void) { INCFUNC("asm/func/EntityE9D3_Create.inc"); }
