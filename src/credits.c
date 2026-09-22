#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[948 - 0x18];
} Credits;
static_assert(sizeof(Credits) == 948);

IWRAM_DATA Credits* gCredits = NULL;  // 0x030000D0

INCASM("asm/credits.inc");
