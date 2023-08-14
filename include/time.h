#ifndef GUARD_ZOKTAI_TIME_H
#define GUARD_ZOKTAI_TIME_H

#include "gba/gba.h"

// Datetime.spanOfTime
enum SpanOfTime {
  TIME_NIGHT,
  TIME_MORNING,
  TIME_DAYTIME,
  TIME_SUNSET,
  // anymore?
};

union Date {
  u32 date;
  u8 day;
  u8 month;
  u16 year;  // BCD, 2023 -> 0x23, 0x20
};

struct Datetime {
  union Date date;
  u32 hour;
  u32 minute;
  u32 second;
};

struct Time {
  u8 hour;
  u8 minute;
} PACKED;

// 0x030047e0
struct Clock {
  union Date date;
  u8 hour;
  u8 minute;
  u8 second;
  u8 frame;
  struct Time ALIGNED(2) daytime;
  struct Time ALIGNED(2) morning;
  struct Time ALIGNED(2) sunset;
  u8 spanOfTime;
  u8 unk_0f;
  struct Time ALIGNED(2) unk_10;  // なにかの時間までの残り時間
  struct Time ALIGNED(2) unk_12;  // なにかの時間までの残り時間
  u16 unk_14;
  u8 unk_16;
  u8 unk_17;
  u32 unk_18;
  u32 unk_1c;
  u32 unk_20;
  u32 unk_24[3];
};  // 48 bytes
static_assert(sizeof(struct Clock) == 48);

// ------------------------------------------------------------------------------------------------------------------------------------

extern struct Clock gClock;

// --------------------------------------------

u32 GetDate(void);
u32 GetHour(void);
u32 GetMinute(void);
u32 GetSecond(void);

#endif  // GUARD_ZOKTAI_TIME_H
