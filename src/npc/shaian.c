#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "msgbus_inline.h"
#include "npc.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

void Entity081f7de4_Spawn(Vec3* pos, u32 rotation);
void Entity081f7de4_RemoveAll(void);

void FUN_08205efc(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void FUN_08205f38(NPCManager* p, NPC* npc) {
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

  npc->timer++;
}

void ShaianNPC_StateSpin(NPCManager* p, NPC* npc) {
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

  npc->timer++;
}

void ShaianNPC_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sShaianNPCStates[19])(NPCManager*, NPC*) = {
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
      FUN_08205efc,
      FUN_08205f38,
      ShaianNPC_StateSpin,
  };  // 0x085AE8DC
  // clang-format on
  sShaianNPCStates[npc->state](p, npc);
}

void ShaianNPC_UpdateState(NPCManager* p, NPC* npc) { ShaianNPC_DispatchState(p, npc); }

s32 ShaianNPC_RunState(NPCManager* p, NPC* npc) {
  ShaianNPC_UpdateState(p, npc);
  return 0;
}

void FUN_08205fe0(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    if (npc->dir4 <= 1) {
      npc->dir4 = 2;
    }
    NPC_PlayAnim(npc, 6, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

void FUN_0820602c(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    if (npc->dir4 <= 1) {
      npc->dir4 = 2;
    }
    NPC_PlayAnim(npc, 7, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if (elapsed > 8) {
    npc->updateDone = 1;
  }
  npc->fn(npc);
}

void ShaianNPC_UpdateSpin(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    Vec3 pos;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 8, 1, 0, 4);
    pos = npc->mover.pos;
    pos.y += 280;
    Entity081f7de4_Spawn(&pos, 0);
    Entity081f7de4_Spawn(&pos, 128);
    PlaySound_082406e0(SONG_975);
    PlaySound_082406e0(VO_SHAIAN_ATK3);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if (npc->fn(npc) == 1) {
    Entity081f7de4_RemoveAll();
  }
}

static void (*const sShaianNPCUpdates[17])(NPCManager*, NPC*, s32) = {
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
    FUN_08205fe0,
    FUN_0820602c,
    ShaianNPC_UpdateSpin,
};  // 0x085AE928

u8 ShaianNPC_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 17) {
    return 0;
  }

  fn = sShaianNPCUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 ShaianNPC_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void ShaianNPC_HandleMsgs(NPC* npc) {
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
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
        break;
      }
      case 34: {
        NPC_StartState(npc, 16);
        break;
      }
      case 35: {
        NPC_StartState(npc, 17);
        break;
      }
      case 36: {
        NPC_StartState(npc, 18);
        break;
      }
    }
  }
}

void ShaianNPC_UpdateShadowPos(NPC* npc) {
  s32 angle = (npc->mover.angle + 32) & 0xFF;

  npc->shadowPos = npc->mover.pos;
  if ((npc->updateID == 2 || npc->updateID == 9) && npc->dir8 == 4) {
    npc->shadowPos.x -= 12;
    npc->shadowPos.z -= 16;
    return;
  }

  switch (angle >> 6) {
    case 0: {
      npc->shadowPos.z -= 32;
      break;
    }
    case 1: {
      npc->shadowPos.x -= 32;
      break;
    }
    case 2: {
      npc->shadowPos.x -= 24;
      npc->shadowPos.z -= 6;
      break;
    }
    case 3: {
      npc->shadowPos.x -= 6;
      npc->shadowPos.z -= 32;
      break;
    }
  }
}

s32 ShaianNPC_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  ShaianNPC_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 ShaianNPC_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  ShaianNPC_UpdateShadowPos(npc);
  return 0;
}

s32 ShaianNPC_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x3004, HashName("ＮＰＣシャイアン"), シャイアンの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnShaianNPC(void) {
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
  kind = VM_GetNamedArgValue('k', 1);
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
  if (NPC_InitSprite(npc, 2, SPR_SHAIAN, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.875), 0);
  npc->shadowPos = npc->mover.pos;
  NPC_InitShadow(npc, &npc->shadowPos, 2, 7, 48);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, ShaianNPC_SelectUpdate);
  NPC_SetCb(npc, 0, ShaianNPC_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, ShaianNPC_RunState);
  NPC_SetCb(npc, 2, ShaianNPC_RunUpdate);
  NPC_SetCb(npc, 3, ShaianNPC_UpdateVisibility);
  NPC_SetOnDestroy(npc, ShaianNPC_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_SHAIAN, 0);
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
