#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vm.h"

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }
static inline s32 GetAngleTo(WorldPos* pos, WorldPos* target) { return ArcTan2_8(target->x - pos->x, target->z - pos->z); }

void Dainn_StateWarpIn(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 5;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Dainn_StateWarpOut(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 6;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 0);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Dainn_StateShake(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Dainn_StateMoveTo(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0820b678(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
    NPC_StartState(npc, 0);
  }
}

void Dainn_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sDainnStates[19])(NPCManager*, NPC*) = {
      FUN_0804355c,
      FUN_08043588,
      FUN_080435b4,
      FUN_080435f0,
      Dainn_StateWarpIn,
      Dainn_StateWarpOut,
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
      Dainn_StateShake,
      Dainn_StateMoveTo,
      FUN_0820b678,
  };  // 0x085AEEA4
  // clang-format on
  sDainnStates[npc->state](p, npc);
}

void Dainn_UpdateState(NPCManager* p, NPC* npc) { Dainn_DispatchState(p, npc); }

s32 Dainn_RunState(NPCManager* p, NPC* npc) {
  Dainn_UpdateState(p, npc);
  return 0;
}

// 残差: 揺れの計算で ~elapsed & 3 と 32 - elapsed を先に作り &delta をその後に作る並びだけが違う, 命令数は一致
// 試済: angle/amp ローカル, 式の直書き, npc->mover.delta 直書き, Vec3* delta の宣言位置2通り
NON_MATCH void Dainn_UpdateWarpIn(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Mover* mover = &npc->mover;
  NPCDainnWork* work = &npc->work.dainn;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 0, 2, 1, 4);
    npc->work.dainn.step = 0;
    work->timer = 0;
    work->endPos = mover->pos;
    PlaySound_082406e0(SE_WARP_808);
  }
  SET_FLAGS(npc->flags, NPCFLAG_HIDE_SHADOW);
  if (npc->fn(npc) == 1) {
    return;
  }

  mover->pos = work->endPos;
  if (elapsed >= 32) {
    npc->updateDone = 1;
  } else {
    s32 angle = (~elapsed & 3) << 6;
    s32 amp = (32 - elapsed) * 8;
    Vec3* delta = &npc->mover.delta;

    delta->x = FixToInt(12, COS(angle) * amp);
    delta->y = 0;
    delta->z = FixToInt(12, SIN(angle) * amp);
  }
#else
  INCFUNC("asm/func/Dainn_UpdateWarpIn.inc");
#endif
}

// 残差: elapsed & 3 を &delta より先に作る並びだけが違う, 命令数は一致
// 試済: angle/amp ローカル, 式の直書き, npc->mover.delta 直書き, Vec3* delta の宣言位置2通り
NON_MATCH void Dainn_UpdateWarpOut(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Mover* mover = &npc->mover;
  NPCDainnWork* work = &npc->work.dainn;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 0, 2, 1, 4);
    npc->work.dainn.step = 0;
    work->timer = 0;
    work->endPos = mover->pos;
    PlaySound_082406e0(SE_WARP_808);
  }
  SET_FLAGS(npc->flags, NPCFLAG_HIDE_SHADOW);
  if (npc->fn(npc) == 1) {
    return;
  }

  mover->pos = work->endPos;
  {
    Vec3* delta = &npc->mover.delta;
    s32 angle = (elapsed & 3) << 6;
    s32 amp = elapsed * 8;

    delta->x = FixToInt(12, COS(angle) * amp);
    delta->y = 0;
    delta->z = FixToInt(12, SIN(angle) * amp);
  }
  if (elapsed >= 32) {
    npc->updateDone = 1;
  }
#else
  INCFUNC("asm/func/Dainn_UpdateWarpOut.inc");
#endif
}

void Dainn_UpdateShake(NPCManager* p, NPC* npc, s32 elapsed) {
  Mover* mover = &npc->mover;
  NPCDainnWork* work = &npc->work.dainn;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 1, 4);
    work->startPos = mover->pos;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  mover->pos = work->startPos;
  mover->delta.x = (RandomNext() & 0x1F) - 16;
  mover->delta.z = (RandomNext() & 0x1F) - 16;
}

void Dainn_UpdateMoveTo(NPCManager* p, NPC* npc, s32 elapsed) {
  Mover* mover = &npc->mover;
  NPCDainnWork* work = &npc->work.dainn;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 4, 2, 1, 4);
    work->startPos = mover->pos;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  if (elapsed >= 64) {
    npc->updateDone = 1;
    mover->pos = work->endPos;
  } else {
    LerpVec3(&npc->mover.pos, &npc->work.dainn.startPos, &npc->work.dainn.endPos, elapsed, 6);
  }
  mover->delta.x = (RandomNext() & 0x1F) - 16;
  mover->delta.z = (RandomNext() & 0x1F) - 16;
}

void FUN_0820b9e8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 2, 1, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

static void (*const sDainnUpdates[17])(NPCManager*, NPC*, s32) = {
    NULL,
    NPC_UpdateHidden,
    NPC_UpdateIdle,
    NPC_UpdateWalkToTarget,
    NPC_UpdateTurn,
    Dainn_UpdateWarpIn,
    Dainn_UpdateWarpOut,
    FUN_08042868,
    NPC_UpdateWalkPath,
    NPC_UpdateFacePlayer,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    NPC_UpdateNavToPathStart,
    Dainn_UpdateShake,
    Dainn_UpdateMoveTo,
    FUN_0820b9e8,
};  // 0x085AEEF0

u8 Dainn_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 17) {
    return 0;
  }

  fn = sDainnUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Dainn_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void Dainn_HandleMsgs(NPC* npc) {
  MsgQueue* mq = &npc->mq;
  NPCDainnWork* work = &npc->work.dainn;
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
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
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
      case 30: {
        NPC_StartState(npc, 16);
        break;
      }
      case 31: {
        work->endPos.x = msg->args[0];
        work->endPos.y = msg->args[1];
        work->endPos.z = msg->args[2];
        NPC_StartState(npc, 17);
        break;
      }
      case 32: {
        NPC_StartState(npc, 18);
        break;
      }
    }
  }
}

s32 Dainn_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Dainn_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Dainn_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Dainn_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xD229, HashName("ＮＰＣダーイン"), ダーインの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnDainnNPC(void) {
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

  id = VM_GetNamedArgValue('n', 0);  // 0x7901, HashName("ダーイン")
  kind = VM_GetNamedArgValue('k', 12);
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
  if (NPC_InitSprite(npc, 2, SPR_DAINN, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 400, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 2, 7, 32);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Dainn_SelectUpdate);
  NPC_SetCb(npc, 0, Dainn_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Dainn_RunState);
  NPC_SetCb(npc, 2, Dainn_RunUpdate);
  NPC_SetCb(npc, 3, Dainn_UpdateVisibility);
  NPC_SetOnDestroy(npc, Dainn_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_DAINN, 0);
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
