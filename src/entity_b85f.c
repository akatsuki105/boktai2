#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[2140 - 0x18];
} EntityB85F;
static_assert(sizeof(EntityB85F) == 2140);

INCASM("asm/entity_b85f.inc");
