#include "enemy.h"
#include "global.h"
#include "malloc.h"

// リッチ+が出してくる 炎の蛇 (技名はインフェルノ?)
// リッチ+ の技なので敵IDとかはない?
typedef struct {
  Enemy e;
  u8 unk_654[3328 - sizeof(Enemy)];
} LichFlameSnake;
static_assert(sizeof(LichFlameSnake) == 3328);

const STRING_DATA char s_eneinline_08252224[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_0825223c[] = "../system/eneinline.h";

void FUN_081a8514(LichFlameSnake*);
void FUN_081a8814(LichFlameSnake*);
void FUN_081a8278(LichFlameSnake*);
void FUN_081a8b28(LichFlameSnake*);
void FUN_081a8748(LichFlameSnake*);
void FUN_081a8c88(LichFlameSnake*);
void FUN_081a9220(LichFlameSnake*);
void FUN_081a94bc(LichFlameSnake*);
void FUN_081a8fe8(LichFlameSnake*);
void FUN_081a95fc(LichFlameSnake*);

void (*const PTR_ARRAY_085adea8[11])(LichFlameSnake*) = {
    FUN_081a8514,
    FUN_081a8814,
    FUN_081a8278,
    (void*)FUN_080f2364,
    FUN_081a8b28,
    FUN_081a8748,
    FUN_081a8c88,
    FUN_081a9220,
    FUN_081a94bc,
    FUN_081a8fe8,
    FUN_081a95fc,
};  // 0x085ADEA8

void FUN_081acd90(LichFlameSnake*);

void (*const PTR_ARRAY_085aded4[1])(LichFlameSnake*) = {
    FUN_081acd90,
};  // 0x085ADED4

void FUN_081a9724(LichFlameSnake*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085aded8[7])(LichFlameSnake*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_081a9724,
};  // 0x085ADED8

INCASM("asm/lich_flame_snake.inc");
