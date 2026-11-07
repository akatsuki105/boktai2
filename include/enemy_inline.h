#ifndef __INCLUDE_ENEMY_INLINE_H__
#define __INCLUDE_ENEMY_INLINE_H__

#include "constants/enemy.h"
#include "enemy.h"
#include "gba/gba.h"
#include "global.h"
#include "macro.h"
#include "types.h"

static inline void Enemy_ResetState(Enemy* p, u8 subState0, u8 subState1, u8 subState2) {
  p->subState0 = subState0;
  p->subState1 = subState1;
  p->subState2 = subState2;
  p->subStateTimer = 0, p->subStateBegun = 1;
}

// 状態ハンドラを差し替えて入場フラグを立てる
static inline void Enemy_EnterState(Enemy* p, void* handler, s32 state) {
  p->stateBegun = TRUE;
  p->subStateDone = 0;
  p->state = state;
  p->handlerState = handler;
  p->stateTimer = 0;
}

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 Enemy_ConsumeStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 下位状態を巻き戻した直後の呼び出しだけ TRUE, 巻き戻しの印を下ろす
static inline bool8 Enemy_ConsumeSubStateBegun(Enemy* p) {
  if (p->subStateBegun) {
    p->subStateBegun = 0;
    return TRUE;
  }
  return FALSE;
}

// 歩きアニメの速さを 64 / animSpeedDiv にする, 怯みなどの印が立っていれば等速に戻す
static inline void Enemy_UpdateWalkAnimSpeed(Enemy* p) {
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    p->animSpeedDiv = 1;
  } else if (p->animSpeedDiv == 0) {
    p->animSpeedDiv = 1;
  }

  if (p->spriteKind == 0) {
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)p->sprite)->anim, Div(64, p->animSpeedDiv));
  } else {
    MainSprite_SetAnimSpeed(&p->sprite->s, (u16)Div(64, p->animSpeedDiv));
  }
}

static inline bool8 Enemy_TestFlag5(Enemy* p, EnemyFlags5 bit) {
  if (p->flags5 & bit) {
    return TRUE;
  }
  return FALSE;
}

// dst への経路を引けたら TRUE, 島の外か経路が無ければ経路追従の印を落として FALSE
static inline bool8 Enemy_TryRouteTo(Enemy* p, NavAgent* agent, WorldPos* pos, WorldPos* dst) {
  s32 result;

  if (Map_IsPosInAgentIsland(agent, pos, dst) && (result = Map_TryFindNavRoute(agent, pos, dst)) != 0) {
    if (result != 2) {
      ClearMemory(&p->mover.delta, 8);
    }
    return TRUE;
  }
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  return FALSE;
}

// Enemy_TryRouteTo と同じ判定, 島の外と経路なしで経路追従の印を落とす出口が2つに分かれる形
static inline bool8 Enemy_TryRouteToEx(Enemy* p, NavAgent* agent, WorldPos* pos, WorldPos* dst) {
  s32 result;

  if (!Map_IsPosInAgentIsland(agent, pos, dst)) {
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    return FALSE;
  }
  result = Map_TryFindNavRoute(agent, pos, dst);
  if (result != 0) {
    if (result != 2) {
      ClearMemory(&p->mover.delta, 8);
    }
    return TRUE;
  }
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  return FALSE;
}

// unk_214 を unk_20c へ残りの 1/4 ずつ (1 フレーム最大 200) 寄せて mover.delta にも足す, 寄せきったら TRUE
static inline bool8 Enemy_StepSlide(Enemy* p) {
  s32 dx = FixToInt(2, p->unk_20c.x - p->unk_214.x);
  s32 dz = FixToInt(2, p->unk_20c.z - p->unk_214.z);

  if (dx > 200) {
    dx = 200;
  } else if (dx < -200) {
    dx = -200;
  }
  if (dz > 200) {
    dz = 200;
  } else if (dz < -200) {
    dz = -200;
  }
  p->mover.delta.x += dx;
  p->mover.delta.z += dz;
  p->unk_214.x += dx;
  p->unk_214.z += dz;
  if (dx == 0 && dz == 0) {
    return TRUE;
  }
  return FALSE;
}

// 追いかけを始める印を立てる
static inline void Enemy_BeginChase(Enemy* p) {
  if (p->kind != ENEK_SPIDER) {
    SET_FLAGS(p->unk_222, ENEMY222_UNK_2);
  }
  SET_FLAGS(p->flags3, ENEFLAG3_UNK_7);
  p->unk_24e = p->unk_24c;
}

// 当たった相手を攻撃対象として覚える
static inline void Enemy_SetHitTarget(Enemy* p, HitboxData* b) {
  if (Enemy_IsDead(p) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      p->hitTargetID = b->id;
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    }
  }
}

#endif  // __INCLUDE_ENEMY_INLINE_H__
