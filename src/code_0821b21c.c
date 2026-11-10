#include "font.h"
#include "global.h"
#include "text.h"
#include "video.h"

// fade[1] を dir (0: 明るく, 1: 暗く) へ duration フレームかけて進め, fade[0] と BG / OBJ の明るさに反映する, 端に着いたら TRUE
// 残差1命令, 原典は gObjBrightness の前に fade の上位16ビットを ldrh で読み直す, ((u16*)fade)[1] は1回に畳まれる
// u16* のローカルに出すと読み直すがレジスタが1本増える, (u32)fade[0] >> 16 は ldrh にならない
NON_MATCH bool32 Video_StepBrightnessFade(s32* fade, s32 dir, s32 duration, u16 rowMask) {
#ifdef NONMATCHING_C
  bool32 done = FALSE;

  switch (dir) {
    case 0: {
      if (++fade[1] >= duration) {
        fade[1] = duration;
        done = TRUE;
      }
      break;
    }
    case 1: {
      if (--fade[1] <= 0) {
        fade[1] = 0;
        done = TRUE;
      }
      break;
    }
  }
  fade[0] = Div(fade[1] << 24, duration << 2);
  gBgBrightness = ((u16*)fade)[1];
  gObjBrightness = ((u16*)fade)[1];
  gBgPlttFadeRowMask |= rowMask;
  gObjPlttFadeSkipMask = 0;
  return done;
#else
  INCFUNC("asm/func/Video_StepBrightnessFade.inc");
#endif
}

void Video_ClearTextRect(u32 x8, u32 y8, u32 w8, u32 h8) {
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
