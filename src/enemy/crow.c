#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  Enemy e;
  u8 unk_654[1728 - sizeof(Enemy)];
} Crow;
static_assert(sizeof(Crow) == 1728);

void FUN_081436b4(Crow*);
void FUN_081439d8(Crow*);
void FUN_08143dd4(Crow*);
void FUN_08143ef8(Crow*);
void FUN_08143fac(Crow*);
void FUN_08144cd0(Crow*);
void FUN_08144ec8(Crow*);
void FUN_081452cc(Crow*);

void (*const PTR_ARRAY_085ad828[5])(Crow*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Crow*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

void FUN_08144160(Crow*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Crow*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

INCASM("asm/crow.inc");
