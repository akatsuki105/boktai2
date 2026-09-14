#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1004 - 0x18];
} Entity501B;
static_assert(sizeof(Entity501B) == 1004);

INCASM("asm/entity_501b.inc");
