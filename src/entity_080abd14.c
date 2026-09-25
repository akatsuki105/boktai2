#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1136 - 0x18];
} Entity080abd14;
static_assert(sizeof(Entity080abd14) == 1136);

INCASM("asm/entity_080abd14.inc");
