#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy/boku.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

typedef Boku BokuLink;  // ボク(boku.c) の通信対戦用版

void BokuLink_StateWakeUp(BokuLink* p, s32 param_2);

void FUN_081afa4c(BokuLink* p);
void BokuLink_OnReset(BokuLink* p);
void FUN_081b2e3c(BokuLink* p);
void FUN_080f3cdc(Enemy* p);
bool8 FUN_080f0a0c(Enemy* p);
const STRING_DATA char s_eneinline_08252254[] = "../boku/../system/eneinline.h";
const STRING_DATA char s_bokucom_c_08252274[] = "../boku/bokucom.c";

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
  Enemy_ClearPendingState(p, s_eneinline_08252254, 2434);
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

static inline void Boku_ClearUnk65c(Boku* p, u16 bit) { p->unk_65c &= ~bit; }

void FUN_081b1ec4(BokuLink*);
void FUN_081b1fb4(BokuLink*);

void (*const PTR_ARRAY_085adef4[2])(BokuLink*) = {
    FUN_081b1ec4,
    FUN_081b1fb4,
};  // 0x085ADEF4

void FUN_081b282c(BokuLink*);
void FUN_081b2a30(BokuLink*);
void FUN_081b2b2c(BokuLink*);

void (*const PTR_ARRAY_085adefc[18])(BokuLink*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    (void*)FUN_080f12c4,
    FUN_081b282c,
    FUN_081b2a30,
    FUN_081b2b2c,
};  // 0x085ADEFC

void FUN_081b2c30(BokuLink*);

void (*const PTR_ARRAY_085adf44[1])(BokuLink*) = {
    FUN_081b2c30,
};  // 0x085ADF44

const u16 sBokuLinkMoveSpeeds[4] = {336, 336, 0, 180};  // 0x085ADF48

void FUN_081b3bec(BokuLink*);
void FUN_081b3dd4(BokuLink*);
void FUN_081b3ebc(BokuLink*);

void (*const PTR_ARRAY_085adf50[18])(BokuLink*) = {
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
    FUN_081b3bec,
    FUN_081b3dd4,
    FUN_081b3ebc,
};  // 0x085ADF50

// boku.c の Boku_OnHit と同じ
void BokuLink_OnHit(Hitbox* a, Hitbox* b, BokuLink* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// boku.c の Boku_OnHurt と同じ
NAKED void BokuLink_OnHurt(Hitbox* a, Hitbox* b, BokuLink* p) { INCFUNC("asm/func/BokuLink_OnHurt.inc"); }

// boku.c の FUN_080fb4d0 と同じ
NAKED void FUN_081aec90(BokuLink* p) { INCFUNC("asm/func/FUN_081aec90.inc"); }

// boku.c の FUN_080fba28 と同じ
void FUN_081af1e8(BokuLink* p) {
  if ((p->e).stateBegun != 0) {
    (p->e).stateBegun = 0;
  }
}

// boku.c の FUN_080fba40 と同じ
void FUN_081af200(BokuLink* p) {
  if ((p->e).stateBegun != 0) {
    (p->e).stateBegun = 0;
  }
  Enemy_PlayAnim(&p->e, 0);
}

// boku.c の FUN_080fba64 と同じ
NAKED void FUN_081af224(BokuLink* p) { INCFUNC("asm/func/FUN_081af224.inc"); }

// boku.c の Boku_StateNap と同じ
void BokuLink_StateNap(BokuLink* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 8);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN)) {
      (p->e).flags3 |= ENEFLAG3_ASLEEP;
    }
  }
  if (Mod(param_2, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, BokuLink_StateWakeUp, ES_WAKE_UP);
  }
}

// boku.c の Boku_StateWakeUp と同じ
void BokuLink_StateWakeUp(BokuLink* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    Enemy_ClearFlag3(&p->e, ENEFLAG3_ASLEEP);
  }

  if (param_2 == 40) {
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  }

  if ((p->e).animForceRestart != 0 && param_2 > 120) {
    (p->e).subStateDone = 1;
  }
}

// boku.c の FUN_080fc1e4 と同じ
void FUN_081af9a4(BokuLink* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (param_2 > 26) {
    Enemy_PlayAnim(&p->e, 9);
    Enemy_EnterState(&p->e, FUN_081afa4c, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// boku.c の FUN_080fc28c と同じ
void FUN_081afa4c(BokuLink* p) {
  AuxAnimState* anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  anim = &(p->e).s->aux.anim;
  if (anim->cmdIdx == 3 && anim->tick == 4) {
    PlaySound_082406e0(NOISE_UNK_128 | NOISE_HEARTBEAT);
  }
  if ((p->e).animForceRestart) {
    BokuLink_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// boku.c の FUN_080fc4ec と同じ
NAKED void FUN_081afcac(BokuLink* p) { INCFUNC("asm/func/FUN_081afcac.inc"); }

// boku.c の FUN_080fc548 と同じ
void FUN_081afd08(BokuLink* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 12);
    (p->e).animForceRestart = 0;
  }
  if (param_2 > 60) {
    if ((p->e).animForceRestart) {
      (p->e).subStateDone = 1;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
        SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      } else {
        Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
        Enemy_PlayAnim(&p->e, 0);
        Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 7);
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      }
    }
  } else {
    AuxAnimState* anim = &(p->e).s->aux.anim;

    if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
      anim->tick = 0;
    }
  }
}

// boku.c の FUN_080fc6f4 と同じ
NAKED void FUN_081afeb4(BokuLink* p, s32 param_2) { INCFUNC("asm/func/FUN_081afeb4.inc"); }

// boku.c の Boku_StateDamaged と同じ
NAKED void FUN_081b084c(BokuLink* p, s32 param_2) { INCFUNC("asm/func/FUN_081b084c.inc"); }

// boku.c の FUN_080fe1bc の通信対戦版
NAKED void FUN_081b197c(BokuLink* p) { INCFUNC("asm/func/FUN_081b197c.inc"); }

// boku.c の Boku_StateDying と同じ
NAKED void BokuLink_StateDying(BokuLink* p, s32 param_2) { INCFUNC("asm/func/BokuLink_StateDying.inc"); }

// boku.c の FUN_080fe704 と同じ
void FUN_081b1ec4(BokuLink* p) {
  BokuLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_080f3cdc, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    FUN_081b2e3c(p);
    SET_FLAGS(q->unk_65c, 4);
  } else {
    (p->e).subStateTimer++;
  }
}

// boku.c の FUN_080fe7f4 と同じ
NAKED void FUN_081b1fb4(BokuLink* p) { INCFUNC("asm/func/FUN_081b1fb4.inc"); }

// boku.c の FUN_080ff05c と同じ
void FUN_081b281c(BokuLink* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085adef4; }

// boku.c の FUN_080ff06c と同じ
void FUN_081b282c(BokuLink* p) {
  BokuLink* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081b197c, ES_UNK_35);
  }
  if (q->timer_670 == 0) {
    if ((p->e).tryDetectPlayer(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
  }
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 6;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 0, 0);
      SET_FLAGS(q->unk_65c, 2);
      return;
    }
  } else {
    if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 16);
    }
  }
  (p->e).subStateTimer++;
}

// boku.c の FUN_080ff270 と同じ
void FUN_081b2a30(BokuLink* p) {
  BokuLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (q->timer_670 == 0) {
    if ((p->e).tryDetectPlayer(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      Boku_ClearUnk65c(q, 1);
      return;
    }
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 15);
  } else {
    (p->e).subStateTimer++;
  }
}

// boku.c の FUN_080ff36c と同じ
void FUN_081b2b2c(BokuLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!(p->e).tryDetectPlayer(&p->e) && !FUN_080f0a0c(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 5);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// boku.c の FUN_080ff45c と同じ
void FUN_081b2c1c(BokuLink* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085adefc; }

// boku.c の FUN_080ff470 と同じ
NAKED void FUN_081b2c30(BokuLink* p) { INCFUNC("asm/func/FUN_081b2c30.inc"); }

// boku.c の FUN_080ff668 と同じ
void FUN_081b2e28(BokuLink* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085adf44; }

// boku.c の FUN_080ff67c と同じ
void FUN_081b2e3c(BokuLink* p) {
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 0, 2, 0);
}

// boku.c の FUN_080ff6e8 と同じ
void FUN_081b2ea8(BokuLink* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      return;
    }
    FUN_081b2e3c(p);
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
}

// boku.c の FUN_080ff7c0 と同じ
NAKED void FUN_081b2f80(BokuLink* p) { INCFUNC("asm/func/FUN_081b2f80.inc"); }

// boku.c の Boku_InitHitboxes と同じ
void BokuLink_InitHitboxes(BokuLink* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, BokuLink_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, BokuLink_OnHit, 0, p);
}

// boku.c の Boku_OnReset と同じ
NAKED void BokuLink_OnReset(BokuLink* p) { INCFUNC("asm/func/BokuLink_OnReset.inc"); }

// boku.c の FUN_080ffc28 と同じ
void FUN_081b33e8(void) {}

// boku.c の Boku_InitAnims と同じ
void BokuLink_InitAnims(BokuLink* p) {
  Enemy_SetAnimEntry(&p->e, 0, 7, 0);
  Enemy_SetAnimEntry(&p->e, 1, 8, 0);
  Enemy_SetAnimEntry(&p->e, 2, 9, 0);
  Enemy_SetAnimEntry(&p->e, 3, 2, 0);
  Enemy_SetAnimEntry(&p->e, 5, 10, 0);
  Enemy_SetAnimEntry(&p->e, 6, 5, 0);
  Enemy_SetAnimEntry(&p->e, 7, 6, 0);
  Enemy_SetAnimEntry(&p->e, 8, 5, 0);
  Enemy_SetAnimEntry(&p->e, 9, 6, 0);
  Enemy_SetAnimEntry(&p->e, 10, 4, 0);
  Enemy_SetAnimEntry(&p->e, 12, 1, 0);
  Enemy_SetAnimEntry(&p->e, 4, 3, 0);
  Enemy_SetAnimEntry(&p->e, 11, 0, 0);
}

// boku.c の Boku_GetMoveSpeed と同じ
s32 BokuLink_GetMoveSpeed(BokuLink* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  AuxAnimState* a = anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (anim->cmdIdx < 4) {
      return sBokuLinkMoveSpeeds[anim->cmdIdx];
    } else if (anim->cmdIdx >= 10 && anim->cmdIdx < 14) {
      return sBokuLinkMoveSpeeds[a->cmdIdx - 10];
    }
  }
  return 0;
}

// boku.c の FUN_080ffd28 と同じ
void FUN_081b34e8(BokuLink* p) {
  BokuLink* q = (p->e).owner;

  if (q->timer_670 != 0) {
    q->timer_670--;
  }
}

// boku.c の Boku_PickRandomPathNode と同じ
void BokuLink_PickRandomPathNode(BokuLink* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// boku.c の Boku_RouteAwayFromPlayer と同じ
NAKED void BokuLink_RouteAwayFromPlayer(BokuLink* p) { INCFUNC("asm/func/BokuLink_RouteAwayFromPlayer.inc"); }

// boku.c の FUN_081000a4 の通信対戦版
NAKED void FUN_081b3864(BokuLink* p) { INCFUNC("asm/func/FUN_081b3864.inc"); }

// boku.c の Boku_InitDelayedScript と同じ
NAKED void BokuLink_InitDelayedScript(BokuLink* p) { INCFUNC("asm/func/BokuLink_InitDelayedScript.inc"); }

// boku.c の Boku_UpdateDelayedScript と同じ
void BokuLink_UpdateDelayedScript(BokuLink* p) {
  BokuLink* q = (p->e).owner;

  if (q->scriptID_658 == 0) {
    return;
  }

  q->unk_65b++;
  if (q->unk_65b < q->unk_65a) {
    return;
  }

  VM_ExecByID(q->scriptID_658, NULL);
  q->scriptID_658 = 0;
  q->unk_65a = 0;
  q->unk_65b = 0;
}

// boku.c の FUN_081019e0 の通信対戦版
NAKED bool32 FUN_081b39e8(BokuLink* p) { INCFUNC("asm/func/FUN_081b39e8.inc"); }

// boku.c の FUN_08101bb4 と同じ
bool32 FUN_081b3be0(BokuLink* p) {
  FUN_081b34e8(p);
  return TRUE;
}

// boku.c の FUN_080ff06c の通信対戦版
NAKED void FUN_081b3bec(BokuLink* p) { INCFUNC("asm/func/FUN_081b3bec.inc"); }

// boku.c の FUN_080ff270 の通信対戦版
NAKED void FUN_081b3dd4(BokuLink* p) { INCFUNC("asm/func/FUN_081b3dd4.inc"); }

// boku.c の FUN_080ff36c の通信対戦版
NAKED void FUN_081b3ebc(BokuLink* p) { INCFUNC("asm/func/FUN_081b3ebc.inc"); }

// boku.c の FUN_080ff45c の通信対戦版, 表を PTR_ARRAY_085adf50 に差し替える
NAKED void FUN_081b3fa0(BokuLink* p) { INCFUNC("asm/func/FUN_081b3fa0.inc"); }

// boku.c の Boku_OnDamaged の通信対戦版
NAKED bool8 BokuLink_OnDamaged(BokuLink* p) { INCFUNC("asm/func/BokuLink_OnDamaged.inc"); }

// boku.c の FUN_080fc6f4 の通信対戦版
NAKED void FUN_081b570c(BokuLink* p, s32 param_2) { INCFUNC("asm/func/FUN_081b570c.inc"); }

// boku.c の Boku_StateDamaged の通信対戦版
NAKED void BokuLink_StateDamaged(BokuLink* p, s32 param_2) { INCFUNC("asm/func/BokuLink_StateDamaged.inc"); }

// boku.c の FUN_08101bc0 と同じ
bool32 FUN_081b71e8(BokuLink* p) {
  FUN_081b39e8(p);

  if (Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_13) || (p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }

  FUN_081b3be0(p);
  return TRUE;
}

// boku.c の Boku_Update と同じ
s32 BokuLink_Update(BokuLink* p) {
  Enemy_Update(&p->e);
  return 0;
}

// boku.c の Boku_Destroy と同じ
s32 BokuLink_Destroy(BokuLink* p) {
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

// boku.c の Boku_Init の通信対戦版
NAKED s32 BokuLink_Init(BokuLink* p) { INCFUNC("asm/func/BokuLink_Init.inc"); }

// boku.c の Boku_Create の通信対戦版
NAKED void BokuLink_Create(void) { INCFUNC("asm/func/BokuLink_Create.inc"); }
