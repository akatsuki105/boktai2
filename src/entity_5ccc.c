#include "entity.h"
#include "global.h"

// Entity0809eb24_Create と Entity0809eeb4_Create
typedef struct Entity5CCC {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[2740 - 0x18];
} Entity5CCC;
static_assert(sizeof(Entity5CCC) == 2740);

extern Entity5CCC* gEntity5CCC;  // 0x03000140

INCASM("asm/entity_5ccc.inc");
