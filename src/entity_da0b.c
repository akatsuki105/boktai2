#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[4964 - 0x18];
} EntityDA0B;
static_assert(sizeof(EntityDA0B) == 4964);

INCASM("asm/entity_da0b.inc");
