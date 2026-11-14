#include "entity.h"
#include "gba/agbrfu.h"
#include "gba/linkManager.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "random.h"
#include "rfu.h"
#include "save.h"
#include "solar.h"
#include "sound.h"
#include "time.h"
#include "video.h"
#include "vm.h"

typedef enum {
  FLAG_0 = (1 << 0),  // 0x1, FUN_0804e514 が送信バッファ unk_b8 を埋めたあとに立てる
  FLAG_1 = (1 << 1),  // 0x2, 立っている間は FUN_0804e514 が送信を断る
  FLAG_2 = (1 << 2),  // 0x4, 立っていると RfuSession_ParentSendMemberList が RfuSession_BuildMemberList を呼んで下ろす
  FLAG_3 = (1 << 3),  // 0x8, 送信が終わると下ろして FLAG_5 を立てる
  FLAG_4 = (1 << 4),  // 0x10, 送信が終わると FLAG_7 を立てる
  FLAG_5 = (1 << 5),  // 0x20
  FLAG_6 = (1 << 6),  // 0x40
  FLAG_7 = (1 << 7),  // 0x80, 立っていると FUN_0804c888 が RfuSession_StartNIDataParent を呼ぶ
  FLAG_8 = (1 << 8),  // 0x100
  FLAG_9 = (1 << 9),  // 0x200
} LinkFlags22;        // RfuSession.unk_22

// 子機が NI で親機に送る 4 バイト
typedef struct {
  u8 flag;  // 0x00, 立っていると親機が unk_22 に FLAG_6 を立てて下ろす
  u8 unk_1[3];
} RfuSessionNiMsg;

// 子機が UNI で親機に送る 4 バイト
typedef struct {
  u8 seq;      // 0x00, 送るたびに 1 進める通し番号
  u8 players;  // 0x01, unk_134.slotBits で数えた人数
  u16 keys;    // 0x02, unk_ec を写す
} RfuSessionUniSend;

// 親機が UNI で全員に送る 16 バイト
typedef struct {
  u8 seq;       // 0x00, 送るたびに 1 進める通し番号
  u8 players;   // 0x01, 親機を含めた人数
  u8 slotBits;  // 0x02, unk_134.slotBits を写す
  u8 unk_03;
  u16 keys[5];  // 0x04, [0] が親機, [i+1] がスロット i の子機のキー
  u8 unk_0e[2];
} RfuSessionUniPacket;
static_assert(sizeof(RfuSessionUniPacket) == 16);

// 親機が子機へ NI で配る 64 バイト, RfuSession の 0x134 に置く
typedef struct {
  u8 unk_00;        // 0x00, unk_22 の FLAG_8 が立っていたら 1
  u8 unk_01;        // 0x01, unk_22 の FLAG_9 が立っていたら 1
  u8 slotBits;      // 0x02, つながっている子機のビット (スロット i が bit i+1, bit0 は親機)
  u8 playerCount;   // 0x03, 親機を含めた人数
  u8 names[5][10];  // 0x04, [0] が親機, [i+1] がスロット i の子機のユーザーネーム
  u16 slotIDs[5];   // 0x36, names と同じ並びの ID, 子機は gRfuLinkStatus->my.id と比べて自分の番号を探す
} RfuSessionUnk134;
static_assert(sizeof(RfuSessionUnk134) == 64);

// ワイヤレスアダプタ (RFU) の通信セッション, 接続から UNI でのキー交換・NI でのデータ交換までを受け持つ, ケーブル通信の LinkSession に当たる, Malloc で確保して自分で AddEntity し, 毎フレームの処理は SystemManager_Update から FUN_0804e36c 経由で RfuSession_Run が回すので _Update / _Destroy は持たない
typedef struct {
  Entity e;  // ENTITY_UNK_1
  u8 unk_18;
  u8 acceptedSlots;      // 0x19, 親機が受け入れた子機のスロットのビット, 切断で落とし, メンバ表の送り先にもなる
  u8 prevAcceptedSlots;  // 0x1A, 前回の acceptedSlots, 変わったらメンバ表を作り直して送る
  u8 unk_1b;             // 0x1B, 根拠: FUN_0804e4ac が 1 を入れる
  u8 unk_1c;             // 0x1C, 根拠: FUN_0804e4c4 が 1 を入れる
  u8 unk_1d;             // 0x1D, 根拠: FUN_0804e604 が 1 を入れる
  u8 unk_1e;             // 0x1E, 根拠: RfuSession_ClearLinkState が 0 を入れる
  s8 playerIdx;          // 0x1F, 子機のとき, slotIDs の中で自分の ID がある位置 (見つからなければ 4)
  u8 childSlot;          // 0x20, 親機のとき, 相手の子機がつながっているスロット番号
  u8 ownSlot;            // 0x21, 子機のとき, 自分のスロット番号
  u16 unk_22;            // 0x22, see LinkFlags22
  s8 parentCursor;       // 0x24, 親機候補の一覧で選んでいる位置 (0..7)
  u8 recoveringSlots;    // 0x25, リンク切れから復帰を試みているスロットのビット
  u8 foundParentBits;    // 0x26, 見つけた親機候補のビット (LMAN_MSG_PARENT_FOUND の param[0])
  u8 parentCount;        // 0x27, parentIdxs に入れた数
  u8 parentIdxs[8];      // 0x28, foundParentBits が立っていて slot が 3 以下の親機候補の番号
  bool8 isParent;        // 0x30, 親機なら TRUE, FUN_0823a730 の isParent に渡す, FUN_0804d680 は立っていたら rfu_clearAllSlot する
  bool8 keysReceived;    // 0x31, そのフレームに通信でキーを受け取れたら立つ, 立っていれば gLinkKeyInput に配って gUseLinkInput を TRUE にする
  bool8 stateBegun;      // 0x32, state を切り替えた側が立て, 各状態ハンドラが最初のフレームで 0 に戻す
  u8 errorKind;          // 0x33, 通信エラーの種類, 0: なし, 1: 復帰できない, 2: ボタンで戻れる, CrossoverError_Update が見て state を振り分ける
  u8 mode;               // 0x34, 0: 接続まで, 1: UNI でキーを交換中, 2: NI でデータを交換中, RfuSession_Run が毎フレームの処理を振り分ける
  u8 disconnectSlots;    // 0x35, NI 送信が届かなかった子機のビット, rfu_REQ_disconnect に渡して 0 に戻す
  u8 unk_36;             // 0x36, 同上
  u8 unk_37;
  u16 state;  // 0x38, sRfuSessionStates の添字
  u16 unk_3a;
  u8 unk_3c;  // 0x3C, 根拠: RfuSession_ClearLinkState が 0 を入れる
  u8 unk_3d;  // 0x3D, 根拠: FUN_0804e5e8 が 1 を入れる
  u8 unk_3e;
  u8 unk_3f;       // 0x3F, 根拠: FUN_0804cc98 が rfu_LMAN_stopManager に渡す
  u16 savedState;  // 0x40, リンク切れから復帰を試みる前の state, 復帰したら戻す
  u8 unk_42;
  u8 unk_43;
  u32 stateTimer;  // 0x44, state が変わると 0 に戻る
  u32 unk_48;
  s32 scriptID;     // 0x4C, '.p', 0 でなければ通信の区切りで VM_ExecByID する
  u8 gameName[16];  // 0x50, rfu に渡すゲームネーム, 文字列 11 バイトの後ろ [11..12] に unk_6c を入れる
  u8 userName[12];  // 0x60, rfu に渡すユーザーネーム, gStat->name を変換したもの
  u16 sessionID;    // 0x6C, 作るときに秒と乱数とフレームから決める番号, gameName[11..12] に入れて相手に見せ, ロビーにも数字で出す
  u8 unk_6e[0x70 - 0x6E];
  RfuSessionUniPacket uniPacket;  // 0x70, 親機が UNI で全員に送る 16 バイト
  RfuSessionUniSend childUni[4];  // 0x80, 子機ごとに UNI で受け取った 4 バイト
  RfuSessionUniSend uniSend;      // 0x90
  RfuSessionUniPacket uniRecv;    // 0x94, 子機が UNI で受け取った親機のパケット, 通し番号が続いていれば recvRing に積む
  RfuSessionNiMsg niSend;         // 0xA4, 子機が NI で親機に送る 4 バイト
  RfuSessionNiMsg niRecv[4];      // 0xA8, 子機スロットごとの NI 受信バッファ
  u32 unk_b8[3];                  // 0xB8, FUN_0804e514 が引数のバッファから 12バイトまとめて写す
  u32 unk_c4[3];                  // 0xC4, FUN_0804e55c が 12バイトまとめて引数のバッファに写す
  u8 lastRecvSeq[4];              // 0x0D0, スロットごとに最後に受け取った通し番号, 子機は [0] だけ使う
  u8 dupRecvCount[4];             // 0x0D4, 同じ通し番号を受け取った回数
  u8 lostRecvCount[4];            // 0x0D8, 通し番号が前より小さかった (子機は次でも同じでもなかった) 回数
  u8 gapRecvCount[4];             // 0x0DC, 通し番号が飛んだ回数 (親機のみ)
  u32 unk_e0;                     // 0x0E0, ACK が揃わないまま RfuSession_CollectAck が呼ばれた回数
  u8 unk_e4;                      // 0x0E4, 全員分のデータが揃ったのに ACK が揃っていなかった回数
  u8 unk_e5;                      // 0x0E5, ACK は揃ったのにデータが揃っていなかった回数
  u8 unk_e6;
  u8 unk_e7;        // 0x0E7, lman.parentAck_flag を1bit ずらして溜めたもの, unk_134.slotBits と揃うまで待つ
  u8 unk_e8;        // 0x0E8, ACK がまだ揃っていなければ 1
  u8 slotLost;      // 0x0E9, リンクが切れたスロットがあると立つ, TickUniParent が ACK を待ち直して下ろす
  u16 unk_ea;       // 0xEA, 根拠: FUN_0804ce0c が 0xFFFF を入れる
  u16 unk_ec;       // 0xEC, 根拠: FUN_0804bb70 が bit14 を見て unk_ee を書き込む
  u16 unk_ee;       // 0xEE, 根拠: FUN_0804bb68 が書く
  u16 linkKeys[5];  // 0xF0, 受け取った全員のキー, bit13 が立っていれば下位 12 ビットが有効, gLinkKeyInput に配る
  u8 unk_fa;        // 0xFA, RfuSession_PopRecvPacket が取り出しの成否に関わらず 1 を入れる
  u8 unk_fb;        // 0xFB, 根拠: Cmd_025E が 1 を入れる
  u8 unk_fc[0x100 - 0xFC];
  u16 unk_100[5];  // 0x100, recvPacket.keys を XOR で溜める
  u8 unk_10a[2];
  RfuSessionUniPacket recvPacket;  // 0x10C, recvRing から取り出したパケット
  INIT_PARAM initParam;            // 0x11C, rfu_LMAN_initializeRFU に渡す
  RfuSessionUnk134 unk_134;        // 0x134, 根拠: RfuSession_ClearLinkState が ClearMemory で 0 にする
  RfuRingBuf recvRing;             // 0x174
  void (*onSent)(void* msg);       // 0x378, CrossoverBattle_OnSent
  void (*onReceive)(void* msg);    // 0x37C, CrossoverBattle_OnReceive, NI 受信が成功すると unk_c4 を渡して呼ぶ
  void (*unk_380)(void);           // 0x380, FUN_0804f950
  void (*onRecvFailed)(void);      // 0x384, FUN_0804f970, NI 受信が失敗すると呼ぶ
  u8* strRefPc;                    // 0x388, '.a' の位置, VM_ParseStringRef で読む
  u8 unk_38c[908 - 0x38C];         // 0x38C, まだ未解析
} RfuSession;
static_assert(sizeof(RfuSession) == 908);

IWRAM_DATA volatile u8 gRfuSendBusy = 0;  // 0x030000DC, 送信要求を出すと 1, 受信要求が完了すると 0, 毎フレームの処理はこれが 0 になるまで待つ
IWRAM_DATA u32 u32_030000e0 = 0;          // 0x030000E0, 型不明

COMMON_DATA RfuSession* gRfuSession = NULL;  // 0x03002B58

// クロスオーバー通信で送る文字列を1文字 = 1エントリに展開した表, 根拠: Cmd_LoadCrossoverMappingBuf が 0x100 個まで strh で埋める
EWRAM_DATA u16 gCrossoverMappingBuf[256] = {};  // 0x0203FC00

extern u32 gRtcReadInhibit;  // src/time.c

const __attribute__((section(".rodata.faraddr"))) ALIGNED(4) u16 gAcceptableSerialNoList[2] = {0x0011, 0xFFFF};  // 0x08251D40, rfu_LMAN_establishConnection に渡す受け入れ可能シリアル番号の一覧, 0xFFFF 終端

void WaitForVBlanks(u16 n);
u16 rfu_NI_setSendData(u8 bmSendSlot, u8 subFrameSize, const void* src, u32 size);
void rfu_UNI_clearRecvNewDataFlag(u8 slotStatusIndex);
u16 rfu_UNI_changeAndReadySendData(u8 slotStatusIndex, const void* src, u8 size);
void rfu_REQ_PARENT_resumeRetransmitAndChange(void);
u16 rfu_UNI_setSendData(u8 bmSendSlot, const void* src, u8 size);
u32 StrCopyPadded(u8* src, u8* dst, s32 length);
void Crossover_EncodeText(u8* src, u8* dst, s32 count);
void RfuSession_StartNIDataParent(RfuSession* p);
void RfuSession_StartNIDataChild(RfuSession* p);
s32 FUN_0804bb68(RfuSession* p, u32 val);
void FUN_0804e584(s32);
extern s32 (*const sRfuSessionStates[33])(RfuSession*);

// unk_1c を下ろし, state を切り替えて stateTimer を 0 に戻す
static inline void RfuSession_SetState(RfuSession* p, u16 state) {
  p->unk_1c = 0;
  p->state = state;
  p->stateTimer = 0;
}

// 自分のキーに有効の印 (bit13) を付けて送る値に入れる
static inline void RfuSession_SendKeys(RfuSession* p, u32 keys) { FUN_0804bb68(p, keys | 0x2000); }

RfuSession* FUN_0804ba3c(void) { return gRfuSession; }

bool32 FUN_0804ba48(void) {
  if (gRfuSession != NULL) {
    return TRUE;
  }
  return FALSE;
}

// 通信の状態をまとめて初期値に戻す
void RfuSession_Reset(RfuSession* p) {
  s32 i;

  p->unk_1c = 0;
  p->acceptedSlots = 0;
  p->prevAcceptedSlots = 0;
  p->unk_1e = 0;
  p->playerIdx = 0;
  p->childSlot = 0;
  p->ownSlot = 0;
  p->unk_22 = 0;
  p->parentCursor = 0;
  p->recoveringSlots = 0;
  p->foundParentBits = 0;
  p->parentCount = 0;
  for (i = 0; i < 8; i++) {
    p->parentIdxs[i] = 0;
  }
  p->isParent = TRUE;
  p->keysReceived = FALSE;
  p->mode = 0;
  p->disconnectSlots = 0;
  p->unk_36 = 0;
  RfuSession_SetState(p, 0);
  p->stateBegun = TRUE;
  p->unk_3a = 0;
  p->unk_3c = 0;
  p->unk_3d = 0;
  p->unk_3e = 0;
  p->unk_3f = 0;
  p->savedState = 0;
  p->unk_42 = 0;
  p->unk_43 = 0;
  p->unk_48 = 0;
  gRfuSendBusy = 0;
  p->unk_fb = 0;
  p->mode = 0;
  p->onSent = NULL;
  p->onReceive = NULL;
  ClearMemory(&p->unk_134, sizeof(p->unk_134));
  ClearMemory(&p->niSend, sizeof(p->niSend));
  ClearMemory(p->niRecv, sizeof(p->niRecv));
}

// 通信用の状態をまとめて初期化する
void RfuSession_ClearLinkState(RfuSession* p) {
  p->unk_1e = 0;
  p->unk_22 = 0;
  p->disconnectSlots = 0;
  p->unk_36 = 0;
  p->unk_3c = 0;
  p->unk_3d = 0;
  p->unk_3e = 0;
  p->unk_3f = 0;
  ClearMemory(&p->unk_134, sizeof(p->unk_134));
}

// 残差は 3 命令 vs 4 命令 で、原典は p を別レジスタに複写してから +0xEE している (局所コピーを置いても agbcc が畳んでしまう)
s32 FUN_0804bb68(RfuSession* p, u32 val) { p->unk_ee = val; }

// unk_ec の bit14 が立っていたら unk_ee を取り込む
s32 FUN_0804bb70(RfuSession* p) {
  if (p->unk_ec & 0x4000) {
    p->unk_ec = p->unk_ee;
    return 0;
  }

  return -1;
}

// 受信リングから1件取り出してキーを linkKeys に写し, unk_100 に XOR で溜める, 空なら -2
s32 RfuSession_PopRecvPacket(RfuSession* p) {
  RfuSessionUniPacket* packet = &p->recvPacket;
  s32 ret;

  if (FUN_0823a7d8(&p->recvRing, packet)) {
    s32 i;

    for (i = 0; i < 5; i++) {
      p->linkKeys[i] = packet->keys[i];
      p->unk_100[i] ^= packet->keys[i];
    }
    ret = 0;
  } else {
    ret = -2;
  }
  p->unk_fa = 1;
  return ret;
}

s32 FUN_0804bbf8(RfuSession* p) {
  if (p->unk_1b != 0) {
    p->unk_1b = 0;
    return 1;
  }
  return 0;
}

s32 FUN_0804bc10(RfuSession* p) {
  if (p->unk_1c != 0) {
    p->unk_1c = 0;
    return 1;
  }
  return 0;
}

// 見つけた親機候補から選べるものを parentIdxs に並べる, 後半の空ループは parentCursor の前後 5 件を表示していた処理の名残とみられる
void RfuSession_ListParents(RfuSession* p) {
  s32 i;
  s32 start, end;
  s32 j;

  p->parentCount = 0;
  for (i = 0; i < gRfuLinkStatus->findParentCount; i++) {
    if (((p->foundParentBits >> i) & 1) && gRfuLinkStatus->partner[i].slot <= 3) {
      p->parentIdxs[p->parentCount] = i;
      p->parentCount++;
    }
  }
  start = p->parentCursor - 2;
  end = p->parentCursor + 3;
  if (start < 0) {
    for (j = start; j < 0; j++) {
    }
  }
  for (i = start < 0 ? 0 : start; i < (end > 8 ? 8 : end); i++) {
  }
  if (end > 7) {
    for (; i < end; i++) {
    }
  }
}

// 子機へ配る unk_134 を組み立てる, 人数とつながっているスロット, 各自の名前と ID を詰める
s32 RfuSession_BuildMemberList(RfuSession* p) {
  RfuSessionUnk134* q = &p->unk_134;
  s32 i;

  CpuFill16(0, q, sizeof(*q));
  if (p->unk_22 & FLAG_8) {
    q->unk_00 = 1;
    p->unk_22 |= FLAG_3;
    p->unk_22 &= ~FLAG_8;
  } else {
    q->unk_00 = 0;
  }
  if (p->unk_22 & FLAG_9) {
    q->unk_01 = 1;
    p->unk_22 |= FLAG_4;
    p->unk_22 &= ~FLAG_9;
  } else {
    q->unk_01 = 0;
  }
  q->playerCount = 1;
  for (i = 0; i < 4; i++) {
    if ((p->acceptedSlots >> i) & 1) {
      q->playerCount++;
    }
  }
  q->slotBits = (p->acceptedSlots << 1) | 1;
  StrCopyPadded(gRfuLinkStatus->my.uname, q->names[0], 8);
  q->slotIDs[0] = gRfuLinkStatus->my.id;
  for (i = 0; i < 4; i++) {
    if ((p->acceptedSlots >> i) & 1) {
      StrCopyPadded(gRfuLinkStatus->partner[i].uname, q->names[i + 1], 8);
      q->slotIDs[i + 1] = gRfuLinkStatus->partner[i].id;
    }
  }
}

// 親機側, 送るものがあれば unk_134 を子機へ NI 送信する, RfuSession_BuildMemberList で送るものを作ったら TRUE
bool32 RfuSession_ParentSendMemberList(RfuSession* p) {
  bool32 ret = FALSE;

  if ((p->unk_22 & FLAG_1) || gRfuLinkStatus->linkLossSlot_flag != 0 || (p->unk_22 & (FLAG_5 | FLAG_7))) {
    return FALSE;
  }
  if (p->state == 9 && !(p->unk_22 & (FLAG_4 | FLAG_9))) {
    p->unk_22 |= FLAG_0 | FLAG_2 | FLAG_9;
  }
  if (p->prevAcceptedSlots != p->acceptedSlots) {
    p->unk_22 |= FLAG_2;
    if (gRfuLinkStatus->connectSlot_flag != 0) {
      p->unk_22 |= FLAG_0;
    }
  }
  p->prevAcceptedSlots = p->acceptedSlots;
  if (p->unk_22 & FLAG_2) {
    RfuSession_BuildMemberList(p);
    p->unk_22 &= ~FLAG_2;
    ret = TRUE;
  }
  if (p->unk_22 & FLAG_0) {
    if (rfu_NI_setSendData(p->acceptedSlots, 0x43, &p->unk_134, sizeof(p->unk_134)) == 0) {
      s32 i;

      for (i = 0; i < 4; i++) {
        if ((gRfuLinkStatus->connectSlot_flag >> i) & 1) {
          break;
        }
      }
      p->childSlot = i;
      p->unk_22 = (p->unk_22 & ~FLAG_0) | FLAG_1;
    } else {
      FUN_0804e584(2);
    }
  }
  return ret;
}

// 子機への NI 送信の結果を見て, 終わったら次の段のフラグを立て, 届かなかった子機を disconnectSlots に溜める
void RfuSession_ParentCheckListSent(RfuSession* p) {
  u8 failed = 0;

  if (p->unk_22 & FLAG_1) {
    RFU_SLOT_STATUS_NI* ni = gRfuSlotStatusNI[p->childSlot];

    if (ni->send.state == SLOT_STATE_SEND_SUCCESS) {
      failed = ni->send.bmSlot_org ^ ni->send.bmSlot;
      rfu_clearSlot(TYPE_NI_SEND, p->childSlot);
      p->unk_22 &= ~FLAG_1;
      if (p->unk_22 & FLAG_4) {
        p->unk_22 |= FLAG_7;
      }
      if (p->unk_22 & FLAG_3) {
        p->unk_22 = (p->unk_22 & ~FLAG_3) | FLAG_5;
      }
    } else if (ni->send.state == SLOT_STATE_SEND_FAILED) {
      failed = ni->send.bmSlot_org ^ ni->send.bmSlot;
      rfu_clearSlot(TYPE_NI_SEND, p->childSlot);
      p->unk_22 = 0;
      if (p->state == 9) {
        RfuSession_SetState(p, 7);
        p->stateBegun = TRUE;
      }
    }
    if (failed) {
      p->disconnectSlots |= failed;
    }
  }
}

// 親機の接続までのリンクマネージャーのコールバック, 何もしないケースの値は分岐木の形から推定したもの
void RfuSession_LmanCallbackParentConnect(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_INITIALIZE_COMPLETED: {
      RfuSession_SetState(p, 5);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED: {
      p->acceptedSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED: {
      RfuSession_SetState(p, 5);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_END_WAIT_CHILD_NAME: {
      if (gRfuLinkStatus->connectCount == 0) {
        RfuSession_SetState(p, 5);
        p->stateBegun = TRUE;
      } else {
        RfuSession_SetState(p, 9);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->acceptedSlots &= ~lman.param[0];
      p->recoveringSlots &= ~lman.param[0];
      if (p->acceptedSlots == 0) {
        RfuSession_SetState(p, 11);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER: {
      p->acceptedSlots &= ~lman.param[0];
      p->recoveringSlots &= ~lman.param[0];
      if (p->acceptedSlots == 0) {
        RfuSession_SetState(p, 11);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_SetState(p, 32);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_MANAGER_STOPPED: {
      RfuSession_SetState(p, 5);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET: {
      RfuSession_SetState(p, 30);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      if (p->state != 28 && p->state > 1) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
    case LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE: {
      break;
    }
  }
}

// 子機の接続までのリンクマネージャーのコールバック
void RfuSession_LmanCallbackChildConnect(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      rfu_LMAN_REQ_sendData(1);
      break;
    }
    case LMAN_MSG_INITIALIZE_COMPLETED: {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_PARENT_FOUND: {
      p->foundParentBits = lman.param[0];
      break;
    }
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED: {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED: {
      p->ownSlot = lman.param[0];
      rfu_setRecvBuffer(TYPE_NI, p->ownSlot, &p->unk_134, sizeof(p->unk_134));
      RfuSession_SetState(p, 14);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CONNECT_PARENT_FAILED: {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED: {
      s32 i;

      p->unk_43 = 0;
      i = gRfuLinkStatus->connectSlot_flag;
      while (--i != 0) {
        p->unk_43++;
      }
      break;
    }
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED: {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      p->savedState = p->state;
      RfuSession_SetState(p, 16);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      RfuSession_SetState(p, p->savedState);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->recoveringSlots &= ~lman.param[0];
      if (p->state > 15) {
        RfuSession_SetState(p, 29);
        p->stateBegun = TRUE;
        rfu_LMAN_stopManager(1);
      } else {
        RfuSession_SetState(p, 11);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER: {
      RfuSession_SetState(p, 11);
      p->stateBegun = TRUE;
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_SetState(p, 32);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_MANAGER_STOPPED: {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET: {
      RfuSession_SetState(p, 30);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      if (p->state == 28) {
        break;
      }
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      if (p->state == 28) {
        break;
      }
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      if (p->state == 28 || p->state <= 1) {
        break;
      }
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CHANGE_AGB_CLOCK_MASTER: {
      break;
    }
  }
}

void FUN_0804c3a8(u16 reqCommandId) { rfu_REQ_recvData(); }

void FUN_0804c3b4(void) {
  if (gRfuSession != NULL) {
    rfu_REQ_recvData();
  }
}

s32 FUN_0804c3cc(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

// リンクマネージャーを初期化し, 成否で state を分ける
s32 FUN_0804c3e4(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }

  if (rfu_LMAN_initializeManager(RfuSession_LmanCallbackParentConnect, FUN_0804c3a8) != 0) {
    RfuSession_SetState(p, 27);
    p->stateBegun = TRUE;
  } else {
    RfuSession_SetState(p, 2);
    p->stateBegun = TRUE;
    p->unk_18 = 1;
  }
  return 0;
}

// RFU のソフトリセットを待ってから, ゲームネームとユーザーネームを作ってリンクマネージャーの初期値を組む
// 149/143命令, 原典は state 3 と Random() & 3 の 3 を r4 で共有して r8 を使わず, 時間帯の 0/1, 2/3 は先に大きい方を入れてから比べる, 三項演算子の向き / if-else / bool 値 / TIME_ の == 列挙と範囲は試済
NON_MATCH s32 FUN_0804c438(RfuSession* p) {
#ifdef NONMATCHING_C
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (p->unk_3c != 0) {
    p->unk_3c--;
  } else {
    switch (PollRfuSoftReset()) {
      case -1: {
        RfuSession_SetState(p, 27);
        p->stateBegun = TRUE;
        break;
      }
      case 0: {
        p->unk_3c = 60;
        break;
      }
      case 1: {
        s32 base;
        s32 n;
        char* str;

        RfuSession_SetState(p, 3);
        p->stateBegun = TRUE;
        base = VM_ParseStringRef(p->strRefPc);
        if ((Random() & 0xFF) < 64) {
          u32 span = Time_GetSpanOfTime();
          s32 hour = Time_GetHour();

          if (span == TIME_MORNING || span == TIME_DAYTIME || span == TIME_SUNSET) {
            n = hour > 11 ? 1 : 0;
          } else {
            n = hour > 11 ? 3 : 2;
          }
        } else {
          n = (Random() & 3) + 4;
        }
        str = GetStringByID(base + n);
        Crossover_EncodeText(gStat->name, p->userName, 8);
        Crossover_EncodeText(str, p->gameName, 11);
        p->gameName[11] = p->sessionID;
        p->gameName[12] = p->sessionID >> 8;
        FUN_0823a730(&p->initParam, p->isParent, 0x11, p->isParent ? 3 : 0, 0, p->gameName, p->userName);
        break;
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0804c438.inc");
#endif
}

// 60フレーム待ってから RFU を初期化し直す
s32 RfuSession_StateReinitRFU(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (p->stateTimer >= 60) {
    rfu_LMAN_initializeRFU(&p->initParam);
    gRfuSendBusy = 0;
    RfuSession_SetState(p, 4);
    p->stateBegun = TRUE;
  }
  return 0;
}

s32 FUN_0804c5c0(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  return 0;
}

// 親機として接続を始め, 成否で state を分ける
s32 RfuSession_StateConnectAsParent(RfuSession* p) {
  if (p->stateBegun) {
    s32 i;

    p->stateBegun = FALSE;
    for (i = 0; i < 4; i++) {
      rfu_setRecvBuffer(TYPE_NI, i, p->niRecv, sizeof(p->niRecv[0]));
    }
  }

  if (rfu_LMAN_establishConnection(MODE_PARENT, 0, 600, (u16*)gAcceptableSerialNoList)) {
    RfuSession_SetState(p, 27);
    p->stateBegun = TRUE;
    return -1;
  }

  RfuSession_SetState(p, 7);
  p->stateBegun = TRUE;
}

s32 FUN_0804c650(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    p->foundParentBits = 0;
  }

  if (rfu_LMAN_establishConnection(0, 0, 600, (u16*)gAcceptableSerialNoList)) {
    RfuSession_SetState(p, 27);
    p->stateBegun = TRUE;
    return -1;
  }

  RfuSession_SetState(p, 8);
  p->stateBegun = TRUE;
}

// 親機の待ち受け中の状態ハンドラ, 子機がそろったら state 9 に移る
s32 RfuSession_StateParentWait(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    p->unk_1b = 0;
    p->unk_1c = 0;
  }
  if (FUN_0804bbf8(p)) {
    if (p->unk_134.unk_01 == 0 && !(p->unk_22 & (FLAG_3 | FLAG_4 | FLAG_5 | FLAG_9))) {
      p->unk_22 |= FLAG_0 | FLAG_2 | FLAG_8;
    }
    p->unk_1b = 0;
  }
  if (p->unk_22 & FLAG_6) {
    if (!(p->unk_22 & (FLAG_3 | FLAG_4 | FLAG_5 | FLAG_8 | FLAG_9))) {
      p->unk_22 |= FLAG_0 | FLAG_2 | FLAG_8;
    }
  }
  if (gRfuSlotStatusNI[p->childSlot]->recv.state == SLOT_STATE_RECV_SUCCESS) {
    if (p->niRecv[p->childSlot].flag) {
      p->niRecv[p->childSlot].flag = 0;
      p->unk_22 |= FLAG_6;
    }
    rfu_clearSlot(TYPE_NI_RECV, p->childSlot);
  }
  if ((p->unk_22 & (FLAG_5 | FLAG_6)) == (FLAG_5 | FLAG_6)) {
    p->unk_22 &= ~FLAG_5;
    p->unk_22 &= ~FLAG_6;
    p->disconnectSlots |= gRfuLinkStatus->connectSlot_flag | gRfuLinkStatus->linkLossSlot_flag;
    return 0;
  }
  if (p->acceptedSlots != 0 && !(p->unk_22 & (FLAG_3 | FLAG_5 | FLAG_6 | FLAG_8)) && p->acceptedSlots == gRfuLinkStatus->connectSlot_flag) {
    if (FUN_0804bc10(p)) {
      RfuSession_SetState(p, 9);
      p->stateBegun = TRUE;
      return 0;
    }
  }
}

// 親機候補の一覧から上下で選び, A で接続を始める
s32 RfuSession_StateSelectParent(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  RfuSession_ListParents(p);
  if (p->parentCount != 0) {
    s32 prev = p->parentCursor;
    s32 cursor;
    s32 count;

    if (gInput[0].pressed & DPAD_UP) {
      p->parentCursor--;
    } else if (gInput[0].pressed & DPAD_DOWN) {
      p->parentCursor++;
    }
    if (prev != p->parentCursor) {
      if (p->parentCursor > 7) {
        p->parentCursor = 7;
      } else if (p->parentCursor < 0) {
        p->parentCursor = 0;
      }
    }
    cursor = p->parentCursor;
    count = p->parentCount;
    if ((gInput[0].pressed & A_BUTTON) && cursor < count) {
      u8 idx = p->parentIdxs[cursor];

      if (rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[idx].id, 0) == 0) {
        RfuSession_SetState(p, 10);
        p->stateBegun = TRUE;
        return 0;
      }
    }
  }
}

s32 FUN_0804c888(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    PlaySound_082406e0(SE_SELECT);
  }

  if (p->unk_22 & FLAG_7) {
    WaitForVBlanks(8);
    RfuSession_StartNIDataParent(p);
  }
}

s32 FUN_0804c8bc(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }

  if (p->stateTimer > 599) {
    rfu_LMAN_stopManager(0);
    RfuSession_SetState(p, 4);
    p->stateBegun = TRUE;
  }
}

// 1.5 秒待ってから通信の状態を初期化し, 親機なら state 7, 子機なら state 6 に戻る
s32 RfuSession_StateCancel(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    PlaySound_082406e0(SE_CANCEL);
  }
  if (p->stateTimer >= 90) {
    RfuSession_ClearLinkState(p);
    if (p->isParent) {
      RfuSession_SetState(p, 7);
      p->stateBegun = TRUE;
    } else {
      RfuSession_SetState(p, 6);
      p->stateBegun = TRUE;
    }
  }
}

s32 FUN_0804c940(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (rfu_getMasterSlave() == AGB_CLK_MASTER) {
    rfu_REQ_disconnect(gRfuLinkStatus->connectSlot_flag | gRfuLinkStatus->linkLossSlot_flag);
    rfu_waitREQComplete();
  }
}

// 120フレーム経ったらstate 8 に切り替える
s32 FUN_0804c978(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }

  if (p->stateTimer > 120) {
    RfuSession_SetState(p, 8);
    p->stateBegun = TRUE;
  }
}

// 子機の待ち受け中の状態ハンドラ, 親機の合図とメンバ表を受け取り, 揃ったら state 12 に移る
s32 RfuSession_StateChildWait(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (gRfuSlotStatusNI[p->ownSlot]->recv.state == SLOT_STATE_RECV_SUCCESS) {
    if (p->unk_134.unk_01) {
      RfuSession_StartNIDataChild(p);
    }
    if (p->unk_134.unk_00) {
      p->unk_134.unk_00 = 0;
      p->unk_22 |= FLAG_6;
    }
    rfu_clearSlot(TYPE_NI_RECV, p->ownSlot);
  }
  if (gInput[0].pressed & B_BUTTON) {
    p->unk_22 |= FLAG_8;
    p->unk_22 |= FLAG_0;
  }
  if (p->unk_22 & FLAG_6) {
    if (!(p->unk_22 & (FLAG_3 | FLAG_5))) {
      p->unk_22 |= FLAG_8;
      p->unk_22 |= FLAG_0;
    }
  }
  if (!(p->unk_22 & FLAG_1)) {
    if (gRfuLinkStatus->linkLossSlot_flag == 0 && (p->unk_22 & FLAG_0)) {
      if (p->unk_22 & FLAG_8) {
        p->niSend.flag = 1;
        p->unk_22 &= ~FLAG_8;
        p->unk_22 |= FLAG_3;
      }
      rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
      if (rfu_NI_setSendData(1 << p->ownSlot, 6, &p->niSend, sizeof(p->niSend)) != 0) {
        FUN_0804e584(2);
        return 0;
      }
      p->unk_22 &= ~FLAG_0;
      p->unk_22 |= FLAG_1;
    }
  }
  if (p->unk_22 & FLAG_1) {
    u16 state = gRfuSlotStatusNI[p->ownSlot]->send.state;

    if (state == SLOT_STATE_SEND_SUCCESS) {
      rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
      p->unk_22 &= ~FLAG_1;
      if (p->unk_22 & FLAG_3) {
        p->unk_22 &= ~FLAG_3;
        p->unk_22 |= FLAG_5;
        p->niSend.flag = 0;
      }
    } else if (state == SLOT_STATE_SEND_FAILED) {
      rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
      p->unk_22 = 0;
    }
  }
  if ((p->unk_22 & (FLAG_5 | FLAG_6)) == (FLAG_5 | FLAG_6)) {
    p->unk_22 &= ~FLAG_5;
    p->unk_22 &= ~FLAG_6;
    rfu_LMAN_requestChangeAgbClockMaster();
    RfuSession_SetState(p, 12);
    p->stateBegun = TRUE;
    return 0;
  }
}

s32 FUN_0804cb6c(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

s32 FUN_0804cb84(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

s32 FUN_0804cb9c(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

s32 FUN_0804cbb4(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

s32 FUN_0804cbcc(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    p->unk_1b = 0;
    p->unk_1c = 0;
  }

  if (FUN_0804bc10(p)) {
    RfuSession_Reset(p);
  }

  return 0;
}

s32 FUN_0804cbfc(RfuSession* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = FALSE;
    FUN_0804e584(1);
    rfu_LMAN_stopManager(1);
    p->unk_1b = 0;
    p->unk_1c = 0;
  }
  if (FUN_0804bc10(p)) {
    RfuSession_Reset(p);
  }
  return 0;
}

s32 FUN_0804cc38(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FUN_0804e584(2);
    rfu_LMAN_stopManager(1);
    p->unk_1b = 0;
    p->unk_1c = 0;
  }

  if (FUN_0804bc10(p)) {
    RfuSession_SetState(p, 30);
    p->stateBegun = TRUE;
  }
  return 0;
}

s32 FUN_0804cc7c(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    rfu_LMAN_powerDownRFU();
  }
  return 0;
}

s32 FUN_0804cc98(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    rfu_LMAN_stopManager(p->unk_3f);
  }
  return 0;
}

s32 FUN_0804ccbc(RfuSession* p) {
  rfu_clearAllSlot();
  RfuSession_Reset(p);
}

// 子機からの ACK を溜めて, 待っている全スロットから返ってきたかどうかを見る
void RfuSession_CollectAck(RfuSession* p) {
  p->unk_e7 |= lman.parentAck_flag << 1;

  if ((p->unk_e7 & p->unk_134.slotBits) == p->unk_134.slotBits) {
    p->unk_e8 = 0;
    p->unk_36 = 0;
  } else {
    p->unk_e8 = 1;
    p->unk_e0++;
  }
}

// 92/94命令, 残差は lastRecvSeq との2つめの比較で原典が lsls/lsrs #24 の切り詰めを残す2命令だけ, s32 + (u8) キャスト / u8 引数の inline / uniRecv を構造体ポインタで持つ形は試済, 同形の一致済み関数は他ファイルに無し
NON_MATCH bool32 FUN_0804cd1c(RfuSession* p) {
#ifdef NONMATCHING_C
  RfuSessionUnk134* q = &p->unk_134;
  bool32 ret = FALSE;

  if (gRfuSlotStatusUNI[p->ownSlot]->recv.newData_flag) {
    RfuSessionUniSend* send = &p->uniSend;
    u8 prev;
    s32 i;

    rfu_UNI_clearRecvNewDataFlag(p->ownSlot);
    prev = p->lastRecvSeq[0];
    if ((u8)(prev + 1) == p->uniRecv.seq) {
      FUN_0823a790(&p->recvRing, &p->uniRecv);
    } else if (prev == p->uniRecv.seq) {
      p->dupRecvCount[0]++;
    } else {
      p->lostRecvCount[0]++;
    }
    p->lastRecvSeq[0] = p->uniRecv.seq;
    send->seq++;
    send->players = 0;
    for (i = 0; i < 5; i++) {
      if ((q->slotBits >> i) & 1) {
        send->players++;
      }
    }
    send->keys = p->unk_ec;
    p->unk_ec = 0xFFFF;
    p->unk_fa = 0;
    ret = TRUE;
  }
  return ret;
#else
  INCFUNC("asm/func/FUN_0804cd1c.inc");
#endif
}

void FUN_0804cde8(RfuSession* p) {
  if (FUN_0804cd1c(p)) {
    rfu_UNI_readySendData(p->ownSlot);
  }
  rfu_LMAN_REQ_sendData(1);
}

// 通信スロットの対応表を未割り当てに戻す
void FUN_0804ce0c(RfuSession* p) {
  s32 i;

  p->unk_ea = 0xFFFF;
  p->unk_ec = -1;

  for (i = 0; i < 5; i++) {
    p->linkKeys[i] |= -1;
  }
}

// 親機側, 子機ごとに UNI の新着を取り込んで通し番号を数え, 全員分のデータと ACK の揃い方の食い違いを数える
// 141/132命令, こちらは i*4 を誘導変数にしてスタックへ逃がし p の複写も増える, 原典は i*4 を毎周 lsls で作り childUni[i] だけを誘導変数にする
NON_MATCH void RfuSession_RecvChildUni(RfuSession* p) {
#ifdef NONMATCHING_C
  RfuSessionUnk134* q = &p->unk_134;
  s32 i;

  p->unk_3e = 0;
  for (i = 0; i < 4; i++) {
    if ((q->slotBits & (2 << i)) && gRfuSlotStatusUNI[i]->recv.newData_flag) {
      RfuSessionUniSend* uni = &p->childUni[i];
      s32 prev;

      p->unk_e6 |= 2 << i;
      rfu_UNI_clearRecvNewDataFlag(i);
      prev = p->lastRecvSeq[i];
      if ((u8)(prev + 1) != uni->seq) {
        if ((u8)prev == uni->seq) {
          p->dupRecvCount[i]++;
          uni->keys = 0;
        } else if ((u8)prev < uni->seq) {
          p->gapRecvCount[i]++;
          uni->keys = 0;
        } else {
          p->lostRecvCount[i]++;
        }
      }
      p->lastRecvSeq[i] = uni->seq;
    }
  }
  if ((p->unk_e6 & q->slotBits) == q->slotBits && (p->unk_e7 & q->slotBits) != q->slotBits) {
    p->unk_e4++;
  }
  if ((p->unk_e7 & q->slotBits) == q->slotBits && (p->unk_e6 & q->slotBits) != q->slotBits) {
    p->unk_e5++;
  }
#else
  INCFUNC("asm/func/RfuSession_RecvChildUni.inc");
#endif
}

// 親機側, 全員から ACK が返ったら前のパケットを recvRing に積み, 子機のキーを集めて次の uniPacket を組み立てる
// 130/130命令, 残差は &unk_e7 と &unk_36 を退避するスタック位置 (sp+8 / sp+0xC) の入れ替わりだけ, ローカルの宣言順は試済
NON_MATCH void FUN_0804cf4c(RfuSession* p) {
#ifdef NONMATCHING_C
  RfuSessionUnk134* q = &p->unk_134;
  RfuSessionUniPacket* pkt = &p->uniPacket;

  if ((p->unk_e7 & q->slotBits) != q->slotBits) {
    return;
  }
  if (p->unk_3e) {
    if (q->playerCount > 1) {
      p->unk_36 = 1;
    }
  } else {
    u32 seq = pkt->seq;
    s32 i;

    FUN_0823a790(&p->recvRing, pkt);
    p->unk_36 = 0;
    CpuFill32(0, pkt, sizeof(*pkt));
    for (i = 0; i < 4; i++) {
      if (TEST_FLAGS(q->slotBits, 2 << i)) {
        pkt->keys[i + 1] = p->childUni[i].keys;
      }
    }
    pkt->keys[0] = p->unk_ea;
    p->unk_ea = p->unk_ec;
    p->unk_ec = 0xFFFF;
    pkt->slotBits = q->slotBits;
    pkt->players = 1;
    for (i = 0; i < 4; i++) {
      if (q->slotBits & (2 << i)) {
        pkt->players++;
      }
    }
    pkt->seq = seq + 1;
    p->unk_e7 = 1;
    p->unk_e6 = 1;
    if (q->playerCount > 1) {
      p->unk_36 = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0804cf4c.inc");
#endif
}

// 40/40命令, 残差は q->slotBits の読みが原典では movs r5, #2 より前に来る1命令の順序だけ
NON_MATCH void RfuSession_RemoveSlots(RfuSession* p, u8 slots) {
#ifdef NONMATCHING_C
  RfuSessionUnk134* q = &p->unk_134;
  u8 bits = slots << 1;
  s32 i;

  for (i = 0; i < 5; i++) {
    if ((2 << i) & q->slotBits & bits) {
      if (q->playerCount > 1) {
        q->playerCount--;
      }
    }
  }
  q->slotBits &= ~bits;
  if ((q->slotBits & p->unk_e7) == q->slotBits) {
    p->unk_e8 = 0;
  }
#else
  INCFUNC("asm/func/RfuSession_RemoveSlots.inc");
#endif
}

// UNI 通信中の親機側のリンクマネージャーのコールバック, 何もしないケースの値は分岐木の形から推定したもの
void RfuSession_LmanCallbackUniParent(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      RfuSession_CollectAck(p);
      RfuSession_RecvChildUni(p);
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->recoveringSlots &= ~lman.param[0];
      p->slotLost = TRUE;
      RfuSession_RemoveSlots(p, lman.param[0]);
      if (p->unk_134.playerCount == 1) {
        rfu_LMAN_stopManager(1);
        RfuSession_SetState(p, 29);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER: {
      RfuSession_RemoveSlots(p, lman.param[0]);
      if (p->unk_134.playerCount == 1) {
        rfu_LMAN_stopManager(1);
        RfuSession_SetState(p, 29);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_Reset(p);
      break;
    }
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET: {
      RfuSession_SetState(p, 30);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
    case LMAN_MSG_END_WAIT_CHILD_NAME:
    case LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE:
    case LMAN_MSG_MANAGER_STOPPED: {
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      gRfuSendBusy = 0;
      break;
    }
  }
}

// UNI 通信中のリンクマネージャーのコールバック, 何もしないケースの値は分岐木の形から推定したもの
void RfuSession_LmanCallbackUniChild(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      FUN_0804cde8(p);
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->recoveringSlots &= ~lman.param[0];
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 29);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_Reset(p);
      break;
    }
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER:
    case LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
    case LMAN_MSG_CHANGE_AGB_CLOCK_MASTER: {
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      if (lman.param[0] == 0x30) {
        if (lman.param[1] == 3) {
          lman.param[1] = 0;
        }
      }
      if (lman.param[1] == 0) {
        break;
      }
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      rfu_LMAN_stopManager(1);
      RfuSession_SetState(p, 28);
      p->stateBegun = TRUE;
      break;
    }
  }
}

// 子機からの ACK を取り込んで, 待っている全スロットから返ってきたかどうかを見る
void RfuSession_RecvParentAck(u16 reqCommandId) {
  RfuSession* p = gRfuSession;

  if (p != NULL) {
    RfuSessionUnk134* q = &p->unk_134;
    u8 ack;

    if (rfu_UNI_PARENT_getDRAC_ACK(&ack) == 0) {
      p->unk_e7 |= ack << 1;
      if ((p->unk_e7 & q->slotBits) == q->slotBits) {
        p->unk_e8 = 0;
        p->unk_36 = 0;
      } else {
        p->unk_e8 = 1;
        p->unk_e0++;
      }
    }
    rfu_REQ_recvData();
  }
}

void FUN_0804d36c(u16 param_1) {
  if (gRfuSession != NULL) {
    if (param_1 == 0x27) {
      rfu_REQ_changeMasterSlave();
      rfu_waitREQComplete();
    } else {
      rfu_REQ_recvData();
    }
  }
}

// 親機として UNI 通信を始める準備, パケットと受信バッファを用意してコールバックを仕掛ける
void RfuSession_StartUniParent(RfuSession* p) {
  RfuSessionUnk134* q = &p->unk_134;
  s32 i;

  ClearBGTilemapBuffer(0);
  p->playerIdx = 0;
  FUN_0823a76c(&p->recvRing);
  ClearMemory(&p->uniPacket, sizeof(p->uniPacket));
  ClearMemory(p->childUni, sizeof(p->childUni));
  FUN_0804ce0c(p);
  p->unk_e8 = 0;
  p->slotLost = FALSE;
  p->unk_e7 = 1;
  p->unk_e6 = 1;
  p->unk_37 = q->slotBits;
  p->uniPacket.slotBits = q->slotBits = (gRfuLinkStatus->connectSlot_flag << 1) | 1;
  p->uniPacket.seq = 1;
  p->uniPacket.players = 1;
  for (i = 0; i < 4; i++) {
    if (q->slotBits & (2 << i)) {
      p->uniPacket.players++;
    }
  }
  p->unk_36 = 1;
  for (i = 0; i < 4; i++) {
    p->lastRecvSeq[i] = 0;
    p->dupRecvCount[i] = 0;
    p->lostRecvCount[i] = 0;
    p->gapRecvCount[i] = 0;
  }
  p->unk_e0 = 0;
  p->unk_e4 = 0;
  p->unk_e5 = 0;
  rfu_LMAN_setLMANCallback(RfuSession_LmanCallbackUniParent);
  rfu_LMAN_setMSCCallback(RfuSession_RecvParentAck);
  for (i = 0; i < 4; i++) {
    if (q->slotBits & (2 << i)) {
      rfu_setRecvBuffer(TYPE_UNI, i, &p->childUni[i], sizeof(p->childUni[i]));
    }
  }
  if (rfu_UNI_setSendData(q->slotBits >> 1, &p->uniPacket, sizeof(p->uniPacket)) == 0) {
    for (i = 0; i < 4; i++) {
      if ((2 << i) & q->slotBits) {
        break;
      }
    }
    p->childSlot = i;
    rfu_UNI_readySendData(p->childSlot);
    p->mode = 1;
    RfuSession_SetState(p, 19);
    p->stateBegun = TRUE;
  } else {
    RfuSession_SetState(p, 27);
    p->stateBegun = TRUE;
  }
}

// 子機として UNI 通信を始める準備, 自分の番号を探してバッファとコールバックを仕掛ける
void RfuSession_StartUniChild(RfuSession* p) {
  RfuSessionUnk134* q = &p->unk_134;
  s32 i;

  ClearBGTilemapBuffer(0);
  for (i = 0; i < 4; i++) {
    if (q->slotIDs[i] == gRfuLinkStatus->my.id) {
      break;
    }
  }
  p->playerIdx = i;
  FUN_0823a76c(&p->recvRing);
  ClearMemory(&p->uniSend, sizeof(p->uniSend));
  ClearMemory(&p->uniRecv, sizeof(p->uniRecv));
  FUN_0804ce0c(p);
  for (i = 0; i < 4; i++) {
    p->lastRecvSeq[i] = 0;
    p->dupRecvCount[i] = 0;
    p->lostRecvCount[i] = 0;
    p->gapRecvCount[i] = 0;
  }
  p->unk_37 = q->slotBits;
  p->uniSend.seq = 0;
  rfu_LMAN_setLMANCallback(RfuSession_LmanCallbackUniChild);
  rfu_LMAN_setMSCCallback(FUN_0804d36c);
  rfu_setRecvBuffer(TYPE_UNI, p->ownSlot, &p->uniRecv, sizeof(p->uniRecv));
  if (rfu_UNI_setSendData(1 << p->ownSlot, &p->uniSend, sizeof(p->uniSend)) != 0) {
    RfuSession_SetState(p, 27);
    p->stateBegun = TRUE;
  } else {
    p->mode = 1;
    RfuSession_SetState(p, 20);
    p->stateBegun = TRUE;
  }
}

s32 FUN_0804d680(RfuSession* p) {
  if (p->isParent != 0) {
    rfu_clearAllSlot();
    return 1;
  }
  return 0;
}

// UNI 通信中の状態ハンドラ, 毎フレーム自分のキーを送る値に入れ, 受け取ったキーを配るよう keysReceived を立てる
s32 RfuSession_StateUniParent(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    ClearBGTilemapBuffer(0);
  }
  RfuSession_SendKeys(p, gRawKeyInput);
  p->keysReceived = TRUE;
}

// UNI 通信中の状態ハンドラ, 毎フレーム自分のキーを送る値に入れ, 受け取ったキーを配るよう keysReceived を立てる
s32 RfuSession_StateUniChild(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    ClearBGTilemapBuffer(0);
  }
  RfuSession_SendKeys(p, gRawKeyInput);
  p->keysReceived = TRUE;
}

// NI 通信中の親機側のリンクマネージャーのコールバック, 何もしないケースの値は分岐木の形から推定したもの
void RfuSession_LmanCallbackNIParent(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->recoveringSlots &= ~lman.param[0];
      p->slotLost = 1;
      RfuSession_RemoveSlots(p, lman.param[0]);
      if (p->unk_134.playerCount == 1) {
        rfu_LMAN_stopManager(1);
        RfuSession_SetState(p, 29);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER: {
      RfuSession_RemoveSlots(p, lman.param[0]);
      if (p->unk_134.playerCount == 1) {
        rfu_LMAN_stopManager(1);
        RfuSession_SetState(p, 29);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_Reset(p);
      break;
    }
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET: {
      RfuSession_SetState(p, 30);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
    case LMAN_MSG_END_WAIT_CHILD_NAME:
    case LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE:
    case LMAN_MSG_MANAGER_STOPPED: {
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      gRfuSendBusy = 0;
      break;
    }
  }
}

void FUN_0804d85c(u16 reqCommandId) { rfu_REQ_recvData(); }

// 通信を始める準備, バッファとコールバックを仕掛けて state 23 に移る
void RfuSession_StartNIDataParent(RfuSession* p) {
  RfuSessionUnk134* q = &p->unk_134;
  s32 i;

  ClearBGTilemapBuffer(0);
  FUN_0823a76c(&p->recvRing);
  ClearMemory(p->unk_b8, sizeof(p->unk_b8));
  ClearMemory(p->unk_c4, sizeof(p->unk_c4));
  rfu_clearSlot(TYPE_NI_RECV, p->childSlot);
  rfu_LMAN_setLMANCallback(RfuSession_LmanCallbackNIParent);
  rfu_LMAN_setMSCCallback(FUN_0804d85c);
  for (i = 0; i < 4; i++) {
    if (q->slotBits & (2 << i)) {
      rfu_setRecvBuffer(TYPE_NI, i, p->unk_c4, sizeof(p->unk_c4));
    }
  }
  p->mode = 2;
  RfuSession_SetState(p, 23);
  p->stateBegun = TRUE;
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
  Sound_FadeOutBGM(4);
}

// 親機から子機へ unk_b8 の NI 送信を始める, 送信を始めたかフラグが無ければ 1, 送信中や失敗なら 0
s32 RfuSession_ParentNISend(RfuSession* p) {
  if ((p->unk_22 & FLAG_1) || gRfuLinkStatus->linkLossSlot_flag != 0) {
    return 0;
  }
  if (p->unk_22 & FLAG_0) {
    rfu_clearSlot(TYPE_NI_SEND, p->childSlot);
    if (rfu_NI_setSendData(1 << p->childSlot, 15, p->unk_b8, sizeof(p->unk_b8)) == 0) {
      s32 i;

      for (i = 0; i < 4; i++) {
        if ((gRfuLinkStatus->connectSlot_flag >> i) & 1) {
          break;
        }
      }
      p->childSlot = i;
      p->unk_22 = (p->unk_22 & ~FLAG_0) | FLAG_1;
    } else {
      FUN_0804e584(2);
      return 0;
    }
  }
  return 1;
}

// 親機側の NI 送信の結果を見て, 終わったら onSent / unk_380 を呼び, 届かなかった子機を disconnectSlots に溜める
void RfuSession_ParentCheckNISent(RfuSession* p) {
  u8 failed = 0;

  if (p->unk_22 & FLAG_1) {
    u16 state = gRfuSlotStatusNI[p->childSlot]->send.state;

    if (state == SLOT_STATE_SEND_SUCCESS) {
      if (p->onSent != NULL) {
        p->onSent(p->unk_b8);
      }
      failed = gRfuSlotStatusNI[p->childSlot]->send.bmSlot_org ^ gRfuSlotStatusNI[p->childSlot]->send.bmSlot;
      rfu_clearSlot(TYPE_NI_SEND, p->childSlot);
      p->unk_22 &= ~FLAG_1;
    } else if (state == SLOT_STATE_SEND_FAILED) {
      if (p->unk_380 != NULL) {
        p->unk_380();
      }
      failed = gRfuSlotStatusNI[p->childSlot]->send.bmSlot_org ^ gRfuSlotStatusNI[p->childSlot]->send.bmSlot;
      rfu_clearSlot(TYPE_NI_SEND, p->childSlot);
      p->unk_22 = 0;
    }
    if (failed) {
      p->disconnectSlots |= failed;
    }
  }
}

// state 23 に切り替える状態ハンドラ
s32 FUN_0804da50(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  RfuSession_SetState(p, 23);
  p->stateBegun = TRUE;
  return 0;
}

// NI 受信の結果を見て, 成功なら onReceive に渡してスロットを空け, 失敗なら onRecvFailed を呼ぶ
s32 RfuSession_StateRecvNI(RfuSession* p) {
  u16 state;

  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  state = gRfuSlotStatusNI[p->childSlot]->recv.state;
  if (state == SLOT_STATE_RECV_SUCCESS) {
    if (p->onReceive != NULL) {
      p->onReceive(p->unk_c4);
    }
    rfu_clearSlot(TYPE_NI_RECV, p->childSlot);
  } else if (state == SLOT_STATE_RECV_FAILED || state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN) {
    if (p->onRecvFailed != NULL) {
      p->onRecvFailed();
    }
  }
  return 0;
}

s32 FUN_0804dae4(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  return 0;
}

// NI 通信中のリンクマネージャーのコールバック, 何もしないケースの値は分岐木の形から推定したもの (0x30 未満の 2 件は 0x22/0x23 とは限らない)
void RfuSession_LmanCallbackNIChild(u8 msg, u8 paramCount) {
  RfuSession* p = gRfuSession;

  if (p == NULL) {
    return;
  }
  switch (msg) {
    case LMAN_MSG_RECV_DATA_REQ_COMPLETED: {
      rfu_LMAN_REQ_sendData(1);
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY: {
      p->recoveringSlots |= lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED: {
      p->recoveringSlots &= ~lman.param[0];
      break;
    }
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED: {
      p->recoveringSlots &= ~lman.param[0];
      RfuSession_SetState(p, 29);
      p->stateBegun = TRUE;
      break;
    }
    case LMAN_MSG_RFU_POWER_DOWN: {
      RfuSession_Reset(p);
      break;
    }
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
    case LMAN_MSG_CONNECT_PARENT_FAILED:
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER:
    case LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
    case LMAN_MSG_CHANGE_AGB_CLOCK_MASTER: {
      break;
    }
    case LMAN_MSG_REQ_API_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      break;
    }
    case LMAN_MSG_RFU_FATAL_ERROR: {
      if (p->state != 28) {
        RfuSession_SetState(p, 28);
        p->stateBegun = TRUE;
      }
      break;
    }
  }
}

void FUN_0804dbc8(u16 reqCommandId) {
  if (gRfuSession != NULL) {
    rfu_REQ_recvData();
  }
}

// 子機として通信を始める準備, 自分の番号を探し, バッファとコールバックを仕掛けて state 24 に移る
void RfuSession_StartNIDataChild(RfuSession* p) {
  s32 i;

  ClearBGTilemapBuffer(0);
  for (i = 0; i < 4; i++) {
    if (p->unk_134.slotIDs[i] == gRfuLinkStatus->my.id) {
      break;
    }
  }
  p->playerIdx = i;
  FUN_0823a76c(&p->recvRing);
  ClearMemory(p->unk_b8, sizeof(p->unk_b8));
  ClearMemory(p->unk_c4, sizeof(p->unk_c4));
  rfu_LMAN_setLMANCallback(RfuSession_LmanCallbackNIChild);
  rfu_LMAN_setMSCCallback(FUN_0804dbc8);
  rfu_setRecvBuffer(TYPE_NI, p->ownSlot, p->unk_c4, sizeof(p->unk_c4));
  p->mode = 2;
  RfuSession_SetState(p, 24);
  p->stateBegun = TRUE;
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

// 子機側, NI 受信の結果を onReceive / onRecvFailed に渡し, 送信の準備ができていれば親機へ unk_b8 の NI 送信を始める
s32 RfuSession_ChildNIExchange(RfuSession* p) {
  u16 state;

  if ((p->unk_22 & FLAG_1) || gRfuLinkStatus->linkLossSlot_flag != 0) {
    return 0;
  }
  state = gRfuSlotStatusNI[p->ownSlot]->recv.state;
  if (state == SLOT_STATE_RECV_SUCCESS) {
    if (p->onReceive != NULL) {
      p->onReceive(p->unk_c4);
    }
    rfu_clearSlot(TYPE_NI_RECV, p->ownSlot);
  } else if (state == SLOT_STATE_RECV_FAILED || state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN) {
    if (p->onRecvFailed != NULL) {
      p->onRecvFailed();
    }
  }
  if (p->unk_22 & FLAG_0) {
    rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
    if (rfu_NI_setSendData(1 << p->ownSlot, 14, p->unk_b8, sizeof(p->unk_b8)) == 0) {
      s32 i;

      for (i = 0; i < 4; i++) {
        if ((gRfuLinkStatus->connectSlot_flag >> i) & 1) {
          break;
        }
      }
      p->ownSlot = i;
      p->unk_22 = (p->unk_22 & ~FLAG_0) | FLAG_1;
    } else {
      FUN_0804e584(2);
      return 0;
    }
  }
  return 1;
}

// NI 送信の結果を見て, 成功なら onSent を呼んでスロットを空け, 失敗なら届かなかった子機を disconnectSlots に溜める
void RfuSession_ChildCheckNISent(RfuSession* p) {
  u8 failed = 0;

  if (p->unk_22 & FLAG_1) {
    u16 state = gRfuSlotStatusNI[p->ownSlot]->send.state;

    if (state == SLOT_STATE_SEND_SUCCESS) {
      if (p->onSent != NULL) {
        p->onSent(p->unk_b8);
      }
      rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
      p->unk_22 &= ~FLAG_1;
    } else if (state == SLOT_STATE_SEND_FAILED) {
      if (p->unk_380 != NULL) {
        p->unk_380();
      }
      failed = gRfuSlotStatusNI[p->ownSlot]->send.bmSlot_org ^ gRfuSlotStatusNI[p->ownSlot]->send.bmSlot;
      rfu_clearSlot(TYPE_NI_SEND, p->ownSlot);
      p->unk_22 = 0;
    }
    if (failed) {
      p->disconnectSlots |= failed;
    }
  }
}

// state 23 に切り替える状態ハンドラ, FUN_0804da50 と同じ内容
s32 FUN_0804de18(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  RfuSession_SetState(p, 23);
  p->stateBegun = TRUE;
  return 0;
}

s32 FUN_0804de40(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  return 0;
}

s32 FUN_0804de58(RfuSession* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  return 0;
}

// 通信の毎フレーム処理, リンクマネージャーと送受信を回してから今の state のハンドラを呼ぶ
s32 RfuSession_TickNIParent(RfuSession* p) {
  if (p->unk_18) {
    while (gRfuSendBusy == 1) {
    }
    rfu_LMAN_manager_entity(0);
    if (p->disconnectSlots) {
      rfu_REQ_disconnect(p->disconnectSlots);
      rfu_waitREQComplete();
      p->disconnectSlots = 0;
    }
    if (gRfuLinkStatus->parent_child == MODE_PARENT) {
      gRfuSendBusy = 1;
      rfu_REQ_sendData(1);
    }
  }
  RfuSession_ParentSendMemberList(p);
  RfuSession_ParentCheckListSent(p);
  sRfuSessionStates[p->state](p);
}

// clang-format off
s32 (*const sRfuSessionStates[33])(RfuSession*) = {
    FUN_0804c3cc,
    FUN_0804c3e4,
    FUN_0804c438,
    RfuSession_StateReinitRFU,
    FUN_0804c5c0,
    RfuSession_StateConnectAsParent,
    FUN_0804c650,
    RfuSession_StateParentWait,
    RfuSession_StateSelectParent,
    FUN_0804c888,
    FUN_0804c8bc,
    RfuSession_StateCancel,
    FUN_0804c940,
    FUN_0804c978,
    RfuSession_StateChildWait,
    FUN_0804cb6c,
    FUN_0804cb84,
    FUN_0804cb9c,
    FUN_0804cbb4,
    RfuSession_StateUniParent,
    RfuSession_StateUniChild,
    FUN_0804da50,
    FUN_0804de18,
    RfuSession_StateRecvNI,
    FUN_0804de40,
    FUN_0804dae4,
    FUN_0804de58,
    FUN_0804cbcc,
    FUN_0804cbfc,
    FUN_0804cc38,
    FUN_0804cc7c,
    FUN_0804cc98,
    FUN_0804ccbc,
};  // 0x085AB5E0
// clang-format on

// 子機の接続までの毎フレーム処理, リンクマネージャーを回してから今の state のハンドラを呼ぶ
s32 RfuSession_TickNIChild(RfuSession* p) {
  if (p->unk_18) {
    p->foundParentBits = 0;
    rfu_LMAN_manager_entity(0);
  }
  sRfuSessionStates[p->state](p);
}

// 親機側の UNI 通信中の毎フレーム処理, uniPacket を送り, state のハンドラがキーを受け取れたら gLinkKeyInput に配る
s32 RfuSession_TickUniParent(RfuSession* p) {
  p->keysReceived = FALSE;
  while (gRfuSendBusy == 1) {
  }
  rfu_LMAN_manager_entity(0);
  if (p->slotLost && p->unk_e8) {
    p->unk_e8 = 0;
    p->unk_e7 = 1;
    p->unk_e6 = 1;
    p->slotLost = 0;
  }
  FUN_0804bb70(p);
  FUN_0804cf4c(p);
  if (gRfuLinkStatus->linkLossSlot_flag == 0 && p->unk_36) {
    gRfuSendBusy = 1;
    if (!p->unk_e8) {
      rfu_UNI_changeAndReadySendData(p->childSlot, &p->uniPacket, sizeof(p->uniPacket));
      rfu_LMAN_REQ_sendData(1);
    } else {
      rfu_REQ_PARENT_resumeRetransmitAndChange();
    }
  }
  RfuSession_PopRecvPacket(p);
  sRfuSessionStates[p->state](p);
  if (p->keysReceived) {
    s32 i;

    gUseLinkInput = TRUE;
    for (i = 0; i < 5; i++) {
      if (p->linkKeys[i] & 0x2000) {
        gLinkKeyInput[i] = p->linkKeys[i] & 0xFFF;
      } else {
        gLinkKeyInput[i] |= 0xFFFF;
      }
    }
  } else {
    gUseLinkInput = FALSE;
  }
}

// 通信中の毎フレーム処理, state のハンドラがキーを受け取れたら受け取ったキーを gLinkKeyInput に配る
s32 RfuSession_TickUniChild(RfuSession* p) {
  p->keysReceived = FALSE;
  rfu_LMAN_manager_entity(0);
  rfu_getMasterSlave();
  FUN_0804bb70(p);
  RfuSession_PopRecvPacket(p);
  sRfuSessionStates[p->state](p);
  if (p->keysReceived) {
    s32 i;

    gUseLinkInput = TRUE;
    for (i = 0; i < 5; i++) {
      if (p->linkKeys[i] & 0x2000) {
        gLinkKeyInput[i] = p->linkKeys[i] & 0xFFF;
      } else {
        gLinkKeyInput[i] |= 0xFFFF;
      }
    }
  } else {
    gUseLinkInput = FALSE;
  }
}

void FUN_0804e0bc(RfuSession* p) {
  while (gRfuSendBusy == 1) {
  }

  rfu_LMAN_manager_entity(0);
  if (p->disconnectSlots != 0) {
    rfu_REQ_disconnect(p->disconnectSlots);
    rfu_waitREQComplete();
    p->disconnectSlots = 0;
  }

  if (gRfuLinkStatus->parent_child == 1) {
    gRfuSendBusy = 1;
    rfu_LMAN_REQ_sendData(1);
  }

  RfuSession_ParentNISend(p);
  RfuSession_ParentCheckNISent(p);
  sRfuSessionStates[p->state](p);
}

// RFU の状態を進めてから state 番の状態ハンドラを呼ぶ
s32 FUN_0804e128(RfuSession* p) {
  p->keysReceived = FALSE;
  rfu_LMAN_manager_entity(0);
  rfu_getMasterSlave();
  RfuSession_ChildNIExchange(p);
  RfuSession_ChildCheckNISent(p);
  return sRfuSessionStates[p->state](p);
}

// 通信の毎フレーム処理を mode と isParent で振り分け, 終了を頼まれていれば自分を消す
s32 RfuSession_Run(RfuSession* p) {
  Taiyo_Disable();
  u32_030000e0 = p->errorKind;
  switch (p->mode) {
    case 0: {
      if (p->isParent) {
        RfuSession_TickNIParent(p);
      } else {
        RfuSession_TickNIChild(p);
      }
      break;
    }
    case 1: {
      if (p->isParent) {
        RfuSession_TickUniParent(p);
      } else {
        RfuSession_TickUniChild(p);
      }
      break;
    }
    case 2: {
      if (p->isParent) {
        FUN_0804e0bc(p);
      } else {
        FUN_0804e128(p);
      }
      break;
    }
  }
  if (p->unk_3d) {
    p->unk_3d = 0;
    rfu_LMAN_stopManager(1);
    RfuSession_SetState(p, 0);
    p->stateBegun = TRUE;
  }
  if (p->unk_1d) {
    gRtcReadInhibit = 0;
    gRfuSession = NULL;
    RemoveEntity((Entity*)p);
    Free(p);
    Taiyo_Enable();
  } else {
    if (p->state >= 9 && p->state <= 26) {
      gSoftResetInhibit = TRUE;
    }
    p->stateTimer++;
    p->unk_48++;
  }
  return 0;
}

// 通信を始める準備をして, スクリプト引数を読む, 失敗すると -1
s32 RfuSession_Init(RfuSession* p) {
  p->errorKind = 0;
  u32_030000e0 = 0;
  if (InitRfuAPI() < 0) {
    return -1;
  }
  p->unk_1d = 0;
  RfuSession_Reset(p);
  RfuSession_SetState(p, 1);
  p->stateBegun = TRUE;
  p->scriptID = VM_GetNamedArgValue('p', 0);
  if (!VM_SeekToNamedArg('a')) {
    return -1;
  }
  p->strRefPc = VM_GetPC_Proxy();
  if (p->strRefPc != NULL) {
    return 0;
  }
  return -1;
}

RfuSession* RfuSession_Create(void) {
  RfuSession* p;

  if (gRfuSession != NULL) {
    return gRfuSession;
  }

  Taiyo_Disable();
  p = Malloc(sizeof(RfuSession));
  if (p == NULL) {
    return NULL;
  }

  ClearMemory(p, sizeof(RfuSession));
  p->sessionID = (gFrameCounter & 0xFF) | (((Time_GetSecond() + Random()) & 0xFF) << 8);

  if (RfuSession_Init(p) < 0) {
    Free(p);
    return NULL;
  }

  SetEntityRoutine(p, NULL, NULL);
  p->e.kind = ENTITY_UNK_1;
  p->e.unk_16 = 1;
  p->e.id = 0;
  AddEntity((Entity*)p);
  gRtcReadInhibit = 1;
  gRfuSession = p;
  return p;
}

void FUN_0804e36c(void) {
  if (gRfuSession != NULL) {
    RfuSession_Run(gRfuSession);
  }
}

void Cmd_025E(void) {
  if (gRfuSession != NULL) {
    gRfuSession->unk_fb = 1;
  }
}

s32 FUN_0804e3a0(void) {
  if (gRfuSession == NULL) {
    return -1;
  }
  return gRfuSession->playerIdx;
}

// 子機として接続しているときだけ ownSlot を返す
s32 FUN_0804e3c0(void) {
  RfuSession* p = gRfuSession;

  if (p == NULL || gRfuLinkStatus->parent_child != 0) {
    return 0;
  }

  return p->ownSlot;
}

// 通信相手とつながっているか
s32 FUN_0804e3ec(void) {
  if (gRfuSession == NULL) {
    return 0;
  }

  if (gRfuSession->isParent != 0) {
    if (gRfuSession->state <= 4) {
      return 0;
    }
    if (gRfuLinkStatus->parent_child == MODE_NEUTRAL) {
      return 0;
    }
    return 1;
  }

  if (gRfuLinkStatus->parent_child == MODE_CHILD) {
    return 1;
  }
  return 0;
}

u8* FUN_0804e438(void) {
  if (gRfuSession == NULL) {
    return NULL;
  }
  return (u8*)&gRfuSession->unk_134;
}

s32 FUN_0804e458(void) {
  if (gRfuSession == NULL) {
    return 0;
  }
  return gRfuSession->isParent;
}

s32 FUN_0804e474(void) {
  if (gRfuSession == NULL) {
    return 0;
  }
  return gRfuSession->acceptedSlots;
}

s32 RfuSession_GetState(void) {
  if (gRfuSession == NULL) {
    return 0;
  }
  return gRfuSession->state;
}

void FUN_0804e4ac(void) {
  if (gRfuSession != NULL) {
    gRfuSession->unk_1b = 1;
  }
}

void FUN_0804e4c4(void) {
  if (gRfuSession != NULL) {
    gRfuSession->unk_1c = 1;
  }
}

void RfuSession_SetCallbacks(void (*onSent)(void*), void (*onReceive)(void*), void (*arg2)(void), void (*onRecvFailed)(void)) {
  RfuSession* p = gRfuSession;

  if (p != NULL) {
    p->onSent = onSent;
    p->onReceive = onReceive;
    p->unk_380 = arg2;
    p->onRecvFailed = onRecvFailed;
  }
}

// 送信バッファに 12バイト積む, 送信中なら -1
s32 FUN_0804e514(u8* src) {
  RfuSession* p = gRfuSession;
  u32* dst;

  if (p == NULL) {
    return -1;
  }
  if (p->unk_22 & FLAG_1) {
    return -1;
  }

  dst = p->unk_b8;
  src[0]++;
  CpuCopy32(src, dst, 12);
  p->unk_22 |= FLAG_0;
  return 0;
}

s32 FUN_0804e55c(void* dest) {
  if (gRfuSession == NULL) {
    return -1;
  }
  CpuCopy32(gRfuSession->unk_c4, dest, 12);
  return 0;
}

void FUN_0804e584(s32 val) {
  if (gRfuSession != NULL) {
    gRfuSession->errorKind = val;
  }
}

s32 FUN_0804e59c(void) {
  if (gRfuSession == NULL) {
    return u32_030000e0;
  }
  return gRfuSession->errorKind;
}

// state 31 に切り替える
void FUN_0804e5bc(void) {
  RfuSession* p = gRfuSession;

  if (p != NULL) {
    p->unk_3f = 1;
    RfuSession_SetState(p, 31);
    p->stateBegun = TRUE;
  }
}

void FUN_0804e5e8(void) {
  if (gRfuSession != NULL) {
    gRfuSession->unk_3d = 1;
  }
}

void FUN_0804e604(void) {
  if (gRfuSession != NULL) {
    gRfuSession->unk_1d = 1;
  }
}

u8* FUN_0804e61c(void) {
  if (gRfuSession == NULL) {
    return NULL;
  }
  return gRfuSession->gameName;
}

s32 FUN_0804e638(void) {
  if (gRfuSession == NULL) {
    return 0;
  }
  return gRfuSession->sessionID;
}

u16* Crossover_GetMappingBuf(void) { return gCrossoverMappingBuf; }

u16 Crossover_GetMappingChar(u8 n) { return Crossover_GetMappingBuf()[n]; }

// 対応表から id の番号を引く, 見つからないと止まらない
s32 Crossover_FindMappingIdx(u16 id) {
  u16* buf = Crossover_GetMappingBuf();
  u8 i = 0;

  for (;;) {
    if (buf[i] == id) {
      return i;
    }
    i++;
  }
}

// 1バイトずつ変換表を引いて, 0x7F を超えるものは2バイトに展開しながら dst へ詰める
void Crossover_DecodeText(u8* src, u8* dst, s32 count) {
  s32 i;

  for (i = 0; i < count; i++) {
    u16 c = Crossover_GetMappingChar(src[i]);

    if (c <= 0x7F) {
      *dst = c;
      dst++;
    } else {
      dst[0] = c;
      dst[1] = c >> 8;
      dst += 2;
    }
  }

  *dst = 0;
}

// 文字列を1文字ずつ対応表の番号に直して dst へ詰め, 残りを 0 で埋める
void Crossover_EncodeText(u8* src, u8* dst, s32 count) {
  s32 i = 0;

  while (i < count && *src != 0) {
    u16 c;

    if ((s8)*src >= 0) {
      c = *src;
      src++;
    } else {
      c = src[0] | (src[1] << 8);
      src += 2;
    }
    dst[i] = Crossover_FindMappingIdx(c);
    i++;
  }
  for (; i < count; i++) {
    dst[i] = 0;
  }
  dst[count] = 0;
}

// 0xC015, '.s' の文字列5本を1文字ずつ対応表に並べる (256 文字まで), 0 番は 0 に戻す
void Cmd_LoadCrossoverMappingBuf(void) {
  u8* pc = VM_SeekToNamedArg('s') ? VM_GetPC() : NULL;

  if (pc != NULL) {
    u16* buf = Crossover_GetMappingBuf();
    s32 n = 0;
    s32 i;

    for (i = 0; i < 5; i++) {
      u8* str = GetStringByID(VM_ParseStringRef(pc) + i);

      while (*str != 0 && n != 256) {
        if ((s8)*str >= 0) {
          buf[n] = *str;
          str++;
        } else {
          buf[n] = (str[1] << 8) | str[0];
          str += 2;
        }
        n++;
      }
    }
    buf[0] = 0;
  }
}
