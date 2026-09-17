#include "global.h"
#include "vm.h"
#include "weapon.h"

extern s32 s32_0300446c;

INCASM("asm/code_0823cd04.inc");

NAKED void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, unknown* param_7) { INCFUNC("asm/func/FUN_0823ce68.inc"); }

NAKED s32 FUN_0823cecc(void) { INCFUNC("asm/func/FUN_0823cecc.inc"); }

NAKED s32 FUN_0823cf90(void) { INCFUNC("asm/func/FUN_0823cf90.inc"); }

NAKED s32 FUN_0823d03c(void) { INCFUNC("asm/func/FUN_0823d03c.inc"); }

NAKED s32 FUN_0823d0e8(void) { INCFUNC("asm/func/FUN_0823d0e8.inc"); }

NAKED void FUN_0823d1d8(void) { INCFUNC("asm/func/FUN_0823d1d8.inc"); }

NAKED void FUN_0823d1fc(void) { INCFUNC("asm/func/FUN_0823d1fc.inc"); }

void FUN_0823d220(void) { SoftReset_0823a928(); }

NAKED void FUN_0823d22c(void) { INCFUNC("asm/func/FUN_0823d22c.inc"); }

NAKED void FUN_0823d280(void) { INCFUNC("asm/func/FUN_0823d280.inc"); }

void FUN_0823d2bc(void) { s32_0300446c = VM_GetKeywordValue('t', 0); }

void FUN_0823d2d4(void) { s32_0300446c = 0; }

NAKED void FUN_0823d2e0(s32 val) { INCFUNC("asm/func/FUN_0823d2e0.inc"); }

NAKED void FUN_0823d310(s32 val) { INCFUNC("asm/func/FUN_0823d310.inc"); }

void UNUSED nop_0823d33c(void) {}

u8* FUN_0823d340(void) { return VM_GetPC(); }

void* FUN_0823d34c(void) { return VM_GetValueSafe2(); }

NAKED void FUN_0823d358(void) { INCFUNC("asm/func/FUN_0823d358.inc"); }

NAKED void FUN_0823d37c(void) { INCFUNC("asm/func/FUN_0823d37c.inc"); }

void FUN_0823d3ec(void) {
  u8 val = 1;
  gSystemSaveData->unk_09 = val;
}

u32 FUN_0823d3fc(void) { return gSystemSaveData->unk_09; }

u32 FUN_0823d408(void) { return gSystemSaveData->unk_0a; }

const WeaponData* FUN_0823d414(s32 idx) { return &gWeaponDB[idx]; }

NAKED void FUN_0823d428(void) { INCFUNC("asm/func/FUN_0823d428.inc"); }

NAKED void FUN_0823d4ac(void) { INCFUNC("asm/func/FUN_0823d4ac.inc"); }

NAKED bool32 FUN_0823d4c8(void) { INCFUNC("asm/func/FUN_0823d4c8.inc"); }

NAKED s32 UpdateSolDarkSide(void) { INCFUNC("asm/func/UpdateSolDarkSide.inc"); }

NAKED s32 UpdateWeaponStyle(void) { INCFUNC("asm/func/UpdateWeaponStyle.inc"); }

NAKED s32 FUN_0823d5b8(void) { INCFUNC("asm/func/FUN_0823d5b8.inc"); }

NAKED bool32 FUN_0823d5f0(void) { INCFUNC("asm/func/FUN_0823d5f0.inc"); }

u32 FUN_0823d680(void) { return gSystemSaveData->timezone; }

bool32 FUN_0823d68c(void) {
  if (gSystemSaveData->unk_10 == 0x369F) {
    return TRUE;
  }
  return FALSE;
}

s32 FUN_0823d6b0(void) { return gSystemSaveData->unk_c; }

NAKED s32 FUN_0823d6bc(void) { INCFUNC("asm/func/FUN_0823d6bc.inc"); }

u16 FUN_0823d6f4(void) { return gSystemSaveData->unk_14; }

u16 FUN_0823d700(void) { return gSystemSaveData->unk_16; }

NAKED void FUN_0823d70c(void) { INCFUNC("asm/func/FUN_0823d70c.inc"); }

NAKED void FUN_0823d748(void) { INCFUNC("asm/func/FUN_0823d748.inc"); }
