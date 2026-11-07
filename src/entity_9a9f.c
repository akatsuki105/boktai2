#include "entity_9a9f.h"

#include "entity.h"
#include "global.h"
#include "input.h"
#include "link.h"
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

// キーの種別 (bit10..13) が kind か
static inline bool8 Entity9A9F_IsKeyKind(u16 key, u16 kind) {
  if ((key & 0x3C00) == kind) {
    return TRUE;
  }
  return FALSE;
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

NAKED void FUN_081ddcfc(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddcfc.inc"); }

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

// 上限に達している unk_2cc を 0 に戻す
void FUN_081ddf84(Entity9A9F* p) {
  static const s32 sEntity9A9FLimits[3] = {2, 3, 4};  // 0x085AE3E8
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->unk_2cc[i] >= sEntity9A9FLimits[i]) {
      p->unk_2cc[i] = 0;
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
  p->unk_2c4 = 0;
  p->unk_2c5 = 0;
  p->unk_2c6 = 0;
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

NAKED s32 FUN_081de6f0(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de6f0.inc"); }

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

NAKED s32 FUN_081de844(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de844.inc"); }

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

NAKED s32 FUN_081de9d8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de9d8.inc"); }

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

// 推測: u8[3][2]
const u8 u8_ARRAY_085ae3f4[6] = {0x10, 0x0E, 0x18, 0x15, 0x20, 0x1C};  // 0x085AE3F4

// 通信対戦のステータス (力, 体力, 精神, 素早さ) の基本値
const u8 sLinkStatBase[4] = {50, 30, 10, 40};  // 0x085AE3FA

// 種類ごとに上がる能力の値, 並びは sLinkStatBase と同じ
const u8 sLinkStatBoost[6] = {90, 60, 60, 60};  // 0x085AE3FE, 末尾2要素は 0

NAKED s32 FUN_081dec1c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dec1c.inc"); }

NAKED s32 FUN_081deef8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081deef8.inc"); }

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

NAKED s32 FUN_081df0f8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df0f8.inc"); }

NAKED s32 FUN_081df23c(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df23c.inc"); }

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
NAKED Entity9A9F* Entity9A9F_Create(void) { INCFUNC("asm/func/Entity9A9F_Create.inc"); }

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
