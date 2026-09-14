#include "entity.h"
#include "global.h"

typedef struct EntityD53D {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[48 - 0x18];
} EntityD53D;
static_assert(sizeof(EntityD53D) == 48);

extern EntityD53D* gEntityD53D;  // 0x030000E8

INCASM("asm/entity_d53d.inc");
