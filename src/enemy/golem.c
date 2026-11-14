#include "camera.h"
#include "cwolf_target.h"
#include "dust.h"
#include "eff_elemcond.h"
#include "eff_scatter.h"
#include "emote.h"
#include "enemy.h"
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

// Golem.flags (0x65C)
typedef u32 GolemFlags;
#define GOLEMFLAG_UNK_11 (1 << 11)        // 0x00000800, 立っていると次の転がり始めの溜めを省く
#define GOLEMFLAG_TARGET_FIXED (1 << 19)  // 0x00080000, Golem_SetTargetTile で目標を決めた印, 立っている間はプレイヤーの位置で上書きしない

// ENEK_GOLEM (EV_GOLEM_C, EV_GOLEM_S, EV_GOLEM_2, EV_GOLEM_P, EV_GOLEM_4, EV_GOLEM_5)
// 転がって攻撃するが, 壁やゴーレム同士で激突するとダメージを受け気絶する
typedef struct {
  Enemy e;
  u8 unk_654[4];      // 0x654
  u8 unk_658;         // 0x658
  u8 playRollSound;   // 0x659, 1 なら止まっている状態から転がり出すときに音を鳴らす
  u16 unk_65a;        // 0x65A
  GolemFlags flags;   // 0x65C, see GolemFlags
  u32 unk_660;        // 0x660
  u8 unk_664[4];      // 0x664
  u16 rollHitID;      // 0x668, 転がりで当てた相手の HitboxData.id, 突進の終わりに hitTargetID へ渡す
  u8 unk_66a[2];      // 0x66A
  NavAgent navAgent;  // 0x66C, Enemy.navAgent が指す
  Vec3 pathNodePos;   // 0x690, Enemy.pathNodePos が指す
  u8 unk_698[16];     // 0x698
  Vec3 unk_6a8;       // 0x6A8
  u32 unk_6b0;        // 0x6B0
  s16 rollTime;       // 0x6B4, 転がり続けられる残り, 1区間ごとに 30 減り尽きたら丸まりを解く
  s16 speed;          // 0x6B6, 転がる速さ, variant ごとの上限まで加速する (階段の上では上限も加速も下がる)
  u16 stopAnimSpeed;  // 0x6B8, 止まる間のアニメの速さ, animSpeedDiv はこの 1/128
  u16 rollFrames;     // 0x6BA, Golem_SubRoll で転がっているフレーム数
  u16 chargeGauge;    // 0x6BC, プレイヤーに近いほど貯まる (上限 400), クレイは 400, ほかは 200 で突進に移る
  u16 windUpTime;     // 0x6BE, 転がり始めの溜めの長さ, variant ごとに乱数で決まる
  u8 facing;          // 0x6C0, mover.angle の4方向
  u8 stopPhase;       // 0x6C1, Golem_StateStopAtTile の段階, 0: 減速 1: タイルの中心へ寄せる 2: 止まって待つ
  u8 moveAngle;       // 0x6C2, x か z の軸に揃えた進む向き
  u8 stopTimer;       // 0x6C3, 減速して止まってからのフレーム数
  u8 prevMoveAngle;   // 0x6C4, 前のフレームの moveAngle
  u8 rollAngle;       // 0x6C5, 転がる向き, 減速中もこの向きに滑る
  u8 unk_6c6;         // 0x6C6
  u8 unk_6c7;         // 0x6C7
  Vec3 targetPos;     // 0x6C8, 向かう先のタイルの中心
  Vec3 routeDest;     // 0x6D0, Golem_RouteTo で経路を引く先
  Vec3 unk_6d8;       // 0x6D8
  u16 shakePower;     // 0x6E0, Camera_Shake の強さ
  u16 shakeTimer;     // 0x6E2, 0 でない間毎フレーム画面を揺らして減る
} Golem;
static_assert(sizeof(Golem) == 1764);

void FUN_080f3cdc(Enemy* p);
bool8 FUN_080f0a0c(Enemy* p);
bool8 Enemy_TargetNearestLinkPlayer(Enemy* p);
// 丸まるアニメの2コマ目で止めて待つ
void Golem_StateCurledIdle(Golem* p);
s32 FUN_080f8abc(Enemy* p);
void Golem_ScatterDebris(Enemy* p);
void Golem_OnReset(Golem* p);
s32 Map_HasLineOfSight(Vec3* pos, Vec3* target, s32 count, s32 limit);
void Golem_StateCharge(Golem* p, s32 timer);
void Golem_ResumeMove(Golem* p);
// 姿を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Golem_StateRespawn(Golem* p);
void Golem_StateWakeUp(Golem* p, s32 timer);
void Golem_StateWindUp(Golem* p, s32 timer);
void Golem_StateRoll(Golem* p, s32 timer);
void Golem_StateStopAtTile(Golem* p);
void Golem_StateDash(Golem* p, s32 timer);
void Golem_StateUncurl(Golem* p);
void Golem_StateStopAndTurn(Golem* p);
void Golem_StateBrake(Golem* p);
s32 Golem_RouteTo(Golem* p);
void Golem_OnHit(HitboxData* a, HitboxData* b, Golem* p);
void Golem_OnHurt(HitboxData* a, HitboxData* b, Golem* p);
// プレイヤーに気付いて向き直り, 感情アイコンとスクリプトを出して追いかけを始め, 終わったら移動に戻る
void Golem_StartChase(Golem*);
void FUN_0811d090(Golem*);
// プレイヤーの方を向いて丸まり溜めてから, 今のタイルの中心を経て targetPos へ転がり始める
void Golem_SubRollToTarget(Golem*);
// 丸まって溜めてから転がり始める
void Golem_SubWindUpAndRoll(Golem*);
void Golem_SubRoll(Golem*);
void Golem_SubDecideCharge(Golem*);
void Golem_SubReturnToRoute(Golem*);
// プレイヤーの方を向いたまま 120 フレーム待ち, 副状態 (0, 2, 5) へ移る
void Golem_WaitFacingPlayer(Golem*);
void Golem_SubDash(Golem*);
// その場のタイルで止まり, targetPos へ経路を引き直して転がり始める
void Golem_SubStopAndReroute(Golem*);
void Golem_SubContinueRoll(Golem*);
void Golem_SubRestAndResume(Golem*);

static inline bool8 Golem_TestFlags(Golem* p, GolemFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

const STRING_DATA char s_eneinline_08251ff4[] = "../system/eneinline.h";
const STRING_DATA char s_golemcom_c_0825200c[] = "golemcom.c";

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
  p->sleepTimer = 0;
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
  Enemy_ClearPendingState(p, s_eneinline_08251ff4, 2434);
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

// 大きく向きが変わるとき, rollTime を 10 減らして残っていればその場で止まって向き直り, 尽きていれば丸まりを解く
static inline void Golem_TurnOrUncurl(Golem* q) {
  q->rollAngle = q->prevMoveAngle;
  (q->e).mover.angle = q->prevMoveAngle;
  q->rollTime -= 10;
  if (q->rollTime > 0) {
    q->routeDest = (q->e).navAgent->waypoint;
    Enemy_EnterState(&q->e, Golem_StateStopAndTurn, ES_UNK_37);
    (q->e).subState2 = 2;
  } else {
    Enemy_EnterState(&q->e, Golem_StateUncurl, ES_UNK_38);
    (q->e).subState2 = 3;
  }
  (q->e).subStateTimer = 0;
  (q->e).subStateBegun = 1;
}

const u16 sGolemMoveSpeeds[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085AD5F8
const u16 sGolemRollPlayFlags[2] = {0, 4};                             // 0x085AD608

void (*const sGolemHandlerTable3[2])(Golem*) = {
    Golem_StartChase,
    FUN_0811d090,
};  // 0x085AD60C

void (*const sGolemHandlerTable4[10])(Golem*) = {
    Golem_SubRollToTarget,
    Golem_SubRoll,
    Golem_SubDecideCharge,
    Golem_SubReturnToRoute,
    Golem_WaitFacingPlayer,
    Golem_SubDash,
    Golem_SubWindUpAndRoll,
    Golem_SubContinueRoll,
    Golem_SubStopAndReroute,
    Golem_SubRestAndResume,
};  // 0x085AD614

// 経路の通過点へ x か z の長い方の軸に沿ってだけ進む, 範囲内に着いたら TRUE, 向きを変えたフレームは進まずに TRUE
bool8 Golem_MoveAlongNavAxis(Golem* p, NavAgent* nav, u32 rangeX, u32 rangeZ, s32 speed) {
  Golem* q = (p->e).owner;
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

// dir の隣のタイルを高さ height から見て分類する, 0: 進める (同じ高さか向きの合う階段で1段差), 1: 高い (壁で高さが足りる場合も), 2: 低い
s32 Golem_ClassifyNextTile(u32 tileIdx, s32 height, s32 dir) {
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

// dir (0:+x 1:+z 2:-x 3:-z) の隣のタイルの中心へ座標を寄せる
// 残差はマスク定数を r3 に読んでから r1 へ写す 2 命令だけ (37/35), 試済: 0xFFFFFF00 表記, dir を u8
NON_MATCH void Golem_SnapToNextTile(Vec3* pos, s32 dir) {
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
  INCFUNC("asm/func/Golem_SnapToNextTile.inc");
#endif
}

// 座標を各軸ともタイル (256) の中心へ揃える
void Golem_SnapToTileCenter(Vec3* pos) {
  pos->x = (pos->x & ~0xFF) + 0x80;
  pos->y = (pos->y & ~0xFF) + 0x80;
  pos->z = (pos->z & ~0xFF) + 0x80;
}

// routeDest への経路を引き, 通過点が別のタイルなら差の小さい軸を今のタイルの中心に揃えて軸沿いに進ませる, moveAngle を4方向に丸め, 向きが変わるなら止める
// 197/204命令, 原典は e と mover を sb/r8 に置き dx を r7, 経路先のタイル番号を ip に持つ, こちらは mover が r7 で dx が r9, 試済: 成否の枝の向き, タイル番号のローカル, abs を別の文に
NON_MATCH s32 Golem_RouteTo(Golem* p) {
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
  INCFUNC("asm/func/Golem_RouteTo.inc");
#endif
}

void Golem_OnAttackRequest(Golem* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      return;
    }
    Golem_ResumeMove(p);
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
}

// 攻撃の要求で一旦止まり, 追いかけ中でなければ 60 フレーム後に経路移動, 追いかけ中なら 30 フレーム後に追跡へ移るよう予約して, プレイヤーへの経路を引き直す
// 260/278命令, boku.c の FUN_080ff7c0 と同じ形で同じ壁 (原典は &flags3 を r6 に持ち越す), 1回目の下書きで切り上げ
NON_MATCH void FUN_08115874(Golem* p) {
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
  INCFUNC("asm/func/FUN_08115874.inc");
#endif
}

// プレイヤーの足元が歩けるタイルで同じ島にあれば, そのタイルの中心を目標にする
void Golem_TargetPlayerTile(Golem* p) {
  Golem* q = (p->e).owner;

  if (!TEST_FLAGS(GetTileAttrAt(&(p->e).playerMover->pos), TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH) && Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    q->targetPos = (p->e).playerMover->pos;
    Golem_SnapToTileCenter(&q->targetPos);
  }
}

// pos が歩けるタイルで同じ島にあれば, そのタイルの中心を目標にして固定する
void Golem_SetTargetTile(Golem* p, WorldPos* pos) {
  Golem* q = (p->e).owner;

  if (!TEST_FLAGS(GetTileAttrAt(pos), TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH) && Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, pos)) {
    q->targetPos = *pos;
    Golem_SnapToTileCenter(&q->targetPos);
    SET_FLAGS(q->flags, GOLEMFLAG_TARGET_FIXED);
  }
}

// 目標が固定されておらずプレイヤーが見えていれば, プレイヤーの足元を目標にし直す
void Golem_UpdateTarget(Golem* p) {
  if (!Golem_TestFlags((p->e).owner, GOLEMFLAG_TARGET_FIXED) && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8) && !Player_TestFlag20(gPlayerPtr[0], PFLAG20_INVISIBLE) && (p->e).playerMover != NULL) {
    Golem_TargetPlayerTile(p);
  }
}

// 保留中の状態を捨てて副状態 (0, 2, 0) の移動状態へ戻す
void Golem_ResumeMove(Golem* p) {
  Enemy_ClearPendingState(&p->e, s_golemcom_c_0825200c, 536);
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

void Golem_InitAnims(Golem* p) {
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

// 復帰時に作業値を消して経路の次のノードへ向き直り, 待機アニメを流して1コマ送る
// 残差1命令, 原典は p->sprite を r0 に読んでから r5 へ移す (Dog_OnReset / Spider_OnReset / Boku_OnReset と同じ壁)
NON_MATCH void Golem_OnReset(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
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
  INCFUNC("asm/func/Golem_OnReset.inc");
#endif
}

void FUN_08115f78(Golem* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// variant ごとの上限まで speed を上げる, 階段タイルの上では上限も加速も小さい
// 残差は p と tileIdx の r4/r5 入れ替えと 0x256 を pool から読むか 0x1CC から足すかだけ (92/92), 試済: tile のローカル, idx を u32 ローカル, max/accel を s16
NON_MATCH void Golem_Accelerate(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
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
  INCFUNC("asm/func/Golem_Accelerate.inc");
#endif
}

bool8 Golem_TryChaseHitTarget(Golem* p) { return TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) ? (p->e).unk_618(&p->e) : FALSE; }

s32 Golem_GetMoveSpeed(Golem* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  AuxAnimState* a = anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (anim->cmdIdx < 8) {
      return sGolemMoveSpeeds[anim->cmdIdx];
    } else if (anim->cmdIdx >= 8 && anim->cmdIdx < 16) {
      return sGolemMoveSpeeds[a->cmdIdx - 8];
    }
  }
  return 0;
}

void Golem_ReleaseFixedTarget(Golem* p) {
  if ((p->e).state != ES_UNK_9 && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) && (*(u32*)&(p->e).subState0 & 0xFFFFFF) != ENEMY_SUBSTATE(0, 2, 0)) {
    Golem* q = (p->e).owner;

    CLEAR_FLAGS(q->flags, GOLEMFLAG_TARGET_FIXED);
  }
}

void Golem_InitHitboxes(Golem* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Golem_OnHurt, p);
  VEC3_SET(hitSize, 64, 120, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Golem_OnHit, 0, p);
}

// 攻撃判定の組を選び直す, ENEFLAG3_UNK_4 なら2番に炎と引火を足し, ENEFLAG3_UNK_8 なら1番を speed に応じて 1〜2 倍にし, どちらでもなければ0番
// 残差は atkKnockback[1] を読む位置 (rate >> 1 の前か後か) と cwolfNode.flags を &cwolfNode + 4 で書くかの2箇所 (166/166), CWolfTargetNode* を受ける inline で後者は揃う, 試済: hb を枝ごとのローカルに, flags4 を枝ごとに, Div の引数を先に計算, 掛け算の順
NON_MATCH void Golem_UpdateAtkHitbox(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
      HitboxData* hb = &(p->e).hitbox;

      hb->ignoreMask = HIM_5;
      hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_0;
      Hitbox_SetAttack(hb, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2] | HBATTR_INKA | HBATTR_FLAME, (p->e).atkIframes[2]);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_14);
    } else if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      s32 rate = FixToInt(5, q->speed);
      s32 power, knockback;
      HitboxData* hb;

      if (rate > 20) {
        rate = 20;
      } else if (rate < 10) {
        rate = 10;
      }
      power = Div(rate * (p->e).atkPower[1], 10);
      knockback = Div((p->e).atkKnockback[1] * (rate >> 1), 10);
      hb = &(p->e).hitbox;
      hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_9 | HBFLAG_ANGLE | HBFLAG_UNK_0;
      hb->ignoreMask = 0;
      Hitbox_SetAttack(hb, power, knockback, 128, (p->e).atkAttrs[1] | HBATTR_18, (p->e).atkIframes[1]);
      SET_FLAGS((p->e).cwolfNode.flags, 1);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_14);
    } else {
      HitboxData* hb = &(p->e).hitbox;

      hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_0;
      hb->ignoreMask = HIM_4;
      Hitbox_SetAttack(hb, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
#else
  INCFUNC("asm/func/Golem_UpdateAtkHitbox.inc");
#endif
}

// 当たった相手を覚えて溜めゲージを 200 足す, 転がり中は壁張り付きで背を向けた相手には当てず (ゲージだけ満たす), 当てたら相手の多段ヒットを抑えて rollHitID に覚える
// 327/327命令, 残差は a / mover / owner の sb, r7, r8 の割当だけ, 試済: 宣言順, switch の角度を p から読む, 枝の向き
NON_MATCH void Golem_OnHit(HitboxData* a, HitboxData* b, Golem* p) {
#ifdef NONMATCHING_C
  Mover* mover = &(p->e).mover;
  Golem* q = (p->e).owner;
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
  INCFUNC("asm/func/Golem_OnHit.inc");
#endif
}

// 食らい判定, 敵共通の処理だけ
// 752/763命令, 敵共通の Enemy_HandleHurt だけ, Dog_OnHurt / Crow_OnHurt と同じ共通 inline の壁 (a / b のレジスタとノックバック判定の配置)
NON_MATCH void Golem_OnHurt(HitboxData* a, HitboxData* b, Golem* p) {
#ifdef NONMATCHING_C
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Golem_OnHurt.inc");
#endif
}

void Golem_StateMove(Golem* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void Golem_StateWait(Golem* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// 経路ノードの向きへ振り向く, 回る向きの振り向きアニメを流してコマごとに 22 ずつ回し, アニメが終わったら向きが合っていれば止まり合っていなければ状態2へ戻す
// 706/725命令, Dog_StateTurn と同じ形と同じ壁 (原典は p を2本のレジスタに持つ), 振り向きアニメは Golem_PlayTurnAnim, 1回目の下書きで切り上げ
NON_MATCH void Golem_StateTurn(Golem* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 dir;
    u32 target;

    (p->e).mover.angle = Angle_ToDir4((p->e).mover.angle) * 64 - 64;
    dir = Angle_ToDir4((p->e).mover.angle);
    if ((p->e).subState2 != 6 && !Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_10)) {
      target = (p->e).mover.path->node->delay >> 12;
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
    u8 angle = (p->e).mover.angle;

    if (abs(angle - target * 32) < 23) {
      (p->e).mover.angle = target * 32;
    } else if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle = angle + 22;
    } else {
      (p->e).mover.angle = angle - 22;
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
  INCFUNC("asm/func/Golem_StateTurn.inc");
#endif
}

// 姿と影を隠して 27 フレーム待ち, Golem_StateRespawn へ移る
void Golem_StateRespawnWait(Golem* p, s32 timer) {
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnim(&p->e, 7);
    Enemy_EnterState(&p->e, Golem_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// 姿を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Golem_StateRespawn(Golem* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  if ((p->e).animForceRestart) {
    Golem_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

void Golem_StateNap(Golem* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 6);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, Golem_StateWakeUp, ES_UNK_6);
  }
}

void Golem_StateWakeUp(Golem* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// 丸まるアニメの2コマ目で止めて待つ
void Golem_StateCurledIdle(Golem* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    (p->e).animForceRestart = FALSE;
  }
  if (anim->cmdIdx == 1) {
    anim->tick = 0;
  }
}

// 丸まるアニメを流し, 終わったら転がり始めの溜めへ移る
void Golem_StateCurlUp(Golem* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Golem_StateWindUp, ES_UNK_33);
  }
}

// 転がり始めの溜め, 転がりアニメを流しながら speed を 384 まで上げ, windUpTime を過ぎたら音を鳴らして終える
// 301/302命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は高位レジスタを3本使う
NON_MATCH void Golem_StateWindUp(Golem* p, s32 timer) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Golem* r = (p->e).owner;
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
  f = sGolemRollPlayFlags[flags] | flags;
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
  INCFUNC("asm/func/Golem_StateWindUp.inc");
#endif
}

// 転がる状態, 向きに合わせて転がりアニメを流し speed に応じてアニメを速め, 4 フレームごとに後ろへ土煙を出す
// 236/241命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は owner と &spriteKind / &flags3 をスタックに置く (フレーム 0x28, こちらは 0x1C)
NON_MATCH void Golem_StateRoll(Golem* p, s32 timer) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemRollPlayFlags[flags] | flags;
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
  (p->e).animSpeedDiv = q->speed >> 7;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((timer & 3) == 0) {
    Vec3 dir, size;

    dir.x = -(p->e).mover.delta.x, dir.y = 0, dir.z = -(p->e).mover.delta.z;
    VEC3_SET(size, 32, 0, 32);
    DustManager_Spawn(&(p->e).mover.pos, &dir, &size, 1, 3, 4);
  }
#else
  INCFUNC("asm/func/Golem_StateRoll.inc");
#endif
}

// 丸まるアニメを逆に流して丸まりを解く
// Enemy_PlayAnim の展開 (アニメ 7 を逆再生) と同じ壁, 原典は再生部分を inline にしてその後で animForceRestart = 0 を2回書く (129/132), inline にしても r8 に定数 4 を置く形と variant の読み順が残る
NON_MATCH void Golem_StateUncurl(Golem* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 variant;
    AuxAnimPlayFlags flags;
    s32 f;

    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    f = flags | ANIM_PLAY_REVERSE;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s = &(p->e).s->aux;

      (p->e).playingAnim = 7;
      AuxAnim_SetAnim(&s->anim, s->animFile, 7, variant, f);
    } else {
      MainSprite* s = &(p->e).s->main.spr;
      s32 a = variant + 7;
      bool32 same = (p->e).playingAnim == a && (p->e).animForceRestart == 0 && ((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)));

      if (!same) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
        if (f & ANIM_PLAY_XFLIP) {
          MainSprite_SetFlags(s, SPRFLAG_XFLIP);
        } else {
          MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
        }
      }
    }
    (p->e).animForceRestart = 0;
  }
  if ((p->e).animForceRestart) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/Golem_StateUncurl.inc");
#endif
}

// 今のタイルの中で減速して止まり, タイルの中心へ寄せて 16 フレーム待ってから targetPos へ経路を引き直して向き直る
// 530/535命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は &spriteKind / &flags3 をスタックに置く (フレーム 0x34, こちらは 0x28), 1回目の下書きで切り上げ
NON_MATCH void Golem_StateStopAndTurn(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
    (p->e).animForceRestart = 0;
    q->stopPhase = 0;
    q->facing = Angle_ToDir4(q->prevMoveAngle);
    q->routeDest = (p->e).mover.pos;
    Golem_SnapToTileCenter(&q->routeDest);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemRollPlayFlags[flags] | flags;
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
    Golem_RouteTo(q);
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
  INCFUNC("asm/func/Golem_StateStopAndTurn.inc");
#endif
}

// プレイヤーへ突進する転がり, 4 フレームごとに周りへ土煙を散らしながら speed を 384 まで上げる
// 309/311命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は p と &spriteKind をスタックに置く
NON_MATCH void Golem_StateCharge(Golem* p, s32 timer) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
    q->rollHitID = 0;
  }
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemRollPlayFlags[flags] | flags;
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
  INCFUNC("asm/func/Golem_StateCharge.inc");
#endif
}

// 向いた方へ speed で突っ込み, 壁にぶつかったら画面を揺らして破片を散らし, 誰にも当てていなければ 180 フレーム気絶する
// 336/349命令, 原典は mover を r10 に置き, 破片の速度の delta.z / delta.x を ldrsh の後でもう一度 lsls/asrs してから FixToInt の分岐に入る (s16 の中間値がある), 試済: mover のローカル, delta への足し方, ダストを mover 経由に
NON_MATCH void Golem_StateDash(Golem* p, s32 timer) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
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
      (p->e).sleepTimer = 180;
      SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
      Enemy_EnterState(&p->e, (p->e).handlerSleep, ES_SLEEP);
    } else {
      (p->e).subStateDone = 1;
    }
  }
#else
  INCFUNC("asm/func/Golem_StateDash.inc");
#endif
}

// variant ごとの減速で止まり, 止まった所のタイルの中心へ軸沿いに寄せてから 8 フレーム待って終える
// 412/428命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は &spriteKind / &flags3 をスタックに置き高位レジスタを3本使う, 1回目の下書きで切り上げ
NON_MATCH void Golem_StateStopAtTile(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 f;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
    q->stopPhase = 0;
    q->facing = Angle_ToDir4(q->moveAngle);
    q->routeDest = (p->e).mover.pos;
    Golem_SnapToTileCenter(&q->routeDest);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  f = sGolemRollPlayFlags[flags] | flags;
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
  INCFUNC("asm/func/Golem_StateStopAtTile.inc");
#endif
}

// rollAngle の向きに転がったまま speed を 16 ずつ落とし, 止まってから 12 フレームで終える
// 236/247命令, Enemy_PlayAnim の展開 (アニメ 8) と同じ壁, 原典は owner を r8 に置き高位レジスタを3本使う
NON_MATCH void Golem_StateBrake(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 variant;
    AuxAnimPlayFlags flags;
    s32 f;
    u8 angle = (p->e).mover.angle;

    (p->e).mover.angle = q->rollAngle;
    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    (p->e).mover.angle = angle;
    f = sGolemRollPlayFlags[flags] | flags;
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
  INCFUNC("asm/func/Golem_StateBrake.inc");
#endif
}

// 音を聞いて立ち止まり, 60 フレーム後に追いかけ中なら追跡へ, そうでなければ音のした場所を目標にして移動に戻る
void Golem_StateHeardSound(Golem* p, s32 timer) {
  Golem* q = (p->e).owner;
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
        Golem_SetTargetTile(p, &(p->e).unk_204);
      }
    }
  } else if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
}

// 931/928命令, boku.c の FUN_080fc6f4 の下書きから眠りの枝を除き共通の3文を前に出したもの, 後半は FUN_080fe7f4 と同じ形と同じ壁 (状態フィールドのアドレスをスタックに作り置く, フレーム 0x68 / こちら 0x30)
NON_MATCH void FUN_081191b8(Golem* p, s32 timer) {
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
  INCFUNC("asm/func/FUN_081191b8.inc");
#endif
}

// 吹き飛ばされた先へ滑り, アニメが終わったらプレイヤーへ向かうよう経路を引き直す
// 1785/1787命令, Boku_StateDamaged の下書きから煙と眠りの枝を直し追跡の枝の順を入れ替えたもの, プレイヤーへ向かう部分は FUN_080fe7f4 と同じ形を2回展開, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0xD8 前後, こちら 0x94)
NON_MATCH void Golem_StateDamaged(Golem* p) {
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
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_19)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerSleep, ES_SLEEP);
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
  INCFUNC("asm/func/Golem_StateDamaged.inc");
#endif
}

void FUN_0811aa64(Golem* p) {}

// 倒れるアニメが終わったら倒されたスクリプトを呼んで図鑑に載せ, 煙を出して姿を消す
// 426/425命令, 原典は図鑑の EnemyDex_GetEntryIdx で作った &kind をスタックに置いて煙の後の種族判定で読み直す (フレーム 0x44, こちらは 0x40), Boku_StateDying と同じ形, 試済: 種族判定を bool8 の inline に
NON_MATCH void Golem_StateDying(Golem* p) {
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
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
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
  INCFUNC("asm/func/Golem_StateDying.inc");
#endif
}

// hp が残る被弾への反応, 転がり中に weaponExpMask の bit7 の武器で撃たれると画面を揺らして被弾状態へ, そうでなければ向き直ってプレイヤーへの経路を引き直す
// 2798/3640命令の粗い下書き, Boku_OnDamaged の下書きにゴーレム固有の転がり中の枝 (炎で気絶, 振動) を足したもの, 原典はプレイヤーへ向かう部分をもう1回 (unk_658 が 0 のときの非追跡側) 展開している, 1回目の下書きで切り上げ
NON_MATCH bool8 Golem_OnDamaged(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      (p->e).unk_214 = (p->e).mover.pos;
      (p->e).unk_20c = (p->e).mover.pos;
      Enemy_EnterState(&p->e, (p->e).handlerSleep, ES_SLEEP);
      Enemy_ResetState(&p->e, 3, 0, 0);
      return TRUE;
    }
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      if ((p->e).weaponExpMask & 0x80) {
        q->shakePower = 30;
        q->shakeTimer = 20;
        (p->e).sleepTimer = (p->e).sleepTime;
        Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
        Enemy_ResetState(&p->e, 3, 0, 0);
        SET_FLAGS((p->e).flags6, ENEFLAG6_UNK_19);
        CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_0 | ENEFLAG2_UNK_1 | ENEFLAG2_UNK_24);
        (p->e).animSpeedDiv = 1;
        return TRUE;
      }
      if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
        (p->e).sleepTimer = (p->e).sleepTime;
        Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
        Enemy_ResetState(&p->e, 3, 0, 0);
        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
        return TRUE;
      }
      PlayGolemSound(&p->e, 1);
      if ((p->e).playerMover != NULL) {
        Golem_TargetPlayerTile(p);
        q->rollTime = 120;
      }
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
      return FALSE;
    }
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
    (p->e).sleepTimer = (p->e).sleepTime;
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
  INCFUNC("asm/func/Golem_OnDamaged.inc");
#endif
}

// プレイヤーに気付いて向き直り, 感情アイコンとスクリプトを出して追いかけを始め, 終わったら移動に戻る
void Golem_StartChase(Golem* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_080f3cdc, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    Golem_ResumeMove(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// 938/898命令, boku.c の FUN_080fe7f4 の下書きをそのまま当てたもの (enedefault.c の FUN_080f12c4 と同じ形), 原典は状態フィールドのアドレスをスタックに作り置く, 1回目の下書きで切り上げ
NON_MATCH void FUN_0811d090(Golem* p) {
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
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
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
  INCFUNC("asm/func/FUN_0811d090.inc");
#endif
}

void Golem_SetHandlerTable3(Golem* p) { (p->e).handlerTables[3] = (void*)sGolemHandlerTable3; }

s32 Golem_PreUpdate(Golem* p) {
  Mover* mover = &(p->e).mover;
  Golem* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && q->unk_65a != 0) {
    q->unk_65a--;
  }
  p->facing = Angle_ToDir4(mover->angle);
  p->prevMoveAngle = p->moveAngle;
  return 1;
}

s32 Golem_PostUpdate(Golem* p) {
  Golem* q = (p->e).owner;

  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_6) && q->shakeTimer != 0) {
    Camera_Shake(q->shakePower);
    q->shakeTimer--;
  }
  Golem_UpdateTarget(p);
  Golem_ReleaseFixedTarget(p);
  Golem_UpdateAtkHitbox(p);
  return 1;
}

// プレイヤーの方を向いて丸まり溜めてから, 今のタイルの中心を経て targetPos へ転がり始める
void Golem_SubRollToTarget(Golem* p) {
  Golem* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Golem_StateCurlUp, ES_UNK_36);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).subStateDone = 0;
    q->chargeGauge = 0;
  }
  if (Golem_TryChaseHitTarget(p)) {
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
      Golem_SnapToTileCenter(&pos);
      Vec3_Diff(&d, &(p->e).mover.pos, &pos);
      if (d.x * d.x + d.z * d.z < 48 * 48) {
        Golem_RouteTo(q);
      } else {
        (p->e).navAgent->waypoint = pos;
        Vec3_Diff(&d, &pos, &(p->e).mover.pos);
        (p->e).mover.angle = (((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6) << 6;
        q->moveAngle = (p->e).mover.angle;
      }
    }
    Enemy_EnterState(&p->e, Golem_StateRoll, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void Golem_SubWindUpAndRoll(Golem* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Golem_StateWindUp, ES_UNK_33);
    (p->e).subStateDone = 0;
  }
  if (!Golem_TryChaseHitTarget(p)) {
    if ((p->e).subStateDone) {
      Enemy_EnterState(&p->e, Golem_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// 転がりの本体, 加速しながら経路を軸沿いに進み, 目標を見失ったり着いたりしたら減速し, 大きく曲がるときは止まって向き直り, rollTime が尽きたら経路を引き直す
// 1605/1762命令の下書き, 角度の差と向き直りは Golem_AngleDiff / Golem_TurnOrUncurl にまとめた (原典は goto で合流させる形), rollTime が尽きた後の経路の引き直しは Golem_SubReturnToRoute と同じ形, 原典は状態フィールドのアドレスをスタックに作り置く, 1回目の下書きで切り上げ
NON_MATCH void Golem_SubRoll(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  NavAgent* nav;
  s32 tile;
  s32 idx;
  bool8 hidden;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->playRollSound = 1;
  }
  if (Golem_TryChaseHitTarget(p)) {
    return;
  }
  if (q->playRollSound == 1 && q->speed == 0) {
    PlayGolemSound(&p->e, 4);
    q->playRollSound = 0;
  }
  Golem_Accelerate(p);
  hidden = FALSE;
  if (!IsLinkPlay()) {
    if ((gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE) && !Golem_TestFlags(q, GOLEMFLAG_TARGET_FIXED)) {
      hidden = TRUE;
    }
  } else if ((p->e).playerMover != NULL) {
    idx = (p->e).playerMover->unk_4 < 4 ? (p->e).playerMover->unk_4 : -1;
    if (idx >= 0 && (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE) && !Golem_TestFlags(q, GOLEMFLAG_TARGET_FIXED)) {
      hidden = TRUE;
    }
  }
  if (hidden) {
    q->rollTime -= 30;
    q->rollAngle = q->prevMoveAngle;
    Enemy_ResetState(&q->e, 0, 2, 7);
    Enemy_EnterState(&q->e, Golem_StateBrake, ES_UNK_42);
    return;
  }
  nav = (p->e).navAgent;
  if (nav->flags & NAVFLAG_DIRECT) {
    if (Golem_MoveAlongNavAxis(p, nav, 24, 24, q->speed)) {
      s16 dx, dz;

      q->routeDest = q->targetPos;
      dx = q->routeDest.x - (p->e).mover.pos.x;
      dz = q->routeDest.z - (p->e).mover.pos.z;
      q->playRollSound = 1;
      if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && dx * dx + dz * dz < 0xFFFF && q->speed >= 200) {
        q->rollTime -= 30;
        q->rollAngle = q->prevMoveAngle;
        Enemy_ResetState(&q->e, 0, 2, 7);
        Enemy_EnterState(&q->e, Golem_StateBrake, ES_UNK_42);
        return;
      }
      {
        s32 d = abs(Golem_AngleDiff(ArcTan2_8(dx, dz), q->moveAngle));

        if (d < 16) {
          s32 dir;

          tile = GetCollisionTileIdx(&q->routeDest);
          dir = ((q->moveAngle + 0x20) & 0xFF) >> 6;
          if (Golem_ClassifyNextTile(tile, TileAtIndex(tile)->heightStairs & 0xF, dir) == 0) {
            Golem_SnapToNextTile(&q->routeDest, dir);
          }
          Golem_RouteTo(q);
        } else if (d >= 52 && d <= 76) {
          Golem_RouteTo(q);
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
            idx = (p->e).playerMover->unk_4 < 4 ? (p->e).playerMover->unk_4 : -1;
            if (idx >= 0 && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
              q->chargeGauge = 400;
            }
          }
        }
      }
      q->rollTime -= 30;
      q->rollAngle = q->prevMoveAngle;
      Enemy_ResetState(&q->e, 0, 2, 7);
      Enemy_EnterState(&q->e, Golem_StateBrake, ES_UNK_42);
      return;
    }
    if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && (p->e).tileIdx != (p->e).prevTileIdx) {
      q->routeDest = q->targetPos;
      Golem_RouteTo(q);
    }
  } else if (!Golem_MoveAlongNavAxis(p, nav, 24, 24, q->speed)) {
    if (abs(Golem_AngleDiff((p->e).playerAngle, q->moveAngle)) < 16 && (p->e).tileIdx != (p->e).prevTileIdx) {
      q->routeDest = q->targetPos;
      Golem_RouteTo(q);
    }
  } else {
    q->routeDest = q->targetPos;
    Golem_RouteTo(q);
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
        if (m != NULL && m->unk_4 <= 3) {
          idx = m->unk_4;
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
  INCFUNC("asm/func/Golem_SubRoll.inc");
#endif
}

// 転がり終えたら, 溜めゲージが満ちてプレイヤーを見通せれば突進へ, そうでなければまた転がる
// 247/249命令, 原典は透明判定とゲージ加算の部分で owner を r3 に写して使い (inline の引数の写し), gPlayerPtr[idx] と gPlayerPtr[0] の判定を1か所に合流させる, 試済: 判定を Golem* / Enemy* を受ける inline に (goto で合流させても写しは出ない), owner を式のまま inline に渡す
NON_MATCH void Golem_SubDecideCharge(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
  }
  if (Golem_TryChaseHitTarget(p)) {
    return;
  }
  if ((p->e).subStateDone) {
    s32 idx;

    if (!IsLinkPlay()) {
      idx = 0;
    } else if ((q->e).playerMover == NULL) {
      idx = -1;
    } else {
      idx = (q->e).playerMover->unk_4 < 4 ? (q->e).playerMover->unk_4 : -1;
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
        Enemy_EnterState(&p->e, Golem_StateCharge, ES_UNK_39);
        Enemy_ResetState(&p->e, 0, 2, 4);
        return;
      }
    }
    Enemy_EnterState(&p->e, Golem_StateRoll, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Golem_SubDecideCharge.inc");
#endif
}

// 転がり終えたら経路を引き直し, 追いかけ中ならプレイヤーの居るタイルへ, そうでなければ経路ノードへ戻るよう予約する
// 947/953命令, 追跡側は boku.c の FUN_080fe7f4 (enedefault.c の FUN_080f12c4) と同じ形と同じ壁, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x5C 前後, こちら 0x38), 1回目の下書きで切り上げ
NON_MATCH void Golem_SubReturnToRoute(Golem* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  Enemy_ConsumeSubStateBegun(&p->e);
  if (Golem_TryChaseHitTarget(p)) {
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
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
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
  INCFUNC("asm/func/Golem_SubReturnToRoute.inc");
#endif
}

// プレイヤーの方を向いたまま 120 フレーム待ち, 副状態 (0, 2, 5) へ移る
void Golem_WaitFacingPlayer(Golem* p) {
  Golem* q = (p->e).owner;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if (!Golem_TryChaseHitTarget(p)) {
    mover->angle = (p->e).playerAngle;
    if ((p->e).subStateTimer >= 120) {
      Enemy_ResetState(&p->e, 0, 2, 5);
      q->chargeGauge = 0;
    }
    (p->e).subStateTimer++;
  }
}

// プレイヤーの方へ速さ 512 で突っ込み, 終わったら当てた相手へ攻撃を通知して丸まりを解く
// 残差は q と mover (p の写し) の r5/r7 入れ替えだけ (125/125), 試済: 宣言順, 条件の向き, rollHitID の判定を inline に (p だけ / p と q)
NON_MATCH void Golem_SubDash(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Golem_StateDash, ES_UNK_40);
    (p->e).subStateDone = 0;
    mover->angle = (p->e).playerAngle;
    q->speed = 512;
  }
  if ((p->e).subStateTimer > 30 || (p->e).subStateDone) {
    if (q->rollHitID != 0) {
      (p->e).hitTargetID = q->rollHitID;
      (p->e).unk_618(&p->e);
    }
    Enemy_EnterState(&p->e, Golem_StateUncurl, ES_UNK_38);
    Enemy_ResetState(&p->e, 0, 2, 3);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Golem_SubDash.inc");
#endif
}

void Golem_SubStopAndReroute(Golem* p) {
  Golem* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Golem_StateStopAtTile, ES_UNK_41);
    (p->e).subStateDone = 0;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
  if (!Golem_TryChaseHitTarget(p)) {
    if ((p->e).subStateDone) {
      q->routeDest = q->targetPos;
      Golem_RouteTo(q);
      Enemy_EnterState(&p->e, Golem_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// 1区間転がり終えるたびに溜めゲージを貯めて rollTime を減らし, 突進できれば突進, rollTime が尽きたら丸まりを解き, 残っていれば次のタイルへ転がり続ける
// 522/616命令, 原典は突進できるかの判定 (Golem_SubDecideCharge と同じ式) を rollTime が尽きたかどうかの両方の枝に1つずつ持つ, それを bool8 の inline にすると 633/616 まで寄る, 試済: 判定を1回にまとめた形 (これ), inline 版
NON_MATCH void Golem_SubContinueRoll(Golem* p) {
#ifdef NONMATCHING_C
  Golem* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).subStateDone = 0;
  }
  if (Golem_TryChaseHitTarget(p)) {
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
      idx = (q->e).playerMover->unk_4 < 4 ? (q->e).playerMover->unk_4 : -1;
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
        idx = (p->e).playerMover->unk_4 < 4 ? (p->e).playerMover->unk_4 : -1;
        if (idx >= 0 && (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
          Enemy_EnterState(&p->e, Golem_StateUncurl, ES_UNK_38);
          Enemy_ResetState(&p->e, 0, 2, 3);
          return;
        }
      }
    } else if (gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE) {
      Enemy_EnterState(&p->e, Golem_StateUncurl, ES_UNK_38);
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
      Enemy_EnterState(&p->e, Golem_StateCharge, ES_UNK_39);
      Enemy_ResetState(&p->e, 0, 2, 4);
    } else if (q->rollTime <= 0) {
      Enemy_EnterState(&p->e, Golem_StateUncurl, ES_UNK_38);
      Enemy_ResetState(&p->e, 0, 2, 3);
    } else {
      Vec3 pos, d;

      TilePosAtIndex(&pos, (p->e).tileIdx);
      Golem_SnapToTileCenter(&pos);
      Vec3_Diff(&d, &(p->e).mover.pos, &pos);
      if (d.x * d.x + d.z * d.z < 64 * 64) {
        Golem_RouteTo(q);
        Enemy_ResetState(&p->e, 0, 2, 6);
        return;
      }
      (p->e).navAgent->waypoint = pos;
      Vec3_Diff(&d, &pos, &(p->e).mover.pos);
      (p->e).mover.angle = (((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6) << 6;
      q->moveAngle = (p->e).mover.angle;
      Enemy_EnterState(&p->e, Golem_StateRoll, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 2, 1);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Golem_SubContinueRoll.inc");
#endif
}

// 丸まったまま止まり, 120 フレーム後に経路移動か追跡を再開するよう予約し, プレイヤーの居るタイルへ経路を引き直す
// 784/773命令, 後半は boku.c の FUN_080fe7f4 (enedefault.c の FUN_080f12c4) と同じ形と同じ壁, 原典は状態フィールドのアドレスをスタックに作り置く, 1回目の下書きで切り上げ
NON_MATCH void Golem_SubRestAndResume(Golem* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Golem_StateCurledIdle, ES_UNK_43);
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
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
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
  INCFUNC("asm/func/Golem_SubRestAndResume.inc");
#endif
}

void Golem_SetHandlerTable4(Golem* p) { (p->e).handlerTables[4] = (void*)sGolemHandlerTable4; }

s32 Golem_UpdateFrame(Golem* p) {
  Golem_PreUpdate(p);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_13) || (p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  Golem_PostUpdate(p);
  return 1;
}

s32 Golem_Update(Golem* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Golem_Destroy(Golem* p) {
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
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1605/1766命令, Bee_Init の下書きを Golem 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 Golem_Init(Golem* p) {
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
  Golem_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_GOLEM);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_GOLEM);
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

  Mover_Init(&(p->e).mover, id, &pos, 0, 4, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_31) {
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
  Golem_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Golem_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Golem_GetMoveSpeed;
  (p->e).handlerTurn = Golem_StateTurn;
  (p->e).handlerMove = Golem_StateMove;
  (p->e).handlerWait = Golem_StateWait;
  (p->e).unk_5c0 = Golem_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Golem_StateDamaged;
  (p->e).handlerDying = Golem_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = Golem_StateHeardSound;
  (p->e).unk_584 = Golem_StateRespawnWait;
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
  (p->e).unk_5e0 = FUN_0811aa64;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).onDamaged = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).handlerChase = FUN_080f624c;
  (p->e).handlerSleep = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).onReset = (EnemyHandler)Golem_OnReset;
  (p->e).unk_5fc = FUN_08115f78;
  (p->e).onAttackRequest = (EnemyHandler)Golem_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_08115874;
  (p->e).onDamaged = (void*)Golem_OnDamaged;
  (p->e).unk_1bc = 0;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22 | ENEFLAG_UNK_24);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_27);
  (p->e).hurtbox.flags &= ~HBFLAG_UNK_0;
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
    (p->e).hurtbox.flags &= ~HBFLAG_ANGLE;
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
  ((Golem*)(p->e).owner)->unk_660 = (p->e).unk_1e8;
  Enemy_InitHandlerTables(&p->e);
  Golem_SetHandlerTable3(p);
  Golem_SetHandlerTable4(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Golem_Update;
  (p->e).handlerDestroy = (EnemyHandler)Golem_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Golem_Init.inc");
#endif
}

void Golem_Create(void) {
  Golem* p = Malloc(sizeof(Golem));

  if (p != NULL) {
    ClearMemory(p, sizeof(Golem));
    if (Golem_Init(p) < 0) {
      Golem_Destroy(p);
      Free(p);
    }
  }
}
