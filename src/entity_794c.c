#include "entity.h"
#include "global.h"

typedef struct {
  u16 unk_0;  // 0x00
  u8 unk_2[2];
  u16 unk_4;  // 0x04
  u8 unk_6[16 - 0x06];
} Entity794CData;
static_assert(sizeof(Entity794CData) == 16);

typedef struct {
  Entity e;  // ENTITY_UNK_5
  u8 unk_18[0x20 - 0x18];
  Entity794CData data[8];  // 0x20, FUN_08240b44
  u8 unk_a0[216 - 0xa0];
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

IWRAM_DATA Entity794C* gEntity794C = NULL;  // 0x03001700

NAKED bool32 FUN_08240ad4(s32 a1, s32 a2, s32 a3, s32 b1, s32 b2, s32 b3) { INCFUNC("asm/func/FUN_08240ad4.inc"); }

INCASM("asm/entity_794c.inc");

NAKED void FUN_08240f4c(void) { INCFUNC("asm/func/FUN_08240f4c.inc"); }

NAKED void FUN_08240f94(void) { INCFUNC("asm/func/FUN_08240f94.inc"); }

NAKED void FUN_08240fdc(void) { INCFUNC("asm/func/FUN_08240fdc.inc"); }

void FUN_08241000(void) { gEntity794C = NULL; }
