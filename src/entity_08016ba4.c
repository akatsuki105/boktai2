#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite.h"

// 1発ぶんの破片, 速度を持って飛びながらアニメを進める
typedef struct {
  bool8 active;       // 0x00, Entity08016ba4_Spawn が 1 を入れる
  u8 life;            // 0x01, Entity08016ba4Burst_Update が毎フレーム 1 減らし, 0 で particle を隠す
  s16 speed;          // 0x02, vel.x / vel.z に掛けて >>12 してから pos に足す
  Vec3 vel;           // 0x04, x は gSineTable[angle + 0x40], z は gSineTable[angle], y は Entity08016ba4Burst_Update が毎フレーム 2 減らす
  Particle particle;  // 0x0C, Particle_Setup で確保し Particle_Remove で返す
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
  ParticleGroup* group;           // 0x001C, PTCL_GROUP_0
  AuxAnimFile* anim;              // 0x0020, ANIM_D1B8
  Entity08016ba4Burst bursts[6];  // 0x0024, Entity08016ba4_Spawn が空いている枠を先頭から探す
} Entity08016ba4;
static_assert(sizeof(Entity08016ba4) == 3324);

IWRAM_DATA Entity08016ba4* gEntity08016ba4 = NULL;  // 0x03000064

void FUN_080166a0(void) { gEntity08016ba4 = NULL; }

NAKED s32 Entity08016ba4_Spawn(s32 count, Vec3* pos, s32 param_3, s32 param_4, s32 param_5, s32 param_6, u32 param_7, s32 param_8, s32 param_9, s32 param_10) { INCFUNC("asm/func/Entity08016ba4_Spawn.inc"); }

NAKED s32 Entity08016ba4Burst_Update(Entity08016ba4Burst* b) { INCFUNC("asm/func/Entity08016ba4Burst_Update.inc"); }

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
  s32 i;

  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &p->bursts[i];

    if (b->active) {
      s32 j;

      for (j = 0; j < b->count; j++) {
        Particle_Remove(&b->pieces[j].particle);
      }
    }
  }

  gEntity08016ba4 = NULL;
  return 0;
}

s32 Entity08016ba4_Init(Entity08016ba4* p, u32 id) {
  s32 i;

  gEntity08016ba4 = p;
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);

  for (i = 0; i < 6; i++) {
    Entity08016ba4Burst* b = &p->bursts[i];
    s32 j;

    b->active = 0;
    for (j = 0; j < 8; j++) {
      Particle_Setup(&b->pieces[j].particle, p->group, 0);
      AuxAnim_SetAnim(&b->pieces[j].anim, p->anim, 3, 0, 0);
    }
  }

  p->frame = 0;
  return 0;
}

Entity08016ba4* Entity08016ba4_Create(u32 id) {
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
