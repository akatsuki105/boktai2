#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;            // ENTITY_UNK_8
  UnkStruct52 unk_18;  // 0x18
  u8 unk_4c[400 - 0x4c];
} Entity28CB;
static_assert(sizeof(Entity28CB) == 400);

NAKED void FUN_08089b48(Entity28CB* p, s32 val1, s32 val2, u32 val3) { INCFUNC("asm/func/FUN_08089b48.inc"); }

NAKED void FUN_08089c44(Entity28CB* p) { INCFUNC("asm/func/FUN_08089c44.inc"); }

NAKED void FUN_08089c60(Entity28CB* p) { INCFUNC("asm/func/FUN_08089c60.inc"); }

NAKED bool32 FUN_08089c7c(Entity28CB* p) { INCFUNC("asm/func/FUN_08089c7c.inc"); }

NAKED void FUN_08089ce0(Entity28CB* p) { INCFUNC("asm/func/FUN_08089ce0.inc"); }

NAKED void FUN_08089d24(Entity28CB* p) { INCFUNC("asm/func/FUN_08089d24.inc"); }

NAKED void FUN_08089d50(Entity28CB* p) { INCFUNC("asm/func/FUN_08089d50.inc"); }

NAKED void FUN_08089ddc(Entity28CB* p) { INCFUNC("asm/func/FUN_08089ddc.inc"); }

NAKED void FUN_08089e98(Entity28CB* p) { INCFUNC("asm/func/FUN_08089e98.inc"); }

NAKED void FUN_08089f38(Entity28CB* p) { INCFUNC("asm/func/FUN_08089f38.inc"); }

NAKED void FUN_08089f58(Entity28CB* p) { INCFUNC("asm/func/FUN_08089f58.inc"); }

NAKED void FUN_08089ff0(Entity28CB* p) { INCFUNC("asm/func/FUN_08089ff0.inc"); }

void (*const PTR_ARRAY_085ac044[8])(Entity28CB*) = {
    FUN_08089ce0, FUN_08089d24, FUN_08089d50, FUN_08089ddc, FUN_08089e98, FUN_08089f38, FUN_08089f58, FUN_08089ff0,
};

NAKED s32 Entity28CB_Update(Entity28CB* p) { INCFUNC("asm/func/Entity28CB_Update.inc"); }

NAKED s32 Entity28CB_Destroy(Entity28CB* p) { INCFUNC("asm/func/Entity28CB_Destroy.inc"); }

NAKED u32 FUN_0808a11c(void) { INCFUNC("asm/func/FUN_0808a11c.inc"); }

NAKED s32 Entity28CB_Init(Entity28CB* p, u32 id) { INCFUNC("asm/func/Entity28CB_Init.inc"); }

NAKED Entity28CB* Entity28CB_Create(u32 id) { INCFUNC("asm/func/Entity28CB_Create.inc"); }
