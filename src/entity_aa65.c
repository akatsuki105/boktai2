#include "entity.h"
#include "global.h"

typedef struct EntityAA65 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[116 - 0x18];
} EntityAA65;
static_assert(sizeof(EntityAA65) == 116);

extern EntityAA65* gEntityAA65;  // 0x03002B34

INCASM("asm/entity_aa65.inc");
