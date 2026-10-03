#ifndef __INCLUDE_BOKTAI2_TIME_H__
#define __INCLUDE_BOKTAI2_TIME_H__

#include "gba/gba.h"

// Clock.spanOfTime
// Time_GetSpanOfTime が返す条件: 日中かどうか (現在時刻が morning〜sunset の間か) と untilSunrise / untilSunset の hour が 0 かどうかの組み合わせ
#define TIME_NIGHT 0    // 日中でない + untilSunrise.hour == 0
#define TIME_MORNING 1  // 日中 + untilSunrise.hour == 0
#define TIME_DAYTIME 2  // 日中 + untilSunrise.hour != 0 + untilSunset.hour != 0
#define TIME_SUNSET 3   // 日中 + untilSunrise.hour != 0 + untilSunset.hour == 0
#define TIME_UNK4 4     // 日中でない + untilSunrise.hour != 0 + untilSunset.hour == 0
#define TIME_UNK5 5     // 日中でない + untilSunrise.hour != 0 + untilSunset.hour != 0

// BCD
typedef union {
  u32 val;  // BCD: 2026/8/11 -> 0x20260811
  // --
  u8 day;    // BCD: 11日 -> 0x11
  u8 month;  // BCD: 10月 -> 0x10
  u16 year;  // BCD, 2023年 -> 0x23, 0x20
} BCDDate;   // 4 bytes

typedef struct {
  BCDDate date;  // ここだけ BCD
  u32 hour;      // 0..23
  u32 minute;    // 0..59
  u32 second;    // 0..59
} Datetime;

struct Time {
  u8 hour;    // 0..23
  u8 minute;  // 0..59
} PACKED;

// 0x030047E0
typedef struct {
  BCDDate date;                         // 0x00
  u8 hour;                              // 0x04, 0..23
  u8 minute;                            // 0x05, 0..59
  u8 second;                            // 0x06, 0..59
  u8 frame;                             // 0x07
  u8 dayOfWeek;                         // 0x08, GetDayOfWeek が返す曜日
  u8 rtcStatus;                         // 0x09, RTC の読み出し結果, 0 なら正常, 負なら壊れていたフィールドの理由コード
  struct Time ALIGNED(2) morning;       // 0x0A, 日の出の時刻
  struct Time ALIGNED(2) sunset;        // 0x0C, 日の入りの時刻
  u8 spanOfTime;                        // 0x0E, see TIMESPAN_XXXX
  u8 unk_0f;                            // 0x0F
  struct Time ALIGNED(2) untilSunset;   // 0x10, 日の入までの残り時間
  struct Time ALIGNED(2) untilSunrise;  // 0x12, 日の出までの残り時間
  u16 moonAge;                          // 0x14, 月齢の10倍, 日の入のたびに +1 し 280 を超えると 0 に戻る
  u8 moonPhase;                         // 0x16
  u8 unk_17;                            // 0x17
  s32 latitude;                         // 0x18, 緯度
  s32 longitude;                        // 0x1C, 経度
  s32 tz;                               // 0x20, Region time zone offset
} Clock;                                // 36 bytes
static_assert(sizeof(Clock) == 36);     // 0x0823d91c でのメモリクリアのサイズ指定的に36バイトで間違いない

// ------------------------------------------------------------------------------------------------------------------------------------

extern Clock gClock;  // 0x030047E0

// --------------------------------------------

void Time_Reset(void);
u32 Time_GetDate(void);
u32 Time_GetHour(void);
u32 Time_GetMinute(void);
u32 Time_GetSecond(void);
u32 Time_GetDayDiff(s32 year1, s32 month1, s32 day1, s32 year2, s32 month2, s32 day2);
u32 Time_GetSpanOfTime(void);
void Time_ParseBCDDate(s32* year, s32* month, s32* day, BCDDate date);
s32 Time_SetLocation(s32 latitude, s32 longitude, s32 tz);

#endif  // __INCLUDE_BOKTAI2_TIME_H__
