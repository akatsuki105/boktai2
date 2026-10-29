#ifndef __INCLUDE_SPIRIT_BUGS_H__
#define __INCLUDE_SPIRIT_BUGS_H__

#include "gba/gba.h"
#include "types.h"

// 精霊虫

typedef enum {
  SOLARBUG = 0,  // 太陽虫 (Ene回復)
  MOONBUG = 1,   // 月光虫 (HP回復)
  DARKBUG = 2,   // 暗黒虫 (Eneが減る)
} SpiritBugKind;

s32 SpawnSpiritBugs(u32 count, s32 kind, s32 amount, Vec3* pos, Vec3* spread, s32 lifetime, s32 lifetimeRand);
s32 SpawnSpiritBugsAt(u32 count, s32 kind, s32 amount, Vec3* pos, Vec3* perBugPos, s32 lifetime, s32 lifetimeRand);

#endif  // __INCLUDE_SPIRIT_BUGS_H__
