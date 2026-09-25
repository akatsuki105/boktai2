#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[848 - 0x18];
} Entity080aace8;
static_assert(sizeof(Entity080aace8) == 848);

INCASM("asm/entity_080aace8.inc");
