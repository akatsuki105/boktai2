#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1680 - sizeof(Enemy)];
} EnemySpider;
static_assert(sizeof(EnemySpider) == 1680);

void FUN_0812f83c(Enemy* p);
void FUN_0812f840(Enemy* p);
void FUN_0812f9ec(Enemy* p);
void FUN_0812fbec(Enemy* p);
void FUN_0812fcd8(Enemy* p);
void FUN_0812fdb8(Enemy* p);
void FUN_08130068(Enemy* p);
void FUN_081302f8(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad6bc[17])(Enemy*) = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_0812fdb8,
    FUN_0812fbec,
    FUN_0812f9ec,
    NULL,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_0812f840,
    FUN_0812fcd8,
    NULL,
    FUN_08130068,
    FUN_0812f83c,
};  // 0x085AD6BC

void (*const PTR_ARRAY_085ad700[3])(Enemy*) = {
    FUN_080f1c54,
    FUN_080f1cb8,
    FUN_080f1cf0,
};  // 0x085AD700

const u16 u16_ARRAY_085ad70c[2] = {486, 486};  // 0x085AD70C

void (*const PTR_ARRAY_085ad710[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081302f8,
};  // 0x085AD710

INCASM("asm/spider.inc");
