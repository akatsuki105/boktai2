#include "emote.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "trig.h"
#include "vm.h"

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }
static inline s32 GetAngleTo(WorldPos* pos, WorldPos* target) { return ArcTan2_8(target->x - pos->x, target->z - pos->z); }

void FUN_08207120(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08207170(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 1, 6);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_082071c0(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08207210(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCZajiWork* work = &npc->work.zaji;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 6, 2, 1, 4);
    npc->work.zaji.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  switch (npc->work.zaji.step) {
    case 0: {
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        NPC_PlayAnim(npc, 7, 1, 1, 4);
        npc->work.zaji.step++;
        work->timer = 0;
      }
      break;
    }
    case 1: {
      npc->updateDone = 1;
      npc->work.zaji.step++;
      work->timer = 0;
      break;
    }
  }
}

void FUN_08207298(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCZajiWork* work = &npc->work.zaji;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 8, 2, 1, 4);
    npc->work.zaji.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void Zaji_UpdateSleep(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCZajiWork* work = &npc->work.zaji;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 9, 1, 1, 4);
    npc->work.zaji.step = 0;
    work->timer = 0;
  }
  SET_FLAGS(npc->flags, NPCFLAG_TALKABLE);
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if (npc->fn(npc) == 1) {
    return;
  }

  if (++work->timer >= 70) {
    work->timer = 0;
    npc->emote = Emote_Show(npc->emote, &npc->mover, EMOTE_2, 0, NULL, 0, 250, 250);
  }
  if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_0820738c(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 10, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

// clang-format off
static void (*const sZajiUpdates[21])(NPCManager*, NPC*, s32) = {
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
    FUN_08207120,
    FUN_08207170,
    FUN_082071c0,
    FUN_08207210,
    FUN_08207298,
    Zaji_UpdateSleep,
    FUN_0820738c,
};  // 0x085AEA1C
// clang-format on

u8 Zaji_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 21) {
    return 0;
  }

  fn = sZajiUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Zaji_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void FUN_0820744c(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08207474(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082074a8(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082074d0(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 17;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082074f8(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 18;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Zaji_StateSleep(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 19;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08207550(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 20;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Zaji_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sZajiStates[23])(NPCManager*, NPC*) = {
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
      FUN_0820744c,
      FUN_08207474,
      FUN_082074a8,
      FUN_082074d0,
      FUN_082074f8,
      Zaji_StateSleep,
      FUN_08207550,
  };  // 0x085AEA70
  // clang-format on
  sZajiStates[npc->state](p, npc);
}

void Zaji_UpdateState(NPCManager* p, NPC* npc) { Zaji_DispatchState(p, npc); }

s32 Zaji_RunState(NPCManager* p, NPC* npc) {
  Zaji_UpdateState(p, npc);
  return 0;
}

void Zaji_HandleMsgs(NPC* npc) {
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
      case 11: {
        NPC_StartState(npc, 16);
        break;
      }
      case 12: {
        NPC_StartState(npc, 17);
        break;
      }
      case 15: {
        NPC_StartState(npc, 18);
        break;
      }
      case 16: {
        NPC_StartState(npc, 19);
        break;
      }
      case 17: {
        NPC_StartState(npc, 20);
        break;
      }
      case 23: {
        NPC_StartState(npc, 21);
        break;
      }
      case 24: {
        NPC_StartState(npc, 22);
        break;
      }
      case 41: {
        npc->mover.pos.x = msg->args[0];
        npc->mover.pos.y = msg->args[1];
        npc->mover.pos.z = msg->args[2];
        break;
      }
    }
  }
}

s32 Zaji_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Zaji_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Zaji_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Zaji_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xF33F, HashName("ＮＰＣザジ"), ザジの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnZajiNPC(void) {
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
  kind = VM_GetNamedArgValue('k', 3);
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
  if (NPC_InitSprite(npc, 2, SPR_ZAJI, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 350, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Zaji_SelectUpdate);
  NPC_SetCb(npc, 0, Zaji_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Zaji_RunState);
  NPC_SetCb(npc, 2, Zaji_RunUpdate);
  NPC_SetCb(npc, 3, Zaji_UpdateVisibility);
  NPC_SetOnDestroy(npc, Zaji_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_ZAJI, 0);
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
    case 3: {
      NPC_StartState(npc, 21);
      NPC_SetUpdate(npc, Zaji_UpdateSleep, 19);
      break;
    }
  }
}
