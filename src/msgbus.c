#include "msgbus.h"

#include "entity.h"
#include "global.h"
#include "vm.h"

// メッセージバス兼デモ再生機, シングルトン (gMsgBus) で、これがいないとメッセージ機構そのものが動かない
// 受け口: 全ての MsgQueue を queues のリストで持ち、登録・解除・ダブルバッファの面切り替えを一手に引き受ける
// 再生: デモスクリプト (PTR_ARRAY_08dbd564) を demoID/step で読み進め、各 MsgPacket を宛先の受け口へ配る
// 自身も targetClass 1 の宛先で、cmd 0=スクリプト実行 / 1=ウェイト / 2=外部待ち を Demo_HandleMsgs で処理する
typedef struct {
  Entity e;            // ENTITY_UNK_2
  s16 demoID;          // 0x18, '.d', DemoTable_GetMsg の第1添字
  s16 step;            // 0x1A, ('.c'-1) から1ずつ進む, 第2添字
  u16 msgIdx;          // 0x1C, 第3添字, 0件のステップに来たらデモ終了
  bool8 advanceReq;    // 0x1E, Demo_RequestNextStep が立て、Update が step を進めて落とす
  bool8 stepBegun;     // 0x1F, ステップが切り替わった回だけ 1, この回にメッセージを配る
  u16 endScriptID;     // 0x20, '.e', デモ終了時に実行するスクリプト
  u8 scriptCount;      // 0x22, scriptKeys/scriptIDs の件数
  bool8 running;       // 0x23, デモ再生中か？
  u8 bufIdx;           // 0x24, MsgQueue のダブルバッファの現在面
  u8 unk_25[3];        // 0x25, padding?
  u16 scriptKeys[16];  // 0x28, Demo_FindScriptID で検索されるキー
  u16 scriptIDs[16];   // 0x48, scriptKeys に対応するスクリプトID
  s32 waitTimer;       // 0x68, cmd 1 の待ちフレーム数, 根拠: Demo_CmdWait
  u32 unk_6c;          // 0x6C
  u32 extWait;         // 0x70, cmd 2 で 1 になり、Demo_Resume が外部から解除する
  MsgQueue* queues;    // 0x74, 登録済みの受け口のリスト先頭
  MsgQueue mq;         // 0x78, 自分宛て (targetClass 1) の受け口
} MsgBus;
static_assert(sizeof(MsgBus) == 172);

COMMON_DATA s32 s32_03002b48 = 0;    // 0x03002B48
COMMON_DATA MsgBus* gMsgBus = NULL;  // 0x03002B4C

static u16 Demo_FindScriptID(u32 id);

// p->queues のリストから targetID と targetClass が一致する受け口を探す
MsgQueue* MsgBus_FindQueue(MsgBus* p, u32 targetID, u32 targetClass) {
  MsgQueue* mq;
  MsgQueue* next;
  for (mq = p->queues; mq != NULL; mq = next) {
    next = mq->next;
    if (mq->targetID == targetID && mq->targetClass == targetClass) {
      return mq;
    }
  }
  return NULL;
}

s32 MsgBus_LinkQueue(MsgBus* p, MsgQueue* mq) {
  if (p->queues != NULL) {
    (p->queues)->prev = mq;
  }
  mq->prev = NULL;
  mq->next = p->queues;
  p->queues = mq;
  return 0;
}

// mq を p->queues のリストから外す
s32 MsgBus_UnlinkQueue(MsgBus* p, MsgQueue* mq) {
  if (mq->prev != NULL) {
    mq->prev->next = mq->next;
  } else {
    p->queues = mq->next;
  }
  if (mq->next != NULL) {
    mq->next->prev = mq->prev;
  }
  return 0;
}

// msg の targetID/targetClass に一致する受け口を探し、その現在と逆側の面に msg を追加する (1面あたり最大4件)
s32 MsgBus_Post(MsgBus* p, MsgPacket* msg) {
  MsgQueue* mq = MsgBus_FindQueue(p, msg->targetID, msg->targetClass);
  s32 side = 1 - p->bufIdx;
  if (mq != NULL && mq->count[side] < 4) {
    mq->msgs[side][mq->count[side]] = msg;
    mq->count[side]++;
  }
}

// リストの全受け口について現在の面(bufIdx)のデータをクリアし、面を切り替える
void MsgBus_SwapBuffers(MsgBus* p) {
  MsgQueue* mq;
  MsgQueue* next;
  for (mq = p->queues; mq != NULL; mq = next) {
    s32 i;
    next = mq->next;
    mq->count[p->bufIdx] = 0;
    for (i = 0; i < 4; i++) {
      mq->msgs[p->bufIdx][i] = NULL;
    }
  }
  p->bufIdx = 1 - p->bufIdx;
}

// msg->args[0] に対応するスクリプトがあれば実行する
void Demo_CmdExecScript(MsgBus* p, MsgQueue* mq, MsgPacket* msg) {
  u16 scriptID = Demo_FindScriptID((u16)msg->args[0]);
  if (scriptID != 0) {
    VM_ExecByID(scriptID, NULL);
  }
  MsgQueue_EndWait(mq, 1);
}

void Demo_CmdWait(MsgBus* p, MsgQueue* mq, MsgPacket* msg) {
  p->waitTimer = msg->args[0];
  if (p->waitTimer == 0) {
    MsgQueue_EndWait(mq, 1);
  }
}

void Demo_CmdWaitExternal(MsgBus* p, MsgQueue* mq, MsgPacket* _) {
  p->extWait = 1;
  MsgQueue_EndWait(mq, 1);
}

// 現在の面に溜まった msg を種類 (cmd) ごとのハンドラで処理する
NON_MATCH s32 Demo_HandleMsgs(MsgBus* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &p->mq;

  s32 i = 0;
  while (i < mq->count[gMsgBus->bufIdx]) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];
    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        Demo_CmdExecScript(p, mq, msg);
        break;
      }
      case 1: {
        Demo_CmdWait(p, mq, msg);
        break;
      }
      case 2: {
        Demo_CmdWaitExternal(p, mq, msg);
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

s32 MsgBus_Update(MsgBus* p) {
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
      MsgPacket* msg;

      p->msgIdx = 0;
      while ((msg = DemoTable_GetMsg(p->demoID, p->step, p->msgIdx)) != NULL) {
        MsgBus_Post(p, msg);
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
        MsgQueue_EndWait(&p->mq, 1);
      }
    }
  }

  MsgBus_SwapBuffers(p);
  if (exec) {
    Demo_HandleMsgs(p);
  }
  return 0;
}

s32 MsgBus_Destroy(MsgBus* p) {
  MsgQueue_Unregister(&p->mq);
  gMsgBus = NULL;
  return 0;
}

s32 MsgBus_Init(MsgBus* p, u32 targetID) {
  gMsgBus = p;
  p->running = 0;
  p->demoID = -1;
  p->step = -1;
  p->msgIdx = 0;
  p->advanceReq = FALSE;
  p->stepBegun = FALSE;
  p->endScriptID = 0;
  p->scriptCount = 0;
  p->unk_6c = 0;
  p->queues = NULL;
  MsgQueue_Register(&p->mq, targetID, 1);
  return 0;
}

MsgBus* MsgBus_Create(u32 targetID) {
  MsgBus* p;
  if (gMsgBus != NULL) {
    return NULL;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(MsgBus));
  if (p != NULL) {
    SetEntityRoutine(p, MsgBus_Update, MsgBus_Destroy);
    if (MsgBus_Init(p, targetID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// mq を初期化して gMsgBus のリストに登録する
s32 MsgQueue_Register(MsgQueue* mq, u32 targetID, s32 targetClass) {
  if (gMsgBus == NULL) {
    return -1;
  }
  mq->targetID = targetID;
  mq->targetClass = targetClass;
  mq->count[0] = 0;
  mq->count[1] = 0;
  mq->waitFlag = 0;
  return MsgBus_LinkQueue(gMsgBus, mq);
}

// mq を gMsgBus のリストから外す
s32 MsgQueue_Unregister(MsgQueue* mq) {
  if (gMsgBus == NULL) {
    return -1;
  }
  return MsgBus_UnlinkQueue(gMsgBus, mq);
}

s32 Demo_RequestNextStep(void) {
  if (gMsgBus == NULL) return -1;
  if (gMsgBus->advanceReq) return -2;
  gMsgBus->advanceReq = TRUE;
  return 0;
}

bool32 MsgQueue_BeginWait(MsgQueue* mq, MsgPacket* msg) {
  if (msg->waitFlag) {
    mq->waitFlag = msg->waitFlag;
    return TRUE;
  }
  return FALSE;
}

bool32 MsgQueue_EndWait(MsgQueue* mq, u32 waitFlag) {
  if (mq->waitFlag == waitFlag) {
    Demo_RequestNextStep();
    mq->waitFlag = 0;
    return TRUE;
  }
  return FALSE;
}

// id に対応するスクリプトIDを scriptKeys/scriptIDs のテーブルから引く (見つからなければ 0)
static u16 Demo_FindScriptID(u32 id) {
  MsgBus* p = gMsgBus;
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

// msg の targetID/targetClass に一致する受け口を探し、その現在と逆側の面に msg を追加する
s32 MsgPacket_Send(MsgPacket* msg) {
  if (gMsgBus == NULL) {
    return -1;
  }
  return MsgBus_Post(gMsgBus, msg);
}

// '.d'/'.c'/'.e'/'.p' から設定を読み込み、scriptKeys/scriptIDs のテーブルを作る
s32 Demo_Start(void) {
  MsgBus* p = gMsgBus;
  MsgQueue* mq;

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
  mq = &p->mq;
  mq->count[0] = 0;
  mq->count[1] = 0;
  mq->waitFlag = 0;
  return 0;
}

s32 Demo_Stop(void) {
  MsgBus* p = gMsgBus;
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
  if (gMsgBus == NULL || gMsgBus->extWait == 0) {
    return -1;
  }
  gMsgBus->extWait = 0;
  Demo_RequestNextStep();
  return 0;
}

bool32 Demo_IsRunning(void) {
  if (gMsgBus == NULL || gMsgBus->running != 1) {
    return FALSE;
  }
  return TRUE;
}
