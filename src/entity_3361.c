#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[176 - 0x18];
} Entity3361;
static_assert(sizeof(Entity3361) == 176);

INCASM("asm/entity_3361.inc");
