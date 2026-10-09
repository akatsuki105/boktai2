#include "enemy.h"
#include "global.h"
#include "malloc.h"

// アックス(ソードも含む?)
typedef struct {
  ENEMY_HDR;
  u8 unk_654[3688 - sizeof(Enemy)];
} EnemyAx;
static_assert(sizeof(EnemyAx) == 3688);

void FUN_08198250(Enemy* p);
void FUN_08198254(Enemy* p);
void FUN_08199eec(Enemy* p);
void FUN_08199ef0(Enemy* p);
void FUN_0819d664(Enemy* p);
void FUN_0819d89c(Enemy* p);
void FUN_0819d998(Enemy* p);
void FUN_0819db7c(Enemy* p);
void FUN_0819dc50(Enemy* p);
void FUN_081a057c(Enemy* p);
void FUN_081a0680(Enemy* p);
void FUN_081a0714(Enemy* p);
void FUN_081a082c(Enemy* p);
void FUN_081a08a4(Enemy* p);
void FUN_081a09bc(Enemy* p);
void FUN_081a0a34(Enemy* p);
void FUN_081a0b70(Enemy* p);
void FUN_081a0c2c(Enemy* p);
void FUN_081a0d3c(Enemy* p);
void FUN_081a1160(Enemy* p);
void FUN_081a158c(Enemy* p);
void FUN_081a1630(Enemy* p);

void (*const PTR_ARRAY_085adda8[2])(Enemy*) = {
    FUN_08198250,
    FUN_08198254,
};  // 0x085ADDA8

void (*const PTR_ARRAY_085addb0[2])(Enemy*) = {
    FUN_08199eec,
    FUN_08199ef0,
};  // 0x085ADDB0

void (*const PTR_ARRAY_085addb8[5])(Enemy*) = {
    FUN_0819dc50,
    FUN_0819d89c,
    FUN_0819d664,
    FUN_0819d998,
    FUN_0819db7c,
};  // 0x085ADDB8

const u16 u16_ARRAY_085addcc[8] = {12, 8, 4, 0, 4, 8, 12, 0};  // 0x085ADDCC

void (*const PTR_ARRAY_085adddc[11])(Enemy*) = {
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

void (*const PTR_ARRAY_085ade08[2])(Enemy*) = {
    FUN_081a158c,
    FUN_081a1630,
};  // 0x085ADE08

// 0x085ADBFC の先頭10要素と同じ中身
const Vec3 vec3_ARRAY_085ade10[10] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106}
};  // 0x085ADE10

INCASM("asm/ax.inc");
