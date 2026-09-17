#include "armor.h"
#include "global.h"
#include "player.h"
#include "vm.h"
#include "weapon.h"

// player.c とファイルを分けてるのは、ファイルサイズが大きくなりすぎてコードを把握しにくいからで、解析が進んだら整理する予定

void FUN_08065164(Player* p);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void Player_Init_Helper_08063b6c(Player* p);
void FUN_0807ddbc(Player* p);

void FUN_08064a64(Player* p, const ArmorData* a);

NAKED void FUN_08065200(Player* p) { INCFUNC("asm/func/FUN_08065200.inc"); }

NAKED void FUN_0806521c(Player* p) { INCFUNC("asm/func/FUN_0806521c.inc"); }

void FUN_08065240(Player* p) {
  if (VM_SeekToKeyword('R') != 0) {
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

NAKED void FUN_08066df8(Player* p) { INCFUNC("asm/func/FUN_08066df8.inc"); }

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

// --------------------------------------------

void FUN_08066f7c(Player* p);
void FUN_080672b0(Player* p);
void MagicDash_0806734c(Player* p);
void FUN_080674dc(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
void FUN_08067f58(Player* p);
void FUN_08067f88(Player* p);
void FUN_08067ffc(Player* p);
void FUN_080682dc(Player* p);
void FUN_0806830c(Player* p);
void FUN_08068624(Player* p);
void MagicRisingSun_08068944(Player* p);
void MagicTransform_0806b92c(Player* p);
void MagicChangeWolf_0806eb40(Player* p);
void MagicChangeBat_0806bc74(Player* p);
void MagicChangeMouse_0806bf18(Player* p);
void MagicSleeping_0806c124(Player* p);
void MagicFreeze_08069710(Player* p);
void MagicHealing_08069928(Player* p);
void MagicDynamite_08069b18(Player* p);
void FUN_08069c8c(Player* p);
void FUN_0806961c(Player* p);
void FUN_08069648(Player* p);
void FUN_080695ec(Player* p);
void FUN_08069218(Player* p);
void FUN_0806a050(Player* p);
void FUN_08069d70(Player* p);
void FUN_08069f60(Player* p);
void FUN_0806a084(Player* p);
void FUN_0806a32c(Player* p);
void FUN_0806a628(Player* p);
void FUN_0806a88c(Player* p);
void FUN_0806abd4(Player* p);
void FUN_0806adc8(Player* p);
void FUN_0806af70(Player* p);
void FUN_0806f1ec(Player* p);
void FUN_0806b06c(Player* p);
void FUN_0806b758(Player* p);
void FUN_0806b374(Player* p);
void FUN_08072014(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
void Sabata_BlackSun(Player* p);
void FUN_0806c2dc(Player* p);
void FUN_0806c400(Player* p);
void FUN_0806c6d4(Player* p);
void FUN_0806c868(Player* p);
void FUN_0806c9bc(Player* p);
void FUN_0806cbe8(Player* p);

const PlayerFunc PTR_ARRAY_085abcac[33] = {
    FUN_08066f7c, FUN_080672b0, MagicDash_0806734c, FUN_080695ec, FUN_08067510, FUN_08067de8, FUN_08069218, FUN_08067ffc, FUN_08068624, MagicRisingSun_08068944, MagicTransform_0806b92c, MagicChangeWolf_0806eb40, MagicChangeBat_0806bc74, MagicChangeMouse_0806bf18, MagicSleeping_0806c124, MagicFreeze_08069710, MagicHealing_08069928, MagicDynamite_08069b18, FUN_08069c8c, FUN_0806961c, FUN_08069648, FUN_0806a050, FUN_08069d70, FUN_08069f60, FUN_0806a084, FUN_0806a32c, FUN_0806a628, FUN_0806a88c, FUN_0806abd4, FUN_0806adc8, FUN_0806af70, FUN_0806f1ec, FUN_0806b06c,
};  // 0x085ABCAC

const PlayerFunc PTR_ARRAY_085abd30[32] = {
    FUN_08066f7c, FUN_080672b0, FUN_0806b374, FUN_08072014, FUN_08067510, FUN_08067de8, FUN_08069218, FUN_0806830c, FUN_08068624, Sabata_BlackSun, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, FUN_0806961c, FUN_08069648, FUN_0806a050, FUN_08069d70, FUN_08069f60, FUN_0806a084, FUN_0806a32c, FUN_0806a628, FUN_0806a88c, FUN_0806abd4, FUN_0806adc8, FUN_0806af70, FUN_0806b758,
};  // 0x085ABD30

const PlayerFunc PTR_ARRAY_085abdb0[27] = {
    FUN_0806c2dc, FUN_0806c400, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, FUN_0806cbe8, NULL, NULL, NULL, NULL, NULL, NULL, FUN_0806c868, FUN_0806c6d4, NULL, NULL, NULL, FUN_0806c9bc, NULL, NULL,
};  // 0x085ABDB0

// --------------------------------------------

void FUN_0806ceb0(Player* p);
void FUN_0806d014(Player* p);
void FUN_0806d22c(Player* p);
void FUN_0806dd7c(Player* p);
void FUN_0806d420(Player* p);
void FUN_0806d5b0(Player* p);
void FUN_0806d74c(Player* p);
void FUN_0806da18(Player* p);

const PlayerFunc PTR_ARRAY_085abe1c[27] = {
    FUN_0806ceb0, FUN_0806d014, NULL, NULL, FUN_0806d22c, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, FUN_0806dd7c, NULL, NULL, NULL, NULL, NULL, FUN_0806d420, FUN_0806d5b0, NULL, NULL, FUN_0806d74c, FUN_0806da18, NULL, NULL,
};  // 0x085ABE1C

// --------------------------------------------

void FUN_0806df84(Player* p);
void FUN_0806e15c(Player* p);
void FUN_0806e404(Player* p);
void FUN_0806e4b4(Player* p);
void FUN_0806e7dc(Player* p);
void FUN_0806e674(Player* p);

const PlayerFunc PTR_ARRAY_085abe88[21] = {
    FUN_0806df84, FUN_0806e15c, NULL, FUN_0806e404, FUN_0806e4b4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, FUN_0806e7dc, NULL, NULL, NULL, NULL, NULL, FUN_0806e674,
};  // 0x085ABE88

// --------------------------------------------

void FUN_08066f7c(Player* p);
void FUN_080672b0(Player* p);
void FUN_0806f284(Player* p);
void FUN_080695ec(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
void FUN_08069218(Player* p);
void FUN_08067ffc(Player* p);
void FUN_08068624(Player* p);
void MagicRisingSun_08068944(Player* p);
void MagicTransform_0806b92c(Player* p);
void MagicChangeWolf_0806eb40(Player* p);
void MagicChangeBat_0806bc74(Player* p);
void MagicChangeMouse_0806bf18(Player* p);
void MagicSleeping_0806c124(Player* p);
void MagicFreeze_08069710(Player* p);
void MagicHealing_0806f3a0(Player* p);
void FUN_0806f5d8(Player* p);
void FUN_08069c8c(Player* p);
void FUN_0806961c(Player* p);
void FUN_08069648(Player* p);
void FUN_0806a050(Player* p);
void FUN_08069d70(Player* p);
void FUN_08069f60(Player* p);
void FUN_0806a084(Player* p);
void FUN_0806a32c(Player* p);
void FUN_0806a628(Player* p);
void FUN_0806a88c(Player* p);

const PlayerFunc PTR_ARRAY_085abedc[28] = {
    FUN_08066f7c, FUN_080672b0, FUN_0806f284, FUN_080695ec, FUN_08067510, FUN_08067de8, FUN_08069218, FUN_08067ffc, FUN_08068624, MagicRisingSun_08068944, MagicTransform_0806b92c, MagicChangeWolf_0806eb40, MagicChangeBat_0806bc74, MagicChangeMouse_0806bf18, MagicSleeping_0806c124, MagicFreeze_08069710, MagicHealing_0806f3a0, FUN_0806f5d8, FUN_08069c8c, FUN_0806961c, FUN_08069648, FUN_0806a050, FUN_08069d70, FUN_08069f60, FUN_0806a084, FUN_0806a32c, FUN_0806a628, FUN_0806a88c,
};  // 0x085ABEDC

const u16 u16_ARRAY_085abf4c[3] = {1800, 1800, 900};  // 0x085ABF4C

// --------------------------------------------

void FUN_08081f80(Player* p);
void FUN_08081fb4(Player* p);
void FUN_08082bdc(Player* p);
void FUN_080832b8(Player* p);
void FUN_08082154(Player* p);
void FUN_0808301c(Player* p);
void FUN_08082dac(Player* p);
void FUN_08082970(Player* p);
void FUN_08082a94(Player* p);
void FUN_080835d8(Player* p);
void FUN_08082464(Player* p);
void FUN_08082498(Player* p);
void FUN_08082670(Player* p);

const PlayerFunc PTR_ARRAY_085abf54[29] = {
    FUN_08081f80, FUN_08081fb4, FUN_08082bdc, FUN_080832b8, NULL, NULL, NULL, FUN_08082154, FUN_0808301c, FUN_08082dac, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, FUN_08082970, FUN_08082a94, FUN_080835d8, FUN_08082464, NULL, NULL, FUN_08082498, FUN_08082670, NULL, NULL, NULL,
};  // 0x085ABF54
