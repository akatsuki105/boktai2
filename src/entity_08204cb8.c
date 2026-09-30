#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1152 - 0x18];
} Entity08204cb8;
static_assert(sizeof(Entity08204cb8) == 1152);

IWRAM_DATA Entity08204cb8* gEntity08204cb8 = NULL;  // 0x03000220
IWRAM_DATA u8 u8_03000224[4] = {};                  // 8-byte alignment padding
IWRAM_DATA rgb555 rgb555_ARRAY_03000228[16] = {};   // 0x03000228

INCASM("asm/entity_08204cb8.inc");
