#include "entity_9a9f.h"

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

COMMON_DATA Entity9A9F* gEntity9A9F = NULL;  // 0x03002C68
IWRAM_DATA u32 bool32_030001ac = FALSE;      // 0x030001AC

s32 FUN_081dec1c(Entity9A9F* p);
s32 FUN_081de130(Entity9A9F* p);
s32 FUN_081df460(Entity9A9F*);
void EntityCF58_CreateWithCallback(s32 param_1, s32 param_2, void* fn, void* arg);
s32 FUN_081de250(Entity9A9F*);
s32 FUN_081de9d8(Entity9A9F*);
s32 FUN_081de360(Entity9A9F*);
s32 FUN_081de844(Entity9A9F*);
s32 FUN_081de960(Entity9A9F*);
s32 FUN_081df568(Entity9A9F* p);
s32 FUN_081df62c(Entity9A9F* p);
void EntityCF58_RequestKill(void);
s32 MainMenu_SetHudMode(s32 mode);
s32 Taiyo_LxToGauge(s32 lx);
void FUN_08238c24(void);
s32 FUN_081de2dc(Entity9A9F* p);
s32 FUN_081df604(Entity9A9F* p);
s32 FUN_081debd4(Entity9A9F* p);
s32 FUN_081df720(s32 n);
s32 FUN_081df0f8(Entity9A9F* p);
s32 FUN_081df3f0(Entity9A9F* p);
s32 FUN_081df540(Entity9A9F* p);
s32 FUN_081de7e8(Entity9A9F* p);
u32 CalcCRC16(u8* data, u32 len);
s32 FUN_081ddb14(Entity9A9F* p, u8* buf, s32 limit);
void FUN_081dc694(void);
s32 FUN_081deaf4(Entity9A9F* p);
s32 FUN_081df014(Entity9A9F* p);
s32 FUN_081df23c(Entity9A9F* p);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void MosaicFader_Stop(void);
extern u32 gMapChanging;
extern const s8 sLinkRankBonus[5][4];
void HUD_StartCountdown(u16* remainingTime);
void HUD_RemoveCountdown(void);
void Entity4B15_ShowFixedMarker(s32 playerIdx, Vec3* pos);
extern const u16 sLinkTimeLimits[3];
s32 FUN_081deef8(Entity9A9F* p);
extern bool32 gRtcReadInhibit;
void FUN_08238b04(void);
s32 FUN_081de214(Entity9A9F* p);
s32 FUN_081df398(Entity9A9F* p);
extern bool32 gSoftResetInhibit;
bool8 MessageWindow_IsOpen(void);

static inline bool8 Entity9A9F_IsIdle(Entity9A9F* p) {
  if (p->state == 0) return TRUE;
  return FALSE;
}

// idx 番のプレイヤーから受け取ったキー, 範囲外なら 0xFFFF (データなし)
static inline u16 Entity9A9F_GetRecvKey(Entity9A9F* p, s32 idx) {
  if (idx < 0) {
    return 0xFFFF;
  }
  return p->unk_44[idx];
}

// データを運ぶキーか (bit10..13 が 0b0010)
static inline bool8 Entity9A9F_IsDataKey(u16 key) {
  if ((key & 0x3C00) == 0x800) {
    return TRUE;
  }
  return FALSE;
}

// 自分のプレイヤー番号, セッションが無ければ -1
static inline s32 Entity9A9F_GetPlayerIdx(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// キーの種別 (bit10..13) が kind か
static inline bool8 Entity9A9F_IsKeyKind(u16 key, u16 kind) {
  if ((key & 0x3C00) == kind) {
    return TRUE;
  }
  return FALSE;
}

// 次に送るキーを決める
static inline void Entity9A9F_SetSendKey(Entity9A9F* p, u16 key) { p->unk_42 = key; }

// キーの種別 (bit10..13) が 0x0400 か
static inline bool8 Entity9A9F_IsKey0400(u16 key) {
  if ((key & 0x3C00) == 0x0400) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1000 か
static inline bool8 Entity9A9F_IsKey1000(u16 key) {
  if ((key & 0x3C00) == 0x1000) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1800 か
static inline bool8 Entity9A9F_IsKey1800(u16 key) {
  if ((key & 0x3C00) == 0x1800) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x1C00 か
static inline bool8 Entity9A9F_IsKey1C00(u16 key) {
  if ((key & 0x3C00) == 0x1C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2000 か
static inline bool8 Entity9A9F_IsKey2000(u16 key) {
  if ((key & 0x3C00) == 0x2000) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2C00 か
static inline bool8 Entity9A9F_IsKey2C00(u16 key) {
  if ((key & 0x3C00) == 0x2C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x0C00 か
static inline bool8 Entity9A9F_IsKey0C00(u16 key) {
  if ((key & 0x3C00) == 0x0C00) {
    return TRUE;
  }
  return FALSE;
}

// キーの種別 (bit10..13) が 0x2800 か
static inline bool8 Entity9A9F_IsKey2800(u16 key) {
  if ((key & 0x3C00) == 0x2800) {
    return TRUE;
  }
  return FALSE;
}

// 参加人数, セッションが無ければ -1
static inline s32 Entity9A9F_GetRecordCount(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->recordCount;
}

// 受信できたキーの数が参加人数と一致するか
static inline bool8 Entity9A9F_AllKeysReceived(Entity9A9F* p) {
  s32 count = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (Entity9A9F_GetRecvKey(p, i) != 0xFFFF) {
      count++;
    }
  }
  if (count == p->recordCount) {
    return TRUE;
  }
  return FALSE;
}

Entity9A9F* GetEntity9A9F(void) { return gEntity9A9F; }

void ClearEntity9A9F(void) { gEntity9A9F = NULL; }

// 状態番号と状態関数を入れ替えて、経過フレームを 0 に戻す
void Entity9A9F_SetState(Entity9A9F* p, u8 state, void* fn) {
  p->state = state;
  p->updateCallback = fn;
  p->stateTimer = 0;
  p->unk_22 = 1;
}

s32 FUN_081dd9d4(Entity9A9F* p) {
  if (p->unk_22 != 0) {
    p->unk_22 = 0;
    return 1;
  }
  return 0;
}

void FUN_081dd9f0(Entity9A9F* p) {
  s32 i;

  p->unk_7e = 0;
  for (i = 0; i < 4; i++) {
    p->unk_80[i] = 0;
  }
}

// unk_50 と unk_51 のどちらが立っているかを入れ替える
void FUN_081dda10(Entity9A9F* p) {
  if (p->unk_50 == 0) {
    p->unk_50 = 1;
    p->unk_51 = 0;
  } else {
    p->unk_50 = 0;
    p->unk_51 = 1;
  }
}

// 全員の太陽センサーの値をゲージに直して unk_60 に入れ, 平均を luxAverage に入れる
// 残差: 命令列は一致, gEntity9A9F の値を原典は r1 に読み添字を r0 で組むが, こちらは逆のレジスタになる (読み出しを NULL なら 0 の static inline にしても同じ)
NON_MATCH void FUN_081dda38(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 i;

  p->luxSum = 0;
  for (i = 0; i < p->recordCount; i++) {
    Entity9A9F* e = gEntity9A9F;
    s32 lux = (e != NULL) ? e->lux[e->unk_51][i] : 0;

    p->unk_60[i] = Taiyo_LxToGauge(lux);
    p->luxSum += lux;
  }
  if (p->recordCount == 0) {
    p->luxAverage = 0;
  } else {
    p->luxAverage = Div(p->luxSum, p->recordCount);
  }
#else
  INCFUNC("asm/func/FUN_081dda38.inc");
#endif
}

// 自分の受信番号が正しく, 再試行が続いておらず, 全員分のキーが届いていれば 0, そうでなければ -1
s32 FUN_081ddab4(Entity9A9F* p) {
  if (p->unk_4c < 0 || p->unk_4c != p->playerIdx || p->retryTimer > 14 || !Entity9A9F_AllKeysReceived(p)) {
    return -1;
  }
  return 0;
}

// buf から1バイトずつ送信データを組む, limit に届いたら 1
// 残差はレジスタ割当だけ (36 対 36), 原典は &unk_7e を r12 に逃がして limit を r2 に残すが, こちらは limit を r5 に写して &unk_7e を低レジスタに置く
// u16* のローカルに退避する形は試済
NON_MATCH s32 FUN_081ddb14(Entity9A9F* p, u8* buf, s32 limit) {
#ifdef NONMATCHING_C
  if (p->unk_7e >= limit) {
    return 1;
  }
  if (p->unk_48 < 0) {
    return 0;
  }

  p->unk_42 = buf[p->unk_7e] | ((p->unk_7e & 3) << 8) | 0x800;
  p->unk_7e++;
  if (p->unk_7e >= limit) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081ddb14.inc");
#endif
}

// idx 番のプレイヤーから届いたキーを順番どおりなら buf に積む, count 個そろっていれば 1
s32 FUN_081ddb5c(Entity9A9F* p, u8* buf, s32 idx, s32 count) {
  u8* dst;
  u16 key;

  if (p->unk_80[idx] >= count) {
    return 1;
  }

  dst = buf + p->unk_80[idx];
  key = Entity9A9F_GetRecvKey(p, idx);
  if (Entity9A9F_IsDataKey(key) && ((key & 0x300) >> 8) == (p->unk_80[idx] & 3)) {
    *dst = key;
    p->unk_80[idx]++;
    if (p->unk_80[idx] >= count) {
      return 1;
    }
  }
  return 0;
}

void FUN_081ddbdc(Entity9A9F* p) {
  p->recordCount = 0;
  p->prevState = p->state;
  Entity9A9F_SetState(p, 0, FUN_081de130);
  EntityCF58_RequestKill();
  Sio_Disconnect();
}

// unk_118 の先頭 recordCount 件に添字を入れ, 残りを 4 で埋める
void FUN_081ddc04(Entity9A9F* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    p->unk_118[i] = i;
  }
  for (; i < 5; i++) {
    p->unk_118[i] = 4;
  }
}

// 各プレイヤーのこの回の得点を unk_130 に, 累計を unk_138 に入れる (0..9999), 参加していない枠は 0xFFFF
// 残差は末尾のループだけ: 原典は参加していない枠を ldrh/orrs/strh で 0xFFFF にするが, こちらは定数の strh に畳まれる
NON_MATCH void FUN_081ddc3c(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    s32 total;

    p->unk_130[i] = FUN_081df720(i) * 16 + p->unk_120[i] * 9 - p->unk_128[i] * 4;
    if (p->unk_130[i] < 0) {
      p->unk_130[i] = 0;
    }
    if (p->unk_130[i] > 9999) {
      p->unk_130[i] = 9999;
    }
    total = p->unk_138[i] + p->unk_130[i];
    if (total > 9999) {
      p->unk_138[i] = 9999;
    } else {
      p->unk_138[i] = total;
    }
  }
  for (; i < 4; i++) {
    p->unk_130[i] |= 0xFFFF;
    p->unk_138[i] |= 0xFFFF;
  }
#else
  INCFUNC("asm/func/FUN_081ddc3c.inc");
#endif
}

// 今回の得点 unk_130 の高い順に順位を付け, 順位と人数で決まる点 (同順位は頭割り) を累計 unk_144 に足す
// 下書き (201/200命令): 流れは一致, レジスタ割当が違いスタックが 4 バイト多い
NON_MATCH void FUN_081ddcfc(Entity9A9F* p) {
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
    scores[i] = p->unk_130[i];
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
    s32 points = p->unk_154[rk];
    s32 bonus = FixToInt(6, Div(p->unk_140 * sLinkRankBonus[n][rk], 20));

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
    p->unk_144[who] += points;
  }
#else
  INCFUNC("asm/func/FUN_081ddcfc.inc");
#endif
}

// 各レコードの36バイトを bodies[] へ写す
void FUN_081dde98(Entity9A9F* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    Entity9A9FRecord* rec = &p->records[i];
    Entity9A9FRecordBody* dst = &p->bodies[i];

    *dst = rec->body;
  }
}

void FUN_081dded4(Entity9A9F* p) {
  s32 i;

  p->unk_32 = p->unk_30;
  p->stateTimer = 0;
  FUN_081ddc04(p);
  for (i = 0; i < 4; i++) {
    p->unk_120[i] = 0;
    p->unk_128[i] = 0;
    p->unk_130[i] = 0;
    gLinkKeyInput[i] = 0x3FF;
  }
  p->unk_140 = 0;
  p->unk_52 = 0;
  p->unk_53 = 0;
  FUN_081dde98(p);
  gRandTableIdx = p->records[0].randSeed & 0x3FF;
}

// recordCount と unk_38 / unk_3a を引数にして scriptID_2dc のスクリプトを起動する
void FUN_081ddf44(Entity9A9F* p) {
  ScriptArgs args;
  u32 argv[3];

  if (p->scriptID_2dc != 0) {
    argv[0] = p->recordCount;
    argv[1] = p->unk_38;
    argv[2] = p->unk_3a;
    args.argc = 3;
    args.argv = argv;
    VM_ExecByID(p->scriptID_2dc, &args);
  }
}

// 上限に達しているルールの値を 0 に戻す
void FUN_081ddf84(Entity9A9F* p) {
  static const s32 sEntity9A9FLimits[3] = {2, 3, 4};  // 0x085AE3E8
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->rules.values[i] >= sEntity9A9FLimits[i]) {
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

// unk_78 に 0 以外があるか
s32 FUN_081de004(Entity9A9F* p) {
  s32 i;

  for (i = 0; i < p->recordCount; i++) {
    if (p->unk_78[i]) {
      return 1;
    }
  }

  return 0;
}

// 自分の記録に名前, 乱数の種, 操作設定, 太陽スタンドを書く, 乱数の種は親機 (unk_1d == 0) だけが時計から作る
void FUN_081de02c(Entity9A9F* p) {
  Entity9A9FRecord* rec = &p->self;
  char* name = gStat->name;
  s32 i;

  for (i = 0; i < 16; i++) {
    rec->name[i] = name[i];
  }
  rec->randSeed = (p->unk_1d == 0) ? gClock.second * 15 + gClock.frame : 0;
  rec->unk_12 = 100;
  rec->controlUp = gStat->controlUp;
  rec->unk_18 = gStat->solarStand;
}

void FUN_081de090(Entity9A9F* p) {
  FUN_081de02c(p);
  p->rulesOut.values[0] = 0;
  p->rulesOut.values[1] = 0;
  p->rulesOut.values[2] = 0;
  ClearMemory(p->self.unk_40, 4);
  p->self.unk_17 = 0xFF;
  p->self.unk_44 = Time_GetSpanOfTime();
}

// 残差: 原典は unk_118 を &unk_118[4] から下へ動くポインタと別の数え役で埋めるが, こちらは添字のまま [base + i] で書く
NON_MATCH void FUN_081de0dc(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 4; i >= 0; i--) {
    p->unk_118[i] = 4;
  }
  for (i = 0; i < 4; i++) {
    p->unk_120[i] = 0;
    p->unk_128[i] = 0;
    p->unk_130[i] = 0;
    p->unk_138[i] = 0;
    p->unk_144[i] = 0;
  }
  p->unk_140 = 0;
#else
  INCFUNC("asm/func/FUN_081de0dc.inc");
#endif
}

// 切断を知らせる画面を出し, メッセージ窓が開いたら終了のメッセージを流す
s32 FUN_081de130(Entity9A9F* p) {
  if ((u8)FUN_081dd9d4(p)) {
    gUseLinkInput = FALSE;
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    p->unk_54[1] = 0;
    p->unk_42 = 0x4000;
    p->windowID = TextPanel_Create(1, 7, 28, 6);
    Sound_FadeOutBGM(1);
    Marquee_CloseGlobal();
    ClearBGTilemapBuffer(0);
  }

  if (p->unk_54[1] == 0 && MessageWindow_IsOpen()) {
    p->unk_54[1] = 1;
    MainMenu_SetHudMode(5);
    TextPanel_SetScript(p->windowID, p->unk_2ec);
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
NON_MATCH s32 FUN_081de214(Entity9A9F* p) {
#ifdef NONMATCHING_C
  if ((u8)FUN_081dd9d4(p)) {
    p->unk_23 = 0;
  }

  if (p->unk_23 == 3) {
    Entity9A9F_SetState(p, 2, FUN_081de250);
    p->unk_23 = 0;
  }
#else
  INCFUNC("asm/func/FUN_081de214.inc");
#endif
}

// 接続を試み, つながれば state 3 へ, 30回失敗したら切断して state 2 からやり直す, 原典は最後の return を書き忘れている
s32 FUN_081de250(Entity9A9F* p) {
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    FUN_08238c24();
    for (i = 0; i < 4; i++) {
      if (p->unk_68[i] != 0) {
        p->unk_68[i] = 1;
      }
    }
    p->retryFrames = 0;
  }

  if (p->stateTimer > 2) {
    s32 id = Sio_Connect();

    if (id >= 0) {
      p->unk_1d = id;
      Entity9A9F_SetState(p, 3, FUN_081de2dc);
      return 0;
    }
    if (++p->retryFrames >= 30) {
      Entity9A9F_SetState(p, 2, FUN_081de250);
      Sio_Disconnect();
      for (i = 0; i < 4; i++) {
        p->unk_68[i] = 0;
      }
    }
  }
}

// 自分の番号へのデータが届いたら state 4 へ, 30 フレーム届かなければ切断して state 2 からやり直す
s32 FUN_081de2dc(Entity9A9F* p) {
  u16 recv[4];
  s32 result;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    p->retryFrames = 0;
  }

  result = Sio_PeekRecvData(recv);
  if (p->unk_4c >= 0 && result >= 0 && recv[p->unk_4c] != 0xFFFF) {
    Entity9A9F_SetState(p, 4, FUN_081de360);
  } else if (++p->retryFrames >= 30) {
    Entity9A9F_SetState(p, 2, FUN_081de250);
    Sio_Disconnect();
    for (i = 0; i < 4; i++) {
      p->unk_68[i] = 0;
    }
  }
  return 0;
}

NAKED s32 FUN_081de360(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de360.inc"); }

// 自分の記録を送り全員の記録を受け取る, 親機は全部そろったらキー 0x1800 を送り, それが届いたら state 6 へ, 原典は最後の return を書き忘れている
s32 FUN_081de6f0(Entity9A9F* p) {
  s32 count;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    FUN_081dd9f0(p);
    FUN_081de02c(p);
    FUN_081ddc04(p);
    p->self.crc = CalcCRC16((u8*)&p->self, 0x46);
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (Entity9A9F_IsKey1800(p->unk_44[0])) {
    FUN_081dde98(p);
    Entity9A9F_SetState(p, 6, FUN_081de7e8);
    return 0;
  }

  FUN_081ddb14(p, (u8*)&p->self, sizeof(Entity9A9FRecord));
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    if ((u8)FUN_081ddb5c(p, (u8*)&p->records[i], i, sizeof(Entity9A9FRecord)) == 1) {
      CalcCRC16((u8*)&p->records[i], 0x46);
      count++;
    }
  }
  if (count == p->recordCount && p->unk_1d == 0) {
    Entity9A9F_SetSendKey(p, 0x1800);
  }
  if (p->stateTimer > 3600) {
    FUN_081ddbdc(p);
    return -1;
  }
}

s32 FUN_081de7e8(Entity9A9F* p) {
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (p->stateTimer > 120) {
    if (gEntity9A9F != NULL && gEntity9A9F->playerIdx == 0) {
      Entity9A9F_SetState(p, 7, FUN_081de844);
    } else {
      Entity9A9F_SetState(p, 8, FUN_081de960);
    }
  }
  return 0;
}

// 親機の選択を待つ: キー 0x1C00 なら state 9 (ルールの受け渡し), キー 0x400 なら state 4 へ戻る, 親機は unk_23 に応じてキーを送る
s32 FUN_081de844(Entity9A9F* p) {
  if ((u8)FUN_081dd9d4(p)) {
    FUN_081dc694();
    VM_ExecByID(p->unk_2ea, NULL);
    if (Entity9A9F_GetPlayerIdx() == 0) {
      sound_08240264(0xA8);
    }
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (Entity9A9F_IsKey1C00(p->unk_44[0])) {
    Entity9A9F_SetState(p, 9, FUN_081de9d8);
  } else if (Entity9A9F_IsKey0400(p->unk_44[0])) {
    Entity9A9F_SetState(p, 4, FUN_081de360);
    if (Entity9A9F_GetPlayerIdx() == 0) {
      Sound_FadeOutBGM(1);
    }
  } else if (Entity9A9F_GetPlayerIdx() == 0 && p->unk_23 != 0) {
    if (p->unk_23 == 1) {
      Entity9A9F_SetSendKey(p, 0x1C00);
    } else if (p->unk_23 == 2) {
      Entity9A9F_SetSendKey(p, 0x400);
      VM_ExecByID(p->unk_2e8, NULL);
    }
    p->unk_23 = 0;
  }
  return 0;
}

// 残差6命令, 原典は通信ステータスの比較結果を 0/1 に起こしてから if で見るが agbcc は条件を直接分岐に畳む (Mover_ShowTrackingMarker / FUN_080fc174 と同じ), static inline (if/else で return) は試済
// ステータス比較を bool8 を返す static inline にすると 0/1 の作り置きは出るが, 比べる定数を原典はマスクの後で作るのに対しこちらは先に作る (52/52)
NON_MATCH s32 FUN_081de960(Entity9A9F* p) {
#ifdef NONMATCHING_C
  u16* status;

  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  status = p->unk_44;
  if ((*status & 0x3C00) == 0x1C00) {
    Entity9A9F_SetState(p, 9, FUN_081de9d8);
    return 0;
  }

  if ((*status & 0x3C00) == 0x400) {
    Entity9A9F_SetState(p, 4, FUN_081de360);
    return 0;
  }
#else
  INCFUNC("asm/func/FUN_081de960.inc");
#endif
}

// 親機がルールを送り, 全員が受け取ったら乱数の種とルールを反映して state 10 へ, 原典は最後の return を書き忘れている
s32 FUN_081de9d8(Entity9A9F* p) {
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    FUN_081dd9f0(p);
    if (Entity9A9F_GetPlayerIdx() == 0) {
      p->rulesOut.crc = CalcCRC16(p->rulesOut.values, 6);
    }
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (Entity9A9F_GetPlayerIdx() == 0) {
    FUN_081ddb14(p, (u8*)&p->rulesOut, sizeof(Entity9A9FRules));
  }
  if ((u8)FUN_081ddb5c(p, (u8*)&p->rules, 0, sizeof(Entity9A9FRules)) == 1) {
    CalcCRC16(p->rules.values, 6);
    Entity9A9F_SetState(p, 10, FUN_081deaf4);
    Marquee_CloseGlobal();
    ClearBGTilemapBuffer(0);
    FUN_081ddf84(p);
    gRandTableIdx = p->records[0].randSeed & 0x3FF;
    p->unk_38 = p->rules.values[2];
    if (p->unk_38 > 2) {
      p->unk_38 = Mod(Random(), 3);
    }
    FUN_081ddf44(p);
    for (i = 0; i < 4; i++) {
      gLinkKeyInput[i] = 0x3FF;
    }
    return 0;
  }
}

// 全員から種別 0x2000 のキーが届いたら state 11 へ, 原典は最後の return を書き忘れている
// 残差: 原典は種別の定数 0x2000 をループ内で毎回作るが, こちらはループ外へ出して r12 に置く (FUN_081df568 と同じ)
NON_MATCH s32 FUN_081deaf4(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  gUseLinkInput = TRUE;
  if ((u8)FUN_081dd9d4(p)) {
    Sound_FadeOutBGM(1);
  }
  if (p->stateTimer == 1) {
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    if (Entity9A9F_IsKeyKind(Entity9A9F_GetRecvKey(p, i), 0x2000)) {
      count++;
    }
  }
  if (count == n) {
    Entity9A9F_SetState(p, 11, FUN_081debd4);
    return 0;
  }
  if (p->stateTimer >= 10) {
    p->unk_42 = 0x2000;
    CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  }
#else
  INCFUNC("asm/func/FUN_081deaf4.inc");
#endif
}

void FUN_081debc0(Entity9A9F* p) { Entity9A9F_SetState(p, 12, FUN_081dec1c); }

s32 FUN_081debd4(Entity9A9F* p) {
  gUseLinkInput = TRUE;

  if ((u8)FUN_081dd9d4(p)) {
    EntityCF58_CreateWithCallback(0, 0, FUN_081debc0, p);
  }

  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
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
NON_MATCH s32 FUN_081dec1c(Entity9A9F* p) {
#ifdef NONMATCHING_C
  u16 keys;
  s32 flags;
  s32 i;
  s32 bit;

  gUseLinkInput = TRUE;
  if ((u8)FUN_081dd9d4(p)) {
    p->unk_32 = sLinkTimeLimits[p->rules.values[1]];
    p->unk_54[0] = gStat->lx;
    HUD_StartCountdown((u16*)&p->unk_32);
    for (i = 0; i < Entity9A9F_GetRecordCount(); i++) {
      if (gPlayerPtr[i] != NULL) {
        Player_Unlock(gPlayerPtr[i]);
      }
    }
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  keys = REG_KEYINPUT & ~(SELECT_BUTTON | START_BUTTON);
  flags = 0;
  for (i = 0; i < p->recordCount; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKey0C00(key)) {
      gLinkKeyInput[i] = (key & 0x3FF) | SELECT_BUTTON | START_BUTTON;
      p->lux[p->unk_50][i] |= ((key >> 2) & 1) << p->unk_52;
      if (i == 0) {
        flags = 1;
        if (key & 8) {
          flags = 3;
        }
      }
    } else {
      if (key == 0xFFFF) {
        FUN_081ddbdc(p);
        return -1;
      }
      if (i == p->playerIdx && Entity9A9F_IsKey2800(key)) {
        Entity9A9F_SetState(p, 13, FUN_081deef8);
        return 0;
      }
    }
  }

  if (flags & 1) {
    p->unk_52++;
  }
  if (flags & 2) {
    FUN_081dda10(p);
    FUN_081dda38(p);
    p->unk_52 = 0;
    p->unk_54[0] = gStat->lx;
    for (i = 0; i < p->recordCount; i++) {
      p->lux[p->unk_50][i] = 0;
    }
  }

  if (p->unk_32 == 1800 || p->unk_32 == 900) {
    for (i = 0; i < p->recordCount; i++) {
      if (FUN_081df720(i) > 2) {
        Entity4B15_ShowFixedMarker(i, &gPlayerPtr[i]->mover.pos);
      }
    }
  }

  if (p->unk_32 <= 0) {
    HUD_RemoveCountdown();
    Entity9A9F_SetSendKey(p, 0x2800);
    Entity9A9F_SetState(p, 13, FUN_081deef8);
    return 0;
  }

  if (Entity9A9F_GetPlayerIdx() == 0 && p->unk_53 == 7) {
    keys |= START_BUTTON;
  }
  bit = (gEntity9A9F != NULL) ? (gEntity9A9F->unk_54[0] >> gEntity9A9F->unk_53) & 1 : 0;
  keys |= bit << 2;
  p->unk_53 = (p->unk_53 + 1) & 7;
  Entity9A9F_SetSendKey(p, (0xC00 | keys) & 0x3FFF);
  p->unk_32--;
  return 0;
#else
  INCFUNC("asm/func/FUN_081dec1c.inc");
#endif
}

// 対戦開始: 参加回数を数え, 全員から種別 0x1000 の 0 番のキーが届いたら得点を計算して state 14 へ, 原典は最後の return を書き忘れている
// 残差: 原典は linkBattleCount の2つ目の式で gStat を読み直し, キー種別の定数をループ内で作る (FUN_081df568 と同じ), p は r5 に置く
NON_MATCH s32 FUN_081deef8(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    Sound_StopAll();
    EntityCF58_CreateWithCallback(1, 0, NULL, p);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    MosaicFader_Stop();
    gUseLinkInput = FALSE;
    gStat->linkBattleCount = (gStat->linkBattleCount < 0) ? 0 : gStat->linkBattleCount;
    gStat->linkBattleCount = (gStat->linkBattleCount + 1 > 9999) ? 9999 : gStat->linkBattleCount + 1;
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKeyKind(key, 0x1000) && (key & 0x3F) == 0) {
      count++;
    }
  }
  if (count == n) {
    Entity9A9F_SetState(p, 14, FUN_081df014);
    p->unk_21 = 0;
    FUN_081ddc3c(p);
    FUN_081ddcfc(p);
    return 0;
  }
  if (p->stateTimer >= 90) {
    p->unk_42 = 0x1000;
  }
#else
  INCFUNC("asm/func/FUN_081deef8.inc");
#endif
}

// 全員から種別 0x2C00 のキーがそろったら, 全員が 0 以外なら state 17, そうでなければ state 20 へ, そろうまでは自分の選択 unk_24 を送る
// 残差: 原典はキー種別の比較定数を比較の直前に毎回作り, ループ外へ出さない (キーがビットフィールドで定数が combine で後から生まれる形かもしれない), 加えて count と i のレジスタが入れ替わる
NON_MATCH s32 FUN_081df014(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 yes;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    VM_ExecByID(p->unk_2e2, NULL);
    p->unk_24 = -1;
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  count = 0;
  yes = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKeyKind(key, 0x2C00)) {
      if (key & 0x3F) {
        yes++;
      }
      count++;
    }
  }

  if (count == n) {
    if (count == yes) {
      Entity9A9F_SetState(p, 17, FUN_081df0f8);
    } else {
      Entity9A9F_SetState(p, 20, FUN_081df3f0);
    }
  } else if (p->unk_24 >= 0) {
    p->unk_42 = (0x2C00 | p->unk_24) & 0x3FFF;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081df014.inc");
#endif
}

// 全員から 0x10A5 のキーが届いたら state 18 へ, unk_25 が立っていれば最初の1回だけ確認のメッセージを出し, 0x10A5 を送り続ける
// 残差: 原典は FUN_081ddab4 の戻り値を r1 に写してから比べ, キー種別の定数をループ内で作る (FUN_081df568 と同じ), count と i のレジスタも違う
NON_MATCH s32 FUN_081df0f8(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 n;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    p->unk_25 = 0;
    p->unk_26 = 0;
    if (gEntity9A9F != NULL) {
      gEntity9A9F->unk_54[2] = 1;
    }
    if (p->unk_2de != 0) {
      VM_ExecByID(p->unk_2de, NULL);
    }
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKeyKind(key, 0x1000) && (key & 0xFF) == 0xA5) {
      count++;
    }
  }
  if (count == n) {
    Entity9A9F_SetState(p, 18, FUN_081df23c);
    return 0;
  }

  if (p->unk_25 != 0) {
    if (p->unk_26 == 0) {
      FUN_0823ce68(0, 1, 4, 4, 4, 0xFFFF, 0);
      MainMenu_SetHudMode(5);
      p->windowID = TextPanel_Create(1, 7, 28, 6);
      TextPanel_SetScript(p->windowID, p->unk_2f0);
      TextPanel_SetMessage(p->windowID, 9);
      TextPanel_Start(p->windowID);
      p->unk_26 = 1;
    }
    p->unk_42 = 0x10A5;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081df0f8.inc");
#endif
}

// 対戦後に自分の記録を作り直して全員と交換する, 親機は全部そろったらキー 0x1800 を送り, それが届いたら state 19 へ, 原典は最後の return を書き忘れている
// 残差: 命令列は一致, Random() の表のアドレスを原典は gRandTableIdx の番地を置いていた r2 に読むが, こちらは r1 に読む
NON_MATCH s32 FUN_081df23c(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  if ((u8)FUN_081dd9d4(p)) {
    FUN_081dd9f0(p);
    FUN_081de02c(p);
    FUN_081ddc04(p);
    if (Entity9A9F_GetPlayerIdx() == 0) {
      p->self.randSeed = gClock.second * 15 + gClock.frame;
      p->self.unk_16 = (p->rules.values[2] > 2) ? Mod(Random(), 3) : p->rules.values[2];
    }
    p->self.crc = CalcCRC16((u8*)&p->self, 0x46);
  }
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (Entity9A9F_IsKey1800(p->unk_44[0])) {
    FUN_081dde98(p);
    Entity9A9F_SetState(p, 19, FUN_081df398);
    return 0;
  }

  FUN_081ddb14(p, (u8*)&p->self, sizeof(Entity9A9FRecord));
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    if ((u8)FUN_081ddb5c(p, (u8*)&p->records[i], i, sizeof(Entity9A9FRecord)) == 1) {
      CalcCRC16((u8*)&p->records[i], 0x46);
      count++;
    }
  }
  if (count == p->recordCount && Entity9A9F_GetPlayerIdx() == 0) {
    Entity9A9F_SetSendKey(p, 0x1800);
  }
#else
  INCFUNC("asm/func/FUN_081df23c.inc");
#endif
}

// 待機が明けたら画面を消してスクリプトを流し, state 10 へ進む
s32 FUN_081df398(Entity9A9F* p) {
  FUN_081dd9d4(p);

  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (p->stateTimer > 119) {
    ClearBGTilemapBuffer(0);
    FUN_081dded4(p);
    p->unk_38 = p->records[0].unk_16;
    FUN_081ddf44(p);
    Entity9A9F_SetState(p, 10, FUN_081deaf4);
  }
}

s32 FUN_081df3f0(Entity9A9F* p) {
  if ((u8)FUN_081dd9d4(p)) {
    p->windowID = TextPanel_Create(1, 7, 28, 6);
    TextPanel_SetScript(p->windowID, p->unk_2f0);
    TextPanel_SetMessage(p->windowID, 10);
    TextPanel_Start(p->windowID);
  }

  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  if (p->stateTimer > 119) {
    Entity9A9F_SetState(p, 21, FUN_081df460);
  }
}

// 全員から種別 0x1000 の 1 番のキーが届いたら state 22 へ, unk_29 が立っていれば 60 フレーム待ってからキー 0x1001 を送る, 原典は最後の return を書き忘れている
// 残差: 原典はキー種別の比較定数を比較の直前に毎回作り, ループ外へ出さない (キーがビットフィールドで定数が combine で後から生まれる形かもしれない), 加えて count と i のレジスタが入れ替わる
NON_MATCH s32 FUN_081df460(Entity9A9F* p) {
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
  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  count = 0;
  n = p->recordCount;
  for (i = 0; i < n; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKeyKind(key, 0x1000) && (key & 0x3F) == 1) {
      count++;
    }
  }
  if (count == n) {
    Entity9A9F_SetState(p, 22, FUN_081df540);
  }

  if (p->unk_29 != 0) {
    if (p->unk_27 >= 60) {
      p->unk_42 = 0x1001;
    } else {
      p->unk_27++;
    }
  }
#else
  INCFUNC("asm/func/FUN_081df460.inc");
#endif
}

s32 FUN_081df540(Entity9A9F* p) {
  FUN_081dd9d4(p);
  if (p->unk_2a) {
    Entity9A9F_SetState(p, 23, FUN_081df568);
  }
}

// 全員から種別 0x1000 の 2 番のキーが届いたら state 24 へ, 受信番号が不正か 180 フレーム経ったら切断する, 原典は最後の return を書き忘れている
// 残差: 原典は種別の定数 0x1000 をループ内で毎回作り, count を r6, i を r5 に置くが, こちらは定数をループ外へ出す
NON_MATCH s32 FUN_081df568(Entity9A9F* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  FUN_081dd9d4(p);
  count = 0;
  for (i = 0; i < p->recordCount; i++) {
    u16 key = Entity9A9F_GetRecvKey(p, i);

    if (Entity9A9F_IsKeyKind(key, 0x1000) && (key & 0x3F) == 2) {
      count++;
    }
  }

  if (count == p->recordCount) {
    Entity9A9F_SetState(p, 24, FUN_081df604);
  } else if (p->unk_4c == -2 || p->unk_4c == -1 || p->stateTimer >= 180) {
    FUN_081ddbdc(p);
    return -1;
  }
  p->unk_42 = 0x1002;
#else
  INCFUNC("asm/func/FUN_081df568.inc");
#endif
}

s32 FUN_081df604(Entity9A9F* p) {
  FUN_081dd9d4(p);
  if (p->unk_2b) {
    Entity9A9F_SetState(p, 25, FUN_081df62c);
  }
}

s32 FUN_081df62c(Entity9A9F* p) {
  if ((u8)FUN_081dd9d4(p)) {
    MainMenu_SetHudMode(7);
    p->killRequested = 1;
  }
}

s32 FUN_081e1984(unknown* param_1, s32 val);  // src/link_battle_coin.c

// unk_118 から val の枠を全部解放する
s32 FUN_081df64c(unknown* param_1, s32 val) {
  Entity9A9F* p = gEntity9A9F;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->unk_118[i] == val) {
      FUN_081e1984(param_1, val);
      p->unk_118[i] = -1;
    }
  }
  return 0;
}

// unk_118 から val の枠を探して解放する
s32 FUN_081df698(unknown* param_1, s32 val) {
  Entity9A9F* p = gEntity9A9F;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->unk_118[i] == val) {
      FUN_081e1984(param_1, val);
      p->unk_118[i] = -1;
      break;
    }
  }
  return 0;
}

// unk_118 の空き枠 (-1) に val を入れる, 空きが無ければ 0
s32 FUN_081df6dc(s32 val) {
  Entity9A9F* p = gEntity9A9F;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < 5; i++) {
    if (p->unk_118[i] == -1) {
      p->unk_118[i] = val;
      return 1;
    }
  }
  return 0;
}

// unk_118 の5要素のうち n と等しいものの個数を返す
s32 FUN_081df720(s32 n) {
  Entity9A9F* p = gEntity9A9F;
  s32 count;
  s32 i;

  if (p == NULL) {
    return 0;
  }

  count = 0;
  for (i = 0; i < 5; i++) {
    if (p->unk_118[i] == n) {
      count++;
    }
  }
  return count;
}

// '.X' の値と等しい unk_118 の個数を数え、スクリプト側へ書き戻して返す
s32 Cmd_BE46(void) {
  u8 desc[8];
  s32 count = FUN_081df720(VM_GetValue());

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, count);
  return count;
}

// playerIdx をスクリプト側へ書き戻して返す
// 残差1命令, 原典は -1 と playerIdx を別の基本ブロックで代入するが agbcc は -1 を先に作って条件付きで上書きする形に畳む, 三項/if-else/条件の反転は試済
NON_MATCH s32 Cmd_064E(void) {
#ifdef NONMATCHING_C
  u8 desc[8];
  Entity9A9F* p = gEntity9A9F;
  s32 idx = (p == NULL) ? -1 : p->playerIdx;

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, idx);
  return idx;
#else
  INCFUNC("asm/func/Cmd_064E.inc");
#endif
}

// idx 番の unk_120 を 1 増やす
s32 FUN_081df7bc(s32 idx) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }

  p->unk_120[idx]++;
  return 0;
}

// idx 番の unk_128 を 1 増やす
s32 FUN_081df7e8(s32 idx) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }

  p->unk_128[idx]++;
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
    return FUN_081df64c(&pos, val);
  } else {
    return FUN_081df698(&pos, val);
  }
}

// state が 0 以外のときだけ unk_24 を書き換えて BGM をフェードアウトする
void FUN_081df8a0(s32 val) {
  Entity9A9F* p = gEntity9A9F;

  if (p != NULL && !Entity9A9F_IsIdle(p)) {
    p->unk_24 = val;
    Sound_FadeOutBGM(1);
  }
}

void FUN_081df8d4(void) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_25 = 1;
  }
}

void FUN_081df8f0(s32 val) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_21 = val;
  }
}

void FUN_081df908(void) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_29 = 1;
  }
}

void FUN_081df924(void) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_2a = 1;
  }
}

void FUN_081df940(void) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_2b = 1;
  }
}

void FUN_081df95c(s32 val) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->unk_23 = val;
  }
}

void FUN_081df974(void) {
  if (gEntity9A9F != NULL) {
    gEntity9A9F->killRequested = 1;
  }
}

// 終了要求が立っているかどうか
bool32 FUN_081df98c(void) {
  Entity9A9F* p = gEntity9A9F;

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
  Entity9A9F* p = gEntity9A9F;

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
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->state;
}

// 通信対戦のステータス (力, 体力, 精神, 素早さ) を基本値で埋め, kind の能力だけ上げた値にする
void FUN_081dfa20(s32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility) {
  if (gEntity9A9F == NULL) {
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

NAKED s32 FUN_081dfa98(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dfa98.inc"); }

s32 Entity9A9F_Destroy(Entity9A9F* p) {
  Sio_Disconnect();
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  gUseLinkInput = FALSE;
  gGameFlags &= ~GAMEFLAG_LINK;
  gEntity9A9F = NULL;
  return 0;
}

// 0x9A9F
// 通信セッションを作る, 既にあればそれを返す, 原典は最後の return を書き忘れている
// 残差: 原典は unk_6c を -1 のレジスタと ldrh/orrs/strh で埋め, '.s' の NULL で返す 0 のブロックを1つ目の取得の直後に置く
NON_MATCH Entity9A9F* Entity9A9F_Create(void) {
#ifdef NONMATCHING_C
  Entity9A9F* p;
  s32 i;

  if (gEntity9A9F != NULL) {
    return gEntity9A9F;
  }

  gEntity9A9F = Malloc(sizeof(Entity9A9F));
  if (gEntity9A9F == NULL) {
    return NULL;
  }
  p = gEntity9A9F;
  ClearMemory(p, sizeof(Entity9A9F));
  SetEntityRoutine(p, NULL, Entity9A9F_Destroy);
  p->e.kind = ENTITY_UNK_1;
  p->e.unk_16 = 1;
  p->e.id = 0;
  AddEntity(&p->e);
  gRtcReadInhibit = TRUE;
  FUN_08238b04();
  p->playerIdx = -1;
  p->killRequested = 0;
  p->unk_44 = p->unk_6c;
  p->unk_48 = -1;
  p->unk_4c = -1;
  p->unk_50 = 0;
  p->unk_51 = 1;
  p->unk_52 = 0;
  p->unk_53 = 0;
  for (i = 0; i < 4; i++) {
    p->unk_6c[i] |= 0xFFFF;
    p->unk_68[i] = 0;
  }
  FUN_081de0dc(p);
  FUN_081de090(p);
  Entity9A9F_SetState(p, 1, FUN_081de214);
  p->prevState = 3;
  p->unk_2ea = VM_GetNamedArgValue('U', 0);
  p->unk_2e8 = VM_GetNamedArgValue('Y', 0);
  p->scriptID_2dc = VM_GetNamedArgValue('l', 0);
  p->unk_2e2 = VM_GetNamedArgValue('r', 0);
  p->unk_2de = VM_GetNamedArgValue('R', 0);
  p->unk_2e0 = VM_GetNamedArgValue('v', 0);
  p->exitScriptID = VM_GetNamedArgValue('E', 0);
  p->unk_2e4 = VM_GetNamedArgValue('b', 0);
  p->unk_30 = 7200;
  p->unk_32 = 7200;
  p->unk_3c = VM_GetNamedArgValue('L', 5000);
  if (VM_SeekToNamedArg('e')) {
    for (i = 0; i < 4; i++) {
      p->unk_154[i] = VM_GetValue();
    }
  } else {
    p->unk_154[0] = 2;
    p->unk_154[1] = 1;
    p->unk_154[2] = -1;
    p->unk_154[3] = -2;
  }

  if (!VM_SeekToNamedArg('s')) {
    return NULL;
  }
  p->unk_2ec = VM_GetPC_Proxy();
  if (p->unk_2ec == NULL) {
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
  INCFUNC("asm/func/Entity9A9F_Create.inc");
#endif
}

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
