#include "entity.h"
#include "global.h"

typedef struct Entity150F {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[828 - 0x18];
} Entity150F;
static_assert(sizeof(Entity150F) == 828);

extern Entity150F* gEntity150F;  // 0x030001B0

INCASM("asm/entity_150f.inc");
