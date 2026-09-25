#include "entity.h"
#include "global.h"

typedef struct Entity080dbe54 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[2600 - 0x18];
} Entity080dbe54;
static_assert(sizeof(Entity080dbe54) == 2600);

extern Entity080dbe54* gEntity080dbe54;  // 0x03000164

INCASM("asm/entity_080dbe54.inc");
