#include "player.h"

#include "global.h"
#include "item.h"

void Script_ExecById(s32 scriptID, s32 r1);

NAKED void FUN_080609dc(Player* p) { INCFUNC("asm/func/FUN_080609dc.inc"); }

NAKED bool32 FUN_08060a24(Player* p, u32 val1, s32 val2) { INCFUNC("asm/func/FUN_08060a24.inc"); }

NAKED void FUN_08060aa4(Player* p, s32 val) { INCFUNC("asm/func/FUN_08060aa4.inc"); }

void FUN_08060b84(Player* p, u32 r1, u32 r2) {
  p->unk_37c = r1;
  p->unk_37d = r2;
  p->unk_37e = 0;
}

NAKED void FUN_08060bac(Player* p) { INCFUNC("asm/func/FUN_08060bac.inc"); }

void FUN_08060c40(Player* p, u32 val) { p->unk_35a |= val; }

u32 FUN_08060c50(Player* p, u32 mask) { return p->unk_35a & mask; }

NAKED void FUN_08060c60(Player* p) { INCFUNC("asm/func/FUN_08060c60.inc"); }

NAKED u32 FUN_08060c98(UNK_PTR r1, UNK_PTR r2) { INCFUNC("asm/func/FUN_08060c98.inc"); }

NAKED void FUN_08060cf8(Player* p, UNK_PTR r1, UNK_PTR r2) { INCFUNC("asm/func/FUN_08060cf8.inc"); }

NAKED bool32 FUN_08060e1c(Player* p) { INCFUNC("asm/func/FUN_08060e1c.inc"); }

s32 GetPlayerCoffinID(void) {
  s32 slot;
  for (slot = 0; slot < VALUABLE_CAP; slot++) {
    u32 itemID = GetValuableItemID(slot);
    if ((itemID - ITEM_OAK_COFFIN) < COFFIN_NUM) {
      return itemID - ITEM_OAK_COFFIN;
    }
  }
  return COFFIN_OAK;
}

void FUN_08060e90(Player* p, u32 r1) {
  u32 scriptID = p->scriptID_9c4;
  if (scriptID != 0) {
    struct {
      s32 arg;
      u32 flags;
      s32* argPtr;
    } local;
    s32* pw;
    u32 mask = 0xFFFF0000;
    local.flags = (local.flags & mask) | 1;
    local.arg = r1;
    pw = (s32*)&local.flags;
    pw[1] = (s32)&local.arg;
    Script_ExecById(scriptID, (s32)pw);
  }
}

void FUN_08060ec8(Player* p, u32 r1) {
  p->unk_9bc |= r1;
  return;
}

u32 FUN_08060ed8(Player* p, u32 r1) { return p->unk_9bc & r1; }

void FUN_08060ee8(Player* p) {
  if (p->scriptID_9c0 != 0) {
    Script_ExecById(p->scriptID_9c0, 0);
  }
}

NAKED void FUN_08060f00(Player* p) { INCFUNC("asm/func/FUN_08060f00.inc"); }

s32 CalcMaxHP(Player* p) {
  s32 val;
  Player_264* unk264 = &p->unk_264;
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->unk_35c + unk264->unk_26c) + unk264->unk_274;
  } else {
    val = (p->unk_35c + unk264->unk_26c) - unk264->unk_274;
  }
  if (99 < val) {
    val = 99;
  }
  return val * 10;
}

s32 CalcMaxEne(Player* p) {
  s32 val;
  Player_264* unk264 = &p->unk_264;
  if (u32_030047a4 & 0x1000) {
    return 10;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->unk_35e + unk264->unk_26e) + unk264->unk_276;
  } else {
    val = (p->unk_35e + unk264->unk_26e) - unk264->unk_276;
  }
  if (99 < val) {
    val = 99;
  }
  return val * 5 + 100;
}

void UpdateMaxHPEne(Player* p) {
  s32 maxHP, maxEne;

  maxHP = CalcMaxHP(p);
  p->maxHP = maxHP;
  if (p->hp > (u16)maxHP) p->hp = maxHP;

  maxEne = CalcMaxEne(p);
  p->maxEne = maxEne;
  if (p->ene > (u16)maxEne) p->ene = maxEne;
}

NAKED void FUN_080610a4(Player* p) { INCFUNC("asm/func/FUN_080610a4.inc"); }

NAKED void FUN_08061198(Player* p) { INCFUNC("asm/func/FUN_08061198.inc"); }

void FUN_08061294(Player* p) {
  FUN_080610a4(p);
  FUN_08061198(p);
}

void FUN_080612a8(Player* p) {
  UpdateMaxHPEne(p);
  FUN_08061198(p);
}

void FUN_080612bc(Player* p) {
  FUN_08060f00(p);
  UpdateMaxHPEne(p);
  FUN_08061198(p);
}

NAKED void FUN_080612d8(Player* p) { INCFUNC("asm/func/FUN_080612d8.inc"); }

NAKED void FUN_08061384(Player* p) { INCFUNC("asm/func/FUN_08061384.inc"); }

INCASM("asm/player.inc");
