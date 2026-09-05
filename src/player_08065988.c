#include "armor.h"
#include "global.h"
#include "player.h"
#include "vm.h"
#include "weapon.h"

void FUN_08065164(Player* p);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void Player_Init_Helper_08063b6c(Player* p);
void FUN_0807ddbc(Player* p);

void FUN_08064a64(Player* p, const ArmorData* a);

NAKED void FUN_08065200(Player* p) { INCFUNC("asm/func/FUN_08065200.inc"); }

NAKED void FUN_0806521c(Player* p) { INCFUNC("asm/func/FUN_0806521c.inc"); }

void FUN_08065240(Player* p) {
  if (VM_SeekToKeyword(0x52) != 0) {
    p->scriptID_9c4 = Script_GetValue();
  } else {
    p->scriptID_9c4 = 0;
  }
}

NAKED void* Player_Init_Helper_08065270(Player* p) { INCFUNC("asm/func/Player_Init_Helper_08065270.inc"); }

NAKED void FUN_0806540c(Player* p) { INCFUNC("asm/func/FUN_0806540c.inc"); }
NAKED void FUN_08065514(Player* p) { INCFUNC("asm/func/FUN_08065514.inc"); }

NAKED bool32 FUN_08065744(Player* p, u32 n) { INCFUNC("asm/func/FUN_08065744.inc"); }

void Player_InitWeapon(Player* p) {
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

// 現在装備している防具の効果をプレイヤーに反映させる, Player_Init時に呼ばれる
void Player_InitArmor(Player* p) {
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

NAKED void Player_Init_Helper_080659e8(Player* p) { INCFUNC("asm/func/Player_Init_Helper_080659e8.inc"); }

NAKED bool32 FUN_08065a98(u32 val) { INCFUNC("asm/func/FUN_08065a98.inc"); }

NAKED bool32 FUN_08065ad0(u32 val) { INCFUNC("asm/func/FUN_08065ad0.inc"); }

NAKED bool32 FUN_08065b08(u32 val) { INCFUNC("asm/func/FUN_08065b08.inc"); }

NAKED bool32 FUN_08065b44(u32 val) { INCFUNC("asm/func/FUN_08065b44.inc"); }

NAKED void FUN_08065b7c(Player* p) { INCFUNC("asm/func/FUN_08065b7c.inc"); }

NAKED s32 FUN_08065cb8(Player* p) { INCFUNC("asm/func/FUN_08065cb8.inc"); }

NAKED void FUN_08065dac(Player* p) { INCFUNC("asm/func/FUN_08065dac.inc"); }

NAKED s32 FUN_08065e24(Player* p) { INCFUNC("asm/func/FUN_08065e24.inc"); }

NAKED bool32 FUN_08065f34(Player* p, Vec3* pos) { INCFUNC("asm/func/FUN_08065f34.inc"); }

NAKED s32 FUN_08066040(Player* p) { INCFUNC("asm/func/FUN_08066040.inc"); }

NAKED void FUN_0806623c(Player* p) { INCFUNC("asm/func/FUN_0806623c.inc"); }

NAKED void FUN_08066408(Player* p) { INCFUNC("asm/func/FUN_08066408.inc"); }

NAKED void FUN_08066794(Player* p) { INCFUNC("asm/func/FUN_08066794.inc"); }

NAKED void FUN_080667b0(Player* p, s32 sungauge) { INCFUNC("asm/func/FUN_080667b0.inc"); }

NAKED bool32 FUN_0806680c(Player* p) { INCFUNC("asm/func/FUN_0806680c.inc"); }

NAKED void FUN_0806687c(Player* p) { INCFUNC("asm/func/FUN_0806687c.inc"); }

NAKED void FUN_0806692c(Player* p) { INCFUNC("asm/func/FUN_0806692c.inc"); }

NAKED void FUN_08066a04(Player* p) { INCFUNC("asm/func/FUN_08066a04.inc"); }

NAKED void FUN_08066abc(Player* p) { INCFUNC("asm/func/FUN_08066abc.inc"); }

NAKED void FUN_08066c64(Player* p) { INCFUNC("asm/func/FUN_08066c64.inc"); }

NAKED void FUN_08066d10(Player* p) { INCFUNC("asm/func/FUN_08066d10.inc"); }

NAKED bool32 FUN_08066d2c(Player* p, s32 val) { INCFUNC("asm/func/FUN_08066d2c.inc"); }

NAKED void FUN_08066d7c(Player* p, s32 val) { INCFUNC("asm/func/FUN_08066d7c.inc"); }

INCASM("asm/player_08065988.inc");

NAKED void FUN_0807e854(Player* p) { INCFUNC("asm/func/FUN_0807e854.inc"); }

NAKED bool32 Player_Update_Helper_0807e968(Player* p) { INCFUNC("asm/func/Player_Update_Helper_0807e968.inc"); }

NAKED void FUN_0807eca8(Player* p) { INCFUNC("asm/func/FUN_0807eca8.inc"); }

NAKED void FUN_0807ed04(Player* p) { INCFUNC("asm/func/FUN_0807ed04.inc"); }

NAKED void Player_Update_Helper_0807ee58(Player* p) { INCFUNC("asm/func/Player_Update_Helper_0807ee58.inc"); }

NAKED void FUN_0807f0bc(Player* p) { INCFUNC("asm/func/FUN_0807f0bc.inc"); }

NAKED void dark_django_0807f13c(Player* p) { INCFUNC("asm/func/dark_django_0807f13c.inc"); }

NAKED static s32 Player_Update(Player* p) { INCFUNC("asm/func/Player_Update.inc"); }

NAKED static s32 Player_Destroy(Player* p) { INCFUNC("asm/func/Player_Destroy.inc"); }

static s32 Player_Init(Player* p, u32 n, void* _) {
  FUN_08065200(p);
  Player_Init_Helper_08065270(p);
  FUN_08065744(p, n);
  Player_Init_Helper_080659e8(p);
  FUN_08065164(p);
  Player_InitWeapon(p);
  Player_InitArmor(p);
  CheckHeartJokerEmblem(p);
  FUN_08061294(p);
  Player_Init_Helper_08063b6c(p);
  FUN_0807ddbc(p);
  FUN_08065240(p);
  gPlayerPtr[(p->unk_24).unk_4] = p;
  gPlayerCount++;
  if ((p->unk_24).unk_4 == 0) {
    FUN_0807ed04(p);
    FUN_0809c464();
  }
  return 0;
}

// エリア移動などでも呼ばれる
Player* CreatePlayer(u32 n, void* _) {
  s32 ok;
  Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));
  if (p != NULL) {
    SetEntityRoutine(p, Player_Update, Player_Destroy);
    ok = Player_Init(p, n, _);
    if (ok < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
