#ifndef __INCLUDE_BOSS_H__
#define __INCLUDE_BOSS_H__

#include "gba/gba.h"

typedef s32 BossID;  // see include/constants/miscs.h

// 各Bossの構造体の最初の方は共通部分っぽい？ (もしそうなら、 ENEMY_HDR のように BOSS_HDR を定義するか, struct Boss を作る予定)

void* FUN_08022a2c(BossID id);

#endif  // __INCLUDE_BOSS_H__
