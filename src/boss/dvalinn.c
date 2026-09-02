#include "boss.h"
#include "entity.h"
#include "global.h"

// ボス戦前の人型のイベント時もこれ使う
typedef struct Dvalinn {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[2120 - 0x18];
} Dvalinn;
static_assert(sizeof(Dvalinn) == 2120);

INCASM("asm/dvalinn.inc");
