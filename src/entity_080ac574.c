#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[280 - 0x18];
} Entity080ac574;
static_assert(sizeof(Entity080ac574) == 280);

INCASM("asm/entity_080ac574.inc");
