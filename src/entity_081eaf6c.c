#include "entity.h"
#include "global.h"

typedef struct Entity081eaf6c {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1328 - 0x18];
} Entity081eaf6c;
static_assert(sizeof(Entity081eaf6c) == 1328);

extern Entity081eaf6c* gEntity081eaf6c;  // 0x030001C0

INCASM("asm/entity_081eaf6c.inc");
