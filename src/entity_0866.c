#include "animation.h"
#include "entity.h"
#include "global.h"
#include "particle.h"

typedef struct Entity0866 {
  Entity e;   // 0x0, ENTITY_UNK_10
  u8 unk_18;  // 0x18
  u8 unk_19[3];
  ParticleGroup* group0;   // 0x1C, PTCL_GROUP_0
  ParticleGroup* group1;   // 0x20, PTCL_GROUP_1
  AnimationFile* anim_24;  // 0x24
  AnimationFile* anim_28;  // 0x28
  u8 unk_2c[2540 - 0x2C];
} Entity0866;
static_assert(sizeof(Entity0866) == 2540);

extern Entity0866* gEntity0866;  // 0x03000040

// --------------------------------------------

void FUN_08009c28(Entity0866*, unknown*);
void FUN_08009c44(Entity0866*, unknown*);
void FUN_08009e28(Entity0866*, unknown*);
void FUN_08009e54(Entity0866*, unknown*);

// clang-format off
void (*const PTR_ARRAY_085aa6b8[6])(Entity0866*, unknown*) = {
    FUN_08009c28,
    FUN_08009e28,
    FUN_08009e54,
    FUN_08009c44,
    FUN_08009e28,
    FUN_08009e54,
};  // 0x085AA6B8
// clang-format on

// --------------------------------------------

INCASM("asm/entity_0866.inc");
