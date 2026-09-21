#include "global.h"
#include "video.h"

extern rgb555* gBGPlttBufferPointer;
extern rgb555 gBgPlttBlendBuffer[256];
extern rgb555 gObjectPlttBuffer[256];
extern rgb555* gObjPlttData;
extern s32 gObjPlttSlotCount;
extern u16 gObjPlttSlotIDs[16];

extern s32 s32_03004040;
extern s32 gObjPlttSlotCursor;
extern s32 s32_03004048;
extern s32 s32_0300404c;
extern s32 s32_03004450;
extern u16 gBgPlttFadeRowMask;
extern s32 s32_0300445c;
extern s32 s32_03004460;
extern u16 u16_03004464;
extern u16 u16_03004490;
extern u16 gBgPlttBlendColor;

rgb555* FUN_0822d00c(void) { return gBgPlttBlendBuffer; }

// パレット系の状態を初期化する。OBJ パレットバッファとスロット表を空にし、
// BG パレットの転送元を gBgPlttBuffer に戻して明るさとブレンド色を既定値に戻す
// 引数はどちらも使っていない
NON_MATCH void FUN_0822d014(rgb555* pltt, s32 val) {
#ifdef NONMATCHING_C
  rgb555* p;
  s32 i, j;

  gObjPlttSlotCursor = 0;
  gObjPlttSlotCount = 0;
  s32_03004450 = 0;
  p = gObjectPlttBuffer;
  for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j++) {
      *p++ = 0;
    }
    gObjPlttSlotIDs[i] = 0;
  }
  gBGPlttBufferPointer = gBgPlttBuffer;
  s32_03004040 = 0x40;
  s32_03004048 = 0x40;
  s32_03004460 = 0x40;
  gBgPlttBlendColor = 0x1084;
  gBgPlttFadeRowMask = 0;
  s32_0300445c = 0x40;
  s32_0300404c = 0x40;
  u16_03004464 = 0x1084;
  u16_03004490 = 0;
#else
  INCFUNC("asm/func/FUN_0822d014.inc");
#endif
}

// FUN_0822d12c 用の OBJ パレットスロット(2 個)を空にする
void FUN_0822d0e4(void) {
  s32 i;

  gObjPlttSlotCount = 0;
  for (i = 0; i < 2; i++) {
    gObjPlttSlotIDs[i] |= 0xFFFF;
  }
}

void FUN_0822d114(void) {
  gObjPlttSlotCursor = s32_03004450 + 2;
  s32_03004450 = 0;
}

// パレット ID に OBJ パレットスロットを割り当てて番号を返す (登録済みならそのスロット、空きがなければ 0)
s32 FUN_0822d12c(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < gObjPlttSlotCount; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (gObjPlttSlotCount > 1) return 0;

  gObjPlttSlotIDs[gObjPlttSlotCount] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[gObjPlttSlotCount * 16], 16 * sizeof(rgb555));
  return gObjPlttSlotCount++;
}

// FUN_0822d12c の 16 スロット版
s32 FUN_0822d190(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < gObjPlttSlotCursor; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (gObjPlttSlotCursor > 15) return 0;

  gObjPlttSlotIDs[gObjPlttSlotCursor] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[gObjPlttSlotCursor * 16], 16 * sizeof(rgb555));
  return gObjPlttSlotCursor++;
}

// 組み立て済みの BG / OBJ パレットを DMA3 でパレット RAM に流し込む
void CommitPalette(void) {
  DmaCopy32(3, gBGPlttBufferPointer, BG_PLTT, BG_PLTT_SIZE);
  DmaCopy32(3, gObjectPlttBuffer, OBJ_PLTT, OBJ_PLTT_SIZE);
}

// BGP13,14,15 にパレット(src)をコピーする
void FUN_0822d22c(rgb555* src) { DmaCopy32(3, src, &gBgPlttBuffer[13 * 16], 48 * sizeof(rgb555)); }

NAKED void FUN_0822d248(void) { INCFUNC("asm/func/FUN_0822d248.inc"); }

// BG パレットに明るさとブレンドを掛けて gBgPlttBlendBuffer に書き、CommitPalette の転送元をそちらへ向ける
// 明るさが等倍でブレンドも無い場合だけ、加工せず gBgPlttBuffer を直接転送元にする
NON_MATCH void FUN_0822d630(void) {
#ifdef NONMATCHING_C
  rgb555* buf = FUN_0822d00c();
  s32 level = s32_03004040 * s32_03004460 >> 6;
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
      if ((gBgPlttFadeRowMask >> i) & 1) {
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

  half = s32_03004040 * s32_03004460 >> 7;
  inv = 0x20 - half;
  gBGPlttBufferPointer = buf;
  src = gBgPlttBuffer;
  dst = buf;
  if (gBgPlttBlendColor == 0) {
    for (i = 0; i < 16; i++) {
      if ((gBgPlttFadeRowMask >> i) & 1) {
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
      if ((gBgPlttFadeRowMask >> i) & 1) {
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
  s32_03004048 = level;
#else
  INCFUNC("asm/func/FUN_0822d630.inc");
#endif
}

NAKED void FUN_0822d828(void) { INCFUNC("asm/func/FUN_0822d828.inc"); }

NAKED void FUN_0822d8e8(void) { INCFUNC("asm/func/FUN_0822d8e8.inc"); }

// CommitPalette が転送する BG パレットを低速バッファに切り替え、OBJ パレットバッファを各スロットの割り当てから作り直す
void FUN_0822d98c(void) {
  s32 i;

  gBGPlttBufferPointer = FUN_0822d00c();
  for (i = 0; i < gObjPlttSlotCount; i++) {
    rgb555* src = &gObjPlttData[gObjPlttSlotIDs[i] * 16];
    rgb555* dst = &gObjectPlttBuffer[i * 16];
    s32 j;

    for (j = 0; j < 16; j++) {
      *dst++ = *src++;
    }
  }
}
