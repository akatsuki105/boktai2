#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[636 - 0x18];
} Entity081ea120;
static_assert(sizeof(Entity081ea120) == 636);

static Entity081ea120* gEntity081ea120;  // 0x030001B8

void FUN_081e9dc4(Entity081ea120*, unknown*);
void FUN_081e9dc8(Entity081ea120*, unknown*);
void FUN_081e9ee8(Entity081ea120*, unknown*);

// Entity081ea120_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae45c[3])(Entity081ea120*, unknown*) = {
    FUN_081e9dc4,
    FUN_081e9dc8,
    FUN_081e9ee8,
};  // 0x085AE45C

const u8 u8_ARRAY_085ae468[4] = {8, 4, 2, 1};  // 0x085AE468, FUN_081ea44c が Mod の除数として引く

INCASM("asm/entity_081ea120.inc");
