#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "entity_9a9f.h"
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

// バット(ENEID_BAT), ヴァンパイアバット(ENEID_VBAT)
// ヴァンパイアバット は 吸血攻撃をしてくる
// プレイヤーが変身するCバット(PLAYER_BAT)などと混同しない様に構造体名は Bat ではなく EnemyBat にした
typedef struct {
  Enemy e;
  u8 unk_654[4];              // 0x654
  u32 unk_658;                // 0x658, bit3 が立っていると移動が速くなる
  u16 unk_65c;                // 0x65C, 飛び上がるときに目指す高さ
  u8 biteInterval;            // 0x65E, 掴んでいる間に攻撃判定を出すフレーム間隔
  u8 unk_65f;                 // 0x65F
  u8 escapeMash;              // 0x660, 振りほどくのに要る連打数
  u8 unk_661;                 // 0x661, 歩きアニメを流し直すかを決めるための前のフレームの mover.angle
  s16 unk_662;                // 0x662
  u16 curveT;                 // 0x664, curveStart から curveEnd への曲線の進み具合, 128 ごとに移動の速さの段階が1つ上がる (7 段階まで)
  u8 unk_666;                 // 0x666
  s8 curveBendDir;            // 0x667, curveBend を増やす向き, 1 か -1
  s16 curveBend;              // 0x668, 曲線のふくらみ, -320〜320 を往復する
  u8 mashCount;               // 0x66A, 掴んでからの連打数
  u8 mashBase;                // 0x66B, 掴んだときの Player.mashCount
  u16 unk_66c;                // 0x66C, 0 でなければ毎フレーム減り, 0 になったらプレイヤーへの曲線移動を始める
  u16 unk_66e;                // 0x66E, 前のフレームの floorY
  u8 unk_670;                 // 0x670, 弾かれて逃げる向き, 乱数で決める
  u8 unk_671[0x674 - 0x671];  // 0x671
  NavAgent navAgent;          // 0x674, Enemy.navAgent が指す
  Vec3 unk_698;               // 0x698, Enemy.unk_4a8 が指す
  WorldPos curveStart;        // 0x6A0, 曲線の始点
  Vec3 curveEnd;              // 0x6A8, 曲線の終点
  Vec3 unk_6b0;               // 0x6B0, 曲線移動を始めるときに 0 に戻す
  WorldPos homePos;           // 0x6B8, 復帰したときに戻る位置
  u8 unk_6c0[1728 - 0x6C0];   // 0x6C0
} EnemyBat;
static_assert(sizeof(EnemyBat) == 1728);

static inline bool8 EnemyBat_TestUnk658(EnemyBat* p, u32 bit) {
  if (p->unk_658 & bit) return TRUE;
  return FALSE;
}

struct Entity081fa164Elem* Entity081fa164_SpawnEx(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority);
void FUN_08140dd0(EnemyBat* p);
void EnemyBat_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip);
void FUN_08140904(EnemyBat* p);
void EnemyBat_BeginCurveMove(EnemyBat* p, Vec3* pos);
void EnemyBat_UpdateCurveBend(EnemyBat* p);
void HUD_ShowEnemyGauge(s32 param_1, s32 param_2, u16 param_3, u16 param_4, s32 param_5);
u8 EnemyBat_StepCurve(EnemyBat* p);
void EnemyBat_PickRandomPathNode(EnemyBat* p);
void FUN_08140c14(EnemyBat* p);
void FUN_0813f9a8(EnemyBat*);
void FUN_0813fbf8(EnemyBat*);
void FUN_0813fc9c(EnemyBat*);
void FUN_0813fd24(EnemyBat*);
void FUN_0813fe34(EnemyBat*);
void FUN_08140eb0(EnemyBat*);
void FUN_081410cc(EnemyBat*);

void (*const PTR_ARRAY_085ad7d0[5])(EnemyBat*) = {
    FUN_0813fc9c,
    FUN_0813fbf8,
    FUN_0813f9a8,
    FUN_0813fd24,
    FUN_0813fe34,
};  // 0x085AD7D0

const u32 u32_ARRAY_085ad7e4[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085AD7E4

void (*const PTR_ARRAY_085ad804[2])(EnemyBat*) = {
    FUN_08140eb0,
    FUN_081410cc,
};  // 0x085AD804

void FUN_08140278(EnemyBat*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad80c[7])(EnemyBat*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08140278,
};  // 0x085AD80C

// 当てたときの処理, 回復するバリアントなら与えたダメージぶん体力を戻してゲージと数字を出し, 攻撃判定を外して離れる副状態へ移る
// 286/290命令, 表示判定は原典では bool を返す inline (通信中なら gEntity9A9F の playerIdx で unk_4a0 を見て case ごとに 0 を返す形) で, playerIdx は solar.c の Entity9A9F_GetPlayerIdx の形にすると -1 の作り方まで揃う, 残差は case ごとの 0 を返す塊が原典では畳まれず unk_4a0 を読み直す点と, CpuFill32 の v のアドレスを r6 に置く点
NON_MATCH void EnemyBat_OnHit(HitboxData* a, HitboxData* b, EnemyBat* p) {
#ifdef NONMATCHING_C
  if (b->ignoreMask != HIM_0) {
    return;
  }
  if (Enemy_IsDead(&p->e)) {
    return;
  }
  Enemy_SetHitTarget(&p->e, b);
  Hitbox_ApplyDamage(a, b);
  if (((p->e).variant == 1 || (u16)((p->e).variant - 12) <= 3) && b->damage != 0) {
    if ((p->e).hp + b->damage > (p->e).maxHp) {
      (p->e).hurtbox.damage = (p->e).maxHp - (p->e).hp;
      (p->e).hp = (p->e).maxHp;
    } else {
      (p->e).hurtbox.damage = b->damage;
      (p->e).hp += b->damage;
    }
    (p->e).unk_48a = (p->e).hurtbox.damage;
    if ((p->e).unk_48a != 0) {
      bool8 show = TRUE;

      if (IsLinkPlay() && !((p->e).unk_4a0 & 0x20) && (p->e).unk_4a0 != 0) {
        switch (gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1) {
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
          CreateDamageNumber(&(p->e).hurtbox, (p->e).unk_48a, 1, &(p->e).mover.pos, &v, 1);
        }
      }
    }
  }
  (p->e).atkHitbox.flags |= HBFLAG_HIDDEN;
  ((EnemyBat*)(p->e).unk_1cc)->unk_658 &= ~8;
  if (!EnemyBat_TestUnk658((p->e).unk_1cc, 4)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 1);
    ((EnemyBat*)(p->e).unk_1cc)->unk_658 |= 4;
  }
#else
  INCFUNC("asm/func/EnemyBat_OnHit.inc");
#endif
}

// 食らい判定, 共通処理のあとノックバックを 0〜15 減らし 20 を下限にして, 速く動く印を落とす
// 803/808命令, Crow_OnHurt と同じ残差 (ノックバックの種別判定の配置, p->angle の格納先の計算位置, 末尾の乱数の読み順)
NON_MATCH void EnemyBat_OnHurt(HitboxData* a, HitboxData* b, EnemyBat* p) {
#ifdef NONMATCHING_C
  s32 knockback;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_UNK_11)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  knockback = b->knockbackPower - (Random() & 15);
  b->knockbackPower = knockback < 20 ? 20 : knockback;
  ((EnemyBat*)(p->e).unk_1cc)->unk_658 &= ~8;
#else
  INCFUNC("asm/func/EnemyBat_OnHurt.inc");
#endif
}

// プレイヤーに取り付いて一定間隔で攻撃し, 連打で振りほどかれたら終わる
// 104/109 命令, 連打数の差分が Curoro_HoldPlayer と同じ残差 (base - 256 を作ってから引く形にならない) を持ち, 定数オフセットのレジスタも違う
NON_MATCH void EnemyBat_HoldPlayer(EnemyBat* p) {
#ifdef NONMATCHING_C
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->mashBase = gPlayerPtr[0]->mashCount;
    Enemy_PlayAnim(&p->e, 1);
    q->unk_661 = (p->e).mover.angle;
  }
  if (Mod((p->e).stateTimer, q->biteInterval) == 0) {
    (p->e).atkHitbox.flags &= ~HBFLAG_HIDDEN;
  }
  if ((p->e).variant > 11) {
    FUN_08140dd0(p);
  }
  {
    s32 base = q->mashBase;
    s32 count = gPlayerPtr[0]->mashCount;

    if (count < base) {
      q->mashCount = count - (base - 256);
    } else {
      q->mashCount = count - base;
    }
  }
  if (q->mashCount > q->escapeMash) {
    (p->e).subStateDone = 1;
  } else if (q->unk_661 != (p->e).mover.angle) {
    Enemy_PlayAnim(&p->e, 1);
    q->unk_661 = (p->e).mover.angle;
  } else {
    (p->e).animForceRestart = FALSE;
  }
#else
  INCFUNC("asm/func/EnemyBat_HoldPlayer.inc");
#endif
}

// 向きが変わったときだけ歩きアニメを流し直す
void FUN_0813f180(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 1);
    q->unk_661 = (p->e).mover.angle;
  } else if (q->unk_661 != (p->e).mover.angle) {
    Enemy_PlayAnim(&p->e, 1);
    q->unk_661 = (p->e).mover.angle;
  } else {
    (p->e).animForceRestart = FALSE;
  }
}

void FUN_0813f1f0(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 1);
    q->unk_661 = (p->e).mover.angle;
  } else {
    FUN_08140dd0(p);
    if (q->unk_661 != (p->e).mover.angle) {
      Enemy_PlayAnim(&p->e, 1);
      q->unk_661 = (p->e).mover.angle;
    } else {
      (p->e).animForceRestart = FALSE;
    }
  }
}

void FUN_0813f268(EnemyBat* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimWithVariant(&p->e, 15, 0);
  }
  (p->e).animForceRestart = FALSE;
}

void FUN_0813f2a8(EnemyBat* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimWithVariant(&p->e, 17, 0);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
    ParticleShadow_Show(&(p->e).shadow);
  }
}

void FUN_0813f2fc(EnemyBat* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// 向きに合わせて animTable[11] のアニメを流し, 30 フレーム未満は flags4 の印を立て, 60 フレームで副状態を終える
// Enemy_PlayAnim の展開, 再生部分を (p, u32 anim, variant, f) を取る static inline にして変化なしで return する形にすると残差は MainSprite_SetAnim をまたいで定数 4 を r8 に置く点だけ (Enemy_PlayAnim と同じ壁), 試済: 反転フラグの直接操作
NON_MATCH void FUN_0813f320(EnemyBat* p, s32 timer) {
#ifdef NONMATCHING_C
  s32 dir;
  s32 flip;
  u32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  EnemyBat_GetDirAndFlip((p->e).mover.angle, &dir, &flip);
  anim = (p->e).animTable[11].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* s;

    (p->e).playingAnim = anim;
    s = (EnemyAuxSpriteData*)(p->e).sprite;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, dir, flip);
    (p->e).animForceRestart = FALSE;
  } else {
    MainSprite* s = &(p->e).sprite->s;
    s32 a = anim + dir;

    if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flip == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, (flip & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (flip & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = FALSE;
    }
  }
  if (timer < 30) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (timer > 59) {
    (p->e).subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_0813f320.inc");
#endif
}

// unk_20c へ滑り終えたら, 追いかけ中ならプレイヤーへの曲線移動へ, そうでなければ向き直って状態10へ移る
void FUN_0813f44c(EnemyBat* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  if (Enemy_StepSlide(&p->e)) {
    FUN_08140904(p);
    if ((p->e).unk_24e != 0) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      (p->e).unk_24e = (p->e).unk_24c;
      EnemyBat_BeginCurveMove(p, &gPlayerPtr[0]->mover.pos);
      Enemy_ResetState(&p->e, 0, 2, 0);
    } else {
      Enemy_EnterState(&p->e, FUN_0813f320, ES_UNK_10);
      Enemy_ResetState(&p->e, 0, 1, 1);
      (p->e).mover.angle = (p->e).unk_1fc;
      (p->e).animSpeedDiv = 1;
    }
  }
}

// 被弾して後ろへ滑る状態, 滑り終えたら, 1度目は副状態3へ, 2度目からはプレイヤーへの曲線移動へ移る
void EnemyBat_StateDamaged(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_PlayAnim(&p->e, 3);
    Hitbox_Hide(&(p->e).atkHitbox);
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    q->unk_666 = 0;
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      EnemyBat_BeginCurveMove(p, &gPlayerPtr[0]->mover.pos);
      Enemy_ResetState(&p->e, 0, 2, 0);
      FUN_08140904(p);
    } else {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      Enemy_ResetState(&p->e, 0, 0, 3);
      FUN_08140904(p);
    }
  }
}

// 倒されたときの状態, 点滅しながら消えたら倒されたスクリプトを呼び図鑑に載せて止まる
void EnemyBat_StateDying(EnemyBat* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
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
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    (p->e).unk_192 = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
}

// 曲線に沿って経路の目的地へ飛び, 曲線の終点に着いたら勢いを残して乱数の経路ノードへ次の曲線を引く
void FUN_0813f9a8(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Vec3_Clear(&q->unk_6b0);
    q->curveBendDir = 1;
  }
  speed = (p->e).unk_588(&p->e);
  EnemyBat_UpdateCurveBend(p);
  if (Enemy_StepToDest(&p->e, speed) && EnemyBat_StepCurve(p)) {
    WorldPos pos;
    WorldPos* dst;
    PathWalker* walker;

    Vec3_SetPolar(&q->unk_6b0, (p->e).mover.angle, speed);
    EnemyBat_PickRandomPathNode(p);
    dst = &pos;
    walker = &(p->e).pathWalker;
    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    EnemyBat_BeginCurveMove(p, &pos);
  }
  (p->e).subStateTimer++;
}

void FUN_0813fbf8(EnemyBat* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).unk_1fc;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    Enemy_ResetState(&p->e, 0, 2, 0);
  } else {
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

void FUN_0813fc9c(EnemyBat* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0813f268, ES_UNK_33);
    ParticleShadow_Hide(&(p->e).shadow);
  }
  if (!(p->e).unk_608(&p->e)) {
    (p->e).subStateTimer++;
  }
}

void FUN_0813fd24(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0813f2a8, ES_UNK_34);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 4);
    (p->e).jumpVel.y = 10;
  }
  if ((p->e).subStateDone && (p->e).heightAboveFloor < q->unk_65c - 20) {
    FUN_08140c14(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// 乱数の向きへ弾かれて滑り, 止まったらプレイヤーへの曲線移動を始める
void FUN_0813fe34(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Vec3_Clear(&q->unk_6b0);
    q->unk_670 = Random();
    (p->e).jumpVel.x = FixToInt(7, SIN(q->unk_670));
    (p->e).jumpVel.z = FixToInt(7, COS(q->unk_670));
  }
  if ((p->e).subStateTimer < 6) {
    (p->e).jumpVel.x = FixToInt(7, SIN(q->unk_670));
    (p->e).jumpVel.z = FixToInt(7, COS(q->unk_670));
  }
  {
    Vec3* vel = &(p->e).jumpVel;

    if (vel->x * vel->x + vel->z * vel->z == 0) {
      FUN_08140904(p);
      Vec3_Clear(vel);
      EnemyBat_BeginCurveMove(p, &gPlayerPtr[0]->mover.pos);
      Enemy_ResetState(&p->e, 0, 2, 0);
    }
  }
  (p->e).subStateTimer++;
}

void FUN_08140014(EnemyBat* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad7d0; }

// 復帰時に作業値を消して homePos へ戻し, 床の高さを取り直して待機アニメを流して1コマ送る
void EnemyBat_OnReset(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_65f = 0;
  q->curveT = 0;
  q->unk_666 = 0;
  q->curveBendDir = 1;
  q->curveBend = 0;
  q->mashCount = 0;
  q->mashBase = 0;
  q->unk_658 = 0;
  (p->e).mover.pos = q->homePos;
  (p->e).unk_256 = GetCollisionTileIdx(&q->homePos);
  (p->e).floorY = TileHeightAtIndex((p->e).unk_256, &q->homePos);
  (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
  (p->e).mover.pos.y = (p->e).floorY;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->unk_6b0);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
}

void FUN_08140278(EnemyBat* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && gPlayerPtr[0] != NULL) {
    EnemyBat* q = (p->e).unk_1cc;

    if (EnemyBat_TestUnk658(q, 2)) {
      CLEAR_FLAGS(q->unk_658, 2);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      Enemy_ResetState(&p->e, 0, 0, 3);
    }
  }
}

// 床から 260 ほどの高さを保って浮き, sin で上下に揺らす, 床の段差ぶんは高さを補う
void EnemyBat_UpdateHover(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (Enemy_IsDead(&p->e) == 0) {
    if (EnemyBat_TestUnk658(q, 2)) {
      (p->e).mover.pos.y = q->unk_662 + (p->e).heightAboveFloor;
    } else {
      s32 d;
      s32 y;

      if ((p->e).heightAboveFloor <= 259) {
        if (EnemyBat_TestUnk658(q, 1)) {
          (p->e).mover.pos.y = (p->e).floorY;
          return;
        }
        (p->e).heightAboveFloor += FixToInt(9, SIN(q->unk_666));
        if (q->unk_666 < 64) {
          q->unk_666++;
        }
      }
      d = (p->e).floorY;
      y = (p->e).mover.pos.y - 260;
      d -= y;
      if (abs(d) > 16) {
        if (d < 0) {
          (p->e).heightAboveFloor -= 2;
        } else {
          (p->e).heightAboveFloor += 2;
        }
      }
      if ((p->e).floorY != q->unk_66e) {
        (p->e).heightAboveFloor -= (p->e).floorY - q->unk_66e;
      }
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
      {
        AuxSprite* sprite = &((EnemyAuxSpriteData*)(p->e).sprite)->sprite;

        sprite->pos.y -= FixToInt(5, SIN(q->unk_666));
      }
      if (q->unk_666 > 64) {
        q->unk_666 = 0;
      } else {
        q->unk_666 += 8;
      }
      q->unk_66e = (p->e).floorY;
    }
  }
}

void EnemyBat_UpdateCurveBend(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  if (q->curveBend > 320) {
    q->curveBendDir = -1;
    q->curveBend = 320;
  } else if (q->curveBend < -320) {
    q->curveBendDir = 1;
    q->curveBend = -320;
  }
  q->curveBend += q->curveBendDir * 12;
}

void EnemyBat_PickRandomPathNode(EnemyBat* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

void EnemyBat_InitHitboxes(EnemyBat* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 32, 82, 32);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, EnemyBat_OnHurt, p);
  VEC3_SET(hitSize, 32, 42, 32);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, EnemyBat_OnHit, 0, p);
}

// curveT が大きいほど速く, unk_658 の bit3 が立っていればさらに速い
s32 EnemyBat_GetMoveSpeed(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;
  s32 v = FixToInt(7, q->curveT);
  s32 i;

  if (v < 0) {
    v = -v;
  }
  i = v;
  if (i > 7) {
    i = 7;
  }
  if (EnemyBat_TestUnk658(q, 8)) {
    return u32_ARRAY_085ad7e4[i] + 6;
  }
  return u32_ARRAY_085ad7e4[i];
}

void EnemyBat_StartCurve(EnemyBat* p, Vec3* pos) {
  EnemyBat* q = (p->e).unk_1cc;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
  q->curveT = 0;
}

// curveStart から curveEnd への曲線上の curveT の位置を経路の目的地に置き, curveT を乱数ぶん進める, 終点に着いたら TRUE
// 220/223命令, Curoro_StepCurve と同じ壁 (原典はフレーム 0x34 で start/end/d/v を置き k などを退避, こちらは 0x28)
NON_MATCH u8 EnemyBat_StepCurve(EnemyBat* p) {
#ifdef NONMATCHING_C
  EnemyBat* q = (p->e).unk_1cc;
  WorldPos start, end;
  Vec3 d, v;
  Vec3* dest;
  s32 t, k, t2, t3, n;

  start = q->curveStart;
  start.y = 0;
  end = q->curveEnd;
  end.y = 0;
  t = q->curveT;
  k = q->curveBend;
  dest = &(p->e).navAgent->dest;
  Vec3_Diff(&d, &end, &start);
  Vec3_Clear(&v);
  t2 = t * t;
  if (t2 >= 0) {
    t2 >>= 10;
  } else {
    t2 = -(-t2 >> 10);
  }
  t3 = t2 * t;
  if (t3 >= 0) {
    t3 >>= 10;
  } else {
    t3 = -(-t3 >> 10);
  }
  k *= t3 - 2 * t2 + t;
  n = v.x * (2 * t3 - 3 * t2 + 1) + d.x * (3 * t2 - 2 * t3) + k;
  if (n >= 0) {
    n >>= 10;
  } else {
    n = -(-n >> 10);
  }
  dest->x = start.x + n;
  n = v.y * (2 * t3 - 3 * t2 + 1) + d.y * (3 * t2 - 2 * t3) + k;
  if (n >= 0) {
    n >>= 10;
  } else {
    n = -(-n >> 10);
  }
  dest->y = start.y + n;
  n = v.z * (2 * t3 - 3 * t2 + 1) + d.z * (3 * t2 - 2 * t3) + k;
  if (n >= 0) {
    n >>= 10;
  } else {
    n = -(-n >> 10);
  }
  dest->z = start.z + n;
  if (q->curveT < 1024) {
    q->curveT += (u8)Random() + 256;
    if (q->curveT > 1024) {
      q->curveT = 1024;
    }
    return FALSE;
  }
  q->curveT = 0;
  return TRUE;
#else
  INCFUNC("asm/func/EnemyBat_StepCurve.inc");
#endif
}

void EnemyBat_InitAnims(EnemyBat* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 3, 1, 0);
  Enemy_SetAnimEntry(&p->e, 15, 2, 0);
  Enemy_SetAnimEntry(&p->e, 16, 3, 0);
  Enemy_SetAnimEntry(&p->e, 17, 4, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 10, 1, 0);
}

// 残差は q と flags2 のアドレスの r1/r2 入れ替えのみ, 試済: q のローカル有無, Enemy_SetFlag2
NON_MATCH void FUN_08140904(EnemyBat* p) {
#ifdef NONMATCHING_C
  EnemyBat* q = (p->e).unk_1cc;

  Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_20);
  q->unk_658 &= ~7;
  Hitbox_ClearFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
#else
  INCFUNC("asm/func/FUN_08140904.inc");
#endif
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void EnemyBat_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *outDir = 8 - dir;
    *outFlip = 1;
  } else {
    *outDir = dir;
    *outFlip = 0;
  }
}

void EnemyBat_BeginCurveMove(EnemyBat* p, Vec3* pos) {
  EnemyBat* q = (p->e).unk_1cc;
  Vec3 diff;

  EnemyBat_StartCurve(p, pos);
  EnemyBat_StepCurve(p);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&diff, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(diff.x, diff.z);
  Vec3_Clear(&q->unk_6b0);
}

void FUN_08140a10(EnemyBat* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  (p->e).unk_24e = 0;
}

void FUN_08140a48(EnemyBat* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).unk_24e = 0;
    return;
  }
  if ((p->e).unk_24e != 0) {
    (p->e).unk_24e--;
    return;
  }
  EnemyBat_PickRandomPathNode(p);
  {
    WorldPos pos;
    WorldPos* dst = &pos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    EnemyBat_BeginCurveMove(p, &pos);
    FUN_08140a10(p);
  }
}

// 残差は sp のコピー (mov rN, sp) の位置2か所のみ, Curoro_BounceOffWall と同じ, 試済: Vec3_Sum の引数順, dst/cur のポインタ, 直書き
NON_MATCH void EnemyBat_BounceOffWall(EnemyBat* p) {
#ifdef NONMATCHING_C
  WorldPos pos;
  WorldPos* cur = &(p->e).mover.pos;
  s32 height;

  Vec3_Sum(&pos, &(p->e).jumpVel, cur);
  height = TileHeightAt(&pos);
  if ((p->e).floorY < height) {
    (p->e).jumpVel.x *= -1;
    (p->e).jumpVel.z *= -1;
    (p->e).mover.delta.x = 0;
    (p->e).mover.delta.z = 0;
  }
#else
  INCFUNC("asm/func/EnemyBat_BounceOffWall.inc");
#endif
}

void FUN_08140c14(EnemyBat* p) {
  EnemyBat* q = (p->e).unk_1cc;

  q->unk_666 = 0;
  Vec3_Clear(&(p->e).jumpVel);
  CLEAR_FLAGS(q->unk_658, 7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  Enemy_ResetState(&p->e, 0, 2, 0);
  ParticleShadow_Show(&(p->e).shadow);
  EnemyBat_BeginCurveMove(p, &gPlayerPtr[0]->mover.pos);
}

// 的を探してよい番を使い切り, 高さが近いプレイヤーが索敵範囲に入っていれば攻撃の要求を立てる
bool8 FUN_08140cd4(EnemyBat* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy;

    (p->e).flags &= ~ENEFLAG_UNK_3;
    dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);
    if (dy <= 512 && (p->e).unk_1e4 < (p->e).range0Sq) {
      goto found;
    }
  }
  return FALSE;

found:
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
}

void FUN_08140d48(EnemyBat* p) {
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  if (!Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_8) && EnemyBat_TestUnk658((p->e).unk_1cc, 2)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ResetState(&p->e, 0, 0, 3);
  }
}

// 6フレームごとに, 向きの反対側の 64 度の範囲へ粒を1つ飛ばす
// 残差は95/94命令, 角度の -32 が乱数側に畳まれ, table が r6 でなく ip に載る, 試済: base を s32 で計算, base + r - 32, r + (base - 32)
NON_MATCH void FUN_08140dd0(EnemyBat* p) {
#ifdef NONMATCHING_C
  if (Mod((p->e).unk_1ca, 6) == 0) {
    Vec3 vel;
    u32 quad = (u32)(((p->e).mover.angle + 0x20) & 0xFF) >> 6;
    s8 base = (quad + 2) << 6;
    u16* table = gRandomTable;
    u8 angle = base - 32 + (_Random(table) & 63);
    s32 speed = (_Random(table) & 7) + 1;

    Vec3_SetPolar(&vel, angle, speed);
    Entity081fa164_SpawnEx(&(p->e).mover.pos, &vel, 40, 2, 1);
  }
#else
  INCFUNC("asm/func/FUN_08140dd0.inc");
#endif
}

s32 FUN_08140ea0(EnemyBat* p) {
  EnemyBat_UpdateHover(p);
  return 1;
}

s32 FUN_08140eac(EnemyBat* p) { return 1; }

// プレイヤーへの曲線に沿って飛び, 曲線の終点に着いたらプレイヤーの近くの乱数の位置へ次の曲線を引く
// 229/229命令, 残差は乱数の表と ldrsh のゼロ添字に使う一時レジスタ番号 (r1/r2 と原典 r2/r3) だけ, 試済: 乱数の受けの型, pos の初期化子, table ローカル
NON_MATCH void FUN_08140eb0(EnemyBat* p) {
#ifdef NONMATCHING_C
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    EnemyBat* q = (p->e).unk_1cc;

    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Vec3_Clear(&q->unk_6b0);
    q->curveBendDir = 1;
  }
  EnemyBat_UpdateCurveBend(p);
  speed = (p->e).unk_588(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    if (EnemyBat_StepCurve(p)) {
      WorldPos pos;
      u8 r = Random();

      pos = gPlayerPtr[0]->mover.pos;
      pos.x += FixToInt(4, SIN(r));
      pos.z += FixToInt(4, COS(r));
      EnemyBat_BeginCurveMove(p, &pos);
      CLEAR_FLAGS(((EnemyBat*)(p->e).unk_1cc)->unk_658, 8);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08140eb0.inc");
#endif
}

// プレイヤーを掴んで周りを曲線で飛び回る副状態, 離れすぎたら少し待ってから曲線移動をやり直す
// 366/366命令, 残差は FUN_08140eb0 と同じく乱数の表と ldrsh のゼロ添字の一時レジスタ番号 (r1/r3 と原典 r3/r1) だけ, 待ちの間は曲線移動を飛ばし, 離れすぎたら return する形で構造は揃う, 試済: SIN の添字のマスクを外す
NON_MATCH void FUN_081410cc(EnemyBat* p) {
#ifdef NONMATCHING_C
  EnemyBat* q = (p->e).unk_1cc;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    WorldPos pos;
    u8 r;

    Enemy_EnterState(&p->e, EnemyBat_HoldPlayer, ES_UNK_35);
    Vec3_Clear(&q->unk_6b0);
    q->curveBendDir = 1;
    q->unk_66c = 0;
    r = Random();
    pos = gPlayerPtr[0]->mover.pos;
    pos.x += FixToInt(3, SIN(r));
    pos.z += FixToInt(3, COS(r));
    EnemyBat_StartCurve(p, &pos);
    EnemyBat_StepCurve(p);
    CLEAR_FLAGS(q->unk_658, 8);
  }
  if (q->unk_66c != 0) {
    if (--q->unk_66c == 0) {
      EnemyBat_BeginCurveMove(p, &gPlayerPtr[0]->mover.pos);
      SET_FLAGS(q->unk_658, 8);
    }
  } else {
    EnemyBat_UpdateCurveBend(p);
    speed = (p->e).unk_588(&p->e);
    if (Enemy_StepToDest(&p->e, speed) && EnemyBat_StepCurve(p)) {
      WorldPos pos;
      u8 r;

      r = Random();
      pos = gPlayerPtr[0]->mover.pos;
      pos.x += FixToInt(3, SIN(r));
      pos.z += FixToInt(3, COS(r));
      EnemyBat_StartCurve(p, &pos);
      EnemyBat_StepCurve(p);
    }
    if ((p->e).unk_1e4 > 65000) {
      FUN_08140904(p);
      (p->e).mover.angle = (p->e).unk_1fc;
      q->unk_66c = 30;
      return;
    }
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 4);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_081410cc.inc");
#endif
}

void FUN_08141448(EnemyBat* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad804; }

s32 FUN_0814145c(EnemyBat* p) {
  FUN_08140ea0(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  return 1;
}

s32 EnemyBat_Update(EnemyBat* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 EnemyBat_Destroy(EnemyBat* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).unk_44c) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).unk_44c = 1;
  }
  if (!(p->e).unk_44d) {
    Eff082473e0Emitter_Destroy(&(p->e).emitter);
    (p->e).unk_44d = 1;
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

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
// 1813/1982命令, Crow_Init の下書きを Bat 向けに直したもの (呼び出し列は一致), 原典はハンドラ表の代入の塊を variant で2つに展開し, Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 EnemyBat_Init(EnemyBat* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->unk_658 = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_BAT;
  EnemyBat_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux;
    u8 k;

    (p->e).sprite = Malloc(sizeof(EnemyAuxSpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemyAuxSpriteData));
    aux = (EnemyAuxSpriteData*)(p->e).sprite;
    Video_GetAuxSprite(&aux->gfx, SPRITE_BAT);
    AuxSprite_Add(&aux->sprite, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_BAT);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_BAT);
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
  if (!VM_SeekToNamedArg('g')) {
    p->biteInterval = 60;
    p->escapeMash = 3;
  } else {
    p->biteInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->escapeMash = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).mover.angle = VM_GetNamedArgValue('E', 0) != 0 ? 64 : 0;
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->homePos = (p->e).mover.pos;
    if ((p->e).mover.angle == 0) {
      p->homePos.x += 0x80;
    } else {
      p->homePos.z += 0x80;
    }
    (p->e).unk_256 = GetCollisionTileIdx(&p->homePos);
    (p->e).floorY = TileHeightAt(&p->homePos);
    (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
    p->unk_65c = (p->e).heightAboveFloor;
    (p->e).mover.pos.y = (p->e).floorY;
    p->unk_662 = (p->e).floorY;
    p->unk_66e = (p->e).floorY;
  }
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).unk_47a = 610;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 612;
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

  EnemyBat_InitHitboxes(p);
  if ((p->e).variant < 12) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
    (p->e).navAgent = &p->navAgent;
    (p->e).unk_4a8 = &p->unk_698;
    (p->e).unk_580 = (EnemyHandler)FUN_0814145c;
    (p->e).unk_588 = (void*)EnemyBat_GetMoveSpeed;
    (p->e).unk_590 = NULL;
    (p->e).unk_5a0 = FUN_0813f180;
    (p->e).unk_5a4 = FUN_0813f2fc;
    (p->e).unk_5c0 = NULL;
    (p->e).unk_5c4 = (EnemyHandler)FUN_080f62b0;
    (p->e).unk_5cc = EnemyBat_StateDamaged;
    (p->e).unk_5d0 = EnemyBat_StateDying;
    (p->e).unk_5d4 = FUN_080f44f4;
    (p->e).unk_5dc = FUN_080f410c;
    (p->e).unk_5c8 = NULL;
    (p->e).unk_584 = NULL;
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
    (p->e).navAgent = &p->navAgent;
    (p->e).unk_4a8 = &p->unk_698;
    (p->e).unk_580 = (EnemyHandler)FUN_0814145c;
    (p->e).unk_588 = (void*)EnemyBat_GetMoveSpeed;
    (p->e).unk_590 = NULL;
    (p->e).unk_5a0 = FUN_0813f1f0;
    (p->e).unk_5a4 = FUN_0813f2fc;
    (p->e).unk_5c0 = NULL;
    (p->e).unk_5c4 = (EnemyHandler)FUN_080f62b0;
    (p->e).unk_5cc = EnemyBat_StateDamaged;
    (p->e).unk_5d0 = EnemyBat_StateDying;
    (p->e).unk_5d4 = FUN_080f44f4;
    (p->e).unk_5dc = FUN_080f410c;
    (p->e).unk_5c8 = NULL;
    (p->e).unk_584 = NULL;
  }
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
  (p->e).unk_60c = (void*)PTR_ARRAY_085ad80c;
  (p->e).onReset = (EnemyHandler)EnemyBat_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).unk_5ac = (EnemyHandler)FUN_08140d48;
  (p->e).unk_5b0 = NULL;
  (p->e).unk_608 = (void*)FUN_08140cd4;
  (p->e).unk_58c = (void*)FUN_080f8400;
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10 | ENEFLAG2_UNK_20 | ENEFLAG2_UNK_25);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5 | ENEFLAG5_UNK_6);
  Enemy_InitShadowAndEmitter(&p->e);

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
  FUN_08140014(p);
  FUN_08141448(p);
  (p->e).unk_1bc = 2;
  ((EnemyAuxSpriteData*)(p->e).sprite)->sprite.priority = 1;
  if (VM_GetNamedArgValue('T', 0) == 0) {
    FUN_08140c14(p);
  } else {
    p->unk_658 |= 2;
    ParticleShadow_Hide(&(p->e).shadow);
  }
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
  (p->e).handlerUpdate = (EnemyHandler)EnemyBat_Update;
  (p->e).handlerDestroy = (EnemyHandler)EnemyBat_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/EnemyBat_Init.inc");
#endif
}

void EnemyBat_Create(void) {
  EnemyBat* p = Malloc(sizeof(EnemyBat));

  if (p != NULL) {
    ClearMemory(p, sizeof(EnemyBat));
    if (EnemyBat_Init(p) < 0) {
      EnemyBat_Destroy(p);
      Free(p);
    }
  }
}
