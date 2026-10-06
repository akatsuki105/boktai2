#include "entity.h"
#include "global.h"
#include "hitbox.h"

// _Create が Entity080d84f8_Create と FUN_080d8568 と FUN_080d85d8 の 3つある (_Init, _Update, _Destroy は共有)
typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[180 - 0x18];
} Entity080d84f8;
static_assert(sizeof(Entity080d84f8) == 180);

INCASM("asm/entity_080d84f8.inc");
