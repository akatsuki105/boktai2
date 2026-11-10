#include "global.h"
#include "video.h"

extern rgb555* gBGPlttBufferPointer;
extern rgb555 gBgPlttBlendBuffer[256];
extern rgb555 gObjectPlttBuffer[256];
extern rgb555* gObjPlttData;
extern s32 gObjPlttSlotCount;
extern u16 gObjPlttSlotIDs[16];

extern s32 gObjPlttSlotCursor;
extern s32 gBgBrightnessApplied;
extern s32 gObjBrightnessApplied;
extern s32 gObjPlttSlotReserved;

rgb555* GetBgPlttBlendBuffer(void) { return gBgPlttBlendBuffer; }

// パレット系の状態を初期化する, OBPバッファとスロット表を空にし、
// BGPの転送元を gBgPlttBuffer に戻して明るさとブレンド色を既定値に戻す
// 引数はどちらも使っていない
NON_MATCH void ResetPltt(rgb555* pltt, s32 val) {
#ifdef NONMATCHING_C
  rgb555* p;
  s32 i, j;

  gObjPlttSlotCursor = 0;
  gObjPlttSlotCount = 0;
  gObjPlttSlotReserved = 0;
  p = gObjectPlttBuffer;
  for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j++) {
      *p++ = 0;
    }
    gObjPlttSlotIDs[i] = 0;
  }
  gBGPlttBufferPointer = gBgPlttBuffer;
  gBgBrightness = 0x40;
  gBgBrightnessApplied = 0x40;
  gBgBrightness2 = 0x40;
  gBgPlttBlendColor = RGB(4, 4, 4);
  gBgPlttFadeRowMask = 0;
  gObjBrightness = 0x40;
  gObjBrightnessApplied = 0x40;
  gObjPlttBlendColor = RGB(4, 4, 4);
  gObjPlttFadeSkipMask = 0;
#else
  INCFUNC("asm/func/ResetPltt.inc");
#endif
}

// パーティクル用の OBP スロット (0, 1) を空にする, シーンの片付けで呼ばれる
void ResetParticlePlttSlots(void) {
  s32 i;

  gObjPlttSlotCount = 0;
  for (i = 0; i < 2; i++) {
    gObjPlttSlotIDs[i] |= 0xFFFF;
  }
}

void ResetObjPlttSlotCursor(void) {
  gObjPlttSlotCursor = gObjPlttSlotReserved + 2;
  gObjPlttSlotReserved = 0;
}

// パーティクルのパレット ID に OBP スロット (0, 1) を割り当てて番号を返す (登録済みならそのスロット、空きがなければ 0)
// このスロットは ResetParticlePlttSlots が呼ばれるまで残る
s32 AllocParticlePlttSlot(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < gObjPlttSlotCount; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (gObjPlttSlotCount > 1) return 0;

  gObjPlttSlotIDs[gObjPlttSlotCount] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[gObjPlttSlotCount * 16], 16 * sizeof(rgb555));
  return gObjPlttSlotCount++;
}

// ブレンド済みパレットに OBP スロット (2 以降) を割り当てて番号を返す, ResetObjPlttSlotCursor が毎フレーム巻き戻すのでフレーム単位の確保になる
s32 AllocBlendPlttSlot(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < gObjPlttSlotCursor; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (gObjPlttSlotCursor > 15) return 0;

  gObjPlttSlotIDs[gObjPlttSlotCursor] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[gObjPlttSlotCursor * 16], 16 * sizeof(rgb555));
  return gObjPlttSlotCursor++;
}

// 組み立て済みの BGP/OBP を DMA3 でパレット RAM に流し込む
void CommitPalette(void) {
  DmaCopy32(3, gBGPlttBufferPointer, BG_PLTT, BG_PLTT_SIZE);
  DmaCopy32(3, gObjectPlttBuffer, OBJ_PLTT, OBJ_PLTT_SIZE);
}

// BGP13,14,15 にパレット(src)をコピーする
void FUN_0822d22c(rgb555* src) { DmaCopy32(3, src, &gBgPlttBuffer[13 * 16], 48 * sizeof(rgb555)); }

// OBJ パレットに gObjBrightness の明るさと gObjPlttBlendColor へのブレンドを掛ける, gObjPlttFadeSkipMask が指す種類のパレットは除く
// 残差 441/411, 原典は除外判定を1つの条件式で組み gObjPlttFadeSkipMask を1回だけ読む, 範囲の判定が短い
// 除外判定を bool の static inline (引数で id を渡す) に出すと 401/411, ApplyBgPlttBlend の形に倣った
NON_MATCH void ApplyObjPlttBlend(void) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  if (gObjBrightness == 0x40) {
    if (gObjBrightnessApplied != 0x40) {
      for (i = 0; i < gObjPlttSlotCount; i++) {
        CpuFastCopy(&gObjPlttData[gObjPlttSlotIDs[i] * 16], &gObjectPlttBuffer[i * 16], 16 * sizeof(rgb555));
      }
    }
  } else {
    s32 half = gObjBrightness >> 1;
    s32 inv = 0x20 - half;
    rgb555* src;
    rgb555* dst;

    if (gObjPlttBlendColor == 0) {
      for (i = 0; i < 16; i++) {
        if ((gObjPlttFadeSkipMask & 1) && (gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27 || gObjPlttSlotIDs[i] == 0x117)) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 2) && (gObjPlttSlotIDs[i] == 0x2A9 || gObjPlttSlotIDs[i] == 0x27A || gObjPlttSlotIDs[i] == 0x2FA || gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27)) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x10) && (gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27 || (gObjPlttSlotIDs[i] >= 0x207 && gObjPlttSlotIDs[i] <= 0x20F))) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x20) && ((gObjPlttSlotIDs[i] >= 0x2FB && gObjPlttSlotIDs[i] <= 0x2FE) || (gObjPlttSlotIDs[i] >= 0x2CF && gObjPlttSlotIDs[i] <= 0x2D2))) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x40) && (gObjPlttSlotIDs[i] == 0x2FA || (gObjPlttSlotIDs[i] >= 0x2A5 && gObjPlttSlotIDs[i] <= 0x2AA) || (gObjPlttSlotIDs[i] >= 0x2F0 && gObjPlttSlotIDs[i] <= 0x2F4))) {
          continue;
        }
        if (i < gObjPlttSlotCount) {
          src = &gObjPlttData[gObjPlttSlotIDs[i] * 16];
        } else {
          src = &gObjectPlttBuffer[i * 16];
        }
        dst = &gObjectPlttBuffer[i * 16];
        for (j = 0; j < 16; j++) {
          u32 c = *src++;

          *dst++ = ((((c & 0x7C1F) * half) & 0xF83E0) | (((c & 0x3E0) * half) & 0x7C00)) >> 5;
        }
      }
    } else {
      for (i = 0; i < 16; i++) {
        if ((gObjPlttFadeSkipMask & 1) && (gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27 || gObjPlttSlotIDs[i] == 0x117)) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 2) && (gObjPlttSlotIDs[i] == 0x2A9 || gObjPlttSlotIDs[i] == 0x27A || gObjPlttSlotIDs[i] == 0x2FA || gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27)) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x10) && (gObjPlttSlotIDs[i] == 0x1D || gObjPlttSlotIDs[i] == 0x26 || gObjPlttSlotIDs[i] == 0x27 || (gObjPlttSlotIDs[i] >= 0x207 && gObjPlttSlotIDs[i] <= 0x20F))) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x20) && ((gObjPlttSlotIDs[i] >= 0x2FB && gObjPlttSlotIDs[i] <= 0x2FE) || (gObjPlttSlotIDs[i] >= 0x2CF && gObjPlttSlotIDs[i] <= 0x2D2))) {
          continue;
        }
        if ((gObjPlttFadeSkipMask & 0x40) && (gObjPlttSlotIDs[i] == 0x2FA || (gObjPlttSlotIDs[i] >= 0x2A5 && gObjPlttSlotIDs[i] <= 0x2AA) || (gObjPlttSlotIDs[i] >= 0x2F0 && gObjPlttSlotIDs[i] <= 0x2F4))) {
          continue;
        }
        if (i < gObjPlttSlotCount) {
          src = &gObjPlttData[gObjPlttSlotIDs[i] * 16];
        } else {
          src = &gObjectPlttBuffer[i * 16];
        }
        dst = &gObjectPlttBuffer[i * 16];
        for (j = 0; j < 16; j++) {
          u32 c = *src++;

          *dst++ = ((((c & 0x7C1F) * half + (gObjPlttBlendColor & 0x7C1F) * inv) & 0xF83E0) | (((c & 0x3E0) * half + (gObjPlttBlendColor & 0x3E0) * inv) & 0x7C00)) >> 5;
        }
      }
    }
  }
  gObjBrightnessApplied = gObjBrightness;
#else
  INCFUNC("asm/func/ApplyObjPlttBlend.inc");
#endif
}

// BGPに明るさとブレンドを掛けて gBgPlttBlendBuffer に書き、CommitPalette の転送元をそちらへ向ける
// 明るさが等倍でブレンドも無い場合だけ、加工せず gBgPlttBuffer を直接転送元にする
NON_MATCH void ApplyBgPlttBlend(void) {
#ifdef NONMATCHING_C
  rgb555* buf = GetBgPlttBlendBuffer();
  s32 level = gBgBrightness * gBgBrightness2 >> 6;
  rgb555* dst;
  rgb555* src;
  s32 half, inv;
  s32 i, j;

  if (level == 0x40) {
    gBGPlttBufferPointer = gBgPlttBuffer;
    return;
  }
  if (level == 0) {
    dst = buf;
    for (i = 0; i < 16; i++) {
      if (gBgPlttFadeRowMask & (1 << i)) {
        for (j = 0; j < 16; j++) {
          *dst++ = gBgPlttBlendColor;
        }
      } else {
        src = &gBgPlttBuffer[i * 16];
        for (j = 0; j < 16; j++) {
          *dst++ = *src++;
        }
      }
    }
    gBGPlttBufferPointer = buf;
    return;
  }

  half = gBgBrightness * gBgBrightness2 >> 7;
  inv = 0x20 - half;
  gBGPlttBufferPointer = buf;
  src = gBgPlttBuffer;
  dst = buf;
  if (gBgPlttBlendColor == 0) {
    for (i = 0; i < 16; i++) {
      if (gBgPlttFadeRowMask & (1 << i)) {
        for (j = 0; j < 16; j++) {
          u32 c = *src++;

          *dst++ = ((((c & 0x7C1F) * half) & 0xF83E0) | (((c & 0x3E0) * half) & 0x7C00)) >> 5;
        }
      } else {
        for (j = 0; j < 16; j++) {
          *dst++ = *src++;
        }
      }
    }
  } else {
    s32 rb = (gBgPlttBlendColor & 0x7C1F) * inv;
    s32 g = (gBgPlttBlendColor & 0x3E0) * inv;

    for (i = 0; i < 16; i++) {
      if (gBgPlttFadeRowMask & (1 << i)) {
        for (j = 0; j < 16; j++) {
          u32 c = *src++;

          *dst++ = (((((c & 0x7C1F) * half) + rb) & 0xF83E0) | ((((c & 0x3E0) * half) + g) & 0x7C00)) >> 5;
        }
      } else {
        for (j = 0; j < 16; j++) {
          *dst++ = *src++;
        }
      }
    }
  }
  gBgBrightnessApplied = level;
#else
  INCFUNC("asm/func/ApplyBgPlttBlend.inc");
#endif
}

// OBJ パレットを灰色にする, パレット ID 0x2FA のスロットは除く
// 残差 86/83, 原典は灰色化の定数をスロットごとの if の中で作りスタックを使わない
NON_MATCH void ApplyObjPlttGrayscale(void) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  gBGPlttBufferPointer = GetBgPlttBlendBuffer();
  for (i = 0; i < 16; i++) {
    rgb555* s;
    rgb555* d;

    if (i < gObjPlttSlotCount) {
      s = &gObjPlttData[gObjPlttSlotIDs[i] * 16];
    } else {
      s = &gObjectPlttBuffer[i * 16];
    }
    d = &gObjectPlttBuffer[i * 16];
    if (gObjPlttSlotIDs[i] != 0x2FA) {
      for (j = 0; j < 16; j++) {
        rgb555 c = *s;
        s32 sum = (c & 0x1F) + ((c & 0x3E0) >> 5) + ((c & 0x7C00) >> 10);
        s32 v = (sum >> 2) + (sum >> 4) + (sum >> 6);

        *d = RGB(v, v, v);
        s++;
        d++;
      }
    }
  }
#else
  INCFUNC("asm/func/ApplyObjPlttGrayscale.inc");
#endif
}

// BG パレットの 0..12 行を灰色にしたものを gBgPlttBlendBuffer に作って転送元にする, 13..15 行はそのまま写す
// 残差はレジスタ割当 (74/73), 原典は dst を ip に置き内側のループ数を r7 で数える
// 灰色化を static inline に出す形と添字の形は試済
NON_MATCH void ApplyBgPlttGrayscale(void) {
#ifdef NONMATCHING_C
  rgb555* dst = GetBgPlttBlendBuffer();
  s32 i;
  s32 j;

  gBGPlttBufferPointer = dst;
  for (i = 0; i < 13; i++) {
    rgb555* s = &gBgPlttBuffer[i * 16];
    rgb555* d = &dst[i * 16];

    for (j = 0; j < 16; j++) {
      rgb555 c = *s;
      s32 sum = (c & 0x1F) + ((c & 0x3E0) >> 5) + ((c & 0x7C00) >> 10);
      s32 v = (sum >> 2) + (sum >> 4) + (sum >> 6);

      *d = RGB(v, v, v);
      s++;
      d++;
    }
  }
  for (i = 0; i < 3; i++) {
    CpuCopy32(&gBgPlttBuffer[(13 + i) * 16], &dst[(13 + i) * 16], 16 * sizeof(rgb555));
  }
#else
  INCFUNC("asm/func/ApplyBgPlttGrayscale.inc");
#endif
}

// CommitPalette が転送する BGP を切り替え、OBPバッファを各スロットの割り当てから作り直す
void FUN_0822d98c(void) {
  s32 i;

  gBGPlttBufferPointer = GetBgPlttBlendBuffer();
  for (i = 0; i < gObjPlttSlotCount; i++) {
    rgb555* src = &gObjPlttData[gObjPlttSlotIDs[i] * 16];
    rgb555* dst = &gObjectPlttBuffer[i * 16];
    s32 j;

    for (j = 0; j < 16; j++) {
      *dst++ = *src++;
    }
  }
}
