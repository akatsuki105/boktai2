#include "entity.h"
#include "global.h"

typedef struct Entity9A9F {
  Entity e;  // ENTITY_UNK_1
  u8 unk_18[732];
} Entity9A9F;
static_assert(sizeof(Entity9A9F) == 756);

extern Entity9A9F* gEntity9A9F;  // 0x03002C68

INCASM("asm/entity_9a9f.inc");
