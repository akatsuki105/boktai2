#include "time.h"

#include "global.h"

u32 GetDate(void) { return gClock.date.date; }
u32 GetHour(void) { return gClock.hour; }
u32 GetMinute(void) { return gClock.minute; }
u32 GetSecond(void) { return gClock.second; }
u32 FUN_0823e1a4(void) { return gClock.daytime.hour; }
