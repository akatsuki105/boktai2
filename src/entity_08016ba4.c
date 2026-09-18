#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[3324 - 0x18];
} Entity08016ba4;
static_assert(sizeof(Entity08016ba4) == 3324);

IWRAM_DATA Entity08016ba4* gEntity08016ba4 = NULL;  // 0x03000064

void FUN_080166a0(void) { gEntity08016ba4 = NULL; }

INCASM("asm/entity_08016ba4.inc");
