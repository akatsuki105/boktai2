#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[44 - 0x18];
} EntityA687;
static_assert(sizeof(EntityA687) == 44);

INCASM("asm/entity_a687.inc");
