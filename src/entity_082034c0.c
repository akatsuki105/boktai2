#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2144 - 0x18];
} Entity082034c0;
static_assert(sizeof(Entity082034c0) == 2144);

IWRAM_DATA Entity082034c0* gEntity082034c0 = NULL;  // 0x03000218

INCASM("asm/entity_082034c0.inc");
