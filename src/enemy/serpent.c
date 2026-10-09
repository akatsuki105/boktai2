#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_0818b4a8(Enemy* p);
void FUN_0818b818(Enemy* p);
void FUN_0818bc28(Enemy* p);
void FUN_0818bdf0(Enemy* p);
void FUN_0818bee0(Enemy* p);
void FUN_0818c080(Enemy* p);
void FUN_0818c1bc(Enemy* p);
void FUN_0818c31c(Enemy* p);
void FUN_0818c3bc(Enemy* p);
void FUN_0818c894(Enemy* p);
void FUN_0818cb5c(Enemy* p);
void FUN_0818cfb8(Enemy* p);
void FUN_0818d3d8(Enemy* p);
void FUN_0818d5b0(Enemy* p);
void FUN_0818d804(Enemy* p);
void FUN_0818dd0c(Enemy* p);
void FUN_0818de20(Enemy* p);
void FUN_0818e158(Enemy* p);
void FUN_08193ca4(Enemy* p);
void FUN_08193dc8(Enemy* p);
void FUN_08193fa4(Enemy* p);
void FUN_081940d8(Enemy* p);

void FUN_08188784(Enemy* p, u16* msg);
void FUN_081887c0(Enemy* p, u16* msg);
void FUN_0818e2b8(Enemy* p, u16* msg);

// メッセージ表
void (*const PTR_ARRAY_085adcd0[9])(Enemy*, u16*) = {
    NULL,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    NULL,
    FUN_08188784,
    FUN_081887c0,
};  // 0x085ADCD0

// clang-format off
void (*const PTR_ARRAY_085adcf4[24])(Enemy*) = {
    FUN_0818bc28,
    FUN_0818b818,
    FUN_0818b4a8,
    FUN_080f2364,
    FUN_0818c1bc,
    FUN_0818bee0,
    FUN_0818bdf0,
    NULL,
    NULL,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_0818c3bc,
    FUN_0818cb5c,
    FUN_0818cfb8,
    FUN_0818d3d8,
    FUN_0818d804,
    FUN_0818dd0c,
    FUN_0818c894,
    FUN_0818de20,
    FUN_0818c080,
    FUN_0818e158,
    FUN_0818d5b0,
    FUN_0818c31c,
};  // 0x085ADCF4
// clang-format on

const u32 u32_ARRAY_085add54[4] = {16, 16, 19, 24};  // 0x085ADD54

void (*const PTR_ARRAY_085add64[4])(Enemy*) = {
    FUN_08193ca4,
    FUN_08193dc8,
    FUN_08193fa4,
    FUN_081940d8,
};  // 0x085ADD64

// メッセージ表
void (*const PTR_ARRAY_085add74[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0818e2b8,
};  // 0x085ADD74

const s32 s32_ARRAY_085add90[6] = {-100, 0, 100, -70, 0, 130};  // 0x085ADD90

INCASM("asm/serpent.inc");
