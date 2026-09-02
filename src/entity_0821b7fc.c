#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[0x6c - 0x18];
  u32 unk_6c;  // 0x6C
  u8 unk_70[508 - 0x70];
} Entity0821b7fc;
static_assert(sizeof(Entity0821b7fc) == 508);

INCASM("asm/entity_0821b7fc.inc");

NAKED Entity0821b7fc* Entity0821b7fc_Create(void* p) { INCFUNC("asm/func/Entity0821b7fc_Create.inc"); }

void FUN_0821b840(Entity0821b7fc* p) { KillEntity((void*)p); }

bool32 FUN_0821b84c(Entity0821b7fc* p) { return p->unk_6c == 4; }
