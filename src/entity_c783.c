#include "entity.h"
#include "global.h"

typedef struct EntityC783 {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[988 - 0x18];
} EntityC783;
static_assert(sizeof(EntityC783) == 988);

extern EntityC783* gEntityC783;  // 0x030001A8

INCASM("asm/entity_c783.inc");
