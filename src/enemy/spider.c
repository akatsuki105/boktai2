#include "enemy.h"
#include "global.h"
#include "malloc.h"

// スパイダー(ENEID_SPIDER), ポイズンスパイダー(ENEID_PSPIDER)
// 見えない蜘蛛の巣を仕掛けて、プレイヤーがそれに触れると身動きが取れなくなる
// ポイズンスパイダーは毒液も吐く
typedef struct {
  Enemy e;
  u8 unk_654[1680 - sizeof(Enemy)];
} Spider;
static_assert(sizeof(Spider) == 1680);

void FUN_0812f83c(Spider*);
void FUN_0812f840(Spider*);
void FUN_0812f9ec(Spider*);
void FUN_0812fbec(Spider*);
void FUN_0812fcd8(Spider*);
void FUN_0812fdb8(Spider*);
void FUN_08130068(Spider*);

void (*const PTR_ARRAY_085ad6bc[17])(Spider*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    FUN_0812fdb8,
    FUN_0812fbec,
    FUN_0812f9ec,
    NULL,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    FUN_0812f840,
    FUN_0812fcd8,
    NULL,
    FUN_08130068,
    FUN_0812f83c,
};  // 0x085AD6BC

void (*const PTR_ARRAY_085ad700[3])(Spider*) = {
    (void*)FUN_080f1c54,
    (void*)FUN_080f1cb8,
    (void*)FUN_080f1cf0,
};  // 0x085AD700

const u16 u16_ARRAY_085ad70c[2] = {486, 486};  // 0x085AD70C

void FUN_081302f8(Spider*, u16*);

void (*const PTR_ARRAY_085ad710[7])(Spider*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_081302f8,
};  // 0x085AD710

INCASM("asm/spider.inc");
