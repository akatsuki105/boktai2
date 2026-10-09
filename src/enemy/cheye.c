#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_08180ad4(Enemy* p);
void FUN_081811b0(Enemy* p);
void FUN_08181a88(Enemy* p);
void FUN_08181c00(Enemy* p);
void FUN_08181d78(Enemy* p);
void FUN_08181f70(Enemy* p);
void FUN_08182410(Enemy* p);
void FUN_0818266c(Enemy* p);
void FUN_081829e8(Enemy* p);
void FUN_08182d1c(Enemy* p);
void FUN_08182de8(Enemy* p);
void FUN_08182e98(Enemy* p);
void FUN_08182fec(Enemy* p);
void FUN_081831c4(Enemy* p);
void FUN_0818327c(Enemy* p);

void (*const PTR_ARRAY_085adb8c[2])(Enemy*) = {
    FUN_08180ad4,
    FUN_081811b0,
};  // 0x085ADB8C

void (*const PTR_ARRAY_085adb94[4])(Enemy*) = {
    FUN_08181a88,
    FUN_08181c00,
    FUN_08181d78,
    FUN_08181f70,
};  // 0x085ADB94

// clang-format off
void (*const PTR_ARRAY_085adba4[22])(Enemy*) = {
    FUN_081829e8,
    NULL,
    FUN_0818266c,
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
    FUN_080f12c4,
    FUN_08182fec,
    FUN_081831c4,
    FUN_0818327c,
    FUN_08182d1c,
    FUN_08182e98,
    FUN_08182de8,
    FUN_08182410,
};  // 0x085ADBA4
// clang-format on

const Vec3 vec3_ARRAY_085adbfc[14] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {28,  250, 48 },
    {38,  0,   24 },
    {42,  250, 48 },
    {12,  0,   24 }
};  // 0x085ADBFC

INCASM("asm/cheye.inc");
