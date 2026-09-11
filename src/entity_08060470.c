#include "entity.h"
#include "global.h"

typedef struct Entity08060470 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[932 - 0x18];
} Entity08060470;
static_assert(sizeof(Entity08060470) == 932);

INCASM("asm/entity_08060470.inc");

NAKED s32 Entity08060470_Update(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Update.inc"); }

NAKED s32 Entity08060470_Destroy(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Destroy.inc"); }

NAKED s32 Entity08060470_Init(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Init.inc"); }

NAKED Entity08060470* Entity08060470_Create(void) { INCFUNC("asm/func/Entity08060470_Create.inc"); }
