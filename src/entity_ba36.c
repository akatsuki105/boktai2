#include "entity.h"
#include "global.h"

typedef struct EntityBA36 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[32 - 0x18];
} EntityBA36;
static_assert(sizeof(EntityBA36) == 32);

extern EntityBA36* gEntityBA36;  // 0x03002C40

INCASM("asm/entity_ba36.inc");
