#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1308 - 0x18];
} Entity081f9cb8;
static_assert(sizeof(Entity081f9cb8) == 1308);

static Entity081f9cb8* gEntity081f9cb8;  // 0x03000210

void FUN_081f9924(Entity081f9cb8*, unknown*);
void FUN_081f9928(Entity081f9cb8*, unknown*);
void FUN_081f9980(Entity081f9cb8*, unknown*);
void FUN_081f9adc(Entity081f9cb8*, unknown*);

void (*const PTR_ARRAY_085ae5e0[4])(Entity081f9cb8*, unknown*) = {
    FUN_081f9924,
    FUN_081f9928,
    FUN_081f9980,
    FUN_081f9adc,
};  // 0x085AE5E0

INCASM("asm/entity_081f9cb8.inc");
