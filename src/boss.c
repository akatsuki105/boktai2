#include "global.h"

// Boss の共通処理? (まだ調査不足)

IWRAM_DATA void* gBossList[8] = {};  // 0x030000A0, idx is BossID

INCASM("asm/boss.inc");
