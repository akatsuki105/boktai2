#ifndef __INCLUDE_SHOP_H__
#define __INCLUDE_SHOP_H__

#include "gba/gba.h"
#include "sprite_main.h"
#include "types.h"

/*
  ショップUI
  道具屋,武器屋,棺桶屋,倉庫, 通信販売 のUI (太陽鍛治は別)
  このようにインベントリUIが2つ並んで表示される(左側は店, 右側はプレイヤー)
  左側は 倉庫は 4x4 で、 道具屋,武器屋,棺桶屋 は 4x3 で表示される (プレイヤー側は常に4x4)
  内部的には 1つの大きなインベントリUIとして扱われる
  プレイヤーインベントリ が 0..3 列目, 店側が 4..7 列目
  店によってインベントリの外に追加のUI要素(売る や 整頓 など)が表示され、それらは (UIの場所には関係なく) 8列目 として扱われる
  またスロット番号は、正確には row*4 + col で求めるのではなく、 .slots[col*4 + row]  がスロット番号になる (col*4 なのがややこしいし、結局追加UIを除いて row*4 + col と同じ値になるのがさらにややこしい)

    4    5    6    7            0    1    2    3
  +----+----+----+----+        +----+----+----+----+
0 | 16 | 17 | 18 | 19 |      0 | 00 | 01 | 02 | 03 |
  +----+----+----+----+        +----+----+----+----+
1 | 20 | 21 | 22 | 23 |      1 | 04 | 05 | 06 | 07 |
  +----+----+----+----+        +----+----+----+----+
2 | 24 | 25 | 26 | 27 |      2 | 08 | 09 | 10 | 11 |
  +----+----+----+----+        +----+----+----+----+
3 | 28 | 29 | 30 | 31 |      3 | 12 | 13 | 14 | 15 |
  +----+----+----+----+        +----+----+----+----+
*/

// ショップUIのカーソル, 行と列から slots を引いて実際のスロット番号を出す
// InventoryCursor とほとんど同じもの (処理も同じ)
typedef struct {
  u8 kind;           // 0x00, 0: 4x4(倉庫, 通信販売), 1: 4x3 (道具屋, 武器屋, 棺桶屋)
  u8 shopColX;       // 0x01, カーソルの現在の列 (0..3: プレイヤー, 4..7: 店側, 8: 追加UI)
  u8 shopRowY;       // 0x02, カーソルの現在の行 (0..3)
  s8 slot;           // 0x03, カーソルが指しているスロット番号 (slots[col*4 + row] の結果)
  u8 savedShopColX;  // 0x04, FUN_080b9fd8 が row を退避し、FUN_080b9fe8 が戻す
  u8 savedShopRowY;  // 0x05, 同じく col
  s8 savedSlot;      // 0x06, 同じく slot
  u8 unk_7;          // 0x07, FUN_080b9d94 の第2引数
  u8 unk_8;          // 0x08, ShopCursor_Init が 0 を入れる
  u8 unk_9[3];       // 0x09, まだ未解析, padding?
  s8 slots[36];      // 0x0C, col と row がどのスロット番号になるかの LUT, slots[col*4 + row]
} ShopCursor;
static_assert(sizeof(ShopCursor) == 48);

// MainSpriteGfx ひとつと、そこから作った MainSprite 2枚をまとめた表示部品, ショップ系のエンティティが共通で持つ
typedef struct {
  MainSpriteGfx gfx;      // 0x00, SPRITE_UI_START_MENU (FUN_080b9814) or SPRITE_INVENTORY_ICONS (FUN_080b99a0)
  MainSprite sprites[2];  // 0x20
} ShopSpritePair;
static_assert(sizeof(ShopSpritePair) == 224);

void FUN_080b95d0(ShopCursor* cursor, MainSprite* sprite0, MainSprite* sprite1, MainSprite* sprite2);
void FUN_080b9a0c(ShopSpritePair* p);
void FUN_080b9400(s32 kind);
void FUN_080b94cc(s32 kind);
void FUN_080b9894(ShopSpritePair* p);
void ShopCursor_Init(ShopCursor* p, u32 kind, u32 row, u32 col, u32 unk);
void ShopCursor_PlaceSprite(ShopCursor* p, MainSprite* sprite);
s32 FUN_080b977c(MainSprite* sprite, MainSpriteGfx* gfx, u8* param_3);
void FUN_080b9fe8(ShopCursor* p);
void FUN_080b9d94(ShopCursor* p, u32 unk);
void Shop_GetSlotPos(s16* pos, s32 idx);
void FUN_080b98c0(MainSpriteGfx* gfx, s32 param_2, s32 param_3);
void FUN_080b95bc(MainSprite* p, u16 plttID);
void FUN_080b99a0(ShopSpritePair* p);
void FUN_080b9814(ShopSpritePair* p);
bool32 FUN_080b9adc(unknown* p);
void FUN_080b9740(MainSprite* sprite, MainSpriteGfx* gfx, char* out, s32 val);
s32 ShopCursor_Move(ShopCursor* p);
void FUN_080b9fd8(ShopCursor* p);
void FUN_080b9a28(MainSpriteGfx* gfx, s32* param_2, WorldPos* pos1, WorldPos* pos2, s32* param_5, s32* param_6, s32 param_7);
void FUN_080b9724(MainSprite* sprites);
void FUN_080b9658(MainSpriteGfx* gfx, MainSprite* sprite, unknown* param_3, s32 param_4, s32 param_5);

#define SHOP_SLOT(p, colX, rowY) ((p)->slots[(rowY) + (colX) * 4])

#endif  // __INCLUDE_SHOP_H__
