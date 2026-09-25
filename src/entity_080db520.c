#include "entity.h"
#include "global.h"

typedef struct Entity080db520 {
  Entity e;  // 0x0, ENTITY_UNK_10
  u8 unk_18[1372 - 0x18];
} Entity080db520;
static_assert(sizeof(Entity080db520) == 1372);

extern Entity080db520* gEntity080db520;  // 0x03000160

INCASM("asm/entity_080db520.inc");
