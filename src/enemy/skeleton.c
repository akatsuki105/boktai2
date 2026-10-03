#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1960 - sizeof(Enemy)];
} Skeleton;
static_assert(sizeof(Skeleton) == 1960);

INCASM("asm/skeleton.inc");

NAKED void EnemySkeleton_Create(void) { INCFUNC("asm/func/EnemySkeleton_Create.inc"); }
