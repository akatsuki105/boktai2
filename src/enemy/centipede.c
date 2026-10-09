#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_08134448(Enemy* p);
void FUN_08134738(Enemy* p);
void FUN_081349dc(Enemy* p);
void FUN_08134ccc(Enemy* p);
void FUN_08134e88(Enemy* p);
void FUN_08134fb4(Enemy* p);
void FUN_081352d4(Enemy* p);
void FUN_0813544c(Enemy* p);
void FUN_08138b34(Enemy* p);

void (*const PTR_ARRAY_085ad72c[12])(Enemy*) = {
    FUN_08134ccc,
    FUN_08134fb4,
    FUN_08134448,
    FUN_080f2364,
    FUN_0813544c,
    FUN_081352d4,
    FUN_08134e88,
    FUN_08134738,
    FUN_081349dc,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
};  // 0x085AD72C

const u32 u32_ARRAY_085ad75c[4] = {28, 31, 38, 48};  // 0x085AD75C

void (*const PTR_ARRAY_085ad76c[1])(Enemy*) = {
    FUN_08138b34,
};  // 0x085AD76C

INCASM("asm/centipede.inc");
