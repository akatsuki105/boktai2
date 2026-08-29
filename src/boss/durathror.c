#include "global.h"

// カワイイ
typedef struct Durathror {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[3620 - 0x18];
} Durathror;
static_assert(sizeof(Durathror) == 3620);

INCASM("asm/durathror.inc");
