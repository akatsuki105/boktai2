#include "global.h"
#include "msgbus.h"
#include "npc.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }
static inline s32 GetAngleTo(WorldPos* pos, WorldPos* target) { return ArcTan2_8(target->x - pos->x, target->z - pos->z); }

// 2点の xz 平面上の距離の2乗
static inline s32 DistSqTo(WorldPos* pos, WorldPos* target) {
  s32 dx = target->x - pos->x;
  s32 dz = target->z - pos->z;

  return dx * dx + dz * dz;
}

struct Entity0821b7fc* Entity0821b7fc_Create(Vec3* pos);
void Entity0821b7fc_Remove(struct Entity0821b7fc* p);
bool32 Entity0821b7fc_IsFinished(struct Entity0821b7fc* p);

COMMON_DATA NPC* gOtenkoNPC = NULL;  // 0x03002C90, Cmd_SpawnOtenkoNPC が作ったおてんこの NPC, 破棄時に NULL

static inline void NPC_SetUnk1F0(NPC* npc, s32 a, s32 b) {
  npc->pathSpeed = a;
  npc->unk_1f2 = b;
  npc->unk_1f4 = a;
  npc->unk_1f8 = b;
}

// 向きを変え, 8 方向と 4 方向の向きも合わせる
static inline void NPC_SetAngle(NPC* npc, u32 angle) {
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  npc->targetAngle = npc->mover.angle;
}

void Otenko_StateAppear(NPCManager* p, NPC* npc) {
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
}

void Otenko_StateDisappear(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 0);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Otenko_StateFollowPlayer(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->unk_227 = npc->state;
  if (npc->updateDone) {
    NPC_SetState(npc, 10);
    npc->stateEntered = 1;
  }
}

void Otenko_StateBlackHole(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 17;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 0);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Otenko_StatePlttBlend(NPCManager* p, NPC* npc) {
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

void Otenko_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sOtenkoStates[21])(NPCManager*, NPC*) = {
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
      Otenko_StateAppear,
      Otenko_StateDisappear,
      Otenko_StateFollowPlayer,
      Otenko_StateBlackHole,
      Otenko_StatePlttBlend,
  };  // 0x085AE83C
  // clang-format on
  sOtenkoStates[npc->state](p, npc);
}

void Otenko_UpdateState(NPCManager* p, NPC* npc) { Otenko_DispatchState(p, npc); }

void Otenko_UpdateWalkToTarget(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 1, 1, 0, 4);
  }
  if (npc->fn(npc) != 1) {
    if (DistSqTo(&npc->mover.pos, &npc->work.walk.target) <= 1024) {
      npc->mover.pos = npc->work.walk.target;
      npc->updateDone = 1;
    } else {
      Vec3 v;
      u8 angle;

      npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
      Vec3_SetPolar(&v, npc->targetAngle, 16);
      Vec3_Add(&npc->mover.pos, &v);
      angle = npc->targetAngle;
      npc->mover.angle = angle;
      npc->dir8 = Angle_ToDir8(angle);
      npc->dir4 = Angle_ToDir4(angle);
      NPC_PlayAnim(npc, 1, 1, 0, 1);
    }
  }
}

void Otenko_UpdateTurn(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 2, 1, 0, 4);
  }
  if (npc->fn(npc) != 1) {
    u8 angle = npc->targetAngle;

    npc->mover.angle = angle;
    npc->dir8 = Angle_ToDir8(angle);
    npc->dir4 = Angle_ToDir4(angle);
    NPC_PlayAnim(npc, 2, 2, 0, 0);
    if (npc->mover.angle == npc->targetAngle) {
      npc->updateDone = 1;
    }
  }
}

// 残差: 最初の 0 の定数を置く位置と, 後半の 1 / 0 の定数のレジスタ (原典 r4 / r6, こちら r6 / r7), unk_0c の判定の 1 をこちらは呼び出しの前に作って r4 に持つ
// 試済: entered の代入位置, TEST_FLAGS / CLEAR_FLAGS, == 0 の判定, SET_FLAGS と |= の書き分け
NON_MATCH void Otenko_UpdateAppear(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  NPCOtenkoWork* work = &npc->work.otenko;
  bool32 entered = FALSE;

  if (npc->updateEntered) {
    u8 angle;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    angle = npc->targetAngle;
    npc->mover.angle = angle;
    npc->dir8 = Angle_ToDir8(angle);
    npc->dir4 = Angle_ToDir4(angle);
    NPC_PlayAnim(npc, 4, 2, 0, 4);
    entered = TRUE;
    SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
    work->bobY = 0;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  if (entered) {
    PlaySound_082406e0(SE_INFO);
  }
  npc->flags |= 1;
  if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
    NPC_PlayAnim(npc, 0, 1, 0, 4);
    NPC_SetUpdate(npc, NPC_UpdateIdle, 2);
    if (!TEST_FLAGS(npc->unk_0c, 1)) {
      PlaySound_082406e0(VO_OTENKO_OTNK);
      CLEAR_FLAGS(npc->unk_0c, 1);
    }
  }
#else
  INCFUNC("asm/func/Otenko_UpdateAppear.inc");
#endif
}

void Otenko_UpdateDisappear(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 5, 2, 0, 4);
    PlaySound_082406e0(SE_UNK_287);
  }
  npc->flags |= 1;
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
    NPC_SetUpdate(npc, NPC_UpdateHidden, 1);
  }
}

// 下書き (326/333命令): 流れは一致, 原典はスタックが 0x18 で fn を呼ぶ前に sp+0x14 へ読まれない u16 の 0 を書く (構造体のローカルの一部らしい), 距離の判定と向きの更新のレジスタ割り当ても違う
// 未: sp+0x14 の正体, 遠いときの位置の書き方 (mover->pos.x と pos->y / z の混在)
NON_MATCH void Otenko_UpdateFollowPlayer(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Player* player = p->player;
  Mover* mover = &npc->mover;
  WorldPos* pos = &npc->mover.pos;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 0, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_NO_GROUND | NPCFLAG_FOLLOW_PLAYER_Y);
  if (npc->fn(npc) == 1) {
    return;
  }

  if (player != NULL) {
    u32 playerAngle = player->mover.angle;
    WorldPos* playerPos = &player->mover.pos;
    s32 angle = ArcTan2_8(playerPos->x - mover->pos.x, playerPos->z - pos->z);
    s32 dx = playerPos->x - mover->pos.x;
    s32 dz = playerPos->z - pos->z;
    s32 distSq = dx * dx + dz * dz;

    if (distSq > 768 * 768) {
      Vec3 v;

      npc->mover.angle = angle;
      npc->dir8 = Angle_ToDir8(angle);
      npc->dir4 = Angle_ToDir4(angle);
      Vec3_SetPolar(&v, mover->angle, -768);
      mover->pos.x = v.x + playerPos->x;
      pos->y = v.y + playerPos->y;
      pos->z = v.z + playerPos->z;
    } else if (distSq > 0xFFFF) {
      npc->mover.angle = angle;
      npc->dir8 = Angle_ToDir8(angle);
      npc->dir4 = Angle_ToDir4(angle);
      Vec3_SetPolar(&npc->mover.delta, mover->angle, 24);
    } else {
      npc->mover.angle = angle;
      npc->dir8 = Angle_ToDir8(angle);
      npc->dir4 = Angle_ToDir4(angle);
      if (abs(mover->pos.y - p->playerPos->y) <= 0xFF) {
        s8 toPlayer = ArcTan2_8(pos->x - p->playerPos->x, pos->z - p->playerPos->z);
        s8 facing = playerAngle - toPlayer;
        s8 back = playerAngle - (npc->mover.angle + 0x80);

        if (abs(facing) <= 63 && abs(back) <= 31) {
          SET_FLAGS(npc->flags, NPCFLAG_TALKABLE);
        }
      }
    }
  }
  NPC_PlayAnim(npc, 0, 1, 0, 1);
#else
  INCFUNC("asm/func/Otenko_UpdateFollowPlayer.inc");
#endif
}

// 残差: BlendPltt の引数で, 原典はパレット 280 / 279 の番地を先に作り plttBuf の番地を後に作る (命令数は一致)
// 試済: &pos を先に取る形 (pos.y += 265 の strh は一致), pltt を書く inline (0xDC + 0xC の格納は一致), 色を変える部分を inline にまとめる, elapsed - 80 のローカル
NON_MATCH void Otenko_UpdateBlackHole(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  NPCOtenkoWork* work = &npc->work.otenko;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    NPC_PlayAnim(npc, 7, 1, 0, 1);
  }
  npc->flags |= 1;
  if (elapsed == 30) {
    Vec3 pos;
    Vec3* dst = &pos;

    *dst = npc->mover.pos;
    dst->y += 265;
    npc->work.otenko.blackHole = Entity0821b7fc_Create(dst);
  }
  if (elapsed > 30) {
    if ((elapsed & 7) >= 7 - (elapsed >> 3)) {
      SET_FLAGS(npc->flags, NPCFLAG_UNK_8 | NPCFLAG_HIDE_SHADOW);
    }
    if (elapsed > 85) {
      SET_FLAGS(npc->flags, NPCFLAG_UNK_8 | NPCFLAG_HIDE_SHADOW);
    }
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  if (elapsed == 0) {
    CpuCopy32(&gObjPlttData[280 * 16], npc->plttBuf, sizeof(npc->plttBuf));
  } else {
    u32 t = elapsed - 80;

    if (t < 32) {
      BlendPltt(npc->plttBuf, &gObjPlttData[280 * 16], &gObjPlttData[279 * 16], t, 5);
    } else if (elapsed == 112) {
      CpuCopy32(&gObjPlttData[279 * 16], npc->plttBuf, sizeof(npc->plttBuf));
    }
  }
  npc->sprite.u.aux.gfx.pltt = npc->plttBuf;
  if (Entity0821b7fc_IsFinished(work->blackHole)) {
    Entity0821b7fc_Remove(work->blackHole);
    npc->updateDone = 1;
  }
#else
  INCFUNC("asm/func/Otenko_UpdateBlackHole.inc");
#endif
}

// 残差: elapsed と elapsed - 80 の r5 / r6 が入れ替わる
// 試済: AuxSpriteGfx* を受けて pltt を書く inline に &npc->sprite.u.aux.gfx を渡すと pltt の格納 (0xDC + 0xC) は一致, elapsed - 80 のローカル (ブロック内 / 先頭), >= && < の範囲判定
NON_MATCH void Otenko_UpdatePlttBlend(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    CpuCopy32(&gObjPlttData[280 * 16], npc->plttBuf, sizeof(npc->plttBuf));
    NPC_PlayAnim(npc, 7, 1, 0, 1);
  }
  if (npc->fn(npc) == 1) {
    npc->sprite.u.aux.gfx.pltt = &gObjPlttData[279 * 16];
    return;
  }

  if (elapsed == 0) {
    CpuCopy32(&gObjPlttData[280 * 16], npc->plttBuf, sizeof(npc->plttBuf));
  } else if ((u32)(elapsed - 80) < 32) {
    BlendPltt(npc->plttBuf, &gObjPlttData[280 * 16], &gObjPlttData[279 * 16], elapsed - 80, 5);
  } else if (elapsed == 112) {
    CpuCopy32(&gObjPlttData[279 * 16], npc->plttBuf, sizeof(npc->plttBuf));
  }
  npc->sprite.u.aux.gfx.pltt = npc->plttBuf;
#else
  INCFUNC("asm/func/Otenko_UpdatePlttBlend.inc");
#endif
}

// updateRequest に対応する更新関数を割り当てて動き出せる状態にする
u8 Otenko_SelectUpdate(NPC* npc) {
  // clang-format off
  static void (*const sOtenkoUpdates[19])(NPCManager*, NPC*, s32) = {
      NULL,
      NPC_UpdateHidden,
      NPC_UpdateIdle,
      Otenko_UpdateWalkToTarget,
      Otenko_UpdateTurn,
      NPC_UpdateDropIn,
      NPC_UpdateRiseOut,
      FUN_08042868,
      NPC_UpdateWalkPath,
      NPC_UpdateFacePlayer,
      FUN_08042cf0,
      FUN_08042d50,
      FUN_08042f34,
      NPC_UpdateNavToPathStart,
      Otenko_UpdateAppear,
      Otenko_UpdateDisappear,
      Otenko_UpdateFollowPlayer,
      Otenko_UpdateBlackHole,
      Otenko_UpdatePlttBlend,
  };  // 0x085AE890
  // clang-format on

  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 19) {  // 本来は >= 19 と書くべきものと思われる...
    return 0;
  }

  fn = sOtenkoUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  return 1;
}

void Otenko_HandleMsgs(NPC* npc) {
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
      case 6: {
        u8 angle;

        npc->targetAngle = Angle_FromDir8((u8)msg->args[0]);
        if (msg->unk_4 == 1) {
          npc->unk_0c |= 1;
        }
        angle = npc->targetAngle;
        npc->mover.angle = angle;
        npc->dir8 = Angle_ToDir8(angle);
        npc->dir4 = Angle_ToDir4(angle);
        NPC_StartState(npc, 16);
        break;
      }
      case 7: {
        NPC_StartState(npc, 17);
        break;
      }
      case 8: {
        NPC_StartState(npc, 19);
        break;
      }
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
        break;
      }
      case 9: {
        NPC_StartState(npc, 20);
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

// 残差: flags と playerPos の r1 / r2 の割り当てが逆で, それに続いて sprite.pos の番地の定数から cmdIdx の番地を subs で作る1命令が出ない (88 対 87)
// 試済: SET_FLAGS / |= の書き分け, & 2 の直書き, playerPos のローカル, コマ番号の switch
NON_MATCH s32 Otenko_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  NPCOtenkoWork* work = &npc->work.otenko;

  Otenko_HandleMsgs(npc);
  if (TEST_FLAGS(npc->flags, NPCFLAG_FOLLOW_PLAYER_Y) && p->playerPos != NULL) {
    SET_FLAGS(npc->flags, NPCFLAG_NO_GROUND);
    npc->mover.pos.y = p->playerPos->y;
  }
  NPC_UpdateMotion(p, npc);
  npc->sprite.pos->y += 160;
  if (!TEST_FLAGS(npc->flags, 1)) {
    if ((work->bobTimer & 3) == 0) {
      u32 frame = npc->sprite.u.aux.anim.cmdIdx & 3;

      if (frame == 0 || frame == 3) {
        work->bobY -= 8;
      } else {
        work->bobY += 8;
      }
      if (work->bobY > 64) {
        work->bobY = 64;
      } else if (work->bobY < -64) {
        work->bobY = -64;
      }
    }
    work->bobTimer++;
    npc->sprite.pos->y += work->bobY;
  }
  npc->updateRequest = 0;
  return 0;
#else
  INCFUNC("asm/func/Otenko_HandleMsgsAndMove.inc");
#endif
}

s32 Otenko_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPCOtenkoWork* work = &npc->work.otenko;

  NPC_UpdateVisibility(p, npc);
  if (work->unk_08 == 0 && npc->updateID <= 16) {
    SET_FLAGS(npc->flags, NPCFLAG_NO_GROUND | NPCFLAG_FOLLOW_PLAYER_Y);
  }
  return 0;
}

s32 Otenko_OnDestroy(NPCManager* p, NPC* npc) {
  s32 ret = MsgQueue_Unregister(&npc->mq);

  gOtenkoNPC = NULL;
  return ret;
}

s32 Otenko_RunState(NPCManager* p, NPC* npc) {
  Otenko_UpdateState(p, npc);
  return 0;
}

s32 Otenko_RunUpdate(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
  }

  return 0;
}

// 0xBB34, HashName("おてんこ"), おてんこの NPC を作って NPCManager に繋ぐ
void Cmd_SpawnOtenkoNPC(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  NPC* npc;
  NPCOtenkoWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 13);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  gOtenkoNPC = npc;
  if (NPC_InitMover(npc, id, &pos, angle) < 0) {
    return;
  }
  if (NPC_InitSprite(npc, 1, SPR_OTENKO_00, ANIM_OTENKO, 0) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.563), 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Otenko_SelectUpdate);
  NPC_SetCb(npc, 0, Otenko_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Otenko_RunState);
  NPC_SetCb(npc, 2, Otenko_RunUpdate);
  NPC_SetCb(npc, 3, Otenko_UpdateVisibility);
  NPC_SetOnDestroy(npc, Otenko_OnDestroy);
  NPC_LookupCharaTables(p, npc, SPR_OTENKO_00, 0);
  NPCManager_LinkNPC(p, npc);
  NPC_ReadConfigArgs(p, npc);
  work = &npc->work.otenko;
  npc->unk_0c = 0;
  work->unk_08 = 0;

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
      NPC_StartState(npc, 18);
      NPC_SetUpdate(npc, Otenko_UpdateFollowPlayer, 16);
      break;
    }
  }

  FUN_0804135c(npc, 0, 0, 0, 0, 0);
  NPC_SetUnk1F0(npc, 16, 20);
  npc->unk_1fc = 256;
  npc->unk_200 = 400;
}

// 0x8918, HashName("おてんこ出る"), おてんこ ('.n' があればその NPC) を状態 16 に移し, '.p' で位置, '.d' で向きを入れる, '.w' が正ならプレイヤーの方を向かせる
void Cmd_ShowOtenkoNPC(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  NPC_StartState(npc, 16);
  NPC_SetUpdate(npc, Otenko_UpdateAppear, 14);

  if (VM_SeekToNamedArg('p')) {
    npc->mover.pos.x = VM_GetValue();
    npc->mover.pos.y = VM_GetValue();
    npc->mover.pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('d')) {
    NPC_SetAngle(npc, VM_GetValue());
  }
  if (VM_GetNamedArgValue('w', 0) > 0) {
    Player* player = gPlayerPtr[0];
    WorldPos* pos = &npc->mover.pos;

    NPC_SetAngle(npc, ArcTan2_8(player->mover.pos.x - pos->x, player->mover.pos.z - pos->z));
  }
}

// 0x6CBE, HashName("おてんこ消える"), おてんこ ('.n' があればその NPC) を状態 17 に移して隠す
void Cmd_HideOtenkoNPC(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  NPC_StartState(npc, 17);
  NPC_SetUpdate(npc, Otenko_UpdateDisappear, 15);
  SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_HIDDEN);
  NPC_HideShadow(npc);
}

// 0x4EBF, おてんこ ('.n' があればその NPC) を状態 18 に移す
void Cmd_4EBF(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  npc->unk_217 = 1;
  NPC_StartState(npc, 18);
  NPC_SetUpdate(npc, Otenko_UpdateFollowPlayer, 16);
}

// 0x11D9
void Cmd_11D9(void) {
  if (gOtenkoNPC != NULL) {
    NPCOtenkoWork* work = &gOtenkoNPC->work.otenko;

    work->unk_08 = 1;
  }
}
