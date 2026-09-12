#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[52 - 0x18];
} Entity6978;
static_assert(sizeof(Entity6978) == 52);

COMMON_DATA Entity6978* gEntity6978 = NULL;  // 0x03002B30

INCASM("asm/entity_6978.inc");
