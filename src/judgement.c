#include "entity.h"
#include "global.h"

// "審判のカード" (ITEM_JUDGEMENT, 全回復して復活) の 効果処理 及び 演出
typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[632 - 0x18];
} Judgement;
static_assert(sizeof(Judgement) == 632);

INCASM("asm/judgement.inc");
