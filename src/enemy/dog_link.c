#include "enemy.h"
#include "global.h"
#include "malloc.h"

// doc.c の通信対戦用版
// TODO: Dog とサイズが同じなので Dog と DogLink が同じ構造体の可能性があるので検証する
typedef struct {
  Enemy e;
  u8 unk_654[1808 - sizeof(Enemy)];
} DogLink;
static_assert(sizeof(DogLink) == 1808);

const STRING_DATA char s_eneinline_082522bc[] = "../dog/../system/eneinline.h";
const STRING_DATA char s_dogcom_c_082522dc[] = "../dog/dogcom.c";
const STRING_DATA char s_eneinline_082522ec[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252308[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252324[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252340[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825235c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252378[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252394[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082523b0[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082523cc[] = "../enemy/system/eneinline.h";

const u16 u16_ARRAY_085ae018[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AE018

void FUN_081ca7f4(DogLink*);
void FUN_081ca8cc(DogLink*);

void (*const PTR_ARRAY_085ae038[2])(DogLink*) = {
    FUN_081ca7f4,
    FUN_081ca8cc,
};  // 0x085AE038

void FUN_081cb148(DogLink*);
void FUN_081cb274(DogLink*);

void (*const PTR_ARRAY_085ae040[2])(DogLink*) = {
    FUN_081cb148,
    FUN_081cb274,
};  // 0x085AE040

void FUN_081cbaa8(DogLink*);
void FUN_081cb400(DogLink*);
void FUN_081cb7e8(DogLink*);
void FUN_081cc1a4(DogLink*);
void FUN_081cc380(DogLink*);
void FUN_081cc444(DogLink*);

// clang-format off
void (*const PTR_ARRAY_085ae048[20])(DogLink*) = {
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
    FUN_081cbaa8,
    FUN_081cb400,
    FUN_081cb7e8,
    FUN_081cc1a4,
    FUN_081cc380,
    FUN_081cc444,
};  // 0x085AE048
// clang-format on

INCASM("asm/dog_link.inc");
