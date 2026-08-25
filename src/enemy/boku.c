#include "enemy.h"
#include "global.h"
#include "struct.h"

typedef struct {
  Entity2UnkData unk_0;  // 0x000
  SpriteData* sprite;    // 0x044
  UnkStruct52 unk_48;    // 0x048
  u8 unk_7c[1596 - 0x7C];
  void* p_63c;  // 0x63C
  u8 unk_640[108];
} Boku;
static_assert(sizeof(Boku) == 1708);

NAKED void FUN_080ff470(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff470.inc"); }

void FUN_080ff668(Boku* p) { p->p_63c = (void*)0x085AD4D8; }

NAKED void FUN_080ff67c(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff67c.inc"); }

NAKED void FUN_080ff6e8(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff6e8.inc"); }

NAKED void FUN_080ff7c0(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff7c0.inc"); }

NAKED void FUN_080ffa44(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffa44.inc"); }

NAKED void FUN_080ffad8(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffad8.inc"); }

void FUN_080ffc28(void) {}

NAKED void FUN_080ffc2c(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffc2c.inc"); }

NAKED UNK_PTR FUN_080ffcd0(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffcd0.inc"); }

INCASM("asm/boku.inc");

// a.k.a. BokEnemy_Create
NAKED void EnemyBoku_Create(void) { INCFUNC("asm/func/EnemyBoku_Create.inc"); }
