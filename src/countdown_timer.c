#include "entity.h"
#include "global.h"
#include "menu.h"
#include "vm.h"

// 画面にカウントダウンを出し、0 になったらスクリプトを実行して消えるタイマー
// 森の3分の時間制限 (部屋をまたいで W_COUNTDOWN_REMAINING で引き継ぐ), 変異域で敵に見つかったときの10秒, 地下墓地の閉じ込め戦闘の30秒, 夢幻街の警報の20秒, 依頼の制限時間などで使う
// スクリプトが渡すインスタンスIDはどこでも 0xB669
typedef struct {
  Entity e;          // 0x00, ENTITY_UNK_8
  u16 timer;         // 0x18, 残りフレーム数, _Init が '.t=1800' を入れ、_Update が毎フレーム -1. アドレスを HUD_StartCountdown に渡して画面に出す
  bool16 cancelled;  // 0x1A, Cmd_EndCountdownTimer が立てる, _Update はこれを見るとスクリプトを実行せずに KillEntity する
  u32 scriptID;      // 0x1C, timer が 0 になったとき VM_ExecByID に渡す, _Init が '.p' から取る, 0 なら何も実行しない
} CountdownTimer;
static_assert(sizeof(CountdownTimer) == 32);

COMMON_DATA CountdownTimer* gCountdownTimer = NULL;  // 0x03002C50

// 0x075C, 残りフレーム数を返す, Entity がいなければ 0
s32 Cmd_GetCountdownTimerRemaining(void) {
  if (gCountdownTimer == NULL) {
    return 0;
  }
  return gCountdownTimer->timer;
}

// 0xAF8E, HashName("タイマー終了"), 次の更新でスクリプトを実行せずに消えるようにする
void Cmd_EndCountdownTimer(void) {
  if (gCountdownTimer != NULL) {
    gCountdownTimer->cancelled = TRUE;
  }
}

// 残り時間を1フレーム減らし、0 になったらスクリプトを実行して消える
s32 CountdownTimer_Update(CountdownTimer* p) {
  if (p->cancelled) {
    HUD_RemoveCountdown();
    KillEntity((Entity*)p);
  } else {
    p->timer--;
    if (p->timer == 0) {
      HUD_RemoveCountdown();
      if (p->scriptID != 0) {
        VM_ExecByID(p->scriptID, NULL);
      }
      KillEntity((Entity*)p);
    }
  }
  return 0;
}

s32 CountdownTimer_Destroy(CountdownTimer* p) {
  gCountdownTimer = NULL;
  return 0;
}

s32 CountdownTimer_Init(CountdownTimer* p, u32 id, u32 _) {
  if (VM_SeekToNamedArg('t')) {
    p->timer = VM_GetValue();
  } else {
    p->timer = SECOND(30);
  }

  if (VM_SeekToNamedArg('p')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }

  HUD_StartCountdown(&p->timer);
  gCountdownTimer = p;
  return 0;
}

// 0x4063
CountdownTimer* CountdownTimer_Create(u32 id, u32 _) {
  if (gCountdownTimer == NULL) {
    CountdownTimer* p = CreateEntity(ENTITY_UNK_8, sizeof(CountdownTimer));
    if (p != NULL) {
      SetEntityRoutine(p, CountdownTimer_Update, CountdownTimer_Destroy);
      if (CountdownTimer_Init(p, id, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gCountdownTimer;
}
