#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1324 - 0x18];
} EntityB426;
static_assert(sizeof(EntityB426) == 1324);

INCASM("asm/entity_b426.inc");
