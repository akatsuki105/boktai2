#include "global.h"

NAKED void FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

NAKED s32 FUN_080de088(UNK_PTR p) { INCFUNC("asm/func/FUN_080de088.inc"); }

Entity* FUN_080ddb28(Entity* p);
Entity* FUN_080ddca0(Entity* p);

UNK_PTR FUN_080de11c(void) {
  Entity* p;
  if (*(Entity**)0x03000174 == NULL) {
    p = CreateEntity(ENTITY_UNK_9, 3300);
    if (p != NULL) {
      SetEntityRoutine(p, FUN_080ddb28, FUN_080ddca0);
      if (FUN_080de088(p) < 0) {
        KillEntity(p);
        return NULL;
      }
    }
    return p;
  }
  return *(Entity**)0x03000174;
}

void FUN_080de168(void) { *(s32*)0x03000174 = 0; }

INCASM("asm/code_080ddf88.inc");

NAKED void FUN_080ff470(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff470.inc"); }

void FUN_080ff668(UNK_PTR p) { *(void**)((u8*)p + 0x63C) = (void*)0x085AD4D8; }

NAKED void FUN_080ff67c(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff67c.inc"); }

NAKED void FUN_080ff6e8(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff6e8.inc"); }

NAKED void FUN_080ff7c0(UNK_PTR p) { INCFUNC("asm/func/FUN_080ff7c0.inc"); }

NAKED void FUN_080ffa44(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffa44.inc"); }

NAKED void FUN_080ffad8(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffad8.inc"); }

void FUN_080ffc28(void) {}

NAKED void FUN_080ffc2c(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffc2c.inc"); }

NAKED UNK_PTR FUN_080ffcd0(UNK_PTR p) { INCFUNC("asm/func/FUN_080ffcd0.inc"); }
