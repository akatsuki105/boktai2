#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_08172848(Enemy* p);
void FUN_08172b4c(Enemy* p);
void FUN_08172df4(Enemy* p);
void FUN_081730a4(Enemy* p);
void FUN_0817324c(Enemy* p);
void FUN_08173318(Enemy* p);
void FUN_081736b0(Enemy* p);
void FUN_081738e0(Enemy* p);
void FUN_08173a28(Enemy* p);
void FUN_08173b88(Enemy* p);
void FUN_08173f2c(Enemy* p);
void FUN_081741f0(Enemy* p);
void FUN_0817456c(Enemy* p);
void FUN_0817497c(Enemy* p);
void FUN_08174ae8(Enemy* p);
void FUN_081750ec(Enemy* p);
void FUN_08175234(Enemy* p);
void FUN_0817552c(Enemy* p);
void FUN_0817a05c(Enemy* p);

void FUN_0817568c(Enemy* p, u16* msg);

// clang-format off
void (*const PTR_ARRAY_085adae4[22])(Enemy*) = {
    FUN_081730a4,
    FUN_08173318,
    FUN_08172848,
    FUN_080f2364,
    FUN_08173a28,
    FUN_081736b0,
    FUN_0817324c,
    FUN_08172b4c,
    FUN_08172df4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_08173b88,
    FUN_081741f0,
    FUN_0817456c,
    FUN_0817497c,
    FUN_08174ae8,
    FUN_081750ec,
    FUN_08173f2c,
    FUN_08175234,
    FUN_081738e0,
    FUN_0817552c,
};  // 0x085ADAE4
// clang-format on

const u32 u32_ARRAY_085adb3c[4] = {14, 15, 19, 24};  // 0x085ADB3C

void (*const PTR_ARRAY_085adb4c[1])(Enemy*) = {
    FUN_0817a05c,
};  // 0x085ADB4C

// メッセージ表
void (*const PTR_ARRAY_085adb50[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0817568c,
};  // 0x085ADB50

const u16 u16_ARRAY_085adb6c[16] = {576, 696, 864, 480, 576, 624, 840, 696, 748, 904, 1123, 624, 748, 811, 1092, 904};  // 0x085ADB6C

INCASM("asm/sandworm.inc");
