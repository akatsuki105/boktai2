#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "vec3.h"

typedef struct {
  Particle ptcl;   // 0x00, PTCL_GROUP_0 のポーズ 52
  u16 flags;       // 0x28, bit0 は ptcl を表示中
  u8 state;        // 0x2A, PTR_ARRAY_085ae4e0 の添字
  s8 idx;          // 0x2B, elems の添字, 空きは -1
  u16 spawned;     // 0x2C, 生成時に 1, 次のフレームで 0 に戻る
  u16 blinkTimer;  // 0x2E, 0 になるたびに ptcl の表示を切り替えて 38 に戻す
} Entity081eeb28Elem;
static_assert(sizeof(Entity081eeb28Elem) == 48);

// 雷が光っている間, バットに変身している間, GOOD_SEE の間だけ点滅して見える目印
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_0
  Entity081eeb28Elem elems[12];  // 0x01C
  u32 activeMask;                // 0x25C, elems の使用中ビット
} Entity081eeb28;
static_assert(sizeof(Entity081eeb28) == 608);

static Entity081eeb28* gEntity081eeb28;  // 0x030001D4

extern s32 gLightningTimer;

static inline bool8 Entity081eeb28_IsElemUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081eeb28Elem_UpdateState0(Entity081eeb28*, Entity081eeb28Elem*);
void Entity081eeb28Elem_UpdateState1(Entity081eeb28*, Entity081eeb28Elem*);
void Entity081eeb28Elem_UpdateState2(Entity081eeb28*, Entity081eeb28Elem*);
Entity081eeb28* Entity081eeb28_Create(void);
s32 Entity081eeb28_Update(Entity081eeb28* p);
s32 Entity081eeb28_Destroy(Entity081eeb28* p);
s32 Entity081eeb28_Init(Entity081eeb28* p);

void (*const PTR_ARRAY_085ae4e0[3])(Entity081eeb28*, Entity081eeb28Elem*) = {
    Entity081eeb28Elem_UpdateState0,
    Entity081eeb28Elem_UpdateState1,
    Entity081eeb28Elem_UpdateState2,
};  // 0x085AE4E0

void Entity081eeb28Elem_UpdateState0(Entity081eeb28* p, Entity081eeb28Elem* elem) {}

Entity081eeb28Elem* Entity081eeb28_AllocElem(Entity081eeb28* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity081eeb28_IsElemUsed(&p->activeMask, i)) {
      Entity081eeb28Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

// 千里眼の判定を 0/1 に落とす inline (GetLocalPlayerIdx と Player の goodCond 判定) にすると 120/120 命令まで揃うが, 0 の初期化を原典はタイマーを読んだ後に置く, BambooShootManager_Init と同じ壁
NON_MATCH void Entity081eeb28Elem_UpdateState1(Entity081eeb28* p, Entity081eeb28Elem* elem) {
#ifdef NONMATCHING_C
  Particle* ptcl = &elem->ptcl;
  bool8 visible = FALSE;

  if (elem->spawned) {
    elem->spawned = 0;
  }
  if (gGameFlags & GAMEFLAG_LINK) {
    if (gEntity9A9F != NULL && gEntity9A9F->playerIdx >= 0) {
      Player* pl = gPlayerPtr[gEntity9A9F->playerIdx];

      if (pl != NULL && pl->goodCondTimer != 0 && pl->goodCondID == GOOD_SEE) {
        visible = TRUE;
      }
    }
  } else if (gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT || (gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE)) {
    visible = TRUE;
  }
  if (visible) {
    if (!(elem->flags & 1)) {
      ptcl->flags &= ~SPRFLAG_HIDDEN;
      elem->flags |= 1;
    }
    if (elem->blinkTimer != 0) {
      elem->blinkTimer--;
    } else {
      if (elem->ptcl.flags & SPRFLAG_HIDDEN) {
        elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
      } else {
        elem->ptcl.flags |= SPRFLAG_HIDDEN;
      }
      elem->blinkTimer = 38;
    }
  } else {
    ptcl->flags |= SPRFLAG_HIDDEN;
    elem->flags &= ~1;
    elem->blinkTimer = 38;
  }
#else
  INCFUNC("asm/func/Entity081eeb28Elem_UpdateState1.inc");
#endif
}

void Entity081eeb28Elem_UpdateState2(Entity081eeb28* p, Entity081eeb28Elem* elem) {
  Entity081eeb28* p2;

  if (elem->spawned) {
    elem->spawned = 0;
  }
  p2 = gEntity081eeb28;
  CLEAR_BIT(p2->activeMask, elem->idx);
  elem->state = 0;
  Particle_Remove(&elem->ptcl);
  elem->idx = -1;
  elem->flags = 0;
}

// pos の少し上に点滅する目印を1つ出す
Entity081eeb28Elem* Entity081eeb28_Spawn(Vec3* pos) {
  Entity081eeb28* p = gEntity081eeb28;
  Entity081eeb28Elem* elem;

  if (p == NULL) {
    p = Entity081eeb28_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  elem = Entity081eeb28_AllocElem(p);
  if (elem == NULL) {
    return NULL;
  }
  elem->state = 1;
  elem->flags = 0;
  elem->blinkTimer = 0;
  elem->spawned = 1;
  elem->ptcl.pos = *pos;
  elem->ptcl.pos.y += 30;
  Particle_Add(&elem->ptcl, p->group, 0);
  Particle_SetOffset(&elem->ptcl, -8, -8);
  Particle_SetPose(&elem->ptcl, p->group, 52);
  elem->ptcl.flags |= SPRFLAG_HIDDEN;
  elem->ptcl.priority = 1;
  return elem;
}

s32 Entity081eeb28_Update(Entity081eeb28* p) {
  Entity081eeb28Elem* elems = p->elems;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (Entity081eeb28_IsElemUsed(&p->activeMask, i)) {
      PTR_ARRAY_085ae4e0[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081eeb28_Destroy(Entity081eeb28* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081eeb28_IsElemUsed(&p->activeMask, i)) {
      Particle_Remove(&p->elems[i].ptcl);
    }
  }
  gEntity081eeb28 = NULL;
  return 0;
}

s32 Entity081eeb28_Init(Entity081eeb28* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->activeMask = 0;
  gEntity081eeb28 = p;
  return 0;
}

Entity081eeb28* Entity081eeb28_Create(void) {
  Entity081eeb28* p;

  if (gEntity081eeb28 != NULL) {
    return gEntity081eeb28;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081eeb28));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081eeb28_Update, Entity081eeb28_Destroy);
    if (Entity081eeb28_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081eeb28_ClearGlobal(void) { gEntity081eeb28 = NULL; }
