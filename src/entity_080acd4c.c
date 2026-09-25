#include "entity.h"
#include "global.h"

typedef struct Entity080acd4c {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[412 - 0x18];
} Entity080acd4c;
static_assert(sizeof(Entity080acd4c) == 412);

extern Entity080acd4c* gEntity080acd4c;  // 0x03002C54

INCASM("asm/entity_080acd4c.inc");
