#include "camera.h"
#include "cwolf_target.h"
#include "dust.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "enemy_target.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// ENEF_SKELETON (ENEK_SKELETON, ENEK_SKELETON_F, ENEK_SKELETON_A, ENEK_LICH)
//   ENEK_SKELETON: EV_SKELETON, EV_SKELETON_P
//   ENEK_LICH: EV_LICH, EV_LICH_P
typedef u16 SkeletonFlags;

typedef struct {
  Enemy e;
  u8 unk_654[4];                   // 0x654
  HitboxData dodgeHitbox;          // 0x658
  HitboxData atkHitbox2;           // 0x6A8, Hitbox_SetAttack で atkPower などの番号を選んで攻撃にする
  u16 hitScriptID;                 // 0x6F8
  u8 hitScriptHits;                // 0x6FA
  u8 hitCount;                     // 0x6FB
  u8 unk_6fc[8];                   // 0x6FC
  Vec3 unk_704;                    // 0x704, 8 フレーム目のプレイヤーの位置を写す
  u8 shotsFired;                   // 0x70C
  u8 shotsToFire;                  // 0x70D
  u8 volleyActive;                 // 0x70E
  u8 unk_70f;                      // 0x70F
  u8 shotSpeed;                    // 0x710
  u8 unk_711;                      // 0x711
  u16 shotInterval;                // 0x712
  u16 relocateCooldown;            // 0x714
  u16 retreatCooldown;             // 0x716
  s8 recentNodes[3];               // 0x718
  u8 recentNodeIdx;                // 0x71B
  u16 curveShotScriptID;           // 0x71C, '.T[0]'
  u16 curveShotExplodeScriptID;    // 0x71E, '.T[1]'
  u16 enemySummonScriptID;         // 0x720, '.s'
  u16 lichAtkFlags;                // 0x722
  u8 dodgeTimer;                   // 0x724
  u8 dashSpeed;                    // 0x725
  u16 wakeDelay;                   // 0x726
  u16 unk_728;                     // 0x728, '.E[0]'
  u16 unk_72a;                     // 0x72A, '.E[1]'
  u16 lichCallCooldown;            // 0x72C
  u8 unk_72e[2];                   // 0x72E
  SkeletonFlags flags;             // 0x730
  u8 unk_732[2];                   // 0x732
  u32 atkRangeSq0;                 // 0x734
  u32 atkRangeSq1;                 // 0x738
  u32 atkRangeSq2;                 // 0x73C
  u8 unk_740[4];                   // 0x740
  s16 atkCooldown0;                // 0x744
  s16 atkCooldown1;                // 0x746
  s16 atkCooldown2;                // 0x748
  s16 atkCooldown3;                // 0x74A
  u16 atkCooldownInit[4];          // 0x74C, '.P[0..3]'
  u8 unk_754;                      // 0x754
  u8 unk_755;                      // 0x755
  u8 summonSlot;                   // 0x756
  u8 movesSinceAttack;             // 0x757
  u16 dodgeCooldown;               // 0x758
  u16 attackRecoverTime;           // 0x75A, '.P[4]'
  u32 nearDistSq;                  // 0x75C
  u32 farDistSq;                   // 0x760
  Vec3 shootTargetPos;             // 0x764, 状態に入ったときのプレイヤーの位置を写す
  NavAgent navAgent;               // 0x76C, Enemy.navAgent が指す
  Vec3 pathNodePos;                // 0x790, Enemy.pathNodePos が指す
  u16 skeletonSummonScriptIDs[3];  // 0x798
  u16 unk_79e[3];                  // 0x79E
  u8 skeletonSummoned[3];          // 0x7A4
  u8 unk_7a7;                      // 0x7A7
} Skeleton;
static_assert(sizeof(Skeleton) == 1960);

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

static inline bool8 Skeleton_TestFlags(Skeleton* p, SkeletonFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

static inline void Skeleton_SetFlags(Skeleton* p, SkeletonFlags bit) { p->flags |= bit; }
static inline void Skeleton_ClearFlags(Skeleton* p, SkeletonFlags bit) { p->flags &= ~bit; }

void Enemy_ResetInPlace(Enemy* p);
s32 Enemy_UpdateMovement(Enemy* p);
s32 FUN_080e1f48(Enemy* p);
s32 Enemy_UpdateHitboxes(Enemy* p);
bool32 Enemy_ProcessRequests(Enemy* p);
bool32 Enemy_ShakeSprite(Enemy* p);
void FUN_080f06ac(Enemy* p);
void Enemy_HandleResumeMsg(Enemy* p, u16* msg);
bool8 Entity081f959c_IsAnyActive(void);
bool8 FUN_080f0a0c(Enemy* p);
void Entity081f0298_Spawn(Vec3* pos, u32 angle, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 speed);
void Entity081f8a28_Spawn(Vec3* pos, Vec3* target, s32 velY, s32 angle, s32 homingTime, s32 turnSpeed, s32 homingDelay, s32 speed, s32 maxSpeed, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);
void Entity081f53a8_Spawn(Vec3* pos, Vec3* chaseTarget, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 maxSpeed, s32 turnTime, s32 lifetime, u32 angle);
void Enemy_StateDefeated(Enemy* p, s32 timer);
void Entity081f53a8_VanishAll(void);
void Entity081f4554_VanishAll(void);
void Entity081f9cb8_CancelAll(void);
void Entity081f959c_VanishAll(void);
void Entity081f959c_Spawn(Vec3* pos, u32 angle, s32 angleSpeed, s32 radius, s32 dir, s32 lifetime, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);
void Entity081f4554_Spawn(Vec3* pos, Vec3* target, s32 flyTime, s32 attackCount, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 unk_9, u32 scriptID, u32 explodeScriptID);
bool8 Entity081f9cb8_ExistsAt(Vec3* pos);
void Entity081f9cb8_Spawn(Vec3* pos, s32 delay, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);
void Skeleton_StateSummonEnemyEnd(Skeleton* p);
void Skeleton_StateVolleyEnd(Skeleton* p);
void Skeleton_StateHomingMissileEnd(Skeleton* p);
void Skeleton_StateShootEnd(Skeleton* p);
void Skeleton_StateDashEnd(Skeleton* p);
void Skeleton_PickFarPathNode(Skeleton* p, Vec3* to, Vec3* from, s32 minDist);
void Skeleton_StateCurveShotEnd(Skeleton* p);
void Skeleton_StateDashSlide(Skeleton* p, s32 timer);
void Skeleton_StateHomingMissile(Skeleton* p, s32 timer);
void Skeleton_StateLichHoldPosition(Skeleton* p);
void Skeleton_OnAtkHitbox2Hit(HitboxData* a, HitboxData* b, Skeleton* p);
void Skeleton_OnDodgeHurt(HitboxData* a, HitboxData* b, Skeleton* p);
void Skeleton_OnHit(HitboxData* a, HitboxData* b, Skeleton* p);
void Skeleton_OnHurt(HitboxData* a, HitboxData* b, Skeleton* p);
bool8 Skeleton_CanAttack(Skeleton* p);
void Skeleton_RetreatOrChase(Skeleton* p);
void Skeleton_StateAttackRecover(Skeleton* p, s32 timer);
void Skeleton_StateVolley(Skeleton* p, s32 timer);
void Skeleton_StateDodge(Skeleton* p);
void Skeleton_StateOrbitFlameEnd(Skeleton* p);
void Skeleton_StateWakeUp(Skeleton* p, s32 timer);
void Skeleton_StateOrbitFlame(Skeleton* p);
void Skeleton_StateSummonEnemy(Skeleton* p);
void Skeleton_StateCurveShot(Skeleton* p, s32 timer);
void Skeleton_StateShoot(Skeleton* p, s32 timer);
void Skeleton_StateRespawn(Skeleton* p);
void Skeleton_StateDash(Skeleton* p);

const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_08251fcc[] = "../system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_skeletoncom_08251fe4[] = "skeletoncom.c";

// 歩きのコマごとの速さ, [0] は通常, [1] は追跡中かリッチ
const u16 u16_ARRAY_085ad4e4[2][8] = {
    {400, 400, 0, 260, 380, 340, 0, 380},
    {480, 480, 0, 312, 504, 408, 0, 456},
};  // 0x085AD4E4
// スケルトンアーチャー用
const u16 u16_ARRAY_085ad504[2][8] = {
    {600, 600, 0, 390, 570, 510, 0, 570},
    {720, 720, 0, 468, 756, 612, 0, 684},
};  // 0x085AD504

void Skeleton_StartChase(Skeleton*);
void FUN_0810f680(Skeleton*);

void (*const PTR_ARRAY_085ad524[2])(Skeleton*) = {
    Skeleton_StartChase,
    FUN_0810f680,
};  // 0x085AD524

void Skeleton_SubMelee(Skeleton*);
void Skeleton_SubDashAttack(Skeleton*);
void Skeleton_SubDoubleSlash(Skeleton*);
void Skeleton_SubShoot(Skeleton*);
void Skeleton_SubVolley(Skeleton*);
void Skeleton_SubCurveShot(Skeleton*);
void Skeleton_SubSummonSkeletons(Skeleton*);
void Skeleton_SubHomingMissile(Skeleton*);
void Skeleton_SubOrbitFlame(Skeleton*);
void Skeleton_SubSummonEnemy(Skeleton*);
void Skeleton_SubKeepDistance(Skeleton*);

void (*const PTR_ARRAY_085ad52c[11])(Skeleton*) = {
    Skeleton_SubMelee,
    Skeleton_SubDashAttack,
    Skeleton_SubDoubleSlash,
    Skeleton_SubShoot,
    Skeleton_SubVolley,
    Skeleton_SubCurveShot,
    Skeleton_SubSummonSkeletons,
    Skeleton_SubHomingMissile,
    Skeleton_SubOrbitFlame,
    Skeleton_SubSummonEnemy,
    Skeleton_SubKeepDistance,
};  // 0x085AD52C

void Skeleton_SubWalk(Skeleton*);
void Skeleton_SubWalkTurn(Skeleton*);
void Skeleton_SubTurnToPlayer(Skeleton*);
void Skeleton_SubRelocate(Skeleton*);
void Skeleton_SubRelocateTurn(Skeleton*);
void Skeleton_SubLichTurnToPlayer(Skeleton*);
void Skeleton_SubWalkToAttackSpot(Skeleton*);
void Skeleton_SubWalkToAttackSpotTurn(Skeleton*);
void Skeleton_SubStartQueuedAttack(Skeleton*);

// clang-format off
void (*const PTR_ARRAY_085ad558[24])(Skeleton*) = {
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
    Skeleton_SubWalk,
    Skeleton_SubWalkTurn,
    Skeleton_SubTurnToPlayer,
    Skeleton_SubRelocate,
    Skeleton_SubRelocateTurn,
    Skeleton_SubLichTurnToPlayer,
    Skeleton_SubWalkToAttackSpot,
    Skeleton_SubWalkToAttackSpotTurn,
    Skeleton_SubStartQueuedAttack,
};  // 0x085AD558
// clang-format on

void Skeleton_OnWakeMsg(Skeleton*, u16*);
void Skeleton_OnLichDamagedMsg(Skeleton*, u16*);

void (*const PTR_ARRAY_085ad5b8[8])(Skeleton*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Skeleton_OnWakeMsg,
    Skeleton_OnLichDamagedMsg,
};  // 0x085AD5B8

void Skeleton_OnSummonDefeatedMsg(Skeleton*, u16*);
void Skeleton_OnVolleyMsg(Skeleton*, u16*);

void (*const PTR_ARRAY_085ad5d8[8])(Skeleton*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Skeleton_OnSummonDefeatedMsg,
    Skeleton_OnVolleyMsg,
};  // 0x085AD5D8

void Skeleton_OnWakeMsg(Skeleton* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_11) && (p->e).state == ES_UNK_56) {
    u16 msg2;

    (p->e).ownerFlagsInit &= ~2;
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
    Enemy_ResetInPlace(&p->e);
    msg2 = 1;
    Enemy_HandleResumeMsg(&p->e, &msg2);
  }
}

// 動けるときにメッセージを受けたらプレイヤーへの経路を引いて歩かせ (追いかけ中なら追跡を延ばす), 360 フレームは受け付けない
void Skeleton_OnLichDamagedMsg(Skeleton* p, u16* msg) {
  Skeleton* q;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  q = (p->e).owner;
  if (Skeleton_TestFlags(q, 1 << 4)) {
    return;
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    return;
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_8)) {
    return;
  }
  {
    Vec3* v = &(p->e).jumpVel;

    if (v->x * v->x + v->y * v->y + v->z * v->z != 0) {
      return;
    }
  }
  if (q->dodgeTimer != 0) {
    return;
  }
  if (q->lichCallCooldown != 0) {
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  (p->e).animSpeedDiv = 3;
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
      (p->e).chaseTimer += 300;
      if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
        (p->e).chaseTimer = (p->e).chaseTimeMax;
      }
    }
  } else {
    Enemy_ResetState(&p->e, 0, 0, 7);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
  (p->e).pathNodePos->val = 1;
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).onRouteFailed(&p->e);
  }
  q->lichCallCooldown = 360;
}

// リッチがメッセージで呼ばれたら, msg[1] 番の召喚の印を消し, msg[2..4] の位置へ経路を引けたら状態16へ移る
// 120/119命令, 原典は &flags3 を r7 に持ち越して経路が引けないときの印の消去にも使う, 試済: Enemy_GetFlag3 で検査 (122→120)
NON_MATCH void Skeleton_OnSummonDefeatedMsg(Skeleton* p, u16* msg) {
#ifdef NONMATCHING_C
  if ((p->e).kind == ENEK_LICH && !Enemy_IsDead(&p->e)) {
    ((Skeleton*)(p->e).owner)->skeletonSummoned[msg[1]] = 0;
    if (!Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_8)) {
      WorldPos pos;

      pos.x = msg[2];
      pos.y = msg[3];
      pos.z = msg[4];
      if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 0, 18);
      }
    }
  }
#else
  INCFUNC("asm/func/Skeleton_OnSummonDefeatedMsg.inc");
#endif
}

// リッチが生きていて relocateCooldown と volleyActive が 0 なら, shotsToFire にメッセージの値を足す (6 まで)
// 39/41命令, 原典は上限の 6 で抑えない側で shotsToFire + msg[1] を比較とは別にもう一度足す, 試済: if/else, 一時変数, > 6 の比較 (変化なしか悪化)
NON_MATCH void Skeleton_OnVolleyMsg(Skeleton* p, u16* msg) {
#ifdef NONMATCHING_C
  if ((p->e).kind == ENEK_LICH && !Enemy_IsDead(&p->e)) {
    Skeleton* q = (p->e).owner;

    if (q->relocateCooldown == 0 && q->volleyActive == 0) {
      q->shotsToFire = q->shotsToFire + msg[1] < 7 ? q->shotsToFire + msg[1] : 6;
    }
  }
#else
  INCFUNC("asm/func/Skeleton_OnVolleyMsg.inc");
#endif
}

void Skeleton_StartDodge(Skeleton* p, Skeleton* self) {
  switch ((p->e).kind) {
    case ENEK_SKELETON: {
      self->dodgeCooldown = 120;
      break;
    }
    case ENEK_SKELETON_F: {
      self->dodgeCooldown = 60;
      break;
    }
    case ENEK_SKELETON_A: {
      self->dodgeCooldown = 120;
      break;
    }
    default: {
      return;
    }
  }
  Enemy_EnterState(&p->e, Skeleton_StateDodge, ES_UNK_55);
  Enemy_ResetState(&p->e, 3, 0, 0);
  Enemy_ClearFlags4(&p->e, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
}

// 止まっていて, 近くにいるプレイヤーの向きが自分の向きと 64 を超えて違えば (向かい合っていれば) 避けられるので TRUE
// 86/87命令, 残差は flags の格納先の定数を作り直すか (原典) 直前の定数から引くか (こちら) の1命令, 試済: Enemy_TestFlag で検査 (変化なし)
NON_MATCH bool8 Skeleton_CanDodge(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  Mover* m = (p->e).playerMover;
  Vec3* v;

  if (m == NULL || q->dodgeCooldown != 0 || !Enemy_TestFlag(&p->e, ENEFLAG_UNK_27)) {
    return FALSE;
  }
  v = &(p->e).jumpVel;
  if (v->x * v->x + v->y * v->y + v->z * v->z == 0 && (p->e).playerDistSq <= 0x24000) {
    s32 d = m->angle - (p->e).mover.angle;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) > 63 && q->dodgeTimer == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Skeleton_CanDodge.inc");
#endif
}

void Skeleton_TickDodgeCooldown(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (q->dodgeCooldown != 0) {
    q->dodgeCooldown--;
  }
}

// 復帰時に印と dodgeCooldown を消して owner の印を初期値に戻し, 経路ノードへ向かい直して待機アニメを1コマ送る
// 88/88命令, 残差は Enemy_ClearPendingState の引数を積む順 (原典はファイル名の文字列を先に r1 へ読む) の1か所, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_OnReset(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  q->dodgeTimer = 0;
  q->dodgeCooldown = 0;
  q->flags = (p->e).ownerFlagsInit;
  ClearMemory((p->e).pathNodePos, 8);
  Enemy_ClearPendingState(&p->e, s_skeletoncom_08251fe4, 267);
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  if (Map_IsPosOutsidePathNode(&(p->e).pathWalker, &(p->e).mover.pos, 32, 32)) {
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  MainSprite_AdvanceAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx);
#else
  INCFUNC("asm/func/Skeleton_OnReset.inc");
#endif
}

// 避けの判定 (dodgeHitbox), 食らい判定, 攻撃判定, 2つ目の攻撃判定 (atkHitbox2) を作る
// 125/125命令, 残差は Enemy_InitAtkHitbox の handler をプールから読む位置 (原典は1つ前の呼び出しの引数を積む前) だけ, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_InitHitboxes(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  Vec3 size1, offset1, hurtSize, hurtOffset, hitSize, hitOffset, size2, offset2;

  VEC3_SET(size1, 128, 128, 128);
  VEC3_SET(offset1, 0, 128, 0);
  Enemy_RegisterHitbox(&p->e, &q->dodgeHitbox, &size1, &offset1, Skeleton_OnDodgeHurt, p, HBFLAG_HURTBOX | HBFLAG_ANGLE | HBFLAG_UNK_3 | HBFLAG_UNK_1 | HBFLAG_UNK_0);
  VEC3_SET(hurtSize, 128, 128, 128);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Skeleton_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Skeleton_OnHit, 0, p);
  VEC3_SET(size2, 0, 100, 0);
  VEC3_SET(offset2, 0, 128, 0);
  Enemy_InitHitboxWithAtk(&p->e, &q->atkHitbox2, &size2, &offset2, Skeleton_OnAtkHitbox2Hit, 1, p);
#else
  INCFUNC("asm/func/Skeleton_InitHitboxes.inc");
#endif
}

void Skeleton_SetAtkHitbox2Attack(Skeleton* p, s32 param_2) { Hitbox_SetAttack(&((Skeleton*)(p->e).owner)->atkHitbox2, (p->e).atkPower[param_2], (p->e).atkKnockback[param_2], 0, (p->e).atkAttrs[param_2], (p->e).atkIframes[param_2]); }

// 毎フレーム, 背後判定 (dodgeHitbox) と2つ目の攻撃判定を自分の位置と前方へ置き直し, 向きに応じて攻撃判定の大きさを変える
// 208/225命令の下書き, 原典は前方の位置を WorldPos の DImode のまま組み, 大きさを halfSize へ 32bit でまとめて書く, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_UpdateHitboxes(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  WorldPos pos;
  u32 dir;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).kind == ENEK_LICH) {
    Hitbox_Hide(&q->dodgeHitbox);
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_11)) {
    return;
  }
  if ((p->e).state == ES_UNK_56 || (p->e).state == 60) {
    return;
  }
  if (q->dodgeTimer == 0) {
    Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    Hitbox_ClearFlags(&q->dodgeHitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_Hide(&(p->e).hurtbox);
    Hitbox_Hide(&q->dodgeHitbox);
    q->dodgeTimer--;
  }
  pos = (p->e).mover.pos;
  Hitbox_SetPos(&q->dodgeHitbox, &pos, 0);
  pos.x += POLAR_X(128, (p->e).mover.angle);
  pos.z += POLAR_Z(128, (p->e).mover.angle);
  dir = (((p->e).mover.angle + 0x10) & 0xFF) >> 6;
  switch (dir) {
    case 1:
    case 3: {
      if ((p->e).kind == ENEK_SKELETON_F) {
        q->atkHitbox2.halfSize.x = 84;
        q->atkHitbox2.halfSize.z = 180;
      } else {
        q->atkHitbox2.halfSize.x = 64;
        q->atkHitbox2.halfSize.z = 160;
      }
      break;
    }
    case 0:
    case 2: {
      if ((p->e).kind == ENEK_SKELETON_F) {
        q->atkHitbox2.halfSize.x = 180;
        q->atkHitbox2.halfSize.z = 84;
      } else {
        q->atkHitbox2.halfSize.x = 160;
        q->atkHitbox2.halfSize.z = 64;
      }
      break;
    }
  }
  q->atkHitbox2.halfSize.y = 100;
  Hitbox_SetPos(&q->atkHitbox2, &pos, 0);
  Hitbox_SetPos(&q->dodgeHitbox, &pos, 0);
#else
  INCFUNC("asm/func/Skeleton_UpdateHitboxes.inc");
#endif
}

void Skeleton_InitAnims(Skeleton* p) {
  switch ((p->e).kind) {
    case ENEK_SKELETON: {
      Enemy_SetAnimEntry(&p->e, 0, 0, 0);
      Enemy_SetAnimEntry(&p->e, 1, 6, 0);
      Enemy_SetAnimEntry(&p->e, 5, 12, 0);
      Enemy_SetAnimEntry(&p->e, 2, 30, 0);
      Enemy_SetAnimEntry(&p->e, 14, 56, 0);
      Enemy_SetAnimEntry(&p->e, 15, 58, 0);
      Enemy_SetAnimEntry(&p->e, 16, 60, 0);
      Enemy_SetAnimEntry(&p->e, 11, 74, 0);
      Enemy_SetAnimEntry(&p->e, 6, 80, 0);
      Enemy_SetAnimEntry(&p->e, 12, 74, 0);
      Enemy_SetAnimEntry(&p->e, 7, 80, 4);
      Enemy_SetAnimEntry(&p->e, 3, 96, 0);
      Enemy_SetAnimEntry(&p->e, 10, 114, 0);
      Enemy_SetAnimEntry(&p->e, 17, 104, 0);
      Enemy_SetAnimEntry(&p->e, 18, 106, 0);
      Enemy_SetAnimEntry(&p->e, 13, 108, 0);
      break;
    }
    case ENEK_SKELETON_F: {
      Enemy_SetAnimEntry(&p->e, 0, 2, 0);
      Enemy_SetAnimEntry(&p->e, 1, 8, 0);
      Enemy_SetAnimEntry(&p->e, 5, 14, 0);
      Enemy_SetAnimEntry(&p->e, 2, 33, 0);
      Enemy_SetAnimEntry(&p->e, 14, 62, 0);
      Enemy_SetAnimEntry(&p->e, 15, 64, 0);
      Enemy_SetAnimEntry(&p->e, 16, 66, 0);
      Enemy_SetAnimEntry(&p->e, 11, 76, 0);
      Enemy_SetAnimEntry(&p->e, 6, 84, 0);
      Enemy_SetAnimEntry(&p->e, 12, 76, 0);
      Enemy_SetAnimEntry(&p->e, 7, 84, 4);
      Enemy_SetAnimEntry(&p->e, 3, 98, 0);
      Enemy_SetAnimEntry(&p->e, 10, 114, 0);
      Enemy_SetAnimEntry(&p->e, 19, 126, 0);
      Enemy_SetAnimEntry(&p->e, 20, 128, 0);
      Enemy_SetAnimEntry(&p->e, 21, 130, 0);
      Enemy_SetAnimEntry(&p->e, 22, 132, 0);
      Enemy_SetAnimEntry(&p->e, 23, 134, 0);
      Enemy_SetAnimEntry(&p->e, 17, 104, 0);
      Enemy_SetAnimEntry(&p->e, 18, 106, 0);
      Enemy_SetAnimEntry(&p->e, 13, 110, 0);
      break;
    }
    case ENEK_SKELETON_A: {
      Enemy_SetAnimEntry(&p->e, 0, 4, 0);
      Enemy_SetAnimEntry(&p->e, 1, 10, 0);
      Enemy_SetAnimEntry(&p->e, 5, 16, 0);
      Enemy_SetAnimEntry(&p->e, 2, 39, 0);
      Enemy_SetAnimEntry(&p->e, 14, 68, 0);
      Enemy_SetAnimEntry(&p->e, 15, 70, 0);
      Enemy_SetAnimEntry(&p->e, 16, 72, 0);
      Enemy_SetAnimEntry(&p->e, 11, 78, 0);
      Enemy_SetAnimEntry(&p->e, 6, 88, 0);
      Enemy_SetAnimEntry(&p->e, 7, 90, 4);
      Enemy_SetAnimEntry(&p->e, 12, 78, 0);
      Enemy_SetAnimEntry(&p->e, 3, 100, 0);
      Enemy_SetAnimEntry(&p->e, 10, 114, 0);
      Enemy_SetAnimEntry(&p->e, 19, 18, 0);
      Enemy_SetAnimEntry(&p->e, 20, 20, 0);
      Enemy_SetAnimEntry(&p->e, 21, 22, 0);
      Enemy_SetAnimEntry(&p->e, 22, 140, 0);
      Enemy_SetAnimEntry(&p->e, 23, 142, 0);
      Enemy_SetAnimEntry(&p->e, 17, 104, 0);
      Enemy_SetAnimEntry(&p->e, 18, 106, 0);
      Enemy_SetAnimEntry(&p->e, 13, 112, 0);
      break;
    }
    case ENEK_LICH: {
      Enemy_SetAnimEntry(&p->e, 0, 124, 0);
      Enemy_SetAnimEntry(&p->e, 1, 54, 0);
      Enemy_SetAnimEntry(&p->e, 2, 45, 0);
      Enemy_SetAnimEntry(&p->e, 5, 136, 0);
      Enemy_SetAnimEntry(&p->e, 6, 92, 0);
      Enemy_SetAnimEntry(&p->e, 7, 94, 0);
      Enemy_SetAnimEntry(&p->e, 3, 102, 0);
      Enemy_SetAnimEntry(&p->e, 10, 116, 0);
      Enemy_SetAnimEntry(&p->e, 19, 24, 0);
      Enemy_SetAnimEntry(&p->e, 20, 26, 0);
      Enemy_SetAnimEntry(&p->e, 21, 28, 0);
      Enemy_SetAnimEntry(&p->e, 22, 136, 0);
      Enemy_SetAnimEntry(&p->e, 23, 138, 0);
      Enemy_SetAnimEntry(&p->e, 24, 136, 4);
      break;
    }
  }
}

s32 Skeleton_TryAttack0InRange(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if ((p->e).playerDistSq > q->nearDistSq && (p->e).playerDistSq < q->farDistSq) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 0);
    return TRUE;
  }
  return FALSE;
}

NAKED void Skeleton_LichPSelectAction(Skeleton* p) { INCFUNC("asm/func/Skeleton_LichPSelectAction.inc"); }

NAKED void Skeleton_LichSelectAction(Skeleton* p) { INCFUNC("asm/func/Skeleton_LichSelectAction.inc"); }

bool8 Skeleton_SelectAttackNormal(Skeleton* p, Skeleton* self, s32 param_3) {
  if (!Skeleton_CanAttack(p)) {
    if (Skeleton_TestFlags(self, 1 << 9)) {
      return TRUE;
    }
    Skeleton_RetreatOrChase(p);
    return TRUE;
  }
  if (param_3 < 25 && (p->e).playerDistSq < self->atkRangeSq0) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 0);
    self->movesSinceAttack = 0;
    return TRUE;
  }
  return FALSE;
}

// SKELETON_F の攻撃を距離, HP, 攻撃ごとの待ち時間から選ぶ
bool8 Skeleton_SelectAttackFencer(Skeleton* p, Skeleton* self, s32 param_3) {
  if (!Skeleton_CanAttack(p)) {
    if (Skeleton_TestFlags(self, 1 << 9)) {
      return TRUE;
    }
    Skeleton_RetreatOrChase(p);
    return TRUE;
  }
  if ((p->e).playerDistSq < self->atkRangeSq2 && self->atkCooldown2 <= 0) {
    if (param_3 < 13 && (p->e).hp <= (p->e).unk_546) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 2);
      self->movesSinceAttack = 0;
      return TRUE;
    }
    if (param_3 < 25 && self->atkCooldown0 <= 0) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 0);
      self->movesSinceAttack = 0;
      return TRUE;
    }
  } else {
    if (param_3 < 25 && (p->e).playerDistSq < self->atkRangeSq0 && self->atkCooldown0 <= 0) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 0);
      self->movesSinceAttack = 0;
      return TRUE;
    }
    if (param_3 < 13 && (p->e).playerDistSq < self->atkRangeSq1 && self->atkCooldown1 <= 0) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 1);
      self->movesSinceAttack = 0;
      return TRUE;
    }
  }
  return FALSE;
}

// SKELETON_A の攻撃を距離, HP, 攻撃ごとの待ち時間から選ぶ
bool8 Skeleton_SelectAttackArcher(Skeleton* p, Skeleton* self, s32 param_3) {
  if ((p->e).playerDistSq < self->nearDistSq) {
    if ((p->e).hp < (p->e).unk_546 || Skeleton_TestFlags(self, 1 << 7)) {
      if (param_3 < 25 && (p->e).playerDistSq < self->atkRangeSq0 && self->atkCooldown0 <= 0) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 2, 0);
        self->movesSinceAttack = 0;
        return TRUE;
      }
      if (param_3 < 25 && self->atkCooldown1 <= 0) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 2, 3);
        Skeleton_ClearFlags(self, 1 << 7);
        self->movesSinceAttack = 0;
        return TRUE;
      }
    }
    if (param_3 < 25 && self->movesSinceAttack) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 3);
      Skeleton_ClearFlags(self, 1 << 7);
      self->movesSinceAttack = 0;
      return TRUE;
    }
    Skeleton_RetreatOrChase(p);
    return TRUE;
  }
  if (param_3 < 21 && (((p->e).playerDistSq < self->atkRangeSq1 && self->atkCooldown1 <= 0) || self->movesSinceAttack)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 3);
    self->movesSinceAttack = 0;
    return TRUE;
  }
  return FALSE;
}

// 近くて正面にいるプレイヤーへ kind ごとの攻撃を選ぶ, 選べなければ次の行動 (Skeleton_RetreatOrChase) へ
// 131/144命令の下書き, 原典は kind の分岐と次の行動へ進む出口を別の形に組む, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SelectAttack(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* self;
  s32 d;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  self = (p->e).owner;
  if ((p->e).playerDistSq >= (p->e).unk_1e8) {
    if (!Skeleton_TestFlags(self, 1 << 9)) {
      Skeleton_RetreatOrChase(p);
    }
    return;
  }
  d = ArcTan2_8((s16)((p->e).playerMover->pos.x - (p->e).mover.pos.x), (s16)((p->e).playerMover->pos.z - (p->e).mover.pos.z)) - (p->e).mover.angle;
  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  d = abs(d);
  if (d >= (p->e).unk_1fd) {
    if (!Skeleton_TestFlags(self, 1 << 9)) {
      Skeleton_RetreatOrChase(p);
    }
    return;
  }
  switch ((p->e).kind) {
    case ENEK_SKELETON: {
      if (Skeleton_SelectAttackNormal(p, self, d)) {
        return;
      }
      break;
    }
    case ENEK_SKELETON_F: {
      if (Skeleton_SelectAttackFencer(p, self, d)) {
        return;
      }
      break;
    }
    case ENEK_SKELETON_A: {
      if (Skeleton_SelectAttackArcher(p, self, d)) {
        return;
      }
      break;
    }
  }
  if (!Skeleton_TestFlags(self, 1 << 9)) {
    Skeleton_RetreatOrChase(p);
  }
#else
  INCFUNC("asm/func/Skeleton_SelectAttack.inc");
#endif
}

void Skeleton_OnAttackRequest(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  u16 msg[2];

  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) || !Skeleton_CanAttack(p) || q->dodgeTimer != 0) {
      if (!Skeleton_TestFlags(q, 1 << 9)) {
        Skeleton_RetreatOrChase(p);
      }
    } else {
      Skeleton_SelectAttack(p);
      if (Enemy_CountByKind(ENEK_LICH) != 0) {
        msg[0] = 7;
        msg[1] = 3;
        Enemy_SendMsgByKind(ENEK_LICH, msg);
      }
    }
  } else {
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    if (Enemy_CountByKind(ENEK_LICH) != 0) {
      msg[0] = 7;
      msg[1] = 3;
      Enemy_SendMsgByKind(ENEK_LICH, msg);
    }
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  }
}

// 攻撃の要求で, 追いかけ中なら追跡を延ばして追跡へ, そうでなければ止まって 60 フレーム後に経路移動するよう予約し, プレイヤーへの経路を引き直す
// 289/293命令, 原典は UNK_7 の検査結果 (0) を経路移動側の 0 の格納に使い回す, 試済: q を先に読む, 追いかけ側を先に書く
NON_MATCH void FUN_08104ebc(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_8)) {
    return;
  }
  if (q->dodgeTimer != 0) {
    return;
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
      (p->e).chaseTimer += 300;
      if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
        (p->e).chaseTimer = (p->e).chaseTimeMax;
      }
    }
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  } else {
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
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
  INCFUNC("asm/func/FUN_08104ebc.inc");
#endif
}

s32 Skeleton_GetMoveSpeed(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (s->animCmdTimer == 0) {
    u32 row;

    if ((p->e).kind == ENEK_LICH) {
      row = 1;
    } else {
      row = Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_7);
    }
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if ((p->e).kind == ENEK_SKELETON_A) {
      return u16_ARRAY_085ad504[row][s->animCmdIdx & 7];
    }
    return u16_ARRAY_085ad4e4[row][s->animCmdIdx & 7];
  }
  return 0;
}

NAKED s32 Skeleton_FindWalkableDir(Skeleton* p, u32 angle) { INCFUNC("asm/func/Skeleton_FindWalkableDir.inc"); }

// '.E' と '.d' の名前付き引数を読む, '.d' の値で owner の印を立てる
// 90/93命令, 原典は '.d' の3つ目を読めなければ v >= 0 の検査ごと飛ばす形 (v に -1 を入れない), 試済: '.d' の枝の順 (91→90)
NON_MATCH void Skeleton_ReadSpawnArgs(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  s32 mode;
  s32 v;

  if (VM_SeekToNamedArg('E')) {
    q->unk_728 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    q->unk_72a = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('d')) {
    mode = VM_GetPC() != NULL ? VM_GetValue() : 0;
    q->wakeDelay = VM_GetPC() != NULL ? VM_GetValue() : 0;
    v = VM_GetPC() != NULL ? VM_GetValue() : -1;
  } else {
    mode = 0;
    v = -1;
  }
  if (v >= 0) {
    Skeleton_SetFlags(q, 1 << 11);
    q->summonSlot = v;
  }
  if (mode != 0) {
    if (mode == 1) {
      Skeleton_SetFlags(q, (1 << 1) | (1 << 3));
    } else {
      Skeleton_SetFlags(q, 1 << 12);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_ReadSpawnArgs.inc");
#endif
}

// kind ごとに攻撃や追跡に使う距離の2乗 (atkRangeSq0 〜 farDistSq) を決める
// 118/120命令の下書き, 原典は kind の分岐で 5 未満 / 6 と 7 の間 / 8 を超える値もそれぞれの枝へ流す (default が2か所), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_InitAttackRanges(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  switch ((p->e).kind) {
    case ENEK_SKELETON: {
      q->atkRangeSq0 = 80000;
      q->nearDistSq = 80000;
      q->farDistSq = (p->e).unk_1e8;
      break;
    }
    case ENEK_SKELETON_F: {
      q->atkRangeSq0 = 0x19000;
      q->atkRangeSq1 = (p->e).unk_1e8;
      q->atkRangeSq2 = 0x14E1F;
      q->nearDistSq = 0x14E1F;
      q->farDistSq = q->atkRangeSq1;
      break;
    }
    case ENEK_SKELETON_A: {
      q->atkRangeSq0 = 0x19000;
      q->atkRangeSq1 = (p->e).unk_1e8;
      q->nearDistSq = Div((p->e).unk_1e8 * 6, 10);
      q->farDistSq = q->atkRangeSq1;
      break;
    }
    case ENEK_LICH: {
      q->atkRangeSq0 = Div((p->e).unk_1e8 * 4, 10);
      q->atkRangeSq1 = (p->e).unk_1e8;
      q->atkRangeSq2 = (p->e).unk_1e8;
      q->nearDistSq = 0x19000;
      q->farDistSq = (p->e).unk_1e8;
      break;
    }
  }
#else
  INCFUNC("asm/func/Skeleton_InitAttackRanges.inc");
#endif
}

// kind と追跡中かどうかで待機・歩き・走りのアニメの割り当てを差し替える
// 117/143命令の下書き, kind ごとの割り当ての中身が原典の分岐と合っていない可能性がある (Ghidra の出力が崩れている), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_UpdateMoveAnims(Skeleton* p) {
#ifdef NONMATCHING_C
  if ((p->e).kind == ENEK_LICH) {
    Enemy_SetAnimEntry(&p->e, 0, 122, 0);
    Enemy_SetAnimEntry(&p->e, 1, 52, 0);
    Enemy_SetAnimEntry(&p->e, 2, 42, 0);
    return;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_9)) {
    switch ((p->e).kind) {
      case ENEK_SKELETON_F: {
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
          Enemy_SetAnimEntry(&p->e, 0, 2, 0);
          Enemy_SetAnimEntry(&p->e, 1, 8, 0);
          Enemy_SetAnimEntry(&p->e, 2, 33, 0);
        } else {
          Enemy_SetAnimEntry(&p->e, 0, 120, 0);
          Enemy_SetAnimEntry(&p->e, 1, 50, 0);
          Enemy_SetAnimEntry(&p->e, 2, 36, 0);
        }
        break;
      }
      case ENEK_SKELETON: {
        Enemy_SetAnimEntry(&p->e, 0, 0, 0);
        Enemy_SetAnimEntry(&p->e, 1, 6, 0);
        break;
      }
      case ENEK_SKELETON_A: {
        Enemy_SetAnimEntry(&p->e, 0, 4, 0);
        Enemy_SetAnimEntry(&p->e, 1, 10, 0);
        Enemy_SetAnimEntry(&p->e, 2, 39, 0);
        break;
      }
    }
  } else {
    switch ((p->e).kind) {
      case ENEK_SKELETON_F: {
        Enemy_SetAnimEntry(&p->e, 0, 120, 0);
        Enemy_SetAnimEntry(&p->e, 1, 50, 0);
        Enemy_SetAnimEntry(&p->e, 2, 36, 0);
        break;
      }
      case ENEK_SKELETON: {
        Enemy_SetAnimEntry(&p->e, 0, 118, 0);
        Enemy_SetAnimEntry(&p->e, 1, 48, 0);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Skeleton_UpdateMoveAnims.inc");
#endif
}

// variant と kind ごとに, 距離の範囲と各攻撃の待ち (atkCooldown0 〜 atkCooldown2) を見て攻撃できるなら TRUE
// 198/189命令の下書き, Ghidra の出力が崩れていて分岐の対応は推測, 1回目の下書きで切り上げ
NON_MATCH bool8 Skeleton_CanAttack(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  switch ((p->e).variant) {
    case 0:
    case 5: {
      switch ((p->e).kind) {
        case ENEK_SKELETON: {
          return q->atkCooldown0 <= 0;
        }
        case ENEK_SKELETON_A: {
          if ((p->e).hp >= (p->e).unk_546 && !Skeleton_TestFlags(q, 1 << 7)) {
            return q->atkCooldown1 <= 0;
          }
          return q->atkCooldown0 <= 0;
        }
        default: {
          if (((p->e).playerDistSq < q->atkRangeSq0 && q->atkCooldown0 < 1) || ((p->e).playerDistSq < q->atkRangeSq1 && q->atkCooldown1 < 1)) {
            return TRUE;
          }
          if ((p->e).playerDistSq >= q->atkRangeSq2) {
            return FALSE;
          }
          return q->atkCooldown2 <= 0;
        }
      }
    }
    case 2: {
      if ((p->e).hp < (p->e).unk_546) {
        if ((p->e).playerDistSq < q->atkRangeSq0 && q->atkCooldown0 <= 0) {
          return TRUE;
        }
        if ((p->e).playerDistSq >= q->atkRangeSq1) {
          return FALSE;
        }
        return q->atkCooldown1 <= 0;
      }
      if (q->atkCooldown0 > 0) {
        return q->atkCooldown2 <= 0;
      }
      return TRUE;
    }
    case 8: {
      if ((p->e).hp < (p->e).unk_546) {
        if (q->atkCooldown0 > 0 && q->atkCooldown1 > 0) {
          return q->atkCooldown2 <= 0;
        }
        return TRUE;
      }
      if (q->atkCooldown0 > 0) {
        return q->atkCooldown1 <= 0;
      }
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Skeleton_CanAttack.inc");
#endif
}

void Skeleton_TickAttackCooldowns(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (q->atkCooldown0 > 0) {
    q->atkCooldown0--;
  }
  if (q->atkCooldown1 > 0) {
    q->atkCooldown1--;
  }
  if (q->atkCooldown2 > 0) {
    q->atkCooldown2--;
  }
  if (q->atkCooldown3 > 0) {
    q->atkCooldown3--;
  }
}

// angle から 90 度ずつ回して隣の歩けるタイルを探し, そこへ経路を引けたら TRUE, 向きは angle に戻す
// 292/298命令, Dog_PickWalkDest と同じタイル探索の割り当ての壁 (原典はフレーム 0x1C で &mover.pos をスタックに2つ置く), 1回目の下書きで切り上げ
NON_MATCH s32 Skeleton_PickWalkDest(Skeleton* p, u32 angle) {
#ifdef NONMATCHING_C
  u32 target;
  s32 i;
  WorldPos pos;

  for (i = 0; i < 4; i++) {
    u32 tileIdx = (p->e).tileIdx;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    s32 idx;
    s32 n;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    if (target != (p->e).tileIdx) {
      break;
    }
    (p->e).mover.angle += 64;
  }
  (p->e).mover.angle = angle;
  TilePosAtIndex(&pos, target);
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
    return TRUE;
  }
  (p->e).onRouteFailed(&p->e);
  return FALSE;
#else
  INCFUNC("asm/func/Skeleton_PickWalkDest.inc");
#endif
}

// angle から 90 度ずつ回して 1〜4 マス先までの歩けるタイルを探し, そこへ経路を引けたら TRUE, 向きは angle に戻す
// 304/318命令, Skeleton_PickWalkDest / Dog_PickWalkDest と同じタイル探索の割り当ての壁 (原典はフレーム 0x1C), 1回目の下書きで切り上げ
NON_MATCH bool8 Skeleton_PickWalkDestRandom(Skeleton* p, u32 angle) {
#ifdef NONMATCHING_C
  u32 target;
  s32 i;
  WorldPos pos;

  for (i = 0; i < 4; i++) {
    s32 steps = (Random() & 3) + 1;
    u32 tileIdx = (p->e).tileIdx;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    s32 idx;
    s32 n;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    if (target != (p->e).tileIdx) {
      break;
    }
    (p->e).mover.angle += 64;
  }
  (p->e).mover.angle = angle;
  TilePosAtIndex(&pos, target);
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
    return TRUE;
  }
  (p->e).onRouteFailed(&p->e);
  return FALSE;
#else
  INCFUNC("asm/func/Skeleton_PickWalkDestRandom.inc");
#endif
}

// 攻撃が当たった相手がいれば警戒してその相手を追う対象にし, 向き直って TRUE
s32 Skeleton_NoticeHitTarget(Skeleton* p) {
  if ((p->e).hitTargetID > 0) {
    Vec3 diff;

    Enemy_Alert(&p->e);
    CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    (p->e).unk_25e = GetCollisionTileIdx(&(p->e).playerMover->pos);
    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    (p->e).mover.angle = ArcTan2_8(diff.x, diff.z);
    Skeleton_ClearFlags((p->e).owner, (1 << 8) | (1 << 9));
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  }
  return FALSE;
}

bool8 Skeleton_LichTryDetectPlayer(Skeleton* p) {
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3) || (p->e).playerDistSq >= (p->e).range0Sq) {
    return FALSE;
  }
  Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
}

void Skeleton_LichOnAttackRequest(Skeleton* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    if ((p->e).variant == 2) {
      Skeleton_LichSelectAction(p);
    } else {
      Skeleton_LichPSelectAction(p);
    }
  }
}

void FUN_08106230(Skeleton* p) {}

// リッチの variant 2 なら '.O' と '.T' の名前付き引数を読み, それ以外のリッチは '.s' を読む
// 111/112命令の下書き, 原典は p を2本のレジスタに持つ ('.O' の枝で r7 に写す), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_ReadLichArgs(Skeleton* p) {
#ifdef NONMATCHING_C
  if ((p->e).kind == ENEK_LICH) {
    if ((p->e).variant == 2) {
      s32 i;

      if (VM_SeekToNamedArg('O')) {
        for (i = 0; i < 3; i++) {
          p->unk_79e[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
          p->skeletonSummonScriptIDs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
          p->skeletonSummoned[i] = 0;
        }
      } else {
        for (i = 0; i < 3; i++) {
          p->unk_79e[i] = 0;
          p->skeletonSummonScriptIDs[i] = 0;
          p->skeletonSummoned[i] = 0;
        }
      }
      if (VM_SeekToNamedArg('T')) {
        p->curveShotScriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
        p->curveShotExplodeScriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
      }
      p->unk_755 = 0;
    } else {
      p->enemySummonScriptID = VM_GetNamedArgValue('s', 0);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_ReadLichArgs.inc");
#endif
}

bool8 Skeleton_CanSummonEnemy(Skeleton* p) {
  if (((Skeleton*)(p->e).owner)->enemySummonScriptID != 0 && Enemy_CountByKind(ENEK_31) == 0) {
    return TRUE;
  }
  return FALSE;
}

// variant 8 のリッチが Skeleton_CanSummonEnemy を満たせば, 向いている方へ 1 タイル先の位置を引数に enemySummonScriptID のスクリプトを呼ぶ
// 103/98命令, 原典は前方へのずれを Vec3 のままスタックに x / y を書く (こちらは DImode でレジスタに組んで read-modify-write), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SummonEnemy(Skeleton* p) {
#ifdef NONMATCHING_C
  if ((p->e).kind == ENEK_LICH && (p->e).variant == 8) {
    Skeleton* q = (p->e).owner;

    if (Skeleton_CanSummonEnemy(p)) {
      u8 angle = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) << 6;
      Vec3 d;
      u32 argv[3];
      ScriptArgs sa;

      d.x = POLAR_X(256, angle);
      d.y = 0;
      d.z = POLAR_Z(256, angle);
      argv[0] = (p->e).mover.pos.x + d.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z + d.z;
      sa.argc = 3;
      sa.argv = argv;
      VM_ExecByID(q->enemySummonScriptID, &sa);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_SummonEnemy.inc");
#endif
}

void FUN_0810644c(void) {
  s32 i;

  for (i = 0; i < 3; i++) {
  }
}

s32 Skeleton_CanSummonSkeleton(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->skeletonSummoned[i] == 0 && q->skeletonSummonScriptIDs[i] != 0) {
      return TRUE;
    }
  }
  return FALSE;
}

void Skeleton_SummonSkeleton(Skeleton* p) {
  u32 argv[4];
  ScriptArgs sa;

  if ((p->e).kind == ENEK_LICH) {
    Skeleton* q = (p->e).owner;
    s32 i;

    for (i = 0; i < 3; i++) {
      if (q->skeletonSummoned[i] == 0 && q->skeletonSummonScriptIDs[i] != 0) {
        break;
      }
    }
    if (i < 3) {
      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).mover.angle;
      sa.argc = 4;
      sa.argv = argv;
      VM_ExecByID(q->skeletonSummonScriptIDs[i], &sa);
      q->skeletonSummoned[i] = 1;
    }
  }
}

void Skeleton_LichTryStartVolley(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    if (q->volleyActive == 0 && q->shotsToFire != 0) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 4);
      q->volleyActive = 1;
    }
  }
}

void Skeleton_ReadCooldownArgs(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (VM_SeekToNamedArg('P')) {
    s32 i;

    for (i = 0; i < 4; i++) {
      q->atkCooldownInit[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
    q->attackRecoverTime = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
}

NAKED void Skeleton_RetreatOrChase(Skeleton* p) { INCFUNC("asm/func/Skeleton_RetreatOrChase.inc"); }

// Skeleton_PickFarPathNode で選んだ経路ノードへの経路を引き, 引けたら向きの差に応じて状態16の副状態18か19へ, 引けなければ onRouteFailed
// 153/157命令の下書き, 経路を引く部分は Enemy_TryRouteTo の展開, 原典は向きの差の求め方が違う, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_RouteToFarPathNode(Skeleton* p, Skeleton* self, s32 minDist) {
#ifdef NONMATCHING_C
  WorldPos to;
  WorldPos* from = &(p->e).mover.pos;

  Skeleton_PickFarPathNode(p, &to, from, minDist);
  if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
    s32 a;

    self->relocateCooldown = 320;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    a = ArcTan2_8((p->e).navAgent->waypoint.x - (p->e).mover.pos.x, (p->e).navAgent->waypoint.z - (p->e).mover.pos.z);
    if (abs(a - (p->e).mover.angle) < 32) {
      Enemy_ResetState(&p->e, 0, 0, 18);
    } else {
      (p->e).unk_1dc = (FixToInt(5, a) + 3) & 7;
      Enemy_ResetState(&p->e, 0, 0, 19);
    }
  } else {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Skeleton_RouteToFarPathNode.inc");
#endif
}

void Skeleton_LichRelocate(Skeleton* p) {
  Skeleton* self = (p->e).owner;

  Enemy_ClearPendingState(&p->e, s_skeletoncom_08251fe4, 1730);
  if ((p->e).playerDistSq < self->nearDistSq) {
    u8 angle = (p->e).mover.angle;

    (p->e).mover.angle = (p->e).playerAngle + 0x80;
    if (Skeleton_PickWalkDestRandom(p, angle)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
    }
  } else if (self->relocateCooldown != 0) {
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Skeleton_StateLichHoldPosition, ES_UNK_59);
  } else {
    Skeleton_RouteToFarPathNode(p, self, 0x40000);
  }
}

void Skeleton_ClearRecentNodes(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    q->recentNodes[i] = -1;
  }
  q->recentNodeIdx = 0;
}

void Skeleton_PushRecentNode(Skeleton* p, s32 param_2) {
  Skeleton* q = (p->e).owner;

  q->recentNodes[q->recentNodeIdx] = param_2;
  q->recentNodeIdx++;
  if (q->recentNodeIdx > 2) {
    q->recentNodeIdx = 0;
  }
}

s32 Skeleton_IsRecentNode(Skeleton* p, s32 param_2) {
  Skeleton* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->recentNodes[i] == param_2) {
      return TRUE;
    }
  }
  return FALSE;
}

// from から minDist 以上離れた経路ノードのうち最近使っていない一番遠いものを選び, 無ければ乱数で選んで to にその位置を入れる
// 126/138命令の下書き, 原典は経路ノードとの差を Vec3 の DImode のまま組む, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_PickFarPathNode(Skeleton* p, Vec3* to, Vec3* from, s32 minDist) {
#ifdef NONMATCHING_C
  PathWalker w;
  s32 best = 0;
  s32 bestIdx = -1;
  s32 i;
  PathNode* nodes;

  Map_InitPathWalker(&w, 0, 0, 0);
  for (i = 0; i < w.path->nodeCount; i++) {
    PathNode* node = &Map_GetPathNodes(w.path)[i];
    Vec3 d;
    s32 dist;

    d.x = node->x - from->x;
    d.z = node->y - from->z;
    dist = d.x * d.x + d.z * d.z;
    if (dist >= minDist && dist > best && !Skeleton_IsRecentNode(p, i)) {
      best = dist;
      bestIdx = i;
    }
  }
  if (best == 0) {
    bestIdx = Mod(Random(), w.path->nodeCount);
  }
  Skeleton_PushRecentNode(p, bestIdx);
  w.nodeIdx = bestIdx;
  w.waitTimer = 0;
  nodes = Map_GetPathNodes(w.path);
  to->x = nodes[w.nodeIdx].x;
  to->y = (p->e).floorY;
  to->z = nodes[w.nodeIdx].y;
#else
  INCFUNC("asm/func/Skeleton_PickFarPathNode.inc");
#endif
}

// pathIdx 番の経路のノードから, from から minDist 以上離れて最近使っていない一番遠いものを選び, to にその位置を入れる
// 130/138命令の下書き, Skeleton_PickFarPathNode と同じ形で経路の番号を引数に取る, 原典はノードとの差を Vec3 の DImode のまま組む
NON_MATCH void Skeleton_PickFarPathNodeOnPath(Skeleton* p, Vec3* to, Vec3* from, s32 minDist, u32 pathIdx) {
#ifdef NONMATCHING_C
  PathWalker w;
  s32 best = 0;
  s32 bestIdx = -1;
  s32 i;
  PathNode* nodes;

  Map_InitPathWalker(&w, pathIdx, 0, 0);
  for (i = 0; i < w.path->nodeCount; i++) {
    PathNode* node = &Map_GetPathNodes(w.path)[i];
    Vec3 d;
    s32 dist;

    d.x = node->x - from->x;
    d.z = node->y - from->z;
    dist = d.x * d.x + d.z * d.z;
    if (dist >= minDist && dist > best && !Skeleton_IsRecentNode(p, i)) {
      best = dist;
      bestIdx = i;
    }
  }
  if (best == 0) {
    bestIdx = Mod(Random(), w.path->nodeCount);
  }
  Skeleton_PushRecentNode(p, bestIdx);
  w.nodeIdx = bestIdx;
  w.waitTimer = 0;
  nodes = Map_GetPathNodes(w.path);
  to->x = nodes[w.nodeIdx].x;
  to->y = (p->e).floorY;
  to->z = nodes[w.nodeIdx].y;
#else
  INCFUNC("asm/func/Skeleton_PickFarPathNodeOnPath.inc");
#endif
}

void Skeleton_PickRandomPathNode(Skeleton* p) {
  PathWalker* w = &(p->e).pathWalker;
  u8 node = Mod(Random(), w->path->nodeCount);

  if (node == w->nodeIdx) {
    node = Mod(node + 1, w->path->nodeCount);
  }
  w->nodeIdx = node;
  w->waitTimer = 0;
  w->node = &Map_GetPathNodes(w->path)[w->nodeIdx];
}

NAKED void Skeleton_SpawnDeathFragments(Skeleton* p) { INCFUNC("asm/func/Skeleton_SpawnDeathFragments.inc"); }

// 向いている方の横向きに, 両側へ 4 本ずつ同じ速さで回る骨 (Entity081f959c) を放つ
// 向いている方の横向きに, 両側へ 4 本ずつ違う速さで回る骨 (Entity081f959c) を放つ
// 219/218命令, 残差は向きを r0 で作ってから r7 へ移す1命令だけ, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SpawnOrbitFlames(Skeleton* p) {
#ifdef NONMATCHING_C
  u32 angle = (((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64 + 64) & 0xFF;
  s32 dir = (Random() & 0xFF) < 128 ? 1 : -1;
  WorldPos* pos = &(p->e).mover.pos;

  Entity081f959c_Spawn(pos, angle, 0x1000, 2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, 3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, 4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, 5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, -2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, -3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, -4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x1000, -5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
#else
  INCFUNC("asm/func/Skeleton_SpawnOrbitFlames.inc");
#endif
}

// 219/218命令, Skeleton_SpawnOrbitFlames と同じ残差 (向きを r0 で作ってから r7 へ移す1命令), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SpawnOrbitFlamesVaried(Skeleton* p) {
#ifdef NONMATCHING_C
  u32 angle = (((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64 + 64) & 0xFF;
  s32 dir = (Random() & 0xFF) < 128 ? 1 : -1;
  WorldPos* pos = &(p->e).mover.pos;

  Entity081f959c_Spawn(pos, angle, 0xA00, 2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x200, 3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x600, 4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xE00, 5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xA00, -2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x200, -3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x600, -4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xE00, -5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
#else
  INCFUNC("asm/func/Skeleton_SpawnOrbitFlamesVaried.inc");
#endif
}

// 向いている方の横向きに, 片側は速く反対側は遅く逆回りで 4 本ずつ回る骨 (Entity081f959c) を放つ
// 221/225命令, Skeleton_SpawnOrbitFlames と同じ残差に加え, 原典は回る向きの反転を別のスタック位置に置く, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SpawnOrbitFlamesCounter(Skeleton* p) {
#ifdef NONMATCHING_C
  u32 angle = (((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64 + 64) & 0xFF;
  s32 dir = (Random() & 0xFF) < 128 ? 1 : -1;
  WorldPos* pos = &(p->e).mover.pos;

  Entity081f959c_Spawn(pos, angle, 0xC00, 2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xC00, 3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xC00, 4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0xC00, 5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  dir = -dir;
  Entity081f959c_Spawn(pos, angle, 0x400, -2, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x400, -3, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x400, -4, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Entity081f959c_Spawn(pos, angle, 0x400, -5, dir, 400, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
#else
  INCFUNC("asm/func/Skeleton_SpawnOrbitFlamesCounter.inc");
#endif
}

// '.x' の名前付き引数から遅れて呼ぶスクリプトの ID とその遅れを読む
// 44/48命令, 原典は '.x' の2つ目を読む枝で hitScriptHits の格納を後ろの hitCount = 0 と共有する形に組む, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_ReadHitScriptArgs(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (VM_SeekToNamedArg('x')) {
    q->hitScriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
    q->hitScriptHits = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    q->hitScriptID = 0;
    q->hitScriptHits = 0;
  }
  q->hitCount = 0;
#else
  INCFUNC("asm/func/Skeleton_ReadHitScriptArgs.inc");
#endif
}

void Skeleton_CountHitForScript(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (q->hitScriptID == 0) {
    return;
  }

  q->hitCount++;
  if (q->hitCount < q->hitScriptHits) {
    return;
  }

  VM_ExecByID(q->hitScriptID, NULL);
  q->hitScriptID = 0;
  q->hitScriptHits = 0;
  q->hitCount = 0;
}

void Skeleton_StateLichBlownAway(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).mover.angle + 0x80) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 0);
    CLEAR_FLAGS(((Skeleton*)(p->e).owner)->flags, (1 << 8) | (1 << 9) | (1 << 10));
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    ((Skeleton*)(p->e).owner)->retreatCooldown = 0;
    Skeleton_LichSelectAction(p);
    (p->e).animSpeedDiv = 1;
  }
}

// 後ろへ向き直り, 着地したら retreatCooldown と lichAtkFlags の印を消して Skeleton_LichPSelectAction で動き出す
// 66/66命令, 残差は retreatCooldown と lichAtkFlags の格納先を作る並び (原典は owner + 0x6FC を基点に [r2, #0x26] で lichAtkFlags を触る, ~0xD は直前の 0 から subs で作る), 試済: Skeleton_StateLichBlownAway と同じく owner を毎回キャストする形 (67/66), 0x6FC 基点は構造体の切り方の問題かもしれない
NON_MATCH void Skeleton_StateLichPBlownAway(Skeleton* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).mover.angle + 0x80) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 0);
    CLEAR_FLAGS(((Skeleton*)(p->e).owner)->flags, (1 << 8) | (1 << 9) | (1 << 10));
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    Skeleton* q = (p->e).owner;

    q->retreatCooldown = 0;
    q->lichAtkFlags &= ~0xD;
    Skeleton_LichPSelectAction(p);
    (p->e).animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/Skeleton_StateLichPBlownAway.inc");
#endif
}

s32 Skeleton_LichPreUpdate(Skeleton* p) {
  Skeleton_UpdateMoveAnims(p);
  Skeleton_TickAttackCooldowns(p);
  if ((p->e).variant == 2 && (p->e).unk_546 < (p->e).hp) {
    if (p->unk_70f != 0) {
      p->unk_70f--;
    }
    Skeleton_LichTryStartVolley(p);
  }
  if (p->relocateCooldown != 0) {
    p->relocateCooldown--;
  }
  if (p->retreatCooldown != 0) {
    p->retreatCooldown--;
  }
  return 1;
}

s32 Skeleton_PreUpdate(Skeleton* p) {
  Skeleton_UpdateMoveAnims(p);
  Skeleton_TickAttackCooldowns(p);
  if (p->lichCallCooldown != 0) {
    p->lichCallCooldown--;
  }
  return 1;
}

s32 Skeleton_PostUpdate(Skeleton* p) {
  Skeleton_UpdateHitboxes(p);
  Skeleton_TickDodgeCooldown(p);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    CLEAR_FLAGS(((Skeleton*)(p->e).owner)->flags, 1 << 13);
  }
  return 1;
}

// 当たった相手を攻撃対象として覚える, 怯み中 (owner の bit4) で bit11 なら跳ねる速さを消す
// 72/73命令, Mummy_OnHit と同じ壁 (原典は p を2本のレジスタに持つ), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_OnHit(HitboxData* a, HitboxData* b, Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e)) {
    if (Skeleton_TestFlags(q, 1 << 4)) {
      if (Skeleton_TestFlags(q, 1 << 11)) {
        (p->e).jumpVel.x = 0;
        (p->e).jumpVel.z = 0;
      }
    } else {
      Enemy_SetHitTarget(&p->e, b);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_OnHit.inc");
#endif
}

void Skeleton_OnAtkHitbox2Hit(HitboxData* a, HitboxData* b, Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Skeleton_TestFlags(q, 1 << 4)) {
    Enemy_SetHitTarget(&p->e, b);
    Skeleton_SetFlags(q, 1 << 5);
  }
}

// 怯み中 (owner の bit4) か無敵の数え中でなければ敵共通の被弾処理を行う
// 782/793命令, 敵共通の Enemy_HandleHurt の壁 (Golem_OnHurt / Mummy_OnHurt と同じ), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_OnHurt(HitboxData* a, HitboxData* b, Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_IsDead(&p->e) || Skeleton_TestFlags(q, 1 << 4) || q->dodgeTimer != 0) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Skeleton_OnHurt.inc");
#endif
}

void Skeleton_OnDodgeHurt(HitboxData* a, HitboxData* b, Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Hitbox_TestFlags(b, HBFLAG_HIDDEN) && (p->e).kind != ENEK_LICH && (p->e).hurtbox.iframes == 0 && !Skeleton_TestFlags(q, 1 << 4) &&
      !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15) && !Hitbox_HasWeakness(a, 0x10) && Skeleton_CanDodge(p)) {
    Skeleton_StartDodge(p, q);
    q->dodgeTimer = 20;
    (p->e).angle = (p->e).playerAngle + 0x80;
  }
}

void Skeleton_StateMove(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
}

void Skeleton_StateKeepDistance(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
}

void Skeleton_StateWait(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
  Enemy_PlayAnim(&p->e, 0);
}

NAKED void Skeleton_StateDodge(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateDodge.inc"); }

void Skeleton_StateMelee(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
  }
  if ((p->e).kind == ENEK_SKELETON && s->animCmdIdx == 2 && s->animCmdTimer == 0) {
    PlaySound_082406e0(SE_SKELETON_ATK);
  }
  if (s->animCmdIdx == 3) {
    Hitbox_Register(&q->atkHitbox2);
    if (s->animCmdTimer == 0 && (p->e).kind == ENEK_SKELETON_F) {
      PlaySound_082406e0(SONG_938);
    }
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateAttackRecover(Skeleton* p, s32 timer) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
  }
  if (timer > q->attackRecoverTime) {
    (p->e).subStateDone = 1;
  }
}

NAKED void Skeleton_StateArcherMelee(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateArcherMelee.inc"); }

void Skeleton_StateBecomeSkeleton(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 22);
    (p->e).kind = ENEK_SKELETON;
    Skeleton_InitAnims(p);
    Skeleton_InitAttackRanges(p);
    Hitbox_SetAttack(&q->atkHitbox2, (p->e).atkPower[3], (p->e).atkKnockback[3], 0, (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateArcherMeleeMiss(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 23);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateDashWindUp(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 19);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateDash, ES_UNK_39);
  }
}

// 前へ滑りながら砂ぼこりを立て, アニメが終わったら状態40へ移る
// 133/132命令の下書き, 原典は前へのずれを Vec3 のままスタックに書く (DImode の壁), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateDash(Skeleton* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 posRange;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 20);
    PlaySound_082406e0(SONG_939);
  }
  vel.x = POLAR_X(32, (p->e).mover.angle);
  vel.y = 0;
  vel.z = POLAR_Z(32, (p->e).mover.angle);
  (p->e).mover.delta.x += vel.x;
  (p->e).mover.delta.z += vel.z;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  CpuFill32(0, &vel, sizeof(vel));
  VEC3_SET(posRange, 82, 0, 82);
  DustManager_Spawn(&(p->e).mover.pos, &vel, &posRange, 1, 2, 4);
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateDashSlide, ES_UNK_40);
  }
#else
  INCFUNC("asm/func/Skeleton_StateDash.inc");
#endif
}

// dashSpeed の速さで前へ滑りながら4フレームごとに半減して砂ぼこりを立て, 止まってアニメが終わったら状態41へ移る
// 183/175命令の下書き, 原典は前へのずれを Vec3 のままスタックに書く (DImode の壁), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateDashSlide(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  Vec3 vel;
  u8 angle;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
    q->dashSpeed = 72;
  }
  angle = (p->e).mover.angle;
  vel.x = POLAR_X(q->dashSpeed, angle);
  vel.y = 0;
  vel.z = POLAR_Z(q->dashSpeed, angle);
  (p->e).mover.delta.x += vel.x;
  (p->e).mover.delta.z += vel.z;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (Mod(timer, 4) == 0) {
    Vec3 posRange;
    Vec3 velRange;

    q->dashSpeed >>= 1;
    VEC3_SET(posRange, 82, 0, 82);
    CpuFill32(0, &velRange, sizeof(velRange));
    DustManager_Spawn(&(p->e).mover.pos, &velRange, &posRange, 1, 2, 4);
  }
  Hitbox_Register(&q->atkHitbox2);
  if ((p->e).animForceRestart && q->dashSpeed == 0) {
    Enemy_EnterState(&p->e, Skeleton_StateDashEnd, ES_UNK_41);
  }
#else
  INCFUNC("asm/func/Skeleton_StateDashSlide.inc");
#endif
}

void Skeleton_StateDashEnd(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 22);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateDoubleSlash(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 23);
  }
  if ((s->animCmdIdx >= 3 && s->animCmdIdx <= 5) || (s->animCmdIdx >= 7 && s->animCmdIdx <= 9)) {
    Hitbox_Register(&q->atkHitbox2);
  }
  if ((s->animCmdIdx == 4 || s->animCmdIdx == 7) && s->animCmdTimer == 0) {
    PlaySound_082406e0(SONG_938);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateShootWindUp(Skeleton* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 19);
  }
  if (timer > 20 && (p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateShoot, ES_UNK_44);
  }
}

// 向いている方へ 12 までの角度で振った火の玉 (Entity081f0298) を頭上から放ち, 24 フレームで状態45へ移る
// 197/223命令の下書き, 原典は放つ位置を WorldPos の DImode のまま組み, 向きの絞り込みも 24bit シフトで書く, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateShoot(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    WorldPos pos = (p->e).mover.pos;
    s32 dir = (((p->e).mover.angle + 0x20) & 0xFF) >> 6;
    s32 base = dir * 64;
    s32 a = ArcTan2_8((s16)(q->shootTargetPos.x - (p->e).mover.pos.x), (s16)(q->shootTargetPos.z - (p->e).mover.pos.z));
    s32 d = a - base;
    u8 angle;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    pos.x += POLAR_X(10, base);
    pos.y += 260;
    pos.z += POLAR_Z(10, base);
    if (d > 12) {
      angle = base + 12;
    } else if (d < -12) {
      angle = base - 12;
    } else {
      angle = a;
    }
    Entity081f0298_Spawn(&pos, angle, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2], 42);
    PlaySound_082406e0(SONG_936);
  }
  Enemy_PlayAnim(&p->e, 20);
  if (timer > 24) {
    Enemy_EnterState(&p->e, Skeleton_StateShootEnd, ES_UNK_45);
  }
#else
  INCFUNC("asm/func/Skeleton_StateShoot.inc");
#endif
}

void Skeleton_StateShootEnd(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateVolleyWindUp(Skeleton* p, s32 timer) {
  Skeleton* q = (p->e).owner;
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).playerAngle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 19);
  }
  if (timer == 8) {
    q->unk_704 = gPlayerPtr[0]->mover.pos;
  }
  if (s->animCmdTimer == 0 && s->animCmdIdx == 12) {
    PlaySound_082406e0(SONG_946);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateVolley, ES_UNK_47);
  }
}

// 向いている方の左右へ乱数で振った頭上から追尾弾 (Entity081f53a8) を12フレームごとに撃ち, 120 フレームで状態48へ移る
// 245/250命令, 原典は放つ位置を Vec3 の DImode の読み書きで組み, スタックが 8 バイト多い, 試済: if/else の順, 比較の向き
NON_MATCH void Skeleton_StateVolley(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->shotsFired = 0;
    if ((p->e).hp <= (p->e).unk_546) {
      q->shotSpeed = 10;
    } else {
      q->shotSpeed = 5;
    }
  }
  Enemy_PlayAnim(&p->e, 20);
  if (q->shotsToFire > q->shotsFired && Mod(timer, 12) == 0) {
    WorldPos pos = (p->e).mover.pos;
    u8 angle = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64 + 224 + (Random() & 0x3F);

    pos.x += POLAR_X(128, angle);
    pos.y += 220 + (u8)Random();
    pos.z += POLAR_Z(128, angle);
    Entity081f53a8_Spawn(&pos, &gPlayerPtr[0]->mover.pos, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1], q->shotSpeed + (Random() & 0xF), 120, 240, angle);
    q->shotsFired++;
  }
  if (timer > 120) {
    Enemy_EnterState(&p->e, Skeleton_StateVolleyEnd, ES_UNK_48);
  }
#else
  INCFUNC("asm/func/Skeleton_StateVolley.inc");
#endif
}

void Skeleton_StateVolleyEnd(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
    q->volleyActive = 0;
    q->shotsToFire = 0;
    q->unk_70f = 60;
  }
}

void Skeleton_StateHomingMissileWindUp(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 2;
    (p->e).mover.angle = ((((p->e).playerAngle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 19);
    Enemy_UpdateWalkAnimSpeed(&p->e);
  }
  if (s->animCmdTimer == 0 && s->animCmdIdx == 12) {
    PlaySound_082406e0(SONG_946);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateHomingMissile, ES_UNK_63);
    (p->e).animSpeedDiv = 1;
  }
}

// 向いている4方向の先の頭上からプレイヤーを追う弾 (Entity081f8a28) を HP に応じて2発か3発撃ち, 80 フレームで状態64へ移る
// 209/239命令, 原典は放つ位置を Vec3 の DImode の読み書きで組み, 分岐ごとに Div の結果を格納する, 試済: if/else の順
NON_MATCH void Skeleton_StateHomingMissile(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->shotsFired = 0;
    if ((p->e).hp <= (p->e).unk_546) {
      q->shotsToFire = 3;
      q->shotInterval = Div(60, 4);
    } else {
      q->shotsToFire = 2;
      q->shotInterval = Div(80, 3);
    }
  }
  Enemy_PlayAnim(&p->e, 20);
  if (q->shotsFired < q->shotsToFire && Mod(timer, q->shotInterval) == 0) {
    WorldPos pos = (p->e).mover.pos;
    s32 base = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64;
    Vec3 target;

    pos.x += POLAR_X(256, base);
    pos.y += 300;
    pos.z += POLAR_Z(256, base);
    target = gPlayerPtr[0]->mover.pos;
    Entity081f8a28_Spawn(&pos, &target, 2, (p->e).playerAngle, 90, 4, 20, 3, 25, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    q->shotsFired++;
  }
  if (timer > 80) {
    Enemy_EnterState(&p->e, Skeleton_StateHomingMissileEnd, ES_UNK_64);
  }
#else
  INCFUNC("asm/func/Skeleton_StateHomingMissile.inc");
#endif
}

void Skeleton_StateHomingMissileEnd(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
    q->volleyActive = 0;
    q->shotsToFire = 0;
    q->unk_70f = 60;
  }
}

void Skeleton_StateOrbitFlameWindUp(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).playerAngle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 19);
  }
  if (s->animCmdTimer == 0 && s->animCmdIdx == 12) {
    PlaySound_082406e0(SONG_946);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateOrbitFlame, ES_UNK_66);
  }
}

void Skeleton_StateOrbitFlame(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    if ((p->e).hp <= (p->e).unk_546) {
      Skeleton_SpawnOrbitFlamesVaried(p);
    } else if ((Random() & 0xFF) < 64) {
      Skeleton_SpawnOrbitFlamesCounter(p);
    } else {
      Skeleton_SpawnOrbitFlames(p);
    }
  }
  Enemy_PlayAnim(&p->e, 20);
  if (!Entity081f959c_IsAnyActive()) {
    Enemy_EnterState(&p->e, Skeleton_StateOrbitFlameEnd, ES_UNK_67);
  }
}

void Skeleton_StateOrbitFlameEnd(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
    q->volleyActive = 0;
    q->shotsToFire = 0;
    q->unk_70f = 60;
  }
}

void Skeleton_StateSummonEnemyWindUp(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).playerAngle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 19);
  }
  if (s->animCmdTimer == 0 && s->animCmdIdx == 12) {
    PlaySound_082406e0(SONG_946);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateSummonEnemy, ES_UNK_69);
  }
}

void Skeleton_StateSummonEnemy(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Skeleton_SummonEnemy(p);
  }
  Enemy_PlayAnim(&p->e, 20);
  if (Enemy_CountByKind(ENEK_31) == 0) {
    Enemy_EnterState(&p->e, Skeleton_StateSummonEnemyEnd, ES_UNK_70);
  }
}

void Skeleton_StateSummonEnemyEnd(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
    q->volleyActive = 0;
    q->shotsToFire = 0;
    q->unk_70f = 60;
  }
}

void Skeleton_StateCurveShotWindUp(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).playerAngle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 19);
  }
  if (s->animCmdTimer == 0 && s->animCmdIdx == 12) {
    PlaySound_082406e0(SONG_946);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateCurveShot, ES_UNK_50);
  }
}

// 15 フレームごとに前方の頭上から矢 (Entity081f4554) を放ち, 40 フレームで状態51へ移る
// 152/161命令の下書き, 原典は放つ位置を WorldPos の DImode のまま組む, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateCurveShot(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
  Enemy_PlayAnim(&p->e, 20);
  if (Mod(timer, 15) == 0) {
    WorldPos pos = (p->e).mover.pos;
    u8 angle = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) << 6;

    pos.x += POLAR_X(128, angle);
    pos.z += POLAR_Z(128, angle);
    pos.y += 220;
    Entity081f4554_Spawn(&pos, &(p->e).playerMover->pos, 6, 6, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2], 20, q->curveShotScriptID, q->curveShotExplodeScriptID);
  }
  if (timer > 40) {
    Enemy_EnterState(&p->e, Skeleton_StateCurveShotEnd, ES_UNK_51);
  }
#else
  INCFUNC("asm/func/Skeleton_StateCurveShot.inc");
#endif
}

void Skeleton_StateCurveShotEnd(Skeleton* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 21);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

void Skeleton_StateSummonSkeletons(Skeleton* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
  }
  if (s->animCmdIdx == 3 && s->animCmdTimer == 0) {
    Skeleton_SummonSkeleton(p);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Skeleton_StateAttackRecover, ES_UNK_61);
  }
}

NAKED void Skeleton_StateTurn(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateTurn.inc"); }

void Skeleton_StateNap(Skeleton* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 8);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait < 1 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, Skeleton_StateWakeUp, ES_UNK_6);
  }
}

void Skeleton_StateWakeUp(Skeleton* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
  }
  if (timer == 40) {
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// 倒れて髑髏が跳ねる, 始めに判定を隠して乱数の向きと速さで跳ね, 着地したら Enemy_HandleResumeMsg へ知らせる
// 180/175命令の下書き, 原典は跳ねる速さを jumpVel に直接 FixToInt で書く順と乱数の引き方が違う, 1回目の下書きで切り上げ
NON_MATCH void FUN_0810c2dc(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 speed;
    u8 angle;

    Hitbox_Hide(&q->dodgeHitbox);
    Hitbox_Hide(&q->atkHitbox2);
    Hitbox_Hide(&(p->e).hurtbox);
    Hitbox_ClearFlags(&(p->e).hitbox, HBFLAG_HIDDEN);
    angle = (p->e).mover.angle;
    speed = (RandomNext() & 0xF) + 28;
    (p->e).jumpVel.x = POLAR_X(speed, angle);
    (p->e).jumpVel.y = 0;
    (p->e).jumpVel.z = POLAR_Z(speed, angle);
    (p->e).jumpVel.y = (RandomNext() & 0x1F) + 24;
    Enemy_PlayAnim(&p->e, 17);
    ParticleShadow_Show(&(p->e).shadow);
    return;
  }
  if ((p->e).mover.tile->unk_0[0] & 1) {
    (p->e).jumpVel.x = 0;
    (p->e).jumpVel.z = 0;
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    u16 msg;

    if (Skeleton_TestFlags(q, 1 << 11)) {
      PlaySound_082406e0(SE_SKELTON_NOT_DEATH);
    }
    Hitbox_Hide(&(p->e).hitbox);
    msg = 1;
    Enemy_HandleResumeMsg(&p->e, &msg);
  }
#else
  INCFUNC("asm/func/FUN_0810c2dc.inc");
#endif
}

void Skeleton_StateDormant(Skeleton* p, s32 timer) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    Hitbox_Hide(&q->dodgeHitbox);
    Hitbox_Hide(&q->atkHitbox2);
    Enemy_PlayAnim(&p->e, 17);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (!Skeleton_TestFlags(q, 1 << 1) && q->wakeDelay < 20000 && q->wakeDelay < timer) {
    u16 msg = 1;

    Enemy_HandleResumeMsg(&p->e, &msg);
  }
}

void Skeleton_StateRespawnWait(Skeleton* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e) || timer == 30 || timer == 55) {
    Enemy_PlayAnim(&p->e, 18);
  } else if (timer > 95) {
    Enemy_EnterState(&p->e, Skeleton_StateRespawn, ES_UNK_13);
  }
}

NAKED void Skeleton_StateRespawn(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateRespawn.inc"); }

// 辺りを見回し (初回だけ専用アニメ), 60 フレームで経路の目標へ向き直って歩くか追跡に戻る
// 193/195命令の下書き, 原典は &q->flags を持ち越し, 状態の切り替えに 0 のレジスタを使い回す, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateHeardSound(Skeleton* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Skeleton* q = (p->e).owner;

    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7) && !Skeleton_TestFlags(q, 1 << 13)) {
      Enemy_PlayAnim(&p->e, 12);
      Skeleton_SetFlags(q, 1 << 13);
    } else {
      Enemy_PlayAnim(&p->e, 0);
    }
  }
  if (timer > 60) {
    (p->e).subStateDone = 1;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    } else {
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    (p->e).animSpeedDiv = 2;
  }
#else
  INCFUNC("asm/func/Skeleton_StateHeardSound.inc");
#endif
}

NAKED void Skeleton_StateDamaged(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateDamaged.inc"); }

// 追う距離の範囲を外れたら次の行動へ, 範囲内なら プレイヤーの位置への経路を引いて状態15へ移る
// 137/141命令の下書き, 経路を引く部分は Enemy_TryRouteTo の展開, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateHoldPosition(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    return;
  }
  if ((p->e).playerDistSq > q->farDistSq || (p->e).playerDistSq < q->nearDistSq) {
    Skeleton_ClearFlags(q, 1 << 8);
    Skeleton_RetreatOrChase(p);
  } else if (Skeleton_CanAttack(p)) {
    Enemy_PlayAnim(&p->e, 0);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
      Skeleton_ClearFlags(q, 1 << 8);
      Enemy_ResetState(&p->e, 0, 0, 15);
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_StateHoldPosition.inc");
#endif
}

// プレイヤーの方へ向き終わるのを待ち, 正面で距離の範囲を外れたら Skeleton_LichRelocate, 向きが大きくずれていれば振り向き直す
// 141/156命令の下書き, 原典は向きの差を別の形で求め, unk_1dc の計算も展開が違う, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_StateLichHoldPosition(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  s32 d;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
  d = (p->e).playerAngle - (p->e).mover.angle;
  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  if (abs(d) <= 32) {
    if ((p->e).playerDistSq > q->farDistSq || (p->e).playerDistSq < q->nearDistSq) {
      Skeleton_ClearFlags(q, 1 << 8);
      Skeleton_LichRelocate(p);
    }
  } else if (!Skeleton_TestFlags(q, 1 << 10)) {
    (p->e).unk_1dc = (((((((p->e).playerAngle + 0x20) & 0xFF) >> 6) * 64) >> 5) + 3) & 7;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 20);
  }
#else
  INCFUNC("asm/func/Skeleton_StateLichHoldPosition.inc");
#endif
}

// 待ちの間は歩きアニメ, 印 (bit8) が立っていれば, 遠ければ振り向いて追い, 近ければ印を消して次の行動を選ぶ
// 102/109命令の下書き, 原典は &q->flags を持ち越し, 状態の切り替えの枝の並びも違う, 試済: 印の検査と消去を inline (104→102)
NON_MATCH void Skeleton_StateNavWalk(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  if (!Skeleton_TestFlags(q, 1 << 8)) {
    Enemy_PlayAnim(&p->e, 1);
  } else if ((p->e).playerDistSq > q->farDistSq) {
    Enemy_ResetState(&p->e, 0, 0, (p->e).kind == ENEK_LICH ? 20 : 17);
    (p->e).unk_1dc = (((p->e).playerAngle >> 5) + 3) & 7;
  } else {
    Skeleton_ClearFlags(q, 1 << 8);
    if ((p->e).kind == ENEK_LICH) {
      Skeleton_LichRelocate(p);
    } else {
      Skeleton_RetreatOrChase(p);
    }
  }
#else
  INCFUNC("asm/func/Skeleton_StateNavWalk.inc");
#endif
}

void Skeleton_StateFallDeath(Skeleton* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    if (!Skeleton_TestFlags((p->e).owner, 1 << 4)) {
      Enemy_PlayAnim(&p->e, 3);
      Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
    }
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Enemy_ResetState(&p->e, 3, 0, 0);
    (p->e).sleepTimer = 0;
    (p->e).animForceRestart = 0;
    (p->e).hurtbox.iframes = 0;
    (p->e).unk_4be = 0;
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_17);
  }
  if (timer > 6) {
    (p->e).mover.pos.y += (timer - 6) * -30;
    Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
    if (timer > 8) {
      (p->e).hp = 0;
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_3);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_10);
      Enemy_SetEmote(&p->e, 0, 0x7F, 0);
      Enemy_SetEmote(&p->e, 1, 0x7F, 0);
      Enemy_SetEmote(&p->e, 3, 0x7F, 0);
      Enemy_FadeParticles(&p->e, 4);
      Enemy_EnterState(&p->e, Enemy_StateDefeated, ES_DEFEATED);
    }
  }
}

// リッチの撃破演出, 放った弾を消して図鑑に載せ, 画面を揺らしながら 120 フレーム待ってから経験値を渡して破棄へ回す
void Skeleton_StateLichDying(Skeleton* p, s32 timer) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 idx;

    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    if ((p->e).variant == 2) {
      Entity081f53a8_VanishAll();
      Entity081f4554_VanishAll();
    } else {
      Entity081f9cb8_CancelAll();
      Entity081f959c_VanishAll();
    }
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
  }
  Enemy_PlayAnim(&p->e, 10);
  Enemy_ClearDamage(&p->e);
  Camera_Shake(64);
  if (timer > 120) {
    PlaySound_082406e0(SONG_947);
    Skeleton_SpawnDeathFragments(p);
    (p->e).subStateDone = 1;
    (p->e).sleepTimer = 0;
    (p->e).hurtbox.iframes = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    FUN_080e6658(&p->e);
    AddPlayerExp(q->unk_72a);
    ParticleShadow_Hide(&(p->e).shadow);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 3, 0, 0);
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_12);
  }
}

NAKED void Skeleton_StateDying(Skeleton* p) { INCFUNC("asm/func/Skeleton_StateDying.inc"); }

NAKED void Skeleton_StartChase(Skeleton* p) { INCFUNC("asm/func/Skeleton_StartChase.inc"); }

NAKED void FUN_0810f680(Skeleton* p) { INCFUNC("asm/func/FUN_0810f680.inc"); }

void Skeleton_SetHandlerTable3(Skeleton* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad524; }

// 1番の攻撃 (アーチャーは別の状態) を出し, 終わったら次の行動を選ぶ
void Skeleton_SubMelee(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    if ((p->e).kind == ENEK_SKELETON_A) {
      Enemy_EnterState(&p->e, Skeleton_StateArcherMelee, ES_UNK_3);
    } else {
      Enemy_EnterState(&p->e, Skeleton_StateMelee, ES_UNK_3);
    }
    Skeleton_SetAtkHitbox2Attack(p, 1);
    q->atkCooldown0 = q->atkCooldownInit[0];
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Skeleton_RetreatOrChase(p);
  } else {
    (p->e).subStateTimer++;
  }
}

void Skeleton_SubDashAttack(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateDashWindUp, ES_UNK_38);
    q->atkCooldown1 = q->atkCooldownInit[1];
    Skeleton_SetAtkHitbox2Attack(p, 2);
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Skeleton_RetreatOrChase(p);
  } else {
    (p->e).subStateTimer++;
  }
}

void Skeleton_SubDoubleSlash(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateDoubleSlash, ES_UNK_42);
    q->atkCooldown2 = q->atkCooldownInit[2];
    Skeleton_SetAtkHitbox2Attack(p, 3);
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Skeleton_RetreatOrChase(p);
  } else {
    (p->e).subStateTimer++;
  }
}

void Skeleton_SubShoot(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateShootWindUp, ES_UNK_43);
    q->shootTargetPos = (p->e).playerMover->pos;
    q->atkCooldown1 = q->atkCooldownInit[1];
    Skeleton_SetAtkHitbox2Attack(p, 2);
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Skeleton_RetreatOrChase(p);
  } else {
    (p->e).subStateTimer++;
  }
}

NAKED void Skeleton_SubKeepDistance(Skeleton* p) { INCFUNC("asm/func/Skeleton_SubKeepDistance.inc"); }

// 状態46 の攻撃が終わったら Skeleton_PickFarPathNode で選んだ経路ノードへ経路を引き, 引けたら relocateCooldown を 320 にして状態16の副状態18へ
// 状態49 の攻撃が終わったら Skeleton_PickFarPathNode で選んだ経路ノードへ経路を引き, 引けたら relocateCooldown を 320 にして状態16の副状態18へ
// 175/175命令, 残差は &flags3 と &mover.pos の r4 / r5 の割当だけ, 経路を引く部分は Enemy_TryRouteTo の展開, 試済: 宣言順 (変化なし)
NON_MATCH void Skeleton_SubVolley(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateVolleyWindUp, ES_UNK_46);
  }
  if ((p->e).subStateDone) {
    WorldPos* from;
    WorldPos to;

    q->atkCooldown0 = q->atkCooldownInit[0];
    q->atkCooldown1 = 100;
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_8);
    from = &(p->e).mover.pos;
    Skeleton_PickFarPathNode(p, &to, from, 0x40000);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
      q->relocateCooldown = 320;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubVolley.inc");
#endif
}

// 175/175命令, 残差は &flags3 と &mover.pos の r4 / r5 の割当だけ, 経路を引く部分は Enemy_TryRouteTo の展開, 試済: 宣言順 (変化なし)
NON_MATCH void Skeleton_SubCurveShot(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateCurveShotWindUp, ES_UNK_49);
  }
  if ((p->e).subStateDone) {
    WorldPos* from;
    WorldPos to;

    q->atkCooldown0 = 100;
    q->atkCooldown1 = q->atkCooldownInit[1];
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_8);
    from = &(p->e).mover.pos;
    Skeleton_PickFarPathNode(p, &to, from, 0x40000);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
      q->relocateCooldown = 320;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubCurveShot.inc");
#endif
}

void Skeleton_SubSummonSkeletons(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateSummonSkeletons, ES_UNK_53);
  }
  if ((p->e).subStateDone) {
    q->atkCooldown2 = q->atkCooldownInit[2];
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Skeleton_LichRelocate(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// 1番の攻撃 (状態62) が終わったら Skeleton_PickFarPathNode で選んだ経路ノードへ経路を引き, 引けたら relocateCooldown を 320 にして状態16の副状態18へ
// 169/171命令の下書き, 経路を引く部分は Enemy_TryRouteTo の展開, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SubHomingMissile(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateHomingMissileWindUp, ES_UNK_62);
  }
  if ((p->e).subStateDone) {
    WorldPos to;
    WorldPos* from;

    q->atkCooldown0 = q->atkCooldownInit[0];
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    from = &(p->e).mover.pos;
    Skeleton_PickFarPathNode(p, &to, from, 0x40000);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
      q->relocateCooldown = 320;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubHomingMissile.inc");
#endif
}

// 状態65 の攻撃が終わったら Skeleton_PickFarPathNode で選んだ経路ノードへ経路を引き, 引けたら relocateCooldown を 320 にして状態16の副状態18へ
// 187/187命令, Skeleton_SubVolley と同じ残差 (レジスタの割当), 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SubOrbitFlame(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateOrbitFlameWindUp, ES_UNK_65);
    SET_FLAGS(q->lichAtkFlags, 1 << 0);
  }
  if ((p->e).subStateDone) {
    WorldPos* from;
    WorldPos to;

    CLEAR_FLAGS(q->lichAtkFlags, 1 << 0);
    q->atkCooldown0 += 100;
    q->atkCooldown1 = q->atkCooldownInit[1];
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_8);
    from = &(p->e).mover.pos;
    Skeleton_PickFarPathNode(p, &to, from, 0x40000);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
      q->relocateCooldown = 320;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubOrbitFlame.inc");
#endif
}

// 状態68 の攻撃が終わったら Skeleton_PickFarPathNode で選んだ経路ノードへ経路を引き, 引けたら relocateCooldown を 320 にして状態16の副状態18へ
// 186/186命令, Skeleton_SubVolley と同じ残差に加え, 原典は lichAtkFlags を owner + 0x6FC 基点で触る, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SubSummonEnemy(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Skeleton_StateSummonEnemyWindUp, ES_UNK_68);
    SET_FLAGS(q->lichAtkFlags, 1 << 1);
  }
  if ((p->e).subStateDone) {
    WorldPos* from;
    WorldPos to;

    CLEAR_FLAGS(q->lichAtkFlags, 1 << 1);
    q->atkCooldown2 = q->atkCooldownInit[2];
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_8);
    from = &(p->e).mover.pos;
    Skeleton_PickFarPathNode(p, &to, from, 0x40000);
    if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, from, &to)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 18);
      q->relocateCooldown = 320;
    } else {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubSummonEnemy.inc");
#endif
}

void Skeleton_SetHandlerTable4(Skeleton* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad52c; }

NAKED bool8 Skeleton_OnDamaged(Skeleton* p) { INCFUNC("asm/func/Skeleton_OnDamaged.inc"); }

bool8 Skeleton_LichOnDamaged(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  u16 msg;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  msg = 7;
  Enemy_SendMsgByKind(ENEK_SKELETON, &msg);
  Enemy_SendMsgByKind(ENEK_SKELETON_F, &msg);
  Enemy_SendMsgByKind(ENEK_SKELETON_A, &msg);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_15)) {
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if (q->atkCooldown0 > 0) {
    q->atkCooldown0 -= 30;
  }
  if (q->atkCooldown0 < 0) {
    q->atkCooldown0 = 0;
  }
  if (q->atkCooldown1 > 0) {
    q->atkCooldown1 -= 30;
  }
  if (q->atkCooldown1 < 0) {
    q->atkCooldown1 = 0;
  }
  if (q->atkCooldown2 > 0) {
    q->atkCooldown2 -= 30;
  }
  if (q->atkCooldown2 < 0) {
    q->atkCooldown2 = 0;
  }
  Skeleton_LichSelectAction(p);
  return TRUE;
}

// リッチの被弾への反応, プレイヤーの足元に罠 (Entity081f9cb8) を仕掛け, 眠りや石化でなければ Skeleton_LichPSelectAction で動き直す
// 129/133命令の下書き, 原典は flags3 の読み直しの位置と罠を仕掛ける部分の展開が違う, 1回目の下書きで切り上げ
NON_MATCH bool8 Skeleton_LichPOnDamaged(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;
  EnemyFlags3 flags3;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  flags3 = (p->e).flags3;
  (p->e).flags3 = flags3 & ~ENEFLAG3_UNK_5;
  if (!(flags3 & (ENEFLAG3_UNK_1 | ENEFLAG3_UNK_15))) {
    if (!(q->lichAtkFlags & 1) && !Entity081f9cb8_ExistsAt(&gPlayerPtr[0]->mover.pos)) {
      Entity081f9cb8_Spawn(&gPlayerPtr[0]->mover.pos, (p->e).hp <= (p->e).unk_546 ? 40 : 60, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    }
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Skeleton_LichPSelectAction(p);
    }
    return TRUE;
  }
  if ((flags3 & ENEFLAG3_UNK_15) && !Entity081f9cb8_ExistsAt(&gPlayerPtr[0]->mover.pos)) {
    Entity081f9cb8_Spawn(&gPlayerPtr[0]->mover.pos, (p->e).hp <= (p->e).unk_546 ? 40 : 60, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  }
  return FALSE;
#else
  INCFUNC("asm/func/Skeleton_LichPOnDamaged.inc");
#endif
}

// 経路に沿って歩き, 目的地に着いたら次のサブ状態へ移る
void Skeleton_SubWalk(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Skeleton_StateNavWalk, ES_UNK_58);
    Skeleton_SetFlags(q, 1 << 9);
  }
  if (Skeleton_CanAttack(p)) {
    if ((p->e).tryDetectPlayer(&p->e)) {
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      return;
    }
  }
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 16);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
      return;
    }
  } else {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Skeleton_SetFlags(q, 1 << 8);
      return;
    }
  }
  (p->e).subStateTimer++;
}

void Skeleton_SubWalkTurn(Skeleton* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!Skeleton_CanAttack(p) || (!(p->e).tryDetectPlayer(&p->e) && !FUN_080f0a0c(&p->e))) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 15);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void Skeleton_SubTurnToPlayer(Skeleton* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!Skeleton_CanAttack(p) || (!(p->e).tryDetectPlayer(&p->e) && !FUN_080f0a0c(&p->e))) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, Skeleton_StateHoldPosition, ES_UNK_59);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// 経路に沿って歩き, 着いたときプレイヤーが近ければ攻撃を選び, 遠ければプレイヤーの方を向いて待機へ移る
void Skeleton_SubRelocate(Skeleton* p) {
  Skeleton* self = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Skeleton_StateNavWalk, ES_UNK_58);
    Skeleton_SetFlags(self, 1 << 9);
  }
  (p->e).tryDetectPlayer(&p->e);
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
      return;
    }
  } else {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Skeleton_SetFlags(self, 1 << 8);
      if ((p->e).playerDistSq < 0x40000) {
        Skeleton_RouteToFarPathNode(p, self, 0x100000);
        return;
      }
      Enemy_ResetState(&p->e, 0, 0, 20);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
      (p->e).unk_1dc = (FixToInt(5, (p->e).playerAngle) + 3) & 7;
      return;
    }
  }
  (p->e).subStateTimer++;
}

void Skeleton_SubRelocateTurn(Skeleton* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  (p->e).tryDetectPlayer(&p->e);
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 18);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    (p->e).subStateTimer++;
  }
}

void Skeleton_SubLichTurnToPlayer(Skeleton* p) {
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    Skeleton_SetFlags(q, 1 << 10);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Skeleton_StateLichHoldPosition, ES_UNK_59);
    CLEAR_FLAGS(q->flags, 1 << 10);
  } else {
    (p->e).subStateTimer++;
  }
}

// 経路に沿って歩き, 着いたらプレイヤーの方を向いて待機へ移る
void Skeleton_SubWalkToAttackSpot(Skeleton* p) {
  Skeleton* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Skeleton_StateNavWalk, ES_UNK_58);
    Skeleton_SetFlags(q, 1 << 9);
    Skeleton_ClearFlags(q, 1 << 8);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 22);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    }
  } else {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 23);
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
      (p->e).unk_1dc = (FixToInt(5, (p->e).playerAngle) + 3) & 7;
      return;
    }
  }
  (p->e).subStateTimer++;
}

void Skeleton_SubWalkToAttackSpotTurn(Skeleton* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 21);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    (p->e).subStateTimer++;
  }
}

// 振り向き終わったら lichAtkFlags の印 (bit3 か bit2) に応じて副状態9か8の攻撃へ移る
// 171/192命令の下書き, 原典は2つの枝で lichAtkFlags から落とすビットを変数に入れて最後に1回だけ書く, 1回目の下書きで切り上げ
NON_MATCH void Skeleton_SubStartQueuedAttack(Skeleton* p) {
#ifdef NONMATCHING_C
  Skeleton* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    Skeleton_SetFlags(q, 1 << 10);
  }
  if ((p->e).subStateDone) {
    Skeleton_ClearFlags(q, 1 << 10);
    if (q->lichAtkFlags & 8) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 9);
      q->lichAtkFlags &= ~8;
    } else {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 2, 8);
      q->lichAtkFlags &= ~4;
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Skeleton_SubStartQueuedAttack.inc");
#endif
}

void Skeleton_SetHandlerTable2(Skeleton* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad558; }

s32 Skeleton_UpdateFrame(Skeleton* p) {
  Enemy* e = &p->e;

  if (e->kind == ENEK_LICH) {
    Skeleton_LichPreUpdate(p);
  } else {
    Skeleton_PreUpdate(p);
  }
  if (TEST_FLAGS(e->flags3, ENEFLAG3_UNK_13) || e->unk_4be == 0) {
    u32 idx = e->subState0;
    EnemyHandler* table = e->handlerTables[0];

    table[idx](e);
    Enemy_RunStateHandler(e);
  }
  Skeleton_PostUpdate(p);
  return 1;
}

s32 Skeleton_Update(Skeleton* p) {
  Enemy* e = &p->e;

  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return FALSE;
  }

  if (!Enemy_TestFlag(e, ENEFLAG_UNK_1)) {
    if (!IsCurrentZone(e->zoneID)) {
      Enemy_Suspend(e, NULL);
      return FALSE;
    }

    if (!Enemy_IsDead(e) && !Skeleton_TestFlags(p, 1 << 4) && !e->unk_624(e)) {
      e->unk_628(e);
    }
    Enemy_ProcessRequests(e);
    FUN_080e1f48(e);
    e->handlerFrame(e->owner);
    Enemy_UpdateHitboxes(e);
    Enemy_UpdateMovement(e);
    Enemy_ShakeSprite(e);
    FUN_080f06ac(e);
    return TRUE;
  }

  if (!Enemy_TestFlag(e, ENEFLAG_UNK_0) && IsCurrentZone(e->zoneID)) {
    Enemy_Resume(e, NULL);
  }
  FUN_080f06ac(e);
  return FALSE;
}

s32 Skeleton_Destroy(Skeleton* p) {
  Hitbox_Unregister(&p->dodgeHitbox);
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
NAKED s32 Skeleton_Init(Skeleton* p) { INCFUNC("asm/func/Skeleton_Init.inc"); }

void Skeleton_Create(void) {
  Skeleton* p = Malloc(sizeof(Skeleton));

  if (p != NULL) {
    ClearMemory(p, sizeof(Skeleton));
    if (Skeleton_Init(p) < 0) {
      Skeleton_Destroy(p);
      Free(p);
    }
  }
}
