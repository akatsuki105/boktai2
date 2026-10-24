#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

// 魔法"ヒーリング" で足場にすることができる ハスの葉(SPRITE_LILYPAD) or 太陽の根(SPRITE_SOLAR_PLANT)
// 他の Entity と _Create, _Init, _Update, _Delete の書き方が異なる
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2236 - 0x18];
} Entity1E98;
static_assert(sizeof(Entity1E98) == 2236);

COMMON_DATA Entity1E98* gEntity1E98 = NULL;  // 0x03002C44

INCASM("asm/solar_plant.inc");
