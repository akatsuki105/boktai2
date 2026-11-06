#include "entity.h"
#include "global.h"
#include "particle.h"

// 粒子1個, vel で流れながら lifetime を減らし, 尽きると state 2 (解放) に移る
typedef struct {
  Particle ptcl;    // 0x00, pos は _SpawnElem の第1引数の写し
  Vec3 vel;         // 0x28, 毎フレーム x と z だけ ptcl.pos に足される
  u16 unk_30;       // 0x30
  u8 state;         // 0x32, PTR_ARRAY_085ae5f0 の添字 (0:待機 1:移動 2:解放)
  s8 slotIdx;       // 0x33, usedMask 上の自分のビット番号, 空きは -1
  bool8 needsShow;  // 0x34, 立っている間に _UpdateMove が ptcl の SPRFLAG_HIDDEN を落とす
  u8 unk_35;        // 0x35, 初期値 0x1E
  u8 animTimer;     // 0x36, 0 になると animDelay を再読込して次のコマへ
  u8 animFlip;      // 0x37, 0/1 を交互に取り baseFrame に足される
  u16 lifetime;     // 0x38, 0 になると state 2 へ移る
  u8 unk_3a[2];     // 0x3A
  u8 baseFrame;     // 0x3C, Particle_SetPose に渡すコマ番号の基準, kind * 2
  u8 unk_3d;        // 0x3D
  u16 animDelay;    // 0x3E, animTimer の再読込値 (初期値 3)
} Entity081fa164Elem;
static_assert(sizeof(Entity081fa164Elem) == 64);

// 粒子を26個まで同時に流すシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_2
  Entity081fa164Elem elems[26];  // 0x01C
  u32 usedMask;                  // 0x69C, elems のどのスロットが使用中かのビットマスク
} Entity081fa164;
static_assert(sizeof(Entity081fa164) == 1696);

static Entity081fa164* gEntity081fa164;  // 0x03000214

static inline bool8 Entity081fa164_IsUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081fa164_UpdateIdle(Entity081fa164*, Entity081fa164Elem*);
void Entity081fa164_UpdateMove(Entity081fa164*, Entity081fa164Elem*);
void Entity081fa164_UpdateRelease(Entity081fa164*, Entity081fa164Elem*);
Entity081fa164Elem* Entity081fa164_SpawnElem(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority);
Entity081fa164* Entity081fa164_Create(void);

void (*const PTR_ARRAY_085ae5f0[3])(Entity081fa164*, Entity081fa164Elem*) = {
    Entity081fa164_UpdateIdle,
    Entity081fa164_UpdateMove,
    Entity081fa164_UpdateRelease,
};  // 0x085AE5F0

void Entity081fa164_UpdateIdle(Entity081fa164* p, Entity081fa164Elem* elem) {}

// 空いているスロットを1つ確保する
Entity081fa164Elem* Entity081fa164_AllocElem(Entity081fa164* p) {
  s32 i;

  for (i = 0; i < 26; i++) {
    if (!Entity081fa164_IsUsed(&p->usedMask, i)) {
      Entity081fa164Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// animTimer が切れるたびに 2 コマを交互に切り替える
s32 Entity081fa164_AdvanceAnim(Entity081fa164* p, Entity081fa164Elem* elem) {
  if (elem->animTimer == 0) {
    elem->animTimer = elem->animDelay;
    elem->animFlip = (elem->animFlip + 1) & 1;
    Particle_SetPose(&elem->ptcl, p->group, elem->baseFrame + elem->animFlip);
  } else {
    elem->animTimer--;
  }
  return 0;
}

// state 1, vel で流してアニメを進め, lifetime が尽きたら解放へ
void Entity081fa164_UpdateMove(Entity081fa164* p, Entity081fa164Elem* elem) {
  if (elem->needsShow) {
    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    elem->needsShow = FALSE;
  }
  elem->ptcl.pos.x += elem->vel.x;
  elem->ptcl.pos.z += elem->vel.z;
  Entity081fa164_AdvanceAnim(p, elem);
  if (elem->lifetime != 0) {
    elem->lifetime--;
  } else {
    elem->state = 2;
    elem->needsShow = TRUE;
  }
}

// state 2, 粒子を外してスロットを空ける
void Entity081fa164_UpdateRelease(Entity081fa164* p, Entity081fa164Elem* elem) {
  if (elem->needsShow) {
    elem->needsShow = FALSE;
  }
  {
    Entity081fa164* e = gEntity081fa164;

    CLEAR_BIT(e->usedMask, elem->slotIdx);
  }
  elem->state = 0;
  Particle_Remove(&elem->ptcl);
  elem->slotIdx = -1;
  elem->unk_30 = 0;
  elem->lifetime = 0;
}

// 描画優先度 1 で粒子を1つ流す
Entity081fa164Elem* Entity081fa164_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind) { return Entity081fa164_SpawnElem(pos, vel, lifetime, kind, 1); }

// 描画優先度を指定して粒子を1つ流す
Entity081fa164Elem* Entity081fa164_SpawnEx(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) { return Entity081fa164_SpawnElem(pos, vel, lifetime, kind, priority); }

// pos から vel で流れる粒子を1つ出す, kind (0..7) で絵柄を選び lifetime フレームで消える
Entity081fa164Elem* Entity081fa164_SpawnElem(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) {
  Entity081fa164* e = gEntity081fa164;
  Entity081fa164Elem* elem;
  s32 frame;

  if (e == NULL) {
    e = Entity081fa164_Create();
    if (e == NULL) {
      return NULL;
    }
  }
  elem = Entity081fa164_AllocElem(e);
  if (elem == NULL) {
    return NULL;
  }
  elem->state = 1;
  elem->unk_30 = 0;
  elem->needsShow = TRUE;
  elem->vel = *vel;
  elem->lifetime = lifetime;
  elem->unk_35 = 30;
  elem->animTimer = 0;
  switch (kind) {
    case 1: {
      frame = 1;
      break;
    }
    case 2: {
      frame = 2;
      break;
    }
    case 3: {
      frame = 3;
      break;
    }
    case 4: {
      frame = 4;
      break;
    }
    case 5: {
      frame = 5;
      break;
    }
    case 6: {
      frame = 6;
      break;
    }
    case 7: {
      frame = 7;
      break;
    }
    case 0:
    default: {
      frame = 0;
      break;
    }
  }
  elem->animFlip = 0;
  elem->baseFrame = frame * 2;
  elem->animDelay = 3;
  elem->animTimer = elem->animDelay;
  elem->ptcl.pos = *pos;
  Particle_Add(&elem->ptcl, e->group, 0);
  Particle_SetOffset(&elem->ptcl, -4, -4);
  Particle_SetPose(&elem->ptcl, e->group, elem->baseFrame);
  Particle_SetPltt(&elem->ptcl, 1);
  elem->ptcl.flags |= SPRFLAG_HIDDEN;
  elem->ptcl.priority = priority;
  return elem;
}

s32 Entity081fa164_Update(Entity081fa164* p) {
  Entity081fa164Elem* elems = p->elems;
  s32 i;

  if (p->usedMask == 0) {
    return 0;
  }
  for (i = 0; i < 26; i++) {
    if (Entity081fa164_IsUsed(&p->usedMask, i)) {
      PTR_ARRAY_085ae5f0[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081fa164_Destroy(Entity081fa164* p) {
  s32 i;

  for (i = 0; i < 26; i++) {
    if (Entity081fa164_IsUsed(&p->usedMask, i)) {
      Particle_Remove(&p->elems[i].ptcl);
    }
  }
  gEntity081fa164 = NULL;
  return 0;
}

s32 Entity081fa164_Init(Entity081fa164* p) {
  p->group = GetParticleGroup(PTCL_GROUP_2);
  p->usedMask = 0;
  gEntity081fa164 = p;
  return 0;
}

Entity081fa164* Entity081fa164_Create(void) {
  if (gEntity081fa164 == NULL) {
    Entity081fa164* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081fa164));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081fa164_Update, Entity081fa164_Destroy);
      if (Entity081fa164_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081fa164;
}

void Entity081fa164_ClearGlobal(void) { gEntity081fa164 = NULL; }
