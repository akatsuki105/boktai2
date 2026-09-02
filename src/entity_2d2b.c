#include "entity.h"
#include "file.h"
#include "global.h"

typedef struct Entity2D2B {
  Entity e;  // 0x0, ENTITY_UNK_10
  u8 unk_18[96 - 0x18];
} Entity2D2B;
static_assert(sizeof(Entity2D2B) == 96);

const FileID u16_ARRAY_085aa66c[2] = {SPRITE_CHANDELIER, SPRITE_CANDLE_BOX};  // 0x085aa66c

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
