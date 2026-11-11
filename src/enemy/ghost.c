#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "spirit_bugs.h"
#include "sprite.h"
#include "vm.h"

// ゴーストの残像, ゴースト自身と同じスプライトを隠した状態で持つ
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxSpriteGfx gfx;       // 0x2C, SPRITE_GHOST
  AuxAnimState anim;      // 0x48
  AuxAnimFile* animFile;  // 0x58, ANIM_GHOST
  u16 timer;              // 0x5C, 0 でなければ毎フレーム減り, 0 になったら隠す
  u8 unk_5e[2];           // 0x5E
} GhostAfterimage;
static_assert(sizeof(GhostAfterimage) == 96);

// Ghost.flags (0x7DC)
typedef u32 GhostFlags;
#define GHOSTFLAG_UNK_0 (1 << 0)       // 0x1
#define GHOSTFLAG_FLEE (1 << 2)        // 0x4, 立っていると体当たりの代わりにプレイヤーから離れる
#define GHOSTFLAG_CHASING (1 << 4)     // 0x10, プレイヤーを追っている, Enemy.chaseTimer の待ちが尽きたら諦めて乱数の経路ノードへ移る
#define GHOSTFLAG_APPEARING (1 << 5)   // 0x20, 現れる途中, 点滅のあと表示して落ちる
#define GHOSTFLAG_VANISHING (1 << 6)   // 0x40, 消える途中, 点滅のあと隠して落ちる
#define GHOSTFLAG_UNK_8 (1 << 8)       // 0x100, '.g' で立つ, 立っていると太陽ゲージの代わりに部屋の明るさ (MPF_BRIGHT) で姿を消すか決める
#define GHOSTFLAG_POSSESSING (1 << 7)  // 0x80, プレイヤーに取り憑いている, その間プレイヤーの speedPenalty を 3 増やしている
#define GHOSTFLAG_UNK_9 (1 << 9)       // 0x200, '.i' で立つ, ENEFLAG3_UNK_14 の間は点滅させずに隠したままにする

// ENEK_GHOST(EV_GHOST, EV_WRAITH)
// プレイヤーに取り憑く, EV_WRAITH は取り憑いたときに混乱も付ける
typedef struct {
  Enemy e;
  u8 unk_654[4];                   // 0x654
  GhostAfterimage afterimages[4];  // 0x658
  u16 nextAfterimage;              // 0x7D8, 次に出す afterimages の番号
  u16 afterimageInterval;          // 0x7DA, 残像を出すフレーム間隔
  GhostFlags flags;                // 0x7DC
  s32 unk_7e0;                     // 0x7E0, 体当たりを始めたときの行き先までの距離の2乗の 1/4
  u8 drainInterval;                // 0x7E4, '.P[0]', 取り憑いている間, このフレーム間隔でプレイヤーの ENE を atkPower[0] ずつ吸う
  u8 escapeMash;                   // 0x7E5, '.P[1]', 振りほどくのに要る連打数
  u16 unk_7e6;                     // 0x7E6
  u16 spawnFloorY;                 // 0x7E8, 出現位置の床の高さ
  u16 curveSpeed;                  // 0x7EA, 曲線の点をたどるときの速さ, だんだん上がる
  Vec3 curvePoints[8];             // 0x7EC, 曲線を 8 等分した点
  Vec3 curvePointsEnd;             // 0x82C, curvePoints の曲線の終点
  u8 curvePointIdx;                // 0x834, curvePoints の今向かっている点の番号
  u8 unk_835;                      // 0x835
  u16 blinkTimer;                  // 0x836, 現れる / 消える点滅の経過フレーム
  u16 curveT;                      // 0x838
  u8 hoverPhase;                   // 0x83A, 上下の揺れの sin の位相
  s8 curveBendDir;                 // 0x83B, curveBend を増やす向き, 1 か -1
  s16 curveBend;                   // 0x83C, 曲線のふくらみ, -320〜320 を往復する
  u8 chaseCooldown;                // 0x83E, 追い始めてから次に判定するまでの待ち, 10 から数え下ろす
  u8 visibleTimer;                 // 0x83F, 残っている間は姿を見せる, 取り憑いたときに 3
  u8 solarBugAmount;               // 0x840, '.P[2]', 倒されたときに落とす太陽虫の量
  u8 mashCount;                    // 0x841, 取り憑いてからの連打数
  u8 mashBase;                     // 0x842, 取り憑いたときの Player.mashCount
  u8 unk_843;                      // 0x843
  u16 talkScriptID;                // 0x844, '.d[0]', 0 でなければ話しかけられる, A ボタンで流すスクリプト
  u32 talkDistSq;                  // 0x848, '.d[1]' の2乗, 話しかけられる距離の2乗
  NavAgent navAgent;               // 0x84C, Enemy.navAgent が指す
  Vec3 pathNodePos;                // 0x870, Enemy.pathNodePos が指す
  WorldPos curveStart;             // 0x878, 曲線の始点
  Vec3 curveEnd;                   // 0x880, 曲線の終点
  Vec3 curveTangent;               // 0x888, 曲線の始点の接線, x と z を 128 倍して使う, 曲線移動を始めるときに 0 に戻す
  WorldPos prevPlayerPos;          // 0x890, 前のフレームのプレイヤーの位置, 動いたかどうかの判定に使う
} Ghost;
static_assert(sizeof(Ghost) == 2200);

const STRING_DATA char s_eneinline_0825212c[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252144[] = "../system/eneinline.h";
const STRING_DATA char s_ghostcom_c_0825215c[] = "ghostcom.c";

extern s32 gLightningTimer;

void Ghost_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Ghost_StartCurve(Ghost* p, Vec3* pos);
void Ghost_BeginCurveTo(Ghost* p, Vec3* pos);
void Ghost_UpdateCurveBend(Ghost* p);
void Ghost_BuildCurvePoints(Ghost* p, Vec3* pos);
void Ghost_SpawnAfterimage(Ghost* p);
bool8 Ghost_StepCurve(Ghost* p);
bool8 Ghost_PickRandomPathNode(Ghost* p);
void Ghost_RestorePlayerSpeed(Ghost* p);
void Ghost_StopChase(Ghost* p);
void Ghost_ResumeHover(Ghost* p);
void Ghost_StateWaitAtNode(Ghost*);
void Ghost_StateDrift(Ghost*);
void Ghost_StateMoveToNode(Ghost*);
void Ghost_StateFlungOff(Ghost*);
void Ghost_StateRam(Ghost*);

void (*const sGhostHandlerTable2[5])(Ghost*) = {
    Ghost_StateWaitAtNode,
    Ghost_StateDrift,
    Ghost_StateMoveToNode,
    Ghost_StateFlungOff,
    Ghost_StateRam,
};  // 0x085ADA84

void Ghost_StatePossess(Ghost*);
void FUN_0816e3b8(Ghost*);
void Ghost_StateCirclePlayer(Ghost*);

void (*const sGhostHandlerTable4[3])(Ghost*) = {
    Ghost_StatePossess,
    FUN_0816e3b8,
    Ghost_StateCirclePlayer,
};  // 0x085ADA98

void FUN_0816ec60(Ghost*);
void FUN_0816ed04(Ghost*);

void (*const sGhostHandlerTable3[2])(Ghost*) = {
    FUN_0816ec60,
    FUN_0816ed04,
};  // 0x085ADAA4

void Ghost_StateWaitTalk(Ghost*);

void (*const sGhostHandlerTable8[6])(Ghost*) = {
    Ghost_StateWaitTalk,
    (void*)FUN_080f1e0c,
    (void*)FUN_080f1e78,
    (void*)FUN_080f1ef8,
    (void*)FUN_080f2074,
    (void*)FUN_080f2160,
};  // 0x085ADAAC

void Ghost_OnDetachMsg(Ghost*, u16*);
void Ghost_OnAppearMsg(Ghost*, u16*);

// メッセージ表
void (*const sGhostMsgHandlers[8])(Ghost*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Ghost_OnDetachMsg,
    Ghost_OnAppearMsg,
};  // 0x085ADAC4

void FUN_0816a9b4(void) {}

static inline bool32 IsPlayerMini(void) {
  u16 timer = gGoodCondTimer;

  return timer != 0 && gGoodCondID == GOOD_MINI;
}

static inline bool8 Ghost_TestFlags(Ghost* p, GhostFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

// flags のアドレスを受ける版, Ghost_ResumeHover はこちらでないと q->flags のアドレスの使い回しが合わない
static inline bool8 Ghost_TestFlagsAt(GhostFlags* flags, GhostFlags bit) {
  if (*flags & bit) return TRUE;
  return FALSE;
}

// 攻撃がプレイヤーに当たったら取り憑く, 判定を隠してプレイヤーを遅くし, 3 フレームだけ姿を見せる
// 109/108命令, 残差は 2 つの判定に HBFLAG_HIDDEN を立てる所のレジスタと命令数だけ, 試済: Hitbox_SetFlags と直書き, TEST_FLAGS / Enemy_GetFlag3, 取り憑き中の判定が空の if で残る形
NON_MATCH void Ghost_OnHit(HitboxData* a, HitboxData* b, Ghost* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && !Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_14) && b->ignoreMask == HIM_0) {
    Ghost* q = (p->e).owner;

    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 2, 0);
    Hitbox_SetFlags(&(p->e).hitbox, HBFLAG_HIDDEN);
    Hitbox_SetFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8);
    if (Ghost_TestFlags(q, GHOSTFLAG_POSSESSING)) {
    }
    gPlayerPtr[0]->speedPenalty += 3;
    SET_FLAGS(q->flags, GHOSTFLAG_POSSESSING);
    q->visibleTimer = 3;
    PlaySound_082406e0(SONG_971);
  }
#else
  INCFUNC("asm/func/Ghost_OnHit.inc");
#endif
}

// 食らい判定, ENEFLAG3_UNK_14 の間は食らわない, あとは敵共通の処理
// 774/774命令, 残差は先頭で見た flags3 のアドレスを Enemy_HandleHurt の中でも使い回す点 (EnemyBat_OnHurt / Crow_OnHurt と同じ共通 inline の壁), 試済: TEST_FLAGS / Enemy_GetFlag3 / & の直書き
NON_MATCH void Ghost_OnHurt(HitboxData* a, HitboxData* b, Ghost* p) {
#ifdef NONMATCHING_C
  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).flags3 & ENEFLAG3_UNK_14) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_UNK_11)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Ghost_OnHurt.inc");
#endif
}

// 取り憑いている間, プレイヤーの ENE を吸い (EV_WRAITH は混乱も付ける), 連打が escapeMash を超えたら振りほどかれる
// 225/234命令, 前半は EnemyBat の FUN_0813f320 と同じ壁 (Enemy_PlayAnim の展開), 試済: 連打数の差の書き方 2 通り
NON_MATCH void Ghost_StateDrainPlayer(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  u32 dir;
  u32 flip;
  u32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
    q->mashBase = gPlayerPtr[0]->mashCount;
    q->unk_7e6 = 0;
    (p->e).animSpeedDiv = 4;
  }
  Ghost_GetAnimVariant((p->e).mover.angle, &dir, &flip);
  anim = (p->e).animTable[1].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, dir, flip);
    (p->e).animForceRestart = FALSE;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = anim + dir;

    if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flip == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (flip & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (flip & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
      (p->e).animForceRestart = FALSE;
    }
  }
  if ((p->e).variant == EV_GHOST) {
    if (Mod((p->e).stateTimer, q->drainInterval) == 0) {
      Player_ReduceENE(gPlayerPtr[0], (p->e).atkPower[0]);
    }
  } else if ((p->e).variant == EV_WRAITH) {
    if (Mod((p->e).stateTimer, q->drainInterval) == 0) {
      Player_ReduceENE(gPlayerPtr[0], (p->e).atkPower[0]);
    }
    if (gPlayerPtr[0] != NULL) {
      Player_ApplyBadCondition(gPlayerPtr[0], BAD_CONFUSE, 900);
    }
  }
  {
    s32 base = q->mashBase;
    s32 count = gPlayerPtr[0]->mashCount;
    s32 n;

    if (count < base) {
      n = count - (base - 256);
    } else {
      n = count - base;
    }
    if (q->mashCount != n) {
      if (Mod(q->mashCount, 4) == 0) {
        SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
      }
      q->mashCount = n;
    }
  }
  if (q->mashCount > q->escapeMash) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/Ghost_StateDrainPlayer.inc");
#endif
}

// 向きに合わせて animTable[1] のアニメを流す
// 106/109命令, Curoro の FUN_0813ac34 と同じ壁 (再生部の展開で定数 4 を r8 に置く), 試済: Curoro の C をそのまま
NON_MATCH void Ghost_StateFly(Ghost* p) {
#ifdef NONMATCHING_C
  u32 variant, flags;
  s32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Ghost_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  anim = (p->e).animTable[1].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
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
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = 0;
#else
  INCFUNC("asm/func/Ghost_StateFly.inc");
#endif
}

// 歩きアニメを等速で流してから, 向きに合わせて animTable[1] のアニメを流す
// 113/121命令, Curoro の FUN_0813ad64 と同じ壁 (再生部の展開で定数 4 を r8 に置く), 試済: Curoro の C をそのまま
NON_MATCH void Ghost_StateWait(Ghost* p) {
#ifdef NONMATCHING_C
  u32 variant, flags;
  s32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
    (p->e).animSpeedDiv = 1;
  }
  Enemy_PlayAnim(&p->e, 1);
  Ghost_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  anim = (p->e).animTable[1].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s = &(p->e).s->aux;

    (p->e).playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
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
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = 0;
#else
  INCFUNC("asm/func/Ghost_StateWait.inc");
#endif
}

// 向きを unk_1dc の8方向へ 32 ずつ回し, 揃ったら待機へ移る
// 279/284命令, Curoro の FUN_0813ae6c と同じ残差 (後半のアニメ再生と mover / anim のアドレスの持ち越し), 試済: Curoro の C をそのまま
NON_MATCH void Ghost_StateTurn(Ghost* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 cur = Angle_ToDir8((p->e).mover.angle);
    s32 target = Angle_ToDir8((p->e).unk_1dc);

    if (cur == target) {
      (p->e).mover.angle = (p->e).unk_1dc;
      Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
      (p->e).subStateDone = 1;
      return;
    }
    if (((cur - (target - 8)) & 7) <= 4) {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    } else {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    }
  }
  sprite = &(p->e).s->aux.spr;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).stateTimer & 4) {
    s32 anim;

    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      (p->e).mover.angle += 32;
    } else {
      (p->e).mover.angle -= 32;
    }
    Ghost_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    sprite->unk_05 = 0;
    anim = (p->e).animTable[1].anim;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s = &(p->e).s->aux;

      (p->e).playingAnim = anim;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
    } else {
      MainSprite* s = &(p->e).s->main.spr;
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
      MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
      if (flags & ANIM_PLAY_XFLIP) {
        s->flags |= SPRFLAG_XFLIP;
      } else {
        s->flags &= ~SPRFLAG_XFLIP;
      }
    }
    (p->e).animForceRestart = 0;
  }
#else
  INCFUNC("asm/func/Ghost_StateTurn.inc");
#endif
}

// 向きに合わせて animTable[11] のアニメを流し, 30 フレーム未満は ENEFLAG4_UNK_5 を立て, 60 フレームで副状態を終える
// 124/129命令, EnemyBat の FUN_0813f320 と同じ壁 (Enemy_PlayAnim の展開), 試済: FUN_0813f320 の C をそのまま
NON_MATCH void FUN_0816b880(Ghost* p, s32 timer) {
#ifdef NONMATCHING_C
  u32 dir;
  u32 flip;
  u32 anim;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Ghost_GetAnimVariant((p->e).mover.angle, &dir, &flip);
  anim = (p->e).animTable[11].anim;
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, dir, flip);
    (p->e).animForceRestart = FALSE;
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 a = anim + dir;

    if ((p->e).playingAnim != a || (p->e).animForceRestart || !((flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flip == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (flip & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
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
  INCFUNC("asm/func/FUN_0816b880.inc");
#endif
}

void Ghost_AnimFlungOff(Ghost* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 16);
  }
  if (timer < 30) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (timer > 59) {
    (p->e).subStateDone = 1;
  }
}

// 吹き飛ばされた先へ寄りながら, 燃えていれば煙を出す, 止まったら取り憑きを解いて浮遊に戻り追跡を始める
// 253/252命令, 原典は flags3 のアドレスを状態に入った直後の判定より前に作って後でも使い回す, 試済: flags3 のポインタのローカル, Enemy_ConsumeStateBegun を直書き
NON_MATCH void Ghost_StateDamaged(Ghost* p, s32 timer) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_PlayAnim(&p->e, 3);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3)) {
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
      PlaySound_082406e0(SE_UNK_298);
    } else {
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
    }
    Ghost_StopChase(p);
    Ghost_ResumeHover(p);
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_3) && Mod(timer, 12) == 0) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 128, 10, 6, 2, 2);
  }
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    Ghost_RestorePlayerSpeed(p);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3 | ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Ghost_ResumeHover(p);
    SET_FLAGS(q->flags, GHOSTFLAG_CHASING);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    Enemy_ResetState(&p->e, 0, 2, 2);
  }
#else
  INCFUNC("asm/func/Ghost_StateDamaged.inc");
#endif
}

// 倒れるアニメを流し, 取り憑きを解いて太陽虫を落とし, 終わったら倒されたときのスクリプトを流して動きを止める
// 252/253命令, 残差は倒されたときのスクリプトの引数を原典は sp+0x24 から直接書くがこちらは配列の先頭を別のレジスタに置く点, 試済: argv / sa / pos の宣言位置, 初期化子, count のローカル
NON_MATCH void Ghost_StateDying(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    Ghost_RestorePlayerSpeed(p);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
      Vec3 pos[3];
      s32 count = Mod(Random(), 3) + 1;
      s32 i;

      for (i = 0; i < 3; i++) {
        pos[i].x = (p->e).mover.pos.x;
        pos[i].y = (p->e).mover.pos.y;
        pos[i].z = (p->e).mover.pos.z;
      }
      SpawnSpiritBugsAt(count, SOLARBUG, q->solarBugAmount, &(p->e).mover.pos, pos, 300, 120);
    }
  }
  if ((p->e).animForceRestart) {
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
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 1, 0, 2);
    }
  }
#else
  INCFUNC("asm/func/Ghost_StateDying.inc");
#endif
}

// 経路の目的地へ曲線で飛び, 着いたら勢いを curveTangent に残して乱数で選んだ次のノードへ向かう
void Ghost_StateMoveToNode(Ghost* p) {
  Ghost* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Vec3_Clear(&q->curveTangent);
    q->curveBendDir = 1;
    (p->e).animSpeedDiv = 1;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  Ghost_UpdateCurveBend(p);
  if (Enemy_StepToDest(&p->e, speed) && Ghost_StepCurve(p)) {
    Vec3_SetPolar(&q->curveTangent, (p->e).mover.angle, speed);
    if (Ghost_PickRandomPathNode(p)) {
      WorldPos pos;
      WorldPos* dst = &pos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Ghost_BeginCurveTo(p, &pos);
    }
  }
  (p->e).subStateTimer++;
}

// curveTangent の勢いのまま流れ, 勢いを 4 フレームごとに半分にする
void Ghost_StateDrift(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  (p->e).mover.delta.x += q->curveTangent.x;
  (p->e).mover.delta.z += q->curveTangent.z;
  if (Mod((p->e).subStateTimer, 4) == 0) {
    q->curveTangent.x >>= 1;
    q->curveTangent.z >>= 1;
  }
  if ((p->e).subStateDone) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Enemy_ResetState(&p->e, 0, 2, 1);
    } else {
      Enemy_ResetState(&p->e, 0, 0, 0);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

// 経路ノードで 60 フレーム待ってから, 乱数で選んだノードへ曲線移動を始める
void Ghost_StateWaitAtNode(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    q->hoverPhase = 0;
  }
  if ((p->e).subStateTimer > 60) {
    Ghost_PickRandomPathNode(p);
    {
      WorldPos pos;
      WorldPos* dst = &pos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Ghost_StartCurve(p, &pos);
      Ghost_StepCurve(p);
      Enemy_ResetState(&p->e, 0, 0, 2);
      Vec3_Diff(&pos, &pos, &(p->e).mover.pos);
      (p->e).unk_1dc = ArcTan2_8(pos.x, pos.z);
      Vec3_Clear(&q->curveTangent);
    }
  }
  (p->e).subStateTimer++;
}

// 振りほどかれて乱数の向きへ飛ばされ, 止まったら乱数で選んだ経路ノードへ曲線移動を始める
// 236/236命令, 残差は乱数の表の先頭を置くレジスタ番号 (r1 と原典 r6) だけ, EnemyBat の FUN_08140eb0 と同じ壁, 試済: r の宣言位置, 副状態の終わりの if の向き
NON_MATCH void Ghost_StateFlungOff(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    u8 r;

    Enemy_EnterState(&p->e, Ghost_AnimFlungOff, ES_UNK_35);
    Ghost_RestorePlayerSpeed(p);
    r = Random();
    Vec3_Clear(&q->curveTangent);
    (p->e).jumpVel.x = FixToInt(12, SIN(r) * 64);
    (p->e).jumpVel.z = FixToInt(12, COS(r) * 64);
    (p->e).mover.angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z) + 128;
  }
  if ((p->e).subStateDone) {
    Ghost_StopChase(p);
    Vec3_Clear(&(p->e).jumpVel);
    Enemy_ResetState(&p->e, 0, 0, 2);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Ghost_PickRandomPathNode(p);
    {
      WorldPos pos;
      WorldPos* dst = &pos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Ghost_BeginCurveTo(p, &pos);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Ghost_StateFlungOff.inc");
#endif
}

// プレイヤーへ曲線で体当たりする (GHOSTFLAG_FLEE なら逆へ離れる), たどる間は攻撃判定を出し, だんだん速くなる
// 572/574命令, 残差はレジスタの割り当て (原典は d のアドレスを副状態に入った直後の判定の合流点で作って r8 に置く, Ghost_StateDamaged と同じ), 試済: d / q の宣言順, 点に着いたときの判定を先に置く形 (原典の並びと逆になる)
NON_MATCH void Ghost_StateRam(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    WorldPos dest;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    if (!Ghost_TestFlags(q, GHOSTFLAG_FLEE)) {
      dest = gPlayerPtr[0]->mover.pos;
    } else {
      u32 angle = ((p->e).playerAngle + (Random() & 63) + 128) & 0xFF;

      dest.y = (p->e).mover.pos.y;
      dest.x = (p->e).mover.pos.x + POLAR_X(728, angle);
      dest.z = (p->e).mover.pos.z + POLAR_Z(728, angle);
    }
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    q->unk_7e0 = FixToInt(2, d.x * d.x + d.z * d.z);
    Vec3_SetPolar(&q->curveTangent, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 32);
    Ghost_BuildCurvePoints(p, &dest);
    q->curveSpeed = 1;
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).animSpeedDiv = 2;
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  if (!Ghost_TestFlags(q, GHOSTFLAG_FLEE)) {
    (p->e).hitbox.flags &= ~HBFLAG_HIDDEN;
  }
  Ghost_SpawnAfterimage(p);
  if (d.x * d.x + d.z * d.z > 1024) {
    (p->e).mover.angle = ArcTan2_8(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z);
    Vec3_SetPolar(&d, (p->e).mover.angle, q->curveSpeed);
    (p->e).mover.delta.x += d.x;
    (p->e).mover.delta.z += d.z;
    q->curveTangent = (p->e).mover.delta;
  } else if (++q->curvePointIdx > 8) {
    (p->e).mover.pos.x = q->curvePointsEnd.x;
    (p->e).mover.pos.z = q->curvePointsEnd.z;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).hitbox.flags |= HBFLAG_HIDDEN;
    if (Ghost_TestFlags(q, GHOSTFLAG_FLEE)) {
      Enemy_ResetState(&p->e, 0, 0, 0);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      CLEAR_FLAGS(q->flags, GHOSTFLAG_FLEE);
      return;
    }
    Enemy_ResetState(&p->e, 0, 2, 1);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    return;
  }
  if ((p->e).variant == EV_GHOST) {
    if (Mod((p->e).subStateTimer, 8) == 0 && q->curveSpeed < 20) {
      q->curveSpeed += 1;
    }
  } else {
    if (Mod((p->e).subStateTimer, 4) == 0 && q->curveSpeed < 20) {
      q->curveSpeed += 2;
    }
  }
#else
  INCFUNC("asm/func/Ghost_StateRam.inc");
#endif
}

void Ghost_SetHandlerTable2(Ghost* p) { (p->e).handlerTables[2] = (void*)sGhostHandlerTable2; }

// プレイヤーに取り憑いている間に受けると, 離れて動きを止める
void Ghost_OnDetachMsg(Ghost* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && Ghost_TestFlags((p->e).owner, GHOSTFLAG_POSSESSING)) {
    Enemy_ResetState(&p->e, 0, 0, 3);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
  }
}

// 姿が隠れているときに受けると, 点滅しながら現れ始める
// 71/70命令, 原典は GHOSTFLAG_APPEARING を見たときの q->flags のアドレスを後の書き換えで使い回す, 試済: Ghost_TestFlags / Ghost_TestFlagsAt / TEST_FLAGS, CLEAR/SET を &= ~ と |= に
NON_MATCH void Ghost_OnAppearMsg(Ghost* p, u16* msg) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14) && !Ghost_TestFlagsAt(&q->flags, GHOSTFLAG_APPEARING)) {
    if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
      q->blinkTimer = 0;
      q->flags &= ~(GHOSTFLAG_VANISHING | GHOSTFLAG_UNK_9);
      q->flags |= GHOSTFLAG_APPEARING;
      PlaySound_082406e0(SE_GHOST_542);
    }
  }
#else
  INCFUNC("asm/func/Ghost_OnAppearMsg.inc");
#endif
}

// プレイヤーの 220 上 (小人かマウスなら 100 上) の高さへ 1/10 ずつ寄せる, ES_UNK_34 以外では上下に揺らす
void Ghost_FollowPlayerHeight(Ghost* p) {
  Ghost* q = (p->e).owner;
  s32 height = (IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_MOUSE) ? 100 : 220;
  s32 y;

  if ((p->e).state == ES_UNK_34) {
    y = gPlayerPtr[0]->mover.pos.y + height;
    (p->e).mover.pos.y += Div(y - (p->e).mover.pos.y, 10);
  } else {
    y = gPlayerPtr[0]->mover.pos.y + height + FixToInt(12, SIN(q->hoverPhase) * 32);
    (p->e).mover.pos.y += Div(y - (p->e).mover.pos.y, 10);
    q->hoverPhase += 2;
  }
}

void Ghost_UpdateCurveBend(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (q->curveBend > 320) {
    q->curveBendDir = -1;
    q->curveBend = 320;
  } else if (q->curveBend < -320) {
    q->curveBendDir = 1;
    q->curveBend = -320;
  }
  q->curveBend += q->curveBendDir * 12;
}

bool8 Ghost_PickRandomPathNode(Ghost* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx;

  if (walker->path->nodeCount <= 1) {
    return FALSE;
  }
  idx = Mod(Random(), walker->path->nodeCount);
  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
  return TRUE;
}

void Ghost_InitHitboxes(Ghost* p) {
  Vec3 size, offset;
  HitboxFlags32 flags;

  VEC3_SET(size, 16, 64, 16);
  VEC3_SET(offset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &size, &offset, Ghost_OnHurt, p);
  VEC3_SET(size, 24, 64, 24);
  VEC3_SET(offset, 0, 0, 0);
  flags = HBFLAG_HITBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0;
  Hitbox_Init(&(p->e).hitbox, (p->e).mover.id, flags, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(&(p->e).hitbox, 0, 0, 0, 0, 0);
  Hitbox_SetPos(&(p->e).hitbox, &(p->e).mover.pos, 0);
  Hitbox_SetHandler(&(p->e).hitbox, Ghost_OnHit, p);
}

s32 Ghost_GetMoveSpeed(Ghost* p) { return 4; }

void Ghost_StartCurve(Ghost* p, Vec3* pos) {
  Ghost* q = (p->e).owner;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
  q->curveT = 0;
}

// curveStart から curveEnd への曲線上の curveT の位置を経路の目的地に置き, curveT を 128 進める, 終点に着いていたら TRUE
// 199/200命令, Bee_StepCurve / EnemyBat_StepCurve / Curoro_StepCurve と同じ壁 (原典はフレーム 0x34, こちらは 0x28), 試済: 末尾の curveT の判定の向き
NON_MATCH bool8 Ghost_StepCurve(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
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
  if (q->curveT >= 1024) {
    return TRUE;
  }
  q->curveT += 128;
  return FALSE;
#else
  INCFUNC("asm/func/Ghost_StepCurve.inc");
#endif
}

void Ghost_InitAnims(Ghost* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 2, 0, 0);
  Enemy_SetAnimEntry(&p->e, 3, 2, 0);
  Enemy_SetAnimEntry(&p->e, 15, 0, 0);
  Enemy_SetAnimEntry(&p->e, 16, 3, 0);
  Enemy_SetAnimEntry(&p->e, 11, 0, 0);
  Enemy_SetAnimEntry(&p->e, 10, 1, 0);
}

// 復帰時に作業値とフラグを初期値に戻し, 待機アニメを流して1コマ送る
// 191/192命令, 残差は Enemy_ClearPendingState の引数を積む順 (原典は文字列が先) と, sprite を r0 に読んでから r5 に写す点, 試済: aux のスコープと宣言位置, sprite を直接渡す, Enemy* を取る送りの inline
NON_MATCH void Ghost_OnReset(Ghost* p) {
#ifdef NONMATCHING_C
  EnemyAuxSprite* aux;
  Ghost* q = (p->e).owner;

  q->curveT = 0;
  q->hoverPhase = 0;
  q->curveBendDir = 1;
  q->curveBend = 0;
  q->mashCount = 0;
  q->mashBase = 0;
  q->flags = (p->e).ownerFlagsInit;
  q->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->curveTangent);
  ClearMemory((p->e).pathNodePos, sizeof(Vec3));
  Enemy_ClearPendingState(&p->e, s_ghostcom_c_0825215c, 300);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/Ghost_OnReset.inc");
#endif
}

// 浮遊 (ENEFLAG2_UNK_20) に戻して食らい判定を出し, 遅くしていたプレイヤーの速さを戻す
void Ghost_ResumeHover(Ghost* p) {
  Ghost* q = (p->e).owner;

  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS(q->flags, GHOSTFLAG_UNK_0 | GHOSTFLAG_CHASING);
  (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
  if (Ghost_TestFlagsAt(&q->flags, GHOSTFLAG_POSSESSING)) {
    gPlayerPtr[0]->speedPenalty -= 3;
    CLEAR_FLAGS(q->flags, GHOSTFLAG_POSSESSING);
  }
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void Ghost_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

void Ghost_BeginCurveTo(Ghost* p, Vec3* pos) {
  Ghost* q = (p->e).owner;
  Vec3 diff;

  Ghost_StartCurve(p, pos);
  Ghost_StepCurve(p);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&diff, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(diff.x, diff.z);
  Vec3_Clear(&q->curveTangent);
}

void Ghost_StopChase(Ghost* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  CLEAR_FLAGS(((Ghost*)(p->e).owner)->flags, GHOSTFLAG_CHASING);
  (p->e).chaseTimer = 0;
}

void Ghost_UpdateChaseTimeout(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8)) {
    return;
  }
  if (!Ghost_TestFlags(q, GHOSTFLAG_CHASING)) {
    (p->e).chaseTimer = 0;
    return;
  }
  if ((p->e).chaseTimer != 0) {
    (p->e).chaseTimer--;
    return;
  }
  Ghost_PickRandomPathNode(p);
  {
    WorldPos pos;
    WorldPos* dst = &pos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    Ghost_BeginCurveTo(p, &pos);
    Ghost_StopChase(p);
    Ghost_ResumeHover(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

// 近くで高さの近いプレイヤーが動いたら追い始める, 既に追っていればプレイヤーに ENE があるときだけ取り憑きに行く
// 199/198命令, 残差は GHOSTFLAG_CHASING を見たときの q->flags のアドレスを後の SET で使い回す点 (Ghost_OnAppearMsg と同じ壁), 試済: Ghost_TestFlags / Ghost_TestFlagsAt, flags のポインタのローカル, SET_FLAGS / |=, Vec3_Diff / Vec3_Delta
NON_MATCH void Ghost_DetectMovingPlayer(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q;
  Vec3 d;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_5)) {
    return;
  }
  q = (p->e).owner;
  Vec3_Delta(&d, &q->prevPlayerPos, &gPlayerPtr[0]->mover.pos);
  q->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  if (q->chaseCooldown != 0) {
    q->chaseCooldown--;
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if (d.x == 0 && d.z == 0) {
    return;
  }
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    return;
  }
  (p->e).flags &= ~ENEFLAG_UNK_3;
  if (abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y) > 512) {
    return;
  }
  if ((p->e).playerDistSq >= (p->e).range0Sq) {
    return;
  }
  if (Ghost_TestFlagsAt(&q->flags, GHOSTFLAG_CHASING)) {
    if (gPlayerPtr[0]->ene == 0) {
      return;
    }
    Enemy_ResetState(&p->e, 0, 0, 4);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    return;
  }
  SET_FLAGS(q->flags, GHOSTFLAG_CHASING);
  Enemy_ResetState(&p->e, 0, 2, 1);
  (p->e).chaseTimer = (p->e).chaseTimeMax;
  q->chaseCooldown = 10;
#else
  INCFUNC("asm/func/Ghost_DetectMovingPlayer.inc");
#endif
}

bool8 Ghost_TryDetectPlayer(Ghost* p) { return FALSE; }

void Ghost_OnAttackRequest(Ghost* p) {}

void Ghost_SetAfterimagePltt(Ghost* p, rgb555* pltt) {
  Ghost* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    q->afterimages[i].gfx.pltt = pltt;
  }
}

void Ghost_InitAfterimages(Ghost* p) {
  Ghost* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    Video_GetAuxSprite(&q->afterimages[i].gfx, SPRITE_GHOST);
    AuxSprite_Add(&q->afterimages[i].sprite, &q->afterimages[i].gfx, 0);
    Video_SetAuxSpritePltt(&q->afterimages[i].gfx, 384);
    q->afterimages[i].animFile = GetFile(DIR_ANIMATION, ANIM_GHOST);
    q->afterimages[i].sprite.flags = SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    q->afterimages[i].timer = 0;
  }
  q->nextAfterimage = 0;
  q->afterimageInterval = 2;
}

// afterimageInterval フレームごとに, 今のアニメと位置を次の残像へ写して 8 フレーム見せる
void Ghost_SpawnAfterimage(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (Mod((p->e).unk_1ca, q->afterimageInterval) == 0) {
    u32 variant, flip;
    AuxAnimState* anim;
    u16 animIdx;

    Ghost_GetAnimVariant((p->e).mover.angle, &variant, &flip);
    anim = &(p->e).s->aux.anim;
    animIdx = anim->animIdx;
    AuxAnim_SetAnim(&q->afterimages[q->nextAfterimage].anim, q->afterimages[q->nextAfterimage].animFile, animIdx, variant, flip);
    AuxSprite_AdvanceAnim(&q->afterimages[q->nextAfterimage].sprite, &q->afterimages[q->nextAfterimage].anim);
    q->afterimages[q->nextAfterimage].sprite.pos = (p->e).mover.pos;
    q->afterimages[q->nextAfterimage].sprite.flags &= ~SPRFLAG_HIDDEN;
    q->afterimages[q->nextAfterimage].timer = 8;
    if (++q->nextAfterimage > 3) {
      q->nextAfterimage = 0;
    }
  }
}

// 残像の表示時間を減らし, 尽きたものを隠す
void Ghost_TickAfterimages(Ghost* p) {
  Ghost* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (q->afterimages[i].timer != 0 && --q->afterimages[i].timer == 0) {
      q->afterimages[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
}

void Ghost_RemoveAfterimages(Ghost* p) {
  Ghost* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    AuxSprite_Remove(&q->afterimages[i].sprite);
  }
}

// 今の位置から pos への曲線を 8 等分した点を curvePoints に求め, 終点を curvePointsEnd に置く
// 239/231命令, Bee_BuildCurvePoints と同じ壁 (原典は start/end/d/v を sp+4 から置く), 試済: Bee_BuildCurvePoints の C をそのまま
NON_MATCH void Ghost_BuildCurvePoints(Ghost* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  WorldPos start, end;
  Vec3 d, v;
  Vec3* dst;
  s32 step, k0, k1, i, t, t2, t3, m, n;

  start = (p->e).mover.pos;
  end = *pos;
  start.y = 0;
  end.y = 0;
  step = Div(1024, 8);
  k0 = q->curveTangent.x << 7;
  k1 = q->curveTangent.z << 7;
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
  INCFUNC("asm/func/Ghost_BuildCurvePoints.inc");
#endif
}

// 現れる / 消える途中なら点滅させ, 30 フレームで表示か非表示に決める
// 98/98命令, 残差は q を r5 に置く点と, u16 の t を lsls/lsrs で広げて >>18 にまとめる点, 試済: 判定の並び, 点滅の共通化を goto で, blinkTimer を s16 に
NON_MATCH void Ghost_UpdateBlink(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q;
  u16 t;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  q = (p->e).owner;
  if (!Ghost_TestFlags(q, GHOSTFLAG_APPEARING | GHOSTFLAG_VANISHING)) {
    return;
  }
  if (IsLinkPlay()) {
  }
  t = q->blinkTimer;
  if (t < 20) {
    t >>= 2;
    if (t & 1) {
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    } else {
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    }
  } else if (t < 30) {
    t >>= 1;
    if (t & 1) {
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    } else {
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    }
  } else if (Ghost_TestFlags(q, GHOSTFLAG_APPEARING)) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    CLEAR_FLAGS(q->flags, GHOSTFLAG_APPEARING);
  } else {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    CLEAR_FLAGS(q->flags, GHOSTFLAG_VANISHING);
  }
  q->blinkTimer++;
#else
  INCFUNC("asm/func/Ghost_UpdateBlink.inc");
#endif
}

// visibleTimer が残っている間は姿を見せる
void Ghost_TickVisibleTimer(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e)) {
    if (IsLinkPlay()) {
    }
    if (q->visibleTimer != 0) {
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
      q->visibleTimer--;
    }
  }
}

void Ghost_RestorePlayerSpeed(Ghost* p) {
  if (Ghost_TestFlags((p->e).owner, GHOSTFLAG_POSSESSING)) {
    gPlayerPtr[0]->speedPenalty -= 3;
    CLEAR_FLAGS(((Ghost*)(p->e).owner)->flags, GHOSTFLAG_POSSESSING);
  }
}

// 太陽ゲージが 1 以上なら消え始め, 0 なら現れ始める (雷の間と千里眼の実の効果中は見える), 続けて点滅や追跡の判定と高さ合わせを行う
// 257/258命令, 残差は千里眼の実の判定で TRUE / FALSE を作る形と, 攻撃判定に HBFLAG_HIDDEN を立てる ldrh の位置, 試済: Hitbox_SetFlags, 枝の向き, 明るさの s16 / s32, 空の IsLinkPlay 判定, see を FALSE で始める形
NON_MATCH s32 Ghost_PreUpdate(Ghost* p) {
#ifdef NONMATCHING_C
  Hitbox_SetFlags(&(p->e).hitbox, HBFLAG_HIDDEN);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
    if (Ghost_TestFlags((p->e).owner, GHOSTFLAG_UNK_9)) {
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
      CLEAR_FLAGS(((Ghost*)(p->e).owner)->flags, GHOSTFLAG_APPEARING);
    } else {
      Ghost_UpdateBlink(p);
    }
  } else {
    Ghost* q = (p->e).owner;

    if (!Enemy_IsDead(&p->e)) {
      s32 light;
      bool32 see;

      if (IsLinkPlay()) {
      }
      if (Ghost_TestFlags(q, GHOSTFLAG_UNK_8)) {
        light = TestMapFlag(MPF_BRIGHT) ? 1 : 0;
      } else {
        light = gStat->sunGauge;
      }
      if (light < 1) {
        see = TRUE;
      } else if (gGameFlags & GAMEFLAG_LINK) {
        see = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
      } else if (gLightningTimer > 0 || gStat->playerKind == 2) {
        see = TRUE;
      } else {
        see = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
      }
      if (see) {
        if (!Ghost_TestFlags(q, GHOSTFLAG_APPEARING) && Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
          q->blinkTimer = 0;
          q->flags = (q->flags & ~GHOSTFLAG_VANISHING) | GHOSTFLAG_APPEARING;
        }
      } else {
        if (!Ghost_TestFlags(q, GHOSTFLAG_VANISHING) && !Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
          q->blinkTimer = 0;
          q->flags = (q->flags & ~GHOSTFLAG_APPEARING) | GHOSTFLAG_VANISHING;
        }
      }
    }
    Ghost_UpdateBlink(p);
    Ghost_TickVisibleTimer(p);
    Ghost_UpdateChaseTimeout(p);
    Ghost_DetectMovingPlayer(p);
  }
  Ghost_FollowPlayerHeight(p);
  return 1;
#else
  INCFUNC("asm/func/Ghost_PreUpdate.inc");
#endif
}

// 残像を進め, 当たり判定を今の位置に合わせて登録する
s32 Ghost_PostUpdate(Ghost* p) {
  Ghost_TickAfterimages(p);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_5)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_4 | ENEFLAG3_UNK_8) || (Enemy_HasTargetNearby(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2))) {
      if (!((p->e).hitbox.flags & HBFLAG_HIDDEN)) {
        Hitbox_SetPos(&(p->e).hitbox, &(p->e).mover.pos, 0);
        Hitbox_Register(&(p->e).hitbox);
      }
    }
    Hitbox_SetPos(&(p->e).hurtbox, &(p->e).mover.pos, 0);
  }
  return 1;
}

// 取り憑いている間, プレイヤーが動いたぶんだけ一緒に動く, プレイヤーの ENE が尽きるか副状態が終わったら離れて止まる
// 223/225命令, 原典は flags3 のアドレスを副状態に入った直後の判定の合流点で作って後でも使い回す (Ghost_StateDamaged と同じ), 試済: Vec3_Diff の差分ローカル, 歩きアニメ速度の inline を直書き / TEST_FLAGS
NON_MATCH void Ghost_StatePossess(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ghost_StateDrainPlayer, ES_UNK_34);
    q->curveStart = gPlayerPtr[0]->mover.pos;
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_25);
    (p->e).mover.angle = (p->e).playerAngle;
  }
  (p->e).unk_494 = 64;
  Vec3_Diff(&d, &gPlayerPtr[0]->mover.pos, &q->curveStart);
  (p->e).mover.delta.x += d.x;
  (p->e).mover.delta.z += d.z;
  q->curveStart = gPlayerPtr[0]->mover.pos;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!(p->e).subStateDone && gPlayerPtr[0]->ene != 0) {
    (p->e).subStateTimer++;
  } else {
    PlaySound_082406e0(SONG_972);
    Enemy_ResetState(&p->e, 0, 0, 3);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/Ghost_StatePossess.inc");
#endif
}

// Ghost_StateCirclePlayer と同じくプレイヤーの周りの点をたどる, 曲線を引き直すたびに速さを半分にし, EV_WRAITH は速く加速する
// 508/494命令, Ghost_StateCirclePlayer と同じ壁 (退避するレジスタが多い), 試済: Ghost_StateCirclePlayer の C を合わせて直した形
NON_MATCH void FUN_0816e3b8(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    WorldPos dest;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, (u8)Random(), 512);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Vec3_SetPolar(&q->curveTangent, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 32);
    Ghost_BuildCurvePoints(p, &dest);
    q->curveSpeed = 1;
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  Ghost_SpawnAfterimage(p);
  if (d.x * d.x + d.z * d.z > 1024) {
    (p->e).mover.angle = ArcTan2_8(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z);
    (p->e).mover.delta.x += POLAR_X(q->curveSpeed, (p->e).mover.angle);
    (p->e).mover.delta.z += POLAR_Z(q->curveSpeed, (p->e).mover.angle);
    q->curveTangent = (p->e).mover.delta;
  } else if (++q->curvePointIdx > 8) {
    WorldPos dest;

    Vec3_Diff(&q->curveTangent, &q->curvePointsEnd, &(p->e).mover.pos);
    q->curveTangent.y = 0;
    (p->e).mover.pos.x = q->curvePointsEnd.x;
    (p->e).mover.pos.z = q->curvePointsEnd.z;
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 512);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Ghost_BuildCurvePoints(p, &dest);
    q->curveSpeed >>= 1;
    return;
  }
  if ((p->e).variant == EV_GHOST) {
    if (Mod((p->e).subStateTimer, 16) == 0 && q->curveSpeed < 12) {
      q->curveSpeed += 1;
    }
  } else {
    if (Mod((p->e).subStateTimer, 8) == 0 && q->curveSpeed < 12) {
      q->curveSpeed += 2;
    }
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/FUN_0816e3b8.inc");
#endif
}

// プレイヤーの周りの乱数の点へ曲線を引いて点をたどり, 16 フレームごとに速さ curveSpeed を 18 まで上げる
// 483/465命令, 曲線の行き先を作ったあと捨てる差分を求める所 (Bee の FUN_0816869c と同じ計算) まで原典に揃えたが, 退避するレジスタが多く残る, 試済: mover.pos のポインタのローカル, 行き先の足し方
NON_MATCH void Ghost_StateCirclePlayer(Ghost* p) {
#ifdef NONMATCHING_C
  Ghost* q = (p->e).owner;
  Vec3 d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    WorldPos dest;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, (u8)Random(), 512);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Vec3_SetPolar(&q->curveTangent, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 32);
    Ghost_BuildCurvePoints(p, &dest);
    q->curveSpeed = 1;
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  Ghost_SpawnAfterimage(p);
  if (d.x * d.x + d.z * d.z > 1024) {
    (p->e).mover.angle = ArcTan2_8(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z);
    (p->e).mover.delta.x += POLAR_X(q->curveSpeed, (p->e).mover.angle);
    (p->e).mover.delta.z += POLAR_Z(q->curveSpeed, (p->e).mover.angle);
    q->curveTangent = (p->e).mover.delta;
  } else if (++q->curvePointIdx > 8) {
    WorldPos dest;

    Vec3_Diff(&q->curveTangent, &q->curvePointsEnd, &(p->e).mover.pos);
    q->curveTangent.y = 0;
    (p->e).mover.pos.x = q->curvePointsEnd.x;
    (p->e).mover.pos.z = q->curvePointsEnd.z;
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 256);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Ghost_BuildCurvePoints(p, &dest);
    return;
  }
  if (Mod((p->e).subStateTimer, 16) == 0 && q->curveSpeed < 18) {
    q->curveSpeed++;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Ghost_StateCirclePlayer.inc");
#endif
}

void Ghost_SetHandlerTable4(Ghost* p) { (p->e).handlerTables[4] = (void*)sGhostHandlerTable4; }

void FUN_0816ec60(Ghost* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0816b880, ES_UNK_10);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
  }
  if ((p->e).subStateDone) {
    Ghost_BeginCurveTo(p, &gPlayerPtr[0]->mover.pos);
  } else {
    (p->e).subStateTimer++;
  }
}

// tryDetectPlayer が FALSE の間 60 フレーム待ってから, 乱数で選んだ経路ノードへ曲線移動を始める
void FUN_0816ed04(Ghost* p) {
  Ghost* q = (p->e).owner;

  Enemy_ConsumeSubStateBegun(&p->e);
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer > 60) {
    Ghost_PickRandomPathNode(p);
    {
      WorldPos pos;
      WorldPos* dst = &pos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Ghost_StartCurve(p, &pos);
      Ghost_StepCurve(p);
      Enemy_ResetState(&p->e, 0, 0, 1);
      Vec3_Diff(&pos, &pos, &(p->e).mover.pos);
      (p->e).unk_1dc = ArcTan2_8(pos.x, pos.z);
      Vec3_Clear(&q->curveTangent);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

void Ghost_SetHandlerTable3(Ghost* p) { (p->e).handlerTables[3] = (void*)sGhostHandlerTable3; }

// プレイヤーの方を向いて待ち, 近くで A ボタンが押されたら talkScriptID のスクリプトを流す
void Ghost_StateWaitTalk(Ghost* p) {
  Ghost* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  }
  (p->e).mover.angle = (p->e).playerAngle;
  if ((gInput[0].pressed & A_BUTTON) && (p->e).playerDistSq < q->talkDistSq && !(gGameFlags & GAMEFLAG_EVENT) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    Enemy_ResetState(&p->e, 2, 0, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    VM_ExecByID(q->talkScriptID, NULL);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0816efc8(Ghost* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    if ((p->e).subStateTimer == 0) {
      MsgQueue_EndWait(&(p->e).mq, 1);
    }
    (p->e).subStateTimer++;
  }
}

void Ghost_SetHandlerTable8(Ghost* p) { (p->e).handlerTables[8] = (void*)sGhostHandlerTable8; }

s32 Ghost_UpdateFrame(Ghost* p) {
  Ghost_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Ghost_PostUpdate(p);
  return 1;
}

s32 Ghost_Update(Ghost* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Ghost_Destroy(Ghost* p) {
  Ghost_RemoveAfterimages(p);
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
// 1949/2131命令, Bee_Init の下書きを Ghost 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 Ghost_Init(Ghost* p) {
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
  (p->e).kind = ENEK_GHOST;
  Ghost_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_GHOST);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_GHOST);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_GHOST);
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
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).tileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);
  }
  p->spawnFloorY = (p->e).floorY;
  p->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  if (VM_SeekToNamedArg('P')) {
    p->drainInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->escapeMash = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->solarBugAmount = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_GetNamedArgValue('g', 0) != 0) {
    SET_FLAGS(p->flags, GHOSTFLAG_UNK_8);
  }
  if (VM_SeekToNamedArg('d')) {
    p->talkScriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->talkDistSq = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->talkDistSq *= p->talkDistSq;
  } else {
    p->talkScriptID = 0;
    p->talkDistSq = 0;
  }
  if (VM_GetNamedArgValue('i', 0) != 0) {
    SET_FLAGS(p->flags, GHOSTFLAG_UNK_9);
  }
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 381;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 381;
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

  (p->e).unk_476 = (p->e).plttBase;
  (p->e).unk_478 = (p->e).plttBase + 2;
  (p->e).unk_47e = 384;
  if (VM_GetNamedArgValue('U', 0) == 0) {
    Ghost* q = (p->e).owner;
    s32 light;

    if (Ghost_TestFlags(q, GHOSTFLAG_UNK_8)) {
      light = TestMapFlag(MPF_BRIGHT) ? 1 : 0;
    } else {
      light = gStat->sunGauge;
    }
    if (light > 0) {
      SET_FLAGS(q->flags, GHOSTFLAG_VANISHING);
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    } else {
      SET_FLAGS(q->flags, GHOSTFLAG_APPEARING);
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    }
    q->blinkTimer = 0;
  }
  Ghost_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Ghost_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Ghost_GetMoveSpeed;
  (p->e).handlerTurn = Ghost_StateTurn;
  (p->e).handlerMove = Ghost_StateFly;
  (p->e).handlerWait = Ghost_StateWait;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Ghost_StateDamaged;
  (p->e).handlerDying = Ghost_StateDying;
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
  (p->e).msgHandlers = (void*)sGhostMsgHandlers;
  (p->e).onReset = (EnemyHandler)Ghost_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Ghost_OnAttackRequest;
  (p->e).unk_5b0 = NULL;
  (p->e).tryDetectPlayer = (void*)Ghost_TryDetectPlayer;
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_9);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_10 | ENEFLAG2_UNK_20 | ENEFLAG2_UNK_25);
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
  Ghost_SetHandlerTable2(p);
  Ghost_SetHandlerTable4(p);
  Ghost_SetHandlerTable3(p);
  if (p->talkScriptID != 0) {
    Ghost_SetHandlerTable8(p);
  }
  Enemy_PlayAnim(&p->e, 1);
  {
    u32 variant, flags;
    s32 anim;

    Ghost_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    anim = (p->e).animTable[1].anim;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s = &(p->e).s->aux;

      (p->e).playingAnim = anim;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
      (p->e).animForceRestart = 0;
    } else {
      MainSprite* s = &(p->e).s->main.spr;
      s32 a = anim + variant;

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
        (p->e).animForceRestart = 0;
      }
    }
  }
  Ghost_InitAfterimages(p);
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
  (p->e).ownerFlagsInit = p->flags;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Ghost_Update;
  (p->e).handlerDestroy = (EnemyHandler)Ghost_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Ghost_Init.inc");
#endif
}

void Ghost_Create(void) {
  Ghost* p = Malloc(sizeof(Ghost));

  if (p != NULL) {
    ClearMemory(p, sizeof(Ghost));
    if (Ghost_Init(p) < 0) {
      Ghost_Destroy(p);
      Free(p);
    }
  }
}
