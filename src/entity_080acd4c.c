#include "entity.h"
#include "global.h"
#include "particle.h"

// 粒を8枠で使い回して順番に出すシングルトン
typedef struct {
  Particle ptcl;         // 0x00
  ParticleGroup* group;  // 0x28, PTCL_GROUP_0
  bool8 active;          // 0x2C, 0 の枠は飛ばす, timer が 0x10 に届くと 0 に戻す
  u8 unk_2d;             // 0x2D, 初期化で 0 を書くだけ
  u16 timer;             // 0x2E, 毎フレーム +1, >> 1 して 0xC を足したコマ番号を使う
} Entity080acd4cElem;
static_assert(sizeof(Entity080acd4cElem) == 48);

typedef struct Entity080acd4c {
  Entity e;                     // 0x000, ENTITY_UNK_10
  Entity080acd4cElem elems[8];  // 0x018
  u16 nextSlot;                 // 0x198, 次に使う枠の添字
  u8 unk_19a[2];                // 0x19A, padding
} Entity080acd4c;
static_assert(sizeof(Entity080acd4c) == 412);

COMMON_DATA Entity080acd4c* gEntity080acd4c = NULL;  // 0x03002C54

void Entity080acd4c_ClearGlobal(void) { gEntity080acd4c = NULL; }

// コマを進めながら上へ昇り, 16 フレームで消える
void Entity080acd4cElem_Update(Entity080acd4cElem* elem) {
  Particle_SetPose(&elem->ptcl, elem->group, PTCL_FIRE(elem->timer >> 1));
  elem->ptcl.pos.y += 10;
  elem->timer++;
  if (elem->timer == 16) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
  }
}

s32 Entity080acd4c_Update(Entity080acd4c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->elems[i].active) {
      Entity080acd4cElem_Update(&p->elems[i]);
    }
  }
  return 0;
}

s32 Entity080acd4c_Destroy(Entity080acd4c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->elems[i].ptcl);
  }
  gEntity080acd4c = NULL;
  return 0;
}

// 8 枠の粒を作って隠しておく
void Entity080acd4c_InitElems(Entity080acd4c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Entity080acd4cElem* elem = &p->elems[i];

    elem->active = FALSE;
    elem->unk_2d = 0;
    elem->timer = 0;
    elem->group = GetParticleGroup(PTCL_GROUP_0);
    Particle_Add(&elem->ptcl, elem->group, 0);
    Particle_SetOffset(&elem->ptcl, -8, -8);
    Particle_SetPose(&elem->ptcl, elem->group, PTCL_FIRE(0));
    Particle_Hide(&elem->ptcl);
    elem->ptcl.priority = 2;
  }
}

s32 Entity080acd4c_Init(Entity080acd4c* p) {
  Entity080acd4c_InitElems(p);
  p->nextSlot = 0;
  gEntity080acd4c = p;
  return 0;
}

Entity080acd4c* Entity080acd4c_Create(void) {
  if (gEntity080acd4c == NULL) {
    Entity080acd4c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080acd4c));

    if (p != NULL) {
      SetEntityRoutine(p, Entity080acd4c_Update, Entity080acd4c_Destroy);
      if (Entity080acd4c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080acd4c;
}

// pos に粒を1つ出す, 8 枠を順番に使い回す
void Entity080acd4c_Spawn(Vec3* pos) {
  Entity080acd4cElem* elem;

  if (gEntity080acd4c == NULL) {
    Entity080acd4c_Create();
  }
  elem = &gEntity080acd4c->elems[gEntity080acd4c->nextSlot];
  Particle_Show(&elem->ptcl);
  elem->ptcl.pos = *pos;
  elem->timer = 0;
  elem->active = TRUE;
  gEntity080acd4c->nextSlot++;
  if (gEntity080acd4c->nextSlot >= 8) {
    gEntity080acd4c->nextSlot = 0;
  }
}
