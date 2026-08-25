#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[80 - sizeof(Entity)];
} EntityD3A9;
static_assert(sizeof(EntityD3A9) == 80);

INCASM("asm/entity_d3a9.inc");
