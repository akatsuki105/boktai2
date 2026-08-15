#include "camera.h"
#include "entity_unk.h"
#include "global.h"

void FUN_0822d0e4(void);
void FUN_08230dc4(bool32 val);

NAKED s32 FUN_0823a6c0(void) { INCFUNC("asm/func/FUN_0823a6c0.inc"); }

NAKED s32 FUN_0823a6fc(void) { INCFUNC("asm/func/FUN_0823a6fc.inc"); }

INCASM("asm/code_0823a6c0.inc");

NAKED bool32 FUN_0823a8b0(void) { INCFUNC("asm/func/FUN_0823a8b0.inc"); }

NAKED void FUN_0823a8f4(u32 val) { INCFUNC("asm/func/FUN_0823a8f4.inc"); }

void FUN_0823a910(void) { bool32_03004788 = TRUE; }

void FUN_0823a91c(void) { bool32_03004788 = FALSE; }

NAKED s32 SoftReset_0823a928(void) { INCFUNC("asm/func/SoftReset_0823a928.inc"); }

NAKED void FUN_0823a9c4(void) { INCFUNC("asm/func/FUN_0823a9c4.inc"); }

NAKED void FUN_0823a9f4(void) { INCFUNC("asm/func/FUN_0823a9f4.inc"); }

NAKED void FUN_0823aa10(void) { INCFUNC("asm/func/FUN_0823aa10.inc"); }

NAKED void FUN_0823aa44(void) { INCFUNC("asm/func/FUN_0823aa44.inc"); }

void FUN_0823aa70(void) {}

void FUN_0823aa74(void) {
  FUN_08230dc4(FALSE);
  FUN_0822d0e4();
}

void FUN_0823aa84(void) {
  FUN_0823b1ec();
  Camera_0823b744();
}

NAKED s32 Entity1_030016a0_Update(Entity1_030016a0* p) { INCFUNC("asm/func/Entity1_030016a0_Update.inc"); }

s32 Entity1_030016a0_Destroy(Entity1_030016a0* _) {}

NAKED void FUN_0823acbc(void) { INCFUNC("asm/func/FUN_0823acbc.inc"); }

NAKED s32 FUN_0823ad98(void) { INCFUNC("asm/func/FUN_0823ad98.inc"); }

NAKED UNK_PTR FUN_0823adc0(void) { INCFUNC("asm/func/FUN_0823adc0.inc"); }

NAKED bool32 FUN_0823add0(u32 sid, void* _) { INCFUNC("asm/func/FUN_0823add0.inc"); }

NAKED bool32 FUN_0823ae14(UNK_PTR p) { INCFUNC("asm/func/FUN_0823ae14.inc"); }
