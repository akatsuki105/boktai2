#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[32 - 0x18];
} EntityED07;
static_assert(sizeof(EntityED07) == 32);

IWRAM_DATA EntityED07* gEntityED07 = NULL;  // 0x03000030

INCASM("asm/entity_ed07.inc");
