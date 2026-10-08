#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1708 - sizeof(Enemy)];
} Boku;
static_assert(sizeof(Boku) == 1708);

bool32 FUN_080f06b0(Enemy* p);

void FUN_080f2644(Enemy* p);
void FUN_080f2864(Enemy* p);
void FUN_080f248c(Enemy* p);
void FUN_080f2364(Enemy* p);
void FUN_080f2ec0(Enemy* p);
void FUN_080f2d04(Enemy* p);
void FUN_080f2a40(Enemy* p);
void FUN_080f31c4(Enemy* p);
void FUN_080f19cc(Enemy* p);
void FUN_080f33e8(Enemy* p);
void FUN_080f34a0(Enemy* p);
void FUN_080f0e78(Enemy* p);
void FUN_080f11d0(Enemy* p);
void FUN_080f12c4(Enemy* p);
void FUN_080ff06c(unknown* p);
void FUN_080ff270(unknown* p);
void FUN_080ff36c(Enemy* p);
void FUN_080ff470(unknown* p);

// FUN_080ff45c が handlerTables[2] に入れる, 先頭15要素は gEnemyHandlerTable2 と同じ中身
void (*const PTR_ARRAY_085ad490[18])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
    (void*)FUN_080ff06c,
    (void*)FUN_080ff270,
    FUN_080ff36c,
};  // 0x085AD490

// FUN_080ff668 が handlerTables[4] に入れる
void (*const PTR_ARRAY_085ad4d8[1])(Enemy*) = {
    (void*)FUN_080ff470,
};  // 0x085AD4D8

// FUN_080ffcd0 が引く
const u16 u16_ARRAY_085ad4dc[4] = {336, 336, 0, 180};  // 0x085AD4DC

INCASM("asm/boku.inc");

void FUN_080ff45c(Boku* p) { p->handlerTables[2] = (void*)0x085AD490; }

NAKED void FUN_080ff470(unknown* p) { INCFUNC("asm/func/FUN_080ff470.inc"); }

void FUN_080ff668(Boku* p) { p->handlerTables[4] = (void*)0x085AD4D8; }

NAKED void FUN_080ff67c(unknown* p) { INCFUNC("asm/func/FUN_080ff67c.inc"); }

NAKED void FUN_080ff6e8(unknown* p) { INCFUNC("asm/func/FUN_080ff6e8.inc"); }

NAKED void FUN_080ff7c0(unknown* p) { INCFUNC("asm/func/FUN_080ff7c0.inc"); }

NAKED void FUN_080ffa44(unknown* p) { INCFUNC("asm/func/FUN_080ffa44.inc"); }

NAKED void FUN_080ffad8(unknown* p) { INCFUNC("asm/func/FUN_080ffad8.inc"); }

void FUN_080ffc28(void) {}

NAKED void FUN_080ffc2c(Boku* p) { INCFUNC("asm/func/FUN_080ffc2c.inc"); }

NAKED unknown* FUN_080ffcd0(unknown* p) { INCFUNC("asm/func/FUN_080ffcd0.inc"); }

NAKED void FUN_080ffd28(Boku* p) { INCFUNC("asm/func/FUN_080ffd28.inc"); }

NAKED void FUN_080ffd48(Boku* p) { INCFUNC("asm/func/FUN_080ffd48.inc"); }

NAKED void FUN_080ffda8(Boku* p) { INCFUNC("asm/func/FUN_080ffda8.inc"); }

NAKED void FUN_081000a4(Boku* p) { INCFUNC("asm/func/FUN_081000a4.inc"); }

NAKED void FUN_08100164(Boku* p) { INCFUNC("asm/func/FUN_08100164.inc"); }

NAKED void FUN_081001dc(Boku* p) { INCFUNC("asm/func/FUN_081001dc.inc"); }

// デカすぎて複数の関数を1つの関数として間違って扱っている可能性がある
NAKED bool32 FUN_08100228(Boku* p) { INCFUNC("asm/func/FUN_08100228.inc"); }

NAKED bool32 FUN_081019e0(Boku* p) { INCFUNC("asm/func/FUN_081019e0.inc"); }

bool32 FUN_08101bb4(Boku* p) {
  FUN_080ffd28(p);
  return TRUE;
}

NAKED bool32 FUN_08101bc0(Boku* p) { INCFUNC("asm/func/FUN_08101bc0.inc"); }

// FUN_080edebc から呼ばれる
s32 FUN_08101c1c(unknown* p) {
  FUN_080f06b0(p);
  return 0;
}

NAKED s32 EnemyBoku_Destroy(Boku* p) { INCFUNC("asm/func/EnemyBoku_Destroy.inc"); }

NAKED s32 EnemyBoku_Init(Boku* p) { INCFUNC("asm/func/EnemyBoku_Init.inc"); }

void EnemyBoku_Create(void) {
  Boku* p = Malloc(sizeof(Boku));
  if (p != NULL) {
    ClearMemory(p, sizeof(Boku));
    if (EnemyBoku_Init(p) < 0) {
      EnemyBoku_Destroy(p);
      Free(p);
    }
  }
}
