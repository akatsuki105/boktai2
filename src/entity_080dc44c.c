#include "entity.h"
#include "global.h"

typedef struct Entity080dc44c {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[708 - 0x18];
} Entity080dc44c;
static_assert(sizeof(Entity080dc44c) == 708);

extern Entity080dc44c* gEntity080dc44c;  // 0x03000168

INCASM("asm/entity_080dc44c.inc");
