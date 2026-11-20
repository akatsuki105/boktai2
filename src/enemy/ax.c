#include "camera.h"
#include "dust.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;       // 0x00
  AuxSpriteGfx gfx;       // 0x2C, SPR_SWORD_AX
  AuxAnimState anim;      // 0x48
  AuxAnimFile* animFile;  // 0x58, ANIM_SWORDAX
  u16 timer;              // 0x5C, 0 でなければ毎フレーム減り, 0 になったら隠す
  u8 unk_5e[2];           // 0x5E
} AxAfterimage;
static_assert(sizeof(AxAfterimage) == 96);

// EneAx.flags (0xE48)
typedef u32 AxFlags;
#define AXFLAG_UNK_0 (1 << 0)          // 0x1
#define AXFLAG_FADING (1 << 1)         // 0x2, plttFade でパレットを寄せている
#define AXFLAG_WARPING (1 << 2)        // 0x4, 潜って別の経路ノードへ移っている, その間は溜め回転斬りに入らない
#define AXFLAG_CHASING (1 << 4)        // 0x10, プレイヤーを追っている
#define AXFLAG_HIDDEN (1 << 6)         // 0x40, 潜って姿を消している
#define AXFLAG_GLOWING (1 << 7)        // 0x80, glowPltt の赤をだんだん強めて光っている
#define AXFLAG_UNGLOWING (1 << 8)      // 0x100, 光るのをやめる途中, 赤を弱めきったら元のパレットに戻す
#define AXFLAG_CHOPPING (1 << 9)       // 0x200, 振り下ろし(小)の最中
#define AXFLAG_SPINNING (1 << 10)      // 0x400, 回転斬りの最中
#define AXFLAG_BIG_CHOPPING (1 << 11)  // 0x800, 振り下ろし(大)の最中
#define AXFLAG_CHARGED_SPIN (1 << 12)  // 0x1000, 溜め回転斬りの最中

// EneAx.cloneFlags (0xCBB)
typedef u8 AxCloneFlags;
#define AXCLONEFLAG_HIT (1 << 0)       // 0x1, 分身のやられ判定に触れた, 本体の攻撃判定とやられ判定を隠す
#define AXCLONEFLAG_ORBITING (1 << 1)  // 0x2, 本体と分身が回っている
#define AXCLONEFLAG_SPINNING (1 << 2)  // 0x4, 回りながら斧も回している, orbitRadius が伸びきった後

// ENEK_AX(見た目が斧の敵)
// variant: ENEID_AX, ENEID_AX_P
// 技: 接触, 回転斬り, 振り下ろし(小), 振り下ろし(大), シャドウアタック
typedef struct {
  Enemy e;
  u8 unk_654[4];                 // 0x654
  WormPaletteFade plttFade;      // 0x658
  AxAfterimage afterimages[4];   // 0x73C
  rgb555 blackPltt[16];          // 0x8BC, OBP 247, 全色 0
  rgb555 redPltt[16];            // 0x8DC, OBP 248, 全色 赤
  rgb555 bluePltt[16];           // 0x8FC, 全色 青
  rgb555 whitePltt[16];          // 0x91C, 全色 白
  rgb555 glowPltt[16];           // 0x93C, OBP 250, 元のパレットの写し, 色1の赤を上げ下げして光らせる
  Hitbox afterimageHitboxes[3];  // 0x95C, atkPower[3] の攻撃判定, 最新の残像の向きに沿って3つ並べる
  Vec3 afterimagePos;            // 0xA4C, 残像を出す位置, afterimageHitboxes もここを中心に並べる
  Vec3 afterimageVel;            // 0xA54, 溜め回転斬りで afterimagePos を毎フレーム動かす速さ
  u8 afterimageAngle;            // 0xA5C, 残像の傾き
  u8 afterimageDir;              // 0xA5D, 溜め回転斬りで残像を飛ばす向き
  u8 spinSpeed;                  // 0xA5E, 回転斬りの後, 毎フレーム rotation から引く量
  u8 unk_a5f;                    // 0xA5F
  AuxSprite cloneSprite;         // 0xA60
  AuxSpriteGfx cloneGfx;         // 0xA8C, SPR_SWORD_AX
  AuxAnimState cloneAnim;        // 0xAA8
  Hitbox cloneHitboxes[3];       // 0xAB8
  Hitbox cloneHurtboxes[3];      // 0xBA8
  Vec3 clonePos;                 // 0xC98
  u8 unk_ca0[8];                 // 0xCA0
  Vec3 orbitCenter;              // 0xCA8, シャドウアタックで本体と分身が回る中心
  s16 orbitRadius;               // 0xCB0, orbitCenter から本体と分身までの距離
  u8 unk_cb2[2];                 // 0xCB2
  u8 orbitSpeed;                 // 0xCB4, orbitAngle を進める速さ (orbitDir を掛けて 16 で割る)
  s8 orbitDir;                   // 0xCB5, 回る向き, 1 か -1
  u8 orbitMoveDir;               // 0xCB6, orbitCenter をプレイヤーへ動かす向き
  u8 cloneShadowResult;          // 0xCB7, ParticleShadow_Init の戻り値, 読むコードは見つかっていない
  u8 unk_cb8;                    // 0xCB8
  u8 orbitAngle;                 // 0xCB9, 本体の orbitCenter からの向き, 分身はその反対側
  u8 unk_cba;                    // 0xCBA
  AxCloneFlags cloneFlags;       // 0xCBB
  ParticleShadow cloneShadow;    // 0xCBC
  Hitbox subHitboxes[2];         // 0xCFC, atkPower[0] の攻撃判定
  Hitbox subHurtboxes[2];        // 0xD9C, Ax_OnHurt を呼ぶやられ判定
  u8 chargedSpinTurnRate;        // 0xE3C, '.O[0]=6', 溜め回転斬りで毎フレーム残像の傾きから引く量
  u8 chargedSpinSpeed;           // 0xE3D, '.O[1]=12', 溜め回転斬りでプレイヤーへ残像を飛ばす速さ
  u8 bigChopWait;                // 0xE3E, '.O[2]=60', 振り下ろし(大)を振りかぶってから振り下ろすまでのフレーム, hp が maxHp の 1/4 以下なら半分
  u8 bigChopRaiseSpeed;          // 0xE3F, '.O[3]=3', 振り下ろし(大)で振りかぶる速さ, hp が maxHp の 1/4 より多い間は半分
  u8 hideTime;                   // 0xE40, '.O[4]=60', 潜ってから現れるまでのフレーム
  u8 cloneSlideTime;             // 0xE41, '.O[5]=30', 分身を出すときに残像を分身の位置へ寄せるフレーム数
  u8 unk_e42[2];                 // 0xE42
  u16 nextAfterimage;            // 0xE44, 次に出す afterimages の番号
  u16 afterimageInterval;        // 0xE46, 残像を出すフレーム間隔
  AxFlags flags;                 // 0xE48
  u8 unk_e4c[0xE52 - 0xE4C];     // 0xE4C
  u16 orbitDistSq;               // 0xE52, 512, プレイヤーとの距離の2乗がこれより小さいと横へ回り込む
  u16 spawnFloorY;               // 0xE54, 出現位置の床の高さ
  u16 curveSpeed;                // 0xE56, 曲線の点をたどるときの速さ, だんだん上がる
  Vec3 curvePoints[8];           // 0xE58, 曲線を 8 等分した点
  Vec3 curvePointsEnd;           // 0xE98, curvePoints の曲線の終点
  u8 curvePointIdx;              // 0xEA0, curvePoints の今向かっている点の番号
  u8 unk_ea1;                    // 0xEA1
  u16 unk_ea2;                   // 0xEA2
  u16 curveT;                    // 0xEA4
  u8 hoverPhase;                 // 0xEA6, 上下の揺れの sin の位相
  s8 curveBendDir;               // 0xEA7
  s16 curveBend;                 // 0xEA8
  u8 swingSpeed;                 // 0xEAA, 振り下ろしで毎フレーム傾きに足す量, 4 フレームごとに 4 増える
  u8 stepTimer;                  // 0xEAB, 残りフレーム, 傾きや位置をこれで割った分ずつ寄せる
  u8 hitStreak;                  // 0xEAC, 被弾ごとに増え 3 で止まる, 3 になると溜め回転斬りに入って 0 に戻す
  u8 shakeTimer;                 // 0xEAD, 0 でなければ毎フレーム減らしながら画面を揺らす
  u8 shakePower;                 // 0xEAE, Camera_Shake の強さ
  u8 unk_eaf;                    // 0xEAF
  u16 lowHpThreshold;            // 0xEB0, 最大 hp の 3/4, hp がこれ以下になると振り下ろしを使い始める
  u8 unk_eb2[2];                 // 0xEB2
  u16 attackCooldowns[4];        // 0xEB4, 技ごとの待ち, 毎フレーム減り 0 の技だけ出せる
  u16 attackIntervals[4];        // 0xEBC, '.P[0..3]=0', 技を出したときに attackCooldowns に入れる
  s8 recentNodes[3];             // 0xEC4
  u8 recentNodeIdx;              // 0xEC7
  u8 unk_ec8[2];                 // 0xEC8
  u8 glowTimer;                  // 0xECA
  u8 glowStep;                   // 0xECB
  u8 glowStartReq;               // 0xECC, 立てると glowPltt で光り始める
  u8 glowStopReq;                // 0xECD, 立てると光るのをやめて元のパレットに戻す
  u8 smokeIdx;                   // 0xECE, Ax_EmitLineSmoke が次に煙を出す位置 0〜4
  u8 chopAngle;                  // 0xECF, 振り下ろしを始めたときのプレイヤーの向き, 反対側へ斧を振りかぶる
  NavAgent navAgent;             // 0xED0, Enemy.navAgent が指す
  Vec3 pathNodePos;              // 0xEF4, Enemy.pathNodePos が指す
  WorldPos curveStart;           // 0xEFC, 曲線の始点
  Vec3 curveEnd;                 // 0xF04, 曲線の終点
  Vec3 curveTangent;             // 0xF0C, 曲線の始点の接線
  WorldPos prevPlayerPos;        // 0xF14, 前のフレームのプレイヤーの位置
} EneAx;
static_assert(sizeof(EneAx) == 3868);

// 0〜255 の角度を -128〜128 に直す
static inline s32 Ax_WrapAngle(s32 d) {
  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Ax_PlayDirAnim(EneAx* p, u32 anim, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 mode;

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    mode = (flags & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

static inline bool8 Ax_TestFlags(EneAx* p, AxFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

static inline bool8 Ax_TestFlagsAt(AxFlags* flags, AxFlags bit) {
  if (*flags & bit) return TRUE;
  return FALSE;
}

const STRING_DATA char s_eneinline_082521a4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521bc[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521d4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521ec[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252204[] = "../system/eneinline.h";
const STRING_DATA char s_axcom_c_0825221c[] = "axcom.c";

// 回転しながら残像をプレイヤーへ曲がりつつ飛ばし, 120 フレーム後は手元へ戻して, 戻ったら回転を緩める状態へ移る
void Ax_StateChargedSpin(EneAx* p, s32 timer);
void Ax_StateStraighten(EneAx* p);
// プレイヤーに気づいた向き付きのアニメを 60 フレーム流す
void Ax_StateNoticePlayer(EneAx* p, s32 timer);
void Ax_SpawnAfterimage(EneAx* p);
void Ax_RemoveClone(EneAx* p);
void Ax_StateCloneVanish(EneAx* p, s32 timer);
void Ax_StateCloneSpin(EneAx* p, s32 timer);
void Ax_StateCloneBlink(EneAx* p, s32 timer);
void Ax_StateSpinDown(EneAx* p, s32 timer);
void Ax_UpdateAfterimageHitboxes(EneAx* p);
void Ax_SpawnAfterimageAt(EneAx* p, Vec3* pos, u32 angle);
void Ax_SpawnChopDust(EneAx* p, u32 count);
void Ax_StopChase(EneAx* p);
void Ax_ResumeHover(EneAx* p);
bool8 Ax_TryStartAttack(EneAx* p);
void Ax_StateVanish(EneAx* p);
void Ax_OnHurt(Hitbox* a, Hitbox* b, EneAx* p);
void Ax_SetAfterimagePltt(EneAx* p, rgb555* pltt);
// プレイヤーへ跳びながら斧を振り下ろし, 着地したら光るのをやめて画面を大きく揺らし砂埃を出す
void Ax_StateBigChopSwing(EneAx* p, s32 timer);
void Ax_StateChopRecover(EneAx* p, s32 timer);
// 本体と分身が orbitCenter のまわりを回り, 途中から半径を広げて斧も回しながらプレイヤーへ寄る, 分身が叩かれるか 1000 フレームで次へ移る
void Ax_StateCloneOrbit(EneAx* p, s32 timer);
// 斧の頭のあたり (傾きに合わせて回した位置) に count 個の砂埃を出す
void Ax_SpawnChopDust(EneAx* p, u32 count);
// 本体と同じアニメの分身を隠して出し, 分身の攻撃判定・やられ判定と影を用意する
void Ax_InitClone(EneAx* p);
void Ax_SetClonePos(EneAx* p, Vec3* pos);
bool8 Ax_BlinkDecel(u32* flags, s32 timer, s32 slowEnd, s32 midEnd);
void Ax_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
// 分身を黒で出し, 光るパレットとの点滅をだんだん遅くして状態 43 へ移る
void Ax_StateCloneAppear(EneAx* p, s32 timer);
// 斧をだんだん速く振り下ろし, 傾きが 96 を超えたら画面を揺らして止まる
void Ax_StateChopSwing(EneAx* p, s32 timer);
void Ax_SpawnAfterimageAt(EneAx* p, Vec3* pos, u32 angle);
// afterimageHitboxes を最新の残像の傾きに沿って afterimagePos のまわりに3つ並べて登録する
void Ax_UpdateAfterimageHitboxes(EneAx* p);
void Ax_UpdateCloneHitboxes(EneAx* p);
void Ax_StateStraighten(EneAx* p);
// 本体の左に分身の位置を決め, 残像を回しながらそこへ寄せていく
void Ax_StateCloneSplit(EneAx* p);
// プレイヤーと反対側へ斧を振りかぶり, 43 フレームで振り下ろしへ移る
void Ax_StateChopRaise(EneAx* p, s32 timer);
// 赤く光りながら振り下ろし(大)を振りかぶり, 待ちが過ぎたら振り下ろしへ移る
void Ax_StateBigChopRaise(EneAx* p, s32 timer);
// 姿を隠したまま hideTime 待ち, プレイヤーから離れた経路ノードを選んで現れる
void Ax_StateHidden(EneAx* p, s32 timer);
// 縦に伸びた姿から元の大きさに戻りながら現れる
void Ax_StateReappear(EneAx* p);
void Ax_PickFarPathNode(EneAx* p, Vec3* to, Vec3* from, s32 maxDist);
void Ax_SetAfterimagePlttID(EneAx* p, rgb555* pltt, s32 plttID);
void Ax_SetClonePltt(EneAx* p, rgb555* pltt, s32 plttID);
bool8 Ax_BlinkAccel(u32* flags, s32 timer, s32 slowEnd, s32 midEnd);

// 経路ノードで 60 フレーム待ってから追跡に戻す
void Ax_SubWaitAtNode(EneAx*);
// 曲線の接線ぶんの勢いを 4 フレームごとに半分にしながら滑り, 終わったら経路ノードで待つ
void Ax_SubDrift(EneAx*);
void Ax_SubApproach(EneAx*);
// hp に応じた速さでプレイヤーへ寄りながら技を探し, 時間が過ぎたら潜って別の経路ノードへ移る
void Ax_SubChase(EneAx*);
// 潜って別の経路ノードから現れ, 追跡に戻す
void Ax_SubWarp(EneAx*);

void (*const sAxHandlerTable2[5])(EneAx*) = {
    Ax_SubWaitAtNode,
    Ax_SubDrift,
    Ax_SubApproach,
    Ax_SubChase,
    Ax_SubWarp,
};  // 0x085ADDB8

// 点滅の間隔, 経過フレームが進むと 0, 1, 2 番の間隔に切り替わる
const s16 sBlinkIntervalsAccel[4] = {12, 8, 4, 0};  // 0x085ADDCC
const s16 sBlinkIntervalsDecel[4] = {4, 8, 12, 0};  // 0x085ADDD4

// 回転斬りを出し, 終わったら潜って次の副状態へ
void Ax_SubStartSpin(EneAx*);
// 回転斬りが終わるのを待ち, 終わったら追跡に戻す
void Ax_SubEndSpin(EneAx*);
// 振り下ろし(小)を出し, 終わったら潜って次の副状態へ
void Ax_SubStartChop(EneAx*);
// 振り下ろし(小)が終わるのを待ち, 終わったら追跡に戻す
void Ax_SubEndChop(EneAx*);
// 振り下ろし(大)を出し, 終わったら潜って次の副状態へ
void Ax_SubStartBigChop(EneAx*);
// 振り下ろし(大)が終わるのを待ち, 終わったら追跡に戻す
void Ax_SubEndBigChop(EneAx*);
// 赤く光って溜め回転斬りを出し, 終わったら潜って次の副状態へ
void Ax_SubStartChargedSpin(EneAx*);
// 溜め回転斬りが終わるのを待ち, 光るのをやめて残像を黒に戻し, 追跡に戻す
void Ax_SubEndChargedSpin(EneAx*);
// 分身を出すシャドウアタックを始め, 終わったら潜って別の経路ノードへ移る
void Ax_SubShadowAttack(EneAx*);
void Ax_SubCirclePlayer(EneAx*);
void Ax_SubCirclePlayerFast(EneAx*);

void (*const sAxHandlerTable4[11])(EneAx*) = {
    Ax_SubStartSpin,
    Ax_SubEndSpin,
    Ax_SubStartChop,
    Ax_SubEndChop,
    Ax_SubStartBigChop,
    Ax_SubEndBigChop,
    Ax_SubStartChargedSpin,
    Ax_SubEndChargedSpin,
    Ax_SubShadowAttack,
    Ax_SubCirclePlayer,
    Ax_SubCirclePlayerFast,
};  // 0x085ADDDC

void Ax_StartChase(EneAx*);
// プレイヤーを探しながら 60 フレーム待ち, 乱数の経路ノードへの曲線移動を始める
void Ax_SubWander(EneAx*);

void (*const sAxHandlerTable3[2])(EneAx*) = {
    Ax_StartChase,
    Ax_SubWander,
};  // 0x085ADE08

void Ax_OnCloneHit(Hitbox* a, Hitbox* b, EneAx* p) {}

// 分身が触れられたら本体の攻撃判定とやられ判定を隠す
void Ax_OnCloneHurt(Hitbox* a, Hitbox* b, EneAx* p) {
  if (!(p->cloneFlags & AXCLONEFLAG_HIT)) {
    p->cloneFlags |= AXCLONEFLAG_HIT;
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
  }
}

void Ax_OnHit(Hitbox* a, Hitbox* b, EneAx* p) {}

// 被弾を受け, 分身と回っている間に 3 回続けて被弾したら分身を点滅させて消す
// 残差は 850/855命令, Ghost_OnHurt / EneBat_OnHurt と同じ Enemy_HandleHurt の共通 inline の壁
// 試済: Enemy_IsDead の先行判定を空の if と return で, ユーザーの指示で早めに打ち切り
NON_MATCH void Ax_OnHurt(Hitbox* a, Hitbox* b, EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  if ((p->e).hurtbox.iframes == 0) {
    (p->e).hurtbox.damage = b->damage;
    (p->e).unk_48c = b->hitResult;
    (p->e).hurtbox.iframes = b->iframes;
  }
  if ((q->cloneFlags & AXCLONEFLAG_ORBITING) && q->hitStreak > 2) {
    for (i = 0; i < 3; i++) {
      Hitbox_Hide(&q->cloneHitboxes[i]);
      Hitbox_Hide(&q->cloneHurtboxes[i]);
    }
    Enemy_EnterState(&p->e, Ax_StateCloneBlink, ES_UNK_46);
    q->hitStreak = 0;
  }
#else
  INCFUNC("asm/func/Ax_OnHurt.inc");
#endif
}

void Ax_StateCloneSplit(EneAx* p) {
  EneAx* q = (p->e).owner;
  Vec3* pos;
  Vec3 d;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->smokeIdx = 0;
    q->clonePos = (p->e).mover.pos;
    q->clonePos.x -= 256;
    q->afterimagePos = (p->e).mover.pos;
    q->afterimageAngle = 0;
    q->stepTimer = q->cloneSlideTime;
    q->cloneFlags = 0;
  }
  pos = &q->afterimagePos;
  Ax_SpawnAfterimageAt(p, pos, q->afterimageAngle);
  Ax_UpdateAfterimageHitboxes(p);
  Vec3_Diff(&d, &q->clonePos, pos);
  pos->x += Div(d.x, q->stepTimer);
  if (--q->stepTimer == 0) {
    Enemy_EnterState(&p->e, Ax_StateCloneAppear, ES_UNK_42);
  }
}

void Ax_StateCloneAppear(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  u32 blink;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Ax_InitClone(p);
    Ax_SetClonePos(p, &q->clonePos);
    q->glowPltt[1] = 0;
    q->cloneSprite.flags &= ~SPRFLAG_HIDDEN;
    ParticleShadow_Show(&q->cloneShadow);
    Ax_SetClonePltt(p, q->blackPltt, 247);
    PlaySound_082406e0(SONG_367);
  }
  if (Ax_BlinkDecel(&blink, timer, 10, 30)) {
    Enemy_EnterState(&p->e, Ax_StateCloneOrbit, ES_UNK_43);
    Ax_SetClonePltt(p, q->glowPltt, 250);
    PlaySound_082406e0(SONG_365);
  } else if (blink & 1) {
    Ax_SetClonePltt(p, q->blackPltt, 247);
  } else {
    Ax_SetClonePltt(p, q->glowPltt, 250);
  }
}

// 残差は 649/649命令, orbitDir を反転する所で &orbitDir を作る一時レジスタ (原典 r2, こちら r1) だけ
// 試済: 中心の寄せを Vec3_Sum で, 回る位置の COS * 半径, 分身の角度の & 0xFF, 向きの差を Vec3_Delta で, Random() & 0xFF, orbitDir *= -1, 回転の s32 ローカル, 分身のヒット判定を先に
NON_MATCH void Ax_StateCloneOrbit(EneAx* p, s32 timer) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  Vec3 d;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->cloneFlags |= AXCLONEFLAG_ORBITING;
    q->orbitAngle = 0;
    q->orbitRadius = 128;
    q->orbitSpeed = 4;
    q->orbitDir = 1;
    q->orbitCenter = q->clonePos;
    Vec3_Diff(&d, &(p->e).mover.pos, &q->orbitCenter);
    d.x = FixToInt(1, d.x);
    d.z = FixToInt(1, d.z);
    Vec3_Sum(&q->orbitCenter, &d, &q->orbitCenter);
  }
  (p->e).mover.pos.x = q->orbitCenter.x + FixToInt(12, COS(q->orbitAngle) * q->orbitRadius);
  (p->e).mover.pos.z = q->orbitCenter.z + FixToInt(12, SIN(q->orbitAngle) * q->orbitRadius);
  q->cloneSprite.pos.x = q->orbitCenter.x + FixToInt(12, COS((q->orbitAngle + 128) & 0xFF) * q->orbitRadius);
  q->cloneSprite.pos.z = q->orbitCenter.z + FixToInt(12, SIN((q->orbitAngle + 128) & 0xFF) * q->orbitRadius);
  if (timer < 60) {
    q->orbitSpeed += 2;
    q->hitStreak = 0;
  } else if (timer < 180) {
    if (Mod(timer, 4) == 0 && (Random() & 0xFF) < 20) {
      q->orbitDir *= -1;
      PlaySound_082406e0(SONG_361);
    }
    Vec3_Delta(&d, &q->orbitCenter, &gPlayerPtr[0]->mover.pos);
    q->orbitMoveDir = ArcTan2_8(d.x, d.z);
    q->hitStreak = 0;
  } else {
    s32 diff;

    if (!(q->cloneFlags & AXCLONEFLAG_SPINNING)) {
      if (q->orbitRadius < 512) {
        q->orbitRadius += 8;
        q->orbitSpeed -= 4;
        if (q->orbitSpeed < 16) {
          q->orbitSpeed = 16;
        }
      } else {
        q->orbitRadius = 512;
        q->orbitSpeed = 16;
        q->cloneFlags |= AXCLONEFLAG_SPINNING;
      }
    }
    Vec3_Delta(&d, &q->orbitCenter, &gPlayerPtr[0]->mover.pos);
    diff = Ax_WrapAngle(ArcTan2_8(d.x, d.z) - q->orbitMoveDir);
    if (abs(diff) > 20) {
      if (diff > 0) {
        q->orbitMoveDir += 4;
      } else {
        q->orbitMoveDir -= 4;
      }
    }
    q->orbitCenter.x += POLAR_X(2, q->orbitMoveDir);
    q->orbitCenter.z += POLAR_Z(2, q->orbitMoveDir);
    if (q->cloneFlags & AXCLONEFLAG_SPINNING) {
      EnemySprite* s = (p->e).s;
      s32 rotation;

      s->aux.spr.flags |= SPRFLAG_AFFINE;
      q->cloneSprite.flags |= SPRFLAG_AFFINE;
      rotation = s->aux.spr.rotation;
      s->aux.spr.rotation = rotation - 6;
      q->cloneSprite.rotation += 6;
      if (rotation < (p->e).s->aux.spr.rotation) {
        PlaySound_082406e0(SONG_361);
      }
      if (q->cloneFlags & AXCLONEFLAG_SPINNING) {
        if (timer < 480) {
          q->orbitRadius -= 1;
        } else if (timer < 580) {
          q->orbitRadius += 6;
        } else if (timer < 660) {
          q->orbitRadius -= 4;
        } else if (timer < 740) {
          q->orbitRadius += 4;
        } else if (timer >= 820) {
          q->orbitRadius -= 6;
        }
      }
    }
  }
  q->orbitAngle += FixToInt(4, q->orbitSpeed * q->orbitDir);
  Ax_UpdateCloneHitboxes(p);
  if (q->cloneFlags & AXCLONEFLAG_HIT) {
    Enemy_EnterState(&p->e, Ax_StateCloneSpin, ES_UNK_45);
  } else if (timer > 1000) {
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    for (i = 0; i < 3; i++) {
      Hitbox_Hide(&q->cloneHitboxes[i]);
      Hitbox_Hide(&q->cloneHurtboxes[i]);
    }
    Enemy_EnterState(&p->e, Ax_StateCloneBlink, ES_UNK_46);
  }
#else
  INCFUNC("asm/func/Ax_StateCloneOrbit.inc");
#endif
}

// 分身を隠し, その位置で残像を速めながら回して 30 フレーム後に分身を消す
void Ax_StateCloneSpin(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  s32 angle;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->cloneSprite.flags |= SPRFLAG_AFFINE;
    q->cloneFlags = 0;
    q->afterimageDir = 0;
    q->afterimagePos = q->cloneSprite.pos;
    q->afterimageAngle = q->unk_cb8;
    q->spinSpeed = 4;
    ParticleShadow_Hide(&q->cloneShadow);
    q->cloneSprite.flags = SPRFLAG_HIDDEN;
  }
  angle = q->afterimageAngle;
  q->afterimageAngle = angle - q->spinSpeed;
  if (angle < q->afterimageAngle) {
    PlaySound_082406e0(SONG_361);
  }
  if ((timer & 1) && q->spinSpeed < 20) {
    q->spinSpeed++;
  }
  Ax_SpawnAfterimageAt(p, &q->afterimagePos, q->afterimageAngle);
  Ax_UpdateAfterimageHitboxes(p);
  Ax_UpdateCloneHitboxes(p);
  if ((q->cloneSprite.flags & SPRFLAG_HIDDEN) && timer > 30) {
    Ax_RemoveClone(p);
    Enemy_EnterState(&p->e, Ax_StateStraighten, ES_UNK_51);
  }
}

// 分身を黒と光るパレットで点滅させ, だんだん速くして状態 47 へ移る
void Ax_StateCloneBlink(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  u32 blink;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->cloneFlags = 0;
    Ax_SetClonePltt(p, q->glowPltt, 250);
  }
  if (Ax_BlinkAccel(&blink, timer, 10, 30)) {
    Enemy_EnterState(&p->e, Ax_StateCloneVanish, ES_UNK_47);
    Ax_SetClonePltt(p, q->blackPltt, 247);
  } else if (blink & 1) {
    Ax_SetClonePltt(p, q->blackPltt, 247);
  } else {
    Ax_SetClonePltt(p, q->glowPltt, 250);
  }
}

// 分身を点滅させて消し, 消えたら状態 51 へ移る
void Ax_StateCloneVanish(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->cloneFlags = 0;
  }
  if (Sprite_UpdateVanishBlink(&q->cloneSprite.flags, timer, 10, 30)) {
    Ax_RemoveClone(p);
    Enemy_EnterState(&p->e, Ax_StateStraighten, ES_UNK_51);
  }
}

// 横に縮み縦に伸びて姿を消し, 状態 35 へ移る
void Ax_StateVanish(EneAx* p) {
  EneAx* q = (p->e).owner;
  AuxSprite* s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_AFFINE;
    SET_FLAGS(q->flags, AXFLAG_WARPING);
    PlaySound_082406e0(SONG_363);
  }
  s = &(p->e).s->aux.spr;
  if (s->scaleX > 32) {
    s->scaleX -= 4;
  } else if (s->scaleX > 8) {
    s->scaleX -= 2;
    (p->e).s->aux.spr.scaleY += 4;
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (s->scaleY < 120) {
    s->scaleY += 8;
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    s->flags = SPRFLAG_HIDDEN;
    Enemy_EnterState(&p->e, Ax_StateHidden, ES_UNK_35);
    ParticleShadow_Hide(&(p->e).shadow);
    SET_FLAGS(q->flags, AXFLAG_HIDDEN);
  }
}

void Ax_StateHidden(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_AFFINE;
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
  }
  (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
  ParticleShadow_Hide(&(p->e).shadow);
  if (timer > q->hideTime) {
    Ax_PickFarPathNode(p, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos, 0x40000);
    Enemy_EnterState(&p->e, Ax_StateReappear, ES_UNK_36);
  }
}

void Ax_StateReappear(EneAx* p) {
  EneAx* q = (p->e).owner;
  AuxSprite* s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s = &(p->e).s->aux.spr;
    s->flags = (s->flags | SPRFLAG_AFFINE) & ~SPRFLAG_HIDDEN;
    s->rotation = 0;
    Hitbox_ClearFlags(&(p->e).hitbox, HBF_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBF_HIDDEN);
    PlaySound_082406e0(SONG_364);
  }
  s = &(p->e).s->aux.spr;
  if (s->scaleY > 112) {
    s->scaleY -= 8;
  } else if (s->scaleY > 64) {
    s->scaleX += 2;
    (p->e).s->aux.spr.scaleY -= 4;
    ParticleShadow_Show(&(p->e).shadow);
  } else if (s->scaleX < 64) {
    s->scaleX += 4;
  } else {
    s->scaleX = 64;
    (p->e).s->aux.spr.scaleY = 64;
    CLEAR_FLAGS(q->flags, AXFLAG_WARPING | AXFLAG_HIDDEN);
    (p->e).subStateDone = TRUE;
  }
}

// 残像を出しながらスプライトを 20 まで傾け, 60 フレームで状態 39 へ移る
void Ax_StateWindUp(EneAx* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_AFFINE;
  }
  Ax_SpawnAfterimage(p);
  if ((p->e).s->aux.spr.rotation < 20) {
    (p->e).s->aux.spr.rotation++;
  }
  if (timer > 60) {
    (p->e).s->aux.spr.rotation = 20;
    Enemy_EnterState(&p->e, Ax_StateChargedSpin, ES_UNK_39);
  }
}

// 残差は最後の距離の2乗で d.x / d.z を読む順だけ (403/403命令)
// Tier A-C の一部を試済: 回転の s32 ローカル, 分岐ごとの Vec3 d, 位置のポインタローカル, Vec3_Sum(pos, &vel, pos) で前半は揃った, 未: 距離の2乗の項の順
NON_MATCH void Ax_StateChargedSpin(EneAx* p, s32 timer) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  s32 rotation;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_AFFINE;
    Vec3_SetPolar(&q->afterimageVel, (p->e).playerAngle, 12);
    q->afterimageDir = (p->e).playerAngle;
    q->afterimagePos = (p->e).mover.pos;
    q->afterimageAngle = (p->e).s->aux.spr.rotation;
    q->spinSpeed = 1;
  }
  rotation = (p->e).s->aux.spr.rotation;
  (p->e).s->aux.spr.rotation = rotation - q->spinSpeed;
  if ((timer & 1) && q->spinSpeed < 12) {
    q->spinSpeed++;
  }
  Ax_UpdateAfterimageHitboxes(p);
  if (rotation < (p->e).s->aux.spr.rotation) {
    PlaySound_082406e0(SONG_361);
  }
  if (timer < 120) {
    Vec3* pos = &q->afterimagePos;
    Vec3 d;

    Ax_SpawnAfterimageAt(p, pos, q->afterimageAngle);
    Vec3_Sum(pos, &q->afterimageVel, pos);
    q->afterimageAngle -= q->chargedSpinTurnRate;
    Vec3_Delta(&d, &q->afterimagePos, &gPlayerPtr[0]->mover.pos);
    if (abs(Ax_WrapAngle(ArcTan2_8(d.x, d.z) - q->afterimageDir)) > 32) {
      q->afterimageDir += 4;
    }
    Vec3_SetPolar(&q->afterimageVel, q->afterimageDir, q->chargedSpinSpeed);
  } else {
    Vec3* pos = &q->afterimagePos;
    Vec3 d;

    Ax_SpawnAfterimageAt(p, pos, q->afterimageAngle);
    Vec3_Sum(pos, &q->afterimageVel, pos);
    q->afterimageAngle -= 6;
    Vec3_Delta(&d, &q->afterimagePos, &(p->e).mover.pos);
    if (abs(Ax_WrapAngle(ArcTan2_8(d.x, d.z) - q->afterimageDir)) > 12) {
      q->afterimageDir += 6;
    }
    Vec3_SetPolar(&q->afterimageVel, q->afterimageDir, 8);
    if (d.x * d.x + d.z * d.z < 1024 || timer > 600) {
      q->afterimagePos = (p->e).mover.pos;
      Enemy_EnterState(&p->e, Ax_StateSpinDown, ES_UNK_40);
    }
  }
#else
  INCFUNC("asm/func/Ax_StateChargedSpin.inc");
#endif
}

// 回転斬りの回転をだんだん緩め, 30 フレーム後に向きがほぼ戻ったら止める
void Ax_StateSpinDown(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;
  s32 d;
  s32 rotation;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->spinSpeed = 12;
    q->stepTimer = 30;
  }
  d = Ax_WrapAngle(s->aux.spr.rotation);
  Ax_SpawnAfterimage(p);
  rotation = s->aux.spr.rotation;
  s->aux.spr.rotation = rotation - q->spinSpeed;
  if (rotation < (p->e).s->aux.spr.rotation) {
    PlaySound_082406e0(SONG_361);
  }
  if (timer > 29) {
    if (abs(d) < 13) {
      s->aux.spr.rotation = 0;
      (p->e).subStateDone = TRUE;
    }
  }
}

// スプライトを回し, 1周ごとに風切り音を鳴らす, 44 フレームで止める
void Ax_AnimSpin(EneAx* p, s32 timer) {
  bool8 begun = Enemy_ConsumeStateBegun(&p->e);
  AuxSprite* s = &(p->e).s->aux.spr;
  s32 rotation;

  if (begun) {
    s->flags |= SPRFLAG_AFFINE;
  }
  rotation = s->rotation;
  s->rotation = rotation - 6;
  if (rotation < (p->e).s->aux.spr.rotation) {
    PlaySound_082406e0(SONG_361);
  }
  if (timer > 43) {
    (p->e).s->aux.spr.rotation = 0;
    (p->e).subStateDone = TRUE;
  }
}

void Ax_StateChopRaise(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->chopAngle = (p->e).playerAngle;
  }
  if (abs(Ax_WrapAngle(s->aux.spr.rotation)) > 48) {
    if (timer > 42) {
      Enemy_EnterState(&p->e, Ax_StateChopSwing, ES_UNK_49);
    }
  } else if (Ax_WrapAngle(32 - q->chopAngle) < 0) {
    s->aux.spr.rotation -= 2;
  } else {
    s->aux.spr.rotation += 2;
  }
}

void Ax_StateChopSwing(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;
  s32 d;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->swingSpeed = 4;
    PlaySound_082406e0(SONG_485);
  }
  if (Ax_WrapAngle(32 - q->chopAngle) < 0) {
    s->aux.spr.rotation += q->swingSpeed;
  } else {
    s->aux.spr.rotation -= q->swingSpeed;
  }
  if (Mod(timer, 4) == 0) {
    q->swingSpeed += 4;
  }
  d = Ax_WrapAngle(s->aux.spr.rotation);
  Ax_SpawnAfterimage(p);
  if (abs(d) > 96) {
    Enemy_EnterState(&p->e, Ax_StateChopRecover, ES_UNK_50);
    CLEAR_FLAGS(q->flags, AXFLAG_CHOPPING);
    q->shakePower = 32;
    Ax_SpawnChopDust(p, 8);
  }
}

// 振り下ろしの後, 画面を揺らして 80 フレーム止まり, 状態 51 へ移る
void Ax_StateChopRecover(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->shakeTimer = 40;
    PlaySound_082406e0(SONG_483);
  }
  if (Mod(timer, 6) == 0) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (timer > 80) {
    Enemy_EnterState(&p->e, Ax_StateStraighten, ES_UNK_51);
  }
}

void Ax_StateBigChopRaise(EneAx* p, s32 timer) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->chopAngle = (p->e).playerAngle;
    q->prevPlayerPos = gPlayerPtr[0]->mover.pos;
    q->glowStartReq = TRUE;
    PlaySound_082406e0(SONG_367);
  }
  if (abs(Ax_WrapAngle(s->aux.spr.rotation)) > 48) {
    if ((p->e).hp <= (p->e).unk_546) {
      if (timer > q->bigChopWait >> 1) {
        Enemy_EnterState(&p->e, Ax_StateBigChopSwing, ES_UNK_53);
      }
    } else if (timer > q->bigChopWait) {
      Enemy_EnterState(&p->e, Ax_StateBigChopSwing, ES_UNK_53);
    }
  } else {
    s32 speed;

    if ((p->e).hp <= (p->e).unk_546) {
      speed = q->bigChopRaiseSpeed;
    } else {
      speed = q->bigChopRaiseSpeed >> 1;
    }

    if (speed <= 0) {
      speed = 1;
    }
    if (Ax_WrapAngle(32 - q->chopAngle) < 0) {
      s->aux.spr.rotation -= speed;
    } else {
      s->aux.spr.rotation += speed;
    }
  }
}

// 269/270命令, 原典は &(p->e).flags2 を入場判定の直後に r8 へ取り, 入場処理の中でも作り直して r8 に入れる
// 試済: flags2 ローカルの位置 (先頭, 入場判定の結果を begun に受けた直後, 入場処理での再代入, 入場処理の後), 跳ぶ向きを Vec3_Delta で, hp の判定の向き, 振り速度の if/else
NON_MATCH void Ax_StateBigChopSwing(EneAx* p, s32 timer) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;
  EnemyFlags2* flags2;
  s32 d;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3 diff;

    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->swingSpeed = 2;
    Vec3_Delta(&diff, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    if ((p->e).hp <= (p->e).unk_546) {
      (p->e).jumpVel.x = Div(diff.x, 44);
      (p->e).jumpVel.y = 44;
      (p->e).jumpVel.z = Div(diff.z, 44);
    } else {
      (p->e).jumpVel.x = FixToInt(6, diff.x);
      (p->e).jumpVel.y = 64;
      (p->e).jumpVel.z = FixToInt(6, diff.z);
    }
    q->unk_eaf = 0;
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Ax_SetAfterimagePlttID(p, q->redPltt, 248);
    PlaySound_082406e0(SONG_485);
  }
  flags2 = &(p->e).flags2;
  (p->e).mover.pos.y += (p->e).heightAboveFloor;
  if (Ax_WrapAngle(32 - q->chopAngle) < 0) {
    s->aux.spr.rotation += q->swingSpeed;
  } else {
    s->aux.spr.rotation -= q->swingSpeed;
  }
  d = Ax_WrapAngle(s->aux.spr.rotation);
  Ax_SpawnAfterimage(p);
  if (timer < 28) {
    if (Mod(timer, 10) == 0) {
      q->swingSpeed += 4;
    }
  } else {
    if (abs(d) < 96) {
      q->swingSpeed = 8;
    } else {
      q->swingSpeed = 0;
    }
  }
  if (TEST_FLAGS(*flags2, ENEFLAG2_UNK_4)) {
    q->glowStopReq = TRUE;
    Enemy_EnterState(&p->e, Ax_StateChopRecover, ES_UNK_50);
    CLEAR_FLAGS(q->flags, AXFLAG_BIG_CHOPPING);
    q->shakePower = 64;
    Ax_SpawnChopDust(p, 14);
  }
#else
  INCFUNC("asm/func/Ax_StateBigChopSwing.inc");
#endif
}

// 81/81命令, 残差はレジスタ割り当て, 原典は &q->stepTimer を Div の引数を作るときに r4 に取り減算まで持ち越す (p が r7 に1つずれる)
// 試済: 前置 -- と後置の分離, abs を別の文に, 分岐ごとの u8* ローカル (番地を作る位置が abs の前にずれるだけになる)
// 傾きを 30 フレームかけて 0 に戻し, 残像を黒に戻す
NON_MATCH void Ax_StateStraighten(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;
  s32 d;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->stepTimer = 30;
  }
  d = Ax_WrapAngle(s->aux.spr.rotation);
  if (d > 0) {
    s->aux.spr.rotation -= Div(d, q->stepTimer);
  } else {
    s->aux.spr.rotation += Div(abs(d), q->stepTimer);
  }
  q->stepTimer--;
  if (q->stepTimer == 0) {
    Ax_SetAfterimagePlttID(p, q->blackPltt, 247);
    (p->e).subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/Ax_StateStraighten.inc");
#endif
}

void Ax_StateMove(EneAx* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 1);
  }
}

void Ax_StateWait(EneAx* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 1;
    Enemy_PlayAnimNoFacing(&p->e, 0);
  }
}

// 向きを unk_1dc の8方向へ 32 ずつ回し, 揃ったら待機へ移る
void Ax_StateTurn(EneAx* p) {
  Mover* mover = &(p->e).mover;
  AuxAnimState* anim;
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
    target -= 8;
    if (((cur - target) & 7) <= 4) {
      CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    } else {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
    }
  }
  anim = &(p->e).s->aux.anim;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).stateTimer & 4) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      mover->angle += 32;
    } else {
      mover->angle -= 32;
    }
    Ax_GetAnimVariant(mover->angle, &variant, &flags);
    anim->cmdCount = 0;
    Ax_PlayDirAnim(p, (p->e).animTable[1].anim, variant, flags);
  }
}

void Ax_StateNoticePlayer(EneAx* p, s32 timer) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Ax_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Ax_PlayDirAnim(p, (p->e).animTable[11].anim, variant, flags);
  if (timer < 30) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (timer > 59) {
    (p->e).subStateDone = TRUE;
  }
}

// 被弾で滑り, 止まったら浮遊に戻ってプレイヤーを追い始める
void Ax_StateDamaged(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_PlayAnimNoFacing(&p->e, 3);
    Ax_StopChase(p);
    Ax_ResumeHover(p);
  }
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Ax_ResumeHover(p);
    SET_FLAGS(q->flags, AXFLAG_CHASING);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
    Enemy_ResetState(&p->e, 0, 2, 9);
  }
}

// 倒されたときの状態, 煙を出しながら点滅して消えたら倒されたスクリプトを呼び図鑑に載せて止まる
// 残差は 415/416命令, 倒されたスクリプトの所で &defeatScriptID と argv の番地を置くレジスタだけ (原典は argv を sp から直接書く)
// 試済: argv / sa の宣言位置と順, idx を関数先頭に
NON_MATCH void Ax_StateDying(EneAx* p, s32 timer) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    q->smokeIdx = 0;
    Ax_RemoveClone(p);
  }
  if (Mod(timer, 2) == 0) {
    Vec3 size;
    Vec3 ofs;
    Vec3 at;

    VEC3_SET(size, 60, 60, 40);
    at = (p->e).mover.pos;
    Vec3_Clear(&ofs);
    switch (q->smokeIdx) {
      case 0: {
        ofs.x = -120;
        ofs.z = -120;
        q->smokeIdx++;
        PlaySound_082406e0(SONG_366);
        break;
      }
      case 1: {
        ofs.x = -75;
        ofs.z = -75;
        q->smokeIdx++;
        break;
      }
      case 2: {
        ofs.x = -30;
        ofs.z = -30;
        q->smokeIdx++;
        break;
      }
      case 3: {
        ofs.x = 15;
        ofs.z = 15;
        q->smokeIdx++;
        break;
      }
      case 4: {
        ofs.x = 60;
        ofs.z = 60;
        q->smokeIdx = 0;
        break;
      }
    }
    at.x += FixToInt(12, ofs.x * COS(s->aux.spr.rotation)) + FixToInt(12, ofs.z * SIN(s->aux.spr.rotation));
    at.z += FixToInt(12, -(ofs.x * SIN(s->aux.spr.rotation))) + FixToInt(12, ofs.z * COS(s->aux.spr.rotation));
    EmitSmoke(&at, 2, &size, 0, 0, 22, 2, 1);
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
    (p->e).stunTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
  }
#else
  INCFUNC("asm/func/Ax_StateDying.inc");
#endif
}

// 254/259命令, 原典は近いときの turn の 0 以下判定を遠いときのものと別に残す (こちらは末尾が畳まれる)
// 試済: Vec3_Diff / Vec3_Delta の向き, target を s32 にして & 0xFF, speed ローカルなし, 比較の左右, 遠いときの turn を一時変数経由
// 残像を出しながらプレイヤーへ向きを寄せて進み, 近すぎるときは横へ回り込む
NON_MATCH void Ax_SubApproach(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  s32 target;
  s32 turn;
  Vec3 d;
  Vec3 v;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).s->aux.spr.flags |= SPRFLAG_AFFINE;
    q->orbitDistSq = 512;
  }
  Ax_SpawnAfterimage(p);
  if (q->orbitDistSq > (p->e).playerDistSq) {
    Vec3_Delta(&d, &gPlayerPtr[0]->mover.pos, &(p->e).mover.pos);
    target = ArcTan2_8(d.x, d.z);
    if (abs(Ax_WrapAngle(((target + 64) & 0xFF) - (p->e).mover.angle)) < 64) {
      target += 64;
    } else {
      target += 192;
    }
    target &= 0xFF;
    turn = Div(32, 8);
    if (turn <= 0) {
      turn = 2;
    }
  } else {
    Vec3_Delta(&d, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    target = ArcTan2_8(d.x, d.z);
    turn = FixToInt(3, abs(Ax_WrapAngle(target - (p->e).mover.angle)));
    if (turn <= 0) {
      turn = 2;
    }
  }
  if (Ax_WrapAngle(target - (p->e).mover.angle) > 0) {
    (p->e).mover.angle += turn;
  } else {
    (p->e).mover.angle -= turn;
  }
  Vec3_SetPolar(&v, (p->e).mover.angle, 32);
  (p->e).s->aux.spr.rotation = 159 - (p->e).mover.angle;
  (p->e).mover.delta = v;
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Ax_SubApproach.inc");
#endif
}

void Ax_SubDrift(EneAx* p) {
  EneAx* q = (p->e).owner;

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
    Enemy_ResetState(&p->e, 0, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubChase(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  }
  if ((p->e).tryDetectPlayer(&p->e) && Ax_TryStartAttack(p)) {
    return;
  }
  if ((p->e).hp <= (p->e).unk_546) {
    speed = 8;
    if ((p->e).subStateTimer > 400) {
      Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
  } else if ((p->e).hp <= q->lowHpThreshold) {
    speed = 6;
    if ((p->e).subStateTimer > 500) {
      Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
  } else {
    speed = 4;
    if ((p->e).subStateTimer > 600) {
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
  }
  Vec3_SetPolar(&(p->e).mover.delta, (p->e).playerAngle, speed);
  (p->e).subStateTimer++;
}

void Ax_SubWarp(EneAx* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Enemy_ResetState(&p->e, 0, 0, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubWaitAtNode(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    q->hoverPhase = 0;
  }
  if ((p->e).subStateTimer > 60) {
    Enemy_ResetState(&p->e, 0, 0, 3);
  }
  (p->e).subStateTimer++;
}

void Ax_SetHandlerTable2(EneAx* p) { (p->e).handlerTables[2] = (void*)sAxHandlerTable2; }

// プレイヤーの 220 上に sin で揺らしながら浮かび, 分身も同じ高さに置く
void Ax_FollowPlayerHeight(EneAx* p) {
  EneAx* q = (p->e).owner;

  (p->e).mover.pos.y = gPlayerPtr[0]->mover.pos.y + 220 + FixToInt(12, SIN(q->hoverPhase) * 32);
  q->cloneSprite.pos.y = (p->e).mover.pos.y;
  q->hoverPhase += 2;
}

void Ax_PickRandomPathNode(EneAx* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx;

  idx = Mod(Random(), walker->path->nodeCount);
  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

// 205/211命令, 原典は &offset を r4 に持ってループで使い回し, &hitSize / &hitOffset を最初のループの前から sl/sb に置き, q と &mover.pos を sp に退避する
// 試済: flags の u16 ローカル (原典と同じく lsls/lsrs が出る), &mover.pos のポインタローカル, Vec3_Set inline, do/while
// 本体のやられ判定と攻撃判定, subHurtboxes / subHitboxes を作る
NON_MATCH void Ax_InitHitboxes(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  Vec3 size, offset;
  Vec3 hitSize, hitOffset;
  HitboxFlags flags;
  s32 i;

  VEC3_SET(size, 24, 70, 24);
  VEC3_SET(offset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &size, &offset, Ax_OnHurt, p);
  for (i = 0; i < 2; i++) {
    Hitbox_Init(&q->subHurtboxes[i], (p->e).mover.id, HBF_HURTBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetPowerAndAttributes(&q->subHurtboxes[i], (p->e).power, (p->e).attrs, (p->e).weakness);
    Hitbox_SetPos(&q->subHurtboxes[i], &(p->e).mover.pos, 0);
    Hitbox_SetHandler(&q->subHurtboxes[i], Ax_OnHurt, p);
    Hitbox_Register(&q->subHurtboxes[i]);
  }
  VEC3_SET(hitSize, 24, 64, 24);
  VEC3_SET(hitOffset, 0, 0, 0);
  flags = HBF_HITBOX | HBF_ONCE | HBF_DAMAGE;
  Hitbox_Init(&(p->e).hitbox, (p->e).mover.id, flags, 0, HIM_4, &hitSize, &hitOffset);
  Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
  Hitbox_SetPos(&(p->e).hitbox, &(p->e).mover.pos, 0);
  Hitbox_SetHandler(&(p->e).hitbox, Ax_OnHit, p);
  for (i = 0; i < 2; i++) {
    Hitbox_Init(&q->subHitboxes[i], (p->e).mover.id, flags, 0, HIM_4, &hitSize, &hitOffset);
    Hitbox_SetAttack(&q->subHitboxes[i], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&q->subHitboxes[i], &(p->e).mover.pos, 0);
    Hitbox_SetHandler(&q->subHitboxes[i], Ax_OnHit, p);
  }
#else
  INCFUNC("asm/func/Ax_InitHitboxes.inc");
#endif
}

s32 Ax_GetMoveSpeed(EneAx* p) { return 4; }

void Ax_StartCurve(EneAx* p, Vec3* pos) {
  EneAx* q = (p->e).owner;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
  q->curveT = 0;
}

// curveStart から curveEnd への曲線上の curveT の位置を経路の目的地に置き, curveT を 128 進める, 終点に着いていたら TRUE
// 198/199命令, Ghost_StepCurve / Bee_StepCurve / EneBat_StepCurve / Curoro_StepCurve と同じ壁 (原典はフレーム 0x34 で start/end/d/v を sp+4 から置く, こちらは 0x28)
// 試済: Ghost_StepCurve の C をそのまま
NON_MATCH bool8 Ax_StepCurve(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
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
  INCFUNC("asm/func/Ax_StepCurve.inc");
#endif
}

void Ax_InitAnims(EneAx* p) {
  Enemy_SetAnimEntry(&p->e, 0, 1, 0);
  Enemy_SetAnimEntry(&p->e, 1, 1, 0);
  Enemy_SetAnimEntry(&p->e, 3, 1, 0);
  Enemy_SetAnimEntry(&p->e, 10, 1, 0);
}

void Ax_OnReset(EneAx* p) {
  EneAx* q = (p->e).owner;

  q->curveT = 0;
  q->hoverPhase = 0;
  q->curveBendDir = 1;
  q->curveBend = 0;
  q->flags = (p->e).ownerFlagsInit;
  q->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->curveTangent);
  ClearMemory((p->e).pathNodePos, sizeof(Vec3));
  Enemy_ClearPendingState(&p->e, s_axcom_c_0825221c, 210);
  Enemy_PlayAnim(&p->e, 0);
}

void Ax_ResumeHover(EneAx* p) {
  EneAx* q = (p->e).owner;

  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS(q->flags, AXFLAG_UNK_0 | AXFLAG_CHASING);
  (p->e).hurtbox.flags &= ~HBF_HIDDEN;
}

void Ax_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

void Ax_BeginCurveTo(EneAx* p, Vec3* pos) {
  EneAx* q = (p->e).owner;
  Vec3 diff;

  Ax_StartCurve(p, pos);
  Ax_StepCurve(p);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&diff, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(diff.x, diff.z);
  Vec3_Clear(&q->curveTangent);
}

void Ax_StopChase(EneAx* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  CLEAR_FLAGS(((EneAx*)(p->e).owner)->flags, AXFLAG_CHASING);
  (p->e).chaseTimer = 0;
}

// 追っている間に追跡時間が尽きたら, 乱数の経路ノードへの曲線移動に切り替える
void Ax_UpdateChaseTimeout(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if (!Ax_TestFlags(q, AXFLAG_CHASING)) {
    (p->e).chaseTimer = 0;
    return;
  }
  if ((p->e).chaseTimer != 0) {
    (p->e).chaseTimer--;
    return;
  }
  Ax_PickRandomPathNode(p);
  {
    WorldPos pos;
    WorldPos* dst = &pos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    Ax_BeginCurveTo(p, &pos);
    Ax_StopChase(p);
    Ax_ResumeHover(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

// '.P' から技ごとの間隔を読み, 待ちを 0 にして lowHpThreshold を決める
void Ax_ReadAttackIntervals(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  if (VM_SeekToNamedArg('P')) {
    for (i = 0; i < 4; i++) {
      q->attackIntervals[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  for (i = 0; i < 4; i++) {
    q->attackCooldowns[i] = 0;
  }
  q->lowHpThreshold = (p->e).hp - FixToInt(2, (p->e).hp);
}

// 技ごとの待ちを減らす
void Ax_TickAttackCooldowns(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (q->attackCooldowns[i] != 0) {
      q->attackCooldowns[i]--;
    }
  }
}

// 技の待ちと hp から出す技を選んで副状態を移す, 選べたら TRUE
bool8 Ax_TryStartAttack(EneAx* p) {
  EneAx* q = (p->e).owner;

  if ((p->e).hp <= (p->e).unk_546 && q->attackCooldowns[3] == 0) {
    Enemy_ResetState(&p->e, 0, 2, 8);
    return TRUE;
  }
  if (q->attackCooldowns[0] == 0 && (p->e).playerDistSq < 0xFFFF) {
    if (abs(Ax_WrapAngle((p->e).playerAngle - 160)) < 42) {
      Enemy_ResetState(&p->e, 0, 2, 0);
    } else {
      Enemy_ResetState(&p->e, 0, 2, 2);
    }
    return TRUE;
  }
  if (q->lowHpThreshold >= (p->e).hp) {
    if (q->attackCooldowns[1] == 0) {
      Enemy_ResetState(&p->e, 0, 2, 4);
      return TRUE;
    }
    if (q->attackCooldowns[2] == 0) {
      Enemy_ResetState(&p->e, 0, 2, 6);
      return TRUE;
    }
  }
  return FALSE;
}

void Ax_ClearRecentNodes(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    q->recentNodes[i] = -1;
  }
  q->recentNodeIdx = 0;
}

void Ax_PushRecentNode(EneAx* p, s32 param_2) {
  EneAx* q = (p->e).owner;

  q->recentNodes[q->recentNodeIdx] = param_2;
  q->recentNodeIdx++;
  if (q->recentNodeIdx > 2) {
    q->recentNodeIdx = 0;
  }
}

s32 Ax_IsRecentNode(EneAx* p, s32 param_2) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->recentNodes[i] == param_2) {
      return TRUE;
    }
  }
  return FALSE;
}

// プレイヤーの位置を控え, 索敵範囲に入っていれば TRUE
bool8 Ax_TryDetectPlayer(EneAx* p) {
  EneAx* q;

  if (Enemy_IsDead(&p->e)) {
    return FALSE;
  }
  q = (p->e).owner;
  q->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if ((p->e).playerDistSq < (p->e).range0Sq) {
    return TRUE;
  }
  return FALSE;
}

void Ax_OnAttackRequest(EneAx* p) {}

// 155/155命令, 残差は &q->flags を作る位置だけ, 原典は glowStopReq を読んでから番地を作る
// 試済: flags ローカルの位置 (if の前, 宣言時の初期化, カンマ式), 立てる/落とすの順
// glowStartReq / glowStopReq を受けて, glowPltt の赤を 10 フレームごとに強めたり弱めたりする
NON_MATCH void Ax_UpdateGlow(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  AxFlags* flags;

  if (q->glowStartReq) {
    q->glowStep = 0;
    q->glowTimer = 0;
    SET_FLAGS(q->flags, AXFLAG_GLOWING);
    q->glowStartReq = FALSE;
  }
  flags = &q->flags;
  if (q->glowStopReq) {
    *flags = (*flags | AXFLAG_UNGLOWING) & ~AXFLAG_GLOWING;
    q->glowStep = 3;
    q->glowTimer = 0;
    q->glowStopReq = FALSE;
  }
  if (!Ax_TestFlagsAt(flags, AXFLAG_GLOWING | AXFLAG_UNGLOWING)) {
    return;
  }
  (p->e).s->aux.gfx.plttID = 250;
  (p->e).s->aux.gfx.pltt = q->glowPltt;
  switch (q->glowStep) {
    case 0: {
      q->glowPltt[1] = 0;
      break;
    }
    case 1: {
      q->glowPltt[1] = 16;
      break;
    }
    case 2: {
      q->glowPltt[1] = 24;
      break;
    }
    case 3: {
      q->glowPltt[1] = 31;
      break;
    }
  }
  if (++q->glowTimer > 9) {
    if (Ax_TestFlagsAt(flags, AXFLAG_GLOWING)) {
      if (q->glowStep < 3) {
        q->glowStep++;
      }
    } else if (--q->glowStep == 0) {
      Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
      CLEAR_FLAGS(*flags, AXFLAG_UNGLOWING);
      return;
    }
    q->glowTimer = 0;
  }
#else
  INCFUNC("asm/func/Ax_UpdateGlow.inc");
#endif
}

// 100/100命令, 残差は glowStep の進め方の分岐の並びだけ (原典は 0 を入れる側が先)
// 試済: 三項演算子の向き, if/else, 格納先のポインタローカル
// 光らせ始めたら glowPltt の赤を 10 フレームごとに強めて弱めるのを繰り返す, どこからも呼ばれない
NON_MATCH void Ax_UpdateGlowLoop(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;

  if (q->glowStartReq) {
    (p->e).s->aux.gfx.plttID = 250;
    (p->e).s->aux.gfx.pltt = q->glowPltt;
    q->glowStep = 0;
    q->glowTimer = 0;
    q->glowStartReq = FALSE;
  }
  if (q->glowStopReq) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
    q->glowStopReq = FALSE;
    return;
  }
  if ((p->e).s->aux.gfx.plttID != 250) {
    return;
  }
  switch (q->glowStep) {
    case 0:
    case 6: {
      q->glowPltt[1] = 0;
      break;
    }
    case 1:
    case 5: {
      q->glowPltt[1] = 16;
      break;
    }
    case 2:
    case 4: {
      q->glowPltt[1] = 24;
      break;
    }
    case 3: {
      q->glowPltt[1] = 31;
      break;
    }
  }
  if (++q->glowTimer > 9) {
    u8* step = &q->glowStep;

    *step = *step < 6 ? *step + 1 : 0;
    q->glowTimer = 0;
  }
#else
  INCFUNC("asm/func/Ax_UpdateGlowLoop.inc");
#endif
}

// 今の色 (フェード前なら fromPlttID の色) から toPlttID の色へ steps 歩で寄せるフェードを始める
void Ax_StartPaletteFade(EneAx* p, s32 toPlttID, s32 fromPlttID, s32 steps) {
  EneAx* self = p;
  WormPaletteFade* fade = &self->plttFade;
  rgb555* dst = &gObjPlttData[toPlttID * 16];
  rgb555* src = &gObjPlttData[fromPlttID * 16];
  s32 i;

  fade->plttID = toPlttID;
  for (i = 0; i < 16; i++) {
    s32 color = fade->timer != 256 ? fade->pltt[i] : src[i];

    fade->stepR[i] = ((dst[i] & 31) - (color & 31)) << 8;
    fade->stepG[i] = (((dst[i] >> 5) & 31) - ((color >> 5) & 31)) << 8;
    fade->stepB[i] = (((dst[i] >> 10) & 31) - ((color >> 10) & 31)) << 8;
    fade->stepR[i] = Div(fade->stepR[i], steps);
    fade->stepG[i] = Div(fade->stepG[i], steps);
    fade->stepB[i] = Div(fade->stepB[i], steps);
    fade->r[i] = (color & 31) << 8;
    fade->g[i] = ((color >> 5) & 31) << 8;
    fade->b[i] = ((color >> 10) & 31) << 8;
  }
  fade->timer = steps;
  SET_FLAGS(self->flags, AXFLAG_FADING);
}

// plttFade を1歩進めて本体と残像のパレットに繋ぐ, 歩数を使い切ったら TRUE
bool8 Ax_StepPaletteFade(EneAx* p) {
  EneAx* q;
  WormPaletteFade* fade;
  EnemyFlags* flags;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return FALSE;
  }
  q = (p->e).owner;
  if (!Ax_TestFlags(q, AXFLAG_FADING)) {
    return FALSE;
  }
  fade = &q->plttFade;
  if (fade->timer == 0) {
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
      (p->e).s->aux.gfx.pltt = fade->pltt;
      Ax_SetAfterimagePltt(p, fade->pltt);
    }
    return TRUE;
  }
  flags = &(p->e).flags;
  for (i = 0; i < 16; i++) {
    fade->r[i] += fade->stepR[i];
    fade->g[i] += fade->stepG[i];
    fade->b[i] += fade->stepB[i];
    fade->pltt[i] = FixToInt(8, fade->r[i]) | (FixToInt(8, fade->g[i]) << 5) | (FixToInt(8, fade->b[i]) << 10);
  }
  fade->timer--;
  if (!TEST_FLAGS(*flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
    (p->e).s->aux.gfx.pltt = fade->pltt;
    Ax_SetAfterimagePltt(p, fade->pltt);
  }
  if (fade->timer == 0) {
    return TRUE;
  }
  return FALSE;
}

// 黒, 赤, 青, 白の単色パレットと, 今のパレットの写しを作る
void Ax_InitPltts(EneAx* p) {
  EneAx* q = (p->e).owner;
  rgb555* src = *(rgb555**)&(p->e).s->main.spr.animFlags;
  s32 i;

  for (i = 0; i < 16; i++) {
    q->blackPltt[i] = 0;
    q->redPltt[i] = 0x1F;
    q->bluePltt[i] = 0x7C00;
    q->whitePltt[i] = 0x7FFF;
    q->glowPltt[i] = src[i];
  }
}

// 残像のパレットを pltt に繋ぐ
void Ax_SetAfterimagePltt(EneAx* p, rgb555* pltt) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    q->afterimages[i].gfx.pltt = pltt;
  }
}

// 残像のパレットを plttID 番の pltt に替える
void Ax_SetAfterimagePlttID(EneAx* p, rgb555* pltt, s32 plttID) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    q->afterimages[i].gfx.plttID = plttID;
    q->afterimages[i].gfx.pltt = pltt;
  }
}

void Ax_InitAfterimages(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    Video_GetAuxSprite(&q->afterimages[i].gfx, SPR_SWORD_AX);
    AuxSprite_Add(&q->afterimages[i].sprite, &q->afterimages[i].gfx, 0);
    q->afterimages[i].gfx.plttID = 247;
    q->afterimages[i].gfx.pltt = q->blackPltt;
    q->afterimages[i].animFile = GetFile(DIR_ANIMATION, ANIM_SWORDAX);
    q->afterimages[i].sprite.flags = SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    q->afterimages[i].timer = 0;
  }
  q->nextAfterimage = 0;
  q->afterimageInterval = 2;
}

// 256/256命令, 残差は AuxSprite_AdvanceAnim の後で &q->nextAfterimage を置くレジスタ (原典 r4, こちら r5) だけ
// 試済: self 写し, nextAfterimage のポインタローカル, anim ローカルなし, 後置 ++ を別の文に, AuxSprite_TestFlags, EnemySprite* ローカル
// afterimageInterval フレームごとに, 今のアニメ・傾き・拡大率と位置を次の残像へ写して 8 フレーム見せる
NON_MATCH void Ax_SpawnAfterimage(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;

  if (!((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN) && Mod((p->e).unk_1ca, q->afterimageInterval) == 0) {
    AuxAnimState* anim = &(p->e).s->aux.anim;
    u16 animIdx = anim->animIdx;

    AuxAnim_SetAnim(&q->afterimages[q->nextAfterimage].anim, q->afterimages[q->nextAfterimage].animFile, animIdx, 0, 0);
    AuxSprite_AdvanceAnim(&q->afterimages[q->nextAfterimage].sprite, &q->afterimages[q->nextAfterimage].anim);
    q->afterimages[q->nextAfterimage].sprite.pos = (p->e).mover.pos;
    q->afterimages[q->nextAfterimage].sprite.flags &= ~SPRFLAG_HIDDEN;
    q->afterimages[q->nextAfterimage].sprite.flags |= SPRFLAG_AFFINE;
    q->afterimages[q->nextAfterimage].timer = 8;
    q->afterimages[q->nextAfterimage].sprite.rotation = (p->e).s->aux.spr.rotation;
    q->afterimages[q->nextAfterimage].sprite.scaleX = (p->e).s->aux.spr.scaleX;
    q->afterimages[q->nextAfterimage].sprite.scaleY = (p->e).s->aux.spr.scaleY;
    if (++q->nextAfterimage > 3) {
      q->nextAfterimage = 0;
    }
  }
#else
  INCFUNC("asm/func/Ax_SpawnAfterimage.inc");
#endif
}

// 260/260命令, 残差は p と定数 1 を置く高位レジスタ (r8/sb) の入れ替わりだけ, Ax_SpawnAfterimage と同じ系統
// 試済: angle を u32 に, AuxSprite_TestFlags, EnemySprite* ローカル, self 写し, animIdx ローカルなし
// Ax_SpawnAfterimage と同じだが, 位置を pos, 傾きを angle にした残像を出す
NON_MATCH void Ax_SpawnAfterimageAt(EneAx* p, Vec3* pos, u32 angle) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;

  if (!((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN) && Mod((p->e).unk_1ca, q->afterimageInterval) == 0) {
    AuxAnimState* anim = &(p->e).s->aux.anim;
    u16 animIdx = anim->animIdx;

    AuxAnim_SetAnim(&q->afterimages[q->nextAfterimage].anim, q->afterimages[q->nextAfterimage].animFile, animIdx, 0, 0);
    AuxSprite_AdvanceAnim(&q->afterimages[q->nextAfterimage].sprite, &q->afterimages[q->nextAfterimage].anim);
    q->afterimages[q->nextAfterimage].sprite.pos = *pos;
    q->afterimages[q->nextAfterimage].sprite.flags &= ~SPRFLAG_HIDDEN;
    q->afterimages[q->nextAfterimage].sprite.flags |= SPRFLAG_AFFINE;
    q->afterimages[q->nextAfterimage].timer = 8;
    q->afterimages[q->nextAfterimage].sprite.rotation = angle;
    q->afterimages[q->nextAfterimage].sprite.scaleX = (p->e).s->aux.spr.scaleX;
    q->afterimages[q->nextAfterimage].sprite.scaleY = (p->e).s->aux.spr.scaleY;
    if (++q->nextAfterimage > 3) {
      q->nextAfterimage = 0;
    }
  }
#else
  INCFUNC("asm/func/Ax_SpawnAfterimageAt.inc");
#endif
}

void Ax_TickAfterimages(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (q->afterimages[i].timer != 0 && --q->afterimages[i].timer == 0) {
      q->afterimages[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
}

void Ax_RemoveAfterimages(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (q->afterimages[i].sprite.active) {
      AuxSprite_Remove(&q->afterimages[i].sprite);
    }
  }
}

// 127/138命令, Skeleton_PickFarPathNode と同じ壁, 原典はノードのポインタを sp+0x14 の構造体に置き差の Vec3 と bestIdx まで sp に退避する
// 試済: 差を from の写しから組む, ループ内の PathWalker と &d のポインタ, best/bestIdx の初期化位置, w.node の2段代入
// from から maxDist 以内で最近使っていない一番遠い経路ノードを選び, 無ければ乱数で選んで to にその位置を入れる
NON_MATCH void Ax_PickFarPathNode(EneAx* p, Vec3* to, Vec3* from, s32 maxDist) {
#ifdef NONMATCHING_C
  PathWalker w;
  s32 best = 0;
  s32 bestIdx = -1;
  s32 i;
  PathNode* nodes;

  Map_InitPathWalker(&w, 0, 0, 0);
  for (i = 0; i < w.path->nodeCount; i++) {
    PathNode* node = &Map_GetPathNodes(w.path)[i];
    Vec3 d = *from;
    s32 dist;

    d.x = node->x - d.x;
    d.z = node->y - d.z;
    dist = d.x * d.x + d.z * d.z;
    if (dist <= maxDist && dist > best && !Ax_IsRecentNode(p, i)) {
      best = dist;
      bestIdx = i;
    }
  }
  if (best == 0) {
    bestIdx = Mod(Random(), w.path->nodeCount);
  }
  Ax_PushRecentNode(p, bestIdx);
  w.nodeIdx = bestIdx;
  w.waitTimer = 0;
  nodes = Map_GetPathNodes(w.path);
  to->x = nodes[w.nodeIdx].x;
  to->y = (p->e).floorY;
  to->z = nodes[w.nodeIdx].y;
#else
  INCFUNC("asm/func/Ax_PickFarPathNode.inc");
#endif
}

void Ax_SpawnChopDust(EneAx* p, u32 count) {
  AuxSprite* s = &(p->e).s->aux.spr;
  Vec3 size;
  Vec3 pos;
  Vec3 ofs;
  Vec3 vel;

  VEC3_SET(size, 120, 60, 120);
  pos = s->pos;
  Vec3_Clear(&ofs);
  Vec3_Clear(&vel);
  ofs.x = -140;
  ofs.z = -140;
  pos.x += FixToInt(12, ofs.x * COS(s->rotation)) + FixToInt(12, ofs.z * SIN(s->rotation));
  pos.z += FixToInt(12, -(ofs.x * SIN(s->rotation))) + FixToInt(12, ofs.z * COS(s->rotation));
  DustManager_Spawn(&pos, &vel, &size, count, 2, 4);
}

// 2 フレームごとに, pos から angle の向きに並んだ5か所のうち次の1か所に煙を出す
void Ax_EmitLineSmoke(EneAx* p, Vec3* pos, u32 angle, s32 timer) {
  EneAx* q = (p->e).owner;

  if (Mod(timer, 2) == 0) {
    Vec3 size;
    Vec3 ofs;
    Vec3 at;

    VEC3_SET(size, 60, 60, 40);
    at = *pos;
    Vec3_Clear(&ofs);
    switch (q->smokeIdx) {
      case 0: {
        ofs.x = -120;
        ofs.z = -120;
        q->smokeIdx++;
        break;
      }
      case 1: {
        ofs.x = -75;
        ofs.z = -75;
        q->smokeIdx++;
        break;
      }
      case 2: {
        ofs.x = -30;
        ofs.z = -30;
        q->smokeIdx++;
        break;
      }
      case 3: {
        ofs.x = 15;
        ofs.z = 15;
        q->smokeIdx++;
        break;
      }
      case 4: {
        ofs.x = 60;
        ofs.z = 60;
        q->smokeIdx = 0;
        break;
      }
    }
    at.x += FixToInt(12, ofs.x * COS(angle)) + FixToInt(12, ofs.z * SIN(angle));
    at.z += FixToInt(12, -(ofs.x * SIN(angle))) + FixToInt(12, ofs.z * COS(angle));
    EmitSmoke(&at, 2, &size, 0, 0, 22, 2, 1);
  }
}

// shakeTimer が残っている間, 画面を揺らす
void Ax_UpdateCameraShake(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_6) && q->shakeTimer != 0) {
    Camera_Shake(q->shakePower);
    q->shakeTimer--;
  }
}

// timer が進むほど短い間隔で flags の bit0 を反転させる, 60 を超えたら bit0 を立てて TRUE
bool8 Ax_BlinkAccel(u32* flags, s32 timer, s32 slowEnd, s32 midEnd) {
  s32 idx;

  if (timer > midEnd) {
    idx = 2;
  } else if (timer > slowEnd) {
    idx = 1;
  } else {
    idx = 0;
  }
  if (Mod(timer, sBlinkIntervalsAccel[idx]) == 0) {
    if (*flags & 1) {
      *flags &= ~1;
    } else {
      *flags |= 1;
    }
  }
  if (timer > 60) {
    *flags |= 1;
    return TRUE;
  }
  return FALSE;
}

// timer が進むほど長い間隔で flags の bit0 を反転させる, 60 を超えたら bit0 を立てて TRUE
bool8 Ax_BlinkDecel(u32* flags, s32 timer, s32 slowEnd, s32 midEnd) {
  s32 idx;

  if (timer > midEnd) {
    idx = 2;
  } else if (timer > slowEnd) {
    idx = 1;
  } else {
    idx = 0;
  }
  if (Mod(timer, sBlinkIntervalsDecel[idx]) == 0) {
    if (*flags & 1) {
      *flags &= ~1;
    } else {
      *flags |= 1;
    }
  }
  if (timer > 60) {
    *flags |= 1;
    return TRUE;
  }
  return FALSE;
}

void Ax_InitClone(EneAx* p) {
  EneAx* q = (p->e).owner;
  Vec3 size, offset;
  Vec3 hitSize, hitOffset;
  s32 i;

  Video_GetAuxSprite(&q->cloneGfx, SPR_SWORD_AX);
  AuxSprite_Add(&q->cloneSprite, &q->cloneGfx, 0);
  {
    AuxAnimFile* file = GetFile(DIR_ANIMATION, ANIM_SWORDAX);
    AuxAnimState* anim = &(p->e).s->aux.anim;
    u16 animIdx = anim->animIdx;

    AuxAnim_SetAnim(&q->cloneAnim, file, animIdx, 0, 0);
  }
  AuxSprite_AdvanceAnim(&q->cloneSprite, &q->cloneAnim);
  q->cloneSprite.flags |= SPRFLAG_HIDDEN;
  q->cloneSprite.pos = (p->e).mover.pos;
  q->cloneSprite.priority = 1;
  VEC3_SET(size, 24, 70, 24);
  VEC3_SET(offset, 0, 0, 0);
  for (i = 0; i < 3; i++) {
    Hitbox_Init(&q->cloneHurtboxes[i], 0, HBF_HURTBOX | HBF_ACTOR | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetPowerAndAttributes(&q->cloneHurtboxes[i], 0, 0, 0);
    Hitbox_SetPos(&q->cloneHurtboxes[i], &q->clonePos, 0);
    Hitbox_SetHandler(&q->cloneHurtboxes[i], Ax_OnCloneHurt, q);
    Hitbox_Register(&q->cloneHurtboxes[i]);
  }
  VEC3_SET(hitSize, 24, 64, 24);
  VEC3_SET(hitOffset, 0, 0, 0);
  for (i = 0; i < 3; i++) {
    Hitbox_Init(&q->cloneHitboxes[i], 0, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, HIM_4, &hitSize, &hitOffset);
    Hitbox_SetAttack(&q->cloneHitboxes[i], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&q->cloneHitboxes[i], &q->clonePos, 0);
    Hitbox_SetHandler(&q->cloneHitboxes[i], Ax_OnCloneHit, q);
  }
  q->cloneShadowResult = ParticleShadow_Init(&q->cloneShadow, &q->cloneSprite.pos, 0);
  ParticleShadow_Hide(&q->cloneShadow);
}

// 分身の攻撃判定とやられ判定を分身の位置に置き, 攻撃判定を登録する
void Ax_UpdateCloneHitboxes(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    Hitbox_SetPos(&q->cloneHurtboxes[i], &q->cloneSprite.pos, 0);
    Hitbox_SetPos(&q->cloneHitboxes[i], &q->cloneSprite.pos, 0);
    Hitbox_Register(&q->cloneHitboxes[i]);
  }
}

void Ax_RemoveClone(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  if (q->cloneSprite.active) {
    for (i = 0; i < 3; i++) {
      Hitbox_Unregister(&q->cloneHurtboxes[i]);
    }
    ParticleShadow_Remove(&q->cloneShadow);
    AuxSprite_Remove(&q->cloneSprite);
  }
}

void Ax_SetClonePos(EneAx* p, Vec3* pos) {
  EneAx* q = (p->e).owner;

  q->cloneSprite.pos = *pos;
}

// 分身のパレットを plttID 番の pltt に替える
void Ax_SetClonePltt(EneAx* p, rgb555* pltt, s32 plttID) {
  EneAx* q = (p->e).owner;

  q->cloneGfx.plttID = plttID;
  q->cloneGfx.pltt = pltt;
}

void Ax_InitAfterimageHitboxes(EneAx* p) {
  EneAx* q = (p->e).owner;
  Vec3 size, offset;
  s32 i;

  VEC3_SET(size, 24, 64, 24);
  VEC3_SET(offset, 0, 0, 0);
  for (i = 0; i < 3; i++) {
    Hitbox_Init(&q->afterimageHitboxes[i], (p->e).mover.id, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetAttack(&q->afterimageHitboxes[i], (p->e).atkPower[3], (p->e).atkKnockback[3], 0, (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    Hitbox_SetPos(&q->afterimageHitboxes[i], &(p->e).mover.pos, 0);
    Hitbox_SetHandler(&q->afterimageHitboxes[i], Ax_OnHit, p);
  }
}

void Ax_UpdateAfterimageHitboxes(EneAx* p) {
  EneAx* q = (p->e).owner;
  AuxSprite* spr;
  s32 last;
  s32 i;

  if (q->nextAfterimage == 0) {
    last = 3;
  } else {
    last = q->nextAfterimage - 1;
  }
  spr = &q->afterimages[last].sprite;
  for (i = 0; i < 3; i++) {
    Vec3 ofs;
    Vec3 pos;

    Vec3_Clear(&ofs);
    pos = q->afterimagePos;
    switch (i) {
      case 0: {
        ofs.x = -120;
        ofs.z = -120;
        break;
      }
      case 1: {
        ofs.x = -30;
        ofs.z = -30;
        break;
      }
      case 2: {
        ofs.x = 60;
        ofs.z = 60;
        break;
      }
    }
    pos.x += FixToInt(12, ofs.x * COS(spr->rotation)) + FixToInt(12, ofs.z * SIN(spr->rotation));
    pos.z += FixToInt(12, -(ofs.x * SIN(spr->rotation))) + FixToInt(12, ofs.z * COS(spr->rotation));
    Hitbox_SetPos(&q->afterimageHitboxes[i], &pos, 0);
    Hitbox_Register(&q->afterimageHitboxes[i]);
  }
}

void Ax_UnregisterSubHurtboxes(EneAx* p) {
  EneAx* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 2; i++) {
    Hitbox_Unregister(&q->subHurtboxes[i]);
  }
}

// 本体と sub の攻撃判定・やられ判定を斧の傾きに沿って3か所に並べる, 潜っているときは全部隠す
void Ax_UpdateBodyHitboxes(EneAx* p) {
  EneAx* q = (p->e).owner;
  EnemySprite* s = (p->e).s;
  s32 i;
  s32 j;

  for (i = 0; i < 3; i++) {
    Vec3 ofs;
    Vec3 pos;

    if (Ax_TestFlags(q, AXFLAG_HIDDEN) || Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_11)) {
      Hitbox_Hide(&(p->e).hitbox);
      Hitbox_Hide(&(p->e).hurtbox);
      for (j = 0; j < 2; j++) {
        Hitbox_Hide(&q->subHurtboxes[j]);
        Hitbox_Hide(&q->subHitboxes[j]);
      }
      return;
    }
    Hitbox_ClearFlags(&(p->e).hitbox, HBF_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBF_HIDDEN);
    for (j = 0; j < 2; j++) {
      Hitbox_ClearFlags(&q->subHurtboxes[j], HBF_HIDDEN);
      Hitbox_ClearFlags(&q->subHitboxes[j], HBF_HIDDEN);
    }
    Vec3_Clear(&ofs);
    pos = (p->e).mover.pos;
    switch (i) {
      case 0: {
        ofs.x = -120;
        ofs.z = -120;
        break;
      }
      case 1: {
        ofs.x = -30;
        ofs.z = -30;
        break;
      }
      case 2: {
        ofs.x = 60;
        ofs.z = 60;
        break;
      }
    }
    pos.x += FixToInt(12, ofs.x * COS(s->aux.spr.rotation)) + FixToInt(12, ofs.z * SIN(s->aux.spr.rotation));
    pos.z += FixToInt(12, -(ofs.x * SIN(s->aux.spr.rotation))) + FixToInt(12, ofs.z * COS(s->aux.spr.rotation));
    if (i == 0) {
      Hitbox_SetPos(&(p->e).hurtbox, &pos, 0);
      Hitbox_SetPos(&(p->e).hitbox, &pos, 0);
      Hitbox_Register(&(p->e).hitbox);
    } else {
      Hitbox_SetPos(&q->subHurtboxes[i - 1], &pos, 0);
      Hitbox_SetPos(&q->subHitboxes[i - 1], &pos, 0);
      Hitbox_Register(&q->subHitboxes[i - 1]);
    }
  }
}

// 出している技に合わせて本体と subHitboxes の攻撃判定の攻撃パラメータを載せ替える, 振り下ろし(大)は atkPower[2] と atkKnockback[2] の倍
void Ax_UpdateAttackPower(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Ax_TestFlags(q, AXFLAG_CHOPPING)) {
    Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
    Hitbox_SetAttack(&q->subHitboxes[0], (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
    Hitbox_SetAttack(&q->subHitboxes[1], (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  } else if (Ax_TestFlags(q, AXFLAG_BIG_CHOPPING)) {
    s32 power = (p->e).atkPower[2] * 2;
    s32 knockback = (p->e).atkKnockback[2] * 2;

    Hitbox_SetAttack(&(p->e).hitbox, power, knockback, 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
    Hitbox_SetAttack(&q->subHitboxes[0], power, knockback, 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
    Hitbox_SetAttack(&q->subHitboxes[1], power, knockback, 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  } else if (Ax_TestFlags(q, AXFLAG_SPINNING)) {
    Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    Hitbox_SetAttack(&q->subHitboxes[0], (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    Hitbox_SetAttack(&q->subHitboxes[1], (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
  } else if (Ax_TestFlags(q, AXFLAG_CHARGED_SPIN)) {
    Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetAttack(&q->subHitboxes[0], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetAttack(&q->subHitboxes[1], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
  } else {
    Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetAttack(&q->subHitboxes[0], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetAttack(&q->subHitboxes[1], (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
  }
}

// '.O' から技の調整値を読む
void Ax_ReadAttackParams(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (VM_SeekToNamedArg('O')) {
    q->chargedSpinTurnRate = VM_GetPC() != NULL ? VM_GetValue() : 6;
    q->chargedSpinSpeed = VM_GetPC() != NULL ? VM_GetValue() : 12;
    q->bigChopWait = VM_GetPC() != NULL ? VM_GetValue() : 60;
    q->bigChopRaiseSpeed = VM_GetPC() != NULL ? VM_GetValue() : 3;
    q->hideTime = VM_GetPC() != NULL ? VM_GetValue() : 60;
    q->cloneSlideTime = VM_GetPC() != NULL ? VM_GetValue() : 30;
  }
}

s32 Ax_PreUpdate(EneAx* p) {
  Ax_FollowPlayerHeight(p);
  Ax_UpdateChaseTimeout(p);
  Ax_UpdateGlow(p);
  return 1;
}

s32 Ax_PostUpdate(EneAx* p) {
  Ax_UpdateCameraShake(p);
  Ax_TickAfterimages(p);
  Ax_StepPaletteFade(p);
  Ax_UpdateBodyHitboxes(p);
  Ax_TickAttackCooldowns(p);
  Ax_UpdateAttackPower(p);
  return 1;
}

void Ax_SubStartSpin(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_AnimSpin, ES_UNK_33);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    SET_FLAGS(q->flags, AXFLAG_SPINNING);
  }
  Ax_SpawnAfterimage(p);
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubEndSpin(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    CLEAR_FLAGS(q->flags, AXFLAG_SPINNING);
    Enemy_ResetState(&p->e, 0, 0, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubStartChop(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateChopRaise, ES_UNK_48);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    SET_FLAGS(q->flags, AXFLAG_CHOPPING);
    q->attackCooldowns[0] = q->attackIntervals[0];
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubEndChop(EneAx* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ResetState(&p->e, 0, 0, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubStartBigChop(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateBigChopRaise, ES_UNK_52);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    SET_FLAGS(q->flags, AXFLAG_BIG_CHOPPING);
    q->attackCooldowns[1] = q->attackIntervals[1];
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 5);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubEndBigChop(EneAx* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ResetState(&p->e, 0, 0, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubStartChargedSpin(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateWindUp, ES_UNK_38);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    SET_FLAGS(q->flags, AXFLAG_CHARGED_SPIN);
    q->attackCooldowns[2] = q->attackIntervals[2];
    Ax_SetAfterimagePlttID(p, q->redPltt, 248);
    q->glowStartReq = TRUE;
    PlaySound_082406e0(SONG_367);
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 2, 7);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubEndChargedSpin(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->glowStopReq = TRUE;
  }
  if ((p->e).subStateDone) {
    Ax_SetAfterimagePlttID(p, q->blackPltt, 247);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    CLEAR_FLAGS(q->flags, AXFLAG_CHARGED_SPIN);
    Enemy_ResetState(&p->e, 0, 0, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubShadowAttack(EneAx* p) {
  EneAx* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateCloneSplit, ES_UNK_41);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    q->attackCooldowns[3] = q->attackIntervals[3];
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Ax_StateVanish, ES_UNK_34);
    Enemy_ResetState(&p->e, 0, 0, 4);
  } else {
    (p->e).subStateTimer++;
  }
}

// プレイヤーのまわりの曲線の点を順にたどって飛び, 終点に着くたびに速さを半分にする
// 残差は 471/466命令, Ghost の FUN_0816e3b8 と同じ壁 (原典は &mover.pos と &curvePointIdx を r7/r6 に持ち, 退避するレジスタが少ない)
// 試済: Ghost の C から曲線を引き直す呼び出しを除いた形, dest を関数先頭で1つに, 差をスカラーで, &mover.pos のポインタローカル
NON_MATCH void Ax_SubCirclePlayer(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  Vec3 d;
  WorldPos dest;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, (u8)Random(), 512);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Vec3_SetPolar(&q->curveTangent, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 32);
    q->curveSpeed = 1;
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  Ax_SpawnAfterimage(p);
  if (d.x * d.x + d.z * d.z > 1024) {
    (p->e).mover.angle = ArcTan2_8(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z);
    (p->e).mover.delta.x += POLAR_X(q->curveSpeed, (p->e).mover.angle);
    (p->e).mover.delta.z += POLAR_Z(q->curveSpeed, (p->e).mover.angle);
    q->curveTangent = (p->e).mover.delta;
  } else if (++q->curvePointIdx > 8) {
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
    q->curveSpeed >>= 1;
  }
  if (Mod((p->e).subStateTimer, 16) == 0 && q->curveSpeed < 12) {
    q->curveSpeed++;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Ax_SubCirclePlayer.inc");
#endif
}

// Ax_SubCirclePlayer と同じく曲線の点をたどるが, 速さを半分にせず 18 まで上げる
// 残差は Ax_SubCirclePlayer と同じ
NON_MATCH void Ax_SubCirclePlayerFast(EneAx* p) {
#ifdef NONMATCHING_C
  EneAx* q = (p->e).owner;
  Vec3 d;
  WorldPos dest;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    q->curvePointIdx = 0;
    dest = gPlayerPtr[0]->mover.pos;
    Vec3_SetPolar(&d, (u8)Random(), 512);
    dest.x += d.x;
    dest.z += d.z;
    Vec3_Diff(&d, &dest, &(p->e).mover.pos);
    Vec3_SetPolar(&q->curveTangent, ((Random() & 63) + (p->e).playerAngle) & 0xFF, 32);
    q->curveSpeed = 1;
  }
  Vec3_Diff(&d, &q->curvePoints[q->curvePointIdx], &(p->e).mover.pos);
  Ax_SpawnAfterimage(p);
  if (d.x * d.x + d.z * d.z > 1024) {
    (p->e).mover.angle = ArcTan2_8(q->curvePoints[q->curvePointIdx].x - (p->e).mover.pos.x, q->curvePoints[q->curvePointIdx].z - (p->e).mover.pos.z);
    (p->e).mover.delta.x += POLAR_X(q->curveSpeed, (p->e).mover.angle);
    (p->e).mover.delta.z += POLAR_Z(q->curveSpeed, (p->e).mover.angle);
    q->curveTangent = (p->e).mover.delta;
  } else if (++q->curvePointIdx > 8) {
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
  }
  if (Mod((p->e).subStateTimer, 16) == 0 && q->curveSpeed < 18) {
    q->curveSpeed++;
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Ax_SubCirclePlayerFast.inc");
#endif
}

void Ax_SetHandlerTable4(EneAx* p) { (p->e).handlerTables[4] = (void*)sAxHandlerTable4; }

void Ax_StartChase(EneAx* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Ax_StateNoticePlayer, ES_UNK_10);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
  }
  if ((p->e).subStateDone) {
    Ax_BeginCurveTo(p, &gPlayerPtr[0]->mover.pos);
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SubWander(EneAx* p) {
  EneAx* q = (p->e).owner;

  Enemy_ConsumeSubStateBegun(&p->e);
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer > 60) {
    Ax_PickRandomPathNode(p);
    {
      WorldPos pos;
      WorldPos* dst = &pos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      Ax_StartCurve(p, &pos);
      Ax_StepCurve(p);
      Enemy_ResetState(&p->e, 0, 0, 1);
      Vec3_Diff(&pos, &pos, &(p->e).mover.pos);
      (p->e).unk_1dc = ArcTan2_8(pos.x, pos.z);
      Vec3_Clear(&q->curveTangent);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

void Ax_SetHandlerTable3(EneAx* p) { (p->e).handlerTables[3] = (void*)sAxHandlerTable3; }

// 被弾音を鳴らし, 3 回続けて被弾したら溜め回転斬りに入る
bool8 Ax_OnDamaged(EneAx* p) {
  EneAx* q = (p->e).owner;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (q->hitStreak < 3) {
    q->hitStreak++;
  }
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) && !Ax_TestFlags(q, AXFLAG_WARPING) && q->hitStreak > 2) {
    Enemy_ResetState(&p->e, 0, 2, 6);
    q->hitStreak = 0;
    return TRUE;
  }
  return TRUE;
}

s32 Ax_UpdateFrame(EneAx* p) {
  Ax_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Ax_PostUpdate(p);
  return 1;
}

s32 Ax_Update(EneAx* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Ax_Destroy(EneAx* p) {
  Ax_UnregisterSubHurtboxes(p);
  Ax_RemoveAfterimages(p);
  Ax_RemoveClone(p);
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
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 残差は 1686/1856命令の下書き, Ghost_Init の C から Ax 用に置き換えた形, 原典は大量のフィールドの番地を sp に退避して使い回す (フレーム 0x1AC, こちらは 0x44)
// ユーザーの指示で1回の下書きで打ち切り
NON_MATCH s32 Ax_Init(EneAx* p) {
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
  (p->e).kind = ENEK_AX;
  Ax_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPR_SWORD_AX);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_SWORDAX);
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
    f = GetFile(DIR_MAIN_SPRITE, SPR_SWORD_AX);
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

  Mover_Init(&(p->e).mover, id, &pos, 0, MOVER_ENEMY, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_SALAMANDER) {
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
  Ax_ReadAttackIntervals(p);
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).tileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);
  }
  p->spawnFloorY = (p->e).floorY;
  Ax_ReadAttackParams(p);
  p->prevPlayerPos = gPlayerPtr[0]->mover.pos;
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 301;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 301;
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
  Ax_InitPltts(p);
  (p->e).unk_47e = 384;
  Ax_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Ax_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Ax_GetMoveSpeed;
  (p->e).handlerTurn = Ax_StateTurn;
  (p->e).handlerMove = Ax_StateMove;
  (p->e).handlerWait = Ax_StateWait;
  (p->e).handlerNap = NULL;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Ax_StateDamaged;
  (p->e).handlerDying = Ax_StateDying;
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
  (p->e).handlerStun = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  (p->e).onReset = (EnemyHandler)Ax_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Ax_OnAttackRequest;
  (p->e).unk_5b0 = NULL;
  (p->e).tryDetectPlayer = (void*)Ax_TryDetectPlayer;
  (p->e).onDamaged = (void*)Ax_OnDamaged;
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5 | ENEFLAG5_UNK_6);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10 | ENEFLAG2_UNK_20 | ENEFLAG2_UNK_25);
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
    (p->e).hurtbox.flags &= ~HBF_ANGLE;
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
  Ax_SetHandlerTable2(p);
  Ax_SetHandlerTable4(p);
  Ax_SetHandlerTable3(p);
  (p->e).s->aux.spr.priority = 1;
  (p->e).unk_1bc = 0;
  Ax_InitAfterimages(p);
  Ax_ClearRecentNodes(p);
  Ax_InitAfterimageHitboxes(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Ax_Update;
  (p->e).handlerDestroy = (EnemyHandler)Ax_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Ax_Init.inc");
#endif
}

void Ax_Create(void) {
  EneAx* p = Malloc(sizeof(EneAx));

  if (p != NULL) {
    ClearMemory(p, sizeof(EneAx));
    if (Ax_Init(p) < 0) {
      Ax_Destroy(p);
      Free(p);
    }
  }
}
