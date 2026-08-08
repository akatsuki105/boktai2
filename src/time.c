#include "time.h"

#include "global.h"

void ClearClock(void) { ClearMemory(&gClock, sizeof(Clock)); }

INCASM("asm/time1.inc");

u32 GetDate(void) { return gClock.date.date; }
u32 GetHour(void) { return gClock.hour; }
u32 GetMinute(void) { return gClock.minute; }
u32 GetSecond(void) { return gClock.second; }
u32 FUN_0823e1a4(void) { return gClock.daytime.hour; }

// 0x0823E1B0
NAKED u32 FUN_0823e1b0(void) { INCFUNC("asm/func/FUN_0823e1b0.inc"); }

u32 FUN_0823e28c(void) { return gClock.daytime.minute; }

INCASM("asm/time.inc");
