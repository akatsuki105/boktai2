#include "interrupts.h"

#include "global.h"

IWRAM_DATA bool32 bool32_03000250 = FALSE;  // 0x03000250

extern vu32 gVblankFlag;  // 0x03002CB4

void VCountIntr(void);
void HBlankIntr(void);
void FUN_0822a188(void);
void VBlankIntr(void);

const Procedure gIntrTableTemplate[13] = {
    VCountIntr,  // V-count interrupt
    IntrDummy,
    IntrDummy,
    HBlankIntr,  // H-blank interrupt
    VBlankIntr,  // V-blank interrupt
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    FUN_0822a188,
};

NAKED void InitIntrHandlers(void) { INCFUNC("asm/func/InitIntrHandlers.inc"); }

NAKED void FUN_08229d80(void) { INCFUNC("asm/func/FUN_08229d80.inc"); }

void WaitForVBlank(void) {
  gVblankFlag = FALSE;

  while (!gVblankFlag) {
  }
}

NAKED void FUN_08229f4c(u32 n) { INCFUNC("asm/func/FUN_08229f4c.inc"); }

NAKED void VBlankIntr(void) { INCFUNC("asm/func/VBlankIntr.inc"); }

NAKED void VCountIntr(void) { INCFUNC("asm/func/VCountIntr.inc"); }

void HBlankIntr(void) {}

void FUN_0822a188(void) {}

void IntrDummy(void) {}
