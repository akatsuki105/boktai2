#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[4964 - 0x18];
} EntityDA0B;
static_assert(sizeof(EntityDA0B) == 4964);

IWRAM_DATA EntityDA0B* gEntityDA0B = NULL;  // 0x03000098

INCASM("asm/entity_da0b.inc");
