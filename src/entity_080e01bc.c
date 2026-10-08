#include "entity.h"
#include "global.h"

typedef struct Entity080e01bc {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[3548 - 0x18];
} Entity080e01bc;
static_assert(sizeof(Entity080e01bc) == 3548);

extern Entity080e01bc* gEntity080e01bc;  // 0x0300017C

void nop_080dfa20(Entity080e01bc*, s32);
void FUN_080dfa24(Entity080e01bc*, s32);
void FUN_080dfbe4(Entity080e01bc*, s32);
void FUN_080dfde8(Entity080e01bc*, s32);

void (*const PTR_ARRAY_085ad364[4])(Entity080e01bc*, s32) = {
    nop_080dfa20,
    FUN_080dfa24,
    FUN_080dfbe4,
    FUN_080dfde8,
};  // 0x085AD364

const u8 u8_ARRAY_085ad374[80] = {
    0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0,
};  // 0x085AD374

NAKED void FUN_080df4c4(unknown* p) { INCFUNC("asm/func/FUN_080df4c4.inc"); }

NAKED void FUN_080df540(unknown* p) { INCFUNC("asm/func/FUN_080df540.inc"); }

NAKED void FUN_080df6d4(unknown* param_1) { INCFUNC("asm/func/FUN_080df6d4.inc"); }

NAKED void FUN_080df714(s32 param_1) { INCFUNC("asm/func/FUN_080df714.inc"); }

NAKED void FUN_080df730(s32 param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080df730.inc"); }

NAKED void FUN_080df760(s32 param_1, s32 param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080df760.inc"); }

NAKED void FUN_080df790(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080df790.inc"); }

NAKED void FUN_080df880(s32 param_1) { INCFUNC("asm/func/FUN_080df880.inc"); }

NAKED s32 FUN_080df8b0(unknown* p) { INCFUNC("asm/func/FUN_080df8b0.inc"); }

NAKED void FUN_080df900(unknown* p) { INCFUNC("asm/func/FUN_080df900.inc"); }

void nop_080dfa20(Entity080e01bc* p, s32 idx) {}

NAKED void FUN_080dfa24(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfa24.inc"); }

NAKED void FUN_080dfbe4(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfbe4.inc"); }

NAKED void FUN_080dfde8(Entity080e01bc* p, s32 idx) { INCFUNC("asm/func/FUN_080dfde8.inc"); }

NAKED void FUN_080dfeb0(unknown* p, unknown* param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11) { INCFUNC("asm/func/FUN_080dfeb0.inc"); }

NAKED s32 Entity080e01bc_Update(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Update.inc"); }

NAKED s32 Entity080e01bc_Destroy(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Destroy.inc"); }

NAKED s32 Entity080e01bc_Init(Entity080e01bc* p) { INCFUNC("asm/func/Entity080e01bc_Init.inc"); }

NAKED Entity080e01bc* Entity080e01bc_Create(void) { INCFUNC("asm/func/Entity080e01bc_Create.inc"); }

void Entity080e01bc_ClearGlobal(void) { gEntity080e01bc = NULL; }

NAKED void FUN_080e0214(void) { INCFUNC("asm/func/FUN_080e0214.inc"); }

NAKED void FUN_080e0248(void) { INCFUNC("asm/func/FUN_080e0248.inc"); }

NAKED void FUN_080e028c(void) { INCFUNC("asm/func/FUN_080e028c.inc"); }
