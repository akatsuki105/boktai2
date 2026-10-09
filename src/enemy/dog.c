#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_0814fba4(Enemy* p);
void FUN_0814fc7c(Enemy* p);
void FUN_08150534(Enemy* p);
void FUN_08150660(Enemy* p);
void FUN_08150790(Enemy* p);
void FUN_08150b18(Enemy* p);
void FUN_08150de8(Enemy* p);
void FUN_081514f0(Enemy* p);
void FUN_081516d8(Enemy* p);
void FUN_081517a8(Enemy* p);

void (*const PTR_ARRAY_085ad8e0[2])(Enemy*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Enemy*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

INCASM("asm/dog.inc");
