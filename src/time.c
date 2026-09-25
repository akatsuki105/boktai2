#include "time.h"

#include "global.h"
#include "vm.h"

COMMON_DATA Clock gClock = {};  // 0x030047E0

COMMON_DATA ALIGNED(16) RtcDataOrg gRTC = {};  // 0x03004810
COMMON_DATA u32 u32_0300481c = 0;

s32 FUN_0823e828(void);
bool32 FUN_0823e768(void);

NAKED void FUN_0823d764(void* timer) { INCFUNC("asm/func/FUN_0823d764.inc"); }

void FUN_0823d7d4(void* timer) {}

NAKED void* FUN_0823d7d8(void* a, void* b, s32 val) { INCFUNC("asm/func/FUN_0823d7d8.inc"); }

NAKED void* FUN_0823d85c(void* p) { INCFUNC("asm/func/FUN_0823d85c.inc"); }

void Delay(s32 n) {
  if (n > 0) {
    while (n != 0) {
      n--;
    }
  }
}

void FUN_0823d904(void) { RtcIoEnable(); }

void FUN_0823d910(void) { RtcIoDisable(); }

void ClearClock(void) { ClearMemory(&gClock, sizeof(Clock)); }

// 4桁の BCD を2進数に変換する
u16 FromBCD(u16 val) {
  u16 result = val & 0xF;

  result += ((val >> 4) & 0xF) * 10;
  result += ((val >> 8) & 0xF) * 100;
  result += ((val >> 12) & 0xF) * 1000;
  return result;
}

s32 GetDaysInMonth(s32 year, s32 month) {
  switch (month) {
    case 2: {
      if (((Mod(year, 4) == 0) && (Mod(year, 100) != 0)) || (Mod(year, 400) == 0)) {
        return 29;
      }
      return 28;
    }
    case 4:
    case 6:
    case 9:
    case 11: {
      return 30;
    }
    default: {
      return 31;
    }
  }
}

NAKED u32 FUN_0823d9ec(s32 year1, s32 month1, s32 day1, s32 year2, s32 month2, s32 day2) { INCFUNC("asm/func/FUN_0823d9ec.inc"); }

// ツェラーの公式。0=日曜 .. 6=土曜
s32 GetDayOfWeek(s32 year, s32 month, s32 day) {
  if (month <= 2) {
    year--;
    month += 12;
  }
  return Mod(year + Div(year, 4) - Div(year, 100) + Div(year, 400) + Div(13 * month + 8, 5) + day, 7);
}

void ParseBCDDate(s32* year, s32* month, s32* day, BCDDate date) {
  s32 bcd = date.val;

  *year = (date.val >> 28) * 1000 + ((bcd & 0x0F000000) >> 24) * 100 + ((bcd & 0x00F00000) >> 20) * 10 + ((bcd & 0x000F0000) >> 16);
  *month = ((bcd & 0x0000F000) >> 12) * 10 + ((bcd & 0x00000F00) >> 8);
  *day = ((bcd & 0x000000F0) >> 4) * 10 + (bcd & 0x0000000F);
}

BCDDate GetBCDDate(s32 year, s32 month, s32 day) {
  BCDDate date;
  s32 y0 = Mod(year, 10);
  s32 y1 = Div(Mod(year, 100) - y0, 10);
  s32 y2 = Div(Mod(year, 1000) - (y0 + y1), 100);
  s32 y3 = Div(Mod(year, 10000) - (y0 + y1 + y2), 1000);
  s32 m0 = Mod(month, 10);
  s32 m1 = Div(Mod(month, 100) - m0, 10);
  s32 d0 = Mod(day, 10);
  s32 d1 = Div(Mod(day, 100) - d0, 10);

  date.val = (y3 << 28) | (y2 << 24) | (y1 << 20) | (y0 << 16) | (m1 << 12) | (m0 << 8) | (d1 << 4) | d0;
  return date;
}

// 0..99 の2進数を BCD に変換する
u8 ToBCD(u8 val) {
  s32 ones = Mod(val, 10);

  return (Div(Mod(val, 100) - ones, 10) << 4) | ones;
}

NAKED void FUN_0823dc70(void) { INCFUNC("asm/func/FUN_0823dc70.inc"); }

NAKED void FUN_0823dd50(void) { INCFUNC("asm/func/FUN_0823dd50.inc"); }

NAKED void FUN_0823de38(s32 hour, s32 minute) { INCFUNC("asm/func/FUN_0823de38.inc"); }

NAKED void FUN_0823df38(s32 hour, s32 minute) { INCFUNC("asm/func/FUN_0823df38.inc"); }

NAKED bool32 SetGameDateTime(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second, bool32 writeRTC) { INCFUNC("asm/func/SetGameDateTime.inc"); }

u32 GetDate(void) { return gClock.date.val; }

u32 GetHour(void) { return gClock.hour; }

u32 GetMinute(void) { return gClock.minute; }

u32 GetSecond(void) { return gClock.second; }

u32 FUN_0823e1a4(void) { return gClock.daytime.hour; }

// 0x0823E1B0
NAKED u32 FUN_0823e1b0(void) { INCFUNC("asm/func/FUN_0823e1b0.inc"); }

u32 FUN_0823e28c(void) { return gClock.daytime.minute; }

// 現在の年月日と時分秒をスクリプトへ返す
void FUN_0823e298(void) {
  s32 ymd[3];
  u8 buf[8];

  ParseBCDDate(&ymd[0], &ymd[1], &ymd[2], gClock.date);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, ymd[0]);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, ymd[1]);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, ymd[2]);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.hour);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.minute);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.second);
}

// 日中が始まる時刻(時)をスクリプトへ返す
void FUN_0823e318(void) {
  u8 buf[8];

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.daytime.hour);
}

// スクリプトから2つの日付を受け取り、その間の日数をスクリプトへ返す
void FUN_0823e338(void) {
  u8 buf[8];
  s32 year1 = Script_GetValue();
  s32 month1 = Script_GetValue();
  s32 day1 = Script_GetValue();
  s32 year2 = Script_GetValue();
  s32 month2 = Script_GetValue();
  s32 day2 = Script_GetValue();
  s32 days = FUN_0823d9ec(year1, month1, day1, year2, month2, day2);

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, days);
}

// 日の出の時刻と日の出までの残り時間をスクリプトへ返す
void FUN_0823e394(void) {
  u8 buf[8];

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.morning.hour);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.morning.minute);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.untilSunrise.hour);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.untilSunrise.minute);
}

// 日の入りの時刻と日の入りまでの残り時間をスクリプトへ返す
void FUN_0823e3e8(void) {
  u8 buf[8];

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.sunset.hour);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.sunset.minute);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.untilSunset.hour);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.untilSunset.minute);
}

u32 Time_GetType(void) {
  u8 buf[8];
  u32 type = gClock.spanOfTime;

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.spanOfTime);
  return type;
}

void FUN_0823e464(void) {}

void FUN_0823e468(void) {}

void FUN_0823e46c(void) {}

#ifdef NONMATCHING_C
// 月齢(10倍値)から月相 0..7 を求める
static inline u8 MoonPhaseFromAge(u16 age) {
  if (age <= 0x22) {
    return 0;
  }
  if (age <= 0x45) {
    return 1;
  }
  if (age <= 0x68) {
    return 2;
  }
  if (age <= 0x95) {
    return 3;
  }
  if (age <= 0x9F) {
    return 4;
  }
  if (age <= 0xD1) {
    return 5;
  }
  if (age <= 0xF4) {
    return 6;
  }
  return 7;
}
#endif

NON_MATCH void FUN_0823e470(s32 days, s32 tenths) {
#ifdef NONMATCHING_C
  gClock.unk_14 = days * 10 + tenths;
  gClock.moonPhase = MoonPhaseFromAge(gClock.unk_14);
#else
  INCFUNC("asm/func/FUN_0823e470.inc");
#endif
}

u32 FUN_0823e4c8(void) { return gClock.unk_14; }

u32 FUN_0823e4d4(void) { return gClock.moonPhase; }

u32 FUN_0823e4e0(void) { return gClock.moonPhase; }

// RTC の起動を5回まで待ち、駄目なら 2004/7/22 12:00 で初期化する
void FUN_0823e4ec(void) {
  s32 status = 0;
  s32 i;

  for (i = 0; i < 5; i++) {
    status = FUN_0823e828();
    if (status != -1) {
      break;
    }
    Delay(200);
  }
  if (status == 1) {
    if (FUN_0823e768() == 1) {
      gClock.daytime.minute = 0;
      return;
    }
    SetGameDateTime(2004, 7, 22, 12, 0, 0, status);
    gClock.daytime.minute = status;
    return;
  }
  SetGameDateTime(2004, 7, 22, 12, 0, 0, 1);
  gClock.daytime.minute = 1;
}

NAKED bool32 SetGameDateTimeIntoRTC(u8 year, u8 month, u8 day, u8 hour, u8 minute, u8 second) { INCFUNC("asm/func/SetGameDateTimeIntoRTC.inc"); }

// RTC から日付を読み、BCD として壊れているフィールドを直して負の理由コードを返す
bool32 FUN_0823e650(void) {
  s32 status;
  s32 i;
  u16 ie;

  SuspendSunlight();
  for (i = 0; i < 5; i++) {
    REG_IME = 0;
    ie = REG_IE;
    REG_IE = 0;
    FUN_0823d904();
    status = RtcReadDate(&gRTC);
    FUN_0823d910();
    REG_IE = ie;
    REG_IME = 1;
    if (status == 1) {
      break;
    }
    Delay(200);
  }
  FUN_0824172c();
  if (status == 1) {
    if (((gRTC.year & 0xF0) > 0x9F) || ((gRTC.year & 0xF) > 9)) {
      status = -2;
      gRTC.year = 0;
    }
    if (((u8)(gRTC.month - 1) > 0x11) || ((gRTC.month & 0xF) > 9)) {
      status = -3;
      gRTC.month = 1;
    }
    if (((u8)(gRTC.day - 1) > 0x30) || ((gRTC.day & 0xF) > 9)) {
      status = -4;
      gRTC.day = 1;
    }
    if (gRTC.week == 7) {
      status = -5;
      gRTC.week = 0;
    }
    if ((gRTC.hour > 0x23) || ((gRTC.hour & 0xF) > 9)) {
      status = -6;
      gRTC.hour = 0;
    }
    if ((gRTC.minute > 0x5F) || ((gRTC.minute & 0xF) > 9)) {
      status = -7;
      gRTC.minute = 0;
    }
    if ((gRTC.second > 0x5F) || ((gRTC.second & 0xF) > 9)) {
      status = -8;
      gRTC.second = 0;
    }
  }
  return status;
}

// RTC から日時を読み出してゲーム内時計へ取り込む
bool32 FUN_0823e768(void) {
  bool32 ok = FUN_0823e650();

  if (ok == 1) {
    SetGameDateTime(FromBCD(gRTC.year) + 2000, FromBCD(gRTC.month), FromBCD(gRTC.day), FromBCD(gRTC.hour), FromBCD(gRTC.minute), FromBCD(gRTC.second), FALSE);
  }
  return ok;
}

bool32 FUN_0823e80c(void) {
  if (gClock.hour < 3) return TRUE;
  return FALSE;
}

// RTC の電源状態を見て、正常なら 1、異常なら -1 を返す
NON_MATCH s32 FUN_0823e828(void) {
#ifdef NONMATCHING_C
  u8 status;

  FUN_0823d904();
  status = RtcPowerOnCheck();
  FUN_0823d910();
  if ((status & 0xF) == 1) {
    return 1;
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_0823e828.inc");
#endif
}
