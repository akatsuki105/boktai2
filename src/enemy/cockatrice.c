#include "camera.h"
#include "constants/weapon.h"
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
#include "inline.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_common.h"
#include "vec3.h"
#include "vm.h"

// Cockatrice.flags (0x700)
typedef u32 CockatriceFlags;
#define COCKAFLAG_UNK_18 (1 << 18)       // 0x00040000
#define COCKAFLAG_UNK_0 (1 << 0)         // 0x00000001
#define COCKAFLAG_UNK_19 (1 << 19)       // 0x00080000
#define COCKAFLAG_UNK_2 (1 << 2)         // 0x00000004
#define COCKAFLAG_FLEEING (1 << 5)       // 0x00000020
#define COCKAFLAG_AT_FLEE_NODE (1 << 6)  // 0x00000040
#define COCKAFLAG_AIRBORNE (1 << 1)      // 0x00000002, 宙に浮いている (heightAboveFloor > 0), 移動の速さを速い表から取り歩きアニメの代わりに 17 番を流す
#define COCKAFLAG_DODGING (1 << 3)       // 0x00000008, 攻撃を感じ取って跳んでかわしている, 立っている間は食らい判定を受けない

// Cockatrice.flags2 (0x704)
typedef u32 CockatriceFlags2;
#define COCKAFLAG2_UNK_0 (1 << 0)  // 0x00000001, 歩きのアニメが等速のとき立つ

// ENEK_COCKA(EV_COCKA, EV_COCKA_P)
// 石化光線を放つ
typedef struct {
  Enemy e;
  u8 unk_654[4];            // 0x654
  HitboxData senseHitbox;   // 0x658, 攻撃が来るのを感じ取る大きめの判定, Cockatrice_OnSenseAttack が受ける
  Vec3 jumpVel;             // 0x6A8, 跳ぶ速さ, x と z は jumpTarget まで 18 フレームで着く速さ, y は上向き 20 から
  Vec3 jumpTarget;          // 0x6B0, 跳んで着く先
  s16 lookTimer;            // 0x6B8, 歩いている間に減り, 尽きたら見回しを始める (120 の 1〜4 倍で張り直す)
  s16 lookDir;              // 0x6BA, 見回す先の8方向
  u8 unk_6bc[2];            // 0x6BC
  u16 lookBaseAngle;        // 0x6BE, 見回しを始めたときの向き
  u16 lookCount;            // 0x6C0, 見回しで向きを選び直す残り回数 (Cockatrice_TryLookAround が 4 にする)
  u16 unk_6c2;              // 0x6C2
  u8 riseAngle;             // 0x6C4, 上がるときの sin の角度, 1回に 12 進む
  u8 shotSpeed;             // 0x6C5, 撃つ弾の速さ
  u16 shotLifetime;         // 0x6C6, 撃つ弾の寿命
  s16 hopTimer;             // 0x6C8, 0 になると状態1では跳ぶ前の構えへ移り flightDuration で, 状態35では walkDuration で張り直す
  s16 riseHeight;           // 0x6CA, ここまで heightAboveFloor を上げる
  s16 unk_6cc;              // 0x6CC
  u16 fallFrames;           // 0x6CE, 落ち始めてからのフレーム数, 1 フレームに 2 倍ずつ落ちる
  u32 fireRangeSq;          // 0x6D0, unk_1e8 の 7/10, プレイヤーとの距離の 2 乗がこれ以上なら撃つ
  u32 unk_6d4;              // 0x6D4
  u8 unk_6d8[4];            // 0x6D8
  s16 fleeTimer;            // 0x6DC
  u16 fleeDuration;         // 0x6DE
  s16 dodgeCooldown;        // 0x6E0, 次にかわせるまでのフレーム数 (かわすと 120)
  s16 fireCooldown;         // 0x6E2, 次に弾を撃てるまでのフレーム数
  s16 backstepCooldown;     // 0x6E4, 次に後ろへ跳び退けるまでのフレーム数, 跳び退くと backstepInterval
  s16 unk_6e6;              // 0x6E6
  s16 unk_6e8;              // 0x6E8
  s16 shotCount;            // 0x6EA, 撃つアニメをあと何回流すか
  s16 walkDuration;         // 0x6EC
  s16 flightDuration;       // 0x6EE
  s16 backstepInterval;     // 0x6F0, 'P' の4番目, 跳び退いたあとの backstepCooldown
  s16 fireInterval;         // 0x6F2, 'P' の3番目, 撃ったあとの fireCooldown
  WorldPos lastSeenPos;     // 0x6F4, 気付いたときのプレイヤーの位置, COCKAFLAG_UNK_19 の間ここへ向かう
  u16 fleePathIdx;          // 0x6FC, 'U', 逃げるときにたどる経路の番号 (省略時は unk_250)
  u16 fleeNodeIdx;          // 0x6FE, 逃げ先に選んだ fleePathIdx の経路のノード番号
  CockatriceFlags flags;    // 0x700, see CockatriceFlags
  CockatriceFlags2 flags2;  // 0x704, see CockatriceFlags2
  NavAgent navAgent;        // 0x708, Enemy.navAgent が指す
  Vec3 pathNodePos;         // 0x72C, Enemy.pathNodePos が指す
} Cockatrice;
static_assert(sizeof(Cockatrice) == 1844);

static inline bool8 Cockatrice_TestFlags(Cockatrice* p, CockatriceFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

// 振り向きアニメ (1 番の variant) を流す, MainSprite では 1 + variant 番を流し, 逆再生でなければ同じものが流れているとき何もしない
static inline void Cockatrice_PlayTurnAnim(Cockatrice* p, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = 1;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, 1, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    u32 anim = variant + 1;

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

static inline void Cockatrice_SetFlags(Cockatrice* p, CockatriceFlags bits) { p->flags |= bits; }
static inline void Cockatrice_ClearFlags(Cockatrice* p, CockatriceFlags bits) { p->flags &= ~bits; }

const STRING_DATA char s_eneinline_082520f0[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252108[] = "../system/eneinline.h";

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
  Enemy_ClearPendingState(p, s_eneinline_082520f0, 2434);
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

void* Entity081e9cacElem_Remove(void* elem);
void* Entity081e9cac_Spawn(Vec3* pos, Vec3* offset, Vec3* vel, u32 angle, u32 hitboxId, s32 power, s32 knockback, s32 iframes, s32 lifetime);
void Entity081e9cacElem_Launch(void* elem);
// 8方向に丸めた向きへ shotSpeed で飛ぶ弾を頭の高さに作り, 2番の攻撃の組を載せて unk_264 に持つ
void Cockatrice_SpawnShot(Cockatrice* p);
void Cockatrice_StateWakeUp(Cockatrice* p, s32 timer);
void Cockatrice_TryLookAround(Cockatrice* p);
bool8 Cockatrice_CanSeePlayerAhead(Cockatrice* p);
s32 Cockatrice_SetLongJumpTarget(Cockatrice* p);
void Cockatrice_TryEndFlee(Cockatrice* p);
void Cockatrice_StateFly(Cockatrice* p);
void Cockatrice_PlayIdleAnim(Cockatrice* p);
void Entity08015584_SpawnSpray(s32 count, u32 kind, u32 flags, u32 animSpeed, WorldPos* pos);
void Cockatrice_SpawnStoneShards(Cockatrice* p, s32 count);
void Cockatrice_StatePrepareJump(Cockatrice* p);
void Cockatrice_StartFlee(Cockatrice* p);
void FUN_080e6834(Enemy* p, s32 timer);
void Cockatrice_StateLookTurn(Cockatrice* p);
void Cockatrice_TryFire(Cockatrice* p);
void Cockatrice_StateJumpDown(Cockatrice* p, s32 timer);
void Cockatrice_SetJumpTargetAhead(Cockatrice* p);
s32 Cockatrice_StartJump(Cockatrice* p);
bool8 FUN_080f0a0c(Enemy* p);
void Cockatrice_FleeToPathNode(Cockatrice* p);
void Cockatrice_StateLand(Cockatrice* p);
void Cockatrice_StateDescend(Cockatrice* p, s32 timer);
bool8 Cockatrice_StepJump(Cockatrice* p, Vec3* vel, s32 mode, s32 gravity, s32 t);
s32 Cockatrice_SetHopVel(Cockatrice* p, s32 noRise, s32 unused);
void Cockatrice_StateWaitEmote(Cockatrice* p, s32 timer);
void Cockatrice_ChooseAttack(Cockatrice* p);
void Cockatrice_StateFlee(Cockatrice* p);
// 前から来た攻撃をかわす, 撃ちかけの弾を消して跳び上がり, 追いかけていなければ追いかけの印を消して攻撃元へ向き直る
void Cockatrice_StartDodge(Cockatrice* p);
// 正面の unk_1fd 以内から銃以外の攻撃が来たのを感じ取ったら, 手が空いていれば Cockatrice_StartDodge で応じる
void Cockatrice_OnSenseAttack(HitboxData* a, HitboxData* b, Cockatrice* p);
void Cockatrice_OnHit(HitboxData* a, HitboxData* b, Cockatrice* p);
void Cockatrice_OnHurt(HitboxData* a, HitboxData* b, Cockatrice* p);
void Cockatrice_StateRespawn(Cockatrice* p);
void Cockatrice_UpdateHitboxes(Cockatrice* p);
void Cockatrice_HandleHurt(HitboxData* a, HitboxData* b, Cockatrice* p);
void Cockatrice_ReleaseSharedEntity(Cockatrice* p);
void Cockatrice_UpdateLookTimer(Cockatrice* p);
void Cockatrice_UpdateSenseHitbox(Cockatrice* p);
void Cockatrice_UpdateAirState(Cockatrice* p);
// 生きている間 fireCooldown と backstepCooldown を, COCKAFLAG_AT_FLEE_NODE の間は unk_6e8 も 0 まで1ずつ減らす
void Cockatrice_TickTimers(Cockatrice* p);
// 状態 38 / 42 の間は攻撃判定の威力とノックバックを2番の組に, それ以外は0番の組にする
void Cockatrice_UpdateAtkPower(Cockatrice* p);
void Cockatrice_TickFleeTimer(Cockatrice* p);
// プレイヤーに気付いて向き直り, 感情アイコンとスクリプトを出して追いかけを始める
void Cockatrice_StartChase(Cockatrice*);
void FUN_0815758c(Cockatrice*);
void FUN_08157df4(Cockatrice*);

void (*const sCockatriceHandlerTable3[3])(Cockatrice*) = {
    Cockatrice_StartChase,
    FUN_0815758c,
    FUN_08157df4,
};  // 0x085AD940

void Cockatrice_SubWaitThenReturn(Cockatrice*);
void Cockatrice_SubChaseMove(Cockatrice*);
void Cockatrice_SubChaseTurn(Cockatrice*);
void Cockatrice_SubChaseReroute(Cockatrice*);
void Cockatrice_SubMoveToPathNode(Cockatrice*);
void Cockatrice_SubPathNodeWait(Cockatrice*);
void Cockatrice_SubMoveToGoal(Cockatrice*);
void Cockatrice_OnReset(Cockatrice* p);
bool8 FUN_0815d6d0(Cockatrice* p);
void Cockatrice_PauseBeforeMove(Cockatrice* p);
void Cockatrice_RestAndResumeRoute(Cockatrice* p);
void Cockatrice_PlayFireAnim(Cockatrice* p);
void FUN_08161b90(Cockatrice* p);
void Cockatrice_StateCrumble(Cockatrice* p, s32 timer);
void Cockatrice_StateHopUp(Cockatrice* p, s32 timer);
void Cockatrice_StateJumpUp(Cockatrice* p, s32 timer);
void Cockatrice_StateTakeOff(Cockatrice* p, s32 timer);
void Cockatrice_SubGiveUpChase(Cockatrice*);
void Cockatrice_SubFleeMove(Cockatrice*);
void Cockatrice_SubFleeTurn(Cockatrice*);

// clang-format off
void (*const sCockatriceHandlerTable2[21])(Cockatrice*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    Cockatrice_SubWaitThenReturn,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    Cockatrice_SubChaseMove,
    Cockatrice_SubChaseTurn,
    Cockatrice_SubChaseReroute,
    Cockatrice_SubMoveToPathNode,
    Cockatrice_SubPathNodeWait,
    Cockatrice_SubMoveToGoal,
    Cockatrice_SubGiveUpChase,
    Cockatrice_SubFleeMove,
    Cockatrice_SubFleeTurn,
};  // 0x085AD94C
// clang-format on

void FUN_081589f0(Cockatrice*);
void FUN_08158a08(Cockatrice*);

void (*const sCockatriceHandlerTable4[2])(Cockatrice*) = {
    FUN_081589f0,
    FUN_08158a08,
};  // 0x085AD9A0

const u16 sCockatriceFastMoveSpeeds[4] = {512, 256, 384, 408};                         // 0x085AD9A8
const u16 sCockatriceMoveSpeeds[10] = {674, 674, 0, 578, 642, 674, 674, 0, 578, 642};  // 0x085AD9B0

void Cockatrice_OnHit(HitboxData* a, HitboxData* b, Cockatrice* p) { Enemy_SetHitTarget(&p->e, b); }

void Cockatrice_OnHurt(HitboxData* a, HitboxData* b, Cockatrice* p) {
  if (!Enemy_IsDead(&p->e) && !Cockatrice_TestFlags((p->e).owner, COCKAFLAG_DODGING)) {
    Cockatrice_HandleHurt(a, b, p);
  }
}

// 正面の unk_1fd 以内から銃以外の攻撃が来たのを感じ取ったら, 手が空いていれば Cockatrice_StartDodge で応じる
void Cockatrice_OnSenseAttack(HitboxData* a, HitboxData* b, Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Hitbox_TestFlags(b, HBFLAG_HIDDEN) && (p->e).hurtbox.iframes == 0 && q->dodgeCooldown <= 0 &&
      !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15) && !Hitbox_HasWeakness(a, 1 << WK_GUN) && !Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
    s32 d = ((a->angle + 0x80) & 0xFF) - (p->e).mover.angle;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) <= (p->e).unk_1fd && !Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
      Cockatrice_StartDodge(p);
    }
  }
}

void Cockatrice_StateMove(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
  if ((p->e).animSpeedDiv == 1) {
    SET_FLAGS(q->flags2, COCKAFLAG2_UNK_0);
  }
}

void Cockatrice_StateWait(Cockatrice* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// 経路ノードの向きへ振り向く, 回る向きの振り向きアニメを流してコマごとに 16 ずつ回し, アニメが終わったら向きが合っていれば止まり合っていなければ状態2へ戻す
// 732/721命令, Golem_StateTurn と同じ形と同じ壁 (原典は p を2本のレジスタに持つ), 振り向きアニメは Cockatrice_PlayTurnAnim, 違いは経路ノードの向きを取らない条件に COCKAFLAG_FLEEING が加わり, 回す幅が 16 でアニメの頭のコマでは回さない点, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateTurn(Cockatrice* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 dir;
    u32 target;

    (p->e).mover.angle = ((((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3) * 64 - 64;
    dir = (((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3;
    if ((p->e).subState2 != 6 && !Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_10) && !Cockatrice_TestFlags((p->e).owner, COCKAFLAG_FLEEING)) {
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
          Cockatrice_PlayTurnAnim(p, 1, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Cockatrice_PlayTurnAnim(p, 0, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 1: {
        if (target - 4 < 4) {
          Cockatrice_PlayTurnAnim(p, 2, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Cockatrice_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 2: {
        if (target - 1 > 4) {
          Cockatrice_PlayTurnAnim(p, 1, ANIM_PLAY_REVERSE | ANIM_PLAY_XFLIP);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Cockatrice_PlayTurnAnim(p, 2, ANIM_PLAY_REVERSE);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 3: {
        if (target < 4) {
          Cockatrice_PlayTurnAnim(p, 0, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Cockatrice_PlayTurnAnim(p, 1, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
    }
    (p->e).animForceRestart = FALSE;
  }
  if ((p->e).s->aux.anim.tick == 0 && (p->e).s->aux.anim.cmdIdx != 0) {
    u32 target = ((p->e).unk_1dc + 5) & 7;
    u8 angle = (p->e).mover.angle;

    if (abs(angle - target * 32) < 17) {
      (p->e).mover.angle = target * 32;
    } else if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle = angle + 16;
    } else {
      (p->e).mover.angle = angle - 16;
    }
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).animForceRestart) {
    s32 dir = (((((p->e).mover.angle + 0x10) & 0xFF) >> 5) + 3) & 7;
    s32 d = (p->e).unk_1dc - dir;

    if (d < 0) {
      d = -d;
    }
    if (d > 0) {
      Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    } else {
      (p->e).subStateDone = 1;
      (p->e).mover.angle = ((((((p->e).mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3) * 64 - 64;
      Enemy_PlayAnim(&p->e, 0);
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_10)) {
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      }
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_StateTurn.inc");
#endif
}

void Cockatrice_StateNap(Cockatrice* p, s32 timer) {
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
    Enemy_EnterState(&p->e, Cockatrice_StateWakeUp, ES_UNK_6);
  }
}

void Cockatrice_StateWakeUp(Cockatrice* p, s32 timer) {
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

// 姿と影を隠して 27 フレーム待ち, 出てくるアニメを逆に流しながら Cockatrice_StateRespawn へ移る
void Cockatrice_StateRespawnWait(Cockatrice* p, s32 timer) {
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnimFlags(&p->e, 10, ANIM_PLAY_REVERSE);
    Enemy_EnterState(&p->e, Cockatrice_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// 姿を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Cockatrice_StateRespawn(Cockatrice* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  if ((p->e).animForceRestart) {
    Cockatrice_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// 感情アイコンが消えるか 30 フレーム経つまで止まって待つ, 宙に浮いていれば 17 番のアニメの頭で足音を鳴らす
void Cockatrice_StateWaitEmote(Cockatrice* p, s32 timer) {
  Cockatrice* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  Enemy_ConsumeStateBegun(&p->e);
  if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    Enemy_PlayAnim(&p->e, 17);
    if (anim->cmdIdx == 0 && anim->tick == 0) {
      PlaySound_082406e0(SONG_465);
    }
  } else {
    Enemy_PlayAnim(&p->e, 0);
  }
  if (Emote_IsInactive((p->e).emote) || timer > 30) {
    (p->e).subStateDone = 1;
  }
}

// 音を聞いて立ち止まり, 60 フレーム後に追いかけ中なら追跡へ, そうでなければ宙に浮いているかに応じて経路移動に戻る
// 206/213命令, Golem_StateHeardSound と同じ流れに宙に浮いているかの分岐を足したもの, 原典は宙に浮いているかを bool に作り置いて枝の 0 に使い回す, 試済: 追跡の枝の順
NON_MATCH void Cockatrice_StateHeardSound(Cockatrice* p, s32 timer) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animForceRestart = 0;
  }
  Cockatrice_PlayIdleAnim(p);
  if (timer > 60) {
    (p->e).subStateDone = 1;
    Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    } else {
      if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
        Enemy_EnterState(&p->e, Cockatrice_StateFly, ES_UNK_35);
        Enemy_ResetState(&p->e, 0, 0, 17);
      } else {
        Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
        Enemy_ResetState(&p->e, 0, 0, 7);
      }
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    }
    (p->e).animSpeedDiv = 2;
  }
#else
  INCFUNC("asm/func/Cockatrice_StateHeardSound.inc");
#endif
}

// 入場時に向きを 8 方向に揃え, 60 フレームを超えてアニメが一巡したら経路の今のノードへ向かう, 向かえなければ状態0へ戻す
// 280/281命令, enedefault.c の FUN_080f5fac と同じ流れで残差も同じ (状態フィールドへのストアの並びと定数のレジスタ), 試済: 経路を moved の bool で書く (283命令), Enemy_TryRouteTo
NON_MATCH void Cockatrice_StateRecover(Cockatrice* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).angle + 3) & 7) << 5) - 0x40;
    Enemy_PlayAnim(&p->e, 0);
  }
  if (timer > 60 && (p->e).animForceRestart) {
    Vec3* target;
    PathWalker* walker;

    (p->e).subStateDone = 1;
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
    target = (p->e).pathNodePos;
    walker = &(p->e).pathWalker;
    target->x = walker->node->x;
    target->z = walker->node->y;
    target->y = TileHeightAt(target);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else {
      (p->e).pathNodePos->val = 1;
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
      (p->e).animSpeedDiv = 1;
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_StateRecover.inc");
#endif
}

// hp が残る被弾で怯み, 押し出しを寄せきってアニメが終わったら, 逃げる印があれば逃げ先へ, 追いかけていなければ Cockatrice_StateFlee へ, 追いかけていればプレイヤーへ経路を引き直す
// 977/1084命令の粗い下書き, Boku_StateDamaged の下書きに逃げる印 (COCKAFLAG_FLEEING) の枝を足し, 追いかけ中の後半を FUN_0815b8d0 の形にしたもの, 原典はプレイヤーへ向かう部分をもう1回展開しているはず (Boku と同じ), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateDamaged(Cockatrice* p, s32 timer) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;
  s32 tile;
  s32 idx;
  bool8 moved;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_8);
    (p->e).animForceRestart = 0;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (timer < 18 && anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if (!Enemy_StepSlide(&p->e)) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_19)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_1);
    return;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
    Enemy_EnterState(&p->e, Cockatrice_StateFlee, ES_UNK_52);
    Enemy_ResetState(&p->e, 0, 0, 19);
    Cockatrice_FleeToPathNode(p);
    Cockatrice_ClearFlags(q, COCKAFLAG_AT_FLEE_NODE);
    return;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Cockatrice_StartFlee(p);
    Enemy_EnterState(&p->e, Cockatrice_StateFlee, ES_UNK_52);
    Enemy_ResetState(&p->e, 0, 0, 19);
    return;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
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
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
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
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }
  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
  }
  if (!moved) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Cockatrice_StateDamaged.inc");
#endif
}

// 気絶して sleepTimer が尽きるまで止まり (残り 30〜120 で点滅), 押し出しを寄せきって明けたら石の破片を散らして Cockatrice_StateRecover へ移る
void Cockatrice_StateStunned(Cockatrice* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    PlaySound_082406e0(SONG_466);
    (p->e).sleepTimer = (p->e).unk_18e;
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_6 | ENEFLAG2_UNK_14);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_25);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_8);
    (p->e).unk_494 = 0;
  }
  if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if ((p->e).sleepTimer >= 30 && (p->e).sleepTimer < 120) {
    if (Mod((s16)(p->e).sleepTimer, 30) < 15 - Div((s16)(p->e).sleepTimer, 10)) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
  }
  if (Enemy_StepSlide(&p->e) && (s16)(p->e).sleepTimer <= 0) {
    (p->e).sleepTimer = 0;
    (p->e).subStateDone = 1;
    (p->e).angle = (((p->e).mover.angle >> 5) + 7) & 7;
    Enemy_ClearDamage(&p->e);
    PlaySound_082406e0(SONG_467);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15);
    Cockatrice_SpawnStoneShards(p, 6);
    FUN_08161b90((p->e).owner);
    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Cockatrice_StateRecover, ES_UNK_15);
  }
}

// 倒れるアニメが終わったら, ENEFLAG_UNK_10 が立っていればその場で倒されたスクリプトを呼んで図鑑に載せ, なければ崩れる状態へ移る
void Cockatrice_StateDying(Cockatrice* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = 0;
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if (timer < 35) {
    anim->tick = 0;
  }
  if (anim->cmdIdx == 7 && anim->tick == 4 && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_2)) {
    PlaySound_082406e0(SONG_466);
  }
  if ((p->e).animForceRestart) {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    ParticleShadow_Hide(&(p->e).shadow);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
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
      (p->e).sleepTimer = 0;
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 1, 0, 2);
    } else {
      Enemy_EnterState(&p->e, Cockatrice_StateCrumble, ES_UNK_49);
    }
  }
}

// 跳ねながら煙を出し, 48 フレーム目に石のかけらを散らして点滅しながら消え, 倒されたスクリプトを呼んで図鑑に載せる
void Cockatrice_StateCrumble(Cockatrice* p, s32 timer) {
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if (timer > 42) {
    if (Mod(timer, 6) == 0) {
      Entity08015584_SpawnSpray(1, 1, 0, Q6(0.5), &(p->e).mover.pos);
    }
  } else if (timer > 52 && Mod(timer, 4) == 0) {
    Entity08015584_SpawnSpray(1, 1, 0, Q6(0.5), &(p->e).mover.pos);
  }
  if (timer == 48) {
    Cockatrice_SpawnStoneShards(p, 6);
    PlaySound_082406e0(SONG_459);
  }
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
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
    (p->e).sleepTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
  }
}

// 14 番のアニメで跳ぶ前の構えを取り, 流し終えたら跳ねる・跳び上がる・Cockatrice_StateTakeOff のどれかへ移る
void Cockatrice_StatePrepareJump(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 14);
    if (Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
      (p->e).animSpeedDiv = 2;
      Enemy_UpdateWalkAnimSpeed(&p->e);
    }
    q->riseAngle = 0;
  }
  if ((p->e).animForceRestart) {
    if (Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
      Enemy_EnterState(&p->e, Cockatrice_StateHopUp, ES_UNK_45);
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else if (Cockatrice_TestFlags(q, COCKAFLAG_UNK_0)) {
      Enemy_EnterState(&p->e, Cockatrice_StateJumpUp, ES_UNK_41);
      Enemy_ResetState(&p->e, 0, 2, 0);
    } else {
      Enemy_EnterState(&p->e, Cockatrice_StateTakeOff, ES_UNK_34);
      Enemy_ResetState(&p->e, 3, 1, 0);
    }
  }
}

// 17 番のアニメのまま上へ跳ね, 上がりきってアニメが終わったら降りる状態 (Cockatrice_StateDescend) へ移る
void Cockatrice_StateHopUp(Cockatrice* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    (p->e).animSpeedDiv = 2;
  }
  if (anim->cmdIdx == 0 && anim->tick == 0) {
    PlaySound_082406e0(SONG_468);
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (Cockatrice_StepJump(p, &q->jumpVel, 0, 12, timer + 42) && (p->e).animForceRestart) {
    Cockatrice_SetHopVel(p, 1, 0);
    Enemy_EnterState(&p->e, Cockatrice_StateDescend, ES_UNK_36);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
}

// 跳び上がり, 上がりきってアニメが終わったら次に降りる先を決めて Cockatrice_StateJumpDown へ移る
void Cockatrice_StateJumpUp(Cockatrice* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    Cockatrice_StartJump(p);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (anim->cmdIdx == 0 && anim->tick == 0) {
    PlaySound_082406e0(SONG_468);
  }
  if (Cockatrice_StepJump(p, &q->jumpVel, 0, 2, timer + 18)) {
    q->riseHeight = (p->e).heightAboveFloor;
    if ((p->e).animForceRestart) {
      if (Cockatrice_CanSeePlayerAhead(p)) {
        Cockatrice_SetLongJumpTarget(p);
      } else {
        Cockatrice_SetJumpTargetAhead(p);
      }
      Enemy_EnterState(&p->e, Cockatrice_StateJumpDown, ES_UNK_42);
      Enemy_ResetState(&p->e, 3, 0, 0);
      {
        Vec3 d;
        Vec3* dst = &d;
        WorldPos* pos = &(p->e).mover.pos;

        Vec3_Diff(dst, &q->jumpTarget, pos);
        (p->e).mover.angle = ArcTan2_8(d.x, d.z);
      }
    }
  }
}

// 16 番のアニメで飛び上がり, 上がりきったら経路の今のノードへ経路を引いて Cockatrice_StateFly (状態35) へ移る, 引けなければ止まる
void Cockatrice_StateTakeOff(Cockatrice* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Cockatrice* q = (p->e).owner;
  WorldPos d;
  WorldPos* dst;
  PathWalker* walker;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Cockatrice_SetHopVel(p, 0, 0);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (!Cockatrice_StepJump(p, &q->jumpVel, 0, 2, timer + 6)) {
    Enemy_PlayAnim(&p->e, 16);
    if (anim->cmdIdx == 0 && anim->tick == 0) {
      PlaySound_082406e0(SONG_468);
    }
    return;
  }
  q->riseHeight = (p->e).heightAboveFloor;
  Enemy_EnterState(&p->e, Cockatrice_StateFly, ES_UNK_35);
  Enemy_ResetState(&p->e, 0, 0, 15);
  dst = &d;
  walker = &(p->e).pathWalker;
  dst->x = walker->node->x;
  dst->z = walker->node->y;
  dst->y = TileHeightAt(dst);
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
}

void Cockatrice_StateFly(Cockatrice* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_6e6 = 1;
    SET_FLAGS(q->flags, COCKAFLAG_UNK_2);
  } else {
    Enemy_PlayAnim(&p->e, 17);
    if (anim->cmdIdx == 0 && anim->tick == 0) {
      PlaySound_082406e0(SONG_465);
    }
    if (!Cockatrice_TestFlags(q, COCKAFLAG_UNK_2)) {
      Enemy_EnterState(&p->e, Cockatrice_StateDescend, ES_UNK_36);
      Enemy_ResetState(&p->e, 3, 1, 0);
    }
  }
}

// jumpTarget へ 10 フレームで着く速さで向きを4方向に揃えて跳び, 床に着いたら Cockatrice_StateLand へ移る
// 139/139命令, 残差はオフセット定数を作る一時レジスタと jumpVel.y = 0 を書く位置だけ, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateJumpDown(Cockatrice* p, s32 timer) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3_Delta(&q->jumpVel, &(p->e).mover.pos, &q->jumpTarget);
    q->jumpVel.x = Div(q->jumpVel.x, 10);
    q->jumpVel.y = 0;
    q->jumpVel.z = Div(q->jumpVel.z, 10);
    (p->e).mover.angle = (((ArcTan2_8(q->jumpVel.x, q->jumpVel.z) + 0x20) & 0xFF) >> 6) << 6;
    PlaySound_082406e0(SONG_469);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (!Cockatrice_StepJump(p, &q->jumpVel, 1, 4, timer + 18)) {
    Enemy_PlayAnim(&p->e, 17);
  } else {
    q->riseHeight = (p->e).heightAboveFloor;
    Enemy_EnterState(&p->e, Cockatrice_StateLand, ES_UNK_37);
    CLEAR_FLAGS(q->flags, COCKAFLAG_UNK_0);
  }
#else
  INCFUNC("asm/func/Cockatrice_StateJumpDown.inc");
#endif
}

void Cockatrice_StateDescend(Cockatrice* p, s32 timer) {
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Cockatrice_SetHopVel(p, 1, 0);
    q->unk_6cc = Div((p->e).s->aux.spr.pos.y, 40);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (!Cockatrice_StepJump(p, &q->jumpVel, 1, 4, timer + 24)) {
    Enemy_PlayAnim(&p->e, 17);
  } else {
    q->riseHeight = (p->e).heightAboveFloor;
    Enemy_EnterState(&p->e, Cockatrice_StateLand, ES_UNK_37);
  }
}

void Cockatrice_StateDescendPuzzled(Cockatrice* p, s32 timer) {
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Cockatrice_SetHopVel(p, 1, 0);
    q->unk_6cc = Div((p->e).s->aux.spr.pos.y, 40);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (!Cockatrice_StepJump(p, &q->jumpVel, 1, 4, timer + 24)) {
    Enemy_PlayAnim(&p->e, 17);
  } else {
    q->riseHeight = (p->e).heightAboveFloor;
    Enemy_EnterState(&p->e, Cockatrice_StateLand, ES_UNK_37);
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  }
}

// 着地のアニメを流し終えたら, 逃げる印があれば逃げ先へ, 追いかけていなければ攻撃対象か覚えた位置へ経路を引いて歩き, 追いかけていればプレイヤーのタイルへ経路を引き直す
// 1007/1028命令の下書き, 追いかけ中の後半は FUN_0815b8d0 / Boku の FUN_080fe7f4 と同じ形と同じ壁 (原典は状態フィールドのアドレスをスタックに作り置く), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateLand(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 moved;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    Cockatrice_ClearFlags(q, COCKAFLAG_UNK_0 | COCKAFLAG_DODGING);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
      Enemy_EnterState(&p->e, Cockatrice_StateFlee, ES_UNK_52);
      Enemy_ResetState(&p->e, 0, 0, 19);
      Cockatrice_FleeToPathNode(p);
      Cockatrice_ClearFlags(q, COCKAFLAG_AT_FLEE_NODE);
      return;
    }
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_12)) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
        (p->e).pathNodePos->val = 0;
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
        return;
      }
    } else if (Cockatrice_TestFlags(q, COCKAFLAG_UNK_19)) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->lastSeenPos)) {
        (p->e).pathNodePos->val = 0;
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
        (p->e).animSpeedDiv = 3;
        ClearMemory(&q->lastSeenPos, sizeof(WorldPos));
        Cockatrice_ClearFlags(q, COCKAFLAG_UNK_19);
        return;
      }
    }
    Cockatrice_RestAndResumeRoute(p);
    return;
  }
  Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
  Enemy_ResetState(&p->e, 0, 0, 12);
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
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
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
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }
  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
  }
  if (!moved) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Cockatrice_StateLand.inc");
#endif
}

// 161/155命令, 原典は owner を r3 に読んで &owner->flags を持ち越し, 判定は bool の作り置きになる, 試済: 宣言順, anim を後に, flags のポインタのローカル (132命令)
NON_MATCH void Cockatrice_StateFlee(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  (p->e).animSpeedDiv = 4;
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Cockatrice_TryFire(p);
  } else {
    if (Cockatrice_TestFlags(q, COCKAFLAG_AT_FLEE_NODE) && (p->e).playerDistSq < 0x10000) {
      Cockatrice_FleeToPathNode(p);
      CLEAR_FLAGS(q->flags, COCKAFLAG_AT_FLEE_NODE);
      Enemy_ResetState(&p->e, 0, 0, 19);
    }
    if (!Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
      if (!Cockatrice_TestFlags(q, COCKAFLAG_AT_FLEE_NODE)) {
        Enemy_PlayAnim(&p->e, 1);
      } else {
        Enemy_PlayAnim(&p->e, 0);
        Cockatrice_FleeToPathNode(p);
        CLEAR_FLAGS(q->flags, COCKAFLAG_AT_FLEE_NODE);
        Enemy_ResetState(&p->e, 0, 0, 19);
      }
    } else if (Cockatrice_TestFlags(q, COCKAFLAG_UNK_2)) {
      Enemy_PlayAnim(&p->e, 17);
      if (anim->cmdIdx == 0 && anim->tick == 0) {
        PlaySound_082406e0(SONG_465);
      }
    }
    Cockatrice_TryEndFlee(p);
  }
#else
  INCFUNC("asm/func/Cockatrice_StateFlee.inc");
#endif
}

// 弾を作って撃つアニメを流し, 流し終えたら弾を放ち, 宙に浮いていなければ逃げ先・経路の今のノード・プレイヤーのいずれかへ向かう
// 1035/1139命令の粗い下書き, 追いかけ中の後半は FUN_0815b8d0 の形で, 原典はプレイヤーへ向かう部分をもう1回展開しているらしい (状態フィールドのアドレスをスタックに作り置く壁も同じ), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateFire(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 moved;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->shotCount = 1;
    Cockatrice_SpawnShot(p);
    Cockatrice_PlayFireAnim(p);
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  if (q->shotCount > 0) {
    Cockatrice_PlayFireAnim(p);
    q->shotCount--;
    return;
  }
  Entity081e9cacElem_Launch((p->e).unk_264);
  PlaySound_082406e0(SONG_464);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
      if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
        return;
      }
      Enemy_PlayAnim(&p->e, 0);
      Cockatrice_FleeToPathNode(p);
      Cockatrice_ClearFlags(q, COCKAFLAG_AT_FLEE_NODE);
      Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
      (p->e).pendingDelay = 24;
      (p->e).pendingHandler = Cockatrice_StateFlee;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 19;
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else {
      WorldPos d;

      if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
        return;
      }
      Enemy_PlayAnim(&p->e, 0);
      d.x = (p->e).pathWalker.node->x;
      d.z = (p->e).pathWalker.node->y;
      d.y = TileHeightAt(&d);
      d.y = (p->e).mover.pos.y;
      if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d)) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      (p->e).pathNodePos->val = 1;
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
      (p->e).pendingDelay = 24;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
    return;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 0);
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
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
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
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }
  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
  }
  if (!moved) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Cockatrice_StateFire.inc");
#endif
}

// 見回しの向き lookDir へアニメに合わせて 45 度ずつ振り向き, 振り向き終えたら lookCount を減らして残っていれば lookBaseAngle の側へ次の向きを選び直し, 尽きたら退避した状態へ戻る
// 368/366命令, 振り向きの向きで分ける switch は d >= 0 側を先に, 最後の判定は向きが違う枝を先に書くと並びが揃う, 残りは owner (原典 r5) と &anim (原典 r8) の割当と, 入場時に退避した状態へ戻すときの読み順
NON_MATCH void Cockatrice_StateLookTurn(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;
  s32 dir = (p->e).mover.angle >> 5;
  s32 d = (q->lookDir - dir) * 32;

  if (d > 128) {
    d -= 256;
  }
  if (d < -128) {
    d += 256;
  }
  if (Enemy_ConsumeStateBegun(&p->e)) {
    if (dir == q->lookDir) {
      Enemy_EnterState(&p->e, (p->e).savedHandlerState, (p->e).savedState);
      Enemy_ResetState(&p->e, (p->e).savedSubState0, (p->e).savedSubState1, (p->e).savedSubState2);
      return;
    }
    if (d >= 0) {
      switch (dir) {
        case 0: {
          Enemy_PlayAnimNoFacing(&p->e, 22);
          break;
        }
        case 1: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 23, ANIM_PLAY_XFLIP);
          break;
        }
        case 2: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 24, ANIM_PLAY_XFLIP);
          break;
        }
        case 3: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 25, ANIM_PLAY_XFLIP);
          break;
        }
        case 4: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 26, ANIM_PLAY_XFLIP);
          break;
        }
        case 5: {
          Enemy_PlayAnimNoFacing(&p->e, 19);
          break;
        }
        case 6: {
          Enemy_PlayAnimNoFacing(&p->e, 20);
          break;
        }
        case 7: {
          Enemy_PlayAnimNoFacing(&p->e, 21);
          break;
        }
      }
    } else {
      switch (dir) {
        case 0: {
          Enemy_PlayAnimNoFacing(&p->e, 24);
          break;
        }
        case 1: {
          Enemy_PlayAnimNoFacing(&p->e, 23);
          break;
        }
        case 2: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 22, ANIM_PLAY_XFLIP);
          break;
        }
        case 3: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 21, ANIM_PLAY_XFLIP);
          break;
        }
        case 4: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 20, ANIM_PLAY_XFLIP);
          break;
        }
        case 5: {
          Enemy_PlayAnimNoFacingFlags(&p->e, 19, ANIM_PLAY_XFLIP);
          break;
        }
        case 6: {
          Enemy_PlayAnimNoFacing(&p->e, 26);
          break;
        }
        case 7: {
          Enemy_PlayAnimNoFacing(&p->e, 25);
          break;
        }
      }
    }
  }
  if (anim->cmdIdx == 2 && anim->tick == 0) {
    if (d < 0) {
      (p->e).mover.angle -= 32;
    } else {
      (p->e).mover.angle += 32;
    }
  }
  if ((p->e).animForceRestart) {
    if (q->lookDir != (p->e).mover.angle >> 5) {
      Enemy_EnterState(&p->e, Cockatrice_StateLookTurn, ES_UNK_44);
      Enemy_ResetState(&p->e, 3, 1, 0);
    } else {
      if (--q->lookCount <= 0) {
        Enemy_EnterState(&p->e, (p->e).savedHandlerState, (p->e).savedState);
        Enemy_ResetState(&p->e, (p->e).savedSubState0, (p->e).savedSubState1, (p->e).savedSubState2);
      } else {
        u32 angle = (p->e).mover.angle;
        s32 e = (u8)q->lookBaseAngle - angle;

        if (e > 128) {
          e -= 256;
        }
        if (e < -128) {
          e += 256;
        }
        if (e < 0) {
          angle -= 32;
        } else {
          angle += 32;
        }
        q->lookDir = (u8)angle >> 5;
        Enemy_EnterState(&p->e, Cockatrice_StateLookTurn, ES_UNK_44);
        Enemy_ResetState(&p->e, 3, 1, 0);
      }
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_StateLookTurn.inc");
#endif
}

// 見回し, unk_542 の回数だけ乱数の向きへ振り向き, 最後に元の向きへ戻ったら退避しておいた状態に戻る
// 211/198命令, enemy_anim.c の Enemy_080eff14 (既定の見回し, NON_MATCH) と同じ形で待ち時間が短い版, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_StateLookAround(Cockatrice* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).animSpeedDiv = 2;
  }
  if ((s8)(p->e).unk_542 > 0) {
    if (timer > 30) {
      u8 dir;

      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
      if ((p->e).unk_542 == 1) {
        dir = (p->e).lookBaseAngle >> 5;
      } else {
        s32 angle;
        s32 i;

        for (i = 0; i < 4; i++) {
          angle = (Random() & 3) * 64;
          if (angle != (p->e).mover.angle) {
            break;
          }
          angle = (p->e).mover.angle;
        }
        dir = angle >> 5;
      }
      (p->e).unk_1dc = (dir + 3) & 7;
      (p->e).unk_542--;
    }
  } else {
    (p->e).unk_542 = 0xFF;
    if (timer > 15) {
      Enemy_EnterState(&p->e, (p->e).savedHandlerState, (p->e).savedState);
      Enemy_ResetState(&p->e, (p->e).savedSubState0, (p->e).savedSubState1, (p->e).savedSubState2);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_StateLookAround.inc");
#endif
}

s32 Cockatrice_PreUpdate(Cockatrice* p) {
  Cockatrice_UpdateAirState(p);
  Cockatrice_TickTimers(p);
  Cockatrice_UpdateAtkPower(p);
  Cockatrice_TickFleeTimer(p);
  if (p->dodgeCooldown > 0) {
    p->dodgeCooldown--;
  }
  return 1;
}

s32 Cockatrice_PostUpdate(Cockatrice* p) {
  Cockatrice_UpdateHitboxes(p);
  Cockatrice_ReleaseSharedEntity(p);
  Cockatrice_UpdateLookTimer(p);
  Cockatrice_UpdateSenseHitbox(p);
  return 1;
}

// プレイヤーに気付いて向き直り, 感情アイコンとスクリプトを出して追いかけを始める
void Cockatrice_StartChase(Cockatrice* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Cockatrice_StateWaitEmote, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    Cockatrice_ChooseAttack(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// 追跡を見失って 60 フレーム待ったら感情アイコンを出し, 追いかけていなければ経路移動へ, 追いかけていればプレイヤーのタイルへ経路を引き直す予約をする
// 938/932命令の下書き, Boku の FUN_080fe7f4 と同じ本体で残差も同じ (原典は状態フィールドのアドレスをスタックに作り置く, フレーム 0x60, こちらは 0x30), 1回目の下書きで切り上げ
NON_MATCH void FUN_0815758c(Cockatrice* p) {
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
    FUN_080e7b6c(&p->e);
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
  INCFUNC("asm/func/FUN_0815758c.inc");
#endif
}

// 入場時に pathNodePos に経路の今のノードを入れてプレイヤーへの経路を引き, 引ければ攻撃対象として追う印を立て, 引けなければ経路のノードへ戻る
// 379/379命令, 原典は pathNodePos を読んでから &pathWalker を r2 に作り, 経路を引き直す枝に入る前に r9 へ写す (こちらは &pathWalker を最初から r9 に置く), 試済: walker と target の宣言順・代入順 (逆順は 380), 引き直しの枝で walker を使わない (377) / 取り直す (381)
NON_MATCH void FUN_08157df4(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3* target;
    PathWalker* walker;

    Enemy_PlayAnim(&p->e, 0);
    walker = &(p->e).pathWalker;
    target = (p->e).pathNodePos;
    target->x = walker->node->x;
    target->z = walker->node->y;
    target->y = TileHeightAt(target);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
      WorldPos d;
      WorldPos* dst = &d;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, dst);
      if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
        Enemy_PlayAnim(&p->e, 17);
        Enemy_EnterState(&p->e, Cockatrice_StateFly, ES_UNK_35);
        Enemy_ResetState(&p->e, 0, 0, 15);
        return;
      }
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 2);
      return;
    }
    Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
    Cockatrice_PauseBeforeMove(p);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_12);
    (p->e).pathNodePos->val = 0;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/FUN_08157df4.inc");
#endif
}

void Cockatrice_SetHandlerTable3(Cockatrice* p) { (p->e).handlerTables[3] = (void*)sCockatriceHandlerTable3; }

void Cockatrice_SubMoveToGoal(Cockatrice* p) {
  s32 speed;

  Enemy_ConsumeSubStateBegun(&p->e);
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
    if ((p->e).pathNodePos->val != 0) {
      Enemy_ResetState(&p->e, 0, 0, 15);
      Enemy_StepTowardPathNode(&p->e);
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_7);
      (p->e).animSpeedDiv = 1;
      ClearMemory((p->e).pathNodePos, sizeof(Vec3));
    } else {
      Enemy_ResetState(&p->e, 0, 0, 18);
      (p->e).animSpeedDiv = 1;
    }
  } else {
    (p->e).subStateTimer++;
  }
}

// 追いかけをやめて感情アイコンを出し, 60 フレーム待っても気付かなければ経路ノードへの経路を引いて走って戻る
void Cockatrice_SubGiveUpChase(Cockatrice* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    (p->e).animSpeedDiv = 1;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer > 60) {
    Enemy_ResetState(&p->e, 0, 0, 17);
    Enemy_EnterState(&p->e, Cockatrice_StateFly, ES_UNK_35);
    (p->e).pathNodePos->val = 1;
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
      (p->e).onRouteFailed(&p->e);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

void Cockatrice_SubMoveToPathNode(Cockatrice* p) {
  s32 speed;

  Enemy_ConsumeSubStateBegun(&p->e);
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 16);
  } else {
    (p->e).subStateTimer++;
  }
}

// 経路ノードの待ちを数え, 待ち終えたら unk_194 のスクリプトを流して次のノードへ進め, コマンドに応じて副状態 15 か 16 を選ぶ
// 181/192命令, enedefault.c の FUN_080f2644 (経路ノードの待ち) と同じ形, 原典はノードのコマンドを判定した結果と経路のアドレスを高位レジスタに持つ, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_SubPathNodeWait(Cockatrice* p) {
#ifdef NONMATCHING_C
  u32 cmd;

  Enemy_ConsumeSubStateBegun(&p->e);
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  cmd = (p->e).mover.path->node->command >> 4;
  if (cmd != 0 && cmd != 2 && cmd != 4) {
    Map_AdvancePathWalker((p->e).mover.path);
    if ((p->e).mover.path->node->command >> 4 == 1) {
      return;
    }
  }
  if ((p->e).mover.path->waitTimer++ < ((p->e).mover.path->node->delay & 0xFFF)) {
    (p->e).subStateTimer++;
    return;
  }
  if ((p->e).unk_194 != 0) {
    u32 argv[3];
    ScriptArgs sa;

    argv[0] = (p->e).pathWalker.nodeIdx;
    argv[1] = (p->e).mover.id;
    argv[2] = (p->e).kind;
    sa.argc = 3;
    sa.argv = argv;
    VM_ExecByID((p->e).unk_194, &sa);
  }
  Map_AdvancePathWalker((p->e).mover.path);
  Enemy_StepTowardPathNode(&p->e);
  cmd = (p->e).mover.path->node->command >> 4;
  if (cmd == 4) {
    (p->e).animSpeedDiv = 2;
  } else {
    (p->e).animSpeedDiv = 1;
    if (cmd == 0) {
      if (Map_IsPosOutsidePathNode((p->e).mover.path, &(p->e).mover.pos, 32, 32)) {
        Enemy_ResetState(&p->e, 0, 0, 15);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 16);
      }
      return;
    }
  }
  Enemy_ResetState(&p->e, 0, 0, 15);
#else
  INCFUNC("asm/func/Cockatrice_SubPathNodeWait.inc");
#endif
}

// 168/168命令, 残差は owner (原典 r6) と速さ (原典 r8) の割当だけ, 試済: 宣言順, 宙に浮いているかを TEST_FLAGS で直接 (162命令)
NON_MATCH void Cockatrice_SubFleeMove(Cockatrice* p) {
#ifdef NONMATCHING_C
  s32 speed;
  Cockatrice* q = (p->e).owner;

  Enemy_ConsumeSubStateBegun(&p->e);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE) && Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 20);
    }
  } else if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    SET_FLAGS(q->flags, COCKAFLAG_AT_FLEE_NODE);
    return;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Cockatrice_SubFleeMove.inc");
#endif
}

void Cockatrice_SubFleeTurn(Cockatrice* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 19);
    Enemy_EnterState(&p->e, Cockatrice_StateFlee, ES_UNK_52);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_081589f0(Cockatrice* p) { Enemy_ConsumeSubStateBegun(&p->e); }

void FUN_08158a08(Cockatrice* p) { Enemy_ConsumeSubStateBegun(&p->e); }

// 経路の目標へ歩かせ, 向きが変わるときは unk_222 の印に応じて, 今の状態を退避してから乱数の新しい向きで状態27へ移る
// 342/365命令, enedefault.c の FUN_080f0e78 と同じ壁 (原典は退避と状態27への切り替えの格納先アドレスをスタックに作り置き sub sp, #0x44), 試済: 退避をループの中に入れる while(TRUE) の形 (337)
NON_MATCH void Cockatrice_SubChaseMove(Cockatrice* p) {
#ifdef NONMATCHING_C
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 14);
      return;
    }
  } else if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
    if (!TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      if (FUN_0815d6d0(p)) {
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
  INCFUNC("asm/func/Cockatrice_SubChaseMove.inc");
#endif
}

void Cockatrice_SubChaseTurn(Cockatrice* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateDone) {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
  } else {
    (p->e).subStateTimer++;
  }
}

// 状態0の待機, 60 を超えたら追跡を予約してプレイヤーのタイルへ経路を引き直し, 同じタイルにいるか見えないときは歩きか追跡に戻して向きを乱数で変える見回しを予約する
// 781/779命令の下書き, enedefault.c の FUN_080f12c4 と同じ形と同じ壁 (原典は状態フィールドのアドレスをスタックに作り置く), 違いは入場時の後始末と予約の待ちが 30 で固定な点, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_SubChaseReroute(Cockatrice* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    (p->e).animSpeedDiv = 1;
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

  (p->e).unk_222 &= ~(ENEMY222_UNK_1 | ENEMY222_UNK_2);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
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

  if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
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

  {
    u8 angle = (p->e).mover.angle;

    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i <= 3; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i > 3) {
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
  }
  FUN_080e7b6c(&p->e);
  (p->e).animSpeedDiv = 2;
#else
  INCFUNC("asm/func/Cockatrice_SubChaseReroute.inc");
#endif
}

// 状態0の待機, 攻撃対象が近ければ状態25へ, 30 で感情アイコンを出し, 60 を超えたら経路の今のノードへ向かって状態1へ移す
// 308/311命令, enedefault.c の FUN_080f2ec0 と同じ流れ (攻撃対象の距離は playerDistSq), flags3 を Enemy_GetFlag3 / Enemy_ClearFlag3 で書くと原典どおり &flags3 を r8 に持つ, 残りは 30 のときの unk_5f0 呼び出しが後ろの onRouteFailed 呼び出しと末尾を共有してしまう点, 試済: 60 以下の枝を先に (307), 経路の成否を if/else に (307)
NON_MATCH void Cockatrice_SubWaitThenReturn(Cockatrice* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
    (p->e).animSpeedDiv = 1;
    Cockatrice_ClearFlags((p->e).owner, COCKAFLAG_UNK_19);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_12) && (p->e).playerDistSq < 0xFFFF) {
    Enemy_EnterState(&p->e, (p->e).unk_5e8, ES_ATTACK);
    Enemy_ResetState(&p->e, 3, 1, 0);
    return;
  }
  if ((p->e).subStateTimer == 30) {
    Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
    if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_12)) {
      (p->e).unk_5f0(&p->e);
      return;
    }
  }
  if ((p->e).subStateTimer > 60) {
    Enemy_ResetState(&p->e, 0, 0, 7);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).pathNodePos->val = 1;
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    return;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Cockatrice_SubWaitThenReturn.inc");
#endif
}

void Cockatrice_SetHandlerTable2(Cockatrice* p) { (p->e).handlerTables[2] = (void*)sCockatriceHandlerTable2; }

void Cockatrice_SetHandlerTable4(Cockatrice* p) { (p->e).handlerTables[4] = (void*)sCockatriceHandlerTable4; }

void Cockatrice_InitAnims(Cockatrice* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 2, 0);
  Enemy_SetAnimEntry(&p->e, 2, 1, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 5, 20, 0);
  Enemy_SetAnimEntry(&p->e, 6, 5, 0);
  Enemy_SetAnimEntry(&p->e, 7, 6, 0);
  Enemy_SetAnimEntry(&p->e, 8, 5, 0);
  Enemy_SetAnimEntry(&p->e, 9, 6, 0);
  Enemy_SetAnimEntry(&p->e, 10, 7, 0);
  Enemy_SetAnimEntry(&p->e, 14, 10, 0);
  Enemy_SetAnimEntry(&p->e, 15, 11, 0);
  Enemy_SetAnimEntry(&p->e, 16, 9, 0);
  Enemy_SetAnimEntry(&p->e, 17, 8, 0);
  Enemy_SetAnimEntry(&p->e, 4, 0, 0);
  Enemy_SetAnimEntry(&p->e, 18, 4, 0);
  Enemy_SetAnimEntry(&p->e, 19, 13, 0);
  Enemy_SetAnimEntry(&p->e, 20, 14, 0);
  Enemy_SetAnimEntry(&p->e, 21, 17, 0);
  Enemy_SetAnimEntry(&p->e, 22, 18, 0);
  Enemy_SetAnimEntry(&p->e, 23, 19, 0);
  Enemy_SetAnimEntry(&p->e, 24, 16, 0);
  Enemy_SetAnimEntry(&p->e, 25, 15, 0);
  Enemy_SetAnimEntry(&p->e, 26, 12, 0);
}

void Cockatrice_InitHitboxes(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;
  Vec3 size, offset, hurtSize, hurtOffset, hitSize, hitOffset;
  HitboxFlags32 flags;

  VEC3_SET(size, 128, 128, 128);
  VEC3_SET(offset, 0, 128, 0);
  flags = HBFLAG_HURTBOX | HBFLAG_ANGLE | HBFLAG_UNK_3 | HBFLAG_UNK_1 | HBFLAG_UNK_0;
  Enemy_RegisterHitbox(&p->e, &q->senseHitbox, &size, &offset, Cockatrice_OnSenseAttack, p, flags);
  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Cockatrice_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Cockatrice_OnHit, 0, p);
}

// 宙に浮いていたり怯んでいる間は感知の判定を隠し, そうでなければ向いた方の 128 先に向きに応じた横長の判定を置く
// 167/167命令, 残差は隠す枝と出す枝で &senseHitbox を作る位置だけ (原典は分岐の前に作って両方で使う), 試済: halfSize をローカルから直接代入 (159命令), if/else の形
NON_MATCH void Cockatrice_UpdateSenseHitbox(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  Vec3 pos, size;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE | COCKAFLAG_FLEEING) || TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    Hitbox_SetFlags(&q->senseHitbox, HBFLAG_HIDDEN);
    return;
  }
  Hitbox_ClearFlags(&q->senseHitbox, HBFLAG_HIDDEN);
  pos = (p->e).mover.pos;
  pos.x += POLAR_X(128, (p->e).mover.angle);
  pos.z += POLAR_Z(128, (p->e).mover.angle);
  switch ((((p->e).mover.angle + 0x10) & 0xFF) >> 6) {
    case 0:
    case 2: {
      size.x = 160;
      size.z = 64;
      break;
    }
    case 1:
    case 3: {
      size.x = 64;
      size.z = 160;
      break;
    }
  }
  size.y = 100;
  Hitbox_SetHalfSize(&q->senseHitbox, &size);
  Hitbox_SetPos(&q->senseHitbox, &pos, 0);
#else
  INCFUNC("asm/func/Cockatrice_UpdateSenseHitbox.inc");
#endif
}

// 前から来た攻撃をかわす, 撃ちかけの弾を消して跳び上がり, 追いかけていなければ追いかけの印を消して攻撃元へ向き直る
void Cockatrice_StartDodge(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
  Cockatrice_SetHopVel(p, 0, 0);
  q->jumpVel.y = 58;
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    Cockatrice_StartFlee(p);
  }
  q->dodgeCooldown = 120;
  SET_FLAGS(q->flags, COCKAFLAG_DODGING);
  Enemy_EnterState(&p->e, Cockatrice_StatePrepareJump, ES_UNK_33);
  Enemy_ResetState(&p->e, 3, 0, 0);
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_SetEmote(&p->e, 0, 0x7F, 0);
  Enemy_SetEmote(&p->e, 1, 0x7F, 0);
  Enemy_SetEmote(&p->e, 3, 0x7F, 0);
  Enemy_FadeParticles(&p->e, 4);
  Enemy_ClearFlags4(&p->e, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
}

// 向いている方向へまっすぐタイルをたどり, 自分の床より高いタイルに遮られずにプレイヤーのタイルへ届くか調べる
// 残差は height と target の r8/r9 入れ替わりと, case 1 の cur < size の cmp 向き (size > cur と書くと向きは揃う), target の型・宣言順・比較の向きは効かない
NON_MATCH bool8 Cockatrice_CanSeePlayerAhead(Cockatrice* p) {
#ifdef NONMATCHING_C
  s32 start = (p->e).tileIdx;
  u32 height = (p->e).floorY >> 8;
  s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
  s32 target = GetCollisionTileIdx(&gPlayerPtr[0]->mover.pos);
  s32 cur;
  s32 x;

  switch ((p->e).mover.angle >> 6) {
    case 0: {
      cur = start + 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width; x++) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return FALSE;
        }
        if (cur == target) {
          return TRUE;
        }
        cur++;
      }
      break;
    }
    case 1: {
      for (cur = start + gCollisionMap->tiledata->width; cur < size; cur += gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return FALSE;
        }
        if (cur == target) {
          return TRUE;
        }
      }
      break;
    }
    case 2: {
      cur = start - 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0; x--) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return FALSE;
        }
        if (cur == target) {
          return TRUE;
        }
        cur--;
      }
      break;
    }
    case 3: {
      for (cur = start - gCollisionMap->tiledata->width; cur >= 0; cur -= gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return FALSE;
        }
        if (cur == target) {
          return TRUE;
        }
      }
      break;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Cockatrice_CanSeePlayerAhead.inc");
#endif
}

// 跳んでいる1フレームぶん, vel の横の速さで動かして t に応じて高さを変える, mode 0 は上がりきったら, mode 1 は床に着いたら TRUE
// 141/141命令, 残差は mode 0 の (height + 1) + rise の足す順 (原典は height + 1 を先に作る) だけ, 試済: 足し算の書き順2通り, pos のローカルと式渡し
NON_MATCH bool8 Cockatrice_StepJump(Cockatrice* p, Vec3* vel, s32 mode, s32 gravity, s32 t) {
#ifdef NONMATCHING_C
  WorldPos* pos = &(p->e).mover.pos;
  Vec3* delta = &(p->e).mover.delta;
  s32 floor = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);
  s32 height = (p->e).heightAboveFloor;
  s32 rise;
  s32 y;

  delta->x = vel->x;
  delta->z = vel->z;
  vel->y -= gravity;
  rise = (t * t) >> 4;
  switch (mode) {
    case 0: {
      height = (height + 1) + rise;
      break;
    }
    case 1: {
      height -= abs(64 - rise);
      break;
    }
    case 2: {
      height += rise;
      break;
    }
  }
  y = height + floor;
  switch (mode) {
    case 0: {
      if (vel->y <= 0) {
        vel->y = 0;
        delta->x = 0;
        delta->z = 0;
        pos->y = (p->e).heightAboveFloor + (p->e).floorY;
        return TRUE;
      }
      break;
    }
    case 1: {
      if (y <= floor) {
        pos->y = floor;
        (p->e).heightAboveFloor = 0;
        return TRUE;
      }
      break;
    }
  }
  (p->e).heightAboveFloor = height;
  pos->y = y;
  return FALSE;
#else
  INCFUNC("asm/func/Cockatrice_StepJump.inc");
#endif
}

// 床より上にいる間は加速しながら落ち, 床に着いたら落下を止める (宙に浮いていれば着いた所を unk_20c に)
void Cockatrice_StepFall(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;
  s32 y = (p->e).floorY + (p->e).heightAboveFloor;
  WorldPos* pos = &(p->e).mover.pos;

  if (TileHeightAtIndex(GetCollisionTileIdx(pos), pos) < y) {
    (p->e).heightAboveFloor -= q->fallFrames * 2;
    (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
    (p->e).s->aux.spr.pos.y = (p->e).mover.pos.y;
    q->fallFrames++;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  } else {
    if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
      (p->e).heightAboveFloor = 0;
      (p->e).unk_20c = (p->e).mover.pos;
    }
    q->fallFrames = 0;
  }
}

// heightAboveFloor が riseHeight を超えるまで sin の山に沿って上がる
s32 Cockatrice_StepRise(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (q->riseHeight < (p->e).heightAboveFloor) {
    q->riseAngle = 0;
  } else {
    s32 dy = POLAR_Z(12, q->riseAngle);

    q->riseAngle += 12;
    (p->e).heightAboveFloor += dy;
  }
  return 0;
}

// 向いている隣のタイルへ 20 フレームで届く jumpVel を作る, 隣が自分の床と違う高さなら水平は 0 にして FALSE, noRise でなければ上向きに 40
// 293/293命令, 残差は tileIdx (原典 r5) と floorY (原典 r6) の割当の入れ替わりだけ, 試済: idx の型 s32 / u16, dir と idx の宣言順, 行き先を別ローカルに (301命令), 比較の左右 (299命令)
NON_MATCH s32 Cockatrice_SetHopVel(Cockatrice* p, s32 noRise, s32 unused) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 dir = ((p->e).mover.angle + 0x20) >> 6;
  u32 idx = (p->e).tileIdx;
  u8 blocked[4];
  WorldPos dst;

  ClearMemory(blocked, sizeof(blocked));
  if ((p->e).floorY != (TileAtIndex(idx + 1)->heightStairs & 0xF) << 8) {
    blocked[0] = TRUE;
  }
  if ((p->e).floorY != (TileAtIndex(idx + gCollisionMap->tiledata->width)->heightStairs & 0xF) << 8) {
    blocked[1] = TRUE;
  }
  if ((p->e).floorY != (TileAtIndex(idx - 1)->heightStairs & 0xF) << 8) {
    blocked[2] = TRUE;
  }
  if ((p->e).floorY != (TileAtIndex(idx - gCollisionMap->tiledata->width)->heightStairs & 0xF) << 8) {
    blocked[3] = TRUE;
  }
  if (blocked[dir] == TRUE) {
    q->jumpVel.x = 0;
    q->jumpVel.z = 0;
    if (!noRise) {
      q->jumpVel.y = 40;
    } else {
      q->jumpVel.y = 0;
    }
    return FALSE;
  }
  switch (dir) {
    case 0: {
      idx++;
      break;
    }
    case 1: {
      idx += gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      idx--;
      break;
    }
    case 3: {
      idx -= gCollisionMap->tiledata->width;
      break;
    }
  }
  TilePosAtIndex(&dst, idx);
  q->jumpVel.x = dst.x - (p->e).mover.pos.x;
  q->jumpVel.y = dst.y - (p->e).mover.pos.y;
  q->jumpVel.z = dst.z - (p->e).mover.pos.z;
  q->jumpVel.x = Div(q->jumpVel.x, 20);
  q->jumpVel.z = Div(q->jumpVel.z, 20);
  if (!noRise) {
    q->jumpVel.y = 40;
    (p->e).heightAboveFloor = 0;
  } else {
    q->jumpVel.y = 0;
  }
  return TRUE;
#else
  INCFUNC("asm/func/Cockatrice_SetHopVel.inc");
#endif
}

s32 Cockatrice_StartJump(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  Vec3_Delta(&q->jumpVel, &(p->e).mover.pos, &q->jumpTarget);
  q->jumpVel.x = Div(q->jumpVel.x, 18);
  q->jumpVel.z = Div(q->jumpVel.z, 18);
  q->jumpVel.y = 20;
  (p->e).heightAboveFloor = 0;
  return TRUE;
}

// 8方向に丸めた向きへ shotSpeed で飛ぶ弾を頭の高さに作り, 2番の攻撃の組を載せて unk_264 に持つ
void Cockatrice_SpawnShot(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;
  s32 dir = (((p->e).mover.angle + 0x10) & 0xFF) >> 5;
  Vec3 vel, offset;

  Vec3_SetPolar(&vel, dir * 32, q->shotSpeed);
  VEC3_SET(offset, 0, 180, -8);
  (p->e).unk_264 = Entity081e9cac_Spawn(&(p->e).mover.pos, &offset, &vel, dir << 5, (p->e).mover.id, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkIframes[2], q->shotLifetime);
}

// 攻撃の選び方, 床にいてプレイヤーが正面になければ追跡へ, 遠ければ撃ち, 近ければ後ろへ跳び退く, 宙に浮いていれば後ろの床へ降りながらプレイヤーへ向く
// 1160/1273命令の粗い下書き, 後ろへ2タイルまで跳ぶ先を探す部分は Cockatrice_SetLongJumpTarget の向きを逆にした形を2か所に書いたもの, 原典は状態フィールドのアドレスをスタックに作り置き (フレーム 0x5C) 跳び先のタイル位置の計算も枝ごとに複製している, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_ChooseAttack(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (!Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    s32 d = (FixToInt(6, (p->e).playerAngle + 0x20) - FixToInt(6, (p->e).mover.angle + 0x20)) * 64;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) > 23) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      (p->e).animSpeedDiv = 2;
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
        (p->e).onRouteFailed(&p->e);
      }
      return;
    }
    if ((p->e).playerDistSq >= q->fireRangeSq) {
      if (q->fireCooldown > 0) {
        return;
      }
      q->fireCooldown = q->fireInterval;
      (p->e).mover.angle = FixToInt(6, (p->e).playerAngle + 0x20) << 6;
      Enemy_EnterState(&p->e, Cockatrice_StateFire, ES_UNK_48);
      Enemy_ResetState(&p->e, 0, 2, 1);
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      return;
    }
    if (q->backstepCooldown > 0) {
      return;
    }
    q->backstepCooldown = q->backstepInterval;
    {
      u32 tileIdx = (p->e).tileIdx;
      s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
      s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
      u32 target;
      s32 idx;
      s32 n;

      switch (FixToInt(6, (p->e).mover.angle + 0x20) & 3) {
        case 0: {
          idx = tileIdx - 1;
          for (n = 0; n < 2; n++) {
            if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx--;
          }
          target = idx + 1;
          break;
        }
        case 1: {
          idx = tileIdx - gCollisionMap->tiledata->width;
          for (n = 0; n < 2; n++) {
            if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx -= gCollisionMap->tiledata->width;
          }
          target = idx + gCollisionMap->tiledata->width;
          break;
        }
        case 2: {
          idx = tileIdx + 1;
          for (n = 0; n < 2; n++) {
            if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx++;
          }
          target = idx - 1;
          break;
        }
        case 3: {
          idx = tileIdx + gCollisionMap->tiledata->width;
          for (n = 0; n < 2; n++) {
            if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
              break;
            }
            idx += gCollisionMap->tiledata->width;
          }
          target = idx - gCollisionMap->tiledata->width;
          break;
        }
        default: {
          target = (p->e).tileIdx;
          break;
        }
      }
      TilePosAtIndex(&q->jumpTarget, target);
    }
    Enemy_EnterState(&p->e, Cockatrice_StatePrepareJump, ES_UNK_33);
    Enemy_ResetState(&p->e, 3, 0, 0);
    Cockatrice_SetFlags(q, COCKAFLAG_UNK_0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    return;
  }
  {
    u32 tileIdx = (p->e).tileIdx;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    u32 target;
    s32 idx;
    s32 n;

    switch (FixToInt(6, (p->e).mover.angle + 0x20) & 3) {
      case 0: {
        idx = tileIdx - 1;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 1: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx + 1;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 3: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    TilePosAtIndex(&q->jumpTarget, target);
  }
  Enemy_EnterState(&p->e, Cockatrice_StateJumpDown, ES_UNK_42);
  Enemy_ResetState(&p->e, 3, 0, 0);
  {
    Vec3 d;
    Vec3* dst = &d;
    WorldPos* pos = &(p->e).mover.pos;

    Vec3_Diff(dst, &gPlayerPtr[0]->mover.pos, pos);
    (p->e).mover.angle = ArcTan2_8(d.x, d.z);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
#else
  INCFUNC("asm/func/Cockatrice_ChooseAttack.inc");
#endif
}

// 宙に浮いておらず撃てる間, 8方向のうち斜めでない向きなら共有エンティティの弾を飛ばす
void Cockatrice_TryFire(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (!Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE) && q->fireCooldown <= 0) {
    s32 dir = (((p->e).mover.angle + 0x10) & 0xFF) >> 5;

    if (dir == 0 || dir == 2 || dir == 4 || dir == 6) {
      q->fireCooldown = 20;
      Cockatrice_SpawnShot(p);
      Entity081e9cacElem_Launch((p->e).unk_264);
      PlaySound_082406e0(SONG_464);
    }
  }
}

// pos へ向かう4方向のまっすぐな列に自分の床より高いタイルがあるか, pos がその列上にないなら TRUE を返す
// 残差は gCollisionMap のアドレスを r7 に持ち target を r9 に置く割当 (こちらは target が r7 でアドレスをスタックに退避, 1 命令多い) と case 1 の cmp 向き, 宣言順・型・tiledata ローカルは効かない
NON_MATCH s32 Cockatrice_IsLineBlocked(Cockatrice* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 d;
  Vec3* dst = &d;
  WorldPos* myPos = &(p->e).mover.pos;
  s32 dir;
  s32 start;
  u32 height;
  s32 target;
  s32 size;
  s32 cur;
  s32 x;

  Vec3_Diff(dst, pos, myPos);
  dir = ((ArcTan2_8(d.x, d.z) + 0x20) >> 6) & 3;
  start = (p->e).tileIdx;
  height = (p->e).floorY >> 8;
  target = GetCollisionTileIdx(pos);
  TileAtIndex(target);
  size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
  switch (dir) {
    case 0: {
      cur = start + 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width; x++) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return TRUE;
        }
        if (cur == target) {
          return FALSE;
        }
        cur++;
      }
      break;
    }
    case 1: {
      for (cur = start + gCollisionMap->tiledata->width; cur < size; cur += gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return TRUE;
        }
        if (cur == target) {
          return FALSE;
        }
      }
      break;
    }
    case 2: {
      cur = start - 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0; x--) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return TRUE;
        }
        if (cur == target) {
          return FALSE;
        }
        cur--;
      }
      break;
    }
    case 3: {
      for (cur = start - gCollisionMap->tiledata->width; cur >= 0; cur -= gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) > height) {
          return TRUE;
        }
        if (cur == target) {
          return FALSE;
        }
      }
      break;
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/Cockatrice_IsLineBlocked.inc");
#endif
}

void Cockatrice_PickRandomPathNode(Cockatrice* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// fleePathIdx の経路のノードから, 256 より離れていてプレイヤーと反対側にある最初のものを選び (なければ乱数で前と違うもの), そこへ経路を引く
// 367/364命令, 原典は dir と d を Vec3 のスタック変数に置き (DImode のまま x / z を読み書き), &d をスタックに退避して絶対値の判定で読み直す, 見つけた番号は u8 で r8 に持って乱数側と合流する, 試済: dir / d を s16 のローカルに (347), 合流させず両方の枝で書く (360)
NON_MATCH void Cockatrice_FleeToPathNode(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  PathWalker walker;
  PathNode* node;
  Vec3 dir;
  Vec3 d;
  u8 angle;
  u8 idx;
  s32 i;
  bool8 found;

  Map_InitPathWalker(&walker, q->fleePathIdx, 0, 0);
  found = FALSE;
  idx = 0;
  angle = ArcTan2_8((p->e).playerMover->pos.x - (p->e).mover.pos.x, (p->e).playerMover->pos.z - (p->e).mover.pos.z);
  dir.x = POLAR_X(160, angle);
  dir.z = POLAR_Z(160, angle);
  node = Map_GetPathNodes(walker.path);
  for (i = 0; i < walker.path->nodeCount; i++) {
    if (q->fleeNodeIdx != i) {
      d.x = node->x - (p->e).mover.pos.x;
      d.z = node->y - (p->e).mover.pos.z;
      if (abs(d.x) > 256 || abs(d.z) > 256) {
        if (dir.x * d.x + dir.z * d.z < 0) {
          idx = i;
          found = TRUE;
          break;
        }
        node++;
      }
    }
  }
  if (!found) {
    idx = Mod(Random(), walker.path->nodeCount);
    if (idx == q->fleeNodeIdx) {
      idx = Mod(idx + 1, walker.path->nodeCount);
    }
  }
  q->fleeNodeIdx = idx;
  walker.nodeIdx = idx;
  walker.waitTimer = 0;
  walker.node = Map_GetPathNodes(walker.path) + walker.nodeIdx;
  {
    Vec3* target = (p->e).pathNodePos;

    target->x = walker.node->x;
    target->z = walker.node->y;
    target->y = TileHeightAt(target);
  }
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).pathNodePos->val = 1;
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
#else
  INCFUNC("asm/func/Cockatrice_FleeToPathNode.inc");
#endif
}

// 経路の今のノードを入れてからプレイヤーのタイルへ経路を引き直す, 同じタイルにいるか見えないときは歩きか追跡に戻して向きを乱数で変える見回しを予約する
// 700/722命令の下書き, enedefault.c の FUN_080f12c4 と Boku の FUN_080fe7f4 の後半と同じ形と同じ壁 (原典は状態フィールドのアドレスをスタックに作り置く, フレーム 0x7C, こちらは 0x3C), 1回目の下書きで切り上げ
NON_MATCH void FUN_0815b8d0(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 moved;

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
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
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
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }
  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
  }
  if (!moved) {
    (p->e).onRouteFailed(&p->e);
    return;
  }
  Cockatrice_ClearFlags(q, COCKAFLAG_AT_FLEE_NODE);
  Enemy_ResetState(&p->e, 0, 0, 19);
#else
  INCFUNC("asm/func/FUN_0815b8d0.inc");
#endif
}

// from を to へ寄せる, x の差が範囲内なら先に x を合わせ, 両方の差が範囲内なら着いたとして TRUE, そうでなければ4方向に丸めた向きへ speed で進む
// 120/120命令, 残差は丸めた向きと x の速さの r3/r4 入れ替えだけ, 試済: 向きを u8 / u32, 宣言の順, 速さを先にローカルへ
NON_MATCH s32 Cockatrice_StepToward(Vec3* from, Vec3* to, u8* dir, u32 rangeX, u32 rangeZ, s32 speed) {
#ifdef NONMATCHING_C
  s32 dx = to->x - from->x;
  s32 dz;

  if (dx != 0 && abs(dx) > rangeX) {
    dz = 0;
  } else {
    if (dx != 0) {
      from->x += dx;
    }
    dz = to->z - from->z;
  }
  if (abs(dx) <= rangeX && abs(dz) <= rangeZ) {
    from->x += dx;
    from->z += dz;
    return 1;
  }
  if (dx != 0 || dz != 0) {
    s32 vx, vz;
    u32 angle;

    angle = ((((u8)ArcTan2_8(dx, dz) + 0x20) & 0xFF) >> 6) << 6;
    *dir = angle;
    vx = FixToInt(16, speed * COS(angle));
    vz = FixToInt(16, speed * SIN(angle));
    vx = abs(vx) > 2 ? vx : 0;
    vz = abs(vz) > 2 ? vz : 0;
    from->x += vx;
    from->z += vz;
  }
  return 0;
#else
  INCFUNC("asm/func/Cockatrice_StepToward.inc");
#endif
}

void Cockatrice_StartFlee(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

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
  SET_FLAGS(q->flags, COCKAFLAG_FLEEING);
  CLEAR_FLAGS(q->flags, COCKAFLAG_UNK_0 | COCKAFLAG_DODGING | COCKAFLAG_UNK_19);
  q->fleeTimer = q->fleeDuration;
  (p->e).mover.angle = (p->e).angle;
  Cockatrice_FleeToPathNode(p);
  CLEAR_FLAGS(q->flags, COCKAFLAG_AT_FLEE_NODE);
}

// 向きを 8 方向に丸め, 方向ごとに variant (0〜5) と左右反転を決めて animTable[5] のアニメを流す, 斜めは Enemy_SetAnimFacing の variant で 2 か 3 を選ぶ
// 121/345命令の形だけの下書き, 原典は向きごとに Enemy_PlayAnim と同じ展開 (アニメ 5) を書き, 枝ごとの AuxAnim_SetAnim と MainSprite 側の後半だけが合流する, (p, variant, flags) を受ける展開の inline を case ごとに呼ぶと 375 命令, case 2 の variant != 0 を case 3/4 へ落とすと 322 命令 (原典はその中間で, AuxSprite 側は複製のまま MainSprite 側だけ合流)
NON_MATCH void Cockatrice_PlayFireAnim(Cockatrice* p) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  u32 dir = (((((p->e).mover.angle + 0x10) & 0xFF) >> 5) + 3) & 7;
  u32 v;
  u32 f;
  u32 anim;

  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  switch (dir) {
    case 0:
    case 1: {
      v = dir;
      f = 0;
      break;
    }
    case 2: {
      v = (variant == 0) ? dir : dir + 1;
      f = 0;
      break;
    }
    case 3:
    case 4: {
      v = dir + 1;
      f = 0;
      break;
    }
    case 5: {
      v = 4;
      f = ANIM_PLAY_XFLIP;
      break;
    }
    case 6: {
      v = (variant == 0) ? 2 : 3;
      f = ANIM_PLAY_XFLIP;
      break;
    }
    case 7: {
      v = 1;
      f = ANIM_PLAY_XFLIP;
      break;
    }
    default: {
      return;
    }
  }
  anim = (p->e).animTable[5].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, v, f);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    u32 a = anim + v;

    if ((p->e).playingAnim == a && !(p->e).animForceRestart && ((f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (f == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = a;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
#else
  INCFUNC("asm/func/Cockatrice_PlayFireAnim.inc");
#endif
}

// 宙に浮いていれば 30 フレーム後に降りる状態へ, 床にいれば 30 フレーム後に経路移動へ戻るよう予約して止まる
// 150/159命令, 原典は状態フィールドのアドレスを高位レジスタに持ち越して両方の枝で使う, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_PauseBeforeMove(Cockatrice* p) {
#ifdef NONMATCHING_C
  bool8 airborne = Cockatrice_TestFlags((p->e).owner, COCKAFLAG_AIRBORNE);

  if (airborne) {
    Enemy_PlayAnim(&p->e, 17);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, FUN_080e6834, ES_UNK_14);
    Cockatrice_SetHopVel(p, 1, 0);
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = Cockatrice_StateDescend;
    (p->e).pendingSubState0 = 3;
    (p->e).pendingSubState1 = 1;
    (p->e).pendingSubState2 = 0;
  } else {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  }
#else
  INCFUNC("asm/func/Cockatrice_PauseBeforeMove.inc");
#endif
}

// 攻撃対象を手放し, 追いかけ中なら追跡へ, そうでなければ 60 フレーム待ってから経路移動か Cockatrice_StateFly へ戻るよう予約し, 経路の今のノードへ経路を引く
// 307/312命令, 原典は追跡側の枝の頭で owner の COCKAFLAG_AIRBORNE を読んで and するだけの死んだ判定を持ち, 落とした flags3 の値をそのまま UNK_7 の判定に使って u16 に詰める, 予約の5つは両方の枝から同じストア列に合流する, 試済: airborne を if の前で取る, 追跡側の枝でも airborne を取る (315)
NON_MATCH void Cockatrice_ReleaseTarget(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  bool8 airborne;
  WorldPos d;

  EnemyTargetManager_Release((p->e).target);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_12);
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    Enemy_ResetState(&p->e, 0, 0, 12);
    (p->e).animSpeedDiv = 2;
  } else {
    Enemy_ResetState(&p->e, 3, 1, 0);
    airborne = Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE);
    if (airborne) {
      Enemy_PlayAnim(&p->e, 17);
      Enemy_EnterState(&p->e, FUN_080e6834, ES_UNK_14);
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = Cockatrice_StateFly;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 17;
    } else {
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
    }
    (p->e).pathNodePos->val = 1;
  }
  d.x = (p->e).pathWalker.node->x;
  d.z = (p->e).pathWalker.node->y;
  d.y = TileHeightAt(&d);
  d.y = (p->e).mover.pos.y;
  if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d)) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Cockatrice_ReleaseTarget.inc");
#endif
}

// 足元から石のかけらを count 個はね上げる
// 103/104命令, 乱数表の基底を置くレジスタの壁 (enedefault.c の FUN_080f8844 と同じ), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_SpawnStoneShards(Cockatrice* p, s32 count) {
#ifdef NONMATCHING_C
  Vec3 vel, velRange;

  vel.x = -7;
  vel.y = (Random() & 15) + 20;
  vel.z = -7;
  velRange.x = (Random() & 3) + 15;
  velRange.y = (Random() & 7) + 15;
  velRange.z = (Random() & 3) + 15;
  ScatterEffect_Spawn(count, SCATTER_STONE, &(p->e).mover.pos, &vel, &velRange, 45, 31);
#else
  INCFUNC("asm/func/Cockatrice_SpawnStoneShards.inc");
#endif
}

s32 Cockatrice_GetMoveSpeed(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->tick == 0) {
    const u16* speeds;
    s32 i;

    if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
      i = Mod(anim->cmdIdx, 4);
      speeds = sCockatriceFastMoveSpeeds;
    } else {
      SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
      i = Mod(anim->cmdIdx, 10);
      speeds = sCockatriceMoveSpeeds;
    }
    return speeds[i];
  }
  return 0;
}

// 108/106命令, 後半の追いかけの後始末を Enemy* を受ける inline にすると 102/106 まで寄る (定数 1 を ip に置く割当が残る), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_ResetChaseState(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  (p->e).animSpeedDiv = 1;
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
  CLEAR_FLAGS(q->flags, 0xFF);
  q->fleeTimer = 0;
  q->unk_6e8 = 0;
  q->dodgeCooldown = 0;
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
#else
  INCFUNC("asm/func/Cockatrice_ResetChaseState.inc");
#endif
}

void Cockatrice_PlayIdleAnim(Cockatrice* p) {
  if (Cockatrice_TestFlags((p->e).owner, COCKAFLAG_AIRBORNE)) {
    Enemy_PlayAnim(&p->e, 17);
  } else {
    Enemy_PlayAnim(&p->e, 0);
  }
}

// COCKAFLAG_DODGING でなければ, 攻撃が当たった相手 (hitTargetID) に気付いて追う相手にしそちらを向く, 当たっていなければ FALSE
bool8 Cockatrice_NoticeHitTarget(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (!Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
    if ((p->e).hitTargetID > 0) {
      Enemy_Alert(&p->e);
      CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
      Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_7);
      Enemy_SetFlag(&p->e, ENEFLAG_UNK_27);
      CLEAR_FLAGS(q->flags, COCKAFLAG_UNK_18 | COCKAFLAG_UNK_19);
      (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
      (p->e).unk_25e = GetCollisionTileIdx(&(p->e).playerMover->pos);
      {
        Vec3 d;
        Vec3* dst = &d;
        WorldPos* pos = &(p->e).mover.pos;

        Vec3_Diff(dst, &(p->e).playerMover->pos, pos);
        (p->e).mover.angle = ArcTan2_8(d.x, d.z);
      }
      return TRUE;
    }
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
      (p->e).flags &= ~ENEFLAG_UNK_27;
    }
  }
  return FALSE;
}

// 130/129命令, Golem_OnAttackRequest と同じ形に COCKAFLAG_DODGING の判定を足したもの, 原典は owner を r3 に読み &owner->flags を r6 に持ち越す, 試済: Enemy_BeginChase, flags のアドレスを受ける inline, flags のポインタのローカル
NON_MATCH void Cockatrice_OnAttackRequest(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      return;
    }
    if (Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
      return;
    }
    Cockatrice_ChooseAttack(p);
  } else {
    if (Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
      return;
    }
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  CLEAR_FLAGS(q->flags, COCKAFLAG_UNK_19);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
#else
  INCFUNC("asm/func/Cockatrice_OnAttackRequest.inc");
#endif
}

// 気付いたときの反応, 追いかけ中なら 26 フレーム後に追跡へ移る予約をし, そうでなければ止まって追う印を立てる (COCKAFLAG_FLEEING ならそのまま), どちらも経路の今のノードを入れてプレイヤーへの経路を引く
// 423/423命令, dog.c の FUN_0814a098 と同じ保留状態の格納の壁 (原典はハンドラを先に読んで定数を後に作る), ほかは p (原典 r6) と owner まわりの割当と追跡側の枝の置き場所, 試済: 追跡でない側を先に書く (421), flags3 の判定を Enemy_GetFlag3 / Enemy_TestFlag3 に (変化なし)
NON_MATCH void Cockatrice_OnNoticeRequest(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  Vec3* target;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_DODGING)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_PlayAnim(&p->e, 0);
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 26;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    Enemy_ResetState(&p->e, 3, 1, 0);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).chaseTimer += 300;
      if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
        (p->e).chaseTimer = (p->e).chaseTimeMax;
      } else {
        if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
          target = (p->e).pathNodePos;
          target->x = (p->e).pathWalker.node->x;
          target->z = (p->e).pathWalker.node->y;
          target->y = TileHeightAt(target);
          (p->e).pathNodePos->val = 0;
          if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
            (p->e).onRouteFailed(&p->e);
          }
          return;
        }
        Cockatrice_PauseBeforeMove(p);
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
        Cockatrice_SetFlags(q, COCKAFLAG_UNK_19);
        (p->e).animSpeedDiv = 2;
      }
    }
  }
  target = (p->e).pathNodePos;
  target->x = (p->e).pathWalker.node->x;
  target->z = (p->e).pathWalker.node->y;
  target->y = TileHeightAt(target);
  (p->e).pathNodePos->val = 0;
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/Cockatrice_OnNoticeRequest.inc");
#endif
}

// 狙う相手を1つ確保できたら, unk_1f8 があって跳び先が取れれば追いかけ, なければ感情アイコンを出して相手の位置を lastSeenPos に覚える, 何かしたら TRUE
// 242/534命令の下書き, enedefault.c の FUN_080f0430 と同じ流れ, 原典は unk_1f8 のときの跳び先選びを Cockatrice_SetLongJumpTarget と同じ本体の展開で持つ (関数呼び出しではない), ほかは確保の前に flags3 の UNK_4 / UNK_8 を見ない点
NON_MATCH bool8 Cockatrice_TryDetectPlayer(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  EnemyTarget* target;
  u16 tile;

  if ((p->e).unk_618(&p->e)) {
    return TRUE;
  }
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_20)) {
    return FALSE;
  }
  if ((p->e).range0Sq == 0) {
    return FALSE;
  }
  target = EnemyTargetManager_Claim(&p->e, 6);
  if (target == NULL) {
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release((p->e).target);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_12);
    (p->e).target = NULL;
  }
  (p->e).playerMover = target->owner;
  tile = target->owner->tile->tileIdx[1];
  CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
  if ((p->e).unk_1f8 != 0 && Cockatrice_SetLongJumpTarget(p)) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
      if ((p->e).unk_25e != tile) {
        Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos);
        (p->e).unk_25e = tile;
      }
    } else {
      Enemy_Alert(&p->e);
    }
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    return TRUE;
  }
  if ((p->e).unk_544 == 0 && !TEST_FLAGS((p->e).flags, ENEFLAG_UNK_7)) {
    Cockatrice_ClearFlags(q, COCKAFLAG_UNK_18);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).unk_542 = 0xFF;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    (p->e).unk_202 = 180;
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_8);
    Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
    q->lastSeenPos = (p->e).playerMover->pos;
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Cockatrice_TryDetectPlayer.inc");
#endif
}

// 向きが変わるところで, プレイヤーと高さが違えばプレイヤーのタイルへ経路を引き直し, 同じなら横の通路の端へ見回しながら回り込む, 何かしたら TRUE
// 1421/1962命令の意味だけの下書き, 原典は直交する2方向の隣へ4方向からまっすぐ届くかの探索を (向きごとに) 全部展開し, 端のタイルを探す部分は enemy.c の FUN_080e7b6c の各節と同じ形, 前半の高さが違うときの経路の引き直しは FUN_0815b8d0 の形, 1回目の下書きで切り上げ
NON_MATCH bool8 FUN_0815d6d0(Cockatrice* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 moved;
  s32 dir;
  u32 start;
  u32 cur;
  s32 x;
  u32 height;
  s32 size;

  if (TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_1)) {
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_0)) {
    return FALSE;
  }
  if ((p->e).mover.pos.y != (p->e).playerMover->pos.y) {
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
        (p->e).unk_222 |= ENEMY222_UNK_1;
        return TRUE;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      u8 angle;

      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        (p->e).unk_222 |= ENEMY222_UNK_1;
        return TRUE;
      }
      (p->e).unk_222 &= ~ENEMY222_UNK_2;
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
      } else {
        Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
        Enemy_ResetState(&p->e, 0, 0, 12);
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
      FUN_080e7b6c(&p->e);
      (p->e).animSpeedDiv = 2;
      (p->e).unk_222 |= ENEMY222_UNK_1;
      return TRUE;
    }
    {
      WorldPos tilePos;

      TilePosAtIndex(&tilePos, tile);
      moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
    }
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
    (p->e).unk_222 |= ENEMY222_UNK_1;
    return TRUE;
  }
  // 向きと直交する2方向の隣のタイルへ, 4方向のどれかからまっすぐ歩いて届くかを調べる
  dir = -1;
  {
    s32 sides[2];
    s32 i;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0:
      case 2: {
        sides[0] = 3;
        sides[1] = 1;
        break;
      }
      default: {
        sides[0] = 0;
        sides[1] = 2;
        break;
      }
    }
    for (i = 0; i < 2 && dir < 0; i++) {
      s32 w = gCollisionMap->tiledata->width;
      s32 steps[4];
      s32 goal;
      s32 d;

      steps[0] = 1;
      steps[1] = w;
      steps[2] = -1;
      steps[3] = -w;
      start = (p->e).tileIdx;
      goal = start + steps[sides[i]];
      height = (p->e).mover.pos.y;
      size = w * gCollisionMap->tiledata->height;
      for (d = 0; d < 4 && dir < 0; d++) {
        for (cur = start + steps[d]; (s32)cur >= 0 && (s32)cur < size && CanWalkToAdjacentTile(start, cur, height, TileAtIndex(start)->heightStairs >> 4); cur += steps[d]) {
          if (cur == goal) {
            dir = sides[i];
            break;
          }
        }
      }
    }
  }
  if (dir < 0) {
    return FALSE;
  }
  // 見つけた向きへ同じ高さで通れる床が続く端のタイルを行き先にする
  start = (p->e).tileIdx;
  height = TileAtIndex(start)->heightStairs & 0xF;
  size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
  tile = start;
  switch (dir) {
    case 0: {
      cur = start + 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width; x++) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
          tile = cur - 1;
          break;
        }
        cur++;
      }
      break;
    }
    case 1: {
      for (cur = start + gCollisionMap->tiledata->width; cur < size; cur += gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
          tile = cur - gCollisionMap->tiledata->width;
          break;
        }
      }
      break;
    }
    case 2: {
      cur = start - 1;
      for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0; x--) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
          tile = cur + 1;
          break;
        }
        cur--;
      }
      break;
    }
    case 3: {
      for (cur = start - gCollisionMap->tiledata->width; (s32)cur >= 0; cur -= gCollisionMap->tiledata->width) {
        if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
          tile = cur + gCollisionMap->tiledata->width;
          break;
        }
      }
      break;
    }
  }
  if (tile == 0 || tile == (p->e).tileIdx) {
    return FALSE;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
    u8 angle = (p->e).mover.angle;
    s32 i;
    u32 a;

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
    (p->e).lookBaseAngle = dir;
    Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
    Enemy_ResetState(&p->e, 3, 1, 0);
    (p->e).unk_542 = 2;
  }
  {
    WorldPos dst;

    TilePosAtIndex(&dst, tile);
    dst.y = (p->e).mover.pos.y;
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &dst)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_0815d6d0.inc");
#endif
}

// 宙に浮いている間は攻撃を1番の組にして食らい判定を縦に伸ばし, 床にいる間は0番の組と普段の大きさに戻す
// 136/150命令, 原典は宙に浮いているかの判定を bool で持って床にいる枝の offset の 0 に使い回し, halfSize の z と val をスタックの Vec3 から1語で写す, 試済: halfSize をローカルの Vec3 から代入 (167命令)
NON_MATCH void Cockatrice_UpdateHitboxes(Cockatrice* p) {
#ifdef NONMATCHING_C
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_6)) {
    if (Cockatrice_TestFlags((p->e).owner, COCKAFLAG_AIRBORNE)) {
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0x800, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
      (p->e).hitbox.ignoreMask = HIM_4;
      (p->e).hurtbox.halfSize.x = 64;
      (p->e).hurtbox.halfSize.y = 256;
      (p->e).hurtbox.halfSize.z = 64;
      (p->e).hurtbox.offset.x = 0;
      (p->e).hurtbox.offset.y = 256 - (p->e).heightAboveFloor;
      (p->e).hurtbox.offset.z = 0;
      (p->e).hurtbox.flags |= HBFLAG_UNK_1;
    } else {
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
      (p->e).hitbox.ignoreMask = HIM_4;
      (p->e).hurtbox.halfSize.x = 64;
      (p->e).hurtbox.halfSize.y = 128;
      (p->e).hurtbox.halfSize.z = 64;
      (p->e).hurtbox.offset.x = 0;
      (p->e).hurtbox.offset.y = 128;
      (p->e).hurtbox.offset.z = 0;
      (p->e).hurtbox.flags &= ~HBFLAG_UNK_1;
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_UpdateHitboxes.inc");
#endif
}

// 経路の次のノードへ向き直って止まり, 60 フレーム後に経路移動 (0, 0, 7) へ戻るよう予約する
// 78/78命令, 残差は状態フィールドのオフセット定数を作るレジスタ (原典は r7 も使う) だけ, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_RestAndResumeRoute(Cockatrice* p) {
#ifdef NONMATCHING_C
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_0);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).pathNodePos->val = 1;
  (p->e).pendingDelay = 60;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
#else
  INCFUNC("asm/func/Cockatrice_RestAndResumeRoute.inc");
#endif
}

// 復帰時に作業値を消して経路の次のノードへ向き直り, 待機アニメを流して1コマ送る
// 187/188命令, Dog_OnReset / Golem_OnReset と同じ壁 (p->sprite を r0 に読んでから r5 へ移す), ほかに乱数表の基底の一時レジスタ
NON_MATCH void Cockatrice_OnReset(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  EnemyAuxSprite* aux;

  ClearMemory(&q->jumpVel, sizeof(Vec3));
  ClearMemory(&q->jumpTarget, sizeof(Vec3));
  q->unk_6c2 = 0;
  q->fleeTimer = 0;
  q->hopTimer = Mod(Random(), q->flightDuration);
  q->riseHeight = 0;
  q->unk_6cc = 0;
  q->fallFrames = 0;
  q->fireCooldown = 0;
  q->backstepCooldown = 0;
  q->unk_6e6 = 0;
  q->shotCount = 0;
  q->flags = 0;
  q->dodgeCooldown = 0;
  q->fleeNodeIdx = 0;
  q->flags2 = 0;
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/Cockatrice_OnReset.inc");
#endif
}

void FUN_0815ec0c(Cockatrice* p) {}

// 敵共通の被弾処理のあと, 宙に浮いていて下から石化以外の攻撃を受けたときはダメージとノックバックを消し, 姿と影を戻して攻撃元を追いかけ始める
// 960/978命令, 前半は敵共通の Enemy_HandleHurt で Golem_OnHurt と同じ共通 inline の壁, 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_HandleHurt(HitboxData* a, HitboxData* b, Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  Enemy_HandleHurt(a, b, &p->e);
  if (!(a->attributes & HBATTR_SEKIKA) && Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE) && (p->e).heightAboveFloor > 256 && (s16)(a->center.y - ((p->e).heightAboveFloor + (p->e).floorY)) < -119) {
    b->damage = 0;
    b->knockback = 0;
    b->iframes = 0;
    (p->e).unk_48a = 0;
    (p->e).unk_48c = 0;
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    if (!(p->e).shadowRemoved) {
      ParticleShadow_Show(&(p->e).shadow);
    }
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8) && !TEST_FLAGS((p->e).flags, ENEFLAG_UNK_7) && !Cockatrice_TestFlags(q, COCKAFLAG_DODGING) && !TEST_FLAGS((p->e).flags4, ENEFLAG4_UNK_7)) {
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_12)) {
        EnemyTargetManager_Release((p->e).target);
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_12);
        (p->e).target = NULL;
      }
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
      (p->e).unk_202 = 180;
      q->lastSeenPos = (p->e).playerMover->pos;
      Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_8);
      (p->e).angle = (a->halfSize.val + 9) & 7;
      Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
    }
  }
#else
  INCFUNC("asm/func/Cockatrice_HandleHurt.inc");
#endif
}

// 死んだら unk_264 の共有エンティティを手放す
void Cockatrice_ReleaseSharedEntity(Cockatrice* p) {
  if ((p->e).unk_264 != NULL && Enemy_IsDead(&p->e)) {
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
  }
}

// ENEFLAG_UNK_22 と UNK_20/21 のどちらかが立っていれば状態14で止めて経路の今のノードを目標にし直す, 宙に浮いていれば 30 フレーム後に Cockatrice_StateDescendPuzzled へ, 床なら handlerWait へ移る
// 244/248命令, enedefault.c の FUN_080f62b0 と同じ流れ, 原典は owner を r5 に読んで airborne と共有し p を r6 に置く (こちらは逆), 予約の5つを (p, delay, handler, s0, s1, s2) の inline にすると 246 命令, 試済: owner の宣言順・読む位置, airborne のローカル有無
NON_MATCH s32 Cockatrice_OnRouteFailed(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  bool8 airborne;
  Vec3* target;
  PathWalker* walker;

  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_22) || !TEST_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21)) {
    return FALSE;
  }

  SET_FLAGS((p->e).flags, ENEFLAG_UNK_8);
  (p->e).animSpeedDiv = 1;
  Enemy_ResetState(&p->e, 3, 1, 0);
  airborne = Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE);
  if (airborne) {
    Enemy_PlayAnim(&p->e, 17);
    Enemy_EnterState(&p->e, FUN_080e6834, ES_UNK_14);
    Cockatrice_SetHopVel(p, 1, 0);
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = Cockatrice_StateDescendPuzzled;
    (p->e).pendingSubState0 = 3;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 0;
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_8);
  } else {
    Enemy_PlayAnim(&p->e, 0);
    Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerWait;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 9;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  target = (p->e).pathNodePos;
  walker = &(p->e).pathWalker;
  target->x = walker->node->x;
  target->z = walker->node->y;
  target->y = TileHeightAt(target);
  (p->e).pathNodePos->val = 1;
  return TRUE;
#else
  INCFUNC("asm/func/Cockatrice_OnRouteFailed.inc");
#endif
}

void Cockatrice_ReduceHopTimer(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    q->hopTimer -= 40;
    if (q->hopTimer <= 0) {
      q->hopTimer = 0;
    }
  }
}

// 乱数の8方向が今の向きから 45 度以内なら, 今の状態を退避して見回し (Cockatrice_StateLookTurn) を始める
// 155/152命令, 乱数表の基底と添字のレジスタ割当の壁 (enedefault.c の FUN_080f8844 と同じ), 1回目の下書きで切り上げ
NON_MATCH void Cockatrice_TryLookAround(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 angle = (Random() & 7) << 5;
  s32 d = angle - (p->e).mover.angle;

  if (d > 128) {
    d -= 256;
  }
  if (d < -128) {
    d += 256;
  }
  if (abs(d) <= 32) {
    (p->e).savedHandlerState = (p->e).handlerState;
    (p->e).savedState = (p->e).state;
    (p->e).savedSubState0 = (p->e).subState0;
    (p->e).savedSubState1 = (p->e).subState1;
    (p->e).savedSubState2 = (p->e).subState2;
    q->lookBaseAngle = (p->e).mover.angle;
    q->lookDir = angle >> 5;
    q->lookTimer = ((Random() & 3) + 1) * 120;
    Enemy_EnterState(&p->e, Cockatrice_StateLookTurn, ES_UNK_44);
    Enemy_ResetState(&p->e, 3, 1, 0);
    q->lookCount = 4;
  }
#else
  INCFUNC("asm/func/Cockatrice_TryLookAround.inc");
#endif
}

// hp が残る被弾への反応, 撃ちかけの弾を消し, 気絶・被弾状態・逃げる・追いかけ直しのどれに移るかを決める, 移ったら TRUE
// 1212/1284命令の粗い下書き, 追いかけ中の後半は FUN_0815b8d0 の形 (状態フィールドのアドレスをスタックに作り置く壁も同じ), 気絶の枝の flags3 の落とし方は asm から読んだまま, 1回目の下書きで切り上げ
NON_MATCH bool8 Cockatrice_OnDamaged(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 moved;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_2 | ENEFLAG3_UNK_15)) {
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_14)) {
    (p->e).flags3 = ((p->e).flags3 | ENEFLAG3_UNK_2) & ~(ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_12);
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
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    Enemy_EnterState(&p->e, Cockatrice_StateStunned, ES_UNK_46);
    Enemy_ResetState(&p->e, 3, 0, 0);
    q->fleeTimer = 0;
    Cockatrice_ClearFlags(q, 0xFF);
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1 | ENEFLAG2_UNK_24);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) {
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    q->fleeTimer = 0;
    Cockatrice_ClearFlags(q, 0xFF);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) || (p->e).unk_4be != 0) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_6 | ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_11);
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    q->fleeTimer = 0;
    Cockatrice_ClearFlags(q, 0xFF);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    Cockatrice_StartFlee(p);
    return TRUE;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
    (p->e).unk_4be = 45;
    (p->e).unk_48d = 0x41;
    Enemy_PlayAnim(&p->e, 3);
  }
  (p->e).unk_544 = 300;
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
      return FALSE;
    }
    (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
    Cockatrice_StartFlee(p);
    Enemy_EnterState(&p->e, Cockatrice_StateFlee, ES_UNK_52);
    Enemy_ResetState(&p->e, 0, 0, 19);
    return TRUE;
  }
  (p->e).unk_264 = Entity081e9cacElem_Remove((p->e).unk_264);
  if ((p->e).playerMover == NULL) {
    return FALSE;
  }
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
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return TRUE;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }
  if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    u8 angle;

    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return TRUE;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
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
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
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
    FUN_080e7b6c(&p->e);
    (p->e).animSpeedDiv = 2;
    return TRUE;
  }
  {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    moved = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
  }
  if (!moved) {
    (p->e).onRouteFailed(&p->e);
    return TRUE;
  }
  Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
  Enemy_ResetState(&p->e, 0, 0, 12);
  return TRUE;
#else
  INCFUNC("asm/func/Cockatrice_OnDamaged.inc");
#endif
}

// 37/38命令, 原典は判定の前に p を r2 へ写して判定に r2, 呼び出しに r4 を使う (inline の引数の写しらしい), 試済: Enemy_TestFlag3, Enemy* のローカル
NON_MATCH s32 Cockatrice_UpdateFrame(Cockatrice* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_2) || (p->e).unk_4be == 0) {
    Cockatrice_PreUpdate(p);
    {
      u32 idx = (p->e).subState0;
      EnemyHandler* table = (p->e).handlerTables[0];
      table[idx](&p->e);
    }
    Enemy_RunStateHandler(&p->e);
    Cockatrice_PostUpdate(p);
  }
  return 1;
#else
  INCFUNC("asm/func/Cockatrice_UpdateFrame.inc");
#endif
}

s32 Cockatrice_Update(Cockatrice* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Cockatrice_Destroy(Cockatrice* p) {
  Hitbox_Unregister(&p->senseHitbox);
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
// 1780/1948命令, Golem_Init の下書きをコカトリス向けに直したもの ('T' / 'P' / 'U' の名前付き引数と fireRangeSq / unk_6d4 を足す), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline の壁), 1回目の下書きで切り上げ
NON_MATCH s32 Cockatrice_Init(Cockatrice* p) {
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
  p->lookTimer = 120;
  *(u16*)p->unk_6bc = Random() & 7;
  p->lookCount = 0;
  p->lookBaseAngle = 0;
  p->backstepCooldown = 0;
  p->fireCooldown = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_COCKA;
  Cockatrice_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_COCKATRICE);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_COCKATRICE);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_COCKATRICE);
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
  if (!VM_SeekToNamedArg('T')) {
    p->walkDuration = 800;
    p->flightDuration = 600;
    p->fleeDuration = 600;
  } else {
    p->walkDuration = VM_GetPC() != NULL ? VM_GetValue() : 800;
    p->flightDuration = VM_GetPC() != NULL ? VM_GetValue() : 600;
    p->fleeDuration = VM_GetPC() != NULL ? VM_GetValue() : 600;
  }
  p->hopTimer = Mod(Random(), p->flightDuration);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 513;
  (p->e).unk_47c = 306;
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
  Cockatrice_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Cockatrice_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Cockatrice_GetMoveSpeed;
  (p->e).handlerTurn = (void*)Cockatrice_StateTurn;
  (p->e).handlerMove = (void*)Cockatrice_StateMove;
  (p->e).handlerWait = (void*)Cockatrice_StateWait;
  (p->e).unk_5c0 = (void*)Cockatrice_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)Cockatrice_OnRouteFailed;
  (p->e).handlerDamaged = (void*)Cockatrice_StateDamaged;
  (p->e).handlerDying = (void*)Cockatrice_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = (void*)Cockatrice_StateHeardSound;
  (p->e).unk_584 = (void*)Cockatrice_StateRespawnWait;
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
  (p->e).unk_5e0 = NULL;
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
  (p->e).unk_1bc = 0;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).unk_5f0 = (EnemyHandler)Cockatrice_ReleaseTarget;
  (p->e).tryDetectPlayer = (void*)Cockatrice_TryDetectPlayer;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).onReset = (EnemyHandler)Cockatrice_OnReset;
  (p->e).handlerLookAround = (void*)Cockatrice_StateLookAround;
  (p->e).unk_5fc = (void*)FUN_0815ec0c;
  (p->e).unk_618 = (void*)Cockatrice_NoticeHitTarget;
  (p->e).onDamaged = (void*)Cockatrice_OnDamaged;
  (p->e).onAttackRequest = (EnemyHandler)Cockatrice_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)Cockatrice_OnNoticeRequest;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22 | ENEFLAG_UNK_24);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  (p->e).kind = ENEK_COCKA;
  if (!VM_SeekToNamedArg('P')) {
    p->shotSpeed = 20;
    p->shotLifetime = 300;
    p->backstepInterval = 0;
    p->fireInterval = 0;
  } else {
    p->shotSpeed = VM_GetPC() != NULL ? VM_GetValue() : 20;
    p->shotLifetime = VM_GetPC() != NULL ? VM_GetValue() : 300;
    p->backstepInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->fireInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  p->fleePathIdx = VM_GetNamedArgValue('U', (p->e).unk_250);
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
  {
    Cockatrice* q = (p->e).owner;

    q->fireRangeSq = Div((p->e).unk_1e8 * 7, 10);
    q->unk_6d4 = (p->e).unk_1e8;
  }
  Enemy_InitHandlerTables(&p->e);
  Cockatrice_SetHandlerTable2(p);
  Cockatrice_SetHandlerTable4(p);
  Cockatrice_SetHandlerTable3(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Cockatrice_Update;
  (p->e).handlerDestroy = (EnemyHandler)Cockatrice_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Cockatrice_Init.inc");
#endif
}

void Cockatrice_Create(void) {
  Cockatrice* p = Malloc(sizeof(Cockatrice));

  if (p != NULL) {
    ClearMemory(p, sizeof(Cockatrice));
    if (Cockatrice_Init(p) < 0) {
      Cockatrice_Destroy(p);
      Free(p);
    }
  }
}

// 向いている4方向へ2タイル先まで歩けるタイルをたどって jumpTarget にする, 今のタイルのままで fireCooldown が残っていれば FALSE
// 297/291命令, Slime_PickWalkDest と同じ探索の形, 原典のループは本体から入って末尾で n < 2 を比べるが, こちらは for だと頭で n > 1 を比べ, do/while でも n <= 1 に正規化される (293命令), 試済: ++n の条件, n を u8 / s16
NON_MATCH s32 Cockatrice_SetLongJumpTarget(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  u32 tileIdx = (p->e).tileIdx;
  s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
  s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
  u32 target;
  s32 idx;
  s32 n;

  switch (FixToInt(6, (p->e).mover.angle + 0x20) & 3) {
    case 0: {
      idx = tileIdx + 1;
      for (n = 0; n < 2; n++) {
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
      for (n = 0; n < 2; n++) {
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
      for (n = 0; n < 2; n++) {
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
      for (n = 0; n < 2; n++) {
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
  if (target == (p->e).tileIdx) {
    TilePosAtIndex(&q->jumpTarget, target);
    if (q->fireCooldown > 0) {
      return FALSE;
    }
  } else {
    TilePosAtIndex(&q->jumpTarget, target);
  }
  return TRUE;
#else
  INCFUNC("asm/func/Cockatrice_SetLongJumpTarget.inc");
#endif
}

void FUN_08161b90(Cockatrice* p) {
  p->fleeTimer = 0;
  CLEAR_FLAGS(p->flags, 0xFF);
}

// COCKAFLAG_FLEEING が立っていて fleeTimer が尽きていれば, 止まって 60 フレーム後に経路移動へ戻るよう予約し, 経路の今のノードへ経路を引いて COCKAFLAG_FLEEING を落とす
// 329/330命令, 原典は Enemy_PlayAnim(0) の直前に owner の COCKAFLAG_AIRBORNE を読んで and するだけの死んだ判定を持つ (使わない bool8 に Cockatrice_TestFlags を入れると出る, Cockatrice_ReleaseTarget の追跡側も同じ), 残りは &flags3 と &owner->flags の r8/r9 の割当と予約のストアの並び, 試済: 予約を (p, delay, handler, s0, s1, s2) の inline に (335), flags3 の判定を Enemy_GetFlag3 / Enemy_TestFlag3 に
NON_MATCH void Cockatrice_TryEndFlee(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;
  WorldPos d;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (!Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_12 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    return;
  }
  if (q->fleeTimer > 0) {
    return;
  }
  Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  Cockatrice_ResetChaseState(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  Enemy_PlayAnim(&p->e, 0);
  (p->e).pendingDelay = 60;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  Enemy_ResetState(&p->e, 3, 1, 0);
  d.x = (p->e).pathWalker.node->x;
  d.z = (p->e).pathWalker.node->y;
  d.y = TileHeightAt(&d);
  d.y = TileHeightAtIndex(GetCollisionTileIdx(&d), &(p->e).mover.pos);
  Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d);
  (p->e).pathNodePos->val = 1;
  if (Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
    Cockatrice_ClearFlags(q, COCKAFLAG_FLEEING);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
    (p->e).animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/Cockatrice_TryEndFlee.inc");
#endif
}

// 向いている4方向の隣のタイルの中心を jumpTarget にする
void Cockatrice_SetJumpTargetAhead(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;
  s32 dir = (((p->e).mover.angle + 0x20) >> 6) & 3;
  s32 tileIdx = 0;

  switch (dir) {
    case 0: {
      tileIdx = (p->e).tileIdx + 1;
      break;
    }
    case 1: {
      tileIdx = (p->e).tileIdx + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      tileIdx = (p->e).tileIdx - 1;
      break;
    }
    case 3: {
      tileIdx = (p->e).tileIdx - gCollisionMap->tiledata->width;
      break;
    }
  }
  TilePosAtIndex(&q->jumpTarget, tileIdx);
}

// 宙に浮いているかと高さで広げた射程を更新して上昇・落下を進め, 移動中は hopTimer が尽きるたびに Cockatrice_StatePrepareJump へ移る
void Cockatrice_UpdateAirState(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).heightAboveFloor > 0) {
    s32 range;

    Cockatrice_SetFlags(q, COCKAFLAG_AIRBORNE);
    range = (p->e).range0 * (FixToInt(9, (p->e).heightAboveFloor) + 1);
    (p->e).range0Sq = range * range;
  } else {
    Cockatrice_ClearFlags(q, COCKAFLAG_AIRBORNE);
    Cockatrice_ClearFlags(q, COCKAFLAG_UNK_2);
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    Cockatrice_StepFall(p);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  } else if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    if (!((p->e).state == ES_UNK_38 || (p->e).state == ES_UNK_39 || (p->e).state == ES_UNK_45 || (p->e).state == ES_UNK_41 || (p->e).state == ES_UNK_42 || (p->e).state == ES_UNK_34 || (p->e).state == ES_UNK_36)) {
      Cockatrice_StepRise(p);
    }
  }
  if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_12)) {
    return;
  }
  if (Cockatrice_TestFlags(q, COCKAFLAG_UNK_19)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_24) || TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4)) {
    return;
  }
  if ((p->e).state == ES_UNK_1 || (p->e).state == ES_UNK_35) {
    if ((p->e).state == ES_UNK_35) {
      if (q->hopTimer <= 0) {
        Cockatrice_ClearFlags(q, COCKAFLAG_UNK_2);
        q->hopTimer = q->walkDuration;
      } else {
        q->hopTimer--;
      }
    } else if (q->hopTimer <= 0) {
      Enemy_EnterState(&p->e, Cockatrice_StatePrepareJump, ES_UNK_33);
      Enemy_ResetState(&p->e, 3, 1, 0);
      q->hopTimer = q->flightDuration;
    } else {
      q->hopTimer--;
    }
  }
}

// 生きている間 fireCooldown と backstepCooldown を, COCKAFLAG_AT_FLEE_NODE の間は unk_6e8 も 0 まで1ずつ減らす
void Cockatrice_TickTimers(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e)) {
    if (q->fireCooldown > 0) {
      q->fireCooldown--;
    }
    if (q->backstepCooldown > 0) {
      q->backstepCooldown--;
    }
    if (Cockatrice_TestFlags(q, COCKAFLAG_AT_FLEE_NODE) && q->unk_6e8 > 0) {
      q->unk_6e8--;
    }
  }
}

// 状態 38 / 42 の間は攻撃判定の威力とノックバックを2番の組に, それ以外は0番の組にする
void Cockatrice_UpdateAtkPower(Cockatrice* p) {
  if (!Enemy_IsDead(&p->e)) {
    u16 power, knockback;

    if ((p->e).state == ES_UNK_38 || (p->e).state == ES_UNK_42) {
      power = (p->e).atkPower[2];
      knockback = (p->e).atkKnockback[2];
    } else {
      power = (p->e).atkPower[0];
      knockback = (p->e).atkKnockback[0];
    }
    (p->e).hitbox.damage = power;
    (p->e).hitbox.knockback = knockback;
  }
}

void Cockatrice_TickFleeTimer(Cockatrice* p) {
  Cockatrice* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e)) {
    if (!Cockatrice_TestFlags(q, COCKAFLAG_FLEEING)) {
      CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
    } else if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_12 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15) && q->fleeTimer > 0) {
      q->fleeTimer--;
      SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_2);
    }
  }
}

// 68/68命令, 残差は flags2 のアドレスを置くレジスタ (r2 と原典 r0) と最後の合流の形だけ, 試済: 判定を && でまとめた形 (62命令), 枝ごとに落とす形 (これ)
NON_MATCH void Cockatrice_UpdateLookTimer(Cockatrice* p) {
#ifdef NONMATCHING_C
  Cockatrice* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    CLEAR_FLAGS(q->flags2, COCKAFLAG2_UNK_0);
  } else if (Cockatrice_TestFlags(q, COCKAFLAG_AIRBORNE | COCKAFLAG_FLEEING)) {
    CLEAR_FLAGS(q->flags2, COCKAFLAG2_UNK_0);
  } else if (TEST_FLAGS(q->flags2, COCKAFLAG2_UNK_0)) {
    if (q->lookTimer < 0) {
      Cockatrice_TryLookAround(p);
    } else {
      q->lookTimer--;
    }
    CLEAR_FLAGS(q->flags2, COCKAFLAG2_UNK_0);
  }
#else
  INCFUNC("asm/func/Cockatrice_UpdateLookTimer.inc");
#endif
}
