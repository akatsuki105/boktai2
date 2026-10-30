#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "sprite_animation.h"

// 煙1つ
typedef struct {
  AuxAnimState anim;  // 0x00
  Particle ptcl;      // 0x10
  Vec3 vel;           // 0x38, 毎フレーム ptcl.pos に足す
  bool8 active;       // 0x40, 煙のアニメーションが終わったら FALSE になる
} SmokePtcl;
static_assert(sizeof(SmokePtcl) == 68);

// 煙のエフェクトエミッタ
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_9
  SmokePtcl ptcls[48];    // 0x018
  AuxAnimFile* animFile;  // 0xCD8, ANIM_D1B8
  ParticleGroup* group;   // 0xCDC, PTCL_GROUP_0
  u32 activeCount;        // 0xCE0, active な要素の数, 0 なら _Update は何もしない
} SmokeEmitter;
static_assert(sizeof(SmokeEmitter) == 3300);

static SmokeEmitter* gSmokeEmitter;  // 0x03000174

SmokeEmitter* SmokeEmitter_Create(void);

// 煙を速度ぶん動かしてアニメを1コマ進め, アニメが一巡したものから消す
s32 SmokeEmitter_Update(SmokeEmitter* p) {
  s32 i;

  if (p->activeCount == 0) {
    return 0;
  }

  for (i = 0; i < 48; i++) {
    SmokePtcl* e = &p->ptcls[i];
    Particle* ptcl = &e->ptcl;

    if (e->active) {
      ptcl->pos.x += e->vel.x;
      ptcl->pos.y += e->vel.y;
      ptcl->pos.z += e->vel.z;

      if (Particle_AdvanceAnim(ptcl, p->group, &e->anim)) {
        e->active = FALSE;
        ptcl->flags |= SPRFLAG_HIDDEN;
        p->activeCount--;
      }
    }
  }
  return 0;
}

// 全要素の粒子を描画リストから外す
s32 SmokeEmitter_Destroy(SmokeEmitter* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  gSmokeEmitter = NULL;
  return 0;
}

// 残差2命令 (307/309), 原典は &e->vel を基点に active を [+8] で読むが, こちらは active 専用の IV ができて &e->vel がスタックに退避され CpuFill32 の dest 取得で2命令増える
// Tier A-C 試済 (e ローカル有無/フラグ/定数順は検証済)
NON_MATCH s32 EmitSmoke(WorldPos* pos, u8 count, Vec3* size, s32 angle, s32 speed, s32 velYMax, s32 kind, u32 priority) {
#ifdef NONMATCHING_C
  SmokeEmitter* p = gSmokeEmitter;
  s32 i;

  if (p == NULL) {
    p = SmokeEmitter_Create();
    if (p == NULL) {
      return 0;
    }
  }

  for (i = 0; i < 48; i++) {
    SmokePtcl* e = &p->ptcls[i];

    if (!e->active) {
      u16 animIdx;

      if (size != NULL) {
        if (size->x == 0) {
          e->ptcl.pos.x = pos->x;
        } else {
          e->ptcl.pos.x = Mod(Random(), size->x) - FixToInt(1, size->x) + pos->x;
        }
        if (size->y == 0) {
          e->ptcl.pos.y = pos->y;
        } else {
          e->ptcl.pos.y = Mod(Random(), size->y) - FixToInt(1, size->y) + pos->y;
        }
        if (size->z == 0) {
          e->ptcl.pos.z = pos->z;
        } else {
          e->ptcl.pos.z = Mod(Random(), size->z) - FixToInt(1, size->z) + pos->z;
        }
      } else {
        e->ptcl.pos.x = pos->x;
        e->ptcl.pos.y = pos->y;
        e->ptcl.pos.z = pos->z;
      }

      e->ptcl.flags &= ~SPRFLAG_HIDDEN;
      e->ptcl.priority = priority;
      e->active = TRUE;
      CpuFill32(0, &e->vel, sizeof(e->vel));
      if (speed != 0) {
        e->vel.x = POLAR_X(speed, angle), e->vel.y = 0, e->vel.z = POLAR_Z(speed, angle);
      }
      if (velYMax == 0) {
        e->vel.y = Mod(Random(), 32);
      } else {
        e->vel.y = Mod(Random(), velYMax);
      }

      switch (kind) {
        case 0:
        case 1: {
          animIdx = 15;
          Particle_SetPltt(&e->ptcl, 1);
          break;
        }
        case 2: {
          animIdx = 16;
          Particle_SetPltt(&e->ptcl, 0);
          break;
        }
        case 3: {
          animIdx = 17;
          Particle_SetPltt(&e->ptcl, 0);
          break;
        }
        default: {
          animIdx = 15;
          Particle_SetPltt(&e->ptcl, 0);
          break;
        }
      }
      AuxAnim_SetAnim(&e->anim, p->animFile, animIdx, 0, 0);
      p->activeCount++;
      count--;
      if (count == 0) {
        break;
      }
    }
  }
  return 1;
#else
  INCFUNC("asm/func/EmitSmoke.inc");
#endif
}

NAKED void UNUSED FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

s32 SmokeEmitter_Init(SmokeEmitter* p) {
  s32 i;

  p->animFile = GetFile(DIR_ANIMATION, ANIM_D1B8);
  if (p->animFile == NULL) {
    return -1;
  }

  p->group = GetParticleGroup(PTCL_GROUP_0);
  if (p->group == NULL) {
    return -1;
  }

  for (i = 0; i < 48; i++) {
    Particle* ptcl = &p->ptcls[i].ptcl;

    p->ptcls[i].active = FALSE;
    Particle_Add(ptcl, p->group, 0);
    Particle_SetOffset(ptcl, -8, -10);
    ptcl->offsetZ = 2;
    ptcl->flags |= SPRFLAG_HIDDEN;
  }

  gSmokeEmitter = p;
  return 0;
}

SmokeEmitter* SmokeEmitter_Create(void) {
  if (gSmokeEmitter == NULL) {
    SmokeEmitter* p = CreateEntity(ENTITY_UNK_9, sizeof(SmokeEmitter));
    if (p != NULL) {
      SetEntityRoutine(p, SmokeEmitter_Update, SmokeEmitter_Destroy);
      if (SmokeEmitter_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gSmokeEmitter;
}

void FUN_080de168(void) { gSmokeEmitter = NULL; }
