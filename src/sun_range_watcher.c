#include "entity.h"
#include "global.h"
#include "vm.h"

// 太陽ゲージが [sunMin, sunMax] に出入りするたびにスクリプトを実行する, 判定は '.f' フレームごと
// 太陽床(太陽ゲージが特定範囲に収まっている間、出現する床) で利用, それ以外の利用はまだ不明
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u16 enterScript;    // 0x18, '.p[0]', 太陽ゲージが [sunMin, sunMax] に入ったときに実行するスクリプト ID, 0 なら何もしない
  u16 leaveScript;    // 0x1A, '.p[1]', 範囲から出たときに実行するスクリプト ID, 0 なら何もしない
  u32 scriptArgs[2];  // 0x1C, '.A', スクリプトの argv[1..2] になる, argv[0] は太陽ゲージ
  u16 interval;       // 0x24, '.f', 0 なら毎フレーム, それ以外は timer がこの倍数のときだけ判定する
  u16 timer;          // 0x26, _Update が毎フレーム +1
  bool16 inRange;     // 0x28, 最後に実行したのが enterScript なら 1, leaveScript なら 0, 同じ側では再実行しない
  u8 sunMin;          // 0x2A, '.u[0]=1'
  u8 sunMax;          // 0x2B, '.u[1]=8', '.u' があって要素が無ければ 1
} SunRangeWatcher;
static_assert(sizeof(SunRangeWatcher) == 44);

// 太陽ゲージが範囲に入ったとき/出たときにそれぞれのスクリプトを1回ずつ実行する
void SunRangeWatcher_CheckSunGauge(SunRangeWatcher* p) {
  u32 argv[3];
  ScriptArgs args;
  s32 sun = gStat->sunGauge;
  bool32 inRange;

  if (p->sunMin <= sun && p->sunMax >= sun) {
    inRange = TRUE;
    if (p->inRange == 1) {
      return;
    }
  } else {
    inRange = FALSE;
    if (p->inRange == 0) {
      return;
    }
  }

  argv[0] = sun;
  argv[1] = p->scriptArgs[0];
  argv[2] = p->scriptArgs[1];
  args.argc = 3, args.argv = argv;
  if (inRange) {
    if (p->enterScript != 0) {
      VM_ExecByID(p->enterScript, &args);
      p->inRange = 1;
    }
  } else if (p->leaveScript != 0) {
    VM_ExecByID(p->leaveScript, &args);
    p->inRange = 0;
  }
}

s32 SunRangeWatcher_Update(SunRangeWatcher* p) {
  if (p->interval == 0) {
    SunRangeWatcher_CheckSunGauge(p);
  } else if (Mod(p->timer, p->interval) == 0) {
    SunRangeWatcher_CheckSunGauge(p);
  }

  p->timer++;
  return 0;
}

s32 SunRangeWatcher_Destroy(SunRangeWatcher* p) { return 0; }

s32 SunRangeWatcher_Init(SunRangeWatcher* p) {
  s32 i;

  if (VM_SeekToNamedArg('p')) {
    p->enterScript = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->leaveScript = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    p->enterScript = 0;
    p->leaveScript = 0;
  }

  if (VM_SeekToNamedArg('A')) {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = VM_GetPC() != NULL ? (u16)VM_GetValue() : 0;
    }
  } else {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = 0;
    }
  }

  if (VM_SeekToNamedArg('u')) {
    p->sunMin = VM_GetPC() != NULL ? VM_GetValue() : 1;
    p->sunMax = VM_GetPC() != NULL ? VM_GetValue() : 1;
  } else {
    p->sunMin = 1;
    p->sunMax = 8;
  }

  p->interval = VM_GetNamedArgValue('f', 0);
  p->timer = 0;
  p->inRange = 0;
  return 0;
}

// 0xAEB2
SunRangeWatcher* SunRangeWatcher_Create(void) {
  SunRangeWatcher* p = CreateEntity(ENTITY_UNK_8, sizeof(SunRangeWatcher));

  if (p != NULL) {
    SetEntityRoutine(p, SunRangeWatcher_Update, SunRangeWatcher_Destroy);
    if (SunRangeWatcher_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
