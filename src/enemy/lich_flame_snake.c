#include "enemy.h"
#include "global.h"
#include "malloc.h"

// リッチ+が出してくる 炎の蛇 (正式名称不明)

void FUN_081a8278(Enemy* p);
void FUN_081a8514(Enemy* p);
void FUN_081a8748(Enemy* p);
void FUN_081a8814(Enemy* p);
void FUN_081a8b28(Enemy* p);
void FUN_081a8c88(Enemy* p);
void FUN_081a8fe8(Enemy* p);
void FUN_081a9220(Enemy* p);
void FUN_081a94bc(Enemy* p);
void FUN_081a95fc(Enemy* p);
void FUN_081acd90(Enemy* p);

void (*const PTR_ARRAY_085adea8[11])(Enemy*) = {
    FUN_081a8514,
    FUN_081a8814,
    FUN_081a8278,
    FUN_080f2364,
    FUN_081a8b28,
    FUN_081a8748,
    FUN_081a8c88,
    FUN_081a9220,
    FUN_081a94bc,
    FUN_081a8fe8,
    FUN_081a95fc,
};  // 0x085ADEA8

void (*const PTR_ARRAY_085aded4[1])(Enemy*) = {
    FUN_081acd90,
};  // 0x085ADED4

void FUN_081a9724(Enemy* p, u16* msg);

// メッセージ表
void (*const PTR_ARRAY_085aded8[7])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_081a9724,
};  // 0x085ADED8

INCASM("asm/lich_flame_snake.inc");
