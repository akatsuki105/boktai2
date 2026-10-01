#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "sprite.h"

// Entity0866 が16個抱える枠
typedef struct {
  u8 unk_00[2];            // 0x00, まだ未解析
  u8 unk_02;               // 0x02, FUN_08009e28 が 2 を入れる
  u8 unk_03[2];            // 0x03, まだ未解析
  bool8 active;            // 0x05, 0 の枠を FUN_08009b10 が空きとして返す
  u8 unk_06;               // 0x06, まだ未解析
  bool8 unk_07;            // 0x07, FUN_08009c28 が読んで落とす目印
  u8 unk_08[2];            // 0x08, まだ未解析
  u16 unk_0a;              // 0x0A, FUN_08009e28 が毎フレーム +1 して 30 を超えたら 0 に戻す
  u8 unk_0c[0x14 - 0x0C];  // 0x0C, まだ未解析
  HitboxData hitbox;       // 0x14
  Particle ptcl;           // 0x64
  u8 unk_8c[0x9C - 0x8C];  // 0x8C, まだ未解析
} Entity0866Elem;
static_assert(sizeof(Entity0866Elem) == 156);

typedef struct {
  Entity e;   // 0x0, ENTITY_UNK_10
  u8 unk_18;  // 0x18
  u8 unk_19[3];
  ParticleGroup* group0;     // 0x1C, PTCL_GROUP_0
  ParticleGroup* group1;     // 0x20, PTCL_GROUP_1
  AuxAnimFile* anim_24;      // 0x24
  AuxAnimFile* anim_28;      // 0x28
  Entity0866Elem elems[16];  // 0x2C
} Entity0866;
static_assert(sizeof(Entity0866) == 2540);

IWRAM_DATA Entity0866* gEntity0866 = NULL;  // 0x03000040

// --------------------------------------------

void FUN_08009c28(Entity0866*, Entity0866Elem*);
void FUN_08009c44(Entity0866*, Entity0866Elem*);
void FUN_08009e28(Entity0866*, Entity0866Elem*);
void FUN_08009e54(Entity0866*, Entity0866Elem*);

// clang-format off
void (*const PTR_ARRAY_085aa6b8[6])(Entity0866*, Entity0866Elem*) = {
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

// 空いている枠を返す, 無ければ NULL
Entity0866Elem* FUN_08009b10(Entity0866* p) {
  Entity0866Elem* e;
  s32 i;

  for (i = 0, e = p->elems; i < 16; i++) {
    if (e->active == 0) {
      return e;
    }

    e++;
  }

  return NULL;
}

NAKED void FUN_08009b30(HitboxData* a, HitboxData* b, void* owner) { INCFUNC("asm/func/FUN_08009b30.inc"); }

NAKED s32 FUN_08009b6c(Entity0866* p, Entity0866Elem* param_2) { INCFUNC("asm/func/FUN_08009b6c.inc"); }

s32 FUN_08009c08(Entity0866* p, Entity0866Elem* e) {
  Particle_Remove(&e->ptcl);
  Hitbox_Unregister(&e->hitbox);
  e->active = FALSE;
  return 0;
}

void FUN_08009c28(Entity0866* p, Entity0866Elem* e) {
  if (e->unk_07) {
    e->unk_07 = FALSE;
    e->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_08009c44(Entity0866* p, Entity0866Elem* param_2) { INCFUNC("asm/func/FUN_08009c44.inc"); }

NON_MATCH void FUN_08009e28(Entity0866* p, Entity0866Elem* e) {
#ifdef NONMATCHING_C
  if (e->unk_07) {
    e->unk_07 = FALSE;
  }

  if (e->unk_0a++ > 30) {
    e->unk_02 = 2;
    e->unk_0a = 0;
    e->unk_07 = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08009e28.inc");
#endif
}

NAKED void FUN_08009e54(Entity0866* p, Entity0866Elem* param_2) { INCFUNC("asm/func/FUN_08009e54.inc"); }

NAKED s32 Entity0866_Update(Entity0866* p) { INCFUNC("asm/func/Entity0866_Update.inc"); }

s32 Entity0866_Destroy(Entity0866* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    Entity0866Elem* e = &p->elems[i];

    if (e->active) {
      FUN_08009c08(p, e);
    }
  }

  gEntity0866 = NULL;
  return 0;
}

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

void FUN_0800a458(void) {
  Entity0866* p = gEntity0866;
  s32 i;

  if (p == NULL) return;

  for (i = 0; i < 16; i++) {
    Entity0866Elem* e = &p->elems[i];

    if (e->active) {
      FUN_08009c08(p, e);
    }
  }
}
