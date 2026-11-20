#include "eff_scatter.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "msgbus_inline.h"
#include "npc.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

void Smith_StateHammer(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0820abec(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0820ac10(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// cmd 3 の歩き先へ, アニメ表の 3 番で歩かせる (update 17), 着いたら state 1 へ
void Smith_StateWalkTo(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 17;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void Smith_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sSmithStates[20])(NPCManager*, NPC*) = {
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
      Smith_StateHammer,
      FUN_0820abec,
      FUN_0820ac10,
      Smith_StateWalkTo,
  };  // 0x085AEE0C
  // clang-format on
  sSmithStates[npc->state](p, npc);
}

void Smith_UpdateState(NPCManager* p, NPC* npc) { Smith_DispatchState(p, npc); }

s32 Smith_RunState(NPCManager* p, NPC* npc) {
  Smith_UpdateState(p, npc);
  return 0;
}

// 槌を振り上げて打ち下ろすアニメを回し, 打ち下ろしの 4 フレーム目に火花を散らして鍛冶の音を鳴らす
void Smith_UpdateHammer(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCSmithWork* work = &npc->work.smith;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 1, 1, 4);
    npc->work.smith.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  switch (npc->work.smith.step) {
    case 0: {
      if (++work->timer >= 15) {
        NPC_PlayAnim(npc, 6, 2, 1, 4);
        npc->work.smith.step++;
        work->timer = 0;
      }
      break;
    }
    case 1: {
      if (++work->timer >= 30) {
        NPC_PlayAnim(npc, 7, 2, 1, 4);
        npc->work.smith.step++;
        work->timer = 0;
      }
      break;
    }
    case 2: {
      if (++work->timer >= 8) {
        NPC_PlayAnim(npc, 8, 2, 1, 4);
        npc->work.smith.step++;
        work->timer = 0;
      }
      break;
    }
    case 3: {
      if (work->timer == 4) {
        Vec3 pos;
        Vec3* dst = &pos;

        *dst = npc->mover.pos;
        dst->x += 180;
        ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 0, Random() & 0x3F, 10, 10, 5, 8, 8, 5);
        ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 64, Random() & 0x3F, 10, 10, 5, 8, 8, 5);
        ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 128, Random() & 0x3F, 10, 10, 5, 8, 8, 5);
        ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 192, Random() & 0x3F, 10, 10, 5, 8, 8, 5);
        ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 0, Random() & 0x3F, 8, 4, 4, 4, 14, 4);
        ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 64, Random() & 0x3F, 8, 4, 4, 4, 14, 4);
        ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 128, Random() & 0x3F, 8, 4, 4, 4, 14, 4);
        ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 192, Random() & 0x3F, 8, 4, 4, 4, 14, 4);
        PlaySound_082406e0(SE_FORGE_STRIKE_GOOD);
      }
      work->timer++;
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        NPC_PlayAnim(npc, 6, 2, 1, 4);
        npc->work.smith.step = 1;
        work->timer = 0;
      }
      break;
    }
  }
}

void FUN_0820afb0(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCSmithWork* work = &npc->work.smith;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 9, 2, 0, 4);
    npc->work.smith.step = 0;
    work->timer = 0;
  }
  npc->fn(npc);
}

void FUN_0820aff0(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCSmithWork* work = &npc->work.smith;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 10, 2, 0, 4);
    npc->work.smith.step = 0;
    work->timer = 0;
  }
  if (npc->fn(npc) != 1 && elapsed > 15) {
    npc->updateDone = 1;
  }
}

static void (*const sSmithUpdates[18])(NPCManager*, NPC*, s32) = {
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
    Smith_UpdateHammer,
    FUN_0820afb0,
    FUN_0820aff0,
    FUN_08043360,
};  // 0x085AEE5C

u8 Smith_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 18) {
    return 0;
  }

  fn = sSmithUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Smith_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void Smith_HandleMsgs(NPC* npc) {
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
      case 20: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
        NPC_StartState(npc, 2);
        break;
      }
      case 3: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
        NPC_StartState(npc, 19);
        break;
      }
      case 2: {
        npc->targetAngle = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 3);
        break;
      }
      case 33: {
        NPC_StartState(npc, 16);
        break;
      }
      case 22: {
        NPC_StartState(npc, 17);
        break;
      }
      case 24: {
        NPC_StartState(npc, 18);
        break;
      }
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
        break;
      }
    }
  }
}

s32 Smith_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Smith_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Smith_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Smith_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xCE28, スミス の NPC を作って NPCManager に繋ぐ
void Cmd_CE28(void) {
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

  // 0x6740, HashName("スミス"), ストーリーイベント用
  // 0x77E5, ハッシュ不明, 通常のスミス
  id = VM_GetNamedArgValue('n', 0);

  kind = VM_GetNamedArgValue('k', 11);
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
  if (NPC_InitSprite(npc, 2, SPR_SMITH_MARCELLO, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 450, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 2, 7, 32);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Smith_SelectUpdate);
  NPC_SetCb(npc, 0, Smith_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Smith_RunState);
  NPC_SetCb(npc, 2, Smith_RunUpdate);
  NPC_SetCb(npc, 3, Smith_UpdateVisibility);
  NPC_SetOnDestroy(npc, Smith_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_SMITH_MARCELLO, 0);
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
      NPC_StartState(npc, 17);
      NPC_SetUpdate(npc, FUN_0820afb0, 15);
      break;
    }
  }
}
