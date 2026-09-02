#include "entity.h"
#include "global.h"

typedef struct EntityCBB0 {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[6108 - 0x18];
} EntityCBB0;
static_assert(sizeof(EntityCBB0) == 6108);

extern EntityCBB0* gEntityCBB0;  // 0x03002C58

INCASM("asm/entity_cbb0.inc");
