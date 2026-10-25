#include "entity.h"
#include "font.h"
#include "global.h"
#include "text.h"
#include "vm.h"

// スタートメニューのアイテム説明など横にスクロールするテキストで使われていたので、 Marquee
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_3
  TextRenderer renderer;  // 0x018, Marquee_Init が FUN_0804967C(&renderer, 0, 18, 2, 2) で初期化する
  bool8 active;           // 0x178, FUN_08049C3C が立てて gMarqueeActive も 1 にする, FUN_08049C78 が両方戻す
  bool8 openReq;          // 0x179, _Update が FUN_08049C3C を呼んでから 0 に戻す
  bool8 closeReq;         // 0x17A, _Update が FUN_08049C78 を呼んでから 0 に戻す
  bool8 manualScroll;     // 0x17B, 0 なら offset を 8 単位で進める, 0 以外なら delay と SELECT で進める
  u8 delay;               // 0x17C, FUN_0804990C が 30 を入れ、FUN_0804996C が手動側で減らす
  u8 unk_17d;             // 0x17D, FUN_0804990C が 0 を入れる
  u8 unk_17e[2];          // 0x17E, padding?
  s32 timer;              // 0x180, active の間 _Update が毎フレーム +1
  s32 offset;             // 0x184, _Update が gMarqueeOffset へ写し、VBlankIntr が 0x03003508 へ転送する
  u32 unk_188;            // 0x188, _Init と FUN_0804990C が 0 を入れる
  u32 unk_18c;            // 0x18C, 同上
  u32 unk_190;            // 0x190, FUN_0804990C が 0 を入れる
  char* text;             // 0x194, _Init が u32_ARRAY_085AB548 を入れ、FUN_0804990C が renderer+0x1C へ複写する
} Marquee;
static_assert(sizeof(Marquee) == 408);

IWRAM_DATA Marquee* gMarquee = NULL;  // 0x030000C8

const char gBlankText[8] = " ";  // 0x085AB548

extern u32 gMarqueeOffset;      // 0x03002CE8
extern u32 gMarqueeOffset2;     // 0x03003508
extern bool32 gMarqueeActive;   // 0x03003520
extern bool32 gMarqueeActive2;  // 0x03002CEC

void FUN_080498c8(void) { gMarquee = NULL; }

void Marquee_ResetRect(Marquee* p) {
  TextRenderer* r = &p->renderer;

  Font_ReleaseRect(0, 18, 32, 2);
  Font_FillRect(0, 18, 32, 2);
  TextRenderer_SetRect(r, 0, 18, 32, 2);
}

s32 Marquee_Rewind(Marquee* p, bool32 resetRect) {
  TextRenderer* r = &p->renderer;

  if (resetRect) Marquee_ResetRect(p);
  p->unk_18c = 0;
  p->unk_188 = 0;
  p->offset = 0;
  p->manualScroll = 0;
  p->delay = 30;
  p->unk_17d = 0;
  p->unk_190 = 0;
  r->text = p->text;
  r->mode = 0;
  TextRenderer_ResetModeStack(r);
}

NAKED void FUN_0804996c(Marquee* p) { INCFUNC("asm/func/FUN_0804996c.inc"); }

s32 Marquee_Open(Marquee* p) {
  if (p->active) return -1;

  p->offset = 0;
  Marquee_Rewind(p, TRUE);
  gMarqueeActive = TRUE;
  p->active = TRUE;
  return 0;
}

s32 Marquee_Close(Marquee* p) {
  if (!p->active) {
    return -1;
  }

  Marquee_Clear();
  gMarqueeActive = FALSE;
  p->active = FALSE;
  return 0;
}

s32 Marquee_Update(Marquee* p) {
  if (p->openReq) {
    Marquee_Open(p);
    p->openReq = FALSE;
  }
  if (p->closeReq) {
    Marquee_Close(p);
    p->closeReq = FALSE;
  }

  if (p->active) {
    TextRenderer* r = &p->renderer;

    TextRenderer_ClearPending(r);
    FUN_0804996c(p);
    if (p->manualScroll) {
      gMarqueeOffset = p->offset;
    } else {
      gMarqueeOffset = 0;
    }
    p->timer++;
    TextRenderer_RunPending(r);
  }
  return 0;
}

s32 Marquee_Destroy(Marquee* p) {
  if (p->active) {
    p->active = FALSE;
  }

  gMarqueeOffset = 0;
  gMarquee = NULL;
  return 0;
}

NAKED s32 Marquee_Init(Marquee* p) { INCFUNC("asm/func/Marquee_Init.inc"); }

Marquee* Marquee_Create(u32 id) {
  Marquee* p;

  if (gMarquee != NULL) {
    return gMarquee;
  }

  p = CreateEntity(ENTITY_UNK_3, sizeof(Marquee));
  if (p != NULL) {
    SetEntityRoutine(p, Marquee_Update, Marquee_Destroy);
    if (Marquee_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

s32 Marquee_SetText(char* str) {
  if (gMarquee == NULL) {
    return -1;
  }
  gMarquee->text = str;
  Marquee_Rewind(gMarquee, TRUE);
  return 0;
}

s32 Marquee_Clear(void) { return Marquee_SetText((char*)gBlankText); }

// 文字列の <VAR=idx> に対応する値を設定する
s32 Marquee_SetVarValue(s32 idx, s32 value) {
  if (gMarquee == NULL) {
    return -1;
  }
  TextRenderer_SetVar(&gMarquee->renderer, idx, value);
  return 0;
}

s32 UNUSED FUN_08049e94(void) { return Marquee_SetVarValue(VM_GetValue(), VM_GetValue()); }

s32 Marquee_SetExtendValue(s32 idx, char* str) {
  if (gMarquee != NULL) {
    return TextRenderer_SetExtend(&gMarquee->renderer, idx, str);
  }
  return -1;
}

s32 UNUSED FUN_08049ed4(void) { return Marquee_SetExtendValue(VM_GetValue(), VM_GetPC_Proxy()); }

s32 UNUSED FUN_08049ef0(void) { return Marquee_SetExtendValue(VM_GetValue(), VM_GetValueSafe2_Proxy()); }

s32 FUN_08049f0c(void) {
  TextRenderer* r;

  if (gMarquee == NULL) {
    return -1;
  }
  r = &gMarquee->renderer;
  r->scriptIdCount = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL) {
      r->scriptIds[r->scriptIdCount] = VM_GetValue();
      r->scriptIdCount++;
    }
  } else {
    return -1;
  }

  return 0;
}

s32 FUN_08049f5c(void) {
  if (gMarquee == NULL) {
    return -1;
  }
  gMarquee->openReq = TRUE;
  return 0;
}

s32 FUN_08049f84(void) {
  if (gMarquee == NULL) {
    return -1;
  }
  gMarquee->closeReq = TRUE;
  return 0;
}

s32 Marquee_CloseGlobal(void) {
  if (gMarquee == NULL) {
    return -1;
  }
  Marquee_Close(gMarquee);
  return 0;
}
