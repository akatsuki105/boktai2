#include "entity.h"
#include "particle.h"
#include "global.h"

// 4個を使い回す粒子の枠
typedef struct {
  Particle ptcl;        // 0x00, _Destroy が Particle_Remove に渡す
  u8 unk_28[8];         // 0x28
  ParticleGroup* group; // 0x30, _Init が GetParticleGroup(PTCL_GROUP_2) を入れる
  u8 unk_34[2];         // 0x34
  u16 active;           // 0x36, _Update が 0 の枠を飛ばす
  u8 unk_38[8];         // 0x38
} Entity080ac574Particle;
static_assert(sizeof(Entity080ac574Particle) == 64);

typedef struct {
  Entity e;                         // 0x00, ENTITY_UNK_11
  Entity080ac574Particle ptcls[4];  // 0x18, 根拠: _Destroy / _Update / _Init の stride 0x40 × 4
} Entity080ac574;
static_assert(sizeof(Entity080ac574) == 280);

NAKED void FUN_080ac3d4(Entity080ac574Particle* ptcl) { INCFUNC("asm/func/FUN_080ac3d4.inc"); }

NAKED void FUN_080ac46c(Entity080ac574Particle* ptcl) { INCFUNC("asm/func/FUN_080ac46c.inc"); }

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

NAKED s32 Entity080ac574_Init(Entity080ac574* p) { INCFUNC("asm/func/Entity080ac574_Init.inc"); }

NAKED Entity080ac574* Entity080ac574_Create(void) { INCFUNC("asm/func/Entity080ac574_Create.inc"); }
