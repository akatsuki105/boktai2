#include "entity.h"
#include "global.h"

typedef struct Entity081d9d38 {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[116 - 0x18];
} Entity081d9d38;
static_assert(sizeof(Entity081d9d38) == 116);

extern Entity081d9d38* gEntity081d9d38;  // 0x03002C64

INCASM("asm/entity_081d9d38.inc");
