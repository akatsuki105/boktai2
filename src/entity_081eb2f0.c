#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"

// 32枠を使い回す粒子1個
typedef struct {
  Particle ptcl;           // 0x00, FUN_081eb0ec が Particle_Remove に渡す
  AuxAnimState anim;       // 0x28, Particle_AdvanceAnim で ptcl に当てる
  u8 unk_38[0x42 - 0x38];  // 0x38, まだ未解析
  u8 unk_42;               // 0x42, FUN_081eb0ec が 0 に戻し, FUN_081eafc0 はアニメが一巡すると 2 にする
  s8 slot;                 // 0x43, activeMask 上の自分のビット番号, 解放時は -1
  u8 unk_44;               // 0x44, FUN_081eafc0 が立っていたら ptcl.flags の bit0 を落として 0 に戻す
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

void FUN_081eafbc(Entity081eb2f0* p, Entity081eb2f0Elem* e) {}

// 生存中の枠, 出現直後に粒子を表示し, アニメを1コマ進めて一巡したら解放待ち (state 2) にする
void FUN_081eafc0(Entity081eb2f0* p, Entity081eb2f0Elem* e) {
  Particle* ptcl = &e->ptcl;

  if (e->unk_44) {
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    e->unk_44 = 0;
  }
  if (e->anim.cmdIdx == 1 && e->anim.tick == 0) {
    ptcl->pos.y += 32;
  }
  if (Particle_AdvanceAnim(ptcl, p->group, &e->anim)) {
    e->unk_42 = 2;
  }
}

// 枠を1つ解放する
void FUN_081eb0ec(Entity081eb2f0* p, Entity081eb2f0Elem* e) {
  s32 slot;

  Particle_Remove(&e->ptcl);
  e->unk_42 = 0;
  slot = e->slot;
  p->activeMask &= ~(1 << slot);
  ClearMemory(e, sizeof(Entity081eb2f0Elem));
  e->slot = -1;
}

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081eb2f0Elem* FUN_081eb12c(Entity081eb2f0* p) {
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

NAKED s32 FUN_081eb178(Vec3* pos, u32 prio) { INCFUNC("asm/func/FUN_081eb178.inc"); }

// Entity081eb2f0_Update が (p, elem) で呼ぶ
void (*const PTR_ARRAY_085ae4b0[3])(Entity081eb2f0*, Entity081eb2f0Elem*) = {
    FUN_081eafbc,
    FUN_081eafc0,
    FUN_081eb0ec,
};  // 0x085AE4B0

NAKED s32 Entity081eb2f0_Update(Entity081eb2f0* p) { INCFUNC("asm/func/Entity081eb2f0_Update.inc"); }

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
