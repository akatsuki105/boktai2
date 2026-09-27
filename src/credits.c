#include "entity.h"
#include "global.h"
#include "text.h"
#include "video.h"

// '.s' で渡したテキストを '.t' の行テーブルに沿って1行ずつ フェードイン -> 表示 -> フェードアウト で流す
// ゲームのスタッフロール, プロローグ/エピローグのポエム に使う, スタッフロールがメインなので Credits という名前にしている
typedef u16 CreditsFlags;              // Credits.flags
#define CREDITS_TAKE_OVER_BG (1 << 0)  // gStagedDISPCNT を退避して BG0 だけにする
#define CREDITS_KILL_AT_END (1 << 1)   // 最終行のあと KillEntity

typedef struct {
  Entity e;             // 0x000, ENTITY_UNK_8
  u8 step;              // 0x018, PTR_ARRAY_085AB550 の添字, 0: フェードイン, 1: 表示待ち, 2: フェードアウト, 3: スキップ, 4: 終了
  bool8 stepChanged;    // 0x019, Credits_SetStep が立て Credits_TakeStepChanged が読んで落とす, step に入った最初の1フレームの目印
  u8 curLine;           // 0x01A, 表示中の行, '.p=0' が開始行
  u8 lastLine;          // 0x01B, 最終行, holdTime が -1 になったところの1つ前
  u32 unk_1c;           // 0x01C, Credits_Start が 0 を書くだけ
  u32 timer;            // 0x020, step に入ってからのフレーム数, Credits_Update が毎フレーム +1
  CreditsFlags flags;   // 0x024, '.f=0', bit0: gStagedDISPCNT を退避して BG0 だけにする, bit1: 最終行のあと KillEntity
  u16 savedDispcnt;     // 0x026, flags bit0 のとき _Init が gStagedDISPCNT を退避し _Destroy が戻す
  u8* scriptS;          // 0x028, '.s' の後の FUN_0823d340(), TextBox_Start に渡す本文
  u8* scriptT;          // 0x02C, '.t' の後の FUN_0823d34c(), 下の7本の配列の読み出し元
  u16 exitScriptID;     // 0x030, '.e', 最終行のあと VM_ExecByID
  u16 skipScriptID;     // 0x032, '.c', 0 でなければ Start/A でスキップでき、そのとき VM_ExecByID
  s16 holdTime[64];     // 0x034, '.t[0]', 表示したまま待つフレーム数, -1 で行テーブルの終端
  u16 fadeInTime[64];   // 0x0B4, '.t[5]', 明るさを 0 から 64 まで上げるフレーム数
  u16 fadeOutTime[64];  // 0x134, '.t[6]', 明るさを 64 から 0 まで下げるフレーム数
  u16 x[64];            // 0x1B4, '.t[1]', TextBox_SetRect の第1引数
  u16 y[64];            // 0x234, '.t[2]', 同第2引数
  u16 w[64];            // 0x2B4, '.t[3]', 同第3引数
  u16 h[64];            // 0x334, '.t[4]', 同第4引数
} Credits;
static_assert(sizeof(Credits) == 948);

IWRAM_DATA Credits* gCredits = NULL;  // 0x030000D0

void Credits_ClearPtr(void) { gCredits = NULL; }

NAKED void Credits_ApplyLineRect(Credits* p) { INCFUNC("asm/func/Credits_ApplyLineRect.inc"); }

void Credits_SetStep(Credits* p, u8 step) {
  p->step = step;
  p->stepChanged = TRUE;
  p->timer = 0;
}

// step に入った最初の1フレームかどうかを返し、目印を落とす
bool32 Credits_TakeStepChanged(Credits* p) {
  if (p->stepChanged) {
    p->stepChanged = FALSE;
    return TRUE;
  }

  return FALSE;
}

NAKED void Credits_StepFadeIn(Credits* p) { INCFUNC("asm/func/Credits_StepFadeIn.inc"); }

NAKED void Credits_StepHold(Credits* p) { INCFUNC("asm/func/Credits_StepHold.inc"); }

NAKED void Credits_StepFadeOut(Credits* p) { INCFUNC("asm/func/Credits_StepFadeOut.inc"); }

NAKED void Credits_StepSkip(Credits* p) { INCFUNC("asm/func/Credits_StepSkip.inc"); }

NAKED s32 Credits_Update(Credits* p) { INCFUNC("asm/func/Credits_Update.inc"); }

s32 Credits_Destroy(Credits* p) {
  gCredits = NULL;
  TextBox_Close();

  if (p->flags & CREDITS_TAKE_OVER_BG) {
    gStagedDISPCNT = p->savedDispcnt;
  }

  return 0;
}

NAKED s32 Credits_Start(Credits* p) { INCFUNC("asm/func/Credits_Start.inc"); }

NAKED s32 Credits_Init(Credits* p) { INCFUNC("asm/func/Credits_Init.inc"); }

NAKED Credits* Credits_Create(void) { INCFUNC("asm/func/Credits_Create.inc"); }
