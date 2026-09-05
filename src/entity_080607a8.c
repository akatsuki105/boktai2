#include "entity.h"
#include "global.h"

typedef struct Entity080607a8 {
  Entity e;  // 0x0, ENTITY_UNK_10
  u8 unk_18[1432 - 0x18];
} Entity080607a8;
static_assert(sizeof(Entity080607a8) == 1432);

extern Entity080607a8* gEntity080607a8;  // 0x03000138

INCASM("asm/entity_080607a8.inc");

NAKED s32 FUN_080608e0(void) { INCFUNC("asm/func/FUN_080608e0.inc"); }
