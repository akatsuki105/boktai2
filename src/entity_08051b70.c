#include "entity.h"
#include "global.h"

typedef struct Entity08051b70 {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1228 - 0x18];
} Entity08051b70;
static_assert(sizeof(Entity08051b70) == 1228);

extern Entity08051b70* gEntity08051b70;  // 0x03000118

void FUN_08050f80(Entity08051b70*, unknown*, unknown*);
void FUN_08050fa0(Entity08051b70*, unknown*, unknown*);
void FUN_080510e0(Entity08051b70*, unknown*, unknown*);
void FUN_080511b0(Entity08051b70*, unknown*, unknown*);
void FUN_0805128c(Entity08051b70*, unknown*, unknown*);
void FUN_0805136c(Entity08051b70*, unknown*, unknown*);
void FUN_080514f0(Entity08051b70*, unknown*, unknown*);

void (*const PTR_ARRAY_085ab6d4[7])(Entity08051b70*, unknown*, unknown*) = {
    FUN_08050f80, FUN_08050fa0, FUN_080510e0, FUN_080511b0, FUN_0805128c, FUN_0805136c, FUN_080514f0,
};  // 0x085AB6D4

void FUN_08051640(Entity08051b70*);
void FUN_08051658(Entity08051b70*);
void FUN_0805169c(Entity08051b70*);
void FUN_08051710(Entity08051b70*);
void FUN_08051830(Entity08051b70*);
void FUN_08051898(Entity08051b70*);
void FUN_08051950(Entity08051b70*);

void (*const PTR_ARRAY_085ab6f0[7])(Entity08051b70*) = {
    FUN_08051640, FUN_08051658, FUN_0805169c, FUN_08051710, FUN_08051830, FUN_08051898, FUN_08051950,
};  // 0x085AB6F0

INCASM("asm/entity_08051b70.inc");
