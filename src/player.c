#include "player.h"

#include "armor.h"
#include "global.h"
#include "item.h"

const u8 u8_ARRAY_085abab4[4] = {3, 4, 6, 0};  // 0x085abab4

// --------------------------------------------

void FUN_0806fedc(Player* p);
void FUN_08070844(Player* p);
void FUN_0807106c(Player* p);
void FUN_080713a8(Player* p);
void gun_080715a0(Player* p);

// clang-format off
const PlayerFunc gPlayerAttackUpdates[5] = {
    [WK_SWORD]  = FUN_0806fedc,
    [WK_SPEAR]  = FUN_08070844,
    [WK_HAMMER] = FUN_0807106c,
    [WK_OTHERS] = FUN_080713a8,
    [WK_GUN]    = gun_080715a0,
};  // 0x085abab8
// clang-format on

// --------------------------------------------

// clang-format off
const u16 gMagicCosts[MAGIC_NUM] = {
    [MAGIC_SOL] = 5,
    [MAGIC_DARK] = 5,
    [MAGIC_FLAME] = 10,
    [MAGIC_FROST] = 10,
    [MAGIC_CLOUD] = 10,
    [MAGIC_EARTH] = 10,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 100,
    [MAGIC_UNK_8] = 10,
    [MAGIC_UNK_9] = 100,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 0,
    [MAGIC_HEALING] = 0,
    [MAGIC_DYNAMITE] = 0,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 10,
    [MAGIC_RAT] = 10,
    [MAGIC_WOLF] = 10,
};  // 0x085abacc
// clang-format on

// FUN_08064b00 での使い方的にこれも魔法の消費コストっぽいけど、いつ使うかわからん
// clang-format off
const u16 gMagicUnkVal[MAGIC_NUM] = {
    [MAGIC_SOL] = 10,
    [MAGIC_DARK] = 0,
    [MAGIC_FLAME] = 5,
    [MAGIC_FROST] = 5,
    [MAGIC_CLOUD] = 5,
    [MAGIC_EARTH] = 5,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 0,
    [MAGIC_UNK_8] = 0,
    [MAGIC_UNK_9] = 0,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 1,
    [MAGIC_HEALING] = 2,
    [MAGIC_DYNAMITE] = 2,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 0,
    [MAGIC_RAT] = 0,
    [MAGIC_WOLF] = 0,
};  // 0x085abaf0
// clang-format on

// --------------------------------------------

void FUN_08078d5c(Player* p);
void FUN_08078d5c(Player* p);
void FUN_080798a4(Player* p);
void FUN_08079b64(Player* p);
void FUN_08079e4c(Player* p);
void FUN_08079138(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085abb14[6] = {
    [PLAYER_SOLAR_DJANGO] = FUN_08078d5c,
    [PLAYER_DARK_DJANGO]  = FUN_08078d5c,
    [PLAYER_BAT]          = FUN_080798a4,
    [PLAYER_MOUSE]        = FUN_08079b64,
    [PLAYER_SLEEPING]     = FUN_08079e4c,
    [PLAYER_SABATA]       = FUN_08079138,
};  // 0x085abb14
// clang-format on

// --------------------------------------------

const u16 u16_ARRAY_085abb2c[57] = {
    0, 5, 20, 22, 24, 26, 28, 30, 52, 54, 56, 58, 60, 61, 62, 63, 10, 15, 44, 46, 48, 109, 119, 114, 124, 129, 134, 139, 144, 149, 154, 159, 64, 69, 74, 79, 84, 89, 94, 99, 104, 32, 34, 38, 40, 42, 36, 179, 184, 194, 189, 534, 513, 514, 515, 519, 520,
};  // 0x085abb2c

const u16 u16_ARRAY_085abb9e[57] = {
    199, 204, 219, 221, 223, 225, 227, 229, 251, 253, 255, 257, 259, 260, 261, 262, 209, 214, 243, 245, 247, 308, 318, 313, 323, 328, 333, 338, 343, 348, 353, 358, 263, 268, 273, 278, 283, 288, 293, 298, 303, 231, 233, 237, 239, 241, 235, 378, 383, 393, 388, 535, 521, 522, 523, 527, 528,
};  // 0x085abb9e

const u16 u16_ARRAY_085abc10[57] = {
    414, 419, 434, 436, 438, 440, 442, 444, 466, 468, 470, 472, 474, 475, 476, 477, 424, 429, 458, 460, 462, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 478, 483, 488, 0, 0, 0, 446, 448, 452, 454, 456, 450, 493, 498, 508, 503, 533, 0, 0, 0, 0, 0,
};  // 0x085abc10

const u8 u8_ARRAY_085abc82[8] = {4, 2, 2, 1, 1, 2, 8, 0};  // 0x085abc82

const s16 s16_ARRAY_085abc8a[17] = {
    -0x1, 0x0, 0x4, -0x1, 0x6, 0x7, 0x5, -0x1, 0x2, 0x1, 0x3, -0x1, -0x1, -0x1, -0x1, -0x1, 0x0,
};  // 0x085abc8a

INCBIN(".rodata", "data/rodata2.bin");  // ./tmp/bin.sh ./baserom.gba 0x085abcac 0x085abfc8 ./data/rodata2.bin

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

NAKED u32 FUN_08060c98(unknown* r1, unknown* r2) { INCFUNC("asm/func/FUN_08060c98.inc"); }

NAKED void FUN_08060cf8(Player* p, unknown* r1, unknown* r2) { INCFUNC("asm/func/FUN_08060cf8.inc"); }

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

void FUN_08060ec8(Player* p, u32 r1) { p->unk_9bc |= r1; }

u32 FUN_08060ed8(Player* p, u32 r1) { return p->unk_9bc & r1; }

void FUN_08060ee8(Player* p) {
  if (p->scriptID_9c0 != 0) {
    Script_ExecById(p->scriptID_9c0, 0);
  }
}

NAKED void FUN_08060f00(Player* p) { INCFUNC("asm/func/FUN_08060f00.inc"); }

s32 CalcMaxHP(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) + armor->hpBonus;
  } else {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) - armor->hpBonus;
  }
  if (99 < val) {
    val = 99;
  }
  return val * 10;
}

s32 CalcMaxEne(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return 10;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) + armor->eneBonus;
  } else {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) - armor->eneBonus;
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

NAKED void FUN_080613ec(Player* p, unknown* param_2, s32 val) { INCFUNC("asm/func/FUN_080613ec.inc"); }

NAKED void FUN_08061458(Player* p) { INCFUNC("asm/func/FUN_08061458.inc"); }

NAKED void FUN_080614bc(Player* p) { INCFUNC("asm/func/FUN_080614bc.inc"); }

NAKED void FUN_0806161c(Player* p) { INCFUNC("asm/func/FUN_0806161c.inc"); }

// Player.fn_714
NAKED void FUN_08061680(unknown* p) { INCFUNC("asm/func/FUN_08061680.inc"); }

// Player.fn_714
NAKED void FUN_080617bc(unknown* p) { INCFUNC("asm/func/FUN_080617bc.inc"); }

NAKED void FUN_080617dc(u32 idx, s32* result1, s32* result2) { INCFUNC("asm/func/FUN_080617dc.inc"); }

NAKED void FUN_0806181c(Player* p) { INCFUNC("asm/func/FUN_0806181c.inc"); }

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる
NAKED void Player_DarkDjangoSword_0806185c(Player* p, u32 idx, Vec3* pos) { INCFUNC("asm/func/Player_DarkDjangoSword_0806185c.inc"); }

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる
NAKED void Player_DarkDjangoSpear_08061970(Player* p, u32 idx, Vec3* pos, s32 n) { INCFUNC("asm/func/Player_DarkDjangoSpear_08061970.inc"); }

// Player_DarkDjangoSword_0806185c のような関数だが、いつ呼ばれるか不明 (武器の攻撃ではない)
NAKED void FUN_08061a98(Player* p, u32 idx, Vec3* pos) { INCFUNC("asm/func/FUN_08061a98.inc"); }

// 多分、サバタが攻撃する時に呼ばれる
NAKED void FUN_08061b48(Player* p, u32 _, Vec3* pos) { INCFUNC("asm/func/FUN_08061b48.inc"); }

void FUN_08061b98(Player* p) { FUN_0822a4e0(&p->unk_6ac[0]); }

NAKED void Player_Init_Anim_08061bac(Player* p) { INCFUNC("asm/func/Player_Init_Anim_08061bac.inc"); }

NAKED void FUN_08061c68(Player* p) { INCFUNC("asm/func/FUN_08061c68.inc"); }

INCASM("asm/player.inc");

NAKED u32 CheckNamakuraProc(void) { INCFUNC("asm/func/CheckNamakuraProc.inc"); }

NAKED u32 CheckParalyzeProc(void) { INCFUNC("asm/func/CheckParalyzeProc.inc"); }

NAKED void FUN_08064058(Player* p) { INCFUNC("asm/func/FUN_08064058.inc"); }

NAKED void Player_EnableWeaponSpecialEffects(Player* p, WeaponData* w) { INCFUNC("asm/func/Player_EnableWeaponSpecialEffects.inc"); }

NAKED void FUN_080643d4(Player* p) { INCFUNC("asm/func/FUN_080643d4.inc"); }

void FUN_08064658(Player* p, Weapon* w) { p->weapon_a70 = w; }

NAKED void weapon_08064664(Player* p, Weapon* w) { INCFUNC("asm/func/weapon_08064664.inc"); }

NAKED void FUN_08064764(Player* p) { INCFUNC("asm/func/FUN_08064764.inc"); }

NAKED void FUN_0806483c(Player* p, const ArmorData* a) { INCFUNC("asm/func/FUN_0806483c.inc"); }

NAKED void FUN_08064a64(Player* p, const ArmorData* a) { INCFUNC("asm/func/FUN_08064a64.inc"); }

NAKED void CheckHeartJokerEmblem(Player* p) { INCFUNC("asm/func/CheckHeartJokerEmblem.inc"); }

s32 FUN_08064b00(magic32_t id) {
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return gMagicUnkVal[id];
  } else {
    return gMagicCosts[id];
  }
}

NAKED s32 CalcMagicCost(Player* p) { INCFUNC("asm/func/CalcMagicCost.inc"); }

NAKED bool32 Player_CheckMagicCost(Player* p) { INCFUNC("asm/func/Player_CheckMagicCost.inc"); }

NAKED void Player_PayMagicCost(Player* p) { INCFUNC("asm/func/Player_PayMagicCost.inc"); }

NAKED bool32 FUN_08064c48(Player* p, magic32_t id) { INCFUNC("asm/func/FUN_08064c48.inc"); }

NAKED magic32_t Player_CheckMagicEnchant(Player* p) { INCFUNC("asm/func/Player_CheckMagicEnchant.inc"); }

bool32 Player_HasEnoughEne(Player* p, s32 ene) {
  if (p->ene < ene) return FALSE;
  return TRUE;
}

NAKED bool32 FUN_08064d6c(Player* p, s32 val) { INCFUNC("asm/func/FUN_08064d6c.inc"); }

NAKED unknown* FUN_08064db0(Player* p) { INCFUNC("asm/func/FUN_08064db0.inc"); }

NAKED void FUN_08064fd8(Player* p, magic32_t n) { INCFUNC("asm/func/FUN_08064fd8.inc"); }

NAKED s32 FUN_08065110(Player* p) { INCFUNC("asm/func/FUN_08065110.inc"); }

NAKED void FUN_08065164(Player* p) { INCFUNC("asm/func/FUN_08065164.inc"); }
