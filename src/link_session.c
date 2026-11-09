#include "link_session.h"

#include "entity.h"
#include "global.h"
#include "input.h"
#include "link.h"
#include "malloc.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "text.h"
#include "time.h"
#include "video.h"
#include "vm.h"

COMMON_DATA LinkSession* gLinkSession = NULL;  // 0x03002C68
IWRAM_DATA u32 bool32_030001ac = FALSE;        // 0x030001AC

s32 FUN_081dec1c(LinkSession* p);
s32 FUN_081de130(LinkSession* p);
s32 FUN_081df460(LinkSession*);
void EntityCF58_CreateWithCallback(s32 param_1, s32 param_2, void* fn, void* arg);
s32 FUN_081de250(LinkSession*);
s32 FUN_081de9d8(LinkSession*);
s32 FUN_081de360(LinkSession*);
s32 FUN_081de6f0(LinkSession*);
s32 FUN_081de844(LinkSession*);
s32 FUN_081de960(LinkSession*);
s32 FUN_081df568(LinkSession* p);
s32 FUN_081df62c(LinkSession* p);
void EntityCF58_RequestKill(void);
s32 MainMenu_SetHudMode(s32 mode);
s32 Taiyo_LxToGauge(s32 lx);
void FUN_08238c24(void);
s32 FUN_081de2dc(LinkSession* p);
s32 FUN_081df604(LinkSession* p);
s32 FUN_081debd4(LinkSession* p);
s32 LinkSession_CountCoins(s32 n);
s32 FUN_081df0f8(LinkSession* p);
s32 FUN_081df3f0(LinkSession* p);
s32 FUN_081df540(LinkSession* p);
s32 FUN_081de7e8(LinkSession* p);
u32 CalcCRC16(u8* data, u32 len);
s32 LinkSession_SendData(LinkSession* p, u8* buf, s32 limit);
void LinkBattleLobby_Close(void);
s32 FUN_081deaf4(LinkSession* p);
s32 FUN_081df014(LinkSession* p);
s32 FUN_081df23c(LinkSession* p);
void MosaicFader_Stop(void);
extern u32 gMapChanging;
extern const s8 sLinkRankBonus[5][4];
void HUD_StartCountdown(u16* remainingTime);
void HUD_RemoveCountdown(void);
void Entity4B15_ShowFixedMarker(s32 playerIdx, Vec3* pos);
extern const u16 sLinkTimeLimits[3];
s32 FUN_081deef8(LinkSession* p);
extern bool32 gRtcReadInhibit;
void FUN_08238b04(void);
s32 FUN_081de214(LinkSession* p);
s32 FUN_081df398(LinkSession* p);
extern bool32 gSoftResetInhibit;
bool8 MessageWindow_IsOpen(void);

static inline bool8 LinkSession_IsIdle(LinkSession* p) {
  if (p->state == 0) return TRUE;
  return FALSE;
}

// idx 番のプレイヤーから受け取ったキー, 範囲外なら 0xFFFF (データなし)
static inline u16 LinkSession_GetRecvKey(LinkSession* p, s32 idx) {
  if (idx < 0) {
    return 0xFFFF;
  }
  return p->recvKeys[idx];
}

// データを運ぶキーか (bit10..13 が 0b0010)
static inline bool8 LinkSession_IsDataKey(u16 key) {
  if ((key & 0x3C00) == 0x800) {
    return TRUE;
  }
  return FALSE;
}

// 自分のプレイヤー番号, セッションが無ければ -1
static inline s32 LinkSession_GetPlayerIdx(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// キーの種別 (bit10..13) が kind か
static inline bool8 LinkSession_IsKeyKind(u16 key, u16 kind) {
  if ((key & 0x3C00) == kind) {
    return TRUE;
  }
  return FALSE;
}

// 次に送るキーを決める
static inline void LinkSession_SetSendKey(LinkSession* p, u16 key) { p->sendKey = key; }

// キーの種別 (bit10..13) が 0x0400 か
static inline bool8 LinkSession_IsKey0400(u16 key) {
  if ((key & 0x3C00) == 0x0400) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1000 か
static inline bool8 LinkSession_IsKey1000(u16 key) {
  if ((key & 0x3C00) == 0x1000) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1400 か
static inline bool8 LinkSession_IsKey1400(u16 key) {
  if ((key & 0x3C00) == 0x1400) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1800 か
static inline bool8 LinkSession_IsKey1800(u16 key) {
  if ((key & 0x3C00) == 0x1800) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1C00 か
static inline bool8 LinkSession_IsKey1C00(u16 key) {
  if ((key & 0x3C00) == 0x1C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2000 か
static inline bool8 LinkSession_IsKey2000(u16 key) {
  if ((key & 0x3C00) == 0x2000) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2C00 か
static inline bool8 LinkSession_IsKey2C00(u16 key) {
  if ((key & 0x3C00) == 0x2C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x0C00 か
static inline bool8 LinkSession_IsKey0C00(u16 key) {
  if ((key & 0x3C00) == 0x0C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2800 か
static inline bool8 LinkSession_IsKey2800(u16 key) {
  if ((key & 0x3C00) == 0x2800) {
    return TRUE;
  }
  return FALSE;
}

// 参加人数, セッションが無ければ -1
static inline s32 LinkSession_GetRecordCount(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->recordCount;
}

// 受信できたキーの数が参加人数と一致するか
static inline bool8 LinkSession_AllKeysReceived(LinkSession* p) {
  s32 count = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (LinkSession_GetRecvKey(p, i) != 0xFFFF) {
      count++;
    }
  }
  if (count == p->recordCount) {
    return TRUE;
  }
  return FALSE;
}

LinkSession* GetLinkSession(void) { return gLinkSession; }

void ClearLinkSession(void) { gLinkSession = NULL; }

// 状態番号と状態関数を入れ替えて、経過フレームを 0 に戻す
void LinkSession_SetState(LinkSession* p, u8 state, void* fn) {
  p->state = state;
  p->updateCallback = fn;
  p->stateTimer = 0;
  p->stateBegun = 1;
}

s32 FUN_081dd9d4(LinkSession* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
    return 1;
  }
  return 0;
}

void LinkSession_ResetDataTransfer(LinkSession* p) {
  s32 i;

  p->dataSendPos = 0;
  for (i = 0; i < 4; i++) {
    p->dataRecvPos[i] = 0;
  }
}

// lux[] の受信側と読み出し側を入れ替える
void LinkSession_SwapLuxBuffers(LinkSession* p) {
  if (p->luxRecvSide == 0) {
    p->luxRecvSide = 1;
    p->luxReadSide = 0;
  } else {
    p->luxRecvSide = 0;
    p->luxReadSide = 1;
  }
}

// 全員の太陽センサーの値をゲージに直して luxGauge に入れ, 平均を luxAverage に入れる
// 残差: 命令列は一致, gLinkSession の値を原典は r1 に読み添字を r0 で組むが, こちらは逆のレジスタになる (読み出しを NULL なら 0 の static inline にしても同じ)
NON_MATCH void LinkSession_UpdateLuxGauges(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 i;

  p->luxSum = 0;
  for (i = 0; i < p->recordCount; i++) {
    LinkSession* e = gLinkSession;
    s32 lux = (e != NULL) ? e->lux[e->luxReadSide][i] : 0;

    p->luxGauge[i] = Taiyo_LxToGauge(lux);
    p->luxSum += lux;
  }
  if (p->recordCount == 0) {
    p->luxAverage = 0;
  } else {
    p->luxAverage = Div(p->luxSum, p->recordCount);
  }
#else
  INCFUNC("asm/func/LinkSession_UpdateLuxGauges.inc");
#endif
}

// 自分の受信番号が正しく, 再試行が続いておらず, 全員分のキーが届いていれば 0, そうでなければ -1
s32 LinkSession_CheckRecv(LinkSession* p) {
  if (p->recvResult < 0 || p->recvResult != p->playerIdx || p->retryTimer > 14 || !LinkSession_AllKeysReceived(p)) {
    return -1;
  }
  return 0;
}

// buf から1バイトずつ送信データを組む, limit に届いたら 1
// 残差はレジスタ割当だけ (36 対 36), 原典は &dataSendPos を r12 に逃がして limit を r2 に残すが, こちらは limit を r5 に写して &dataSendPos を低レジスタに置く
// u16* のローカルに退避する形は試済
NON_MATCH s32 LinkSession_SendData(LinkSession* p, u8* buf, s32 limit) {
#ifdef NONMATCHING_C
  if (p->dataSendPos >= limit) {
    return 1;
  }
  if (p->sendResult < 0) {
    return 0;
  }

  p->sendKey = buf[p->dataSendPos] | ((p->dataSendPos & 3) << 8) | 0x800;
  p->dataSendPos++;
  if (p->dataSendPos >= limit) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/LinkSession_SendData.inc");
#endif
}

// idx 番のプレイヤーから届いたキーを順番どおりなら buf に積む, count 個そろっていれば 1
s32 LinkSession_RecvData(LinkSession* p, u8* buf, s32 idx, s32 count) {
  u8* dst;
  u16 key;

  if (p->dataRecvPos[idx] >= count) {
    return 1;
  }

  dst = buf + p->dataRecvPos[idx];
  key = LinkSession_GetRecvKey(p, idx);
  if (LinkSession_IsDataKey(key) && ((key & 0x300) >> 8) == (p->dataRecvPos[idx] & 3)) {
    *dst = key;
    p->dataRecvPos[idx]++;
    if (p->dataRecvPos[idx] >= count) {
      return 1;
    }
  }
  return 0;
}

void LinkSession_Disconnect(LinkSession* p) {
  p->recordCount = 0;
  p->prevState = p->state;
  LinkSession_SetState(p, 0, FUN_081de130);
  EntityCF58_RequestKill();
  Sio_Disconnect();
}

// コインを1人1枚ずつ持たせ, 残りの枠は持ち主なし (4) にする
void LinkSession_ResetCoins(LinkSession* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    p->coinOwners[i] = i;
  }
  for (; i < 5; i++) {
    p->coinOwners[i] = 4;
  }
}

// 各プレイヤーのこの回の得点を roundScores に, 累計を totalScores に入れる (0..9999), 参加していない枠は 0xFFFF
// 残差は末尾のループだけ: 原典は参加していない枠を ldrh/orrs/strh で 0xFFFF にするが, こちらは定数の strh に畳まれる
NON_MATCH void LinkSession_CalcScores(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    s32 total;

    p->roundScores[i] = LinkSession_CountCoins(i) * 16 + p->kills[i] * 9 - p->deaths[i] * 4;
    if (p->roundScores[i] < 0) {
      p->roundScores[i] = 0;
    }
    if (p->roundScores[i] > 9999) {
      p->roundScores[i] = 9999;
    }
    total = p->totalScores[i] + p->roundScores[i];
    if (total > 9999) {
      p->totalScores[i] = 9999;
    } else {
      p->totalScores[i] = total;
    }
  }
  for (; i < 4; i++) {
    p->roundScores[i] |= 0xFFFF;
    p->totalScores[i] |= 0xFFFF;
  }
#else
  INCFUNC("asm/func/LinkSession_CalcScores.inc");
#endif
}

// 今回の得点 roundScores の高い順に順位を付け, 順位と人数で決まる点 (同順位は頭割り) を累計 rankPoints に足す
// 下書き (201/200命令): 流れは一致, レジスタ割当が違いスタックが 4 バイト多い
NON_MATCH void LinkSession_AddRankPoints(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 order[4];
  s32 scores[4];
  s32 rankCount[4];
  s32 ranks[4];
  s32 n;
  s32 i;
  s32 j;
  s32 rank;

  for (i = 0; i < p->recordCount; i++) {
    order[i] = i;
    scores[i] = p->roundScores[i];
  }
  n = p->recordCount;
  for (; i < 4; i++) {
    order[i] = -1;
    scores[i] = -1;
  }

  for (i = 0; i < 3; i++) {
    for (j = 3; j > i; j--) {
      if (scores[j - 1] < scores[j]) {
        s32 tmp = scores[j];

        scores[j] = scores[j - 1];
        scores[j - 1] = tmp;
        tmp = order[j];
        order[j] = order[j - 1];
        order[j - 1] = tmp;
      }
    }
  }

  for (i = 0; i < 4; i++) {
    rankCount[i] = 0;
  }
  rank = 0;
  rankCount[0] = 1;
  ranks[0] = 0;
  for (i = 1; i < n; i++) {
    if (scores[i] < scores[i - 1]) {
      rank = i;
    }
    ranks[i] = rank;
    rankCount[rank]++;
  }

  for (i = 0; i < p->recordCount; i++) {
    s32 who = order[i];
    s32 rk = ranks[i];
    s32 points = p->rankPointTable[rk];
    s32 bonus = FixToInt(6, Div(p->eneSpent * sLinkRankBonus[n][rk], 20));

    if (bonus > 0) {
      if (bonus > 60) {
        bonus = 60;
      }
    } else if (bonus < -60) {
      bonus = -60;
    }
    points += bonus;
    if (rankCount[rk] > 1) {
      points = Div(points, rankCount[rk]);
    }
    p->rankPoints[who] += points;
  }
#else
  INCFUNC("asm/func/LinkSession_AddRankPoints.inc");
#endif
}

// 各レコードの36バイトを bodies[] へ写す
void LinkSession_CopyTradeWeapons(LinkSession* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    LinkPlayerRecord* rec = &p->records[i];
    LinkTradeWeapon* dst = &p->bodies[i];

    *dst = rec->body;
  }
}

void LinkSession_ResetRound(LinkSession* p) {
  s32 i;

  p->timeLeft = p->timeLimit;
  p->stateTimer = 0;
  LinkSession_ResetCoins(p);
  for (i = 0; i < 4; i++) {
    p->kills[i] = 0;
    p->deaths[i] = 0;
    p->roundScores[i] = 0;
    gLinkKeyInput[i] = 0x3FF;
  }
  p->eneSpent = 0;
  p->luxRecvBit = 0;
  p->luxSendBit = 0;
  LinkSession_CopyTradeWeapons(p);
  gRandTableIdx = p->records[0].randSeed & 0x3FF;
}

// recordCount と unk_38 / unk_3a を引数にして startScriptID のスクリプトを起動する
void LinkSession_RunStartScript(LinkSession* p) {
  ScriptArgs args;
  u32 argv[3];

  if (p->startScriptID != 0) {
    argv[0] = p->recordCount;
    argv[1] = p->unk_38;
    argv[2] = p->unk_3a;
    args.argc = 3;
    args.argv = argv;
    VM_ExecByID(p->startScriptID, &args);
  }
}

// 上限に達しているルールの値を 0 に戻す
void LinkSession_ClampRules(LinkSession* p) {
  static const s32 sLinkBattleRuleLimits[3] = {2, 3, 4};  // 0x085AE3E8
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->rules.values[i] >= sLinkBattleRuleLimits[i]) {
      p->rules.values[i] = 0;
    }
  }
}

// CRC-16/CCITT (生成多項式 0x1021, 初期値 0xFFFF) を求めて反転したものを返す
u32 CalcCRC16(u8* data, u32 len) {
  u32 crc = 0xFFFF;
  u32 i;

  for (i = 0; i < len; i++) {
    u32 j;

    crc ^= data[i] << 8;
    for (j = 0; j < 8; j++) {
      if (crc & 0x8000) {
        crc = (crc << 1) ^ 0x1021;
      } else {
        crc <<= 1;
      }
    }
  }
  return ~crc & 0xFFFF;
}

// 応答の途絶えているプレイヤーがいるか
s32 FUN_081de004(LinkSession* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    if (p->noReplyFrames[i]) {
      return 1;
    }
  }

  return 0;
}

// 自分の記録に名前, 乱数の種, 操作設定, 太陽スタンドを書く, 乱数の種は親機 (sioID == 0) だけが時計から作る
void LinkSession_InitSelfRecord(LinkSession* p) {
  LinkPlayerRecord* rec = &p->self;
  char* name = gStat->name;
  s32 i;

  for (i = 0; i < 16; i++) {
    rec->name[i] = name[i];
  }
  rec->randSeed = (p->sioID == 0) ? gClock.second * 15 + gClock.frame : 0;
  rec->unk_12 = 100;
  rec->controlUp = gStat->controlUp;
  rec->unk_18 = gStat->solarStand;
}

void FUN_081de090(LinkSession* p) {
  LinkSession_InitSelfRecord(p);
  p->rulesOut.values[0] = 0;
  p->rulesOut.values[1] = 0;
  p->rulesOut.values[2] = 0;
  ClearMemory(p->self.unk_40, 4);
  p->self.tradeSlot = 0xFF;
  p->self.unk_44 = Time_GetSpanOfTime();
}

// 残差: 原典は coinOwners を &coinOwners[4] から下へ動くポインタと別の数え役で埋めるが, こちらは添字のまま [base + i] で書く
NON_MATCH void FUN_081de0dc(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 4; i >= 0; i--) {
    p->coinOwners[i] = 4;
  }
  for (i = 0; i < 4; i++) {
    p->kills[i] = 0;
    p->deaths[i] = 0;
    p->roundScores[i] = 0;
    p->totalScores[i] = 0;
    p->rankPoints[i] = 0;
  }
  p->eneSpent = 0;
#else
  INCFUNC("asm/func/FUN_081de0dc.inc");
#endif
}

// 切断を知らせる画面を出し, メッセージ窓が開いたら終了のメッセージを流す
s32 FUN_081de130(LinkSession* p) {
  if ((u8)FUN_081dd9d4(p)) {
    gUseLinkInput = FALSE;
    SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
    p->unk_54[1] = 0;
    p->sendKey = 0x4000;
    p->windowID = TextPanel_Create(1, 7, 28, 6);
    Sound_FadeOutBGM(1);
    Marquee_CloseGlobal();
    ClearBGTilemapBuffer(0);
  }

  if (p->unk_54[1] == 0 && MessageWindow_IsOpen()) {
    p->unk_54[1] = 1;
    MainMenu_SetHudMode(5);
    TextPanel_SetScript(p->windowID, p->messageScript);
    TextPanel_SetMessage(p->windowID, 2);
    TextPanel_Start(p->windowID);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
    Video_ResetFrameState(1);
  }

  Video_SetDrawPasses(0, nop_0822e738, nop_0822b09c, FUN_0822f584);
  if (p->stateTimer < 30) {
    gSoftResetInhibit = TRUE;
  }
  return 0;
}

// 残差は最後の 0 代入のレジスタのみ (原典 r0 / こちら r1), 命令列は 25 対 25 で一致
// 値を返す宣言 + return 無しで FUN_081dd9d4 の戻り値が r0 を塞ぐ形までは再現できたが、末尾の 0 共有が合わない
NON_MATCH s32 FUN_081de214(LinkSession* p) {
#ifdef NONMATCHING_C
  if ((u8)FUN_081dd9d4(p)) {
    p->unk_23 = 0;
  }

  if (p->unk_23 == 3) {
    LinkSession_SetState(p, 2, FUN_081de250);
    p->unk_23 = 0;
  }
#else
  INCFUNC("asm/func/FUN_081de214.inc");
#endif
}

// 接続を試み, つながれば state 3 へ, 30回失敗したら切断して state 2 からやり直す, 原典は最後の return を書き忘れている
s32 FUN_081de250(LinkSession* p) {
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    FUN_08238c24();
    for (i = 0; i < 4; i++) {
      if (p->connStatus[i] != 0) {
        p->connStatus[i] = 1;
      }
    }
    p->retryFrames = 0;
  }

  if (p->stateTimer > 2) {
    s32 id = Sio_Connect();

    if (id >= 0) {
      p->sioID = id;
      LinkSession_SetState(p, 3, FUN_081de2dc);
      return 0;
    }
    if (++p->retryFrames >= 30) {
      LinkSession_SetState(p, 2, FUN_081de250);
      Sio_Disconnect();
      for (i = 0; i < 4; i++) {
        p->connStatus[i] = 0;
      }
    }
  }
}

// 自分の番号へのデータが届いたら state 4 へ, 30 フレーム届かなければ切断して state 2 からやり直す
s32 FUN_081de2dc(LinkSession* p) {
  u16 recv[4];
  s32 result;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    p->retryFrames = 0;
  }

  result = Sio_PeekRecvData(recv);
  if (p->recvResult >= 0 && result >= 0 && recv[p->recvResult] != 0xFFFF) {
    LinkSession_SetState(p, 4, FUN_081de360);
  } else if (++p->retryFrames >= 30) {
    LinkSession_SetState(p, 2, FUN_081de250);
    Sio_Disconnect();
    for (i = 0; i < 4; i++) {
      p->connStatus[i] = 0;
    }
  }
  return 0;
}

// ロビー, 全員の準備完了 (0x0400 | 0x3E か 0x1400) がそろって親機が START を押したら state 5 へ, 受信が途絶えたら state 2 からやり直す
// 下書き (421/416命令): 流れは一致, 原典は unk_74 を消すループを &unk_74[3] から下へ動くポインタと &unk_74[0] の比較で回し (FUN_081de0dc と同じ形), &unk_23 を経路ごとに r6 へ作る
NON_MATCH s32 FUN_081de360(LinkSession* p) {
#ifdef NONMATCHING_C
  u16 recv[4];
  s32 i;

  Sio_PeekRecvData(recv);
  if ((u8)FUN_081dd9d4(p)) {
    p->retryFrames = 0;
    p->unk_28 = 0;
    p->unk_2c[1] = 40;
    if (gLinkSession != NULL) {
      gLinkSession->unk_2c[0] = 0;
    }
    for (i = 3; i >= 0; i--) {
      p->unk_74[i] = 0;
    }
  }

  if (p->recvResult < 0) {
    if (++p->retryFrames >= 60) {
    restart:
      LinkSession_SetState(p, 2, FUN_081de250);
      Sio_Disconnect();
      return 0;
    }
    if (p->recvResult != -3) {
      for (i = 3; i >= 0; i--) {
        p->unk_74[i] = 0;
      }
      for (i = 0; i < 4; i++) {
        if (recv[i] == 0xFFFF) {
          if (p->noReplyFrames[i] < 0xFF) {
            p->noReplyFrames[i]++;
          }
          if (p->noReplyFrames[i] > 119) {
            p->connStatus[i] = 0;
          }
        } else {
          p->noReplyFrames[i] = 0;
          p->connStatus[i] = 1;
        }
      }
    } else if (p->sioID == 0 && (gInput[0].pressed & START_BUTTON)) {
      p->unk_28 = 1;
    }
  } else {
    s32 readyCount;
    bool32 allReady;
    bool32 waiting;

    for (i = 0; i < 4; i++) {
      if (recv[i] == 0xFFFF) {
        if (p->noReplyFrames[i] < 0xFF) {
          p->noReplyFrames[i]++;
        }
        if (p->noReplyFrames[i] > 119) {
          p->connStatus[i] = 0;
        }
      } else {
        p->noReplyFrames[i] = 0;
        p->connStatus[i] = 1;
      }
    }
    p->retryFrames = 0;
    if (recv[p->recvResult] == 0xFFFF) {
      goto restart;
    }
    p->playerIdx = p->recvResult;
    p->recordCount = 0;
    readyCount = 0;
    allReady = TRUE;
    waiting = FALSE;
    for (i = 0; i < 4; i++) {
      u16 key = LinkSession_GetRecvKey(p, i);

      if (key != 0xFFFF && ((LinkSession_IsKey0400(key) && (key & 0xFF) == 0x3E) || LinkSession_IsKey1400(key))) {
        readyCount++;
        if (p->unk_74[i] < 0xFF) {
          p->unk_74[i]++;
        }
        if (p->unk_74[i] > 89) {
          p->connStatus[i] = 2;
          if (allReady) {
            p->recordCount++;
          }
        } else {
          allReady = FALSE;
          p->connStatus[i] = 1;
        }
      } else {
        if (key == 0xFFFF) {
          p->connStatus[i] = 0;
        } else {
          waiting = TRUE;
          p->connStatus[i] = 1;
        }
        allReady = FALSE;
        p->unk_74[i] = 0;
        if (gLinkSession != NULL) {
          gLinkSession->unk_2c[0] = 0;
        }
      }
    }
    if (waiting) {
      for (i = 0; i < 4; i++) {
        if (recv[i] != 0xFFFF) {
          p->connStatus[i] = 1;
        }
        p->unk_74[i] = 0;
      }
    }
    if (LinkSession_IsKey1400(p->recvKeys[0])) {
      if (gLinkSession != NULL) {
        gLinkSession->unk_2c[0] = 1;
      }
      if (p->unk_2c[1] != 0) {
        p->unk_2c[1]--;
        if (p->recordCount > 1 && p->recordCount == readyCount && !waiting) {
          if (p->sioID == 0) {
            p->connStatus[0] = 3;
          }
          goto check;
        }
      } else if (p->recordCount > 1 && p->recordCount == readyCount && !waiting) {
        LinkSession_SetState(p, 5, FUN_081de6f0);
        LinkSession_ResetDataTransfer(p);
        PlaySound_082406e0(SE_SELECT);
        return 0;
      }
    } else {
      p->unk_2c[1] = 40;
      if (p->sioID == 0 && p->recordCount > 1 && p->recordCount == readyCount && !waiting) {
        if ((gInput[0].pressed & START_BUTTON) || p->unk_28) {
          LinkSession_SetSendKey(p, 0x1400);
          p->unk_28 = 0;
          if (gLinkSession != NULL) {
            gLinkSession->unk_2c[0] = 1;
          }
        }
        p->connStatus[0] = 3;
        goto check;
      }
    }
    LinkSession_SetSendKey(p, 0x043E);
  }
check:
  if (p->unk_23 == 2) {
    FUN_08238c24();
    LinkSession_SetState(p, 1, FUN_081de214);
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081de360.inc");
#endif
}

// 自分の記録を送り全員の記録を受け取る, 親機は全部そろったらキー 0x1800 を送り, それが届いたら state 6 へ, 原典は最後の return を書き忘れている
s32 FUN_081de6f0(LinkSession* p) {
  s32 count;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    LinkSession_ResetDataTransfer(p);
    LinkSession_InitSelfRecord(p);
    LinkSession_ResetCoins(p);
    p->self.crc = CalcCRC16((u8*)&p->self, 0x46);
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (LinkSession_IsKey1800(p->recvKeys[0])) {
    LinkSession_CopyTradeWeapons(p);
    LinkSession_SetState(p, 6, FUN_081de7e8);
    return 0;
  }

  LinkSession_SendData(p, (u8*)&p->self, sizeof(LinkPlayerRecord));
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    if ((u8)LinkSession_RecvData(p, (u8*)&p->records[i], i, sizeof(LinkPlayerRecord)) == 1) {
      CalcCRC16((u8*)&p->records[i], 0x46);
      count++;
    }
  }
  if (count == p->recordCount && p->sioID == 0) {
    LinkSession_SetSendKey(p, 0x1800);
  }
  if (p->stateTimer > 3600) {
    LinkSession_Disconnect(p);
    return -1;
  }
}

s32 FUN_081de7e8(LinkSession* p) {
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (p->stateTimer > 120) {
    if (gLinkSession != NULL && gLinkSession->playerIdx == 0) {
      LinkSession_SetState(p, 7, FUN_081de844);
    } else {
      LinkSession_SetState(p, 8, FUN_081de960);
    }
  }
  return 0;
}

// 親機の選択を待つ: キー 0x1C00 なら state 9 (ルールの受け渡し), キー 0x400 なら state 4 へ戻る, 親機は unk_23 に応じてキーを送る
s32 FUN_081de844(LinkSession* p) {
  if ((u8)FUN_081dd9d4(p)) {
    LinkBattleLobby_Close();
    VM_ExecByID(p->unk_2ea, NULL);
    if (LinkSession_GetPlayerIdx() == 0) {
      sound_08240264(0xA8);
    }
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (LinkSession_IsKey1C00(p->recvKeys[0])) {
    LinkSession_SetState(p, 9, FUN_081de9d8);
  } else if (LinkSession_IsKey0400(p->recvKeys[0])) {
    LinkSession_SetState(p, 4, FUN_081de360);
    if (LinkSession_GetPlayerIdx() == 0) {
      Sound_FadeOutBGM(1);
    }
  } else if (LinkSession_GetPlayerIdx() == 0 && p->unk_23 != 0) {
    if (p->unk_23 == 1) {
      LinkSession_SetSendKey(p, 0x1C00);
    } else if (p->unk_23 == 2) {
      LinkSession_SetSendKey(p, 0x400);
      VM_ExecByID(p->unk_2e8, NULL);
    }
    p->unk_23 = 0;
  }
  return 0;
}

// 残差6命令, 原典は通信ステータスの比較結果を 0/1 に起こしてから if で見るが agbcc は条件を直接分岐に畳む (Mover_ShowTrackingMarker / FUN_080fc174 と同じ), static inline (if/else で return) は試済
// ステータス比較を bool8 を返す static inline にすると 0/1 の作り置きは出るが, 比べる定数を原典はマスクの後で作るのに対しこちらは先に作る (52/52)
NON_MATCH s32 FUN_081de960(LinkSession* p) {
#ifdef NONMATCHING_C
  u16* status;

  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  status = p->recvKeys;
  if ((*status & 0x3C00) == 0x1C00) {
    LinkSession_SetState(p, 9, FUN_081de9d8);
    return 0;
  }

  if ((*status & 0x3C00) == 0x400) {
    LinkSession_SetState(p, 4, FUN_081de360);
    return 0;
  }
#else
  INCFUNC("asm/func/FUN_081de960.inc");
#endif
}

// 親機がルールを送り, 全員が受け取ったら乱数の種とルールを反映して state 10 へ, 原典は最後の return を書き忘れている
s32 FUN_081de9d8(LinkSession* p) {
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    LinkSession_ResetDataTransfer(p);
    if (LinkSession_GetPlayerIdx() == 0) {
      p->rulesOut.crc = CalcCRC16(p->rulesOut.values, 6);
    }
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (LinkSession_GetPlayerIdx() == 0) {
    LinkSession_SendData(p, (u8*)&p->rulesOut, sizeof(LinkBattleRules));
  }
  if ((u8)LinkSession_RecvData(p, (u8*)&p->rules, 0, sizeof(LinkBattleRules)) == 1) {
    CalcCRC16(p->rules.values, 6);
    LinkSession_SetState(p, 10, FUN_081deaf4);
    Marquee_CloseGlobal();
    ClearBGTilemapBuffer(0);
    LinkSession_ClampRules(p);
    gRandTableIdx = p->records[0].randSeed & 0x3FF;
    p->unk_38 = p->rules.values[2];
    if (p->unk_38 > 2) {
      p->unk_38 = Mod(Random(), 3);
    }
    LinkSession_RunStartScript(p);
    for (i = 0; i < 4; i++) {
      gLinkKeyInput[i] = 0x3FF;
    }
    return 0;
  }
}

// 全員から種別 0x2000 のキーが届いたら state 11 へ, 原典は最後の return を書き忘れている
// 残差: 原典は種別の定数 0x2000 をループ内で毎回作るが, こちらはループ外へ出して r12 に置く (FUN_081df568 と同じ)
NON_MATCH s32 FUN_081deaf4(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  gUseLinkInput = TRUE;
  if ((u8)FUN_081dd9d4(p)) {
    Sound_FadeOutBGM(1);
  }
  if (p->stateTimer == 1) {
    SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    if (LinkSession_IsKeyKind(LinkSession_GetRecvKey(p, i), 0x2000)) {
      count++;
    }
  }
  if (count == n) {
    LinkSession_SetState(p, 11, FUN_081debd4);
    return 0;
  }
  if (p->stateTimer >= 10) {
    p->sendKey = 0x2000;
    CLEAR_FLAGS(gSuspendFlags, SUSPEND_MENU);
  }
#else
  INCFUNC("asm/func/FUN_081deaf4.inc");
#endif
}

void FUN_081debc0(LinkSession* p) { LinkSession_SetState(p, 12, FUN_081dec1c); }

s32 FUN_081debd4(LinkSession* p) {
  gUseLinkInput = TRUE;

  if ((u8)FUN_081dd9d4(p)) {
    EntityCF58_CreateWithCallback(0, 0, FUN_081debc0, p);
  }

  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }
}

// 通信対戦の制限時間 (フレーム), rules.values[1] で選ぶ
const u16 sLinkTimeLimits[3] = {3600, 5400, 7200};  // 0x085AE3F4

// 通信対戦のステータス (力, 体力, 精神, 素早さ) の基本値
const u8 sLinkStatBase[4] = {50, 30, 10, 40};  // 0x085AE3FA

// 種類ごとに上がる能力の値, 並びは sLinkStatBase と同じ
const u8 sLinkStatBoost[6] = {90, 60, 60, 60};  // 0x085AE3FE, 末尾2要素は 0

// 対戦中: 全員のキー入力を受け取って gLinkKeyInput に入れ, 太陽センサーの値を 1 bit ずつ集め, 時間切れか決着のキーで state 13 へ
// 下書き (326/318命令): 呼び出しの並びは一致, レジスタ割当と送るキーの組み立て (bit 演算の順) が違う
NON_MATCH s32 FUN_081dec1c(LinkSession* p) {
#ifdef NONMATCHING_C
  u16 keys;
  s32 flags;
  s32 i;
  s32 bit;

  gUseLinkInput = TRUE;
  if ((u8)FUN_081dd9d4(p)) {
    p->timeLeft = sLinkTimeLimits[p->rules.values[1]];
    p->unk_54[0] = gStat->lx;
    HUD_StartCountdown((u16*)&p->timeLeft);
    for (i = 0; i < LinkSession_GetRecordCount(); i++) {
      if (gPlayerPtr[i] != NULL) {
        Player_Unlock(gPlayerPtr[i]);
      }
    }
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  keys = REG_KEYINPUT & ~(SELECT_BUTTON | START_BUTTON);
  flags = 0;
  for (i = 0; i < p->recordCount; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKey0C00(key)) {
      gLinkKeyInput[i] = (key & 0x3FF) | SELECT_BUTTON | START_BUTTON;
      p->lux[p->luxRecvSide][i] |= ((key >> 2) & 1) << p->luxRecvBit;
      if (i == 0) {
        flags = 1;
        if (key & 8) {
          flags = 3;
        }
      }
    } else {
      if (key == 0xFFFF) {
        LinkSession_Disconnect(p);
        return -1;
      }
      if (i == p->playerIdx && LinkSession_IsKey2800(key)) {
        LinkSession_SetState(p, 13, FUN_081deef8);
        return 0;
      }
    }
  }

  if (flags & 1) {
    p->luxRecvBit++;
  }
  if (flags & 2) {
    LinkSession_SwapLuxBuffers(p);
    LinkSession_UpdateLuxGauges(p);
    p->luxRecvBit = 0;
    p->unk_54[0] = gStat->lx;
    for (i = 0; i < p->recordCount; i++) {
      p->lux[p->luxRecvSide][i] = 0;
    }
  }

  if (p->timeLeft == 1800 || p->timeLeft == 900) {
    for (i = 0; i < p->recordCount; i++) {
      if (LinkSession_CountCoins(i) > 2) {
        Entity4B15_ShowFixedMarker(i, &gPlayerPtr[i]->mover.pos);
      }
    }
  }

  if (p->timeLeft <= 0) {
    HUD_RemoveCountdown();
    LinkSession_SetSendKey(p, 0x2800);
    LinkSession_SetState(p, 13, FUN_081deef8);
    return 0;
  }

  if (LinkSession_GetPlayerIdx() == 0 && p->luxSendBit == 7) {
    keys |= START_BUTTON;
  }
  bit = (gLinkSession != NULL) ? (gLinkSession->unk_54[0] >> gLinkSession->luxSendBit) & 1 : 0;
  keys |= bit << 2;
  p->luxSendBit = (p->luxSendBit + 1) & 7;
  LinkSession_SetSendKey(p, (0xC00 | keys) & 0x3FFF);
  p->timeLeft--;
  return 0;
#else
  INCFUNC("asm/func/FUN_081dec1c.inc");
#endif
}

// 対戦開始: 参加回数を数え, 全員から種別 0x1000 の 0 番のキーが届いたら得点を計算して state 14 へ, 原典は最後の return を書き忘れている
// 残差: 原典は linkBattleCount の2つ目の式で gStat を読み直し, キー種別の定数をループ内で作る (FUN_081df568 と同じ), p は r5 に置く
NON_MATCH s32 FUN_081deef8(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    Sound_StopAll();
    EntityCF58_CreateWithCallback(1, 0, NULL, p);
    SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
    MosaicFader_Stop();
    gUseLinkInput = FALSE;
    gStat->linkBattleCount = (gStat->linkBattleCount < 0) ? 0 : gStat->linkBattleCount;
    gStat->linkBattleCount = (gStat->linkBattleCount + 1 > 9999) ? 9999 : gStat->linkBattleCount + 1;
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKeyKind(key, 0x1000) && (key & 0x3F) == 0) {
      count++;
    }
  }
  if (count == n) {
    LinkSession_SetState(p, 14, FUN_081df014);
    p->unk_21 = 0;
    LinkSession_CalcScores(p);
    LinkSession_AddRankPoints(p);
    return 0;
  }
  if (p->stateTimer >= 90) {
    p->sendKey = 0x1000;
  }
#else
  INCFUNC("asm/func/FUN_081deef8.inc");
#endif
}

// 全員から種別 0x2C00 のキーがそろったら, 全員が 0 以外なら state 17, そうでなければ state 20 へ, そろうまでは自分の選択 unk_24 を送る
// 残差: 原典はキー種別の比較定数を比較の直前に毎回作り, ループ外へ出さない (キーがビットフィールドで定数が combine で後から生まれる形かもしれない), 加えて count と i のレジスタが入れ替わる
NON_MATCH s32 FUN_081df014(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 yes;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    VM_ExecByID(p->unk_2e2, NULL);
    p->unk_24 = -1;
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  count = 0;
  yes = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKeyKind(key, 0x2C00)) {
      if (key & 0x3F) {
        yes++;
      }
      count++;
    }
  }

  if (count == n) {
    if (count == yes) {
      LinkSession_SetState(p, 17, FUN_081df0f8);
    } else {
      LinkSession_SetState(p, 20, FUN_081df3f0);
    }
  } else if (p->unk_24 >= 0) {
    p->sendKey = (0x2C00 | p->unk_24) & 0x3FFF;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081df014.inc");
#endif
}

// 全員から 0x10A5 のキーが届いたら state 18 へ, unk_25 が立っていれば最初の1回だけ確認のメッセージを出し, 0x10A5 を送り続ける
// 残差: 原典は LinkSession_CheckRecv の戻り値を r1 に写してから比べ, キー種別の定数をループ内で作る (FUN_081df568 と同じ), count と i のレジスタも違う
NON_MATCH s32 FUN_081df0f8(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    p->unk_25 = 0;
    p->unk_26 = 0;
    if (gLinkSession != NULL) {
      gLinkSession->unk_54[2] = 1;
    }
    if (p->unk_2de != 0) {
      VM_ExecByID(p->unk_2de, NULL);
    }
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKeyKind(key, 0x1000) && (key & 0xFF) == 0xA5) {
      count++;
    }
  }
  if (count == n) {
    LinkSession_SetState(p, 18, FUN_081df23c);
    return 0;
  }

  if (p->unk_25 != 0) {
    if (p->unk_26 == 0) {
      StartBgObjPlttFade(0, 1, 4, 4, 4, 0xFFFF, 0);
      MainMenu_SetHudMode(5);
      p->windowID = TextPanel_Create(1, 7, 28, 6);
      TextPanel_SetScript(p->windowID, p->unk_2f0);
      TextPanel_SetMessage(p->windowID, 9);
      TextPanel_Start(p->windowID);
      p->unk_26 = 1;
    }
    p->sendKey = 0x10A5;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081df0f8.inc");
#endif
}

// 対戦後に自分の記録を作り直して全員と交換する, 親機は全部そろったらキー 0x1800 を送り, それが届いたら state 19 へ, 原典は最後の return を書き忘れている
// 残差: 命令列は一致, Random() の表のアドレスを原典は gRandTableIdx の番地を置いていた r2 に読むが, こちらは r1 に読む
NON_MATCH s32 FUN_081df23c(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    LinkSession_ResetDataTransfer(p);
    LinkSession_InitSelfRecord(p);
    LinkSession_ResetCoins(p);
    if (LinkSession_GetPlayerIdx() == 0) {
      p->self.randSeed = gClock.second * 15 + gClock.frame;
      p->self.unk_16 = (p->rules.values[2] > 2) ? Mod(Random(), 3) : p->rules.values[2];
    }
    p->self.crc = CalcCRC16((u8*)&p->self, 0x46);
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (LinkSession_IsKey1800(p->recvKeys[0])) {
    LinkSession_CopyTradeWeapons(p);
    LinkSession_SetState(p, 19, FUN_081df398);
    return 0;
  }

  LinkSession_SendData(p, (u8*)&p->self, sizeof(LinkPlayerRecord));
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    if ((u8)LinkSession_RecvData(p, (u8*)&p->records[i], i, sizeof(LinkPlayerRecord)) == 1) {
      CalcCRC16((u8*)&p->records[i], 0x46);
      count++;
    }
  }
  if (count == p->recordCount && LinkSession_GetPlayerIdx() == 0) {
    LinkSession_SetSendKey(p, 0x1800);
  }
#else
  INCFUNC("asm/func/FUN_081df23c.inc");
#endif
}

// 待機が明けたら画面を消してスクリプトを流し, state 10 へ進む
s32 FUN_081df398(LinkSession* p) {
  FUN_081dd9d4(p);

  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (p->stateTimer > 119) {
    ClearBGTilemapBuffer(0);
    LinkSession_ResetRound(p);
    p->unk_38 = p->records[0].unk_16;
    LinkSession_RunStartScript(p);
    LinkSession_SetState(p, 10, FUN_081deaf4);
  }
}

s32 FUN_081df3f0(LinkSession* p) {
  if ((u8)FUN_081dd9d4(p)) {
    p->windowID = TextPanel_Create(1, 7, 28, 6);
    TextPanel_SetScript(p->windowID, p->unk_2f0);
    TextPanel_SetMessage(p->windowID, 10);
    TextPanel_Start(p->windowID);
  }

  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  if (p->stateTimer > 119) {
    LinkSession_SetState(p, 21, FUN_081df460);
  }
}

// 全員から種別 0x1000 の 1 番のキーが届いたら state 22 へ, unk_29 が立っていれば 60 フレーム待ってからキー 0x1001 を送る, 原典は最後の return を書き忘れている
// 残差: 原典はキー種別の比較定数を比較の直前に毎回作り, ループ外へ出さない (キーがビットフィールドで定数が combine で後から生まれる形かもしれない), 加えて count と i のレジスタが入れ替わる
NON_MATCH s32 FUN_081df460(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    if (p->unk_2e0 != 0) {
      VM_ExecByID(p->unk_2e0, NULL);
    }
    p->unk_27 = 0;
  }
  if (LinkSession_CheckRecv(p) < 0) {
    LinkSession_Disconnect(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKeyKind(key, 0x1000) && (key & 0x3F) == 1) {
      count++;
    }
  }
  if (count == n) {
    LinkSession_SetState(p, 22, FUN_081df540);
  }

  if (p->unk_29 != 0) {
    if (p->unk_27 >= 60) {
      p->sendKey = 0x1001;
    } else {
      p->unk_27++;
    }
  }
#else
  INCFUNC("asm/func/FUN_081df460.inc");
#endif
}

s32 FUN_081df540(LinkSession* p) {
  FUN_081dd9d4(p);
  if (p->unk_2a) {
    LinkSession_SetState(p, 23, FUN_081df568);
  }
}

// 全員から種別 0x1000 の 2 番のキーが届いたら state 24 へ, 受信番号が不正か 180 フレーム経ったら切断する, 原典は最後の return を書き忘れている
// 残差: 原典は種別の定数 0x1000 をループ内で毎回作り, count を r6, i を r5 に置くが, こちらは定数をループ外へ出す
NON_MATCH s32 FUN_081df568(LinkSession* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  FUN_081dd9d4(p);
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    u16 key = LinkSession_GetRecvKey(p, i);

    if (LinkSession_IsKeyKind(key, 0x1000) && (key & 0x3F) == 2) {
      count++;
    }
  }

  if (count == p->recordCount) {
    LinkSession_SetState(p, 24, FUN_081df604);
  } else if (p->recvResult == -2 || p->recvResult == -1 || p->stateTimer >= 180) {
    LinkSession_Disconnect(p);
    return -1;
  }
  p->sendKey = 0x1002;
#else
  INCFUNC("asm/func/FUN_081df568.inc");
#endif
}

s32 FUN_081df604(LinkSession* p) {
  FUN_081dd9d4(p);
  if (p->unk_2b) {
    LinkSession_SetState(p, 25, FUN_081df62c);
  }
}

s32 FUN_081df62c(LinkSession* p) {
  if ((u8)FUN_081dd9d4(p)) {
    MainMenu_SetHudMode(7);
    p->killRequested = 1;
  }
}

s32 FUN_081e1984(unknown* param_1, s32 val);  // src/link_battle_coin.c

// val 番のプレイヤーが持つコインを全部手放させる
s32 LinkSession_ReleaseAllCoins(unknown* param_1, s32 val) {
  LinkSession* p = gLinkSession;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->coinOwners[i] == val) {
      FUN_081e1984(param_1, val);
      p->coinOwners[i] = -1;
    }
  }
  return 0;
}

// val 番のプレイヤーが持つコインを1枚手放させる
s32 LinkSession_ReleaseCoin(unknown* param_1, s32 val) {
  LinkSession* p = gLinkSession;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->coinOwners[i] == val) {
      FUN_081e1984(param_1, val);
      p->coinOwners[i] = -1;
      break;
    }
  }
  return 0;
}

// 空いているコインを val 番のプレイヤーに持たせる, 空きが無ければ 0
s32 LinkSession_AddCoin(s32 val) {
  LinkSession* p = gLinkSession;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->coinOwners[i] == -1) {
      p->coinOwners[i] = val;
      return 1;
    }
  }
  return 0;
}

// n 番のプレイヤーが持っているコインの枚数
s32 LinkSession_CountCoins(s32 n) {
  LinkSession* p = gLinkSession;
  s32 count;
  s32 i;

  if (p == NULL) {
    return 0;
  }

  count = 0;
  for (i = 0; i < 5; i++) {
    if (p->coinOwners[i] == n) {
      count++;
    }
  }
  return count;
}

// '.X' 番のプレイヤーが持つコインの枚数をスクリプト側へ書き戻して返す
s32 Cmd_BE46(void) {
  u8 desc[8];
  s32 count = LinkSession_CountCoins(VM_GetValue());

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, count);
  return count;
}

// playerIdx をスクリプト側へ書き戻して返す
// 残差1命令, 原典は -1 と playerIdx を別の基本ブロックで代入するが agbcc は -1 を先に作って条件付きで上書きする形に畳む, 三項/if-else/条件の反転は試済
NON_MATCH s32 Cmd_064E(void) {
#ifdef NONMATCHING_C
  u8 desc[8];
  LinkSession* p = gLinkSession;
  s32 idx = (p == NULL) ? -1 : p->playerIdx;

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, idx);
  return idx;
#else
  INCFUNC("asm/func/Cmd_064E.inc");
#endif
}

// idx 番のプレイヤーが相手を倒した数を1増やす
s32 LinkSession_AddKill(s32 idx) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }

  p->kills[idx]++;
  return 0;
}

// idx 番のプレイヤーが倒された数を1増やす
s32 LinkSession_AddDeath(s32 idx) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }

  p->deaths[idx]++;
  return 0;
}

s32 Cmd_33C4(void) {
  WorldPos pos;
  s32 val;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }
  val = VM_GetNamedArgValue('t', 4);
  if (VM_GetNamedArgValue('m', 0) != 0) {
    return LinkSession_ReleaseAllCoins(&pos, val);
  } else {
    return LinkSession_ReleaseCoin(&pos, val);
  }
}

// state が 0 以外のときだけ unk_24 を書き換えて BGM をフェードアウトする
void FUN_081df8a0(s32 val) {
  LinkSession* p = gLinkSession;

  if (p != NULL && !LinkSession_IsIdle(p)) {
    p->unk_24 = val;
    Sound_FadeOutBGM(1);
  }
}

void FUN_081df8d4(void) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_25 = 1;
  }
}

void FUN_081df8f0(s32 val) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_21 = val;
  }
}

void FUN_081df908(void) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_29 = 1;
  }
}

void FUN_081df924(void) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_2a = 1;
  }
}

void FUN_081df940(void) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_2b = 1;
  }
}

void FUN_081df95c(s32 val) {
  if (gLinkSession != NULL) {
    gLinkSession->unk_23 = val;
  }
}

void LinkSession_RequestKill(void) {
  if (gLinkSession != NULL) {
    gLinkSession->killRequested = 1;
  }
}

// 終了要求が立っているかどうか
bool32 LinkSession_IsKillRequested(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return FALSE;
  }

  if (p->killRequested != 0) {
    return TRUE;
  }
  return FALSE;
}

// pos と val を引数に unk_2e4 のスクリプトを実行する
void FUN_081df9ac(Vec3* pos, s32 val) {
  LinkSession* p = gLinkSession;

  if (p != NULL) {
    u32 argv[6];
    ScriptArgs args;

    argv[0] = pos->x;
    argv[1] = pos->y;
    argv[2] = pos->z;
    argv[3] = 0;
    argv[4] = val;
    argv[5] = 0;
    args.argc = 6, args.argv = argv;
    VM_ExecByID(p->unk_2e4, &args);
  }
}

s32 FUN_081dfa04(void) {
  if (gLinkSession == NULL) {
    return 0;
  }
  return gLinkSession->state;
}

// 通信対戦のステータス (力, 体力, 精神, 素早さ) を基本値で埋め, kind の能力だけ上げた値にする
void FUN_081dfa20(s32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility) {
  if (gLinkSession == NULL) {
    return;
  }

  *strength = sLinkStatBase[0];
  *vitality = sLinkStatBase[1];
  *spirit = sLinkStatBase[2];
  *agility = sLinkStatBase[3];
  switch (kind) {
    case 2: {
      *strength = sLinkStatBoost[0];
      break;
    }
    case 0: {
      *vitality = sLinkStatBoost[1];
      break;
    }
    case 1: {
      *spirit = sLinkStatBoost[2];
      break;
    }
    case 3: {
      *agility = sLinkStatBoost[3];
      break;
    }
  }
}

// 通信を1フレーム進めて状態の updateCallback を呼ぶ, 受信が -3 の間は Entity を止めて数え, 終わる要求があれば消してスクリプトかソフトリセットへ
s32 LinkSession_Update(LinkSession* p) {
  bool32_030001ac = 0;
  if (p->state > 4) {
    gSoftResetInhibit = TRUE;
  }
  bool32_030001ac = 1;
  if (p->state > 2) {
    p->recvResult = Sio_GetRecvData(p->recvKeys);
    bool32_030001ac = 2;
    p->sendResult = Sio_SetSendData(p->sendKey);
    bool32_030001ac = 3;
    if (p->state > 5) {
      if (gLinkSession != NULL && gLinkSession->playerIdx == 0 && p->state != 22 && p->state != 24) {
        Sio_StartTransferIfIdle();
      }
    } else if (p->sioID == 0 && p->state != 22 && p->state != 24) {
      Sio_StartTransferIfIdle();
    }
    bool32_030001ac = 4;
  }
  bool32_030001ac = 5;
  if (p->state > 4 && p->state != 22 && p->state != 24 && p->state != 25) {
    bool32_030001ac = 6;
    if (p->recvResult == -3) {
      SET_FLAGS(gSuspendFlags, SUSPEND_LINK_WAIT);
      bool32_030001ac = 8;
      if (p->retryTimer < 0xFF) {
        p->retryTimer++;
        if (p->state > 4 && p->retryTimer > 14 && !gMapChanging) {
          LinkSession_Disconnect(p);
        }
      }
      bool32_030001ac = 9;
      return 0;
    }
    CLEAR_FLAGS(gSuspendFlags, SUSPEND_LINK_WAIT);
    p->retryTimer = 0;
    bool32_030001ac = 10;
  }
  bool32_030001ac = 12;
  p->updateCallback(p);
  p->stateTimer++;
  bool32_030001ac = 14;
  if (p->killRequested) {
    KillEntity(&p->e);
    if (p->state == 0) {
      bool32_030001ac = 15;
      GameSystem_SoftReset();
    } else if (p->exitScriptID != 0) {
      bool32_030001ac = 16;
      VM_ExecByID(p->exitScriptID, NULL);
    } else {
      bool32_030001ac = 17;
      GameSystem_SoftReset();
    }
  }
  bool32_030001ac = 18;
  return 0;
}

s32 LinkSession_Destroy(LinkSession* p) {
  Sio_Disconnect();
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  gUseLinkInput = FALSE;
  gGameFlags &= ~GAMEFLAG_LINK;
  gLinkSession = NULL;
  return 0;
}

// 0x9A9F
// 通信セッションを作る, 既にあればそれを返す, 原典は最後の return を書き忘れている
// 残差: 原典は recvKeyBuf を -1 のレジスタと ldrh/orrs/strh で埋め, '.s' の NULL で返す 0 のブロックを1つ目の取得の直後に置く
NON_MATCH LinkSession* LinkSession_Create(void) {
#ifdef NONMATCHING_C
  LinkSession* p;
  s32 i;

  if (gLinkSession != NULL) {
    return gLinkSession;
  }

  gLinkSession = Malloc(sizeof(LinkSession));
  if (gLinkSession == NULL) {
    return NULL;
  }
  p = gLinkSession;
  ClearMemory(p, sizeof(LinkSession));
  SetEntityRoutine(p, NULL, LinkSession_Destroy);
  p->e.kind = ENTITY_UNK_1;
  p->e.unk_16 = 1;
  p->e.id = 0;
  AddEntity(&p->e);
  gRtcReadInhibit = TRUE;
  FUN_08238b04();
  p->playerIdx = -1;
  p->killRequested = 0;
  p->recvKeys = p->recvKeyBuf;
  p->sendResult = -1;
  p->recvResult = -1;
  p->luxRecvSide = 0;
  p->luxReadSide = 1;
  p->luxRecvBit = 0;
  p->luxSendBit = 0;
  for (i = 0; i < 4; i++) {
    p->recvKeyBuf[i] |= 0xFFFF;
    p->connStatus[i] = 0;
  }
  FUN_081de0dc(p);
  FUN_081de090(p);
  LinkSession_SetState(p, 1, FUN_081de214);
  p->prevState = 3;
  p->unk_2ea = VM_GetNamedArgValue('U', 0);
  p->unk_2e8 = VM_GetNamedArgValue('Y', 0);
  p->startScriptID = VM_GetNamedArgValue('l', 0);
  p->unk_2e2 = VM_GetNamedArgValue('r', 0);
  p->unk_2de = VM_GetNamedArgValue('R', 0);
  p->unk_2e0 = VM_GetNamedArgValue('v', 0);
  p->exitScriptID = VM_GetNamedArgValue('E', 0);
  p->unk_2e4 = VM_GetNamedArgValue('b', 0);
  p->timeLimit = 7200;
  p->timeLeft = 7200;
  p->unk_3c = VM_GetNamedArgValue('L', 5000);
  if (VM_SeekToNamedArg('e')) {
    for (i = 0; i < 4; i++) {
      p->rankPointTable[i] = VM_GetValue();
    }
  } else {
    p->rankPointTable[0] = 2;
    p->rankPointTable[1] = 1;
    p->rankPointTable[2] = -1;
    p->rankPointTable[3] = -2;
  }

  if (!VM_SeekToNamedArg('s')) {
    return NULL;
  }
  p->messageScript = VM_GetPC_Proxy();
  if (p->messageScript == NULL) {
    return NULL;
  }
  if (!VM_SeekToNamedArg('S')) {
    return NULL;
  }
  p->unk_2f0 = VM_GetPC_Proxy();
  if (p->unk_2f0 == NULL) {
    return NULL;
  }
  MainMenu_SetHudMode(7);
#else
  INCFUNC("asm/func/LinkSession_Create.inc");
#endif
}

void FUN_081dfe5c(void) {
  if (gLinkSession != NULL) {
    LinkSession_Update(gLinkSession);
  }
}
