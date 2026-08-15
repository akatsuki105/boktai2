#include "time.h"

#include "global.h"

INCASM("asm/time_0823cd04.inc");

NAKED void FUN_0823d764(void* timer) { INCFUNC("asm/func/FUN_0823d764.inc"); }

void FUN_0823d7d4(void* timer) {}

NAKED void* FUN_0823d7d8(void* a, void* b, s32 val) { INCFUNC("asm/func/FUN_0823d7d8.inc"); }

NAKED void* FUN_0823d85c(void* p) { INCFUNC("asm/func/FUN_0823d85c.inc"); }

void Delay(s32 n) {
  if (n > 0) {
    do {
      n -= 1;
    } while (n != 0);
  }
}

void FUN_0823d904(void) { RtcIoEnable(); }

void FUN_0823d910(void) { RtcIoDisable(); }

void ClearClock(void) { ClearMemory(&gClock, sizeof(Clock)); }

NAKED u32 FUN_0823d930(u32 val) { INCFUNC("asm/func/FUN_0823d930.inc"); }

NAKED s32 GetDaysInMonth(s32 year, s32 month) { INCFUNC("asm/func/GetDaysInMonth.inc"); }

NAKED s32 FUN_0823d9ec(s32 year1, s32 month1, s32 day1, s32 year2, s32 month2, s32 day2) { INCFUNC("asm/func/FUN_0823d9ec.inc"); }

NAKED s32 FUN_0823daa4(s32 year, s32 month, s32 day) { INCFUNC("asm/func/FUN_0823daa4.inc"); }

NAKED void ParseBCDDate(s32* year, s32* month, s32* day, BCDDate date) { INCFUNC("asm/func/ParseBCDDate.inc"); }

NAKED BCDDate GetBCDDate(s32 year, s32 month, s32 day) { INCFUNC("asm/func/GetBCDDate.inc"); }

// BCD
NAKED u8 FUN_0823dc40(u8 val) { INCFUNC("asm/func/FUN_0823dc40.inc"); }

NAKED void FUN_0823dc70(void) { INCFUNC("asm/func/FUN_0823dc70.inc"); }

NAKED void FUN_0823dd50(void) { INCFUNC("asm/func/FUN_0823dd50.inc"); }

NAKED void FUN_0823de38(s32 hour, s32 minute) { INCFUNC("asm/func/FUN_0823de38.inc"); }

NAKED void FUN_0823df38(s32 hour, s32 minute) { INCFUNC("asm/func/FUN_0823df38.inc"); }

NAKED bool32 SetGameDateTime(s32 year, s32 month, s32 day, u8 hour, u8 minute, u8 second, bool32 writeRTC) { INCFUNC("asm/func/SetGameDateTime.inc"); }

u32 GetDate(void) { return gClock.date.val; }
u32 GetHour(void) { return gClock.hour; }
u32 GetMinute(void) { return gClock.minute; }
u32 GetSecond(void) { return gClock.second; }
u32 FUN_0823e1a4(void) { return gClock.daytime.hour; }

// 0x0823E1B0
NAKED u32 FUN_0823e1b0(void) { INCFUNC("asm/func/FUN_0823e1b0.inc"); }

u32 FUN_0823e28c(void) { return gClock.daytime.minute; }

NAKED void FUN_0823e298(void) { INCFUNC("asm/func/FUN_0823e298.inc"); }

NAKED void FUN_0823e318(void) { INCFUNC("asm/func/FUN_0823e318.inc"); }

NAKED void FUN_0823e338(void) { INCFUNC("asm/func/FUN_0823e338.inc"); }

NAKED void FUN_0823e394(void) { INCFUNC("asm/func/FUN_0823e394.inc"); }

NAKED void FUN_0823e3e8(void) { INCFUNC("asm/func/FUN_0823e3e8.inc"); }

NAKED u32 Time_GetType(void) { INCFUNC("asm/func/Time_GetType.inc"); }

void FUN_0823e464(void) {}

void FUN_0823e468(void) {}

void FUN_0823e46c(void) {}

NAKED void FUN_0823e470(s32 a, s32 b) { INCFUNC("asm/func/FUN_0823e470.inc"); }

u32 FUN_0823e4c8(void) { return gClock.unk_14; }

u32 FUN_0823e4d4(void) { return gClock.unk_16; }

u32 FUN_0823e4e0(void) { return gClock.unk_16; }

NAKED void FUN_0823e4ec(void) { INCFUNC("asm/func/FUN_0823e4ec.inc"); }

NAKED bool32 SetGameDateTimeIntoRTC(u8 year, u8 month, u8 day, u8 hour, u8 minute, u8 second) { INCFUNC("asm/func/SetGameDateTimeIntoRTC.inc"); }

NAKED bool32 FUN_0823e650(void) { INCFUNC("asm/func/FUN_0823e650.inc"); }

NAKED bool32 FUN_0823e768(void) { INCFUNC("asm/func/FUN_0823e768.inc"); }

bool32 FUN_0823e80c(void) {
  if (gClock.hour < 3) return TRUE;
  return FALSE;
}

NAKED s32 FUN_0823e828(void) { INCFUNC("asm/func/FUN_0823e828.inc"); }

INCASM("asm/time.inc");
