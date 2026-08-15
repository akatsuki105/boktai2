#ifndef __INCLUDE_CAMERA_H__
#define __INCLUDE_CAMERA_H__

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

typedef struct {
  ENTITY;          // 0x00
  u8 buffer[140];  // 0x18
} Camera;
static_assert(sizeof(Camera) == 164);

extern Camera* gCamera;  // 0x030047D0

void Camera_0823b744(void);

#endif  // __INCLUDE_CAMERA_H__
