#ifndef __INCLUDE_GBA_AGBRTC_H__
#define __INCLUDE_GBA_AGBRTC_H__

#define RTC_BKUP_FLAG 0x40
#define RTC_POWER_FLAG 0x80
#define RTC_FLAGS 0xC0

#define RTC_INTMOD_MASK 0x07

typedef struct {
  u8 year;
  u8 month;
  u8 day;
  u8 week;
  u8 hour;
  u8 minute;
  u8 second;
  u8 stat;
  u8 alarm_hour;
  u8 alarm_minute;
} RtcDataOrg;

void RtcIoEnable(void);
void RtcIoDisable(void);

u8 RtcPowerOnCheck(void);
u8 RtcReset(void);

u8 RtcReadStat(RtcDataOrg* r);
u8 RtcWriteStat(RtcDataOrg* r);
u8 RtcReadDate(RtcDataOrg* r);
u8 RtcWriteDate(RtcDataOrg* r);
u8 RtcReadTime(RtcDataOrg* r);
u8 RtcWriteTime(RtcDataOrg* r);
u8 RtcWriteAlarm(RtcDataOrg* r);

#endif  // __INCLUDE_GBA_AGBRTC_H__
