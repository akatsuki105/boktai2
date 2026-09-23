#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[816 - 0x18];
} Entity08F4;
static_assert(sizeof(Entity08F4) == 816);

INCASM("asm/entity_08f4.inc");
