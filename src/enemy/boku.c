#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  Entity2UnkData unk_0;     // 0x000
  EnemySpriteData* sprite;  // 0x044
  EntityMsgBox msgbox;      // 0x048, 0x08102d1e
  u8 unk_7c[0x25D - 0x7C];
  bool8 isMainSprite;  // 0x25D, true: Main, false: Aux
  u8 unk_25e[0x63C - 0x25E];
  void* p_63c;  // 0x63C
  u8 unk_640[108];
} Boku;
static_assert(sizeof(Boku) == 1708);

INCASM("asm/boku.inc");

NAKED void FUN_080ff45c(Boku* p) { INCFUNC("asm/func/FUN_080ff45c.inc"); }

NAKED void FUN_080ff470(unknown* p) { INCFUNC("asm/func/FUN_080ff470.inc"); }

void FUN_080ff668(Boku* p) { p->p_63c = (void*)0x085AD4D8; }

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

NAKED bool32 FUN_08101bb4(Boku* p) { INCFUNC("asm/func/FUN_08101bb4.inc"); }

NAKED bool32 FUN_08101bc0(Boku* p) { INCFUNC("asm/func/FUN_08101bc0.inc"); }

// FUN_080edebc から呼ばれる
NAKED s32 FUN_08101c1c(unknown* p) { INCFUNC("asm/func/FUN_08101c1c.inc"); }

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
