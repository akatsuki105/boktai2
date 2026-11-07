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
  u8 unk_66c[2];              // 0x66C
  u16 unk_66e;                // 0x66E, 前のフレームの floorY
  u8 unk_670[0x6A0 - 0x670];  // 0x670
  WorldPos curveStart;        // 0x6A0, 曲線の始点
  Vec3 curveEnd;              // 0x6A8, 曲線の終点
  Vec3 unk_6b0;               // 0x6B0, 曲線移動を始めるときに 0 に戻す
  u8 unk_6b8[1728 - 0x6B8];   // 0x6B8
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

NAKED void EnemyBat_OnHit(HitboxData* a, HitboxData* b, EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnHit.inc"); }

NAKED void EnemyBat_OnHurt(HitboxData* a, HitboxData* b, EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnHurt.inc"); }

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

NAKED void FUN_0813f5fc(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f5fc.inc"); }

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

NAKED void FUN_0813f9a8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f9a8.inc"); }

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

NAKED void FUN_0813fe34(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fe34.inc"); }

void FUN_08140014(EnemyBat* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad7d0; }

NAKED void EnemyBat_OnReset(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnReset.inc"); }

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

NAKED u8 FUN_081406b8(EnemyBat* p) { INCFUNC("asm/func/FUN_081406b8.inc"); }

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
  FUN_081406b8(p);
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

NAKED void FUN_08140eb0(EnemyBat* p) { INCFUNC("asm/func/FUN_08140eb0.inc"); }

NAKED void FUN_081410cc(EnemyBat* p) { INCFUNC("asm/func/FUN_081410cc.inc"); }

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
NAKED s32 EnemyBat_Init(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_Init.inc"); }

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
