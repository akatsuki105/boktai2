#include "entity.h"
#include "global.h"

typedef struct Entity1DBE {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1980 - 0x18];
} Entity1DBE;
static_assert(sizeof(Entity1DBE) == 1980);

extern Entity1DBE* gEntity1DBE;  // 0x03000144

INCASM("asm/entity_1dbe.inc");
