#ifndef __INCLUDE_INLINE_H__
#define __INCLUDE_INLINE_H__

#include "gba/gba.h"
#include "types.h"

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// この inline.h は global.h に include されることを前提としているため、 グローバル変数を参照する static inline 関数は絶対に定義してはいけない

// 固定小数の値を整数に変換するための関数
static inline s32 FixToInt(s32 fracBits, s32 fixedPointValS32) { return fixedPointValS32 >= 0 ? (fixedPointValS32 >> fracBits) : -((-fixedPointValS32) >> fracBits); }

// xz 平面上の差分 (dx, dz) から距離の 2 乗を求める
static inline u32 DistSq(s32 dx, s32 dz) { return dx * dx + dz * dz; }

// global.h の FixToInt(12, v) と同等 (global.h を include したくなかったので別途定義しただけ)
#define Trig_Fix12ToInt(v) FixToInt(12, (v))

// 角度 (0〜255) を 8 方向のインデックスに変換する (FUN_08237834 と全く同じ)
static inline u16 Angle_ToDir8(u16 angle) { return ((((angle + 0x10) & 0xFF) >> 5) + 3) & 7; }

// 角度 (0〜255) を 4 方向のインデックスに変換する (FUN_08237848 と全く同じ)
static inline u16 Angle_ToDir4(u16 angle) { return ((((angle + 0x20) & 0xFF) >> 6) + 1) & 3; }

// Angle_ToDir4 の逆, 4 方向のインデックスをその方向の角度に戻す
static inline u8 Angle_FromDir4(u32 dir) { return dir * 64 - 64; }

// Angle_ToDir8 の逆, 8 方向のインデックスをその方向の角度に戻す
static inline u8 Angle_FromDir8(u32 dir) { return (dir + 5) * 32; }

// ワールド座標をアイソメトリック投影して視点座標にする
static inline void WorldToVp(Vec3* vp, WorldPos* world) {
  s32 hx = world->x >> 1;
  s32 hz = world->z >> 1;
  s32 a, b;

  vp->x = FixToInt(8, (hx - hz) * 48);
  a = FixToInt(8, (hx + hz) * 48);
  b = FixToInt(8, world->y * 24);
  vp->y = a - b;
  vp->z = a + b;
}

#endif  // __INCLUDE_INLINE_H__
