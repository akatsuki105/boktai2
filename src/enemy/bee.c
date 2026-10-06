#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1812 - sizeof(Enemy)];
} Bee;
static_assert(sizeof(Bee) == 1812);

INCASM("asm/bee.inc");

NAKED s32 EnemyBee_Init(Bee* p) { INCFUNC("asm/func/EnemyBee_Init.inc"); }

NAKED void EnemyBee_Create(void) { INCFUNC("asm/func/EnemyBee_Create.inc"); }
