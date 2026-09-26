#include "entity.h"
#include "global.h"
#include "time.h"
#include "vm.h"

// 実時計を見張り、正午・夜明け・日没に差しかかった回に1度だけスクリプトを起動する
typedef struct {
  Entity e;          // 0x00, ENTITY_UNK_8
  s16 hour;          // 0x18, GetHour()
  s16 minute;        // 0x1A, GetMinute()
  s16 second;        // 0x1C, GetSecond()
  s16 frameCounter;  // 0x1E, 毎フレーム +1, 60 になったフレームだけ判定を飛ばして 0 に戻す
  s32 secondOfDay;   // 0x20, hour * 3600 + minute * 60 + second
  s32 window;        // 0x24, '.d=60', 夜明け・日没と一致とみなす秒数の幅
  s32 scriptID;      // 0x28, '.p=0', 0 以外なら Script_ExecById で実行する
  u8 armed[4];       // 0x2C, Init が4つとも 1, 0=正午 1=夜明け 2=日没, 窓に入った回に1度だけ発火して 0 になる, [3] は読み手なし
} ClockAlarm;
static_assert(sizeof(ClockAlarm) == 48);

// どの時刻に差しかかったか (0=正午 1=夜明け 2=日没) を引数にしてスクリプトを起動する
void ClockAlarm_Fire(ClockAlarm* p, u32 kind) {
  ScriptArgs args;
  args.argc = 1, args.argv = &kind;
  if (p->scriptID != 0) {
    Script_ExecById(p->scriptID, &args);
  }
}

// 真夜中をまたいだぶんを畳んだ秒差, 符号はどちら向きに離れているかを表す
static inline s32 ClockAlarm_Diff(s32 t, s32 target) {
  s32 d = t - target;

  if (t < target) {
    d = target - t;
  }
  if (d > 43199) {
    d -= 86400;
  }
  return d;
}

// 正午・夜明け・日没に差しかかったら、それぞれ1度だけスクリプトを起動する
NON_MATCH s32 ClockAlarm_Update(ClockAlarm* p) {
#ifdef NONMATCHING_C
  s32 target;
  s32 window;
  s32 d;

  p->frameCounter++;
  if (p->frameCounter > 59) {
    p->frameCounter = 0;
    return 0;
  }
  p->hour = GetHour();
  p->minute = GetMinute();
  p->second = GetSecond();
  p->secondOfDay = p->hour * 3600 + p->minute * 60 + p->second;

  d = ClockAlarm_Diff(p->secondOfDay, 43230);
  if (d < 0) {
    d = -d;
  }
  if (d <= 30) {
    if (p->armed[0] != 0) {
      p->armed[0] = 0;
      ClockAlarm_Fire(p, 0);
    }
  } else {
    p->armed[0] = 1;
  }

  target = gClock.morning.hour * 3600 + gClock.morning.minute * 60;
  window = p->window;
  d = ClockAlarm_Diff(p->secondOfDay, target);
  if (d < 0) {
    d = -d;
  }
  if (d <= window) {
    if (p->armed[1] != 0) {
      p->armed[1] = 0;
      ClockAlarm_Fire(p, 1);
    }
  } else {
    p->armed[1] = 1;
  }

  target = gClock.sunset.hour * 3600 + gClock.sunset.minute * 60;
  window = p->window;
  d = ClockAlarm_Diff(p->secondOfDay, target);
  if (d < 0) {
    d = -d;
  }
  if (d <= window) {
    if (p->armed[2] != 0) {
      p->armed[2] = 0;
      ClockAlarm_Fire(p, 2);
    }
  } else {
    p->armed[2] = 1;
  }

  return 0;
#else
  INCFUNC("asm/func/ClockAlarm_Update.inc");
#endif
}

s32 ClockAlarm_Destroy(ClockAlarm* p) { return 0; }

// 現在時刻を取り込んで、スクリプトIDと一致幅をキーワードから読む
s32 ClockAlarm_Init(ClockAlarm* p) {
  s32 i;

  p->hour = GetHour();
  p->minute = GetMinute();
  p->second = GetSecond();
  p->secondOfDay = p->hour * 3600 + p->minute * 60 + p->second;
  p->window = VM_GetKeywordValue('d', 60);
  p->scriptID = VM_GetKeywordValue('p', 0);
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
