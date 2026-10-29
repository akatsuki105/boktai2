#ifndef __INCLUDE_TRIG_H__
#define __INCLUDE_TRIG_H__

#include "gba/gba.h"
#include "inline.h"

// これを直書きせずに SIN / COS か POLAR_X / POLAR_Z を使うこと
extern const s4_12 gSineTable[320];

s32 ArcTan2_8(s32 x, s32 y);

// 2つの角度 (256 で1周) の差を 0..255 で返す
static inline s32 Angle_Diff(s32 a, s32 b) { return (a - b) & 0xFF; }

#define SIN(angle) gSineTable[(angle) & 0xFF]
#define COS(angle) SIN((angle) + 0x40)

// 半径 radius と角度 angle (256 で一周) から xz 平面上の z / x 成分を求める, 端数は 0 方向に丸める
#define POLAR_Z(radius, angle) FixToInt(12, (radius) * SIN(angle))
#define POLAR_X(radius, angle) FixToInt(12, (radius) * COS(angle))

#endif  // __INCLUDE_TRIG_H__
