#include "enemy_target.h"
#include "entity_9a9f.h"
#include "global.h"
#include "input.h"
#include "player.h"
#include "sound.h"
#include "vm.h"

// 通信対戦で対戦相手のプレイヤー?
// player.c, player_sabata.c に同形の関数がある

const u8 u8_ARRAY_085ad148[4] = {3, 4, 6, 0};  // 0x085AD148 (u8_ARRAY_085abab4 と同じもの)

void FUN_080d2008(Player* p);
void FUN_080d2968(Player* p);
void FUN_080d318c(Player* p);
void FUN_080d34b4(Player* p);
void FUN_080d36ac(Player* p);

const PlayerFunc PTR_ARRAY_085ad14c[5] = {
    [WK_SWORD] = FUN_080d2008,
    [WK_SPEAR] = FUN_080d2968,
    [WK_HAMMER] = FUN_080d318c,
    [WK_OTHERS] = FUN_080d34b4,
    [WK_GUN] = FUN_080d36ac,
};  // 0x085AD14C

const u16 gMagicCosts_085ad160[MAGIC_NUM] = {
    [MAGIC_SOL] = 5,
    [MAGIC_DARK] = 5,
    [MAGIC_FLAME] = 10,
    [MAGIC_FROST] = 10,
    [MAGIC_CLOUD] = 10,
    [MAGIC_EARTH] = 10,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 100,
    [MAGIC_ZERO_SHIFT] = 10,
    [MAGIC_BLACK_SUN] = 100,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 0,
    [MAGIC_HEALING] = 0,
    [MAGIC_DYNAMITE] = 0,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 10,
    [MAGIC_RAT] = 10,
    [MAGIC_WOLF] = 10,
};  // 0x085AD160

void FUN_080d0738(Player* p);
void FUN_080d0a04(Player* p);
void FUN_080d0aa0(Player* p);
void FUN_080d4494(Player* p);
void FUN_080d0c6c(Player* p);
void FUN_080d13b8(Player* p);
void FUN_080d5510(Player* p);
void FUN_080d55d8(Player* p);
void FUN_080d44c4(Player* p);
void FUN_080d482c(Player* p);
void FUN_080d4a34(Player* p);
void FUN_080d4d34(Player* p);
void FUN_080d4fa4(Player* p);
void FUN_080d53e4(Player* p);
void FUN_080d3f1c(Player* p);
void FUN_080d16d4(Player* p);
void FUN_080cc43c(Player* p);
void FUN_080ce330(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085ad184[32] = {
    FUN_080d0738,
    FUN_080d0a04,
    FUN_080d0aa0,
    FUN_080d4494,
    FUN_080d0c6c,
    NULL,
    NULL,
    FUN_080d13b8,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d55d8,
    NULL,
    NULL,
    NULL,
    FUN_080d44c4,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d482c,
    FUN_080d4a34,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
    NULL,
};  // 0x085AD184
// clang-format on

// clang-format off
const PlayerFunc PTR_ARRAY_085ad204[31] = {
    FUN_080d0738,
    FUN_080d0a04,
    FUN_080d5510,
    FUN_080d3f1c,
    FUN_080d0c6c,
    NULL,
    NULL,
    FUN_080d16d4,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d482c,
    FUN_080d4a34,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
};  // 0x085AD204
// clang-format on

void FUN_080d57e4(Player* p);
void FUN_080d5948(Player* p);
void FUN_080d5ae0(Player* p);
void FUN_080d6408(Player* p);
void FUN_080d613c(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085ad280[27] = {
    FUN_080d57e4,
    FUN_080d5948,
    NULL,
    NULL,
    FUN_080d5ae0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d6408,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d613c,
    NULL,
    NULL,
};  // 0x085AD280
// clang-format on

// facing から animIDOffset と xflip を決める
void PlayerLink_SetAnimFacing(Player* p) {
  u8 v = p->facing;

  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = 1;
  } else {
    p->animIDOffset = v;
    p->xflip = 0;
  }
}

NAKED s32 PlayerLink_PlayAnim(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/PlayerLink_PlayAnim.inc"); }

NAKED void FUN_080cc268(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cc268.inc"); }

void PlayerLink_SetAction(Player* p, s32 action, s32 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

NAKED void FUN_080cc370(Player* p) { INCFUNC("asm/func/FUN_080cc370.inc"); }

void FUN_080cc3c4(Player* p, s32 bits) { p->flag35a |= bits; }

s32 FUN_080cc3d4(Player* p, s32 mask) { return p->flag35a & mask; }

// 通信プレイで自分の番号のときだけ効果音を鳴らす
// 命令数は一致 (17/17) だが, 原典は -1 を else のブロックの中で作るのに対し agbcc は分岐より前へ巻き上げるので
// レジスタが1本余分に生き残り push {r4, lr} になる
// Tier A-C 試済: 三項演算子 / gEntity9A9F をローカルに退避 / 退避しない
NON_MATCH void Sound_PlayForPlayer(s32 playerIdx, SoundID32 id) {
#ifdef NONMATCHING_C
  s32 self;

  if (gEntity9A9F == NULL) {
    self = -1;
  } else {
    self = gEntity9A9F->playerIdx;
  }
  if (playerIdx == self) {
    PlaySound_082406e0(id);
  }
#else
  INCFUNC("asm/func/Sound_PlayForPlayer.inc");
#endif
}

// 通信プレイで自分の番号のときだけ効果音を止める
// 残差は Sound_PlayForPlayer と同じ
NON_MATCH void FUN_080cc410(s32 playerIdx, SoundID32 id) {
#ifdef NONMATCHING_C
  s32 self;

  if (gEntity9A9F == NULL) {
    self = -1;
  } else {
    self = gEntity9A9F->playerIdx;
  }
  if (playerIdx == self) {
    sound_08240740(id);
  }
#else
  INCFUNC("asm/func/FUN_080cc410.inc");
#endif
}

NAKED void FUN_080cc43c(Player* p) { INCFUNC("asm/func/FUN_080cc43c.inc"); }

NAKED s32 FUN_080cc494(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cc494.inc"); }

NAKED void FUN_080cc4f4(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080cc4f4.inc"); }

s32 FUN_080cc618(void) {
  s32 v;

  if (gEntity9A9F == NULL) {
    v = 0;
  } else {
    v = gEntity9A9F->records[0].unk_44;
  }

  if (v == 4 || v == 5 || v == 0) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080cc648(Player* p) { INCFUNC("asm/func/FUN_080cc648.inc"); }

NAKED void FUN_080cc6b0(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080cc6b0.inc"); }

NAKED void FUN_080cc71c(Player* p) { INCFUNC("asm/func/FUN_080cc71c.inc"); }

NAKED void FUN_080cc780(Player* p) { INCFUNC("asm/func/FUN_080cc780.inc"); }

NAKED void FUN_080cc8e0(Player* p) { INCFUNC("asm/func/FUN_080cc8e0.inc"); }

NAKED void FUN_080cc944(Player* p) { INCFUNC("asm/func/FUN_080cc944.inc"); }

// アニメが最後まで行った印を消費し, まだなら衝撃波を隠す
void FUN_080cca80(PlayerShockwave* p) {
  if (p->finished) {
    p->finished = FALSE;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_080ccaa0(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ccaa0.inc"); }

NAKED void FUN_080ccae0(Player* p) { INCFUNC("asm/func/FUN_080ccae0.inc"); }

NAKED void FUN_080ccb20(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ccb20.inc"); }

NAKED void FUN_080ccc34(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080ccc34.inc"); }

NAKED void FUN_080ccd5c(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ccd5c.inc"); }

NAKED void FUN_080cce0c(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080cce0c.inc"); }

void FUN_080cce5c(Player* p) { AuxSprite_Remove(&p->meleeShockwave.sprite); }

NAKED void FUN_080cce70(Player* p) { INCFUNC("asm/func/FUN_080cce70.inc"); }

NAKED void FUN_080ccf2c(Player* p) { INCFUNC("asm/func/FUN_080ccf2c.inc"); }

NAKED void FUN_080ccfe4(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080ccfe4.inc"); }

void FUN_080cd078(Player* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Particle_Remove(&p->ptcl_718.ptcls[i].base);
  }
}

NAKED void FUN_080cd098(Player* p) { INCFUNC("asm/func/FUN_080cd098.inc"); }

NAKED void FUN_080cd0f0(Player* p) { INCFUNC("asm/func/FUN_080cd0f0.inc"); }

NAKED void FUN_080cd230(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd230.inc"); }

NAKED void FUN_080cd3c0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd3c0.inc"); }

void FUN_080cd528(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcl_858.ptcls[i].base);
  }
}

NAKED void FUN_080cd548(Player* p) { INCFUNC("asm/func/FUN_080cd548.inc"); }

NAKED void FUN_080cd5a0(Player* p) { INCFUNC("asm/func/FUN_080cd5a0.inc"); }

NAKED s32 FUN_080cd6ec(Player* p) { INCFUNC("asm/func/FUN_080cd6ec.inc"); }

NAKED void FUN_080cd738(Player* p) { INCFUNC("asm/func/FUN_080cd738.inc"); }

NAKED void FUN_080cd780(Player* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080cd780.inc"); }

NAKED void FUN_080cd958(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd958.inc"); }

NAKED void FUN_080cdbb0(Player* p) { INCFUNC("asm/func/FUN_080cdbb0.inc"); }

NAKED void FUN_080cdc10(Player* p) { INCFUNC("asm/func/FUN_080cdc10.inc"); }

NAKED void FUN_080cdc6c(Player* p) { INCFUNC("asm/func/FUN_080cdc6c.inc"); }

void FUN_080cdda8(Player* p) {
  u8 n = p->unk_4c4.unk_3;

  if (n != 0) {
    s32 i = n;

    do {
      FUN_080cdc6c(p);
      i--;
    } while (i != 0);
  }
}

s32 FUN_080cddd0(Player* p) { return (p->angle_400 - p->angle_401 + 0x100) & 0xFF; }

NAKED s32 FUN_080cddf0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cddf0.inc"); }

NAKED s32 FUN_080cdeb0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cdeb0.inc"); }

NAKED s32 FUN_080cdfd4(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cdfd4.inc"); }

NAKED void FUN_080ce00c(Player* p) { INCFUNC("asm/func/FUN_080ce00c.inc"); }

// 方向キーが押された最初のフレームだけ angle_400 を1つ進める
void FUN_080ce264(Player* p) {
  if (p->input->pressed & DPAD_ANY) {
    p->angle_400++;
  }
}

NAKED void FUN_080ce28c(Player* p) { INCFUNC("asm/func/FUN_080ce28c.inc"); }

NAKED void FUN_080ce330(Player* p) { INCFUNC("asm/func/FUN_080ce330.inc"); }

NAKED void FUN_080ce378(Player* p) { INCFUNC("asm/func/FUN_080ce378.inc"); }

s32 FUN_080ce4d0(Player* p) {
  u32 i = p->unk_18;

  if (gEntity9A9F != NULL) {
    return gEntity9A9F->unk_60[i];
  }
  return 0;
}

s32 FUN_080ce4f0(void) {
  if (FUN_080cc618() != 0) {
    return 10;
  }
  return 0;
}

NAKED s32 FUN_080ce504(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ce504.inc"); }

NAKED void FUN_080ce544(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080ce544.inc"); }

NAKED void FUN_080ce5a0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080ce5a0.inc"); }

NAKED void FUN_080ce868(Player* p) { INCFUNC("asm/func/FUN_080ce868.inc"); }

NAKED s32 FUN_080ceaa4(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080ceaa4.inc"); }

NAKED void player_weapon_080ceafc(Player* p, Weapon* w) { INCFUNC("asm/func/player_weapon_080ceafc.inc"); }

s32 GetMagicCost(s32 magic) { return gMagicCosts_085ad160[magic]; }

NAKED s32 FUN_080ceba8(Player* p) { INCFUNC("asm/func/FUN_080ceba8.inc"); }

s32 FUN_080cebf8(Player* p) {
  s32 cost = FUN_080ceba8(p);

  if (p->ene >= cost) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080cec18(Player* p) { INCFUNC("asm/func/FUN_080cec18.inc"); }

NAKED s32 FUN_080cec70(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cec70.inc"); }

NAKED s32 FUN_080ced00(Player* p) { INCFUNC("asm/func/FUN_080ced00.inc"); }

s32 FUN_080ced50(Player* p, s32 cost) {
  if (p->ene < cost) {
    return 0;
  }
  return 1;
}

s32 FUN_080ced68(Player* p, s32 param_2) {
  u32 i = p->unk_18;
  s32 v;

  if (gEntity9A9F == NULL) {
    v = 0;
  } else {
    v = gEntity9A9F->unk_60[i];
  }

  if (v < param_2) {
    return 0;
  }
  return 1;
}

NAKED s32 FUN_080ced90(Player* p) { INCFUNC("asm/func/FUN_080ced90.inc"); }

NAKED void FUN_080ceec0(Player* p) { INCFUNC("asm/func/FUN_080ceec0.inc"); }

void FUN_080cef14(Player* p) {
  s32 val = VM_SeekToNamedArg('i');

  if (val != 0) {
    val = VM_GetValue();
  }
  p->unk_18 = val;
}

Entity9A9FRecord* FUN_080cef30(Player* p) {
  s32 i = p->unk_18;

  if (gEntity9A9F == NULL || i < 0) {
    return NULL;
  }
  return &gEntity9A9F->records[i];
}

NAKED s32 FUN_080cef5c(Player* p) { INCFUNC("asm/func/FUN_080cef5c.inc"); }

NAKED void FUN_080cefcc(Player* p) { INCFUNC("asm/func/FUN_080cefcc.inc"); }

// 体力のステータスから最大HPを決め直して全快にする
void FUN_080cf01c(Player* p) {
  s32 hp = p->stats[0] * 10;

  p->maxHP = hp;
  p->hp = hp;
}

// ENEのステータスから最大ENEを決め直して満タンにする
void FUN_080cf040(Player* p) {
  s32 ene = p->stats[1] * 5 + 100;

  p->maxEne = ene;
  p->ene = ene;
}

NAKED void FUN_080cf064(Player* p) { INCFUNC("asm/func/FUN_080cf064.inc"); }

NAKED s32 FUN_080cf0b4(Player* p) { INCFUNC("asm/func/FUN_080cf0b4.inc"); }

NAKED void FUN_080cf15c(Player* p) { INCFUNC("asm/func/FUN_080cf15c.inc"); }

NAKED void FUN_080cf248(Player* p) { INCFUNC("asm/func/FUN_080cf248.inc"); }

NAKED s32 FUN_080cf3c0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cf3c0.inc"); }

void FUN_080cf54c(Player* p) { player_weapon_080ceafc(p, p->unk_288 + 1); }

NAKED void FUN_080cf560(Player* p) { INCFUNC("asm/func/FUN_080cf560.inc"); }

NAKED void FUN_080cf610(Player* p) { INCFUNC("asm/func/FUN_080cf610.inc"); }

NAKED void FUN_080cf684(Player* p) { INCFUNC("asm/func/FUN_080cf684.inc"); }

NAKED void FUN_080cf740(Player* p) { INCFUNC("asm/func/FUN_080cf740.inc"); }

NAKED void FUN_080cf7f8(Player* p) { INCFUNC("asm/func/FUN_080cf7f8.inc"); }

NAKED void FUN_080cf958(Player* p) { INCFUNC("asm/func/FUN_080cf958.inc"); }

NAKED void FUN_080cfa24(Player* p) { INCFUNC("asm/func/FUN_080cfa24.inc"); }

NAKED s32 FUN_080cfa60(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cfa60.inc"); }

NAKED void FUN_080cfaa4(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cfaa4.inc"); }

NAKED void FUN_080cfb20(Player* p) { INCFUNC("asm/func/FUN_080cfb20.inc"); }

NAKED s32 FUN_080cfbcc(Player* p) { INCFUNC("asm/func/FUN_080cfbcc.inc"); }

NAKED s32 FUN_080cfc04(Player* p) { INCFUNC("asm/func/FUN_080cfc04.inc"); }

NAKED s32 FUN_080cfc3c(Player* p) { INCFUNC("asm/func/FUN_080cfc3c.inc"); }

NAKED s32 FUN_080cfc78(Player* p) { INCFUNC("asm/func/FUN_080cfc78.inc"); }

NAKED void FUN_080cfcb0(Player* p) { INCFUNC("asm/func/FUN_080cfcb0.inc"); }

NAKED s32 FUN_080cfdec(Player* p) { INCFUNC("asm/func/FUN_080cfdec.inc"); }

NAKED s32 FUN_080cfec0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cfec0.inc"); }

NAKED s32 FUN_080cffcc(Player* p) { INCFUNC("asm/func/FUN_080cffcc.inc"); }

NAKED void FUN_080d01c8(Player* p) { INCFUNC("asm/func/FUN_080d01c8.inc"); }

// 太陽ゲージ+2 を貯めて, 100 を超えるたびに1回ぶん消費する
void FUN_080d0394(Player* p, s32 param_2) {
  p->unk_3dc += param_2 + 2;
  if (p->unk_3dc > 99) {
    FUN_080cf684(p);
    p->unk_3dc -= 100;
  }
}

NAKED void FUN_080d03bc(Player* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_080d03bc.inc"); }

NAKED void FUN_080d040c(Player* p) { INCFUNC("asm/func/FUN_080d040c.inc"); }

NAKED void FUN_080d05e8(Player* p) { INCFUNC("asm/func/FUN_080d05e8.inc"); }

NAKED s32 FUN_080d06d4(Player* p) { INCFUNC("asm/func/FUN_080d06d4.inc"); }

NAKED void FUN_080d0738(Player* p) { INCFUNC("asm/func/FUN_080d0738.inc"); }

NAKED s32 FUN_080d0790(Player* p) { INCFUNC("asm/func/FUN_080d0790.inc"); }

NAKED s32 FUN_080d0824(Player* p) { INCFUNC("asm/func/FUN_080d0824.inc"); }

s32 FUN_080d0890(s32 x) {
  if (x == 12) {
    return 0x40;
  }
  if (x <= 11) {
    return (12 - x) * 8 + 0x40;
  }
  return 0x40 - (x - 12) * 4;
}

NAKED void FUN_080d08b8(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080d08b8.inc"); }

NAKED void FUN_080d0a04(Player* p) { INCFUNC("asm/func/FUN_080d0a04.inc"); }

NAKED void FUN_080d0aa0(Player* p) { INCFUNC("asm/func/FUN_080d0aa0.inc"); }

NAKED s32 FUN_080d0c38(Player* p) { INCFUNC("asm/func/FUN_080d0c38.inc"); }

NAKED void FUN_080d0c6c(Player* p) { INCFUNC("asm/func/FUN_080d0c6c.inc"); }

s32 FUN_080d1314(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_UNK_4) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080d1344(Player* p) { INCFUNC("asm/func/FUN_080d1344.inc"); }

NAKED void FUN_080d13b8(Player* p) { INCFUNC("asm/func/FUN_080d13b8.inc"); }

s32 FUN_080d16a4(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_UNK_4) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080d16d4(Player* p) { INCFUNC("asm/func/FUN_080d16d4.inc"); }

NAKED s32 FUN_080d19fc(Player* p) { INCFUNC("asm/func/FUN_080d19fc.inc"); }

NAKED void FUN_080d1a44(Player* p) { INCFUNC("asm/func/FUN_080d1a44.inc"); }

NAKED s32 FUN_080d1a80(Player* p) { INCFUNC("asm/func/FUN_080d1a80.inc"); }

s32 FUN_080d1b04(Player* p) {
  s32 result = FUN_080d1a80(p);
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponExDamageCb[i] != NULL) {
      result += p->weaponExDamageCb[i](p);
    }
  }
  return result;
}

s32 FUN_080d1b38(Player* p) {
  s32 result = 0;
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponEffectCb2[i] != NULL) {
      result |= p->weaponEffectCb2[i](p);
    }
  }
  return result;
}

NAKED void FUN_080d1b68(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080d1b68.inc"); }

NAKED void FUN_080d1c08(Player* p) { INCFUNC("asm/func/FUN_080d1c08.inc"); }

NAKED void FUN_080d1d44(Player* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080d1d44.inc"); }

NAKED s32 FUN_080d1e7c(Player* p) { INCFUNC("asm/func/FUN_080d1e7c.inc"); }

NAKED void FUN_080d2008(Player* p) { INCFUNC("asm/func/FUN_080d2008.inc"); }

NAKED void FUN_080d21d0(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080d21d0.inc"); }

NAKED s32 FUN_080d2230(unknown* p, s32 param_2) { INCFUNC("asm/func/FUN_080d2230.inc"); }

NAKED s32 FUN_080d2258(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080d2258.inc"); }

NAKED void FUN_080d230c(Player* p) { INCFUNC("asm/func/FUN_080d230c.inc"); }

NAKED void FUN_080d25f8(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080d25f8.inc"); }

NAKED s32 FUN_080d2724(Player* p) { INCFUNC("asm/func/FUN_080d2724.inc"); }

NAKED void FUN_080d2968(Player* p) { INCFUNC("asm/func/FUN_080d2968.inc"); }

NAKED void FUN_080d2c00(Player* p) { INCFUNC("asm/func/FUN_080d2c00.inc"); }

NAKED void FUN_080d2d48(Player* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080d2d48.inc"); }

NAKED s32 FUN_080d2ed0(Player* p) { INCFUNC("asm/func/FUN_080d2ed0.inc"); }

NAKED void FUN_080d318c(Player* p) { INCFUNC("asm/func/FUN_080d318c.inc"); }

NAKED void FUN_080d3338(Player* p) { INCFUNC("asm/func/FUN_080d3338.inc"); }

NAKED s32 FUN_080d33dc(Player* p) { INCFUNC("asm/func/FUN_080d33dc.inc"); }

NAKED void FUN_080d34b4(Player* p) { INCFUNC("asm/func/FUN_080d34b4.inc"); }

NAKED void FUN_080d36ac(Player* p) { INCFUNC("asm/func/FUN_080d36ac.inc"); }

NAKED void FUN_080d3b14(Player* p) { INCFUNC("asm/func/FUN_080d3b14.inc"); }

NAKED void FUN_080d3f1c(Player* p) { INCFUNC("asm/func/FUN_080d3f1c.inc"); }

void FUN_080d4494(Player* p) {
  if (p->action != 3) {
    PlayerLink_SetAction(p, 3, 0);
  }
  p->attackCB(p);
}

NAKED void FUN_080d44c4(Player* p) { INCFUNC("asm/func/FUN_080d44c4.inc"); }

NAKED void FUN_080d4638(Player* p) { INCFUNC("asm/func/FUN_080d4638.inc"); }

NAKED void FUN_080d482c(Player* p) { INCFUNC("asm/func/FUN_080d482c.inc"); }

NAKED void FUN_080d4a34(Player* p) { INCFUNC("asm/func/FUN_080d4a34.inc"); }

NAKED void FUN_080d4d34(Player* p) { INCFUNC("asm/func/FUN_080d4d34.inc"); }

NAKED void FUN_080d4fa4(Player* p) { INCFUNC("asm/func/FUN_080d4fa4.inc"); }

NAKED void FUN_080d53e4(Player* p) { INCFUNC("asm/func/FUN_080d53e4.inc"); }

NAKED void FUN_080d5510(Player* p) { INCFUNC("asm/func/FUN_080d5510.inc"); }

NAKED void FUN_080d55d8(Player* p) { INCFUNC("asm/func/FUN_080d55d8.inc"); }

NAKED void FUN_080d57e4(Player* p) { INCFUNC("asm/func/FUN_080d57e4.inc"); }

s32 FUN_080d5908(Player* p) {
  s32 v = 12;

  if (p->unk_4c4.kind == 2 && p->unk_4c4.unk_3 != 0) {
    v = 8;
  }
  if (p->speedPenalty != 0) {
    v -= p->speedPenalty;
  }
  if (v <= 1) {
    return 2;
  }
  return v;
}

NAKED void FUN_080d5948(Player* p) { INCFUNC("asm/func/FUN_080d5948.inc"); }

NAKED void FUN_080d5ae0(Player* p) { INCFUNC("asm/func/FUN_080d5ae0.inc"); }

NAKED void FUN_080d5cd4(Player* p) { INCFUNC("asm/func/FUN_080d5cd4.inc"); }

NAKED void FUN_080d5e70(Player* p) { INCFUNC("asm/func/FUN_080d5e70.inc"); }

NAKED void FUN_080d613c(Player* p) { INCFUNC("asm/func/FUN_080d613c.inc"); }

NAKED void FUN_080d6408(Player* p) { INCFUNC("asm/func/FUN_080d6408.inc"); }

NAKED void FUN_080d6600(Player* p) { INCFUNC("asm/func/FUN_080d6600.inc"); }

NAKED s32 FUN_080d664c(Player* p) { INCFUNC("asm/func/FUN_080d664c.inc"); }

NAKED s32 FUN_080d6804(Player* p) { INCFUNC("asm/func/FUN_080d6804.inc"); }

NAKED void FUN_080d69dc(Player* p) { INCFUNC("asm/func/FUN_080d69dc.inc"); }

NAKED void FUN_080d6b24(Player* p) { INCFUNC("asm/func/FUN_080d6b24.inc"); }

NAKED void FUN_080d6ea0(Player* p) { INCFUNC("asm/func/FUN_080d6ea0.inc"); }

NAKED s32 FUN_080d7210(Player* p) { INCFUNC("asm/func/FUN_080d7210.inc"); }

NAKED void FUN_080d72a8(Player* p) { INCFUNC("asm/func/FUN_080d72a8.inc"); }

NAKED void FUN_080d7374(Player* p) { INCFUNC("asm/func/FUN_080d7374.inc"); }

// ignoreMask の立っているビットのプレイヤーを返す, 無ければ1人目
Player* FUN_080d7444(HitboxData* hitbox) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if ((hitbox->ignoreMask >> i) & 1) {
      return gPlayerPtr[i];
    }
  }
  return gPlayerPtr[0];
}

NAKED void FUN_080d7474(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080d7474.inc"); }

NAKED void FUN_080d74e8(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080d74e8.inc"); }

NAKED s32 FUN_080d7558(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080d7558.inc"); }

NAKED void FUN_080d787c(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080d787c.inc"); }

NAKED s32 FUN_080d78dc(Player* p) { INCFUNC("asm/func/FUN_080d78dc.inc"); }

NAKED void FUN_080d7b50(Player* p) { INCFUNC("asm/func/FUN_080d7b50.inc"); }

s32 FUN_080d7bac(void) {
  if (VM_SeekToNamedArg('i') != 0) {
    return VM_GetValue();
  }
  return 0;
}

void FUN_080d7bc4(Player* p, s32 plttID) {
  p->plttID_95e = plttID;
  p->unk_960 = 0x20;
}

NAKED void FUN_080d7bdc(void) { INCFUNC("asm/func/FUN_080d7bdc.inc"); }

NAKED void FUN_080d7f48(void) { INCFUNC("asm/func/FUN_080d7f48.inc"); }

NAKED void FUN_080d7fbc(Player* p) { INCFUNC("asm/func/FUN_080d7fbc.inc"); }

NAKED s32 PlayerLink_Update(Player* p) { INCFUNC("asm/func/PlayerLink_Update.inc"); }

s32 PlayerLink_Destroy(Player* p) {
  EnemyTargetManager_Remove(&p->target);
  MainSprite_Remove(&p->sprite_88);
  AuxSprite_Remove(&p->sprite_e8);
  Hitbox_Unregister(&p->hurtbox);
  Mover_Unlink(&p->mover);
  FUN_080ce330(p);
  FUN_080cc43c(p);
  gPlayerPtr[p->unk_18] = NULL;
  gPlayerCount--;
  return 0;
}

NAKED s32 PlayerLink_Init(Player* p, u32 val1, u32 val2) { INCFUNC("asm/func/PlayerLink_Init.inc"); }

// 0x980B, HashName("通信対戦プレイヤー")
Player* PlayerLink_Create(u32 val1, u32 val2) {
  Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));

  if (p != NULL) {
    SetEntityRoutine(p, PlayerLink_Update, PlayerLink_Destroy);
    if (PlayerLink_Init(p, val1, val2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
