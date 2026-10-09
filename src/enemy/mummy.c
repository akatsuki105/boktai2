#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_08125d3c(Enemy* p);
void FUN_08125e1c(Enemy* p);
void FUN_081266f4(Enemy* p);
void FUN_08126780(Enemy* p);
void FUN_08126b34(Enemy* p);
void FUN_081272d0(Enemy* p);
void FUN_08127434(Enemy* p);
void FUN_08127524(Enemy* p);
void FUN_0812c038(Enemy* p);
void FUN_0812c7c0(Enemy* p);

void (*const PTR_ARRAY_085ad63c[2])(Enemy*) = {
    FUN_08125d3c,
    FUN_08125e1c,
};  // 0x085AD63C

// clang-format off
void (*const PTR_ARRAY_085ad644[19])(Enemy*) = {
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
    FUN_08126780,
    FUN_080f11d0,
    FUN_08126b34,
    FUN_081266f4,
    FUN_081272d0,
    FUN_08127434,
    FUN_08127524,
};  // 0x085AD644
// clang-format on

const u16 u16_ARRAY_085ad690[4] = {0, 120, 260, 200};  // 0x085AD690

const u8 u8_ARRAY_085ad698[4] = {0, 4, 8, 8};  // 0x085AD698

const s16 s16_ARRAY_085ad69c[12] = {-102, 102, 0, 0, 0, 0, 102, -102, -48, 48, 0, 0};  // 0x085AD69C

void (*const PTR_ARRAY_085ad6b4[2])(Enemy*) = {
    FUN_0812c038,
    FUN_0812c7c0,
};  // 0x085AD6B4

INCASM("asm/mummy.inc");
