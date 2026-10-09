#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1812 - sizeof(Enemy)];
} Bee;
static_assert(sizeof(Bee) == 1812);

void FUN_081678bc(Enemy* p);
void FUN_0816883c(Enemy* p);
void FUN_08168d2c(Enemy* p);
void FUN_08168df0(Enemy* p);
void FUN_08168eb0(Enemy* p);
void FUN_08169050(Enemy* p);
void FUN_08169188(Enemy* p);

void FUN_08167a38(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ada14[1])(Enemy*) = {
    FUN_081678bc,
};  // 0x085ADA14

const u32 u32_ARRAY_085ada18[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085ADA18

void (*const PTR_ARRAY_085ada38[5])(Enemy*) = {
    FUN_0816883c,
    FUN_08168d2c,
    FUN_08168df0,
    FUN_08168eb0,
    FUN_08169050,
};  // 0x085ADA38

void (*const PTR_ARRAY_085ada4c[7])(Enemy*) = {
    FUN_080f1de4,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
    FUN_08169188,
};  // 0x085ADA4C

// メッセージ表
void (*const PTR_ARRAY_085ada68[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08167a38,
};  // 0x085ADA68

INCASM("asm/bee.inc");

NAKED s32 EnemyBee_Destroy(Bee* p) { INCFUNC("asm/func/EnemyBee_Destroy.inc"); }

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
