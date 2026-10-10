#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[320 - 0x18];
} Entity080c1abc;
static_assert(sizeof(Entity080c1abc) == 320);

INCASM("asm/entity_080c1abc.inc");
