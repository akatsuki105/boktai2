#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "msgbus_inline.h"
#include "sound.h"

// 原典の名前は "デモサウンドマネージャ" (0xD3A9), 宛先 ID は "サウンドマネージャ" (0x74E2), カットシーンからの音の命令を受け持つ, Scr_CreateMapSystems がマップごとに1体作る
typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_11
  u8 unk_18[0x1C - 0x18];  // 0x18
  MsgQueue mq;             // 0x1C, CutsceneSoundManager_Init が MsgQueue_Register に渡す
} CutsceneSoundManager;
static_assert(sizeof(CutsceneSoundManager) == 80);

void CutsceneSoundManager_CmdPlaySound(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  PlaySound_082406e0(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdPlaySoundUntracked(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  PlaySound_08240718(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdPlayBGM(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  sound_08240264(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdFadeInBGM(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeInBGM(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdPauseBGM(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutBGMTemporarily(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdFadeOutBGM(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutBGM(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdPlaySub(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_PlaySub(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdFadeInSub(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeInSub(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdPauseSub(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutSubTemporarily(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void CutsceneSoundManager_CmdFadeOutSub(CutsceneSoundManager* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutSub(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

// 届いたメッセージを cmd ごとのハンドラへ配る
void* CutsceneSoundManager_HandleMessages(CutsceneSoundManager* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        CutsceneSoundManager_CmdPlaySound(p, mq, msg);
        break;
      }
      case 1: {
        CutsceneSoundManager_CmdPlaySoundUntracked(p, mq, msg);
        break;
      }
      case 2: {
        CutsceneSoundManager_CmdPlayBGM(p, mq, msg);
        break;
      }
      case 3: {
        CutsceneSoundManager_CmdFadeInBGM(p, mq, msg);
        break;
      }
      case 4: {
        CutsceneSoundManager_CmdPauseBGM(p, mq, msg);
        break;
      }
      case 5: {
        CutsceneSoundManager_CmdFadeOutBGM(p, mq, msg);
        break;
      }
      case 6: {
        CutsceneSoundManager_CmdPlaySub(p, mq, msg);
        break;
      }
      case 7: {
        CutsceneSoundManager_CmdFadeInSub(p, mq, msg);
        break;
      }
      case 8: {
        CutsceneSoundManager_CmdPauseSub(p, mq, msg);
        break;
      }
      case 9: {
        CutsceneSoundManager_CmdFadeOutSub(p, mq, msg);
        break;
      }
    }
  }
}

s32 CutsceneSoundManager_Update(CutsceneSoundManager* p) {
  CutsceneSoundManager_HandleMessages(p);
  return 0;
}

s32 CutsceneSoundManager_Destroy(CutsceneSoundManager* _) { return 0; }

s32 CutsceneSoundManager_Init(CutsceneSoundManager* p, u32 n) {
  MsgQueue_Register(&p->mq, n, CLS_SOUND);
  return 0;
}

// 0xD3A9, HashName("デモサウンドマネージャ")
CutsceneSoundManager* CutsceneSoundManager_Create(u32 n) {
  CutsceneSoundManager* p = CreateEntity(ENTITY_UNK_11, sizeof(CutsceneSoundManager));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneSoundManager_Update, CutsceneSoundManager_Destroy);
    if (CutsceneSoundManager_Init(p, n) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
