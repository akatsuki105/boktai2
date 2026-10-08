#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1960 - sizeof(Enemy)];
} Skeleton;
static_assert(sizeof(Skeleton) == 1960);

s32 EnemySkeleton_Init(Skeleton*);
s32 EnemySkeleton_Destroy(Skeleton*);

INCASM("asm/skeleton.inc");

void EnemySkeleton_Create(void) {
  Skeleton* p = Malloc(sizeof(Skeleton));

  if (p != NULL) {
    ClearMemory(p, sizeof(Skeleton));
    if (EnemySkeleton_Init(p) < 0) {
      EnemySkeleton_Destroy(p);
      Free(p);
    }
  }
}
