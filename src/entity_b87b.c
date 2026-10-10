#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[568 - 0x18];
} EntityB87B;
static_assert(sizeof(EntityB87B) == 568);

INCASM("asm/entity_b87b.inc");
