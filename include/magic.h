#ifndef __INCLUDE_MAGIC_H__
#define __INCLUDE_MAGIC_H__

#include "gba/gba.h"
#include "types.h"

s32 GetMagicCategory(magic32_t id);
bool32 IsMagicUnlocked(magic32_t id);

#endif  // __INCLUDE_MAGIC_H__
