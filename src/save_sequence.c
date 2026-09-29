#include "entity.h"
#include "global.h"
#include "input.h"
#include "save.h"
#include "sound.h"
#include "text.h"
#include "vm.h"

// スクリプト命令 0xB0BC が作るセーブ処理, メッセージを出して 60 フレーム目に Save_WriteToNextSlot を実行し、
// 結果のメッセージに差し替えたあと、結果を引数にしてスクリプトを起動して自滅する
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_11
  s32 windowID;  // 0x18, TextPanel_Create(1, 13, 28, 6) の戻り値, 失敗時は -1, _Destroy が TextPanel_Destroy に渡す
  s32 scriptID;  // 0x1C, '.e=0', result を唯一の引数にして VM_ExecByID へ渡したあと 0 に戻す
  s32 timer;     // 0x20, 毎フレーム +1, 60 でセーブ実行、120 以降は A で進める、300 で打ち切る
  s32 result;    // 0x24, セーブ実行までは -1, Save_WriteToNextSlot の戻り値で、1 ならメッセージ 0xE、それ以外は 0xF
  u8* msgPc;     // 0x28, _Init 時点の VM_GetPC(), TextPanel_SetScript(windowID, msgPc) に渡す
} SaveSequence;
static_assert(sizeof(SaveSequence) == 44);

s32 FUN_0809c08c(s32 mode);

// 60フレーム目にセーブを実行して結果メッセージに差し替え、A 押下か 300 フレームで結果をスクリプトに渡して自滅する
s32 SaveSequence_Update(SaveSequence* p) {
  u32 arg;
  ScriptArgs sa;

  // timer の書き間違いと思われる, result は -1 か 0/1 しか取らないので常に真, 下の timer > 119 と同じ値なのが根拠
  if (p->result <= 119) {
    gSoftResetInhibit = TRUE;
  }
  if (p->result < 0 && p->timer == 60) {
    p->result = Save_WriteToNextSlot();
    if (p->result == 1) {
      TextPanel_SetMessage(p->windowID, 14);
      PlaySound_082406e0(0x2AE);
    } else {
      TextPanel_SetMessage(p->windowID, 15);
      PlaySound_082406e0(0x192);
    }
  }
  if ((p->result >= 0 && p->timer > 119 && (gInput[0].pressed & A_BUTTON)) || p->timer > 299) {
    FUN_0809c08c(7);
    if (p->scriptID != 0) {
      arg = p->result;
      sa.argc = 1, sa.argv = &arg;
      VM_ExecByID(p->scriptID, &sa);
      p->scriptID = 0;
    }
    KillEntity((Entity*)p);
  }
  p->timer++;
  return 0;
}

s32 SaveSequence_Destroy(SaveSequence* p) {
  TextPanel_Destroy(p->windowID);
  return 0;
}

s32 SaveSequence_Init(SaveSequence* p) {
  s32 err;

  FUN_0809c08c(3);
  p->scriptID = VM_GetKeywordValue('e', 0);
  p->timer = 0;
  p->result = err = -1;
  if (VM_SeekToKeyword('s')) {
    p->msgPc = FUN_0823d340();
    if (p->msgPc != NULL) {
      p->windowID = TextPanel_Create(1, 13, 28, 6);
      if (p->windowID >= 0) {
        TextPanel_SetScript(p->windowID, p->msgPc);
        TextPanel_SetMessage(p->windowID, 11);
        TextPanel_Start(p->windowID);
        return 0;
      }
    }
  }
  return err;
}

SaveSequence* SaveSequence_Create(void) {
  SaveSequence* p = CreateEntity(ENTITY_UNK_11, sizeof(SaveSequence));

  if (p != NULL) {
    SetEntityRoutine(p, SaveSequence_Update, SaveSequence_Destroy);
    if (SaveSequence_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
