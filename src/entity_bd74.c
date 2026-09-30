#include "entity.h"
#include "global.h"

typedef struct EntityBD74 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[940 - 0x18];
} EntityBD74;
static_assert(sizeof(EntityBD74) == 940);

extern EntityBD74* gEntityBD74;  // 0x03002BFC

INCASM("asm/entity_bd74.inc");
