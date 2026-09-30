#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[5392 - 0x18];
} Entity0805e67c;
static_assert(sizeof(Entity0805e67c) == 5392);

INCASM("asm/entity_0805e67c.inc");
