#include "msgbus.h"

#include "entity.h"
#include "global.h"
#include "vm.h"

// メッセージバス兼デモ再生機, シングルトン (gEntityMsgBus) で、これがいないとメッセージ機構そのものが動かない
// 受け口: 全エンティティの EntityMsgBox を boxes のリストで持ち、登録・解除・ダブルバッファの面切り替えを一手に引き受ける
// 再生: デモスクリプト (PTR_ARRAY_08dbd564) を demoID/step で読み進め、各 EntityMsg を宛先の受け口へ配る
// 自身も targetClass 1 の宛先で、cmd 0=スクリプト実行 / 1=ウェイト / 2=外部待ち を Demo_HandleMsgs で処理する
typedef struct {
  Entity e;             // ENTITY_UNK_2
  s16 demoID;           // 0x18, '.d', DemoTable_GetMsg の第1添字
  s16 step;             // 0x1A, ('.c'-1) から1ずつ進む, 第2添字
  u16 msgIdx;           // 0x1C, 第3添字, 0件のステップに来たらデモ終了
  bool8 advanceReq;     // 0x1E, Demo_RequestNextStep が立て、Update が step を進めて落とす
  bool8 stepBegun;      // 0x1F, ステップが切り替わった回だけ 1, この回にメッセージを配る
  u16 endScriptID;      // 0x20, '.e', デモ終了時に実行するスクリプト
  u8 scriptCount;       // 0x22, scriptKeys/scriptIDs の件数
  bool8 running;        // 0x23, デモ再生中か？
  u8 bufIdx;            // 0x24, EntityMsgBox のダブルバッファの現在面
  u8 unk_25[3];         // 0x25, padding?
  u16 scriptKeys[16];   // 0x28, Demo_FindScriptID で検索されるキー
  u16 scriptIDs[16];    // 0x48, scriptKeys に対応するスクリプトID
  s32 waitTimer;        // 0x68, cmd 1 の待ちフレーム数, 根拠: Demo_CmdWait
  u32 unk_6c;           // 0x6C
  u32 extWait;          // 0x70, cmd 2 で 1 になり、Demo_Resume が外部から解除する
  EntityMsgBox* boxes;  // 0x74, 登録済みの受け口のリスト先頭
  EntityMsgBox msgBox;  // 0x78, 自分宛て (targetClass 1) の受け口
} EntityMsgBus;
static_assert(sizeof(EntityMsgBus) == 172);

COMMON_DATA s32 s32_03002b48 = 0;                // 0x03002B48, 多分こいつは msgbus.c のものじゃない
COMMON_DATA EntityMsgBus* gEntityMsgBus = NULL;  // 0x03002B4C

static u16 Demo_FindScriptID(u32 id);

// p->boxes のリストから targetID と targetClass が一致するノードを探す
EntityMsgBox* EntityMsgBus_FindBox(EntityMsgBus* p, u32 targetID, u32 targetClass) {
  EntityMsgBox* box;
  EntityMsgBox* next;
  for (box = p->boxes; box != NULL; box = next) {
    next = box->next;
    if (box->targetID == targetID && box->targetClass == targetClass) {
      return box;
    }
  }
  return NULL;
}

s32 EntityMsgBus_LinkBox(EntityMsgBus* p, EntityMsgBox* box) {
  if (p->boxes != NULL) {
    (p->boxes)->prev = box;
  }
  box->prev = NULL;
  box->next = p->boxes;
  p->boxes = box;
  return 0;
}

// box を p->boxes のリストから外す
s32 EntityMsgBus_UnlinkBox(EntityMsgBus* p, EntityMsgBox* box) {
  if (box->prev != NULL) {
    box->prev->next = box->next;
  } else {
    p->boxes = box->next;
  }
  if (box->next != NULL) {
    box->next->prev = box->prev;
  }
  return 0;
}

// msg の targetID/targetClass に一致するノードを探し、その現在と逆側の面に msg を追加する (1面あたり最大4件)
s32 EntityMsgBus_Post(EntityMsgBus* p, EntityMsg* msg) {
  EntityMsgBox* box = EntityMsgBus_FindBox(p, msg->targetID, msg->targetClass);
  s32 side = 1 - p->bufIdx;
  if (box != NULL && box->count[side] < 4) {
    box->msgs[side][box->count[side]] = msg;
    box->count[side]++;
  }
}

// リストの全ノードについて現在の面(bufIdx)のデータをクリアし、面を切り替える
void EntityMsgBus_SwapBuffers(EntityMsgBus* p) {
  EntityMsgBox* box;
  EntityMsgBox* next;
  for (box = p->boxes; box != NULL; box = next) {
    s32 i;
    next = box->next;
    box->count[p->bufIdx] = 0;
    for (i = 0; i < 4; i++) {
      box->msgs[p->bufIdx][i] = NULL;
    }
  }
  p->bufIdx = 1 - p->bufIdx;
}

// msg->args[0] に対応するスクリプトがあれば実行する
void Demo_CmdExecScript(EntityMsgBus* p, EntityMsgBox* box, EntityMsg* msg) {
  u16 scriptID = Demo_FindScriptID((u16)msg->args[0]);
  if (scriptID != 0) {
    VM_ExecByID(scriptID, NULL);
  }
  EntityMsgBox_EndWait(box, 1);
}

void Demo_CmdWait(EntityMsgBus* p, EntityMsgBox* box, EntityMsg* msg) {
  p->waitTimer = msg->args[0];
  if (p->waitTimer == 0) {
    EntityMsgBox_EndWait(box, 1);
  }
}

void Demo_CmdWaitExternal(EntityMsgBus* p, EntityMsgBox* box, EntityMsg* _) {
  p->extWait = 1;
  EntityMsgBox_EndWait(box, 1);
}

// 現在の面に溜まった msg を種類 (cmd) ごとのハンドラで処理する
NON_MATCH s32 Demo_HandleMsgs(EntityMsgBus* p) {
#ifdef NONMATCHING_C
  EntityMsgBox* box = &p->msgBox;

  s32 i = 0;
  while (i < box->count[gEntityMsgBus->bufIdx]) {
    EntityMsg* msg = box->msgs[gEntityMsgBus->bufIdx][i];
    EntityMsgBox_BeginWait(box, msg);
    switch (msg->cmd) {
      case 0: {
        Demo_CmdExecScript(p, box, msg);
        break;
      }
      case 1: {
        Demo_CmdWait(p, box, msg);
        break;
      }
      case 2: {
        Demo_CmdWaitExternal(p, box, msg);
        break;
      }
    }
    i++;
  }
  return 0;
#else
  INCFUNC("asm/func/Demo_HandleMsgs.inc");
#endif
}

s32 EntityMsgBus_Update(EntityMsgBus* p) {
  bool32 exec = FALSE;

  if (p->running == 1) {
    p->stepBegun = FALSE;
    if (p->advanceReq) {
      p->step++;
      p->msgIdx = 0;
      p->advanceReq = FALSE;
      p->stepBegun = TRUE;
    }

    if (p->stepBegun) {
      EntityMsg* msg;

      p->msgIdx = 0;
      while ((msg = DemoTable_GetMsg(p->demoID, p->step, p->msgIdx)) != NULL) {
        EntityMsgBus_Post(p, msg);
        p->msgIdx++;
      }

      if (p->msgIdx == 0) {
        if (p->endScriptID != 0) VM_ExecByID(p->endScriptID, NULL);
        p->running = 0;
        return 0;
      }
      exec = TRUE;
    }

    if (p->waitTimer != 0) {
      p->waitTimer--;
      if (p->waitTimer == 0) {
        EntityMsgBox_EndWait(&p->msgBox, 1);
      }
    }
  }

  EntityMsgBus_SwapBuffers(p);
  if (exec) {
    Demo_HandleMsgs(p);
  }
  return 0;
}

s32 EntityMsgBus_Destroy(EntityMsgBus* p) {
  EntityMsgBus_Unregister(&p->msgBox);
  gEntityMsgBus = NULL;
  return 0;
}

s32 EntityMsgBus_Init(EntityMsgBus* p, u32 id) {
  gEntityMsgBus = p;
  p->running = 0;
  p->demoID = -1;
  p->step = -1;
  p->msgIdx = 0;
  p->advanceReq = FALSE;
  p->stepBegun = FALSE;
  p->endScriptID = 0;
  p->scriptCount = 0;
  p->unk_6c = 0;
  p->boxes = NULL;
  EntityMsgBus_Register(&p->msgBox, id, 1);
  return 0;
}

EntityMsgBus* EntityMsgBus_Create(u32 id) {
  EntityMsgBus* p;
  if (gEntityMsgBus != NULL) {
    return NULL;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(EntityMsgBus));
  if (p != NULL) {
    SetEntityRoutine(p, EntityMsgBus_Update, EntityMsgBus_Destroy);
    if (EntityMsgBus_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// p を初期化して gEntityMsgBus のリストに登録する
s32 EntityMsgBus_Register(EntityMsgBox* box, u32 targetID, s32 targetClass) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  box->targetID = targetID;
  box->targetClass = targetClass;
  box->count[0] = 0;
  box->count[1] = 0;
  box->waitFlag = 0;
  return EntityMsgBus_LinkBox(gEntityMsgBus, box);
}

// p を gEntityMsgBus のリストから外す
s32 EntityMsgBus_Unregister(EntityMsgBox* box) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  return EntityMsgBus_UnlinkBox(gEntityMsgBus, box);
}

s32 Demo_RequestNextStep(void) {
  if (gEntityMsgBus == NULL) return -1;
  if (gEntityMsgBus->advanceReq) return -2;
  gEntityMsgBus->advanceReq = TRUE;
  return 0;
}

bool32 EntityMsgBox_BeginWait(EntityMsgBox* box, EntityMsg* msg) {
  if (msg->waitFlag) {
    box->waitFlag = msg->waitFlag;
    return TRUE;
  }
  return FALSE;
}

bool32 EntityMsgBox_EndWait(EntityMsgBox* box, u32 val) {
  if (box->waitFlag == val) {
    Demo_RequestNextStep();
    box->waitFlag = 0;
    return TRUE;
  }
  return FALSE;
}

// id に対応するスクリプトIDを scriptKeys/scriptIDs のテーブルから引く (見つからなければ 0)
static u16 Demo_FindScriptID(u32 id) {
  EntityMsgBus* p = gEntityMsgBus;
  s32 i;
  if (p == NULL) {
    return 0;
  }
  for (i = 0; i < p->scriptCount; i++) {
    if (p->scriptKeys[i] == id) {
      return p->scriptIDs[i];
    }
  }
  return 0;
}

// msg の targetID/targetClass に一致するノードを探し、その現在と逆側の面に msg を追加する
s32 EntityMsg_Send(EntityMsg* msg) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  return EntityMsgBus_Post(gEntityMsgBus, msg);
}

// '.d'/'.c'/'.e'/'.p' から設定を読み込み、scriptKeys/scriptIDs のテーブルを作る
s32 Demo_Start(void) {
  EntityMsgBus* p = gEntityMsgBus;
  EntityMsgBox* box;

  s32 i;
  if (p == NULL || p->running == 1) {
    return -1;
  }
  p->running = 1;
  p->demoID = VM_GetNamedArgValue('d', -1);
  p->step = VM_GetNamedArgValue('c', -1) - 1;
  p->msgIdx = 0;
  p->advanceReq = TRUE;
  p->stepBegun = FALSE;
  p->endScriptID = VM_GetNamedArgValue('e', 0);

  p->scriptCount = 0;
  if (VM_SeekToNamedArg('p')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() == NULL) break;
      p->scriptKeys[p->scriptCount] = VM_GetValue();
      if (VM_GetPC() == NULL) break;
      p->scriptIDs[p->scriptCount] = VM_GetValue();
      p->scriptCount++;
    }
  }

  p->unk_6c = 0;
  box = &p->msgBox;
  box->count[0] = 0;
  box->count[1] = 0;
  box->waitFlag = 0;
  return 0;
}

s32 Demo_Stop(void) {
  EntityMsgBus* p = gEntityMsgBus;
  if (p == NULL) {
    return -1;
  }
  p->running = 0;
  p->demoID = -1;
  p->step = -1;
  p->msgIdx = 0;
  p->advanceReq = FALSE;
  p->stepBegun = FALSE;
  p->endScriptID = 0;
  p->scriptCount = 0;
  p->unk_6c = 0;
  return 0;
}

s32 Demo_Resume(void) {
  if (gEntityMsgBus == NULL || gEntityMsgBus->extWait == 0) {
    return -1;
  }
  gEntityMsgBus->extWait = 0;
  Demo_RequestNextStep();
  return 0;
}

bool32 Demo_IsRunning(void) {
  if (gEntityMsgBus == NULL || gEntityMsgBus->running != 1) {
    return FALSE;
  }
  return TRUE;
}
