#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1728 - sizeof(Enemy)];
} EnemyBat;
static_assert(sizeof(EnemyBat) == 1728);

INCASM("asm/bat.inc");

NAKED s32 EnemyBat_Init(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Init.inc"); }

NAKED void EnemyBat_Create(void) { INCFUNC("asm/func/EnemyBat_Create.inc"); }
