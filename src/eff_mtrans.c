#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sprite.h"
#include "sprite_pltt.h"
#include "vec3.h"
#include "video.h"

// 8個を使い回す粒子の枠
typedef struct TransEffectParticle {
  Particle ptcl;                                                           // 0x00, FUN_080abfec が Particle_Remove に渡す
  bool8 active;                                                            // 0x28, 立っている間 FUN_080abf9c が update を呼ぶ
  u8 pose;                                                                 // 0x29, FUN_080ac008 が unk_24 から決める
  u8 timer;                                                                // 0x2A, 出てからのフレーム数, 12 で消える
  u8 riseSpeed;                                                            // 0x2B, 毎フレーム上がる量, 4 フレーム目から増える
  u8 radius;                                                               // 0x2C, center からの距離
  u8 angle;                                                                // 0x2D, center から見た向き
  u8 angleSpeed;                                                           // 0x2E, 毎フレーム angle に足す, 9 フレーム目から減る
  u8 unk_2f;                                                               // 0x2F
  Vec3 center;                                                             // 0x30, 回る中心
  void (*update)(struct TransEffectParticle* elem, ParticleGroup* group);  // 0x38
} TransEffectParticle;
static_assert(sizeof(TransEffectParticle) == 60);

// 粒子8個とそれを動かす状態
typedef struct {
  u8 nextIdx;                    // 0x00, 次に出す elems の添字
  u8 spawnTimer;                 // 0x01, 2 フレームごとに1つ出す
  bool8 active;                  // 0x02, 動いている粒子が1つもなくなると FUN_080abf9c が落とす
  u8 unk_03;                     // 0x03
  ParticleGroup* group;          // 0x04, PTCL_GROUP_2
  TransEffectParticle elems[8];  // 0x08
} TransEffectParticles;
static_assert(sizeof(TransEffectParticles) == 488);

// FUN_080ac090 / FUN_080ac100 / FUN_080ac13c が受け取る一式, パレットを timer に応じて白から元の色へ寄せる
typedef struct {
  AuxSprite spr;     // 0x00, ->gfx
  AuxSpriteGfx gfx;  // 0x2C, SPRITE_MAGIC_CIRCLE
  rgb555* srcPltt;   // 0x48, 元のパレット
  rgb555 pltt[16];   // 0x4C, srcPltt を timer / 16 で白と混ぜたもの
  u8 active;         // 0x6C, FUN_080ac13c が timer 0 のとき 0 を書く
  u8 timer;          // 0x6D, FUN_080ac100 が 0xF 未満なら +1, FUN_080ac13c が 0 でなければ -1
  u8 unk_6e[2];      // 0x6E
} TransEffectSprite;
static_assert(sizeof(TransEffectSprite) == 112);

// 魔法"トランス", "Cマウス", "Cバット" を使用した際の 魔方陣, パーティクル
typedef struct {
  Entity e;                        // 0x000, ENTITY_UNK_8
  Player* player;                  // 0x018
  Vec3 pos;                        // 0x01C, _Init の第4引数を8バイトまるごと写す, NULL なら x/y/z を 0 にする
  u8 unk_24;                       // 0x024, _Init の第3引数
  u8 unk_25;                       // 0x025, _Init が player->action を写す, 変わったら魔方陣を消し始める
  u16 timer;                       // 0x026, 魔方陣を出してからのフレーム数, unk_2a で消え始める
  u16 unk_28;                      // 0x028, _Init の第5引数, timer がこれ未満の間は粒子を出す
  u16 unk_2a;                      // 0x02A, _Init の第6引数, 魔方陣を出しておくフレーム数
  TransEffectSprite circle;        // 0x02C, 足元の魔方陣
  TransEffectParticles particles;  // 0x09C
} TransEffect;
static_assert(sizeof(TransEffect) == 644);

void FUN_080abe48(TransEffect* p, Vec3* pos);
void FUN_080ac100(TransEffectSprite* s);
void FUN_080ac13c(TransEffectSprite* s);

// 粒子1つを center の周りで回しながら上げ, 12 フレームで消す
void FUN_080abd74(TransEffectParticle* e, ParticleGroup* group) {
  if (++e->timer > 11) {
    e->ptcl.flags |= SPRFLAG_HIDDEN;
    e->active = FALSE;
    return;
  }
  if (e->timer == 6) {
    Particle_SetPose(&e->ptcl, group, e->pose + 1);
  }
  if (e->timer > 3) {
    e->riseSpeed++;
    if (e->timer > 8) {
      e->angleSpeed--;
    }
  }
  e->angle += e->angleSpeed;
  e->ptcl.pos.x = e->center.x + POLAR_X(e->radius, e->angle);
  e->ptcl.pos.z = e->center.z + POLAR_Z(e->radius, e->angle);
  e->ptcl.pos.y += e->riseSpeed;
}

// 2 フレームごとに pos を中心に粒子を1つ出す
void FUN_080abe48(TransEffect* p, Vec3* pos) {
  TransEffectParticles* particles = &p->particles;

  if (++particles->spawnTimer > 1) {
    TransEffectParticle* e = &particles->elems[particles->nextIdx];
    Particle* ptcl;
    u16* table;

    e->active = TRUE;
    table = gRandomTable;
    e->riseSpeed = (_Random(table) & 15) + 16;
    e->radius = (_Random(table) & 15) + 64;
    e->angle = _Random(table);
    e->angleSpeed = 8;
    e->timer = 0;
    e->center = *pos;
    e->update = FUN_080abd74;
    ptcl = &e->ptcl;
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    Particle_SetPose(ptcl, p->particles.group, e->pose);
    ptcl->pos.x = e->center.x + POLAR_X(e->radius, e->angle);
    ptcl->pos.y = e->center.y;
    ptcl->pos.z = e->center.z + POLAR_Z(e->radius, e->angle);
    if (++particles->nextIdx > 7) {
      particles->nextIdx = 0;
    }
    particles->spawnTimer = 0;
    p->particles.active = TRUE;
  }
}

// 動いている粒子を進め, 1つも残っていなければ止める
void FUN_080abf9c(TransEffect* p) {
  if (p->particles.active) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 8; i++) {
      TransEffectParticle* e = &p->particles.elems[i];

      if (e->active) {
        e->update(e, p->particles.group);
        n++;
      }
    }
    if (n == 0) {
      p->particles.active = n;
    }
  }
}

void FUN_080abfec(TransEffect* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->particles.elems[i].ptcl);
  }
}

// 粒子8個を止めた状態で用意し, unk_24 からコマを決める
void FUN_080ac008(TransEffect* p) {
  TransEffectParticles* particles = &p->particles;
  s32 pose;
  s32 i;

  particles->group = GetParticleGroup(PTCL_GROUP_2);
  particles->nextIdx = 0;
  particles->spawnTimer = 0;
  if (p->unk_24 == 7) {
    pose = 14;
  } else {
    pose = (p->unk_24 + 1) * 2;
  }
  for (i = 0; i < 8; i++) {
    TransEffectParticle* e = &particles->elems[i];

    e->active = FALSE;
    e->pose = pose;
    Particle_Add(&e->ptcl, particles->group, 1);
    Particle_SetOffset(&e->ptcl, -4, -4);
    Particle_SetPltt(&e->ptcl, 1);
    e->ptcl.offsetZ = -8;
    e->ptcl.priority = 2;
  }
}

// srcPltt を timer / 16 の割合で白から元の色へ寄せて pltt に入れる
void FUN_080ac090(TransEffectSprite* s) {
  rgb555* src = s->srcPltt;
  s32 white = (16 - s->timer) * 15;
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 r = *src & 0x1F;
    s32 g = (*src >> 5) & 0x1F;
    s32 b = (*src >> 10) & 0x1F;

    r = (white + r * s->timer) >> 4;
    g = (white + g * s->timer) >> 4;
    b = (white + b * s->timer) >> 4;
    s->pltt[i] = (b << 10) | (g << 5) | r;
    src++;
  }
}

void FUN_080ac100(TransEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer <= 0xF) {
    s->timer++;
    FUN_080ac090(s);
  }
}

void FUN_080ac13c(TransEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer == 0) {
    s->spr.flags |= SPRFLAG_HIDDEN;
    s->active = 0;
  } else {
    s->timer--;
    FUN_080ac090(s);
  }
}

// 魔方陣を player に付いて回らせ, unk_2a フレームか player の行動が変わったら消し始める
void FUN_080ac18c(TransEffect* p) {
  if (p->circle.active) {
    if (p->timer < p->unk_2a && p->unk_25 != p->player->action) {
      p->timer = p->unk_2a;
    }
    if (++p->timer < p->unk_2a) {
      FUN_080ac100(&p->circle);
      p->circle.spr.pos = p->player->mover.pos;
      p->circle.spr.pos.x += p->pos.x;
      p->circle.spr.pos.y += p->pos.y;
      p->circle.spr.pos.z += p->pos.z;
      if (p->timer < p->unk_28) {
        FUN_080abe48(p, &p->circle.spr.pos);
      }
    } else {
      FUN_080ac13c(&p->circle);
    }
  }
}

void FUN_080ac21c(TransEffect* p) { AuxSprite_Remove(&p->circle.spr); }

// 足元に魔方陣を出し, 種類ごとのパレットを灰色から寄せ始める
// 残差: 83 対 84 命令, 原典は unk_24 を r7 に読んで比較には r0 の写しを使い, 魔方陣のポインタを r4 に置く割当
NON_MATCH void FUN_080ac228(TransEffect* p, Vec3* pos) {
#ifdef NONMATCHING_C
  TransEffectSprite* s = &p->circle;
  u8 kind = p->unk_24;
  s32 plttID;
  s32 i;

  plttID = 99;
  if (kind != 0) {
    plttID = 108;
    if (kind == 1) {
      plttID = 98;
    }
  }
  Video_GetAuxSprite(&s->gfx, SPRITE_MAGIC_CIRCLE);
  AuxSprite_Add(&s->spr, &s->gfx, 0);
  s->spr.poseIdx = kind;
  s->spr.priority = 3;
  s->spr.pos = *pos;
  s->spr.pos.x += p->pos.x;
  s->spr.pos.y += p->pos.y;
  s->spr.pos.z += p->pos.z;
  s->spr.flags |= SPRFLAG_BLINK_EVEN;
  s->srcPltt = &gObjPlttData[plttID * 16];
  for (i = 15; i >= 0; i--) {
    s->pltt[i] = RGB(15, 15, 15);
  }
  s->gfx.plttID = plttID;
  s->gfx.pltt = s->pltt;
  s->active = TRUE;
#else
  INCFUNC("asm/func/FUN_080ac228.inc");
#endif
}

// 戻り値は呼んだ先が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 TransEffect_Update(TransEffect* p) {
  FUN_080ac18c(p);
  FUN_080abf9c(p);
  if (p->circle.active == 0) {
    if (p->particles.active == 0) {
      KillEntity((Entity*)p);
    }
  }
}

// 戻り値は FUN_080abfec が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 TransEffect_Destroy(TransEffect* p) {
  FUN_080ac21c(p);
  FUN_080abfec(p);
}

s32 TransEffect_Init(TransEffect* p, Player* player, u32 param_3, Vec3* pos, u32 param_5, u32 param_6) {
  p->unk_24 = param_3;
  p->player = player;

  if (pos == NULL) {
    VEC3_SET(p->pos, 0, 0, 0);
  } else {
    p->pos = *pos;
  }

  p->unk_25 = p->player->action;
  p->unk_28 = param_5;
  p->unk_2a = param_6;
  FUN_080ac228(p, &p->player->mover.pos);
  FUN_080ac008(p);
  return 0;
}

TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5) {
  TransEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(TransEffect));

  if (p != NULL) {
    SetEntityRoutine(p, TransEffect_Update, TransEffect_Destroy);
    if (TransEffect_Init(p, player, param_2, pos, param_4, param_5) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
