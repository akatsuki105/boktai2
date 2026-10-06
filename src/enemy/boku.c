#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1708 - sizeof(Enemy)];
} Boku;
static_assert(sizeof(Boku) == 1708);

bool32 FUN_080f06b0(Enemy* p);

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
