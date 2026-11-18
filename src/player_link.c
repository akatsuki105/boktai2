#include "camera.h"
#include "dust.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "link_session.h"
#include "magic.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "vm.h"

// 通信対戦で対戦相手のプレイヤー?
// player.c, sabata.c に同形の関数がある

const u8 u8_ARRAY_085ad148[4] = {3, 4, 6, 0};  // 0x085AD148 (u8_ARRAY_085abab4 と同じもの)

void PlayerLink_UpdateSwordAttack(Player* p);
void PlayerLink_UpdateSpearAttack(Player* p);
void PlayerLink_UpdateHammerAttack(Player* p);
void PlayerLink_UpdateFistAttack(Player* p);
void PlayerLink_UpdateSolarGunAttack(Player* p);

const PlayerFunc PTR_ARRAY_085ad14c[5] = {
    [WK_SWORD] = PlayerLink_UpdateSwordAttack,
    [WK_SPEAR] = PlayerLink_UpdateSpearAttack,
    [WK_HAMMER] = PlayerLink_UpdateHammerAttack,
    [WK_OTHERS] = PlayerLink_UpdateFistAttack,
    [WK_GUN] = PlayerLink_UpdateSolarGunAttack,
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
void PlayerLink_UpdateWalk(Player* p);
void PlayerLink_UpdateDash(Player* p);
void FUN_080d4494(Player* p);
void PlayerLink_UpdateWall(Player* p);
void PlayerLink_UpdateSolarCharge(Player* p);
void PlayerLink_ZeroShift(Player* p);
void PlayerLink_ChangeMouse(Player* p);
void PlayerLink_UpdateDynamite(Player* p);
void PlayerLink_UpdateHurt(Player* p);
void PlayerLink_UpdateBlownAway(Player* p);
void FUN_080d4d34(Player* p);
void FUN_080d4fa4(Player* p);
void FUN_080d53e4(Player* p);
void PlayerLink_UpdateSabataAttack(Player* p);
void PlayerLink_UpdateDarkCharge(Player* p);
void FUN_080cc43c(Player* p);
void FUN_080ce330(Player* p);
s32 PlayerLink_CheckMagicEnchant(Player* p);
void Player_UpdateBloodSword(Player* p);
void* BloodEmitter_Create(void);
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);
void Player_MakeNoise(Player* p, Vec3* pos1, s32 param_3, s32 param_4, Vec3* pos2, bool32 fragileWall, SoundID32 soundID);
NON_MATCH bool32 Player_IsNearTileCenter(Player* p);
s32 MovableBlock_PushAtDir8(Vec3* pos, u32 dir);
s32 FUN_08020358(u32 id);
void Hitbox_ApplyDamageAlt(Hitbox* a, Hitbox* b);
s32 SpawnBlood(Vec3* pos, Vec3* param_2, u32 param_3, u32 param_4, u32 param_5);
NON_MATCH void Player_InflictElementalCond(Player* p, u32 kind);
void FUN_080dab9c(s32 idx);
struct Bullet* Bullet_Create(Player* player, u32 heightOffset, u32 forwardOffset, u32 sideOffset, u32 offsetRadius, u32 plttID, u32 knockback, HitboxAttrs attrs, u32 iframes, u32 pose, u32 cost, bool32 elefan);
NON_MATCH void Player_ApplyWindPush(Player* p);
void Player_StopChargeAndLookAround(Player* p);
bool8 MapItemManager_TryOpen(Mover* mover);
bool32 IsInPuddle(WorldPos* pos);
struct DynamiteEffect* DynamiteEffect_Create(Player* owner, Vec3* pos, s32 mode);
void Entity080acd4c_Spawn(Vec3* pos);
u32 CheckStunProc(Player* p);
u32 CheckNamakuraProc(Player* p);
u32 Player_WeaponEffectVitality(Player* p);
u32 Player_WeaponEffectStatCond(Player* p);
u32 Player_WeaponEffectSpirit(Player* p);
u32 Player_WeaponEffectRandom(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectKajiba(Player* p);
u32 Player_WeaponEffectHP(Player* p);
u32 Player_WeaponEffectGyakuKajiba(Player* p);
u32 Player_WeaponEffectFrost(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectFlame(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectEarth(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectENE(Player* p);
u32 Player_WeaponEffectCloud(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAntiUndead(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAntiThing(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAntiPhantom(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAntiImmortal(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAntiBeast(Player* p, Hitbox* a, Hitbox* b);
u32 Player_WeaponEffectAgility(Player* p);
struct TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5);
void Camera_LookAt(Vec3* pos);
struct Elevator* Elevator_FindAtPos(Vec3* pos);
void PlayerLink_OnHurt(Hitbox* a, Hitbox* b, Player* p);

// clang-format off
const PlayerFunc gLinkDjangoActionFuncs[32] = {
    FUN_080d0738,
    PlayerLink_UpdateWalk,
    PlayerLink_UpdateDash,
    FUN_080d4494,
    PlayerLink_UpdateWall,
    NULL,
    NULL,
    PlayerLink_UpdateSolarCharge,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PlayerLink_ChangeMouse,
    NULL,
    NULL,
    NULL,
    PlayerLink_UpdateDynamite,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PlayerLink_UpdateHurt,
    PlayerLink_UpdateBlownAway,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
    NULL,
};  // 0x085AD184
// clang-format on

// clang-format off
const PlayerFunc gLinkSabataActionFuncs[31] = {
    FUN_080d0738,
    PlayerLink_UpdateWalk,
    PlayerLink_ZeroShift,
    PlayerLink_UpdateSabataAttack,
    PlayerLink_UpdateWall,
    NULL,
    NULL,
    PlayerLink_UpdateDarkCharge,
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
    PlayerLink_UpdateHurt,
    PlayerLink_UpdateBlownAway,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
};  // 0x085AD204
// clang-format on

void PlayerLink_UpdateMouseIdle(Player* p);
void PlayerLink_UpdateMouseWalk(Player* p);
void PlayerLink_UpdateMouseMakeNoise(Player* p);
void PlayerLink_UndoChangeMouse(Player* p);
void PlayerLink_UpdateMouseHurt(Player* p);

// clang-format off
const PlayerFunc gLinkMouseActionFuncs[27] = {
    PlayerLink_UpdateMouseIdle,
    PlayerLink_UpdateMouseWalk,
    NULL,
    NULL,
    PlayerLink_UpdateMouseMakeNoise,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PlayerLink_UndoChangeMouse,
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
    PlayerLink_UpdateMouseHurt,
    NULL,
    NULL,
};  // 0x085AD280
// clang-format on

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

static inline s32 Player_GetIframes(Player* p) { return p->hurtbox.iframes; }

static inline void Player_SetIframes(Player* p, u16 time) { p->hurtbox.iframes = time; }

static inline s32 LinkSession_GetPlayerIdx(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// ignoreMask のうち mask のビットを見る, 通信対戦の攻撃判定では撃ったプレイヤーのビットが立つ
static inline u32 Hitbox_TestIgnoreMask(Hitbox* hb, u32 mask) { return hb->ignoreMask & mask; }

static inline bool32 HasGoodCond(Player* p, u32 id) {
  if (p->goodCondTimer != 0 && p->goodCondID == id) {
    return TRUE;
  }
  return FALSE;
}

// facing から animDir と xflip を決める
void PlayerLink_SetAnimFacing(Player* p) {
  u8 dir8 = p->facing;

  if (IS_8DIR_LEFT(dir8)) {
    p->animDir = 8 - dir8;
    p->xflip = TRUE;
  } else {
    p->animDir = dir8;
    p->xflip = FALSE;
  }
}

// animIdx のアニメを向きのオフセット込みで流し, 同じアニメなら続きから再生する, 1コマ進めて一巡したら TRUE
bool32 PlayerLink_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->human, &p->humanGfx, p->animID + p->animDir, PLAYMODE_LOOP, flags);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->human, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
}

// 向きと速さから mover.delta を作る, 階段タイルの上では上りで 52/64, 下りで 40/64 に変える
void PlayerLink_SetMoveDelta(Player* p, s32 val) {
  s32 angle = ((p->facing + 5) & 7) * 32;

  p->mover.delta.x = POLAR_X(val, angle);
  p->mover.delta.z = POLAR_Z(val, angle);

  if (p->tile.stairs[1] == 1) {
    if (p->mover.delta.z < 0) {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
    } else {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
    }
  } else if (p->tile.stairs[1] == 2) {
    if (p->mover.delta.x < 0) {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
    } else {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
    }
  }
}

void PlayerLink_SetAction(Player* p, s32 action, s32 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

bool32 FUN_0809ebf4(Player* p);

// 日光に当たっているかを引き直し, 影のずれと多段ヒット制限を戻す
void FUN_080cc370(Player* p) {
  p->flag20 = PFLAG20_BUSY;
  if (FUN_0809ebf4(p)) {
    Player_SetFlag20(p, PFLAG20_SUNBATHING);
  }

  VEC3_SET(p->shadowOffset, 0, 0, 0);
  p->flag35a = 0;
  p->hurtbox.hitState &= ~HBHITSTATE_ONCE_HIT;
}

void PlayerLink_SetFlag35a(Player* p, s32 bits) { p->flag35a |= bits; }

s32 PlayerLink_TestFlag35a(Player* p, s32 mask) { return p->flag35a & mask; }

// 通信プレイで自分の番号のときだけ効果音を鳴らす
void Sound_PlayForPlayer(s32 playerIdx, SoundID32 id) {
  if (playerIdx == LinkSession_GetPlayerIdx()) {
    PlaySound_082406e0(id);
  }
}

// 通信プレイで自分の番号のときだけ効果音を止める
void Sound_StopForPlayer(s32 playerIdx, SoundID32 id) {
  if (playerIdx == LinkSession_GetPlayerIdx()) {
    sound_08240740(id);
  }
}

// 残差1命令 (30/31): PlayerLink_EndLookAround と同じく, 原典は idx = -1 の materialize を else 側に残すが agbcc は先頭へ巻き上げる
NON_MATCH void FUN_080cc43c(Player* p) {
#ifdef NONMATCHING_C
  s32 idx = gLinkSession != NULL ? gLinkSession->playerIdx : -1;

  if (p->inputIdx == idx) {
    if (p->kind == PLAYER_SABATA) {
      sound_08240740(NOISE_DARK_CHARGE);
      sound_08240740(SE_GUN_SPREAD);
      sound_08240740(SONG_870);
    } else {
      sound_08240740(NOISE_SOLAR_CHARGE);
    }
  }
#else
  INCFUNC("asm/func/FUN_080cc43c.inc");
#endif
}

// 被弾側 b から攻撃側 a を向く向きを 1/3/5/7 の斜め4方向に丸めて返す, 同じ位置なら b->angle から作る
u32 PlayerLink_GetDirToAttacker(Hitbox* a, Hitbox* b) {
  s32 angle;
  s32 dx;
  s32 dz;

  if (a->flags & HBF_ANGLE) {
    angle = a->angle + 0xE0;
    return ((angle & 0xFF) >> 6) * 2 + 1;
  }

  dx = a->center.x - b->center.x;
  dz = a->center.z - b->center.z;
  if (dx == 0 && dz == 0) {
    angle = b->angle + 0xE0;
    return ((angle & 0xFF) >> 6) * 2 + 1;
  }

  angle = ArcTan2_8(dx, dz) + 0x60;
  return ((angle & 0xFF) >> 6) * 2 + 1;
}

// 被弾したときの向きと退避処理, 攻撃側 a のダメージを被弾側 b に移してから向きを決める
void PlayerLink_SetupKnockback(Player* p, Hitbox* a, Hitbox* b) {
  b->knockback = a->knockback;
  if (a->knockback > 200) {
    b->knockback = 200;
  }

  if (Hitbox_TestAttr(a, HBATTR_BLOW)) {
    p->blownAway = 1;
    p->facing = PlayerLink_GetDirToAttacker(a, b);
    return;
  }

  if (p->action == PACT_PUSH) {
    b->flags |= HBF_HIDDEN;
    b->knockback = 0;
    return;
  }

  if (Player_TestFlag20(p, PFLAG20_UNK_15)) {
    if (a->flags & HBF_ANGLE) {
      p->knockbackDir = ANGLE_TO_DIR8(a->angle + 0x10);
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->knockbackDir = p->facing;
      } else {
        p->knockbackDir = (ANGLE_TO_DIR8(((u16)ArcTan2_8(dx, dz) + 0x10)) + 4) & 7;
      }
    }

    p->knockbackSpeed = b->knockback;
    b->knockback = 0;
    b->flags |= HBF_HIDDEN;
    return;
  }

  p->blownAway = 0;
  p->facing = PlayerLink_GetDirToAttacker(a, b);
}

s32 PlayerLink_IsNight(void) {
  s32 v;

  if (gLinkSession == NULL) {
    v = 0;
  } else {
    v = gLinkSession->records[0].unk_44;
  }

  if (v == 4 || v == 5 || v == 0) {
    return 1;
  }
  return 0;
}

// 物音の漫符のパーティクルを1フレーム進める, 4フレームごとにパレットを1段ずらし6フレーム過ぎたら消す
void PlayerLink_UpdateNoisePtcl(Player* p) {
  if (p->noise.active == 0) {
    return;
  }

  if (++p->noise.timer > 5) {
    p->noise.ptcl.flags |= SPRFLAG_HIDDEN;
    p->noise.active = 0;
    return;
  }

  Particle_SetPose(&p->noise.ptcl, p->noise.group1, p->noise.poseIdx + (p->noise.timer >> 2));
}

void LinkPlayerMarker_ShowTracking(s32 playerIdx, Vec3* pos);

// 物音の漫符のパーティクルを pos に出す, 傷んだ壁を叩いたときは専用の漫符にする
void PlayerLink_ShowNoisePtcl(Player* p, Vec3* pos, bool32 isFragileWallKnock) {
  Particle* ptcl = &p->noise.ptcl;

  if (isFragileWallKnock) {
    p->noise.poseIdx = PTCL1_FRAGILE_KNOCK_S;
  } else {
    p->noise.poseIdx = PTCL1_NOISE_S;
  }

  Particle_SetPose(ptcl, p->noise.group1, p->noise.poseIdx);
  ptcl->pos = *pos;
  ptcl->flags &= ~SPRFLAG_HIDDEN;
  p->noise.active = TRUE;
  p->noise.timer = 0;
}

// 物音の漫符のパーティクルを確保して隠した状態で初期化する
void PlayerLink_InitNoisePtcl(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->noise.group1 = group;
  ptcl = &p->noise.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->noise.group1, PTCL1_NOISE_S);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 20;
  p->noise.active = 0;
  p->noise.timer = 0;
}

// 混乱時に、周囲を回るパーティクルを1つ出し続ける
void PlayerLink_UpdateConfusePtcl(Player* p) {
  s32 angle;

  if (p->spurl.active) {
    if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
      p->spurl.ptcl.flags |= SPRFLAG_HIDDEN;
      p->spurl.active = FALSE;
      return;
    }

    angle = (p->spurl.timer * 5) & 0xFF;

    p->spurl.ptcl.pos.x = p->mover.pos.x + POLAR_X(Q8(0.22), angle);
    p->spurl.ptcl.pos.y = p->mover.pos.y + Q8(1.37) + POLAR_Z(Q8(0.274), angle);
    p->spurl.ptcl.pos.z = p->mover.pos.z - POLAR_X(Q8(0.22), angle);

    p->spurl.timer++;
    return;
  }

  if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
    return;
  }

  p->spurl.ptcl.pos = p->mover.pos;
  p->spurl.ptcl.pos.x += Q8(0.22);
  p->spurl.ptcl.pos.y += Q8(1.37);
  p->spurl.ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetPose(&p->spurl.ptcl, p->spurl.group1, PTCL1_CONFUSE);
  p->spurl.timer = 0;
  p->spurl.active = TRUE;
}

// 混乱のパーティクルを確保して隠した状態で初期化する
void PlayerLink_InitConfusePtcl(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->spurl.group1 = group;
  ptcl = &p->spurl.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->spurl.group1, PTCL1_CONFUSE);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 20;
  p->spurl.active = 0;
  p->spurl.timer = 0;
}

// 衝撃波のアニメーションを1コマ進めて動かし, 末尾まで行ったら消して finished を落とす (PlayerShockwave_UpdateAnim と同じ)
void PlayerLink_UpdateShockwaveAnim(PlayerShockwave* p) {
  if (!p->finished) {
    return;
  }

  if (AuxSprite_AdvanceAnim(&p->sprite, &p->anim)) {
    p->finished = FALSE;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    return;
  }

  p->sprite.pos.x += p->vel.x;
  p->sprite.pos.z += p->vel.z;
}

// アニメが最後まで行った印を消費し, まだなら衝撃波を隠す
void PlayerLink_UpdateShockwaveFlash(PlayerShockwave* p) {
  if (p->finished) {
    p->finished = FALSE;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 種別 kind から下位2bitの値と, 0..5 を 0/2/3 に畳んだ値を取り出す
void PlayerLink_GetShockwaveDirParams(u32 kind, s32* out1, s32* out2) {
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
void PlayerLink_ShowShockwave(Player* p) {
  p->shockwave.gfx.plttID = p->human.plttID;
  p->shockwave.gfx.pltt = p->human.pltt;
  p->shockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->shockwave.finished = 1;
}

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, 衝撃波を向きに応じてずらして出す
void PlayerLink_SpawnSwordShockwave(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->shockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 variant;
  s32 flags;

  sprite->pos = *pos;
  sprite->pos.y += Q8(0.743);
  sprite->pos.x += POLAR_X(Q8(0.94), angle);
  sprite->pos.z += POLAR_Z(Q8(0.94), angle);
  p->shockwave.vel.x = POLAR_X(Q8(0.04), angle);
  p->shockwave.vel.z = POLAR_Z(Q8(0.04), angle);

  PlayerLink_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->shockwave.anim, p->shockwave.animFile, 0, variant, flags);
  PlayerLink_ShowShockwave(p);
}

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, n で衝撃波の高さと前に出る距離が変わる
void PlayerLink_SpawnSpearShockwave(Player* p, u32 idx, Vec3* pos, s32 n) {
  AuxSprite* sprite = &p->shockwave.sprite;
  s32 height;
  s32 dist;
  s32 angle;
  s32 variant;
  s32 flags;

  if (n == 0) {
    height = Q8(0.625);
    dist = Q8(1.76);
  } else if (n == 1) {
    height = Q8(0.55);
    dist = Q8(1.321);
  } else {
    height = Q8(0.47);
    dist = Q8(0.875);
  }

  angle = ((p->facing + 5) & 7) * 32;

  sprite->pos = *pos;
  sprite->pos.y += height;
  sprite->pos.x += POLAR_X(dist, angle);
  sprite->pos.z += POLAR_Z(dist, angle);
  p->shockwave.vel.x = POLAR_X(Q8(0.04), angle);
  p->shockwave.vel.z = POLAR_Z(Q8(0.04), angle);

  PlayerLink_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->shockwave.anim, p->shockwave.animFile, 1, variant, flags);
  PlayerLink_ShowShockwave(p);
}

// 黒ジャンゴがハンマーを振り下ろしたとき, pos から向いている方向へ 180 ずらした位置に衝撃波を出す (Player_SpawnHammerShockwave と同じ)
void PlayerLink_SpawnHammerShockwave(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->shockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  sprite->pos = *pos;

  sprite->pos.x += POLAR_X(180, angle);
  sprite->pos.z += POLAR_Z(180, angle);

  p->shockwave.vel.x = 0;
  p->shockwave.vel.z = 0;
  AuxAnim_SetAnim(&p->shockwave.anim, p->shockwave.animFile, 2, 0, 0);
  PlayerLink_ShowShockwave(p);
}

// Player_ShowGunSpread の通信対戦版, サバタの散弾スプライトを pos の少し上に置き, wpn.timer の向きに回して表示する
void PlayerLink_ShowGunSpread(Player* p, s32 param_2, Vec3* pos) {
  p->shockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->shockwave.sprite.pos = *pos;
  p->shockwave.sprite.pos.y += 0xE6;
  p->shockwave.sprite.rotation = p->wpn.timer;
  p->shockwave.finished = 1;
}

void PlayerLink_RemoveShockwave(Player* p) { AuxSprite_Remove(&p->shockwave.sprite); }

// 衝撃波スプライトを用意する, サバタは散弾の1枚絵, それ以外はアニメーション付き
void PlayerLink_InitShockwave(Player* p) {
  AuxSprite* sprite = &p->shockwave.sprite;
  AuxSpriteGfx* gfx = &p->shockwave.gfx;

  if (p->kind == PLAYER_SABATA) {
    Video_GetAuxSprite(gfx, SPR_GUN_SPREAD);
    AuxSprite_Add(sprite, gfx, SPRFLAG_NO_CLIP | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
    sprite->poseIdx = 4;
    Video_SetAuxSpritePltt(gfx, 50);
    sprite->priority = 1;
    sprite->scaleY = 0x7F;
    sprite->scaleX = 0x7F;
    sprite->pos = p->mover.pos;
    p->shockwave.update = PlayerLink_UpdateShockwaveFlash;
  } else {
    Video_GetAuxSprite(gfx, SPR_MELEE_SHOCKWAVE);
    AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
    Video_SetAuxSpritePltt(gfx, OBP_RDJANGO);
    p->shockwave.animFile = GetFile(DIR_ANIMATION, ANIM_0837);
    p->shockwave.update = PlayerLink_UpdateShockwaveAnim;
  }

  p->shockwave.finished = FALSE;
}

// エンチャントの粒を1フレーム進める, 12フレームで消え 6フレーム目で小さいコマに変える
void PlayerLink_UpdateEnchantPtcls(Player* p) {
  s32 alive;
  s32 i;

  if (!p->enchantPtcls.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 6; i++) {
    EnchantPtcl* ptcl;
    Particle* base;

    if (!p->enchantPtcls.ptcls[i].active) {
      continue;
    }

    ptcl = &p->enchantPtcls.ptcls[i];
    base = &ptcl->base;
    if (++ptcl->timer > 11) {
      base->flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    if (ptcl->timer == 6) {
      Particle_SetPose(&ptcl->base, p->enchantPtcls.group2, ptcl->poseIdx + 1);
    }

    base->pos.x += ptcl->vel.x;
    base->pos.y += ptcl->vel.y;
    base->pos.z += ptcl->vel.z;
    alive++;
  }

  if (alive == 0) {
    p->enchantPtcls.active = FALSE;
  }
}

// エンチャントの粒を1つ使って pos / vel を入れて出す, 使う番号は 0..5 を巡回する
void PlayerLink_SpawnEnchantPtcl(Player* p, Vec3* pos, Vec3* vel, s32 element) {
  EnchantPtcl* ptcl = &p->enchantPtcls.ptcls[p->enchantPtcls.next];

  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = element * 2 + 2;
  Particle_SetPose(&ptcl->base, p->enchantPtcls.group2, ptcl->poseIdx);
  ptcl->base.pos = *pos;
  ptcl->vel = *vel;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->enchantPtcls.active = TRUE;
  p->enchantPtcls.next++;
  if (p->enchantPtcls.next > 5) {
    p->enchantPtcls.next = 0;
  }
}

void PlayerLink_RemoveEnchantPtcls(Player* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Particle_Remove(&p->enchantPtcls.ptcls[i].base);
  }
}

// player.c の Player_InitEnchantPtcls と同じ内容
void PlayerLink_InitEnchantPtcls(Player* p) {
  PlayerEnchantPtcls* st = &p->enchantPtcls;
  s32 i;

  st->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 6; i++) {
    EnchantPtcl* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->active = FALSE;
  st->next = 0;
}

// チャージの粒を chargePos へ寄せながら1フレーム進める, 寄り切ったものは消す
// 残差 149/150: Player_UpdateChargePtcls と同じく, 原典は要素の写し (&ptcl->base) を r5 に置くが, こちらはスタックへ逃がす
// 試済: base を宣言で初期化, 要素ごとの処理を inline に出す
NON_MATCH void PlayerLink_UpdateChargePtcls(Player* p) {
#ifdef NONMATCHING_C
  s32 alive;
  s32 i;

  if (!p->chargePtcls.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 4; i++) {
    ChargePtcl* ptcl = &p->chargePtcls.ptcls[i];
    Particle* base;
    s32 angle;

    if (!ptcl->active) {
      continue;
    }

    base = &ptcl->base;

    if (abs(ptcl->offset.x) <= 15 && abs(ptcl->offset.z) <= 15) {
      base->flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    angle = ArcTan2_8(ptcl->offset.x, ptcl->offset.z);

    ptcl->offset.x -= POLAR_X(ptcl->speed, angle);
    ptcl->offset.z -= POLAR_Z(ptcl->speed, angle);

    base->pos.x = ptcl->offset.x + p->chargePos.x;
    base->pos.z = ptcl->offset.z + p->chargePos.z;

    if (++ptcl->timer == 4) {
      Particle_SetPose(&ptcl->base, p->chargePtcls.group2, ptcl->poseIdx + 1);
    }

    alive++;
  }

  if (alive == 0) {
    p->chargePtcls.active = FALSE;
  }
#else
  INCFUNC("asm/func/PlayerLink_UpdateChargePtcls.inc");
#endif
}

// 自分の光ゲージ (luxGauge) のぶんカウンタを溜め, 0x27 を超えたら太陽チャージの粒を1つ出す
// 残差 162/167: Player_SpawnSolarChargePtcl と同じく原典は p を r7 / pos を r9 / 要素の写しを r8 に置く, 光ゲージの値も原典は r0 で作って r2 へ写す
// 試済: 光ゲージを読む inline (if/else の向き 2 通り), 足す順
NON_MATCH void PlayerLink_SpawnSolarChargePtcl(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  ChargePtcl* ptcl;
  Particle* base;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;
  u32 i = p->inputIdx;
  s32 lux;

  if (gLinkSession == NULL) {
    lux = 0;
  } else {
    lux = gLinkSession->luxGauge[i];
  }

  if ((p->chargePtcls.spawnTimer += lux + 2) <= 0x27) {
    return;
  }

  ptcl = &p->chargePtcls.ptcls[p->chargePtcls.next];
  base = &ptcl->base;
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = PTCL2_SOL_L;
  Particle_SetPose(&ptcl->base, p->chargePtcls.group2, PTCL2_SOL_L);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x3F) + 0x80;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  base->pos = *pos;
  base->pos.x += ptcl->offset.x;
  base->pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 3) + 0xE;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->chargePtcls.next++;
  if (p->chargePtcls.next > 3) {
    p->chargePtcls.next = 0;
  }

  p->chargePtcls.spawnTimer -= 0x28;
  p->chargePtcls.active = TRUE;
#else
  INCFUNC("asm/func/PlayerLink_SpawnSolarChargePtcl.inc");
#endif
}

// 4フレームごとに暗黒チャージの粒を1つ, pos からランダムな向き・距離だけ離して置く
// 残差 149/151: Player_SpawnDarkChargePtcl と同じく, 原典は p と pos を r8/r9 に置き要素の写しを r7 に作る
// 試済: base を pos を書く直前で取る (146 命令)
NON_MATCH void PlayerLink_SpawnDarkChargePtcl(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  ChargePtcl* ptcl;
  Particle* base;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;

  if ((++p->chargePtcls.spawnTimer & 3) != 0) {
    return;
  }

  ptcl = &p->chargePtcls.ptcls[p->chargePtcls.next];
  base = &ptcl->base;
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = PTCL2_DARK_L;
  Particle_SetPose(&ptcl->base, p->chargePtcls.group2, PTCL2_DARK_L);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x7F) + 0x100;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  base->pos = *pos;
  base->pos.x += ptcl->offset.x;
  base->pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 7) + 0x1C;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->chargePtcls.active = TRUE;
  p->chargePtcls.next++;
  if (p->chargePtcls.next > 3) {
    p->chargePtcls.next = 0;
  }
#else
  INCFUNC("asm/func/PlayerLink_SpawnDarkChargePtcl.inc");
#endif
}

void PlayerLink_RemoveChargePtcls(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->chargePtcls.ptcls[i].base);
  }
}

// player.c の Player_InitChargePtcls と同じ内容
void PlayerLink_InitChargePtcls(Player* p) {
  PlayerChargePtcls* st = &p->chargePtcls;
  s32 i;

  st->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    ChargePtcl* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->next = 0;
  st->spawnTimer = 0;
}

// 自前のパレット pltt を作る, plttBrightness のぶん全チャンネルを明るくし, useAuxSprite が 0 なら色5/6/13 は触らない (Player_BuildPltt と同じ)
// 命令数は一致 (154), 残差は i と src のレジスタ入れ替えと i = 0 の位置のみ
// 試済: Player_BuildPltt の添字版 (r9 を使い 159 命令), c ローカル無し, ポインタを本体末尾で進める形, dst を関数頭で1回だけ作る形
NON_MATCH void PlayerLink_BuildPltt(Player* p) {
#ifdef NONMATCHING_C
  rgb555* src = &gObjPlttData[p->plttIDs[p->plttIdx] * 16];
  rgb555* dst;
  s32 i;

  if (p->plttBrightness == 0) {
    if (p->useAuxSprite == 0) {
      dst = p->pltt;
      for (i = 0; i < 16; i++, src++, dst++) {
        if (i != 5 && i != 6 && i != 13) {
          *dst = *src;
        }
      }
    } else {
      dst = p->pltt;
      for (i = 0; i < 16; i++) {
        *dst++ = *src++;
      }
    }
  } else if (p->useAuxSprite == 0) {
    dst = p->pltt;
    for (i = 0; i < 16; i++, src++, dst++) {
      if (i != 5 && i != 6 && i != 13) {
        s32 r = (*src & 0x1F) + p->plttBrightness;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((*src >> 5) & 0x1F) + p->plttBrightness;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((*src >> 10) & 0x1F) + p->plttBrightness;
        if (b > 0x1F) {
          b = 0x1F;
        }
        *dst = (b << 10) | (g << 5) | r;
      }
    }
  } else {
    dst = p->pltt;
    for (i = 0; i < 16; i++, src++, dst++) {
      s32 r = (*src & 0x1F) + p->plttBrightness;
      s32 g;
      s32 b;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((*src >> 5) & 0x1F) + p->plttBrightness;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((*src >> 10) & 0x1F) + p->plttBrightness;
      if (b > 0x1F) {
        b = 0x1F;
      }
      *dst = (b << 10) | (g << 5) | r;
    }
  }
#else
  INCFUNC("asm/func/PlayerLink_BuildPltt.inc");
#endif
}

// 日光が当たっているとき, 屋外なら 8, 屋内なら 4 を返す
s32 PlayerLink_GetSunbathBrightness(Player* p) {
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

void PlayerLink_ApplyEnchantColors(Player* p) {
  rgb555* src = &gObjPlttData[40 * 16];

  src += p->enchantColorIdx * 3;

  p->pltt[5] = *src++;
  p->pltt[6] = src[0];
  p->pltt[13] = src[1];
}

// src と pltt を wSrc:wBase の比で混ぜて pltt[16..31] に作り, スプライトのパレットをそこへ向ける (Player_BlendPltt と同じ)
// 残差3命令 (228/225): 原典は src を r8 に置き i をスタックに逃がすが, こちらは逆, 2本目のループも原典は数え上げのまま (こちらは逆順に変わる)
// 効いた手: 素の成分を先に3つ取り出してから混ぜる, 結果を s32 c に入れて格納を共有, src++/base++ を本体末尾, 試済: 宣言順, c ローカル無しの *src
NON_MATCH void PlayerLink_BlendPltt(Player* p, u16* src, s32 wSrc, s32 wBase, u32 shift) {
#ifdef NONMATCHING_C
  rgb555* base;
  s32 c;
  s32 i;

  if (wSrc == 0) {
    if (p->useAuxSprite == 0) {
      p->human.pltt = p->pltt;
    } else {
      p->beastGfx->pltt = p->pltt;
    }
    return;
  }

  if (p->useAuxSprite == 0) {
    base = p->pltt;
    for (i = 0; i < 16; i++) {
      if (i == 5 || i == 6 || i == 13) {
        c = *base;
      } else {
        s32 r = (*src & 0x1F) + p->plttBrightness;
        s32 g;
        s32 b;
        s32 br;
        s32 bg;
        s32 bb;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((*src >> 5) & 0x1F) + p->plttBrightness;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((*src >> 10) & 0x1F) + p->plttBrightness;
        if (b > 0x1F) {
          b = 0x1F;
        }
        br = *base & 0x1F;
        bg = (*base >> 5) & 0x1F;
        bb = (*base >> 10) & 0x1F;
        r = (r * wSrc + br * wBase) >> shift;
        g = (g * wSrc + bg * wBase) >> shift;
        b = (b * wSrc + bb * wBase) >> shift;
        c = (b << 10) | (g << 5) | r;
      }
      base[16] = c;
      src++;
      base++;
    }
    p->human.pltt = &p->pltt[16];
  } else {
    base = p->pltt;
    for (i = 0; i < 16; i++) {
      s32 r = (*src & 0x1F) + p->plttBrightness;
      s32 g;
      s32 b;
      s32 br;
      s32 bg;
      s32 bb;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((*src >> 5) & 0x1F) + p->plttBrightness;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((*src >> 10) & 0x1F) + p->plttBrightness;
      if (b > 0x1F) {
        b = 0x1F;
      }
      br = *base & 0x1F;
      bg = (*base >> 5) & 0x1F;
      bb = (*base >> 10) & 0x1F;
      r = (r * wSrc + br * wBase) >> shift;
      g = (g * wSrc + bg * wBase) >> shift;
      b = (b * wSrc + bb * wBase) >> shift;
      c = (b << 10) | (g << 5) | r;
      base[16] = c;
      src++;
      base++;
    }
    p->beastGfx->pltt = &p->pltt[16];
  }
#else
  INCFUNC("asm/func/PlayerLink_BlendPltt.inc");
#endif
}

// 毎フレームのパレット更新, エンチャントの色と変身の色をクロスフェードさせる (Player_UpdatePltt と同じ)
// 残差 (260/255): 原典は p を r5, n と plttFlashTimer を r4 に置くがこちらは逆, ブロックの並びは plttFlashTimer == 0 を先に書くと原典に揃う
// 試済: Player_UpdatePltt の早期 return 形 (259 命令), 前方宣言の置き場所と有無 (ファイル頭/関数内/プロトタイプ無し), n を s32
NON_MATCH void PlayerLink_UpdatePltt(Player* p, u32 n) {
#ifdef NONMATCHING_C
  u32 bright;
  s32 w;
  rgb555* src;
  magic32_t mid;
  s32 i;

  if (p->nextEnchantColorIdx != p->enchantColorIdx) {
    p->enchantColorIdx = p->nextEnchantColorIdx;
    PlayerLink_ApplyEnchantColors(p);
  }

  bright = PlayerLink_GetSunbathBrightness(p);
  if (p->plttIdx != n || p->plttBrightness != bright) {
    p->plttIdx = n;
    p->plttBrightness = bright;
    PlayerLink_BuildPltt(p);
  }

  if (p->plttFlashTimer == 0) {
    mid = PlayerLink_CheckMagicEnchant(p);
    if (mid >= 0) {
      p->enchantPlttID = OBP_ELEMENT(mid);
      src = &gObjPlttData[p->enchantPlttID * 16];
      if (p->enchantPlttTimer <= 0x1F) {
        w = p->enchantPlttTimer;
      } else if (p->enchantPlttTimer <= 0x2F) {
        w = 0x20;
      } else if (p->enchantPlttTimer <= 0x4F) {
        w = 0x50 - p->enchantPlttTimer;
      } else {
        w = 0;
      }

      PlayerLink_BlendPltt(p, src, w, 0x20 - w, 5);
      p->enchantPlttTimer++;
      if (p->enchantPlttTimer > 0x5F) {
        p->enchantPlttTimer = 0;
      }
    } else if (p->enchantPlttTimer >= 1 && p->enchantPlttTimer <= 0x4F) {
      src = &gObjPlttData[p->enchantPlttID * 16];
      if (p->enchantPlttTimer >= 0x21 && p->enchantPlttTimer <= 0x2F) {
        p->enchantPlttTimer = 0x30;
      }

      if (p->enchantPlttTimer <= 0x20) {
        w = p->enchantPlttTimer;
        p->enchantPlttTimer = w - 1;
      } else {
        w = 0x50 - p->enchantPlttTimer;
        p->enchantPlttTimer++;
        if (p->enchantPlttTimer > 0x4F) {
          p->enchantPlttTimer = 0;
        }
      }

      PlayerLink_BlendPltt(p, src, w, 0x20 - w, 5);
    } else {
      p->enchantPlttID = 0;
      p->enchantPlttTimer = 0;
      if (p->useAuxSprite == 0) {
        p->human.pltt = p->pltt;
      } else {
        p->beastGfx->pltt = p->pltt;
      }
    }
  } else {
    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->flashPlttID * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt[16 + i] = p->pltt[i];
          } else {
            p->pltt[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt[16];
      }
    } else {
      src = &gObjPlttData[p->flashPlttID * 16];
      w = p->plttFlashTimer;
      PlayerLink_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->plttFlashTimer--;
  }
#else
  INCFUNC("asm/func/PlayerLink_UpdatePltt.inc");
#endif
}

// 通信対戦のプレイヤーのパレットID表を埋める, ベースカラーは inputIdx ごとに 34, 35
void PlayerLink_SetPlttIDs(Player* p) {
  p->plttIDs[0] = p->inputIdx + 34;
  p->plttIDs[1] = OBP_ELEMENT(0), p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
}

// スプライトのパレットを自前の pltt に差し替えて初期状態に戻す
void PlayerLink_ResetPltt(Player* p) {
  PlayerLink_SetPlttIDs(p);
  p->plttIdx = 0xFFFF;
  p->enchantColorIdx = 0xFF;
  p->human.plttID = p->plttIDs[0];
  p->human.pltt = p->pltt;
  p->beastGfx->plttID = p->plttIDs[0];
  p->beastGfx->pltt = p->pltt;
  PlayerLink_UpdatePltt(p, 0);
}

// 状態異常の粒をひとつ弾けさせて1段階解く, 引火なら消えかけさせるだけ
// 残差2命令 (136/134), Player_BurstElementalCond と同じく原典は高位レジスタを r8-r10 の3本使う (0xF と &gRandTableIdx を高位に置く)
// 試済: 表を直接添字で引く, idx を s32, src ローカル無し, 宣言順, 表と添字の文の順
NON_MATCH void PlayerLink_BurstElementalCond(Player* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3 vel;
  Vec3 velRange;
  Vec3* src;
  u16* table;
  u32 idx;

  if (p->emitter.kind == ELEMCOND_INKA) {
    ElementalCondEmitter_FadeParticle(&p->emitter);
    return;
  }

  if (p->emitter.kind == ELEMCOND_HYOKETU) {
    Sound_PlayForPlayer(p->inputIdx, SE_END_SOLIDIFY);
  } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
    Sound_PlayForPlayer(p->inputIdx, SE_END_SOLIDIFY);
  }

  src = p->emitter.pos;
  pos.x = src->x;
  pos.y = src->y + 0x80;
  pos.z = src->z;

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  vel.x = (table[idx] & 0xF) - 7;
  idx = (idx + 1) & 0x3FF;
  vel.y = (table[idx] & 0x1F) - 0x10;
  gRandTableIdx = (idx + 1) & 0x3FF;
  vel.z = (table[gRandTableIdx] & 0xF) - 7;

  velRange.x = 5, velRange.y = 0xA, velRange.z = 5;
  ElementalCondEmitter_BurstParticle(&p->emitter, 3, &pos, &vel, &velRange, 0x28, 0x28);
#else
  INCFUNC("asm/func/PlayerLink_BurstElementalCond.inc");
#endif
}

void PlayerLink_ClearElementalCond(Player* p) {
  u8 n = p->emitter.aliveCount;

  if (n != 0) {
    s32 i = n;

    do {
      PlayerLink_BurstElementalCond(p);
      i--;
    } while (i != 0);
  }
}

s32 PlayerLink_GetMashCount(Player* p) { return (p->mashCount - p->mashCountBase + 0x100) & 0xFF; }

// 姿勢を決める, 変化直後は 64 フレームのあいだ 4フレームおきに前の値と交互に返す (Player_ApplyPoseHold から行動中の判定と鈍足を除いたもの)
u32 PlayerLink_ApplyPoseHold(Player* p, u32 n) {
  u32 pose = n;

  if (p->emitter.aliveCount != 0) {
    if (PlayerLink_GetMashCount(p) >= u8_ARRAY_085ad148[p->emitter.kind - 1]) {
      PlayerLink_BurstElementalCond(p);
      p->mashCountBase = p->mashCount;
    }

    if (p->emitter.aliveCount != 0) {
      if (p->emitter.kind == ELEMCOND_INKA) {
        pose = 3;
      } else if (p->emitter.kind == ELEMCOND_HYOKETU) {
        pose = 4;
      } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
        pose = 5;
      }
    }
  }

  if (pose == n) {
    if (p->altPoseTimer != 0) {
      if ((p->altPoseTimer >> 2) & 1) {
        pose = p->altPose;
      }
      p->altPoseTimer--;
    }
  } else {
    p->altPose = pose;
    p->altPoseTimer = 64;
  }

  return pose;
}

// 状態異常の残り時間を1フレーム進め, 毒なら姿勢番号を 2 で上書きして返す, 腹痛のモザイクは自分の画面のプレイヤーだけ (Player_TickBadCondTimers からカーモスの日光吸収を除いたもの)
u32 PlayerLink_TickBadCondTimers(Player* p, u32 n) {
  s32 i;

  for (i = 0; i < 3; i++) {
    switch (i) {
      case BAD_POISON: {
        if (p->badCondTimer[BAD_POISON] != 0) {
          if (p->mode & PMODE_ACTIVE) {
            p->badCondTimer[BAD_POISON]--;
          }
          n = 2;
          p->badCondBlinkTimer = 64;
        } else if (p->badCondBlinkTimer != 0) {
          if ((p->badCondBlinkTimer >> 2) & 1) {
            n = 2;
          }
          p->badCondBlinkTimer--;
        }
        break;
      }
      case BAD_HARAITA: {
        if (p->badCondTimer[BAD_HARAITA] != 0 && (p->mode & PMODE_ACTIVE)) {
          p->badCondTimer[BAD_HARAITA]--;
          if (p->inputIdx == LinkSession_GetPlayerIdx() && (p->input->down & DPAD_ANY)) {
            MosaicFader_Start(2, 1, 0x1E, p->mosaicFrom, p->mosaicTo, p->mosaicInterval);
          }
        }
        break;
      }
      case BAD_CONFUSE: {
        if (p->badCondTimer[BAD_CONFUSE] != 0 && (p->mode & PMODE_ACTIVE)) {
          p->badCondTimer[BAD_CONFUSE]--;
          if (p->badCondTimer[BAD_CONFUSE] == 0) {
            p->controlUp = p->linkRecord->controlUp;
          }
        }
        break;
      }
    }
  }

  return n;
}

// flashTimer が動いている間, 4フレームごとに pose を flashPose と入れ替える (点滅)
s32 PlayerLink_ApplyFlashPose(Player* p, s32 pose) {
  if (p->flashTimer == 0) {
    return pose;
  } else if ((--p->flashTimer >> 2) & 1) {
    return p->flashPose;
  } else {
    return pose;
  }
}

// 小人の縮みと透明化の表示を進める, 透明は自分の画面か千里眼の実を持つ相手には点滅で見せ, それ以外の相手からは隠す (Player_UpdateFormScale の通信版)
void PlayerLink_UpdateFormScale(Player* p) {
  s32 scale;

  if (p->goodCondTimer != 0) {
    if (p->goodCondID == GOOD_MINI) {
      if (p->shrink <= 0x3F) {
        if (p->shrink == 0) {
          Sound_PlayForPlayer(p->inputIdx, SE_PLAYER_SHRINK);
          p->isMiniHuman = TRUE;
        }
        p->shrink++;
      }

      p->human.flags |= SPRFLAG_AFFINE;
      scale = 0x40 - (p->shrink >> 1);
      p->human.scaleX = scale;
      p->human.scaleY = scale;
      Player_SetFlag20(p, PFLAG20_SNEAKING | PFLAG20_UNK_18);
    } else if (p->shrink != 0) {
      if (p->isMiniHuman) {
        Sound_PlayForPlayer(p->inputIdx, SE_PLAYER_SHRINK_END);
        p->isMiniHuman = FALSE;
      }

      p->shrink--;
      if (p->shrink == 0) {
        p->human.flags &= ~SPRFLAG_AFFINE;
        p->human.scaleX = Q6(1);
        p->human.scaleY = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->shrink >> 1);
        p->human.scaleX = scale;
        p->human.scaleY = scale;
      }
    }

    if (p->goodCondID == GOOD_INVISIBLE) {
      s32 idx = LinkSession_GetPlayerIdx();

      if (p->inputIdx == idx) {
        p->beast.flags |= SPRFLAG_BLINK_ODD;
        p->human.flags |= SPRFLAG_BLINK_ODD;
      } else if (HasGoodCond(gPlayerPtr[idx], GOOD_SEE)) {
        p->beast.flags |= SPRFLAG_BLINK_ODD;
        p->human.flags |= SPRFLAG_BLINK_ODD;
      } else {
        p->beast.flags |= SPRFLAG_HIDDEN;
        p->human.flags |= SPRFLAG_HIDDEN;
      }
      Player_SetFlag20(p, PFLAG20_INVISIBLE);
    } else {
      p->beast.flags &= ~SPRFLAG_BLINK_ODD;
      p->human.flags &= ~SPRFLAG_BLINK_ODD;
    }

    if (p->mode & PMODE_ACTIVE) {
      p->goodCondTimer--;
    }
  } else {
    if (p->shrink != 0) {
      if (p->isMiniHuman) {
        Sound_PlayForPlayer(p->inputIdx, SE_PLAYER_SHRINK_END);
        p->isMiniHuman = FALSE;
      }

      p->shrink--;
      if (p->shrink == 0) {
        p->human.flags &= ~SPRFLAG_AFFINE;
        p->human.scaleX = Q6(1);
        p->human.scaleY = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->shrink >> 1);
        p->human.scaleX = scale;
        p->human.scaleY = scale;
      }
    }

    if (p->human.flags & SPRFLAG_BLINK_ODD) {
      p->human.flags &= ~SPRFLAG_BLINK_ODD;
    }
    if (p->beast.flags & SPRFLAG_BLINK_ODD) {
      p->beast.flags &= ~SPRFLAG_BLINK_ODD;
    }
  }
}

// 方向キーが押された最初のフレームだけ mashCount を1つ進める
void PlayerLink_CountMash(Player* p) {
  if (p->input->pressed & DPAD_ANY) {
    p->mashCount++;
  }
}

NAKED void FUN_080ce28c(Player* p) { INCFUNC("asm/func/FUN_080ce28c.inc"); }

void FUN_080ce330(Player* p) {
  ElementalCondEmitter_Destroy(&p->emitter);
  ParticleShadow_Remove(&p->shadow);
  Particle_Remove(&p->noise.ptcl);
  Particle_Remove(&p->spurl.ptcl);
  PlayerLink_RemoveEnchantPtcls(p);
  PlayerLink_RemoveChargePtcls(p);
  PlayerLink_RemoveShockwave(p);
}

// 状態異常の粒・影・パレット・各種パーティクル・衝撃波を用意し, 風とライジングサンの状態を戻す (Player_InitEffects の通信版)
void PlayerLink_InitEffects(Player* p) {
  ElementalCondEmitter_Init(&p->emitter, &p->human.pos, ELEMCOND_NONE, 0, 1);

  p->shadowPos = p->human.pos;
  p->shadowOffset.x = 0, p->shadowOffset.y = 0, p->shadowOffset.z = 0;
  ParticleShadow_Init(&p->shadow, &p->shadowPos, 0);
  BloodEmitter_Create();

  PlayerLink_ResetPltt(p);
  PlayerLink_InitNoisePtcl(p);
  PlayerLink_InitConfusePtcl(p);
  PlayerLink_InitEnchantPtcls(p);
  PlayerLink_InitChargePtcls(p);
  PlayerLink_InitShockwave(p);

  p->mosaicFrom[0] = 4;
  p->mosaicFrom[1] = 4;
  p->mosaicFrom[2] = 4;
  p->mosaicFrom[3] = 4;
  p->mosaicTo[0] = 0;
  p->mosaicTo[1] = 0;
  p->mosaicTo[2] = 0;
  p->mosaicTo[3] = 0;
  p->mosaicInterval[0] = 4;
  p->mosaicInterval[1] = 4;
  p->mosaicInterval[2] = 4;
  p->mosaicInterval[3] = 4;
  if (p->inputIdx == LinkSession_GetPlayerIdx()) {
    p->unk_978 = 0;
  } else {
    p->unk_978 = 1;
  }
  p->damageNumOffset.x = 0;
  p->damageNumOffset.y = 0;
  p->damageNumOffset.z = 0;
  gWindStrength = 0;
  gWindAngle = 0;
  gWindPushThreshold = 1;
  gRisingSunCount = 0;
  p->spiderWebIdx = 0xFF;
}

u32 PlayerLink_WeaponEffectSol(Player* p) {
  u32 i = p->inputIdx;

  if (gLinkSession != NULL) {
    return gLinkSession->luxGauge[i];
  }
  return 0;
}

u32 PlayerLink_WeaponEffectNight(Player* p) {
  if (PlayerLink_IsNight() != 0) {
    return 10;
  }
  return 0;
}

// 相手が魔物なら 10, そうでなければ 0
u32 PlayerLink_WeaponEffectKillCount(Player* p, Hitbox* _, Hitbox* b) {
  if (Hitbox_TestAttr(b, HBATTR_BEAST) || Hitbox_TestAttr(b, HBATTR_THING) || Hitbox_TestAttr(b, HBATTR_PHANTOM) || Hitbox_TestAttr(b, HBATTR_UNDEAD) || Hitbox_TestAttr(b, HBATTR_IMMORTAL)) {
    return 10;
  }
  return 0;
}

// 通信対戦で敵を倒したとき, playerMask の一番下のビットのプレイヤーが剣/槍/ハンマーで倒していればブラッドソードの状態を作り直す (Player_AddWeaponExp の通信版, 経験値は入れない)
void PlayerLink_UpdateBloodSwordOnKill(u32 playerMask, u32 weaponMask) {
  s32 idx;
  Player* player;

  if (playerMask & 1) {
    idx = 0;
  } else if (playerMask & 2) {
    idx = 1;
  } else if (playerMask & 4) {
    idx = 2;
  } else if (playerMask & 8) {
    idx = 3;
  } else {
    return;
  }

  if (weaponMask & ((1 << WK_SWORD) | (1 << WK_SPEAR) | (1 << WK_HAMMER))) {
    player = gPlayerPtr[idx];
    if (player != NULL && player->mode == PMODE_ACTIVE) {
      Player_UpdateBloodSword(player);
    }
  }
}

// 武器の特殊効果をコールバックと装備バフに展開する (Player_EnableWeaponSpecialEffects の通信版, アストロ武器は効かず, 耐久と ENE 消費の軽減はバフを落とす)
// 残差1命令 (196/196): 原典は w + i * 4 の順に足すが, こちらは i * 4 + w になる
// 試済: WeaponData* と *(u8*)&w->effects[i] / (u8)w->effects[i], LinkTradeWeapon* と w->effects[i][0] (w + 0x18 が巻き上がる) / *w->effects[i] / 要素のポインタのローカル
NON_MATCH void PlayerLink_EnableWeaponSpecialEffects(Player* p, LinkTradeWeapon* w) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    p->weaponExDamageCb[i] = NULL;
    p->weaponEffectCb2[i] = NULL;
    p->weaponEffectCb3[i] = NULL;
  }
  Player_ClearEquipBuff(p, EBUFF_WET_DURABILITY | EBUFF_WET_ENE_COST | EBUFF_BLOOD_SWORD | EBUFF_ASTRO);

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    switch (*w->effects[i]) {
      case WET_GUN_DEL_SOL:
      case WET_SOL: {
        p->weaponExDamageCb[i] = PlayerLink_WeaponEffectSol;
        break;
      }
      case WET_STATCOND: {
        p->weaponExDamageCb[i] = Player_WeaponEffectStatCond;
        break;
      }
      case WET_GUN_DEL_HELL:
      case WET_NIGHT: {
        p->weaponExDamageCb[i] = PlayerLink_WeaponEffectNight;
        break;
      }
      case WET_AGILITY: {
        p->weaponExDamageCb[i] = Player_WeaponEffectAgility;
        break;
      }
      case WET_VITALITY: {
        p->weaponExDamageCb[i] = Player_WeaponEffectVitality;
        break;
      }
      case WET_SPIRIT: {
        p->weaponExDamageCb[i] = Player_WeaponEffectSpirit;
        break;
      }
      case WET_ENE: {
        p->weaponExDamageCb[i] = Player_WeaponEffectENE;
        break;
      }
      case WET_HP: {
        p->weaponExDamageCb[i] = Player_WeaponEffectHP;
        break;
      }
      case WET_KAJIBA: {
        p->weaponExDamageCb[i] = Player_WeaponEffectKajiba;
        break;
      }
      case WET_GYAKU_KAJIBA: {
        p->weaponExDamageCb[i] = Player_WeaponEffectGyakuKajiba;
        break;
      }
      case WET_KILLCOUNT: {
        p->weaponEffectCb3[i] = PlayerLink_WeaponEffectKillCount;
        break;
      }
      case WET_RANDOM: {
        p->weaponEffectCb3[i] = Player_WeaponEffectRandom;
        break;
      }
      case WET_ANTI_BEAST: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiBeast;
        break;
      }
      case WET_ANTI_THING: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiThing;
        break;
      }
      case WET_ANTI_PHANTOM: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiPhantom;
        break;
      }
      case WET_ANTI_UNDEAD: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiUndead;
        break;
      }
      case WET_ANTI_IMMORTAL: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiImmortal;
        break;
      }
      case WET_FLAME: {
        p->weaponEffectCb3[i] = Player_WeaponEffectFlame;
        break;
      }
      case WET_FROST: {
        p->weaponEffectCb3[i] = Player_WeaponEffectFrost;
        break;
      }
      case WET_CLOUD: {
        p->weaponEffectCb3[i] = Player_WeaponEffectCloud;
        break;
      }
      case WET_EARTH: {
        p->weaponEffectCb3[i] = Player_WeaponEffectEarth;
        break;
      }
      case WET_NAMAKURA: {
        p->weaponEffectCb2[i] = CheckNamakuraProc;
        break;
      }
      case WET_STUN: {
        p->weaponEffectCb2[i] = CheckStunProc;
        break;
      }
      case WET_DURABILITY: {
        Player_ClearEquipBuff(p, EBUFF_WET_DURABILITY);
        break;
      }
      case WET_ENE_COST: {
        Player_ClearEquipBuff(p, EBUFF_WET_ENE_COST);
        break;
      }
      case WET_BLOOD_SWORD: {
        Player_SetEquipBuff(p, EBUFF_BLOOD_SWORD);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/PlayerLink_EnableWeaponSpecialEffects.inc");
#endif
}

NAKED void FUN_080ce868(Player* p) { INCFUNC("asm/func/FUN_080ce868.inc"); }

NAKED s32 FUN_080ceaa4(Player* p, LinkTradeWeapon* w) { INCFUNC("asm/func/FUN_080ceaa4.inc"); }

NAKED void player_weapon_080ceafc(Player* p, LinkTradeWeapon* w) { INCFUNC("asm/func/player_weapon_080ceafc.inc"); }

s32 GetMagicCost(s32 magic) { return gMagicCosts_085ad160[magic]; }

// 装備魔法の消費MP, WET_ENE_COST の武器を持っていると 8 割になる
s32 PlayerLink_CalcMagicCost(Player* p) {
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

// 装備魔法の消費 ENE を払えるか
s32 PlayerLink_CheckMagicCost(Player* p) {
  s32 cost = PlayerLink_CalcMagicCost(p);

  if (p->ene >= cost) {
    return 1;
  }
  return 0;
}

// 装備魔法の消費 ENE を払い, 払った分を通信対戦の ENE 使用量に足す
void PlayerLink_PayMagicCost(Player* p) {
  s32 cost = PlayerLink_CalcMagicCost(p);

  if (p->ene < cost) {
    if (gLinkSession != NULL) {
      gLinkSession->eneSpent += p->ene;
    }
    p->ene = 0;
  } else {
    if (gLinkSession != NULL) {
      gLinkSession->eneSpent += cost;
    }
    p->ene -= cost;
  }
}

// 今の姿で魔法 id を使えるか (Player_IsMagicAvailableForm の通信版), ジャンゴで系統が LUNA/SOL/DARK 以外のときは return を通らず GetMagicCategory の値がそのまま返る
bool32 PlayerLink_IsMagicAvailableForm(Player* p, magic32_t id) {
  s32 cat;

  if (id < 0) {
    return FALSE;
  }

  cat = GetMagicCategory(id);
  if (p->kind == PLAYER_RDJANGO) {
    if (cat == MC_LUNA) {
      if (id == MAGIC_DARK) {
        return FALSE;
      }
      return TRUE;
    } else if (cat == MC_SOL) {
      return TRUE;
    } else if (cat == MC_DARK) {
      return FALSE;
    }
  } else if (p->kind == PLAYER_BDJANGO) {
    if (cat == MC_LUNA) {
      if (id == MAGIC_SOL || id == MAGIC_FLAME || id == MAGIC_FROST || id == MAGIC_CLOUD || id == MAGIC_EARTH) {
        return FALSE;
      }
      return TRUE;
    } else if (cat == MC_SOL) {
      return FALSE;
    } else if (cat == MC_DARK) {
      if (id == MAGIC_SLEEPING) {
        if (gStat->coffin >= 0) {
          return FALSE;
        }
        return TRUE;
      }
      return TRUE;
    }
  } else if (p->kind == PLAYER_SABATA) {
    return TRUE;
  } else if (p->kind == PLAYER_MOUSE) {
    if (id == MAGIC_RAT) {
      return TRUE;
    }
    return FALSE;
  } else {
    return FALSE;
  }
}

// エンチャント中かつ近接武器を持っているときだけ魔法IDを返す, それ以外は -1
s32 PlayerLink_CheckMagicEnchant(Player* p) {
  if (!p->magic.enchanted) {
    return -1;
  }
  if (p->magic.id > 5) {
    return -1;
  }
  if (!PlayerLink_CheckMagicCost(p)) {
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

s32 PlayerLink_HasEnoughLux(Player* p, s32 param_2) {
  u32 i = p->inputIdx;
  s32 v;

  if (gLinkSession == NULL) {
    v = 0;
  } else {
    v = gLinkSession->luxGauge[i];
  }

  if (v < param_2) {
    return 0;
  }
  return 1;
}

// L で装備魔法を使ったときの行動を返す, エンチャントは切り替えるだけ, C マウス・ゼロシフト・ダッシュ・ダイナマイトだけが行動になる (Player_GetMagicAction の通信版)
// 残差 138/136: 原典は p->action を返す箇所ごとに読み直して別々に終わりへ飛ぶ, こちらは1か所にまとまる, id < 0 の枝も原典は直後に置く
// 試済: 早期 return の並び (137 命令, 返す塊が1つに畳まれる), player.c と同じ入れ子, 戻り値の変数1つに集める (s32 / u32), p->action を直接比べる
NON_MATCH s32 PlayerLink_GetMagicAction(Player* p) {
#ifdef NONMATCHING_C
  PlayerMagic* m = &p->magic;
  magic32_t id = m->id;
  s32 action;

  if (id < 0) {
    action = p->action;
  } else if (!m->availableForm) {
    action = p->action;
  } else if (id <= MAGIC_EARTH) {
    if (m->enchanted) {
      m->enchanted = FALSE;
      p->nextEnchantColorIdx = 0;
    } else {
      m->enchanted = TRUE;
      if (PlayerLink_CheckMagicEnchant(p) >= 0) {
        p->enchantStarted = 1;
        p->enchantPlttTimer = 0x20;
        p->nextEnchantColorIdx = m->id + 1;
      }
    }
    action = p->action;
  } else if (id == MAGIC_RAT) {
    action = p->action;
    if (action <= PACT_WALK) {
      if (p->kind != PLAYER_MOUSE) {
        if (!PlayerLink_CheckMagicCost(p)) {
          return p->action;
        }
        p->beastGfx = &p->beastGfxs[1];
        AuxSprite_SetGfx(&p->beast, p->beastGfx);
        AuxAnim_RestartAnim(&p->beastAnim, p->mouseAnim, 0, 0, 0);
        p->beast.flags = 0;
        PlayerLink_PayMagicCost(p);
      }
      action = PACT_CMOUSE;
    }
  } else {
    action = p->action;
    if (action <= PACT_WALK) {
      if (id == MAGIC_ZERO_SHIFT) {
        if (!PlayerLink_CheckMagicCost(p)) {
          return p->action;
        }
        PlayerLink_PayMagicCost(p);
        action = PACT_DASH;
      } else if (id == MAGIC_DASH) {
        action = PACT_DASH;
      } else if (id == MAGIC_DYNAMITE && p->dynamiteCount == 0) {
        action = PACT_DYNAMITE;
      } else {
        action = p->action;
      }
    }
  }
  return action;
#else
  INCFUNC("asm/func/PlayerLink_GetMagicAction.inc");
#endif
}

// 通信相手の記録から装備魔法の情報を作り直す
void PlayerLink_RefreshMagicInfo(Player* p) {
  PlayerMagic* m = &p->magic;

  m->id = p->linkRecord->unk_40[2];
  if (m->id < 0) {
    m->cat = 0xFF;
    m->basicCost = 0;
    m->availableForm = FALSE;
    m->enchanted = FALSE;
    return;
  }

  m->cat = GetMagicCategory(m->id);
  m->basicCost = GetMagicCost(m->id);
  m->availableForm = PlayerLink_IsMagicAvailableForm(p, m->id);
  m->enchanted = FALSE;
}

void FUN_080cef14(Player* p) {
  s32 val = VM_SeekToNamedArg('i');

  if (val != 0) {
    val = VM_GetValue();
  }
  p->inputIdx = val;
}

LinkPlayerRecord* FUN_080cef30(Player* p) {
  s32 i = p->inputIdx;

  if (gLinkSession == NULL || i < 0) {
    return NULL;
  }
  return &gLinkSession->records[i];
}

NAKED s32 FUN_080cef5c(Player* p) { INCFUNC("asm/func/FUN_080cef5c.inc"); }

// 通信相手の記録からステータス4種を引き直す
void FUN_080cefcc(Player* p) {
  s32 strength;
  s32 vitality;
  s32 spirit;
  s32 agility;

  FUN_081dfa20(p->linkRecord->unk_40[1], &strength, &vitality, &spirit, &agility);
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
  p->controlUp = p->linkRecord->controlUp;

  for (i = 0; i < 10; i++) {
    p->facingHistory[i] |= 0xFFFF;
  }
}

NAKED s32 FUN_080cf0b4(Player* p) { INCFUNC("asm/func/FUN_080cf0b4.inc"); }

// 人の姿のスプライトを用意し, スクリプトの '.d' の向きで立たせる
void PlayerLink_InitSprite(Player* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPR_DJANGO_SABATA);

  if (f != NULL) {
    p->humanGfx = *(MainSpriteGfx*)f;
    OpenMainSpriteFile(&p->humanGfx, f);
    MainSprite_Add(&p->human, &p->humanGfx, 0, SPRFLAG_UNK_15 | SPRFLAG_GAMEOVER, 2, PLAYMODE_PAUSE, 60, &p->mover.pos);

    if (VM_SeekToNamedArg('d')) {
      p->initFacing = VM_GetValue();
    } else {
      p->initFacing = DIR8_UP;
    }
    p->facing = p->initFacing;
    PlayerLink_SetAnimFacing(p);

    p->animID = 0;
    MainSprite_SetAnim(&p->human, &p->humanGfx, p->animDir, PLAYMODE_LOOP, 0);
    if (p->xflip) {
      p->human.flags |= SPRFLAG_XFLIP;
    } else {
      p->human.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

// マウスのスプライトとアニメを読み込んで beast に出し, 最初のコマを当てる (Player_InitBeastSprite のマウスだけの版)
void PlayerLink_InitBeastSprite(Player* p) {
  AuxSprite* sprite;
  AuxAnimState* anim;
  AuxAnimFile* file;
  u32 animIdx;

  Video_GetAuxSprite(&p->beastGfxs[1], SPR_MOUSE);
  file = GetFile(DIR_ANIMATION, ANIM_MOUSE);
  p->mouseAnim = file;

  sprite = &p->beast;
  p->beastGfx = &p->beastGfxs[1];
  animIdx = 0;

  AuxSprite_Add(sprite, p->beastGfx, SPRFLAG_GAMEOVER | SPRFLAG_HIDDEN);
  p->beast.pos.x = p->mover.pos.x;
  p->beast.pos.y = p->mover.pos.y;
  p->beast.pos.z = p->mover.pos.z;
  p->floatHeight = 0;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, file, animIdx, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(sprite, anim);
}

// スクリプトの '.p' の位置 (initPos) に mover を置き, スプライト・タイル・当たり範囲・ターゲットを登録する
bool32 PlayerLink_InitMover(Player* p, u32 moverID) {
  Vec3 offset;
  Mover* mover;
  bool32 result;

  if (VM_SeekToNamedArg('p')) {
    p->initPos.x = VM_GetValue();
    p->initPos.y = VM_GetValue();
    p->initPos.z = VM_GetValue();
  } else {
    p->initPos.x = 0;
    p->initPos.y = 0;
    p->initPos.z = 0;
  }
  p->initPos.y = TileHeightAt(&p->initPos);
  Mover_Init(&p->mover, moverID, &p->initPos, 0, (u8)p->inputIdx, p);

  PlayerLink_InitSprite(p);
  PlayerLink_InitBeastSprite(p);
  mover = &p->mover;
  p->useAuxSprite = FALSE;
  Mover_SetMainSprite(mover, &p->human);
  Map_InitMoverTile(&p->tile, &p->initPos);
  Mover_SetCollision(mover, &p->tile, 30, 30);
  offset.x = 0, offset.y = 300, offset.z = 0;
  FUN_0823b47c(mover, &offset);
  p->zoneEvents.id = p->mover.id;
  result = EnemyTargetManager_Add(&p->target, mover, 2);
  gPlayerMoverIDs[p->inputIdx] = p->mover.id;
  return result;
}

void FUN_080cf54c(Player* p) { player_weapon_080ceafc(p, &p->linkRecord->body); }

// 本体の当たり判定を組み立てる, 赤ジャンゴは属性がソル・弱点がダークで、それ以外は逆になる, 通信対戦では HBF_NPC を付けない
void PlayerLink_SetupHurtbox(Player* p) {
  Hitbox* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.196), Q8(0.497), Q8(0.196));
  VEC3_SET(offset, 0, Q8(0.497), 0);
  Hitbox_Init(hurtbox, p->mover.id, HBF_HURTBOX | HBF_DAMAGE, 0, 1 << p->inputIdx, &halfSize, &offset);
  if (p->kind == PLAYER_RDJANGO) {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_SOL, HBATTR_DARK);
  } else {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_DARK, HBATTR_SOL);
  }
  Hitbox_SetHandler(hurtbox, PlayerLink_OnHurt, p);
  Hitbox_SetPos(hurtbox, &p->beast.pos, 0);
  Hitbox_Register(hurtbox);
}

NAKED void FUN_080cf610(Player* p) { INCFUNC("asm/func/FUN_080cf610.inc"); }

// 煙を出してダメージを1増やす (Player_StepRainDamage の15フレームごとの中身と同じ)
void PlayerLink_EmitDamageSmoke(Player* p) {
  Vec3 size;
  WorldPos pos;

  if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
    pos = p->beast.pos;
    size.x = Q8(0.125), size.y = Q8(0.125), size.z = Q8(0.125);
  } else {
    pos = p->mover.pos;
    pos.y += Q8(0.313);
    size.x = Q8(0.25), size.y = Q8(0.235), size.z = Q8(0.25);
  }
  EmitSmoke(&pos, 1, &size, 0, 0, 12, 2, 2);
  p->damage++;
}

// 見回しのオフセットを, y の半分を引いた x / z が |z - x| <= 800 かつ |z + x| <= 800 のひし形に収まるよう押し戻す
// 残差はレジスタ割当のみ (84/84, 3 hunk), 原典は half を r2 に置き x / z を一時レジスタに読んでから引くが, こちらは half が r0 で x / z へ直接読む
// 試済: Player_ClampLookAround の形 (7 hunk), half ローカル無し, 初期化子つき宣言, half を文で代入, 宣言順
NON_MATCH void PlayerLink_ClampLookAround(Player* p) {
#ifdef NONMATCHING_C
  s32 x, z, d, delta;
  s32 half = p->lookAroundOffset.y >> 1;

  x = p->lookAroundOffset.x;
  x -= half;
  z = p->lookAroundOffset.z;
  z -= half;
  d = z - x;

  if (d > 800) {
    delta = (d - 800) >> 1;
    p->lookAroundOffset.x += delta;
    p->lookAroundOffset.z -= delta;
  } else if (d < -800) {
    delta = (-800 - d) >> 1;
    p->lookAroundOffset.x -= delta;
    p->lookAroundOffset.z += delta;
  }
  d = z + x;
  if (d > 800) {
    delta = (d - 800) >> 1;
    p->lookAroundOffset.x -= delta;
    p->lookAroundOffset.z -= delta;
  }
  if (d < -800) {
    delta = (-800 - d) >> 1;
    p->lookAroundOffset.x += delta;
    p->lookAroundOffset.z += delta;
  }
#else
  INCFUNC("asm/func/PlayerLink_ClampLookAround.inc");
#endif
}

// 見回し中の毎フレーム処理, 始めたときは注視点を頭上に置き直し, 入力方向ぶんオフセットをずらして押し戻し, unk_3d1 が立っていればオフセットの向きを向く
void PlayerLink_UpdateLookAround(Player* p) {
  if (p->lookAroundOffset.val == 0) {
    p->cameraLookAt.x = p->mover.pos.x;
    p->cameraLookAt.y = p->mover.pos.y + 150;
    p->cameraLookAt.z = p->mover.pos.z;
    p->lookAroundOffset.x = 0;
    p->lookAroundOffset.y = 0;
    p->lookAroundOffset.z = 0;
    p->lookAroundOffset.val = 1;
    PlayerLink_ClampLookAround(p);
  }

  if ((s16)p->facingHistory[0] != -1) {
    s32 angle = (((s16)p->facingHistory[0] + 1) & 7) * 32;

    p->lookAroundOffset.x -= POLAR_X(30, angle);
    p->lookAroundOffset.z -= POLAR_Z(30, angle);
    PlayerLink_ClampLookAround(p);
  }

  if (p->lookAroundOffset.x != 0 || p->lookAroundOffset.z != 0) {
    if (p->unk_3d1 != 0) {
      u16 angle = ArcTan2_8(p->lookAroundOffset.x, p->lookAroundOffset.z);
      p->facing = Angle_ToDir8(angle);
      PLAYER_SET_ANIM_8DIR(p, p->facing);
    }
  }
}

// 見回しモードを始める, 注視点をプレイヤーの頭上に置き直し, 注視点からプレイヤーへのオフセットを actionDir の向きの反対側に取る
void PlayerLink_StartLookAround(Player* p) {
  if (p->lookAroundOffset.val == 0) {
    s32 angle;

    p->cameraLookAt.x = p->mover.pos.x;
    p->cameraLookAt.y = p->mover.pos.y + 150;
    p->cameraLookAt.z = p->mover.pos.z;
    angle = ((p->actionDir + 1) & 7) * 32;

    p->lookAroundOffset.x = -POLAR_X(800, angle);
    p->lookAroundOffset.y = 0;
    p->lookAroundOffset.z = -POLAR_Z(800, angle);
    p->lookAroundOffset.val = 1;
  }
}

// 見回しモードを終了する, 自分の画面のプレイヤーならカメラも戻す
void PlayerLink_EndLookAround(Player* p) {
  if (p->inputIdx == LinkSession_GetPlayerIdx()) {
    Camera_ReleaseLook(8);
  }
  p->lookAroundOffset.val = 0;
}

// 種別と param_2 の組み合わせが許されているか
s32 PlayerLink_CanLookAround(Player* p, s32 param_2) {
  if (p->kind <= PLAYER_BDJANGO || p->kind == PLAYER_SABATA) {
    if (param_2 == 0 || param_2 == 3 || param_2 == 6) {
      return 1;
    }
    if (param_2 == 4 && p->wallSidling != 0) {
      return 1;
    }
    return 0;
  }

  if (param_2 == 0 || param_2 == 4) {
    return 1;
  }
  return 0;
}

// R を押していて見回しできる行動なら見回しを始める・続け, 離したら終える
void PlayerLink_HandleLookAround(Player* p, s32 val) {
  if ((p->input->down & R_BUTTON) && PlayerLink_CanLookAround(p, val)) {
    if ((p->kind <= PLAYER_BDJANGO || p->kind == PLAYER_SABATA) && p->action == PACT_WALL) {
      PlayerLink_StartLookAround(p);
    } else {
      PlayerLink_UpdateLookAround(p);
    }
  } else if (p->lookAroundOffset.val) {
    PlayerLink_EndLookAround(p);
  }
  p->unk_3d1 = 1;
}

// 見回し中の注視点を mover.pos + lookAroundOffset (+150 上) と今の注視点を 1:4 で混ぜて作り, 自分の画面のプレイヤーならカメラをそこへ向ける
void PlayerLink_UpdateCameraLookAt(Player* p) {
  p->cameraLookAt.x = Div(p->mover.pos.x + p->lookAroundOffset.x + p->cameraLookAt.x * 4, 5);
  p->cameraLookAt.y = Div(p->mover.pos.y + p->lookAroundOffset.y + 150 + p->cameraLookAt.y * 4, 5);
  p->cameraLookAt.z = Div(p->mover.pos.z + p->lookAroundOffset.z + p->cameraLookAt.z * 4, 5);
  if (p->mover.unk_4 == LinkSession_GetPlayerIdx()) {
    Camera_LookAt(&p->cameraLookAt);
  }
}

// 鳴り床の上にいるか
bool32 PlayerLink_IsOnSoundFloor(u32 attr) {
  if ((attr & TATTR_SPECIAL) && !TestMapFlag(MPF_HOT | MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

bool32 PlayerLink_IsInLava(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_HOT)) {
    return TRUE;
  }
  return FALSE;
}

static bool32 UNUSED FUN_080cfc3c(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_WATERFRONT)) {
    return TRUE;
  }
  return FALSE;
}

bool32 PlayerLink_IsOnIce(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

// 溶岩タイルに乗ったら, そのタイルの中心を knockbackOrigin にして位置をタイルの内側に収め, 被弾を保留する (エレベーター上と吹き飛ばし中は除く)
void PlayerLink_CheckLavaHurt(Player* p) {
  if (PlayerLink_IsInLava(GetTileAttrAt(&p->mover.pos)) && p->elevatorFlags == 0 && !p->originKnockback && !Elevator_FindAtPos(&p->mover.pos)) {
    s32 bx = Mod(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 bz = Div(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 minX, maxX, minZ, maxZ;

    p->knockbackTileCenter.x = (bx << 8) + 128;
    p->knockbackTileCenter.z = (bz << 8) + 128;
    p->knockbackOrigin = &p->knockbackTileCenter;
    minX = (bx << 8) + 1;
    maxX = (bx << 8) + 255;
    minZ = (bz << 8) + 1;
    maxZ = (bz << 8) + 255;
    if (p->mover.pos.x < minX) {
      p->mover.pos.x = minX;
    } else if (p->mover.pos.x > maxX) {
      p->mover.pos.x = maxX;
    }
    if (p->mover.pos.z < minZ) {
      p->mover.pos.z = minZ;
    } else if (p->mover.pos.z > maxZ) {
      p->mover.pos.z = maxZ;
    }
    p->beast.pos = p->mover.pos;
    p->human.pos = p->mover.pos;
    p->originHitPending = TRUE;
  }
}

// knockbackOrigin の位置から弾かれたときの被弾処理, 向きを knockbackOrigin から見た方向に合わせて吹き飛ばしを設定し, 受けるダメージ 50 を返す
s32 PlayerLink_ApplyOriginHit(Player* p) {
  p->originKnockback = TRUE;
  p->hurtbox.knockback = 50;
  Player_SetIframes(p, 60);
  p->blownAway = 0;
  p->floatHeight = 0;
  p->facing = (Angle_ToDir4(ArcTan2_8(p->mover.pos.x - p->knockbackOrigin->x, p->mover.pos.z - p->knockbackOrigin->z)) << 1) + 1;
  PLAYER_SET_ANIM_4DIR(p, p->facing);
  p->hurtSound = SE_IGNITE;
  p->originHitPending = FALSE;
  return 50;
}

// pos のタイルの高さが p の足元の高さと違うか, タイルに TATTR_UNK_0 が立っていれば真
bool32 PlayerLink_IsTileBlockedAt(Player* p, Vec3* pos) {
  if (TileHeightAt(pos) != p->mover.pos.y) {
    return TRUE;
  }
  if (GetTileAttrAt(pos) & TATTR_UNK_0) {
    return TRUE;
  }
  return FALSE;
}

// slideDir が斜めのとき, 進む先の両脇のタイルが段差か壁かを調べて, 塞がっていない側の方向 (1/3/5/7) を返す, 斜めでなければ -1
s32 PlayerLink_GetSlideDeflectDir(Player* p) {
  Vec3 pos;

  switch (p->slideDir) {
    case 0: {
      pos = p->mover.pos;
      pos.x -= 30;
      pos.z -= 30;
      pos.x -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      pos.x += 100;
      pos.z -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 7;
      }
      pos = p->mover.pos;
      pos.x -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      return 7;
    }
    case 2: {
      pos = p->mover.pos;
      pos.x += 30;
      pos.z -= 30;
      pos.x += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      pos.x -= 100;
      pos.z -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 3;
      }
      pos = p->mover.pos;
      pos.x += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      return 3;
    }
    case 4: {
      pos = p->mover.pos;
      pos.x += 30;
      pos.z += 30;
      pos.x += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      pos.x -= 100;
      pos.z += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 3;
      }
      pos = p->mover.pos;
      pos.x += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      return 3;
    }
    case 6: {
      pos = p->mover.pos;
      pos.x -= 30;
      pos.z += 30;
      pos.x -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      pos.x += 100;
      pos.z += 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 7;
      }
      pos = p->mover.pos;
      pos.x -= 100;
      if (PlayerLink_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      return 7;
    }
  }
  return -1;
}

// 氷の床で滑る処理, 歩き・ダッシュ・棺桶引きで氷に乗ると facing の向きに forcedDelta で滑り出し, 氷から出たら止める
void PlayerLink_UpdateIceSlide(Player* p) {
  u8* flag = &p->useForcedDelta;

  if (*flag != 0) {
    bool32 onIce = PlayerLink_IsOnIce(p->tile.attr[1]);

    if (onIce == FALSE) {
      p->slip_3a5[0] = 0;
      p->slip_3a5[1] = 0;
      *flag = 0;
    } else if (p->tile.unk_0[0] & 1) {
      Dir8U8* dir = &p->slideDir;

      if (*dir & 1) {
        p->slip_3a5[0] = 0;
        p->slip_3a5[1] = 0;
        *flag = 0;
      } else {
        u32 angle;

        *dir = PlayerLink_GetSlideDeflectDir(p);
        angle = ((*dir + 5) & 7) << 5;
        p->forcedDelta.x = POLAR_X(10, angle);
        p->forcedDelta.z = POLAR_Z(10, angle);
      }
    } else if (p->slip_3a5[0] == 0) {
      if (p->slip_3a5[1] != 0) {
        Sound_PlayForPlayer(p->inputIdx, SE_PLAYER_SLIP);
        p->slip_3a5[0] = 1;
      } else {
        p->slip_3a5[1]++;
      }
    }
  } else {
    u32 angle;

    if (!PlayerLink_IsOnIce(p->tile.attr[1])) {
      return;
    }
    if (p->action != PACT_WALK && p->action != PACT_DASH) {
      if (p->action != PACT_PULL_COFFIN) {
        return;
      }
      if ((s16)p->facingHistory[0] < 0) {
        return;
      }
    }
    *flag = 1;
    p->slideDir = p->facing;
    angle = ((p->slideDir + 5) & 7) << 5;
    p->forcedDelta.x = POLAR_X(10, angle);
    p->forcedDelta.z = POLAR_Z(10, angle);
  }
}

// 太陽ゲージ+2 を貯めて, 100 を超えるたびに1回ぶん消費する
void PlayerLink_StepSunburn(Player* p, s32 sungauge) {
  p->sunburn += sungauge + 2;
  if (p->sunburn > 99) {
    PlayerLink_EmitDamageSmoke(p);
    p->sunburn -= 100;
  }
}

// pos に何かを出し, marker があれば追尾マーカーも出して soundID を鳴らす
void PlayerLink_MakeNoise(Player* p, Vec3* pos, s16 param_3, s32 param_4, Vec3* marker, s32 param_6, s32 soundID) {
  NoiseManager_AddMoverNoise(pos->x, pos->z, param_3, 0, param_4, p->mover.id);

  if (marker != NULL) {
    LinkPlayerMarker_ShowTracking(p->inputIdx, marker);
    PlayerLink_ShowNoisePtcl(p, marker, param_6);
  }

  if (soundID != 0) {
    Sound_PlayForPlayer(p->inputIdx, soundID);
  }
}

NAKED void FUN_080d040c(Player* p) { INCFUNC("asm/func/FUN_080d040c.inc"); }

NAKED void FUN_080d05e8(Player* p) { INCFUNC("asm/func/FUN_080d05e8.inc"); }

// 直前の入力方向の履歴から向き直す先を選ぶ, 履歴が斜めなら即採用、それ以外は隣の方向が来るまで遡る
u32 PlayerLink_ResolveStopFacing(Player* p) {
  s32 dir = (s16)p->facingHistory[1];
  s32 next;
  s32 prev;
  s32 i;

  if (dir == -1) {
    return p->facing;
  }
  if (dir & 1) {
    return dir;
  }
  next = (dir + 1) & 7;
  prev = (dir + 7) & 7;
  for (i = 2; i < 10; i++) {
    s32 d = (s16)p->facingHistory[i];

    if (d != -1) {
      if (d == next || d == prev) {
        return d;
      }
      if (d != dir) {
        return dir;
      }
    }
  }
  return p->facing;
}

// player.c の Player_UpdateIdle と同じ内容
void FUN_080d0738(Player* p) {
  if (p->action != PACT_IDLE) {
    PlayerLink_SetAction(p, PACT_IDLE, 0);
    p->facing = PlayerLink_ResolveStopFacing(p);
    PlayerLink_SetAnimFacing(p);
  }
  p->flag20 &= ~PFLAG20_BUSY;
  PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
}

// ハヤサと鎧の重さから移動速度を出す, 下限は 2
s32 PlayerLink_CalcMoveSpeed(Player* p) {
  u16 n = p->goodCondTimer;
  bool32 heaviest = FALSE;
  s32 val;

  if (n != 0 && p->goodCondID == GOOD_SPEED) {
    heaviest = TRUE;
  }

  if (heaviest) {
    val = 16;
  } else {
    s32 agility = p->stats[STAT_AGILITY];
    s32 over = p->armor.weight - 100;

    val = Div((agility - over) * 12, 100);
    if (val > 16) {
      val = 16;
    } else if (val < 9) {
      val = 9;
    }
  }

  if (p->emitter.kind == ELEMCOND_HYOKETU && p->emitter.aliveCount != 0) {
    val -= 4;
  }
  if (p->speedPenalty != 0) {
    val -= p->speedPenalty;
  }
  if (val < 2) {
    return 2;
  }
  return val;
}

// 入力履歴の直近4件から隣の方向への向き直しを探す
// 残差1命令 (53/52), Player_ResolveInputFacing と同じく原典は d を -1 判定の直後に戻り値レジスタへ写す
// 試済: s16 d, d を関数頭で宣言, 戻り値用のローカルに写す
NON_MATCH u32 PlayerLink_ResolveInputFacing(Player* p) {
#ifdef NONMATCHING_C
  s32 dir = (s16)p->facingHistory[0];
  s32 next;
  s32 prev;
  s32 i;

  if (dir & 1) {
    return dir;
  }
  next = (dir + 1) & 7;
  prev = (dir + 7) & 7;
  for (i = 1; i < 5; i++) {
    s32 d = (s16)p->facingHistory[i];

    if (d != -1) {
      if (d == next || d == prev) {
        return d;
      }
      if (d != (s16)p->facingHistory[0]) {
        return dir;
      }
    }
  }
  return dir;
#else
  INCFUNC("asm/func/PlayerLink_ResolveInputFacing.inc");
#endif
}

s32 PlayerLink_CalcWalkAnimSpeed(s32 x) {
  if (x == 12) {
    return 0x40;
  }
  if (x <= 11) {
    return (12 - x) * 8 + 0x40;
  }
  return 0x40 - (x - 12) * 4;
}

// 歩きアニメの区切りで足音を鳴らす, 音の鳴る床なら物音も立てる (Player_PlayFootstep から水たまりとマップフラグの物音を除いたもの)
void PlayerLink_PlayFootstep(Player* p, u32 val) {
  if ((p->human.animCmdIdx & 3) != 0 || p->human.animCmdTimer != 0) {
    return;
  }

  if (HasGoodCond(p, GOOD_NINJA)) {
    return;
  }

  if (PlayerLink_IsOnSoundFloor(p->tile.attr[1]) && !HasGoodCond(p, GOOD_MINI)) {
    if (p->human.animCmdIdx == 0) {
      PlayerLink_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_1);
    } else {
      PlayerLink_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_0);
    }
    return;
  }

  if (val == 0) {
    if (HasGoodCond(p, GOOD_MINI)) {
      if (p->human.animCmdIdx == 0) {
        Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_MINI_1);
      } else {
        Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_MINI_0);
      }
    } else if (p->elevatorFlags != 0 || p->tile.stairs[1] == 0) {
      if (p->human.animCmdIdx == 0) {
        Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_M_1);
      } else {
        Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_M_0);
      }
    } else if (p->human.animCmdIdx == 0) {
      Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_STAIRS_1);
    } else {
      Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_STAIRS_0);
    }
  }
}

// 歩き始めるときの初期化, 移動速度とアニメを設定する
void PlayerLink_UpdateWalk(Player* p) {
  p->action = PACT_WALK;
  p->flag20 &= ~PFLAG20_BUSY;
  p->facing = PlayerLink_ResolveInputFacing(p);
  if (p->useForcedDelta == 0) {
    s32 val = PlayerLink_CalcMoveSpeed(p);
    bool32 scaled;
    u16 n;

    PlayerLink_CalcWalkAnimSpeed(val);
    n = p->goodCondTimer;
    scaled = FALSE;
    if (n != 0 && p->goodCondID == GOOD_MINI) {
      scaled = TRUE;
    }
    if (scaled) {
      val = val * p->human.scaleX >> 6;
    }
    PlayerLink_SetMoveDelta(p, val);
  }
  PlayerLink_PlayFootstep(p, 0);
  PlayerLink_SetAnimFacing(p);
  PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
}

// 魔法ダッシュ, 自分の光ゲージ (luxGauge) に応じた速さで前へ走る
void PlayerLink_UpdateDash(Player* p) {
  if (p->action != PACT_DASH) {
    if (PlayerLink_HasEnoughLux(p, 1)) {
      u32 i;
      s32 lux;

      Sound_PlayForPlayer(p->inputIdx, SE_M_DASH);
      i = p->inputIdx;
      if (gLinkSession == NULL) {
        lux = 0;
      } else {
        lux = gLinkSession->luxGauge[i];
      }
      p->dashSpeed = lux * 2 + 14;
      if (p->dashSpeed > 32) {
        p->dashSpeed = 32;
      }
      p->dashFrames = Div(512, p->dashSpeed);
      PlayerLink_SetAction(p, PACT_DASH, 0);
    } else {
      Sound_PlayForPlayer(p->inputIdx, SE_NG);
      PlayerLink_SetAction(p, PACT_DASH, 1);
    }
  }

  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer >= p->dashFrames) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      } else {
        if (p->stateTimer < p->dashFrames - 8) {
          p->flashPlttID = 293;
          p->plttFlashTimer = 32;
        }
        if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
          p->facing = PlayerLink_ResolveInputFacing(p);
        }
        PlayerLink_SetMoveDelta(p, p->dashSpeed);
        PlayerLink_PlayFootstep(p, 1);
        PlayerLink_SetAnimFacing(p);
        PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(0.5));
      }
      break;
    }
    case 1: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 7) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 進行方向のタイル端数が中央寄りかを返す
// 向いている軸の座標がタイルの中心寄り (タイル内の位置 31..225) にあるか (Player_IsNearTileCenter と同じ)
// 残差1命令 (23対22), Player_IsNearTileCenter と同じくマスク側を destination にできない
// 試済: 0xFF & pos, 条件を TRUE 側に反転, (u16) で受けて &= 0xFF
NON_MATCH bool32 PlayerLink_IsNearTileCenter(Player* p) {
#ifdef NONMATCHING_C
  u16 pos;
  u32 ofs;

  if (p->actionDir == DIR8_UP_RIGHT || p->actionDir == DIR8_DOWN_LEFT) {
    pos = p->mover.pos.x;
  } else {
    pos = p->mover.pos.z;
  }
  ofs = pos & 0xFF;
  if (ofs < 31 || ofs > 225) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/PlayerLink_IsNearTileCenter.inc");
#endif
}

// 壁張り付き (PACT_WALL), 張り付いて横歩きし A で壁を叩く (Player_UpdateWall から押しブロックと脆い壁・扉の判定を除いたもの, wallPos は計算するだけで使われない)
void PlayerLink_UpdateWall(Player* p) {
  u32 animIdx;

  p->action = PACT_WALL;
  if (p->state == 1 && (p->input->pressed & A_BUTTON)) {
    PlayerLink_SetAction(p, PACT_WALL, 2);
  }

  switch (p->state) {
    case 0: {
      Player_SetFlag20(p, PFLAG20_UNK_2);
      animIdx = Player_GetAnimIdx(p->kind, 2);
      if (p->animID != animIdx) {
        Sound_PlayForPlayer(p->inputIdx, SE_COVER);
        p->facing = (p->actionDir + 4) & 7;
        PLAYER_SET_ANIM_4DIR(p, p->actionDir);
      }
      if (PlayerLink_PlayAnim(p, animIdx, Q6(1))) {
        PlayerLink_SetAction(p, PACT_WALL, 1);
      }
      break;
    }
    case 1: {
      s32 dir;
      s32 left;
      s32 right;

      Player_SetFlag20(p, PFLAG20_WALL_COVER);
      p->wallSidling = 1;
      dir = (s16)p->facingHistory[0];
      left = (p->actionDir + 7) & 7;
      right = (p->actionDir + 1) & 7;
      animIdx = Player_GetAnimIdx(p->kind, 3);
      if (dir == left || dir == right) {
        s32 turn = (dir - p->actionDir) * 2 + 8;
        Vec3 pos;
        s32 idx;
        s32 height;

        dir = (((p->actionDir + turn) & 7) + 1) & 7;
        pos = p->mover.pos;
        pos.x -= POLAR_X(50, dir << 5);
        pos.z -= POLAR_Z(50, dir << 5);
        idx = GetCollisionTileIdx(&pos);
        height = TileHeightAt(&pos);
        if (height > p->mover.pos.y - Q8(0.5) && height < p->mover.pos.y + Q8(0.5)) {
          MapTileOverride* ov = Map_FindTileOverride(idx, 1);
          CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

          if (!PlayerLink_IsOnIce(tile->attr)) {
            pos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
            pos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
            if (TileHeightAt(&pos) >= height + Q8(0.782) && !(GetTileAttrAt(&pos) & TATTR_UNK_2)) {
              s32 speed;

              animIdx = Player_GetAnimIdx(p->kind, 4);
              if (p->human.animCmdIdx == 0) {
                speed = 0;
              } else if (p->human.animCmdIdx == 2) {
                speed = 6;
              } else {
                speed = 3;
              }
              p->mover.delta.x = -FixToInt(12, COS(dir << 5) * speed);
              p->mover.delta.z = -FixToInt(12, SIN(dir << 5) * speed);
            }
          }
        }
      }
      PlayerLink_PlayAnim(p, animIdx, Q6(1));
      if (p->animID == 24 && p->human.animCmdIdx == 0 && p->human.animCmdTimer == 1) {
        Sound_PlayForPlayer(p->inputIdx, SE_WALL_SLIDE);
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_WALL_COVER);
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 5), Q6(1))) {
        Vec3 effectPos = p->mover.pos;
        Vec3 wallPos;

        if (p->actionDir == DIR8_UP_RIGHT) {
          effectPos.x += 28, effectPos.y += 44, effectPos.z -= 76;
        } else if (p->actionDir == DIR8_DOWN_RIGHT) {
          effectPos.x -= 52, effectPos.y += 0, effectPos.z += 0;
        } else if (p->actionDir == DIR8_DOWN_LEFT) {
          effectPos.x += 12, effectPos.y += 44, effectPos.z -= 32;
        } else if (p->actionDir == DIR8_UP_LEFT) {
          effectPos.x -= 64, effectPos.y += 68, effectPos.z += 44;
        }
        wallPos = p->mover.pos;
        wallPos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
        wallPos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
        PlayerLink_MakeNoise(p, &p->mover.pos, 256, 1, &effectPos, 0, SE_WALL_KNOCK);
        PlayerLink_SetAction(p, PACT_WALL, 1);
      }
      break;
    }
  }
}

s32 PlayerLink_CanSolarCharge(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

// チャージの溜め位置 chargePos を頭上の手元に置く, 下向きかどうかで前後をずらす
void PlayerLink_SetChargePos(Player* p) {
  p->chargePos = p->mover.pos;
  if (p->facing == DIR8_DOWN) {
    p->chargePos.x -= Q8(0.08);
    p->chargePos.y += Q8(1.29);
    p->chargePos.z += Q8(0.235);
  } else {
    p->chargePos.x += Q8(0.08);
    p->chargePos.y += Q8(1.29);
    p->chargePos.z -= Q8(0.12);
  }
}

// 太陽チャージ (PACT_UNK_7), 構えたあと A を押し続けている間, 日光が当たっていて ENE が満タンでなければチャージ音を鳴らして光の粒を出す
void PlayerLink_UpdateSolarCharge(Player* p) {
  if (p->action != PACT_UNK_7) {
    PlayerLink_SetAction(p, PACT_UNK_7, 0);
    p->nextEnchantColorIdx = 0;
  }

  switch (p->state) {
    case 0: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      PlayerLink_SetAction(p, PACT_UNK_7, 1);
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        if (p->facing >= 2 && p->facing <= 6) {
          p->facing = DIR8_DOWN;
          p->animDir = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animDir = 0;
          p->xflip = FALSE;
        }
        PlayerLink_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        Sound_PlayForPlayer(p->inputIdx, SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          PlayerLink_SetAction(p, PACT_UNK_7, 4);
        } else if (PlayerLink_CanSolarCharge(p)) {
          Sound_PlayForPlayer(p->inputIdx, NOISE_SOLAR_CHARGE);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          PlayerLink_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          PlayerLink_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5) {
          if (p->kind == PLAYER_BDJANGO) {
            Sound_PlayForPlayer(p->inputIdx, VO_BDJANGO_TAIYO);
          } else {
            Sound_PlayForPlayer(p->inputIdx, VO_RDJANGO_TAIYO);
          }
        }
      }
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      PlayerLink_SetChargePos(p);
      PlayerLink_SpawnSolarChargePtcl(p, &p->chargePos);
      if (!(p->input->down & A_BUTTON)) {
        Sound_StopForPlayer(p->inputIdx, NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 4);
      } else if (!PlayerLink_CanSolarCharge(p)) {
        Sound_StopForPlayer(p->inputIdx, NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        PlayerLink_SetAction(p, PACT_UNK_7, 4);
      } else if (PlayerLink_CanSolarCharge(p)) {
        Sound_PlayForPlayer(p->inputIdx, NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animDir = p->facing;
        p->xflip = FALSE;
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

s32 PlayerLink_CanDarkCharge(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return 1;
  }
  return 0;
}

// サバタの暗黒チャージ (PACT_UNK_7), 構えたあと A を押し続けている間, 日光が当たっていなくて ENE が満タンでなければチャージ音を鳴らして闇の粒を出す
void PlayerLink_UpdateDarkCharge(Player* p) {
  if (p->action != PACT_UNK_7) {
    PlayerLink_SetAction(p, PACT_UNK_7, 0);
  }

  switch (p->state) {
    case 0: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      PlayerLink_SetAction(p, PACT_UNK_7, 1);
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        if (p->facing >= 2 && p->facing <= 6) {
          p->facing = DIR8_DOWN;
          p->animDir = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animDir = 0;
          p->xflip = FALSE;
        }
        PlayerLink_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        Sound_PlayForPlayer(p->inputIdx, SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          PlayerLink_SetAction(p, PACT_UNK_7, 4);
        } else if (PlayerLink_CanDarkCharge(p)) {
          Sound_PlayForPlayer(p->inputIdx, VO_SABATA_ANKOKU);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          PlayerLink_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          PlayerLink_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5) {
          Sound_PlayForPlayer(p->inputIdx, NOISE_DARK_CHARGE);
        }
      }
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      PlayerLink_SetChargePos(p);
      PlayerLink_SpawnDarkChargePtcl(p, &p->chargePos);
      p->flashPlttID = OBP_ELEMENT(1);
      if (p->stateTimer < 32) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }
      if (++p->stateTimer > 64) {
        p->stateTimer = 0;
      }
      if (!(p->input->down & A_BUTTON)) {
        Sound_StopForPlayer(p->inputIdx, NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 4);
      } else if (!PlayerLink_CanDarkCharge(p)) {
        Sound_StopForPlayer(p->inputIdx, NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        PlayerLink_SetAction(p, PACT_UNK_7, 4);
      } else if (PlayerLink_CanDarkCharge(p)) {
        Sound_PlayForPlayer(p->inputIdx, NOISE_DARK_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        PlayerLink_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animDir = p->facing;
        p->xflip = FALSE;
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 入力があって見回し中でなければ向きを入力方向に合わせ直す
s32 PlayerLink_FaceInputDir(Player* p) {
  s32 changed = 0;

  if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
    p->facing = PlayerLink_ResolveInputFacing(p);
    changed = 1;
  }

  PlayerLink_SetAnimFacing(p);
  return changed;
}

void PlayerLink_RefreshEnchant(Player* p) {
  p->wpn.enchantIdx = PlayerLink_CheckMagicEnchant(p);
  if (p->wpn.enchantIdx >= 0) {
    p->nextEnchantColorIdx = p->wpn.enchantIdx + 1;
  } else {
    p->nextEnchantColorIdx = 0;
  }
}

NAKED s32 FUN_080d1a80(Player* p) { INCFUNC("asm/func/FUN_080d1a80.inc"); }

s32 PlayerLink_GetAttackPower(Player* p) {
  s32 result = FUN_080d1a80(p);
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponExDamageCb[i] != NULL) {
      result += p->weaponExDamageCb[i](p);
    }
  }
  return result;
}

s32 PlayerLink_GetWeaponEffectAttrs(Player* p) {
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

// 向いている方向へ武器の攻撃判定を出す準備をする, 黒ジャンゴとブルースパワー装備中は振りの速さを 1.5 倍にし, エンチャント中は属性を足して魔法のコストを払う
void PlayerLink_SetupSwordAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttrs attrs;
  u16 iframes;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = PlayerLink_GetAttackPower(p);
  attrs = PlayerLink_GetWeaponEffectAttrs(p);
  iframes = p->wpn.iframes;
  if (p->kind == PLAYER_BDJANGO) {
    p->wpn.step = 12;
    p->wpn.swingTime = 5;
    p->wpn.waitTime = 3;
    attrs |= HBATTR_BLOW;
  } else if (TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
    p->wpn.step = 12;
    p->wpn.swingTime = 5;
    p->wpn.waitTime = 3;
  } else {
    p->wpn.step = 8;
    p->wpn.swingTime = 8;
    p->wpn.waitTime = 4;
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    PlayerLink_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockback, HBSRC_SWORD, attrs, iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->timer = 0;
}

// pos から angle の向きに 112-239 離れた位置に, angle と直交する向き (flip で反対) に速さ 6 で飛ぶエンチャントの粒を出す
void PlayerLink_SpawnSwordEnchantPtcl(Player* p, Vec3* pos, s32 angle, bool32 flip, s32 element) {
  Vec3 spawn, vel;
  s32 r = (Random() & 0x7F) + 112;

  spawn.x = pos->x + POLAR_X(r, angle);
  spawn.y = pos->y;
  spawn.z = pos->z + POLAR_Z(r, angle);
  vel.x = POLAR_Z(6, angle);
  vel.y = 0;
  vel.z = -POLAR_X(6, angle);
  if (flip) {
    vel.x = -vel.x;
    vel.z = -vel.z;
  }
  PlayerLink_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 剣を振る: wpn.angle の両側を往復させながら判定を出し, 振り終えたら TRUE
// 残差 178/178: Player_UpdateSwordSwing と同じく xflip でない側の角度の足し算と p / angle のレジスタ
// 試済: 原典の足す順 (n * k + 0x100 + angle - 0x20) に並べる (180 命令)
NON_MATCH bool32 PlayerLink_UpdateSwordSwing(Player* p) {
#ifdef NONMATCHING_C
  PlayerWeapon* wpn = &p->wpn;

  if (p->wpn.timer == 0) {
    if (p->kind == PLAYER_RDJANGO) {
      Sound_PlayForPlayer(p->inputIdx, SE_SWORD_ATK_R);
    } else {
      Sound_PlayForPlayer(p->inputIdx, SE_SWORD_ATK_B);
    }
  }
  if (++wpn->timer <= wpn->swingTime) {
    u32 angle;
    if (p->xflip) {
      angle = wpn->angle + 0x20 - wpn->timer * wpn->step + 0x100;
    } else {
      angle = wpn->angle - 0x20 + wpn->timer * wpn->step + 0x100;
    }
    angle &= 0xFF;
    wpn->atkPos.x = wpn->basePos.x + POLAR_X(160, angle);
    wpn->atkPos.y = wpn->basePos.y;
    wpn->atkPos.z = wpn->basePos.z + POLAR_Z(160, angle);
    Hitbox_SetPos(&wpn->hitbox, &wpn->atkPos, 0);
    Hitbox_Register(&wpn->hitbox);
    if (wpn->enchantIdx >= 0) {
      p->flag20 |= PFLAG20_UNK_19;
      if (wpn->timer & 1) {
        PlayerLink_SpawnSwordEnchantPtcl(p, &wpn->basePos, angle, p->xflip, wpn->enchantIdx);
      }
    }
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/PlayerLink_UpdateSwordSwing.inc");
#endif
}

// 剣の攻撃 (PACT_ATTACK), B を離すと振り, 振りの間に B を押せば続けて振る
void PlayerLink_UpdateSwordAttack(Player* p) {
  s32 animSpeed;

  if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      PlayerLink_RefreshEnchant(p);
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 21), animSpeed)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      PlayerLink_RefreshEnchant(p);
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 22), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        PlayerLink_SetupSwordAttack(p);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 23), animSpeed);
      if (p->kind == PLAYER_BDJANGO && p->human.animCmdIdx == 2 && p->human.animCmdTimer == 0) {
        PlayerLink_SpawnSwordShockwave(p, p->facing, &p->mover.pos);
      }
      if (PlayerLink_UpdateSwordSwing(p)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 0;
      } else if (++p->stateTimer >= p->wpn.waitTime) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// src から angle の方向へ dist だけずらした座標を dst に書く, 高さはそのまま写す (Vec3_CopyOffsetPolar と同じ)
void PlayerLink_CopyOffsetPolar(Vec3* dst, Vec3* src, s32 angle, s32 dist) {
  dst->x = src->x + POLAR_X(dist, angle);
  dst->y = src->y;
  dst->z = src->z + POLAR_Z(dist, angle);
}

// tile の高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
s32 PlayerLink_GetTileHeight(CollisionMapTile* tile, Vec3* pos) {
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

// pos から angle の方向へ dist 進んだ位置のタイルが足元より高いか, 1 なら元のタイル, 2 なら差し替えタイルが高い, 0 は高くない
s32 PlayerLink_CheckTileHigherAhead(Vec3* pos, s32 angle, s32 dist) {
  Vec3 dst;
  s32 bx, bz, idx;
  CollisionMapTile* tile;
  MapTileOverride* ov;

  PlayerLink_CopyOffsetPolar(&dst, pos, angle, dist);
  bx = (s8)(dst.x >> 8);
  bz = (s8)(dst.z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  if (gCollisionMap->tiledata == NULL) {
    tile = NULL;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }
  if (PlayerLink_GetTileHeight(tile, &dst) > dst.y) {
    return 1;
  }
  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL && PlayerLink_GetTileHeight(&ov->tile, &dst) > dst.y) {
    return 2;
  }
  return 0;
}

// 槍の攻撃判定を構える, 前方の段差の高さで振り方 (anim のアニメ) と振りの段数を選び, エンチャント中は属性を足して魔法のコストを払う
void PlayerLink_SetupSpearAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttrs attrs;
  u16 knockback;
  s32 r;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 150;
  wpn->angle = ((p->facing + 5) & 7) << 5;
  wpn->atkPos.x = wpn->basePos.x + POLAR_X(204, wpn->angle);
  wpn->atkPos.y = wpn->basePos.y;
  wpn->atkPos.z = wpn->basePos.z + POLAR_Z(204, wpn->angle);
  power = PlayerLink_GetAttackPower(p);
  attrs = PlayerLink_GetWeaponEffectAttrs(p);
  if (p->kind == PLAYER_BDJANGO) {
    attrs |= HBATTR_BLOW;
  }
  knockback = wpn->knockback;
  r = PlayerLink_CheckTileHigherAhead(&wpn->basePos, wpn->angle, 224);
  if (r != 0) {
    if ((wpn->enchantIdx == 2 || wpn->enchantIdx == 4) && r == 2) {
      wpn->anim = 27;
      if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
        wpn->step = 56;
        wpn->swingTime = 0;
        wpn->holdTime = 2;
        wpn->waitTime = 3;
      } else {
        wpn->step = 56;
        wpn->swingTime = 0;
        wpn->holdTime = 3;
        wpn->waitTime = 6;
      }
    } else {
      wpn->anim = 26;
      if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
        wpn->step = 56;
        wpn->swingTime = 0;
        wpn->holdTime = 2;
        wpn->waitTime = 0;
      } else {
        wpn->step = 56;
        wpn->swingTime = 0;
        wpn->holdTime = 3;
        wpn->waitTime = 0;
      }
    }
  } else if (PlayerLink_CheckTileHigherAhead(&wpn->basePos, wpn->angle, 336)) {
    wpn->anim = 27;
    if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
      wpn->step = 56;
      wpn->swingTime = 2;
      wpn->holdTime = 3;
      wpn->waitTime = 0;
    } else {
      wpn->step = 56;
      wpn->swingTime = 2;
      wpn->holdTime = 7;
      wpn->waitTime = 0;
    }
  } else {
    wpn->anim = 28;
    if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
      wpn->step = 56;
      wpn->swingTime = 4;
      wpn->holdTime = 4;
      wpn->waitTime = 1;
    } else {
      wpn->step = 56;
      wpn->swingTime = 4;
      wpn->holdTime = 7;
      wpn->waitTime = 5;
    }
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    PlayerLink_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, knockback, HBSRC_SPEAR, attrs, wpn->iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->timer = 0;
}

// pos の周り ±15 の位置から angle の反対向きに速さ 3-6 で飛ぶエンチャントの粒を出す
void PlayerLink_SpawnSpearEnchantPtcl(Player* p, Vec3* pos, s32 angle, s32 element) {
  Vec3 spawn, vel;
  s32 speed;

  spawn.x = pos->x + (RandomNext() & 0x1F) - 15;
  spawn.y = pos->y + (RandomNext() & 0x1F) - 15;
  spawn.z = pos->z + (RandomNext() & 0x1F) - 15;
  speed = (RandomNext() & 3) + 3;
  vel.x = -POLAR_X(speed, angle);
  vel.y = 0;
  vel.z = -POLAR_Z(speed, angle);
  PlayerLink_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 槍の突きを1フレーム進める, swingTime フレームかけて攻撃判定を前へ伸ばし, holdTime フレーム留めて, waitTime フレーム待つと終わり (TRUE)
s32 PlayerLink_UpdateSpearThrust(Player* p) {
  PlayerWeapon* w = &p->wpn;

  if (w->timer == 0) {
    if (p->kind == PLAYER_RDJANGO) {
      Sound_PlayForPlayer(p->inputIdx, SE_SPEAR_ATK_R);
    } else {
      Sound_PlayForPlayer(p->inputIdx, SE_SPEAR_ATK_B);
    }
  }
  if (w->timer < w->swingTime) {
    s32 r = w->step * w->timer + 204;

    w->atkPos.x = w->basePos.x + POLAR_X(r, w->angle);
    w->atkPos.y = w->basePos.y;
    w->atkPos.z = w->basePos.z + POLAR_Z(r, w->angle);
    Hitbox_SetPos(&w->hitbox, &w->atkPos, 0);
    Hitbox_Register(&w->hitbox);
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      PlayerLink_SpawnSpearEnchantPtcl(p, &w->atkPos, w->angle, w->enchantIdx);
    }
  } else if (w->timer < w->swingTime + w->holdTime) {
    s32 r = w->step * w->swingTime + 204;

    w->atkPos.x = w->basePos.x + POLAR_X(r, w->angle);
    w->atkPos.y = w->basePos.y;
    w->atkPos.z = w->basePos.z + POLAR_Z(r, w->angle);
    Hitbox_SetPos(&w->hitbox, &w->atkPos, 0);
    Hitbox_Register(&w->hitbox);
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      if (!(w->timer & 1)) {
        PlayerLink_SpawnSpearEnchantPtcl(p, &w->atkPos, w->angle, w->enchantIdx);
      }
    }
  }
  if (++w->timer >= w->swingTime + w->holdTime + w->waitTime) {
    w->timer = 0;
    return TRUE;
  }
  return FALSE;
}

// 槍の攻撃 (PACT_ATTACK), 7 フレーム以上構えて B を離すと突き, 黒ジャンゴは槍の衝撃波を出す
void PlayerLink_UpdateSpearAttack(Player* p) {
  s32 animSpeed;
  u16* kind;
  u8* playerKind;
  u8 idx;

  if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      PlayerLink_RefreshEnchant(p);
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), animSpeed)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      PlayerLink_RefreshEnchant(p);
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), Q6(1));
      if (p->stateTimer > 6 && !(p->input->down & B_BUTTON)) {
        PlayerLink_SetupSpearAttack(p);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      playerKind = &p->kind;
      idx = *playerKind;
      kind = &p->wpn.anim;
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(idx, *kind), animSpeed);
      if (*playerKind == PLAYER_BDJANGO) {
        if (*kind == 28) {
          if (p->human.animCmdIdx == 1 && p->human.animCmdTimer == 0) {
            PlayerLink_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 0);
          }
        } else if (*kind == 27) {
          if (p->human.animCmdIdx == 1 && p->human.animCmdTimer == 0) {
            PlayerLink_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 1);
          }
        } else if (*kind == 26 && p->human.animCmdIdx == 0 && p->human.animCmdTimer == 1) {
          PlayerLink_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 2);
        }
      }
      if (PlayerLink_UpdateSpearThrust(p)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), animSpeed)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 0;
      } else if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), animSpeed)) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 向いている方向へ武器の攻撃判定を出す準備をする (Player_SetupSwordAttack の別の値の版, 判定の種類は 4)
void PlayerLink_SetupHammerAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttrs attrs;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = PlayerLink_GetAttackPower(p);
  attrs = PlayerLink_GetWeaponEffectAttrs(p);
  if (p->kind == PLAYER_BDJANGO) {
    p->wpn.step = 29;
    p->wpn.waitTime = 7;
    p->wpn.swingTime = 4;
    p->wpn.holdTime = 6;
    attrs |= HBATTR_BLOW;
  } else if (TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
    p->wpn.step = 29;
    p->wpn.waitTime = 7;
    p->wpn.swingTime = 4;
    p->wpn.holdTime = 6;
  } else {
    p->wpn.step = 19;
    p->wpn.waitTime = 11;
    p->wpn.swingTime = 6;
    p->wpn.holdTime = 9;
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    PlayerLink_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockback, HBSRC_HAMMER, attrs, wpn->iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->timer = 0;
}

// pos の周り ±15 の位置から, yaw / pitch の向きに速さ 5-8 で飛ぶエンチャントの粒を出す (Player_SpawnSpearEnchantPtcl の別版)
void PlayerLink_SpawnHammerEnchantPtcl(Player* p, Vec3* pos, s32 yaw, s32 pitch, s32 element) {
  Vec3 spawn, vel;
  s32 speed, v;

  spawn.x = pos->x + (RandomNext() & 0x1F) - 15;
  spawn.y = pos->y + (RandomNext() & 0x1F) - 15;
  spawn.z = pos->z + (RandomNext() & 0x1F) - 15;
  speed = (RandomNext() & 3) + 5;
  vel.y = POLAR_X(speed, yaw);
  v = -POLAR_Z(speed, yaw);
  vel.x = POLAR_X(v, pitch);
  vel.z = POLAR_Z(v, pitch);
  PlayerLink_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 槌の振り下ろしを1フレーム進める, waitTime フレーム溜めてから swingTime フレームで頭上から前へ弧を描き, 振り下ろしの終わりに足元へ判定を出して holdTime フレーム残すと終わり (TRUE)
s32 PlayerLink_UpdateHammerSwing(Player* p) {
  PlayerWeapon* w = &p->wpn;

  if (++w->timer <= w->waitTime) {
    return FALSE;
  }
  if (w->timer <= w->waitTime + w->swingTime) {
    s32 pitch;
    s32 v;

    if (w->timer == w->waitTime + w->swingTime) {
      if (p->kind == PLAYER_RDJANGO) {
        Sound_PlayForPlayer(p->inputIdx, SE_HAMMER_ATK_R);
      } else {
        Sound_PlayForPlayer(p->inputIdx, SE_HAMMER_ATK_B);
      }
    }
    pitch = (336 - (w->timer - w->waitTime) * w->step) & 0xFF;
    w->atkPos.y = w->basePos.y + POLAR_Z(250, pitch);
    v = POLAR_X(250, pitch);
    w->atkPos.x = w->basePos.x + POLAR_X(v, w->angle);
    w->atkPos.z = w->basePos.z + POLAR_Z(v, w->angle);
    if (w->timer > w->waitTime + 2 && w->enchantIdx >= 0) {
      PlayerLink_SpawnHammerEnchantPtcl(p, &w->atkPos, pitch, w->angle, w->enchantIdx);
    }
    if (w->timer > w->waitTime + w->swingTime - 2) {
      Vec3 pos;
      s32 radius = 170;

      pos.x = w->basePos.x + POLAR_X(radius, w->angle);
      pos.y = (w->waitTime + w->swingTime - w->timer + 1) * 90 + w->basePos.y - 260;
      pos.z = w->basePos.z + POLAR_Z(radius, w->angle);
      if (w->enchantIdx >= 0) {
        SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      }
      Hitbox_SetPos(&p->wpn.hitbox, &pos, 0);
      Hitbox_Register(&w->hitbox);
    }
    return FALSE;
  }
  if (w->timer <= w->waitTime + w->swingTime + w->holdTime) {
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
    }
    Hitbox_Register(&p->wpn.hitbox);
    return FALSE;
  }
  w->timer = 0;
  return TRUE;
}

// 槌の攻撃 (PACT_ATTACK), B を離すと振り下ろし, 黒ジャンゴは後ろへ衝撃波を出す
void PlayerLink_UpdateHammerAttack(Player* p) {
  s32 animSpeed;

  if (p->kind == PLAYER_BDJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      PlayerLink_RefreshEnchant(p);
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 29), animSpeed)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      PlayerLink_RefreshEnchant(p);
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 30), animSpeed);
      if (!(p->input->down & B_BUTTON)) {
        PlayerLink_SetupHammerAttack(p);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), animSpeed);
      if (PlayerLink_UpdateHammerSwing(p)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->kind == PLAYER_BDJANGO && p->human.animCmdIdx == 5 && p->human.animCmdTimer == 0) {
        PlayerLink_SpawnHammerShockwave(p, p->facing, &p->mover.pos);
      }
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), animSpeed)) {
        if (p->wpn.unk_ae[0] != 0) {
          p->wpn.unk_ae[0] = 0;
          PlayerLink_SetAction(p, PACT_ATTACK, 1);
        } else {
          p->wpn.unk_ae[0] = 0;
          PlayerLink_SetAction(p, PACT_IDLE, 0);
        }
      }
      break;
    }
  }
}

// 向いている方向へ素手の攻撃判定を出す準備をする, 判定の向きと威力を決め, 出した位置を wpn.basePos に残す
void PlayerLink_SetupFistAttack(Player* p) {
  s32 power;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = PlayerLink_GetAttackPower(p);
  Video_SetAuxSpritePltt(&p->wpn.gfx, 45);
  Hitbox_SetAttack(&p->wpn.hitbox, power, p->wpn.knockback, HBSRC_FIST, 0, p->wpn.iframes);
  p->wpn.hitbox.angle = p->wpn.angle;
  p->wpn.timer = 0;
}

// 武器の攻撃判定を wpn.basePos から wpn.angle の向きへ 100 進めた位置に置いて6フレーム出し続ける, 出し終えたら 1 を返す
s32 PlayerLink_UpdateFistPunch(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  if (p->wpn.timer == 0) {
    Sound_PlayForPlayer(p->inputIdx, SE_FIST_ATK);
  }
  if (++p->wpn.timer <= 5) {
    wpn->atkPos.x = wpn->basePos.x + POLAR_X(100, wpn->angle);
    wpn->atkPos.y = wpn->basePos.y;
    wpn->atkPos.z = wpn->basePos.z + POLAR_Z(100, wpn->angle);
    Hitbox_SetPos(&p->wpn.hitbox, &p->wpn.atkPos, 0);
    Hitbox_Register(&p->wpn.hitbox);
    return 0;
  }
  p->wpn.timer = 0;
  return 1;
}

// 拳の攻撃 (PACT_ATTACK), B を離すと突き, 突きの間に B を押せば続けて突く
void PlayerLink_UpdateFistAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 32), Q6(1))) {
        if (p->input->down & B_BUTTON) {
          PlayerLink_SetAction(p, PACT_ATTACK, 1);
        } else {
          PlayerLink_SetupFistAttack(p);
          PlayerLink_SetAction(p, PACT_ATTACK, 4);
        }
      }
      break;
    }
    case 1: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 33), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        PlayerLink_SetupFistAttack(p);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 34), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (PlayerLink_UpdateFistPunch(p)) {
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 33), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer >= 10) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 32), Q6(1));
      if (++p->stateTimer >= 5) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 通信対戦の太陽銃の攻撃, 撃って B を押し続けると1段チャージする, 撃っている間 solarGunTime を数え黒ジャンゴは日焼けする (Player_UpdateSolarGunAttack の通信版)
void PlayerLink_UpdateSolarGunAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_AIM);
      }
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        p->knockbackSpeed = 0;
        if (p->ene <= 24) {
          Sound_PlayForPlayer(p->inputIdx, SE_GUN_MISFIRE);
          PlayerLink_SetAction(p, PACT_ATTACK, 5);
        } else {
          p->solarGunTime = 15;
          if (!(p->input->down & B_BUTTON)) {
            Sound_PlayForPlayer(p->inputIdx, SE_GUN_FIRE);
            PlayerLink_SetAction(p, PACT_ATTACK, 5);
          } else {
            PlayerLink_SetAction(p, PACT_ATTACK, 2);
          }
          Bullet_Create(p, 230, 180, 0, 32, 44, 32, HBATTR_SOL, 30, 3, 25, FALSE);
        }
      }
      break;
    }
    case 2: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      p->solarGunTime++;
      if (p->stateTimer == 6) {
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_CHARGING);
      }
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_FIRE);
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= 60) {
        p->wpn.charge = 1;
        p->knockbackSpeed = 30;
        p->flashPlttID = 289;
        p->plttFlashTimer = 36;
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_CHARGED);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      }
      break;
    }
    case 4: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      p->solarGunTime++;
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_FIRE);
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->knockbackSpeed != 0) {
        s32 angle;

        if (p->knockbackSpeed > 5) {
          Vec3 ofs;
          Vec3 size;

          VEC3_SET(ofs, 0, 0, 0);
          VEC3_SET(size, 32, 32, 32);
          DustManager_SpawnNoPause(&p->mover.pos, &ofs, &size, 1, 3, 4);
        }
        angle = ((p->facing + 5) & 7) * 32;
        p->mover.delta.x = -POLAR_X(p->knockbackSpeed, angle);
        p->mover.delta.z = -POLAR_Z(p->knockbackSpeed, angle);
        p->knockbackSpeed = (p->knockbackSpeed * 3) >> 2;
      } else if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0]) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer > 14) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1));
      if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
  if (p->solarGunTime > 14) {
    if (p->kind == PLAYER_BDJANGO) {
      PlayerLink_EmitDamageSmoke(p);
    }
    p->solarGunTime = 0;
  }
  p->nextEnchantColorIdx = 8;
}

// 通信対戦のロックバスターの攻撃, 撃って B を押し続けると1段チャージし, 離すと撃った反動で後ろへ下がる (Player_UpdateMegaBusterAttack の通信版)
void PlayerLink_UpdateMegaBusterAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1))) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        p->knockbackSpeed = 0;
        if (p->ene <= 19) {
          Sound_PlayForPlayer(p->inputIdx, SE_GUN_MISFIRE);
          PlayerLink_SetAction(p, PACT_ATTACK, 5);
        } else {
          if (!(p->input->down & B_BUTTON)) {
            Sound_PlayForPlayer(p->inputIdx, SE_ROCKBUSTER_FIRE);
            PlayerLink_SetAction(p, PACT_ATTACK, 5);
          } else {
            PlayerLink_SetAction(p, PACT_ATTACK, 4);
          }
          Bullet_Create(p, 200, 170, 8, 32, 46, 32, 0, 30, 17, 20, FALSE);
        }
      }
      break;
    }
    case 2: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (p->stateTimer == 6) {
        Sound_PlayForPlayer(p->inputIdx, SONG_500);
      }
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, SE_ROCKBUSTER_FIRE);
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= 60) {
        p->wpn.charge = 1;
        p->knockbackSpeed = 30;
        p->flashPlttID = 289;
        p->plttFlashTimer = 36;
        Sound_PlayForPlayer(p->inputIdx, SONG_501);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      }
      break;
    }
    case 4: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, SE_ROCKBUSTER_FIRE);
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 40), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->knockbackSpeed != 0) {
        s32 angle;

        if (p->knockbackSpeed > 5) {
          Vec3 ofs;
          Vec3 size;

          VEC3_SET(ofs, 0, 0, 0);
          VEC3_SET(size, 32, 32, 32);
          DustManager_SpawnNoPause(&p->mover.pos, &ofs, &size, 1, 3, 4);
        }
        angle = ((p->facing + 5) & 7) * 32;
        p->mover.delta.x = -POLAR_X(p->knockbackSpeed, angle);
        p->mover.delta.z = -POLAR_Z(p->knockbackSpeed, angle);
        p->knockbackSpeed = (p->knockbackSpeed * 3) >> 2;
      } else if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0]) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer > 14) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1));
      if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
  p->nextEnchantColorIdx = 4;
}

// 通信対戦のサバタの暗黒銃の攻撃, 撃って B を押し続けると1段チャージし, 離すと周りを回る散弾を撃つ (Player_UpdateSabataAttack の通信版)
void PlayerLink_UpdateSabataAttack(Player* p) {
  if (p->action != PACT_ATTACK) {
    PlayerLink_SetAction(p, PACT_ATTACK, 0);
  }

  switch (p->state) {
    case 0: {
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        PlayerLink_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        if (p->ene <= 9) {
          Sound_PlayForPlayer(p->inputIdx, SE_GUN_MISFIRE);
          PlayerLink_SetAction(p, PACT_ATTACK, 5);
        } else {
          if (!(p->input->down & B_BUTTON)) {
            Sound_PlayForPlayer(p->inputIdx, SE_SABATA_FIRE);
            PlayerLink_SetAction(p, PACT_ATTACK, 5);
          } else {
            PlayerLink_SetAction(p, PACT_ATTACK, 2);
          }
          Bullet_Create(p, 230, 170, 0, 32, 50, 32, HBATTR_DARK, 30, 5, 10, FALSE);
        }
      }
      break;
    }
    case 2: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->stateTimer == 6) {
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_CHARGING);
      }
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, SE_SABATA_FIRE);
        PlayerLink_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= 30) {
        p->wpn.charge = 1;
        p->flashPlttID = 290;
        p->plttFlashTimer = 36;
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_CHARGED);
        PlayerLink_SetAction(p, PACT_ATTACK, 4);
      }
      break;
    }
    case 4: {
      PlayerLink_FaceInputDir(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        Sound_PlayForPlayer(p->inputIdx, VO_SABATA_TAKETHIS);
        p->wpn.timer = ((8 - p->facing) & 7) << 5;
        Hitbox_SetAttack(&p->wpn.hitbox, PlayerLink_GetAttackPower(p), 32, HBSRC_GUN, HBATTR_DARK, 30);
        Sound_PlayForPlayer(p->inputIdx, SE_GUN_SPREAD);
        PlayerLink_SetAction(p, PACT_ATTACK, 8);
      }
      break;
    }
    case 5: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0]) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer > 14) {
        p->wpn.unk_ae[0] = 0;
        PlayerLink_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1));
      if (++p->stateTimer > 4) {
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
    case 8: {
      Vec3 pos;
      s32 angle;

      p->unk_3d1 = 0;
      if (PlayerLink_FaceInputDir(p)) {
        PlayerLink_SetMoveDelta(p, 6);
      }
      if (!(p->stateTimer & 3)) {
        Vec3 ofs;
        Vec3 size;

        VEC3_SET(ofs, 0, 0, 0);
        VEC3_SET(size, 32, 0, 32);
        DustManager_Spawn(&p->mover.pos, &ofs, &size, 1, 2, 4);
      }
      p->wpn.timer = (p->wpn.timer + 16) & 0xFF;
      PlayerLink_ShowGunSpread(p, p->wpn.timer, &p->mover.pos);
      pos = p->mover.pos;
      angle = (416 - p->wpn.timer) & 0xFF;
      pos.x += POLAR_X(170, angle);
      pos.y += 230;
      pos.z += POLAR_Z(170, angle);
      Hitbox_SetPos(&p->wpn.hitbox, &pos, 0);
      p->wpn.hitbox.angle = angle;
      Hitbox_Register(&p->wpn.hitbox);
      p->facing = ((271 - p->wpn.timer) & 0xFF) >> 5;
      PlayerLink_SetAnimFacing(p);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (!(p->stateTimer & 15)) {
        Sound_PlayForPlayer(p->inputIdx, SE_SABATA_SPIN);
      }
      if (++p->stateTimer >= p->wpn.charge << 5) {
        Sound_StopForPlayer(p->inputIdx, SE_GUN_SPREAD);
        PlayerLink_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
  }
  p->nextEnchantColorIdx = 9;
}

void FUN_080d4494(Player* p) {
  if (p->action != PACT_ATTACK) {
    PlayerLink_SetAction(p, PACT_ATTACK, 0);
  }
  p->attackCB(p);
}

// ダイナマイトの魔法, 太陽ゲージが足りていれば爆弾を1個出し, 以降は発動したかどうかで演出を振り分ける
void PlayerLink_UpdateDynamite(Player* p) {
  if (p->action != PACT_DYNAMITE) {
    if (p->elevatorFlags != 0) {
      p->magicFired = FALSE;
    } else if (PlayerLink_HasEnoughLux(p, 3)) {
      p->magicFired = TRUE;
      DynamiteEffect_Create(p, &p->mover.pos, 0);
    } else {
      p->magicFired = FALSE;
    }
    PlayerLink_SetAction(p, PACT_DYNAMITE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->flashPlttID = 291;
        p->plttFlashTimer = 32;
      }
      if (PlayerLink_PlayAnim(p, 184, Q6(1))) {
        if (p->magicFired) {
          PlayerLink_SetAction(p, PACT_DYNAMITE, 1);
        } else {
          PlayerLink_SetAction(p, PACT_DYNAMITE, 2);
        }
      }
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->flashPlttID = 291;
        p->plttFlashTimer = 32;
      }
      p->stateTimer++;
      if (p->stateTimer > 11) {
        PlayerLink_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        Sound_PlayForPlayer(p->inputIdx, SE_NG);
      }
      PlayerLink_PlayAnim(p, 194, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 11) {
        PlayerLink_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 3: {
      if (PlayerLink_PlayAnim(p, 189, Q6(1))) {
        PlayerLink_SetAction(p, PACT_IDLE, 1);
      }
      break;
    }
  }
}

// 人型の落下 (PACT_FALL), カメラを上に向けて落下アニメを当て, 6フレーム後に沈み始めて途中で声を上げ, 30 フレームで消える
void PlayerLink_UpdateFall(Player* p) {
  PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Vec3 pos = p->mover.pos;

      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->fallFadeMode != 0) {
        StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 16);
      } else {
        StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 1);
      }
      Sound_PlayForPlayer(p->inputIdx, SE_FALL_SURPRISE);
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlayerLink_SetAction(p, PACT_FALL, 1);
      p->floatHeight = 0;
      break;
    }
    case 1: {
      if (++p->stateTimer > 5) {
        PlayerLink_SetAction(p, PACT_FALL, 2);
        p->floatHeight = 0;
        p->beast.priority = 1;
        Sound_PlayForPlayer(p->inputIdx, SE_FALL_430);
      }
      break;
    }
    case 2: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 60;
      if (p->stateTimer == 4) {
        if (p->kind == PLAYER_SABATA) {
          Sound_PlayForPlayer(p->inputIdx, VO_SABATA_PITFALL);
        } else {
          Sound_PlayForPlayer(p->inputIdx, VO_DJANGO_PITFALL);
        }
      }
      if (++p->stateTimer > 29) {
        PlayerLink_SetAction(p, PACT_FALL, 3);
      }
      break;
    }
    case 3: {
      p->floatHeight = 0;
      PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// 被弾 (PACT_DAMAGED), 吹き飛ばされて止まったら PACT_SEKIKA か PACT_IDLE に戻る, knockbackOrigin から弾かれたときはそちらへ寄せながら炎を出す
void PlayerLink_UpdateHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PlayerLink_SetAction(p, PACT_DAMAGED, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
    if (p->hurtSound != SONG_NONE) {
      Sound_PlayForPlayer(p->inputIdx, p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
  }
  if (p->hurtbox.knockback != 0) {
    if (p->originKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          Sound_PlayForPlayer(p->inputIdx, SE_IGNITE);
          Entity080acd4c_Spawn(&p->mover.pos);
        }
        p->stateTimer++;
      }
    } else {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
    }
    Camera_Shake(p->hurtbox.knockback);
    p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
  } else {
    p->hurtbox.knockback = 0;
    p->originKnockback = FALSE;
    if (p->emitter.kind == ELEMCOND_SEKIKA && p->emitter.aliveCount != 0) {
      PlayerLink_SetAction(p, PACT_SEKIKA, 0);
    } else if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 42), Q6(1))) {
      PlayerLink_SetAnimFacing(p);
      PlayerLink_SetAction(p, PACT_IDLE, 0);
    }
  }
}

// PACT_BLOWN_AWAY, 宙に浮いて後ろへ飛び, 着地して倒れたあと起き上がって PACT_IDLE に戻る
void PlayerLink_UpdateBlownAway(Player* p) {
  if (p->action != PACT_BLOWN_AWAY) {
    PlayerLink_SetAction(p, PACT_BLOWN_AWAY, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      Sound_PlayForPlayer(p->inputIdx, p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
  }

  switch (p->state) {
    case 0: {
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      if (++p->stateTimer > 2) {
        PlayerLink_SetAction(p, PACT_BLOWN_AWAY, 1);
      }
      break;
    }
    case 1: {
      s32 angle;

      if (p->stateTimer == 0) {
        p->floatHeight = 300;
      }
      PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 43), Q6(1));
      angle = ((p->facing + 5) & 7) << 5;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
      if (p->stateTimer > 3) {
        if (p->floatHeight >= p->stateTimer * 8) {
          p->floatHeight -= p->stateTimer * 8;
        } else {
          p->floatHeight = 0;
        }
      }
      p->stateTimer++;
      if (p->hurtbox.knockback < 20 && p->floatHeight == 0) {
        p->floatHeight = 0;
        Sound_PlayForPlayer(p->inputIdx, SONG_680);
        PlayerLink_SetAction(p, PACT_BLOWN_AWAY, 2);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->hurtbox.knockback = 0;
        PlayerLink_SetAction(p, PACT_BLOWN_AWAY, 3);
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 19) {
        PlayerLink_SetAction(p, PACT_BLOWN_AWAY, 4);
      }
      break;
    }
    case 4: {
      if (PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 45), Q6(1))) {
        p->blownAway = 0;
        PlayerLink_SetAnimFacing(p);
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

NAKED void FUN_080d4d34(Player* p) { INCFUNC("asm/func/FUN_080d4d34.inc"); }

NAKED void FUN_080d4fa4(Player* p) { INCFUNC("asm/func/FUN_080d4fa4.inc"); }

NAKED void FUN_080d53e4(Player* p) { INCFUNC("asm/func/FUN_080d53e4.inc"); }

// サバタのゼロシフト, 16フレームの間 食らい判定を消して点滅しながら前へ進む
void PlayerLink_ZeroShift(Player* p) {
  if (p->action != PACT_DASH) {
    PlayerLink_SetAction(p, PACT_DASH, 0);
    Sound_PlayForPlayer(p->inputIdx, SE_M_ZEROSHIFT);
  }
  PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  if (++p->stateTimer >= 16) {
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  } else {
    PlayerLink_SetFlag35a(p, PFLAG35A_BLINK);
    if (p->stateTimer >= 5 && p->stateTimer <= 12) {
      PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_BODY);
    }
    PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
    p->flashPlttID = OBP_ELEMENT(6);
    p->plttFlashTimer = 24;
    if (!p->useForcedDelta) {
      PlayerLink_SetMoveDelta(p, 32);
    }
    PlayerLink_SetAnimFacing(p);
    PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
  }
}

// 魔法チェンジ・マウス, 点滅が消えている間だけ本体を隠して beast のネズミを出し, 31フレームでマウスのフォームへ切り替える
void PlayerLink_ChangeMouse(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_CMOUSE) {
    PlayerLink_SetAction(p, PACT_CMOUSE, 0);
    p->plttFlashTimer = 0;
    PlayerLink_ClearElementalCond(p);
    Sound_PlayForPlayer(p->inputIdx, SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    Sound_PlayForPlayer(p->inputIdx, SE_M_CMOUSE);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->beast.pos = p->mover.pos;
  }

  PlayerLink_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  p->flashPlttID = 290;
  p->plttFlashTimer += 3;
  if (p->plttFlashTimer > 32) {
    p->plttFlashTimer = 32;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->mouseAnim, 0, p->animDir, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  Video_SetAuxSpritePltt(p->beastGfx, 290);
  p->stateTimer++;
  if (p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_MOUSE;
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの待機 (PACT_IDLE), マウスのアニメを向きに合わせて1コマ進める
void PlayerLink_UpdateMouseIdle(Player* p) {
  p->flag20 &= ~PFLAG20_BUSY;
  if (p->action != PACT_IDLE) {
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
}

s32 PlayerLink_GetMouseWalkSpeed(Player* p) {
  s32 v = 12;

  if (p->emitter.kind == ELEMCOND_HYOKETU && p->emitter.aliveCount != 0) {
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

// マウスの歩き (PACT_WALK), 入力方向へ向きと移動量を合わせてアニメ 1 を進め, 2コマ目の頭で左右交互の足音を鳴らす
void PlayerLink_UpdateMouseWalk(Player* p) {
  if (p->action != PACT_WALK) {
    p->mouseStepAlt = 0;
    PlayerLink_SetAction(p, PACT_WALK, 0);
  }
  p->flag20 &= ~PFLAG20_BUSY;
  p->facing = PlayerLink_ResolveInputFacing(p);
  PlayerLink_SetMoveDelta(p, PlayerLink_GetMouseWalkSpeed(p));
  PlayerLink_SetAnimFacing(p);
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 1, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->beastAnim.cmdIdx == 2 && p->beastAnim.tick == 0) {
    if (p->mouseStepAlt) {
      p->mouseStepAlt = 0;
      Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_MINI_0);
    } else {
      p->mouseStepAlt = 1;
      Sound_PlayForPlayer(p->inputIdx, SE_FSTEP_MINI_1);
    }
  }
}

// マウスの PACT_WALL, 入った瞬間に前方 64 上方 64 の位置へ Player_MakeNoise で SE_M_CMOUSE の演出を出し, アニメ 0 を進めて 16 フレームで PACT_IDLE に戻る
void PlayerLink_UpdateMouseMakeNoise(Player* p) {
  if (p->action != PACT_WALL) {
    Vec3 pos = p->mover.pos;
    s32 angle = ((p->facing + 5) & 7) * 32;

    pos.x += POLAR_X(64, angle);
    pos.y += 64;
    pos.z += POLAR_Z(64, angle);
    PlayerLink_SetAction(p, PACT_WALL, 0);
    PlayerLink_MakeNoise(p, &p->mover.pos, 1, 1, &pos, 0, SE_M_CMOUSE);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->stateTimer++;
  if (p->stateTimer > 15) {
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの PACT_SPIDER_WEB, 方向入力に向きを合わせてアニメ 2 を1コマ進め, spiderWebIdx が空いたら PACT_IDLE に戻る
void PlayerLink_UpdateMouseSpiderWeb(Player* p) {
  if (p->action != PACT_SPIDER_WEB) {
    PlayerLink_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  if ((s16)p->facingHistory[0] >= 0) {
    p->facing = p->facingHistory[0];
    p->facing = (p->facing & 0xFE) + 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->spiderWebIdx < 0) {
    PlayerLink_SetAnimFacing(p);
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの PACT_LANDING, heightAboveTile を毎フレーム 30 ずつ減らして落下し, 着地したらアニメ 3 を一巡させて PACT_IDLE に戻る
void PlayerLink_UpdateMouseLanding(Player* p) {
  PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  switch (p->state) {
    case 0: {
      p->facing |= 1;
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if ((u16)p->heightAboveTile <= 30) {
        p->heightAboveTile = 0;
        Sound_PlayForPlayer(p->inputIdx, SE_LANDING);
        p->state = 1;
      } else {
        p->heightAboveTile -= 30;
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 3, p->animDir, p->xflip);
      if (AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim)) {
        PlayerLink_SetAnimFacing(p);
        PlayerLink_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// マウスの被弾 (PACT_DAMAGED), アニメ 2 を進めながら吹き飛び, knockbackOrigin から弾かれたときはそちらへ寄せながら炎を出し, 止まったら PACT_SEKIKA か PACT_IDLE に戻る
void PlayerLink_UpdateMouseHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      Sound_PlayForPlayer(p->inputIdx, p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
    PlayerLink_SetAction(p, PACT_DAMAGED, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->hurtbox.knockback != 0) {
    if (p->originKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          Sound_PlayForPlayer(p->inputIdx, SE_IGNITE);
          Entity080acd4c_Spawn(&p->mover.pos);
        }
        p->stateTimer++;
      }
    } else {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
    }
    Camera_Shake(p->hurtbox.knockback);
    p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
  } else {
    p->hurtbox.knockback = 0;
    p->originKnockback = FALSE;
    if (p->emitter.kind == ELEMCOND_SEKIKA && p->emitter.aliveCount != 0) {
      PlayerLink_SetAction(p, PACT_SEKIKA, 0);
    } else {
      PlayerLink_SetAnimFacing(p);
      PlayerLink_SetAction(p, PACT_IDLE, 0);
    }
  }
}

// マウスのままチェンジ・マウスを使ったとき (PACT_CMOUSE), 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ戻す
void PlayerLink_UndoChangeMouse(Player* p) {
  if (p->action != PACT_CMOUSE) {
    PlayerLink_SetAction(p, PACT_CMOUSE, 0);
    p->plttFlashTimer = 0;
    PlayerLink_ClearElementalCond(p);
    Sound_PlayForPlayer(p->inputIdx, SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
  }

  PlayerLink_PlayAnim(p, 199, Q6(1));
  p->human.pltt = &gObjPlttData[290 * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->flashPlttID = 290;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_BDJANGO;
    PlayerLink_SetAction(p, PACT_IDLE, 0);
  }
}

// 入力方向の履歴を1つずらして今フレームの向きを先頭に入れる (Player_PushFacingHistory と同じ)
void PlayerLink_PushFacingHistory(Player* p) {
  s32 i;

  for (i = 9; i > 0; i--) {
    p->facingHistory[i] = p->facingHistory[i - 1];
  }

  p->facingHistory[0] = Player_GetDpadFacing(p);
  if ((s16)p->facingHistory[0] >= 0) {
    p->facingHistory[0] = ((s16)p->facingHistory[0] + p->controlUp + 7) & 7;
  }
}

// 壁張り付きを続けるか, 壁の方 (actionDir とその両隣) へ入力していて壁側のタイルが 200 以上高ければ TRUE, そうでなければ壁から離れる向きにして PACT_IDLE に戻す
s32 PlayerLink_CanKeepWall(Player* p) {
  s32 dir;
  s32 left;
  s32 right;

  if (p->wallLockCount != 0) {
    return TRUE;
  }
  dir = p->actionDir;
  left = (dir + 7) & 7;
  right = (dir + 9) & 7;
  if ((s16)p->facingHistory[0] == dir || (s16)p->facingHistory[0] == left || (s16)p->facingHistory[0] == right) {
    s32 angle = ((p->actionDir + 1) & 7) << 5;
    WorldPos pos = p->mover.pos;
    u32 height;

    pos.x -= POLAR_X(50, angle);
    pos.z -= POLAR_Z(50, angle);
    height = TileHeightAt(&pos);
    if (height >= p->mover.pos.y + 200) {
      return TRUE;
    }
    p->facing = (p->actionDir + 4) & 7;
    PlayerLink_SetAnimFacing(p);
    p->action = PACT_IDLE;
  } else {
    p->facing = (dir + 4) & 7;
    PlayerLink_SetAnimFacing(p);
    p->action = PACT_IDLE;
  }
  return FALSE;
}

// 入力と状態からこのフレームの行動を決める (Player_DecideAction の通信版, 棺桶・クモの巣・壁張り付きの維持などを省いたもの)
s32 PlayerLink_DecideAction(Player* p) {
  s32 action = p->action;

  if (!HasGoodCond(p, GOOD_MINI) && (p->input->pressed & L_BUTTON)) {
    action = PlayerLink_GetMagicAction(p);
  }
  if (p->hurtbox.knockback != 0) {
    action = p->blownAway ? PACT_BLOWN_AWAY : PACT_DAMAGED;
    Player_StopChargeAndLookAround(p);
    return action;
  }
  if (!(action == PACT_DAMAGED || action == PACT_BLOWN_AWAY || action == PACT_FALL || action == PACT_LANDING || action == PACT_GRABBED || action == PACT_SPIDER_WEB || action == PACT_SEKIKA) && p->mashRecoverTimer != 0) {
    action = PACT_UNK_18;
  }
  switch (action) {
    case PACT_WALL: {
      if (!PlayerLink_CanKeepWall(p)) {
        action = PACT_IDLE;
      }
      break;
    }
    case PACT_PUSH:
    case PACT_PULL_COFFIN:
    case PACT_REFUELING:
    case PACT_SUN_MAGIC:
    case PACT_TRANSFORM:
    case PACT_CWOLF:
    case PACT_CBAT:
    case PACT_SLEEPING:
    case PACT_HEALING:
    case PACT_UNK_18:
    case PACT_SEKIKA:
    case PACT_SPIDER_WEB:
    case PACT_GRABBED:
    case PACT_UNK_32: {
      action = PACT_IDLE;
      break;
    }
    case PACT_DASH:
    case PACT_ATTACK:
    case PACT_UNK_7:
    case PACT_CMOUSE:
    case PACT_FREEZE:
    case PACT_DYNAMITE:
    case PACT_FALL:
    case PACT_LANDING:
    case PACT_DAMAGED:
    case PACT_BLOWN_AWAY: {
      break;
    }
    default: {
      if (HasGoodCond(p, GOOD_MINI)) {
        if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
          action = PACT_IDLE;
        } else {
          action = PACT_WALK;
        }
      } else if (p->input->pressed & B_BUTTON) {
        action = PACT_ATTACK;
      } else if (p->input->pressed & A_BUTTON) {
        if (MapItemManager_TryOpen(&p->mover)) {
          action = PACT_IDLE;
        } else {
          action = PACT_UNK_7;
        }
      } else if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
        action = PACT_IDLE;
      } else {
        action = PACT_WALK;
      }
      break;
    }
  }
  return action;
}

// 人の姿の毎フレームの後処理, 移動と食らい判定・表示フラグを反映し human を mover の位置に置く
void PlayerLink_PostUpdateHuman(Player* p) {
  if (p->elevatorFlags == 0) {
    if (PlayerLink_TestFlag35a(p, PFLAG35A_NO_TILE)) {
      p->mover.tile = NULL;
    } else if (p->mover.tile == NULL) {
      Map_InitMoverTile(&p->tile, &p->mover.pos);
      p->mover.tile = &p->tile;
    }
  }
  Mover_ApplyMove(&p->mover);

  if (PlayerLink_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBF_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBF_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->human.flags |= SPRFLAG_HIDDEN;
  } else {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_BLINK)) {
    p->human.flags |= SPRFLAG_BLINK_ODD;
  } else {
    p->human.flags &= ~SPRFLAG_BLINK_ODD;
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->beast.flags |= SPRFLAG_HIDDEN;
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }

  p->mover.pos.y += p->heightAboveTile;
  p->human.pos = p->mover.pos;
  p->human.pos.y += p->floatHeight;
}

// 通信対戦のジャンゴの毎フレーム更新, 黒ジャンゴは自分の光ゲージで焼け, 行動ごとに gLinkDjangoActionFuncs の関数を呼ぶ (Player_UpdateCrossoverDjango と同形)
// 残差1命令 (379/380): PlayerLink_UpdateMouse と同じく, 原典は光ゲージの値を r0 で作って r1 へ写す (サバタ版の (lux + 1) >> 1 は一致する)
// 試済: u8 / s32 のローカル, 光ゲージを読む inline (u32 返し), 引数に三項演算子
NON_MATCH void PlayerLink_UpdateDjango(Player* p) {
#ifdef NONMATCHING_C
  s32 action;

  Player_SetFlag20(p, PFLAG20_UPDATED);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Vec3 pos;
      s32 angle;
      s32 height;
      s32 attr;
      bool32 busy;
      u16 n;
      bool32 canStep;

      if (p->kind == PLAYER_BDJANGO && (p->flag20 & PFLAG20_SUNBATHING)) {
        u32 i = p->inputIdx;
        s32 lux;

        if (gLinkSession == NULL) {
          lux = 0;
        } else {
          lux = gLinkSession->luxGauge[i];
        }
        PlayerLink_StepSunburn(p, lux);
      }

      PlayerLink_PushFacingHistory(p);
      action = PlayerLink_DecideAction(p);
      PlayerLink_HandleLookAround(p, action);
      gLinkDjangoActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      PlayerLink_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        PlayerLink_UpdateCameraLookAt(p);
      }
      PlayerLink_CheckLavaHurt(p);
      PlayerLink_UpdateIceSlide(p);

      n = p->goodCondTimer;
      busy = FALSE;
      if (n != 0 && p->goodCondID == GOOD_MINI) {
        busy = TRUE;
      }
      if (busy) {
        return;
      }

      canStep = !PlayerLink_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
      if (canStep) {
        if (++p->wallPressTimer == 5) {
          pos = p->mover.pos;
          angle = ((p->facing + 5) & 7) * 32;
          pos.x += POLAR_X(50, angle);
          pos.z += POLAR_Z(50, angle);

          height = TileHeightAt(&pos);
          if ((u32)height >= (u32)(p->mover.pos.y + Q8(0.782))) {
            attr = GetTileAttrAt(&pos);
            if (!(attr & TATTR_UNK_2)) {
              p->actionDir = p->facing;
              p->wallSidling = 0;
              p->action = PACT_WALL;
              p->state = 0;
            }
          }
        }
      } else {
        p->wallPressTimer = 0;
      }
      break;
    }
    case PMODE_UNK_3: {
      PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action == PACT_FALLDEATH) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_DEATH_SUPINE : PACT_DEATH_PRONE;
      }
      gLinkDjangoActionFuncs[action](p);
      PlayerLink_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      PlayerLink_PostUpdateHuman(p);
      break;
    }
  }
#else
  INCFUNC("asm/func/PlayerLink_UpdateDjango.inc");
#endif
}

// 通信対戦のサバタの毎フレーム更新, 行動ごとに gLinkSabataActionFuncs の関数を呼び, 壁にまっすぐ歩き当たり続けたら壁張り付きに入る (Player_UpdateCrossoverDjango と同形)
void PlayerLink_UpdateSabata(Player* p) {
  s32 action;

  Player_SetFlag20(p, PFLAG20_UPDATED);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Vec3 pos;
      s32 angle;
      s32 height;
      s32 attr;
      bool32 busy;
      u16 n;
      bool32 canStep;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        u32 i = p->inputIdx;
        s32 lux;

        if (gLinkSession == NULL) {
          lux = 0;
        } else {
          lux = gLinkSession->luxGauge[i];
        }
        PlayerLink_StepSunburn(p, (lux + 1) >> 1);
      }

      PlayerLink_PushFacingHistory(p);
      action = PlayerLink_DecideAction(p);
      PlayerLink_HandleLookAround(p, action);
      gLinkSabataActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      PlayerLink_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        PlayerLink_UpdateCameraLookAt(p);
      }
      PlayerLink_CheckLavaHurt(p);
      PlayerLink_UpdateIceSlide(p);

      n = p->goodCondTimer;
      busy = FALSE;
      if (n != 0 && p->goodCondID == GOOD_MINI) {
        busy = TRUE;
      }
      if (busy) {
        return;
      }

      canStep = !PlayerLink_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
      if (canStep) {
        if (++p->wallPressTimer == 5) {
          pos = p->mover.pos;
          angle = ((p->facing + 5) & 7) * 32;
          pos.x += POLAR_X(50, angle);
          pos.z += POLAR_Z(50, angle);

          height = TileHeightAt(&pos);
          if ((u32)height >= (u32)(p->mover.pos.y + Q8(0.782))) {
            attr = GetTileAttrAt(&pos);
            if (!(attr & TATTR_UNK_2)) {
              p->actionDir = p->facing;
              p->wallSidling = 0;
              p->action = PACT_WALL;
              p->state = 0;
            }
          }
        }
      } else {
        p->wallPressTimer = 0;
      }
      break;
    }
    case PMODE_UNK_3: {
      PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action == PACT_FALLDEATH) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_DEATH_SUPINE : PACT_DEATH_PRONE;
      }
      gLinkSabataActionFuncs[action](p);
      PlayerLink_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      PlayerLink_PostUpdateHuman(p);
      break;
    }
  }
}

// マウスの行動を入力から決める (Player_GetMouseAction からクモの巣の処理を除いたもの)
s32 PlayerLink_GetMouseAction(Player* p) {
  u32 action;
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = PlayerLink_GetMagicAction(p);
  }
  if (p->hurtbox.knockback != 0) {
    action = PACT_DAMAGED;
  } else if (action != PACT_DAMAGED && action != PACT_SPIDER_WEB && action != PACT_SEKIKA && action != PACT_LANDING && action != PACT_WALL && action != PACT_CMOUSE) {
    struct Input* input = p->input;
    if (input->pressed & A_BUTTON) {
      if (MapItemManager_TryOpen(&p->mover)) {
        action = PACT_IDLE;
      } else {
        action = PACT_WALL;
      }
    } else if ((s16)p->facingHistory[0] == -1 || (input->down & R_BUTTON)) {
      action = PACT_IDLE;
    } else {
      action = PACT_WALK;
    }
  }
  return action;
}

// マウス時の毎フレームの後処理, 移動と食らい判定を反映し beast を mover の位置に置く
void PlayerLink_PostUpdateMouse(Player* p) {
  Mover_ApplyMove(&p->mover);

  if (PlayerLink_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBF_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBF_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->beast.flags |= SPRFLAG_HIDDEN;
  } else {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  }

  if (PlayerLink_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->human.flags |= SPRFLAG_HIDDEN;
  }

  p->mover.pos.y += p->heightAboveTile;
  p->beast.pos = p->mover.pos;
  p->beast.pos.y += p->floatHeight;
}

// (Cマウスによる)ネズミ形態の毎フレーム更新, 行動ごとに gLinkMouseActionFuncs の関数を呼ぶ
// 残差1命令 (84/85), 原典は光ゲージの値を r0 で作ってから r1 へ写すがこちらは r1 に直接作る
// 試済: 光ゲージを読む inline (if/else, 三項演算子, u8 返し), ローカル経由
NON_MATCH void PlayerLink_UpdateMouse(Player* p) {
#ifdef NONMATCHING_C
  Player_SetFlag20(p, PFLAG20_UPDATED | PFLAG20_SNEAKING | PFLAG20_UNK_18);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        u32 i = p->inputIdx;
        s32 lux;

        if (gLinkSession == NULL) {
          lux = 0;
        } else {
          lux = gLinkSession->luxGauge[i];
        }
        PlayerLink_StepSunburn(p, lux);
      }

      PlayerLink_PushFacingHistory(p);
      action = PlayerLink_GetMouseAction(p);
      PlayerLink_HandleLookAround(p, action);
      gLinkMouseActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      PlayerLink_PostUpdateMouse(p);
      if (p->lookAroundOffset.val) {
        PlayerLink_UpdateCameraLookAt(p);
      }
      PlayerLink_CheckLavaHurt(p);
      PlayerLink_UpdateIceSlide(p);
      break;
    }
    case PMODE_LOCKED: {
      PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      PlayerLink_PostUpdateMouse(p);
      break;
    }
  }
#else
  INCFUNC("asm/func/PlayerLink_UpdateMouse.inc");
#endif
}

// ignoreMask の立っているビットのプレイヤーを返す, 無ければ1人目
Player* PlayerLink_GetHitboxOwner(Hitbox* hitbox) {
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

// 通信対戦の被弾処理, 吹き飛ばしと状態異常を入れてダメージを damage に足し, 当てたプレイヤーと攻撃元を覚える (Player_HandleHurt の通信版, フレイム/フロスト属性で引火/氷結, クラウド属性でコインを落とす)
u32 PlayerLink_HandleHurt(Player* p, Hitbox* a, Hitbox* b) {
  s32 shift;
  u32 dmg;
  s32 power;

  power = a->power;
  if (power > 0) {
    Hitbox_ApplyDamageAlt(a, b);
  } else {
    b->damage = 0;
  }
  b->iframes = a->iframes;

  shift = 0;

  if (a->knockback == 0) {
    p->hurtSound = SONG_NONE;
  } else {
    p->hurtSound = SE_DAMAGE;
    if (p->kind == PLAYER_MOUSE && p->action == PACT_CMOUSE) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_BDJANGO;
    }
    if (HasGoodCond(p, GOOD_INVISIBLE)) {
      p->goodCondID = 0;
      p->goodCondTimer = 0;
      p->beast.flags &= ~SPRFLAG_BLINK_EVEN;
    }
    PlayerLink_SetupKnockback(p, a, b);
  }

  if (Hitbox_TestAttr(a, HBATTR_CLOUD)) {
    LinkSession_ReleaseCoin(&p->mover.pos, p->inputIdx);
  }

  if (HasGoodCond(p, GOOD_GAMAN)) {
    b->damage = 0;
    dmg = 0;
    if (Hitbox_TestAttr(a, HBATTR_BLOW)) {
      PlayerLink_ClearElementalCond(p);
    }
  } else {
    // これらの場合は2倍のダメージを受ける
    if (HasGoodCond(p, GOOD_MINI) || p->action == PACT_DASH || p->kind == PLAYER_MOUSE) {
      shift++;
    }

    if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (!p->blownAway) p->hurtSound = SE_IGNITE;
        Player_InflictElementalCond(p, ELEMCOND_INKA);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_FROST)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (!p->blownAway) p->hurtSound = SE_SOLIDIFY;
        Player_InflictElementalCond(p, ELEMCOND_HYOKETU);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_BLOW)) {
      PlayerLink_ClearElementalCond(p);
    }
    if (Hitbox_TestAttr(a, HBATTR_POISON)) {
      Player_ApplyBadCondition(p, BAD_POISON, SECOND(30));
    }
    if (Hitbox_TestAttr(a, HBATTR_CONFUSE)) {
      Player_ApplyBadCondition(p, BAD_CONFUSE, SECOND(15));
    }
    if (Hitbox_TestAttr(a, HBATTR_17)) {
      Vec3 v;
      u32 angle = ((p->facing + 5) & 7) * 32;
      v.x = POLAR_X(Q8(0.313), angle);
      v.y = Q8(0.782);
      v.z = POLAR_Z(Q8(0.313), angle);
      SpawnBlood(&p->mover.pos, &v, 0, 0, 1);
    }

    dmg = b->damage << shift;
    b->damage = 0;
    if (!(a->typeMask & HBSRC_GUN) && Hitbox_TestIgnoreMask(a, 0xF)) {
      if (Hitbox_TestAttr(a, HBATTR_EARTH)) {
        FUN_080d7474(PlayerLink_GetHitboxOwner(a), dmg);
      }
      if (Hitbox_TestAttr(a, HBATTR_DARK)) {
        FUN_080d74e8(PlayerLink_GetHitboxOwner(a), dmg);
      }
    }
    p->damage += dmg;
  }
  p->lastHitPlayerMask = a->ignoreMask;
  p->lastHitSource = a->typeMask;
  return dmg;
}

// 食らい判定に当たったときのコールバック, 多段/1回限りの判定を処理して PlayerLink_HandleHurt へ渡す (Django_OnHurt からトゲの反撃を除いたもの)
void PlayerLink_OnHurt(Hitbox* a, Hitbox* b, Player* p) {
  if (p->mode == PMODE_ACTIVE) {
    if (Hitbox_TestFlags(a, HBF_9)) {
      if ((b->hitState & HBHITSTATE_UNK_0) == 0) {
        return;
      }
      b->hitState &= ~HBHITSTATE_UNK_0;
    }
    if (Hitbox_TestFlags(a, HBF_ONCE)) {
      if (b->hitState & HBHITSTATE_ONCE_HIT) {
        return;
      }
      b->hitState |= HBHITSTATE_ONCE_HIT;
    }
    PlayerLink_HandleHurt(p, a, b);
  }
}

NAKED s32 FUN_080d78dc(Player* p) { INCFUNC("asm/func/FUN_080d78dc.inc"); }

// 無敵時間中は食らい判定を消し, 吹き飛ばされていなければ1減らして4フレームおきに点滅させる
void PlayerLink_UpdateIframes(Player* p) {
  s32 n = Player_GetIframes(p);

  if (n > 0) {
    PlayerLink_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
    if (p->hurtbox.knockback == 0 && p->action != PACT_DAMAGED && p->action != PACT_BLOWN_AWAY) {
      n--;
      if (n != 0 && ((n >> 2) & 1)) {
        PlayerLink_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      p->hurtbox.iframes = n;
    }
  }
}

s32 FUN_080d7bac(void) {
  if (VM_SeekToNamedArg('i') != 0) {
    return VM_GetValue();
  }
  return 0;
}

void FUN_080d7bc4(Player* p, s32 plttID) {
  p->flashPlttID = plttID;
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
