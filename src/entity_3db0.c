#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[204 - 0x18];
} Entity3DB0;
static_assert(sizeof(Entity3DB0) == 204);

INCASM("asm/entity_3db0.inc");
