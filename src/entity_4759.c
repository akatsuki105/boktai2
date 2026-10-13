#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[204 - 0x18];
} Entity4759;
static_assert(sizeof(Entity4759) == 204);

INCASM("asm/entity_4759.inc");
