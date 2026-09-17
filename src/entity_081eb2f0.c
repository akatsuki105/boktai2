#include "entity.h"
#include "global.h"
#include "particle.h"

typedef struct Entity081eb2f0 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[2340 - 0x18];
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

NAKED void FUN_081eb2b0(Entity081eb2f0* p) { INCFUNC("asm/func/FUN_081eb2b0.inc"); }

NAKED s32 Entity081eb2f0_Init(Entity081eb2f0* p) { INCFUNC("asm/func/Entity081eb2f0_Init.inc"); }

NAKED Entity081eb2f0* Entity081eb2f0_Create(void) { INCFUNC("asm/func/Entity081eb2f0_Create.inc"); }

void FUN_081eb33c(void) { gEntity081eb2f0 = NULL; }
