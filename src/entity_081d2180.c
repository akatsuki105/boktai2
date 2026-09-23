#include "entity.h"
#include "global.h"

typedef struct Entity081d2180 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1116 - 0x18];
} Entity081d2180;
static_assert(sizeof(Entity081d2180) == 1116);

INCASM("asm/entity_081d2180.inc");
