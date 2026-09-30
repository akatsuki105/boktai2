#include "entity.h"
#include "global.h"

typedef struct Entity081ea120 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[636 - 0x18];
} Entity081ea120;
static_assert(sizeof(Entity081ea120) == 636);

extern Entity081ea120* gEntity081ea120;  // 0x030001B8

INCASM("asm/entity_081ea120.inc");
