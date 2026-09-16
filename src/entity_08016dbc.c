#include "entity.h"
#include "global.h"

typedef struct Entity08016dbc {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[52 - 0x18];
} Entity08016dbc;
static_assert(sizeof(Entity08016dbc) == 52);

extern Entity08016dbc* gEntity08016dbc;  // 0x03000068

void FUN_08016c00(Entity08016dbc*);
void FUN_08016ca4(Entity08016dbc*);

void (*const PTR_ARRAY_085aa920[3])(Entity08016dbc*) = {
    NULL,
    FUN_08016c00,
    FUN_08016ca4,
};  // 0x085AA920

INCASM("asm/entity_08016dbc.inc");
