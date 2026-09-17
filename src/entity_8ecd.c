#include "entity.h"
#include "global.h"

typedef struct Entity8ECD {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[2280 - 0x18];
} Entity8ECD;
static_assert(sizeof(Entity8ECD) == 2280);

extern s32 s32_03000080;         // 0x03000080
extern Entity8ECD* gEntity8ECD;  // 0x03000084

INCASM("asm/entity_8ecd.inc");
