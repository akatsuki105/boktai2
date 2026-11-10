
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "global.h"
#include "link_session.h"
#include "map_inline.h"
#include "player.h"

// enedefault.c と同様にいろんなエネミーから呼ばれる関数群

s32 FUN_08240b98(Vec3* param_1, s8 param_2);
void Enemy_FindReachablePosNear(Enemy* p, Vec3* out, Vec3* target);
s8 FUN_08240dec(s32 x, s32 y, s32 size, u8 mask, u16 moverID, s32 start);

s32 UNUSED FUN_080f9bf8(unknown* p, s32 val) { return val; }

void Enemy_ForgetTarget(Enemy* p) {
  p->unk_21e = 0;
  p->unk_220 = 0;
  p->unk_202 = 0;
  p->playerMover = NULL;
}

// 待ち状態に入り, プレイヤーを見つけないまま 30 フレームで感情アイコンを出し, 60 フレームを過ぎたら経路の目標へ歩き出す
void FUN_080f9c20(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->handlerWait, ES_UNK_0);
    Enemy_ClearFlag(p, ENEFLAG_UNK_7);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    p->animSpeedDiv = 1;
  }
  if (!p->tryDetectPlayer(p)) {
    if (p->subStateTimer == 30) {
      Enemy_SetEmote(p, 0, 2, p->kind);
      Enemy_ForgetTarget(p);
    }
    if (p->subStateTimer > 60) {
      Enemy_ResetState(p, 0, 0, 7);
      Enemy_EnterState(p, p->handlerMove, ES_UNK_1);
      p->pathNodePos->val = 1;
      if (!Enemy_TryRouteToEx(p, p->navAgent, &p->mover.pos, p->pathNodePos)) {
        p->onRouteFailed(p);
      } else if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
        Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
        Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
        p->unk_21c = 0;
        p->unk_21e = 0;
        p->unk_202 = 0;
      }
    } else {
      p->subStateTimer++;
    }
  }
}

// 待ち状態に入り, プレイヤーを見つけないまま 60 フレームを過ぎたら下位状態を 0/0/2 に戻す
void FUN_080f9e34(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->handlerWait, ES_UNK_0);
  }
  if (!p->tryDetectPlayer(p)) {
    if (p->subStateTimer >= 60) {
      Enemy_ResetState(p, 0, 0, 2);
    } else {
      p->subStateTimer++;
    }
  }
}

void FUN_080f9ee0(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }
  if (!p->tryDetectPlayer(p)) {
    p->subStateTimer++;
  }
}

// 残差はレジスタ割当のみ (377/377), 原典は &playerMover を r5, &flags3 を r8 に置きスタックを使わない, こちらは 4 バイト退避する
// idx の三項演算子, Mover* のローカル化, TEST_FLAGS は試済
NON_MATCH s32 FUN_080f9f20(Enemy* p) {
#ifdef NONMATCHING_C
  s32 idx;

  if (Enemy_IsDead(p)) {
    return FALSE;
  }
  if (p->playerMover == NULL) {
    return FALSE;
  }
  idx = p->playerMover->unk_4 <= 3 ? p->playerMover->unk_4 : -1;
  if (idx < 0) {
    return FALSE;
  }
  if (!TEST_FLAGS(gPlayerModes[idx], PMODE_UNK_3)) {
    return FALSE;
  }
  if (p->flags3 & (ENEFLAG3_UNK_15 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_0)) {
    return FALSE;
  }
  if (*(u32*)&p->jumpVel != 0 || p->jumpVel.z != 0) {
    return FALSE;
  }

  Enemy_ClearFlag3(p, ENEFLAG3_UNK_5);
  p->animSpeedDiv = 1;
  Enemy_PlayAnim(p, 0);
  p->playerMover = NULL;
  Enemy_ResetState(p, 3, 1, 0);
  Enemy_EnterState(p, Enemy_WaitPendingState, ES_UNK_14);
  SET_FLAGS(p->flags, ENEFLAG_UNK_4);
  p->pendingDelay = 30;
  p->pendingHandler = p->handlerMove;
  p->pendingSubState0 = 0;
  p->pendingSubState1 = 0;
  p->pendingSubState2 = 7;
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  Map_InitNavAgent(p->navAgent, &p->mover.pos);
  {
    Vec3* dst = p->pathNodePos;
    PathWalker* walker = &p->pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  p->pathNodePos->val = 1;
  if (!Enemy_TryRouteToEx(p, p->navAgent, &p->mover.pos, p->pathNodePos)) {
    p->onRouteFailed(p);
  } else {
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->animSpeedDiv = 1;
    p->unk_222 = 0;
    p->chaseTimer = 0;
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    p->flags &= ~(ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      p->unk_21c = 0;
      p->unk_21e = 0;
      p->unk_202 = 0;
    }
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_10);
    p->unk_542 = 0xFF;
    Enemy_SetEmote(p, 0, 2, p->kind);
    Enemy_PlayAnim(p, 0);
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080f9f20.inc");
#endif
}

// param_3 が今の対象なら TRUE, unk_220 の待ちが残っていれば FALSE, それ以外は pos が標的のプレイヤーより遠くなければ TRUE
s32 FUN_080fa2ac(Enemy* p, Vec3* pos, u32 param_3) {
  Vec3 d;
  s32 distSelf;

  if (p->unk_21e == param_3) {
    return TRUE;
  }
  if (p->unk_220 != 0) {
    return FALSE;
  }
  Vec3_Diff(&d, pos, &p->mover.pos);
  distSelf = d.x * d.x + d.z * d.z;
  if (p->playerMover == NULL) {
    return TRUE;
  }
  Vec3_Diff(&d, &p->playerMover->pos, &p->mover.pos);
  if (d.x * d.x + d.z * d.z < distSelf) {
    return FALSE;
  }
  return TRUE;
}

s32 FUN_080fa354(Enemy* p, Vec3* pos, s8 idx) {
  s32 ret = FUN_08240b98(pos, idx);

  if (ret == 0xB546) {
    Enemy_FindReachablePosNear(p, pos, pos);
  }
  return ret;
}

// 残差はレジスタ割当 (442/443), 原典は slot を r6 に置き戻り値の符号を <<24 のまま比べる
// 前半の条件を bool8 の static inline (if 一列で TRUE/FALSE を返す, 中は TEST_FLAGS) に出すと 443/443 で残差は slot のレジスタだけ, do-while / for / next 変数は試済
NON_MATCH s32 Enemy_TryHeadToSound(Enemy* p) {
#ifdef NONMATCHING_C
  bool32 blocked;
  bool32 found;
  s32 best;
  s32 bestId;
  s8 slot;
  Vec3 cand;
  Vec3 d;

  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_21) || TEST_FLAGS(p->flags2, ENEFLAG2_UNK_2) || TEST_FLAGS(p->flags, ENEFLAG_UNK_8) ||
      TEST_FLAGS(p->flags3, ENEFLAG3_UNK_15 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_0) || TEST_FLAGS(p->flags, ENEFLAG_UNK_27) || p->unk_4be != 0 || p->hurtbox.iframes != 0) {
    blocked = TRUE;
  } else {
    blocked = FALSE;
  }
  if (blocked) {
    return FALSE;
  }

  p->unk_21c = blocked;
  found = FALSE;
  best = 0x7FFFFFFF;
  bestId = 0;
  for (slot = 0; slot <= 7; slot++) {
    s32 id;

    slot = FUN_08240dec(p->mover.pos.x, p->mover.pos.z, p->range2, p->unk_21d, p->mover.id, slot);
    if (slot < 0) {
      break;
    }
    id = FUN_080fa354(p, &cand, slot);
    if (FUN_080fa2ac(p, &cand, id) && Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &cand)) {
      s32 distSq;

      Vec3_Diff(&d, &cand, &p->mover.pos);
      distSq = d.x * d.x + d.z * d.z;
      if (distSq < best) {
        best = distSq;
        p->unk_204 = cand;
        bestId = id;
        found = TRUE;
      }
    }
  }

  if (!found) {
    return FALSE;
  }
  if (p->unk_202 == 0) {
    p->flags &= ~(ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    p->unk_202 = 180;
    Enemy_SetEmote(p, 0, 1, p->kind);
    Enemy_EnterState(p, p->unk_5c8, ES_UNK_9);
    Enemy_ResetState(p, 0, 0, 11);
  }
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
    p->chaseTimer += 300;
    if (p->chaseTimer > p->chaseTimeMax) {
      p->chaseTimer = p->chaseTimeMax;
    }
  }
  p->unk_21e = bestId;
  p->unk_220 = 360;
  {
    Vec3* dst = p->pathNodePos;
    PathWalker* walker = &p->pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  p->pathNodePos->y = p->mover.pos.y;
  p->pathNodePos->val = 0;
  if (!Enemy_TryRouteToEx(p, p->navAgent, &p->mover.pos, &p->unk_204)) {
    p->onRouteFailed(p);
  } else {
    SET_FLAGS(p->flags, ENEFLAG_UNK_4);
    SET_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->animSpeedDiv = 2;
    SET_FLAGS(p->flags2, ENEFLAG2_UNK_24);
    Enemy_TargetNearestPlayer(p, &p->unk_204);
    if (p->unk_614 != NULL) {
      ((EnemyHandler)p->unk_614)(p);
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/Enemy_TryHeadToSound.inc");
#endif
}

void FUN_080fa77c(Enemy* p) {
  if (p->unk_220 != 0) {
    p->unk_220--;
  } else {
    p->unk_21e = 0;
  }
}

// 残差はレジスタ割当 (188/187), 原典は bestIdx もスタックに置きフレームが 4 バイト大きい
// Enemy_TryRouteToEx は一致, pos のローカル化と探索部の static inline 化 (FindNearestLinkPlayer と共通) は試済
NON_MATCH bool8 Enemy_RouteToNearestLinkPlayer(Enemy* p) {
#ifdef NONMATCHING_C
  s32 best = 0x7FFFFFFF;
  s32 bestIdx = -1;
  s32 count = gLinkSession != NULL ? gLinkSession->recordCount : -1;
  s32 i;

  for (i = 0; i < count; i++) {
    if (gPlayerPtr[i] != NULL && !TEST_FLAGS(gPlayerModes[i], PMODE_UNK_3) && !TEST_FLAGS(gPlayerPtr[i]->flag20, PFLAG20_INVISIBLE) && !(GetTileAttrAt(&gPlayerPtr[i]->mover.pos) & (TATTR_FALLDEATH | TATTR_WALL | TATTR_UNK_0))) {
      Vec3 d;
      s32 distSq;

      Vec3_Diff(&d, &gPlayerPtr[i]->mover.pos, &p->mover.pos);
      distSq = d.x * d.x + d.z * d.z;
      if (distSq < best) {
        best = distSq;
        bestIdx = i;
      }
    }
  }
  if (bestIdx < 0) {
    return FALSE;
  }
  Enemy_TryRouteToEx(p, p->navAgent, &p->mover.pos, &gPlayerPtr[bestIdx]->mover.pos);
  return TRUE;
#else
  INCFUNC("asm/func/Enemy_RouteToNearestLinkPlayer.inc");
#endif
}

// 通信対戦の参加者のうち標的にできて pos に一番近い (XZ 平面) プレイヤーの番号を返す, いなければ -1
s32 FindNearestLinkPlayer(Vec3* pos) {
  s32 best = 0x7FFFFFFF;
  s32 bestIdx = -1;
  s32 count = gLinkSession != NULL ? gLinkSession->recordCount : -1;
  s32 i;

  for (i = 0; i < count; i++) {
    if (gPlayerPtr[i] != NULL && !TEST_FLAGS(gPlayerModes[i], PMODE_UNK_3) && !TEST_FLAGS(gPlayerPtr[i]->flag20, PFLAG20_INVISIBLE) && !(GetTileAttrAt(&gPlayerPtr[i]->mover.pos) & (TATTR_FALLDEATH | TATTR_WALL | TATTR_UNK_0))) {
      Vec3 d;
      s32 distSq;

      Vec3_Diff(&d, &gPlayerPtr[i]->mover.pos, pos);
      distSq = d.x * d.x + d.z * d.z;
      if (distSq < best) {
        best = distSq;
        bestIdx = i;
      }
    }
  }
  if (bestIdx < 0) {
    return -1;
  }
  return bestIdx;
}

bool8 Enemy_TargetNearestLinkPlayer(Enemy* p) {
  s32 idx = FindNearestLinkPlayer(&p->mover.pos);
  if (idx < 0) {
    p->onRouteFailed(p);
    return FALSE;
  }
  p->playerMover = &gPlayerPtr[idx]->mover;
  return TRUE;
}

// 残差はレジスタ割当と読み込み順のみ (332/332), 原典は node の先頭 word を walker->node より先に読む
// dir と d を受ける XZ 内積の static inline (Vec3_DotXZ(Vec3* a, Vec3* b)) を通すと命令の形は一致する, 比較の左右入れ替えと RandomNext は試済
NON_MATCH void Enemy_PickPathNodeAwayFromPlayer(Enemy* p) {
#ifdef NONMATCHING_C
  PathWalker* walker = &p->pathWalker;
  u8 nodeIdx = 0;
  bool8 found = FALSE;
  Vec3 dir;
  Vec3 d;
  PathNode* node;
  u8 angle;
  s32 i;

  angle = ArcTan2_8(p->playerMover->pos.x - p->mover.pos.x, p->playerMover->pos.z - p->mover.pos.z);
  dir.x = (COS(angle) * 160) >> 16;
  dir.z = (SIN(angle) * 160) >> 16;
  node = Map_GetPathNodes(walker->path);
  for (i = 0; i < walker->path->nodeCount; i++) {
    d.x = node->x - p->mover.pos.x;
    d.z = node->y - p->mover.pos.z;
    if (dir.x * d.x + dir.z * d.z < 0) {
      if (*(u32*)node != *(u32*)p->pathWalker.node) {
        nodeIdx = i;
        found = TRUE;
        break;
      }
    } else {
      node++;
    }
  }

  if (!found) {
    PathWalker* w = &p->pathWalker;
    u8 next = Mod(Random(), w->path->nodeCount);

    if (next == w->nodeIdx) {
      next = Mod(next + 1, w->path->nodeCount);
    }
    w->nodeIdx = next;
    w->waitTimer = 0;
    w->node = &Map_GetPathNodes(w->path)[w->nodeIdx];
  } else {
    walker->nodeIdx = nodeIdx;
    walker->waitTimer = 0;
    walker->node = node;
  }

  {
    Vec3* dst = p->pathNodePos;
    PathWalker* w = &p->pathWalker;

    dst->x = w->node->x;
    dst->z = w->node->y;
    dst->y = TileHeightAt(dst);
  }
  if (!Enemy_TryRouteToEx(p, p->navAgent, &p->mover.pos, p->pathNodePos)) {
    Enemy_EnterState(p, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(p, 3, 0, 0);
  } else {
    p->pathNodePos->val = 1;
  }
#else
  INCFUNC("asm/func/Enemy_PickPathNodeAwayFromPlayer.inc");
#endif
}
