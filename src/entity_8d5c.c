#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "video.h"
#include "vm.h"

// 不使用?
// 上下キーで選ぶ縦並びのメニュー, 項目は '.s' から値の対として読む
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_4
  u8* listPC;       // 0x18, '.s' の読み出し位置, 選択を動かすたびにここへ戻して読み直す
  s32 curValue;     // 0x1C, 選択中の項目の1つめの値
  s32 curScriptID;  // 0x20, 選択中の項目の2つめの値, A ボタンを離すと実行して自分を消す
  s32 index;        // 0x24, 選択中の添字, 終端に当たるとそこで止まる
  s32 repeatTimer;  // 0x28, キーを押し続けたときの待ちフレーム, 押し始めは 0x14 で以降は 4
  s32 lastDir;      // 0x2C, 前のフレームに押していた方向 (-1 上 / 1 下 / 0 なし)
} Entity8D5C;
static_assert(sizeof(Entity8D5C) == 48);

bool32 FUN_0823d4c8(void);

// 選択を delta だけ動かして, 選択中の項目の2つの値を読み直す
void Entity8D5C_MoveSelection(Entity8D5C* p, s32 delta) {
  s32 value = 0;
  s32 scriptID = 0;
  s32 i;

  p->index += delta;
  if (p->index < 0) {
    p->index = 0;
  }

  VM_SetPC(p->listPC);
  for (i = 0; i <= p->index; i++) {
    if (VM_GetPC() == NULL) {
      p->index = i;
      break;
    }
    value = (s32)VM_GetValueAtSafe(VM_GetPC());
    scriptID = VM_GetValueAt(VM_GetPC());
  }

  p->curValue = value;
  p->curScriptID = scriptID;
}

// 上下キーで選択を動かし (押し続けると繰り返す), B で末尾へ飛び, A を離すと選択中のスクリプトを実行して自分を消す
s32 Entity8D5C_Update(Entity8D5C* p) {
  Input* input = &gInput[0];

  u16 keys = input->down;

  if (keys & (DPAD_UP | DPAD_DOWN)) {
    s32 dir = (keys & DPAD_UP) ? -1 : 1;

    if (p->lastDir == dir) {
      if (--p->repeatTimer < 0) {
        Entity8D5C_MoveSelection(p, dir);
        p->repeatTimer = 4;
      }
    } else {
      Entity8D5C_MoveSelection(p, dir);
      p->repeatTimer = 20;
      p->lastDir = dir;
    }
  } else {
    p->lastDir = 0;
  }

  if (input->pressed & B_BUTTON) {
    s32 prev;

    do {
      prev = p->index;
      Entity8D5C_MoveSelection(p, 1);
    } while (prev != p->index);
  }
  if (input->released & A_BUTTON) {
    VM_ExecByID(p->curScriptID, NULL);
    KillEntity((Entity*)p);
  }
  FUN_0823d4c8();
  return 0;
}

s32 Entity8D5C_Init(Entity8D5C* p) {
  if (!VM_SeekToNamedArg('s')) {
    return -1;
  }

  p->listPC = VM_GetPC();
  p->index = 0;
  p->lastDir = 0;
  Entity8D5C_MoveSelection(p, 0);
  CpuCopy32(&GetBgPlttFile(BGP_519C)->body[240], &gBgPlttBuffer[240], 16 * sizeof(rgb555));
  return 0;
}

// 0x8D5C
Entity8D5C* Entity8D5C_Create(void) {
  Entity8D5C* p = CreateEntity(ENTITY_UNK_4, sizeof(Entity8D5C));

  if (p != NULL) {
    SetEntityRoutine(p, Entity8D5C_Update, NULL);
    if (Entity8D5C_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
