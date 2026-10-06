#include "entity.h"
#include "global.h"
#include "vm.h"

typedef struct EntityA628 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[56 - 0x18];
} EntityA628;
static_assert(sizeof(EntityA628) == 56);

extern EntityA628* gEntityA628;  // 0x03002C3C

INCASM("asm/entity_a628.inc");
