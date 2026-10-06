#include "bg_pltt.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "text.h"
#include "video.h"
#include "vm.h"

typedef u16 TextSlideshowFlags;              // TextSlideshow.flags
#define TEXTSLIDESHOW_TAKE_OVER_BG (1 << 0)  // gStagedDISPCNT を退避して BG0 だけにする
#define TEXTSLIDESHOW_KILL_AT_END (1 << 1)   // 最終行のあと KillEntity

// '.s' で渡したテキストを '.t' の行テーブルに沿って1行ずつ フェードイン -> 表示 -> フェードアウト で流す
// ゲームのスタッフロール, プロローグ/エピローグのポエム に使う
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_8
  u8 step;                   // 0x018, sTextSlideshowUpdates の添字, 0: フェードイン, 1: 表示待ち, 2: フェードアウト, 3: スキップ, 4: 終了
  bool8 stepChanged;         // 0x019, TextSlideshow_SetStep が立て TextSlideshow_TakeStepChanged が読んで落とす, step に入った最初の1フレームの目印
  u8 curLine;                // 0x01A, 表示中の行, '.p=0' が開始行
  u8 lastLine;               // 0x01B, 最終行, holdTime が -1 になったところの1つ前
  u32 unk_1c;                // 0x01C, TextSlideshow_Start が 0 を書くだけ
  u32 timer;                 // 0x020, step に入ってからのフレーム数, TextSlideshow_Update が毎フレーム +1
  TextSlideshowFlags flags;  // 0x024, '.f=0', bit0: gStagedDISPCNT を退避して BG0 だけにする, bit1: 最終行のあと KillEntity
  u16 savedDispcnt;          // 0x026, flags bit0 のとき _Init が gStagedDISPCNT を退避し _Destroy が戻す
  u8* scriptS;               // 0x028, '.s' の後の FUN_0823d340(), TextBox_Start に渡す本文
  u8* scriptT;               // 0x02C, '.t' の後の FUN_0823d34c(), 下の7本の配列の読み出し元
  u16 exitScriptID;          // 0x030, '.e', 最終行のあと VM_ExecByID
  u16 skipScriptID;          // 0x032, '.c', 0 でなければ Start/A でスキップでき、そのとき VM_ExecByID
  s16 holdTime[64];          // 0x034, '.t[0]', 表示したまま待つフレーム数, -1 で行テーブルの終端
  u16 fadeInTime[64];        // 0x0B4, '.t[5]', 明るさを 0 から 64 まで上げるフレーム数
  u16 fadeOutTime[64];       // 0x134, '.t[6]', 明るさを 64 から 0 まで下げるフレーム数
  u16 x[64];                 // 0x1B4, '.t[1]', TextBox_SetRect の第1引数
  u16 y[64];                 // 0x234, '.t[2]', 同第2引数
  u16 w[64];                 // 0x2B4, '.t[3]', 同第3引数
  u16 h[64];                 // 0x334, '.t[4]', 同第4引数
} TextSlideshow;
static_assert(sizeof(TextSlideshow) == 948);

extern u16 gBgPlttFadeRowMask;

IWRAM_DATA TextSlideshow* gTextSlideshow = NULL;  // 0x030000D0

void TextSlideshow_ClearPtr(void) { gTextSlideshow = NULL; }

void TextSlideshow_ApplyLineRect(TextSlideshow* p) { TextBox_SetRect(p->x[p->curLine], p->y[p->curLine], p->w[p->curLine], p->h[p->curLine]); }

void TextSlideshow_SetStep(TextSlideshow* p, u8 step) {
  p->step = step;
  p->stepChanged = TRUE;
  p->timer = 0;
}

// step に入った最初の1フレームかどうかを返し、目印を落とす
bool8 TextSlideshow_TakeStepChanged(TextSlideshow* p) {
  if (p->stepChanged) {
    p->stepChanged = FALSE;
    return TRUE;
  }

  return FALSE;
}

// その行を描き直してから fadeInTime フレームかけて明るくし, 明るさが上限に届いたら表示待ちへ
void TextSlideshow_StepFadeIn(TextSlideshow* p) {
  if (TextSlideshow_TakeStepChanged(p)) {
    ClearBGTilemapBuffer(0);
    TextSlideshow_ApplyLineRect(p);
    TextBox_ShowLine(p->curLine);
  }

  if (p->timer >= p->fadeInTime[p->curLine]) {
    gBgBrightness = 64;
    TextSlideshow_SetStep(p, 1);
  } else {
    gBgBrightness = Div(p->timer * 64, p->fadeInTime[p->curLine]);
  }
}

// 1行を表示したまま holdTime フレームだけ待ち, 経過したらフェードアウトへ
void TextSlideshow_StepHold(TextSlideshow* p) {
  if (TextSlideshow_TakeStepChanged(p)) {
    gBgBrightness = 64;
  }

  if (p->timer >= p->holdTime[p->curLine]) {
    TextSlideshow_SetStep(p, 2);
  }
}

// fadeOutTime フレームかけて暗くし, 暗転したら次の行へ, 最終行なら '.e' のスクリプトを呼んで終わる
void TextSlideshow_StepFadeOut(TextSlideshow* p) {
  TextSlideshow_TakeStepChanged(p);
  if (p->timer >= p->fadeOutTime[p->curLine]) {
    gBgBrightness = 0;
    if (p->curLine == p->lastLine) {
      TextBox_Close();
      TextSlideshow_SetStep(p, 4);
      if (p->exitScriptID != 0) {
        VM_ExecByID(p->exitScriptID, NULL);
      }

      if (p->flags & TEXTSLIDESHOW_KILL_AT_END) {
        KillEntity((Entity*)p);
      }
    } else {
      p->curLine++;
      TextSlideshow_SetStep(p, 0);
    }
  } else {
    gBgBrightness = 64 - Div(p->timer * 64, p->fadeOutTime[p->curLine]);
  }
}

// 16フレームかけて暗転し, 終わったら '.c' のスクリプトを呼んで自分を消す
void TextSlideshow_StepSkip(TextSlideshow* p) {
  TextSlideshow_TakeStepChanged(p);
  if (p->skipScriptID != 0) {
    if (p->timer >= 16) {
      gBgBrightness = 0;
      VM_ExecByID(p->skipScriptID, NULL);
      p->skipScriptID = 0;
      KillEntity((Entity*)p);
    } else {
      gBgBrightness = 64 - Div(p->timer * 64, 16);
    }
  }
}

// 今の step の処理を1フレーム進め, スキップ先が指定されていれば Start/A でスキップ段へ飛ばす
s32 TextSlideshow_Update(TextSlideshow* p) {
  // clang-format off
  static void (*const sTextSlideshowUpdates[5])(TextSlideshow*) = {
      TextSlideshow_StepFadeIn,
      TextSlideshow_StepHold,
      TextSlideshow_StepFadeOut,
      TextSlideshow_StepSkip,
      NULL,
  };  // 0x085AB550
  // clang-format on

  void (*update)(TextSlideshow*) = sTextSlideshowUpdates[p->step];
  if (update != NULL) {
    update(p);
  }

  gBgPlttBuffer[0] = RGB(4, 4, 4);  // 背景色を暗い灰色で固定する
  if ((gInput[0].pressed & (A_BUTTON | START_BUTTON)) && p->skipScriptID != 0 && p->step < 3) {
    TextSlideshow_SetStep(p, 3);
  }

  p->timer++;
  return 0;
}

s32 TextSlideshow_Destroy(TextSlideshow* p) {
  gTextSlideshow = NULL;
  TextBox_Close();

  if (p->flags & TEXTSLIDESHOW_TAKE_OVER_BG) {
    gStagedDISPCNT = p->savedDispcnt;
  }

  return 0;
}

// スクリプトの引数から本文と行テーブルを読み直し, '.p' の行のフェードインから流し始める
s32 TextSlideshow_Start(TextSlideshow* p) {
  p->step = 0;
  p->stepChanged = FALSE;
  p->timer = 0;
  p->curLine = VM_GetNamedArgValue('p', 0);
  p->unk_1c = 0;

  if (!VM_SeekToNamedArg('s')) return -1;
  p->scriptS = FUN_0823d340();
  if (p->scriptS == NULL) return -1;

  if (VM_SeekToNamedArg('t')) {
    s32 i;

    p->scriptT = FUN_0823d34c();
    VM_SetPC(p->scriptT);
    for (i = 0; i < 64; i++) {
      p->holdTime[i] = VM_GetValue();
      p->x[i] = VM_GetValue();
      p->y[i] = VM_GetValue();
      p->w[i] = VM_GetValue();
      p->h[i] = VM_GetValue();
      p->fadeInTime[i] = VM_GetValue();
      p->fadeOutTime[i] = VM_GetValue();
      if (i >= p->curLine && p->holdTime[i] == -1) {
        p->lastLine = i - 1;
        break;
      }
    }
  }

  p->exitScriptID = VM_GetNamedArgValue('e', 0);
  p->skipScriptID = VM_GetNamedArgValue('c', 0);
  TextBox_Start(p->scriptS);
  TextBox_SetInstant(TRUE);
  TextBox_SetBgPltt(BGP_539C);
  TextBox_ShowLine(p->curLine);
  TextSlideshow_ApplyLineRect(p);
  gBgPlttBlendColor = RGB(4, 4, 4);
  gBgPlttFadeRowMask = 0x8000;
  gBgBrightness = 0;
  TextSlideshow_SetStep(p, 0);
  return 0;
}

// BG1-BG3 を消して BG0 だけ表示する
NON_MATCH s32 TextSlideshow_Init(TextSlideshow* p) {
#ifdef NONMATCHING_C
  gTextSlideshow = p;
  p->flags = VM_GetNamedArgValue('f', 0);
  if (p->flags & TEXTSLIDESHOW_TAKE_OVER_BG) {
    p->savedDispcnt = gStagedDISPCNT;
    gStagedDISPCNT = (gStagedDISPCNT & ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON)) | DISPCNT_BG0_ON;
  }

  return TextSlideshow_Start(p);
#else
  INCFUNC("asm/func/TextSlideshow_Init.inc");
#endif
}

// 0x3DF7
TextSlideshow* TextSlideshow_Create(void) {
  TextSlideshow* p;

  if (gTextSlideshow != NULL) {
    TextSlideshow_Start(gTextSlideshow);
    return gTextSlideshow;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(TextSlideshow));
  if (p != NULL) {
    SetEntityRoutine(p, TextSlideshow_Update, TextSlideshow_Destroy);
    if (TextSlideshow_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
