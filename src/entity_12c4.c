#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_9 or ENTITY_UNK_11
  u8 unk_18[768 - 0x18];
} Entity12C4;
static_assert(sizeof(Entity12C4) == 768);

IWRAM_DATA Entity12C4* gEntity12C4 = NULL;  // 0x03000094

INCASM("asm/entity_12c4.inc");
