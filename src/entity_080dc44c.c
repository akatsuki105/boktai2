#include "animation.h"
#include "entity.h"
#include "file.h"
#include "particle.h"
#include "global.h"

// 8枠ぶんの演出要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  u8 unk_0[0x17];  // 0x00
  s8 idx;          // 0x17, 自分の添字。ptcls と activeMask のビットを指す
  u8 unk_18[4];    // 0x18
} Entity080dc44cSlot;
static_assert(sizeof(Entity080dc44cSlot) == 28);

typedef struct Entity080dc44c {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;            // 0x018, FUN_080dc418 が GetFile(0x922E, 0xD1B8) を入れる
  ParticleGroup* group;         // 0x01C, FUN_080dc418 が GetParticleGroup(PTCL_GROUP_0) を入れる
  Particle ptcls[8];            // 0x020, slots[i].idx が添字
  u8 unk_160[0x80];             // 0x160
  u32 activeMask;               // 0x1E0, 使用中の slots のビットマスク
  Entity080dc44cSlot slots[8];  // 0x1E4, 根拠: _Destroy の stride 0x1C × 8
} Entity080dc44c;
static_assert(sizeof(Entity080dc44c) == 708);

extern Entity080dc44c* gEntity080dc44c;  // 0x03000168

void FUN_080dbeb0(void) {}

s32 FUN_080dc0d0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);

NAKED void FUN_080dbeb4(Entity080dc44c* p, u32 param_2) { INCFUNC("asm/func/FUN_080dbeb4.inc"); }

NAKED void FUN_080dc00c(Entity080dc44c* p, u32 param_2) { INCFUNC("asm/func/FUN_080dc00c.inc"); }

NAKED s32 FUN_080dc050(Entity080dc44c* p) { INCFUNC("asm/func/FUN_080dc050.inc"); }

s32 FUN_080dc0a0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  return FUN_080dc0d0(p, param_2, param_3, param_4, param_5, param_6);
}

s32 FUN_080dc0b8(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
  return FUN_080dc0d0(p, param_2, param_3, param_4, param_5, 2);
}

NAKED s32 FUN_080dc0d0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_080dc0d0.inc"); }

NAKED s32 Entity080dc44c_Update(Entity080dc44c* p) { INCFUNC("asm/func/Entity080dc44c_Update.inc"); }

NAKED s32 Entity080dc44c_Destroy(Entity080dc44c* p) { INCFUNC("asm/func/Entity080dc44c_Destroy.inc"); }

void FUN_080dc418(Entity080dc44c* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
}

s32 Entity080dc44c_Init(Entity080dc44c* p) {
  FUN_080dc418(p);
  return 0;
}

Entity080dc44c* Entity080dc44c_Create(void) {
  if (gEntity080dc44c == NULL) {
    Entity080dc44c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080dc44c));
    gEntity080dc44c = p;
    if (p != NULL) {
      SetEntityRoutine(p, Entity080dc44c_Update, Entity080dc44c_Destroy);
      if (Entity080dc44c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080dc44c;
}

void FUN_080dc498(void) { gEntity080dc44c = NULL; }
