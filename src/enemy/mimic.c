#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1684 - sizeof(Enemy)];
} Mimic;
static_assert(sizeof(Mimic) == 1684);

INCASM("asm/mimic.inc");
