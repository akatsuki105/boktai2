#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "sound.h"

typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_11
  u8 unk_18[0x1C - 0x18];  // 0x18
  MsgQueue mq;             // 0x1C, EntityD3A9_Init が MsgQueue_Register に渡す
} EntityD3A9;
static_assert(sizeof(EntityD3A9) == 80);

// gMsgBus をこの inline 越しに読むと, メッセージ取り出しのループで原典どおり毎回プールから読み直す形になる
static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

void FUN_080c0ae4(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  PlaySound_082406e0(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b00(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  PlaySound_08240718(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b1c(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  sound_08240264(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b38(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeInBGM(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b54(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutBGMTemporarily(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b70(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  Sound_FadeOutBGM(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0b8c(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  FUN_082404b0(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0ba8(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  FUN_082404fc(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0bc4(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  FUN_08240568(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

void FUN_080c0be0(EntityD3A9* p, MsgQueue* mq, MsgPacket* msg) {
  FUN_082405c0(msg->args[0]);
  MsgQueue_EndWait(mq, 1);
}

// 届いたメッセージを cmd ごとのハンドラへ配る
void* EntityD3A9_HandleMessages(EntityD3A9* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        FUN_080c0ae4(p, mq, msg);
        break;
      }
      case 1: {
        FUN_080c0b00(p, mq, msg);
        break;
      }
      case 2: {
        FUN_080c0b1c(p, mq, msg);
        break;
      }
      case 3: {
        FUN_080c0b38(p, mq, msg);
        break;
      }
      case 4: {
        FUN_080c0b54(p, mq, msg);
        break;
      }
      case 5: {
        FUN_080c0b70(p, mq, msg);
        break;
      }
      case 6: {
        FUN_080c0b8c(p, mq, msg);
        break;
      }
      case 7: {
        FUN_080c0ba8(p, mq, msg);
        break;
      }
      case 8: {
        FUN_080c0bc4(p, mq, msg);
        break;
      }
      case 9: {
        FUN_080c0be0(p, mq, msg);
        break;
      }
    }
  }
}

s32 EntityD3A9_Update(EntityD3A9* p) {
  EntityD3A9_HandleMessages(p);
  return 0;
}

s32 EntityD3A9_Destroy(EntityD3A9* _) { return 0; }

s32 EntityD3A9_Init(EntityD3A9* p, u32 n) {
  MsgQueue_Register(&p->mq, n, CLS_SOUND);
  return 0;
}

// 0xD3A9
EntityD3A9* EntityD3A9_Create(u32 n) {
  EntityD3A9* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityD3A9));

  if (p != NULL) {
    SetEntityRoutine(p, EntityD3A9_Update, EntityD3A9_Destroy);
    if (EntityD3A9_Init(p, n) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
