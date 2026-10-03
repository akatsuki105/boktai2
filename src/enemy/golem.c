#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1764 - sizeof(Enemy)];
} Golem;
static_assert(sizeof(Golem) == 1764);

INCASM("asm/golem.inc");
