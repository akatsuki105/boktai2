#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[2276 - 0x18];
} EntityB6FF;
static_assert(sizeof(EntityB6FF) == 2276);

INCASM("asm/entity_b6ff.inc");
