#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1812 - sizeof(Enemy)];
} Bee;
static_assert(sizeof(Bee) == 1812);

s32 EnemyBee_Destroy(Bee*);

INCASM("asm/bee.inc");

NAKED s32 EnemyBee_Init(Bee* p) { INCFUNC("asm/func/EnemyBee_Init.inc"); }

void EnemyBee_Create(void) {
  Bee* p = Malloc(sizeof(Bee));

  if (p != NULL) {
    ClearMemory(p, sizeof(Bee));
    if (EnemyBee_Init(p) < 0) {
      EnemyBee_Destroy(p);
      Free(p);
    }
  }
}
