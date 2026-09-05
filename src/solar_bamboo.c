#include "entity.h"
#include "global.h"

// Entity95A8_Init で太陽ダケのスプライトをロードしているので太陽ダケのEntityだと思われる
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[276 - 0x18];
} SolarBamboo;
static_assert(sizeof(SolarBamboo) == 276);

INCASM("asm/solar_bamboo.inc");
