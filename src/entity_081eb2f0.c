#include "animation.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"

typedef struct Entity081eb2f0 {
  Entity e;                 // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;        // 0x018, FUN_081eb2b0 が GetFile(DIR_ANIMATION, 0xD1B8)
  ParticleGroup* group;     // 0x01C, FUN_081eb2b0 が GetParticleGroup(0x1C1A)
  u8 unk_20[2340 - 0x020];  // 0x020
} Entity081eb2f0;
static_assert(sizeof(Entity081eb2f0) == 2340);

extern Entity081eb2f0* gEntity081eb2f0;  // 0x030001C4

void FUN_081eafbc(Entity081eb2f0* p, Particle* ptcl) {}

NAKED void FUN_081eafc0(Entity081eb2f0* p, Particle* ptcl) { INCFUNC("asm/func/FUN_081eafc0.inc"); }

NAKED void FUN_081eb0ec(Entity081eb2f0* p, Particle* ptcl) { INCFUNC("asm/func/FUN_081eb0ec.inc"); }

NAKED Particle* FUN_081eb12c(Entity081eb2f0* p) { INCFUNC("asm/func/FUN_081eb12c.inc"); }

NAKED s32 FUN_081eb178(Vec3* pos, u32 prio) { INCFUNC("asm/func/FUN_081eb178.inc"); }

NAKED s32 Entity081eb2f0_Update(Entity081eb2f0* p) { INCFUNC("asm/func/Entity081eb2f0_Update.inc"); }

NAKED s32 Entity081eb2f0_Destroy(Entity081eb2f0* p) { INCFUNC("asm/func/Entity081eb2f0_Destroy.inc"); }

void FUN_081eb2b0(Entity081eb2f0* p) {
  p->group = GetParticleGroup(0x1C1A);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
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
