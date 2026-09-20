#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[7712 - 0x18];
} Entity5645;
static_assert(sizeof(Entity5645) == 7712);

INCASM("asm/entity_5645.inc");
