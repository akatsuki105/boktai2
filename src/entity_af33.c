#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[444 - 0x18];
} EntityAF33;
static_assert(sizeof(EntityAF33) == 444);

INCASM("asm/entity_af33.inc");
