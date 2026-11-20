#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

void Rockman_StateShrinkAway(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 14;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

void Rockman_DispatchState(NPCManager* p, NPC* npc) {
  static void (*const sRockmanStates[17])(NPCManager*, NPC*) = {
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
      Rockman_StateShrinkAway,
  };  // 0x085AEF34
  sRockmanStates[npc->state](p, npc);
}

void Rockman_UpdateState(NPCManager* p, NPC* npc) { Rockman_DispatchState(p, npc); }

s32 Rockman_RunState(NPCManager* p, NPC* npc) {
  Rockman_UpdateState(p, npc);
  return 0;
}

// 1フレームおきに姿を隠して点滅させながら立つ
void Rockman_UpdateIdle(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 0, 1, 0, 4);
  }
  if (gFrameCounter & 1) {
    SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

void Rockman_EnableAffine(NPC* npc) {
  SpriteHolder* sprite = &npc->sprite;

  SpriteHolder_SetFlags(sprite, SPRFLAG_AFFINE);
  SpriteHolder_SetAffine(sprite, 64, 64, 0);
}

void Rockman_DisableAffine(NPC* npc) {
  SpriteHolder* sprite = &npc->sprite;

  SpriteHolder_ClearFlags(sprite, SPRFLAG_AFFINE);
  SpriteHolder_SetAffine(sprite, 64, 64, 0);
}

// 点滅しながら毎フレーム縮んで work.walk.target へ walkSpeed で向かい, 縮みきったら隠れる update に移る
void Rockman_UpdateShrinkAway(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 0, 2, 0, 4);
    Rockman_EnableAffine(npc);
  }
  if (gFrameCounter & 1) {
    SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
  }
  if (npc->sprite.u.main.spr.scaleX > 1) {
    npc->sprite.u.main.spr.scaleY = --npc->sprite.u.main.spr.scaleX;
  } else {
    NPC_SetUpdate(npc, NPC_UpdateHidden, 1);
  }
  if (npc->fn(npc) == 1) {
    Rockman_DisableAffine(npc);
    SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_HIDDEN);
  } else {
    Vec3 d;
    u32 distSq;

    Vec3_Diff(&d, &npc->work.walk.target, &npc->mover.pos);
    distSq = d.x * d.x + d.y * d.y + d.z * d.z;
    if (distSq <= npc->arriveDistSq) {
      npc->mover.pos = npc->work.walk.target;
    } else {
      s32 speed = npc->walkSpeed;
      u16 dist = Sqrt(distSq);

      if (dist != 0) {
        d.x = Div(d.x * speed, dist);
        d.y = Div(d.y * speed, dist);
        d.z = Div(d.z * speed, dist);
      }
      npc->mover.delta = d;
    }
  }
}

static void (*const sRockmanUpdates[15])(NPCManager*, NPC*, s32) = {
    NULL,
    NPC_UpdateHidden,
    Rockman_UpdateIdle,
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
    Rockman_UpdateShrinkAway,
};  // 0x085AEF78

u8 Rockman_SelectUpdate(NPC* npc) {
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 15) {
    return 0;
  }

  fn = sRockmanUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

s32 Rockman_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

void Rockman_HandleMsgs(NPC* npc) {
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
      case 40: {
        NPC_StartState(npc, 16);
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
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
    }
  }
}

s32 Rockman_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Rockman_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Rockman_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Rockman_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x56AD, HashName("ＮＰＣロックマン"), ロックマンの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnRockmanNPC(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);  // 0xB548, HashName("ロックマン")
  kind = VM_GetNamedArgValue('k', 15);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = SPR_MEGAMAN;
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

  Mover_SetUnk30(&npc->mover, 0, 400, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Rockman_SelectUpdate);
  NPC_SetCb(npc, 0, Rockman_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Rockman_RunState);
  NPC_SetCb(npc, 2, Rockman_RunUpdate);
  NPC_SetCb(npc, 3, Rockman_UpdateVisibility);
  NPC_SetOnDestroy(npc, Rockman_OnDestroy);
  NPC_LookupCharaTables(p, npc, spriteID, 0);
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
