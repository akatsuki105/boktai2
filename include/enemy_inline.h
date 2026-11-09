#ifndef __INCLUDE_ENEMY_INLINE_H__
#define __INCLUDE_ENEMY_INLINE_H__

#include "constants/enemy.h"
#include "enemy.h"
#include "gba/gba.h"
#include "global.h"
#include "macro.h"
#include "player.h"
#include "random.h"
#include "trig.h"
#include "types.h"
#include "vec3.h"

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
    AuxAnim_SetAnimSpeed(&p->s->aux.anim, Div(Q6(1), p->animSpeedDiv));
  } else {
    MainSprite_SetAnimSpeed(&p->s->main.spr, (u16)Div(Q6(1), p->animSpeedDiv));
  }
}

static inline bool8 Enemy_TestFlag5(Enemy* p, EnemyFlags5 bit) {
  if (p->flags5 & bit) {
    return TRUE;
  }
  return FALSE;
}

static inline void Enemy_SetHitInfo(Enemy* p, u32 weakness, u32 attributes) {
  p->weaponExpMask = weakness;
  p->flags6 = attributes;
}

// 攻撃判定 a の ignoreMask から攻撃してきたプレイヤーを覚え, そのプレイヤーへの向きと距離の2乗を求める
static inline void Enemy_RememberAttacker(Enemy* p, HitboxData* a) {
  bool8 found = FALSE;
  u32 mask = a->ignoreMask;

  if (mask & HIM_0) {
    p->playerMover = &gPlayerPtr[0]->mover;
    found = TRUE;
  } else if (mask & HIM_1) {
    p->playerMover = &gPlayerPtr[1]->mover;
    found = TRUE;
  } else if (mask & HIM_2) {
    p->playerMover = &gPlayerPtr[2]->mover;
    found = TRUE;
  } else if (mask & HIM_3) {
    p->playerMover = &gPlayerPtr[3]->mover;
    found = TRUE;
  } else if (mask & HIM_4) {
    p->playerMover = NULL;
    found = TRUE;
  } else if (mask & HIM_5) {
    found = TRUE;
  }
  p->unk_4a0 = mask;
  Enemy_SetHitInfo(p, a->weakness, a->attributes);
  if (found) {
    s32 dx;
    s32 dz;

    if (Enemy_TestFlag5(p, ENEFLAG5_UNK_1)) {
      p->playerMover = &gPlayerPtr[0]->mover;
    } else if (p->playerMover == NULL) {
      return;
    }
    dx = p->playerMover->pos.x - p->mover.pos.x;
    dz = p->playerMover->pos.z - p->mover.pos.z;
    p->playerAngle = ArcTan2_8(dx, dz);
    p->playerDistSq = dx * dx + dz * dz;
  }
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

// 経路の目的地 navAgent->dest の 32 以内に着いていれば TRUE, まだなら目的地を向いて speed ぶん進む
static inline bool8 Enemy_StepToDest(Enemy* p, s32 speed) {
  NavAgent* agent = p->navAgent;
  s16 dx = agent->dest.x - p->mover.pos.x;
  s16 dz = agent->dest.z - p->mover.pos.z;

  if ((dx < 0 ? -dx : dx) <= 32 && (dz < 0 ? -dz : dz) <= 32) {
    return TRUE;
  }
  if (dx != 0 || dz != 0) {
    p->mover.angle = ArcTan2_8(dx, dz);
    p->mover.delta.x += POLAR_X(speed, p->mover.angle);
    p->mover.delta.z += POLAR_Z(speed, p->mover.angle);
  }
  return FALSE;
}

// subState0/1/2 の3つを1語に並べた値, 原典は *(u32*)&subState0 & 0xFFFFFF をこれと比べる
#define ENEMY_SUBSTATE(s0, s1, s2) ((s0) | ((s1) << 8) | ((s2) << 16))

// 通信プレイ中なら TRUE
static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) return TRUE;
  return FALSE;
}

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// 追いかけを始める印を立てる
static inline void Enemy_BeginChase(Enemy* p) {
  if (p->kind != ENEK_SPIDER) {
    SET_FLAGS(p->unk_222, ENEMY222_UNK_2);
  }
  SET_FLAGS(p->flags3, ENEFLAG3_UNK_7);
  p->chaseTimer = p->chaseTimeMax;
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

// 食らい判定の共通処理, 凍結攻撃ならひるみだけ, ダメージ攻撃ならダメージとノックバックを計算して攻撃者を覚える
static inline void Enemy_HandleHurt(HitboxData* a, HitboxData* b, Enemy* p) {
  u32 knockback;

  if (Enemy_IsDead(p)) {
    return;
  }
  if (p->hurtbox.iframes != 0) {
    if (p->unk_48c != 0) {
      b->damage = 0;
      b->hitResult = 0;
    }
    return;
  }
  if (Hitbox_TestFlags(&p->hurtbox, HBFLAG_HIDDEN)) {
    return;
  }
  if (!Hitbox_TestFlags(a, HBFLAG_UNK_0)) {
    if (!Hitbox_HasWeakness(a, 0x4000)) {
      return;
    }
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
      return;
    }
    if (p->unk_488 != 0) {
      return;
    }
    p->unk_488 = 60;
    if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_27)) {
      if (Hitbox_TestFlags(b, HBFLAG_ANGLE) && Hitbox_TestFlags(a, HBFLAG_ANGLE)) {
        s32 d = b->angle - a->angle;

        if (d < 0) {
          d = -d;
        }
        if (d <= 32) {
          p->unk_4be = a->power;
          p->unk_48c = 1;
          p->unk_44e = Div(p->unk_4be, 3);
          Enemy_SetFlag3(p, ENEFLAG3_UNK_13);
          return;
        }
      }
      b->damage = 0;
      p->unk_48a = 0;
      Enemy_RememberAttacker(p, a);
    } else {
      b->damage = 0;
      p->unk_48a = 0;
      Enemy_RememberAttacker(p, a);
    }
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_7)) {
      p->chaseTimer += 300;
      if (p->chaseTimer > p->chaseTimeMax) {
        p->chaseTimer = p->chaseTimeMax;
      }
    }
    p->unk_48c = 1;
    return;
  }

  if (IsLinkPlay()) {
    Hitbox_ApplyDamageAlt(a, b);
  } else {
    Hitbox_ApplyDamage(a, b);
  }
  b->iframes = a->iframes;
  p->unk_48c = b->hitResult;
  if (p->kind == ENEK_BAT || p->kind == ENEK_CROW || p->kind == ENEK_BEE || p->kind == ENEK_GHOST) {
    knockback = a->knockback;
  } else if (Hitbox_TestAttr(a, HBATTR_18)) {
    knockback = a->knockback;
  } else {
    knockback = a->knockback - p->unk_187;
    if ((s32)knockback < 0) {
      knockback = 0;
    }
  }
  b->knockback = knockback;
  if (Enemy_GetFlag3(p, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2)) {
    b->damage <<= 1;
    b->knockback = FixToInt(1, b->knockback);
  }
  if (a->flags & HBFLAG_ANGLE) {
    p->angle = a->angle;
  } else {
    Vec3 diff;

    Vec3_Delta(&diff, &a->pos, &b->pos);
    if (diff.x == 0 && diff.z == 0) {
      p->angle = Random();
    } else {
      p->angle = ArcTan2_8(diff.x, diff.z);
    }
  }
  Enemy_RememberAttacker(p, a);
  if (p->unk_48c != 0 && Enemy_GetFlag3(p, ENEFLAG3_UNK_7)) {
    p->chaseTimer += 300;
    if (p->chaseTimer > p->chaseTimeMax) {
      p->chaseTimer = p->chaseTimeMax;
    }
  }
  if (TestMapFlag(MPF_UNK_10)) {
    b->damage = 0;
    b->knockback = 0;
    p->unk_48a = 0;
    p->unk_48c = 1;
  }
  FUN_080e64e4(p);
  p->unk_48a = b->damage;
  a->damage += p->unk_188;
  SET_FLAGS(p->flags, ENEFLAG_UNK_13);
}

#endif  // __INCLUDE_ENEMY_INLINE_H__
