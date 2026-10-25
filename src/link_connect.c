#include "entity.h"
#include "global.h"
#include "input.h"
#include "link.h"
#include "solar.h"

typedef void (*LinkConnectFunc)(void* owner, s32 handle, s32 canceled);

// 2人用リンクの接続待ち, 0x192 を送り合い、両方が 0xE2 になったら成功として onSuccess を呼ぶ
typedef struct LinkConnect {
  Entity e;                   // 0x00, ENTITY_UNK_2
  s32 timeout;                // 0x18, Create の第1引数, 0 なら 300, LinkConnect_TickTimeout が timer と比べる
  s32 cancelable;             // 0x1C, Create の第2引数, 0 でない間だけ B ボタンでキャンセルできる
  s32 canceled;               // 0x20, B ボタンで打ち切ったとき 1, コールバックの第3引数になる
  s32 handle;                 // 0x24, Sio_Connect() の戻り値, 負の間は張り直す, コールバックの第2引数になる
  s32 succeeded;              // 0x28, 両者が 0xE2 を返したら 1, onSuccess と onFailure の選択に使う
  s32 finished;               // 0x2C, 立つと次のフレームでコールバックを呼んで KillEntity する
  s32 linkStopped;            // 0x30, Sio_Disconnect を呼んだら 1, _Destroy はこれが立っていれば呼ばない
  s32 timer;                  // 0x34, LinkConnect_TickTimeout が +1 し、timeout 以上になったら真を返す
  s32 agreeFrames;            // 0x38, 両者が 0x192 を返し続けたフレーム数, 0x77 を超えると sendVal が 0xE2 になる
  s32 noDataRetry;            // 0x3C, 受信データが来ないまま経過したフレーム数, 30 でリンクを張り直して 0 に戻る
  s32 connectRetry;           // 0x40, Sio_Connect が失敗し続けたフレーム数, 30 でリンクを張り直して 0 に戻る
  s32 sendResult;             // 0x44, Sio_SetSendData(sendVal) の戻り値, _Init は -1
  s32 recvResult;             // 0x48, Sio_GetRecvData(recvBuf) の戻り値, -3 なら再試行, _Init は -1
  s32 noDataCount;            // 0x4C, recvResult が -3 になるたびに +1, 読み手はいない
  s32 recvErrorRetry;         // 0x50, recvResult が -3 以外のエラーだったフレーム数, 30 でリンクを張り直して 0 に戻る
  s32 connectCount;           // 0x54, Sio_Connect を呼ぶたびに +1, 読み手はいない
  s32 recvCount;              // 0x58, 受信に成功したフレームごとに +1, 読み手はいない
  u16 sendVal;                // 0x5C, Sio_SetSendData で送る値, 握手中は 0x192、agreeFrames が 0x77 を超えると 0xE2
  u16 recvBuf[4];             // 0x5E, Sio_GetRecvData が埋める, -1 でないスロットを数え、0x192 と 0xE2 を探す
  LinkConnectFunc onSuccess;  // 0x68, LinkConnect_SetCallbacks の第2引数
  LinkConnectFunc onFailure;  // 0x6C, 同第3引数, 成功しなかったときに呼ぶ
  void* owner;                // 0x70, 同第1引数, コールバックの第1引数になる
} LinkConnect;
static_assert(sizeof(LinkConnect) == 116);

COMMON_DATA LinkConnect* gLinkConnect = NULL;  // 0x03002C64

extern u32 u32_0300481c;  // src/time.c

s32 FUN_08238b04(void);   // src/link.c
void FUN_08238cd4(void);  // src/link.c

void LinkConnect_ClearGlobal(void) { gLinkConnect = NULL; }

// 待ち時間を1フレーム進め、timeout に達したかを返す
bool8 LinkConnect_TickTimeout(LinkConnect* p) {
  p->timer++;
  if (p->timer >= p->timeout) {
    return TRUE;
  }
  return FALSE;
}

// 残差は最終行のキャンセル判定で p->succeeded を読むレジスタが r0 (こちら) と r2 (元) で違う1命令のみ, 命令列は241対241で一致, Tier A-C 試済
NON_MATCH s32 LinkConnect_Update(LinkConnect* p) {
#ifdef NONMATCHING_C
  s32 connected;
  s32 agreed;
  s32 ready;
  bool32 scanning;
  s32 i;

  if (p->finished != 0) {
    Sio_Disconnect();
    p->linkStopped = 1;
    if (p->succeeded != 0) {
      if (p->onSuccess != NULL) {
        p->onSuccess(p->owner, p->handle, p->canceled);
      }
    } else {
      if (p->onFailure != NULL) {
        p->onFailure(p->owner, p->handle, p->canceled);
      }
    }
    KillEntity((Entity*)p);
    return 0;
  }

  connected = 0;
  agreed = 0;
  ready = 0;
  scanning = TRUE;

  if (p->handle < 0) {
    p->connectCount++;
    p->handle = Sio_Connect();
    if (p->handle < 0) {
      if (p->connectRetry > 29) {
        FUN_08238cd4();
        p->handle = Sio_Connect();
        p->connectRetry = 0;
      } else {
        p->connectRetry++;
      }
    }
    if (LinkConnect_TickTimeout(p)) {
      p->finished = 1;
    }
    p->noDataRetry = 0;
    p->agreeFrames = 0;
  } else {
    p->recvResult = Sio_GetRecvData(p->recvBuf);
    p->sendResult = Sio_SetSendData(p->sendVal);
    if (p->finished == 0 && p->handle == 0) {
      Sio_StartTransferIfIdle();
    }
    if (p->recvResult >= 0) {
      p->recvCount++;
      for (i = 0; i < 4; i++) {
        if (p->recvBuf[i] != 0xFFFF) {
          if (scanning) {
            if (p->recvBuf[i] == 0x192) {
              agreed++;
            } else if (p->recvBuf[i] == 0xE2) {
              agreed++;
              ready++;
            }
          }
          connected++;
        } else {
          scanning = FALSE;
        }
      }
      if (connected == 2 && agreed == 2) {
        p->agreeFrames++;
        if (p->agreeFrames > 119) {
          p->sendVal = 0xE2;
        }
        p->timer = 0;
      } else {
        if (LinkConnect_TickTimeout(p)) {
          p->finished = 1;
        }
        p->agreeFrames = 0;
      }
      if (ready == 2) {
        p->succeeded = 1;
        p->finished = 1;
      }
      p->noDataRetry = 0;
    } else {
      p->sendVal = 0x192;
      if (p->recvResult == -3) {
        p->noDataCount++;
        if (p->noDataRetry > 29) {
          Sio_Disconnect();
          FUN_08238cd4();
          p->handle = Sio_Connect();
          p->agreeFrames = 0;
          p->recvErrorRetry = 0;
          p->noDataRetry = 0;
          p->connectRetry = 0;
        } else {
          p->noDataRetry++;
        }
        if (LinkConnect_TickTimeout(p)) {
          p->finished = 1;
        }
      } else {
        p->agreeFrames = 0;
        if (p->recvErrorRetry > 29) {
          Sio_Disconnect();
          FUN_08238cd4();
          p->handle = Sio_Connect();
          p->agreeFrames = 0;
          p->recvErrorRetry = 0;
          p->noDataRetry = 0;
          p->connectRetry = 0;
        } else {
          p->recvErrorRetry++;
        }
        if (LinkConnect_TickTimeout(p)) {
          p->finished = 1;
        }
        p->noDataRetry = 0;
      }
    }
  }

  if (p->cancelable != 0 && p->finished == 0 && p->succeeded == 0 && (gInput[0].pressed & B_BUTTON)) {
    p->finished = 1;
    p->canceled = 1;
  }
  return 0;
#else
  INCFUNC("asm/func/LinkConnect_Update.inc");
#endif
}

s32 LinkConnect_Destroy(LinkConnect* p) {
  if (p->linkStopped == 0) {
    Sio_Disconnect();
  }
  gLinkConnect = NULL;
  return 0;
}

// 太陽センサーと時計の更新を止めてリンクを張り直し、握手の初期値を入れる
s32 LinkConnect_Init(LinkConnect* p, s32 timeout, s32 cancelable) {
  gLinkConnect = p;
  Taiyo_Disable();
  u32_0300481c = 1;
  Sio_Reset();
  FUN_08238b04();
  if (timeout == 0) {
    p->timeout = 300;
  } else {
    p->timeout = timeout;
  }
  p->cancelable = cancelable;
  p->canceled = 0;
  p->handle = -1;
  p->succeeded = 0;
  p->finished = 0;
  p->linkStopped = 0;
  p->timer = 0;
  p->agreeFrames = 0;
  p->sendResult = -1;
  p->recvResult = -1;
  p->sendVal = 0x192;
  p->recvBuf[0] = 0xFFFF;
  p->recvBuf[1] = -1;
  p->recvBuf[2] = -1;
  p->recvBuf[3] = -1;
  p->owner = NULL;
  p->onSuccess = NULL;
  p->onFailure = NULL;
  return 0;
}

LinkConnect* LinkConnect_Create(s32 timeout, s32 cancelable) {
  LinkConnect* p;

  if (gLinkConnect != NULL) {
    return gLinkConnect;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(LinkConnect));
  if (p != NULL) {
    SetEntityRoutine(p, LinkConnect_Update, LinkConnect_Destroy);
    if (LinkConnect_Init(p, timeout, cancelable) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 接続の成否を知らせるコールバックを登録する
void LinkConnect_SetCallbacks(void* owner, LinkConnectFunc onSuccess, LinkConnectFunc onFailure) {
  if (gLinkConnect != NULL) {
    gLinkConnect->owner = owner;
    gLinkConnect->onSuccess = onSuccess;
    gLinkConnect->onFailure = onFailure;
  }
}
