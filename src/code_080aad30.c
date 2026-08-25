#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[132 - sizeof(Entity)];
} EntityC438;
static_assert(sizeof(EntityC438) == 132);

NAKED bool32 FUN_080aad30(EntityC438* p) { INCFUNC("asm/func/FUN_080aad30.inc"); }

NAKED s32 EntityC438_Update(EntityC438* p) { INCFUNC("asm/func/EntityC438_Update.inc"); }

NAKED s32 EntityC438_Destroy(EntityC438* p) { INCFUNC("asm/func/EntityC438_Destroy.inc"); }

NAKED s32 EntityC438_Init(EntityC438* p) { INCFUNC("asm/func/EntityC438_Init.inc"); }

NAKED EntityC438* EntityC438_Create(void) { INCFUNC("asm/func/EntityC438_Create.inc"); }
