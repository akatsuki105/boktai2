#ifndef __INCLUDE_CAMERA_H__
#define __INCLUDE_CAMERA_H__

#include "entity.h"
#include "gba/gba.h"
#include "struct.h"
#include "types.h"

typedef struct {
  Entity e;            // 0x00, ENTITY_CAMERA
  u32 unk_18;          // 0x18, マップと対応する何かの値, サンミゲル(屋外や鍛冶屋内)や暗黒街: 0xD23E, n番街: 0x56CB
  u16 unk_1c;          // 0x1C
  u16 unk_1e;          // 0x1E
  UnkStruct52 unk_20;  // 0x20
  u8 unk_54[80];       // 0x54
} Camera;
static_assert(sizeof(Camera) == 164);

extern Camera* gCamera;  // 0x030047D0

void Camera_0823b744(void);

#endif  // __INCLUDE_CAMERA_H__
