#ifndef __INCLUDE_FLAMETHROWER_H__
#define __INCLUDE_FLAMETHROWER_H__

#include "gba/gba.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite.h"
#include "types.h"

typedef struct Flamethrower {
  MainSprite sprite;  // 0x000, Entity081eaf6c_Destroy が要素そのものを MainSprite_Remove に渡す
  Mover unk_60;       // 0x060, flags の bit0 が立っていれば _Destroy が FUN_08002a58 に、その後 Mover_Unlink に渡す
  AuxSprite unk_a4;   // 0x0A4, unk_60 に Mover_SetAuxSprite で繋ぐ
  Vec3 hitboxPos;     // 0x0D0, Hitbox_SetPos に渡す位置
  HitboxData hitbox;  // 0x0D8, FUN_081eaa10 が unk_128 が 1 のときだけ登録する
  s16 unk_128;        // 0x128, 1 のときだけヒットボックスを登録する
  s16 unk_12a;        // 0x12A
  s16 unk_12c;        // 0x12C
  s16 unk_12e;        // 0x12E
  s16 unk_130;        // 0x130
  s16 unk_132;        // 0x132, _Update が s16 として読む
  u16 unk_134;        // 0x134, FUN_081eaa10 が毎フレーム +1 する
  u16 unk_136;        // 0x136, activeMask 上の自分のビット番号, 空きなら 0xFFFF, 読む側は s16 にして使う
  u16 flags;          // 0x138, bit0 が立っていると _Destroy が FUN_08002a58 を呼ぶ
  u8 unk_13a[2];      // 0x13A, padding?
} Flamethrower;
static_assert(sizeof(Flamethrower) == 316);

#endif  // __INCLUDE_FLAMETHROWER_H__
