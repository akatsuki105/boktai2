#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[644 - 0x18];
} Entity080ac374;
static_assert(sizeof(Entity080ac374) == 644);

INCASM("asm/entity_080ac374.inc");
