#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[192 - 0x18];
} Entity080cbabc;
static_assert(sizeof(Entity080cbabc) == 192);

INCASM("asm/entity_080cbabc.inc");
