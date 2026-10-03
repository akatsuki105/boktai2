#include "player.h"

#include "armor.h"
#include "global.h"
#include "input.h"
#include "item.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

extern u16 u16_03002bb0;

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

void FUN_080609dc(Player* p) {
  u8 v = p->facing;

  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = 1;
  } else {
    p->animIDOffset = v;
    p->xflip = 0;
  }
}

NAKED bool32 FUN_08060a24(Player* p, u32 animIdx, s32 animSpeed) { INCFUNC("asm/func/FUN_08060a24.inc"); }

NAKED void Player_SetMoveDelta(Player* p, s32 val) { INCFUNC("asm/func/Player_SetMoveDelta.inc"); }

void Player_SetAction(Player* p, u32 r1, u32 r2) {
  p->action = r1;
  p->state = r2;
  p->stateTimer = 0;
}

NAKED void FUN_08060bac(Player* p) { INCFUNC("asm/func/FUN_08060bac.inc"); }

void FUN_08060c40(Player* p, u32 val) { p->unk_35a |= val; }

u32 FUN_08060c50(Player* p, u32 mask) { return p->unk_35a & mask; }

// エネルギーチャージ音を止める
void Player_StopEneChargeSound(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    sound_08240740(0xD8);
    return;
  }
  sound_08240740(0x239);
  sound_08240740(0x202);
  sound_08240740(0x366);
}

NAKED u32 FUN_08060c98(unknown* r1, unknown* r2) { INCFUNC("asm/func/FUN_08060c98.inc"); }

NAKED void FUN_08060cf8(Player* p, unknown* r1, unknown* r2) { INCFUNC("asm/func/FUN_08060cf8.inc"); }

bool32 FUN_08060e1c(Player* p) {
  u32 span;

  if (*(p->isSabata + gStat->unk_2c8) > 0) return TRUE;
  if (Player_TestFlag378(p, FLAG378_UNK_10)) return TRUE;

  span = Time_GetSpanOfTime();
  if (span >= TIME_UNK4 && span <= TIME_UNK5) return TRUE;
  if (span != TIME_NIGHT) return FALSE;

  return TRUE;
}

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

void FUN_08060e90(Player* p, u32 val) {
  if (p->scriptID_9c4 != 0) {
    ScriptArgs args;
    u32 argv;
    args.argc = 1;
    argv = val;
    args.argv = &argv;
    VM_ExecByID(p->scriptID_9c4, &args);
  }
}

void FUN_08060ec8(Player* p, u32 r1) { p->unk_9bc |= r1; }

u32 FUN_08060ed8(Player* p, u32 r1) { return p->unk_9bc & r1; }

void FUN_08060ee8(Player* p) {
  if (p->scriptID_9c0 != 0) {
    VM_ExecByID(p->scriptID_9c0, NULL);
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

// 0x64C のパーティクルを確保して隠した状態で初期化する
// 命令数は40で一致, 残差は p と &ptcl_64c のレジスタが入れ替わっているだけ (原典は p が r5)
// Tier A/B と C の宣言順・ローカル化は試済
NON_MATCH void FUN_08061458(Player* p) {
#ifdef NONMATCHING_C
  ParticleGroup* group = GetParticleGroup(0x1C1C);
  PlayerParticleGroup1* st = &p->ptcl_64c;

  st->group1 = group;
  FUN_0822d9f0(&st->ptcl, group, 0);
  Particle_SetOffset(&st->ptcl, -4, -4);
  FUN_0822dafc(&st->ptcl, st->group1, 4);
  st->ptcl.flags |= SPRFLAG_HIDDEN;
  st->ptcl.priority = 1;
  st->ptcl.offsetZ = 0x14;
  st->unk_2c = 0;
  st->unk_2d = 0;
#else
  INCFUNC("asm/func/FUN_08061458.inc");
#endif
}

NAKED void FUN_080614bc(Player* p) { INCFUNC("asm/func/FUN_080614bc.inc"); }

// 0x67C のパーティクルを確保して隠した状態で初期化する
// FUN_08061458 と同じ残差 (40/40, p と &ptcl_67c のレジスタが入れ替わっているだけ)
NON_MATCH void FUN_0806161c(Player* p) {
#ifdef NONMATCHING_C
  ParticleGroup* group = GetParticleGroup(0x1C1C);
  PlayerParticleGroup1* st = &p->ptcl_67c;

  st->group1 = group;
  FUN_0822d9f0(&st->ptcl, group, 0);
  Particle_SetOffset(&st->ptcl, -4, -4);
  FUN_0822dafc(&st->ptcl, st->group1, 0x10);
  st->ptcl.flags |= SPRFLAG_HIDDEN;
  st->ptcl.priority = 1;
  st->ptcl.offsetZ = 0x14;
  st->unk_2c = 0;
  st->unk_2d = 0;
#else
  INCFUNC("asm/func/FUN_0806161c.inc");
#endif
}

// 衝撃波のアニメーションを1フレーム進める, 終端まで行くと finished を立てて消す
NAKED void PlayerShockwave_UpdateAnim(PlayerShockwave* p) { INCFUNC("asm/func/PlayerShockwave_UpdateAnim.inc"); }

// finished が立っていれば下ろし, 立っていなければ衝撃波を消す
void PlayerShockwave_UpdateFlash(PlayerShockwave* p) {
  if (p->finished) {
    p->finished = FALSE;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 攻撃の向き dir から衝撃波スプライトのパラメータ2つを決める
void Player_GetShockwaveDirParams(u32 dir, s32* result1, s32* result2) {
  s32 axis = dir & 3;

  switch (axis) {
    case 0: {
      *result1 = 0;
      break;
    }
    case 1: {
      *result1 = 1;
      break;
    }
    case 2: {
      *result1 = 2;
      break;
    }
    default: {
      *result1 = 1;
      break;
    }
  }

  if (dir <= 2) {
    *result2 = 0;
  } else if (dir == 3 || dir == 4) {
    *result2 = 2;
  } else if (dir == 5) {
    *result2 = 3;
  } else {
    *result2 = 1;
  }
}

// 衝撃波のスプライトに本体と同じパレットを渡して表示する
void FUN_0806181c(Player* p) {
  p->meleeShockwave.gfx.plttID = p->sprite_88.plttID;
  p->meleeShockwave.gfx.pltt = p->sprite_88.pltt;
  AuxSprite_Show(&p->meleeShockwave.sprite);
  p->meleeShockwave.finished = TRUE;
}

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる (多分、 衝撃波 を出す処理)
NAKED void Player_DarkDjangoSword_0806185c(Player* p, u32 idx, Vec3* pos) { INCFUNC("asm/func/Player_DarkDjangoSword_0806185c.inc"); }

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる (多分、 衝撃波 を出す処理)
NAKED void Player_DarkDjangoSpear_08061970(Player* p, u32 idx, Vec3* pos, s32 n) { INCFUNC("asm/func/Player_DarkDjangoSpear_08061970.inc"); }

// Player_DarkDjangoSword_0806185c のような関数だが、いつ呼ばれるか不明 (武器の攻撃ではない)
NAKED void FUN_08061a98(Player* p, u32 idx, Vec3* pos) { INCFUNC("asm/func/FUN_08061a98.inc"); }

// 多分、サバタが攻撃する時に呼ばれる
// サバタの攻撃時に散弾スプライトを pos の少し上に置いて表示する
void Player_ShowGunSpread(Player* p, u32 _, Vec3* pos) {
  p->meleeShockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->meleeShockwave.sprite.pos = *pos;
  p->meleeShockwave.sprite.pos.y += 0xE6;
  p->meleeShockwave.sprite.rotation = p->unk_a8a;
  p->meleeShockwave.finished = TRUE;
}

void FUN_08061b98(Player* p) { AuxSprite_Remove(&(p->meleeShockwave).sprite); }

NAKED void Player_Init_Anim_08061bac(Player* p) { INCFUNC("asm/func/Player_Init_Anim_08061bac.inc"); }

NAKED void FUN_08061c68(Player* p) { INCFUNC("asm/func/FUN_08061c68.inc"); }

NAKED void FUN_08061d20(Player* p, s32* param_2, s32* param_3, s32 param_4) { INCFUNC("asm/func/FUN_08061d20.inc"); }

void FUN_08061db4(Player* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Particle_Remove(&p->ptcl_718.ptcls[i].base);
  }
}

// 0x718 のパーティクル6個を確保して初期化する
void Player_InitPtcl718(Player* p) {
  PlayerParticleState718* st = &p->ptcl_718;
  s32 i;

  st->group = GetParticleGroup(0x1C1E);
  for (i = 0; i < 6; i++) {
    Particle52* ptcl = &st->ptcls[i];

    FUN_0822d9f0(&ptcl->base, st->group, 1);
    Particle_SetOffset(&ptcl->base, -4, -4);
    FUN_0822dadc(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->unk_04[0] = 0;
  st->unk_04[1] = 0;
}

NAKED void FUN_08061e2c(Player* p) { INCFUNC("asm/func/FUN_08061e2c.inc"); }

NAKED void FUN_08061f6c(Player* p) { INCFUNC("asm/func/FUN_08061f6c.inc"); }

NAKED void FUN_080620f0(Player* p) { INCFUNC("asm/func/FUN_080620f0.inc"); }

void FUN_08062258(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcl_858.ptcls[i].base);
  }
}

// 0x858 のパーティクル4個を確保して初期化する
void Player_InitPtcl858(Player* p) {
  PlayerParticleState858* st = &p->ptcl_858;
  s32 i;

  st->group = GetParticleGroup(0x1C1E);
  for (i = 0; i < 4; i++) {
    Particle52* ptcl = &st->ptcls[i];

    FUN_0822d9f0(&ptcl->base, st->group, 1);
    Particle_SetOffset(&ptcl->base, -4, -4);
    FUN_0822dadc(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->unk_04[1] = 0;
  st->unk_04[2] = 0;
}

NAKED void FUN_080622d0(Player* p) { INCFUNC("asm/func/FUN_080622d0.inc"); }

// 屋外かどうかと PFLAG20 の 0x10 で 0 / 4 / 8 を返す
// 残差は屋外判定の 0/1 正規化4命令だけ (29/34), 原典は真偽値を一度レジスタに作ってから 0 と比べている
// Tier A/B と bool32 ローカル化・述語 inline 化は試済, agbcc がどう書いても畳んでしまう
NON_MATCH u32 FUN_0806241c(Player* p) {
#ifdef NONMATCHING_C
  u32 r = 0;

  if (gStat->unk_934 & SF934_OUTDOOR) {
    if (Player_TestFlag20(p, 0x10)) {
      r = 4;
    }
  } else {
    if (Player_TestFlag20(p, 0x10)) {
      r = 8;
    }
  }

  return r;
#else
  INCFUNC("asm/func/FUN_0806241c.inc");
#endif
}

// unk_950 ごとに3色ずつ並んだ表から、パレットの5,6,13番を差し替える
void FUN_08062468(Player* p) {
  rgb555* src = &gObjPlttData[0x280];

  src += p->unk_950 * 3;

  p->pltt_2a4[5] = *src++;
  p->pltt_2a4[6] = src[0];
  p->pltt_2a4[13] = src[1];
}

NAKED void FUN_080624b0(Player* p, u16* param_2, s32 param_3, s32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_080624b0.inc"); }

NAKED void FUN_08062688(Player* p, u32 n) { INCFUNC("asm/func/FUN_08062688.inc"); }

NAKED void FUN_080628ec(Player* p, u32 n) { INCFUNC("asm/func/FUN_080628ec.inc"); }

void FUN_08062c14(Player* p) {
  if (p->unk_18 == 0) {
    p->plttID_94a = 0x1D;
  } else {
    p->plttID_94a = 0x28;
  }
}

NAKED void FUN_08062c3c(Player* p) { INCFUNC("asm/func/FUN_08062c3c.inc"); }

// スプライトのパレットを自前の pltt_2a4 に差し替えて初期状態に戻す
void Player_ResetPltt(Player* p) {
  FUN_08062c14(p);
  FUN_08062c3c(p);
  p->unk_94c = 0xFFFF;
  p->unk_950 = 0xFF;
  p->sprite_88.plttID = p->plttID_94a;
  p->sprite_88.pltt = p->pltt_2a4;
  p->gfx_114->plttID = p->plttID_94a;
  p->gfx_114->pltt = p->pltt_2a4;
  FUN_08062688(p, 0);
}

NAKED void FUN_080630e8(Player* p) { INCFUNC("asm/func/FUN_080630e8.inc"); }

void FUN_08063220(Player* p) {
  s32 count = p->unk_4c4.unk_3;
  s32 i;

  for (i = 0; i < count; i++) {
    FUN_080630e8(p);
  }
}

void FUN_08063248(Player* p) {
  if (p->unk_4c4.kind == 1) {
    Eff082473e0Emitter_Reset(&p->unk_4c4);
  } else {
    s32 count = p->unk_4c4.unk_3;
    s32 i;

    for (i = 0; i < count; i++) {
      FUN_080630e8(p);
    }
  }
}

NAKED void FUN_08063288(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_08063288.inc"); }

u32 FUN_08063478(Player* p) { return (p->angle_400 - p->angle_401 + 0x100) & 0xFF; }

NAKED u32 FUN_08063498(Player* p, u32 n) { INCFUNC("asm/func/FUN_08063498.inc"); }

NAKED void FUN_08063574(Player* p, s32 badcondID, s32 frames) { INCFUNC("asm/func/FUN_08063574.inc"); }

void FUN_08063634(Player* p, s32 n) {
  p->unk_43c[n] = 0;
  if (n == 2) {
    p->unk_456 = gStat->unk_010;
  }
}

NAKED u32 FUN_08063668(Player* p, u32 n) { INCFUNC("asm/func/FUN_08063668.inc"); }

// flashTimer が動いている間, 4フレームごとに pose を flashPose と入れ替える (点滅)
// 残差は共有された return pose のブロック位置だけ (23/23), Tier A の分岐形 4通りと Tier B は試済
NON_MATCH u32 Player_ApplyFlashPose(Player* p, u32 pose) {
#ifdef NONMATCHING_C
  if (p->flashTimer != 0) {
    p->flashTimer--;
    if ((p->flashTimer >> 2) & 1) {
      return p->flashPose;
    }
  }

  return pose;
#else
  INCFUNC("asm/func/Player_ApplyFlashPose.inc");
#endif
}

NAKED void FUN_08063814(Player* p) { INCFUNC("asm/func/FUN_08063814.inc"); }

void FUN_080639d0(Player* p) {
  if (p->input_28c->pressed & (A_BUTTON | B_BUTTON | DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN)) {
    p->angle_400++;
  }
}

NAKED void Player_Update_Helper_080639f8(Player* p) { INCFUNC("asm/func/Player_Update_Helper_080639f8.inc"); }

// Player が抱えているエフェクト・影・パーティクル・衝撃波をまとめて片付ける
void Player_DestroyEffects(Player* p) {
  Eff082473e0Emitter_Destroy(&p->unk_4c4);
  ParticleShadow_Remove(&p->shadow);
  Particle_Remove(&p->ptcl_64c.ptcl);
  Particle_Remove(&p->ptcl_67c.ptcl);
  FUN_08061db4(p);
  FUN_08062258(p);
  FUN_08061b98(p);
}

NAKED void Player_Init_Helper_08063b6c(Player* p) { INCFUNC("asm/func/Player_Init_Helper_08063b6c.inc"); }

u32 Player_WeaponEffectSol(Player* p) { return gStat->sunGauge; }

// 状態異常中や太陽光を浴びている間だけ追加ダメージ 10
u32 Player_WeaponEffectStatCond(Player* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->unk_43c[i] != 0) return 10;
  }

  if (*(p->isSabata + gStat->unk_2c8) != 0) return 10;
  if (p->unk_4c4.unk_3 != 0) return 10;

  return 0;
}

u32 Player_WeaponEffectNight(Player* p) {
  if (FUN_08060e1c(p)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAgility(Player* p) { return p->stats[STAT_AGILITY] >> 3; }

u32 Player_WeaponEffectVitality(Player* p) { return p->stats[STAT_VITALITY] >> 3; }

u32 Player_WeaponEffectSpirit(Player* p) { return p->stats[STAT_SPIRIT] >> 3; }

u32 Player_WeaponEffectENE(Player* p) { return Div(p->ene * 10, p->maxEne); }

u32 Player_WeaponEffectHP(Player* p) { return Div(p->hp * 10, p->maxHP); }

// 火事場: HP が減っているほど強くなる
u32 Player_WeaponEffectKajiba(Player* p) { return Div((p->maxHP - p->hp) * 20, p->maxHP); }

// 逆火事場: HP が減っているほど弱くなる
u32 Player_WeaponEffectGyakuKajiba(Player* p) { return -Div((p->maxHP - p->hp) * 40, p->maxHP); }

// 同じ種族の敵をたくさん倒しているほど威力が上がる
NAKED u32 Player_WeaponEffectKillCount(Player* p, HitboxData* a, HitboxData* b) { INCFUNC("asm/func/Player_WeaponEffectKillCount.inc"); }

// 一定確率で追加ダメージ 10
u32 Player_WeaponEffectRandom(Player* p, HitboxData* a, HitboxData* b) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 10;
  }

  return 0;
}

u32 Player_WeaponEffectAntiBeast(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_BEAST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiThing(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_THING)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiPhantom(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_PHANTOM)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiUndead(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_UNDEAD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiImmortal(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_IMMORTAL)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFlame(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_FLAME)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFrost(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_FROST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectCloud(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_CLOUD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectEarth(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_EARTH)) {
    return 10;
  }
  return 0;
}

// 一定確率で防御無視(なまくら系の特殊効果)
u32 CheckNamakuraProc(void) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 1 << 12;
  }
  return 0;
}

// 一定確率で麻痺
u32 CheckParalyzeProc(void) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 1 << 19;
  }
  return 0;
}

NAKED void FUN_08064058(Player* p) { INCFUNC("asm/func/FUN_08064058.inc"); }

NAKED void Player_EnableWeaponSpecialEffects(Player* p, WeaponData* w) { INCFUNC("asm/func/Player_EnableWeaponSpecialEffects.inc"); }

NAKED void FUN_080643d4(Player* p) { INCFUNC("asm/func/FUN_080643d4.inc"); }

void FUN_08064658(Player* p, Weapon* w) { p->weapon_a70 = w; }

NAKED void weapon_08064664(Player* p, Weapon* w) { INCFUNC("asm/func/weapon_08064664.inc"); }

// HitboxData.damage (Player.unk_a10.damage) が0以外なら Weapon.wear に加算して HitboxData.damage を 0にする, ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で加算される (他の敵も同様と思われる)
NAKED void Player_UpdateWeaponWear(Player* p) { INCFUNC("asm/func/Player_UpdateWeaponWear.inc"); }

NAKED void FUN_0806483c(Player* p, const ArmorData* a) { INCFUNC("asm/func/FUN_0806483c.inc"); }

// 鎧を装備する, a が NULL なら素手の値に戻す
void Player_EquipArmor(Player* p, const ArmorData* a) {
  if (a == NULL) {
    p->armor.id = 0xFFFF;
    p->armor.defence = 0;
    p->armor.weight = 0;
  } else {
    p->armor.id = a->id;
    p->armor.defence = a->defence;
    p->armor.weight = a->weight;
  }

  FUN_0806483c(p, a);
  FUN_080612bc(p);
}

void CheckHeartJokerEmblem(Player* p) {
  if (CheckItemOwn(ITEM_HEART_EMBLEM)) {
    Player_SetFlag378(p, FLAG378_HEART);
  }

  if (CheckItemOwn(ITEM_JOKER_EMBLEM)) {
    Player_SetFlag378(p, FLAG378_JOKER);
  }
}

s32 FUN_08064b00(magic32_t id) {
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return gMagicUnkVal[id];
  } else {
    return gMagicCosts[id];
  }
}

// 装備している魔法の消費 Ene を計算する, 装備していなければ 0
// 命令数は46で一致, 残差は flag378 の読み出しと 0x100 の組み立ての順序だけ (原典は 0x378 を r6 に置いて push が1本多い)
// Tier A/B と C の初期化位置・オペランド順は試済
NON_MATCH s32 CalcMagicCost(Player* p) {
#ifdef NONMATCHING_C
  s32 cost;
  s32 pct;

  if (p->equippedMagic < 0) {
    return 0;
  }

  cost = FUN_08064b00(p->equippedMagic);
  pct = 100;
  if (p->flag378 & FLAG378_UNK_8) {
    pct = 80;
  }
  if (p->equippedMagic <= 5 && (p->flag378 & FLAG378_WET_ENE_COST)) {
    pct -= 20;
  }

  if (pct <= 99) {
    cost = Div(cost * pct, 100);
  }
  return cost;
#else
  INCFUNC("asm/func/CalcMagicCost.inc");
#endif
}

// 装備中の魔法のコストを払えるか, アストロ武器なら太陽スタンドから、そうでなければ ENE から払う
bool32 Player_CheckMagicCost(Player* p) {
  s32 cost = CalcMagicCost(p);
  s32 avail;

  if (p->equippedMagic <= 5 && Player_TestFlag378(p, FLAG378_ASTRO)) {
    avail = gStat->solarStand;
  } else {
    avail = p->ene;
  }

  if (avail >= cost) return TRUE;

  return FALSE;
}

NAKED void Player_PayMagicCost(Player* p) { INCFUNC("asm/func/Player_PayMagicCost.inc"); }

NAKED bool32 FUN_08064c48(Player* p, magic32_t id) { INCFUNC("asm/func/FUN_08064c48.inc"); }

// エンチャント中で、コストも払えて、武器種が銃でも拳でもなければ その魔法の ID を返す
magic32_t Player_CheckMagicEnchant(Player* p) {
  if (p->isEnchanted && p->equippedMagic <= 5 && Player_CheckMagicCost(p)) {
    if ((u8)(p->weaponKind_a75 - STYLE_GUN) > 1) {
      return p->equippedMagic;
    }
  }

  return -1;
}

bool32 Player_HasEnoughEne(Player* p, s32 ene) {
  if (p->ene < ene) return FALSE;
  return TRUE;
}

bool32 FUN_08064d6c(Player* p, s32 val) {
  if (*(p->isSabata + gStat->unk_2c8) > 0) return FALSE;
  if (gStat->sunGauge < val) return FALSE;

  return TRUE;
}

NAKED unknown* FUN_08064db0(Player* p) { INCFUNC("asm/func/FUN_08064db0.inc"); }

NAKED void FUN_08064fd8(Player* p, magic32_t n) { INCFUNC("asm/func/FUN_08064fd8.inc"); }

// 使う魔法の番号を返す, サバタは固定の2種から選び、それ以外は登録魔法から引く
s32 FUN_08065110(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    return *(gStat->equippedMagicIdx + gStat->registeredMagic);
  }

  u16_03002bb0 = 0;
  if (gStat->unk_5e == 0) return 8;

  return 9;
}

NAKED void FUN_08065164(Player* p) { INCFUNC("asm/func/FUN_08065164.inc"); }
