#include "entity.h"
#include "global.h"

typedef struct Entity95F8 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[44 - 0x18];
} Entity95F8;
static_assert(sizeof(Entity95F8) == 44);

extern Entity95F8* gEntity95F8;  // 0x0300004C

INCASM("asm/entity_95f8.inc");
