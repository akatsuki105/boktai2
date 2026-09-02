#include "entity.h"
#include "global.h"

// 魔法"フリーズ"で生成される氷のエフェクト
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[524 - 0x18];
} FreezeEffect;
static_assert(sizeof(FreezeEffect) == 524);

INCASM("asm/freeze_effect.inc");
