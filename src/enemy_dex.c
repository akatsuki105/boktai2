#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[4704 - sizeof(Entity)];
} EnemyDexMenu;
static_assert(sizeof(EnemyDexMenu) == 4704);

INCASM("asm/enemy_dex.inc");
