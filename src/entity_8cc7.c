#include "entity.h"
#include "global.h"

typedef struct Entity8CC7 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[3796 - 0x18];
} Entity8CC7;
static_assert(sizeof(Entity8CC7) == 3796);

INCASM("asm/entity_8cc7.inc");
