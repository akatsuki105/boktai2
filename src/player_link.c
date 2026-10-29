#include "camera.h"
#include "enemy_target.h"
#include "entity_9a9f.h"
#include "global.h"
#include "input.h"
#include "magic.h"
#include "player.h"
#include "sound.h"
#include "vm.h"

// 通信対戦で対戦相手のプレイヤー?
// player.c, sabata.c に同形の関数がある

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

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

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

bool32 FUN_0809ebf4(Player* p);

// 日光に当たっているかを引き直し, 影のずれと多段ヒット制限を戻す
void FUN_080cc370(Player* p) {
  p->flag20 = PFLAG20_UNK_0;
  if (FUN_0809ebf4(p)) {
    Player_SetFlag20(p, PFLAG20_SUNBATHING);
  }

  VEC3_SET(p->shadowOffset, 0, 0, 0);
  p->flag35a = 0;
  p->hurtbox.hitState &= ~HBHITSTATE_UNK_1;
}

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

// 残差1命令 (30/31): FUN_080cfa24 と同じく, 原典は idx = -1 の materialize を else 側に残すが agbcc は先頭へ巻き上げる
NON_MATCH void FUN_080cc43c(Player* p) {
#ifdef NONMATCHING_C
  s32 idx = gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1;

  if (p->inputIdx == idx) {
    if (p->kind == PLAYER_SABATA) {
      sound_08240740(SONG_569);
      sound_08240740(SONG_514);
      sound_08240740(SONG_870);
    } else {
      sound_08240740(NOISE_SOLAR_CHARGE);
    }
  }
#else
  INCFUNC("asm/func/FUN_080cc43c.inc");
#endif
}

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

void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos);

NAKED void FUN_080cc6b0(Player* p, Vec3* pos, s32 param_3) { INCFUNC("asm/func/FUN_080cc6b0.inc"); }

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

// 種別 kind から下位2bitの値と, 0..5 を 0/2/3 に畳んだ値を取り出す
void FUN_080ccaa0(u32 kind, s32* out1, s32* out2) {
  s32 n = kind & 3;

  switch (n) {
    case 0: {
      *out1 = 0;
      break;
    }
    case 1: {
      *out1 = 1;
      break;
    }
    case 2: {
      *out1 = 2;
      break;
    }
    default: {
      *out1 = 1;
      break;
    }
  }

  if (kind <= 2) {
    *out2 = 0;
  } else if (kind - 3 <= 1) {
    *out2 = 2;
  } else if (kind == 5) {
    *out2 = 3;
  } else {
    *out2 = 1;
  }
}

// 本体スプライトのパレットを衝撃波スプライトへ写してから出す
void FUN_080ccae0(Player* p) {
  p->meleeShockwave.gfx.plttID = p->human.plttID;
  p->meleeShockwave.gfx.pltt = p->human.pltt;
  p->meleeShockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->meleeShockwave.finished = 1;
}

NAKED void FUN_080ccb20(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ccb20.inc"); }

NAKED void FUN_080ccc34(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080ccc34.inc"); }

NAKED void FUN_080ccd5c(Player* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080ccd5c.inc"); }

// 衝撃波スプライトを pos の少し上に出す
void FUN_080cce0c(Player* p, s32 param_2, Vec3* pos) {
  p->meleeShockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->meleeShockwave.sprite.pos = *pos;
  p->meleeShockwave.sprite.pos.y += 0xE6;
  p->meleeShockwave.sprite.rotation = p->wpn.gunSpreadAngle;
  p->meleeShockwave.finished = 1;
}

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

// player.c の Player_InitPtcl718 と同じ内容
void PlayerLink_InitPtcl718(Player* p) {
  PlayerParticleState718* st = &p->ptcl_718;
  s32 i;

  st->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 6; i++) {
    Particle52* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->active = FALSE;
  st->next = 0;
}

NAKED void FUN_080cd0f0(Player* p) { INCFUNC("asm/func/FUN_080cd0f0.inc"); }

NAKED void FUN_080cd230(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd230.inc"); }

NAKED void FUN_080cd3c0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd3c0.inc"); }

void FUN_080cd528(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcl_858.ptcls[i].base);
  }
}

// player.c の Player_InitPtcl858 と同じ内容
void PlayerLink_InitPtcl858(Player* p) {
  PlayerParticleState858* st = &p->ptcl_858;
  s32 i;

  st->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    PlayerPtcl858* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->unk_05 = 0;
  st->unk_06 = 0;
}

NAKED void FUN_080cd5a0(Player* p) { INCFUNC("asm/func/FUN_080cd5a0.inc"); }

// 日光が当たっているとき, 屋外なら 8, 屋内なら 4 を返す
s32 FUN_080cd6ec(Player* p) {
  s32 ret = 0;

  if (!TestMapFlag(MPF_OUTDOOR)) {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      ret = 4;
    }
  } else {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      ret = 8;
    }
  }
  return ret;
}

void FUN_080cd738(Player* p) {
  rgb555* src = &gObjPlttData[40 * 16];

  src += p->unk_950 * 3;

  p->pltt_2a4[5] = *src++;
  p->pltt_2a4[6] = src[0];
  p->pltt_2a4[13] = src[1];
}

NAKED void FUN_080cd780(Player* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080cd780.inc"); }

NAKED void FUN_080cd958(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cd958.inc"); }

NAKED void FUN_080cdbb0(Player* p) { INCFUNC("asm/func/FUN_080cdbb0.inc"); }

NAKED void FUN_080cdc10(Player* p) { INCFUNC("asm/func/FUN_080cdc10.inc"); }

NAKED void FUN_080cdc6c(Player* p) { INCFUNC("asm/func/FUN_080cdc6c.inc"); }

void FUN_080cdda8(Player* p) {
  u8 n = p->emitter.unk_3;

  if (n != 0) {
    s32 i = n;

    do {
      FUN_080cdc6c(p);
      i--;
    } while (i != 0);
  }
}

s32 PlayerLink_GetMashCount(Player* p) { return (p->mashCount - p->mashCountBase + 0x100) & 0xFF; }

NAKED s32 FUN_080cddf0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cddf0.inc"); }

NAKED s32 FUN_080cdeb0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cdeb0.inc"); }

// 残差は共有された return pose のブロック位置だけ (23/23), player.c の Player_ApplyFlashPose と同じ
NON_MATCH s32 FUN_080cdfd4(Player* p, s32 pose) {
#ifdef NONMATCHING_C
  if (p->flashTimer != 0) {
    p->flashTimer--;
    if ((p->flashTimer >> 2) & 1) {
      return p->flashPose;
    }
  }

  return pose;
#else
  INCFUNC("asm/func/FUN_080cdfd4.inc");
#endif
}

NAKED void FUN_080ce00c(Player* p) { INCFUNC("asm/func/FUN_080ce00c.inc"); }

// 方向キーが押された最初のフレームだけ mashCount を1つ進める
void PlayerLink_CountMash(Player* p) {
  if (p->input->pressed & DPAD_ANY) {
    p->mashCount++;
  }
}

NAKED void FUN_080ce28c(Player* p) { INCFUNC("asm/func/FUN_080ce28c.inc"); }

void FUN_080ce330(Player* p) {
  Eff082473e0Emitter_Destroy(&p->emitter);
  ParticleShadow_Remove(&p->shadow);
  Particle_Remove(&p->ptcl_64c.ptcl);
  Particle_Remove(&p->ptcl_67c.ptcl);
  FUN_080cd078(p);
  FUN_080cd528(p);
  FUN_080cce5c(p);
}

NAKED void FUN_080ce378(Player* p) { INCFUNC("asm/func/FUN_080ce378.inc"); }

s32 FUN_080ce4d0(Player* p) {
  u32 i = p->inputIdx;

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

// 相手が魔物なら 10, そうでなければ 0
s32 FUN_080ce504(Player* p, s32 param_2, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_BEAST) || Hitbox_TestAttr(b, HBATTR_THING) || Hitbox_TestAttr(b, HBATTR_PHANTOM) || Hitbox_TestAttr(b, HBATTR_UNDEAD) || Hitbox_TestAttr(b, HBATTR_IMMORTAL)) {
    return 10;
  }
  return 0;
}

NAKED void FUN_080ce544(u32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_080ce544.inc"); }

NAKED void FUN_080ce5a0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080ce5a0.inc"); }

NAKED void FUN_080ce868(Player* p) { INCFUNC("asm/func/FUN_080ce868.inc"); }

NAKED s32 FUN_080ceaa4(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080ceaa4.inc"); }

NAKED void player_weapon_080ceafc(Player* p, Weapon* w) { INCFUNC("asm/func/player_weapon_080ceafc.inc"); }

s32 GetMagicCost(s32 magic) { return gMagicCosts_085ad160[magic]; }

// 装備魔法の消費MP, WET_ENE_COST の武器を持っていると 8 割になる
s32 FUN_080ceba8(Player* p) {
  s32 cost;

  if (p->magic.id < 0) {
    return 0;
  }

  cost = GetMagicCost(p->magic.id);
  if (p->magic.id <= 5 && Player_TestEquipBuff(p, EBUFF_WET_ENE_COST)) {
    cost = Div(cost * 80, 100);
  }
  return cost;
}

s32 FUN_080cebf8(Player* p) {
  s32 cost = FUN_080ceba8(p);

  if (p->ene >= cost) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080cec18(Player* p) { INCFUNC("asm/func/FUN_080cec18.inc"); }

NAKED s32 FUN_080cec70(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cec70.inc"); }

// エンチャント中かつ近接武器を持っているときだけ魔法IDを返す, それ以外は -1
s32 FUN_080ced00(Player* p) {
  if (!p->magic.enchanted) {
    return -1;
  }
  if (p->magic.id > 5) {
    return -1;
  }
  if (!FUN_080cebf8(p)) {
    return -1;
  }
  if (p->wpn.weaponKind == WK_OTHERS || p->wpn.weaponKind == WK_GUN) {
    return -1;
  }
  return p->magic.id;
}

s32 FUN_080ced50(Player* p, s32 cost) {
  if (p->ene < cost) {
    return 0;
  }
  return 1;
}

s32 FUN_080ced68(Player* p, s32 param_2) {
  u32 i = p->inputIdx;
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

// 通信相手の記録から装備魔法の情報を作り直す
void PlayerLink_RefreshMagicInfo(Player* p) {
  PlayerMagic* m = &p->magic;

  m->id = ((u8*)p->unk_288)[0x42];
  if (m->id < 0) {
    m->cat = 0xFF;
    m->basicCost = 0;
    m->availableForm = FALSE;
    m->enchanted = FALSE;
    return;
  }

  m->cat = GetMagicCategory(m->id);
  m->basicCost = GetMagicCost(m->id);
  m->availableForm = FUN_080cec70(p, m->id);
  m->enchanted = FALSE;
}

void FUN_080cef14(Player* p) {
  s32 val = VM_SeekToNamedArg('i');

  if (val != 0) {
    val = VM_GetValue();
  }
  p->inputIdx = val;
}

Entity9A9FRecord* FUN_080cef30(Player* p) {
  s32 i = p->inputIdx;

  if (gEntity9A9F == NULL || i < 0) {
    return NULL;
  }
  return &gEntity9A9F->records[i];
}

NAKED s32 FUN_080cef5c(Player* p) { INCFUNC("asm/func/FUN_080cef5c.inc"); }

void FUN_081dfa20(u32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility);

// 通信相手の記録からステータス4種を引き直す
void FUN_080cefcc(Player* p) {
  s32 strength;
  s32 vitality;
  s32 spirit;
  s32 agility;

  FUN_081dfa20(((u8*)p->unk_288)[0x41], &strength, &vitality, &spirit, &agility);
  p->stats[STAT_VITALITY] = vitality;
  p->stats[STAT_SPIRIT] = spirit;
  p->stats[STAT_STRENGTH] = strength;
  p->stats[STAT_AGILITY] = agility;
}

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

// 入力元と操作方向を通信相手ぶんに差し替え, 方向の履歴を入力なしで埋める
void FUN_080cf064(Player* p) {
  s32 i;

  p->input = &gInput[p->inputIdx];
  p->controlUp = *(u16*)((u8*)p->unk_288 + 0x14);

  for (i = 0; i < 10; i++) {
    p->facingHistory[i] |= 0xFFFF;
  }
}

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

// 残差1命令 (22/23): 原典は gEntity9A9F の NULL 判定を分岐の前後で2回持つが, agbcc は1回に畳む
NON_MATCH void FUN_080cfa24(Player* p) {
#ifdef NONMATCHING_C
  s32 idx;

  if (gEntity9A9F == NULL) {
    idx = -1;
  } else {
    idx = gEntity9A9F->playerIdx;
  }

  if (p->inputIdx == idx) {
    FUN_0823bca8(8);
  }
  p->lookAroundOffset.val = 0;
#else
  INCFUNC("asm/func/FUN_080cfa24.inc");
#endif
}

// 種別と param_2 の組み合わせが許されているか
s32 FUN_080cfa60(Player* p, s32 param_2) {
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    if (param_2 == 0 || param_2 == 3 || param_2 == 6) {
      return 1;
    }
    if (param_2 == 4 && p->unk_3bc != 0) {
      return 1;
    }
    return 0;
  }

  if (param_2 == 0 || param_2 == 4) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080cfaa4(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cfaa4.inc"); }

NAKED void FUN_080cfb20(Player* p) { INCFUNC("asm/func/FUN_080cfb20.inc"); }

// Player_IsOnRock の通信プレイ版
bool32 PlayerLink_IsLiveLava(u32 attr) {
  if ((attr & TATTR_SPECIAL) && !TestMapFlag(MPF_HOT | MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

// Player_IsInLava の通信プレイ版
bool32 PlayerLink_IsFrozenLava(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_HOT)) {
    return TRUE;
  }
  return FALSE;
}

bool32 FUN_080cfc3c(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_UNK_13)) {
    return TRUE;
  }
  return FALSE;
}

bool32 FUN_080cfc78(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_080cfcb0(Player* p) { INCFUNC("asm/func/FUN_080cfcb0.inc"); }

NAKED s32 FUN_080cfdec(Player* p) { INCFUNC("asm/func/FUN_080cfdec.inc"); }

NAKED s32 FUN_080cfec0(Player* p, s32 param_2) { INCFUNC("asm/func/FUN_080cfec0.inc"); }

NAKED s32 FUN_080cffcc(Player* p) { INCFUNC("asm/func/FUN_080cffcc.inc"); }

NAKED void FUN_080d01c8(Player* p) { INCFUNC("asm/func/FUN_080d01c8.inc"); }

// 太陽ゲージ+2 を貯めて, 100 を超えるたびに1回ぶん消費する
void FUN_080d0394(Player* p, s32 sungauge) {
  p->sunburn += sungauge + 2;
  if (p->sunburn > 99) {
    FUN_080cf684(p);
    p->sunburn -= 100;
  }
}

// pos に何かを出し, marker があれば追尾マーカーも出して soundID を鳴らす
void FUN_080d03bc(Player* p, Vec3* pos, s16 param_3, s32 param_4, Vec3* marker, s32 param_6, s32 soundID) {
  FUN_08240cf0(pos->x, pos->z, param_3, 0, param_4, p->mover.id);

  if (marker != NULL) {
    Entity4B15_ShowTrackingMarker(p->inputIdx, marker);
    FUN_080cc6b0(p, marker, param_6);
  }

  if (soundID != 0) {
    Sound_PlayForPlayer(p->inputIdx, soundID);
  }
}

NAKED void FUN_080d040c(Player* p) { INCFUNC("asm/func/FUN_080d040c.inc"); }

NAKED void FUN_080d05e8(Player* p) { INCFUNC("asm/func/FUN_080d05e8.inc"); }

NAKED s32 FUN_080d06d4(Player* p) { INCFUNC("asm/func/FUN_080d06d4.inc"); }

// player.c の FUN_08066f7c と同じ内容
void FUN_080d0738(Player* p) {
  if (p->action != PACT_IDLE) {
    PlayerLink_SetAction(p, PACT_IDLE, 0);
    p->facing = FUN_080d06d4(p);
    PlayerLink_SetAnimFacing(p);
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
}

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

// 進行方向のタイル端数が中央寄りかを返す
// 残差1命令 (23/22): 原典は 0xFF を結果レジスタ側に置くが, こちらは別レジスタに載り複写が1本残る
NON_MATCH s32 FUN_080d0c38(Player* p) {
#ifdef NONMATCHING_C
  s32 pos;
  s32 frac;

  if (p->actionDir == FACE_UP_RIGHT || p->actionDir == FACE_DOWN_LEFT) {
    pos = (u16)p->mover.pos.x;
  } else {
    pos = (u16)p->mover.pos.z;
  }

  frac = pos & 0xFF;
  if (frac < 0x1F || frac > 0xE1) {
    return 0;
  }
  return 1;
#else
  INCFUNC("asm/func/FUN_080d0c38.inc");
#endif
}

NAKED void FUN_080d0c6c(Player* p) { INCFUNC("asm/func/FUN_080d0c6c.inc"); }

s32 FUN_080d1314(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080d1344(Player* p) { INCFUNC("asm/func/FUN_080d1344.inc"); }

NAKED void FUN_080d13b8(Player* p) { INCFUNC("asm/func/FUN_080d13b8.inc"); }

s32 FUN_080d16a4(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

NAKED void FUN_080d16d4(Player* p) { INCFUNC("asm/func/FUN_080d16d4.inc"); }

// 入力があって見回し中でなければ向きを入力方向に合わせ直す
s32 FUN_080d19fc(Player* p) {
  s32 changed = 0;

  if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
    p->facing = FUN_080d0824(p);
    changed = 1;
  }

  PlayerLink_SetAnimFacing(p);
  return changed;
}

void FUN_080d1a44(Player* p) {
  p->wpn.enchantIdx = FUN_080ced00(p);
  if (p->wpn.enchantIdx >= 0) {
    p->unk_951 = p->wpn.enchantIdx + 1;
  } else {
    p->unk_951 = 0;
  }
}

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

// tile の高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
s32 FUN_080d2230(CollisionMapTile* tile, Vec3* pos) {
  s32 height = (tile->heightStairs & 0xF) << 8;

  switch (tile->heightStairs >> 4) {
    case STAIRS_VERTICAL: {
      height -= (u8)pos->z;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= (u8)pos->x;
      break;
    }
  }
  return height;
}

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
  if (p->action != PACT_ATTACK) {
    PlayerLink_SetAction(p, PACT_ATTACK, 0);
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

  if (p->emitter.kind == 2 && p->emitter.unk_3 != 0) {
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

// 入力方向の履歴を1つずらして今フレームの向きを先頭に入れる (FUN_080784fc と同じ)
void FUN_080d6600(Player* p) {
  s32 i;

  for (i = 9; i > 0; i--) {
    p->facingHistory[i] = p->facingHistory[i - 1];
  }

  p->facingHistory[0] = Player_GetDpadFacing(p);
  if ((s16)p->facingHistory[0] >= 0) {
    p->facingHistory[0] = ((s16)p->facingHistory[0] + p->controlUp + 7) & 7;
  }
}

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
  p->plttFlashTimer = 32;
}

NAKED void Cmd_E9DA(void) { INCFUNC("asm/func/Cmd_E9DA.inc"); }

NAKED void Cmd_42EF(void) { INCFUNC("asm/func/Cmd_42EF.inc"); }

NAKED void FUN_080d7fbc(Player* p) { INCFUNC("asm/func/FUN_080d7fbc.inc"); }

NAKED s32 PlayerLink_Update(Player* p) { INCFUNC("asm/func/PlayerLink_Update.inc"); }

s32 PlayerLink_Destroy(Player* p) {
  EnemyTargetManager_Remove(&p->target);
  MainSprite_Remove(&p->human);
  AuxSprite_Remove(&p->beast);
  Hitbox_Unregister(&p->hurtbox);
  Mover_Unlink(&p->mover);
  FUN_080ce330(p);
  FUN_080cc43c(p);
  gPlayerPtr[p->inputIdx] = NULL;
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
