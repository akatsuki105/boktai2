#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "solar.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// ライジングサン, ブラックサンの 効果処理 及び 演出

#define K_RISING_SUN 0  // ライジングサン
#define K_BLACK_SUN 1   // ブラックサン

struct RisingSunEffect;

// 12個を使い回す粒子の枠, updateCallback が動きを決める
typedef struct RisingSunEffectParticle {
  Particle ptcl;                                                            // 0x00
  bool8 active;                                                             // 0x28
  u8 poseIdx;                                                               // 0x29, 途中で poseIdx + 1 のコマに切り替える
  u8 angle;                                                                 // 0x2A
  s8 angleVel;                                                              // 0x2B, 毎フレーム angle に足す
  u16 frame;                                                                // 0x2C
  u16 speed;                                                                // 0x2E, RisingSunEffectParticle_UpdateOrbit では毎フレーム pos.y に足す量, RisingSunEffectParticle_UpdateBurst では vec の長さ
  u16 orbitRadius;                                                          // 0x30, RisingSunEffectParticle_UpdateOrbit が vec を中心に回る半径
  u16 spiralRadius;                                                         // 0x32, RisingSunEffectParticle_UpdateSpiral が center へ向けて縮めていく半径
  Vec3* center;                                                             // 0x34, RisingSunEffectParticle_UpdateSpiral が回る中心
  Vec3 vec;                                                                 // 0x38, RisingSunEffectParticle_UpdateOrbit では回る中心, RisingSunEffectParticle_UpdateBurst では毎フレームの移動量
  void (*updateCallback)(struct RisingSunEffectParticle*, ParticleGroup*);  // 0x40
} RisingSunEffectParticle;
static_assert(sizeof(RisingSunEffectParticle) == 68);

typedef struct {
  u8 nextIdx;                         // 0x00, 次に使う elems の添字, 12 で 0 に戻る
  u8 spawnTimer;                      // 0x01, 発生を数フレームおきに間引く
  bool8 active;                       // 0x02, 動いている粒が無くなると 0
  u8 unk_3;                           // 0x03
  ParticleGroup* group;               // 0x04, PTCL_GROUP_2
  RisingSunEffectParticle elems[12];  // 0x08
} RisingSunEffectEmitter;
static_assert(sizeof(RisingSunEffectEmitter) == 824);

// 落ちてきて弾ける玉, 弾けると画面を光らせて太陽の状態を書き換える
typedef struct RisingSunEffectOrb {
  AuxSprite spr;                                       // 0x00
  AuxSpriteGfx gfx;                                    // 0x2C, SPRITE_EBALL_210E
  AuxSprite burstSpr;                                  // 0x48, 弾けたあとの絵
  AuxSpriteGfx burstGfx;                               // 0x74, SPRITE_EXPLOSION
  bool8 active;                                        // 0x90
  bool8 burst;                                         // 0x91, 弾けたら 1
  u8 flashColor[3];                                    // 0x92, 弾けたときの画面フラッシュの色 (r, g, b)
  s8 velY;                                             // 0x95, 36 から毎フレーム 1 減る
  u16 frame;                                           // 0x96
  void (*updateCallback)(struct RisingSunEffectOrb*);  // 0x98
  struct RisingSunEffect* parent;                      // 0x9C
} RisingSunEffectOrb;
static_assert(sizeof(RisingSunEffectOrb) == 160);

// パレットを白から元の色へ戻しながら出し, 消えるときは点滅させるスプライト
typedef struct {
  AuxSprite spr;                   // 0x00
  AuxSpriteGfx gfx;                // 0x2C, SPRITE_MAGIC_SQUARE
  rgb555* srcPltt;                 // 0x48, 元の色
  rgb555 pltt[16];                 // 0x4C, srcPltt を白へ寄せた色, gfx.pltt がここを指す
  bool8 active;                    // 0x6C
  u8 timer;                        // 0x6D, 0〜16, srcPltt の重み
  bool8 fadingOut;                 // 0x6E
  u8 unk_6f[3];                    // 0x6F
  u16 frame;                       // 0x72
  struct RisingSunEffect* parent;  // 0x74
} RisingSunEffectSprite;
static_assert(sizeof(RisingSunEffectSprite) == 120);

// ブラックサンも扱う
typedef struct RisingSunEffect {
  Entity e;                        // 0x000, ENTITY_UNK_8
  u8 kind;                         // 0x018, _Init の第5引数, 0 ならライジングサン, それ以外はブラックサン
  u8 unk_19;                       // 0x019, gRisingSunCount を増やしたら 1, _Update が戻す
  u8 unk_1a;                       // 0x01A, _Init の第6引数, _Destroy は unk_1b と2バイトまとめて 0 かを見る
  u8 unk_1b;                       // 0x01B, _Update が player の死亡時に 1 にする
  Player* player;                  // 0x01C, _Init の第2引数, _Update は player が死ぬと止まる
  RisingSunEffectOrb orb;          // 0x020
  RisingSunEffectSprite glow;      // 0x0C0
  RisingSunEffectEmitter emitter;  // 0x138
} RisingSunEffect;
static_assert(sizeof(RisingSunEffect) == 1136);

void RisingSunEffectSprite_FadeOut(RisingSunEffectSprite* s);

static inline void Solar_SetOverride(u16 kind, u16 frames) {
  gSunGaugeOverride = kind;
  gSunGaugeOverrideTimer = frames;
}

// 玉が弾けたとき, kind に応じて太陽をライジングサン / ブラックサンの状態に 1800 フレーム固定する
void RisingSunEffect_ApplySun(RisingSunEffect* p) {
  p->player->ene = 0;
  if (p->kind == 0) {
    Solar_SetOverride(SUN_OVERRIDE_RISING, 1800);
    gRisingSunCount++;
    p->unk_19 = TRUE;
  } else {
    Solar_SetOverride(SUN_OVERRIDE_BLACK, 1800);
  }
}

// 中心の周りを回りながら昇る粒を進める
void RisingSunEffectParticle_UpdateOrbit(RisingSunEffectParticle* elem, ParticleGroup* group) {
  if (++elem->frame > 11) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
  } else {
    if (elem->frame == 6) {
      Particle_SetPose(&elem->ptcl, group, elem->poseIdx + 1);
    }
    if (elem->frame > 3) {
      elem->speed++;
      if (elem->frame > 8) {
        elem->angleVel--;
      }
    }
    elem->angle += elem->angleVel;
    elem->ptcl.pos.x = elem->vec.x + POLAR_X(elem->orbitRadius, elem->angle);
    elem->ptcl.pos.z = elem->vec.z + POLAR_Z(elem->orbitRadius, elem->angle);
    elem->ptcl.pos.y += elem->speed;
  }
}

// pos の周りを回って昇る粒を1つ出す, 2フレームに1回だけ
void RisingSunEffect_SpawnOrbitParticle(RisingSunEffect* p, WorldPos* pos) {
  RisingSunEffectEmitter* em = &p->emitter;

  if (++em->spawnTimer > 1) {
    RisingSunEffectParticle* elem = &em->elems[em->nextIdx];
    Particle* ptcl;

    elem->active = TRUE;
    elem->speed = (RandomNext() & 15) + 16;
    elem->orbitRadius = (RandomNext() & 15) + 64;
    elem->angle = RandomNext();
    elem->angleVel = 8;
    elem->frame = 0;
    elem->vec = *pos;
    elem->updateCallback = RisingSunEffectParticle_UpdateOrbit;
    ptcl = &elem->ptcl;
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    Particle_SetPose(ptcl, p->emitter.group, elem->poseIdx);
    ptcl->pos.x = elem->vec.x + POLAR_X(elem->orbitRadius, elem->angle);
    ptcl->pos.y = elem->vec.y;
    ptcl->pos.z = elem->vec.z + POLAR_Z(elem->orbitRadius, elem->angle);
    ptcl->priority = 2;
    if (++em->nextIdx > 11) {
      em->nextIdx = 0;
    }
    em->spawnTimer = 0;
    p->emitter.active = TRUE;
  }
}

// center へ渦を巻いて寄っていく粒を進め, 消えるときに煙を出す
void RisingSunEffectParticle_UpdateSpiral(RisingSunEffectParticle* elem, ParticleGroup* group) {
  if (++elem->frame > 15) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
    EmitSmoke(&elem->ptcl.pos, 1, NULL, 0, 0, 0, 2, 1);
  } else if (elem->frame > 11) {
    elem->ptcl.pos.x = elem->center->x + POLAR_X(10, elem->angle);
    elem->ptcl.pos.y = elem->center->y;
    elem->ptcl.pos.z = elem->center->z + POLAR_Z(10, elem->angle);
  } else {
    s32 n = 12 - elem->frame;
    s32 d = n + 1;

    elem->angle += elem->angleVel;
    elem->spiralRadius = Div(elem->spiralRadius * n, d);
    elem->ptcl.pos.x = elem->center->x + POLAR_X(elem->spiralRadius, elem->angle);
    elem->ptcl.pos.y = elem->center->y;
    elem->ptcl.pos.z = elem->center->z + POLAR_Z(elem->spiralRadius, elem->angle);
  }
}

void RisingSunEffect_SpawnSpiralParticle(RisingSunEffect* p, Vec3* center) {
  RisingSunEffectEmitter* em = &p->emitter;

  if (++em->spawnTimer > 2) {
    RisingSunEffectParticle* elem = &em->elems[em->nextIdx];

    elem->active = TRUE;
    elem->center = center;
    elem->spiralRadius = (RandomNext() & 0x7F) + 384;
    elem->angle = RandomNext();
    elem->angleVel = (RandomNext() & 1) + 2;
    elem->frame = 0;
    elem->updateCallback = RisingSunEffectParticle_UpdateSpiral;
    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    Particle_SetPose(&elem->ptcl, p->emitter.group, 4);
    elem->ptcl.pos.x = elem->center->x + POLAR_X(elem->spiralRadius, elem->angle);
    elem->ptcl.pos.y = elem->center->y;
    elem->ptcl.pos.z = elem->center->z + POLAR_Z(elem->spiralRadius, elem->angle);
    elem->ptcl.priority = 1;
    if (++em->nextIdx > 11) {
      em->nextIdx = 0;
    }
    em->spawnTimer = 0;
    p->emitter.active = TRUE;
  }
}

// まっすぐ飛び散る粒を進める
void RisingSunEffectParticle_UpdateBurst(RisingSunEffectParticle* elem, ParticleGroup* group) {
  if (++elem->frame > 13) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
  } else {
    elem->ptcl.pos.x += elem->vec.x;
    elem->ptcl.pos.y += elem->vec.y;
    elem->ptcl.pos.z += elem->vec.z;
    if (elem->frame == 10) {
      Particle_SetPose(&elem->ptcl, group, elem->poseIdx + 1);
    }
  }
}

void RisingSunEffect_SpawnBurstParticles(RisingSunEffect* p, WorldPos* pos) {
  s32 angle = RandomNext() & 0xFF;
  s32 i;

  for (i = 0; i < 12; i++) {
    RisingSunEffectParticle* elem = &p->emitter.elems[i];

    elem->active = TRUE;
    elem->angle = (Random() & 15) + angle - 9;
    elem->speed = (Random() & 15) + 25;
    elem->vec.x = POLAR_X(elem->speed, elem->angle);
    elem->vec.y = 0;
    elem->vec.z = POLAR_Z(elem->speed, elem->angle);
    elem->updateCallback = RisingSunEffectParticle_UpdateBurst;
    elem->frame = 0;
    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    Particle_SetPose(&elem->ptcl, p->emitter.group, elem->poseIdx);
    elem->ptcl.pos.x = pos->x + elem->vec.x;
    elem->ptcl.pos.y = pos->y;
    elem->ptcl.pos.z = pos->z + elem->vec.z;
    elem->ptcl.priority = 1;
    angle = (angle + 24) & 0xFF;
  }
  p->emitter.active = TRUE;
}

// 動いている粒をそれぞれの updateCallback で進める
void RisingSunEffect_UpdateParticles(RisingSunEffect* p) {
  if (p->emitter.active) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 12; i++) {
      RisingSunEffectParticle* elem = &p->emitter.elems[i];

      if (elem->active) {
        elem->updateCallback(elem, p->emitter.group);
        n++;
      }
    }
    if (n == 0) {
      p->emitter.active = FALSE;
    }
  }
}

void RisingSunEffect_RemoveParticles(RisingSunEffect* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->emitter.elems[i].ptcl);
  }
}

void RisingSunEffect_InitParticles(RisingSunEffect* p) {
  RisingSunEffectEmitter* em = &p->emitter;
  u8 poseIdx;
  s32 i;

  em->group = GetParticleGroup(PTCL_GROUP_2);
  em->nextIdx = 0;
  em->spawnTimer = 0;
  if (p->kind == K_RISING_SUN) {
    poseIdx = PTCL2_SOL_L;
  } else {
    poseIdx = PTCL2_DARK_L;
  }
  for (i = 0; i < 12; i++) {
    RisingSunEffectParticle* elem = &em->elems[i];

    elem->active = FALSE;
    elem->poseIdx = poseIdx;
    Particle_Add(&elem->ptcl, em->group, 1);
    Particle_SetOffset(&elem->ptcl, -4, -4);
    Particle_SetPltt(&elem->ptcl, 1);
    elem->ptcl.offsetZ = -8;
    elem->ptcl.priority = 2;
  }
}

// 元の色を timer / 16 の重みで灰色に寄せたパレットを作る
void RisingSunEffectSprite_UpdatePltt(RisingSunEffectSprite* s) {
  rgb555* src = s->srcPltt;
  s32 base = (16 - s->timer) * 15;
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 r = *src & 31;
    s32 g = (*src >> 5) & 31;
    s32 b = (*src >> 10) & 31;

    r = (base + r * s->timer) >> 4;
    g = (base + g * s->timer) >> 4;
    b = (base + b * s->timer) >> 4;
    s->pltt[i] = (b << 10) | (g << 5) | r;
    src++;
  }
}

// パレットを元の色へ戻しつつ, 最初の 20 フレームは回る粒を出す
void RisingSunEffectSprite_FadeIn(RisingSunEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }
  if (s->timer <= 15) {
    s->timer++;
    RisingSunEffectSprite_UpdatePltt(s);
  }
  s->frame++;
  if (s->frame <= 19) {
    RisingSunEffect_SpawnOrbitParticle(s->parent, &s->spr.pos);
  }
}

void RisingSunEffectSprite_FadeOut(RisingSunEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer == 0) {
    s->spr.flags |= SPRFLAG_HIDDEN;
    s->active = FALSE;
  } else {
    s->timer--;
    RisingSunEffectSprite_UpdatePltt(s);
  }
}

// player が詠唱を続けている間は glow を出し, 止めたら消していく
void RisingSunEffect_UpdateGlow(RisingSunEffect* p) {
  if (p->glow.active) {
    if (p->player->action == PACT_SUN_MAGIC && p->player->state <= 2 && !p->glow.fadingOut) {
      RisingSunEffectSprite_FadeIn(&p->glow);
    } else {
      p->glow.fadingOut = TRUE;
      RisingSunEffectSprite_FadeOut(&p->glow);
    }
  }
}

void RisingSunEffect_RemoveGlow(RisingSunEffect* p) { AuxSprite_Remove(&p->glow.spr); }

// 73/73命令, p と poseIdx の割り当てレジスタ (r7/r6) が入れ替わるだけ, 試済: poseIdx の型 u16/s16/s32/u32, 局所変数の宣言順, gfx ローカルの有無
NON_MATCH void RisingSunEffect_InitGlow(RisingSunEffect* p, WorldPos* pos) {
#ifdef NONMATCHING_C
  RisingSunEffectSprite* s = &p->glow;
  u16 poseIdx;
  u32 plttID;
  s32 i;
  AuxSpriteGfx* gfx;

  if (p->kind == K_RISING_SUN) {
    poseIdx = 0;
    plttID = 99;
  } else {
    poseIdx = 1;
    plttID = 98;
  }
  gfx = &s->gfx;
  Video_GetAuxSprite(gfx, SPRITE_MAGIC_SQUARE);
  AuxSprite_Add(&s->spr, gfx, 0);
  s->spr.poseIdx = poseIdx;
  s->spr.priority = 3;
  s->spr.pos = *pos;
  s->spr.pos.z += 24;
  s->spr.flags |= SPRFLAG_BLINK_EVEN;
  s->srcPltt = &gObjPlttData[plttID * 16];
  for (i = 0; i < 16; i++) {
    s->pltt[i] = RGB(15, 15, 15);
  }
  gfx->plttID = plttID;
  gfx->pltt = s->pltt;
  s->parent = p;
  s->active = TRUE;
#else
  INCFUNC("asm/func/RisingSunEffect_InitGlow.inc");
#endif
}

// 弾けた絵をコマ送りし, 24 フレームで消す
void RisingSunEffectOrb_UpdateBurst(RisingSunEffectOrb* orb) {
  AuxSprite_SetPoseIdx(&orb->burstSpr, orb->frame < 8 ? orb->frame >> 2 : (orb->frame >> 2) + 4);
  orb->frame++;
  if (orb->frame > 23) {
    orb->burstSpr.flags |= SPRFLAG_HIDDEN;
    orb->active = FALSE;
  }
}

// 玉を落とし, 48 フレームで弾けさせて画面を光らせる
void RisingSunEffectOrb_UpdateFall(RisingSunEffectOrb* orb) {
  orb->spr.flags &= ~SPRFLAG_HIDDEN;
  if (++orb->frame <= 47) {
    orb->spr.pos.y += orb->velY;
    orb->velY--;
    if (orb->parent->unk_1a != 0 && orb->velY > 0) {
      RisingSunEffect_SpawnSpiralParticle(orb->parent, &orb->spr.pos);
    }
  } else if (orb->parent->unk_1a != 0) {
    orb->spr.flags |= SPRFLAG_HIDDEN;
    orb->active = FALSE;
  } else {
    PlaySound_082406e0(SE_M_SUN_BURST);
    StartBgObjPlttFade(0, 4, orb->flashColor[0], orb->flashColor[1], orb->flashColor[2], 0x1FFF, 0);
    RisingSunEffect_ApplySun(orb->parent);
    orb->burst = TRUE;
    orb->spr.flags |= SPRFLAG_HIDDEN;
    orb->burstSpr.flags &= ~SPRFLAG_HIDDEN;
    orb->burstSpr.pos = orb->spr.pos;
    orb->updateCallback = RisingSunEffectOrb_UpdateBurst;
    orb->frame = 0;
    RisingSunEffect_SpawnBurstParticles(orb->parent, &orb->spr.pos);
  }
}

void RisingSunEffect_UpdateOrb(RisingSunEffect* p) {
  if (p->orb.active == 0) {
    if (p->player->action == PACT_SUN_MAGIC && p->player->state == 2) {
      p->orb.active = 1;
    }

    if (p->orb.active == 0) {
      return;
    }
  }

  p->orb.updateCallback(&p->orb);
}

void RisingSunEffect_RemoveOrb(RisingSunEffect* p) {
  AuxSprite_Remove(&p->orb.spr);
  AuxSprite_Remove(&p->orb.burstSpr);
}

// 112/112命令, pos 引数と使い回しの定数 0 が入る r8/r9 が入れ替わるだけ, 試済: spr/gfx ローカル (これで命令数は揃う)
NON_MATCH void RisingSunEffect_InitOrb(RisingSunEffect* p, WorldPos* pos) {
#ifdef NONMATCHING_C
  RisingSunEffectOrb* orb = &p->orb;
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  s32 plttOfs;
  s32 burstPlttOfs;

  if (p->kind == K_RISING_SUN) {
    plttOfs = 0;
    burstPlttOfs = 3;
    orb->flashColor[0] = 31;
    orb->flashColor[1] = 31;
    orb->flashColor[2] = 20;
  } else {
    plttOfs = 6;
    burstPlttOfs = 2;
    orb->flashColor[0] = 20;
    orb->flashColor[1] = 0;
    orb->flashColor[2] = 0;
  }
  gfx = &orb->gfx;
  Video_GetAuxSprite(gfx, SPRITE_EBALL_210E);
  AuxSprite_Add(&orb->spr, gfx, 0);
  orb->spr.poseIdx = 1;
  Video_SetAuxSpritePltt(gfx, plttOfs + 44);
  orb->spr.priority = 2;
  orb->spr.flags |= SPRFLAG_HIDDEN;
  orb->spr.pos = *pos;
  spr = &orb->burstSpr;
  gfx = &orb->burstGfx;
  Video_GetAuxSprite(gfx, SPRITE_EXPLOSION);
  AuxSprite_Add(spr, gfx, 0);
  spr->poseIdx = 0;
  Video_SetAuxSpritePltt(gfx, burstPlttOfs + 275);
  spr->priority = 1;
  orb->burstSpr.flags |= SPRFLAG_HIDDEN;
  orb->velY = 36;
  orb->parent = p;
  orb->active = FALSE;
  orb->burst = FALSE;
  orb->updateCallback = RisingSunEffectOrb_UpdateFall;
#else
  INCFUNC("asm/func/RisingSunEffect_InitOrb.inc");
#endif
}

s32 RisingSunEffect_Update(RisingSunEffect* p) {
  if (p->player->mode == PMODE_DEAD) {
    p->unk_1b = TRUE;
    return 0;
  }
  if (p->unk_19) {
    gRisingSunCount--;
    p->unk_19 = FALSE;
  }
  RisingSunEffect_UpdateGlow(p);
  RisingSunEffect_UpdateOrb(p);
  RisingSunEffect_UpdateParticles(p);
  if (!p->glow.active && !p->orb.active && !p->emitter.active) {
    KillEntity((Entity*)p);
  }
}

s32 RisingSunEffect_Destroy(RisingSunEffect* p) {
  if (p->orb.active && !p->orb.burst && *(u16*)&p->unk_1a == 0) {
    RisingSunEffect_ApplySun(p);
  }

  RisingSunEffect_RemoveOrb(p);
  RisingSunEffect_RemoveGlow(p);
  RisingSunEffect_RemoveParticles(p);
  if (p->unk_19) {
    gRisingSunCount--;
  }
}

s32 RisingSunEffect_Init(RisingSunEffect* p, void* owner, WorldPos* pos1, WorldPos* pos2, u32 kind, u32 param_6) {
  p->kind = kind;
  p->player = owner;
  RisingSunEffect_InitOrb(p, pos2);
  RisingSunEffect_InitGlow(p, pos1);
  RisingSunEffect_InitParticles(p);

  if (kind == K_RISING_SUN) {
    PlaySound_082406e0(SE_M_RISINGSUN);
  } else {
    PlaySound_082406e0(SE_M_BLACKSUN);
  }

  p->unk_1a = param_6;
  return 0;
}

RisingSunEffect* RisingSunEffect_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 kind, u32 param_5) {
  RisingSunEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(RisingSunEffect));

  if (p != NULL) {
    SetEntityRoutine(p, RisingSunEffect_Update, RisingSunEffect_Destroy);
    if (RisingSunEffect_Init(p, owner, pos1, pos2, kind, param_5) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
