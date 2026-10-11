#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[48 - 0x18];
} EntityEF66;
static_assert(sizeof(EntityEF66) == 48);

IWRAM_DATA EntityEF66* gEntityEF66 = NULL;  // 0x03000148

INCASM("asm/entity_ef66.inc");
