#include "entity.h"
#include "global.h"

// 通信関連?
typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[2280 - 0x18];
} Entity723E;
static_assert(sizeof(Entity723E) == 2280);

IWRAM_DATA Entity723E* gEntity723E = NULL;  // 0x0300011C

void FUN_08052338(Entity723E*);
void FUN_0805234c(Entity723E*);
void FUN_080525d0(Entity723E*);
void FUN_080526d8(Entity723E*);
void FUN_08052798(Entity723E*);
void FUN_080528c4(Entity723E*);

void (*const PTR_ARRAY_085ab724[6])(Entity723E*) = {
    FUN_08052338,
    FUN_0805234c,
    FUN_080525d0,
    FUN_080526d8,
    FUN_08052798,
    FUN_080528c4,
};  // 0x085AB724

INCASM("asm/entity_723e.inc");
