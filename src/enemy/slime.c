#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1680 - sizeof(Enemy)];
} EnemySlime;
static_assert(sizeof(EnemySlime) == 1680);

void FUN_08163b04(Enemy* p);
void FUN_08163bbc(Enemy* p);
void FUN_08163d94(Enemy* p);
void FUN_08163e10(Enemy* p);

void (*const PTR_ARRAY_085ad9c4[1])(Enemy*) = {
    FUN_08163b04,
};  // 0x085AD9C4

void (*const PTR_ARRAY_085ad9c8[16])(Enemy*) = {
    FUN_08163d94,
    FUN_080f2864,
    FUN_08163bbc,
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
    FUN_08163e10,
};  // 0x085AD9C8

const u16 u16_ARRAY_085ada08[6] = {0, 16, 32, 20, 12, 0};  // 0x085ADA08

INCASM("asm/slime.inc");
