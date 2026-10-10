#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1696 - 0x18];
} Entity081ee2a0;
static_assert(sizeof(Entity081ee2a0) == 1696);

IWRAM_DATA Entity081ee2a0* gEntity081ee2a0 = NULL;  // 0x030001CC
IWRAM_DATA u8 u8_030001c8[0x218 - 0x1D0] = {};

INCASM("asm/entity_081ee2a0.inc");
