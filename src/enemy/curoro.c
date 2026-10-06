#include "enemy.h"
#include "global.h"
#include "malloc.h"

// クロロホルルン
typedef struct {
  ENEMY_HDR;
  u8 unk_654[1712 - sizeof(Enemy)];
} Curoro;
static_assert(sizeof(Curoro) == 1712);

INCASM("asm/curoro.inc");
