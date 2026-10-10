#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1980 - 0x18];
} Entity1DBE;
static_assert(sizeof(Entity1DBE) == 1980);

IWRAM_DATA Entity1DBE* gEntity1DBE = NULL;  // 0x03000144

INCASM("asm/entity_1dbe.inc");
