#include "entity_9a9f.h"

#include "entity.h"
#include "global.h"
#include "input.h"
#include "link.h"
#include "sound.h"
#include "text.h"
#include "video.h"
#include "vm.h"

s32 FUN_081dec1c(Entity9A9F* p);
s32 FUN_081de130(Entity9A9F* p);
void FUN_081df460(Entity9A9F*);
s32 FUN_081de250(Entity9A9F*);
s32 FUN_081de9d8(Entity9A9F*);
s32 FUN_081de360(Entity9A9F*);

s32 FUN_081de844(Entity9A9F*);
s32 FUN_081de960(Entity9A9F*);
void FUN_081df568(Entity9A9F* p);
void FUN_081df62c(Entity9A9F* p);
void FUN_080a5e4c(void);     // src/code_080917e4.s
s32 FUN_0809c08c(s32 mode);  // src/entity_cc28.c

extern const s32 sEntity9A9FLimits[3];  // 0x085AE3E8

Entity9A9F* GetEntity9A9F(void) { return gEntity9A9F; }

void ClearEntity9A9F(void) { gEntity9A9F = NULL; }

// 状態番号と状態関数を入れ替えて、経過フレームを 0 に戻す
void Entity9A9F_SetState(Entity9A9F* p, u8 state, EntityFunc* fn) {
  p->state = state;
  p->updateCallback = (void (*)(struct Entity9A9F*))fn;
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

NAKED s32 FUN_081ddb14(Entity9A9F* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_081ddb14.inc"); }

NAKED s32 FUN_081ddb5c(Entity9A9F* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_081ddb5c.inc"); }

void FUN_081ddbdc(Entity9A9F* p) {
  p->recordCount = 0;
  p->prevState = p->state;
  Entity9A9F_SetState(p, 0, (EntityFunc*)FUN_081de130);
  FUN_080a5e4c();
  FUN_08238bf4();
}

NAKED void FUN_081ddc04(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddc04.inc"); }

NAKED void FUN_081ddc3c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddc3c.inc"); }

NAKED void FUN_081ddcfc(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddcfc.inc"); }

NAKED void FUN_081dde98(Entity9A9F* p, unknown* param_2) { INCFUNC("asm/func/FUN_081dde98.inc"); }

NAKED void FUN_081dded4(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dded4.inc"); }

NAKED void FUN_081ddf44(Entity9A9F* p) { INCFUNC("asm/func/FUN_081ddf44.inc"); }

// 上限に達している unk_2cc を 0 に戻す
void FUN_081ddf84(Entity9A9F* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->unk_2cc[i] >= sEntity9A9FLimits[i]) {
      p->unk_2cc[i] = 0;
    }
  }
}

NAKED u32 FUN_081ddfb0(Entity9A9F* p, u32 param_2) { INCFUNC("asm/func/FUN_081ddfb0.inc"); }

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

NAKED void FUN_081de090(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de090.inc"); }

NAKED void FUN_081de0dc(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de0dc.inc"); }

NAKED s32 FUN_081de130(Entity9A9F* p) { INCFUNC("asm/func/FUN_081de130.inc"); }

// 残差1命令, 原典は FUN_081dd9d4 の戻り値を別レジスタへ複写してから u8 に落として判定する, ローカル退避と直接 (u8) キャストは試済
NON_MATCH void FUN_081de214(Entity9A9F* p) {
#ifdef NONMATCHING_C
  if ((u8)FUN_081dd9d4(p)) {
    p->unk_23 = 0;
  }

  if (p->unk_23 == 3) {
    Entity9A9F_SetState(p, 2, (EntityFunc*)FUN_081de250);
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
      Entity9A9F_SetState(p, 7, (EntityFunc*)FUN_081de844);
    } else {
      Entity9A9F_SetState(p, 8, (EntityFunc*)FUN_081de960);
    }
  }
  return 0;
}

NAKED s32 FUN_081de844(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de844.inc"); }

// 残差6命令, 原典は通信ステータスの比較結果を 0/1 に起こしてから if で見るが agbcc は条件を直接分岐に畳む (FUN_080f8bb8 / FUN_080fc174 と同じ), static inline (if/else で return) は試済
NON_MATCH s32 FUN_081de960(Entity9A9F* p) {
#ifdef NONMATCHING_C
  u16* status;

  if (FUN_081ddab4(p) < 0) {
    FUN_081ddbdc(p);
    return -1;
  }

  status = p->unk_44;
  if ((*status & 0x3C00) == 0x1C00) {
    Entity9A9F_SetState(p, 9, (EntityFunc*)FUN_081de9d8);
    return 0;
  }

  if ((*status & 0x3C00) == 0x400) {
    Entity9A9F_SetState(p, 4, (EntityFunc*)FUN_081de360);
    return 0;
  }
#else
  INCFUNC("asm/func/FUN_081de960.inc");
#endif
}

NAKED s32 FUN_081de9d8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081de9d8.inc"); }

NAKED s32 FUN_081deaf4(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081deaf4.inc"); }

void FUN_081debc0(Entity9A9F* p) { Entity9A9F_SetState(p, 12, (EntityFunc*)FUN_081dec1c); }

NAKED s32 FUN_081debd4(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081debd4.inc"); }

NAKED s32 FUN_081dec1c(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dec1c.inc"); }

NAKED s32 FUN_081deef8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081deef8.inc"); }

NAKED s32 FUN_081df014(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df014.inc"); }

NAKED s32 FUN_081df0f8(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df0f8.inc"); }

NAKED s32 FUN_081df23c(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df23c.inc"); }

NAKED void FUN_081df398(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df398.inc"); }

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
    Entity9A9F_SetState(p, 21, (EntityFunc*)FUN_081df460);
  }
}

NAKED void FUN_081df460(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df460.inc"); }

// 残差はレジスタ番号のみ (原典は捨てる FUN_081dd9d4 の戻り値で r0 を塞いだまま r1 を使う)
NON_MATCH void FUN_081df540(Entity9A9F* p) {
#ifdef NONMATCHING_C
  FUN_081dd9d4(p);
  if (p->unk_2a) {
    Entity9A9F_SetState(p, 23, (EntityFunc*)FUN_081df568);
  }
#else
  INCFUNC("asm/func/FUN_081df540.inc");
#endif
}

NAKED void FUN_081df568(Entity9A9F* param_1) { INCFUNC("asm/func/FUN_081df568.inc"); }

// 残差はレジスタ番号のみ (原典は捨てる FUN_081dd9d4 の戻り値で r0 を塞いだまま r1 を使う)
NON_MATCH void FUN_081df604(Entity9A9F* p) {
#ifdef NONMATCHING_C
  FUN_081dd9d4(p);
  if (p->unk_2b) {
    Entity9A9F_SetState(p, 25, (EntityFunc*)FUN_081df62c);
  }
#else
  INCFUNC("asm/func/FUN_081df604.inc");
#endif
}

// 残差は 13 命令 vs 14 命令 で、原典は戻り値を別レジスタに複写してから u8 として判定する
NON_MATCH void FUN_081df62c(Entity9A9F* p) {
#ifdef NONMATCHING_C
  if ((u8)FUN_081dd9d4(p)) {
    FUN_0809c08c(7);
    p->killRequested = 1;
  }
#else
  INCFUNC("asm/func/FUN_081df62c.inc");
#endif
}

NAKED s32 FUN_081df64c(Entity9A9F* p, s32 param_2) { INCFUNC("asm/func/FUN_081df64c.inc"); }

NAKED s32 FUN_081df698(Entity9A9F* p, s32 param_2) { INCFUNC("asm/func/FUN_081df698.inc"); }

NAKED s32 FUN_081df6dc(Entity9A9F* p) { INCFUNC("asm/func/FUN_081df6dc.inc"); }

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
s32 FUN_081df75c(void) {
  u8 desc[8];
  s32 count = FUN_081df720(VM_GetValue());

  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, count);
  return count;
}

// playerIdx をスクリプト側へ書き戻して返す
// 残差1命令, 原典は -1 と playerIdx を別の基本ブロックで代入するが agbcc は -1 を先に作って条件付きで上書きする形に畳む, 三項/if-else/条件の反転は試済
NON_MATCH s32 FUN_081df784(void) {
#ifdef NONMATCHING_C
  u8 desc[8];
  Entity9A9F* p = gEntity9A9F;
  s32 idx = (p == NULL) ? -1 : p->playerIdx;

  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, idx);
  return idx;
#else
  INCFUNC("asm/func/FUN_081df784.inc");
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

NAKED void FUN_081df814(void) { INCFUNC("asm/func/FUN_081df814.inc"); }

// state が 0 以外のときだけ unk_24 を書き換えて BGM をフェードアウトする
// 残差2命令, 原典は state == 0 を 0/1 に起こすところで分岐と b を使う (こちらは 0 を先に入れて条件付きで 1 にする短い形)
// bool32 を返す static inline を挟んでも同じ形にはならない
NON_MATCH void FUN_081df8a0(s32 val) {
#ifdef NONMATCHING_C
  Entity9A9F* p = gEntity9A9F;

  if (p != NULL && p->state != 0) {
    p->unk_24 = val;
    Sound_FadeOutBGM(1);
  }
#else
  INCFUNC("asm/func/FUN_081df8a0.inc");
#endif
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

NAKED void FUN_081dfa20(Entity9A9F* p, unknown* param_2, unknown* param_3, unknown* param_4, unknown* param_5) { INCFUNC("asm/func/FUN_081dfa20.inc"); }

NAKED s32 FUN_081dfa98(Entity9A9F* p) { INCFUNC("asm/func/FUN_081dfa98.inc"); }

s32 Entity9A9F_Destroy(Entity9A9F* p) {
  FUN_08238bf4();
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  gUseLinkInput = FALSE;
  gFlag030047a4 &= ~FLAG030047A4_LINK;
  gEntity9A9F = NULL;
  return 0;
}

NAKED Entity9A9F* Entity9A9F_Create(void) { INCFUNC("asm/func/Entity9A9F_Create.inc"); }

void FUN_081dfe5c(void) {
  if (gEntity9A9F != NULL) {
    FUN_081dfa98(gEntity9A9F);
  }
}
