#include "enemy.h"
#include "global.h"
#include "malloc.h"

// バット, ヴァンパイアバット (プレイヤーが変身するCバット(PLAYER_BAT)などと混同しない様に Bat ではなく EnemyBat)
typedef struct {
  Enemy e;
  u8 unk_654[1728 - sizeof(Enemy)];
} EnemyBat;
static_assert(sizeof(EnemyBat) == 1728);

void FUN_0813f9a8(EnemyBat*);
void FUN_0813fbf8(EnemyBat*);
void FUN_0813fc9c(EnemyBat*);
void FUN_0813fd24(EnemyBat*);
void FUN_0813fe34(EnemyBat*);
void FUN_08140eb0(EnemyBat*);
void FUN_081410cc(EnemyBat*);

void (*const PTR_ARRAY_085ad7d0[5])(EnemyBat*) = {
    FUN_0813fc9c,
    FUN_0813fbf8,
    FUN_0813f9a8,
    FUN_0813fd24,
    FUN_0813fe34,
};  // 0x085AD7D0

const u32 u32_ARRAY_085ad7e4[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085AD7E4

void (*const PTR_ARRAY_085ad804[2])(EnemyBat*) = {
    FUN_08140eb0,
    FUN_081410cc,
};  // 0x085AD804

void FUN_08140278(EnemyBat*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad80c[7])(EnemyBat*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08140278,
};  // 0x085AD80C

INCASM("asm/bat.inc");

NAKED s32 EnemyBat_Destroy(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 EnemyBat_Init(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Init.inc"); }

void EnemyBat_Create(void) {
  EnemyBat* p = Malloc(sizeof(EnemyBat));

  if (p != NULL) {
    ClearMemory(p, sizeof(EnemyBat));
    if (EnemyBat_Init(p) < 0) {
      EnemyBat_Destroy(p);
      Free(p);
    }
  }
}
