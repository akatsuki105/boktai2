#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[712 - 0x18];
} EntityD852;
static_assert(sizeof(EntityD852) == 712);

INCASM("asm/entity_d852.inc");
