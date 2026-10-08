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
  s32 offset;             // 0x184, _Update が u8_03002ce8 へ写し、VBlankIntr が 0x03003508 へ転送する
  u32 unk_188;            // 0x188, _Init と FUN_0804990C が 0 を入れる
  u32 unk_18c;            // 0x18C, 同上
  u32 unk_190;            // 0x190, FUN_0804990C が 0 を入れる
  char* unk_194;          // 0x194, _Init が u32_ARRAY_085AB548 を入れ、FUN_0804990C が renderer+0x1C へ複写する
} Marquee;
static_assert(sizeof(Marquee) == 408);

IWRAM_DATA Marquee* gMarquee = NULL;  // 0x030000C8

const char gBlankText[8] = " ";  // 0x085AB548

extern u8 u8_03002ce8[8];      // 0x03002CE8
extern bool32 gMarqueeActive;  // 0x03003520

void FUN_080498c8(void) { gMarquee = NULL; }

void FUN_080498d4(Marquee* p) {
  TextRenderer* r = &p->renderer;

  FUN_0822ea60(0, 18, 32, 2);
  FUN_0822eadc(0, 18, 32, 2);
  TextRenderer_SetRect(r, 0, 18, 32, 2);
}

NAKED s32 FUN_0804990c(Marquee* p, bool32 reset) { INCFUNC("asm/func/FUN_0804990c.inc"); }

NAKED void FUN_0804996c(Marquee* p) { INCFUNC("asm/func/FUN_0804996c.inc"); }

s32 FUN_08049c3c(Marquee* p) {
  if (p->active) return -1;

  p->offset = 0;
  FUN_0804990c(p, TRUE);
  gMarqueeActive = TRUE;
  p->active = TRUE;
  return 0;
}

s32 FUN_08049c78(Marquee* p) {
  if (!p->active) {
    return -1;
  }

  FUN_08049e5c();
  gMarqueeActive = FALSE;
  p->active = FALSE;
  return 0;
}

NAKED s32 Marquee_Update(Marquee* p) { INCFUNC("asm/func/Marquee_Update.inc"); }

s32 Marquee_Destroy(Marquee* p) {
  if (p->active) {
    p->active = FALSE;
  }

  *(u32*)u8_03002ce8 = 0;
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

s32 FUN_08049e30(char* str) {
  if (gMarquee == NULL) {
    return -1;
  }
  gMarquee->unk_194 = str;
  FUN_0804990c(gMarquee, 1);
  return 0;
}

s32 FUN_08049e5c(void) { return FUN_08049e30((char*)gBlankText); }

s32 FUN_08049e6c(s32 idx, s32 value) {
  if (gMarquee == NULL) {
    return -1;
  }
  TextRenderer_SetVar(&gMarquee->renderer, idx, value);
  return 0;
}

s32 FUN_08049e94(void) {
  s32 n = VM_GetValue();
  return FUN_08049e6c(n, VM_GetValue());
}

s32 FUN_08049eb0(s32 idx, void* str) {
  if (gMarquee != NULL) {
    return TextRenderer_SetExtend(&gMarquee->renderer, idx, str);
  }
  return -1;
}

s32 FUN_08049ed4(void) {
  s32 n = VM_GetValue();
  return FUN_08049eb0(n, FUN_0823d340());
}

s32 FUN_08049ef0(void) {
  s32 n = VM_GetValue();
  return FUN_08049eb0(n, FUN_0823d34c());
}

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

s32 FUN_08049fa8(void) {
  if (gMarquee == NULL) {
    return -1;
  }
  FUN_08049c78(gMarquee);
  return 0;
}
