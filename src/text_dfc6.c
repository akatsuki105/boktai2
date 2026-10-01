#include "entity.h"
#include "font.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "text.h"
#include "vm.h"

// TextRenderer を1つ持ち、offset を毎フレーム進めて DAT_03002CE8 に流すシングルトン
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_3
  TextRenderer renderer;  // 0x018, EntityDFC6_Init が FUN_0804967C(&renderer, 0, 0x12, 2, 2) で初期化する
  bool8 active;           // 0x178, FUN_08049C3C が立てて DAT_03003520 も 1 にする, FUN_08049C78 が両方戻す
  bool8 openReq;          // 0x179, _Update が FUN_08049C3C を呼んでから 0 に戻す
  bool8 closeReq;         // 0x17A, _Update が FUN_08049C78 を呼んでから 0 に戻す
  bool8 manualScroll;     // 0x17B, 0 なら offset を 8 単位で進める, 0 以外なら delay と SELECT で進める
  u8 delay;               // 0x17C, FUN_0804990C が 30 を入れ、FUN_0804996C が手動側で減らす
  u8 unk_17d;             // 0x17D, FUN_0804990C が 0 を入れる
  u8 unk_17e[2];          // 0x17E, 読み手も書き手も見つかっていない
  s32 timer;              // 0x180, active の間 _Update が毎フレーム +1
  s32 offset;             // 0x184, _Update が DAT_03002CE8 へ写し、VBlankIntr が 0x03003508 へ転送する
  u32 unk_188;            // 0x188, _Init と FUN_0804990C が 0 を入れる
  u32 unk_18c;            // 0x18C, 同上
  u32 unk_190;            // 0x190, FUN_0804990C が 0 を入れる
  char* unk_194;          // 0x194, _Init が u32_ARRAY_085AB548 を入れ、FUN_0804990C が renderer+0x1C へ複写する
} EntityDFC6;
static_assert(sizeof(EntityDFC6) == 408);

IWRAM_DATA EntityDFC6* gEntityDFC6 = NULL;  // 0x030000C8

const SoundID16 s16_ARRAY_085ab458[2] = {0x105, 0x106};  // 0x085AB458

const u16 u16_ARRAY_085ab45c[118] = {
    0x4C, 0x61, 0x68, 0x62, 0x66, 0x60, 0x1, 0x63, 0x3, 0x64, 0x6A, 0x66, 0x4, 0x67, 0x67, 0x65, 0x69, 0x68, 0x6E, 0x6A, 0x6B, 0x6B, 0x6C, 0x69, 0x6D, 0x6C, 0x72, 0x6E, 0x6F, 0x6F, 0x70, 0x6D, 0x6, 0x70, 0x75, 0x72, 0x73, 0x73, 0x74, 0x71, 0x7, 0x74, 0x5A, 0x75, 0x28, 0x8F, 0x9, 0x78, 0x8, 0x79, 0xA, 0x77, 0xD, 0x94, 0xB, 0x7A, 0xE, 0x7B, 0x10, 0x7D, 0xF, 0x7E, 0x11, 0x7C, 0x12, 0x7F, 0x14, 0x81, 0x13, 0x82, 0x15, 0x80, 0x16, 0x83, 0x19, 0x85, 0x18, 0x86, 0x1A, 0x84, 0x1B, 0x87, 0x1E, 0x89, 0x1D, 0x8A, 0x1F, 0x88, 0x20, 0x8B, 0x58, 0x8C, 0x59, 0x8D, 0x4F, 0x8015, 0x50, 0x8016, 0x29, 0x0, 0x48, 0x90, 0x49, 0x91, 0x4A, 0x0, 0x22, 0x95, 0x42, 0x93, 0x41, 0x92, 0x17, 0x8E, 0x5, 0x76, 0xFF81, 0x0,
};  // 0x085AB45C

const u32 u32_ARRAY_085ab548[2] = {0x20, 0x0};  // 0x085AB548

extern u8 u8_03002ce8[8];           // 0x03002CE8
extern bool32 gTextRendererActive;  // 0x03003520

s32 FUN_08049e5c(void);

static inline s32 GetMessageSpeed(void) { return gStat->messageSpeed; }  // 本体設定のメッセージ速度

NAKED void FUN_08048934(unknown* param_1, u8 param_2) { INCFUNC("asm/func/FUN_08048934.inc"); }

// 退避しておいた mode を1つ取り出して戻す
void FUN_08048964(TextRenderer* p) {
  if (p->stackDepth != 0) {
    p->stackDepth--;
    p->mode = p->stack[p->stackDepth];
  }
}

// 改行: 描画位置を矩形の左端に戻して2行ぶん下げる
void TextRenderer_NewLine(TextRenderer* p) {
  p->cursorX = p->rectX;
  p->cursorY += 2;
}

s32 FUN_08048998(u8* param_1, s32 param_2) {
  s32 v;
  s32 lim;

  if (param_2 == 0) {
    param_1[0] += 1;
  } else {
    param_1[0] += 2;
  }

  v = param_1[0];
  lim = param_1[2] + param_1[4];
  if (v >= lim) {
    param_1[0] = v - lim;
  }
}

NAKED void FUN_080489c4(unknown* param_1, u32 param_2) { INCFUNC("asm/func/FUN_080489c4.inc"); }

s32 FUN_08048a20(u8* param_1, u16 param_2) {
  FUN_080489c4(param_1, param_2);
  Video_DrawCharNarrow(param_2, param_1[0], param_1[1], param_1[6]);
  FUN_08048998(param_1, 0);
  param_1[0x13] = 0;
}

s32 FUN_08048a4c(u8* param_1, u16 param_2) {
  FUN_080489c4(param_1, param_2);
  Video_DrawCharWide(param_2, param_1[0], param_1[1], param_1[6]);
  FUN_08048998(param_1, 1);
  param_1[0x13] = 1;
}

s32 FUN_08048a78(s32* p, s32 n) {
  s32 count = 0;
  s32 v = *p;

  while (v >= n) {
    count++;
    v -= n;
    *p = v;
  }
  return count;
}

NAKED s32 FUN_08048a98(char* param_1, u8* param_2, u8* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08048a98.inc"); }

// キーが param_1[1] と一致する組の値を返す, 無ければ 0xFFFF
s32 FUN_08048afc(u8* param_1) {
  const u16* t = u16_ARRAY_085ab45c;

  while (t[0] != 0) {
    if (t[0] == param_1[1]) {
      return t[1];
    }
    t += 2;
  }

  return 0xFFFF;
}

NAKED void FUN_08048b28(char* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08048b28.inc"); }

// s の先頭 n 文字を lit と比べる, s が先に終われば -1、文字が違えば 1、n 文字一致すれば 0
s32 TextBox_StrNCmp(u8* s, const char* lit, s32 n) {
  s32 i;

  for (i = 0; i < n; i++) {
    if (s[i] == 0) {
      if (lit[0] != 0) {
        return -1;
      }

      return 0;
    }

    if (s[i] != lit[0]) {
      return 1;
    }

    lit++;
  }

  return 0;
}

// 末尾の桁から見て10進の数値にする
NON_MATCH s32 TextBox_ParseDecimal(u8* s, s32 len) {
#ifdef NONMATCHING_C
  s32 v = 0;
  s32 mul = 1;
  u8* p = s + len - 1;
  s32 i;

  for (i = 0; i < len; i++) {
    v += (*p-- - '0') * mul;
    mul *= 10;
  }

  return v;
#else
  INCFUNC("asm/func/TextBox_ParseDecimal.inc");
#endif
}

NAKED s32 FUN_08048c58(TextRenderer* p) { INCFUNC("asm/func/FUN_08048c58.inc"); }

// c か終端に当たるまで進めた位置を返す
u8* TextBox_FindChar(u8* s, u8 c) {
  while (*s != c && *s != 0) {
    s++;
  }
  return s;
}

NAKED s32 FUN_08048ce0(TextRenderer* p, char* text) { INCFUNC("asm/func/FUN_08048ce0.inc"); }

s32 FUN_08048d40(void) {
  switch (gStat->playerKind) {
    case PLAYER_SOLAR_DJANGO: {
      return 0;
    }
    case PLAYER_DARK_DJANGO: {
      return 1;
    }
    case PLAYER_SABATA: {
      return 3;
    }
    default: {
      return 1;
    }
  }
}

NON_MATCH s32 FUN_08048d78(void) {
#ifdef NONMATCHING_C
  if (gStat->playerKind == PLAYER_SOLAR_DJANGO) return 0x1B;

  return 0x1C;
#else
  INCFUNC("asm/func/FUN_08048d78.inc");
#endif
}

NAKED s32 FUN_08048da4(TextRenderer* p, u8* s) { INCFUNC("asm/func/FUN_08048da4.inc"); }

NAKED s32 FUN_08049488(TextRenderer* p, u8* s) { INCFUNC("asm/func/FUN_08049488.inc"); }

NAKED s32 TextRenderer_Advance(TextRenderer* p) { INCFUNC("asm/func/TextRenderer_Advance.inc"); }

// mode が選ぶ4本の文字列のうち、いま進めているものを返す
char* FUN_0804960c(TextRenderer* p) {
  switch (p->mode) {
    case 0: {
      return p->text;
    }
    case 1: {
      return p->textAlt;
    }
    case 2: {
      return p->unk_24;
    }
    case 3: {
      return p->unk_28;
    }
  }

  return NULL;
}

void FUN_08049640(TextRenderer* p) {
  p->unk_06 = 0;
  p->stackDepth = 0;
  p->mode = 0;
}

// 描画矩形を設定し、カーソルを左上へ戻す
void TextRenderer_SetRect(TextRenderer* p, s32 x, s32 y, s32 width, s32 height) {
  p->rectX = x;
  p->rectY = y;
  p->rectW = width;
  p->rectH = height;
  p->cursorX = x;
  p->cursorY = y;
}

// 文字送り速度を設定から取り込む
void FUN_08049668(TextRenderer* p) {
  p->unk_08 = 0;
  p->speed = GetMessageSpeed();
}

void TextRenderer_Init(TextRenderer* p, s32 x, s32 y, s32 width, s32 height) {
  TextRenderer_SetRect(p, x, y, width, height);
  FUN_08049640(p);
  FUN_08049668(p);
  p->unk_0a = 0;
  p->unk_0b = 0;
  p->unk_0c = p->speed;
  p->unk_13 = 0;
  p->scriptIdCount = 0;
  p->text = NULL;
  p->textAlt = NULL;
  p->unk_24 = NULL;
  p->unk_28 = NULL;
  p->face = -1;
  p->unk_14 = 1;
  p->unk_18 = 0;
}

s32 TextRenderer_SetVar(TextRenderer* p, s32 idx, u32 val) { p->vars[idx] = val; }

s32 TextRenderer_SetExtend(TextRenderer* p, s32 idx, char* str) { p->extends[idx] = str; }

s32 TextRenderer_SetScriptIds(TextRenderer* p, s32 count, u32* ids) {
  s32 i;

  for (i = 0; i < count; i++) {
    p->scriptIds[i] = ids[i];
  }

  p->scriptIdCount = count;
}

NAKED s32 TextRenderer_GetVarWidth(TextRenderer* p, s32 param_2) { INCFUNC("asm/func/TextRenderer_GetVarWidth.inc"); }

NAKED s32 TextRenderer_GetExtendWidth(TextRenderer* p, s32 param_2) { INCFUNC("asm/func/TextRenderer_GetExtendWidth.inc"); }

void TextRenderer_ClearPending(TextRenderer* p) { p->pendingCount = 0; }

void TextRenderer_RunPending(TextRenderer* p) {
  u32 i;

  for (i = 0; i < p->pendingCount; i++) {
    VM_ExecByID(p->scriptIds[p->pending[i]], NULL);
  }
}

void FUN_080498c8(void) { gEntityDFC6 = NULL; }

void FUN_080498d4(EntityDFC6* p) {
  TextRenderer* r = &p->renderer;

  FUN_0822ea60(0, 0x12, 0x20, 2);
  FUN_0822eadc(0, 0x12, 0x20, 2);
  TextRenderer_SetRect(r, 0, 0x12, 0x20, 2);
}

NAKED s32 FUN_0804990c(EntityDFC6* p, bool32 reset) { INCFUNC("asm/func/FUN_0804990c.inc"); }

NAKED void FUN_0804996c(EntityDFC6* p) { INCFUNC("asm/func/FUN_0804996c.inc"); }

s32 FUN_08049c3c(EntityDFC6* p) {
  if (p->active) return -1;

  p->offset = 0;
  FUN_0804990c(p, TRUE);
  gTextRendererActive = TRUE;
  p->active = TRUE;
  return 0;
}

s32 FUN_08049c78(EntityDFC6* p) {
  if (!p->active) {
    return -1;
  }

  FUN_08049e5c();
  gTextRendererActive = FALSE;
  p->active = FALSE;
  return 0;
}

NAKED s32 EntityDFC6_Update(EntityDFC6* p) { INCFUNC("asm/func/EntityDFC6_Update.inc"); }

s32 EntityDFC6_Destroy(EntityDFC6* p) {
  if (p->active) {
    p->active = FALSE;
  }

  *(u32*)u8_03002ce8 = 0;
  gEntityDFC6 = NULL;
  return 0;
}

NAKED s32 EntityDFC6_Init(EntityDFC6* p) { INCFUNC("asm/func/EntityDFC6_Init.inc"); }

EntityDFC6* EntityDFC6_Create(void) {
  EntityDFC6* p;

  if (gEntityDFC6 != NULL) {
    return gEntityDFC6;
  }

  p = CreateEntity(ENTITY_UNK_3, sizeof(EntityDFC6));
  if (p != NULL) {
    SetEntityRoutine(p, EntityDFC6_Update, EntityDFC6_Destroy);
    if (EntityDFC6_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

extern char gBlankText[];  // " ", data/rodata.bin の 0x085AB548

s32 FUN_08049e30(char* str) {
  if (gEntityDFC6 == NULL) {
    return -1;
  }

  gEntityDFC6->unk_194 = str;
  FUN_0804990c(gEntityDFC6, 1);
  return 0;
}

s32 FUN_08049e5c(void) { return FUN_08049e30(gBlankText); }

s32 FUN_08049e6c(s32 idx, s32 value) {
  if (gEntityDFC6 == NULL) {
    return -1;
  }

  TextRenderer_SetVar(&gEntityDFC6->renderer, idx, value);
  return 0;
}

s32 FUN_08049e94(void) {
  s32 n = VM_GetValue();
  return FUN_08049e6c(n, VM_GetValue());
}

s32 FUN_08049eb0(s32 idx, void* str) {
  EntityDFC6* p = gEntityDFC6;

  if (p != NULL) {
    return TextRenderer_SetExtend(&p->renderer, idx, str);
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
  EntityDFC6* p = gEntityDFC6;
  TextRenderer* r;

  if (p == NULL) return -1;

  r = &p->renderer;
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
  if (gEntityDFC6 == NULL) {
    return -1;
  }

  gEntityDFC6->openReq = TRUE;
  return 0;
}

s32 FUN_08049f84(void) {
  if (gEntityDFC6 == NULL) {
    return -1;
  }

  gEntityDFC6->closeReq = TRUE;
  return 0;
}

s32 FUN_08049fa8(void) {
  EntityDFC6* p = gEntityDFC6;

  if (p == NULL) {
    return -1;
  }
  FUN_08049c78(p);
  return 0;
}
