#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[28 - 0x18];
} Entity162E;
static_assert(sizeof(Entity162E) == 28);

INCASM("asm/entity_162e.inc");
