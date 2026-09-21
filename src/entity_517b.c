#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[72 - 0x18];
} Entity517B;
static_assert(sizeof(Entity517B) == 72);

IWRAM_DATA Entity517B* gEntity517B = NULL;  // 0x03000088

INCASM("asm/entity_517b.inc");
