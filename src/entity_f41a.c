#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[316 - 0x18];
} EntityF41A;
static_assert(sizeof(EntityF41A) == 316);

INCASM("asm/entity_f41a.inc");
