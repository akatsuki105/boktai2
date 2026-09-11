#include "entity.h"
#include "global.h"
#include "particle.h"

typedef struct {
  u8 unk_0[452];
} Entity080146e0Data;
static_assert(sizeof(Entity080146e0Data) == 452);

// おそらく ParticleManager (でもこれ以外にも別の種類の ParticleManager　があるかも？)
typedef struct Entity080146e0 {
  Entity e;                    // 0x0, ENTITY_UNK_10
  u32 unk_18;                  // 0x18
  ParticleGroup* group1;       // 0x1C, GetParticleGroup(PTCL_GROUP_1)
  ParticleGroup* group2;       // 0x20, GetParticleGroup(PTCL_GROUP_2)
  Entity080146e0Data data[6];  // 0x24, 0x080145cc
} Entity080146e0;
static_assert(sizeof(Entity080146e0) == 2748);

extern Entity080146e0* gEntity080146e0;  // 0x03000058

const u32 u32_ARRAY_085aa850[40] = {
    0x0, 0x0, 0x8, 0x9, 0xF, 0xC, 0xD, 0xE, 0x10, 0x1C, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x12, 0x11, 0x1B, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x5, 0x12, 0xA,
};

INCASM("asm/entity_080146e0.inc");

NAKED void FUN_08014d24(void) { INCFUNC("asm/func/FUN_08014d24.inc"); }
