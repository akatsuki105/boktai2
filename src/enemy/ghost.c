#include "enemy.h"
#include "global.h"
#include "malloc.h"

void FUN_0816be8c(Enemy* p);
void FUN_0816c164(Enemy* p);
void FUN_0816c29c(Enemy* p);
void FUN_0816c45c(Enemy* p);
void FUN_0816c6a0(Enemy* p);
void FUN_0816e1a4(Enemy* p);
void FUN_0816e3b8(Enemy* p);
void FUN_0816e828(Enemy* p);
void FUN_0816ec60(Enemy* p);
void FUN_0816ed04(Enemy* p);
void FUN_0816ee98(Enemy* p);

void FUN_0816cbf0(Enemy* p, u16* msg);
void FUN_0816cc94(Enemy* p, u16* msg);

void (*const PTR_ARRAY_085ada84[5])(Enemy*) = {
    FUN_0816c29c,
    FUN_0816c164,
    FUN_0816be8c,
    FUN_0816c45c,
    FUN_0816c6a0,
};  // 0x085ADA84

void (*const PTR_ARRAY_085ada98[3])(Enemy*) = {
    FUN_0816e1a4,
    FUN_0816e3b8,
    FUN_0816e828,
};  // 0x085ADA98

void (*const PTR_ARRAY_085adaa4[2])(Enemy*) = {
    FUN_0816ec60,
    FUN_0816ed04,
};  // 0x085ADAA4

void (*const PTR_ARRAY_085adaac[6])(Enemy*) = {
    FUN_0816ee98,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
};  // 0x085ADAAC

// メッセージ表
void (*const PTR_ARRAY_085adac4[8])(Enemy*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)FUN_080f07d0,
    (void*)FUN_080f0914,
    (void*)FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
    FUN_0816cbf0,
    FUN_0816cc94,
};  // 0x085ADAC4

INCASM("asm/ghost.inc");
