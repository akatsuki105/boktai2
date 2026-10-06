#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1728 - sizeof(Enemy)];
} Crow;
static_assert(sizeof(Crow) == 1728);

INCASM("asm/crow.inc");
