#include "entity.h"
#include "global.h"

typedef struct Entity080dd1f8 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[3948 - 0x18];
} Entity080dd1f8;
static_assert(sizeof(Entity080dd1f8) == 3948);

extern Entity080dd1f8* gEntity080dd1f8;  // 0x0300016C

INCASM("asm/entity_080dd1f8.inc");
