#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1696 - sizeof(Enemy)];
} RootOfDarkness;
static_assert(sizeof(RootOfDarkness) == 1696);

s32 EnemyRootOfDarkness_Destroy(RootOfDarkness*);

INCASM("asm/root_of_darkness.inc");

NAKED s32 EnemyRootOfDarkness_Init(RootOfDarkness* p) { INCFUNC("asm/func/EnemyRootOfDarkness_Init.inc"); }

void EnemyRootOfDarkness_Create(void) {
  RootOfDarkness* p = Malloc(sizeof(RootOfDarkness));

  if (p != NULL) {
    ClearMemory(p, sizeof(RootOfDarkness));
    if (EnemyRootOfDarkness_Init(p) < 0) {
      EnemyRootOfDarkness_Destroy(p);
      Free(p);
    }
  }
}
