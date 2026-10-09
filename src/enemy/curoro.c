#include "enemy.h"
#include "global.h"
#include "malloc.h"

// クロロホルルン
typedef struct {
  ENEMY_HDR;
  u8 unk_654[1712 - sizeof(Enemy)];
} Curoro;
static_assert(sizeof(Curoro) == 1712);

void FUN_0813b824(Enemy* p);
void FUN_0813bb04(Enemy* p);
void FUN_0813bc50(Enemy* p);
void FUN_0813be38(Enemy* p);
void FUN_0813bf78(Enemy* p);
void FUN_0813ce1c(Enemy* p);
void FUN_0813d080(Enemy* p);
void FUN_0813d1d0(Enemy* p);
void FUN_0813d274(Enemy* p);

void FUN_0813c14c(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad770[5])(Enemy*) = {
    FUN_0813bc50,
    FUN_0813bb04,
    FUN_0813b824,
    FUN_0813bf78,
    FUN_0813be38,
};  // 0x085AD770

const u32 u32_ARRAY_085ad784[8] = {2, 3, 4, 6, 8, 9, 10, 12};  // 0x085AD784

void (*const PTR_ARRAY_085ad7a4[2])(Enemy*) = {
    FUN_0813d080,
    FUN_0813ce1c,
};  // 0x085AD7A4

void (*const PTR_ARRAY_085ad7ac[2])(Enemy*) = {
    FUN_0813d1d0,
    FUN_0813d274,
};  // 0x085AD7AC

// メッセージ表
void (*const PTR_ARRAY_085ad7b4[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0813c14c,
};  // 0x085AD7B4

INCASM("asm/curoro.inc");
