#ifndef __INCLUDE_VEC3_H__
#define __INCLUDE_VEC3_H__

#include "gba/gba.h"
#include "trig.h"
#include "types.h"

// dst に src を足し込む
static inline void Vec3_Add(Vec3* dst, Vec3* src) {
  dst->x += src->x;
  dst->y += src->y;
  dst->z += src->z;
}

// dst = a + b
static inline void Vec3_Sum(Vec3* dst, Vec3* a, Vec3* b) {
  dst->x = a->x + b->x;
  dst->y = a->y + b->y;
  dst->z = a->z + b->z;
}

// src を dst に写して y だけ dy ずらす
static inline void Vec3_CopyOffsetY(Vec3* dst, Vec3* src, s32 dy) {
  *dst = *src;
  dst->y += dy;
}

// xz 平面上で原点から angle の向きに radius だけ離れた位置を v に入れる
static inline void Vec3_SetPolar(Vec3* v, u32 angle, s32 radius) {
  v->x = POLAR_X(radius, angle);
  v->y = 0;
  v->z = POLAR_Z(radius, angle);
}

#endif  // __INCLUDE_VEC3_H__
