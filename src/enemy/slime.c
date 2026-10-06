#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1680 - sizeof(Enemy)];
} EnemySlime;
static_assert(sizeof(EnemySlime) == 1680);

INCASM("asm/slime.inc");
