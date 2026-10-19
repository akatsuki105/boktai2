#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1152 - 0x18];
} Entity08204cb8;
static_assert(sizeof(Entity08204cb8) == 1152);

static Entity08204cb8* gEntity08204cb8;  // 0x03000220

void FUN_0820492c(Entity08204cb8*, unknown*);
void FUN_08204a64(Entity08204cb8*, unknown*);

// Entity08204cb8_Update が (p, elem) で呼ぶ
void (*const PTR_ARRAY_085ae834[2])(Entity08204cb8*, unknown*) = {
    FUN_0820492c,
    FUN_08204a64,
};  // 0x085AE834

INCASM("asm/entity_08204cb8.inc");
