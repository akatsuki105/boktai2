
#include "enemy.h"
#include "enemy_target.h"
#include "global.h"
#include "player.h"

// enedefault.c と同様にいろんなエネミーから呼ばれる関数群

s32 FUN_08240b98(u32 param_1, s8 param_2);
void FUN_080e8ae4(unknown* param_1, u32 param_2, u32 param_3);

s32 UNUSED FUN_080f9bf8(unknown* p, s32 val) { return val; }

void FUN_080f9bfc(Enemy* p) {
  p->unk_21e = 0;
  p->unk_220 = 0;
  p->unk_202 = 0;
  p->playerMover = NULL;
}

NAKED void FUN_080f9c20(Enemy* p) { INCFUNC("asm/func/FUN_080f9c20.inc"); }

NAKED void FUN_080f9e34(Enemy* p) { INCFUNC("asm/func/FUN_080f9e34.inc"); }

void FUN_080f9ee0(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }
  if (!p->unk_608(p)) {
    p->subStateTimer++;
  }
}

NAKED s32 FUN_080f9f20(Enemy* p) { INCFUNC("asm/func/FUN_080f9f20.inc"); }

NAKED s32 FUN_080fa2ac(Enemy* p, Vec3* pos, u32 param_3) { INCFUNC("asm/func/FUN_080fa2ac.inc"); }

s32 FUN_080fa354(unknown* param_1, u32 param_2, s8 param_3) {
  s32 ret = FUN_08240b98(param_2, param_3);

  if (ret == 0xB546) {
    FUN_080e8ae4(param_1, param_2, param_2);
  }
  return ret;
}

NAKED s32 FUN_080fa384(Enemy* p) { INCFUNC("asm/func/FUN_080fa384.inc"); }

void FUN_080fa77c(Enemy* p) {
  if (p->unk_220 != 0) {
    p->unk_220--;
  } else {
    p->unk_21e = 0;
  }
}

NAKED bool8 FUN_080fa7a4(Enemy* p) { INCFUNC("asm/func/FUN_080fa7a4.inc"); }

NAKED s32 FUN_080fa958(Vec3* pos) { INCFUNC("asm/func/FUN_080fa958.inc"); }

bool32 FUN_080faa98(Enemy* p) {
  s32 idx = FUN_080fa958(&p->mover.pos);
  if (idx < 0) {
    p->unk_5c4(p);
    return FALSE;
  }
  p->playerMover = &gPlayerPtr[idx]->mover;
  return TRUE;
}

NAKED void FUN_080faad8(Enemy* p) { INCFUNC("asm/func/FUN_080faad8.inc"); }
