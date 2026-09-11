#include "animation.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
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

void FUN_08009b04(void) { gEntity0866 = NULL; }

NAKED void* FUN_08009b10(Entity0866* p) { INCFUNC("asm/func/FUN_08009b10.inc"); }

NAKED void FUN_08009b30(HitboxData* a, HitboxData* b, void* owner) { INCFUNC("asm/func/FUN_08009b30.inc"); }

NAKED s32 FUN_08009b6c(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009b6c.inc"); }

NAKED s32 FUN_08009c08(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009c08.inc"); }

NAKED void FUN_08009c28(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009c28.inc"); }

NAKED void FUN_08009c44(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009c44.inc"); }

NAKED void FUN_08009e28(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009e28.inc"); }

NAKED void FUN_08009e54(Entity0866* p, unknown* param_2) { INCFUNC("asm/func/FUN_08009e54.inc"); }

NAKED s32 Entity0866_Update(Entity0866* p) { INCFUNC("asm/func/Entity0866_Update.inc"); }

NAKED s32 Entity0866_Destroy(Entity0866* p) { INCFUNC("asm/func/Entity0866_Destroy.inc"); }

NAKED s32 Entity0866_Init(Entity0866* p, u32 _) { INCFUNC("asm/func/Entity0866_Init.inc"); }

Entity0866* Entity0866_Create(u32 _, u32 unused) {
  Entity0866* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity0866));
  if (p != NULL) {
    SetEntityRoutine(p, Entity0866_Update, Entity0866_Destroy);
    if (Entity0866_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 FUN_0800a2f8(void) { INCFUNC("asm/func/FUN_0800a2f8.inc"); }

NAKED u32 VM_Sub78EE(void) { INCFUNC("asm/func/VM_Sub78EE.inc"); }

NAKED void FUN_0800a458(void) { INCFUNC("asm/func/FUN_0800a458.inc"); }
