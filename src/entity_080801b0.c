#include "entity.h"
#include "global.h"
#include "player.h"
#include "sprite.h"

typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_11
  Player* player;      // 0x18
  MainSpriteGfx gfx;   // 0x1C
  MainSprite sprites;  // 0x3C
  u8 unk_9c[1220 - 0x9C];
} Entity080801b0;
static_assert(sizeof(Entity080801b0) == 1220);

INCASM("asm/entity_080801b0.inc");

NAKED void LoadPlayerSprite_0807fe48(Entity080801b0* p) { INCFUNC("asm/func/LoadPlayerSprite_0807fe48.inc"); }

NAKED void FUN_0807fed0(Entity080801b0* p) { INCFUNC("asm/func/FUN_0807fed0.inc"); }

NAKED void FUN_0807ff78(Entity080801b0* p) { INCFUNC("asm/func/FUN_0807ff78.inc"); }

NAKED s32 FUN_08080148(Entity080801b0* p, Player* player) { INCFUNC("asm/func/FUN_08080148.inc"); }

NAKED Entity080801b0* FUN_080801b0(Player* player) { INCFUNC("asm/func/FUN_080801b0.inc"); }
