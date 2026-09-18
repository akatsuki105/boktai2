#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1884 - 0x18];
} EntityEF6F;
static_assert(sizeof(EntityEF6F) == 1884);

INCASM("asm/entity_ef6f.inc");
