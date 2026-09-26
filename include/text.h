#ifndef __INCLUDE_TEXT_H__
#define __INCLUDE_TEXT_H__

#include "gba/gba.h"
#include "types.h"

// テキスト表示まわりの構成
//
//   TextRenderer   文字列を1歩ずつ進めるエンジン, エンティティではなく、下の3つが1つずつ内部に持つ
//     |            枠も id もフレームも知らず、渡された char* を進めてタグを展開するだけ
//     +- TextBox       画面に1つしかない共有の本文表示領域 (src/text_0e37.c)
//     |    |           使う側が TextBox_SetRect で設定し直して借りる, 顔グラ・送り矢印・オート送り・行ラベルつき
//     |    |           会話だけでなく gameover / title_card / credits / 各種図鑑も使う
//     |    +- TextBoxChoice  TextBox を操作して <ALTER> を選択肢として選ばせる UI (src/textbox_choice.c)
//     |                      自分では描かず、カーソルのスプライトを左右に置く
//     +- TextPanel     各画面が必要なだけ自分で開き、id で持って自分で閉じる追加パネル (src/text_panel.c)
//     |                TextPanelManager が双方向リストで抱え、複数同時に存在できる
//     +- EntityDFC6    未解明 (src/text_dfc6.c), offset を毎フレーム進めて DAT_03002CE8 に流す
//
// TextBox と TextPanel の違いは用途ではなく所有関係, どちらも同じ BG0 のタイルマップに描く
// (閉じるときの FUN_0822EA60 が GetTilemapBuffer(0) を使う)

// 枠内に文字を流し込む描画器, TextBox のほか EntityDFC6 / TextPanel も同じものを1つずつ持つ
// 根拠: TextRenderer_Init (初期化) / TextRenderer_SetRect (矩形) / FUN_08049668 (速度) / TextRenderer_Advance (1歩進める) / TextRenderer_ClearPending / TextRenderer_RunPending
typedef struct {
  u8 cursorX;        // 0x000, TextRenderer_SetRect が rectX を書き込む描画位置
  u8 cursorY;        // 0x001, TextRenderer_SetRect が rectY を書き込む描画位置
  u8 rectX;          // 0x002, TextRenderer_SetRect の第2引数, TextBox_GetRect が返す4つ組の1番目
  u8 rectY;          // 0x003, TextRenderer_SetRect の第3引数
  u8 rectW;          // 0x004, TextRenderer_SetRect の第4引数
  u8 rectH;          // 0x005, TextRenderer_SetRect の第5引数
  u8 unk_06;         // 0x006, FUN_08049640 が stackDepth と一緒に 0 を入れる
  u8 mode;           // 0x007, TextRenderer_Advance がこれで分岐する,  0 なら text、 1 なら textAlt を進める
  u8 unk_08;         // 0x008, FUN_08049668 が速度を読む直前に 0 を入れる
  u8 speed;          // 0x009, FUN_08049668 が gStat->unk_12 (メッセージ速度設定) を入れる, 0x0C にも同じ値を複製する
  u8 unk_0a;         // 0x00A, TextRenderer_Init が 0 を入れる
  u8 unk_0b;         // 0x00B, TextRenderer_Init が 0 を入れる
  u8 unk_0c;         // 0x00C, TextRenderer_Init が speed を複製する
  u8 scriptIdCount;  // 0x00D, scriptIds の使用数, TextBox_Init が '.p' の並びを積むときに +1 する
  u8 unk_0e;         // 0x00E, TextRenderer_Advance が呼ばれるたび 0 に戻す
  bool8 finished;    // 0x00F, 0 以外なら TextRenderer_Advance が 1 (終了) を返す
  u8 unk_10;         // 0x010
  u8 unk_11;         // 0x011, TextBox_Init が 0 を入れるだけ
  u8 unk_12;         // 0x012
  u8 unk_13;         // 0x013, TextRenderer_Init が 0 を入れる
  u8 unk_14;         // 0x014, TextRenderer_Init が 1 を入れる
  s8 face;           // 0x015, TextRenderer_Init が 0xFF を入れる, TextBox が顔スプライトのポーズ番号として読む
  u8 unk_16[2];      // 0x016, padding?
  u32 unk_18;        // 0x018, TextBox_Update が毎フレーム TextBox.waitFrames へ移してから 0 に戻す
  char* text;        // 0x01C, TextRenderer_Init が NULL を入れ、TextBox_Init / TextBox_ShowLine が TextBox_GetLine の戻り値 (行頭ポインタ) を入れる
  char* textAlt;     // 0x020, mode が 1 のとき TextRenderer_Advance が進めるもう一方の文字列
  u32 unk_24;        // 0x024, TextRenderer_Init が 0 を入れる
  u32 unk_28;        // 0x028, TextRenderer_Init が 0 を入れる
  u8 unk_2c[0x84 - 0x2C];
  s32 vars[16];       // 0x084, TextRenderer_SetVar が書き、TextRenderer_GetVarWidth が符号つき10進の桁数を数える, TextBox_SetVarValue の格納先
  s32 scriptIds[16];  // 0x0C4, '.p' で積まれたスクリプトID, 0x104 の直前までで16個
  u8 stackDepth;      // 0x104, FUN_08048934 が 7 未満のときだけ積む
  u8 stack[7];        // 0x105, FUN_08048934 が 0x07 の値を退避する
  char* extends[16];  // 0x10C, TextRenderer_SetExtend が書き、TextRenderer_GetExtendWidth が文字列として走査する, TextBox_SetExtendValue の格納先
  u32 pendingCount;   // 0x14C, TextRenderer_ClearPending が毎フレーム 0 に戻し、TextRenderer_RunPending がこの数だけ pending を実行する
  u8 pending[16];     // 0x150, TextRenderer_RunPending が scriptIds の添字として読む, 構造体末尾までで16個
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
bool32 TextBox_IsFinished(void);
s32 TextBox_ParseDecimal(u8* s, s32 len);
u8* TextBox_FindChar(u8* s, u8 c);
s32 TextBox_GetExtendWidth(s32 idx);
s32 TextBox_GetVarWidth(s32 idx);
s32 TextBox_GetRect(s32* rect);

void TextRenderer_Init(TextRenderer* p, u8 x, u8 y, u8 width, u8 height);
void TextRenderer_SetRect(TextRenderer* p, s32 x, s32 y, s32 width, s32 height);
void TextRenderer_ClearPending(TextRenderer* p);
void TextRenderer_RunPending(TextRenderer* p);
s32 TextRenderer_Advance(TextRenderer* p);
void FUN_08049640(TextRenderer* p);
void TextRenderer_SetVar(TextRenderer* p, s32 idx, u32 value);
s32 TextRenderer_SetExtend(TextRenderer* p, s32 idx, u32 str);
s32 TextRenderer_GetVarWidth(TextRenderer* p, s32 idx);
s32 TextRenderer_GetExtendWidth(TextRenderer* p, s32 idx);
s32 FUN_08048c58(TextRenderer* p);

s32 TextPanel_Create(s32 x, s32 y, s32 width, s32 height);
s32 TextPanel_Start(s32 id);
s32 TextPanel_Hide(s32 id);
s32 TextPanel_SetScript(s32 id, u8* scriptPc);
s32 TextPanel_SetMessage(s32 id, s32 msgIdx);

static inline void TextRenderer_GetRect(TextRenderer* r, u32* out) { out[0] = r->rectX, out[1] = r->rectY, out[2] = r->rectW, out[3] = r->rectH; }
static inline void TextRenderer_SetFinished(TextRenderer* r, bool8 finished) { r->finished = finished; }

#endif  // __INCLUDE_TEXT_H__
