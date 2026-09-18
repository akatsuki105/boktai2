#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[4336 - 0x18];
} Entity571D;
static_assert(sizeof(Entity571D) == 4336);

INCASM("asm/entity_571d.inc");

NAKED s32 Entity571D_Update(Entity571D* p) { INCFUNC("asm/func/Entity571D_Update.inc"); }

NAKED s32 Entity571D_Destroy(Entity571D* p) { INCFUNC("asm/func/Entity571D_Destroy.inc"); }

NAKED s32 Entity571D_Init(Entity571D* p) { INCFUNC("asm/func/Entity571D_Init.inc"); }

NAKED Entity571D* Entity571D_Create(void) { INCFUNC("asm/func/Entity571D_Create.inc"); }
