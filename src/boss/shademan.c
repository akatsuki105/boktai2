#include "boss.h"
#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2396 - 0x18];
} BossShadeMan;
static_assert(sizeof(BossShadeMan) == 2396);

s32 FUN_0803c1bc(void* _) { return 7; }

INCASM("asm/shademan.inc");
