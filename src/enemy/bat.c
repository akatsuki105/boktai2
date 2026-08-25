#include "global.h"
#include "struct.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048
  u8 unk_7c[1728 - 0x7C];  // 0x07C
} Bat;
static_assert(sizeof(Bat) == 1728);

INCASM("asm/bat.inc");

NAKED s32 EnemyBat_Init(Bat* p) { INCFUNC("asm/func/EnemyBat_Init.inc"); }

NAKED void EnemyBat_Create(void) { INCFUNC("asm/func/EnemyBat_Create.inc"); }
