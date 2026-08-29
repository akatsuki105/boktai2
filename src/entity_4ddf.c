
#include "global.h"

typedef struct Entity4DDF {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[808 - 0x18];
} Entity4DDF;
static_assert(sizeof(Entity4DDF) == 808);

INCASM("asm/entity_4ddf.inc");

NAKED void FUN_08211d7c(Entity4DDF* p) { INCFUNC("asm/func/FUN_08211d7c.inc"); }

NAKED s32 Entity4DDF_Update(Entity4DDF* p) { INCFUNC("asm/func/Entity4DDF_Update.inc"); }

NAKED s32 Entity4DDF_Destroy(Entity4DDF* _) { INCFUNC("asm/func/Entity4DDF_Destroy.inc"); }

NAKED Entity4DDF* Entity4DDF_Init(Entity4DDF* p, void* _) { INCFUNC("asm/func/Entity4DDF_Init.inc"); }

NAKED Entity4DDF* Entity4DDF_Create(void* _) { INCFUNC("asm/func/Entity4DDF_Create.inc"); }
