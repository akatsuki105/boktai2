#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_4
  u8 unk_18[48 - 0x18];
} Entity8D5C;
static_assert(sizeof(Entity8D5C) == 48);

INCASM("asm/entity_8d5c.inc");
