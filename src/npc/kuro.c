#include "emote.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "player.h"
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

// 向きを差し替えて, 8 方向と 4 方向の向きも合わせる
static inline void NPC_SetAngle(NPC* npc, u8 angle) {
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
}

// step に入った最初のフレームなら 1 を返して印を下ろす
static inline bool16 Kuro_ConsumeStepEntered(NPC* npc) {
  NPCKuroWork* work = &npc->work.kuro;
  bool16 entered = work->stepEntered;

  work->stepEntered = FALSE;
  return entered;
}

// step を差し替えて, 次のフレームを最初のフレームにする
static inline void Kuro_SetStep(NPC* npc, u16 step) {
  NPCKuroWork* work = &npc->work.kuro;

  work->step = step;
  work->stepEntered = TRUE;
  work->timer = 0;
}

void Kuro_StateRunTo(NPCManager* p, NPC* npc) {
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

void FUN_08208194(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 15;
  }

  if (npc->updateDone) {
    npc->updateRequest = 18;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082081c0(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 16;
  }

  if (npc->updateDone) {
    npc->updateRequest = 18;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082081ec(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 17;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Kuro_StateSleep(NPCManager* p, NPC* npc) {
  NPCKuroWork* work = &npc->work.kuro;

  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 18;
    MsgQueue_EndWait(&npc->mq, 1);
    work->sleepEmote = 1;
  }
}

void Kuro_StateFall(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 19;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Kuro_StateJump(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 20;
  }

  if (npc->updateDone) {
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Kuro_StatePulsePltt(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 21;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_082082c0(NPCManager* p, NPC* npc) {
  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 22;
  }

  if (npc->updateDone) {
    NPC_SetState(npc, 1);
    npc->stateEntered = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void Kuro_StateSleepTalkable(NPCManager* p, NPC* npc) {
  NPCKuroWork* work = &npc->work.kuro;

  if (npc->stateEntered) {
    npc->stateEntered = 0;
    npc->updateDone = 0;
    npc->updateRequest = 23;
    MsgQueue_EndWait(&npc->mq, 1);
    work->sleepEmote = 1;
  }
}

void Kuro_DispatchState(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const sKuroStates[26])(NPCManager*, NPC*) = {
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
      Kuro_StateRunTo,
      FUN_08208194,
      FUN_082081c0,
      FUN_082081ec,
      Kuro_StateSleep,
      Kuro_StateFall,
      Kuro_StateJump,
      Kuro_StatePulsePltt,
      FUN_082082c0,
      Kuro_StateSleepTalkable,
  };  // 0x085AEB5C
  // clang-format on
  sKuroStates[npc->state](p, npc);
}

void Kuro_UpdateState(NPCManager* p, NPC* npc) { Kuro_DispatchState(p, npc); }

s32 Kuro_RunState(NPCManager* p, NPC* npc) {
  Kuro_UpdateState(p, npc);
  return 0;
}

static rgb555 rgb555_ARRAY_03000228[16];  // 0x03000228

// パレット 655 と 656 を tick / frames の割合で混ぜて専用のバッファに書き, MainSprite をそちらへ向ける
// 残差: 定数 0x1F を r2 に置いて Div の前後で退避し b1 を r10 に置く割り当てだけが違う (原典 122 命令, こちら 124)
// 試済: u32 / u16 の色ローカル, Coffin_BlendPltt と同じ *from 直読み (成分の取り出しは一致), 宣言順, pltt の格納先の書き方
NON_MATCH void Kuro_BlendPltt(NPC* npc, s32 tick, s32 frames) {
#ifdef NONMATCHING_C
  rgb555* from = &gObjPlttData[655 * 16];
  rgb555* to = &gObjPlttData[656 * 16];
  rgb555* dst = rgb555_ARRAY_03000228;
  s32 i;
  s32 rest;
  s32 r1, g1, b1;

  ((SpriteHolderMain*)&npc->sprite.u)->spr.pltt = dst;
  tick *= 4;
  frames *= 4;
  rest = frames - tick;
  b1 = 0;
  g1 = 0;
  r1 = 0;
  for (i = 0; i < 16; i++) {
    s32 r0 = *from & 0x1F;
    s32 g0 = (*from >> 5) & 0x1F;
    s32 b0 = (*from >> 10) & 0x1F;
    s32 r, g, b;

    if (to != NULL) {
      r1 = *to & 0x1F;
      g1 = (*to >> 5) & 0x1F;
      b1 = (*to >> 10) & 0x1F;
      to++;
    }
    r = Div(r0 * rest + r1 * tick, frames) & 0x1F;
    g = Div(g0 * rest + g1 * tick, frames) & 0x1F;
    b = Div(b0 * rest + b1 * tick, frames) & 0x1F;
    *dst = r | (g << 5) | (b << 10);
    from++;
    dst++;
  }
#else
  INCFUNC("asm/func/Kuro_BlendPltt.inc");
#endif
}

void Kuro_PlayAnim(NPC* npc, s32 idx, s32 param_3, s32 param_4, s32 param_5) {
  if (idx < 10) {
    NPC_PlayAnim(npc, idx + npc->work.kuro.bandaged * 10, param_3, param_4, param_5);
  } else {
    NPC_PlayAnim(npc, idx, param_3, param_4, param_5);
  }
}

void Kuro_UpdateIdle(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    u8 angle;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    angle = npc->targetAngle;
    npc->mover.angle = angle;
    npc->dir8 = Angle_ToDir8(angle);
    npc->dir4 = Angle_ToDir4(angle);
    Kuro_PlayAnim(npc, 0, 1, 1, 4);
  }
  npc->fn(npc);
}

void Kuro_UpdateWalkToTarget(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 1, 1, 0, 4);
  }
  if (npc->fn(npc) != 1) {
    if (DistSqTo(&npc->mover.pos, &npc->work.walk.target) <= 100) {
      npc->mover.pos = npc->work.walk.target;
      npc->updateDone = 1;
    } else {
      Vec3_SetPolar(&npc->mover.delta, npc->mover.angle, 5);
      npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
      NPC_SetAngle(npc, npc->targetAngle);
      Kuro_PlayAnim(npc, 1, 1, 0, 5);
    }
  }
}

// 残差: (u8)diff > 127 が原典では lsrs #24 + cmp #0x7f のまま残るがこちらは符号の判定に畳まれる, 1 命令
// 試済: 値渡しの NPC_SetAngle(npc, u8 angle) inline (mover.angle を書いて引数から dir8/dir4 を作る) で r4/r5 の割り当てまで一致, Mover ローカル, 早期 return
NON_MATCH void Kuro_UpdateTurn(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  s32 diff;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 0, 1, 0, 4);
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  diff = npc->targetAngle - npc->mover.angle;
  if (abs(diff) <= 8) {
    npc->mover.angle += diff;
  } else if ((u8)diff > 127) {
    npc->mover.angle -= 8;
  } else {
    npc->mover.angle += 8;
  }
  npc->dir8 = Angle_ToDir8(npc->mover.angle);
  npc->dir4 = Angle_ToDir4(npc->mover.angle);
  Kuro_PlayAnim(npc, 0, 1, 0, 4);
  if (npc->mover.angle == npc->targetAngle) {
    npc->updateDone = 1;
  }
#else
  INCFUNC("asm/func/Kuro_UpdateTurn.inc");
#endif
}

void Kuro_UpdateRunToTarget(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 3, 1, 0, 4);
  }
  if (npc->fn(npc) != 1) {
    if (DistSqTo(&npc->mover.pos, &npc->work.walk.target) <= 100) {
      npc->mover.pos = npc->work.walk.target;
      npc->updateDone = 1;
    } else {
      Vec3_SetPolar(&npc->mover.delta, npc->mover.angle, 8);
      npc->targetAngle = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
      NPC_SetAngle(npc, npc->targetAngle);
      Kuro_PlayAnim(npc, 3, 1, 0, 5);
    }
  }
}

void FUN_08208808(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 5, 2, 0, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_08208858(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 5, 2, 0, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void FUN_082088a8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 6, 2, 0, 4);
  }
  if (npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
}

void Kuro_UpdateSleep(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCKuroWork* work = &npc->work.kuro;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 5, 2, 0, 4);
    npc->sprite.u.main.spr.animCmdIdx = 3;
    npc->sprite.u.main.spr.animCmdTimer = 0;
    MainSprite_AdvanceAnim(&npc->sprite.u.main.spr, &npc->sprite.u.main.gfx);
  }
  if (npc->fn(npc) != 1 && work->sleepEmote && elapsed > 0 && Mod(elapsed, 70) == 0) {
    work->emote = Emote_Show(work->emote, &npc->mover, EMOTE_2, 0, NULL, 0, 128, 0);
  }
}

void Kuro_UpdateFall(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCKuroWork* work = &npc->work.kuro;
  WorldPos* pos = &npc->mover.pos;

  if (npc->updateEntered) {
    u16 n;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    npc->targetAngle = 0x40;
    npc->mover.angle = 0x40;
    npc->dir8 = 5;
    npc->dir4 = 2;
    Kuro_PlayAnim(npc, 7, 2, 0, 4);
    work->velY = 0;
    work->startX = pos->x;
    work->startY = pos->y;
    work->startZ = pos->z;
    n = Sqrt((npc->work.walk.target.y - work->startY) * -200);
    if (Mod(n, 10) > 4) {
      work->frames = Div(n, 10) + 1;
    } else {
      work->frames = Div(n, 10);
    }
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  SET_FLAGS(npc->flags, NPCFLAG_NO_GROUND);
  switch (work->step) {
    case 0: {
      Kuro_ConsumeStepEntered(npc);
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        Kuro_SetStep(npc, 1);
      }
      break;
    }
    case 1: {
      s32 dx;
      s32 dz;

      if (Kuro_ConsumeStepEntered(npc)) {
        Kuro_PlayAnim(npc, 8, 2, 0, 4);
      }
      dx = npc->work.walk.target.x - work->startX;
      dz = npc->work.walk.target.z - work->startZ;
      pos->x = work->startX + Div(work->timer * dx, work->frames);
      pos->z = work->startZ + Div(work->timer * dz, work->frames);
      pos->y = work->timer * work->velY + work->startY + FixToInt(1, -work->timer * work->timer);
      if (work->timer >= work->frames) {
        pos->y = npc->work.walk.target.y;
        Kuro_SetStep(npc, 2);
      }
      break;
    }
    case 2: {
      if (Kuro_ConsumeStepEntered(npc)) {
        Kuro_PlayAnim(npc, 9, 2, 0, 4);
      }
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        npc->updateDone = 1;
      }
      break;
    }
  }
}

// 残差: 着いたときの step / stepEntered / timer の格納を原典は work の写し (r2) で行い, 1 の定数を2本持つ, 129 対 128 命令
// 試済: Kuro_SetStep を work 渡し / npc 渡し / &npc->work.kuro 渡し (定数2本は合うが写しは出ない), Kuro_ConsumeStepEntered の有無, if 内の別ポインタ, 宣言順
NON_MATCH void Kuro_UpdateJump(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  NPCKuroWork* work = &npc->work.kuro;
  WorldPos* pos = &npc->mover.pos;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    npc->targetAngle = 0;
    npc->mover.angle = 0;
    npc->dir8 = 3;
    npc->dir4 = 1;
    Kuro_PlayAnim(npc, 20, 1, 0, 4);
    work->velY = 20;
    pos->x = work->startX;
    pos->y = work->startY;
    pos->z = work->startZ;
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  SET_FLAGS(npc->flags, NPCFLAG_NO_GROUND);
  switch (work->step) {
    case 0: {
      s32 dx;
      s32 dz;

      work->stepEntered = FALSE;
      dx = npc->work.walk.target.x - work->startX;
      dz = npc->work.walk.target.z - work->startZ;
      pos->x = work->startX + Div(work->timer * dx, work->frames);
      pos->z = work->startZ + Div(work->timer * dz, work->frames);
      pos->y = work->startY + FixToInt(12, SIN(Div(work->timer * 128, work->frames)) * 200);
      if (work->timer >= work->frames) {
        pos->y = npc->work.walk.target.y;
        work->step = 1;
        work->stepEntered = TRUE;
        work->timer = 0;
        npc->updateDone = 1;
      }
      break;
    }
    case 1: {
      work->stepEntered = FALSE;
      break;
    }
  }
#else
  INCFUNC("asm/func/Kuro_UpdateJump.inc");
#endif
}

void Kuro_UpdatePulsePltt(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCKuroWork* work = &npc->work.kuro;
  s32 n;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
  }

  n = Div(elapsed, 60);
  Kuro_BlendPltt(npc, (n & 1) ? 60 - Mod(elapsed, 60) : Mod(elapsed, 60), 60);
  if (npc->fn(npc) == 1) {
    work->plttFadeFrames = (n & 1) ? 60 - Mod(elapsed, 60) : Mod(elapsed, 60);
  }
}

void FUN_08208ce8(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCKuroWork* work = &npc->work.kuro;

  if (npc->updateEntered) {
    u8 angle;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    angle = npc->dir4 > 1 ? 128 : 192;
    npc->mover.angle = angle;
    npc->dir8 = Angle_ToDir8Floor(angle);
    npc->dir4 = Angle_ToDir4Floor(angle);
    Kuro_PlayAnim(npc, 0, 1, 0, 4);
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  switch (work->step) {
    case 0: {
      if (Kuro_ConsumeStepEntered(npc)) {
        Kuro_PlayAnim(npc, 2, 2, 0, 4);
      }
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        Kuro_SetStep(npc, 1);
      }
      break;
    }
    case 1: {
      Kuro_ConsumeStepEntered(npc);
      if (work->timer > 30) {
        Kuro_SetStep(npc, 2);
      }
      break;
    }
    case 2: {
      if (Kuro_ConsumeStepEntered(npc)) {
        Kuro_PlayAnim(npc, 4, 2, 0, 4);
      }
      if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
        Kuro_SetStep(npc, 3);
      }
      break;
    }
    case 3: {
      if (Kuro_ConsumeStepEntered(npc)) {
        Kuro_PlayAnim(npc, 0, 2, 0, 4);
      }
      if (npc->mover.angle == npc->targetAngle) {
        npc->updateDone = 1;
      }
      break;
    }
  }
}

void Kuro_UpdateSleepTalkable(NPCManager* p, NPC* npc, s32 elapsed) {
  NPCKuroWork* work = &npc->work.kuro;

  if (npc->updateEntered) {
    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 5, 2, 0, 4);
    npc->sprite.u.main.spr.animCmdIdx = 3;
    npc->sprite.u.main.spr.animCmdTimer = 0;
    MainSprite_AdvanceAnim(&npc->sprite.u.main.spr, &npc->sprite.u.main.gfx);
  }
  if (npc->fn(npc) == 1) {
    return;
  }

  SET_FLAGS(npc->flags, NPCFLAG_TALKABLE);
  if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
    npc->updateDone = 1;
  }
  if (work->sleepEmote && elapsed > 0 && Mod(elapsed, 70) == 0) {
    work->emote = Emote_Show(work->emote, &npc->mover, EMOTE_2, 0, NULL, 0, 128, 0);
  }
}

// 下書き (268/290命令): 流れは NPC_UpdateFacePlayer と同じ, 原典は向きの更新で +8 の分岐だけ値をそのまま使い他の2つは u16 に変換した後片付けを共有する, 距離の判定は FUN_0804157c と同じ形の inline で 0/1 に起こす
// 試済: 分岐ごとの NPC_SetAngle, u16 / u32 のローカル, プレイヤーの状態の判定を Player* を受ける inline にする, IsNear inline
NON_MATCH void Kuro_UpdateFacePlayer(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Vec3* pos = &npc->mover.pos;
  s32 playerAngle;

  if (p->playerPos != NULL) {
    s8 diff = ArcTan2_8(p->playerPos->x - pos->x, p->playerPos->z - pos->z) - npc->mover.angle;

    if (diff > 8) {
      NPC_SetAngle(npc, npc->mover.angle + 8);
    } else if (diff < -8) {
      NPC_SetAngle(npc, npc->mover.angle - 8);
    } else {
      NPC_SetAngle(npc, npc->mover.angle + diff);
    }
    playerAngle = p->player->mover.angle;
  } else {
    playerAngle = 0;
  }

  if (npc->updateEntered) {
    Player* player;

    npc->updateEntered = 0;
    npc->updateDone = 0;
    Kuro_PlayAnim(npc, 0, 1, 0, 4);
    npc->unk_1ec = 1;
    npc->unk_225 = npc->mover.angle;
    player = p->player;
    if (player != NULL) {
      if (!(player->kind == PLAYER_BAT || player->kind == PLAYER_MOUSE || player->kind == PLAYER_SLEEPING) && !player->formRequest && !(player->goodCondTimer != 0 && (player->goodCondID == GOOD_MINI || player->goodCondID == GOOD_INVISIBLE)) &&
          (player->action <= PACT_WALK || player->action == PACT_PALM_UP)) {
      } else if (!(gGameFlags & GAMEFLAG_CUTSCENE) && npc->unk_0b) {
        NPC_ShowEmote(npc, 3, 0, 0);
      }
    }
  } else {
    Kuro_PlayAnim(npc, 0, 1, 0, 1);
  }

  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if (npc->fn(npc) == 1) {
    return;
  }
  if (abs(p->playerPos->x - pos->x) < npc->talkRange && abs(p->playerPos->y - pos->y) <= 0xFF && abs(p->playerPos->z - pos->z) < npc->talkRange) {
    s8 toPlayer = ArcTan2_8(pos->x - p->playerPos->x, pos->z - p->playerPos->z);
    s8 facing = playerAngle - toPlayer;
    s8 back = playerAngle - (npc->mover.angle + 0x80);

    if (abs(facing) <= 63 && abs(back) <= 31) {
      SET_FLAGS(npc->flags, NPCFLAG_TALKABLE);
    }
  }
#else
  INCFUNC("asm/func/Kuro_UpdateFacePlayer.inc");
#endif
}

// clang-format off
void (*const gKuroUpdates[24])(NPCManager*, NPC*, s32) = {
    NULL,
    NPC_UpdateHidden,
    Kuro_UpdateIdle,
    Kuro_UpdateWalkToTarget,
    Kuro_UpdateTurn,
    NPC_UpdateDropIn,
    NPC_UpdateRiseOut,
    FUN_08042868,
    NPC_UpdateWalkPath,
    Kuro_UpdateFacePlayer,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    NPC_UpdateNavToPathStart,
    Kuro_UpdateRunToTarget,
    FUN_08208808,
    FUN_08208858,
    FUN_082088a8,
    Kuro_UpdateSleep,
    Kuro_UpdateFall,
    Kuro_UpdateJump,
    Kuro_UpdatePulsePltt,
    FUN_08208ce8,
    Kuro_UpdateSleepTalkable,
};  // 0x085AEBC4
// clang-format on

u8 Kuro_SelectUpdate(NPC* npc) {
  NPCKuroWork* work = &npc->work.kuro;
  NPCUpdate* fn;

  if (npc->updateRequest == 0 || npc->updateRequest > 24) {
    return 0;
  }

  fn = gKuroUpdates[npc->updateRequest];
  npc->updateID = npc->updateRequest;
  npc->update = fn;
  npc->updateElapsed = 0;
  npc->updateEntered = 1;
  npc->updatePhase = 0;
  work->emote = Emote_Show(work->emote, &npc->mover, EMOTE_2, 0x7F, NULL, 0, 128, 0);
  work->step = 0;
  work->stepEntered = 1;
  work->timer = 0;
  return 1;
}

s32 Kuro_RunUpdate(NPCManager* p, NPC* npc) {
  NPCKuroWork* work = &npc->work.kuro;
  u32 elapsed;

  npc->flags = 0;
  npc->updateDone = 0;
  elapsed = npc->updateElapsed++;
  if (!work->stepEntered) {
    work->timer++;
  }

  if (npc->update != NULL) {
    npc->update(p, npc, elapsed);
    if (work->plttFadeFrames > 0) {
      work->plttFadeFrames--;
      Kuro_BlendPltt(npc, work->plttFadeFrames, 60);
    }
  }

  return 0;
}

void Kuro_HandleMsgs(NPC* npc) {
  MsgQueue* mq = &npc->mq;
  NPCKuroWork* work = &npc->work.kuro;
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
      case 2: {
        npc->targetAngle = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 3);
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
        NPC_StartState(npc, 16);
        break;
      }
      case 21: {
        NPC_StartState(npc, 17);
        work->sleepEmote = 0;
        break;
      }
      case 22: {
        NPC_StartState(npc, 20);
        work->sleepEmote = 0;
        break;
      }
      case 23: {
        NPC_StartState(npc, 18);
        work->sleepEmote = 1;
        break;
      }
      case 24: {
        NPC_StartState(npc, 19);
        break;
      }
      case 25: {
        NPC_StartState(npc, 20);
        work->sleepEmote = 1;
        break;
      }
      case 26: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        NPC_StartState(npc, 21);
        break;
      }
      case 27: {
        work->startX = msg->args[0];
        work->startY = msg->args[1];
        work->startZ = msg->args[2];
        npc->work.walk.target.x = msg->args[3];
        npc->work.walk.target.y = msg->args[4];
        npc->work.walk.target.z = msg->args[5];
        work->frames = msg->args[6];
        NPC_StartState(npc, 22);
        break;
      }
      case 28: {
        NPC_StartState(npc, 23);
        break;
      }
      case 29: {
        NPC_StartState(npc, 24);
        break;
      }
      case 10: {
        NPC_ShowEmote(npc, msg->args[0], msg->args[1], msg->args[2]);
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

s32 Kuro_HandleMsgsAndMove(NPCManager* p, NPC* npc) {
  Kuro_HandleMsgs(npc);
  NPC_UpdateMotion(p, npc);
  npc->updateRequest = 0;
  return 0;
}

s32 Kuro_UpdateVisibility(NPCManager* p, NPC* npc) {
  NPC_UpdateVisibility(p, npc);
  return 0;
}

s32 Kuro_OnDestroy(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// クロの NPC を作って NPCManager に繋ぐ, param_1 は work.kuro.bandaged に入る
void Kuro_SpawnNPC(s32 param_1) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  NPC* npc;
  NPCKuroWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 5);
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
  if (NPC_InitSprite(npc, 2, SPR_KURO, 0, flags) < 0) {
    return;
  }

  work = &npc->work.kuro;
  work->bandaged = param_1;
  work->sleepEmote = 0;
  work->emote = NULL;
  work->plttFadeFrames = 0;
  Mover_SetUnk30(&npc->mover, 0, 200, 0);
  NPC_InitShadow(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->dir8 = Angle_ToDir8(angle);
  npc->dir4 = Angle_ToDir4(angle);
  NPC_SetFn(npc, Kuro_SelectUpdate);
  NPC_SetCb(npc, 0, Kuro_HandleMsgsAndMove);
  NPC_SetCb(npc, 1, Kuro_RunState);
  NPC_SetCb(npc, 2, Kuro_RunUpdate);
  NPC_SetCb(npc, 3, Kuro_UpdateVisibility);
  NPC_SetOnDestroy(npc, Kuro_OnDestroy);
  npc->targetAngle = angle;
  NPC_LookupCharaTables(p, npc, SPR_KURO, 0);
  NPCManager_LinkNPC(p, npc);
  NPC_ReadConfigArgs(p, npc);

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      NPC_StartState(npc, 1);
      NPC_SetUpdate(npc, Kuro_UpdateIdle, 2);
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
      NPC_StartState(npc, 20);
      NPC_SetUpdate(npc, Kuro_UpdateSleep, 18);
      break;
    }
  }
}

// 0xD774, HashName("ＮＰＣクロ")
void Cmd_SpawnKuroNormalNPC(void) { Kuro_SpawnNPC(0); }

// 0x82C8, HashName("ＮＰＣ包帯クロ")
void Cmd_SpawnKuroBandageNPC(void) { Kuro_SpawnNPC(1); }

// 0x9DFE, '.n' の NPC を状態 25 に移す
void Cmd_9DFE(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return;
  }

  npc->unk_217 = 1;
  NPC_StartState(npc, 25);
}
