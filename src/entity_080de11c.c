#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"

typedef struct {
  AuxAnimState anim;  // 0x00
  Particle ptcl;      // 0x10
  Vec3 vel;           // 0x38, 毎フレーム ptcl.pos に足す
  bool8 active;       // 0x40, アニメが一周すると 0 に戻って activeCount が1減る
  u8 unk_41[3];       // 0x41, まだ未解析
} Entity080de11cElem;
static_assert(sizeof(Entity080de11cElem) == 68);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_9
  Entity080de11cElem ptcls[48];  // 0x018
  AuxAnimFile* animFile;         // 0xCD8, ANIM_D1B8
  ParticleGroup* group;          // 0xCDC, PTCL_GROUP_0
  u32 activeCount;               // 0xCE0, active な要素の数, 0 なら _Update は何もしない
} Entity080de11c;
static_assert(sizeof(Entity080de11c) == 3300);

static Entity080de11c* gEntity080de11c;  // 0x03000174

// 残差5命令 (178/183), 原典はループ外に 1 と 2 の両方を括り出すがこちらは 1 だけ, muls の前にコピーが2つ入る
// Tier A-C 試済, 兄弟の Entity0800a89c_UpdateCollectedBug と同じ形まで追い込んだ
NON_MATCH s32 Entity080de11c_Update(Entity080de11c* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->activeCount == 0) {
    return 0;
  }

  for (i = 0; i < 48; i++) {
    Entity080de11cElem* e = &p->ptcls[i];

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
  INCFUNC("asm/func/Entity080de11c_Update.inc");
#endif
}

// 全要素の粒子を描画リストから外す
s32 Entity080de11c_Destroy(Entity080de11c* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  gEntity080de11c = NULL;
  return 0;
}

NAKED s32 FUN_080ddcc8(WorldPos* pos, u8 param_2, Vec3* halfSize, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080ddcc8.inc"); }

NAKED void UNUSED FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

s32 Entity080de11c_Init(Entity080de11c* p) {
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

  gEntity080de11c = p;
  return 0;
}

Entity080de11c* Entity080de11c_Create(void) {
  if (gEntity080de11c == NULL) {
    Entity080de11c* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080de11c));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080de11c_Update, Entity080de11c_Destroy);
      if (Entity080de11c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080de11c;
}

void FUN_080de168(void) { gEntity080de11c = NULL; }
