#ifndef __INCLUDE_TRIG_H__
#define __INCLUDE_TRIG_H__

#include "gba/gba.h"

// これを直書きせずに SIN / COS か POLAR_X / POLAR_Z を使うこと
extern const s4_12 gSineTable[320];

s32 ArcTan2_8(s32 x, s32 y);

// xz 平面上の差分 (dx, dz) から距離の 2 乗を求める
static inline u32 DistSq(s32 dx, s32 dz) { return dx * dx + dz * dz; }

// global.h の FixToInt(12, v) と同等 (global.h を include したくなかったので別途定義しただけ)
static inline s32 Trig_Fix12ToInt(s32 v) { return v >= 0 ? (v >> 12) : -((-v) >> 12); }

// 角度 (0〜255) を 8 方向のインデックスに変換する
static inline u16 Angle_ToDir8(u16 angle) { return ((((angle + 0x10) & 0xFF) >> 5) + 3) & 7; }

// 角度 (0〜255) を 4 方向のインデックスに変換する
static inline u16 Angle_ToDir4(u16 angle) { return ((((angle + 0x20) & 0xFF) >> 6) + 1) & 3; }

// Angle_ToDir4 の逆, 4 方向のインデックスをその方向の角度に戻す
static inline u8 Angle_FromDir4(u32 dir) { return dir * 64 - 64; }

// Angle_ToDir8 の逆, 8 方向のインデックスをその方向の角度に戻す
static inline u8 Angle_FromDir8(u32 dir) { return (dir + 5) * 32; }

#define SIN(angle) gSineTable[(angle) & 0xFF]
#define COS(angle) SIN((angle) + 0x40)

// 半径 radius と角度 angle (256 で一周) から xz 平面上の z / x 成分を求める, 端数は 0 方向に丸める
#define POLAR_Z(radius, angle) Trig_Fix12ToInt((radius) * SIN(angle))
#define POLAR_X(radius, angle) Trig_Fix12ToInt((radius) * COS(angle))

#endif  // __INCLUDE_TRIG_H__
