#include "enemy.h"
#include "global.h"
#include "malloc.h"

// golem.c の通信対戦用版

void FUN_081bdf44(Enemy* p);
void FUN_081be01c(Enemy* p);
void FUN_081be858(Enemy* p);
void FUN_081beb70(Enemy* p);
void FUN_081bec58(Enemy* p);
void FUN_081bfccc(Enemy* p);
void FUN_081bff24(Enemy* p);
void FUN_081c07e4(Enemy* p);
void FUN_081c0868(Enemy* p);
void FUN_081c0990(Enemy* p);
void FUN_081c0aa8(Enemy* p);
void FUN_081c1074(Enemy* p);

const u16 u16_ARRAY_085adf98[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085ADF98

const u16 u16_ARRAY_085adfa8[2] = {0, 4};  // 0x085ADFA8

void (*const PTR_ARRAY_085adfac[2])(Enemy*) = {
    FUN_081bdf44,
    FUN_081be01c,
};  // 0x085ADFAC

void (*const PTR_ARRAY_085adfb4[10])(Enemy*) = {
    FUN_081be858,
    FUN_081bec58,
    FUN_081bfccc,
    FUN_081bff24,
    FUN_081c07e4,
    FUN_081c0868,
    FUN_081beb70,
    FUN_081c0aa8,
    FUN_081c0990,
    FUN_081c1074,
};  // 0x085ADFB4

void (*const PTR_ARRAY_085adfdc[15])(Enemy*) = {
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
};  // 0x085ADFDC

INCASM("asm/golem_link.inc");
