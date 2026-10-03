#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1692 - sizeof(Enemy)];
} EnemyOctopus;
static_assert(sizeof(EnemyOctopus) == 1692);

INCASM("asm/octopus.inc");
