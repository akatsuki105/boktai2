#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[276 - 0x18];
} Entity7C62;
static_assert(sizeof(Entity7C62) == 276);

INCASM("asm/entity_7c62.inc");
