#include "entity.h"
#include "global.h"

typedef struct Entity7B9F {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[940 - 0x18];
} Entity7B9F;
static_assert(sizeof(Entity7B9F) == 940);

extern Entity7B9F* gEntity7B9F;  // 0x030001A0

INCASM("asm/entity_7b9f.inc");
