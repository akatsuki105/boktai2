#include "enemy.h"
#include "global.h"
#include "malloc.h"

// 暗黒の根
typedef struct {
  ENEMY_HDR;
  u8 unk_654[1696 - sizeof(Enemy)];
} RootOfDarkness;
static_assert(sizeof(RootOfDarkness) == 1696);

void FUN_081a4648(Enemy* p);
void FUN_081a473c(Enemy* p);
void FUN_081a483c(Enemy* p);
void FUN_081a48d0(Enemy* p);
void FUN_081a48e8(Enemy* p);
void FUN_081a493c(Enemy* p);
void FUN_081a49c0(Enemy* p);
void FUN_081a4a44(Enemy* p);
void FUN_081a4aa0(Enemy* p);
void FUN_081a4b30(Enemy* p);

void FUN_081a4ccc(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ade60[4])(Enemy*) = {
    FUN_081a483c,
    FUN_081a493c,
    FUN_081a49c0,
    FUN_081a48d0,
};  // 0x085ADE60

void (*const PTR_ARRAY_085ade70[4])(Enemy*) = {
    FUN_081a4648,
    FUN_081a473c,
    FUN_081a48e8,
    FUN_081a4b30,
};  // 0x085ADE70

void (*const PTR_ARRAY_085ade80[3])(Enemy*) = {
    FUN_081a4a44,
    FUN_080f1cb8,
    FUN_081a4aa0,
};  // 0x085ADE80

// メッセージ表
void (*const PTR_ARRAY_085ade8c[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081a4ccc,
};  // 0x085ADE8C

INCASM("asm/root_of_darkness.inc");

NAKED s32 EnemyRootOfDarkness_Destroy(RootOfDarkness* p) { INCFUNC("asm/func/EnemyRootOfDarkness_Destroy.inc"); }

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
