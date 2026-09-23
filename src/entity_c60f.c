#include "entity.h"
#include "global.h"

typedef struct EntityC60F {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[168 - 0x18];
} EntityC60F;
static_assert(sizeof(EntityC60F) == 168);

extern EntityC60F* gEntityC60F;  // 0x0300019C

INCASM("asm/entity_c60f.inc");
