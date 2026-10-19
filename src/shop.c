#include "shop.h"

#include "global.h"
#include "input.h"
#include "inventory.h"
#include "sound.h"
#include "sprite.h"
#include "video.h"

// ショップ系の共通関数?

// BG のタイルマップ上の (x, y) のアドレスを返す
static BgMapEntry* GetBgTilemapAddr(s32 bgID, u32 x, u32 y) {
  BgState* bg = &gBgStates[bgID];
  BgMapEntry* tilemap = bg->tilemap;

  return tilemap + (x & 0x1F) + (y & 0x1F) * 32;
}

// value を divisor の桁から順に BG のタイルマップへ書く, タイル番号は plttRow * 16 + 0x21 + 数字
// 残差はレジスタ割当だけ (36 対 36), 原典は value/divisor を引数順に r5/r6 へ置いて dst を r7 に回すが, こちらは dst が r6 を取る
// 宣言順の入れ替えと digit/tile を関数スコープに出す形は試済
NON_MATCH void FUN_080b93b0(s32 value, s32 divisor, u32 x, u32 y, s32 plttRow) {
#ifdef NONMATCHING_C
  BgMapEntry* dst = GetBgTilemapAddr(0, x, y);
  s32 base = plttRow * 16 + 0x21;

  while (divisor > 0) {
    s32 digit = Div(value, divisor);
    u16 tile = digit + base;

    *dst = tile | 0xF000;
    dst++;
    value -= divisor * digit;
    divisor = Div(divisor, 10);
  }
#else
  INCFUNC("asm/func/FUN_080b93b0.inc");
#endif
}

NAKED void FUN_080b9400(s32 kind) { INCFUNC("asm/func/FUN_080b9400.inc"); }

NAKED void FUN_080b94cc(s32 kind) { INCFUNC("asm/func/FUN_080b94cc.inc"); }

// MainSprite_SetPlttID と同じことをするもう1つの実装
void FUN_080b95bc(MainSprite* p, u16 plttID) {
  p->plttID = plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
}

NAKED void FUN_080b95d0(MenuCursor* cursor, s32 param_2, MainSprite* sprite1, MainSprite* sprite2) { INCFUNC("asm/func/FUN_080b95d0.inc"); }

NAKED void FUN_080b9658(MainSpriteGfx* gfx, MainSprite* sprite, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080b9658.inc"); }

void FUN_080b9724(MainSprite* sprites) {
  MainSprite* p = sprites;
  s32 i;

  for (i = 0; i < 5; i++) {
    p->flags |= SPRFLAG_HIDDEN;
    p++;
  }
}

void FUN_080b9740(MainSprite* sprite, MainSpriteGfx* gfx, char* out, s32 val) {
  u16 animIdx;

  sprite->flags &= ~SPRFLAG_HIDDEN;
  *out = val;
  animIdx = ((u8)val != 0) ? 4 : 5;
  MainSprite_SetAnim(sprite, gfx, animIdx, 1, 0);
  MainSprite_AdvanceAnim(sprite, gfx);
}

NAKED s32 FUN_080b977c(MainSprite* sprite, MainSpriteGfx* gfx, u8* param_3) { INCFUNC("asm/func/FUN_080b977c.inc"); }

NAKED void FUN_080b9814(MenuSpritePair* p) { INCFUNC("asm/func/FUN_080b9814.inc"); }

void FUN_080b9894(MenuSpritePair* p) {
  s32 i;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

s32 FUN_080b98b0(s32 param_1) {
  if (param_1 != 0) {
    param_1 += 0xA0;
  } else {
    param_1 = 0x93;
  }

  return param_1;
}

NAKED void FUN_080b98c0(MainSpriteGfx* gfx, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080b98c0.inc"); }

NAKED void FUN_080b9938(s16* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080b9938.inc"); }

NAKED void FUN_080b99a0(MenuSpritePair* p) { INCFUNC("asm/func/FUN_080b99a0.inc"); }

void FUN_080b9a0c(MenuSpritePair* p) {
  s32 i;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

NAKED void FUN_080b9a28(MainSpriteGfx* gfx, s32* param_2, WorldPos* pos1, WorldPos* pos2, s32* param_5, s32* param_6, s32 param_7) { INCFUNC("asm/func/FUN_080b9a28.inc"); }

NAKED bool32 FUN_080b9adc(unknown* p) { INCFUNC("asm/func/FUN_080b9adc.inc"); }

// 行と列から実際のスロット番号を引く
s32 MenuCursor_GetSlot(MenuCursor* p) { return p->slots[p->row * 4 + p->col]; }

NAKED void FUN_080b9b88(MenuCursor* p) { INCFUNC("asm/func/FUN_080b9b88.inc"); }

void FUN_080b9d94(MenuCursor* p, u32 unk) {
  p->unk_7 = unk;
  FUN_080b9b88(p);
}

u8 FUN_080b9da0(MenuCursor* p, u8 mask) { return p->unk_7 & mask; }

// 十字キーの入力を返す, 押しっぱなしのときは10フレームごとに1回だけ返す
s32 FUN_080b9da8(MenuCursor* p) {
  if (gInput[0].pressed & DPAD_ANY) {
    p->unk_8 = 0;
    return gInput[0].pressed;
  }

  if (gInput[0].down & DPAD_ANY) {
    p->unk_8++;
    if (p->unk_8 > 9) {
      p->unk_8 = 0;
      return gInput[0].down;
    }
  } else {
    p->unk_8 = 0;
  }
  return 0;
}

// 同じ行を左へ辿って別のスロットへカーソルを移す
s32 FUN_080b9df0(MenuCursor* p) {
  s32 cur = p->slots[p->col + p->row * 4];
  u8 col = (p->col + 3) & 3;

  while (col != p->col) {
    s32 slot = p->slots[col + p->row * 4];

    if (slot >= 0 && slot != cur) {
      p->col = col;
      p->slot = MenuCursor_GetSlot(p);
      PlaySound_082406e0(SONG_220);
      return 1;
    }
    col = (col + 3) & 3;
  }
  return 0;
}

// 同じ行を右へ辿って別のスロットへカーソルを移す
s32 FUN_080b9e50(MenuCursor* p) {
  s32 cur = p->slots[p->col + p->row * 4];
  u8 col = (p->col + 1) & 3;

  while (col != p->col) {
    s32 slot = p->slots[col + p->row * 4];

    if (slot >= 0 && slot != cur) {
      p->col = col;
      p->slot = MenuCursor_GetSlot(p);
      PlaySound_082406e0(SONG_220);
      return 1;
    }
    col = (col + 1) & 3;
  }
  return 0;
}

// 同じ列を上へ辿って別のスロットへカーソルを移す
s32 FUN_080b9eb0(MenuCursor* p) {
  s32 orig = p->row;
  s32 cur = p->slots[orig * 4 + p->col];
  s32 row = orig - 1;

  if (orig == 0) {
    row = 8;
  }

  while (row != orig) {
    s32 slot = p->slots[row * 4 + p->col];

    if (slot >= 0 && slot != cur) {
      p->row = row;
      p->slot = MenuCursor_GetSlot(p);
      PlaySound_082406e0(SONG_220);
      return 1;
    }
    if (row == 0) {
      row = 8;
    } else {
      row--;
    }
  }
  return 0;
}

// 同じ列を下へ辿って別のスロットへカーソルを移す
s32 FUN_080b9f10(MenuCursor* p) {
  s32 orig = p->row;
  s32 cur = p->slots[orig * 4 + p->col];
  s32 row = orig + 1;

  if (orig == 8) {
    row = 0;
  }

  while (row != orig) {
    s32 slot = p->slots[row * 4 + p->col];

    if (slot >= 0 && slot != cur) {
      p->row = row;
      p->slot = MenuCursor_GetSlot(p);
      PlaySound_082406e0(SONG_220);
      return 1;
    }
    if (row == 8) {
      row = 0;
    } else {
      row++;
    }
  }
  return 0;
}

// 押された方向キーに応じてカーソル移動を振り分ける
s32 FUN_080b9f70(MenuCursor* p) {
  s32 keys = FUN_080b9da8(p);

  if (keys & DPAD_UP) {
    return FUN_080b9df0(p);
  }
  if (keys & DPAD_DOWN) {
    return FUN_080b9e50(p);
  }
  if (keys & DPAD_LEFT) {
    return FUN_080b9eb0(p);
  }
  if (keys & DPAD_RIGHT) {
    return FUN_080b9f10(p);
  }
  return 0;
}

void FUN_080b9fc4(MenuCursor* p, MainSprite* sprite) { FUN_080b9938(&sprite->pos.x, (u8)p->slot); }

// カーソルの位置を退避する
void FUN_080b9fd8(MenuCursor* p) {
  p->savedRow = p->row;
  p->savedCol = p->col;
  p->savedSlot = p->slot;
}

// 退避したカーソルの位置を戻す
void FUN_080b9fe8(MenuCursor* p) {
  p->row = p->savedRow;
  p->col = p->savedCol;
  p->slot = p->savedSlot;
}

// カーソルを初期化して行と列から実際のスロット番号を引く
void MenuCursor_Init(MenuCursor* p, u32 kind, u32 row, u32 col, u32 unk) {
  p->kind = kind;
  FUN_080b9d94(p, unk);
  p->row = row;
  p->col = col;
  p->slot = MenuCursor_GetSlot(p);
  p->unk_8 = 0;
}
