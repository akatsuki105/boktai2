#ifndef __INCLUDE_HITBOX_H__
#define __INCLUDE_HITBOX_H__

#include "gba/gba.h"
#include "types.h"

typedef u16 HitboxFlags;
#define HBFLAG_UNK_0 (1 << 0)    // 0x2
#define HBFLAG_UNK_1 (1 << 1)    // 0x2
#define HBFLAG_UNK_2 (1 << 2)    // 0x4
#define HBFLAG_UNK_8 (1 << 8)    // 0x100
#define HBFLAG_UNK_13 (1 << 13)  // 0x2000

// paddingがあるので Vec3 を使うべきかも?
typedef struct {
  s8_8 x, y, z, pad_6;  // 座標
  s8_8 w, h, d, pad_e;  // 幅、高さ、奥
} AABB;

// TODO: 解析が終わって問題なさそうなら HitboxData じゃなくて Hitbox にリネームする
typedef struct HitboxData {
  struct HitboxData* next;  // 0x00, 同じキャラの Hitbox なのか、全ての Hitbox をつなげているのかはまだ不明
  u16 unk_4;                // 0x04, 0x08236db8, IDっぽい
  HitboxFlags flags;        // 0x06, see HitboxFlags
  u8 unk_8[0xA - 0x8];
  u16 ignoreMask;  // 0x0A, ((this.ignoreMask & other.ignoreMask) == 0) なら、Overlap 判定を行う, != 0 でなく == 0 に注意
  Vec3 vec3_c;     // 0x0C
  Vec3 vec3_14;    // 0x14
  AABB box;        // 0x1C, 判定の範囲
  u8 unk_2c[0x34 - 0x2C];
  u32 unk_34;  // 0x34 (Player: 0x1A0)
  u32 unk_38;  // 0x38 (Player: 0x1A4)
  u16 unk_3c;  // 0x3C (Player: 0x1A8)

  // 0x3E, 0x08236df8
  // 用途は owner や fn に依存する汎用データ?
  // ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で a->wear (Player.unk_a10.wear) に値が加算される, Player_UpdateWeaponWear でこれを武器の耐久ダメージとして使う
  u16 wear;

  u8 unk_40[8];  // 0x40 (Player: 0x1AC)

  // 0x48, e.g. dark_django_0806f990(ジャンゴ), FUN_0813e944(バット)
  // Overlap時に呼ばれるが、ダメージ計算などの汎用処理もここでやるのか、追加のカスタム処理のためのコールバックなのかは不明
  // a: 攻撃側, b: 被攻撃側, owner: このHitboxの持ち主 (a->owner or b->owner のどちらか)
  // 例え、ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 では a は Player.Hitbox, b は Bat.Hitbox, owner は Bat
  void (*fn)(struct HitboxData* a, struct HitboxData* b, void* owner);

  void* owner;  // 0x4C, このHitboxの持ち主
} HitboxData;
static_assert(sizeof(HitboxData) == 80);

#endif  // __INCLUDE_HITBOX_H__
