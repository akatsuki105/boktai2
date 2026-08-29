#include "global.h"

INCASM("asm/code_0821b21c.inc");

/**
 * @brief 文字列を描画する(セーブデータ選択画面で使用されているが、NPCなどとの会話やメニュー画面では使用されていない)
 * @param x8 描画先のx座標(8x8pxのタイル単位)
 * @param y8 描画先のy座標(8x8pxのタイル単位)
 */
NAKED void Video_DrawText(s32 x8, s32 y8, char* s) { INCFUNC("asm/func/Video_DrawText.inc"); }
