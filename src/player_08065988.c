#include "armor.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "vm.h"
#include "weapon.h"

// player.c とファイルを分けてるのは、ファイルサイズが大きくなりすぎてコードを把握しにくいからで、解析が進んだら整理する予定

void FUN_08065164(Player* p);
extern const u16 u16_ARRAY_085abf4c[3];
extern u16 u16_ARRAY_03002ba0[3];
extern u16 u16_03002b78;
extern u16 u16_03002b80;
extern u16 u16_03002bd0;
void FUN_080612d8(Player* p);
bool32 FUN_08060a24(Player* p, u32 animID, s32 param_3);
void FUN_080609dc(Player* p);
s32 FUN_08086294(Vec3* pos, u32 a, u32 b);
void Player_StopEneChargeSound(Player* p);
magic32_t Player_CheckMagicEnchant(Player* p);
void FUN_08060b84(Player* p, u8 a, u8 b);
void FUN_08072724(Player* p);
void FUN_0823bca8(s32 n);
void FUN_0807e854(Player* p);
void FUN_0807d118(Player* p);
void FUN_08063220(Player* p);
void FUN_08063574(Player* p, s32 badcondID, s32 frames);
void FUN_08063634(Player* p, s32 n);
void FUN_080ec79c(u8 kind, void* payload);
void FUN_08060c40(Player* p, u32 val);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void Player_Init_Helper_08063b6c(Player* p);
void FUN_0807ddbc(Player* p);

void FUN_08064a64(Player* p, const ArmorData* a);

void FUN_08065200(Player* p) {
  if (VM_SeekToKeyword('i')) {
    p->unk_18 = VM_GetValue();
  } else {
    p->unk_18 = 0;
  }
}

void FUN_0806521c(Player* p) {
  s32 i;

  for (i = 0; i < 10; i++) {
    p->unk_290[i] |= 0xFFFF;
  }
}

void FUN_08065240(Player* p) {
  if (VM_SeekToKeyword('R')) {
    p->scriptID_9c4 = VM_GetValue();
  } else {
    p->scriptID_9c4 = 0;
  }
}

NAKED s32 Player_Init_Helper_08065270(Player* p) { INCFUNC("asm/func/Player_Init_Helper_08065270.inc"); }

NAKED void FUN_0806540c(Player* p) { INCFUNC("asm/func/FUN_0806540c.inc"); }
NAKED void FUN_08065514(Player* p) { INCFUNC("asm/func/FUN_08065514.inc"); }

NAKED bool32 FUN_08065744(Player* p, u32 n) { INCFUNC("asm/func/FUN_08065744.inc"); }

void Player_InitWeapon(Player* p) {
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

void FUN_08066794(Player* p) {
  FUN_080612d8(p);
  p->unk_376++;
}

NAKED void FUN_080667b0(Player* p, s32 sungauge) { INCFUNC("asm/func/FUN_080667b0.inc"); }

NAKED bool32 FUN_0806680c(Player* p) { INCFUNC("asm/func/FUN_0806680c.inc"); }

NAKED void FUN_0806687c(Player* p) { INCFUNC("asm/func/FUN_0806687c.inc"); }

NAKED void FUN_0806692c(Player* p) { INCFUNC("asm/func/FUN_0806692c.inc"); }

NAKED void FUN_08066a04(Player* p) { INCFUNC("asm/func/FUN_08066a04.inc"); }

NAKED void FUN_08066abc(Player* p) { INCFUNC("asm/func/FUN_08066abc.inc"); }

NAKED void FUN_08066c64(Player* p) { INCFUNC("asm/func/FUN_08066c64.inc"); }

void FUN_08066d10(Player* p) {
  FUN_0823bca8(8);
  p->unk_3ce = 0;
}

// 残差1命令: 原典は TRUE を返す経路を全部まとめて後ろへ飛ばすが、こちらは途中で合流する
NON_MATCH bool32 FUN_08066d2c(Player* p, s32 val) {
#ifdef NONMATCHING_C
  if (p->kind <= 1 || p->kind == 5) {
    if (val == 0 || val == 3 || val == 6) {
      return TRUE;
    }
    if (val == 4 && p->unk_3bc != 0) {
      return TRUE;
    }
  } else if (p->kind == 4) {
    if (val == 0) {
      return TRUE;
    }
  } else {
    if (val == 0 || val == 4) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08066d2c.inc");
#endif
}

NAKED void FUN_08066d7c(Player* p, s32 val) { INCFUNC("asm/func/FUN_08066d7c.inc"); }

NAKED void FUN_08066df8(Player* p) { INCFUNC("asm/func/FUN_08066df8.inc"); }

void FUN_08066e84(void) {
  u16 payload = 6;

  FUN_080ec79c(0x11, &payload);
}

NAKED void FUN_08066e9c(Player* p, Vec3* pos1, s16 param_3, u8 param_4, Vec3* pos2, s32 param_6, u16 id) { INCFUNC("asm/func/FUN_08066e9c.inc"); }

NAKED u32 FUN_08066ee4(s32 kind, s32 idx) { INCFUNC("asm/func/FUN_08066ee4.inc"); }

NAKED u32 FUN_08066f18(Player* p) { INCFUNC("asm/func/FUN_08066f18.inc"); }

void FUN_08066f7c(Player* p) {
  if (p->unk_37c != 0) {
    FUN_08060b84(p, 0, 0);
    p->sprite_2e4.active = FUN_08066f18(p);
    FUN_080609dc(p);
  }
  p->unk_20 &= ~1;
  FUN_08060a24(p, FUN_08066ee4(p->kind, 0), 0x40);
}

NAKED s32 FUN_08066fd4(Player* p) { INCFUNC("asm/func/FUN_08066fd4.inc"); }

NAKED u32 FUN_08067068(Player* p) { INCFUNC("asm/func/FUN_08067068.inc"); }

s32 FUN_080670d4(s32 val) {
  if (val == 12) {
    return 64;
  }
  if (val <= 11) {
    return (12 - val) * 8 + 64;
  } else {
    return 64 - (val - 12) * 4;
  }
}

NAKED void FUN_080670fc(Player* p, u32 val) { INCFUNC("asm/func/FUN_080670fc.inc"); }

NAKED void FUN_080672b0(Player* p) { INCFUNC("asm/func/FUN_080672b0.inc"); }

NAKED void MagicDash_0806734c(Player* p) { INCFUNC("asm/func/MagicDash_0806734c.inc"); }

NAKED void FUN_080674dc(Player* p) { INCFUNC("asm/func/FUN_080674dc.inc"); }

NAKED void FUN_08067510(Player* p) { INCFUNC("asm/func/FUN_08067510.inc"); }

NAKED void FUN_08067de8(Player* p) { INCFUNC("asm/func/FUN_08067de8.inc"); }

bool32 FUN_08067f58(Player* p) {
  if (Player_TestFlag20(p, 0x10) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_08067f88(Player* p) { INCFUNC("asm/func/FUN_08067f88.inc"); }

NAKED void FUN_08067ffc(Player* p) { INCFUNC("asm/func/FUN_08067ffc.inc"); }

bool32 FUN_080682dc(Player* p) {
  if (!Player_TestFlag20(p, 0x10) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_0806830c(Player* p) { INCFUNC("asm/func/FUN_0806830c.inc"); }

NAKED void FUN_08068624(Player* p) { INCFUNC("asm/func/FUN_08068624.inc"); }

NAKED void MagicRisingSun_08068944(Player* p) { INCFUNC("asm/func/MagicRisingSun_08068944.inc"); }

NAKED s32 FUN_08068c6c(Player* p) { INCFUNC("asm/func/FUN_08068c6c.inc"); }

NAKED bool32 FUN_08068d18(Player* p, void* param_2) { INCFUNC("asm/func/FUN_08068d18.inc"); }

NAKED void FUN_08068e94(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08068e94.inc"); }

NAKED void FUN_08069218(Player* p) { INCFUNC("asm/func/FUN_08069218.inc"); }

void FUN_080695ec(Player* p) {
  if (p->unk_37c != 3) {
    FUN_08060b84(p, 3, 0);
  }
  p->attackCB(p);
}

void FUN_0806961c(Player* p) {
  p->unk_20 &= ~1;
  if (p->unk_4c4.unk_3 == 0) {
    FUN_08060b84(p, 0, 0);
  }
}

NAKED void FUN_08069648(Player* p) { INCFUNC("asm/func/FUN_08069648.inc"); }

NAKED void MagicFreeze_08069710(Player* p) { INCFUNC("asm/func/MagicFreeze_08069710.inc"); }

NAKED void MagicHealing_08069928(Player* p) { INCFUNC("asm/func/MagicHealing_08069928.inc"); }

NAKED void MagicDynamite_08069b18(Player* p) { INCFUNC("asm/func/MagicDynamite_08069b18.inc"); }

NAKED void FUN_08069c8c(Player* p) { INCFUNC("asm/func/FUN_08069c8c.inc"); }

NAKED void FUN_08069d70(Player* p) { INCFUNC("asm/func/FUN_08069d70.inc"); }

NAKED void FUN_08069f60(Player* p) { INCFUNC("asm/func/FUN_08069f60.inc"); }

void FUN_0806a050(Player* p) {
  if (p->unk_3fe != 0) {
    FUN_08060c40(p, 0x1C);
  } else {
    FUN_08060c40(p, 0x1D);
  }
  Player_SetFlag20(p, 0x1100);
}

NAKED void FUN_0806a084(Player* p) { INCFUNC("asm/func/FUN_0806a084.inc"); }

NAKED void FUN_0806a32c(Player* p) { INCFUNC("asm/func/FUN_0806a32c.inc"); }

NAKED void FUN_0806a628(Player* p) { INCFUNC("asm/func/FUN_0806a628.inc"); }

NAKED void FUN_0806a88c(Player* p) { INCFUNC("asm/func/FUN_0806a88c.inc"); }

NAKED void FUN_0806abd4(Player* p) { INCFUNC("asm/func/FUN_0806abd4.inc"); }

NAKED void FUN_0806adc8(Player* p) { INCFUNC("asm/func/FUN_0806adc8.inc"); }

NAKED void FUN_0806af70(Player* p) { INCFUNC("asm/func/FUN_0806af70.inc"); }

NAKED void FUN_0806b06c(Player* p) { INCFUNC("asm/func/FUN_0806b06c.inc"); }

NAKED void FUN_0806b374(Player* p) { INCFUNC("asm/func/FUN_0806b374.inc"); }

NAKED void Sabata_BlackSun(Player* p) { INCFUNC("asm/func/Sabata_BlackSun.inc"); }

NAKED void FUN_0806b758(Player* p) { INCFUNC("asm/func/FUN_0806b758.inc"); }

NAKED void MagicTransform_0806b92c(Player* p) { INCFUNC("asm/func/MagicTransform_0806b92c.inc"); }

NAKED void MagicChangeBat_0806bc74(Player* p) { INCFUNC("asm/func/MagicChangeBat_0806bc74.inc"); }

NAKED void MagicChangeMouse_0806bf18(Player* p) { INCFUNC("asm/func/MagicChangeMouse_0806bf18.inc"); }

NAKED void MagicSleeping_0806c124(Player* p) { INCFUNC("asm/func/MagicSleeping_0806c124.inc"); }

NAKED void FUN_0806c2dc(Player* p) { INCFUNC("asm/func/FUN_0806c2dc.inc"); }

NAKED void FUN_0806c400(Player* p) { INCFUNC("asm/func/FUN_0806c400.inc"); }

NAKED void FUN_0806c6d4(Player* p) { INCFUNC("asm/func/FUN_0806c6d4.inc"); }

NAKED void FUN_0806c868(Player* p) { INCFUNC("asm/func/FUN_0806c868.inc"); }

NAKED void FUN_0806c9bc(Player* p) { INCFUNC("asm/func/FUN_0806c9bc.inc"); }

NAKED void FUN_0806cbe8(Player* p) { INCFUNC("asm/func/FUN_0806cbe8.inc"); }

NAKED void FUN_0806ceb0(Player* p) { INCFUNC("asm/func/FUN_0806ceb0.inc"); }

s32 FUN_0806cfd4(Player* p) {
  s32 n = 12;

  if (p->unk_4c4.kind == 2 && p->unk_4c4.unk_3 != 0) {
    n = 8;
  }
  if (p->unk_402 != 0) {
    n -= p->unk_402;
  }
  if (n <= 1) {
    return 2;
  } else {
    return n;
  }
}

NAKED void FUN_0806d014(Player* p) { INCFUNC("asm/func/FUN_0806d014.inc"); }

NAKED void FUN_0806d22c(Player* p) { INCFUNC("asm/func/FUN_0806d22c.inc"); }

NAKED void FUN_0806d420(Player* p) { INCFUNC("asm/func/FUN_0806d420.inc"); }

NAKED void FUN_0806d5b0(Player* p) { INCFUNC("asm/func/FUN_0806d5b0.inc"); }

NAKED void FUN_0806d74c(Player* p) { INCFUNC("asm/func/FUN_0806d74c.inc"); }

NAKED void FUN_0806da18(Player* p) { INCFUNC("asm/func/FUN_0806da18.inc"); }

NAKED void FUN_0806dd7c(Player* p) { INCFUNC("asm/func/FUN_0806dd7c.inc"); }

NAKED void FUN_0806df84(Player* p) { INCFUNC("asm/func/FUN_0806df84.inc"); }

NAKED void FUN_0806e15c(Player* p) { INCFUNC("asm/func/FUN_0806e15c.inc"); }

NAKED void FUN_0806e404(Player* p) { INCFUNC("asm/func/FUN_0806e404.inc"); }

NAKED void FUN_0806e4b4(Player* p) { INCFUNC("asm/func/FUN_0806e4b4.inc"); }

NAKED void FUN_0806e674(Player* p) { INCFUNC("asm/func/FUN_0806e674.inc"); }

NAKED void FUN_0806e7dc(Player* p) { INCFUNC("asm/func/FUN_0806e7dc.inc"); }

NAKED void* FUN_0806ea98(Player* p) { INCFUNC("asm/func/FUN_0806ea98.inc"); }

NAKED void MagicChangeWolf_0806eb40(Player* p) { INCFUNC("asm/func/MagicChangeWolf_0806eb40.inc"); }

NAKED void FUN_0806f1ec(Player* p) { INCFUNC("asm/func/FUN_0806f1ec.inc"); }

NAKED void FUN_0806f284(Player* p) { INCFUNC("asm/func/FUN_0806f284.inc"); }

NAKED void MagicHealing_0806f3a0(Player* p) { INCFUNC("asm/func/MagicHealing_0806f3a0.inc"); }

NAKED void FUN_0806f5d8(Player* p) { INCFUNC("asm/func/FUN_0806f5d8.inc"); }

NAKED u32 FUN_0806f738(Player* p) { INCFUNC("asm/func/FUN_0806f738.inc"); }

void FUN_0806f780(Player* p) {
  p->unk_a8d = Player_CheckMagicEnchant(p);
  if (p->unk_a8d >= 0) {
    p->unk_951 = p->unk_a8d + 1;
  } else {
    p->unk_951 = 0;
  }
}

NAKED void* FUN_0806f7bc(Player* p) { INCFUNC("asm/func/FUN_0806f7bc.inc"); }

NAKED s32 FUN_0806f900(Player* p) { INCFUNC("asm/func/FUN_0806f900.inc"); }

s32 FUN_0806f960(Player* p) {
  s32 result = 0;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->weaponEffectCb2[i] != NULL) {
      result |= p->weaponEffectCb2[i](p);
    }
  }
  return result;
}

NAKED void dark_django_0806f990(HitboxData* a, HitboxData* b, void* _) { INCFUNC("asm/func/dark_django_0806f990.inc"); }

NAKED void FUN_0806fad8(Player* p) { INCFUNC("asm/func/FUN_0806fad8.inc"); }

NAKED void FUN_0806fc20(Player* p, u16* param_2, u32 param_3, s32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_0806fc20.inc"); }

NAKED bool32 FUN_0806fd58(Player* p) { INCFUNC("asm/func/FUN_0806fd58.inc"); }

NAKED void FUN_0806fedc(Player* p) { INCFUNC("asm/func/FUN_0806fedc.inc"); }

NAKED void FUN_080700a4(Player* p) { INCFUNC("asm/func/FUN_080700a4.inc"); }

s32 FUN_08070104(u8* src, u8* base) {
  s32 v = (*src & 0xF) << 8;

  switch (*src >> 4) {
    case 1: {
      v -= base[4];
      break;
    }
    case 2: {
      v -= base[0];
      break;
    }
  }
  return v;
}

NAKED s32 FUN_0807012c(Player* p) { INCFUNC("asm/func/FUN_0807012c.inc"); }

NAKED void FUN_080701e0(Player* p) { INCFUNC("asm/func/FUN_080701e0.inc"); }

NAKED void FUN_080704d8(Player* p, u16* param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080704d8.inc"); }

NAKED s32 FUN_08070604(Player* p) { INCFUNC("asm/func/FUN_08070604.inc"); }

NAKED void FUN_08070844(Player* p) { INCFUNC("asm/func/FUN_08070844.inc"); }

NAKED void FUN_08070adc(Player* p) { INCFUNC("asm/func/FUN_08070adc.inc"); }

NAKED void FUN_08070c2c(Player* p) { INCFUNC("asm/func/FUN_08070c2c.inc"); }

NAKED s32 FUN_08070db4(Player* p) { INCFUNC("asm/func/FUN_08070db4.inc"); }

NAKED void FUN_0807106c(Player* p) { INCFUNC("asm/func/FUN_0807106c.inc"); }

NAKED void FUN_08071218(Player* p) { INCFUNC("asm/func/FUN_08071218.inc"); }

NAKED s32 FUN_080712d4(Player* p) { INCFUNC("asm/func/FUN_080712d4.inc"); }

NAKED void FUN_080713a8(Player* p) { INCFUNC("asm/func/FUN_080713a8.inc"); }

NAKED void gun_080715a0(Player* p) { INCFUNC("asm/func/gun_080715a0.inc"); }

NAKED void FUN_08071b14(Player* p) { INCFUNC("asm/func/FUN_08071b14.inc"); }

NAKED void FUN_08072014(Player* p) { INCFUNC("asm/func/FUN_08072014.inc"); }

void FUN_08072620(Player* p) {
  FUN_08060b84(p, 0, 0);
  p->fn_498 = FUN_08072724;
}

void FUN_08072640(Player* p) { p->unk_4aa = 1; }

void FUN_08072650(Player* p) {
  if (p->scriptID_4b0 != 0) {
    s32 id = p->scriptID_4b0;

    p->scriptID_4b0 = 0;
    VM_ExecByID(id, NULL);
  }
}

void FUN_08072670(Player* p) {
  p->unk_4aa = 2;
  p->unk_4ab = 1;
}

void FUN_0807268c(Player* p) {
  if (p->unk_4ab != 0) {
    EntityMsgBox_EndWait(&p->msgbox, 1);
    p->unk_4ab = 0;
  }
}

void FUN_080726b4(Player* p) {
  if (p->unk_4aa == 1) {
    FUN_08072650(p);
  } else if (p->unk_4aa == 2) {
    FUN_0807268c(p);
  }
}

void FUN_080726e0(Player* p) { FUN_08060c40(p, 5); }

void FUN_080726ec(Player* p) {
  if (p->unk_4ad != 0) {
    p->unk_4ae++;
    if (p->unk_4ae > 7) {
      FUN_080612d8(p);
      p->unk_4ae = 0;
    }
  }
}

NAKED void FUN_08072724(Player* p) { INCFUNC("asm/func/FUN_08072724.inc"); }

NAKED void FUN_080727d4(Player* p) { INCFUNC("asm/func/FUN_080727d4.inc"); }

NAKED void FUN_080728a8(Player* p) { INCFUNC("asm/func/FUN_080728a8.inc"); }

void FUN_080729e0(Player* p) {
  if (FUN_08060a24(p, 531, FRACUNIT_6)) {
    FUN_080609dc(p);
    FUN_08072620(p);
    FUN_080726b4(p);
  }
}

void FUN_08072a0c(Player* p) {
  FUN_08060a24(p, FUN_08066ee4(p->kind, 51), FRACUNIT_6);
  FUN_08060c40(p, 4);
}

NAKED void FUN_08072a38(Player* p) { INCFUNC("asm/func/FUN_08072a38.inc"); }

NAKED void FUN_08072d48(Player* p) { INCFUNC("asm/func/FUN_08072d48.inc"); }

NAKED void FUN_0807304c(Player* p) { INCFUNC("asm/func/FUN_0807304c.inc"); }

NAKED void FUN_0807317c(Player* p) { INCFUNC("asm/func/FUN_0807317c.inc"); }

NAKED void FUN_08073574(Player* p) { INCFUNC("asm/func/FUN_08073574.inc"); }

NAKED void FUN_080736b8(Player* p) { INCFUNC("asm/func/FUN_080736b8.inc"); }

NAKED void FUN_080738b4(Player* p) { INCFUNC("asm/func/FUN_080738b4.inc"); }

NAKED void FUN_080739e0(Player* p) { INCFUNC("asm/func/FUN_080739e0.inc"); }

NAKED void FUN_08073b3c(Player* p) { INCFUNC("asm/func/FUN_08073b3c.inc"); }

NAKED void FUN_08073e18(Player* p) { INCFUNC("asm/func/FUN_08073e18.inc"); }

NAKED void FUN_08073f88(Player* p) { INCFUNC("asm/func/FUN_08073f88.inc"); }

NAKED void FUN_080740b0(Player* p) { INCFUNC("asm/func/FUN_080740b0.inc"); }

NAKED void FUN_08074244(Player* p) { INCFUNC("asm/func/FUN_08074244.inc"); }

NAKED void FUN_08074350(Player* p) { INCFUNC("asm/func/FUN_08074350.inc"); }

NAKED void FUN_080744bc(Player* p) { INCFUNC("asm/func/FUN_080744bc.inc"); }

NAKED void FUN_080746ec(Player* p) { INCFUNC("asm/func/FUN_080746ec.inc"); }

void FUN_08074994(Player* p) {
  p->unk_95e = 0x127;
  p->unk_960 = 24;
}

NAKED void FUN_080749b0(Player* p) { INCFUNC("asm/func/FUN_080749b0.inc"); }

NAKED void FUN_08074a40(Player* p) { INCFUNC("asm/func/FUN_08074a40.inc"); }

NAKED void FUN_08074d90(Player* p) { INCFUNC("asm/func/FUN_08074d90.inc"); }

NAKED void FUN_08074e98(Player* p) { INCFUNC("asm/func/FUN_08074e98.inc"); }

NAKED void FUN_08075134(Player* p) { INCFUNC("asm/func/FUN_08075134.inc"); }

NAKED void FUN_08075980(Player* p) { INCFUNC("asm/func/FUN_08075980.inc"); }

NAKED void FUN_08075b4c(Player* p) { INCFUNC("asm/func/FUN_08075b4c.inc"); }

NAKED void FUN_08075df8(Player* p) { INCFUNC("asm/func/FUN_08075df8.inc"); }

NAKED void FUN_08075f00(Player* p) { INCFUNC("asm/func/FUN_08075f00.inc"); }

NAKED void FUN_080762fc(Player* p) { INCFUNC("asm/func/FUN_080762fc.inc"); }

NAKED void FUN_080765a0(Player* p) { INCFUNC("asm/func/FUN_080765a0.inc"); }

NAKED void FUN_0807688c(Player* p) { INCFUNC("asm/func/FUN_0807688c.inc"); }

NAKED void FUN_08076f2c(Player* p) { INCFUNC("asm/func/FUN_08076f2c.inc"); }

NAKED void FUN_08077100(Player* p) { INCFUNC("asm/func/FUN_08077100.inc"); }

NAKED void FUN_080772ec(Player* p) { INCFUNC("asm/func/FUN_080772ec.inc"); }

NAKED void FUN_080773f0(Player* p) { INCFUNC("asm/func/FUN_080773f0.inc"); }

NAKED void FUN_08077a5c(Player* p) { INCFUNC("asm/func/FUN_08077a5c.inc"); }

NAKED void FUN_08077cbc(Player* p) { INCFUNC("asm/func/FUN_08077cbc.inc"); }

NAKED void FUN_08078060(Player* p) { INCFUNC("asm/func/FUN_08078060.inc"); }

NAKED s32 FUN_0807849c(Player* p) { INCFUNC("asm/func/FUN_0807849c.inc"); }

void FUN_080784fc(Player* p) {
  s32 i;

  for (i = 9; i > 0; i--) {
    p->unk_290[i] = p->unk_290[i - 1];
  }

  p->unk_290[0] = FUN_0807849c(p);
  if ((s16)p->unk_290[0] >= 0) {
    p->unk_290[0] = ((s16)p->unk_290[0] + p->unk_456 + 7) & 7;
  }
}

void FUN_08078548(Player* p) {
  Player_StopEneChargeSound(p);
  if (p->unk_3ce != 0) {
    FUN_08066d10(p);
  }
}

void FUN_0807856c(Player* p) {
  if (p->unk_3ce != 0) {
    FUN_08066d10(p);
  }
}

NAKED void FUN_0807858c(Player* p) { INCFUNC("asm/func/FUN_0807858c.inc"); }

NAKED s32 FUN_0807868c(Player* p) { INCFUNC("asm/func/FUN_0807868c.inc"); }

NAKED s32 FUN_08078844(Player* p) { INCFUNC("asm/func/FUN_08078844.inc"); }

s32 FUN_080788b0(Player* p) { return FUN_08086294(&p->unk_24.pos, p->elevatorID, p->unk_390); }

NAKED s32 FUN_080788d0(Player* p) { INCFUNC("asm/func/FUN_080788d0.inc"); }

NAKED void FUN_08078bc0(Player* p) { INCFUNC("asm/func/FUN_08078bc0.inc"); }

NAKED void FUN_08078d5c(Player* p) { INCFUNC("asm/func/FUN_08078d5c.inc"); }

NAKED void FUN_08079138(Player* p) { INCFUNC("asm/func/FUN_08079138.inc"); }

NAKED s32 FUN_080794e0(Player* p) { INCFUNC("asm/func/FUN_080794e0.inc"); }

NAKED s32 FUN_080795bc(Player* p) { INCFUNC("asm/func/FUN_080795bc.inc"); }

NAKED void FUN_08079644(Player* p) { INCFUNC("asm/func/FUN_08079644.inc"); }

NAKED void FUN_0807972c(Player* p) { INCFUNC("asm/func/FUN_0807972c.inc"); }

NAKED void FUN_080798a4(Player* p) { INCFUNC("asm/func/FUN_080798a4.inc"); }

NAKED s32 FUN_0807998c(Player* p) { INCFUNC("asm/func/FUN_0807998c.inc"); }

NAKED void FUN_08079a64(Player* p) { INCFUNC("asm/func/FUN_08079a64.inc"); }

NAKED void FUN_08079b64(Player* p) { INCFUNC("asm/func/FUN_08079b64.inc"); }

NAKED s32 FUN_08079c50(Player* p) { INCFUNC("asm/func/FUN_08079c50.inc"); }

NAKED void FUN_08079d40(Player* p) { INCFUNC("asm/func/FUN_08079d40.inc"); }

NAKED void FUN_08079e4c(Player* p) { INCFUNC("asm/func/FUN_08079e4c.inc"); }

NAKED void FUN_08079f1c(Player* p) { INCFUNC("asm/func/FUN_08079f1c.inc"); }

NAKED void FUN_0807a270(Player* p) { INCFUNC("asm/func/FUN_0807a270.inc"); }

NAKED void FUN_0807a334(Player* p) { INCFUNC("asm/func/FUN_0807a334.inc"); }

NAKED void FUN_0807a44c(Player* p) { INCFUNC("asm/func/FUN_0807a44c.inc"); }

NAKED s32 FUN_0807a4c4(Player* p) { INCFUNC("asm/func/FUN_0807a4c4.inc"); }

void FUN_0807a524(Player* p) {}

void FUN_0807a528(Player* p, Vec3* pos, u16 param_3) {
  p->unk_37c = 8;
  p->unk_37e = 0;
  p->unk_37d = 0;
  p->unk_3f6 = 0;
  p->unk_3b0 = *pos;
  p->unk_3b8 = param_3;
}

NAKED s32 FUN_0807a570(Player* p) { INCFUNC("asm/func/FUN_0807a570.inc"); }

NAKED s32 FUN_0807a5d8(WeaponData* w, ArmorData* armor) { INCFUNC("asm/func/FUN_0807a5d8.inc"); }

NAKED void* FUN_0807a6cc(WeaponData* w) { INCFUNC("asm/func/FUN_0807a6cc.inc"); }

NAKED s32 FUN_0807a70c(ArmorData* data) { INCFUNC("asm/func/FUN_0807a70c.inc"); }

NAKED void FUN_0807a798(s32 amount) { INCFUNC("asm/func/FUN_0807a798.inc"); }

// 残差はレジスタの割り当てのみ (命令数 30 対 30): 原典は kind を退避するが、こちらは amount を退避する
NON_MATCH void FUN_0807a7f8(s32 kind, s32 amount) {
#ifdef NONMATCHING_C
  if (gStat->playerKind != 5 && kind <= 4) {
    gStat->weaponExp[kind] += amount;
    if (gStat->weaponExp[kind] > 0x26AB) {
      gStat->weaponExp[kind] = 0x26AC;
    }
  }
#else
  INCFUNC("asm/func/FUN_0807a7f8.inc");
#endif
}

NAKED void FUN_0807a840(Player* p) { INCFUNC("asm/func/FUN_0807a840.inc"); }

// 武器の経験値をそのまま返す
s32 FUN_0807a8ac(s32 kind) { return *(gStat->weaponExp + kind); }

// 武器の経験値をレベルに直す, 100 たまると1レベル
s32 GetWeaponSkillLevel(s32 kind) { return Div(*(gStat->weaponExp + kind), 100); }

void FUN_0807a8e0(Player* p) { *(gStat->unk_2c8 + p->isSabata) = 0; }

void FUN_0807a904(Player* p, u32 flag) {
  if (flag == 0) {
    p->unk_402++;
  }
}

// 残差2命令: 原典は gStat->playerPos への3つの代入ごとに gStat を読み直すが、こちらは1回に畳まれる
NON_MATCH void FUN_0807a91c(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  p->unk_24.pos = *pos;
  p->unk_104 = *pos;
  p->sprite_88.pos = *pos;
  gStat->playerPos.x = pos->x;
  gStat->playerPos.y = pos->y;
  gStat->playerPos.z = pos->z;
#else
  INCFUNC("asm/func/FUN_0807a91c.inc");
#endif
}

bool32 FUN_0807a954(Player* p, u32 mask) {
  if (p->unk_390 & mask) {
    return TRUE;
  }
  return FALSE;
}

u32 Player_GetElevatorID(Player* p) { return p->elevatorID; }

void FUN_0807a97c(Player* p, u32 flags, u32 value) {
  p->unk_390 |= flags;
  p->elevatorID = value;
}

void FUN_0807a99c(Player* p, u32 flags) {
  p->unk_390 &= ~flags;
  p->elevatorID = 0;
}

void FUN_0807a9b8(Player* p, void* val) {
  p->ptr_398 = val;
  p->unk_394 = 1;
}

NAKED s32 FUN_0807a9d0(Player* p) { INCFUNC("asm/func/FUN_0807a9d0.inc"); }

void FUN_0807aa00(Player* p, s32 amount) {
  if (p->unk_1c == 1) {
    p->hp += amount;
    if (p->hp >= p->maxHP) {
      p->hp = p->maxHP;
    }
  }
}

void FUN_0807aa30(Player* p, s32 amount) {
  if (p->unk_1c == 1) {
    p->ene += amount;
    if (p->ene >= p->maxEne) {
      p->ene = p->maxEne;
    }
  }
}

// ENE を減らす, 0 未満にはならない
void Player_ReduceENE_0807aa60(Player* player, s32 amount) {
  if (player->unk_1c == 1) {
    u16* ene = &player->ene;

    if (*ene < amount) {
      *ene = 0;
    } else {
      *ene -= amount;
    }
  }
}

// 月光虫取得時に呼ばれる(HP回復)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplyMoonbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
    FUN_0807aa00(p, amount * 2);
  } else {
    FUN_0807aa00(p, amount);
  }
}

// 太陽虫取得時に呼ばれる(Ene回復)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplySolarbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
    FUN_0807aa30(p, amount * 2);
  } else {
    FUN_0807aa30(p, amount);
  }
}

// 暗黒虫取得時に呼ばれる(Eneが減る)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplyDarkbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
    Player_ReduceENE_0807aa60(p, amount * 2);
  } else {
    Player_ReduceENE_0807aa60(p, amount);
  }
}

void FUN_0807ab14(Player* p) {
  Player_SetFlag20(p, 0x1000);
  p->unk_380[0] = 0;
  p->sprite_2e4.unk_2 = 0;
  FUN_08063220(p);
  p->unk_16c.flags |= HBFLAG_UNK_2;
  p->unk_16c.unk_40 = 0;
  p->unk_16c.unk_44 = 0;
  FUN_08060b84(p, 0x15, 0);
}

NAKED s32 FUN_0807ab64(Player* param_1, PlayerFunc** param_2, unknown* param_3, s32 param_4, u8 param_5, s32 param_6, s32 param_7, s32 param_8, u32 param_9) { INCFUNC("asm/func/FUN_0807ab64.inc"); }

NAKED u32 FUN_0807ac74(Player* p, unknown* param_2, u16 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_0807ac74.inc"); }

NAKED s32 FUN_0807ad60(Player* p) { INCFUNC("asm/func/FUN_0807ad60.inc"); }

NAKED void FUN_0807adc0(Player* p) { INCFUNC("asm/func/FUN_0807adc0.inc"); }

NAKED void FUN_0807ae6c(Player* p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0807ae6c.inc"); }

// '.i' から gPlayerPtr の idx を取得する, なかったら 0 (1P) を返すので、 実質的な '.i=0'
u32 VM_GetPlayerIdx(void) { return VM_SeekToKeyword('i') ? VM_GetValue() : 0; }

s32 FUN_0807b000(Vec3* pos) {
  if (VM_SeekToKeyword('p')) {
    pos->x = VM_GetValue();
    pos->y = VM_GetValue();
    pos->z = VM_GetValue();
    return 1;
  }

  return 0;
}

NAKED void FUN_0807b02c(Player* p) { INCFUNC("asm/func/FUN_0807b02c.inc"); }

NAKED s32 FUN_0807b0c0(Player* p) { INCFUNC("asm/func/FUN_0807b0c0.inc"); }

bool32 FUN_0807b118(void) {
  if (gPlayerPtr[0] == NULL || gPlayerPtr[0]->unk_1c != 4) {
    return FALSE;
  }
  return TRUE;
}

s32 FUN_0807b138(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] == NULL) {
    return 0;
  }
  return FUN_0807a9d0(gPlayerPtr[i]);
}

void FUN_0807b15c(void) {
  if (VM_SeekToKeyword('e')) {
    FUN_0807a798(VM_GetValue());
  }
}

void FUN_0807b174(void) {
  if (VM_SeekToKeyword('t')) {
    s32 kind = VM_GetValue();

    if (VM_SeekToKeyword('p')) {
      FUN_0807a7f8(kind, VM_GetValue());
    }
  }
}

// 残差1命令: 原典は gPlayerPtr[i] を読んだレジスタから写しを作る, FUN_0807b2dc / FUN_0807b66c と同じ類
NON_MATCH s32 FUN_0807b1a4(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p == NULL || !VM_SeekToKeyword('f')) {
    return 0;
  }
  return p->flag378 & VM_GetValue();
#else
  INCFUNC("asm/func/FUN_0807b1a4.inc");
#endif
}

NAKED void item_0807b1e4(Player* p) { INCFUNC("asm/func/item_0807b1e4.inc"); }

// 残差1命令: 原典は gPlayerPtr[i] を読んだレジスタから別のレジスタへ写してから使う
// ローカルの有無・宣言と代入の分離・gPlayerPtr[i] の直接参照のどれでも写しが出ない
NON_MATCH s32 FUN_0807b2dc(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL && gPlayerPtr[i]->unk_446 != 0) {
    return gPlayerPtr[i]->unk_442;
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_0807b2dc.inc");
#endif
}

void FUN_0807b314(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    p->unk_442 = 0;
    p->unk_446 = 0;
    p->unk_444 = 0;
  }
}

NAKED void FUN_0807b34c(Player* p) { INCFUNC("asm/func/FUN_0807b34c.inc"); }

void FUN_0807b3c0(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_08063220(gPlayerPtr[i]);
  }
}

// 残差は分岐の配置のみ (命令数 28 対 28): 原典は return 0 のブロックが先に出て、成功側が後ろに置かれる
NON_MATCH s32 FUN_0807b3e0(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToKeyword('s')) {
    s32 n = VM_GetValue();

    if (n <= 2 && p->unk_43c[n] != 0) {
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0807b3e0.inc");
#endif
}

void FUN_0807b428(void) {
  if (VM_SeekToKeyword('s')) {
    s32 n = VM_GetValue();

    if (n <= 2) {
      s32 val = VM_SeekToKeyword('t') ? VM_GetValue() : u16_ARRAY_085abf4c[n];

      if (gPlayerPtr[0] != NULL) {
        FUN_08063574(gPlayerPtr[0], n, val);
      } else {
        u16_ARRAY_03002ba0[n] = val;
      }
    }
  }
}

void FUN_0807b484(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToKeyword('s')) {
    FUN_08063634(p, VM_GetValue());
  }
}

void FUN_0807b4b8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 j;

    for (j = 0; j < 3; j++) {
      FUN_08063634(p, j);
    }
  }
}

// 残差1命令: 2つ目の判定の分岐極性が逆 (原典は bgt で 1 を返す側へ飛び、0 を返す側が直列)
// if/return, else 明示, && の直接 return をいずれも試したが極性が変わらない
NON_MATCH s32 FUN_0807b4e4(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && *(gStat->unk_2c8 + p->isSabata) > 0) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0807b4e4.inc");
#endif
}

void FUN_0807b528(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    *(gStat->unk_2c8 + p->isSabata) = 0;
  }
}

void FUN_0807b564(void) {
  u16_03002bd0 = 0;
  u16_03002b80 = 0;
  u16_03002b78 = 0;
}

void FUN_0807b580(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_43a = 1;
  }
}

void FUN_0807b5a8(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_3ba = 1;
  }
}

void FUN_0807b5d0(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_285 = 1;
  }
}

void FUN_0807b5f8(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_285 = 0;
  }
}

// スクリプトが指すプレイヤーの武器種を返す
s32 FUN_0807b620(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] == NULL) {
    return 0;
  }
  return gPlayerPtr[i]->weaponKind_a75;
}

void FUN_0807b64c(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_0807e854(gPlayerPtr[i]);
  }
}

// 残差1命令: 原典は gPlayerPtr[i] を読んだあと別レジスタへ写し、後半の呼び出しはそちらを使う
// FUN_0807b2dc と同じ「読んだポインタの写し」が出ない類, ローカル1個・gPlayerPtr[i] 直接・両者の混在を試済
NON_MATCH void FUN_0807b66c(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807e854(p);
    if (VM_SeekToKeyword('d')) {
      p->sprite_2e4.active = VM_GetValue();
    }
    FUN_080609dc(p);
    FUN_08060b84(p, 0x1F, 0);
  }
#else
  INCFUNC("asm/func/FUN_0807b66c.inc");
#endif
}

NAKED s32 FUN_0807b6b8(Player* p) { INCFUNC("asm/func/FUN_0807b6b8.inc"); }

NAKED void FUN_0807b7a4(Player* p) { INCFUNC("asm/func/FUN_0807b7a4.inc"); }

void FUN_0807b890(Player* p, s32 val) {
  p->unk_96c = 1;
  p->unk_95e = val;
}

void FUN_0807b8a8(Player* p, s32 val) {
  p->unk_96c = 2;
  p->unk_95e = val;
}

void FUN_0807b8c0(Player* p) { p->unk_96c = 0; }

void FUN_0807b8d0(Player* p, Vec3* src) { p->unk_24.pos = *src; }

void FUN_0807b8dc(Player* p) {
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0, 0);
  p->sprite_88.flags |= SPRFLAG_HIDDEN;
  p->fn_498 = FUN_080726e0;
}

NAKED void FUN_0807b910(Player* p, s32 val) { INCFUNC("asm/func/FUN_0807b910.inc"); }

void FUN_0807b9dc(Player* p, s32 param_2, u32 param_3) {
  p->unk_4a9 = param_2;
  p->scriptID_4b0 = param_3;
  p->fn_498 = FUN_080727d4;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0, 0);
}

void FUN_0807ba14(Player* p, s32 param_2) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0, 1);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba50(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0, 2);
  p->fn_498 = FUN_08072724;
}

NAKED void FUN_0807ba94(Player* p, unknown* param_2, u32 param_3, u8 param_4) { INCFUNC("asm/func/FUN_0807ba94.inc"); }

NAKED void FUN_0807bb3c(Player* p) { INCFUNC("asm/func/FUN_0807bb3c.inc"); }

NAKED void FUN_0807bbb0(Player* p) { INCFUNC("asm/func/FUN_0807bbb0.inc"); }

void FUN_0807bc14(Player* p, s32 param_2, u32 param_3) {
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = param_3;
  p->sprite_2e4.active = 0;
  p->sprite_2e4.unk_2 = 0;
  p->sprite_2e4.unk_3 = 0;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc64(Player* p, u32 param_2) {
  if (p->unk_1c == 2 && p->unk_37c == 7 && p->unk_37d != 0) {
    p->scriptID_4b0 = param_2;
    FUN_0807b7a4(p);
    FUN_08060b84(p, 7, 3);
    p->fn_498 = FUN_0807304c;
  }
}

void FUN_0807bcb0(Player* p, s32 param_2, u32 param_3) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0x12, 0);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bcfc(Player* p, s32 param_2) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  PlaySound_082406e0(0xC6);
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0x12, 2);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd44(Player* p, s32 param_2) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0x12, 1);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd84(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 0x12, 3);
  p->fn_498 = FUN_08073574;
}

NAKED void FUN_0807bdc8(Player* p, s32 param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_0807bdc8.inc"); }

NAKED void FUN_0807be58(Player* p, s32 param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_0807be58.inc"); }

NAKED void FUN_0807bee0(Player* p, s32 param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_0807bee0.inc"); }

NAKED void FUN_0807bfa4(Player* p) { INCFUNC("asm/func/FUN_0807bfa4.inc"); }

NAKED void FUN_0807c048(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_0807c048.inc"); }

NAKED void FUN_0807c084(Player* p, s32 param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_0807c084.inc"); }

NAKED void FUN_0807c11c(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_0807c11c.inc"); }

NAKED void FUN_0807c200(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c200.inc"); }

NAKED void FUN_0807c30c(Player* p) { INCFUNC("asm/func/FUN_0807c30c.inc"); }

NAKED void FUN_0807c36c(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c36c.inc"); }

void FUN_0807c458(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 0);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c49c(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 2);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c4e0(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 0);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c524(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 2);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c568(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 0);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5ac(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 2);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5f0(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 0);
  p->fn_498 = FUN_08074350;
}

NAKED void FUN_0807c634(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c634.inc"); }

void FUN_0807c748(Player* p, s32 param_2, s32 param_3, u32 param_4) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  p->scriptID_4b0 = param_4;
  p->unk_4a7 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 0);
  p->fn_498 = FUN_080744bc;
}

void FUN_0807c798(Player* p, s32 scriptID) {
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 3, 5);
  p->fn_498 = FUN_080744bc;
}

NAKED void FUN_0807c7c8(Player* p) { INCFUNC("asm/func/FUN_0807c7c8.inc"); }

void FUN_0807c88c(Player* p, Vec3* pos, u8 param_3, u32 param_4) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = param_4;
  p->unk_4a9 = param_3;
  FUN_0807b7a4(p);
  FUN_08060b84(p, 2, 0);
  p->fn_498 = FUN_080746ec;
}

void FUN_0807c8d4(Player* p, s32 param_2) {
  if (param_2 >= 0) {
    p->sprite_2e4.active = param_2;
  }
  FUN_080609dc(p);
  FUN_08060a24(p, FUN_08066ee4(p->kind, 1), 0x20);
  FUN_0807b7a4(p);
  FUN_08060b84(p, 2, 0);
  p->fn_498 = FUN_08074994;
}

void FUN_0807c928(Player* p, s32 val) {
  FUN_0807b7a4(p);
  p->sprite_2e4.active = 1;
  p->sprite_2e4.unk_2 = 0;
  p->sprite_2e4.unk_3 = 0;
  FUN_08060b84(p, 0x10, 0);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c968(Player* p, s32 val) {
  FUN_0807b7a4(p);
  p->sprite_2e4.active = 1;
  p->sprite_2e4.unk_2 = 0;
  p->sprite_2e4.unk_3 = 0;
  FUN_08060b84(p, 0x10, 2);
  p->fn_498 = FUN_080749b0;
}

NAKED void FUN_0807c9ac(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c9ac.inc"); }

NAKED void FUN_0807ca24(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807ca24.inc"); }

NAKED void FUN_0807ca9c(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807ca9c.inc"); }

NAKED void FUN_0807cb14(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807cb14.inc"); }

NAKED void FUN_0807cb8c(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807cb8c.inc"); }

NAKED void FUN_0807cc14(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_0807cc14.inc"); }

NAKED bool32 FUN_0807cc84(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_0807cc84.inc"); }

NAKED void FUN_0807cd24(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_0807cd24.inc"); }

void FUN_0807ceb8(Player* p) { FUN_08063220(p); }

NAKED void FUN_0807cec4(Player* p) { INCFUNC("asm/func/FUN_0807cec4.inc"); }

void FUN_0807d118(Player* p) {
  if (p->unk_37c != 6) {
    p->unk_37c = 0;
  }
  p->unk_37d = 0;
  p->unk_37e = 0;
  if (p->unk_4a8 != 0) {
    p->unk_4a8 = 0;
  }
  p->unk_1c = 1;
  p->unk_395 = 0;
}

s32 FUN_0807d164(void) {
  if (VM_SeekToKeyword('d')) {
    return VM_GetValue();
  }
  return -1;
}

u32 FUN_0807d180(void) { return VM_SeekToKeyword('e') ? VM_GetValue() : 0; }

void FUN_0807d198(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b8dc(p);
    FUN_08072640(p);
  }
}

void FUN_0807d1c0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToKeyword('p')) {
    FUN_0807b890(p, VM_GetValue() + 0x121);
    FUN_08072640(p);
  }
}

void FUN_0807d200(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToKeyword('p')) {
    FUN_0807b8a8(p, VM_GetValue() + 0x121);
    FUN_08072640(p);
  }
}

void FUN_0807d240(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b8c0(p);
    FUN_08072640(p);
  }
}

void Player_Lock(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b910(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d298(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b9dc(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d2d0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba14(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d300(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba50(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

NAKED void Player_MoveTo(Player* p) { INCFUNC("asm/func/Player_MoveTo.inc"); }

NAKED void FUN_0807d3b8(Player* p) { INCFUNC("asm/func/FUN_0807d3b8.inc"); }

NAKED void FUN_0807d438(Player* p) { INCFUNC("asm/func/FUN_0807d438.inc"); }

NAKED void FUN_0807d4ec(Player* p) { INCFUNC("asm/func/FUN_0807d4ec.inc"); }

void FUN_0807d560(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bc64(p, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d590(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcb0(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d5c8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcfc(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d5f8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd44(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d628(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd84(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d660(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 a = FUN_0807d164();
    u32 b = FUN_0807d180();

    FUN_0807bdc8(p, a, VM_SeekToKeyword('f') ? VM_GetValue() : 0, b);
  }
}

void FUN_0807d6a8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 a = FUN_0807d164();
    u32 b = FUN_0807d180();

    FUN_0807be58(p, a, VM_SeekToKeyword('h') ? VM_GetValue() : 1500, b);
    FUN_08072640(p);
  }
}

void FUN_0807d6f8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('f') ? VM_GetValue() : 30;

    FUN_0807bee0(p, FUN_0807d164(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

NAKED void FUN_0807d744(Player* p) { INCFUNC("asm/func/FUN_0807d744.inc"); }

void FUN_0807d7ac(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c048(p, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d7dc(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('f') ? VM_GetValue() : 50;

    FUN_0807c084(p, FUN_0807d164(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d828(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c11c(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d858(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c200(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d890(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c36c(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d8c8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c458(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d900(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c49c(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d938(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c4e0(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d970(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c524(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9a8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c568(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9e0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5ac(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da18(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5f0(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da50(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('l') ? VM_GetValue() : 32;

    FUN_0807c634(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da94(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    bool32 done = FUN_0807cc84(p, FUN_0807d180());

    FUN_08072640(p);
    if (!done) {
      FUN_08072650(p);
    }
  }
}

void FUN_0807dad0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('r') ? VM_GetValue() : 0;

    FUN_0807c9ac(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db14(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('r') ? VM_GetValue() : 0;

    FUN_0807ca24(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db58(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('r') ? VM_GetValue() : 0;

    FUN_0807ca9c(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db9c(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('r') ? VM_GetValue() : 0;

    FUN_0807cb14(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807dbe0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToKeyword('d') ? VM_GetValue() : 0;

    FUN_0807cb8c(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807dc24(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807cc14(p, VM_SeekToKeyword('r') ? VM_GetValue() : 0);
    FUN_08072640(p);
  }
}

NAKED void FUN_0807dc60(Player* p) { INCFUNC("asm/func/FUN_0807dc60.inc"); }

void Player_Unlock(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_0807d118(gPlayerPtr[i]);
  }
}

NAKED void FUN_0807dcec(Player* p) { INCFUNC("asm/func/FUN_0807dcec.inc"); }

void FUN_0807ddbc(Player* p) { EntityMsgBus_Register(&p->msgbox, p->unk_24.id, 2); }

void FUN_0807ddd4(Player* p) { EntityMsgBus_Unregister(&p->msgbox); }

NAKED void Player_Update_Helper_0807dde4(Player* p) { INCFUNC("asm/func/Player_Update_Helper_0807dde4.inc"); }

NAKED void FUN_0807e278(Player* p) { INCFUNC("asm/func/FUN_0807e278.inc"); }

NAKED void FUN_0807e2cc(Player* p) { INCFUNC("asm/func/FUN_0807e2cc.inc"); }

NAKED void FUN_0807e388(Player* p) { INCFUNC("asm/func/FUN_0807e388.inc"); }

NAKED u32 FUN_0807e3b0(Player* p, HitboxData* a, HitboxData* b) { INCFUNC("asm/func/FUN_0807e3b0.inc"); }

NAKED void FUN_0807e784(HitboxData* a, HitboxData* b, Player* p) { INCFUNC("asm/func/FUN_0807e784.inc"); }

NAKED s32 FUN_0807e7fc(Player* p, u32 param_2, u16 param_3, u8 param_4, u16 param_5, u32 param_6) { INCFUNC("asm/func/FUN_0807e7fc.inc"); }

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
bool32 FUN_08067f58(Player* p);
void FUN_08067f88(Player* p);
void FUN_08067ffc(Player* p);
bool32 FUN_080682dc(Player* p);
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
