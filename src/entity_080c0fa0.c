#include "entity.h"
#include "global.h"

// _Create が Entity080c0fa0_Create と FUN_080c1108 の2つあるが、後者は使われていない
typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[124 - 0x18];
} Entity080c0fa0;
static_assert(sizeof(Entity080c0fa0) == 124);

INCASM("asm/entity_080c0fa0.inc");
