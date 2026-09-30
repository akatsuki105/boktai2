#include "entity.h"
#include "global.h"

typedef struct Entity0805fe30 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[752 - 0x18];
} Entity0805fe30;
static_assert(sizeof(Entity0805fe30) == 752);

extern Entity0805fe30* gEntity0805fe30;  // 0x03000130

const s32 s32_ARRAY_085aba88[5] = {0, 0, -3, -6, -9};  // 0x085ABA88

void FUN_0805fb20(unknown*, unknown*, s32);
void FUN_0805fc38(unknown*, unknown*, s32);

void (*const PTR_ARRAY_085aba9c[2])(unknown*, unknown*, s32) = {
    FUN_0805fb20,
    FUN_0805fc38,
};  // 0x085ABA9C

INCASM("asm/entity_0805fe30.inc");
