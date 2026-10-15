#include "entity.h"
#include "global.h"

// 不使用?
typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[468 - 0x18];
} Entity081edcc4;
static_assert(sizeof(Entity081edcc4) == 468);

static Entity081edcc4* gEntity081edcc4;  // 0x030001C8

void FUN_081ed6d8(Entity081edcc4*, unknown*);
void FUN_081ed6dc(Entity081edcc4*, unknown*);
void FUN_081eda54(Entity081edcc4*, unknown*);

void (*const PTR_ARRAY_085ae4bc[3])(Entity081edcc4*, unknown*) = {
    FUN_081ed6d8,
    FUN_081ed6dc,
    FUN_081eda54,
};  // 0x085AE4BC

INCASM("asm/entity_081edcc4.inc");
