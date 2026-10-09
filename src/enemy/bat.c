#include "enemy.h"
#include "global.h"
#include "malloc.h"

// バット, ヴァンパイアバット (プレイヤーがチェンジバットで変身するコウモリと混同しないように注意)
typedef struct {
  ENEMY_HDR;
  u8 unk_654[1728 - sizeof(Enemy)];
} EnemyBat;
static_assert(sizeof(EnemyBat) == 1728);

void FUN_0813f9a8(Enemy* p);
void FUN_0813fbf8(Enemy* p);
void FUN_0813fc9c(Enemy* p);
void FUN_0813fd24(Enemy* p);
void FUN_0813fe34(Enemy* p);
void FUN_08140eb0(Enemy* p);
void FUN_081410cc(Enemy* p);

void FUN_08140278(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad7d0[5])(Enemy*) = {
    FUN_0813fc9c,
    FUN_0813fbf8,
    FUN_0813f9a8,
    FUN_0813fd24,
    FUN_0813fe34,
};  // 0x085AD7D0

const u32 u32_ARRAY_085ad7e4[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085AD7E4

void (*const PTR_ARRAY_085ad804[2])(Enemy*) = {
    FUN_08140eb0,
    FUN_081410cc,
};  // 0x085AD804

// メッセージ表
void (*const PTR_ARRAY_085ad80c[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08140278,
};  // 0x085AD80C

INCASM("asm/bat.inc");

NAKED s32 EnemyBat_Destroy(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Destroy.inc"); }

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
