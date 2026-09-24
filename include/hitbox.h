#ifndef __INCLUDE_HITBOX_H__
#define __INCLUDE_HITBOX_H__

#include "gba/gba.h"
#include "types.h"

typedef u16 HitboxFlags;
typedef u32 HitboxFlags32;
#define HBFLAG_UNK_0 (1 << 0)    // 0x1
#define HBFLAG_UNK_1 (1 << 1)    // 0x2
#define HBFLAG_UNK_2 (1 << 2)    // 0x4
#define HBFLAG_UNK_8 (1 << 8)    // 0x100
#define HBFLAG_UNK_9 (1 << 9)    // 0x200, 立っていると相手の hitState bit0 を消費する (FUN_0807e784)
#define HBFLAG_UNK_10 (1 << 10)  // 0x400, 立っていると相手の hitState bit1 で1回だけに制限する (FUN_0807e784)
#define HBFLAG_UNK_12 (1 << 12)  // 0x1000
#define HBFLAG_UNK_13 (1 << 13)  // 0x2000
#define HBFLAG_UNK_14 (1 << 14)  // 0x4000

// HitboxData.hitResult, Hitbox_ApplyDamage が書く
typedef u8 HitboxHitResult8;
#define HBRESULT_NORMAL (1 << 0)  // 0x1, 等倍または 5/4倍
#define HBRESULT_RESIST (1 << 1)  // 0x2, 属性が噛み合って 1/4倍
#define HBRESULT_WEAK (1 << 2)    // 0x4, 弱点を突いて 4倍
#define HBRESULT_BONUS (1 << 3)   // 0x8, 1.5倍の追加補正を適用済み。背後から当てたとき、または dark_django_0806f990 の条件で立つ

// TODO: 解析が終わって問題なさそうなら HitboxData じゃなくて Hitbox にリネームする
typedef struct HitboxData {
  struct HitboxData* next;  // 0x00, 同じキャラの Hitbox なのか、全ての Hitbox をつなげているのかはまだ不明
  u16 unk_4;                // 0x04, 0x08236db8, IDっぽい
  HitboxFlags flags;        // 0x06, see HitboxFlags
  u16 unk_8;                // 0x08
  u16 ignoreMask;           // 0x0A, ((this.ignoreMask & other.ignoreMask) == 0) なら、Overlap 判定を行う, != 0 でなく == 0 に注意
  Vec3 pos;                 // 0x0C, Hitbox_SetPos が毎フレーム書く判定の基準位置
  Vec3 offset;              // 0x14, pos からのずれ
  Vec3 halfSize;            // 0x1C, 判定の直方体の各軸の半径。Hitbox_Init が引数の Vec3 を8バイトまるごとコピーする
  Vec3 center;              // 0x24, 判定の直方体の中心。Hitbox_UpdateBoxes が毎フレーム pos + offset で作る
  u8 unk_2c[0x34 - 0x2C];
  u32 weakness;    // 0x34 (Player: 0x1A0), 低位7bitが属性マスク。Hitbox_ApplyDamage が (b->weakness & 0x7F & a->attributes) != 0 でダメージ4倍にする
  u32 attributes;  // 0x38 (Player: 0x1A4), 低位7bitが自分の属性マスク。攻撃側の属性と守備側の耐性を兼ねる。bit12 で守備側の power を引かない, bit13 で守備側の耐性を無視する。bit7-11 は dark_django_0806f990 が別の用途で見る
  u16 power;       // 0x3C (Player: 0x1A8), Hitbox_ApplyDamage の基礎ダメージ = a->power - b->power (1未満なら1)。攻撃側では攻撃力、守備側では防御力

  // 0x3E, そのヒットで与えるダメージ。Hitbox_ApplyDamage が b->damage に計算結果を書き、被弾側の fn が読んで体力から引く (Breakable_OnHit, FUN_08013288 など)。0 になることはなく、最低 1 に切り上げられる
  // 攻撃側でも使われる: ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で a->damage (Player.unk_a10.damage) に値が加算され、Player_UpdateWeaponWear がこれを武器の耐久ダメージ (Weapon.wear) として吸い上げる
  u16 damage;

  u16 unk_40;  // 0x40 (Player: 0x1AC)

  // 0x42, 8bit の向き。Hitbox_GetPushDir が (angle + 0x20 & 0xFF) >> 6 で押し出し方向の象限を出し、Breakable_OnHit が gSineTable の添字に使う
  // Hitbox_ApplyDamage は a と b の差が 0x21 未満なら背後から当てたとみなして 1.5倍にする
  u8 angle;

  HitboxHitResult8 hitResult;  // 0x43, see HBRESULT_*
  u16 unk_44;                  // 0x44, Hitbox_SetAttack の第6引数 (FUN_0800e594 では 0x3C)。被弾時に FUN_0807e3b0 / FUN_0813e944 が a から b へそのままコピーする
  u8 hitState;                 // 0x46, 多段ヒット管理。see HBFLAG_UNK_9 / HBFLAG_UNK_10
  u8 unk_47;                   // 0x47, Hitbox_Init が 1 にする。読み手が見つかっていない

  // 0x48, e.g. dark_django_0806f990(ジャンゴ), FUN_0813e944(バット)
  // Overlap時に呼ばれるが、ダメージ計算などの汎用処理もここでやるのか、追加のカスタム処理のためのコールバックなのかは不明
  // a: 攻撃側, b: 被攻撃側, owner: このHitboxの持ち主 (a->owner or b->owner のどちらか)
  // 例え、ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 では a は Player.Hitbox, b は Bat.Hitbox, owner は Bat
  void (*fn)(struct HitboxData* a, struct HitboxData* b, void* owner);

  void* owner;  // 0x4C, このHitboxの持ち主
} HitboxData;
static_assert(sizeof(HitboxData) == 80);

static inline void Hitbox_SetFlags(HitboxData* p, HitboxFlags flags) { p->flags |= flags; }
static inline void Hitbox_ClearFlags(HitboxData* p, HitboxFlags flags) { p->flags &= ~flags; }

void Hitbox_Register(HitboxData* p);
void Hitbox_Init(HitboxData* p, u32 id, HitboxFlags32 flags, u32 unk_8, u16 ignoreMask, Vec3* halfSize, Vec3* offset);
void Hitbox_SetPos(HitboxData* p, Vec3* pos, u32 unk_8);
void Hitbox_SetAttack(HitboxData* p, s32 power, s32 unk_40, s32 weakness, s32 attributes, s32 unk_44);
void Hitbox_SetPowerAndAttributes(HitboxData* p, u32 power, u32 attributes, u32 weakness);
void Hitbox_SetHandler(HitboxData* p, void* handler, void* owner);
void Hitbox_Unregister(HitboxData* p);
void Hitbox_ApplyDamage(HitboxData* a, HitboxData* b);

#endif  // __INCLUDE_HITBOX_H__
