#ifndef __INCLUDE_TRIG_H__
#define __INCLUDE_TRIG_H__

#include "gba/gba.h"

extern const s16 gSineTable[320];

s32 ArcTan2_8(s32 x, s32 y);

static inline s32 Trig_Fix12ToInt(s32 v) { return v >= 0 ? (v >> 12) : -((-v) >> 12); }

#define SIN(angle, amplitude) Trig_Fix12ToInt((amplitude) * gSineTable[(angle) & 0xFF])
#define COS(angle, amplitude) SIN((angle) + 0x40, amplitude)

#endif  // __INCLUDE_TRIG_H__
