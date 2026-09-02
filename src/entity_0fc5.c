#include "entity.h"
#include "global.h"

typedef struct Entity0FC5 {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[392 - 0x18];
} Entity0FC5;
static_assert(sizeof(Entity0FC5) == 392);

void FUN_0821abfc(Entity0FC5*);

INCASM("asm/entity_0fc5.inc");

NAKED s32 Entity0FC5_Init(Entity0FC5* p) { INCFUNC("asm/func/Entity0FC5_Init.inc"); }

NAKED Entity0FC5* Entity0FC5_Create(void) { INCFUNC("asm/func/Entity0FC5_Create.inc"); }

void (*const PTR_ARRAY_085affa4[1])(Entity0FC5*) = {
    FUN_0821abfc,
};
