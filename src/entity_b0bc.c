#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[44 - 0x18];
} EntityB0BC;
static_assert(sizeof(EntityB0BC) == 44);

INCASM("asm/entity_b0bc.inc");
