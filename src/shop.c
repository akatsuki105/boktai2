#include "shop.h"

#include "global.h"
#include "input.h"
#include "inventory.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"

// ショップ系の共通関数?

// BG のタイルマップ上の (x8, y8) のアドレスを返す
static BgMapEntry* GetBgMapAddr(s32 bgnum, u32 x8, u32 y8) {
  BgState* bg = &gBgStates[bgnum];
  BgMapEntry* tilemap = bg->tilemap;

  return tilemap + (x8 & 0x1F) + (y8 & 0x1F) * 32;
}

// value を divisor の桁から順に BG のタイルマップへ書く, タイル番号は plttRow * 16 + 0x21 + 数字
// 残差はレジスタ割当だけ (36 対 36), 原典は value/divisor を引数順に r5/r6 へ置いて dst を r7 に回すが, こちらは dst が r6 を取る
// 宣言順の入れ替えと digit/tile を関数スコープに出す形は試済
NON_MATCH void FUN_080b93b0(s32 value, s32 divisor, u32 x, u32 y, s32 plttRow) {
#ifdef NONMATCHING_C
  BgMapEntry* dst = GetBgMapAddr(0, x, y);
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

void FUN_080b9400(s32 kind) {
  BgMapEntry* tilemap = GetBgMapAddr(0, 18, 0);

  if (kind == 0) {
    *tilemap++ = 0xF03B;
    *tilemap++ = 0xF03C;
    *tilemap = 0xF03D;
    FUN_080b93b0(Time_GetHour(), 10, 22, 0, 0);
    FUN_080b93b0(Time_GetMinute(), 10, 25, 0, 0);
  } else if (kind == 1) {
    *tilemap++ = 0xF045;
    *tilemap++ = 0xF046;
    *tilemap = 0xF047;
    FUN_080b93b0(gClock.morning.hour, 10, 22, 0, 0);
    FUN_080b93b0(gClock.morning.minute, 10, 25, 0, 0);
  } else {
    *tilemap++ = 0xF045;
    *tilemap++ = 0xF046;
    *tilemap = 0xF048;
    FUN_080b93b0(gClock.sunset.hour, 10, 22, 0, 0);
    FUN_080b93b0(gClock.sunset.minute, 10, 25, 0, 0);
  }
}

void FUN_080b94cc(s32 kind) {
  BgMapEntry* tilemap = GetBgMapAddr(0, 18, 1);

  if (kind == 0) {
    *tilemap++ = 0xF03E;
    *tilemap++ = 0xF03D;
    *tilemap++ = 0xF03F;
    *tilemap++ = 0xF069;
    *tilemap = 0xF001;
    FUN_080b93b0((s16)gStat->solarBank, 1000, 23, 1, kind);
  } else if (kind == 1) {
    *tilemap++ = 0xF040;
    *tilemap++ = 0xF041;
    *tilemap++ = 0xF03D;
    *tilemap++ = 0xF069;
    *tilemap = 0xF030;
    FUN_080b93b0(gStat->darkDebts, 1000, 23, 1, kind);
  } else {
    *tilemap++ = 0xF042;
    *tilemap++ = 0xF043;
    *tilemap++ = 0xF03D;
    *tilemap++ = 0xF044;
    *tilemap = 0xF069;
    FUN_080b93b0(gStat->solarStand, 1000, 23, 1, 0);
  }
}

// MainSprite_SetPlttID と全く同じ
void FUN_080b95bc(MainSprite* p, u16 plttID) {
  p->plttID = plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
}

void FUN_080b95d0(ShopCursor* cursor, MainSprite* sprite0, MainSprite* sprite1, MainSprite* sprite2) {
  if (sprite0 != NULL) {
    if (FUN_080b9da0(cursor, 4)) {
      FUN_080b95bc(sprite0, 736);
    } else {
      FUN_080b95bc(sprite0, 735);
    }
  }

  if (sprite1 != NULL) {
    if (FUN_080b9da0(cursor, 8)) {
      FUN_080b95bc(sprite1, 736);
    } else {
      FUN_080b95bc(sprite1, 735);
    }
  }

  if (sprite2 != NULL) {
    if (FUN_080b9da0(cursor, 16)) {
      FUN_080b95bc(sprite2, 736);
    } else {
      FUN_080b95bc(sprite2, 735);
    }
  }
}

// 95/96 命令, x を r0 で作って r4 に移す形にならない
NON_MATCH void FUN_080b9658(MainSpriteGfx* gfx, MainSprite* sprite, Vec3* param_3, s32 param_4, s32 param_5) {
#ifdef NONMATCHING_C
  s32 digits[4];
  s32 x;
  s32 i;

  MainSprite_Show(sprite);
  sprite->pos = *param_3;
  MainSprite_SetPose(sprite, gfx, param_5 + 23, PLAYMODE_LOOP);
  sprite++;
  digits[0] = Div(param_4, 1000);
  param_4 -= digits[0] * 1000;
  digits[1] = Div(param_4, 100);
  param_4 -= digits[1] * 100;
  digits[2] = Div(param_4, 10);
  param_4 -= digits[2] * 10;
  digits[3] = param_4;
  if (param_5 == 0) {
    x = 0;
  } else {
    x = -1;
  }
  for (i = 0; i < 4; i++) {
    MainSprite_Show(sprite);
    MainSprite_SetPose(sprite, gfx, digits[i] + 25, PLAYMODE_LOOP);
    sprite->pos = *param_3;
    sprite->pos.x += x;
    sprite++;
    x += 6;
  }
#else
  INCFUNC("asm/func/FUN_080b9658.inc");
#endif
}

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
  MainSprite_SetAnim(sprite, gfx, animIdx, PLAYMODE_LOOP, 0);
  MainSprite_AdvanceAnim(sprite, gfx);
}

s32 FUN_080b977c(MainSprite* sprite, MainSpriteGfx* gfx, u8* param_3) {
  s32 moved;

  if (gInput[0].pressed & A_BUTTON) {
    MainSprite_Hide(sprite);
    return *param_3;
  }

  if (gInput[0].pressed & B_BUTTON) {
    MainSprite_Hide(sprite);
    return 0;
  }

  moved = FALSE;
  if (*param_3 != 0) {
    if (gInput[0].pressed & DPAD_RIGHT) {
      moved = TRUE;
    }
  } else {
    if (gInput[0].pressed & DPAD_LEFT) {
      moved = TRUE;
    }
  }

  if (moved) {
    PlaySound_082406e0(SE_CURSOR_MOVE);
    *param_3 = 1 - *param_3;
    MainSprite_SetAnim(sprite, gfx, 5 - *param_3, PLAYMODE_LOOP, 0);
  }

  MainSprite_AdvanceAnim(sprite, gfx);
  return -1;
}

void FUN_080b9814(ShopSpritePair* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  Vec3 pos;
  s32 i;

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  pos.x = 0, pos.y = 0, pos.z = 0;
  for (i = 0; i < 2; i++) {
    MainSprite_Add(&p->sprites[i], &p->gfx, 147, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.y += 8;
  }
}

void FUN_080b9894(ShopSpritePair* p) {
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

void FUN_080b98c0(ShopSpritePair* p, s32 pose0, s32 pose1) {
  s32 pose;

  if (pose0 >= 0) {
    p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
    pose = FUN_080b98b0(pose0);
    MainSprite_SetPose(&p->sprites[0], &p->gfx, pose, PLAYMODE_LOOP);
  } else {
    p->sprites[0].flags |= SPRFLAG_HIDDEN;
  }

  if (pose1 >= 0) {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    pose = FUN_080b98b0(pose1);
    MainSprite_SetPose(&p->sprites[1], &p->gfx, pose, PLAYMODE_LOOP);
  } else {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
  }
}

// 枠番号から画面上の表示位置を出す
void Shop_GetSlotPos(s16* pos, s32 idx) {
  if (idx < 16) {
    pos[0] = (idx & 3) * 24 + 144;
    pos[1] = (idx >> 2) * 24 + 32;
  } else if (idx < 32) {
    pos[0] = ((idx - 16) & 3) * 24 + 8;
    pos[1] = ((idx - 16) >> 2) * 24 + 32;
  } else if (idx == 32) {
    pos[0] = 112;
    pos[1] = 64;
  } else if (idx == 33) {
    pos[0] = 120;
    pos[1] = 104;
  } else {
    pos[0] = 104;
    pos[1] = 32;
  }
}

void FUN_080b99a0(ShopSpritePair* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  Vec3 pos;
  s32 i;

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  pos.x = 0, pos.y = 0, pos.z = 0;
  for (i = 0; i < 2; i++) {
    MainSprite_Add(&p->sprites[i], &p->gfx, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

void FUN_080b9a0c(ShopSpritePair* p) {
  s32 i;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void FUN_080b9a28(ShopFlyingPair* p, s32* param_2, WorldPos* pos1, WorldPos* pos2, s32* param_5, s32* param_6, s32 param_7) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (param_2[i] == 0) {
      MainSprite_Hide(&p->pair.sprites[i]);
    } else {
      MainSprite_Show(&p->pair.sprites[i]);
      MainSprite_SetPose(&p->pair.sprites[i], &p->pair.gfx, param_5[i], PLAYMODE_LOOP);
      p->pair.sprites[i].pos = pos1[i];
      p->dest[i] = pos2[i];
    }
  }

  p->timer = 0;
  p->duration = param_7;
}

// 73/73 命令, MainSprite のポインタが flags の位置 (+0x28) を指す形にならずオフセットだけがずれる
NON_MATCH bool32 FUN_080b9adc(unknown* p) {
#ifdef NONMATCHING_C
  ShopFlyingPair* fly = p;
  MainSprite* sprite;
  Vec3* dest;
  s32 remain;
  s32 i;

  if (++fly->timer >= fly->duration) {
    fly->pair.sprites[0].flags |= SPRFLAG_HIDDEN;
    fly->pair.sprites[1].flags |= SPRFLAG_HIDDEN;
    return TRUE;
  }

  remain = fly->duration - fly->timer;
  dest = fly->dest;
  sprite = fly->pair.sprites;
  for (i = 0; i < 2; i++) {
    if (!(sprite->flags & SPRFLAG_HIDDEN)) {
      sprite->pos.x = Div(remain * sprite->pos.x + dest->x, remain + 1);
      sprite->pos.y = Div(remain * sprite->pos.y + dest->y, remain + 1);
    }
    dest++;
    sprite++;
  }

  return FALSE;
#else
  INCFUNC("asm/func/FUN_080b9adc.inc");
#endif
}

// 行と列から実際のスロット番号を引く
s32 ShopCursor_GetSlot(ShopCursor* p) { return SHOP_SLOT(p, p->shopColX, p->shopRowY); }

// 241/255 命令, スロット表を埋めるループのポインタの持ち方が違う
NON_MATCH void FUN_080b9b88(ShopCursor* p) {
#ifdef NONMATCHING_C
  s32 row;
  s32 col;
  s8* special;

  if (FUN_080b9da0(p, 1)) {
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[row + col * 4] = -1;
      }
    }
  } else {
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[row + col * 4] = row * 4 + col;
      }
    }
  }

  special = &p->slots[32];
  if (FUN_080b9da0(p, 2)) {
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[16 + row + col * 4] = -1;
      }
    }
  } else if (!(p->kind & 1)) {
    for (row = 0; row < 3; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[16 + row + col * 4] = 16 + row * 4 + col;
      }
    }
    for (col = 0; col < 4; col++) {
      p->slots[19 + col * 4] = 28 + col;
    }
  } else if (FUN_080b9da0(p, 32)) {
    for (row = 0; row < 4; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[16 + row + col * 4] = p->savedSlot;
      }
    }
  } else {
    for (row = 0; row < 3; row++) {
      for (col = 0; col < 4; col++) {
        p->slots[16 + row + col * 4] = 16 + row * 4 + col;
      }
    }
    for (col = 0; col < 4; col++) {
      p->slots[19 + col * 4] = p->slots[18 + col * 4];
    }
  }

  if (FUN_080b9da0(p, 16)) {
    if (FUN_080b9da0(p, 8)) {
      for (row = 0; row < 4; row++) {
        special[row] = -1;
      }
      return;
    }
    for (row = 0; row < 3; row++) {
      special[row] = -1;
    }
  } else {
    if (p->kind != 1) {
      *special = 34;
      p->slots[33] = -1;
      p->slots[34] = -1;
      if (FUN_080b9da0(p, 8)) {
        p->slots[35] = -1;
      } else {
        p->slots[35] = 33;
      }
      return;
    }
    for (row = 0; row < 3; row++) {
      special[row] = 34;
    }
    if (FUN_080b9da0(p, 8)) {
      p->slots[35] = 34;
      return;
    }
  }

  p->slots[35] = 33;
#else
  INCFUNC("asm/func/FUN_080b9b88.inc");
#endif
}

void FUN_080b9d94(ShopCursor* p, u32 unk) {
  p->unk_7 = unk;
  FUN_080b9b88(p);
}

s32 FUN_080b9da0(ShopCursor* p, u8 mask) { return p->unk_7 & mask; }

// 十字キーの入力を返す, 押しっぱなしのときは10フレームごとに1回だけ返す
s32 ShopCursor_ReadDpad(ShopCursor* p) {
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
s32 ShopCursor_MoveUp(ShopCursor* p) {
  s32 cur = SHOP_SLOT(p, p->shopColX, p->shopRowY);
  u8 rowY = (p->shopRowY + 3) & 3;

  while (rowY != p->shopRowY) {
    s32 slot = SHOP_SLOT(p, p->shopColX, rowY);

    if (slot >= 0 && slot != cur) {
      p->shopRowY = rowY;
      p->slot = ShopCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    rowY = (rowY + 3) & 3;
  }
  return 0;
}

// 同じ行を右へ辿って別のスロットへカーソルを移す
s32 ShopCursor_MoveDown(ShopCursor* p) {
  s32 cur = SHOP_SLOT(p, p->shopColX, p->shopRowY);
  u8 rowY = (p->shopRowY + 1) & 3;

  while (rowY != p->shopRowY) {
    s32 slot = SHOP_SLOT(p, p->shopColX, rowY);

    if (slot >= 0 && slot != cur) {
      p->shopRowY = rowY;
      p->slot = ShopCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    rowY = (rowY + 1) & 3;
  }
  return 0;
}

// 同じ列を上へ辿って別のスロットへカーソルを移す
s32 ShopCursor_MoveLeft(ShopCursor* p) {
  s32 orig = p->shopColX;
  s32 cur = SHOP_SLOT(p, orig, p->shopRowY);
  s32 colX = orig - 1;

  if (orig == 0) {
    colX = 8;
  }

  while (colX != orig) {
    s32 slot = SHOP_SLOT(p, colX, p->shopRowY);

    if (slot >= 0 && slot != cur) {
      p->shopColX = colX;
      p->slot = ShopCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    if (colX == 0) {
      colX = 8;
    } else {
      colX--;
    }
  }
  return 0;
}

// 同じ列を下へ辿って別のスロットへカーソルを移す
s32 ShopCursor_MoveRight(ShopCursor* p) {
  s32 orig = p->shopColX;
  s32 cur = SHOP_SLOT(p, orig, p->shopRowY);
  s32 colX = orig + 1;

  if (orig == 8) {
    colX = 0;
  }

  while (colX != orig) {
    s32 slot = SHOP_SLOT(p, colX, p->shopRowY);

    if (slot >= 0 && slot != cur) {
      p->shopColX = colX;
      p->slot = ShopCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    if (colX == 8) {
      colX = 0;
    } else {
      colX++;
    }
  }
  return 0;
}

// 押された方向キーに応じてカーソル移動を振り分ける
s32 ShopCursor_Move(ShopCursor* p) {
  s32 keys = ShopCursor_ReadDpad(p);

  if (keys & DPAD_UP) return ShopCursor_MoveUp(p);
  if (keys & DPAD_DOWN) return ShopCursor_MoveDown(p);
  if (keys & DPAD_LEFT) return ShopCursor_MoveLeft(p);
  if (keys & DPAD_RIGHT) return ShopCursor_MoveRight(p);
  return 0;
}

// スプライトをカーソルのある枠の位置へ置く
void ShopCursor_PlaceSprite(ShopCursor* p, MainSprite* sprite) { Shop_GetSlotPos(&sprite->pos.x, (u8)p->slot); }

// カーソルの位置を退避する
void FUN_080b9fd8(ShopCursor* p) {
  p->savedShopColX = p->shopColX;
  p->savedShopRowY = p->shopRowY;
  p->savedSlot = p->slot;
}

// 退避したカーソルの位置を戻す
void FUN_080b9fe8(ShopCursor* p) {
  p->shopColX = p->savedShopColX;
  p->shopRowY = p->savedShopRowY;
  p->slot = p->savedSlot;
}

// カーソルを初期化して行と列から実際のスロット番号を引く
void ShopCursor_Init(ShopCursor* p, u32 kind, u32 col, u32 row, u32 unk) {
  p->kind = kind;
  FUN_080b9d94(p, unk);
  p->shopColX = col;
  p->shopRowY = row;
  p->slot = ShopCursor_GetSlot(p);
  p->unk_8 = 0;
}
