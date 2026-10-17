#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "link.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"

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

// 回線に流す1通分のメッセージ, .kind 以外の意味は kind ごとに変わる
typedef struct LinkShopMsg {
  u16 kind;     // 0x00, 0 = 太陽バンクの残高, 1 = 名前, 2 = 武器の本数, 3-5/6-8/10-12 は呼び出し側が決める
  u16 unk_02;   // 0x02, LinkShopManager_Send の第3引数をそのまま乗せる, 読むのは受け取った側の onRecv
  s32 data[3];  // 0x04, kind 1 では GameInfo.name の12バイト, kind 0 は残高, kind 2 は売れる武器の本数2種
} LinkShopMsg;
static_assert(sizeof(LinkShopMsg) == 16);

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
  TilemapFile* tilemap;       // 0x58, TILEMAP_A413
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

extern LinkShopManager* gLinkShopManager;  // 0x03002C6C, 0 以外なら SoftReset_0823a928 が Sio_Stop を呼ぶ

static inline void LinkShopManager_SetFlags(LinkShopManager* p, LinkShopFlags bits) { p->flags |= bits; }
static inline void LinkShopManager_MaskFlags(LinkShopManager* p, LinkShopFlags mask) { p->flags &= mask; }

void nop_081e19e0(void) {}

// 呼び出し元がなく, 戻り値を捨てるエピローグなのに p->flags & LSFLAG_PARENT を計算している
// 元は void 宣言のまま return していたとみられるが, このプロジェクトは警告をエラーにするので C では書けない
NAKED void FUN_081e19e4(LinkShopManager* p) { INCFUNC("asm/func/FUN_081e19e4.inc"); }

void nop_081e19f0(void) {}

void nop_081e19f4(void) {}

void nop_081e19f8(void) {}

void LinkShopManager_OpenTextBox(LinkShopManager* p) {
  MessageWindow_Start(p->script);
  MessageWindow_SetRect(1, 7, 28, 6);
  MessageWindow_ShowLine(0);
  MessageWindow_SetBgPltt(BOKHASH("bg_link_col_arr"));
  MessageWindow_SetInstant(1);
  p->unk_61 = 0xFF;
  LinkShopManager_MaskFlags(p, ~LSFLAG_UNK_10);
}

void LinkShopManager_SetupBG(LinkShopManager* p) {
  s32 layer;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  layer = 3;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &layer);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

NAKED void LinkShopManager_OnConnected(LinkShopManager* p, s32 handle, s32 canceled) { INCFUNC("asm/func/LinkShopManager_OnConnected.inc"); }

NAKED void LinkShopManager_OnConnectFailed(LinkShopManager* p, s32 handle, s32 canceled) { INCFUNC("asm/func/LinkShopManager_OnConnectFailed.inc"); }

NAKED bool32 LinkShopManager_CheckLinkLost(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_CheckLinkLost.inc"); }

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

NAKED void LinkShopManager_StateSendWait(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_StateSendWait.inc"); }

NAKED s32 LinkShopManager_PollRecv(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_PollRecv.inc"); }

NAKED void LinkShopManager_StateHandleMsg(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_StateHandleMsg.inc"); }

NAKED void LinkShopManager_StateError(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_StateError.inc"); }

NAKED void LinkShopManager_StateClose(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_StateClose.inc"); }

// LinkConnect が握手している間の状態, 何もしない
void LinkShopManager_StateConnecting(LinkShopManager* p) {
  if (p->stateEnter) {
    p->stateEnter = FALSE;
  }
}

NAKED s32 LinkShopManager_Update(LinkShopManager* p) { INCFUNC("asm/func/LinkShopManager_Update.inc"); }

s32 LinkShopManager_Destroy(LinkShopManager* p) {
  Sio_Stop();
  gLinkShopManager = NULL;
  return 1;
}

NAKED s32 EntityA0A6_Init(LinkShopManager* p) { INCFUNC("asm/func/EntityA0A6_Init.inc"); }

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

NAKED s32 Entity92ED_Init(LinkShopManager* p) { INCFUNC("asm/func/Entity92ED_Init.inc"); }

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
// 残差は 0/1 の実体化が元は2回あること (フラグ判定の結果を一度値にしてから再度 cmp する), マスクも ldr より先に置かれる
// static inline 経由・ローカル経由とも gcc が畳んでしまい再現できず, IsReady / IsFinished / IsParent も同じ形
NON_MATCH bool32 LinkShopManager_IsBusy(void) {
#ifdef NONMATCHING_C
  if (gLinkShopManager == NULL) {
    return FALSE;
  }
  if ((gLinkShopManager->flags & (LSFLAG_SENDING | LSFLAG_RECEIVED)) != 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/LinkShopManager_IsBusy.inc");
#endif
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
// 残差は LinkShopManager_IsBusy と同じ, フラグ判定の 0/1 実体化が元は2回ある
NON_MATCH s32 LinkShopManager_IsParent(void) {
#ifdef NONMATCHING_C
  if (gLinkShopManager == NULL) {
    return -1;
  }
  if ((gLinkShopManager->flags & LSFLAG_PARENT) != 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/LinkShopManager_IsParent.inc");
#endif
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

// 残差は LinkShopManager_IsBusy と同じ, フラグ判定の 0/1 実体化が元は2回ある
NON_MATCH bool32 LinkShopManager_IsReady(void) {
#ifdef NONMATCHING_C
  if (gLinkShopManager == NULL) {
    return FALSE;
  }
  if ((gLinkShopManager->flags & LSFLAG_READY) != 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/LinkShopManager_IsReady.inc");
#endif
}

// 残差は LinkShopManager_IsBusy と同じ, フラグ判定の 0/1 実体化が元は2回ある
NON_MATCH bool8 LinkShopManager_IsFinished(void) {
#ifdef NONMATCHING_C
  if (gLinkShopManager == NULL) {
    return TRUE;
  }
  if ((gLinkShopManager->flags & LSFLAG_FINISHED) != 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/LinkShopManager_IsFinished.inc");
#endif
}

NAKED void LinkShopManager_Abort(void) { INCFUNC("asm/func/LinkShopManager_Abort.inc"); }

NAKED bool8 LinkShopManager_Send(s32* args, s32 kind, u32 tag) { INCFUNC("asm/func/LinkShopManager_Send.inc"); }

void LinkShopManager_Kill(void) {
  if (gLinkShopManager != NULL) {
    KillEntity((Entity*)gLinkShopManager);
  }
}

void LinkShopManager_StopLinkWatch(void) {
  if (gLinkShopManager != NULL) {
    LinkShopManager_SetFlags(gLinkShopManager, LSFLAG_NO_LINK_WATCH);
  }
}

void LinkShopManager_AllowSoftReset(void) {
  if (gLinkShopManager != NULL) {
    LinkShopManager_SetFlags(gLinkShopManager, LSFLAG_ALLOW_SOFT_RESET);
  }
}
