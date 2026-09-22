#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// モザイク (MOSAIC レジスタ) の強さを目標値まで1段ずつ動かす。4つのニブル (BG横/BG縦/OBJ横/OBJ縦) を別々に動かせる
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_9
  u8 mode;          // 0x18, sMosaicFaderUpdates の添字。1 = 増やす, 2 = 減らす, 0 = 停止
  u8 objEnabled;    // 0x19, Video_SetMosaic の第2引数
  u8 targets;       // 0x1A, Video_SetMosaic の第3引数
  u8 activeMask;    // 0x1B, bit0-3。まだ goalSize に届いていないニブル。0 になると mode を 0 に戻す
  u16 timer[4];     // 0x1C, ニブルごとの経過フレーム。interval に達すると size を1段進める
  u16 interval[4];  // 0x24, 1段あたりのフレーム数
  s8 size[4];       // 0x2C, 現在のモザイク量。size[i] << (i * 4) を Video_SetMosaic に渡す
  u8 goalSize[4];   // 0x30, 目標のモザイク量
} MosaicFader;
static_assert(sizeof(MosaicFader) == 52);

IWRAM_DATA MosaicFader* gMosaicFader = NULL;  // 0x03000068

void MosaicFader_UpdateIncrease(MosaicFader*);
void MosaicFader_UpdateDecrease(MosaicFader*);

void (*const sMosaicFaderUpdates[3])(MosaicFader*) = {
    NULL,
    MosaicFader_UpdateIncrease,
    MosaicFader_UpdateDecrease,
};  // 0x085AA920

void MosaicFader_ClearGlobal(void) { gMosaicFader = NULL; }

// 4つのニブルを goalSize まで1ずつ増やす
void MosaicFader_UpdateIncrease(MosaicFader* p) {
  u16 value = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    value = value | (p->size[i] << (i * 4));
    if ((p->activeMask >> i) & 1) {
      p->timer[i]++;
      if (p->timer[i] >= p->interval[i]) {
        p->timer[i] = 0;
        if (p->size[i] >= (s8)p->goalSize[i]) {
          p->size[i] = p->goalSize[i];
          p->activeMask &= ~(1 << i);
        } else {
          p->size[i] = p->size[i] + 1;
        }
      }
    }
  }
  Video_SetMosaic(value, p->objEnabled, p->targets);
  if (p->activeMask == 0) {
    p->mode = 0;
  }
}

// 4つのニブルを goalSize まで1ずつ減らす
void MosaicFader_UpdateDecrease(MosaicFader* p) {
  u16 value = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    value = value | (p->size[i] << (i * 4));
    if ((p->activeMask >> i) & 1) {
      p->timer[i]++;
      if (p->timer[i] >= p->interval[i]) {
        p->timer[i] = 0;
        if (p->size[i] <= (s8)p->goalSize[i]) {
          p->size[i] = p->goalSize[i];
          p->activeMask &= ~(1 << i);
        } else {
          p->size[i] = p->size[i] - 1;
        }
      }
    }
  }
  Video_SetMosaic(value, p->objEnabled, p->targets);
  if (p->activeMask == 0) {
    p->mode = 0;
  }
}

s32 MosaicFader_Update(MosaicFader* p) {
  if (sMosaicFaderUpdates[p->mode] != NULL) {
    sMosaicFaderUpdates[p->mode](p);
  }
}

s32 MosaicFader_Destroy(MosaicFader* p) {
  Video_ClearMosaic();
  gMosaicFader = NULL;
  return 0;
}

s32 MosaicFader_Init(MosaicFader* p, u32 param_2) {
  s32 i;

  gMosaicFader = p;
  p->mode = 0;
  p->objEnabled = 0;
  p->targets = 0;
  p->activeMask = 0;
  for (i = 0; i < 4; i++) {
    p->timer[i] = 0;
    p->interval[i] = 0;
    p->size[i] = 0;
    p->goalSize[i] = 0;
  }
}

MosaicFader* MosaicFader_Create(u32 param_1, u32 param_2) {
  MosaicFader* p;

  if (gMosaicFader != NULL) {
    return gMosaicFader;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(MosaicFader));
  if (p != NULL) {
    SetEntityRoutine(p, MosaicFader_Update, MosaicFader_Destroy);
    if (MosaicFader_Init(p, (u16)param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 4つのニブルを from から to へ interval フレームごとに1段ずつ動かし始める
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval) {
  MosaicFader* p;
  s32 i;

  if (gMosaicFader == NULL) {
    p = MosaicFader_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  } else {
    p = gMosaicFader;
  }
  p->mode = mode;
  p->objEnabled = objEnabled;
  p->targets = targets;
  p->activeMask = 0xF;
  for (i = 0; i < 4; i++) {
    p->timer[i] = 0;
    p->interval[i] = interval[i];
    p->size[i] = from[i] & 0xF;
    p->goalSize[i] = to[i] & 0xF;
  }
  return 0;
}

// モザイクをかけるスクリプトコマンド。'c' が開始値、'a' が目標値、'i' が1段あたりのフレーム数
s32 MosaicFader_StartFromScript(void) {
  u8 from[4], to[4];
  u16 interval[4];
  s32 i;
  s32 mode = VM_GetKeywordValue('m', 0);
  s32 objEnabled = VM_GetKeywordValue('f', 0);
  s32 targets = VM_GetKeywordValue('t', 0);

  if (VM_SeekToKeyword('c')) {
    for (i = 0; i < 4; i++) {
      from[i] = Script_GetValue();
    }
  } else {
    for (i = 0; i < 4; i++) {
      from[i] = 0;
    }
  }
  if (VM_SeekToKeyword('a')) {
    for (i = 0; i < 4; i++) {
      to[i] = Script_GetValue();
    }
  } else {
    for (i = 0; i < 4; i++) {
      to[i] = 0;
    }
  }
  if (VM_SeekToKeyword('i')) {
    for (i = 0; i < 4; i++) {
      interval[i] = Script_GetValue();
    }
  } else {
    for (i = 0; i < 4; i++) {
      interval[i] = 0;
    }
  }
  return MosaicFader_Start(mode, objEnabled, targets, from, to, interval);
}

// モザイクを解除して、進行中のフェードを全部止める
void MosaicFader_Stop(void) {
  MosaicFader* p = gMosaicFader;
  s32 i;

  if (p != NULL) {
    Video_ClearMosaic();
    p->mode = 0;
    p->objEnabled = 0;
    p->targets = 0;
    p->activeMask = 0;
    for (i = 0; i < 4; i++) {
      p->timer[i] = 0;
      p->interval[i] = 0;
      p->size[i] = 0;
      p->goalSize[i] = 0;
    }
  }
}
