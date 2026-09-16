#include "entity.h"
#include "global.h"

typedef struct Entity081d16ec {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[2432 - 0x18];
} Entity081d16ec;
static_assert(sizeof(Entity081d16ec) == 2432);

extern Entity081d16ec* gEntity081d16ec;  // 0x0300018C

INCASM("asm/entity_081d16ec.inc");
