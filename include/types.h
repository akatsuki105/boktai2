#ifndef __INCLUDE_BOKTAI2_TYPES_H__
#define __INCLUDE_BOKTAI2_TYPES_H__

#include "gba/types.h"

// include/constants/item.h
typedef s16 item16_t;
typedef s32 item32_t;

// see "include/constants/item.h", item/weapon/armor を区別するものなので、 item.h にあるのは適切ではないけど、ここに置いておく
typedef s16 ItemCategory16;
typedef s32 ItemCategory32;

// include/constants/armor.h
typedef s16 armor16_t;
typedef s32 armor32_t;

// include/constants/coffin.h
typedef u8 coffin8_t;
typedef s16 coffin16_t;

// include/constants/songs.h
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

// このゲームでは、返り値の型が void でないのに、 何も return しない関数がそこそこある
// どれも返り値を使わない関数なので、関数の返り値の型を void にし忘れているだけだと思われる
// それらをわかりやすく明示するために missing 型を用意
typedef u32 missing;

typedef struct {
  s16 x;
  s16 y;  // 高さ
  s16 z;
  s16 val;  // 用途不明だが、Mover_Init で 16 がセットされている
} Vec3;

// ワールド座標, isometric, Y-up, right-handed coordinate system (X: 画面右下, Y: 高さ, Z: 画面左下)
// 1ブロック = 256, ブロック: このゲームの地形の単位ユニット, 木箱の大きさと同じ
// 例：
//   x と z は サンミゲルの太陽樹のところあたりのグリッドがわかりやすい, 右下に1グリッド進むと x が 256 増える, 左下に1グリッド進むと z が 256 増える
//   階段を1つ登ると y が 256 増える
typedef Vec3 WorldPos;

// Boktai2 で ROM から RAM に読み込んで使うデータの中には、ROM内では親構造体からのオフセットでRAM読み込み時にポインタに変換されるものが多い
typedef union {
  void* ptr;
  u32 offset;
} AssetRef;

#endif  // __INCLUDE_BOKTAI2_TYPES_H__
