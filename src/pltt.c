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
extern u16 gObjPlttFadeSkipMask;

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

NAKED void FUN_0822d248(void) { INCFUNC("asm/func/FUN_0822d248.inc"); }

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

NAKED void FUN_0822d828(void) { INCFUNC("asm/func/FUN_0822d828.inc"); }

NAKED void FUN_0822d8e8(void) { INCFUNC("asm/func/FUN_0822d8e8.inc"); }

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
