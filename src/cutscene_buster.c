#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sprite_aux.h"

// ロックマンイベントで、シェードマンを浄化するときのカットシーンで打つロックバスターのチャージショット

struct CutsceneBusterShot;
typedef void(CutsceneBusterShotFunc)(struct CutsceneBusterShot* p);

typedef struct {
  Particle ptcl;   // 0x00, PTCL2_17, パレット 1, オフセット (-4,-4)
  bool8 active;    // 0x28, 0 の間は動かさない
  s8 angleOffset;  // 0x29, dir から作る角度に足してばらつかせる
  u16 radius;      // 0x2A, 中心からの距離の基準
  u16 timer;       // 0x2C, 15 で寿命, 距離が radius * (16 - timer) >> 3 なので中心へ寄っていく
  u8 unk_2e[2];    // 0x2E, padding?
} CutsceneBusterShotPtcl;
static_assert(sizeof(CutsceneBusterShotPtcl) == 48);

typedef struct CutsceneBusterShot {
  Entity e;                                // 0x000, ENTITY_UNK_8
  Player* player;                          // 0x018
  AuxSprite sprite;                        // 0x01C
  AuxSpriteGfx gfx;                        // 0x048, SPRITE_EBALL_210E, パレット 46
  u16 velX;                                // 0x064, 毎フレーム sprite.pos.x に加算される
  u8 unk_66[2];                            // 0x066, まだ未解析
  u16 velZ;                                // 0x068, 毎フレーム sprite.pos.z に加算される
  u8 unk_6a[2];                            // 0x06A, まだ未解析
  u16 speed;                               // 0x06C, Init の第3引数, 向きと合わせて velX / velZ を作る
  Dir8U8 dir;                              // 0x06E, 着弾の絵と反転を決める
  bool8 charged;                           // 0x06F, チャージを終えると 1, poseIdx の基準になる
  u16 stateTimer;                          // 0x070, updateCallback を差し替えるたびに 0 に戻る
  u16 flyTime;                             // 0x072, Init の第4引数, この時間だけ飛んで着弾する
  u8 unk_74[3];                            // 0x074, まだ未解析
  u8 ptclIdx;                              // 0x077, 次に撒く ptcls の添字, 0..3 を回る
  ParticleGroup* group2;                   // 0x078, PTCL_GROUP_2
  CutsceneBusterShotPtcl ptcls[4];         // 0x07C
  CutsceneBusterShotFunc* updateCallback;  // 0x13C
} CutsceneBusterShot;
static_assert(sizeof(CutsceneBusterShot) == 320);

// 向きに合わせて着弾の絵と反転を選ぶ
static inline void AuxSprite_SetImpactPose(AuxSprite* spr, s32 dir) {
  if (dir & 1) {
    spr->poseIdx = 7;
  } else if ((dir >> 1) & 1) {
    spr->poseIdx = 8;
  } else {
    spr->poseIdx = 6;
  }
  if (dir <= 2) {
    spr->flags &= ~(SPRFLAG_XFLIP | SPRFLAG_YFLIP);
  } else if (dir <= 4) {
    spr->flags = (spr->flags & ~SPRFLAG_XFLIP) | SPRFLAG_YFLIP;
  } else if (dir <= 5) {
    spr->flags |= SPRFLAG_XFLIP | SPRFLAG_YFLIP;
  } else {
    spr->flags = (spr->flags | SPRFLAG_XFLIP) & ~SPRFLAG_YFLIP;
  }
}

void CutsceneBusterShot_SetUpdateCallback(CutsceneBusterShot* p, CutsceneBusterShotFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// プレイヤーの位置と向きから, 自分の位置と向き, 飛ぶときの進み幅を作り直す
void CutsceneBusterShot_Reposition(CutsceneBusterShot* p) {
  Player* player = p->player;
  s32 angle;
  s32 cosv;
  s32 sinv;

  p->sprite.pos = player->mover.pos;
  p->sprite.pos.y += 200;
  angle = ((player->facing + 5) & 7) * 32;
  cosv = COS(angle);
  sinv = SIN(angle);
  if (player->xflip) {
    p->sprite.pos.x += FixToInt(12, cosv * 170) + FixToInt(12, sinv * 8);
    p->sprite.pos.z += FixToInt(12, sinv * 170) - FixToInt(12, cosv * 8);
  } else {
    p->sprite.pos.x += FixToInt(12, cosv * 170) - FixToInt(12, sinv * 8);
    p->sprite.pos.z += FixToInt(12, sinv * 170) + FixToInt(12, cosv * 8);
  }
  p->dir = Angle_ToDir8Floor(angle);
  p->velX = FixToInt(12, COS(angle) * p->speed);
  p->velZ = FixToInt(12, SIN(angle) * p->speed);
}

// 集まる粒子を寿命まで動かす, 距離が毎フレーム縮むので中心へ吸い込まれていく
void CutsceneBusterShot_UpdateParticles(CutsceneBusterShot* p) {
  s32 dirBase = ((p->dir + 5) & 7) * 32;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active) {
      p->ptcls[i].timer++;
      if (p->ptcls[i].timer > 14) {
        p->ptcls[i].active = FALSE;
        p->ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
      } else {
        s32 dist = p->ptcls[i].radius * (16 - p->ptcls[i].timer) >> 3;
        s32 angle = (dirBase + 0x100 + p->ptcls[i].angleOffset) & 0xFF;

        p->ptcls[i].ptcl.pos = p->sprite.pos;
        p->ptcls[i].ptcl.pos.x += POLAR_X(dist, angle);
        p->ptcls[i].ptcl.pos.z += POLAR_Z(dist, angle);
      }
    }
  }
}

// 粒子を 1 個, 向きと距離をばらつかせて撒く
void CutsceneBusterShot_SpawnParticle(CutsceneBusterShot* p) {
  s32 angle;

  p->ptcls[p->ptclIdx].active = TRUE;
  p->ptcls[p->ptclIdx].ptcl.flags &= ~SPRFLAG_HIDDEN;
  p->ptcls[p->ptclIdx].timer = 0;
  p->ptcls[p->ptclIdx].radius = ((RandomNext() >> 3) & 0x7F) + 0x40;
  p->ptcls[p->ptclIdx].angleOffset = Mod(RandomNext(), 0x60) - 0x30;
  angle = ((p->dir + 5) & 7) * 32;
  angle = (angle + 0x100 + p->ptcls[p->ptclIdx].angleOffset) & 0xFF;
  p->ptcls[p->ptclIdx].ptcl.pos = p->sprite.pos;
  p->ptcls[p->ptclIdx].ptcl.pos.x += POLAR_X(p->ptcls[p->ptclIdx].radius, angle);
  p->ptcls[p->ptclIdx].ptcl.pos.z += POLAR_Z(p->ptcls[p->ptclIdx].radius, angle);
  p->ptclIdx++;
  if (p->ptclIdx > 3) {
    p->ptclIdx = 0;
  }
}

void CutsceneBusterShot_HideParticles(CutsceneBusterShot* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->ptcls[i].active = FALSE;
    p->ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

void CutsceneBusterShot_StateFly(CutsceneBusterShot* p);

// プレイヤーの構えに付いていき, チャージ中は粒子を集め, 撃ったら飛ぶ状態へ移る
void CutsceneBusterShot_StateCharge(CutsceneBusterShot* p) {
  if (p->player->action != PACT_ATTACK) {
    KillEntity(&p->e);
    return;
  }
  CutsceneBusterShot_Reposition(p);
  if (p->player->state == 5) {
    CutsceneBusterShot_HideParticles(p);
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.poseIdx = p->charged;
    CutsceneBusterShot_SetUpdateCallback(p, CutsceneBusterShot_StateFly);
    return;
  }
  CutsceneBusterShot_UpdateParticles(p);
  if (p->player->state == 2) {
    if ((p->stateTimer & 3) == 3) {
      CutsceneBusterShot_SpawnParticle(p);
    }
    p->charged = 0;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->charged = 1;
  }
  p->sprite.poseIdx = (p->stateTimer >> 2) & 1 ? p->charged + 1 : p->charged;
  p->stateTimer++;
}

void CutsceneBusterShot_StateImpact(CutsceneBusterShot* p);

void CutsceneBusterShot_StateFly(CutsceneBusterShot* p) {
  p->sprite.pos.x += p->velX;
  p->sprite.pos.z += p->velZ;
  p->stateTimer++;
  if (p->stateTimer >= p->flyTime) {
    CutsceneBusterShot_SetUpdateCallback(p, CutsceneBusterShot_StateImpact);
  }
}

// 着弾の短い演出, 4 フレーム目に向きに合わせた絵にして 7 フレーム目で消える
void CutsceneBusterShot_StateImpact(CutsceneBusterShot* p) {
  p->stateTimer++;
  if (p->stateTimer == 1) {
    p->sprite.poseIdx = 4;
  } else if (p->stateTimer == 4) {
    AuxSprite_SetImpactPose(&p->sprite, p->dir);
  } else if (p->stateTimer > 6) {
    KillEntity(&p->e);
  }
}

s32 CutsceneBusterShot_Update(CutsceneBusterShot* p) {
  p->updateCallback(p);
  return 0;
}

s32 CutsceneBusterShot_Destroy(CutsceneBusterShot* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

void CutsceneBusterShot_InitSprite(CutsceneBusterShot* p) {
  AuxSpriteGfx* gfx = &p->gfx;
  AuxSprite* spr;

  Video_GetAuxSprite(gfx, SPRITE_EBALL_210E);
  spr = &p->sprite;
  AuxSprite_Add(spr, gfx, SPRFLAG_HIDDEN);
  spr->poseIdx = 0;
  Video_SetAuxSpritePltt(gfx, 46);
}

// 粒子 4 個を非表示のまま用意する
void CutsceneBusterShot_InitParticles(CutsceneBusterShot* p) {
  s32 i;

  p->ptclIdx = 0;
  p->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    Particle_Add(&p->ptcls[i].ptcl, p->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&p->ptcls[i].ptcl, -4, -4);
    Particle_SetPose(&p->ptcls[i].ptcl, p->group2, PTCL2_17);
    Particle_SetPltt(&p->ptcls[i].ptcl, 1);
    p->ptcls[i].active = FALSE;
  }
}

s32 CutsceneBusterShot_Init(CutsceneBusterShot* p, Player* player, u32 speed, u32 flyTime) {
  p->player = player;
  p->speed = speed;
  p->flyTime = flyTime;
  p->charged = 0;
  CutsceneBusterShot_InitSprite(p);
  CutsceneBusterShot_Reposition(p);
  CutsceneBusterShot_InitParticles(p);
  CutsceneBusterShot_SetUpdateCallback(p, CutsceneBusterShot_StateCharge);
  return 0;
}

CutsceneBusterShot* CutsceneBusterShot_Create(Player* player, u32 speed, u32 flyTime) {
  CutsceneBusterShot* p = CreateEntity(ENTITY_UNK_8, sizeof(CutsceneBusterShot));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneBusterShot_Update, CutsceneBusterShot_Destroy);
    if (CutsceneBusterShot_Init(p, player, speed, flyTime) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
