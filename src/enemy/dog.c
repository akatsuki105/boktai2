#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  Enemy e;
  u8 unk_654[1808 - sizeof(Enemy)];
} Dog;
static_assert(sizeof(Dog) == 1808);

const u16 u16_ARRAY_085ad8c0[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AD8C0

void FUN_0814fba4(Dog*);
void FUN_0814fc7c(Dog*);
void FUN_08150534(Dog*);
void FUN_08150660(Dog*);
void FUN_08150790(Dog*);
void FUN_08150b18(Dog*);
void FUN_08150de8(Dog*);
void FUN_081514f0(Dog*);
void FUN_081516d8(Dog*);
void FUN_081517a8(Dog*);

void (*const PTR_ARRAY_085ad8e0[2])(Dog*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Dog*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Dog*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

INCASM("asm/dog.inc");
