#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048
  u8 unk_7c[1812 - 0x7C];  // 0x07C
} Bee;
static_assert(sizeof(Bee) == 1812);

INCASM("asm/bee.inc");

NAKED s32 EnemyBee_Init(Bee* p) { INCFUNC("asm/func/EnemyBee_Init.inc"); }

NAKED void EnemyBee_Create(void) { INCFUNC("asm/func/EnemyBee_Create.inc"); }
