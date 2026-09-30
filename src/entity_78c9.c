#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1720 - 0x18];
} Entity78C9;
static_assert(sizeof(Entity78C9) == 1720);

const u8 u8_ARRAY_085aa988[4] = {8, 14, 9, 15};  // 0x085AA988

INCASM("asm/entity_78c9.inc");
