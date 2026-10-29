#include "entity_9a9f.h"

#include "entity.h"
#include "global.h"
#include "input.h"
#include "link.h"
#include "sound.h"
#include "text.h"
#include "video.h"
#include "vm.h"

COMMON_DATA Entity9A9F* gEntity9A9F = NULL;  // 0x03002C68
IWRAM_DATA u32 bool32_030001ac = FALSE;      // 0x030001AC

static inline bool8 Entity9A9F_IsIdle(Entity9A9F* p) {
  if (p->state == 0) return TRUE;
  return FALSE;
}

s32 FUN_081dec1c(Entity9A9F* p);
s32 FUN_081de130(Entity9A9F* p);
void FUN_081df460(Entity9A9F*);
void EntityCF58_CreateWithCallback(s32 param_1, s32 param_2, void* fn, void* arg);
s32 FUN_081de250(Entity9A9F*);
s32 FUN_081de9d8(Entity9A9F*);
s32 FUN_081de360(Entity9A9F*);
s32 FUN_081de844(Entity9A9F*);
s32 FUN_081de960(Entity9A9F*);
void FUN_081df568(Entity9A9F* p);
s32 FUN_081df62c(Entity9A9F* p);
void EntityCF58_RequestKill(void);
s32 FUN_0809c08c(s32 mode);

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

NAKED void FUN_081dda38(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dda38.inc"); }

NAKED s32 FUN_081ddab4(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddab4.inc"); }

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

NAKED s32 FUN_081ddb5c(Entity9A9F* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_081ddb5c.inc"); }

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

NAKED void FUN_081ddc3c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddc3c.inc"); }

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

NAKED void FUN_081dded4(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dded4.inc"); }

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

NAKED void FUN_081de02c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de02c.inc"); }

void FUN_081de090(Entity9A9F* p) {
  FUN_081de02c(p);
  p->unk_2c4 = 0;
  p->unk_2c5 = 0;
  p->unk_2c6 = 0;
  ClearMemory(p->unk_19c, 4);
  p->unk_173 = 0xFF;
  p->spanOfTime = Time_GetSpanOfTime();
}

NAKED void FUN_081de0dc(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de0dc.inc"); }

NAKED s32 FUN_081de130(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de130.inc"); }

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

NAKED s32 FUN_081de250(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de250.inc"); }

NAKED s32 FUN_081de2dc(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de2dc.inc"); }

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

// 残差6命令, 原典は通信ステータスの比較結果を 0/1 に起こしてから if で見るが agbcc は条件を直接分岐に畳む (FUN_080f8bb8 / FUN_080fc174 と同じ), static inline (if/else で return) は試済
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

NAKED s32 FUN_081deaf4(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081deaf4.inc"); }

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

// 推測: u8[8][2]
const u8 u8_ARRAY_085ae3f4[16] = {0x10, 0x0E, 0x18, 0x15, 0x20, 0x1C, 0x32, 0x1E, 0x0A, 0x28, 0x5A, 0x3C, 0x3C, 0x3C, 0x00, 0x00};  // 0x085AE3F4

NAKED s32 FUN_081dec1c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dec1c.inc"); }

NAKED s32 FUN_081deef8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081deef8.inc"); }

NAKED s32 FUN_081df014(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df014.inc"); }

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

NAKED void FUN_081df460(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df460.inc"); }

s32 FUN_081df540(Entity9A9F* p) {
  FUN_081dd9d4(p);
  if (p->unk_2a) {
    Entity9A9F_SetState(p, 23, FUN_081df568);
  }
}

NAKED void FUN_081df568(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df568.inc"); }

s32 FUN_081df604(Entity9A9F* p) {
  FUN_081dd9d4(p);
  if (p->unk_2b) {
    Entity9A9F_SetState(p, 25, FUN_081df62c);
  }
}

s32 FUN_081df62c(Entity9A9F* p) {
  if ((u8)FUN_081dd9d4(p)) {
    FUN_0809c08c(7);
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

NAKED void Cmd_33C4(void) { INCFUNC("asm/func/Cmd_33C4.inc"); }

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

NAKED void FUN_081df9ac(Entity9A9F* p, s32 param_2) { INCFUNC("asm/func/FUN_081df9ac.inc"); }

s32 FUN_081dfa04(void) {
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->state;
}

NAKED void FUN_081dfa20(u32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility) { INCFUNC("asm/func/FUN_081dfa20.inc"); }

NAKED s32 FUN_081dfa98(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dfa98.inc"); }

s32 Entity9A9F_Destroy(Entity9A9F* p) {
  Sio_Disconnect();
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  gUseLinkInput = FALSE;
  gGameFlags &= ~FLAG030047A4_LINK;
  gEntity9A9F = NULL;
  return 0;
}

NAKED Entity9A9F* Entity9A9F_Create(void) { INCFUNC("asm/func/Entity9A9F_Create.inc"); }

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
