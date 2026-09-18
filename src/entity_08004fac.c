#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[28 - 0x18];
} Entity08004fac;
static_assert(sizeof(Entity08004fac) == 28);

IWRAM_DATA Entity08004fac* gEntity08004fac = NULL;  // 0x03000024

INCASM("asm/entity_08004fac.inc");
