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
  NavAgent navAgent;         // 0x664, Enemy.navAgent が指す
  Vec3 unk_688;              // 0x688, Enemy.unk_4a8 が指す
  u8 unk_690[1680 - 0x690];  // 0x690
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
bool8 Spider_IsCoffinInRange(Spider* p, s32 rangeX, s32 rangeZ);
bool8 FUN_08130508(Spider* p);
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

// 食らい判定, ACTOR 以外の攻撃は高さの差の半分だけずらした攻撃位置が自分の xz の箱に入るときだけ攻撃側の fn を呼んでから受ける
// 1503/1505命令, 原典は a を sb / b を r8 に置く (こちらは逆), 残りは Crow_OnHurt と同じ共通処理の残差
NON_MATCH void Spider_OnHurt(HitboxData* a, HitboxData* b, Spider* p) {
#ifdef NONMATCHING_C
  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_ACTOR)) {
    Enemy_HandleHurt(a, b, &p->e);
  } else {
    Vec3 v;
    s32 dy = (a->pos.y - b->pos.y) >> 1;

    v.x = a->pos.x - dy;
    v.z = a->pos.z - dy;
    if (b->pos.x + b->halfSize.x <= v.x || b->pos.x - b->halfSize.x >= v.x) {
      return;
    }
    if (b->pos.z + b->halfSize.z <= v.z || b->pos.z - b->halfSize.z >= v.z) {
      return;
    }
    if (a->fn != NULL) {
      a->fn(a, b, a->owner);
    }
    Enemy_HandleHurt(a, b, &p->e);
  }
#else
  INCFUNC("asm/func/Spider_OnHurt.inc");
#endif
}

void FUN_0812ea6c(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void FUN_0812ea90(Spider* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// 振り向く状態, 入ったときに4方向へ揃えて振り向きのアニメを流し, unk_1dc の向きへ 64 ずつ回す
// 325/351命令の下書き, 振り向きのアニメは Enemy_PlayAnim の展開 (anim 5, 向き 0/1, 逆再生の有無) で, (p, anim, variant, f) を取る inline にすると書きやすいが一致しない, 原典は &mover を r7 に写して角度を読み書きする, 試済: Mover* のローカル
NON_MATCH void Spider_StateTurn(Spider* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 dir;
    u32 target;
    s32 d;

    (p->e).mover.angle = Angle_FromDir4(Angle_ToDir4((p->e).mover.angle));
    dir = Angle_ToDir4((p->e).mover.angle);
    target = (p->e).unk_1dc >> 1;
    d = target - dir;
    if (dir == target || abs(d) != 2) {
      (p->e).subStateDone = 1;
      Enemy_PlayAnim(&p->e, 0);
    } else {
      switch (dir) {
        case 0: {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s;

            (p->e).playingAnim = 5;
            s = (EnemyAuxSpriteData*)(p->e).sprite;
            AuxAnim_SetAnim(&s->anim, s->animFile, 5, 0, 0);
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim == 5 && !(p->e).animForceRestart && !(s->flags & SPRFLAG_XFLIP)) {
              break;
            }
            (p->e).playingAnim = 5;
            MainSprite_SetAnim(s, &(p->e).sprite->gfx, 5, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
          break;
        }
        case 1: {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s;

            (p->e).playingAnim = 5;
            s = (EnemyAuxSpriteData*)(p->e).sprite;
            AuxAnim_SetAnim(&s->anim, s->animFile, 5, 1, 0);
          } else {
            MainSprite* s = &(p->e).sprite->s;

            if ((p->e).playingAnim == 6 && !(p->e).animForceRestart && !(s->flags & SPRFLAG_XFLIP)) {
              break;
            }
            (p->e).playingAnim = 6;
            MainSprite_SetAnim(s, &(p->e).sprite->gfx, 6, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
          break;
        }
        case 2: {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s;

            (p->e).playingAnim = 5;
            s = (EnemyAuxSpriteData*)(p->e).sprite;
            AuxAnim_SetAnim(&s->anim, s->animFile, 5, 0, ANIM_PLAY_REVERSE);
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 5;
            MainSprite_SetAnim(s, &(p->e).sprite->gfx, 5, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
          break;
        }
        case 3: {
          if ((p->e).spriteKind == 0) {
            EnemyAuxSpriteData* s;

            (p->e).playingAnim = 5;
            s = (EnemyAuxSpriteData*)(p->e).sprite;
            AuxAnim_SetAnim(&s->anim, s->animFile, 5, 1, ANIM_PLAY_REVERSE);
          } else {
            MainSprite* s = &(p->e).sprite->s;

            (p->e).playingAnim = 6;
            MainSprite_SetAnim(s, &(p->e).sprite->gfx, 6, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
          break;
        }
      }
    }
  }
  if (((EnemyAuxSpriteData*)(p->e).sprite)->anim.tick == 0) {
    u32 goal = Angle_FromDir8((p->e).unk_1dc);
    u8 a = (p->e).mover.angle;
    s32 d = a - goal;

    if (abs(d) <= 64) {
      (p->e).mover.angle = goal;
    }
    if (a < goal) {
      if (abs(d) <= 128) {
        (p->e).mover.angle = a + 64;
      } else {
        (p->e).mover.angle = a - 64;
      }
    } else if (a > goal) {
      if (abs(d) <= 128) {
        (p->e).mover.angle = a - 64;
      } else {
        (p->e).mover.angle = a + 64;
      }
    }
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/Spider_StateTurn.inc");
#endif
}

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

// 待つ状態, unk_65e フレーム過ぎたら, バリアント0で FUN_080db290 が枠を返すか 1/4 の確率で状態 (unk_5a0, 副状態7) へ, そうでなければ (unk_5a4, 副状態5) へ 60 フレーム後に移る
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
void Spider_StateDamaged(Spider* p, s32 timer) {
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

// 経路ノードで待つ副状態, 棺桶を狙っているならその判定をし, 60 フレーム過ぎたら次のノードへ向かって, 歩くか待つ状態 (FUN_0812ef50) に入るかを乱数で選ぶ
// 281/286命令, 原典は巣を張る塊と歩く塊を1つずつ持ち, バリアントごとの乱数の判定からそれぞれへ飛ぶ (歩く側は & 7 の 7 を subState2 に使い回す), こちらは三項演算子の条件で塊の入口の共有のされ方が違う, 試済: バリアントごとに塊を2つずつ書く (320命令)
NON_MATCH void FUN_0812fdb8(Spider* p) {
#ifdef NONMATCHING_C
  Spider* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    (p->e).animSpeedDiv = 1;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if (Spider_TestUnk660(q, 4)) {
    if (Spider_IsCoffinInRange(p, 64, 64)) {
      (p->e).animSpeedDiv = 1;
      Spider_PickRandomPathNode(p);
      Enemy_StepTowardPathNode(&p->e);
      q->unk_65e = 0;
      Enemy_ResetState(&p->e, 0, 0, 15);
      Enemy_EnterState(&p->e, FUN_0812ef50, ES_UNK_33);
    } else {
      FUN_08130508(p);
    }
    return;
  }
  if ((p->e).subStateTimer > 60) {
    Spider_PickRandomPathNode(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).variant == 0 ? (Random() & 3) != 0 : (Random() & 7) == 0) {
      Enemy_ResetState(&p->e, 0, 0, 15);
      Enemy_EnterState(&p->e, FUN_0812ef50, ES_UNK_33);
      q->unk_65e = (Random() & 127) + 60;
    } else {
      Enemy_ResetState(&p->e, 0, 0, 7);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0812fdb8.inc");
#endif
}

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

// プレイヤーが同じ高さで近く, 前方 45 度以内に見えていれば, 近ければ追いかけ, 遠ければ毒液を吐く状態に入って TRUE を返す
// 277/275命令, 原典は p の写しを sl に置き (フレーム 8), こちらはスタックに退避する (フレーム 0xc), 失敗は早期 return, 不可視の検査は Player_TestFlag20 で揃う, 試済: Mover* のローカル, distSq の符号
NON_MATCH bool8 FUN_08130ac4(Spider* p) {
#ifdef NONMATCHING_C
  Spider* self = p;
  Player* player;
  Vec3 d;
  u32 distSq;
  u8 angle;
  s32 a;

  if (!Spider_TestUnk660((p->e).unk_1cc, 2)) {
    if (FUN_081309f0(p)) {
      return TRUE;
    }
    if (Player_TestFlag20(gPlayerPtr[0], PFLAG20_INVISIBLE)) {
      return FALSE;
    }
  } else if (FUN_081309f0(p)) {
    return TRUE;
  }
  if (gPlayerPtr[0] == NULL) {
    return FALSE;
  }
  player = gPlayerPtr[0];
  Vec3_Delta(&d, &(p->e).mover.pos, &player->mover.pos);
  if (abs(d.y) > 255) {
    return FALSE;
  }
  distSq = d.x * d.x + d.z * d.z;
  ArcTan2_8(d.x, d.z);
  if (distSq >= (p->e).range0Sq * 2) {
    return FALSE;
  }
  angle = (p->e).mover.angle;
  Vec3_Delta(&d, &(p->e).mover.pos, &player->mover.pos);
  a = ArcTan2_8(d.x, d.z) - angle;
  if (a > 128) {
    a -= 256;
  } else if (a < -128) {
    a += 256;
  }
  if (abs(a) > 32) {
    return FALSE;
  }
  if (!(u8)Map_HasLineOfSight(&self->e.mover.pos, &player->mover.pos, 5, 0x100)) {
    return FALSE;
  }
  (p->e).playerMover = &player->mover;
  if ((s32)distSq < 0x4000) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
    FUN_08130eec(p);
    Enemy_StepTowardPathNode(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
  } else {
    Enemy_ResetState(&p->e, 0, 0, 16);
    Enemy_EnterState(&p->e, Spider_SpitVenom, ES_UNK_3);
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_08130ac4.inc");
#endif
}

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
// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
// 1709/1865命令, Crow_Init の下書きを Spider 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 Spider_Init(Spider* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  s32 height;
  u8 kind;

  p->unk_660 = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_SPIDER;
  Spider_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux;
    u8 k;

    (p->e).sprite = Malloc(sizeof(EnemyAuxSpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemyAuxSpriteData));
    aux = (EnemyAuxSpriteData*)(p->e).sprite;
    Video_GetAuxSprite(&aux->gfx, SPRITE_SPIDER);
    AuxSprite_Add(&aux->sprite, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_SPIDER);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->sprite.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemySpriteData* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).sprite = Malloc(sizeof(EnemySpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemySpriteData));
    spr = (p->e).sprite;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_SPIDER);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->s, &spr->gfx, 0, 0, 2, 2, 60, &origin);
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
    (p->e).unk_256 = GetCollisionTileIdx(&pos);
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
      (p->e).atkUnk40[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkInvincibleTime[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).unk_24c = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).unk_24c = VM_GetPC() != NULL ? VM_GetValue() : 300;
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
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? (AuxSprite*)(p->e).sprite : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).moverTile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).moverTile, 64, 64);
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
  (p->e).unk_47a = 143;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 143;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)(p->e).sprite)->gfx, (p->e).unk_47a + (p->e).variant);
  } else {
    (p->e).sprite->s.pltt = &gObjPlttData[((p->e).unk_47a + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).sprite->s.plttID = n + 220;
  }

  Spider_InitHitboxes(p);
  height = VM_GetNamedArgValue('f', 0);
  if (VM_GetNamedArgValue('T', 0) != 0) {
    p->unk_660 |= 0x10;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).unk_4a8 = &p->unk_688;
  (p->e).unk_580 = (EnemyHandler)FUN_081310b8;
  (p->e).unk_588 = (void*)Spider_GetMoveSpeed;
  (p->e).unk_590 = Spider_StateTurn;
  (p->e).unk_5a0 = FUN_0812ea6c;
  (p->e).unk_5a4 = FUN_0812ea90;
  (p->e).unk_5c0 = FUN_0812f1b4;
  (p->e).unk_5c4 = (EnemyHandler)FUN_080f62b0;
  (p->e).unk_5cc = Spider_StateDamaged;
  (p->e).unk_5d0 = Spider_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = FUN_0812f1b8;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).unk_608 = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).unk_60c = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).unk_5bc = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = NULL;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).unk_58c = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).unk_5b8 = FUN_080f624c;
  (p->e).unk_594 = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).unk_60c = (void*)PTR_ARRAY_085ad710;
  (p->e).onReset = (EnemyHandler)Spider_OnReset;
  (p->e).unk_5ac = NULL;
  (p->e).unk_5b0 = NULL;
  (p->e).unk_5b8 = FUN_0812f358;
  (p->e).unk_608 = (p->e).variant == 0 ? (void*)FUN_08130d34 : (void*)FUN_08130ac4;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_22);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).unk_19a = VM_GetNamedArgValue('D', 0);
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
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
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
    EnemyAuxSpriteData* aux = (EnemyAuxSpriteData*)(p->e).sprite;

    AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).sprite->s, &(p->e).sprite->gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  Enemy_InitHandlerTables(&p->e);
  FUN_081300d0(p);
  if (height == 0) {
    Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).unk_5a0;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
    (p->e).unk_44c = 1;
    (p->e).unk_44d = 1;
  } else {
    (p->e).heightAboveFloor = height;
    (p->e).unk_1bc = 2;
    Enemy_EnterState(&p->e, FUN_0812edf8, ES_UNK_34);
    Enemy_ResetState(&p->e, 3, 0, 0);
    (p->e).unk_44c = AuxShadow_Init(&(p->e).auxShadow, &(p->e).mover.pos, 64, 16, 96, 100, 0xA00, 1, 5, 1, 0);
    (p->e).unk_44d = 1;
    p->unk_660 |= 1;
  }
  p->unk_662 = 300;
  (p->e).unk_572 = (p->e).flags5;
  (p->e).unk_570 = (p->e).heightAboveFloor;
  (p->e).unk_55c = (p->e).flags;
  (p->e).unk_560 = (p->e).flags2;
  (p->e).unk_564 = (p->e).mover.angle;
  (p->e).unk_565 = (p->e).subState0;
  (p->e).unk_566 = (p->e).subState1;
  (p->e).unk_567 = (p->e).subState2;
  (p->e).unk_568 = (p->e).handlerState;
  (p->e).unk_56c = (p->e).state;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Spider_Update;
  (p->e).handlerDestroy = (EnemyHandler)Spider_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Spider_Init.inc");
#endif
}

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
