#include "global.h"

void VCountIntr(void);
void HBlankIntr(void);
void FUN_0822a188(void);
void IntrDummy(void);
void VBlankIntr(void);

// clang-format off
const Procedure gIntrTableTemplate[13] = {
    VCountIntr,   // V-count interrupt
    IntrDummy,
    IntrDummy,
    HBlankIntr,   // H-blank interrupt
    VBlankIntr,   // V-blank interrupt
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    IntrDummy,
    FUN_0822a188,
};
// clang-format on

NAKED void InitIntrHandlers(void) { INCFUNC("asm/func/InitIntrHandlers.inc"); }

NAKED void FUN_08229d80(void) { INCFUNC("asm/func/FUN_08229d80.inc"); }

NAKED void WaitForVBlank(void) { INCFUNC("asm/func/WaitForVBlank.inc"); }

NAKED void FUN_08229f4c(u32 n) { INCFUNC("asm/func/FUN_08229f4c.inc"); }

NAKED void VBlankIntr(void) { INCFUNC("asm/func/VBlankIntr.inc"); }

NAKED void VCountIntr(void) { INCFUNC("asm/func/VCountIntr.inc"); }

void HBlankIntr(void) {}

void FUN_0822a188(void) {}

void IntrDummy(void) {}
