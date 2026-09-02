#ifndef GUARD_ZOKTAI_TYPES_H
#define GUARD_ZOKTAI_TYPES_H

#include "gba/types.h"

// include/constants/item.h
typedef s16 item16_t;
typedef s32 item32_t;

// include/constants/armor.h
typedef s16 armor16_t;
typedef s32 armor32_t;

// include/constants/coffin.h
typedef u8 coffin8_t;
typedef s16 coffin16_t;

typedef u16 SoundID16;
typedef u32 SoundID32;

// include/constants/weapon.h
typedef u8 weapon8_t;
typedef s32 weapon32_t;

// include/constants/magic.h
typedef s8 magic8_t;
typedef s16 magic16_t;
typedef s32 magic32_t;

typedef s16 slot16_t;
typedef s32 slot32_t;

typedef void unknown;  // まだ型が不明なときは unknown* で一応 void* と区別しておく

typedef s32 Sunlevel;  // 0..10, (digital) sunlight level

typedef struct {
  s8_8 x;
  s8_8 y;  // 高さ
  s8_8 z;
  u16 val;  // 用途不明だが、FUN_0823b400 で 0x10 がセットされている, gStat.playerPos の場合はプレイヤーの移動方向に応じて 01 とか 02 とか 05 とかがセットされた
} Vec3;

#endif  // GUARD_ZOKTAI_TYPES_H
