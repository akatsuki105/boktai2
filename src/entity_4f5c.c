#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[480 - 0x18];
} Entity4F5C;
static_assert(sizeof(Entity4F5C) == 480);

INCASM("asm/entity_4f5c.inc");

const u16 u16_ARRAY_085aa970[2] = {3, 3};  // 0x085AA970

void FUN_0801a170(unknown*, unknown*);
void FUN_0801a174(unknown*, unknown*);
void FUN_0801a3c8(unknown*, unknown*);

void (*const PTR_ARRAY_085aa974[3])(unknown*, unknown*) = {
    FUN_0801a170,
    FUN_0801a174,
    FUN_0801a3c8,
};  // 0x085AA974

const u16 u16_ARRAY_085aa980[3] = {0x0, 0x80, 0x258};  // 0x085AA980

static const u16 padding_085aa986 = 0;  // 後で消す
