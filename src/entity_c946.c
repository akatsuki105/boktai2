#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[884 - sizeof(Entity)];
} EntityC946;
static_assert(sizeof(EntityC946) == 884);

INCASM("asm/entity_c946.inc");

NAKED void EntityC946_Update_Helper_0820fb20(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update_Helper_0820fb20.inc"); }

NAKED s32 EntityC946_Update(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update.inc"); }

NAKED s32 EntityC946_Destroy(EntityC946* p) { INCFUNC("asm/func/EntityC946_Destroy.inc"); }

NAKED s32 EntityC946_Init(EntityC946* p, void* _) { INCFUNC("asm/func/EntityC946_Init.inc"); }

NAKED EntityC946* EntityC946_Create(void* _) { INCFUNC("asm/func/EntityC946_Create.inc"); }

INCBIN(".rodata", "data/entity_c946.bin");  // ./tmp/bin.sh ./baserom.gba 0x085af0ec 0x085af9ac ./data/entity_c946.bin
