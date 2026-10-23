#include "link.h"

#include "global.h"
#include "interrupts.h"

// 通信プロトコル層が扱うフレーム, .checksum 以降の .len バイトがそのまま回線に流れる
typedef struct SioFrame {
  struct SioFrame* prev;  // 0x00
  struct SioFrame* next;  // 0x04
  u8 id;                  // 0x08, データフレームは .seq と同じ, 応答フレームは送り返す側の連番
  u8 len;                 // 0x09, .checksum から数えた回線上のバイト数 (payloadLen + 4)
  u16 unk_0a;             // 0x0A, 常に 0x01E0
  u8 checksum;            // 0x0C, .kind から payload の末尾までの XOR
  u8 kind;                // 0x0D, 1 = データ, 2 = 応答
  u8 seq;                 // 0x0E
  u8 payloadLen;          // 0x0F
  u8 payload[16];         // 0x10
} SioFrame;
static_assert(sizeof(SioFrame) == 32);

// 2個のセンチネルだけを持つ双方向リスト, 実体は head と tail の間に繋がる
typedef struct {
  SioFrame head;  // 0x00, .prev は常に NULL
  SioFrame tail;  // 0x20, .next は常に NULL
} SioFrameList;
static_assert(sizeof(SioFrameList) == 64);

typedef struct {
  SioFrameList sendQueue;  // 0x000, 送信待ち
  SioFrameList sentQueue;  // 0x040, 送信済みで応答待ち
  SioFrameList recvQueue;  // 0x080, 受信済みで読み出し待ち
  SioFrameList freeList;   // 0x0C0, 空きフレーム, 受信もここから借りる
  u32 nextSeq;             // 0x100, (n + 1) & 0xFF で払い出す連番
  SioFrame frames[16];     // 0x104
  u8 unk_304[4];           // 0x304, 参照なし
  s32 error;               // 0x308
} SioPacketCtx;
static_assert(sizeof(SioPacketCtx) == 780);

EWRAM_DATA SioPacketCtx gSioPacketCtxBuf = {};            // 0x0203F800, gSioPacketCtx の置き場所
EWRAM_DATA u8 u8_0203fb0c[0x0203FC00 - 0x0203FB0C] = {};  // 0x0203FB0C, 参照なし

IWRAM_DATA s32 gSioRecvWriteIdx = 0;            // 0x03000788
IWRAM_DATA s32 gSioRecvReadIdx = 0;             // 0x0300078C
IWRAM_DATA s32 gSioRecvCount = 0;               // 0x03000790
IWRAM_DATA s32 gSioSendWriteIdx = 0;            // 0x03000794
IWRAM_DATA s32 gSioSendReadIdx = 0;             // 0x03000798
IWRAM_DATA s32 gSioSendCount = 0;               // 0x0300079C
IWRAM_DATA u8 gSioRecvBuf[64] = {};             // 0x030007A0
IWRAM_DATA u8 gSioSendBuf[64] = {};             // 0x030007E0
IWRAM_DATA SioPacketCtx* gSioPacketCtx = NULL;  // 0x03000820
IWRAM_DATA u16 gSioSendNext = 0;                // 0x03000824, ゲームが次に送るデータ, bit14 が立っていれば空
IWRAM_DATA u16 gSioSendCur = 0;                 // 0x03000826, 今回 REG_SIOMLT_SEND に出す値, 割り込みが gSioSendNext から引き取る
IWRAM_DATA s32 gSioRecvDataFace = 0;            // 0x03000828, gSioRecvData を読む面 (0 or 1), 割り込みは 1 - これ の面に書いてから反転する
IWRAM_DATA bool32 gSioRecvDataNew = FALSE;      // 0x0300082C, gSioRecvData に未読データあり, Sio_GetRecvData が読み出すと 0 に戻る
IWRAM_DATA s32 gSioRecvRawFace = 0;             // 0x03000830, gSioRecvRaw を読む面 (0 or 1), 同じく割り込みが反転する

COMMON_DATA s32 gSioTimerIntrCount = 0;              // 0x030046C0, 親のタイマー3割り込み回数
COMMON_DATA u32 u32_030046c4 = 0;                    // 0x030046C4
COMMON_DATA s32 gSioSerialIntrCount = 0;             // 0x030046C8, 子のシリアル割り込み回数
COMMON_DATA s32 gSioMultiId = 0;                     // 0x030046CC, 0 = 親, 1 = 子, -1 = 未確定
COMMON_DATA u16 gSioChildRecv = 0;                   // 0x030046D0, 子が受け取った親のデータ (SIOMULTI0)
COMMON_DATA s32 gSioStatus = 0;                      // 0x030046D4, 負ならエラー
COMMON_DATA u16 ALIGNED(16) gSioRecvRingCount = 0;   // 0x030046E0, gSioRecvRing に溜まっている件数 (0..4)
COMMON_DATA u16 ALIGNED(16) gSioRecvRaw[2][4] = {};  // 0x030046F0, 割り込みが SIOMULTI0-3 をそのまま書くダブルバッファ, 読む面は gSioRecvRawFace
COMMON_DATA u16 gSioRecvRing[4][4] = {};             // 0x03004700, ゲームが読み遅れたときに溜めるリングバッファ, 読み位置は gSioRecvRingRead, 件数は gSioRecvRingCount
COMMON_DATA u16 gSioRecvData[2][4] = {};             // 0x03004720, ゲームに渡す1回分の受信データ, 読む面は gSioRecvDataFace
COMMON_DATA u16 gSioRecvRingRead = 0;                // 0x03004730, gSioRecvRing の読み位置 (0..3)

static void Sio_ParentTimerIntr(void);

static void DisableInterrupts(void) { REG_IME = 0; }

static void EnableInterrupts(void) { REG_IME = 1; }

// タイマー3 を約 100Hz の割り込みで動かし、そのハンドラに Sio_ParentTimerIntr を登録する
void Sio_StartParentTimer(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_L = 0xF5D8;
  REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_64CLK;
  gIntrTable[2] = Sio_ParentTimerIntr;
  ie |= INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_TIMER3;
}

// 親用のタイマー3割り込みを止め、ハンドラを IntrDummy に戻す
void Sio_StopParentTimer(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_H = 0;
  REG_TM3CNT_L = 0;
  gIntrTable[2] = IntrDummy;
  ie &= ~INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_TIMER3;
}

// 親のタイマー3割り込み: 子のデータを受信バッファに積み、送信バッファから1バイト送る
static void Sio_ParentTimerIntr(void) {
  s32 recv, m2, m3;
  s32 send;

  recv = REG_SIOMULTI1;
  m2 = REG_SIOMULTI2;
  m3 = REG_SIOMULTI3;
  send = 0;
  gSioParentRecv = recv;
  if ((REG_SIOCNT & (SIO_ERROR | SIO_MULTI_BUSY)) || m2 != 0xFFFF || m3 != 0xFFFF) {
    if (m2 != 0xFFFF || m3 != 0xFFFF) {
      gSioStatus = -7;
    } else {
      gSioStatus = -8;
    }
  } else {
    if ((recv & 0x2000) && recv != 0xFFFF) {
      gSioRecvBuf[gSioRecvWriteIdx] = recv;
      gSioRecvWriteIdx = (gSioRecvWriteIdx + 1) & 0x3F;
      gSioRecvCount++;
    }
    if (gSioRecvCount > 62) {
      send |= 0x4000;
    }
    if (gSioSendCount > 0 && !(recv & 0x4000)) {
      send |= gSioSendBuf[gSioSendReadIdx];
      gSioSendReadIdx = (gSioSendReadIdx + 1) & 0x3F;
      gSioSendCount--;
      send |= 0x2000;
    }
    if (send == 0xFFFF) {
      send = 0x8000;
    }
    REG_SIOMLT_SEND = send;
  }
  REG_SIOCNT |= SIO_START;
  REG_TM3CNT_L = 0xF5D8;
  gSioTimerIntrCount++;
}

void Sio_ChildSerialIntr(void);

// 子用のシリアル割り込みを有効にし、ハンドラに Sio_ChildSerialIntr を登録する
void Sio_StartChildIntr(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  gIntrTable[1] = Sio_ChildSerialIntr;
  REG_SIOCNT |= SIO_INTR_ENABLE;
  ie |= INTR_FLAG_SERIAL;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
}

// 子用のシリアル割り込みを止め、ハンドラを IntrDummy に戻す
void Sio_StopChildIntr(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  gIntrTable[1] = IntrDummy;
  REG_SIOCNT &= ~SIO_INTR_ENABLE;
  ie &= ~INTR_FLAG_SERIAL;
  REG_IE = ie;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
}

// 子のシリアル割り込み: 親のデータを受信バッファに積み、送信バッファから1バイト送る
void Sio_ChildSerialIntr(void) {
  s32 recv, m2, m3;
  s32 send;

  recv = REG_SIOMULTI0;
  m2 = REG_SIOMULTI2;
  m3 = REG_SIOMULTI3;
  send = 0;
  gSioChildRecv = recv;
  if ((REG_SIOCNT & SIO_ERROR) || m2 != 0xFFFF || m3 != 0xFFFF) {
    if (m2 != 0xFFFF || m3 != 0xFFFF) {
      gSioStatus = -7;
    } else {
      gSioStatus = -8;
    }
  } else {
    if ((recv & 0x2000) && recv != 0xFFFF) {
      gSioRecvBuf[gSioRecvWriteIdx] = recv;
      gSioRecvWriteIdx = (gSioRecvWriteIdx + 1) & 0x3F;
      gSioRecvCount++;
    }
    if (gSioRecvCount > 62) {
      send |= 0x4000;
    }
    if (gSioSendCount > 0 && !(recv & 0x4000)) {
      send |= gSioSendBuf[gSioSendReadIdx];
      gSioSendReadIdx = (gSioSendReadIdx + 1) & 0x3F;
      gSioSendCount--;
      send |= 0x2000;
    }
    if (send == 0xFFFF) {
      send = 0x8000;
    }
    REG_SIOMLT_SEND = send;
    if (gSioMultiId == -1) {
      gSioMultiId = (REG_SIOCNT >> 4) & 3;
      if (gSioMultiId != 1) {
        gSioStatus = -5;
      }
    }
  }
  gSioSerialIntrCount++;
}

// SIO を 115200bps のマルチプレイモードに初期化する
void Sio_Init(void) {
  gSioStatus = 0;
  gSioMultiId = -1;
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  REG_IME = 1;
  REG_RCNT = 0;
  REG_SIOCNT = SIO_MULTI_MODE;
  REG_SIOCNT |= SIO_115200_BPS;
}

NON_MATCH void Sio_CheckConnection(void) {
#ifdef NONMATCHING_C
  u16 cnt, busy;

  REG_SIOMLT_SEND = 0;
  cnt = REG_SIOCNT;
  if (!(cnt & SIO_MULTI_SD)) {
    gSioStatus = -9;
    return;
  }
  busy = cnt & SIO_MULTI_BUSY;
  if (busy) {
    gSioStatus = -4;
    return;
  }
  if (!(cnt & SIO_MULTI_SI)) {
    gSioMultiId = 0;
  } else {
    gSioMultiId = -1;
  }
  REG_SIOMLT_SEND = 0;
#else
  INCFUNC("asm/func/Sio_CheckConnection.inc");
#endif
}

// 通信状態をリセットして SIO を初期化し直す
void Sio_Reset(void) {
  gSioStatus = -1;
  Sio_Init();
}

void FUN_08237eb0(void) {}

s32 Sio_Start(void) {
  s32 i;

  gSioRecvWriteIdx = gSioRecvReadIdx = 0;
  gSioSendWriteIdx = gSioSendReadIdx = 0;
  gSioRecvCount = 0;
  gSioSendCount = 0;
  for (i = 0; i < 64; i++) {
    gSioRecvBuf[i] = 0;
    gSioSendBuf[i] = 0;
  }
  gSioStatus = 0;
  gSioMultiId = -1;
  gSioTimerIntrCount = gSioSerialIntrCount = 0;
  Sio_CheckConnection();
  if (gSioStatus < 0) {
    return gSioStatus;
  }
  if (gSioMultiId == 0) {
    Sio_StartParentTimer();
    return 0;
  }
  Sio_StartChildIntr();
  return 1;
}

// 通信を止める (親ならタイマー3、子ならシリアル割り込みを止める)
s32 Sio_Stop(void) {
  if (gSioMultiId == 0) {
    Sio_StopParentTimer();
  } else {
    Sio_StopChildIntr();
  }
  return 0;
}

NAKED s32 FUN_08237f74(unknown* p) { INCFUNC("asm/func/FUN_08237f74.inc"); }

NAKED s32 FUN_08238014(unknown* p, s32 param_2) { INCFUNC("asm/func/FUN_08238014.inc"); }

// 通信エラーが出ていればそのエラーコード, 出ていなければ 0
s32 Sio_GetError(void) {
  if (gSioStatus < 0) {
    return gSioStatus;
  }
  return 0;
}

// 親と子の双方からデータが来ているか, どちらかが 0xFFFF (データなし) なら OR も 0xFFFF になる
bool32 Sio_HasBothData(void) {
  if ((gSioChildRecv | gSioParentRecv) != 0xFFFF) {
    return TRUE;
  }
  return FALSE;
}

// 子が親からデータを受け取っているか (0xFFFF はデータなし)
bool32 Sio_HasParentData(void) {
  if (gSioChildRecv != 0xFFFF) {
    return TRUE;
  }
  return FALSE;
}

// 親が子からデータを受け取っているか (0xFFFF はデータなし)
bool32 Sio_HasChildData(void) {
  if (gSioParentRecv != 0xFFFF) {
    return TRUE;
  }
  return FALSE;
}

s32 Sio_GetTimerIntrCount(void) { return gSioTimerIntrCount; }

s32 Sio_GetSerialIntrCount(void) { return gSioSerialIntrCount; }

s32 Sio_GetMultiId(void) { return gSioMultiId; }

void Sio_AllocPacketCtx(void) { gSioPacketCtx = &gSioPacketCtxBuf; }

// 空のリストにする
void SioFrameList_Init(SioFrameList* list) {
  list->head.prev = NULL;
  list->tail.next = NULL;
  list->head.next = &list->tail;
  list->tail.prev = &list->head;
}

// 繋がっているリストから取り外す
void SioFrame_Unlink(SioFrame* frame) {
  SioFrame* prev = frame->prev;
  SioFrame* next = frame->next;

  if (prev != NULL) {
    prev->next = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  frame->prev = NULL;
  frame->next = NULL;
}

// 元のリストから外してリストの末尾に繋ぐ
void SioFrameList_PushBack(SioFrameList* list, SioFrame* frame) {
  SioFrame* tail;
  SioFrame* last;

  SioFrame_Unlink(frame);
  tail = &list->tail;
  last = list->tail.prev;
  frame->prev = last;
  frame->next = tail;
  last->next = frame;
  list->tail.prev = frame;
}

// 元のリストから外してリストの先頭に繋ぐ
void SioFrameList_PushFront(SioFrameList* list, SioFrame* frame) {
  SioFrame* first;

  SioFrame_Unlink(frame);
  first = list->head.next;
  list->head.next = frame;
  first->prev = frame;
  frame->prev = &list->head;
  frame->next = first;
}

// 先頭の要素, リストが空なら NULL
SioFrame* SioFrameList_First(SioFrameList* list) {
  SioFrame* frame = list->head.next;

  if (frame->next == NULL) {
    return NULL;
  }
  return frame;
}

// .id が一致する要素を探す, 見つからなければ NULL
SioFrame* SioFrameList_FindById(SioFrameList* list, u32 id) {
  SioFrame* frame = list->head.next;

  while (frame->next != NULL) {
    if (frame->id == id) {
      return frame;
    }
    frame = frame->next;
  }
  return NULL;
}

// 連番を1つ払い出す
u32 Sio_NextSeq(SioPacketCtx* ctx) {
  u32 seq = ctx->nextSeq;

  ctx->nextSeq = (seq + 1) & 0xFF;
  return seq;
}

// .checksum が合っていれば 0, 合っていなければ -1
s32 SioFrame_VerifyChecksum(SioFrame* frame) {
  u8 sum = frame->checksum;
  u8* p = &frame->kind;
  s32 i, len = frame->len;

  for (i = 1; i < len; i++) {
    sum ^= *p;
    p++;
  }
  if (sum != 0) {
    return -1;
  }
  return 0;
}

// .kind から .len - 1 バイト分の XOR を .checksum に入れる
void SioFrame_SetChecksum(SioFrame* frame) {
  u8 sum = 0;
  u8* p = &frame->kind;
  s32 i, len = frame->len;

  for (i = 1; i < len; i++) {
    sum ^= *p;
    p++;
  }
  frame->checksum = sum;
}

// 連番を払い出してデータフレームを組み立てる, 戻り値は .len
// 残差は命令列が完全一致で frame/src/len に割り当つレジスタが入れ替わるのみ, Tier A-C は試済
NON_MATCH s32 Sio_BuildDataFrame(SioPacketCtx* ctx, SioFrame* frame, u8* src, s32 len) {
#ifdef NONMATCHING_C
  u8* dst;
  u32 seq;
  s32 i;

  frame->checksum = 0;
  frame->kind = 1;
  seq = Sio_NextSeq(ctx);
  frame->seq = seq;
  frame->payloadLen = len;
  frame->id = seq;
  frame->unk_0a = 0x01E0;
  frame->len = len + 4;
  dst = frame->payload;
  for (i = 0; i < len; i++) {
    *dst = *src;
    dst++;
    src++;
  }
  SioFrame_SetChecksum(frame);
  return frame->len;
#else
  INCFUNC("asm/func/Sio_BuildDataFrame.inc");
#endif
}

// 受け取った .id への応答フレームを組んで送信待ちキューに積む, 空きがなければ -1
s32 Sio_SendAck(SioPacketCtx* ctx, u32 id) {
  SioFrame* frame = SioFrameList_First(&ctx->freeList);

  if (frame == NULL) {
    return -1;
  }
  frame->checksum = 0;
  frame->kind = 2;
  frame->seq = id;
  frame->payloadLen = 0;
  frame->id = ctx->nextSeq;
  frame->unk_0a = 0x01E0;
  frame->len = 4;
  SioFrame_SetChecksum(frame);
  SioFrameList_PushBack(&ctx->sendQueue, frame);
  return 0;
}

void Sio_SetPacketError(SioPacketCtx* ctx, s32 err) { ctx->error = err; }

// 受信したフレームを種別ごとに振り分ける
void Sio_HandleFrame(SioPacketCtx* ctx, SioFrame* frame) {
  SioFrame* sent;

  switch (frame->kind) {
    case 1: {
      SioFrameList_PushBack(&ctx->recvQueue, frame);
      if (Sio_SendAck(ctx, frame->id) < 0) {
        Sio_SetPacketError(ctx, 1);
      }
      break;
    }
    case 2: {
      sent = SioFrameList_FindById(&ctx->sentQueue, frame->seq);
      if (sent != NULL) {
        SioFrameList_PushBack(&ctx->freeList, sent);
      } else {
        Sio_SetPacketError(ctx, 0);
      }
      break;
    }
    default: {
      Sio_SetPacketError(ctx, 3);
      break;
    }
  }
}

NAKED void FUN_08238354(SioPacketCtx* p) { INCFUNC("asm/func/FUN_08238354.inc"); }

void Sio_FreePacketCtx(void) { gSioPacketCtx = NULL; }

// 4本のキューを空にして16個のフレームを全部空きフレームに繋ぐ
s32 Sio_InitPacketCtx(SioPacketCtx* ctx) {
  s32 i;

  ClearMemory(ctx, sizeof(SioPacketCtx));
  SioFrameList_Init(&ctx->sendQueue);
  SioFrameList_Init(&ctx->sentQueue);
  SioFrameList_Init(&ctx->recvQueue);
  SioFrameList_Init(&ctx->freeList);
  for (i = 0; i < 16; i++) {
    ctx->frames[i].prev = NULL;
    ctx->frames[i].next = NULL;
    SioFrameList_PushBack(&ctx->freeList, &ctx->frames[i]);
  }
  gSioPacketCtx = ctx;
  return 0;
}

// コンテキストの置き場所を確保して初期化し, そのポインタを返す
SioPacketCtx* Sio_CreatePacketCtx(void) {
  SioPacketCtx* ctx;

  Sio_AllocPacketCtx();
  ctx = gSioPacketCtx;
  Sio_InitPacketCtx(ctx);
  return ctx;
}

void FUN_0823849c(void) { FUN_08238354(gSioPacketCtx); }

// 送信待ちキューにフレームを積む, 戻り値は払い出した .id, 空きがなければ -1
s32 Sio_SendPacket(u8* src, s32 len) {
  SioPacketCtx* ctx = gSioPacketCtx;
  SioFrame* frame;

  if (ctx == NULL) {
    return -1;
  }
  frame = SioFrameList_First(&ctx->freeList);
  if (frame == NULL) {
    return -1;
  }
  Sio_BuildDataFrame(ctx, frame, src, len);
  SioFrameList_PushBack(&ctx->sendQueue, frame);
  return frame->id;
}

// .id のフレームの行き先, 1 = 送信待ち, 2 = 応答待ち, 0 = どこにもない (完了)
s32 Sio_GetPacketStatus(u32 id) {
  SioPacketCtx* ctx = gSioPacketCtx;

  if (ctx == NULL) {
    return -1;
  }
  if (SioFrameList_FindById(&ctx->sendQueue, id) != NULL) {
    return 1;
  }
  if (SioFrameList_FindById(&ctx->sentQueue, id) != NULL) {
    return 2;
  }
  return 0;
}

// 受信キューの先頭フレームの payload を取り出す, 戻り値は取り出したバイト数, キューが空なら 0
s32 Sio_RecvPacket(u8* dst) {
  SioPacketCtx* ctx = gSioPacketCtx;
  SioFrame* frame;
  u8* src;
  u8* p;
  u32 n, i;

  if (ctx == NULL) {
    return -1;
  }
  frame = SioFrameList_First(&ctx->recvQueue);
  if (frame == NULL) {
    return 0;
  }
  n = frame->payloadLen;
  src = frame->payload;
  p = dst;
  if (n != 0) {
    i = n;
    do {
      *p = *src;
      src++;
      p++;
      i--;
    } while (i != 0);
  }
  SioFrameList_PushBack(&ctx->freeList, frame);
  return n;
}

// エラーを消すつもりの関数だが条件が逆で, 0 のときに 0 を書くだけになっている
// 残差は自分自身への代入を gcc が削るため cmp/bne/str の3命令が消えること, 別名を使った書き換えも効かず
NON_MATCH s32 FUN_08238590(void) {
#ifdef NONMATCHING_C
  if (gSioPacketCtx->error == 0) {
    gSioPacketCtx->error = 0;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_08238590.inc");
#endif
}

// 3本のキューに残っているフレームを全部空きフレームに戻す
void Sio_ResetPacketQueues(void) {
  SioPacketCtx* ctx = gSioPacketCtx;
  SioFrame* frame;

  while ((frame = SioFrameList_First(&ctx->sendQueue)) != NULL) {
    SioFrameList_PushBack(&ctx->freeList, frame);
  }
  while ((frame = SioFrameList_First(&ctx->sentQueue)) != NULL) {
    SioFrameList_PushBack(&ctx->freeList, frame);
  }
  while ((frame = SioFrameList_First(&ctx->recvQueue)) != NULL) {
    SioFrameList_PushBack(&ctx->freeList, frame);
  }
}

void Sio_DisableInterrupts(void) { REG_IME = 0; }

void Sio_EnableInterrupts(void) { REG_IME = 1; }

void Sio_StartTransfer(void) { REG_SIOCNT |= SIO_START; }

void Sio_SerialIntr(void);

// シリアル割り込みのハンドラに Sio_SerialIntr を据え, SIOCNT と IE の両方で割り込みを有効にする
void Sio_StartSerialIntr(void) {
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  gIntrTable[1] = Sio_SerialIntr;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
  REG_SIOCNT |= SIO_INTR_ENABLE;
  REG_IME = 0;
  REG_IE |= INTR_FLAG_SERIAL;
  REG_IME = 1;
}

// シリアル割り込みを止めてハンドラを IntrDummy に戻し, SIOCNT を割り込みなしのマルチプレイモードに戻す
void Sio_StopSerialIntr(void) {
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  gIntrTable[1] = IntrDummy;
  REG_IME = 1;
  REG_SIOCNT = SIO_MULTI_MODE | SIO_115200_BPS;
  REG_IF = INTR_FLAG_SERIAL;
}

NAKED void Sio_SerialIntr(void) { INCFUNC("asm/func/Sio_SerialIntr.inc"); }

// 保留中のシリアル割り込みを捨ててから VBlank を待ち、SIO を 115200bps のマルチプレイモードに組み直す
void Sio_Reinit(void) {
  gSioStatus = 0;
  gSioMultiId = -1;
  REG_IME = 0;
  REG_IE &= ~INTR_FLAG_SERIAL;
  REG_IME = 1;
  REG_IF = INTR_FLAG_SERIAL;
  WaitForVBlank();
  REG_RCNT = 0;
  REG_SIOCNT = SIO_MULTI_MODE;
  REG_SIOCNT |= SIO_115200_BPS;
}

NAKED void FUN_08238a30(void) { INCFUNC("asm/func/FUN_08238a30.inc"); }

// 残差は命令列が完全一致でレジスタ番号が全体に1つずれるのみ (r1-r4 対 r2-r5), Tier A-C 試済
NON_MATCH void Sio_DetectRole(void) {
#ifdef NONMATCHING_C
  u16 cnt, si;

  gSioMultiId = -1;
  gSioStatus = 0;
  cnt = REG_SIOCNT;
  if ((cnt & (SIO_MULTI_SD | SIO_MULTI_BUSY)) != SIO_MULTI_SD) {
    gSioStatus = -1;
    return;
  }
  si = cnt & SIO_MULTI_SI;
  if (si == 0) {
    gSioMultiId = 0;
  } else {
    gSioMultiId = -1;
  }
  REG_SIOMLT_SEND = 0x4000;
#else
  INCFUNC("asm/func/Sio_DetectRole.inc");
#endif
}

NAKED s32 FUN_08238b04(void) { INCFUNC("asm/func/FUN_08238b04.inc"); }

// 役割を判定してシリアル割り込みを動かす, 戻り値は 0 = 親, 1 = 子, 負ならエラー
s32 Sio_Connect(void) {
  Sio_DetectRole();
  if (gSioStatus < 0) {
    return gSioStatus;
  }
  if (gSioMultiId == 0) {
    Sio_StartSerialIntr();
    return 0;
  }
  Sio_StartSerialIntr();
  return 1;
}

// シリアル割り込みを止めて通信を終了する, 親子で同じ処理だが分岐の形が一致に必要
s32 Sio_Disconnect(void) {
  if (gSioMultiId == 0) {
    Sio_StopSerialIntr();
  } else {
    Sio_StopSerialIntr();
  }
  if (u32_030046c4 == 1) {
    u32_030046c4 = 0;
  }
  return 0;
}

NAKED void FUN_08238c24(void) { INCFUNC("asm/func/FUN_08238c24.inc"); }

NAKED void FUN_08238cd4(void) { INCFUNC("asm/func/FUN_08238cd4.inc"); }

// 接続待ち (-1, -2) の間は何もせず, 正常に繋がっている間だけ転送を開始する
void Sio_StartTransferIfIdle(void) {
  if (gSioStatus < 0 && gSioStatus > -3) {
    return;
  }
  if (gSioStatus == 0) {
    Sio_StartTransfer();
  }
}

// 未読の受信データ4人分を取り出す, 戻り値は gSioMultiId, 未読がなければ -3
s32 Sio_GetRecvData(u16* dst) {
  s32 ret;

  if (gSioStatus < 0) {
    return gSioStatus;
  }
  Sio_DisableInterrupts();
  if (gSioRecvDataNew) {
    dst[0] = gSioRecvData[gSioRecvDataFace][0];
    dst[1] = gSioRecvData[gSioRecvDataFace][1];
    dst[2] = gSioRecvData[gSioRecvDataFace][2];
    dst[3] = gSioRecvData[gSioRecvDataFace][3];
    gSioRecvDataNew = FALSE;
    ret = gSioMultiId;
  } else {
    ret = -3;
  }
  Sio_EnableInterrupts();
  return ret;
}

// 送信スロットが空いていれば送信データを入れる, 空いていなければ -4
s32 Sio_SetSendData(u16 data) {
  s32 ret;

  Sio_DisableInterrupts();
  if (gSioSendNext & 0x4000) {
    gSioSendNext = data;
    ret = 0;
  } else {
    ret = -4;
  }
  Sio_EnableInterrupts();
  return ret;
}

// 受信データ4人分を既読かどうかに関わらず読む, 戻り値は gSioMultiId
s32 Sio_PeekRecvData(u16* dst) {
  if (gSioStatus < 0 && gSioStatus > -3) {
    dst[0] = 0xFFFF;
    dst[1] = 0xFFFF;
    dst[2] = 0xFFFF;
    dst[3] = 0xFFFF;
    return gSioStatus;
  }
  Sio_DisableInterrupts();
  dst[0] = gSioRecvRaw[gSioRecvRawFace][0];
  dst[1] = gSioRecvRaw[gSioRecvRawFace][1];
  dst[2] = gSioRecvRaw[gSioRecvRawFace][2];
  dst[3] = gSioRecvRaw[gSioRecvRawFace][3];
  Sio_EnableInterrupts();
  return gSioMultiId;
}
