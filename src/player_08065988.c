#include "armor.h"
#include "global.h"
#include "player.h"
#include "vm.h"
#include "weapon.h"

void FUN_08064a64(Player* p, const ArmorData* a);

NAKED UNK_PTR FUN_08064db0(Player* p) { INCFUNC("asm/func/FUN_08064db0.inc"); }

NAKED void FUN_08064fd8(Player* p, magic32_t n) { INCFUNC("asm/func/FUN_08064fd8.inc"); }

NAKED s32 FUN_08065110(Player* p) { INCFUNC("asm/func/FUN_08065110.inc"); }

NAKED void FUN_08065164(Player* p) { INCFUNC("asm/func/FUN_08065164.inc"); }

NAKED void FUN_08065200(Player* p) { INCFUNC("asm/func/FUN_08065200.inc"); }

NAKED void FUN_0806521c(Player* p) { INCFUNC("asm/func/FUN_0806521c.inc"); }

void FUN_08065240(Player* p) {
  if (prepare_08231510(0x52) != 0) {
    p->scriptID_9c4 = Script_GetValue();
  } else {
    p->scriptID_9c4 = 0;
  }
}

NAKED void* FUN_08065270(Player* p) { INCFUNC("asm/func/FUN_08065270.inc"); }

NAKED void FUN_0806540c(Player* p) { INCFUNC("asm/func/FUN_0806540c.inc"); }
NAKED void FUN_08065514(Player* p) { INCFUNC("asm/func/FUN_08065514.inc"); }

NAKED bool32 FUN_08065744(Player* p, u32 n) { INCFUNC("asm/func/FUN_08065744.inc"); }

void weapon_08065924(Player* p) {
  Weapon* w;

  if (p->kind != PLAYER_SABATA) {
    if (REGISTERED_WEAPON(gStat->equippedWeaponIdx) >= 0) {
      weapon_08064664(p, GetWeapon(REGISTERED_WEAPON(gStat->equippedWeaponIdx)));
    } else {
      weapon_08064664(p, NULL);
    }
  } else {
    weapon_08064664(p, NULL);
    if (p->unk_18 == 0) {
      SetWeaponFoundFlag(WEAPON_GUN_DEL_HELL);
    }
  }
}

void armor_08065988(Player* p) {
  const ArmorData* a;

  if (p->kind != PLAYER_SABATA) {
    if (gStat->armor < 0) {
      a = NULL;
    } else {
      a = &gArmorDB[ARMORS(gStat->armor)];
    }
  } else {
    SetArmorFoundFlag(ARMOR_MAIL_OF_LUNA);
    a = &gArmorDB[ARMOR_MAIL_OF_LUNA];
  }

  FUN_08064a64(p, a);
}
