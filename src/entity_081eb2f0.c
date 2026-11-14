#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"

// 32枠を使い回す粒子1個
typedef struct {
  Particle ptcl;           // 0x00, Entity081eb2f0_FreeElem が Particle_Remove に渡す
  AuxAnimState anim;       // 0x28, Particle_AdvanceAnim で ptcl に当てる
  u8 unk_38[0x42 - 0x38];  // 0x38, まだ未解析
  u8 state;                // 0x42, sEntity081eb2f0ElemUpdates の添字, 0: 待機, 1: 生存中, 2: 解放
  s8 slot;                 // 0x43, activeMask 上の自分のビット番号, 解放時は -1
  bool8 pendingShow;       // 0x44, 立っていると次の更新で ptcl を表示して落とす
  u8 unk_45[0x48 - 0x45];  // 0x45, まだ未解析
} Entity081eb2f0Elem;
static_assert(sizeof(Entity081eb2f0Elem) == 72);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;             // 0x018, ANIM_D1B8
  ParticleGroup* group;          // 0x01C, PTCL_GROUP_0
  Entity081eb2f0Elem elems[32];  // 0x020
  u32 activeMask;                // 0x920, 1 << i で elems[i] が使用中
} Entity081eb2f0;
static_assert(sizeof(Entity081eb2f0) == 2340);

static inline bool8 Entity081eb2f0_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

static Entity081eb2f0* gEntity081eb2f0;  // 0x030001C4

Entity081eb2f0* Entity081eb2f0_Create(void);

void Entity081eb2f0_UpdateIdle(Entity081eb2f0* p, Entity081eb2f0Elem* e) {}

// 生存中の枠, 出現直後に粒子を表示し, アニメを1コマ進めて一巡したら解放待ち (state 2) にする
void Entity081eb2f0_UpdateActive(Entity081eb2f0* p, Entity081eb2f0Elem* e) {
  Particle* ptcl = &e->ptcl;

  if (e->pendingShow) {
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    e->pendingShow = FALSE;
  }
  if (e->anim.cmdIdx == 1 && e->anim.tick == 0) {
    ptcl->pos.y += 32;
  }
  if (Particle_AdvanceAnim(ptcl, p->group, &e->anim)) {
    e->state = 2;
  }
}

// 枠を1つ解放する
void Entity081eb2f0_FreeElem(Entity081eb2f0* p, Entity081eb2f0Elem* e) {
  s32 slot;

  Particle_Remove(&e->ptcl);
  e->state = 0;
  slot = e->slot;
  p->activeMask &= ~(1 << slot);
  ClearMemory(e, sizeof(Entity081eb2f0Elem));
  e->slot = -1;
}

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081eb2f0Elem* Entity081eb2f0_AllocElem(Entity081eb2f0* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (!Entity081eb2f0_IsActive(&p->activeMask, i)) {
      Entity081eb2f0Elem* e = &p->elems[i];

      e->slot = i;
      p->activeMask |= 1 << i;
      return e;
    }
  }
  return NULL;
}

// pos に粒子を1つ出す, 次のフレームから見える
// 57/57命令, 残差は AuxAnim_SetAnim の前の movs r2, #0 が原典では &e->anim の計算より先に来る1命令の順序だけ
NON_MATCH s32 Entity081eb2f0_Spawn(Vec3* pos, u32 prio) {
#ifdef NONMATCHING_C
  Entity081eb2f0* p;
  Entity081eb2f0Elem* e;

  if (pos == NULL) {
    return -1;
  }
  p = gEntity081eb2f0;
  if (p == NULL) {
    p = Entity081eb2f0_Create();
    if (p == NULL) {
      return -1;
    }
  }
  e = Entity081eb2f0_AllocElem(p);
  if (e == NULL) {
    return -1;
  }

  e->ptcl.pos = *pos;
  Particle_Add(&e->ptcl, p->group, 0);
  Particle_SetOffset(&e->ptcl, -8, -8);
  AuxAnim_SetAnim(&e->anim, p->anim, 0, 0, 0);
  e->ptcl.flags |= SPRFLAG_HIDDEN;
  e->ptcl.priority = prio;
  e->state = 1;
  e->pendingShow = TRUE;
  return 0;
#else
  INCFUNC("asm/func/Entity081eb2f0_Spawn.inc");
#endif
}

// Entity081eb2f0_Update が (p, elem) で呼ぶ
void (*const sEntity081eb2f0ElemUpdates[3])(Entity081eb2f0*, Entity081eb2f0Elem*) = {
    Entity081eb2f0_UpdateIdle,
    Entity081eb2f0_UpdateActive,
    Entity081eb2f0_FreeElem,
};  // 0x085AE4B0

// 使用中の枠について state ごとの更新関数を呼ぶ
s32 Entity081eb2f0_Update(Entity081eb2f0* p) {
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 32; i++) {
    if (Entity081eb2f0_IsActive(&p->activeMask, i)) {
      Entity081eb2f0Elem* e = &p->elems[i];

      sEntity081eb2f0ElemUpdates[e->state](p, e);
    }
  }
  return 0;
}

s32 Entity081eb2f0_Destroy(Entity081eb2f0* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (Entity081eb2f0_IsActive(&p->activeMask, i)) {
      Entity081eb2f0Elem* e = &p->elems[i];

      Particle_Remove(&e->ptcl);
    }
  }
  gEntity081eb2f0 = NULL;
  return 0;
}

void FUN_081eb2b0(Entity081eb2f0* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
}

s32 Entity081eb2f0_Init(Entity081eb2f0* p) {
  FUN_081eb2b0(p);
  gEntity081eb2f0 = p;
  return 0;
}

Entity081eb2f0* Entity081eb2f0_Create(void) {
  Entity081eb2f0* p;

  if (gEntity081eb2f0 != NULL) {
    return gEntity081eb2f0;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081eb2f0));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081eb2f0_Update, Entity081eb2f0_Destroy);
    if (Entity081eb2f0_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void FUN_081eb33c(void) { gEntity081eb2f0 = NULL; }
