#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;     // 0x000
  EnemySpriteData* sprite;  // 0x044
  EntityMsgBox msgbox;      // 0x048
  u8 unk_7c[1960 - 0x7C];   // 0x07C
} Skeleton;
static_assert(sizeof(Skeleton) == 1960);

INCASM("asm/skeleton.inc");

NAKED void EnemySkeleton_Create(void) { INCFUNC("asm/func/EnemySkeleton_Create.inc"); }
