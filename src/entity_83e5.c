#include "global.h"

typedef struct Entity83E5 {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[896 - 0x18];
} Entity83E5;
static_assert(sizeof(Entity83E5) == 896);

NAKED void FUN_08222270(Entity83E5* p) { INCFUNC("asm/func/FUN_08222270.inc"); }

NAKED void FUN_082222f0(Entity83E5* p) { INCFUNC("asm/func/FUN_082222f0.inc"); }

NAKED void FUN_0822230c(Entity83E5* p) { INCFUNC("asm/func/FUN_0822230c.inc"); }

NAKED void FUN_08222328(Entity83E5* p) { INCFUNC("asm/func/FUN_08222328.inc"); }

NAKED void FUN_082229ac(Entity83E5* p) { INCFUNC("asm/func/FUN_082229ac.inc"); }

NAKED void FUN_082229e8(Entity83E5* p) { INCFUNC("asm/func/FUN_082229e8.inc"); }

NAKED void FUN_08222a18(Entity83E5* p) { INCFUNC("asm/func/FUN_08222a18.inc"); }

NAKED void FUN_08222a54(Entity83E5* p, s32 idx) { INCFUNC("asm/func/FUN_08222a54.inc"); }

NAKED s32 Entity83E5_Update(Entity83E5* p) { INCFUNC("asm/func/Entity83E5_Update.inc"); }

s32 Entity83E5_Destroy(Entity83E5* p) {
  FUN_082222f0(p);
  return 0;
}

NAKED s32 Entity83E5_Init(Entity83E5* p) { INCFUNC("asm/func/Entity83E5_Init.inc"); }

NAKED Entity83E5* Entity83E5_Create(void) { INCFUNC("asm/func/Entity83E5_Create.inc"); }

void (*const PTR_ARRAY_085b0080[1])(Entity83E5*) = {
    FUN_08222328,
};  // 0x085b0080
