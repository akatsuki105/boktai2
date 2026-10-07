#ifndef __INCLUDE_SPRITE_PLTT_H__
#define __INCLUDE_SPRITE_PLTT_H__

#include "gba/gba.h"
#include "types.h"

// SpritePltt, OBJPltt, OBP
typedef struct {
  u16 length;      // 0x00, 16色パレットの個数
  u16 unk_02;      // 0x02, ???
  rgb555 body[0];  // 0x04, rgb555[length*16]
} ObjPlttFile;

extern rgb555* gObjPlttData;
s32 AllocParticlePlttSlot(u32 plttID, rgb555* pltt);

#endif  // __INCLUDE_SPRITE_PLTT_H__
