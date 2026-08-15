#ifndef GUARD_ZOKTAI_TIME_H
#define GUARD_ZOKTAI_TIME_H

#include "gba/gba.h"

// Clock.spanOfTime
enum SpanOfTime {
  TIME_NIGHT,
  TIME_MORNING,
  TIME_DAYTIME,
  TIME_SUNSET,
  // anymore?
};

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

// 0x030047e0
typedef struct Clock {
  BCDDate date;                    // 0x00
  u8 hour;                         // 0x04, 0..23
  u8 minute;                       // 0x05, 0..59
  u8 second;                       // 0x06, 0..59
  u8 frame;                        // 0x07
  struct Time ALIGNED(2) daytime;  // 0x08
  struct Time ALIGNED(2) morning;  // 0x0A
  struct Time ALIGNED(2) sunset;   // 0x0C
  u8 spanOfTime;                   // 0x0E, see SpanOfTime
  u8 unk_0f;                       // 0x0F
  struct Time ALIGNED(2) unk_10;   // なにかの時間までの残り時間
  struct Time ALIGNED(2) unk_12;   // なにかの時間までの残り時間
  u16 unk_14;
  u8 unk_16;
  u8 unk_17;
  s32 latitude;                      // 0x18, 緯度
  s32 longitude;                     // 0x1C, 経度
  s32 tz;                            // 0x20, Region time zone offset
} Clock;                             // 36 bytes
static_assert(sizeof(Clock) == 36);  // 0x0823d91c でのメモリクリアのサイズ指定的に36バイトで間違いない

// ------------------------------------------------------------------------------------------------------------------------------------

extern Clock gClock;

// --------------------------------------------

u32 GetDate(void);
u32 GetHour(void);
u32 GetMinute(void);
u32 GetSecond(void);

void ParseBCDDate(s32* year, s32* month, s32* day, BCDDate date);

#endif  // GUARD_ZOKTAI_TIME_H
