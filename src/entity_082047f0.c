#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[204 - 0x18];
} Entity082047f0;
static_assert(sizeof(Entity082047f0) == 204);

INCASM("asm/entity_082047f0.inc");
