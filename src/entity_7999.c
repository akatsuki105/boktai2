#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[676 - 0x18];
} Entity7999;
static_assert(sizeof(Entity7999) == 676);

INCASM("asm/entity_7999.inc");
