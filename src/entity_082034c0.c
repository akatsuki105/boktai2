#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2144 - 0x18];
} Entity082034c0;
static_assert(sizeof(Entity082034c0) == 2144);

static Entity082034c0* gEntity082034c0;  // 0x03000218

void FUN_08203034(unknown*, unknown*);
void FUN_082032a0(unknown*, unknown*);
void FUN_082032dc(unknown*, unknown*);

// Entity082034c0_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae818[3])(unknown*, unknown*) = {
    FUN_08203034,
    FUN_082032a0,
    FUN_082032dc,
};  // 0x085AE818

INCASM("asm/entity_082034c0.inc");
