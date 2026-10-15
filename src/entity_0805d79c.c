#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[4408 - 0x18];
} Entity0805d79c;
static_assert(sizeof(Entity0805d79c) == 4408);

INCASM("asm/entity_0805d79c.inc");
