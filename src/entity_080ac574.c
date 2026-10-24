#include "entity.h"
#include "global.h"
#include "particle.h"
#include "registry.h"
#include "vm.h"

// 4個を使い回す粒子の枠
typedef struct {
  Particle ptcl;         // 0x00
  u8 unk_28[8];          // 0x28
  ParticleGroup* group;  // 0x30, PTCL_GROUP_2
  u16 unk_34;            // 0x34, FUN_080ac5b4 が探すときの照合キー
  u16 active;            // 0x36, _Update が 0 の枠を飛ばす
  u16 timer;             // 0x38, 毎フレーム +1, 3以下と7以下でコマを変え, lifetime に届くと作り直す
  u16 lifetime;          // 0x3A
  u8 unk_3c[4];          // 0x3C
} Entity080ac574Particle;
static_assert(sizeof(Entity080ac574Particle) == 64);

typedef struct {
  Entity e;                         // 0x00, ENTITY_UNK_11
  Entity080ac574Particle ptcls[4];  // 0x18
} Entity080ac574;
static_assert(sizeof(Entity080ac574) == 280);

NAKED void FUN_080ac3d4(Entity080ac574Particle* ptcl) { INCFUNC("asm/func/FUN_080ac3d4.inc"); }

void FUN_080ac46c(Entity080ac574Particle* ptcl) {
  ptcl->timer++;
  if (ptcl->timer <= 3) {
    Particle_SetFrame(&ptcl->ptcl, ptcl->group, 3);
  } else if (ptcl->timer <= 7) {
    Particle_SetFrame(&ptcl->ptcl, ptcl->group, 2);
  } else if (ptcl->timer < ptcl->lifetime) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
  } else {
    FUN_080ac3d4(ptcl);
  }
}

s32 Entity080ac574_Update(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active != 0) {
      FUN_080ac46c(&p->ptcls[i]);
    }
  }
  return 0;
}

s32 Entity080ac574_Destroy(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

// 粒子4枠を隠した状態で用意し, レジストリに自分を登録する
s32 Entity080ac574_Init(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Entity080ac574Particle* ptcl = &p->ptcls[i];
    ParticleGroup* g = GetParticleGroup(PTCL_GROUP_2);

    ptcl->group = g;
    Particle_Add(&ptcl->ptcl, g, 0);
    Particle_SetPltt(&ptcl->ptcl, 1);
    Particle_SetOffset(&ptcl->ptcl, -4, -4);
    ptcl->ptcl.priority = 2;
    ptcl->ptcl.offsetZ = 0xEC;
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->unk_34 = 0;
    ptcl->active = 0;
  }
  Registry_Add(0xA854, p, 0);
  return 0;
}

Entity080ac574* Entity080ac574_Create(void) {
  Entity080ac574* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080ac574));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080ac574_Update, Entity080ac574_Destroy);
    if (Entity080ac574_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// unk_34 が id の粒子を隠して枠を空ける
void FUN_080ac5b4(u32 id) {
  Entity080ac574* p = Registry_Find(0xA854);
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active != 0 && p->ptcls[i].unk_34 == id) {
      p->ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
      p->ptcls[i].active = 0;
    }
  }
}

void FUN_080ac5f4(void) {
  if (VM_SeekToNamedArg('n')) {
    FUN_080ac5b4(VM_GetValue());
  }
}

NAKED void FUN_080ac60c(u16 param_1, unknown* param_2, u16 param_3, u16 param_4) { INCFUNC("asm/func/FUN_080ac60c.inc"); }

NAKED void FUN_080ac698(void) { INCFUNC("asm/func/FUN_080ac698.inc"); }
