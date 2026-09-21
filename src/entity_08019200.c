#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[860 - 0x18];
} Entity08019200;
static_assert(sizeof(Entity08019200) == 860);

IWRAM_DATA Entity08019200* gEntity08019200 = NULL;  // 0x0300008C

INCASM("asm/entity_08019200.inc");
