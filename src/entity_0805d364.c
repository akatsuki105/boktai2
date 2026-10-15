#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[5800 - 0x18];
} Entity0805d364;
static_assert(sizeof(Entity0805d364) == 5800);

void FUN_0805bd68(Entity0805d364*, unknown*, s32);
void FUN_0805be28(Entity0805d364*, unknown*, s32);
void FUN_0805bf60(Entity0805d364*, unknown*, s32);
void FUN_0805c330(Entity0805d364*, unknown*, s32);
void FUN_0805c4c4(Entity0805d364*, unknown*, s32);
void FUN_0805c644(Entity0805d364*, unknown*, s32);
void FUN_0805c9b4(Entity0805d364*, unknown*, s32);
void FUN_0805cb7c(Entity0805d364*, unknown*, s32);
void FUN_0805cd08(Entity0805d364*, unknown*, s32);
void FUN_0805ce28(Entity0805d364*, unknown*, s32);
void FUN_0805d0a0(Entity0805d364*, unknown*, s32);
void FUN_0805d0f0(Entity0805d364*, unknown*, s32);

// Entity0805d364_Update が引く
void (*const PTR_ARRAY_085aba2c[12])(Entity0805d364*, unknown*, s32) = {
    FUN_0805bd68,
    FUN_0805bf60,
    FUN_0805be28,
    FUN_0805c330,
    FUN_0805c4c4,
    FUN_0805c644,
    FUN_0805c9b4,
    FUN_0805cb7c,
    FUN_0805cd08,
    FUN_0805ce28,
    FUN_0805d0a0,
    FUN_0805d0f0,
};  // 0x085ABA2C

INCASM("asm/entity_0805d364.inc");
