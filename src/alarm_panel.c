#include "entity.h"
#include "global.h"

// 太陽警報機
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[248 - 0x18];
} AlarmPanel;
static_assert(sizeof(AlarmPanel) == 248);

INCASM("asm/alarm_panel.inc");
