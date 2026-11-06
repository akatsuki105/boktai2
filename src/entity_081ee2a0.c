#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "particle.h"
#include "vec3.h"

typedef struct {
  Particle ptcl;  // 0x00
  Vec3 vel;       // 0x28, vel.y は毎フレーム 1 ずつ減り, 床で跳ね返るたびに縮む
  u16 flags;      // 0x30, bit0 が立つと止まる (vel が全部 0 になったとき)
  u8 state;       // 0x32, PTR_ARRAY_085ae4c8 の添字, 1 で跳ね回り, lifetime が切れると 2 で片付く
  s8 idx;         // 0x33, elems の添字, 空きは -1
  bool8 spawned;  // 0x34, 生成した次のフレームで ptcl を表示して 0 に戻る
  u8 unk_35;      // 0x35, 生成時に 30
  u8 animTimer;   // 0x36, 3 フレームごとに animFrame を切り替える
  u8 animFrame;   // 0x37, 0..1, basePose に足すポーズ番号
  u16 lifetime;   // 0x38
  u16 tileIdx;    // 0x3A, ptcl.pos のタイル番号
  u8 basePose;    // 0x3C, kind * 2
} Entity081ee2a0Elem;
static_assert(sizeof(Entity081ee2a0Elem) == 64);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_2
  Entity081ee2a0Elem elems[26];  // 0x01C
  u32 activeMask;                // 0x69C, elems の使用中ビット
} Entity081ee2a0;
static_assert(sizeof(Entity081ee2a0) == 1696);

static Entity081ee2a0* gEntity081ee2a0;  // 0x030001CC

static inline s32 TileHeightAtIdx(u32 idx, WorldPos* pos) {
  MapTileOverride* ov = Map_FindTileOverride(idx, 1);
  CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  s32 stairs = tile->heightStairs >> 4;
  s32 height = (tile->heightStairs & 0xF) << 8;

  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= pos->z & 0xFF;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= pos->x & 0xFF;
      break;
    }
  }
  return height;
}

// 床で跳ね返りながら1フレーム進める, 止まっていたら TRUE を返す
static inline bool8 Entity081ee2a0Elem_Bounce(Entity081ee2a0Elem* elem) {
  Vec3* pos;
  Vec3* vel;
  u32 tileIdx;
  s32 floor;
  Vec3 next;
  u32 nextTileIdx;

  elem->tileIdx = GetCollisionTileIdx(&elem->ptcl.pos);
  elem->vel.y--;
  pos = &elem->ptcl.pos;
  vel = &elem->vel;
  tileIdx = elem->tileIdx;
  ArcTan2_8(vel->x, vel->z);
  floor = TileHeightAtIdx(tileIdx, pos);
  if (vel->x * vel->x + vel->y * vel->y + vel->z * vel->z == 0) {
    return TRUE;
  }
  if (pos->y <= floor) {
    vel->x = Div(vel->x * 6, 10);
    vel->y = Div(-(vel->y * 4), 10);
    vel->z = Div(vel->z * 6, 10);
    pos->y = floor;
  }
  next.x = pos->x + vel->x;
  next.y = pos->y + vel->y;
  next.z = pos->z + vel->z;
  nextTileIdx = GetCollisionTileIdx(&next);
  if (tileIdx != nextTileIdx && floor < TileHeightAtIdx(nextTileIdx, &next)) {
    vel->x = -Div(vel->x * 5, 10);
    vel->z = -Div(vel->z * 5, 10);
  }
  pos->x += vel->x;
  pos->y += vel->y;
  pos->z += vel->z;
  return FALSE;
}

static inline bool8 Entity081ee2a0_IsElemUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081ee2a0Elem_UpdateState0(Entity081ee2a0*, Entity081ee2a0Elem*);
void Entity081ee2a0Elem_UpdateState1(Entity081ee2a0*, Entity081ee2a0Elem*);
void Entity081ee2a0Elem_UpdateState2(Entity081ee2a0*, Entity081ee2a0Elem*);
Entity081ee2a0Elem* Entity081ee2a0_Spawn(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority);
Entity081ee2a0* Entity081ee2a0_Create(void);
s32 Entity081ee2a0_Update(Entity081ee2a0* p);
s32 Entity081ee2a0_Destroy(Entity081ee2a0* p);
s32 Entity081ee2a0_Init(Entity081ee2a0* p);
void Entity081ee2a0Elem_UpdateAnim(Entity081ee2a0* p, Entity081ee2a0Elem* elem);

void (*const PTR_ARRAY_085ae4c8[3])(Entity081ee2a0*, Entity081ee2a0Elem*) = {
    Entity081ee2a0Elem_UpdateState0,
    Entity081ee2a0Elem_UpdateState1,
    Entity081ee2a0Elem_UpdateState2,
};  // 0x085AE4C8

void Entity081ee2a0Elem_UpdateState0(Entity081ee2a0* p, Entity081ee2a0Elem* elem) {}

Entity081ee2a0Elem* Entity081ee2a0_AllocElem(Entity081ee2a0* p) {
  s32 i;

  for (i = 0; i < 26; i++) {
    if (!Entity081ee2a0_IsElemUsed(&p->activeMask, i)) {
      Entity081ee2a0Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

// 4 フレームごとに 2 コマを切り替える
void Entity081ee2a0Elem_UpdateAnim(Entity081ee2a0* p, Entity081ee2a0Elem* elem) {
  if (elem->animTimer != 0) {
    elem->animTimer--;
  } else {
    elem->animTimer = 3;
    elem->animFrame = (elem->animFrame + 1) & 1;
    Particle_SetPose(&elem->ptcl, p->group, elem->basePose + elem->animFrame);
  }
}

// 床で跳ね回り, lifetime が切れたら片付けの状態に移す
void Entity081ee2a0Elem_UpdateState1(Entity081ee2a0* p, Entity081ee2a0Elem* elem) {
  if (elem->spawned) {
    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    elem->spawned = FALSE;
  }
  if (!(elem->flags & 1)) {
    if (Entity081ee2a0Elem_Bounce(elem)) {
      elem->flags |= 1;
    }
  }
  Entity081ee2a0Elem_UpdateAnim(p, elem);
  if (elem->lifetime != 0) {
    elem->lifetime--;
  } else {
    elem->state = 2;
    elem->spawned = TRUE;
  }
}

void Entity081ee2a0Elem_UpdateState2(Entity081ee2a0* p, Entity081ee2a0Elem* elem) {
  Entity081ee2a0* p2;

  if (elem->spawned) {
    elem->spawned = FALSE;
  }
  p2 = gEntity081ee2a0;
  CLEAR_BIT(p2->activeMask, elem->idx);
  elem->state = 0;
  Particle_Remove(&elem->ptcl);
  elem->idx = -1;
  elem->flags = 0;
  elem->lifetime = 0;
}

// priority 1 で粒を1つ出す
Entity081ee2a0Elem* Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind) { return Entity081ee2a0_Spawn(pos, vel, lifetime, kind, 1); }

Entity081ee2a0Elem* Entity081ee2a0_SpawnEx(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) { return Entity081ee2a0_Spawn(pos, vel, lifetime, kind, priority); }

// pos から vel で跳ねる粒を1つ出す, kind (0〜7) でポーズの組を選ぶ
Entity081ee2a0Elem* Entity081ee2a0_Spawn(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) {
  Entity081ee2a0* p = gEntity081ee2a0;
  Entity081ee2a0Elem* elem;
  u8 k;

  if (p == NULL) {
    p = Entity081ee2a0_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  elem = Entity081ee2a0_AllocElem(p);
  if (elem == NULL) {
    return NULL;
  }
  elem->state = 1;
  elem->flags = 0;
  elem->spawned = TRUE;
  elem->vel = *vel;
  elem->lifetime = lifetime;
  elem->unk_35 = 30;
  elem->animTimer = 0;
  switch (kind) {
    case 1: {
      k = 1;
      break;
    }
    case 2: {
      k = 2;
      break;
    }
    case 3: {
      k = 3;
      break;
    }
    case 4: {
      k = 4;
      break;
    }
    case 5: {
      k = 5;
      break;
    }
    case 6: {
      k = 6;
      break;
    }
    case 7: {
      k = 7;
      break;
    }
    case 0:
    default: {
      k = 0;
      break;
    }
  }
  elem->animFrame = 0;
  elem->basePose = k * 2;
  elem->ptcl.pos = *pos;
  Particle_Add(&elem->ptcl, p->group, 0);
  Particle_SetOffset(&elem->ptcl, -4, -4);
  Particle_SetPose(&elem->ptcl, p->group, elem->basePose);
  Particle_SetPltt(&elem->ptcl, 1);
  elem->ptcl.flags |= SPRFLAG_HIDDEN;
  elem->ptcl.priority = priority;
  return elem;
}

s32 Entity081ee2a0_Update(Entity081ee2a0* p) {
  Entity081ee2a0Elem* elems = p->elems;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 26; i++) {
    if (Entity081ee2a0_IsElemUsed(&p->activeMask, i)) {
      PTR_ARRAY_085ae4c8[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081ee2a0_Destroy(Entity081ee2a0* p) {
  s32 i;

  for (i = 0; i < 26; i++) {
    if (Entity081ee2a0_IsElemUsed(&p->activeMask, i)) {
      Particle_Remove(&p->elems[i].ptcl);
    }
  }
  gEntity081ee2a0 = NULL;
  return 0;
}

s32 Entity081ee2a0_Init(Entity081ee2a0* p) {
  p->group = GetParticleGroup(PTCL_GROUP_2);
  p->activeMask = 0;
  gEntity081ee2a0 = p;
  return 0;
}

Entity081ee2a0* Entity081ee2a0_Create(void) {
  Entity081ee2a0* p;

  if (gEntity081ee2a0 != NULL) {
    return gEntity081ee2a0;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081ee2a0));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081ee2a0_Update, Entity081ee2a0_Destroy);
    if (Entity081ee2a0_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081ee2a0_ClearGlobal(void) { gEntity081ee2a0 = NULL; }
