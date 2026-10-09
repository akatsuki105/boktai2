#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1764 - sizeof(Enemy)];
} Golem;
static_assert(sizeof(Golem) == 1764);

void FUN_0811cfb8(Enemy* p);
void FUN_0811d090(Enemy* p);
void FUN_0811d980(Enemy* p);
void FUN_0811dc98(Enemy* p);
void FUN_0811dd80(Enemy* p);
void FUN_0811edf4(Enemy* p);
void FUN_0811f04c(Enemy* p);
void FUN_0811f90c(Enemy* p);
void FUN_0811f990(Enemy* p);
void FUN_0811fab8(Enemy* p);
void FUN_0811fbd0(Enemy* p);
void FUN_0812019c(Enemy* p);

const u16 u16_ARRAY_085ad5f8[8] = {300, 306, 0, 360, 300, 306, 0, 360};  // 0x085AD5F8
const u16 u16_ARRAY_085ad608[2] = {0, 4};                                // 0x085AD608

void (*const PTR_ARRAY_085ad60c[2])(Enemy*) = {
    FUN_0811cfb8,
    FUN_0811d090,
};  // 0x085AD60C

void (*const PTR_ARRAY_085ad614[10])(Enemy*) = {
    FUN_0811d980,
    FUN_0811dd80,
    FUN_0811edf4,
    FUN_0811f04c,
    FUN_0811f90c,
    FUN_0811f990,
    FUN_0811dc98,
    FUN_0811fbd0,
    FUN_0811fab8,
    FUN_0812019c,
};  // 0x085AD614

INCASM("asm/golem.inc");
