#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "trig.h"
#include "vm.h"

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }
static inline s32 GetAngleTo(WorldPos* pos, WorldPos* target) { return ArcTan2_8(target->x - pos->x, target->z - pos->z); }

void FUN_08207ac4(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void FUN_08207af0(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void FUN_08207b1c(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void Sumire_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sSumireStates[19])(NPCManager*, NPC*) = {
      FUN_0804355c,
      FUN_08043588,
      FUN_080435b4,
      FUN_080435f0,
      FUN_0804364c,
      FUN_08043688,
      FUN_080436c4,
      FUN_08043774,
      FUN_08043960,
      FUN_08043a24,
      FUN_08043bcc,
      FUN_08043c94,
      FUN_08043cc4,
      FUN_08043cf4,
      NPC_StateWaitTimeWindow,
      FUN_08043e54,
      FUN_08207ac4,
      FUN_08207af0,
      FUN_08207b1c,
  };  // 0x085AEACC
  // clang-format on
  sSumireStates[npc->state](p, npc);
}

void Sumire_UpdateState(NPCManager* p, NPC* npc) { Sumire_DispatchState(p, npc); }

s32 Sumire_RunState(NPCManager* p, NPC* npc) {
  Sumire_UpdateState(p, npc);
  return 0;
}

void FUN_08207b78(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

void FUN_08207bbc(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 6, 2, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

void FUN_08207c00(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 7, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

static void (*const sSumireUpdates[17])(NPCManager*, NPC*, s32) = {
    NULL,
    NPC_UpdateHidden,
    NPC_UpdateIdle,
    NPC_UpdateWalkToTarget,
    NPC_UpdateTurn,
    NPC_UpdateDropIn,
    NPC_UpdateRiseOut,
    FUN_08042868,
    NPC_UpdateWalkPath,
    NPC_UpdateFacePlayer,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    NPC_UpdateNavToPathStart,
    FUN_08207b78,
    FUN_08207bbc,
    FUN_08207c00,
};  // 0x085AEB18

u8 Sumire_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 17) {
    return 0;
  }

  fn = sSumireUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Sumire_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void Sumire_HandleMsgs(NPC* npc) {
  MsgQueue* mq = &npc->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        NPC_StartState(npc, 0);
        break;
      }
      case 1: {
        npc->targetAngle = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 1);
        break;
      }
      case 3: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
        NPC_StartState(npc, 2);
        break;
      }
      case 2: {
        npc->targetAngle = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 3);
        break;
      }
      case 4: {
        NPC_StartState(npc, 4);
        break;
      }
      case 5: {
        NPC_StartState(npc, 5);
        break;
      }
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
        break;
      }
      case 37: {
        NPC_StartState(npc, 16);
        break;
      }
      case 38: {
        NPC_StartState(npc, 17);
        break;
      }
      case 39: {
        NPC_StartState(npc, 18);
        break;
      }
    }
  }
}

s32 Sumire_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Sumire_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Sumire_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Sumire_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xB189, HashName("ＮＰＣスミレ"), スミレの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnSumireNPC(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 4);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  flags = 0;

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (NPC_InitMover(npc, id, &pos, angle) < 0) {
    return;
  }
  if (NPC_InitSprite(npc, 2, SPR_SUMIRE, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 300, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Sumire_SelectUpdate);
  NPC_SetCb(npc, 0, Sumire_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Sumire_RunState);
  NPC_SetCb(npc, 2, Sumire_RunUpdate);
  NPC_SetCb(npc, 3, Sumire_UpdateVisibility);
  NPC_SetOnDestroy(npc, Sumire_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_SUMIRE, 0);
  NPCManager_LinkNPC(p, npc);
  NPC_ReadConfigArgs(p, npc);

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      NPC_StartState(npc, 1);
      NPC_SetUpdate(npc, NPC_UpdateIdle, 2);
      break;
    }
    case 1: {
      NPC_StartState(npc, 0);
      NPC_SetUpdate(npc, NPC_UpdateHidden, 1);
      SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_HIDDEN);
      NPC_HideShadow(npc);
      break;
    }
    case 2: {
      npc->unk_217 = 1;
      if (npc->pathIdx >= 0) {
        NPC_StartState(npc, FUN_08043510(npc));
        NPC_SetUpdate(npc, NPC_UpdateIdle, 2);
      } else {
        NPC_StartState(npc, 6);
        NPC_SetUpdate(npc, FUN_08042868, 7);
      }
      break;
    }
  }
}
