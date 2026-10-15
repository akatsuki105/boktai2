#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[700 - 0x18];
} Entity081e8d0c;
static_assert(sizeof(Entity081e8d0c) == 700);

const u8 u8_ARRAY_085ae44c[4] = {8, 4, 2, 1};  // 0x085AE44C, FUN_081e8664 が Mod の除数として引く

void FUN_081e8660(Entity081e8d0c*, unknown*);
void FUN_081e86ec(Entity081e8d0c*, unknown*);
void FUN_081e8710(Entity081e8d0c*, unknown*);

// Entity081e8d0c_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae450[3])(Entity081e8d0c*, unknown*) = {
    FUN_081e8660,
    FUN_081e8710,
    FUN_081e86ec,
};  // 0x085AE450

INCASM("asm/entity_081e8d0c.inc");
