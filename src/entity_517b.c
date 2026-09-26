#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

bool32 FUN_0800271c(void);

// BGパレットバンク2の色1〜12を3色ずつ4グループに分け、グループ単位でバンク3の色へクロスフェードさせる
// 下地は savedPltt (バンク2の退避), 行き先は gBgPlttBuffer[0x30 + i] で、level がその配合比になる
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_12
  u16 litMask;           // 0x18, '.f', bit i が i 番目のグループ, mode 1 ではそのグループを 0x20 固定 (バンク3の色そのもの) にし、mode 0/2 では level に従わせる
  u16 fadeMask;          // 0x1A, '.n', mode 1 と mode 2 でだけ見る, litMask に入っていないグループのうち level に従わせるもの
  u8 mode;               // 0x1C, '.m', 0 = level を 0x10..0x20 で往復, 1 = 0 から 0x20 へ上げる, 2 = 0x20 から 0 へ下げる
  u8 unk_1d[3];          // 0x1D, padding?
  s16 level;             // 0x20, 0x00..0x20 のブレンド量, 0 で savedPltt の色, 0x20 でバンク3の色
  s16 step;              // 0x22, '.a' (mode 1 の既定 2, mode 2 の既定 1), 16フレームごとに level へ足す, mode 0 では往復のため ±1 が入る
  s32 timer;             // 0x24, BgPlttGroupFader_Update が毎フレーム +1, 下位4bitが0のフレームだけ level を動かす
  rgb555 savedPltt[16];  // 0x28, BgPlttGroupFader_SavePltt が gBgPlttBuffer[0x20..0x2F] を CpuSet で退避したもの
} BgPlttGroupFader;
static_assert(sizeof(BgPlttGroupFader) == 72);

IWRAM_DATA BgPlttGroupFader* gBgPlttGroupFader = NULL;  // 0x03000088

// グループ1つを savedPltt とバンク3の色の間で level:0x20-level に混ぜてバンク2へ書く
// src がスタックに溢れて 3命令多い, ターゲットは ip に載せている
NON_MATCH s32 BgPlttGroupFader_BlendGroup(BgPlttGroupFader* p, s32 start, s32 end, s32 level) {
#ifdef NONMATCHING_C
  rgb555* dst = &gBgPlttBuffer[32 + start];
  rgb555* src = &gBgPlttBuffer[48 + start];
  rgb555* base;
  s32 inv;
  s32 i;

  if (level > 0x1F) {
    for (i = start; i < end; i++) {
      *dst = *src;
      src++;
      dst++;
    }
  } else {
    base = &p->savedPltt[start];
    inv = 0x20 - level;
    for (i = start; i < end; i++) {
      u32 a = *base;
      u32 b = *src;
      *dst = ((((b & 0x7C1F) * level + (a & 0x7C1F) * inv) & 0xF83E0) | (((b & 0x3E0) * level + (a & 0x3E0) * inv) & 0x7C00)) >> 5;
      base++;
      src++;
      dst++;
    }
  }
#else
  INCFUNC("asm/func/BgPlttGroupFader_BlendGroup.inc");
#endif
}

// グループ1つを退避しておいた色に戻す
s32 BgPlttGroupFader_RestoreGroup(BgPlttGroupFader* p, s32 start, s32 end) {
  rgb555* src = &p->savedPltt[start];
  rgb555* dst = &gBgPlttBuffer[32 + start];
  rgb555* base;
  s32 inv;
  s32 i;

  for (i = start; i < end; i++) {
    *dst = *src;
    dst++;
    src++;
  }
}

// ブレンドの下地にする BG パレットバンク2 を退避する
void BgPlttGroupFader_SavePltt(BgPlttGroupFader* p) { CpuCopy32(&gBgPlttBuffer[32], p->savedPltt, sizeof(p->savedPltt)); }

s32 BgPlttGroupFader_Update(BgPlttGroupFader* p) {
  s32 start;
  s32 i;
  s32 mask;

  if (FUN_0800271c()) {
    BgPlttGroupFader_SavePltt(p);
  }
  if (p->mode == 2) {
    if ((p->timer & 0xF) == 0) {
      p->level -= p->step;
      if (p->level < 0) {
        p->level = 0;
      }
    }
  } else if (p->mode == 1) {
    if ((p->timer & 0xF) == 0) {
      p->level += p->step;
      if (p->level > 0x1F) {
        p->level = 0x20;
      }
    }
  } else if ((p->timer & 0xF) == 0) {
    p->level += p->step;
    if (p->level > 0x1F) {
      p->level = 0x20;
      p->step = -1;
    } else if (p->level <= 0x10) {
      p->level = 0x10;
      p->step = 1;
    }
  }
  start = 1;
  switch (p->mode) {
    case 0: {
      for (i = 0; i < 4; i++) {
        mask = 1 << i;
        if (!(p->litMask & mask)) {
          BgPlttGroupFader_RestoreGroup(p, start, start + 3);
        } else {
          BgPlttGroupFader_BlendGroup(p, start, start + 3, p->level);
        }
        start += 3;
      }
      break;
    }
    case 1: {
      for (i = 0; i < 4; i++) {
        mask = 1 << i;
        if (!(p->litMask & mask)) {
          if (!(p->fadeMask & mask)) {
            BgPlttGroupFader_RestoreGroup(p, start, start + 3);
          } else {
            BgPlttGroupFader_BlendGroup(p, start, start + 3, p->level);
          }
        } else {
          BgPlttGroupFader_BlendGroup(p, start, start + 3, 0x20);
        }
        start += 3;
      }
      break;
    }
    case 2: {
      for (i = 0; i < 4; i++) {
        mask = 1 << i;
        if (!(p->litMask & mask)) {
          if (!(p->fadeMask & mask)) {
            BgPlttGroupFader_RestoreGroup(p, start, start + 3);
          } else {
            BgPlttGroupFader_BlendGroup(p, start, start + 3, p->level);
          }
        } else {
          BgPlttGroupFader_BlendGroup(p, start, start + 3, p->level);
        }
        start += 3;
      }
      break;
    }
    default: {
      break;
    }
  }
  p->timer++;
  return 0;
}

s32 BgPlttGroupFader_Destroy(BgPlttGroupFader* p) {
  gBgPlttGroupFader = NULL;
  return 0;
}

s32 BgPlttGroupFader_Init(BgPlttGroupFader* p) {
  s32 lit;
  s32 fade;

  gBgPlttGroupFader = p;
  lit = VM_GetKeywordValue('f', 0);
  fade = VM_GetKeywordValue('n', 0);
  p->litMask |= lit;
  p->fadeMask |= fade;
  p->mode = VM_GetKeywordValue('m', 0);
  switch (p->mode) {
    case 0: {
      p->level = 0x10;
      p->step = 1;
      break;
    }
    case 1: {
      p->level = 0;
      p->step = VM_GetKeywordValue('a', 2);
      break;
    }
    case 2: {
      p->level = 0x20;
      p->step = VM_GetKeywordValue('a', 2);
      break;
    }
    default: {
      break;
    }
  }
  BgPlttGroupFader_SavePltt(p);
  return 0;
}

BgPlttGroupFader* BgPlttGroupFader_Create(void) {
  BgPlttGroupFader* p = CreateEntity(ENTITY_UNK_12, sizeof(BgPlttGroupFader));

  if (p != NULL) {
    SetEntityRoutine(p, BgPlttGroupFader_Update, BgPlttGroupFader_Destroy);
    if (BgPlttGroupFader_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// スクリプトコマンド 0x800C, 動いているフェーダの mode を差し替える
void BgPlttGroupFader_SetModeScripted(void) {
  BgPlttGroupFader* p = gBgPlttGroupFader;
  if (p != NULL) {
    p->mode = VM_GetKeywordValue('m', 0);
    switch (p->mode) {
      case 0: {
        p->level = 0x10;
        p->step = 1;
        break;
      }
      case 1: {
        p->level = 0;
        p->step = VM_GetKeywordValue('a', 2);
        break;
      }
      case 2: {
        p->step = VM_GetKeywordValue('a', 1);
        break;
      }
      default: {
        break;
      }
    }
  }
}
