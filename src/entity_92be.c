#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[176 - 0x18];
} Entity92BE;
static_assert(sizeof(Entity92BE) == 176);

NAKED void FUN_080a6f54(Entity92BE* p) { INCFUNC("asm/func/FUN_080a6f54.inc"); }

NAKED s32 Entity92BE_Update(Entity92BE* p) { INCFUNC("asm/func/Entity92BE_Update.inc"); }

NAKED s32 Entity92BE_Destroy(Entity92BE* p) { INCFUNC("asm/func/Entity92BE_Destroy.inc"); }

NAKED s32 Entity92BE_Init(Entity92BE* p) { INCFUNC("asm/func/Entity92BE_Init.inc"); }

NAKED Entity92BE* Entity92BE_Create(void) { INCFUNC("asm/func/Entity92BE_Create.inc"); }
