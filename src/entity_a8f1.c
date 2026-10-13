#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[904 - 0x18];
} EntityA8F1;
static_assert(sizeof(EntityA8F1) == 904);

INCASM("asm/entity_a8f1.inc");
