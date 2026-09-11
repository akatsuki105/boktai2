#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[140 - 0x18];
} Entity55C2;
static_assert(sizeof(Entity55C2) == 140);

INCASM("asm/entity_55c2.inc");
