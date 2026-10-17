#ifndef __INCLUDE_MENU_H__
#define __INCLUDE_MENU_H__

#include "gba/gba.h"

// メニューのカーソル, 行と列から slots を引いて実際のスロット番号を出す
typedef struct {
  u8 kind;       // 0x00, MenuCursor_Init の第1引数
  u8 row;        // 0x01, slots の行
  u8 col;        // 0x02, slots の列
  s8 slot;       // 0x03, slots[row][col] の結果, FUN_080b9938 がこれから画面座標を出す
  u8 savedRow;   // 0x04, FUN_080b9fd8 が row を退避し、FUN_080b9fe8 が戻す
  u8 savedCol;   // 0x05, 同じく col
  s8 savedSlot;  // 0x06, 同じく slot
  u8 unk_7;      // 0x07, FUN_080b9d94 の第2引数
  u8 unk_8;      // 0x08, MenuCursor_Init が 0 を入れる
  u8 unk_9[3];   // 0x09, まだ未解析
  s8 slots[36];  // 0x0C, MenuCursor_GetSlot が [row * 4 + col] で引く
} MenuCursor;
static_assert(sizeof(MenuCursor) == 48);

#endif  // __INCLUDE_MENU_H__
