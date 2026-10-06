#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[3688 - sizeof(Enemy)];
} EnemyAx;
static_assert(sizeof(EnemyAx) == 3688);

INCASM("asm/ax.inc");
