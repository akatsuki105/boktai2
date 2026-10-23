#include "font.h"
#include "global.h"
#include "text.h"

NAKED bool32 FUN_0821b21c(unknown* param_1, s32 val1, s32 val2, u16 val3) { INCFUNC("asm/func/FUN_0821b21c.inc"); }

void FUN_0821b28c(u32 x8, u32 y8, u32 w8, u32 h8) {
  Font_ReleaseRect(x8, y8, w8, h8);
  Font_FillRect(x8, y8, w8, h8);
}

/**
 * @brief 文字列を描画する(セーブデータ選択画面で使用されているが、NPCなどとの会話やメニュー画面では使用されていない)
 * @param x8 描画先のx座標(8x8pxのタイル単位)
 * @param y8 描画先のy座標(8x8pxのタイル単位)
 */
// 残差は命令数一致 (78/78) のループ形だけ, 原典は上テスト + 無条件の戻り, こちらは入口ジャンプ + 底テストに回される (while / for(;;)+break / s8 ローカル いずれも同じ)
NON_MATCH void Video_DrawText(s32 x8, s32 y8, char* s) {
#ifdef NONMATCHING_C
  u16 c;
  s32 x = x8;
  s32 y = y8;
  s32 style = 0;

  for (;;) {
    if (*s == 0) {
      break;
    }

    if ((s8)*s >= 0) {
      if (*s == '<') {
        style = 1;
        s = Text_FindChar(s, '>');
      } else if (*s == '\n') {
        x = x8;
        y += 2;
      } else {
        c = *s - 0x20;
        Font_DrawHankakuChar(c, x, y, style);
        x++;
      }
    } else {
      c = (*s & 0x7F) << 8;
      s++;
      c |= *s;
      if (c >= Font_GetZenkakuCharCount()) {
        x += 2;
      } else {
        Font_DrawZenkakuChar(c, x, y, style);
        x += 2;
        if (style == 1) {
          s++;
          s = Text_FindChar(s, '>');
          style = 0;
        }
      }
    }
    s++;
  }
#else
  INCFUNC("asm/func/Video_DrawText.inc");
#endif
}
