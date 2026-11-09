#include "enemy.h"
#include "global.h"
#include "malloc.h"

// golem.c の通信対戦用版
// TODO: Golem とサイズが同じなので Golem と GolemLink が同じ構造体の可能性があるので検証する
typedef struct {
  Enemy e;
  u8 unk_654[1764 - sizeof(Enemy)];
} GolemLink;
static_assert(sizeof(GolemLink) == 1764);

const STRING_DATA char s_eneinline_08252288[] = "../golem/../system/eneinline.h";  // 0x08252288
const STRING_DATA char s_golemcom_c_082522a8[] = "../golem/golemcom.c";

const u16 u16_ARRAY_085adf98[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085ADF98

const u16 u16_ARRAY_085adfa8[2] = {0, 4};  // 0x085ADFA8

void FUN_081bdf44(GolemLink*);
void FUN_081be01c(GolemLink*);

void (*const PTR_ARRAY_085adfac[2])(GolemLink*) = {
    FUN_081bdf44,
    FUN_081be01c,
};  // 0x085ADFAC

void FUN_081be858(GolemLink*);
void FUN_081bec58(GolemLink*);
void FUN_081bfccc(GolemLink*);
void FUN_081bff24(GolemLink*);
void FUN_081c07e4(GolemLink*);
void FUN_081c0868(GolemLink*);
void FUN_081beb70(GolemLink*);
void FUN_081c0aa8(GolemLink*);
void FUN_081c0990(GolemLink*);
void FUN_081c1074(GolemLink*);

void (*const PTR_ARRAY_085adfb4[10])(GolemLink*) = {
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

void (*const PTR_ARRAY_085adfdc[15])(GolemLink*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f9c20,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f9e34,
    (void*)FUN_080f9ee0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    (void*)FUN_080f12c4,
};  // 0x085ADFDC

INCASM("asm/golem_link.inc");
