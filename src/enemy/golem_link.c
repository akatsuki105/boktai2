#include "camera.h"
#include "cwolf_target.h"
#include "dust.h"
#include "eff_elemcond.h"
#include "eff_scatter.h"
#include "emote.h"
#include "enemy.h"
#include "enemy/golem.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "link_session.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

typedef Golem GolemLink;  // ゴーレム(golem.c) の通信対戦用版

bool8 FUN_080f0a0c(Enemy* p);
bool8 Enemy_TargetNearestLinkPlayer(Enemy* p);
void FUN_080f3cdc(Enemy* p);
bool8 FUN_080f9f20(Enemy* p);
void FUN_080fa77c(Enemy* p);
bool8 Enemy_RouteToNearestLinkPlayer(Enemy* p);
void Enemy_PickPathNodeAwayFromPlayer(Enemy* p);
s32 SpawnAttackBox(Vec3* pos, u32 kind, u32 variant, s32 power, s32 knockback, s32 iframes, s32 ignoreMask);
void PlayerLink_UpdateBloodSwordOnKill(u32 param_1, u32 param_2);
void EnemyRespawnInfo_Add(u16 a, u16 b);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, u16 maxHP, u16 cells, s32 flash);
void Enemy_AddKillCount(Enemy* p);
void GolemLink_StateBurnRecover(GolemLink* p, s32 timer);
s32 FUN_080f8abc(Enemy* p);
void GolemLink_ResumeMove(GolemLink* p);
void Golem_ScatterDebris(Enemy* p);
s32 Map_HasLineOfSight(Vec3* pos, Vec3* target, s32 count, s32 limit);

void GolemLink_OnHit(Hitbox* a, Hitbox* b, GolemLink* p);
void GolemLink_OnHurt(Hitbox* a, Hitbox* b, GolemLink* p);

void GolemLink_StateRespawn(GolemLink* p);

void GolemLink_StateWakeUp(GolemLink* p, s32 timer);

void GolemLink_StateWindUp(GolemLink* p, s32 timer);

const STRING_DATA char s_eneinline_08252288[] = "../golem/../system/eneinline.h";  // 0x08252288
const STRING_DATA char s_golemcom_c_082522a8[] = "../golem/golemcom.c";

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Golem_PlayDirAnim(Golem* p, u32 anim, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 mode;

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    mode = (flags & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

static inline bool8 Golem_TestFlags(Golem* p, GolemFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

// 生成時に退避しておいた状態とフラグに戻し, 一時的な値を全部初期化する
static inline void Enemy_RestoreInitialState(Enemy* p) {
  p->flags = p->initFlags;
  p->flags2 = p->initFlags2;
  p->mover.angle = p->initAngle;
  p->subState0 = p->initSubState0;
  p->subState1 = p->initSubState1;
  p->subState2 = p->initSubState2;
  p->handlerState = p->initHandlerState;
  p->state = p->initState;
  p->flags5 = p->initFlags5;
  p->heightAboveFloor = p->initHeightAboveFloor;
  p->hp = p->maxHp;
  p->flags4 = 0;
  p->unk_222 = 0;
  p->flags3 = 0;
  p->subStateDone = FALSE;
  p->subStateBegun = TRUE;
  p->stateBegun = TRUE;
  p->animForceRestart = FALSE;
  p->chaseTimer = 0;
  p->stunTimer = 0;
  p->unk_544 = 0;
  p->nodeWait = 0;
  p->hitTargetID = 0;
  p->playerMover = NULL;
  p->angle = 0;
  p->unk_21c = 0;
  p->animSpeedDiv = 1;
  p->weaponExpMask = 0;
  p->flags6 = 0;
  p->unk_4a0 = 0;
  p->unk_48c = 0;
  p->unk_4be = 0;
  p->unk_48d = 0;
  p->unk_48e = 0;
  ClearMemory(p->unk_458, 8);
  p->burnTimer = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, s_eneinline_08252288, 2434);
  p->lookAngle = 0;
  p->lookBaseAngle = 0;
  p->unk_542 = 0xFF;
  p->savedHandlerState = NULL;
  p->savedSubState0 = 0;
  p->savedSubState1 = 0;
  p->savedSubState2 = 0;
  p->savedState = 0;
  EnemyManager_TryEndPaletteFade(p);
}

// 振り向きアニメ (2 番の variant) を流す, MainSprite では 2 + variant 番を流し, 逆再生でなければ同じものが流れているとき何もしない
static inline void Golem_PlayTurnAnim(Golem* p, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = 2;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, 2, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    u32 anim = variant + 2;

    if (!(flags & ANIM_PLAY_REVERSE) && (p->e).playingAnim == anim && !(p->e).animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, (flags & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

// a - b を -128..128 に丸めた角度の差
static inline s32 Golem_AngleDiff(s32 a, s32 b) {
  s32 d = a - b;

  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

void GolemLink_StateStopAndTurn(GolemLink* p);
void GolemLink_StateUncurl(GolemLink* p);

// 大きく向きが変わるとき, rollTime を 10 減らして残っていればその場で止まって向き直り, 尽きていれば丸まりを解く
static inline void Golem_TurnOrUncurl(Golem* q) {
  q->rollAngle = q->prevMoveAngle;
  (q->e).mover.angle = q->prevMoveAngle;
  q->rollTime -= 10;
  if (q->rollTime > 0) {
    q->routeDest = (q->e).navAgent->waypoint;
    Enemy_EnterState(&q->e, GolemLink_StateStopAndTurn, ES_UNK_37);
    (q->e).subState2 = 2;
  } else {
    Enemy_EnterState(&q->e, GolemLink_StateUncurl, ES_UNK_38);
    (q->e).subState2 = 3;
  }
  (q->e).subStateTimer = 0;
  (q->e).subStateBegun = 1;
}

const u16 sGolemLinkMoveSpeeds[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085ADF98

const u16 sGolemLinkRollPlayFlags[2] = {0, 4};  // 0x085ADFA8

void GolemLink_StartChase(GolemLink*);
void FUN_081be01c(GolemLink*);

void (*const sGolemLinkHandlerTable3[2])(GolemLink*) = {
    GolemLink_StartChase,
    FUN_081be01c,
};  // 0x085ADFAC

void GolemLink_SubRollToTarget(GolemLink*);
void GolemLink_SubRoll(GolemLink*);
void GolemLink_SubDecideCharge(GolemLink*);
void GolemLink_SubReturnToRoute(GolemLink*);
void GolemLink_WaitFacingPlayer(GolemLink*);
void GolemLink_SubDash(GolemLink*);
void GolemLink_SubWindUpAndRoll(GolemLink*);
void GolemLink_SubContinueRoll(GolemLink*);
void GolemLink_SubStopAndReroute(GolemLink*);
void GolemLink_SubRestAndResume(GolemLink*);

void (*const sGolemLinkHandlerTable4[10])(GolemLink*) = {
    GolemLink_SubRollToTarget,
    GolemLink_SubRoll,
    GolemLink_SubDecideCharge,
    GolemLink_SubReturnToRoute,
    GolemLink_WaitFacingPlayer,
    GolemLink_SubDash,
    GolemLink_SubWindUpAndRoll,
    GolemLink_SubContinueRoll,
    GolemLink_SubStopAndReroute,
    GolemLink_SubRestAndResume,
};  // 0x085ADFB4

void (*const PTR_ARRAY_085adfdc[15])(GolemLink*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f9c20,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f9e34,
    (void*)FUN_080f9ee0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    (void*)FUN_080f12c4,
};  // 0x085ADFDC

// golem.c の Golem_MoveAlongNavAxis と同じ
bool8 GolemLink_MoveAlongNavAxis(GolemLink* p, NavAgent* nav, u32 rangeX, u32 rangeZ, s32 speed) {
  GolemLink* q = (p->e).owner;
  s32 dx = nav->waypoint.x - (p->e).mover.pos.x;
  s32 dz = nav->waypoint.z - (p->e).mover.pos.z;

  if (abs(dx) <= rangeX && abs(dz) <= rangeZ) {
    if (abs(dx) > abs(dz)) {
      dz = 0;
    } else {
      dx = 0;
    }
    q->moveAngle = ArcTan2_8(dx, dz);
    (p->e).mover.delta.x += (speed * COS(q->moveAngle)) >> 16;
    (p->e).mover.delta.z += (speed * SIN(q->moveAngle)) >> 16;
    return TRUE;
  }
  if (dx != 0 || dz != 0) {
    u8 angle;

    if (abs(dx) > abs(dz)) {
      dz = 0;
    } else {
      dx = 0;
    }
    angle = ArcTan2_8(dx, dz);
    if (angle != q->moveAngle) {
      (p->e).mover.angle = angle;
      q->moveAngle = angle;
      return TRUE;
    }
    (p->e).mover.delta.x += (speed * COS(angle)) >> 16;
    (p->e).mover.delta.z += (speed * SIN(angle)) >> 16;
    (p->e).mover.angle = angle;
    q->moveAngle = angle;
  }
  return FALSE;
}

// golem.c の Golem_ClassifyNextTile と同じ
s32 GolemLink_ClassifyNextTile(u32 tileIdx, s32 height, s32 dir) {
  s32 stairs = -1;
  s32 tileHeight, tileStairs, diff;

  switch (dir) {
    case 0: {
      tileIdx += 1;
      stairs = STAIRS_HORIZONTAL;
      break;
    }
    case 1: {
      tileIdx += gCollisionMap->tiledata->width;
      stairs = STAIRS_VERTICAL;
      break;
    }
    case 2: {
      tileIdx -= 1;
      stairs = STAIRS_HORIZONTAL;
      break;
    }
    case 3: {
      tileIdx -= gCollisionMap->tiledata->width;
      stairs = STAIRS_VERTICAL;
      break;
    }
  }
  tileHeight = TileAtIndex(tileIdx)->heightStairs & 0xF;
  tileStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
  if (TEST_FLAGS(TileAtIndex(tileIdx)->attr, TATTR_PLAYER_WALL | TATTR_ENEMY_WALL)) {
    if (tileHeight >= height) {
      return 1;
    }
    return 2;
  }
  diff = tileHeight - height;
  if (diff == 1 && tileStairs == stairs) {
    return 0;
  }
  if (diff == -1 && tileStairs == stairs) {
    return 0;
  }
  if (diff > 0) {
    return 1;
  }
  if (diff < 0) {
    return 2;
  }
  return 0;
}

// golem.c の Golem_SnapToNextTile と同じ
// 37/35 命令, golem.c の Golem_SnapToNextTile の C をそのまま当てただけ, 残差は Golem_SnapToNextTile と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SnapToNextTile(Vec3* pos, s32 dir) {
#ifdef NONMATCHING_C
  switch (dir) {
    case 0: {
      pos->x = ((pos->x + 0xFF) & ~0xFF) + 0x80;
      break;
    }
    case 1: {
      pos->z = ((pos->z + 0xFF) & ~0xFF) + 0x80;
      break;
    }
    case 2: {
      pos->x = ((pos->x - 0xFF) & ~0xFF) + 0x80;
      break;
    }
    case 3: {
      pos->z = ((pos->z - 0xFF) & ~0xFF) + 0x80;
      break;
    }
  }
#else
  INCFUNC("asm/func/GolemLink_SnapToNextTile.inc");
#endif
}

// golem.c の Golem_SnapToTileCenter と同じ
void GolemLink_SnapToTileCenter(Vec3* pos) {
  pos->x = (pos->x & ~0xFF) + 0x80;
  pos->y = (pos->y & ~0xFF) + 0x80;
  pos->z = (pos->z & ~0xFF) + 0x80;
}

// golem.c の Golem_RouteTo と同じ
// 197/204 命令, golem.c の Golem_RouteTo の C をそのまま当てただけ, 残差は Golem_RouteTo と同じ形 (1回で打ち切り)
NON_MATCH s32 GolemLink_RouteTo(GolemLink* p) {
#ifdef NONMATCHING_C
  Enemy* e = &p->e;
  Mover* mover = &(p->e).mover;

  if (Map_TryFindNavRoute((p->e).navAgent, &(p->e).mover.pos, &p->routeDest) != 0) {
    s32 dx = (p->e).navAgent->waypoint.x - (p->e).mover.pos.x;
    s32 dz = (p->e).navAgent->waypoint.z - (p->e).mover.pos.z;
    s32 tile = GetCollisionTileIdx(&(p->e).navAgent->waypoint);
    Vec3 d;
    s32 dir;

    if (tile != GetCollisionTileIdx(&mover->pos)) {
      if (abs(dx) < abs(dz)) {
        e->navAgent->waypoint.x = (mover->pos.x & ~0xFF) + 0x80;
      } else {
        e->navAgent->waypoint.z = (mover->pos.z & ~0xFF) + 0x80;
      }
    }
    p->moveAngle = ArcTan2_8(e->navAgent->waypoint.x - mover->pos.x, e->navAgent->waypoint.z - mover->pos.z);
    p->moveAngle = (((p->moveAngle + 0x20) & 0xFF) >> 6) << 6;
    Vec3_Diff(&d, &e->navAgent->waypoint, &e->mover.pos);
    dir = ((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6;
    if (d.x + d.z != 0 && dir != p->moveAngle >> 6) {
      ClearMemory(&e->mover.delta, 8);
    }
  } else {
    p->rollTime = 0;
  }
  return 1;
#else
  INCFUNC("asm/func/GolemLink_RouteTo.inc");
#endif
}

// golem.c の Golem_OnAttackRequest の通信対戦版
void GolemLink_OnAttackRequest(GolemLink* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      return;
    }
    GolemLink_ResumeMove(p);
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
}

// golem.c の FUN_08115874 と同じ
// 260/278 命令, golem.c の FUN_08115874 の C をそのまま当てただけ, 残差は FUN_08115874 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081b8988(GolemLink* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  } else {
    (p->e).animSpeedDiv = 2;
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).chaseTimer += 300;
      if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
        (p->e).chaseTimer = (p->e).chaseTimeMax;
      }
    }
  }
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  (p->e).pathNodePos->val = 0;
  if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/FUN_081b8988.inc");
#endif
}

// golem.c の Golem_TargetPlayerTile の通信対戦版
void GolemLink_TargetPlayerTile(GolemLink* p) {
  GolemLink* q = (p->e).owner;

  if (!TEST_FLAGS(GetTileAttrAt(&(p->e).playerMover->pos), TATTR_PLAYER_WALL | TATTR_ENEMY_WALL | TATTR_FALLDEATH) && Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    q->targetPos = (p->e).playerMover->pos;
    GolemLink_SnapToTileCenter(&q->targetPos);
  }
}

// golem.c の Golem_SetTargetTile の通信対戦版
void GolemLink_SetTargetTile(GolemLink* p, WorldPos* pos) {
  GolemLink* q = (p->e).owner;

  if (!TEST_FLAGS(GetTileAttrAt(pos), TATTR_PLAYER_WALL | TATTR_ENEMY_WALL | TATTR_FALLDEATH) && Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, pos)) {
    q->targetPos = *pos;
    GolemLink_SnapToTileCenter(&q->targetPos);
    SET_FLAGS(q->flags, GOLEMFLAG_TARGET_FIXED);
  }
}

// golem.c の Golem_UpdateTarget の通信対戦版
void GolemLink_UpdateTarget(GolemLink* p) {
  if (!Golem_TestFlags((p->e).owner, GOLEMFLAG_TARGET_FIXED) && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8) && !Player_TestFlag20(gPlayerPtr[0], PFLAG20_INVISIBLE) && (p->e).playerMover != NULL) {
    GolemLink_TargetPlayerTile(p);
  }
}

// golem.c の Golem_ResumeMove と同じ
void GolemLink_ResumeMove(GolemLink* p) {
  Enemy_ClearPendingState(&p->e, s_golemcom_c_082522a8, 536);
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

// golem.c の Golem_InitAnims と同じ
void GolemLink_InitAnims(GolemLink* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 11, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 1, 0);
  Enemy_SetAnimEntry(&p->e, 2, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 6, 4, 0);
  Enemy_SetAnimEntry(&p->e, 7, 5, 0);
  Enemy_SetAnimEntry(&p->e, 10, 6, 0);
  Enemy_SetAnimEntry(&p->e, 15, 7, 0);
  Enemy_SetAnimEntry(&p->e, 16, 8, 0);
}

// golem.c の Golem_OnReset と同じ
// 193/194 命令, golem.c の Golem_OnReset の C をそのまま当てただけ, 残差は Golem_OnReset と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_OnReset(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->unk_658 = 0;
  q->flags = 0;
  q->unk_6b0 = 0;
  q->speed = 0;
  q->rollTime = 0;
  q->stopAnimSpeed = 0;
  q->rollFrames = 0;
  q->chargeGauge = 0;
  q->windUpTime = 0;
  q->facing = DIR4_NORTH;
  q->stopPhase = 0;
  q->moveAngle = 0;
  q->stopTimer = 0;
  q->prevMoveAngle = 0;
  q->rollAngle = 0;
  ClearMemory(&q->targetPos, sizeof(Vec3));
  ClearMemory(&q->routeDest, sizeof(Vec3));
  ClearMemory(&q->unk_6d8, sizeof(Vec3));
  ClearMemory(&q->unk_6a8, sizeof(Vec3));
  q->shakePower = 0;
  q->shakeTimer = 0;
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/GolemLink_OnReset.inc");
#endif
}

// golem.c の FUN_08115f78 と同じ
void FUN_081b908c(GolemLink* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// golem.c の Golem_Accelerate と同じ
// 92/92 命令, golem.c の Golem_Accelerate の C をそのまま当てただけ, 残差は Golem_Accelerate と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_Accelerate(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  s32 max, accel;

  if (TileAtIndex((p->e).tileIdx)->heightStairs >> 4) {
    switch ((p->e).variant) {
      case EV_GOLEM_S:
      case EV_GOLEM_P:
      case EV_GOLEM_5: {
        max = 320, accel = 11;
        break;
      }
      case EV_GOLEM_C: {
        max = 160, accel = 5;
        break;
      }
      default: {
        max = 256, accel = 8;
        break;
      }
    }
  } else {
    switch ((p->e).variant) {
      case EV_GOLEM_S:
      case EV_GOLEM_P:
      case EV_GOLEM_5: {
        max = 448, accel = 22;
        break;
      }
      case EV_GOLEM_C: {
        max = 320, accel = 10;
        break;
      }
      default: {
        max = 384, accel = 16;
        break;
      }
    }
  }
  if (q->speed < max) {
    q->speed += accel;
  } else {
    q->speed = max;
  }
#else
  INCFUNC("asm/func/GolemLink_Accelerate.inc");
#endif
}

// golem.c の Golem_TryChaseHitTarget と同じ
bool8 GolemLink_TryChaseHitTarget(GolemLink* p) { return TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) ? (p->e).unk_618(&p->e) : FALSE; }

// golem.c の Golem_GetMoveSpeed と同じ
s32 GolemLink_GetMoveSpeed(GolemLink* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  AuxAnimState* a = anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (anim->cmdIdx < 8) {
      return sGolemLinkMoveSpeeds[anim->cmdIdx];
    } else if (anim->cmdIdx >= 8 && anim->cmdIdx < 16) {
      return sGolemLinkMoveSpeeds[a->cmdIdx - 8];
    }
  }
  return 0;
}

// golem.c の Golem_ReleaseFixedTarget と同じ
void GolemLink_ReleaseFixedTarget(GolemLink* p) {
  if ((p->e).state != ES_UNK_9 && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) && (*(u32*)&(p->e).subState0 & 0xFFFFFF) != ENEMY_SUBSTATE(0, 2, 0)) {
    GolemLink* q = (p->e).owner;

    CLEAR_FLAGS(q->flags, GOLEMFLAG_TARGET_FIXED);
  }
}

// golem.c の Golem_InitHitboxes と同じ
void GolemLink_InitHitboxes(GolemLink* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, GolemLink_OnHurt, p);
  VEC3_SET(hitSize, 64, 120, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, GolemLink_OnHit, 0, p);
}

// golem.c の Golem_UpdateAtkHitbox と同じ
// 166/166 命令, golem.c の Golem_UpdateAtkHitbox の C をそのまま当てただけ, 残差は Golem_UpdateAtkHitbox と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_UpdateAtkHitbox(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
      Hitbox* hb = &(p->e).hitbox;

      hb->ignoreMask = HIM_5;
      hb->flags = HBF_HITBOX | HBF_DAMAGE;
      Hitbox_SetAttack(hb, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2] | HBATTR_INKA | HBATTR_FLAME, (p->e).atkIframes[2]);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_14);
    } else if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      s32 rate = FixToInt(5, q->speed);
      s32 power, knockback;
      Hitbox* hb;

      if (rate > 20) {
        rate = 20;
      } else if (rate < 10) {
        rate = 10;
      }
      power = Div(rate * (p->e).atkPower[1], 10);
      knockback = Div((p->e).atkKnockback[1] * (rate >> 1), 10);
      hb = &(p->e).hitbox;
      hb->flags = HBF_HITBOX | HBF_9 | HBF_ANGLE | HBF_DAMAGE;
      hb->ignoreMask = 0;
      Hitbox_SetAttack(hb, power, knockback, HBSRC_7, (p->e).atkAttrs[1] | HBATTR_BLOW, (p->e).atkIframes[1]);
      SET_FLAGS((p->e).cwolfNode.flags, 1);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_14);
    } else {
      Hitbox* hb = &(p->e).hitbox;

      hb->flags = HBF_HITBOX | HBF_DAMAGE;
      hb->ignoreMask = HIM_4;
      Hitbox_SetAttack(hb, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
#else
  INCFUNC("asm/func/GolemLink_UpdateAtkHitbox.inc");
#endif
}

// golem.c の Golem_OnHit と同じ
// 327/327 命令, golem.c の Golem_OnHit の C をそのまま当てただけ, 残差は Golem_OnHit と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_OnHit(Hitbox* a, Hitbox* b, GolemLink* p) {
#ifdef NONMATCHING_C
  Mover* mover = &(p->e).mover;
  GolemLink* q = (p->e).owner;
  Vec3 pos, d;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  pos = a->center;
  switch (((mover->angle + 0x20) & 0xFF) >> 6) {
    case 0: {
      pos.x -= 0x100;
      break;
    }
    case 1: {
      pos.z -= 0x100;
      break;
    }
    case 2: {
      pos.x += 0x100;
      break;
    }
    case 3: {
      pos.z += 0x100;
      break;
    }
  }
  Vec3_Diff(&d, &b->center, &pos);
  a->angle = ArcTan2_8(d.x, d.z);
  if (b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      if ((p->e).state != ES_UNK_40) {
        bool8 hit;

        if (!(((Player*)b->owner)->flag20 & PFLAG20_WALL_COVER)) {
          hit = TRUE;
        } else {
          hit = abs(FixToInt(6, (mover->angle + 0x20) & 0xFF) - FixToInt(6, (b->angle + 0x20) & 0xFF)) == 2;
        }
        if (!hit) {
          Player* pl;

          if (!IsLinkPlay()) {
            pl = gPlayerPtr[0];
          } else {
            u16 mask = b->ignoreMask;
            s32 idx;

            if (mask & HIM_0) {
              idx = 0;
            } else if (mask & HIM_1) {
              idx = 1;
            } else if (mask & HIM_2) {
              idx = 2;
            } else {
              idx = 3;
            }
            pl = gPlayerPtr[idx];
          }
          if (pl->flag20 & PFLAG20_INVISIBLE) {
            return;
          }
          q->chargeGauge = 400;
          return;
        }
      }
      Enemy_SetHitTarget(&p->e, b);
      q->chargeGauge += 200;
      if (q->chargeGauge > 400) {
        q->chargeGauge = 400;
      }
      b->hitState |= 1;
      q->rollHitID = b->id;
    } else {
      Enemy_SetHitTarget(&p->e, b);
      q->chargeGauge += 200;
      if (q->chargeGauge > 400) {
        q->chargeGauge = 400;
      }
    }
  } else {
    Enemy_SetHitTarget(&p->e, b);
  }
#else
  INCFUNC("asm/func/GolemLink_OnHit.inc");
#endif
}

// golem.c の Golem_OnHurt と同じ
// 752/763 命令, golem.c の Golem_OnHurt の C をそのまま当てただけ, 残差は Golem_OnHurt と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_OnHurt(Hitbox* a, Hitbox* b, GolemLink* p) {
#ifdef NONMATCHING_C
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/GolemLink_OnHurt.inc");
#endif
}

// golem.c の Golem_StateMove と同じ
void GolemLink_StateMove(GolemLink* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

// golem.c の Golem_StateWait と同じ
void GolemLink_StateWait(GolemLink* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// golem.c の Golem_StateTurn と同じ
// 714/725 命令, golem.c の Golem_StateTurn の C をそのまま当てただけ, 残差は Golem_StateTurn と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateTurn(GolemLink* p) {
#ifdef NONMATCHING_C
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 dir;
    u32 target;

    (p->e).mover.angle = Angle_ToDir4((p->e).mover.angle) * 64 - 64;
    dir = Angle_ToDir4((p->e).mover.angle);
    if ((p->e).subState2 != 6 && !Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_10)) {
      target = mover->path->node->delay >> 12;
      (p->e).unk_1dc = target;
    } else {
      target = (p->e).unk_1dc;
    }
    if (dir == FixToInt(1, target)) {
      (p->e).subStateDone = 1;
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_10)) {
        Enemy_PlayAnim(&p->e, 0);
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        return;
      }
      Enemy_PlayAnim(&p->e, 0);
      return;
    }
    switch (dir) {
      case DIR4_NORTH: {
        if (target - 2 < 4) {
          Golem_PlayTurnAnim(p, 1, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Golem_PlayTurnAnim(p, 0, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case DIR4_EAST: {
        if (target - 4 < 4) {
          Golem_PlayTurnAnim(p, 2, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Golem_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case DIR4_SOUTH: {
        if (target - 1 > 4) {
          Golem_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE | ANIM_PLAY_XFLIP);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Golem_PlayTurnAnim(p, 2, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case DIR4_WEST: {
        if (target < 4) {
          Golem_PlayTurnAnim(p, 0, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Golem_PlayTurnAnim(p, 1, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
    }
    (p->e).animForceRestart = FALSE;
  }
  if ((p->e).s->aux.anim.tick == 0) {
    u32 target = ((p->e).unk_1dc + 5) & 7;
    u8 angle = mover->angle;

    if (abs(angle - target * 32) < 23) {
      mover->angle = target * 32;
    } else if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      mover->angle = angle + 22;
    } else {
      mover->angle = angle - 22;
    }
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).animForceRestart) {
    s32 dir = Angle_ToDir8((p->e).mover.angle);
    s32 d = abs((p->e).unk_1dc - dir);

    if (d > 0) {
      Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    } else {
      (p->e).subStateDone = 1;
      (p->e).mover.angle = Angle_ToDir4((p->e).mover.angle) * 64 - 64;
      Enemy_PlayAnim(&p->e, 0);
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_10)) {
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      }
    }
  }
#else
  INCFUNC("asm/func/GolemLink_StateTurn.inc");
#endif
}

// golem.c の Golem_StateRespawnWait と同じ
void GolemLink_StateRespawnWait(GolemLink* p, s32 timer) {
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnim(&p->e, 7);
    Enemy_EnterState(&p->e, GolemLink_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// golem.c の Golem_StateRespawn と同じ
void GolemLink_StateRespawn(GolemLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  if ((p->e).animForceRestart) {
    GolemLink_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// golem.c の Golem_StateNap と同じ
void GolemLink_StateNap(GolemLink* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 6);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, GolemLink_StateWakeUp, ES_WAKE_UP);
  }
}

// golem.c の Golem_StateWakeUp と同じ
void GolemLink_StateWakeUp(GolemLink* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// golem.c の Golem_StateCurledIdle と同じ
void GolemLink_StateCurledIdle(GolemLink* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    (p->e).animForceRestart = FALSE;
  }
  if (anim->cmdIdx == 1) {
    anim->tick = 0;
  }
}

// golem.c の Golem_StateCurlUp と同じ
void GolemLink_StateCurlUp(GolemLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, GolemLink_StateWindUp, ES_UNK_33);
  }
}

// golem.c の Golem_StateWindUp と同じ
// 301/302 命令, golem.c の Golem_StateWindUp の C をそのまま当てただけ, 残差は Golem_StateWindUp と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateWindUp(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    GolemLink* r = (p->e).owner;
    s32 wait;

    switch ((p->e).variant) {
      case EV_GOLEM_C: {
        if (Golem_TestFlags(r, GOLEMFLAG_UNK_11)) {
          CLEAR_FLAGS(r->flags, GOLEMFLAG_UNK_11);
          wait = 0;
        } else {
          wait = (Random() & 3) * 16 + 50;
        }
        break;
      }
      case EV_GOLEM_S:
      case EV_GOLEM_P:
      case EV_GOLEM_5: {
        if (Golem_TestFlags(r, GOLEMFLAG_UNK_11)) {
          CLEAR_FLAGS(r->flags, GOLEMFLAG_UNK_11);
          wait = 0;
        } else {
          wait = (Random() & 3) * 4 + 30;
        }
        break;
      }
      default: {
        wait = 0;
        break;
      }
    }
    q->windUpTime = wait;
  }
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemLinkRollPlayFlags[flags] | flags;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = 8;
    AuxAnim_SetAnim(&s->anim, s->animFile, 8, variant, f);
    (p->e).animForceRestart = 0;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = variant + 8;

    if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (f & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = 0;
    }
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  if (q->speed < 384) {
    q->speed += 16;
  }
  (p->e).animSpeedDiv = q->speed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (timer > q->windUpTime) {
    (p->e).subStateDone = 1;
    PlayGolemSound(&p->e, 4);
  }
#else
  INCFUNC("asm/func/GolemLink_StateWindUp.inc");
#endif
}

// golem.c の Golem_StateRoll と同じ
// 242/241 命令, golem.c の Golem_StateRoll の C をそのまま当てただけ, 残差は Golem_StateRoll と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateRoll(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  Enemy* e = &p->e;
  u8 variant;
  AuxAnimPlayFlags flags;

  if (Enemy_ConsumeStateBegun(e)) {
    (p->e).animForceRestart = 0;
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  Golem_PlayDirAnim(p, 8, variant, sGolemLinkRollPlayFlags[flags] | flags);
  (p->e).animSpeedDiv = q->speed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((timer & 3) == 0) {
    Vec3 dir, size;

    dir.x = -e->mover.delta.x, dir.y = 0, dir.z = -e->mover.delta.z;
    VEC3_SET(size, 32, 0, 32);
    DustManager_Spawn(&e->mover.pos, &dir, &size, 1, 3, 4);
  }
#else
  INCFUNC("asm/func/GolemLink_StateRoll.inc");
#endif
}

// golem.c の Golem_StateUncurl と同じ
void GolemLink_StateUncurl(GolemLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 variant;
    AuxAnimPlayFlags flags;

    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    Golem_PlayDirAnim(p, 7, variant, flags | ANIM_PLAY_REVERSE);
    (p->e).animForceRestart = 0;
  }
  if ((p->e).animForceRestart) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).subStateDone = 1;
  }
}

// golem.c の Golem_StateStopAndTurn と同じ
// 530/535 命令, golem.c の Golem_StateStopAndTurn の C をそのまま当てただけ, 残差は Golem_StateStopAndTurn と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateStopAndTurn(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
    (p->e).animForceRestart = 0;
    q->stopPhase = 0;
    q->facing = Angle_ToDir4(q->prevMoveAngle);
    q->routeDest = (p->e).mover.pos;
    GolemLink_SnapToTileCenter(&q->routeDest);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemLinkRollPlayFlags[flags] | flags;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = 8;
    AuxAnim_SetAnim(&s->anim, s->animFile, 8, variant, f);
    (p->e).animForceRestart = 0;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = variant + 8;

    if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (f & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = 0;
    }
  }
  if (q->stopPhase == 0) {
    Vec3 delta, next;

    q->speed -= 40;
    if (q->speed < 0) {
      q->stopPhase = 1;
      q->speed = 0;
      return;
    }
    delta.x = (COS(q->rollAngle) * q->speed) >> 16;
    delta.z = (SIN(q->rollAngle) * q->speed) >> 16;
    next = (p->e).mover.pos;
    next.x += delta.x;
    next.z += delta.z;
    if ((p->e).tileIdx == GetCollisionTileIdx(&next)) {
      (p->e).mover.delta.x += delta.x;
      (p->e).mover.delta.z += delta.z;
    } else {
      q->speed = 0;
      q->stopPhase = 1;
    }
  } else if (q->stopPhase == 1) {
    Vec3 pos, d;

    TilePosAtIndex(&pos, (p->e).tileIdx);
    Vec3_Diff(&d, &pos, &(p->e).mover.pos);
    switch (q->rollAngle >> 6) {
      case 0:
      case 2: {
        d.z = 0;
        if (d.x > 8) {
          (p->e).mover.delta.x = 8;
        } else if (d.x < -8) {
          (p->e).mover.delta.x = -8;
        } else {
          (p->e).mover.delta.x = d.x;
        }
        break;
      }
      case 1:
      case 3: {
        d.x = 0;
        if (d.z > 8) {
          (p->e).mover.delta.z = 8;
        } else if (d.z < -8) {
          (p->e).mover.delta.z = -8;
        } else {
          (p->e).mover.delta.z = d.z;
        }
        break;
      }
    }
    if (d.x + d.z == 0) {
      q->stopPhase = 2;
      q->stopTimer = 0;
      return;
    }
  } else if (++q->stopTimer >= 16) {
    q->routeDest = q->targetPos;
    GolemLink_RouteTo(q);
    q->prevMoveAngle = q->moveAngle;
    (p->e).mover.angle = q->moveAngle;
    (p->e).subStateDone = 1;
    q->stopTimer = 0;
    q->speed = 0;
    return;
  }
  (p->e).animSpeedDiv = q->stopAnimSpeed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
#else
  INCFUNC("asm/func/GolemLink_StateStopAndTurn.inc");
#endif
}

// golem.c の Golem_StateCharge と同じ
// 309/311 命令, golem.c の Golem_StateCharge の C をそのまま当てただけ, 残差は Golem_StateCharge と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateCharge(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
    q->rollHitID = 0;
  }
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemLinkRollPlayFlags[flags] | flags;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = 8;
    AuxAnim_SetAnim(&s->anim, s->animFile, 8, variant, f);
    (p->e).animForceRestart = 0;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = variant + 8;

    if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (f & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = 0;
    }
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  if ((timer & 3) == 0) {
    Vec3 dir, size;
    u8 angle = Random();

    dir.x = FixToInt(8, COS(angle));
    dir.z = FixToInt(8, COS(angle));
    VEC3_SET(size, 48, 0, 48);
    DustManager_Spawn(&(p->e).mover.pos, &dir, &size, 2, (Random() & 1) + 2, 4);
  }
  if (q->speed < 384) {
    q->speed += 16;
  }
  (p->e).animSpeedDiv = q->speed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
#else
  INCFUNC("asm/func/GolemLink_StateCharge.inc");
#endif
}

// golem.c の Golem_StateDash と同じ
// 339/349 命令, golem.c の Golem_StateDash の C をそのまま当てただけ, 残差は Golem_StateDash と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateDash(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    PlayGolemSound(&p->e, 4);
  }
  Enemy_PlayAnim(&p->e, 16);
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).mover.delta.x = ((q->speed * COS(mover->angle)) >> 16) + (p->e).mover.delta.x;
  (p->e).mover.delta.z = ((q->speed * SIN(mover->angle)) >> 16) + (p->e).mover.delta.z;
  if ((timer & 3) == 0) {
    Vec3 dir, size;

    dir.x = -mover->delta.x, dir.y = 0, dir.z = -mover->delta.z;
    VEC3_SET(size, 32, 0, 32);
    DustManager_Spawn(&mover->pos, &dir, &size, 1, 3, 4);
  }
  if ((p->e).tile.unk_0[0] & 1) {
    Vec3 vel, velRange;
    s32 count;

    q->shakePower = 30;
    q->shakeTimer = 20;
    vel.x = FixToInt(2, mover->delta.z);
    vel.y = Random() & 7;
    vel.z = FixToInt(2, mover->delta.x);
    velRange.x = (Random() & 3) + 15;
    velRange.y = (Random() & 7) + 15;
    velRange.z = (Random() & 3) + 15;
    count = (Random() & 3) + 4;
    ScatterEffect_Spawn(count, FUN_080f8abc(&p->e), &(p->e).mover.pos, &vel, &velRange, 45, 31);
    PlayGolemSound(&p->e, 5);
    if (q->rollHitID == 0) {
      (p->e).stunTimer = 180;
      SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
      Enemy_EnterState(&p->e, (p->e).handlerStun, ES_STUN);
    } else {
      (p->e).subStateDone = 1;
    }
  }
#else
  INCFUNC("asm/func/GolemLink_StateDash.inc");
#endif
}

// golem.c の Golem_StateStopAtTile と同じ
// 412/428 命令, golem.c の Golem_StateStopAtTile の C をそのまま当てただけ, 残差は Golem_StateStopAtTile と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateStopAtTile(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
    q->stopPhase = 0;
    q->facing = Angle_ToDir4(q->moveAngle);
    q->routeDest = (p->e).mover.pos;
    GolemLink_SnapToTileCenter(&q->routeDest);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemLinkRollPlayFlags[flags] | flags;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = 8;
    AuxAnim_SetAnim(&s->anim, s->animFile, 8, variant, f);
    (p->e).animForceRestart = 0;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = variant + 8;

    if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (f & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = 0;
    }
  }
  if (q->stopPhase == 0) {
    switch ((p->e).variant) {
      case EV_GOLEM_C: {
        q->speed -= 64;
        break;
      }
      case EV_GOLEM_S:
      case EV_GOLEM_P:
      case EV_GOLEM_5: {
        q->speed -= 192;
        break;
      }
      default: {
        q->speed -= 128;
        break;
      }
    }
    if (q->speed < 0) {
      q->stopPhase = 1;
      q->speed = 0;
      return;
    }
    (p->e).mover.delta.x = ((q->speed * COS(q->moveAngle)) >> 16) + (p->e).mover.delta.x;
    (p->e).mover.delta.z = ((q->speed * SIN(q->moveAngle)) >> 16) + (p->e).mover.delta.z;
  } else if (q->stopPhase == 1) {
    Vec3 d;

    Vec3_Diff(&d, &q->routeDest, &(p->e).mover.pos);
    switch (q->rollAngle >> 6) {
      case 0:
      case 2: {
        d.z = 0;
        if (d.x > 8) {
          (p->e).mover.delta.x = 8;
        } else if (d.x < -8) {
          (p->e).mover.delta.x = -8;
        } else {
          (p->e).mover.delta.x = d.x;
        }
        break;
      }
      case 1:
      case 3: {
        d.x = 0;
        if (d.z > 8) {
          (p->e).mover.delta.z = 8;
        } else if (d.z < -8) {
          (p->e).mover.delta.z = -8;
        } else {
          (p->e).mover.delta.z = d.z;
        }
        break;
      }
    }
    if (d.x + d.z == 0) {
      q->stopPhase = 2;
      q->stopTimer = 0;
      return;
    }
  } else if (++q->stopTimer >= 8) {
    (p->e).subStateDone = 1;
    q->stopTimer = 0;
    q->speed = 0;
    return;
  }
  (p->e).animSpeedDiv = q->stopAnimSpeed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
#else
  INCFUNC("asm/func/GolemLink_StateStopAtTile.inc");
#endif
}

// golem.c の Golem_StateBrake と同じ
// 236/247 命令, golem.c の Golem_StateBrake の C をそのまま当てただけ, 残差は Golem_StateBrake と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateBrake(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 variant;
    AuxAnimPlayFlags flags;
    s32 f;
    u8 angle = (p->e).mover.angle;

    (p->e).mover.angle = q->rollAngle;
    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    (p->e).mover.angle = angle;
    f = sGolemLinkRollPlayFlags[flags] | flags;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s = &(p->e).s->aux;

      (p->e).playingAnim = 8;
      AuxAnim_SetAnim(&s->anim, s->animFile, 8, variant, f);
      (p->e).animForceRestart = 0;
    } else {
      MainSprite* s = &(p->e).s->main.spr;
      s32 a = variant + 8;

      if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
        if (f & ANIM_PLAY_XFLIP) {
          MainSprite_SetFlags(s, SPRFLAG_XFLIP);
        } else {
          MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
        }
        (p->e).animForceRestart = 0;
      }
    }
    (p->e).animForceRestart = 0;
    q->stopTimer = 0;
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  {
    s32 vx = FixToInt(16, COS(q->rollAngle) * q->speed);
    s32 vz = FixToInt(16, SIN(q->rollAngle) * q->speed);

    if (abs(vx) < abs(vz)) {
      (p->e).mover.delta.z = vz;
    } else {
      (p->e).mover.delta.x = vx;
    }
  }
  if (q->speed <= 0) {
    q->speed = 0;
    if (++q->stopTimer >= 12) {
      (p->e).subStateDone = 1;
      q->speed = 0;
    }
  } else {
    q->speed -= 16;
  }
#else
  INCFUNC("asm/func/GolemLink_StateBrake.inc");
#endif
}

// golem.c の Golem_StateHeardSound の通信対戦版
void GolemLink_StateHeardSound(GolemLink* p, s32 timer) {
  GolemLink* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    (p->e).animForceRestart = 0;
  }
  if (timer > 60) {
    if ((p->e).animForceRestart) {
      (p->e).subStateDone = 1;
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
        Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
        SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
        (p->e).animSpeedDiv = 2;
      } else {
        Enemy_SetAngleToward(&p->e, q->navAgent.waypoint.x, q->navAgent.waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 2, 0);
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
        GolemLink_SetTargetTile(p, &(p->e).unk_204);
      }
    }
  } else if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
}

// golem.c の FUN_081191b8 と同じ
// 930/928 命令, golem.c の FUN_081191b8 の C をそのまま当てただけ, 残差は FUN_081191b8 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081bc2cc(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  if (timer < 20) {
    AuxAnimState* anim = &(p->e).s->aux.anim;
    if (anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
      anim->tick = 0;
    }
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  Enemy_PlayAnim(&p->e, 0);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    s32 tile;
    s32 idx;

    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }

    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }

    if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      u8 angle;

      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        return;
      }
      (p->e).unk_222 &= ~ENEMY222_UNK_2;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
      } else {
        Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 5);
        {
          Vec3* dst = (p->e).pathNodePos;
          PathWalker* walker = &(p->e).pathWalker;

          dst->x = walker->node->x;
          dst->z = walker->node->y;
          dst->y = TileHeightAt(dst);
        }
        (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
        (p->e).pathNodePos->val = 0;
      }
      angle = (p->e).mover.angle;
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
        s32 i;
        u32 a;

        for (i = 0; i < 4; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        if (i >= 4) {
          a = angle;
        }
        (p->e).lookAngle = a;
        (p->e).savedHandlerState = (p->e).handlerState;
        (p->e).savedState = (p->e).state;
        (p->e).savedSubState0 = (p->e).subState0;
        (p->e).savedSubState1 = (p->e).subState1;
        (p->e).savedSubState2 = (p->e).subState2;
        (p->e).lookBaseAngle = angle;
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 6;
      }
      Enemy_StepToFloorEdge(&p->e);
      (p->e).animSpeedDiv = 2;
      return;
    }

    {
      WorldPos tilePos;
      bool8 moved = FALSE;

      {
        s32 x = Mod(tile, gCollisionMap->tiledata->width);
        s32 z = Div(tile, gCollisionMap->tiledata->width);
        MapTileOverride* ov;

        tilePos.x = (x << 8) + 0x80;
        ov = Map_FindTileOverride(tile, 1);
        tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
        tilePos.z = (z << 8) + 0x80;
      }
      {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;

        if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
          s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&(p->e).mover.delta, 8);
            }
            moved = TRUE;
          }
        }
        if (!moved) {
          CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
        }
      }
      if (!moved) {
        (p->e).onRouteFailed(&p->e);
      }
    }
    return;
  }

  (p->e).pendingDelay = 60;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  (p->e).animSpeedDiv = 1;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  {
    NavAgent* agent = (p->e).navAgent;
    WorldPos* pos = &(p->e).mover.pos;
    Vec3* dst = (p->e).pathNodePos;
    bool8 moved = FALSE;

    if (Map_IsPosInAgentIsland(agent, pos, dst)) {
      s32 result = Map_TryFindNavRoute(agent, pos, dst);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&(p->e).mover.delta, 8);
        }
        moved = TRUE;
      }
    }
    if (!moved) {
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    }
    if (moved) {
      (p->e).pathNodePos->val = 1;
    } else {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_081bc2cc.inc");
#endif
}

// golem.c の Golem_StateDamaged と同じ
// 1783/1787 命令, golem.c の Golem_StateDamaged の C をそのまま当てただけ, 残差は Golem_StateDamaged と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_StateDamaged(GolemLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
    if ((p->e).weaponExpMask & 0x80) {
      PlaySound_082406e0(SONG_395);
    }
    (p->e).flags3 = ((p->e).flags3 & ~ENEFLAG3_UNK_8) | ENEFLAG3_UNK_5;
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (!Enemy_StepSlide(&p->e)) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags6, HBATTR_STUN)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerStun, ES_STUN);
    return;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_7);
    (p->e).pathNodePos->val = 0;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  }
#else
  INCFUNC("asm/func/GolemLink_StateDamaged.inc");
#endif
}

// golem.c の FUN_0811aa64 と同じ
void FUN_081bdb78(GolemLink* p) {}

// golem.c の Golem_StateDying と同じ
// 426/425 命令, golem.c の Golem_StateDying の C をそのまま当てただけ, 残差は Golem_StateDying と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081bdb7c(GolemLink* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = 0;
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    PlayGolemSound(&p->e, 1);
    (p->e).hurtbox.flags |= HBF_HIDDEN;
  }
  Enemy_ClearDamage(&p->e);
  if ((p->e).animForceRestart) {
    s32 idx;

    (p->e).subStateDone = 1;
    FUN_080e6658(&p->e);
    if ((p->e).defeatScriptID != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).defeatScriptID, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      Vec3 size;
      WorldPos* pos;
      u8 kind;

      VEC3_SET(size, 80, 60, 60);
      pos = &(p->e).mover.pos;
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x40, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0x80, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
      EmitSmoke(pos, (Random() & 3) + 1, &size, 0xF0, 4, 20, 2, 1);
      kind = (p->e).kind;
      if (kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DARKROOT) {
        PlaySound_082406e0(SE_UNDEAD_EXORCISM);
      }
    }
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Golem_ScatterDebris(&p->e);
    PlayEnemyDeathCry(&p->e);
  }
#else
  INCFUNC("asm/func/FUN_081bdb7c.inc");
#endif
}

// golem.c の Golem_StartChase の通信対戦版
void GolemLink_StartChase(GolemLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_080f3cdc, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    GolemLink_ResumeMove(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// golem.c の FUN_0811d090 と同じ
// 938/898 命令, golem.c の FUN_0811d090 の C をそのまま当てただけ, 残差は FUN_0811d090 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081be01c(GolemLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 60) {
    (p->e).subStateTimer++;
    return;
  }

  Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    bool8 moved;

    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4)) {
      (p->e).pendingDelay = 30;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 2;
      (p->e).animSpeedDiv = 1;
      return;
    }
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      Vec3* dst = (p->e).pathNodePos;

      moved = FALSE;
      if (Map_IsPosInAgentIsland(agent, pos, dst)) {
        s32 result = Map_TryFindNavRoute(agent, pos, dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else {
      (p->e).pathNodePos->val = 1;
    }
    return;
  }

  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
  if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    u8 angle;

    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
      (p->e).pathNodePos->val = 0;
    }
    angle = (p->e).mover.angle;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i < 4; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i >= 4) {
        a = angle;
      }
      (p->e).lookAngle = a;
      (p->e).savedHandlerState = (p->e).handlerState;
      (p->e).savedState = (p->e).state;
      (p->e).savedSubState0 = (p->e).subState0;
      (p->e).savedSubState1 = (p->e).subState1;
      (p->e).savedSubState2 = (p->e).subState2;
      (p->e).lookBaseAngle = angle;
      Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
    Enemy_StepToFloorEdge(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }

  {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
  }
#else
  INCFUNC("asm/func/FUN_081be01c.inc");
#endif
}

// golem.c の Golem_SetHandlerTable3 と同じ
void GolemLink_SetHandlerTable3(GolemLink* p) { (p->e).handlerTables[3] = (void*)sGolemLinkHandlerTable3; }

// golem.c の Golem_SubRollToTarget の通信対戦版
void GolemLink_SubRollToTarget(GolemLink* p) {
  GolemLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, GolemLink_StateCurlUp, ES_UNK_36);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).subStateDone = 0;
    q->chargeGauge = 0;
  }
  if (GolemLink_TryChaseHitTarget(p)) {
    return;
  }
  if ((p->e).subStateDone) {
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    (p->e).pathNodePos->val = 0;
    q->stopPhase = 0;
    q->rollTime = 120;
    q->rollFrames = 0;
    q->stopAnimSpeed = 2;
    q->speed = 0;
    q->routeDest = q->targetPos;
    {
      Vec3 pos, d;

      TilePosAtIndex(&pos, (p->e).tileIdx);
      GolemLink_SnapToTileCenter(&pos);
      Vec3_Diff(&d, &(p->e).mover.pos, &pos);
      if (d.x * d.x + d.z * d.z < 48 * 48) {
        GolemLink_RouteTo(q);
      } else {
        (p->e).navAgent->waypoint = pos;
        Vec3_Diff(&d, &pos, &(p->e).mover.pos);
        (p->e).mover.angle = (((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6) << 6;
        q->moveAngle = (p->e).mover.angle;
      }
    }
    Enemy_EnterState(&p->e, GolemLink_StateRoll, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

// golem.c の Golem_SubWindUpAndRoll の通信対戦版
void GolemLink_SubWindUpAndRoll(GolemLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, GolemLink_StateWindUp, ES_UNK_33);
    (p->e).subStateDone = 0;
  }
  if (!GolemLink_TryChaseHitTarget(p)) {
    if ((p->e).subStateDone) {
      Enemy_EnterState(&p->e, GolemLink_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// golem.c の Golem_SubRoll の通信対戦版
// 1603/1762 命令, golem.c の Golem_SubRoll の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH void GolemLink_SubRoll(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  NavAgent* nav;
  s32 tile;
  s32 idx;
  bool8 hidden;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->playRollSound = 1;
  }
  if (GolemLink_TryChaseHitTarget(p)) {
    return;
  }
  if (q->playRollSound == 1 && q->speed == 0) {
    PlayGolemSound(&p->e, 4);
    q->playRollSound = 0;
  }
  GolemLink_Accelerate(p);
  hidden = FALSE;
  if (!IsLinkPlay()) {
    if ((gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE) && !Golem_TestFlags(q, GOLEMFLAG_TARGET_FIXED)) {
      hidden = TRUE;
    }
  } else if ((p->e).playerMover != NULL) {
    idx = (p->e).playerMover->kind < 4 ? (p->e).playerMover->kind : -1;
    if (idx >= 0 && (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE) && !Golem_TestFlags(q, GOLEMFLAG_TARGET_FIXED)) {
      hidden = TRUE;
    }
  }
  if (hidden) {
    q->rollTime -= 30;
    q->rollAngle = q->prevMoveAngle;
    Enemy_ResetState(&q->e, 0, 2, 7);
    Enemy_EnterState(&q->e, GolemLink_StateBrake, ES_UNK_42);
    return;
  }
  nav = (p->e).navAgent;
  if (nav->flags & NAVFLAG_DIRECT) {
    if (GolemLink_MoveAlongNavAxis(p, nav, 24, 24, q->speed)) {
      s16 dx, dz;

      q->routeDest = q->targetPos;
      dx = q->routeDest.x - (p->e).mover.pos.x;
      dz = q->routeDest.z - (p->e).mover.pos.z;
      q->playRollSound = 1;
      if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && dx * dx + dz * dz < 0xFFFF && q->speed >= 200) {
        q->rollTime -= 30;
        q->rollAngle = q->prevMoveAngle;
        Enemy_ResetState(&q->e, 0, 2, 7);
        Enemy_EnterState(&q->e, GolemLink_StateBrake, ES_UNK_42);
        return;
      }
      {
        s32 d = abs(Golem_AngleDiff(ArcTan2_8(dx, dz), q->moveAngle));

        if (d < 16) {
          s32 dir;

          tile = GetCollisionTileIdx(&q->routeDest);
          dir = ((q->moveAngle + 0x20) & 0xFF) >> 6;
          if (GolemLink_ClassifyNextTile(tile, TileAtIndex(tile)->heightStairs & 0xF, dir) == 0) {
            GolemLink_SnapToNextTile(&q->routeDest, dir);
          }
          GolemLink_RouteTo(q);
        } else if (d >= 52 && d <= 76) {
          GolemLink_RouteTo(q);
        }
      }
      if (abs(Golem_AngleDiff(q->prevMoveAngle, q->moveAngle)) >= 32) {
        Golem_TurnOrUncurl(q);
        return;
      }
      {
        s16 px = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
        s16 pz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

        if (px * px + pz * pz < 0xFFFF && q->speed >= 200) {
          if (!IsLinkPlay()) {
            if (!(gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE)) {
              q->chargeGauge = 400;
            }
          } else if ((p->e).playerMover != NULL) {
            idx = (p->e).playerMover->kind < 4 ? (p->e).playerMover->kind : -1;
            if (idx >= 0 && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
              q->chargeGauge = 400;
            }
          }
        }
      }
      q->rollTime -= 30;
      q->rollAngle = q->prevMoveAngle;
      Enemy_ResetState(&q->e, 0, 2, 7);
      Enemy_EnterState(&q->e, GolemLink_StateBrake, ES_UNK_42);
      return;
    }
    if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && (p->e).tileIdx != (p->e).prevTileIdx) {
      q->routeDest = q->targetPos;
      GolemLink_RouteTo(q);
    }
  } else if (!GolemLink_MoveAlongNavAxis(p, nav, 24, 24, q->speed)) {
    if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && (p->e).tileIdx != (p->e).prevTileIdx) {
      q->routeDest = q->targetPos;
      GolemLink_RouteTo(q);
    }
  } else {
    q->routeDest = q->targetPos;
    GolemLink_RouteTo(q);
  }
  if (abs(Golem_AngleDiff(q->prevMoveAngle, q->moveAngle)) >= 32) {
    Golem_TurnOrUncurl(q);
    return;
  }
  if (q->rollTime <= 0) {
    u16 flags3;

    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    flags3 = (p->e).flags3;
    (p->e).flags3 = flags3 & ~ENEFLAG3_UNK_8;
    if (flags3 & ENEFLAG3_UNK_7) {
      (p->e).pendingDelay = 30;
      (p->e).pendingHandler = (p->e).handlerChase;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 12;
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      if (IsLinkPlay()) {
        Mover* m = (p->e).playerMover;

        idx = -1;
        if (m != NULL && m->kind <= 3) {
          idx = m->kind;
        }
        if (m == NULL || idx < 0) {
          (p->e).onRouteFailed(&p->e);
          return;
        }
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      } else {
        tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
        idx = 0;
      }

      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        u8 angle;

        if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          return;
        }
        (p->e).unk_222 &= ~ENEMY222_UNK_2;
        if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
          Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
          Enemy_ResetState(&p->e, 0, 0, 12);
        } else {
          Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
          Enemy_ResetState(&p->e, 0, 0, 5);
          {
            Vec3* dst = (p->e).pathNodePos;
            PathWalker* walker = &(p->e).pathWalker;

            dst->x = walker->node->x;
            dst->z = walker->node->y;
            dst->y = TileHeightAt(dst);
          }
          (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
          (p->e).pathNodePos->val = 0;
        }
        angle = (p->e).mover.angle;
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
          s32 i;
          u32 a;

          for (i = 0; i < 4; i++) {
            a = (Random() & 3) << 6;
            if (a != angle) {
              break;
            }
          }
          if (i >= 4) {
            a = angle;
          }
          (p->e).lookAngle = a;
          (p->e).savedHandlerState = (p->e).handlerState;
          (p->e).savedState = (p->e).state;
          (p->e).savedSubState0 = (p->e).subState0;
          (p->e).savedSubState1 = (p->e).subState1;
          (p->e).savedSubState2 = (p->e).subState2;
          (p->e).lookBaseAngle = angle;
          Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
          Enemy_ResetState(&p->e, 3, 1, 0);
          (p->e).unk_542 = 6;
        }
        Enemy_StepToFloorEdge(&p->e);
        (p->e).animSpeedDiv = 2;
        return;
      }

      {
        WorldPos tilePos;
        bool8 moved = FALSE;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              moved = TRUE;
            }
          }
          if (!moved) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!moved) {
          (p->e).onRouteFailed(&p->e);
          return;
        }
        (p->e).animSpeedDiv = 2;
      }
    } else {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      (p->e).animSpeedDiv = 1;
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->val = 1;
      if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
    }
  }
  q->rollFrames++;
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/GolemLink_SubRoll.inc");
#endif
}

// golem.c の Golem_SubDecideCharge と同じ
// 247/249 命令, golem.c の Golem_SubDecideCharge の C をそのまま当てただけ, 残差は Golem_SubDecideCharge と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SubDecideCharge(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
  }
  if (GolemLink_TryChaseHitTarget(p)) {
    return;
  }
  if ((p->e).subStateDone) {
    s32 idx;

    if (!IsLinkPlay()) {
      idx = 0;
    } else if ((q->e).playerMover == NULL) {
      idx = -1;
    } else {
      idx = (q->e).playerMover->kind < 4 ? (q->e).playerMover->kind : -1;
    }
    if ((idx < 0 || !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) && TEST_FLAGS((q->e).flags3, ENEFLAG3_UNK_7)) {
      s32 v = 0x400000 - (q->e).playerDistSq;

      if (v < 0) {
        v = 0;
      }
      q->chargeGauge += v >> 16;
      if (q->chargeGauge > 400) {
        q->chargeGauge = 400;
      }
    }
    if ((q->e).playerMover != NULL) {
      bool8 attack = FALSE;

      if ((q->e).variant == EV_GOLEM_C) {
        if (q->chargeGauge >= 400) {
          attack = TRUE;
        }
      } else if (q->chargeGauge >= 200) {
        attack = TRUE;
      }
      if (attack) {
        attack = (q->e).playerDistSq < (q->e).range0Sq && (u8)Map_HasLineOfSight(&(q->e).mover.pos, &(q->e).playerMover->pos, 10, 256);
      }
      if (attack) {
        Enemy_EnterState(&p->e, GolemLink_StateCharge, ES_UNK_39);
        Enemy_ResetState(&p->e, 0, 2, 4);
        return;
      }
    }
    Enemy_EnterState(&p->e, GolemLink_StateRoll, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/GolemLink_SubDecideCharge.inc");
#endif
}

// golem.c の Golem_SubReturnToRoute と同じ
// 946/953 命令, golem.c の Golem_SubReturnToRoute の C をそのまま当てただけ, 残差は Golem_SubReturnToRoute と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SubReturnToRoute(GolemLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  Enemy_ConsumeSubStateBegun(&p->e);
  if (GolemLink_TryChaseHitTarget(p)) {
    return;
  }
  if (!(p->e).subStateDone) {
    (p->e).subStateTimer++;
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  Map_InitNavAgent((p->e).navAgent, &(p->e).mover.pos);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    if (!IsLinkPlay()) {
      (p->e).playerMover = &gPlayerPtr[0]->mover;
    } else if (!Enemy_TargetNearestLinkPlayer(&p->e)) {
      return;
    }
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }

    if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      u8 angle;

      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        return;
      }
      (p->e).unk_222 &= ~ENEMY222_UNK_2;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
      } else {
        Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 5);
        {
          Vec3* dst = (p->e).pathNodePos;
          PathWalker* walker = &(p->e).pathWalker;

          dst->x = walker->node->x;
          dst->z = walker->node->y;
          dst->y = TileHeightAt(dst);
        }
        (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
        (p->e).pathNodePos->val = 0;
      }
      angle = (p->e).mover.angle;
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
        s32 i;
        u32 a;

        for (i = 0; i < 4; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        if (i >= 4) {
          a = angle;
        }
        (p->e).lookAngle = a;
        (p->e).savedHandlerState = (p->e).handlerState;
        (p->e).savedState = (p->e).state;
        (p->e).savedSubState0 = (p->e).subState0;
        (p->e).savedSubState1 = (p->e).subState1;
        (p->e).savedSubState2 = (p->e).subState2;
        (p->e).lookBaseAngle = angle;
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 6;
      }
      Enemy_StepToFloorEdge(&p->e);
      (p->e).animSpeedDiv = 2;
      return;
    }

    {
      WorldPos tilePos;
      bool8 moved = FALSE;

      {
        s32 x = Mod(tile, gCollisionMap->tiledata->width);
        s32 z = Div(tile, gCollisionMap->tiledata->width);
        MapTileOverride* ov;

        tilePos.x = (x << 8) + 0x80;
        ov = Map_FindTileOverride(tile, 1);
        tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
        tilePos.z = (z << 8) + 0x80;
      }
      {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;

        if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
          s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&(p->e).mover.delta, 8);
            }
            moved = TRUE;
          }
        }
        if (!moved) {
          CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
        }
      }
      if (!moved) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      (p->e).animSpeedDiv = 2;
    }
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  (p->e).animSpeedDiv = 1;
  (p->e).pendingDelay = 60;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  (p->e).pathNodePos->val = 1;
  if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/GolemLink_SubReturnToRoute.inc");
#endif
}

// golem.c の Golem_WaitFacingPlayer の通信対戦版
void GolemLink_WaitFacingPlayer(GolemLink* p) {
  GolemLink* q = (p->e).owner;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if (!GolemLink_TryChaseHitTarget(p)) {
    mover->angle = (p->e).playerAngle;
    if ((p->e).subStateTimer >= 120) {
      Enemy_ResetState(&p->e, 0, 2, 5);
      q->chargeGauge = 0;
    }
    (p->e).subStateTimer++;
  }
}

// golem.c の Golem_SubDash と同じ
// 125/125 命令, golem.c の Golem_SubDash の C をそのまま当てただけ, 残差は Golem_SubDash と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SubDash(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, GolemLink_StateDash, ES_UNK_40);
    (p->e).subStateDone = 0;
    mover->angle = (p->e).playerAngle;
    q->speed = 512;
  }
  if ((p->e).subStateTimer > 30 || (p->e).subStateDone) {
    if (q->rollHitID != 0) {
      (p->e).hitTargetID = q->rollHitID;
      (p->e).unk_618(&p->e);
    }
    Enemy_EnterState(&p->e, GolemLink_StateUncurl, ES_UNK_38);
    Enemy_ResetState(&p->e, 0, 2, 3);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/GolemLink_SubDash.inc");
#endif
}

// golem.c の Golem_SubStopAndReroute の通信対戦版
void GolemLink_SubStopAndReroute(GolemLink* p) {
  GolemLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, GolemLink_StateStopAtTile, ES_UNK_41);
    (p->e).subStateDone = 0;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
  if (!GolemLink_TryChaseHitTarget(p)) {
    if ((p->e).subStateDone) {
      q->routeDest = q->targetPos;
      GolemLink_RouteTo(q);
      Enemy_EnterState(&p->e, GolemLink_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// golem.c の Golem_SubContinueRoll と同じ
// 522/616 命令, golem.c の Golem_SubContinueRoll の C をそのまま当てただけ, 残差は Golem_SubContinueRoll と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SubContinueRoll(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
  }
  if (GolemLink_TryChaseHitTarget(p)) {
    return;
  }
  if ((p->e).subStateDone) {
    s32 idx;
    bool8 attack;

    if (!IsLinkPlay()) {
      idx = 0;
    } else if ((q->e).playerMover == NULL) {
      idx = -1;
    } else {
      idx = (q->e).playerMover->kind < 4 ? (q->e).playerMover->kind : -1;
    }
    if ((idx < 0 || !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) && TEST_FLAGS((q->e).flags3, ENEFLAG3_UNK_7)) {
      s32 v = 0x400000 - (q->e).playerDistSq;

      if (v < 0) {
        v = 0;
      }
      q->chargeGauge += v >> 16;
      if (q->chargeGauge > 400) {
        q->chargeGauge = 400;
      }
    }
    q->rollTime -= 30;
    if (IsLinkPlay()) {
      if ((p->e).playerMover != NULL) {
        idx = (p->e).playerMover->kind < 4 ? (p->e).playerMover->kind : -1;
        if (idx >= 0 && (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
          Enemy_EnterState(&p->e, GolemLink_StateUncurl, ES_UNK_38);
          Enemy_ResetState(&p->e, 0, 2, 3);
          return;
        }
      }
    } else if (gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE) {
      Enemy_EnterState(&p->e, GolemLink_StateUncurl, ES_UNK_38);
      Enemy_ResetState(&p->e, 0, 2, 3);
      return;
    }
    attack = FALSE;
    if ((q->e).playerMover != NULL) {
      if ((q->e).variant == EV_GOLEM_C) {
        if (q->chargeGauge >= 400) {
          attack = TRUE;
        }
      } else if (q->chargeGauge >= 200) {
        attack = TRUE;
      }
      if (attack) {
        attack = (q->e).playerDistSq < (q->e).range0Sq && (u8)Map_HasLineOfSight(&(q->e).mover.pos, &(q->e).playerMover->pos, 10, 256);
      }
    }
    if (attack) {
      Enemy_EnterState(&p->e, GolemLink_StateCharge, ES_UNK_39);
      Enemy_ResetState(&p->e, 0, 2, 4);
    } else if (q->rollTime <= 0) {
      Enemy_EnterState(&p->e, GolemLink_StateUncurl, ES_UNK_38);
      Enemy_ResetState(&p->e, 0, 2, 3);
    } else {
      Vec3 pos, d;

      TilePosAtIndex(&pos, (p->e).tileIdx);
      GolemLink_SnapToTileCenter(&pos);
      Vec3_Diff(&d, &(p->e).mover.pos, &pos);
      if (d.x * d.x + d.z * d.z < 64 * 64) {
        GolemLink_RouteTo(q);
        Enemy_ResetState(&p->e, 0, 2, 6);
        return;
      }
      (p->e).navAgent->waypoint = pos;
      Vec3_Diff(&d, &pos, &(p->e).mover.pos);
      (p->e).mover.angle = (((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6) << 6;
      q->moveAngle = (p->e).mover.angle;
      Enemy_EnterState(&p->e, GolemLink_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/GolemLink_SubContinueRoll.inc");
#endif
}

// golem.c の Golem_SubRestAndResume と同じ
// 783/773 命令, golem.c の Golem_SubRestAndResume の C をそのまま当てただけ, 残差は Golem_SubRestAndResume と同じ形 (1回で打ち切り)
NON_MATCH void GolemLink_SubRestAndResume(GolemLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, GolemLink_StateCurledIdle, ES_UNK_43);
    (p->e).subStateDone = 0;
  }
  if (!(p->e).subStateDone) {
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).pendingDelay = 120;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  } else {
    (p->e).pendingDelay = 120;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  (p->e).animSpeedDiv = 2;
  Enemy_ResetState(&p->e, 3, 1, 0);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    u8 angle;

    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
      (p->e).pathNodePos->val = 0;
    }
    angle = (p->e).mover.angle;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i < 4; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i >= 4) {
        a = angle;
      }
      (p->e).lookAngle = a;
      (p->e).savedHandlerState = (p->e).handlerState;
      (p->e).savedState = (p->e).state;
      (p->e).savedSubState0 = (p->e).subState0;
      (p->e).savedSubState1 = (p->e).subState1;
      (p->e).savedSubState2 = (p->e).subState2;
      (p->e).lookBaseAngle = angle;
      Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
    Enemy_StepToFloorEdge(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }

  {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
  }
#else
  INCFUNC("asm/func/GolemLink_SubRestAndResume.inc");
#endif
}

// golem.c の Golem_SetHandlerTable4 と同じ
void GolemLink_SetHandlerTable4(GolemLink* p) { (p->e).handlerTables[4] = (void*)sGolemLinkHandlerTable4; }

// mummy.c の Mummy_StateBurning と同じ形, 焼かれている間アニメ 1 を流し, 燃え尽きたら GolemLink_StateBurnRecover へ移る
// 121/120 命令, Mummy_StateBurning (一致済み) と同じ形, 原典は &animSpeedDiv を r8 に持ち越し 0 を r7 に先に置く, animSpeedDiv の inline・番地のローカル化は試済
NON_MATCH void GolemLink_StateBurning(GolemLink* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_4);
  }
  Enemy_PlayAnim(&p->e, 1);
  (p->e).animSpeedDiv = 4;
  if ((p->e).burnTimer == 0) {
    (p->e).subStateDone = 1;
    Enemy_PlayAnim(&p->e, 6);
    (p->e).unk_494 = 32;
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, GolemLink_StateBurnRecover, ES_UNK_19);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/GolemLink_StateBurning.inc");
#endif
}

// mummy.c の Mummy_StateBurnRecover と同じ形, 燃え尽きて起き上がるアニメ (7 番) を流し, 終わったら経路を引き直して移動へ戻る
// 281/287 命令, Mummy_StateBurnRecover (NON_MATCH) を元にした下書き, 原典は cmdIdx/tick の 0 を s から2回取り直して書き, 経路の可否を 0/1 に落としてから分岐する (1回で打ち切り)
NON_MATCH void GolemLink_StateBurnRecover(GolemLink* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Enemy_PlayAnim(&p->e, 7);
  }
  if (timer < 60) {
    AuxAnimState* anim = &(p->e).s->aux.anim;

    anim->cmdIdx = 0;
    anim->tick = 0;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).stunTimer = 0;
  (p->e).subStateDone = 1;
  Enemy_PlayAnim(&p->e, 0);
  {
    Vec3* target = (p->e).pathNodePos;

    target->x = (p->e).pathWalker.node->x;
    target->z = (p->e).pathWalker.node->y;
    target->y = TileHeightAt(target);
  }
  if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).pathNodePos->val = 1;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
#else
  INCFUNC("asm/func/GolemLink_StateBurnRecover.inc");
#endif
}

// 火が付いた瞬間に跳ねるアニメを流し, flags2 の UNK_4 が立ったらプレイヤーから逃げる経路を引いて GolemLink_StateBurning へ移る
void GolemLink_StateIgnite(GolemLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 variant;
    AuxAnimPlayFlags flags;
    EnemyAuxSprite* s;

    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    s = &(p->e).s->aux;
    AuxAnim_RestartAnim(&s->anim, s->animFile, (p->e).animTable[1].anim, variant, flags);
    (p->e).jumpVel.y = 32;
    (p->e).animForceRestart = 0;
  }
  (p->e).animSpeedDiv = 4;
  Enemy_PlayAnim(&p->e, 1);
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    if (!Enemy_RouteToNearestLinkPlayer(&p->e)) {
      Enemy_PickPathNodeAwayFromPlayer(&p->e);
    }
    Enemy_ResetState(&p->e, 0, 0, 8);
    Enemy_EnterState(&p->e, GolemLink_StateBurning, ES_UNK_19);
  }
}

// golem.c の Golem_StateDying に当たる通信対戦用の関数, 倒れるアニメが終わったら撃破スクリプトを呼んで図鑑に載せ, 足元に攻撃判定を出して消える
void GolemLink_StateDying(GolemLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = FALSE;
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    PlayGolemSound(&p->e, 1);
    (p->e).hurtbox.flags |= HBF_HIDDEN;
  }
  Enemy_ClearDamage(&p->e);
  if ((p->e).animForceRestart) {
    s32 idx;

    (p->e).subStateDone = 1;
    FUN_080e6658(&p->e);
    if ((p->e).defeatScriptID != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).defeatScriptID, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    SpawnAttackBox(&(p->e).mover.pos, 2, 0, 128, 64, 40, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    PlayEnemyDeathCry(&p->e);
  }
}

// mummy.c の Mummy_UpdateBurn と同じ形, 焼かれている間粒子を消していき, 40 フレームおきに hp を減らして尽きたら倒れる状態へ移す
// 512/535 命令, Mummy_UpdateBurn (NON_MATCH) の C から焼ける声を抜いただけ, Mummy_UpdateBurn のメモにある FUN_080f6868 と同じ inline は未適用 (1回で打ち切り)
NON_MATCH void GolemLink_UpdateBurn(GolemLink* p) {
#ifdef NONMATCHING_C
  bool8 dead = Enemy_IsDead(&p->e);
  u16* slots;
  s32 i;
  bool8 show;

  if (dead) {
    return;
  }
  if ((p->e).burnTimer == 0) {
    return;
  }
  if ((p->e).state == ES_UNK_21) {
    (p->e).unk_494 = 32;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_4);
    (p->e).animSpeedDiv = 1;
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    (p->e).burnTimer = dead;
    return;
  }
  if ((p->e).emitter.activeCount > 2) {
    if (Mod((p->e).burnTimer, 16) == 0) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
    }
  } else if (Mod((p->e).burnTimer, 48) == 0) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if ((p->e).unk_460 != 0) {
    for (i = 0; i < (p->e).unk_460; i++) {
      if ((p->e).unk_458[i] == 0) {
        Enemy_FadeParticles(&p->e, 1);
        (p->e).unk_458[i] = 0;
        (p->e).unk_462 &= ~(1 << i);
        (p->e).unk_460--;
      }
      (p->e).unk_458[i]--;
    }
  }
  (p->e).burnTimer--;
  if (Mod((p->e).burnTimer, 40) == 0) {
    (p->e).hurtbox.damage = 1 << (p->e).emitter.activeCount;
    (p->e).unk_48a = (p->e).hurtbox.damage;
    (p->e).hp -= (p->e).hurtbox.damage;
    if (!((p->e).weaponExpMask & 0x4000)) {
      if ((p->e).spriteKind == 0) {
        Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).unk_47c);
      } else {
        (p->e).s->main.spr.pltt = &gObjPlttData[(p->e).unk_47c * 16];
      }
      (p->e).unk_492 = 8;
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_15);
      show = TRUE;
      if (IsLinkPlay() && !((p->e).unk_4a0 & 0x20) && (p->e).unk_4a0 != 0) {
        switch (gLinkSession != NULL ? gLinkSession->playerIdx : -1) {
          case 0: {
            show = (p->e).unk_4a0 == 1;
            break;
          }
          case 1: {
            show = (p->e).unk_4a0 == 2;
            break;
          }
          case 2: {
            show = (p->e).unk_4a0 == 4;
            break;
          }
          case 3: {
            show = (p->e).unk_4a0 == 8;
            break;
          }
        }
      }
      if (show) {
        Vec3 v;

        HUD_ShowEnemyGauge((p->e).mover.id, (p->e).hp, (p->e).maxHp, (p->e).unk_25a, 0);
        Vec3_Clear(&v);
        if ((p->e).unk_48a != 0 || !((p->e).weaponExpMask & 0x4000)) {
          CreateDamageNumber(&(p->e).hurtbox, (p->e).unk_48a, 0, &(p->e).mover.pos, &v, 1);
        }
      }
    }
  }
  if ((p->e).hp <= 0) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerDying, ES_DYING);
    if (IsLinkPlay()) {
      PlayerLink_UpdateBloodSwordOnKill((p->e).unk_4a0, (p->e).weaponExpMask);
    } else {
      if (((p->e).unk_4a0 & 1) && !Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_7)) {
        if (((p->e).kind != ENEK_OCTOPUS || (p->e).variant != 1) && (p->e).kind != ENEK_SKELETON && (p->e).kind != ENEK_SKELETON_A && (p->e).kind != ENEK_SKELETON_F) {
          UNK_948(0) = (UNK_948(0) < 9999) ? (UNK_948(0) + 1) : 9999;
          TOTAL_ENEMY_KILL = (TOTAL_ENEMY_KILL < 9999) ? (TOTAL_ENEMY_KILL + 1) : 9999;
          Enemy_AddKillCount(&p->e);
        }
        AddPlayerExp((p->e).exp);
        Player_AddWeaponExp((p->e).weaponExpMask, (p->e).weaponExp);
      }
      if (!Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_7) && !IsLinkPlay() && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_11)) {
        EnemyRespawnInfo_Add(gMapInitScriptID, (p->e).mover.id);
      }
      (p->e).hurtbox.flags |= HBF_HIDDEN;
    }
    (p->e).burnTimer = 0;
    (p->e).unk_4be = 0;
  }
#else
  INCFUNC("asm/func/GolemLink_UpdateBurn.inc");
#endif
}

// Golem_UpdateTarget の通信対戦版, 狙っているプレイヤーが透明でなければ targetPos をそのタイルに合わせる
void GolemLink_UpdateLinkTarget(GolemLink* p) {
  if (!Golem_TestFlags((p->e).owner, GOLEMFLAG_TARGET_FIXED) && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8)) {
    Mover* m = (p->e).playerMover;

    if (m != NULL) {
      s32 idx = m->kind <= 3 ? m->kind : -1;

      if (idx >= 0 && Player_TestFlag20(gPlayerPtr[idx], PFLAG20_INVISIBLE)) {
        return;
      }
    }
    if ((p->e).playerMover != NULL) {
      GolemLink_TargetPlayerTile(p);
    }
  }
}

// golem.c の Golem_OnDamaged に当たる通信対戦用の関数
// 2795/4040 命令, golem.c の Golem_OnDamaged (粗い下書き) をそのまま当てただけ, 原典は燃焼 (GolemLink_StateIgnite / GolemLink_StateBurning へ移る枝) が加わる, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH bool8 GolemLink_OnDamaged(GolemLink* p) {
#ifdef NONMATCHING_C
  GolemLink* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  SET_FLAGS(q->flags, GOLEMFLAG_UNK_11);
  Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
  PlayGolemSound(&p->e, 1);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_13)) {
    (p->e).mover.angle = (p->e).angle + 128;
    Enemy_PlayAnim(&p->e, 0);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13);
    (p->e).unk_544 = 300;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).pathNodePos->val = 0;
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }

    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
      return TRUE;
    }
    (p->e).onRouteFailed(&p->e);
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_15)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN)) {
      (p->e).unk_214 = (p->e).mover.pos;
      (p->e).unk_20c = (p->e).mover.pos;
      Enemy_EnterState(&p->e, (p->e).handlerStun, ES_STUN);
      Enemy_ResetState(&p->e, 3, 0, 0);
      return TRUE;
    }
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      if ((p->e).weaponExpMask & 0x80) {
        q->shakePower = 30;
        q->shakeTimer = 20;
        (p->e).stunTimer = (p->e).stunTime;
        Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
        Enemy_ResetState(&p->e, 3, 0, 0);
        SET_FLAGS((p->e).flags6, HBATTR_STUN);
        CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_0 | ENEFLAG2_UNK_1 | ENEFLAG2_UNK_24);
        (p->e).animSpeedDiv = 1;
        return TRUE;
      }
      if (TEST_FLAGS((p->e).flags6, HBATTR_BLOW | HBATTR_STUN)) {
        (p->e).stunTimer = (p->e).stunTime;
        Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
        Enemy_ResetState(&p->e, 3, 0, 0);
        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
        return TRUE;
      }
      PlayGolemSound(&p->e, 1);
      if ((p->e).playerMover != NULL) {
        GolemLink_TargetPlayerTile(p);
        q->rollTime = 120;
      }
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
      return FALSE;
    }
  }
  if (TEST_FLAGS((p->e).flags6, HBATTR_BLOW | HBATTR_STUN)) {
    (p->e).stunTimer = (p->e).stunTime;
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
    return TRUE;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_27)) {
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
      (p->e).unk_4be = 45;
      (p->e).unk_48d = 65;
      Enemy_PlayAnim(&p->e, 3);
    }
    if ((p->e).playerMover == NULL) {
      return FALSE;
    }
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }

    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return TRUE;
    }
    (p->e).onRouteFailed(&p->e);
    return FALSE;
  } else {
    if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
      (p->e).unk_4be = 45;
      (p->e).unk_48d = 65;
      Enemy_PlayAnim(&p->e, 3);
    }
    if ((p->e).playerMover == NULL) {
      return FALSE;
    }
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).pathNodePos->val = 0;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }

    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 3;
      return TRUE;
    }
    (p->e).onRouteFailed(&p->e);
    return FALSE;
  }
#else
  INCFUNC("asm/func/GolemLink_OnDamaged.inc");
#endif
}

// golem.c の Golem_PreUpdate に当たる通信対戦用の関数
s32 GolemLink_PreUpdate(GolemLink* p) {
  Mover* mover = &(p->e).mover;

  FUN_080fa77c(&p->e);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_6) && FUN_080f9f20(&p->e) && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
    if (!Enemy_RouteToNearestLinkPlayer(&p->e)) {
      Enemy_PickPathNodeAwayFromPlayer(&p->e);
    }
    Enemy_ResetState(&p->e, 0, 0, 8);
    Enemy_EnterState(&p->e, GolemLink_StateBurning, ES_UNK_19);
  }
  GolemLink_UpdateBurn((GolemLink*)mover);  // 原典は p でなく mover を写したレジスタで渡す, p と同じ番地
  p->facing = Angle_ToDir4(mover->angle);
  p->prevMoveAngle = p->moveAngle;
  return 1;
}

// golem.c の Golem_PostUpdate に当たる通信対戦用の関数
s32 GolemLink_PostUpdate(GolemLink* p) {
  GolemLink_UpdateLinkTarget(p);
  GolemLink_ReleaseFixedTarget(p);
  GolemLink_UpdateAtkHitbox(p);
  return 1;
}

// golem.c の Golem_UpdateFrame の通信対戦版
s32 GolemLink_UpdateFrame(GolemLink* p) {
  GolemLink_PreUpdate(p);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_13) || (p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  GolemLink_PostUpdate(p);
  return 1;
}

// golem.c の Golem_Update と同じ
s32 GolemLink_Update(GolemLink* p) {
  Enemy_Update(&p->e);
  return 0;
}

// golem.c の Golem_Destroy と同じ
s32 GolemLink_Destroy(GolemLink* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove(&(p->e).s->aux.spr);
  } else {
    MainSprite_Remove(&(p->e).s->main.spr);
  }
  Free((p->e).s);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).shadowRemoved) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).shadowRemoved = 1;
  }
  if (!(p->e).emitterRemoved) {
    ElementalCondEmitter_Destroy(&(p->e).emitter);
    (p->e).emitterRemoved = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// golem.c の Golem_Init の通信対戦版
// 1605/1781 命令, golem.c の Golem_Init の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH s32 GolemLink_Init(GolemLink* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->flags = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_GOLEM;
  GolemLink_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPR_GOLEM);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_GOLEM);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->spr.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemyMainSprite* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).s = Malloc(sizeof(EnemySprite));
    ClearMemory((p->e).s, sizeof(EnemySprite));
    spr = &(p->e).s->main;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPR_GOLEM);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).flags = 0;
  (p->e).flags2 = 0;
  (p->e).unk_46f = 0;
  (p->e).unk_1bc = 8;
  (p->e).flags5 = VM_GetNamedArgValue('M', 0);
  Vec3_Clear(&pos);
  (p->e).unk_4b6 = 0;
  if (!VM_SeekToNamedArg('r')) {
    (p->e).unk_250 = 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = 0;
    (p->e).prevPathNode = 0;
    (p->e).unk_4b4[(p->e).unk_4b6] = 0;
    (p->e).unk_4b4[(p->e).unk_4b6 ^ 1] = 0;
    onPath = FALSE;
  } else {
    u8 sel;

    (p->e).unk_250 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).prevPathNode = (p->e).unk_252;
    (p->e).unk_4b4[(p->e).unk_4b6] = (p->e).unk_250;
    sel = (p->e).unk_4b6;
    (p->e).unk_4b4[sel ^ 1] = VM_GetPC() != NULL ? VM_GetValue() : (p->e).unk_250;
    Map_GetPathNodePos(&pos, (p->e).unk_250, (p->e).unk_252);
    (p->e).tileIdx = GetCollisionTileIdx(&pos);
    pos.y = TileHeightAt(&pos);
    (p->e).floorY = pos.y;
    onPath = TRUE;
  }

  id = VM_GetNamedArgValue('N', 0);
  if (!VM_SeekToNamedArg('e')) {
    range0 = 48;
    range3 = 64;
  } else {
    range0 = VM_GetPC() != NULL ? VM_GetValue() : 48;
    range3 = VM_GetPC() != NULL ? (u8)VM_GetValue() : 64;
  }
  if (!VM_SeekToNamedArg('n')) {
    range1 = 0;
    (p->e).unk_1fe = 0;
  } else {
    range1 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_1fe = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  range2 = range0;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      (p->e).atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkKnockback[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkIframes[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).chaseTimeMax = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).chaseTimeMax = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  if (VM_GetNamedArgValue('b', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_9);
  }
  (p->e).scriptID = VM_GetNamedArgValue('F', 0);
  (p->e).unk_194 = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('A')) {
    (p->e).maxHp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_546 = (p->e).maxHp >> 1;
    (p->e).power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_187 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_188 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  Enemy_InitHpAndState(&p->e, (p->e).maxHp, hpParam3, hpParam4);
  Enemy_SetRanges(&p->e, 0, range0, range2, range1, range3);
  if (VM_SeekToNamedArg('X')) {
    (p->e).exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).unk_25a = VM_GetNamedArgValue('K', 2);
  if (VM_GetNamedArgValue('H', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  if (VM_GetNamedArgValue('L', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_15);
  }

  Mover_Init(&(p->e).mover, id, &pos, 0, MOVER_ENEMY, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_SALAMANDER) {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_3)) {
    (p->e).unk_1e8 = Div((p->e).range0Sq * 7, 10);
  } else {
    (p->e).unk_1e8 = (p->e).range0Sq;
  }
  (p->e).zoneSource.id = (p->e).mover.id;
  (p->e).zoneSource.pos = &(p->e).mover.pos;
  if (onPath) {
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 513;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 513;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).s->main.spr.plttID = n + 220;
  }

  (p->e).unk_476 = (p->e).plttBase + 2;
  (p->e).unk_478 = (p->e).plttBase;
  GolemLink_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)GolemLink_UpdateFrame;
  (p->e).getMoveSpeed = (void*)GolemLink_GetMoveSpeed;
  (p->e).handlerTurn = GolemLink_StateTurn;
  (p->e).handlerMove = GolemLink_StateMove;
  (p->e).handlerWait = GolemLink_StateWait;
  (p->e).handlerNap = GolemLink_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = GolemLink_StateDamaged;
  (p->e).handlerDying = FUN_081bdb7c;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = GolemLink_StateHeardSound;
  (p->e).unk_584 = GolemLink_StateRespawnWait;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).tryDetectPlayer = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).msgHandlers = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).handlerLookAround = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = FUN_081bdb78;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).onDamaged = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).handlerChase = FUN_080f624c;
  (p->e).handlerStun = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).onReset = (EnemyHandler)GolemLink_OnReset;
  (p->e).unk_5fc = FUN_081b908c;
  (p->e).onAttackRequest = (EnemyHandler)GolemLink_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_081b8988;
  (p->e).onDamaged = (void*)GolemLink_OnDamaged;
  (p->e).unk_1bc = 0;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22 | ENEFLAG_UNK_24);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_27);
  (p->e).hurtbox.flags &= ~HBF_DAMAGE;
  Enemy_InitShadowAndEmitter(&p->e);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).defeatScriptID = VM_GetNamedArgValue('D', 0);
  {
    s32 u = VM_GetNamedArgValue('u', 0);

    (p->e).unk_496[0] = 0x21;
    (p->e).unk_496[1] = 0;
    if (u != 0) {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_18);
      if (u == 2) {
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_18 | ENEFLAG_UNK_19);
      }
    }
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_2)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_13);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_1)) {
    (p->e).zoneID = GetZoneAt(&(p->e).mover.pos);
  } else {
    (p->e).zoneID = gStat->zoneID;
  }
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_6)) {
    (p->e).hurtbox.flags &= ~HBF_ANGLE;
  }
  if (VM_GetNamedArgValue('S', 0) != 0 || gStat->zoneID != (p->e).zoneID) {
    Enemy_Suspend(&p->e, NULL);
  }
  Enemy_PlayAnim(&p->e, 0);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux = &(p->e).s->aux;

    AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  ((GolemLink*)(p->e).owner)->unk_660 = (p->e).unk_1e8;
  Enemy_InitHandlerTables(&p->e);
  GolemLink_SetHandlerTable3(p);
  GolemLink_SetHandlerTable4(p);
  p->stopPhase = 0;
  p->rollTime = 120;
  p->rollFrames = 0;
  p->stopAnimSpeed = 2;
  p->speed = 0;
  p->rollTime = 160;
  p->windUpTime = 0;
  p->unk_658 = 0;
  p->unk_6c7 = 0;
  (p->e).initFlags5 = (p->e).flags5;
  (p->e).initHeightAboveFloor = (p->e).heightAboveFloor;
  (p->e).initFlags = (p->e).flags;
  (p->e).initFlags2 = (p->e).flags2;
  (p->e).initAngle = (p->e).mover.angle;
  (p->e).initSubState0 = (p->e).subState0;
  (p->e).initSubState1 = (p->e).subState1;
  (p->e).initSubState2 = (p->e).subState2;
  (p->e).initHandlerState = (p->e).handlerState;
  (p->e).initState = (p->e).state;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)GolemLink_Update;
  (p->e).handlerDestroy = (EnemyHandler)GolemLink_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/GolemLink_Init.inc");
#endif
}

// golem.c の Golem_Create の通信対戦版
void GolemLink_Create(void) {
  GolemLink* p = Malloc(sizeof(GolemLink));

  if (p != NULL) {
    ClearMemory(p, sizeof(GolemLink));
    if (GolemLink_Init(p) < 0) {
      GolemLink_Destroy(p);
      Free(p);
    }
  }
}
