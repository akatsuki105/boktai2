#include "hitbox.h"

#include "entity.h"
#include "global.h"

typedef struct HitboxManager {
  Entity e;            // 0x0, ENTITY_UNK_11
  HitboxData* unk_18;  // 0x18
  HitboxData* unk_1c;  // 0x1C
  HitboxData* unk_20;  // 0x20
  HitboxData* unk_24;  // 0x24
  HitboxData data0;    // 0x28
  HitboxData data1;    // 0x78
  u16 unk_c8;          // 0xC8
  u16 unk_ca;          // 0xCA
} HitboxManager;
static_assert(sizeof(HitboxManager) == 204);

extern HitboxManager* gHitboxManager;  // 0x03000780

void FUN_08236514(HitboxData* p, u32 val1, u32 val2, u32 val3) {
  p->unk_3c = val1;
  p->unk_38 = val2;
  p->unk_34 = val3;
}

void FUN_0823651c(HitboxData* p, void* handler, void* owner) {
  p->fn = handler;
  p->owner = owner;
}

NAKED void FUN_08236524(HitboxData* a, HitboxData* b) { INCFUNC("asm/func/FUN_08236524.inc"); }

NAKED void FUN_08236640(unknown* a, unknown* b) { INCFUNC("asm/func/FUN_08236640.inc"); }

NAKED void FUN_08236768(void* a, void* b, void* c) { INCFUNC("asm/func/FUN_08236768.inc"); }
NAKED void FUN_082367e4(void* a, void* b, void* c) { INCFUNC("asm/func/FUN_082367e4.inc"); }
NAKED bool32 FUN_082368d4(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/FUN_082368d4.inc"); }
NAKED bool32 Unused_FUN_082369cc(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/Unused_FUN_082369cc.inc"); }
NAKED bool32 Unused_FUN_08236ac4(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/Unused_FUN_08236ac4.inc"); }
NAKED bool32 Unused_FUN_08236bbc(void* a, void* b, void* c, void* d) { INCFUNC("asm/func/Unused_FUN_08236bbc.inc"); }
NAKED bool32 Unused_FUN_08236c18(void* a, void* b) { INCFUNC("asm/func/Unused_FUN_08236c18.inc"); }

NAKED void FUN_08236d10(void* unused1, void* unused2, HitboxData* unk_1c, HitboxData* unk_18) { INCFUNC("asm/func/FUN_08236d10.inc"); }

NAKED void Entity08236ed0_Update_Helper_08236d70(void* unused1, void* unused2, HitboxData* unk_1c, HitboxData* unk_18) { INCFUNC("asm/func/Entity08236ed0_Update_Helper_08236d70.inc"); }

NAKED s32 Entity08236ed0_Update(HitboxManager* p) { INCFUNC("asm/func/Entity08236ed0_Update.inc"); }

s32 Entity08236ed0_Destroy(HitboxManager* p) {
  gHitboxManager = NULL;
  return 0;
}

// 他の Entity_Init 関数とシグネチャが違う
NAKED void Entity08236ed0_Init(void) { INCFUNC("asm/func/Entity08236ed0_Init.inc"); }

NAKED HitboxManager* Entity08236ed0_Create(void) { INCFUNC("asm/func/Entity08236ed0_Create.inc"); }

HitboxManager* FUN_08236f0c(void) { return gHitboxManager; }

// AABBのOverlapを判定する関数
NAKED bool32 Hitbox_CheckOverlap(HitboxData* a, HitboxData* b) { INCFUNC("asm/func/Hitbox_CheckOverlap.inc"); }
