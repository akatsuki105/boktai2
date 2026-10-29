#ifndef __INCLUDE_BOSS_H__
#define __INCLUDE_BOSS_H__

#include "emote.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "trig.h"
#include "types.h"

typedef s32 BossID;
#define BOSS_DUNEYRR 0             // ドゥネイル
#define BOSS_RINGO 1               // 紅のリンゴ?
#define BOSS_DURATHROR 2           // ドゥラスロール
#define BOSS_DVALINN 3             // ドヴァリン
#define BOSS_DAINN 4               // ダーイン?
#define BOSS_JORMUNGANDR 5         // ヨルムンガンド
#define BOSS_SHADEMAN 6            // シェードマン(シングルプレイ用)
#define BOSS_SHADEMAN_CROSSOVER 7  // シェードマン(クロスオーバーバトル用)

// Boss.flags, Boss_UpdateState が毎フレーム 0 に戻し、その後の状態処理が立てる
typedef u32 BossFlags;
#define BOSSFLAG_UNK_0 (1 << 0)       // 0x1
#define BOSSFLAG_UNK_1 (1 << 1)       // 0x2
#define BOSSFLAG_NO_HURTBOX (1 << 2)  // 0x4, hurtbox に HBFLAG_HIDDEN を付けて食らわないようにする
#define BOSSFLAG_NO_HITBOX (1 << 3)   // 0x8, hitbox を登録しない
#define BOSSFLAG_HIDDEN (1 << 4)      // 0x10, スプライトと影を隠す
#define BOSSFLAG_NO_SHADOW (1 << 16)  // 0x10000, 影だけを隠す
#define BOSSFLAG_UNK_17 (1 << 17)     // 0x20000, ボスごとに意味が違う (ドゥラスロールは sprite_4e8 を出す)
#define BOSSFLAG_UNK_18 (1 << 18)     // 0x40000, ボスごとに意味が違う (リンゴは揺らす, ドゥラスロールは node の bit0 を落とす)
#define BOSSFLAG_UNK_19 (1 << 19)     // 0x80000, リンゴは hurtbox2 を有効にして本体のダメージを止める
#define BOSSFLAG_HITBOX2 (1 << 20)    // 0x100000, hitbox2 を登録する
#define BOSSFLAG_VISIBLE (1 << 21)    // 0x200000, BOSSFLAG_HIDDEN が立っていないとき各ボスの Update が立てる
#define BOSSFLAG_UNK_22 (1 << 22)     // 0x400000, シェードマン (クロスオーバー) は hitbox の攻撃力を2つ目の値に切り替える
#define BOSSFLAG_UNK_23 (1 << 23)     // 0x800000
#define BOSSFLAG_UNK_24 (1 << 24)     // 0x1000000
#define BOSSFLAG_UNK_31 (1u << 31)    // 0x80000000

// 全ボスの構造体が先頭に持つ共通部分, 各ボスは Boss base; として埋め込む
// サイズの根拠: ヨルムンガンドは 0x158 から HitboxData を持ち、ドヴァリンとシェードマンは 0x15C から自分の当たり判定を持つ, src/boss.c の関数が触るのも 0x156 まで
// MainSprite / MainSpriteGfx は共通部分に入っていない (ボスごとに位置が違うので引数で渡される, 例: bee_0803aee4 は +0x280 / +0x260)
struct Boss;
typedef void (*BossUpdateFunc)(struct Boss* p, s32 timer);
typedef bool8 (*BossCheckFunc)(struct Boss* p);

typedef struct Boss {
  Entity e;                            // 0x000, ENTITY_UNK_8
  u8 unk_18[0x48 - 0x18];              // 0x018, まだ未解析
  Mover mover;                         // 0x048
  u32 timer;                           // 0x08C, Boss_UpdateState が毎回 +1 し、増やす前の値を updateCallback に渡す
  s16 hp;                              // 0x090, 0..maxHP, HUD 用に gStat の 0x2B8 へ写される
  s16 maxHP;                           // 0x092, HUD 用に gStat の 0x2BC へ写される
  s16 hurtboxPower;                    // 0x094, 各ボスが hurtbox の power と同じ値を入れる
  u8 canDie;                           // 0x096, 下位状態ハンドラが毎フレーム立て, hp <= 0 かつ立っているときだけ死亡状態へ移る
  u8 bossID;                           // 0x097, see BossID, gBossList の添字
  BossFlags flags;                     // 0x098
  bool8 lowHP;                         // 0x09C, hpRatio < 0x40
  u8 unk_9d;                           // 0x09D
  u8 unk_9e[0xA0 - 0x9E];              // 0x09E
  u8 facing;                           // 0x0A0, 0..3 の向き, 1 か 2 のときだけ呼び出し側の variant を使い、2 以上で左右反転する
  DirU8 dir;                           // 0x0A1, 8方向の向き, Boss_PlayAnimDir8 は 5..7 を左右反転して使う
  u8 state;                            // 0x0A2, 切り替えたい状態番号, stateRequestCallback が表を引いて updateCallback を差し替える
  u8 curState;                         // 0x0A3, 今の updateCallback の状態番号
  u8 subState0;                        // 0x0A4, 3段の下位状態の1段目, stateRequestCallback とは別に各ボスが表を引いて処理を呼び分ける
  u8 subState1;                        // 0x0A5, 2段目
  u8 subState2;                        // 0x0A6, 3段目
  bool8 subStateDone;                  // 0x0A7, 毎回 0 に戻り, 下位状態を続ける時間が過ぎたフレームに立つ
  bool8 subStateEntered;               // 0x0A8, 下位状態を差し替えると 1, その状態の最初のフレームで 0 に戻す
  bool8 stateEntered;                  // 0x0A9, updateCallback を差し替えると 1, 各状態の最初のフレームで 0 に戻す
  bool8 animDone;                      // 0x0AA, MainSprite_AdvanceAnim の戻り値
  u8 isDemo;                           // 0x0AB, '.i', 立っていると初期状態を '.D' で選ぶ, 0 のボスだけを FUN_08022a3c が拾う
  u8 unk_ac;                           // 0x0AC, 0 でない間 FUN_08022ec0 が減らしながら Camera_Shake(unk_ad) を呼ぶ
  u8 unk_ad;                           // 0x0AD
  u8 animVariant;                      // 0x0AE, facing から決まるアニメ番号のオフセット
  bool8 xflip;                         // 0x0AF, 0 以外なら MainSprite に SPRFLAG_XFLIP を立てる
  u16 animID;                          // 0x0B0, animVariant + 呼び出し側のアニメ番号, MainSprite_SetAnim に渡した値
  u16 prevAnimID;                      // 0x0B2, Boss_AdvanceAnim が animID を写す
  u32 weaponExpMask;                   // 0x0B4, Player_AddWeaponExp の mask
  HitboxAttributes hurtAttributes;     // 0x0B8, 当たってきた攻撃の attributes, weaponExpMask と対
  u32 subStateTimer;                   // 0x0BC, 下位状態を差し替えると 0 に戻る
  s32 playerDistSq[2];                 // 0x0C0, playerPos までの距離の2乗
  u8 playerAngle[2];                   // 0x0C8, playerPos への 8bit 角度
  u8 unk_ca[0xCC - 0xCA];              // 0x0CA
  Vec3 targetPos;                      // 0x0CC, x と z だけ読まれる, FUN_08022e20 が mover.pos からの向きと距離を出す
  s32 targetDistSq;                    // 0x0D4, targetPos までの距離の2乗
  u32 targetAngle;                     // 0x0D8, targetPos への 8bit 角度
  u8 unk_dc;                           // 0x0DC
  u8 hpRatio;                          // 0x0DD, hp * 128 / maxHP
  u8 damageBonus;                      // 0x0DE, '.x=2', 受けたダメージに足す
  u8 unk_df;                           // 0x0DF
  u32 frameCount;                      // 0x0E0, 毎フレーム増える, FUN_08022ec0 が & 3 で間引きに使う
  u16 unk_e4;                          // 0x0E4, FUN_08022fb8 が VM_ExecByID で実行するスクリプト ID
  u16 unk_e6;                          // 0x0E6, FUN_08023024 が VM_ExecByID で実行するスクリプト ID
  u32 unk_e8[4];                       // 0x0E8, unk_e4 / unk_e6 のスクリプトに渡す引数
  BossUpdateFunc updateCallback;       // 0x0F8
  BossCheckFunc damageCallback;        // 0x0FC, 受けたダメージを hp に反映し、状態を変えたら 1 を返す
  BossCheckFunc stateRequestCallback;  // 0x100, state が有効なら updateCallback を差し替えて 1 を返す
  struct Player* players[2];           // 0x104
  Vec3* playerPos[2];                  // 0x10C, players[i] の mover.pos
  s8 destAngle;                        // 0x114, Boss_Init の angle, mover.angle をこの角度まで回す
  u8 unk_115[0x118 - 0x115];           // 0x115
  MsgQueue msgQueue;                   // 0x118
  Emote* emote;                        // 0x14C, Boss_ShowEmote が Emote_Show に渡して戻り値を入れ直す
  u16 unk_150;                         // 0x150, Emote_Show の第5引数 (ポインタ) に渡る
  s16 unk_152;                         // 0x152, Emote_Show の第6引数
  u8 unk_154;                          // 0x154, Cmd_SetBossFlags ('.s') が立て ('.e') が落とす, 立っている間 FUN_08022ec0 が FUN_0802326c を呼ぶ
  u8 unk_155;                          // 0x155, Cmd_SetBossFlags ('.b') が立てる, FUN_08022ec0 が flags に BOSSFLAG_HIDDEN を立てる条件
  u8 unk_156;                          // 0x156, Cmd_SetBossFlags ('.i') が立てる, FUN_08022ec0 が flags に BOSSFLAG_HIDDEN を立てる条件
  u8 unk_157;                          // 0x157
} Boss;
static_assert(sizeof(Boss) == 344);

// HP の割合 (0..128) を返す
static inline s32 Boss_GetHPRatio(Boss* p) { return p->hpRatio; }

// mover.angle を差し替えて facing と dir をそれに合わせる
static inline void Boss_SetAngle(Boss* p, u32 angle) {
  p->mover.angle = angle;
  p->facing = Angle_ToDir4(p->mover.angle);
  p->dir = Angle_ToDir8(p->mover.angle);
}

// 当たってきた攻撃の weakness / attributes を控える, 経験値の配分に使う
static inline void Boss_SetWeaponExpMask(Boss* p, u32 mask) { p->weaponExpMask = mask; }
static inline void Boss_SetHurtAttributes(Boss* p, HitboxAttributes attributes) { p->hurtAttributes = attributes; }

// updateCallback を差し替えて timer を 0 に戻す
static inline void Boss_SetState(Boss* p, void* fn, u32 state) {
  p->curState = state;
  p->updateCallback = fn;
  p->timer = 0;
  p->stateEntered = TRUE;
}

// stateRequestCallback で切り替える状態番号を入れる
static inline void Boss_RequestState(Boss* p, u8 state) { p->state = state; }

// 下位状態の3段目を差し替える
static inline void Boss_SetSubState2(Boss* p, u32 subState) {
  p->subState2 = subState;
  p->subStateTimer = 0;
  p->subStateEntered = TRUE;
}

// 下位状態を3段まとめて差し替える
static inline void Boss_SetSubStates(Boss* p, u32 subState0, u32 subState1, u32 subState2) {
  p->subState0 = subState0;
  p->subState1 = subState1;
  Boss_SetSubState2(p, subState2);
}

// targetPos への向きと距離を作り直す, 作り直している間は unk_dc を下ろしておく
static inline void Boss_UpdateTarget(Boss* p) {
  Mover* mover;
  s32 dx;
  s32 dz;

  p->unk_dc = 0;
  mover = &p->mover;
  dx = p->targetPos.x - mover->pos.x;
  dz = p->targetPos.z - mover->pos.z;
  p->targetAngle = (u8)ArcTan2_8(dx, dz);
  p->targetDistSq = dx * dx + dz * dz;
  p->unk_dc = 1;
}

static inline void Boss_SetTarget(Boss* p, s32 x, s32 y, s32 z) {
  p->targetPos.x = x;
  p->targetPos.y = y;
  p->targetPos.z = z;
  Boss_UpdateTarget(p);
}

// 下位状態に入った最初のフレームなら subStateEntered と subStateDone を下ろして TRUE を返す
static inline bool8 Boss_EnterSubState(Boss* p) {
  if (p->subStateEntered) {
    p->subStateEntered = FALSE;
    p->subStateDone = FALSE;
    return TRUE;
  }
  return FALSE;
}

void Boss_Register(Boss*, BossID);
void Boss_Unregister(BossID id);
void* Boss_Get(BossID);
Boss* FUN_08022a3c(void);
s32 Boss_Init(Boss* p, u32 id, BossID bossID, Vec3* pos, u32 angle);
s32 Boss_Destroy(Boss*);
s32 Boss_InitHP(Boss* p, s32 hp, s32 maxHP, s32 hurtboxPower);
s32 Boss_SetHP(Boss* p, s32 hp);
s32 FUN_08022c24(Boss* p, u32 param_2, u32 param_3);
void Boss_PlayAnimFlip(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 flags);
void Boss_PlayAnimFacing(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 variant, u32 flags);
void Boss_PlayAnimDir8(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 variant, u32 flags);
void Boss_PlayAnim(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 flags);
s32 Boss_AdvanceAnim(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx);
void FUN_08022e20(Boss*);
void FUN_08022ec0(Boss*);
void Boss_UpdateState(Boss* p);
void FUN_08022fac(Boss* p, u32 scriptA, u32 scriptB);
void FUN_08022fb8(Boss* p, Vec3* pos);
void FUN_08023024(Boss* p, Vec3* pos);
void Boss_GiveWeaponExp(Boss* p, s32 amount);
s32 FUN_080230a0(Vec3* out);
void Boss_ShowEmote(Boss* p, u32 kind, s32 param_3, s32 param_4);
void FUN_08015d3c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);

#endif  // __INCLUDE_BOSS_H__
