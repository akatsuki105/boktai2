#include "player.h"

#include "armor.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "item.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

extern u16 u16_03002b64;
extern u16 u16_03002bb0;

s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);                 // src/entity_0805fd6c.c
bool32 FUN_0809e138(Player* p);                                                                                        // src/entity_5ccc.c
s32 GetMagicCategory(magic32_t id);                                                                                    // src/equip_magic.c
s32 FUN_080ddcc8(Vec3* pos, u8 param_2, Vec3* size, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8);  // src/entity_080ddf88.c

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

// sprite_88 に animIdx のアニメを設定して1フレーム進める, 前回と同じIDならコマ番号を引き継ぐ
// 命令数は57で一致, 残差は animIdx + animIDOffset の adds のオペランド順だけ (原典は adds r2, r1, r2)
// Tier A/B と複合代入・オペランド入れ替えは試済
NON_MATCH bool32 Player_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
#ifdef NONMATCHING_C
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->sprite_88, &p->spriteSet_68, animIdx + p->animIDOffset, 1, flags);
  if (p->xflip) {
    p->sprite_88.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite_88.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->sprite_88, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->sprite_88, &p->spriteSet_68);
#else
  INCFUNC("asm/func/Player_PlayAnim.inc");
#endif
}

NAKED void Player_SetMoveDelta(Player* p, s32 val) { INCFUNC("asm/func/Player_SetMoveDelta.inc"); }

void Player_SetAction(Player* p, u32 r1, u32 r2) {
  p->action = r1;
  p->state = r2;
  p->stateTimer = 0;
}

// 行動を始める前のフラグ初期化, 日光と武器効果を見て unk_20 を組み立て直し各種タイマを 0 に戻す
// 残差1命令 (61/62): 原典は 0x2C8 を movs/lsls で作るが agbcc が 0x38E のレジスタから引き算で作ってしまう
// 添字をローカルに切り出すと 62/62 になるがレジスタが入れ替わる, Tier A-C は試済
NON_MATCH void Player_BeginAction(Player* p) {
#ifdef NONMATCHING_C
  p->unk_20 = PFLAG20_UNK_0;
  if (gStat->unk_2c8[p->isSabata] == 0 && FUN_0809e138(p)) {
    p->unk_20 |= PFLAG20_UNK_4;
  }
  if (p->flag378 & FLAG378_UNK_9) {
    p->unk_20 |= PFLAG20_UNK_16;
  }

  p->unk_604 = 0;
  p->unk_606 = 0;
  p->unk_608 = 0;
  p->unk_35a = 0;
  p->unk_16c.hitState &= ~2;
#else
  INCFUNC("asm/func/Player_BeginAction.inc");
#endif
}

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

// 攻撃側 a から被弾側 b へ向かう向きを 1/3/5/7 の4象限に落として返す
// 残差4命令: 原典は angle + 0xE0 を両方の枝で別々に組み立てるが, agbcc が ldrb と +0xE0 を共通化してしまう
// Tier A/B と中間変数の切り出しは試済
NON_MATCH u32 Player_GetHitDirIdx(HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  s32 angle;

  if (a->flags & HBFLAG_UNK_8) {
    angle = a->angle + 0xE0;
  } else {
    s32 dx = a->center.x - b->center.x;
    s32 dz = a->center.z - b->center.z;

    if (dx == 0 && dz == 0) {
      angle = b->angle + 0xE0;
    } else {
      angle = ArcTan2_8(dx, dz) + 0x60;
    }
  }

  return ((angle & 0xFF) >> 6) * 2 + 1;
#else
  INCFUNC("asm/func/Player_GetHitDirIdx.inc");
#endif
}

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

// ステータス値を割り振りとドーピングから作り直す, サバタはレベルから4つに均等割りする
// 残差3命令 (79/76): 原典は &p->stats を kind (0x358) のレジスタに +4 して作るが agbcc は 0x35C を組み直す
// Tier A/B は試済
NON_MATCH void Player_RefreshStats(Player* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->kind != PLAYER_SABATA) {
    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = gStat->stats[i] + gStat->stats[i + STAT_KINDS];
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  } else {
    s32 lv = gStat->lv + 10;
    s32 total;
    s32 base;
    s32 rem;

    if (lv > 99) {
      lv = 99;
    }

    total = (lv - 1) * 3;
    base = Div(total, 4);
    rem = total - base * 4;
    base += 10;

    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = gStat->stats[i + STAT_KINDS] + base;
      if (rem > 0) {
        p->stats[i]++;
        rem--;
      }
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  }
#else
  INCFUNC("asm/func/Player_RefreshStats.inc");
#endif
}

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
  Player_RefreshStats(p);
  UpdateMaxHPEne(p);
  FUN_08061198(p);
}

// 足元の判定を1つ出す, コウモリ/ネズミ姿は補助スプライトの位置と小さめの大きさを使う
void Player_SpawnFootHitbox(Player* p) {
  Vec3 size;
  Vec3 pos;

  if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
    pos = p->sprite_e8.pos;
    size.x = 0x20, size.y = 0x20, size.z = 0x20;
  } else {
    pos = p->mover.pos;
    pos.y += 0x50;
    size.x = 0x40, size.y = 0x3C, size.z = 0x40;
  }

  FUN_080ddcc8(&pos, 1, &size, 0, 0, 0xC, 2, 2);
}

// 0x64C のパーティクルを1フレーム進める, 4フレームごとにパレットを1段ずらし6フレーム過ぎたら消す
// 残差は timer++ のレジスタ組だけ (42/43, 原典はアドレスを r1・値を r0 に置く), Tier A/B と C のローカル化は試済
NON_MATCH void Player_UpdatePtcl64c(Player* p) {
#ifdef NONMATCHING_C
  if (p->ptcl_64c.active == 0) {
    return;
  }

  p->ptcl_64c.timer++;
  if (p->ptcl_64c.timer > 5) {
    p->ptcl_64c.ptcl.flags |= SPRFLAG_HIDDEN;
    p->ptcl_64c.active = 0;
    return;
  }

  FUN_0822dafc(&p->ptcl_64c.ptcl, p->ptcl_64c.group1, (p->ptcl_64c.timer >> 2) + p->ptcl_64c.plttBase);
#else
  INCFUNC("asm/func/Player_UpdatePtcl64c.inc");
#endif
}

// 0x64C のパーティクルを pos に出す, big なら別のパレットを使う
void Player_ShowPtcl64c(Player* p, Vec3* pos, s32 big) {
  Particle* ptcl = &p->ptcl_64c.ptcl;

  if (big) {
    p->ptcl_64c.plttBase = 0x48;
  } else {
    p->ptcl_64c.plttBase = 4;
  }

  FUN_0822dafc(ptcl, p->ptcl_64c.group1, p->ptcl_64c.plttBase);
  ptcl->pos = *pos;
  ptcl->flags &= ~SPRFLAG_HIDDEN;
  p->ptcl_64c.active = TRUE;
  p->ptcl_64c.timer = 0;
}

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
  st->active = 0;
  st->timer = 0;
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
  st->active = 0;
  st->timer = 0;
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
// 衝撃波を pos から向きの反対側に少しずらして出す
void Player_SpawnShockwaveBehind(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 sin;
  s32 offset;

  sprite->pos = *pos;

  sin = gSineTable[(angle + 0x40) & 0xFF] * 180;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  sprite->pos.x += offset;

  sin = gSineTable[angle] * 180;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  sprite->pos.z += offset;

  p->meleeShockwave.velX = 0;
  p->meleeShockwave.velZ = 0;
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 2, 0, 0);
  FUN_0806181c(p);
}

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

// 衝撃波スプライトを用意する, サバタは散弾の1枚絵, それ以外はアニメーション付き
void Player_InitShockwave(Player* p) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  AuxSpriteGfx* gfx = &p->meleeShockwave.gfx;

  if (p->kind == PLAYER_SABATA) {
    Video_GetAuxSprite(gfx, 0x2110);
    AuxSprite_Add(sprite, gfx, 0x43);
    sprite->metaspriteIdx = 4;
    Video_SetAuxSpritePltt(gfx, 0x32);
    sprite->priority = 1;
    sprite->scaleY = 0x7F;
    sprite->scaleX = 0x7F;
    sprite->pos = p->mover.pos;
    p->meleeShockwave.update = PlayerShockwave_UpdateFlash;
  } else {
    Video_GetAuxSprite(gfx, 0x8F5D);
    AuxSprite_Add(sprite, gfx, 1);
    Video_SetAuxSpritePltt(gfx, 0x1D);
    p->meleeShockwave.animFile = GetFile(0x922E, 0x837);
    p->meleeShockwave.update = PlayerShockwave_UpdateAnim;
  }

  p->meleeShockwave.finished = FALSE;
}

// 0x718 のパーティクルを1フレーム進める, 12フレームで消え 6フレーム目でパレットを1段進める
// 残差10命令 (76/86): 原典は生存数を高位レジスタ r8 に置き (push が1組増える), 要素のアドレスを r3/r4 の2本に複写している
// Tier A/B は試済, ローカルを増やして原典のレジスタ圧を再現する形は未発見
NON_MATCH void Player_UpdatePtcl718(Player* p) {
#ifdef NONMATCHING_C
  s32 alive;
  s32 i;

  if (!p->ptcl_718.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 6; i++) {
    Particle52* ptcl;

    if (!p->ptcl_718.ptcls[i].active) {
      continue;
    }

    ptcl = &p->ptcl_718.ptcls[i];
    ptcl->unk_31++;
    if (ptcl->unk_31 > 0xB) {
      ptcl->base.flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    if (ptcl->unk_31 == 6) {
      FUN_0822dafc(&ptcl->base, p->ptcl_718.group, ptcl->plttBase + 1);
    }

    ptcl->base.pos.x += ptcl->vel.x;
    ptcl->base.pos.y += ptcl->vel.y;
    ptcl->base.pos.z += ptcl->vel.z;
    alive++;
  }

  if (alive == 0) {
    p->ptcl_718.active = FALSE;
  }
#else
  INCFUNC("asm/func/Player_UpdatePtcl718.inc");
#endif
}

// 0x718 のパーティクルを1つ使って pos / vel を入れて出す, 使う番号は 0..5 を巡回する
void Player_SpawnPtcl718(Player* p, Vec3* pos, Vec3* vel, s32 plttStep) {
  Particle52* ptcl = &p->ptcl_718.ptcls[p->ptcl_718.next];

  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->plttBase = plttStep * 2 + 2;
  FUN_0822dafc(&ptcl->base, p->ptcl_718.group, ptcl->plttBase);
  ptcl->base.pos = *pos;
  ptcl->vel = *vel;
  ptcl->unk_31 = 0;
  ptcl->active = TRUE;
  p->ptcl_718.active = TRUE;
  p->ptcl_718.next++;
  if (p->ptcl_718.next > 5) {
    p->ptcl_718.next = 0;
  }
}

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

  st->active = FALSE;
  st->next = 0;
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

// 状態異常 badcondID を frames フレームかける, 1 は変身を解き 2 は向きをランダムに変える
// 命令数は76で一致, 残差はレジスタ割当だけ (原典は p/badcondID/frames を r5/r6/r7 に置き push が1本多い)
NON_MATCH void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames) {
#ifdef NONMATCHING_C
  switch (badcondID) {
    case 0: {
      break;
    }
    case 1: {
      if (p->unk_4c4.unk_3 != 0) {
        if (p->unk_4c4.kind == 3) {
          break;
        }
        FUN_08063220(p);
      }
      if (p->unk_43c[1] == 0) {
        p->unk_3d8 = 0;
      }
      break;
    }
    case 2: {
      if (p->unk_43c[2] == 0) {
        s32 v;

        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        v = (p->unk_456 + 1 + Mod(gRandomTable[gRandTableIdx], 7)) & 7;
        u16_03002b64 = v;
        p->unk_456 = v;
        PlaySound_082406e0(0x138);
      }
      break;
    }
    default: {
      return;
    }
  }

  p->unk_43c[badcondID] = frames;
#else
  INCFUNC("asm/func/Player_ApplyBadCondition.inc");
#endif
}

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
// 相手の系統に応じた撃破数ボーナス (撃破数/64, 最大10) を返す, 系統が付いていなければ 0
// 命令数は59で一致, 残差は最初の movs #0x80 が attributes の ldr より前か後かだけ
// 各枝で上限処理を書くと cross-jumping が原典と同じ形 (1本目に合流) になる, Tier A/B は試済
NON_MATCH u32 Player_WeaponEffectKillCount(Player* p, HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  s32 n;

  if (b->attributes & HBATTR_BEAST) {
    n = (s16)gStat->killCounts[0] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (b->attributes & HBATTR_THING) {
    n = (s16)gStat->killCounts[1] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (b->attributes & HBATTR_PHANTOM) {
    n = (s16)gStat->killCounts[2] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (b->attributes & HBATTR_UNDEAD) {
    n = (s16)gStat->killCounts[3] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (b->attributes & HBATTR_IMMORTAL) {
    n = (s16)gStat->killCounts[4] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }

  return 0;
#else
  INCFUNC("asm/func/Player_WeaponEffectKillCount.inc");
#endif
}

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

// ブラッドソードの吸収, 通常状態でジャンゴなら unk_376 を増やし, それ以外なら HP を1回復して判定を出す
// 命令数は63で一致, 残差は定数の組み立て順とレジスタ選択だけ (原典は 0x378 のレジスタを subs #2 で 0x376 に使い回す)
// CalcMagicCost / Player_PayMagicCost と同じ系統の残差
NON_MATCH void Player_UpdateBloodSword(Player* p) {
#ifdef NONMATCHING_C
  if (p->unk_1c != 1 || !(p->flag378 & FLAG378_BLOOD_SWORD)) {
    return;
  }

  if (p->kind == 0) {
    if (p->hp <= 1) {
      return;
    }
    p->unk_376++;
  } else {
    if (p->hp >= p->maxHP) {
      return;
    }
    p->hp++;
    FUN_0805fe7c(&p->unk_16c, 1, 1, &p->mover.pos, &p->pos_970, p->unk_978);
  }
#else
  INCFUNC("asm/func/Player_UpdateBloodSword.inc");
#endif
}

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

  if (p->magic.id < 0) {
    return 0;
  }

  cost = FUN_08064b00(p->magic.id);
  pct = 100;
  if (p->flag378 & FLAG378_UNK_8) {
    pct = 80;
  }
  if (p->magic.id <= 5 && (p->flag378 & FLAG378_WET_ENE_COST)) {
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

  if (p->magic.id <= 5 && Player_TestFlag378(p, FLAG378_ASTRO)) {
    avail = gStat->solarStand;
  } else {
    avail = p->ene;
  }

  if (avail >= cost) return TRUE;

  return FALSE;
}

// 魔法の消費分を支払う, 0〜5番の魔法でアストロ武器を装備しているときは Ene ではなく太陽スタンドから引く
// 命令数は46で一致, 残差は FLAG378_ASTRO の movs の位置だけ (原典は flag378 を読む前に置く)
// CalcMagicCost と同じ系統の残差, Tier A/B とオペランド順は試済
NON_MATCH void Player_PayMagicCost(Player* p) {
#ifdef NONMATCHING_C
  s32 cost = CalcMagicCost(p);

  if (p->magic.id <= 5 && (p->flag378 & FLAG378_ASTRO)) {
    if ((s32)gStat->solarStand < cost) {
      gStat->solarStand = 0;
    } else {
      gStat->solarStand -= cost;
    }
  } else {
    if (p->ene < cost) {
      p->ene = 0;
    } else {
      p->ene -= cost;
    }
  }
#else
  INCFUNC("asm/func/Player_PayMagicCost.inc");
#endif
}

NAKED bool32 FUN_08064c48(Player* p, magic32_t id) { INCFUNC("asm/func/FUN_08064c48.inc"); }

// エンチャント中で、コストも払えて、武器種が銃でも拳でもなければ その魔法の ID を返す
magic32_t Player_CheckMagicEnchant(Player* p) {
  if (p->magic.enchanted && p->magic.id <= 5 && Player_CheckMagicCost(p)) {
    if ((u8)(p->weaponKind_a75 - STYLE_GUN) > 1) {
      return p->magic.id;
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

// 装備魔法の情報 (カテゴリ・消費MP・フォームで使えるか・エンチャント中か) を再計算する
void Player_RefreshMagicInfo(Player* p) {
  PlayerMagic* m = &p->magic;

  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    m->id = -1;
  } else {
    m->id = FUN_08065110(p);
  }

  if (m->id < 0) {
    m->cat = 0xFF;
    m->basicCost = 0;
    m->availableForm = FALSE;
    m->enchanted = FALSE;
    return;
  }

  m->cat = GetMagicCategory(m->id);
  m->basicCost = FUN_08064b00(m->id);
  m->availableForm = FUN_08064c48(p, m->id);
  m->enchanted = u16_03002bb0;
  if (!m->availableForm) {
    m->enchanted = FALSE;
    return;
  }

  if (!m->enchanted) {
    return;
  }
  if (m->id > 5) {
    return;
  }
  p->unk_951 = m->id + 1;
}
