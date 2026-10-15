#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[500 - 0x18];
} Entity3FFD;
static_assert(sizeof(Entity3FFD) == 500);

INCASM("asm/entity_3ffd.inc");
