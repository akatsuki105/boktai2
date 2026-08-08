#ifndef __INCLUDE_GBA_AGBRTC_H__
#define __INCLUDE_GBA_AGBRTC_H__

#define RTC_BKUP_FLAG 0x40
#define RTC_POWER_FLAG 0x80
#define RTC_FLAGS 0xC0

#define RTC_INTMOD_MASK 0x07

typedef struct SiiRtcInfo {
  u8 year;          // 0x00
  u8 month;         // 0x01
  u8 day;           // 0x02
  u8 week;          // 0x03, pret: dayOfWeek
  u8 hour;          // 0x04
  u8 minute;        // 0x05
  u8 second;        // 0x06
  u8 stat;          // 0x07, pret: status
  u8 alarm_hour;    // 0x08, pret: alarmHour
  u8 alarm_minute;  // 0x09, pret: alarmMinute
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

// pret と 公式SDK で表記揺れがある(公式SDKの表記を優先)
#define SiiRtcUnprotect RtcIoEnable
#define SiiRtcProtect RtcIoDisable
#define SiiRtcProbe RtcPowerOnCheck
#define SiiRtcReset RtcReset
#define SiiRtcGetStatus RtcReadStat
#define SiiRtcSetStatus RtcWriteStat
#define SiiRtcGetDateTime RtcReadDate
#define SiiRtcSetDateTime RtcWriteDate
#define SiiRtcGetTime RtcReadTime
#define SiiRtcSetTime RtcWriteTime
#define SiiRtcSetAlarm RtcWriteAlarm

#endif  // __INCLUDE_GBA_AGBRTC_H__
