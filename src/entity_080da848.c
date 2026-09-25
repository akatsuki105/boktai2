#include "entity.h"
#include "global.h"

typedef struct Entity080da848 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[2560 - 0x18];
} Entity080da848;
static_assert(sizeof(Entity080da848) == 2560);

extern Entity080da848* gEntity080da848;  // 0x0300015C

INCASM("asm/entity_080da848.inc");
