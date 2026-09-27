#include "entity.h"
#include "global.h"

// 通信関連?
typedef struct Entity723E {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[2280 - 0x18];
} Entity723E;
static_assert(sizeof(Entity723E) == 2280);

extern Entity723E* gEntity723E;  // 0x0300011C

INCASM("asm/entity_723e.inc");
