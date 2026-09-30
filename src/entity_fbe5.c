#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[672 - 0x18];
} EntityFBE5;
static_assert(sizeof(EntityFBE5) == 672);

INCASM("asm/entity_fbe5.inc");
