#ifndef __INCLUDE_HITBOX_H__
#define __INCLUDE_HITBOX_H__

#include "gba/gba.h"
#include "types.h"

typedef u16 HitboxFlags;
#define HBFLAG_UNK_0 (1 << 0)    // 0x2
#define HBFLAG_UNK_1 (1 << 1)    // 0x2
#define HBFLAG_UNK_2 (1 << 2)    // 0x4
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
  u32 unk_34;                                                       // 0x34 (Player: 0x1A0)
  u32 unk_38;                                                       // 0x38 (Player: 0x1A4)
  u16 unk_3c;                                                       // 0x3C (Player: 0x1A8)
  u16 unk_3e;                                                       // 0x3E, 0x08236df8
  u8 unk_40[8];                                                     // 0x40 (Player: 0x1AC)
  void (*fn)(struct HitboxData*, struct HitboxData*, void* owner);  // 0x48, e.g. dark_django_0806f990, Overlap時に呼ばれるが、ダメージ計算などの汎用処理もここでやるのか、追加のカスタム処理のためのコールバックなのかは不明
  void* owner;                                                      // 0x4C, このHitboxの持ち主
} HitboxData;
static_assert(sizeof(HitboxData) == 80);

#endif  // __INCLUDE_HITBOX_H__
