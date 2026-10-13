#include "entity.h"
#include "global.h"

// 太陽結界(この上に置いたイモータルが入った棺桶は逃げ出さない)
typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[616 - 0x18];
} SolarCircle;
static_assert(sizeof(SolarCircle) == 616);

INCASM("asm/solar_circle.inc");
