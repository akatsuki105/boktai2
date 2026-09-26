#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[8172 - 0x18];
} EntityA288;
static_assert(sizeof(EntityA288) == 8172);

INCASM("asm/entity_a288.inc");
