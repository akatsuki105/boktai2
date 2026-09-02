#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048, 0x081a6546
  u8 unk_7c[1696 - 0x7C];  // 0x07C
} RootOfDarkness;
static_assert(sizeof(RootOfDarkness) == 1696);

INCASM("asm/root_of_darkness.inc");

NAKED s32 EnemyRootOfDarkness_Init(RootOfDarkness* p) { INCFUNC("asm/func/EnemyRootOfDarkness_Init.inc"); }

NAKED void EnemyRootOfDarkness_Create(void) { INCFUNC("asm/func/EnemyRootOfDarkness_Create.inc"); }
