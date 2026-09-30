#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[644 - 0x18];
} EntityB88C;
static_assert(sizeof(EntityB88C) == 644);

const u16 u16_ARRAY_085ab564[16] = {
    0x200, 0x100, 0x200, 0x100, 0x200, 0x200, 0x100, 0x100, 0x100, 0x100, 0x200, 0x200, 0x4, 0x8, 0x4, 0x8,
};  // 0x085AB564

void FUN_0804ac7c(EntityB88C* p);
void FUN_0804ad40(EntityB88C* p);
void FUN_0804add8(EntityB88C* p);
void FUN_0804aecc(EntityB88C* p);
void FUN_0804af38(EntityB88C* p);

void (*const PTR_ARRAY_085ab584[5])(EntityB88C*) = {
    FUN_0804ac7c, FUN_0804ad40, FUN_0804add8, FUN_0804aecc, FUN_0804af38,
};  // 0x085AB584

const u16 u16_ARRAY_085ab598[6] = {10, 8, 8, 8, 8, 8};  // 0x085AB598

const u16 u16_ARRAY_085ab5a4[6] = {31, 27, 18, 10, 18, 27};  // 0x085AB5A4

INCASM("asm/entity_b88c.inc");
