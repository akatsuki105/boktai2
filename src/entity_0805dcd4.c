#include "entity.h"
#include "global.h"

typedef struct Entity0805dcd4 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1604 - 0x18];
} Entity0805dcd4;
static_assert(sizeof(Entity0805dcd4) == 1604);

INCASM("asm/entity_0805dcd4.inc");
