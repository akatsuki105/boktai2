#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1076 - 0x18];
} Entity6D69;
static_assert(sizeof(Entity6D69) == 1076);

INCASM("asm/entity_6d69.inc");
