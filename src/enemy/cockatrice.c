#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_081574b4(Enemy* p);
void FUN_0815758c(Enemy* p);
void FUN_08157df4(Enemy* p);
void FUN_08158180(Enemy* p);
void FUN_08158314(Enemy* p);
void FUN_0815849c(Enemy* p);
void FUN_081585bc(Enemy* p);
void FUN_08158784(Enemy* p);
void FUN_08158914(Enemy* p);
void FUN_081589f0(Enemy* p);
void FUN_08158a08(Enemy* p);
void FUN_08158a20(Enemy* p);
void FUN_08158d90(Enemy* p);
void FUN_08158e8c(Enemy* p);
void FUN_08159594(Enemy* p);

void (*const PTR_ARRAY_085ad940[3])(Enemy*) = {
    FUN_081574b4,
    FUN_0815758c,
    FUN_08157df4,
};  // 0x085AD940

// clang-format off
void (*const PTR_ARRAY_085ad94c[21])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_08159594,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_08158a20,
    FUN_08158d90,
    FUN_08158e8c,
    FUN_0815849c,
    FUN_081585bc,
    FUN_08158180,
    FUN_08158314,
    FUN_08158784,
    FUN_08158914,
};  // 0x085AD94C
// clang-format on

void (*const PTR_ARRAY_085ad9a0[2])(Enemy*) = {
    FUN_081589f0,
    FUN_08158a08,
};  // 0x085AD9A0

const u16 u16_ARRAY_085ad9a8[14] = {512, 256, 384, 408, 674, 674, 0, 578, 642, 674, 674, 0, 578, 642};  // 0x085AD9A8

INCASM("asm/cockatrice.inc");
