#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1684 - sizeof(Enemy)];
} Mimic;
static_assert(sizeof(Mimic) == 1684);

void FUN_081467bc(Enemy* p);
void FUN_081468c8(Enemy* p);
void FUN_08146970(Enemy* p);
void FUN_08146a34(Enemy* p);
void FUN_08146ae8(Enemy* p);
void FUN_08146ce0(Enemy* p);
void FUN_08148c00(Enemy* p);

void (*const PTR_ARRAY_085ad874[18])(Enemy*) = {
    FUN_081467bc,
    FUN_080f2864,
    FUN_081468c8,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_08146ce0,
    FUN_080f33e8,
    FUN_080f34a0,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_08146a34,
    FUN_08146ae8,
    FUN_08146970,
};  // 0x085AD874

void (*const PTR_ARRAY_085ad8bc[1])(Enemy*) = {
    FUN_08148c00,
};  // 0x085AD8BC

const u16 u16_ARRAY_085ad8c0[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AD8C0

INCASM("asm/mimic.inc");
