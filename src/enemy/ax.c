#include "enemy.h"
#include "global.h"
#include "malloc.h"

// ENEK_AX(多分 ENEK_SWORD も含む 見た目が武器の敵)
// どちらも 小さい斧, 剣 を飛ばして攻撃してくる (こちらの攻撃で弾き返せる)
typedef struct {
  Enemy e;
  u8 unk_654[3688 - sizeof(Enemy)];
} EnemyAx;
static_assert(sizeof(EnemyAx) == 3688);

const STRING_DATA char s_eneinline_082521a4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521bc[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521d4[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_082521ec[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252204[] = "../system/eneinline.h";
const STRING_DATA char s_axcom_c_0825221c[] = "axcom.c";

void FUN_08198250(EnemyAx*);
void FUN_08198254(EnemyAx*);

void (*const PTR_ARRAY_085adda8[2])(EnemyAx*) = {
    FUN_08198250,
    FUN_08198254,
};  // 0x085ADDA8

void FUN_08199eec(EnemyAx*);
void FUN_08199ef0(EnemyAx*);

void (*const PTR_ARRAY_085addb0[2])(EnemyAx*) = {
    FUN_08199eec,
    FUN_08199ef0,
};  // 0x085ADDB0

void FUN_0819dc50(EnemyAx*);
void FUN_0819d89c(EnemyAx*);
void FUN_0819d664(EnemyAx*);
void FUN_0819d998(EnemyAx*);
void FUN_0819db7c(EnemyAx*);

void (*const PTR_ARRAY_085addb8[5])(EnemyAx*) = {
    FUN_0819dc50,
    FUN_0819d89c,
    FUN_0819d664,
    FUN_0819d998,
    FUN_0819db7c,
};  // 0x085ADDB8

const u16 u16_ARRAY_085addcc[8] = {12, 8, 4, 0, 4, 8, 12, 0};  // 0x085ADDCC

void FUN_081a057c(EnemyAx*);
void FUN_081a0680(EnemyAx*);
void FUN_081a0714(EnemyAx*);
void FUN_081a082c(EnemyAx*);
void FUN_081a08a4(EnemyAx*);
void FUN_081a09bc(EnemyAx*);
void FUN_081a0a34(EnemyAx*);
void FUN_081a0b70(EnemyAx*);
void FUN_081a0c2c(EnemyAx*);
void FUN_081a0d3c(EnemyAx*);
void FUN_081a1160(EnemyAx*);

void (*const PTR_ARRAY_085adddc[11])(EnemyAx*) = {
    FUN_081a057c,
    FUN_081a0680,
    FUN_081a0714,
    FUN_081a082c,
    FUN_081a08a4,
    FUN_081a09bc,
    FUN_081a0a34,
    FUN_081a0b70,
    FUN_081a0c2c,
    FUN_081a0d3c,
    FUN_081a1160,
};  // 0x085ADDDC

void FUN_081a158c(EnemyAx*);
void FUN_081a1630(EnemyAx*);

void (*const PTR_ARRAY_085ade08[2])(EnemyAx*) = {
    FUN_081a158c,
    FUN_081a1630,
};  // 0x085ADE08

INCASM("asm/ax.inc");
