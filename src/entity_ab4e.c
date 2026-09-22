#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_5
  u8 unk_18[6704 - 0x18];
} EntityAB4E;
static_assert(sizeof(EntityAB4E) == 6704);

IWRAM_DATA EntityAB4E* gEntityAB4E = NULL;  // 0x030000C0

INCASM("asm/entity_ab4e.inc");
