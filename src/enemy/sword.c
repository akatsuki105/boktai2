#include "constants/sprite_palette.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

struct EneSword;

// EneSwordBody.flags
typedef u8 EneSwordBodyFlags;
#define SWORDFLAG_ENTERED (1 << 0)  // 0x1, 状態を差し替えると立ち, その状態の最初のフレームで落とす
#define SWORDFLAG_UNK_4 (1 << 4)    // 0x10, 立っている間は mode の更新関数を呼ばない

// 本体の剣とスレイブソードが同じ並びで持つ動きと状態, 両者の初期化は同じ順に書き込む
typedef struct {
  Vec3 vel;                 // 0x00, 毎フレーム座標に足す
  Vec3 accel;               // 0x08, y だけ使う, ±1 で vel.y を上下させて浮かせる
  Vec3 knockback;           // 0x10, 被弾で付く速さ, 本体は毎フレーム半分にしながら座標に足す
  u8 unk_18[2];             // 0x18
  s16 hp;                   // 0x1A, 本体は '.A[0]', スレイブソードは EneSword.slaveHP
  s16 power;                // 0x1C, 本体は '.A[1]', 食らい判定の power
  s16 unk_1e;               // 0x1E, 本体は '.A[2]'
  s16 unk_20;               // 0x20, 本体は '.A[3]', 被弾時に攻撃側の damage に足す
  s16 weaponExp;            // 0x22, 本体は '.X[1]', 倒されたとき Player_AddWeaponExp に渡す量
  s16 weakness;             // 0x24, 本体は '.A[5]', 食らい判定の weakness
  s16 attrs;                // 0x26, 本体は '.A[4]', 食らい判定の attrs
  u8 idx;                   // 0x28, スレイブソードの番号, 本体は使わない
  EneSwordBodyFlags flags;  // 0x29
  u8 angle;                 // 0x2A, スレイブソードが被弾で弾かれる向き
  u8 unk_2b[3];             // 0x2B
  u8 mode;                  // 0x2E, 更新関数の表の添字, 0 なら何もしない
  u8 state;                 // 0x2F, 状態番号, stateFn と一緒に書き換える, 本体は 6, スレイブソードは 5 がやられ
  u8 unk_30[6];             // 0x30
  u16 unk_36;               // 0x36
  s16 flashTimer;           // 0x38, 被弾で 8, 尽きると元のパレットに戻す
  u8 unk_3a;                // 0x3A
  u8 unk_3b;                // 0x3B
  u8 vanishTimer;           // 0x3C, やられて点滅しながら消えるまでのフレーム数
  u8 smokeCount;            // 0x3D, やられたときに出す煙の残りの回数
  u8 unk_3e;                // 0x3E, 状態に入ったときに 0 に戻す
  u8 unk_3f;                // 0x3F
  u16 exp;                  // 0x40, 本体は '.X[0]', 倒されたとき AddPlayerExp に渡す量
  u8 unk_42[2];             // 0x42
} EneSwordBody;
static_assert(sizeof(EneSwordBody) == 68);

// スレイブソード, 本体の周りを回って飛んでくる小さい剣, こちらの攻撃で弾き返せる
typedef struct SlaveSword {
  AuxSprite sprite;                            // 0x000
  AuxSpriteGfx gfx;                            // 0x02C, SPR_SLAVE_SWORD_AX
  Hitbox hitbox;                               // 0x048, EneSword.slaveAtk* の攻撃判定
  Hitbox hurtbox;                              // 0x098, EneSword_OnSlaveSwordHurt を呼ぶ食らい判定
  EneSwordBody body;                           // 0x0E8
  Vec3 moveTo;                                 // 0x12C, 直線で動くときの行き先
  Vec3 moveFrom;                               // 0x134, 直線で動き始めた位置
  Vec3 moveDelta;                              // 0x13C, moveTo - moveFrom
  Vec3 homeOffset;                             // 0x144, ブーメランで飛び出したときの orbitCenter からのずれ, 戻る先を決める
  Vec3 returnCenter;                           // 0x14C, ブーメランで戻り始めたときの orbitCenter, 戻る間に本体が動いた分だけ行き先をずらす
  Vec3* orbitCenter;                           // 0x154, 本体の sprite.pos を指す
  struct EneSword* owner;                      // 0x158
  void (*stateFn)(struct SlaveSword*);         // 0x15C
  void (*flashFn)(struct SlaveSword*);         // 0x160, 被弾で EneSword_UpdateSlaveFlash, 戻し終わると NULL
  void (*subStateFns[5])(struct SlaveSword*);  // 0x164, body.state ごとの下位処理
  s32 bobTimer;                                // 0x178, 尽きるたびに accel.y を反転して 40 に戻す
  s32 timer;                                   // 0x17C
  u8 targetRotation;                           // 0x180, sprite.rotation をこの値まで回す
  u8 orbitAngle;                               // 0x181, orbitCenter から見た向き, 半径 200 で回る
  s8 orbitDir;                                 // 0x182, 回る向き, 1 か -1
  s8 spinSpeed;                                // 0x183, 1フレームに sprite.rotation を orbitDir だけ回す回数, 8 フレームごとに増えて 7 で止まる
  u8 unk_184;                                  // 0x184
  s8 rotSpeed;                                 // 0x185, 毎フレーム sprite.rotation に足す
  s8 scaleXSpeed;                              // 0x186, 出現するとき毎フレーム sprite.scaleX に足す
  s8 scaleYSpeed;                              // 0x187, 同じく sprite.scaleY に足す
  u8 unk_188[4];                               // 0x188
} SlaveSword;
static_assert(sizeof(SlaveSword) == 396);

// ENEK_SWORD, "ソード"という名前の見た目が剣の敵
// variant: ENEID_SWORD, ENEID_SWORD_P
// 技: 接触, 残像, スレイブソード(小さい剣を飛ばして攻撃してくる(こちらの攻撃で弾き返せる))
// これだけ Enemy でなく Entity から作る
typedef struct EneSword {
  Entity e;                                      // 0x000, ENTITY_UNK_8
  Player* player;                                // 0x018, gPlayerPtr[0]
  EneSwordBody body;                             // 0x01C
  AuxSprite afterimageSprites[4];                // 0x060
  AuxSpriteGfx afterimageGfx[4];                 // 0x110, SPR_SWORD_AX
  Hitbox afterimageHitboxes[4];                  // 0x180, atkPower[1] ほかの攻撃判定
  Hitbox afterimageHurtboxes[4];                 // 0x2C0, 本体と同じ body.power の食らい判定
  Vec3 afterimageStarts[4];                      // 0x400, プレイヤーのそばに出し直した残像の初めの位置, ここからプレイヤーへ寄せる
  Vec3 playerPos;                                // 0x420, player の mover.pos の写し
  Vec3 toPlayer;                                 // 0x428, playerPos - sprite.pos
  Vec3 moveFrom;                                 // 0x430, 回転攻撃でプレイヤーへ飛び始めた位置
  s32 afterimageAngles[4];                       // 0x438, 周りを回る残像ごとの向き
  s8 spinSpeed;                                  // 0x448, 回転攻撃では sprite.rotation に, 残像を回すときは afterimageAngles に毎フレーム足す
  u8 playerAngle;                                // 0x449, toPlayer の向き
  u8 bladeAngle;                                 // 0x44A, 剣先の向き, 当たり判定をこの向きに沿ってずらす
  u8 unk_44b;                                    // 0x44B
  u16 spinTimer;                                 // 0x44C, 回転攻撃で回り始めてからのフレーム数
  u8 unk_44e[2];                                 // 0x44E
  s32 orbitRadius;                               // 0x450, 残像が回る半径
  SlaveSword slaves[4];                          // 0x454, slaveCount 個だけ使う
  rgb555 blackPltt[16];                          // 0xA84, 全色 0, OBP 247 で残像に使う
  rgb555 origPltt[16];                           // 0xAA4, gfx の元のパレットの写し
  u16 slaveInterval;                             // 0xAC4, '.M[0]=60', スレイブソードを1本ずつ呼び出す間隔
  u16 slaveTimer;                                // 0xAC6, 次のスレイブソードを呼び出すまでの残りフレーム
  u16 orbitCount;                                // 0xAC8, '.M[1]=2', 周りを回す残像の数
  u16 orbitRadiusMax;                            // 0xACA, '.M[2]=80', orbitRadius をここまで広げる
  u16 orbitRadiusStep;                           // 0xACC, '.M[3]=1', 4 フレームごとに orbitRadius を広げ縮めする量
  u8 unk_ace[0xAE0 - 0xACE];                     // 0xACE
  AuxSprite sprite;                              // 0xAE0, pos は '.p'
  AuxSpriteGfx gfx;                              // 0xB0C, SPR_SWORD_AX
  AuxShadow shadow;                              // 0xB28
  Hitbox hitbox;                                 // 0xB94, atkPower[0] ほかの攻撃判定, EneSword_OnHit
  Hitbox hurtbox;                                // 0xBE4, EneSword_OnHurt を呼ぶ食らい判定
  s8 colorR;                                     // 0xC34, pltt[1] の赤, glowFn が上げ下げして赤く光らせる
  s8 colorG;                                     // 0xC35, pltt[1] の緑
  s8 colorB;                                     // 0xC36, pltt[1] の青
  u8 unk_c37;                                    // 0xC37
  void (*stateFn)(struct EneSword*);             // 0xC38
  u8 unk_c3c[4];                                 // 0xC3C
  void (*postStateFn)(struct EneSword*);         // 0xC40, stateFn の後に呼ぶ, NULL なら呼ばない
  void (*subStateFns[5])(struct EneSword*);      // 0xC44, body.state 1〜5 の下位処理, [state - 1]
  void (*slaveNextStateFn)(struct SlaveSword*);  // 0xC58, スレイブソードに次に移らせる状態
  void (*flashFn)(struct EneSword*);             // 0xC5C, 被弾で EneSword_UpdateFlash, 戻し終わると NULL
  bool8 (*glowFn)(struct EneSword*);             // 0xC60, colorR を段階ごとに動かす, 明滅を1周し終えたフレームに 1 を返す
  s32 timer;                                     // 0xC64
  s32 bobTimer;                                  // 0xC68, 尽きるたびに accel.y を反転して 40 に戻す
  s32 glowTimer;                                 // 0xC6C, glowFn の段階の中の経過フレーム
  u32 floorY;                                    // 0xC70, 出現から 8 フレーム後に sprite.pos の床の高さを入れる
  s16 atkPower[2];                               // 0xC74, '.T[0]' と '.T[4]', [0] は hitbox, [1] は afterimageHitboxes
  s16 atkKnockback[2];                           // 0xC78, '.T[1]' と '.T[5]'
  s16 atkAttrs[2];                               // 0xC7C, '.T[2]' と '.T[6]'
  s16 atkIframes[2];                             // 0xC80, '.T[3]' と '.T[7]'
  s16 slaveHP;                                   // 0xC84, '.c[0]'
  s16 slavePower;                                // 0xC86, '.c[1]'
  s16 unk_c88;                                   // 0xC88, '.c[2]'
  s16 unk_c8a;                                   // 0xC8A, '.c[3]', スレイブソードの被弾時に攻撃側の damage に足す
  s16 slaveAttrs;                                // 0xC8C, '.c[5]'
  s16 slaveWeakness;                             // 0xC8E, '.c[6]'
  s16 slaveAtkPower;                             // 0xC90, '.C[0]'
  s16 slaveAtkKnockback;                         // 0xC92, '.C[1]'
  s16 slaveAtkAttrs;                             // 0xC94, '.C[2]'
  s16 slaveAtkIframes;                           // 0xC96, '.C[3]'
  u16 unk_c98;                                   // 0xC98
  u16 unk_c9a;                                   // 0xC9A, スレイブソードを呼ぶ状態に入ってからのフレーム数, 1024 フレームごとに slaveNextStateFn を入れ替える
  u8 slaveCount;                                 // 0xC9C, '.n=4'
  u8 slaveAngle;                                 // 0xC9D, スレイブソードを並べる向きの基準, 番号 * 256 / slaveCount を足す
  u16 dyingFrames;                               // 0xC9E, やられてからのフレーム数, 奇数フレームだけ姿を出して点滅する
  rgb555 pltt[16];                               // 0xCA0, gfx.pltt がここを指す
  u8 unk_cc0[2];                                 // 0xCC0
  s8 glowPhaseLen;                               // 0xCC2, 5, glowFn の1段階のフレーム数
  s8 glowCount;                                  // 0xCC3, 明滅を終えた回数
  u8 glowHold;                                   // 0xCC4, 立っている間は一番明るいところで止める
  u8 plttVariant;                                // 0xCC5, '.t=0' 0: ENEID_SWORD, 1: ENEID_SWORD_P
  u16 plttID;                                    // 0xCC6, OBP_SWORDAX(plttVariant)
  u16 flashPlttID;                               // 0xCC8, OBP_WHITE_306, 被弾したときのパレット
  s16 spinPhase;                                 // 0xCCA, spinSpeed を積んで 256 を超えるたびに風切り音を鳴らす
  s16 maxHP;                                     // 0xCCC, body.hp の初期値
  u8 unk_cce;                                    // 0xCCE, '.K=2', HUD_ShowEnemyGauge の第4引数
  u8 smokeStep;                                  // 0xCCF, やられたときに煙を出す位置の段階, 0〜4 を繰り返す
  u32 hurtTypeMask;                              // 0xCD0, 当たってきた攻撃の typeMask
  HitboxAttrs hurtAttributes;                    // 0xCD4, 当たってきた攻撃の attributes
  u32 defeatScriptID;                            // 0xCD8, '.e', 倒されたときに VM_ExecByID するスクリプト ID
  u32 defeatScriptArgs[2];                       // 0xCDC, '.a[0]', '.a[1]', defeatScriptID のスクリプトに渡す引数
  u16 damage;                                    // 0xCE4, 受けたダメージ, EneSword_ShowDamage が数字を出して 0 に戻す
  u16 hitResult;                                 // 0xCE6, 0 でなければ EneSword_Update が EneSword_ShowDamage を呼ぶ
  u16 id;                                        // 0xCE8, EneSword_Create の id, HUD_ShowEnemyGauge に渡す
  u8 unk_cea;                                    // 0xCEA, '.c[4]'
  u8 unk_ceb;                                    // 0xCEB
  s32 frameCount;                                // 0xCEC, 毎フレーム増える
  u16 orbitFrames;                               // 0xCF0, 残像を回し始めてからのフレーム数
  u8 unk_cf2[2];                                 // 0xCF2
} EneSword;
static_assert(sizeof(EneSword) == 3316);

// state に移って最初のフレームの印を立てる
static inline void EneSwordBody_SetState(EneSwordBody* b, s32 mode, s32 state) {
  b->mode = mode;
  b->state = state;
  SET_FLAGS(b->flags, SWORDFLAG_ENTERED);
}

// 状態に入った最初のフレームなら印を落として TRUE を返す
static inline bool8 EneSwordBody_ConsumeEntered(EneSwordBody* b) {
  if (TEST_FLAGS(b->flags, SWORDFLAG_ENTERED)) {
    CLEAR_FLAGS(b->flags, SWORDFLAG_ENTERED);
    b->unk_3e = 0;
    return TRUE;
  }
  return FALSE;
}

const s32 s32_ARRAY_085add90[3] = {-100, 0, 100};  // 0x085ADD90
const s32 s32_ARRAY_085add9c[3] = {-70, 0, 130};   // 0x085ADD9C

bool8 EneSword_GlowRise1(EneSword* p);
bool8 EneSword_GlowRise2(EneSword* p);
bool8 EneSword_GlowRise3(EneSword* p);
bool8 EneSword_GlowFall1(EneSword* p);
bool8 EneSword_GlowFall2(EneSword* p);
bool8 EneSword_GlowFall3(EneSword* p);
bool8 EneSword_GlowHold(EneSword* p);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, s32 maxHP, s32 cells, s32 flash);
void EneSword_ChaseMove(EneSword* p);
void EneSword_StateOrbit(EneSword* p);
void EneSword_StateChase(EneSword* p);
void EneSword_UpdateFlash(EneSword* p);
void EneSword_StateDying(EneSword* p);
void EneSword_SummonWait(EneSword* p);
void EneSword_StateSummon(EneSword* p);
void EneSword_StateWarp(EneSword* p);
void EneSword_SpinCharge(EneSword* p);
void EneSword_OrbitExpand(EneSword* p);
void EneSword_OrbitChase(EneSword* p);
void EneSword_OrbitShrink(EneSword* p);
void EneSword_OrbitChaseShrink(EneSword* p);
void EneSword_WarpMove(EneSword* p);
void EneSword_WarpAppear(EneSword* p);
void EneSword_DashMove(EneSword* p);
void EneSword_SummonSlaves(EneSword* p);
void EneSword_DashEnd(EneSword* p);
void EneSword_DashAim(EneSword* p);
void EneSword_DashGlow(EneSword* p);
void EneSword_StateIdle(EneSword* p);
void EneSword_SlaveAppearSettle(SlaveSword* p);
void EneSword_WarpConverge(EneSword* p);
void EneSword_SlaveBoomerangOut(SlaveSword* p);
void EneSword_SlaveThrustReturn(SlaveSword* p);
void EneSword_SlaveThrustEnd(SlaveSword* p);
void EneSword_SlaveStateAppear(SlaveSword* p);
void EneSword_SlaveStateOrbit(SlaveSword* p);
void EneSword_UpdateSlaveFlash(SlaveSword* p);
void EneSword_SlaveSetMoveToHere(SlaveSword* p);
void EneSword_SlaveStateDying(SlaveSword* p);
void EneSword_SlaveBoomerangBounced(SlaveSword* p);
void EneSword_SlaveThrustBounced(SlaveSword* p);
void EneSword_SlaveSpinBounced(SlaveSword* p);
void EneSword_SlaveBoomerangReturn(SlaveSword* p);
void EneSword_SlaveBoomerangSpinUp(SlaveSword* p);
void EneSword_SlaveThrustAim(SlaveSword* p);
void EneSword_SlaveSpinFlyZ(SlaveSword* p);
void EneSword_SlaveSpinFlyX(SlaveSword* p);
void EneSword_SlaveStateBoomerang(SlaveSword* p);
void EneSword_SlaveStateThrust(SlaveSword* p);
void EneSword_SlaveStateSpin(SlaveSword* p);
void EneSword_SlaveThrustWait(SlaveSword* p);
void EneSword_SlaveSpinReturnX(SlaveSword* p);
void EneSword_SlaveSpinReturnZ(SlaveSword* p);
void EneSword_StateDash(EneSword* p);
void EneSword_SlaveThrustMove(SlaveSword* p);
void EneSword_SlaveSpinUp(SlaveSword* p);
void EneSword_SlaveAppearStretch(SlaveSword* p);
void EneSword_SlaveOrbitMove(SlaveSword* p);

// 赤く光る明滅を始める, 緑と青は今の色のまま使う, 原典は return を書いていない
bool8 EneSword_GlowBegin(EneSword* p) {
  p->colorG = (p->pltt[1] >> 5) & 0x1F;
  p->colorB = (p->pltt[1] >> 10) & 0x1F;
  p->glowFn = EneSword_GlowRise1;
}

// 赤を 0 から 16 まで上げる
bool8 EneSword_GlowRise1(EneSword* p) {
  p->colorR = Div(p->glowTimer << 4, p->glowPhaseLen);
  if (p->glowTimer++ == p->glowPhaseLen) {
    p->glowFn = EneSword_GlowRise2;
    p->glowTimer = 0;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// 赤を 16 から 24 まで上げる
bool8 EneSword_GlowRise2(EneSword* p) {
  p->colorR = Div(p->glowTimer << 3, p->glowPhaseLen) + 16;
  if (p->glowTimer++ == p->glowPhaseLen) {
    p->glowFn = EneSword_GlowRise3;
    p->glowTimer = 0;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// 赤を 24 から 31 まで上げる, glowHold が立っていればそこで止める
bool8 EneSword_GlowRise3(EneSword* p) {
  p->colorR = Div(p->glowTimer * 7, p->glowPhaseLen) + 24;
  if (p->glowTimer++ == p->glowPhaseLen) {
    if (p->glowHold == 0) {
      p->glowFn = EneSword_GlowFall1;
    } else {
      p->glowFn = EneSword_GlowHold;
    }
    p->glowTimer = p->glowPhaseLen;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// 赤を 31 から 24 まで下げる
bool8 EneSword_GlowFall1(EneSword* p) {
  p->colorR = Div(p->glowTimer * 7, p->glowPhaseLen) + 24;
  if (--p->glowTimer == -1) {
    p->glowFn = EneSword_GlowFall2;
    p->glowTimer = p->glowPhaseLen;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// 赤を 24 から 16 まで下げる
bool8 EneSword_GlowFall2(EneSword* p) {
  p->colorR = Div(p->glowTimer << 3, p->glowPhaseLen) + 16;
  if (--p->glowTimer == -1) {
    p->glowFn = EneSword_GlowFall3;
    p->glowTimer = p->glowPhaseLen;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// 赤を 16 から 0 まで下げる, 下げきったら明滅を1周終えたとして TRUE を返す
bool8 EneSword_GlowFall3(EneSword* p) {
  p->colorR = Div(p->glowTimer << 4, p->glowPhaseLen);
  if (--p->glowTimer == -1) {
    p->glowFn = EneSword_GlowBegin;
    p->glowTimer = 0;
    p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
    return TRUE;
  }
  p->pltt[1] = (p->colorB << 10) | (p->colorG << 5) | p->colorR;
  return FALSE;
}

// glowHold が落ちるまで一番明るい色のまま待つ
bool8 EneSword_GlowHold(EneSword* p) {
  bool8 ret;
  if (p->glowHold) {
    ret = TRUE;
  } else {
    p->glowFn = EneSword_GlowFall1;
    ret = FALSE;
  }
  return ret;
}

// 光らせずに pltt[1] の色を控えるだけ, 原典は return を書いていない
bool8 EneSword_GlowNone(EneSword* p) {
  p->colorR = p->pltt[1] & 0x1F;
  p->colorG = (p->pltt[1] >> 5) & 0x1F;
  p->colorB = (p->pltt[1] >> 10) & 0x1F;
}

// 食らい判定をプレイヤーの高さに置き, x と z をフレームごとに -100, 0, 100 とずらす, どこからも使われていない
// 残差は表の番地の ldr が sprite.pos の番地より1命令早いだけ, 原典は表の値を x と z で2回読む
// Tier A-C は試済 (要素ポインタ, 値のローカル, 加算順, 添字の分離)
NON_MATCH void EneSword_SweepHurtbox(EneSword* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 i = Mod(p->frameCount, 3);
  const s32* ofs = s32_ARRAY_085add90;
  pos.x = p->sprite.pos.x + ofs[i];
  pos.y = p->player->mover.pos.y + 220;
  pos.z = p->sprite.pos.z + ofs[i];
  Hitbox_SetPos(&p->hurtbox, &pos, 0);
#else
  INCFUNC("asm/func/EneSword_SweepHurtbox.inc");
#endif
}

// 本体と残像の当たり判定を, 剣先の向きに沿ってフレームごとに -70, 0, 130 ずらした位置に置く
// 残差は表の番地の ldr が lsls の後に1命令ずれるだけ (190/190 命令), 原典は表の値を毎回読み直すので const を外した読み方で近づく, EneSword_SweepHurtbox と同じ表の壁
// Tier A-C は試済 (要素ポインタ, 添字のローカル, 先頭ポインタのローカル, *(s32*)&tbl[n])
NON_MATCH void EneSword_UpdateHitboxes(EneSword* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 n;
  s32 i;
  p->bladeAngle = 0x1C - p->sprite.rotation;
  n = Mod(p->frameCount, 3);
  pos.x = p->sprite.pos.x + Div(COS(p->bladeAngle) * ((s32*)s32_ARRAY_085add9c)[n], 0x1000);
  pos.y = p->player->mover.pos.y + 220;
  pos.z = p->sprite.pos.z + Div(SIN(p->bladeAngle) * ((s32*)s32_ARRAY_085add9c)[n], 0x1000);
  Hitbox_SetPos(&p->hitbox, &pos, 0);
  Hitbox_SetPos(&p->hurtbox, &pos, 0);
  if (!(p->hitbox.flags & HBF_HIDDEN)) {
    Hitbox_Register(&p->hitbox);
  }
  for (i = 0; i < 4; i++) {
    pos.x = p->afterimageSprites[i].pos.x + Div(COS(p->bladeAngle) * ((s32*)s32_ARRAY_085add9c)[n], 0x1000);
    pos.y = p->player->mover.pos.y + 220;
    pos.z = p->afterimageSprites[i].pos.z + Div(SIN(p->bladeAngle) * ((s32*)s32_ARRAY_085add9c)[n], 0x1000);
    if (!(p->afterimageHitboxes[i].flags & HBF_HIDDEN)) {
      Hitbox_Register(&p->afterimageHitboxes[i]);
    }
    Hitbox_SetPos(&p->afterimageHitboxes[i], &pos, 0);
    Hitbox_SetPos(&p->afterimageHurtboxes[i], &pos, 0);
  }
#else
  INCFUNC("asm/func/EneSword_UpdateHitboxes.inc");
#endif
}

// 当たり判定を, プレイヤーの高さとの差を 724/1024 倍して x と z にもずらした位置に置く
// 残差は ofs.y の式だけ, 原典は sprite.pos.y - 220 を先に作ってから引く, こちらは player.y + 220 - sprite.pos.y に畳まれる (85/86 命令)
// Tier A-B は試済 (s16 / s32 / u16 の中間ローカル, y のローカル, a - b + 220 の順)
NON_MATCH void EneSword_SlaveUpdateHitboxes(SlaveSword* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3 ofs;
  ofs.y = p->owner->player->mover.pos.y - (p->sprite.pos.y - 220);
  ofs.x = ofs.z = (ofs.y * 724) >> 10;
  pos.x = p->sprite.pos.x + ofs.x;
  pos.y = p->sprite.pos.y + ofs.y;
  pos.z = p->sprite.pos.z + ofs.z;
  Hitbox_SetPos(&p->hurtbox, &pos, 0);
  Hitbox_SetPos(&p->hitbox, &pos, 0);
  if (!(p->hitbox.flags & HBF_HIDDEN)) {
    Hitbox_Register(&p->hitbox);
  }
#else
  INCFUNC("asm/func/EneSword_SlaveUpdateHitboxes.inc");
#endif
}

void EneSword_OnHit(Hitbox* a, Hitbox* b, EneSword* p) {}

// 被弾で HP を減らして白く光らせ, 倒されたら state 6 (やられ) に移って撃破数を数える
// 残差は hurtTypeMask の番地を flashFn の番地から足して作る形, 撃破数の加算でのレジスタと定数の作り方 (353/367 命令), 撃破数の系統別の加算は Enemy_AddKillCount (NAKED) と同じ処理の可能性
// Tier A-B は試済 (count ポインタ, TOTAL_ENEMY_KILL の三項演算子, s32 の bonus ローカル)
NON_MATCH void EneSword_OnHurt(Hitbox* a, Hitbox* b, EneSword* p) {
#ifdef NONMATCHING_C
  if (p->stateFn == EneSword_StateDying) {
    return;
  }
  if (p->hurtbox.iframes != 0) {
    if (p->hitResult != 0) {
      b->damage = 0;
      b->hitResult = 0;
    }
    return;
  }
  Hitbox_ApplyDamage(a, b);
  b->iframes = a->iframes;
  if (p->flashFn == NULL && b->damage != 0) {
    p->hurtTypeMask = a->typeMask;
    p->hurtAttributes = a->attributes;
    p->body.flashTimer = 8;
    p->flashFn = EneSword_UpdateFlash;
    Video_SetAuxSpritePltt(p->sprite.gfx, p->flashPlttID);
    p->body.hp -= b->damage;
    if (p->body.hp < 0) {
      b->damage += p->body.hp;
    }
    {
      s32 bonus = p->body.unk_20;
      a->damage += bonus;
    }
    if (p->body.hp <= 0) {
      s16* count;
      u32 attrs;
      s32 kills;
      p->body.hp = 0;
      EneSwordBody_SetState(&p->body, 1, 6);
      p->stateFn = EneSword_StateDying;
      count = &gStat->totalEnemyKillCount;
      *count = (*count < 9999) ? *count + 1 : 9999;
      attrs = p->hurtbox.attributes;
      count = &gStat->enemyKillCount[ENEF_SWORD];
      *count = (*count < 9999) ? *count + 1 : 9999;
      if (attrs & HBATTR_BEAST) {
        kills = gStat->killCounts[0] + 1;
        if (kills > 9999) {
          kills = 9999;
        } else if (kills < 0) {
          kills = 0;
        }
        gStat->killCounts[0] = kills;
      } else if (attrs & HBATTR_THING) {
        kills = gStat->killCounts[1] + 1;
        if (kills > 9999) {
          kills = 9999;
        } else if (kills < 0) {
          kills = 0;
        }
        gStat->killCounts[1] = kills;
      } else if (attrs & HBATTR_PHANTOM) {
        kills = gStat->killCounts[2] + 1;
        if (kills > 9999) {
          kills = 9999;
        } else if (kills < 0) {
          kills = 0;
        }
        gStat->killCounts[2] = kills;
      } else if (attrs & HBATTR_UNDEAD) {
        kills = gStat->killCounts[3] + 1;
        if (kills > 9999) {
          kills = 9999;
        } else if (kills < 0) {
          kills = 0;
        }
        gStat->killCounts[3] = kills;
      } else if (attrs & HBATTR_IMMORTAL) {
        kills = gStat->killCounts[4] + 1;
        if (kills > 9999) {
          kills = 9999;
        } else if (kills < 0) {
          kills = 0;
        }
        gStat->killCounts[4] = kills;
      }
      switch (a->ignoreMask) {
        case HIM_0: {
          UNK_948(0) = (UNK_948(0) < 9999) ? (UNK_948(0) + 1) : 9999;
          break;
        }
        case HIM_1: {
          UNK_948(1) = (UNK_948(1) < 9999) ? (UNK_948(1) + 1) : 9999;
          break;
        }
        case HIM_2: {
          UNK_948(2) = (UNK_948(2) < 9999) ? (UNK_948(2) + 1) : 9999;
          break;
        }
        case HIM_3: {
          UNK_948(3) = (UNK_948(3) < 9999) ? (UNK_948(3) + 1) : 9999;
          break;
        }
      }
    }
  }
  if (b->damage != 0) {
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
  } else {
    PlaySound_082406e0(SONG_400);
  }
  if (p->body.state == 1) {
    p->body.knockback.x = -p->body.vel.x * 4;
    p->body.knockback.z = -p->body.vel.z * 4;
  }
  p->damage = b->damage;
  p->hitResult = b->hitResult;
#else
  INCFUNC("asm/func/EneSword_OnHurt.inc");
#endif
}

void EneSword_ResetHover(EneSword* p) {
  p->body.vel.x = 0, p->body.vel.y = 0, p->body.vel.z = 0;
  p->body.accel.x = 0, p->body.accel.y = 1, p->body.accel.z = 0;
  p->bobTimer = 20;
}

void EneSword_UpdateHover(EneSword* p) {
  if ((p->bobTimer & 3) == 0) {
    p->body.vel.y += p->body.accel.y;
  }
  if (--p->bobTimer == 0) {
    p->body.accel.y = -p->body.accel.y;
    p->bobTimer = 40;
  }
  p->sprite.pos.y += p->body.vel.y;
}

void EneSword_UpdateFloorY(EneSword* p) {
  if (p->frameCount > 7) {
    p->floorY = Map_GetTileHeightAt(&p->sprite.pos);
  }
}

// 追いかけ始めるまで timer だけ待つ
void EneSword_ChaseWait(EneSword* p) {
  if (--p->timer == 0) {
    p->timer = 300;
    p->subStateFns[0] = EneSword_ChaseMove;
  }
}

// プレイヤーへ向かって進み, timer が尽きたら state 3 (残像を回す) に移る, z にも knockback.x を足している
void EneSword_ChaseMove(EneSword* p) {
  s32 cos;
  s32 sin;
  p->playerPos.x = p->player->mover.pos.x;
  p->playerPos.y = p->player->mover.pos.y;
  p->playerPos.z = p->player->mover.pos.z;
  p->toPlayer.x = p->playerPos.x - p->sprite.pos.x;
  p->toPlayer.y = p->playerPos.y - p->sprite.pos.y;
  p->toPlayer.z = p->playerPos.z - p->sprite.pos.z;
  p->playerAngle = ArcTan2_8(p->toPlayer.x, p->toPlayer.z);
  cos = COS(p->playerAngle);
  sin = SIN(p->playerAngle);
  p->body.vel.x = FixToInt(10, cos);
  p->body.vel.z = FixToInt(10, sin);
  p->sprite.pos.x += p->body.vel.x + p->body.knockback.x;
  p->sprite.pos.z += p->body.vel.z + p->body.knockback.x;
  p->body.knockback.x = FixToInt(1, p->body.knockback.x);
  p->body.knockback.z = FixToInt(1, p->body.knockback.z);
  if (--p->timer == 0) {
    p->timer = 300;
    EneSwordBody_SetState(&p->body, 1, 3);
    p->stateFn = EneSword_StateOrbit;
    p->subStateFns[0] = EneSword_ChaseWait;
  }
}

// 回転攻撃の前に赤く2回光る
void EneSword_SpinGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 1) {
    p->glowCount = 0;
    p->subStateFns[1] = EneSword_SpinCharge;
  }
}

// 150 フレームかけて回転を上げ, 突進の行き先 (プレイヤーの上) を決める
void EneSword_SpinCharge(EneSword* p) {
  p->spinPhase += p->spinSpeed;
  if (p->spinPhase > 255) {
    p->spinPhase = 0;
    PlaySound_082406e0(SONG_361);
  }
  p->sprite.rotation += p->spinSpeed;
  if ((p->frameCount & 7) == 0 && ++p->spinSpeed > 7) {
    p->spinSpeed = 7;
  }
  if (++p->spinTimer > 150) {
    p->playerAngle = 0x20 - ArcTan2_8(p->sprite.pos.x - p->player->mover.pos.x, p->sprite.pos.z - p->player->mover.pos.z);
    p->moveFrom.x = p->sprite.pos.x;
    p->moveFrom.y = p->sprite.pos.y;
    p->moveFrom.z = p->sprite.pos.z;
    p->playerPos.x = p->player->mover.pos.x;
    p->playerPos.y = p->player->mover.pos.y + 350;
    p->playerPos.z = p->player->mover.pos.z;
    p->toPlayer.x = p->playerPos.x - p->sprite.pos.x;
    p->toPlayer.y = p->playerPos.y - p->sprite.pos.y;
    p->toPlayer.z = p->playerPos.z - p->sprite.pos.z;
    p->spinTimer = 0;
    p->subStateFns[1] = EneSword_DashAim;
  }
}

// 剣先をプレイヤーへ向けるまで回し, 近ければ突進の前の明滅へ, 遠ければ突進をやめる
void EneSword_DashAim(EneSword* p) {
  s32 i;
  s32 j;
  p->spinPhase += p->spinSpeed;
  if (p->spinPhase > 255) {
    p->spinPhase = 0;
    PlaySound_082406e0(SONG_361);
  }
  for (i = 0; i < p->spinSpeed; i++) {
    p->sprite.rotation++;
    if (p->sprite.rotation == p->playerAngle) {
      p->sprite.rotation = p->playerAngle;
      p->spinTimer = 0;
      p->spinSpeed = 0;
      if (p->toPlayer.x * p->toPlayer.x + p->toPlayer.z * p->toPlayer.z < 1000000) {
        p->subStateFns[1] = EneSword_DashGlow;
      } else {
        for (j = 0; j < 4; j++) {
          p->afterimageSprites[j].flags |= SPRFLAG_HIDDEN;
        }
        p->subStateFns[1] = EneSword_DashEnd;
      }
      return;
    }
  }
}

// プレイヤーへ突っ込む前に赤く2回光る
void EneSword_DashGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 1) {
    p->glowCount = 0;
    p->spinTimer = 0;
    p->subStateFns[1] = EneSword_DashMove;
    PlaySound_082406e0(SONG_399);
  }
}

// 16 フレームかけてプレイヤーのいた位置へ一直線に突っ込む
void EneSword_DashMove(EneSword* p) {
  p->sprite.pos.x = p->moveFrom.x + Div(p->toPlayer.x * p->spinTimer, 16);
  p->sprite.pos.y = p->moveFrom.y + Div(p->toPlayer.y * p->spinTimer, 16);
  p->sprite.pos.z = p->moveFrom.z + Div(p->toPlayer.z * p->spinTimer, 16);
  if (p->spinTimer++ > 16) {
    s32 i;
    p->spinTimer = 0;
    p->sprite.pos.x = p->playerPos.x;
    p->sprite.pos.y = p->playerPos.y;
    p->sprite.pos.z = p->playerPos.z;
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
    }
    p->subStateFns[1] = EneSword_DashEnd;
  }
}

// 突進の後, 剣を上向き (128) まで回し戻して state 0 (待機) に移る, 残像を隠すループは i を 0 に戻さずに続けている
void EneSword_DashEnd(EneSword* p) {
  s32 i;
  if ((p->frameCount & 7) == 0) {
    if (++p->spinSpeed > 7) {
      p->spinSpeed = 7;
    }
  }
  for (i = 0; i < p->spinSpeed; i++) {
    if (++p->sprite.rotation == 128) {
      for (; i < 4; i++) {
        p->afterimageSprites[i].rotation = 128;
        p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
      }
      p->spinSpeed = 0;
      EneSword_ResetHover(p);
      EneSwordBody_SetState(&p->body, 1, 0);
      p->stateFn = EneSword_StateIdle;
      p->subStateFns[1] = EneSword_SpinGlow;
    }
  }
}

// 残像を回し始める前に赤く2回光る
void EneSword_OrbitGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 1) {
    p->glowCount = 0;
    p->subStateFns[2] = EneSword_OrbitExpand;
  }
}

// 回る残像の半径を orbitRadiusMax まで広げる
void EneSword_OrbitExpand(EneSword* p) {
  if ((p->frameCount & 3) == 0) {
    if (p->orbitRadius >= p->orbitRadiusMax) {
      p->subStateFns[2] = EneSword_OrbitShrink;
    } else {
      p->orbitRadius += p->orbitRadiusStep;
    }
  }
}

// 回る残像の半径を 0 まで縮め, 残像を隠して state 2 (突進) に移る
void EneSword_OrbitShrink(EneSword* p) {
  if ((p->frameCount & 3) == 0) {
    if (p->orbitRadius <= 0) {
      s32 i;
      p->spinSpeed = -p->spinSpeed;
      EneSwordBody_SetState(&p->body, 1, 2);
      p->stateFn = EneSword_StateDash;
      for (i = 0; i < 4; i++) {
        p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
        p->afterimageHitboxes[i].flags |= HBF_HIDDEN;
        p->afterimageHurtboxes[i].flags |= HBF_HIDDEN;
      }
      p->subStateFns[2] = EneSword_OrbitExpand;
    } else {
      p->orbitRadius -= p->orbitRadiusStep;
      p->orbitRadius = p->orbitRadius < 0 ? 0 : p->orbitRadius;
    }
  }
}

// 赤く3回光ってから, 残像を広げながらプレイヤーへ寄る, どこからも使われていない
void EneSword_OrbitChaseGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 2) {
    p->glowCount = 0;
    p->subStateFns[2] = EneSword_OrbitChase;
  }
}

// 回る残像の半径を 80 まで広げながらプレイヤーの方へ寄る
void EneSword_OrbitChase(EneSword* p) {
  s32 cos;
  s32 sin;
  p->playerPos.x = p->player->mover.pos.x;
  p->playerPos.y = p->player->mover.pos.y;
  p->playerPos.z = p->player->mover.pos.z;
  p->toPlayer.x = p->playerPos.x - p->sprite.pos.x;
  p->toPlayer.y = p->playerPos.y - p->sprite.pos.y;
  p->toPlayer.z = p->playerPos.z - p->sprite.pos.z;
  p->playerAngle = ArcTan2_8(p->toPlayer.x, p->toPlayer.z);
  cos = COS(p->playerAngle);
  sin = SIN(p->playerAngle);
  p->body.vel.x = FixToInt(10, cos);
  p->body.vel.z = FixToInt(10, sin);
  p->sprite.pos.x += p->body.vel.x;
  p->sprite.pos.z += p->body.vel.z;
  if ((p->frameCount & 3) == 0 && ++p->orbitRadius == 80) {
    p->subStateFns[2] = EneSword_OrbitChaseShrink;
  }
}

// 回る残像の半径を 0 まで縮め, 残像を隠して state 2 (突進) に移る
void EneSword_OrbitChaseShrink(EneSword* p) {
  if ((p->frameCount & 3) == 0 && --p->orbitRadius == 0) {
    s32 i;
    p->spinSpeed = -p->spinSpeed;
    EneSwordBody_SetState(&p->body, 1, 2);
    p->stateFn = EneSword_StateDash;
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
      p->afterimageHitboxes[i].flags |= HBF_HIDDEN;
      p->afterimageHurtboxes[i].flags |= HBF_HIDDEN;
    }
    p->subStateFns[2] = EneSword_OrbitChase;
  }
}

// 消えてプレイヤーのそばへ移る前に赤く2回光る
void EneSword_WarpGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 1) {
    p->glowCount = 0;
    p->subStateFns[3] = EneSword_WarpMove;
    PlaySound_082406e0(SONG_363);
  }
}

// 残像を縮めながら左右に揺らし, 消えきったらプレイヤーの周りの乱数の位置へ移って残像の出し直しを待つ
// 残差はレジスタ割り当てだけ (ループ変数 r4/r6 と sprite.pos の番地のスタック退避, 222/222 命令)
// Tier A-C は試済 (accel を先に増やす, angle を s32 で Random() & 0xFF, 2つ目のループに j, 宣言順)
NON_MATCH void EneSword_WarpMove(EneSword* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;
  for (i = 0; i < 4; i++) {
    p->body.vel.x = -p->body.vel.x;
    p->body.vel.z = -p->body.vel.z;
    p->afterimageSprites[i].pos.x += p->body.vel.x;
    p->afterimageSprites[i].pos.z -= p->body.vel.z;
    p->afterimageSprites[i].scaleX -= 2;
    if (p->afterimageSprites[i].scaleX < 2) {
      p->afterimageSprites[i].scaleX = 1;
    }
  }
  if ((p->frameCount & 1) == 0) {
    p->body.accel.x++;
    p->body.accel.z++;
    p->body.vel.x = p->body.accel.x;
    p->body.vel.z = p->body.accel.z;
    if (p->body.accel.x > 15) {
      s32 angle;
      p->body.vel.x = p->afterimageSprites[0].pos.x - p->sprite.pos.x;
      p->body.vel.z = p->afterimageSprites[0].pos.z - p->sprite.pos.z;
      angle = Random() & 0xFF;
      p->sprite.pos.x = p->player->mover.pos.x + Div(COS(angle) * 200, 0x1000);
      p->sprite.pos.y = p->player->mover.pos.y + 350;
      p->sprite.pos.z = p->player->mover.pos.z + Div(SIN(angle) * 200, 0x1000);
      for (j = 0; j < 4; j++) {
        p->afterimageSprites[j].flags |= SPRFLAG_HIDDEN;
        p->afterimageSprites[j].pos.x = p->afterimageStarts[j].x = p->body.vel.x + p->sprite.pos.x;
        p->afterimageSprites[j].pos.z = p->afterimageStarts[j].z = p->body.vel.z + p->sprite.pos.z;
        p->playerPos.x = p->sprite.pos.x;
        p->playerPos.y = p->sprite.pos.y;
        p->playerPos.z = p->sprite.pos.z;
        p->body.vel.x = -p->body.vel.x;
        p->body.vel.z = -p->body.vel.z;
      }
      p->timer = 30;
      p->subStateFns[3] = EneSword_WarpAppear;
    }
  }
#else
  INCFUNC("asm/func/EneSword_WarpMove.inc");
#endif
}

// 消えてから timer だけ待ち, プレイヤーのそばに残像を出し直す
void EneSword_WarpAppear(EneSword* p) {
  if (--p->timer == 0) {
    s32 i;
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].pos.y = p->playerPos.y;
      p->afterimageSprites[i].flags &= ~SPRFLAG_HIDDEN;
    }
    EneSword_ResetHover(p);
    p->timer = 15;
    p->bobTimer = 20;
    p->subStateFns[3] = EneSword_WarpConverge;
    PlaySound_082406e0(SONG_364);
  }
}

// 出し直した残像をプレイヤーの位置へ寄せて重ね, 本体を現して state 5 (スレイブソードを呼ぶ) に移る
void EneSword_WarpConverge(EneSword* p) {
  s32 i;
  for (i = 0; i < 4; i++) {
    p->afterimageSprites[i].pos.x = p->playerPos.x + Div((p->playerPos.x - p->afterimageStarts[i].x) * p->timer, 15);
    p->afterimageSprites[i].pos.z = p->playerPos.z + Div((p->playerPos.z - p->afterimageStarts[i].z) * p->timer, 15);
    p->afterimageSprites[i].scaleX += 3;
    if (p->afterimageSprites[i].scaleX > 63) {
      p->afterimageSprites[i].scaleX = 64;
    }
  }
  if ((p->frameCount & 1) == 0 && --p->timer == 0) {
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].pos.x = p->playerPos.x;
      p->afterimageSprites[i].pos.z = p->playerPos.z;
      p->afterimageSprites[i].scaleX = 64;
      p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
    }
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->hitbox.flags &= ~HBF_HIDDEN;
    p->hurtbox.flags &= ~HBF_HIDDEN;
    EneSwordBody_SetState(&p->body, 1, 5);
    p->stateFn = EneSword_StateSummon;
    p->subStateFns[3] = EneSword_WarpMove;
  }
}

// スレイブソードを呼び出す前に赤く2回光る
void EneSword_SummonGlow(EneSword* p) {
  if (p->glowFn != NULL && p->glowFn(p)) {
    p->glowCount++;
  }
  if (p->glowCount > 1) {
    p->glowCount = 0;
    p->slaveTimer = p->slaveInterval;
    p->subStateFns[4] = EneSword_SummonSlaves;
  }
}

// slaveInterval フレームごとに空いているスレイブソードを1本ずつ呼び出し, 全部出したら EneSword_SummonWait へ移る
// 残差はループの誘導変数, 原典は i * 396 だけを持ち &slaves[i].body を使う所で p と足す, こちらは p + i * 396 も別に持つ (63/64 命令)
// Tier A-C は試済 (要素ポインタのローカル, body ポインタのローカル, break で分ける形, slaveTimer を u16 に)
NON_MATCH void EneSword_SummonSlaves(EneSword* p) {
#ifdef NONMATCHING_C
  if (p->slaveTimer != 0) {
    p->slaveTimer--;
  } else {
    s32 i;
    for (i = 0; i < p->slaveCount; i++) {
      if (p->slaves[i].body.mode == 0) {
        EneSwordBody_SetState(&p->slaves[i].body, 1, 0);
        p->slaves[i].stateFn = EneSword_SlaveStateAppear;
        p->slaveTimer = p->slaveInterval;
        return;
      }
    }
    p->subStateFns[4] = EneSword_SummonWait;
  }
#else
  INCFUNC("asm/func/EneSword_SummonSlaves.inc");
#endif
}

// スレイブソードが全部やられたら state 1 (追いかける) に戻る
void EneSword_SummonWait(EneSword* p) {
  s32 i;
  s32 count = 0;
  for (i = 0; i < p->slaveCount; i++) {
    if (p->slaves[i].body.mode != 0) {
      count++;
    }
  }
  if (count == 0) {
    EneSwordBody_SetState(&p->body, 1, 1);
    p->stateFn = EneSword_StateChase;
  } else if (count < p->slaveCount && ++p->unk_c98 <= 7) {
    p->subStateFns[4] = EneSword_SummonWait;
  }
}

void EneSword_UpdateFlash(EneSword* p) {
  if (--p->body.flashTimer == 0) {
    Video_SetAuxSpritePltt(p->sprite.gfx, p->plttID);
    p->sprite.gfx->pltt = p->pltt;
    p->flashFn = NULL;
  }
}

// HP ゲージを出し, 受けたダメージがあれば数字を出す
void EneSword_ShowDamage(EneSword* p, u32 hitResult, s32 kind) {
  Vec3 ofs;
  HUD_ShowEnemyGauge(p->id, p->body.hp, p->maxHP, p->unk_cce, (hitResult >> 2) & 1);
  Vec3_Clear(&ofs);
  if (p->damage != 0) {
    ofs.y = -120;
    CreateDamageNumber(&p->hurtbox, p->damage, kind, &p->sprite.pos, &ofs, 1);
    p->damage = 0;
  }
}

// 残像用の黒パレットと, 元のパレットの写しを作る
void EneSword_InitPltts(EneSword* p) {
  s32 i;
  rgb555* src = p->gfx.pltt;
  for (i = 0; i < 16; i++) {
    p->blackPltt[i] = 0;
    p->origPltt[i] = src[i];
  }
}

void EneSword_SetAfterimagePlttData(EneSword* p, rgb555* pltt) {
  s32 i;
  for (i = 0; i < 4; i++) {
    p->afterimageGfx[i].pltt = pltt;
  }
}

void EneSword_SetAfterimagePltt(EneSword* p, rgb555* pltt, u32 plttID) {
  s32 i;
  for (i = 0; i < 4; i++) {
    p->afterimageGfx[i].plttID = plttID;
    p->afterimageGfx[i].pltt = pltt;
  }
}

// '.M' からスレイブソードの間隔と回る残像の設定を読む
void EneSword_ReadArgM(EneSword* p) {
  if (VM_SeekToNamedArg('M')) {
    p->slaveInterval = VM_GetPC() != NULL ? VM_GetValue() : 60;
    p->orbitCount = VM_GetPC() != NULL ? VM_GetValue() : 2;
    p->orbitRadiusMax = VM_GetPC() != NULL ? VM_GetValue() : 80;
    p->orbitRadiusStep = VM_GetPC() != NULL ? VM_GetValue() : 1;
  }
}

// 150 フレーム浮いて待ってから state 4 (消えてプレイヤーのそばへ移る) に移る
void EneSword_StateIdle(EneSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->timer = 150;
    p->glowFn = EneSword_GlowNone;
  }
  EneSword_UpdateHover(p);
  if (--p->timer == 0) {
    EneSwordBody_SetState(&p->body, 1, 4);
    p->stateFn = EneSword_StateWarp;
    p->subStateFns[1] = EneSword_SpinGlow;
  }
}

void EneSword_StateChase(EneSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->timer = 100;
    p->subStateFns[0] = EneSword_ChaseWait;
    p->glowFn = EneSword_GlowNone;
  }
  EneSword_UpdateHover(p);
  if (p->subStateFns[0] != NULL) {
    p->subStateFns[0](p);
  }
}

// 出現してから 30 フレーム待って state 2 の処理に移る
void EneSword_StateSpawnWait(EneSword* p) {
  if (p->frameCount > 30) {
    p->stateFn = EneSword_StateDash;
    SET_FLAGS(p->body.flags, SWORDFLAG_ENTERED);
  }
}

// state 2, 回転を上げてプレイヤーへ突っ込む, 2 フレームごとに残像を後ろへ送る
void EneSword_StateDash(EneSword* p) {
  s32 i;
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].pos.x = p->sprite.pos.x;
      p->afterimageSprites[i].pos.y = p->sprite.pos.y;
      p->afterimageSprites[i].pos.z = p->sprite.pos.z;
      p->afterimageSprites[i].rotation = p->sprite.rotation;
    }
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].flags &= ~SPRFLAG_HIDDEN;
    }
    p->subStateFns[1] = EneSword_SpinGlow;
    p->spinTimer = 0;
    p->spinSpeed = 0;
    p->spinPhase = 0;
    p->glowFn = EneSword_GlowBegin;
    p->glowCount = 0;
    PlaySound_082406e0(SONG_367);
  }
  if (p->subStateFns[1] != NULL) {
    p->subStateFns[1](p);
  }
  if (p->frameCount & 1) {
    for (i = 3; i > 0; i--) {
      p->afterimageSprites[i].pos.x = p->afterimageSprites[i - 1].pos.x;
      p->afterimageSprites[i].pos.y = p->afterimageSprites[i - 1].pos.y;
      p->afterimageSprites[i].pos.z = p->afterimageSprites[i - 1].pos.z;
      p->afterimageSprites[i].rotation = p->afterimageSprites[i - 1].rotation;
    }
    p->afterimageSprites[0].pos.x = p->sprite.pos.x;
    p->afterimageSprites[0].pos.y = p->sprite.pos.y;
    p->afterimageSprites[0].pos.z = p->sprite.pos.z;
    p->afterimageSprites[0].rotation = p->sprite.rotation;
  }
}

// state 3, orbitCount 本の残像を本体の周りに回し, 半径を広げてから縮める
void EneSword_StateOrbit(EneSword* p) {
  s32 i;
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    for (i = 0; i < p->orbitCount; i++) {
      p->afterimageSprites[i].pos.x = p->sprite.pos.x;
      p->afterimageSprites[i].pos.y = p->sprite.pos.y;
      p->afterimageSprites[i].pos.z = p->sprite.pos.z;
      p->afterimageSprites[i].rotation = p->sprite.rotation;
      p->afterimageSprites[i].flags &= ~SPRFLAG_HIDDEN;
      p->afterimageAngles[i] = i * Div(256, p->orbitCount);
    }
    p->orbitRadius = 0;
    p->playerAngle = 0;
    p->spinSpeed = 5;
    p->orbitFrames = 0;
    for (i = 0; i < p->orbitCount; i++) {
      p->afterimageHitboxes[i].flags &= ~HBF_HIDDEN;
      p->afterimageHurtboxes[i].flags &= ~HBF_HIDDEN;
    }
    p->subStateFns[2] = EneSword_OrbitGlow;
    p->glowFn = EneSword_GlowBegin;
    p->glowCount = 0;
    PlaySound_082406e0(SONG_367);
  }
  EneSword_UpdateHover(p);
  for (i = 0; i < p->orbitCount; i++) {
    p->afterimageSprites[i].pos.x = p->sprite.pos.x + FixToInt(10, p->orbitRadius * COS(p->afterimageAngles[i]));
    p->afterimageSprites[i].pos.y = p->sprite.pos.y;
    p->afterimageSprites[i].pos.z = p->sprite.pos.z + FixToInt(10, p->orbitRadius * SIN(p->afterimageAngles[i]));
    p->afterimageAngles[i] += p->spinSpeed;
    if (p->afterimageAngles[i] > 255) {
      if (p->orbitFrames > 70) {
        PlaySound_082406e0(SONG_361);
      }
      p->afterimageAngles[i] -= 255;
    }
  }
  if (p->subStateFns[2] != NULL) {
    p->subStateFns[2](p);
  }
  p->orbitFrames++;
}

void EneSword_StateWarp(EneSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    s32 i;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->hitbox.flags |= HBF_HIDDEN;
    p->hurtbox.flags |= HBF_HIDDEN;
    for (i = 0; i < 4; i++) {
      p->afterimageSprites[i].pos.x = p->sprite.pos.x;
      p->afterimageSprites[i].pos.y = p->sprite.pos.y;
      p->afterimageSprites[i].pos.z = p->sprite.pos.z;
      p->afterimageSprites[i].rotation = p->sprite.rotation;
      p->afterimageSprites[i].flags &= ~SPRFLAG_HIDDEN;
      p->afterimageHitboxes[i].flags |= HBF_HIDDEN;
      p->afterimageHurtboxes[i].flags |= HBF_HIDDEN;
      p->floorY = Map_GetTileHeightAt(&p->sprite.pos);
    }
    p->body.vel.x = 0;
    p->body.vel.z = 0;
    p->body.accel.x = -7;
    p->body.accel.z = -7;
    p->subStateFns[3] = EneSword_WarpGlow;
    p->glowFn = EneSword_GlowBegin;
    p->glowCount = 0;
    PlaySound_082406e0(SONG_367);
  }
  if (p->subStateFns[3] != NULL) {
    p->subStateFns[3](p);
  }
}

// state 5, スレイブソードを呼び出す, 出す攻撃は plttVariant で決め, ソード+ は 1024 フレームごとに突きと回転を入れ替える
// 残差は slaveAngle の Random の表の番地のレジスタ (r1 と r2) と, 2つ目の switch の case 0 が case 2 の else の末尾へ跳ぶ形 (150/150 命令)
// Tier A-C は試済 (case 2 の if/else と三項演算子, Random の直書き, RandomNext)
NON_MATCH void EneSword_StateSummon(EneSword* p) {
#ifdef NONMATCHING_C
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->unk_c98 = 0;
    p->slaveAngle = Random();
    p->subStateFns[4] = EneSword_SummonGlow;
    p->unk_c9a = 0;
    switch (p->plttVariant) {
      case 0: {
        p->slaveNextStateFn = EneSword_SlaveStateBoomerang;
        break;
      }
      case 1: {
        p->slaveNextStateFn = EneSword_SlaveStateThrust;
        break;
      }
      case 2: {
        p->slaveNextStateFn = EneSword_SlaveStateSpin;
        break;
      }
    }
    PlaySound_082406e0(SONG_367);
  }
  EneSword_UpdateHover(p);
  if (p->subStateFns[4] != NULL) {
    p->subStateFns[4](p);
  }
  if ((++p->unk_c9a & 0x3FF) == 0) {
    p->unk_c9a = 0;
    switch (p->plttVariant) {
      case 0: {
        p->slaveNextStateFn = EneSword_SlaveStateBoomerang;
        break;
      }
      case 1: {
        if (p->slaveNextStateFn == EneSword_SlaveStateSpin) {
          p->slaveNextStateFn = EneSword_SlaveStateThrust;
        } else if (p->slaveNextStateFn == EneSword_SlaveStateThrust) {
          p->slaveNextStateFn = EneSword_SlaveStateSpin;
        }
        break;
      }
      case 2: {
        p->slaveNextStateFn = (Random() & 1) ? EneSword_SlaveStateSpin : EneSword_SlaveStateBoomerang;
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/EneSword_StateSummon.inc");
#endif
}

// state 6, スレイブソードも倒して経験値を入れ, 点滅しながら煙を出して消える, 消えきったら撃破時のスクリプトを実行する
// 残差はスレイブソードを倒すループの誘導変数だけ (464/464 命令), 原典は stateFn を &slaves[i].body からの +0x74 で書く, EneSword_SummonSlaves と同じ壁
// Tier A-C は試済 (要素ポインタのローカル, body ポインタのローカル, dyingFrames と weaponExp の型, 点滅の if の向き)
NON_MATCH void EneSword_StateDying(EneSword* p) {
#ifdef NONMATCHING_C
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    s32 i;
    for (i = 0; i < 4; i++) {
      if (p->slaves[i].body.mode != 0) {
        EneSwordBody_SetState(&p->slaves[i].body, 1, 5);
        p->slaves[i].stateFn = EneSword_SlaveStateDying;
      }
    }
    for (i = 0; i < 4; i++) {
      if (!(p->afterimageSprites[i].flags & SPRFLAG_HIDDEN)) {
        p->afterimageSprites[i].flags |= SPRFLAG_HIDDEN;
        p->afterimageHitboxes[i].flags |= HBF_HIDDEN;
        p->afterimageHurtboxes[i].flags |= HBF_HIDDEN;
      }
    }
    p->hitbox.flags |= HBF_HIDDEN;
    p->hurtbox.flags |= HBF_HIDDEN;
    p->dyingFrames = 0;
    p->smokeStep = 0;
    p->body.vanishTimer = 0;
    p->body.smokeCount = 30;
    AddPlayerExp(p->body.exp);
    Player_AddWeaponExp(p->hurtTypeMask, p->body.weaponExp);
    p->glowHold = 1;
  }
  if (p->glowFn != NULL) {
    p->glowFn(p);
  }
  if (Mod(p->dyingFrames, 2) == 0) {
    Vec3 size;
    Vec3 ofs;
    WorldPos pos;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->body.vanishTimer = 0;
    p->body.smokeCount--;
    size.x = 60, size.y = 60, size.z = 40;
    pos = p->sprite.pos;
    Vec3_Clear(&ofs);
    switch (p->smokeStep) {
      case 0: {
        ofs.x = -120;
        ofs.z = -120;
        p->smokeStep++;
        PlaySound_082406e0(SONG_366);
        break;
      }
      case 1: {
        ofs.x = -75;
        ofs.z = -75;
        p->smokeStep++;
        break;
      }
      case 2: {
        ofs.x = -30;
        ofs.z = -30;
        p->smokeStep++;
        break;
      }
      case 3: {
        ofs.x = 15;
        ofs.z = 15;
        p->smokeStep++;
        break;
      }
      case 4: {
        ofs.x = 60;
        ofs.z = 60;
        p->smokeStep = 0;
        break;
      }
    }
    pos.x += FixToInt(12, ofs.x * COS(p->sprite.rotation)) + FixToInt(12, ofs.z * SIN(p->sprite.rotation));
    pos.z += FixToInt(12, -(ofs.x * SIN(p->sprite.rotation))) + FixToInt(12, ofs.z * COS(p->sprite.rotation));
    EmitSmoke(&pos, 2, &size, 0, 0, 22, 2, 1);
    if (p->body.smokeCount == 0) {
      AuxShadow_Hide(&p->shadow);
      EneSwordBody_SetState(&p->body, 0, 0);
      if (p->player->mode != PMODE_DEAD && p->defeatScriptID != 0) {
        ScriptArgs sa;
        s32 idx;
        sa.argc = 2;
        sa.argv = p->defeatScriptArgs;
        VM_ExecByID(p->defeatScriptID, &sa);
        idx = EnemyDex_GetEntryIdx(ENEK_SWORD, p->plttVariant);
        if (idx < 32) {
          gStat->enemyDexSeen[0] |= 1 << idx;
        } else {
          gStat->enemyDexSeen[1] |= 1 << (idx - 32);
        }
      }
    }
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->body.vanishTimer++;
  }
  p->dyingFrames++;
#else
  INCFUNC("asm/func/EneSword_StateDying.inc");
#endif
}

void EneSword_UpdateIdle(EneSword* p) {}

// 被弾の点滅, 無敵時間, 状態を進める
void EneSword_UpdateActive(EneSword* p) {
  if (p->flashFn != NULL) {
    p->flashFn(p);
  }
  if (p->hurtbox.iframes != 0) {
    p->hurtbox.iframes--;
  }
  if (p->stateFn != NULL) {
    p->stateFn(p);
    if (p->postStateFn != NULL) {
      p->postStateFn(p);
    }
    EneSword_UpdateFloorY(p);
  }
}

void (*const gEneSwordModeFuncs[2])(EneSword*) = {
    EneSword_UpdateIdle,
    EneSword_UpdateActive,
};  // 0x085ADDA8

void EneSword_UpdateMainSword(EneSword* p) {
  if (!TEST_FLAGS(p->body.flags, SWORDFLAG_UNK_4)) {
    gEneSwordModeFuncs[p->body.mode](p);
  }
}

void EneSword_OnSlaveSwordHit(Hitbox* a, Hitbox* b, SlaveSword* p) {}

// 被弾したスレイブソードの HP を減らし, 攻撃中なら当たった向きへ弾き飛ばす
// 残差は弾き返しの枝で timer の値 0x80 から subStateFns の番地を足し算で作る形と, 角度の格納先の番地を枝ごとに作るかどうか (289/295 命令)
// Tier A-C は試済 (Hitbox_HasSource, s32 の bonus ローカルで ldrsh, state のポインタローカル)
NON_MATCH void EneSword_OnSlaveSwordHurt(Hitbox* a, Hitbox* b, SlaveSword* p) {
#ifdef NONMATCHING_C
  EneSword* owner = p->owner;
  if (p->body.hp <= 0) {
    return;
  }
  if (Hitbox_HasSource(a, HBSRC_10)) {
    return;
  }
  if (p->hurtbox.iframes != 0) {
    return;
  }
  Hitbox_ApplyDamage(a, b);
  b->iframes = a->iframes;
  if (p->flashFn == NULL && b->damage != 0) {
    p->body.flashTimer = 8;
    p->flashFn = EneSword_UpdateSlaveFlash;
    Video_SetAuxSpritePltt(p->sprite.gfx, owner->flashPlttID);
    p->body.hp -= b->damage;
    {
      s32 bonus = owner->unk_c8a;
      a->damage += bonus;
    }
    if (p->body.hp <= 0) {
      EneSwordBody_SetState(&p->body, 1, 5);
      p->stateFn = EneSword_SlaveStateDying;
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
      return;
    }
  }
  if ((p->body.state == 2 && p->subStateFns[2] != EneSword_SlaveSpinBounced) || (p->body.state == 3 && (p->subStateFns[3] == EneSword_SlaveThrustWait || p->subStateFns[3] == EneSword_SlaveThrustMove)) ||
      (p->body.state == 4 && (p->subStateFns[4] == EneSword_SlaveBoomerangSpinUp || p->subStateFns[4] == EneSword_SlaveBoomerangOut || p->subStateFns[4] == EneSword_SlaveBoomerangReturn))) {
    EneSword_SlaveSetMoveToHere(p);
    if (p->body.state == 2) {
      p->timer = 128;
      p->subStateFns[2] = EneSword_SlaveSpinBounced;
    } else if (p->body.state == 3) {
      p->timer = 20;
      p->subStateFns[3] = EneSword_SlaveThrustBounced;
    } else if (p->body.state == 4) {
      p->timer = 100;
      p->subStateFns[4] = EneSword_SlaveBoomerangBounced;
    }
    if (a->flags & HBF_ANGLE) {
      p->body.angle = a->angle;
    } else {
      Vec3 d;
      Vec3_Diff(&d, &a->pos, &b->pos);
      if (d.x == 0 && d.z == 0) {
        p->body.angle = Random();
      } else {
        p->body.angle = ArcTan2_8(d.x, d.z);
      }
    }
    p->hurtbox.ignoreMask = 1;
    p->hitbox.ignoreMask = 1;
    p->hitbox.halfSize.val = a->halfSize.val;
    p->body.knockback.x = COS(p->body.angle) >> 7;
    p->body.knockback.z = SIN(p->body.angle) >> 7;
    PlaySound_082406e0(SONG_368);
    return;
  }
  if (b->damage != 0) {
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
  } else {
    PlaySound_082406e0(SONG_400);
  }
#else
  INCFUNC("asm/func/EneSword_OnSlaveSwordHurt.inc");
#endif
}

void EneSword_UpdateSlaveHover(SlaveSword* p) {
  if ((p->bobTimer & 3) == 0) {
    p->body.vel.y += p->body.accel.y;
  }
  if (--p->bobTimer == 0) {
    p->body.accel.y = -p->body.accel.y;
    p->bobTimer = 40;
  }
  p->sprite.pos.y += p->body.vel.y;
}

// 横に潰れた形から縦に伸びて現れる演出を始める
void EneSword_SlaveAppearBegin(SlaveSword* p) {
  p->sprite.rotation = 128;
  p->sprite.scaleX = 127;
  p->sprite.scaleY = 1;
  p->scaleXSpeed = -8;
  p->scaleYSpeed = 16;
  p->subStateFns[0] = EneSword_SlaveAppearStretch;
  PlaySound_082406e0(SONG_365);
}

// 横幅を 64 まで縮めながら縦を 127 まで伸ばす
void EneSword_SlaveAppearStretch(SlaveSword* p) {
  s32 scaleX = p->sprite.scaleX;
  s32 scaleY = p->sprite.scaleY;
  if (scaleX > 64) {
    scaleX += p->scaleXSpeed;
    if (scaleX < 64) {
      scaleX = 64;
    }
  }
  if (scaleY < 127) {
    scaleY += p->scaleYSpeed;
    if (scaleY > 127) {
      scaleY = 127;
    }
  }
  p->sprite.scaleX = scaleX;
  p->sprite.scaleY = scaleY;
  if (scaleY == 127) {
    p->sprite.scaleX = 64;
    p->scaleYSpeed = -16;
    p->subStateFns[0] = EneSword_SlaveAppearSettle;
  }
}

// 縦を 64 まで縮めて出現を終え, 本体の周りを回る state 1 に移る
void EneSword_SlaveAppearSettle(SlaveSword* p) {
  s32 scaleY = p->sprite.scaleY;
  if (scaleY > 64) {
    scaleY += p->scaleYSpeed;
    if (scaleY < 64) {
      scaleY = 64;
    }
  }
  p->sprite.scaleY = scaleY;
  if (scaleY == 64) {
    p->subStateFns[0] = EneSword_SlaveAppearBegin;
    p->orbitDir = (Random() & 1) ? 1 : -1;
    EneSwordBody_SetState(&p->body, 1, 1);
    p->stateFn = EneSword_SlaveStateOrbit;
  }
}

// 本体の周りを回る時間を乱数で決める
void EneSword_SlaveOrbitBegin(SlaveSword* p) {
  p->timer = (Random() & 0x40) + 30;
  p->subStateFns[1] = EneSword_SlaveOrbitMove;
}

// 本体の周りを半径 200 で回り, timer が尽きたら本体が決めた攻撃 (slaveNextStateFn) に移る
void EneSword_SlaveOrbitMove(SlaveSword* p) {
  EneSword* owner = p->owner;
  p->orbitAngle += p->orbitDir;
  p->sprite.pos.x = owner->sprite.pos.x + Div(COS(p->orbitAngle) * 200, 0x1000);
  p->sprite.pos.z = owner->sprite.pos.z + Div(SIN(p->orbitAngle) * 200, 0x1000);
  if (--p->timer == 0) {
    void (*next)(SlaveSword*) = owner->slaveNextStateFn;
    if (next == EneSword_SlaveStateSpin) {
      EneSwordBody_SetState(&p->body, 1, 2);
    } else if (next == EneSword_SlaveStateThrust) {
      EneSwordBody_SetState(&p->body, 1, 3);
    } else if (next == EneSword_SlaveStateBoomerang) {
      EneSwordBody_SetState(&p->body, 1, 4);
    } else {
      return;
    }
    p->stateFn = next;
  }
}

// 回転しながら飛んでくる攻撃を始める, 回転を止めて今の位置を控える
void EneSword_SlaveSpinBegin(SlaveSword* p) {
  p->rotSpeed = 0;
  p->subStateFns[2] = EneSword_SlaveSpinUp;
  p->moveFrom.x = p->sprite.pos.x;
  p->moveFrom.y = p->sprite.pos.y;
  p->moveFrom.z = p->sprite.pos.z;
}

// 回転を 9 を超えるまで上げてから, プレイヤーの位置へ揺れながら飛ぶ向き (x か z) を決める
// 残差は Random の表の番地と -1 の一時レジスタだけ (r1/r2 と r2/r4 の入れ替わり, 140/140 命令)
// Tier A-C は試済 (RandomNext, if/else と dir ローカル, == 0 の三項演算子, timer = 0 の位置)
NON_MATCH void EneSword_SlaveSpinUp(SlaveSword* p) {
#ifdef NONMATCHING_C
  EneSword* owner = p->owner;
  if ((owner->frameCount & 3) == 0) {
    p->rotSpeed--;
  }
  p->sprite.rotation += p->rotSpeed;
  if (abs(p->rotSpeed) > 9) {
    p->moveFrom.x = p->sprite.pos.x;
    p->moveFrom.y = p->sprite.pos.y;
    p->moveFrom.z = p->sprite.pos.z;
    p->moveTo.x = owner->player->mover.pos.x;
    p->moveTo.y = owner->player->mover.pos.y + 220;
    p->moveTo.z = owner->player->mover.pos.z;
    p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
    p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
    p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
    p->timer = 0;
    p->orbitDir = (Random() & 1) ? -1 : 1;
    if (abs(p->moveDelta.x) < abs(p->moveDelta.z)) {
      p->subStateFns[2] = EneSword_SlaveSpinFlyX;
    } else {
      p->subStateFns[2] = EneSword_SlaveSpinFlyZ;
    }
  }
#else
  INCFUNC("asm/func/EneSword_SlaveSpinUp.inc");
#endif
}

// 回りながら 128 フレームかけてプレイヤーの位置へ飛ぶ, x 方向に sin で揺れる
void EneSword_SlaveSpinFlyX(SlaveSword* p) {
  s32 sway;
  p->sprite.rotation += p->rotSpeed;
  sway = (gSineTable[p->timer & 0xFF] >> 3) * p->orbitDir;
  p->sprite.pos.x = p->moveFrom.x + Div(p->timer * p->moveDelta.x, 128) + sway;
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 128);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 128);
  if (++p->timer > 128) {
    p->subStateFns[2] = EneSword_SlaveSpinReturnX;
  }
}

// 回りながら 128 フレームかけてプレイヤーの位置へ飛ぶ, z 方向に sin で揺れる
void EneSword_SlaveSpinFlyZ(SlaveSword* p) {
  s32 sway;
  p->sprite.rotation += p->rotSpeed;
  sway = (gSineTable[p->timer & 0xFF] >> 3) * p->orbitDir;
  p->sprite.pos.x = p->moveFrom.x + Div(p->timer * p->moveDelta.x, 128);
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 128);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 128) + sway;
  if (++p->timer > 128) {
    p->subStateFns[2] = EneSword_SlaveSpinReturnZ;
  }
}

// 回りながら x 方向に揺れて moveFrom へ戻り, 本体の周りを回る state 1 に戻る
void EneSword_SlaveSpinReturnX(SlaveSword* p) {
  s32 sway;
  p->sprite.rotation += p->rotSpeed;
  sway = (gSineTable[(256 - p->timer) & 0xFF] >> 3) * p->orbitDir;
  p->sprite.pos.x = p->moveFrom.x + Div(p->timer * p->moveDelta.x, 128) + sway;
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 128);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 128);
  if (--p->timer == 0) {
    p->sprite.rotation = 128;
    EneSwordBody_SetState(&p->body, 1, 1);
    p->stateFn = EneSword_SlaveStateOrbit;
  }
}

// 回りながら z 方向に揺れて moveFrom へ戻り, 本体の周りを回る state 1 に戻る
void EneSword_SlaveSpinReturnZ(SlaveSword* p) {
  s32 sway;
  p->sprite.rotation += p->rotSpeed;
  sway = (gSineTable[(256 - p->timer) & 0xFF] >> 3) * p->orbitDir;
  p->sprite.pos.x = p->moveFrom.x + Div(p->timer * p->moveDelta.x, 128);
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 128);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 128) + sway;
  if (--p->timer == 0) {
    p->sprite.rotation = 128;
    EneSwordBody_SetState(&p->body, 1, 1);
    p->stateFn = EneSword_SlaveStateOrbit;
  }
}

// 回転して飛ぶ途中で弾かれて飛ばされ, 止まったらその位置から揺れながら moveFrom へ戻る
void EneSword_SlaveSpinBounced(SlaveSword* p) {
  EneSword* owner = p->owner;
  p->sprite.rotation += 20;
  p->sprite.pos.x += p->body.knockback.x;
  p->sprite.pos.z += p->body.knockback.z;
  if ((owner->frameCount & 7) == 0) {
    if (p->body.knockback.x == 0 && p->body.knockback.z == 0) {
      p->hurtbox.ignoreMask = 0x10;
      p->hitbox.ignoreMask = 0x10;
      p->moveTo.x = p->sprite.pos.x;
      p->moveTo.y = p->sprite.pos.y;
      p->moveTo.z = p->sprite.pos.z;
      p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
      p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
      p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
      p->orbitDir = -p->orbitDir;
      p->rotSpeed = -10;
      if (abs(p->moveDelta.x) < abs(p->moveDelta.z)) {
        p->subStateFns[2] = EneSword_SlaveSpinReturnX;
      } else {
        p->subStateFns[2] = EneSword_SlaveSpinReturnZ;
      }
    }
    p->body.knockback.x = FixToInt(1, p->body.knockback.x);
    p->body.knockback.z = FixToInt(1, p->body.knockback.z);
  }
}

// プレイヤーの方を向き, 剣を回す向きと 800 先の突きの行き先を決める
// 残差は Random の表の番地を入れるレジスタだけ (r1 と r3, 166/166 命令), EneSword_SlaveSpinUp と同じ形
// Tier A-C は試済 (if/else, angle のポインタローカル, 条件を反転した三項演算子)
NON_MATCH void EneSword_SlaveThrustBegin(SlaveSword* p) {
#ifdef NONMATCHING_C
  EneSword* owner = p->owner;
  p->body.angle = ArcTan2_8(owner->player->mover.pos.x - p->sprite.pos.x, owner->player->mover.pos.z - p->sprite.pos.z);
  p->targetRotation = 160 - p->body.angle;
  p->orbitDir = (Random() & 1) ? 1 : -1;
  p->spinSpeed = 1;
  p->moveFrom.x = p->sprite.pos.x;
  p->moveFrom.y = p->sprite.pos.y;
  p->moveFrom.z = p->sprite.pos.z;
  p->moveTo.x = p->sprite.pos.x + Div(COS(p->body.angle) * 800, 0x1000);
  p->moveTo.y = owner->player->mover.pos.y + 220;
  p->moveTo.z = p->sprite.pos.z + Div(SIN(p->body.angle) * 800, 0x1000);
  p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
  p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
  p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
  p->subStateFns[3] = EneSword_SlaveThrustAim;
#else
  INCFUNC("asm/func/EneSword_SlaveThrustBegin.inc");
#endif
}

// targetRotation まで剣を回して突きの向きを合わせる, 回す速さは 8 フレームごとに上がる
void EneSword_SlaveThrustAim(SlaveSword* p) {
  EneSword* owner = p->owner;
  s32 i;
  for (i = 0; i < p->spinSpeed; i++) {
    p->sprite.rotation += p->orbitDir;
    if (p->sprite.rotation == p->targetRotation) {
      p->timer = 30;
      p->subStateFns[3] = EneSword_SlaveThrustWait;
      return;
    }
  }
  if ((owner->frameCount & 7) == 0) {
    if (++p->spinSpeed > 6) {
      p->spinSpeed = 7;
    }
  }
}

// 突きの向きに回し終えてから timer だけ待ち, 音を鳴らして突き出す
void EneSword_SlaveThrustWait(SlaveSword* p) {
  if (--p->timer == 0) {
    p->subStateFns[3] = EneSword_SlaveThrustMove;
    PlaySound_082406e0(SONG_362);
  }
}

// 20 フレームかけて moveFrom から moveTo へ一直線に突き出す
void EneSword_SlaveThrustMove(SlaveSword* p) {
  p->sprite.pos.x = p->moveFrom.x + Div(p->moveDelta.x * p->timer, 20);
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 20);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 20);
  if (++p->timer > 20) {
    p->subStateFns[3] = EneSword_SlaveThrustReturn;
  }
}

// 突き出した剣を moveFrom まで引き戻す
void EneSword_SlaveThrustReturn(SlaveSword* p) {
  p->sprite.pos.x = p->moveFrom.x + Div(p->moveDelta.x * p->timer, 20);
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 20);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 20);
  if (--p->timer == 0) {
    p->spinSpeed = 1;
    p->subStateFns[3] = EneSword_SlaveThrustEnd;
  }
}

// 剣を上向き (128) まで回し戻してから本体の周りを回る state 1 に戻る
void EneSword_SlaveThrustEnd(SlaveSword* p) {
  EneSword* owner = p->owner;
  s32 i;
  for (i = 0; i < p->spinSpeed; i++) {
    p->sprite.rotation += p->orbitDir;
    if (p->sprite.rotation == 128) {
      EneSwordBody_SetState(&p->body, 1, 1);
      p->stateFn = EneSword_SlaveStateOrbit;
      return;
    }
  }
  if ((owner->frameCount & 7) == 0) {
    if (++p->spinSpeed > 6) {
      p->spinSpeed = 7;
    }
  }
}

// 突きの途中で弾かれて回りながら飛ばされ, 止まったらその位置から moveFrom へ引き戻す
void EneSword_SlaveThrustBounced(SlaveSword* p) {
  EneSword* owner = p->owner;
  p->sprite.rotation += 20;
  p->sprite.pos.x += p->body.knockback.x;
  p->sprite.pos.z += p->body.knockback.z;
  if ((owner->frameCount & 7) == 0) {
    if (p->body.knockback.x == 0 && p->body.knockback.z == 0) {
      p->hurtbox.ignoreMask = 0x10;
      p->hitbox.ignoreMask = 0x10;
      p->moveTo.x = p->sprite.pos.x;
      p->moveTo.y = p->sprite.pos.y;
      p->moveTo.z = p->sprite.pos.z;
      p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
      p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
      p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
      p->subStateFns[3] = EneSword_SlaveThrustReturn;
    }
    p->body.knockback.x = FixToInt(1, p->body.knockback.x);
    p->body.knockback.z = FixToInt(1, p->body.knockback.z);
  }
}

// プレイヤーの方へ 800 先までブーメランのように飛ぶ準備をする, 本体からのずれを控える
void EneSword_SlaveBoomerangBegin(SlaveSword* p) {
  EneSword* owner = p->owner;
  p->body.angle = ArcTan2_8(owner->player->mover.pos.x - p->sprite.pos.x, owner->player->mover.pos.z - p->sprite.pos.z);
  p->rotSpeed = 0;
  p->subStateFns[4] = EneSword_SlaveBoomerangSpinUp;
  p->returnCenter.x = 0;
  p->returnCenter.y = 0;
  p->returnCenter.z = 0;
  p->homeOffset.x = p->orbitCenter->x - p->sprite.pos.x;
  p->homeOffset.y = p->orbitCenter->y - p->sprite.pos.y;
  p->homeOffset.z = p->orbitCenter->z - p->sprite.pos.z;
  p->moveFrom.x = p->sprite.pos.x;
  p->moveFrom.y = p->sprite.pos.y;
  p->moveFrom.z = p->sprite.pos.z;
  p->moveTo.x = p->sprite.pos.x + Div(COS(p->body.angle) * 800, 0x1000);
  p->moveTo.y = owner->player->mover.pos.y + 220;
  p->moveTo.z = p->sprite.pos.z + Div(SIN(p->body.angle) * 800, 0x1000);
  p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
  p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
  p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
  p->timer = 0;
}

// 飛び出す前に回転を最大の 15 まで上げる
void EneSword_SlaveBoomerangSpinUp(SlaveSword* p) {
  if ((p->owner->frameCount & 3) == 0) {
    p->rotSpeed--;
    if (abs(p->rotSpeed) > 15) {
      p->rotSpeed = -15;
    }
  }
  p->sprite.rotation += p->rotSpeed;
  if (--p->timer < 0) {
    p->timer = 0;
    if (abs(p->rotSpeed) == 15) {
      p->subStateFns[4] = EneSword_SlaveBoomerangOut;
    }
  }
}

// 回りながら 100 フレームかけて moveTo まで飛び出し, 戻りの行き先を決める
void EneSword_SlaveBoomerangOut(SlaveSword* p) {
  p->sprite.rotation += p->rotSpeed;
  p->sprite.pos.x = p->moveFrom.x + Div(p->moveDelta.x * p->timer, 100);
  p->sprite.pos.y = p->moveFrom.y + Div(p->moveDelta.y * p->timer, 100);
  p->sprite.pos.z = p->moveFrom.z + Div(p->moveDelta.z * p->timer, 100);
  if (++p->timer > 100) {
    p->subStateFns[4] = EneSword_SlaveBoomerangReturn;
    p->timer = 0;
    p->returnCenter.x = p->orbitCenter->x - p->homeOffset.x - p->moveFrom.x;
    p->returnCenter.y = p->orbitCenter->y - p->homeOffset.y - p->moveFrom.y;
    p->returnCenter.z = p->orbitCenter->z - p->homeOffset.z - p->moveFrom.z;
    p->moveTo.x = p->moveFrom.x + p->returnCenter.x;
    p->moveTo.y = p->moveFrom.y + p->returnCenter.y;
    p->moveTo.z = p->moveFrom.z + p->returnCenter.z;
    p->moveFrom.x = p->sprite.pos.x;
    p->moveFrom.y = p->sprite.pos.y;
    p->moveFrom.z = p->sprite.pos.z;
    p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
    p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
    p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
    p->returnCenter.x = p->orbitCenter->x;
    p->returnCenter.y = p->orbitCenter->y;
    p->returnCenter.z = p->orbitCenter->z;
  }
}

// 本体が動いた分だけ行き先をずらしながら 100 フレームかけて元の位置へ戻り, state 1 に戻る
void EneSword_SlaveBoomerangReturn(SlaveSword* p) {
  Vec3 shift;
  shift.x = p->orbitCenter->x - p->returnCenter.x;
  shift.y = p->orbitCenter->y - p->returnCenter.y;
  shift.z = p->orbitCenter->z - p->returnCenter.z;
  p->sprite.rotation += p->rotSpeed;
  p->sprite.pos.x = shift.x + p->moveFrom.x + Div(p->moveDelta.x * p->timer, 100);
  p->sprite.pos.y = shift.y + p->moveFrom.y + Div(p->moveDelta.y * p->timer, 100);
  p->sprite.pos.z = shift.z + p->moveFrom.z + Div(p->moveDelta.z * p->timer, 100);
  if (++p->timer > 100) {
    p->spinSpeed = 1;
    p->sprite.rotation = 128;
    EneSwordBody_SetState(&p->body, 1, 1);
    p->stateFn = EneSword_SlaveStateOrbit;
  }
}

// ブーメランの途中で弾かれて飛ばされ, 止まったら本体のそばの元の位置へ戻る
void EneSword_SlaveBoomerangBounced(SlaveSword* p) {
  p->sprite.rotation += 20;
  p->sprite.pos.x += p->body.knockback.x;
  p->sprite.pos.z += p->body.knockback.z;
  if (Mod(++p->body.unk_36, 5) == 0) {
    if (p->body.knockback.x == 0 && p->body.knockback.z == 0) {
      p->hurtbox.ignoreMask = 0x10;
      p->hitbox.ignoreMask = 0x10;
      p->timer = 0;
      p->returnCenter.x = p->orbitCenter->x - p->homeOffset.x - p->moveFrom.x;
      p->returnCenter.y = p->orbitCenter->y - p->homeOffset.y - p->moveFrom.y;
      p->returnCenter.z = p->orbitCenter->z - p->homeOffset.z - p->moveFrom.z;
      p->moveTo.x = p->moveFrom.x + p->returnCenter.x;
      p->moveTo.y = p->moveFrom.y + p->returnCenter.y;
      p->moveTo.z = p->moveFrom.z + p->returnCenter.z;
      p->moveFrom.x = p->sprite.pos.x;
      p->moveFrom.y = p->sprite.pos.y;
      p->moveFrom.z = p->sprite.pos.z;
      p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
      p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
      p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
      p->returnCenter.x = p->orbitCenter->x;
      p->returnCenter.y = p->orbitCenter->y;
      p->returnCenter.z = p->orbitCenter->z;
      p->orbitDir = -p->orbitDir;
      p->rotSpeed = -15;
      p->subStateFns[4] = EneSword_SlaveBoomerangReturn;
    }
    p->body.knockback.x = FixToInt(1, p->body.knockback.x);
    p->body.knockback.z = FixToInt(1, p->body.knockback.z);
  }
}

void EneSword_UpdateSlaveFlash(SlaveSword* p) {
  if (--p->body.flashTimer == 0) {
    EneSword* owner = p->owner;
    Video_SetAuxSpritePltt(p->sprite.gfx, owner->plttID);
    p->sprite.gfx->pltt = owner->pltt;
    p->flashFn = NULL;
  }
}

// 弾かれたとき, 今の位置を直線移動の行き先にして moveDelta を作り直す
void EneSword_SlaveSetMoveToHere(SlaveSword* p) {
  p->moveTo.x = p->sprite.pos.x;
  p->moveTo.y = p->sprite.pos.y;
  p->moveTo.z = p->sprite.pos.z;
  p->moveDelta.x = p->moveTo.x - p->moveFrom.x;
  p->moveDelta.y = p->moveTo.y - p->moveFrom.y;
  p->moveDelta.z = p->moveTo.z - p->moveFrom.z;
}

// state 0, 本体の周りの自分の番号の位置に出現させ, 出現の演出を進める
// 残差は orbitDir の -1 を scaleY の 1 から作る形と Random の表の番地のレジスタ (174/173 命令), EneSword_SlaveSpinUp などと同じ壁
// Tier A-C は試済 (orbitAngle の項の順, if/else)
NON_MATCH void EneSword_SlaveStateAppear(SlaveSword* p) {
#ifdef NONMATCHING_C
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    EneSword* owner = p->owner;
    p->body.hp = owner->slaveHP;
    p->orbitAngle = owner->slaveAngle + p->body.idx * Div(256, owner->slaveCount);
    p->sprite.pos.x = owner->sprite.pos.x + Div(COS(p->orbitAngle) * 200, 0x1000);
    p->sprite.pos.y = owner->player->mover.pos.y + 220;
    p->sprite.pos.z = owner->sprite.pos.z + Div(SIN(p->orbitAngle) * 200, 0x1000);
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.rotation = 128;
    p->sprite.scaleX = 127;
    p->sprite.scaleY = 1;
    p->orbitDir = (Random() & 1) ? 1 : -1;
    p->orbitCenter = &owner->sprite.pos;
    p->hurtbox.flags &= ~HBF_HIDDEN;
    p->hitbox.flags &= ~HBF_HIDDEN;
    p->hurtbox.ignoreMask = 0x10;
    p->hitbox.ignoreMask = 0x10;
    p->subStateFns[0] = EneSword_SlaveAppearBegin;
  }
  if (p->subStateFns[0] != NULL) {
    p->subStateFns[0](p);
  }
#else
  INCFUNC("asm/func/EneSword_SlaveStateAppear.inc");
#endif
}

void EneSword_SlaveStateOrbit(SlaveSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->subStateFns[1] = EneSword_SlaveOrbitBegin;
  }
  EneSword_UpdateSlaveHover(p);
  if (p->subStateFns[1] != NULL) {
    p->subStateFns[1](p);
  }
}

void EneSword_SlaveStateSpin(SlaveSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->subStateFns[2] = EneSword_SlaveSpinBegin;
  }
  if (p->subStateFns[2] != NULL) {
    p->subStateFns[2](p);
  }
}

void EneSword_SlaveStateThrust(SlaveSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->subStateFns[3] = EneSword_SlaveThrustBegin;
  }
  if (p->subStateFns[3] != NULL) {
    p->subStateFns[3](p);
  }
}

void EneSword_SlaveStateBoomerang(SlaveSword* p) {
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->subStateFns[4] = EneSword_SlaveBoomerangBegin;
  }
  if (p->subStateFns[4] != NULL) {
    p->subStateFns[4](p);
  }
}

// やられたスレイブソードを点滅させながら消し, 煙を出す, 消えきったら mode 0 に戻す
void EneSword_SlaveStateDying(SlaveSword* p) {
  EneSword* owner = p->owner;
  if (EneSwordBody_ConsumeEntered(&p->body)) {
    p->hitbox.flags |= HBF_HIDDEN;
    p->hurtbox.flags |= HBF_HIDDEN;
    p->body.vanishTimer = 0;
    p->body.smokeCount = 20;
  }
  if (Sprite_UpdateVanishBlink(&p->sprite.flags, p->body.vanishTimer++, 10, 30)) {
    s32 state;
    Video_SetAuxSpritePltt(p->sprite.gfx, owner->plttID);
    state = 5;
    p->body.mode = 0;
    p->body.state = state;
    SET_FLAGS(p->body.flags, SWORDFLAG_ENTERED);
  }
  if ((p->body.vanishTimer & 7) == 0) {
    WorldPos pos = p->hitbox.center;
    Vec3 size;
    pos.x += 100;
    pos.y += 100;
    pos.z += 100;
    size.x = 80, size.y = 60, size.z = 40;
    EmitSmoke(&pos, 1, &size, 0, p->body.vanishTimer & 7, 14, 2, 2);
    PlaySound_082406e0(SONG_366);
  }
}

void EneSword_UpdateSlaveIdle(SlaveSword* p) {}

// 無敵時間を減らし, 状態と当たり判定と被弾の点滅を進める
void EneSword_UpdateSlaveActive(SlaveSword* p) {
  if (!TEST_FLAGS(p->body.flags, SWORDFLAG_UNK_4)) {
    if (p->hurtbox.iframes != 0) {
      p->hurtbox.iframes--;
    }
    if (p->stateFn != NULL) {
      p->stateFn(p);
    }
    EneSword_SlaveUpdateHitboxes(p);
    if (p->flashFn != NULL) {
      p->flashFn(p);
    }
  }
}

void (*const gSlaveSwordModeFuncs[2])(SlaveSword*) = {
    EneSword_UpdateSlaveIdle,
    EneSword_UpdateSlaveActive,
};  // 0x085ADDB0

void EneSword_UpdateSlaves(EneSword* p) {
  s32 i;
  for (i = 0; i < p->slaveCount; i++) {
    SlaveSword* slave = &p->slaves[i];
    gSlaveSwordModeFuncs[slave->body.mode](slave);
  }
}

s32 EneSword_Update(EneSword* p) {
  if (p->player->mode & PMODE_DEAD) {
    return 1;
  }
  EneSword_UpdateMainSword(p);
  EneSword_UpdateSlaves(p);
  if (p->hitResult != 0) {
    EneSword_ShowDamage(p, p->hitResult, 0);
    p->hitResult = 0;
    p->damage = 0;
  }
  p->frameCount++;
  return 0;
}

s32 EneSword_Destroy(EneSword* p) {
  s32 i;
  AuxSprite_Remove(&p->sprite);
  AuxShadow_Remove(&p->shadow);
  Hitbox_Unregister(&p->hitbox);
  Hitbox_Unregister(&p->hurtbox);
  for (i = 0; i < 4; i++) {
    AuxSprite_Remove(&p->afterimageSprites[i]);
  }
  for (i = 0; i < p->slaveCount; i++) {
    AuxSprite_Remove(&p->slaves[i].sprite);
    Hitbox_Unregister(&p->slaves[i].hitbox);
    Hitbox_Unregister(&p->slaves[i].hurtbox);
  }
  return 0;
}

// 本体の剣のスプライト, 影, 当たり判定, 残像を組み, '.A' '.T' '.p' '.K' '.M' を読む
void EneSword_InitMainSword(EneSword* p) {
  Vec3 size;
  Vec3 offset;
  s32 i;
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;
  p->player = gPlayerPtr[0];
  gfx = &p->gfx;
  sprite = &p->sprite;
  p->body.vel.x = 0, p->body.vel.y = 0, p->body.vel.z = 0;
  p->body.accel.x = 0, p->body.accel.y = 1, p->body.accel.z = 0;
  p->body.flags = 0;
  p->body.hp = 0;
  p->body.angle = 0;
  p->body.unk_3a = 0;
  p->body.unk_3b = 0;
  p->body.unk_36 = 0;
  p->body.flashTimer = 0;
  EneSwordBody_SetState(&p->body, 1, 0);
  p->stateFn = EneSword_StateSpawnWait;
  p->glowFn = EneSword_GlowBegin;
  p->flashFn = NULL;
  p->bobTimer = 20;
  Video_GetAuxSprite(gfx, SPR_SWORD_AX);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->flags |= SPRFLAG_AFFINE;
  Video_SetAuxSpritePltt(p->sprite.gfx, p->plttID);
  {
    rgb555* src = gfx->pltt;
    for (i = 0; i < 16; i++) {
      p->pltt[i] = src[i];
    }
  }
  gfx->pltt = p->pltt;
  p->glowPhaseLen = 5;
  p->glowCount = 0;
  p->glowHold = 0;
  AuxShadow_Init(&p->shadow, &p->sprite.pos, 0x30, 0x30, 0x30, 0x30, 0, 0, 0, 0, 0);
  if (VM_SeekToNamedArg('A')) {
    p->body.hp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.unk_1e = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.unk_20 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->maxHP = p->body.hp;
  }
  if (VM_SeekToNamedArg('T')) {
    for (i = 0; i < 2; i++) {
      p->atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      p->atkKnockback[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      p->atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      p->atkIframes[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (VM_SeekToNamedArg('p')) {
    sprite->pos.x = VM_GetValue();
    sprite->pos.y = VM_GetValue();
    sprite->pos.z = VM_GetValue();
  } else {
    sprite->pos.x = 0;
    sprite->pos.y = 0;
    sprite->pos.z = 0;
  }
  p->unk_cce = VM_GetNamedArgValue('K', 2);
  sprite->pos.y = Map_GetTileHeightAt(&sprite->pos) + 350;
  size.x = 50, size.y = 50, size.z = 50;
  offset.x = 0, offset.y = 0, offset.z = 0;
  Hitbox_Init(&p->hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(&p->hitbox, p->atkPower[0], p->atkKnockback[0], 0, p->atkAttrs[0], p->atkIframes[0]);
  Hitbox_SetHandler(&p->hitbox, EneSword_OnHit, p);
  Hitbox_Register(&p->hitbox);
  p->hitbox.flags &= ~HBF_HIDDEN;
  Hitbox_Init(&p->hurtbox, 0, HBF_HURTBOX | HBF_ACTOR | HBF_3 | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPowerAndAttributes(&p->hurtbox, p->body.power, p->body.attrs, p->body.weakness);
  Hitbox_SetHandler(&p->hurtbox, EneSword_OnHurt, p);
  Hitbox_Register(&p->hurtbox);
  p->postStateFn = EneSword_UpdateHitboxes;
  for (i = 0; i < 4; i++) {
    Video_GetAuxSprite(&p->afterimageGfx[i], SPR_SWORD_AX);
    AuxSprite_Add(&p->afterimageSprites[i], &p->afterimageGfx[i], 0);
    p->afterimageSprites[i].flags = SPRFLAG_BLINK_ODD | SPRFLAG_AFFINE | SPRFLAG_HIDDEN;
    p->afterimageSprites[i].priority = 3;
    p->afterimageSprites[i].pos.x = 0;
    p->afterimageSprites[i].pos.y = 0;
    p->afterimageSprites[i].pos.z = 0;
    Hitbox_Init(&p->afterimageHitboxes[i], 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetHandler(&p->afterimageHitboxes[i], NULL, p);
    Hitbox_Register(&p->afterimageHitboxes[i]);
    Hitbox_SetAttack(&p->afterimageHitboxes[i], p->atkPower[1], p->atkKnockback[1], 0, p->atkAttrs[1], p->atkIframes[1]);
    p->afterimageHitboxes[i].flags |= HBF_HIDDEN;
    Hitbox_Init(&p->afterimageHurtboxes[i], 0, HBF_HURTBOX | HBF_3 | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetPowerAndAttributes(&p->afterimageHurtboxes[i], p->body.power, p->body.attrs, p->body.weakness);
    Hitbox_SetHandler(&p->afterimageHurtboxes[i], NULL, p);
    Hitbox_Register(&p->afterimageHurtboxes[i]);
    p->afterimageHurtboxes[i].flags |= HBF_HIDDEN;
  }
  EneSword_InitPltts(p);
  EneSword_SetAfterimagePltt(p, p->blackPltt, 0xF7);
  EneSword_ReadArgM(p);
}

// '.c' '.C' '.n' を読み, スレイブソード4本を隠した状態で組む
// 残差はループ前で body と gfx の番地を作る順と定数の作り方だけ (343/342 命令)
// Tier A-C は試済 (slaveCount の if/else, p->slaves[i] 直書き, EneSwordBody_Init inline, ポインタを進めるループ)
NON_MATCH void EneSword_InitSlaveSwords(EneSword* p) {
#ifdef NONMATCHING_C
  Vec3 size;
  Vec3 offset;
  s32 i;
  size.x = 100, size.y = 100, size.z = 100;
  offset.x = 0, offset.y = 0, offset.z = 0;
  if (VM_SeekToNamedArg('c')) {
    p->slaveHP = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slavePower = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_c88 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_c8a = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_cea = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slaveAttrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slaveWeakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('C')) {
    p->slaveAtkPower = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slaveAtkKnockback = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slaveAtkAttrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->slaveAtkIframes = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('n')) {
    p->slaveCount = VM_GetValue();
  } else {
    p->slaveCount = 4;
  }
  for (i = 0; i < 4; i++) {
    SlaveSword* s = &p->slaves[i];
    s->body.vel.x = 0, s->body.vel.y = 0, s->body.vel.z = 0;
    s->body.accel.x = 0, s->body.accel.y = 1, s->body.accel.z = 0;
    s->body.flags = 0;
    s->body.hp = 0;
    s->body.angle = 0;
    s->body.unk_3a = 0;
    s->body.unk_3b = 0;
    s->body.unk_36 = 0;
    s->body.flashTimer = 0;
    s->flashFn = NULL;
    Video_GetAuxSprite(&s->gfx, SPR_SLAVE_SWORD_AX);
    AuxSprite_Add(&s->sprite, &s->gfx, 0);
    s->sprite.flags = SPRFLAG_AFFINE | SPRFLAG_HIDDEN;
    Video_SetAuxSpritePltt(s->sprite.gfx, p->plttID);
    s->body.idx = i;
    s->body.mode = 0;
    s->body.state = 0;
    SET_FLAGS(s->body.flags, SWORDFLAG_ENTERED);
    s->owner = p;
    s->bobTimer = 20;
    s->timer = 0;
    Hitbox_Init(&s->hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetHandler(&s->hitbox, EneSword_OnSlaveSwordHit, s);
    Hitbox_Register(&s->hitbox);
    Hitbox_SetAttack(&s->hitbox, p->slaveAtkPower, p->slaveAtkKnockback, HBSRC_10, p->slaveAtkAttrs, p->slaveAtkIframes);
    s->hitbox.flags |= HBF_HIDDEN;
    Hitbox_Init(&s->hurtbox, 0, HBF_HURTBOX | HBF_ACTOR | HBF_3 | HBF_DAMAGE, 0, HIM_4, &size, &offset);
    Hitbox_SetPowerAndAttributes(&s->hurtbox, p->slavePower, p->slaveAttrs, p->slaveWeakness);
    Hitbox_SetHandler(&s->hurtbox, EneSword_OnSlaveSwordHurt, s);
    Hitbox_Register(&s->hurtbox);
    s->hurtbox.flags |= HBF_HIDDEN;
  }
#else
  INCFUNC("asm/func/EneSword_InitSlaveSwords.inc");
#endif
}

s32 EneSword_Init(EneSword* p) {
  s32 i;
  p->plttVariant = VM_GetNamedArgValue('t', 0);
  p->plttID = OBP_SWORDAX(p->plttVariant);
  p->flashPlttID = OBP_WHITE_306;
  VM_SeekToNamedArg('a');
  for (i = 0; i < 2 && VM_GetPC() != NULL; i++) {
    p->defeatScriptArgs[i] = VM_GetValue();
  }
  if (VM_SeekToNamedArg('e')) {
    p->defeatScriptID = VM_GetValue();
  }
  if (VM_SeekToNamedArg('X')) {
    p->body.exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->body.weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  EneSword_InitSlaveSwords(p);
  EneSword_InitMainSword(p);
  p->frameCount = 0;
  return 0;
}

// 0xA1D7
EneSword* EneSword_Create(u16 id) {
  EneSword* p = CreateEntity(ENTITY_UNK_8, sizeof(EneSword));
  if (p != NULL) {
    p->id = id;
    SetEntityRoutine(p, EneSword_Update, EneSword_Destroy);
    if (EneSword_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
