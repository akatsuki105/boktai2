#include "time.h"

#include "global.h"
#include "save.h"
#include "solar.h"
#include "vm.h"

COMMON_DATA Clock gClock = {};  // 0x030047E0

COMMON_DATA ALIGNED(16) RtcDataOrg gRTC = {};  // 0x03004810
COMMON_DATA u32 u32_0300481c = 0;

bool32 SetGameDateTimeIntoRTC(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second);
s32 Time_CheckRtcPowerOn(void);
static bool32 ApplyRtcToClock(void);

static void Delay(s32 n) {
  if (n > 0) {
    while (n != 0) {
      n--;
    }
  }
}

void Time_RtcIoEnable(void) { RtcIoEnable(); }

void Time_RtcIoDisable(void) { RtcIoDisable(); }

void Time_Reset(void) { ClearMemory(&gClock, sizeof(Clock)); }

// 4桁の BCD を2進数に変換する
static u16 FromBCD(u16 val) {
  u16 result = val & 0xF;

  result += ((val >> 4) & 0xF) * 10;
  result += ((val >> 8) & 0xF) * 100;
  result += ((val >> 12) & 0xF) * 1000;
  return result;
}

// 指定された月が何日まであるかを取得する
s32 Time_GetDaysInMonth(s32 year, s32 month) {
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

// 2つの日付の通算日数の差 (date1 - date2)
u32 Time_GetDayDiff(s32 year1, s32 month1, s32 day1, s32 year2, s32 month2, s32 day2) {
  s32 days1 = year1 * 365 + Div(year1, 4) - Div(year1, 100) + Div(year1, 400);
  s32 days2;
  s32 i;

  for (i = 1; i < month1; i++) {
    days1 += Time_GetDaysInMonth(year1, i);
  }
  days1 += day1;

  days2 = year2 * 365 + Div(year2, 4) - Div(year2, 100) + Div(year2, 400);
  for (i = 1; i < month2; i++) {
    days2 += Time_GetDaysInMonth(year2, i);
  }
  days2 += day2;

  return days1 - days2;
}

// ツェラーの公式, 0=日曜 .. 6=土曜
static s32 GetDayOfWeek(s32 year, s32 month, s32 day) {
  if (month <= 2) {
    year--;
    month += 12;
  }
  return Mod(year + Div(year, 4) - Div(year, 100) + Div(year, 400) + Div(13 * month + 8, 5) + day, 7);
}

// BCDDate 形式の値を解析して年・月・日を取得する
void Time_ParseBCDDate(s32* year, s32* month, s32* day, BCDDate date) {
  s32 bcd = date.val;

  *year = (date.val >> 28) * 1000 + ((bcd & 0x0F000000) >> 24) * 100 + ((bcd & 0x00F00000) >> 20) * 10 + ((bcd & 0x000F0000) >> 16);
  *month = ((bcd & 0x0000F000) >> 12) * 10 + ((bcd & 0x00000F00) >> 8);
  *day = ((bcd & 0x000000F0) >> 4) * 10 + (bcd & 0x0000000F);
}

// year, month, day を BCDDate 形式に変換して返す
static BCDDate GetBCDDate(s32 year, s32 month, s32 day) {
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
static u8 ToBCD(u8 val) {
  s32 ones = Mod(val, 10);

  return (Div(Mod(val, 100) - ones, 10) << 4) | ones;
}

// 1フレーム進める, 60フレームで1秒、日付をまたぐときは曜日も引き直す
// 残差なし・レジスタ割当のみ不一致: 原典は &gClock を r4 に退避して使い続けるが、こちらは呼び出しのあとでプール定数を読み直す
NON_MATCH void Time_AdvanceFrame(void) {
#ifdef NONMATCHING_C
  gClock.frame++;
  if (gClock.frame > 59) {
    gClock.frame = 0;
    gClock.second++;
    if (gClock.second > 59) {
      gClock.second = 0;
      gClock.minute++;
      if (gClock.minute > 59) {
        gClock.minute = 0;
        gClock.hour++;
        if (gClock.hour > 23) {
          s32 year, month, day;

          gClock.hour = 0;
          Time_ParseBCDDate(&year, &month, &day, gClock.date);
          day++;
          if (day >= Time_GetDaysInMonth(year, month)) {
            day = 1;
            month++;
            if (month > 12) {
              month = 1;
              year++;
              if (year >= 2099) year = 2099;
            }
          }
          gClock.date = GetBCDDate(year, month, day);
          gClock.dayOfWeek = GetDayOfWeek(year, month, day);
        }

        gSaveSucceeded = TRUE;
        if (gClock.sunset.hour == gClock.hour && gClock.sunset.minute == gClock.minute) {
          gClock.moonAge++;
          if (gClock.moonAge > 280) {
            gClock.moonAge = 0;
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Time_AdvanceFrame.inc");
#endif
}

// 日の入/日の出までの残り時間を引き直し、spanOfTime と遷移の進み具合を更新する
static inline void UpdateSunTimers(Clock* c) {
  s32 sunsetHour, sunsetMinute;
  s32 sunriseHour, sunriseMinute;
  s32 blend;

  sunsetHour = c->sunset.hour - c->hour;
  sunsetMinute = c->sunset.minute - c->minute;
  if (sunsetHour < 0) {
    sunsetHour += 24;
  }
  if (sunsetMinute < 0) {
    if (sunsetHour > 0) {
      sunsetHour--;
    } else {
      sunsetHour = 23;
    }
    sunsetMinute += 60;
  }

  sunriseHour = c->morning.hour - c->hour;
  sunriseMinute = c->morning.minute - c->minute;
  if (sunriseHour < 0) {
    sunriseHour += 24;
  }
  if (sunriseMinute < 0) {
    if (sunriseHour > 0) {
      sunriseHour--;
    } else {
      sunriseHour = 23;
    }
    sunriseMinute += 60;
  }

  c->untilSunset.hour = sunsetHour;
  c->untilSunset.minute = sunsetMinute;
  c->untilSunrise.hour = sunriseHour;
  c->untilSunrise.minute = sunriseMinute;

  if ((u8)(c->spanOfTime - 1) <= 2) {
    blend = (60 - sunsetMinute) << 6;
  } else {
    blend = (60 - sunriseMinute) << 6;
  }

  c->spanOfTime = Time_GetSpanOfTime();
  switch (c->spanOfTime) {
    case TIME_NIGHT: {
      c->unk_0f = Div(blend, 60) >> 1;
      break;
    }
    case TIME_MORNING: {
      c->unk_0f = (Div(blend, 60) >> 1) + 32;
      break;
    }
    case TIME_DAYTIME: {
      c->unk_0f = 0;
      break;
    }
    case TIME_SUNSET: {
      c->unk_0f = Div(blend, 60);
      break;
    }
    case TIME_UNK4: {
      c->unk_0f = Div(blend, 60);
      break;
    }
    case TIME_UNK5: {
      c->unk_0f = 0;
      break;
    }
  }
}

void Time_UpdateSunTimers(void) {
  Clock* c;

  if (u32_0300481c == 0) {
    ApplyRtcToClock();
  }

  c = &gClock;
  UpdateSunTimers(c);
}

// 日の出の時刻を設定する, サマータイムなら1時間進める
void Time_SetMorning(s32 hour, s32 minute) {
  Clock* c;

  gClock.morning.hour = hour;
  gClock.morning.minute = minute;
  if (gSystemSaveData->summerTime != 0) {
    gClock.morning.hour = hour + 1;
    if (gClock.morning.hour > 23) {
      gClock.morning.hour = hour - 23;
    }
  }

  c = &gClock;
  UpdateSunTimers(c);
}

// 日の入の時刻を設定する, サマータイムなら1時間進める
void Time_SetSunset(s32 hour, s32 minute) {
  Clock* c;

  gClock.sunset.hour = hour;
  gClock.sunset.minute = minute;
  if (gSystemSaveData->summerTime != 0) {
    gClock.sunset.hour = hour + 1;
    if (gClock.sunset.hour > 23) {
      gClock.sunset.hour = hour - 23;
    }
  }

  c = &gClock;
  UpdateSunTimers(c);
}

// ゲーム内の日付時刻を設定する, writeRTC が 1 なら RTC にも書き戻す
bool32 SetGameDateTime(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second, bool32 writeRTC) {
  bool32 ok;
  Clock* c;

  gClock.date = GetBCDDate(year, month, day);
  gClock.dayOfWeek = GetDayOfWeek(year, month, day);
  gClock.hour = hour;
  gClock.minute = minute;
  gClock.second = second;
  gClock.frame = 0;
  if (writeRTC == 1) {
    ok = SetGameDateTimeIntoRTC(year, month, day, gClock.hour, gClock.minute, gClock.second);
  } else {
    ok = 1;
  }

  c = &gClock;
  UpdateSunTimers(c);
  return ok;
}

u32 Time_GetDate(void) { return gClock.date.val; }

u32 Time_GetHour(void) { return gClock.hour; }

u32 Time_GetMinute(void) { return gClock.minute; }

u32 Time_GetSecond(void) { return gClock.second; }

u32 Time_GetDayOfWeek(void) { return gClock.dayOfWeek; }

// 現在時刻が日の出〜日の入の間かを見て、そこから untilSunrise / untilSunset で 6 段階に分ける
// 残差26命令: 原典は3つの時刻比較をそれぞれ独立に展開するが、agbcc は同じ || 式を CSE で畳む (agbcc-levers.md 参照)
NON_MATCH u32 Time_GetSpanOfTime(void) {
#ifdef NONMATCHING_C
  bool32 daytime;

  if (gClock.hour < gClock.morning.hour || (gClock.hour == gClock.morning.hour && gClock.minute < gClock.morning.minute)) {
    // 日の出前なので、日の入が日の出より後ろ (日付をまたぐ) ときだけ日中になりうる
    daytime = (gClock.sunset.hour < gClock.morning.hour || (gClock.sunset.hour == gClock.morning.hour && gClock.sunset.minute < gClock.morning.minute)) && (gClock.hour < gClock.sunset.hour || (gClock.hour == gClock.sunset.hour && gClock.minute < gClock.sunset.minute));
  } else {
    daytime = (gClock.hour < gClock.sunset.hour || (gClock.hour == gClock.sunset.hour && gClock.minute < gClock.sunset.minute)) || (gClock.sunset.hour < gClock.morning.hour || (gClock.sunset.hour == gClock.morning.hour && gClock.sunset.minute < gClock.morning.minute));
  }

  if (daytime) {
    if (gClock.untilSunrise.hour == 0) {
      return TIME_MORNING;
    }
    if (gClock.untilSunset.hour != 0) {
      return TIME_DAYTIME;
    }
    return TIME_SUNSET;
  }
  if (gClock.untilSunrise.hour == 0) {
    return TIME_NIGHT;
  }
  if (gClock.untilSunset.hour == 0) {
    return TIME_UNK4;
  }
  return TIME_UNK5;
#else
  INCFUNC("asm/func/Time_GetSpanOfTime.inc");
#endif
}

u32 Time_GetRtcStatus(void) { return gClock.rtcStatus; }

// 0xB55A, 現在の年月日と時分秒をスクリプトへ返す
void Time_GetDateTimeScripted(void) {
  s32 ymd[3];
  u8 buf[8];

  Time_ParseBCDDate(&ymd[0], &ymd[1], &ymd[2], gClock.date);
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

// 0x1C3E, 曜日をスクリプトへ返す
void Time_GetDayOfWeekScripted(void) {
  u8 buf[8];

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, gClock.dayOfWeek);
}

// 0xFBC1, スクリプトから2つの日付を受け取り、その間の日数をスクリプトへ返す
void Time_GetDayDiffScripted(void) {
  u8 buf[8];
  s32 year1 = VM_GetValue();
  s32 month1 = VM_GetValue();
  s32 day1 = VM_GetValue();
  s32 year2 = VM_GetValue();
  s32 month2 = VM_GetValue();
  s32 day2 = VM_GetValue();
  s32 days = Time_GetDayDiff(year1, month1, day1, year2, month2, day2);

  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, days);
}

// 0x3C47, 日の出の時刻と日の出までの残り時間をスクリプトへ返す
void Time_GetSunriseScripted(void) {
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

// 0x5365, 日の入りの時刻と日の入りまでの残り時間をスクリプトへ返す
void Time_GetSunsetScripted(void) {
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

// 0x2F01
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

NON_MATCH void Time_SetMoonAge(s32 days, s32 tenths) {
#ifdef NONMATCHING_C
  gClock.moonAge = days * 10 + tenths;
  gClock.moonPhase = MoonPhaseFromAge(gClock.moonAge);
#else
  INCFUNC("asm/func/Time_SetMoonAge.inc");
#endif
}

u32 Time_GetMoonAge(void) { return gClock.moonAge; }

u32 Time_GetMoonPhase(void) { return gClock.moonPhase; }

// 0x5933
u32 Time_GetMoonPhaseScripted(void) { return gClock.moonPhase; }

// RTC の起動を5回まで待ち、駄目なら 2004/7/22 12:00 で初期化する
void Time_InitFromRtc(void) {
  s32 status = 0;
  s32 i;

  for (i = 0; i < 5; i++) {
    status = Time_CheckRtcPowerOn();
    if (status != -1) {
      break;
    }
    Delay(200);
  }
  if (status == 1) {
    if (ApplyRtcToClock() == 1) {
      gClock.rtcStatus = 0;
      return;
    }
    SetGameDateTime(2004, 7, 22, 12, 0, 0, status);
    gClock.rtcStatus = status;
    return;
  }
  SetGameDateTime(2004, 7, 22, 12, 0, 0, 1);
  gClock.rtcStatus = 1;
}

// 指定した日付時刻を BCD に直して RTC へ書き戻す, 5回まで再試行する
bool32 SetGameDateTimeIntoRTC(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
  s32 status;
  s32 i;
  u16 ie;

  gRTC.year = ToBCD(year + 48);
  gRTC.month = ToBCD(month);
  gRTC.day = ToBCD(day);
  gRTC.week = GetDayOfWeek(year, month, day);
  gRTC.hour = ToBCD(hour);
  gRTC.minute = ToBCD(minute);
  gRTC.second = ToBCD(second);
  gRTC.stat = 0;
  status = 0;
  Taiyo_Disable();
  for (i = 0; i < 5; i++) {
    REG_IME = 0;
    ie = REG_IE;
    REG_IE = 0;
    Time_RtcIoEnable();
    status = RtcWriteDate(&gRTC);
    Time_RtcIoDisable();
    REG_IE = ie;
    REG_IME = 1;
    if (status == 1) {
      break;
    }
    Delay(200);
  }
  Taiyo_Enable();
  return status;
}

// RTC から日付を読み、BCD として壊れているフィールドを直して負の理由コードを返す
static bool32 ReadRtcDate(void) {
  s32 status;
  s32 i;
  u16 ie;

  Taiyo_Disable();
  for (i = 0; i < 5; i++) {
    REG_IME = 0;
    ie = REG_IE;
    REG_IE = 0;
    Time_RtcIoEnable();
    status = RtcReadDate(&gRTC);
    Time_RtcIoDisable();
    REG_IE = ie;
    REG_IME = 1;
    if (status == 1) {
      break;
    }
    Delay(200);
  }
  Taiyo_Enable();
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
static bool32 ApplyRtcToClock(void) {
  bool32 ok = ReadRtcDate();

  if (ok == 1) {
    SetGameDateTime(FromBCD(gRTC.year) + 2000, FromBCD(gRTC.month), FromBCD(gRTC.day), FromBCD(gRTC.hour), FromBCD(gRTC.minute), FromBCD(gRTC.second), FALSE);
  }
  return ok;
}

bool32 UNUSED FUN_0823e80c(void) {
  if (gClock.hour < 3) return TRUE;
  return FALSE;
}

// RTC の電源状態を見て、正常なら 1、異常なら -1 を返す
NON_MATCH s32 Time_CheckRtcPowerOn(void) {
#ifdef NONMATCHING_C
  u8 status;

  Time_RtcIoEnable();
  status = RtcPowerOnCheck();
  Time_RtcIoDisable();
  if ((status & 0xF) == 1) {
    return 1;
  }
  return -1;
#else
  INCFUNC("asm/func/Time_CheckRtcPowerOn.inc");
#endif
}
