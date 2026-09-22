#ifndef __INCLUDE_TEXT_H__
#define __INCLUDE_TEXT_H__

#include "gba/gba.h"
#include "types.h"

// 枠内に文字を流し込む描画器。TextBox のほか EntityDFC6 / Entity6273 も同じものを1つずつ持つ
// 根拠: FUN_0804967c (初期化) / FUN_08049650 (矩形) / FUN_08049668 (速度) / FUN_08049884 / FUN_08049890
typedef struct {
  u8 cursorX;  // 0x000, FUN_08049650 が rectX を書き込む描画位置
  u8 cursorY;  // 0x001, FUN_08049650 が rectY を書き込む描画位置
  u8 rectX;    // 0x002, FUN_08049650 の第2引数, TextBox_GetRect が返す4つ組の1番目
  u8 rectY;    // 0x003, FUN_08049650 の第3引数
  u8 rectW;    // 0x004, FUN_08049650 の第4引数
  u8 rectH;    // 0x005, FUN_08049650 の第5引数
  u8 unk_06[0x09 - 0x06];
  u8 speed;  // 0x009, FUN_08049668 が gStat->unk_12 (メッセージ速度設定) を入れる。0x0C にも同じ値を複製する
  u8 unk_0a[0x0D - 0x0A];
  u8 scriptIdCount;  // 0x00D, scriptIds の使用数, TextBox_Init が script keyword 'p' の並びを積むときに +1 する
  u8 unk_0e[0x11 - 0x0E];
  u8 unk_11;  // 0x011, TextBox_Init が 0 を入れるだけ
  u8 unk_12[0x15 - 0x12];
  s8 face;  // 0x015, FUN_0804967c が 0xFF を入れる。TextBox が顔スプライトのポーズ番号として読む
  u8 unk_16[2];
  u32 unk_18;  // 0x018, TextBox_Update が毎フレーム TextBox.waitFrames へ移してから 0 に戻す
  char* text;  // 0x01C, FUN_0804967c が NULL を入れ、TextBox_Init / TextBox_ShowLine が TextBox_GetLine の戻り値 (行頭ポインタ) を入れる
  u8 unk_20[0xC4 - 0x20];
  s32 scriptIds[16];  // 0x0C4, script keyword 'p' で積まれたスクリプトID, 0x104 の直前までで16個
  u8 stackDepth;      // 0x104, FUN_08048934 が 7 未満のときだけ積む
  u8 stack[7];        // 0x105, FUN_08048934 が 0x07 の値を退避する
  u8 unk_10c[0x14C - 0x10C];
  u32 pendingCount;  // 0x14C, FUN_08049884 が毎フレーム 0 に戻し、FUN_08049890 がこの数だけ pending を実行する
  u8 pending[16];    // 0x150, FUN_08049890 が scriptIds の添字として読む, 構造体末尾までで16個
} TextRenderer;
static_assert(sizeof(TextRenderer) == 352);

// --------------------------------------------

s32 TextBox_SetRect(s32 x, s32 y, s32 w, s32 h);
s32 TextBox_Start(u8* pc);
s32 TextBox_SetInstant(s32 instant);
s32 TextBox_ShowLine(s32 line);
s32 TextBox_SetVarValue(s32 idx, s32 value);
s32 TextBox_Close(void);
s32 TextBox_StrNCmp(u8* s, const char* lit, s32 n);

#endif  // __INCLUDE_TEXT_H__
