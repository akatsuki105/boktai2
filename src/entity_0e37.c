#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "text.h"

struct TextBox;
typedef void (*TextBoxFunc)(struct TextBox* p);

// メッセージウィンドウ。文字送り・顔グラ・送り矢印・オートモードを持つ
typedef struct TextBox {
  Entity e;                // 0x000, ENTITY_UNK_12
  TextRenderer renderer;   // 0x018
  u8 rectX;                // 0x178, script keyword 'r' の1番目, TextRenderer_SetRect と FUN_0822ea60 に渡す
  u8 rectY;                // 0x179, script keyword 'r' の2番目
  u8 rectW;                // 0x17A, script keyword 'r' の3番目
  u8 rectH;                // 0x17B, script keyword 'r' の4番目
  s16 lineIdx;             // 0x17C, script keyword 'i', TextBox_GetLine(p, lineIdx) が行頭ポインタを返す。次の行へ進むとき +1
  u8 unk_17e;              // 0x17E, 0 なら fn = TextBox_StateType (1文字ずつ表示), 0 以外なら unk_198 を 0 にして fn = TextBox_StateRenderAll
  u8 unk_17f;              // 0x17F, 入力待ちのフラグらしい。キー状態の bit1 が入る
  s8 shownFace;            // 0x180, 顔スプライトに実際に反映済みの renderer.face, 食い違うと TextBox_RefreshFace が貼り直す
  u8 unk_181;              // 0x181, TextBox_Init が 0 を入れるだけ
  u8 autoAdvance;          // 0x182, TextBox_EnableAutoAdvance (TextBox_SetAutoAdvance) の第1引数
  s8 unk_183;              // 0x183, 3 で初期化され 0 になると unk_17f が 1 になるカウントダウン
  u16 autoAdvanceDelay;    // 0x184, TextBox_SetAutoAdvance の第2引数, autoAdvanceTimer がこれ以上になると次へ進む
  u16 autoAdvanceTimer;    // 0x186, 毎フレーム +1
  s32 waitFrames;          // 0x188, 次の行へ進む前に待つフレーム数。script keyword 'l' で初期化し、TextBox_Update が毎フレーム renderer.unk_18 で上書きする
  u32 waitTimer;           // 0x18C, waitFrames の経過フレーム数。TextBox_StateWaitInput が waitFrames に達するまで +1 し、達したら両方 0 に戻す
  u16 bgPlttFileID;        // 0x190, TextBox_LoadBgPltt が GetFile(BGPLTT, id) に渡した ID, script keyword 'c' (既定 0x519C)
  s16 pendingLine;         // 0x192, 次に表示する行。-1 なら何もしない。TextBox_Update がこれを TextBox_ShowLine に渡す
  u32 unk_194;             // 0x194, TextBox_SetAutoAdvance の第3引数 (script keyword 'm')
  u32 unk_198;             // 0x198, 表示が終わると 1 になり TextBox_IsFinished が返す
  u8 unk_19c[4];           // 0x19C
  u8* scriptPc;            // 0x1A0, FUN_0823d340 の戻り値、または TextBox_Start / TextBox_StartWithLabels の第1引数
  u16 labelIdx;            // 0x1A4, labels の添字, pendingLine = labels[labelIdx]
  u16 labelCount;          // 0x1A6, TextBox_StartWithLabels が 32 に丸める
  u16 labels[32];          // 0x1A8, TextBox_StartWithLabels が呼び出し側の配列をコピーする行番号表
  void* bgPltt;            // 0x1E8, TextBox_LoadBgPltt の GetFile(BGPLTT, bgPlttFileID), TextBox_UploadBgPltt が +500 から gBgPlttBuffer[0xF0] へ転送する
  MainSpriteGfx arrowGfx;  // 0x1EC, GetFile(SPRITE_SETS, SPRITE_MARKERS) を OpenSpriteSetFile したもの
  MainSprite arrow;        // 0x20C, 次ページ送りの矢印, TextBox_Update が pos を枠の右下に置き直す
  MainSpriteGfx faceGfx;   // 0x26C, GetFile(SPRITE_SETS, SPRITE_PORTRAITS)
  MainSprite face;         // 0x28C, 話者の顔, TextBox_RefreshFace が renderer.face のポーズを貼る
  TextBoxFunc fn;          // 0x2EC, TextBox_Update が毎フレーム呼ぶ状態関数
} TextBox;
static_assert(sizeof(TextBox) == 752);

IWRAM_DATA TextBox* gTextBox = NULL;  // 0x030000C4

NAKED void TextBox_ClearGlobal(void) { INCFUNC("asm/func/TextBox_ClearGlobal.inc"); }

NAKED bool32 TextBox_IsOpen(void) { INCFUNC("asm/func/TextBox_IsOpen.inc"); }

NAKED s32 TextBox_LoadBgPltt(TextBox* p, u16 fileID) { INCFUNC("asm/func/TextBox_LoadBgPltt.inc"); }

NAKED void TextBox_UploadBgPltt(TextBox* p) { INCFUNC("asm/func/TextBox_UploadBgPltt.inc"); }

NAKED s32 TextBox_RefreshFace(TextBox* p) { INCFUNC("asm/func/TextBox_RefreshFace.inc"); }

NAKED s32 TextBox_SetInstant(s32 instant) { INCFUNC("asm/func/TextBox_SetInstant.inc"); }

NAKED s32 TextBox_SetInstantScripted(void) { INCFUNC("asm/func/TextBox_SetInstantScripted.inc"); }

NAKED s32 TextBox_Close(void) { INCFUNC("asm/func/TextBox_Close.inc"); }

NAKED s32 TextBox_CloseScripted(void) { INCFUNC("asm/func/TextBox_CloseScripted.inc"); }

NAKED s32 TextBox_Start(u8* pc) { INCFUNC("asm/func/TextBox_Start.inc"); }

NAKED s32 TextBox_StartWithLabels(u8* pc, u16 labelCount, u16 labelIdx, u16* labels) { INCFUNC("asm/func/TextBox_StartWithLabels.inc"); }

NAKED s32 TextBox_Open(void) { INCFUNC("asm/func/TextBox_Open.inc"); }

NAKED s32 TextBox_ShowLine(s32 line) { INCFUNC("asm/func/TextBox_ShowLine.inc"); }

NAKED s32 TextBox_SetPendingLineScripted(void) { INCFUNC("asm/func/TextBox_SetPendingLineScripted.inc"); }

NAKED s32 TextBox_SetText(char* text) { INCFUNC("asm/func/TextBox_SetText.inc"); }

NAKED s32 TextBox_SetRect(s32 x, s32 y, s32 w, s32 h) { INCFUNC("asm/func/TextBox_SetRect.inc"); }

NAKED s32 TextBox_SetRectScripted(void) { INCFUNC("asm/func/TextBox_SetRectScripted.inc"); }

NAKED s32 TextBox_SetVarValue(s32 idx, s32 value) { INCFUNC("asm/func/TextBox_SetVarValue.inc"); }

NAKED s32 TextBox_SetVar(void) { INCFUNC("asm/func/TextBox_SetVar.inc"); }

NAKED s32 TextBox_SetExtendValue(s32 idx, char* text) { INCFUNC("asm/func/TextBox_SetExtendValue.inc"); }

NAKED s32 TextBox_SetExtendStringScripted(void) { INCFUNC("asm/func/TextBox_SetExtendStringScripted.inc"); }

NAKED s32 TextBox_SetExtend(void) { INCFUNC("asm/func/TextBox_SetExtend.inc"); }

NAKED s32 TextBox_SetScriptIdsScripted(void) { INCFUNC("asm/func/TextBox_SetScriptIdsScripted.inc"); }

NAKED s32 TextBox_SetAutoAdvance(s32 enable, u16 delay, u32 unk_194) { INCFUNC("asm/func/TextBox_SetAutoAdvance.inc"); }

NAKED s32 TextBox_EnableAutoAdvance(void) { INCFUNC("asm/func/TextBox_EnableAutoAdvance.inc"); }

NAKED s32 TextBox_SetBgPltt(u16 fileID) { INCFUNC("asm/func/TextBox_SetBgPltt.inc"); }

NAKED s32 TextBox_SetBgPlttScripted(void) { INCFUNC("asm/func/TextBox_SetBgPlttScripted.inc"); }

NAKED s32 TextBox_ConfigureScripted(void) { INCFUNC("asm/func/TextBox_ConfigureScripted.inc"); }

NAKED s32 TextBox_SetWait(s32 frames) { INCFUNC("asm/func/TextBox_SetWait.inc"); }

NAKED s32 TextBox_SetWaitScripted(void) { INCFUNC("asm/func/TextBox_SetWaitScripted.inc"); }

NAKED s32 FUN_08047fbc(void) { INCFUNC("asm/func/FUN_08047fbc.inc"); }

NAKED char* TextBox_GetLine(TextBox* p, s32 lineIdx) { INCFUNC("asm/func/TextBox_GetLine.inc"); }

NAKED void TextBox_StateWaitInput(TextBox* p) { INCFUNC("asm/func/TextBox_StateWaitInput.inc"); }

NAKED void TextBox_StateFastForward(TextBox* p) { INCFUNC("asm/func/TextBox_StateFastForward.inc"); }

NAKED void TextBox_StateType(TextBox* p) { INCFUNC("asm/func/TextBox_StateType.inc"); }

NAKED void TextBox_StateIdle(TextBox* p) { INCFUNC("asm/func/TextBox_StateIdle.inc"); }

NAKED void TextBox_StateDone(TextBox* p) { INCFUNC("asm/func/TextBox_StateDone.inc"); }

NAKED void TextBox_StateRenderAll(TextBox* p) { INCFUNC("asm/func/TextBox_StateRenderAll.inc"); }

NAKED s32 TextBox_Update(TextBox* p) { INCFUNC("asm/func/TextBox_Update.inc"); }

NAKED s32 TextBox_Destroy(TextBox* p) { INCFUNC("asm/func/TextBox_Destroy.inc"); }

NAKED s32 TextBox_Init(TextBox* p, u32 _) { INCFUNC("asm/func/TextBox_Init.inc"); }

NAKED TextBox* TextBox_Create(u32 _) { INCFUNC("asm/func/TextBox_Create.inc"); }

NAKED s32 TextBox_GetRect(s32* rect) { INCFUNC("asm/func/TextBox_GetRect.inc"); }

NAKED s32 TextBox_GetVarWidth(s32 idx) { INCFUNC("asm/func/TextBox_GetVarWidth.inc"); }

NAKED s32 TextBox_GetExtendWidth(s32 idx) { INCFUNC("asm/func/TextBox_GetExtendWidth.inc"); }

NAKED s32 FUN_080488dc(void) { INCFUNC("asm/func/FUN_080488dc.inc"); }

NAKED s32 FUN_080488fc(void) { INCFUNC("asm/func/FUN_080488fc.inc"); }

NAKED bool32 TextBox_IsFinished(void) { INCFUNC("asm/func/TextBox_IsFinished.inc"); }
