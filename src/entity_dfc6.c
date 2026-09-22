#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_3
  u8 unk_18[408 - 0x18];
} EntityDFC6;
static_assert(sizeof(EntityDFC6) == 408);

IWRAM_DATA EntityDFC6* gEntityDFC6 = NULL;  // 0x030000C8

INCASM("asm/entity_dfc6.inc");
