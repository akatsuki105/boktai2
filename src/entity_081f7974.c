#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1212 - 0x18];
} Entity081f7974;
static_assert(sizeof(Entity081f7974) == 1212);

static Entity081f7974* gEntity081f7974;  // 0x03000200

void FUN_081f74f0(Entity081f7974*, unknown*);
void FUN_081f74f4(Entity081f7974*, unknown*);
void FUN_081f75f0(Entity081f7974*, unknown*);
void FUN_081f7624(Entity081f7974*, unknown*);

void (*const PTR_ARRAY_085ae5a4[4])(Entity081f7974*, unknown*) = {
    FUN_081f74f0,
    FUN_081f74f4,
    FUN_081f75f0,
    FUN_081f7624,
};  // 0x085AE5A4

INCASM("asm/entity_081f7974.inc");
