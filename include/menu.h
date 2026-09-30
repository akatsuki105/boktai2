#ifndef __INCLUDE_MENU_H__
#define __INCLUDE_MENU_H__

#include "gba/gba.h"
#include "sprite_main.h"
#include "types.h"

// MainSpriteGfx ひとつと、そこから作った MainSprite 2枚をまとめた表示部品, メニュー系のエンティティが共通で持つ
typedef struct {
  MainSpriteGfx gfx;      // 0x00, FUN_080b99a0 / FUN_080b9814 が OpenMainSpriteFile で作る
  MainSprite sprites[2];  // 0x20, FUN_080b9a0c / FUN_080b9894 が MainSprite_Remove する
} MenuSpritePair;
static_assert(sizeof(MenuSpritePair) == 224);

// メニューのカーソル, 行と列から slots を引いて実際のスロット番号を出す
typedef struct {
  u8 kind;       // 0x00, FUN_080b9ff8 の第1引数
  u8 row;        // 0x01, slots の行
  u8 col;        // 0x02, slots の列
  s8 slot;       // 0x03, slots[row][col] の結果, FUN_080b9938 がこれから画面座標を出す
  u8 unk_4[3];   // 0x04, まだ未解析
  u8 unk_7;      // 0x07, FUN_080b9d94 の第2引数
  u8 unk_8;      // 0x08, FUN_080b9ff8 が 0 を入れる
  u8 unk_9[3];   // 0x09, まだ未解析
  s8 slots[36];  // 0x0C, FUN_080b9b74 が [row * 4 + col] で引く
} MenuCursor;
static_assert(sizeof(MenuCursor) == 48);

#endif  // __INCLUDE_MENU_H__
