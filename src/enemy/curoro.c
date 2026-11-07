#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

// クロロホルルン
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u32 unk_658;                // 0x658, bit1 が立っている間はプレイヤーを掴んでいる
  u8 biteInterval;            // 0x65C, '.P[0]', 掴んでいる間に噛みつくフレーム間隔
  u8 escapeMash;              // 0x65D, '.P[1]', 振りほどくのに要る連打数
  u16 formGauge;              // 0x65E, variant 1/2 が噛みつくたびに atkPower を溜め, 100 を超えるとプレイヤーを変身させる
  u16 unk_660;                // 0x660, '.p' で置いたときの floorY
  u8 unk_662[0x664 - 0x662];  // 0x662
  u16 curveT;                 // 0x664, curveStart から curveEnd への曲線の進み具合, 0〜1024 を 128 ずつ進む
  u8 bobAngle;                // 0x666, 浮遊の上下の揺れの gSineTable 索引
  s8 curveBendDir;            // 0x667, curveBend を増やす向き, 1 か -1
  s16 curveBend;              // 0x668, 曲線のふくらみ, -320〜320 を往復する
  u8 mashCount;               // 0x66A, 掴んでからの連打数
  u8 mashBase;                // 0x66B, 掴んだときの Player.mashCount
  NavAgent navAgent;          // 0x66C, Enemy.navAgent が指す
  Vec3 unk_690;               // 0x690, Enemy.unk_4a8 が指す
  WorldPos curveStart;        // 0x698, 曲線の始点
  Vec3 curveEnd;              // 0x6A0, 曲線の終点
  Vec3 inertia;               // 0x6A8, 慣性, mover.delta に足しながら 4 フレームおきに半分にする
} Curoro;
static_assert(sizeof(Curoro) == 1712);

extern const char s_curorocom_c_08252078[];  // "curorocom.c"

void Enemy_PlayAnimNoFacing(Enemy* p, s32 param_2);
void FUN_0807a904(Player* p, u32 flag);
bool32 FUN_080f62b0(Enemy* p);
void Player_StartFormEffect(Player* p, u32 kind);
void Curoro_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Curoro_OnHit(HitboxData* a, HitboxData* b, Curoro* p);
void Curoro_OnHurt(HitboxData* a, HitboxData* b, Curoro* p);
void Curoro_HoldPlayer(Curoro* p);
void FUN_0813ac34(Curoro* p);
void FUN_0813ad34(Curoro* p);
void FUN_0813ad64(Curoro* p);
void FUN_0813ae6c(Curoro* p);
void FUN_0813b100(Curoro* p, s32 param_2);
void FUN_0813b22c(Curoro* p, s32 param_2);
void FUN_0813b358(Curoro* p);
void FUN_0813b640(Curoro* p);
void FUN_0813b824(Curoro* p);
void FUN_0813bb04(Curoro* p);
void FUN_0813bc50(Curoro* p);
void FUN_0813be38(Curoro* p);
void FUN_0813bf78(Curoro* p);
void FUN_0813c138(Curoro* p);
void FUN_0813c14c(Curoro* p, u16* msg);
void Curoro_UpdateHover(Curoro* p);
void FUN_0813c38c(Curoro* p);
void Curoro_PickRandomPathNode(Curoro* p);
void Curoro_StartCurve(Curoro* p, Vec3* pos);
bool8 Curoro_StepCurve(Curoro* p);
void FUN_0813c738(Curoro* p);
void Curoro_OnReset(Curoro* p);
void FUN_0813c938(Curoro* p);
void FUN_0813c9c4(Curoro* p, Vec3* pos);
void FUN_0813ca64(Curoro* p);
void FUN_0813ca9c(Curoro* p);
void Curoro_BounceOffWall(Curoro* p);
bool32 FUN_0813cc7c(Curoro* p);
void FUN_0813ccf0(Curoro* p);
void Curoro_ReleasePlayer(Curoro* p);
s32 FUN_0813cdf8(Curoro* p);
s32 FUN_0813ce10(Curoro* p);
void FUN_0813ce1c(Curoro* p);
void FUN_0813d080(Curoro* p);
void FUN_0813d1bc(Curoro* p);
void FUN_0813d1d0(Curoro* p);
void FUN_0813d274(Curoro* p);
void FUN_0813d3f4(Curoro* p);
s32 FUN_0813d404(Curoro* p);

static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) return TRUE;
  return FALSE;
}

static inline bool32 IsPlayerMini(void) {
  u16 timer = gGoodCondTimer;

  return timer != 0 && gGoodCondID == GOOD_MINI;
}

static inline void Hitbox_Hide(HitboxData* hitbox) { hitbox->flags |= HBFLAG_HIDDEN; }

static inline bool8 Curoro_StepToDest(Curoro* p, s32 speed) {
  NavAgent* agent = (p->e).navAgent;
  s16 dx = agent->dest.x - (p->e).mover.pos.x;
  s16 dz = agent->dest.z - (p->e).mover.pos.z;

  if ((dx < 0 ? -dx : dx) <= 32 && (dz < 0 ? -dz : dz) <= 32) {
    return TRUE;
  }
  if (dx != 0 || dz != 0) {
    (p->e).mover.angle = ArcTan2_8(dx, dz);
    (p->e).mover.delta.x += POLAR_X(speed, (p->e).mover.angle);
    (p->e).mover.delta.z += POLAR_Z(speed, (p->e).mover.angle);
  }
  return FALSE;
}

static inline bool8 Curoro_TestUnk658(Curoro* p, u32 bit) {
  if (p->unk_658 & bit) {
    return TRUE;
  }
  return FALSE;
}

// 161/182命令, 原典は variant の両分岐で unk_658 & 2 を読んで捨てる (ldr/ands が残る) 形, 判定 inline の呼び捨ては消える, 1回目の下書きで切り上げ
NON_MATCH void Curoro_OnHit(HitboxData* a, HitboxData* b, Curoro* p) {
#ifdef NONMATCHING_C
  s32 dy;
  Curoro* q;

  if (b->ignoreMask != HIM_0 || Enemy_IsDead(&p->e)) {
    return;
  }
  dy = ((IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_MOUSE) ? 60 : 260) - ((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);
  if (dy < 0) {
    dy = -dy;
  }
  if (dy > 32) {
    return;
  }
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 0, 2, 0);
  Hitbox_SetFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
  Hitbox_SetFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8);
  if ((p->e).variant == 0) {
    FUN_0807a904(gPlayerPtr[0], 0);
    q = (p->e).unk_1cc;
    SET_FLAGS(q->unk_658, 2);
    PlaySound_082406e0(SONG_685);
  } else {
    q = (p->e).unk_1cc;
    SET_FLAGS(q->unk_658, 2);
    if ((p->e).variant == 1) {
      Player_StartFormEffect(gPlayerPtr[0], 1);
    } else {
      Player_StartFormEffect(gPlayerPtr[0], 2);
    }
  }
#else
  INCFUNC("asm/func/Curoro_OnHit.inc");
#endif
}

// Mimic_OnHurt と同じ食らい判定 (敵共通の処理の inline 展開らしい), Mimic_OnHurt の下書きをそのまま当てただけ
NON_MATCH void Curoro_OnHurt(HitboxData* a, HitboxData* b, Curoro* p) {
#ifdef NONMATCHING_C
  u32 knockback;
  u8 angle;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).hurtbox.invincibleTime != 0) {
    if ((p->e).unk_48c != 0) {
      b->damage = 0;
      b->hitResult = 0;
    }
    return;
  }
  if ((p->e).hurtbox.flags & HBFLAG_HIDDEN) {
    return;
  }

  if (!(a->flags & HBFLAG_UNK_0)) {
    if (!(a->weakness & 0x4000)) {
      return;
    }
    if ((p->e).flags3 & (ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
      return;
    }
    if ((p->e).unk_488 != 0) {
      return;
    }
    (p->e).unk_488 = 60;
    if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_27) && (b->flags & HBFLAG_ANGLE) && (a->flags & HBFLAG_ANGLE)) {
      s32 d = b->angle - a->angle;

      if (d < 0) {
        d = -d;
      }
      if (d <= 32) {
        (p->e).unk_4be = a->power;
        (p->e).unk_48c = 1;
        (p->e).unk_44e = Div((p->e).unk_4be, 3);
        SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_13);
        return;
      }
    }
    b->damage = 0;
    (p->e).unk_48a = 0;
    {
      bool8 found = FALSE;
      u16 mask = a->ignoreMask;

      if (mask & HIM_0) {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
        found = TRUE;
      } else if (mask & HIM_1) {
        (p->e).playerMover = &gPlayerPtr[1]->mover;
        found = TRUE;
      } else if (mask & HIM_2) {
        (p->e).playerMover = &gPlayerPtr[2]->mover;
        found = TRUE;
      } else if (mask & HIM_3) {
        (p->e).playerMover = &gPlayerPtr[3]->mover;
        found = TRUE;
      } else if (mask & HIM_4) {
        (p->e).playerMover = NULL;
        found = TRUE;
      } else if (mask & HIM_5) {
        found = TRUE;
      }
      (p->e).unk_4a0 = mask;
      (p->e).weaponExpMask = a->weakness;
      (p->e).flags6 = a->attributes;
      if (found) {
        if ((p->e).flags5 & ENEFLAG5_UNK_1) {
          (p->e).playerMover = &gPlayerPtr[0]->mover;
        }
        if ((p->e).playerMover != NULL) {
          s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
          s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

          (p->e).unk_1fc = ArcTan2_8(dx, dz);
          (p->e).unk_1e4 = dx * dx + dz * dz;
        }
      }
    }
    if ((p->e).flags3 & ENEFLAG3_UNK_7) {
      (p->e).unk_24e += 300;
      if ((p->e).unk_24e > (p->e).unk_24c) {
        (p->e).unk_24e = (p->e).unk_24c;
      }
    }
    (p->e).unk_48c = 1;
    return;
  }

  if (!IsLinkPlay()) {
    Hitbox_ApplyDamage(a, b);
  } else {
    Hitbox_ApplyDamageAlt(a, b);
  }
  b->invincibleTime = a->invincibleTime;
  (p->e).unk_48c = b->hitResult;
  if ((p->e).kind == ENEK_BAT || (p->e).kind == ENEK_CROW || (p->e).kind == ENEK_BEE || (p->e).kind == ENEK_GHOST || (a->attributes & HBATTR_18)) {
    knockback = a->knockbackPower;
  } else {
    knockback = a->knockbackPower - (p->e).unk_187;
    if ((s32)knockback < 0) {
      knockback = 0;
    }
  }
  b->knockbackPower = knockback;
  if ((p->e).flags3 & (ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2)) {
    b->damage <<= 1;
    b->knockbackPower >>= 1;
  }
  if (!(a->flags & HBFLAG_ANGLE)) {
    s16 dx = b->pos.x - a->pos.x;
    s16 dz = b->pos.z - a->pos.z;

    if (dx == 0 && dz == 0) {
      angle = Random();
    } else {
      angle = ArcTan2_8(dx, dz);
    }
  } else {
    angle = a->angle;
  }
  (p->e).angle = angle;
  {
    bool8 found = FALSE;
    u16 mask = a->ignoreMask;

    if (mask & HIM_0) {
      (p->e).playerMover = &gPlayerPtr[0]->mover;
      found = TRUE;
    } else if (mask & HIM_1) {
      (p->e).playerMover = &gPlayerPtr[1]->mover;
      found = TRUE;
    } else if (mask & HIM_2) {
      (p->e).playerMover = &gPlayerPtr[2]->mover;
      found = TRUE;
    } else if (mask & HIM_3) {
      (p->e).playerMover = &gPlayerPtr[3]->mover;
      found = TRUE;
    } else if (mask & HIM_4) {
      (p->e).playerMover = NULL;
      found = TRUE;
    } else if (mask & HIM_5) {
      found = TRUE;
    }
    (p->e).unk_4a0 = mask;
    (p->e).weaponExpMask = a->weakness;
    (p->e).flags6 = a->attributes;
    if (found) {
      if ((p->e).flags5 & ENEFLAG5_UNK_1) {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
      }
      if ((p->e).playerMover != NULL) {
        s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
        s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

        (p->e).unk_1fc = ArcTan2_8(dx, dz);
        (p->e).unk_1e4 = dx * dx + dz * dz;
      }
    }
  }
  if ((p->e).unk_48c != 0 && ((p->e).flags3 & ENEFLAG3_UNK_7)) {
    (p->e).unk_24e += 300;
    if ((p->e).unk_24e > (p->e).unk_24c) {
      (p->e).unk_24e = (p->e).unk_24c;
    }
  }
  if (gStat->mapFlags & MPF_UNK_10) {
    b->damage = 0;
    b->knockbackPower = 0;
    (p->e).unk_48a = 0;
    (p->e).unk_48c = 1;
  }
  FUN_080e64e4(&p->e);
  (p->e).unk_48a = b->damage;
  a->damage += (p->e).unk_188;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
#else
  INCFUNC("asm/func/Curoro_OnHurt.inc");
#endif
}

// 148/147命令, 残差は連打数の差分だけ, 原典は base - 256 を作ってから引くが, こちらは (count + 256) - base に畳まれる, 引き直しを分岐の外に出す形と u32 は試済
NON_MATCH void Curoro_HoldPlayer(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
  s32 mash;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->mashBase = gPlayerPtr[0]->mashCount;
    q->formGauge = 0;
  }
  Enemy_PlayAnimNoFacing(&p->e, 15);
  if (Mod((p->e).stateTimer, q->biteInterval) == 0) {
    if ((p->e).variant == 0) {
      Player_TakeInstantHit(gPlayerPtr[0], (p->e).atkPower[0], (p->e).atkUnk40[0], 0, 0, (p->e).atkAttrs[0]);
    } else {
      q->formGauge += (p->e).atkPower[0];
      if (q->formGauge > 100) {
        if ((p->e).variant == 1) {
          Player_StartFormEffect(gPlayerPtr[0], 1);
        } else {
          Player_StartFormEffect(gPlayerPtr[0], 2);
        }
        q->formGauge = 0;
      }
    }
  }
  {
    s32 base = q->mashBase;
    s32 count = gPlayerPtr[0]->mashCount;

    if (count < base) {
      mash = count - (base - 256);
    } else {
      mash = count - base;
    }
  }
  if (q->mashCount != mash) {
    if (Mod(q->mashCount, 4) == 0) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
    q->mashCount = mash;
  }
  if (q->mashCount > q->escapeMash) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/Curoro_HoldPlayer.inc");
#endif
}

// Enemy_PlayAnim と同じ残差 (定数 4 を r8 に置く形), 再生部を anim/variant/flags を値で受ける inline にすると 108/109 まで寄るが r8 と r6 の割り当てが残る, mode の型と三項演算子は試済
NON_MATCH void FUN_0813ac34(Curoro* p) {
#ifdef NONMATCHING_C
  u32 variant, flags;
  s32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Curoro_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  anim = (p->e).animTable[1].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

    (p->e).playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).sprite->s;
    s32 a = anim + variant;
    s32 mode;

    if ((p->e).playingAnim == a && (p->e).animForceRestart == 0) {
      if (flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (flags == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }
    (p->e).playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (flags & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = 0;
#else
  INCFUNC("asm/func/FUN_0813ac34.inc");
#endif
}

void FUN_0813ad34(Curoro* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 16);
  }
}

// FUN_0813ac34 と同じ残差 (先頭に Enemy_PlayAnim があるだけ), 再生部の inline 化で r8 が出るところまでは FUN_0813ac34 で確認済
NON_MATCH void FUN_0813ad64(Curoro* p) {
#ifdef NONMATCHING_C
  u32 variant, flags;
  s32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Enemy_PlayAnim(&p->e, 0);
  Curoro_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  anim = (p->e).animTable[1].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

    (p->e).playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).sprite->s;
    s32 a = anim + variant;
    s32 mode;

    if ((p->e).playingAnim == a && (p->e).animForceRestart == 0) {
      if (flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (flags == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }
    (p->e).playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (flags & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = 0;
#else
  INCFUNC("asm/func/FUN_0813ad64.inc");
#endif
}

// 279/284命令, 後半のアニメ再生は FUN_0813ac34 と同じ残差, ほかに mover を指すポインタと sprite の anim のアドレスを r6/r8 に持ち越す形, 1回目の下書きで切り上げ
NON_MATCH void FUN_0813ae6c(Curoro* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 cur = Angle_ToDir8((p->e).mover.angle);
    s32 target = Angle_ToDir8((p->e).unk_1dc);

    if (cur == target) {
      (p->e).mover.angle = (p->e).unk_1dc;
      Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
      (p->e).subStateDone = 1;
      return;
    }
    if (((cur - (target - 8)) & 7) <= 4) {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    } else {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    }
  }
  sprite = (AuxSprite*)(p->e).sprite;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).stateTimer & 4) {
    s32 anim;

    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle += 32;
    } else {
      (p->e).mover.angle -= 32;
    }
    Curoro_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    sprite->unk_05 = 0;
    anim = (p->e).animTable[1].anim;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

      (p->e).playingAnim = anim;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
    } else {
      MainSprite* s = &(p->e).sprite->s;
      s32 a = anim + variant;
      s32 mode;

      if ((p->e).playingAnim == a && (p->e).animForceRestart == 0) {
        if (flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
          return;
        }
        if (flags == 0 && !(s->flags & SPRFLAG_XFLIP)) {
          return;
        }
      }
      (p->e).playingAnim = a;
      mode = MAIN_ANIM_FORCE_POSE;
      if (flags & ANIM_PLAY_REVERSE) {
        mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
      }
      MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
      if (flags & ANIM_PLAY_XFLIP) {
        s->flags |= SPRFLAG_XFLIP;
      } else {
        s->flags &= ~SPRFLAG_XFLIP;
      }
    }
    (p->e).animForceRestart = 0;
  }
#else
  INCFUNC("asm/func/FUN_0813ae6c.inc");
#endif
}

// FUN_0813ac34 と同じ再生部の残差, 再生部を値渡しの inline にすると早期 return が後半の判定へ落ちる形になり原典の分岐と合うが r8 と r6 の割り当てが残る
NON_MATCH void FUN_0813b100(Curoro* p, s32 param_2) {
#ifdef NONMATCHING_C
  u32 variant, flags;
  s32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Curoro_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  anim = (p->e).animTable[11].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

    (p->e).playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
    (p->e).animForceRestart = 0;
  } else {
    MainSprite* s = &(p->e).sprite->s;
    s32 a = anim + variant;

    if ((p->e).playingAnim != a || (p->e).animForceRestart != 0 || !((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      s32 mode;

      (p->e).playingAnim = a;
      mode = MAIN_ANIM_FORCE_POSE;
      if (flags & ANIM_PLAY_REVERSE) {
        mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
      }
      MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
      if (flags & ANIM_PLAY_XFLIP) {
        s->flags |= SPRFLAG_XFLIP;
      } else {
        s->flags &= ~SPRFLAG_XFLIP;
      }
      (p->e).animForceRestart = 0;
    }
  }
  if (param_2 < 30) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (param_2 > 59) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/FUN_0813b100.inc");
#endif
}

void FUN_0813b22c(Curoro* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Curoro_ReleasePlayer(p);
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  if (param_2 > 30) {
    FUN_0813c938(p);
    if ((p->e).unk_24e != 0) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
      (p->e).unk_24e = (p->e).unk_24c;
      FUN_0813c9c4(p, &gPlayerPtr[0]->mover.pos);
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      Enemy_EnterState(&p->e, FUN_0813b100, ES_UNK_10);
      Enemy_ResetState(&p->e, 0, 1, 1);
      (p->e).mover.angle = (p->e).unk_1fc;
      (p->e).animSpeedDiv = 1;
    }
  }
}

// 320/327命令, 止まったかの判定の後ろで原典は値を u16 に詰めて r8 に持ち越し, 状態遷移の格納の並びも違う, 2回目の下書きで切り上げ
NON_MATCH void FUN_0813b358(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
  s32 dx, dz;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(SE_UNK_298);
    }
    Hitbox_Hide(&(p->e).atkHitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  dx = FixToInt(2, (p->e).unk_20c.x - (p->e).unk_214.x);
  dz = FixToInt(2, (p->e).unk_20c.z - (p->e).unk_214.z);
  if (dx > 200) {
    dx = 200;
  } else if (dx < -200) {
    dx = -200;
  }
  if (dz > 200) {
    dz = 200;
  } else if (dz < -200) {
    dz = -200;
  }
  (p->e).mover.delta.x += dx;
  (p->e).mover.delta.z += dz;
  (p->e).unk_214.x += dx;
  (p->e).unk_214.z += dz;
  if (dx == 0 && dz == 0) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    q->bobAngle = 0;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      if ((p->e).unk_24e != 0) {
        SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
        (p->e).unk_24e = (p->e).unk_24c;
        FUN_0813c9c4(p, &gPlayerPtr[0]->mover.pos);
        Enemy_ResetState(&p->e, 0, 2, 1);
        FUN_0813c938(p);
      } else {
        (p->e).mover.angle = (p->e).unk_1fc;
        Enemy_EnterState(&p->e, FUN_0813b100, ES_UNK_10);
        Enemy_ResetState(&p->e, 0, 1, 1);
        (p->e).mover.angle = (p->e).unk_1fc;
        (p->e).animSpeedDiv = 1;
        FUN_0813c938(p);
      }
    } else {
      Enemy_ResetState(&p->e, 3, 0, 0);
      Enemy_EnterState(&p->e, FUN_0813b22c, ES_UNK_20);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3);
      (p->e).animSpeedDiv = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0813b358.inc");
#endif
}

void FUN_0813b640(Curoro* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Hitbox_Hide(&(p->e).atkHitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Curoro_ReleasePlayer(p);
  }
  if ((p->e).animForceRestart) {
    s32 idx;

    (p->e).subStateDone = 1;
    FUN_080e6658(&p->e);
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
    (p->e).unk_192 = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
  }
}

void FUN_0813b824(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Vec3_Clear(&q->inertia);
    q->curveBendDir = 1;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  speed = (p->e).unk_588(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  FUN_0813c38c(p);
  if (Curoro_StepToDest(p, speed) && Curoro_StepCurve(p)) {
    WorldPos pos;
    WorldPos* dst;
    PathWalker* walker;

    Vec3_SetPolar(&q->inertia, (p->e).mover.angle, speed);
    Curoro_PickRandomPathNode(p);
    dst = &pos;
    walker = &(p->e).pathWalker;
    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    FUN_0813c9c4(p, &pos);
  }
  (p->e).subStateTimer++;
}

void FUN_0813bb04(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  }
  (p->e).mover.delta.x += q->inertia.x;
  (p->e).mover.delta.z += q->inertia.z;
  if (Mod((p->e).subStateTimer, 4) == 0) {
    q->inertia.x >>= 1;
    q->inertia.z >>= 1;
  }
  if ((p->e).subStateDone) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      Enemy_ResetState(&p->e, 0, 0, 2);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0813bc50(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    q->bobAngle = 0;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if ((p->e).heightAboveFloor >= 240 && (p->e).subStateTimer > 60) {
    WorldPos pos;
    WorldPos* dst;
    PathWalker* walker;

    (p->e).heightAboveFloor = 240;
    Curoro_PickRandomPathNode(p);
    dst = &pos;
    walker = &(p->e).pathWalker;
    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    Curoro_StartCurve(p, &pos);
    Curoro_StepCurve(p);
    Enemy_ResetState(&p->e, 0, 0, 1);
    Vec3_Diff(&pos, &pos, &(p->e).mover.pos);
    (p->e).unk_1dc = ArcTan2_8(pos.x, pos.z);
    Vec3_Clear(&q->inertia);
  }
  (p->e).subStateTimer++;
}

void FUN_0813be38(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_PlayAnimNoFacing(&p->e, 17);
    SET_FLAGS(q->unk_658, 1);
    Hitbox_ClearFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  if ((p->e).subStateTimer < 40) {
    if (Mod((p->e).subStateTimer, 8) == 0) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
  } else {
    if (Mod((p->e).subStateTimer, 3) == 0) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
  }
  if ((p->e).subStateTimer > 60) {
    (p->e).heightAboveFloor += (p->e).mover.pos.y - (p->e).floorY;
    FUN_0813c938(p);
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  (p->e).subStateTimer++;
}

// 187/188命令, 原典は &flags2 を入場判定の直後 (分岐の前) に作り, 入場処理の中で作り直したものと合流させて最後の判定まで持ち越す, 先頭で flags2 のポインタを取る形は試済 (退避レジスタが増える)
NON_MATCH void FUN_0813bf78(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    u8 angle;
    s32 s, n;

    Enemy_EnterState(&p->e, FUN_0813ad34, ES_UNK_35);
    Curoro_ReleasePlayer(p);
    angle = Random();
    Vec3_Clear(&q->inertia);
    s = SIN(angle) * 12;
    if (s >= 0) {
      n = s >> 12;
    } else {
      n = -(-s >> 12);
    }
    (p->e).jumpVel.x = n;
    (p->e).jumpVel.y = 10;
    s = SIN(angle + 64) * 12;
    if (s >= 0) {
      n = s >> 12;
    } else {
      n = -(-s >> 12);
    }
    (p->e).jumpVel.z = n;
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Vec3_Clear(&(p->e).jumpVel);
    Enemy_ResetState(&p->e, 0, 0, 4);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/FUN_0813bf78.inc");
#endif
}

void (*const PTR_ARRAY_085ad770[5])(Curoro*) = {
    FUN_0813bc50,
    FUN_0813bb04,
    FUN_0813b824,
    FUN_0813bf78,
    FUN_0813be38,
};  // 0x085AD770

void FUN_0813c138(Curoro* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad770; }

void FUN_0813c14c(Curoro* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && Curoro_TestUnk658((p->e).unk_1cc, 2)) {
    Enemy_ResetState(&p->e, 0, 0, 3);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
}

// 床からの高さを保って浮かび, スプライトを上下に揺らす
void Curoro_UpdateHover(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e) && !Curoro_TestUnk658(q, 1)) {
    if ((p->e).state == ES_UNK_34 || (p->e).state == ES_UNK_35) {
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
    } else if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
    } else {
      s32 h, d;

      h = (IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_MOUSE) ? 60 : 260;
      if ((p->e).heightAboveFloor < h) {
        (p->e).heightAboveFloor += FixToInt(9, gSineTable[q->bobAngle]);
        if (q->bobAngle < 64) {
          q->bobAngle++;
        }
        (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
      }
      d = (p->e).floorY + h - (p->e).mover.pos.y;
      if ((d < 0 ? -d : d) > 16) {
        if (d < 0) {
          (p->e).heightAboveFloor -= 2;
        } else {
          (p->e).heightAboveFloor += 2;
        }
      }
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
      {
        AuxSprite* sprite = (AuxSprite*)(p->e).sprite;

        sprite->pos.y += FixToInt(12, gSineTable[q->bobAngle] * 32);
      }
      q->bobAngle += 2;
    }
  }
}

void FUN_0813c38c(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if (q->curveBend > 320) {
    q->curveBendDir = -1;
    q->curveBend = 320;
  } else if (q->curveBend < -320) {
    q->curveBendDir = 1;
    q->curveBend = -320;
  }
  q->curveBend += q->curveBendDir * 12;
}

void Curoro_PickRandomPathNode(Curoro* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

void Curoro_InitHitboxes(Curoro* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;
  HitboxFlags32 flags;

  VEC3_SET(hurtSize, 16, 128, 16);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Curoro_OnHurt, p);
  VEC3_SET(hitSize, 16, 84, 16);
  VEC3_SET(hitOffset, 0, 0, 0);
  flags = HBFLAG_HITBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0;
  Hitbox_Init(&(p->e).atkHitbox, (p->e).mover.id, flags, 0, HIM_4, &hitSize, &hitOffset);
  Hitbox_SetAttack(&(p->e).atkHitbox, 0, 0, 0, 0, 0);
  Hitbox_SetPos(&(p->e).atkHitbox, &(p->e).mover.pos, 0);
  Hitbox_SetHandler(&(p->e).atkHitbox, Curoro_OnHit, p);
}

const u32 u32_ARRAY_085ad784[8] = {2, 3, 4, 6, 8, 9, 10, 12};  // 0x085AD784

// 残差1命令 (18/19), 原典は >> 7 の結果を r0 に作ってから r1 へ写す, u32 化, 三項演算子, 値を返す inline は試済
NON_MATCH s32 Curoro_GetMoveSpeed(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
  s32 i = q->curveT >> 7;

  if (i > 7) {
    i = 7;
  }
  return u32_ARRAY_085ad784[i];
#else
  INCFUNC("asm/func/Curoro_GetMoveSpeed.inc");
#endif
}

void Curoro_StartCurve(Curoro* p, Vec3* pos) {
  Curoro* q = (p->e).unk_1cc;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
  q->curveT = 0;
}

// 199/202命令, 原典はフレーム 0x34 で start/end/d/v を sp+4 から宣言順に置き k などを退避するが, こちらはフレーム 0x28 で start と d の位置が逆, 宣言順の入れ替えでは動かない
NON_MATCH bool8 Curoro_StepCurve(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
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
    q->curveT += 128;
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/Curoro_StepCurve.inc");
#endif
}

void FUN_0813c738(Curoro* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 2, 0, 0);
  Enemy_SetAnimEntry(&p->e, 3, 5, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 16, 2, 0);
  Enemy_SetAnimEntry(&p->e, 17, 3, 0);
  Enemy_SetAnimEntry(&p->e, 11, 0, 0);
  Enemy_SetAnimEntry(&p->e, 10, 6, 0);
}

// 残差2命令 (182/183), boku.c の Boku_OnReset と同じく原典は sprite を r0 に読んでから r5 へ写す, ほかに Enemy_ClearPendingState の第1引数の位置, aux を引数に直接書く形と送りを包む inline は試済
NON_MATCH void Curoro_OnReset(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->curveT = 0;
  q->bobAngle = 0;
  q->curveBendDir = 1;
  q->curveBend = 0;
  q->mashCount = 0;
  q->mashBase = 0;
  q->unk_658 = 0;
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->inertia);
  ClearMemory((p->e).unk_4a8, sizeof(Vec3));
  Enemy_ClearPendingState(&p->e, s_curorocom_c_08252078, 270);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
#else
  INCFUNC("asm/func/Curoro_OnReset.inc");
#endif
}

void FUN_0813c938(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS(q->unk_658, 1);
  Hitbox_ClearFlags(&(p->e).atkHitbox, HBFLAG_HIDDEN);
  Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
  CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
}

void Curoro_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = ANGLE_TO_DIR8(angle + 0x10);
  if (IS_8DIR_LEFT(dir)) {
    *variant = 8 - dir;
    *xflip = TRUE;
  } else {
    *variant = dir;
    *xflip = FALSE;
  }
}

void FUN_0813c9c4(Curoro* p, Vec3* pos) {
  Curoro* q = (p->e).unk_1cc;
  Vec3 d;

  Curoro_StartCurve(p, pos);
  Curoro_StepCurve(p);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&d, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  Vec3_Clear(&q->inertia);
}

void FUN_0813ca64(Curoro* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  (p->e).unk_24e = 0;
}

void FUN_0813ca9c(Curoro* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).unk_24e = 0;
    return;
  }
  if ((p->e).unk_24e != 0) {
    (p->e).unk_24e--;
    return;
  }
  Curoro_PickRandomPathNode(p);
  {
    WorldPos pos;
    WorldPos* dst = &pos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    FUN_0813c9c4(p, &pos);
    FUN_0813ca64(p);
  }
}

// 残差は Vec3_Sum の読み順 (mover.pos と jumpVel が逆) と sp のコピーの位置, 引数の入れ替え, 直書き, dst ポインタは試済
NON_MATCH void Curoro_BounceOffWall(Curoro* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_13)) {
    WorldPos pos;
    s32 height;

    Vec3_Sum(&pos, &(p->e).mover.pos, &(p->e).jumpVel);
    height = TileHeightAt(&pos);
    if ((p->e).floorY < height) {
      (p->e).jumpVel.x *= -1;
      (p->e).jumpVel.z *= -1;
      (p->e).mover.delta.x = 0;
      (p->e).mover.delta.z = 0;
    }
  }
#else
  INCFUNC("asm/func/Curoro_BounceOffWall.inc");
#endif
}

bool32 FUN_0813cc7c(Curoro* p) {
  s32 dy;

  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    return FALSE;
  }
  (p->e).flags &= ~ENEFLAG_UNK_3;
  dy = (p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y;
  if (dy < 0) {
    dy = -dy;
  }
  if (dy > 512 || (p->e).unk_1e4 >= (p->e).range0Sq) {
    return FALSE;
  }
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
}

void FUN_0813ccf0(Curoro* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).unk_24e = (p->e).unk_24c;
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 1, 0);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  }
}

void Curoro_ReleasePlayer(Curoro* p) {
  if (Curoro_TestUnk658((p->e).unk_1cc, 2)) {
    Curoro* q;

    if ((p->e).variant == 0) {
      gPlayerPtr[0]->speedPenalty--;
    }
    q = (p->e).unk_1cc;
    CLEAR_FLAGS(q->unk_658, 2);
  }
}

s32 FUN_0813cdf8(Curoro* p) {
  Curoro_UpdateHover(p);
  FUN_0813ca9c(p);
  return 1;
}

s32 FUN_0813ce10(Curoro* p) {
  Curoro_BounceOffWall(p);
  return 1;
}

// 目標への一歩 (到着なら TRUE) を bool8 を返す inline にすると 257/257 命令まで揃い, 残差は p と q の r5/r6 の入れ替わりだけ, 宣言順の入れ替えは効かない
NON_MATCH void FUN_0813ce1c(Curoro* p) {
#ifdef NONMATCHING_C
  Curoro* q = (p->e).unk_1cc;
  s32 speed;
  bool8 arrived;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Vec3_Clear(&q->inertia);
    q->curveBendDir = 1;
  }
  (p->e).unk_608(&p->e);
  speed = (p->e).unk_588(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  FUN_0813c38c(p);
  {
    NavAgent* agent = (p->e).navAgent;
    s16 dx = agent->dest.x - (p->e).mover.pos.x;
    s16 dz = agent->dest.z - (p->e).mover.pos.z;

    if ((dx < 0 ? -dx : dx) <= 32 && (dz < 0 ? -dz : dz) <= 32) {
      arrived = TRUE;
    } else {
      if (dx != 0 || dz != 0) {
        s32 s, n;

        (p->e).mover.angle = ArcTan2_8(dx, dz);
        s = speed * SIN((p->e).mover.angle + 64);
        if (s >= 0) {
          n = s >> 12;
        } else {
          n = -(-s >> 12);
        }
        (p->e).mover.delta.x += n;
        s = speed * SIN((p->e).mover.angle);
        if (s >= 0) {
          n = s >> 12;
        } else {
          n = -(-s >> 12);
        }
        (p->e).mover.delta.z += n;
      }
      arrived = FALSE;
    }
  }
  if (arrived && Curoro_StepCurve(p)) {
    Vec3 d;

    Curoro_StartCurve(p, &gPlayerPtr[0]->mover.pos);
    Curoro_StepCurve(p);
    Enemy_ResetState(&p->e, 0, 0, 1);
    Vec3_Diff(&d, &gPlayerPtr[0]->mover.pos, &(p->e).mover.pos);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/FUN_0813ce1c.inc");
#endif
}

void FUN_0813d080(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Curoro_HoldPlayer, ES_UNK_34);
    q->curveStart = gPlayerPtr[0]->mover.pos;
    FUN_0813ca64(p);
  }
  Vec3_Delta(&d, &q->curveStart, &gPlayerPtr[0]->mover.pos);
  (p->e).mover.delta.x += d.x;
  (p->e).mover.delta.z += d.z;
  q->curveStart = gPlayerPtr[0]->mover.pos;
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 0, 3);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  } else {
    (p->e).subStateTimer++;
  }
}

void (*const PTR_ARRAY_085ad7a4[2])(Curoro*) = {
    FUN_0813d080,
    FUN_0813ce1c,
};  // 0x085AD7A4

void FUN_0813d1bc(Curoro* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad7a4; }

void FUN_0813d1d0(Curoro* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0813b100, ES_UNK_10);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).unk_24e = (p->e).unk_24c;
  }
  if ((p->e).subStateDone) {
    FUN_0813c9c4(p, &gPlayerPtr[0]->mover.pos);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0813d274(Curoro* p) {
  Curoro* q = (p->e).unk_1cc;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer > 60) {
    WorldPos pos;
    WorldPos* dst;
    PathWalker* walker;

    Curoro_PickRandomPathNode(p);
    dst = &pos;
    walker = &(p->e).pathWalker;
    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    Curoro_StartCurve(p, &pos);
    Curoro_StepCurve(p);
    Enemy_ResetState(&p->e, 0, 0, 1);
    Vec3_Diff(&pos, &pos, &(p->e).mover.pos);
    (p->e).unk_1dc = ArcTan2_8(pos.x, pos.z);
    Vec3_Clear(&q->inertia);
  } else {
    (p->e).subStateTimer++;
  }
}

void (*const PTR_ARRAY_085ad7ac[2])(Curoro*) = {
    FUN_0813d1d0,
    FUN_0813d274,
};  // 0x085AD7AC

void FUN_0813d3f4(Curoro* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad7ac; }

s32 FUN_0813d404(Curoro* p) {
  FUN_0813cdf8(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  FUN_0813ce10(p);
  return 1;
}

bool32 Curoro_Update(Curoro* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return FALSE;
}

s32 Curoro_Destroy(Curoro* p) {
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

// メッセージ表
void (*const PTR_ARRAY_085ad7b4[7])(Curoro*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_0813c14c,
};  // 0x085AD7B4

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
// 1663/1834命令, Mimic_Init と同じ残差 (原典はフレーム 0x1A4 に Enemy のフィールドのアドレスを作り置く, 敵共通の初期化 inline), Mimic_Init の下書きを Curoro 向けに直しただけ
NON_MATCH s32 Curoro_Init(Curoro* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_CURORO;
  FUN_0813c738(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSpriteData* aux;
    u8 k;

    (p->e).sprite = Malloc(sizeof(EnemyAuxSpriteData));
    ClearMemory((p->e).sprite, sizeof(EnemyAuxSpriteData));
    aux = (EnemyAuxSpriteData*)(p->e).sprite;
    Video_GetAuxSprite(&aux->gfx, SPRITE_CURORO);
    AuxSprite_Add(&aux->sprite, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_CURORO);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_CURORO);
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
  if (VM_SeekToNamedArg('p')) {
    CollisionMapTile* tile;
    MapTileOverride* ov;
    s32 height;

    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_256 = GetCollisionTileIdx(&(p->e).mover.pos);
    ov = Map_FindTileOverride((p->e).unk_256, 1);
    tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[(p->e).unk_256];
    height = (tile->heightStairs & 0xF) << 8;
    switch (tile->heightStairs >> 4) {
      case STAIRS_VERTICAL: {
        height -= (p->e).mover.pos.z & 0xFF;
        break;
      }
      case STAIRS_HORIZONTAL: {
        height -= (p->e).mover.pos.x & 0xFF;
        break;
      }
    }
    (p->e).floorY = height;
    p->unk_660 = height;
  }
  if (VM_SeekToNamedArg('P')) {
    p->biteInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->escapeMash = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }

  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).unk_47a = 92;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 97;
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

  Curoro_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).unk_4a8 = &p->unk_690;
  (p->e).unk_580 = (EnemyHandler)FUN_0813d404;
  (p->e).unk_588 = (void*)Curoro_GetMoveSpeed;
  (p->e).unk_590 = FUN_0813ae6c;
  (p->e).unk_5a0 = FUN_0813ac34;
  (p->e).unk_5a4 = FUN_0813ad64;
  (p->e).unk_5c0 = NULL;
  (p->e).unk_5c4 = (EnemyHandler)FUN_080f62b0;
  (p->e).unk_5cc = FUN_0813b358;
  (p->e).unk_5d0 = FUN_0813b640;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = NULL;
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
  (p->e).onReset = (EnemyHandler)Curoro_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).unk_5ac = (EnemyHandler)FUN_0813ccf0;
  (p->e).unk_5b0 = NULL;
  (p->e).unk_608 = (void*)FUN_0813cc7c;
  (p->e).unk_60c = (void*)PTR_ARRAY_085ad7b4;
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5 | ENEFLAG5_UNK_6);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_10 | ENEFLAG2_UNK_20 | ENEFLAG2_UNK_25);
  if ((p->e).variant != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  }
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
  FUN_0813c138(p);
  FUN_0813d1bc(p);
  FUN_0813d3f4(p);
  (p->e).unk_1bc = 2;
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
  (p->e).handlerUpdate = (EnemyHandler)Curoro_Update;
  (p->e).handlerDestroy = (EnemyHandler)Curoro_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Curoro_Init.inc");
#endif
}

void Curoro_Create(void) {
  Curoro* p = Malloc(sizeof(Curoro));
  if (p != NULL) {
    ClearMemory(p, sizeof(Curoro));
    if (Curoro_Init(p) < 0) {
      Curoro_Destroy(p);
      Free(p);
    }
  }
}
