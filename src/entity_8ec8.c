#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_4
  u8 unk_18[128 - 0x18];
} Entity8EC8;
static_assert(sizeof(Entity8EC8) == 128);

INCASM("asm/entity_8ec8.inc");
