#include "enemy.h"
#include "global.h"
#include "malloc.h"

// ボク(boku.c) の通信対戦用版

void FUN_081b1ec4(Enemy* p);
void FUN_081b1fb4(Enemy* p);
void FUN_081b282c(Enemy* p);
void FUN_081b2a30(Enemy* p);
void FUN_081b2b2c(Enemy* p);
void FUN_081b2c30(Enemy* p);
void FUN_081b3bec(Enemy* p);
void FUN_081b3dd4(Enemy* p);
void FUN_081b3ebc(Enemy* p);

void (*const PTR_ARRAY_085adef4[2])(Enemy*) = {
    FUN_081b1ec4,
    FUN_081b1fb4,
};  // 0x085ADEF4

void (*const PTR_ARRAY_085adefc[18])(Enemy*) = {
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
    FUN_080f12c4,
    FUN_081b282c,
    FUN_081b2a30,
    FUN_081b2b2c,
};  // 0x085ADEFC

void (*const PTR_ARRAY_085adf44[1])(Enemy*) = {
    FUN_081b2c30,
};  // 0x085ADF44

const u16 u16_ARRAY_085adf48[4] = {336, 336, 0, 180};  // 0x085ADF48

void (*const PTR_ARRAY_085adf50[18])(Enemy*) = {
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
    FUN_080f12c4,
    FUN_081b3bec,
    FUN_081b3dd4,
    FUN_081b3ebc,
};  // 0x085ADF50

INCASM("asm/boku_link.inc");
