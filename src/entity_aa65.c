#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[116 - 0x18];
} EntityAA65;
static_assert(sizeof(EntityAA65) == 116);

COMMON_DATA EntityAA65* gEntityAA65 = NULL;  // 0x03002B34

INCASM("asm/entity_aa65.inc");
