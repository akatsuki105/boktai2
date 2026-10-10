#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[3504 - 0x18];
} Entity08056728;
static_assert(sizeof(Entity08056728) == 3504);

IWRAM_DATA Entity08056728* gEntity08056728 = NULL;  // 0x03000128

void FUN_08055fe4(Entity08056728*, unknown*, s32);
void FUN_080561b8(Entity08056728*, unknown*, s32);
void FUN_080563b0(Entity08056728*, unknown*, s32);

const u16 u16_ARRAY_085ab990[4] = {4, 1, 2, 4};  // 0x085AB990

void (*const PTR_ARRAY_085ab998[3])(Entity08056728*, unknown*, s32) = {
    FUN_08055fe4,
    FUN_080561b8,
    FUN_080563b0,
};  // 0x085AB998

INCASM("asm/entity_08056728.inc");
