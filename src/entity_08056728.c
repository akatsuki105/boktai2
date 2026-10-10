#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[3504 - 0x18];
} Entity08056728;
static_assert(sizeof(Entity08056728) == 3504);

IWRAM_DATA Entity08056728* gEntity08056728 = NULL;  // 0x03000128
IWRAM_DATA u8 u8_0300012c[0x130 - 0x12c] = {};

INCASM("asm/entity_08056728.inc");
