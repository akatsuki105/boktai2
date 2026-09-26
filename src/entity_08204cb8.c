#include "entity.h"
#include "global.h"

typedef struct Entity08204cb8 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1152 - 0x18];
} Entity08204cb8;
static_assert(sizeof(Entity08204cb8) == 1152);

extern Entity08204cb8* gEntity08204cb8;  // 0x03000220

INCASM("asm/entity_08204cb8.inc");
