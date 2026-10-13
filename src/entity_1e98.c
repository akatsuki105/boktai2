#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2236 - 0x18];
} Entity1E98;
static_assert(sizeof(Entity1E98) == 2236);

extern Entity1E98* gEntity1E98;  // 0x03002C44

INCASM("asm/entity_1e98.inc");
