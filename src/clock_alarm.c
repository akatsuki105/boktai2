#include "entity.h"
#include "global.h"
#include "time.h"
#include "vm.h"

// 実時計を見張り、正午・夜明け・日没に差しかかった回に1度だけスクリプトを起動する
typedef struct {
  Entity e;          // 0x00, ENTITY_UNK_8
  s16 hour;          // 0x18, Time_GetHour()
  s16 minute;        // 0x1A, Time_GetMinute()
  s16 second;        // 0x1C, Time_GetSecond()
  s16 frameCounter;  // 0x1E, 毎フレーム +1, 60 になったフレームだけ判定を飛ばして 0 に戻す
  s32 secondOfDay;   // 0x20, hour * 3600 + minute * 60 + second
  s32 window;        // 0x24, '.d=60', 夜明け・日没と一致とみなす秒数の幅
  s32 scriptID;      // 0x28, '.p=0', 0 以外なら VM_ExecByID で実行する
  u8 armed[4];       // 0x2C, Init が4つとも 1, 0=正午 1=夜明け 2=日没, 窓に入った回に1度だけ発火して 0 になる, [3] は読み手なし
} ClockAlarm;
static_assert(sizeof(ClockAlarm) == 48);

// どの時刻に差しかかったか (0=正午 1=夜明け 2=日没) を引数にしてスクリプトを起動する
void ClockAlarm_Fire(ClockAlarm* p, u32 kind) {
  ScriptArgs args;
  args.argc = 1, args.argv = &kind;
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, &args);
  }
}

// target 時刻から window 秒以内に入った回に1度だけ kind でスクリプトを起動し, 窓を出たら次に備える
static inline void ClockAlarm_Check(ClockAlarm* p, s32 target, s32 window, u32 kind) {
  s32 d = abs(p->secondOfDay - target);

  if (d >= 43200) {
    d -= 86400;
  }
  if (abs(d) <= window) {
    if (p->armed[kind] != 0) {
      p->armed[kind] = 0;
      ClockAlarm_Fire(p, kind);
    }
  } else {
    p->armed[kind] = 1;
  }
}

// 正午・夜明け・日没に差しかかったら、それぞれ1度だけスクリプトを起動する
// 1つ目の abs が原典では t < target の比較で書かれ, 0 を r5 に置いて使い回す (19 hunk), 比較形にすると 12 hunk
NON_MATCH s32 ClockAlarm_Update(ClockAlarm* p) {
#ifdef NONMATCHING_C
  p->frameCounter++;
  if (p->frameCounter > 59) {
    p->frameCounter = 0;
    return 0;
  }
  p->hour = Time_GetHour();
  p->minute = Time_GetMinute();
  p->second = Time_GetSecond();
  p->secondOfDay = p->hour * 3600 + p->minute * 60 + p->second;
  ClockAlarm_Check(p, 43230, 30, 0);
  ClockAlarm_Check(p, gClock.morning.hour * 3600 + gClock.morning.minute * 60, p->window, 1);
  ClockAlarm_Check(p, gClock.sunset.hour * 3600 + gClock.sunset.minute * 60, p->window, 2);
  return 0;
#else
  INCFUNC("asm/func/ClockAlarm_Update.inc");
#endif
}

s32 ClockAlarm_Destroy(ClockAlarm* p) { return 0; }

// 現在時刻を取り込んで、スクリプトIDと一致幅を'.d','.p'から読む
s32 ClockAlarm_Init(ClockAlarm* p) {
  s32 i;

  p->hour = Time_GetHour();
  p->minute = Time_GetMinute();
  p->second = Time_GetSecond();
  p->secondOfDay = p->hour * 3600 + p->minute * 60 + p->second;
  p->window = VM_GetNamedArgValue('d', 60);
  p->scriptID = VM_GetNamedArgValue('p', 0);
  for (i = 0; i < 4; i++) {
    p->armed[i] = 1;
  }
  p->frameCounter = 0;
  return 0;
}

ClockAlarm* ClockAlarm_Create(void) {
  ClockAlarm* p = CreateEntity(ENTITY_UNK_8, sizeof(ClockAlarm));

  if (p != NULL) {
    SetEntityRoutine(p, ClockAlarm_Update, ClockAlarm_Destroy);
    if (ClockAlarm_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
