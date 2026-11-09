#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "sprite.h"
#include "trig.h"

// 1発ぶんの破片, 速度を持って飛びながらアニメを進める
typedef struct {
  bool8 active;       // 0x00, Entity08016ba4_Spawn が 1 を入れる
  u8 life;            // 0x01, Entity08016ba4Burst_Update が毎フレーム 1 減らし, 0 で ptcl を隠す
  s16 speed;          // 0x02, vel.x / vel.z に掛けて >>12 してから pos に足す
  Vec3 vel;           // 0x04, x は gSineTable[angle + 0x40], z は gSineTable[angle], y は Entity08016ba4Burst_Update が毎フレーム 2 減らす
  Particle ptcl;      // 0x0C, Particle_Setup で確保し Particle_Remove で返す
  AuxAnimState anim;  // 0x34, AuxAnim_SetAnim が初期化し AuxAnim_SetAnimSpeed が進める
} Entity08016ba4Piece;
static_assert(sizeof(Entity08016ba4Piece) == 68);

// 1回の発生ぶん, 同じ位置から最大8個の破片をまとめて飛ばす
typedef struct {
  bool8 active;                   // 0x000, Entity08016ba4_Spawn が空き枠に 1 を入れ, pieces が尽きると Entity08016ba4Burst_Update が 0 に戻す
  u8 count;                       // 0x001, 使う pieces の数, 8 で頭打ち
  u8 unk_2[2];                    // 0x002, まだ未解析
  Entity08016ba4Piece pieces[8];  // 0x004
} Entity08016ba4Burst;
static_assert(sizeof(Entity08016ba4Burst) == 548);

typedef struct {
  Entity e;                       // 0x0000, ENTITY_UNK_10
  s32 frame;                      // 0x0018, _Update が毎フレーム 1 足す
  ParticleGroup* group0;          // 0x001C, PTCL_GROUP_0
  AuxAnimFile* anim;              // 0x0020, ANIM_D1B8
  Entity08016ba4Burst bursts[6];  // 0x0024, Entity08016ba4_Spawn が空いている枠を先頭から探す
} Entity08016ba4;
static_assert(sizeof(Entity08016ba4) == 3324);

IWRAM_DATA Entity08016ba4* gEntity08016ba4 = NULL;  // 0x03000064

Entity08016ba4* Entity08016ba4_Create(u32 id, u32 _);

void FUN_080166a0(void) { gEntity08016ba4 = NULL; }

// 空いている枠を探し, pos から破片を count 個 (最大8) ばらばらの速さと向きで飛ばす
s32 Entity08016ba4_Spawn(s32 count, Vec3* pos, s32 lifeBase, s32 lifeRand, s32 speedBase, s32 speedRand, s32 angleBase, s32 angleRand, s32 velYBase, s32 velYRand) {
  s32 i, j;

  if (gEntity08016ba4 == NULL && Entity08016ba4_Create(0, 0) == NULL) {
    return -1;
  }
  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &gEntity08016ba4->bursts[i];

    if (!b->active) {
      b->active = TRUE;
      b->count = count;
      if (b->count > 8) {
        b->count = 8;
      }
      for (j = 0; j < b->count; j++) {
        Entity08016ba4Piece* pc = &b->pieces[j];
        s32 angle;

        pc->active = TRUE;
        if (lifeRand == 0) {
          pc->life = lifeBase;
        } else {
          pc->life = lifeBase + Mod(Random(), lifeRand);
        }
        if (speedRand == 0) {
          pc->speed = speedBase;
        } else {
          pc->speed = speedBase + Mod(Random(), speedRand);
        }
        if (angleRand == 0) {
          angle = angleBase;
        } else {
          angle = angleBase + Mod(Random(), angleRand);
        }
        pc->vel.x = COS(angle);
        pc->vel.z = SIN(angle);
        if (velYRand == 0) {
          pc->vel.y = velYBase;
        } else {
          pc->vel.y = velYBase + Mod(Random(), velYRand);
        }
        pc->ptcl.pos = *pos;
        Particle_AddToDrawList(&pc->ptcl, 0);
        pc->ptcl.flags &= ~SPRFLAG_HIDDEN;
        AuxAnim_SetAnim(&pc->anim, gEntity08016ba4->anim, 3, 0, 0);
      }
      return 0;
    }
  }
  return -1;
}

// 破片を動かしてアニメを進め, 寿命が尽きたら隠す, 全部尽きたら枠を空ける
s32 Entity08016ba4Burst_Update(Entity08016ba4Burst* b) {
  s32 alive = 0;
  s32 i;

  for (i = 0; i < b->count; i++) {
    Entity08016ba4Piece* pc = &b->pieces[i];
    Particle* ptcl = &pc->ptcl;

    if (pc->life != 0) {
      alive++;
      ptcl->pos.x += FixToInt(12, pc->vel.x * pc->speed);
      ptcl->pos.y += pc->vel.y;
      ptcl->pos.z += FixToInt(12, pc->vel.z * pc->speed);
      pc->vel.y -= 2;
      AuxAnim_SetAnimSpeed(&pc->anim, Q6(0.25));
      Particle_AdvanceAnim(ptcl, gEntity08016ba4->group0, &pc->anim);
      if (pc->life > 8) {
        if (pc->anim.cmdIdx == 5) {
          pc->anim.cmdIdx = 0;
        }
      } else if (pc->life == 8) {
        pc->anim.cmdIdx = 0;
      }
      pc->life--;
      if (pc->life == 255) {
        ptcl->flags |= SPRFLAG_HIDDEN;
      }
    } else {
      ptcl->flags |= SPRFLAG_HIDDEN;
    }
  }
  if (alive == 0) {
    b->active = FALSE;
    for (i = 0; i < b->count; i++) {
      Particle_Remove(&b->pieces[i].ptcl);
    }
    b->count = 0;
  }
  return 0;
}

s32 Entity08016ba4_Update(Entity08016ba4* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &gEntity08016ba4->bursts[i];

    if (b->active) {
      Entity08016ba4Burst_Update(b);
    }
  }

  p->frame++;
  return 0;
}

s32 Entity08016ba4_Destroy(Entity08016ba4* p) {
  s32 i, j;

  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &p->bursts[i];
    if (b->active) {
      for (j = 0; j < b->count; j++) {
        Particle_Remove(&b->pieces[j].ptcl);
      }
    }
  }

  gEntity08016ba4 = NULL;
  return 0;
}

s32 Entity08016ba4_Init(Entity08016ba4* p, u32 id) {
  s32 i, j;

  gEntity08016ba4 = p;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);

  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &p->bursts[i];
    b->active = FALSE;
    for (j = 0; j < 8; j++) {
      Particle_Setup(&b->pieces[j].ptcl, p->group0, 0);
      AuxAnim_SetAnim(&b->pieces[j].anim, p->anim, 3, 0, 0);
    }
  }

  p->frame = 0;
  return 0;
}

Entity08016ba4* Entity08016ba4_Create(u32 id, u32 _) {
  Entity08016ba4* p;

  if (gEntity08016ba4 != NULL) {
    return gEntity08016ba4;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity08016ba4));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08016ba4_Update, Entity08016ba4_Destroy);
    if (Entity08016ba4_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
