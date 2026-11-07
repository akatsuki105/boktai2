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
  u8 unk_65c[5];              // 0x65C
  u8 unk_661;                 // 0x661, 歩きアニメを流し直すかを決めるための前のフレームの mover.angle
  u8 unk_662[2];              // 0x662
  u16 curveT;                 // 0x664, curveStart から curveEnd への曲線の進み具合, 128 ごとに移動の速さの段階が1つ上がる (7 段階まで)
  u8 unk_666;                 // 0x666
  s8 curveBendDir;            // 0x667, curveBend を増やす向き, 1 か -1
  s16 curveBend;              // 0x668, 曲線のふくらみ, -320〜320 を往復する
  u8 unk_66a[0x6A0 - 0x66A];  // 0x66A
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

void FUN_08140dd0(EnemyBat* p);
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

NAKED void FUN_0813f06c(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f06c.inc"); }

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

NAKED void FUN_0813f320(EnemyBat* p, s32 timer) { INCFUNC("asm/func/FUN_0813f320.inc"); }

NAKED void FUN_0813f44c(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f44c.inc"); }

NAKED void FUN_0813f5fc(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f5fc.inc"); }

NAKED void FUN_0813f7d4(EnemyBat* p, s32 timer) { INCFUNC("asm/func/FUN_0813f7d4.inc"); }

NAKED void FUN_0813f9a8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813f9a8.inc"); }

NAKED void FUN_0813fbf8(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fbf8.inc"); }

void FUN_0813fc9c(EnemyBat* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0813f268, ES_UNK_33);
    ParticleShadow_Hide(&(p->e).shadow);
  }
  if (!(p->e).unk_608(&p->e)) {
    (p->e).subStateTimer++;
  }
}

NAKED void FUN_0813fd24(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fd24.inc"); }

NAKED void FUN_0813fe34(EnemyBat* p) { INCFUNC("asm/func/FUN_0813fe34.inc"); }

void FUN_08140014(EnemyBat* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad7d0; }

NAKED void EnemyBat_OnReset(EnemyBat* p) { INCFUNC("asm/func/EnemyBat_OnReset.inc"); }

NAKED void FUN_08140278(EnemyBat* p, u16* msg) { INCFUNC("asm/func/FUN_08140278.inc"); }

NAKED void FUN_0814031c(EnemyBat* p) { INCFUNC("asm/func/FUN_0814031c.inc"); }

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

NAKED void FUN_08140a48(EnemyBat* p) { INCFUNC("asm/func/FUN_08140a48.inc"); }

NAKED void FUN_08140b30(EnemyBat* p) { INCFUNC("asm/func/FUN_08140b30.inc"); }

NAKED void FUN_08140c14(EnemyBat* p) { INCFUNC("asm/func/FUN_08140c14.inc"); }

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

NAKED void FUN_08140dd0(EnemyBat* p) { INCFUNC("asm/func/FUN_08140dd0.inc"); }

s32 FUN_08140ea0(EnemyBat* p) {
  FUN_0814031c(p);
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
