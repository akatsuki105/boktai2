#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

typedef u8 BgPlttBlendFlags;                    // BgPlttBlend.flags
#define BGP_BLEND_INTERPOLATE (1 << 0)          // セットされているなら、書き出し時に補間する, クリアされている場合は単純コピーする
#define BGP_BLEND_STOP_AT_FADEIN_END (1 << 1)   // 往路の終端で止める
#define BGP_BLEND_STOP_AT_FADEOUT_END (1 << 2)  // 復路の終端で止める

// 2枚のパレットの間を補間して書き出すスロット, Cmd_AddBgPlttBlenderSlot がスクリプトから1件ずつ積む
typedef struct {
  rgb555* endPltt;         // 0x00, '.s', 補間の終点 (t が最大のときの色)
  rgb555* startPltt;       // 0x04, '.d', 補間の始点, BGP_BLEND_INTERPOLATE がクリアされている場合はこれがそのままコピーされる
  rgb555* outPltt;         // 0x08, '.b', 書き出し先 (常に gBgPlttBuffer 内)
  u8 count;                // 0x0C, '.n=1', 書き出す色数
  u8 timer;                // 0x0D, 毎フレーム +1, t = timer * 32 / 所要フレーム数
  BgPlttBlendFlags flags;  // 0x0E, '.f=0', see BgPlttBlendFlags
  bool8 reverse;           // 0x0F, 0 なら startPltt -> endPltt、 1 なら逆向き
  u8 fadeIn;               // 0x10, '.S=10', 往路のフレーム数
  u8 fadeOut;              // 0x11, '.D=10', 復路のフレーム数
  u8 _[2];                 // 0x12, padding
} BgPlttBlend;
static_assert(sizeof(BgPlttBlend) == 20);

// BG パレットの補間スロットを最大16件持ち、毎フレームまとめて更新するシングルトン
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_12
  u32 count;              // 0x18, 使用中のスロット数, _Init が 0、_AddSlotFromScript が +1 (15 を超えると拒否)
  rgb555 savedPltt[256];  // 0x1C, BgPlttBlender_SavePltt が gBgPlttBuffer 全体 (128 ワード) をコピーする, スロットの参照先にできる
  BgPlttBlend slots[16];  // 0x21C
} BgPlttBlender;
static_assert(sizeof(BgPlttBlender) == 860);

IWRAM_DATA BgPlttBlender* gBgPlttBlender = NULL;  // 0x0300008C

bool32 FUN_0800271c(void);  // asm/entity_517b.inc

void BgPlttBlender_SavePltt(BgPlttBlender* p) { CpuCopy32(gBgPlttBuffer, p->savedPltt, sizeof(p->savedPltt)); }

// スロットのタイマーを進めて往復の向きを切り替え, 2枚のパレットを補間して書き出す
s32 BgPlttBlender_UpdateSlot(BgPlttBlender* p, BgPlttBlend* slot) {
  rgb555* to;
  rgb555* from;
  s32 frames;
  s32 t, u;
  s32 i;

  if (!slot->reverse) {
    if (slot->timer >= slot->fadeIn) {
      if (!(slot->flags & BGP_BLEND_STOP_AT_FADEIN_END)) {
        slot->reverse = TRUE;
        slot->timer = 0;
        to = slot->startPltt;
        from = slot->endPltt;
        frames = slot->fadeOut;
      } else {
        to = slot->endPltt;
        from = slot->startPltt;
        frames = slot->fadeIn;
      }
    } else {
      to = slot->endPltt;
      from = slot->startPltt;
      frames = slot->fadeIn;
      slot->timer++;
    }
  } else {
    if (slot->timer >= slot->fadeOut) {
      if (!(slot->flags & BGP_BLEND_STOP_AT_FADEOUT_END)) {
        slot->reverse = FALSE;
        slot->timer = 0;
        to = slot->endPltt;
        from = slot->startPltt;
        frames = slot->fadeIn;
      } else {
        to = slot->startPltt;
        from = slot->endPltt;
        frames = slot->fadeOut;
      }
    } else {
      to = slot->startPltt;
      from = slot->endPltt;
      frames = slot->fadeOut;
      slot->timer++;
    }
  }

  if (slot->flags & BGP_BLEND_INTERPOLATE) {
    t = frames > 0 ? Div(slot->timer * 32, frames) : 0;
    u = 32 - t;
    for (i = 0; i < slot->count; i++) {
      u32 c1 = to[i];
      u32 c2 = from[i];
      rgb555 c = ((((c1 & 0x7C1F) * t + (c2 & 0x7C1F) * u) & 0xF83E0) | (((c1 & 0x3E0) * t + (c2 & 0x3E0) * u) & 0x7C00)) >> 5;

      slot->outPltt[i] = c;
    }
  } else {
    for (i = 0; i < slot->count; i++) {
      slot->outPltt[i] = from[i];
    }
  }
  return 0;
}

s32 BgPlttBlender_Update(BgPlttBlender* p) {
  u32 i;

  if (FUN_0800271c()) {
    BgPlttBlender_SavePltt(p);
  }

  for (i = 0; i < p->count; i++) {
    BgPlttBlender_UpdateSlot(p, &p->slots[i]);
  }
  return 0;
}

s32 BgPlttBlender_Destroy(BgPlttBlender* p) {
  gBgPlttBlender = NULL;
  return 0;
}

s32 BgPlttBlender_Init(BgPlttBlender* p) {
  gBgPlttBlender = p;
  p->count = 0;
  BgPlttBlender_SavePltt(p);
  return 0;
}

BgPlttBlender* BgPlttBlender_Create(void) {
  BgPlttBlender* p;

  if (gBgPlttBlender != NULL) {
    return gBgPlttBlender;
  }

  p = CreateEntity(ENTITY_UNK_12, sizeof(BgPlttBlender));
  if (p != NULL) {
    SetEntityRoutine(p, BgPlttBlender_Update, BgPlttBlender_Destroy);
    if (BgPlttBlender_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// スクリプトから補間スロットを1件積む, '.s' / '.d' / '.b' は (パレット行, 色番号, 1 なら savedPltt から) の並び
// 134/137, 原典は gBgPlttBuffer 側のアドレスを 行 * 32 + (色番号 * 2 + 土台) の順に組み, '.d' の3つ目をスタックに退避する
// gBgPlttBuffer + 色番号 + 行 * 16, 行 * 16 + &gBgPlttBuffer[色番号] は試済 (138/137)
NON_MATCH s32 Cmd_AddBgPlttBlenderSlot(void) {
#ifdef NONMATCHING_C
  BgPlttBlender* p = BgPlttBlender_Create();
  BgPlttBlend* slot;
  s32 endRow, endCol, endSaved;
  s32 startRow, startCol, startSaved;
  s32 outRow, outCol;

  if (p == NULL || p->count > 15) {
    return -1;
  }

  slot = &p->slots[p->count];
  if (VM_SeekToNamedArg('s')) {
    endRow = VM_GetValue();
    endCol = VM_GetValue();
    endSaved = VM_GetValue();
  } else {
    endRow = 0;
    endCol = 0;
    endSaved = 0;
  }
  if (VM_SeekToNamedArg('d')) {
    startRow = VM_GetValue();
    startCol = VM_GetValue();
    startSaved = VM_GetValue();
  } else {
    startRow = 0;
    startCol = 0;
    startSaved = 0;
  }
  if (VM_SeekToNamedArg('b')) {
    outRow = VM_GetValue();
    outCol = VM_GetValue();
  } else {
    outRow = 0;
    outCol = 0;
  }

  if (endSaved == 1) {
    slot->endPltt = &p->savedPltt[endRow * 16 + endCol];
  } else {
    slot->endPltt = &gBgPlttBuffer[endRow * 16 + endCol];
  }
  if (startSaved == 1) {
    slot->startPltt = &p->savedPltt[startRow * 16 + startCol];
  } else {
    slot->startPltt = &gBgPlttBuffer[startRow * 16 + startCol];
  }
  slot->outPltt = &gBgPlttBuffer[outRow * 16 + outCol];
  slot->count = VM_GetNamedArgValue('n', 1);
  slot->timer = 0;
  slot->flags = VM_GetNamedArgValue('f', 0);
  slot->reverse = FALSE;
  slot->fadeIn = VM_GetNamedArgValue('S', 10);
  slot->fadeOut = VM_GetNamedArgValue('D', 10);
  p->count++;
#else
  INCFUNC("asm/func/Cmd_AddBgPlttBlenderSlot.inc");
#endif
}
