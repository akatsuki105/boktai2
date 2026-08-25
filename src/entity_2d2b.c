#include "file.h"
#include "global.h"

typedef void Entity2D2B;

const FileID u16_ARRAY_085aa66c[2] = {0xF099, 0xB991};  // 0x085aa66c

const u16 u16_ARRAY_085aa670[4] = {0, 1, 0, 1};

const u16 u16_ARRAY_085aa678[2] = {64, 739};

void FUN_080080a8(Entity2D2B*);
void FUN_080080ac(Entity2D2B*);
void FUN_08008100(Entity2D2B*);
void FUN_0800816c(Entity2D2B*);
void FUN_080081e0(Entity2D2B*);

// clang-format off
void (*const PTR_ARRAY_085aa67c[5])(Entity2D2B*) = {
    FUN_080080a8,
    FUN_080080ac,
    FUN_08008100,
    FUN_0800816c,
    FUN_080081e0,
};  // 0x085aa67c
// clang-format on
