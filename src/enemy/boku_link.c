#include "enemy.h"
#include "global.h"
#include "malloc.h"

// ボク(boku.c) の通信対戦用版
// TODO: Boku とサイズが同じなので Boku と BokuLink が同じ構造体の可能性があるので検証する
typedef struct {
  Enemy e;
  u8 unk_654[1708 - sizeof(Enemy)];
} BokuLink;
static_assert(sizeof(BokuLink) == 1708);

const STRING_DATA char s_eneinline_08252254[] = "../boku/../system/eneinline.h";
const STRING_DATA char s_bokucom_c_08252274[] = "../boku/bokucom.c";

void FUN_081b1ec4(BokuLink*);
void FUN_081b1fb4(BokuLink*);

void (*const PTR_ARRAY_085adef4[2])(BokuLink*) = {
    FUN_081b1ec4,
    FUN_081b1fb4,
};  // 0x085ADEF4

void FUN_081b282c(BokuLink*);
void FUN_081b2a30(BokuLink*);
void FUN_081b2b2c(BokuLink*);

void (*const PTR_ARRAY_085adefc[18])(BokuLink*) = {
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
    (void*)FUN_080f12c4,
    FUN_081b282c,
    FUN_081b2a30,
    FUN_081b2b2c,
};  // 0x085ADEFC

void FUN_081b2c30(BokuLink*);

void (*const PTR_ARRAY_085adf44[1])(BokuLink*) = {
    FUN_081b2c30,
};  // 0x085ADF44

const u16 u16_ARRAY_085adf48[4] = {336, 336, 0, 180};  // 0x085ADF48

void FUN_081b3bec(BokuLink*);
void FUN_081b3dd4(BokuLink*);
void FUN_081b3ebc(BokuLink*);

void (*const PTR_ARRAY_085adf50[18])(BokuLink*) = {
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
    FUN_081b3bec,
    FUN_081b3dd4,
    FUN_081b3ebc,
};  // 0x085ADF50

INCASM("asm/boku_link.inc");
