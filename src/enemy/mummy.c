#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "enemy_target.h"
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

// ENEK_MUMMY(variant: EV_MUMMY, EV_GAST, EV_MUMMY_P)
// 視覚を持たず聴覚のみで敵を感知(その分、聴覚は鋭い), フレイム属性の攻撃を食らうと引火して暴れ回る(それを使って燭台に火をつけさせたりするギミックもある)
typedef u16 MummyFlags;
#define MUMMYFLAG_UNK_8 (1 << 8)             // 0x0100
#define MUMMYFLAG_AVOIDING_BOMB (1 << 10)    // 0x0400
#define MUMMYFLAG_GRAB_WALL_COVER (1 << 11)  // 0x0800
#define MUMMYFLAG_WAITING_BOMBS (1 << 12)    // 0x1000
#define MUMMYFLAG_HEARD_SOUND (1 << 14)      // 0x4000

typedef struct {
  Enemy e;
  u8 unk_654[164];        // 0x654
  u16 bombSpeedMax;       // 0x6F8, '.B[0]=20', 吐く爆弾の速さの上限
  u16 bombFuseTime;       // 0x6FA, '.B[1]=180', 1発目の爆弾の導火線のフレーム数
  u16 spitCooldown;       // 0x6FC, 吐いたあと bombFuseTime + 30 から数え下ろす, 残っている間は離れた相手に吐かない
  u16 floorEndCooldown;   // 0x6FE, 240 から数え下ろし, 残っている間は床の端を探し直さない
  u16 bombAvoidCooldown;  // 0x700
  u16 spitWaitTimer;      // 0x702, 吐いたあと bombFuseTime から数え下ろす待ち
  u32 leapRangeSq;        // 0x704, unk_1e8 の 3/10
  u32 unk_708;            // 0x708, unk_1e8 の写し
  u8 unk_70c[8];          // 0x70C
  u16 unk_714;            // 0x714, range0 の写し
  u8 heardSoundTimer;     // 0x716
  u8 unk_717[3];          // 0x717
  u16 unk_71a;            // 0x71A
  u8 unk_71c[2];          // 0x71C
  MummyFlags flags;       // 0x71E, see MummyFlags
  NavAgent navAgent;      // 0x720, Enemy.navAgent が指す
  Vec3 pathNodePos;       // 0x744, Enemy.pathNodePos が指す
} Mummy;
static_assert(sizeof(Mummy) == 1868);

// playerMover への向きと距離の 2 乗を取り直す, ENEFLAG5_UNK_1 なら1人目のプレイヤーを相手にする
static inline void Enemy_UpdatePlayerVector(Enemy* p) {
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

// 物音を聞き取れない状態なら TRUE
static inline bool8 Enemy_IsDeaf(Enemy* p) {
  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_21) || Enemy_TestFlag2(p, ENEFLAG2_UNK_2) || TEST_FLAGS(p->flags, ENEFLAG_UNK_8) ||
      TEST_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15) || TEST_FLAGS(p->flags, ENEFLAG_UNK_27) || p->unk_4be != 0 || p->hurtbox.iframes != 0) {
    return TRUE;
  }
  return FALSE;
}

// 振り向きアニメ (AuxSprite は 2 番の variant, MainSprite は 2 + variant 番) を流す
static inline void Mummy_PlayTurnAnim(Mummy* p, u32 variant, u32 flags) {
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

static inline void Mummy_SetFlags(Mummy* p, MummyFlags bits) { p->flags |= bits; }
static inline void Mummy_ClearFlags(Mummy* p, MummyFlags bits) { p->flags &= ~bits; }

const STRING_DATA char s_eneinline_08252018[] = "../system/eneinline.h";  // 0x08252018

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
  Enemy_ClearPendingState(p, s_eneinline_08252018, 2434);
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

s32 FUN_080dd250(Vec3* pos);
s32 Mummy_StepBackOneTile(Mummy* p);
void Mummy_SpitBombs(Mummy* p);
void Mummy_SetJumpVelToPlayer(Mummy* p);
void Mummy_ChooseAttack(Mummy* p);
void Mummy_StateWakeUp(Mummy* p, s32 timer);
void Mummy_StateBurnRecover(Mummy* p, s32 timer);
s32 Mummy_GetWalkableNeighbor(Mummy* p, s32 dir);
void Mummy_ClearBurnParticles(Mummy* p);
void* Explosion_CreateDelayed(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, s32 plttOffset, s32 delay);
bool8 Mummy_CanReachPlayerStraight(Mummy* p);
void Mummy_UpdateAtkHitbox(Mummy* p);
void Mummy_StateRespawn(Mummy* p);
void Mummy_OnReset(Mummy* p);
void Mummy_StateSpit(Mummy* p);
void* Entity080dd1f8_Spawn(Vec3* pos, Vec3* vel, Vec3* unk_124, s32 power, s32 knockback, s32 timer, s32 id);
void Mummy_TickSpitTimers(Mummy* p);
s8 FUN_08240dc8(s32 x, s32 y, s32 size, u8 mask, u16 moverID);
void FUN_080e8f20(Enemy* p, s32 param_2);
bool8 Mummy_HearWallCover(Mummy* p, Vec3* pos, u32 id);
void Mummy_SnapToTile(Vec3* pos, u32 id);
bool8 Mummy_RouteToFloorEnd(Mummy* p);
bool8 Mummy_AvoidNearbyBomb(Mummy* p);
bool8 FUN_080eb2a0(Enemy* p);
void FUN_080ce544(u32 param_1, u32 param_2);
void DefeatedEnemyLog_Add(u16 a, u16 b);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, u16 maxHP, u16 cells, s32 flash);
void Enemy_AddKillCount(Enemy* p);
Mover* Enemy_FindVisiblePlayer(Enemy* p);
void Mummy_Explode(Mummy* p);
void FUN_08240cc4(s16 x, s16 z, s16 param_3, s16 param_4, u8 flags);
void Mummy_UpdateBurn(Mummy* p);
void Mummy_TickFloorEndCooldown(Mummy* p);
void Mummy_TickHeardSoundTimer(Mummy* p);
void Mummy_ClearBombWaitFlags(Mummy* p);

void Mummy_StartChase(Mummy*);
void FUN_08125e1c(Mummy*);

void (*const PTR_ARRAY_085ad63c[2])(Mummy*) = {
    Mummy_StartChase,
    FUN_08125e1c,
};  // 0x085AD63C

void Mummy_SubChaseMove(Mummy*);
void Mummy_SubChaseReroute(Mummy*);
void FUN_081266f4(Mummy*);
void Mummy_SubWaitBombsWalk(Mummy*);
void Mummy_SubWaitBombsTurn(Mummy*);
void Mummy_SubWaitBombsIdle(Mummy*);

// clang-format off
void (*const PTR_ARRAY_085ad644[19])(Mummy*) = {
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
    Mummy_SubChaseMove,
    (void*)FUN_080f11d0,
    Mummy_SubChaseReroute,
    FUN_081266f4,
    Mummy_SubWaitBombsWalk,
    Mummy_SubWaitBombsTurn,
    Mummy_SubWaitBombsIdle,
};  // 0x085AD644
// clang-format on

const u16 u16_ARRAY_085ad690[4] = {0, 120, 260, 200};  // 0x085AD690

const u8 sExplodeDelays[4] = {0, 4, 8, 8};  // 0x085AD698, 爆発ごとの遅れのフレーム数

// 爆発の位置のずれ, マミー+ は4つ, ガストは2つ
const s16 sMummyPExplodeX[4] = {-102, 102, 0, 0};  // 0x085AD69C
const s16 sMummyPExplodeZ[4] = {0, 0, 102, -102};  // 0x085AD6A4
const s16 sGastExplodeX[2] = {-48, 48};            // 0x085AD6AC
const s16 sGastExplodeZ[2] = {0, 0};               // 0x085AD6B0

void Mummy_SubLeapAttack(Mummy*);
void Mummy_SubSpitAttack(Mummy*);

void (*const PTR_ARRAY_085ad6b4[2])(Mummy*) = {
    Mummy_SubLeapAttack,
    Mummy_SubSpitAttack,
};  // 0x085AD6B4

// 攻撃が当たった相手を覚える, プレイヤーが壁に張り付いていないか気付いていれば掴み, 引火中のプレイヤーなら自分も燃える被弾を受ける
// 140/148命令, 原典は p を2本のレジスタに持ち, 被弾した相手の Enemy_SetHitTarget を両方の枝で展開する, 1回目の下書きで切り上げ
NON_MATCH void Mummy_OnHit(HitboxData* a, HitboxData* b, Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (b->ignoreMask >= 1 && b->ignoreMask <= 8) {
    if (TEST_FLAGS(q->flags, MUMMYFLAG_GRAB_WALL_COVER) || !Player_TestFlag20(b->owner, PFLAG20_WALL_COVER)) {
      CLEAR_FLAGS(q->flags, MUMMYFLAG_GRAB_WALL_COVER);
      Enemy_SetHitTarget(&p->e, b);
      (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
      b->hitState |= HBHITSTATE_UNK_0;
      if ((p->e).hurtbox.iframes == 0 && Player_TestFlag20(b->owner, PFLAG20_INKA)) {
        (p->e).unk_4a0 = 1;
        (p->e).flags6 = ENEFLAG6_UNK_2;
        (p->e).weaponExpMask = 0;
        (p->e).hurtbox.damage = 1;
        (p->e).unk_48a = 1;
        (p->e).hurtbox.knockback = 1;
        (p->e).hurtbox.iframes = 30;
        (p->e).unk_48c = 4;
      }
    }
  } else {
    Enemy_SetHitTarget(&p->e, b);
  }
#else
  INCFUNC("asm/func/Mummy_OnHit.inc");
#endif
}

// 食らい判定, 敵共通の処理だけ
// 752/763命令, 敵共通の Enemy_HandleHurt だけ, Golem_OnHurt / Dog_OnHurt と同じ共通 inline の壁 (a / b のレジスタとノックバック判定の配置)
NON_MATCH void Mummy_OnHurt(HitboxData* a, HitboxData* b, Mummy* p) {
#ifdef NONMATCHING_C
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Mummy_OnHurt.inc");
#endif
}

void Mummy_StateSpit(Mummy* p) {
  Mummy* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  if (anim->cmdIdx > 2) {
    if (anim->cmdIdx == 4 && anim->tick == 0) {
      Mummy_SpitBombs(p);
    }
  }
  if ((p->e).animForceRestart) {
    q->spitWaitTimer = q->bombFuseTime;
    q->spitCooldown = q->bombFuseTime + 30;
    (p->e).subStateDone = 1;
  }
}

void FUN_08122388(Mummy* p) {}

// プレイヤーへ向けて跳びかかる, 着地したら副状態を終える
void Mummy_StateLeap(Mummy* p) {
  Mover* mover = &(p->e).mover;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Mummy_SetJumpVelToPlayer(p);
    mover->angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z);
    Enemy_PlayAnim(&p->e, 5);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  if (anim->cmdIdx > 2) {
    if (anim->cmdIdx == 4 && anim->tick == 0) {
      PlaySound_082406e0(CRY_MUMMY_ATK);
    }
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).subStateDone = 1;
    Enemy_PlayAnim(&p->e, 0);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

void Mummy_StateMove(Mummy* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
  }
  Enemy_PlayAnim(&p->e, 1);
}

void Mummy_StateWait(Mummy* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// 経路ノードの向きへ振り向く, 回る向きの振り向きアニメを流してコマごとに 21 ずつ回し, アニメが終わったら向きが合っていれば止まり合っていなければ状態2へ戻す
// 710/769命令, Golem_StateTurn / Cockatrice_StateTurn と同じ形と同じ壁 (原典は p を2本のレジスタに持つ), 振り向きアニメは Mummy_PlayTurnAnim, 違いは回す幅が 21, 試済: anim を先頭のローカルに置く (706→710)
NON_MATCH void Mummy_StateTurn(Mummy* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

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
      case 0: {
        if (target - 2 < 4) {
          Mummy_PlayTurnAnim(p, 1, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Mummy_PlayTurnAnim(p, 0, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 1: {
        if (target - 4 < 4) {
          Mummy_PlayTurnAnim(p, 2, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Mummy_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 2: {
        if (target - 1 > 4) {
          Mummy_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE | ANIM_PLAY_XFLIP);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Mummy_PlayTurnAnim(p, 2, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 3: {
        if (target < 4) {
          Mummy_PlayTurnAnim(p, 0, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Mummy_PlayTurnAnim(p, 1, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
    }
    (p->e).animForceRestart = FALSE;
  }
  if (anim->tick == 0) {
    u32 target = ((p->e).unk_1dc + 5) & 7;
    u8 angle = (p->e).mover.angle;

    if (abs(angle - target * 32) < 22) {
      (p->e).mover.angle = target * 32;
    } else if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle = angle + 21;
    } else {
      (p->e).mover.angle = angle - 21;
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
  INCFUNC("asm/func/Mummy_StateTurn.inc");
#endif
}

void Mummy_StateBurning(Mummy* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_4);
  }
  Enemy_PlayAnim(&p->e, 1);
  (p->e).animSpeedDiv = 6;
  if ((p->e).unk_464 == 0) {
    (p->e).subStateDone = 1;
    Enemy_PlayAnim(&p->e, 6);
    Mummy_ClearBurnParticles(p);
    (p->e).unk_494 = 64;
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, Mummy_StateBurnRecover, ES_UNK_19);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 1;
  }
}

// 燃え尽きて起き上がるアニメ (7 番) を流し, 終わったら経路を最初から引き直して 60 フレーム後に経路移動へ戻る
// 319/322命令, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x3c, こちらは 0x38), 1回目の下書きで切り上げ
NON_MATCH void Mummy_StateBurnRecover(Mummy* p, s32 timer) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Enemy_PlayAnim(&p->e, 7);
    (p->e).animForceRestart = 0;
  }
  if (timer < 60) {
    anim->cmdIdx = 0;
    anim->tick = 0;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).sleepTimer = 0;
  (p->e).subStateDone = 1;
  Enemy_PlayAnim(&p->e, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  {
    Vec3* target = (p->e).pathNodePos;

    target->x = (p->e).pathWalker.node->x;
    target->z = (p->e).pathWalker.node->y;
    target->y = TileHeightAt(target);
  }
  if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).pathNodePos->val = 1;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
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
  INCFUNC("asm/func/Mummy_StateBurnRecover.inc");
#endif
}

void Mummy_StateNoticePause(Mummy* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    (p->e).animForceRestart = 0;
  }
  if (timer > 16 && (p->e).animForceRestart && (p->e).subStateDone != 1) {
    (p->e).subStateDone = 1;
    Enemy_PlayAnim(&p->e, 0);
  }
}

void Mummy_StateHeardSound(Mummy* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    (p->e).animForceRestart = 0;
  }
  if (timer > 42) {
    if ((p->e).animForceRestart) {
      (p->e).subStateDone = 1;
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_36);
        Enemy_ResetState(&p->e, 0, 0, 12);
        (p->e).pathNodePos->val = 1;
        SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 7);
        Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
        (p->e).pathNodePos->val = 0;
        (p->e).animSpeedDiv = 3;
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      }
    }
  } else {
    if (anim->cmdIdx == 2) {
      u16 tick = anim->tick;

      if (anim->wait != 0 ? tick == anim->wait - 1 : tick == 0) {
        anim->tick = 0;
      }
    }
  }
}

// 姿と影を隠して 27 フレーム待ち, 出てくるアニメ (8 番) を逆に流しながら Mummy_StateRespawn (状態13) へ移る
// 169/167命令, Golem_StateRespawnWait と同じ流れでアニメ 8 の逆再生を Enemy_PlayAnim と同じ展開で書いたもの, 展開の壁 (r8 / sb の割当と flags の持ち方), 1回目の下書きで切り上げ
NON_MATCH void Mummy_StateRespawnWait(Mummy* p, s32 timer) {
#ifdef NONMATCHING_C
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    u8 variant;
    AuxAnimPlayFlags flags;
    s32 f;

    Enemy_SetAnimFacing(&p->e, &variant, &flags);
    f = flags | ANIM_PLAY_REVERSE;
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
        MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
        if (flags & ANIM_PLAY_XFLIP) {
          MainSprite_SetFlags(s, SPRFLAG_XFLIP);
        } else {
          MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
        }
        (p->e).animForceRestart = 0;
      }
    }
    Enemy_EnterState(&p->e, Mummy_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
#else
  INCFUNC("asm/func/Mummy_StateRespawnWait.inc");
#endif
}

void Mummy_StateRespawn(Mummy* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  if ((p->e).animForceRestart) {
    Mummy_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

void Mummy_StateNap(Mummy* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 8);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, Mummy_StateWakeUp, ES_UNK_6);
  } else if (anim->cmdIdx == 2) {
    anim->tick = 0;
  }
}

void Mummy_StateWakeUp(Mummy* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 9);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
  }
  if (timer == 40) {
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart) {
    Enemy_PlayAnim(&p->e, 0);
    if (timer > 60) {
      (p->e).subStateDone = 1;
    }
  }
}

// アニメが終わったら, 眠っていれば眠りへ, 追跡中なら追跡へ戻し, それ以外は経路の目標へ向かい直して歩きを予約する
// 399/399命令, boku.c の FUN_080fc6f4 と同じ壁 (原典は &flags4 を r6 に持ち越し状態フィールドのアドレスをスタックに作り置く, フレーム 0x38 でこちらは 0x30), 試済: UNK_4 を Enemy_SetFlag4 で立てる (変化なし)
NON_MATCH void Mummy_StateRecover(Mummy* p, s32 timer) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
  Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  if (timer < 18 && anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerSleep, ES_SLEEP);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 0, 0, 14);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_36);
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  (p->e).pendingDelay = 40;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).pathNodePos->val = 1;
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
#else
  INCFUNC("asm/func/Mummy_StateRecover.inc");
#endif
}

// 吹き飛ばされた先へ滑り, アニメが終わったら逃げるか燃えているかに応じて移り, それ以外はプレイヤーへ向かうよう経路を引き直す
// 2026/2023命令の下書き, 前半は Boku_StateDamaged, 後半は Golem_StateDamaged の追跡の枝 (プレイヤーへ向かう部分を2回展開), 違いは逃げる印 (ENEFLAG3_UNK_4) なら別の経路ノードへ散らして unk_5a8 へ移る枝, 原典は状態フィールドのアドレスをスタックに作り置く, 1回目の下書きで切り上げ
NON_MATCH void Mummy_StateDamaged(Mummy* p, s32 timer) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).jumpVel.x = FixToInt(2, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(2, (p->e).jumpVel.z);
    Enemy_PlayAnim(&p->e, 3);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(SE_UNK_298);
      PlaySound_082406e0(CRY_MUMMY_DAMAGED);
    }
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    (p->e).animForceRestart = 0;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (timer < 18 && anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if (Mod(timer, 12) == 0 && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 128, 10, 6, 2, 2);
  }
  if (!Enemy_StepSlide(&p->e)) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
    PathWalker* w = (p->e).mover.path;
    u8 node = Mod(Random() >> 3, w->path->nodeCount);

    if (node == w->nodeIdx) {
      node = Mod(node + 1, w->path->nodeCount);
    }
    w->nodeIdx = node;
    w->waitTimer = 0;
    w->node = &((PathNode*)((u8*)gCollisionMap->paths + w->path->nodeOffset))[w->nodeIdx];
    Enemy_StepTowardPathNode(&p->e);
    Enemy_ResetState(&p->e, 0, 0, 8);
    Enemy_EnterState(&p->e, (p->e).unk_5a8, ES_UNK_19);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3);
    return;
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_19)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_1);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, Mummy_StateRecover, ES_UNK_20);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3);
    (p->e).animSpeedDiv = 1;
    return;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
  INCFUNC("asm/func/Mummy_StateDamaged.inc");
#endif
}

// 倒れるアニメが終わったら, flags3 の状態の印が無ければ爆発し, あれば煙を散らして, 倒されたスクリプトを呼んで図鑑に載せ姿を消す
// 557/558命令, boku.c の Boku_StateDying と同じ残差 (原典は最初の EmitSmoke の size をスタック上で読み書きしながら組み乱数をその後に引く, フレームが 4 バイト大きい 0x4C)
NON_MATCH void Mummy_StateDying(Mummy* p, s32 timer) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_17)) {
      Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    }
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = 0;
    (p->e).unk_494 = 32;
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    (p->e).hurtbox.iframes = 0;
    PlayEnemyDeathCry(&p->e);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(SE_UNK_298);
    }
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  if (Mod(timer, 12) == 0 && TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 128, 10, 8, 2, 2);
  }
  if (timer < 35) {
    anim->tick = 0;
  }
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if ((p->e).animForceRestart) {
    s32 idx;

    (p->e).subStateDone = 1;
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
        Mummy_Explode(p);
        FUN_08240cc4((p->e).mover.pos.x, (p->e).mover.pos.z, 0x400, 0, 1);
      } else {
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
    }
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
    (p->e).sleepTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  }
#else
  INCFUNC("asm/func/Mummy_StateDying.inc");
#endif
}

// owner の spitWaitTimer が残っている間は待ち, 尽きたら1人目のプレイヤーのタイルへの経路を引いて追跡へ移る
// 816/841命令, Mummy_SubLeapAttack と同じ後半, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x84, こちらは 0x50)
NON_MATCH void Mummy_StateWaitBombs(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
  }
  if (Mummy_AvoidNearbyBomb(p)) {
    Enemy_ResetState(&p->e, 0, 0, 16);
  }
  if ((p->e).subState2 == 16) {
    Enemy_PlayAnim(&p->e, 1);
  } else if ((p->e).subState2 == 18) {
    Enemy_PlayAnim(&p->e, 0);
  }
  (p->e).animSpeedDiv = 2;
  if (q->spitWaitTimer != 0) {
    (p->e).subStateTimer++;
    return;
  }
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
  Mummy_ClearFlags(q, MUMMYFLAG_AVOIDING_BOMB | MUMMYFLAG_WAITING_BOMBS);
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

    TilePosAtIndex(&tilePos, tile);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
  }
  Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_36);
  Enemy_ResetState(&p->e, 0, 0, 12);
#else
  INCFUNC("asm/func/Mummy_StateWaitBombs.inc");
#endif
}

// 近くで物音がしたら音のした場所へ向かわせる, 壁に張り付いたプレイヤーを聞きつけたか初めて気付いたときは 1
s32 Mummy_HearSound(Mummy* p) {
  Mummy* q;
  s8 idx;
  bool8 noticed;
  Vec3* target;
  PathWalker* walker;

  Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
  if (Enemy_IsDeaf(&p->e)) {
    return 0;
  }

  (p->e).unk_21c = 0;
  noticed = FALSE;
  q = (p->e).owner;
  idx = FUN_08240dc8((p->e).mover.pos.x, (p->e).mover.pos.z, (p->e).range2, (p->e).unk_21d, (p->e).mover.id);
  if (idx < 0) {
    return 0;
  }

  if ((p->e).unk_202 == 0) {
    (p->e).unk_202 = 180;
    Enemy_EnterState(&p->e, (p->e).unk_5c8, ES_UNK_9);
    Enemy_ResetState(&p->e, 0, 0, 11);
    Mummy_SetFlags(q, MUMMYFLAG_HEARD_SOUND);
    noticed = TRUE;
  }
  if (Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_7)) {
    (p->e).chaseTimer += 300;
    if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
      (p->e).chaseTimer = (p->e).chaseTimeMax;
    }
  }
  FUN_080e8f20(&p->e, idx);
  if (Mummy_HearWallCover(p, &(p->e).unk_204, (p->e).unk_21e)) {
    return 1;
  }

  target = (p->e).pathNodePos;
  walker = &(p->e).pathWalker;
  target->x = walker->node->x;
  target->z = walker->node->y;
  target->y = TileHeightAt(target);
  (p->e).pathNodePos->y = (p->e).mover.pos.y;
  (p->e).pathNodePos->val = 0;
  Mummy_SnapToTile(&(p->e).unk_204, (p->e).unk_21e);
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).unk_204)) {
    (p->e).onRouteFailed(&p->e);
    return 1;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  (p->e).animSpeedDiv = 3;
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_23);
  q->heardSoundTimer = 4;
  Enemy_SetFlag3(&p->e, ENEFLAG3_UNK_9);
  Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_24);
  Enemy_TargetNearestPlayer(&p->e, &(p->e).unk_204);
  if (!noticed) {
    return 0;
  }
  return 1;
}

s32 Mummy_PostUpdate(Mummy* p) {
  Mummy_UpdateAtkHitbox(p);
  Mummy_TickSpitTimers(p);
  Mummy_TickFloorEndCooldown(p);
  Mummy_UpdateBurn(p);
  Mummy_TickHeardSoundTimer(p);
  return 1;
}

s32 FUN_08125d30(Mummy* p) {
  Mummy_ClearBombWaitFlags(p);
  return 1;
}

void Mummy_StartChase(Mummy* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Mummy_StateNoticePause, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  } else if ((p->e).subStateDone) {
    Mummy_ChooseAttack(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// 60 フレーム待ってから感情アイコンを出し, 追跡中ならプレイヤーのタイルかプレイヤーの位置への経路を引いて追跡を予約, そうでなければ経路の目標へ戻る
// 989/963命令の下書き, boku.c の FUN_080fe7f4 と同じ形に, プレイヤーのタイルへの経路が引けなければプレイヤーの位置そのものへ引き直す枝が加わる, 原典はタイルへの経路の部分を bool を返す inline として展開し (0/1 の作り置き), 状態フィールドのアドレスをスタックに作り置く (フレーム 0x60, こちらは 0x30)
NON_MATCH void FUN_08125e1c(Mummy* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 moved;
  bool8 found;
  u8 angle;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
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

  SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  moved = FALSE;
  found = FALSE;
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
    }
    if (m != NULL && idx >= 0) {
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      found = TRUE;
    }
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
    found = TRUE;
  }
  if (!found) {
    (p->e).onRouteFailed(&p->e);
  } else if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
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
    moved = TRUE;
  } else {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
  }
  if (!moved && !Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).onRouteFailed(&p->e);
    return;
  }
  SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
#else
  INCFUNC("asm/func/FUN_08125e1c.inc");
#endif
}

void Mummy_SetHandlerTable3(Mummy* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad63c; }

void FUN_081266f4(Mummy* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateTimer >= (p->e).chaseTimer) {
      Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
      Enemy_ResetState(&p->e, 0, 0, 2);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// 経路の目標へ歩かせ, 着いたら壁に張り付いたプレイヤーを探し, 向きが変わるときは今の状態を退避して乱数の新しい向きで状態27へ移る
// 369/391命令, cockatrice.c の Cockatrice_SubChaseMove と同じ壁 (原典は退避と状態27への切り替えの格納先アドレスをスタックに作り置き sub sp, #0x44), 試済: UNK_10 の判定を Enemy_TestFlag3 (368)
NON_MATCH void Mummy_SubChaseMove(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Mummy_ClearFlags(q, MUMMYFLAG_WAITING_BOMBS);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      if (Player_TestFlag20(gPlayerPtr[0], PFLAG20_WALL_COVER) && q->floorEndCooldown == 0 && Mummy_RouteToFloorEnd(p)) {
        return;
      }
      Enemy_ResetState(&p->e, 0, 0, 14);
      return;
    }
  } else if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
    if (!TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      if (FUN_080eb2a0(&p->e)) {
        return;
      }
      if (TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_0)) {
        u32 angle;
        u32 a;
        s32 i;

        if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          return;
        }
        if (TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
          return;
        }
        angle = (p->e).mover.angle;
        for (i = 0; i < 4; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        (p->e).lookAngle = a;
        (p->e).savedHandlerState = (p->e).handlerState;
        (p->e).savedState = (p->e).state;
        (p->e).savedSubState0 = (p->e).subState0;
        (p->e).savedSubState1 = (p->e).subState1;
        (p->e).savedSubState2 = (p->e).subState2;
        (p->e).lookBaseAngle = ((p->e).unk_1dc + 5) * 32;
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 2;
        return;
      }
    }
    Enemy_ResetState(&p->e, 0, 0, 13);
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Mummy_SubChaseMove.inc");
#endif
}

// 60 フレーム待ってから追跡を予約し, 壁沿いの探索中に同じタイルに来たら別の経路ノードへ散らして, プレイヤーのタイルへの経路を引き直す
// 828/839命令, boku.c の FUN_080fe7f4 と同じ形, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x64, こちらは 0x3C)
NON_MATCH void Mummy_SubChaseReroute(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  s32 tile;
  s32 idx;
  u8 angle;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    (p->e).unk_202 = 0;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 60) {
    (p->e).subStateTimer++;
    return;
  }
  (p->e).unk_222 &= ~(ENEMY222_UNK_1 | ENEMY222_UNK_2);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
  Enemy_ResetState(&p->e, 3, 1, 0);
  if (q->floorEndCooldown != 0 && (p->e).tileIdx == (p->e).playerMover->tile->tileIdx[1]) {
    PathWalker* w;
    u8 node;

    if (Mummy_RouteToFloorEnd(p)) {
      return;
    }
    w = (p->e).mover.path;
    node = Mod(Random() >> 3, w->path->nodeCount);
    if (node == w->nodeIdx) {
      node = Mod(node + 1, w->path->nodeCount);
    }
    w->nodeIdx = node;
    w->waitTimer = 0;
    w->node = &((PathNode*)((u8*)gCollisionMap->paths + w->path->nodeOffset))[w->nodeIdx];
    Enemy_StepTowardPathNode(&p->e);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
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

  if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
      (p->e).onRouteFailed(&p->e);
    }
    return;
  }
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
#else
  INCFUNC("asm/func/Mummy_SubChaseReroute.inc");
#endif
}

void Mummy_SubWaitBombsWalk(Mummy* p) {
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 18);
      return;
    }
  } else if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 17);
  }
  (p->e).subStateTimer++;
}

void Mummy_SubWaitBombsTurn(Mummy* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_PlayAnim(&p->e, 0);
      Enemy_ResetState(&p->e, 0, 0, 16);
      Enemy_EnterState(&p->e, Mummy_StateWaitBombs, ES_UNK_38);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void Mummy_SubWaitBombsIdle(Mummy* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Mummy_StateWaitBombs, ES_UNK_38);
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    (p->e).subStateTimer++;
  }
}

void Mummy_SetHandlerTable2(Mummy* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad644; }

// 頭の 200 上からプレイヤーへ向けて variant ごとの数 (1〜3) の爆弾を吐く, 高さの差と距離で初速を決め, 2つ目からは速く遅れを短くする
// 244/246命令の下書き, 原典は放り出す位置を WorldPos の DImode のまま y を足し, 方向の sin の表を指すポインタを作り置く, 1回目の下書きで切り上げ
NON_MATCH void Mummy_SpitBombs(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  WorldPos pos = (p->e).mover.pos;
  Vec3 d;
  s32 div;
  s32 speed;
  s32 n;
  u32 angle;
  s32 diff;
  s32 timer;

  pos.y += 200;
  diff = pos.y - (p->e).playerMover->pos.y;
  if (diff < 256) {
    div = 15;
  } else if (diff < 512) {
    div = 20;
  } else if (diff < 768) {
    div = 23;
  } else if (diff < 1024) {
    div = 27;
  } else {
    div = 34;
  }
  Vec3_Diff(&d, &(p->e).playerMover->pos, &(p->e).mover.pos);
  speed = abs(Div(abs(d.z) < abs(d.x) ? d.x : d.z, div));
  if (speed < 11) {
    speed = 10;
  }
  if (speed > q->bombSpeedMax) {
    speed = q->bombSpeedMax;
  }
  if ((p->e).variant == EV_MUMMY) {
    n = 1;
  } else if ((p->e).variant == EV_GAST) {
    n = 2;
  } else {
    n = 3;
  }
  angle = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64;
  {
    s32 a = (p->e).playerAngle - angle;

    if (a > 128) {
      a -= 256;
    } else if (a < -128) {
      a += 256;
    }
    if (abs(a) < 29) {
      angle = (p->e).playerAngle;
    }
  }
  timer = q->bombFuseTime;
  while (n != 0) {
    d.x = POLAR_X(speed, angle);
    d.y = 0;
    d.z = POLAR_Z(speed, angle);
    Entity080dd1f8_Spawn(&pos, &d, &(p->e).playerMover->pos, (p->e).atkPower[2], (p->e).atkKnockback[2], timer, (p->e).mover.id);
    timer = Div(timer * 8, 10);
    speed += Div(speed * 4, 10);
    n--;
  }
  PlaySound_082406e0(CRY_MUMMY_ATK);
#else
  INCFUNC("asm/func/Mummy_SpitBombs.inc");
#endif
}

void Mummy_ChooseAttack(Mummy* p) {
  Mummy* q = (p->e).owner;

  if ((p->e).playerDistSq < q->leapRangeSq) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 0);
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 1);
  }
}

// 物音の主が1人目のプレイヤーで, そのタイルへまっすぐ届けば TRUE, 届かなければプレイヤーのタイルへの経路を引き直すか見回しに戻して FALSE
// 871/901命令, 前半は Mummy_CanReachPlayerStraight の走査, 後半は Mummy_SubLeapAttack と同じ形, 原典は p まで含めて状態フィールドのアドレスをスタックに作り置く (フレーム 0x7C, こちらは 0x50)
NON_MATCH bool8 Mummy_TryReachHeardPlayer(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  u32 target = (p->e).playerMover->tile->tileIdx[1];
  u32 start;
  s32 height;
  s32 fromStairs;
  s32 size;
  u32 cur;
  s32 x;
  bool8 found;
  s32 tile;
  s32 idx;
  u8 angle;

  if ((p->e).unk_21e != gPlayerMoverIDs[0]) {
    return FALSE;
  }
  if (target == (p->e).tileIdx) {
    return TRUE;
  }
  start = (p->e).tileIdx;
  height = (p->e).mover.pos.y;
  fromStairs = TileAtIndex(start)->heightStairs >> 4;
  size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
  found = FALSE;
  if (start < target) {
    cur = start + 1;
    for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width && CanWalkToAdjacentTile(start, cur, height, fromStairs); x++) {
      if (cur == target) {
        found = TRUE;
        break;
      }
      cur++;
    }
    if (!found) {
      for (cur = start + gCollisionMap->tiledata->width; (s32)cur < size && CanWalkToAdjacentTile(start, cur, height, fromStairs); cur += gCollisionMap->tiledata->width) {
        if (cur == target) {
          found = TRUE;
          break;
        }
      }
    }
  } else {
    cur = start - 1;
    for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0 && CanWalkToAdjacentTile(start, cur, height, fromStairs); x--) {
      if (cur == target) {
        found = TRUE;
        break;
      }
      cur--;
    }
    if (!found) {
      for (cur = start - gCollisionMap->tiledata->width; (s32)cur >= 0 && CanWalkToAdjacentTile(start, cur, height, fromStairs); cur -= gCollisionMap->tiledata->width) {
        if (cur == target) {
          found = TRUE;
          break;
        }
      }
    }
  }
  if (found) {
    return TRUE;
  }
  if (q->floorEndCooldown == 0 && (p->e).tileIdx == target) {
    Mummy_RouteToFloorEnd(p);
  }
  (p->e).playerMover = &gPlayerPtr[0]->mover;
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
      return FALSE;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return FALSE;
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
    return FALSE;
  }

  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
      (p->e).onRouteFailed(&p->e);
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Mummy_TryReachHeardPlayer.inc");
#endif
}

// プレイヤーの方を向き, 同じタイルか同じ行・列をまっすぐ歩いてプレイヤーのタイルへ届けば TRUE, 届かなければ向きを戻して FALSE
// 195/201命令, 原典は見つけたときの出口を1か所に集めて TRUE を作り置く形 (cmp の後の bool の作り置き), 1回目の下書きで切り上げ
NON_MATCH bool8 Mummy_CanReachPlayerStraight(Mummy* p) {
#ifdef NONMATCHING_C
  Mover* m = (p->e).playerMover;
  u32 target = m->tile->tileIdx[1];
  u8 angle = (p->e).mover.angle;
  u32 start;
  s32 height;
  s32 fromStairs;
  s32 size;
  u32 cur;
  s32 x;
  bool8 found;

  (p->e).mover.angle = ArcTan2_8((s16)(m->pos.x - (p->e).mover.pos.x), (s16)(m->pos.z - (p->e).mover.pos.z));
  if (target == (p->e).tileIdx) {
    return TRUE;
  }
  start = (p->e).tileIdx;
  height = (p->e).mover.pos.y;
  fromStairs = TileAtIndex(start)->heightStairs >> 4;
  size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
  found = FALSE;
  if (start < target) {
    cur = start + 1;
    for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width && CanWalkToAdjacentTile(start, cur, height, fromStairs); x++) {
      if (cur == target) {
        found = TRUE;
        break;
      }
      cur++;
    }
    if (!found) {
      for (cur = start + gCollisionMap->tiledata->width; (s32)cur < size && CanWalkToAdjacentTile(start, cur, height, fromStairs); cur += gCollisionMap->tiledata->width) {
        if (cur == target) {
          found = TRUE;
          break;
        }
      }
    }
  } else {
    cur = start - 1;
    for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0 && CanWalkToAdjacentTile(start, cur, height, fromStairs); x--) {
      if (cur == target) {
        found = TRUE;
        break;
      }
      cur--;
    }
    if (!found) {
      for (cur = start - gCollisionMap->tiledata->width; (s32)cur >= 0 && CanWalkToAdjacentTile(start, cur, height, fromStairs); cur -= gCollisionMap->tiledata->width) {
        if (cur == target) {
          found = TRUE;
          break;
        }
      }
    }
  }
  if (found) {
    return TRUE;
  }
  (p->e).mover.angle = angle;
  return FALSE;
#else
  INCFUNC("asm/func/Mummy_CanReachPlayerStraight.inc");
#endif
}

bool8 Mummy_IsPlayerWallCovering(void) {
  if (Player_TestFlag20(gPlayerPtr[0], PFLAG20_WALL_COVER)) {
    return TRUE;
  }
  return FALSE;
}

// 向いている方向へ同じ高さの床が途切れる手前のタイルを探し, 見つかればそこへの経路を引いて TRUE
// 429/463命令, 床の判定を bool8 を返す inline にし, 4方向の走査を「途切れたら手前のタイルを返し, 端まで続けば start を返す」inline にまとめると 462/463 まで寄る (残差は高さが r10 に乗らずスタックへ退避される割当だけ), 試済: 高さを u8, 高さを caller のローカル (変化なし)
NON_MATCH bool8 Mummy_RouteToFloorEnd(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;

  if (q->floorEndCooldown == 0) {
    s32 dir = (((p->e).mover.angle + 0x20) >> 6) & 3;
    s32 best = (p->e).tileIdx;
    s32 height = TileAtIndex(best)->heightStairs & 0xF;
    s32 width = gCollisionMap->tiledata->width;
    s32 size = gCollisionMap->tiledata->height * width;
    s32 cur;
    s32 x;

    switch (dir) {
      case 0: {
        cur = best + 1;
        for (x = Mod(cur, width); x < gCollisionMap->tiledata->width; x++) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            best = cur - 1;
            break;
          }
          cur++;
        }
        break;
      }
      case 1: {
        for (cur = best + width; cur < size; cur += gCollisionMap->tiledata->width) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            best = cur - gCollisionMap->tiledata->width;
            break;
          }
        }
        break;
      }
      case 2: {
        cur = best - 1;
        for (x = Mod(cur, width); x >= 0; x--) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            best = cur + 1;
            break;
          }
          cur--;
        }
        break;
      }
      case 3: {
        for (cur = best - width; cur >= 0; cur -= gCollisionMap->tiledata->width) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            best = cur + gCollisionMap->tiledata->width;
            break;
          }
        }
        break;
      }
    }
    if (best != (p->e).tileIdx) {
      WorldPos d;

      TilePosAtIndex(&d, best);
      d.y = (p->e).mover.pos.y;
      if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d)) {
        q->floorEndCooldown = 240;
        return TRUE;
      }
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Mummy_RouteToFloorEnd.inc");
#endif
}

bool8 Mummy_CanAttack(Mummy* p) {
  Mummy* q = (p->e).owner;

  if ((p->e).playerDistSq >= q->leapRangeSq && q->spitCooldown != 0) {
    return FALSE;
  }
  return TRUE;
}

void Mummy_OnAttackRequest(Mummy* p) {
  Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_2);
  Mummy_ClearFlags((p->e).owner, MUMMYFLAG_AVOIDING_BOMB | MUMMYFLAG_WAITING_BOMBS);
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Enemy_BeginChase(&p->e);
    if (Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_8)) {
      return;
    }
    Mummy_ChooseAttack(p);
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
}

void FUN_08128824(Mummy* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    Mummy_RouteToFloorEnd(p);
  }
}

// tryDetectPlayer, 物音の主の1人目のプレイヤーが見えたら追いかけるか見失った場所へ経路を引き直し, まっすぐ届くなら警戒して TRUE
// 985/994命令, 経路を引き直す部分は Mummy_SubLeapAttack と同じ形, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x84, こちらは 0x48), 1回目の下書きで切り上げ
NON_MATCH bool8 Mummy_TryDetectPlayer(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  Mover* m;
  u16 playerTile;
  s32 tile;
  s32 idx;
  u8 angle;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
    return FALSE;
  }
  if ((p->e).unk_618(&p->e)) {
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_24)) {
    return FALSE;
  }
  if ((p->e).unk_21e != gPlayerMoverIDs[0]) {
    return FALSE;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_3);
  m = Enemy_FindVisiblePlayer(&p->e);
  if (m == NULL) {
    if (TEST_FLAGS(q->flags, MUMMYFLAG_HEARD_SOUND)) {
      Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
      CLEAR_FLAGS(q->flags, MUMMYFLAG_HEARD_SOUND);
    }
    return FALSE;
  }
  (p->e).playerMover = m;
  playerTile = m->tile->tileIdx[1];
  if ((p->e).unk_1f8 == 0) {
    if ((!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_7) || TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) && !TEST_FLAGS(q->flags, MUMMYFLAG_AVOIDING_BOMB | MUMMYFLAG_WAITING_BOMBS)) {
      if ((p->e).animSpeedDiv == 1 && (p->e).unk_21e == gPlayerMoverIDs[0]) {
        SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_8);
      }
    } else if (TEST_FLAGS(q->flags, MUMMYFLAG_HEARD_SOUND)) {
      Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
      CLEAR_FLAGS(q->flags, MUMMYFLAG_HEARD_SOUND);
    }
    return FALSE;
  }
  Enemy_UpdatePlayerVector(&p->e);
  if (!Mummy_CanAttack(p)) {
    if (!TEST_FLAGS(q->flags, MUMMYFLAG_AVOIDING_BOMB | MUMMYFLAG_WAITING_BOMBS)) {
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
          return FALSE;
        }
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      } else {
        tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
        idx = 0;
      }

      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          return FALSE;
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
        return FALSE;
      }

      {
        WorldPos tilePos;

        TilePosAtIndex(&tilePos, tile);
        if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
          (p->e).onRouteFailed(&p->e);
        }
      }
      return FALSE;
    }
    return FALSE;
  }
  if (!Mummy_TryReachHeardPlayer(p)) {
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Enemy_Alert(&p->e);
  } else if ((p->e).unk_25e != playerTile) {
    Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos);
    (p->e).unk_25e = playerTile;
  }
  Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
#else
  INCFUNC("asm/func/Mummy_TryDetectPlayer.inc");
#endif
}

void Mummy_InitHitboxes(Mummy* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 32, 128, 32);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Mummy_OnHurt, p);
  VEC3_SET(hitSize, 32, 100, 32);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Mummy_OnHit, 0, p);
}

void Mummy_InitAnims(Mummy* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 1, 0);
  Enemy_SetAnimEntry(&p->e, 2, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 5, 6, 0);
  Enemy_SetAnimEntry(&p->e, 6, 5, 0);
  Enemy_SetAnimEntry(&p->e, 7, 7, 0);
  Enemy_SetAnimEntry(&p->e, 8, 8, 0);
  Enemy_SetAnimEntry(&p->e, 9, 7, 0);
  Enemy_SetAnimEntry(&p->e, 10, 4, 0);
}

// 攻撃判定の大きさと威力の組を, 燃えて暴れているとき・跳びかかっているとき・普段で切り替える
// 171/165命令, 原典は halfSize をスタックの Vec3 で x / y / z を DImode のまま組み (val は不定のまま) 2語で写し, &hitbox を基準に ignoreMask と flags を書く, 試済: Hitbox_SetHalfSize (183), 構造体の代入 (199)
NON_MATCH void Mummy_UpdateAtkHitbox(Mummy* p) {
#ifdef NONMATCHING_C
  Vec3 size;

  if (!Enemy_IsDead(&p->e) && (p->e).hurtbox.iframes == 0 && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_15)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
      size.x = 64;
      size.y = 100;
      size.z = 64;
      {
        HitboxData* hb = &(p->e).hitbox;

        hb->halfSize = size;
        hb->ignoreMask = 0x20;
        hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_9 | HBFLAG_UNK_0;
      }
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1] | HBATTR_INKA | HBATTR_FLAME, (p->e).atkIframes[1]);
      Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_14);
    } else if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      size.x = 32;
      size.y = 100;
      size.z = 32;
      {
        HitboxData* hb = &(p->e).hitbox;

        hb->halfSize = size;
        hb->ignoreMask = 0x10;
        hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_9 | HBFLAG_UNK_0;
      }
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1] | HBATTR_17, (p->e).atkIframes[1]);
    } else {
      size.x = 32;
      size.y = 100;
      size.z = 32;
      {
        HitboxData* hb = &(p->e).hitbox;

        hb->halfSize = size;
        hb->ignoreMask = 0x10;
        hb->flags = HBFLAG_HITBOX | HBFLAG_UNK_9 | HBFLAG_UNK_0;
      }
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
#else
  INCFUNC("asm/func/Mummy_UpdateAtkHitbox.inc");
#endif
}

void Mummy_TickSpitTimers(Mummy* p) {
  Mummy* q = (p->e).owner;

  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_6)) {
    if (q->spitCooldown != 0) {
      q->spitCooldown--;
    }
    if (q->spitWaitTimer != 0) {
      q->spitWaitTimer--;
    }
  }
}

// 焼かれている間, 焼ける声を出し粒子を消していき, 40フレームおきに hp を減らして尽きたら倒れる状態へ移す
// 514/515命令, enedefault.c の FUN_080f6868 と同じ inline (spriteKind でパレットを切り替える, 自分の画面のプレイヤーが当てたかを返す bool8 で各 case が一致しなければ FALSE を返し break する形) で 515/515 まで寄る, 残差は &weaponExpMask を r7 に持ち越す形と CpuFill32 の &v を 0 より先に作る並び, 試済: weaponExpMask の検査を inline (512)
NON_MATCH void Mummy_UpdateBurn(Mummy* p) {
#ifdef NONMATCHING_C
  bool8 dead = Enemy_IsDead(&p->e);
  u16* slots;
  s32 i;
  bool8 show;

  if (dead) {
    return;
  }
  if ((p->e).unk_464 == 0) {
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
    (p->e).unk_464 = dead;
    return;
  }
  if ((p->e).emitter.activeCount > 2) {
    if (Mod((p->e).unk_464, 16) == 0) {
      PlaySound_082406e0(CRY_MUMMY_BURN);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
    }
  } else if (Mod((p->e).unk_464, 48) == 0) {
    PlaySound_082406e0(CRY_MUMMY_BURN);
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
  (p->e).unk_464--;
  if (Mod((p->e).unk_464, 40) == 0) {
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
        CpuFill32(0, &v, sizeof(v));
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
      FUN_080ce544((p->e).unk_4a0, (p->e).weaponExpMask);
    } else {
      if (((p->e).unk_4a0 & 1) && !Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_7)) {
        if (((p->e).kind != ENEK_OCTOPUS || (p->e).variant != 1) && (p->e).kind != ENEK_SKELETON && (p->e).kind != ENEK_SKELETON_A && (p->e).kind != ENEK_SKELETON_F) {
          if (gStat->unk_948[0] < 9999) {
            gStat->unk_948[0]++;
          } else {
            gStat->unk_948[0] = 9999;
          }
          if (gStat->totalEnemyKillCount < 9999) {
            gStat->totalEnemyKillCount++;
          } else {
            gStat->totalEnemyKillCount = 9999;
          }
          Enemy_AddKillCount(&p->e);
        }
        AddPlayerExp((p->e).exp);
        Player_AddWeaponExp((p->e).weaponExpMask, (p->e).weaponExp);
      }
      if (!Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_7) && !IsLinkPlay() && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_11)) {
        DefeatedEnemyLog_Add(gMapInitScriptID, (p->e).mover.id);
      }
      (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    }
    (p->e).unk_464 = 0;
    (p->e).unk_4be = 0;
  }
#else
  INCFUNC("asm/func/Mummy_UpdateBurn.inc");
#endif
}

// 歩きアニメの頭のコマごとに u16_ARRAY_085ad690 の速さを返す, animSpeedDiv が 2 を超えれば倍
s32 Mummy_GetMoveSpeed(Mummy* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->tick == 0) {
    s32 i = Mod(anim->cmdIdx, 4);

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (i != 0) {
      s32 mul = (p->e).animSpeedDiv > 2 ? 2 : 1;

      return u16_ARRAY_085ad690[i] * mul;
    }
  }
  return 0;
}

void Mummy_TickFloorEndCooldown(Mummy* p) {
  Mummy* q = (p->e).owner;

  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_6) && q->floorEndCooldown != 0) {
    q->floorEndCooldown--;
  }
}

// dir の向きの隣のタイルが同じ高さの床なら, その索引を返す, 歩けなければ今のタイルを返す
// 78/791命令, 意味だけを書いた形, 原典は各向きで「idx が今のタイルの右・下・左・上のどれか」を順に調べて床の判定を展開する inline (結果のタイルが idx と等しいかまで比べる) を通し, その形の inline で 766/791 まで寄る
NON_MATCH s32 Mummy_GetWalkableNeighbor(Mummy* p, s32 dir) {
#ifdef NONMATCHING_C
  s32 tile = (p->e).tileIdx;
  s32 height = (p->e).mover.pos.y >> 8;
  s32 next;

  switch (dir) {
    case 0: {
      next = tile + 1;
      break;
    }
    case 1: {
      next = tile + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      next = tile - 1;
      break;
    }
    case 3: {
      next = tile - gCollisionMap->tiledata->width;
      break;
    }
    default: {
      return tile;
    }
  }
  if ((TileAtIndex(next)->heightStairs & 0xF) == height && !(TileAtIndex(next)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
    tile = next;
  }
  return tile;
#else
  INCFUNC("asm/func/Mummy_GetWalkableNeighbor.inc");
#endif
}

s32 Mummy_StepBackOneTile(Mummy* p) {
  Mummy* q = (p->e).owner;
  s32 dir = ((((p->e).mover.angle + 0x20) >> 6) + 2) & 3;
  s32 tile = 0;
  s32 i;
  WorldPos d;

  for (i = 0; i < 4; i++) {
    tile = Mummy_GetWalkableNeighbor(p, dir);
    dir = (dir + 1) & 3;
    if (tile != (p->e).tileIdx) {
      break;
    }
  }
  TilePosAtIndex(&d, tile);
  d.y = (p->e).mover.pos.y;
  Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d);
  q->bombAvoidCooldown = 30;
  return TRUE;
}

bool8 Mummy_AvoidNearbyBomb(Mummy* p) {
  u16* timer = &((Mummy*)(p->e).owner)->bombAvoidCooldown;

  if (*timer != 0) {
    (*timer)--;
  } else {
    if (FUN_080dd250(&(p->e).mover.pos) >= 0) {
      Mummy_SetFlags((p->e).owner, MUMMYFLAG_AVOIDING_BOMB);
      Mummy_StepBackOneTile(p);
      return TRUE;
    }
    Mummy_ClearFlags((p->e).owner, MUMMYFLAG_AVOIDING_BOMB);
    *timer = 0;
  }
  return FALSE;
}

// 壁に張り付いたプレイヤーの音が range2 の内側で聞こえたら, 気付いた印を立ててプレイヤーへ向きを取り直す, 気付いたら TRUE
bool8 Mummy_HearWallCover(Mummy* p, Vec3* pos, u32 id) {
  if (id == gPlayerMoverIDs[0] && Player_TestFlag20(gPlayerPtr[0], PFLAG20_WALL_COVER)) {
    Vec3 d;

    Vec3_Diff(&d, pos, &(p->e).mover.pos);
    if ((u32)(d.x * d.x + d.z * d.z) < (p->e).range2Sq && Mummy_CanReachPlayerStraight(p)) {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
      Mummy_SetFlags((p->e).owner, MUMMYFLAG_GRAB_WALL_COVER);
      (p->e).playerMover = &gPlayerPtr[0]->mover;
      Enemy_UpdatePlayerVector(&p->e);
      Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_7);
      return TRUE;
    }
  }
  return FALSE;
}

void Mummy_SnapToTile(Vec3* pos, u32 id) { TilePosAtIndex(pos, GetCollisionTileIdx(pos)); }

void Mummy_ClearBurnParticles(Mummy* p) {
  Enemy_FadeParticles(&p->e, 4);
  ClearMemory((p->e).unk_458, 8);
  (p->e).unk_462 = 0;
  (p->e).unk_460 = 0;
}

void Mummy_ClearChaseState(Mummy* p) {
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
  Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
  (p->e).animSpeedDiv = 1;
  (p->e).unk_222 = 0;
  (p->e).chaseTimer = 0;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    (p->e).unk_21c = 0;
    (p->e).unk_21e = 0;
    (p->e).unk_202 = 0;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
  (p->e).unk_542 = 0xFF;
}

// 復帰時に作業値と印を消し, 経路のノードへ向き直って待機アニメを流して1コマ送る
// 142/143命令, Dog_OnReset / Golem_OnReset と同じ壁 (p->sprite を r0 に読んでから r5 へ移す), 1回目の下書きで切り上げ
NON_MATCH void Mummy_OnReset(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->spitCooldown = 0;
  q->floorEndCooldown = 0;
  q->bombAvoidCooldown = 0;
  q->spitWaitTimer = 0;
  q->flags = 0;
  (p->e).unk_464 = 0;
  q->unk_71a = 0;
  Mummy_ClearBurnParticles(p);
  Enemy_PlayAnim(&p->e, 0);
  Enemy_StepTowardPathNode(&p->e);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/Mummy_OnReset.inc");
#endif
}

void FUN_0812a63c(Mummy* p) { Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_1); }

void Mummy_TickHeardSoundTimer(Mummy* p) {
  Mummy* q = (p->e).owner;

  if (q->heardSoundTimer != 0) {
    q->heardSoundTimer--;
  } else {
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
  }
}

// 自分の位置の 64 上に variant ごとの数と配置で爆発を起こす (マミーは1つ, ガストは2つ, マミー+ は4つ)
void Mummy_Explode(Mummy* p) {
  WorldPos pos = (p->e).mover.pos;
  s32 i;

  pos.y += 64;
  switch ((p->e).variant) {
    case EV_MUMMY: {
      Explosion_CreateDelayed(&pos, 0, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, 0);
      break;
    }
    case EV_GAST: {
      for (i = 0; i < 2; i++) {
        pos = (p->e).mover.pos;
        pos.y += 64;
        pos.x += sGastExplodeX[i];
        pos.z += sGastExplodeZ[i];
        Explosion_CreateDelayed(&pos, 0, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, sExplodeDelays[i]);
      }
      break;
    }
    case EV_MUMMY_P: {
      for (i = 0; i < 4; i++) {
        pos = (p->e).mover.pos;
        pos.y += 64;
        pos.x += sMummyPExplodeX[i];
        pos.z += sMummyPExplodeZ[i];
        Explosion_CreateDelayed(&pos, 0, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, sExplodeDelays[i]);
      }
      break;
    }
  }
}

void Mummy_ClearBombWaitFlags(Mummy* p) {
  if ((p->e).state != ES_UNK_38) {
    CLEAR_FLAGS(((Mummy*)(p->e).owner)->flags, MUMMYFLAG_AVOIDING_BOMB | MUMMYFLAG_WAITING_BOMBS);
  }
}

// hp が残る被弾への反応, 逃げている最中なら別の経路ノードへ散らし, そうでなければ向き直ってプレイヤーへの経路を引き直す
// 2632/2638命令の下書き, Boku_OnDamaged の下書きの頭を差し替えたもの (逃げる印 ENEFLAG3_UNK_4 なら別の経路ノードへ散らして unk_5a8 へ移る枝), 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x10C, こちらは 0xD0), 1回目の下書きで切り上げ
NON_MATCH bool8 Mummy_OnDamaged(Mummy* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  PlaySound_082406e0(CRY_MUMMY_DAMAGED);
  CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4)) {
    PathWalker* w = (p->e).mover.path;
    u8 node = Mod(Random() >> 3, w->path->nodeCount);

    if (node == w->nodeIdx) {
      node = Mod(node + 1, w->path->nodeCount);
    }
    w->nodeIdx = node;
    w->waitTimer = 0;
    w->node = &((PathNode*)((u8*)gCollisionMap->paths + w->path->nodeOffset))[w->nodeIdx];
    Enemy_StepTowardPathNode(&p->e);
    Enemy_ResetState(&p->e, 0, 0, 8);
    Enemy_EnterState(&p->e, (p->e).unk_5a8, ES_UNK_19);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return TRUE;
  }
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
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
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
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
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
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_15)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
    return TRUE;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if ((p->e).unk_4be != 0) {
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
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
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
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
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
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
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
    // プレイヤーのタイルへ向かえなければプレイヤーの座標そのものへ向かう
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
  INCFUNC("asm/func/Mummy_OnDamaged.inc");
#endif
}

// 跳び終えたら1人目のプレイヤーのタイルへの経路を引いて追跡を予約する, プレイヤーと同じタイルにいるか見えなければ歩きか追跡に戻して見回す
// 789/820命令, boku.c の FUN_080fe7f4 の後半と同じ形, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x84, こちらは 0x48)
NON_MATCH void Mummy_SubLeapAttack(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_EnterState(&p->e, Mummy_StateLeap, ES_UNK_3);
  }
  if (!(p->e).subStateDone) {
    return;
  }
  Mummy_ClearFlags(q, MUMMYFLAG_GRAB_WALL_COVER);
  (p->e).playerMover = &gPlayerPtr[0]->mover;
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

    TilePosAtIndex(&tilePos, tile);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
  }
  Enemy_PlayAnim(&p->e, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
  Enemy_ResetState(&p->e, 3, 1, 0);
#else
  INCFUNC("asm/func/Mummy_SubLeapAttack.inc");
#endif
}

// 爆弾を吐く状態 (状態37) へ入り, 吐き終えたら気付いた印を消して状態38へ移りその場に経路を引く, 引けなければ止まる
// 208/209命令, 原典は状態フィールドのアドレスをスタックに作り置く (フレーム 0x34, こちらは 0x2c), 1回目の下書きで切り上げ
NON_MATCH void Mummy_SubSpitAttack(Mummy* p) {
#ifdef NONMATCHING_C
  Mummy* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_EnterState(&p->e, Mummy_StateSpit, ES_UNK_37);
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    CLEAR_FLAGS(q->flags, MUMMYFLAG_GRAB_WALL_COVER);
    Enemy_PlayAnim(&p->e, 0);
    (p->e).unk_222 &= ~(ENEMY222_UNK_1 | ENEMY222_UNK_2);
    SET_FLAGS(q->flags, MUMMYFLAG_WAITING_BOMBS);
    Enemy_EnterState(&p->e, Mummy_StateWaitBombs, ES_UNK_38);
    Enemy_ResetState(&p->e, 0, 0, 16);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).mover.pos)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/Mummy_SubSpitAttack.inc");
#endif
}

void Mummy_SetHandlerTable4(Mummy* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad6b4; }

s32 Mummy_UpdateFrame(Mummy* p) {
  Mummy_PostUpdate(p);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_13) || (p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];

    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  FUN_08125d30(p);
  return 1;
}

s32 Mummy_Update(Mummy* p) {
  Enemy_Update(&p->e);
  return 0;
}

// 原典は戻り値を返さずに終わる
s32 Mummy_Destroy(Mummy* p) {
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
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1660/1817命令, Golem_Init の下書きをマミー向けに直したもの ('.B' の名前付き引数と leapRangeSq / unk_708 / unk_714 を足す), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline の壁), 1回目の下書きで切り上げ
NON_MATCH s32 Mummy_Init(Mummy* p) {
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
  (p->e).kind = ENEK_MUMMY;
  Mummy_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_MUMMY);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_MUMMY);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_MUMMY);
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
  Mummy_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Mummy_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Mummy_GetMoveSpeed;
  (p->e).handlerTurn = Mummy_StateTurn;
  (p->e).handlerMove = Mummy_StateMove;
  (p->e).handlerWait = Mummy_StateWait;
  (p->e).unk_5c0 = Mummy_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Mummy_StateDamaged;
  (p->e).handlerDying = Mummy_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = Mummy_StateHeardSound;
  (p->e).unk_584 = Mummy_StateRespawnWait;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).tryDetectPlayer = FUN_080f0430;
  (p->e).unk_21d = 3;
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
  (p->e).unk_5e0 = FUN_08122388;
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
  (p->e).tryDetectPlayer = (void*)Mummy_TryDetectPlayer;
  (p->e).onReset = (EnemyHandler)Mummy_OnReset;
  (p->e).unk_5fc = FUN_0812a63c;
  (p->e).onAttackRequest = (EnemyHandler)Mummy_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_08128824;
  (p->e).unk_5a8 = Mummy_StateBurning;
  (p->e).onDamaged = (void*)Mummy_OnDamaged;
  (p->e).unk_628 = (void*)Mummy_HearSound;
  (p->e).unk_1bc = 1;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_27);
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
  Enemy_InitHandlerTables(&p->e);
  Mummy_SetHandlerTable2(p);
  Mummy_SetHandlerTable3(p);
  Mummy_SetHandlerTable4(p);
  p->unk_714 = (p->e).range0;
  if (VM_SeekToNamedArg('B')) {
    ((Mummy*)(p->e).owner)->bombSpeedMax = VM_GetPC() != NULL ? VM_GetValue() : 20;
    ((Mummy*)(p->e).owner)->bombFuseTime = VM_GetPC() != NULL ? VM_GetValue() : 180;
  } else {
    ((Mummy*)(p->e).owner)->bombSpeedMax = 20;
    ((Mummy*)(p->e).owner)->bombFuseTime = 180;
  }
  ((Mummy*)(p->e).owner)->leapRangeSq = Div((p->e).unk_1e8 * 3, 10);
  ((Mummy*)(p->e).owner)->unk_708 = (p->e).unk_1e8;
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
  (p->e).handlerUpdate = (EnemyHandler)Mummy_Update;
  (p->e).handlerDestroy = (EnemyHandler)Mummy_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Mummy_Init.inc");
#endif
}

void Mummy_Create(void) {
  Mummy* p = Malloc(sizeof(Mummy));

  if (p != NULL) {
    ClearMemory(p, sizeof(Mummy));
    if (Mummy_Init(p) < 0) {
      Mummy_Destroy(p);
      Free(p);
    }
  }
}

// プレイヤーへ 28 フレームで届く横の速さと上向き 32 を jumpVel に入れる
void Mummy_SetJumpVelToPlayer(Mummy* p) {
  Vec3 d;
  Vec3* dst = &d;
  WorldPos* pos = &(p->e).mover.pos;

  Vec3_Diff(dst, &(p->e).playerMover->pos, pos);
  (p->e).jumpVel.x = Div(d.x, 28);
  (p->e).jumpVel.y = 32;
  (p->e).jumpVel.z = Div(d.z, 28);
}
