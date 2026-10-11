#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[700 - 0x18];
} Entity081e8d0c;
static_assert(sizeof(Entity081e8d0c) == 700);

INCASM("asm/entity_081e8d0c.inc");
