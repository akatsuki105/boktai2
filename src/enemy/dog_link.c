#include "enemy.h"
#include "global.h"
#include "malloc.h"

// doc.c の通信対戦用版

void FUN_081ca7f4(Enemy* p);
void FUN_081ca8cc(Enemy* p);
void FUN_081cb148(Enemy* p);
void FUN_081cb274(Enemy* p);
void FUN_081cb400(Enemy* p);
void FUN_081cb7e8(Enemy* p);
void FUN_081cbaa8(Enemy* p);
void FUN_081cc1a4(Enemy* p);
void FUN_081cc380(Enemy* p);
void FUN_081cc444(Enemy* p);

const u16 u16_ARRAY_085ae018[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AE018

void (*const PTR_ARRAY_085ae038[2])(Enemy*) = {
    FUN_081ca7f4,
    FUN_081ca8cc,
};  // 0x085AE038

void (*const PTR_ARRAY_085ae040[2])(Enemy*) = {
    FUN_081cb148,
    FUN_081cb274,
};  // 0x085AE040

// clang-format off
void (*const PTR_ARRAY_085ae048[20])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f9c20,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f9e34,
    FUN_080f9ee0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_081cbaa8,
    FUN_081cb400,
    FUN_081cb7e8,
    FUN_081cc1a4,
    FUN_081cc380,
    FUN_081cc444,
};  // 0x085AE048
// clang-format on

INCASM("asm/dog_link.inc");
