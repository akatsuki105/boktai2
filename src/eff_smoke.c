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
  bool8 active;       // 0x40, アニメが一周すると 0 に戻って activeCount が1減る
  u8 unk_41[3];       // 0x41, まだ未解析
} SmokePtcl;
static_assert(sizeof(SmokePtcl) == 68);

// 煙のエフェクトマネージャ
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

// 残差5命令 (178/183), 原典はループ外に 1 と 2 の両方を括り出すがこちらは 1 だけ, muls の前にコピーが2つ入る
// Tier A-C 試済, 兄弟の Entity0800a89c_UpdateCollectedBug と同じ形まで追い込んだ
NON_MATCH s32 SmokeEmitter_Update(SmokeEmitter* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->activeCount == 0) {
    return 0;
  }

  for (i = 0; i < 48; i++) {
    SmokePtcl* e = &p->ptcls[i];

    if (e->active) {
      AuxAnimCmd* cmd;
      bool32 finished;

      e->ptcl.pos.x += e->vel.x;
      e->ptcl.pos.y += e->vel.y;
      e->ptcl.pos.z += e->vel.z;

      cmd = &e->anim.cmds[e->anim.cmdIdx];
      e->ptcl.tileNum = (*cmd >> 6) * ((e->ptcl.spriteWidth >> 3) * (e->ptcl.spriteHeight >> 3)) + p->group->tile;
      if ((e->anim.flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
        e->ptcl.flags |= SPRFLAG_XFLIP;
      } else {
        e->ptcl.flags &= ~SPRFLAG_XFLIP;
      }
      if ((e->anim.flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
        e->ptcl.flags |= SPRFLAG_YFLIP;
      } else {
        e->ptcl.flags &= ~SPRFLAG_YFLIP;
      }
      e->anim.tick++;
      if (e->anim.tick < e->anim.wait) {
        finished = FALSE;
      } else {
        e->anim.tick = 0;
        if (e->anim.flags & ANIM_PLAY_REVERSE) {
          if (e->anim.cmdIdx == 0) {
            e->anim.cmdIdx = e->anim.cmdCount - 1;
            finished = TRUE;
          } else {
            e->anim.cmdIdx--;
            finished = FALSE;
          }
        } else {
          e->anim.cmdIdx++;
          if (e->anim.cmdIdx < e->anim.cmdCount) {
            finished = FALSE;
          } else {
            e->anim.cmdIdx = 0;
            finished = TRUE;
          }
        }
        e->anim.wait = (e->anim.speed * (e->anim.cmds[e->anim.cmdIdx] & 0xF)) >> 6;
      }
      if (finished) {
        e->active = FALSE;
        e->ptcl.flags |= SPRFLAG_HIDDEN;
        p->activeCount--;
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/SmokeEmitter_Update.inc");
#endif
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
NON_MATCH s32 FUN_080ddcc8(WorldPos* pos, u8 count, Vec3* size, s32 angle, s32 speed, s32 velYMax, s32 kind, u32 priority) {
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
        e->vel.x = COS(angle, speed), e->vel.y = 0, e->vel.z = SIN(angle, speed);
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
  INCFUNC("asm/func/FUN_080ddcc8.inc");
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
