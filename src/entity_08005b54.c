#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[452 - 0x18];
} Entity08005b54;
static_assert(sizeof(Entity08005b54) == 452);

IWRAM_DATA Entity08005b54* gEntity08005b54 = NULL;  // 0x03000028

INCASM("asm/entity_08005b54.inc");
