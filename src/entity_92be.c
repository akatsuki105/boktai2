#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[176 - 0x18];
} Entity92BE;
static_assert(sizeof(Entity92BE) == 176);

INCASM("asm/entity_92be.inc");
