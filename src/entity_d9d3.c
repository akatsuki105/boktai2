#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[544 - 0x18];
} EntityD9D3;
static_assert(sizeof(EntityD9D3) == 544);

INCASM("asm/entity_d9d3.inc");
