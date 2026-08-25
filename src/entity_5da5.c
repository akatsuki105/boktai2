#include "global.h"

typedef void Entity5DA5;  // TODO: 後で実装する

const u16 u16_ARRAY_085aa690[8] = {
    0x0, 0x80, 0xFF80, 0x0, 0xFF80, 0x0, 0x0, 0x80,
};  // 0x085aa690

void FUN_08008b68(Entity5DA5*, UNK_PTR);
void FUN_08008c08(Entity5DA5*, UNK_PTR);

void (*const PTR_ARRAY_085aa6a0[2])(Entity5DA5*, UNK_PTR) = {
    FUN_08008b68,
    FUN_08008c08,
};  // 0x085aa6a0

const u8 u8_ARRAY_085aa6a8[4] = {11, 12, 11, 10};  // 0x085aa6a8
