#include "camera.h"
#include "entity.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"

// 原典の名前は "デモエフェクトマネージャ" (0x730A), カットシーンのフェード・粒の演出・画面揺れを受け持つ, Scr_CreateMapSystems がマップごとに1体作る
typedef struct {
  Entity e;                // ENTITY_UNK_3
  MsgQueue mq;             // 0x18
  u8 unk_4c[0x50 - 0x4C];  // 0x4C
  s32 shakeTimer;          // 0x50, 画面揺れの残りフレーム, 負なら止めるまで揺らし続ける
  s32 shakeAmplitude;      // 0x54, Camera_Shake に渡す揺れ幅
} CutsceneEffectManager;
static_assert(sizeof(CutsceneEffectManager) == 88);

void Entity99CA_CreateAt(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
void MapPltt_PushCommand(s32 val, s32 count, u32* args);
void Entity6978_SetRequest(s32 val, s32 count, s32* args);
void RingoCutsceneAnim_Create(Vec3* pos, MsgQueue* mq);

// gMsgBus をこの inline 越しに読むと, メッセージ取り出しのループで原典どおり毎回プールから読み直す形になる
static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

void CutsceneEffectManager_CmdRisingPtclAt(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
  Vec3 pos;
  VEC3_SET(pos, msg->args[0], msg->args[1], msg->args[2]);
  Entity99CA_CreateAt(&pos, msg->args[3], msg->args[4], msg->args[5], msg->args[6]);
}

void CutsceneEffectManager_CmdRisingPtclOn(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
  Mover* mover = Mover_FindByID_Proxy(msg->args[0]);

  if (mover != NULL) {
    Vec3 pos;
    VEC3_SET(pos, mover->pos.x, mover->pos.y, mover->pos.z);
    Entity99CA_CreateAt(&pos, msg->args[1], msg->args[2], msg->args[3], msg->args[4]);
  }
}

NON_MATCH void CutsceneEffectManager_CmdFade(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  s16* args = msg->args;
  u32 flags = 0;
  s32 kind;

  if (args[5] != 0) {
    flags = 0x0FFF;
  }
  if (args[6] != 0) {
    flags |= 0x1000;
  }
  if (args[7] != 0) {
    flags |= 0xE000;
  }
  kind = 3;
  if (msg->args[0] == 0) {
    kind = 2;
  }
  StartBgObjPlttFade(kind, args[1], args[2], args[3], args[4], flags, args[8]);
#else
  INCFUNC("asm/func/CutsceneEffectManager_CmdFade.inc");
#endif
}

NON_MATCH void CutsceneEffectManager_CmdFadeBG(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  s16* args = msg->args;
  u32 cmd[5];
  u32 flags = 0;
  s32 kind;

  if (args[5] != 0) {
    flags = 0x0FFF;
  }
  if (args[6] != 0) {
    flags |= 0x1000;
  }
  if (args[7] != 0) {
    flags |= 0xE000;
  }
  cmd[0] = args[1];
  cmd[1] = args[2];
  cmd[2] = args[3];
  cmd[3] = args[4];
  cmd[4] = flags;
  if ((cmd[1] == 0) && (cmd[2] == 0) && (cmd[3] == 0)) {
    cmd[1] = 4;
    cmd[2] = 4;
    cmd[3] = 4;
  }
  kind = 3;
  if (args[0] == 0) {
    kind = 2;
  }
  MapPltt_PushCommand(kind, 5, cmd);
#else
  INCFUNC("asm/func/CutsceneEffectManager_CmdFadeBG.inc");
#endif
}

NON_MATCH void CutsceneEffectManager_CmdFadeObj(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  s16* args = msg->args;
  s32 cmd[5];
  s32 kind;

  cmd[0] = args[1];
  cmd[1] = args[2];
  cmd[2] = args[3];
  cmd[3] = args[4];
  cmd[4] = args[8];
  if ((cmd[1] == 0) && (cmd[2] == 0) && (cmd[3] == 0)) {
    cmd[1] = 4;
    cmd[2] = 4;
    cmd[3] = 4;
  }
  kind = 2;
  if (args[0] == 0) {
    kind = 1;
  }
  Entity6978_SetRequest(kind, 5, cmd);
#else
  INCFUNC("asm/func/CutsceneEffectManager_CmdFadeObj.inc");
#endif
}

void CutsceneEffectManager_CmdShake(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
  p->shakeTimer = msg->args[0];
  p->shakeAmplitude = msg->args[1];
}

void CutsceneEffectManager_CmdStopShake(CutsceneEffectManager* p, MsgQueue* mq, MsgPacket* msg) {
  p->shakeTimer = 0;
  p->shakeAmplitude = 0;
}

// 溜まったメッセージを cmd ごとのハンドラへ配る
s32 CutsceneEffectManager_HandleMessages(CutsceneEffectManager* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];
    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        CutsceneEffectManager_CmdRisingPtclAt(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 1: {
        CutsceneEffectManager_CmdRisingPtclOn(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 2: {
        CutsceneEffectManager_CmdFade(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 3: {
        CutsceneEffectManager_CmdFadeBG(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 4: {
        CutsceneEffectManager_CmdFadeObj(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 5: {
        CutsceneEffectManager_CmdShake(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 6: {
        CutsceneEffectManager_CmdStopShake(p, mq, msg);
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 7: {
        Vec3 pos;
        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        RingoCutsceneAnim_Create(&pos, mq);
        break;
      }
    }
  }
  return 0;
}

s32 CutsceneEffectManager_Update(CutsceneEffectManager* p) {
  CutsceneEffectManager_HandleMessages(p);
  if (p->shakeTimer != 0) {
    if (p->shakeTimer > 0) {
      p->shakeTimer--;
    }
    Camera_Shake(p->shakeAmplitude);
  }
  return 0;
}

s32 CutsceneEffectManager_Destroy(CutsceneEffectManager* p) {
  MsgQueue_Unregister(&p->mq);
  return 0;
}

s32 CutsceneEffectManager_Init(CutsceneEffectManager* p, u32 param) {
  MsgQueue_Register(&p->mq, param, CLS_EFFECT);
  return 0;
}

// 0x730A, HashName("デモエフェクトマネージャ")
CutsceneEffectManager* CutsceneEffectManager_Create(u32 param) {
  CutsceneEffectManager* p = CreateEntity(ENTITY_UNK_3, sizeof(CutsceneEffectManager));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneEffectManager_Update, CutsceneEffectManager_Destroy);
    if (CutsceneEffectManager_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
