#include "animation.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"

typedef struct {
  Entity e;             // ENTITY_UNK_8
  AuxAnimFile* anim;  // 0x18, 根拠: Entity08016660_Init
  void* unk_1c;         // 0x1C
} Entity08016660;
static_assert(sizeof(Entity08016660) == 32);

COMMON_DATA Entity08016660* gEntity08016660 = NULL;  // 0x03002B44

void FUN_08016430(unknown*);
void FUN_08016454(unknown*);

void (*const PTR_ARRAY_085aa918[2])(unknown*) = {
    FUN_08016430,
    FUN_08016454,
};  // 0x085AA918

void FUN_08016060(void) { gEntity08016660 = NULL; }

NAKED void FUN_0801606c(HitboxData* a, HitboxData* b, unknown* p) { INCFUNC("asm/func/FUN_0801606c.inc"); }

void nop_08016090(void) { return; }

NAKED s32 FUN_08016094(Entity08016660* p, unknown* data) { INCFUNC("asm/func/FUN_08016094.inc"); }

NAKED s32 FUN_080160b0(Entity08016660* p, unknown* data) { INCFUNC("asm/func/FUN_080160b0.inc"); }

NAKED s32 FUN_080160cc(unknown* p) { INCFUNC("asm/func/FUN_080160cc.inc"); }

NAKED s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos) { INCFUNC("asm/func/FUN_08016110.inc"); }

NAKED void UNUSED FUN_0801638c(void) { INCFUNC("asm/func/FUN_0801638c.inc"); }

NAKED void FUN_08016430(unknown* p) { INCFUNC("asm/func/FUN_08016430.inc"); }

NAKED void FUN_08016454(unknown* p) { INCFUNC("asm/func/FUN_08016454.inc"); }

NAKED s32 Entity08016660_Update(Entity08016660* p) { INCFUNC("asm/func/Entity08016660_Update.inc"); }

NAKED s32 Entity08016660_Destroy(Entity08016660* p) { INCFUNC("asm/func/Entity08016660_Destroy.inc"); }

NAKED s32 Entity08016660_Init(Entity08016660* p, u32 id) { INCFUNC("asm/func/Entity08016660_Init.inc"); }

NAKED Entity08016660* Entity08016660_Create(u32 id, u32 _) { INCFUNC("asm/func/Entity08016660_Create.inc"); }
