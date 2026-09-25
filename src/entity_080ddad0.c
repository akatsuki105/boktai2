#include "entity.h"
#include "global.h"

typedef struct Entity080ddad0 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[528 - 0x18];
} Entity080ddad0;
static_assert(sizeof(Entity080ddad0) == 528);

extern Entity080ddad0* gEntity080ddad0;  // 0x03000170

INCASM("asm/entity_080ddad0.inc");
