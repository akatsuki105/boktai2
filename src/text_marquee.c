#include "entity.h"
#include "font.h"
#include "global.h"
#include "input.h"
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
  u8 delay;               // 0x17C, FUN_0804990C が 30 を入れ、Marquee_Scroll が手動側で減らす
  bool8 paused;           // 0x17D, 手動スクロールに切り替えた直後に立て, delay が尽きるまで描き足しを止める
  u8 unk_17e[2];          // 0x17E, padding?
  s32 timer;              // 0x180, active の間 _Update が毎フレーム +1
  s32 offset;             // 0x184, _Update が gMarqueeOffset へ写し、VBlankIntr が 0x03003508 へ転送する
  s32 drawCol;            // 0x188, 次に文字を描くタイル列, 32 で折り返す
  s32 clearCol;           // 0x18C, 次に消すタイル列, 32 で折り返す
  s32 padCount;           // 0x190, 文字列の終わりに足す空白の残り, 0 になると text の先頭へ戻す
  char* text;             // 0x194, _Init が u32_ARRAY_085AB548 を入れ、FUN_0804990C が renderer+0x1C へ複写する
} Marquee;
static_assert(sizeof(Marquee) == 408);

IWRAM_DATA Marquee* gMarquee = NULL;  // 0x030000C8

const char gBlankText[8] = " ";  // 0x085AB548

extern u32 gMarqueeOffset;      // 0x03002CE8
extern u32 gMarqueeOffset2;     // 0x03003508
extern bool32 gMarqueeActive;   // 0x03003520
extern bool32 gMarqueeActive2;  // 0x03002CEC

char* TextRenderer_GetCurrentText(TextRenderer* p);
s32 TextRenderer_DrawHankakuChar(TextRenderer* p, u16 charcode);

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
  p->clearCol = 0;
  p->drawCol = 0;
  p->offset = 0;
  p->manualScroll = 0;
  p->delay = 30;
  p->paused = 0;
  p->padCount = 0;
  r->text = p->text;
  r->mode = 0;
  TextRenderer_ResetModeStack(r);
}

// スクロールを1歩進め, 見えてきたタイル列を消して次の文字を描き足す, 自動スクロール中は手動に切り替わるまで繰り返す
void Marquee_Scroll(Marquee* p) {
  TextRenderer* r = &p->renderer;
  bool32 stepped = FALSE;
  char* c;

  if (p->manualScroll) {
    if (p->delay == 0) {
      if (gInput[0].down & SELECT_BUTTON) {
        p->offset = (p->offset & ~3) + 4;
      } else {
        p->offset++;
      }
      stepped = TRUE;
    } else {
      p->delay--;
    }
  } else {
    p->offset = (p->offset & ~7) + 8;
    stepped = TRUE;
  }

  if ((p->offset & 7) == 0) {
    if (p->manualScroll && p->delay == 0 && p->paused) {
      p->paused = FALSE;
    }
    if (p->padCount == 0 && !p->manualScroll && p->drawCol == 31 && (p->offset & 15) == 8) {
      char* s = TextRenderer_GetCurrentText(r);

      if (s != NULL && (s8)*s < 0) {
        p->offset -= 8;
        p->manualScroll = TRUE;
        p->paused = TRUE;
      }
    }
    if (!p->paused && stepped) {
      Font_ReleaseRect(p->clearCol, 18, 1, 2);
      Font_FillRect(p->clearCol, 18, 1, 2);
      p->clearCol++;
      c = TextRenderer_GetCurrentText(r);
      if (c != NULL) {
      skipTag:
        if (*c == '<') {
          TextRenderer_Advance(r);
          if (r->stopAtTag) {
            c = TextRenderer_GetCurrentText(r);
            if (r->mode == 0 && *c == '\0') {
              p->padCount = 8;
            }
            goto skipTag;
          }
        }
        if ((s8)*c >= 0) {
          TextRenderer_SetRect(&p->renderer, p->drawCol, 18, 1, 2);
          p->drawCol++;
          if (p->padCount > 0) {
            TextRenderer_DrawHankakuChar(r, 0);
            if (--p->padCount <= 0) {
              r->text = p->text;
              p->padCount = 0;
            }
          } else if (TextRenderer_Advance(r)) {
            p->padCount = 8;
          }
        } else if ((!(p->drawCol & 1) && (p->offset & 15) == 0) || ((p->drawCol & 1) && (p->offset & 15) == 8)) {
          if (p->padCount > 0) {
            TextRenderer_DrawHankakuChar(r, 0);
            p->drawCol++;
            if (--p->padCount <= 0) {
              r->text = p->text;
              p->padCount = 0;
            }
          } else {
            TextRenderer_SetRect(&p->renderer, p->drawCol, 18, 2, 2);
            p->drawCol += 2;
            if (TextRenderer_Advance(r)) {
              p->padCount = 8;
            }
          }
        }
      }
      if (p->drawCol > 31) {
        if (!p->manualScroll) {
          p->manualScroll = TRUE;
        }
        p->drawCol -= 32;
      }
      if (p->clearCol > 31) {
        p->clearCol -= 32;
      }
    }
  }
  if (!p->manualScroll) {
    Marquee_Scroll(p);
  }
}

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
    Marquee_Scroll(p);
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

s32 Marquee_Init(Marquee* p) {
  TextRenderer* r;

  gMarquee = p;
  r = &p->renderer;
  p->active = FALSE;
  p->openReq = FALSE;
  p->closeReq = FALSE;
  p->timer = 0;
  p->clearCol = 0;
  p->drawCol = 0;
  TextRenderer_Init(r, 0, 18, 2, 2);
  r->tagsInline = FALSE;
  r->text = p->text = (char*)gBlankText;
  Marquee_Rewind(p, FALSE);
  r->charSoundIdx = 0;
  r->muteCharSound = TRUE;
  p->offset = 0;
  gMarqueeOffset = 0;
  return 0;
}

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

// 表示中のマーキーに閉じる要求を出す, 無ければ -1
s32 Marquee_RequestClose(void) {
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
