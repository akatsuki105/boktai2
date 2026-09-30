#include "entity.h"
#include "global.h"

typedef struct Entity081ea820 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1752 - 0x18];
} Entity081ea820;
static_assert(sizeof(Entity081ea820) == 1752);

extern Entity081ea820* gEntity081ea820;  // 0x030001BC

INCASM("asm/entity_081ea820.inc");
