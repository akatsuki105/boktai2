#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[60 - 0x18];
} Entity5E27;
static_assert(sizeof(Entity5E27) == 60);

const u8 u8_ARRAY_085aa964[9] = {0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x67};  // 0x085AA964

INCASM("asm/entity_5e27.inc");
