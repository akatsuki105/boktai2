#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"

typedef struct Entity08080be8 {
  Entity e;        // ENTITY_UNK_8
  Player* player;  // 0x18
  u8 unk_1c[0xCA - 0x1c];
  u16 unk_ca;  // 0xCA
  u8 unk_cc[0x194 - 0xCC];
  void (*updateCallback)(struct Entity08080be8*);  // 0x194
} Entity08080be8;
static_assert(sizeof(Entity08080be8) == 408);

NAKED void FUN_080801f4(Entity08080be8* p, void (*fn)(Entity08080be8*)) { INCFUNC("asm/func/FUN_080801f4.inc"); }

NAKED void FUN_08080204(Entity08080be8* p) { INCFUNC("asm/func/FUN_08080204.inc"); }

NAKED void FUN_080803b4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080803b4.inc"); }

NAKED void FUN_080804a0(Entity08080be8* p) { INCFUNC("asm/func/FUN_080804a0.inc"); }

NAKED void FUN_08080620(Entity08080be8* p) { INCFUNC("asm/func/FUN_08080620.inc"); }

NAKED void FUN_08080648(HitboxData* a, HitboxData* b, Entity08080be8* p) { INCFUNC("asm/func/FUN_08080648.inc"); }

NAKED void FUN_0808065c(Entity08080be8* p) { INCFUNC("asm/func/FUN_0808065c.inc"); }

NAKED u32 FUN_080806a4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080806a4.inc"); }

NAKED void FUN_080806ec(Entity08080be8* p) { INCFUNC("asm/func/FUN_080806ec.inc"); }

NAKED void FUN_080807f4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080807f4.inc"); }

NAKED void FUN_080808cc(Entity08080be8* p) { INCFUNC("asm/func/FUN_080808cc.inc"); }

NAKED void FUN_0808094c(Entity08080be8* p) { INCFUNC("asm/func/FUN_0808094c.inc"); }

NAKED s32 Entity08080be8_Update(Entity08080be8* p) { INCFUNC("asm/func/Entity08080be8_Update.inc"); }

NAKED s32 Entity08080be8_Destroy(Entity08080be8* p) { INCFUNC("asm/func/Entity08080be8_Destroy.inc"); }

NAKED void FUN_08080a10(Entity08080be8* p, s32 plttID) { INCFUNC("asm/func/FUN_08080a10.inc"); }

NAKED void FUN_08080a44(Entity08080be8* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08080a44.inc"); }

NAKED void FUN_08080af4(Entity08080be8* p, s32 val) { INCFUNC("asm/func/FUN_08080af4.inc"); }

NAKED s32 Entity08080be8_Init(Entity08080be8* p, Player* player, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10, u32 param_11, u32 param_12, u32 param_13) { INCFUNC("asm/func/Entity08080be8_Init.inc"); }

NAKED Entity08080be8* Entity08080be8_Create(Player* player, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10, u32 param_11, u32 param_12) { INCFUNC("asm/func/Entity08080be8_Create.inc"); }
