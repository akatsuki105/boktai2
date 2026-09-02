#include "entity.h"
#include "global.h"

typedef struct Entity794C {
  Entity e;  // ENTITY_UNK_5
  u8 unk_18[216 - 0x18];
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

extern Entity794C* gEntity794C;  // 0x03001700

INCASM("asm/entity_794c.inc");
