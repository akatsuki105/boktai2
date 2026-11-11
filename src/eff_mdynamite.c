#include "collision_map.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "link_session.h"
#include "map_inline.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"

// DynamiteEffect_InitParticles が 8個ばらまく粒子, Particle に角度と半径を足しただけ
typedef struct {
  Particle base;  // 0x00, Particle_Add などに Particle* として渡る
  u16 angle;      // 0x28, gSineTable[(angle + 0x40) & 0xFF] と gSineTable[angle & 0xFF] で x/z のオフセットを作る
  u16 radius;     // 0x2A, 上の sin に掛けて >> 12 する
} DynamiteEffectParticle;
static_assert(sizeof(DynamiteEffectParticle) == 44);

// 魔法"ダイナマイト"のエフェクト の 効果処理 及び 演出
typedef struct DynamiteEffect {
  Entity e;                                        // 0x000, ENTITY_UNK_8
  Player* owner;                                   // 0x018, Init の第2引数, owner->unk_3fb がこのエンティティの生存数カウンタ
  AuxSprite sprite;                                // 0x01C
  AuxSpriteGfx gfx;                                // 0x048, SPRITE_BOMB
  Vec3 pos;                                        // 0x064, Init が引数の Vec3 をまるごと写す
  DynamiteEffectParticle ptcls[8];                 // 0x06C, 根拠: DynamiteEffect_InitParticles の i=0..7 / stride 0x2C のループ
  ParticleGroup* group;                            // 0x1CC, PTCL_GROUP_2
  u16 mode;                                        // 0x1D0, Init の第4引数, 0 かどうかで fuseTimer の減り方と timeoutTimer の有無が変わる
  u16 phaseLen;                                    // 0x1D2, fuseTimer の初期値 / 3, カウントダウンを3段階に分けてスプライト番号を変える
  u16 fuseTimer;                                   // 0x1D4, 0 で爆発して KillEntity
  u16 timeoutTimer;                                // 0x1D6, mode == 0 のときだけ減り、0 で爆発せずに KillEntity
  u8 unk_1d8[2];                                   // 0x1D8, 読み書きするコードが見つかっていない
  u16 stateTimer;                                  // 0x1DA, DynamiteEffect_SetState が 0 に戻し、各状態が毎フレーム +1 する
  void (*updateCallback)(struct DynamiteEffect*);  // 0x1DC
} DynamiteEffect;
static_assert(sizeof(DynamiteEffect) == 480);

struct Explosion* Explosion_CreateWithAttrs(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 plttOffset, s32 delay);

void DynamiteEffect_StateFuse(DynamiteEffect* p);
void DynamiteEffect_StateSink(DynamiteEffect* p);

// まだセッションが無ければ 0
static inline u8 LinkSession_GetLuxGauge(s32 idx) {
  if (gLinkSession == NULL) {
    return 0;
  }
  return gLinkSession->luxGauge[idx];
}

void DynamiteEffect_SetState(DynamiteEffect* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// 炎の粒を渦を巻くように集め, 終わったら粒を隠してダイナマイトを見せる
void DynamiteEffect_StateGather(DynamiteEffect* p) {
  s32 i;

  if (++p->stateTimer >= 30) {
    for (i = 0; i < 8; i++) {
      p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
      DynamiteEffect_SetState(p, DynamiteEffect_StateFuse);
    }
    AuxSprite_Show(&p->sprite);
  } else {
    s32 numer = 32 - p->stateTimer;
    s32 denom = numer + 1;

    for (i = 0; i < 8; i++) {
      p->ptcls[i].angle = (p->ptcls[i].angle + 4) & 0xFF;
      p->ptcls[i].radius = Div(p->ptcls[i].radius * numer, denom);
      p->ptcls[i].base.pos.x = p->pos.x + POLAR_X(p->ptcls[i].radius, p->ptcls[i].angle);
      p->ptcls[i].base.pos.y = (30 - p->stateTimer) * Q8(0.04) + p->pos.y;
      p->ptcls[i].base.pos.z = p->pos.z + POLAR_Z(p->ptcls[i].radius, p->ptcls[i].angle);
      if (p->stateTimer == 8) {
        Particle_SetPose(&p->ptcls[i].base, p->group, PTCL2_FLAME_L);
      }
    }
  }
}

// 足元の高さまで落としながら導火線を減らし, 0 になったら十字の5か所で爆発する
void DynamiteEffect_StateFuse(DynamiteEffect* p) {
  s32 sun;

  if (gGameFlags & GAMEFLAG_LINK) {
    sun = LinkSession_GetLuxGauge(p->owner->inputIdx);
  } else {
    sun = gStat->sunGauge;
  }

  if (p->fuseTimer != 0) {
    if (p->mode != 0) {
      p->fuseTimer--;
    } else {
      if (sun > 0) {
        p->fuseTimer--;
      }
      if (p->timeoutTimer != 0) {
        p->timeoutTimer--;
      }
    }
  }

  if (GetTileAttrAt(&p->pos) & TATTR_FALLDEATH) {
    DynamiteEffect_SetState(p, DynamiteEffect_StateSink);
  } else {
    s32 height = TileHeightAt(&p->pos);

    if (height > p->pos.y) {
      p->fuseTimer = 0;
    } else if (height < p->pos.y) {
      if ((p->pos.y -= Q8(0.12)) < height) {
        p->pos.y = height;
      }
      p->sprite.pos = p->pos;
    }
  }

  if (p->fuseTimer < p->phaseLen) {
    p->sprite.poseIdx = (p->stateTimer & 3) + 20;
  } else if (p->fuseTimer < p->phaseLen * 2) {
    p->sprite.poseIdx = (p->stateTimer & 3) + 16;
  } else {
    p->sprite.poseIdx = (p->stateTimer & 3) + 12;
  }
  p->stateTimer++;

  if (p->fuseTimer == 0) {
    s32 power;
    s32 i;

    if (p->mode != 0) {
      power = 125;
    } else if (gGameFlags & GAMEFLAG_LINK) {
      power = p->owner->stats[STAT_SPIRIT] * 3 + sun * 10;
    } else {
      power = Div(p->owner->stats[STAT_SPIRIT], 10) * sun;
    }

    for (i = 0; i < 5; i++) {
      Vec3 pos = p->pos;

      pos.y += Q8(0.5);
      pos.x += Q8(0.25);
      pos.z += Q8(0.25);
      switch (i) {
        case 1: {
          pos.x += Q8(0.375);
          break;
        }
        case 2: {
          pos.z += Q8(0.375);
          break;
        }
        case 3: {
          pos.z -= Q8(0.375);
          break;
        }
        case 4: {
          pos.x -= Q8(0.375);
          break;
        }
      }
      Explosion_CreateWithAttrs(&pos, 0, power, 50, HBATTR_INKA | HBATTR_18 | HBATTR_NAMAKURA | HBATTR_FLAME, 30, 0, i * 4);
    }
    FUN_08240cf0(p->pos.x, p->pos.z, 0x400, 0, 1, 0xB546);
    p->owner->dynamiteCount--;
    KillEntity((Entity*)p);
  } else if (p->timeoutTimer == 0) {
    p->owner->dynamiteCount--;
    KillEntity((Entity*)p);
  }
}

// 水や穴のタイルに落ちたとき, 爆発せずに沈んで消える
void DynamiteEffect_StateSink(DynamiteEffect* p) {
  p->pos.y -= Q8(0.08);
  p->sprite.pos = p->pos;
  p->stateTimer++;
  if (p->stateTimer > 2) {
    p->owner->dynamiteCount--;
    KillEntity((Entity*)p);
  }
}

s32 DynamiteEffect_Update(DynamiteEffect* p) {
  p->updateCallback(p);
  return 0;
}

s32 DynamiteEffect_Destroy(DynamiteEffect* p) {
  s32 i;
  AuxSprite_Remove(&p->sprite);

  for (i = 0; i < 8; i++) {
    Particle_Remove((Particle*)&p->ptcls[i]);
  }

  return 0;
}

void DynamiteEffect_InitSprite(DynamiteEffect* p) {
  AuxSpriteGfx* gfx = &p->gfx;

  Video_GetAuxSprite(gfx, SPRITE_BOMB);
  AuxSprite_Add(&p->sprite, gfx, SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&p->sprite, 12);
  p->sprite.pos = p->pos;
  if (Map_IsBehindHigherTile(&p->sprite.pos, Q8(0.5))) {
    Video_SetAuxSpritePltt(gfx, OBP_WHITE_306);
    p->sprite.priority = 1;
  } else {
    p->sprite.priority = 2;
  }
}

void DynamiteEffect_InitParticles(DynamiteEffect* p) {
  u8 base = RandomNext();
  s32 i;

  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    Particle* ptcl = &p->ptcls[i].base;
    u16 rnd;

    Particle_Add(ptcl, p->group, 0);
    Particle_SetOffset(ptcl, -4, -4);
    Particle_SetPose(ptcl, p->group, PTCL2_FLAME_S);
    Particle_SetPltt(ptcl, 1);
    rnd = RandomNext();
    p->ptcls[i].angle = (base + i * 32 + (rnd & 0xF)) & 0xFF;
    p->ptcls[i].radius = (RandomNext() & 0x1FF) + Q8(1);
    ptcl->pos.x = p->pos.x + POLAR_X(p->ptcls[i].radius, p->ptcls[i].angle);
    ptcl->pos.y = Q8(1.172) + p->pos.y;
    ptcl->pos.z = p->pos.z + POLAR_Z(p->ptcls[i].radius, p->ptcls[i].angle);
    ptcl->priority = 2;
    ptcl->offsetZ = -20;
  }
}

s32 DynamiteEffect_Init(DynamiteEffect* p, Player* owner, Vec3* pos, s32 mode) {
  p->pos = *pos;
  p->owner = owner;
  p->mode = mode;
  DynamiteEffect_InitSprite(p);
  DynamiteEffect_InitParticles(p);
  p->owner->dynamiteCount++;
  if (p->mode != 0) {
    p->fuseTimer = SECOND(2);
  } else if (gGameFlags & GAMEFLAG_LINK) {
    p->fuseTimer = SECOND(1.5);
  } else {
    p->fuseTimer = SECOND(3);
  }
  p->phaseLen = Div(p->fuseTimer, 3);
  p->timeoutTimer = SECOND(15);
  PlaySound_082406e0(SE_M_DYNAMITE);
  DynamiteEffect_SetState(p, DynamiteEffect_StateGather);
  return 0;
}

DynamiteEffect* DynamiteEffect_Create(Player* owner, Vec3* pos, s32 mode) {
  DynamiteEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(DynamiteEffect));

  if (p != NULL) {
    SetEntityRoutine(p, DynamiteEffect_Update, DynamiteEffect_Destroy);
    if (DynamiteEffect_Init(p, owner, pos, mode) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
