#include "msgbus.h"

#include "entity.h"
#include "global.h"
#include "vm.h"

// メッセージバス兼デモ再生機。シングルトン (gEntityMsgBus) で、これがいないとメッセージ機構そのものが動かない
// 受け口: 全エンティティの EntityMsgBox を boxes のリストで持ち、登録・解除・ダブルバッファの面切り替えを一手に引き受ける
// 再生: デモスクリプト (PTR_ARRAY_08dbd564) を demoID/step で読み進め、各 EntityMsg を宛先の受け口へ配る
// 自身も targetClass 1 の宛先で、cmd 0=スクリプト実行 / 1=ウェイト / 2=外部待ち を Demo_HandleMsgs で処理する
typedef struct EntityMsgBus {
  Entity e;             // ENTITY_UNK_2
  u16 demoID;           // 0x18, キーワード 'd'。DemoTable_GetMsg の第1添字
  s16 step;             // 0x1A, キーワード 'c' - 1 から1ずつ進む。第2添字
  u16 msgIdx;           // 0x1C, 第3添字。0件のステップに来たらデモ終了
  u8 advanceReq;        // 0x1E, Demo_RequestNextStep が立て、Update が step を進めて落とす
  u8 stepBegun;         // 0x1F, ステップが切り替わった回だけ 1。この回にメッセージを配る
  u16 endScriptID;      // 0x20, キーワード 'e'。デモ終了時に実行する
  u8 scriptCount;       // 0x22, scriptKeys/scriptIDs の件数
  u8 running;           // 0x23, デモ再生中なら 1, 根拠: Demo_IsRunning
  u8 bufIdx;            // 0x24, EntityMsgBox のダブルバッファの現在面
  u8 unk_25[3];         // 0x25, ??
  u16 scriptKeys[16];   // 0x28, Demo_FindScriptID で検索されるキー
  u16 scriptIDs[16];    // 0x48, scriptKeys に対応するスクリプトID
  s32 waitTimer;        // 0x68, cmd 1 の待ちフレーム数, 根拠: Demo_CmdWait
  u32 unk_6c;           // 0x6C
  u32 extWait;          // 0x70, cmd 2 で 1 になり、Demo_Resume が外部から解除する
  EntityMsgBox* boxes;  // 0x74, 登録済みの受け口のリスト先頭
  EntityMsgBox msgBox;  // 0x78, 自分宛て (targetClass 1) の受け口
} EntityMsgBus;
static_assert(sizeof(EntityMsgBus) == 172);

extern EntityMsgBus* gEntityMsgBus;  // 0x03002B4C

bool32 EntityMsgBox_BeginWait(EntityMsgBox* p, EntityMsg* data);
bool32 EntityMsgBox_EndWait(EntityMsgBox* p, u32 val);
u16 Demo_FindScriptID(u32 id);
EntityMsg* DemoTable_GetMsg(s32 idx1, s32 idx2, s32 idx3);

// p->boxes のリストから targetID と targetClass が一致するノードを探す
EntityMsgBox* EntityMsgBus_FindBox(EntityMsgBus* p, u32 targetID, u32 targetClass) {
  EntityMsgBox* data;
  EntityMsgBox* next;
  for (data = p->boxes; data != NULL; data = next) {
    next = data->next;
    if (data->targetID == targetID && data->targetClass == targetClass) {
      return data;
    }
  }
  return NULL;
}

s32 EntityMsgBus_LinkBox(EntityMsgBus* p, EntityMsgBox* data) {
  if (p->boxes != NULL) {
    (p->boxes)->prev = data;
  }
  data->prev = NULL;
  data->next = p->boxes;
  p->boxes = data;
  return 0;
}

// data を p->boxes のリストから外す
s32 EntityMsgBus_UnlinkBox(EntityMsgBus* p, EntityMsgBox* data) {
  if (data->prev != NULL) {
    data->prev->next = data->next;
  } else {
    p->boxes = data->next;
  }
  if (data->next != NULL) {
    data->next->prev = data->prev;
  }
  return 0;
}

// data の targetID/targetClass に一致するノードを探し、その現在と逆側の面に data を追加する (1面あたり最大4件)
s32 EntityMsgBus_Post(EntityMsgBus* p, EntityMsg* data) {
  EntityMsgBox* node;
  s32 side;
  node = EntityMsgBus_FindBox(p, data->targetID, data->targetClass);
  side = 1 - p->bufIdx;
  if (node != NULL && node->count[side] < 4) {
    node->msgs[side][node->count[side]] = data;
    node->count[side]++;
  }
}

// リストの全ノードについて現在の面(bufIdx)のデータをクリアし、面を切り替える
void EntityMsgBus_SwapBuffers(EntityMsgBus* p) {
  EntityMsgBox* data;
  EntityMsgBox* next;
  s32 i;
  for (data = p->boxes; data != NULL; data = next) {
    next = data->next;
    data->count[p->bufIdx] = 0;
    for (i = 0; i < 4; i++) {
      data->msgs[p->bufIdx][i] = NULL;
    }
  }
  p->bufIdx = 1 - p->bufIdx;
}

// data->args[0] に対応するスクリプトがあれば実行する
void Demo_CmdExecScript(EntityMsgBus* p, EntityMsgBox* q, EntityMsg* data) {
  u16 scriptID = Demo_FindScriptID((u16)data->args[0]);
  if (scriptID != 0) {
    Script_ExecById(scriptID, NULL);
  }
  EntityMsgBox_EndWait(q, 1);
}

void Demo_CmdWait(EntityMsgBus* p, EntityMsgBox* q, EntityMsg* data) {
  p->waitTimer = data->args[0];
  if (p->waitTimer == 0) {
    EntityMsgBox_EndWait(q, 1);
  }
}

void Demo_CmdWaitExternal(EntityMsgBus* p, EntityMsgBox* q, EntityMsg* _) {
  p->extWait = 1;
  EntityMsgBox_EndWait(q, 1);
}

// 現在の面に溜まった data を種類 (cmd) ごとのハンドラで処理する
NON_MATCH s32 Demo_HandleMsgs(EntityMsgBus* p) {
#ifdef NONMATCHING_C
  EntityMsgBox* node = &p->msgBox;
  EntityMsg* data;
  s32 i = 0;
  while (i < node->count[gEntityMsgBus->bufIdx]) {
    data = node->msgs[gEntityMsgBus->bufIdx][i];
    EntityMsgBox_BeginWait(node, data);
    switch (data->cmd) {
      case 0: {
        Demo_CmdExecScript(p, node, data);
        break;
      }
      case 1: {
        Demo_CmdWait(p, node, data);
        break;
      }
      case 2: {
        Demo_CmdWaitExternal(p, node, data);
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
  EntityMsg* data;
  if (p->running == 1) {
    p->stepBegun = 0;
    if (p->advanceReq != 0) {
      p->step++;
      p->msgIdx = 0;
      p->advanceReq = 0;
      p->stepBegun = 1;
    }
    if (p->stepBegun != 0) {
      p->msgIdx = 0;
      while ((data = DemoTable_GetMsg((s16)p->demoID, p->step, p->msgIdx)) != NULL) {
        EntityMsgBus_Post(p, data);
        p->msgIdx++;
      }
      if (p->msgIdx == 0) {
        if (p->endScriptID != 0) {
          Script_ExecById(p->endScriptID, NULL);
        }
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

s32 EntityMsgBus_Init(EntityMsgBus* p, u32 subroutineID) {
  gEntityMsgBus = p;
  p->running = 0;
  p->demoID = 0xFFFF;
  p->step = -1;
  p->msgIdx = 0;
  p->advanceReq = 0;
  p->stepBegun = 0;
  p->endScriptID = 0;
  p->scriptCount = 0;
  p->unk_6c = 0;
  p->boxes = NULL;
  EntityMsgBus_Register(&p->msgBox, subroutineID, 1);
  return 0;
}

EntityMsgBus* EntityMsgBus_Create(u32 subroutineID) {
  EntityMsgBus* p;
  if (gEntityMsgBus != NULL) {
    return NULL;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(EntityMsgBus));
  if (p != NULL) {
    SetEntityRoutine(p, EntityMsgBus_Update, EntityMsgBus_Destroy);
    if (EntityMsgBus_Init(p, subroutineID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// p を初期化して gEntityMsgBus のリストに登録する
s32 EntityMsgBus_Register(EntityMsgBox* p, u32 targetID, s32 targetClass) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  p->targetID = targetID;
  p->targetClass = targetClass;
  p->count[0] = 0;
  p->count[1] = 0;
  p->waitFlag = 0;
  return EntityMsgBus_LinkBox(gEntityMsgBus, p);
}

// p を gEntityMsgBus のリストから外す
s32 EntityMsgBus_Unregister(EntityMsgBox* p) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  return EntityMsgBus_UnlinkBox(gEntityMsgBus, p);
}

s32 Demo_RequestNextStep(void) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  if (gEntityMsgBus->advanceReq != 0) {
    return -2;
  }
  gEntityMsgBus->advanceReq = 1;
  return 0;
}

bool32 EntityMsgBox_BeginWait(EntityMsgBox* p, EntityMsg* data) {
  if (data->waitFlag != 0) {
    p->waitFlag = data->waitFlag;
    return TRUE;
  }
  return FALSE;
}

bool32 EntityMsgBox_EndWait(EntityMsgBox* p, u32 val) {
  if (p->waitFlag == val) {
    Demo_RequestNextStep();
    p->waitFlag = 0;
    return TRUE;
  }
  return FALSE;
}

// id に対応するスクリプトIDを scriptKeys/scriptIDs のテーブルから引く (見つからなければ 0)
u16 Demo_FindScriptID(u32 id) {
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

// p の targetID/targetClass に一致するノードを探し、その現在と逆側の面に p を追加する
s32 EntityMsg_Send(EntityMsg* p) {
  if (gEntityMsgBus == NULL) {
    return -1;
  }
  return EntityMsgBus_Post(gEntityMsgBus, p);
}

// スクリプトのキーワード引数から設定を読み込み、scriptKeys/scriptIDs のテーブルを作る
s32 Demo_Start(void) {
  EntityMsgBus* p = gEntityMsgBus;
  EntityMsgBox* node;
  s32 i;
  if (p == NULL || p->running == 1) {
    return -1;
  }
  p->running = 1;
  p->demoID = VM_GetKeywordValue('d', -1);
  p->step = VM_GetKeywordValue('c', -1) - 1;
  p->msgIdx = 0;
  p->advanceReq = 1;
  p->stepBegun = 0;
  p->endScriptID = VM_GetKeywordValue('e', 0);
  p->scriptCount = 0;
  if (VM_SeekToKeyword('p')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() == NULL) {
        break;
      }
      p->scriptKeys[p->scriptCount] = Script_GetValue();
      if (VM_GetPC() == NULL) {
        break;
      }
      p->scriptIDs[p->scriptCount] = Script_GetValue();
      p->scriptCount++;
    }
  }
  p->unk_6c = 0;
  node = &p->msgBox;
  node->count[0] = 0;
  node->count[1] = 0;
  node->waitFlag = 0;
  return 0;
}

s32 Demo_Stop(void) {
  EntityMsgBus* p = gEntityMsgBus;
  if (p == NULL) {
    return -1;
  }
  p->running = 0;
  p->demoID = 0xFFFF;
  p->step = -1;
  p->msgIdx = 0;
  p->advanceReq = 0;
  p->stepBegun = 0;
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
