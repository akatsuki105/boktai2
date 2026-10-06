#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1680 - sizeof(Enemy)];
} EnemySpider;
static_assert(sizeof(EnemySpider) == 1680);

INCASM("asm/spider.inc");
