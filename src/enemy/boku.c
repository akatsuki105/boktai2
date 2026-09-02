#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  Entity2UnkData unk_0;  // 0x000
  SpriteData* sprite;    // 0x044
  UnkStruct52 unk_48;    // 0x048, 0x08102d1e
  u8 unk_7c[0x25D - 0x7C];
  bool8 isSpriteSet;  // 0x25D, true: SpriteSet, false: ActorSprite
  u8 unk_25e[0x63C - 0x25E];
  void* p_63c;  // 0x63C
  u8 unk_640[108];
} Boku;
static_assert(sizeof(Boku) == 1708);

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

INCASM("asm/boku.inc");

s32 EnemyBoku_Init(Boku* p);
s32 EnemyBoku_Destroy(Boku* p);

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
