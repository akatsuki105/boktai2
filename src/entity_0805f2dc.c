#include "entity.h"
#include "global.h"

// シェードマンの出すエフェクト?
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1860 - 0x18];
} Entity0805f2dc;
static_assert(sizeof(Entity0805f2dc) == 1860);

INCASM("asm/entity_0805f2dc.inc");
