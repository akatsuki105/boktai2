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

void GolemLink_OnHit(Hitbox* a, Hitbox* b, GolemLink* p);
void GolemLink_OnHurt(Hitbox* a, Hitbox* b, GolemLink* p);

void GolemLink_StateRespawn(GolemLink* p);

void GolemLink_StateWakeUp(GolemLink* p, s32 timer);

void GolemLink_StateWindUp(GolemLink* p, s32 timer);

const STRING_DATA char s_eneinline_08252288[] = "../golem/../system/eneinline.h";  // 0x08252288
const STRING_DATA char s_golemcom_c_082522a8[] = "../golem/golemcom.c";

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
  p->unk_464 = 0;
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
  if (TEST_FLAGS(TileAtIndex(tileIdx)->attr, TATTR_UNK_0 | TATTR_WALL)) {
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
NAKED void GolemLink_SnapToNextTile(Vec3* pos, s32 dir) { INCFUNC("asm/func/GolemLink_SnapToNextTile.inc"); }

// golem.c の Golem_SnapToTileCenter と同じ
void GolemLink_SnapToTileCenter(Vec3* pos) {
  pos->x = (pos->x & ~0xFF) + 0x80;
  pos->y = (pos->y & ~0xFF) + 0x80;
  pos->z = (pos->z & ~0xFF) + 0x80;
}

// golem.c の Golem_RouteTo と同じ
NAKED s32 GolemLink_RouteTo(GolemLink* p) { INCFUNC("asm/func/GolemLink_RouteTo.inc"); }

// golem.c の Golem_OnAttackRequest の通信対戦版
NAKED void GolemLink_OnAttackRequest(GolemLink* p) { INCFUNC("asm/func/GolemLink_OnAttackRequest.inc"); }

// golem.c の FUN_08115874 と同じ
NAKED void FUN_081b8988(GolemLink* p) { INCFUNC("asm/func/FUN_081b8988.inc"); }

// golem.c の Golem_TargetPlayerTile の通信対戦版
NAKED void GolemLink_TargetPlayerTile(GolemLink* p) { INCFUNC("asm/func/GolemLink_TargetPlayerTile.inc"); }

// golem.c の Golem_SetTargetTile の通信対戦版
NAKED void GolemLink_SetTargetTile(GolemLink* p, WorldPos* pos) { INCFUNC("asm/func/GolemLink_SetTargetTile.inc"); }

// golem.c の Golem_UpdateTarget の通信対戦版
NAKED void GolemLink_UpdateTarget(GolemLink* p) { INCFUNC("asm/func/GolemLink_UpdateTarget.inc"); }

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
NAKED void GolemLink_OnReset(GolemLink* p) { INCFUNC("asm/func/GolemLink_OnReset.inc"); }

// golem.c の FUN_08115f78 と同じ
void FUN_081b908c(GolemLink* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// golem.c の Golem_Accelerate と同じ
NAKED void GolemLink_Accelerate(GolemLink* p) { INCFUNC("asm/func/GolemLink_Accelerate.inc"); }

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
NAKED void GolemLink_UpdateAtkHitbox(GolemLink* p) { INCFUNC("asm/func/GolemLink_UpdateAtkHitbox.inc"); }

// golem.c の Golem_OnHit と同じ
NAKED void GolemLink_OnHit(Hitbox* a, Hitbox* b, GolemLink* p) { INCFUNC("asm/func/GolemLink_OnHit.inc"); }

// golem.c の Golem_OnHurt と同じ
NAKED void GolemLink_OnHurt(Hitbox* a, Hitbox* b, GolemLink* p) { INCFUNC("asm/func/GolemLink_OnHurt.inc"); }

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
NAKED void GolemLink_StateTurn(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateTurn.inc"); }

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
NAKED void GolemLink_StateWindUp(GolemLink* p, s32 timer) { INCFUNC("asm/func/GolemLink_StateWindUp.inc"); }

// golem.c の Golem_StateRoll と同じ
NAKED void GolemLink_StateRoll(GolemLink* p, s32 timer) { INCFUNC("asm/func/GolemLink_StateRoll.inc"); }

// golem.c の Golem_StateUncurl と同じ
NAKED void GolemLink_StateUncurl(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateUncurl.inc"); }

// golem.c の Golem_StateStopAndTurn と同じ
NAKED void GolemLink_StateStopAndTurn(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateStopAndTurn.inc"); }

// golem.c の Golem_StateCharge と同じ
NAKED void GolemLink_StateCharge(GolemLink* p, s32 timer) { INCFUNC("asm/func/GolemLink_StateCharge.inc"); }

// golem.c の Golem_StateDash と同じ
NAKED void GolemLink_StateDash(GolemLink* p, s32 timer) { INCFUNC("asm/func/GolemLink_StateDash.inc"); }

// golem.c の Golem_StateStopAtTile と同じ
NAKED void GolemLink_StateStopAtTile(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateStopAtTile.inc"); }

// golem.c の Golem_StateBrake と同じ
NAKED void GolemLink_StateBrake(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateBrake.inc"); }

// golem.c の Golem_StateHeardSound の通信対戦版
NAKED void GolemLink_StateHeardSound(GolemLink* p, s32 timer) { INCFUNC("asm/func/GolemLink_StateHeardSound.inc"); }

// golem.c の FUN_081191b8 と同じ
NAKED void FUN_081bc2cc(GolemLink* p, s32 timer) { INCFUNC("asm/func/FUN_081bc2cc.inc"); }

// golem.c の Golem_StateDamaged と同じ
NAKED void GolemLink_StateDamaged(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateDamaged.inc"); }

// golem.c の FUN_0811aa64 と同じ
void FUN_081bdb78(GolemLink* p) {}

// golem.c の Golem_StateDying と同じ
NAKED void FUN_081bdb7c(GolemLink* p) { INCFUNC("asm/func/FUN_081bdb7c.inc"); }

// golem.c の Golem_StartChase の通信対戦版
NAKED void GolemLink_StartChase(GolemLink* p) { INCFUNC("asm/func/GolemLink_StartChase.inc"); }

// golem.c の FUN_0811d090 と同じ
NAKED void FUN_081be01c(GolemLink* p) { INCFUNC("asm/func/FUN_081be01c.inc"); }

// golem.c の Golem_SetHandlerTable3 と同じ
void GolemLink_SetHandlerTable3(GolemLink* p) { (p->e).handlerTables[3] = (void*)sGolemLinkHandlerTable3; }

// golem.c の Golem_SubRollToTarget の通信対戦版
NAKED void GolemLink_SubRollToTarget(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubRollToTarget.inc"); }

// golem.c の Golem_SubWindUpAndRoll の通信対戦版
NAKED void GolemLink_SubWindUpAndRoll(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubWindUpAndRoll.inc"); }

// golem.c の Golem_SubRoll の通信対戦版
NAKED void GolemLink_SubRoll(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubRoll.inc"); }

// golem.c の Golem_SubDecideCharge と同じ
NAKED void GolemLink_SubDecideCharge(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubDecideCharge.inc"); }

// golem.c の Golem_SubReturnToRoute と同じ
NAKED void GolemLink_SubReturnToRoute(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubReturnToRoute.inc"); }

// golem.c の Golem_WaitFacingPlayer の通信対戦版
NAKED void GolemLink_WaitFacingPlayer(GolemLink* p) { INCFUNC("asm/func/GolemLink_WaitFacingPlayer.inc"); }

// golem.c の Golem_SubDash と同じ
NAKED void GolemLink_SubDash(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubDash.inc"); }

// golem.c の Golem_SubStopAndReroute の通信対戦版
NAKED void GolemLink_SubStopAndReroute(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubStopAndReroute.inc"); }

// golem.c の Golem_SubContinueRoll と同じ
NAKED void GolemLink_SubContinueRoll(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubContinueRoll.inc"); }

// golem.c の Golem_SubRestAndResume と同じ
NAKED void GolemLink_SubRestAndResume(GolemLink* p) { INCFUNC("asm/func/GolemLink_SubRestAndResume.inc"); }

// golem.c の Golem_SetHandlerTable4 と同じ
void GolemLink_SetHandlerTable4(GolemLink* p) { (p->e).handlerTables[4] = (void*)sGolemLinkHandlerTable4; }

NAKED void FUN_081c1790(GolemLink* p) { INCFUNC("asm/func/FUN_081c1790.inc"); }

NAKED void FUN_081c18a8(GolemLink* p, s32 timer) { INCFUNC("asm/func/FUN_081c18a8.inc"); }

NAKED void FUN_081c1b5c(GolemLink* p) { INCFUNC("asm/func/FUN_081c1b5c.inc"); }

// golem.c の Golem_StateDying に当たる通信対戦用の関数
NAKED void GolemLink_StateDying(GolemLink* p) { INCFUNC("asm/func/GolemLink_StateDying.inc"); }

NAKED void FUN_081c1e84(GolemLink* p) { INCFUNC("asm/func/FUN_081c1e84.inc"); }

NAKED void FUN_081c2374(GolemLink* p) { INCFUNC("asm/func/FUN_081c2374.inc"); }

// golem.c の Golem_OnDamaged に当たる通信対戦用の関数
NAKED bool8 GolemLink_OnDamaged(GolemLink* p) { INCFUNC("asm/func/GolemLink_OnDamaged.inc"); }

// golem.c の Golem_PreUpdate に当たる通信対戦用の関数
NAKED s32 GolemLink_PreUpdate(GolemLink* p) { INCFUNC("asm/func/GolemLink_PreUpdate.inc"); }

// golem.c の Golem_PostUpdate に当たる通信対戦用の関数
NAKED s32 GolemLink_PostUpdate(GolemLink* p) { INCFUNC("asm/func/GolemLink_PostUpdate.inc"); }

// golem.c の Golem_UpdateFrame の通信対戦版
NAKED s32 GolemLink_UpdateFrame(GolemLink* p) { INCFUNC("asm/func/GolemLink_UpdateFrame.inc"); }

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
NAKED s32 GolemLink_Init(GolemLink* p) { INCFUNC("asm/func/GolemLink_Init.inc"); }

// golem.c の Golem_Create の通信対戦版
NAKED void GolemLink_Create(void) { INCFUNC("asm/func/GolemLink_Create.inc"); }
