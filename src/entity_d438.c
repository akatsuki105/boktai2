#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[120 - 0x18];
} EntityD438;
static_assert(sizeof(EntityD438) == 120);

IWRAM_DATA EntityD438* gEntityD438 = NULL;  // 0x03000124

INCASM("asm/entity_d438.inc");
