#include "entity.h"
#include "global.h"

typedef struct EntityF1F9 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1408 - 0x18];
} EntityF1F9;
static_assert(sizeof(EntityF1F9) == 1408);

INCASM("asm/entity_f1f9.inc");
