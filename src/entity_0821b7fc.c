#include "entity.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

// ブラックホールのまわりに散る粒
typedef struct {
  Particle ptcl;  // 0x00, PTCL_GROUP_2
  s16 active;     // 0x28
  s16 angle;      // 0x2A, 負なら中心のまわりに散らばって出る, 0 以上ならこの向きへ 15 ずつ飛ぶ
  s16 velY;       // 0x2C, 毎フレーム 1 ずつ減る
  u8 age;         // 0x2E, 8 で絵が変わる
  u8 life;        // 0x2F, 10..19
} Entity0821b7fcParticle;
static_assert(sizeof(Entity0821b7fcParticle) == 48);

// おてんこが出すブラックホールの演出, 現れて揺れ, 縮みながら上がり, 粒を散らして消える
typedef struct Entity0821b7fc {
  Entity e;                         // 0x000, ENTITY_UNK_11
  AuxSprite sprite;                 // 0x018
  AuxSpriteGfx gfx;                 // 0x044, SPR_BLACKHOLE
  Vec3 pos;                         // 0x060, 毎フレーム sprite.pos へ写す
  s32 timer;                        // 0x068, 毎フレーム +1, 3 フレーム周期で絵を切り替える
  u32 state;                        // 0x06C, 4 で終わり
  s32 stateTimer;                   // 0x070
  bool32 stateBegun;                // 0x074, state に入った最初のフレームで立っている
  ParticleGroup* group;             // 0x078, PTCL_GROUP_2
  Entity0821b7fcParticle ptcls[8];  // 0x07C
} Entity0821b7fc;
static_assert(sizeof(Entity0821b7fc) == 508);

static inline void Entity0821b7fc_SetState(Entity0821b7fc* p, u32 state) {
  p->state = state;
  p->stateTimer = 0;
  p->stateBegun = TRUE;
}

// 空いている粒を1つ出す, angle が負なら中心のまわりに散らばって止まったまま落ちる
// 残差22箇所 (129/127): 原典は angle をスタックに逃がし 0x3FF と &gRandTableIdx だけをレジスタに持って表の番地は毎回読む, こちらは表も括り出して r10 まで使う
// Tier A-B は試済 (添字と要素ポインタ, 乱数の足し方の順), 未: Tier C
NON_MATCH void Entity0821b7fc_SpawnParticle(Entity0821b7fc* p, s32 angle) {
#ifdef NONMATCHING_C
  Entity0821b7fcParticle* elem = p->ptcls;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (!elem->active) {
      elem->active = TRUE;
      elem->angle = angle;
      elem->age = 0;
      elem->life = Mod(Random(), 10) + 10;
      if (angle < 0) {
        elem->ptcl.pos.x = Mod(Random(), 160) - 80 + p->pos.x;
        elem->ptcl.pos.y = Mod(Random(), 80) - 40 + p->pos.y;
        elem->ptcl.pos.z = Mod(Random(), 160) - 80 + p->pos.z;
        elem->velY = 0;
      } else {
        elem->ptcl.pos.x = p->pos.x;
        elem->ptcl.pos.y = p->pos.y;
        elem->ptcl.pos.z = p->pos.z;
        elem->velY = 15;
      }
      Particle_Show(&elem->ptcl);
      return;
    }
  }
#else
  INCFUNC("asm/func/Entity0821b7fc_SpawnParticle.inc");
#endif
}

// 出ている粒を動かし, 寿命が来たら隠す
// 残差 (134/129): Vec3_SetPolar と添字ループで muls とスタックの数え下げは出る, 原典は &age と &ptcl を別の誘導変数に持つ
// Tier A-B は試済 (要素ポインタ, angle のローカル化, Vec3_Add), 未: Particle* を別に取る形
NON_MATCH void Entity0821b7fc_UpdateParticles(Entity0821b7fc* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      if (p->ptcls[i].angle >= 0) {
        Vec3 d;

        Vec3_SetPolar(&d, p->ptcls[i].angle, 15);
        Vec3_Add(&p->ptcls[i].ptcl.pos, &d);
      }
      p->ptcls[i].velY--;
      p->ptcls[i].ptcl.pos.y += p->ptcls[i].velY;
      if (p->ptcls[i].age == 8) {
        Particle_SetPose(&p->ptcls[i].ptcl, p->group, 3);
      }
      if (++p->ptcls[i].age >= p->ptcls[i].life) {
        Particle_Hide(&p->ptcls[i].ptcl);
        p->ptcls[i].active = FALSE;
      }
    }
  }
#else
  INCFUNC("asm/func/Entity0821b7fc_UpdateParticles.inc");
#endif
}

s32 Entity0821b7fc_Update(Entity0821b7fc* p) {
  if (!p->stateBegun) {
    p->stateTimer++;
  }
  p->sprite.pos = p->pos;
  switch (p->state) {
    case 0: {
      p->stateBegun = FALSE;
      if (p->stateTimer >= 56) {
        Entity0821b7fc_SetState(p, 1);
      }
      break;
    }
    case 1: {
      bool32 begun = p->stateBegun;

      p->stateBegun = FALSE;
      if (begun) {
        p->sprite.priority = 2;
      }
      p->sprite.pos.x += Mod(RandomNext(), 40) - 20;
      p->sprite.pos.y += Mod(RandomNext(), 40) - 20;
      p->sprite.pos.z += Mod(RandomNext(), 40) - 20;
      if (p->stateTimer >= 59) {
        Entity0821b7fc_SetState(p, 2);
      }
      break;
    }
    case 2: {
      p->stateBegun = FALSE;
      p->pos.y -= 20;
      if (p->sprite.scaleX > 48) {
        p->sprite.scaleX -= 2;
        p->sprite.scaleY -= 2;
      }
      if (p->stateTimer >= 7) {
        Entity0821b7fc_SetState(p, 3);
      }
      break;
    }
    case 3: {
      p->stateBegun = FALSE;
      if (p->sprite.scaleX < 64) {
        p->sprite.scaleX += 4;
        p->sprite.scaleY += 4;
      }
      p->pos.y += 100;
      if (p->stateTimer >= 3 && Mod(p->stateTimer, 3) == 0) {
        Entity0821b7fc_SpawnParticle(p, -1);
      }
      if (p->stateTimer >= 30) {
        Entity0821b7fc_SetState(p, 4);
      }
      break;
    }
    case 4: {
      bool32 begun = p->stateBegun;

      p->stateBegun = FALSE;
      if (begun) {
        AuxSprite_Hide(&p->sprite);
      }
      if (p->stateTimer > 300) {
        KillEntity((Entity*)p);
      }
      return 0;
    }
  }
  switch (Mod(p->timer, 3)) {
    case 0:
    case 1: {
      p->sprite.poseIdx = 1;
      break;
    }
    default: {
      p->sprite.poseIdx = 0;
      break;
    }
  }
  Entity0821b7fc_UpdateParticles(p);
  p->timer++;
  return 0;
}

s32 Entity0821b7fc_Destroy(Entity0821b7fc* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  return 0;
}

s32 Entity0821b7fc_Init(Entity0821b7fc* p, Vec3* pos) {
  s32 i;

  p->pos = *pos;
  p->timer = 0;
  Video_GetAuxSprite(&p->gfx, SPR_BLACKHOLE);
  AuxSprite_Add(&p->sprite, &p->gfx, 2);
  p->sprite.pos = *pos;
  p->sprite.scaleX = Q6(1);
  p->sprite.scaleY = Q6(1);
  p->sprite.priority = 3;
  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    Particle_Add(&p->ptcls[i].ptcl, p->group, 1);
    Particle_SetOffset(&p->ptcls[i].ptcl, -4, -4);
    Particle_SetPose(&p->ptcls[i].ptcl, p->group, 2);
    Particle_SetPltt(&p->ptcls[i].ptcl, 1);
    p->ptcls[i].active = FALSE;
  }
  p->state = 0;
  p->stateTimer = 0;
  p->stateBegun = TRUE;
  return 0;
}

Entity0821b7fc* Entity0821b7fc_Create(Vec3* pos) {
  Entity0821b7fc* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity0821b7fc));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0821b7fc_Update, Entity0821b7fc_Destroy);
    if (Entity0821b7fc_Init(p, pos) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void Entity0821b7fc_Remove(Entity0821b7fc* p) { KillEntity((void*)p); }

bool32 Entity0821b7fc_IsFinished(Entity0821b7fc* p) { return p->state == 4; }
