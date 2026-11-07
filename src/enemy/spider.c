#include "coffin.h"
#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
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

// スパイダー(ENEID_SPIDER), ポイズンスパイダー(ENEID_PSPIDER)
// 見えない蜘蛛の巣を仕掛けて、プレイヤーがそれに触れると身動きが取れなくなる
// ポイズンスパイダーは毒液も吐く
typedef struct {
  Enemy e;
  u8 unk_654[4];             // 0x654
  Mover* venomTarget;        // 0x658, 毒液を吐く状態に入ったときの playerMover, SpiderVenom_Spawn の狙い先
  s16 unk_65c;               // 0x65C
  s16 unk_65e;               // 0x65E
  u16 unk_660;               // 0x660, bit1 はプレイヤーが Entity080db520 の枠を持っていないとき落とす
  u16 unk_662;               // 0x662, 300 から数え下ろし, 0 になると棺桶を狙いに行く
  u8 unk_664[1680 - 0x664];  // 0x664
} Spider;
static_assert(sizeof(Spider) == 1680);

static inline bool8 Spider_TestUnk660(Spider* p, u16 bit) {
  if (p->unk_660 & bit) return TRUE;
  return FALSE;
}

void FUN_080e8614(Enemy* p);
void FUN_080e68d8(Enemy* p, s32 timer);
void FUN_08130eec(Spider* p);
void FUN_081307b0(Spider* p);
void SpiderVenom_Spawn(void* p, Mover* mover, Mover* target, s32 power, s32 knockbackPower, s32 invincibleTime);
s32 Map_HasLineOfSight(Vec3* pos, Vec3* target, s32 count, s32 limit);
s32 FUN_080db290(void* p, Mover* mover);
void Spider_PickRandomPathNode(Spider* p);
void FUN_0812f83c(Spider*);
void FUN_0812f840(Spider*);
void FUN_0812f9ec(Spider*);
void FUN_0812fbec(Spider*);
void FUN_0812fcd8(Spider*);
void FUN_0812fdb8(Spider*);
void FUN_08130068(Spider*);
void FUN_08130460(Spider*);
void FUN_08130610(Spider*);
void FUN_0813069c(Spider*);

void (*const PTR_ARRAY_085ad6bc[17])(Spider*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    FUN_0812fdb8,
    FUN_0812fbec,
    FUN_0812f9ec,
    NULL,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    FUN_0812f840,
    FUN_0812fcd8,
    NULL,
    FUN_08130068,
    FUN_0812f83c,
};  // 0x085AD6BC

void (*const PTR_ARRAY_085ad700[3])(Spider*) = {
    (void*)FUN_080f1c54,
    (void*)FUN_080f1cb8,
    (void*)FUN_080f1cf0,
};  // 0x085AD700

const u16 u16_ARRAY_085ad70c[2] = {486, 486};  // 0x085AD70C

void FUN_081302f8(Spider*, u16*);

void (*const PTR_ARRAY_085ad710[7])(Spider*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_081302f8,
};  // 0x085AD710

void Spider_OnHit(HitboxData* a, HitboxData* b, Spider* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void Spider_OnHurt(HitboxData* a, HitboxData* b, Spider* p) { INCFUNC("asm/func/Spider_OnHurt.inc"); }

void FUN_0812ea6c(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void FUN_0812ea90(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

NAKED void FUN_0812eab4(Spider* p) { INCFUNC("asm/func/FUN_0812eab4.inc"); }

// 残差は143/144命令, p が r6 に乗る (原典は r7), 保留状態の格納は unk_5a4 を先に読み 5 を ip に置く, inline で引数を先に評価させると読む順は揃うが割り当ては変わらない
NON_MATCH void FUN_0812edf8(Spider* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    AuxShadow_Show(&(p->e).auxShadow);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Hitbox_SetFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
    Hitbox_SetFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    if (!(p->e).unk_44c) {
      AuxShadow_Remove(&(p->e).auxShadow);
      (p->e).unk_44c = 1;
    }
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Hitbox_ClearFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    (p->e).pendingDelay = 20;
    (p->e).pendingHandler = (p->e).unk_5a4;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 5;
    Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
    Enemy_ResetState(&p->e, 3, 1, 0);
  }
#else
  INCFUNC("asm/func/FUN_0812edf8.inc");
#endif
}

// 巣で待つ状態, 待ち時間が過ぎたら, 巣に獲物が掛かっているか 1/4 の確率で状態 (unk_5a0, 副状態7) へ, そうでなければ (unk_5a4, 副状態5) へ 60 フレーム後に移る
// 242/251命令, FUN_0812edf8 と同じ保留状態の格納の壁 (原典はハンドラを先に読み副状態の定数を r8 に置く), 加えて原典は &mover を r8 に写して FUN_080db290 に渡し, variant や乱数の 0 をそのまま格納の 0 に使う, 試済: 保留状態の inline, Mover* / Enemy* のローカル
NON_MATCH void FUN_0812ef50(Spider* p, s32 timer) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;
  Mover* mover = &(p->e).mover;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Enemy_PlayAnim(&p->e, 14);
  if (timer > q->unk_65e) {
    CLEAR_FLAGS(q->unk_660, 4);
    if ((p->e).variant == 0 && FUN_080db290((p->e).unk_260, mover) >= 0) {
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).unk_5a0;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
      Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
      Enemy_ResetState(&p->e, 3, 1, 0);
    } else if (((Random() >> 3) & 3) == 0) {
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).unk_5a0;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 7;
      Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
      Enemy_ResetState(&p->e, 3, 1, 0);
    } else {
      (p->e).pendingDelay = 60;
      (p->e).pendingHandler = (p->e).unk_5a4;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 5;
      Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
      Enemy_ResetState(&p->e, 3, 1, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_0812ef50.inc");
#endif
}

void FUN_0812f1b4(Spider* p) {}

void FUN_0812f1b8(Spider* p) {}

// 毒液を吐く状態, アニメの4コマ目で狙い先へ毒液を飛ばし, 終わったら経路を引き直して追いかけに戻る
void Spider_SpitVenom(Spider* p, s32 timer) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  Spider* q = (p->e).unk_1cc;
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_PlayAnim(&p->e, 5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_14);
    q->venomTarget = (p->e).playerMover;
  }
  if (anim->cmdIdx == 3 && anim->tick == 0) {
    PlaySound_082406e0(CRY_SPIDER_ATK);
    if (q->venomTarget != NULL) {
      SpiderVenom_Spawn((p->e).unk_260, mover, q->venomTarget, (p->e).atkPower[1], (p->e).atkUnk40[1], (p->e).atkInvincibleTime[1]);
    }
  }
  if ((p->e).animForceRestart && timer > 60) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
  }
}

void FUN_0812f358(Spider* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Enemy_PlayAnim(&p->e, 1);
  if ((p->e).unk_24e == 0) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    Enemy_ResetState(&p->e, 0, 0, 7);
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
  }
}

// 被弾して後ろへ滑る状態, 滑り終えたら経路を引き直して追いかけに戻る
void FUN_0812f3f8(Spider* p, s32 timer) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    CLEAR_FLAGS(((Spider*)(p->e).unk_1cc)->unk_660, 2 | 4);
    Enemy_PlayAnim(&p->e, 3);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    PlaySound_082406e0(SE_UNK_274);
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  Enemy_SetFlag(&p->e, ENEFLAG_UNK_13);
  if (timer < 18 && anim->cmdIdx == 1) {
    anim->tick = 0;
  }
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    (p->e).mover.angle = (p->e).unk_1fc;
    Enemy_SetFlag(&p->e, ENEFLAG_UNK_4);
  }
}

// 倒されたときの状態, 粒子を散らしながら点滅して消えたら倒されたスクリプトを呼び図鑑に載せて止まる
// 228/228命令, flags の検査を Enemy_TestFlag にし, 消えきった後は影を触らず return すると割り当て以外は揃う, 残差は入場時の乱数とフィールド格納のアドレス用の一時レジスタ番号 (r1/r3/r6 と原典 r3/r6/r0), 試済: Random() & 0xFF, 片方だけ TEST_FLAGS, 入場の3行の inline
NON_MATCH void Spider_StateDying(Spider* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 3);
    PlayEnemyDeathCry(&p->e);
    (p->e).unk_470 = 60;
    (p->e).unk_452 = Random();
    (p->e).unk_453 = 1;
  }
  if (Enemy_TestFlag(&p->e, ENEFLAG_UNK_15)) {
    return;
  }
  if (Sprite_UpdateVanishBlink(&((AuxSprite*)(p->e).sprite)->flags, timer, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
    if ((p->e).unk_19a != 0) {
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
      VM_ExecByID((p->e).unk_19a, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    return;
  }
  if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    ParticleShadow_Show(&(p->e).shadow);
  }
#else
  INCFUNC("asm/func/Spider_StateDying.inc");
#endif
}

s32 FUN_0812f818(Spider* p) {
  FUN_08130460(p);
  FUN_08130610(p);
  FUN_0813069c(p);
  FUN_080e8614(&p->e);
  return 1;
}

void FUN_0812f83c(Spider* p) {}

// 経路に沿って歩き, 通過点が変わって曲がれたら副状態13へ, 経路の終わりに着いたら経路を引き直して状態1へ戻る
void FUN_0812f840(Spider* p) {
  s32 speed;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  speed = (p->e).unk_588(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Map_ConsumeNavWaypointChanged((p->e).navAgent) && FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 13);
    return;
  }
  if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_1);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
  } else {
    (p->e).subStateTimer++;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 経路に沿って歩き, 経路の終わりに着いたら副状態5へ, 通過点が変わって曲がれたら副状態6へ移る
void FUN_0812f9ec(Spider* p) {
  Spider* q = (p->e).unk_1cc;
  s32 speed;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  speed = (p->e).unk_588(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_14) && !Spider_TestUnk660((p->e).unk_1cc, 4)) {
    FUN_081307b0(p);
  }
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 5);
      Enemy_ClearFlag(&p->e, ENEFLAG_UNK_14);
      CLEAR_FLAGS(((Spider*)(p->e).unk_1cc)->unk_660, 2);
      return;
    }
  } else if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 6);
  }
  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_14) && q->unk_65c > 0) {
    Enemy_SetFlag(&p->e, ENEFLAG_UNK_13);
  }
  (p->e).subStateTimer++;
}

void FUN_0812fbec(Spider* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  } else if (!(p->e).unk_608(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 7);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_0812fcd8(Spider* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  } else if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
  } else {
    (p->e).subStateTimer++;
  }
}

NAKED void FUN_0812fdb8(Spider* p) { INCFUNC("asm/func/FUN_0812fdb8.inc"); }

void FUN_08130068(Spider* p) {
  Enemy_ConsumeSubStateBegun(&p->e);
  if (!(p->e).unk_608(&p->e)) {
    (p->e).subStateTimer++;
  }
}

void FUN_081300a8(Spider* p) {
  Enemy_ConsumeSubStateBegun(&p->e);
  (p->e).subStateTimer++;
}

void FUN_081300d0(Spider* p) {
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad6bc;
  (p->e).handlerTables[6] = (void*)PTR_ARRAY_085ad700;
}

void Spider_InitHitboxes(Spider* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 128, 128, 128);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtboxWithFlags(&p->e, &hurtSize, &hurtOffset, Spider_OnHurt, p, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_3 | HBFLAG_UNK_1 | HBFLAG_UNK_0);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Spider_OnHit, 0, p);
}

// 復帰時に作業値を消して経路の次のノードへ向き直り, 待機アニメを流して1コマ送る
// 残差1命令, 原典は p->sprite を r0 に読んでから r5 へ移す (Slime_OnReset / Boku_OnReset / Mimic_OnReset と同じ壁)
NON_MATCH void Spider_OnReset(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_65c = 0;
  q->unk_65e = 0;
  q->unk_660 = 0;
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
#else
  INCFUNC("asm/func/Spider_OnReset.inc");
#endif
}

void Spider_InitAnims(Spider* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 2, 5, 0);
  Enemy_SetAnimEntry(&p->e, 3, 4, 0);
  Enemy_SetAnimEntry(&p->e, 5, 2, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
}

// プレイヤーと同じ島にいればプレイヤーを追いかける状態へ移る
void FUN_081302f8(Spider* p, u16* msg) {
  if (Enemy_IsDead(&p->e) == 0 && gPlayerPtr[0] != NULL) {
    if (Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos)) {
      *(p->e).unk_4a8 = (p->e).mover.pos;
      (p->e).unk_4a8->val = 0;
      (p->e).playerMover = &gPlayerPtr[0]->mover;
      Enemy_ResetState(&p->e, 0, 0, 7);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_14);
      (p->e).animSpeedDiv = 3;
      ((Spider*)(p->e).unk_1cc)->unk_660 |= 2;
      ((Spider*)(p->e).unk_1cc)->unk_65c = 0;
    }
  }
}

void FUN_08130460(Spider* p) {
  if (Enemy_IsDead(&p->e) == 0 && gPlayerPtr[0]->unk_3ff < 0) {
    Spider* q = (p->e).unk_1cc;

    CLEAR_FLAGS(q->unk_660, 2);
  }
}

// 棺桶が x 方向 rangeX, z 方向 rangeZ 以内にいれば TRUE を返す
bool8 Spider_IsCoffinInRange(Spider* p, s32 rangeX, s32 rangeZ) {
  WorldPos* coffin = Coffin_GetPos();

  if (coffin != NULL) {
    Vec3 d;

    Vec3_Diff(&d, coffin, &(p->e).mover.pos);
    if (abs(d.x) <= rangeX && abs(d.z) <= rangeZ) {
      return TRUE;
    }
  }
  return FALSE;
}

// 棺桶への経路を引けたら棺桶を狙って歩き出す
// 残差1命令, ドッグの FUN_0814e424 と同じ「失敗の出口を2つ持つ経路 inline」にすると定数 4 (unk_660 の bit と animSpeedDiv) が1本のレジスタにまとめられる所だけ違う
NON_MATCH bool8 FUN_08130508(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e)) {
    WorldPos* dst = Coffin_GetPos();

    if (dst != NULL && Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, dst)) {
      SET_FLAGS(q->unk_660, 4);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 4;
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08130508.inc");
#endif
}

// 棺桶が空いて止まっている間, 300 フレームごとに棺桶を狙いに行く
void FUN_08130610(Spider* p) {
  if ((p->e).variant != 1) {
    Spider* q = (p->e).unk_1cc;

    if (FUN_08086878() != -1 || !Coffin_IsIdle()) {
      q->unk_662 = 300;
      CLEAR_FLAGS(q->unk_660, 4);
    } else if (q->unk_662 != 0) {
      q->unk_662--;
    } else {
      q->unk_662 = 300;
      if (!Spider_TestUnk660(q, 4)) {
        FUN_08130508(p);
      }
    }
  }
}

// 日が当たっている間は巡回をやめて棺桶へ向かい, 日が陰ったら元の速さに戻す
// 121/121 命令, 原典は unk_660 のアドレスを別レジスタに写し, 日向の枝で bit3 の判定を 0/1 に作り直してから分岐する, 試済: 判定の inline, TestMapFlag の inline (5 命令増える)
NON_MATCH void FUN_0813069c(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e) && Spider_TestUnk660(q, 0x10)) {
    if (TEST_FLAGS(gStat->mapFlags, MPF_BRIGHT)) {
      if (!Spider_TestUnk660(q, 8)) {
        Enemy_StepTowardPathNode(&p->e);
        Enemy_ResetState(&p->e, 0, 0, 7);
        Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
        q->unk_660 |= 8;
      }
      (p->e).animSpeedDiv = 5;
    } else if (Spider_TestUnk660(q, 8)) {
      q->unk_660 &= ~8;
      (p->e).animSpeedDiv = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0813069c.inc");
#endif
}

// 30 フレームごとに, 前方の乱数の向きと距離の点を unk_20c に選んで経路を引き, 次に選ぶまでの待ちを unk_65c に入れる
// 231/241命令, 原典は乱数の表・gRandTableIdx のアドレス・0x3FF を関数の頭から callee-saved (sl/r7/r6) に置いて3つ目の乱数まで持ち越し, p をスタック (sp+8) に退避して経路 inline の pos に使う, こちらは定数を毎回プールから読む (乱数の割り当ての壁)
NON_MATCH void FUN_081307b0(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;
  u16* table = gRandomTable;
  s32 dist = (_Random(table) & 0x3FF) + 256;
  s32 spread = (_Random(table) & 0x7F) - 63;
  u8 angle = spread + (p->e).mover.angle;

  if (Mod((p->e).subStateTimer, 30) == 0) {
    WorldPos pos;

    if (q->unk_65c > 0) {
      q->unk_65c--;
      return;
    }
    pos.x = ((COS(angle) * dist) >> 14) + (p->e).mover.pos.x;
    pos.y = (p->e).mover.pos.y;
    pos.z = ((SIN(angle) * dist) >> 14) + (p->e).mover.pos.z;
    if (!Map_IsPosInAgentIsland((p->e).navAgent, &(p->e).mover.pos, &pos)) {
      if (!Spider_TestUnk660(q, 0x10)) {
        (p->e).animSpeedDiv = 1;
      }
      Enemy_StepTowardPathNode(&p->e);
      q->unk_65c = 0;
      return;
    }
    (p->e).unk_20c = pos;
    (p->e).animSpeedDiv = (_Random(table) & 3) == 0 ? 4 : 1;
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).unk_20c)) {
      Enemy_StepTowardPathNode(&p->e);
      q->unk_65c = 0;
    }
    if (Spider_TestUnk660(q, 8)) {
      q->unk_65c = 60;
      return;
    }
    q->unk_65c = 120;
  } else if (q->unk_65c > 0) {
    q->unk_65c--;
  }
#else
  INCFUNC("asm/func/FUN_081307b0.inc");
#endif
}

bool8 FUN_081309f0(Spider* p) {
  if ((p->e).hitTargetID > 0) {
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
    return TRUE;
  }
  return FALSE;
}

NAKED bool8 FUN_08130ac4(Spider* p) { INCFUNC("asm/func/FUN_08130ac4.inc"); }

// プレイヤーが見えていて前方 45 度以内にいれば追いかけを始めて TRUE を返す
// 196/194命令, 原典は flags3 のアドレスを検査のときに r7 へ写して末尾の SET_FLAGS まで持ち越し, p が r5 に乗る, 試済: 条件の入れ子, 角度差の inline, Enemy_BeginChase, flags3 の直接演算
NON_MATCH bool8 FUN_08130d34(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;
  Mover* mover = &(p->e).mover;
  u8 angle;
  Vec3 diff;
  s32 d;

  if (Spider_TestUnk660(q, 4)) {
    return FALSE;
  }
  if (FUN_081309f0(p)) {
    return TRUE;
  }
  if (gPlayerPtr[0]->flag20 & PFLAG20_INVISIBLE) {
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    return FALSE;
  }
  if ((p->e).unk_1e4 > (p->e).range0Sq) {
    return FALSE;
  }
  angle = (p->e).mover.angle;
  Vec3_Delta(&diff, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
  d = ArcTan2_8(diff.x, diff.z) - angle;
  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  if (abs(d) > 32) {
    return FALSE;
  }
  if (!(u8)Map_HasLineOfSight(&mover->pos, &gPlayerPtr[0]->mover.pos, 5, 0x100)) {
    return FALSE;
  }
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_ResetState(&p->e, 0, 0, 12);
  Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
  FUN_08130eec(p);
  Enemy_StepTowardPathNode(&p->e);
  if ((p->e).kind != ENEK_SPIDER) {
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  }
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
  (p->e).unk_24e = (p->e).unk_24c;
  return TRUE;
#else
  INCFUNC("asm/func/FUN_08130d34.inc");
#endif
}

// プレイヤーと反対側にある道順のノードを選び, 見つからなければでたらめに選ぶ
// 下書き段階, 100/144 命令, 原典は 0x10 バイトのスタックに向きのベクトルなどを置いている
NON_MATCH void FUN_08130eec(Spider* p) {
#ifdef NONMATCHING_C
  Mover* m = (p->e).playerMover;
  u8 angle = ArcTan2_8(m->pos.x - (p->e).mover.pos.x, m->pos.z - (p->e).mover.pos.z);
  s16 cs = gSineTable[(angle + 0x40) & 0xFF];
  s16 sn = gSineTable[angle];
  PathNode* node = Map_GetPathNodes((p->e).pathWalker.path);
  s32 i;

  for (i = 0; i < (p->e).pathWalker.path->nodeCount; i++) {
    s16 dx = (u32)(cs * 160) >> 16;
    s16 dz = (u32)(sn * 160) >> 16;

    if ((s16)(node->x - (p->e).mover.pos.x) * dx + dz * (s16)(node->y - (p->e).mover.pos.z) < 0) {
      if (*(s32*)node != *(s32*)(p->e).pathWalker.node) {
        (p->e).pathWalker.nodeIdx = i;
        (p->e).pathWalker.waitTimer = 0;
        (p->e).pathWalker.node = node;
        return;
      }
    } else {
      node++;
    }
  }
  Spider_PickRandomPathNode(p);
#else
  INCFUNC("asm/func/FUN_08130eec.inc");
#endif
}

void Spider_PickRandomPathNode(Spider* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// 歩きアニメのコマが変わる瞬間だけ移動の速さを返す
s32 Spider_GetMoveSpeed(Spider* p) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    return u16_ARRAY_085ad70c[anim->cmdIdx & 1];
  }
  return 0;
}

s32 FUN_081310b8(Spider* p) {
  FUN_0812f818(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  return 1;
}

s32 Spider_Update(Spider* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Spider_Destroy(Spider* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (!(p->e).unk_44c) {
    AuxShadow_Remove(&(p->e).auxShadow);
  }
  FUN_08002a58(&(p->e).mover);
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Spider_Init(Spider* p) { INCFUNC("asm/func/Spider_Init.inc"); }

void Spider_Create(void) {
  Spider* p = Malloc(sizeof(Spider));

  if (p != NULL) {
    ClearMemory(p, sizeof(Spider));
    if (Spider_Init(p) < 0) {
      Spider_Destroy(p);
      Free(p);
    }
  }
}
