#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "global.h"
#include "hitbox.h"
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

// Bee.flags (0x658)
typedef u32 BeeFlags;
#define BEEFLAG_UNK_0 (1 << 0)    // 0x1, 立っている間 Bee_UpdateHover は浮かずに床の高さに置く
#define BEEFLAG_UNK_1 (1 << 1)    // 0x2, BEEFLAG_UNK_0 と一緒に Bee_ResumeHover が落とす
#define BEEFLAG_FAST (1 << 2)     // 0x4, 立っていると Bee_GetMoveSpeed が速くなる, 被弾で落ちる
#define BEEFLAG_RETREAT (1 << 3)  // 0x8, 立っていると次の曲線は playerAngle の反対側へ短く引く, 被弾と突進の待ちの後に立つ

// ENEK_BEE (variant: EV_BEE, EV_KBEE, EV_PBEE)
typedef struct {
  Enemy e;
  u8 unk_654[4];              // 0x654
  BeeFlags flags;             // 0x658
  u16 spawnHeight;            // 0x65C, 出現位置の床からの高さ
  u16 prevFloorY;             // 0x65E, 前のフレームの floorY
  u8 chargeCooldown;          // 0x660, 突進を始めると chargeInterval を入れ毎フレーム減る, 残っている間は突進せず待つ
  u8 unk_661;                 // 0x661
  u8 unk_662;                 // 0x662
  u8 animAngle;               // 0x663, animTable[1] のアニメを流したときの向き, 変わったら流し直す
  Vec3 curvePoints[8];        // 0x664, 曲線を 8 等分した点
  Vec3 curvePointsEnd;        // 0x6A4, curvePoints の曲線の終点
  u8 curvePointIdx;           // 0x6AC, curvePoints の今向かっている点の番号
  u8 chargeInterval;          // 0x6AD, '.P[0]=104'
  u8 attackWait;              // 0x6AE, 0 になるまで突進しない, 被弾や待ちの後に 60 を入れる
  u8 unk_6af;                 // 0x6AF
  u16 curveTimeBase;          // 0x6B0, '.P[1]=100', 新しい曲線の curveTime の元, Bee_GetCurveTimeShift ぶん左に寄せる
  u8 unk_6b2[0x6B4 - 0x6B2];  // 0x6B2
  u16 curveT;                 // 0x6B4
  u8 hoverPhase;              // 0x6B6, 浮遊の上下の揺れの sin の位相
  s8 curveBendDir;            // 0x6B7
  s16 curveBend;              // 0x6B8
  u8 unk_6ba;                 // 0x6BA
  u8 unk_6bb;                 // 0x6BB
  u8 unk_6bc[0x6BE - 0x6BC];  // 0x6BC
  s16 curveTime;              // 0x6BE, 曲線の今の区間の残り時間, 毎フレーム subStateTimer ずつ減り 0 以下で次の点へ移る
  u16 targetID;               // 0x6C0, 向かう相手の mover.id, メッセージで受け取る
  u16 orbitRadius;            // 0x6C2, target から曲線の終点までの距離, メッセージで受け取る
  Mover* target;              // 0x6C4, targetID の Mover
  NavAgent navAgent;          // 0x6C8, Enemy.navAgent が指す
  Vec3 pathNodePos;           // 0x6EC, Enemy.pathNodePos が指す
  WorldPos curveStart;        // 0x6F4, 曲線の始点
  Vec3 curveEnd;              // 0x6FC, 曲線の終点
  Vec3 curveTangent;          // 0x704, 曲線の始点の接線, x と z を 16 倍して使う, 曲線移動を始めるときに 0 に戻す
  WorldPos homePos;           // 0x70C, 復帰したときに戻る位置
} Bee;
static_assert(sizeof(Bee) == 1812);

static inline bool8 Bee_TestFlags(Bee* p, BeeFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

void Bee_ResumeHover(Bee* p);
void Bee_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Bee_BeginCurveTo(Bee* p, Vec3* pos);
void Bee_BuildCurvePoints(Bee* p, Vec3* pos);
s32 FUN_0816869c(Bee* p, Vec3* from, Vec3* to);

void Bee_OnHit(HitboxData* a, HitboxData* b, Bee* p) {}

// 食らい判定, 共通処理のあとノックバックを 0〜15 減らし 20 を下限にして, BEEFLAG_FAST を落とす
// 803/808命令, EnemyBat_OnHurt / Crow_OnHurt と同じ残差 (ノックバックの種別判定の配置, p->angle の格納先の計算位置, 末尾の乱数の読み順), 試済: EnemyBat_OnHurt と同じ形
NON_MATCH void Bee_OnHurt(HitboxData* a, HitboxData* b, Bee* p) {
#ifdef NONMATCHING_C
  s32 knockback;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_UNK_11)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  knockback = b->knockback - (Random() & 15);
  b->knockback = knockback < 20 ? 20 : knockback;
  ((Bee*)(p->e).owner)->flags &= ~BEEFLAG_FAST;
#else
  INCFUNC("asm/func/Bee_OnHurt.inc");
#endif
}

// 向きが変わったときだけ animTable[1] のアニメを向きに合わせて流し直し, コマの進み具合は引き継ぐ
// 260/252命令, 再生部を (Enemy*, anim, variant, flags) を取る inline にすると 249/252 まで寄り, 残差は Curoro の FUN_0813ac34 と同じ (原典は再生モードの定数 4 と反転フラグの 4 を別々に作り片方を r8 に置く), 試済: anim ポインタのローカル, mode の型と変数化
NON_MATCH void Bee_StateFly(Bee* p) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    AuxAnimState* anim;

    Bee_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    anim = &(p->e).s->aux.anim;
    anim->cmdCount = 0;
    {
      u8 idx = (p->e).animTable[1].anim;

      if ((p->e).spriteKind == 0) {
        EnemyAuxSprite* s = &(p->e).s->aux;

        (p->e).playingAnim = idx;
        AuxAnim_SetAnim(&s->anim, s->animFile, idx, variant, flags);
        (p->e).animForceRestart = FALSE;
      } else {
        MainSprite* s = &(p->e).s->main.spr;
        s32 a = idx + variant;

        if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
          s32 mode;

          (p->e).playingAnim = a;
          mode = MAIN_ANIM_FORCE_POSE;
          if (flags & ANIM_PLAY_REVERSE) {
            mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
          }
          MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
          if (flags & ANIM_PLAY_XFLIP) {
            s->flags |= SPRFLAG_XFLIP;
          } else {
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
        }
      }
    }
    q->animAngle = (p->e).mover.angle;
  } else if (q->animAngle != (p->e).mover.angle) {
    AuxAnimState* anim = &(p->e).s->aux.anim;
    u32 cmdIdx = anim->cmdIdx;
    u32 tick = anim->tick;

    Bee_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    {
      u8 idx = (p->e).animTable[1].anim;

      if ((p->e).spriteKind == 0) {
        EnemyAuxSprite* s = &(p->e).s->aux;

        (p->e).playingAnim = idx;
        AuxAnim_SetAnim(&s->anim, s->animFile, idx, variant, flags);
        (p->e).animForceRestart = FALSE;
      } else {
        MainSprite* s = &(p->e).s->main.spr;
        s32 a = idx + variant;

        if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
          s32 mode;

          (p->e).playingAnim = a;
          mode = MAIN_ANIM_FORCE_POSE;
          if (flags & ANIM_PLAY_REVERSE) {
            mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
          }
          MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
          if (flags & ANIM_PLAY_XFLIP) {
            s->flags |= SPRFLAG_XFLIP;
          } else {
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
        }
      }
    }
    anim->cmdIdx = cmdIdx;
    anim->tick = tick;
    q->animAngle = (p->e).mover.angle;
  } else {
    (p->e).animForceRestart = FALSE;
  }
#else
  INCFUNC("asm/func/Bee_StateFly.inc");
#endif
}

void Bee_AnimIdle(Bee* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

void Bee_AnimWindUp(Bee* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 14);
}

void Bee_AnimCharge(Bee* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// playerAngle が変わったときだけ animTable[1] のアニメをその向きに合わせて流し直し, コマの進み具合は引き継ぐ
// 266/258命令, Bee_StateFly と同じ壁 (再生部の展開), 試済: Bee_StateFly と同じ形
NON_MATCH void Bee_AnimRecoil(Bee* p) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Bee_GetAnimVariant((p->e).playerAngle, &variant, &flags);
    {
      u8 idx = (p->e).animTable[1].anim;

      if ((p->e).spriteKind == 0) {
        EnemyAuxSprite* s = &(p->e).s->aux;

        (p->e).playingAnim = idx;
        AuxAnim_SetAnim(&s->anim, s->animFile, idx, variant, flags);
        (p->e).animForceRestart = FALSE;
      } else {
        MainSprite* s = &(p->e).s->main.spr;
        s32 a = idx + variant;

        if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
          s32 mode;

          (p->e).playingAnim = a;
          mode = MAIN_ANIM_FORCE_POSE;
          if (flags & ANIM_PLAY_REVERSE) {
            mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
          }
          MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
          if (flags & ANIM_PLAY_XFLIP) {
            s->flags |= SPRFLAG_XFLIP;
          } else {
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
        }
      }
    }
    Enemy_PlayAnim(&p->e, 1);
    q->animAngle = (p->e).playerAngle;
  } else if (q->animAngle != (p->e).playerAngle) {
    AuxAnimState* anim = &(p->e).s->aux.anim;
    u32 cmdIdx = anim->cmdIdx;
    u32 tick = anim->tick;

    Bee_GetAnimVariant((p->e).playerAngle, &variant, &flags);
    {
      u8 idx = (p->e).animTable[1].anim;

      if ((p->e).spriteKind == 0) {
        EnemyAuxSprite* s = &(p->e).s->aux;

        (p->e).playingAnim = idx;
        AuxAnim_SetAnim(&s->anim, s->animFile, idx, variant, flags);
        (p->e).animForceRestart = FALSE;
      } else {
        MainSprite* s = &(p->e).s->main.spr;
        s32 a = idx + variant;

        if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
          s32 mode;

          (p->e).playingAnim = a;
          mode = MAIN_ANIM_FORCE_POSE;
          if (flags & ANIM_PLAY_REVERSE) {
            mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
          }
          MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
          if (flags & ANIM_PLAY_XFLIP) {
            s->flags |= SPRFLAG_XFLIP;
          } else {
            s->flags &= ~SPRFLAG_XFLIP;
          }
          (p->e).animForceRestart = FALSE;
        }
      }
    }
    anim->cmdIdx = cmdIdx;
    anim->tick = tick;
    q->animAngle = (p->e).playerAngle;
  } else {
    (p->e).animForceRestart = FALSE;
  }
#else
  INCFUNC("asm/func/Bee_AnimRecoil.inc");
#endif
}

void Bee_StateDamaged(Bee* p) {
  Bee* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_PlayAnim(&p->e, 3);
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    Bee_ResumeHover(p);
    Enemy_ResetState(&p->e, 0, 2, 0);
    SET_FLAGS(q->flags, BEEFLAG_RETREAT);
    q->attackWait = 60;
  }
}

void Bee_StateDying(Bee* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
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
      FUN_080e6658(&p->e);
    }
    (p->e).sleepTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
}

// 乱数の向きへ弾かれて滑り, 止まったらプレイヤーへの曲線移動を始める
// 148/148命令, 残差は ldrsh のゼロ添字と jumpVel のオフセットに使う一時レジスタ番号だけ (EnemyBat の FUN_08140eb0 と同じ壁), 試済: q のスコープ, vel ローカルの有無と位置
NON_MATCH void Bee_StateBounce(Bee* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Bee* q = (p->e).owner;
    u8 r;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Vec3_Clear(&q->curveTangent);
    r = Random();
    (p->e).jumpVel.x = FixToInt(6, SIN(r));
    (p->e).jumpVel.z = FixToInt(6, COS(r));
  }
  {
    Vec3* vel = &(p->e).jumpVel;

    if (vel->x * vel->x + vel->z * vel->z == 0) {
      Bee_ResumeHover(p);
      Vec3_Clear(vel);
      Bee_BeginCurveTo(p, &gPlayerPtr[0]->mover.pos);
      Enemy_ResetState(&p->e, 0, 2, 0);
    }
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Bee_StateBounce.inc");
#endif
}

void (*const sBeeHandlerTable2[1])(Bee*) = {
    Bee_StateBounce,
};  // 0x085ADA14

void Bee_SetHandlerTable2(Bee* p) { (p->e).handlerTables[2] = (void*)sBeeHandlerTable2; }

// メッセージで受け取った mover.id の相手の方向から乱数で 0〜63 ずらした 512 先へ曲線で飛び始める
// 215/215命令, 残差は COS の ldrsh のゼロ添字の一時レジスタ番号 (r1 と原典 r2) だけ, Bee_StateBounce と同じ壁, 試済: pos ローカル, Vec3_Sum/Add, Vec3_Diff/Delta, 角度のローカルと & 0xFF の有無, ローカルの宣言位置
NON_MATCH void Bee_OnTargetMsg(Bee* p, u16* msg) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_14)) {
    Bee* q = (p->e).owner;
    Vec3 diff;
    Vec3 dest;

    q->targetID = msg[1];
    q->target = Mover_FindByID_Proxy(q->targetID);
    q->orbitRadius = msg[2];
    q->curvePointIdx = 0;
    Vec3_Delta(&diff, &(p->e).mover.pos, &q->target->pos);
    (p->e).playerAngle = ArcTan2_8(diff.x, diff.z);
    Vec3_SetPolar(&dest, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 512);
    q->curveTime = 1280;
    Vec3_Add(&dest, &(p->e).mover.pos);
    Bee_BuildCurvePoints(p, &dest);
    FUN_0816869c(p, &(p->e).mover.pos, &dest);
    Vec3_Clear(&q->curveTangent);
    Enemy_ResetState(&p->e, 2, 0, 6);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
#else
  INCFUNC("asm/func/Bee_OnTargetMsg.inc");
#endif
}

// 復帰時に作業値を消して homePos へ戻し, 床の高さを取り直して待機アニメを流して1コマ送る
void Bee_OnReset(Bee* p) {
  Bee* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->unk_661 = 0;
  q->curveT = 0;
  q->hoverPhase = 0;
  q->curveBendDir = 1;
  q->curveBend = 0;
  q->unk_6ba = 0;
  q->unk_6bb = 0;
  q->flags = 0;
  (p->e).mover.pos = q->homePos;
  (p->e).tileIdx = GetCollisionTileIdx(&q->homePos);
  (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &q->homePos);
  (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
  (p->e).mover.pos.y = (p->e).floorY;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->curveTangent);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
}

// ENEFLAG2_UNK_20 の間は床から 260 ほどの高さを保って浮き, sin で上下に揺らす, 床の段差ぶんは高さを補う
void Bee_UpdateHover(Bee* p) {
  Bee* q = (p->e).owner;

  if (Enemy_IsDead(&p->e) == 0) {
    s32 diff = (p->e).floorY - q->prevFloorY;

    (p->e).heightAboveFloor -= diff;
    q->prevFloorY = (p->e).floorY;
    if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
    } else {
      s32 d;
      s32 y;

      if ((p->e).heightAboveFloor <= 259) {
        if (Bee_TestFlags(q, BEEFLAG_UNK_0)) {
          (p->e).mover.pos.y = (p->e).floorY;
          return;
        }
        (p->e).heightAboveFloor += FixToInt(9, SIN(q->hoverPhase));
        if (q->hoverPhase < 64) {
          q->hoverPhase++;
        }
        (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
      }
      d = (p->e).floorY;
      y = (p->e).mover.pos.y - 260;
      d -= y;
      if (abs(d) > 16) {
        if (d < 0) {
          (p->e).heightAboveFloor -= 8;
        } else {
          (p->e).heightAboveFloor += 8;
        }
      }
      (p->e).mover.pos.y = (p->e).floorY + (p->e).heightAboveFloor;
      {
        AuxSprite* sprite = &(p->e).s->aux.spr;

        sprite->pos.y -= FixToInt(5, SIN(q->hoverPhase));
      }
      if (q->hoverPhase > 64) {
        q->hoverPhase = 0;
      } else {
        q->hoverPhase += 8;
      }
    }
  }
}

void Bee_InitHitboxes(Bee* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 16, 64, 16);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Bee_OnHurt, p);
  VEC3_SET(hitSize, 32, 52, 32);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Bee_OnHit, 0, p);
}

const u32 sBeeMoveSpeeds[8] = {2, 3, 4, 6, 7, 9, 10, 12};  // 0x085ADA18

// curveT が大きいほど速く, BEEFLAG_FAST が立っていればさらに速い
s32 Bee_GetMoveSpeed(Bee* p) {
  Bee* q = (p->e).owner;
  s32 v = abs(FixToInt(7, q->curveT));
  s32 i = v;

  if (i > 7) {
    i = 7;
  }
  if (Bee_TestFlags(q, BEEFLAG_FAST)) {
    return sBeeMoveSpeeds[i] + 6;
  }
  return sBeeMoveSpeeds[i];
}

void Bee_StartCurve(Bee* p, Vec3* pos) {
  Bee* q = (p->e).owner;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
  q->curveT = 0;
}

// curveStart から curveEnd への曲線上の curveT の位置を経路の目的地に置き, curveT を乱数ぶん進める, 終点に着いたら TRUE
// 220/221命令, EnemyBat_StepCurve / Curoro_StepCurve と同じ壁 (原典はフレーム 0x34 で start/end/d/v を sp+4 から置き k などを退避, こちらは 0x28), 試済: EnemyBat の C をそのまま
NON_MATCH bool8 Bee_StepCurve(Bee* p) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
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
  t2 = FixToInt(10, t * t);
  t3 = FixToInt(10, t2 * t);
  k *= t3 - 2 * t2 + t;
  n = v.x * (2 * t3 - 3 * t2 + 1) + d.x * (3 * t2 - 2 * t3) + k;
  dest->x = start.x + FixToInt(10, n);
  n = v.y * (2 * t3 - 3 * t2 + 1) + d.y * (3 * t2 - 2 * t3) + k;
  dest->y = start.y + FixToInt(10, n);
  n = v.z * (2 * t3 - 3 * t2 + 1) + d.z * (3 * t2 - 2 * t3) + k;
  dest->z = start.z + FixToInt(10, n);
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
  INCFUNC("asm/func/Bee_StepCurve.inc");
#endif
}

void Bee_InitAnims(Bee* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 10, 3, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
  Enemy_SetAnimEntry(&p->e, 5, 2, 0);
}

// 浮遊 (ENEFLAG2_UNK_20) に戻し, 攻撃判定を出し直す
void Bee_ResumeHover(Bee* p) {
  Bee* q = (p->e).owner;

  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS(q->flags, BEEFLAG_UNK_0 | BEEFLAG_UNK_1);
  (p->e).hitbox.flags &= ~HBFLAG_HIDDEN;
}

void Bee_BeginCurveTo(Bee* p, Vec3* pos) {
  Bee* q = (p->e).owner;
  Vec3 diff;

  Bee_StartCurve(p, pos);
  Bee_StepCurve(p);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&diff, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(diff.x, diff.z);
  Vec3_Clear(&q->curveTangent);
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void Bee_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

void Bee_TickChargeCooldown(Bee* p) {
  Bee* q = (p->e).owner;

  if (q->chargeCooldown != 0) {
    q->chargeCooldown--;
  }
}

// 今の位置から pos への曲線を 8 等分した点を curvePoints に求め, 終点を curvePointsEnd に置く
// 240/232命令, Bee_StepCurve と同じく原典は start/end/d/v を sp+4 から置くがこちらは start が sp+0x14 (宣言順では動かない), 加えて m を退避する分だけ命令が多い, 試済: d/v のスコープ, 宣言順, h11 のローカル, dst ポインタの有無, 全ローカルを関数頭に
NON_MATCH void Bee_BuildCurvePoints(Bee* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
  WorldPos start, end;
  Vec3 d, v;
  Vec3* dst;
  s32 step, k0, k1, i, t, t2, t3, m, n;

  start = (p->e).mover.pos;
  end = *pos;
  start.y = 0;
  end.y = 0;
  step = Div(1024, 8);
  k0 = q->curveTangent.x << 4;
  k1 = q->curveTangent.z << 4;
  for (i = 0; i < 8; i++) {
    dst = &q->curvePoints[i];
    t = (i + 1) * step;
    Vec3_Diff(&d, &end, &start);
    Vec3_Clear(&v);
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    m = k1 * (t3 - 2 * t2 + t);
    n = v.x * (2 * t3 - 3 * t2 + 1) * k0 + d.x * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->x = start.x + FixToInt(10, n);
    n = v.y * (2 * t3 - 3 * t2 + 1) * k0 + d.y * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->y = start.y + FixToInt(10, n);
    n = v.z * (2 * t3 - 3 * t2 + 1) * k0 + d.z * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->z = start.z + FixToInt(10, n);
  }
  q->curvePointsEnd = end;
#else
  INCFUNC("asm/func/Bee_BuildCurvePoints.inc");
#endif
}

// from から to へのずれを求めるが結果は使わない
s32 FUN_0816869c(Bee* p, Vec3* from, Vec3* to) {
  Vec3 d;

  Vec3_Delta(&d, from, to);
}

// 攻撃判定の威力などを, ENEFLAG3_UNK_8 が立っていれば 1 番, そうでなければ 0 番の組にする
void Bee_SelectAttack(Bee* p) {
  if (!Enemy_IsDead(&p->e)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 的を探してよい番を使い切り, 高さが近いプレイヤーが索敵範囲に入っていれば攻撃の要求を立てる
bool8 Bee_TryDetectPlayer(Bee* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy;

    (p->e).flags &= ~ENEFLAG_UNK_3;
    dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);
    if (dy <= 512 && (p->e).playerDistSq < (p->e).range0Sq) {
      goto found;
    }
  }
  return FALSE;

found:
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
}

// Bee_TryDetectPlayer が立てた攻撃の要求を受けたときに呼ばれる
void Bee_OnAttackRequest(Bee* p) { SET_FLAGS((p->e).flags, ENEFLAG_UNK_26); }

s32 Bee_GetCurveTimeShift(Bee* p) {
  switch ((p->e).variant) {
    case EV_BEE: {
      return 5;
    }
    case EV_KBEE: {
      return 2;
    }
    case EV_PBEE: {
      return 4;
    }
  }
  return 4;
}

void FUN_081687fc(Bee* p) {
  if (p->unk_6af != 0) {
    p->unk_6af--;
  }
}

s32 Bee_PreUpdate(Bee* p) {
  Bee_UpdateHover(p);
  return 1;
}

s32 Bee_PostUpdate(Bee* p) {
  Bee_TickChargeCooldown(p);
  Bee_SelectAttack(p);
  FUN_081687fc(p);
  return 1;
}

// playerAngle の向き (BEEFLAG_RETREAT が立っていれば反対向き) へ曲線で飛び回り, attackWait が尽きてプレイヤーが近ければ突進の溜めへ移る
// 543/541命令, 残差は BEEFLAG_RETREAT を見たアドレスを落とすときに使い回すかどうかと, 乱数の & 63 と playerAngle の読み順 (Bee_StateRecoil と同じ壁), 試済: 枝の順, 角度の足し順, CLEAR_FLAGS / &= ~8, TEST_FLAGS
NON_MATCH void Bee_StateRoam(Bee* p) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
  Vec3 dest;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    if (Bee_TestFlags(q, BEEFLAG_RETREAT)) {
      Vec3_SetPolar(&dest, ((Random() & 63) + 128 + (p->e).playerAngle) & 0xFF, 320);
      CLEAR_FLAGS(q->flags, BEEFLAG_RETREAT);
      q->curveTime = 6 << Bee_GetCurveTimeShift(p);
    } else {
      Vec3_SetPolar(&dest, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 512);
      q->curveTime = 40 << Bee_GetCurveTimeShift(p);
    }
    Vec3_Add(&dest, &(p->e).mover.pos);
    Bee_BuildCurvePoints(p, &dest);
    FUN_0816869c(p, &(p->e).mover.pos, &dest);
    Vec3_Clear(&q->curveTangent);
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  (p->e).mover.angle = (p->e).playerAngle;
  if (q->curveTime > 0 && d.x * d.x + d.z * d.z > 1024) {
    s32 div = FixToInt(5, q->curveTime);

    div = div < 1 ? 1 : div;
    (p->e).mover.delta.x += Div(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, div);
    (p->e).mover.delta.z += Div(q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z, div);
    q->curveTangent = (p->e).mover.delta;
    q->curveTime -= (p->e).subStateTimer;
  } else {
    if (++q->curvePointIdx > 8) {
      (p->e).mover.pos.x = q->curvePointsEnd.x;
      (p->e).mover.pos.z = q->curvePointsEnd.z;
      Vec3_SetPolar(&dest, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 512);
      Vec3_Add(&dest, &(p->e).mover.pos);
      Bee_BuildCurvePoints(p, &dest);
      FUN_0816869c(p, &(p->e).mover.pos, &dest);
      q->curveTime = q->curveTimeBase << Bee_GetCurveTimeShift(p);
      q->curvePointIdx = 0;
      (p->e).subStateTimer = 0;
      return;
    }
    (p->e).mover.pos.x = q->curvePoints[q->curvePointIdx - 1].x;
    (p->e).mover.pos.z = q->curvePoints[q->curvePointIdx - 1].z;
  }
  if ((p->e).subStateTimer < 20) {
    (p->e).subStateTimer++;
  }
  if (q->attackWait == 0) {
    if ((p->e).playerDistSq > 65534) {
      return;
    }
    if (q->chargeCooldown != 0) {
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      Enemy_ResetState(&p->e, 0, 2, 2);
    }
  } else {
    q->attackWait--;
  }
#else
  INCFUNC("asm/func/Bee_StateRoam.inc");
#endif
}

void Bee_StateWaitCharge(Bee* p) {
  Bee* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
  if ((p->e).subStateTimer > 30) {
    Enemy_ResetState(&p->e, 0, 2, 0);
    SET_FLAGS(q->flags, BEEFLAG_RETREAT);
    q->attackWait = 60;
  } else {
    (p->e).subStateTimer++;
  }
}

// 突進の前の溜め, アニメ 14 を 40 フレーム以上流し終えたら Bee_StateCharge へ
void Bee_StateWindUp(Bee* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_EnterState(&p->e, Bee_AnimWindUp, ES_UNK_36);
  }
  if ((p->e).subStateTimer > 40 && (p->e).animForceRestart) {
    Enemy_ResetState(&p->e, 0, 2, 3);
  }
  (p->e).subStateTimer++;
}

// 入った時点のプレイヤーの位置へ突進し, 攻撃判定を 1 番の組にする, 終わったら Bee_StateRecoil へ
void Bee_StateCharge(Bee* p) {
  Bee* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_EnterState(&p->e, Bee_AnimCharge, ES_UNK_37);
    (p->e).navAgent->dest = gPlayerPtr[0]->mover.pos;
    q->chargeCooldown = q->chargeInterval;
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    PlaySound_082406e0(SE_BEE_968);
  }
  Enemy_StepToDest(&p->e, 24);
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 2, 4);
  } else {
    (p->e).subStateTimer++;
  }
}

// 突進の後, playerAngle の反対側へ弾かれ 30 フレームで攻撃判定を 0 番の組に戻す
// 残差は乱数の & 31 と &playerAngle のアドレス計算の順序のみ (原典はアドレスを先に作る), 試済: u8 ローカル, (u8) キャスト, 1式にまとめる, 2文に分ける
NON_MATCH void Bee_StateRecoil(Bee* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    u32 angle;

    Enemy_EnterState(&p->e, Bee_AnimRecoil, ES_UNK_38);
    angle = (Random() & 31) + 113;
    angle = (angle + (p->e).playerAngle) & 0xFF;
    Vec3_SetPolar(&(p->e).jumpVel, angle, 32);
  }
  if ((p->e).subStateTimer > 30) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ResetState(&p->e, 0, 2, 0);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Bee_StateRecoil.inc");
#endif
}

// target の周りの乱数の位置へ曲線を引き, curvePoints を順にたどって飛ぶ, 9 点目に着くたびに次の曲線を引く
// 488/488命令, 残差は COS の ldrsh のゼロ添字の一時レジスタ番号 2 か所だけ (Bee_OnTargetMsg と同じ壁), 試済: pos ローカルの有無と位置, if の向き, div の型, div の下限の書き方 (三項演算子で cmp #1 になる)
NON_MATCH void Bee_StateFlyAroundTarget(Bee* p) {
#ifdef NONMATCHING_C
  Bee* q = (p->e).owner;
  Vec3 diff;
  Vec3 dest;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    Vec3_Delta(&diff, &(p->e).mover.pos, &q->target->pos);
    (p->e).playerAngle = ArcTan2_8(diff.x, diff.z);
    Vec3_SetPolar(&dest, ((Random() & 63) + (p->e).playerAngle) & 0xFF, q->orbitRadius);
    q->curveTime = 1280;
    Vec3_Add(&dest, &(p->e).mover.pos);
    Bee_BuildCurvePoints(p, &dest);
    FUN_0816869c(p, &(p->e).mover.pos, &dest);
    Vec3_Clear(&q->curveTangent);
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  Vec3_Delta(&diff, &(p->e).mover.pos, &q->target->pos);
  (p->e).mover.angle = (p->e).playerAngle = ArcTan2_8(diff.x, diff.z);
  if (q->curveTime > 0 && d.x * d.x + d.z * d.z > 1024) {
    s32 div = FixToInt(5, q->curveTime);

    div = div < 1 ? 1 : div;
    (p->e).mover.delta.x += Div(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, div);
    (p->e).mover.delta.z += Div(q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z, div);
    q->curveTangent = (p->e).mover.delta;
    q->curveTime -= (p->e).subStateTimer;
  } else {
    if (++q->curvePointIdx > 8) {
      (p->e).mover.pos.x = q->curvePointsEnd.x;
      (p->e).mover.pos.z = q->curvePointsEnd.z;
      Vec3_Delta(&diff, &(p->e).mover.pos, &q->target->pos);
      (p->e).playerAngle = ArcTan2_8(diff.x, diff.z);
      Vec3_SetPolar(&dest, ((Random() & 63) + (p->e).playerAngle) & 0xFF, q->orbitRadius);
      Vec3_Add(&dest, &(p->e).mover.pos);
      Bee_BuildCurvePoints(p, &dest);
      FUN_0816869c(p, &(p->e).mover.pos, &dest);
      q->curveTime = q->curveTimeBase * 32;
      q->curvePointIdx = 0;
      (p->e).subStateTimer = 0;
      return;
    }
    (p->e).mover.pos.x = q->curvePoints[q->curvePointIdx - 1].x;
    (p->e).mover.pos.z = q->curvePoints[q->curvePointIdx - 1].z;
  }
  if ((p->e).subStateTimer < 20) {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Bee_StateFlyAroundTarget.inc");
#endif
}

void (*const sBeeHandlerTable4[5])(Bee*) = {
    Bee_StateRoam,
    Bee_StateWaitCharge,
    Bee_StateWindUp,
    Bee_StateCharge,
    Bee_StateRecoil,
};  // 0x085ADA38

void Bee_SetHandlerTable4(Bee* p) { (p->e).handlerTables[4] = (void*)sBeeHandlerTable4; }

void (*const sBeeHandlerTable8[7])(Bee*) = {
    (void*)FUN_080f1de4,
    (void*)FUN_080f1e0c,
    (void*)FUN_080f1e78,
    (void*)FUN_080f1ef8,
    (void*)FUN_080f2074,
    (void*)FUN_080f2160,
    Bee_StateFlyAroundTarget,
};  // 0x085ADA4C

void Bee_SetHandlerTable8(Bee* p) { (p->e).handlerTables[8] = (void*)sBeeHandlerTable8; }

s32 Bee_UpdateFrame(Bee* p) {
  Bee_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Bee_PostUpdate(p);
  return 1;
}

s32 Bee_Update(Bee* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Bee_Destroy(Bee* p) {
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

// メッセージ表
void (*const sBeeMsgHandlers[7])(Bee*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Bee_OnTargetMsg,
};  // 0x085ADA68

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1756/1918命令, EnemyBat_Init の下書きを Bee 向けに直したもの (呼び出し列は一致), 原典は flags5 の UNK_2 を見る所で印のローカルを使い, Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 Bee_Init(Bee* p) {
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
  (p->e).kind = ENEK_BEE;
  Bee_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_BEE);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_BEE);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_BEE);
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
  if (VM_SeekToNamedArg('P')) {
    p->chargeInterval = VM_GetPC() != NULL ? VM_GetValue() : 104;
    p->chargeCooldown = 0;
    p->curveTimeBase = VM_GetPC() != NULL ? VM_GetValue() : 100;
  }
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
    (p->e).tileIdx = GetCollisionTileIdx(&p->homePos);
    (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &p->homePos);
    (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
    p->spawnHeight = (p->e).heightAboveFloor;
    (p->e).mover.pos.y = (p->e).floorY;
    p->prevFloorY = (p->e).floorY;
  }
  p->target = NULL;
  (p->e).hurtbox.iframes = VM_GetNamedArgValue('n', 0);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 176;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 176;
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

  Bee_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Bee_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Bee_GetMoveSpeed;
  (p->e).handlerTurn = NULL;
  (p->e).handlerMove = Bee_StateFly;
  (p->e).handlerWait = Bee_AnimIdle;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Bee_StateDamaged;
  (p->e).handlerDying = Bee_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = NULL;
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
  (p->e).msgHandlers = (void*)sBeeMsgHandlers;
  (p->e).onReset = (EnemyHandler)Bee_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Bee_OnAttackRequest;
  (p->e).unk_5b0 = NULL;
  (p->e).tryDetectPlayer = (void*)Bee_TryDetectPlayer;
  (p->e).onDamaged = (void*)FUN_080f8400;
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
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  Enemy_InitHandlerTables(&p->e);
  Bee_SetHandlerTable2(p);
  Bee_SetHandlerTable4(p);
  Bee_SetHandlerTable8(p);
  (p->e).unk_1bc = 2;
  (p->e).s->aux.spr.priority = 1;
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
  (p->e).handlerUpdate = (EnemyHandler)Bee_Update;
  (p->e).handlerDestroy = (EnemyHandler)Bee_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Bee_Init.inc");
#endif
}

void Bee_Create(void) {
  Bee* p = Malloc(sizeof(Bee));

  if (p != NULL) {
    ClearMemory(p, sizeof(Bee));
    if (Bee_Init(p) < 0) {
      Bee_Destroy(p);
      Free(p);
    }
  }
}
