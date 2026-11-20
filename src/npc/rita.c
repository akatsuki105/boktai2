#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "msgbus_inline.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

void FUN_082066c8(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082066f0(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08206718(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 17;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0820673c(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 18;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08206764(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 19;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0820678c(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 20;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 残差: work の番地 (原典は npc の写しから r2 に作る) と, 距離の判定の早期 FALSE が外側の 0/1 へ畳まれる (npc.c の FUN_08043cf4 と同じ壁)
// 試済: IsNear + Rita_IsPlayerNear の inline 2段 (外側の 0/1 は合う), && 1式, bool8 返し, work の宣言位置3通り
NON_MATCH void FUN_082067c0(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->stateEntered) {
    NPCRitaWork* work;

    npc->stateEntered = 0;
    npc->updateDone = 0;
    work = &npc->work.rita;
    if (work->unk_04 == 1) {
      npc->updateRequest = 17;
      work->unk_04 = 0;
    } else {
      npc->updateRequest = 15;
    }
    npc->timer = 0;
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    if (npc->updateID != 16) {
      npc->updateRequest = 16;
    } else if (npc->updateDone == 1) {
      npc->unk_227 = npc->state;
      NPC_SetState(npc, 10);
      npc->stateEntered = 1;
    }
    return;
  }

  if (npc->updateID == 16) {
    npc->updateRequest = 15;
  }
  npc->timer++;
#else
  INCFUNC("asm/func/FUN_082067c0.inc");
#endif
}

void Rita_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sRitaStates[23])(NPCManager*, NPC*) = {
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
      FUN_082066c8,
      FUN_082066f0,
      FUN_08206718,
      FUN_0820673c,
      FUN_08206764,
      FUN_0820678c,
      FUN_082067c0,
  };  // 0x085AE96C
  // clang-format on
  sRitaStates[npc->state](p, npc);
}

void Rita_UpdateState(NPCManager* p, NPC* npc) { Rita_DispatchState(p, npc); }

s32 Rita_RunState(NPCManager* p, NPC* npc) {
  Rita_UpdateState(p, npc);
  return 0;
}

void FUN_082068c8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08206918(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08206968(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 2, 1, 6);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_082069b8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 7, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08206a08(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCRitaWork* work = &npc->work.rita;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 8, 2, 1, 4);
    npc->work.rita.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    if (npc->work.rita.step == 0) {
      npc->work.rita.step++;
      NPC_PlayAnim(npc, 9, 2, 1, 4);
    } else {
      npc->updateDone = 1;
    }
  }
}

void FUN_08206a7c(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCRitaWork* work = &npc->work.rita;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 10, 2, 1, 4);
    npc->work.rita.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08206ad4(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 6, 2, 1, 4);
  }
  npc->fn(npc);
}

// clang-format off
static void (*const sRitaUpdates[21])(NPCManager*, NPC*, s32) = {
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
    FUN_082068c8,
    FUN_08206918,
    FUN_08206968,
    FUN_08206ad4,
    FUN_082069b8,
    FUN_08206a08,
    FUN_08206a7c,
};  // 0x085AE9C8
// clang-format on

u8 Rita_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 21) {
    return 0;
  }

  fn = sRitaUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Rita_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void Rita_HandleMsgs(NPC* npc) {
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
      case 13: {
        NPC_StartState(npc, 17);
        break;
      }
      case 14: {
        NPC_StartState(npc, 18);
        break;
      }
      case 15: {
        NPC_StartState(npc, 19);
        break;
      }
      case 18: {
        NPC_StartState(npc, 20);
        break;
      }
      case 19: {
        NPC_StartState(npc, 21);
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

s32 Rita_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Rita_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Rita_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Rita_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xC347, HashName("ＮＰＣリタ"), リタの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnRitaNPC(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  NPC* npc;
  NPCRitaWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 2);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = SPR_RITA;
  flags = 0;

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (NPC_InitMover(npc, id, &pos, angle) < 0) {
    return;
  }
  if (NPC_InitSprite(npc, 2, spriteID, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.37), 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Rita_SelectUpdate);
  NPC_SetCb(npc, 0, Rita_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Rita_RunState);
  NPC_SetCb(npc, 2, Rita_RunUpdate);
  NPC_SetCb(npc, 3, Rita_UpdateVisibility);
  NPC_SetOnDestroy(npc, Rita_OnDestroy);
  NPC_LookupCharaTables(p, npc, spriteID, 0);
  NPCManager_LinkNPC(p, npc);
  NPC_ReadConfigArgs(p, npc);
  work = &npc->work.rita;
  work->unk_04 = 0;

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
      npc->unk_217 = 1;
      work->unk_04 = 1;
      NPC_StartState(npc, 22);
      NPC_SetUpdate(npc, FUN_08042868, 7);
      break;
    }
    case 4: {
      NPC_StartState(npc, 18);
      NPC_SetUpdate(npc, FUN_08206ad4, 17);
      break;
    }
  }
}

// 0x8894, '.n' の NPC (リタ) を状態 22 に移す
void Cmd_8894(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;
  NPCRitaWork* work;

  if (p == NULL) {
    return;
  }

  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return;
  }

  work = &npc->work.rita;
  npc->unk_217 = 1;
  NPC_StartState(npc, 22);
  NPC_SetUpdate(npc, FUN_08042868, 7);
  work->unk_04 = 1;
}
