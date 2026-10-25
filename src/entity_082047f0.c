#include "entity.h"
#include "global.h"

typedef struct Entity082047f0 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[204 - 0x18];
} Entity082047f0;
static_assert(sizeof(Entity082047f0) == 204);

s32 FUN_08203d40(Entity082047f0*, unknown*, s32);
s32 FUN_08203d44(Entity082047f0*, unknown*, s32);
s32 FUN_082040d0(Entity082047f0*, unknown*, s32);
s32 FUN_08204390(Entity082047f0*, unknown*, s32);

// Entity082047f0_Update が引数3つで呼んで戻り値を使う
s32 (*const PTR_ARRAY_085ae824[4])(Entity082047f0*, unknown*, s32) = {
    FUN_08203d40,
    FUN_08203d44,
    FUN_082040d0,
    FUN_08204390,
};  // 0x085AE824

INCASM("asm/entity_082047f0.inc");
