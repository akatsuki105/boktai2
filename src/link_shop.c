#include "link_shop.h"

#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "link.h"
#include "save.h"
#include "solar.h"
#include "sound.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

typedef u32 LinkShopFlags;
#define LSFLAG_SENDING (1 << 0)            // 0x1, msg を送信待ちまたは送信中
#define LSFLAG_RECEIVED (1 << 1)           // 0x2, msg に相手からのメッセージが入っている
#define LSFLAG_PARENT (1 << 5)             // 0x20, 自分が親
#define LSFLAG_CHILD (1 << 6)              // 0x40, 自分が子
#define LSFLAG_REQ_NAME (1 << 7)           // 0x80, 名前を要求された (msg.kind 6 を受けた)
#define LSFLAG_REQ_SOLARBANK (1 << 8)      // 0x100, 太陽バンクの残高を要求された (msg.kind 7 を受けた)
#define LSFLAG_REQ_WEAPONCOUNT (1 << 9)    // 0x200, 交換に出せる武器の本数を要求された (msg.kind 8 を受けた)
#define LSFLAG_UNK_10 (1 << 10)            // 0x400, 落とす側しかおらず立てる側が未発見
#define LSFLAG_READY (1 << 11)             // 0x800, パケット層まで用意できた
#define LSFLAG_FINISHED (1 << 12)          // 0x1000, 終了処理に入った
#define LSFLAG_ID_FIXED (1 << 13)          // 0x2000, multiId を記録した
#define LSFLAG_NO_LINK_WATCH (1 << 14)     // 0x4000, リンクの生存確認をやめる
#define LSFLAG_ALLOW_SOFT_RESET (1 << 15)  // 0x8000, 立つまで gSoftResetInhibit を立て続ける

struct LinkShopManager;

typedef void (*LinkShopStateFn)(struct LinkShopManager* p);
typedef void (*LinkShopDoneFn)(void* owner);
typedef void (*LinkShopRecvFn)(void* owner, LinkShopMsg* msg);

// _Create が EntityA0A6_Create と Entity92ED_Create の 2種類ある (_Update, _Destroy は共通で _Init は別)
// "通信販売"(というアイテム交換機能) の 文字列を使っていたので、 LinkShopManager という名前にしたが、 "通信販売" のロジックではなく、"通信販売"のセッション管理だけかもしれない (もしそうなら、適切な名前に変える)
typedef struct LinkShopManager {
  Entity e;                   // 0x00, ENTITY_UNK_2
  u8 unk_18[0x3C - 0x18];     // 0x18, 読み手も書き手も未発見
  LinkShopMsg msg;            // 0x3C, 送信にも受信にも同じ領域を使う
  LinkShopStateFn stateFn;    // 0x4C
  s32 sendPacketId;           // 0x50, Sio_SendPacket が払い出した id, -1 なら送信していない
  u8* script;                 // 0x54, MessageWindow_Start に渡す文字列
  TilemapFile* tilemap;       // 0x58, MP_SYSTEM
  u8 unk_5c[0x60 - 0x5C];     // 0x5C, 読み手も書き手も未発見
  u8 unk_60;                  // 0x60, 外から書いて読むだけの1バイト
  u8 unk_61;                  // 0x61, 0xFF が入るだけで読み手は未発見
  u16 stateTimer;             // 0x62, 状態に入ってからのフレーム数
  LinkShopFlags flags;        // 0x64
  u8 resultLine;              // 0x68, MessageWindow_ShowLine に渡す行番号, 2 = エラー, 3 = キャンセル, 4 = 正常終了
  bool8 stateEnter;           // 0x69, 状態に入った最初のフレームだけ 1
  u8 state;                   // 0x6A, 0 = 受信待ち, 1 = 送信待ち, 4 = メッセージ処理, 5 = エラー, 6 = 終了, 7 = 接続待ち
  u8 idleFrames;              // 0x6B, 割り込み回数が進まないフレーム数, 11 で切断とみなす
  u8 noDataFrames;            // 0x6C, 相手のデータが来ないフレーム数, 11 で切断とみなす
  s8 multiId;                 // 0x6D, 記録した Sio_GetMultiId(), 初期値 -1
  u16 scriptID;               // 0x6E, '.e', 終了時に VM_ExecByID する
  s32 intrCount;              // 0x70, 前フレームの割り込み回数, idleFrames と組で生存確認に使う
  void* owner;                // 0x74, onSendDone と onRecv の第1引数
  LinkShopDoneFn onSendDone;  // 0x78
  LinkShopRecvFn onRecv;      // 0x7C
  LinkShopStateFn onFinish;   // 0x80, KillEntity の直前に呼ぶ
} LinkShopManager;
static_assert(sizeof(LinkShopManager) == 132);

COMMON_DATA LinkShopManager* gLinkShopManager = NULL;  // 0x03002C6C
COMMON_DATA u8 u8_03002c70[16] = {};                   // unused?

void sound_082402f8(SoundID32 id);
void* LinkConnect_Create(s32 timeout, s32 cancelable);
void LinkConnect_SetCallbacks(void* owner, void* onSuccess, void* onFailure);
void* Sio_CreatePacketCtx(void);
void Sio_UpdatePackets(void);
s32 CountSellableWeapons(void);
s32 CountSellableOrEmptySlots(void);
extern bool32 gRtcReadInhibit;
void LinkShopManager_StateIdle(LinkShopManager* p);
void LinkShopManager_StateError(LinkShopManager* p);
void LinkShopManager_StateHandleMsg(LinkShopManager* p);
void LinkShopManager_StateSendWait(LinkShopManager* p);

static inline bool8 TestLinkShopFlag(LinkShopFlags flag) {
  if (TEST_FLAGS(gLinkShopManager->flags, flag)) return TRUE;
  return FALSE;
}

static inline bool8 LinkShopManager_TestFlag(LinkShopManager* p, LinkShopFlags flag) {
  if (TEST_FLAGS(p->flags, flag)) return TRUE;
  return FALSE;
}

// flags のビットを落とす
static inline void LinkShopManager_ClearFlag(LinkShopManager* p, LinkShopFlags flag) { p->flags &= ~flag; }

// 次の状態に切り替える, 終了済みの判定は結果を使わない (中身が消えたデバッグ出力の跡か)
static inline void LinkShopManager_SetState(LinkShopManager* p, LinkShopStateFn fn, s32 state) {
  if (LinkShopManager_TestFlag(p, LSFLAG_FINISHED)) {
  }
  p->stateFn = fn;
  p->stateEnter = TRUE;
  p->state = state;
}

// msg を埋めたあと送信待ちの状態へ移す
static inline void LinkShopManager_StartSend(LinkShopManager* p) {
  LinkShopManager_SetState(p, LinkShopManager_StateSendWait, 1);
  SET_FLAGS(p->flags, LSFLAG_SENDING);
}

void nop_081e19e0(void) {}

// 呼び出し元がない, 親かどうかを調べるだけで結果を使わない (LinkShopManager_SetState と同じく中身が消えた if の跡か)
void FUN_081e19e4(LinkShopManager* p) {
  if (LinkShopManager_TestFlag(p, LSFLAG_PARENT)) {
  }
}

void nop_081e19f0(void) {}

void nop_081e19f4(void) {}

void nop_081e19f8(void) {}

void LinkShopManager_OpenTextBox(LinkShopManager* p) {
  MessageWindow_Start(p->script);
  MessageWindow_SetRect(1, 7, 28, 6);
  MessageWindow_ShowLine(0);
  MessageWindow_SetBgPltt(BGP_LINK);
  MessageWindow_SetInstant(1);
  p->unk_61 = 0xFF;
  CLEAR_FLAGS(p->flags, LSFLAG_UNK_10);
}

void LinkShopManager_SetupBG(LinkShopManager* p) {
  s32 layer;

  p->tilemap = GetFile(DIR_TILE_MAP, MP_SYSTEM);
  layer = 3;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &layer);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

// 接続できたら通信を始めて受信待ちへ, 親なら timer 割り込み, 子なら serial 割り込みの回数を生存確認の起点にする, 始められなければエラーへ
void LinkShopManager_OnConnected(LinkShopManager* p, s32 handle, s32 canceled) {
  s32 role;

  MessageWindow_Close();
  ClearBGTilemapBuffer(0);
  Sio_Reset();
  role = Sio_Start();
  LinkShopManager_SetState(p, LinkShopManager_StateIdle, 0);
  if (role < 0) {
    p->resultLine = 2;
    LinkShopManager_SetState(p, LinkShopManager_StateError, 5);
    SET_FLAGS(p->flags, LSFLAG_FINISHED);
    return;
  }

  if (role == 0) {
    SET_FLAGS(p->flags, LSFLAG_PARENT);
    p->intrCount = Sio_GetTimerIntrCount();
  } else {
    SET_FLAGS(p->flags, LSFLAG_CHILD);
    p->intrCount = Sio_GetSerialIntrCount();
  }
  Sio_CreatePacketCtx();
  SET_FLAGS(p->flags, LSFLAG_READY);
  p->multiId = -1;
  p->noDataFrames = 0;
  p->idleFrames = 0;
}

void LinkShopManager_StateClose(LinkShopManager* p);

// 接続に失敗したときの後始末, canceled ならキャンセル扱いの行を出す
void LinkShopManager_OnConnectFailed(LinkShopManager* p, s32 handle, s32 canceled) {
  if (canceled != 0) {
    p->resultLine = 3;
    PlaySound_082406e0(SE_CANCEL);
  } else {
    p->resultLine = 4;
  }

  LinkShopManager_SetState(p, LinkShopManager_StateClose, 6);
  SET_FLAGS(p->flags, LSFLAG_FINISHED);
}

// 割り込み回数が 10 フレームを超えて進まないか相手のデータが 10 フレームを超えて来ないか, Sio のエラーかマルチ ID が途中で変わったら切断とみなして TRUE
bool8 LinkShopManager_CheckLinkLost(LinkShopManager* p) {
  bool8 noWatch = LinkShopManager_TestFlag(p, LSFLAG_NO_LINK_WATCH);

  if (!noWatch) {
    bool32 hasData = FALSE;

    switch (Sio_GetMultiId()) {
      case 0: {
        hasData = Sio_HasChildData();
        if (p->intrCount == Sio_GetTimerIntrCount()) {
          p->idleFrames++;
        } else {
          p->idleFrames = 0;
          p->intrCount = Sio_GetTimerIntrCount();
        }
        break;
      }
      case 1: {
        hasData = Sio_HasParentData();
        if (p->intrCount == Sio_GetSerialIntrCount()) {
          p->idleFrames++;
        } else {
          p->idleFrames = 0;
          p->intrCount = Sio_GetSerialIntrCount();
        }
        break;
      }
    }

    if (p->idleFrames > 10) {
      return TRUE;
    }
    if (hasData) {
      p->noDataFrames = 0;
    } else if (++p->noDataFrames > 10) {
      return TRUE;
    }
    if (Sio_GetError() < 0) {
      return TRUE;
    }
    if (Sio_GetMultiId() >= 0 && Sio_GetMultiId() != p->multiId) {
      if (LinkShopManager_TestFlag(p, LSFLAG_ID_FIXED)) {
        return TRUE;
      }
      p->multiId = Sio_GetMultiId();
      SET_FLAGS(p->flags, LSFLAG_ID_FIXED);
    }
  }
  return FALSE;
}

// 1 = 受け取った, 0 = 届いていない, -1 = 送受信中で受け取れない
s32 LinkShopMsg_TryRecv(LinkShopMsg* msg, LinkShopFlags flags) {
  s32 n;

  if ((flags & (LSFLAG_SENDING | LSFLAG_RECEIVED)) != 0) {
    return -1;
  }
  n = Sio_RecvPacket((u8*)msg);
  if (n > 0) {
    return 1;
  }
  if (n < 0) {
    return -1;
  }
  return 0;
}

// 1 = 相手に届いた, 2 = 送信中, 0 = 空きがなくて送れなかった
s32 LinkShopMsg_TrySend(LinkShopMsg* msg, s32* packetId) {
  if (*packetId >= 0) {
    if (Sio_GetPacketStatus(*packetId) == 0) {
      return 1;
    }
    return 2;
  }
  *packetId = Sio_SendPacket((u8*)msg, 16);
  if (*packetId < 0) {
    return 0;
  }
  return 2;
}

s32 LinkShopManager_PollRecv(LinkShopManager* p);

// 相手からのメッセージを待つ状態
void LinkShopManager_StateIdle(LinkShopManager* p) {
  if (p->stateEnter) {
    p->stateEnter = FALSE;
  }
  LinkShopManager_PollRecv(p);
}

// msg の送信を待つ状態, 相手に届いたら onSendDone を呼んで msg を空け受信待ちへ戻る
void LinkShopManager_StateSendWait(LinkShopManager* p) {
  if (p->stateEnter) {
    p->stateEnter = FALSE;
  }

  if (LinkShopManager_TestFlag(p, LSFLAG_SENDING) && LinkShopMsg_TrySend(&p->msg, &p->sendPacketId) == 1) {
    if (p->onSendDone != NULL) {
      p->onSendDone(p->owner);
    }
    p->msg.kind = 0;
    LinkShopManager_ClearFlag(p, LSFLAG_SENDING);
    p->sendPacketId = -1;
    LinkShopManager_SetState(p, LinkShopManager_StateIdle, 0);
  }
}

// 相手からのメッセージを1通受け取ったら種類に応じた要求フラグを立ててメッセージ処理の状態へ移る, 届いていなければ送信 id を空ける
// 残差: 原典は kind の比較が bool8 inline の 0/1 作り置きで, 2 回目以降の比較で kind を lsls/lsrs し直し, kind 10 の判定も結果を捨てて残る
// Tier A-C は試済 (u16 引数の IsKind inline に s32 / u32 / u16 の kind を渡す, 空の if, switch に case -1 で枝の形は一致), 未: inline の引数型の組み合わせ
NON_MATCH s32 LinkShopManager_PollRecv(LinkShopManager* p) {
#ifdef NONMATCHING_C
  switch (LinkShopMsg_TryRecv(&p->msg, p->flags)) {
    case -1: {
      break;
    }
    case 0: {
      p->sendPacketId = -1;
      break;
    }
    case 1: {
      u32 flag;

      if (p->msg.kind == 6) {
        flag = LSFLAG_REQ_NAME | LSFLAG_RECEIVED;
      } else if (p->msg.kind == 7) {
        flag = LSFLAG_REQ_SOLARBANK | LSFLAG_RECEIVED;
      } else if (p->msg.kind == 8) {
        flag = LSFLAG_REQ_WEAPONCOUNT | LSFLAG_RECEIVED;
      } else if (p->msg.kind == 10) {
        flag = LSFLAG_RECEIVED;
      } else {
        flag = LSFLAG_RECEIVED;
      }
      SET_FLAGS(p->flags, flag);
      LinkShopManager_SetState(p, LinkShopManager_StateHandleMsg, 4);
      p->sendPacketId = -1;
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/LinkShopManager_PollRecv.inc");
#endif
}

// 受け取ったメッセージを処理する状態, 名前・太陽バンクの残高・売れる武器の本数の要求ならその場で返事を送り, それ以外は onRecv に渡して受信待ちへ戻る
void LinkShopManager_StateHandleMsg(LinkShopManager* p) {
  if (p->stateEnter) {
    p->stateEnter = FALSE;
  }

  if (LinkShopManager_TestFlag(p, LSFLAG_RECEIVED)) {
  }
  LinkShopManager_ClearFlag(p, LSFLAG_RECEIVED);

  if (LinkShopManager_TestFlag(p, LSFLAG_REQ_NAME)) {
    LinkShopManager_ClearFlag(p, LSFLAG_REQ_NAME);
    p->msg.kind = 1;
    p->msg.data[0] = ((s32*)gStat->name)[0];
    p->msg.data[1] = ((s32*)gStat->name)[1];
    p->msg.data[2] = ((s32*)gStat->name)[2];
    LinkShopManager_StartSend(p);
  } else if (LinkShopManager_TestFlag(p, LSFLAG_REQ_SOLARBANK)) {
    LinkShopManager_ClearFlag(p, LSFLAG_REQ_SOLARBANK);
    p->msg.kind = 0;
    p->msg.data[0] = gStat->solarBank;
    LinkShopManager_StartSend(p);
  } else if (LinkShopManager_TestFlag(p, LSFLAG_REQ_WEAPONCOUNT)) {
    LinkShopManager_ClearFlag(p, LSFLAG_REQ_WEAPONCOUNT);
    p->msg.kind = 2;
    p->msg.data[0] = CountSellableWeapons();
    p->msg.data[1] = CountSellableOrEmptySlots();
    LinkShopManager_StartSend(p);
  } else {
    if (p->onRecv != NULL) {
      p->onRecv(p->owner, &p->msg);
    }
    if (!LinkShopManager_TestFlag(p, LSFLAG_FINISHED)) {
      LinkShopManager_SetState(p, LinkShopManager_StateIdle, 0);
    }
  }
}

// 通信エラーの状態, 背景を消して resultLine の行を出し BGM をフェードアウトし, 1 秒後にソフトリセットを許す
void LinkShopManager_StateError(LinkShopManager* p) {
  if (p->stateEnter) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap, 3);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MessageWindow_ShowLine(p->resultLine);
    MessageWindow_SetInstant(1);
    Sound_FadeOutBGM(1);
    p->stateTimer = 0;
    p->stateEnter = FALSE;
  }

  if (p->stateTimer < 60) {
    p->stateTimer++;
  } else {
    SET_FLAGS(p->flags, LSFLAG_ALLOW_SOFT_RESET);
  }
}

// 終了の状態, resultLine の行を出してフェードアウトし, 3 秒で onFinish と '.e' のスクリプトを呼んで自分を消す
void LinkShopManager_StateClose(LinkShopManager* p) {
  if (p->stateEnter) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap, 3);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MessageWindow_ShowLine(p->resultLine);
    MessageWindow_SetInstant(1);
    Sound_FadeOutBGM(1);
    p->stateTimer = 0;
    p->stateEnter = FALSE;
  }

  if (p->stateTimer == 156) {
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
  }
  if (p->stateTimer > 180) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(1);
    ClearBGTilemapBuffer(2);
    ClearBGTilemapBuffer(3);
    if (p->onFinish != NULL) {
      p->onFinish(p);
    }
    Taiyo_Enable();
    gRtcReadInhibit = FALSE;
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
    }
    KillEntity((Entity*)p);
  }
  p->stateTimer++;
}

// LinkConnect が握手している間の状態, 何もしない
void LinkShopManager_StateConnecting(LinkShopManager* p) {
  if (p->stateEnter) {
    p->stateEnter = FALSE;
  }
}

// 通信中は太陽センサーと RTC を止め, 繋がっていればパケットを回して切断を見張り, 切れたらエラーの状態へ移る
s32 LinkShopManager_Update(LinkShopManager* p) {
  Taiyo_Disable();
  gRtcReadInhibit = TRUE;
  if (!LinkShopManager_TestFlag(p, LSFLAG_ALLOW_SOFT_RESET)) {
    gSoftResetInhibit = TRUE;
  }

  if (LinkShopManager_TestFlag(p, LSFLAG_FINISHED)) {
    if (p->stateFn != NULL) {
      p->stateFn(p);
    }
    return -1;
  }

  gSoftResetInhibit = TRUE;
  if (LinkShopManager_TestFlag(p, LSFLAG_READY)) {
    Sio_UpdatePackets();
    if (LinkShopManager_CheckLinkLost(p)) {
      p->resultLine = 2;
      LinkShopManager_SetState(p, LinkShopManager_StateError, 5);
      SET_FLAGS(p->flags, LSFLAG_FINISHED);
      Sio_Stop();
      return -1;
    }
  }

  if (p->stateFn != NULL) {
    p->stateFn(p);
  }
  return 1;
}

s32 LinkShopManager_Destroy(LinkShopManager* p) {
  Sio_Stop();
  gLinkShopManager = NULL;
  return 1;
}

// 自分で LinkConnect を作って相手を待つ版, 100 秒で打ち切り, キャンセル可
s32 EntityA0A6_Init(LinkShopManager* p) {
  sound_082402f8(0);
  p->sendPacketId = -1;
  if (VM_SeekToNamedArg('s')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return -1;
    }
  }
  p->scriptID = VM_GetNamedArgValue('e', 0);
  if (LinkConnect_Create(6000, TRUE) == NULL) {
    return -1;
  }
  LinkConnect_SetCallbacks(p, LinkShopManager_OnConnected, LinkShopManager_OnConnectFailed);
  LinkShopManager_SetupBG(p);
  LinkShopManager_OpenTextBox(p);
  gLinkShopManager = p;
  p->onRecv = NULL;
  p->onFinish = NULL;
  p->onSendDone = NULL;
  p->owner = NULL;
  LinkShopManager_SetState(p, LinkShopManager_StateConnecting, 7);
  return 1;
}

LinkShopManager* EntityA0A6_Create(void) {
  LinkShopManager* p;

  if (gLinkShopManager != NULL) {
    return gLinkShopManager;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(LinkShopManager));
  if (p != NULL) {
    SetEntityRoutine(p, LinkShopManager_Update, LinkShopManager_Destroy);
    if (EntityA0A6_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 繋がった後で作る版, 接続待ちを飛ばしてすぐ LinkShopManager_OnConnected を呼ぶ
s32 Entity92ED_Init(LinkShopManager* p) {
  p->sendPacketId = -1;
  if (VM_SeekToNamedArg('s')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return -1;
    }
  }
  p->scriptID = VM_GetNamedArgValue('e', 0);
  LinkShopManager_SetupBG(p);
  LinkShopManager_OpenTextBox(p);
  gLinkShopManager = p;
  p->onRecv = NULL;
  p->onFinish = NULL;
  p->onSendDone = NULL;
  p->owner = NULL;
  LinkShopManager_OnConnected(p, 0, 0);
  return 1;
}

LinkShopManager* Entity92ED_Create(void) {
  LinkShopManager* p;

  if (gLinkShopManager != NULL) {
    return gLinkShopManager;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(LinkShopManager));
  if (p != NULL) {
    SetEntityRoutine(p, LinkShopManager_Update, LinkShopManager_Destroy);
    if (Entity92ED_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void LinkShopManager_ClearGlobal(void) { gLinkShopManager = NULL; }

// msg が送信待ちか受信済みのどちらかで埋まっているか
bool32 LinkShopManager_IsBusy(void) {
  if (gLinkShopManager == NULL) {
    return FALSE;
  }
  if (TestLinkShopFlag(LSFLAG_SENDING | LSFLAG_RECEIVED)) {
    return TRUE;
  }
  return FALSE;
}

// onRecv にも同じ値が入るが, 呼び出し元は直後に LinkShopManager_SetCallbacks で上書きする
void LinkShopManager_SetOwner(void* owner) {
  if (gLinkShopManager != NULL) {
    gLinkShopManager->owner = owner;
    gLinkShopManager->onRecv = (LinkShopRecvFn)owner;
  }
}

void LinkShopManager_SetCallbacks(LinkShopRecvFn onRecv, LinkShopStateFn onFinish, LinkShopDoneFn onSendDone) {
  if (gLinkShopManager != NULL) {
    gLinkShopManager->onRecv = onRecv;
    gLinkShopManager->onFinish = onFinish;
    gLinkShopManager->onSendDone = onSendDone;
  }
}

// 1 = 親, 0 = 子, -1 = まだ繋がっていない
s32 LinkShopManager_IsParent(void) {
  if (gLinkShopManager == NULL) {
    return -1;
  }
  if (TestLinkShopFlag(LSFLAG_PARENT)) {
    return TRUE;
  }
  return FALSE;
}

s32 FUN_081e2418(u32 v) {
  if (gLinkShopManager == NULL) {
    return -1;
  }
  gLinkShopManager->unk_60 = v;
  return 0;
}

u32 FUN_081e2438(void) {
  if (gLinkShopManager == NULL) {
    return 0;
  }
  return gLinkShopManager->unk_60;
}

bool32 LinkShopManager_IsReady(void) {
  if (gLinkShopManager == NULL) {
    return FALSE;
  }
  if (TestLinkShopFlag(LSFLAG_READY)) {
    return TRUE;
  }
  return FALSE;
}

bool8 LinkShopManager_IsFinished(void) {
  if (gLinkShopManager == NULL) {
    return TRUE;
  }
  if (TestLinkShopFlag(LSFLAG_FINISHED)) {
    return TRUE;
  }
  return FALSE;
}

// まだ終わっていなければエラーの行 (2) を出す状態へ移して終了扱いにする
void LinkShopManager_Abort(void) {
  if (gLinkShopManager != NULL) {
    LinkShopManager* p = gLinkShopManager;

    if (!LinkShopManager_TestFlag(p, LSFLAG_FINISHED)) {
      p->resultLine = 2;
      LinkShopManager_SetState(p, LinkShopManager_StateError, 5);
      SET_FLAGS(p->flags, LSFLAG_FINISHED);
    }
  }
}

// kind に応じて args と tag を msg に詰めて送信待ちにする, 送受信中か終了済みなら FALSE, 知らない kind は何もせず TRUE
bool8 LinkShopManager_Send(s32* args, s32 kind, u32 tag) {
  LinkShopManager* p;

  if (gLinkShopManager == NULL) {
    return FALSE;
  }
  p = gLinkShopManager;
  if (LinkShopManager_TestFlag(p, LSFLAG_SENDING | LSFLAG_RECEIVED | LSFLAG_FINISHED)) {
    return FALSE;
  }

  if (kind == 3) {
    p->msg.kind = kind;
    p->msg.data[0] = args[0];
    p->msg.data[1] = args[1];
    p->msg.data[2] = args[2];
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 4) {
    p->msg.kind = kind;
    p->msg.data[0] = args[3];
    p->msg.data[1] = args[4];
    p->msg.data[2] = args[5];
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 5) {
    p->msg.kind = kind;
    p->msg.data[0] = args[6];
    p->msg.data[1] = args[7];
    p->msg.data[2] = args[8];
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 10) {
    p->msg.kind = kind;
    p->msg.data[0] = args[0];
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 11) {
    p->msg.kind = kind;
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 12) {
    p->msg.kind = kind;
    p->msg.data[0] = args[0];
    p->msg.unk_02 = tag;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 6) {
    p->msg.kind = kind;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 7) {
    p->msg.kind = kind;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  if (kind == 8) {
    p->msg.kind = kind;
    LinkShopManager_StartSend(p);
    return TRUE;
  }
  return TRUE;
}

void LinkShopManager_Kill(void) {
  if (gLinkShopManager != NULL) {
    KillEntity((Entity*)gLinkShopManager);
  }
}

void LinkShopManager_StopLinkWatch(void) {
  if (gLinkShopManager != NULL) {
    SET_FLAGS(gLinkShopManager->flags, LSFLAG_NO_LINK_WATCH);
  }
}

void LinkShopManager_AllowSoftReset(void) {
  if (gLinkShopManager != NULL) {
    SET_FLAGS(gLinkShopManager->flags, LSFLAG_ALLOW_SOFT_RESET);
  }
}
