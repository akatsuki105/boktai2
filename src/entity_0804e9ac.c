#include "entity.h"
#include "global.h"

typedef struct Entity0804e9ac {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[164 - 0x18];
} Entity0804e9ac;
static_assert(sizeof(Entity0804e9ac) == 164);

extern Entity0804e9ac* gEntity0804e9ac;  // 0x030000E4

INCASM("asm/entity_0804e9ac.inc");
