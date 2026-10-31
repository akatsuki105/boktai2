#ifndef __INCLUDE_HITBOX_H__
#define __INCLUDE_HITBOX_H__

#include "gba/gba.h"
#include "types.h"

// HitboxData.flags
typedef u16 HitboxFlags;
typedef u32 HitboxFlags32;
#define HBFLAG_UNK_0 (1 << 0)     // 0x1, 食らい側に立っていると、攻撃側にも立っているときだけ当たる (Hitbox_CheckAllPairs)
#define HBFLAG_UNK_1 (1 << 1)     // 0x2
#define HBFLAG_HIDDEN (1 << 2)    // 0x4, 一時的に食らい判定を外すためのフラグ？, 食らい側に立っていると、どの攻撃とも判定せず center も更新しない (Hitbox_CheckAllPairs, Hitbox_UpdateBoxes)
#define HBFLAG_UNK_3 (1 << 3)     // 0x8
#define HBFLAG_UNK_7 (1 << 7)     // 0x80
#define HBFLAG_ANGLE (1 << 8)     // 0x100, 向きの概念があるものにつける, バックアタックの判定, 攻撃のノックバック方向 などで利用
#define HBFLAG_UNK_9 (1 << 9)     // 0x200, 立っていると相手の hitState bit0 を消費する (Django_OnHurt)
#define HBFLAG_UNK_10 (1 << 10)   // 0x400, 立っていると相手の hitState bit1 で1回だけに制限する (Django_OnHurt)
#define HBFLAG_UNK_11 (1 << 11)   // 0x800
#define HBFLAG_ACTOR (1 << 12)    // 0x1000, プレイヤーと敵の食らい判定につく, 攻撃判定に立っていると HBFLAG_ACTOR 付きの食らい判定にしか当たらない (Hitbox_CheckAllPairs)
#define HBFLAG_HITBOX (1 << 13)   // 0x2000, 攻撃判定 (このフラグがセットされていたら hitbox, そうでないなら食らい判定(hurtbox)として扱っているっぽい, つまり下の HBFLAG_HURTBOX は意味がなさそう)
#define HBFLAG_HURTBOX (1 << 14)  // 0x4000, 食らい判定 (開発用の目印かも？ このフラグを参照しているものが見つからない)

// HitboxData.hitResult, Hitbox_ApplyDamage が書く
typedef u8 HitboxHitResult8;
#define HBRESULT_NORMAL (1 << 0)  // 0x1, 等倍または 5/4倍
#define HBRESULT_RESIST (1 << 1)  // 0x2, 属性が噛み合って 1/4倍
#define HBRESULT_WEAK (1 << 2)    // 0x4, 弱点を突いて 4倍
#define HBRESULT_BONUS (1 << 3)   // 0x8, 1.5倍の追加補正を適用済み, 背後から当てたとき、または dark_django_0806f990 の条件で立つ

// HitboxData.hitState, 多段ヒットを抑えるために相手の攻撃側 flags と組で見る
typedef u8 HitboxHitState8;
#define HBHITSTATE_UNK_0 (1 << 0)  // 0x1, 相手の HBFLAG_UNK_9 が消費する
#define HBHITSTATE_UNK_1 (1 << 1)  // 0x2, 相手の HBFLAG_UNK_10 が1回だけに制限するのに使う

typedef u32 HitboxAttributes;      // 低位7bitが自分の属性マスク, 攻撃側の属性と守備側の耐性を兼ねる, bit7-11 は dark_django_0806f990 が別の用途で見る
#define HBATTR_SOL (1 << 0)        // 0x1, ソル属性
#define HBATTR_DARK (1 << 1)       // 0x2, ダーク属性
#define HBATTR_FLAME (1 << 2)      // 0x4, 炎属性
#define HBATTR_FROST (1 << 3)      // 0x8, 氷属性
#define HBATTR_CLOUD (1 << 4)      // 0x10, 風属性
#define HBATTR_EARTH (1 << 5)      // 0x20, 地属性
#define HBATTR_ALL (1 << 6)        // 0x40, 全属性
#define HBATTR_BEAST (1 << 7)      // 0x80, ビースト系の敵
#define HBATTR_THING (1 << 8)      // 0x100, シング系の敵
#define HBATTR_PHANTOM (1 << 9)    // 0x200, ファントム系の敵
#define HBATTR_UNDEAD (1 << 10)    // 0x400, アンデッド系の敵
#define HBATTR_IMMORTAL (1 << 11)  // 0x800, イモータル系の敵
#define HBATTR_NAMAKURA (1 << 12)  // 0x1000, 防御力無視の攻撃
#define HBATTR_13 (1 << 13)        // 0x2000, 守備側の耐性を無視する
#define HBATTR_14 (1 << 14)        // 0x4000, (プレイヤーに)当たると石化の状態異常?
#define HBATTR_POISON (1 << 15)    // 0x8000, 当たると毒になる (EBUFF_IMMUNEPOISON なら防ぐ)
#define HBATTR_17 (1 << 17)        // 0x20000, 当たると Player_TakeHit が FUN_080dc0b8 を呼ぶ
#define HBATTR_18 (1 << 18)        // 0x40000, ???
#define HBATTR_19 (1 << 19)        // 0x80000, ???
#define HBATTR_CONFUSE (1 << 20)   // 0x100000, 当たると混乱になる
#define HBATTR_INKA (1 << 21)      // 0x200000, (プレイヤーに)当たると引火の状態異常
#define HBATTR_HYOKETU (1 << 22)   // 0x400000, (プレイヤーに)当たると氷結の状態異常

// HitboxData.ignoreMask
#define HIM_0 (1 << 0)  // 0x1
#define HIM_1 (1 << 1)  // 0x2
#define HIM_2 (1 << 2)  // 0x4
#define HIM_3 (1 << 3)  // 0x8
#define HIM_4 (1 << 4)  // 0x10
#define HIM_5 (1 << 5)  // 0x20

// TODO: 解析が終わって問題なさそうなら HitboxData じゃなくて Hitbox にリネームする
// 当たり判定も食らい判定も同じ構造体で扱う, HBFLAG_HITBOX で攻撃判定かどうかを区別する
typedef struct HitboxData {
  struct HitboxData* next;      // 0x00, 同じキャラの Hitbox なのか、全ての Hitbox をつなげているのかはまだ不明
  u16 id;                       // 0x04, 0x08236db8, IDっぽい
  HitboxFlags flags;            // 0x06, see HitboxFlags
  u16 unk_8;                    // 0x08
  u16 ignoreMask;               // 0x0A, ((this.ignoreMask & other.ignoreMask) == 0) なら、Overlap 判定を行う, != 0 でなく == 0 に注意
  WorldPos pos;                 // 0x0C, Hitbox_SetPos が毎フレーム書く判定の基準位置
  Vec3 offset;                  // 0x14, pos からのずれ
  Vec3 halfSize;                // 0x1C, 判定の直方体の各軸の半径, Hitbox_Init が引数の Vec3 を8バイトまるごとコピーする
  WorldPos center;              // 0x24, 判定の直方体の中心, Hitbox_UpdateBoxes が毎フレーム pos + offset で作る
  Vec3 unk_2c;                  // 0x2C, ShadeManCrossover_OnHurt が 8 バイトまるごと写す
  u32 weakness;                 // 0x34, 低位7bitが属性マスク, Hitbox_ApplyDamage が (b->weakness & 0x7F & a->attributes) != 0 でダメージ4倍にする
  HitboxAttributes attributes;  // 0x38, see HitboxAttributes
  u16 power;                    // 0x3C (Player: 0x1A8), Hitbox_ApplyDamage の基礎ダメージ = a->power - b->power (1未満なら1), 攻撃側では攻撃力、守備側では防御力

  // 0x3E, そのヒットで与えるダメージ, Hitbox_ApplyDamage が b->damage に計算結果を書き、被弾側の fn が読んで体力から引く (Breakable_OnHit, FUN_08013288 など), 0 になることはなく、最低 1 に切り上げられる
  // 攻撃側でも使われる: ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で a->damage (Player.wpn.hitbox.damage) に値が加算され、Player_UpdateWeaponWear がこれを武器の耐久ダメージ (Weapon.wear) として吸い上げる
  u16 damage;

  u16 knockbackPower;  // 0x40, Hitbox_SetAttack の第3引数, 当たると Player_SetupKnockback が相手に写し (200 で頭打ち), 食らい側はこれを振幅に後ろへ動いて毎回 3/4 倍に減らす

  // 0x42, 8bit の向き, Hitbox_GetPushDir が (angle + 0x20 & 0xFF) >> 6 で押し出し方向の象限を出し、Breakable_OnHit が gSineTable の添字に使う
  // Hitbox_ApplyDamage は a と b の差が 33 未満なら背後から当てたとみなして 1.5倍にする
  u8 angle;

  HitboxHitResult8 hitResult;  // 0x43, see HBRESULT_*
  u16 invincibleTime;          // 0x44, 攻撃側では当てた相手に与える無敵時間, 食らい側では残りの無敵時間 (毎フレーム減り,0でない間は食らわない), 被弾時に Player_TakeHit / FUN_0813e944 が a から b へそのままコピーする
  HitboxHitState8 hitState;    // 0x46, 多段ヒット管理, see HBHITSTATE_*
  u8 unk_47;                   // 0x47, Hitbox_Init が 1 にする, 読み手が見つかっていない

  // 0x48, e.g. dark_django_0806f990(ジャンゴ), FUN_0813e944(バット)
  // Overlap時に呼ばれるが、ダメージ計算などの汎用処理もここでやるのか、追加のカスタム処理のためのコールバックなのかは不明
  // a: 攻撃側, b: 被攻撃側, owner: このHitboxの持ち主 (a->owner or b->owner のどちらか)
  // 例え、ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 では a は Player.Hitbox, b は EnemyBat.Hitbox, owner は EnemyBat
  void (*fn)(struct HitboxData* a, struct HitboxData* b, void* owner);

  void* owner;  // 0x4C, このHitboxの持ち主
} HitboxData;
static_assert(sizeof(HitboxData) == 80);

static inline void Hitbox_SetFlags(HitboxData* hitbox, HitboxFlags flags) { hitbox->flags |= flags; }
static inline void Hitbox_ClearFlags(HitboxData* hitbox, HitboxFlags flags) { hitbox->flags &= ~flags; }
static inline HitboxFlags Hitbox_TestFlags(HitboxData* hitbox, HitboxFlags flags) { return hitbox->flags & flags; }
static inline bool32 Hitbox_HasWeakness(HitboxData* hitbox, u32 mask) { return hitbox->weakness & mask; }
static inline u32 Hitbox_TestAttr(HitboxData* hitbox, HitboxAttributes mask) { return (hitbox->attributes & mask); }
static inline s32 Hitbox_GetDamage(HitboxData* hb) { return hb->damage; }
static inline void Hitbox_ClearDamage(HitboxData* hb) { hb->damage = 0; }

void Hitbox_Register(HitboxData* p);
void Hitbox_Init(HitboxData* p, u16 id, HitboxFlags32 flags, u32 unk_8, u16 ignoreMask, Vec3* halfSize, Vec3* offset);
void Hitbox_SetPos(HitboxData* p, Vec3* pos, u32 unk_8);
void Hitbox_SetAttack(HitboxData* p, s32 power, s32 knockbackPower, s32 weakness, HitboxAttributes attrs, s32 invincibleTime);
void Hitbox_SetPowerAndAttributes(HitboxData* p, u32 power, HitboxAttributes attrs, u32 weakness);
void Hitbox_SetHandler(HitboxData* p, void* handler, void* owner);
void Hitbox_Unregister(HitboxData* p);
void Hitbox_ApplyDamage(HitboxData* a, HitboxData* b);

s32 CreateDamageNumber(HitboxData* hitbox, s32 amount, s32 kind, Vec3* pos, Vec3* param_5, s32 priority);

#endif  // __INCLUDE_HITBOX_H__
