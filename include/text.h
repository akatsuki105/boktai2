#ifndef __INCLUDE_TEXT_H__
#define __INCLUDE_TEXT_H__

#include "gba/gba.h"
#include "types.h"

// テキスト表示まわりの構成
//
//   TextRenderer   文字列を1歩ずつ進めるエンジン, エンティティではなく、下の3つが1つずつ内部に持つ
//     |            枠も id もフレームも知らず、渡された char* を進めてタグを展開するだけ
//     +- MessageWindow  画面に1つしかない共有の本文表示領域 (src/message_window.c)
//     |    |            使う側が MessageWindow_SetRect で設定し直して借りる, 顔グラ・送り矢印・オート送り・行ラベルつき
//     |    |            会話だけでなく gameover / dungeon_title / credits / 各種図鑑も使う
//     |    +- MessageChoice  MessageWindow を操作して <ALTER> を選択肢として選ばせる UI (src/message_choice.c)
//     |                       自分では描かず、カーソルのスプライトを左右に置く
//     +- TextPanel      各画面が必要なだけ自分で開き、id で持って自分で閉じる追加パネル (src/text_panel.c)
//     |                 TextPanelManager が双方向リストで抱え、複数同時に存在できる
//     +- Marquee        おそらく横スクロールするテキスト (src/text_marquee.c), offset を毎フレーム進めて gMarqueeOffset に流す
//
// MessageWindow と TextPanel の違いは用途ではなく所有関係, どちらも同じ BG0 のタイルマップに描く
// (閉じるときの FUN_0822EA60 が GetTilemapBuffer(0) を使う)

// 枠内に文字を流し込む描画器, MessageWindow のほか Marquee / TextPanel も同じものを1つずつ持つ
// 根拠: TextRenderer_Init (初期化) / TextRenderer_SetRect (矩形) / TextRenderer_ResetSpeed (速度) / TextRenderer_Advance (1歩進める) / TextRenderer_ClearPending / TextRenderer_RunPending
typedef struct {
  u8 cursorX;            // 0x000, TextRenderer_SetRect が rectX を書き込む描画位置
  u8 cursorY;            // 0x001, TextRenderer_SetRect が rectY を書き込む描画位置
  u8 rectX;              // 0x002, TextRenderer_SetRect の第2引数, MessageWindow_GetRect が返す4つ組の1番目
  u8 rectY;              // 0x003, TextRenderer_SetRect の第3引数
  u8 rectW;              // 0x004, TextRenderer_SetRect の第4引数
  u8 rectH;              // 0x005, TextRenderer_SetRect の第5引数
  u8 style;              // 0x006, Font_DrawXXXkakuChar の第4引数, WEIGHT/ALTER タグで 1、NONSEL/UVMOJI タグで 2、閉じタグで 0
  u8 mode;               // 0x007, TextRenderer_Advance がこれで分岐する, 0 なら text、 1 なら textAlt を進める
  u8 frameCounter;       // 0x008, MessageWindow_StateType が毎フレーム数え, speed に届いたら 0 に戻して TextRenderer_Advance を呼ぶ
  u8 speed;              // 0x009, TextRenderer_ResetSpeed が gStat->unk_12 (メッセージ速度設定) を入れる, 0x0C にも同じ値を複製する
  bool8 muteCharSound;   // 0x00A, 立っている間 TextRenderer_PlayCharSound は鳴らさない, MessageWindow_StateType が '.m' を入れ, 一気に描く状態と Marquee は 1
  bool8 silent;          // 0x00B, LABEL タグと TextPanel_Create が立てる, 立っている間 TextRenderer_PlayCharSound は鳴らさない
  u8 savedSpeed;         // 0x00C, LABEL タグが speed を退避して speed を 0 にし、/LABEL が戻す
  u8 scriptIdCount;      // 0x00D, scriptIds の使用数, MessageWindow_Init が '.p' の並びを積むときに +1 する
  bool8 stopAtTag;       // 0x00E, この1歩がタグで止まったら TRUE, TextRenderer_DrawNextChar はそこで戻り, '>' を読み飛ばす, TextRenderer_Advance が毎回 0 に戻す
  bool8 finished;        // 0x00F, 0 以外なら TextRenderer_Advance が 1 (終了) を返す
  bool8 parenEnabled;    // 0x010, 立っていないと PAREN / /PAREN タグが括弧を描かない
  u8 charSoundIdx;       // 0x011, gCharSounds の添字, MOJISE_SYSTEM タグで 0、MOJISE_TALK タグで 1
  u8 soundToggle;        // 0x012, 0/1 を往復して1文字おきに文字送り音を鳴らす
  bool8 drewWide;        // 0x013, 直前に描いた文字が全角なら TRUE
  bool8 tagsInline;      // 0x014, 0 ならどのタグでも stopAtTag を立てる, 1 なら差し込みを始めるタグ以外は同じ1歩で続けて描く, TextRenderer_Init が 1 を入れる
  s8 face;               // 0x015, TextRenderer_Init が 0xFF を入れる, MessageWindow が顔スプライトのポーズ番号として読む
  bool8 soundEveryChar;  // 0x016, TextRenderer_PlayCharSound が speed > 1 のときだけ読む, TRUE なら1文字おきの間引きをやめて毎文字鳴らす
  u8 unk_17;             // 0x017, padding?
  u32 waitFrames;        // 0x018, LOCK タグの値, MessageWindow_Update が毎フレーム MessageWindow.waitFrames へ移してから 0 に戻す
  char* text;            // 0x01C, TextRenderer_Init が NULL を入れ、MessageWindow_Init / MessageWindow_ShowLine が MessageWindow_GetLine の戻り値 (行頭ポインタ) を入れる
  char* textAlt;         // 0x020, mode が 1 のとき TextRenderer_Advance が進めるもう一方の文字列
  char* numText;         // 0x024, VAR タグが numBuf を指させる, mode が 2 のとき TextRenderer_Advance がここを進める
  char* extendText;      // 0x028, EXTEND タグが extends[i] を指させる, mode が 3 のとき TextRenderer_Advance がここを進める
  bool32 tagHasValue;    // 0x02C, TextRenderer_ReadTagValue がタグの中で '=' を見たら TRUE
  u32 tagValueLen;       // 0x030, tagValue に積んだ文字数
  char tagValue[68];     // 0x034, TextRenderer_ReadTagValue が '=' の後ろから '>' までを最大64文字写す
  char numBuf[12];       // 0x078, VAR タグが Text_FormatDecimal で vars[i] を10進に直す先, numText が指す
  s32 vars[16];          // 0x084, <VAR=idx> で参照される
  s32 scriptIds[16];     // 0x0C4, '.p' で積まれたスクリプトID, 0x104 の直前までで16個
  u8 stackDepth;         // 0x104, TextRenderer_PushMode が 7 未満のときだけ積む
  u8 stack[7];           // 0x105, TextRenderer_PushMode が 0x07 の値を退避する
  char* extends[16];     // 0x10C, <EXTEND=idx> で参照される
  u32 pendingCount;      // 0x14C, TextRenderer_ClearPending が毎フレーム 0 に戻し、TextRenderer_RunPending がこの数だけ pending を実行する
  u8 pending[16];        // 0x150, TextRenderer_RunPending が scriptIds の添字として読む, 構造体末尾までで16個
} TextRenderer;
static_assert(sizeof(TextRenderer) == 352);

// --------------------------------------------

s32 MessageWindow_SetRect(s32 x, s32 y, s32 w, s32 h);
s32 MessageWindow_Start(u8* pc);
s32 MessageWindow_SetInstant(s32 instant);
s32 MessageWindow_ShowLine(s32 line);
s32 MessageWindow_SetExtendValue(s32 idx, char* text);
s32 MessageWindow_SetBgPltt(s32 fileID);
s32 MessageWindow_SetVarValue(s32 idx, s32 value);
s32 MessageWindow_Close(void);
bool32 MessageWindow_IsFinished(void);
s32 MessageWindow_GetExtendWidth(s32 idx);
s32 MessageWindow_GetVarWidth(s32 idx);
s32 MessageWindow_GetRect(s32* rect);

// 文字列ヘルパー, TextRenderer のタグ解析と MessageChoice が使う
s32 Text_StrNCmp(u8* s, const char* lit, s32 n);
s32 Text_ParseDecimal(u8* s, s32 len);
u8* Text_FindChar(u8* s, u8 c);
u16 Text_GetEscapeCharcode(u8* s);

void TextRenderer_Init(TextRenderer* p, s32 x, s32 y, s32 width, s32 height);
void TextRenderer_SetRect(TextRenderer* p, s32 x, s32 y, s32 width, s32 height);
void TextRenderer_ClearPending(TextRenderer* p);
void TextRenderer_RunPending(TextRenderer* p);
s32 TextRenderer_Advance(TextRenderer* p);
void TextRenderer_ResetModeStack(TextRenderer* p);
s32 TextRenderer_SetVar(TextRenderer* p, s32 idx, u32 value);  // 文字列の <VAR=idx> に対応する値を設定する
s32 TextRenderer_SetExtend(TextRenderer* p, s32 idx, char* str);
s32 TextRenderer_GetVarWidth(TextRenderer* p, s32 idx);
s32 TextRenderer_GetExtendWidth(TextRenderer* p, s32 idx);
s32 TextRenderer_GetTextWidth(TextRenderer* p);

s32 TextPanel_Create(s32 x, s32 y, s32 width, s32 height);
s32 TextPanel_Destroy(s32 id);
void TextPanelManager_DestroyAll(void);
s32 TextPanel_Start(s32 id);
s32 TextPanel_Hide(s32 id);
s32 TextPanel_SetScript(s32 id, u8* scriptPc);
s32 TextPanel_SetRect(s32 id, s32 x, s32 y, s32 width, s32 height);
s32 TextPanel_SetMessage(s32 id, s32 msgIdx);
s32 FUN_0804a40c(s32 id, s32 idx, char* str);

s32 Marquee_Clear(void);
s32 Marquee_RequestClose(void);
s32 FUN_08049f5c(void);
s32 Marquee_SetText(char* str);
s32 Marquee_CloseGlobal(void);

static inline void TextRenderer_GetRect(TextRenderer* r, u32* out) { out[0] = r->rectX, out[1] = r->rectY, out[2] = r->rectW, out[3] = r->rectH; }
static inline void TextRenderer_SetFinished(TextRenderer* r, bool8 finished) { r->finished = finished; }

#endif  // __INCLUDE_TEXT_H__
