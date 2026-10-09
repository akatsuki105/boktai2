#include "enemy.h"
#include "global.h"
#include "malloc.h"

typedef struct {
  ENEMY_HDR;
  u8 unk_654[1692 - sizeof(Enemy)];
} EnemyOctopus;
static_assert(sizeof(EnemyOctopus) == 1692);

void FUN_08186484(Enemy* p);
void FUN_081865a8(Enemy* p);
void FUN_08186734(Enemy* p);
void FUN_08186844(Enemy* p);
void FUN_08186988(Enemy* p);
void FUN_08186a7c(Enemy* p);
void FUN_08186b10(Enemy* p);
void FUN_08186b28(Enemy* p);
void FUN_08186b7c(Enemy* p);
void FUN_08186c00(Enemy* p);
void FUN_08186c88(Enemy* p);
void FUN_08186ca0(Enemy* p);
void FUN_08186d00(Enemy* p);
void FUN_08186d7c(Enemy* p);

void FUN_081870f4(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085adc6c[6])(Enemy*) = {
    FUN_08186a7c,
    FUN_08186b7c,
    FUN_08186c00,
    FUN_08186b10,
    FUN_08186c88,
    FUN_08186734,
};  // 0x085ADC6C

void (*const PTR_ARRAY_085adc84[5])(Enemy*) = {
    FUN_08186988,
    FUN_08186484,
    FUN_08186844,
    FUN_08186b28,
    FUN_081865a8,
};  // 0x085ADC84

void (*const PTR_ARRAY_085adc98[4])(Enemy*) = {
    FUN_08186ca0,
    FUN_080f1cb8,
    FUN_08186d7c,
    FUN_08186d00,
};  // 0x085ADC98

// メッセージ表
void (*const PTR_ARRAY_085adca8[10])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    NULL,
    NULL,
    NULL,
    FUN_081870f4,
};  // 0x085ADCA8

INCASM("asm/octopus.inc");
