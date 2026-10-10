#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[2988 - 0x18];
} Entity081e9cac;
static_assert(sizeof(Entity081e9cac) == 2988);

IWRAM_DATA Entity081e9cac* gEntity081e9cac = NULL;  // 0x030001B4

INCASM("asm/entity_081e9cac.inc");
