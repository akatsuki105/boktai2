#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

struct TextBox;
typedef void (*TextBoxFunc)(struct TextBox* p);

// 文字送り・顔グラ・送り矢印・オートモードを持つ, TextPanel と区別しやすい名前にしたい
typedef struct TextBox {
  Entity e;                // 0x000, ENTITY_UNK_12
  TextRenderer renderer;   // 0x018
  u8 rectX;                // 0x178, '.r' の1番目, TextRenderer_SetRect と FUN_0822ea60 に渡す
  u8 rectY;                // 0x179, '.r' の2番目
  u8 rectW;                // 0x17A, '.r' の3番目
  u8 rectH;                // 0x17B, '.r' の4番目
  s16 lineIdx;             // 0x17C, '.i', TextBox_GetLine(p, lineIdx) が行頭ポインタを返す。次の行へ進むとき +1
  bool8 unk_17e;           // 0x17E, 0 なら fn = TextBox_StateType (1文字ずつ表示), 0 以外なら unk_198 を 0 にして fn = TextBox_StateRenderAll
  u8 unk_17f;              // 0x17F, 入力待ちのフラグらしい。キー状態の bit1 が入る
  s8 shownFace;            // 0x180, 顔スプライトに実際に反映済みの renderer.face, 食い違うと TextBox_RefreshFace が貼り直す
  u8 unk_181;              // 0x181, TextBox_Init が 0 を入れるだけ
  u8 autoAdvance;          // 0x182, TextBox_EnableAutoAdvance (TextBox_SetAutoAdvance) の第1引数
  s8 unk_183;              // 0x183, 3 で初期化され 0 になると unk_17f が 1 になるカウントダウン
  u16 autoAdvanceDelay;    // 0x184, TextBox_SetAutoAdvance の第2引数, autoAdvanceTimer がこれ以上になると次へ進む
  u16 autoAdvanceTimer;    // 0x186, 毎フレーム +1
  s32 waitFrames;          // 0x188, 次の行へ進む前に待つフレーム数, '.l' で初期化し、TextBox_Update が毎フレーム renderer.unk_18 で上書きする
  u32 waitTimer;           // 0x18C, waitFrames の経過フレーム数。TextBox_StateWaitInput が waitFrames に達するまで +1 し、達したら両方 0 に戻す
  FileID bgPlttFileID;     // 0x190, '.c=0x519C', TextBox_LoadBgPltt が GetFile(BGPLTT, id) に渡した ID
  s16 pendingLine;         // 0x192, 次に表示する行。-1 なら何もしない。TextBox_Update がこれを TextBox_ShowLine に渡す
  u32 unk_194;             // 0x194, '.m', TextBox_SetAutoAdvance の第3引数
  u32 unk_198;             // 0x198, 表示が終わると 1 になり TextBox_IsFinished が返す
  u8 unk_19c[4];           // 0x19C
  u8* scriptPc;            // 0x1A0, FUN_0823d340 の戻り値、または TextBox_Start / TextBox_StartWithLabels の第1引数
  u16 labelIdx;            // 0x1A4, labels の添字, pendingLine = labels[labelIdx]
  u16 labelCount;          // 0x1A6, TextBox_StartWithLabels が 32 に丸める
  u16 labels[32];          // 0x1A8, TextBox_StartWithLabels が呼び出し側の配列をコピーする行番号表
  void* bgPltt;            // 0x1E8, TextBox_LoadBgPltt の GetFile(BGPLTT, bgPlttFileID), TextBox_UploadBgPltt が +500 から gBgPlttBuffer[0xF0] へ転送する
  MainSpriteGfx arrowGfx;  // 0x1EC, SPRITE_MARKERS
  MainSprite arrow;        // 0x20C, 次ページ送りの矢印, TextBox_Update が pos を枠の右下に置き直す
  MainSpriteGfx faceGfx;   // 0x26C, SPRITE_PORTRAITS
  MainSprite face;         // 0x28C, 話者の顔, TextBox_RefreshFace が renderer.face のポーズを貼る
  TextBoxFunc fn;          // 0x2EC, TextBox_Update が毎フレーム呼ぶ状態関数
} TextBox;
static_assert(sizeof(TextBox) == 752);

IWRAM_DATA TextBox* gTextBox = NULL;  // 0x030000C4

void TextBox_ClearGlobal(void) { gTextBox = NULL; }

bool32 TextBox_IsOpen(void) { return gTextBox != NULL; }

NAKED s32 TextBox_LoadBgPltt(TextBox* p, u16 fileID) { INCFUNC("asm/func/TextBox_LoadBgPltt.inc"); }

// パレットファイルの 500 バイト目から 16色を BG パレットの最終ブロックへ送る
void TextBox_UploadBgPltt(TextBox* p) { CpuCopy32((u8*)p->bgPltt + 500, &gBgPlttBuffer[240], 16 * sizeof(rgb555)); }

NAKED s32 TextBox_RefreshFace(TextBox* p) { INCFUNC("asm/func/TextBox_RefreshFace.inc"); }

NAKED s32 TextBox_SetInstant(s32 instant) { INCFUNC("asm/func/TextBox_SetInstant.inc"); }

s32 TextBox_SetInstantScripted(void) { return TextBox_SetInstant(Script_GetValue()); }

NAKED s32 TextBox_Close(void) { INCFUNC("asm/func/TextBox_Close.inc"); }

s32 TextBox_CloseScripted(void) { return TextBox_Close(); }

NAKED s32 TextBox_Start(u8* pc) { INCFUNC("asm/func/TextBox_Start.inc"); }

NAKED s32 TextBox_StartWithLabels(u8* pc, u16 labelCount, u16 labelIdx, u16* labels) { INCFUNC("asm/func/TextBox_StartWithLabels.inc"); }

// スクリプトの 'r' があればそこを、なければ現在位置を本文の先頭にする
s32 TextBox_Open(void) { return TextBox_Start(!VM_SeekToKeyword('r') ? VM_GetPC() : FUN_0823d340()); }

NAKED s32 TextBox_ShowLine(s32 line) { INCFUNC("asm/func/TextBox_ShowLine.inc"); }

NAKED s32 TextBox_SetPendingLineScripted(void) { INCFUNC("asm/func/TextBox_SetPendingLineScripted.inc"); }

NAKED s32 TextBox_SetText(char* text) { INCFUNC("asm/func/TextBox_SetText.inc"); }

NAKED s32 TextBox_SetRect(s32 x, s32 y, s32 w, s32 h) { INCFUNC("asm/func/TextBox_SetRect.inc"); }

s32 TextBox_SetRectScripted(void) {
  s32 x = Script_GetValue();
  s32 y = Script_GetValue();
  s32 w = Script_GetValue();

  return TextBox_SetRect(x, y, w, Script_GetValue());
}

NAKED s32 TextBox_SetVarValue(s32 idx, s32 value) { INCFUNC("asm/func/TextBox_SetVarValue.inc"); }

s32 TextBox_SetVar(void) {
  s32 idx = Script_GetValue();
  return TextBox_SetVarValue(idx, Script_GetValue());
}

s32 TextBox_SetExtendValue(s32 idx, char* text) {
  TextBox* p = gTextBox;

  if (p != NULL) {
    return TextRenderer_SetExtend(&p->renderer, idx, (u32)text);
  }
  return 0;
}

NAKED s32 TextBox_SetExtendStringScripted(void) { INCFUNC("asm/func/TextBox_SetExtendStringScripted.inc"); }

s32 TextBox_SetExtend(void) {
  s32 idx = Script_GetValue();
  return TextBox_SetExtendValue(idx, FUN_0823d34c());
}

NAKED s32 TextBox_SetScriptIdsScripted(void) { INCFUNC("asm/func/TextBox_SetScriptIdsScripted.inc"); }

NAKED s32 TextBox_SetAutoAdvance(s32 enable, u16 delay, u32 unk_194) { INCFUNC("asm/func/TextBox_SetAutoAdvance.inc"); }

NAKED s32 TextBox_EnableAutoAdvance(void) { INCFUNC("asm/func/TextBox_EnableAutoAdvance.inc"); }

NAKED s32 TextBox_SetBgPltt(s32 fileID) { INCFUNC("asm/func/TextBox_SetBgPltt.inc"); }

s32 TextBox_SetBgPlttScripted(void) { return TextBox_SetBgPltt(Script_GetValue()); }

NAKED s32 TextBox_ConfigureScripted(void) { INCFUNC("asm/func/TextBox_ConfigureScripted.inc"); }

NAKED s32 TextBox_SetWait(s32 frames) { INCFUNC("asm/func/TextBox_SetWait.inc"); }

s32 TextBox_SetWaitScripted(void) { return TextBox_SetWait(Script_GetValue()); }

s32 FUN_08047fbc(void) {
  if (gTextBox == NULL) {
    return -1;
  }
  return 0;
}

// スクリプトの文字列表の lineIdx 行目を引く
char* TextBox_GetLine(TextBox* p, s32 lineIdx) { return Textbox_LookupString(VM_ParseStringRef(p->scriptPc) + lineIdx); }

NAKED void TextBox_StateWaitInput(TextBox* p) { INCFUNC("asm/func/TextBox_StateWaitInput.inc"); }

NAKED void TextBox_StateFastForward(TextBox* p) { INCFUNC("asm/func/TextBox_StateFastForward.inc"); }

NAKED void TextBox_StateType(TextBox* p) { INCFUNC("asm/func/TextBox_StateType.inc"); }

void TextBox_StateIdle(TextBox* p) { TextRenderer_SetFinished(&p->renderer, FALSE); }

void TextBox_StateDone(TextBox* p) {}

NAKED void TextBox_StateRenderAll(TextBox* p) { INCFUNC("asm/func/TextBox_StateRenderAll.inc"); }

NAKED s32 TextBox_Update(TextBox* p) { INCFUNC("asm/func/TextBox_Update.inc"); }

NAKED s32 TextBox_Destroy(TextBox* p) { INCFUNC("asm/func/TextBox_Destroy.inc"); }

NAKED s32 TextBox_Init(TextBox* p, u32 _) { INCFUNC("asm/func/TextBox_Init.inc"); }

NAKED TextBox* TextBox_Create(u32 _) { INCFUNC("asm/func/TextBox_Create.inc"); }

NAKED s32 TextBox_GetRect(s32* rect) { INCFUNC("asm/func/TextBox_GetRect.inc"); }

s32 TextBox_GetVarWidth(s32 idx) {
  TextBox* p = gTextBox;

  if (p == NULL) {
    return 0;
  }
  return TextRenderer_GetVarWidth(&p->renderer, idx);
}

s32 TextBox_GetExtendWidth(s32 idx) {
  TextBox* p = gTextBox;

  if (p == NULL) {
    return 0;
  }
  return TextRenderer_GetExtendWidth(&p->renderer, idx);
}

s32 FUN_080488dc(void) {
  TextBox* p = gTextBox;

  if (p == NULL) {
    return 0;
  }
  return FUN_08048c58(&p->renderer);
}

s32 FUN_080488fc(void) { return gStat->unk_938; }

bool32 TextBox_IsFinished(void) {
  TextBox* p = gTextBox;

  if (p == NULL) {
    return FALSE;
  }
  return p->unk_198;
}
