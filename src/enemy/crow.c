#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1728 - sizeof(Enemy)];
} Crow;
static_assert(sizeof(Crow) == 1728);

void FUN_081436b4(Enemy* p);
void FUN_081439d8(Enemy* p);
void FUN_08143dd4(Enemy* p);
void FUN_08143ef8(Enemy* p);
void FUN_08143fac(Enemy* p);
void FUN_08144cd0(Enemy* p);
void FUN_08144ec8(Enemy* p);
void FUN_081452cc(Enemy* p);

void FUN_08144160(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ad828[5])(Enemy*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Enemy*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

INCASM("asm/crow.inc");
